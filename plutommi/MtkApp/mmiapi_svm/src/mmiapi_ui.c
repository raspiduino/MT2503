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
 * mmiapi_ui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
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
 *============================================================================== *******************************************************************************/

#include "MMI_include.h"

// #define MMIAPI_USING_SMS
#define MMIAPI_USING_UI
#define MMIAPI_USING_BLOCKING
#include "mmiapi_struct.h"
#include "mmiapi.h"
#include "mmiapi_func.h"
#include "mmiapi_res.h"

#include "ems.h"

#include "Wgui_softkeys.h"
#include "gui_generic_menuitems.h"
#include "gui_generic_menus.h"
#include "gui_bytestream.h"
#include "CommonScreens.h"
/* added for phone book */
#include "PhbCuiGprot.h"
#include "PhbSrvGprot.h"
/* added for phone book end */

#include "FSEditorCuiGprot.h"

#include "SettingResDef.h"  //added for "Writing lauange"

#if defined (__J2ME__)
#include "jam_internal.h"
#include "jam_interface.h"
#include "jui_interface.h"
#endif

#include "DateTimeType.h"
#include "DateTimeGprot.h"

#include "wgui_calendar.h"

#include "JavaAgencyDef.h"

#include "CommonScreensResDef.h"
#include "SettingResDef.h"

#include "custom_mmi_default_value.h"
#include "gui_typedef.h"
#include "kal_non_specific_general_types.h"
#include "stack_config.h"
#include "kal_release.h"
#include "MMI_features.h"
#include "GlobalResDef.h"
#include "app_datetime.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "Unicodexdcl.h"
#include "mmi_frm_input_gprot.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "app_mem.h"
#include "mmi_rp_app_phonesetting_new_def.h"
#include "wgui_categories_util.h"
#include "mmi_rp_srv_editor_def.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_inputs.h"
#include "gdi_include.h"
#include "gui_data_types.h"
#include "wgui_include.h"
#include "gui_inputs.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#ifdef __J2ME__
#include "jvm_def.h"
#endif /* __J2ME__ */

#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_calendar.h"
#include "CustDataRes.h"
#include "stdio.h"
#include "gui_calendar.h"
#include "gui_theme_struct.h"
    
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);
extern void ClearKeyEvents(void);
#ifdef __J2ME__
extern U16 mmi_java_get_title_icon(void);
#define MMI_GET_TITLE_ICON mmi_java_get_title_icon()
#else
#define MMI_GET_TITLE_ICON NULL
#endif

#ifndef __J2ME__
#define GRP_ID_JAVA_APP 0
#define GRP_ID_JAVA_TEXTFIELD 0
#endif /* __J2ME__ */
typedef struct
{
    MYTIME CalTime;
    S8 DayBuf[MMIAPI_UI_CLNDR_DAY_LEN];
    S8 MonBuf[MMIAPI_UI_CLNDR_MON_LEN];
    S8 YearBuf[MMIAPI_UI_CLNDR_YEAR_LEN];
    U8 DayOnFirst;
    U8 NumDaysInMonth;
    U8 *Title;
    U8 *HorizonList[MMIAPI_UI_CLNDR_COLUMN];
    U8 *VerticalList[MMIAPI_UI_CLNDR_ROW];
    gui_calendar_cell_struct *CalendarCell;
    U8 RowNumber;
    U8 horizon_select1[MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN];
    U8 horizon_select2[MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN];
} mmiapi_ui_clndr_context_struct;


typedef enum
{
    MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA = 0,
    MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA_MMI,
    MMIAPI_UI_JAVA_SCREEN_TYPE_UNKNOWN,
    MMIAPI_UI_JAVA_SCREEN_TYPE_TOTAL
}MMIAPI_UI_JAVA_SCREEN_TYPE_ENUM;

static kal_int32 mmiapi_ui_java_screen_type = MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fullscreen Editor 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FULLSCREEN_EDITOR_RETURN_NONE  0
#define FULLSCREEN_EDITOR_RETURN_DONE  1
#define FULLSCREEN_EDITOR_RETURN_CANCEL   2

extern const U16 gIndexIconsImageList[];

/* mmiapi lock */
volatile int mmiapi_ui_lcd_mutex_cnt = 0;
volatile module_type mmiapi_ui_lcd_mutex_tid = MOD_NIL;
extern kal_mutexid mmiapi_mutex_control;

/*------------the flowing for TextField ------------------*/
void mmiapi_ui_enter_fullscreen_editor_rsp(module_type mod_dest);

/*------------the above for TextField ------------------*/


/*------------the flowing for TextBox ------------------*/
static void mmiapi_enter_textbox_editor(void);
static MMI_BOOL mmiapi_textbox_editor_is_display_option(void);
static void mmiapi_goto_textbox_editor_option(void);
static void mmiapi_exit_textbox_editor_option(void);
static void mmiapi_exit_textbox_editor_with_cancel(void);
static void mmiapi_textbox_editor_customize_key(void);
static void mmiapi_goto_textbox_search_number(void);
static int mmiapi_check_textbox_editor_input_value();
static void mmiapi_textbox_number_empty(void);
static mmi_ret mmiapi_textbox_editor_set_number(mmi_event_struct *evt);
static void mmiapi_ui_textbox_option_highlight_handler(S32 index);
static void mmiapi_ui_textbox_option_leftkey_handler(void);
static void mmiapi_ui_textbox_editor_endkey_handler(void);
static void mmiapi_ui_terminate_mmi_textbox_editor_req(module_type mod_dest);

static void mmiapi_ui_textbox_reset_menus();
static void mmiapi_ui_textbox_update_text(
										  kal_uint8 *text_buffer,
										  kal_int32 max_length,
										  kal_int32 constraint,
										  kal_bool editable);
static void mmiapi_ui_textbox_update_title(kal_uint8 *title);
static void mmiapi_ui_textbox_update_ticker(kal_uint8 *titcker);
static void mmiapi_ui_textbox_update_commands(kal_uint16 **menu_list, kal_int32 menu_num, kal_int32 *menu_ids);

/*------------the above for TextBox ------------------*/

