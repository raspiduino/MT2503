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
 * WAPPushScreenHdlr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the various Screen handler API's declaration and structure defination of Push message.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PUSH_MSG_SH_H__
#define __PUSH_MSG_SH_H__
//#include "MMI_include.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "gui_data_types.h"
    #include "gui_typedef.h"
    #include "MMI_features.h"
    #include "mmi_frm_gestures_gprot.h"
    #include "wgui_touch_screen.h"

#ifdef __WAP_PUSH_SUPPORT__

//#ifdef __MMI_FTE_SUPPORT__
//#include "wgui_categories_util.h"
//#endif /*__MMI_FTE_SUPPORT__*/
//#include "MenuCuiGprot.h"
//#include "mmi_rp_app_mmi_wap_push_def.h"
    

extern void mmi_wap_push_set_scrhdlr_DB_id (U16 screen_id);
extern void mmi_wap_push_set_rc_DB_id (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_if_init (U16 screen_id);
extern U16 mmi_wap_push_map_internal_event (U16 event_id);
extern void mmi_wap_push_event_based_display_popup (U16 event_id, U16 str_id);
extern void mmi_wap_push_draw_dummy_screen (MMI_BOOL gdi_lock);

extern MMI_BOOL mmi_wap_push_scrhdlr_create_static_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_pre_static_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_static_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_static_screen_option (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_static_screen_app_sub_menu (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_post_static_screen (U16 screen_id);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
extern MMI_BOOL mmi_wap_push_scrhdlr_post_nuknwn_addr_opt (U16 screen_id);
#endif
extern void mmi_wap_push_setting_entry_main_menu (void);
extern void mmi_wap_push_scrhdlr_exit_static_screen (void);
extern void mmi_wap_push_entry_service_message (void);
extern void mmi_wap_push_scrhdlr_lsk_static_screen (void);
extern void mmi_wap_push_scrhdlr_rsk_static_screen (void);
extern void mmi_wap_push_scrhdlr_hilite_static_screen (S32 index);
extern mmi_ret mmi_wap_push_scrhdlr_delete_static_screen (mmi_event_struct *evt);
#if 0
/* under construction !*/
/* under construction !*/
#endif /*0*/
extern MMI_BOOL mmi_wap_push_scrhdlr_pre_selection_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_selection_screen (U16 screen_id);
extern void mmi_wap_push_scrhdlr_lsk_selection_screen (void);
extern U16 mmi_wap_push_get_sel_scr_hilited_index (U16 screen_id);
extern U8** mmi_wap_push_get_sel_scr_list_of_item (U16 menu_id);
extern U32 mmi_wap_push_get_sel_scr_num_of_item (U16 menu_id);

extern MMI_BOOL mmi_wap_push_scrhdlr_draw_inline_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ph_num (U16 screen_id);
#if 0
/* under construction !*/
#endif /*0*/
extern MMI_BOOL mmi_wap_push_scrhdlr_pre_inline_screen_add_new_ip (U16 screen_id);
extern void mmi_wap_push_scrhdlr_lsk_inline_screen (void);
extern void mmi_wap_push_scrhdlr_entry_add_new_ph_num (void);
extern void mmi_wap_push_scrhdlr_rsk_inline_screen (void);
extern void mmi_wap_push_scrhdlr_exit_inline_screen (void);

extern MMI_BOOL mmi_wap_push_scrhdlr_pre_dynamic_screen_white_list (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_pre_dynamic_screen_black_list (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_dynamic_screen (U16 screen_id);
extern void mmi_wap_push_scrhdlr_hilite_dynamic_screen (S32 index);

extern MMI_BOOL mmi_wap_push_scrhdlr_pre_async_dynamic_screen_inbox (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_async_dynamic_screen (U16 screen_id);
extern void mmi_wap_push_scrhdlr_hilite_async_dynamic_screen (S32 index);
extern MMI_BOOL mmi_wap_push_scrhdlr_post_async_dynamic_screen_inbox (U16 screen_id);

extern MMI_BOOL mmi_wap_push_scrhdlr_pre_selected_message_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_message_screen (U16 screen_id);
extern void mmi_wap_push_scrhdlr_lsk_selected_message_screen (void);
extern void mmi_wap_push_scrhdlr_rsk_selected_message_screen (void);
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
extern MMI_BOOL mmi_wap_push_scrhdlr_post_sia_dlg_screen (U16 screen_id);

extern void mmi_wap_push_scrhdlr_lsk_sia_dlg_screen (void);
extern void mmi_wap_push_scrhdlr_rsk_sia_dlg_screen (void);
#endif
extern MMI_BOOL mmi_wap_push_scrhdlr_post_progress_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_progress_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_pre_progress_screen (U16 screen_id);

extern MMI_BOOL mmi_wap_push_scrhdlr_pre_notification_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_notification_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_post_notification_screen (U16 screen_id);

extern MMI_BOOL mmi_wap_push_scrhdlr_pre_small_screen (U16 screen_id);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_small_screen (U16 screen_id);




extern void mmi_wap_push_entry_um_list_opt_menu (void);
extern void mmi_wap_push_entry_unknwn_addr_opt_menu (void);
extern void mmi_wap_push_entry_connect_sim_opt_menu (void);
extern void mmi_wap_push_entry_msg_opt_menu (void);
extern void mmi_wap_push_entry_send_by_opt_menu (void);
extern void mmi_wap_push_setting_entry_main_menu (void);
extern void mmi_wap_push_setting_entry_wl_opt_menu (void);
extern void mmi_wap_push_setting_entry_wl_add_new_menu (void);
extern void mmi_wap_push_scrhdlr_entry_um_sort_by (void);

extern void mmi_wap_push_scrhdlr_entry_enable_push (void);
extern void mmi_wap_push_scrhdlr_entry_enable_sl_set (void);
extern void mmi_wap_push_scrhdlr_entry_enable_black_list (void);
extern void mmi_wap_push_scrhdlr_entry_enable_white_list (void);

extern void mmi_wap_push_scrhdlr_entry_add_new_ph_num (void);
extern void mmi_wap_push_scrhdlr_entry_add_new_ip (void);
#if 0
/* under construction !*/
#endif /* 0 */
extern void mmi_wap_push_setting_entry_black_list (void);
extern void mmi_wap_push_setting_entry_white_list (void);

extern void mmi_wap_push_setting_entry_service_inbox (void);
extern void mmi_wap_push_scrhdlr_lsk_service_inbox (void);

extern void mmi_wap_push_scrhdlr_entry_message_display_group (MMI_ID caller_grp_id);
extern void mmi_wap_push_scrhdlr_entry_message_display (void);
#if !defined(__MMI_WAP_PUSH_SIA_SLIM__) || defined(__MMI_WAP_PUSH_WHITE_LIST__) 
extern void mmi_wap_push_scrhdlr_entry_sia_dlg_display (void);
#endif
extern void mmi_wap_push_scrhdlr_entry_generic_processing (void);
extern void mmi_wap_push_scrhdlr_entry_generic_processing_ex (void);
//extern void mmi_wap_push_scrhdlr_draw_message_popup (void);
extern MMI_BOOL mmi_wap_push_scrhdlr_draw_message_popup (mmi_scenario_id scen_id, void *arg);

extern void mmi_wap_push_scrhdlr_entry_inbox_processing (void);
extern void mmi_wap_push_scrhdlr_entry_async_processing (void);

extern void mmi_wap_push_scrhdlr_entry_new_msg_ind_screen (void);
extern void mmi_wap_push_scrhdlr_entry_msg_deleted_screen (void);

#ifdef __MMI_UM_ITERATOR_VIEWER__
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 
extern void mmi_wap_push_display_next_viewer_through_swipe(mmi_frm_gesture_event_enum gesture_event);
extern void mmi_wap_push_display_prev_viewer_through_swipe(mmi_frm_gesture_event_enum gesture_event);
#endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  */
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

/******************* New functions *****************************/
extern mmi_ret mmi_wap_push_scrhdlr_lsk_setting_menu (mmi_event_struct *evt);
extern mmi_ret mmi_wap_push_scrhdlr_lsk_wl_options_menu (mmi_event_struct *evt);
extern mmi_ret mmi_wap_push_scrhdlr_lsk_add_new_options_menu (mmi_event_struct *evt);
extern mmi_ret mmi_wap_push_scrhdlr_lsk_msg_option_menu (mmi_event_struct *evt);
#if 0
/* under construction !*/
#endif /* 0*/
extern mmi_ret mmi_wap_push_scrhdlr_lsk_unknwn_addr_opt_menu (mmi_event_struct *evt);
extern mmi_ret mmi_wap_push_scrhdlr_lsk_service_msg_main_menu (mmi_event_struct *evt);
extern void mmi_wap_push_dummy_screen (mmi_id  group_id);

typedef void (*hide_hdlr_func_ptr) (void*);
typedef S32 (*highlighter_func_ptr) (void);
typedef void (*Default_func_ptr) (void);
typedef mmi_ret (*leaf_node_func) (mmi_event_struct *evt);

typedef struct
{
    U16 scrn_id;
	U16 hilighted_item;
    S32 (*number_of_items)(U16);
    U16* (*list_of_items)(U16, U16*);
    U16* (*list_of_icons)(U16, U16*);
    highlighter_func_ptr highlighter_func;
    U8** (*list_of_descriptions)(U16,U8**);
    hide_hdlr_func_ptr hide_handler;
    leaf_node_func  leaf_node_hdlr;
} mmi_wap_push_scrhdlr_static_screen_struct;

typedef struct
{
    U16 scrn_id;
	U16 hilighted_item;
    U32 (*number_of_items)(U16);
    U8** (*list_of_items)(U16);
    U16 (*higlighted_index)(U16);
    hide_hdlr_func_ptr hide_handler;
} mmi_wap_push_scrhdlr_selection_screen_struct;


typedef struct
{
	U16 scrn_id;
	U16 hilighted_item;
	U16 number_of_items;
	void (*image_list_icons)(U16*);
    void (*inline_items)(void);
}mmi_wap_push_scrhdlr_inline_screen_struct;


typedef struct
{
	U16 scrn_id;
	U16 hilighted_item;
	U16 number_of_items;
#if defined(__MMI_FTE_SUPPORT__) &&  defined(__MMI_TOUCH_SCREEN__)
    void (*tap_callback_func) (mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */
    pBOOL (*dynamic_list_handler)(S32, UI_string_type, PU8*, U8);
}mmi_wap_push_scrhdlr_dynamic_screen_struct;


typedef struct
{
	U16 scrn_id;
	U16 hilighted_item;
	U16 number_of_items;
    U16 selected_item;
    U16 default_icon;
    S32 (*async_dynamic_list_handler)(S32, gui_iconlist_menu_item*, S32);
}mmi_wap_push_scrhdlr_async_dynamic_screen_struct;

#ifdef __MMI_FTE_SUPPORT__
#define MMI_PUSH_MAX_FTE_TB_ICON 2
typedef struct
{
	S32 item_count;
	PU8 content_icon [MMI_PUSH_MAX_FTE_TB_ICON];
	PU8 disabled_content_icon[MMI_PUSH_MAX_FTE_TB_ICON];
	PU8 string[MMI_PUSH_MAX_FTE_TB_ICON];
	GUIIconbarItemCallback callback;
}mmi_push_scrhdlr_viewer_fte_tb_struct;
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_UM_ITERATOR_VIEWER__
typedef struct
{
    U8                 *left_button_string;
    U8                 *left_button_down_img;
    U8                 *left_button_up_img;
    Default_func_ptr   left_button_func;
    U8                 *right_button_string;
    U8                 *right_button_down_img;
    U8                 *right_button_up_img;
    Default_func_ptr   right_button_func;
    U8                 middle_string [40];
}mmi_push_scrhdlr_viewer_slide_buttons_struct;
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

typedef struct
{
	U16 scrn_id;
	U16 title_string_id;
	U16 lsk_string_id;
	U16 lsk_image_id;
	U16 rsk_string_id;
	U16 rsk_image_id;
#ifdef __MMI_FTE_SUPPORT__
    mmi_push_scrhdlr_viewer_fte_tb_struct fte_data;
#endif /* __MMI_FTE_SUPPORT__ */
    Default_func_ptr csk_func;
    Default_func_ptr lnk_func;
    Default_func_ptr rnk_func;
    Default_func_ptr data_init_func;
#ifdef __MMI_UM_ITERATOR_VIEWER__
    mmi_push_scrhdlr_viewer_slide_buttons_struct slide_buttons_data;
#endif
}mmi_wap_push_scrhdlr_message_screen_struct;


typedef struct
{
	U16 scrn_id;
	U16 msg_str_id;
	U16 msg_img_id;
}mmi_wap_push_scrhdlr_progress_screen_struct;

typedef struct
{
	U16 scrn_id;
	U16 msg_str_id;
	U16 msg_img_id;
}mmi_wap_push_scrhdlr_notification_screen_struct;


typedef struct
{
	U16 scrn_id;
	U16 msg_str_id;
	U16 msg_img_id;
}mmi_wap_push_scrhdlr_small_screen_struct;


typedef struct
{
    U16 scrn_id;                            /* Screen id */
    U16 menu_item_id;                       /* menu id */
    U16 title_str_id;                       /* String id of title */
    U16 title_icon_id;                      /* Icon id of title */
    U16 lsk_str_id;                         /* String id of LSK */
    U16 lsk_icon_id;                        /* Icon id of LSK */
    U16 rsk_str_id;                         /* String id of RSK */
    U16 rsk_icon_id;                        /* Icon id of RSK */
	U16 waiting_message;
} mmi_wap_push_resourceDB_struct;

typedef struct
{
	U16 scrn_id;
	mmi_wap_push_resourceDB_struct* rcDB;
    void *screen;
	U16 parent_menu_id;	 
	MMI_BOOL (*create_func)(U16);
	MMI_BOOL (*pre_func)(U16);
	MMI_BOOL (*draw_func)(U16); 
	MMI_BOOL (*post_func)(U16); 
	void (*EntryFunction)(void);
	void (*exit_screen)(void); 
	void (*lsk_func)(void);
	void (*rsk_func)(void);
	void (*hilite_handler)(S32);
	mmi_ret (*delete_screen_handler)(mmi_event_struct *);
} mmi_wap_push_screenDB_struct;

#endif /* __WAP_PUSH_SUPPORT__*/
#endif /* __PUSH_MSG_SH_H__ */
