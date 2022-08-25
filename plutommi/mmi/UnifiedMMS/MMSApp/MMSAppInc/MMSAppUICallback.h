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
 * MMSAppUICallback.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_UI_CALLBACK_H
#define MMS_APP_UI_CALLBACK_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "MMSAppUICommon.h"
#include "gui_typedef.h"
#include "wgui_categories_MMS_viewer.h"
#include "kal_general_types.h"
#include "mmi_frm_gestures_gprot.h"
#include "wgui_touch_screen.h"

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern S32 mmi_umms_app_ui_callback_recipient_options_decide(U16 menu_id);
extern S32 mmi_umms_app_ui_callback_get_recipient_list(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item);
extern MMI_UMMS_ERROR mmi_umms_app_ui_callback_prop_hide_all_menu_options(U16 scr_id);
extern U16 mmi_umms_app_ui_callback_composer_options_decide(U16 menu_id);
extern void mmi_umms_app_ui_callback_process_entry_write_msg(U8 mode);
extern void mmi_umms_app_ui_callback_uc_show_error_and_exit(mma_insert_check_struct *check_result);
extern void mmi_umms_app_ui_callback_move_to_attachment(mma_mms_slide_object_struct *media);
extern U16 mmi_umms_app_ui_callback_compose_option_decide(U16 scrn_id);
extern mmi_ret mmi_umms_app_ui_callback_slim_sim_sel_proc(mmi_event_struct *evt);
extern U16 mmi_umms_app_ui_callback_insert_options_decide(U16 menu_id);
#ifdef __MMI_FTE_SUPPORT__
extern MMI_BOOL  mmi_umms_app_ui_callback_decide_enable_disable_insert_tool(void);
#endif
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
extern U16 *mmi_umms_app_ui_callback_mms_options_menu_item_list(U16 menu_id, U16 *str_item_list);
extern const U16 *mmi_umms_app_ui_callback_mms_options_menu_list_of_icon(U16 MMI_UMMS_SCR_ID);

extern S32 mmi_umms_app_ui_callback_draft_options_decide(U16 MMI_UMMS_SCR_ID);
extern MMI_UMMS_ERROR mmi_umms_app_ui_callback_prop_unhide_all_menu_options(U16 scr_id);

