/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file scratchpad.h
 * @brief
 * Defines common constants, macros, enumerations and structures used by
 * the sysc/secc scratchpad driver.
 */

#ifndef SCRATCHPAD_H
#define SCRATCHPAD_H

// all sysc scratch register
#define SYSC_SCRATCH_STICKY_NUM_REG 32U
#define SYSC_SCRATCH_STICKY_REG_WIDTH 32U
/// boot scratch register 
#define SYSC_BOOT_SCRATCH_STICKY_SIZE 2U
#define SYSC_BOOT_SCRATCH_STICKY_OFF 0U
// exception handler boot counter 
#define SYSC_BOOT_CNT_SCRATCH_STICKY_SIZE 1U
#define SYSC_BOOT_CNT_SCRATCH_STICKY_OFF (SYSC_BOOT_SCRATCH_STICKY_OFF+ SYSC_BOOT_SCRATCH_STICKY_SIZE)
#define SYSC_BOOT_CNT_SCRATCH_STICKY_SAT_MASK 0xFFFFU  
// sysc exception handler scratch register
#define SYSC_EXC_SCRATCH_STICKY_SIZE 5U
#define SYSC_EXC_SCRATCH_STICKY_OFF (SYSC_BOOT_CNT_SCRATCH_STICKY_OFF+SYSC_BOOT_CNT_SCRATCH_STICKY_SIZE)
/// sysc free
#define SYSC_FREE_SCRATCH_STICKY_SIZE 21U
#define SYSC_FREE_SCRATCH_STICKY_OFF  (SYSC_EXC_SCRATCH_STICKY_OFF+SYSC_EXC_SCRATCH_STICKY_SIZE)
/// Allocate region of scratch register for tracking BOOT_STAT settings
#define SYSC_BOOT_STAT_SHADOW_SCRATCH_STICKY_SIZE 3U
#define SYSC_BOOT_STAT_SHADOW_SCRATCH_STICKY_OFF  (SYSC_FREE_SCRATCH_STICKY_OFF+SYSC_FREE_SCRATCH_STICKY_SIZE)
#ifndef SWIG
static_assert(SYSC_BOOT_STAT_SHADOW_SCRATCH_STICKY_OFF+SYSC_BOOT_STAT_SHADOW_SCRATCH_STICKY_SIZE == SYSC_SCRATCH_STICKY_NUM_REG,"wrong sysc M1 scratchpad sizing");
#endif

// all secc scratch register
#define SECC_SCRATCH_STICKY_NUM_REG   8U
#define SECC_SCRATCH_STICKY_REG_WIDTH 32U
// secc exception handler scratch register
#define SECC_EXC_SCRATCH_STICKY_SIZE 5U
#define SECC_EXC_SCRATCH_STICKY_OFF  0U
// mnbeu 
#define SECC_MNBEU_STICKY_OFF 4U
/// exception boot counter 
#define SECC_BOOT_CNT_SCRATCH_STICKY_SIZE 1U
#define SECC_BOOT_CNT_SCRATCH_STICKY_OFF  SECC_EXC_SCRATCH_STICKY_OFF+SECC_EXC_SCRATCH_STICKY_SIZE
#define SECC_BOOT_CNT_SCRATCH_STICKY_SAT_MASK 0xFFFFU
/// NMI context 
#define SECC_NIM_CONTEXT_SCRATCH_STICKY_SIZE 1U
#define SECC_NIM_CONTEXT_SCRATCH_STICKY_OFF  SECC_BOOT_CNT_SCRATCH_STICKY_OFF+SECC_BOOT_CNT_SCRATCH_STICKY_SIZE
/// secc free

