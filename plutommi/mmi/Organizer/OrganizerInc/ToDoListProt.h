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
 * ToDoListProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes used in todolist application.
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef TODOLISTPROT_H
#define TODOLISTPROT_H

#include "MMI_features.h"

#if defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)

/******************************************************************************* 
 * Include 
 *******************************************************************************/
 
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_touch_screen.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "TodolistSrvGprot.h"
#include "Mmi_frm_history_gprot.h"
#include "TodolistGprot.h"
#include "CalendarGprot.h"
#ifndef __RESOURCE_GEN_
#include "inlinecuiGprot.h"
#endif
#if defined(__MMI_TODOLIST__)
	#ifndef __MMI_TODO_SEARCH__
	#define __MMI_TODO_SEARCH__
	#endif
#endif
/******************************************************************************* 
 * Define 
 *******************************************************************************/
#define MMI_TDL_INVALID_INDEX                   (0xFF)
#define MMI_TDL_MAX_DEL_NUM                     (3)

#define MMI_TDL_MAX_YEAR_SIZE                   (5)
#define MMI_TDL_MAX_MONTH_SIZE                  (3)
#define MMI_TDL_MAX_DAY_SIZE                    (3)
#define MMI_TDL_MAX_DOW_SIZE                    (3)
#define MMI_TDL_MAX_HOUR_SIZE                   (3)
#define MMI_TDL_MAX_MIN_SIZE                    (3)
#define MMI_TDL_MAX_DATE_BUFF_SIZE              (MMI_TDL_MAX_YEAR_SIZE + MMI_TDL_MAX_MONTH_SIZE + MMI_TDL_MAX_DAY_SIZE + 1)
#define MMI_TDL_MAX_TIME_BUFF_SIZE              (MMI_TDL_MAX_HOUR_SIZE + MMI_TDL_MAX_MIN_SIZE + 1)
#define MMI_TDL_MAX_TITLE_BUF_SIZE              (25)

#define MMI_TDL_MAX_DAYS_PER_MONTH              (31)
#define MMI_TDL_MAX_DAYS_PER_WEEK               (7)

/* Num of description edit templates */
#define MMI_TDL_MAX_NOTE_TEMPLATE_ITEM          (10)
/* Num of task type */
#define MMI_TDL_MAX_TASK_TYPE                   (3)

/* Defines for edit context*/
#ifdef __MMI_INDICAL__
#define MMI_TDL_MAX_FREQ_ITEM                   (7)
#else
#define MMI_TDL_MAX_FREQ_ITEM                   (6)        /* Once, Weekly, Monthly, Dayly, Days*/
#endif /* __MMI_INDICAL__ */
#define MMI_TDL_MAX_PRIORITY                    (3)
#define MMI_TDL_MAX_STATUS_NUM                  (2)
#define MMI_TDL_MAX_INLINE_ITEM                 (30)
#define MMI_TDL_MAX_EVENT1_INLINE_ITEM          (20)
#define MMI_TDL_MAX_EVENT2_INLINE_ITEM          (11)
#define MMI_TDL_MAX_EVENT3_INLINE_ITEM          (2)
#define MMI_TDL_MAX_TASK_INLINE_ITEM            (15)
#define MMI_TDL_MAX_INLINE_STRING_LEN           (36)



/* The pre-alarm time in second */
#ifdef SUPPORT_JSR_75_PIM
#define MMI_TDL_MAX_PRE_REMINDER_SEC            (43200)    /* If java support, 12hours max support */
#else /* SUPPORT_JSR_75_PIM */
#define MMI_TDL_MAX_PRE_REMINDER_SEC            (2678400)  /* If java not support, 1month max support */
#endif /* SUPPORT_JSR_75_PIM */

/* 
 * 04/03/12 Thu
 * This is required because in Bulgairan the maximum length of day is 20 
 */
#define MMI_TDL_MAX_DATE_EN_LEN                 (21 * ENCODING_LENGTH)

/* 12:12 - 13:15 */
#define MMI_TDL_MAX_TIME_EN_LEN                 (14 * ENCODING_LENGTH)
#define MMI_TDL_MAX_DATE_STRING_LEN             (10)  /* YYYY/MM/DD */
#define MMI_TDL_MAX_TIME_STRING_LEN             (5)   /* HH:MM */

/* Show popup screen */
#define MMI_TDL_MAX_OUT_PUT_MSG_SIZE                 (50)