#ifdef __J2ME__
/*------------the flowing for DateField ------------------*/
static void mmiapi_ui_clndr_get_date_str(MYTIME *date, U8 *dateStr);
static void mmiapi_ui_clndr_get_weekday(U8 **weekdayStr);
static void mmiapi_ui_clndr_get_week_numbers(U16 year, U8 month, U8 **weekStr);
static void mmiapi_ui_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len);
static void mmiapi_ui_clndr_construct_monthly_cell_info(void);
static void mmiapi_ui_clndr_get_screenInfo(void);
static MMI_BOOL mmiapi_ui_clndr_monthly_highlight(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_monthly_compute_next_time(U32 arrow);
static MMI_BOOL mmiapi_ui_clndr_monthly_out_of_boundary(MYTIME *resultDate);
static MMI_BOOL mmiapi_ui_clndr_left_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_right_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_up_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_down_out_of_boundary(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_up_side_key(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_down_side_key(U32 row, U32 column);
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL mmiapi_ui_clndr_touch_year_increase(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_touch_year_decrease(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_touch_month_increase(U32 row, U32 column);
static MMI_BOOL mmiapi_ui_clndr_touch_month_decrease(U32 row, U32 column);
#endif /*#__MMI_TOUCH_SCREEN__*/
static MMI_BOOL mmiapi_ui_clndr_monthly_movement(U32 type);
static void mmiapi_ui_clndr_monthly_set_content(void);
static void mmiapi_ui_clndr_done_handler(void);
static void mmiapi_ui_clndr_cancel_handler(void);
static void mmiapi_ui_entry_datefield_date(void);
static void mmiapi_ui_entry_datefield_date(void);
static void mmiapi_ui_delete_datefield_date_callback(void);
/*------------the above for DateField ------------------*/
#endif

static void mmiapi_ui_ime_common_scr_entry_callback(kal_uint16 old_scr_id,kal_uint16 new_scr_id);
static void mmiapi_ui_ime_common_scr_exit_callback(kal_uint16 old_scr_id,kal_uint16 new_scr_id);


#define STR_AT(RAW,n) (void*)(((kal_uint8*)RAW)+((n)<<1))
#define CHR_AT(RAW,n) (*(kal_uint16*)STR_AT(RAW,n))
#define CHR(x)      ((kal_uint16)x)

/////////////////////////////////////////////////////////////////////////////////////
// variables related to fullscreen editor
/////////////////////////////////////////////////////////////////////////////////////
static kal_uint8 *mmiapi_fullscreen_editor_input_buffer;
static kal_int32 mmiapi_fullscreen_editor_input_buffer_max_len;

/* remember current mmiapi_fullscreen_editor type */
static kal_bool mmiapi_fullscreen_editor_input_required;
static S32 mmiapi_fullscreen_editor_input_type;
static void (*mmiapi_fullscreen_editor_callback)(kal_bool result, int text_len);    

/* disable switching input method */
static int mmiapi_fullscreen_editor_return_value;

#define MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM		32
#define MMIAPI_TEXTBOX_MAX_MENU_ITEM_LENGTH	    64

/*-------------------textbox value----------------*/
static kal_uint8 *mmiapi_textbox_editor_input_buffer;
static kal_int32 mmiapi_textbox_editor_input_buffer_max_len;

static kal_uint32 mmiapi_textbox_editor_input_type;

/* disable switching input method */
static kal_bool mmiapi_textbox_editor_disable_switch_IM;
static kal_bool mmiapi_textbox_editor_editable;
static kal_uint8 *mmiapi_textbox_editor_title;
static kal_uint8 *mmiapi_textbox_editor_ticker;
static kal_int32 mmiapi_textbox_editor_menu_num;

static kal_int32 mmiapi_textbox_editor_menu_selected_index = -1;
static kal_uint8 **mmiapi_textbox_editor_option_list_ptr;
static kal_uint8 **mmiapi_textbox_editor_option_icons_ptr;
static kal_int32 mmiapi_textbox_editor_option_inputmethod_index = -1;
static kal_int32 mmiapi_textbox_editor_option_insertsymbol_index = -1;

static void (*mmiapi_textbox_enter_callback) ();
static void (*mmiapi_textbox_exit_callback) ();

static kal_uint8 *mmiapi_textbox_editor_gui_buffer;

static kal_bool mmiapi_textbox_editor_is_endkey_pressed = KAL_FALSE;
static kal_bool mmiapi_textbox_editor_is_data_updated = KAL_FALSE;
static kal_bool mmiapi_textbox_editor_is_editor_updated = KAL_FALSE;

static kal_uint16 mmiapi_textbox_editor_menu_text_buffer[MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM][MMIAPI_TEXTBOX_MAX_MENU_ITEM_LENGTH+1];
static kal_int32 mmiapi_textbox_editor_menu_id_buffer[MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM];
/*--------------- textbox -------------------------*/


static MMI_ID mmiapi_phone_numer_id;
static MMI_ID mmiapi_phone_number_group_id;

static MMI_ID mmiapi_fullscreen_editor_id = GRP_ID_INVALID;
static MMI_ID mmiapi_fullscreen_editor_group_id = GRP_ID_INVALID;

static kal_bool mmiapi_fullscreen_search_flag = KAL_FALSE;
static kal_bool mmiapi_fullscreen_active = KAL_FALSE;

/* -----------------menu -------------------*/
static kal_int32 mmiapi_menu_index = 0;
static kal_uint16 **mmiapi_menu_list;
static kal_int32 mmiapi_menu_num;
static kal_int32 *mmiapi_menu_ids;
static kal_uint8 **mmiapi_menu_icons_ptr;
/*------------------menu -------------------*/

/*-----------the following for DateField-----------------*/
const S8 mmiapi_ui_clndr_weekday[] = {'S','M','T','W','T','F','S'};
static mmiapi_ui_clndr_context_struct g_clndr_context_struct;
mmiapi_ui_clndr_context_struct *g_mmiapi_ui_clndr_cntx  = &g_clndr_context_struct ;
static void ( *mmiapi_ui_datefield_date_callback)(kal_bool date_udpated,kal_uint16 year,kal_uint8 month,kal_uint8 day);
/*-----------the above for DateField-----------------*/

/* Java JTWI spec */
static const U8 *JTWISymbol[5] = 
{
    (U8 *) "\x5e\0\0",		// circumflex accent
		(U8 *) "\x60\0\0",		// grave acent
		(U8 *) "\x7c\0\0",		// vertical bar
		(U8 *) "\xa1\0\0",		// inverted exclamation
		(U8 *) "\xbf\0\0",		// inverted question mark
};

#ifdef __J2ME__
/*****************************************************************************
* FUNCTION
 *  mmiapi_ui_clndr_highlight_select_handler
 * DESCRIPTION
 *  Calendar highlighted cell select handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmiapi_ui_clndr_highlight_select_handler(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiapi_ui_clndr_done_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_ui_clndr_highlight_change_handler
 * DESCRIPTION
 *  Calendar highlighted cell change handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_highlight_change_handler(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time,
             applib_time_struct start_time,
             applib_time_struct end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME myTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlighted_time.nYear == g_mmiapi_ui_clndr_cntx->CalTime.nYear &&
        highlighted_time.nMonth == g_mmiapi_ui_clndr_cntx->CalTime.nMonth)
    {
        g_mmiapi_ui_clndr_cntx->CalTime.nDay = highlighted_time.nDay;
        g_mmiapi_ui_clndr_cntx->CalTime.DayIndex = DOW(g_mmiapi_ui_clndr_cntx->CalTime.nYear, g_mmiapi_ui_clndr_cntx->CalTime.nMonth, g_mmiapi_ui_clndr_cntx->CalTime.nDay);
        return MMI_TRUE;
    }
    else
    {
        memset(&myTime, 0, sizeof(MYTIME));
        myTime.nYear = highlighted_time.nYear;
        myTime.nMonth = highlighted_time.nMonth;
        myTime.nDay = highlighted_time.nDay;
        return mmiapi_ui_clndr_monthly_out_of_boundary(&myTime);
    }
}
#endif

/*****************************************************************************
* FUNCTION
*  mmiapi_init_fullscreen_editor
* DESCRIPTION
*  this function will initialize some global variables local to this file.
* CALLS
*  
* PARAMETERS
*  src                 [?]         
*  maxlen              [IN]        
*  type                [IN]        
*  input_required      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_init_fullscreen_editor(kal_uint8 *src, int maxlen, int type, kal_bool input_required, void (*editor_cb)(kal_bool result, int text_len))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiapi_fullscreen_editor_return_value = FULLSCREEN_EDITOR_RETURN_NONE;
	
    mmiapi_fullscreen_editor_input_buffer = src;
    mmiapi_fullscreen_editor_input_buffer_max_len = maxlen;
    mmiapi_fullscreen_editor_input_required = input_required;
    mmiapi_fullscreen_editor_input_type = type;
    mmiapi_fullscreen_editor_callback = editor_cb;    	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_check_fullscreen_editor_input_value
* DESCRIPTION
*  check the validity of the input value, and prompt error message
*  It _must_ be called from mmiapi_exit_fullscreen_editor_with_done()
* PARAMETERS
*  void
* RETURNS
*  1: ok 0: fail
*****************************************************************************/
/* 1: ok 0: fail */
static int mmiapi_check_fullscreen_editor_input_value()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}



/*****************************************************************************
* FUNCTION
*  mmiapi_add_extra_symbol
* DESCRIPTION
*  Add extra symbols into symbol table
* CALLS
*  
* PARAMETERS
*  out         [?]
*  out_max     [IN]
*  in          [IN]
*  in_max      [IN]
* RETURNS
*  S32         numbers of symbols to add
*****************************************************************************/
S32 mmiapi_add_extra_symbol(U8* out, S32 out_max, U8** in, S32 in_max)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 previousScrnId;
    U16 currScrnId ;
    U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < in_max; i++)
    {
		memcpy(out + i * 4, *(in + i), 4);
    }

    if(mmiapi_fullscreen_active)
    {
    	for (i = 0; i < sizeof(JTWISymbol)/4; i++)
        {
		    memcpy(out + in_max * 4 + i * 4, *(JTWISymbol + i), 4);
        }
        return (in_max + sizeof(JTWISymbol)/4);
    }
	
    //if (!IsScreenPresent(MMIAPI_SCREEN_FULLSCREEN_EDITOR) && !(IsScreenPresent(MMIAPI_SCREEN_TEXTBOX_EDITOR)))
    if(!mmi_frm_scrn_is_present(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR,MMI_FRM_NODE_ALL_FLAG))
    {
        return in_max;
    }
	
    currScrnId = MMIAPI_SCREEN_TEXTBOX_EDITOR;

    i = 1;
    previousScrnId = mmi_frm_scrn_get_neighbor_id(GRP_ID_JAVA_APP,currScrnId,MMI_FRM_NODE_BEFORE_FLAG);
    while (/*GetPreviousScrnIdOf(currScrnId, &previousScrnId)*/ previousScrnId != SCR_ID_INVALID) //10A
    {
        currScrnId = previousScrnId;
        i++;
        previousScrnId = mmi_frm_scrn_get_neighbor_id(GRP_ID_JAVA_APP,currScrnId,MMI_FRM_NODE_BEFORE_FLAG);
    }
    
    if ((/*GetScreenCountInHistory()*/mmi_frm_scrn_get_count(GRP_ID_JAVA_APP) - i) > 2 )
    {
        return in_max;
    }
	
    for (i = 0; i < sizeof(JTWISymbol)/4; i++)
    {
		memcpy(out + in_max * 4 + i * 4, *(JTWISymbol + i), 4);
    }
    return (in_max + sizeof(JTWISymbol)/4);
}


/*****************************************************************************
* FUNCTION
*  mmiapi_fullscreen_editor_proc
* DESCRIPTION
*  enter full screen editor and put mmiapi screen into history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

static mmi_ret mmiapi_fullscreen_editor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct * event;
    S8 * number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            mmiapi_fullscreen_active = KAL_TRUE;
            break;
        case EVT_ID_GROUP_INACTIVE: 
            mmiapi_fullscreen_active = KAL_FALSE;
            break;
        case EVT_ID_GROUP_DEINIT:
            mmiapi_fullscreen_active = KAL_FALSE;
            break;
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
            mmi_frm_group_close(GRP_ID_JAVA_TEXTFIELD);
            break;

        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            /* Handler when user confirm input */
            if(mmiapi_fullscreen_search_flag)
            {
                mmiapi_phone_numer_id = cui_phb_list_select_contact_create(GRP_ID_JAVA_TEXTFIELD);     
                cui_phb_list_select_contact_set_field_filter(mmiapi_phone_numer_id, SRV_PHB_ENTRY_FIELD_GSM_NUM);
                cui_phb_list_select_contact_run(mmiapi_phone_numer_id);
            }
            else
            {
                cui_fseditor_get_text(mmiapi_fullscreen_editor_id, (WCHAR*)mmiapi_fullscreen_editor_input_buffer,mmiapi_fullscreen_editor_input_buffer_max_len*ENCODING_LENGTH);
                mmiapi_fullscreen_editor_return_value = FULLSCREEN_EDITOR_RETURN_DONE;
                mmiapi_ui_enter_fullscreen_editor_rsp(MOD_JAM);
                cui_fseditor_close(mmiapi_fullscreen_editor_id);
            }
            break;
        case EVT_ID_CUI_FSEDITOR_ABORT:
            /* Handler when user Cancel input */

            mmiapi_fullscreen_editor_return_value = FULLSCREEN_EDITOR_RETURN_CANCEL;
            mmiapi_ui_enter_fullscreen_editor_rsp(MOD_JAM);
            cui_fseditor_close(mmiapi_fullscreen_editor_id);
            break;
        case EVT_ID_CUI_FSEDITOR_EMPTY:
            /* Handler when editor content is empty */
            if((mmiapi_fullscreen_editor_input_type & (~INPUT_TYPE_OVERRIDE_DEFAULT))== IMM_INPUT_TYPE_PHONE_NUMBER)
            {
                cui_fseditor_set_softkey_text(mmiapi_fullscreen_editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SEARCH);
                cui_fseditor_set_softkey_icon(mmiapi_fullscreen_editor_id, MMI_LEFT_SOFTKEY, 0);
                cui_fseditor_set_softkey_icon(mmiapi_fullscreen_editor_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
                mmiapi_fullscreen_search_flag = KAL_TRUE;
            }
     
            break;
        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            /* Handler when editor content is not empty */
            if((mmiapi_fullscreen_editor_input_type& (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER)
            {
                cui_fseditor_set_softkey_text(mmiapi_fullscreen_editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
                cui_fseditor_set_softkey_icon(mmiapi_fullscreen_editor_id, MMI_LEFT_SOFTKEY, 0);
                cui_fseditor_set_softkey_icon(mmiapi_fullscreen_editor_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
                mmiapi_fullscreen_search_flag = KAL_FALSE;
            }
            break;
       case EVT_ID_PHB_SELECT_CONTACT:
		event = (cui_phb_select_contact_result_struct*)evt;
		number = (S8 *)(event->select_data);
		if(number)
		{
			mmi_ucs2ncpy((S8*) mmiapi_fullscreen_editor_input_buffer, (PS8) number, mmiapi_fullscreen_editor_input_buffer_max_len-1);
            cui_fseditor_set_text(mmiapi_fullscreen_editor_id, 
                (WCHAR*)mmiapi_fullscreen_editor_input_buffer, 
                mmiapi_fullscreen_editor_input_buffer_max_len, 
                mmiapi_fullscreen_editor_input_buffer_max_len-1);
		}
		cui_phb_list_select_contact_close(mmiapi_phone_numer_id);
		break;
	case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
		cui_phb_list_select_contact_close(mmiapi_phone_numer_id);
		break;
   }
   return MMI_RET_OK;
}



/*****************************************************************************
* FUNCTION
*  mmiapi_enter_fullscreen_editor
* DESCRIPTION
*  enter full screen editor and put mmiapi screen into history
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmiapi_enter_fullscreen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmiapi_fullscreen_editor_group_id != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmiapi_fullscreen_editor_group_id);
        mmiapi_fullscreen_editor_group_id = GRP_ID_INVALID;
    }
    
    mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_JAVA_TEXTFIELD, mmiapi_fullscreen_editor_proc, NULL); 
    mmi_frm_group_enter(GRP_ID_JAVA_TEXTFIELD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmiapi_fullscreen_search_flag = KAL_FALSE;        
    
    mmiapi_fullscreen_editor_id = cui_fseditor_create(GRP_ID_JAVA_TEXTFIELD);

    if( mmiapi_fullscreen_editor_id != GRP_ID_INVALID)
    {
        cui_fseditor_set_title(mmiapi_fullscreen_editor_id, STR_GLOBAL_TEXT, mmi_java_get_title_icon());
        cui_fseditor_set_text(mmiapi_fullscreen_editor_id, 
                (WCHAR*)mmiapi_fullscreen_editor_input_buffer, 
                mmiapi_fullscreen_editor_input_buffer_max_len, 
                mmiapi_fullscreen_editor_input_buffer_max_len-1);
        cui_fseditor_set_input_method(mmiapi_fullscreen_editor_id, mmiapi_fullscreen_editor_input_type, NULL, IMM_INPUT_MODE_NONE);
        cui_fseditor_run(mmiapi_fullscreen_editor_id);
    }
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_enter_fullscreen_editor_req
* DESCRIPTION
*  enter fullscreen editor
* CALLS
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_enter_fullscreen_editor_req(mmiapi_ui_enter_fullscreen_editor_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);
	
    mmiapi_init_fullscreen_editor(msg->editor_buffer, msg->maxlen, msg->type, msg->is_must_input, msg->editor_cb);
    ClearKeyEvents();   /* clear all keypad buffer */
    mmiapi_enter_fullscreen_editor();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_enter_fullscreen_editor_rsp
* DESCRIPTION
*  
* PARAMETERS
*  mod_dest        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_enter_fullscreen_editor_rsp(module_type mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    mmiapi_ui_enter_fullscreen_editor_rsp_struct *msg = NEW_LOCAL_PTR(mmiapi_ui_enter_fullscreen_editor_rsp_struct);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_fullscreen_editor_return_value == FULLSCREEN_EDITOR_RETURN_DONE)
    {
        msg->result = KAL_TRUE;
    }
    else
    {
        msg->result = KAL_FALSE;
    }
    msg->text_length = mmiapi_fullscreen_editor_input_buffer_max_len;
    msg->jui_editor_cb = mmiapi_fullscreen_editor_callback;
	
    SEND_MESSAGE(MOD_MMI, mod_dest, MMI_J2ME_SAP, MSG_ID_MMIAPI_UI_ENTER_FULLSCREEN_EDITOR_RSP, msg, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_enter_idle_screen_rsp
* DESCRIPTION
*  
* PARAMETERS
*  mod_dest        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_enter_idle_screen_rsp(module_type mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SEND_MESSAGE(MOD_MMI, mod_dest, 0, MSG_ID_MMIAPI_UI_ENTER_IDLE_SCREEN_RSP, NULL, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_enter_idle_screen_req
* DESCRIPTION
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_enter_idle_screen_req(mmiapi_ui_enter_idle_screen_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);
	
    mmi_idle_display();
	
    if (!IS_BLOCKING(mod_src))
    {
        mmiapi_ui_enter_idle_screen_rsp(mod_src);
    }
    BLOCKING_FINISH(mod_src);
}


/*****************************************************************************
 * FUNCTION
 *  mmiapi_remove_fullscreen_screen
 * DESCRIPTION
 *  This function will remove mmiapi-related fullscreen editor screen
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmiapi_remove_fullscreen_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION);
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_FULLSCREEN_EDITOR);
	
    //DeleteScreenIfPresent(MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION);   //10A
    //DeleteScreenIfPresent(MMIAPI_SCREEN_FULLSCREEN_EDITOR);

    mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION);
    mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_FULLSCREEN_EDITOR);
    
}

//****************textbox***************************/


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_lcd_mutex_lock
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_lcd_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_LOCK; */
    //if (stack_int_get_active_module_id() != mmiapi_ui_lcd_mutex_tid)
    {
        kal_take_mutex(mmiapi_mutex_control);
	//  mmiapi_ui_lcd_mutex_tid = stack_int_get_active_module_id();
    }
    //++mmiapi_ui_lcd_mutex_cnt;
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_lcd_mutex_unlock
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_lcd_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//  ASSERT(mmiapi_ui_lcd_mutex_tid == stack_int_get_active_module_id());
	
	// --mmiapi_ui_lcd_mutex_cnt;
	
	// if (mmiapi_ui_lcd_mutex_cnt == 0)
    {
		//    mmiapi_ui_lcd_mutex_tid = MOD_NIL;
        kal_give_mutex(mmiapi_mutex_control);
    }
    /* GDI_UNLOCK; */
}
/*****************************************************************************
* FUNCTION
*  mmiapi_textbox_editor_customize_key
* DESCRIPTION
*  This function will remap keypad
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_textbox_editor_customize_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_textbox_editor_disable_switch_IM)
    {
        mmi_imm_config_change_input_mode(MMI_FALSE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmiapi_exit_textbox_editor_option
* DESCRIPTION
*  this function exit the fullscreen editor option menu
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_exit_textbox_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint16 nextScreenId = GetActiveScreenId();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GenericExitScreen(MMIAPI_SCREEN_FULLSCREEN_EDITOR_OPTION, mmiapi_goto_textbox_editor_option); */
    if (mmiapi_textbox_editor_option_icons_ptr)
    {
        applib_mem_screen_free(mmiapi_textbox_editor_option_icons_ptr);
        mmiapi_textbox_editor_option_icons_ptr = NULL;
    }
	
    if (mmiapi_textbox_editor_option_list_ptr)
    {
        applib_mem_screen_free(mmiapi_textbox_editor_option_list_ptr);
        mmiapi_textbox_editor_option_list_ptr = NULL;
    }

#if defined(__J2ME__)

    if(!jam_is_enter_in_fg_mmi_screen_2(nextScreenId))
    {
        mmiapi_ui_java_screen_type = MMIAPI_UI_JAVA_SCREEN_TYPE_UNKNOWN;
    }
    
	jam_exit_fg_mmi_screen_callback(MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION, nextScreenId, NULL);
#endif /*__J2ME__*/
}


/*****************************************************************************
* FUNCTION
*  mmiapi_textbox_editor_is_display_option
* DESCRIPTION
*  If the option menu of this texbox should be displayed.
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmiapi_textbox_editor_is_display_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  MMI_BOOL displayInputMethod = MMI_FALSE;
	  MMI_BOOL displayInsertSymbol = MMI_FALSE;
	  kal_uint8 tmp_menu_num;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMC_CAPITAL_SWITCH__) 
    if (mmi_imm_get_current_allowed_writing_language_num() > 1)
    {
    	  displayInputMethod = MMI_TRUE;
    }
#else
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
    	  displayInputMethod = MMI_TRUE;
    }
#endif /*__MMI_IMC_CAPITAL_SWITCH__ */

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (mmiapi_textbox_editor_editable)  
    {  
        displayInsertSymbol = MMI_TRUE;
    }    
#endif /* */

    if (mmiapi_textbox_editor_editable)
    {
    	  tmp_menu_num = 1;
    }
	  else
	  {
				tmp_menu_num = 2;
		}

		if (((!mmiapi_textbox_editor_disable_switch_IM) && (displayInputMethod || displayInsertSymbol)) || mmiapi_textbox_editor_menu_num > tmp_menu_num)
		{
				return MMI_TRUE;
		}
		else
		{
	    	return MMI_FALSE;
		}
}


/*****************************************************************************
* FUNCTION
*  mmiapi_goto_textbox_editor_option
* DESCRIPTION
*  this function will goto edit option menu.
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_goto_textbox_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *guiBuffer;
    kal_int16 nNumofItem;
    kal_bool displayInputMethod = KAL_FALSE;
    kal_int32 menu_id_temp;
    kal_int16 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmiapi_ui_lcd_mutex_lock();
	
    mmi_frm_scrn_enter(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION, mmiapi_exit_textbox_editor_option, NULL, MMI_FRM_FULL_SCRN);  //10A  
    guiBuffer = (U8*) mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION);
	

    nNumofItem = mmiapi_textbox_editor_menu_num;
	
    mmiapi_textbox_editor_option_inputmethod_index = -1;
    mmiapi_textbox_editor_option_insertsymbol_index = -1;
	
#if defined(__MMI_IMC_CAPITAL_SWITCH__) 
    if (mmi_imm_get_current_allowed_writing_language_num() > 1)
    {
    	 displayInputMethod = KAL_TRUE;
    }
#else
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
    	 displayInputMethod = KAL_TRUE;
    }
#endif /*__MMI_IMC_CAPITAL_SWITCH__ */
    //displayInputMethod = (!mmiapi_textbox_editor_disable_switch_IM) & mmiapi_textbox_editor_editable ;
	
    if (displayInputMethod && mmiapi_textbox_editor_editable)
    {
        nNumofItem += 1;
        mmiapi_textbox_editor_option_inputmethod_index = nNumofItem - 1;
    }

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (mmiapi_textbox_editor_editable)  
    {  
        nNumofItem += 1;
        mmiapi_textbox_editor_option_insertsymbol_index = nNumofItem - 1;
    }    
#endif /* */
	
    mmiapi_textbox_editor_option_list_ptr = (U8 **) applib_mem_screen_alloc(nNumofItem * sizeof(U8*));
	
    for (i = 0; i < mmiapi_textbox_editor_menu_num; i++)
    {
        mmiapi_textbox_editor_option_list_ptr[i] = (U8 *)mmiapi_textbox_editor_menu_text_buffer[i];/*(U8*) mmiapi_textbox_editor_menu_list[i];*/
    }


	//mmiapi_ui_textbox_reset_menus();

    if (displayInputMethod && mmiapi_textbox_editor_editable)
    {
#if defined(__MMI_IMC_CAPITAL_SWITCH__) ||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        mmiapi_textbox_editor_option_list_ptr[mmiapi_textbox_editor_option_inputmethod_index] =
            (U8*) get_string(STR_INPUT_METHOD_WRITING_LANGUAGE);
#else
        mmiapi_textbox_editor_option_list_ptr[mmiapi_textbox_editor_option_inputmethod_index] =
            (U8*) get_string(STR_GLOBAL_INPUT_METHOD);
#endif /*__MMI_IMC_CAPITAL_SWITCH__ */
    }
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if (mmiapi_textbox_editor_editable)
    {
        mmiapi_textbox_editor_option_list_ptr[mmiapi_textbox_editor_option_insertsymbol_index] =
            (U8*) get_string(STR_INPUT_METHOD_MENU_INSERT_SYMBOLS);   
    }
#endif /* __MMI_EDITOR_OPTION_MENU_STYLE_1__*/   
	
    mmiapi_textbox_editor_option_icons_ptr = (U8 **) applib_mem_screen_alloc(nNumofItem * sizeof(U8*));
    for (i = 0; i < nNumofItem; i++)
    {
        mmiapi_textbox_editor_option_icons_ptr[i] = (U8*) get_image(gIndexIconsImageList[i]);
    }
	
    RegisterHighlightHandler(mmiapi_ui_textbox_option_highlight_handler);

    //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);   //10A Key Rule
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    
	ShowCategory170Screen(
		(U8 * )get_string(STR_GLOBAL_OPTIONS), 
		(U8 *) get_image(MMI_GET_TITLE_ICON), 
		(U8 *) get_string(STR_GLOBAL_OK),
		(U8 *) get_image(IMG_GLOBAL_OK),
		(U8 *)get_string(STR_GLOBAL_BACK),
		(U8 *)get_image(IMG_GLOBAL_BACK),
        (S32)  nNumofItem,
		(U8 **) mmiapi_textbox_editor_option_list_ptr,
		( U8 **) mmiapi_textbox_editor_option_icons_ptr, 
		0, 
        0,
		guiBuffer);


	//don't need to key handler when there is no menu
	if (nNumofItem>0)
    {
		SetKeyHandler(mmiapi_ui_textbox_option_leftkey_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);
		SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_UP);
		
		SetLeftSoftkeyFunction(mmiapi_ui_textbox_option_leftkey_handler, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);   //10A

        SetCenterSoftkeyFunction(mmiapi_ui_textbox_option_leftkey_handler,KEY_EVENT_UP);    //10A Key Rule
	}
	
	
    SetKeyHandler(mmiapi_ui_textbox_editor_endkey_handler, KEY_END, KEY_EVENT_DOWN);
	mmiapi_ui_lcd_mutex_unlock();
#ifdef __J2ME__
    jam_resume_fg_mmi_screen_callback(MMIAPI_SCREEN_TEXTBOX_EDITOR, MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION,mmiapi_ui_java_screen_type,mmiapi_ui_java_screen_type);
#endif /* __J2ME__ */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_option_highlight_handler
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_option_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
        return;
	
    mmiapi_textbox_editor_menu_selected_index = index;
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_option_leftkey_handler
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_option_leftkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmiapi_textbox_editor_disable_switch_IM & mmiapi_textbox_editor_editable)
    {
        if (mmiapi_textbox_editor_menu_selected_index == mmiapi_textbox_editor_option_inputmethod_index)
        {
            RegisterInputMethodScreenCloseFunction(/*GoBackHistory*/mmi_frm_scrn_close_active_id);//10A
            EntryInputMethodScreen();
            return;
        }
        else if (mmiapi_textbox_editor_menu_selected_index == mmiapi_textbox_editor_option_insertsymbol_index)
        {
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
            mmi_ime_commonscreens_config_is_java_screens(MMI_TRUE);
#endif
            RegisterInputMethodScreenCloseFunction(/*GoBackHistory*/mmi_frm_scrn_close_active_id);//10A
            EntrySymbolPickerScreenFromMenuList();
            return;
        }	
    }
	
    //GoBackHistory();    //10A
    mmi_frm_scrn_close_active_id();

#if (defined(__J2ME__) && defined (__IJET_VM__))
    //kal_trace(TRACE_STATE, FUNC_J2ME_JUI_SELECT_MENU_SHOW, mmiapi_textbox_editor_menu_id_buffer[mmiapi_textbox_editor_menu_selected_index],mmiapi_textbox_editor_menu_selected_index);
    jvm_post_command_event(mmiapi_textbox_editor_menu_id_buffer[mmiapi_textbox_editor_menu_selected_index]);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmiapi_textbox_editor_set_number
* DESCRIPTION
*  set the phone number into edior buffer
* PARAMETERS
*  name        [IN]        Entry's name
*  number      [IN]        Entry's phonenumber
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmiapi_textbox_editor_set_number(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	  cui_phb_select_contact_result_struct* select_contact_result;
	  S8 * number;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (number)
    {
        mmi_ucs2ncpy(
            (S8*) mmiapi_textbox_editor_input_buffer,
            (PS8) number,
            mmiapi_textbox_editor_input_buffer_max_len - 1);
    }
    HistoryReplace(MMIAPI_SCREEN_TEXTBOX_EDITOR, MMIAPI_SCREEN_TEXTBOX_EDITOR, mmiapi_enter_textbox_editor);
    GoBackToHistory(MMIAPI_SCREEN_TEXTBOX_EDITOR);*/
    switch(evt->evt_id)
    {
	      case EVT_ID_GROUP_FIRST_ENTRY:
	      case EVT_ID_GROUP_INACTIVE:
		         break;
        
	      case EVT_ID_GROUP_ACTIVE:
		         break;
		
	      case EVT_ID_GROUP_GOBACK:
	      case EVT_ID_GROUP_DELETE_REQ:
		         break;
		
	      case EVT_ID_GROUP_DEINIT:
		         break;
	      case EVT_ID_PHB_SELECT_CONTACT:
		         select_contact_result = (cui_phb_select_contact_result_struct*)evt;
		         /**
		          * Do something self here
		          */
		
		         number = (S8 *)(select_contact_result->select_data);
		         if(number)
		         {
			           mmi_ucs2ncpy((S8*) mmiapi_textbox_editor_input_buffer, (PS8) number, mmiapi_textbox_editor_input_buffer_max_len-1);
			           mmiapi_textbox_editor_is_data_updated = KAL_TRUE;
		         }
		         HistoryReplace(MMIAPI_SCREEN_TEXTBOX_EDITOR, MMIAPI_SCREEN_TEXTBOX_EDITOR, mmiapi_enter_textbox_editor);
		         //GoBackToHistory(MMIAPI_SCREEN_FULLSCREEN_EDITOR);
		         /**
		          * Caller should call CUI close function to release CUI resource
		          */
		         cui_phb_list_select_contact_close(mmiapi_phone_numer_id);
		         break;
	      case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
		         /**
		           * Do something self here
		           */
		
		         /**
		           * Caller should call CUI close function to release CUI resource
		           */
		         cui_phb_list_select_contact_close(mmiapi_phone_numer_id);
		         break;
	      default:
		         break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmiapi_goto_textbox_search_number
* DESCRIPTION
*  this function will goto edit option menu.
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmiapi_close_phb_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_phb_list_select_contact_close(mmiapi_phone_numer_id);
}

/*****************************************************************************
* FUNCTION
*  mmiapi_goto_textbox_search_number
* DESCRIPTION
*  this function will goto edit option menu.
* CALLS
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_goto_textbox_search_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmiapi_textbox_editor_set_number);
#ifdef __J2ME__
	 mmiapi_phone_number_group_id = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmiapi_textbox_editor_set_number, NULL);
  
     mmi_frm_group_enter(mmiapi_phone_number_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     //mmi_frm_group_entry_ex(GRP_ID_ROOT, APP_JAVA, mmiapi_fullscreen_editor_set_number, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	  /** 
     * Caller should keep the CUI group id, because all operation about CUI depends on it
     */
	  mmiapi_phone_numer_id = cui_phb_list_select_contact_create(mmiapi_phone_number_group_id);
	
	  cui_phb_list_select_contact_set_field_filter(mmiapi_phone_numer_id, SRV_PHB_ENTRY_FIELD_GSM_NUM);
	
	  cui_phb_list_select_contact_run(mmiapi_phone_numer_id);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmiapi_textbox_number_empty
* DESCRIPTION
*  LSK handle when number input is empty
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_textbox_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeRightSoftkey(STR_GLOBAL_SEARCH, IMG_GLOBAL_OK);
    SetCategory5RightSoftkeyFunction(mmiapi_goto_textbox_search_number, KEY_EVENT_UP);
}

/*****************************************************************************
* FUNCTION
*  mmiapi_textbox_leftkey_handler
* DESCRIPTION
*  void
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

static void mmiapi_textbox_leftkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__J2ME__) && defined (__IJET_VM__))
    jam_notify_vm();
    jvm_post_command_event(mmiapi_textbox_editor_menu_id_buffer[0]);
#endif


}

/*****************************************************************************
* FUNCTION
*  mmiapi_textbox_rightkey_handler
* DESCRIPTION
*  void
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

static void mmiapi_textbox_rightkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__J2ME__) && defined (__IJET_VM__))
    jam_notify_vm();
    jvm_post_command_event(mmiapi_textbox_editor_menu_id_buffer[1]);
#endif

}
/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_editor_endkey_handler
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_editor_endkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __J2ME__ 
	jvm_end_key_handler();
#endif
}


/*****************************************************************************
* FUNCTION
*  mmiapi_exit_textbox_editor
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_exit_textbox_editor()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id;
    MMI_ID screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_textbox_editor_option_list_ptr)
    {
        applib_mem_screen_free(mmiapi_textbox_editor_option_list_ptr);
        mmiapi_textbox_editor_option_list_ptr = NULL;
    }

   mmi_frm_get_active_scrn_id(&group_id,&screen_id);
#if defined(__J2ME__)	
   if(!jam_is_enter_in_fg_mmi_screen_2(screen_id))
   {
        mmiapi_ui_java_screen_type = MMIAPI_UI_JAVA_SCREEN_TYPE_UNKNOWN;
   }
   
   jam_exit_fg_mmi_screen_callback((kal_uint16)MMIAPI_SCREEN_TEXTBOX_EDITOR, screen_id, NULL);
#endif /*__J2ME__*/	   
     
    #if 0
/* under construction !*/
/* under construction !*/
#if defined(__J2ME__)	
/* under construction !*/
#endif /*__J2ME__*/	
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #if defined(__J2ME__)	
/* under construction !*/
#endif /*__J2ME__*/	   
/* under construction !*/
    #endif /* removed for 10A */
    
    mmiapi_textbox_exit_callback();
}

/*****************************************************************************
* FUNCTION
*  mmiapi_enter_textbox_editor
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_show_textbox_editor_screen(kal_bool resumeCallback,kal_int32 previous_screen,kal_int32 next_screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i;
    kal_uint8 *leftKeyStr = NULL;
    kal_uint8 *rightKeyStr = NULL;
    kal_bool display_option = KAL_TRUE;

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    mmiapi_textbox_editor_gui_buffer = (U8*) mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR);
    if(mmiapi_textbox_editor_is_editor_updated || mmiapi_textbox_editor_is_data_updated)
    {
        mmiapi_textbox_editor_gui_buffer = NULL;
        if(!mmi_is_redrawing_bk_screens())
        {
            mmiapi_textbox_editor_is_editor_updated = KAL_FALSE;
            mmiapi_textbox_editor_is_data_updated = KAL_FALSE;
        }
    }
	
	  if (mmiapi_textbox_editor_editable && 
		    ((mmiapi_textbox_editor_input_type & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER))
    {
        RegisterInputBoxEmptyFunction(mmiapi_textbox_number_empty);
    }
	
    gdi_layer_lock_frame_buffer();
	
    wgui_cat2002_show(
        (UI_string_type) mmiapi_textbox_editor_title,
        (PU8 )get_image(MMI_GET_TITLE_ICON),
        NULL,
        0,
        NULL,
        0,
        mmiapi_textbox_editor_ticker,
        (U8*) mmiapi_textbox_editor_input_buffer,
        mmiapi_textbox_editor_input_buffer_max_len,
        mmiapi_textbox_editor_input_type,
        NULL,
        mmiapi_textbox_editor_editable,
        KAL_FALSE,
        mmiapi_textbox_editor_gui_buffer);
	
		if(mmiapi_textbox_editor_is_display_option())
    {
        //display_option = KAL_TRUE;
        //leftKeyStr = (U8*) get_string(STR_GLOBAL_OPTIONS);
        ChangeCenterSoftkey(0,IMG_GLOBAL_OPTION_CSK);
	    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
	    SetLeftSoftkeyFunction(mmiapi_goto_textbox_editor_option, KEY_EVENT_UP);
        //ChangeCenterSoftkey(STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmiapi_goto_textbox_editor_option,KEY_EVENT_UP);
    }
    else
    {
        //display_option = KAL_FALSE;

        if(mmiapi_textbox_editor_menu_num>0)
        {
            mmiapi_textbox_editor_option_list_ptr = (U8 **) applib_mem_screen_alloc(mmiapi_textbox_editor_menu_num * sizeof(U8*));
	
            for (i = 0; i < mmiapi_textbox_editor_menu_num; i++)
            {
                mmiapi_textbox_editor_option_list_ptr[i] = (U8 *)mmiapi_textbox_editor_menu_text_buffer[i];
            }

            //leftKeyStr = mmiapi_textbox_editor_option_list_ptr[0];
			ChangeLeftSoftkeyByString((UI_string_type)mmiapi_textbox_editor_option_list_ptr[0], 0);
		    SetLeftSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);

            //ChangeCenterSoftkey(STR_GLOBAL_OK,IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
        
            if(mmiapi_textbox_editor_menu_num == 2)
            {
                //rightKeyStr = mmiapi_textbox_editor_option_list_ptr[1];
				ChangeRightSoftkeyByString((UI_string_type)mmiapi_textbox_editor_option_list_ptr[1],0);
				SetRightSoftkeyFunction(mmiapi_textbox_rightkey_handler,KEY_EVENT_UP);
            }
        }
        else
        {
            //ResetCenterSoftkey();
            ChangeCenterSoftkey(0,0);
        }
    }
    
#ifdef __MMI_CLIPBOARD__ 
		wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD); 
	// //disabled clipboard
#endif /* __MMI_CLIPBOARD__ */
    
	reset_softkey(MMI_LEFT_SOFTKEY);
	reset_softkey(MMI_RIGHT_SOFTKEY);
    
    gdi_layer_unlock_frame_buffer();

#if defined (__J2ME__)
    if(resumeCallback)
		jam_resume_fg_mmi_screen_callback(0, MMIAPI_SCREEN_TEXTBOX_EDITOR,previous_screen,next_screen);
#endif /*__J2ME__*/

    gdi_lcd_repaint_all();
    
    /*if(display_option)
    {
		SetLeftSoftkeyFunction(mmiapi_goto_textbox_editor_option, KEY_EVENT_UP);
    }
    else
    {
        if(mmiapi_textbox_editor_menu_num>0)
        {
            SetLeftSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
            if(mmiapi_textbox_editor_menu_num>1)
            {
                SetRightSoftkeyFunction(mmiapi_textbox_rightkey_handler,KEY_EVENT_UP);
            } 
        }
    }*/
	
    SetKeyHandler(mmiapi_ui_textbox_editor_endkey_handler, KEY_END, KEY_EVENT_DOWN);
	
    mmiapi_textbox_enter_callback();
    /* customize key */
    mmiapi_textbox_editor_customize_key();


    mmi_ime_register_editor_common_scr_entry_callback(mmiapi_ui_ime_common_scr_entry_callback);
    mmi_ime_register_editor_common_scr_exit_callback(mmiapi_ui_ime_common_scr_exit_callback);

	

}


