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
 *    SyncMLPcsync.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is pc sync related info
 *
 * Author:
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__

#include "bt_a2dp_base_struct.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_syncml_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "ps_public_enum.h"
#include "App_mine.h"
#include "PhbSrvGprot.h"
#include "TodolistGProt.h"
#include "BTMMIScrGprots.h"
#include "BtcmCuiGprot.h"
#include "BtcmSrvGprot.h"
#include "UcmSrvGprot.h"
#include "mmi2syncml_struct.h"
#include "BTMMISCOPathGProts.h"
#include "Conversions.h"
#include "SyncMLGProt.h"
#include "SyncMLDef.h"
#include "SyncMLStruct.h"
#include "SyncMLProt.h"
#include "NoteGprot.h"

/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static void mmi_syncml_pc_sync_pre_check_return(U8 state);
static void mmi_syncml_pc_sync_select_device_hdlr(cui_event_bt_cm_device_select_result_struct* event);


/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/


/*****************************************************************************
 * Function definition
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_init
 * DESCRIPTION
 *  Pc sync ini function
 * PARAMETERS
 *  Void          
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_pc_sync_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
    g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_entry_sync_confirm
 * DESCRIPTION
 *  function whether pc sync or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        MMI_TRUE:yes       MMI_FALSE:no
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_pc_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_cntx.is_pc_sync;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_entry_bt_select_cui
 * DESCRIPTION
 *  Enter device selection screen if selected account is pcaccount, 
 *  three situation will enter here:
 *  1- normal entry sync
 *  2- app entry sync
 *  3- regular sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_entry_bt_select_cui(mmi_id parent_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    mmi_id bt_cui_gid;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 	   
    bt_cui_gid = cui_bt_device_select_screen_create(parent_id);

    if (bt_cui_gid != GRP_ID_INVALID)
    {
        cui_bt_device_select_screen_set_mask(bt_cui_gid, 0xFFFFFFFF, 0);
        
        cui_bt_device_select_screen_set_option_flag(
                                            bt_cui_gid, 
                                            CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT);
        
        cui_bt_device_select_screen_run(bt_cui_gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_bt_sel_cui_proc
 * DESCRIPTION
 *  BT CUI process function
 * PARAMETERS
 *  mmi_event_struct *event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_syncml_pc_sync_bt_sel_cui_proc(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    cui_event_bt_cm_device_select_result_struct *bt_sel_evt
        = (cui_event_bt_cm_device_select_result_struct*)event;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
    switch(event->evt_id)
    {
        case EVT_ID_CUI_BT_CM_DEVICE_SELECT:
            
            /* parent_id for GRP_ID_SYNC_PRE_CHECK */
            g_mmi_syncml_cntx.temp_gid = (mmi_id)(U32)mmi_frm_group_get_user_data(GRP_ID_SYNC_PRE_CHECK);

            cui_bt_device_select_screen_close(bt_sel_evt->gid);

            /* should close pre_check, due to editor group exist */
            mmi_frm_group_close(GRP_ID_SYNC_PRE_CHECK);
            
            mmi_syncml_pc_sync_select_device_hdlr(bt_sel_evt);
             
            break;
            
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_finish
 * DESCRIPTION
 *  Handle pc sync completation
 * PARAMETERS
 *  sync_result         [IN]            the result for sync
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_finish(U32 sync_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_syncml_enable_alarm();
    
    /* unsuccessfull/successful and no sync report*/
    if ((SYNCML_GET_SYNC_STATUS(sync_result) != SYNCML_OK) 
        || ((SYNCML_GET_SYNC_STATUS(sync_result) == SYNCML_OK)
        && !g_mmi_syncml_cntx.sync_report_status[g_mmi_syncml_cntx.active_account - 1]))
    {   
        g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE; 
        g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] = g_mmi_syncml_cntx.phn_app_to_sync;     
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_start
 * DESCRIPTION
 *  Start pc sync 
 * PARAMETERS
 *  *imei           [IN]            imei
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_start_sync(U8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_syncml_device_get_curr_role() == MMI_SYNCML_DEV_ROLE_A)
    {
        g_mmi_syncml_cntx.is_pre_sync = 0;
         
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
        mmi_syncml_set_status_icon(MMI_TRUE);
#endif 
        mmi_bt_suppress_profile_popup(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, MMI_TRUE);

        g_mmi_syncml_cntx.phn_app_to_sync = g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1];
        
        mmi_syncml_pc_sync_start_sync_req(imei);
    }
    else if (mmi_syncml_device_get_curr_role() == MMI_SYNCML_DEV_ROLE_B)
    {    
        strcpy((CHAR*)g_mmi_syncml_common_cntx.imei, (const CHAR*)imei);  
         
        mmi_syncml_device_remoteinfo_confirm_check();
    }
    else
    {
        MMI_ASSERT(!"[Sycnml]Wrong role");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_check_account
 * DESCRIPTION
 *  check whether exist matchable profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_check_account(void)
{
    /*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/ 
    mmi_syncml_account_struct *temp_account = NULL;
    U8 i;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
    /* Search for the matchable profile */     
    for (i = 0; i < MMI_MAX_SYNCML_ACCOUNTS ; i++)
    {
        mmi_syncml_read_account_from_nvram((U8)(i + 1), (void *)temp_account);
        
        if ((temp_account->transport_type == MMI_SYNCML_TRANS_TYPE_BT) &&
            strcmp((CHAR*)&temp_account->server_address, (CHAR*)&g_mmi_syncml_common_cntx.remote_uri) == 0)
        {            
            g_mmi_syncml_cntx.active_account = i + 1;
            break;
        }
        else
        {
            g_mmi_syncml_cntx.active_account = 0;
        }
    }

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }    

    if (g_mmi_syncml_cntx.active_account == 0)
    {
		/*
		 * Wen, Start
		 *    1. Should delete confirm screen;
		 *	  2. A popup to tell the result that there is no profile which 
		 *		 allow to sync via pc
		 *	  3. restore the original data
		 *    4. A better solution maybe that if there is not proper profile, 
		 *       the confirm screen should not be popuped.
		 */

		mmi_popup_display_simple(
			(WCHAR*)get_string(STR_ID_SYNC_NO_PROFILE), 
			MMI_EVENT_FAILURE, 
			GRP_ID_ROOT, 
			NULL); 
        
        g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
        g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;
        
        mmi_syncml_pc_sync_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
        
        return;
    }  
  
    g_mmi_syncml_cntx.phn_app_to_sync = g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1];
    g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] = 0;
       
    mmi_syncml_get_imei_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_yes
 * DESCRIPTION
 *  accept sync request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_syncml_pc_sync_pre_check();
    
    mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_pre_check
 * DESCRIPTION
 *  reject pc sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
    g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;
    g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] = g_mmi_syncml_cntx.phn_app_to_sync; 
    
    mmi_syncml_pc_sync_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
    mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_pre_check
 * DESCRIPTION
 *  check some status before pc sync start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL result; /*BT concurrency */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    if (mmi_syncml_device_get_curr_role() == MMI_SYNCML_DEV_ROLE_B)
    {
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

        if (!mmi_syncml_is_phb_ready())
        {
            /* phonebook busy */
  			mmi_popup_display_simple(
				(WCHAR*)get_string(STR_ID_SYNC_PHB_BUSY), 
				MMI_EVENT_FAILURE, 
				GRP_ID_ROOT, 
				NULL);          
            mmi_syncml_pc_sync_pre_check_return(MMI_SYNCML_DEVICE_ERROR_PRE_CHECK);
            return;
        }   
    
        mmi_syncml_pc_sync_pre_check_return(MMI_SYNCML_DEVICE_ERROR_SUCCESS);
        mmi_syncml_group_entry_sync_start(GRP_ID_ROOT);           
    }
    else
    {
    	CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN + 1];
		
        /* get local device name from bt cm */
	    srv_bt_cm_get_dev_name(
	        &g_mmi_syncml_common_cntx.remote_bt_addr,
	        (MAX_SYNCML_DEV_NAME_LEN + 1), 
	        (U8*)name_buff);

	    if (strlen(name_buff))
	    {
	        /* Device name from CM is utf8 */
	        mmi_chset_utf8_to_ucs2_string(
	            (U8*)g_mmi_syncml_common_cntx.remote_dev_name, 
	            (MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH, 
	            (U8*)name_buff);
	    }
		
        g_mmi_syncml_common_cntx.cm_conn_id = srv_bt_cm_start_conn(
					MMI_FALSE,
					SRV_BT_CM_SYNCML_DEV_PROFILE_UUID,
                    &g_mmi_syncml_common_cntx.remote_bt_addr,
                    name_buff);
		
        if (g_mmi_syncml_common_cntx.cm_conn_id < 0)
        {
			mmi_popup_display_simple(
				(WCHAR*)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
				MMI_EVENT_FAILURE, 
				GRP_ID_ROOT, 
				NULL);

            mmi_syncml_pc_sync_pre_check_return(MMI_SYNCML_DEVICE_ERROR_PRE_CHECK);
        }
        else
        {
             mmi_syncml_bt_conn_callback(g_mmi_syncml_common_cntx.remote_bt_addr);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_start_sync_req
 * DESCRIPTION
 *  send start sync message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_start_sync_req(U8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_start_sync_req_struct *data_ptr;
    applib_mime_type_struct *mime;
    mmi_syncml_account_struct *temp_account = NULL;
    U8 account_index = g_mmi_syncml_cntx.active_account - 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));
    
    mmi_syncml_read_account_from_nvram((U8)(g_mmi_syncml_cntx.active_account), (void*)temp_account);

    data_ptr =
        (mmi_syncml_start_sync_req_struct*) construct_local_para(sizeof(mmi_syncml_start_sync_req_struct), TD_CTRL|TD_RESET);

    /* also record remote bt address for conn indication */
	data_ptr->bt_addr_lap = g_mmi_syncml_common_cntx.remote_bt_addr.lap;
	data_ptr->bt_addr_uap = g_mmi_syncml_common_cntx.remote_bt_addr.uap;
	data_ptr->bt_addr_nap = g_mmi_syncml_common_cntx.remote_bt_addr.nap;
    
    strcpy((CHAR*) data_ptr->server_uri, (CHAR*) temp_account->server_address);
    strcpy((CHAR*) data_ptr->server_username, (CHAR*) temp_account->server_username);
    strcpy((CHAR*) data_ptr->server_password, (CHAR*) temp_account->server_password);
    
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_PHONEBOOK)
    {
        strcpy((CHAR*) data_ptr->contact_database_uri, (CHAR*) temp_account->contact_address);
        strcpy((CHAR*) data_ptr->contact_database_username, (CHAR*) temp_account->contact_username);
        strcpy((CHAR*) data_ptr->contact_database_password, (CHAR*) temp_account->contact_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCARD);
        if (mime)
        {
            strcpy((CHAR*) data_ptr->contact_mime_type, mime->mime_string);
        }
        data_ptr->contact_last_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index];
        data_ptr->contact_next_anchor = g_mmi_syncml_cntx.next_phb_anchor;

        g_mmi_syncml_cntx.contact_sync_state = MMI_TRUE; /* synchronizing */

        data_ptr->contact_free_id = srv_phb_get_total_contact(PHB_STORAGE_NVRAM) - srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
        data_ptr->contact_free_mem = data_ptr->contact_free_id * srv_phb_sync_get_record_size();
    }

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_CALENDAR)
    {
        strcpy((CHAR*) data_ptr->calendar_database_uri, (CHAR*) temp_account->calendar_address);
        strcpy((CHAR*) data_ptr->calendar_database_username, (CHAR*) temp_account->calendar_username);
        strcpy((CHAR*) data_ptr->calendar_database_password, (CHAR*) temp_account->calendar_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if (mime)
        {
            strcpy((CHAR*) data_ptr->calendar_mime_type, mime->mime_string);
        }
        data_ptr->calendar_last_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index];
        data_ptr->calendar_next_anchor = g_mmi_syncml_cntx.next_cal_anchor;

        g_mmi_syncml_cntx.calendar_sync_state = MMI_TRUE; /* synchronizing */
        mmi_syncml_disable_alarm(); /* disable alarm */

        data_ptr->calendar_free_id = NUM_OF_CAL - mmi_tdl_get_total_cal_index(NULL);
        data_ptr->calendar_free_mem = data_ptr->calendar_free_id * NVRAM_TODO_LIST_RECORD_SIZE;
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_TASK)
    {
        strcpy((CHAR*) data_ptr->task_database_uri, (CHAR*) temp_account->task_address);
        strcpy((CHAR*) data_ptr->task_database_username, (CHAR*) temp_account->task_username);
        strcpy((CHAR*) data_ptr->task_database_password, (CHAR*) temp_account->task_password);
        mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
        if (mime)
        {
            strcpy((CHAR*) data_ptr->task_mime_type, mime->mime_string);
        }
        data_ptr->task_last_anchor = g_mmi_syncml_cntx.last_task_anchor[account_index];
        data_ptr->task_next_anchor = g_mmi_syncml_cntx.next_task_anchor;

        g_mmi_syncml_cntx.task_sync_state = MMI_TRUE; /* synchronizing */
        mmi_syncml_disable_alarm(); /* disable alarm */

        data_ptr->task_free_id = NUM_OF_TASK - mmi_tdl_get_total_task_index(NULL);
        data_ptr->task_free_mem = data_ptr->task_free_id * NVRAM_TODO_LIST_RECORD_SIZE;
    }	
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (g_mmi_syncml_cntx.app_to_sync[account_index] & SYNCML_DB_NOTE)
        {
            strcpy((CHAR*) data_ptr->note_database_uri, (CHAR*) temp_account->note_address);
            strcpy((CHAR*) data_ptr->note_database_username, (CHAR*) temp_account->note_username);
            strcpy((CHAR*) data_ptr->note_database_password, (CHAR*) temp_account->note_password);
            mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_PLAIN);
            if (mime)
            {
                strcpy((CHAR*) data_ptr->note_mime_type, mime->mime_string);
            }
            data_ptr->note_last_anchor = g_mmi_syncml_cntx.last_note_anchor[account_index];
            data_ptr->note_next_anchor = g_mmi_syncml_cntx.next_note_anchor;
    
            g_mmi_syncml_cntx.note_sync_state = MMI_TRUE; /* synchronizing */
            mmi_syncml_disable_alarm(); /* disable alarm */
    
            data_ptr->note_free_id = MMI_MAX_NOTE_ITEM - mmi_note_get_total_record_index_array(NULL);
            data_ptr->note_free_mem = data_ptr->note_free_id * mmi_note_get_record_size();
        }   
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

	/* Local IMEI */
    memcpy(&data_ptr->imei[0], "IMEI:", 5);
    memcpy(&data_ptr->imei[5], imei, 15);
    data_ptr->imei[20] = 0;

