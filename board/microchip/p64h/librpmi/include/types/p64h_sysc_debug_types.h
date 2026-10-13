/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_debug_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_DEBUG_TYPE_H
#define P64H_SYSC_DEBUG_TYPE_H

/* Public Structs and Enums --------------------------------------- */

/// debug module type
typedef enum {
    P64H_SYSC_DM_ID_APPC_0 = 0u, ///< appc 0 Debug module
    P64H_SYSC_DM_ID_APPC_1,      ///< appc 1 Debug module
    P64H_SYSC_DM_ID_SYSC,        ///< sysc Debug module
    P64H_SYSC_DM_ID_SECC         ///< secc Debug module
} p64h_sysc_dm_id_t;

/// addr/data struct
typedef struct {
    uint64_t       addr;      ///< addr
    const uint8_t* data_ptr;  ///< data pointer
    uint32_t       data_size; ///< data_size
} p64h_sysc_addr_data_t;

#endif // P64H_SYSC_DEBUG_TYPE_H
/// @}
