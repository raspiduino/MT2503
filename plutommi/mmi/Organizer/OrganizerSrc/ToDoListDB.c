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
 * ToDoListDB.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for providing phonebook interface for java package
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_TODOLIST__

#include "MMIDataType.h"
#include "TodolistSrvGprot.h"
#include "custom_mmi_default_value.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ToDoListProt.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_msg_struct.h"
#include "Conversions.h"
#include "stdio.h"
#include "fs_type.h"
#include "fs_func.h"
#include "ToDoListGprot.h"
#include "ToDoListDB.h"
#include "FileMgrSrvGProt.h"
#include "vCalSrvGprot.h"
#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif
#ifdef __SYNCML_SUPPORT__
#include "SyncMLGProt.h"
#endif

#include "ToDoListDBStruct.h"

/*
** Define
*/
#define MMI_TDLDB_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_TDLDB_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_TDLDB_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_TDLDB_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)
		
/*
** Local Variable
*/
mmi_tdl_java_context_struct g_tdl_java_cntx;

/*
** Local Function
*/
#if defined(SUPPORT_JSR_75_PIM)
static void mmi_tdl_make_list_by_category(
                        U8 category, 
                        srv_tdl_event_task_struct *list, 
                        U16 buff_size,
                        U16 *total);
                        
static U16 mmi_tdl_pim_event_add(
                                 const mmi_evtdb_java_entry_struct* java_entry, 
                                 const mmi_vclndr_db_sort_enum db_index,                        
                                 U16 *index);
                        
static U16 mmi_tdl_pim_task_add(
                        const mmi_evtdb_java_entry_struct* evtdb_entry, 
                        U16 *index);
                        
static U16 mmi_tdl_pim_check_field_mask(const U16 mask, const U16 field);

static U16 mmi_tdl_pim_event_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index);

static U16 mmi_tdl_pim_task_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index);

static U8 mmi_tdl_pim_event_get_field(U16 index, mmi_evtdb_java_entry_struct *entry);
static U16 mmi_tdl_pim_task_parse_field(
                        srv_tdl_task_struct *ptask,
                        const mmi_evtdb_java_entry_struct* java_entry);
static U16 mmi_tdl_pim_event_parse_field(
                        srv_tdl_event_struct *pevent,
                        const mmi_vclndr_db_sort_enum db_index,
                        const mmi_evtdb_java_entry_struct *java_entry);
static U8 mmi_tdl_pim_task_get_field(U16 index, mmi_evtdb_java_entry_struct *entry);
#endif

#ifdef __MMI_VCALENDAR__
static U16 mmi_tdl_at_event_add(
                        srv_tdl_event_struct *pevent, 
                        U16 *index);
static U16 mmi_tdl_at_event_update(
                        srv_tdl_event_struct *pevent, 
                        U16 index);
static U16 mmi_tdl_at_task_add(
                        srv_tdl_task_struct *ptask, 
                        U16 *index);
static U16 mmi_tdl_at_task_update(
                        srv_tdl_task_struct *ptask, 
                        U16 index); 
static void mmi_at_get_default_filename(CHAR *result);                        
#endif /* __MMI_VCALENDAR__ */                        

/*
** Global Variable
*/
extern tdl_context_struct g_tdl_cntx;


/*
** Global Function
*/
#if defined(SUPPORT_JSR_75_PIM)
/*****************************************************************************
* FUNCTION
*  mmi_phb_handler_init
* DESCRIPTION
*   This function initializes phonebook handler app.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_evtdb_handler_init(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   SetProtocolEventHandler(mmi_tdl_pim_evtdb_wirte_req, MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ);
   SetProtocolEventHandler(mmi_tdl_pim_evtdb_read_req, MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ);

}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_evtdb_wirte_req
* DESCRIPTION
*   This function write a todolist entry from pim request
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_evtdb_wirte_req(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_set_entry_req_struct* local_ptr;
    mmi_evtdb_java_entry_struct java_entry;
    mmi_evtdb_java_error_enum error_code = MMI_EVTDB_JAVA_SUCCESS;
    U16  result, record_index = 0;
    U16 vcal_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_evtdb_java_set_entry_req_struct*)info;

    if(local_ptr->sort_type != MMI_EVTDB_SORT_BY_TIME)
    {
        error_code = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_JAVA_RETURN;        
    }

    if (local_ptr->db_index < MMI_VCLNDR_DB_TASK)
    {
        vcal_type = SRV_TDL_VCAL_EVENT;
    }
    else if (local_ptr->db_index == MMI_VCLNDR_DB_TASK)
    {
        vcal_type = SRV_TDL_VCAL_TASK;
    }
    else /* MMI_VCLNDR_DB_ALL: all events. */
    {
        vcal_type = SRV_TDL_VCAL_EVENT;
    }

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (mmi_syncml_is_calendar_sync_now() && vcal_type == SRV_TDL_VCAL_EVENT)
    {
        error_code = MMI_EVTDB_JAVA_TDL_NOT_READY;
        goto MMI_JAVA_RETURN;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
    
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (mmi_syncml_is_task_sync_now() && vcal_type == SRV_TDL_VCAL_TASK)
    {
        error_code = MMI_EVTDB_JAVA_TDL_NOT_READY;
        goto MMI_JAVA_RETURN;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

    /* delete record */
    if (local_ptr->entry_ptr == NULL)
    {
        record_index = (U8)local_ptr->index;

        result = srv_tdl_delete(record_index, vcal_type);
        if (result != SRV_TDL_RESULT_OK)
        {
            error_code = MMI_EVTDB_JAVA_OUT_OF_INDEX;
            goto MMI_JAVA_RETURN;
        }
    }  
    else /* Add and update new record */
    {
        memcpy(&java_entry, local_ptr->entry_ptr, sizeof(mmi_evtdb_java_entry_struct));

        /* Add */
        if (local_ptr->index == 0xFFFF) 
        {
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                error_code = mmi_tdl_pim_event_add(
                                        &java_entry, 
                                        (mmi_vclndr_db_sort_enum)local_ptr->db_index, 
                                        &record_index);
            }
            else
            {
                error_code = mmi_tdl_pim_task_add(
                                        &java_entry, 
                                        &record_index);
            }
        }
        /* Update */
        else
        {
			record_index = (U8)local_ptr->index;
            if (vcal_type == SRV_TDL_VCAL_EVENT)
            {
                error_code = mmi_tdl_pim_event_update(
                                        local_ptr->index,
                                        &java_entry, 
                                        local_ptr->db_index);
            }
            else
            {
                error_code = mmi_tdl_pim_task_update(
					local_ptr->index,
                                        &java_entry, 
                                        local_ptr->db_index);
            }
        }

        if (error_code <= MMI_EVTDB_JAVA_SUCCESS)
        {
        #ifdef __SYNCML_SUPPORT__
            /* send notification to SyncML */
            if (local_ptr->index == 0xFFFF)
            {
                if (vcal_type == SRV_TDL_VCAL_EVENT)
                {
                #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                    mmi_syncml_calendar_data_changed_notification(SYNCML_RECORD_ADD, record_index);
                #endif
                }
                else
                {
                #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                    mmi_syncml_task_data_changed_notification(SYNCML_RECORD_ADD, record_index);
                #endif
                }
            }
            else
            {
                if (vcal_type == SRV_TDL_VCAL_EVENT)
                {
                #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
                    mmi_syncml_calendar_data_changed_notification(SYNCML_RECORD_MODIFY, record_index);
                #endif
                }
                else
                {
                #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
                    mmi_syncml_task_data_changed_notification(SYNCML_RECORD_MODIFY, record_index);
                #endif
                }
            }
        #endif
        }
    }

MMI_JAVA_RETURN:
    mmi_tdl_pim_write_rsp((U16)error_code,record_index);
}

