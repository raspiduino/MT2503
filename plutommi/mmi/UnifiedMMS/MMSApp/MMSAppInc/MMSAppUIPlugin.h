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
 * MMSAppUILogic.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_UI_LOGIC_H
#define MMS_APP_UI_LOGIC_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMSAppUICommon.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "MessagesMiscell.h"
#ifdef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
#define         MMI_UMMS_STOP_CORRUPT_DWNLD       0x0B
#define         MMI_UMMS_STOP_UNRECONIZED_NOTIFICATION       0x0C
#endif /* __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__ */ 

#if (defined(__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__))
#define  __MMI_OP01_202_DEFFERED_DOWNLOAD_AT_FULL_IND__
#endif 
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_option_slim_menu_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_option_slim_menu_post_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_add_recipient_list_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_add_recipient_list_post_func(U16 scr_id);
extern void mmi_umms_app_ui_plug_in_create_dynamic_scrn_data(U16 hilite_menu);
extern U16 mmi_umms_app_ui_plug_in_recipient_items_number(void);
extern U16 mmi_umms_app_ui_plug_in_get_hilite_item(U16 scr_id);
extern void mmi_umms_app_ui_plug_in_set_hilite_item(U16 scr_id, U16 temp);

extern MMI_BOOL mmi_umms_app_ui_plug_in_called_from(void);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_delete_option_screen(U8 folder_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_notification_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_notification_post_func(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_full_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_full_post_func(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_draft_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_draft_options_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_mms_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_mms_options_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_notification_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_notification_options_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_read_delivery_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_read_delivery_options_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_java_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_inbox_java_options_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sent_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sent_options_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_outbox_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_outbox_options_post_func(U16 MMI_UMMS_SCR_ID);

#if(MMI_MAX_SIM_NUM == 2)
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sim_options_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sim_options_post_func(U16 MMI_UMMS_SCR_ID);
#endif /* (MMI_MAX_SIM_NUM == 2) */ 
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_progress_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_progress_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_template_menu_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_template_menu_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_user_template_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_user_template_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_confirm_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_confirm_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_set_archive_confirm_func(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_get_archive_confirm_func(void);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_option_handling(U16 hilite_menu, U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sim_option_handling(U16 hilite_menu, U16 scr_id);

extern void mmi_umms_app_ui_plug_in_add_to_phb_list_and_deinit_umms(void);
extern void mmi_umms_app_ui_plug_in_add_contact_phonebook_notify(void);
extern void mmi_umms_app_ui_plug_in_check_phb_interface_for_num_add(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_popup_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_popup_post_func(U16 MMI_UMMS_SCR_ID);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_set_archive_confirm_func(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_get_archive_confirm_func(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_option_handling(U16 hilite_menu, U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_viewer_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_viewer_post_func(U16 scr_id);
extern void mmi_umms_app_ui_plugin_viewer_lsk_hdlr(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_use_details_list_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_use_details_list_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_reset_use_details_list_data(U16 scr_id);

#ifdef __MMI_MMS_PREVIEW_GOTO__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_preview_slide_list_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_preview_slide_list_post_func(U16 scr_id);
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_preview_option_handling(U16 hilite_menu, U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_rr_yes_hdlr(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_rr_no_hdlr(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_recipient_screen_hdlr(U16 hilite_menu, U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_draw_cui_static_list_draw_func(U16 scr_id);

/************************************Niraj Added*****************************/
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_message_settings_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_message_settings_menu_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_message_settings_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_message_settings_menu_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_compose_settings_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_compose_settings_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_retrieval_settings_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_retrieval_settings_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_retrieval_filters_settings_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_retrieval_filters_settings_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sending_settings_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sending_settings_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_compose_signature_settings_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_compose_signature_settings_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_signature_options_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_signature_options_post_func(U16 scr_id);

/************************************Amit Added*****************************/
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_memory_status_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_memory_status_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_save_objects_attachment_list_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_save_objects_attachment_list_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_save_objects_list_pre_func(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_save_objects_list_post_func(U16 static_scr);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_properties_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_properties_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_use_recipient_post_func(U16 scr_id);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sort_by_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sort_by_post_func(U16 scr_id);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_use_details_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_use_details_menu_post_func(U16 scr_id);

#ifdef __MMI_MMS_PREVIEW_GOTO__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_preview_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_mms_preview_menu_post_func(U16 scr_id);
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_java_options_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_java_options_menu_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sim_selection_profile_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_app_ui_plug_in_sim_selection_profile_menu_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_notification_option_screen_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_notification_option_screen_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_report_options_screen_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_report_options_screen_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_sim_options_resend_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_sim_options_resend_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_use_details_addresses_options_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_use_details_addresses_options_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_message_status_screen_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_message_status_post_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_new_message_popup_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_new_message_popup_post_func(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_user_defined_options_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_user_defined_options_post_func(U16 scr_id);

/* Amitesh For Progress */
extern void *mmi_umms_app_ui_plug_in_progress_scrn_data(void);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_template_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_template_menu_post_func(U16 scr_id);

extern void mmi_umms_app_ui_plug_in_compose_inline_custom_func(void);

extern void mmi_umms_compose_image_select_path_from_file_manager(S8 *path);
extern void mmi_umms_compose_video_select_path_from_file_manager(S8 *path);
extern void mmi_umms_compose_audio_select_path_from_file_manager(S8 *path);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_archive_confirm_func(void);
#endif 
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_delete_confirm_func(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_delete_all_confirm_func(void);
extern void mmi_umms_app_ui_plug_in_final_edit(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_properties_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_properties_post_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_abnormal_view_post_func(U16 MMI_UMMS_SCR_ID);
extern void mmi_umms_app_ui_plug_in_redraw_dr(void);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sort_by_pre_func(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_sort_by_post_func(U16 MMI_UMMS_SCR_ID);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
extern void mmi_umms_app_ui_plug_in_download_using_other_sim(void);
extern void mmi_umms_app_ui_plug_in_download(void);
extern void mmi_umms_app_ui_plug_in_download_continue(void);
extern void mmi_umms_app_ui_plug_in_download_req(const U32 msg_id, U32 time, U32 msg_size);
extern void mmi_umms_app_plug_in_pre_entry_send_msg(void);
extern void mmi_umms_app_ui_plug_in_download_cancel_by_pressing_no(void);
extern void mmi_umms_app_plug_in_entry_send_msg_from_box_ext(void);
extern void mmi_umms_app_plug_in_entry_send_msg_from_box(const U32 msg_id);
extern void mmi_umms_app_plug_in_send_mms_msg(const U32 msg_id);
extern void mmi_umms_app_plug_in_entry_cancel_send(void);

extern void mmi_umms_app_plug_in_wap_connection_error_popup(U32 element_size, U32 max_msg_size, U16 str_id);
extern void mmi_umms_signature_done_handler(void);

#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
extern void mmi_umms_app_callback_lsk_funct_add_audio(void);
#endif 

#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
extern void mmi_umms_app_callback_lsk_funct_add_video(void);
#endif 

#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
extern void mmi_umms_app_callback_lsk_funct_add_image(void);
#endif 

extern void mmi_umms_app_ui_plug_in_goto_slide(U16 slide_num);
extern void mmi_umms_ui_plug_in_audio_msg_view(void);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_default_template_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_default_template_post_func(U16 scr_id);
extern void mmi_umms_app_ui_plug_in_exit_confirm_screen(void);

extern void mmi_umms_app_ui_plug_in_set_lock_mode_req(void);
extern void mmi_umms_app_ui_plug_in_save_to_contacts(void);

extern void mmi_umms_app_ui_plug_in_set_inline_compose_settings_to_nvram(void);
extern void mmi_umms_app_ui_plug_in_set_inline_retrieval_settings_to_nvram(void);
extern void mmi_umms_app_ui_plug_in_set_inline_sending_settings_to_nvram(void);
extern void mmi_umms_app_ui_plug_in_save_as_template(U32 msgId);
extern void mmi_umms_app_ui_plug_in_show_manual_play_slide_list(void);
extern void mmi_umms_app_ui_plug_in_template_view_by_csk(void);
extern void mmi_umms_app_ui_plug_in_use_details_list_addresses_options_lsk_handler(U16 hilite_menu);
extern void mmi_umms_app_ui_plug_in_use_details_list_addresses_list_hilite_handler(S32 index);

extern void mmi_umms_use_details_address_insert_hdlr(U8 *address);
extern void mmi_umms_mms_address_insert_hdlr(U8 *address);
extern void mmi_umms_truncate_send_sms_interface_to_uc_callback(void);
extern void mmi_umms_truncate_send_mms_interface_to_uc_callback(void);
extern void mmi_umms_truncate_send_email_interface_callback(void);

extern void mmi_umms_app_ui_plug_in_use_email_as_save_to_phb(void);
extern void mmi_umms_app_ui_plug_in_use_email_as_send_email(void);
extern void mmi_umms_app_ui_plug_in_use_details_common_as_send_mms(void);
extern void mmi_umms_app_ui_plug_in_use_number_as_make_call(void);
extern void mmi_umms_app_ui_plug_in_use_number_as_save_to_phb(void);
extern void mmi_umms_app_ui_plug_in_use_number_as_send_sms(void);
extern void mmi_umms_app_ui_plug_in_use_url_as_browser_launch(void);
extern void mmi_umms_app_ui_plug_in_use_url_as_save_to_bookmark(void);
extern void mmi_umms_app_ui_plug_reset_settings_common_list_data(void);
extern void mmi_umms_app_ui_plug_in_compose_settings_signature_selection_lsk_handler(void);
extern void *mmi_umms_app_ui_plug_in_get_confirm_func(void);
extern void mmi_umms_app_ui_plug_in_forward(void);

extern void mmi_umms_app_ui_plug_in_entry_edit_fwd_mode(void);
extern void mmi_umms_app_ui_plug_in_reply_as_sms(void);
extern void mmi_umms_app_ui_plug_in_reply(void);
extern void mmi_umms_app_ui_plug_in_handle_mms_template_option(void);
extern U8 mmi_umms_get_app_ui_plug_in_change_in_filters(void);
extern void mmi_umms_app_ui_plug_in_preview_slide_list_hdlr(U16 scr_id);
extern U8 mmi_umms_app_ui_plug_in_get_change_in_compose_signature(void);

#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__)
extern BOOL mmi_umms_composer_signature_check_object(S8 *path, U8 object_type);
#endif 

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_pref_storage_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_pref_storage_post_func(U16 scr_id);
extern void mmi_umms_app_plug_in_move_done(void);
extern void mmi_umms_app_plug_in_copy_done(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_pref_storage_menu_handling(U16 hilite_menu, U16 scr_id);
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_msg_filter_menu_handling(mmi_event_struct* evt);
#endif
extern void mmi_umms_app_ui_callback_move_copy_options_hide_unhide(void);
extern void mmi_umms_app_ui_callback_move_copy_options_hide_all(void);
extern void mmi_umms_app_plug_in_download_in_other_memory(void);
extern MMI_BOOL mmi_umms_app_ui_plug_in_check_downloading_with_memory_card_support(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */ 

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_settings_sim_selection_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_settings_sim_selection_post_func(U16 scr_id);

extern void mmi_umms_app_ui_plug_in_show_sim_profile(mmi_sim_enum sim_id);

extern void mmi_umms_app_app_ui_plug_in_network_changed_from_immd_to_deffered_callback(void);
extern void mmi_umms_app_ui_plug_in_save_viewer_objects(U16 menu_id);
extern void mmi_umms_app_ui_plug_in_save_attachmant_data_in_mms(void);
extern void mmi_umms_app_ui_plug_in_check_and_update_signature_file_info(void);
extern void mmi_umms_app_ui_plug_in_check_and_update_signature_file_info_first(void);
extern void mmi_umms_app_ui_plug_in_lsk_funct_pre_signature_restricted(void);
extern void mmi_umms_app_ui_plug_in_rsk_funct_pre_signature_restricted(void);
extern void mmi_umms_app_ui_plug_in_lsk_funct_pre_signature_warning(void);
extern void mmi_umms_app_ui_plug_in_check_sending_settings_check_before_save(void);
extern void mmi_umms_app_ui_plug_in_template_error_popup_handling(S32 result);
extern void mmi_umms_ui_plug_in_read_report_cancel_hdlr(void);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern U8 mmi_umms_app_ui_plug_in_get_prefer_storage_hilighted_index(void);
#endif 
#ifdef __MMI_EMAIL__
extern void mmi_umms_app_ui_plug_in_use_email_as_send_email_viewer(U8 *string);
extern void mmi_umms_truncate_send_email_interface_view_callback(void);
#endif /* __MMI_EMAIL__ */ 
extern void mmi_umms_app_ui_plug_in_use_url_as_browser_launch_viewer(U8 *string);
extern void mmi_umms_app_ui_plug_in_use_number_as_make_call_viewer(U8 *string);
extern MMI_BOOL mmi_umms_ui_plug_in_profile_validation(U8 sim_id);
extern void mmi_umms_app_ui_plug_in_entry_use_details_csk(void);
extern void mmi_umms_app_ui_plug_in_hangup_calls(void);

//#ifdef __MMI_MMS_AUTO_SWITCH_TO_FIRST_SLIDE__
//extern void mmi_umms_app_ui_plug_in_goto_first_slide(void);
//#endif
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
extern void mmi_umms_app_ui_plug_in_viewer_back_key_pressed(void);
#endif 
extern U16 mmi_umms_app_ui_plug_in_get_csk_icon(void);
extern void mmi_umms_app_ui_plug_in_exec_csk_func(void);
extern U16 mmi_umms_app_ui_plug_in_get_lsk_str(void);
extern FuncPtr mmi_umms_app_ui_plug_in_get_lsk_fn(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_memory_status_menu_pre_func(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_memory_status_menu_post_func(U16 scr_id);
extern void mmi_umms_app_ui_plug_in_viewer_handover_to_category(void);
extern void mmi_umms_app_ui_plug_in_show_progress_screen_with_no_history(void);
extern MMI_RET mmi_umms_app_ui_plug_in_save_object_error_handling(mmi_event_struct *);
extern MMI_BOOL mmi_umms_app_ui_plug_in_check_progress_is_active(void);
extern MMI_RET mmi_umms_app_ui_plug_in_check_and_delete_progress_screen(mmi_event_struct *);

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_ui_plug_in_decide_toolbar_icon_and_string(void *fte_data);
extern void mmi_umms_app_ui_plugin_viewer_toolbar_hdlr(S32 index);
extern void mmi_umms_app_ui_plug_in_delete_mms_from_toolbar(void);
extern void mmi_umms_app_ui_plug_in_resend_mms_from_toolbar(void);
extern void mmi_umms_app_ui_plug_in_edit_mms_from_toolbar(void);
//extern void mmi_umms_app_ui_plug_in_disable_icon_if_any(void);

extern void mmi_umms_app_ui_plug_in_reply_as_sms_for_msg_list(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_delete_confirm_func_for_folder_list(void);
extern void mmi_umms_app_ui_plug_in_edit_fwd_mode_for_msg_list_toolbar(void);
extern void mmi_umms_app_ui_plug_in_edit_for_msg_list_toolbar(void);
extern void mmi_umms_app_ui_plug_in_send_msg_from_msg_list(void);
extern void mmi_umms_app_ui_plug_in_resend_msg_from_msg_list(void);
extern void mmi_umms_app_plug_in_pre_entry_send_msg_from_folder_list(void);

#endif /* __MMI_FTE_SUPPORT__ */ 
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_abnormal_view_pre_func(U16 scr_id);

#ifdef __MMI_MMS_ITERATOR_VIEWER__
extern void mmi_umms_app_ui_plug_in_abnormal_screen_option(void);
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_check_viewer_playing(void);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_dr_rr_status_pre_func(U16 scr_id);
#endif 
extern void mmi_umms_app_ui_plug_in_call_sender_viewer(void);

#if(MMI_MAX_SIM_NUM >=2)
extern void mmi_umms_app_ui_plug_in_download_with_sim_id(mmi_sim_enum sim_id);
#endif 
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_UI_LOGIC_H */ 

