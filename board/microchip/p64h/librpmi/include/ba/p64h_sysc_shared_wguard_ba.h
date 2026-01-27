/* (c) 2023 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief
 * Defines sysc shared wguard configuration for appc and sysc.
 */

#ifndef P64H_SYSC_SHARED_WGUARD_BA_H
#define P64H_SYSC_SHARED_WGUARD_BA_H

#include "p64h_sysc_shared_periph_ba.h"
#include "p64h_sysc_shared_ba.h"

#define APPC_WG_CHECKER_NUM_SLOT_1  1u  ///< number of slot of 1 slot worldguard checker
#define APPC_WG_CHECKER_NUM_SLOT_32 32u ///< number of slot of 32 slots worldguard checker
#define APPC_WG_CHECKER_NUM_SLOT_64 64u ///< number of slot of 64 slots worldguard checker
#define APPC_CORE_NUM               8u  ///< number of core in appc
#define APPC_CLUSTER_NUM            2u  ///< number of cluster in appc
#define APPC_WGM_NUM_LUT_ENTRIES    32u ///< max number of did-wid LUT entries limited by appc_static_cfg
#define APPC_SPLIT_CORE_NUM         4u  ///< number of cores per cluster in split

/**
 * @brief
 *   worldguard cluster configuration
 */
typedef struct {
    int      enable;          ///< Enable the cluster
    uint32_t hpmwidlist;      ///< The list of authorized WIDs for Hardware Performance Monitor counters (hpmwidlist). HPM counters are
                              ///< inhibited when WID is not authorized, except the mtime counter that cannot be inhibited
    uint32_t debugwidlist;    ///< The list of authorized WIDs allowed to use in Debug mode (debugwidlist).
    uint32_t debugsbawidlist; ///< The list of authorized WIDs eligible for Debug SBA (System Bus Access) mode.
    uint32_t tracewidlist;    ///< The list of authorized WIDs allowed to perform trace operations in the trace modules.
    uint32_t tracesbawidlist; ///< The list of authorized WIDs allowed to perform trace operations with SBA (System Bus Access) in the trace modules.
} p64h_sysc_appc_wg_cluster_cfg_t;

/**
 * @brief
 *  define wg core complex marker instances
 *  base on SiFive X280_P64H Manual, Chapter 23 Sifive Worldguard
 */
typedef enum {
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_DEBUG_SBA_0 = 0, ///< Mark transactions coming from the Core Complex 0 Debug SBA
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_APLIC_0,         ///< Mark transactions coming from the Core Complex 0 APLIC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_SMC_0,           ///< Mark transactions coming from the Core Complex 0 SMC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TF_0,            ///< Mark transactions coming from the Trace Funnel 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_0,           ///< Mark transactions coming from the TMC 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_1,           ///< Mark transactions coming from the TMC 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_2,           ///< Mark transactions coming from the TMC 2
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_3,           ///< Mark transactions coming from the TMC 3
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_DEBUG_SBA_1,     ///< Mark transactions coming from the Core Complex 1 Debug SBA
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_APLIC_1,         ///< Mark transactions coming from the Core Complex 1 APLIC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_SMC_1,           ///< Mark transactions coming from the Core Complex 1 SMC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TF_1,            ///< Mark transactions coming from the Trace Funnel 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_4,           ///< Mark transactions coming from the TMC 4
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_5,           ///< Mark transactions coming from the TMC 5
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_6,           ///< Mark transactions coming from the TMC 6
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_TMC_7,           ///< Mark transactions coming from the TMC 7
    P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_NUM              ///< how many instance?
} p64h_sysc_appc_wg_core_complex_marker_t;

/**
 * @brief
 *  define wg core complex checker instances
 *  base on SiFive X280_P64H Manual, Chapter 23 Sifive Worldguard
 */
