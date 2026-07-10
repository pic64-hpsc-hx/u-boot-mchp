/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_ras_em_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_RAS_EM_TYPE_H
#define P64H_SYSC_RAS_EM_TYPE_H

#include "p64h_sysc_common_types.h"
#include <generated/p64h_sysc_ras_error_sources.h>
#include <generated/p64h_sysc_ras_data_defs.h>

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_RAS_EM_PROF_MAX 10UL ///<  Maximum number of Error Monitoring profiles

/* Public Structs and Enums --------------------------------------- */

/// Enum listing all possible notifications supported by the EM RAS service
typedef enum {
    P64H_SYSC_RAS_EM_NOTIF_EVT_ERROR_EVT = 0, ///< Error events notification ID
    P64H_SYSC_RAS_EM_NOTIF_EVT_HEST_EVT  = 1, ///< HEST events notification ID
    P64H_SYSC_RAS_EM_NOTIF_EVT_LAST           ///< Last ID
} p64h_sysc_ras_em_evt_id_t;

/// RAS EM notification event received
typedef struct {
    p64h_sysc_ras_em_evt_id_t evt_id;       ///< Notification event ID
    p64h_sysc_psm_id_t        partition_id; ///< Partition ID for which notification events should be enabled
    uint32_t                  reserved;     ///< reserved
    p64h_sysc_ras_erte_t evt_data; ///< Error event data for P64H_SYSC_RAS_EM_NOTIF_EVT_ERROR_EVT, invalid for P64H_SYSC_RAS_EM_NOTIF_EVT_HEST_EVT
} p64h_sysc_ras_em_evt_t;

/// Data request to get notifications
typedef struct {
    p64h_sysc_ras_em_evt_id_t evt_id;       ///< Notification event ID
    p64h_sysc_psm_id_t        partition_id; ///< Partition ID for which notification events should be enabled
} p64h_sysc_ras_em_notif_t;

/// Data request to get the list of error source IDs
typedef struct {
    uint32_t hest_addr_lo; ///< HEST address lower bits for specified partition
    uint32_t hest_addr_hi; ///< HEST address higher bits for specified partition
    uint32_t bert_addr_lo; ///< BERT address lower for specified partition
    uint32_t bert_addr_hi; ///< BERT address higher for specified partition
} p64h_sysc_ras_em_table_t;

/// Error monitoring profile
typedef struct {
    uint32_t filter_bitmap[(P64H_RAS_ERR_ID_NUM + 31UL)
                           / 32UL]; ///< Error event filter bitmap. Each bit corresponds to one error event in p64h_ras_err_id_t.
} p64h_sysc_ras_em_prof_t;

/// EM serial log identifying characteristics
typedef struct {
    uint32_t id;           ///< Serial log ID value
    uint32_t timestamp_lo; ///< Serial log start timestamp LSB
    uint32_t timestamp_hi; ///< Serial log start timestamp MSB
} p64h_sysc_ras_em_serial_log_id_t;

/// function pointer type for RAS EM event notification
typedef void (*p64h_sysc_ras_em_evt_fct_t)(const p64h_sysc_ras_em_evt_t* ras_em_evt_ptr);

#endif // P64H_SYSC_RAS_EM_TYPE_H
/// @}