#define MMI_TDL_MAX_NOTE_EN_LEN                      (MAX_TODO_NOTE_LEN * ENCODING_LENGTH)
#define MMI_TDL_MAX_REMINDER_PREFIX_EN_LEN           (80 * ENCODING_LENGTH)
#define MMI_TDL_MAX_DATE_FORMAT_BUFF_EN_SIZE         (32 * ENCODING_LENGTH)
#define MMI_TDL_MAX_TIME_FORMAT_BUFF_EN_SIZE         (32 * ENCODING_LENGTH)
#define MMI_TDL_MAX_TEXT_EDIT_BUFF_EN_SIZE           (MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH)

#define MMI_TDL_MAX_REMINDER_NOTE_EN_SIZE     \
    (MMI_TDL_MAX_NOTE_EN_LEN + MMI_TDL_MAX_REMINDER_PREFIX_EN_LEN + MAX_TDL_LOCATION_LEN + \
     MMI_TDL_MAX_TEXT_EDIT_BUFF_EN_SIZE + MMI_TDL_MAX_DATE_FORMAT_BUFF_EN_SIZE + MMI_TDL_MAX_TIME_FORMAT_BUFF_EN_SIZE)

#define  MMI_TDL_START_YEAR_SUPPORT            (1970) 
#define  MMI_TDL_END_YEAR_SUPPORT              (2030)

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 
#endif 

#define MMI_TDL_REMINDER_INTERVAL               4
#define MMI_TDL_REMINDER_DURATION               30000



/******************************************************************************* 
 * Typedef 
 *******************************************************************************/

/* To be removed */
typedef struct
{
    MYTIME from_time;
    MYTIME to_time;
}clndr_delete_spec_time_struct;

typedef enum
{
    MMI_TDL_VIEW_MONTHLY = 1,
    MMI_TDL_VIEW_WEEKLY,
    MMI_TDL_VIEW_TOTAL
}mmi_tdl_view_mode_enum;

typedef enum
{
    TODO_LIST_TASK_OPTION_VIEW,
    TODO_LIST_TASK_OPTION_ADD,
    TODO_LIST_TASK_OPTION_EDIT,
    TODO_LIST_TASK_OPTION_DELETE,
    TODO_LIST_TASK_OPTION_DELETE_OVERDUE,
    TODO_LIST_TASK_OPTION_DELETE_ALL,
    TODO_LIST_TASK_OPTION_JUMP_TO_DATE,
    TODO_LIST_TASK_OPTION_VIEW_UNDONE,
#if defined(__MMI_VCALENDAR__)
    TODO_FROM_FMGR,
    TODO_FROM_NETWORK,
    TODO_FROM_APP,
#endif /* defined(__MMI_VCALENDAR__) */ 
    TODO_LIST_OPTION_TOTAL
} TDL_OPTION_ENUM;

typedef enum{
	MMI_TDL_VCAL_TYPE_VEVENT,
	MMI_TDL_VCAL_TYPE_VTODO,
	MMI_TDL_VCAL_TYPE_TOTAL
}MMI_TDL_VCAL_TYPE_ENUM;

typedef enum{
	MMI_TDL_ASYNC_ALL,
	MMI_TDL_ASYNC_DAILY,
	MMI_TDL_ASYNC_SUB,
	MMI_TDL_ASYNC_TYPE_TOTAL
}MMI_TDL_LIST_TYPE_ENUM;

typedef enum
{
	TDL_MENU_OPTION1_VIEW,
	TDL_MENU_OPTION1_ADD,
	TDL_MENU_OPTION1_EDIT,
	TDL_MENU_OPTION1_SEARCH,
	TDL_MENU_OPTION1_DEL,
    TDL_MENU_OPTION1_DEL_OVERDUE,
	TDL_MENU_OPTION1_DEL_ALL,
    TDL_MENU_OPTION1_JUMP_TO_DATE,
    TDL_MENU_OPTION1_VIEW_UNDONE,
#ifdef __MMI_VCALENDAR__
	TDL_MENU_OPTION1_FORWARD,
#endif
#ifdef __MMI_FILE_MANAGER__
    TDL_MENU_OPTION1_SEND_BY_FILEMGR,
#endif
	TDL_MENU_OPTION1_TOTAL
}mmi_tdl_menu_option1_enum;

