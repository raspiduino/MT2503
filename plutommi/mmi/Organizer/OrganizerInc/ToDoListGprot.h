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
 * ToDoListGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Birthday application.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef TODOLIST_GPROT_H
#define TODOLIST_GPROT_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/
 
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "custom_mmi_default_value.h"
#include "custom_phb_config.h"
#include "kal_general_types.h"

/*****************************************************************************
 * Define 
 *****************************************************************************/
#ifdef __MMI_BIRTHDAY_REMINDER__
#define TDL_BIRTHDAY_INDEX_POOL      (sizeof(U16) * MMI_PHB_PHONE_ENTRIES)
#endif


/*****************************************************************************
 * Typedef 
 *****************************************************************************/
typedef enum
{
    MMI_TDL_OP_TYPE_ADD,
    MMI_TDL_OP_TYPE_EDIT,
    MMI_TDL_OP_TYPE_TOTAL
}mmi_tdl_operation_type_enum;

/* MUST NOT change the order */
typedef enum
{
    MMI_TDL_ALARM_OFF,
    MMI_TDL_ALARM_ON,
    MMI_TDL_ALARM_BEFORE_5_MINS,
    MMI_TDL_ALARM_BEFORE_10_MINS,
    MMI_TDL_ALARM_BEFORE_15_MINS,
    MMI_TDL_ALARM_BEFORE_30_MINS,
    MMI_TDL_ALARM_CUSTOM,
    MMI_TDL_ALARM_TOTAL
} mmi_tdl_alarm_enum;

typedef enum
{
    MMI_TDL_STATUS_UNDONE,
    MMI_TDL_STATUS_DONE,
    MMI_TDL_STATUS_TOTAL
} mmi_tdl_status_enum;

/* MUST NOT change the order */
typedef enum
{
    MMI_TDL_CATEGORY_REMINDER,
    MMI_TDL_CATEGORY_MEETING,
    MMI_TDL_CATEGORY_COURSE,
    MMI_TDL_CATEGORY_DATE,
    MMI_TDL_CATEGORY_CALL,
    MMI_TDL_CATEGORY_ANNIVERSARY,
    MMI_TDL_CATEGORY_BIRTHDAY,
    MMI_TDL_CATEGORY_TOTAL
} mmi_tdl_category_enum;

typedef enum
{
    MMI_TDL_PRIORITY_LOW,
    MMI_TDL_PRIORITY_MEDIUM,
    MMI_TDL_PRIORITY_HIGH,
    MMI_TDL_PRIORITY_TOTAL
} mmi_tdl_priority_enum;

/* MUST NOT change the order */
typedef enum
{
    MMI_TDL_RULE_ONCE,
    MMI_TDL_RULE_DAILY,
    MMI_TDL_RULE_DAYS,
    MMI_TDL_RULE_WEEKLY,
    MMI_TDL_RULE_MONTHLY,
    MMI_TDL_RULE_YEARLY,
#ifdef __MMI_INDICAL__
    MMI_TDL_RULE_TITHI,
#endif
    MMI_TDL_RULE_TOTAL
} mmi_tdl_repeat_rule_enum;

typedef enum
{
    MMI_TDL_SUCCESS,    
	MMI_TDL_EXPIRED_ALARM,  /* Repeat is once and start time is overdue */
    MMI_TDL_INVALID_ANNIVERSARY_REPEAT,
    MMI_TDL_INVALID_START_TIME,
    MMI_TDL_INVALID_END_TIME,
    MMI_TDL_EMPTY_SUBJECT,  /* Notes is empty */    
    MMI_TDL_INVALID_ALARM,
    MMI_TDL_INVALID_REPEAT,
    MMI_TDL_REPEAT_OUT_OF_BOUNDARY,
    MMI_TDL_ALARM_OVERRUN,
    MMI_TDL_ALARM_TOO_LATE,
    MMI_TDL_ERROR_UNKNOW,
    MMI_TDL_INVALID_RANGE, /* Used for tithi repeat */
    MMI_TDL_ERROR_TOTAL
} mmi_tdl_error_enum;

#ifdef __SYNCML_SUPPORT__
typedef enum
{
    MMI_TDL_SYNCML_ERR_NO_ERROR,
    MMI_TDL_SYNCML_ERR_NOT_FOUND,
    MMI_TDL_SYNCML_ERR_EMPTY_NAME,
    MMI_TDL_SYNCML_ERR_DUPLICATE_NAME,
    MMI_TDL_SYNCML_ERR_MEMORY_FULL,
    MMI_TDL_SYNCML_ERR_INVALID_FILENAME,
    MMI_TDL_SYNCML_ERR_SELECT_PATH_TOO_LONG,
    MMI_TDL_SYNCML_ERR_UNSUPPORT_FORMAT,
    MMI_TDL_SYNCML_ERR_UNKNOWN,
    MMI_TDL_SYNCML_ERR_INVALID_INDEX,    
    MMI_TDL_SYNCML_ERR_DELETE_FAIL,	
    MMI_TDL_SYNCML_ERR_INVALID_OPERATION,
    MMI_TDL_SYNCML_ERR_TOTAL
} vclndr_syncml_error_enum;

