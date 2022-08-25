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
 *    SyncMLHandler.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "mmi_msg_struct.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "string.h"
#include "ps_public_enum.h"
#include "custom_mmi_default_value.h"
#include "cbm_api.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "fs_func.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_syncml_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "App_mine.h"
#include "PhbSrvGprot.h"
#include "ToDoListGprot.h"
#include "NoteGprot.h"
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "syncml_common_customize.h"
#include "dtcntsrvgprot.h"
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 


/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/
static mmi_syncml_sync_request_struct g_syncml_sync_context;
    
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif


/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
extern mmi_syncml_device_sync_context_struct *const mmi_syncml_dev_p;
extern mmi_syncml_device_setting_context_struct *const mmi_syncml_dev_setting_p; 
extern mmi_syncml_device_account_context_struct *const mmi_syncml_dev_accnt_p; 
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

extern U16 g_syncml_temp_luid[];

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif 

/*  The flag is matchment flag for task and mmi;
    set/get_record_res_req may be later than finish_sync_indication, in this case,
    we should not execut res_req handler;
    Notes: This flag is only used for asynchronous database such as phonebook, email */
MMI_BOOL mmi_syncml_msg_match_flag = MMI_TRUE;


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static MMI_BOOL mmi_syncml_is_first_sync(U8 database);
static void mmi_syncml_finish_sync_hdlr(mmi_syncml_finish_sync_ind_struct *local_data);

static void mmi_syncml_set_record_req_ind(void *info);
static void mmi_syncml_get_record_req_ind(void *info);
static void mmi_syncml_query_luid_list_req_ind(void *info);
static void mmi_syncml_clean_luid_list_req_ind(void *info);
static void mmi_syncml_finish_sync_ind(void *info);
static void mmi_syncml_ps_busy_ind_hdlr(void *info);
static void mmi_syncml_progress_info_ind(void *info);
static void mmi_syncml_set_record_res_req(void);
static void mmi_syncml_get_record_res_req(void);
static void mmi_syncml_query_luid_list_res_req(void);
static void mmi_syncml_clean_luid_list_res_req(void);
static void mmi_syncml_start_sync_req(U8 *imei);
static void mmi_syncml_get_imei_rsp(void *info);

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif


/*****************************************************************************
 * Function definition
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_message_handlers
 * DESCRIPTION
 *  Protocol event handlers of SyncML messages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_message_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_syncml_set_record_req_ind, MSG_ID_MMI_SYNCML_SET_RECORD_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_get_record_req_ind, MSG_ID_MMI_SYNCML_GET_RECORD_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_query_luid_list_req_ind, MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_clean_luid_list_req_ind, MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_REQ_IND);
    SetProtocolEventHandler(mmi_syncml_finish_sync_ind, MSG_ID_MMI_SYNCML_FINISH_SYNC_IND);
    SetProtocolEventHandler(mmi_syncml_progress_info_ind, MSG_ID_MMI_SYNCML_PROGRESS_INFO_IND);
    SetProtocolEventHandler(mmi_syncml_ps_busy_ind_hdlr, MSG_ID_MMI_SYNCML_PS_BUSY_IND);

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    SetProtocolEventHandler(mmi_syncml_device_ask_accept_conn_ind_hdlr, MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_IND);
    SetProtocolEventHandler(mmi_syncml_device_bt_connected_ind_hdlr, MSG_ID_MMI_SYNCML_BT_CONNECTED_IND);
    SetProtocolEventHandler(mmi_syncml_device_bt_disconnected_ind_hdlr, MSG_ID_MMI_SYNCML_BT_DISCONNECTED_IND);
    SetProtocolEventHandler(mmi_syncml_device_remoteinfo_ind_hdlr, MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_IND);
    SetProtocolEventHandler(mmi_syncml_device_sync_db_ind_hdlr, MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND);
    SetProtocolEventHandler(mmi_syncml_device_session_aborted_ind, MSG_ID_MMI_SYNCML_SESSION_ABORTED_IND);
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_imei_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_get_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_NW_GET_IMEI_REQ, NULL, NULL);
    SetProtocolEventHandler(mmi_syncml_get_imei_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_finish_sync_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_get_imei_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_imei_rsp_struct *dataPtr = (mmi_nw_get_imei_rsp_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);

    if (dataPtr->result == 1)
    {
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__  
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
/* under construction !*/
#endif 
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

