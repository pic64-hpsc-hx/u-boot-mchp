/* (c) 2026 Microchip Technology Inc. */
/*    SPDX-License-Identifier: MIT    */

#ifndef RAS_DATA_PRINT_H
#define RAS_DATA_PRINT_H

#include <stdint.h>
// #include <assert.h>
#include "generated/p64h_sysc_ras_data_defs.h"
#include "generated/p64h_sysc_ras_error_sources.h"
#include "generated/p64h_sysc_cper_sections.h"
#include "p64h_sysc_diag_lib.h"

//////////////////////
// Error Source String 
//////////////////////
const char* p64h_sysc_ras_ghes_id_string_get(uint32_t ghes_id);

//////////////////////
// Error Id Print 
//////////////////////
void p64h_ras_error_code_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_error_code_t erro_code);

//////////////////////
// Error Id String 
//////////////////////
const char* p64h_ras_err_id_string_get(uint32_t err_id_val);

//////////////////////
// Error Struct Print
//////////////////////
const char* p64h_ras_app_mem_struct_string_get(uint32_t struct_val);


const char* p64h_ras_app_noc_struct_string_get(uint32_t struct_val);


const char* p64h_ras_app_periph_struct_string_get(uint32_t struct_val);


const char* p64h_ras_app_x288_struct_string_get(uint32_t struct_val);


const char* p64h_ras_clock_struct_string_get(uint32_t struct_val);


const char* p64h_ras_ddr_struct_string_get(uint32_t struct_val);


const char* p64h_ras_ddr_noc_struct_string_get(uint32_t struct_val);


const char* p64h_ras_enet_struct_string_get(uint32_t struct_val);


const char* p64h_ras_enet_ep_struct_string_get(uint32_t struct_val);


const char* p64h_ras_nvm_struct_string_get(uint32_t struct_val);


const char* p64h_ras_pcxl_struct_string_get(uint32_t struct_val);


const char* p64h_ras_sec_struct_string_get(uint32_t struct_val);


const char* p64h_ras_svc_noc_struct_string_get(uint32_t struct_val);


const char* p64h_ras_sys_struct_string_get(uint32_t struct_val);


const char* p64h_ras_sys_noc_struct_string_get(uint32_t struct_val);


// Error Struct Instance Print
//////////////////////
const char* p64h_ras_app_mem_ocr_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_noc_dtp_ln_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_noc_initiators_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_noc_observer_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_noc_targets_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_noc_top_fault_agg_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_noc_wgc_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_periph_wdog_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_x288_fabric_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_x288_iommu_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_x288_lockstep_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_x288_tile_inst_string_get(uint32_t inst_val);

const char* p64h_ras_app_x288_wgc_inst_string_get(uint32_t inst_val);

const char* p64h_ras_clock_csu_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_edac_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_hsio_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_phy_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_noc_initiators_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_noc_observer_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_noc_targets_inst_string_get(uint32_t inst_val);

const char* p64h_ras_ddr_noc_top_fault_agg_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_ana_ac_eacl_rew_wrap_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_anacl32oam_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_asm_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_dsm_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_eacl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_misc_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_pier_rdma_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_pier_rdma_misc_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_sqs_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_tcam_ecc_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_vcap_super_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_ep_core_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_ep_frer_rx_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_ep_frer_tx_inst_string_get(uint32_t inst_val);

const char* p64h_ras_enet_ep_sb_inst_string_get(uint32_t inst_val);

const char* p64h_ras_nvm_nand_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_nvm_nvm_edac_inst_string_get(uint32_t inst_val);

const char* p64h_ras_nvm_pflash_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_nvm_spi_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_nvm_sram_edac_inst_string_get(uint32_t inst_val);

const char* p64h_ras_pcxl_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_pcxl_link_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_ana_mon_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_apb2jtag_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_cmon_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_csu_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_dma_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_mesh_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_noc_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_ocr_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_pqs_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_ram_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_s7_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_tamper_mon_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_timer_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_tvs_mon_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sec_wdog_inst_string_get(uint32_t inst_val);

