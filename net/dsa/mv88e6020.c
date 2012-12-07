/*
 * net/dsa/mv88e6020.c - Driver for Marvell 88e6060 switch chips
 * Copyright (c) 2008-2009 Marvell Semiconductor
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/list.h>
#include <linux/netdevice.h>
#include <linux/phy.h>
#include "dsa_priv.h"

#define REG_PORT(p)		(0x8 + (p+loc))
#define REG_GLOBAL1		(0x0f + (loc))
#define REG_GLOBAL2		(0x07 + (loc))

int loc;

static int reg_read(struct dsa_switch *ds, int addr, int reg)
{
	return mdiobus_read(ds->master_mii_bus, addr, reg);
}

#define REG_READ(addr, reg)					\
	({							\
		int __ret;					\
								\
		__ret = reg_read(ds, addr, reg);		\
		if (__ret < 0)					\
			return __ret;				\
		__ret;						\
	})


static int reg_write(struct dsa_switch *ds, int addr, int reg, u16 val)
{
	return mdiobus_write(ds->master_mii_bus, addr, reg, val);
}

#define REG_WRITE(addr, reg, val)				\
	({							\
		int __ret;					\
								\
		__ret = reg_write(ds, addr, reg, val);		\
		if (__ret < 0)					\
			return __ret;				\
	})

static char *mv88e6020_probe(struct mii_bus *bus, int sw_addr)
{
	int ret;

	printk(KERN_ERR "Kris: PRobing for 6020 %d\n",sw_addr);
	for(loc = 0; loc <= 0x10; loc += 0x10) {
		ret = mdiobus_read(bus, REG_PORT(0), 0x03);
		if (ret >= 0) {
			printk(KERN_ERR "Kris: ret = %X\n", ret);
			ret &= 0xfff0;
			if (ret == 0x0200)
				return "Marvell 88E6020";
		}
	}
	
	printk(KERN_ERR "Kris: made it here?\n");

	return NULL;
}

/* Cleared for 6020 */
static int mv88e6020_switch_reset(struct dsa_switch *ds)
{
	int i;
	int ret;

	/*
	 * Set all ports to the disabled state.
	 */
	for (i = 0; i < 7; i++) {
		ret = REG_READ(REG_PORT(i), 0x04);
		REG_WRITE(REG_PORT(i), 0x04, ret & 0xfffc);
	}

	/*
	 * Wait for transmit queues to drain.
	 */
	msleep(2);

	/*
	 * Reset the switch.
	 */
	//Set per the original mv88e6060 code
	REG_WRITE(REG_GLOBAL1, 0x0a, 0x2130);
	//Sets reset, this also disables all interrupts, might not be wise
	REG_WRITE(REG_GLOBAL1, 0x04, 0x8400);

	/*
	 * Wait up to one second for reset to complete.
	 */
	for (i = 0; i < 1000; i++) {
		ret = REG_READ(REG_GLOBAL1, 0x00);
		//The code originally checked bit15, but the 6060 manual calls this reserved
		//Using bit 11 is a best guess
		if (ret & 0x800)
			break;

		msleep(1);
	}
	if (i == 1000)
		return -ETIMEDOUT;

	return 0;
}

/* Cleared for 6020 */
static int mv88e6020_setup_global(struct dsa_switch *ds)
{
	/*
	 * Disable discarding of frames with excessive collisions,
	 * set the maximum frame size to 1536 bytes, and mask all
	 * interrupt sources.
	 */
	//Set to 2048 instead
	REG_WRITE(REG_GLOBAL1, 0x04, 0x0400);

	/*
	 * Enable automatic address learning, set the address
	 * database size to 1024 entries, and set the default aging
	 * time to 5 minutes.
	 */
	REG_WRITE(REG_GLOBAL1, 0x0a, 0x2130);

	return 0;
}

/* Cleared for 6020*/
static int mv88e6020_setup_port(struct dsa_switch *ds, int p)
{
	int addr = REG_PORT(p);

	/*
	 * Do not force flow control, disable Ingress and Egress
	 * Header tagging, disable VLAN tunneling, and set the port
	 * state to Forwarding.  Additionally, if this is the CPU
	 * port, enable Ingress and Egress Trailer tagging mode.
	 */
	//All the damn names have changed between 6060 and 6020
	REG_WRITE(addr, 0x04, dsa_is_cpu_port(ds, p) ?  0x200f : 0x000f);
	REG_WRITE(addr, 0x01, 0x3);

	/*
	 * Port based VLAN map: give each port its own address
	 * database, allow the CPU port to talk to each of the 'real'
	 * ports, and allow each of the 'real' ports to only talk to
	 * the CPU port.
	 */
	/* I dont think we want this to happen, function as a normal switch
	 * According to the 6020 datasheet, the VLAN port mapping comes up
	 * by default with every port able to talk to every other port */
	/*REG_WRITE(addr, 0x06,
			((p & 0xf) << 12) |
			 (dsa_is_cpu_port(ds, p) ?
				ds->phys_port_mask :
				(1 << ds->dst->cpu_port)));
*/
	/*
	 * Port Association Vector: when learning source addresses
	 * of packets, add the address to the address database using
	 * a port bitmap that has only the bit for this port set and
	 * the other bits clear.
	 */
	REG_WRITE(addr, 0x0b, 1 << p);

	return 0;
}

