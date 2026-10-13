/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * SECC_ZSBL BOOT_STAT defines
 */

 /*--------------------.
 | auto-generated file |
 +--------------------*/

#ifdef __ASSEMBLER__
// #defines are for when included by assembler .S files.
#define BOOT_STAGE_SECC_SPACEWIRE_ACCESS_ALLOWED  0U ///< SYSC SpaceWire Access Allowed (status, HW driven)  
#define BOOT_STAGE_SECC_ENTRY                     1U ///< Start of SECC firmware (status)  
#define BOOT_STAGE_SECC_TOP_POWER                 2U ///< top power reset (status)  
#define BOOT_STAGE_SECC_RANDOM                    3U ///< initialize random (status)  
#define BOOT_STAGE_SECC_ITIM_INIT                 4U ///< scrub ITIM (status)  
#define BOOT_STAGE_SECC_MAIN                      5U ///< start of SECC main() (status)  
#define BOOT_STAGE_SECC_WDOG_INIT                 6U ///< watchdog initialization (status)  
#define BOOT_STAGE_SECC_OCR_INIT                  7U ///< hardware zeroization of OCR (status)  
#define BOOT_STAGE_SECC_DMA_INIT                  8U ///< SECC DMAC initialization (status)  
#define BOOT_STAGE_SECC_MODE_VIRGIN               9U ///< Entering Virgin Mode (status)  
#define BOOT_STAGE_SECC_MODE_TEST                10U ///< Entering Test Mode (status)  
#define BOOT_STAGE_SECC_MODE_NORMAL              11U ///< Entering Normal Mode (status)  
#define BOOT_STAGE_SECC_MODE_FIRST               12U ///< Entering First Boot (status)  
#define BOOT_STAGE_SECC_FMC_FW_DWNLD_COMPLETE    13U ///< SecC First Mutable Code download done (status)  
#define BOOT_STAGE_SECC_PUF_INIT                 14U ///< Initializing the PUF (status)  
#define BOOT_STAGE_SECC_FMC_FW_MAIN              15U ///< Entered First Mutable Code main (status)  
#define BOOT_STAGE_SECC_PATCH_TEST               16U ///< used by patch testing to show that a patch is executing  
#define BOOT_STAGE_SECC_SYSC_LBIST               17U ///< Running SysC LBIST (status)  
#define BOOT_STAGE_SECC_LBIST                    18U ///< Running SecC LBIST (status)  
#define BOOT_STAGE_SECC_BURNIN_MODE              19U ///< Device is in Burn-in mode (status)  
#define BOOT_STAGE_SECC_BOOTROM_XFER_COMPLETE    20U ///< SYSC boot ROM transfer completed (status)  
#define BOOT_STAGE_SECC_AUTORESET_DISABLED       21U ///< Entering Critical section, AutoReset Disabled (status)  
#define BOOT_STAGE_SECC_SYSC_REBOOT              22U ///< SYSC initiated reboot (status)  
#define BOOT_STAGE_SECC_SYS_INIT                 23U ///< SYSC out of reset (status)  
#define BOOT_STAGE_SECC_BOOTROM_XFER             24U ///< SYSC boot ROM transfer started (status)  
#define BOOT_STAGE_SECC_MBOX_INIT                25U ///< Initializing SECC Mailbox (status)  
#define BOOT_STAGE_SECC_EMERG                    26U ///< SpW emergency mode enabled (status)  
#define BOOT_STAGE_SECC_AR0_RNMI_INT             27U ///< halt in RNMI interrupt handler in AR0 (status)  
#define BOOT_STAGE_SECC_AR0_MTVEC                28U ///< halt in MTVEC handler in AR0 (status)  
#define BOOT_STAGE_SECC_AR0_RNMI_EXCP            29U ///< halt in RNMI exception handler in AR0 (status)  
#define BOOT_STAGE_SECC_EARLY_TRAP               30U ///< halt in secc early trap exception handler (status)  
#define BOOT_STAGE_SECC_HOLD                     31U ///< enter in halt state, infinite WFI loop (status)  
#define BOOT_STAGE_SECC_EXCP_HANDLER             32U ///< Entering exception handler (status)  
#define BOOT_STAGE_SECC_RNMI_INT_HANDLER         33U ///< Entering RNMI interrupt handler (status)  
#define BOOT_STAGE_SECC_RNMI_EXCP_HANDLER        34U ///< Entering RNMI exception handler (status)  
#define BOOT_STAGE_SECC_AR0_SYSC_KEEP_ALIVE      35U ///< ignore sysc keep sysc alive expiry AR0 (status)  
#define BOOT_STAGE_SECC_PATCHED_BOOTROM_XFER_COMPLETE 36U ///< patched SYSC boot ROM transfer completed (status)  
#define BOOT_STAGE_SECC_APPLY_PATCHES            37U ///< pacthes have been applied (status)  
#define BOOT_STAGE_SECC_TAMPER_DIGEST_CHECK_FAIL 38U ///< Detected a tamper event, digest check (status)  
#define BOOT_STAGE_SECC_TAMPER_EVENT_DETECTED    39U ///< Detected a tamper event on MESH or Tamper monitor (status)  
#define BOOT_STAGE_SECC_FSBL_ENTRY               40U ///< FSBL Entry (status)  
#define BOOT_STAGE_SECC_OTP_PUF_BLANK            41U ///< PUF data in OTP is blank (check)  
#define BOOT_STAGE_SECC_SKC_INIT_FAILED          42U ///< SKC init failed (check)  
#define BOOT_STAGE_SECC_PQ_INIT_FAILED           43U ///< PQ Core initialization failed (check)  
#define BOOT_STAGE_SECC_MBOX_CMD_MISMATCH        44U ///< Mailbox Command mismatch. Command register does not match cmd field (check)  
#define BOOT_STAGE_SECC_JTAG_MBOX_CMD_INVALID    45U ///< JTAG Invalid Mailbox command (check)  
#define BOOT_STAGE_SECC_KEY_LOAD_FAIL            46U ///< Key Load failed (check)  
#define BOOT_STAGE_SECC_EXPORT_FAIL              47U ///< Key Export failed (check)  
#define BOOT_STAGE_SECC_SHA3_MISMATCH            48U ///< SHA3 check failed (check)  
#define BOOT_STAGE_SECC_SKC_SHA3_MISMATCH        49U ///< SKC SHA3 check failed (check)  
#define BOOT_STAGE_SECC_SKC_SHA3_FAILED          50U ///< SKC SHA3 Operation failed (check)  
#define BOOT_STAGE_SECC_BITS_INVALID_HDR         51U ///< Invalid image header (check)  
#define BOOT_STAGE_SECC_IMG_VALIDATE_ERR         52U ///< Error during image validation (check)  
#define BOOT_STAGE_SECC_SIGNATURE_CHECK_FAIL     53U ///< Signature verification failed (check)  
#define BOOT_STAGE_SECC_DRBG_INIT_FAILED         54U ///< DRBG failed to generate random value (check)  
#define BOOT_STAGE_SECC_ERROR_STACK_OVERFLOW     55U ///< Stack overflow detected in handlers (check)  
#define BOOT_STAGE_SECC_AES_KEY_LOAD_FAIL        56U ///< Failed to load AES key (check)  
#define BOOT_STAGE_SECC_AES_START_FAIL           57U ///< AES hardware failed to initialize (check)  
#define BOOT_STAGE_SECC_ERR_OTP_OPERATION_FAILED 58U ///< OTP read/write operation failed (check)  
#define BOOT_STAGE_SECC_EC_HASH_CHECK_FAIL       59U ///< EC Pub key hash check failed (check)  
#define BOOT_STAGE_SECC_PQ_HASH_CHECK_FAIL       60U ///< PQ Pub key hash check failed (check)  
#define BOOT_STAGE_SECC_PQC_ENTROPY_FAIL         61U ///< PQC entropy load failed (check)  
#define BOOT_STAGE_SECC_SHA3_DMA_FAIL            62U ///< SHA3 DMA failed (check)  
#define BOOT_STAGE_SECC_STACK_OVERFLOW           63U ///< Reserved for future use (exception handler check)  
#define BOOT_STAGE_SECC_ARM_AND_FIRE_FAILED      64U ///< an arm and fire register failed (check)  
#define BOOT_STAGE_SECC_ASSERT                   65U ///< Software Assert (check)  
#define BOOT_STAGE_SECC_DMA_XFER_TIMEOUT         66U ///< DMA block transfer timeout (check)  
#define BOOT_STAGE_SECC_DMA_SLAVE_ERROR_FAIL     67U ///< DMA bus slave error transfer failure (check)  
#define BOOT_STAGE_SECC_ZSBL_ROM_CHECK_FAILED    68U ///< rom integrity check failed (check)  
#define BOOT_STAGE_SECC_DMA_SYSC_PATCH_FAIL      69U ///< DMA patch into SYSC ITIM failed (check)  
#define BOOT_STAGE_SECC_PUF_RECONSTRUCT_FAIL     70U ///< PUF reconstruct operation failed (check)  
#define BOOT_STAGE_SECC_UNEXPECTED_ERROR         71U ///< Unexpected error (check)  
#define BOOT_STAGE_SECC_BOOT_MODE_UNKNOWN        72U ///< Unknown boot mode. Halt firmware (check)  
#define BOOT_STAGE_SECC_ROM_CHECK_FAILED         73U ///< SECC ITIM ROM checksum verification failed (check)  
#define BOOT_STAGE_SECC_BOOTROM_CHECK_FAILED     74U ///< ZSBL checksum verification failed (check)  
#define BOOT_STAGE_SECC_DEV_RST                  75U ///< SECC requested a device reset (check)  
#define BOOT_STAGE_SECC_SYSC_MBOX_CMD_INVALID    76U ///< Invalid System Mailbox command (check)  
#define BOOT_STAGE_SECC_BOOTROM_XFER_FAIL        77U ///< SYSC boot ROM transfer failed (check)  
#define BOOT_STAGE_SECC_PUF_SEED_GEN_FAIL        78U ///< PUF failed to generate random seed (check)  
#define BOOT_STAGE_SECC_PUF_INIT_FAILED          79U ///< PUF initialization failed (check)  
#define BOOT_STAGE_SECC_PATCH_NOT_COMPATIBLE     80U ///< a secure or system controller patch is not compatible with the rom  
#define BOOT_STAGE_SECC_PUF_ENROLL_FAIL          81U ///< PUF enrollment failed (check)  
#define BOOT_STAGE_SECC_PATCH_EXCEPTION_HANG_TEST 82U ///< used by patch testing to hang when entering the exception handler  
#define BOOT_STAGE_SECC_RESERVED_CHECK_3_19      83U ///< Reserved for future use (check)  
#define BOOT_STAGE_SECC_BOOT_CNT0                84U ///< Secc Reboot counter bit 0 (boot counter status)  
#define BOOT_STAGE_SECC_BOOT_CNT1                85U ///< Secc Reboot counter bit 1 (boot counter status)  
#define BOOT_STAGE_SECC_BOOT_CNT2                86U ///< Secc Reboot counter 2 (boot counter status)  
#define BOOT_STAGE_SECC_BOOT_STICKY_0            87U ///< SecC ZSBL encoding reboot failure cause from M1 bit 0 (reboot fail cause)  
#define BOOT_STAGE_SECC_BOOT_STICKY_1            88U ///< SecC ZSBL encoding reboot failure cause from M1 bit 1 (reboot fail cause)  
#define BOOT_STAGE_SECC_BOOT_STICKY_2            89U ///< SecC ZSBL encoding reboot failure cause from M1 bit 2 (reboot fail cause)  
#define BOOT_STAGE_SECC_BOOT_STICKY_3            90U ///< SecC ZSBL encoding reboot failure cause from M1 bit 3 (reboot fail cause)  
#define BOOT_STAGE_SECC_BOOT_STICKY_4            91U ///< SecC ZSBL encoding reboot failure cause from M1 bit 4 (reboot fail cause)  
#define BOOT_STAGE_SECC_BOOT_STICKY_5            92U ///< SecC ZSBL encoding reboot failure cause from M1 bit 5 (reboot fail cause)  
#define BOOT_STAGE_SECC_RESET_REASON_STICKY_0    93U ///< SecC ZSBL encoding reset reason from M1 bit 0 (reset reason)  
#define BOOT_STAGE_SECC_RESET_REASON_STICKY_1    94U ///< SecC ZSBL encoding reset reason from M1 bit 1 (reset reason)  
#define BOOT_STAGE_SECC_RESET_REASON_STICKY_2    95U ///< SecC ZSBL encoding reset reason from M1 bit 2 (reset reason)  
#else // __ASSEMBLER__