#define SECC_MISC_SCRATCH_STICKY_SIZE 1U
#define SECC_MISC_SCRATCH_STICKY_OFF  SECC_NIM_CONTEXT_SCRATCH_STICKY_OFF+SECC_NIM_CONTEXT_SCRATCH_STICKY_SIZE
#ifndef SWIG
static_assert(SECC_MISC_SCRATCH_STICKY_OFF+SECC_MISC_SCRATCH_STICKY_SIZE == SECC_SCRATCH_STICKY_NUM_REG,"wrong secc M1 scratchpad sizing");
#endif

// exception handler type 
typedef enum {
    EXC_HANDLER_EARLY_TRAP = 0U, 
    EXC_HANDLER_DEFAULT_ZSBL, 
    EXC_HANDLER_RNMI_EXCP, 
    EXC_HANDLER_DEFAULT_FSBL, 
} exc_handler_t;

// exception handler action
typedef enum {
    EXC_ACTION_DEV_RST = 0U, ///< request a device reset    
    EXC_ACTION_SOFT_RST,     ///< perform a system soft reset (local)
    EXC_ACTION_HARD_RST,     ///< perform a system soft reset (local)
    EXC_ACTION_HOLD,         ///< halt processor in a WFI loop
    EXC_ACTION_TAMPER        ///< tamper
} exc_action_t;

/// Scratchpad registers for boot control
/// boot mode
typedef struct {
    uint32_t por                    : 1;  ///< indicates power-on reset; Assumption is that it is cleared on POR; 0- POR, 1- not POR
    uint32_t early_sys_zsbl_active  : 1; ///< indicates if ZSBL is active; tracks this iteration of code execution prior to plan_iteration() analyzing prior iteration data.
    uint32_t sys_zsbl_active        : 1;  ///< indicates if ZSBL is active; 0- ZSBL is not active, 1- ZSBL is active
    uint32_t sys_fsbl_active        : 1;  ///< indicates if FSBL is active; 0- FSBL is not active, 1- FSBL is active
    uint32_t image_id               : 3;  ///< image_id being processed for sysc FSBL boot procedure
    uint32_t sysc_boot_sticky       : 6;  ///< Sticky bits for SysC ZSBL to transfer to BOOT_STAT on execution startup
    uint32_t sys_fsbl_boot_req      : 2; ///< FSBL boot request command see sysc_fsbl_boot_req_t
    uint32_t sys_fsbl_boot_image_id : 3; ///< FSBL requested image_id for SysC ZSBL to attempt boot
    uint32_t sys_fsbl_fail_mode     : 1; ///< FSBL force image boot fails, 0 - follow policy in image_table_entry, 1 - follow fsbl defined policy
    uint32_t sys_fsbl_policy        : 1; ///< on failure of FSBL forced image boot, 0 - request emergency mode, 1 - use sys_fsbl_policy_image
    uint32_t sys_fsbl_policy_image  : 3; ///< FSBL force image boot, failure rollback next image ID
    uint32_t fill                   : 9; ///< Reserved  
} scratchpad_boot_mode_t;
#ifndef SWIG
static_assert(sizeof(scratchpad_boot_mode_t) == 4,"scratchpad_boot_mode_t should be 4 bytes");
#endif

