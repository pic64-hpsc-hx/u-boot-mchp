/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines types used for OTP data
 */
#ifndef SEC_OTP_TYPES_H
#define SEC_OTP_TYPES_H

#include "boot_cfg_helper.h"

/// OTP patch reserved space
#define SEC_OTP_PATCH_LEN (64UL*1024UL)
/// OTP Patch Max offset
#define SEC_OTP_MAX_PATCH_WORD_OFFSET (SEC_OTP_PATCH_LEN/sizeof(uint32_t))
/// Total boot config entries
#define OTP_MAX_BOOTCFG_ENTRIES 5UL ///< 4 Custom Configs and 1 Canned
/// DSN length in words
#define DSN_DWORD_LEN 2u

#define LOCKSET_SIZE_MAX (16u)
#define KEYSET_SIZE_MAX  (7u)
#define HASHSET_SIZE_MAX (15u)   ///< Max key hash sets

/// Burn-in key sizes
#define BURNIN_KEY_SIGNATURE_SIZE 12u ///< 96B burn-in FW ECC signature key
#define BURNIN_KEY_AES_SIZE 4u ///< AES 256 burn-in key

#define SCAC_SIZE_WORDS 2239u    ///< Total word size to contain 3 SCACs
#define UPDIGEST_SIZE_WORDS 12u  ///< Size of User Permanent Digest in 32-bit words
#define FDIGEST_SIZE_WORDS 12u   ///< Size of Factory locki Digest in 32-bit words

///*------------------------------------------------------LOCKS------------------------------------------------------*////
/**
 * @brief User permament locks feature enable 
 * for each field, the feature is:
 *   enable  = 0x3
 *   disable = 0xc
 * Other values will disable the feature and create a SW_LOCK tamper event 
 **/
typedef struct {
    uint32_t sec_acsu_change:1;          ///< secure controller frequency can be changed via mbox commands                                         
    uint32_t otp_security:1;             ///< secure controller go in hold mode in emergency mode when enabled otherwise it 
                                         ///< accepts mbox command in emergency mode    
    uint32_t sec_zsbl_tamp_mon:1;        ///< secure controller tamper monitor, conditional of otp_sec_zsbl_tamp_mon
    uint32_t invalidate_prior_keyset:1;  ///< invalidate previous user keys when downloading a new user keyset
                                         ///< otherwise do not override SECC factory key (set0).    
    uint32_t rsvd_0:1;                  ///< reserved 0 for future use
    uint32_t rsvd_1:1;                  ///< reserved 1 for future use
    uint32_t rsvd_2:1;                  ///< reserved 2 for future use
    uint32_t rsvd_3:1;                  ///< reserved 3 for future use    
    int32_t reserved:24;                ///< reserved
} uperm_feature_t;

/**
 * @brief User permament locks 
 * for each field, the feature is:
 *   enable  = 0x3
 *   disable = 0xc
 * Other values will disable the feature and create a SW_LOCK tamper event 
 **/
typedef struct {
    uint32_t sec_acsu_change:4;          ///< secure controller frequency can be changed via mbox commands                                         
    uint32_t otp_security:4;             ///< secure controller go in hold mode in emergency mode when enabled otherwise it 
                                         ///< accepts mbox command in emergency mode    
    uint32_t sec_zsbl_tamp_mon:4;        ///< secure controller tamper monitor, conditional of otp_sec_zsbl_tamp_mon
    uint32_t invalidate_prior_keyset:4;  ///< invalidate previous user keys when downloading a new user keyset
                                         ///< otherwise do not override SECC factory key (set0).    
    uint32_t rsvd_0:4;                  ///< reserved 0 for future use
    uint32_t rsvd_1:4;                  ///< reserved 1 for future use
    uint32_t rsvd_2:4;                  ///< reserved 2 for future use
    uint32_t rsvd_3:4;                  ///< reserved 3 for future use    
    int32_t reserved_w[3];
} uperm_named_bits_t;
typedef union { 
    uint32_t UPERM[4];                                       ///< 128 bits 
    __attribute__((packed, aligned(8)))uperm_named_bits_t b; ///< access bit fields
} uperm_t;

