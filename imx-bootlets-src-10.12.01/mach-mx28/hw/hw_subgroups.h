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

#ifndef _HW_SUBGROUPS_H
#define _HW_SUBGROUPS_H

#include "groups.h"

#define HW_MMU_GROUP              (HW_GROUP|0x00000000)
#define HW_IRQ_GROUP              (HW_GROUP|0x00001000)
#define HW_CACHE_GROUP            (HW_GROUP|0x00002000)
#define HW_USB_PHY_GROUP          (HW_GROUP|0x00004000)
#define HW_ICOLL_GROUP            (HW_GROUP|0x00005000)
#define HW_PLL_GROUP              (HW_GROUP|0x00006000)
#define HW_TIMER_GROUP            (HW_GROUP|0x00007000)
#define HW_PWM_OUTPUT_GROUP       (HW_GROUP|0x00008000)
#define HW_UART_DEBUG_GROUP       (HW_GROUP|0x00009000)
#define HW_UARTAPP_GROUP          (HW_GROUP|0x0000A000)
#define HW_EMI_GROUP              (HW_GROUP|0x0000B000)
#define HW_SSP_GROUP              (HW_GROUP|0x0000E000)
#define HW_I2C_GROUP              (HW_GROUP|0x0000F000)
#define HW_DAC_GROUP              (HW_GROUP|0x00011000)
#define HW_ADC_GROUP              (HW_GROUP|0x00012000)
#define HW_RTC_GROUP              (HW_GROUP|0x00014000)
#define HW_ALARM_GROUP            (HW_GROUP|0x00015000)
#define HW_WATCHDOG_GROUP         (HW_GROUP|0x00016000)
#define HW_LRADC_GROUP            (HW_GROUP|0x00017000)
#define HW_GPMI_GROUP             (HW_GROUP|0x00018000)
#define HW_CLOCKS_GROUP           (HW_GROUP|0x0001A000)
#define HW_DRI_GROUP              (HW_GROUP|0x0001B000)
#define HW_HWECC_GROUP            (HW_GROUP|0x00019000)
#define HW_LCDIF_GROUP            (HW_GROUP|0x0000C000)
#define HW_DCDC_GROUP             (HW_GROUP|0x0000D000)
#define HW_DCP_GROUP              (HW_GROUP|0x0001C000)
#define HW_PINMUX_GROUP           (HW_GROUP|0x0001D000)

#endif//_HW_SUBGROUPS_H