/*****************************************************************************
* FUNCTION
*  mmi_phb_java_write_rsp
* DESCRIPTION
*   This function return write result to JAVA
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_write_rsp(U16 result, U16 store_index)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_set_entry_rsp_struct *MsgPtr;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   MsgPtr = (mmi_evtdb_java_set_entry_rsp_struct*) 
                OslConstructDataPtr(sizeof(mmi_evtdb_java_set_entry_rsp_struct));
   MsgPtr->index = MsgPtr->handle = store_index;
   
   /* TDL may want to display some warning but it still save the task */
    if (result < MMI_EVTDB_JAVA_SUCCESS)
    {
        MsgPtr->result = MMI_EVTDB_JAVA_SUCCESS;
        MsgPtr->detail = (U8)result;
    }
    else
    {
        MsgPtr->result = (U8)result;
        MsgPtr->detail = 0xFF;
    }

   mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_RSP, (oslParaType *)MsgPtr, NULL);
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_evtdb_read_req
* DESCRIPTION
*   This function read a todolist entry from pim.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_evtdb_read_req(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_get_entry_req_struct* local_ptr;
    mmi_evtdb_java_error_enum error_code = MMI_EVTDB_JAVA_SUCCESS;
    U16 result;
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_evtdb_java_get_entry_req_struct*)info;

    if(local_ptr->sort_type != MMI_EVTDB_SORT_BY_TIME)
    {
        error_code = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    /* init tdl list, sort by date */
    if(local_ptr->index == 0 || local_ptr->count == 0)
    {
        if (local_ptr->db_index < MMI_VCLNDR_DB_TASK)
        {
            mmi_tdl_make_list_by_category(
                                local_ptr->db_index, 
                                g_tdl_java_cntx.sorted_list, 
                                NUM_OF_TDL, 
                                &g_tdl_java_cntx.total_listed_num);
        }
        else if (local_ptr->db_index == MMI_VCLNDR_DB_TASK)
        {

            mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list, 
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_TASK);
        }
        else /* MMI_VCLNDR_DB_ALL: get all events. */
        {
            mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list, 
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_EVENT);
        }
    }

	/* If count == 0, means only want to get total. */
    if (local_ptr->count != 0)
    {
        /* Get a record in context */
        if (local_ptr->index < NUM_OF_TDL)
        {
            if (local_ptr->db_index < MMI_VCLNDR_DB_TASK || local_ptr->db_index == MMI_VCLNDR_DB_ALL)
            {
                result = mmi_tdl_pim_event_get_field(local_ptr->index, local_ptr->entry_ptr);
            }
            else
            {
                result = mmi_tdl_pim_task_get_field(local_ptr->index, local_ptr->entry_ptr);
            }
            
            if (result == MMI_FALSE)
            {
                error_code = MMI_EVTDB_JAVA_NOT_FOUND;
                goto MMI_TDL_JAVA_RETURN;
            }            
        }
        else
        {
            error_code = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        }
    }

MMI_TDL_JAVA_RETURN:
    mmi_tdl_pim_read_rsp((U16)error_code, g_tdl_java_cntx.total_listed_num);
    return;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_read_rsp