/// Factory locks feature enable
/// NOTE: HW Locks features of flockset have been deprecated, setting them will have no effect.
typedef struct {
    uint32_t get_log:1;                 ///< GET_LOG command
    uint32_t secc_boot_status:1;        ///< allow secure controller boot stats and GET_PERIPH_STAT detailed report
    uint32_t rom_override_fwk:1;        ///< Lock fwk usage, from now on it shall be secc_klk for decrypting patches/secc_fmc test fw
    uint32_t secc_secure_debug:1;       ///< **DEPRECATED** Control the secure debug of secure controller. 
                                        //   If unset, the device unlocks debug sticky bits at boot. 
    uint32_t secure_production_test :1; ///< **DEPRECATED** Disable security requirements to enter production test mode
    uint32_t secure_otp_jtag:1;         ///< **DEPRECATED** Disable security requirements to access otp jtag.    
    uint32_t pq_boot:1;                 ///< Disable the PQ boot    
    uint32_t pq_command:1;              ///< Disable the PQ command flow in provisioning.
    uint32_t secure_hw_lock_spare_5:1;  ///< **DEPRECATED** Disable security requirements for Spare bit 5
    uint32_t periph_stat:1;             ///< Disable the periph stat command
    uint32_t rsvd_1:1;                  ///< reserved 1 for future use
    uint32_t rsvd_2:1;                  ///< reserved 2 for future use
    uint32_t rsvd_3:1;                  ///< reserved 3 for future use
    uint32_t rsvd_4:1;                  ///< reserved 4 for future use
    uint32_t dak_keyrom_index:4;        ///< Index of the key in the key ROM to be used as the DAK     
    uint32_t fwk_keyrom_index:4;        ///< Index of the key in the key ROM to be used as the FWK        
    uint32_t reserved:10;               ///< reserved    
} flockset_feature_t;

/**
 * @brief Factory locks 
 * for each field, the feature is:
 *   enable  = 0x3
 *   disable = 0xc
 * Other values will disable the feature and create a SW_LOCK or HW_LOCK tamper event 
 * NOTE: HW Locks features of flockset have been deprecated, setting them will have no effect.
 */
typedef struct {
    uint32_t get_log:4;                 ///< GET_LOG command
    uint32_t secc_boot_status:4;        ///< secure controller boot stats and GET_PERIPH_STAT detailed report
    uint32_t rom_override_fwk:4;        ///< Lock fwk usage, from now on it shall be secc_klk for decrypting patches/secc_fmc test fw
    uint32_t secc_secure_debug:4;       ///< **DEPRECATED** Control the secure debug of secure controller. If unset, the device unlocks debug sticky bits at boot. 
    uint32_t secure_production_test :4; ///< **DEPRECATED** Disable security requirements to enter production test mode
    uint32_t secure_otp_jtag:4;         ///< **DEPRECATED** Disable security requirements to access otp jtag.    
    uint32_t pq_boot:4;                 ///< Disable the PQ boot    
    uint32_t pq_command:4;              ///< Disable the PQ command flow in provisioning.
    uint32_t secure_hw_lock_spare_5:4;  ///< **DEPRECATED** Disable security requirements for Spare bit 5
    uint32_t dak_keyrom_index:4;        ///< Index of the key in the key ROM to be used as the DAK     
    uint32_t fwk_keyrom_index:4;        ///< Index of the key in the key ROM to be used as the FWK    
    uint32_t periph_stat:4;             ///< peripheral statistics command lock
    uint32_t rsvd_1:4;                  ///< reserved 1 for future use
    uint32_t rsvd_2:4;                  ///< reserved 2 for future use
    uint32_t rsvd_3:4;                  ///< reserved 3 for future use
    uint32_t rsvd_4:4;                  ///< reserved 4 for future use
    uint32_t reserved_w[2];    
} flockset_named_bits_t;

// Factory locks 
typedef union {
    uint32_t FLOCK32[4];      ///< bitmask where each bit represents a factory lock
    __attribute__((packed, aligned(8)))flockset_named_bits_t b;   ///< access bit fields
} flockset_t;

/**
 * @brief lockset feature enable 
 */