typedef enum
{
	TDL_MENU_OPTION2_VIEW,
	TDL_MENU_OPTION2_EDIT,
	TDL_MENU_OPTION2_SEARCH,
	TDL_MENU_OPTION2_DEL,
    TDL_MENU_OPTION2_DEL_OVERDUE,
	TDL_MENU_OPTION2_DEL_ALL,
    TDL_MENU_OPTION2_JUMP_TO_DATE,
    TDL_MENU_OPTION2_VIEW_UNDONE,
#ifdef __MMI_VCALENDAR__
	TDL_MENU_OPTION2_FORWARD,
#endif
#ifdef __MMI_FILE_MANAGER__
    TDL_MENU_OPTION2_SEND_BY_FILEMGR,
#endif
	TDL_MENU_OPTION2_TOTAL
}mmi_tdl_menu_option2_enum;

typedef enum
{
	TDL_MENU_OPTION_SEARCH_VIEW,
	TDL_MENU_OPTION_SEARCH_EDIT,
	TDL_MENU_OPTION_SEARCH_DEL,
	TDL_MENU_OPTION_SEARCH_DEL_ALL,
#ifdef __MMI_VCALENDAR__
	TDL_MENU_OPTION_SEARCH_FORWARD,
#endif
#ifdef __MMI_FILE_MANAGER__
    TDL_MENU_OPTION_SEARCH_SEND_BY_FILEMGR,
#endif
	TDL_MENU_OPTION_SEARCH_TOTAL
}mmi_tdl_menu_option_search_enum;

typedef enum
{
	TDL_MENU_OPTION_GOTO_VIEW,
	TDL_MENU_OPTION_GOTO_EDIT,
	TDL_MENU_OPTION_GOTO_DEL,
	TDL_MENU_OPTION_GOTO_DEL_ALL,
    TDL_MENU_OPTION_GOTO_DATE,
#ifdef __MMI_VCALENDAR__
	TDL_MENU_OPTION_GOTO_FORWARD,
#endif
#ifdef __MMI_FILE_MANAGER__
    TDL_MENU_OPTION_GOTO_SEND_BY_FILEMGR,
#endif
	TDL_MENU_OPTION_GOTO_TOTAL
}mmi_tdl_menu_option_goto_enum;

typedef enum
{
	TDL_MENU_OPTION_VEVENT_VIEW,
	TDL_MENU_OPTION_VEVENT_ADD,
	TDL_MENU_OPTION_VEVENT_EDIT,
	TDL_MENU_OPTION1_VEVENT_SEARCH,
	TDL_MENU_OPTION_VEVENT_DEL,
#ifdef __MMI_VCALENDAR__
	TDL_MENU_OPTION_VEVENT_FORWARD,
#endif
#ifdef __MMI_FILE_MANAGER__
    TDL_MENU_OPTION_VEVENT_SEND_BY_FILEMGR,
#endif
	TDL_MENU_OPTION_VEVENT_TOTAL
}mmi_tdl_menu_option_vevent_enum;

typedef enum
{
	TDL_MENU_OPTION_VIEW_UNDONE_VIEW,
	TDL_MENU_OPTION_VIEW_UNDONE_EDIT,
	TDL_MENU_OPTION_VIEW_UNDONE_DEL,
	TDL_MENU_OPTION_VIEW_UNDONE_DEL_ALL,
#ifdef __MMI_VCALENDAR__
	TDL_MENU_OPTION_VIEW_UNDONE_FORWARD,
#endif
#ifdef __MMI_FILE_MANAGER__
    TDL_MENU_OPTION_VIEW_SEND_BY_FILEMGR,
#endif
	TDL_MENU_OPTION_VIEW_UNDONE_TOTAL
}mmi_tdl_menu_option_view_undone_enum;

#ifdef __MMI_TODOLIST__
typedef enum
{
    CUI_INLINE_ITEM_SUBJECT_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    CUI_INLINE_ITEM_SUBJECT_TEXT,
    CUI_INLINE_ITEM_PRIORITY_CAPTION,
    CUI_INLINE_ITEM_PRIORITY_TEXT,
    CUI_INLINE_ITEM_DUETIME_CAPTION,
    CUI_INLINE_ITEM_DUEDATE_TEXT,
    CUI_INLINE_ITEM_DUETIME_TEXT,
    CUI_INLINE_ITEM_ALARM_CAPTION,
    CUI_INLINE_ITEM_ALARM_TEXT,
    CUI_INLINE_ITEM_REPEAT_CAPTION,
    CUI_INLINE_ITEM_REPEAT_TEXT,
    CUI_INLINE_ITEM_DETAILS_CAPTION,
    CUI_INLINE_ITEM_DETAILS_TEXT,
    CUI_INLINE_ITEM_STATUS_CAPTION,
    CUI_INLINE_ITEM_STATUS_TEXT,
    CUI_INLINE_ITEM_TOTAL = CUI_INLINE_ITEM_STATUS_TEXT - CUI_INLINE_ITEM_ID_BASE + 1,
}mmi_tdl_cui_item_enum;
#endif


