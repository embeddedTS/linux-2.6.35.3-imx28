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

#ifndef _HW_ERRORDEFS_H
#define _HW_ERRORDEFS_H

#include "errordefs.h"
#include "hw_subgroups.h"

#define ERROR_HW_MMU_GROUP              (ERROR_MASK|HW_MMU_GROUP)
#define ERROR_HW_IRQ_GROUP              (ERROR_MASK|HW_IRQ_GROUP)
#define ERROR_HW_CACHE_GROUP            (ERROR_MASK|HW_CACHE_GROUP)
#define ERROR_HW_USB_PHY_GROUP          (ERROR_MASK|HW_USB_PHY_GROUP)
#define ERROR_HW_ICOLL_GROUP            (ERROR_MASK|HW_ICOLL_GROUP)
#define ERROR_HW_PLL_GROUP              (ERROR_MASK|HW_PLL_GROUP)
#define ERROR_HW_TIMER_GROUP            (ERROR_MASK|HW_TIMER_GROUP)
#define ERROR_HW_PWM_OUTPUT_GROUP       (ERROR_MASK|HW_PWM_OUTPUT_GROUP)
#define ERROR_HW_UART_DEBUG_GROUP       (ERROR_MASK|HW_UART_DEBUG_GROUP)
#define ERROR_HW_UARTAPP_GROUP          (ERROR_MASK|HW_UARTAPP_GROUP)
#define ERROR_HW_EMI_GROUP              (ERROR_MASK|HW_EMI_GROUP)
#define ERROR_HW_SSP_GROUP              (ERROR_MASK|HW_SSP_GROUP)
#define ERROR_HW_I2C_GROUP              (ERROR_MASK|HW_I2C_GROUP)
#define ERROR_HW_DAC_GROUP              (ERROR_MASK|HW_DAC_GROUP)
#define ERROR_HW_ADC_GROUP              (ERROR_MASK|HW_ADC_GROUP)
#define ERROR_HW_RTC_GROUP              (ERROR_MASK|HW_RTC_GROUP)
#define ERROR_HW_ALARM_GROUP            (ERROR_MASK|HW_ALARM_GROUP)
#define ERROR_HW_WATCHDOG_GROUP         (ERROR_MASK|HW_WATCHDOG_GROUP)
#define ERROR_HW_LRADC_GROUP            (ERROR_MASK|HW_LRADC_GROUP)
#define ERROR_HW_GPMI_GROUP             (ERROR_MASK|HW_GPMI_GROUP)
#define ERROR_HW_CLOCKS_GROUP           (ERROR_MASK|HW_CLOCKS_GROUP)
#define ERROR_HW_DRI_GROUP              (ERROR_MASK|HW_DRI_GROUP)
#define ERROR_HW_HWECC_GROUP            (ERROR_MASK|HW_HWECC_GROUP)
#define ERROR_HW_LCDIF_GROUP            (ERROR_MASK|HW_LCDIF_GROUP)
#define ERROR_HW_DCDC_GROUP             (ERROR_MASK|HW_DCDC_GROUP)
#define ERROR_HW_DCP_GROUP              (ERROR_MASK|HW_DCP_GROUP)
#define ERROR_HW_PINMUX_GROUP           (ERROR_MASK|HW_PINMUX_GROUP)

#endif//_HW_ERRORDEFS_H

