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
 * WAPPushSrvProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file have the declaration of internally used function.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PUSH_MSG_PROT__
#define __PUSH_MSG_PROT__
#include "MMI_features.h"
#include "WapPushUITypes.h"
#include "WapPushScreenHdlr.h"
//#include "WAPPushCntrlr.h"
//#include "WapPushDmgr.h"
//#include "WapPushResDef.h"
#include "wgui_touch_screen.h"
#include "servicemsgcuigprot.h"
#include "InlineCuiGprot.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "MMI_features.h"
    #include "WAPPushSrvTypes.h"
    #include "gui_data_types.h"
    #include "pmg_struct.h"

#ifdef __WAP_PUSH_SUPPORT__

#define MMI_BRW_PUSH_PH_NUM_SENDER_CAPTION      (CUI_INLINE_ITEM_ID_BASE + 0)
#define MMI_BRW_PUSH_PH_NUM_SMSC_CAPTION        (CUI_INLINE_ITEM_ID_BASE + 1)
#define MMI_BRW_PUSH_PH_NUM_SENDER_EDIT         (CUI_INLINE_ITEM_ID_BASE + 2)
#define MMI_BRW_PUSH_PH_NUM_SMSC_EDIT           (CUI_INLINE_ITEM_ID_BASE + 3)
#define MMI_BRW_PUSH_IP_NUM_CAPTION             (CUI_INLINE_ITEM_ID_BASE + 4)
#define MMI_BRW_PUSH_IP_NUM_EDIT                (CUI_INLINE_ITEM_ID_BASE + 5)

extern mmi_wap_push_context_struct *g_push_cntxt;

extern mmi_ret mmi_wap_push_inline_group_proc (mmi_event_struct *evt);
extern MMI_BOOL mmi_wap_push_update_inbox_selected_index (S16 factor);
extern MMI_BOOL mmi_wap_push_is_push_screen_active (void);
#ifdef __MMI_PUSH_IN_UM__
extern void mmi_wap_push_read_message_from_um_option(mmi_id parent_grp_id);
extern void mmi_wap_push_delete_message_from_um_option(void);
extern void mmi_wap_push_um_delete_all_msgs(void);
#if 0
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/* under construction !*/
#endif
#endif /* 0 */
#endif /* __MMI_PUSH_IN_UM__ */


#ifdef __MMI_WAP_PUSH_WHITE_LIST__
extern void mmi_wap_push_accept_unknwn_addr_req(void);
extern void mmi_wap_push_reject_unknwn_addr_req(void);
extern void mmi_wap_push_accept_and_add_wl_unknwn_addr_req(void);
extern void mmi_wap_push_entry_list_screen(void);
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
extern void mmi_wap_push_reject_and_add_bl_unknwn_addr_req(void);
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
extern void mmi_wap_push_connect_using_sim1(void);
extern void mmi_wap_push_connect_using_sim2(void);
extern void mmi_wap_push_add_new_ph_no_pre_entry(void);
extern void mmi_wap_push_add_new_ip_addr_pre_entry(void);
extern void mmi_wap_push_modify_pre_entry(void);
extern void mmi_wap_push_delete_all_from_msg_option(void);
extern void mmi_wap_push_delete_from_msg_option(void);
extern void mmi_wap_push_set_as_homepage_confirm(void);
extern void mmi_wap_push_add_to_validation_list_confirm(void);
extern void mmi_wap_push_add_to_bookmark_list(void);

extern void mmi_wap_push_add_new_ph_no_pre_entry(void);
extern void mmi_wap_push_add_new_ip_addr_pre_entry(void);
extern void mmi_wap_push_modify_pre_entry(void);
extern void mmi_wap_push_confirm_delete_list(void);
extern void mmi_wap_push_setting_confirm_delete_all_list_entry(void);
extern U16 mmi_wap_push_get_enable_push_string(void);
extern U16 mmi_wap_push_get_sl_setting_string(void);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
extern U16 mmi_wap_push_get_enable_wl_string(void);
#endif
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
extern U16 mmi_wap_push_get_enable_bl_string(void);
#endif