static int mv88e6020_setup(struct dsa_switch *ds)
{
	int i;
	int ret;

	ret = mv88e6020_switch_reset(ds);
	if (ret < 0)
		return ret;

	/* @@@ initialise atu */

	ret = mv88e6020_setup_global(ds);
	if (ret < 0)
		return ret;

	for (i = 0; i < 6; i++) {
		ret = mv88e6020_setup_port(ds, i);
		if (ret < 0)
			return ret;
	}

	return 0;
}

/* Not used in the 6020? */
static int mv88e6020_set_addr(struct dsa_switch *ds, u8 *addr)
{
	//REG_WRITE(REG_GLOBAL, 0x01, (addr[0] << 8) | addr[1]);
	//REG_WRITE(REG_GLOBAL, 0x02, (addr[2] << 8) | addr[3]);
	//REG_WRITE(REG_GLOBAL, 0x03, (addr[4] << 8) | addr[5]);

	return 0;
}

static int mv88e6020_port_to_phy_addr(int port)
{
	if (port >= 0 && port <= 5)
		return port;
	return -1;
}

/* XXX: This needs to be fixed for PHY memwindow in 6020*/
static int mv88e6020_phy_read(struct dsa_switch *ds, int port, int regnum)
{
	int addr;

	addr = mv88e6020_port_to_phy_addr(port);
	if (addr == -1)
		return 0xffff;

	//reg_write(ds, REG_GLOBAL2, 0x18, 
	return reg_read(ds, addr, regnum);
}

/* XXX: This needs to be fixed for PHY memwindow in 6020*/
static int
mv88e6020_phy_write(struct dsa_switch *ds, int port, int regnum, u16 val)
{
	int addr;

	addr = mv88e6020_port_to_phy_addr(port);
	if (addr == -1)
		return 0xffff;

	return reg_write(ds, addr, regnum, val);
}

static void mv88e6020_poll_link(struct dsa_switch *ds)
{
	int i;

	for (i = 0; i < DSA_MAX_PORTS; i++) {
		struct net_device *dev;
		int uninitialized_var(port_status);
		int link;
		int speed;
		int duplex;
		int fc;

		//dump_stack();

		dev = ds->ports[i];
		if (dev == NULL)
			continue;
		//printk(KERN_ERR "Kris: Polling link %d 0x%X\n", i, REG_PORT(i));

		link = 0;
		if (dev->flags & IFF_UP) {
			port_status = reg_read(ds, REG_PORT(i), 0x00);
			if (port_status < 0)
				continue;

			link = !!(port_status & 0x1000);
			//printk(KERN_ERR "Kris: link %d\n", link);
		}


		if (!link) {
			if (netif_carrier_ok(dev)) {
				printk(KERN_INFO "%s: link down\n", dev->name);
				netif_carrier_off(dev);
			}
			continue;
		}

		speed = (port_status & 0x0100) ? 100 : 10;
		duplex = (port_status & 0x0200) ? 1 : 0;
		fc = ((port_status & 0xc000) == 0xc000) ? 1 : 0;

		if (!netif_carrier_ok(dev)) {
			printk(KERN_INFO "%s: link up, %d Mb/s, %s duplex, "
					 "flow control %sabled\n", dev->name,
					 speed, duplex ? "full" : "half",
					 fc ? "en" : "dis");
			netif_carrier_on(dev);
		}
	}
}

static struct dsa_switch_driver mv88e6020_switch_driver = {
	.tag_protocol	= htons(ETH_P_TRAILER),
	.probe		= mv88e6020_probe,
	.setup		= mv88e6020_setup,
	.set_addr	= mv88e6020_set_addr,
	.phy_read	= mv88e6020_phy_read,
	.phy_write	= mv88e6020_phy_write,
	.poll_link	= mv88e6020_poll_link,
};

static int __init mv88e6020_init(void)
{
	register_switch_driver(&mv88e6020_switch_driver);
	return 0;
}
module_init(mv88e6020_init);

static void __exit mv88e6020_cleanup(void)
{
	unregister_switch_driver(&mv88e6020_switch_driver);
}
module_exit(mv88e6020_cleanup);
