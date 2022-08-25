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
 *  InlineCui.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_INLINECUI_H
#define MMI_INLINECUI_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

//#include "MMI_include.h"
#include "InlineCUIGprot.h"
#include "wgui_inline_edit.h"
#ifdef __cplusplus
}
#endif

#include "MMIDataType.h"
#include "gui_inputs.h"
#include "ImeGprot.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "gui_typedef.h"
#include "wgui_datetime.h"

#ifdef __MMI_DATETIME_USE_MULTI_LINE__
#define __INLINE_DATETIME_SLIM__
#endif
typedef enum
{
    CUI_INLINE_TEXT_MEMORY_NONE,
    CUI_INLINE_TEXT_MEMEORY_MALLOC  = 1,
    CUI_INLINE_TEXT_MEMORY_POINTER 
}cui_inline_malloc_type_enum;

#define CUI_INLINE_MAX_ITEM_COUNT   MAX_INLINE_ITEMS

#define CUI_INLINE_ITEM_TYPE_COUNT  16


#if defined(__COSMOS_MMI_PACKAGE__)
#if defined(__MMI_INLINE_SLIM__) && !defined(__MMI_EBOOK_READER__)
#define CUI_INLINE_INSTANCE_COUNT	(1)
#else
#define CUI_INLINE_INSTANCE_COUNT   2  
#endif

#elif !defined (__MMI_EMAIL__)

#define CUI_INLINE_INSTANCE_COUNT   3 

#else

#define CUI_INLINE_INSTANCE_COUNT   4  

#endif

#define ONE_INLINE_TEXT_COUNT 6
#define CUI_INLINE_TEXT_INSTANCE_COUNT  (CUI_INLINE_INSTANCE_COUNT * ONE_INLINE_TEXT_COUNT)


#define CUI_INLINE_SELECT_CONTENT_COUNT 20

#define CUI_INLINE_FULLSCREEN_EDIT_SIZE 512
#define CUI_INLINE_FULLSCREEN_BUFFER_COUNT CUI_INLINE_INSTANCE_COUNT

#define CUI_INLINE_DATE_TIME_INSTANCE_COUNT (CUI_INLINE_INSTANCE_COUNT * 5)

#define CUI_INLINE_IP4_INSTANCE_COUNT (CUI_INLINE_INSTANCE_COUNT * 3)

#define CUI_INLINE_ML_HILIST_COUNT      200

/*****************************************************************************  
*   Extern variables 
*****************************************************************************/

/*****************************************************************************  
*   Structure 
*****************************************************************************/
typedef struct
{
    U32 flags;
    PU8 text_p;
    U8 memory_mode;
    U16 default_text_id;
}cui_inline_display_only_struct;

typedef struct
{
    U32 flags;
    PU8 text_p;
}cui_inline_button_struct;

#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
typedef struct
{
    U32 style;				// 0 text ptr : 1 image id : 2 thumbnail path
    U16 default_id;
	PU8 text_p;
    PU8 thumbnail_path;
	PU8 buffer_p;
}cui_inline_caption_tn_struct;
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */

typedef struct
{
    PU8 text_p;
    U8 memory_mode;
}cui_inline_caption_struct;

typedef struct
{
    HILITE_STR *hilite_list;
    U16 count;
    U16 curr_hilite_idx;
}cui_inline_multiline_rd_highlight_list_struct;

typedef struct
{
    U32 flags;
    PU8 buffer;
    U8  height_of_item;
    U8 memory_mode;
    cui_inline_multiline_rd_highlight_list_struct highlight_list_info;
}cui_inline_multiline_read_only_struct;

#ifndef __MMI_INLINE_SLIM__
typedef struct
{
    U32 flags;
    U32 input_type;
    S16 input_extended_type;
    mmi_imm_input_mode_enum *required_input_mode_set;
    PU8 buffer;
    U32 buffer_size;
    S32 ucs2_count;
    U16 default_text_id;
    U8  *default_text_ptr;  
    U8  invalid_gui_buffer;
    U32 wgui_flag_attr;
    U8 memory_mode;
}cui_inline_text_edit_struct;
#endif

