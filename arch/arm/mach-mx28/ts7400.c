/*
 * Copyright (C) 2009-2010 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>

#include <asm/setup.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>

#include <mach/hardware.h>
#include <mach/device.h>
#include <mach/pinctrl.h>

#include <linux/spi/spi.h>
#include <linux/spi/flash.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/physmap.h>

#include "device.h"
#include "ts7400.h"

static struct i2c_board_info __initdata mxs_i2c_device[] = {
	{ I2C_BOARD_INFO("sgtl5000-i2c", 0xa), .flags = I2C_M_TEN },
	{ I2C_BOARD_INFO("m41t00", 0x68)}
};

static void __init i2c_device_init(void)
{
	i2c_register_board_info(0, mxs_i2c_device, ARRAY_SIZE(mxs_i2c_device));
}
#if defined(CONFIG_MTD_M25P80) || defined(CONFIG_MTD_M25P80_MODULE)
static struct flash_platform_data mx28_spi_flash_data = {
	.name = "m25p80",
	.type = "w25x80",
};
#endif

static struct spi_board_info spi_board_info[] __initdata = {
#if defined(CONFIG_SPI_MXS) || defined(CONFIG_SPI_MXS_MODULE)
	{
		/* the modalias must be the same as spi device driver name */
		.modalias = "spidev", /* Name of spi_driver for this device */
		.max_speed_hz = 20000000,     /* max spi clock (SCK) speed in HZ */
		.bus_num = 1, /* Framework bus number */
		.chip_select = 0, /* Framework chip select. */
		.mode = SPI_MODE_0,
		//.platform_data = &mx28_spi_flash_data,
	},
#endif
};

static void spi_device_init(void)
{
	spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
}

static void __init fixup_board(struct machine_desc *desc, struct tag *tags,
			       char **cmdline, struct meminfo *mi)
{
	mx28_set_input_clk(24000000, 24000000, 32000, 50000000);
}

#if 0
//#if defined(CONFIG_LEDS_MXS) || defined(CONFIG_LEDS_MXS_MODULE)
static struct mxs_pwm_led  mx28evk_led_pwm[2] = {
	[0] = {
		.name = "led-pwm0",
		.pwm = 0,
		},
	[1] = {
		.name = "led-pwm1",
		.pwm = 1,
		},
};

struct mxs_pwm_leds_plat_data mx28evk_led_data = {
	.num = ARRAY_SIZE(mx28evk_led_pwm),
	.leds = mx28evk_led_pwm,
};

static struct resource mx28evk_led_res = {
	.flags = IORESOURCE_MEM,
	.start = PWM_PHYS_ADDR,
	.end   = PWM_PHYS_ADDR + 0x3FFF,
};

static void __init mx28evk_init_leds(void)
{
	struct platform_device *pdev;

	pdev = mxs_get_device("mxs-leds", 0);
	if (pdev == NULL || IS_ERR(pdev))
		return;

	pdev->resource = &mx28evk_led_res;
	pdev->num_resources = 1;
	pdev->dev.platform_data = &mx28evk_led_data;
	mxs_add_device(pdev, 3);
}
#else
static void __init mx28evk_init_leds(void)
{
	;
}
#endif

static void __init mx28evk_device_init(void)
{
	/* Add mx28evk special code */
	i2c_device_init();
	spi_device_init();
	mx28evk_init_leds();
}

