/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * SYSC_ZSBL BOOT_STAT defines
 */

 /*--------------------.
 | auto-generated file |
 +--------------------*/

#ifdef __ASSEMBLER__
// #defines are for when included by assembler .S files.
#define BOOT_STAGE_SYSC_BOOT_IMAGE_ID_CHOSEN      0U ///< SysC Image chosen (status)  
#define BOOT_STAGE_SYSC_ENTRY                     1U ///< Start of SYSC firmware (status)  
#define BOOT_STAGE_SYSC_MAIN                      2U ///< start of ZSBL main (status)  
#define BOOT_STAGE_SYSC_WDOG_INIT                 3U ///< watchdog initialization (status)  
#define BOOT_STAGE_SYSC_OCR_CLEAR                 4U ///< SYSC OCR cleared (status)  
#define BOOT_STAGE_SYSC_MBOX_INIT                 5U ///< SYSC Mailbox initialized (status)  
#define BOOT_STAGE_SYSC_FLASH_INIT                6U ///< SYSC flash driver initialized. xSPI or pFlash (status)  
#define BOOT_STAGE_SYSC_DMA_INIT                  7U ///< SYSC DMAC initialization (status)  
#define BOOT_STAGE_SYSC_HEADER_VERIFIED           8U ///< Flash image header verified (status)  
#define BOOT_STAGE_SYSC_DTB_VERIFIED              9U ///< DTB verified (status)  
#define BOOT_STAGE_SYSC_IMAGE_VERIFIED           10U ///< Flash image verified (status)  
#define BOOT_STAGE_SYSC_EMERGENCY_BOOT           11U ///< Emergency Boot Required (status)  
#define BOOT_STAGE_SYSC_ZSBL_BOOT_CONFIG_PIN_FAIL 12U ///< BOOT_CONFIG[4:3] input pin value 0x3 not valid selection (status)  
#define BOOT_STAGE_SYSC_BOOT_NO_PLAN_FAIL        13U ///< ZSBL exceeded start attempts without establishing a plan (status)  
#define BOOT_STAGE_SYSC_BOOT_OTP_UNBOUNDED_FAIL  14U ///< ZSBL exceeded image booting attempts without a successful FSBL start (status)  
#define BOOT_STAGE_SYSC_LAST_IMAGE               15U ///< ZSBL Boot attempted all images till policy specified an emergency mode request (status)  
#define BOOT_STAGE_SYSC_RTEMS_JUMP               16U ///< Entering RTEMS program (status)  
#define BOOT_STAGE_SYSC_EARLY_TRAP               17U ///< Entering early trap handler (status)  
#define BOOT_STAGE_SYSC_EXCP_HANDLER             18U ///< Entering exception handler (status)  
#define BOOT_STAGE_SYSC_RNMI_INT_HANDLER         19U ///< Entering RNMI interrupt handler (status)  
#define BOOT_STAGE_SYSC_RNMI_EXCP_HANDLER        20U ///< Entering RNMI exception handler (status)  
#define BOOT_STAGE_SYSC_HOLD                     21U ///< SYSC is in HALT, infinite WFI loop (status)  
#define BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_22 22U ///< Reserved for future use (status or check)  
#define BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_23 23U ///< Reserved for future use (cstatus or checkheck)  
#define BOOT_STAGE_SYSC_MBOX_INIT_FAIL           24U ///< SYSC Mailbox initialization failed (check, device reset)  
#define BOOT_STAGE_SYSC_FLASH_INIT_FAIL          25U ///< SYSC flash driver initialization failed (check, device reset)  
#define BOOT_STAGE_SYSC_FLASH_READ_FAIL          26U ///< Failed to read the flash device (check, device reset)  
#define BOOT_STAGE_SYSC_HEADER_VERIFY_FAIL       27U ///< Flash image header verification failed (check, device reset)  
#define BOOT_STAGE_SYSC_DTB_SIZE_TOO_LARGE       28U ///< The size of the DTB files is too large (check, device reset)  
#define BOOT_STAGE_SYSC_FLASH_READ_DTB_FAIL      29U ///< Failed to read DTB file from flash (check, device reset)  
#define BOOT_STAGE_SYSC_DTB_VERIFY_FAIL          30U ///< DTB verification failed (check, device reset)  
#define BOOT_STAGE_SYSC_FLASH_READ_FSBL_FAIL     31U ///< Failed to read FSBL file from Flash (check,  system soft reset)  
#define BOOT_STAGE_SYSC_ARM_AND_FIRE_FAILED      64U ///< an arm and fire register failed (check, device reset)  
#define BOOT_STAGE_SYSC_ASSERT                   65U ///< Software Assert (check, device reset)  
#define BOOT_STAGE_SYSC_DMA_XFER_TIMEOUT         66U ///< DMA block transfer timeout (check, device reset)  
#define BOOT_STAGE_SYSC_DMA_SLAVE_ERROR_FAIL     67U ///< DMA bus slave error transfer failure (check, device reset)  
#define BOOT_STAGE_SYSC_ACSU_INIT_FAILED         68U ///< the programming of a clock (ACSU) failed (check, device reset)  
#define BOOT_STAGE_SYSC_STACK_OVERFLOW           69U ///< Stack overflow detected in handlers (check, device reset)  
#define BOOT_STAGE_SYSC_UNEXPECTED_ERROR         70U ///< Unexpected error(check, device reset)  
#define BOOT_STAGE_SYSC_DMA_XFER_HEADER_FAILED   71U ///< DMA transfer of flash header failed (check, system soft reset)  
#define BOOT_STAGE_SYSC_DMA_XFER_IMAGE_FAILED    72U ///< DMA transfer of flash image failed (check, device reset)  
#define BOOT_STAGE_SYSC_SPI_POLL_TIMEOUT         73U ///< timeout polling SPI status (check,  system soft reset)  
#define BOOT_STAGE_SYSC_SPI_FLASH_DISCOVERY_FAIL 74U ///< SPI Flash Discovery operation failed (check, device reset)  
#define BOOT_STAGE_SYSC_SPI_INIT_FAIL            75U ///< SPI Flash Initialization Fail (check, system soft reset)  
#define BOOT_STAGE_SYSC_SPI_ACTIVE_FAIL          76U ///< SPI Flash Active Fail (check, system soft reset)  
#define BOOT_STAGE_SYSC_FSBL_SIZE_TOO_LARGE      77U ///< The size of the FSBL file is too large (check,  system soft reset)  
#define BOOT_STAGE_SYSC_IMAGE_VERIFY_FAIL        78U ///< FSBL verification failed (check, device reset)  
#define BOOT_STAGE_SYSC_MBOX_SEND_ERROR          79U ///< Failed to send a Mailbox command (check, device reset)  
#define BOOT_STAGE_SYSC_MBOX_RESP_MISMATCH       80U ///< Mailbox Command mismatch. Command register does not match cmd field (check, device reset)  
#define BOOT_STAGE_SYSC_MBOX_RECV_ERROR          81U ///< Failed to read Mailbox response (check, device reset)  
#define BOOT_STAGE_SYSC_BOOTCFG_GET_ERROR        82U ///< Error fetching Boot config (check, device reset)  
#define BOOT_STAGE_SYSC_MBOX_RECV_TIMEOUT        83U ///< Failed to receive a response from SecC (check, device reset)  
#define BOOT_STAGE_SYSC_BOOT_CNT0                84U ///< Secc Reboot counter bit 0 (boot counter status)  
#define BOOT_STAGE_SYSC_BOOT_CNT1                85U ///< Secc Reboot counter bit 1 (boot counter status)  
#define BOOT_STAGE_SYSC_BOOT_CNT2                86U ///< Secc Reboot counter 2 (boot counter status)  
#define BOOT_STAGE_SYSC_BOOT_STICKY_0            87U ///< SecC ZSBL encoding reboot failure cause from M1 bit 0 (reboot fail cause)  
#define BOOT_STAGE_SYSC_BOOT_STICKY_1            88U ///< SecC ZSBL encoding reboot failure cause from M1 bit 1 (reboot fail cause)  
#define BOOT_STAGE_SYSC_BOOT_STICKY_2            89U ///< SecC ZSBL encoding reboot failure cause from M1 bit 2 (reboot fail cause)  
#define BOOT_STAGE_SYSC_BOOT_STICKY_3            90U ///< SecC ZSBL encoding reboot failure cause from M1 bit 3 (reboot fail cause)  
#define BOOT_STAGE_SYSC_BOOT_STICKY_4            91U ///< SecC ZSBL encoding reboot failure cause from M1 bit 4 (reboot fail cause)  
#define BOOT_STAGE_SYSC_BOOT_STICKY_5            92U ///< SecC ZSBL encoding reboot failure cause from M1 bit 5 (reboot fail cause)  
#define BOOT_STAGE_SYSC_RESET_REASON_STICKY_0    93U ///< SecC ZSBL encoding reset reason from M1 bit 0 (reset reason)  
#define BOOT_STAGE_SYSC_RESET_REASON_STICKY_1    94U ///< SecC ZSBL encoding reset reason from M1 bit 1 (reset reason)  
#define BOOT_STAGE_SYSC_RESET_REASON_STICKY_2    95U ///< SecC ZSBL encoding reset reason from M1 bit 2 (reset reason)  
#else // __ASSEMBLER__

