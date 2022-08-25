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

/*******************************************************************************
 * Filename:
 * ---------
 * MMSAppSrvHdlr.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_SRV_HDLR_H
#define MMS_APP_SRV_HDLR_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "MMSAppUICommon.h"
#include "UmSrvGprot.h"
#include "MmsXMLDefSrv.h"
#include "mmi_frm_events_gprot.h"
#include "MmsSrvGprot.h"

#include "WAPProfileSrvType.h"
 
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif 
#include "kal_general_types.h"
#include "mmiapi_dm_struct.h"
#include "UMGProt.h"

#define   MMI_UMMS_DOWNLOAD_TIMER                   2000

extern void mmi_umms_app_core_mms_app_asm_success_callback(void);
extern void mmi_ummsapp_core_mms_app_asm_stop_callback(void *user_data);
extern void mmi_umms_app_core_asm_viewer_stop_callback(void *user_data);
extern void mmi_umms_app_core_asm_viewer_success_callback(void);
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
 extern void mmi_umms_app_core_asm_viewer_cancel_callback(void *user_data);
#endif
extern void mmi_umms_app_core_msg_entry_new_msg_popup(U8 type, U8 tone);
extern MMI_UMMS_ERROR mmi_umms_app_core_handle_view(void);
extern void mmi_umms_app_core_delete_msg_notify_callback(U32 msg_id, kal_uint8 result);
extern void mmi_umms_app_core_delete_all_msg_callback(srv_mms_result_enum result, void *rsp_data, void *user_data);
extern void mmi_umms_app_core_delete_all_msg_notify_callback(U32 msg_id, kal_uint8 result);
extern S32 mmi_umms_app_core_um_delete_folder_callback(S32 pid, srv_um_delete_folder_result *rsp, S32 para);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_umms_app_core_move_to_archive_msg_notify_callback(U32 msg_id, kal_uint8 result);
#endif 


extern void mmi_umms_app_dtmgr_sim_validation(void);

extern MMI_RET mmi_umms_app_core_check_crnt_selected_msg(mmi_event_struct *);
extern void mmi_umms_app_core_mark_several_rsp_handle(srv_mms_result_enum result, void *msgrsp, S32 user_data);
extern void mmi_umms_app_core_get_option_scrn_data_callback(srv_mms_result_enum result, void *msgrsp, S32 user_data);
extern void mmi_umms_app_core_viewer_info_callback(srv_mms_result_enum result, void *msgrsp, void *user_data);
extern MMI_UMMS_ERROR mmi_umms_app_core_handle_view_option(void);
extern void mmi_umms_app_core_get_use_details_list_cb(void *msgrsp);
extern MMI_RET mmi_umms_app_core_show_mms_status_icon(mmi_event_struct *);
extern void mmi_umms_app_core_get_list_info_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_core_get_template_msg_info_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_core_get_template_delete_all_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_core_get_create_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern MMI_RET mmi_umms_app_core_exit_viewer_application(mmi_event_struct *);
extern void mmi_umms_app_core_viewer_show_error_popup(srv_mms_viewer_result_enum result, S32 file_error_type);
extern void mmi_umms_app_core_get_msg_info_from_bgsr_callback(U32 msg_id, srv_mms_bgsr_msg_info_struct *msg_info);
extern void mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view(
                U32 msg_id,
                srv_mms_bgsr_msg_info_struct *msg_info);

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
extern MMI_BOOL mmi_umms_app_core_get_recent_event(void);
extern MMI_BOOL mmi_umms_app_core_get_hs_active(void);
extern MMI_RET mmi_umms_app_core_set_new_mms_arrived(mmi_event_struct *);
extern void mmi_umms_app_core_hs_get_header(U32 msg_id, U16 key_code, BOOL is_recent_event);
extern void mmi_umms_app_core_show_cofirm_pop_up_for_clear_event(void);
extern void mmi_umms_app_core_entry_clear_event(void);
extern void mmi_umms_app_core_clear_recent_event_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data);
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 

extern void mmi_umms_app_core_save_template_file_callback(S32 copy_result);
extern void mmi_umms_app_core_create_template_file_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_core_save_template_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern MMI_BOOL mmi_umms_app_core_pre_display_message(U32 msg_id);
extern void mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_pre_display_msg(
                U32 msg_id,
                srv_mms_bgsr_msg_info_struct *msg_info);
extern void mmi_umms_app_core_show_option(void);
extern void mmi_umms_app_core_display_message(U32 msg_id);
extern MMI_UMMS_ERROR mmi_umms_app_core_get_msg_state_from_mma(void);
extern MMI_RET mmi_umms_app_core_check_crnt_selected_msg_for_update(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_wap_ready_hdlr(mmi_event_struct *);

/* memory card   */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern MMI_RET mmi_umms_app_core_handle_change_storage_rsp(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_handle_template_error_event(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_handle_sd_card_plug_out(mmi_event_struct *);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/* memory card  */
extern MMI_RET mmi_umms_app_core_memory_status_screen_update(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_display_invalid_popup(mmi_event_struct *);
extern void mmi_umms_app_core_deinit_viewer_and_globals_and_go_to_box_list(void);
extern MMI_RET mmi_umms_app_core_mms_display_uri_confirm_popup(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_update_use_details_list(mmi_event_struct *);
extern void mmi_umms_app_core_view_or_replace(void);
extern void mmi_umms_app_core_send_rr_confirm_or_replace(void);
extern void mmi_umms_app_core_show_progress_screen_with_no_history(void);


extern void mmi_umms_app_core_updated_profile_send_callback(
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_app_id_enum app_id,
                U8 profile_id,
                srv_wap_prof_result_enum configure_dtcnt_rsp);
extern void mmi_umms_app_core_profile_download_callback(
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_app_id_enum app_id,
                U8 profile_id,
                srv_wap_prof_result_enum configure_dtcnt_rsp);

extern MMI_RET mmi_umms_app_core_update_template_list_after_phone_suite_delete(mmi_event_struct *);
extern void mmi_umms_app_core_bootup_init_template_folder_data(void);
extern MMI_RET mmi_umms_app_core_bootup_init(mmi_event_struct *);
extern void mmi_umms_app_core_show_use_details_progress(void);
extern void mmi_umms_app_core_sim_status_info(void);
extern MMI_RET mmi_umms_app_core_show_error_popup(mmi_event_struct *);

#ifdef __DM_LAWMO_SUPPORT__
extern mmi_ret mmi_umms_app_core_mo_type_lawmo_lock_callback_hdlr(mmi_event_struct* evt);
extern mmi_ret mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr(mmi_event_struct* evt);
extern void mmi_umms_app_core_remove_all_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data);
#endif /* __DM_LAWMO_SUPPORT__ */ 

extern MMI_RET mmi_umms_app_core_get_storage_full_ind_data(mmi_event_struct *);
extern void mmi_umms_app_core_handle_download_timer_expiry(void);
extern void mmi_umms_app_core_no_duration_popup(U8 *str, U8 event_type);
extern void mmi_umms_app_core_show_memory_full_pop_up(U32 min_sapce_required, MMI_BOOL flag);

extern void mmi_umms_app_core_set_backgroundaudioresume(MMI_BOOL backgroundaudioresume);
extern MMI_BOOL mmi_umms_app_core_get_backgroundaudioresume(void);
extern MMI_BOOL srv_mms_check_send_ota_mms_settings_rsp_to_profile(void *rsp_data);

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_core_delete_msg_notify_for_msg_list_callback(U32 msg_id, kal_uint8 result);
#endif 
extern MMI_RET mmi_umms_app_core_save_rsp_from_uc(mmi_event_struct *);

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern MMI_BOOL mmi_umms_app_core_get_hs32_active(void);
extern void mmi_umms_app_core_set_hs32_new_mms_arrived(MMI_BOOL is_new_mms_arrived);
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 
#if(MMI_MAX_SIM_NUM == 2)
extern MMI_RET mmi_umms_app_core_check_card_plug_out_handling(mmi_event_struct *);
#endif 
#ifdef __MMI_MMS_ITERATOR_VIEWER__
extern MMI_UMMS_ERROR mmi_umms_app_core_query_indexing_for_template_iter_view(mmi_um_iter_viewer_result_struct *data);
extern void mmi_umms_app_core_um_data_ready_cb(void *user_data);
extern MMI_UMMS_ERROR mmi_umms_app_core_prepare_data_before_deinit(
                        mmi_um_iter_viewer_result_struct *other_msg_data,
                        U8 *folder_id,
                        void **user_data);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
#ifdef __MMI_MMS_USE_ASM__
extern mmi_ret mmi_umms_app_core_asm_success(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_asm_stop(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_asm_cancel(mmi_event_struct *param);
#endif /* __MMI_MMS_USE_ASM__ */ 
extern MMI_RET mmi_umms_app_core_mms_display_popup_for_bgsr(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_hanlde_save_objects_copy_result(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_display_bgsr_popup(mmi_event_struct *);

#ifdef __MMI_SLIM_MMS_2__
extern U16 mmi_umms_app_core_bgsr_translate_result_to_strid(srv_mms_bgsr_result_enum bgsr_result, U8 send_flag);
#else 
extern U16 mmi_umms_app_core_bgsr_translate_result_to_strid(srv_mms_bgsr_result_enum bgsr_result);
#endif 
extern mmi_ret mmi_umms_app_core_show_hide_status_icon(mmi_event_struct *evt);
extern mmi_ret mmi_umms_app_core_dummy_listener(mmi_event_struct *evt);
extern mmi_ret mmi_umms_app_core_get_current_msg_box(mmi_event_struct *evt);

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
extern MMI_RET mmi_umms_app_core_display_jsr_popup(mmi_event_struct *evt);
#endif 
#endif /* __MMI_MMS_2__ */ 

#endif /* MMS_APP_SRV_HDLR_H */ 

