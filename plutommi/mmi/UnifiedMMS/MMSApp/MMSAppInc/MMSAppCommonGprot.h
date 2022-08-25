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
 * MMSAppCommonGprot.h
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
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_COMMON_GPROT_H
#define MMS_APP_COMMON_GPROT_H

#ifdef __MMI_MMS_2__
#include "MsgViewerCuiGProt.h"
#include "MmsSrvGprot.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "UMGProt.h"
#endif 
#ifdef __MMI_MMS_POSTCARD__
#include "FileManagerGprot.h"
#endif 
#include "FileMgrCUIGProt.h"
/* mmsadp */
typedef void *(*umms_sync_op_mem_alloc_fn) (kal_uint32);
typedef void (*umms_sync_op_mem_free_fn) (void *);
extern mma_result_enum mma_mms_get_msg_report_status_info(
                        U32 msg_id,
                        wap_mma_mms_msg_report_status_struct *mms_msg_report_info,
                        umms_sync_op_mem_alloc_fn mem_alloc_fn,
                        umms_sync_op_mem_free_fn mem_free_fn);
extern MMI_BOOL mmi_umms_app_if_is_option_screen_present(void);
extern MMI_BOOL mmi_umms_app_if_end_call_is_download_in_progress(void);
extern void mmi_umms_app_if_show_message_settings_menu(void);
extern void mmi_umms_app_if_show_template_menu(void);
extern MMI_BOOL mmi_umms_app_interface_entry_from_um(U16 key, U32 msg_id, void *user_data, mmi_id parent_grp_id);

/* msgviewercuiadp.c */
extern void mmi_umms_app_if_start_viewer(U16, U32, void *, cui_msg_viewer_type_enum);

/* idlerecentevent.c */
extern void mmi_umms_op_hs_get_recent_mms(S32);

/* javaagencyutil.c */
extern MMI_BOOL mmi_umms_app_if_is_msg_screen_active(void);

/* mmsbgsrmain.c */
extern void mmi_umms_app_core_bgsr_free_mms_data_for_wipe_callback(U8 result);
extern mmi_ret mmi_umms_app_if_msg_in_view(mmi_event_struct *);
extern mmi_ret mmi_umms_app_if_is_mms_in_open_state(mmi_event_struct *);

/* mmsbgsrapp.c */
extern void mmi_umms_app_blink_status_icon_by_id(S32 icon_id);
extern void mmi_umms_app_hide_status_icon_by_id(S32 icon_id);
extern void mmi_umms_app_show_status_icon_by_id(S32 icon_id);

/* mmsjsr205.c */
extern mmi_ret mmi_umms_op_update_recent_event_list_from_phone_suit(mmi_event_struct *para);

/* mmi_rp_file_type_table */

extern void mmi_umms_fmgr_forward_mms_enabler(
                mmi_menu_id item_id,
                const WCHAR *filepath,
                const srv_fmgr_fileinfo_struct *fileinfo);
extern void mmi_umms_fmgr_to_mms_hdlr(
                mmi_menu_id item_id,
                const WCHAR *filepath,
                const srv_fmgr_fileinfo_struct *fileinfo);

/* ucappcore.c */
extern void mmi_umms_app_if_uc_request_to_deinit(void);

/* umadaptor.c */
#ifndef __COSMOS_MMI_PACKAGE__
extern mmi_ret umms_cb_hdlr(mmi_event_struct *, mmi_um_opt_para_struct *);
#endif 
extern mmi_id cui_umms_mms_templates_launch(mmi_id);
extern mmi_id cui_umms_mms_settings_launch(mmi_id);
extern mmi_menu_id umms_menu_query_function(U32);
extern U16 mmi_umms_app_if_get_um_box_type_from_msg_id(U32);

extern U16 mmi_umms_app_if_get_um_box_type_from_msg_id(U32);

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_if_reply_mms(mmi_id, U32);
extern void mmi_umms_app_if_forward_mms(mmi_id, U32);
extern void mmi_umms_app_if_edit_mms(mmi_id, U32);
extern void mmi_umms_app_if_send_mms(mmi_id, U32);
extern void mmi_umms_app_if_resend_mms(mmi_id, U32);
extern void mmi_umms_app_if_delete_mms(mmi_id, U32);
#endif /* __MMI_FTE_SUPPORT__ */ 

/* ucmsghdlrapp.c */
extern void *cui_umms_app_set_uc_preview_msg(U32, U8, U8);
extern mmi_id cui_umms_preview_mms_create(mmi_id);
extern void cui_umms_preview_mms_run(mmi_id, void *);
extern void cui_umms_preview_mms_close(mmi_id);

/* Callback Manager */
extern mmi_ret mmi_umms_drv_format_hdlr_cb(mmi_event_struct *);
extern mmi_ret mmi_umms_sd_card_plug_in_hdlr_cb(mmi_event_struct *);
extern mmi_ret mmi_umms_sd_card_plug_out_hdlr_cb(mmi_event_struct *);
extern MMI_RET mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_hanlde_save_objects_copy_result(mmi_event_struct *);
extern MMI_RET mmi_umms_app_core_display_bgsr_popup(mmi_event_struct *);

#ifdef __MMI_MMS_USE_ASM__
extern mmi_ret mmi_umms_app_core_asm_success(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_asm_stop(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_asm_cancel(mmi_event_struct *param);
#endif /* __MMI_MMS_USE_ASM__ */ 

extern mmi_ret mmi_umms_app_dtmgr_send_set_settings_to_service(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_show_error_popup(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_ui_plug_in_save_object_error_handling(mmi_event_struct *param);

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
extern mmi_ret mmi_umms_app_core_handle_template_error_event(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_update_template_list_after_phone_suite_delete(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag(mmi_event_struct *param);
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

extern mmi_ret mmi_umms_app_core_show_mms_status_icon(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_save_rsp_from_uc(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_bootup_init(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_display_invalid_popup(mmi_event_struct *param);

#ifdef __MMI_MMS_URI_AGENT__
extern mmi_ret mmi_umms_app_core_mms_display_uri_confirm_popup(mmi_event_struct *param);
#endif 

#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
extern mmi_ret mmi_umms_app_core_update_use_details_list(mmi_event_struct *param);

#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 

extern mmi_ret mmi_umms_app_core_exit_viewer_application(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_check_crnt_selected_msg_for_update(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_display_bgsr_popup(mmi_event_struct *param);

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
extern mmi_ret mmi_umms_app_core_set_new_mms_arrived(mmi_event_struct *param);
#endif 
extern mmi_ret mmi_umms_app_core_check_crnt_selected_msg(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_wap_ready_hdlr(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_get_storage_full_ind_data(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_memory_status_screen_update(mmi_event_struct *param);

#ifdef __MMI_MMS_DUAL_SIM__
extern mmi_ret mmi_umms_app_core_check_card_plug_out_handling(mmi_event_struct *param);
#endif 

extern mmi_ret mmi_umms_app_core_mms_display_popup_for_bgsr(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_hanlde_save_objects_copy_result(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(mmi_event_struct *param);

extern mmi_ret mmi_umms_app_core_mma_insuf_mem(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_mms_deinit(mmi_event_struct *param);

extern void mmi_umms_app_core_save_object(srv_mms_viewer_object_struct *object, void *obj_req);

extern void mmi_umms_set_current_msg_id_in_view(U32 msg_id);

extern U32 mmi_umms_get_current_msg_id_in_view(void);

#endif /* __MMI_MMS_2__ */ 

#endif /* MMS_APP_COMMON_GPROT_H */ /* MMS_APP_INTERFACE_GPROT_H */

