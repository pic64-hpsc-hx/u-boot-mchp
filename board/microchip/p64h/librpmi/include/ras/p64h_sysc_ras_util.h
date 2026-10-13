/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file p64h_sysc_ras_util.h
 * @brief
 *  Utility functions.
 * @addtogroup RASLIB
 * @{
 */
#ifndef P64H_SYSC_RAS_UTIL_H
#define P64H_SYSC_RAS_UTIL_H

#include "generated/p64h_sysc_ras_error_sources.h"

void       em_err_filter_context_init();

p64h_err_t em_err_filter_set(p64h_sysc_ras_em_prof_t* em_prof_ptr,

                             const p64h_ras_err_id_t err_id, bool enable);

p64h_err_t em_err_filter_get(const p64h_sysc_ras_em_prof_t* em_prof_ptr, const p64h_ras_err_id_t err_id, bool* enabled);

#endif