typedef enum {
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_0 = 0,                 ///< Check transactions on Hart 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_1,                     ///< Check transactions on Hart 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_2,                     ///< Check transactions on Hart 2
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_3,                     ///< Check transactions on Hart 3
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_0,                  ///< Check transactions on IMSIC 0 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_0,                  ///< Check transactions on IMSIC 0 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_1,                  ///< Check transactions on IMSIC 1 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_1,                  ///< Check transactions on IMSIC 1 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_2,                  ///< Check transactions on IMSIC 2 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_2,                  ///< Check transactions on IMSIC 2 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_3,                  ///< Check transactions on IMSIC 3 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_3,                  ///< Check transactions on IMSIC 3 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CLINT_0,                    ///< Check transactions on Core Complex 0 CLINT
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_APLIC_0,                    ///< Check transactions on Core Complex 0 APLIC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_SMC_0,                      ///< Check transactions on Core Complex 0 SMC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TEST_IND_0,                 ///< Check transactions on Core Complex 0 Test Indicator
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_ROOT_ERR_MAP_0,             ///< Check transactions on Core Complex 0 Root Error Map
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_0_0,  ///< Check transactions on Core Complex 0 Extensible_Cache Slice 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_0_1,  ///< Check transactions on Core Complex 0 Extensible Cache Slice 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_0_2,  ///< Check transactions on Core Complex 0 Extensible Cache Slice 2
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_0_3,  ///< Check transactions on Core Complex 0 Extensible Cache Slice 3
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_WRITE_COMBINING_BUFFER_0_0, ///< Check transactions on Core Complex 0 Write Combining Buffer
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_WRITE_COMBINING_BUFFER_0_1, ///< Check transactions on Core Complex 0 Write Combining Buffer
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_FRONT_PORT_0,               ///< Check transactions on Core Complex 0 Front Port
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_0,                       ///< Check transactions on Trace Encoder 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_1,                       ///< Check transactions on Trace Encoder 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_2,                       ///< Check transactions on Trace Encoder 2
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_3,                       ///< Check transactions on Trace Encoder 3
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TF_0,                       ///< Check transactions on Trace Funnel 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_0,                      ///< Check transactions on TMC 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_1,                      ///< Check transactions on TMC 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_2,                      ///< Check transactions on TMC 2
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_3,                      ///< Check transactions on TMC 3
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLC_TO_TL2C_0,             ///< Check transactions on Core Complex 0 CXL.cache to TL2c Bridge
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TL2C_TO_CXLMB_0,            ///< Check transactions on Core Complex 0 TL2c to CXL.mem Bridge
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLC_FRM_CPI_0,             ///< Check transactions on Core Complex 0 CXL.cache from CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLM_TO_CPI_0_0,            ///< Check transactions on Core Complex 0 CXL.mem to CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLM_TO_CPI_1_0,            ///< Check transactions on Core Complex 0 CXL.mem to CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLM_FRM_CPI_0,             ///< Check transactions on Core Complex 0 CXL.cache from CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TL2C_TO_CXLM_0,             ///< Check transactions on Core Complex 0 TL2c to CXL.mem
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_SYS_DEINTRLVR_ERR_BANK_0,   ///< Check transactions on Core Complex 0 Sys Deinterleaver Error Bank
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_MEM_DEINTRLVR_ERR_BANK_0,   ///< Check transactions on Core Complex 0 Mem Deinterleaver Error Bank
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_4,                     ///< Check transactions on Hart 4
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_5,                     ///< Check transactions on Hart 5
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_6,                     ///< Check transactions on Hart 6
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_HART_7,                     ///< Check transactions on Hart 7
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_4,                  ///< Check transactions on IMSIC 4 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_4,                  ///< Check transactions on IMSIC 4 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_5,                  ///< Check transactions on IMSIC 5 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_5,                  ///< Check transactions on IMSIC 5 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_6,                  ///< Check transactions on IMSIC 6 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_6,                  ///< Check transactions on IMSIC 6 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_M_7,                  ///< Check transactions on IMSIC 7 (machine level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_IMSIC_S_7,                  ///< Check transactions on IMSIC 7 (supervisor level)
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CLINT_1,                    ///< Check transactions on Core Complex 1 CLINT
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_APLIC_1,                    ///< Check transactions on Core Complex 1 APLIC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_SMC_1,                      ///< Check transactions on Core Complex 1 SMC
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TEST_IND_1,                 ///< Check transactions on Core Complex 1 Test Indicator
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_ROOT_ERR_MAP_1,             ///< Check transactions on Core Complex 1 Root Error Map
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_1_0,  ///< Check transactions on Core Complex 1 Extensible Cache Slice 0
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_1_1,  ///< Check transactions on Core Complex 1 Extensible Cache Slice 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_1_2,  ///< Check transactions on Core Complex 1 Extensible Cache Slice 2
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_XTENSIBLE_CACHE_SLICE_1_3,  ///< Check transactions on Core Complex 1 Extensible Cache Slice 3
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_WRITE_COMBINING_BUFFER_1_0, ///< Check transactions on Core Complex 1 Write Combining Buffer
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_WRITE_COMBINING_BUFFER_1_1, ///< Check transactions on Core Complex 1 Write Combining Buffer
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_FRONT_PORT_1,               ///< Check transactions on Core Complex 1 Front Port
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_4,                       ///< Check transactions on Trace Encoder 4
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_5,                       ///< Check transactions on Trace Encoder 5
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_6,                       ///< Check transactions on Trace Encoder 6
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TE_7,                       ///< Check transactions on Trace Encoder 7
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TF_1,                       ///< Check transactions on Trace Funnel 1
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_4,                      ///< Check transactions on TMC 4
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_5,                      ///< Check transactions on TMC 5
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_6,                      ///< Check transactions on TMC 6
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TMC_7,                      ///< Check transactions on TMC 7
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLC_TO_TL2C_1,             ///< Check transactions on Core Complex 1 CXL.cache to TL2c Bridge
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TL2C_TO_CXLMB_1,            ///< Check transactions on Core Complex 1 TL2c to CXL.mem Bridge
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLC_FRM_CPI_1,             ///< Check transactions on Core Complex 1 CXL.cache from CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLM_TO_CPI_0_1,            ///< Check transactions on Core Complex 1 CXL.mem to CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLM_TO_CPI_1_1,            ///< Check transactions on Core Complex 1 CXL.mem to CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_CXLM_FRM_CPI_1,             ///< Check transactions on Core Complex 1 CXL.cache from CPI
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_TL2C_TO_CXLM_1,             ///< Check transactions on Core Complex 1 TL2c to CXL.mem
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_SYS_DEINTRLVR_ERR_BANK_1,   ///< Check transactions on Core Complex 1 Sys Deinterleaver Error Bank
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_MEM_DEINTRLVR_ERR_BANK_1,   ///< Check transactions on Core Complex 1 Mem Deinterleaver Error Bank
    P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_NUM                         ///< how many instance?
} p64h_sysc_appc_wg_core_complex_checker_t;

