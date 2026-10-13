/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  librpmi_sysc.h
 * @brief RPMI SysC API
 * @{
 */

#ifndef LIB_RPMI_SYSC_H
#define LIB_RPMI_SYSC_H

// include p64h sysc API
#include <rpmi/librpmi_mchp.h>
#include <generated/p64h_sysc_errors.h>

/**
 * @brief
 *   The condition is checked and if FALSE then we return an error
 *   @param[in] condition - check to perform
 *   @param[in] err_code - the error code to return
 *
 */
#define P64H_SYSC_ASSERT(condition, err_code)                                                                                                        \
    do {                                                                                                                                             \
        if (__builtin_expect(!(condition), 0)) {                                                                                                     \
            return (err_code);                                                                                                                       \
        }                                                                                                                                            \
    } while (false)

/// Configuration of log to fetch
typedef struct {
    void*    log_ptr;       ///< Pointer to the memory space of the log
    uint32_t num_entries;   ///< Number of entries in the log
    size_t   entry_size;    ///< Size of the entries in bytes
    uint64_t req_start_off; ///< Requested start offset for entries to fetch
} p64h_sysc_log_cfg_t;

p64h_err_t p64h_sysc_rpmi_req_resp(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                   const uint32_t id1, const uint32_t id2, const void* req_data_ptr, const size_t req_size, void* resp_data_ptr,
                                   const size_t resp_size);

p64h_err_t p64h_sysc_rpmi_resp_list(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                    const uint32_t id1, const uint32_t id2, void* list_ptr, uint32_t list_num, size_t entry_size, bool shmem_xfer);

p64h_err_t p64h_sysc_rpmi_req_with_data(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                        const void* req_data_ptr, const size_t req_size, const void* buf_ptr, const size_t buf_size, bool shmem_xfer);

p64h_err_t p64h_sysc_rpmi_resp_with_data(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                         const uint32_t id1, const uint32_t id2, const void* req_data_ptr, const size_t req_size, void* buf_ptr,
                                         size_t buf_size, bool shmem_xfer);

p64h_err_t p64h_sysc_rpmi_log(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, p64h_sysc_log_cfg_t* log_cfg_ptr,
                              uint64_t* resp_start_off, uint32_t* num_returned, uint64_t* entries_left);
p64h_err_t p64h_sysc_rpmi_log_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                 p64h_sysc_log_cfg_t* log_cfg_ptr, uint64_t* resp_start_off, uint32_t* num_returned, uint64_t* entries_left);
#endif // LIB_RPMI_SYSC_H
/// @}