* DESCRIPTION
*   This function return read result to JAVA
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_pim_read_rsp(U16 result, U16 count)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_evtdb_java_get_entry_rsp_struct *MsgPtr;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   MsgPtr = (mmi_evtdb_java_get_entry_rsp_struct*)
                    OslConstructDataPtr(sizeof(mmi_evtdb_java_get_entry_rsp_struct));

   MsgPtr->result = (U8)result;
   MsgPtr->count = count;

   mmi_frm_send_ilm(MOD_JASYN, MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_RSP, (oslParaType *)MsgPtr, NULL);
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_check_field_mask
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_check_field_mask(const U16 mask, const U16 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mask & field) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_event
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_event_add(
                        const mmi_evtdb_java_entry_struct* java_entry, 
                        const mmi_vclndr_db_sort_enum db_index,                        
                        U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code;
    srv_tdl_event_struct *pevent = NULL;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pevent = OslMalloc(sizeof(srv_tdl_event_struct));
    memset(pevent, 0, sizeof(srv_tdl_event_struct));

    pevent->present = MMI_TRUE;
    pevent->vcal = SRV_TDL_VCAL_EVENT;
    
    result = mmi_tdl_pim_event_parse_field(pevent, db_index, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }
    
    mmi_tdl_save_adjust_field(pevent, sizeof(srv_tdl_event_struct), SRV_TDL_VCAL_EVENT);
    
    error_code = srv_tdl_add(pevent, SRV_TDL_VCAL_EVENT, index);

    if (error_code == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
    {
        result = MMI_EVTDB_JAVA_STORAGE_FULL;
        goto MMI_TDL_JAVA_RETURN;
    }

    if (error_code != SRV_TDL_RESULT_OK)
    { 
        result = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_TDL_JAVA_RETURN;
    }

    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:
    if (pevent)
    {
        OslMfree(pevent);
        pevent = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_task
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_task_add(
                        const mmi_evtdb_java_entry_struct* java_entry, 
                        U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_code;
    srv_tdl_task_struct *ptask = NULL;
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptask = OslMalloc(sizeof(srv_tdl_task_struct));
    memset(ptask, 0, sizeof(srv_tdl_task_struct));

    ptask->present = MMI_TRUE;
    ptask->vcal = SRV_TDL_VCAL_TASK;
    
    result = mmi_tdl_pim_task_parse_field(ptask, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }
    
    mmi_tdl_save_adjust_field(ptask, sizeof(srv_tdl_task_struct), SRV_TDL_VCAL_TASK);

    error_code = srv_tdl_add(
                    ptask, 
                    SRV_TDL_VCAL_TASK, 
                    index);

    if (error_code == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
    {
        result = MMI_EVTDB_JAVA_STORAGE_FULL;
        goto MMI_TDL_JAVA_RETURN;
    }

    if (error_code != SRV_TDL_RESULT_OK)
    { 
        result = MMI_EVTDB_JAVA_NOT_SUPPORT;
        goto MMI_TDL_JAVA_RETURN;
    }

    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:
    if (ptask)
    {
        OslMfree(ptask);
        ptask = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_task_parse_field
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_task_parse_field(
                        srv_tdl_task_struct *ptask,
                        const mmi_evtdb_java_entry_struct* java_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_error_enum error_code;
    mmi_evtdb_java_entry_struct* pentry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pentry = OslMalloc(sizeof(mmi_evtdb_java_entry_struct));
    memcpy(pentry, java_entry, sizeof(mmi_evtdb_java_entry_struct));

    if (!mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_SUBJECT))
    {
        error_code = MMI_EVTDB_JAVA_TDL_INVALID_NOTES;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(ptask->subject, pentry->note, MAX_TODO_LIST_NOTE);
    }
    
    if (!mmi_tdl_pim_check_field_mask(
                            pentry->field_mask, 
                            MMI_TDL_JAVA_FIELD_END_TIME) ||
        !applib_dt_check_valid_by_app(
                            (U16)MMI_TDL_START_YEAR_SUPPORT, 
                            (U16)MMI_TDL_END_YEAR_SUPPORT, 
                            &pentry->endTime))
    {
        error_code = MMI_EVTDB_JAVA_TDL_INVALID_END_TIME;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(&ptask->due_time, &pentry->endTime, sizeof(MYTIME));
    }
 
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM))
    {
        ptask->alarm.type = pentry->alarm;
    }
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM_TIME))
    {
        memcpy(&ptask->alarm.first_launch, &pentry->alarm_time, sizeof(MYTIME));
    }
#endif
#ifdef JSR_75_PIM_EXTRA_DETAIL
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_DETAILS))
    {
        memcpy(ptask->details, pentry->details, MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH);
    }
#endif
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_REPEAT))
    {
        ptask->repeat.rule = pentry->repeat;
    }

#ifdef JSR_75_PIM_EXTRA_TODO
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_STATUS))
    {
        if (pentry->status < MMI_TDL_STATUS_TOTAL)
        {
            ptask->status = pentry->status;
        }
    }

    if (ptask->status == MMI_TDL_STATUS_DONE)
    {
        if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_DONE_TIME))
        {
            memcpy(&ptask->complete_time, &pentry->complete_time, sizeof(MYTIME));
        }
        else
        {
            GetDateTime(&ptask->complete_time);
        }
    }
    
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_PRIORITY))
    {
        ptask->priority = pentry->Priority;
    }
#endif
    error_code = MMI_EVTDB_JAVA_SUCCESS;
MMI_TDL_JAVA_RETURN:
    OslMfree(pentry);
    return error_code;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_event_parse_field
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_event_parse_field(
                        srv_tdl_event_struct *pevent,
                        const mmi_vclndr_db_sort_enum db_index,
                        const mmi_evtdb_java_entry_struct* java_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evtdb_java_error_enum error_code;
    mmi_evtdb_java_entry_struct* pentry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pentry = OslMalloc(sizeof(mmi_evtdb_java_entry_struct));
    memcpy(pentry, java_entry, sizeof(mmi_evtdb_java_entry_struct));

    if (!mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_SUBJECT))
    {
        error_code = MMI_EVTDB_JAVA_TDL_INVALID_NOTES;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(pevent->subject, pentry->note, MAX_TODO_LIST_NOTE);
    }

    if (!mmi_tdl_pim_check_field_mask(
                            pentry->field_mask, 
                            MMI_TDL_JAVA_FIELD_START_TIME) ||
        !applib_dt_check_valid_by_app(
                            (U16)MMI_TDL_START_YEAR_SUPPORT, 
                            (U16)MMI_TDL_END_YEAR_SUPPORT, 
                            &pentry->startTime))
    {
        error_code = MMI_EVTDB_JAVA_TDL_INVALID_START_TIME;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(&pevent->start_time, &pentry->startTime, sizeof(MYTIME));
    }

    if (!mmi_tdl_pim_check_field_mask(
                            pentry->field_mask, 
                            MMI_TDL_JAVA_FIELD_END_TIME) ||
        !applib_dt_check_valid_by_app(
                            (U16)MMI_TDL_START_YEAR_SUPPORT, 
                            (U16)MMI_TDL_END_YEAR_SUPPORT, 
                            &pentry->endTime))    
    {
        error_code = MMI_EVTDB_JAVA_TDL_INVALID_END_TIME;
        goto MMI_TDL_JAVA_RETURN;
    }
    else
    {
        memcpy(&pevent->end_time, &pentry->endTime, sizeof(MYTIME));
    }

    if (db_index < MMI_VCLNDR_DB_TASK)
    {
        pevent->category = db_index;
    }

    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM))
    {
        pevent->alarm.type = pentry->alarm;
    }
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_ALARM_TIME))
    {
        memcpy(&pevent->alarm.first_launch, &pentry->alarm_time, sizeof(MYTIME));
    }