const char* p64h_ras_svc_noc_initiators_inst_string_get(uint32_t inst_val);

const char* p64h_ras_svc_noc_targets_inst_string_get(uint32_t inst_val);

const char* p64h_ras_svc_noc_top_fault_agg_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_dma_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_hpt_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_ocr_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_s7_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_spi_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_spw_ctrl_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_sram_edac_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_noc_dtp_ln_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_noc_initiators_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_noc_observer_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_noc_targets_inst_string_get(uint32_t inst_val);

const char* p64h_ras_sys_noc_top_fault_agg_inst_string_get(uint32_t inst_val);

// Error Event Print
//////////////////////
const char* p64h_ras_app_mem_ocr_err_string_get(uint32_t err_val);


const char* p64h_ras_app_noc_dtp_ln_err_string_get(uint32_t err_val);


const char* p64h_ras_app_noc_initiators_err_string_get(uint32_t err_val);


const char* p64h_ras_app_noc_observer_err_string_get(uint32_t err_val);


const char* p64h_ras_app_noc_targets_err_string_get(uint32_t err_val);


const char* p64h_ras_app_noc_top_fault_agg_err_string_get(uint32_t err_val);


const char* p64h_ras_app_noc_wgc_err_string_get(uint32_t err_val);


const char* p64h_ras_app_periph_wdog_err_string_get(uint32_t err_val);


const char* p64h_ras_app_x288_fabric_err_string_get(uint32_t err_val);


const char* p64h_ras_app_x288_iommu_err_string_get(uint32_t err_val);


const char* p64h_ras_app_x288_lockstep_err_string_get(uint32_t err_val);


const char* p64h_ras_app_x288_tile_err_string_get(uint32_t err_val);


const char* p64h_ras_app_x288_wgc_err_string_get(uint32_t err_val);


const char* p64h_ras_clock_csu_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_edac_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_hsio_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_phy_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_noc_initiators_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_noc_observer_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_noc_targets_err_string_get(uint32_t err_val);


const char* p64h_ras_ddr_noc_top_fault_agg_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_ana_ac_eacl_rew_wrap_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_anacl32oam_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_asm_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_dsm_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_eacl_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_misc_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_pier_rdma_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_pier_rdma_misc_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_sqs_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_tcam_ecc_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_vcap_super_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_ep_core_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_ep_frer_rx_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_ep_frer_tx_err_string_get(uint32_t err_val);


const char* p64h_ras_enet_ep_sb_err_string_get(uint32_t err_val);


const char* p64h_ras_nvm_nand_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_nvm_nvm_edac_err_string_get(uint32_t err_val);


const char* p64h_ras_nvm_pflash_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_nvm_spi_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_nvm_sram_edac_err_string_get(uint32_t err_val);


const char* p64h_ras_pcxl_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_pcxl_link_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_ana_mon_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_apb2jtag_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_cmon_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_csu_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_dma_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_mesh_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_noc_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_ocr_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_pqs_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_ram_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_s7_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_tamper_mon_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_timer_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_tvs_mon_err_string_get(uint32_t err_val);


const char* p64h_ras_sec_wdog_err_string_get(uint32_t err_val);


const char* p64h_ras_svc_noc_initiators_err_string_get(uint32_t err_val);


const char* p64h_ras_svc_noc_targets_err_string_get(uint32_t err_val);


const char* p64h_ras_svc_noc_top_fault_agg_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_dma_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_hpt_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_ocr_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_s7_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_spi_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_spw_ctrl_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_sram_edac_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_noc_dtp_ln_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_noc_initiators_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_noc_observer_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_noc_targets_err_string_get(uint32_t err_val);


const char* p64h_ras_sys_noc_top_fault_agg_err_string_get(uint32_t err_val);


//////////////////////
// ID Types Print
//////////////////////
const char* p64h_sysc_ras_ext_cache_slice_id_string_get(p64h_sysc_ras_ext_cache_slice_id_t ext_cache_slice);

const char* p64h_sysc_ras_ext_cache_bank_id_string_get(p64h_sysc_ras_ext_cache_bank_id_t ext_cache_bank);

