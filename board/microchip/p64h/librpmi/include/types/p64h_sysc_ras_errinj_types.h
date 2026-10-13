/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_errinj_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_ERRINJ_TYPE_H
#define P64H_SYSC_RAS_ERRINJ_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_ras_error_sources.h>
#include <generated/p64h_sysc_ras_data_defs.h>

/* Public Defines ------------------------------------------------- */

/* Public Structs and Enums --------------------------------------- */

/// @brief Struct to pack the values for error injection (without severity)
typedef struct __attribute__((packed)) {
    uint32_t err_evt : RAS_ERR_PACK_EVT_ID_LEN;            ///< Error event ID
    uint32_t : RAS_ERR_PACK_SEV_ID_LEN;                    ///< Reserved (no severity for injection)
    uint32_t struc_inst : RAS_ERR_PACK_STRUCT_INST_ID_LEN; ///< Structure instance
    uint32_t struc : RAS_ERR_PACK_STRUCT_ID_LEN;           ///< Structure ID
    uint32_t src : RAS_ERR_PACK_SRC_ID_LEN;                ///< Error source ID
} p64h_sysc_ras_einj_pack_t;

/// @brief Union to facilitate reading a unique RAS error injection code (without severity)
typedef union {
    uint32_t                  w; ///< Word access
    p64h_sysc_ras_einj_pack_t b; ///< Bitfield access
} p64h_sysc_ras_einj_code_t;

/// Description of attributes for a specific error injection
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for an error injection
} p64h_sysc_ras_errinj_attr_desc_t;

/// Attributes for the description of a specific error injection. Used to trigger an error injection
typedef struct {
    uint32_t placeholder; ///< Placeholder variable for an error injection
} p64h_sysc_ras_errinj_attr_t;

#endif // P64H_SYSC_RAS_ERRINJ_TYPE_H
/// @}
