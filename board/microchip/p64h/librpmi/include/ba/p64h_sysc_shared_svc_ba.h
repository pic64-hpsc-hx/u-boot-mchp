/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines sysc general shared types
 */

#ifndef P64H_SYSC_SHARED_SVC_BA_H
#define P64H_SYSC_SHARED_SVC_BA_H

#include "p64h_sysc_shared_ba.h"
#include "generated/p64h_sysc_components.h"

/// SysC WID cfg ID
typedef enum {
    P64H_SYSC_WORLDGUARD_ID_SYS = 0x0u,
    P64H_SYSC_WORLDGUARD_ID_SYSDMA,
    P64H_SYSC_WORLDGUARD_ID_SECDMA,
    P64H_SYSC_WORLDGUARD_ID_SPW,
    P64H_SYSC_WORLDGUARD_ID_LAST
} p64h_sysc_wg_cfg_id_t;

#endif // P64H_SYSC_SHARED_SVC_BA_H
