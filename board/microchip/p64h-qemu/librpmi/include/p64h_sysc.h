/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc.h
 * @brief SysC API
 * @addtogroup SYSC_API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_H
#define P64H_SYSC_H

// include p64h sysc API
#include <generated/p64h_sysc_errors.h>
#include <generated/p64h_sysc_version.h>
#include "p64h_sysc_system.h"
#include "p64h_sysc_psm.h"
#include "p64h_sysc_trace.h"
#include "p64h_sysc_ddr.h"
#include "p64h_sysc_serdes.h"
#include "p64h_sysc_lsio.h"
#include "p64h_sysc_switch.h"
#include "p64h_sysc_test.h"
#include "p64h_sysc_ras_em.h"
#include "p64h_sysc_ras_er.h"
#include "p64h_sysc_ras_health.h"
#include "p64h_sysc_ras_errinj.h"
#include "p64h_sysc_crypto.h"
#include "p64h_sysc_nvm.h"
#include "p64h_sysc_crypto.h"
#include "p64h_sysc_debug.h"
#include "p64h_sysc_base.h"
#include <rpmi/librpmi_mchp.h>
#include <rpmi/librpmi_sysc.h>

/// P64H SYSC Interfaces
p64h_err_t          p64h_sysc_version_check(p64h_sysc_sys_version_t* sysc_ver, uint32_t vers);
p64h_sysc_handle_t* p64h_sysc_handle_get(void);
p64h_err_t          p64h_sysc_rpmi_shmem_init(const p64h_sysc_rpmi_shmem_cfg_t* cfg_ptr, p64h_sysc_handle_t** handle_pptr);
p64h_err_t          p64h_sysc_rpmi_remote_init(const p64h_sysc_rpmi_remote_cfg_t* cfg_ptr, p64h_sysc_handle_t** handle_pptr);

#endif // P64H_SYSC_H
/// @}