/**
 * @brief
 *   worldguard core configuration
 */
typedef struct {
    uint32_t mwid;      ///< The WID value for machine mode (mwid) associated with all cores of the application
    uint32_t mwidlist;  ///< The list of authorized WIDs the application is allowed to use (mwidlist).
    uint32_t mlwid;     ///< CSR 0x380. The value contained in mlwid is loaded in the wgMarker when the core
                        ///< privilege mode is the next lower privilege mode ([H]S-mode)
    uint32_t slwid;     ///< CSR 0x190. The value contained in slwid is loaded in the wgMarker when the core privilege
                        ///< mode is the next lower privilege mode (VU- or VS-mode). slwid controls the WID for both VS- and
                        ///< VU-modes
    uint32_t mwiddeleg; ///< CSR 0x748. The WIDs delegated to [H]S-mode. (allow setting slwid)
} p64h_sysc_appc_wg_core_cfg_t;

/**
 * @brief
 *  define a worldguard checker slot configuration
 *  base on SiFive X280_P64H Manual, Chapter 23 Sifive Worldguard
 */
typedef struct {
    uint64_t base_address;    ///< base address of the wg checker slot 0 in memory
    uint64_t address;         ///< protected memory region address
    uint64_t perm_list;       ///< list of authorized WIDs with read and write permissions (rwrw..)
    uint32_t config;          ///< configuration structure defining
    uint8_t  appc_owner_mask; ///< owners of the wg checkers
    uint8_t  valid;           ///< injected valid bit of wg checkers
} p64h_sysc_appc_wg_checker_slot_cfg_t;

/**
 * @brief
 *  define a worldguard peripheral checker slot configuration
 *  base on SiFive X280_P64H Manual, Chapter 23 Sifive Worldguard
 */
typedef struct {
    uint64_t base_address;    ///< base address of the wg checker slot 0 in memory
    uint64_t address;         ///< protected memory region address
    uint64_t perm_list;       ///< list of authorized WIDs with read and write permissions (rwrw..)
    uint32_t config;          ///< configuration structure defining
    uint8_t  appc_owner_mask; ///< owners of the wg checkers
    uint8_t  valid;           ///< injected valid bit of wg checkers
    uint8_t  slot_offset;     ///< shared peripheral slot offset
} p64h_sysc_appc_wg_periph_checker_slot_cfg_t;

/**
 * @brief
 *  define status of wg checkers and markers
 */
