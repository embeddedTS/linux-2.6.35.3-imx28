/*
 * Copyright (c) 2009-2012 Freescale Semiconductor, Inc. All Rights Reserved.
 */

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Freescale Semiconductor nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *
 * ALTERNATIVELY, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") as published by the Free Software
 * Foundation, either version 2 of that License or (at your option) any
 * later version.
 *
 * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Includes and external references
////////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "error.h"

#include "registers/regspower.h"
#include "registers/regsdigctl.h"
#include "hw/power/hw_power.h"
#include "hw/icoll/hw_icoll.h"

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////
#define FIQ_DEBOUNCE_MICROSECONDS 11

//------------------------------------------------------------------------------
// This definition will add global variables that store the brownout status
// and bit information.  It will also add a system halt just before the
// handler would power down the chip.  This allows the debugger to stay
// powered so the brownout information can be read.  Do not define DEBUG_FIQ
// for production code.
//------------------------------------------------------------------------------
//#define DEBUG_FIQ 1

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG_FIQ
uint32_t DEBUG_StatusRegister = 0;
uint32_t DEBUG_BrownoutStatusBits = 0;
uint32_t DEBUG_DebounceMicroseconds = FIQ_DEBOUNCE_MICROSECONDS;
#endif

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
#pragma ghs section text=".static.text"
bool hw_power_FiqHandler(void)
{

    uint32_t u32FIQBits;
    uint32_t u32Start;

    //--------------------------------------------------------------------------
    // VBUSDROOP is time critical so it must be checked first.  The first three
    // registers bitfield clears should occur ASAP.
    //--------------------------------------------------------------------------
    if( HW_POWER_CTRL.B.VDD5V_DROOP_IRQ &&
        HW_POWER_CTRL.B.ENIRQ_VDD5V_DROOP )
    {
        // Stop the 4P2.  This forces the DCDC to immediatlely use the battery
	// power.
        BF_CLR( POWER_DCDC4P2, ENABLE_DCDC );
        BF_CLR( POWER_DCDC4P2, ENABLE_4P2 );
        BF_CLR( POWER_CHARGE,  ENABLE_LOAD );

        // Disable the ICOLL VDD5V droop interrupt
        hw_power_EnableVdd5vDroopInterrupt( false );
        hw_icoll_EnableVector((ICOLL_IRQ_enums_t)(VECTOR_IRQ_VDD5V_DROOP),
		false );

        // Clear status for next interrupt.
        hw_power_ClearVdd5vDroopInterrupt();

        // Trigger a 5V removal interrupt since VBUSDROOP is the first indicator
        // 5V is lost.  This will overcome any VBUSVALID hysterisis issues.
        hw_icoll_SoftTrigger( VECTOR_IRQ_VDD5V, true );

        return false;
    }


    //--------------------------------------------------------------------------
    // The HW_POWER_CTRL register contains all the brownout interrupt bits.  We
    // need to read this register.
    //--------------------------------------------------------------------------

    u32FIQBits = HW_POWER_CTRL_RD();


    //--------------------------------------------------------------------------
    // Find out if either VDDD, VDDA, or VDDIO have drooped.
    //--------------------------------------------------------------------------

    if (u32FIQBits &
    (BM_POWER_CTRL_VDDD_BO_IRQ | BM_POWER_CTRL_VDDIO_BO_IRQ |
	BM_POWER_CTRL_VDDA_BO_IRQ))
    {
        uint32_t  u32BoStsBits;

        //----------------------------------------------------------------------
        // Loop for specified time to debounce the brownout status bits.
        //----------------------------------------------------------------------

#ifdef DEBUG_FIQ
        //----------------------------------------------------------------------
        // This version saves important data to a global variables to help
        // debug any brownout issues.  The debounce time can also be changed.
        //----------------------------------------------------------------------
        u32Start = HW_DIGCTL_MICROSECONDS_RD();
        while(HW_DIGCTL_MICROSECONDS_RD()<u32Start+DEBUG_DebounceMicroseconds);
        u32BoStsBits = HW_POWER_STS_RD();
        DEBUG_StatusRegister = u32BoStsBits;

        DEBUG_BrownoutStatusBits = (u32BoStsBits &
        (BM_POWER_STS_VDDD_BO | BM_POWER_STS_VDDA_BO | BM_POWER_STS_VDDIO_BO));
#else

        //----------------------------------------------------------------------
        // This version should be used for production code.
        //----------------------------------------------------------------------
        u32Start = HW_DIGCTL_MICROSECONDS_RD();

        while(HW_DIGCTL_MICROSECONDS_RD() < u32Start+FIQ_DEBOUNCE_MICROSECONDS)
	    {
	        u32BoStsBits = HW_POWER_STS_RD();


       	    if(
    		    ( !(u32BoStsBits & BM_POWER_STS_VDDD_BO)  ) ==
    		    ( !(u32BoStsBits & BM_POWER_STS_VDDA_BO)  ) ==
    		    ( !(u32BoStsBits & BM_POWER_STS_VDDIO_BO) )
    		 )


    	    {

                //--------------------------------------------------------------
                // This was a false brownout.  We need to clear the brownout IRQ
		// bits and return.
                //--------------------------------------------------------------

                BF_CLR(POWER_CTRL,VDDD_BO_IRQ);
                BF_CLR(POWER_CTRL,VDDA_BO_IRQ);
                BF_CLR(POWER_CTRL,VDDIO_BO_IRQ);

                //--------------------------------------------------------------
                // We need to return FALSE to let the PMI FIQ know this was a
		// false power supply brownout.  Otherwise, the PMI FIQ will
                // assume since we had a brownout and it wasn't a supply, it
		// must have been the battery.
                //--------------------------------------------------------------

                return false;
    	    }

        }

#endif

#ifdef DEBUG_FIQ
        //----------------------------------------------------------------------
        // The following function call will set a debug point.
        // This is the last place to stop before the brownout would
        // shut down power.  A while loop is used instead of SystemHalt()
        // because SystemHalt needs to be paged in.
        //----------------------------------------------------------------------
        while(DEBUG_BrownoutStatusBits);
#endif

        //----------------------------------------------------------------------
        // One of the rail's experienced a brownout.  We need to power down
        // the device.  Good bye.
        //----------------------------------------------------------------------
        hw_power_PowerDown();
        return true;
    }


    //--------------------------------------------------------------------------
    // The power rails didn't brownout.  Check the 4p2 rail.
    //--------------------------------------------------------------------------
    else if (u32FIQBits & BM_POWER_CTRL_DCDC4P2_BO_IRQ &&
             HW_POWER_CTRL.B.ENIRQ_DCDC4P2_BO)
    {

    #ifdef DEBUG_FIQ
        DEBUG_StatusRegister = ( HW_POWER_STS_RD() |
		BM_POWER_CTRL_DCDC4P2_BO_IRQ );
        while( DEBUG_StatusRegister );
    #endif

        // We had a brownout on the 4p2 rail.  Power down the chip.
        hw_power_PowerDown();
        return true;
    }


    //--------------------------------------------------------------------------
    // The only brownout left is the battery.  Check it.
    //--------------------------------------------------------------------------
    else if (u32FIQBits & BM_POWER_CTRL_BATT_BO_IRQ)
    {
	    return true;
    }

    //--------------------------------------------------------------------------
    // We should not reach this statement.  If we do, there is a brownout
    // we are not handling.  This is here to make the compiler happy.
    //--------------------------------------------------------------------------
    else
    {
	    return false;
    }



}

#pragma ghs section

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}




