/* (c) 2024 Microchip Technology Inc. */
/* SPDX-License-Identifier: MIT */

/**
 * @file cperlib.h
 * @brief
 *  CPERLIB header
 * @addtogroup CPERLIB
 * @{
 */

#ifndef ACPI_TABLES_H
#define ACPI_TABLES_H

#include <ras/p64h_cper.h>

/* Public Defines -------------------------------------------------- */
#define P64H_ACPI_NAMESEG_SIZE                 (4U)
#define P64H_ACPI_OEM_ID_SIZE                  (6U)
#define P64H_ACPI_OEM_TABLE_ID_SIZE            (8U)

#define P64H_CPRL_SIG_RECORD                   "CPRL"

#define P64H_HEST_ACK_REGISTER_NOT_ACKNOWLEDGE (0x00000AC5U)

#define P64H_CPER_GUID_TILE_EVT                P64H_UUID_INIT(0x1de0eb5f, 0x39be, 0x4944, 0xa1, 0xb5, 0xb5, 0xc0, 0xb2, 0x6b, 0x76, 0xfb)
#define P64H_CPER_GUID_LOCKSTEP                P64H_UUID_INIT(0xFB5D9857, 0x5672, 0x4E2A, 0xB9, 0x00, 0x92, 0x30, 0x48, 0x33, 0x24, 0x54)
#define P64H_CPER_GUID_WORLDGUARD              P64H_UUID_INIT(0x9EB1127E, 0x8DA7, 0x44CC, 0xB9, 0x4A, 0xDE, 0x93, 0x86, 0x44, 0xE3, 0x30)
#define P64H_CPER_GUID_SYSC_BEU                P64H_UUID_INIT(0x7e9b0031, 0x5302, 0x4506, 0xb0, 0x15, 0x14, 0x83, 0x4e, 0xd4, 0x6b, 0x08)
#define P64H_CPER_GUID_SECC_BEU                P64H_UUID_INIT(0x8776731c, 0x6c9f, 0x4a0b, 0x9a, 0x6e, 0x80, 0x19, 0x20, 0xb5, 0x71, 0xf0)
#define P64H_CPER_GUID_SDRAM                   P64H_UUID_INIT(0xADB5527E, 0x8DA7, 0x44CC, 0xB9, 0x4A, 0xDE, 0x93, 0x86, 0x44, 0xE3, 0x30)
#define P64H_CPER_GUID_OCR                     P64H_UUID_INIT(0xA0BEC99E, 0xA94C, 0x4FD6, 0xA7, 0xC7, 0x07, 0x79, 0x55, 0x23, 0x46, 0x82)
#define P64H_CPER_GUID_NVM_EDAC                P64H_UUID_INIT(0xb438ba2d, 0x75b9, 0x4267, 0x9d, 0x28, 0x55, 0x57, 0x0b, 0xbe, 0x4f, 0xcf)
#define P64H_CPER_GUID_IOMMU                   P64H_UUID_INIT(0xe585014a, 0x57a4, 0x495f, 0x81, 0xd4, 0xe4, 0xb5, 0x87, 0x6c, 0x3e, 0x25)
#define P64H_CPER_GUID_ACSU                    P64H_UUID_INIT(0x13f6b576, 0x5606, 0x478e, 0x9e, 0x71, 0xe3, 0xc8, 0x15, 0xd6, 0x99, 0xb8)
#define P64H_CPER_GUID_SYSC_FW                 P64H_UUID_INIT(0x743a60b7, 0x53be, 0x4ea2, 0xae, 0xd1, 0x8b, 0xfd, 0x5a, 0x60, 0x32, 0xbd)
#define P64H_CPER_GUID_INTR_STORM              P64H_UUID_INIT(0x743a60b7, 0x53be, 0x4ea2, 0xae, 0xd1, 0x8b, 0xfd, 0x5a, 0x60, 0x32, 0xbd)
#define P64H_CPER_GUID_PFLASH_CTRL             P64H_UUID_INIT(0x7c80927d, 0x43bf, 0x4bcf, 0xb3, 0x72, 0xb0, 0x1a, 0x70, 0x20, 0xf3, 0x44)
#define P64H_CPER_GUID_ENET_SW                 P64H_UUID_INIT(0x111663cb, 0xfc25, 0x499b, 0xa6, 0x72, 0x3a, 0x73, 0xae, 0xa7, 0xac, 0x92)
#define P64H_CPER_GUID_DDR_CTRL                P64H_UUID_INIT(0xe7f522ea, 0xfa2e, 0x4eb5, 0x96, 0xeb, 0x3b, 0xda, 0xa5, 0x9a, 0x1b, 0x6a)
#define P64H_CPER_GUID_DDR_EDAC                P64H_UUID_INIT(0x3d798239, 0xec96, 0x4e76, 0x8f, 0x7e, 0x29, 0x9f, 0xb6, 0x69, 0xc7, 0x04)
#define P64H_CPER_GUID_SPI_CTRL                P64H_UUID_INIT(0xf521e2a4, 0x5eb9, 0x41f1, 0x9c, 0xd6, 0x33, 0x09, 0xe4, 0xd3, 0xc9, 0xab)
#define P64H_CPER_GUID_NAND_CTRL               P64H_UUID_INIT(0x2626c610, 0xd946, 0x400e, 0xa2, 0x53, 0x33, 0xb6, 0xe2, 0xd4, 0x2e, 0x41)