typedef enum {
    P64H_SYSC_CFG_PROV = 0,   ///< provision from sysc
    P64H_SYSC_FW_SLOT_ENABLE, ///< provision from appc
    P64H_SYSC_FW_SLOT_DISABLE ///< deprovision from appc
} p64h_sysc_appc_wg_dev_cfg_slot_status_t;

/**
 * @brief
 *  define a worldguard marker slot configuration for core complex markers
 */
typedef struct {
    uint64_t base_address; ///< base address of the wg marker slot 0 in memory
    uint32_t wid;          ///< WID associated with the Device ID
    uint32_t lock_valid;   ///< Lock and Valid Register
} p64h_sysc_appc_wg_core_complex_marker_cfg_t;

/**
 * @brief
 *  define a worldguard did marker slot configuration
 */
typedef struct {
    uint32_t did;   ///< Device ID
    uint32_t wid;   ///< WID associated with the Device ID
    uint8_t  lock;  ///< Lock bit
    uint8_t  valid; ///< Valid bit
} p64h_sysc_appc_wg_did_marker_map_cfg_t;

/**
 * @brief
 *  define a worldguard did marker configuration that include 16 slots
 */
typedef struct {
    uint32_t                               default_wid;       ///< Default WID bit value
    uint8_t                                default_wid_lock;  ///< WID lock bit value
    uint8_t                                default_wid_valid; ///< WID valid bit value
    p64h_sysc_appc_wg_did_marker_map_cfg_t maps[16];          ///< checker slots
} p64h_sysc_appc_wg_did_marker_cfg_t;

/**
 * @brief
 *  WGM did-wid entry structure
 */
typedef struct p64h_sysc_appc_wgm_did_wid_lut_t {
    uint32_t wid;     ///< WID
    uint8_t  valid;   ///< Entry is valid
    uint8_t  lock;    ///< Entry is locked
    uint8_t  did;     ///< did-base + channel ID
    uint8_t  fp_sel;  ///< FP select
    uint8_t  ddr_sel; ///< DDR select
} p64h_sysc_appc_wgm_did_wid_lut_t;

/**
 * @brief
 *  define peripheral WGM config
 */
typedef struct p64h_sysc_appc_wg_marker_cfg_t {
    uint32_t                         default_wid;                           ///< default WID
    uint8_t                          default_wid_valid;                     ///< default WID valid
    uint8_t                          default_wid_lock;                      ///< default WID lock
    uint8_t                          num_lut_entries;                       ///< number of did-wid entries to configure
    p64h_sysc_appc_wgm_did_wid_lut_t did_wid_lut[APPC_WGM_NUM_LUT_ENTRIES]; ///< did-wid entry table
} p64h_sysc_appc_wg_marker_cfg_t;

/**
 * @brief
 *  define worldguard configuration for an application
 *  base on SiFive X280_P64H Manual, Chapter 23 Sifive Worldguard
 */
