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
 * EbookSrc.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines structure, enum and function for EbookSrc.c
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_EBBOKSRC_H
#define _MMI_EBBOKSRC_H

#include "app_ltlcom.h" /* Task message communiction */
#include "Conversions.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ebrsrvgprot.h"
#include "FileMgrSrvGProt.h"
#include "wgui_inputs.h"
#include "FileMgrCuiGProt.h"
#include "InlineCuiGprot.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "menucuigprot.h"
#include "FSEditorCuiGprot.h"
#include "gui_data_types.h"
#include "wgui_touch_screen.h"
#include "ebookprot.h"
#ifndef __COSMOS_MMI_PACKAGE__

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#else /* __MMI_MY_FAVORITE__ */
#define     EBR_DOWNLOADED_EBOOK_PATH           ":\\Ebook\\"
#endif /* __MMI_MY_FAVORITE__ */
#else
#define     EBR_DOWNLOADED_EBOOK_PATH           ":\\Ebooks\\"
#endif /* __MMI_MY_FAVORITE__ */

#define     EBR_LINE_NUMBER_BIT_LENGTH                    32
#define     EBR_JUMP_INLINE_ITEM_COUNT                    4
#define     EBR_DRIVE_WCS_PATH_LEN                        10 /* "D:\\" */

typedef enum
{
    MMI_EBR_POPUPCALLBACK_TAG_LIST_STORAGE = 1,
    MMI_EBR_POPUPCALLBACK_TAG_TOTAL    
} mmi_ebr_popupcallback_tag_enum;

typedef enum
{
    MMI_EBR_BOOKSHELF_ALERT_TYPE_DELETE_BOOK = MMI_EBR_POPUPCALLBACK_TAG_TOTAL,
    MMI_EBR_BOOKSHELF_ALERT_TYPE_BOOKSHELF_SETTING,
    MMI_EBR_BOOKSHELF_ALERT_TYPE_OPEN_CONVERTING_BOOK,
    MMI_EBR_BOOKSHELF_ALERT_TYPE_MEMORY_CARD_REMOVE_USE_PHONE,
    MMI_EBR_BOOKSHELF_ALERT_TYPE_TOTAL
} mmi_ebr_bookshelf_alert_type_enum;

typedef enum
{
    MMI_EBR_BOOK_ALERT_TYPE_DELETE_BOOKMARK = MMI_EBR_BOOKSHELF_ALERT_TYPE_TOTAL,
    MMI_EBR_BOOK_ALERT_TYPE_DUPLICATED_BOOKMARK,
    MMI_EBR_BOOK_ALERT_TYPE_STOP_CONVERTING_EBOOK,
    MMI_EBR_BOOK_ALERT_TYPE_TOTAL
} mmi_ebr_book_alert_type_enum;

typedef enum
{
    EBR_FONT_SIZE_SMALL,
    EBR_FONT_SIZE_MEDIUM,
    EBR_FONT_SIZE_LARGE,
    EBR_FONT_SIZE_TOTAL
} ebr_font_size_enum;

typedef enum
{
    EBR_SCROLL_BY_LINE,
    EBR_SCROLL_BY_PAGE,
    EBR_SCROLL_TYPE_TOTAL
} ebr_scroll_type_enum;

typedef enum
{
    EBR_AUTO_SCROLL_SPEED_1,
    EBR_AUTO_SCROLL_SPEED_2,
    EBR_AUTO_SCROLL_SPEED_3,
    EBR_AUTO_SCROLL_SPEED_4,
    EBR_AUTO_SCROLL_SPEED_5,
    EBR_AUTO_SCROLL_SPEED_TOTAL
} ebr_scroll_speed_enum;


typedef struct
{
    U16 ebook_settings_font_size[EBR_FONT_SIZE_TOTAL];
    U16 ebook_settings_scroll_by[EBR_SCROLL_TYPE_TOTAL];
    U16 ebook_settinsg_auto_scroll_speed[EBR_AUTO_SCROLL_SPEED_TOTAL];
}mmi_ebr_app_inline_const_string_cntx;


typedef struct
{
    S32 inlineHighligtItemFontSize;
    S32 inlineHighligtItemScrollBy;
    S32 inlineHighligtItemScrollSpeed;
} mmi_ebr_set_cntx;

