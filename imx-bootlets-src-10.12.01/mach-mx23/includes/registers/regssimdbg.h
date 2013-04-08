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

#ifndef REGSSIMDBG_H
#define REGSSIMDBG_H

// for documentation purposes only..... these addresses are in use, but not defined here.
#define REGSSIMGPMISELBEG 0x8003c050
#define REGSSIMGPMISELEND 0x8003c05c

#define REGSSIMMEMSELBEG  0x8003c070
#define REGSSIMMEMSELEND  0x8003c07c

#define REGSSIMSSPSELBEG  0x8003c0a0
#define REGSSIMSSPSELEND  0x8003c0ac

#define HW_BROWNOUT_GENERATOR_ADDR_DEFINITION  0x8003c500

// real definitions
#define HW_SIMDBG_CS_REG_ADDR    0x8003C000
#define HW_SIMDBG_PTR_REG_ADDR   0x8003C010
#define HW_SIMDBG_TERM_REG_ADDR  0x8003C020

#define HW_SIMDBG_UART_REG_ADDR    0x8003C090
#define HW_SIMDBG_CORESYS_REG_ADDR 0x8003c100
#define HW_SIMDBG_SAIF_LOOPBACK_REG_ADDR 0x8003c110

#define HW_SIMDBG_CORESYS_REG_WR(v) ((*(volatile u32 *) HW_SIMDBG_CORESYS_REG_ADDR) = (v))
#define HW_SIMDBG_UART_REG_WR(v)  ((*(volatile u32 *) HW_SIMDBG_UART_REG_ADDR) = (v))
#define HW_SIMDBG_SAIF_LOOPBACK_REG_WR(v)  ((*(volatile u32 *) HW_SIMDBG_SAIF_LOOPBACK_REG_ADDR) = (v))

#define HW_SIMDBG_ANATOP_PROBE_OUTPUT_SEL_ADDR 0x8003c200
#define HW_SIMDBG_ANATOP_PROBE_INPUT_SEL_ADDR  0x8003c210
#define HW_SIMDBG_ANATOP_PROBE_DATA_ADDR       0x8003c220
#define HW_SIMDBG_ANATOP_PROBE_DIGTOP_ADDR     0x8003c230

#define HW_SIMDBG_ANATOP_PROBE_OUTPUT_SEL_WR(v) ((*(volatile u32*) HW_SIMDBG_ANATOP_PROBE_OUTPUT_SEL_ADDR) = (v))
#define HW_SIMDBG_ANATOP_PROBE_INPUT_SEL_WR(v)  ((*(volatile u32*) HW_SIMDBG_ANATOP_PROBE_INPUT_SEL_ADDR) = (v))
#define HW_SIMDBG_ANATOP_PROBE_DATA_WR(v)       ((*(volatile u32*) HW_SIMDBG_ANATOP_PROBE_DATA_ADDR) = (v))
#define HW_SIMDBG_ANATOP_PROBE_DIGTOP_WR(v)     ((*(volatile u32*) HW_SIMDBG_ANATOP_PROBE_DIGTOP_ADDR) = (v))

#define HW_SIMDBG_LCDIFMON_ADDR                0x8003c600
#define HW_SIMDBG_LCDIFMON_LEN_ADDR            0x8003c610
#define HW_SIMDBG_FSDBDUMPING_ADDR             0x8003c520

#define HW_SIMDBG_LCDIFMONADDR_WR(v)            ((*(volatile u32*) HW_SIMDBG_LCDIFMON_ADDR) = (v))
#define HW_SIMDBG_LCDIFMONLEN_WR(v)             ((*(volatile u32*) HW_SIMDBG_LCDIFMON_LEN_ADDR) = (v))
#define HW_SIMDBG_FSDBDUMPING_WR(v)             ((*(volatile u32*) HW_SIMDBG_FSDBDUMPING_ADDR) = (v))

#endif
