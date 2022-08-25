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
*  Copyright Statement: *  -------------------- *  This software is protected by 
Copyright and the information contained *  herein is confidential. The software 
may not be copied and the information *  contained herein may not be used or 
disclosed except with the written *  permission of MediaTek Inc. (C) 2002 * 
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * UcScrUIDb.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local enum, constant and prototypes for Unified Composer
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_UNIFIED_COMPOSER_SCREEN_UI_PROT_H
#define _MMI_UNIFIED_COMPOSER_SCREEN_UI_PROT_H
//suggested add
    #include "MMI_features.h"
    #include "MMIDataType.h"
    //#include "kal_general_types.h"
    #include "gui_data_types.h"
    #include "gui_typedef.h"
    #include "wgui_inline_edit.h"
    #include "mmi_frm_events_gprot.h"
    #include "UcAppGProt.h"
    #include "wgui_icon_bar.h"

#define MAX_UC_SCREENS_AT_ONE_FLOW 10

typedef enum
{
    MMI_UC_FALSE,
    MMI_UC_TRUE,
    MMI_UC_ASYNC_WAIT
} mmi_uc_frm_result_enum;

typedef enum
{
    MMI_UC_FLOW_INSTANCE_ID_DUMMY_START = 0,
    MMI_UC_FLOW_INSTANCE_ID_PROCESSING,                 /* 1 */
    MMI_UC_FLOW_INSTANCE_ID_EDITOR,                     /* 2 */
    MMI_UC_FLOW_INSTANCE_ID_OPT,                        /* 3 */
#ifndef __MMI_SLIM_MMS_2__
    MMI_UC_FLOW_INSTANCE_ID_MSG_DETAIL,                 /* 4 */
#endif
    MMI_UC_FLOW_INSTANCE_ID_MSG_PREVIEW,                /* 5 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_INSERT,                 /* 6 */
    MMI_UC_FLOW_INSTANCE_ID_ADD_PICTURE_OPTIONS,        /* 7 */
    MMI_UC_FLOW_INSTANCE_ID_ADD_SOUND_OPTIONS,          /* 8 */
#ifdef __MMI_MMS_VIDEO_FEATURE__
    MMI_UC_FLOW_INSTANCE_ID_ADD_VIDEO_OPTIONS,          /* 9 */
#endif
    MMI_UC_FLOW_INSTANCE_ID_ADVANCED_OPTIONS,           /* 10 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_REMOVE,                 /* 11 */
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    MMI_UC_FLOW_INSTANCE_ID_OPT_REPLACE,                /* 12 */
#endif
    MMI_UC_FLOW_INSTANCE_ID_PICTURE_OPTIONS,            /* 13 */
    MMI_UC_FLOW_INSTANCE_ID_SOUND_OPTIONS,              /* 14 */
    MMI_UC_FLOW_INSTANCE_ID_VIDEO_OPTIONS,              /* 15 */
    MMI_UC_FLOW_INSTANCE_ID_ATTACHMENT_OPTIONS,         /* 16 */
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
    MMI_UC_FLOW_INSTANCE_ID_TEXT_OPTIONS,               /* 17 */
#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_RECIPIENT,          /* 18 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_RECIPIENT_OPTIONS,  /* 19 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_ENTER_RECIPIENT,        /* 20 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_EDIT_RECIPIENT,         /* 21 */
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#if defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) && defined(__MMI_TOUCH_SCREEN__)
    MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACH_LIST,
#else
    MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACHMENT_REMOVE,      /* 22 */
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACHMENT_REPLACE,     /* 23 */
#endif
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT,              /* 24 */
#ifdef __MMI_MMS_2__
    MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_SLIDE_TIMING, /* 25 */
#endif
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
    MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_TEXT_TIMING,  /* 26 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_IMAGE_TIMING, /* 27 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_AUDIO_TIMING, /* 28 */
    MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_VIDEO_TIMING, /* 29 */
#endif
    MMI_UC_FLOW_INSTANCE_ID_OPT_SEND_OPT,               /* 30 */
#ifndef __MMI_FTE_SUPPORT__
    MMI_UC_FLOW_INSTANCE_ID_EXIT_OPT,                   /* 31 */
#endif
#ifndef __MMI_SLIM_MMS_2__
    MMI_UC_FLOW_INSTANCE_ID_OPT_INSERT_NEW_MM_OBJECT,   /* 32 */
#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    MMI_UC_FLOW_INSTANCE_ID_SUBJECT_EDITOR,             /* 33 */
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    MMI_UC_FLOW_INSTANCE_ID_CONFIRM,                    /* 34 */
    MMI_UC_FLOW_INSTANCE_ID_SIG_CONFIRM,                /* 35 */
    MMI_UC_FLOW_INSTANCE_ID_INPUT_METHOD_AND_DONE,      /* 36 */
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    MMI_UC_FLOW_INSTANCE_ID_ENTER_RECIPIENT_OPTIONS,    /* 37 */
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#if !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__)
    MMI_UC_FLOW_INSTANCE_ID_SENDING_FORGROUND_SMS,
#endif 
#if !defined(__MMI_MMS_BGSR_SUPPORT__)
    MMI_UC_FLOW_INSTANCE_ID_SENDING_FORGROUND_MMS,
#endif 
 #if (MMI_MAX_SIM_NUM >=2)
    MMI_UC_FLOW_INSTANCE_ID_SIM_OPT,
#endif 
#ifdef __MMI_MMS_POSTCARD__
    MMI_UC_FLOW_INSTANCE_ID_WRITE_MSG_SELECTION,
    MMI_UC_FLOW_INSTANCE_ID_POSTCARD_RECIPIENT_OPTION,
    MMI_UC_FLOW_INSTANCE_ID_POSTCARD_ADDRESS,
#endif /* __MMI_MMS_POSTCARD__ */ 
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_OBJECT,          /* 38 */
#endif
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    MMI_UC_FLOW_INSTANCE_ID_OPT_HEADER_FIELDS,
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    MMI_UC_FLOW_INSTANCE_ID_TOTAL
} mmi_uc_frm_flow_instance_identifier_enum;