#ifndef BOOT_STAT_GEN_SECC_ZSBL_H
#define BOOT_STAT_GEN_SECC_ZSBL_H

/// Definitions of Secure Controller ZSBL boot stages
typedef enum boot_stage_secc_zsbl_t
{
    BOOT_STAGE_SECC_SPACEWIRE_ACCESS_ALLOWED =  0U, ///< SYSC SpaceWire Access Allowed (status, HW driven)  
    BOOT_STAGE_SECC_ENTRY                    =  1U, ///< Start of SECC firmware (status)  
    BOOT_STAGE_SECC_TOP_POWER                =  2U, ///< top power reset (status)  
    BOOT_STAGE_SECC_RANDOM                   =  3U, ///< initialize random (status)  
    BOOT_STAGE_SECC_ITIM_INIT                =  4U, ///< scrub ITIM (status)  
    BOOT_STAGE_SECC_MAIN                     =  5U, ///< start of SECC main() (status)  
    BOOT_STAGE_SECC_WDOG_INIT                =  6U, ///< watchdog initialization (status)  
    BOOT_STAGE_SECC_OCR_INIT                 =  7U, ///< hardware zeroization of OCR (status)  
    BOOT_STAGE_SECC_DMA_INIT                 =  8U, ///< SECC DMAC initialization (status)  
    BOOT_STAGE_SECC_MODE_VIRGIN              =  9U, ///< Entering Virgin Mode (status)  
    BOOT_STAGE_SECC_MODE_TEST                = 10U, ///< Entering Test Mode (status)  
    BOOT_STAGE_SECC_MODE_NORMAL              = 11U, ///< Entering Normal Mode (status)  
    BOOT_STAGE_SECC_MODE_FIRST               = 12U, ///< Entering First Boot (status)  
    BOOT_STAGE_SECC_FMC_FW_DWNLD_COMPLETE    = 13U, ///< SecC First Mutable Code download done (status)  
    BOOT_STAGE_SECC_PUF_INIT                 = 14U, ///< Initializing the PUF (status)  
    BOOT_STAGE_SECC_FMC_FW_MAIN              = 15U, ///< Entered First Mutable Code main (status)  
    BOOT_STAGE_SECC_PATCH_TEST               = 16U, ///< used by patch testing to show that a patch is executing  
    BOOT_STAGE_SECC_SYSC_LBIST               = 17U, ///< Running SysC LBIST (status)  
    BOOT_STAGE_SECC_LBIST                    = 18U, ///< Running SecC LBIST (status)  
    BOOT_STAGE_SECC_BURNIN_MODE              = 19U, ///< Device is in Burn-in mode (status)  
    BOOT_STAGE_SECC_BOOTROM_XFER_COMPLETE    = 20U, ///< SYSC boot ROM transfer completed (status)  
    BOOT_STAGE_SECC_AUTORESET_DISABLED       = 21U, ///< Entering Critical section, AutoReset Disabled (status)  
    BOOT_STAGE_SECC_SYSC_REBOOT              = 22U, ///< SYSC initiated reboot (status)  
    BOOT_STAGE_SECC_SYS_INIT                 = 23U, ///< SYSC out of reset (status)  
    BOOT_STAGE_SECC_BOOTROM_XFER             = 24U, ///< SYSC boot ROM transfer started (status)  
    BOOT_STAGE_SECC_MBOX_INIT                = 25U, ///< Initializing SECC Mailbox (status)  
    BOOT_STAGE_SECC_EMERG                    = 26U, ///< SpW emergency mode enabled (status)  
    BOOT_STAGE_SECC_AR0_RNMI_INT             = 27U, ///< halt in RNMI interrupt handler in AR0 (status)  
    BOOT_STAGE_SECC_AR0_MTVEC                = 28U, ///< halt in MTVEC handler in AR0 (status)  
    BOOT_STAGE_SECC_AR0_RNMI_EXCP            = 29U, ///< halt in RNMI exception handler in AR0 (status)  
    BOOT_STAGE_SECC_EARLY_TRAP               = 30U, ///< halt in secc early trap exception handler (status)  
    BOOT_STAGE_SECC_HOLD                     = 31U, ///< enter in halt state, infinite WFI loop (status)  
    BOOT_STAGE_SECC_EXCP_HANDLER             = 32U, ///< Entering exception handler (status)  
    BOOT_STAGE_SECC_RNMI_INT_HANDLER         = 33U, ///< Entering RNMI interrupt handler (status)  
    BOOT_STAGE_SECC_RNMI_EXCP_HANDLER        = 34U, ///< Entering RNMI exception handler (status)  
    BOOT_STAGE_SECC_AR0_SYSC_KEEP_ALIVE      = 35U, ///< ignore sysc keep sysc alive expiry AR0 (status)  
    BOOT_STAGE_SECC_PATCHED_BOOTROM_XFER_COMPLETE = 36U, ///< patched SYSC boot ROM transfer completed (status)  
    BOOT_STAGE_SECC_APPLY_PATCHES            = 37U, ///< pacthes have been applied (status)  
    BOOT_STAGE_SECC_TAMPER_DIGEST_CHECK_FAIL = 38U, ///< Detected a tamper event, digest check (status)  
    BOOT_STAGE_SECC_TAMPER_EVENT_DETECTED    = 39U, ///< Detected a tamper event on MESH or Tamper monitor (status)  
    BOOT_STAGE_SECC_FSBL_ENTRY               = 40U, ///< FSBL Entry (status)  
    BOOT_STAGE_SECC_OTP_PUF_BLANK            = 41U, ///< PUF data in OTP is blank (check)  
    BOOT_STAGE_SECC_SKC_INIT_FAILED          = 42U, ///< SKC init failed (check)  
    BOOT_STAGE_SECC_PQ_INIT_FAILED           = 43U, ///< PQ Core initialization failed (check)  
    BOOT_STAGE_SECC_MBOX_CMD_MISMATCH        = 44U, ///< Mailbox Command mismatch. Command register does not match cmd field (check)  
    BOOT_STAGE_SECC_JTAG_MBOX_CMD_INVALID    = 45U, ///< JTAG Invalid Mailbox command (check)  
    BOOT_STAGE_SECC_KEY_LOAD_FAIL            = 46U, ///< Key Load failed (check)  
    BOOT_STAGE_SECC_EXPORT_FAIL              = 47U, ///< Key Export failed (check)  
    BOOT_STAGE_SECC_SHA3_MISMATCH            = 48U, ///< SHA3 check failed (check)  
    BOOT_STAGE_SECC_SKC_SHA3_MISMATCH        = 49U, ///< SKC SHA3 check failed (check)  
    BOOT_STAGE_SECC_SKC_SHA3_FAILED          = 50U, ///< SKC SHA3 Operation failed (check)  
    BOOT_STAGE_SECC_BITS_INVALID_HDR         = 51U, ///< Invalid image header (check)  
    BOOT_STAGE_SECC_IMG_VALIDATE_ERR         = 52U, ///< Error during image validation (check)  
    BOOT_STAGE_SECC_SIGNATURE_CHECK_FAIL     = 53U, ///< Signature verification failed (check)  
    BOOT_STAGE_SECC_DRBG_INIT_FAILED         = 54U, ///< DRBG failed to generate random value (check)  
    BOOT_STAGE_SECC_ERROR_STACK_OVERFLOW     = 55U, ///< Stack overflow detected in handlers (check)  
    BOOT_STAGE_SECC_AES_KEY_LOAD_FAIL        = 56U, ///< Failed to load AES key (check)  
    BOOT_STAGE_SECC_AES_START_FAIL           = 57U, ///< AES hardware failed to initialize (check)  
    BOOT_STAGE_SECC_ERR_OTP_OPERATION_FAILED = 58U, ///< OTP read/write operation failed (check)  
    BOOT_STAGE_SECC_EC_HASH_CHECK_FAIL       = 59U, ///< EC Pub key hash check failed (check)  
    BOOT_STAGE_SECC_PQ_HASH_CHECK_FAIL       = 60U, ///< PQ Pub key hash check failed (check)  
    BOOT_STAGE_SECC_PQC_ENTROPY_FAIL         = 61U, ///< PQC entropy load failed (check)  
    BOOT_STAGE_SECC_SHA3_DMA_FAIL            = 62U, ///< SHA3 DMA failed (check)  
    BOOT_STAGE_SECC_STACK_OVERFLOW           = 63U, ///< Reserved for future use (exception handler check)  
    BOOT_STAGE_SECC_ARM_AND_FIRE_FAILED      = 64U, ///< an arm and fire register failed (check)  
    BOOT_STAGE_SECC_ASSERT                   = 65U, ///< Software Assert (check)  
    BOOT_STAGE_SECC_DMA_XFER_TIMEOUT         = 66U, ///< DMA block transfer timeout (check)  
    BOOT_STAGE_SECC_DMA_SLAVE_ERROR_FAIL     = 67U, ///< DMA bus slave error transfer failure (check)  
    BOOT_STAGE_SECC_ZSBL_ROM_CHECK_FAILED    = 68U, ///< rom integrity check failed (check)  
    BOOT_STAGE_SECC_DMA_SYSC_PATCH_FAIL      = 69U, ///< DMA patch into SYSC ITIM failed (check)  
    BOOT_STAGE_SECC_PUF_RECONSTRUCT_FAIL     = 70U, ///< PUF reconstruct operation failed (check)  
    BOOT_STAGE_SECC_UNEXPECTED_ERROR         = 71U, ///< Unexpected error (check)  
    BOOT_STAGE_SECC_BOOT_MODE_UNKNOWN        = 72U, ///< Unknown boot mode. Halt firmware (check)  
    BOOT_STAGE_SECC_ROM_CHECK_FAILED         = 73U, ///< SECC ITIM ROM checksum verification failed (check)  
    BOOT_STAGE_SECC_BOOTROM_CHECK_FAILED     = 74U, ///< ZSBL checksum verification failed (check)  
    BOOT_STAGE_SECC_DEV_RST                  = 75U, ///< SECC requested a device reset (check)  
    BOOT_STAGE_SECC_SYSC_MBOX_CMD_INVALID    = 76U, ///< Invalid System Mailbox command (check)  
    BOOT_STAGE_SECC_BOOTROM_XFER_FAIL        = 77U, ///< SYSC boot ROM transfer failed (check)  
    BOOT_STAGE_SECC_PUF_SEED_GEN_FAIL        = 78U, ///< PUF failed to generate random seed (check)  
    BOOT_STAGE_SECC_PUF_INIT_FAILED          = 79U, ///< PUF initialization failed (check)  
    BOOT_STAGE_SECC_PATCH_NOT_COMPATIBLE     = 80U, ///< a secure or system controller patch is not compatible with the rom  
    BOOT_STAGE_SECC_PUF_ENROLL_FAIL          = 81U, ///< PUF enrollment failed (check)  
    BOOT_STAGE_SECC_PATCH_EXCEPTION_HANG_TEST = 82U, ///< used by patch testing to hang when entering the exception handler  
    BOOT_STAGE_SECC_RESERVED_CHECK_3_19      = 83U, ///< Reserved for future use (check)  
    BOOT_STAGE_SECC_BOOT_CNT0                = 84U, ///< Secc Reboot counter bit 0 (boot counter status)  
    BOOT_STAGE_SECC_BOOT_CNT1                = 85U, ///< Secc Reboot counter bit 1 (boot counter status)  
    BOOT_STAGE_SECC_BOOT_CNT2                = 86U, ///< Secc Reboot counter 2 (boot counter status)  
    BOOT_STAGE_SECC_BOOT_STICKY_0            = 87U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 0 (reboot fail cause)  
    BOOT_STAGE_SECC_BOOT_STICKY_1            = 88U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 1 (reboot fail cause)  
    BOOT_STAGE_SECC_BOOT_STICKY_2            = 89U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 2 (reboot fail cause)  
    BOOT_STAGE_SECC_BOOT_STICKY_3            = 90U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 3 (reboot fail cause)  
    BOOT_STAGE_SECC_BOOT_STICKY_4            = 91U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 4 (reboot fail cause)  
    BOOT_STAGE_SECC_BOOT_STICKY_5            = 92U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 5 (reboot fail cause)  
    BOOT_STAGE_SECC_RESET_REASON_STICKY_0    = 93U, ///< SecC ZSBL encoding reset reason from M1 bit 0 (reset reason)  
    BOOT_STAGE_SECC_RESET_REASON_STICKY_1    = 94U, ///< SecC ZSBL encoding reset reason from M1 bit 1 (reset reason)  
    BOOT_STAGE_SECC_RESET_REASON_STICKY_2    = 95U, ///< SecC ZSBL encoding reset reason from M1 bit 2 (reset reason)  
} boot_stage_secc_zsbl_t;