typedef struct {
    uint64_t sysc_image_signature:1;  ///< signature check for the sysc image
    uint64_t sysc_image_encryption:1; ///< encryption check for the sysc image
    uint64_t app_secure_debug:1;      ///< secure debug of the application complex
    uint64_t sysc_secure_debug:1;     ///< secure debug of sysc 
    uint64_t zeroize:1;               ///< zeroize command/will be implemented in patch.
    uint64_t force_autoreset:1;       ///< force auto_reset  
    uint64_t hw_lock_spare_6:1;       ///< Disable security requirements for Spare bit 6
    uint64_t hw_lock_spare_7:1;       ///< Disable security requirements for Spare bit 7    
    uint32_t patch_fail_reset_dev:1;  ///< reset the device if applying patch fails  
    uint32_t rsvd_0:1;                ///< reserved 0 for future use
    uint32_t rsvd_1:1;                ///< reserved 1 for future use
    uint32_t rsvd_2:1;                ///< reserved 2 for future use
    uint32_t rsvd_3:1;                ///< reserved 3 for future use
    uint32_t rsvd_4:1;                ///< reserved 4 for future use
    uint32_t rsvd_5:1;                ///< reserved 5 for future use
    uint32_t rsvd_6:1;                ///< reserved 6 for future use      
    uint64_t reserved:16;
} __attribute__((packed, aligned(4))) lockset_feature_t;

/**
 * @brief lockset feature enable 
 */
typedef struct {
    uint64_t app_secure_debug:1;      ///< secure debug of the application complex
    uint64_t sysc_secure_debug:1;     ///< secure debug of sysc 
    uint64_t sysc_debug_first_inst:1; ///< when sysc_first_inst is set, secure controller won't remove suppress fetch when sysc boot
                                      ///< this state persists until a POR or when it is cleared
    uint64_t reserved:29;
} __attribute__((packed, aligned(4))) lockset_secure_debug_enable_t;

/**
 * @brief lockset stucture 
 * for each field, the feature is:
 *   enable  = 0x3
 *   disable = 0xc
 * Other values will disable the feature and create a SW_LOCK or HW_LOCK tamper event 
 */
typedef struct {
    uint64_t sysc_image_signature:4;  ///< signature check for the sysc image
    uint64_t sysc_image_encryption:4; ///< encryption check for the sysc image
    uint64_t app_secure_debug:4;      ///< secure debug of the application complex
    uint64_t sysc_secure_debug:4;     ///< secure debug of sysc 
    uint64_t zeroize:4;               ///< zeroize command/will be implemented in patch.
    uint64_t force_autoreset:4;       ///< force auto_reset  
    uint64_t hw_lock_spare_6:4;       ///< Disable security requirements for Spare bit 6
    uint64_t hw_lock_spare_7:4;       ///< Disable security requirements for Spare bit 7
    uint32_t patch_fail_reset_dev:4;  ///< reset the device if applying patch fails   
    uint32_t rsvd_0:4;                ///< reserved 0 for future use
    uint32_t rsvd_1:4;                ///< reserved 1 for future use
    uint32_t rsvd_2:4;                ///< reserved 2 for future use
    uint32_t rsvd_3:4;                ///< reserved 3 for future use
    uint32_t rsvd_4:4;                ///< reserved 4 for future use
    uint32_t rsvd_5:4;                ///< reserved 5 for future use
    uint32_t rsvd_6:4;                ///< reserved 6 for future use      
    uint64_t reserved_w[2];
} lockset_named_bits_t;

typedef union {
    uint64_t ULOCK64[4];
    __attribute__((packed, aligned(4)))lockset_named_bits_t b;
} __attribute__((packed, aligned(4))) lockset_t;

////*------------------------------------------------------END OF LOCKS------------------------------------------------------*////

/// PUF initialization data
typedef struct {
    uint64_t PUFPPS[6];       /* 6 (5.5) DWORDS */
    uint64_t PUFAC[361];
    uint64_t FDIGEST0[6];
} __attribute__((packed, aligned(4))) puf_config_t;

/// Factory keys
typedef struct {
    uint32_t KLK[12];
    uint32_t KM_DEFAULT_KEY[12];
    uint32_t KLK_PQ[20];
    uint32_t KLK_EC[16];
    uint32_t FDIGEST[12]; //FDIGEST_SYSC_KLK for sysc, FDIGEST_SECC_KLK for secc
} __attribute__((packed)) factory_bs_keys_t;

/// Private Factory keys
typedef struct {
    uint64_t PCSALT[2];                 /**< Passcode salt **/
    uint64_t FSKEC[8];                /**< FSKEC (exported) **/
    uint64_t FEK[8];                  /**< FEK (exported) **/
    uint64_t FSKPQ[6];                /**< FSKPQ (exported) (2x256b shares) **/ 
    uint64_t FDIGEST3[6];   
} __attribute__((packed, aligned(4))) private_factory_keys_t;


