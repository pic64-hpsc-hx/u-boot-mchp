/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines sysc general shared types, this file SHALL not include sysc_config.h
 */

#ifndef P64H_SYSC_SHARED_BA_H
#define P64H_SYSC_SHARED_BA_H

#include <env/p64h_sysc_os_specific.h>

#define SYSC_STRING_MAX 400U ///< Maximum Filename size for Boot Commands

/**
 * @brief
 *  Enumeration of APPc booting source location
 */
typedef enum {
    P64H_SYSC_BOOT_SOURCE_NVM = 0u, ///< boot from
    P64H_SYSC_LAST_BOOT_SOURCE      ///< invalid, used for error checking
} p64h_sysc_boot_source_t;

/// @brief File types consumed by SYSC assigned magic numbers for identification
///    DEV_CFG_GEN_BIN_TYPE_SYSC_APPC_CFG        = 65,
///    DEV_CFG_GEN_BIN_TYPE_SYSC_APPC_CFG_STATIC = 82,
///    DEV_CFG_GEN_BIN_TYPE_BOOT_CFG             = 85
typedef enum {
    P64H_SYSC_APPC_CFG        = 65,
    P64H_SYSC_APPC_CFG_STATIC = 82,
    P64H_SYSC_BOOT_CFG        = 85,
    P64H_SYSC_CFG1            = 87,
    P64H_SYSC_SOC_CFG         = 89
} p64h_sysc_dev_cfg_gen_bin_type_t;

/**
 * @brief
 *   dev_cfg dtb version information
 */
typedef struct {
    uint32_t major;                       ///< dev_cfg major version
    uint32_t minor;                       ///< dev_cfg minor version
    uint32_t patch;                       ///< dev_cfg patch version
    uint32_t hash;                        ///< dev_cfg git hash
    char     custom_tag[SYSC_STRING_MAX]; ///< dev_cfg dtb custom string tag
    char     log_cfg[SYSC_STRING_MAX];    ///< dev_cfg dtb log configuration string
    char     utest[SYSC_STRING_MAX];      ///< dev_cfg dtb utest string
} p64h_sysc_dev_cfg_node_t;

/**
 * @brief
 *   dev_cfg version information
 */
typedef struct {
    uint32_t magic;   ///< magic number identifying
    uint32_t version; ///< version of dev_cfg tool used to generate this header
} p64h_sysc_bin_hdr_t;

#endif // P64H_SYSC_SHARED_BA_H
