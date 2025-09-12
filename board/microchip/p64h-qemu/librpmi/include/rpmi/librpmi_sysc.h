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

/// Configuration of log to fetch
typedef struct {
    void*    log_ptr;       ///< Pointer to the memory space of the log
    uint32_t num_entries;   ///< Number of entries in the log
    size_t   entry_size;    ///< Size of the entries in bytes
    uint64_t req_start_off; ///< Requested start offset for entries to fetch
} p64h_sysc_log_cfg_t;

p64h_err_t p64h_sysc_rpmi_bare_req_resp(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id);
p64h_err_t p64h_sysc_rpmi_bare_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0);
p64h_err_t p64h_sysc_rpmi_bare_id2(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                   const uint32_t id1);
p64h_err_t p64h_sysc_rpmi_bare_id3(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                   const uint32_t id1, const uint32_t id2);
p64h_err_t p64h_sysc_rpmi_req(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const void* req_data_ptr,
                              const size_t req_size);
p64h_err_t p64h_sysc_rpmi_resp(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, void* resp_data_ptr,
                               const size_t resp_size);
p64h_err_t p64h_sysc_rpmi_req_resp(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const void* req_data_ptr,
                                   const size_t req_size, void* resp_data_ptr, const size_t resp_size);
p64h_err_t p64h_sysc_rpmi_req_resp_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id,
                                      const void* req_data_ptr, const size_t req_size, void* resp_data_ptr, const size_t resp_size);

p64h_err_t p64h_sysc_rpmi_resp_list(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, void* list_ptr,
                                    size_t entry_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_list_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                       void* list_ptr, size_t entry_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_list_id2(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                        const uint32_t id1, void* list_ptr, size_t entry_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_list_id3(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                        const uint32_t id1, const uint32_t id2, void* list_ptr, size_t entry_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_req_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id,
                                 const void* req_data_ptr, const size_t req_size);
p64h_err_t p64h_sysc_rpmi_resp_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id,
                                  void* resp_data_ptr, const size_t resp_size);
p64h_err_t p64h_sysc_rpmi_req_outbuf(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const void* req_data_ptr,
                                     const size_t req_size, const void* buf_ptr, const size_t buf_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_inbuf(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, void* buf_ptr,
                                     size_t buf_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_req_resp_inbuf(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id,
                                         const void* req_data_ptr, const size_t req_size, void* buf_ptr, size_t buf_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_inbuf_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                        void* buf_ptr, size_t buf_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_inbuf_id2(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                         const uint32_t id1, void* buf_ptr, size_t buf_size, bool shmem_xfer);
p64h_err_t p64h_sysc_rpmi_resp_inbuf_id3(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                         const uint32_t id1, const uint32_t id2, void* buf_ptr, size_t buf_size, bool shmem_xfer);

p64h_err_t p64h_sysc_rpmi_req_id2(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                  const uint32_t id1, const void* req_data_ptr, const size_t req_size);
p64h_err_t p64h_sysc_rpmi_resp_id2(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                   const uint32_t id1, void* resp_data_ptr, const size_t resp_size);
p64h_err_t p64h_sysc_rpmi_req_id3(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                  const uint32_t id1, const uint32_t id2, const void* req_data_ptr, const size_t req_size);
p64h_err_t p64h_sysc_rpmi_resp_id3(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                   const uint32_t id1, const uint32_t id2, void* resp_data_ptr, const size_t resp_size);
p64h_err_t p64h_sysc_rpmi_log(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, p64h_sysc_log_cfg_t* log_cfg_ptr,
                              uint64_t* resp_start_off, uint32_t* num_returned);
p64h_err_t p64h_sysc_rpmi_log_id(const p64h_sysc_handle_t* handle_ptr, const uint16_t svc_grp_id, const uint8_t svc_id, const uint32_t id0,
                                 p64h_sysc_log_cfg_t* log_cfg_ptr, uint64_t* resp_start_off, uint32_t* num_returned);
#endif // LIB_RPMI_SYSC_H
/// @}