/*****************************************************************************
* FUNCTION
*  mmiapi_enter_textbox_editor
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_resume_textbox_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_get_active_scrn_id(&group_id,&screen_id);       // 10A
    mmi_frm_scrn_enter(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR, mmiapi_exit_textbox_editor, mmiapi_resume_textbox_editor, MMI_FRM_FULL_SCRN); //10A

    //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    mmiapi_show_textbox_editor_screen(!mmi_is_redrawing_bk_screens(),mmiapi_ui_java_screen_type,MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA_MMI);
	

}


/*****************************************************************************
* FUNCTION
*  mmiapi_enter_textbox_editor
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_enter_textbox_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


////#if defined(__J2ME__)
////    jui_lcd_mutex_lock();
////#endif /* __J2ME__ */    
    gdi_layer_lock_frame_buffer();

    if(mmi_frm_scrn_is_present(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR);
    }

    mmi_frm_get_active_scrn_id(&group_id,&screen_id);       // 10A
    //exit screen if the current screen is same to the new screen
    if(screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR)
    {
        if (mmiapi_textbox_editor_option_list_ptr)
        {
            applib_mem_screen_free(mmiapi_textbox_editor_option_list_ptr);
            mmiapi_textbox_editor_option_list_ptr = NULL;
        }
#if defined(__J2ME__)	
	   jam_exit_fg_mmi_screen_callback((kal_uint16)MMIAPI_SCREEN_TEXTBOX_EDITOR, (kal_uint16)MMIAPI_SCREEN_TEXTBOX_EDITOR, NULL);
#endif /*__J2ME__*/	
        ExitCategory5Screen();
	UI_common_screen_pre_exit();
	UI_common_screen_exit();
    }
    gdi_layer_unlock_frame_buffer();
    mmi_frm_scrn_enter(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR, mmiapi_exit_textbox_editor, mmiapi_resume_textbox_editor, MMI_FRM_FULL_SCRN); //10A
    mmiapi_ui_java_screen_type = MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA_MMI;
    //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    mmiapi_show_textbox_editor_screen(screen_id != MMIAPI_SCREEN_TEXTBOX_EDITOR,MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA,mmiapi_ui_java_screen_type);
