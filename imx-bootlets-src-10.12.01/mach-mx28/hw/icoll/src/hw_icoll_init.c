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
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "hw/icoll/hw_icoll.h"
#include "hw_icoll_internal.h"
#include "registers/regsicoll.h"


////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//! See hw_icoll.h for details.
///////////////////////////////////////////////////////////////////////////////
void hw_icoll_SetFiqMode(ICOLL_FIQ_enums_t eIrqVectorNumber, bool bEnable)
{
	if(bEnable)
            HW_ICOLL_INTERRUPTn_SET(eIrqVectorNumber,
		BM_ICOLL_INTERRUPTn_ENFIQ);
        else
            HW_ICOLL_INTERRUPTn_CLR(eIrqVectorNumber,
		 BM_ICOLL_INTERRUPTn_ENFIQ);
}

///////////////////////////////////////////////////////////////////////////////
//! See hw_icoll.h for details.
///////////////////////////////////////////////////////////////////////////////
bool hw_icoll_CtrlRegisterUpdate(
            IcollCtrlRegisterEnums_t ControlRegisterField, bool bSet)
{
    uint32_t u32_icollControl = HW_ICOLL_CTRL_RD();

    if(bSet)
        HW_ICOLL_CTRL_SET(1<<ControlRegisterField);
    else
        HW_ICOLL_CTRL_CLR(1<<ControlRegisterField);

    return (u32_icollControl >> ControlRegisterField) & 0x00000001;
}



////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