/// Device identity parameters
typedef struct {  
    uint64_t dsn[DSN_DWORD_LEN];///< Device Serial Number  
    uint64_t FPKH[6];
    uint64_t FDIGEST1[6];
} __attribute__((packed, aligned(4)))  device_identity_t;

//burn-in key
typedef struct {
    uint64_t burnin_ecdsapub_key[BURNIN_KEY_SIGNATURE_SIZE]; ///< 96B burn-in FW ECC signature key
    uint64_t burnin_aes_key[BURNIN_KEY_AES_SIZE]; ///< AES 256 burn-in key
} __attribute__((packed, aligned(4)))  burnin_key_t;

typedef struct {
    uint32_t boot_cfg_vector_sel:5; ///< Boot config select vector
    uint32_t rsvd2: 27;             ///< unused
} boot_cfg_params_t;

/** Structure defining content of a KeySet **/

typedef struct {
    /// @brief We dont have any UPK/DPK based usecase in the ZSBL currently
    uint64_t UPK1H[6]; ///< This is a space reserver in the OTP for future use in secc fsbl
    uint64_t DPKH[6];  ///< place holder for future use in secc fsbl
    uint64_t UK1[6];  
    uint64_t UK2[6];  
    uint64_t USKEC[8];          /// wrapped 
    uint64_t USQEC[12];  
    uint64_t USKPQ[6];          /// wrapped seed of the PQ private key
    uint64_t HUBQ[6];           /**< H(UBQEC || UBQPQ) **/ //112. comes in via UDATA0 as full keys. we compoute the hash and store it here
    uint64_t UKDIGEST1[6];
    uint64_t RESERVER[6]; 
     
} __attribute__((packed, aligned(4)))  keyset_t;

/**
 * A ULDIGEST structure fore LOCKSET
 */

typedef struct {
    uint32_t ULDIGEST[12];
} uldigest_t;

/**
 * A HASHSET structure.
 */
typedef struct {
    uint32_t hash_desc; ///< Each bit signifies to support key type and usage
    uint32_t hash[12]; ///< Sha3(PT Payload); precalculated by Cryptool, that will be compared with FW calculated hash
} hashset_t;

/**
 * 0x00000284 BOOT_MODE
 *
 *     TMR protected register - can write individual bits to 1 on different
 *         write actions without corrupting the register.
 *     This register is not shadowed.
 *
 * bits        4:0  default 0x0 BOOT_MODE
 * field_bits  4:0
 *     Boot Mode
 *     Virgin/test/burn-in/normal/EOL
 *
 *     (FW should also look into OTP_write_protect)
 *
 * bits        31:5 default 0x0 SPARE_BITS_161__31_5
 * field_bits  26:0
 *     SPARE/unassigned OTP bits
 */
typedef struct {
    uint32_t boot_mode:5;///< bit  0..4  R/W
    uint32_t padding:27; ///< bit  5..31 R/W
} boot_mode_t; ///< access bit fields

/// boot_op_0_t structure 
typedef struct {
    uint32_t otp_spw_mode:2;                              ///< bit  0..1  r/w
    uint32_t otp_usr_disable_ip_while_power_gated_mode:2; ///< bit  2..3  r/w
    uint32_t otp_ddr_disable_ip_while_power_gated_mode:2; ///< bit  4..5  r/w
    uint32_t otp_force_autoreset:1;                       ///< bit  6     r/w
    uint32_t sysc_wdt_mode_sel:1;                         ///< bit  7     r/w
    uint32_t otp_mask_secc_boot_status:1;                 ///< bit  8     r/w
    uint32_t reserved:23;                                 ///< bit  9..31 r/w
} boot_op_0_t;

/// boot_op_1_t structure 
typedef struct {
    uint32_t otp_sec_zsbl_tamp_mon:1;  ///< bit  0     r/w
    uint32_t spare_bits_6631__31_1:31; ///< bit  1..31 r/w    
} boot_op_1_t;

/*
 * @brief permanent lock for features
 * Program to 0x7 to set the permanent disable the feature access.
 *  When set to logic:
 *     0x0 - Permanent lock is not set.
 *     Other - Permanent lock is set.
 */
