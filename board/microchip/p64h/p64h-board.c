// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2025 Microchip Technology Inc.
 * Romain Caritey <romain.caritey@microchip.com>
 */

#include <common.h>
#include <virtio_types.h>
#include <virtio.h>
#include <asm/sections.h>

#include <p64h-board.h>

DECLARE_GLOBAL_DATA_PTR;

static p64h_sysc_rpmi_shmem_cfg_t shmem_cfg;
static p64h_sysc_handle_t* handle_ptr = NULL;

static int board_rpmi_get_cells(const void *fdt,
                                             int nodeoffset,
                                             int parentoffset,
                                             const char *propname,
                                             uint32_t *value) {
    int len;
    const int offsets[2] = { nodeoffset, parentoffset };
    for (int i = 0; i < 2; ++i) {
        const fdt32_t *prop = fdt_getprop(fdt, offsets[i], propname, &len);
        if (prop && len == 4) {
            *value = fdt32_to_cpu(*prop);
            return 0;
        }
    }
    return -1;
}

static int p64h_rpmi_get_shmem_cfg(const void *fdt, int nodeoffset) {

    int parent = fdt_parent_offset(fdt, nodeoffset);
    if (parent < 0) {
        printf("Parent node not found\n");
        return -1;
    }

    uint32_t address_cells, size_cells;
    if (board_rpmi_get_cells(fdt, nodeoffset, parent, "#address-cells", &address_cells) < 0) {
        printf("RPMI: #address-cells not found in node or parent\n");
        return -1;
    }
    if (board_rpmi_get_cells(fdt, nodeoffset, parent, "#size-cells", &size_cells) < 0) {
        printf("RPMI: #size-cells not found in node or parent\n");
        return -1;
    }

    int len;
    const fdt32_t *reg = fdt_getprop(fdt, nodeoffset, "reg", &len);
    if (!reg) {
        printf("RPMI: reg property not found\n");
        return -1;
    }

    int entry_size = address_cells + size_cells;
    if (entry_size == 0) {
        printf("RPMI: entry_size is zero\n");
        return -1;
    }
    if (len % (4 * entry_size) != 0) {
        printf("RPMI: reg property length does not match address/size cells\n");
        return -1;
    }

    int num_entries = len / (4 * entry_size);
    if (num_entries != 1) {
        /* no support for multiple entries */
        printf("RPMI: reg property have more than one address/size entry\n");
    }

    uint64_t addr = 0, size = 0;
    const fdt32_t *entry = reg;
    for (int j = 0; j < address_cells; ++j)
        addr = (addr << 32) | fdt32_to_cpu(entry[j]);
    for (int j = 0; j < size_cells; ++j)
        size = (size << 32) | fdt32_to_cpu(entry[address_cells + j]);

    shmem_cfg.mem.base_addr = addr;
    shmem_cfg.mem.size = (uint32_t) size;

    return 0;
}

static void board_rpmi_init(void)
{
    p64h_sysc_sys_info_t info;
    int len, nodeoffset, depth, found = 0;
    const void *fdt = gd->fdt_blob;

    for (nodeoffset = fdt_next_node(fdt, -1, &depth);
         nodeoffset >= 0;
         nodeoffset = fdt_next_node(fdt, nodeoffset, &depth)) {
        const char *compat = fdt_getprop(fdt, nodeoffset, "compatible", &len);
        if (compat) {
            const char *end = compat + len;
            while (compat < end) {
                if (strcmp(compat, "microchip,p64h-sysc-rpmi") == 0) {
                    found = 1;
                    break;
                }
                compat += strlen(compat) + 1;
            }
        }
        if (found)
            break;
    }

    /* if RPMI failed then just ignore it, never stop U-Boot */
    if (!found) {
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

void *board_fdt_blob_setup(int *err)
{
    *err = 0;
    if (IS_ENABLED(CONFIG_OF_SEPARATE) || IS_ENABLED(CONFIG_OF_BOARD)) {
        if (gd->arch.firmware_fdt_addr)
            return (ulong *)(uintptr_t)gd->arch.firmware_fdt_addr;
    }

    return (ulong *)_end;
}
