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

  .file	"hw_core_asm_interrupt.S"
	.text

    .global hw_core_EnableIrqInterrupt
    .global hw_core_EnableFiqInterrupt

/*
//!
//!     \brief       Enable or disable the IRQ Interrupt.
//!
//!     \fntype:     Non-reentrant.
//!
//!     Description  Enable or disable the IRQ Interrupt.
//!
//!     \param[in]	 bool r0 holds the enable/disable flag (true = enable)
//!
//!     \retval      bool previous state of IRQ Interrupt.
//!
//!     Notes:
//!
//////////////////////////////////////////////////////////////////////////////*/
hw_core_EnableIrqInterrupt:
    MRS     r2,CPSR            @Save Current Program Status Register
    teq     r0,#0
    bicNE   r1,r2,#0x80        @Disable IRQ if clear
    orrEQ   r1,r2,#0x80        @Enable IRQ if set.
    MSR     CPSR_c,r1
    tst     r2,#0x80
    movne   r0,#0
    moveq   r0,#1
    bx      lr

/*
//!
//!     \brief       Enable or disable the FIQ Interrupt.
//!
//!     \fntype:     Non-reentrant.
//!
//!     Description  Enable or disable the FIQ Interrupt.
//!
//!     \param[in]	 bool r0 holds the enable/disable flag (true = enable)
//!
//!     \retval      bool previous state of FIQ Interrupt.
//!
//!     Notes:
//!
//////////////////////////////////////////////////////////////////////////////*/
hw_core_EnableFiqInterrupt:
    MRS     r2,CPSR            @Save Current Program Status Register.
    teq     r0,#0
    bicNE   r1,r2,#0x40        @Disable FIQ if clear.
    orrEQ   r1,r2,#0x40        @Enable FIQ if set.
    MSR     CPSR_c,r1
    tst     r2,#0x40
    movne   r0,#0
    moveq   r0,#1
    bx      lr