#ifndef BOOT_STAT_GEN_SYSC_ZSBL_H
#define BOOT_STAT_GEN_SYSC_ZSBL_H

/// Definitions of System Controller ZSBL boot stages
typedef enum boot_stage_sysc_zsbl_t
{
    BOOT_STAGE_SYSC_BOOT_IMAGE_ID_CHOSEN     =  0U, ///< SysC Image chosen (status)  
    BOOT_STAGE_SYSC_ENTRY                    =  1U, ///< Start of SYSC firmware (status)  
    BOOT_STAGE_SYSC_MAIN                     =  2U, ///< start of ZSBL main (status)  
    BOOT_STAGE_SYSC_WDOG_INIT                =  3U, ///< watchdog initialization (status)  
    BOOT_STAGE_SYSC_OCR_CLEAR                =  4U, ///< SYSC OCR cleared (status)  
    BOOT_STAGE_SYSC_MBOX_INIT                =  5U, ///< SYSC Mailbox initialized (status)  
    BOOT_STAGE_SYSC_FLASH_INIT               =  6U, ///< SYSC flash driver initialized. xSPI or pFlash (status)  
    BOOT_STAGE_SYSC_DMA_INIT                 =  7U, ///< SYSC DMAC initialization (status)  
    BOOT_STAGE_SYSC_HEADER_VERIFIED          =  8U, ///< Flash image header verified (status)  
    BOOT_STAGE_SYSC_DTB_VERIFIED             =  9U, ///< DTB verified (status)  
    BOOT_STAGE_SYSC_IMAGE_VERIFIED           = 10U, ///< Flash image verified (status)  
    BOOT_STAGE_SYSC_EMERGENCY_BOOT           = 11U, ///< Emergency Boot Required (status)  
    BOOT_STAGE_SYSC_ZSBL_BOOT_CONFIG_PIN_FAIL = 12U, ///< BOOT_CONFIG[4:3] input pin value 0x3 not valid selection (status)  
    BOOT_STAGE_SYSC_BOOT_NO_PLAN_FAIL        = 13U, ///< ZSBL exceeded start attempts without establishing a plan (status)  
    BOOT_STAGE_SYSC_BOOT_OTP_UNBOUNDED_FAIL  = 14U, ///< ZSBL exceeded image booting attempts without a successful FSBL start (status)  
    BOOT_STAGE_SYSC_LAST_IMAGE               = 15U, ///< ZSBL Boot attempted all images till policy specified an emergency mode request (status)  
    BOOT_STAGE_SYSC_RTEMS_JUMP               = 16U, ///< Entering RTEMS program (status)  
    BOOT_STAGE_SYSC_EARLY_TRAP               = 17U, ///< Entering early trap handler (status)  
    BOOT_STAGE_SYSC_EXCP_HANDLER             = 18U, ///< Entering exception handler (status)  
    BOOT_STAGE_SYSC_RNMI_INT_HANDLER         = 19U, ///< Entering RNMI interrupt handler (status)  
    BOOT_STAGE_SYSC_RNMI_EXCP_HANDLER        = 20U, ///< Entering RNMI exception handler (status)  
    BOOT_STAGE_SYSC_HOLD                     = 21U, ///< SYSC is in HALT, infinite WFI loop (status)  
    BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_22 = 22U, ///< Reserved for future use (status or check)  
    BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_23 = 23U, ///< Reserved for future use (cstatus or checkheck)  
    BOOT_STAGE_SYSC_MBOX_INIT_FAIL           = 24U, ///< SYSC Mailbox initialization failed (check, device reset)  
    BOOT_STAGE_SYSC_FLASH_INIT_FAIL          = 25U, ///< SYSC flash driver initialization failed (check, device reset)  
    BOOT_STAGE_SYSC_FLASH_READ_FAIL          = 26U, ///< Failed to read the flash device (check, device reset)  
    BOOT_STAGE_SYSC_HEADER_VERIFY_FAIL       = 27U, ///< Flash image header verification failed (check, device reset)  
    BOOT_STAGE_SYSC_DTB_SIZE_TOO_LARGE       = 28U, ///< The size of the DTB files is too large (check, device reset)  
    BOOT_STAGE_SYSC_FLASH_READ_DTB_FAIL      = 29U, ///< Failed to read DTB file from flash (check, device reset)  
    BOOT_STAGE_SYSC_DTB_VERIFY_FAIL          = 30U, ///< DTB verification failed (check, device reset)  
    BOOT_STAGE_SYSC_FLASH_READ_FSBL_FAIL     = 31U, ///< Failed to read FSBL file from Flash (check,  system soft reset)  
    BOOT_STAGE_SYSC_ARM_AND_FIRE_FAILED      = 64U, ///< an arm and fire register failed (check, device reset)  
    BOOT_STAGE_SYSC_ASSERT                   = 65U, ///< Software Assert (check, device reset)  
    BOOT_STAGE_SYSC_DMA_XFER_TIMEOUT         = 66U, ///< DMA block transfer timeout (check, device reset)  
    BOOT_STAGE_SYSC_DMA_SLAVE_ERROR_FAIL     = 67U, ///< DMA bus slave error transfer failure (check, device reset)  
    BOOT_STAGE_SYSC_ACSU_INIT_FAILED         = 68U, ///< the programming of a clock (ACSU) failed (check, device reset)  
    BOOT_STAGE_SYSC_STACK_OVERFLOW           = 69U, ///< Stack overflow detected in handlers (check, device reset)  
    BOOT_STAGE_SYSC_UNEXPECTED_ERROR         = 70U, ///< Unexpected error(check, device reset)  
    BOOT_STAGE_SYSC_DMA_XFER_HEADER_FAILED   = 71U, ///< DMA transfer of flash header failed (check, system soft reset)  
    BOOT_STAGE_SYSC_DMA_XFER_IMAGE_FAILED    = 72U, ///< DMA transfer of flash image failed (check, device reset)  
    BOOT_STAGE_SYSC_SPI_POLL_TIMEOUT         = 73U, ///< timeout polling SPI status (check,  system soft reset)  
    BOOT_STAGE_SYSC_SPI_FLASH_DISCOVERY_FAIL = 74U, ///< SPI Flash Discovery operation failed (check, device reset)  
    BOOT_STAGE_SYSC_SPI_INIT_FAIL            = 75U, ///< SPI Flash Initialization Fail (check, system soft reset)  
    BOOT_STAGE_SYSC_SPI_ACTIVE_FAIL          = 76U, ///< SPI Flash Active Fail (check, system soft reset)  
    BOOT_STAGE_SYSC_FSBL_SIZE_TOO_LARGE      = 77U, ///< The size of the FSBL file is too large (check,  system soft reset)  
    BOOT_STAGE_SYSC_IMAGE_VERIFY_FAIL        = 78U, ///< FSBL verification failed (check, device reset)  
    BOOT_STAGE_SYSC_MBOX_SEND_ERROR          = 79U, ///< Failed to send a Mailbox command (check, device reset)  
    BOOT_STAGE_SYSC_MBOX_RESP_MISMATCH       = 80U, ///< Mailbox Command mismatch. Command register does not match cmd field (check, device reset)  
    BOOT_STAGE_SYSC_MBOX_RECV_ERROR          = 81U, ///< Failed to read Mailbox response (check, device reset)  
    BOOT_STAGE_SYSC_BOOTCFG_GET_ERROR        = 82U, ///< Error fetching Boot config (check, device reset)  
    BOOT_STAGE_SYSC_MBOX_RECV_TIMEOUT        = 83U, ///< Failed to receive a response from SecC (check, device reset)  
    BOOT_STAGE_SYSC_BOOT_CNT0                = 84U, ///< Secc Reboot counter bit 0 (boot counter status)  
    BOOT_STAGE_SYSC_BOOT_CNT1                = 85U, ///< Secc Reboot counter bit 1 (boot counter status)  
    BOOT_STAGE_SYSC_BOOT_CNT2                = 86U, ///< Secc Reboot counter 2 (boot counter status)  
    BOOT_STAGE_SYSC_BOOT_STICKY_0            = 87U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 0 (reboot fail cause)  
    BOOT_STAGE_SYSC_BOOT_STICKY_1            = 88U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 1 (reboot fail cause)  
    BOOT_STAGE_SYSC_BOOT_STICKY_2            = 89U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 2 (reboot fail cause)  
    BOOT_STAGE_SYSC_BOOT_STICKY_3            = 90U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 3 (reboot fail cause)  
    BOOT_STAGE_SYSC_BOOT_STICKY_4            = 91U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 4 (reboot fail cause)  
    BOOT_STAGE_SYSC_BOOT_STICKY_5            = 92U, ///< SecC ZSBL encoding reboot failure cause from M1 bit 5 (reboot fail cause)  
    BOOT_STAGE_SYSC_RESET_REASON_STICKY_0    = 93U, ///< SecC ZSBL encoding reset reason from M1 bit 0 (reset reason)  
    BOOT_STAGE_SYSC_RESET_REASON_STICKY_1    = 94U, ///< SecC ZSBL encoding reset reason from M1 bit 1 (reset reason)  
    BOOT_STAGE_SYSC_RESET_REASON_STICKY_2    = 95U, ///< SecC ZSBL encoding reset reason from M1 bit 2 (reset reason)  
} boot_stage_sysc_zsbl_t;