typedef enum
{
    MMI_EBR_APP_STATE_IDLE = 0,
    MMI_EBR_APP_STATE_CONVERTING,
    MMI_EBR_APP_STATE_TOTAL
} mmi_ebr_app_state_enum;

typedef enum
{
    MMI_EBR_APP_ENTRY_FROM_EBOOK_READER = 0,
    MMI_EBR_APP_ENTRY_FROM_FMGR,
    MMI_EBR_APP_ENTRY_FROM_TOTAL
} mmi_ebr_entry_from_enum;

typedef struct
{
    LOCAL_PARA_HDR /*header of local paramter*/
    S32 result; /* result */
}mmi_ebr_reset_auto_scroll_result;

typedef struct
{
    LOCAL_PARA_HDR /*header of local paramter*/
    S32 fs_error; /* result */
} mmi_ebr_book_convert_error_struct;


typedef struct
{
    srv_ebr_bookshelf_setting bookshelf_setting;
} mmi_ebr_app_setting_struct;

typedef struct
{
    WCHAR book_path[SRV_EBR_MAX_PATH_LEN];
    WCHAR book_name[(SRV_EBR_MAX_FILE_LEN + 1)];
    U32 book_size;
    U16 icon_id;
} mmi_ebr_app_book_info;


typedef struct
{
    S32 bookshelf_id;
    CHAR bookshelf_path[SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH];
    MMI_BOOL is_usb_plugged_in;
    S32 book_id;
    mmi_ebr_app_book_info open_book_info;
    mmi_ebr_app_book_info highlight_book_info;
    wgui_ml_line_base_info screen_disply_info;

    srv_ebr_search_type_enum search_string_type;
    MMI_BOOL search_found_flag; /* identify whether there is string searched */
    CHAR last_search_string[(SRV_EBR_MAX_SEARCH_STRING_LENGTH + 1) * ENCODING_LENGTH];
    CHAR search_string[(SRV_EBR_MAX_SEARCH_STRING_LENGTH + 1) * ENCODING_LENGTH];
    CHAR search_string_book_name[SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH];

    U8 jump_input_line[EBR_LINE_NUMBER_BIT_LENGTH * ENCODING_LENGTH]; /* the buffer stores the line number which user inputs */
    U8 jump_total_line[EBR_LINE_NUMBER_BIT_LENGTH * ENCODING_LENGTH]; /* the buffer stores the total line number which in ucs2 encoding format */
    S32 jump_screen_total_line_num; /* identify the total line number when entering the jump screen */
    
    srv_ebr_book_bookmark_struct bookmark_info_array[SRV_EBR_MAX_BOOKMARK_NUMBER];
    S32 bookmark_id_array[SRV_EBR_MAX_BOOKMARK_NUMBER];
    S32 bookmark_number;
    CHAR input_bookmark_name[(SRV_EBR_MAX_BOOKMARK_NAME_SIZE + 1) * ENCODING_LENGTH];
    S32 current_select_bookmark;

    WCHAR *book_info_buffer;

    /* bookshelf setting */
    mmi_ebr_set_cntx select_setting_value; /* This structure records the user selected enum value */
    mmi_ebr_app_inline_const_string_cntx select_setting_caption;
        
    /* charset related */
//    mmi_chset_enum support_chset_array[MMI_CHSET_TOTAL];
//    S32 support_chset_count;

    MMI_BOOL auto_scroll; /* if book auto scroll , MMI_TRUE if auto scroll */
    MMI_BOOL full_screen; /* if book full screen , MMI_TRUE if full screen */

    mmi_ebr_app_state_enum state;
    mmi_ebr_entry_from_enum entry_from;
    MMI_BOOL send_error_msg_flag;
    MMI_BOOL search_string_from_short_key_flag; /* the flag identifies enter searching from shorcut key */

    mmi_id folder_browser_id; /* the folder browser cui id for listing book */
    mmi_id search_fseditor_id; /* the fseditor cui id of searching string */
    mmi_id add_bookmark_fseditor_id; /* the fseditor cui id of adding bookmark */
    mmi_id book_setting_id; /* the inline cui id of book's setting */
    mmi_id bookshelf_setting_id; /* the inline cui id of bookshelf's setting */
    CHAR select_bookshelf_drive; /* select bookshelf's drive */
    
    mmi_ebr_frm_bookshelf_context g_ebr_frm_bookshelf_context;
    mmi_ebr_frm_book_context g_ebr_frm_book_context;

} mmi_ebr_app_context;