/// boot context 
typedef struct {
    uint32_t sys_zsbl_periph_init      :1;  ///< 1- Enter ZSBL Reset Init Periph section, this iteration
    uint32_t sys_zsbl_nvm_read_auth    :1;  ///< 1- Enter ZSBL NVM Read and Auth section, this iteration
    uint32_t sys_zsbl_flash_hdr_auth   :1;  ///< 1- Completed successful Flash Header Authentication, this iteration
    uint32_t sys_zsbl_dtb_auth         :1;  ///< 1- Completed successful FSBL DTB Authentication, this iteration
    uint32_t sys_zsbl_ocr_fw_auth      :1;  ///< 1- Completed successful FSBL FW Binary Authentication, this iteration
    uint32_t sys_zsbl_fsbl_jump        :1;  ///< 1- Calling Jump to FSBL program, this iteration
    uint32_t sys_fsbl_main_start       :1;  ///< 1- Enter FSBL main function, this iteration
    uint32_t sys_fsbl_mon_active       :1;  ///< 1- Completed FSBL initial appc boot and in monitor mode, this iteration 
    uint32_t sys_zsbl_img_fail_cnt     :2;  ///< Count ZSBL failed before FSBL Jump, this image attempt
    uint32_t sys_fsbl_img_fail_cnt     :2;  ///< Count FSBL failed before FSBL entered monitoring state
    uint32_t sys_img_fail_limit        :2;  ///< Limit FSBL and ZSBL can fail before entering monitoring phase, this image attempt    
    uint32_t sys_zsbl_otp_itn_fail_cnt :6;  ///< Count ZSBL failed for an iteration of n images in OTP image attempt execution 
    uint32_t sys_zsbl_no_plan_fail_cnt :6;  ///< Count ZSBL failed prior to planning an image boot or to enter emergency mode
    uint32_t sys_fsbl_mon_fail_cnt     :6;  ///< Count FSBL failed in monitoring phase since POR
    //uint32_t fill                    :0;  ///< Reserved
} scratchpad_boot_ctxt_t;
#ifndef SWIG
static_assert(sizeof(scratchpad_boot_ctxt_t) == 4,"scratchpad_boot_ctxt_t should be 4 bytes");
#endif

/// exception handler scratch register 
/// exception machine-level 0
typedef struct {
  // machine exception (from mtvec handler or rnmi exception handler)    
  uint32_t mhandler:2;      ///< 0 = early trap (zsbl), 1: default handler(zbsl), 2: rnmi exception(zsbl), 3: default handler (fsbl)
  uint32_t mexccode:4;      ///< Machine Cause Register - code identifying the last exception.      
  uint32_t mtval_high:12;   ///< Machine bad address or instruction (12 higher bits)        
  uint32_t maction:3;       ///< 0 = Device Reset, 1 = System Soft Reset, 2 = System Hard Reset, 3 = Hold, 4 = tamper
  uint32_t mboot_stat:7;    ///< boot_stat that causes that the exception 
                            ///<   - valid when mexccode == MCAUSE_MACHINE_ECALL, last boot_stat from the machine env 
                            ///<   - otherwise, indicate handler has cause the reset  
                            ///< may be redundant with mepc 
  uint32_t mcause_set:1;    ///< mcause is set 
  uint32_t mncause_set:1;   ///< mncause is set 
  uint32_t unsed :2;        ///< unused
} scratchpad_exc_m0_t;
#ifndef SWIG
static_assert(sizeof(scratchpad_exc_m0_t) == 4,"scratchpad_exc_m0_t should be 4 bytes");
#endif

/// exception machine-level 1
typedef struct {
  uint32_t minterrupt:1;        ///< Machine Cause Register - 1,if the trap was caused by an interrupt; 0 otherwise.    
  uint32_t mepc_high:12;        ///< Machine exception program counter (12 higher bits)               
  uint32_t mnrnmi_cause:1;      ///< Resumable Non-maskable cause value, 0 = Interrupt, 1 = BEU
  uint32_t mnrnmi_wdog_src : 1; ///< RNMI sysc SWE source, 0 = wdog ok, 1 = sysc wdog
                                ///<      secc 0 = sysc reset request, 1 = secc wdog
  uint32_t mnbeu_cause:3;       ///< BEU - Cause of error event
  uint32_t mnbeu_value_high:12; ///< BEU - Physical address of error event    
  uint32_t mnaction:2;          ///< 0 = Device Reset, 1 = System Soft Reset, 2 = System Hard Reset, 3 = Hold
} scratchpad_exc_m1_t;
#ifndef SWIG
static_assert(sizeof(scratchpad_exc_m1_t) == 4,"scratchpad_exc_m0_t should be 4 bytes");
#endif

