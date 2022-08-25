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
 * BrowserAppScrDB.h
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERAPPSCRDB_H
#define MMI_BROWSERAPPSCRDB_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserAppTypes.h"
#include "ProfilesSrvGprot.h"
#include "MMIDataType.h"
#include "wgui_touch_screen.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "wgui_categories.h"
#include "gui_typedef.h"

/* Resource Database struct */
typedef struct
{
    U16 scrn_id;                            /* Screen id */
    U16 title_str_id;                       /* String id of title */
    U16 title_icon_id;                      /* Icon id of title */
    U16 lsk_str_id;                         /* String id of LSK */
    U16 lsk_icon_id;                        /* Icon id of LSK */
    U16 rsk_str_id;                         /* String id of RSK */
    U16 rsk_icon_id;                        /* Icon id of RSK */
} mmi_brw_app_resourceDB_struct;

/* Screen handler Database struct */
typedef struct
{
    mmi_brw_app_resourceDB_struct *rcDB;
    void *screen;
    mmi_brw_app_result_enum (*create_func) (U16);
    mmi_brw_app_result_enum (*pre_func) (U16);
    mmi_brw_app_result_enum (*post_func) (U16);
    mmi_brw_app_result_enum (*draw_func) (U16);
    void (*exit_screen) (void);
    void (*entry_screen) (void);
    void (*lsk_func) (void);
    void (*rsk_func) (void);
    void (*hilite_handler) (S32);
    mmi_ret (*delete_screen_handler) (mmi_event_struct *evt);
    U16 scrn_id;
} mmi_brw_app_screenDB_struct;





/* Structures for the varios types of screens required for 
   some specific information required by the screen  */


/* Dynamic list screen structure for category 184 screen */
typedef struct
{
	U16 scrn_id;
	U16 number_of_items;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    void (*tap_callback_func) (mmi_tap_type_enum tap_type, S32 index);
    show_toolbar_func_ptr show_toolbar_func;
#endif /* #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */
    S32 (*dynamic_list_handler)(S32, gui_iconlist_menu_item *, S32);
}mmi_brw_app_scrhdlr_dynamic_screen_struct;


/* Small screen structure for category 165 66 screen */
typedef struct
{
	U16 scrn_id;
    U16 title_str_id;
	U16 display_msg_str_id;
	U16 msg_img_id;
    srv_prof_tone_enum tone_id;
}mmi_brw_app_scrhdlr_small_screen_struct;


/* Small screen structure for 165 sec confirm screen */
typedef struct
{
	U16 scrn_id;
	UI_string_type display_msg;
	U16 msg_img_id;
    srv_prof_tone_enum tone_id;
    U16 lsk_str_id;
    U16 lsk_img_id;
    U16 rsk_str_id;
    U16 rsk_img_id;
}mmi_brw_app_confirm_screen_struct;


/* Splash screen structure for category 132 screen */
typedef struct
{
	U16 scrn_id;
	U16 img_id;
    MMI_BOOL (*enable_full_screen_check_func) (void);
}mmi_brw_app_scrhdlr_img_screen_struct;

/* Rendered page screen structure for category 431 screen */
typedef struct
{
	U16 scrn_id;
    U16 title_icon;
    U8* title_str_buffer;
    U16 security_icon;
    MMI_BOOL screen_size_status;
    S32 percentage;
    S8* display_str;
    cat431_pen_handler pen_handler_func;
#ifdef __MMI_FTE_SUPPORT__
    show_toolbar_func_ptr show_toolbar_func;
#endif

}mmi_brw_app_scrhdlr_rendered_page_screen_struct;

/* Auto URL screen structure for category 103 screen */
typedef struct
{
	U16 scrn_id;
	S16 hilighted_item;
    S32 (*get_number_of_matched_items_func)(void);
    GetItemFuncPtr get_matched_item_func;
    GetHintFuncPtr get_hint_func;
    S32 (*search_func) (UI_buffer_type);
    U8* buffer;
    U16 buffer_length;
}mmi_brw_app_scrhdlr_enter_url_screen_struct;

/* Upload progress screen structure for category 412 screen */
typedef struct
{
	U16 scrn_id;
    U16 rsk_str_id;
    U16 rsk_icon_id;
    U16 progress_img_id;
    U16 message_str_id;
    U8 percentage_value;
    S32 message_count;
    UI_string_type display_str[1];
}mmi_brw_app_scrhdlr_upload_screen_struct;


/* View screen structure for category 74 screen */
typedef struct
{
	U16 scrn_id;
    PU8 buffer;
    S32 buffer_length;
}mmi_brw_app_scrhdlr_view_screen_struct;

extern void mmi_brw_app_set_scrhdlr_db_index(U16 scr_id);
extern mmi_brw_app_screenDB_struct* mmi_brw_app_get_curr_screenDB (void);
extern mmi_brw_app_screenDB_struct* mmi_brw_app_scrhdlr_get_screenDB (U16 scr_id);


extern void mmi_brw_app_set_res_db_index(U16 scr_id);
extern mmi_brw_app_resourceDB_struct* mmi_brw_app_get_current_resDB (void);



#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERAPPSCRDB_H */