typedef struct
{
    U32 flags;
    U32 input_type;
    PU8 buffer;
    U32 buffer_size;
    PU8 cursor_p;
    U8  height_of_item; 
    S32 ucs2_count;
    U8  invalid_gui_buffer;
    U8  memory_mode;
}cui_inline_multiline_edit_struct;

typedef struct
{
    U32  flags;         /*  no use now. */
    U32  input_type;
    U16  input_ext_type;
    U16  title;
    U16  title_icon;
    PU8  buffer;
    PU8  temp_edit_buffer;
    U32  buffer_size;
    U16 default_text_id;
#ifdef __MMI_INLINE_SLIM__
    U8  *default_text_ptr; 
#endif 
    S32  ucs2_count;
    mmi_imm_input_mode_enum *required_input_mode_set;
    U8  invalid_gui_buffer;
    U8  invalid_input_buffer;
    U32 input_buffer_flag;
#ifdef __MMI_INLINE_SLIM__
    U8 is_changed;
#endif
    U8  memory_mode;
}cui_inline_fullscreen_edit_struct;

typedef struct
{
    U32  flags;
    U32  input_type;
    U16  title;
    U16  title_icon;
    PU8  buffer;
    U32  buffer_size;
    PU8  image1;
    PU8  image2;
    PU8  image3;
    S32  ucs2_count;
    U8   is_open;
    U8   invalid_gui_buffer;
    U8  memory_mode;
}cui_inline_image_text_struct;

/* For malloc date time item memory */
typedef struct
{
    U16 day_buffer[3];
    U16 month_buffer[3];
    U16 year_buffer[5];
    U16 hour_buffer[3]; 
    U16 minute_buffer[3];
    U16 second_buffer[3];
    U8 am_pm_flag;
}cui_inline_date_time_struct;

/******************************************/

typedef struct
{
    U32 flags;
    cui_inline_date_time_struct *date_data;
    U32 wgui_flag_attr;
    U8 invalid_gui_buffer;
}cui_inline_date_struct;

typedef struct
{
    U32 flags;
    cui_inline_date_time_struct *time_data;
    U32 wgui_flag_attr;
    U8 invalid_gui_buffer;
}cui_inline_time_struct;

/* typedef struct cui_inline_set_time_period_struct; */

typedef struct
{
    U32 flags;
    cui_inline_date_time_struct *time_data1;
    cui_inline_date_time_struct *time_data2;
    U32 wgui_flag_attr;
    U8  invalid_gui_buffer;
}cui_inline_time_period_struct;

/* For malloc date time item memory */
typedef struct
{
    U16 b1[4];
    U16 b2[4];
    U16 b3[4];
    U16 b4[4];
}cui_inline_ip4_data_struct;

typedef struct
{
    U32 flags;
    cui_inline_ip4_data_struct *ip4_data;
    U32 wgui_flag_attr;
    U8  invalid_gui_buffer;
}cui_inline_ip4_struct;

typedef struct
{
    U32 flags;
    S32 first_item;
	S32 n_items;
	MMI_BOOL IsSeld;
	PU8 string;
}cui_inline_radio_struct;

typedef struct
{
    U32 flags;
	MMI_BOOL IsSeld;
	PU8 string;
}cui_inline_checkbox_struct;

typedef struct
{
    U32 flags;
    U8 n_items;
    S32 highlight_index;
    S32 old_index;
    PU8 list_of_strings[CUI_INLINE_SELECT_CONTENT_COUNT];
    PU8 *string_ptr;
    U16 *string_id_list_ptr;
    U8 string_flag;             /* 0: use app global string id list; 1: app global string point list; 2: local string point list  */ 
#ifdef __MMI_INLINE_SLIM__    
    U8 is_changed;
    S32 highlight_index_backup;
#endif
}cui_inline_select_struct;

typedef struct
{
    U32 flags;
    U8 n_color;
    U8 highlight_index;
    U8 start_index;
    color * list_of_color;
}cui_inline_color_select_struct;

typedef struct
{
    U32 flags;
}cui_inline_user_defined_select_struct;

typedef struct
{
    U32 flags;
    U8 * list_of_status;
    S32 wgui_flag_attr;
    U8  invalid_gui_buffer;
}cui_inline_dow_struct;