/// sysc exception context 
typedef struct {
  scratchpad_exc_m0_t m0;   ///< Machine-level exception register 0    
  uint32_t mepc_low;        ///< Machine exception program counter (32 lower bits)
  uint32_t mtval_low;       ///< If the cause is a load/store fault, this register 
                            ///< has the value of the problematic address. 
                            ///< If it is an invalid instruction, it provides the instruction that the core tried to execute.     
  scratchpad_exc_m1_t m1;   ///< Machine-level exception register 1
  uint32_t mnbeu_value_low; ///< BEU - Physical address of error event
} sysc_scratchreg_exc_sticky_t;

typedef struct {
  scratchpad_exc_m0_t m0;   ///< Machine-level exception register 0    
  uint32_t mepc_low;        ///< Machine exception program counter (32 lower bits)
  uint32_t mtval_low;       ///< If the cause is a load/store fault, this register 
                            ///< has the value of the problematic address. 
                            ///< If it is an invalid instruction, it provides the instruction that the core tried to execute.     
  scratchpad_exc_m1_t m1;   ///< Machine-level exception register 1
  uint32_t mnbeu_value_low; ///< BEU - Physical address of error event
} secc_scratchreg_exc_sticky_t;

typedef struct {
    scratchpad_boot_mode_t boot_mode;
    scratchpad_boot_ctxt_t history;    
} scratchpad_boot_mode_grp_t;

/**
 * @brief misc SECC M1 sticky bits
 */
typedef struct  {
    uint32_t sysc_bist:1;             ///< bit  0     R/W
    uint32_t secc_bist:1;             ///< bit  1     R/W
    uint32_t override_bist:1;         ///< bit  2     R/W
    uint32_t sysc_no_supress_fetch:1; ///< bit  3     R/W
    uint32_t padding : 27;            ///< bit  4..30 R/W
    uint32_t past_emergency_check : 1; ///< bit 31 - past emergency_mode check at least once.
} secc_scratchreg_misc_t;

#ifndef SWIG
typedef union {
  uint32_t w[SYSC_EXC_SCRATCH_STICKY_SIZE]; ///< This grouping will be used to commit the scratchpad registers to HW
  sysc_scratchreg_exc_sticky_t exc;         ///< exception handler sticky bit 
} sysc_scratchreg_exc_sticky_grp_t;

typedef union {
  uint32_t w[SECC_EXC_SCRATCH_STICKY_SIZE]; ///< This grouping will be used to commit the scratchpad registers to HW
  secc_scratchreg_exc_sticky_t exc;         ///< exception handler sticky bit 
} secc_scratchreg_exc_sticky_grp_t;

typedef union {
  uint32_t w[SYSC_BOOT_SCRATCH_STICKY_SIZE]; // This grouping will be used to commit the scratchpad registers to HW
  scratchpad_boot_mode_grp_t b;
} sysc_boot_scratchreg_sticky_t;

// Compile time check to ensure that the size of the scratchpad register structure is within the expected size
static_assert(sizeof(sysc_scratchreg_exc_sticky_grp_t) == (size_t)SYSC_EXC_SCRATCH_STICKY_SIZE * sizeof(uint32_t), "Unexpected size of sysc_scratchreg_exc_sticky_grp_t");
static_assert(sizeof(secc_scratchreg_exc_sticky_grp_t) == (size_t)SECC_EXC_SCRATCH_STICKY_SIZE * sizeof(uint32_t), "Unexpected size of secc_scratchreg_exc_sticky_grp_t");
static_assert(sizeof(sysc_boot_scratchreg_sticky_t) == (size_t)SYSC_BOOT_SCRATCH_STICKY_SIZE * sizeof(uint32_t), "Unexpected size of sysc_boot_scratchreg_sticky_t");
static_assert(sizeof(sysc_boot_scratchreg_sticky_t) == 8, "sysc_boot_scratchreg_sticky_t should be 8 bytes");
#endif 

#endif // SCRATCHPAD_H