////#if defined(__J2ME__)
////    jui_lcd_mutex_unlock();
////#endif /* __J2ME__ */ 
    gdi_lcd_repaint_all();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_reset_menus
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_reset_menus()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 temp;
    kal_int16 i;
    kal_uint16 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmiapi_textbox_editor_menu_num > 1)
    {
        for(i = 0 ;i < MMIAPI_TEXTBOX_MAX_MENU_ITEM_LENGTH ; i ++)
        {
            data = mmiapi_textbox_editor_menu_text_buffer[0][i];
            mmiapi_textbox_editor_menu_text_buffer[0][i] = mmiapi_textbox_editor_menu_text_buffer[1][i];
            mmiapi_textbox_editor_menu_text_buffer[1][i] = data;
        }
        
       // mmiapi_textbox_editor_menu_text_buffer[0][0] = (U16 *)(&mmiapi_textbox_editor_menu_text_buffer[1][0]);
       // mmiapi_textbox_editor_menu_text_buffer[1][0] = temp_ptr;

        temp = mmiapi_textbox_editor_menu_id_buffer[0];
        mmiapi_textbox_editor_menu_id_buffer[0] = mmiapi_textbox_editor_menu_id_buffer[1];
        mmiapi_textbox_editor_menu_id_buffer[1] = temp;
    }
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_show_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_show_mmi_textbox_editor_req(mmiapi_ui_show_mmi_textbox_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 constraint;
	kal_int32 i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BLOCKING_INIT(mod_src, msg);
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]Entry TextBox"); */
    //MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_TEXTBOX_SHOW, mmi_frm_scrn_get_active_id()== MMIAPI_SCREEN_TEXTBOX_EDITOR);
	
	
	
    mmiapi_textbox_editor_title = (kal_uint8*) msg->title;
    mmiapi_textbox_editor_ticker = (kal_uint8*) msg->ticker;
    mmiapi_textbox_editor_input_buffer = msg->editor_buffer;
    mmiapi_textbox_editor_input_buffer_max_len = msg->maxLen;
    mmiapi_textbox_editor_input_type = (U32) msg->constraint;

	for( i = 0 ; i < MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM ; i ++)
	{
		mmiapi_textbox_editor_menu_id_buffer[i] = msg->menu_ids[i];
		
	}

	for( i = 0 ; i < MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM && i < msg->menu_num; i ++)
	{
		for( j = 0 ;j < MMIAPI_TEXTBOX_MAX_MENU_ITEM_LENGTH ; j ++)
		{
			mmiapi_textbox_editor_menu_text_buffer[i][j] = msg->menu_list[i][j];
		}
	}
    mmiapi_textbox_editor_menu_num = msg->menu_num;
    mmiapi_textbox_enter_callback = msg->textbox_enter_callback;
    mmiapi_textbox_exit_callback = msg->textbox_exit_callback;
    mmiapi_textbox_editor_editable = msg->is_editable;

    mmiapi_ui_textbox_reset_menus();

    mmiapi_textbox_editor_disable_switch_IM = !mmiapi_textbox_editor_editable;
    mmiapi_textbox_editor_is_data_updated = KAL_TRUE;
    ClearKeyEvents();   /* clear all keypad buffer */
    mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR);
	mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION);
    //DeleteScreenIfPresent(MMIAPI_SCREEN_TEXTBOX_EDITOR);
    ////mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR);
