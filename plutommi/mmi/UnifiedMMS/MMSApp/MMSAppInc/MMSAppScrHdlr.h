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
 * MMSAppScrHdlr.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_SH_HDLR_H
#define MMS_APP_SH_HDLR_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
// #include "MmsSrvGprot.h"
#include "MMIDataType.h"
#include "MMSAppUICommon.h"
#include "kal_general_types.h"

#define MMI_UMMS_APP_SH_MAX_CNTX 10

typedef struct
{
    U16 scr_id;
    void *sh_data;
} mmi_umms_app_sh_context;

extern void mmi_umms_app_sh_dummy_history_func(void *arg);
extern void mmi_umms_app_sh_template_menu_exit_func(void);
extern void mmi_umms_app_sh_template_menu_list_handler(U16);
extern void mmi_umms_app_sh_template_menu_rsk_handler(void);
extern MMI_UMMS_ERROR mmi_umms_app_sh_prop_mms_options_handling(U16 hilite_menu, U16 scr_id);

extern void mmi_umms_app_sh_dynamic_list_hilite_handler(S32 index);
extern void *mmi_umms_app_sh_get_scr_context(U16 scrId);
extern void mmi_umms_app_sh_set_screen_context(U16 scrId, void *data);
extern void mmi_umms_app_sh_delete_screen_context(U16 scrId);
extern mmi_ret mmi_umms_app_sh_dynamic_list_delete_scr_handler(mmi_event_struct *data);

/***********************Niraj Added**********************************/

/******************common settings***************/
extern void mmi_umms_app_sh_message_settings_menu_exit_func(void);

/******************mms common settings******************/
extern void mmi_umms_app_sh_mms_message_settings_menu_exit_func(void);

/******compose settings***********************/
extern void mmi_umms_app_sh_compose_settings_rsk_handler(void);
extern void mmi_umms_app_sh_compose_settings_hilite_handler(S32 index);
extern void mmi_umms_app_sh_compose_settings_exit_func(void);

/**retrieval settings*******/
extern void mmi_umms_app_sh_retrieval_settings_exit_func(void);
extern void mmi_umms_app_sh_retrieval_settings_rsk_handler(void);
extern void mmi_umms_app_sh_retrieval_settings_hilite_handler(S32 index);

/***********compose signature settings****************/
extern void mmi_umms_app_sh_compose_signature_settings_hilite_handler(S32 index);
extern void mmi_umms_app_sh_compose_signature_settings_lsk_handler(void);
extern void mmi_umms_app_sh_compose_signature_settings_rsk_handler(void);
extern void mmi_umms_app_sh_compose_signature_settings_exit_func(void);

/*****************retrieval filter settings*********/
extern void mmi_umms_app_sh_retrieval_filters_settings_exit_func(void);

/****************sending settings***********/
extern void mmi_umms_app_sh_sending_settings_exit_func(void);

/************************signature options*******************/

extern void mmi_umms_app_sh_signature_options_exit_func(void);

/**********************************Amit Added*************************/
extern void mmi_umms_app_sh_memory_status_exit_func(void);
extern void mmi_umms_app_sh_property_status_rsk_handler(void);
extern mmi_ret mmi_umms_app_sh_property_status_delete_scr_handler(mmi_event_struct *data);
extern void mmi_umms_app_sh_save_objects_attachment_list_exit_func(void);
extern void mmi_umms_app_sh_save_objects_attachment_list_rsk_handler(void);
extern void mmi_umms_app_sh_save_objects_attachment_list_hilite_handler(S32 index);
extern void mmi_umms_app_sh_save_objects_list_exit_func(void);
extern void mmi_umms_app_sh_mms_properties_exit_func(void);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern void mmi_umms_app_sh_sort_by_exit_func(void);
extern void mmi_umms_app_sh_sort_by_rsk_handler(void);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
extern void mmi_umms_app_sh_use_details_menu_exit_func(void);
extern void mmi_umms_app_sh_mms_java_options_exit_func(void);
extern void mmi_umms_app_sh_mms_java_options_rsk_handler(void);
extern void mmi_umms_app_sh_sim_selection_profile_exit_func(void);
extern void mmi_umms_app_sh_sim_selection_profile_rsk_handler(void);
extern void mmi_umms_app_sh_notification_option_screen_exit_func(void);
extern void mmi_umms_app_sh_notification_option_screen_rsk_handler(void);
extern void mmi_umms_app_sh_show_report_options_screen_exit_func(void);
extern void mmi_umms_app_sh_show_report_options_screen_rsk_handler(void);
extern void mmi_umms_app_sh_show_sim_options_resend_screen_exit_func(void);
extern void mmi_umms_app_sh_show_use_details_addresses_options_screen_exit_func(void);
extern void mmi_umms_app_sh_message_status_screen_exit_func(void);
extern void mmi_umms_app_sh_show_new_message_popup_exit_func(void);
extern void mmi_umms_app_sh_mms_preview_menu_exit_func(void);
extern void mmi_umms_app_sh_mms_preview_menu_rsk_handler(void);

#ifdef __MMI_MMS_PREVIEW_GOTO__
extern void mmi_umms_app_sh_preview_option_lsk_hdlr(void);
#endif 
extern void mmi_umms_app_sh_recipient_screen_handler(U16 hilite_menu);