typedef struct
{
    U8 alarm_type;
    U16 str_id;   
}mmi_tdl_alarm_type_struct;

 typedef struct
{
    U8 repeat_type;
    U16 str_id;   
}mmi_tdl_repeat_type_struct;


typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
}mmi_tdl_common_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_cal_save_gid;
    mmi_id cui_tdl_save_gid;
}mmi_tdl_main_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_cal_save_gid;
    mmi_id cui_tdl_save_gid;
    mmi_id cui_inline_gid;
    mmi_id fseditor_gid;
}mmi_tdl_search_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_cal_save_gid;
    mmi_id cui_tdl_save_gid;
    mmi_id cui_inline_gid;
}mmi_tdl_jump_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_inline_gid;
}mmi_tdl_view_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_cal_save_gid;
    mmi_id cui_tdl_save_gid;
}mmi_tdl_hs_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
	U8 source_id;
    U8 repeat_index;
    U8 dow_state[MMI_TDL_MAX_DAYS_PER_WEEK];
    U8 priority_index;
    U8 status_index;
    U8 category_index;
    U8 alarm_index;
    U8 operation_type;
    U16 title_id;
    U16 *subject;
    U16 *detail;
    U16 *location;
    U16 highlight_item;
    MYTIME start_time;
    MYTIME end_time;
    MYTIME alarm_time; 
    U16 save_result;
} mmi_tdl_save_cntx_struct;

