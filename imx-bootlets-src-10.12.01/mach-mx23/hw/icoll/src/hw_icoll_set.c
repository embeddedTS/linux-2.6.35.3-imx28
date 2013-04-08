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
#include "hw/core/hw_core.h"
#include "hw/icoll/hw_icoll.h"
#include "hw_icoll_internal.h"
#include "registers/regsicoll.h"


////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//! Convert ddi priority typedef value to an integer for use with this chip.
///////////////////////////////////////////////////////////////////////////////
inline static uint32_t hw_icoll_Priority_Ddi2Hw( IcollPriority_t ePriority )

{
    uint32_t    uPriority;

	switch ( ePriority )
	{
		case ICOLL_PRIORITY_LEVEL_0 :
			uPriority = BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL0;
			break;

		case ICOLL_PRIORITY_LEVEL_1 :
			uPriority = BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL1;
			break;

		case ICOLL_PRIORITY_LEVEL_2 :
			uPriority = BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL2;
			break;

		case ICOLL_PRIORITY_LEVEL_3 :
			uPriority = BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL3;
			break;
	}

    return uPriority;
}


///////////////////////////////////////////////////////////////////////////////
//! Convert an integer for use with this chip to a ddi priority typedef value
///////////////////////////////////////////////////////////////////////////////
inline static IcollPriority_t hw_icoll_Priority_Hw2Ddi( uint32_t uPriority  )

{
    IcollPriority_t tPriority;

	switch ( uPriority )
	{
		case BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL0 :
			tPriority = ICOLL_PRIORITY_LEVEL_0;
			break;

		case BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL1 :
			tPriority = ICOLL_PRIORITY_LEVEL_1;
			break;

		case BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL2 :
			tPriority = ICOLL_PRIORITY_LEVEL_2;
			break;

		case BV_ICOLL_INTERRUPTn_PRIORITY__LEVEL3 :
			tPriority = ICOLL_PRIORITY_LEVEL_3;
			break;
	}

    return tPriority;
}



#pragma ghs section text=".ocram.text"
///////////////////////////////////////////////////////////////////////////////
//! See hw_icoll.h for details.
///////////////////////////////////////////////////////////////////////////////
bool hw_icoll_EnableVector(ICOLL_IRQ_enums_t eIrqVectorNumber, bool bEnable)
{
    bool b_previousEnableState;

	b_previousEnableState=
		(HW_ICOLL_INTERRUPTn(eIrqVectorNumber).B.ENABLE)?true:false;
	if (bEnable)
		HW_ICOLL_INTERRUPTn_SET(eIrqVectorNumber,
			BM_ICOLL_INTERRUPTn_ENABLE);
	else
		HW_ICOLL_INTERRUPTn_CLR(eIrqVectorNumber,
			BM_ICOLL_INTERRUPTn_ENABLE);

    return b_previousEnableState;
}


#pragma ghs section


////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}

