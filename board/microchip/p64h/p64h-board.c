// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2025 Microchip Technology Inc.
 * Romain Caritey <romain.caritey@microchip.com>
 */


#include <fdtdec.h>
#include <virtio_types.h>
#include <virtio.h>
#include <asm/sections.h>

#include <p64h-board.h>

DECLARE_GLOBAL_DATA_PTR;

static p64h_sysc_rpmi_shmem_cfg_t shmem_cfg;
static p64h_sysc_handle_t* handle_ptr = NULL;

static int p64h_rpmi_get_shmem_cfg(const void *fdt, int nodeoffset) {

    int parent = fdt_parent_offset(fdt, nodeoffset);
    if (parent < 0) {
        printf("Parent node not found\n");
        return -1;
    }

    fdt_size_t size;
    fdt_addr_t addr = fdtdec_get_addr_size_auto_parent(fdt, parent, nodeoffset,
                                                        "reg", 0, &size, false);
    if (addr == FDT_ADDR_T_NONE) {
        printf("RPMI: reg property not found or invalid\n");
        return -1;
    }

    shmem_cfg.mem.base_addr = addr;
    shmem_cfg.mem.size = (uint32_t) size;

    return 0;
}

static void board_rpmi_init(void)
{
    p64h_sysc_sys_info_t info;
    const void *fdt = gd->fdt_blob;
    int nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "microchip,p64h-sysc-rpmi");

    /* if RPMI failed then just ignore it, never stop U-Boot */
    if (nodeoffset < 0) {
        printf("RPMI: *** DISABLED *** No device found in DTS\n");
        goto board_rpmi_init_failed;
    }

    if (p64h_rpmi_get_shmem_cfg(fdt, nodeoffset)) {
        printf("RPMI: *** DISABLED *** Shared memory config failed\n");
        goto board_rpmi_init_failed;
    }

    if (P64H_ERR_OK != p64h_sysc_rpmi_shmem_init(&shmem_cfg, &handle_ptr)) {
        printf("RPMI: *** DISABLED *** Shared memory initialization failed\n");
        goto board_rpmi_init_failed;
    }

    if (P64H_ERR_OK != p64h_sysc_sys_info_get(handle_ptr, &info)) {
        printf("RPMI: *** DISABLED *** Get version failed\n");
        goto board_rpmi_init_failed;
    }

    printf("RPMI:  v%u.%u.%u\n",
        info.fw_version.major, info.fw_version.minor, info.fw_version.patch);

    return;

board_rpmi_init_failed:
        /* rpmi is disabled */
        handle_ptr = NULL;
}

const p64h_sysc_handle_t* board_get_rpmi_handle(void)
{
   return handle_ptr;
}

int dram_init(void)
{
#if defined(CONFIG_P64H_NO_DDR)
    gd->ram_base = OCR_BASE_ADDR;
    gd->ram_size = 2 * OCR_BASE_SIZE;
    return 0;
#else
	return fdtdec_setup_mem_size_base();
#endif
}

int dram_init_banksize(void)
{
#if defined(CONFIG_P64H_NO_DDR)
    gd->bd->bi_dram[0].start = OCR_BASE_ADDR;
    gd->bd->bi_dram[0].size = 2 * OCR_BASE_SIZE;
    return 0;
#else
	return fdtdec_setup_memory_banksize();
#endif
}

int board_init(void)
{
    return 0;
}

int board_late_init(void)
{
    /*
     * Make sure virtio bus is enumerated so that peripherals
     * on the virtio bus can be discovered by their drivers
     */
#ifdef CONFIG_VIRTIO_NET
    virtio_init();
#endif

    /* Initialize RPMI subsystem */
    board_rpmi_init();

    return 0;
}

int board_fdt_blob_setup(void **fdtp)
{
	if (IS_ENABLED(CONFIG_OF_SEPARATE) || IS_ENABLED(CONFIG_OF_BOARD)) {
		if (fdt_magic((uintptr_t)gd->arch.firmware_fdt_addr) ==
			FDT_MAGIC) {
			*fdtp = (void *)(ulong)gd->arch.firmware_fdt_addr;

			return 0;
		}
	}

	return -EINVAL;
}
