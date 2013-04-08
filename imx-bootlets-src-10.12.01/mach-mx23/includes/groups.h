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

#ifndef _GROUPS_H
#define _GROUPS_H

///////////////////////////////////////////////////////////////////////////////
//! \addtogroup common
//! @{
//
// Copyright (c) 2004-2005 SigmaTel, Inc.
//
//! \file groups.h
//! \brief  Contains group codes.
//!
//! \code
//! 0x00000000, 0xFFFFFFFF, and 0x8000000 - 0xAFFFFFFF reserved for Sigmatel
//! 0xB0000000 - 0xFFFFFFFE available for customer use
//! \endcode
//! 768 Major groups for Sigmatel, 1280 Major groups for customers\n
//! 256 Minor groups per Major group\n
//! \code
//! Bit            3322 2222 2222 1111 1111 11
//!                1098 7654 3210 9876 5432 1098 7654 3210
//!                ---------------------------------------
//! Major Groups:  ---- MMMM MMMM ---- ---- ---- ---- ----
//! Minor Groups:  ---- ---- ---- mmmm mmmm ---- ---- ----
//! Errors:        ---- ---- ---- ---- ---- eeee eeee eeee
//! \endcode
//!


//the below is ugly, but its the only way to solve the int typedef type checking
// where errors show up as negative
#define HW_GROUP                  (0x00100000) //0x80100000
#define DDI_GROUP                 (0x00200000) //0x80200000
#define OS_GROUP                  (0x00300000) //0x80300000
#define MIDDLEWARE_GROUP          (0x00400000) //0x80400000
#define ROM_GROUP                 (0x00500000) //0x80500000
#define BM_GROUP                  (0x00600000) //0x80600000
#define APPS_GROUP                (0x00700000) //0x80700000
#define UTILITY_GROUP             (0x00800000) //0x80800000
#endif//_GROUPS_H

