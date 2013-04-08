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


//   Includes and external references
////////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "error.h"                  // Common SigmaTel Error Codes

#include "hw/power/hw_power.h"
#include "hw/icoll/hw_icoll.h"
//#include "hw/core/hw_core.h"

#include "drivers/power/ddi_power.h"       // Driver API
//#include "drivers/icoll/ddi_icoll.h"

#include "ddi_power_internal.h"

////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Globals & Variables
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//! \brief Sets the DCDC and software 5V detection methods.
//!
//! \fntype Function
//!
//! Configures the 5V detection method for the DCDC and software.  Also sets
//! the VBUSVALID 5V valid level.
//!
//! \param[in]  eDcdc5vDetection DCDC control logic 5V detection method.
//! \param[in]  eSw5vDetection Software's 5V detection method.
//! \param[in]  u16VbusValidThresh Voltage level in millivolts where 5V will be
//! considered valid.
//!
//! \retval SUCCESS Detection methods and thresholds set.
/////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_Configure5vDetection( ddi_power_5vDetection_t eDcdc5vDetection,
                                           ddi_power_5vDetection_t eSw5vDetection,
                                           uint16_t u16VbusValidThresh )
{
    hw_power_5vDetection_t eDcdc = HW_POWER_5V_UNINITIALIZED;
    hw_power_5vDetection_t eSw = HW_POWER_5V_UNINITIALIZED;
    hw_power_VbusValidThresh_t eThresh;

    // Translate the DCDC detection method to hw level.
    switch( eDcdc5vDetection )
    {
        case DDI_POWER_VBUSVALID:
            eDcdc = HW_POWER_5V_VBUSVALID;
            break;

        case DDI_POWER_VBUSVALID_WITH_POLLING:
            eDcdc = HW_POWER_5V_VBUSVALID_WITH_POLLING;
            break;

        case DDI_POWER_VDD5V_GT_VDDIO:
            eDcdc = HW_POWER_5V_VDD5V_GT_VDDIO;
            break;
    }

    // Translate the software detection method to hw level.
    switch( eSw5vDetection )
    {
        case DDI_POWER_VBUSVALID:
            eSw = HW_POWER_5V_VBUSVALID;
            break;

        case DDI_POWER_VBUSVALID_WITH_POLLING:
            eSw = HW_POWER_5V_VBUSVALID_WITH_POLLING;
            break;

        case DDI_POWER_VDD5V_GT_VDDIO:
            eSw = HW_POWER_5V_VDD5V_GT_VDDIO;
            break;
    }



    // Set the DCDC control logic's 5V detection method.
    hw_power_SetDcdc5vDetect( eDcdc );

    // Set the software's 5V detection method.
    hw_power_SetSw5vDetect( eSw );

    // Convert the voltage to register setting and set the threshold.
    eThresh = hw_power_ConvertVoltToVbusThresh( u16VbusValidThresh );
    hw_power_SetVbusValidThresh( eThresh );

    return SUCCESS;
}
////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}

