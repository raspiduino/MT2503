/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

/* Filename:
 * ---------
 *    SyncMLChangeLog.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file provide serveral api to maintain the chenge log.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/

#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#include "fs_type.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "PhbSrvGprot.h"
#include "timerevents.h"

typedef FS_HANDLE (*mmi_syncml_return_file_hdl_funcptr_type)(U8, U32, U8);


/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/
static U8 syncml_record[SYNCML_CHANGE_LOG_RECORD_SIZE];
static mmi_syncml_return_file_hdl_funcptr_type g_mmi_syncml_return_file_hdl_callback;


/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
extern MMI_BOOL mmi_syncml_msg_match_flag;


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static void mmi_syncml_prepare_record_to_save(U8 operation, U16 luid);
static FS_HANDLE mmi_syncml_return_file_handle(U8 account_id, U32 access_parameter, U8 application_type);
static S32 mmi_syncml_search_duplicate_record(U16 luid, U8 account_id, U8 application_type);
static void mmi_syncml_merge_record(U8 account_id, U8 application_type, S32 fs_index);
static void mmi_syncml_append_record(U8 account_id, U8 application_type);
static U8 mmi_syncml_operation_update(U8 old_operation, U8 new_operation);
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
static void mmi_syncml_update_regular_sync_notify(U8 account_index, U8 database_type);
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
#endif 
#ifdef __MMI_SYNCML_DEVICE_SYNC__
static FS_HANDLE mmi_syncml_device_return_file_handle(U8 accnt_id, U32 access_parameter, U8 application_type);
#endif


/*****************************************************************************
 * Function definition
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_addition_notification
 * DESCRIPTION
 *  addition notification for mmi framework register
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_syncml_phb_addition_notification(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;

    if (srv_phb_get_storage(evt->store_index) == PHB_STORAGE_NVRAM)
    {
        mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_ADD, evt->store_index);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_delete_notification
 * DESCRIPTION
 *  deletion notification for mmi framework register
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_syncml_phb_deletion_notification(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;
    if (srv_phb_get_storage(evt->store_index) == PHB_STORAGE_NVRAM)
    {
        mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_DELETE, evt->store_index);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_modification_notification
 * DESCRIPTION
 *  modification notification for mmi framework register
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_syncml_phb_modification_notification(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;
    if (srv_phb_get_storage(evt->store_index) == PHB_STORAGE_NVRAM)
    {
        mmi_syncml_phb_data_changed_notification(SYNCML_RECORD_MODIFY, evt->store_index);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_data_changed_notification
 * DESCRIPTION
 *  Callback for phonebook record changed
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_phb_data_changed_notification(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 luid_exist;
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_PHB_DATA_CHANGED, operation, luid);
    
    /* currently MMI takes the store index as LUID */
    MMI_ASSERT(luid < MAX_PHB_PHONE_ENTRY);

    mmi_syncml_prepare_record_to_save(operation, luid);

	g_mmi_syncml_return_file_hdl_callback = mmi_syncml_return_file_handle;
    
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        /* this profile is used to sync before */ 
        if (g_mmi_syncml_cntx.last_phb_anchor[i - 1] != 0) 
        {
            /* change to write change log even if in syncing 
             * It is for that in next syncing we can send the data received last time,
             * This change is from cmcc test requirement.
             */                   
            if (mmi_syncml_is_phb_sync_now() && 
                i == g_mmi_syncml_cntx.active_account &&
                operation != SYNCML_RECORD_ADD)
            {
                continue; /* skip the synchronizing account and update the other profiles */
            }        

            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_PHONEBOOK);

            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_PHONEBOOK, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_PHONEBOOK);
            }
        }
    }

