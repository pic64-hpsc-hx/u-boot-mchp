/* (c) 2025 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file  p64h_sysc_common_types.h
 * @brief API type
 * @addtogroup API
 * @ingroup p64h_sysc_api
 * @{
 */

#ifndef P64H_SYSC_COMMON_TYPE_H
#define P64H_SYSC_COMMON_TYPE_H

#include <env/p64h_sysc_os_specific.h>

/* Public Defines ------------------------------------------------- */
#define P64H_SYSC_STRING_MAX            256UL
#define P64H_SYSC_EDAC_LARGE_SKIP_SLOTS 2u ///< define the maximum number of slots for SRAM patrol srubbing large skip range
#define P64H_SYSC_EDAC_SMALL_SKIP_SLOTS 8u ///< define the maximum number of slots for SRAM patrol srubbing small skip range
/* Public Structs and Enums --------------------------------------- */

/// partition identifier
typedef enum {
    P64H_SYSC_PSM_ID_APPC_P0 = 0, ///< AppC Partition 0
    P64H_SYSC_PSM_ID_APPC_P1,     ///< AppC Partition 1
    P64H_SYSC_PSM_ID_APPC_P2,     ///< AppC Partition 2
    P64H_SYSC_PSM_ID_APPC_P3,     ///< AppC Partition 3
    P64H_SYSC_PSM_ID_APPC_P4,     ///< AppC Partition 4
    P64H_SYSC_PSM_ID_APPC_P5,     ///< AppC Partition 5
    P64H_SYSC_PSM_ID_APPC_P6,     ///< AppC Partition 6
    P64H_SYSC_PSM_ID_APPC_P7,     ///< AppC Partition 7
    P64H_SYSC_PSM_ID_SYSC,        ///< SysC Partition
    P64H_SYSC_PSM_ID_COUNT        ///< Number of partitions (not a valid ID)
} p64h_sysc_psm_id_t;

/// ACPI partition identifier
typedef enum {
    P64H_SYSC_ACPI_PID_APPC_P0 = 0, ///< AppC Partition 0
    P64H_SYSC_ACPI_PID_APPC_P1,     ///< AppC Partition 1
    P64H_SYSC_ACPI_PID_APPC_P2,     ///< AppC Partition 2
    P64H_SYSC_ACPI_PID_APPC_P3,     ///< AppC Partition 3
    P64H_SYSC_ACPI_PID_APPC_P4,     ///< AppC Partition 4
    P64H_SYSC_ACPI_PID_APPC_P5,     ///< AppC Partition 5
    P64H_SYSC_ACPI_PID_APPC_P6,     ///< AppC Partition 6
    P64H_SYSC_ACPI_PID_APPC_P7,     ///< AppC Partition 7
    P64H_SYSC_ACPI_PID_COUNT        ///< Number of ACPI partitions (not a valid ID)
} p64h_sysc_acpi_pid_t;

/// enumerate of EDAC FEC mode
typedef enum {
    P64H_SYSC_FEC_MODE_BYPASS = 0u, ///< bypass mode FEC is not used
    P64H_SYSC_FEC_MODE_SECDED,      ///< SECDED ECC fec mode
    P64H_SYSC_FEC_MODE_BCH,         ///< BCH fec mode (NVM only)
    P64H_SYSC_FEC_MODE_DEECE        ///< DEECE (Reed Solomon) fec mode (DDR only)
} p64h_sysc_mem_fec_mode_t;

/// enumerate of notification state
typedef enum {
    P64H_SYSC_EVT_NOTIFICATION_ACTIVE   = 0, ///< Notification active
    P64H_SYSC_EVT_NOTIFICATION_INACTIVE = 1, ///< Notification inactive
} p64h_sysc_evt_notification_state_t;

/// Demand srubbing configuration
typedef struct {
    bool enable;       ///< Enables the demand scrub logic. This should only be used when ecc is enabled .
                       ///< Demand scrubbing will cause a write transaction when correctable data is read from memory.
    uint8_t threshold; ///< The ECC error count greater than srub_thres activates a write back scrub. (5 bits)
                       ///< for BCH, this is the number of bits per decoder (8 decoders total)
                       ///< for SECDED, at most one bit can be correctable, per decoder making for a total of 8 bits which can be set as the threshold
    uint64_t no_corr_msk;    ///< This mask tells the EDAC to ignore corrections on the interface pin when the associated mask bit is set high.  E.g.
                             ///< 0x0000_00FF tells the EDAC to ignore errors on pins 7:0. If errors only appear on these pins no scrub write will be
                             ///< performed.
    uint16_t no_corr_msk_hi; ///< DDR only
                             ///<  upper 16-bits of no_corr_mask that has 82 bits overall as DDR might need up to 80 pins
} p64h_sysc_demand_scrub_cfg_t;

