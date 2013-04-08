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
// Includes and external references
////////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "error.h"

#include "hw/power/hw_power.h"
#include "registers/regspower.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnablePswitchInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQ_PSWITCH);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_PSWITCH);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_PSWITCH);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearPswitchInterrupt(void)
{
    BF_CLR(POWER_CTRL, PSWITCH_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_SetPswitchInterruptSource(bool bSource)
{
    if(bSource == HW_POWER_STS_PSWITCH_BIT_0)
    {
        BF_CLR(POWER_CTRL, PSWITCH_IRQ_SRC);
    }
    else // bSource == HW_POWER_STS_PSWITCH_BIT_1
    {
        BF_SET(POWER_CTRL, PSWITCH_IRQ_SRC);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_SetPswitchInterruptPolarity(bool bPolarity)
{
    if(bPolarity == HW_POWER_CHECK_PSWITCH_LOW)
    {
        BF_CLR(POWER_CTRL, POLARITY_PSWITCH);
    }

    // bPolarity == HW_POWER_CHECK_PSWITCH_HIGH
    else
    {
        BF_SET(POWER_CTRL, POLARITY_PSWITCH);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_GetPswitchInterruptPolarity(void)
{
    // used to be hw_power_GetPswitchPolarityFlag
    return HW_POWER_CTRL.B.POLARITY_PSWITCH;
}


////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_EnableDcOkInterrupt(bool bEnable)
{
    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_DC_OK);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_DC_OK);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearDcOkInterrupt(void)
{
    BF_CLR(POWER_CTRL, DC_OK_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableBatteryBrownoutInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQBATT_BO);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQBATT_BO);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQBATT_BO);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearBatteryBrownoutInterrupt(void)
{
    BF_CLR(POWER_CTRL, BATT_BO_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableVddioBrownoutInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQ_VDDIO_BO);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_VDDIO_BO);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_VDDIO_BO);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearVddioBrownoutInterrupt(void)
{
    BF_CLR(POWER_CTRL, VDDIO_BO_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableVddaBrownoutInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQ_VDDA_BO);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_VDDA_BO);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_VDDA_BO);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearVddaBrownoutInterrupt(void)
{
    BF_CLR(POWER_CTRL, VDDA_BO_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableVdddBrownoutInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQ_VDDD_BO);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_VDDD_BO);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_VDDD_BO);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearVdddBrownoutInterrupt(void)
{
    BF_CLR(POWER_CTRL, VDDD_BO_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableVbusValidInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQ_VBUS_VALID);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_VBUS_VALID);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_VBUS_VALID);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearVbusValidInterrupt(void)
{
    while( BF_RD(POWER_CTRL, VBUSVALID_IRQ) != 0 )
    {
        BF_CLR(POWER_CTRL, VBUSVALID_IRQ);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_GetVbusValidInterruptPolarity(void)
{
    return HW_POWER_CTRL.B.POLARITY_VBUSVALID;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_SetVbusValidInterruptPolarity(bool bPolarity)
{
    if(bPolarity == HW_POWER_CHECK_5V_DISCONNECTED)
    {
        BF_CLR(POWER_CTRL, POLARITY_VBUSVALID);
    }

    // bPolarity == HW_POWER_CHECK_5V_CONNECTED
    else
    {
        BF_SET(POWER_CTRL, POLARITY_VBUSVALID);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableVdd5vGtVddioInterrupt(bool bEnable)
{
    bool bPrev = BF_RD(POWER_CTRL, ENIRQ_VDD5V_GT_VDDIO);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_VDD5V_GT_VDDIO);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_VDD5V_GT_VDDIO);
    }

    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearVdd5vGtVddioInterrupt(void)
{
    BF_CLR(POWER_CTRL, VDD5V_GT_VDDIO_IRQ);
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_SetVdd5vGtVddioInterruptPolarity(bool bPolarity)
{
    if(bPolarity == HW_POWER_CHECK_5V_DISCONNECTED)
    {
        BF_CLR(POWER_CTRL, POLARITY_VDD5V_GT_VDDIO);
    }

    // bPolarity == HW_POWER_CHECK_5V_CONNECTED
    else
    {
        BF_SET(POWER_CTRL, POLARITY_VDD5V_GT_VDDIO);
    }
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_GetVdd5vGtVddioInterruptPolarity(void)
{
    return HW_POWER_CTRL.B.POLARITY_VDD5V_GT_VDDIO;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_Enable4p2BrownoutInterrupt(bool bEnable)
{
    bool bPrev = false;



    bPrev = BF_RD(POWER_CTRL, ENIRQ_DCDC4P2_BO);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_DCDC4P2_BO);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_DCDC4P2_BO);
    }



    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_Clear4p2BrownoutInterrupt(void)
{

    BF_CLR(POWER_CTRL, DCDC4P2_BO_IRQ);

}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
bool hw_power_EnableVdd5vDroopInterrupt(bool bEnable)
{
    bool bPrev = false;



    bPrev = BF_RD(POWER_CTRL, ENIRQ_VDD5V_DROOP);

    if(bEnable)
    {
        BF_SET(POWER_CTRL, ENIRQ_VDD5V_DROOP);
    }
    else
    {
        BF_CLR(POWER_CTRL, ENIRQ_VDD5V_DROOP);
    }



    return bPrev;
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_power.h for details.
////////////////////////////////////////////////////////////////////////////////
void hw_power_ClearVdd5vDroopInterrupt(void)
{

    while( BF_RD(POWER_CTRL, VDD5V_DROOP_IRQ) != 0 )
    {
        BF_CLR(POWER_CTRL, VDD5V_DROOP_IRQ);
    }

}


////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}