extern S32 mmi_umms_app_ui_callback_inbox_mms_options_decide(U16 scr_id);
extern void mmi_umms_app_ui_callback_download_options_decide(mmi_event_struct *evt);
extern S32 mmi_umms_app_ui_callback_inbox_notification_options_decide(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_inbox_read_delivery_options_decide(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_sent_options_decide(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_inbox_java_mms_options_decide(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_outbox_options_decide(U16 scr_id);
extern void mmi_umms_app_ui_callback_resend_options_decide(mmi_event_struct* evt);
extern S32 mmi_umms_app_ui_callback_default_template_options_decide(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_user_defined_template_options_decide(U16 scr_id);

extern const U16 *mmi_umms_app_ui_callback_get_list_of_icon(U16 MMI_UMMS_SCR_ID);

/* MMI_BOOL mmi_umms_app_ui_callback_template_get_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask); */

extern S8 *mmi_umms_app_ui_callback_get_progress_screen_data(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_template_get_data(
            S32 item_index,
            gui_iconlist_menu_item *menuData,
            S32 dnumber_of_item);
/*********VIEWER CATEGORY CALLBACKS***************/
extern void mmi_umms_app_ui_callback_exit_viewer_application(void);
extern void mmi_umms_app_ui_callback_handle_stop(void);
extern void mmi_umms_app_ui_callback_viewer_stop_callback(void);
extern void mmi_umms_app_ui_callback_viewer_mid_slides_cb(void);

#ifdef __MMI_MSG_FTE_ENHANCE__
extern MMI_BOOL mmi_umms_app_ui_callback_viewer_fte2_common_cb(U16 touch_area);
#endif 

extern void mmi_umms_app_ui_callback_viewer_get_use_details_on_slide(srv_mms_viewer_use_details_list **list_head);
extern MMI_BOOL mmi_umms_app_ui_callback_get_filename_by_id(
                    mma_mms_slide_object_struct *media,
                    PU16 vf,
                    PU16 *file_path,
                    PS32 vf_parent_file_handle);
extern MMI_BOOL mmi_umms_app_ui_callback_load_ucs2_txt_to_buffer(
                    PU8 dest_buffer,
                    U32 dest_buffer_size,
                    mma_mms_slide_text_object_struct *media);
extern MMI_BOOL mmi_umms_app_ui_callback_check_rights_by_id(mma_mms_slide_object_struct *media);
extern MMI_BOOL mmi_umms_app_ui_callback_start_consume_rights(mma_mms_slide_object_struct *media, PU16 file_path);
extern void mmi_umms_app_ui_callback_stop_consume_rights(mma_mms_slide_object_struct *media);
extern void mmi_umms_app_ui_callback_update_rights_by_id(mma_mms_slide_object_struct *media, MMI_BOOL rights_expired);
extern MMI_BOOL mmi_umms_app_ui_callback_allow_audio_playing(void);
extern void mmi_umms_app_ui_callback_best_page_duration(
                U64 playing_time,
                kal_uint32 *slide_duration,
                kal_uint32 *obj_start_time,
                kal_uint32 *obj_end_time);
extern void mmi_umms_app_ui_callback_set_send_key(srv_mms_viewer_use_details_list *current_hilited);

extern MMI_BOOL mmi_umms_app_ui_callback_app_common_action(wgui_mv_action_type);


#ifdef __MMI_MMS_ITERATOR_VIEWER__
extern void mmi_umms_app_ui_callback_display_next_mms(void);
extern void mmi_umms_app_ui_callback_display_previous_mms(void);
extern void mmi_umms_app_ui_callback_get_index_data(U16 *curr_msg_num, U16 *total_msg_num);
extern U8 *mmi_umms_app_ui_callback_mms_get_error_print_data(U16 scr_id);

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_ui_callback_tb_rr_dr(S32 index);
extern void mmi_umms_app_ui_callback_tb_notification(S32 index);
#endif /* __MMI_FTE_SUPPORT__ */ 
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
extern void mmi_umms_app_ui_callback_display_next_mms_through_swipe(mmi_frm_gesture_event_enum gesture_event);
extern void mmi_umms_app_ui_callback_display_previous_mms_through_swipe(mmi_frm_gesture_event_enum gesture_event);
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */ 
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 

/*********VIEWER CATEGORY CALLBACKS***************/

/********************************amit added *******************************/
extern U8 *mmi_umms_app_ui_callback_message_status_get_data(U16 scr_id);
extern U8 *mmi_umms_app_ui_callback_memory_status_get_data(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_get_save_objects_attachment_count(void);
extern S32 mmi_umms_app_ui_callback_get_attachment_data(S32 item_index, gui_iconlist_menu_item *menuData, S32 num);
extern U16 *mmi_umms_app_ui_callback_save_objects_item_list(U16 menu_id, U16 *arr);
extern void mmi_umms_app_ui_callback_save_objects_items_hide_unhide(void);
extern void mmi_umms_app_ui_callback_save_objects_items_check_for_empty(void);
extern const U16 *mmi_umms_app_ui_callback_get_save_objects_list_of_icons(U16 scr_id);
extern U8 *mmi_umms_app_ui_callback_mms_property_screen_get_data(U16 scr_id);
extern U8 *mmi_umms_app_ui_callback_mms_property_screen_get_data_slim(U16 scr_id);
extern S32 mmi_umms_app_ui_callback_notification_option_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_notification_option_screen_list(U16 menu_id, U16 *str_item_list);
extern S32 mmi_umms_app_ui_callback_show_report_options_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_show_report_options_screen_list(U16 menu_id, U16 *str_item_list);
extern U16 mmi_umms_app_ui_callback_sh_new_message_popup_get_data(U16 scr_id);
extern U16 mmi_umms_app_ui_callback_sh_new_message_popup_get_image_id(U16 scr_id);
extern U16 *mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_list(U16 menu_id, U16 *str_item_list);
extern S32 mmi_umms_app_ui_callback_show_use_details_addresses_options_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_show_sim_options_resend_screen_list(U16 menu_id, U16 *str_item_list);
extern S32 mmi_umms_app_ui_callback_show_sim_options_resend_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_use_recipients_screen_list(U16 menu_id, U16 *arr);
extern S32 mmi_umms_app_ui_callback_use_recipients_screen_item(U16 menu_id);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern S32 mmi_umms_app_ui_callback_sort_by_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_sort_by_screen_list(U16 menu_id, U16 *arr);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 

extern S32 mmi_umms_app_ui_callback_use_details_menu_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_use_details_menu_screen_list(U16 menu_id, U16 *str_item_list);

#ifdef __MMI_MMS_PREVIEW_GOTO__
extern S32 mmi_umms_app_ui_callback_mms_preview_menu_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_mms_preview_menu_screen_list(U16 menu_id, U16 *str_item_list);
#endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
extern S32 mmi_umms_app_ui_callback_java_options_menu_screen_item(U16 menu_id);
extern U16 *mmi_umms_app_ui_callback_java_options_menu_screen_list(U16 menu_id, U16 *str_item_list);

extern S32 mmi_umms_app_ui_callback_get_address_list(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item);
extern U16 *mmi_umms_app_ui_callback_sim_selection_profile_menu_screen_list(U16 menu_id, U16 *str_item_list);
extern S32 mmi_umms_app_ui_callback_sim_selection_profile_menu_screen_item(U16 menu_id);

#ifdef __MMI_MMS_PREVIEW_GOTO__
extern S32 mmi_umms_app_ui_callback_get_slide_list(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item);
#endif 
extern U16 *mmi_umms_app_sim_selection_profile_menu_screen_list(U16 menu_id, U16 *str_item_list);
extern S32 mmi_umms_app_sim_selection_profile_menu_screen_item(U16 menu_id);

extern MMI_UMMS_ERROR mmi_umms_app_ui_plug_in_show_new_message_popup_post_func(U16 scr_id);

extern S32 mmi_umms_app_ui_callback_multimedia_template_item(U16 scr_id);
extern U16 *mmi_umms_app_ui_callback_template_menu_item_list(U16 menu_id, U16 *str_item_list);
extern WCHAR *mmi_umms_app_ui_callback_template_menu_list_of_descriptions(U16 scr_id);

/********************************Niraj Added**********************************/

extern S32 mmi_umms_app_ui_callback_get_no_of_items_general(U16 scrn_id);
extern U16 *mmi_umms_app_ui_callback_message_menu_item_list(U16 scr_id, U16 *str_item_list);
extern const U16 *mmi_umms_app_ui_callback_message_menu_list_of_icon(U16 scr_id);
extern U16 *mmi_umms_app_ui_callback_mms_message_settings_menu_item_list(U16 scr_id, U16 *str_item_list);
extern const U16 *mmi_umms_app_ui_callback_mms_message_settings_menu_list_of_icon(U16 scr_id);

extern void mmi_umms_app_ui_callback_compose_settings_item_list(mmi_id);
extern void mmi_umms_app_ui_callback_compose_settings_list_of_icon(U16 *image_list);

extern void mmi_umms_app_ui_callback_retrieval_settings_item_list(U16);
extern void mmi_umms_app_ui_callback_retrieval_settings_list_of_icon(U16 *image_list);

extern void mmi_umms_app_ui_callback_retrieval_filters_settings_item_list(U16);
extern void mmi_umms_app_ui_callback_retrieval_filters_settings_list_of_icon(U16 *image_list);

extern void mmi_umms_app_ui_callback_sending_settings_list_of_icon(U16 *image_list);
extern void mmi_umms_app_ui_callback_sending_settings_item_list(U16);

extern void mmi_umms_app_ui_callback_compose_signature_settings_item_list(U16);
extern void mmi_umms_app_ui_callback_compose_signature_settings_list_of_icon(U16 *image_list);
extern void mmi_umms_app_ui_callback_compose_signature_settings_set_flag(void);

extern S32 mmi_umms_app_ui_callback_signature_options_get_no_of_items(U16 scrn_id);
extern U16 *mmi_umms_app_ui_callback_signature_options_item_list(U16 scr_id, U16 *str_item_list);
extern const U16 *mmi_umms_app_ui_callback_signature_options_list_of_icon(U16 scr_id);

extern void mmi_umms_app_ui_callback_sim_options_decide(mmi_event_struct *evt);
extern U16 *mmi_umms_app_ui_callback_sim_options_menu_item_list(U16 menu_id, U16 *str_item_list);
extern const U16 *mmi_umms_app_ui_callback_sim_options_menu_list_of_icon(U16 scr_id);

extern MMI_BOOL mmi_umms_app_ui_callback_check_compose_settings(void);
extern void mmi_umms_app_ui_callback_compose_settings_signature_selection_lsk_handler(void);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern U16 *mmi_umms_app_ui_callback_sort_by_menu_item_list(U16 menu_id, U16 *str_item_list);
extern S32 mmi_umms_app_ui_callback_sort_by_num(U16 scr_id);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
extern void mmi_umms_compose_select_from_file_manager(void);
extern void mmi_umms_pre_entry_compose_reference_delete(void);
extern S32 mmi_umms_app_ui_callback_userdef_template_count(void);
extern void mmi_umms_app_ui_callback_reset_settings_common_list(void);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern S32 mmi_umms_app_ui_callback_prefer_storage_options_decide(U16 scr_id);
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
extern void mmi_umms_app_ui_callback_msg_filter_options_decide(cui_menu_event_struct *menu_evt);
#endif
extern U16 *mmi_umms_app_ui_callback_prefer_storage_item_list(U16 menu_id, U16 *str_item_list);
extern void mmi_umms_app_ui_callback_move_copy_options_hide_all(void);
extern void mmi_umms_app_ui_callback_move_copy_options_hide_unhide(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
extern void mmi_umms_app_ui_use_details_list_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_umms_app_ui_template_list_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */ 
extern S32 mmi_umms_app_ui_callback_sim_selection_profile_menu_item(U16 scr_id);
extern U16 *mmi_umms_app_ui_callback_sim_selection_profile_menu_item_list(U16 menu_id, U16 *str_item_list);
extern mmi_ret mmi_umms_proc_func(mmi_event_struct *evt);
extern mmi_ret mmi_umms_template_grp_proc_func(mmi_event_struct *evt);
extern mmi_ret mmi_umms_popupcallback_ext_proc_fun(mmi_event_struct *evt);
extern mmi_ret mmi_umms_inline_proc_func(mmi_event_struct *evt);
extern void mmi_umms_app_reset_buffer_for_signature(void);

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
extern U8 *mmi_umms_app_ui_callback_dr_rr_status_get_data(U16 scr_id);
#endif 
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
extern S32 mmi_umms_app_ui_callback_report_box_options_decide(U16 scr_id);
#endif 
extern void mmi_umms_app_ui_callback_common_settings_decide(void);

#if(MMI_MAX_SIM_NUM >= 2)
extern S32 mmi_umms_app_ui_callback_sim_decide(U16 scr_id);
#endif 
#if(MMI_MAX_SIM_NUM >= 3)
extern mmi_ret mmi_umms_app_ui_callback_sim_sel_post_action_decide(mmi_event_struct *evt);
#endif 
#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
extern wgui_mv_image_decode_status_enum mmi_umms_app_ui_callback_decode_image(U16 *src_path, U32 width_orig, U32 height_orig, U32 width_final, U32 height_final, U16 slide_id);
#endif
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_UI_CALLBACK_H */ 