/* typedef struct
   {
   U16 scrn_id;
   mmi_uc_frm_result_enum (*create_func)(U16);
   mmi_uc_frm_result_enum (*pre_func)(U16);
   mmi_uc_frm_result_enum (*post_func)(U16);
   mmi_uc_frm_result_enum (*show_func)(U16);
   MMI_BOOL (*get_async_func)(U16);
   MMI_BOOL (*data_ready_func)(U16);
                                 }mmi_uc_frm_cntrlr_struct; *//* No need currentely */

typedef struct
{
    U16 title_str_id;   /* String id of title */
    U16 title_icon_id;  /* Icon id of title */
    U16 lsk_str_id;     /* String id of LSK */
    U16 lsk_icon_id;    /* Icon id of LSK */
    U16 rsk_str_id;     /* String id of RSK */
    U16 rsk_icon_id;
    U16 waiting_message;
} mmi_uc_frm_resourceDB_struct;

typedef struct
{
    U16 scrn_id;
    U16 instance_hash_id;
    U16 parent_menu_id;
      MMI_BOOL(*create_func) (U16);
      MMI_BOOL(*pre_func) (U16);
      MMI_BOOL(*post_func) (U16);
      MMI_BOOL(*draw_func) (U16);
    void (*exit_screen) (void);
    void (*EntryFunction) (void);
    void (*lsk_func) (void);
    void (*rsk_func) (void);
    void (*hilite_handler) (S32);
    mmi_ret (*delete_screen_handler) (mmi_event_struct *evt);
	
} mmi_uc_frm_screenDB_struct;

/*----------------------------------------Scr specific---------------------------------------------*/

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)

#define MMI_UC_APP_MAX_ICON_FTE WGUI_ICONBAR_MAX_COUNT

typedef struct
{
	S32 item_count; // the count of your items, max is 4 in FTE
    PU8 content_icon[MMI_UC_APP_MAX_ICON_FTE]; // icon of item
    PU8 disabled_content_icon[MMI_UC_APP_MAX_ICON_FTE]; // icon of item in disabled state
    PU8 string[MMI_UC_APP_MAX_ICON_FTE]; // text string of item
    GUIIconbarItemCallback callback;
}mmi_uc_frm_toolbar_struct;
#endif /*__MMI_FTE_SUPPORT__*/

#ifndef __MMI_SLIM_MMS_2__
typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
    U8 *(*get_string_buffer) (U16, S32 *);  /* full sub menu data or string buffer */
    mmi_id uc_gid;
	U16 scrn_id;
} mmi_uc_frm_full_text_screen_struct;       /* showcategory74screen */
#endif

typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
      S32(*number_of_items) (U16);
    U16 *(*list_of_icons) (U16);
    mmi_id uc_gid;
	U16 scrn_id;
    U8 **(*list_of_items) (U16);                /* full sub menu data or string buffer */
} mmi_uc_frm_single_buffer_list_screen_struct;  /* showcategory84screen */

typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
    void (*set_data_for_menu_list) (U16);
      U16(*set_title) (U16);
    S32 number_of_items;
    U16 hilighted_item;
    mmi_id uc_gid;
    U16 *(*list_of_items) (U16, U16 *);
    U16 *(*list_of_icons) (U16);
    U8 **(*list_of_descriptions) (U16, U8 **);
	U16 scrn_id;
} mmi_uc_frm_static_screen_struct;
typedef struct
{
    U16 scrn_id;
    mmi_id uc_gid;
    const mmi_uc_frm_screenDB_struct *scrDB;
      S32(*get_progress_percent) (U16); /* progress percent */
    U8 *(*get_string_buffer) (U16);     /* progress string buffer */
    S8 *(*get_message_buffer) (U16);    /* temp data or string buffer */
    void (*free_message_buffer) (S8 *); /* free temp data or string buffer */
    void (*end_key_func) (void);
} mmi_uc_frm_progress_meter_screen_struct;
typedef struct
{
    U16 scrn_id;
    mmi_id uc_gid;
    const mmi_uc_frm_screenDB_struct *scrDB;
      S32(*editor_msg_type) (void);     /* msg_type */
    S32 input_type;                     /* progress string buffer */
    void (*get_subject_strings) (UI_string_type *, UI_string_type *);   /* temp data or string buffer */
    void (*free_message_buffer) (S8 *); /* free temp data or string buffer */
    void (*csk_func) (void);
    void (*end_key_func) (void);
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    U16(*get_title_id) (U16);
#endif
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    mmi_uc_frm_toolbar_struct editor_tool_bar;
#endif
} mmi_uc_frm_content_editor_screen_struct;
typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
      U16(*set_data_for_recipient_list) (U16);
      U16(*number_of_item) (void);
      mmi_id uc_gid;
	  U16 scrn_id;
      MMI_BOOL(*fixed_list_register_get_flags) (S32, U32 *, U32 *);
  #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
      void (*tap_func) (mmi_tap_type_enum , S32 );
  #endif /* __MMI_FTE_SUPPORT__*/
      U16(*get_hilighted_item) (U8 *, U16); /* for list icon in lefthandside */
	#ifdef __UC_ASYNC_DYNAMIC_LIST__
	GetAsyncItemFuncPtr get_item_cb;
	#else
    GetItemFuncPtr get_item_cb;             /* Callback function to get the item data */
	#endif
    GetHintFuncPtr get_item_hint_cb;        /* Callback function to get the item hint data */
} mmi_uc_frm_dynamic_screen_struct;         /* showcategory184screen */
typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
      S32(*get_input_type) (void);
      mmi_id uc_gid;
	  U16 scrn_id;
      S16(*get_editor_filters) (void);                      /* editor filters */
    S32 *(*get_editor_filter_for_input_mode) (void);        /* mmi_imm_input_mode_enum *required_input_mode_set */
    U16 *(*get_editor_buffer) (U16);                        /* editor buffer */
      S32(*get_max_buffer_length) (void);                   /* max buffer length */
    void (*csk_func) (void);
      MMI_BOOL(*set_first_entry_editor_environment) (void); /* set buffer */
} mmi_uc_frm_normal_editor_screen_struct;                   /* showcategory5screen_ext */
typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
    U32 hilighted_item;
    U16 num_of_items;
    mmi_id uc_gid;
    void (*lsk_done_func) (void);
    void (*rsk_done_func) (void);
    void (*rsk_back_func) (void);
    void (*image_list_icons) (U16 *);
    wgui_inline_item *(*inline_items) (void);
	U16 scrn_id;
} mmi_uc_frm_inline_selection_screen_struct;    /* showcategory57screen */
typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
    S32 number_of_items;
    U16 hilighted_item;
    mmi_id uc_gid;
    void (*set_data_for_editor_option) (U16);
    U16 *(*list_of_items) (U16, U16 *);
    U16 *(*list_of_icons) (U16);
    U8 **(*list_of_descriptions) (U16, U8 **);
    void (*f_close) (void);
	U16 scrn_id;
} mmi_uc_frm_editor_option_screen_struct;
typedef struct
{
    
    const mmi_uc_frm_screenDB_struct *scrDB;
	U16 scrn_id;
    mmi_id uc_gid;
    void (*is_back_process_handle) (MMI_BOOL);
} mmi_uc_frm_is_back_empty_body_screen_struct;
typedef struct
{
    U16 scrn_id;
    mmi_id uc_gid;
    const mmi_uc_frm_screenDB_struct *scrDB;
    U16 animation_image_id;
    U16 body_str_id;
    U8 *(*get_message_cb) (U16);
} mmi_uc_frm_progress_screen_struct;    /* showcategory66screen */

