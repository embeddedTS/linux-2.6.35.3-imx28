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

#ifndef _INTERRUPTS_H
#define _INTERRUPTS_H

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include <drivers\ddi_icoll.h>

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
//! \brief TBD
#define PRIORITY_DAC_ISR		(IcollPriority_t)ICOLL_PRIORITY_LEVEL_2
//! \brief TBD
#define PRIORITY_DAC_ERROR		(IcollPriority_t)ICOLL_PRIORITY_LEVEL_1
//! \brief TBD
#define PRIORITY_ADC_DMA_ISR        (IcollPriority_t)ICOLL_PRIORITY_LEVEL_2
//! \brief TBD
#define PRIORITY_ADC_ERROR_ISR      (IcollPriority_t)ICOLL_PRIORITY_LEVEL_2
//! \brief TBD
#define PRIORITY_HP_SHORT_ISR       (IcollPriority_t)ICOLL_PRIORITY_LEVEL_2
//! \brief Video synchronization interrupt for the display driver
#define PRIORITY_VIDEO_ISR          (IcollPriority_t)ICOLL_PRIORITY_LEVEL_3

//! \brief Priority of the DCP ISR.  This does not change the priority of the
//! individual channels or the color space converter
#define PRIORITY_DCP_ISR		(IcollPriority_t)ICOLL_PRIORITY_LEVEL_2

//! \brief TBD
#define PRIORITY_LCDIF_ISR		(IcollPriority_t)ICOLL_PRIORITY_LEVEL_3

//! \brief TBD
#define DAC_ICOLL_FUNCTION_TYPE     (IcollFunctionType_t)IRQ_HANDLER_DEFERRED
//! \brief TBD
#define ADC_ICOLL_FUNCTION_TYPE     (IcollFunctionType_t)IRQ_HANDLER_DEFERRED
//! \brief TBD
#define LCDIF_ICOLL_FUNCTION_TYPE   (IcollFunctionType_t)IRQ_HANDLER_DEFERRED
//! \brief TBD
#define VIDEO_ICOLL_FUNCTION_TYPE   (IcollFunctionType_t)IRQ_HANDLER_DEFERRED

#endif // _INTERRUPTS_H

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