#ifdef __MMI_SYNCML_DEVICE_SYNC__
	g_mmi_syncml_return_file_hdl_callback = mmi_syncml_device_return_file_handle;

	for (i = 1; i < MAX_SYNCML_DEV_NUM + 1; i++)
	{
        if (g_mmi_syncml_cntx.dev_cntx_ptr->setting_ptr->last_phb_anchor[i - 1] != 0)
			/* this profile is used to sync before */ 
        {
            if (mmi_syncml_is_device_sync()
                && mmi_syncml_is_phb_sync_now()
                && i == g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev
                && operation != SYNCML_RECORD_ADD)
            {
                continue; /* skip the synchronizing profile and update the other profiles */
            }          

            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_PHONEBOOK);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_PHONEBOOK, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_PHONEBOOK);
            }
        }
	}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {      
        if (g_mmi_syncml_cntx.regular_sync[i] == MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED && 
            (g_mmi_syncml_cntx.app_to_sync[i] & SYNCML_DB_PHONEBOOK) )
        {
            if (!g_mmi_syncml_cntx.is_pre_sync &&
                ((!mmi_syncml_is_phb_sync_now() && mmi_syncml_msg_match_flag)
            #ifdef __MMI_SYNCML_DEVICE_SYNC__
                || mmi_syncml_is_device_sync()
            #endif 
                ))
            {
                mmi_syncml_update_regular_sync_notify(i, SYNCML_DB_PHONEBOOK);
                return;
            }    
        }
    }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */ 
}

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_calendar_data_changed_notification
 * DESCRIPTION
 *  Callback for to-do-list record changed
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 *	vcal_type			   [IN]			   vcal_type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_calendar_data_changed_notification(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    mmi_syncml_device_setting_context_struct *dev_setting_ptr;
#endif    
    S32 luid_exist;
	//U16 vcal_type;
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_TDL_DATA_CHANGED, operation, luid);

    /* currently MMI takes the store index as LUID */
    mmi_syncml_prepare_record_to_save(operation, luid);
    
	g_mmi_syncml_return_file_hdl_callback = mmi_syncml_return_file_handle;
    
	//vcal_type = mmi_tdl_get_vcal_type(luid);
    
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {

        /* change to write change log even if in syncing 
         * It is for that in next syncing we can send the data received last time,
         * This change is from cmcc test requirement.
         */ 
        if (mmi_syncml_is_calendar_sync_now() && 
            i == g_mmi_syncml_cntx.active_account&&
            operation != SYNCML_RECORD_ADD)
        {
            continue; /* skip the synchronizing profile and update the other profiles */
        }
			/* Get the vcalendar db type */
        if (g_mmi_syncml_cntx.last_cal_anchor[i - 1] != 0)
    	{
            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_CALENDAR);

            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_CALENDAR, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_CALENDAR);
            }
        }
    }   
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    dev_setting_ptr = (mmi_syncml_device_setting_context_struct *)mmi_syncml_device_get_setting_cntx();

    g_mmi_syncml_return_file_hdl_callback = mmi_syncml_device_return_file_handle;

    for (i = 1; i < MAX_SYNCML_DEV_NUM + 1; i++)
	{
        if (mmi_syncml_is_device_sync()
            && mmi_syncml_is_calendar_sync_now()
            && i == g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev
            && operation != SYNCML_RECORD_ADD)
        {
            continue; /* skip the synchronizing profile and update the other profiles */
        }
        
        if (dev_setting_ptr->last_cal_anchor[i - 1] != 0)
			/* this profile is used to sync before */ 
        {
            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_CALENDAR);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_CALENDAR, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_CALENDAR);
            }
        }
	}   
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {      
        if (g_mmi_syncml_cntx.regular_sync[i] == MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED && 
            (g_mmi_syncml_cntx.app_to_sync[i] & SYNCML_DB_CALENDAR) )
        {
            if (!g_mmi_syncml_cntx.is_pre_sync &&
               ((!mmi_syncml_is_calendar_sync_now())
            #ifdef __MMI_SYNCML_DEVICE_SYNC__
                || mmi_syncml_is_device_sync()
            #endif 
                ))
            {
                mmi_syncml_update_regular_sync_notify(i, SYNCML_DB_CALENDAR);
                return;
            }    
        }
    }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */


#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_task_data_changed_notification
 * DESCRIPTION
 *  Callback for task record changed
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 *	vcal_type			   [IN]			   vcal_type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_task_data_changed_notification(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    mmi_syncml_device_setting_context_struct *dev_setting_ptr;
#endif    
    S32 luid_exist;
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_TDL_DATA_CHANGED, operation, luid);

    /* currently MMI takes the store index as LUID */
    mmi_syncml_prepare_record_to_save(operation, luid);
    
    g_mmi_syncml_return_file_hdl_callback = mmi_syncml_return_file_handle;
    
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        /* change to write change log even if in syncing 
         * It is for that in next syncing we can send the data received last time,
         * This change is from cmcc test requirement.
         */     
        if (mmi_syncml_is_task_sync_now() && 
            i == g_mmi_syncml_cntx.active_account &&
            operation != SYNCML_RECORD_ADD)
        {
            continue; /* skip the synchronizing profile and update the other profiles */
        }
			/* Get the vcalendar db type */
        if (g_mmi_syncml_cntx.last_task_anchor[i - 1] != 0)
    	{
            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_TASK);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_TASK, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_TASK);
            }
        }
    }
        
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    dev_setting_ptr = (mmi_syncml_device_setting_context_struct *)mmi_syncml_device_get_setting_cntx();
	g_mmi_syncml_return_file_hdl_callback = mmi_syncml_device_return_file_handle;
	for (i = 1; i < MAX_SYNCML_DEV_NUM + 1; i++)
	{
        if (mmi_syncml_is_device_sync()
            && mmi_syncml_is_task_sync_now()
            && i == g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev
            && operation != SYNCML_RECORD_ADD)
        {
            continue; /* skip the synchronizing profile and update the other profiles */
        }
        
        if (dev_setting_ptr->last_task_anchor[i - 1] != 0)
			/* this profile is used to sync before */ 
        {     
            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_TASK);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_TASK, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_TASK);
            }
        }
	}  
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {      
        if (g_mmi_syncml_cntx.regular_sync[i] == MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED && 
            (g_mmi_syncml_cntx.app_to_sync[i] & SYNCML_DB_TASK) )
        {
            if (!g_mmi_syncml_cntx.is_pre_sync &&
               ((!mmi_syncml_is_task_sync_now())
            #ifdef __MMI_SYNCML_DEVICE_SYNC__
                || mmi_syncml_is_device_sync()
            #endif 
                ))
            {
                mmi_syncml_update_regular_sync_notify(i, SYNCML_DB_TASK);
                return;
            }    
        }
    }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */


#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_note_data_changed_notification
 * DESCRIPTION
 *  Callback for note record changed
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_note_data_changed_notification(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    mmi_syncml_device_setting_context_struct *dev_setting_ptr;
#endif    
    S32 luid_exist;
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_TDL_DATA_CHANGED, operation, luid);

    /* currently MMI takes the store index as LUID */
    mmi_syncml_prepare_record_to_save(operation, luid);
    
    g_mmi_syncml_return_file_hdl_callback = mmi_syncml_return_file_handle;
    
    for (i = 1; i < MMI_MAX_SYNCML_ACCOUNTS + 1; i++)
    {
        /* change to write change log even if in syncing 
         * It is for that in next syncing we can send the data received last time,
         * This change is from cmcc test requirement.
         */     
        if (mmi_syncml_is_note_sync_now() && 
            i == g_mmi_syncml_cntx.active_account &&
            operation != SYNCML_RECORD_ADD)
        {
            continue; /* skip the synchronizing profile and update the other profiles */
        }
		/* Get the note db type */
        if (g_mmi_syncml_cntx.last_note_anchor[i - 1] != 0)
    	{
            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_NOTE);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_NOTE, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_NOTE);
            }
        }
    }
        
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    dev_setting_ptr = (mmi_syncml_device_setting_context_struct *)mmi_syncml_device_get_setting_cntx();
	g_mmi_syncml_return_file_hdl_callback = mmi_syncml_device_return_file_handle;
	for (i = 1; i < MAX_SYNCML_DEV_NUM + 1; i++)
	{
        if (mmi_syncml_is_device_sync()
            && mmi_syncml_is_note_sync_now()
            && i == g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev
            && operation != SYNCML_RECORD_ADD)
        {
            continue; /* skip the synchronizing profile and update the other profiles */
        }
        
        if (dev_setting_ptr->last_note_anchor[i - 1] != 0)
			/* this profile is used to sync before */ 
        {     
            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_NOTE);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_NOTE, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_NOTE);
            }
        }
	}  
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS; i++)
    {      
        if (g_mmi_syncml_cntx.regular_sync[i] == MMI_SYNCML_REGULAR_SYNC_DATA_CHANGED && 
            (g_mmi_syncml_cntx.app_to_sync[i] & SYNCML_DB_NOTE))
        {
            if (!g_mmi_syncml_cntx.is_pre_sync &&
               ((!mmi_syncml_is_note_sync_now())
            #ifdef __MMI_SYNCML_DEVICE_SYNC__
                || mmi_syncml_is_device_sync()
            #endif 
                ))
            {
                mmi_syncml_update_regular_sync_notify(i, SYNCML_DB_NOTE);
                return;
            }    
        }
    }
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
}
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */


#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
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
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
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
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */


#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
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
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
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
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
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
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_current_time
 * DESCRIPTION
 *  Get current time in seconds
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_syncml_get_current_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&t);
    return mmi_dt_mytime_2_utc_sec(&t, KAL_FALSE);
}


/*****************************************************************************
* Local Function  
*****************************************************************************/
/* Local function can only be called within this .C file, it shallbe declare */
/* as static */



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_prepare_record_to_save
 * DESCRIPTION
 *  Prepare the change log data
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_prepare_record_to_save(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(syncml_record, (void *)(&luid), sizeof(U16));
    s = mmi_syncml_get_current_time();
    memcpy(syncml_record + sizeof(U16), (void *)(&s), sizeof(U32));
    syncml_record[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] = operation;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_return_file_handle
 * DESCRIPTION
 *  Open log file for the specific database
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  access_parameter        [IN]            file access parameter
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static FS_HANDLE mmi_syncml_return_file_handle(U8 account_id, U32 access_parameter, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U8 *fs_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* task changelog path is longest */
    fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH));
    
    if (application_type == SYNCML_DB_PHONEBOOK) /* phb */
    {       
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_id;
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    else if (application_type == SYNCML_DB_CALENDAR) /* tdl */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_CAL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_CAL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_id;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    else if (application_type == SYNCML_DB_TASK) /* tdl */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_TASK_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_id;
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    else if (application_type == SYNCML_DB_NOTE) /* note */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_NOTE_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_NOTE_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + account_id;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    else
    {
        return -9; /* file not found */
        OslMfree(fs_path);
    }

    fh = FS_Open((U16*) fs_path, access_parameter);
    
    OslMfree(fs_path);

    return fh;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_search_duplicate_record
 * DESCRIPTION
 *  Search if there is a duplicate change log with the same LUID
 * PARAMETERS
 *  luid                    [IN]            LUID
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static S32 mmi_syncml_search_duplicate_record(U16 luid, U8 account_id, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    S32 res = SYNCML_CHANGE_LOG_NOT_FOUND;
    U32 fs_size, read_length, i;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
    U16 luid_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = g_mmi_syncml_return_file_hdl_callback(account_id, FS_READ_ONLY, application_type);

    if (fs_handle >= 0)
    {
        FS_GetFileSize(fs_handle, &fs_size);

        for (i = 0; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
        {
            FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
            memcpy((void *) &luid_temp, (void*) &syncml_temp[0], sizeof(U16));
            if (luid == luid_temp)
            {
                res = i;
                break;
            }
        }

        FS_Close(fs_handle);
    }
    else
    {
        /* file access error... */
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_append_record
 * DESCRIPTION
 *  Append the change log data
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 *  fs_index                [IN]            file index
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static void mmi_syncml_merge_record(U8 account_id, U8 application_type, S32 fs_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    U32 read_length, written_length, fs_size, i;
    U8 old_operation, new_operation;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
    U8 syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = g_mmi_syncml_return_file_hdl_callback(account_id, FS_READ_WRITE, application_type);

    FS_GetFileSize(fs_handle, &fs_size);

    /* find out the data for merge */
    FS_Seek(fs_handle, fs_index, FS_FILE_BEGIN);
    FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
    old_operation = syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE - 1];
    new_operation = syncml_record[SYNCML_CHANGE_LOG_RECORD_SIZE - 1];

    memcpy((void*) &syncml_update[0], (void*) &syncml_record[0], SYNCML_CHANGE_LOG_RECORD_SIZE);
    syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] = mmi_syncml_operation_update(old_operation, new_operation);

    /* prepare the updated change log */
    FS_Seek(fs_handle, fs_index, FS_FILE_BEGIN); /* change file content from the modified index */
    if (syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] == SYNCML_RECORD_ERASE)
    {
        /* after erase a record, other record need move ahead */
        for (i = fs_index + SYNCML_CHANGE_LOG_RECORD_SIZE; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
        {
            FS_Seek(fs_handle, SYNCML_CHANGE_LOG_RECORD_SIZE, FS_FILE_CURRENT);
            FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
            FS_Seek(fs_handle, 0 - 2 * SYNCML_CHANGE_LOG_RECORD_SIZE, FS_FILE_CURRENT);
            FS_Write(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length);
        }
        FS_Truncate(fs_handle);
    }
    else
    {
        FS_Write(fs_handle, (void*) &syncml_update[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length);
    }

    FS_Close(fs_handle);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_append_record
 * DESCRIPTION
 *  Append the change log data
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static void mmi_syncml_append_record(U8 account_id, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    U32 written_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = g_mmi_syncml_return_file_hdl_callback(account_id, FS_CREATE | FS_READ_WRITE, application_type);

    FS_Seek(fs_handle, 0, FS_FILE_END);
    FS_Write(fs_handle, (void*) &syncml_record[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length); 
    FS_Close(fs_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_operation_update
 * DESCRIPTION
 *  Check the operation if the change log is duplicted
 * PARAMETERS
 *  old_operation           [IN]            old operation
 *  new_operation           [IN]            new operation
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_syncml_operation_update(U8 old_operation, U8 new_operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rtn = old_operation;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (old_operation)
    {
        case SYNCML_RECORD_ADD:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */
                    break;
                case SYNCML_RECORD_MODIFY:
                    rtn = SYNCML_RECORD_ADD;
                    break;
                case SYNCML_RECORD_DELETE:
                    rtn = SYNCML_RECORD_ERASE;
                    break;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
            }
            break;
        case SYNCML_RECORD_MODIFY:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */
                    break;
                case SYNCML_RECORD_MODIFY:
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_DELETE:
                    rtn = SYNCML_RECORD_DELETE;
                    break;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */                   
            }
            break;
        case SYNCML_RECORD_DELETE:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD:
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_MODIFY: /* error */
                    break;
                case SYNCML_RECORD_DELETE: /* error */
                    break;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */                   
            }
            break;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__            
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */            
    }

    return rtn;
}


#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_operation_update
 * DESCRIPTION
 *  Check the operation if the change log is duplicted
 * PARAMETERS
 *  old_operation           [IN]            old operation
 *  new_operation           [IN]            new operation
 * RETURNS
 *  U8
 *****************************************************************************/
static void mmi_syncml_update_regular_sync_notify(U8 account_index, U8 database_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_account_struct *temp_account = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/          
    switch(database_type)
    {
        case SYNCML_DB_PHONEBOOK:             
            g_mmi_syncml_cntx.regular_sync_notify[account_index]|= MMI_SYNCML_PHB_DATA_CHANGE;
            break;
            
        case SYNCML_DB_CALENDAR:
            g_mmi_syncml_cntx.regular_sync_notify[account_index]|= MMI_SYNCML_CALENDAR_DATA_CHANGE;
            break;
            
        case SYNCML_DB_TASK:
            g_mmi_syncml_cntx.regular_sync_notify[account_index]|= MMI_SYNCML_TASK_DATA_CHANGE;
            break;
            
        case SYNCML_DB_NOTE:
            g_mmi_syncml_cntx.regular_sync_notify[account_index]|= MMI_SYNCML_NOTE_DATA_CHANGE;
            break;
            
        case SYNCML_DB_BOOKMARK:
            g_mmi_syncml_cntx.regular_sync_notify[account_index]|= MMI_SYNCML_BOOKMARK_DATA_CHANGE;
            break;
            
        case SYNCML_DB_EMAIL:
            g_mmi_syncml_cntx.regular_sync_notify[account_index]|= MMI_SYNCML_EMAIL_DATA_CHANGE;
            break;
            
        default:
            break;
    }

    /* If plag out the battery, should save the flag first here */       	
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    mmi_syncml_read_account_from_nvram((U8)(account_index + 1), (void*)temp_account);
    temp_account->regular_sync_notify = g_mmi_syncml_cntx.regular_sync_notify[account_index];
    mmi_syncml_write_account_to_nvram((U8)(account_index + 1), (void *)temp_account);
    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }

#ifdef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
    g_mmi_syncml_cntx.is_data_change_timeout = MMI_FALSE;
    
    StartTimer(SYNCML_DATA_CHANGE_DELAY_TIMER, 
               SYNCML_DATA_CHANGE_DELAY_TIME, 
               mmi_syncml_data_change_timer_hdlr);                
#endif/* __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__ */

}
#endif /* __MMI_SYNCML_VF_DATA_CHANGE_SYNC__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clearall_change_log
 * DESCRIPTION
 *  clear all items in change log
 * PARAMETERS
 *  profile_id           [IN]            profile id
 *  database             [IN]            application/database type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_clearall_change_log(U8 account_id, U8 database)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    fs_handle = mmi_syncml_return_file_handle(account_id, FS_READ_WRITE, database);
    if (fs_handle >= 0)
    {
        FS_Seek(fs_handle, 0, FS_FILE_BEGIN);
        FS_Truncate(fs_handle);
        FS_Close(fs_handle);
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_query_change_log
 * DESCRIPTION
 *  Qurey the change log
 * PARAMETERS
 *  profile_id           [IN]            profile id
 *  database             [IN]            application/database type
 *  luid                 [OUT]           LUID
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_syncml_query_change_log(U8 operation, U8 database, U16 *luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_length, fs_size, i;
    U16 count = 0;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];

	FS_HANDLE fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	if (mmi_syncml_is_device_sync())
	{
		fs_handle = mmi_syncml_device_return_file_handle(g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev, FS_READ_ONLY, database);
	}
	else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
	{
		fs_handle = mmi_syncml_return_file_handle((U8)(g_mmi_syncml_cntx.active_account), FS_READ_ONLY, database);
	}

	if  (fs_handle < 0)
    {
		return 0; /* log file not exist, count should be 0 */
    }

    FS_GetFileSize(fs_handle, &fs_size);

    for (i = 0; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
    {
        FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
        if (syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] == operation)
        {
            *(luid + count) = ((U16*)syncml_temp)[0]; 
            count++;
        }
    }

    FS_Close(fs_handle);
    return count;
}


#ifdef __MMI_SYNCML_DEVICE_SYNC__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_return_file_handle
 * DESCRIPTION
 *  Open log file for the specific database
 * PARAMETERS
 *  accnt_id	            [IN]            profile id
 *  access_parameter        [IN]            file access parameter
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static FS_HANDLE mmi_syncml_device_return_file_handle(U8 accnt_id, U32 access_parameter, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U8 *fs_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    fs_path = OslMalloc(sizeof(SYNCML_DEV_PHB_CHANGE_LOG_FILE_PATH) + 3);
    
    if (application_type == SYNCML_DB_PHONEBOOK) /* phb */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_DEV_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_DEV_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_id;
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    else if (application_type == SYNCML_DB_CALENDAR) /* cal */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_DEV_CAL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_DEV_CAL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_id;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    else if (application_type == SYNCML_DB_TASK) /* task */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_DEV_TASK_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_DEV_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_id;
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    else if (application_type == SYNCML_DB_NOTE) /* task */
    {
        mmi_ucs2cpy((CHAR*) fs_path, (CHAR*) SYNCML_DEV_NOTE_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_DEV_NOTE_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_id;
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
    else
    {
        return -9; /* file not found */
    }

    fh = FS_Open((U16*) fs_path, access_parameter);
    OslMfree(fs_path);

    return fh;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clearall_change_log
 * DESCRIPTION
 *  clear all items in change log
 * PARAMETERS
 *  accnt_id 	         [IN]            profile id
 *  database             [IN]            application/database type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_clearall_change_log(U8 accnt_id, U8 database)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    fs_handle = mmi_syncml_device_return_file_handle(accnt_id, FS_READ_WRITE, database);
    if (fs_handle >= 0)
    {
        FS_Seek(fs_handle, 0, FS_FILE_BEGIN);
        FS_Truncate(fs_handle);
        FS_Close(fs_handle);
    }
    
}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#endif /* __SYNCML_SUPPORT__ */


