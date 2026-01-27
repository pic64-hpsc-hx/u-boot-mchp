/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines types used for SMB commands
 */
#ifndef SEC_SMB_TYPES_H
#define SEC_SMB_TYPES_H

#include "sec_crypto_types.h" // sec_signature_t

/**
 * Signature Verification command structure
 */
typedef struct sec_sig_ec_pq_verify_t{
    sec_signature_t signature;  ///< includes EC & PQ signatures, EC & PQ public keys
    uint32_t size;              ///< message size in bytes
    uint8_t padding[4];         ///< padding to align payload to 64b
    uint8_t *payload;           ///< message used for signature generation
} sec_sig_ec_pq_verify_t;

/**
 * @brief Bitmask to get the peripheral stat of the category that has 1 in the bit position
 */
typedef enum {
    SEC_OTP_PE_DATA_CMD_TEMP_MON_R = 1 << 0,  ///< Mask for TEMP_MON_R fields
    SEC_OTP_PE_DATA_CMD_TEMP_MON_L = 1 << 1,  ///< Mask for TEMP_MON_L fields
    SEC_OTP_PE_DATA_CMD_CAL        = 1 << 2,  ///< Mask for CAL fields
    SEC_OTP_PE_DATA_CMD_PE         = 1 << 3,  ///< Mask for PE fields
    SEC_OTP_PE_DATA_CMD_SPARE      = 1 << 4   ///< Mask for SPARE fields
} sec_otp_pe_data_cmd_mask_t;


/**
 * @brief PE_t structure definition
 */
typedef struct {
    uint32_t pe_fuse_gen[8]; ///< PE_PE_FUSE_GEN
    uint32_t pe_ringosc[8];  ///< PE_PE_RINGOSC
} pe_t;

/**
 * @brief SPARE_t structure definition
 */
typedef struct {
    uint32_t spare_tmr_reg1; ///< SPARE_SPARE_TMR_REG1
    uint32_t spare_ecc0[96]; ///< SPARE_SPARE_ECC0
    uint32_t spare_ecc1[16]; ///< SPARE_SPARE_ECC1
    uint32_t spare_ecc2[64]; ///< SPARE_SPARE_ECC2
} spare_t;


/**
 * @brief TEMP_MON_x_t structure definition
 */
typedef struct {
    uint32_t trim_grp; ///< TEMP_MON_R_TRIM_GRP / TEMP_MON_L_TRIM_GRP
    /**< @note Use AES_OTP_MEMORY_MAP_reg_TEMP_MON_R_TRIM_GRP_t to decode fields */
    uint32_t conrate_grp; ///< TEMP_MON_R_CONRATE_GRP / TEMP_MON_L_CONRATE_GRP
    uint32_t ta_grp;      ///< TEMP_MON_R_TA_GRP / TEMP_MON_L_TA_GRP
    uint32_t tb_grp;      ///< TEMP_MON_R_TB_GRP / TEMP_MON_L_TB_GRP
    uint32_t tc_grp;      ///< TEMP_MON_R_TC_GRP / TEMP_MON_L_TC_GRP
    uint32_t va_grp;      ///< TEMP_MON_R_VA_GRP / TEMP_MON_L_VA_GRP
    uint32_t vb_grp;      ///< TEMP_MON_R_VB_GRP / TEMP_MON_L_VB_GRP
    uint32_t vc_grp;      ///< TEMP_MON_R_VC_GRP / TEMP_MON_L_VC_GRP
    uint32_t v18a_grp;    ///< TEMP_MON_R_V18A_GRP / TEMP_MON_L_V18A_GRP
    uint32_t v18b_grp;    ///< TEMP_MON_R_V18B_GRP / TEMP_MON_L_V18B_GRP
    uint32_t v18c_grp;    ///< TEMP_MON_R_V18C_GRP / TEMP_MON_L_V18C_GRP
    uint32_t level_grp;   ///< TEMP_MON_R_LEVEL_GRP / TEMP_MON_L_LEVEL_GRP
    /**< @note Use AES_OTP_MEMORY_MAP_reg_TEMP_MON_LEVEL_GRP_t to decode fields */
} temp_mon_x_t;


/**
 * @brief CAL_t structure definition
 */
typedef struct {
    uint32_t txpll_grp[4];          ///< CAL_TXPLL_GRP
    uint32_t cdr_dc_offset_grp[44]; ///< CAL_CDR_DC_OFFSET_GRP
} cal_t;


/**
 * @brief otp_pe_data_t structure definition
 */
typedef struct {
    temp_mon_x_t temp_mon_r; ///< TEMP_MON_R fields
    temp_mon_x_t temp_mon_l; ///< TEMP_MON_L fields
    cal_t cal;               ///< CAL fields
    pe_t pe;                 ///< PE fields
    spare_t spare;           ///< SPARE fields
} otp_pe_data_t;


/**
 * @brief /// Temparture and Voltage Sensor readout
 * 
 */
typedef struct {    
    uint16_t tvs_val_vdd;        ///< Converted value for channel 0 VDD.                           
    uint16_t tvs_val_vdd18;      ///< Converted value for channel 1 VDD18.
    uint16_t tvs_val_adc;        ///< Converted value for channel 2 ADC.
    uint16_t tvs_val_temp;       ///< Converted value for channel 3 Temperature.
    uint8_t  tvs_high_trig_stat; ///< High temperature threshold event has occurred since the last read, reading this feild will also clear it until next read
    uint8_t  tvs_high_trig_val;  ///< reflects the current state of the high temperature trigger, 1 = High temperature trigger is currently present.
    uint8_t  tvs_low_trig_stat;  ///<  Low temperature threshold event has occurred since the last read, reading this feild will also clear it until next read
    uint8_t  tvs_low_trig_val;   ///< reflects the current state of the low temperature trigger, 1 = low temperature trigger is currently present.
} tvs_mon_stat_t;

#endif /* SEC_SMB_TYPES_H */

