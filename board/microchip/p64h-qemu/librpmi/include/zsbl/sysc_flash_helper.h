/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file
 * @brief 
 * Defines common enumeration, structures and functions that 
 * are used to access data in the flash
 */
#ifndef SYSC_FLASH_HELPER_H
#define SYSC_FLASH_HELPER_H

#include <env/p64h_sysc_os_specific.h>

/// Max data size for the payload
#define MAX_DATA_SIZE 1024*1024

/// ECDSA Signature Length returned in attestation report
#define ECDSA_SIG_SIZE_BYTES                    96u
/// ECDSA Signature Length in DER format
#define ECDSA_SIG_SIZE_BYTES_DER                (ECDSA_SIG_SIZE_BYTES + 8u)
/// Dilithium Signature Length returned in attestation report
//#define DILITHIUM_SIG_SIZE_BYTES                (4595u+32u)
/// Dilithium Signature in DER format
//#define DILITHIUM_SIG_SIZE_BYTES_DER            (DILITHIUM_SIG_SIZE_BYTES + 5u)
/// ECDSA Public key size
#define ECDSA_PUBLIC_KEY_SIZE_BYTES             96u
/// Dilithum Public key size
#define DILITHIUM_PUBLIC_KEY_SIZE_BYTES         2592u
/// DTB SECTION max size in bytes (includes header bytes)
#define DTB_SECTION_MAX_SIZE_IN_BYTES  (16u*1024u)

#define PQS_MLKEM_1024_CT_SIZE 1568u
#define PQS_MLDSA87_SIGN_SIZE  (4627u)
#define PQS_MLDSA87_SIGN_SIZE_DER  (PQS_MLDSA87_SIGN_SIZE + 5u)
//#define PQS_MLDSA87_PUBLIC_KEY_SIZE  (2592u)


/**
 * An EC P-384 public key.
 */
typedef struct {

    uint32_t x[12]; ///< EC Pub Key x co-ordinate
    uint32_t y[12]; ///< EC Pub Key y co-ordinate

} sec_ec_pubkey_t;

/**
 * PQ public key struct
 */
typedef struct {

    uint8_t pub[DILITHIUM_PUBLIC_KEY_SIZE_BYTES];      ///< FIX: temporary container of the correct size

} sec_dilithium5_pubkey_t;

/** 
 * @brief
 *  Define EC & PQ signatures structure for the image header
 *  The hashes of the keys used here are to be put into HASHSET entry in OTP as part of factory provisioning using KEYS component
 */
typedef struct signature_ec_pq_t
{
  sec_ec_pubkey_t ecpubkey;                          ///< EC public key
  sec_dilithium5_pubkey_t pqpubkey;                  ///< PQ public key
  uint8_t ecsignature[ECDSA_SIG_SIZE_BYTES];         ///< signature array for NIST P-384
  uint8_t pqsignature[PQS_MLDSA87_SIGN_SIZE];     ///< signature array for Dilithium5
  uint8_t pad[5];                                    ///< padding for 64-bit alignment
} signature_ec_pq_t;

/** 
 * @brief
 *  Define a section of the flash image payload
 * 
 */
typedef struct section_desc_t
{
  uint32_t offset;            ///< offset to access section in image payload
  uint32_t length;            ///< length of section in image payload. (A length of 0 means the section is not present)
  uint32_t dest_addr;         ///< destination address to DMA the image section in sysc NOC address map. An address of 0x0 means to not DMA the image section
  uint32_t dummy;             ///< reserved (64bit alignment)
} section_desc_t;

/** 
 * @brief
 *  Define user keys
 * 
 */
typedef struct user_keys_t
{
  uint32_t sysc_fw_kek_slot;           ///< key slot for FW KEK
  uint32_t sysc_fw_kek[16];            ///< Wrapped KG descriptor
} __attribute__((packed)) user_keys_t;


/**
 * @brief flag to indicate if the image is encrypted and signed
 * 
 */
typedef struct {
  uint32_t image_encrypted:1;    ///< flag to indicate if image is encrypted.
  uint32_t image_ec_signed:1;   ///< flag to indicate if image is EC signed.
  uint32_t image_pq_signed:1;   ///< flag to indicate if image is PQ signed.
  uint32_t secc_fsbl_load_from_zsbl:1; ///< flag to indicate if secc fsbl is loaded from sysc zsbl
  uint32_t rsvd:28;             ///< reserved
} flash_header_flags_t;

/** 
 * @brief
 *  Define temporary sysc flash image header format structure
 * 
 */
typedef struct flash_header_t
{
    uint32_t version;                    ///< version    
    flash_header_flags_t flags;          ///< flag to indicate if image is encrypted and signed.
    section_desc_t sysc_cfg0;            ///< sysc cfg 0 file (typically a dtb) (optional)
    section_desc_t sysc_cfg1;            ///< sysc cfg 1 file (an extra cfg) (optional)   
    section_desc_t sysc_cfg2;            ///< sysc cfg 2 file (verification) (optional)
    section_desc_t sysc_fw;              ///< sysc FW binary     
    section_desc_t secc_fw;              ///< secc FSBL FW (optional)
    signature_ec_pq_t signature;         ///< header signature
}  flash_header_t;

/** 
 * @brief
 *  Define sysc flash image format structure
 * 
 */
typedef struct flash_image_t 
{ 
    flash_header_t hdr;                     ///< flash header structure
    uint32_t       payload[MAX_DATA_SIZE];  ///< Payload structure to store binary files
} flash_image_t;

#endif /* SYSC_FLASH_HELPER_H */