#if defined (__J2ME__)
    if(jam_is_own_mmi_screen() || jam_is_own_java_screen())
        mmiapi_enter_textbox_editor(); 
#endif

    msg->textbox_callback();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_exit_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_exit_mmi_textbox_editor_req(mmiapi_ui_show_mmi_textbox_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id,screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]Exit TextBox"); */

    mmi_frm_get_active_scrn_id(&group_id,&screen_id);
    
	mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR);
	mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION);
 /*   DeleteScreenIfPresent(MMIAPI_SCREEN_TEXTBOX_EDITOR);   
    
    if (GetActiveScreenId() == MMIAPI_SCREEN_TEXTBOX_EDITOR ||
        GetActiveScreenId() == MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION)
    {
        GoBackHistory();
        //#ifdef __J2ME__
#if (defined(__J2ME__) && defined (__IJET_VM__))
        jvm_post_repaint_event();
#endif
    }
*/

    if(screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR || screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION)
    {
         mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR);
#if (defined(__J2ME__) && defined (__IJET_VM__))
         jvm_post_repaint_event();
#endif

    }
    else
    {
          mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_TEXTBOX_EDITOR);
    }
	msg->textbox_callback();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_terminate_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  mod_dest        [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_terminate_mmi_textbox_editor_req(module_type mod_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    mmiapi_ui_show_mmi_textbox_editor_rsp_struct *msg = NEW_LOCAL_PTR(mmiapi_ui_show_mmi_textbox_editor_rsp_struct);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]Terminate Java request"); */
	
    SEND_MESSAGE(MOD_MMI, mod_dest, MMI_J2ME_SAP, MSG_ID_MMIAPI_UI_TERMINATE_TEXTBOX_EDITOR_REQ, msg, NULL);
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_update_title_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_update_title_mmi_textbox_editor_req(mmiapi_ui_show_mmi_textbox_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]update title"); */
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_TEXTBOX_UPDATE_TITLE);
    mmiapi_ui_textbox_update_title((kal_uint8*) msg->title);
    msg->textbox_callback();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_update_ticker_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_update_ticker_mmi_textbox_editor_req(mmiapi_ui_show_mmi_textbox_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]update ticker"); */
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_TEXTBOX_UPDATE_TICKER);
    mmiapi_ui_textbox_update_ticker((kal_uint8*) msg->ticker);
    msg->textbox_callback();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_update_text_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_update_text_mmi_textbox_editor_req(mmiapi_ui_show_mmi_textbox_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]update text"); */
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_TEXTBOX_UPDATE_DATA);
    mmiapi_ui_textbox_update_text(msg->editor_buffer, msg->maxLen, msg->constraint, msg->is_editable);
    msg->textbox_callback();
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_update_commands_mmi_textbox_editor_req
* DESCRIPTION
*  
* PARAMETERS
*  msg         [?]         
*  mod_src     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_update_commands_mmi_textbox_editor_req(mmiapi_ui_show_mmi_textbox_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]update commands"); */
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_TEXTBOX_UPDATE_COMMAND);
    mmiapi_ui_textbox_update_commands(msg->menu_list, msg->menu_num, msg->menu_ids);
	
    msg->textbox_callback();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_update_text
* DESCRIPTION
*  
* PARAMETERS
*  text_buffer     [?]         
*  max_length      [IN]        
*  constraint      [IN]        
*  editable        [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_update_text(
										  kal_uint8 *text_buffer,
										  kal_int32 max_length,
										  kal_int32 constraint,
										  kal_bool editable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool editable_change = KAL_FALSE;
    //kal_bool display_option = KAL_FALSE;
    kal_uint8 * leftKeyStr = NULL;
    kal_uint8 * rightKeyStr = NULL;
    kal_uint16 index;
    kal_int16 i;
	
    MMI_ID group_id;
    MMI_ID screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_J2ME,"[MMIAPI]update text"); */
    if (mmiapi_textbox_editor_editable != editable)
        editable_change = KAL_TRUE;
    gdi_layer_lock_frame_buffer();
    for(index = 0;index<max_length*2;index++)
		mmiapi_textbox_editor_input_buffer[index] = text_buffer[index];
    mmiapi_textbox_editor_input_buffer[(max_length-1)*2] = 0;
	mmiapi_textbox_editor_input_buffer[(max_length-1)*2+1] = 0;
    //mmiapi_textbox_editor_input_buffer = text_buffer;
    mmiapi_textbox_editor_input_buffer_max_len = max_length;
	
    if(wgui_cat2002_is_vk_state())      //check vk,MAUI_02258397
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    if (constraint >= 0)
    {
		mmiapi_textbox_editor_input_type = (U32) constraint;
		mmiapi_textbox_editor_editable = editable;

        mmiapi_textbox_editor_disable_switch_IM = !mmiapi_textbox_editor_editable;
		
		
	}
    if( mmiapi_textbox_editor_is_endkey_pressed )
	{
		gdi_layer_unlock_frame_buffer();
        return;
	}
    
#if defined (__J2ME__) && defined(__IJET_VM__)
		if (jam_get_state() == JVM_LONG_EVENT_STATE)
		{
			gdi_layer_unlock_frame_buffer();
			return;
		}
#endif
    

    mmi_frm_get_active_scrn_id(&group_id,&screen_id);
    
	if (constraint >= 0)
    {
        if(editable_change)
        {
            mmiapi_textbox_editor_is_editor_updated = KAL_TRUE;    
        }
		if(screen_id != MMIAPI_SCREEN_TEXTBOX_EDITOR)
		{
			mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR);
			mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION);
		}
		
		if (screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION)
			mmi_frm_scrn_close_active_id();
        else
            mmiapi_textbox_editor_is_editor_updated = KAL_FALSE;

         /* customize key */
		mmiapi_textbox_editor_customize_key();  //after disppear option screen and then customize option
    
		if(screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR)
		{
			wgui_cat2002_change_input_type(mmiapi_textbox_editor_input_type, NULL);
			
			if (editable_change)
			{
				reset_softkey(MMI_LEFT_SOFTKEY);
				reset_softkey(MMI_RIGHT_SOFTKEY);
				
				if (editable)
				{
					wgui_cat2002_activate_editor(
						NULL,
						0,
						NULL,
						0,
						(U8*) mmiapi_textbox_editor_input_buffer,
						mmiapi_textbox_editor_input_buffer_max_len,
						mmiapi_textbox_editor_input_type,
						NULL);
				}
				else
				{
					wgui_cat2002_inactivate_editor(
						NULL,
						0,
						NULL,
						0,
						(UI_string_type) mmiapi_textbox_editor_input_buffer,
						mmiapi_textbox_editor_input_buffer_max_len);
					
				}

				if(mmiapi_textbox_editor_is_display_option())
                {
						//display_option = KAL_TRUE;
          	            //leftKeyStr = (U8*) get_string(STR_GLOBAL_OPTIONS);
                        //EnableCenterSoftkey(0,IMG_GLOBAL_OPTION_CSK);
                        ChangeCenterSoftkey(0,IMG_GLOBAL_OPTION_CSK);
						ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
						SetLeftSoftkeyFunction(mmiapi_goto_textbox_editor_option, KEY_EVENT_UP);
                        SetCenterSoftkeyFunction(mmiapi_goto_textbox_editor_option,KEY_EVENT_UP);

                }
                else
                {            
                    //display_option = KAL_FALSE;

                    if(mmiapi_textbox_editor_menu_num>0)
                    {
                        if(mmiapi_textbox_editor_option_list_ptr)
                        {
                            applib_mem_screen_free(mmiapi_textbox_editor_option_list_ptr);
                            mmiapi_textbox_editor_option_list_ptr = NULL;
                        }

                        mmiapi_textbox_editor_option_list_ptr = (U8 **) applib_mem_screen_alloc(mmiapi_textbox_editor_menu_num * sizeof(U8*));

                        for (i = 0; i < mmiapi_textbox_editor_menu_num; i++)
                        {
                            mmiapi_textbox_editor_option_list_ptr[i] = (U8 *)mmiapi_textbox_editor_menu_text_buffer[i];
                        }

                        //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
                        ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
                        //leftKeyStr = mmiapi_textbox_editor_option_list_ptr[0];
                        ChangeLeftSoftkeyByString((UI_string_type)mmiapi_textbox_editor_option_list_ptr[0], 0);
                        SetLeftSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
                        SetCenterSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
                        if(mmiapi_textbox_editor_menu_num == 2)
                        {
                            //rightKeyStr = mmiapi_textbox_editor_option_list_ptr[1];
                            ChangeRightSoftkeyByString((UI_string_type)mmiapi_textbox_editor_option_list_ptr[1],0);
                            SetRightSoftkeyFunction(mmiapi_textbox_rightkey_handler,KEY_EVENT_UP);
                        }   
                    }
                    else
                    {
                        ChangeCenterSoftkey(0,0);
                    }
                }

#ifdef __MMI_CLIPBOARD__ 
	      wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD); 
	            // //disabled clipboard
#endif /* __MMI_CLIPBOARD__ */

				/*if(display_option)
                {            
					SetLeftSoftkeyFunction(mmiapi_goto_textbox_editor_option, KEY_EVENT_UP);
                }
                else
                {
                    if(mmiapi_textbox_editor_menu_num>0)
                    {
                        SetLeftSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
                        if(mmiapi_textbox_editor_menu_num>1)
                        {
                            SetRightSoftkeyFunction(mmiapi_textbox_rightkey_handler,KEY_EVENT_UP);
                        } 
                    }
                }*/
				
				/* kal_prompt_trace(MOD_J2ME,"editable change"); */
			}
			
			if (mmiapi_textbox_editor_editable && 
		        ((mmiapi_textbox_editor_input_type & (~INPUT_TYPE_OVERRIDE_DEFAULT)) == IMM_INPUT_TYPE_PHONE_NUMBER))
            {
                RegisterInputBoxEmptyFunction(mmiapi_textbox_number_empty);
            }
			else
			{
				RegisterInputBoxEmptyFunction(NULL);
			}
		}
    }
	
    if (screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR)
	{
		wgui_cat2002_change_text(
			(UI_string_type) mmiapi_textbox_editor_input_buffer,
			mmiapi_textbox_editor_input_buffer_max_len,
			KAL_FALSE);
	}
    else
	{
		mmiapi_textbox_editor_is_data_updated = KAL_TRUE;
	}
	
    gdi_layer_unlock_frame_buffer();
	
    gdi_lcd_repaint_all();
    //gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_update_title