#endif

#ifdef JSR_75_PIM_EXTRA_TODO
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_LOCATION))
    {
        memcpy(pevent->location, pentry->Location, MAX_TDL_LOCATION_LEN * ENCODING_LENGTH);
    }
#endif

#ifdef JSR_75_PIM_EXTRA_DETAIL
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_DETAILS))
    {
        memcpy(pevent->details, pentry->details, MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH);
    }
#endif
    if (mmi_tdl_pim_check_field_mask(pentry->field_mask, MMI_TDL_JAVA_FIELD_REPEAT))
    {
        pevent->repeat.rule = pentry->repeat;
        if (pevent->repeat.rule == MMI_TDL_RULE_DAYS)
        {
            pevent->repeat.dows = pentry->days;
        }
    }

    error_code = MMI_EVTDB_JAVA_SUCCESS;

MMI_TDL_JAVA_RETURN:
    OslMfree(pentry);
    return error_code;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_task_update
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_task_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    srv_tdl_task_struct *ptask = NULL;
    mmi_evtdb_java_error_enum error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptask = OslMalloc(sizeof(srv_tdl_task_struct));
    error_code = srv_tdl_get(
                    ptask, 
                    sizeof(srv_tdl_task_struct), 
                    SRV_TDL_VCAL_TASK, 
                    index);

    if (error_code != SRV_TDL_RESULT_OK || !ptask->present)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        goto MMI_TDL_JAVA_RETURN;
    }

    ptask->vcal = SRV_TDL_VCAL_TASK;
    
    result = mmi_tdl_pim_task_parse_field(ptask, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }
    
    mmi_tdl_save_adjust_field(ptask, sizeof(srv_tdl_task_struct), SRV_TDL_VCAL_TASK);
    ptask->alarm.snooze = 0;
    error_code = srv_tdl_update(ptask, SRV_TDL_VCAL_TASK, index);
                        
    if (error_code != SRV_TDL_RESULT_OK)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:    
    if (ptask)
    {
        OslMfree(ptask);
        ptask = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_update_event
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_pim_event_update(
                        U16 index, 
                        mmi_evtdb_java_entry_struct* java_entry, 
                        mmi_vclndr_db_sort_enum db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;
    srv_tdl_event_struct *pevent = NULL;
    mmi_evtdb_java_error_enum error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pevent = OslMalloc(sizeof(srv_tdl_event_struct));
    error_code = srv_tdl_get(
                    pevent, 
                    sizeof(srv_tdl_event_struct), 
                    SRV_TDL_VCAL_EVENT, 
                    index);

    if (error_code != SRV_TDL_RESULT_OK || !pevent->present)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;
        goto MMI_TDL_JAVA_RETURN;
    }

    pevent->vcal = SRV_TDL_VCAL_EVENT;
    
    result = mmi_tdl_pim_event_parse_field(pevent, db_index, java_entry);
    if (result !=  MMI_EVTDB_JAVA_SUCCESS)
    {
        goto MMI_TDL_JAVA_RETURN;
    }
    
    mmi_tdl_save_adjust_field(pevent, sizeof(srv_tdl_event_struct), SRV_TDL_VCAL_EVENT);
    pevent->alarm.snooze = 0;
    error_code = srv_tdl_update(pevent, SRV_TDL_VCAL_EVENT, index);
                        
    if (error_code != SRV_TDL_RESULT_OK)
    {
        result = MMI_EVTDB_JAVA_OUT_OF_INDEX;    
        goto MMI_TDL_JAVA_RETURN;
    }
    
    result = MMI_EVTDB_JAVA_SUCCESS;
    
MMI_TDL_JAVA_RETURN:    
    if (pevent)
    {
        OslMfree(pevent);
        pevent = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_task_get_field
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U8 mmi_tdl_pim_task_get_field(U16 index, mmi_evtdb_java_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    srv_tdl_task_struct *ptask = NULL;
    U16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptask = OslMalloc(sizeof(srv_tdl_task_struct));

    error_code = srv_tdl_get(
                    ptask, 
                    sizeof(srv_tdl_task_struct), 
                    SRV_TDL_VCAL_TASK, 
                    g_tdl_java_cntx.sorted_list[index].index);
                
    if (!ptask->present || error_code != SRV_TDL_RESULT_OK)
    {
        result = MMI_FALSE;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    memcpy(&entry->startTime, &ptask->due_time, sizeof(MYTIME));
    memcpy(&entry->endTime, &ptask->due_time, sizeof(MYTIME));
    
    entry->alarm = ptask->alarm.type;
#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE    
    if (ptask->alarm.type < MMI_TDL_ALARM_CUSTOM)
    {
        mmi_tdl_compute_alarm_time(
                        ptask->alarm.type, 
                        &ptask->due_time, 
                        (MYTIME*)&entry->alarm_time);
    }
    else
    {
        memcpy(&entry->alarm_time, &ptask->alarm.first_launch, sizeof(MYTIME));
    }
#endif    
    mmi_ucs2ncpy((CHAR*)&entry->note, (CHAR*)&ptask->subject, MAX_TODO_NOTE_LEN - 1);
#ifdef JSR_75_PIM_EXTRA_DETAIL
    mmi_ucs2ncpy((CHAR*)&entry->details, (CHAR*)&ptask->details, MAX_TDL_DETAILS_LEN);
#endif
    entry->repeat= ptask->repeat.rule;
    entry->days= ptask->repeat.dows;

#ifdef JSR_75_PIM_EXTRA_TODO   
	entry->Priority = ptask->priority;
	entry->status = ptask->status;
	memcpy(&entry->complete_time, &ptask->complete_time, sizeof(MYTIME));
#endif /* JSR_75_PIM_EXTRA_TODO */

    entry->index= index;
    entry->handle= g_tdl_java_cntx.sorted_list[index].index;
    
    result = MMI_TRUE;

MMI_TDL_JAVA_RETURN:
    if (ptask)
    {
        OslMfree(ptask);
        ptask = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_event_get_field
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
U8 mmi_tdl_pim_event_get_field(U16 index, mmi_evtdb_java_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    srv_tdl_event_struct *pevent = NULL;
    mmi_evtdb_java_error_enum error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pevent = OslMalloc(sizeof(srv_tdl_event_struct));

    error_code = srv_tdl_get(
                    pevent, 
                    sizeof(srv_tdl_event_struct), 
                    SRV_TDL_VCAL_EVENT, 
                    g_tdl_java_cntx.sorted_list[index].index);
                
    if (!pevent->present || error_code != SRV_TDL_RESULT_OK)
    {
        result = MMI_FALSE;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    memcpy(&entry->startTime, &pevent->start_time, sizeof(MYTIME));
    memcpy(&entry->endTime, &pevent->end_time, sizeof(MYTIME));
    
#if defined(JSR_75_PIM_EXTRA_TODO)
    entry->Type = pevent->category;
    memcpy(&entry->Location, &pevent->location, MAX_TDL_LOCATION_LEN * ENCODING_LENGTH);    
#endif /* JSR_75_PIM_EXTRA_TODO */

    entry->alarm = pevent->alarm.type;

#ifdef JSR_75_PIM_EXTRA_ALARM_TIME_USER_DEFINE    
    if (pevent->alarm.type < MMI_TDL_ALARM_CUSTOM)
    {
        mmi_tdl_compute_alarm_time(
                        pevent->alarm.type, 
                        &pevent->start_time, 
                        (MYTIME*)&entry->alarm_time);
    }
    else
    {
        memcpy(&entry->alarm_time, &pevent->alarm.first_launch, sizeof(MYTIME));
    }
#endif    
    mmi_ucs2ncpy((CHAR*)&entry->note, (CHAR*)&pevent->subject, MAX_TODO_NOTE_LEN - 1);
#ifdef JSR_75_PIM_EXTRA_DETAIL
    mmi_ucs2ncpy((CHAR*)&entry->details, (CHAR*)&pevent->details, MAX_TDL_DETAILS_LEN);
#endif
    entry->repeat= pevent->repeat.rule;
    entry->days= pevent->repeat.dows;

    entry->index= index;
    entry->handle= g_tdl_java_cntx.sorted_list[index].index;
    
    result = MMI_TRUE;

MMI_TDL_JAVA_RETURN:
    if (pevent)
    {
        OslMfree(pevent);
        pevent = NULL;
    }
    return result;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_handle
* DESCRIPTION
*   This function gets handle by sorted index.
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_pim_get_handle(U16 index, U8 sort_type, U8 db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_task_struct *temp_list = NULL;
    U16 total;
    S16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_list = OslMalloc(sizeof(srv_tdl_event_task_struct) * NUM_OF_TDL);
    memset(temp_list, 0xFF, sizeof(srv_tdl_event_task_struct) * NUM_OF_TDL);

    /* Required index should not be larger than NUM_OF_TDL*/
    if (index >= NUM_OF_TDL)
    {
        result = -1;
        goto MMI_TDL_JAVA_RETURN;
    }
    
    switch (sort_type)
    {
        case MMI_EVTDB_SORT_BY_TIME:

            if(db_index < MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_list_by_category(
                                        db_index,
                                        temp_list,
                                        NUM_OF_TDL,
                                        &total);
            }
            else if(db_index == MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_all_list(
                                temp_list,
                                NUM_OF_TDL,
                                &total,
                                SRV_TDL_VCAL_TASK);
            }
            else /* MMI_VCLNDR_DB_ALL: get all events. */
            {
                mmi_tdl_make_all_list(
                                temp_list,
                                NUM_OF_TDL,
                                &total,
                                SRV_TDL_VCAL_EVENT);
            }

        	/* if the index is not exist */
            if (temp_list[index].index == 0xFF)
            {
                result = -1;
            }
            else
            {
                result = (S16)temp_list[index].index;
            }
            break;
            
        default:
            result = -1;
    }
    
MMI_TDL_JAVA_RETURN:
    if (temp_list)
    {
        OslMfree(temp_list);
        temp_list = NULL;
    }
    return result;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_get_sorted_index
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_pim_get_sorted_index(U16 store_index, U8 sort_type, U8 db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sort_type)
    {
        case MMI_EVTDB_SORT_BY_TIME:
            /* sort the tdl by date */
            if(db_index < MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_list_by_category(
                                        db_index,
                                        g_tdl_java_cntx.sorted_list,
                                        NUM_OF_TDL,
                                        &g_tdl_java_cntx.total_listed_num);
            }
            else if(db_index == MMI_VCLNDR_DB_TASK)
            {
                mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list,
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_TASK);
            }
            else /* MMI_VCLNDR_DB_ALL: get all events. */
            {
                mmi_tdl_make_all_list(
                                g_tdl_java_cntx.sorted_list,
                                NUM_OF_TDL,
                                &g_tdl_java_cntx.total_listed_num,
                                SRV_TDL_VCAL_EVENT);
            }
            
            for (i = 0; i < NUM_OF_TDL ; i++)
            {
                if (g_tdl_java_cntx.sorted_list[i].index == store_index)    break;
            }

            if(i >= NUM_OF_TDL)
            {
                result = -1;
                goto MMI_TDL_JAVA_RETURN;
            }
            else
            {
                result = (S16)i;
                goto MMI_TDL_JAVA_RETURN;
            }
            break;
            
        default:
            result = -1;
            goto MMI_TDL_JAVA_RETURN;
    }

MMI_TDL_JAVA_RETURN:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tdl_make_list_by_category
 * DESCRIPTION
 *  To make the list of all tasks to be displayed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tdl_make_list_by_category(
                                U8 category, 
                                srv_tdl_event_task_struct *list, 
                                U16 buff_size,
                                U16 *total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_search_filter_struct search_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list);

    if (buff_size < NUM_OF_CAL)
    {
        return;
    }
    
    search_info.type = SRV_TDL_SEARCH_TYPE_CATEGORY;
    search_info.u.category = category;
    srv_tdl_search(
                list, 
                buff_size, 
                SRV_TDL_VCAL_EVENT, 
                search_info, 
                total);
                
    srv_tdl_sort(
                list, 
                *total, 
                SRV_TDL_SORT_TYPE_ENTRY_TIME);
}

#endif /* SUPPORT_JSR_75_PIM */


#if defined(__MMI_VCALENDAR__)
/*****************************************************************************
* FUNCTION
*  mmi_tdl_handler_init
* DESCRIPTION
*   This function initializes todolist handler for at command.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_handler_init(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   SetProtocolEventHandler(mmi_tdl_at_req_ind, MSG_ID_MMI_EQ_VCALENDAR_REQ_IND);
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_req_ind
* DESCRIPTION
*   This function handle AT command to request todolist record.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_req_ind(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_vcalendar_req_ind_struct* LocalPtr;
    U8 file_path[TDL_FOR_AT_MAX_FILE_PATH_LEN];
    U16 recordindex, delete_result;
    S16 i;
    srv_tdl_event_task_struct sorted_list[NUM_OF_TDL];
    U16 total;
    S32 vclndr_error_code;
    U16 error_code;
    MMI_BOOL result = MMI_TRUE;
    srv_vcal_parse_struct *handle;
    void *pobject;
    srv_vcal_type_enum vcal_type;
    U8 flag_finish;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (mmi_eq_vcalendar_req_ind_struct*)info;
    /* Init check */
#ifdef __SYNCML_SUPPORT__        
    if (mmi_syncml_is_tdl_sync_now())
    {
        result = MMI_FALSE;
        goto MMI_TDL_ERROR_RETURN;
    }    
#endif
    switch (LocalPtr->mode)
    {
        /*ADD*/
        case MMI_TDL_AT_ADD:
            /* file path check */
            if (LocalPtr->file_path == NULL)
            {
                result = MMI_FALSE;
                break;
            }

            handle = srv_vcal_parse_begin((U16*)LocalPtr->file_path, MMI_CHSET_UTF8);
            vclndr_error_code = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if (vclndr_error_code != SRV_VCAL_RESULT_SUCCESS)
            {
                vclndr_error_code = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            }
			else
			{
				if (vcal_type == SRV_VCAL_VEVENT)
	            {
	                memcpy(&g_tdl_cntx.curr_event, pobject, sizeof(srv_tdl_event_struct));
	            }
	            else if (vcal_type == SRV_VCAL_VTODO)
	            {
	                memcpy(&g_tdl_cntx.curr_task, pobject, sizeof(srv_tdl_task_struct));
	            }
			}
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            
            if (vclndr_error_code == SRV_VCAL_RESULT_SUCCESS)
            {
                if (vcal_type == SRV_TDL_VCAL_EVENT)
                {
                    if (g_tdl_cntx.curr_event.alarm.first_launch.nYear == 0)
                    {
                        g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_OFF;
                    }
                    else
                    {
                        g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_CUSTOM;
                        mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_event.alarm, &g_tdl_cntx.curr_event.start_time); 
                    }
                    error_code = mmi_tdl_at_event_add(&g_tdl_cntx.curr_event, &recordindex);
                }
                else
                {
                    if (g_tdl_cntx.curr_task.alarm.first_launch.nYear == 0)
                    {
                        g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_OFF;
                    }
                    else
                    {
                        g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_CUSTOM;
                        mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_task.alarm, &g_tdl_cntx.curr_task.due_time); 
                    }
                    error_code = mmi_tdl_at_task_add(&g_tdl_cntx.curr_task, &recordindex);
                }
                
                if (error_code != SRV_TDL_RESULT_OK)
                {
                    result = MMI_FALSE;
                    break;
                }
                srv_tdl_get_all_index(sorted_list, NUM_OF_TDL, (srv_tdl_vcal_enum)vcal_type, &total);
                srv_tdl_sort(sorted_list, total, SRV_TDL_SORT_TYPE_ENTRY_TIME);
                 
                /* sort task and get index*/
                i = mmi_tdl_at_get_sorted_index(recordindex, sorted_list, total, vcal_type);
                if (i > 0)
                {
                    LocalPtr->index = i;
                }                 
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
             
        /*UPDATE*/
        case MMI_TDL_AT_UPDATE:
            handle = srv_vcal_parse_begin((U16*)LocalPtr->file_path, MMI_CHSET_UTF8);
            vclndr_error_code = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, (U8*)&flag_finish);
            if (vclndr_error_code != SRV_VCAL_RESULT_SUCCESS)
            {
                vclndr_error_code = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            }
			else
			{
				if (vcal_type == SRV_VCAL_VEVENT)
	            {
	                memcpy(&g_tdl_cntx.curr_event, pobject, sizeof(srv_tdl_event_struct));
	            }
	            else if (vcal_type == SRV_VCAL_VTODO)
	            {
	                memcpy(&g_tdl_cntx.curr_task, pobject, sizeof(srv_tdl_task_struct));
	            }
	            else
	            {
	                vclndr_error_code = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
	            }
			}
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            srv_tdl_get_all_index(sorted_list, NUM_OF_TDL, (srv_tdl_vcal_enum)vcal_type, &total);
            srv_tdl_sort(sorted_list, total, SRV_TDL_SORT_TYPE_ENTRY_TIME);
            if (LocalPtr->index >= total)
            {
                result = MMI_FALSE;
                break;
            }
            if (vclndr_error_code == SRV_VCAL_RESULT_SUCCESS)
            {
                if (vcal_type == SRV_TDL_VCAL_EVENT)
                {
                    if (g_tdl_cntx.curr_event.alarm.first_launch.nYear == 0)
                    {
                        g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_OFF;
                    }
                    else
                    {
                        g_tdl_cntx.curr_event.alarm.type = MMI_TDL_ALARM_CUSTOM;
                        mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_event.alarm, &g_tdl_cntx.curr_event.start_time); 
                    }
                    
                    mmi_tdl_at_event_update(
                        &g_tdl_cntx.curr_event,
                        sorted_list[LocalPtr->index].index);
                }
                else
                {
                
                    if (g_tdl_cntx.curr_task.alarm.first_launch.nYear == 0)
                    {
                        g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_OFF;
                    }
                    else
                    {
                        g_tdl_cntx.curr_task.alarm.type = MMI_TDL_ALARM_CUSTOM;
                        mmi_tdl_save_adjust_alarm_type(&g_tdl_cntx.curr_task.alarm, &g_tdl_cntx.curr_task.due_time); 
                    }
                    
                    mmi_tdl_at_task_update(
                        &g_tdl_cntx.curr_task,
                        sorted_list[LocalPtr->index].index);
                }
            }    
            else
            {
                result = MMI_FALSE;     
            }        
            break;
             
        /*DELETE*/
        case MMI_TDL_AT_DELETE:
            srv_tdl_get_all_index(sorted_list, NUM_OF_TDL, (srv_tdl_vcal_enum)LocalPtr->vcal_type, &total);
            
            srv_tdl_sort(sorted_list, total, SRV_TDL_SORT_TYPE_ENTRY_TIME);
 
            if (LocalPtr->index >= total)
            {
                result = MMI_FALSE;
                break;
            }
 
            delete_result = mmi_tdl_delete_record(
                                    sorted_list[LocalPtr->index].index, 
                                    LocalPtr->vcal_type);
            
            /* delete fail */
            if (delete_result != MMI_TRUE)
            {
                result = MMI_FALSE;
                break;
            }                       
            break;
             
        /*READ*/
        case MMI_TDL_AT_READ:
		{
            srv_vcal_build_struct *handle;
        
            srv_tdl_get_all_index(sorted_list, NUM_OF_TDL, (srv_tdl_vcal_enum)LocalPtr->vcal_type, &total);
           
            srv_tdl_sort(sorted_list, total, SRV_TDL_SORT_TYPE_ENTRY_TIME);
 
            /* index check*/
            if (LocalPtr->index >= total)
            {
                result = MMI_FALSE;
                break;
            }
            memset(file_path, 0, TDL_FOR_AT_MAX_FILE_PATH_LEN);
            mmi_at_get_default_filename((CHAR*)file_path);
            mmi_tdl_load_by_store_index(sorted_list[LocalPtr->index].index, LocalPtr->vcal_type);

            handle = srv_vcal_build_begin((U16*)file_path, SRV_VCAL_VER_VCAL_1_0);
            if (SRV_TDL_VCAL_EVENT == LocalPtr->vcal_type)
            {
                vclndr_error_code = srv_vcal_build_add(handle, &g_tdl_cntx.curr_event, SRV_VCAL_VEVENT);            
            }
            else
            {
                vclndr_error_code = srv_vcal_build_add(handle, &g_tdl_cntx.curr_task, SRV_VCAL_VTODO);
            }
            srv_vcal_build_end(handle);
            
            if (vclndr_error_code != SRV_VCAL_RESULT_SUCCESS)
            {
                result = MMI_FALSE;
                break;
            }
     
            break;
		}
         /*QUERY*/
         case MMI_TDL_AT_QUERY:
            srv_tdl_get_all_index(NULL, 0, (srv_tdl_vcal_enum)LocalPtr->vcal_type, &total);
            result = MMI_TRUE;
            break;
         
         /* vCalendar is support? */
         case MMI_TDL_AT_SUPPORT:
            LocalPtr->mode = MMI_TRUE;
            result = MMI_TRUE;
            break;
         
    }
 
    mmi_tdl_at_res_req(LocalPtr->mode, result, LocalPtr->index, (U8)total, file_path);
    
MMI_TDL_ERROR_RETURN:
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_event
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_at_event_add(
                        srv_tdl_event_struct *pevent, 
                        U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_tdl_save_adjust_field(pevent, sizeof(srv_tdl_event_struct), SRV_TDL_VCAL_EVENT);
    
    if (pevent->category == MMI_TDL_CATEGORY_ANNIVERSARY ||
        pevent->category == MMI_TDL_CATEGORY_BIRTHDAY)
    {
        memset(&pevent->location, 0, sizeof(pevent->location));
        if (pevent->category == MMI_TDL_CATEGORY_BIRTHDAY)
        {
            memset(&pevent->details, 0, sizeof(pevent->details));
        }
    }
    
    result = srv_tdl_add(
                    pevent, 
                    SRV_TDL_VCAL_EVENT, 
                    index);
                    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    mmi_syncml_calendar_data_changed_notification(SYNCML_RECORD_ADD, *index);
#endif	
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_event
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_at_event_update(
                        srv_tdl_event_struct *pevent, 
                        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_tdl_save_adjust_field(pevent, sizeof(srv_tdl_event_struct), SRV_TDL_VCAL_EVENT);
    
    if (pevent->category == MMI_TDL_CATEGORY_ANNIVERSARY ||
        pevent->category == MMI_TDL_CATEGORY_BIRTHDAY)
    {
        memset(&pevent->location, 0, sizeof(pevent->location));
        if (pevent->category == MMI_TDL_CATEGORY_BIRTHDAY)
        {
            memset(&pevent->details, 0, sizeof(pevent->details));
        }
    }
    
    result = srv_tdl_update(
                        pevent, 
                        SRV_TDL_VCAL_EVENT, 
                        index);
                    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    mmi_syncml_calendar_data_changed_notification(SYNCML_RECORD_MODIFY, index);
#endif                    
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_task
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_at_task_add(
                        srv_tdl_task_struct *ptask, 
                        U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_tdl_save_adjust_field(ptask, sizeof(srv_tdl_task_struct), SRV_TDL_VCAL_TASK);

    result = srv_tdl_add(
                    ptask, 
                    SRV_TDL_VCAL_TASK, 
                    index);
                    
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    mmi_syncml_task_data_changed_notification(SYNCML_RECORD_ADD, *index);
#endif
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_pim_add_task
* DESCRIPTION
*   This function update tdl record
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_at_task_update(
                        srv_tdl_task_struct *ptask, 
                        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_tdl_save_adjust_field(ptask, sizeof(srv_tdl_task_struct), SRV_TDL_VCAL_TASK);

    result = srv_tdl_update(
                        ptask, 
                        SRV_TDL_VCAL_TASK, 
                        index);
                    
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    mmi_syncml_task_data_changed_notification(SYNCML_RECORD_MODIFY, index);
#endif
                    
    return result;
}

/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_get_sorted_index
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S16 mmi_tdl_at_get_sorted_index(U16 handle, srv_tdl_event_task_struct *sorted_list, U16 total, U16 vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_short_struct *pevent = NULL;
    srv_tdl_task_short_struct *ptask = NULL;
    U8 i = 0;
    U16 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        ret = srv_tdl_get_cache(
                    (void*)&pevent, 
                    sizeof(srv_tdl_event_short_struct), 
                    SRV_TDL_VCAL_EVENT,
                    handle);
        //MMI_ASSERT(ret == SRV_TDL_RESULT_OK);        
        if (pevent->present == 0)
        {
            return -1;
        }

        for (i = 0; i < total; i++)
        {
            if (sorted_list[i].index == handle) break;
        }
        
        if(i >= NUM_OF_CAL)
        {
            return -1;
        }
        else
        {
            return (S16)i;
        }
    }
    else
    {
        ret = srv_tdl_get_cache(
                    (void*)&ptask, 
                    sizeof(srv_tdl_task_short_struct), 
                    SRV_TDL_VCAL_TASK,
                    handle);
        //MMI_ASSERT(ret == SRV_TDL_RESULT_OK);        
        if (ptask->present == 0)
        {
            return -1;
        }
                
        for (i = 0; i < total ; i++)
        {
            if (sorted_list[i].index == handle) break;
        }
        
        if(i >= NUM_OF_TASK)
        {
            return -1;
        }
        else
        {
            return (S16)i;
        }    
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_at_get_default_filename
* DESCRIPTION
*   This function handle AT command to request todolist record.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_at_get_default_filename(CHAR *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ascii_path;
    S32 retval;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ascii_path = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
    sprintf(
            ascii_path, 
            "%c:\\%s", 
            MMI_TDL_PIM_DRV, 
            MMI_TDL_PIM_FILE_PATH);
    mmi_asc_to_ucs2(result, ascii_path);
    retval = FS_GetAttributes((const WCHAR*)result);
    if (retval == FS_PATH_NOT_FOUND || 
        retval == FS_FILE_NOT_FOUND)
    {
        retval = FS_CreateDir((const WCHAR*)result);
    }
    
    sprintf(
            ascii_path, 
            "%c:\\%s\\%s", 
            MMI_TDL_PIM_DRV, 
            MMI_TDL_PIM_FILE_PATH, 
            MMI_TDL_PIM_DEFAULT_FILE_NAME_FOR_AT);
    mmi_asc_to_ucs2(result, ascii_path);
    OslMfree(ascii_path);
}


#else /*defined(__MMI_VCALENDAR__)*/
/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_req_ind
* DESCRIPTION
*   This function handle AT command to request todolist record.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_req_ind(void* info)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_eq_vcalendar_req_ind_struct* LocalPtr;
   U8 file_path[TDL_FOR_AT_MAX_FILE_PATH_LEN];
   U8 total_task = 0;
   U8 index = 0;
   BOOL result = MMI_TRUE;
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   LocalPtr = (mmi_eq_vcalendar_req_ind_struct*)info;
   
    if (LocalPtr->mode == MMI_TDL_AT_SUPPORT)
    {
        LocalPtr->mode = MMI_FALSE;
        mmi_tdl_at_res_req(LocalPtr->mode,result,index, total_task, file_path);        
    }
}

#endif /*defined(__MMI_VCALENDAR__)*/

/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_res_req
* DESCRIPTION
*   This function return result to AT command
*
* PARAMETERS
*  
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_res_req(U8 mode, BOOL result,U8 index, U8 number, U8 *file_path)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_eq_vcalendar_res_req_struct *MsgPtr;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   MsgPtr = (mmi_eq_vcalendar_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_vcalendar_res_req_struct));
   MsgPtr->mode = mode;
   MsgPtr->result = (kal_bool)result;
   MsgPtr->index = index;
    if (MsgPtr->mode == MMI_TDL_AT_QUERY)
    {
        MsgPtr->total = NUM_OF_TDL;
        MsgPtr->used= number;
    }
    else if (MsgPtr->mode == MMI_TDL_AT_READ)
    {
        memcpy(MsgPtr->file_path, file_path, TDL_FOR_AT_MAX_FILE_PATH_LEN);
    }
 
   mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_VCALENDAR_RES_REQ, (oslParaType *)MsgPtr, NULL);

}


#endif /*__MMI_TODOLIST__*/