typedef struct
{
    U32 flags;
    U32 ext_flag;
    U16 value;
    U16 max_value;
    U16 step_size;
}cui_inline_progress_bar_struct;


typedef struct
{
    U16 item_id;
    U32 flag;
    S32 key_code;
    S32 key_event;
} cui_inline_item_common_data_struct;

#define CUI_INLINE_ITEM_MAX_ALIGN_SIZE		(28)

typedef struct
{
    U32 dummuy[CUI_INLINE_ITEM_MAX_ALIGN_SIZE];
} cui_inline_dummuy_struct;

typedef union
{
    cui_inline_dummuy_struct dummuy_data;
    cui_inline_caption_struct caption_data;
    cui_inline_display_only_struct display_only_data;
	cui_inline_button_struct button_data;
    cui_inline_multiline_read_only_struct multiline_rd_only_data;
#ifndef __MMI_INLINE_SLIM__ 
    cui_inline_text_edit_struct  edit_data;
#endif
    cui_inline_multiline_edit_struct multiline_edit_data;
    cui_inline_fullscreen_edit_struct fullscreen_edit_data;
    cui_inline_image_text_struct image_text_data;
    cui_inline_date_struct date_data;
    cui_inline_time_struct time_data;
    cui_inline_time_period_struct time_period_data;
    cui_inline_ip4_struct ip4_data;
    cui_inline_select_struct select_struct;
    cui_inline_color_select_struct color_select_data;
    cui_inline_user_defined_select_struct user_defined_select_data;
    cui_inline_dow_struct dow_data;
    cui_inline_progress_bar_struct progress_bar_data;
	cui_inline_radio_struct radio_data;
	cui_inline_checkbox_struct checkbox_data;
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
	cui_inline_caption_tn_struct caption_tn_data;
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
} cui_inline_item_data_union;

typedef struct 
{
    cui_inline_item_common_data_struct common_data;
    cui_inline_item_data_union special_data;
} cui_inline_item_struct;

typedef struct cui_inline_instance_struct
{
    MMI_BOOL is_create;
    /* is_drawing flag avoid redraw process is been reentry. */
    MMI_BOOL is_drawing; 
    /* draw_count counter avoid redraw process is been executed many times.*/
    U8 draw_count;
    /* When inline main screen, can set this flag to prohibit draw item or screen. */
    U8 draw_locked;
    MMI_BOOL invalid_input_buffer;  
   // MMI_BOOL invalid_gui_buffer;    /* ?? */
    U8 inline_status;
    U8  item_count;
    U16 history_item_id;
    mmi_id gid;
    mmi_id parent_id;
    U16 title;
    U16 title_icon;
    U16 list_of_icons[CUI_INLINE_MAX_ITEM_COUNT];
    U16 highlight_item_id;
    U16 current_screen_id;
    U16 app_screen_id;
    S32 highlight_item;
    U32 parent_data;
    U32 screen_flag;
    U8 *picon;
    PU8 title_string;
    mmi_malloc_func_ptr input_buffer_malloc_func;
    mmi_mfree_func_ptr input_buffer_free_func;
    cui_inline_item_struct cui_inline_items[CUI_INLINE_MAX_ITEM_COUNT];
    cui_inline_item_softkey_struct  cui_inline_items_softkey[CUI_INLINE_MAX_ITEM_COUNT];
    cui_inline_draw_top_info_struct info_box_draw;
#ifdef __MMI_INLINE_SLIM__ 
    MMI_BOOL characters_list_is_allowed;
    const UI_character_type *characters_list;
#endif
    
} cui_inline_instance_struct;


#if 1//def INLINE_CUI_MEMORY_FROM_ASM
#define INLINE_TEXT_BUFFER_SIZE            ONE_INLINE_TEXT_COUNT*CUI_INLINE_TEXT_BUFFER_SIZE
#define INLINE_TEXT_BUFFER_USED_INFO_SIZE  ONE_INLINE_TEXT_COUNT
#define INLINE_INSTANCE_SIZE               sizeof(cui_inline_instance_struct) 