typedef struct
{    
    /* Repeat */
    S32 selected_repeat;
	CHAR view_buff[MMI_TDL_MAX_REMINDER_NOTE_EN_SIZE]; 
    CHAR reminder_buff[MMI_TDL_MAX_REMINDER_NOTE_EN_SIZE]; 
    CHAR title_buff[MMI_TDL_MAX_TITLE_BUF_SIZE * ENCODING_LENGTH]; 
    CHAR start_year_buff[MMI_TDL_MAX_YEAR_SIZE * ENCODING_LENGTH];
    CHAR start_mon_buff[MMI_TDL_MAX_MONTH_SIZE * ENCODING_LENGTH];
    CHAR start_day_buff[MMI_TDL_MAX_DAY_SIZE * ENCODING_LENGTH];
    CHAR start_hour_buff[MMI_TDL_MAX_HOUR_SIZE * ENCODING_LENGTH];
    CHAR start_min_buff[MMI_TDL_MAX_MIN_SIZE * ENCODING_LENGTH];
    
    CHAR end_year_buff[MMI_TDL_MAX_YEAR_SIZE * ENCODING_LENGTH];
    CHAR end_mon_buff[MMI_TDL_MAX_MONTH_SIZE * ENCODING_LENGTH];
    CHAR end_day_buff[MMI_TDL_MAX_DAY_SIZE * ENCODING_LENGTH];
    CHAR end_hour_buff[MMI_TDL_MAX_HOUR_SIZE * ENCODING_LENGTH];
    CHAR end_min_buff[MMI_TDL_MAX_MIN_SIZE * ENCODING_LENGTH];

    CHAR alarm_year_buff[MMI_TDL_MAX_YEAR_SIZE * ENCODING_LENGTH];
    CHAR alarm_mon_buff[MMI_TDL_MAX_MONTH_SIZE * ENCODING_LENGTH];
    CHAR alarm_day_buff[MMI_TDL_MAX_DAY_SIZE * ENCODING_LENGTH];
    CHAR alarm_hour_buff[MMI_TDL_MAX_HOUR_SIZE * ENCODING_LENGTH];
    CHAR alarm_min_buff[MMI_TDL_MAX_MIN_SIZE * ENCODING_LENGTH];
    U8 alarm_date_buff[MMI_TDL_MAX_DATE_EN_LEN];  /* Merge year, month, day to a date string */
    U8 alarm_time_buff[MMI_TDL_MAX_TIME_EN_LEN];  /* Merge hour, minute to a time string */    
    
    U8 start_date_buff[MMI_TDL_MAX_DATE_EN_LEN];  /* Merge year, month, day to a date string */
    U8 start_time_buff[MMI_TDL_MAX_TIME_EN_LEN];  /* Merge hour, minute to a time string */    
    U8 end_date_buff[MMI_TDL_MAX_DATE_EN_LEN];    /* Similar with start_date_buff */
    U8 end_time_buff[MMI_TDL_MAX_TIME_EN_LEN];    /* Similar with start_time_buff */
    
    CHAR subject_buff[MMI_TDL_MAX_NOTE_EN_LEN];
    CHAR location_buff[MMI_TDL_MAX_NOTE_EN_LEN];
    CHAR *repeat_set[MMI_TDL_RULE_TOTAL];
    U8 is_dow_set;                                  /* MMI_TRUE: Dow has been selected */
    U8 dow_index;                                   /* Index of inline editor for notes */
    
    /* Priority */
    S32 selected_priority;                          /* Priority for inline selected index */
    CHAR *priority_set[MMI_TDL_MAX_PRIORITY];         /* Priority strings for selecting */

    /* Status */
    S32 selected_status;
    CHAR *status_set[MMI_TDL_MAX_STATUS_NUM];

    /* Category */
    S32 selected_category;
    S32 old_category;
    U8 hilited_category;
    CHAR *category_set[MMI_TDL_CATEGORY_TOTAL];
 
    U8 hilited_inline;     /* index of selected item in View screen */
    mmi_id fseditor_gid;
    mmi_id menu_gid;
    U16 fseditor_option_menu[3];

    /* Alarm */
    S32 selected_alm;      /* Inline selected index */
    U8 alarm_date_index;
    U8 alarm_time_index;
    CHAR *alarm_set[MMI_TDL_ALARM_TOTAL];       /* Alarm type strings for selecting */
    
    /* 
     * Buffers for edit
     */  
    WCHAR start_date[MMI_TDL_MAX_DATE_BUFF_SIZE];
    WCHAR start_time[MMI_TDL_MAX_TIME_BUFF_SIZE];
    WCHAR alarm_date[MMI_TDL_MAX_DATE_BUFF_SIZE];
    WCHAR alarm_time[MMI_TDL_MAX_TIME_BUFF_SIZE];
    WCHAR end_date[MMI_TDL_MAX_DATE_BUFF_SIZE];
    WCHAR end_time[MMI_TDL_MAX_TIME_BUFF_SIZE];
    U8 dow_state[MMI_TDL_MAX_DAYS_PER_WEEK];
    WCHAR edit_buff[MAX_TDL_DETAILS_SIZE];           /* Buffer for full screen edit, note or location */
    WCHAR repeat_str[MMI_TDL_MAX_INLINE_STRING_LEN]; /* Buffer for custom repeat string buffer */
    U8 template_idx;                                 /* Index of current selected template for note */
    CHAR *details_buff_p;
    U8 details_idx;
    history *history_ptr;                            /* Pointer to store history buffer when inserting template */
    U8 done_flag; /* done flag only for edit event screen */
    mmi_id save_sg_id;
}mmi_tdl_edit_cntx_struct;

#ifdef __MMI_CALENDAR_EVENT__
typedef struct
{
    MYTIME date;
	S32 search_id;
    mmi_cal_event_search_state_enum state;
    U32 event_cnt;
    srv_tdl_event_id_struct *event_buf;
}mmi_tdl_event_search_struct;
#endif