#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
    if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_BACKUP)
    {
        data_ptr->sync_type = SYNCML_SYNC_CLIENT_ONE_WAY_REFRESH;
    }
    else if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_RESTORE)
    {
        data_ptr->sync_type = SYNCML_SYNC_SERVER_ONE_WAY_REFRESH;
    }
    else if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_EXPORT)
    {
        data_ptr->sync_type = SYNCML_SYNC_CLIENT_ONE_WAY_SYNC;
    }
    else if (g_mmi_syncml_cntx.sync_type[account_index] == MMI_SYNCML_TYPE_IMPORT)
    {
        data_ptr->sync_type = SYNCML_SYNC_SERVER_ONE_WAY_SYNC;
    }
    else
    {
        data_ptr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;
    }
#else /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    data_ptr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;

#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    data_ptr->transport_type = SYNCML_TRANS_BT;

    g_mmi_syncml_cntx.abort_state = MMI_FALSE;

    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_START_SYNC_REQ, (oslParaType*) data_ptr, NULL);

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_selection_device_callback
 * DESCRIPTION
 *  callback for selecting a device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_pc_sync_select_device_hdlr(cui_event_bt_cm_device_select_result_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (event->result)
    {
#if defined(__MMI_BT_AUDIO_SUPPORT__)
        if (mmi_bt_sco_is_connected(MMI_BT_SCO_HFP_SCO) &&
            srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            mmi_bt_popup_operation_not_allowed();
            return;
        }
#endif /* __MMI_BT_AUDIO_SUPPORT__ */
 
        g_mmi_syncml_common_cntx.remote_bt_addr.lap = event->lap;
        g_mmi_syncml_common_cntx.remote_bt_addr.nap = event->nap;
        g_mmi_syncml_common_cntx.remote_bt_addr.uap = event->uap;
        
        srv_bt_cm_get_dev_name(&g_mmi_syncml_common_cntx.remote_bt_addr, MAX_SYNCML_DEV_NAME_LEN, (U8*)name_buff);
        /* Device name from CM is utf8 */
        mmi_chset_utf8_to_ucs2_string(
            (U8*)&g_mmi_syncml_common_cntx.remote_dev_name, 
            (MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH, 
            (U8*)name_buff);

        g_mmi_syncml_cntx.is_pc_sync = MMI_TRUE;
        g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_A;

        mmi_syncml_pc_sync_pre_check();
    }     
    else
    {
        mmi_syncml_entry_sync_pre_check_return();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_entry_sync_confirm
 * DESCRIPTION
 *  response for sync request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_pc_sync_remoteinfo_ind_res(U8* imei, U8 state)
{
    /*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
    mmi_syncml_device_remoteinfo_res_struct *data_ptr;
    mmi_syncml_account_struct *temp_account = NULL;
    applib_mime_type_struct *mime;
    U8 account_index = g_mmi_syncml_cntx.active_account - 1;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    data_ptr = (mmi_syncml_device_remoteinfo_res_struct*) 
                OslConstructDataPtr(sizeof(mmi_syncml_device_remoteinfo_res_struct));
    MMI_ASSERT(data_ptr != NULL);

    /* State before STATE_SYNC_ASK_RSP is STATE_CONNECTING */
    mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_SYNC_ASK_RSP);

    data_ptr->result = state;
    
    if (state == MMI_SYNCML_DEV_SYNC_ACCEPT)
    {      
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
        mmi_syncml_set_status_icon(MMI_TRUE);
#endif        
        temp_account = (mmi_syncml_account_struct*)OslMalloc(sizeof(mmi_syncml_account_struct));

        mmi_syncml_read_account_from_nvram((U8)g_mmi_syncml_cntx.active_account, (void*)temp_account);

        if (temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_CON)
        {
            strcpy((CHAR*) data_ptr->db_info.contact_database_uri, (CHAR*) temp_account->contact_address);
            mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCARD);
            if (mime)
            {
                strcpy((CHAR*) data_ptr->db_info.contact_mime_type, mime->mime_string);
            }
            data_ptr->db_info.contact_last_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index];  
            g_mmi_syncml_cntx.next_phb_anchor = g_mmi_syncml_cntx.last_phb_anchor[account_index] + 1;  
            data_ptr->db_info.contact_next_anchor = g_mmi_syncml_cntx.next_phb_anchor;   
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        if (temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_CAL)
        {
            strcpy((CHAR*)data_ptr->db_info.calendar_database_uri, (CHAR*)temp_account->calendar_address);
            mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
            if (mime)
            {
                strcpy((CHAR*)data_ptr->db_info.calendar_mime_type, mime->mime_string);
            }
            data_ptr->db_info.calendar_last_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index];
            g_mmi_syncml_cntx.next_cal_anchor = g_mmi_syncml_cntx.last_cal_anchor[account_index] + 1;  
            data_ptr->db_info.calendar_next_anchor = g_mmi_syncml_cntx.next_cal_anchor; 
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
        
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        if (temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_TASK)
        {
            strcpy((CHAR*)data_ptr->db_info.task_database_uri, (CHAR*)temp_account->task_address);
            mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_XVCALENDAR);
            if (mime)
            {
                strcpy((CHAR*)data_ptr->db_info.task_mime_type, mime->mime_string);
            }
            data_ptr->db_info.task_last_anchor =g_mmi_syncml_cntx.last_task_anchor[account_index];
            g_mmi_syncml_cntx.next_task_anchor = g_mmi_syncml_cntx.last_task_anchor[account_index] + 1;  
            data_ptr->db_info.task_next_anchor = g_mmi_syncml_cntx.next_task_anchor; 
        }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (temp_account->account_validation & MMI_SYNCML_ACCOUNT_VALID_MASK_NOTE)
        {
            strcpy((CHAR*)data_ptr->db_info.note_database_uri, (CHAR*)temp_account->note_address);
            mime = applib_mime_type_look_up(NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_PLAIN);
            if (mime)
            {
                strcpy((CHAR*)data_ptr->db_info.note_mime_type, mime->mime_string);
            }
            data_ptr->db_info.note_last_anchor =g_mmi_syncml_cntx.last_note_anchor[account_index];
            g_mmi_syncml_cntx.next_note_anchor = g_mmi_syncml_cntx.last_note_anchor[account_index] + 1;  
            data_ptr->db_info.note_next_anchor = g_mmi_syncml_cntx.next_note_anchor; 
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
     
        memcpy(&data_ptr->imei[0], "IMEI:", 5);
        memcpy(&data_ptr->imei[5], imei, 15);
        data_ptr->imei[20] = 0;       

        if (temp_account != NULL)
        {
            OslMfree(temp_account);
        }
    }
    
    else
    {
        memset(&data_ptr->db_info, 0, sizeof(mmi_syncml_device_db_info_struct));
        mmi_syncml_device_unlock_all_db();   
    }
    
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_RES, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_pc_sync_entry_sync_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_pc_sync_pre_check_return(U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* because will entry sync now menu */
    if (MMI_SYNCML_DEV_ROLE_B == mmi_syncml_device_get_curr_role())
    {
        mmi_syncml_device_unlock_all_db();
    }
    
    if (state == MMI_SYNCML_DEVICE_ERROR_SUCCESS)
    {
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_START);
    }
    else /* Fail, Do roll back */
    {        
        if (MMI_SYNCML_DEV_ROLE_A == mmi_syncml_device_get_curr_role())
        {
            g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;
            g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
            g_mmi_syncml_cntx.is_pre_sync = 0;
            
            mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_ON);
        }
       
        if (MMI_SYNCML_DEV_ROLE_B == mmi_syncml_device_get_curr_role())
        {
            g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
            g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;
            g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] = g_mmi_syncml_cntx.phn_app_to_sync;         
            
            mmi_syncml_pc_sync_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
        }
    }
}

#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