typedef enum
{
    MMI_TDL_SYNCML_GET,
    MMI_TDL_SYNCML_ADD,
    MMI_TDL_SYNCML_MODIFY,
    MMI_TDL_SYNCML_DELETE,
    MMI_TDL_SYNCML_TOTAL_OPERATIONS
}vclndr_syncml_operations_enum;
#endif /* __SYNCML_SUPPORT__ */



/** 
  * CUI: save a task/event
  */

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    S32 result;      
    U16 store_index;
} cui_tdl_save_result_struct;

typedef enum
{
    /* SG event ID */
    EVT_ID_TDL_SAVE_SUCCESS = TO_DO_LIST_BASE + 100,  
    EVT_ID_TDL_SAVE_CANCEL,
    EVT_ID_TDL_SAVE_FAIL,
    EVT_ID_TDL_TOTAL

    /* SG event ID */
} evt_id_tdl_enum;

/*****************************************************************************
 * Global Function 
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
*  mmi_tdl_save_adjust_field
 * DESCRIPTION
*   This function update tdl record
 * 
* PARAMETERS
*  data : data to adjust
*  buff_size : buffer size of data.
*  vcal_type : vcal type of data.
 * RETURNS
*  error code
* GLOBALS AFFECTED
*   none
 *****************************************************************************/
extern U16 mmi_tdl_save_adjust_field(
                        void *data,
                        const U16 buff_size,
                        const U16 vcal_type);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_create
 * DESCRIPTION
 *  Create tdl save CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_tdl_save_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_run
 * DESCRIPTION
 *  Run tdl save CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to run group.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_tdl_save_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_title
 * DESCRIPTION
 *  Set the title of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * title : [IN] title to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_title(mmi_id sg_id, U16 title_id);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_subject
 * DESCRIPTION
 *  Set the subject of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * subject : [IN] subject to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_subject(mmi_id sg_id, U16 *subject);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_due_time
 * DESCRIPTION
 *  Set the due_time of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * due_time : [IN] due_time to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_due_time(mmi_id sg_id, MYTIME *due_time);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_priority
 * DESCRIPTION
 *  Set the priority of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * priority : [IN] priority to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_priority(mmi_id sg_id, U8 priority);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_status
 * DESCRIPTION
 *  Set the status of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * status : [IN] status to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_status(mmi_id sg_id, U8 status);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_alarm
 * DESCRIPTION
 *  Set the category of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * alarm_type : [IN] alarm type to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_alarm(mmi_id sg_id, U8 alarm_type);

	
/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_alarm_time
 * DESCRIPTION
 *  Set the category of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * alarm_time : [IN] alarm time to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_alarm_time(mmi_id sg_id, MYTIME *alarm_time);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_repeat
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * repeat_type : [IN] repeat type to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_repeat(mmi_id sg_id, srv_tdl_repeat_struct *repeat);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_detail
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * detail : [IN] detail to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_detail(mmi_id sg_id, U16 *detail);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_task
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * pevent : [IN] event struct to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_set_task(mmi_id sg_id, srv_tdl_task_struct *ptask);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_operation_type
 * DESCRIPTION
 *  Set the type of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * title : [IN] type to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