/**
 * @brief return string associated with boot stat code
 * note: we could generate a c file for this.
 *  for now, if we just call this from one .c file it should be fine.
 *  we don't really need the performance or space improvement of an array lookup.
 * 
 * @param[in] code - boot stat enum
 * @return string
 */
static inline const char *boot_stage_secc_zsbl_str( boot_stage_secc_zsbl_t code )
{
    const char *res;
    switch (code)
    {
          // SYSC SpaceWire Access Allowed (status, HW driven)
          case BOOT_STAGE_SECC_SPACEWIRE_ACCESS_ALLOWED:
              res = "BOOT_STAGE_SECC_SPACEWIRE_ACCESS_ALLOWED";
              break;
          // Start of SECC firmware (status)
          case BOOT_STAGE_SECC_ENTRY:
              res = "BOOT_STAGE_SECC_ENTRY";
              break;
          // top power reset (status)
          case BOOT_STAGE_SECC_TOP_POWER:
              res = "BOOT_STAGE_SECC_TOP_POWER";
              break;
          // initialize random (status)
          case BOOT_STAGE_SECC_RANDOM:
              res = "BOOT_STAGE_SECC_RANDOM";
              break;
          // scrub ITIM (status)
          case BOOT_STAGE_SECC_ITIM_INIT:
              res = "BOOT_STAGE_SECC_ITIM_INIT";
              break;
          // start of SECC main() (status)
          case BOOT_STAGE_SECC_MAIN:
              res = "BOOT_STAGE_SECC_MAIN";
              break;
          // watchdog initialization (status)
          case BOOT_STAGE_SECC_WDOG_INIT:
              res = "BOOT_STAGE_SECC_WDOG_INIT";
              break;
          // hardware zeroization of OCR (status)
          case BOOT_STAGE_SECC_OCR_INIT:
              res = "BOOT_STAGE_SECC_OCR_INIT";
              break;
          // SECC DMAC initialization (status)
          case BOOT_STAGE_SECC_DMA_INIT:
              res = "BOOT_STAGE_SECC_DMA_INIT";
              break;
          // Entering Virgin Mode (status)
          case BOOT_STAGE_SECC_MODE_VIRGIN:
              res = "BOOT_STAGE_SECC_MODE_VIRGIN";
              break;
          // Entering Test Mode (status)
          case BOOT_STAGE_SECC_MODE_TEST:
              res = "BOOT_STAGE_SECC_MODE_TEST";
              break;
          // Entering Normal Mode (status)
          case BOOT_STAGE_SECC_MODE_NORMAL:
              res = "BOOT_STAGE_SECC_MODE_NORMAL";
              break;
          // Entering First Boot (status)
          case BOOT_STAGE_SECC_MODE_FIRST:
              res = "BOOT_STAGE_SECC_MODE_FIRST";
              break;
          // SecC First Mutable Code download done (status)
          case BOOT_STAGE_SECC_FMC_FW_DWNLD_COMPLETE:
              res = "BOOT_STAGE_SECC_FMC_FW_DWNLD_COMPLETE";
              break;
          // Initializing the PUF (status)
          case BOOT_STAGE_SECC_PUF_INIT:
              res = "BOOT_STAGE_SECC_PUF_INIT";
              break;
          // Entered First Mutable Code main (status)
          case BOOT_STAGE_SECC_FMC_FW_MAIN:
              res = "BOOT_STAGE_SECC_FMC_FW_MAIN";
              break;
          // used by patch testing to show that a patch is executing
          case BOOT_STAGE_SECC_PATCH_TEST:
              res = "BOOT_STAGE_SECC_PATCH_TEST";
              break;
          // Running SysC LBIST (status)
          case BOOT_STAGE_SECC_SYSC_LBIST:
              res = "BOOT_STAGE_SECC_SYSC_LBIST";
              break;
          // Running SecC LBIST (status)
          case BOOT_STAGE_SECC_LBIST:
              res = "BOOT_STAGE_SECC_LBIST";
              break;
          // Device is in Burn-in mode (status)
          case BOOT_STAGE_SECC_BURNIN_MODE:
              res = "BOOT_STAGE_SECC_BURNIN_MODE";
              break;
          // SYSC boot ROM transfer completed (status)
          case BOOT_STAGE_SECC_BOOTROM_XFER_COMPLETE:
              res = "BOOT_STAGE_SECC_BOOTROM_XFER_COMPLETE";
              break;
          // Entering Critical section, AutoReset Disabled (status)
          case BOOT_STAGE_SECC_AUTORESET_DISABLED:
              res = "BOOT_STAGE_SECC_AUTORESET_DISABLED";
              break;
          // SYSC initiated reboot (status)
          case BOOT_STAGE_SECC_SYSC_REBOOT:
              res = "BOOT_STAGE_SECC_SYSC_REBOOT";
              break;
          // SYSC out of reset (status)
          case BOOT_STAGE_SECC_SYS_INIT:
              res = "BOOT_STAGE_SECC_SYS_INIT";
              break;
          // SYSC boot ROM transfer started (status)
          case BOOT_STAGE_SECC_BOOTROM_XFER:
              res = "BOOT_STAGE_SECC_BOOTROM_XFER";
              break;
          // Initializing SECC Mailbox (status)
          case BOOT_STAGE_SECC_MBOX_INIT:
              res = "BOOT_STAGE_SECC_MBOX_INIT";
              break;
          // SpW emergency mode enabled (status)
          case BOOT_STAGE_SECC_EMERG:
              res = "BOOT_STAGE_SECC_EMERG";
              break;
          // halt in RNMI interrupt handler in AR0 (status)
          case BOOT_STAGE_SECC_AR0_RNMI_INT:
              res = "BOOT_STAGE_SECC_AR0_RNMI_INT";
              break;
          // halt in MTVEC handler in AR0 (status)
          case BOOT_STAGE_SECC_AR0_MTVEC:
              res = "BOOT_STAGE_SECC_AR0_MTVEC";
              break;
          // halt in RNMI exception handler in AR0 (status)
          case BOOT_STAGE_SECC_AR0_RNMI_EXCP:
              res = "BOOT_STAGE_SECC_AR0_RNMI_EXCP";
              break;
          // halt in secc early trap exception handler (status)
          case BOOT_STAGE_SECC_EARLY_TRAP:
              res = "BOOT_STAGE_SECC_EARLY_TRAP";
              break;
          // enter in halt state, infinite WFI loop (status)
          case BOOT_STAGE_SECC_HOLD:
              res = "BOOT_STAGE_SECC_HOLD";
              break;
          // Entering exception handler (status)
          case BOOT_STAGE_SECC_EXCP_HANDLER:
              res = "BOOT_STAGE_SECC_EXCP_HANDLER";
              break;
          // Entering RNMI interrupt handler (status)
          case BOOT_STAGE_SECC_RNMI_INT_HANDLER:
              res = "BOOT_STAGE_SECC_RNMI_INT_HANDLER";
              break;
          // Entering RNMI exception handler (status)
          case BOOT_STAGE_SECC_RNMI_EXCP_HANDLER:
              res = "BOOT_STAGE_SECC_RNMI_EXCP_HANDLER";
              break;
          // ignore sysc keep sysc alive expiry AR0 (status)
          case BOOT_STAGE_SECC_AR0_SYSC_KEEP_ALIVE:
              res = "BOOT_STAGE_SECC_AR0_SYSC_KEEP_ALIVE";
              break;
          // patched SYSC boot ROM transfer completed (status)
          case BOOT_STAGE_SECC_PATCHED_BOOTROM_XFER_COMPLETE:
              res = "BOOT_STAGE_SECC_PATCHED_BOOTROM_XFER_COMPLETE";
              break;
          // pacthes have been applied (status)
          case BOOT_STAGE_SECC_APPLY_PATCHES:
              res = "BOOT_STAGE_SECC_APPLY_PATCHES";
              break;
          // Detected a tamper event, digest check (status)
          case BOOT_STAGE_SECC_TAMPER_DIGEST_CHECK_FAIL:
              res = "BOOT_STAGE_SECC_TAMPER_DIGEST_CHECK_FAIL";
              break;
          // Detected a tamper event on MESH or Tamper monitor (status)
          case BOOT_STAGE_SECC_TAMPER_EVENT_DETECTED:
              res = "BOOT_STAGE_SECC_TAMPER_EVENT_DETECTED";
              break;
          // FSBL Entry (status)
          case BOOT_STAGE_SECC_FSBL_ENTRY:
              res = "BOOT_STAGE_SECC_FSBL_ENTRY";
              break;
          // PUF data in OTP is blank (check)
          case BOOT_STAGE_SECC_OTP_PUF_BLANK:
              res = "BOOT_STAGE_SECC_OTP_PUF_BLANK";
              break;
          // SKC init failed (check)
          case BOOT_STAGE_SECC_SKC_INIT_FAILED:
              res = "BOOT_STAGE_SECC_SKC_INIT_FAILED";
              break;
          // PQ Core initialization failed (check)
          case BOOT_STAGE_SECC_PQ_INIT_FAILED:
              res = "BOOT_STAGE_SECC_PQ_INIT_FAILED";
              break;
          // Mailbox Command mismatch. Command register does not match cmd field (check)
          case BOOT_STAGE_SECC_MBOX_CMD_MISMATCH:
              res = "BOOT_STAGE_SECC_MBOX_CMD_MISMATCH";
              break;
          // JTAG Invalid Mailbox command (check)
          case BOOT_STAGE_SECC_JTAG_MBOX_CMD_INVALID:
              res = "BOOT_STAGE_SECC_JTAG_MBOX_CMD_INVALID";
              break;
          // Key Load failed (check)
          case BOOT_STAGE_SECC_KEY_LOAD_FAIL:
              res = "BOOT_STAGE_SECC_KEY_LOAD_FAIL";
              break;
          // Key Export failed (check)
          case BOOT_STAGE_SECC_EXPORT_FAIL:
              res = "BOOT_STAGE_SECC_EXPORT_FAIL";
              break;
          // SHA3 check failed (check)
          case BOOT_STAGE_SECC_SHA3_MISMATCH:
              res = "BOOT_STAGE_SECC_SHA3_MISMATCH";
              break;
          // SKC SHA3 check failed (check)
          case BOOT_STAGE_SECC_SKC_SHA3_MISMATCH:
              res = "BOOT_STAGE_SECC_SKC_SHA3_MISMATCH";
              break;
          // SKC SHA3 Operation failed (check)
          case BOOT_STAGE_SECC_SKC_SHA3_FAILED:
              res = "BOOT_STAGE_SECC_SKC_SHA3_FAILED";
              break;
          // Invalid image header (check)
          case BOOT_STAGE_SECC_BITS_INVALID_HDR:
              res = "BOOT_STAGE_SECC_BITS_INVALID_HDR";
              break;
          // Error during image validation (check)
          case BOOT_STAGE_SECC_IMG_VALIDATE_ERR:
              res = "BOOT_STAGE_SECC_IMG_VALIDATE_ERR";
              break;
          // Signature verification failed (check)
          case BOOT_STAGE_SECC_SIGNATURE_CHECK_FAIL:
              res = "BOOT_STAGE_SECC_SIGNATURE_CHECK_FAIL";
              break;
          // DRBG failed to generate random value (check)
          case BOOT_STAGE_SECC_DRBG_INIT_FAILED:
              res = "BOOT_STAGE_SECC_DRBG_INIT_FAILED";
              break;
          // Stack overflow detected in handlers (check)
          case BOOT_STAGE_SECC_ERROR_STACK_OVERFLOW:
              res = "BOOT_STAGE_SECC_ERROR_STACK_OVERFLOW";
              break;
          // Failed to load AES key (check)
          case BOOT_STAGE_SECC_AES_KEY_LOAD_FAIL:
              res = "BOOT_STAGE_SECC_AES_KEY_LOAD_FAIL";
              break;
          // AES hardware failed to initialize (check)
          case BOOT_STAGE_SECC_AES_START_FAIL:
              res = "BOOT_STAGE_SECC_AES_START_FAIL";
              break;
          // OTP read/write operation failed (check)
          case BOOT_STAGE_SECC_ERR_OTP_OPERATION_FAILED:
              res = "BOOT_STAGE_SECC_ERR_OTP_OPERATION_FAILED";
              break;
          // EC Pub key hash check failed (check)
          case BOOT_STAGE_SECC_EC_HASH_CHECK_FAIL:
              res = "BOOT_STAGE_SECC_EC_HASH_CHECK_FAIL";
              break;
          // PQ Pub key hash check failed (check)
          case BOOT_STAGE_SECC_PQ_HASH_CHECK_FAIL:
              res = "BOOT_STAGE_SECC_PQ_HASH_CHECK_FAIL";
              break;
          // PQC entropy load failed (check)
          case BOOT_STAGE_SECC_PQC_ENTROPY_FAIL:
              res = "BOOT_STAGE_SECC_PQC_ENTROPY_FAIL";
              break;
          // SHA3 DMA failed (check)
          case BOOT_STAGE_SECC_SHA3_DMA_FAIL:
              res = "BOOT_STAGE_SECC_SHA3_DMA_FAIL";
              break;
          // Reserved for future use (exception handler check)
          case BOOT_STAGE_SECC_STACK_OVERFLOW:
              res = "BOOT_STAGE_SECC_STACK_OVERFLOW";
              break;
          // an arm and fire register failed (check)
          case BOOT_STAGE_SECC_ARM_AND_FIRE_FAILED:
              res = "BOOT_STAGE_SECC_ARM_AND_FIRE_FAILED";
              break;
          // Software Assert (check)
          case BOOT_STAGE_SECC_ASSERT:
              res = "BOOT_STAGE_SECC_ASSERT";
              break;
          // DMA block transfer timeout (check)
          case BOOT_STAGE_SECC_DMA_XFER_TIMEOUT:
              res = "BOOT_STAGE_SECC_DMA_XFER_TIMEOUT";
              break;
          // DMA bus slave error transfer failure (check)
          case BOOT_STAGE_SECC_DMA_SLAVE_ERROR_FAIL:
              res = "BOOT_STAGE_SECC_DMA_SLAVE_ERROR_FAIL";
              break;
          // rom integrity check failed (check)
          case BOOT_STAGE_SECC_ZSBL_ROM_CHECK_FAILED:
              res = "BOOT_STAGE_SECC_ZSBL_ROM_CHECK_FAILED";
              break;
          // DMA patch into SYSC ITIM failed (check)
          case BOOT_STAGE_SECC_DMA_SYSC_PATCH_FAIL:
              res = "BOOT_STAGE_SECC_DMA_SYSC_PATCH_FAIL";
              break;
          // PUF reconstruct operation failed (check)
          case BOOT_STAGE_SECC_PUF_RECONSTRUCT_FAIL:
              res = "BOOT_STAGE_SECC_PUF_RECONSTRUCT_FAIL";
              break;
          // Unexpected error (check)
          case BOOT_STAGE_SECC_UNEXPECTED_ERROR:
              res = "BOOT_STAGE_SECC_UNEXPECTED_ERROR";
              break;
          // Unknown boot mode. Halt firmware (check)
          case BOOT_STAGE_SECC_BOOT_MODE_UNKNOWN:
              res = "BOOT_STAGE_SECC_BOOT_MODE_UNKNOWN";
              break;
          // SECC ITIM ROM checksum verification failed (check)
          case BOOT_STAGE_SECC_ROM_CHECK_FAILED:
              res = "BOOT_STAGE_SECC_ROM_CHECK_FAILED";
              break;
          // ZSBL checksum verification failed (check)
          case BOOT_STAGE_SECC_BOOTROM_CHECK_FAILED:
              res = "BOOT_STAGE_SECC_BOOTROM_CHECK_FAILED";
              break;
          // SECC requested a device reset (check)
          case BOOT_STAGE_SECC_DEV_RST:
              res = "BOOT_STAGE_SECC_DEV_RST";
              break;
          // Invalid System Mailbox command (check)
          case BOOT_STAGE_SECC_SYSC_MBOX_CMD_INVALID:
              res = "BOOT_STAGE_SECC_SYSC_MBOX_CMD_INVALID";
              break;
          // SYSC boot ROM transfer failed (check)
          case BOOT_STAGE_SECC_BOOTROM_XFER_FAIL:
              res = "BOOT_STAGE_SECC_BOOTROM_XFER_FAIL";
              break;
          // PUF failed to generate random seed (check)
          case BOOT_STAGE_SECC_PUF_SEED_GEN_FAIL:
              res = "BOOT_STAGE_SECC_PUF_SEED_GEN_FAIL";
              break;
          // PUF initialization failed (check)
          case BOOT_STAGE_SECC_PUF_INIT_FAILED:
              res = "BOOT_STAGE_SECC_PUF_INIT_FAILED";
              break;
          // a secure or system controller patch is not compatible with the rom
          case BOOT_STAGE_SECC_PATCH_NOT_COMPATIBLE:
              res = "BOOT_STAGE_SECC_PATCH_NOT_COMPATIBLE";
              break;
          // PUF enrollment failed (check)
          case BOOT_STAGE_SECC_PUF_ENROLL_FAIL:
              res = "BOOT_STAGE_SECC_PUF_ENROLL_FAIL";
              break;
          // used by patch testing to hang when entering the exception handler
          case BOOT_STAGE_SECC_PATCH_EXCEPTION_HANG_TEST:
              res = "BOOT_STAGE_SECC_PATCH_EXCEPTION_HANG_TEST";
              break;
          // Reserved for future use (check)
          case BOOT_STAGE_SECC_RESERVED_CHECK_3_19:
              res = "BOOT_STAGE_SECC_RESERVED_CHECK_3_19";
              break;
          // Secc Reboot counter bit 0 (boot counter status)
          case BOOT_STAGE_SECC_BOOT_CNT0:
              res = "BOOT_STAGE_SECC_BOOT_CNT0";
              break;
          // Secc Reboot counter bit 1 (boot counter status)
          case BOOT_STAGE_SECC_BOOT_CNT1:
              res = "BOOT_STAGE_SECC_BOOT_CNT1";
              break;
          // Secc Reboot counter 2 (boot counter status)
          case BOOT_STAGE_SECC_BOOT_CNT2:
              res = "BOOT_STAGE_SECC_BOOT_CNT2";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 0 (reboot fail cause)
          case BOOT_STAGE_SECC_BOOT_STICKY_0:
              res = "BOOT_STAGE_SECC_BOOT_STICKY_0";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 1 (reboot fail cause)
          case BOOT_STAGE_SECC_BOOT_STICKY_1:
              res = "BOOT_STAGE_SECC_BOOT_STICKY_1";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 2 (reboot fail cause)
          case BOOT_STAGE_SECC_BOOT_STICKY_2:
              res = "BOOT_STAGE_SECC_BOOT_STICKY_2";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 3 (reboot fail cause)
          case BOOT_STAGE_SECC_BOOT_STICKY_3:
              res = "BOOT_STAGE_SECC_BOOT_STICKY_3";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 4 (reboot fail cause)
          case BOOT_STAGE_SECC_BOOT_STICKY_4:
              res = "BOOT_STAGE_SECC_BOOT_STICKY_4";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 5 (reboot fail cause)
          case BOOT_STAGE_SECC_BOOT_STICKY_5:
              res = "BOOT_STAGE_SECC_BOOT_STICKY_5";
              break;
          // SecC ZSBL encoding reset reason from M1 bit 0 (reset reason)
          case BOOT_STAGE_SECC_RESET_REASON_STICKY_0:
              res = "BOOT_STAGE_SECC_RESET_REASON_STICKY_0";
              break;
          // SecC ZSBL encoding reset reason from M1 bit 1 (reset reason)
          case BOOT_STAGE_SECC_RESET_REASON_STICKY_1:
              res = "BOOT_STAGE_SECC_RESET_REASON_STICKY_1";
              break;
          // SecC ZSBL encoding reset reason from M1 bit 2 (reset reason)
          case BOOT_STAGE_SECC_RESET_REASON_STICKY_2:
              res = "BOOT_STAGE_SECC_RESET_REASON_STICKY_2";
              break;
          default:
              res = "unknown boot_stage_secc_zsbl_t";
              break;

    }
    return res;
}
#endif
#endif // __ASSEMBLER__
