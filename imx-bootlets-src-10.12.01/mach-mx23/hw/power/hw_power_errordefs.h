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


#ifndef _HW_POWER_ERRORDEFS_H
#define _HW_POWER_ERRORDEFS_H

#include "hw/hw_errordefs.h"


#define ERROR_HW_DCDC_GENERAL                                    (ERROR_HW_DCDC_GROUP)
#define ERROR_HW_DCDC_INVALID_INPUT_PARAM                        (ERROR_HW_DCDC_GROUP + 1)


#define ERROR_HW_POWER_GROUP                                      (ERROR_HW_DCDC_GROUP)
#define ERROR_HW_POWER_GENERAL                                    (ERROR_HW_POWER_GROUP)
#define ERROR_HW_POWER_INVALID_POWER_FET_SETTING                  (ERROR_HW_POWER_GROUP + 0x1)
#define ERROR_HW_POWER_INVALID_LINREG_STEP                        (ERROR_HW_POWER_GROUP + 0x2)
#define ERROR_HW_POWER_UNSAFE_VDDD_VOLTAGE                        (ERROR_HW_POWER_GROUP + 0x3)
#define ERROR_HW_POWER_INVALID_VDDD_VOLTAGE                       (ERROR_HW_POWER_GROUP + 0x4)
#define ERROR_HW_POWER_INVALID_VDDD_BO_LEVEL                      (ERROR_HW_POWER_GROUP + 0x5)
#define ERROR_HW_POWER_UNSAFE_VDDA_VOLTAGE                        (ERROR_HW_POWER_GROUP + 0x6)
#define ERROR_HW_POWER_INVALID_VDDA_VOLTAGE                       (ERROR_HW_POWER_GROUP + 0x7)
#define ERROR_HW_POWER_INVALID_VDDA_BO_LEVEL                      (ERROR_HW_POWER_GROUP + 0x8)
#define ERROR_HW_POWER_UNSAFE_VDDIO_VOLTAGE                       (ERROR_HW_POWER_GROUP + 0x9)
#define ERROR_HW_POWER_INVALID_VDDIO_VOLTAGE                      (ERROR_HW_POWER_GROUP + 0x10)
#define ERROR_HW_POWER_INVALID_VDDIO_BO_LEVEL                     (ERROR_HW_POWER_GROUP + 0x11)
#define ERROR_HW_POWER_AUTO_XFER_TO_DCDC_ENABLED                  (ERROR_HW_POWER_GROUP + 0x12)
#define ERROR_HW_POWER_INVALID_BATT_MODE                          (ERROR_HW_POWER_GROUP + 0x13)
#define ERROR_HW_POWER_INVALID_INPUT_PARAM                        (ERROR_HW_POWER_GROUP + 0x14)
#define ERROR_HW_POWER_BAD_ARGUMENT                               (ERROR_HW_POWER_GROUP + 0x15)
#define ERROR_HW_POWER_4P2_ALREADY_ON                             (ERROR_HW_POWER_GROUP + 0x16)

#endif//_HW_POWER_ERRORDEFS_H