typedef struct {
    uint32_t otp_perm_prod_test_lock:3;  ///< Permanent lock for production_test_enable.
    uint32_t spare_bits_7__3_3:1;        ///< spare
    uint32_t otp_perm_otp_jtag_lock:3;   ///< Permanent lock for OTP JTAG interface.
    uint32_t spare_bits_7__7_7:1;        ///< spare
    uint32_t otp_perm_sysc_debug_lock:3; ///< Permanent lock for System Controller debug_enable.
    uint32_t spare_bits_7__11_11:1;      ///< spare
    uint32_t otp_perm_appc_debug_lock:3; ///< Permanent lock for Application Complex debug_enable.
    uint32_t spare_bits_7__15_15:1;      ///< spare
    uint32_t otp_perm_secc_debug_lock:3; ///< Permanent lock for secc_debug_enable
    uint32_t spare_bits_7__19_19:1;      ///< spare
    uint32_t otp_perm_spare5_lock:3;     ///< Permanent lock for SPARE5 feature
    uint32_t spare_bits_7__23_23:1;      ///< spare
    uint32_t otp_perm_spare6_lock:3;     ///< Permanent lock for SPARE6 feature.
    uint32_t spare_bits_7__27_27:1;      ///< spare
    uint32_t otp_perm_spare7_lock:3;     ///< Permanent lock for SPARE7 feature
    uint32_t spare_bits_7__31_31:1;      ///< spare
  } perm_lock_0_t; 

/**
 * 0x000002d0 PUF_CONFIG0
 *
 *     TMR protected register - can write individual bits to 1 on different
 *         write actions without corrupting the register.
 *     This register is not shadowed.
 *
 * bits        0     default 0   OTP_PUF_QK_EXCLUDE_BUS_KEEPER_PUF
 *     Setting guidance for ZSBL for PUF usage.
 *     This value is to be used for setting the PUF_QK_EXCLUDE_BUS_KEEPER_PUF
 *         field in the M1 SECC PCBI registers when using the PUF.  This bit
 *         will be programmed to 1 to indicate PUF bus keeper cells should be
 *         excluded from usage if device testing reveals that the PUF bus
 *         keeper usage has problems and we need to fall back to using the SRAM
 *         PUF only instead of SRAM+bus_keeper PUF.
 *
 * bits        25:16 default 0x0 OTP_PUFSW_PU
 * field_bits  9:0
 *     Setting guidance for ZSBL for PUF usage.
 *     This value is to guide the value be used for setting the PUFSW_PU[9:0]
 *         field in the M1 SECC PCBI registers when using the PUF to control
 *         the PUF Power Switch trim.
 *     If this field is not programmed and has valu all-zeros, then the
 *         PUFSW_PU[9:0] field in the M1 SECC PCBI registers should be
 *         programmed to 0x200.
 *
 * bits        15:1  default 0x0 SPARE_BITS_180__15_1
 * field_bits  14:0
 *     SPARE/unassigned OTP bits
 *
 * bits        31:26 default 0x0 SPARE_BITS_180__31_26
 * field_bits  5:0
 *     SPARE/unassigned OTP bits
 */
typedef struct {
    uint32_t f_OTP_PUF_QK_INCLUDE_BUS_KEEPER_PUF:1; ///< bit  0      R/W
    uint32_t f_SPARE_BITS_180__15_1:15;             ///< bit  1..15  R/W
    uint32_t f_OTP_PUFSW_PU:10;                     ///< bit  16..25 R/W
    uint32_t f_SPARE_BITS_180__31_26:6;             ///< bit  26..31 R/W
    uint32_t f_OTP_PUF_POWER_OFF_DELAY; ///< bit  0..31 R/
    uint32_t f_OTP_PUF_POWER_ON_DELAY; ///< bit  0..31 R/W
} puf_hw_config_t;

typedef struct {
    uint32_t spw_disable:1;
    uint32_t usb_disable:1;
    uint32_t emmcsd_disable:1;
    uint32_t ddr_enc_disable:1;
    uint32_t usr_crypto_disable:1;
    uint32_t pqc_usr_disable:1;
    uint32_t pqc_sec_disable:1;
    uint32_t enet_swr_disable:1;
    uint32_t app_clstr1_disable:1;
    uint32_t scrub_demand_disable:1;
    uint32_t scrub_patrol_disable:1;
    uint32_t scrub_limit:1;
    uint32_t spare_bits:20;
}disable_grp_named_bits_t;

typedef union {
    uint32_t disable_grp;
    __attribute__((packed, aligned(4))) disable_grp_named_bits_t b;
} disable_grp_t;