extern mmi_ebr_app_context *g_ebr_app_context_array_p;

extern mmi_ret mmi_ebr_entry_bookshelf_proc(mmi_event_struct *p_event);
extern MMI_BOOL mmi_ebr_app_check_bookshelf_storage_status(void);
extern void mmi_ebr_app_bookshelf_handle_cui_folder_browser_on_quit_message(cui_folder_browser_on_quit_event_struct *p_quit_event);
#ifndef __COSMOS_MMI_PACKAGE__   
extern void mmi_ebr_app_bookshelf_handle_cui_storage_selector_result_message(cui_storage_selector_result_event_struct *p_select_result_event);
#endif
extern void mmi_ebr_app_bookshelf_handle_cui_inline_submit_message(cui_event_inline_submit_struct *p_submit_event);
extern void mmi_ebr_app_bookshelf_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_abort_event);
extern void mmi_ebr_app_bookshelf_handle_cui_inline_notify_message(cui_event_inline_notify_struct *p_notify_event);
extern void mmi_ebr_app_bookshelf_handle_cui_inline_screen_active_message(cui_event_inline_common_struct *p_event);
extern void mmi_ebr_app_bookshelf_handle_cui_group_deinit_message(mmi_event_struct *p_event);
extern void mmi_ebr_app_bookshelf_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
extern mmi_id mmi_ebr_app_open_book_launch(mmi_id parent_id);
extern void mmi_ebr_app_entry_open_book(mmi_scrn_essential_struct *p_screen_data);
extern void mmi_ebr_app_open_book_handle_cui_group_deinit_message(mmi_event_struct *p_event);
extern void mmi_ebr_app_open_book_handle_cui_menu_list_entry_message(cui_menu_event_struct *p_menu_event_list_entry);
extern void mmi_ebr_app_open_book_handle_cui_menu_item_select_message(cui_menu_event_struct *p_menu_event_item_select);
extern void mmi_ebr_app_open_book_handle_cui_menu_close_request_message(cui_menu_event_struct *p_menu_event_close_request);
extern void mmi_ebr_app_open_book_handle_cui_fseditor_submit_message(cui_fseditor_evt_struct *p_fseditor_submit);
extern void mmi_ebr_app_open_book_handle_cui_fseditor_abort_message(cui_fseditor_evt_struct *p_fseditor_abort);
extern void mmi_ebr_app_open_book_handle_cui_inline_submit_message(cui_event_inline_submit_struct *p_inline_submit);
extern void mmi_ebr_app_open_book_handle_cui_inline_abort_message(cui_event_inline_abort_struct *p_inline_abort);
extern void mmi_ebr_app_open_book_handle_alert_quit_message(mmi_alert_result_evt_struct *p_event);
extern mmi_ret mmi_ebr_entry_open_book_proc(mmi_event_struct *p_event);
extern void mmi_ebr_app_init_setting_select_value(void);
extern mmi_ret mmi_ebr_app_entry_book_info_proc(mmi_event_struct *p_event);
extern void mmi_ebr_app_entry_book_info(mmi_scrn_essential_struct *p_screen_data);
extern void mmi_ebr_app_entry_help_screen(mmi_scrn_essential_struct *p_screen_data);
extern void mmi_ebr_app_show_waiting_screen(mmi_scrn_essential_struct *p_screen_data);
extern void mmi_ebr_app_display_adding_bookmark_result_popup(mmi_id group_id, MMI_BOOL adding_bookmark_result);
extern void mmi_ebr_app_entry_book_local_setting(mmi_id group_id);
extern void mmi_ebr_app_jump_to_special_line(void);
extern void mmi_ebr_app_save_book_local_setting(mmi_id inline_id);
extern void mmi_ebr_app_save_book_local_setting_confirm_lsk_handler(void);
extern void mmi_ebr_app_save_book_local_setting_confirm_rsk_handler(void);
extern void mmi_ebr_app_entry_bookshelf_setting(void);
extern void mmi_ebr_app_save_bookshelf_setting_confirm_lsk_handler(void);
extern void mmi_ebr_app_save_bookshelf_setting_confirm_rsk_handler(void);
extern mmi_ret mmi_ebr_app_entry_bookshelf_screen_proc(mmi_event_struct *p_event);
extern MMI_BOOL mmi_ebr_app_check_drive_is_external_drive(CHAR drive, S32 *p_drive_type);
extern MMI_BOOL mmi_ebr_app_check_drive_status(CHAR drive);
extern void mmi_ebr_change_storage_from_card_to_phone_lsk(void);
extern void mmi_ebr_change_storage_from_card_to_phone_rsk(void);
extern void mmi_ebr_app_init(void);
extern mmi_ret mmi_ebr_app_bookshelf_list_storage_popup_callback(mmi_event_struct *p_event);
extern void mmi_ebr_entry_refresh_book_shelf(void);
extern void mmi_ebr_highlight_refresh_book_shelf(void);
extern void mmi_ebr_open_lsk_hdlr(void);
extern void mmi_ebr_highlight_open_ebook(void);
extern void mmi_ebr_info_lsk_hdlr(void);
extern void mmi_ebr_higlight_book_info(void);
extern void mmi_ebr_highlight_delete_ebook(void);
extern void mmi_ebr_entry_delete_book_popup(void);
extern void mmi_ebr_highlight_help(void);
extern void mmi_ebr_highlight_book_shelf_settings(void);
extern void mmi_ebr_app_search_string_next(void);
extern void mmi_ebr_entry_remove_book_mark(void);
extern void mmi_ebr_delete_bookmark(void);
extern void mmi_ebr_entry_goto_book_mark(void);
extern MMI_BOOL mmi_ebr_app_get_bookmark_list(void);
extern void mmi_ebr_highlight_selected_bookmark(S32 index);
extern void mmi_ebr_goto_selected_bookmark(void);
extern void mmi_ebr_remove_selected_bookmark(void);
extern void mmi_ebr_entry_add_book_mark(void);
extern pBOOL mmi_ebr_get_book_mark_name_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_ebr_async_get_book_mark_name_list(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items);
extern void mmi_ebr_entry_book_mark_edit_list(void);
extern void mmi_ebr_app_add_bookmark(void);
extern void mmi_ebr_entry_jump_to(void);
extern void mmi_ebr_entry_close_book(void);
extern void mmi_ebr_ebook_search_string(void);
extern void mmi_ebr_ebook_search_string_from_shorcut_key(void);
extern void mmi_ebr_exit_ebook_search_string(void);
extern void mmi_ebr_app_search_string(void);
extern void mmi_ebr_entry_book_options(void);
extern void mmi_ebr_entry_delete_ebook(void);
extern void mmi_ebr_entry_help(void);
extern void mmi_ebr_entry_search_string(void);
extern void mmi_ebr_entry_local_settings(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_ebr_set_key_TS(UI_character_type c);
#endif 
extern void mmi_ebr_mmi_ebook_exit(void *arg);
extern void mmi_ebr_entry_duplicate_book_mark_pop_up(void);
extern void mmi_ebr_entry_duplicate_book_mark_add(void);
extern void mmi_ebr_app_restore_default_book_settings_thru_frm(void);
extern void mmi_ebr_app_restore_default_book_settings(void);
extern void mmi_ebr_app_display_adding_book_mark_popup(MMI_BOOL adding_book_mark);
extern void mmi_ebr_app_search_result_invalid(void);
extern void mmi_ebr_app_display_pop_up_changed_screen_mode(MMI_BOOL screen_mode);
extern void mmi_ebr_app_display_pop_up_changed_auto_scroll(MMI_BOOL auto_scroll_mode);
extern void mmi_ebr_entry_select_drive(void);
extern void mmi_ebr_gui_reset_auto_scroll(void);
extern void mmi_ebr_reset_auto_scroll_handler(void *arg);
extern void mmi_ebr_conversion_complete_handler(void *arg);
extern void mmi_ebr_show_book_info_screen(mmi_ebr_app_book_info *p_book_info, wgui_ml_line_base_info **p_line_base_info);
extern void mmi_ebr_entry_book_shelf_normal_flow(CHAR *bookshelf_path);
extern void mmi_ebr_entry_book_shelf_lsk_handler(void);
extern void mmi_ebr_entry_book_shelf_rsk_handler(void);
extern void mmi_ebr_stop_converting_ebook(void);
extern void mmi_ebr_fs_op_error_handler(void *arg);
extern void mmi_ebr_app_display_stop_converting_confirm(void);
extern void mmi_ebr_app_stop_converting_confirm_lsk_handler(void);
extern void mmi_ebr_app_stop_converting_confirm_rsk_handler(void);
extern void mmi_ebr_cancel_refresh_book_shelf(void);
#ifdef __MMI_INDIC_ALG__
extern MMI_BOOL mmi_ebr_check_for_full_characters(S16 *pattern);
#endif
extern void mmi_ebr_search_complete_hdlr(srv_ebr_book_search_result *search_result);
extern void mmi_ebr_multiline_inputbox_navigate_callback(void);
extern U16 mmi_ebr_get_open_result_code_string_id(srv_ebr_book_open_error_enum result_code);
extern void mmi_ebr_refresh_bookshelf_complete_handler(srv_ebr_bookshelf_refresh_result_struct *operation_result);
extern void mmi_ebr_app_toggle_screen_mode(void);
extern void mmi_ebr_app_toggle_scroll_mode(void);
extern void mmi_ebr_get_default_bookmark_name(CHAR *bookmark_name);
extern void mmi_ebr_set_gui_page_info(wgui_ml_line_base_info *p_line_base_info);
extern MMI_BOOL mmi_ebr_get_ebook_screen_highlight(void);
extern void mmi_ebr_open_book_handler(srv_ebr_open_book_enum operation_enum, void *arg);
extern void mmi_ebr_app_entry_bookshelf(void);
extern void mmi_ebr_app_show_bookshelf_screen(CHAR *bookshelf_path);
extern MMI_BOOL mmi_ebr_app_get_view_data_callback(U8 **buffer, S32 *buf_len, S32 start_line, S32 end_line);
extern void *mmi_ebr_app_malloc_memory(S32 size);
extern void mmi_ebr_app_free_memory(void **arg);
extern void mmi_ebr_app_fill_support_chset_array(S32 index);
extern S32 mmi_ebr_app_create_bookshelf(CHAR *new_bookshelf_path);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#define MMI_EBR_OPEN_BOOK_FTE_TIME_DURATION 5000
#ifdef  __EBOOK_SEARCH_SUPPORT__
#define FTE_OPEN_BOOK_SCREEN_ITEM_COUNT 4
#else
#define FTE_OPEN_BOOK_SCREEN_ITEM_COUNT 3
#endif
extern void mmi_ebr_open_book_fte_timeout_handler(void);
extern void mmi_ebr_open_book_fte_tap_callback(void);
extern void mmi_ebr_open_book_fte_move_callback(void);
extern void mmi_ebr_open_book_fte_pen_down_icon_bar_callback(void);
extern void mmi_ebr_open_book_fte_pen_up_icon_bar_callback(void);
extern void mmi_ebr_open_book_fte_toolbar_command(S32 index);
extern void mmi_ebr_highlight_fte_bookmark_list(void);
extern void mmi_ebr_entry_fte_bookmark_list(void);
extern void mmi_ebr_fte_bookmark_list_tap_callback_funtion(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_ebr_entry_fte_bookmark_list_highlight_handler(S32 index);
extern void mmi_ebr_entry_fte_bookmark_list_option(void);
extern void mmi_ebr_entry_fte_bookmark_list_option_highlight_handler(S32 index);
extern void mmi_ebr_fte_goto_selected_bookmark(mmi_id bookmark_list_option_id);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
extern S32 mmi_ebr_app_get_storage_number(srv_fmgr_drivelist_type_enum b_access, U8 *p_drive_letter, S32 drive_size);
extern void mmi_fmgr_ebook_option_hdlr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
extern void mmi_ebr_app_async_open_error_handler(mmi_ebr_frm_op_result_enum error);
extern void mmi_ebr_async_open_book_loading_screen(void);

#endif /* _MMI_EBBOKSRC_H */