typedef struct
{
  
    const mmi_uc_frm_screenDB_struct *scrDB;
    U16 body_str_id;
    mmi_id uc_gid;
    U16 animation_image_id;
	  U16 scrn_id;
    void (*end_key_func) (void);
    void (*rsk_func) (void);
} mmi_uc_frm_progress_screen_for_send_cancellation_struct;  /* showcategory66screen */

typedef struct
{
    U16 scrn_id;
    mmi_id uc_gid;
    const mmi_uc_frm_screenDB_struct *scrDB;
    S16 body_str_id;
	mmi_event_notify_enum event_id;
	U8 confirm_tone_id;
	U8 *(*get_message_cb) (S16);
    U16(*get_image_id_cb) (mmi_event_notify_enum);
    uc_confirm_func_ptr confirm_lsk_func;   /* for warning mode confirm popup, when press LSK */
    uc_confirm_func_ptr confirm_rsk_func;   /* for warning mode confirm popup, when press RSK */
    
} mmi_uc_frm_confirmation_screen_struct;

typedef struct
{
    U16 instance_flow_hash_id;
    U16 scr_id;
    void *scr_data;
} mmi_uc_frm_screen_context;

extern mmi_uc_frm_screen_context g_uc_frm_screen_cntx[];

/*--------------------------------- Prototypes ----------------------------------------*/
extern void mmi_uc_frm_cntrlr_screen_render_start(U16 id);

extern mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_create_func(U16 id);
extern mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_pre_func(U16 id);
extern mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_post_func(U16 id);
extern mmi_uc_frm_result_enum mmi_uc_frm_cntrlr_show_func(U16 id);

/* extern mmi_uc_frm_cntrlr_struct* mmi_uc_frm_get_cntrlr_resource(U16 instance_hash_id); */
extern const mmi_uc_frm_screenDB_struct *mmi_uc_frm_get_screenDB(U16 instance_hash_id);
extern const mmi_uc_frm_resourceDB_struct *mmi_uc_frm_get_resourceDB(U16 instance_hash_id);

/*--------------------------------- ScrUI hldr ----------------------------------------*/
extern U8 mmi_uc_frm_sh_generic_delete_screen(void *data);
extern void *mmi_uc_frm_get_scr_context(U16 id);
extern MMI_BOOL mmi_uc_frm_sh_init_function(U16 id);
extern MMI_BOOL mmi_uc_frm_sh_create_func(U16 id);
extern void mmi_uc_frm_sh_delete_screen_context(U16 instance_hash_id);
extern void mmi_uc_frm_sh_set_screen_context(U16 instance_hash_id, void *data);
extern void *mmi_uc_frm_sh_get_scr_context(U16 instance_hash_id);

/*--------------------------------- Common general utility ----------------------------*/
extern MMI_BOOL mmi_uc_frm_ui_progress_screen_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_dynamic_list_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_static_list_cui_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_infinite_time_list_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_confirm_popup_history_list_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_full_text_screen_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_progress_meter_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_inline_selection_list_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_single_buffer_list_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_slide_time_editor_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_recipient_editor_draw_func(U16 instance_hash_id);
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
extern MMI_BOOL mmi_uc_frm_ui_subject_editor_draw_func(U16 instance_hash_id);
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
extern MMI_BOOL mmi_uc_frm_ui_editor_cat215ext_screen_draw(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_editor_cat215_screen_draw(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_editor_cat5ext_screen_draw(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_editor_cat5_screen_draw(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_content_editor_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_editor_option_list_draw_func(U16 id);
extern MMI_BOOL mmi_uc_frm_ui_is_back_empty_body_draw_func(U16 id);
extern MMI_BOOL mmi_uc_frm_ui_confirmation_screen_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_progress_screen_for_send_cancellation_draw_func(U16 instance_hash_id);
extern MMI_BOOL mmi_uc_frm_ui_dummy_screen_draw_func(U16 instance_hash_id);


/*FTE*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
extern void mmi_uc_write_msg_toolbar_callback(S32 index);
#endif

extern void mmi_uc_write_msg_send_key_callback(void);

#endif /* _MMI_UNIFIED_COMPOSER_SCREEN_UI_PROT_H */ 