const char* p64h_sysc_ras_pl2_inst_id_string_get(p64h_sysc_ras_pl2_inst_id_t pl2_inst);

const char* p64h_sysc_ras_sec_noc_niu_id_string_get(p64h_sysc_ras_sec_noc_niu_id_t sec_noc_niu);

const char* p64h_sysc_ras_tamper_hw_lock_id_string_get(p64h_sysc_ras_tamper_hw_lock_id_t tamper_hw_lock);

const char* p64h_sysc_ras_mesh_block_id_string_get(p64h_sysc_ras_mesh_block_id_t mesh_block);

const char* p64h_sysc_ras_sec_mem_block_id_string_get(p64h_sysc_ras_sec_mem_block_id_t sec_mem_block);

const char* p64h_sysc_ras_vdd_thres_detect_id_string_get(p64h_sysc_ras_vdd_thres_detect_id_t vdd_thres_detect);

const char* p64h_sysc_ras_ls_einj_mod_type_id_string_get(p64h_sysc_ras_ls_einj_mod_type_id_t ls_einj_mod_type);

const char* p64h_sysc_ras_ls_chk_mod_id_string_get(p64h_sysc_ras_ls_chk_mod_id_t ls_chk_mod);

const char* p64h_sysc_ras_ls_broadcast_mod_id_string_get(p64h_sysc_ras_ls_broadcast_mod_id_t ls_broadcast_mod);

const char* p64h_sysc_ras_tl_req_denied_type_id_string_get(p64h_sysc_ras_tl_req_denied_type_id_t tl_req_denied_type);

const char* p64h_sysc_ras_sram_edac_err_inj_stage_id_string_get(p64h_sysc_ras_sram_edac_err_inj_stage_id_t sram_edac_err_inj_stage);

const char* p64h_sysc_ras_sram_edac_inst_id_string_get(p64h_sysc_ras_sram_edac_inst_id_t sram_edac_inst);

const char* p64h_sysc_ras_nvm_edac_err_inj_stage_id_string_get(p64h_sysc_ras_nvm_edac_err_inj_stage_id_t nvm_edac_err_inj_stage);

const char* p64h_sysc_ras_nvm_edac_inst_id_string_get(p64h_sysc_ras_nvm_edac_inst_id_t nvm_edac_inst);

const char* p64h_sysc_ras_nvm_edac_mode_id_string_get(p64h_sysc_ras_nvm_edac_mode_id_t nvm_edac_mode);

const char* p64h_sysc_ras_ddr_edac_mode_id_string_get(p64h_sysc_ras_ddr_edac_mode_id_t ddr_edac_mode);

const char* p64h_sysc_ras_ddr_edac_err_sel_id_string_get(p64h_sysc_ras_ddr_edac_err_sel_id_t ddr_edac_err_sel);

const char* p64h_sysc_ras_ddr_edac_di_fault_sel_id_string_get(p64h_sysc_ras_ddr_edac_di_fault_sel_id_t ddr_edac_di_fault_sel);

const char* p64h_sysc_ras_enet_ep_diag_inst_id_string_get(p64h_sysc_ras_enet_ep_diag_inst_id_t enet_ep_diag_inst);

const char* p64h_sysc_ras_noc_pkt_opc_id_string_get(p64h_sysc_ras_noc_pkt_opc_id_t noc_pkt_opc);

const char* p64h_sysc_ras_sys_noc_init_id_string_get(p64h_sysc_ras_sys_noc_init_id_t sys_noc_init);

const char* p64h_sysc_ras_sys_noc_targ_id_string_get(p64h_sysc_ras_sys_noc_targ_id_t sys_noc_targ);

const char* p64h_sysc_ras_app_noc_init_id_string_get(p64h_sysc_ras_app_noc_init_id_t app_noc_init);

const char* p64h_sysc_ras_app_noc_targ_id_string_get(p64h_sysc_ras_app_noc_targ_id_t app_noc_targ);

const char* p64h_sysc_ras_ddr_noc_init_id_string_get(p64h_sysc_ras_ddr_noc_init_id_t ddr_noc_init);