typedef struct
{
    MYTIME date;                        /* Date/time information from calendar application */
    srv_tdl_event_struct curr_event;
    srv_tdl_task_struct curr_task;
    srv_tdl_event_struct event_reminder;
    srv_tdl_task_struct task_reminder;
    srv_tdl_event_task_struct sorted_list[NUM_OF_TDL];
    U8 async_item_type;
    U16 curr_selected; 
    U8 curr_option;                     /* Index of current higlighted option */
    U16 total;                /* Total number of listed task */
    U16 curr_store_idx;                  /* index of current selected task */
#if 0
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
/* under construction !*/
#endif
#endif
	srv_tdl_search_filter_struct search;
	U8 hs_flag;
	U8 add_finish_flag;
    U8 delete_marker;
    U8 delete_process;
    U16 count_deleted;
	S32 hs_request_num;					/* home screen req task number */
	srv_tdl_vcal_enum vcal_filter;					/* 0->vEvent, 1->vTodo*/
    U16 reminder_type;  /* Event or task, due to event reminder screen may appears on task screens,
                           here cannot use vcal_filter.*/
    U32 reminder_id;
	U32 reminder_sns_source;
    MMI_BOOL reminder_pow_off;

#ifdef __MMI_CALENDAR_EVENT__
	mmi_tdl_event_search_struct monthly_search;
	mmi_tdl_event_search_struct weekly_search[7];
	mmi_tdl_event_search_struct daily_search;
	mmi_tdl_event_search_struct all_search;
	mmi_tdl_event_search_struct special_search;
	
	U32 weekly_search_cnt;
	srv_tdl_event_source_enum curr_source_id;
	U32 curr_event_id;
	srv_tdl_event_id_struct *sorted_event;
#endif
} tdl_context_struct;

typedef void (*soft_key_hdlr) (MMI_ID);
typedef void (*del_callback_hdlr) (MMI_ID);

typedef struct
{
    mmi_id sg_id;
    soft_key_hdlr LSK_function;
    soft_key_hdlr CSK_function;
    soft_key_hdlr RSK_function;
}mmi_tdl_confirm_user_data_struct;

typedef struct
{
    mmi_id sg_id;
    del_callback_hdlr callback_function;
}mmi_tdl_popup_user_data_struct;

/******************************************************************************* 
 * Extern Global Variable 
 *******************************************************************************/
extern tdl_context_struct g_tdl_cntx;
extern mmi_tdl_popup_user_data_struct g_tdl_popup_user_data;
extern mmi_tdl_confirm_user_data_struct g_tdl_confirm_user_data;
extern mmi_tdl_edit_cntx_struct g_tdl_edit_cntx;
extern const mmi_tdl_repeat_type_struct g_tdl_freq_set[];
extern const mmi_tdl_alarm_type_struct g_tdl_alm_set[];

/******************************************************************************* 
 * Global Function 
 *******************************************************************************/
/* Highlight handlers */
extern void mmi_tdl_highlight_menu(void);
//extern MMI_BOOL mmi_tdl_entry_reminder(void);
extern MMI_BOOL mmi_tdl_entry_reminder(mmi_scenario_id scen_id, void *arg);
extern void mmi_tdl_reminder_end_key(void);

extern void mmi_tdl_highlight_view(void);
extern void mmi_tdl_highlight_edit(void);
extern void mmi_tdl_highlight_delete(void);
extern void mmi_tdl_highlight_add(void);
extern void mmi_tdl_highlight_delete_all(void);

extern void mmi_tdl_highlight_meeting(void);
extern void mmi_tdl_highlight_course(void);
extern void mmi_tdl_highlight_date(void);
extern void mmi_tdl_highlight_call(void);
extern void mmi_tdl_highlight_anniversary(void);
extern void mmi_tdl_highlight_reminder(void);
extern void mmi_tdl_delete_all_history(void);
/* User Interface */
extern void mmi_tdl_stop_reminder(void);
extern void mmi_tdl_dismiss_reminder(void);
extern void mmi_tdl_reminder_snooze_handler(void);
extern mmi_ret mmi_tdl_task_main_group_proc(mmi_event_struct *evt);

extern void mmi_tdl_entry_view_int();
extern void mmi_tdl_entry_task_edit(void); 
extern void mmi_tdl_view_with_sg(mmi_id parent_id, srv_tdl_vcal_enum vcal_type, U32 source, U32 index);
extern void mmi_tdl_entry_view_hdlr(void);
extern void mmi_tdl_confirm_user_data_init(mmi_tdl_confirm_user_data_struct* arg);
extern mmi_ret mmi_tdl_comfirm_proc(mmi_event_struct *evt);
extern mmi_ret mmi_tdl_popup_proc(mmi_event_struct *evt);
extern void mmi_tdl_popup_user_data_init(mmi_tdl_popup_user_data_struct* arg);

#if 0
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif
#endif

extern U8 mmi_tdl_list_del_callback(void *parm);
extern mmi_ret mmi_tdl_task_main_leave_proc(mmi_event_struct *parm);
extern void mmi_tdl_entry_option_list(void);
extern void mmi_tdl_entry_add_hdlr(void);                        
extern void mmi_tdl_entry_delete_confirm(mmi_id parent);

