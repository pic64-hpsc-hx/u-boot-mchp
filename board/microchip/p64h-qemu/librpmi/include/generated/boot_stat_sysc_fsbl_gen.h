/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * SYSC_FSBL BOOT_STAT defines
 */

 /*--------------------.
 | auto-generated file |
 +--------------------*/

#ifdef __ASSEMBLER__
// #defines are for when included by assembler .S files.
#define BOOT_STAGE_SYSC_RTEMS_MAIN               32U ///< Inside RTEMS main()  
#define BOOT_STAGE_SYSC_FSBL_HEART_BEAT          33U ///< SYSC FSBL - heartbeat  
#define BOOT_STAGE_SYSC_FSBL_SYSTEM_TASK_CTXT    34U ///< SYSC FSBL - system task  
#define BOOT_STAGE_SYSC_FSBL_CLK_RAMPUP          35U ///< SYSC FSBL - clock rampup  
#define BOOT_STAGE_SYSC_FSBL_BLOB_FETCH          36U ///< SYSC FSBL - blob fetch  
#define BOOT_STAGE_SYSC_FSBL_SYS_HEALTH_CHK      37U ///< SYSC FSBL - sys health check  
#define BOOT_STAGE_SYSC_FSBL_COM_ACTIVE          38U ///< SYSC FSBL - com active  
#define BOOT_STAGE_SYSC_FSBL_FULL_NVM_INTF_ACTIVE 39U ///< SYSC FSBL - full NVM interface active  
#define BOOT_STAGE_SYSC_FSBL_PHASE_1             40U ///< SYSC FSBL - phase 1  
#define BOOT_STAGE_SYSC_FSBL_SVC_START           41U ///< SYSC FSBL - service started  
#define BOOT_STAGE_SYSC_FSBL_RAS_ACTIVE          42U ///< SYSC FSBL - RAS is up and active  
#define BOOT_STAGE_SYSC_FSBL_APP_HEALTH_CHK      43U ///< SYSC FSBL - app health check  
#define BOOT_STAGE_SYSC_FSBL_SAFE_MODE           44U ///< SYSC FSBL - safe mode  
#define BOOT_STAGE_SYSC_FSBL_RSVD_13             45U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_14             46U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_15             47U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_16             48U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_17             49U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_18             50U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_19             51U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_20             52U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_21             53U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_22             54U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_23             55U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_24             56U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_25             57U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_26             58U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_27             59U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_28             60U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_29             61U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_30             62U ///< Reserved for future use for SYSC FW  
#define BOOT_STAGE_SYSC_FSBL_RSVD_31             63U ///< Reserved for future use for SYSC FW  
#else // __ASSEMBLER__

#ifndef BOOT_STAT_GEN_SYSC_FSBL_H
#define BOOT_STAT_GEN_SYSC_FSBL_H

/// Definitions of System Controller FSBL boot stages
typedef enum boot_stage_sysc_fsbl_t
{
    BOOT_STAGE_SYSC_RTEMS_MAIN               = 32U, ///< Inside RTEMS main()  
    BOOT_STAGE_SYSC_FSBL_HEART_BEAT          = 33U, ///< SYSC FSBL - heartbeat  
    BOOT_STAGE_SYSC_FSBL_SYSTEM_TASK_CTXT    = 34U, ///< SYSC FSBL - system task  
    BOOT_STAGE_SYSC_FSBL_CLK_RAMPUP          = 35U, ///< SYSC FSBL - clock rampup  
    BOOT_STAGE_SYSC_FSBL_BLOB_FETCH          = 36U, ///< SYSC FSBL - blob fetch  
    BOOT_STAGE_SYSC_FSBL_SYS_HEALTH_CHK      = 37U, ///< SYSC FSBL - sys health check  
    BOOT_STAGE_SYSC_FSBL_COM_ACTIVE          = 38U, ///< SYSC FSBL - com active  
    BOOT_STAGE_SYSC_FSBL_FULL_NVM_INTF_ACTIVE = 39U, ///< SYSC FSBL - full NVM interface active  
    BOOT_STAGE_SYSC_FSBL_PHASE_1             = 40U, ///< SYSC FSBL - phase 1  
    BOOT_STAGE_SYSC_FSBL_SVC_START           = 41U, ///< SYSC FSBL - service started  
    BOOT_STAGE_SYSC_FSBL_RAS_ACTIVE          = 42U, ///< SYSC FSBL - RAS is up and active  
    BOOT_STAGE_SYSC_FSBL_APP_HEALTH_CHK      = 43U, ///< SYSC FSBL - app health check  
    BOOT_STAGE_SYSC_FSBL_SAFE_MODE           = 44U, ///< SYSC FSBL - safe mode  
    BOOT_STAGE_SYSC_FSBL_RSVD_13             = 45U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_14             = 46U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_15             = 47U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_16             = 48U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_17             = 49U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_18             = 50U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_19             = 51U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_20             = 52U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_21             = 53U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_22             = 54U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_23             = 55U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_24             = 56U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_25             = 57U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_26             = 58U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_27             = 59U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_28             = 60U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_29             = 61U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_30             = 62U, ///< Reserved for future use for SYSC FW  
    BOOT_STAGE_SYSC_FSBL_RSVD_31             = 63U, ///< Reserved for future use for SYSC FW  
} boot_stage_sysc_fsbl_t;