#ifdef __MMI_MMS_PREVIEW_GOTO__
extern void mmi_umms_app_sh_preview_slide_list_lsk_hdlr(void);
#endif 
extern void mmi_umms_app_sh_mms_option_delete_lsk_handler(void);
extern void mmi_umms_app_sh_mms_option_delete_rsk_handler(void);
extern void mmi_umms_app_sh_mms_option_delete_all_lsk_handler(void);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_umms_app_sh_move_to_archive_confirm_lsk_handler(void);
#endif 
extern void mmi_umms_app_sh_go_to_box_list_screen(void);
extern void mmi_umms_app_sh_delete_umms_screens(void);
extern void mmi_umms_app_sh_delete_umms_use_details_screens(void);
extern void mmi_umms_app_sh_delete_umms_save_objects_screens(void);
extern void mmi_umms_app_sh_delete_progress_screen(void);

extern void mmi_umms_app_sh_mms_message_settings_handler(U16);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern void mmi_umms_app_sh_sort_by_lsk_handler(void);
#endif 
#ifdef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
extern void mmi_umms_app_sh_cancel_dwnld_lsk_handler(void);
#endif 
extern void mmi_umms_app_sh_show_send_active_profile_screen(void);
extern void mmi_umms_app_sh_show_download_active_profile_screen(void);
extern void mmi_umms_app_sh_mms_common_settings_handler(U16);
extern void mmi_umms_app_sh_mms_message_settings_handler(U16);
extern void mmi_umms_app_sh_template_menu_exit_func(void);
extern void mmi_umms_app_sh_template_menu_rsk_handler(void);
extern void mmi_umms_app_sh_template_menu_list_handler(U16);
extern void mmi_umms_app_sh_memory_status_menu_exit_func(void);
extern void mmi_umms_app_sh_user_template_rsk_handler(void);
extern void mmi_umms_app_sh_mms_template_lsk_handler(void);
extern void mmi_umms_app_sh_user_template_exit_func(void);
extern void mmi_umms_app_sh_default_template_exit_func(void);
extern void mmi_umms_app_sh_use_number_list_lsk_handler(void);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mmi_umms_app_sh_mms_memory_status_handler(U16 hilite_menu);
#endif 
extern void mmi_umms_app_sh_show_screen_based_on_msg_status(U32 msg_id);
extern void mmi_umms_app_sh_show_other_mms_option_list_option_off(U32 msg_id);
extern void mmi_umms_app_sh_show_other_mms_option_list_option_on(U32 msg_id);
extern void mmi_umms_app_sh_delete_screen_reset_globals(void);
extern void mmi_umms_app_sh_show_notification_or_outbox_option(U32 msg_id);
extern void mmi_umms_app_sh_enter_java_mms_screen(void);

#ifdef __MMI_OP12_TOOLBAR__
extern void mmi_umms_app_sh_display_msg_for_tb(U32 msg_id);
extern void mmi_umms_app_sh_get_msg_info_from_bgsr_callback_for_tb(U32 msg_id, srv_mms_bgsr_msg_info_struct *msg_info);
#endif /* __MMI_OP12_TOOLBAR__ */ 

extern void mmi_umms_app_sh_use_details_list_hilite_handler(S32 index);
extern void mmi_umms_app_sh_userdef_template_list_hilite_handler(S32 index);
extern void mmi_umms_app_sh_default_template_list_hilite_handler(S32 index);
extern void mmi_umms_compose_settings_signature_selection_lsk_handler(void);
extern void mmi_umms_app_sh_display_working_space_popup(kal_uint32 min_fs_space_required);

/* extern U8 mmi_umms_sh_get_compose_signature_hilighter(void); */
extern void mmi_umms_app_sh_delete_option_screen(U8 folder_id);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mmi_umms_app_sh_mms_pref_storage_exit_func(void);
extern MMI_UMMS_ERROR mmi_umms_app_sh_mms_pref_storage_handler(U16);
extern void mmi_umms_app_sh_radio_button_hilite_handler(S32 index);
extern void mmi_umms_app_sh_radio_button_list_rsk_handler(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

/* amit added for sim profile selection menuhandlng */
extern void mmi_umms_app_sh_settings_sim_selection_exit_func(void);

extern void mmi_umms_app_sh_network_changed_from_immd_to_deffered_callback(void);

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_sh_viewer_toolbar_cb(S32 index);
#endif 
/* Screen Group and CUI */
extern mmi_ret mmi_umms_proc_func(mmi_event_struct *evt);
extern mmi_ret mmi_umms_popupcallback_ext_proc_fun(mmi_event_struct *evt);

#ifdef __MMI_MMS_ITERATOR_VIEWER__
void mmi_umms_app_sh_abnormal_view_lsk_handler(void);
#endif 

extern void mmi_umms_app_sh_warning_object_signature_confirm_rsk_handler(void);

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern void mmi_umms_app_sh_mms_option_save_lsk_handler(void);
extern void mmi_umms_app_sh_mms_option_save_rsk_handler(void);
extern void mmi_umms_app_sh_mms_option_save_exit_handler(void);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#if defined(__OP01__) && defined(__MMI_TOUCH_SCREEN__)
void mmi_umms_app_sh_use_detail_delete_options_hdlr(void) ;
#endif
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_SH_HDLR_H */ 

