// SPDX-License-Identifier: (GPL-2.0+ OR MIT)
/*
 * Copyright (c) 2026 Microchip
 */

#include <miiphy.h>
#include <wait_bit.h>
#include <linux/bitops.h>
#include <linux/bitfield.h>
#include <linux/kernel.h>

#define P64H_MDIO_REG_PRESCALER 0x20
#define P64H_MDIO_CFG_PRESCALE_MASK GENMASK(7, 0)

#define P64H_MDIO_REG_FRAME_CFG_1 0x24
#define P64H_MDIO_WDATA_MASK GENMASK(15, 0)

#define P64H_MDIO_REG_FRAME_CFG_2 0x28
#define P64H_MDIO_TRIGGER_BIT BIT(31)
#define P64H_MDIO_REG_DEV_ADDR_MASK GENMASK(20, 16)
#define P64H_MDIO_PHY_PRT_ADDR_MASK GENMASK(8, 4)
#define P64H_MDIO_OPERATION_MASK GENMASK(3, 2)
#define P64H_MDIO_START_OF_FRAME_MASK GENMASK(1, 0)

#define P64H_MDIO_OPERATION_WRITE BIT(0)
#define P64H_MDIO_OPERATION_READ BIT(1)

#define P64H_MDIO_REG_FRAME_STATUS 0x2C
#define P64H_MDIO_READOK_BIT BIT(24)
#define P64H_MDIO_RDATA_MASK GENMASK(15, 0)

#define P64H_MDIO_REG_INT_I 0x30
#define P64H_MDIO_INT_I BIT(0)

#define P64H_MDIO_REG_INT_E 0x34

struct p64h_mdio_priv {
	void *regs_base;
};

static int p64h_mdio_wait_trigger(struct p64h_mdio_priv *priv)
{
	int ret;

	ret = wait_for_bit_le32(priv->regs_base + P64H_MDIO_REG_FRAME_CFG_2,
			P64H_MDIO_TRIGGER_BIT, false, 250, false);

	if (ret < 0) {
		printf("%s: TRIGGER bit timeout: %x\n", __func__,
			in_le32(priv->regs_base + P64H_MDIO_REG_FRAME_CFG_2));
	}

	return ret;
}

static int dm_p64h_mdio_read(struct udevice *dev, int addr,
				int devad, int reg)
{
	struct p64h_mdio_priv *priv = dev_get_priv(dev);
	u32 val;
	int ret;

	debug("%s addr=%i devad=0x%x reg=0x%x\n", __func__, addr, devad, reg);

	if (devad != MDIO_DEVAD_NONE) {
		printf("%s: c45 not supported\n", __func__);
		ret = -EOPNOTSUPP;
		goto out;
	}

	ret = p64h_mdio_wait_trigger(priv);
	if (ret)
		goto out;

	out_le32(priv->regs_base + P64H_MDIO_REG_FRAME_CFG_2,
		P64H_MDIO_TRIGGER_BIT |
		FIELD_PREP(P64H_MDIO_REG_DEV_ADDR_MASK, reg) |
		FIELD_PREP(P64H_MDIO_PHY_PRT_ADDR_MASK, addr) |
		FIELD_PREP(P64H_MDIO_OPERATION_MASK, P64H_MDIO_OPERATION_READ) |
		FIELD_PREP(P64H_MDIO_START_OF_FRAME_MASK, 1));

	ret = p64h_mdio_wait_trigger(priv);
	if (ret)
		goto out;

	val = in_le32(priv->regs_base + P64H_MDIO_REG_FRAME_STATUS);

	if (!FIELD_GET(P64H_MDIO_READOK_BIT, val)) {
		ret = -ENODEV;
		goto out;
	}

	ret = FIELD_GET(P64H_MDIO_RDATA_MASK, val);

out:
	return ret;
}

static int dm_p64h_mdio_write(struct udevice *dev, int addr, int devad,
				int reg, u16 val)
{
	struct p64h_mdio_priv *priv = dev_get_priv(dev);
	int ret;

	debug("%s: addr=%i devad=0x%x reg=0x%x\n", __func__, addr, devad, reg);

	if (devad != MDIO_DEVAD_NONE) {
		printf("%s: c45 not supported\n", __func__);
		ret = -EOPNOTSUPP;
		goto out;
	}

	ret = p64h_mdio_wait_trigger(priv);
	if (ret < 0)
		goto out;

	out_le32(priv->regs_base + P64H_MDIO_REG_FRAME_CFG_1,
		FIELD_PREP(P64H_MDIO_WDATA_MASK, val));

	out_le32(priv->regs_base + P64H_MDIO_REG_FRAME_CFG_2,
		P64H_MDIO_TRIGGER_BIT |
		FIELD_PREP(P64H_MDIO_REG_DEV_ADDR_MASK, reg) |
		FIELD_PREP(P64H_MDIO_PHY_PRT_ADDR_MASK, addr) |
		FIELD_PREP(P64H_MDIO_OPERATION_MASK, P64H_MDIO_OPERATION_WRITE) |
		FIELD_PREP(P64H_MDIO_START_OF_FRAME_MASK, 1));

out:
	return ret;
}

static const struct mdio_ops p64h_mdio_ops = {
	.read = dm_p64h_mdio_read,
	.write = dm_p64h_mdio_write,
};

static int p64h_mdio_probe(struct udevice *dev)
{
	struct p64h_mdio_priv *priv = dev_get_priv(dev);
	u32 div;

	priv->regs_base = dev_read_addr_ptr(dev);
	if (!priv->regs_base)
		return -ENODEV;

	div = DIV_ROUND_UP(156250000, 2 * 2500000) - 1;
	if (div == 0 || div & ~P64H_MDIO_CFG_PRESCALE_MASK) {
		printf("%s: Incorrect MDIO clock frequency\n", __func__);
		return -EINVAL;
	}

	out_le32(priv->regs_base + P64H_MDIO_REG_PRESCALER, div);

	return 0;
}

static const struct udevice_id p64h_mdio_of_ids[] = {
	{ .compatible = "microchip,p64h-mdio" },
};

U_BOOT_DRIVER(p64h_mdio) = {
	.name = "p64h_mdio",
	.id = UCLASS_MDIO,
	.of_match = p64h_mdio_of_ids,
	.probe = p64h_mdio_probe,
	.ops = &p64h_mdio_ops,
	.priv_auto	= sizeof(struct p64h_mdio_priv),
};