/**
 * @brief return string associated with boot stat code
 * note: we could generate a c file for this.
 *  for now, if we just call this from one .c file it should be fine.
 *  we don't really need the performance or space improvement of an array lookup.
 * 
 * @param[in] code - boot stat enum
 * @return string
 */
static inline const char *boot_stage_sysc_fsbl_str( boot_stage_sysc_fsbl_t code )
{
    const char *res;
    switch (code)
    {
          // Inside RTEMS main()
          case BOOT_STAGE_SYSC_RTEMS_MAIN:
              res = "BOOT_STAGE_SYSC_RTEMS_MAIN";
              break;
          // SYSC FSBL - heartbeat
          case BOOT_STAGE_SYSC_FSBL_HEART_BEAT:
              res = "BOOT_STAGE_SYSC_FSBL_HEART_BEAT";
              break;
          // SYSC FSBL - system task
          case BOOT_STAGE_SYSC_FSBL_SYSTEM_TASK_CTXT:
              res = "BOOT_STAGE_SYSC_FSBL_SYSTEM_TASK_CTXT";
              break;
          // SYSC FSBL - clock rampup
          case BOOT_STAGE_SYSC_FSBL_CLK_RAMPUP:
              res = "BOOT_STAGE_SYSC_FSBL_CLK_RAMPUP";
              break;
          // SYSC FSBL - blob fetch
          case BOOT_STAGE_SYSC_FSBL_BLOB_FETCH:
              res = "BOOT_STAGE_SYSC_FSBL_BLOB_FETCH";
              break;
          // SYSC FSBL - sys health check
          case BOOT_STAGE_SYSC_FSBL_SYS_HEALTH_CHK:
              res = "BOOT_STAGE_SYSC_FSBL_SYS_HEALTH_CHK";
              break;
          // SYSC FSBL - com active
          case BOOT_STAGE_SYSC_FSBL_COM_ACTIVE:
              res = "BOOT_STAGE_SYSC_FSBL_COM_ACTIVE";
              break;
          // SYSC FSBL - full NVM interface active
          case BOOT_STAGE_SYSC_FSBL_FULL_NVM_INTF_ACTIVE:
              res = "BOOT_STAGE_SYSC_FSBL_FULL_NVM_INTF_ACTIVE";
              break;
          // SYSC FSBL - phase 1
          case BOOT_STAGE_SYSC_FSBL_PHASE_1:
              res = "BOOT_STAGE_SYSC_FSBL_PHASE_1";
              break;
          // SYSC FSBL - service started
          case BOOT_STAGE_SYSC_FSBL_SVC_START:
              res = "BOOT_STAGE_SYSC_FSBL_SVC_START";
              break;
          // SYSC FSBL - RAS is up and active
          case BOOT_STAGE_SYSC_FSBL_RAS_ACTIVE:
              res = "BOOT_STAGE_SYSC_FSBL_RAS_ACTIVE";
              break;
          // SYSC FSBL - app health check
          case BOOT_STAGE_SYSC_FSBL_APP_HEALTH_CHK:
              res = "BOOT_STAGE_SYSC_FSBL_APP_HEALTH_CHK";
              break;
          // SYSC FSBL - safe mode
          case BOOT_STAGE_SYSC_FSBL_SAFE_MODE:
              res = "BOOT_STAGE_SYSC_FSBL_SAFE_MODE";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_13:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_13";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_14:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_14";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_15:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_15";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_16:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_16";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_17:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_17";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_18:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_18";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_19:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_19";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_20:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_20";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_21:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_21";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_22:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_22";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_23:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_23";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_24:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_24";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_25:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_25";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_26:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_26";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_27:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_27";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_28:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_28";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_29:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_29";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_30:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_30";
              break;
          // Reserved for future use for SYSC FW
          case BOOT_STAGE_SYSC_FSBL_RSVD_31:
              res = "BOOT_STAGE_SYSC_FSBL_RSVD_31";
              break;
          default:
              res = "unknown boot_stage_sysc_fsbl_t";
              break;

    }
    return res;
}
#endif
#endif // __ASSEMBLER__