extern void mmi_push_close_active_screen(void);
extern void mmi_wap_push_delete_screen_if_present (U16 screen_id);
extern MMI_BOOL mmi_wap_push_is_screen_present(MMI_ID scrn_id);
extern srv_wap_push_result_enum mmi_wap_push_if_draw_screen(U16 scr_id);
extern void mmi_wap_push_hide_handler_send_by (void *gui_buffer);
extern void mmi_wap_push_hide_handler_message_option (void *gui_buffer);
extern void mmi_wap_push_hide_handler_unknwn_addr (void *gui_buffer);
#if 0
/* under construction !*/
#endif /* 0*/
extern void mmi_wap_push_add_new_ph_num_set_buffers (void);
extern U16 mmi_wap_push_get_number_of_white_list (void);
extern U16 mmi_wap_push_get_number_of_black_list (void);
extern void mmi_wap_push_get_msg_detail_for_tb_opr(void);
extern void mmi_wap_push_set_as_homepage (void);
#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
extern void mmi_wap_push_send_by_sms (void);
#endif
extern void mmi_wap_push_fill_add_ph_no_screen_data(void);
extern void mmi_wap_push_fill_ip_addr_inline_struct(void);

extern void mmi_wap_push_exit_new_msg_popup(void);
extern void mmi_wap_push_start_msg_sub_anm(void);
extern void mmi_wap_push_set_highlighted_index_item(S32 index);
extern void mmi_wap_push_read_selected_message (void);
extern void mmi_wap_push_clear_inbox_history (void);
extern void mmi_wap_push_full_screen_edit (void);
extern void mmi_wap_push_display_async_loading_screen (void);
extern void mmi_wap_push_go_back_unknwn_addr_screen(void);
#ifdef __MMI_WAP_PUSH_SIA_SUPPORT__
extern void mmi_wap_push_go_back_sia_req_screen(void);
extern void mmi_wap_push_sia_req_accept(void);
#endif
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
extern void mmi_wap_push_end_key_sia_dlg_screen(void);
#endif
extern void mmi_wap_push_add_bookmark_confirm (void);
extern void mmi_wap_push_confirm_modify_add_trust_list (void);

extern void mmi_wap_push_fill_inline_item_for_add_new_ph_num (void);
extern void mmi_wap_push_fill_inline_item_for_add_new_ip (void);
extern void mmi_wap_push_get_add_new_ph_num_image_icon (U16 *image_list);
extern void mmi_wap_push_get_add_new_ip_image_icon (U16 *image_list);
extern void mmi_wap_push_update_viewer_slide_button_data (void);

extern void mmi_wap_push_setting_modify_or_add_ip_addr(void);
extern void mmi_wap_push_setting_modify_or_add_list(void);

/*----------------------------------------------------------------*/
/* Functions declared in PushMsgMain.c file                       */
/*----------------------------------------------------------------*/

extern void mmi_wap_push_event_based_confirm(U16 str_id, Default_func_ptr lsk, Default_func_ptr rsk, Default_func_ptr csk);
extern void mmi_wap_push_launch_selected_message (void);

#ifdef __MMI_OP12_TOOLBAR__
extern MMI_BOOL mmi_wap_push_toolbar_option_hdlr(U16 menu_id);
extern void mmi_wap_push_set_key_hndlr_for_push_view_from_tb(U16 key_code, U16 key_type, void *user_data);
extern void mmi_wap_push_set_key_hndlr_for_multi_hndlr_for_tb(U16 key_code, U16 key_type);
#endif /* __MMI_OP12_TOOLBAR__ */

extern void mmi_wap_push_cancel_pending_events (void);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
#ifdef __MMI_UM_ITERATOR_VIEWER__
extern void mmi_wap_push_hanndle_lnk_on_viewer (void);
extern void mmi_wap_push_hanndle_rnk_on_viewer (void);
extern void mmi_wap_push_um_draw_viewer_screen (void *user_data);
extern MMI_BOOL mmi_wap_push_is_push_scr_is_current_active_screen (void);
extern MMI_BOOL mmi_wap_push_launch_next_viewer (void);
extern MMI_BOOL mmi_wap_push_launch_prev_viewer (void);
extern mmi_ret mmi_wap_push_update_indexing_data_from_um(mmi_event_struct *param);
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

