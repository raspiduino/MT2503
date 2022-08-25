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
 * BrowserAppUICallback.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPUICALLBACK_H
#define MMI_BROWSERAPPUICALLBACK_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_touch_screen.h"

typedef enum
{
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    BRW_BKM_TB_ITEM_ADD_BOOKMARK,
#endif
    BRW_BKM_TB_ITEM_INPUT_ADDRESS,
    BRW_BKM_TB_ITEM_DELETE_BOOKMARK,
    BRW_BKM_TB_ITEM_TOTAL
} brw_bookmark_toolbar_enum;

typedef enum
{
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    BRW_RPAGE_TB_ITEM_ADD_BOOKMARK,
#endif
    BRW_RPAGE_TB_ITEM_INPUT_ADDRESS,
    BRW_RPAGE_TB_ITEM_DELETE_PAGE,
    BRW_RPAGE_TB_ITEM_TOTAL
} brw_recent_page_toolbar_enum;

extern U32 mmi_brw_app_ui_callback_get_wap_scr_num_of_items (U16 menu_id);
extern U16 mmi_brw_app_ui_callback_get_wap_scr_list_of_icons(U16 menu_id, U16 *image_ids);
extern void mmi_brw_app_ui_callback_wap_scr_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_bookmark_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_browser_path_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_send_address_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_recent_pages_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_page_object_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_ren_page_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_select_mode_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_advanced_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_settings_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_browser_options_hide_handler(void *gui_buffer);
extern void mmi_brw_app_ui_callback_security_settings_hide_handler(void *gui_buffer);
extern S32 mmi_brw_app_ui_callback_get_number_of_addr_list_matched_items(void);
extern S32 mmi_brw_app_ui_callback_get_number_of_search_list_matched_items(void);
extern S32 mmi_brw_app_ui_callback_get_matched_items_count(void);
extern MMI_BOOL mmi_brw_ui_callback_get_full_screen_status(void);
extern pBOOL mmi_brw_app_ui_callback_get_address_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_matched_address_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_matched_search_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_matched_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_brw_app_ui_callback_find_entry(U8 *input_str);
extern S32 mmi_brw_app_ui_callback_find_address_list_entry(U8 *input_str);

/*****************************************BOOKMARK*********************************************/
extern pBOOL mmi_brw_app_ui_callback_get_bookmarks_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_insert_bookmarks_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_folder_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_brw_app_ui_callback_bookmarks_list_csk_hdlr(void);
extern void mmi_brw_app_ui_callback_bookmarks_browse_path_list_csk_hdlr(void);

/*****************************************BOOKMARK*********************************************/

/***************************************RECENT PAGES START*********************************/
extern pBOOL mmi_brw_app_ui_callback_get_recent_page_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_recent_page_host_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

/***************************************RECENT PAGES END*********************************/


/***************************************STORED PAGES START*********************************/
extern pBOOL mmi_brw_app_ui_callback_get_stored_page_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
/***************************************STORED PAGES END*********************************/


/***************************************SETTINGS START*********************************/
extern pBOOL mmi_brw_app_ui_callback_get_trusted_certificates_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern void mmi_brw_app_ui_callback_trusted_certificate_csk_hdlr(void);
/***************************************SETTINGS END*********************************/

extern void mmi_brw_app_ui_callback_shortcuts_list_csk_hdlr(void);
extern MMI_BOOL mmi_brw_app_ui_callback_ren_page_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
extern pBOOL mmi_brw_app_ui_callback_page_actions_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_page_object_types_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_page_objects_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern pBOOL mmi_brw_app_ui_callback_get_shortcuts_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_brw_app_ui_callback_get_dynamic_list_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
/***************************************FTE START************************************/
extern void mmi_brw_app_ui_callback_show_address_list_toolbar(void);
extern void mmi_brw_app_ui_callback_address_list_toolbar(S32 index);
extern void mmi_brw_app_ui_callback_address_list_tap(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_address_list_tap(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_enter_url_tap(mmi_tap_type_enum tap_type, S32 index);

extern void mmi_brw_app_ui_callback_show_bookmarks_toolbar(void);
extern void mmi_brw_app_ui_callback_bookmarks_toolbar(S32 index);
extern void mmi_brw_app_ui_callback_bookmarks_list_tap(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_browse_path_tap(mmi_tap_type_enum tap_type, S32 index);

extern void mmi_brw_app_ui_callback_show_rendered_page_toolbar(void);
extern void mmi_brw_app_ui_callback_render_page_toolbar(S32 index);

extern void mmi_brw_app_ui_callback_show_recent_page_toolbar(void);
extern void mmi_brw_app_ui_callback_recent_page_toolbar(S32 index);
extern void mmi_brw_app_ui_callback_recent_page_list_tap(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_recent_page_host_list_tap(mmi_tap_type_enum tap_type, S32 index);

extern void mmi_brw_app_ui_callback_page_obj_list_tap(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_trusted_certificate_tap(mmi_tap_type_enum tap_type, S32 index);

extern void mmi_brw_app_ui_callback_show_stored_page_toolbar(void);
extern void mmi_brw_app_ui_callback_stored_page_toolbar(S32 index);
extern void mmi_brw_app_ui_callback_stored_page_list_tap(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_shortcuts_list_tap(mmi_tap_type_enum tap_type, S32 index);

extern void mmi_brw_app_ui_callback_save_bookmark_inline_tap_callback(mmi_tap_type_enum tap_type, S32 index);
extern void mmi_brw_app_ui_callback_add_bookmark_inline_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPUICALLBACK_H */