/* Public Structs and Enums ----------------------------------------- */
typedef struct p64h_acpi_hest_generic_status {
    uint32_t block_status;
    uint32_t raw_data_offset;
    uint32_t raw_data_length;
    uint32_t data_length;
    uint32_t severity;
} p64h_acpi_hest_generic_status_t;

typedef struct p64h_acpi_hest_generic_data_v300 {
    uint8_t  section_type[16];
    uint32_t severity;
    uint16_t revision;
    uint8_t  validation_bits;
    uint8_t  flags;
    uint32_t error_data_length;
    uint8_t  fru_id[16];
    uint8_t  fru_text[20];
    uint64_t timestamp;
} p64h_acpi_hest_generic_data_v300_t;

typedef struct p64h_acpi_generic_address {
    uint8_t  space_id;     /* Address space where struct or register exists */
    uint8_t  bit_width;    /* Size in bits of given register */
    uint8_t  bit_offset;   /* Bit offset within the register */
    uint8_t  access_width; /* Minimum Access size (ACPI 3.0) */
    uint64_t address;      /* 64-bit address of struct or register */
} p64h_acpi_generic_address_t;

typedef struct p64h_acpi_hest_notify {
    uint8_t  type;
    uint8_t  length;
    uint16_t config_write_enable;
    uint32_t poll_interval;
    uint32_t vector;
    uint32_t polling_threshold_value;
    uint32_t polling_threshold_window;
    uint32_t error_threshold_value;
    uint32_t error_threshold_window;
} p64h_acpi_hest_notify_t;

typedef struct acpi_table_header {
    char     signature[P64H_ACPI_NAMESEG_SIZE];         /* ASCII table signature */
    uint32_t length;                                    /* Length of table in bytes, including this header */
    uint8_t  revision;                                  /* ACPI Specification minor version number */
    uint8_t  checksum;                                  /* To make sum of entire table == 0 */
    char     oem_id[P64H_ACPI_OEM_ID_SIZE];             /* ASCII OEM identification */
    char     oem_table_id[P64H_ACPI_OEM_TABLE_ID_SIZE]; /* ASCII OEM table identification */
    uint32_t oem_revision;                              /* OEM revision number */
    char     asl_compiler_id[P64H_ACPI_NAMESEG_SIZE];   /* ASCII ASL compiler vendor ID */
    uint32_t asl_compiler_revision;                     /* ASL compiler version */
} p64h_acpi_table_header_t;

typedef struct acpi_table_hest {
    p64h_acpi_table_header_t header; /* Common ACPI table header */
    uint32_t                 error_source_count;
} p64h_acpi_table_hest_t;

typedef struct p64h_acpi_hest_header {
    uint16_t type;
    uint16_t source_id;
} p64h_acpi_hest_header_t;

typedef struct p64h_acpi_hest_generic_v2 {
    p64h_acpi_hest_header_t     header;
    uint16_t                    related_source_id;
    uint8_t                     reserved;
    uint8_t                     enabled;
    uint32_t                    records_to_preallocate;
    uint32_t                    max_sections_per_record;
    uint32_t                    max_raw_data_length;
    p64h_acpi_generic_address_t error_status_address;
    p64h_acpi_hest_notify_t     notify;
    uint32_t                    error_block_length;
    p64h_acpi_generic_address_t read_ack_register;
    uint64_t                    read_ack_preserve;
    uint64_t                    read_ack_write;
} p64h_acpi_hest_generic_v2_t;

typedef struct p64h_hest {
    p64h_acpi_table_hest_t      header;
    p64h_acpi_hest_generic_v2_t cluster_ghes[0];
} p64h_hest_t;

typedef struct p64h_bert {
    p64h_acpi_table_header_t header; /* Common ACPI table header */
    uint32_t                 boot_error_region_len;
    uint64_t                 boot_error_region;
} p64h_bert_t;

#endif /* ACPI_TABLES_H */

/// @}