* DESCRIPTION
*  
* PARAMETERS
*  title       [?]     
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_update_title(kal_uint8 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id;
    MMI_ID screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiapi_textbox_editor_title = title;
	
    if( mmiapi_textbox_editor_is_endkey_pressed )
        return;

    mmi_frm_get_active_scrn_id(&group_id,&screen_id);
    
    /* update title data */
    if (screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR)
        wgui_cat2002_change_title((UI_string_type) mmiapi_textbox_editor_title, MMI_GET_TITLE_ICON);
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_update_ticker
* DESCRIPTION
*  
* PARAMETERS
*  ticker      [?]     
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_update_ticker(kal_uint8 *ticker)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL tickerChanged = KAL_FALSE;
	
    MMI_ID group_id;
    MMI_ID screen_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmiapi_textbox_editor_ticker != NULL && ticker == NULL) ||
        (mmiapi_textbox_editor_ticker == NULL && ticker != NULL))
        tickerChanged = KAL_TRUE;
	
    mmiapi_textbox_editor_ticker = ticker;
	
    if( mmiapi_textbox_editor_is_endkey_pressed )
        return;

    mmi_frm_get_active_scrn_id(&group_id,&screen_id);
    
    /* update ticker data */
    if (screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR)
        wgui_cat2002_change_ticker((UI_string_type) mmiapi_textbox_editor_ticker, tickerChanged);
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_update_commands
* DESCRIPTION
*  
* PARAMETERS
*  menu_list       [IN]        
*  menu_num        [IN]        
*  menu_ids        [?]         
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_textbox_update_commands(kal_uint16 **menu_list, kal_int32 menu_num, kal_int32 *menu_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 i, j;

    MMI_ID group_id;
    MMI_ID screen_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmiapi_ui_lcd_mutex_lock();



    if( mmiapi_textbox_editor_is_endkey_pressed )
	{
		mmiapi_ui_lcd_mutex_unlock();
        return;
	}

    mmi_frm_get_active_scrn_id(&group_id,&screen_id);
	
	gdi_layer_lock_frame_buffer();
	if( screen_id != MMIAPI_SCREEN_TEXTBOX_EDITOR)
	{
		mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR);
		mmi_ime_delete_editor_common_scr_with_sg(GRP_ID_JAVA_APP, MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION);
	}
	
    /* goback the main editor screen */
    if ( screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR_OPTION)
    {
        mmi_frm_scrn_close_active_id();
    }
	
	
	for( i = 0 ; i < MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM ; i ++)
	{
		mmiapi_textbox_editor_menu_id_buffer[i] = menu_ids[i];

	}
	for( i = 0 ; i < MMIAPI_TEXTBOX_MAX_MENU_ITEM_SUM && i < menu_num; i ++)
	{
		for( j = 0 ;j < MMIAPI_TEXTBOX_MAX_MENU_ITEM_LENGTH ; j ++)
		{
			mmiapi_textbox_editor_menu_text_buffer[i][j] = menu_list[i][j];
		}
	}
	mmiapi_textbox_editor_menu_num = menu_num;
    mmiapi_ui_textbox_reset_menus();
	
	
	if(screen_id == MMIAPI_SCREEN_TEXTBOX_EDITOR)
	{
		mmi_imc_reset_ime_state();
        if(mmiapi_textbox_editor_editable)
		    wgui_inputs_ml_set_RSK(); //added for MAUI_01911290
		else
            ChangeRightSoftkey(NULL, NULL); //MAUI_02126037,set right softkey is NULL

        if(mmiapi_textbox_editor_is_display_option())
        {
            //EnableCenterSoftkey(0,IMG_GLOBAL_OPTION_CSK);
            ChangeCenterSoftkey(0,IMG_GLOBAL_OPTION_CSK);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetLeftSoftkeyFunction(mmiapi_goto_textbox_editor_option, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmiapi_goto_textbox_editor_option,KEY_EVENT_UP);
        }
        else
        {

            if(mmiapi_textbox_editor_menu_num>0)
            {
                //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
                ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
                if(mmiapi_textbox_editor_option_list_ptr)
                {
                    applib_mem_screen_free(mmiapi_textbox_editor_option_list_ptr);
                    mmiapi_textbox_editor_option_list_ptr = NULL;
                }
                mmiapi_textbox_editor_option_list_ptr = (U8 **) applib_mem_screen_alloc(mmiapi_textbox_editor_menu_num * sizeof(U8*));
	
                for (i = 0; i < mmiapi_textbox_editor_menu_num; i++)
                {
                    mmiapi_textbox_editor_option_list_ptr[i] = (U8 *)mmiapi_textbox_editor_menu_text_buffer[i];
                }

                ChangeLeftSoftkeyByString((UI_string_type)mmiapi_textbox_editor_option_list_ptr[0], 0);
                SetLeftSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
                SetCenterSoftkeyFunction(mmiapi_textbox_leftkey_handler,KEY_EVENT_UP);
                if(mmiapi_textbox_editor_menu_num == 2)
                {
                    ChangeRightSoftkeyByString((UI_string_type)mmiapi_textbox_editor_option_list_ptr[1],0);
                    SetRightSoftkeyFunction(mmiapi_textbox_rightkey_handler,KEY_EVENT_UP);
                }
            }
            else
            {
                ChangeLeftSoftkeyByString(NULL, 0);
                SetLeftSoftkeyFunction(NULL,KEY_EVENT_UP);
                //ResetCenterSoftkey();
                ChangeCenterSoftkey(0,0);
            }    
        }
	}
	
	gdi_layer_unlock_frame_buffer();
	
    gdi_lcd_repaint_all();
	mmiapi_ui_lcd_mutex_unlock();
}	


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_textbox_option_highlight_handler
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_menu_option_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
        return;
	
    mmiapi_menu_index = index;
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_menu_leftkey_handler
* DESCRIPTION
*  
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_menu_leftkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close_active_id();
#if defined(__J2ME__) && defined(__IJET_VM__)
    //kal_trace(TRACE_STATE, FUNC_J2ME_JUI_SELECT_MENU_SHOW, mmiapi_menu_ids[mmiapi_menu_index],mmiapi_menu_index);
    jam_notify_vm();
    jvm_post_command_event(mmiapi_menu_ids[mmiapi_menu_index]);
#endif /*__IJET_VM__*/
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_menu_rightkey_handler
* DESCRIPTION
*  
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_menu_rightkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close_active_id();
#if defined(__J2ME__) && defined(__IJET_VM__)
    //kal_trace(TRACE_STATE, FUNC_J2ME_JUI_SELECT_MENU_SHOW, mmiapi_menu_ids[mmiapi_menu_index],mmiapi_menu_index);
    jam_notify_vm();
    jvm_post_command_event(-2);  // -2: dismiss menu
#endif /*__IJET_VM__*/
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_enter_mmi_menu_screen
* DESCRIPTION
*  
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_menu_endkey_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__J2ME__)
	jvm_end_key_handler();
#endif /*__J2ME__*/
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_exit_mmi_menu
* DESCRIPTION
*  
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_exit_mmi_menu()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmiapi_menu_icons_ptr)
    {
        applib_mem_screen_free(mmiapi_menu_icons_ptr);
        mmiapi_menu_icons_ptr = NULL;
    }
	
#if defined(__J2ME__) && defined(__IJET_VM__)
    jui_widget_exit_menu();
	jam_exit_fg_mmi_screen_callback(MMIAPI_SCREEN_SHOW_MENU, GetActiveScreenId(), NULL);
