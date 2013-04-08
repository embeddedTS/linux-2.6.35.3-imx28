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

#ifndef __CORE_H
#define __CORE_H

#include "types.h"

#if defined(HW_TARGET_BRAZOS)
//! \brief TBD
#define VECTOR_OFFSET 0x0000
#elif defined(HW_TARGET_SIMULATOR)
//! \brief TBD
#define VECTOR_OFFSET 0x0000
#else
//! \brief TBD
#define VECTOR_OFFSET 0x80000000
#endif

//! \brief TBD
typedef enum
{
    //! \brief TBD
    VECTOR_RESET                   = 0,
    //! \brief TBD
    VECTOR_UNDEFINED_INSTRUCTION   = 1,
    //! \brief TBD
    VECTOR_SWI                     = 2,
    //! \brief TBD
    VECTOR_PREFETCH_ABORT          = 3,
    //! \brief TBD
    VECTOR_DATA_ABORT              = 4,
//  VECTOR_RESERVED                = 5,  // Comment out since not real.
    //! \brief TBD
    VECTOR_IRQ                     = 6,
    //! \brief TBD
    VECTOR_FIQ                     = 7,
    //! \brief TBD
    NUMBER_VECTORS                 = 8
} HwCoreVector_t;

//! \brief TBD
typedef void (*pvoid_void_t)(void);

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
//!     \brief       Enable or disable the IRQ Interrupt.
//!     \fntype:     Non-reentrant.
//!     \param[in]	 bEnable holds the enable/disable flag (true = enable)
//!     \retval      bool previous state of IRQ Interrupt.
////////////////////////////////////////////////////////////////////////////////
bool hw_core_EnableIrqInterrupt(bool bEnable);

////////////////////////////////////////////////////////////////////////////////
//!     \brief       Enable or disable the FIQ Interrupt.
//!     \fntype:     Non-reentrant.
//!     \param[in]	 bEnable holds the enable/disable flag (true = enable)
//!     \retval      bool previous state of FIQ Interrupt.
////////////////////////////////////////////////////////////////////////////////
bool hw_core_EnableFiqInterrupt(bool bEnable);



#ifdef __cplusplus
} // extern "C"
#endif

#endif //__CORE_H

///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
//! @}

