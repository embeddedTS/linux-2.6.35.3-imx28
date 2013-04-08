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


#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include "assert.h"
//! \brief TBD
//! \todo [PUBS] Add definition(s)...
//! \todo Where does this really go?
typedef struct
{
    //! \brief TBD
    uint32_t val[4];
} uint128_t;

//! \brief TBD
#ifndef RETCODE
#define RETCODE int
#endif

//------------------------------------------------------------------------------
// All of the following defs are included for compatability.  Please use the
// ANSI C99 defs for all new work.
//------------------------------------------------------------------------------

//! \brief TBD
#if !defined(FALSE)
#define FALSE false
#endif

//! \brief TBD
#if !defined(TRUE)
#define TRUE  true
#endif

//! \brief TBD
#if !defined(NULL)
#define NULL 0
#endif

//! \brief TBD
typedef bool        BOOL;

//! \brief TBD
typedef uint8_t     UINT8;
//! \brief TBD
typedef uint8_t     BYTE;
//! \brief TBD
typedef uint8_t     PACKED_BYTE;

//! \brief TBD
typedef uint16_t    UINT16;
//! \brief TBD
typedef uint16_t    USHORT;
//! \brief TBD
typedef uint16_t    WCHAR;
//! \brief TBD
typedef uint16_t    UCS3;
//! \brief TBD
typedef int16_t     SHORT;

//! \brief TBD
typedef uint32_t    UINT32;
//! \brief TBD
typedef uint32_t    WORD;
//! \brief TBD
typedef uint32_t    SECTOR_BUFFER;
//! \brief TBD
typedef uint32_t *  P_SECTOR_BUFFER;

//! \brief TBD
typedef uint64_t    DWORD;
//! \brief TBD
typedef int64_t     INT64;
//! \brief TBD
typedef int64_t     UINT64;

//! \brief TBD
typedef uint128_t   UINT128;

//! \brief TBD
typedef float       FLOAT;

//! \brief TBD
#define FRACT       _fract
//! \brief TBD
#define CIRC        _circ

//! \brief Provides a default of 16 bytes (128 bits / 8 bits per byte)
#ifndef MAX_NUM_RAW_SERIAL_NUMBER_BYTES
    #define MAX_NUM_RAW_SERIAL_NUMBER_BYTES (16)
#endif

//! \brief Provides a default value that allows each nibble of raw to be
//! converted to its
//! ASCII hex character (1 extra for NULL termination)
#ifndef MAX_NUM_ASCII_SERIAL_NUMBER_CHARS
   #define MAX_NUM_ASCII_SERIAL_NUMBER_CHARS (2*MAX_NUM_RAW_SERIAL_NUMBER_BYTES)
#endif

//! \brief Serial number.
typedef struct SerialNumber
{
    //! \brief TBD
    uint8_t rawSizeInBytes;
    //! \brief TBD
    uint8_t asciiSizeInChars;
    //! \brief TBD
    uint8_t raw[MAX_NUM_RAW_SERIAL_NUMBER_BYTES];
    // One extra for NULL termination
    char ascii[MAX_NUM_ASCII_SERIAL_NUMBER_CHARS+1];
} SerialNumber_t;

//------------------------------------------------------------------------------
// Huh?
//------------------------------------------------------------------------------

//! \brief TBD
#define REENTRANT

//------------------------------------------------------------------------------
// Debug macros in types.h?
//------------------------------------------------------------------------------

//! \brief TBD
#ifdef DEBUG
#define IFDEBUG(x) x
#else
#define IFDEBUG(x)
#endif

//------------------------------------------------------------------------------
// This sets the default build of the target
//------------------------------------------------------------------------------

//! \brief TBD
#if !defined(HW_TARGET_ASIC) && !defined(HW_TARGET_SIMULATOR)
#define HW_TARGET_BRAZOS 1
#endif

//------------------------------------------------------------------------------
// Win32 compatibility?
//------------------------------------------------------------------------------

//! \brief TBD
#ifdef _WIN32
#define inline __inline
#endif

#endif // #ifndef _TYPES_H

///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////
//! @}
