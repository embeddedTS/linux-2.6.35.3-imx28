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
bool hw_lradc_GetTouchDetectPresent(void)
{
    // Read the TOUCH_PANEL_PRESENT bit of HW_LRADC_STATUS register
    return (BF_RD(LRADC_STATUS, TOUCH_PANEL_PRESENT));
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_lradc_EnableTouchDetect(bool bValue)
{
    if(bValue)
    {   //Enable the touch detector
        BF_SET(LRADC_CTRL0, TOUCH_DETECT_ENABLE);
    }
    else
    {   // Disable the touch detector
        BF_CLR(LRADC_CTRL0, TOUCH_DETECT_ENABLE);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_lradc_EnableTouchDetectInterrupt(bool bValue)
{
    if(bValue)
    {   //Enable the touch detector interrupt
        BF_SET(LRADC_CTRL1, TOUCH_DETECT_IRQ_EN);
    }
    else
    {   // Disable the touch detector interrupt
        BF_CLR(LRADC_CTRL1, TOUCH_DETECT_IRQ_EN);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_lradc_GetTouchDetectInterruptFlag(void)
{
    return ((bool)(BF_RD(LRADC_CTRL1, TOUCH_DETECT_IRQ)));
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_lradc_ClearTouchDetectInterruptFlag(void)
{
    BF_CLR(LRADC_CTRL1, TOUCH_DETECT_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_lradc_EnableTouchDetectXDrive(bool bValue)
{
#if 0
    if(bValue)
    {   //Enable the X-Drive
        BF_SET(LRADC_CTRL0, XMINUS_ENABLE);
        BF_SET(LRADC_CTRL0, XPLUS_ENABLE);
    }
    else
    {   // Disable the X-Drive
        BF_CLR(LRADC_CTRL0, XMINUS_ENABLE);
        BF_CLR(LRADC_CTRL0, XPLUS_ENABLE);
    }
#endif
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_lradc_EnableTouchDetectYDrive(bool bValue)
{
#if 0
    if(bValue)
    {   //Enable the Y-Drive
        BF_SET(LRADC_CTRL0, YMINUS_ENABLE);
        BF_SET(LRADC_CTRL0, YPLUS_ENABLE);
    }
    else
    {   // Disable the Y-Drive
        BF_CLR(LRADC_CTRL0, YMINUS_ENABLE);
        BF_CLR(LRADC_CTRL0, YPLUS_ENABLE);
    }
#endif
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_lradc.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_lradc_GetTouchDetect(void)
{
    // Read the TOUCH_DETECT_RAW bit of HW_LRADC_STATUS register
    return ((bool)(BF_RD(LRADC_STATUS, TOUCH_DETECT_RAW)));
}

