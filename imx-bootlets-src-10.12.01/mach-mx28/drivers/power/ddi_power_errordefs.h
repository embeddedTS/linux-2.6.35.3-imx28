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

#ifndef _DDI_POWER_ERRORDEFS_H
#define _DDI_POWER_ERRORDEFS_H

#include "drivers/ddi_errordefs.h"


#define ERROR_DDI_POWER_GENERAL                                 (ERROR_DDI_POWER_GROUP)
#define ERROR_DDI_POWER_HCLK_SLOW_TOO_LOW                       (ERROR_DDI_POWER_GROUP + 1)
#define ERROR_DDI_POWER_HCLK_FAST_TOO_HIGH                      (ERROR_DDI_POWER_GROUP + 2)
#define ERROR_DDI_POWER_CANT_MEET_HCLK_CONSTRAINTS              (ERROR_DDI_POWER_GROUP + 3)
#define ERROR_DDI_POWER_PLL_OFF_BUT_NOT_BYPASSED                (ERROR_DDI_POWER_GROUP + 4)

#define ERROR_DDI_POWER_INVALID_PCLK_FREQ                       (ERROR_DDI_POWER_GROUP)
#define ERROR_DDI_POWER_INVALID_XCLK_FREQ                       (ERROR_DDI_POWER_GROUP + 1)
#define ERROR_DDI_POWER_INVALID_EMICLK_FREQ                     (ERROR_DDI_POWER_GROUP + 2)
#define ERROR_DDI_POWER_INVALID_POWER_SOURCE                    (ERROR_DDI_POWER_GROUP + 3)
#define ERROR_DDI_POWER_VDDD_PARAM_ADJUSTED                     (ERROR_DDI_POWER_GROUP + 4)
#define ERROR_DDI_POWER_VDDA_PARAM_ADJUSTED                     (ERROR_DDI_POWER_GROUP + 5)
#define ERROR_DDI_POWER_VDDIO_PARAM_ADJUSTED                    (ERROR_DDI_POWER_GROUP + 6)
#define ERROR_DDI_POWER_INVALID_PARAM                           (ERROR_DDI_POWER_GROUP + 7)
#define ERROR_DDI_FAILED_TO_START_4P2_RAIL                      (ERROR_DDI_POWER_GROUP + 8)
#define ERROR_DDI_FAILED_TO_PREPARE_4P2_RAIL                    (ERROR_DDI_POWER_GROUP + 9)
#define ERROR_DDI_POWER_BATT_TOO_LOW_FOR_HANDOFF                (ERROR_DDI_POWER_GROUP + 10)
#define ERROR_DDI_POWER_5V_LOST_DURING_4P2_CHARGE               (ERROR_DDI_POWER_GROUP + 11)
#endif//_DDI_POWER_ERRORDEFS_H