#endif /*__IJET_VM__*/
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_enter_mmi_menu_screen
* DESCRIPTION
*  
* PARAMETERS
*  void      
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_enter_mmi_menu_screen()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint16 i;
	kal_uint16 oldScreenId = GetActiveScreenId();
	
	    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_enter(GRP_ID_JAVA_APP,MMIAPI_SCREEN_SHOW_MENU, mmiapi_ui_exit_mmi_menu, NULL, MMI_FRM_FULL_SCRN);

    //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    
	mmiapi_menu_icons_ptr = (U8 **) applib_mem_screen_alloc(mmiapi_menu_num * sizeof(U8*));
    for (i = 0; i < mmiapi_menu_num; i++)
    {
        mmiapi_menu_icons_ptr[i] = (U8*) get_image(gIndexIconsImageList[i]);
    }
	
	RegisterHighlightHandler(mmiapi_ui_menu_option_highlight_handler);
	ShowCategory170Screen(
        (U8*) get_string(STR_GLOBAL_OPTIONS),
        (PU8) get_image(MMI_GET_TITLE_ICON),
        (U8*) get_string(STR_GLOBAL_OK),
        (U8*) get_image(IMG_GLOBAL_OK),
        (U8*) get_string(STR_GLOBAL_BACK),
        (U8*) get_image(IMG_GLOBAL_BACK),
        (S32) mmiapi_menu_num,
        (U8 **) mmiapi_menu_list,
        mmiapi_menu_icons_ptr,
        0,
        0,
        NULL);
    SetLeftSoftkeyFunction(mmiapi_ui_menu_leftkey_handler, KEY_EVENT_UP);
    SetKeyHandler(mmiapi_ui_menu_leftkey_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	
    SetRightSoftkeyFunction(mmiapi_ui_menu_rightkey_handler, KEY_EVENT_UP);
    SetKeyHandler(mmiapi_ui_menu_rightkey_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetCenterSoftkeyFunction(mmiapi_ui_menu_leftkey_handler,KEY_EVENT_UP);
	
#if defined(__J2ME__)
	SetKeyHandler(mmiapi_ui_menu_endkey_handler, KEY_END, KEY_EVENT_DOWN);
    jam_resume_fg_mmi_screen_callback( oldScreenId, MMIAPI_SCREEN_SHOW_MENU,MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA,MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA_MMI);
#endif /*__J2ME__*/
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_show_mmi_menu_req
* DESCRIPTION
*  
* PARAMETERS
*  msg       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_show_mmi_menu_req(mmiapi_ui_show_mmi_menu_req_struct * msg,module_type mod_src)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 nNumofItem;
    kal_bool displayInputMethod;
    kal_int32 menu_id_temp;
    kal_int16 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiapi_menu_list = msg->menu_list;
    mmiapi_menu_num = msg->menu_num;
    mmiapi_menu_ids = msg->menu_ids;
    mmiapi_menu_index  = 0;

#ifdef __J2ME__
    if(jam_is_own_screen())
    {
        mmiapi_ui_enter_mmi_menu_screen();
    }
#endif /* __J2ME__ */
	
    if(msg->textbox_callback)
		msg->textbox_callback();
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_hide_mmi_menu_req
* DESCRIPTION
*  
* PARAMETERS
*  msg       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_hide_mmi_menu_req(mmiapi_ui_show_mmi_menu_req_struct * msg,module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//DeleteScreenIfPresent(MMIAPI_SCREEN_SHOW_MENU);

	mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_SHOW_MENU);
	
	mmi_frm_get_active_scrn_id(&group_id,&screen_id);
	if(screen_id == MMIAPI_SCREEN_SHOW_MENU)
	{
		mmi_frm_scrn_close_active_id();
	}
	if(msg->textbox_callback)
		msg->textbox_callback();
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_ime_common_scr_entry_callback
* DESCRIPTION
*  
* PARAMETERS
*  screen_id       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_ime_common_scr_entry_callback(kal_uint16 old_scr_id,kal_uint16 new_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __J2ME__

    jam_resume_fg_mmi_screen_callback(old_scr_id,new_scr_id,mmiapi_ui_java_screen_type,MMIAPI_UI_JAVA_SCREEN_TYPE_JAVA_MMI);
#endif /* __J2ME__ */
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_ime_common_scr_exit_callback
* DESCRIPTION
*  
* PARAMETERS
*  screen_id       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_ime_common_scr_exit_callback(kal_uint16 old_scr_id,kal_uint16 new_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __J2ME__
    jam_exit_fg_mmi_screen_callback(old_scr_id,new_scr_id,NULL);
    if(!jam_is_enter_in_fg_mmi_screen_2(new_scr_id))
    {
        mmi_ime_register_editor_common_scr_entry_callback(NULL);
        mmi_ime_register_editor_common_scr_exit_callback(NULL);

        mmiapi_ui_java_screen_type = MMIAPI_UI_JAVA_SCREEN_TYPE_UNKNOWN;
    }
#endif /* __J2ME__*/
}

#ifdef __J2ME__
/*****************************************************************************
* FUNCTION
*  mmiapi_ui_show_mmi_datefield_date_req
* DESCRIPTION
*  
* PARAMETERS
    
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_show_mmi_datefield_date_req(mmiapi_ui_show_mmi_datefield_req_struct *msg, module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME myTime;
    S32 highlightCell, currCell = -1;
    S32 i;
    gui_calendar_cell_struct *startCell;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   mmiapi_ui_datefield_date_callback = msg->callback;

   memset(&g_mmiapi_ui_clndr_cntx->CalTime, 0, sizeof(MYTIME));
   g_mmiapi_ui_clndr_cntx->CalTime.nDay = msg->day;
   g_mmiapi_ui_clndr_cntx->CalTime.nMonth = msg->month +1;
   g_mmiapi_ui_clndr_cntx->CalTime.nYear = msg->year;
	
  
	mmiapi_ui_entry_datefield_date();
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_hide_mmi_datafield_date_req
* DESCRIPTION
*  
* PARAMETERS

* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_hide_mmi_datafield_date_req(
                mmiapi_ui_show_mmi_datefield_req_struct *msg,
                module_type mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id;
    MMI_ID screen_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//DeleteScreenIfPresent(MMIAPI_SCREEN_DATEFIELD_CALENDAR);

    mmi_frm_get_active_scrn_id( &group_id, &screen_id);
    
	mmi_frm_scrn_close(GRP_ID_JAVA_APP,MMIAPI_SCREEN_DATEFIELD_CALENDAR);
	if( screen_id == MMIAPI_SCREEN_DATEFIELD_CALENDAR)
	{
		mmi_frm_scrn_close_active_id();
	}
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_exit_clndr_screen
* DESCRIPTION
*  Exit function of calendar screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_exit_clndr_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmiapi_ui_clndr_cntx)
    {
        if (g_mmiapi_ui_clndr_cntx->Title != NULL)
        {
            mmi_frm_scrmem_free((void*)g_mmiapi_ui_clndr_cntx->Title);
            g_mmiapi_ui_clndr_cntx->Title = NULL;
        }
		
        if (g_mmiapi_ui_clndr_cntx->HorizonList[0] != NULL)
        {
            mmi_frm_scrmem_free((void*)g_mmiapi_ui_clndr_cntx->HorizonList[0]);
            g_mmiapi_ui_clndr_cntx->HorizonList[0] = NULL;
        }
		
        if (g_mmiapi_ui_clndr_cntx->VerticalList[0] != NULL)
        {
            mmi_frm_scrmem_free((void*)g_mmiapi_ui_clndr_cntx->VerticalList[0]);
            g_mmiapi_ui_clndr_cntx->VerticalList[0] = NULL;
        }
		
        if (g_mmiapi_ui_clndr_cntx->CalendarCell != NULL)
        {
            mmi_frm_scrmem_free((void*)g_mmiapi_ui_clndr_cntx->CalendarCell);
            g_mmiapi_ui_clndr_cntx->CalendarCell = NULL;
        }
		
    }
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_delete_datefield_date_callback
* DESCRIPTION
*  Enter function of calendar screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_delete_datefield_date_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmiapi_ui_exit_clndr_screen();

//	mmiapi_ui_clndr_cancel_handler(); //send cancel message to jam
	
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_entry_datefield_date
* DESCRIPTION
*  Enter function of calendar screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_entry_datefield_date()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME myTime;
    S32 highlightCell, currCell = -1;
    S32 i;
    gui_calendar_cell_struct *startCell;

    applib_time_struct max_time, min_time, highlight_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(GRP_ID_JAVA_APP,MMIAPI_SCREEN_DATEFIELD_CALENDAR,mmiapi_ui_exit_clndr_screen,mmiapi_ui_entry_datefield_date,MMI_FRM_FULL_SCRN);
    //SetDelScrnIDCallbackHandler(MMIAPI_SCREEN_DATEFIELD_CALENDAR, mmiapi_ui_delete_datefield_date_callback);

    //EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    
    g_mmiapi_ui_clndr_cntx->Title = mmi_frm_scrmem_alloc(MMIAPI_UI_CLNDR_TITLE_LEN * MMIAPI_UI_CLNDR_COLUMN);
    g_mmiapi_ui_clndr_cntx->HorizonList[0] =
        (U8*) mmi_frm_scrmem_alloc(MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * MMIAPI_UI_CLNDR_COLUMN);
    g_mmiapi_ui_clndr_cntx->VerticalList[0] =
        (U8*) mmi_frm_scrmem_alloc(MMIAPI_UI_CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * MMIAPI_UI_CLNDR_ROW);
	g_mmiapi_ui_clndr_cntx->RowNumber = MMIAPI_UI_CLNDR_ROW;
    g_mmiapi_ui_clndr_cntx->CalendarCell = mmi_frm_scrmem_alloc((g_mmiapi_ui_clndr_cntx->RowNumber * MMIAPI_UI_CLNDR_COLUMN) * MMIAPI_UI_CLNDR_CELL_SIZE);
	
    for (i = 1; i < MMIAPI_UI_CLNDR_COLUMN; i++)
    {
        g_mmiapi_ui_clndr_cntx->HorizonList[i] = g_mmiapi_ui_clndr_cntx->HorizonList[i - 1] + MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
    }
    for (i = 1; i < MMIAPI_UI_CLNDR_ROW; i++)
    {
        g_mmiapi_ui_clndr_cntx->VerticalList[i] =
            g_mmiapi_ui_clndr_cntx->VerticalList[i - 1] + MMIAPI_UI_CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
    }
	
	
    memset(g_mmiapi_ui_clndr_cntx->Title, 0, MMIAPI_UI_CLNDR_TITLE_LEN * MMIAPI_UI_CLNDR_COLUMN);
    memset(g_mmiapi_ui_clndr_cntx->HorizonList[0], 0, MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * MMIAPI_UI_CLNDR_COLUMN);
    memset(g_mmiapi_ui_clndr_cntx->VerticalList[0], 0, MMIAPI_UI_CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * MMIAPI_UI_CLNDR_ROW);
    memset(g_mmiapi_ui_clndr_cntx->CalendarCell, 0, g_mmiapi_ui_clndr_cntx->RowNumber * MMIAPI_UI_CLNDR_COLUMN * MMIAPI_UI_CLNDR_CELL_SIZE);
	
    mmiapi_ui_clndr_get_screenInfo();
	
	
	highlightCell = g_mmiapi_ui_clndr_cntx->DayOnFirst + g_mmiapi_ui_clndr_cntx->CalTime.nDay - 1;
	
	GetDateTime(&myTime);
	if (myTime.nMonth == g_mmiapi_ui_clndr_cntx->CalTime.nMonth && myTime.nYear == g_mmiapi_ui_clndr_cntx->CalTime.nYear)
	{
		currCell = g_mmiapi_ui_clndr_cntx->DayOnFirst + myTime.nDay - 1;
	}
	
	mmiapi_ui_clndr_monthly_set_content();
	
    wgui_cat83_register_highlight_change_callback(mmiapi_ui_clndr_highlight_change_handler);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat83_register_highlight_select_callback(mmiapi_ui_clndr_highlight_select_handler);
#endif 
	
    memset(&min_time, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));
    memset(&highlight_time, 0, sizeof(applib_time_struct));
    min_time.nYear = 0; /* MMIAPI_UI_CLNDR_START_YEAR*/;
    min_time.nMonth = 1;
    min_time.nDay = 1;
    max_time.nYear = MMIAPI_UI_CLNDR_END_YEAR;
    max_time.nMonth = 12;
    max_time.nDay = 31;
    highlight_time.nYear = g_mmiapi_ui_clndr_cntx->CalTime.nYear;
    highlight_time.nMonth = g_mmiapi_ui_clndr_cntx->CalTime.nMonth;
    highlight_time.nDay = g_mmiapi_ui_clndr_cntx->CalTime.nDay;
	
	ShowCategory83Screen(
#if !defined(__MMI_OP01_DM_PROFILE_SETTING__) || defined(__MMI_FTE_SUPPORT__)
		0,
#else
/* under construction !*/
#endif
        GUI_CALENDAR_TYPE_MONTH,
        max_time,
        min_time,
        highlight_time,//g_clndr_cntx->CalTime,
		KAL_TRUE,
		(U8*)GetString(STR_GLOBAL_OK),
		(U8*)GetString(STR_GLOBAL_CANCEL),
		NULL);    
	
    SetLeftSoftkeyFunction(mmiapi_ui_clndr_done_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmiapi_ui_clndr_cancel_handler, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmiapi_ui_clndr_done_handler,KEY_EVENT_UP);
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_done_handler
* DESCRIPTION
*  
* PARAMETERS

* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_done_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    mmiapi_ui_show_mmi_datefield_rsp_struct *msg = NEW_LOCAL_PTR(mmiapi_ui_show_mmi_datefield_rsp_struct);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->year = g_mmiapi_ui_clndr_cntx->CalTime.nYear;
    msg->month = g_mmiapi_ui_clndr_cntx->CalTime.nMonth - 1; 
    msg->day = g_mmiapi_ui_clndr_cntx->CalTime.nDay;
    msg->data_updated = KAL_TRUE;
    msg->callback = mmiapi_ui_datefield_date_callback;
	
    mmi_frm_scrn_close_active_id();

    SEND_MESSAGE(MOD_MMI, MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMIAPI_UI_TERMINATE_DATEFIELD_DATE_RSP, msg, NULL);


}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_cancel_handler
* DESCRIPTION
*  
* PARAMETERS

* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_cancel_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    mmiapi_ui_show_mmi_datefield_rsp_struct *msg = NEW_LOCAL_PTR(mmiapi_ui_show_mmi_datefield_rsp_struct);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
      msg->year = g_mmiapi_ui_clndr_cntx->CalTime.nYear;
    msg->month = g_mmiapi_ui_clndr_cntx->CalTime.nMonth; 
    msg->day = g_mmiapi_ui_clndr_cntx->CalTime.nDay;
    msg->data_updated = KAL_FALSE;
    msg->callback = mmiapi_ui_datefield_date_callback;
	
    SEND_MESSAGE(MOD_MMI, MOD_JAM, MMI_J2ME_SAP, MSG_ID_MMIAPI_UI_TERMINATE_DATEFIELD_DATE_RSP, msg, NULL);

    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_get_date_str
* DESCRIPTION
*  
* PARAMETERS
*  date        [?]     [?]
*  dateStr     [?]     [?]
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_get_date_str(MYTIME *date, U8 *dateStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_str[MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE];
    S8 unicode_str[MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE * ENCODING_LENGTH];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&ascii_str, 0, MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE);
    memset(&unicode_str, 0, MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE * ENCODING_LENGTH);
	
    /* year */
    sprintf(ascii_str, "%d", date->nYear);
    mmi_asc_to_ucs2(unicode_str, ascii_str);
    mmi_ucs2ncpy((S8*) dateStr, unicode_str, MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE);
    mmi_ucs2cat((S8*) dateStr, (PS8) L"/");
	
    /* month */
    if (date->nMonth < 10)
    {
        mmi_ucs2cat((S8*) dateStr, (PS8) L"0");
    }
    sprintf(ascii_str, "%d", date->nMonth);
    mmi_asc_to_ucs2(unicode_str, ascii_str);
    mmi_ucs2ncat((S8*) dateStr, unicode_str, MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE);
    mmi_ucs2cat((S8*) dateStr, (PS8) L"/");
	
    /* day */
    if (date->nDay < 10)
    {
        mmi_ucs2cat((S8*) dateStr, (PS8) L"0");
    }
    sprintf(ascii_str, "%d", date->nDay);
    mmi_asc_to_ucs2(unicode_str, ascii_str);
    mmi_ucs2ncat((S8*) dateStr, unicode_str, MMIAPI_UI_CLNDR_MAX_YEAR_BUF_SIZE);
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_get_weekday
* DESCRIPTION
*  
* PARAMETERS
*  weekdayStr      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_get_weekday(U8 **weekdayStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMIAPI_UI_CLNDR_START_WEEKDAY; i < MMIAPI_UI_CLNDR_TOTAL_WEEKDAY; i++)
    {
        mmi_asc_n_to_ucs2((S8*)weekdayStr[i], (S8*)&mmiapi_ui_clndr_weekday[i], 1);
    }
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_get_week_numbers
* DESCRIPTION
*  
* PARAMETERS
*  year        [IN]        
*  month       [IN]        
*  weekStr     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_get_week_numbers(U16 year, U8 month, U8 **weekStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME dt;
    U8 week, i;
    S8 asciiStr[MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN], unicodeStr[MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&dt, 0, sizeof(MYTIME));
    memset(&asciiStr, 0, MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN);
    memset(&unicodeStr, 0, MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH);
	
    dt.nYear = year;
    dt.nMonth = month;
    dt.nDay = 1;
	
    /* get the week number of first day of the month */
    week = applib_dt_get_week_number((applib_time_struct*) & dt);
	
    for (i = 0; i < MMIAPI_UI_CLNDR_ROW; i++, week++)
    {
        sprintf(asciiStr, "%d", week);
		
        /* assert if the string of week number is longer than  */
        ASSERT(strlen(asciiStr) < MMIAPI_UI_CLNDR_HORIZON_LIST_CELL_LEN - MMIAPI_UI_CLNDR_WEEK_SYMBOL_LEN);
		
        mmi_asc_to_ucs2(unicodeStr, asciiStr);
#ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
        mmi_ucs2ncpy((S8*) weekStr[i], GetString((U16) /*STR_GLSTR_CLNDR_WEEK_SYMBOL*/0), MMIAPI_UI_CLNDR_WEEK_SYMBOL_LEN);
        mmi_ucs2ncat((S8*) weekStr[i], unicodeStr, strlen(asciiStr));
#else
        mmi_ucs2ncpy((S8*) weekStr[i], unicodeStr, strlen(asciiStr));
#endif        
		
    }
	
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_util_num_to_unicode
* DESCRIPTION
*  
* PARAMETERS
*  num     [IN]        
*  str     [?]         [?]
*  len     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii[CLNDR_TITLE_LEN];
    U16 value = (U16) num;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ascii, 0, CLNDR_TITLE_LEN);
    sprintf(ascii, "%d", value);
	
    /* ASSERT(strlen(ascii) < len); */
	
    mmi_asc_to_ucs2((S8*) str, ascii);
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_construct_monthly_cell_info
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_construct_monthly_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, taskPos, nextMonthBoundary;
    gui_calendar_cell_struct *cell;
    MYTIME preMonth, incTime, currTime;
    U8 lastDayofPreMonth;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&preMonth, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&currTime, 0, sizeof(MYTIME));
	
    incTime.nMonth = 1;
    applib_dt_decrease_time(
        (applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & preMonth);
    lastDayofPreMonth = applib_dt_last_day_of_mon(preMonth.nMonth, preMonth.nYear);
	
    cell = g_mmiapi_ui_clndr_cntx->CalendarCell + (g_mmiapi_ui_clndr_cntx->DayOnFirst);
	
    /* last month */
    for (i = g_mmiapi_ui_clndr_cntx->DayOnFirst - 1; i >= 0; i--)
    {
        cell--;
        cell->flags = GUI_CALENDAR_CELL_INVALID;
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        lastDayofPreMonth--;
    }
	
    /* this month */
    taskPos = 1;
	
    cell = g_mmiapi_ui_clndr_cntx->CalendarCell + g_mmiapi_ui_clndr_cntx->DayOnFirst;
	
    for (i = 1; i <= g_mmiapi_ui_clndr_cntx->NumDaysInMonth; i++)
    {
        cell->bg_index = cell->bg_index = GUI_CALENDAR_COLOR_NONE;
		
        cell->flags = GUI_CALENDAR_CELL_VALID;
        cell++;
    }
	
    /* next month */
    nextMonthBoundary = MMIAPI_UI_CLNDR_ROW * MMIAPI_UI_CLNDR_COLUMN - (g_mmiapi_ui_clndr_cntx->DayOnFirst + g_mmiapi_ui_clndr_cntx->NumDaysInMonth);
    for (i = 1; i <= nextMonthBoundary; i++)
    {
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        cell->flags = GUI_CALENDAR_CELL_INVALID;
        cell++;
    }
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_get_screenInfo
* DESCRIPTION
*  Get screen display information of.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmiapi_ui_clndr_get_screenInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the DOW 1st of todays month */
    g_mmiapi_ui_clndr_cntx->DayOnFirst = DOW(g_mmiapi_ui_clndr_cntx->CalTime.nYear, g_mmiapi_ui_clndr_cntx->CalTime.nMonth, 1);
	
    /* get the num of days in todays month */
    g_mmiapi_ui_clndr_cntx->NumDaysInMonth = LastDayOfMonth(g_mmiapi_ui_clndr_cntx->CalTime.nMonth, g_mmiapi_ui_clndr_cntx->CalTime.nYear);
	
    mmiapi_ui_clndr_get_date_str(&(g_mmiapi_ui_clndr_cntx->CalTime), g_mmiapi_ui_clndr_cntx->Title);
	
    mmiapi_ui_clndr_get_weekday(g_mmiapi_ui_clndr_cntx->HorizonList);
    mmiapi_ui_clndr_get_week_numbers(
		g_mmiapi_ui_clndr_cntx->CalTime.nYear,
		g_mmiapi_ui_clndr_cntx->CalTime.nMonth,
		g_mmiapi_ui_clndr_cntx->VerticalList);
	mmiapi_ui_clndr_construct_monthly_cell_info();
}

/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_monthly_highlight
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_monthly_highlight(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 totaldays;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totaldays = (row * MMIAPI_UI_CLNDR_COLUMN) + column + 1;
    g_mmiapi_ui_clndr_cntx->CalTime.nDay = totaldays - g_mmiapi_ui_clndr_cntx->DayOnFirst;
    g_mmiapi_ui_clndr_cntx->CalTime.DayIndex = DOW(g_mmiapi_ui_clndr_cntx->CalTime.nYear, g_mmiapi_ui_clndr_cntx->CalTime.nMonth, g_mmiapi_ui_clndr_cntx->CalTime.nDay);
	
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_monthly_compute_next_time
* DESCRIPTION
*  
* PARAMETERS
*  arrow       [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_monthly_compute_next_time(U32 arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME resultDate, incTime;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&resultDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
	
    switch (arrow)
    {
	case MMIAPI_UI_CLNDR_KEY_UP:
		incTime.nDay = MMIAPI_UI_CLNDR_TOTAL_WEEKDAY;
		applib_dt_decrease_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultDate);
		break;
	case MMIAPI_UI_CLNDR_KEY_DOWN:
		incTime.nDay = MMIAPI_UI_CLNDR_TOTAL_WEEKDAY;
		applib_dt_increase_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultDate);
		break;
	case MMIAPI_UI_CLNDR_KEY_LEFT:
		incTime.nDay = 1;
		applib_dt_decrease_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultDate);
		break;
	case MMIAPI_UI_CLNDR_KEY_RIGHT:
		incTime.nDay = 1;
		applib_dt_increase_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultDate);
		break;
	default:
		break;
    }
	
    return mmiapi_ui_clndr_monthly_out_of_boundary(&resultDate);
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_monthly_out_of_boundary
* DESCRIPTION
*  
* PARAMETERS
*  resultDate      [?]     
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_monthly_out_of_boundary(MYTIME *resultDate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;
    U32 highlightDays, highlightX, highlightY;
    S32 currCell = -1;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (resultDate->nYear > MMIAPI_UI_CLNDR_END_YEAR || resultDate->nYear < MMIAPI_UI_CLNDR_START_YEAR)
    {
        return MMI_FALSE;
    }
        
    g_mmiapi_ui_clndr_cntx->DayOnFirst = DOW(resultDate->nYear, resultDate->nMonth, 1);
	
    /* set highlight and current date */
    /* subtract 1 to compute the correct highlight position */
    highlightDays = g_mmiapi_ui_clndr_cntx->DayOnFirst + resultDate->nDay - 1;
    highlightX = highlightDays % MMIAPI_UI_CLNDR_TOTAL_WEEKDAY;
    highlightY = highlightDays / MMIAPI_UI_CLNDR_TOTAL_WEEKDAY;
	
    /* move to next/previous month */
    if (g_mmiapi_ui_clndr_cntx->CalTime.nMonth != resultDate->nMonth || g_mmiapi_ui_clndr_cntx->CalTime.nYear != resultDate->nYear)
    {
        memcpy(&g_mmiapi_ui_clndr_cntx->CalTime, resultDate, sizeof(MYTIME));
		
        /* get calendar information */
        //memset(g_mmiapi_ui_clndr_cntx->TaskDayList, 0, MMIAPI_UI_CLNDR_COLUMN * MMIAPI_UI_CLNDR_ROW * sizeof(clndr_task_icon_struct));
        g_mmiapi_ui_clndr_cntx->NumDaysInMonth = LastDayOfMonth(g_mmiapi_ui_clndr_cntx->CalTime.nMonth, g_mmiapi_ui_clndr_cntx->CalTime.nYear);
		
        mmiapi_ui_clndr_get_date_str(&(g_mmiapi_ui_clndr_cntx->CalTime), g_mmiapi_ui_clndr_cntx->Title);
        mmiapi_ui_clndr_get_weekday(g_mmiapi_ui_clndr_cntx->HorizonList);
        mmiapi_ui_clndr_get_week_numbers(
            g_mmiapi_ui_clndr_cntx->CalTime.nYear,
            g_mmiapi_ui_clndr_cntx->CalTime.nMonth,
            g_mmiapi_ui_clndr_cntx->VerticalList);
		
        /* Set current date */
        GetDateTime(&currTime);
        if (currTime.nMonth == g_mmiapi_ui_clndr_cntx->CalTime.nMonth && currTime.nYear == g_mmiapi_ui_clndr_cntx->CalTime.nYear)
        {
            currCell = g_mmiapi_ui_clndr_cntx->DayOnFirst + currTime.nDay - 1;
        }
		
        /* construct cell info */
        memset(g_mmiapi_ui_clndr_cntx->CalendarCell, 0, g_mmiapi_ui_clndr_cntx->RowNumber * MMIAPI_UI_CLNDR_COLUMN * MMIAPI_UI_CLNDR_CELL_SIZE);
        mmiapi_ui_clndr_construct_monthly_cell_info();
		
        mmiapi_ui_clndr_monthly_set_content();
        /* ClndrGetScreenInfo(); */
        return MMI_TRUE;
    }
    else
    {
        /* return MMI_FALSE; */
        return MMI_TRUE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_left_out_of_boundary
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_left_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	return mmiapi_ui_clndr_monthly_compute_next_time(MMIAPI_UI_CLNDR_KEY_LEFT);
	/* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_LEFT, row, column); */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_right_out_of_boundary
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_right_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    return mmiapi_ui_clndr_monthly_compute_next_time(MMIAPI_UI_CLNDR_KEY_RIGHT);
	/* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_RIGHT, row, column); */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_up_out_of_boundary
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_up_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	return mmiapi_ui_clndr_monthly_compute_next_time(MMIAPI_UI_CLNDR_KEY_UP);
	/* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_UP, row, column); */
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_down_out_of_boundary
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_down_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    return mmiapi_ui_clndr_monthly_compute_next_time(MMIAPI_UI_CLNDR_KEY_DOWN);
	/* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_DOWN, row, column); */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_up_side_key
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_up_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_ui_clndr_monthly_movement(MMIAPI_UI_CLNDR_PRIVOUS_MONTH);
    /* return MMI_TRUE; */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_down_side_key
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_down_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_ui_clndr_monthly_movement(MMIAPI_UI_CLNDR_NEXT_MONTH);
    /* return MMI_TRUE; */
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_touch_year_increase
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_touch_year_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_ui_clndr_monthly_movement(MMIAPI_UI_CLNDR_NEXT_YEAR);
    /* return MMI_TRUE; */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_touch_year_decrease
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_touch_year_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_ui_clndr_monthly_movement(MMIAPI_UI_CLNDR_PRIVOUS_YEAR);
    /* return MMI_TRUE; */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_touch_month_increase
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_touch_month_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_ui_clndr_monthly_movement(MMIAPI_UI_CLNDR_NEXT_MONTH);
    /* return MMI_TRUE; */
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_touch_month_decrease
* DESCRIPTION
*  
* PARAMETERS
*  row         [IN]        
*  column      [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_touch_month_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmiapi_ui_clndr_monthly_movement(MMIAPI_UI_CLNDR_PRIVOUS_MONTH);
    /* return MMI_TRUE; */
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/* void mmi_clndr_monthly_movement(CLNDR_CLNDAR_MOVEMENT_ENUM type) */


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_monthly_movement
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
* RETURNS
*  
*****************************************************************************/
static MMI_BOOL mmiapi_ui_clndr_monthly_movement(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime, resultTime;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&resultTime, 0, sizeof(MYTIME));
	
    switch (type)
    {
	case MMIAPI_UI_CLNDR_PRIVOUS_MONTH:
		incTime.nMonth = 1;
		applib_dt_decrease_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultTime);
		break;
		
	case MMIAPI_UI_CLNDR_NEXT_MONTH:
		incTime.nMonth = 1;
		applib_dt_increase_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultTime);
		break;
#ifdef __MMI_TOUCH_SCREEN__
	case MMIAPI_UI_CLNDR_PRIVOUS_YEAR:
		incTime.nYear = 1;
		applib_dt_decrease_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultTime);
		break;
		
	case MMIAPI_UI_CLNDR_NEXT_YEAR:
		incTime.nYear = 1;
		applib_dt_increase_time(
			(applib_time_struct*) & (g_mmiapi_ui_clndr_cntx->CalTime),
			(applib_time_struct*) & incTime,
			(applib_time_struct*) & resultTime);
		break;
#endif /* __MMI_TOUCH_SCREEN__ */ 
	default:
		ASSERT(0);
    }
    resultTime.nDay = 1;
	
    return mmiapi_ui_clndr_monthly_out_of_boundary(&resultTime);
	
}


/*****************************************************************************
* FUNCTION
*  mmiapi_ui_clndr_monthly_set_content
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmiapi_ui_clndr_monthly_set_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(g_mmiapi_ui_clndr_cntx->horizon_select1, 0, MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN);
	memset(g_mmiapi_ui_clndr_cntx->horizon_select2, 0, MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN);
	
//#if defined (__MMI_CALENDAR__)
	mmiapi_ui_clndr_util_num_to_unicode(
		g_mmiapi_ui_clndr_cntx->CalTime.nYear,
		g_mmiapi_ui_clndr_cntx->horizon_select1,
		MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN);
	mmiapi_ui_clndr_util_num_to_unicode(
		g_mmiapi_ui_clndr_cntx->CalTime.nMonth,
		g_mmiapi_ui_clndr_cntx->horizon_select2,
		MMIAPI_UI_CLNDR_VERTICAL_SELECT_LEN);
	
	
    
//#endif /*__MMI_CALENDAR__ */
}
#endif /* __J2ME__ */