//#define INLINE_CUI_ASM_DEBUG_TRACE
#define INLINE_CUI_INSTANCE_SIZE  (INLINE_INSTANCE_SIZE+INLINE_TEXT_BUFFER_SIZE+INLINE_TEXT_BUFFER_USED_INFO_SIZE)

typedef enum
{
    CUI_INLINE_NOT_CREATE = 0,
    CUI_INLINE_CREATE_WITH_ASM,
    CUI_INLINE_CREATE_WITH_ADM,
    CUI_INLINE_CREATE_WITH_MEMORY_POINT,
    CUI_INLINE_CREATE_INFO_MAX_ID    
}cui_inline_create_info;



typedef struct cui_inline_asm_instance_struct
{       
    cui_inline_create_info is_create;  /* is  created flag from ASM  */
    KAL_ADM_ID app_adm_id; /* ID of ADM which created CUI */
    mmi_id app_id;         /* ID of APP which created CUI */    
    cui_inline_instance_struct * asm_instance; /* instance 's address of ASM */
    U8 *inline_text_buff_used;  /*CUI's text buff use inof*/
    U8 *inline_text_buff;       /*CUI's text buff address*/
    
} cui_inline_asm_instance_struct;

#endif

typedef struct
{
    U16 lsk_text_id;
    U16 rsk_done_text_id;
    U16 rsk_back_text_id;
    U16 csk_icon_id;
}cui_inline_softkey_default_text_struct;

typedef struct
{
    S32 key_code;
    S32 key_event;
}cui_inline_activate_behavior_struct;

/*****************************************************************************  
*   Extern Functions for inline
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *	cui_inline_get_item_lsk_string_id
 * DESCRIPTION
 *	
 * PARAMETERS
 *	index		[IN]		
 * RETURNS
 *	current left softkey string id
 *****************************************************************************/
extern U16 cui_inline_get_item_lsk_string_id(S32 index);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_evt_submit_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_inline_evt_submit_int(MMI_ID gid, WGUI_SOFTKEY_ENUM key);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_evt_abort_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_inline_evt_abort_int(MMI_ID gid);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_item_default_lsk_strind_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  return left softkey id
 *****************************************************************************/
extern U16 cui_inline_get_item_default_lsk_strind_id(S32 index);

U16 cui_inline_convert_id_to_index(mmi_id gid, S32 id);
void cui_inline_set_item_default_softkey_attribute(S32 index);
MMI_BOOL cui_inline_is_item_lsk_by_app(S32 index);
void cui_inline_replace_item_softkey_by_app(S32 index);
extern void cui_inline_lock_draw_softkey(MMI_BOOL IsLock);
void cui_inline_evt_submit(WGUI_SOFTKEY_ENUM key);
void cui_inline_evt_abort(void);
void cui_inline_evt_csk_press(void);
void cui_inline_evt_set_key(void);
void cui_inline_evt_mainscreen_exit(void);
void cui_inline_evt_item_activate(void);
#ifndef __MMI_INLINE_SLIM__
void cui_inline_evt_item_changed(void);
#else
void cui_inline_evt_item_changed(U16 index);
#endif
void cui_inline_evt_item_text_not_empty(void);
void cui_inline_evt_item_text_empty(void);
void cui_inline_evt_item_image_text_pen_down_0(void);
void cui_inline_evt_item_image_text_pen_down_1(void);
#ifndef __MMI_INLINE_SLIM__
void cui_inline_evt_item_select_focus_changed(S32 select_index) ;  
#endif
void cui_inline_evt_item_color_select_focus_changed(U16);
U8 *cui_inline_evt_item_user_defined_select_focus_changed(cui_inline_user_defined_select_highlight_enum flag, S16 index);
void cui_inline_item_replace_gui_buffer(S32 index, wgui_inline_item *inline_item, PU8 *history_buffer);
void cui_inline_item_save_gui_buffer(S32 index, wgui_inline_item *inline_item, PU8 history_buffer);
void cui_inline_item_replace_input_buffer(S32 index, wgui_inline_item *inline_item);
MMI_BOOL cui_inline_is_current_cui(void);
void cui_inline_lsk_function(void);
void cui_inline_rsk_function(void);
void cui_inline_csk_function(void);
void cui_inline_register_lsk_handler(void);
void cui_inline_register_rsk_handler(void);
void cui_inline_register_csk_handler(void);
void cui_inline_highlight_handler(S32 index);
void cui_inline_reset_instance_point(void);
void cui_inline_item_save_input_buffer(void);
void cui_inline_entry_options_screen(void);
void cui_inline_progress_bar_change_callback(void);
MMI_BOOL cui_inline_is_edit_main_screen(mmi_id gid);
void cui_inline_selector_update_old_index(S32 old_index);
#ifdef __MMI_INLINE_SLIM__
void cui_inline_set_char_filter_to_inline(MMI_BOOL *is_allowed, const UI_character_type * * characters_list);
#endif