void cui_tdl_save_set_operation_type(mmi_id sg_id, mmi_tdl_operation_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_set_highlight_item
 * DESCRIPTION
 *  Set highlight item.
 * PARAMETERS
 *  sg_id      [IN]        Screen group.
 *  item_id    [IN]        item id.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_tdl_save_set_highlight_item(mmi_id sg_id, U16 item_id);


/*****************************************************************************
 * FUNCTION
 *  cui_tdl_save_close
 * DESCRIPTION
 *  Set the title of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_tdl_save_close(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_create
 * DESCRIPTION
 *  Create calendar event save CUI.
 * PARAMETERS
 *  mmi_id : [IN] parent_id, parent group ID to add current group to.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_cal_save_create(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_run
 * DESCRIPTION
 *  Run tdl save CUI.
 * PARAMETERS
 *  mmi_id : [IN] sg_id, group ID to run group.
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern void cui_cal_save_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_title
 * DESCRIPTION
 *  Set the title of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * title : [IN] title to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_title(mmi_id sg_id, U16 title_id);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_subject
 * DESCRIPTION
 *  Set the subject of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * subject : [IN] subject to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_subject(mmi_id sg_id, U16 *subject);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_start_time
 * DESCRIPTION
 *  Set the start_time of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * start_time : [IN] start_time to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_start_time(mmi_id sg_id, MYTIME *start_time);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_end_time
 * DESCRIPTION
 *  Set the end_time of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * end_time : [IN] end_time to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_end_time(mmi_id sg_id, MYTIME *end_time);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_category
 * DESCRIPTION
 *  Set the category of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * category : [IN] category to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_category(mmi_id sg_id, U8 category);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_alarm
 * DESCRIPTION
 *  Set the category of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * alarm_type : [IN] alarm type to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_alarm(mmi_id sg_id, U8 alarm_type);

	
/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_alarm_time
 * DESCRIPTION
 *  Set the category of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * alarm_time : [IN] alarm time to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_alarm_time(mmi_id sg_id, MYTIME *alarm_time);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_repeat
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * repeat_type : [IN] repeat type to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_repeat(mmi_id sg_id, srv_tdl_repeat_struct *repeat);

	
/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_location
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * location : [IN] location to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_location(mmi_id sg_id, U16 *location);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_detail
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * detail : [IN] detail to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_detail(mmi_id sg_id, U16 *detail);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_event
 * DESCRIPTION
 *  Set the repeat of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * pevent : [IN] event struct to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_event(mmi_id sg_id, srv_tdl_event_struct *pevent);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_operation_type
 * DESCRIPTION
 *  Set the type of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * title : [IN] type to set to
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_set_operation_type(mmi_id sg_id, mmi_tdl_operation_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_set_highlight_item
 * DESCRIPTION
 *  Set highlight item.
 * PARAMETERS
 *  sg_id      [IN]        Screen group.
 *  item_id    [IN]        item id.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_cal_save_set_highlight_item(mmi_id sg_id, U16 item_id);

/*****************************************************************************
 * FUNCTION
 *  cui_cal_save_close
 * DESCRIPTION
 *  Set the title of edit screen
 * PARAMETERS
 * sg_id : [IN] screen group ID
 * RETURNS
 * RETURN VALUES
 *****************************************************************************/
extern void cui_cal_save_close(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_is_busy
 * DESCRIPTION
 *  TDL is busy now?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE TDL is busy now
 *  MMI_FALSE TDL isn't busy now
 *****************************************************************************/
extern MMI_BOOL mmi_tdl_is_busy(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_is_pending_reminder
 * DESCRIPTION
 *  Check is task/event reminder screen presents
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_tdl_is_pending_reminder(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_is_context_inited
 * DESCRIPTION
 *  Check if global context has been initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : TRUE
 *  MMI_FALSE : FALSE
 *****************************************************************************/
extern MMI_BOOL mmi_tdl_is_context_inited(void);

#if 0
#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __SYNCML_SUPPORT__
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_get_total_cal_index
 * DESCRIPTION
 *  Get store index of all events
 * PARAMETERS
 *  list : [IN/OUT] index list of events
 * RETURNS
 *  Total amount of events
 * RETURN VALUES
 *  Return value : total amount of events
 *****************************************************************************/
extern U16 mmi_tdl_get_total_cal_index(U16* list);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_sync_vevent
 * DESCRIPTION
 *  Synchronize the calendar data
 * PARAMETERS
 *  action : [IN] sync type
 *  path : [IN/OUT] file path of sync data
 *  index : [IN/OUT] index of todolist
 *  sync_chset : [IN] charset of the event
 * RETURNS
 *  Error code
 * RETURN VALUES
 *  Reture value : the error code of the sync result
 *****************************************************************************/
extern U16 mmi_tdl_sync_vevent(
                    U8 action, 
                    CHAR *path, 
                    U16 *index, 
                    U8 sync_chset);
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_get_total_task_index
 * DESCRIPTION
 *  Get store index of all tasks
 * PARAMETERS
 *  list : [IN/OUT] index list of tasks
 * RETURNS
 *  Total amount of tasks
 * RETURN VALUES
 *  Return value : total amount of tasks
 *****************************************************************************/
extern U16 mmi_tdl_get_total_task_index(U16* list);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_sync_vtodo
 * DESCRIPTION
 *  Synchronize the task data
 * PARAMETERS
 *  action : [IN] sync type
 *  path : [IN/OUT] file path of sync data
 *  index : [IN/OUT] index of todolist
 *  sync_chset : [IN] charset of the task
 * RETURNS
 *  Error code
 * RETURN VALUES
 *  Reture value : the error code of the sync result
 *****************************************************************************/                    
extern U16 mmi_tdl_sync_vtodo(
                    U8 action, 
                    CHAR *path, 
                    U16 *index, 
                    U8 sync_chset);
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#endif /* __SYNCML_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_view_vcalendar
 * DESCRIPTION
 *  View vcalendar
 * PARAMETERS
 *  type : [IN] calendar type
 *  index: [IN] index
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void mmi_tdl_view_vcalendar(U16 type, U16 index);


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_conv_repeat_type
 * DESCRIPTION
 *  convert repeat type
 * PARAMETERS
 *  repeat type : [IN]
 * RETURNS
 *  framework repeat type
 *****************************************************************************/
extern U8 mmi_tdl_conv_repeat_type(U8 repeat);

extern void *mmi_tdl_get_event_node(U16 index);

extern mmi_ret mmi_tdl_set_reminder_proc(mmi_event_struct *evt);

extern MMI_BOOL mmi_tdl_check_no_event_popup(void);

#endif /* TODOLIST_GPROT_H */