#if 0
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_TODOLIST_DIARY_SUPPORT__ */
#endif /* __MMI_OP11_TODOLIST_DIARY_SUPPORT__ */

extern void mmi_tdl_entry_search_by_time(void);
extern void mmi_tdl_entry_search_by_note(void);
extern void mmi_tdl_entry_search_by_location(void);

#ifdef __SYNCML_SUPPORT__
extern U8 mmi_tdl_db_is_sync_now(void);
#endif

#define TODOLIST_DATA
extern void mmi_tdl_save_event(mmi_id parent_id, mmi_tdl_operation_type_enum type);
extern void mmi_tdl_save_task(mmi_id parent_id, mmi_tdl_operation_type_enum type);
extern void mmi_get_async_items(
                S32 start_index, 
                gui_iconlist_menu_item *menu_data, 
                S32 num_item,
                MYTIME* date);

extern void mmi_list_highlight_hdlr(S32 index);
extern S32 mmi_tdl_get_async_items(
                    S32 start_indx, 
                    gui_iconlist_menu_item *menuData, 
                    S32 num_item);
extern void mmi_entry_list_option(MMI_ID parent_id, mmi_menu_id root_id, mmi_proc_func proc);
extern void mmi_tdl_make_daily_list(U8 Type);
extern U16 mmi_tdl_make_daily_list_ext(
                    srv_tdl_event_task_struct *sorted_list, 
                    U16 *total,
                    U8 size, 
                    MYTIME seleted_time, 
                    U16 vcal_type);
extern void mmi_tdl_make_all_list(
                        srv_tdl_event_task_struct *list, 
                        U16 size,
                        U16 *total, 
                        U16 vcal_type);
extern U8 mmi_tdl_delete_record(U16 index, U16 vcal_type);
extern U16 mmi_tdl_get_curr_store_idx(void);
extern void mmi_tdl_save_adjust_alarm_type(
                        srv_tdl_alarm_struct *alarm, 
                        const MYTIME *entry_time);
extern void mmi_tdl_entry_task_view_all(void);
extern void* mmi_tdl_get_short(srv_tdl_vcal_enum vcal_type, U16 index);
#define TODOLIST_UTIL
extern void TDLShowAllList(void);
extern void mmi_tdl_get_time_string(
                    const void *data, 
                    const U16 vcal_type,
                    const MYTIME *date, 
                    CHAR *time_buff,
                    const U16 buff_size);
extern void mmi_tdl_get_date_string(
                    const MYTIME *date, 
                    CHAR *date_buff,
                    const U16 buff_size);
extern void mmi_tdl_set_context_date(MYTIME *CalTime);
extern void mmi_tdl_compute_alarm_time(
                        const U8 alarm_type,
                        const MYTIME *start_time, 
                        MYTIME *alarm_time);                         
                       

extern void mmi_tdl_load_task_by_display_index(U8 display_index);
extern void mmi_tdl_delete_all_searched_confirm(mmi_id parent_id);
extern void mmi_tdl_delete_overdue_confirm(mmi_id parent_id);
extern void mmi_tdl_delete_all_confirm(mmi_id parent_id);
extern U16 mmi_tdl_is_valid_alarm(U8 category, srv_tdl_alarm_struct *alarm, MYTIME *start_time, U8 repeat);
extern U16 mmi_tdl_load_by_store_index(U16 store_index, U16 vcal_filter);
//extern void mmi_tdl_validated_delete_all(void);
extern void mmi_tdl_validated_delete_all(MMI_ID app_id);
extern mmi_ret mmi_tdl_event_view_group_proc(mmi_event_struct *evt);
extern void mmi_tdl_set_type(srv_tdl_vcal_enum type);
extern mmi_ret mmi_tdl_task_view_group_proc(mmi_event_struct *evt);
extern void mmi_tdl_entry_task_edit_screen();


#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_tdl_tap_list_callback(mmi_tap_type_enum tap_type, S32 index);
#endif
#endif /* __MMI_TODOLIST__ */ 

#if defined(__MMI_TODOLIST__) || (defined(__MMI_CALENDAR__))
extern mmi_id mmi_tdl_sg_mgr_get_current_sg_id(void);
#endif

#endif /* TODOLISTPROT_H */