const char* p64h_sysc_ras_ddr_noc_targ_id_string_get(p64h_sysc_ras_ddr_noc_targ_id_t ddr_noc_targ);

//////////////////////
// Error Data Structs Print
//////////////////////
void p64h_sysc_ras_target_address_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_target_address_t* target_address_ptr);

void p64h_sysc_ras_address_offset_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_address_offset_t* address_offset_ptr);

void p64h_sysc_ras_ocr_ecc_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ocr_ecc_t* ocr_ecc_ptr);

void p64h_sysc_ras_ls_einj_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ls_einj_params_t* ls_einj_params_ptr);

void p64h_sysc_ras_ecache_einj_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ecache_einj_params_t* ecache_einj_params_ptr);

void p64h_sysc_ras_pl2_einj_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_pl2_einj_params_t* pl2_einj_params_ptr);

void p64h_sysc_ras_temp_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_temp_evt_t* temp_evt_ptr);

void p64h_sysc_ras_cmon_thres_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_cmon_thres_evt_t* cmon_thres_evt_ptr);

void p64h_sysc_ras_wgc_error_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_wgc_error_t* wgc_error_ptr);

void p64h_sysc_ras_fw_error_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_fw_error_t* fw_error_ptr);

void p64h_sysc_ras_x288_setwaybank_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_setwaybank_t* x288_setwaybank_ptr);

void p64h_sysc_ras_x288_ls_error_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_ls_error_t* x288_ls_error_ptr);

void p64h_sysc_ras_x288_l3_tag_err_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_l3_tag_err_t* x288_l3_tag_err_ptr);

void p64h_sysc_ras_x288_l3_data_err_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_l3_data_err_t* x288_l3_data_err_ptr);

void p64h_sysc_ras_x288_l3_data_corrupt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_l3_data_corrupt_t* x288_l3_data_corrupt_ptr);

void p64h_sysc_ras_x288_l3_tl_denied_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_l3_tl_denied_t* x288_l3_tl_denied_ptr);

void p64h_sysc_ras_x288_deint_err_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_deint_err_t* x288_deint_err_ptr);

void p64h_sysc_ras_iommu_err_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_iommu_err_t* iommu_err_ptr);

void p64h_sysc_ras_nvm_sram_edac_mon_cor_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_nvm_sram_edac_mon_cor_evt_t* nvm_sram_edac_mon_cor_evt_ptr);

void p64h_sysc_ras_nvm_sram_edac_mon_uncor_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_nvm_sram_edac_mon_uncor_evt_t* nvm_sram_edac_mon_uncor_evt_ptr);

void p64h_sysc_ras_sram_edac_dec_einj_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_sram_edac_dec_einj_t* sram_edac_dec_einj_ptr);

void p64h_sysc_ras_sram_edac_bus_secded_einj_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_sram_edac_bus_secded_einj_t* sram_edac_bus_secded_einj_ptr);

void p64h_sysc_ras_nvm_edac_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_nvm_edac_params_t* nvm_edac_params_ptr);

void p64h_sysc_ras_nvm_emon_ext_err_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_nvm_emon_ext_err_t* nvm_emon_ext_err_ptr);

void p64h_sysc_ras_ddr_emon_ext_err_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_emon_ext_err_t* ddr_emon_ext_err_ptr);

void p64h_sysc_ras_ddr_edac_emon_evt_einj_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_edac_emon_evt_einj_t* ddr_edac_emon_evt_einj_ptr);

void p64h_sysc_ras_ddr_edac_enc_int_einj_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_edac_enc_int_einj_t* ddr_edac_enc_int_einj_ptr);

void p64h_sysc_ras_enet_dp_err_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_enet_dp_err_params_t* enet_dp_err_params_ptr);

void p64h_sysc_ras_ddr_edac_cor_mon_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_edac_cor_mon_evt_t* ddr_edac_cor_mon_evt_ptr);

void p64h_sysc_ras_ddr_edac_uncor_mon_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_edac_uncor_mon_evt_t* ddr_edac_uncor_mon_evt_ptr);