/* struct cui_inline_instance_struct; */

/***************************************************************************** 
*  Extern Variables
*****************************************************************************/

extern struct cui_inline_instance_struct *g_cui_inline_current_instance;

/*****************************************************************************
                   Extern for Inline CUI
****************************************************************************/
U8 inline_text_edit_set_history(U16 history_ID, U8 *history_buffer);
#ifndef __MMI_INLINE_SLIM__
extern single_line_input_box MMI_inline_singleline_inputbox;
#endif
extern U8 inline_date_edit_set_history(U16 history_ID, U8 *history_buffer);
extern U8 inline_time_edit_set_history(U16 history_ID, U8 *history_buffer);
extern U8 inline_time_period_edit_set_history(U16 history_ID, U8 *history_buffer);
extern U8 inline_IP4_edit_set_history(U16 history_ID, U8 *history_buffer);
extern U8 inline_DOW_select_set_history(U16 history_ID, U8 *history_buffer);
U8 inline_image_text_set_history(U16 history_ID, U8 *history_buffer);
extern void handle_inline_full_screen_edit_complete(void);
extern void ShowCategory57Screen_for_title(
    PU8 title_string,
    U16 title_icon,
    U16 left_softkey,
    U16 left_softkey_icon,
    U16 right_softkey,
    U16 right_softkey_icon,
    S32 number_of_items,
    U16 *list_of_icons,
    InlineItem *list_of_items,
    S32 highlighted_item,
    U8 *history_buffer);
extern void (*complete_inline_item_edit) (void) ;
void wgui_inline_menu_enable_looping(void);
S32 wgui_inline_edit_get_next_highlight_index(S32 start_index);
void wgui_inline_item_key_handler(void);
void handle_inline_DOW_select_LSK_up(void);

extern U8 inline_image_text_edit_flag;
#ifndef __INLINE_DATETIME_SLIM__
extern date_input wgui_inline_date_input;
extern time_input wgui_inline_time_input;
#else
extern datetime_input wgui_inline_datetime_input;
#endif

#ifdef __MMI_INLINE_ITEM_TIME_PEROID__
extern time_period_input wgui_inline_time_period_input;
#endif

#ifndef __INLINE_DATETIME_SLIM__
#ifdef __MMI_INLINE_ITEM_IP4__
extern IP4_input wgui_inline_IP4_input;
#endif
#endif

#ifdef __MMI_INLINE_ITEM_DOW__
extern DOW_select MMI_inline_DOW_select;
#endif

extern wgui_inline_item *current_wgui_inline_item;
extern S32 wgui_n_inline_items;

extern U8 wgui_inline_list_menu_changed ;
extern U8 wgui_inline_list_menu_disable_done;
extern U8 wgui_inline_list_menu_rsk_back;
extern S32 wgui_inline_item_highlighted_index;

extern PU8 wgui_inline_full_screen_text_edit_buffer;

extern const U16 gIndexIconsImageList[];

extern void SetInlineIconStyle(InlineItem *item, PU8 picon, BOOL b);

extern void wgui_inline_option_menu_done_lsk_handler(mmi_id menu_gid);

extern void (*redraw_current_inline_item) (void);

#ifdef __MMI_INLINE_SLIM__
extern void wgui_inline_lsk_fs_cui_editor(void);

extern void wgui_inline_lsk_menu_cui_select(void);
#endif

#endif /* MMI_INLINECUI_H */

