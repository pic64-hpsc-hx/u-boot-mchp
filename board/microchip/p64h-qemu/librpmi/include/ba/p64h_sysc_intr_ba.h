/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines type definitions for the interrupts of the system
 */
#ifndef P64H_SYSC_INTR_BA_H
#define P64H_SYSC_INTR_BA_H

/* Public Includes ------------------------------------------------------------ */
#include "p64h_sysc_shared_periph_ba.h"

/* Public Defines ------------------------------------------------------------- */
/// @brief Number of XPLIC assignable interrupts
#define NUM_XPLIC_INTRS 127
/// @brief Number of XPLIC assignable interrupts
#define NUM_PLIC_INTRS 189
/// @brief Number of non-dynamically assigned interrupts
#define NUM_NONDYNAMIC_INTRS 99
/// @brief Number of dynamically assigned interrupts
#define NUM_DYNAMIC_INTRS NUM_XPLIC_INTRS - NUM_NONDYNAMIC_INTRS
/// @brief Number of plic-only assignable interrupts
#define NUM_PLIC_UNIQUE_INTRS NUM_PLIC_INTRS - NUM_XPLIC_INTRS
/// @brief Maximum number of groups in a non-dynamic interrupt configuration
#define NUM_NONDYN_INTR_CFG_GROUPS 4
/// @brief Number of groups in a dynamic interrupt configuration
#define NUM_DYN_INTR_CFG_GROUPS 6

/* Public Structs and Enums --------------------------------------------------- */

/////////////////
// Interrupt Controller Structs
/////////////////
typedef enum p64h_sysc_intr_ctrl_type_t {
    P64H_SYSC_INTR_CTRL_LIC = 0,
    P64H_SYSC_INTR_CTRL_PLIC,
} p64h_sysc_intr_ctrl_type_t;

/////////////////
// XPLICs Structs
/////////////////

/**
 * @brief Interrupt configuration for XPLICs. Contains assignment for
 *        interrupts 0 to 126
 */
typedef struct p64h_sysc_xplic_cfg {
    uint32_t nondynamic_intr[NUM_NONDYNAMIC_INTRS][NUM_NONDYN_INTR_CFG_GROUPS];
    uint32_t dynamic_intr[NUM_DYNAMIC_INTRS][NUM_DYN_INTR_CFG_GROUPS];
} p64h_sysc_xplic_cfg_t;

/**
 * @brief Struct containing the interrupt configuration to the APPC domain in the device.
 *        It details the connections from the interrupt aggregator to the APLIC 0 and APLIC 1
 *
 * TODO ALIC steering control
 */
typedef struct p64h_sysc_appc_int_agg_cfg {
    p64h_sysc_xplic_cfg_t xplic_intr[2];
} p64h_sysc_appc_int_agg_cfg_t;

/**
 * @brief Struct containing the interrupt configuration to the SYSC domaine in the device.
 *        It details the connections from the interrupt aggregator to the SYSC PLIC.
 *
 */
typedef struct p64h_sysc_int_agg_cfg {
    p64h_sysc_xplic_cfg_t xplic_intr;
} p64h_sysc_int_agg_cfg_t;

#endif // P64H_SYSC_INTR_BA_H