typedef struct
{
    uint32_t top_ctrl;       ///< top control
    uint32_t vstart0;        ///< Virgin device start access enable control.  Set any bits to 1 to disable.  Enabled when all of VSTART0/1/2=0.
    uint32_t vstart1;        ///< Virgin device start access enable control.  Set any bits to 1 to disable.  Enabled when all of VSTART0/1/2=0.
    uint32_t vstart2;        ///< Virgin device start access enable control.  Set any bits to 1 to disable.  Enabled when all of VSTART0/1/2=0.
    uint32_t m1_otp_data;    ///< Spare OTP data to M1 for POR FSM BOOT.
    disable_grp_t disable_grp;    ///< device disable group
    boot_op_0_t boot_op_0;   ///< boot operation 
    perm_lock_0_t perm_lock;   ///< 0x0000001c                    AES_OTP_MEMORY_MAPPED_ACCESS_reg_PERM_LOCK0_t
    uint32_t r_SPARE_SHDW_TMR_OVR_Y[5]; ///< spare TMR with override
    uint32_t r_SPARE_SHDW_TMR_OVR_N[3]; ///< spare TMR without override
    burnin_key_t burnin_key; ///< Burn-in key (32*32bits)    
    uint32_t r_SPARE_TMR_REG0;
    uint32_t ZIP_ZDONE;       ///< ZIP and ZDONE //To be used in FSBL
    uint32_t locktherm;            ///< Thermometer counter for LOCKSET selection     
    uint32_t  keytherm;             ///< Thermometer counter for KEYSET selection
    uint32_t r_SPARE_TMR_REG1;
    uint32_t r_hwmtherm[20]; ///< HWM Thermometer counter
    uint32_t r_backlevel_sysc[20]; ///< Backlevel for SYSC
    uint32_t r_backlevel_secc[20]; ///< Backlevel for SECC
    uint32_t  patch_inv_vect[8];    ///< Patch Invalidation Vector
    uint32_t  hash_inv_vect; ///< Hash list invalidation vector     
    boot_mode_t boot_mode; ///< boot mode 
    puf_hw_config_t puf_hw_config;    
    uint32_t r_SPARE_TMR0[2];
    boot_cfg_params_t bootcfg_params; ///< boot config vector    
    uint32_t r_SPARE_TMR1[127];

    // ---- end of TMR section ----
    // (fields in first 1K of OTP can be rewritten multiple times changing bits from 0 to 1)
    
    uint32_t r_DEVICE_ID_GRP;        
    uint32_t r_ANALOG_TOP_GRP0;      
    uint32_t r_ANALOG_TOP_GRP1;      
    uint32_t r_ANALOG_TOP_GRP2;      
    uint32_t r_ANALOG_TOP_GRP3;      
    uint32_t r_TEMP_MON_CONRATE_GRP; 
    uint32_t r_TEMP_MON_TA_GRP;      
    uint32_t r_TEMP_MON_TB_GRP;      
    uint32_t r_TEMP_MON_TC_GRP;      
    uint32_t r_TEMP_MON_VA_GRP;      
    uint32_t r_TEMP_MON_VB_GRP;      
    uint32_t r_TEMP_MON_VC_GRP;      
    uint32_t r_TEMP_MON_V18A_GRP;    
    uint32_t r_TEMP_MON_V18B_GRP;    
    uint32_t r_TEMP_MON_V18C_GRP;    
    uint32_t r_TEMP_MON_LEVEL_GRP;   
    uint32_t r_M1_TIME_SETTLE_GRP;   
    uint32_t r_DRV_STAT_GRP;         
    uint32_t r_RC_TIMER_GRP;         
    uint32_t r_EDGECURR_CTRIM_GRP;   
    uint32_t r_EDGECURR_ITRIM_GRP;   
    uint32_t r_SPARE_SHDW_ECC_OVR_Y[8];
    uint32_t r_SPARE_SHDW_ECC_OVR_N[3];   
    uint32_t r_TEMP_MON_R_TRIM_GRP;  
    uint32_t r_TEMP_MON_L_TRIM_GRP;  
    uint32_t r_TEMP_MON_RCONRATE_GRP;
    uint32_t r_TEMP_MON_RTA_GRP;     
    uint32_t r_TEMP_MON_RTB_GRP;     
    uint32_t r_TEMP_MON_RTC_GRP;     
    uint32_t r_TEMP_MON_RVA_GRP;     
    uint32_t r_TEMP_MON_RVB_GRP;     
    uint32_t r_TEMP_MON_RVC_GRP;     
    uint32_t r_TEMP_MON_RV18A_GRP;   
    uint32_t r_TEMP_MON_RV18B_GRP;   
    uint32_t r_TEMP_MON_RV18C_GRP;   
    uint32_t r_TEMP_MON_RLEVEL_GRP;  
    uint32_t r_TEMP_MON_LCONRATE_GRP;
    uint32_t r_TEMP_MON_LTA_GRP;     
    uint32_t r_TEMP_MON_LTB_GRP;     
    uint32_t r_TEMP_MON_LTC_GRP;     
    uint32_t r_TEMP_MON_LVA_GRP;     
    uint32_t r_TEMP_MON_LVB_GRP;     
    uint32_t r_TEMP_MON_LVC_GRP;     
    uint32_t r_TEMP_MON_LV18A_GRP;   
    uint32_t r_TEMP_MON_LV18B_GRP;   
    uint32_t r_TEMP_MON_LV18C_GRP;   
    uint32_t r_TEMP_MON_LLEVEL_GRP;  
    uint32_t r_TXPLL_GRP[4];         
    uint32_t r_CDR_DC_OFFSET_GRP[44];
    uint32_t r_PE_FUSE_GEN[8];       
    uint32_t r_PE_RINGOSC[8];   
    device_identity_t device_identity; ///< FPKH and FDIGEST1
    uint32_t fdigest[FDIGEST_SIZE_WORDS];        ///< Flockset digest 
    uint32_t r_SPARE_ECC0[96];               
    uint32_t updigest[UPDIGEST_SIZE_WORDS];     ///< User permanent digest.
    uint32_t SCAC[SCAC_SIZE_WORDS];         ///< container for 3 SCACs   
    puf_config_t puf_config;     ///< PUF config data    
    factory_bs_keys_t sysc_factory_keys; ///< factory provisioned sysc klk    
    factory_bs_keys_t secc_factory_keys; ///< factory provisioned secc klk
    private_factory_keys_t private_factory_keys;///< device keys generated during factory enrollment
    uint32_t dib[8]; ///< Device identity block    
    lockset_t lockset[LOCKSET_SIZE_MAX];  /**< Lockset array indexed by LOCKTHERM **/       
    keyset_t  keyset[KEYSET_SIZE_MAX];    /**< Keyset array indexed by KEYTHERM **/    
    uldigest_t uldigest[LOCKSET_SIZE_MAX];  ///< uldigest array indexed by LOCKTHERM  
    uint32_t zcert[1187]; ///< ZCERT
    uint32_t hwm[256]; ///< HWM
    hashset_t hashset[HASHSET_SIZE_MAX]; /**< Hashset array, not indexed by HASHTHERM **/    
    boot_op_1_t boot_op_1;    
    uperm_t uperm;                ///< permanent locks  
    flockset_t flockset;          ///< factory Lockset
    uint32_t r_SPARE_ECC1[16];    
    bootcfg_otp_t boot_cfg[OTP_MAX_BOOTCFG_ENTRIES];///< boot config data bootcfg_otp_t
    uint32_t r_SPARE_ECC2[64];
    uint32_t PATCH_CT[16384UL];                 ///< space for ROM patches        
} otp_struct_t;

#if 0
/** @brief 
 *   Use this function to display the offset of PATCH_CT.
 *   Remove the #if 0 to display.
 * 
 *  @note
 *   A special function to show the offset of PATCH_CT.
 *   This function when compiled will show an argument type mismatch error AND
 *   it will also display the offset of PATCH_CT!
 *  
 * hpsc-zsbl/core/include/sec_otp_types.h:189:28: error: 
 * format specifies type 'int' but the argument has type 'int (*)[26624]' [-Werror,-Wformat] 189 |     __builtin_printf("%d", &array);
 * 
 *  In the above example, the offsetof(otp_struct_t, PATCH_CT) = 26624
 */
void error() {
    int array[offsetof(otp_struct_t,PATCH_CT)];
    __builtin_printf("%d", &array);
}
#endif

typedef union 
{
    /// 3 blocks of 32KB    
    volatile uint32_t OTP_DATA32[3u * 32u*1024u/4u];
    /// OTP mem map
    otp_struct_t otp;
    
} sec_otp_map_t;


#endif /* SEC_OTP_TYPES_H */