typedef struct {
    p64h_sysc_appc_wg_checker_slot_cfg_t
        core_complex_checker_cfg[P64H_SYSC_APPC_WG_CORE_COMPLEX_CHECKER_NUM]; ///< the set of wg checker configs within the core complex
    p64h_sysc_appc_wg_core_complex_marker_cfg_t
        core_complex_marker_cfg[P64H_SYSC_APPC_WG_CORE_COMPLEX_MARKER_NUM]; ///< the set of wg marker configs within the core complex

    p64h_sysc_appc_wg_checker_slot_cfg_t        ddr_0_wgc[APPC_WG_CHECKER_NUM_SLOT_64]; ///< DDR_0 64 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        ddr_1_wgc[APPC_WG_CHECKER_NUM_SLOT_64]; ///< DDR_1 64 slot WGC

    p64h_sysc_appc_wg_checker_slot_cfg_t        fp_0_wgc[APPC_WG_CHECKER_NUM_SLOT_64];  ///< FP 64 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        fp_1_wgc[APPC_WG_CHECKER_NUM_SLOT_64];  ///< FP 64 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        pmc_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< PMC_0 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        pmc_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< PMC_1 slot WGC

    p64h_sysc_appc_wg_marker_cfg_t              mem_qos_0_wgm; ///< MEM_QOS 0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              mem_qos_1_wgm; ///< MEM_QOS 1 WGM
    p64h_sysc_appc_wg_marker_cfg_t              sys_qos_0_wgm; ///< SYS_QOS 0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              sys_qos_1_wgm; ///< SYS_QOS 1 WGM

    p64h_sysc_appc_wg_checker_slot_cfg_t        ocr_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< OCR_0 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        ocr_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< OCR_1 32 slot WGC

    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_edac_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32];        ///< NVM_EDAC_0 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_edac_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32];        ///< NVM_EDAC_1 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_sram_edac_0_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NVM_SRAM_EDAC_0_0 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_sram_edac_0_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NVM_SRAM_EDAC_0_1 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_sram_edac_1_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NVM_SRAM_EDAC_1_0 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_sram_edac_1_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NVM_SRAM_EDAC_1_1 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_sram_edac_2_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NVM_SRAM_EDAC_2_0 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_sram_edac_2_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NVM_SRAM_EDAC_2_1 32 slot WGC
    p64h_sysc_appc_wg_checker_slot_cfg_t        nvm_ss_cfg_wgc[APPC_WG_CHECKER_NUM_SLOT_32];        ///< NVM_SS_CFG 32 slot WGC

    p64h_sysc_appc_wg_marker_cfg_t              nvm_dma0_wgm;    ///< NVM_DMA0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              nvm_dma1_wgm;    ///< NVM_DMA1 WGM
    p64h_sysc_appc_wg_marker_cfg_t              nvm_sd_dma0_wgm; ///< NVM_SD_DMA0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              nvm_sd_dma1_wgm; ///< NVM_SD_DMA1 WGM

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t enet_ep_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< ENET_EP shared WGC, slot[0:3]
    p64h_sysc_appc_wg_marker_cfg_t              enet_ep_0_wgm;                            ///< ENET_EP_0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              enet_ep_1_wgm;                            ///< ENET_EP_1 WGM
    p64h_sysc_appc_wg_marker_cfg_t              enet_ep_2_wgm;                            ///< ENET_EP_2 WGM
    p64h_sysc_appc_wg_marker_cfg_t              enet_ep_3_wgm;                            ///< ENET_EP_3 WGM

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t enet_swr_switch_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< ENET_EP SWITCH WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t enet_swr_top_wgc[APPC_WG_CHECKER_NUM_SLOT_32];    ///< ENET_EP SWITCH TOP WGC

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t appdma_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< APPDMA0 WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t appdma_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< APPDMA1 WGC

    p64h_sysc_appc_wg_marker_cfg_t              appdma_0_wgm; ///< APPDMA0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              appdma_1_wgm; ///< APPDMA1 WGM

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t ipc_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< IPC0 WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t ipc_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< IPC1 WGC

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t nmra_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NMRA0 WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t nmra_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< NMRA1 WGC

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t iommu_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< IOMMU0 WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t iommu_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< IOMMU1 WGC
    p64h_sysc_appc_wg_marker_cfg_t              iommu_0_wgm;                              ///< IOMMU0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              iommu_1_wgm;                              ///< IOMMU1 WGM

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t pcie_0_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< PCIE0 WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t pcie_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< PCIE1 WGC
    p64h_sysc_appc_wg_marker_cfg_t              pcie_0_wgm;                              ///< PCIE0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              pcie_1_wgm;                              ///< PCIE1 WGM

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t m2_1_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< M2 WGC1 (shared)
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t m2_2_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< M2 WGC2 (SPW)
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t m2_3_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< M2 WGC3 (JTAG, SPI) WGC
    p64h_sysc_appc_wg_periph_checker_slot_cfg_t m2_4_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< M2 WGC4 APPC_STAT
    p64h_sysc_appc_wg_marker_cfg_t              spw_0_wgm;                             ///< SPW0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              spw_1_wgm;                             ///< SPW1 WGM
    p64h_sysc_appc_wg_marker_cfg_t              usb_0_wgm;                             ///< USB0 WGM
    p64h_sysc_appc_wg_marker_cfg_t              usb_1_wgm;                             ///< USB1 WGM

    p64h_sysc_appc_wg_periph_checker_slot_cfg_t user_crypto_wgc[APPC_WG_CHECKER_NUM_SLOT_32]; ///< USER CRYPTO WGC
    p64h_sysc_appc_wg_marker_cfg_t              user_crypto_wgm;                              ///< USER CRYPTO WGM
    p64h_sysc_appc_wg_marker_cfg_t              trace_wgm;                                    ///< trace WGM
} p64h_sysc_appc_wg_cfg_t;

#endif // P64H_SYSC_SHARED_WGUARD_BA_H