static void __init i2c_pause(void) { udelay(2); }
#define scl_z do { i2c_pause(); iowrite32((1 << 24), (dio + 0x2ce)); } while(0)
#define scl_0 do { i2c_pause(); iowrite32((1 << 24), (dio + 0x2cd)); } while(0)
#define sda_z do { i2c_pause(); iowrite32((1 << 25), (dio + 0x2ce)); } while(0)
#define sda_0 do { i2c_pause(); iowrite32((1 << 25), (dio + 0x2cd)); } while(0)
#define sda_in (ioread32((dio + 0x24c)) & (1 << 25))
static int __init get_M0_id(void) {
	volatile unsigned int *dio = NULL;
	unsigned int d, i, ack, ret;

	request_mem_region(0x80018000, 4095, "gpio");
	dio = ioremap(0x80018000, 4095);

	/* Set NAND D7 pullup, we may need to test this later */
	iowrite32((1 << 7), (dio + 0x181));
	
	iowrite32(0xf0000, (dio + 0x5d)); /* scl/sda GPIO mode */
	iowrite32(0x3000000, (dio + 0x2ce)); /* tristate sda/scl */
	iowrite32(0x3000000, (dio + 0x138)); /* sda/scl low */



	scl_z; /* tristate, scl/sda pulled up */
	sda_z;

	sda_0; /* i2c, start (sda low) */
	for (d = (0x78<<1)+1, i = 0; i < 7; i++, d <<= 1) {
		scl_0; /* scl low */
		if (d & 0x80) sda_z; else sda_0;
		scl_z; /* scl high */
	}
	scl_0;
	sda_z;
	scl_z;

	scl_0;
	sda_z; /* scl low, tristate sda */
	scl_z; /* scl high, tristate sda */
	scl_z; /* scl high, tristate sda */
	ack = sda_in; /* sample ack */
	for (d = 0; d < 17; d++) {
		for (ret = i = 0; i < 8; i++) {
			scl_0; /* scl low, tri sda */
			sda_z;
			scl_z; /* scl high, tri sda */
			scl_z; /* scl high, tri sda (for timing) */
			ret <<= 1;
			ret |= sda_in ? 1 : 0;
		}
		if(d != 16) {
			scl_0;
			sda_0;
			scl_z;
			scl_z;
		}
	}
	scl_0;
	sda_z;
	scl_z;
	scl_z;
	scl_0;
	sda_0;
	scl_z;
	sda_z;

	ret &= 0xf;

	switch(ret) {
	/* The addition of eMMC on the mx28s was a huge change in the series.
	 * The difference is unknown by uC, and is only seen with a CPU 
	 * strapping pin.  Revs that went this way drop NAND and use eMMC on SSP1
         * which is bootable.
	 */
	  case 0x0: //and 0x4
		if(!((ioread32(dio + 0x240)) & (1 << 7))) ret = 0x4;
		/* 4 is 7400 rev B+
		 * Userspace can check for eMMC or NAND
		 */
		printk(KERN_INFO "boardID=7400\n");
		break;
	  case 0x1: //and 0x3
		if(!((ioread32(dio + 0x240)) & (1 << 7))) ret = 0x3;
		/* 3 is 7670 rev C+
		 * Userspace can check for eMMC or NAND
		 */
		printk(KERN_INFO "boardID=7670\n");
		break;
	  case 0x2:
		printk(KERN_INFO "boardID=7680\n");
		break;
	  default:
		printk(KERN_INFO "boardID=unknown\n");
		break;
	}

	iounmap(dio);
	release_mem_region(0x80018000, 4095);

	return ret;
}

		
static void __init mx28evk_init_machine(void)
{
	int boardid;

	boardid = get_M0_id();

	mx28_pinctrl_init();
	/* Init iram allocate */
#ifdef CONFIG_VECTORS_PHY_ADDR
	/* reserve the first page for irq vector table*/
	iram_init(MX28_OCRAM_PHBASE + PAGE_SIZE, MX28_OCRAM_SIZE - PAGE_SIZE);
#else
	iram_init(MX28_OCRAM_PHBASE, MX28_OCRAM_SIZE);
#endif

	mx28_gpio_init();
	mx28evk_pins_init(boardid);
	mx28_device_init(boardid);
	mx28evk_device_init();
}

MACHINE_START(MX28EVK, "Technologic Systems TS-7400/TS-7670/TS-7680")
	.phys_io	= 0x80000000,
	.io_pg_offst	= ((0xf0000000) >> 18) & 0xfffc,
	.boot_params	= 0x40000100,
	.fixup		= fixup_board,
	.map_io		= mx28_map_io,
	.init_irq	= mx28_irq_init,
	.init_machine	= mx28evk_init_machine,
	.timer		= &mx28_timer.timer,
MACHINE_END
