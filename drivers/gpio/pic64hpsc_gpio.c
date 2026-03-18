// SPDX-License-Identifier: (GPL-2.0)
/*
 * Copyright (c) 2026 Microchip
 */

#include <common.h>
#include <dm.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <errno.h>
#include <linux/bitops.h>

#define PIC64_OUT_VAL_CFG_REG 0x84
#define PIC64_OUT_EN_CFG_REG  0x8C
#define PIC64_IN_STATUS_REG   0x114

struct pic64hpsc_gpio {
	u8 *base;
};

static void pic64hpsc_gpio_set_direction(struct udevice *dev, unsigned int gpio, bool out)
{
	struct pic64hpsc_gpio *plat = dev_get_plat(dev);
	int reg = gpio / 16;
	int bit = gpio % 16;
	u32 mask = (~(1 << bit)) << 16;
	u32 data = mask | ((out ? 1 : 0) << bit);
	writel(data, plat->base + PIC64_OUT_EN_CFG_REG + (4 * reg));
}

static int pic64hpsc_gpio_get_direction(struct udevice *dev, unsigned int gpio)
{
	struct pic64hpsc_gpio *plat = dev_get_plat(dev);
	int reg = gpio / 16;
	int bit = gpio % 16;
	u32 data = readl(plat->base + PIC64_OUT_EN_CFG_REG + (4 * reg));
	return !!(data & (1 << bit));
}

static int pic64hpsc_gpio_direction_input(struct udevice *dev, unsigned int gpio)
{
	pic64hpsc_gpio_set_direction(dev, gpio, false);
	return 0;
}

static int pic64hpsc_gpio_set_value(struct udevice *dev, unsigned gpio,
				  int value)
{
	struct pic64hpsc_gpio *plat = dev_get_plat(dev);
	int reg = gpio / 16;
	int bit = gpio % 16;
	u32 mask = (~(1 << bit)) << 16;
	u32 data = mask | ((value ? 1 : 0) << bit);

	writel(data, plat->base + PIC64_OUT_VAL_CFG_REG + (4 * reg));
	return 0;
}

static int pic64hpsc_gpio_direction_output(struct udevice *dev, unsigned gpio,
					int value)
{
	pic64hpsc_gpio_set_direction(dev, gpio, true);
	pic64hpsc_gpio_set_value(dev, gpio, value);
	return 0;
}

static int pic64hpsc_gpio_get_value(struct udevice *dev, unsigned gpio)
{
	struct pic64hpsc_gpio *plat = dev_get_plat(dev);

	return !!(readl(plat->base + PIC64_IN_STATUS_REG) & (1 << gpio));
}

static int pic64hpsc_gpio_get_function(struct udevice *dev, unsigned gpio)
{
	int direction = pic64hpsc_gpio_get_direction(dev, gpio);
	return direction ? GPIOF_OUTPUT : GPIOF_INPUT;
}

static int pic64hpsc_gpio_get_flags(struct udevice *dev, unsigned gpio, ulong *flags)
{
	int direction = pic64hpsc_gpio_get_direction(dev, gpio);
	*flags = direction ? GPIOD_IS_OUT : GPIOD_IS_IN;
	return 0;
}

static const struct dm_gpio_ops gpio_pic64hpsc_ops = {
	.direction_input	= pic64hpsc_gpio_direction_input,
	.direction_output	= pic64hpsc_gpio_direction_output,
	.get_value		= pic64hpsc_gpio_get_value,
	.set_value		= pic64hpsc_gpio_set_value,
	.get_function		= pic64hpsc_gpio_get_function,
	.get_flags		= pic64hpsc_gpio_get_flags,
};

static int pic64hpsc_gpio_probe(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	char name[32], *str;

	if (dev->name) {
		snprintf(name, sizeof(name), "%s_", dev->name);
	} else {
		snprintf(name, sizeof(name), "gpio@%llx_", dev_read_addr(dev));
	}

	str = strdup(name);
	if (!str)
		return -ENOMEM;

	uc_priv->bank_name = str;
	uc_priv->gpio_count = 32;
	return 0;
}

static int pic64hpsc_of_to_plat(struct udevice *dev)
{
	struct pic64hpsc_gpio *plat = dev_get_plat(dev);

	plat->base = dev_read_addr_ptr(dev);
	return 0;
}

static const struct udevice_id pic64hpsc_gpio_ids[] = {
	{ .compatible = "microchip,pic64hpsc-gpio" },
	{ }
};

U_BOOT_DRIVER(gpio_pic64hpsc) = {
	.name		= "gpio_pic64hpsc",
	.id		= UCLASS_GPIO,
	.of_match	= pic64hpsc_gpio_ids,
	.ops		= &gpio_pic64hpsc_ops,
	.of_to_plat	= pic64hpsc_of_to_plat,
	.plat_auto	= sizeof(struct pic64hpsc_gpio),
	.probe		= pic64hpsc_gpio_probe,
};
