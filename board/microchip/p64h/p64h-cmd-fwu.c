// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2025 Microchip Technology Inc.
 * Romain Caritey <romain.caritey@microchip.com>
 */

#include <command.h>
#include <linux/libfdt.h>
#include <linux/ctype.h>
#include <fdt_support.h>
#include <asm/global_data.h>
#include <time.h>

#include <p64h-board.h>

bool is_valid_number(const char *str) {
    /* check for hex prefix */
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        str += 2;
        if (*str == '\0')
            return 0;
        while (*str) {
            if (!isxdigit((unsigned char)*str))
                return false;
            str++;
        }
        return true;
    }

    /* decimal check */
    while (*str) {
        if (!isdigit((unsigned char)*str))
            return false;
        str++;
    }
    return true;
}

static int p64h_rpmi_fwu_cmd(struct cmd_tbl *cmdtp,
                             int flag, int argc,
                             char * const argv[])
{
    p64h_err_t ret;
    const p64h_sysc_handle_t* handle_ptr = board_get_rpmi_handle();
    p64h_sysc_fw_pkg_cfg_t cfg = {
        .pkg_data_cfg = {
            .is_compressed = false,
            .is_encrypted = false,
        },
    };

    /* Check if RPMI is activated */
    if (!handle_ptr) {
         printf("ERROR !!! RPMI is not enabled\n");
         return CMD_RET_FAILURE;
    }

    /* two parameters :
     * - address of the downloaded firmware data
     * - size of the downloaded firmware data
     */
    if (argc != 3) {
        return CMD_RET_USAGE;
    }

    if (!is_valid_number(argv[1])) {
        printf("ERROR !!! wrong 'address' value\n");
        return CMD_RET_USAGE;
    }

    if (!is_valid_number(argv[2])) {
        printf("ERROR !!! wrong 'size' value\n");
        return CMD_RET_USAGE;
    }

    const void *data = (const void *) simple_strtoul(argv[1], NULL, 0);
    size_t data_size = (size_t) simple_strtoul(argv[2], NULL, 0);

    cfg.uncompressed_pkg_size = data_size;
    cfg.pkg_size = data_size;

    ulong start_time = get_timer(0);
    printf("rpmi_fwu: start\n");

    printf("Upgrade firmware command: ");
    ret = p64h_sysc_sys_fw_pkg_upgrade_upload(handle_ptr, &cfg, data, data_size, true);
    if (P64H_ERR_OK != ret) {
        printf("upgrade failed (error code %x)\n", ret);
        return CMD_RET_FAILURE;
    }
    printf("\b done\n");

    printf("Apply firmware command: ");
    ret = p64h_sysc_sys_fw_pkg_upgrade_apply(handle_ptr, &cfg);
    if (P64H_ERR_OK != ret) {
        printf("apply failed (error code %x)\n", ret);
        return CMD_RET_FAILURE;
    }
    printf("\b done\nFirmware upgraded\n");

    ulong elapsed = get_timer(start_time);
    printf("rpmi_fwu: done in %lu ms (%lu.%03lu s)\n", elapsed, elapsed / 1000, elapsed % 1000);

    return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
    rpmi_fwu, 3, 1, p64h_rpmi_fwu_cmd,
    "Send an RPMI an RPMI upgrade firmware message to System Controller",
    "rpmi_fwu <addr> <size>\n"
    "  - addr : address where the firmware has been loaded by U-Boot\n"
    "  - size : size of the firmware in bytes\n"
    "  Values can be specified in hexadecimal or decimal (e.g., 255 or 0xff)\n"
);
