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
#include "hw/power/hw_power.h"
#include "error.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_lradc_ClearInterruptFlag(hw_lradc_Channel_t eChannel)
{
    // Clears a LRADC channel interrupt flag
    switch (eChannel)
    {
        case LRADC_CH0:
            BF_CLR(LRADC_CTRL1, LRADC0_IRQ);
            break;
        case LRADC_CH1:
            BF_CLR(LRADC_CTRL1, LRADC1_IRQ);
            break;
        case LRADC_CH2:
            BF_CLR(LRADC_CTRL1, LRADC2_IRQ);
            break;
        case LRADC_CH3:
            BF_CLR(LRADC_CTRL1, LRADC3_IRQ);
            break;
        case LRADC_CH4:
            BF_CLR(LRADC_CTRL1, LRADC4_IRQ);
            break;
        case LRADC_CH5:
            BF_CLR(LRADC_CTRL1, LRADC5_IRQ);
            break;
        case LRADC_CH6:
            BF_CLR(LRADC_CTRL1, LRADC6_IRQ);
            break;
        case LRADC_CH7:
            BF_CLR(LRADC_CTRL1, LRADC7_IRQ);
            break;
        default:
            break;
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
uint16_t hw_lradc_GetAccumValue(hw_lradc_Channel_t eChannel)
{
    // Read the accumulator value of the channel
    return (uint16_t)(BF_RDn(LRADC_CHn, eChannel, VALUE));
}

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
