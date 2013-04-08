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

#include "drivers/power/ddi_power.h"       // Driver API
#include "drivers/power/ddi_power_errordefs.h"

////////////////////////////////////////////////////////////////////////////////
// Globals & Variables
////////////////////////////////////////////////////////////////////////////////

//! This global variable contains a code that represents the "safe" battery
//! voltage. As long as the battery voltage is above this level, we believe it
//! is probably safe to perform any normal system function.
//!
//! If the battery voltage ever dips down to or below this level, we believe
//! that some future operation has an unacceptable probability of causing the
//! system to brown out and power down.
//!
//! In normal operation, if the battery voltage dips down to or below this
//! level, and the 5V supply is not present, then the FIQ handler will catch a
//! brown out interrupt and send a message to the PMI state machine.
//!
//! The actual voltage represented here depends on the battery mode. See
//! "Battery Level Monitor Register Description" in the data sheet for details.
uint8_t g_ddi_power_SafeBatteryVoltageCode = 23;


//! This global variable contains a code that represents the "brown out" battery
//! voltage. In normal operation, if the battery voltage dips down to or below
//! this level, and the 5V supply is not present, then the hardware will
//! immediately cut off the power.
//!
//! The actual voltage represented here depends on the battery mode. See
//! "Battery Level Monitor Register Description" in the data sheet for details.
uint8_t g_ddi_power_BatteryBrownOutVoltageCode = 14;



////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Battery Charger Status
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Battery Voltage
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//!
//! \brief Report the voltage across the battery.
//!
//! \fntype Function
//!
//! This function reports the voltage across the battery.
//!
//! \retval The voltage across the battery, in mV.
//!
////////////////////////////////////////////////////////////////////////////////
uint16_t  ddi_power_GetBattery(void)
{
    // Should return a value in range ~3000 - 4200 mV
    return hw_power_GetBatteryVoltage();
}


////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
