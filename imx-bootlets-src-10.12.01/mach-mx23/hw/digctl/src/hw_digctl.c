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
//  Includes and external references
////////////////////////////////////////////////////////////////////////////////

#include "types.h"
#include "error.h"
#include "registers/regsdigctl.h"
#include "hw/digctl/hw_digctl.h"
////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////
static char const * const chipStr[] = {
    "TA1", "TA2", "TA3", "TA4", "TA5", "TA6",
    "TB1",
    "TC1",
    "???",
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////


// MUST BE IN OCRAM due to paging applications that need this functionality
// early on.  This should be fixed later on to be split up into a separate file
// and located by the framework as needed.
#pragma ghs section text=".ocram.text"

////////////////////////////////////////////////////////////////////////////////
//! See hw_digctl.h for details
////////////////////////////////////////////////////////////////////////////////
uint32_t hw_digctl_GetCurrentTime(void)
{
    return HW_DIGCTL_MICROSECONDS_RD();
}

////////////////////////////////////////////////////////////////////////////////
//! See hw_digctl.h for details
////////////////////////////////////////////////////////////////////////////////
bool hw_digctl_CheckTimeOut(uint32_t StartTime, uint32_t TimeOut)
{
    uint32_t    CurTime, EndTime;
    bool        bTimeOut;

    CurTime = HW_DIGCTL_MICROSECONDS_RD();
    EndTime = StartTime + TimeOut;

    if ( StartTime <= EndTime)
    {
        bTimeOut = ((CurTime >= StartTime) &&
		(CurTime < EndTime))? FALSE : TRUE;
    }
    else
    {
        bTimeOut =
		((CurTime >= StartTime) || (CurTime < EndTime))? FALSE : TRUE;
    }

    return bTimeOut;
}

void hw_digctl_MicrosecondWait(uint32_t u32Microseconds)
{
    uint32_t Start;

    //--------------------------------------------------------------------------
    // Get the start time.
    //--------------------------------------------------------------------------
    Start = HW_DIGCTL_MICROSECONDS_RD();

    //--------------------------------------------------------------------------
    // Loop until the timeout has elapsed.
    //--------------------------------------------------------------------------
    while(!hw_digctl_CheckTimeOut(Start,u32Microseconds));

}
#pragma ghs section

////////////////////////////////////////////////////////////////////////////////
//! See hw_digctl.h for details
////////////////////////////////////////////////////////////////////////////////
hw_digctl_packageType_t hw_digctl_CheckPackageType(void)
{
    hw_digctl_packageType_t pkgId = HW_PACKAGE_TYPE_169BGA;


    switch((hw_digctl_packageType_t)HW_DIGCTL_STATUS.B.PACKAGE_TYPE)
    {
    case HW_PACKAGE_TYPE_169BGA:
        pkgId = HW_PACKAGE_TYPE_169BGA;
        break;

    case HW_PACKAGE_TYPE_128TQFP:
        pkgId = HW_PACKAGE_TYPE_128TQFP;
        break;
    }

    return pkgId;

}

// See documentation in /hw/digctl/hw_digctl.h
hw_digctl_ChipAndRevision hw_digctl_GetChipRevision(void)
{
    hw_digctl_ChipAndRevision ChipAndRevision=HW_UNKNOWN_CHIP_OR_REVISION;

    switch(HW_DIGCTL_CHIPID.B.REVISION)
    {
		case 0x0:
			ChipAndRevision = HW_3780_TA1;
			break;
		case 0x1:
			ChipAndRevision = HW_3780_TA2;
			break;
		case 0x2:
			ChipAndRevision = HW_3780_TA3;
			break;
		case 0x3:
			ChipAndRevision = HW_3780_TA4;
			break;
    }

    return ChipAndRevision;
}

// Valid input values to set the ARM cache timing include ...
void hw_digctl_SetArmCacheTiming(uint16_t u16Timing)
{
    uint32_t u32Reg=0;

    // Set all the speed select value to the given timing value
    // This is best accomplished with one write or toggle to the
    // register so that all speed select fields are set to the
    // given value at once.

    u32Reg = ( (u16Timing << BP_DIGCTL_ARMCACHE_CACHE_SS) |
        (u16Timing << BP_DIGCTL_ARMCACHE_DTAG_SS) |
        (u16Timing << BP_DIGCTL_ARMCACHE_ITAG_SS) |
        (u16Timing << BP_DIGCTL_ARMCACHE_VALID_SS) |
        (u16Timing << BP_DIGCTL_ARMCACHE_DRTY_SS) );

    HW_DIGCTL_ARMCACHE.U = u32Reg;
}

// See documentation in /hw/digctl/hw_digctl.h
const char * hw_digctl_getChipRevStr(uint32_t revision)
{

    switch(revision)
    {
    case 0x00: return chipStr[CHIP_STR_TA1];
    case 0x01: return chipStr[CHIP_STR_TA2];
    case 0x02: return chipStr[CHIP_STR_TA3];
    case 0x03: return chipStr[CHIP_STR_TA4];
    }


    return chipStr[CHIP_STR_UNK];
}

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