#ifdef __MMI_SYNCML_DEVICE_SYNC__
		if (mmi_syncml_is_device_sync())
		{
		    /* If disconnection msg come before get imei, reject current sync*/
		    if (mmi_syncml_device_get_curr_role() == MMI_SYNCML_DEV_ROLE_NONE)
            {
                mmi_syncml_device_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
                return;      
            }      
		    mmi_syncml_device_start_sync(dataPtr->imei);
			return;
		}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
        if (mmi_syncml_is_pc_sync())
        {
             /* If disconnection msg come before get imei, reject current sync*/
            if (mmi_syncml_device_get_curr_role() == MMI_SYNCML_DEV_ROLE_NONE)
            {   
                g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;
                g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] = g_mmi_syncml_cntx.phn_app_to_sync;
                mmi_syncml_pc_sync_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
                return;       
            }                      
            mmi_syncml_pc_start_sync(dataPtr->imei);
            return;        
        }
        
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

        /* common sync/server sync */
        mmi_syncml_start_sync_req(dataPtr->imei);
    }
    
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_start_sync_req
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_start_sync_req(U8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 account_index;
    mmi_syncml_start_sync_req_struct *dataPtr;

    mmi_syncml_account_struct *temp_account = NULL;
    applib_mime_type_struct *mime;
    srv_dtcnt_prof_proxy_info_struct *proxy_info = NULL;
	srv_dtcnt_sim_type_enum sim_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear the pre_sync flag because sync will start right now */
    g_mmi_syncml_cntx.is_pre_sync = 0;
	g_mmi_syncml_cntx.is_sync_state = MMI_TRUE;
    
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
    mmi_syncml_set_status_icon(MMI_TRUE);
#endif 
   
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif

#ifdef  __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
	{
		account_index = g_mmi_syncml_cntx.active_account - 1;
	}

    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

    mmi_syncml_read_account_from_nvram((U8)(account_index + 1), (void*)temp_account);

    dataPtr =
        (mmi_syncml_start_sync_req_struct*) construct_local_para(sizeof(mmi_syncml_start_sync_req_struct), TD_CTRL|TD_RESET);

    strcpy((CHAR*) dataPtr->server_uri, (CHAR*) temp_account->server_address);
    strcpy((CHAR*) dataPtr->server_username, (CHAR*) temp_account->server_username);
    strcpy((CHAR*) dataPtr->server_password, (CHAR*) temp_account->server_password);
    dataPtr->app_id = g_mmi_syncml_cntx.app_id[account_index];

    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
    {
        strcpy((CHAR*) dataPtr->contact_database_uri, (CHAR*) temp_account->contact_address);
        strcpy((CHAR*) dataPtr->contact_database_username, (CHAR*) temp_account->contact_username);
        strcpy((CHAR*) dataPtr->contact_database_password, (CHAR*) temp_account->contact_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCARD);
        if(mime)
        {
            strcpy((CHAR*) dataPtr->contact_mime_type, mime->mime_string);
        }
        dataPtr->contact_last_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index];
        dataPtr->contact_next_anchor = g_mmi_syncml_cntx.next_phb_anchor;

    #ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        g_mmi_syncml_cntx.contact_sync_state = MMI_TRUE; /* synchronizing */

        dataPtr->contact_free_id = srv_phb_get_total_contact(PHB_STORAGE_NVRAM) - srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
        dataPtr->contact_free_mem = dataPtr->contact_free_id * srv_phb_sync_get_record_size();
    }
	
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR)
    {
        strcpy((CHAR*) dataPtr->calendar_database_uri, (CHAR*) temp_account->calendar_address);
        strcpy((CHAR*) dataPtr->calendar_database_username, (CHAR*) temp_account->calendar_username);
        strcpy((CHAR*) dataPtr->calendar_database_password, (CHAR*) temp_account->calendar_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if(mime)
        {
            strcpy((CHAR*) dataPtr->calendar_mime_type, mime->mime_string);
        }
        dataPtr->calendar_last_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index];
        dataPtr->calendar_next_anchor = g_mmi_syncml_cntx.next_cal_anchor;

    #ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        g_mmi_syncml_cntx.calendar_sync_state = MMI_TRUE; /* synchronizing */
        mmi_syncml_disable_alarm(); /* disable alarm */

        dataPtr->calendar_free_id = NUM_OF_CAL - mmi_tdl_get_total_cal_index(NULL);
        dataPtr->calendar_free_mem = dataPtr->calendar_free_id * NVRAM_TODO_LIST_RECORD_SIZE;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
    {
        strcpy((CHAR*) dataPtr->task_database_uri, (CHAR*) temp_account->task_address);
        strcpy((CHAR*) dataPtr->task_database_username, (CHAR*) temp_account->task_username);
        strcpy((CHAR*) dataPtr->task_database_password, (CHAR*) temp_account->task_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if(mime)
        {
            strcpy((CHAR*) dataPtr->task_mime_type, mime->mime_string);
        }
        dataPtr->task_last_anchor = g_mmi_syncml_cntx.last_task_anchor[account_index];
        dataPtr->task_next_anchor = g_mmi_syncml_cntx.next_task_anchor;

    #ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        g_mmi_syncml_cntx.task_sync_state = MMI_TRUE; /* synchronizing */
        mmi_syncml_disable_alarm(); /* disable alarm */

        dataPtr->task_free_id = NUM_OF_TASK - mmi_tdl_get_total_task_index(NULL);
        dataPtr->task_free_mem = dataPtr->task_free_id * NVRAM_TODO_LIST_RECORD_SIZE;
    }	
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_NOTE)
    {
        strcpy((CHAR*) dataPtr->note_database_uri, (CHAR*) temp_account->note_address);
        strcpy((CHAR*) dataPtr->note_database_username, (CHAR*) temp_account->note_username);
        strcpy((CHAR*) dataPtr->note_database_password, (CHAR*) temp_account->note_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_PLAIN);
        if(mime)
        {
            strcpy((CHAR*) dataPtr->note_mime_type, mime->mime_string);
        }
        dataPtr->note_last_anchor = g_mmi_syncml_cntx.last_note_anchor[account_index];
        dataPtr->note_next_anchor = g_mmi_syncml_cntx.next_note_anchor;

    #ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        g_mmi_syncml_cntx.note_sync_state = MMI_TRUE; 

        dataPtr->note_free_id = MMI_MAX_NOTE_ITEM - mmi_note_get_total_record_index_array(NULL);
        dataPtr->note_free_mem = dataPtr->note_free_id * mmi_note_get_record_size();
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
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    memcpy(&dataPtr->imei[0], "IMEI:", 5);
    memcpy(&dataPtr->imei[5], imei, 15);
    dataPtr->imei[20] = 0;

#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_BACKUP)
    {
        dataPtr->sync_type = SYNCML_SYNC_CLIENT_ONE_WAY_REFRESH;
    }
    else if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_RESTORE)
    {
        dataPtr->sync_type = SYNCML_SYNC_SERVER_ONE_WAY_REFRESH;
    }
    else if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_EXPORT)
    {
        dataPtr->sync_type = SYNCML_SYNC_CLIENT_ONE_WAY_SYNC;
    }
    else if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_IMPORT)
    {
        dataPtr->sync_type = SYNCML_SYNC_SERVER_ONE_WAY_SYNC;
    }
    else
    {
        dataPtr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;
    }
#else
    dataPtr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    /* do not consider pc sync, another api to start sync for pc sync */
   
	srv_dtcnt_get_sim_preference(&sim_id);
	
    MMI_SYNCML_TRACE1(MMI_SYNCML_START_SYNC_GET_SIM, sim_id);
	
	if(SRV_DTCNT_SIM_TYPE_NONE == sim_id)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}

    dataPtr->net_id = cbm_encode_data_account_id(
                            temp_account->net_id[sim_id - 1],                                                
                            (cbm_sim_id_enum)(sim_id - 1),       
                            g_mmi_syncml_cntx.app_id[account_index],                             
                            KAL_FALSE); 

    proxy_info = (srv_dtcnt_prof_proxy_info_struct*)OslMalloc(sizeof(srv_dtcnt_prof_proxy_info_struct));

    memset(proxy_info, 0, sizeof(srv_dtcnt_prof_proxy_info_struct));
    
    srv_dtcnt_get_proxy_info(dataPtr->net_id, proxy_info, SRV_DTCNT_ACCOUNT_PRIMARY);
    
    switch(proxy_info->px_service)
    {
        case SRV_DTCNT_PROF_PX_SRV_CL_WSP:       /* WSP, Connection less */
        case SRV_DTCNT_PROF_PX_SRV_CO_WSP:       /* WSP, Connection oriented */
        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP:   /* WSP, Connection less, security mode */
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP:   /* WSP, Connection oriented, security mode */
        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA:   /* WTA, Connection less, security mode */
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA:   /* WTA, Connection oriented, security mode */
            dataPtr->transport_type = SYNCML_TRANS_WSP;
            break;
        default:
            dataPtr->transport_type = SYNCML_TRANS_HTTP;
            break;
    }

    if (proxy_info->use_proxy)
    {
        strncpy(dataPtr->proxy_server_ip, proxy_info->px_addr, MAX_SYNCML_PROXY_ADDR);
        dataPtr->proxy_server_port = (dataPtr->transport_type == SYNCML_TRANS_HTTP) ? proxy_info->px_port : 9201;
        strncpy((CHAR*) dataPtr->proxy_username, (CHAR*) proxy_info->px_authid, MAX_SYNCML_PROXY_USERNAME);
        strncpy((CHAR*) dataPtr->proxy_password, (CHAR*) proxy_info->px_authpw, MAX_SYNCML_PROXY_PASSWORD);
    }
    
    OslMfree(proxy_info);
    
    g_mmi_syncml_cntx.abort_state = MMI_FALSE;
    
    OslMfree(temp_account);
    
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_START_SYNC_REQ, (oslParaType*) dataPtr, NULL);