void p64h_sysc_ras_ddr_ctrl_pmon_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_ctrl_pmon_evt_t* ddr_ctrl_pmon_evt_ptr);

void p64h_sysc_ras_ddr_phy_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_phy_evt_t* ddr_phy_evt_ptr);

void p64h_sysc_ras_x288_cores_state_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_x288_cores_state_t* x288_cores_state_ptr);

void p64h_sysc_ras_enet_swr_ram_idx_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_enet_swr_ram_idx_t* enet_swr_ram_idx_ptr);

void p64h_sysc_ras_intr_storm_src_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_intr_storm_src_t* intr_storm_src_ptr);

void p64h_sysc_ras_spw_edac_sts_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_spw_edac_sts_t* spw_edac_sts_ptr);

void p64h_sysc_ras_dma_error_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_dma_error_params_t* dma_error_params_ptr);

void p64h_sysc_ras_enet_ep_sb_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_enet_ep_sb_evt_t* enet_ep_sb_evt_ptr);

void p64h_sysc_ras_enet_ep_core_evt_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_enet_ep_core_evt_t* enet_ep_core_evt_ptr);

void p64h_sysc_ras_sys_noc_err_pkt_hdr_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_sys_noc_err_pkt_hdr_t* sys_noc_err_pkt_hdr_ptr);

void p64h_sysc_ras_ddr_noc_err_pkt_hdr_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_ddr_noc_err_pkt_hdr_t* ddr_noc_err_pkt_hdr_ptr);

void p64h_sysc_ras_app_noc_err_pkt_hdr_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_app_noc_err_pkt_hdr_t* app_noc_err_pkt_hdr_ptr);

void p64h_sysc_ras_agg_fault_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_agg_fault_t* agg_fault_ptr);

void p64h_sysc_ras_enet_swr_tcam_einj_params_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_enet_swr_tcam_einj_params_t* enet_swr_tcam_einj_params_ptr);

void p64h_sysc_ras_nvm_ctrl_bus_secded_einj_print(const p64h_sysc_env_print_t* env_print_ptr, p64h_sysc_ras_nvm_ctrl_bus_secded_einj_t* nvm_ctrl_bus_secded_einj_ptr);

//////////////////////
// CPER section Print
//////////////////////
void csu_section_print(const p64h_sysc_env_print_t* env_print_ptr, const csu_section_t* csu_ptr);

void ocr_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ocr_section_t* ocr_ptr);

void pqs_section_print(const p64h_sysc_env_print_t* env_print_ptr, const pqs_section_t* pqs_ptr);

void sec_noc_section_print(const p64h_sysc_env_print_t* env_print_ptr, const sec_noc_section_t* sec_noc_ptr);

void cmon_section_print(const p64h_sysc_env_print_t* env_print_ptr, const cmon_section_t* cmon_ptr);

void tamper_mon_section_print(const p64h_sysc_env_print_t* env_print_ptr, const tamper_mon_section_t* tamper_mon_ptr);

void mesh_section_print(const p64h_sysc_env_print_t* env_print_ptr, const mesh_section_t* mesh_ptr);

void proc_section_print(const p64h_sysc_env_print_t* env_print_ptr, const proc_section_t* proc_ptr);

void wdog_section_print(const p64h_sysc_env_print_t* env_print_ptr, const wdog_section_t* wdog_ptr);

void ana_mon_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ana_mon_section_t* ana_mon_ptr);

void boot_itr_section_print(const p64h_sysc_env_print_t* env_print_ptr, const boot_itr_section_t* boot_itr_ptr);

void dma_section_print(const p64h_sysc_env_print_t* env_print_ptr, const dma_section_t* dma_ptr);

void tvs_mon_section_print(const p64h_sysc_env_print_t* env_print_ptr, const tvs_mon_section_t* tvs_mon_ptr);

void riscv_proc_section_print(const p64h_sysc_env_print_t* env_print_ptr, const riscv_proc_section_t* riscv_proc_ptr);

void app_noc_section_print(const p64h_sysc_env_print_t* env_print_ptr, const app_noc_section_t* app_noc_ptr);

