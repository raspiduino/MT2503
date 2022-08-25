/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  SIMProvAgentProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM Provisioning Agent Header File
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef MMI_SPA_PROT_H
#define MMI_SPA_PROT_H

#ifdef __SPA_SUPPORT__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "CcaSrvGprot.h"

#include "SIMProvAgentConfig.h"
#ifdef MMI_SPA_JOB_SUPPORT

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif

#endif /* MMI_SPA_JOB_SUPPORT */ 
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "SIMProvAgentConst.h"
#include "SIMProvAgentDefs.h"
#include "SIMProvAgentGProt.h"

void *mmi_spa_malloc(U32 size);
void mmi_spa_free(void *p);
U8 mmi_spa_sim_info_notify_hdlr(void *msg, int mod_src, void *peer_buf);
void mmi_spa_sim_info_handler(const mmi_spa_sim_status_info_ind_struct *sim_info);
void mmi_spa_cca_ready_ind_handler(void);

mmi_ret mmi_spa_sim_available_change_hdlr(mmi_event_struct *evt);
mmi_ret mmi_spa_mode_switch_event_hdlr(mmi_event_struct *evt);
    
#ifdef MMI_SPA_JOB_SUPPORT
void mmi_spa_new_setting_rsp_handler(mmi_spa_sim_id_enum sim_id, mmi_spa_result_enum result, U32 trans_id);
#else 
void mmi_spa_new_setting_rsp_handler(mmi_spa_sim_id_enum sim_id, mmi_spa_result_enum result);
#endif 
void mmi_spa_send_cca_sim_profile_status_ind(mmi_spa_sim_id_enum sim_id, U32 flag);
void mmi_spa_send_cca_new_doc_ind(U32 flag, mmi_spa_sim_id_enum sim_id, S32 hConfig);
void mmi_spa_send_empty_cca_new_doc(mmi_spa_sim_id_enum sim_id);
void mmi_spa_send_cca_new_setting_ind(mmi_spa_sim_id_enum sim_id, U32 msg_id, U32 *trans_id);

mmi_spa_result_enum mmi_spa_mmsicp_parser(void *param, spa_sim_ef_parse_callback_fn callback);
void mmi_spa_ef_release_cca_config(S32 hConfig);
U8 mmi_spa_sim_id_convert(mmi_spa_sim_id_enum sim_id);
mmi_sim_enum mmi_spa_sim_id_spa2mmi(mmi_spa_sim_id_enum sim_id);
MMI_BOOL mmi_spa_check_hconfig(S32 hConfig);
MMI_BOOL mmi_spa_is_sim_changed(mmi_spa_sim_id_enum sim_id);
void mmi_spa_set_sim_changed_status_ok(mmi_spa_sim_id_enum sim_id);
S32 mmi_spa_get_ef_table_size(void);
void mmi_spa_update_sim_changed_flag(void);
mmi_spa_sim_id_enum mmi_spa_sim_id_converter_cca2spa(mmi_cca_sim_id_enum cca_sim_id);

#ifdef SPA_EF_TEST
void mmi_spa_clear_ef_process_flags(void);
void mmi_spa_set_cur_ef_file_idx(mmi_spa_sim_id_enum sim_id, S8 *file);
void mmi_spa_set_test_code_on(void);
void mmi_spa_set_test_code_off(void);
MMI_BOOL mmi_spa_is_test_code_on(void);
MMI_BOOL mmi_spa_is_test_code_open(void);
void mmi_spa_test_code_open_init(void);
#endif /* SPA_EF_TEST */ 

#ifndef MMI_SPA_JOB_SUPPORT

mmi_spa_result_enum mmi_spa_ef_hdlr(mmi_spa_sim_id_enum sim_id, spa_sim_ef_process_callback callback);
void mmi_spa_cca_new_doc_rsp_handler(mmi_spa_sim_id_enum sim_id);

#else /* MMI_SPA_JOB_SUPPORT */ 

void mmi_spa_cca_new_doc_rsp_handler(mmi_cca_source_new_doc_rsp_struct *data);
MMI_BOOL mmi_spa_is_job_type_exist(mmi_spa_sim_id_enum sim_id, mmi_spa_job_type_enum type);
MMI_BOOL mmi_spa_add_sim_ef_jobs(mmi_spa_sim_id_enum sim_id, mmi_spa_job_type_enum type);
void mmi_spa_remove_sim_ef_jobs(mmi_spa_sim_id_enum sim_id, mmi_spa_job_type_enum type);
void mmi_spa_start_next_job(void);
MMI_BOOL mmi_spa_is_sim_available(mmi_spa_sim_id_enum sim_id);
U32 mmi_spa_get_sim_flag(void);
cca_status_enum mmi_spa_convert_result_spa2cca(mmi_spa_result_enum result);
void mmi_spa_send_cca_invalid_setting_ind(mmi_spa_sim_id_enum sim_id, U32 msg_id, cca_status_enum status);

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
void mmi_spa_set_ef_saved_state_in_table(mmi_spa_sim_id_enum sim_id, U16 saved_flags);
void mmi_spa_send_provbox_save_msg_data_req(
        mmi_spa_sim_id_enum sim_id,
        mmi_provbox_msg_type_enum msg_type,
        mmi_provbox_save_msg_req_struct *msg_data,
        U32 *trans_id);
U8 mmi_spa_provbox_save_msg_data_cnf_hdlr(void *msg, int src_mod, void *peer_buf);
void mmi_spa_provbox_save_msg_data_cnf_handler(mmi_provbox_save_msg_cnf_struct *data);
U8 mmi_spa_cca_install_msg_req_hdlr(void *msg, int src_mod, void *peer_buf);
void mmi_spa_cca_install_msg_req_handler(mmi_cca_source_install_prov_msg_req_struct *data);
void mmi_spa_send_cca_install_msg_cnf(mmi_spa_sim_id_enum sim_id, U32 msg_id, U32 trans_id, mmi_spa_result_enum result);
mmi_spa_result_enum mmi_spa_provbox_get_msg_data_cnf_handler(mmi_provbox_get_msg_data_cnf_struct *data);
void mmi_spa_send_provbox_get_msg_data_req(U32 msg_id, U32 *trans_id);
U8 mmi_spa_provbox_get_msg_data_cnf_hdlr(void *msg, int src_mod, void *peer_buf);
void mmi_spa_get_ef_saved_state_in_table(U16 *saved_flags);
void mmi_spa_write_ef_saved_flag_to_nvram(void);
U8 mmi_spa_provbox_save_msg_available_ind_hdlr(void *msg, int src_mod, void *peer_buf);
void mmi_spa_provbox_save_msg_available_ind_handler(mmi_provbox_save_msg_available_ind_struct *data);

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

#endif /* MMI_SPA_JOB_SUPPORT */ 

#endif /* __SPA_SUPPORT__ */ 
#endif /* MMI_SPA_PROT_H */ 

