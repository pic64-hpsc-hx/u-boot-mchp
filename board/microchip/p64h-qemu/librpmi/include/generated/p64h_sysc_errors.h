/* (c) 2026 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

/* ======================================= */
/*  This file is generated and should not  */
/*              be modified!               */
/* ======================================= */

#ifndef P64H_SYSC_DEF_ERRORS
#define P64H_SYSC_DEF_ERRORS

#include <generated/p64h_sysc_components.h>

/* Public Defines ------------------------------------------ */
#define P64H_SYSC_SVC_ERR_SVC_OFFSET 0x80000000U ///< Service components error start offset

uint32_t err_id_decode(uint32_t code);
uint32_t err_component_decode(uint32_t code);

// Only a literal error value will show its name correctly
// Usage: P64H_LOG_INFO(P64H_ERROR_LOG_FORMAT, P64H_ERROR_LOG_DECODE( P64H_ERR_GENERAL ));
#define P64H_ERROR_LOG_DECODE(err_code) #err_code, err_component_decode(err_code), err_id_decode(err_code)
extern char* P64H_ERROR_LOG_FORMAT;

/* Public Structs and Enums -------------------------------- */
/**
 * @brief P64H SYSC Errors
 *
 */

typedef enum p64h_err_t {
    P64H_ERR_OK                                                             = 0,                                                                                    ///< This is the status to indicate successful completion
    P64H_ERR_GENERAL,                                                                                                                                               ///< INFO General message type
    P64H_ERR_BOOT_CONFIG_FILE,                                                                                                                                      ///< boot config related errors
    P64H_ERR_MEMORY_FAIL,                                                                                                                                           ///< memory malloc errors
    P64H_ERR_INIT_FAIL,                                                                                                                                             ///< Initialization operation errors.
    P64H_ERR_IPC_DATA_NULL,                                                                                                                                         ///< IPC data returned NULL error
    P64H_ERR_IPC_WRONG_MESSAGE,                                                                                                                                     ///< IPC wrong message type error
    P64H_ERR_IPC_MESSAGE_SIZE_ERROR,                                                                                                                                ///< IPC message size error.
    P64H_ERR_IPC_SEND_FAIL,                                                                                                                                         ///< IPC send fail
    P64H_ERR_IPC_GET_MSG_FAIL,                                                                                                                                      ///< IPC get fail
    P64H_ERR_IPC_CHANNEL_NOT_FOUND,                                                                                                                                 ///< IPC channel not found
    P64H_ERR_IPC_CHANNEL_ID_INVALID,                                                                                                                                ///< IPC channel ID invalid
    P64H_ERR_RPMSG_FAIL,                                                                                                                                            ///< RPMSG API related failure
    P64H_ERR_DDR_INIT_FAIL,                                                                                                                                         ///< DDR initialization failed
    P64H_ERR_CONFIG_POPULATE_FAIL,                                                                                                                                  ///< Populating config failure
    P64H_ERR_PFLASH_INIT_FAIL,                                                                                                                                      ///< PFLASH initialization failed
    P64H_ERR_PFLASH_SOC_UNDEFINED,                                                                                                                                  ///< PFLASH DTS expects to find a SOC element
    P64H_ERR_PFLASH_FLASH_UNDEFINED,                                                                                                                                ///< PFLASH DTS expects to find a FLASH element
    P64H_ERR_PFLASH_CELL_SIZE,                                                                                                                                      ///< PFLASH DTS expects cell size of some elements
    P64H_ERR_FDT_NOT_FOUND,                                                                                                                                         ///< FDT file header check failed or not found
    P64H_ERR_FDT_BAD_FORMATTING,                                                                                                                                    ///< Unexpected FDT format
    P64H_ERR_FDT_DEV_CFG_NODE,                                                                                                                                      ///< Missing dev_cfg node
    P64H_ERR_NULL_POINTER,                                                                                                                                          ///< NULL pointer argument
    P64H_ERR_NULL_HANDLE,                                                                                                                                           ///< Handle argument not set
    P64H_ERR_INVALID_HANDLE,                                                                                                                                        ///< Invalid base address for peripheral handle
    P64H_ERR_INVALID_INPUT,                                                                                                                                         ///< Invalid function parameter
    P64H_ERR_VERSION_MISMATCH,                                                                                                                                      ///< dev_cfg & sysc_fw version mismatch
    P64H_ERR_NOT_IMPLEMENTED,                                                                                                                                       ///< Function not implemented
    P64H_ERR_MEMCPY_FAIL,                                                                                                                                           ///< Failed to copy memory
    P64H_ERR_DWORD_UNALIGNED,                                                                                                                                       ///< Table address not DWORD aligned
    P64H_ERR_SVC_SYSTEM_CTXT_INIT                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_SYSTEM),
    P64H_ERR_SVC_SYSTEM_SERVICE_START,
    P64H_ERR_SVC_SYSTEM_ERR,
    P64H_ERR_SVC_SYSTEM_INVALID_API,
    P64H_ERR_SVC_SYSTEM_UNEXPECTED_EVENT,
    P64H_ERR_SVC_SYSTEM_DEV_CFG_VERSION_INIT,
    P64H_ERR_SVC_SYSTEM_ACOT_ENTRY_INVALID,                                                                                                                         ///< ACOT entry invalid
    P64H_ERR_SVC_APPC_INVALID_API                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_APPC),
    P64H_ERR_SVC_APPC_UNEXPECTED_EVENT,
    P64H_ERR_SVC_APPC_NOT_LOADED_APPC_CFG,                                                                                                                          ///< appc_cfg not loaded at bootscript execution time
    P64H_ERR_SVC_APPC_NOT_LOADED_STATIC_CFG,                                                                                                                        ///< static_cfg not loaded at bootscript execution time
    P64H_ERR_SVC_APPC_INVALID_CTXT_SIGNATURE,                                                                                                                       ///< invalid value for ctxt component address struct signature
    P64H_ERR_SVC_APPC_OUT_OF_RANGE_PARTITIONID,                                                                                                                     ///< out of range partition id given
    P64H_ERR_SVC_APPC_UNEXPECTED_CMD,                                                                                                                               ///< unexpected cmd id passed in the appc_bootscript
    P64H_ERR_SVC_APPC_NO_CMD_IN_BOOTSCRIPT,                                                                                                                         ///< No commands were found in the bootscript attempted for boot
    P64H_ERR_SVC_APPC_BOOTSCRIPT_CMD_LOAD,                                                                                                                          ///< Failed to load the requested appc binary specified in the booscript
    P64H_ERR_SVC_APPC_BOOTSCRIPT_CMD_GET,                                                                                                                           ///< Failed to fetch the requested command indexed from bootscript
    P64H_ERR_SVC_COM_ERR                                                    = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_COM),
    P64H_ERR_SVC_COM_INVALID_API,
    P64H_ERR_SVC_COM_UNEXPECTED_EVENT,
    P64H_ERR_SVC_COM_ERR2,
    P64H_ERR_SVC_TEST_ERR                                                   = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_TEST),
    P64H_ERR_SVC_TEST_INVALID_API,
    P64H_ERR_SVC_TEST_UNEXPECTED_EVENT,
    P64H_ERR_SVC_TEST_UTEST_UNEXPECTED_EVENT,
    P64H_ERR_SVC_TEST_UNIT_TEST_FAIL,
    P64H_ERR_SVC_TEST_ERR2,
    P64H_ERR_SVC_TEST_UTEST_INVALID_REQ_SRC,                                                                                                                        ///< Error: Invalid request source for event intercept set
    P64H_ERR_SVC_TEST_UTEST_IN_PROGRESS,                                                                                                                            ///< Error: Only one unit test can run
    P64H_ERR_SVC_TEST_NO_ACTIVE_UTEST,                                                                                                                              ///< A unit test was requested to stop but none are running.
    P64H_ERR_SVC_TRACE_ERR                                                  = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_TRACE),
    P64H_ERR_SVC_TRACE_INVALID_API,
    P64H_ERR_SVC_TRACE_UNEXPECTED_EVENT,
    P64H_ERR_SVC_TRACE_ERR2,
    P64H_ERR_SVC_TRACE_INVALID_DATA,
    P64H_ERR_SVC_TRACE_SW_TRACING_UNSUPPORTED_TYPE,
    P64H_ERR_SVC_TRACE_SW_TRACING_OUT_OF_ENTRIES,
    P64H_ERR_SVC_CRYPTO_ERR                                                 = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_CRYPTO),
    P64H_ERR_SVC_CRYPTO_INVALID_API,
    P64H_ERR_SVC_CRYPTO_UNEXPECTED_EVENT,
    P64H_ERR_SVC_CRYPTO_ERR2,
    P64H_ERR_SVC_SECC_MBOX_INVALID_CMD                                      = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_SECC_MBOX),        ///< Invalid SMB command was received
    P64H_ERR_SVC_SECC_MBOX_SMB_BUSY,                                                                                                                                ///< SMB busy with other command
    P64H_ERR_SVC_SECC_MBOX_FALSE_RESP,                                                                                                                              ///< False positive response detected through interrupt event from SMB
    P64H_ERR_SVC_HW_CTXT_UNINIT                                             = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_HW),               ///< context accessed prior to initialization
    P64H_ERR_SVC_HW_DDR_BINARY_LOAD,                                                                                                                                ///< Trying to load sysc_ddr_cfg binary into hw context
    P64H_ERR_SVC_HW_HANDLE_UNINIT,                                                                                                                                  ///< Trying to access hw handle prior initialization
    P64H_ERR_SVC_HW_INVALID_ID,                                                                                                                                     ///< HW RPMI Call made with invalid ID
    P64H_ERR_SVC_HW_SERDES_NOT_CFG,                                                                                                                                 ///< Attempted to call an RPMI function on a SerDes group which does not have a static configuration
    P64H_ERR_SVC_HW_INTR_REGISTRATION_FAILED,
    P64H_ERR_SVC_HW_INTR_DISABLE_FAILED,                                                                                                                            ///< Failed to disable the interrupt
    P64H_ERR_SVC_HW_INTR_ENABLE_FAILED,                                                                                                                             ///< Failed to enable the interrupt
    P64H_ERR_SVC_HW_UNEXPECTED_EVENT,
    P64H_ERR_SVC_SWITCH_INVALID_API                                         = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_SWITCH),
    P64H_ERR_SVC_SWITCH_UNEXPECTED_EVENT,
    P64H_ERR_SVC_EM_INVALID_API                                             = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_EM),
    P64H_ERR_SVC_EM_UNEXPECTED_EVENT,
    P64H_ERR_SVC_EM_UNIT_TEST_FAIL,
    P64H_ERR_SVC_EM_CPER_BUFFER,                                                                                                                                    ///< Failed to complete add, remove, init, or destroy operations on the GHES CPER buffer
    P64H_ERR_SVC_EM_CPERLIB_MAKE_CPER,                                                                                                                              ///< Failed to convert a error event into a CPER record
    P64H_ERR_SVC_EM_CPERLIB_HANDLE_CPER,                                                                                                                            ///< Failed to forward and handle a hardware error event into a CPER record
    P64H_ERR_SVC_EM_HEST_INSUFFICIENT_MEM,                                                                                                                          ///< Not enough memory was allocated for the HEST of a partition
    P64H_ERR_SVC_EM_BERT_INSUFFICIENT_MEM,                                                                                                                          ///< Not enough memory was allocated for the BERT of a partition
    P64H_ERR_SVC_EM_RB_INSUFFICIENT_MEM,                                                                                                                            ///< Not enough memory was allocated for the ring buffers used in error logging
    P64H_ERR_SVC_EM_ERR_BUF_IDX_OUT_OF_RANGE,                                                                                                                       ///< Index of error record in ERT for fetch is invalid
    P64H_ERR_SVC_EM_INVALID_APPC_PARTITION,                                                                                                                         ///< Index of appc partition is invalid
    P64H_ERR_SVC_HEALTH_INVALID_API                                         = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_SVC_HEALTH),
    P64H_ERR_SVC_HEALTH_UNEXPECTED_EVENT,
    P64H_ERR_DRV_APP_WRAP_DCLS_TIMEOUT                                      = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_APP_WRAP),         ///< Error returned when executing DCLS action is taking too long
    P64H_ERR_DRV_APP_WRAP_NULL_HANDLE,                                                                                                                              ///< Error returned when a pointer argument to an APP_WRAP handle is null.
    P64H_ERR_DRV_APP_WRAP_NULL_CFG,                                                                                                                                 ///< Error returned when a pointer argument to an APP_WRAP configuration is null.
    P64H_ERR_DRV_APP_WRAP_INVALID_INST,                                                                                                                             ///< Error returned when trying to configure an invalid APP_WRAP instance.
    P64H_ERR_DRV_APP_PERIPH_GPIO_NULL_HANDLE                                = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_APP_PERIPH),       ///< Error: a pointer argument to a gpio handle is NULL
    P64H_ERR_DRV_APP_PERIPH_GPIO_NULL_CFG,                                                                                                                          ///< Error: a pointer argument to a gpio configuration is NULL
    P64H_ERR_DRV_APP_PERIPH_GPIO_INVALID_INSTANCE,                                                                                                                  ///< Error: trying to configure an invalid number of GPIO instances
    P64H_ERR_DRV_APP_PERIPH_GPIO_AF_ERR,                                                                                                                            ///< Error: trying to configure arm and fire GPIO register
    P64H_ERR_DRV_APP_PERIPH_GPIO_MUX_NULL_HANDLE,                                                                                                                   ///< Error: a pointer argument to a gpio mux handle is NULL
    P64H_ERR_DRV_APP_PERIPH_GPIO_MUX_NULL_CFG,                                                                                                                      ///< Error: a pointer to the gpio mux configuration structure is null
    P64H_ERR_DRV_APP_PERIPH_GPIO_MUX_INVALID_CFG,                                                                                                                   ///< Error: the gpio mux configuration is invalid
    P64H_ERR_DRV_APP_PERIPH_I2C_INVALID_INST,                                                                                                                       ///< Error: i2c id is invalid
    P64H_ERR_DRV_APP_PERIPH_I2C_NULL_HANDLE,                                                                                                                        ///< Error: a pointer to the handle is null
    P64H_ERR_DRV_APP_PERIPH_I2C_NULL_CFG,                                                                                                                           ///< Error: a pointer to the configuration structure is null
    P64H_ERR_DRV_APP_PERIPH_IPC_NULL_HANDLE,                                                                                                                        ///< Error: a pointer to the handle is null
    P64H_ERR_DRV_APP_PERIPH_IPC_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to an IPC configuration is null
    P64H_ERR_DRV_APP_PERIPH_IPC_INVALID_INST,                                                                                                                       ///< Error: trying to configure an invalid IPC instance
    P64H_ERR_DRV_APP_PERIPH_APP_HPT_NULL_HANDLE,                                                                                                                    ///< Error: a pointer to the handle is null
    P64H_ERR_DRV_APP_PERIPH_APP_HPT_NULL_CFG,                                                                                                                       ///< Error: a pointer argument to an App HPT configuration is null
    P64H_ERR_DRV_APP_PERIPH_APP_HPT_INVALID_INST,                                                                                                                   ///< Error: trying to configure an invalid App HPT instance
    P64H_ERR_DRV_APP_PERIPH_APP_WDT_NULL_HANDLE,                                                                                                                    ///< Error: a pointer to the handle is null
    P64H_ERR_DRV_APP_PERIPH_APP_WDT_NULL_CFG,                                                                                                                       ///< Error: a pointer argument to an App WDT configuration is null
    P64H_ERR_DRV_APP_PERIPH_APP_WDT_INVALID_INST,                                                                                                                   ///< Error: trying to configure an invalid App WDT instance
    P64H_ERR_DRV_APP_PERIPH_APP_TIMERS_NULL_HANDLE,                                                                                                                 ///< Error: a pointer to the handle is null
    P64H_ERR_DRV_APP_PERIPH_APP_TIMERS_INVALID_ARG,                                                                                                                 ///< Error: the argument is invalid
    P64H_ERR_DRV_APP_PERIPH_ENET_EP_NULL_HANDLE,                                                                                                                    ///< Error: a pointer argument to an ENET EP handle is null
    P64H_ERR_DRV_APP_PERIPH_ENET_EP_NULL_CFG,                                                                                                                       ///< Error: a pointer argument to an ENET EP configuration is null
    P64H_ERR_DRV_APP_PERIPH_ENET_EP_INVALID_INST,                                                                                                                   ///< Error: trying to configure an invalid ENET EP instance
    P64H_ERR_DRV_APP_PERIPH_ENET_EP_INVALID_RATE,                                                                                                                   ///< Error: trying to configure ENET EP with an invalid rate
    P64H_ERR_DRV_APP_PERIPH_DDR_NULL_HANDLE,                                                                                                                        ///< Error: a pointer argument to an DDR handle is null
    P64H_ERR_DRV_APP_PERIPH_DDR_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to an DDR configuration is null
    P64H_ERR_DRV_APP_PERIPH_DDR_INVALID_INST,                                                                                                                       ///< Error: trying to configure an invalid DDR instance
    P64H_ERR_DRV_APP_PERIPH_ENET_SWR_NULL_HANDLE,                                                                                                                   ///< Error: a pointer argument to an ENET Switch configuration is null
    P64H_ERR_DRV_APP_PERIPH_ENET_SWR_NULL_CFG,                                                                                                                      ///< Error: a pointer argument to an ENET Switch configuration is null
    P64H_ERR_DRV_APP_PERIPH_ENET_SWR_NO_INTR_FOUND,                                                                                                                 ///< Error: no interrupt status bit was set
    P64H_ERR_DRV_APP_PERIPH_ENET_SWR_INVALID_PARAM,                                                                                                                 ///< Error: invalid function parameters passed
    P64H_ERR_DRV_APP_PERIPH_NULL_HANDLE,                                                                                                                            ///< Error: a pointer to the app_periph handle is null
    P64H_ERR_DRV_APP_PERIPH_NULL_CFG,                                                                                                                               ///< Error: a pointer to the app_periph configuration is null
    P64H_ERR_DRV_APP_PERIPH_UART_NULL_HANDLE,                                                                                                                       ///< Error: a pointer argument to an UART handle is null
    P64H_ERR_DRV_APP_PERIPH_UART_NULL_CFG,                                                                                                                          ///< Error: a pointer argument to an UART configuration is null
    P64H_ERR_DRV_APP_PERIPH_UART_INVALID_INST,                                                                                                                      ///< Error: trying to configure an invalid UART instance
    P64H_ERR_DRV_APP_PERIPH_APPDMA_NULL_HANDLE,                                                                                                                     ///< Error: a pointer argument to an APPDMA handle is null
    P64H_ERR_DRV_APP_PERIPH_APPDMA_NULL_CFG,                                                                                                                        ///< Error: a pointer argument to an APPDMA configuration is null
    P64H_ERR_DRV_APP_PERIPH_APPDMA_INVALID_INST,                                                                                                                    ///< Error: trying to configure an invalid APPDMA instance
    P64H_ERR_DRV_APP_PERIPH_OCR_NULL_HANDLE,                                                                                                                        ///< Error: a pointer argument to an OCR handle is null
    P64H_ERR_DRV_APP_PERIPH_OCR_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to an OCR configuration is null
    P64H_ERR_DRV_APP_PERIPH_OCR_INVALID_INST,                                                                                                                       ///< Error: trying to configure an invalid OCR instance
    P64H_ERR_DRV_APP_PERIPH_BOOT_STAT_NULL_HANDLE,                                                                                                                  ///< Error: a pointer argument to a BOOT STAT handle is null
    P64H_ERR_DRV_APP_PERIPH_BOOT_STAT_NULL_CFG,                                                                                                                     ///< Error: a pointer argument to a BOOT STAT configuration is null
    P64H_ERR_DRV_APP_PERIPH_INVALID_EDAC_INSTANCE,                                                                                                                  ///< Error: trying to configure an invalid EDAC instance
    P64H_ERR_DRV_APP_PERIPH_SPW_NULL_HANDLE,                                                                                                                        ///< Error: a pointer argument to a SPW handle is null
    P64H_ERR_DRV_APP_PERIPH_SPW_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to a SPW configuration is null
    P64H_ERR_DRV_APP_PERIPH_SPW_INVALID_INST,                                                                                                                       ///< Error returned when trying to configure an invalid SPW instance.
    P64H_ERR_DRV_APP_PERIPH_SPW_INVALID_ROUTER_TABLE_ADDRESS,                                                                                                       ///< Error returned when trying to read/write to an invalid SPW Router table address.
    P64H_ERR_DRV_APP_PERIPH_SPW_INVALID_PORT,                                                                                                                       ///< Error returned when trying to write with an invalid SPW port.
    P64H_ERR_DRV_APP_PERIPH_PCIE_NULL_HANDLE,                                                                                                                       ///< Error: a pointer argument to an PCIE handle is null
    P64H_ERR_DRV_APP_PERIPH_PCIE_NULL_CFG,                                                                                                                          ///< Error: a pointer argument to an PCIE configuration is null
    P64H_ERR_DRV_APP_PERIPH_PCIE_INVALID_INST,                                                                                                                      ///< Error: trying to configure an invalid PCIE instance
    P64H_ERR_DRV_APP_PERIPH_PCIE_INVALID_CFG,                                                                                                                       ///< Error: the given configuration for a PCIe instance is invalid
    P64H_ERR_DRV_APP_PERIPH_PCIE_ARM_AND_FIRE_ERR,                                                                                                                  ///< Error: the arm and fire operation on PCIE failed
    P64H_ERR_DRV_APP_PERIPH_MDIO_NULL_HANDLE,                                                                                                                       ///< Error: a pointer argument to a mdio handle is NULL
    P64H_ERR_DRV_APP_PERIPH_MDIO_NULL_CFG,                                                                                                                          ///< Error: a pointer argument to a mdio configuration is NULL
    P64H_ERR_DRV_APP_PERIPH_MDIO_INVALID_INSTANCE,                                                                                                                  ///< Error: trying to configure an invalid number of mdio instances
    P64H_ERR_DRV_APP_PERIPH_MDIO_AF_ERR,                                                                                                                            ///< Error: trying to configure arm and fire mdio register
    P64H_ERR_DRV_APP_PERIPH_MDIO_IO_ERR,                                                                                                                            ///< Error: mdio operation failed
    P64H_ERR_DRV_APP_PERIPH_SPI_NULL_HANDLE,                                                                                                                        ///< Error: a pointer argument to a spi handle is NULL
    P64H_ERR_DRV_APP_PERIPH_SPI_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to a spi configuration is NULL
    P64H_ERR_DRV_APP_PERIPH_SPI_INVALID_INSTANCE,                                                                                                                   ///< Error: trying to configure an invalid number of spi instances
    P64H_ERR_DRV_APP_PERIPH_SPI_AF_ERR,                                                                                                                             ///< Error: trying to configure arm and fire spi register
    P64H_ERR_DRV_APP_PERIPH_IOMMU_NULL_HANDLE,                                                                                                                      ///< Error: a pointer argument to a iommu handle is NULL
    P64H_ERR_DRV_APP_PERIPH_IOMMU_NULL_CFG,                                                                                                                         ///< Error: a pointer argument to a iommu configuration is NULL
    P64H_ERR_DRV_APP_PERIPH_IOMMU_NULL_WGC_CFG,                                                                                                                     ///< Error: a pointer argument to a iommu wgc configuration is NULL
    P64H_ERR_DRV_APP_PERIPH_IOMMU_INVALID_INSTANCE,                                                                                                                 ///< Error: trying to configure an invalid number of iommu instances
    P64H_ERR_DRV_APP_PERIPH_IOMMU_AF_ERR,                                                                                                                           ///< Error: trying to configure arm and fire iommu register
    P64H_ERR_DRV_APP_PERIPH_NMRA_NULL_HANDLE,                                                                                                                       ///< Error: a pointer argument to a nmra handle is NULL
    P64H_ERR_DRV_APP_PERIPH_NMRA_NULL_CFG,                                                                                                                          ///< Error: a pointer argument to a nmra configuration is NULL
    P64H_ERR_DRV_APP_PERIPH_NMRA_INVALID_INSTANCE,                                                                                                                  ///< Error: trying to configure an invalid number of nmra instances
    P64H_ERR_DRV_APP_PERIPH_NMRA_AF_ERR,                                                                                                                            ///< Error: trying to configure arm and fire nmra register
    P64H_ERR_DRV_APP_PERIPH_USB_NULL_HANDLE,                                                                                                                        ///< Error: a pointer argument to an USB handle is null
    P64H_ERR_DRV_APP_PERIPH_USB_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to an USB configuration is null
    P64H_ERR_DRV_APP_PERIPH_USB_INVALID_INST,                                                                                                                       ///< Error: trying to configure an invalid USB instance
    P64H_ERR_DRV_APP_PERIPH_USB_AF_ERR,                                                                                                                             ///< Error: the arm and fire operation on USB failed
    P64H_ERR_DRV_APP_PERIPH_JTAG_HOST_NULL_HANDLE,                                                                                                                  ///< Error: a pointer argument to an JTAG HOST configuration is null
    P64H_ERR_DRV_APP_PERIPH_JTAG_HOST_NULL_CFG,                                                                                                                     ///< Error: a pointer argument to an JTAG HOST configuration is null
    P64H_ERR_DRV_APP_PERIPH_TRACE_NULL_HANDLE,                                                                                                                      ///< Error: a pointer argument to a trace handle is NULL
    P64H_ERR_DRV_APP_PERIPH_TRACE_AF_ERR,                                                                                                                           ///< Error: trying to configure arm and fire trace register
    P64H_ERR_DRV_APP_PERIPH_USER_CRYPTO_NULL_HANDLE,                                                                                                                ///< Error: a pointer argument to an User Crypto configuration is null
    P64H_ERR_DRV_APP_PERIPH_USER_CRYPTO_NULL_CFG,                                                                                                                   ///< Error returned when a pointer argument to an User Crypto configuration is null.
    P64H_ERR_DRV_DDR_INVALID_INSTANCE                                       = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_DDR),              ///< Error returned when trying to configure an invalid DDR instance (0 or 1 are valid value)
    P64H_ERR_DRV_DDR_PHY_IN_RESET,                                                                                                                                  ///< Error returned when trying to access DDR PHY when it is in reset
    P64H_ERR_DRV_DDR_PHY_INVALID_DQ_WITDH,                                                                                                                          ///< Error returned when trying to cofigure an invalid DDR DQ width
    P64H_ERR_DRV_DDR_DDR_PLL_LOCK_TIMEOUT,                                                                                                                          ///< Error: DDR_PLL failed to lock
    P64H_ERR_DRV_DDR_DDR_DLL_LOCK_TIMEOUT,                                                                                                                          ///< Error: DDR_DLL failed to lock
    P64H_ERR_DRV_TOP_AF_ERR                                                 = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_TOP),              ///< Error returned when trying to configure arm and fire TOP register
    P64H_ERR_DRV_TOP_INVALID_INSTANCE,
    P64H_ERR_DRV_TOP_LOWPOWER_SET_FAILED,
    P64H_ERR_DRV_TOP_LOWPOWER_CLEAR_FAILED,
    P64H_ERR_DRV_TOP_RESET_SET_FAILED,
    P64H_ERR_DRV_TOP_RESET_CLEAR_FAILED,
    P64H_ERR_DRV_TOP_HANDLE_ERROR,                                                                                                                                  ///< handle error
    P64H_ERR_DRV_TOP_INVALID_INST_ID,                                                                                                                               ///< invalid instance id
    P64H_ERR_DRV_TOP_INVALID_NVM_EDAC_MUX,                                                                                                                          ///< Error reported for an invalid NVM Edac mux selection
    P64H_ERR_DRV_TOP_INVALID_CTRL_TYPE,                                                                                                                             ///< Error reported for invalid NVM controller type selection
    P64H_ERR_DRV_TOP_INVALID_CONNECTOR_INSTANCE,                                                                                                                    ///< Error returned when trying to configure an invalid NVM connector instance
    P64H_ERR_DRV_TOP_INVALID_NVM_CTRL_CLK_SEL,                                                                                                                      ///< Error returned when trying to configure an NVM controller clock selection
    P64H_ERR_DRV_TOP_INVALID_NVM_EDAC_CLK_SEL,                                                                                                                      ///< Error returned when trying to configure an NVM EDAC clock selection
    P64H_ERR_DRV_TOP_INVALID_NVM_BCH_CLK_SEL,                                                                                                                       ///< Error returned when trying to configure an NVM BCH clock selection
    P64H_ERR_DRV_TOP_INVALID_ENET_EP_D_CLK_SEL,                                                                                                                     ///< Error returned when trying to configure ENET_EP D_CLK clock source.
    P64H_ERR_DRV_TOP_PSC_INVALID,                                                                                                                                   ///< Error returned when an invalid PSC region is passed as an argument.
    P64H_ERR_DRV_TOP_PSC_TIMEOUT_ERROR,                                                                                                                             ///< Error when a PSC does not powerup/down (PSC_POWERUP_ACK) in timeout period.
    P64H_ERR_DRV_TOP_PSC_STAT_ERROR,                                                                                                                                ///< Error when a PSC_STAT register indicates an error (VOLTAGE_OK!=1).
    P64H_ERR_DRV_NOC_CORE_UNSUPPORTED_EVENT_TYPE                            = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_NOC_CORE),         ///< Unsupported event type
    P64H_ERR_DRV_NOC_CORE_INVALID_OBSERVED_PORT_INDEX,                                                                                                              ///< Invalid observed port index
    P64H_ERR_DRV_NOC_CORE_INVALID_DUMP_SELECTION,                                                                                                                   ///< Invalid selection for statistics dump
    P64H_ERR_DRV_NOC_CORE_INVALID_FILTER_INDEX,                                                                                                                     ///< Invalid filter index
    P64H_ERR_DRV_NOC_CORE_INVALID_TRANS_PROF_MODE,                                                                                                                  ///< Invalid transaction profiling mode
    P64H_ERR_DRV_NOC_CORE_INVALID_SUBSYSTEM,                                                                                                                        ///< Invalid subsystem for trace collection
    P64H_ERR_DRV_NOC_CORE_INVALID_ACTION_PACKET_STAT_COUNTER,                                                                                                       ///< Invalid action for packet counter
    P64H_ERR_DRV_NOC_CORE_INVALID_ACTION_TRANSACTION_STAT_COUNTER,                                                                                                  ///< Invalid action for counter for transaction profiling
    P64H_ERR_DRV_NOC_CORE_INVALID_COUNTER_INDEX,                                                                                                                    ///< Invalid counter index used to observe the port
    P64H_ERR_DRV_NOC_CORE_UNSUPPORTED_TRANS_PROBE_INDEX,                                                                                                            ///< Unsupported transaction probe index
    P64H_ERR_DRV_NOC_CORE_INVALID_TRANSACTION_PROFILING_OP_MODE,                                                                                                    ///< Invalid transaction profiling operation mode
    P64H_ERR_DRV_NOC_CORE_ALL_COUNTERS_OCCUPIED,                                                                                                                    ///< All counters are currently occupied
    P64H_ERR_DRV_NOC_CORE_UNALLOCATED_COUNTER,                                                                                                                      ///< No counters allocated for the event
    P64H_ERR_DRV_NOC_CORE_INVALID_TARG_BITMASK,                                                                                                                     ///< Invalid target bitmask
    P64H_ERR_DRV_NOC_CORE_INVALID_INITIATOR,                                                                                                                        ///< Invalid pm initiator
    P64H_ERR_DRV_NOC_CORE_INVALID_NOC_TYPE,                                                                                                                         ///< Invalid noc type
    P64H_ERR_DRV_NOC_CORE_DRIVER_UNINITIALIZED,                                                                                                                     ///< Noc pm driver uninitialized
    P64H_ERR_DRV_NOC_CORE_COUNTER_OUT_OF_RANGE,                                                                                                                     ///< Counter out of range
    P64H_ERR_DRV_NOC_CORE_INVALID_BASE_ADDRESS,                                                                                                                     ///< Invalid base address
    P64H_ERR_DRV_NOC_CORE_INVALID_STAT_PERIOD,                                                                                                                      ///< Invalid statistic period
    P64H_ERR_DRV_NOC_CORE_INVALID_BIN_INDEX,                                                                                                                        ///< Invalid bin index
    P64H_ERR_DRV_NOC_CORE_TENURE_LINES_LATENCY_OUT_OF_RANGE,                                                                                                        ///< Tenure lines for latency measurements out of range
    P64H_ERR_DRV_NOC_CORE_TENURE_LINES_PENDING_TRANS_OUT_OF_RANGE,                                                                                                  ///< Tenure lines for pending transactions out of range
    P64H_ERR_DRV_NOC_CORE_INVALID_STAT_COLLECTION_TYPE,                                                                                                             ///< Invalid statistics collection type
    P64H_ERR_DRV_NOC_CORE_STAT_ALARM_THRESHOLD_OUT_OF_RANGE,                                                                                                        ///< statistics alarm threshold out of range
    P64H_ERR_DRV_NOC_CORE_INVALID_ASYNC_PERIOD,                                                                                                                     ///< Invalid Async Period
    P64H_ERR_DRV_NOC_CORE_HANDLE_ERROR,                                                                                                                             ///< handle error
    P64H_ERR_DRV_NOC_CORE_CFG_ERROR,                                                                                                                                ///< configuration error
    P64H_ERR_DRV_NOC_CORE_INVALID_PARAM,                                                                                                                            ///< Error: an invalid parameter is passed to a NOC driver functions
    P64H_ERR_DRV_IOBRIDGE_NULL_PARAMS                                       = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_IOBRIDGE),         ///< Error returned when a argument pointer is NULL.
    P64H_ERR_DRV_WGUARD_NULL_WGC_SLOT_CFG                                   = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_WGUARD),           ///< Error returned when a pointer to Wguard checker slot configuration is NULL.
    P64H_ERR_DRV_WGUARD_NULL_WGM_CFG,                                                                                                                               ///< Error returned when a pointer to Wguard marker configuration is NULL.
    P64H_ERR_DRV_WGUARD_NULL_WGM_DID_CFG,                                                                                                                           ///< Error returned when a pointer to Wguard marker DID configuration is NULL.
    P64H_ERR_DRV_WGUARD_NULL_ERR_DATA_CFG,                                                                                                                          ///< Error returned when a pointer to error data configuration is NULL.
    P64H_ERR_DRV_WGUARD_INVALID_SLOT_NUM,                                                                                                                           ///< Error returned when the number of slots is invalid
    P64H_ERR_DRV_WGUARD_INVALID_DID_WID_NUMBER,                                                                                                                     ///< Error returned when trying to configure invalid number of did-wid entries
    P64H_ERR_DRV_WGUARD_OUT_OF_RANGE_SLOT_IDX,                                                                                                                      ///< Error returned when trying to provision/deprovision an out of range WG slot.
    P64H_ERR_DRV_WGUARD_INVALID_ERROR_STATE,                                                                                                                        ///< Interrupt indicates error but register shows neither read nor write fault.
    P64H_ERR_DRV_ACSU_NULL_HANDLE                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_ACSU),             ///< Error: a pointer argument to an ACSU handle is null
    P64H_ERR_DRV_ACSU_INVALID_PRESET,                                                                                                                               ///< Error: trying to configure an ACSU with invalid preset
    P64H_ERR_DRV_ACSU_INVALID_INST,                                                                                                                                 ///< Error: trying to configure an invalid ACSU instance
    P64H_ERR_DRV_ACSU_PLL_LOCK_TIMEOUT,                                                                                                                             ///< Error: ACSU PLL did not achieve lock before the timeout occurred
    P64H_ERR_DRV_ACSU_PLL_OFFSETCAL_LOCK_TIMEOUT,                                                                                                                   ///< Error: ACSU PLL offset calibration did not achieve lock before the timeout occurred
    P64H_ERR_DRV_ACSU_ACSU_NOT_INITIALIZED,                                                                                                                         ///< Error: an ACSU API is called while ACSU is in reset (uninitialized)
    P64H_ERR_DRV_ACSU_INVALID_CLOCK_OUTPUT_INDEX,                                                                                                                   ///< Error: an invalid index is provided for selecting a clock output
    P64H_ERR_DRV_ACSU_OUT_OF_RANGE_POST_DIV_VALUE,                                                                                                                  ///< Error: trying to configure the ACSU output post divider with out of range value
    P64H_ERR_DRV_PGMRCLK_NULL_CFG                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_PGMRCLK),          ///< Error: a pointer argument to an PGMRCLK configuration is null
    P64H_ERR_DRV_PGMRCLK_INVALID_CLOCK_ID,                                                                                                                          ///< Error: an invalid identifier is provided for a PGMRCLK clock
    P64H_ERR_DRV_PGMRCLK_FREQUENCY_NOT_SUPPORTED,                                                                                                                   ///< Error: an invalid value is provided for clock desired frequency
    P64H_ERR_DRV_CFM_MEAS_DISABLED                                          = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_CFM),              ///< Error: CFM measurement is disabled
    P64H_ERR_DRV_CFM_INVALID_INST,                                                                                                                                  ///< Error: an invalid instance is provided for a CFM
    P64H_ERR_DRV_CFM_INVALID_CHNL,                                                                                                                                  ///< Error: an invalid channel is provided for a CFM
    P64H_ERR_DRV_CFM_INVALID_CFG,                                                                                                                                   ///< Error: an invalid configuration is provided for a CFM
    P64H_ERR_DRV_CFM_BUSY_MONITORING,                                                                                                                               ///< Error: CFM is active
    P64H_ERR_DRV_APP_IPC_NULL_HANDLE                                        = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_APP_IPC),          ///< Error: a pointer argument to an IPC handle is NULL
    P64H_ERR_DRV_DDR_CTRL_NULL_HANDLE                                       = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_DDR_CTRL),         ///< Error: a pointer argument to a ddr_ctrl handle is NULL
    P64H_ERR_DRV_DDR_CTRL_UNSUPPORTED_TYPE,                                                                                                                         ///< Error: DDR is configured for an unsupported type
    P64H_ERR_DRV_DDR_CTRL_INVALID_CTRL_INSTANCE,                                                                                                                    ///< Error: trying to configure an invalid CTRL instance
    P64H_ERR_DRV_DDR_EDAC_INVALID_FEC_MODE                                  = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_DDR_EDAC),         ///< Error: trying to configure an invalid FEC mode
    P64H_ERR_DRV_DDR_EDAC_INVALID_READ_PERIOD,                                                                                                                      ///< Error: trying to configure an invalid period of rests
    P64H_ERR_DRV_DDR_EDAC_INVALID_WDRESP_VAL,                                                                                                                       ///< Error: trying to configure an invalid write response timeout
    P64H_ERR_DRV_DDR_EDAC_INVALID_WDGEN_VAL,                                                                                                                        ///< Error: trying to configure an invalid write data timeout
    P64H_ERR_DRV_DDR_EDAC_INVALID_WCMD_VAL,                                                                                                                         ///< Error: trying to configure an invalid write request timeout
    P64H_ERR_DRV_DDR_EDAC_INVALID_RDCAP_VAL,                                                                                                                        ///< Error: trying to configure an invalid read data timeout
    P64H_ERR_DRV_DDR_EDAC_INVALID_RCMD_VAL,                                                                                                                         ///< Error: trying to configure an invalid read request timeout
    P64H_ERR_DRV_DMA_NULL_POINTER                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_DMA),              ///< Error: a pointer argument is NULL
    P64H_ERR_DRV_DMA_INVALID_MASK,                                                                                                                                  ///< Error: the mask value is invalid
    P64H_ERR_DRV_DMA_TIMEOUT,                                                                                                                                       ///< Error: time is out
    P64H_ERR_DRV_DMA_INVALID_TYPE,                                                                                                                                  ///< Error: the type is invalid
    P64H_ERR_DRV_DMA_MEMORY_ALLOCATION_FAILURE,                                                                                                                     ///< Error: the memory allocation failed
    P64H_ERR_DRV_DMA_UNIMPLEMENTED,                                                                                                                                 ///< Error: the function called is unimplemented
    P64H_ERR_DRV_DMA_INVALID_ARG,                                                                                                                                   ///< Error: the argument is invalid
    P64H_ERR_DRV_DMA_DMAC_CHID_OUT_OF_RANGE_ERR,                                                                                                                    ///< Error: The select channel id is does not exist
    P64H_ERR_DRV_DMA_DMAC_XFER_DONE_FAIL,                                                                                                                           ///< Error: DMA transfer failed to complete
    P64H_ERR_DRV_DMA_DMAC_BLK_XFER_FAIL,                                                                                                                            ///< Error: DMA block transfer failed
    P64H_ERR_DRV_OCR_FIFO_MEL_RD_ERR                                        = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_OCR),              ///< Error: unable to read from the OCR Memory Error Logger FIFO
    P64H_ERR_DRV_OCR_INIT_BUSY,                                                                                                                                     ///< Error: OCR Memory block is performing initialization and is not accessible
    P64H_ERR_DRV_OCR_INIT_FAIL,                                                                                                                                     ///< init_fail
    P64H_ERR_DRV_OCR_INVALID_PARAM,                                                                                                                                 ///< Error: an invalid parameter is passed to a OCR driver functions
    P64H_ERR_DRV_SERDES_IF_ERR                                              = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_SERDES_IF),        ///< Error returned for failure cases that do not have unique error codes
    P64H_ERR_DRV_SERDES_IF_INVALID_LANE,                                                                                                                            ///< Error: driver functions are called with a lane parameter larger than the number of lanes on the device
    P64H_ERR_DRV_SERDES_IF_INVALID_RATE,                                                                                                                            ///< Error: driver functions are called with a rate outside the approved rates for the device
    P64H_ERR_DRV_SERDES_IF_INVALID_LPBK,                                                                                                                            ///< Error: driver functions are called with a loopback configuration that is not supported by the device
    P64H_ERR_DRV_SERDES_IF_CALIBRATION_TIMEOUT,                                                                                                                     ///< Error: calibration takes longer to happen than the specified timeout
    P64H_ERR_DRV_SERDES_IF_INVALID_AN_CFG,                                                                                                                          ///< Error: static configuration method is called with an impossible AN configuration
    P64H_ERR_DRV_SERDES_IF_TXPLL_AT_DIFFERENT_FVCO,                                                                                                                 ///< Error: attempting to configure a lane in a bank to a different FVco while a different lane in that bank is already utilizing that FVco
    P64H_ERR_DRV_SERDES_IF_TXPLL_LOCK_TIMEOUT,                                                                                                                      ///< Error: lock takes longer to happen than the specified timeout
    P64H_ERR_DRV_ANLT_ERR                                                   = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_ANLT),             ///< Error returned for failure cases that do not have unique error codes
    P64H_ERR_DRV_ANLT_FAILED_LOOKUP,                                                                                                                                ///< Error: a lookup into an array has failed, either due to the index being too large, or the entry in the array being nonsensical
    P64H_ERR_DRV_ANLT_INVALID_AN_ARB_STATE,                                                                                                                         ///< Error: an invalid AN Arbitration State Enum is passed into a function
    P64H_ERR_DRV_M1_CORE_APB2JTAG_NULL_HANDLE                               = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_M1_CORE),          ///< Error: a pointer argument to a APB2JTAG handle is NULL
    P64H_ERR_DRV_M1_CORE_APB2JTAG_NULL_CFG,                                                                                                                         ///< Error: a pointer argument to a APB2JTAG config is NULL
    P64H_ERR_DRV_M1_CORE_APB2JTAG_CFG_INVALID_NBITS,                                                                                                                ///< Error: APB2JTAG config NBITS exceeds M1_CORE_APB2JTAG_MAX_BITS
    P64H_ERR_DRV_M1_CORE_APB2JTAG_CFG_INVALID_NSHIFTS,                                                                                                              ///< Error: APB2JTAG config NSHIFTS exceeds M1_CORE_APB2JTAG_MAX_SHIFTS
    P64H_ERR_DRV_M1_CORE_APB2JTAG_CFG_INVALID_OPCODE,                                                                                                               ///< Error: APB2JTAG config OPCODE_SEL exceeds M1_CORE_APB2JTAG_MAX_OPCODE_SEL
    P64H_ERR_DRV_M1_CORE_APB2JTAG_CFG_INVALID_SELECT_TYPE,                                                                                                          ///< Error: APB2JTAG config SELECT_TYPE exceeds M1_CORE_APB2JTAG_MAX_SELECT_TYPE
    P64H_ERR_DRV_M1_CORE_APB2JTAG_FSM_ERR,                                                                                                                          ///< Error: A2J_ERROR_I2=1 during APB2JTAG access
    P64H_ERR_DRV_M1_CORE_APB2JTAG_TDO_MISCOMPARE,                                                                                                                   ///< Error: both APB2JTAG TDO read/checking are enabled and TDO miscompare between read/expected
    P64H_ERR_DRV_M1_CORE_NULL_HANDLE,                                                                                                                               ///< Error: a pointer argument to a M1 CORE handle is NULL
    P64H_ERR_DRV_M1_CORE_FW_PLL_NULL_CFG,                                                                                                                           ///< Error: a pointer argument to a FW PLL config is NULL
    P64H_ERR_DRV_SYS_TOP_AF_ERR                                             = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_SYS_TOP),          ///< Error: trying to configure arm and fire SYS TOP register
    P64H_ERR_DRV_SYS_TOP_INVALID_REGISTER,                                                                                                                          ///< Error: register arguement does not exist
    P64H_ERR_DRV_SYS_TOP_NULL_RETURN,                                                                                                                               ///< Error: a pointer to the result is NULL
    P64H_ERR_DRV_SYS_TOP_HANDLE_ERROR,                                                                                                                              ///< handle error
    P64H_ERR_DRV_SYS_TOP_CFG_ERROR,                                                                                                                                 ///< configuration error
    P64H_ERR_DRV_SYS_SPI_FLASH_CFG_NULL                                     = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_SYS_SPI_FLASH),    ///< Error: a pointer argument to a SYS SPI Flash configuration is NULL
    P64H_ERR_DRV_SYS_SPI_FLASH_INIT_ERR,                                                                                                                            ///< Error: SYS SPI Flash initialization failed
    P64H_ERR_DRV_SYS_SPI_FLASH_PROG_ERR,                                                                                                                            ///< Error: SYS SPI Flash program failed
    P64H_ERR_DRV_SYS_SPI_FLASH_READ_ERR,                                                                                                                            ///< Error: SYS SPI Flash read failed
    P64H_ERR_DRV_SYS_SPI_FLASH_ERASE_ERR,                                                                                                                           ///< Error: SYS SPI Flash erase failed
    P64H_ERR_DRV_SYS_HPT_INVALID_PARAM                                      = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_SYS_HPT),          ///< Error: hpt arguement invalid
    P64H_ERR_DRV_SYS_HPT_EXCEED_MAX_LOOP,                                                                                                                           ///< Error: MAX loop reached
    P64H_ERR_DRV_SYS_HPT_MTIME_ERROR,                                                                                                                               ///< Error returned when read mtime.
    P64H_ERR_DRV_NVM_CTRL_AF_ERR                                            = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_NVM),              ///< Error: trying to configure arm and fire NVM CTRL register
    P64H_ERR_DRV_NVM_SS_NULL_HANDLE,                                                                                                                                ///< Error: a pointer argument to a NVM handle is NULL
    P64H_ERR_DRV_NVM_CFG_NULL,                                                                                                                                      ///< Error: a pointer argument to a NVM configuration is NULL
    P64H_ERR_DRV_NVM_INVALID_CTRL_INSTANCE,                                                                                                                         ///< Error: trying to configure an invalid NVM controller instance
    P64H_ERR_DRV_NVM_INVALID_CTRL_TYPE,                                                                                                                             ///< Error: trying to configure an invalid NVM controller type
    P64H_ERR_DRV_NVM_INVALID_EDAC_INSTANCE,                                                                                                                         ///< Error: trying to configure an invalid EDAC instance
    P64H_ERR_DRV_NVM_PFLASH_CTRL_UNSUPPORTED_DATA_WIDTH,                                                                                                            ///< Error return when trying to configure pflash unsupported data width
    P64H_ERR_DRV_NVM_PFLASH_CTRL_DEVICE_READY_TIMEOUT,                                                                                                              ///< Error return when pflash device ready times out
    P64H_ERR_DRV_NVM_PFLASH_CTRL_WRITE_BUFFER_NULL,                                                                                                                 ///< Error return when trying to load program data with null write buffer for write buffer program
    P64H_ERR_DRV_NVM_INVALID_XSPI_INSTANCE,                                                                                                                         ///< Error: trying to configure an invalid XSPI instance
    P64H_ERR_DRV_NVM_XSPI_PROBE,                                                                                                                                    ///< Error: trying to probe XSPI controller
    P64H_ERR_DRV_NVM_XSPI_INIT,                                                                                                                                     ///< Error: trying to init XSPI controller
    P64H_ERR_DRV_NVM_XSPI_START,                                                                                                                                    ///< Error returned when trying to start the XSPI controller
    P64H_ERR_DRV_NVM_XSPI_GET_CB,                                                                                                                                   ///< Error returned when trying to get Callbacks for the XSPI controller
    P64H_ERR_DRV_NVM_XSPI_SET_CB,                                                                                                                                   ///< Error returned when trying to set Callbacks for the XSPI controller
    P64H_ERR_DRV_NVM_XSPI_GET_EVENT,                                                                                                                                ///< Error returned when trying to get the Events for the XSPI controller
    P64H_ERR_DRV_NVM_XSPI_SET_EVENT,                                                                                                                                ///< Error returned when trying to set the Events for the XSPI controller
    P64H_ERR_DRV_NVM_XSPI_GET_DIRECT_MODE_CONFIG,                                                                                                                   ///< Error returned when trying to get the direct mode config from the XSPI controller inst
    P64H_ERR_DRV_NVM_XSPI_GET_WORK_MODE_CONFIG,                                                                                                                     ///< Error returned when trying to get work mode config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_WORK_MODE_CONFIG_INVALID,                                                                                                             ///< Error returned when trying to set work mode config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_WORK_MODE_CONFIG_BUSY,                                                                                                                ///< Error returned when trying to set work mode config from the XSPI controller inst; Error is controller busy
    P64H_ERR_DRV_NVM_XSPI_SEND_STIG_COMMAND,                                                                                                                        ///< Error returned when trying to send the stig command to the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_GET_STIG_STATUS,                                                                                                                          ///< Error returned when trying to get the set work mode config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_DIRECT_MODE_CONFIG,                                                                                                                   ///< Error returned when trying to set the direct mode config from the XSPI controller inst
    P64H_ERR_DRV_NVM_XSPI_GET_GLOBAL_CMD_PARAMS,                                                                                                                    ///< Error returned when trying to get global command parameters from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_GLOBAL_CMD_PARAMS,                                                                                                                    ///< Error returned when trying to set global command parameters from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_GET_PROGRAM_SEQ_P1_CONFIG,                                                                                                                ///< Error returned when trying to get program sequence profile 1 config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_PROGRAM_SEQ_P1_CONFIG,                                                                                                                ///< Error returned when trying to set program sequence profile 1 config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_GET_READ_SEQ_P1_CONFIG,                                                                                                                   ///< Error returned when trying to get read sequence profile 1 config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_READ_SEQ_P1_CONFIG,                                                                                                                   ///< Error returned when trying to set read sequence profile 1 config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_GET_COMM_STAT_SEQ_CONFIG,                                                                                                                 ///< Error returned when trying to get common status sequence configuration from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_COMM_STAT_SEQ_CONFIG,                                                                                                                 ///< Error returned when trying to set common status sequence configuration from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_GET_STAT_SEQ_P1_CONFIG,                                                                                                                   ///< Error returned when trying to get status sequence profile 1 config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_STAT_SEQ_P1_CONFIG,                                                                                                                   ///< Error returned when trying to set status sequence profile 1 config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_GET_WEL_SEQ_CONFIG,                                                                                                                       ///< Error returned when trying to get write enable sequence config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_SET_WEL_SEQ_CONFIG,                                                                                                                       ///< Error returned when trying to set write enable sequence config from the XSPI controller inst; Error is invalid pointer
    P64H_ERR_DRV_NVM_XSPI_ENABLE_DIRECT_MODE,                                                                                                                       ///< Error returned when trying to enable direct mode in the XSPI controller inst
    P64H_ERR_DRV_NVM_XSPI_ENABLE_STIG_MODE,                                                                                                                         ///< Error returned when trying to enable stig mode in the XSPI controller inst
    P64H_ERR_DRV_NVM_XSPI_CONVERT_NUM_IOS,                                                                                                                          ///< Error returned when trying to convert the p64h number of ios enum to the XSPI enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_DATA_EDGE_MODE,                                                                                                                   ///< Error returned when trying to convert the p64h edge mode enum to the XSPI data edge enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_ADDR_EDGE_MODE,                                                                                                                   ///< Error returned when trying to convert the p64h edge mode enum to the XSPI addr edge enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_CMD_EDGE_MODE,                                                                                                                    ///< Error returned when trying to convert the p64h edge mode enum to the XSPI cmd edge enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_CMD_WORD_SIZE,                                                                                                                    ///< Error returned when trying to convert the p64h word size enum to the XSPI cmd word size enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_STAT_POLARITY,                                                                                                                    ///< Error returned when trying to convert the p64h status polarity enum to the XSPI status polarity enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_SEQ_TYPE,                                                                                                                         ///< Error returned when trying to convert the p64h sequence type enum to the XSPI sequence type enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_CRC_CHUNK_SIZE,                                                                                                                   ///< Error returned when trying to convert the p64h crc chunk size enum to the XSPI crc chunk size enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_CRC_VARIANT,                                                                                                                      ///< Error returned when trying to convert the p64h crc variant enum to the XSPI crc variant enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_DATA_PER_ADDR,                                                                                                                    ///< Error returned when trying to convert the p64h data per address enum to the XSPI data per address enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_STAT_ADDR_COUNT,                                                                                                                  ///< Error returned when trying to convert the p64h status sequence address count enum to the XSPI status sequence address count enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_PROGRAM_PAGE_SIZE,                                                                                                                ///< Error returned when trying to convert the p64h program page size enum to the XSPI program page size enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_READ_PAGE_SIZE,                                                                                                                   ///< Error returned when trying to convert the p64h read page size enum to the XSPI read page size enum
    P64H_ERR_DRV_NVM_XSPI_CONVERT_P1_STIG_INSTR,                                                                                                                    ///< Error returned when trying to convert the p64h profile 1 stig instruction enum to the XSPI profile 1 stig instruction enum
    P64H_ERR_DRV_NVM_INVALID_CCP_INSTANCE,                                                                                                                          ///< Error: trying to configure an invalid XSPI CCP instance
    P64H_ERR_DRV_NVM_XSPI_CCP_PROBE,                                                                                                                                ///< Error: trying to probe XSPI CCP
    P64H_ERR_DRV_NVM_XSPI_CCP_INIT,                                                                                                                                 ///< Error: trying to init XSPI CCP
    P64H_ERR_DRV_NVM_DIAG_TEST_FAIL,                                                                                                                                ///< Error: Diagnostic Test Failed
    P64H_ERR_DRV_EDAC_NULL_HANDLE                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_EDAC),             ///< Error: a pointer argument to an EDAC handle is NULL
    P64H_ERR_DRV_EDAC_INVALID_CFG,                                                                                                                                  ///< Error: the EDAC configuration is invalid
    P64H_ERR_DRV_EDAC_INVALID_EDAC_INSTANCE,                                                                                                                        ///< Error: trying to configure an invalid EDAC instance
    P64H_ERR_DRV_EDAC_EMON_RD_TIMEOUT,                                                                                                                              ///< Error returned on timeout when trying to read EDAC error monitor
    P64H_ERR_DRV_GPIO_NULL_HANDLE                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_GPIO),             ///< Error: a pointer argument to an GPIO handle is NULL
    P64H_ERR_DRV_GPIO_INVALID_PIN_INDEX,                                                                                                                            ///< Error: trying to configure an invalid pin index
    P64H_ERR_DRV_X288_RAS_NO_SIGNAL                                         = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_X288_RAS),         ///< No errors active in the error map since no signal was logged to the signal status register
    P64H_ERR_DRV_X288_RAS_INVALID_INST_ID,                                                                                                                          ///< Error bank instance ID from registers is invalid
    P64H_ERR_DRV_ARM_N_FIRE_NULL_HANDLE                                     = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_DRV_ARM_N_FIRE),       ///< Error: a pointer argument to an handle is NULL
    P64H_ERR_DRV_ARM_N_FIRE_OPERATION_FAIL,                                                                                                                         ///< Error: arm and fire operation failed
    P64H_ERR_DRV_ARM_N_FIRE_UNKNOWN_ERROR,                                                                                                                          ///< Error: no related arm and fire operation error found
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TEMP_MON_L,                                                                                                              ///< Error: signature TOP2_TEMP_MON_L mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TEMP_MON_R,                                                                                                              ///< Error: signature TOP2_TEMP_MON_R mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_M1_SOK_CORE_PCBI,                                                                                                        ///< Error: signature TOP2_M1_SOK_CORE_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO0,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO1,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO2,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO3,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO4,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO4 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO5,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO5 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO6,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO6 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP2_TOP_IOB_GPIO7,                                                                                                           ///< Error: signature TOP2_TOP_IOB_GPIO7 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_E0,                                                                                                                  ///< Error: signature TOP3_SHI_E0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_E1,                                                                                                                  ///< Error: signature TOP3_SHI_E1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_S3,                                                                                                                  ///< Error: signature TOP3_SHI_S3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_S2,                                                                                                                  ///< Error: signature TOP3_SHI_S2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_S1,                                                                                                                  ///< Error: signature TOP3_SHI_S1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_S0,                                                                                                                  ///< Error: signature TOP3_SHI_S0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SHI_HT,                                                                                                                  ///< Error: signature TOP3_SHI_HT mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_APP_ACSU,                                                                                                                ///< Error: signature TOP3_APP_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_EDGE_CURR_TOP,                                                                                                           ///< Error: signature TOP3_EDGE_CURR_TOP mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_EDGE_CURR_BOTTOM,                                                                                                        ///< Error: signature TOP3_EDGE_CURR_BOTTOM mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP3_SYS_ACSU,                                                                                                                ///< Error: signature TOP3_SYS_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_ETH_ENET_EP_SS_SVC,                                                                                                           ///< Error: signature ETH_ENET_EP_SS_SVC mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_ETH_ENET_SWR_SS_SVC,                                                                                                          ///< Error: signature ETH_ENET_SWR_SS_SVC mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_DDR_EDAC0,                                                                                                                ///< Error: signature DDR_DDR_EDAC0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_DDR_EDAC1,                                                                                                                ///< Error: signature DDR_DDR_EDAC1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_IOB_HSIO_SOK0,                                                                                                            ///< Error: signature DDR_IOB_HSIO_SOK0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_IOB_HSIO_SOK1,                                                                                                            ///< Error: signature DDR_IOB_HSIO_SOK1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_IOB_HSIO_SOK2,                                                                                                            ///< Error: signature DDR_IOB_HSIO_SOK2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_IOB_HSIO_SOK3,                                                                                                            ///< Error: signature DDR_IOB_HSIO_SOK3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_IOB_HSIO_SOK4,                                                                                                            ///< Error: signature DDR_IOB_HSIO_SOK4 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_DDR_CTRL0,                                                                                                                ///< Error: signature DDR_DDR_CTRL0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_DDR_CTRL1,                                                                                                                ///< Error: signature DDR_DDR_CTRL1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_DDR_NOC,                                                                                                                  ///< Error: signature DDR_DDR_NOC mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_DDR_DDR_PHY_SOK,                                                                                                              ///< Error: signature DDR_DDR_PHY_SOK mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_NVM_CTRL0,                                                                                                                ///< Error: signature NVM_NVM_CTRL0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_NVM_CTRL1,                                                                                                                ///< Error: signature NVM_NVM_CTRL1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_NVM_CTRL2,                                                                                                                ///< Error: signature NVM_NVM_CTRL2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_NVM_CTRL3,                                                                                                                ///< Error: signature NVM_NVM_CTRL3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_SRAM_EDAC0,                                                                                                               ///< Error: signature NVM_SRAM_EDAC0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_SRAM_EDAC1,                                                                                                               ///< Error: signature NVM_SRAM_EDAC1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_SRAM_EDAC2,                                                                                                               ///< Error: signature NVM_SRAM_EDAC2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_NVM_EDAC1,                                                                                                                ///< Error: signature NVM_NVM_EDAC1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_NVM_EDAC0,                                                                                                                ///< Error: signature NVM_NVM_EDAC0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB0,                                                                                                                     ///< Error: signature NVM_IOB0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB1,                                                                                                                     ///< Error: signature NVM_IOB1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB2,                                                                                                                     ///< Error: signature NVM_IOB2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB3,                                                                                                                     ///< Error: signature NVM_IOB3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB4,                                                                                                                     ///< Error: signature NVM_IOB4 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB5,                                                                                                                     ///< Error: signature NVM_IOB5 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB6,                                                                                                                     ///< Error: signature NVM_IOB6 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_NVM_IOB7,                                                                                                                     ///< Error: signature NVM_IOB7 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SYSC_SYSREG,                                                                                                              ///< Error: signature SUP_SYSC_SYSREG mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SYSC_WDT,                                                                                                                 ///< Error: signature SUP_SYSC_WDT mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SRAM_EDAC_GSB,                                                                                                            ///< Error: signature SUP_SRAM_EDAC_GSB mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SYS_OCR,                                                                                                                  ///< Error: signature SUP_SYS_OCR mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_DDR_ENCRYPTOR,                                                                                                            ///< Error: signature SUP_DDR_ENCRYPTOR mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_USER_CRYPTO_GSB,                                                                                                          ///< Error: signature SUP_USER_CRYPTO_GSB mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SYSC_HPT,                                                                                                                 ///< Error: signature SUP_SYSC_HPT mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SYSC_ELT,                                                                                                                 ///< Error: signature SUP_SYSC_ELT mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_PQ_CRYPTO_CFG,                                                                                                            ///< Error: signature SUP_PQ_CRYPTO_CFG mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_GPIO_SOK,                                                                                                                 ///< Error: signature SUP_GPIO_SOK mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_OCR0,                                                                                                                ///< Error: signature SUP_APPC_OCR0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_OCR1,                                                                                                                ///< Error: signature SUP_APPC_OCR1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_PQRAM_OCR,                                                                                                                ///< Error: signature SUP_PQRAM_OCR mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SECC_OCR,                                                                                                                 ///< Error: signature SUP_SECC_OCR mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SEC_S7_OCR,                                                                                                               ///< Error: signature SUP_SEC_S7_OCR mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SPI_CTRL_TPGM,                                                                                                            ///< Error: signature SUP_SPI_CTRL_TPGM mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SECC_SECREGS,                                                                                                             ///< Error: signature SUP_SECC_SECREGS mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SECC_WDT,                                                                                                                 ///< Error: signature SUP_SECC_WDT mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_SECC_HPT,                                                                                                                 ///< Error: signature SUP_SECC_HPT mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT0,                                                                                                                ///< Error: signature SUP_APPC_WDT0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT1,                                                                                                                ///< Error: signature SUP_APPC_WDT1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT2,                                                                                                                ///< Error: signature SUP_APPC_WDT2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT3,                                                                                                                ///< Error: signature SUP_APPC_WDT3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT4,                                                                                                                ///< Error: signature SUP_APPC_WDT4 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT5,                                                                                                                ///< Error: signature SUP_APPC_WDT5 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT6,                                                                                                                ///< Error: signature SUP_APPC_WDT6 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_WDT7,                                                                                                                ///< Error: signature SUP_APPC_WDT7 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT0,                                                                                                                ///< Error: signature SUP_APPC_HPT0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT1,                                                                                                                ///< Error: signature SUP_APPC_HPT1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT2,                                                                                                                ///< Error: signature SUP_APPC_HPT2 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT3,                                                                                                                ///< Error: signature SUP_APPC_HPT3 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT4,                                                                                                                ///< Error: signature SUP_APPC_HPT4 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT5,                                                                                                                ///< Error: signature SUP_APPC_HPT5 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT6,                                                                                                                ///< Error: signature SUP_APPC_HPT6 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APPC_HPT7,                                                                                                                ///< Error: signature SUP_APPC_HPT7 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APP_DMA_CFG0,                                                                                                             ///< Error: signature SUP_APP_DMA_CFG0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APP_DMA_GSB0,                                                                                                             ///< Error: signature SUP_APP_DMA_GSB0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APP_DMA_CFG1,                                                                                                             ///< Error: signature SUP_APP_DMA_CFG1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_SUP_APP_DMA_GSB1,                                                                                                             ///< Error: signature SUP_APP_DMA_GSB1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_PCIE_CXL_WRAP0_PCIE_CXL,                                                                                                  ///< Error: signature APP_PCIE_CXL_WRAP0_PCIE_CXL mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_PCIE_CXL_WRAP0_SHI_SOK0,                                                                                                  ///< Error: signature APP_PCIE_CXL_WRAP0_SHI_SOK0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_PCIE_CXL_WRAP0_SHI_SOK1,                                                                                                  ///< Error: signature APP_PCIE_CXL_WRAP0_SHI_SOK1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_PCIE_CXL_WRAP1_PCIE_CXL,                                                                                                  ///< Error: signature APP_PCIE_CXL_WRAP1_PCIE_CXL mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_PCIE_CXL_WRAP1_SHI_SOK0,                                                                                                  ///< Error: signature APP_PCIE_CXL_WRAP1_SHI_SOK0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_PCIE_CXL_WRAP1_SHI_SOK1,                                                                                                  ///< Error: signature APP_PCIE_CXL_WRAP1_SHI_SOK1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_APP_WRAP,                                                                                                                 ///< Error: signature APP_APP_WRAP mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_IO_BRIDGE,                                                                                                                ///< Error: signature APP_IO_BRIDGE mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_IOMMU,                                                                                                                    ///< Error: signature APP_IOMMU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_APP_IO_BRIDGEPG,                                                                                                              ///< Error: signature APP_IO_BRIDGEPG mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_SYS0_ACSU,                                                                                                               ///< Error: signature TOP1_SYS0_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_APP_GPIO_SOK0,                                                                                                           ///< Error: signature TOP1_APP_GPIO_SOK0 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_APP_GPIO_SOK1,                                                                                                           ///< Error: signature TOP1_APP_GPIO_SOK1 mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_SYS1_ACSU,                                                                                                               ///< Error: signature TOP1_SYS1_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_CPU_ACSU,                                                                                                                ///< Error: signature TOP1_CPU_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_SEC_ACSU,                                                                                                                ///< Error: signature TOP1_SEC_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_ENET_ACSU,                                                                                                               ///< Error: signature TOP1_ENET_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_NVM0_ACSU,                                                                                                               ///< Error: signature TOP1_NVM0_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_NVM1_ACSU,                                                                                                               ///< Error: signature TOP1_NVM1_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_NVM2_ACSU,                                                                                                               ///< Error: signature TOP1_NVM2_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_TOP_TCSR_PCBI,                                                                                                           ///< Error: signature TOP1_TOP_TCSR_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_TOP_MCSR_PCBI,                                                                                                           ///< Error: signature TOP1_TOP_MCSR_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_TOP_LCSR_PCBI,                                                                                                           ///< Error: signature TOP1_TOP_LCSR_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_TOP_RCSR_PCBI,                                                                                                           ///< Error: signature TOP1_TOP_RCSR_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_M2_MISC_SVC_NOC_PCBI,                                                                                                    ///< Error: signature TOP1_M2_MISC_SVC_NOC_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_M2_MISC_APP_NOC_PCBI,                                                                                                    ///< Error: signature TOP1_M2_MISC_APP_NOC_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_M3_SVC_NOC_PCBI,                                                                                                         ///< Error: signature TOP1_M3_SVC_NOC_PCBI mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_EDAC_ACSU,                                                                                                               ///< Error: signature TOP1_EDAC_ACSU mismatches
    P64H_ERR_DRV_ARM_N_FIRE_SIGNATURE_TOP1_M1_SOK_SECC_PCBI,                                                                                                        ///< Error: signature TOP1_M1_SOK_SECC_PCBI mismatches
    P64H_ERR_LIB_POWER_CFG_ERROR                                            = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_POWER),            ///< configuration error
    P64H_ERR_LIB_POWER_HANDLE_ERROR,                                                                                                                                ///< handle error
    P64H_ERR_LIB_POWER_UNSUPPORTED_BOOT_SRC,                                                                                                                        ///< unsupported boot source
    P64H_ERR_LIB_POWER_INVALID_ACSU_CLK,                                                                                                                            ///< Error returned when trying to configure Invalid ACSU clock
    P64H_ERR_LIB_POWER_INVALID_NVM_CTRL,                                                                                                                            ///< Error returned when trying to configure invalid NVM controller
    P64H_ERR_LIB_USR_CRYPTO_NULL_CFG                                        = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_USR_CRYPTO),       ///< Error returned when a pointer argument to a configuration is NULL.
    P64H_ERR_LIB_USR_CRYPTO_NULL_HANDLE,                                                                                                                            ///< Error returned when a pointer argument to a handle is NULL.
    P64H_ERR_LIB_USR_CRYPTO_INIT_ERR,                                                                                                                               ///< Error returned due to crypto blocks(SHA, AES, EC, KeyGuard) init &/or  root key gen failure.
    P64H_ERR_LIB_USR_CRYPTO_SKC_SUCCESS,                                                                                                                            ///< skc crypto API passed
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_TIMEOUT,                                                                                                                         ///< KeyGuard external interface timeout
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_KEY_MISMATCH,                                                                                                                    ///< Key destination does not match key use type
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_SRC_UNAVAIL,                                                                                                                     ///< Key load source is not available
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_DST_UNAVAIL,                                                                                                                     ///< Key distribute destination is not available
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_SCRATCH_SMALL,                                                                                                                   ///< Scratch I/O is too small for the operation size
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_STATE_ERR,                                                                                                                       ///< Current state does not allow requested operation
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_UNWRAP_INVALID,                                                                                                                  ///< Key unwrap operation resulted in an invalid key
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_NO_EXPORT,                                                                                                                       ///< KeyGuard selected key cannot be exported
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_OPSEL_UNAVAIL,                                                                                                                   ///< KeyGuard operation is not available
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_OPMODE_UNAVAIL,                                                                                                                  ///< KeyGuard mode for the given operation is not available
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_NO_ALLOC,                                                                                                                        ///< KeyGuard key load cannot allocate the given KID with the requested size
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_KID_INVALID,                                                                                                                     ///< KeyGuard KID invalid
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_PURGECHK_FAIL,                                                                                                                   ///< KeyGuard purge verification failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_NRBG_HEALTH,                                                                                                                     ///< KeyGuard NRBG health monitoring error
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_MAC_INVALID,                                                                                                                     ///< KeyGuard encrypted key store MAC validation error
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_NO_CLEAR,                                                                                                                        ///< KeyGuard cannot clear the given KID. It either has the NOCLEAR attribute, or is a root key
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_KATTR_INVALID,                                                                                                                   ///< The requested attributes are invalid for the given operation
    P64H_ERR_LIB_USR_CRYPTO_SKC_KG_KSIZE_INVALID,                                                                                                                   ///< The requested key size is invalid for given operation
    P64H_ERR_LIB_USR_CRYPTO_SKC_POST_FAIL,                                                                                                                          ///< Power-on self-test failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_POST_NRBG_ZERO,                                                                                                                     ///< Zero bits in POST NRGB data
    P64H_ERR_LIB_USR_CRYPTO_SKC_BUSY,                                                                                                                               ///< Busy
    P64H_ERR_LIB_USR_CRYPTO_SKC_NOPEND,                                                                                                                             ///< No pending operation
    P64H_ERR_LIB_USR_CRYPTO_SKC_INI_FAIL,                                                                                                                           ///< Initialization failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_INI_BADCORE,                                                                                                                        ///< Initialization failed - bad core type
    P64H_ERR_LIB_USR_CRYPTO_SKC_INI_BADCFG,                                                                                                                         ///< Initialization failed - core config = 0
    P64H_ERR_LIB_USR_CRYPTO_SKC_SB_PAUSED,                                                                                                                          ///< Operation successfully paused
    P64H_ERR_LIB_USR_CRYPTO_SKC_SB_EC_FAIL,                                                                                                                         ///< ECDSA Verification failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_SB_GCM_FAIL,                                                                                                                        ///< AES GCM MAC authentication failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_SB_IHASH_FAIL,                                                                                                                      ///< Intermediate hash comparison failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_SB_HASH_FAIL,                                                                                                                       ///< Hash comparison failed
    P64H_ERR_LIB_USR_CRYPTO_SKC_SB_RESUME_FAIL,                                                                                                                     ///< Tried to resume when already complete
    P64H_ERR_LIB_USR_CRYPTO_SKC_TYPE_INVALID,                                                                                                                       ///< Invalid type for the requested resource
    P64H_ERR_LIB_USR_CRYPTO_SKC_RSRC_UNAVAIL,                                                                                                                       ///< Unavailable, not present, resource
    P64H_ERR_LIB_USR_CRYPTO_SKC_CTX_UNINI,                                                                                                                          ///< Uninitialized context
    P64H_ERR_LIB_USR_CRYPTO_SKC_CTX_STATE_NO_ALLOC,                                                                                                                 ///< Context state unallocated
    P64H_ERR_LIB_USR_CRYPTO_SKC_CTX_STATE_INVALID,                                                                                                                  ///< Context state invalid
    P64H_ERR_LIB_USR_CRYPTO_SKC_CTX_NOTFINAL,                                                                                                                       ///< Context is not finalized
    P64H_ERR_LIB_USR_CRYPTO_SKC_CTX_SUB_BLOCKSIZE,                                                                                                                  ///< Context switching would cause loss of unprocessed data
    P64H_ERR_LIB_USR_CRYPTO_SKC_MODE_DISABLED,                                                                                                                      ///< Mode is disabled and cannot be used
    P64H_ERR_LIB_USR_CRYPTO_SKC_LENGTH_INVALID,                                                                                                                     ///< Invalid data length
    P64H_ERR_LIB_USR_CRYPTO_SKC_PARAM_INVALID,                                                                                                                      ///< Invalid parameter
    P64H_ERR_LIB_USR_CRYPTO_SKC_PARAM_RANGE,                                                                                                                        ///< Parameter value out of range
    P64H_ERR_LIB_USR_CRYPTO_SKC_MOD_INVALID,                                                                                                                        ///< Invalid even modulus
    P64H_ERR_LIB_USR_CRYPTO_SKC_ECTYPE_INVALID,                                                                                                                     ///< Operation does not support curve type
    P64H_ERR_LIB_USR_CRYPTO_SKC_ECDCMP_INVALID,                                                                                                                     ///< Point decompression with modulus not of the form 4n+3
    P64H_ERR_LIB_USR_CRYPTO_SKC_ECPAF,                                                                                                                              ///< EC point at infinity
    P64H_ERR_LIB_USR_CRYPTO_SKC_ECPT_INVALID,                                                                                                                       ///< Invalid EC point, not on curve
    P64H_ERR_LIB_USR_CRYPTO_SKC_PRNG_HEALTH,                                                                                                                        ///< Data from entropy source is zero or not unique
    P64H_ERR_LIB_USR_CRYPTO_SKC_SIGNFAIL,                                                                                                                           ///< Signature failure
    P64H_ERR_LIB_USR_CRYPTO_SKC_VERIFYFAIL,                                                                                                                         ///< Signature or tag verification failure
    P64H_ERR_LIB_USR_CRYPTO_SKC_TFR_OVRFLOW,                                                                                                                        ///< Transfer count exceeds allocated
    P64H_ERR_LIB_USR_CRYPTO_SKC_TRANSLATE_ERR,                                                                                                                      ///< HW to SW error code translation error
    P64H_ERR_LIB_USR_CRYPTO_SKC_PARITY_DED,                                                                                                                         ///< Double bit error detected
    P64H_ERR_LIB_USR_CRYPTO_SKC_FNP,                                                                                                                                ///< Function implementation not populated
    P64H_ERR_LIB_USR_CRYPTO_SKC_DEPRECATED,                                                                                                                         ///< Function has been deprecated
    P64H_ERR_LIB_USR_CRYPTO_SKC_BUS_ERR,                                                                                                                            ///< DMA operation returned a bus error
    P64H_ERR_LIB_USR_CRYPTO_SKC_MEM_NOALLOC,                                                                                                                        ///< No available memory to allocate
    P64H_ERR_LIB_USR_CRYPTO_SKC_TIMEOUT,                                                                                                                            ///< SKC resource timed out
    P64H_ERR_LIB_USR_CRYPTO_SKC_FIFO_EMPTY,                                                                                                                         ///< FIFO is empty
    P64H_ERR_LIB_USR_CRYPTO_SKC_FIFO_FULL,                                                                                                                          ///< FIFO is full
    P64H_ERR_LIB_USR_CRYPTO_SKC_FAIL,                                                                                                                               ///< General failure
    P64H_ERR_LIB_USR_CRYPTO_PQS_VERIFICATION_FAILED,                                                                                                                ///< Signature verification failed
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_SERVICE_NOT_SUPPORTED,                                                                                                        ///< Service checks failed
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_SERVICE_NOT_FOUND,                                                                                                            ///< Service not present in the system
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_EXCEPTION_OCCURRED_RESETTING,                                                                                                 ///< Exception occurred, resetting itself
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_MEMORY_CORRUPTION,                                                                                                            ///< Detected memory corruption, resetting itself
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_RESET_NEEDED,                                                                                                                 ///< Unexpected failure occurred, need external reset
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_DOWNLOAD_NOT_ALLOWED,                                                                                                         ///< Download of FW is not allowed
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_DATA_COMM_RECEIVE,                                                                                                            ///< Error occurred during data transfer
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_DATA_COMM_SEND,                                                                                                               ///< Error occurred during data transfer
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_NOT_READY,                                                                                                                    ///< PQSubSys not yet boot-up
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INTERNAL,                                                                                                                     ///< Unexpected Error
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_SELF_TEST_FAILED,                                                                                                             ///< ROM Self test failed
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_ZEROISATION_TRIGGERED,                                                                                                        ///< Zeroisation triggered
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_BUSY_WITH_OTHER_APPLICATION,                                                                                                  ///< PQSubSys is already busy running a service, can't accept new request
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_NO_APPLICATION_RUNNING,                                                                                                       ///< PQSubSys is idle, no response is expected
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INSUFFICIENT_KEY_MEM,                                                                                                         ///< No memory left for a new key
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INSUFFICIENT_CONTEXT_MEM,                                                                                                     ///< No memory left for a new context
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INSUFFICIENT_IO_MEM,                                                                                                          ///< No memory left for IO buffers
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INCOMPATIBLE_BINARY,                                                                                                          ///< Incompatible IRAM binary
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INCOMPATIBLE_KEY,                                                                                                             ///< Key is not compatible for the intended usage
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INVALID_CONTEXT,                                                                                                              ///< Context ID is invalid
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_INVALID_KEY,                                                                                                                  ///< Key ID is invalid
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_OUTPUT_BUFFER_SMALL,                                                                                                          ///< Host memory buffer size is insufficient for the data to be received
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_UNSUPPORTED_ALGO,                                                                                                             ///< Algorithm not supported by the PQSubSys
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_UNSUPPORTED_ALGO_PARAM,                                                                                                       ///< Algorithm parameter is not supported by the PQSubSys
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_UNSUPPORTED_KEY_TYPE,                                                                                                         ///< Provided key type not supported for the given purpose
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_UNSUPPORTED_FORMAT,                                                                                                           ///< Provided key format not supported for the given purpose
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_UNSUPPORTED_DATA_INTERFACE,                                                                                                   ///< Provided data interface not supported for the given purpose
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_UNSUPPORTED_DRBG_SECURITY_STRENGTH,                                                                                           ///< Provided security strength is not supported
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_WRONG_PARAMETER_VALUE,                                                                                                        ///< Invalid input parameter
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_WRONG_ENTROPY_INTERFACE_USED,                                                                                                 ///< Provided interface for the entropy is locked during initialization
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_WRONG_DIGEST_SIZE,                                                                                                            ///< Invalid digest size, bigger than the expected size
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_API_PREREQUISITE_NOT_MET,                                                                                                     ///< API called in an order in which didn't satisfy the condition to execute the service
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_DRBG_REQUIRE_RESEED,                                                                                                          ///< entropy depleted, DRBG needs to be reseeded via pqs_reseed() API, before performing an operation
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_WRAPQ_PUBLIC_KEY_ABSENT,                                                                                                      ///< WrapQ requires a public key to be present when deserialising a secret key
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_KEY_ENCRYPTION_KEY_NOT_SET,                                                                                                   ///< KEK is not set for the wrapq format
    P64H_ERR_LIB_USR_CRYPTO_PQS_ERROR_NOT_SUPPORTED_YET,                                                                                                            ///< Feature is not supported yet
    P64H_ERR_LIB_BIST_NULL_HANDLE                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_BIST),             ///< Error due to NULL BIST handle.
    P64H_ERR_LIB_BIST_INVALID_TEST,                                                                                                                                 ///< Unsupported BIST test type passed to BIST library.
    P64H_ERR_LIB_BIST_INVALID_INST_N,                                                                                                                               ///< Error due to BIST block not having instance N.
    P64H_ERR_LIB_BIST_INVALID_ALGORITHM,                                                                                                                            ///< Error due to BIST test not having the given BIST algorithm.
    P64H_ERR_LIB_APPC_SOC_CFG_NULL_CFG                                      = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_APPC_SOC_CFG),     ///< Error returned when a pointer argument to a configuration is NULL.
    P64H_ERR_LIB_APPC_SOC_CFG_NULL_HANDLE,                                                                                                                          ///< Error returned when a pointer argument to a handle is NULL.
    P64H_ERR_LIB_APPC_SOC_CFG_NULL_M2_HANDLE,                                                                                                                       ///< Error returned when a pointer argument to a m2 handle is NULL.
    P64H_ERR_LIB_APPC_SOC_CFG_HPT_ERROR,                                                                                                                            ///< Error returned when HPT status is not OK
    P64H_ERR_LIB_APPC_SOC_CFG_RNMI_ERROR,                                                                                                                           ///< Error returned when RNMI status is not OK
    P64H_ERR_LIB_APPC_SOC_CFG_RNMI_TIMEOUT,                                                                                                                         ///< Error returned when executing RNMI action is taking too long
    P64H_ERR_LIB_API_NULL_POINTER                                           = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_API),              ///< Error returned when a pointer is NULL
    P64H_ERR_LIB_API_BAD_SIZE,                                                                                                                                      ///< Error returned when size is zero
    P64H_ERR_LIB_API_CID_INVALID,                                                                                                                                   ///< Error returned when RPMI Client identifier is invalid
    P64H_ERR_LIB_API_SHMEM_INIT_FAIL,                                                                                                                               ///< Error returned when RPMI shared-memory initialization fails
    P64H_ERR_LIB_API_REMOTE_INIT_FAIL,                                                                                                                              ///< Error returned when RPMI remote initialization fails
    P64H_ERR_LIB_API_RPMI_CLIENT_NOT_INITIALIZED,                                                                                                                   ///< Error returned when RPMI client is not not initialized
    P64H_ERR_LIB_API_NOT_YET_IMPLEMENTED,                                                                                                                           ///< API not yet implemented
    P64H_ERR_LIB_API_INVALID_PARAM,                                                                                                                                 ///< One or more parameters passed are invalid
    P64H_ERR_LIB_API_BAD_RANGE,                                                                                                                                     ///< Bad or invalid range
    P64H_ERR_LIB_API_INVALID_STATE,                                                                                                                                 ///< Invalid state
    P64H_ERR_LIB_API_DENIED,                                                                                                                                        ///< Requested operation denied due to insufficient permissions or failed dependency check
    P64H_ERR_LIB_API_INVALID_ADDR,                                                                                                                                  ///< One or more addresses are invalidd
    P64H_ERR_LIB_API_HW_FAULT,                                                                                                                                      ///< Failed due to hardware fault
    P64H_ERR_LIB_API_ALREADY,                                                                                                                                       ///< Operation already in progress or state changed already for which the operation was performed
    P64H_ERR_LIB_API_BUSY,                                                                                                                                          ///< Service cannot be completed due to system or device is busy
    P64H_ERR_LIB_API_TIMEOUT,                                                                                                                                       ///< Failed due to timeout
    P64H_ERR_LIB_API_IO,                                                                                                                                            ///< Input/Output error
    P64H_ERR_LIB_API_FAILED,                                                                                                                                        ///< Failed due to general error.
    P64H_ERR_LIB_API_NOT_SUPPORTED,                                                                                                                                 ///< Service or feature is not supported.
    P64H_ERR_LIB_API_NO_DATA,                                                                                                                                       ///< Data not available
    P64H_ERR_LIB_API_EXTENSION,                                                                                                                                     ///< Error in extension implementation that violates the extension specification or the extension version mismatch
    P64H_ERR_LIB_API_VERSION_MISMATCH,                                                                                                                              ///< Versions between remote and system FW are not the same
    P64H_ERR_LIB_API_TOO_MANY_ENTRIES_RETURNED,                                                                                                                     ///< Too many log entries were returned on a log fetch transaction
    P64H_ERR_LIB_API_INVALID_ENTRIES_RETURNED,                                                                                                                      ///< Invalid entries were returned on a log fetch transaction
    P64H_ERR_LIB_API_REQ_BUSY,                                                                                                                                      ///< There is already an outstanding posted request
    P64H_ERR_LIB_API_RESP_PENDING,                                                                                                                                  ///< Response is not ready
    P64H_ERR_LIB_API_INVALID_REQ_STATE,                                                                                                                             ///< Invalid request state is returned
    P64H_ERR_LIB_API_CHECKSUM_MISMATCH,                                                                                                                             ///< Checksum mismatched, data is corrupted
    P64H_ERR_LIB_API_CALLBACK_UNSET,                                                                                                                                ///< The callback function is unset
    P64H_ERR_LIB_SYSC_SOC_CFG_NULL_CFG                                      = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_SYSC_SOC_CFG),     ///< Error returned when a pointer argument to a configuration is NULL.
    P64H_ERR_LIB_SYSC_SOC_CFG_NULL_HANDLE,                                                                                                                          ///< Error returned when a pointer argument to a handle is NULL.
    P64H_ERR_LIB_SYSC_SOC_CFG_INVALID_FS_INSTANCE,                                                                                                                  ///< Error returned when trying to use invalid filesystem instance
    P64H_ERR_LIB_SYSC_SOC_CFG_INVALID_FS_CONFIG,                                                                                                                    ///< Error returned when trying to use invalid filesystem config
    P64H_ERR_LIB_SYSC_SOC_CFG_MOUNT_FAIL,                                                                                                                           ///< Error returned when there is a failure to mount the filesystem
    P64H_ERR_LIB_RASLIB_NO_ERR_FROM_HER                                     = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_RASLIB),           ///< No error was detected in the parsing of the HER
    P64H_ERR_LIB_RASLIB_NO_BERT_ERROR,                                                                                                                              ///< No error to report for the requested BERT entry
    P64H_ERR_LIB_RASLIB_ERT_INVALID_READ,                                                                                                                           ///< Request to read the ERT at a buffer offset beyond the history of the buffer entries
    P64H_ERR_LIB_RASLIB_INVALID_HER_DATA,                                                                                                                           ///< Unexpected and invalid data extracted from parsing HER
    P64H_ERR_LIB_FW_UPGRADE_UPLOAD_FAIL                                     = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_FW_UPGRADE),       ///< firmware upgrade upload fail
    P64H_ERR_LIB_FW_UPGRADE_APPLY_FAIL,                                                                                                                             ///< firmware upgrade apply fail
    P64H_ERR_LIB_BAAL_INVALID_SIMG_ID                                       = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_BAAL),             ///< Error returned when the sysc image identifier is invalid
    P64H_ERR_LIB_BAAL_METADATA_ERR,                                                                                                                                 ///< Error returned when there was an issue accessing or reading from an AppC image metadata
    P64H_ERR_LIB_BAAL_APPC_NOT_INIT,                                                                                                                                ///< Error returned when baal was not properly initialized to access AppC Boot Articats
    P64H_ERR_LIB_BAAL_NOT_IMPL,                                                                                                                                     ///< BAAL not implemented error.
    P64H_ERR_LIB_BAAL_INIT_FAIL,                                                                                                                                    ///< BAAL init fail.
    P64H_ERR_LIB_BAAL_DEINIT_FAIL,                                                                                                                                  ///< BAAL deinit fail.
    P64H_ERR_LIB_BAAL_GET_FAIL,                                                                                                                                     ///< BAAL failed to get an artifact
    P64H_ERR_LIB_BAAL_READ_FAIL,                                                                                                                                    ///< BAAL failed to read an artifact
    P64H_ERR_LIB_BAAL_DMA_FAIL,                                                                                                                                     ///< baal failed to write to an artifact with dma
    P64H_ERR_LIB_BAAL_UPGRADE_FAIL,                                                                                                                                 ///< baal failed to upgrade an AppC artifact
    P64H_ERR_LIB_BAAL_OVERWRITE_FAIL,                                                                                                                               ///< baal failed to overwrite artifact
    P64H_ERR_LIB_BAAL_SECTOR_ERASE_FAIL,                                                                                                                            ///< baal failed to erase a sector
    P64H_ERR_LIB_BAAL_UPDATE_FAIL,                                                                                                                                  ///< baal failed to update an AppC artifact
    P64H_ERR_LIB_BAAL_OTP_READ_FAIL,                                                                                                                                ///< BAAL failed to read data from otp
    P64H_ERR_LIB_BAAL_SECC_FSBL_DWNLD,                                                                                                                              ///< BAAL failed to load secc fsbl image
    P64H_ERR_LIB_BAAL_INVALID_FSBL_SIZE,                                                                                                                            ///< BAAL invalid fsbl size error.
    P64H_ERR_LIB_BAAL_READ_TRUNC,                                                                                                                                   ///< Read from baal truncated to fit local storage
    P64H_ERR_LIB_ANLT_SM_ERR                                                = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_ANLT_SM),          ///< generic error from unexpected source in the ANLT State Machine
    P64H_ERR_LIB_ANLT_SM_MISCFG,                                                                                                                                    ///< The ANLT State Machine has detected that the ANLT instance it is associated with has somehow been configured incorrectly during ANLT operation
    P64H_ERR_LIB_ANLT_SM_AN_ARB_FAIL,                                                                                                                               ///< The AN_ARB state machine in hardware has transitioned back to AN_TRANS_DIS indicating loss of frame and AN failing to complete
    P64H_ERR_LIB_ANLT_SM_INVALID_STATE,                                                                                                                             ///< ANLT State Machine called with state larger than P64H_SYSC_ANLT_SM_STATE_LAST
    P64H_ERR_LIB_ANLT_SM_INVALID_SEND_TRAINING_STATE,                                                                                                               ///< ANLT State Machine called while in the ANLT_SM_STATE_LT_SEND_TRAINING with an lt_train_state larger than P64H_SYSC_LT_TRAIN_STATE_LAST
    P64H_ERR_LIB_ANLT_SM_INVALID_LT_UPD_STATE,                                                                                                                      ///< ANLT State Machine called with lt_upd_state larger than P64H_SYSC_LT_TRAIN_STATE_LAST
    P64H_ERR_LIB_TAR_ZIP_HELPER_COMPRESS                                    = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_TAR_ZIP_HELPER),   ///< Error returned when compressing a tar file fails.
    P64H_ERR_LIB_TAR_ZIP_HELPER_DECOMPRESS,                                                                                                                         ///< Error returned when decompressing a tgz file fails.
    P64H_ERR_LIB_TAR_ZIP_HELPER_ZLIB_HEADER,                                                                                                                        ///< Error returned when Invalid Zlib header checksum
    P64H_ERR_LIB_TAR_ZIP_HELPER_MTAR_OPEN,                                                                                                                          ///< Error returned when opening a tar file fails.
    P64H_ERR_LIB_RING_BUF_FULL                                              = P64H_SYSC_SVC_ERR_SVC_OFFSET + P64H_SYSC_COMP_ENCODE(P64H_COMP_LIB_RING_BUF),         ///< ring buffer is full and action cannot be processed
    P64H_ERR_LIB_RING_BUF_EMPTY,                                                                                                                                    ///< ring buffer is empty and action cannot be processed
    P64H_ERR_LIB_RING_BUF_INVALID_READ,                                                                                                                             ///< read at an invalid index was requested
    P64H_ERR_LAST
} p64h_err_t;

/* Public Methods ------------------------------------------ */

/**
* @brief Method used to retrieve the enum name of an error
*/
char* p64h_err_name_get(p64h_err_t err_code);

/**
* @brief Method used to retrieve the enum name of an error
*/
char* p64h_err_desc_get(p64h_err_t err_code);

#endif /* P64H_SYSC_DEF_ERRORS */
