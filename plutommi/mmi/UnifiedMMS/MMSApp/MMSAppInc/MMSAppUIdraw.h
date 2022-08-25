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
 * MMSAppUIdraw.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_UI_DRAW_H
#define MMS_APP_UI_DRAW_H

#define MMI_UMMS_MAX_POPUP_LENGTH 50
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
// #include "App_usedetails.h"
#include "MMIDataType.h"
#include "MMSAppResourceDB.h"
#include "gui_typedef.h"
#include "wgui_categories_MMS_viewer.h"
#include "InlineCuiGprot.h"
#include "MMSAppUICommon.h"
#include "kal_general_types.h"

typedef struct
{
    U16 scrn_id;
    U16 hilighted_item;
    mmi_umms_app_screenDB_struct *scrDB;
    U32 number_of_item;
    GetAsyncItemFuncPtr get_item_cb;        /* Callback function to get the item data */
    GetAsyncHintFuncPtr get_item_hint_cb;   /* Callback function to get the item hint data */
    AsyncUpdateCallback hilite_notify_cb;   /* Callback function to get the current highlight */
    void (*hndl_list_not_ready) (S32);
      U16(*change_title) (void);
    U16 highlighted_menu;
} mmi_umms_app_ui_draw_dynamic_screen_struct;

typedef struct
{
    U16 scrn_id;
    U16 hilighted_item;
    mmi_umms_app_screenDB_struct *scrDB;
      S32(*number_of_items) (U16);
    U16 *(*list_of_items) (U16, U16 *);
    const U16 *(*list_of_icons) (U16);
    U8 **(*list_of_descriptions) (U16, U8 **);
} mmi_umms_app_ui_draw_static_screen_struct;

typedef struct
{
    U16 scrn_id;
    mmi_umms_app_screenDB_struct *scrDB;
    U8 *(*get_message_cb) (U16);    /* Callback function to get the item data */
} mmi_umms_app_ui_draw_progress_screen_struct;

typedef struct
{
    U16 lsk_str_id;     /* String id of LSK */
    U16 lsk_icon_id;    /* Icon id of LSK */
    U16 rsk_str_id;     /* String id of RSK */
    U16 rsk_icon_id;
    U16 message[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 mmi_event;
    MMI_BOOL need_history;
    MMI_BOOL need_csk;
    void (*lsk_handler) (void);
    void (*rsk_handler) (void);
    void (*exit_screen) (void);
    void (*del_scr_handler) (void);
} mmi_umms_app_ui_draw_display_confrim_screen_struct;

typedef struct
{
    U16 string_id[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 event_type;
} mmi_umms_app_ui_draw_display_popup_screen_struct;

typedef struct
{
    U16 string_id[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 image_id;
    U16 tone_id;
} mmi_umms_app_ui_draw_infinite_popup_screen_struct;

typedef struct
{
    U16 string[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 event_type;
    void (*success_callback) (void);
    void (*failure_callback) (void);
} mmi_umms_app_ui_draw_display_callback_popup_screen_struct;

typedef struct
{
    U16 title_str_id;
    U16 display_id;
    /* U16 lsk_icon;
       U16 lsk_str_id;
       U16 rsk_icon;
       U16 rsk_str_id;kal ko */
} mmi_umms_app_ui_draw_progress_scrn_struct;

#ifdef __MMI_FTE_SUPPORT__
#define MMI_UMMS_APP_MAX_ICON_FTE 3
typedef struct
{
    S32 item_count;                                         /* the count of your items, max is 4 in FTE */
    PU8 content_icon[MMI_UMMS_APP_MAX_ICON_FTE];            /* icon of item */
    PU8 disabled_content_icon[MMI_UMMS_APP_MAX_ICON_FTE];   /* icon of item in disabled state */
    PU8 string[MMI_UMMS_APP_MAX_ICON_FTE];                  /* text string of item */
    GUIIconbarItemCallback callback;
} mmi_umms_app_ui_fte_struct;
#endif /* __MMI_FTE_SUPPORT__ */ 

typedef struct
{
    U16 scrn_id;
    U16 lsk_str_id;
    U16 mode;
    BOOL full_scrn;
    BOOL is_review;
    mmi_umms_app_screenDB_struct *scrDB;
    srv_mms_viewer_use_details_list *current_hilited;
    srv_mms_viewer_use_details_list *list_head;
    void (*lsk_func) (void);
    void (*set_send_key_cb) (srv_mms_viewer_use_details_list *current_hilited);
    void (*call_number) (void);
    void (*launch_url) (void);
    void (*launch_email) (void);
#ifdef __MMI_FTE_SUPPORT__
    mmi_umms_app_ui_fte_struct fte_data;
#endif 
} mmi_umms_app_ui_draw_viewer_screen_struct;

typedef struct
{
    U16 scrn_id;
    U16 str_id;
    U16 image_id;                                   /* get the image to display in this popupbased upon evemt type failure or new_msg */
    MMI_BOOL data1;
    MMI_BOOL data2;
    mmi_umms_app_screenDB_struct *scrDB;
} mmi_umms_app_ui_draw_infinite_time_screen_struct; /* showcategory65screen */

#ifdef __MMI_MMS_ITERATOR_VIEWER__
#define MMI_MMS_MAX_ITER_VIEWER_MIDDLE_STR_LEN 14
#endif 

typedef struct
{
    U16 scrn_id;
    U16 csk_icon;
    mmi_umms_app_screenDB_struct *scrDB;
    U8 *(*get_string_buffer) (U16);             /* full sub menu data or string buffer */
    void (*csk_func) (void);
    U16 title_str_id;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    void (*rnk_func) (void);
    void (*lnk_func) (void);
    MMI_BOOL lsk_delete;
    WCHAR middle_str[MMI_MMS_MAX_ITER_VIEWER_MIDDLE_STR_LEN];
#ifdef __MMI_FTE_SUPPORT__
    mmi_umms_app_ui_fte_struct fte_data;
#endif 
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
} mmi_umms_app_ui_draw_property_screen_struct;  /* showcategory78screen */

/* Inline CUI */
typedef struct
{
    U16 scrn_id;
    U16 hilighted_item;
    void (*set_item_list) (U16);
    void (*image_list_icons) (U16 *);
    cui_inline_struct inline_initial_data;
} mmi_umms_app_ui_draw_inline_cui_selection_screen_struct;  /* showcategory57screen */

typedef struct
{
    U16 scrn_id;
    mmi_umms_app_screenDB_struct *scrDB;
    U32 hilighted_item;
      S32(*number_of_items) (U16);
    U16 *(*list_of_items) (U16, U16 *);     /* list of items */
} mmi_umms_radio_selection_screen_struct;   /* showcategory36screen */

typedef struct
{
    U16 lsk_str_id;     /* String id of LSK */
    U16 lsk_icon_id;    /* Icon id of LSK */
    U16 rsk_str_id;     /* String id of RSK */
    U16 rsk_icon_id;
    U16 message;
    U16 mmi_event;
    MMI_BOOL need_history;
    void (*lsk_handler) (void);
    void (*rsk_handler) (void);
} mmi_umms_app_ui_draw_display_progress_screen_struct;

extern MMI_UMMS_ERROR mmi_umms_app_ui_property_status_screen_draw_func(U16 scr_id);
extern void mmi_umms_app_ui_draw_dummy_screen(void);
extern void mmi_umms_app_ui_draw_set_current_opt_menu_id(mmi_menu_id id);
extern mmi_menu_id mmi_umms_app_ui_draw_get_current_opt_menu_id(void);

#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_UI_DRAW_H */ 