/// SRAM patrol skip range configuraton
typedef struct {
    uint32_t offset; ///< Number of blocks from the start address to skip patrol scrub reads.
                     ///< skip_start_addr = p64h_sysc_sram_edac_psrub_cfg_t::start_addr + (p64h_sysc_sram_edac_psrub_cfg_t::block_size * offset)
    uint16_t size;   ///< Number of blocks from skip offset to be skipped.
                     ///< skip_end_start = skip_start_addr + (p64h_sysc_sram_edac_psrub_cfg_t::block_size* size)
    ///< Note that this structure is used for large and small skip range. size field is respectively 8 and 16 bits for small and large
    ///< skip range
} p64h_sysc_patrol_scrub_skip_range_t;

/// Patrol scrubbing configuration for SRAM and NVM EDAC
typedef struct {
    bool enable;    ///< Enable patrol scrubbing. This should only be used when when ecc_en and demand_scrub_en are enabled. Patrol scrubing enabled,
                    ///< will generate reads from memory periodically based on configuration fields
    uint8_t period; ///< If set to 0, the patrol scrub will perform scrubbing as fast as possible. For non-zero values period minimum ~60 ns
                    ///< to maximum ~60 sec. The scrub clock for NVM EDAC is 600 MHz. This is a 6 bits field.
    uint64_t priority; ///< SRAM and DDR only
                       ///< Number of clock cycles that the patrol scrub priority is lower than functional data transfers. Arbitration priority low
                       ///< for time = clock period * priority. To enable this feature priority needs to be less than 2^ (srub period + 1 ) .
    uint8_t patrol_thrd_msk_en; ///< NVM EDAC only
                                ///< Enable patrol scrubbing thread. Only one thread can be enabled at one time. This enable should not conflict with
                                ///< the functional app enable.
                                ///< 0000_0001: Enables thread 0
                                ///< 0000_0010: Enables thread 1
                                ///< 0000_0100: Enables thread 2
                                ///< 0000_1000: Enables thread 3
                                ///< 0001_0000: Enables thread 4
                                ///< 0010_0000: Enables thread 5
                                ///< 0100_0000: Enables thread 6
                                ///< 1000_0000: Enables thread 7
    uint32_t block_num;  ///< The number of blocks from the start address that are to be patrol scrubbed. last address scrubbed = Start_Address + (
                         ///< block_num * block_size) -1. BLK_NUM should not equal zero; behaviour not defined
    uint16_t block_size; ///< The number of bytes in a scrubbed block of memory. This multiplied by block_num defines the size of scrubbed memory
                         ///< region. Last address scrubbed = Start_Address + ( block_num * block_size) -1. This block size also determines the
                         ///< granularity of patrol scrub skipped memory region. block_size should not equal zero; behavior not defined
    uint64_t start_addr; ///< device patrol scrub start address uses byte addressing. bits 33:1 are valid. Note: the start address should not be
                         ///< defined within a skip region
    bool scrub_once;     ///< DDR only
                         ///< Patrol scrubber will continously run if enabled
    uint8_t patrol_scrub_per; ///< DDR only
                              ///< Number of clock cycles between patrol scrub reads
                              ///< period of reads = clock period * 2^(patrol_scrub_per+1) + clock period (max value for patrol_scrub_per 35)
    p64h_sysc_patrol_scrub_skip_range_t large_skip[P64H_SYSC_EDAC_LARGE_SKIP_SLOTS]; ///< large skip ranges
    p64h_sysc_patrol_scrub_skip_range_t small_skip[P64H_SYSC_EDAC_SMALL_SKIP_SLOTS]; ///< small skip ranges
} p64h_sysc_patrol_scrub_cfg_t;

#endif // P64H_SYSC_COMMON_TYPE_H
/// @}
