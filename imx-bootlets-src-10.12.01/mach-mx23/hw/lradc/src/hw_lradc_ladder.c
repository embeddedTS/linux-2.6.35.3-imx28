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
//   Includes and external references
////////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "hw/lradc/hw_lradc.h"
#include "registers/regs.h"
#include "registers/regslradc.h"
#include "error.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
RtStatus_t hw_lradc_InitLadder(hw_lradc_Channel_t       eChannel,
                                hw_lradc_DelayTrigger_t eTrigger,
                                uint16_t                u16SamplingInterval)
{
    RtStatus_t    Rtn = SUCCESS;

    //
    // Check if the lradc channel is present in this product
    //
    if( hw_lradc_GetChannelPresent(eChannel) == 0 )
        return (ERROR_HW_LRADC_CH_NOT_PRESENT);

    if ( (BF_RD(LRADC_CTRL0, SFTRST) != 0) ||
		(BF_RD(LRADC_CTRL0, CLKGATE) != 0) )
    {
        // Clean On-chip ground ref and set LRADC clock
        hw_lradc_Init(FALSE, LRADC_CLOCK_6MHZ);
    }

    // Disable the channel interrupt
    hw_lradc_EnableInterrupt(eChannel, FALSE);

    // Configure the specified lradc channel
    hw_lradc_ConfigureChannel(  eChannel,   //Lradc channel
                                TRUE,       //DIVIDE_BY_TWO
                                FALSE,      //ACCUMULATE
                                0);         //NUM_SAMPLES

    // Setup the trigger loop forever,
    hw_lradc_SetDelayTrigger( eTrigger,          // Trigger Index
                              (1 << eChannel),  // Lradc channels
                              (1 << eTrigger),  // Restart the triggers
                              0,                // No loop count
                              u16SamplingInterval); // 0.5*N msec on 2khz

    // Clear the accumulator & NUM_SAMPLES
    HW_LRADC_CHn_CLR(eChannel, 0xFFFFFFFF);

    return Rtn;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
uint16_t hw_lradc_MeasureVddio(void)
{
    // Clear the Soft Reset for normal operation
    BF_CLR(LRADC_CTRL0, SFTRST);

    // Clear the Clock Gate for normal operation
    BF_CLR(LRADC_CTRL0, CLKGATE);

     // Clear the divide by two for channel 6 since it has a HW divide-by-two
     // built in.
     BF_CLRV(LRADC_CTRL2, DIVIDE_BY_TWO, 1 << VDDIO_VOLTAGE_CH);

     // Clear the accumulator & NUM_SAMPLES
     HW_LRADC_CHn_CLR(VDDIO_VOLTAGE_CH, 0xFFFFFFFF);

     // Get VddIO; this is the max scale value for the button resistor ladder.
     // schedule ch 6:
     BF_WR( LRADC_CTRL0, SCHEDULE, (1 << VDDIO_VOLTAGE_CH) );

     // wait for completion
     while (BF_RD( LRADC_CTRL1, LRADC6_IRQ ) !=
	BV_LRADC_CTRL1_LRADC6_IRQ__PENDING)
     {
	 // Wait for channel 6 completion.
     }

     // Clear the interrupt flag
     BF_CLR(LRADC_CTRL1, LRADC6_IRQ);

     // read ch 6 value.
    return BF_RDn( LRADC_CHn, VDDIO_VOLTAGE_CH, VALUE);
}