/*----------------------------------------------------------------*/
/* Functions declared in PushMsgUI.c file                         */
/*----------------------------------------------------------------*/
extern void mmi_brw_push_pre_entry_inbox_validation (void);
#if 0
/* under construction !*/
#endif 
extern void mmi_wap_push_pre_entry_add_bookmark (S8 *title, S8 *url);



/*----------------------------------------------------------------*/
/* Functions declared in PushMsgSettings.c file                   */
/*----------------------------------------------------------------*/
extern void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void ReturnThreeDigitString(PU8 StringVal, U8 DigitVal);
extern void mmi_brw_settings_restore_default_push_callback(void);
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
extern void mmi_wap_push_ota_add_trustlist_result_callback(srv_wap_push_add_list_error_enum result);
#endif 

extern void mmi_wap_push_scrhdlr_entry_add_new_ph_num(void);
extern void mmi_push_pre_entry_push_setting_ex(void);
extern MMI_ID mmi_push_pre_entry_push_setting(void);
extern pBOOL mmi_wap_push_get_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_wap_push_set_crnt_hilited_index(S32 index);
extern void mmi_wap_push_go_back_two_screen(void);
extern U16 mmi_wap_push_get_hilited_index (U16 screen_id);
extern void mmi_wap_push_save_selection_menu_option (U16 screen_id, U16 option);
extern void mmi_wap_push_get_add_new_ph_num_image_icon (U16 *image_list);
extern void mmi_wap_push_fill_inline_item_for_add_new_ph_num (void);
#if (MMI_MAX_SIM_NUM == 2)
extern void mmi_wap_push_change_active_sim_and_load_url (void);
#endif /* MMI_MAX_SIM_NUM */

#ifdef __MMI_FTE_SUPPORT__
extern void mmi_push_uiplugin_init_viewer_fte_data(mmi_push_scrhdlr_viewer_fte_tb_struct *fte_data, U16 scr_id);
#endif
#if defined(__MMI_FTE_SUPPORT__) &&  defined(__MMI_TOUCH_SCREEN__)
extern void mmi_push_handle_tap_on_validation_list_screen (mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_UM_ITERATOR_VIEWER__
extern void mmi_push_uiplugin_get_slide_buttons_data(mmi_push_scrhdlr_viewer_slide_buttons_struct *slide_buttons_data, U16 scr_id);
extern void mmi_push_dmgr_get_slide_buttons_middle_string (U8 *string);
extern void mmi_wap_push_um_get_slide_buttons_data (U16 *current_index, U16 *total_num);
extern MMI_BOOL mmi_dmgr_if_lnk_available (void);
extern MMI_BOOL mmi_dmgr_if_rnk_available (void);
#endif

#ifdef __MMI_PUSH_IN_UM__
extern void mmi_wap_push_handle_msg_display_from_um (pmg_detailed_msg_struct *new_msg, S8 *url, MMI_BOOL read_from_um);
#endif /* __MMI_PUSH_IN_UM__ */

/* Q03C specific API */
extern void mmi_brw_get_active_sim_setting (kal_uint32 *active_sim, kal_uint16 *is_asked);
extern kal_uint16 mmi_brw_add_bkm_without_ui (kal_uint8 *ucs2_title, kal_uint8 *ascii_url);


extern void mmi_wap_push_confirm_before_list_edit(void);
extern U16 mmi_wap_push_get_call_marker_screen_id(void);

/* Service APIs */
#ifndef __COSMOS_MMI__
extern void mmi_wap_push_service_msg_setting_send_result (cui_service_msg_evt_enum result);
#endif
extern void mmi_wap_push_create_idle_callback_group(void);
#if 0
#ifdef __MMI_PUSH_IN_UM__
/* under construction !*/
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/* under construction !*/
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_PUSH_IN_UM__ */
#endif /* 0*/
extern void mmi_brw_push_delete_previous_instance_of_push (void);
extern void mmi_wap_push_delete_previous_push_setting_instance_if_present(void);
extern mmi_wap_push_context_struct *g_push_cntxt;
//extern srv_wap_push_msg_inbox_struct  *g_push_inbox_ctxt;
//extern srv_wap_push_setting_cntxt_struct *g_push_set_p;
#endif /* __WAP_PUSH_SUPPORT__ */
#endif /* __PUSH_MSG_PROT__ */
