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
 * MMSAppScrHdlrEx.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_SH_HDLREX_H
#define MMS_APP_SH_HDLREX_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMSAppUICommon.h"
#include "MMIDataType.h"
#include "wgui_categories_MMS_viewer.h"
#include "MmsSrvGprot.h"
#include "kal_general_types.h"
#define _SLIM_32_32_
#ifdef _SLIM_32_32_
extern void mmi_umms_app_sh_option_slim_delete_scr_handler(void);
extern mmi_ret mmi_umms_app_sh_show_recipient_list_delete_scr_handler(mmi_event_struct *scrDB);
extern void mmi_umms_app_if_show_recipient_list(void);
#endif /* _SLIM_32_32_ */ 
extern MMI_UMMS_ERROR mmi_umms_app_sh_init_function(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_sh_create_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_sh_template_create_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_sh_create_popup_func(U16 scr_id);

extern void mmi_umms_app_sh_static_list_lsk_handler(void);
extern void mmi_umms_app_sh_static_list_rsk_handler(void);
extern mmi_ret mmi_umms_app_sh_dynamic_list_delete_scr_handler(mmi_event_struct *data);
extern void mmi_umms_app_sh_dynamic_list_hilite_handler(S32 index);
extern void mmi_umms_app_sh_save_objects_attachment_list_lsk_handler(void);
extern void mmi_umms_app_sh_progress_screen_exit_func(void);
extern mmi_ret mmi_umms_app_sh_progress_delete_screen(mmi_event_struct *data);
extern void mmi_umms_app_sh_draft_options_exit_func(void);
extern void mmi_umms_app_sh_confirm_screen_exit_func(void);
extern void mmi_umms_app_sh_viewer_exit_func(void);
extern mmi_ret mmi_umms_app_sh_viewer_delete_scr_handler(mmi_event_struct *data);
extern void mmi_umms_app_sh_read_delivery_report_view_exit_func(void);
extern void mmi_umms_app_sh_viewer_hilitte_hdlr(srv_mms_viewer_use_details_list *current_node);

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_umms_app_sh_viewer_hilitte_click_hdlr(srv_mms_viewer_use_details_list *current_node);
#endif 
extern void mmi_umms_app_sh_highlighted_number_call(void);
extern void mmi_umms_app_sh_entry_use_url_go_to(void);
extern void mmi_umms_app_sh_use_email_send_email(void);
extern void mmi_umms_app_sh_viewer_lsk_hdlr(void);
extern void mmi_umms_app_sh_viewer_rsk_handler(void);
extern mmi_ret mmi_umms_app_sh_use_details_list_delete_scr_handler(mmi_event_struct *scrDB);
extern void mmi_umms_app_sh_mms_options_exit_func(void);
extern mmi_ret mmi_umms_app_sh_inline_selection_delete_scr_handler(mmi_event_struct *scrDB);
extern void mmi_umms_app_sh_mms_new_notification_exit_func(void);
extern void mmi_umms_app_sh_mms_full_exit_func(void);
extern void mmi_umms_app_dtmgr_update_data_for_use_details(void *data);

#if(MMI_MAX_SIM_NUM == 2)
extern void mmi_umms_app_sh_sim_options_exit_func(void);
#endif 
extern void mmi_umms_app_sh_read_delivery_report_view_lsk_handler(void);
extern void mmi_umms_app_sh_read_delivery_report_view_rsk_handler(void);
extern void mmi_umms_app_ui_plug_in_confirm_save_sending_settings(void);
extern void mmi_umms_app_ui_plug_in_confirm_save_compose_settings(void);
extern void mmi_umms_app_ui_plug_in_confirm_save_retrieval_settings(void);

extern void mmi_umms_confirm_save_sending_settings(void);
extern void mmi_umms_confirm_save_compose_settings(void);
extern void mmi_umms_confirm_save_retrieval_settings(void);
extern void mmi_umms_app_ui_plug_in_filter_done_handler(void);
extern void mmi_umms_retrieval_settings_filter_selection_lsk_handler(void);
extern void mmi_umms_app_if_show_use_number(void);
extern void mmi_umms_app_if_show_use_email(void);
extern void mmi_umms_app_if_show_use_url(void);
extern void mmi_umms_app_if_show_use_sender(void);
extern void mmi_umms_app_if_show_use_recipient(void);
extern void mmi_umms_app_sh_popup_screen_exit_func(void);
extern void mmi_umms_app_sh_send_read_report_yes(void);
extern void mmi_umms_app_sh_send_read_report_no(void);

extern void mmi_umms_app_sh_delete_umms_screens(void);
extern void mmi_umms_app_sh_delete_umms_use_details_screens(void);
extern void mmi_umms_app_sh_delete_umms_save_objects_screens(void);
extern void mmi_umms_app_sh_delete_progress_screen(void);
extern void mmi_umms_app_sh_go_to_box_list_screen(void);
extern void mmi_umms_app_sh_delete_screen_reset_globals(void);
extern void mmi_umms_app_sh_show_corrupt_and_delete(void);
extern void mmi_umms_app_sh_show_unsupported_and_delete(void);
extern void mmi_umms_app_sh_get_msg_info_from_bgsr_callback_for_update(
                U32 msg_id,
                srv_mms_bgsr_msg_info_struct *msg_info);
#ifdef __MMI_OP12_TOOLBAR__
extern void mmi_umms_app_sh_display_msg_for_tb(U32 msg_id);
#endif 

extern void mmi_umms_app_sh_return_to_um_list(void);
extern void mmi_umms_app_sh_display_working_space_popup(kal_uint32 min_fs_space_required);
extern void mmi_umms_app_sh_show_screen_based_on_msg_status(U32 msg_id);
extern mmi_ret mmi_umms_app_sh_userdef_template_delete_scr_handler(mmi_event_struct *data);

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_sh_mms_delete_lsk_handler_for_msg_list(void);
#endif 
extern void mmi_umms_app_sh_mms_option_mms_handler(U16 hilite_menu, U16 sender_id);
extern void mmi_umms_app_sh_signature_options_handler(U16 hilite_menu);

#if(MMI_MAX_SIM_NUM >= 2)
extern void mmi_umms_app_sh_settings_sim_selection_handler(U16 hilite_menu);
#endif 
extern void mmi_umms_app_sh_use_detail_options_hdlr(U16 hilite_menu);
extern void mmi_umms_app_sh_save_objects_list_handler(U16 hilite_menu);
extern void mmi_umms_app_sh_sim_option_mms_handler(U16 hilite_menu);
extern void mmi_umms_app_sh_signature_options_handler(U16 hilite_menu);
extern mmi_ret mmi_umms_app_sh_infinite_pop_up_delete_scr_handler(mmi_event_struct *data);

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern void mmi_umms_app_sh_show_recipient_list_lsk_handler(void);
extern void mmi_umms_app_sh_show_recipient_list_hilite_handler(S32 index);
extern void mmi_umms_app_sh_option_slim_menu_rsk_handler(void);

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_SH_HDLREX_H */ 

