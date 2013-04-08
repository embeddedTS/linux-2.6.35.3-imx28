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

#ifndef _DDI_ERRORDEFS_H
#define _DDI_ERRORDEFS_H

#include "errordefs.h"
#include "ddi_subgroups.h"

#define ERROR_DDI_UART_DEBUG_GROUP      (ERROR_MASK |DDI_UART_DEBUG_GROUP)
#define ERROR_DDI_UARTAPP_GROUP         (ERROR_MASK |DDI_UARTAPP_GROUP)
#define ERROR_DDI_LED_GROUP             (ERROR_MASK |DDI_LED_GROUP)
#define ERROR_DDI_TIMER_GROUP           (ERROR_MASK |DDI_TIMER_GROUP)
#define ERROR_DDI_PWM_OUTPUT_GROUP      (ERROR_MASK |DDI_PWM_OUTPUT_GROUP)
#define ERROR_DDI_ETM_GROUP				(ERROR_MASK |DDI_ETM_GROUP)
#define ERROR_DDI_SSP_GROUP             (ERROR_MASK |DDI_SSP_GROUP)
#define ERROR_DDI_I2C_GROUP             (ERROR_MASK |DDI_I2C_GROUP)
#define ERROR_DDI_LDL_GROUP             (ERROR_MASK |DDI_LDL_GROUP)
#define ERROR_DDI_USB_GROUP             (ERROR_MASK |DDI_USB_GROUP)
#define ERROR_DDI_LCDIF_GROUP           (ERROR_MASK |DDI_LCDIF_GROUP)
#define ERROR_DDI_ADC_GROUP             (ERROR_MASK |DDI_ADC_GROUP)
#define ERROR_DDI_RTC_GROUP             (ERROR_MASK |DDI_RTC_GROUP)
#define ERROR_DDI_ALARM_GROUP           (ERROR_MASK |DDI_ALARM_GROUP)
#define ERROR_DDI_FM_TUNER_GROUP        (ERROR_MASK |DDI_FM_TUNER_GROUP)
#define ERROR_DDI_LRADC_GROUP           (ERROR_MASK |DDI_LRADC_GROUP)
#define ERROR_DDI_GPIO_GROUP            (ERROR_MASK |DDI_GPIO_GROUP)
#define ERROR_DDI_DISPLAY_GROUP         (ERROR_MASK |DDI_DISPLAY_GROUP)
#define ERROR_DDI_PSWITCH_GROUP         (ERROR_MASK |DDI_PSWITCH_GROUP)
#define ERROR_DDI_BCM_GROUP             (ERROR_MASK |DDI_BCM_GROUP)
#define ERROR_DDI_DRI_GROUP             (ERROR_MASK |DDI_DRI_GROUP)
#define ERROR_DDI_CLOCKS_GROUP          (ERROR_MASK |DDI_CLOCKS_GROUP)
#define ERROR_DDI_MEDIA_CACHE_GROUP     (ERROR_MASK |DDI_MEDIA_CACHE_GROUP)
#define ERROR_DDI_MEDIABUFMGR_GROUP     (ERROR_MASK |DDI_MEDIABUFMGR_GROUP)
#define ERROR_DDI_NAND_GROUP            (ERROR_MASK |DDI_NAND_GROUP)
#define ERROR_DDI_LBA_NAND_GROUP        (ERROR_MASK |DDI_LBA_NAND_GROUP)
#define ERROR_DDI_NAND_GPMI_GROUP       (ERROR_MASK |DDI_NAND_GPMI_GROUP)
#define ERROR_DDI_MMC_GROUP             (ERROR_MASK |DDI_MMC_GROUP)
#define ERROR_DDI_DCP_GROUP             (ERROR_MASK |DDI_DCP_GROUP)
#define ERROR_DDI_POWER_GROUP           (ERROR_MASK |DDI_POWER_GROUP)
#define ERROR_DDI_EMI_GROUP             (ERROR_MASK |DDI_EMI_GROUP)
#define ERROR_DDI_RNG_GROUP             (ERROR_MASK |DDI_RNG_GROUP)
#define ERROR_DDI_UART_GROUP            (ERROR_MASK |DDI_UART_GROUP)

#endif//_DDI_ERRORDEFS_H

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
