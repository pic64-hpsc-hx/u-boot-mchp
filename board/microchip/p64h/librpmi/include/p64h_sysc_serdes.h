/* (c) 2025 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

/**
 * @file  p64h_sysc_serdes.h
 * @brief Serdes API
 * @addtogroup SERDES_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_SERDES_H
#define P64H_SYSC_SERDES_H

#include <rpmi/librpmi_sysc.h>
#include <types/p64h_sysc_serdes_types.h>

p64h_err_t p64h_sysc_serdes_grp_list_get(const p64h_sysc_handle_t* handle_ptr, uint32_t list_num, p64h_sysc_serdes_grp_id_t* sids_ptr,
                                         bool shmem_xfer);
p64h_err_t p64h_sysc_serdes_grp_num_get(const p64h_sysc_handle_t* handle_ptr, uint32_t* num_serdes_grp_id_ptr);
p64h_err_t p64h_sysc_serdes_attr_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id, p64h_sysc_serdes_grp_attr_t* attr_ptr);
p64h_err_t p64h_sysc_serdes_cfg_set(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id,
                                    const p64h_sysc_serdes_grp_runtim_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_serdes_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id, p64h_sysc_serdes_grp_runtim_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_serdes_diag_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id, p64h_sysc_serdes_grp_diag_t* diag_ptr);
p64h_err_t p64h_sysc_serdes_prov(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id, p64h_sysc_serdes_rate_t rate,
                                 p64h_sysc_serdes_grp_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_serdes_deprov(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id);
p64h_err_t p64h_sysc_serdes_anlt_cfg_set(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id,
                                         const p64h_sysc_serdes_grp_anlt_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_serdes_anlt_cfg_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id,
                                         p64h_sysc_serdes_grp_anlt_cfg_t* cfg_ptr);
p64h_err_t p64h_sysc_serdes_anlt_diag_get(const p64h_sysc_handle_t* handle_ptr, p64h_sysc_serdes_grp_id_t id,
                                          p64h_sysc_serdes_grp_anlt_diag_t* diag_ptr);

#endif // P64H_SYSC_SERDES_H
/// @}