void app_wdog_section_print(const p64h_sysc_env_print_t* env_print_ptr, const app_wdog_section_t* app_wdog_ptr);

void sram_edac_section_print(const p64h_sysc_env_print_t* env_print_ptr, const sram_edac_section_t* sram_edac_ptr);

void nvm_edac_section_print(const p64h_sysc_env_print_t* env_print_ptr, const nvm_edac_section_t* nvm_edac_ptr);

void fw_err_section_print(const p64h_sysc_env_print_t* env_print_ptr, const fw_err_section_t* fw_err_ptr);

void intr_storm_section_print(const p64h_sysc_env_print_t* env_print_ptr, const intr_storm_section_t* intr_storm_ptr);

void enet_sw_section_print(const p64h_sysc_env_print_t* env_print_ptr, const enet_sw_section_t* enet_sw_ptr);

void pflash_ctrl_section_print(const p64h_sysc_env_print_t* env_print_ptr, const pflash_ctrl_section_t* pflash_ctrl_ptr);

void ddr_edac_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ddr_edac_section_t* ddr_edac_ptr);

void spi_ctrl_section_print(const p64h_sysc_env_print_t* env_print_ptr, const spi_ctrl_section_t* spi_ctrl_ptr);

void nand_ctrl_section_print(const p64h_sysc_env_print_t* env_print_ptr, const nand_ctrl_section_t* nand_ctrl_ptr);

void ddr_ctrl_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ddr_ctrl_section_t* ddr_ctrl_ptr);

void ddr_phy_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ddr_phy_section_t* ddr_phy_ptr);

void ddr_hsio_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ddr_hsio_section_t* ddr_hsio_ptr);

void spw_ctrl_section_print(const p64h_sysc_env_print_t* env_print_ptr, const spw_ctrl_section_t* spw_ctrl_ptr);

void sys_dbg_section_print(const p64h_sysc_env_print_t* env_print_ptr, const sys_dbg_section_t* sys_dbg_ptr);

void enet_ep_sb_section_print(const p64h_sysc_env_print_t* env_print_ptr, const enet_ep_sb_section_t* enet_ep_sb_ptr);

void enet_ep_core_section_print(const p64h_sysc_env_print_t* env_print_ptr, const enet_ep_core_section_t* enet_ep_core_ptr);

void enet_ep_frer_tx_section_print(const p64h_sysc_env_print_t* env_print_ptr, const enet_ep_frer_tx_section_t* enet_ep_frer_tx_ptr);

void enet_ep_frer_rx_section_print(const p64h_sysc_env_print_t* env_print_ptr, const enet_ep_frer_rx_section_t* enet_ep_frer_rx_ptr);

void sys_noc_fa_section_print(const p64h_sysc_env_print_t* env_print_ptr, const sys_noc_fa_section_t* sys_noc_fa_ptr);

void noc_obs_section_print(const p64h_sysc_env_print_t* env_print_ptr, const noc_obs_section_t* noc_obs_ptr);

void ddr_noc_section_print(const p64h_sysc_env_print_t* env_print_ptr, const ddr_noc_section_t* ddr_noc_ptr);

void hpt_section_print(const p64h_sysc_env_print_t* env_print_ptr, const hpt_section_t* hpt_ptr);

void app_noc_fa_section_print(const p64h_sysc_env_print_t* env_print_ptr, const app_noc_fa_section_t* app_noc_fa_ptr);

void svc_noc_section_print(const p64h_sysc_env_print_t* env_print_ptr, const svc_noc_section_t* svc_noc_ptr);

void pcxl_ctrl_section_print(const p64h_sysc_env_print_t* env_print_ptr, const pcxl_ctrl_section_t* pcxl_ctrl_ptr);

void pcxl_link_section_print(const p64h_sysc_env_print_t* env_print_ptr, const pcxl_link_section_t* pcxl_link_ptr);

//////////////////////
// Error Injection
//////////////////////
const char* p64h_sysc_ras_einj_attrs_string_get(p64h_sysc_ras_einj_attrs_t einj_attr);

#endif // RAS_DATA_PRINT_H