#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */
    g_mmi_syncml_cntx.cbm_state = 0; /* Fix bug */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_abort_sync_hdlr
 * DESCRIPTION
 *  abort sync on foreground and show abort popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_abort_sync_hdlr(CHAR* file, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_mmi_syncml_cntx.abort_by_other = MMI_FALSE;
    g_mmi_syncml_cntx.abort_state = MMI_TRUE;

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_ABORT_SYNC_REQ, NULL, NULL);
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_ABORT_SYNC_TRACE, file, line, g_mmi_syncml_cntx.abort_by_other);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_abort_sync_ext
 * DESCRIPTION
 *  abort sync in background and no abort popup
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_abort_sync_hdlr_ext(CHAR* file, U32 line)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/     
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/  
    g_mmi_syncml_cntx.abort_by_other = MMI_TRUE;
    g_mmi_syncml_cntx.abort_state = MMI_TRUE;   
    
    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_ABORT_SYNC_REQ, NULL, NULL);

    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_ABORT_SYNC_TRACE, line, g_mmi_syncml_cntx.abort_by_other);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_query_luid_list_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_query_luid_list_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_query_luid_list_req_ind_struct *local_data = (mmi_syncml_query_luid_list_req_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_sync_now())
    {
        return;
    }
	
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    /* now, we know which app will be synced, so unlock other apps that not be synced */
    if (mmi_syncml_is_device_or_pc_sync())
    {
        mmi_syncml_device_reset_sync_state();
    }
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;
    g_syncml_sync_context.luid_buf = local_data->luid_buf;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK) /* phb */
    {
        if ( g_syncml_sync_context.operation == SYNCML_RECORD_ALL ||
            (g_syncml_sync_context.operation == SYNCML_RECORD_ADD && mmi_syncml_is_first_sync(SYNCML_DB_PHONEBOOK)) )
        {
            /* sync all records */
            g_syncml_sync_context.count = srv_phb_sync_get_index_array(g_syncml_sync_context.luid_buf, MAX_SYNC_ITEMS); /* How to fix 1000 phb entries? */

        }
        else if(mmi_syncml_is_first_sync(SYNCML_DB_PHONEBOOK))
        {
            g_syncml_sync_context.count = 0;
        }
        else
        {
            g_syncml_sync_context.count = mmi_syncml_query_change_log(g_syncml_sync_context.operation, g_syncml_sync_context.database, g_syncml_sync_context.luid_buf);
        }
    }
	
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__	
    else if (g_syncml_sync_context.database == SYNCML_DB_CALENDAR) /* tdl */
    {
        if ( g_syncml_sync_context.operation == SYNCML_RECORD_ALL ||
            (g_syncml_sync_context.operation == SYNCML_RECORD_ADD && mmi_syncml_is_first_sync(SYNCML_DB_CALENDAR)) )
        {
            /* sync all records */
            g_syncml_sync_context.count = mmi_tdl_get_total_cal_index(g_syncml_sync_context.luid_buf);
        }
        else if(mmi_syncml_is_first_sync(SYNCML_DB_CALENDAR))
        {
            g_syncml_sync_context.count = 0;
        }
        else
        {
            g_syncml_sync_context.count = mmi_syncml_query_change_log(g_syncml_sync_context.operation, g_syncml_sync_context.database, g_syncml_sync_context.luid_buf);

        }
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    else if (g_syncml_sync_context.database == SYNCML_DB_TASK) /* tdl */
    {
        if ( g_syncml_sync_context.operation == SYNCML_RECORD_ALL ||
            (g_syncml_sync_context.operation == SYNCML_RECORD_ADD && mmi_syncml_is_first_sync(SYNCML_DB_TASK)) )
        {
            /* sync all records */
            g_syncml_sync_context.count = mmi_tdl_get_total_task_index(g_syncml_sync_context.luid_buf);

        }
        else if(mmi_syncml_is_first_sync(SYNCML_DB_TASK))
        {
            g_syncml_sync_context.count = 0;
        }
        else
        {
            g_syncml_sync_context.count = mmi_syncml_query_change_log(g_syncml_sync_context.operation, g_syncml_sync_context.database, g_syncml_sync_context.luid_buf);

        }
    }	
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    else if (g_syncml_sync_context.database == SYNCML_DB_NOTE) /* tdl */
    {
        if ( g_syncml_sync_context.operation == SYNCML_RECORD_ALL ||
            (g_syncml_sync_context.operation == SYNCML_RECORD_ADD && mmi_syncml_is_first_sync(SYNCML_DB_NOTE)) )
        {
            /* sync all records */
            g_syncml_sync_context.count = mmi_note_get_total_record_index_array(g_syncml_sync_context.luid_buf);

        }
        else if(mmi_syncml_is_first_sync(SYNCML_DB_NOTE))
        {
            g_syncml_sync_context.count = 0;
        }
        else
        {
            g_syncml_sync_context.count = mmi_syncml_query_change_log(g_syncml_sync_context.operation, g_syncml_sync_context.database, g_syncml_sync_context.luid_buf);

        }
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
#ifdef __SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __SYNCML_SYNC_EMAIL_SUPPORT__ */ 
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    mmi_syncml_query_luid_list_res_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_query_luid_list_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_query_luid_list_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_query_luid_list_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dataPtr =
        (mmi_syncml_query_luid_list_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_query_luid_list_res_req_struct));

    dataPtr->luid = g_syncml_sync_context.luid_buf;
    dataPtr->count = g_syncml_sync_context.count;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_QUERY_LOG, g_syncml_sync_context.operation, dataPtr->count);

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_RES_REQ, (oslParaType*) dataPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_record_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_get_record_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_get_record_req_ind_struct *local_data = (mmi_syncml_get_record_req_ind_struct*) info;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_GET_RECORD, local_data->luid, local_data->database_type);

    if (!mmi_syncml_is_sync_now())
    {
        return;
    }
    
    mmi_syncml_msg_match_flag = MMI_FALSE;

    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;
    g_syncml_sync_context.luid = local_data->luid;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    /* if get deletion or move, only to reponse directly without geting data actually. */
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#else
    if (g_syncml_sync_context.operation == SYNCML_RECORD_GET_DEL_NOTIFY)
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    {
        g_syncml_sync_context.result = SYNCML_OK;
        mmi_syncml_get_record_res_req();
        return;
    }

    if (local_data->database_type == SYNCML_DB_PHONEBOOK) /* phb */
    {
        srv_phb_sync_vcard(SRV_PHB_VCARD_READ, (U16 *) SYNCML_VOBJ_PATH, g_syncml_sync_context.luid, 0);
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    else if (local_data->database_type == SYNCML_DB_CALENDAR) /* cal */
    {
        g_syncml_sync_context.result = (mmi_tdl_sync_vevent(MMI_TDL_SYNCML_GET, (CHAR*) SYNCML_VOBJ_PATH, &g_syncml_sync_context.luid, 0) == MMI_TDL_SYNCML_ERR_NO_ERROR) ? SYNCML_OK : SYNCML_FAIL;
        mmi_syncml_get_record_res_req();
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    else if (local_data->database_type == SYNCML_DB_TASK) /* task */
    {
        g_syncml_sync_context.result = (mmi_tdl_sync_vtodo(MMI_TDL_SYNCML_GET, (CHAR*) SYNCML_VOBJ_PATH, &g_syncml_sync_context.luid, 0) == MMI_TDL_SYNCML_ERR_NO_ERROR) ? SYNCML_OK : SYNCML_FAIL;
        mmi_syncml_get_record_res_req();
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    else if (local_data->database_type == SYNCML_DB_NOTE) /* note */
    {
        g_syncml_sync_context.result = (mmi_note_sync_pnote(SYNCML_RECORD_GET, (CHAR*) SYNCML_VOBJ_PATH, &g_syncml_sync_context.luid, 0) == MMI_NOTE_ACTION_SUCCESS) ? SYNCML_OK : SYNCML_FAIL;
        mmi_syncml_get_record_res_req();
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
    else
    {

    }

    /* mmi_syncml_get_record_res_req(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_record_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_get_record_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_get_record_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sync finish, new sync do not start again -> set_res_req is later than finish_ind */
    if (!mmi_syncml_is_sync_now())
    {
        return;
    }

    /* sync finish, new sync start again -> set_res_req is later than finish_ind */
    if (mmi_syncml_msg_match_flag == MMI_TRUE)
    {
        return;
    }
    
    mmi_syncml_msg_match_flag = MMI_TRUE;

    dataPtr =
        (mmi_syncml_get_record_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_get_record_res_req_struct));

    dataPtr->result = g_syncml_sync_context.result;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#else    
    if (g_syncml_sync_context.operation != SYNCML_RECORD_GET_DEL_NOTIFY)
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    {
        mmi_ucs2cpy((CHAR*)dataPtr->file_path, (const CHAR*)SYNCML_VOBJ_PATH);
    }
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_GET_RECORD_RES_REQ, (oslParaType*) dataPtr, NULL);

    /* update to show the current progress */
    if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
    {
        g_mmi_syncml_cntx.contact_send_current++;
        mmi_syncml_update_progress_string(PROGRESS_CONTACT_DATASTORE_SENDING);
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    else if (g_syncml_sync_context.database == SYNCML_DB_CALENDAR)
    {
        g_mmi_syncml_cntx.calendar_send_current++;
        mmi_syncml_update_progress_string(PROGRESS_CALENDAR_DATASTORE_SENDING);
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    else if (g_syncml_sync_context.database == SYNCML_DB_TASK)
    {
        g_mmi_syncml_cntx.task_send_current++;
        mmi_syncml_update_progress_string(PROGRESS_TASK_DATASTORE_SENDING);
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    else if (g_syncml_sync_context.database == SYNCML_DB_NOTE)
    {
        g_mmi_syncml_cntx.note_send_current++;
        mmi_syncml_update_progress_string(PROGRESS_NOTE_DATASTORE_SENDING);
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clean_luid_list_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_clean_luid_list_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_clean_luid_list_req_ind_struct *local_data = (mmi_syncml_clean_luid_list_req_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_sync_now())
    {
        return;
    }

    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;

/* do not clean luid one by one, delete log file directly. 
 * Because when it is a large number , MMI will hang, MMI queue will be full.*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	if (mmi_syncml_is_device_sync())
	{
		mmi_syncml_device_clearall_change_log(g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev, local_data->database_type);
	}
	else
#endif
	{
		mmi_syncml_clearall_change_log(g_mmi_syncml_cntx.active_account, local_data->database_type);
	}
    

    mmi_syncml_clean_luid_list_res_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clean_luid_list_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_clean_luid_list_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_clean_luid_list_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dataPtr =
        (mmi_syncml_clean_luid_list_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_clean_luid_list_res_req_struct));
    dataPtr->result = SYNCML_OK;

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_RES_REQ, (oslParaType*) dataPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_record_req_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_set_record_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_set_record_req_ind_struct *local_data = (mmi_syncml_set_record_req_ind_struct*) info;

    FS_HANDLE fs_handle;
    U32 written_length;
    U16 temp_count, i, result;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__    
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_SET_RECORD, local_data->luid, local_data->operation_type, local_data->database_type);

    if (!mmi_syncml_is_sync_now())
    {
        return;
    }
    
    mmi_syncml_msg_match_flag = MMI_FALSE;

    g_syncml_sync_context.luid = (local_data->operation_type != SYNCML_RECORD_ADD) ? local_data->luid : 0xFFFF;
    g_syncml_sync_context.operation = local_data->operation_type;
    g_syncml_sync_context.database = local_data->database_type;
    g_syncml_sync_context.more_data = local_data->more_data;
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#else
    if (local_data->operation_type != SYNCML_RECORD_DELETE)
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    {
        fs_handle = FS_Open(SYNCML_VOBJ_PATH, FS_CREATE | FS_READ_WRITE);
        FS_Seek(fs_handle, 0, FS_FILE_END);

        if (local_data->data != NULL)
        {
           FS_Write(fs_handle, (void*) local_data->data, local_data->data_length, &written_length);
        }
        
        FS_Close(fs_handle);         
    }

    if (g_syncml_sync_context.more_data)
    {
        g_syncml_sync_context.result = SYNCML_OK;
        mmi_syncml_set_record_res_req();
        return;
    }

    if (local_data->database_type == SYNCML_DB_PHONEBOOK) /* phb */
    {
        if (local_data->operation_type == SYNCML_RECORD_MODIFY)
        {
            /* REPLACE: modify the record or add new record if LUID is not present */
            temp_count = srv_phb_sync_get_index_array(g_syncml_temp_luid, MAX_SYNC_ITEMS);
            for (i = 0; i < temp_count; i++)
            {
                if (g_syncml_temp_luid[i] == g_syncml_sync_context.luid)
                {
                    break;
                }
            }
            if (i == temp_count)
            {
                g_syncml_sync_context.operation = SYNCML_RECORD_ADD;
                g_syncml_sync_context.luid = 0xFFFF;
            }
        }

        srv_phb_sync_vcard(g_syncml_sync_context.operation, (U16 *) SYNCML_VOBJ_PATH, g_syncml_sync_context.luid, 
                local_data->charset);
    }
	
#if defined(__MMI_SYNCML_SYNC_CALENDAR_SUPPORT__) 
    else if (local_data->database_type == SYNCML_DB_CALENDAR )
    {
        if (local_data->operation_type == SYNCML_RECORD_MODIFY)
        {
            /* REPLACE: modify the record or add new record if LUID is not present */
            temp_count = mmi_tdl_get_total_cal_index(g_syncml_temp_luid);
            for (i = 0; i < temp_count; i++)
            {
                if (g_syncml_temp_luid[i] == g_syncml_sync_context.luid)
                {
                    break;
                }
            }
            if (i == temp_count)
            {
                g_syncml_sync_context.operation = SYNCML_RECORD_ADD;
                g_syncml_sync_context.luid = 0xFFFF;
            }
        }
        result = mmi_tdl_sync_vevent(g_syncml_sync_context.operation,
                                     (CHAR*) SYNCML_VOBJ_PATH,
                                     &g_syncml_sync_context.luid, 
                                     local_data->charset);
        switch (result)
        {
            case MMI_TDL_SYNCML_ERR_NO_ERROR:
               g_syncml_sync_context.result = SYNCML_OK;
               break;

            case MMI_TDL_SYNCML_ERR_MEMORY_FULL:
               g_syncml_sync_context.result = SYNCML_DEVICE_FULL;
               break;
               
            case MMI_TDL_SYNCML_ERR_NOT_FOUND:
              g_syncml_sync_context.result = SYNCML_NOT_FOUND;
               break;
               
            default:
               g_syncml_sync_context.result = SYNCML_FAIL;
	
			   break;
        }
        mmi_syncml_set_record_res_req();
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    else if (local_data->database_type == SYNCML_DB_TASK)
    {
        if (local_data->operation_type == SYNCML_RECORD_MODIFY)
        {
            /* REPLACE: modify the record or add new record if LUID is not present */
            temp_count = mmi_tdl_get_total_task_index(g_syncml_temp_luid);
            for (i = 0; i < temp_count; i++)
            {
                if (g_syncml_temp_luid[i] == g_syncml_sync_context.luid)
                {
                    break;
                }
            }
            if (i == temp_count)
            {
                g_syncml_sync_context.operation = SYNCML_RECORD_ADD;
                g_syncml_sync_context.luid = 0xFFFF;
            }
        }
        result = mmi_tdl_sync_vtodo(g_syncml_sync_context.operation,
                                    (CHAR*) SYNCML_VOBJ_PATH,
								   	&g_syncml_sync_context.luid, 
                				   	local_data->charset);
        switch (result)
        {
            case MMI_TDL_SYNCML_ERR_NO_ERROR:
               g_syncml_sync_context.result = SYNCML_OK;
               break;

            case MMI_TDL_SYNCML_ERR_MEMORY_FULL:
               g_syncml_sync_context.result = SYNCML_DEVICE_FULL;
               break;
               
            case MMI_TDL_SYNCML_ERR_NOT_FOUND:
              g_syncml_sync_context.result = SYNCML_NOT_FOUND;
               break;
                
            default:
               g_syncml_sync_context.result = SYNCML_FAIL;
	
			   break;
        }
        mmi_syncml_set_record_res_req();
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    else if (local_data->database_type == SYNCML_DB_NOTE)
    {
        if (local_data->operation_type == SYNCML_RECORD_MODIFY)
        {
            /* REPLACE: modify the record or add new record if LUID is not present */
            temp_count = mmi_note_get_total_record_index_array(g_syncml_temp_luid);
            for (i = 0; i < temp_count; i++)
            {
                if (g_syncml_temp_luid[i] == g_syncml_sync_context.luid)
                {
                    break;
                }
            }
            if (i == temp_count)
            {
                g_syncml_sync_context.operation = SYNCML_RECORD_ADD;
                g_syncml_sync_context.luid = 0xFFFF;
            }
        }
		
        result = mmi_note_sync_pnote(g_syncml_sync_context.operation,
                                    (CHAR*) SYNCML_VOBJ_PATH,
								   	&g_syncml_sync_context.luid, 
                				   	local_data->charset);
        switch (result)
        {
            case MMI_NOTE_ACTION_SUCCESS:
               g_syncml_sync_context.result = SYNCML_OK;
               break;

            case MMI_NOTE_ACTION_MEMORY_FULL:
               g_syncml_sync_context.result = SYNCML_DEVICE_FULL;
               break;
               
            case MMI_NOTE_ACTION_NOT_FOUND:
              g_syncml_sync_context.result = SYNCML_NOT_FOUND;
               break;
                
            default:
               g_syncml_sync_context.result = SYNCML_FAIL;
	
			   break;
        }
        mmi_syncml_set_record_res_req();
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    else
    {
        MMI_ASSERT(!"Error data base name");
    }

    /* mmi_syncml_set_record_res_req(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_record_res_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_set_record_res_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_set_record_res_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sync finish, new sync do not start again -> set_res_req is later than finish_ind */
    if (!mmi_syncml_is_sync_now())
    {
        return;
    }

    /* sync finish, new sync start again -> set_res_req is later than finish_ind */
    if (mmi_syncml_msg_match_flag == MMI_TRUE)
    {
        return;
    }

    mmi_syncml_msg_match_flag = MMI_TRUE;

    dataPtr =
        (mmi_syncml_set_record_res_req_struct*) OslConstructDataPtr(sizeof(mmi_syncml_set_record_res_req_struct));

    dataPtr->result = g_syncml_sync_context.result;
    dataPtr->luid = g_syncml_sync_context.luid;
    dataPtr->mmi_oprt = g_syncml_sync_context.operation;

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_SET_RECORD_RES_REQ, (oslParaType*) dataPtr, NULL);

    /* sync report */
    if (g_syncml_sync_context.result == SYNCML_OK)
    {
    	if (g_syncml_sync_context.more_data == 0)
    	{
            if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
            {
                g_mmi_syncml_cntx.contact_ok_cnt[g_syncml_sync_context.operation - SYNCML_RECORD_ADD]++;
            }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
            else if (g_syncml_sync_context.database == SYNCML_DB_CALENDAR)
            {
                g_mmi_syncml_cntx.calendar_ok_cnt[g_syncml_sync_context.operation - SYNCML_RECORD_ADD]++;
            }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
            else if (g_syncml_sync_context.database == SYNCML_DB_TASK)
            {
                g_mmi_syncml_cntx.task_ok_cnt[g_syncml_sync_context.operation - SYNCML_RECORD_ADD]++;
            }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
            else if (g_syncml_sync_context.database == SYNCML_DB_NOTE)
            {
                g_mmi_syncml_cntx.note_ok_cnt[g_syncml_sync_context.operation - SYNCML_RECORD_ADD]++;
            }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
            else
            {
                /* other database*/
            }
        }
    }
    else if (g_syncml_sync_context.result != SYNCML_NOT_FOUND)
    {
        if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
        {
            g_mmi_syncml_cntx.contact_ng_cnt++;
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        else if (g_syncml_sync_context.database == SYNCML_DB_CALENDAR)
        {
            g_mmi_syncml_cntx.calendar_ng_cnt++;
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        else if (g_syncml_sync_context.database == SYNCML_DB_TASK)
        {
            g_mmi_syncml_cntx.task_ng_cnt++;
        }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        else if (g_syncml_sync_context.database == SYNCML_DB_NOTE)
        {
            g_mmi_syncml_cntx.note_ng_cnt++;
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
        else
        {
            /* other database*/
        }
    }

    if (g_syncml_sync_context.more_data == 0)
    {
        FS_Delete(SYNCML_VOBJ_PATH);
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

        if (g_syncml_sync_context.database == SYNCML_DB_PHONEBOOK)
        {
            g_mmi_syncml_cntx.contact_recv_current++;
            mmi_syncml_update_progress_string(PROGRESS_CONTACT_DATASTORE_RECEIVED);
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        else if (g_syncml_sync_context.database == SYNCML_DB_CALENDAR)
        {
            g_mmi_syncml_cntx.calendar_recv_current++;
            mmi_syncml_update_progress_string(PROGRESS_CALENDAR_DATASTORE_RECEIVED);
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        else if (g_syncml_sync_context.database == SYNCML_DB_TASK)
        {
            g_mmi_syncml_cntx.task_recv_current++;
            mmi_syncml_update_progress_string(PROGRESS_TASK_DATASTORE_RECEIVED);
        }       
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        else if (g_syncml_sync_context.database == SYNCML_DB_NOTE)
        {
            g_mmi_syncml_cntx.note_recv_current++;
            mmi_syncml_update_progress_string(PROGRESS_NOTE_DATASTORE_RECEIVED);
        }       
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
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
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_progress_info_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_progress_info_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_progress_info_ind_struct *dataPtr = (mmi_syncml_progress_info_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_PROGRESSION_INFO, dataPtr->progress_info);

    if (dataPtr->progress_info <= PROGRESS_SESSION_DONE 
        && dataPtr->progress_info >= PROGRESS_LINK_ESTABLISHED)
    {
        /* do not handle these progress */
        return;
    }

    /*  get numberofchanges and sending progress info*/
    switch (dataPtr->progress_info)
    {
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    	case PROGRESS_CALENDAR_LOCAL_NOC:
			g_mmi_syncml_cntx.calendar_send_noc = dataPtr->numberofchange;
			return;
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        case PROGRESS_TASK_LOCAL_NOC:
            g_mmi_syncml_cntx.task_send_noc = dataPtr->numberofchange;
            return;
#endif /*__MMI_SYNCML_SYNC_TASK_SUPPORT__*/
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        case PROGRESS_NOTE_LOCAL_NOC:
            g_mmi_syncml_cntx.note_send_noc = dataPtr->numberofchange;
            return;
#endif /*__MMI_SYNCML_SYNC_NOTE_SUPPORT__*/
        case PROGRESS_CONTACT_LOCAL_NOC:
            g_mmi_syncml_cntx.contact_send_noc = dataPtr->numberofchange;
            return;
            
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */     

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        case PROGRESS_CALENDAR_REMOTE_NOC:
            g_mmi_syncml_cntx.calendar_recv_noc = dataPtr->numberofchange;
            return;
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        case PROGRESS_TASK_REMOTE_NOC:
            g_mmi_syncml_cntx.task_recv_noc = dataPtr->numberofchange;
            return;
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        case PROGRESS_NOTE_REMOTE_NOC:
            g_mmi_syncml_cntx.note_recv_noc = dataPtr->numberofchange;
            return;
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
        case PROGRESS_CONTACT_REMOTE_NOC:
            g_mmi_syncml_cntx.contact_recv_noc = dataPtr->numberofchange;
            return;

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
        
        default:
            break;
            
    }
    
    mmi_syncml_update_progress_string(dataPtr->progress_info);

    /* sync report */
    if (dataPtr->progress_info == PROGRESS_CONTACT_DATASTORE_FAILED)
    {
        mmi_syncml_set_database_sync_fail(SYNCML_DB_PHONEBOOK);
    }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (dataPtr->progress_info == PROGRESS_CALENDAR_DATASTORE_FAILED)
    {
        mmi_syncml_set_database_sync_fail(SYNCML_DB_CALENDAR);
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (dataPtr->progress_info == PROGRESS_TASK_DATASTORE_FAILED)
    {
        mmi_syncml_set_database_sync_fail(SYNCML_DB_TASK);
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (dataPtr->progress_info == PROGRESS_NOTE_DATASTORE_FAILED)
    {
        mmi_syncml_set_database_sync_fail(SYNCML_DB_NOTE);
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_dummy_finish_sync
 * DESCRIPTION
 *  send remonte info to syncml, if no such record, all the devinfo is empty
 * PARAMETERS
 *  U8			status			1->accept, 0->reject
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_dummy_finish_sync(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_finish_sync_ind_struct *local_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_is_sync_now())
    {
        local_data = (mmi_syncml_finish_sync_ind_struct *)OslMalloc(sizeof(mmi_syncml_finish_sync_ind_struct));
        local_data->result = SYNCML_FAIL;
        
        mmi_popup_display_simple(
            (WCHAR*)get_string(str_id), 
            MMI_EVENT_FAILURE, 
            GRP_ID_ROOT, 
            NULL);             

        mmi_frm_group_close(GRP_ID_SYNC_START);
        
#if defined(__MMI_NCENTER_SUPPORT__)
		mmi_syncml_ncenter_sync_finish(local_data);
#endif
		
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
        if (mmi_syncml_is_device_or_pc_sync())
        {
            mmi_syncml_common_finish_hdlr();
        }
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */
        
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        if (mmi_syncml_is_device_sync())
        {
            mmi_syncml_device_finish((void*)local_data);
        }
        else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
        {
            mmi_syncml_finish_sync_hdlr(local_data);
        }

        OslMfree(local_data);
        
        mmi_syncml_restore_context();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_finish_sync_ind
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_finish_sync_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_finish_sync_ind_struct *local_data = (mmi_syncml_finish_sync_ind_struct*) info;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_syncml_is_sync_now())
    {
        return;
    }
    
    mmi_frm_group_close(GRP_ID_SYNC_START);

#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
    mmi_syncml_set_status_icon(MMI_FALSE);
#endif 
    
    /* delete in case of abnormal abort */
    FS_Delete(SYNCML_VOBJ_PATH);
    
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
#endif

#if defined(__MMI_NCENTER_SUPPORT__)
	mmi_syncml_ncenter_sync_finish(local_data);
#endif

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
    if (mmi_syncml_is_device_or_pc_sync())
    {
        mmi_syncml_common_finish_hdlr();
    }
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

    /* whether show report screen */
    if (!g_mmi_syncml_cntx.abort_by_other)
    {
        mmi_syncml_report_screen_hdlr((void*)local_data);
    }

	/* Update anchor and global status variable */
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	if (mmi_syncml_is_device_sync() && local_data->f_is_device)
	{
		mmi_syncml_device_finish((void*)local_data);
	}
    else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    /* remote server and pc sync use the same api to handle finish phase*/
	{
        mmi_syncml_finish_sync_hdlr(local_data);
	}

	if (MMI_TRUE
	#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		&& (!mmi_syncml_is_device_sync()) 
	#endif
	#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
		&& (!mmi_syncml_is_pc_sync()) 
	#endif
	)
	{
		mmi_syncml_cbm_brearer_release();
	}
	
    mmi_syncml_restore_context();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_ps_busy_ind_hdlr
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_ps_busy_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_syncml_dummy_finish_sync(STR_ID_SYNC_CODE_FORBIDDEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_restore_context
 * DESCRIPTION
 *  restore g_mmi_syncml_cntx to init value.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_restore_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

	g_mmi_syncml_cntx.is_sync_state = MMI_FALSE;

    g_mmi_syncml_cntx.abort_state = MMI_FALSE;
    g_mmi_syncml_cntx.sync_progress = 0xFF;
    g_mmi_syncml_cntx.abort_by_other = MMI_FALSE;
    mmi_syncml_msg_match_flag = MMI_TRUE;
	
    g_mmi_syncml_cntx.contact_sync_state = MMI_FALSE;
    g_mmi_syncml_cntx.contact_send_noc = 0;
    g_mmi_syncml_cntx.contact_send_current = 0;
    g_mmi_syncml_cntx.contact_recv_noc = 0;
    g_mmi_syncml_cntx.contact_recv_current = 0;
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	g_mmi_syncml_cntx.calendar_sync_state = MMI_FALSE;
	g_mmi_syncml_cntx.calendar_send_noc = 0;
    g_mmi_syncml_cntx.calendar_send_current = 0;
    g_mmi_syncml_cntx.calendar_recv_noc = 0;
    g_mmi_syncml_cntx.calendar_recv_current = 0;
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	g_mmi_syncml_cntx.task_sync_state = MMI_FALSE;
	g_mmi_syncml_cntx.task_send_noc = 0;
    g_mmi_syncml_cntx.task_send_current = 0;
    g_mmi_syncml_cntx.task_recv_noc = 0;
    g_mmi_syncml_cntx.task_recv_current = 0;
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	g_mmi_syncml_cntx.note_sync_state = MMI_FALSE;
	g_mmi_syncml_cntx.note_send_noc = 0;
    g_mmi_syncml_cntx.note_send_current = 0;
    g_mmi_syncml_cntx.note_recv_noc = 0;
    g_mmi_syncml_cntx.note_recv_current = 0;
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
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_finish_sync_hdlr
 * DESCRIPTION
 *  Finish phase handler
 * PARAMETERS
 *  local_data        [IN]            finish struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_finish_sync_hdlr(mmi_syncml_finish_sync_ind_struct *local_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 account_index;
    mmi_syncml_account_struct *temp_account = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(local_data != NULL);
	
#ifdef	__MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	{
		account_index = g_mmi_syncml_cntx.active_account - 1;
	}

    if (SYNCML_GET_SYNC_STATUS(local_data->result) == SYNCML_OK)
    {
        /* If sync success, need update anchor */
        temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
        mmi_syncml_read_account_from_nvram((U8)(account_index + 1), (void*)temp_account);
        
        /* update the last anchor because of sync completion */
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
        {
			
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_PHONEBOOK))
			{
				g_mmi_syncml_cntx.last_phb_anchor[account_index] = g_mmi_syncml_cntx.next_phb_anchor;

                /* will be updated into nvram */
				temp_account->last_phb_anchor = g_mmi_syncml_cntx.next_phb_anchor;
                
				memcpy(g_mmi_syncml_cntx.svr_contact_ok_cnt, 
					local_data->svr_contact_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_contact_ok_cnt));
				g_mmi_syncml_cntx.svr_contact_ng_cnt = local_data->svr_contact_ng_cnt;
                
				/* For we write change log when receiving data from server,
				* it need clear change log here to avoid log is remained after sync succeed.
				* ex, when in local no data change to send, change log can not be cleared automatically by protocol.
				*/ 
				mmi_syncml_clearall_change_log((U8)(account_index + 1), SYNCML_DB_PHONEBOOK);	
            }
			else /* If DB failed, don't update anchor */
			{
				g_mmi_syncml_cntx.next_phb_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index];
			}
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR)
        {
			
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_CALENDAR))
			{
				g_mmi_syncml_cntx.last_cal_anchor[account_index] = g_mmi_syncml_cntx.next_cal_anchor;
				
				temp_account->last_cal_anchor = g_mmi_syncml_cntx.next_cal_anchor;
                
				memcpy(g_mmi_syncml_cntx.svr_calendar_ok_cnt, 
					local_data->svr_calendar_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_calendar_ok_cnt));
				g_mmi_syncml_cntx.svr_calendar_ng_cnt = local_data->svr_calendar_ng_cnt;
				mmi_syncml_clearall_change_log((U8)(account_index + 1), SYNCML_DB_CALENDAR);	
            }
			else /* If calendar database failed, don't update */
			{
				g_mmi_syncml_cntx.next_cal_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index];
			}
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
		
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
        {
			
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_TASK))
			{
				g_mmi_syncml_cntx.last_task_anchor[account_index] = g_mmi_syncml_cntx.next_task_anchor;
       
				temp_account->last_task_anchor = g_mmi_syncml_cntx.next_task_anchor;
                
				memcpy(g_mmi_syncml_cntx.svr_task_ok_cnt, 
					local_data->svr_task_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_task_ok_cnt));
				g_mmi_syncml_cntx.svr_task_ng_cnt = local_data->svr_task_ng_cnt;
				mmi_syncml_clearall_change_log((U8)(account_index + 1), SYNCML_DB_TASK);	
			}	
			else /* If task failed, don't update anchor */
			{
				g_mmi_syncml_cntx.next_task_anchor = g_mmi_syncml_cntx.last_task_anchor[account_index];
			}
		}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_NOTE)
        {
			
			if (!(g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_NOTE))
			{
				g_mmi_syncml_cntx.last_note_anchor[account_index] = g_mmi_syncml_cntx.next_note_anchor;
       
				temp_account->last_note_anchor = g_mmi_syncml_cntx.next_note_anchor;
                
				memcpy(g_mmi_syncml_cntx.svr_note_ok_cnt, 
					local_data->svr_note_ok_cnt, 
					sizeof(g_mmi_syncml_cntx.svr_note_ok_cnt));
				g_mmi_syncml_cntx.svr_note_ng_cnt = local_data->svr_note_ng_cnt;
				mmi_syncml_clearall_change_log((U8)(account_index + 1), SYNCML_DB_NOTE);	
			}	
			else /* If task failed, don't update anchor */
			{
				g_mmi_syncml_cntx.next_note_anchor = g_mmi_syncml_cntx.last_note_anchor[account_index];
			}
		}
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
		
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
		if (!mmi_syncml_is_pc_sync())
#endif
        {
			
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__  */
        }

		if (
	#ifdef  __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__	
/* under construction !*/
	#endif	
	    	MMI_TRUE
			)
		{
            mmi_syncml_write_account_to_nvram((U8)(account_index + 1), (void*)temp_account);
		}

        if (temp_account != NULL)
        {
            OslMfree(temp_account);
        }   
        
    }/* if (SYNCML_GET_SYNC_STATUS(local_data->result) == SYNCML_OK) */

    /* sync fail */
    else
    {
        mmi_frm_group_close(GRP_ID_SYNC_START);
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
        {
            g_mmi_syncml_cntx.next_phb_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index];
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR)
        {
            g_mmi_syncml_cntx.next_cal_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index];
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
        {
            g_mmi_syncml_cntx.next_task_anchor = g_mmi_syncml_cntx.last_task_anchor[account_index];
        }		
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_NOTE)
        {
            g_mmi_syncml_cntx.next_note_anchor = g_mmi_syncml_cntx.last_note_anchor[account_index];
        }		
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__  */        
    }
	
    mmi_syncml_update_sync_log_to_nvram();
	
#if defined(__MMI_SYNCML_SYNC_CALENDAR_SUPPORT__) || defined(__MMI_SYNCML_SYNC_TASK_SUPPORT__)
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR || 
		g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
    {
        mmi_syncml_enable_alarm(); /* enable alarm */
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
	
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__     
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
	
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
	if (mmi_syncml_is_pc_sync())
	{
        mmi_syncml_pc_sync_finish(local_data->result);
	}
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
	
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    if (g_mmi_syncml_cntx.app_sync_menu)
    {
        if ((SYNCML_GET_SYNC_STATUS(local_data->result) != SYNCML_OK) 
            || ((SYNCML_GET_SYNC_STATUS(local_data->result) == SYNCML_OK)
            && !g_mmi_syncml_cntx.sync_report_status[account_index]))
        {	
            mmi_syncml_app_sync_finish_hdlr(account_index);            
        }
    }   
#endif /*__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__*/
 	
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_first_sync
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  database        [IN]            The first sync
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_syncml_is_first_sync(U8 database)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 account_index = g_mmi_syncml_cntx.active_account - 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	if (mmi_syncml_is_device_sync())
	{
		if (database == SYNCML_DB_PHONEBOOK)
		{
			if (g_mmi_syncml_cntx.dev_cntx_ptr->setting_ptr->last_phb_anchor[g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev - 1] == 0)
			{
				return MMI_TRUE;
			}
		}
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
		else if (database == SYNCML_DB_CALENDAR)
		{
			if (g_mmi_syncml_cntx.dev_cntx_ptr->setting_ptr->last_cal_anchor[g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev - 1] == 0)
			{
				return MMI_TRUE;
			}
		}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
		else if (database == SYNCML_DB_TASK)
		{
			if (g_mmi_syncml_cntx.dev_cntx_ptr->setting_ptr->last_task_anchor[g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev - 1] == 0)
			{
				return MMI_TRUE;
			}
		}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        else if (database == SYNCML_DB_NOTE)
        {
            if (g_mmi_syncml_cntx.dev_cntx_ptr->setting_ptr->last_note_anchor[g_mmi_syncml_cntx.dev_cntx_ptr->selected_dev - 1] == 0)
            {
                return MMI_TRUE;
            }
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

		return MMI_FALSE;
	}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

    /* pc sync and common sync */
	if (database == SYNCML_DB_PHONEBOOK)
	{
		if (g_mmi_syncml_cntx.last_phb_anchor[account_index] == 0)
		{
			return MMI_TRUE;
		}
	}
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	else if(database == SYNCML_DB_CALENDAR)
	{
		if (g_mmi_syncml_cntx.last_cal_anchor[account_index] == 0)
		{
			return MMI_TRUE;
		}
	}
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	else if(database == SYNCML_DB_TASK)
	{
		if (g_mmi_syncml_cntx.last_task_anchor[account_index] == 0)
		{
			return MMI_TRUE;
		}
	}
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	else if(database == SYNCML_DB_NOTE)
	{
		if (g_mmi_syncml_cntx.last_note_anchor[account_index] == 0)
		{
			return MMI_TRUE;
		}
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
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __SYNCML_SYNC_EMAIL_SUPPORT__ */

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_sync_rsp
 * DESCRIPTION
 *  Callback for phonebook access
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_phb_sync_rsp(U16 phb_result, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    if (g_mmi_syncml_cntx.sync_type[g_mmi_syncml_cntx.active_account - 1] == MMI_SYNCML_TYPE_RESTORE 
            && mmi_syncml_is_phb_sync_now() == MMI_FALSE)
    {
        if (phb_result == SRV_PHB_SYNC_SUCCESS)
        {
            /* delete phb for RESTORE sync type */
            mmi_syncml_perform_delete_phb_one_by_one();
        }
        else
        {
            mmi_popup_display_simple(
                (WCHAR*)get_string(STR_GLOBAL_UNFINISHED), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);              
            mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
        }
        return;
    }
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    switch (phb_result)
    {
        case SRV_PHB_SYNC_SUCCESS:
           g_syncml_sync_context.result = SYNCML_OK;
           break;

        case SRV_PHB_SYNC_STORAGE_FULL:
           g_syncml_sync_context.result = SYNCML_DEVICE_FULL;
           break;
           
        case SRV_PHB_SYNC_NOT_FOUND:
           g_syncml_sync_context.result = SYNCML_NOT_FOUND;
           break;
            
        default:
           g_syncml_sync_context.result = SYNCML_FAIL;
           break;
    }

    if (g_syncml_sync_context.operation == SYNCML_RECORD_ADD)
    {
        g_syncml_sync_context.luid = store_index;
    }
    if (g_syncml_sync_context.operation == SYNCML_RECORD_GET)
    {
        mmi_syncml_get_record_res_req();
    }
    else
    {
        mmi_syncml_set_record_res_req();
    }
}


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
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
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
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */
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
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
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
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */            
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

#endif /* __SYNCML_SUPPORT__ */