/**
 * @brief return string associated with boot stat code
 * note: we could generate a c file for this.
 *  for now, if we just call this from one .c file it should be fine.
 *  we don't really need the performance or space improvement of an array lookup.
 * 
 * @param[in] code - boot stat enum
 * @return string
 */
static inline const char *boot_stage_sysc_zsbl_str( boot_stage_sysc_zsbl_t code )
{
    const char *res;
    switch (code)
    {
          // SysC Image chosen (status)
          case BOOT_STAGE_SYSC_BOOT_IMAGE_ID_CHOSEN:
              res = "BOOT_STAGE_SYSC_BOOT_IMAGE_ID_CHOSEN";
              break;
          // Start of SYSC firmware (status)
          case BOOT_STAGE_SYSC_ENTRY:
              res = "BOOT_STAGE_SYSC_ENTRY";
              break;
          // start of ZSBL main (status)
          case BOOT_STAGE_SYSC_MAIN:
              res = "BOOT_STAGE_SYSC_MAIN";
              break;
          // watchdog initialization (status)
          case BOOT_STAGE_SYSC_WDOG_INIT:
              res = "BOOT_STAGE_SYSC_WDOG_INIT";
              break;
          // SYSC OCR cleared (status)
          case BOOT_STAGE_SYSC_OCR_CLEAR:
              res = "BOOT_STAGE_SYSC_OCR_CLEAR";
              break;
          // SYSC Mailbox initialized (status)
          case BOOT_STAGE_SYSC_MBOX_INIT:
              res = "BOOT_STAGE_SYSC_MBOX_INIT";
              break;
          // SYSC flash driver initialized. xSPI or pFlash (status)
          case BOOT_STAGE_SYSC_FLASH_INIT:
              res = "BOOT_STAGE_SYSC_FLASH_INIT";
              break;
          // SYSC DMAC initialization (status)
          case BOOT_STAGE_SYSC_DMA_INIT:
              res = "BOOT_STAGE_SYSC_DMA_INIT";
              break;
          // Flash image header verified (status)
          case BOOT_STAGE_SYSC_HEADER_VERIFIED:
              res = "BOOT_STAGE_SYSC_HEADER_VERIFIED";
              break;
          // DTB verified (status)
          case BOOT_STAGE_SYSC_DTB_VERIFIED:
              res = "BOOT_STAGE_SYSC_DTB_VERIFIED";
              break;
          // Flash image verified (status)
          case BOOT_STAGE_SYSC_IMAGE_VERIFIED:
              res = "BOOT_STAGE_SYSC_IMAGE_VERIFIED";
              break;
          // Emergency Boot Required (status)
          case BOOT_STAGE_SYSC_EMERGENCY_BOOT:
              res = "BOOT_STAGE_SYSC_EMERGENCY_BOOT";
              break;
          // BOOT_CONFIG[4:3] input pin value 0x3 not valid selection (status)
          case BOOT_STAGE_SYSC_ZSBL_BOOT_CONFIG_PIN_FAIL:
              res = "BOOT_STAGE_SYSC_ZSBL_BOOT_CONFIG_PIN_FAIL";
              break;
          // ZSBL exceeded start attempts without establishing a plan (status)
          case BOOT_STAGE_SYSC_BOOT_NO_PLAN_FAIL:
              res = "BOOT_STAGE_SYSC_BOOT_NO_PLAN_FAIL";
              break;
          // ZSBL exceeded image booting attempts without a successful FSBL start (status)
          case BOOT_STAGE_SYSC_BOOT_OTP_UNBOUNDED_FAIL:
              res = "BOOT_STAGE_SYSC_BOOT_OTP_UNBOUNDED_FAIL";
              break;
          // ZSBL Boot attempted all images till policy specified an emergency mode request (status)
          case BOOT_STAGE_SYSC_LAST_IMAGE:
              res = "BOOT_STAGE_SYSC_LAST_IMAGE";
              break;
          // Entering RTEMS program (status)
          case BOOT_STAGE_SYSC_RTEMS_JUMP:
              res = "BOOT_STAGE_SYSC_RTEMS_JUMP";
              break;
          // Entering early trap handler (status)
          case BOOT_STAGE_SYSC_EARLY_TRAP:
              res = "BOOT_STAGE_SYSC_EARLY_TRAP";
              break;
          // Entering exception handler (status)
          case BOOT_STAGE_SYSC_EXCP_HANDLER:
              res = "BOOT_STAGE_SYSC_EXCP_HANDLER";
              break;
          // Entering RNMI interrupt handler (status)
          case BOOT_STAGE_SYSC_RNMI_INT_HANDLER:
              res = "BOOT_STAGE_SYSC_RNMI_INT_HANDLER";
              break;
          // Entering RNMI exception handler (status)
          case BOOT_STAGE_SYSC_RNMI_EXCP_HANDLER:
              res = "BOOT_STAGE_SYSC_RNMI_EXCP_HANDLER";
              break;
          // SYSC is in HALT, infinite WFI loop (status)
          case BOOT_STAGE_SYSC_HOLD:
              res = "BOOT_STAGE_SYSC_HOLD";
              break;
          // Reserved for future use (status or check)
          case BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_22:
              res = "BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_22";
              break;
          // Reserved for future use (cstatus or checkheck)
          case BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_23:
              res = "BOOT_STAGE_SYSC_RESERVED_STATUS_CHECK_4_23";
              break;
          // SYSC Mailbox initialization failed (check, device reset)
          case BOOT_STAGE_SYSC_MBOX_INIT_FAIL:
              res = "BOOT_STAGE_SYSC_MBOX_INIT_FAIL";
              break;
          // SYSC flash driver initialization failed (check, device reset)
          case BOOT_STAGE_SYSC_FLASH_INIT_FAIL:
              res = "BOOT_STAGE_SYSC_FLASH_INIT_FAIL";
              break;
          // Failed to read the flash device (check, device reset)
          case BOOT_STAGE_SYSC_FLASH_READ_FAIL:
              res = "BOOT_STAGE_SYSC_FLASH_READ_FAIL";
              break;
          // Flash image header verification failed (check, device reset)
          case BOOT_STAGE_SYSC_HEADER_VERIFY_FAIL:
              res = "BOOT_STAGE_SYSC_HEADER_VERIFY_FAIL";
              break;
          // The size of the DTB files is too large (check, device reset)
          case BOOT_STAGE_SYSC_DTB_SIZE_TOO_LARGE:
              res = "BOOT_STAGE_SYSC_DTB_SIZE_TOO_LARGE";
              break;
          // Failed to read DTB file from flash (check, device reset)
          case BOOT_STAGE_SYSC_FLASH_READ_DTB_FAIL:
              res = "BOOT_STAGE_SYSC_FLASH_READ_DTB_FAIL";
              break;
          // DTB verification failed (check, device reset)
          case BOOT_STAGE_SYSC_DTB_VERIFY_FAIL:
              res = "BOOT_STAGE_SYSC_DTB_VERIFY_FAIL";
              break;
          // Failed to read FSBL file from Flash (check,  system soft reset)
          case BOOT_STAGE_SYSC_FLASH_READ_FSBL_FAIL:
              res = "BOOT_STAGE_SYSC_FLASH_READ_FSBL_FAIL";
              break;
          // an arm and fire register failed (check, device reset)
          case BOOT_STAGE_SYSC_ARM_AND_FIRE_FAILED:
              res = "BOOT_STAGE_SYSC_ARM_AND_FIRE_FAILED";
              break;
          // Software Assert (check, device reset)
          case BOOT_STAGE_SYSC_ASSERT:
              res = "BOOT_STAGE_SYSC_ASSERT";
              break;
          // DMA block transfer timeout (check, device reset)
          case BOOT_STAGE_SYSC_DMA_XFER_TIMEOUT:
              res = "BOOT_STAGE_SYSC_DMA_XFER_TIMEOUT";
              break;
          // DMA bus slave error transfer failure (check, device reset)
          case BOOT_STAGE_SYSC_DMA_SLAVE_ERROR_FAIL:
              res = "BOOT_STAGE_SYSC_DMA_SLAVE_ERROR_FAIL";
              break;
          // the programming of a clock (ACSU) failed (check, device reset)
          case BOOT_STAGE_SYSC_ACSU_INIT_FAILED:
              res = "BOOT_STAGE_SYSC_ACSU_INIT_FAILED";
              break;
          // Stack overflow detected in handlers (check, device reset)
          case BOOT_STAGE_SYSC_STACK_OVERFLOW:
              res = "BOOT_STAGE_SYSC_STACK_OVERFLOW";
              break;
          // Unexpected error(check, device reset)
          case BOOT_STAGE_SYSC_UNEXPECTED_ERROR:
              res = "BOOT_STAGE_SYSC_UNEXPECTED_ERROR";
              break;
          // DMA transfer of flash header failed (check, system soft reset)
          case BOOT_STAGE_SYSC_DMA_XFER_HEADER_FAILED:
              res = "BOOT_STAGE_SYSC_DMA_XFER_HEADER_FAILED";
              break;
          // DMA transfer of flash image failed (check, device reset)
          case BOOT_STAGE_SYSC_DMA_XFER_IMAGE_FAILED:
              res = "BOOT_STAGE_SYSC_DMA_XFER_IMAGE_FAILED";
              break;
          // timeout polling SPI status (check,  system soft reset)
          case BOOT_STAGE_SYSC_SPI_POLL_TIMEOUT:
              res = "BOOT_STAGE_SYSC_SPI_POLL_TIMEOUT";
              break;
          // SPI Flash Discovery operation failed (check, device reset)
          case BOOT_STAGE_SYSC_SPI_FLASH_DISCOVERY_FAIL:
              res = "BOOT_STAGE_SYSC_SPI_FLASH_DISCOVERY_FAIL";
              break;
          // SPI Flash Initialization Fail (check, system soft reset)
          case BOOT_STAGE_SYSC_SPI_INIT_FAIL:
              res = "BOOT_STAGE_SYSC_SPI_INIT_FAIL";
              break;
          // SPI Flash Active Fail (check, system soft reset)
          case BOOT_STAGE_SYSC_SPI_ACTIVE_FAIL:
              res = "BOOT_STAGE_SYSC_SPI_ACTIVE_FAIL";
              break;
          // The size of the FSBL file is too large (check,  system soft reset)
          case BOOT_STAGE_SYSC_FSBL_SIZE_TOO_LARGE:
              res = "BOOT_STAGE_SYSC_FSBL_SIZE_TOO_LARGE";
              break;
          // FSBL verification failed (check, device reset)
          case BOOT_STAGE_SYSC_IMAGE_VERIFY_FAIL:
              res = "BOOT_STAGE_SYSC_IMAGE_VERIFY_FAIL";
              break;
          // Failed to send a Mailbox command (check, device reset)
          case BOOT_STAGE_SYSC_MBOX_SEND_ERROR:
              res = "BOOT_STAGE_SYSC_MBOX_SEND_ERROR";
              break;
          // Mailbox Command mismatch. Command register does not match cmd field (check, device reset)
          case BOOT_STAGE_SYSC_MBOX_RESP_MISMATCH:
              res = "BOOT_STAGE_SYSC_MBOX_RESP_MISMATCH";
              break;
          // Failed to read Mailbox response (check, device reset)
          case BOOT_STAGE_SYSC_MBOX_RECV_ERROR:
              res = "BOOT_STAGE_SYSC_MBOX_RECV_ERROR";
              break;
          // Error fetching Boot config (check, device reset)
          case BOOT_STAGE_SYSC_BOOTCFG_GET_ERROR:
              res = "BOOT_STAGE_SYSC_BOOTCFG_GET_ERROR";
              break;
          // Failed to receive a response from SecC (check, device reset)
          case BOOT_STAGE_SYSC_MBOX_RECV_TIMEOUT:
              res = "BOOT_STAGE_SYSC_MBOX_RECV_TIMEOUT";
              break;
          // Secc Reboot counter bit 0 (boot counter status)
          case BOOT_STAGE_SYSC_BOOT_CNT0:
              res = "BOOT_STAGE_SYSC_BOOT_CNT0";
              break;
          // Secc Reboot counter bit 1 (boot counter status)
          case BOOT_STAGE_SYSC_BOOT_CNT1:
              res = "BOOT_STAGE_SYSC_BOOT_CNT1";
              break;
          // Secc Reboot counter 2 (boot counter status)
          case BOOT_STAGE_SYSC_BOOT_CNT2:
              res = "BOOT_STAGE_SYSC_BOOT_CNT2";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 0 (reboot fail cause)
          case BOOT_STAGE_SYSC_BOOT_STICKY_0:
              res = "BOOT_STAGE_SYSC_BOOT_STICKY_0";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 1 (reboot fail cause)
          case BOOT_STAGE_SYSC_BOOT_STICKY_1:
              res = "BOOT_STAGE_SYSC_BOOT_STICKY_1";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 2 (reboot fail cause)
          case BOOT_STAGE_SYSC_BOOT_STICKY_2:
              res = "BOOT_STAGE_SYSC_BOOT_STICKY_2";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 3 (reboot fail cause)
          case BOOT_STAGE_SYSC_BOOT_STICKY_3:
              res = "BOOT_STAGE_SYSC_BOOT_STICKY_3";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 4 (reboot fail cause)
          case BOOT_STAGE_SYSC_BOOT_STICKY_4:
              res = "BOOT_STAGE_SYSC_BOOT_STICKY_4";
              break;
          // SecC ZSBL encoding reboot failure cause from M1 bit 5 (reboot fail cause)
          case BOOT_STAGE_SYSC_BOOT_STICKY_5:
              res = "BOOT_STAGE_SYSC_BOOT_STICKY_5";
              break;
          // SecC ZSBL encoding reset reason from M1 bit 0 (reset reason)
          case BOOT_STAGE_SYSC_RESET_REASON_STICKY_0:
              res = "BOOT_STAGE_SYSC_RESET_REASON_STICKY_0";
              break;
          // SecC ZSBL encoding reset reason from M1 bit 1 (reset reason)
          case BOOT_STAGE_SYSC_RESET_REASON_STICKY_1:
              res = "BOOT_STAGE_SYSC_RESET_REASON_STICKY_1";
              break;
          // SecC ZSBL encoding reset reason from M1 bit 2 (reset reason)
          case BOOT_STAGE_SYSC_RESET_REASON_STICKY_2:
              res = "BOOT_STAGE_SYSC_RESET_REASON_STICKY_2";
              break;
          default:
              res = "unknown boot_stage_sysc_zsbl_t";
              break;

    }
    return res;
}
#endif
#endif // __ASSEMBLER__
