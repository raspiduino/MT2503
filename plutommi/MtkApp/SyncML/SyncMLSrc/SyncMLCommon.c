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
 *    SyncMLCommon.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is about common api for pc sync and device sync.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "BtcmSrvGprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_rp_srv_syncml_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalResDef.h"
#include "NotificationGprot.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "PhoneBookGprot.h"
#include "ToDoListGprot.h"
#include "AlarmFrameWorkProt.h"
#include "UcmSrvGprot.h"
#include "NoteGprot.h"
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "BTMMIScrGprots.h"
#include "CalendarGprot.h"
#include "Conversions.h"

#include "ReminderSrvGprot.h"

/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/
static U8 g_syncml_device_tmp_string[(MAX_MMI_SYNCML_DEV_STR_LEN + 1) * ENCODING_LENGTH];


/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
mmi_syncml_common_cntx_struct g_mmi_syncml_common_cntx;

#ifdef __MMI_SYNCML_DEVICE_SYNC__
extern mmi_syncml_device_sync_context_struct *const mmi_syncml_dev_p;
extern mmi_syncml_device_setting_context_struct *const mmi_syncml_dev_setting_p; 
extern mmi_syncml_device_account_context_struct *const mmi_syncml_dev_accnt_p; 
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static void mmi_syncml_device_ask_accept_conn_ind_res(U8 status);
static MMI_BOOL mmi_syncml_device_is_synchronizable(void);
static MMI_BOOL mmi_syncml_is_background_sync(void);
static void mmi_syncml_device_exit_sync_confirm(void);
static mmi_ret mmi_syncml_device_sync_confirm_leave_proc(mmi_event_struct *param);
static void mmi_syncml_device_clear_all_screen(void);
static void mmi_syncml_reject_sync_request(U8 state);
static void mmi_syncml_device_group_entry_sync_confirm(void);
static void mmi_syncml_device_bt_activate(void);
static void mmi_syncml_device_bt_deactivate(void);
static void mmi_syncml_device_bt_disconn(U32 conn_id);


/*****************************************************************************
 * Function definition
 *****************************************************************************/

static void mmi_syncml_conn_res_callback(srv_bt_cm_bt_addr *bd_addr, U32 profile_id, U32 result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (result == 1)
    {
		/* sometimes do not run here, because connection authorization is passed */
		mmi_syncml_device_clear_all_screen();
    	mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_ACCEPT);
    }
    else
    {
    #ifdef __MMI_NCENTER_SUPPORT__
		mmi_syncml_ncenter_sync_reset();
	#endif
        mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_REJECT);
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_ask_accept_conn_ind_hdlr
 * DESCRIPTION
 *  Handler for connection request
 * PARAMETERS
 *  *param          [IN]            connection info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_ask_accept_conn_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_bt_ask_accept_conn_ind_struct *ask_accept_ptr;
	CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN + 1];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_SYNCML_TRACE0(MMI_SYNCML_DEV_CONN_ASK_IND);
    MMI_ASSERT(param != NULL);
    ask_accept_ptr = (mmi_syncml_bt_ask_accept_conn_ind_struct *)param;
    
    /* bt is busy or can't sync*/
    if (!mmi_syncml_device_is_synchronizable())
    {
        mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_REJECT);
        return;
    }
    
    g_mmi_syncml_common_cntx.remote_bt_addr.lap = ask_accept_ptr->bt_addr_lap;
    g_mmi_syncml_common_cntx.remote_bt_addr.nap = ask_accept_ptr->bt_addr_nap;
    g_mmi_syncml_common_cntx.remote_bt_addr.uap = ask_accept_ptr->bt_addr_uap;

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
    else
    {
        mmi_ucs2cpy((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name, (CHAR *)ask_accept_ptr->device_name);
    }

#ifdef __MMI_SYNCML_DEVICE_SYNC__   
    mmi_ucs2cpy((CHAR *)g_mmi_syncml_common_cntx.org_dev_name, (CHAR *)g_mmi_syncml_common_cntx.remote_dev_name);
    /* Peer the device name if this device has been in device list */
    mmi_syncml_device_locate_new_dev(&g_mmi_syncml_common_cntx.remote_bt_addr, MMI_TRUE);
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

    /* If the device has been authorized, than device B will accept this sync automatically */
#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(&g_mmi_syncml_common_cntx.remote_bt_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
    {
        mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_REJECT);
    }
    else if (srv_bt_cm_get_authorize(&g_mmi_syncml_common_cntx.remote_bt_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT)
    {
    	mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK);
        mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_ACCEPT);
    }
    else
#endif /* __MMI_BT_AUTHORIZE__ */
    {
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK);
		
		g_mmi_syncml_common_cntx.cm_conn_id = srv_bt_cm_start_conn(MMI_TRUE, 
							 SRV_BT_CM_SYNCML_DEV_PROFILE_UUID,
            &g_mmi_syncml_common_cntx.remote_bt_addr,
							 name_buff);

		// need to handle error infomation
		if (g_mmi_syncml_common_cntx.cm_conn_id >= 0)
		{
			mmi_bt_authorize_ind_notify(name_buff, 
										&g_mmi_syncml_common_cntx.remote_bt_addr,
										SRV_BT_CM_SYNCML_DEV_PROFILE_UUID,
										(void*)mmi_syncml_conn_res_callback);
		}
		else
		{
			mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_REJECT);			
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_connected_ind_hdlr
 * DESCRIPTION
 *  Handler for bt connected
 * PARAMETERS
 *  *param          [IN]            bt connection info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_bt_connected_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//mmi_syncml_bt_connected_ind_struct *conn_ind_ptr;
	srv_bt_cm_bt_addr *bt_addr;
    U8 tmp_name[MAX_MMI_SYNCML_DEV_STR_LEN];
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_SYNCML_TRACE0(MMI_SYNCML_DEV_CONN_IND);
	MMI_ASSERT(param != NULL);
    
	//conn_ind_ptr = (mmi_syncml_bt_connected_ind_struct *)param;
    
	//g_mmi_syncml_common_cntx.cm_conn_id = conn_ind_ptr->cm_id;

    bt_addr = (srv_bt_cm_bt_addr *)&g_mmi_syncml_common_cntx.remote_bt_addr;
    
    if (bt_addr->lap ==0 && bt_addr->uap == 0 && bt_addr->nap == 0)
    {
        MMI_ASSERT(!"[SyncML,Device sync]ERRROR BT ADDR!");
    }

    if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_B)
    {
        /* Cut all the sync related screen */
        mmi_syncml_device_clear_all_screen();
    }  

    mmi_chset_ucs2_to_utf8_string((U8 *)tmp_name, 
        MAX_MMI_SYNCML_DEV_STR_LEN, 
        (U8 *)g_mmi_syncml_common_cntx.remote_dev_name);

    /* disable bt "SyncML service connetive" popup */
    mmi_bt_suppress_profile_popup(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, MMI_FALSE);

	srv_bt_cm_connect_ind(g_mmi_syncml_common_cntx.cm_conn_id);

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    /* 
     * If sync start from phone list and the target phone is not in device list,
     * BT does not know the cod. 
     */
    if (g_mmi_syncml_common_cntx.dev_role == MMI_SYNCML_DEV_ROLE_A && 
        mmi_frm_scrn_is_present(GRP_ID_SYNC_DEV_MAIN, SCR_ID_SYNC_DEV_PHONES_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
          srv_bt_cm_set_dev_cod(bt_addr, mmi_syncml_dev_p->accnt_ptr->dev_bt_cod);  
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

    /* disable "connection fialed" popup */
    mmi_bt_suppress_profile_popup(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_disconnected_ind_hdlr
 * DESCRIPTION
 *  Handler for bt disconnected
 * PARAMETERS
 *  *param          [IN]            bt disconnected info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_bt_disconnected_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//srv_bt_cm_bt_addr *bt_addr;
    CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN + 1]; /*BT concurrency*/
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_SYNCML_TRACE1(MMI_SYNCML_DEV_DISCONN_IND, g_mmi_syncml_common_cntx.curr_state);
	//bt_addr = &g_mmi_syncml_common_cntx.remote_bt_addr; /*BT concurrency*/

    if (g_mmi_syncml_common_cntx.cm_conn_id != MMI_SYNCML_DEV_INVALID_CONN_ID)
    {
        /* Indication to BTCM, who will show a popup "Disconnected" 
         * If sync, cnf_hdlr will be called
         */
        if (!(g_mmi_syncml_common_cntx.cm_opr_flag & SYNCML_DEV_BTCM_OPR_MASK_DISCONN))
        {
        	srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);
        }
    }
/*BT concurrency*/
    /* fail to connect */
    else
    {
        /* For obex server, use disc_ind, for client, use connect_cnf*/
        if (g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK)
        {
        	srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);
			mmi_bt_authorize_screen_close(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
            mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_REJECT);
            
        }
        else
        {   /* Device name from CM is utf8 */
            mmi_chset_ucs2_to_utf8_string(
                 (U8*)name_buff, 
                 MAX_SYNCML_DEV_NAME_LEN + 1, 
                 (U8*)g_mmi_syncml_common_cntx.remote_dev_name);
        
			srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);
        }

    }
/*BT concurrency*/

    /* Cut the connect confirm screen if disconn is coming */
    if (g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_SYNC_ASK)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_SYNC_DEV_SYNC_CONFIRM)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
            mmi_frm_group_close(GRP_ID_SYNC_BT_SYNC_REQ);
        }
		
		mmi_syncml_device_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
    }

    /* If not start sync, then clear the conn_id. */
    if (g_mmi_syncml_common_cntx.curr_state < MMI_SYNCML_DEVICE_STATE_START)
    {
        g_mmi_syncml_common_cntx.cm_conn_id = MMI_SYNCML_DEV_INVALID_CONN_ID;
        g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;

        /* Disconn is coming before the sync confirm */
        if (g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_BT_CONNECTING ||
			g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK ||
			g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_SYNC_ASK)
        {
            mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_ON);
        }
        
		/* sync have not really start when sync is aborted by other app */
        g_mmi_syncml_cntx.abort_by_other = MMI_FALSE;
        g_mmi_syncml_cntx.abort_state = MMI_FALSE;
        
        mmi_syncml_device_unlock_all_db();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_remoteinfo_ind_hdlr
 * DESCRIPTION
 *  Handler for request sync message
 * PARAMETERS
 *  *param          [IN]            request sync info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_remoteinfo_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_remoteinfo_ind_struct *remote_info_ptr;
	U16 curr_state = mmi_syncml_device_get_curr_state();
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_SYNCML_TRACE0(MMI_SYNCML_DEV_SYNC_ASK_IND);
    MMI_ASSERT(param != NULL);

	remote_info_ptr = (mmi_syncml_device_remoteinfo_ind_struct *)param;

    memcpy((void *)&g_mmi_syncml_common_cntx.remote_uri, (void *)remote_info_ptr->device_uri, MAX_SYNCML_SERVER_ADDR_LEN);

    /* 1: phone sync, 0: pc sync */
    g_mmi_syncml_common_cntx.f_is_phone = remote_info_ptr->f_is_phone;
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (g_mmi_syncml_common_cntx.f_is_phone == MMI_SYNCML_DEVICE_SYNC)
    {
        /* Error state, the conn has been disconnected*/
	    if (MMI_SYNCML_DEVICE_STATE_BT_CONNECTING != curr_state)
	    {
		    mmi_syncml_device_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
		    return;
	    }

        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_SYNC_ASK);
        
        g_mmi_syncml_cntx.is_dev_sync = MMI_TRUE;
        
        mmi_syncml_get_imei_req();
        
        return;
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (g_mmi_syncml_common_cntx.f_is_phone == MMI_SYNCML_PC_SYNC)
    {
        /* Error state, the conn has been disconnected*/
	    if (MMI_SYNCML_DEVICE_STATE_BT_CONNECTING != curr_state)
	    {
	        g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
            
		    mmi_syncml_pc_sync_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
		    return;
	    }
        
        g_mmi_syncml_cntx.is_pc_sync = MMI_TRUE;
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_SYNC_ASK);

        mmi_syncml_pc_sync_check_account();   

        return;
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

    /* If this project don't support device sync or pc sync. 2009/4/19*/
    mmi_syncml_reject_sync_request(MMI_SYNCML_DEV_SYNC_REJECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_reject_sync_request
 * DESCRIPTION
 *  reject synchorniztion 
 * PARAMETERS
 *  state          [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_reject_sync_request(U8 state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	typedef mmi_syncml_device_remoteinfo_res_struct dev_rmtinfo_res_struct;
	dev_rmtinfo_res_struct *remote_info_res_ptr;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
	remote_info_res_ptr = (dev_rmtinfo_res_struct *)construct_local_para(sizeof(dev_rmtinfo_res_struct), TD_CTRL|TD_RESET);
	MMI_ASSERT(remote_info_res_ptr != NULL);

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    remote_info_res_ptr->sml_role = mmi_syncml_dev_p->sync_role;
#endif

	remote_info_res_ptr->result = state; /* 1 or 0 */  

    mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_SYNC_ASK_RSP);

    memset(&remote_info_res_ptr->db_info, 0, sizeof(mmi_syncml_device_db_info_struct));
    mmi_syncml_device_unlock_all_db();   
    
    mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_RES, (oslParaType*) remote_info_res_ptr, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_db_ind_hdlr
 * DESCRIPTION
 *  Inform database will be synced
 * PARAMETERS
 *  *param          [IN]            database related info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_sync_db_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_sync_db_ind_struct *sync_info_ptr;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    MMI_SYNCML_TRACE0(MMI_SYNCML_DEV_SYNC_DB_IND);
    MMI_ASSERT(param != NULL);
    sync_info_ptr = (mmi_syncml_device_sync_db_ind_struct *)param;

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (mmi_syncml_is_device_sync())
    {
        if (sync_info_ptr->synced_db_type & SYNCML_DB_PHONEBOOK)
        {
            strcpy((CHAR*)mmi_syncml_dev_p->accnt_ptr->contact_address, (CHAR*)sync_info_ptr->database_remote_uri);
            mmi_syncml_dev_p->app_to_sync |= SYNCML_DB_PHONEBOOK; 
        }
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
        else if (sync_info_ptr->synced_db_type & SYNCML_DB_CALENDAR)
        {
            strcpy((CHAR*)mmi_syncml_dev_p->accnt_ptr->calendar_address, (CHAR*)sync_info_ptr->database_remote_uri);
            mmi_syncml_dev_p->app_to_sync |= SYNCML_DB_CALENDAR;
        }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
        else if (sync_info_ptr->synced_db_type & SYNCML_DB_TASK)
        {     
            strcpy((CHAR*)mmi_syncml_dev_p->accnt_ptr->task_address, (CHAR*)sync_info_ptr->database_remote_uri);
            mmi_syncml_dev_p->app_to_sync |= SYNCML_DB_TASK; 
        }      
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        else if (sync_info_ptr->synced_db_type & SYNCML_DB_NOTE)
        {     
            strcpy((CHAR*)mmi_syncml_dev_p->accnt_ptr->note_address, (CHAR*)sync_info_ptr->database_remote_uri);
            mmi_syncml_dev_p->app_to_sync |= SYNCML_DB_NOTE; 
        }      
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
        else{}
    }    
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync())
    {
        if (sync_info_ptr->synced_db_type & SYNCML_DB_PHONEBOOK)
        {
            g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] |= SYNCML_DB_PHONEBOOK; 
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        else if (sync_info_ptr->synced_db_type & SYNCML_DB_CALENDAR)
        {
            g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] |= SYNCML_DB_CALENDAR;
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        else if (sync_info_ptr->synced_db_type & SYNCML_DB_TASK)
        {     
            g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] |= SYNCML_DB_TASK; 
        }      
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */   
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        else if (sync_info_ptr->synced_db_type & SYNCML_DB_NOTE)
        {     
            g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] |= SYNCML_DB_NOTE; 
        }      
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */ 

        else{}
    }     
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */        
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_db_ind_hdlr
 * DESCRIPTION
 *  The message will come if the syncml task has clearup, but MMI send 
 *	remoteinfo_res to syncml task.
 * PARAMETERS
 *  void*       [IN]                NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_session_aborted_ind(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_syncml_dummy_finish_sync(STR_ID_SYNC_DEFAULT_FAIL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_ask_accept_conn_ind_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  U8 			status 		1-> accept 0-> reject
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_ask_accept_conn_ind_res(U8 status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	typedef mmi_syncml_bt_ask_accept_conn_res_struct dev_accept_res_struct;
	dev_accept_res_struct *ask_res_ptr;
        
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	ask_res_ptr = (dev_accept_res_struct*) construct_local_para(sizeof(dev_accept_res_struct), TD_CTRL|TD_RESET);
	MMI_ASSERT(ask_res_ptr != NULL);

    if (status == MMI_SYNCML_DEV_CONN_ACCEPT)
    {
    	if(g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK)
        {
            g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_B;
        
            /* Only consider the three database now, only used when bt act as role B */

            mmi_syncml_device_lock_all_db();
            mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_CONNECTING);
    	}

    }
    else
    {
        srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);
    	g_mmi_syncml_common_cntx.cm_conn_id = MMI_SYNCML_DEV_INVALID_CONN_ID;
		
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK_RSP);
    }
    
	ask_res_ptr->result = status; /* 1 or 0 */

	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_RES, (oslParaType*)ask_res_ptr, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_background_sync
 * DESCRIPTION
 *  is background sync 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_syncml_is_background_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL scr_present = MMI_FALSE;
    U16 scr_id; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if (scr_id == SCR_ID_SYNC_NOW ||
        IsScreenPresent(SCR_ID_SYNC_NOW) ||
        scr_id == SCR_ID_SYNC_ABORT)
    {
        scr_present = MMI_TRUE;
    }
         
    if (mmi_syncml_is_sync_now() && !scr_present)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_is_synchronizable
 * DESCRIPTION
 *  To check whether this device is syncable,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_syncml_device_is_synchronizable(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (mmi_syncml_is_sync_now())
    {
        result = MMI_FALSE;
        goto FINISH;
    }

    if (mmi_phb_screen_present() || !mmi_syncml_is_phb_ready_inner()
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        || mmi_cal_is_busy()
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        || mmi_tdl_is_busy()
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        || mmi_note_is_busy()
#endif
        )   
    {
        result = MMI_FALSE;
        goto FINISH;
    }

    if (g_mmi_syncml_common_cntx.curr_state != MMI_SYNCML_DEVICE_STATE_BT_ON)
    {
        return MMI_FALSE;
    }

#if defined(__MMI_SYNCML_SYNC_CALENDAR_SUPPORT__) || defined(__MMI_SYNCML_SYNC_TASK_SUPPORT__)
    if (mmi_alm_is_in_alarm() && 
        (srv_reminder_get_expiry_type() == SRV_REMINDER_TYPE_CAL||
         srv_reminder_get_expiry_type() == SRV_REMINDER_TYPE_TASK))
    {
        result = MMI_FALSE;
        goto FINISH;
    }
#endif

	/* If delete all is processing, don't accept the sync req.*/
    if (SCR_ID_SYNC_DEV_PHONES_DELETE_ALL == mmi_frm_scrn_get_active_id() ||
        mmi_frm_scrn_is_present(GRP_ID_SYNC_DEV_MAIN,SCR_ID_SYNC_DEV_PHONES_DELETE_ALL, MMI_FRM_NODE_ALL_FLAG)
        )
	{
        result = MMI_FALSE;
        goto FINISH;
	}

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
        || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 
        || srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0
        )
    {
        result = MMI_FALSE;
        goto FINISH;
    }

    FINISH:
    MMI_SYNCML_TRACE1(MMI_SYNCML_DEV_IS_SYNCHRONIZABLE, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_exit_sync_confirm
 * DESCRIPTION
 *  Exit function for sync ask confirm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_exit_sync_confirm(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
 
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_sync_confirm_leave_proc
 * DESCRIPTION
 *  Ask usr's confirm to start sync.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_device_sync_confirm_leave_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_frm_end_scenario(MMI_SCENARIO_ID_AUTO_SYNC);

    switch(param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            if (g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_SYNC_ASK)
            {
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (mmi_syncml_is_device_sync())
                {
                    mmi_syncml_device_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
                    return 0;
                }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
                if (mmi_syncml_is_pc_sync())
                {
                    g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
                    g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;                 

                    mmi_syncml_pc_sync_remoteinfo_ind_res(NULL, MMI_SYNCML_DEV_SYNC_REJECT);
                }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
            }
            break;
        }
    }

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_pwr_switch_notify
 * DESCRIPTION
 *  Notify Syncml task about BT power on, syncml task will register OBEX
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_device_bt_pwr_switch_notify(U8 bt_state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bt_state == MMI_SYNCML_DEVICE_STATE_BT_PWR_ON)
    {
        mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_BT_POWER_ON_NOTIFY_REQ, NULL, NULL);
    }
    else if(bt_state == MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF)
    {
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_BT_POWER_OFF_NOTIFY_REQ, NULL, NULL);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_clear_all_screen
 * DESCRIPTION
 *  After conn indication, clear all the phone-sync related screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
static void mmi_syncml_device_clear_all_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_group_close(GRP_ID_SYNC_MAIN);

    /* should close sync report */
    mmi_frm_group_close(GRP_ID_SYNC_FINISH);

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    mmi_frm_group_close(GRP_ID_SYNC_DEV_MAIN);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_reset_sync_state
 * DESCRIPTION
 *  After sync start, reinit the sync state, unlock no sync database(only used device B)
 * PARAMETERS
 *  void
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_device_reset_sync_state(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    /* already reset */
    if (g_mmi_syncml_common_cntx.is_state_reset)
    {
        return;
    }

    if (g_mmi_syncml_common_cntx.dev_role != MMI_SYNCML_DEV_ROLE_B)
    {
        return;
    }
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__       
    if (mmi_syncml_is_device_sync())
    {
        if (!(mmi_syncml_dev_p->app_to_sync & SYNCML_DB_PHONEBOOK))
        {
            g_mmi_syncml_cntx.contact_sync_state = MMI_FALSE;
        }      
#ifdef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
        if (!(mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR))
        {
            g_mmi_syncml_cntx.calendar_sync_state = MMI_FALSE;
        }
#endif /* __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__ */     
#ifdef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
        if (!(mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK))
        {
            g_mmi_syncml_cntx.task_sync_state = MMI_FALSE;           
        }
#endif /* __MMI_SYNCML_DEVICE_TASK_SUPPORT__ */ 
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (!(mmi_syncml_dev_p->app_to_sync & SYNCML_DB_NOTE))
        {
            g_mmi_syncml_cntx.note_sync_state = MMI_FALSE;           
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */ 

		if (!(mmi_syncml_dev_p->app_to_sync & SYNCML_DB_CALENDAR) &&
    	  !(mmi_syncml_dev_p->app_to_sync & SYNCML_DB_TASK))
		{
    		mmi_syncml_enable_alarm(); /* enable alarm */
		}         
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync())
    {
        if (!(g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_PHONEBOOK))
        {
            g_mmi_syncml_cntx.contact_sync_state = MMI_FALSE;
        }
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        if (!(g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_CALENDAR))
        {
            g_mmi_syncml_cntx.calendar_sync_state = MMI_FALSE;
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */     
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        if (!(g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_TASK))
        {
            g_mmi_syncml_cntx.task_sync_state = MMI_FALSE;
        }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */  
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        if (!(g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_NOTE))
        {
            g_mmi_syncml_cntx.note_sync_state = MMI_FALSE;
        }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */  

    	if (!(g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_CALENDAR) &&
        	!(g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] & SYNCML_DB_TASK))
		{
    		mmi_syncml_enable_alarm(); /* enable alarm */
		}             
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */   
   
    g_mmi_syncml_common_cntx.is_state_reset = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_unlock_all_db
 * DESCRIPTION
 *  To check whether this device is syncable,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_bt_common_ini(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_IDLE);
    g_mmi_syncml_common_cntx.cm_opr_flag = 0;
	g_mmi_syncml_common_cntx.cm_conn_id = MMI_SYNCML_DEV_INVALID_CONN_ID;
    g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE; 
    g_mmi_syncml_common_cntx.f_is_phone = MMI_SYNCML_COMMON_SYNC;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_set_state
 * DESCRIPTION
 *  Device sync state machine
 * PARAMETERS
 *  U8          [IN]        new state
 * RETURNS
 *  void	
 *****************************************************************************/
void mmi_syncml_device_set_state(mmi_syncml_device_state_enum new_state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SYNCML_TRACE2(MMI_SYNCML_DEV_STATE, new_state, g_mmi_syncml_common_cntx.curr_state);
    
    switch (new_state)
    {
        case MMI_SYNCML_DEVICE_STATE_IDLE:
        case MMI_SYNCML_DEVICE_STATE_BT_ON:
        {
            break;
        }    
        
        case MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF:
        {           
        	srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
            new_state = MMI_SYNCML_DEVICE_STATE_IDLE;
            break;
        }
        
        case MMI_SYNCML_DEVICE_STATE_REENTRY:
        {
            new_state = MMI_SYNCML_DEVICE_STATE_SYNCING;
            break;
        }
            
        case MMI_SYNCML_DEVICE_STATE_BT_PWR_ON:
        {
            srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
            new_state = MMI_SYNCML_DEVICE_STATE_BT_ON;
            break;
        }
        
        case MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK:
        {
            break;
        }

        case MMI_SYNCML_DEVICE_STATE_BT_CONNECTING:
        {
            break;
        }
        case MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK_RSP:
        {
            if (MMI_SYNCML_DEVICE_STATE_BT_CONN_ASK == mmi_syncml_device_get_curr_state())
            {
                new_state = MMI_SYNCML_DEVICE_STATE_BT_ON;
            }
            else
            {
                return;
            }
            break;

        }
        
        case MMI_SYNCML_DEVICE_STATE_SYNC_ASK:
        {
            break;
        }

        case MMI_SYNCML_DEVICE_STATE_SYNC_ASK_RSP:
        {
            if (MMI_SYNCML_DEVICE_STATE_SYNC_ASK == mmi_syncml_device_get_curr_state())
            {
                new_state = MMI_SYNCML_DEVICE_STATE_BT_ON;
            }
            else
            {
                return;
            }
            break;
        }
                
        case MMI_SYNCML_DEVICE_STATE_START:
        {
#ifdef __MMI_SYNCML_DEVICE_SYNC__
            if (mmi_syncml_is_device_sync())   
            {
                mmi_syncml_device_add_remote_device();
            }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

            new_state = MMI_SYNCML_DEVICE_STATE_SYNCING;
            break;
        }
        
        case MMI_SYNCML_DEVICE_STATE_SYNCING:
            break;
            
        case MMI_SYNCML_DEVICE_STATE_DISCONN:
        {
            if (MMI_SYNCML_DEVICE_STATE_SYNCING == mmi_syncml_device_get_curr_state())
            {
                /* record disconnection happened, deal with it in finish handler */
                g_mmi_syncml_common_cntx.cm_opr_flag |= SYNCML_DEV_BTCM_OPR_MASK_DISCONN;
                new_state = MMI_SYNCML_DEVICE_STATE_ABORTING;
                
                if (!mmi_syncml_is_sync_aborting())
                {
                    mmi_syncml_abort_sync_req();
                }  
            }
            
            break;
        }
		case MMI_SYNCML_DEVICE_STATE_BT_DEINIT:			

        case MMI_SYNCML_DEVICE_STATE_DEACTIVE:
        {
            if (MMI_SYNCML_DEVICE_STATE_SYNCING == mmi_syncml_device_get_curr_state())
            {
            	if (new_state == MMI_SYNCML_DEVICE_STATE_DEACTIVE)
        		{
        			g_mmi_syncml_common_cntx.cm_opr_flag |= SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE;
        		}
				else
				{
					g_mmi_syncml_common_cntx.cm_opr_flag |= SYNCML_DEV_BTCM_OPR_MASK_DEINIT;
				}
                
                new_state = MMI_SYNCML_DEVICE_STATE_ABORTING;
                
                if (!mmi_syncml_is_sync_aborting())
                {
                    mmi_syncml_abort_sync_req();
                }  
            }
            else
            {
            	if (new_state == MMI_SYNCML_DEVICE_STATE_DEACTIVE)
        		{
        			srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
        		}
				
	            new_state = MMI_SYNCML_DEVICE_STATE_IDLE;
                mmi_syncml_device_bt_pwr_switch_notify(MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF);
            }
            break;
        }       
            
        case MMI_SYNCML_DEVICE_STATE_ABORTING:
            break;
            
        default:
            break;
    }
    
    MMI_SYNCML_TRACE2(MMI_SYNCML_DEV_STATE, new_state, g_mmi_syncml_common_cntx.curr_state);

    g_mmi_syncml_common_cntx.curr_state = new_state;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_init
 * DESCRIPTION
 *  When BT power on, this funtion will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_bt_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct syncml_profile;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
    
	MMI_SYNCML_TRACE1(MMI_SYNCML_DEV_BT_INIT, g_mmi_syncml_common_cntx.curr_state);

	syncml_profile.profile_id = SRV_BT_CM_SYNCML_DEV_PROFILE_UUID;
	syncml_profile.activater = mmi_syncml_device_bt_activate;
	syncml_profile.deactivater = mmi_syncml_device_bt_deactivate;
	syncml_profile.disconnector = mmi_syncml_device_bt_disconn;
	
	srv_bt_cm_profile_register(&syncml_profile);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_deinit
 * DESCRIPTION
 *  When BT reset, this function will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_bt_deinit(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	MMI_SYNCML_TRACE2(MMI_SYNCML_DEV_BT_DEINIT, g_mmi_syncml_cntx.is_dev_sync, g_mmi_syncml_common_cntx.curr_state);
#endif

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    MMI_SYNCML_TRACE2(MMI_SYNCML_DEV_BT_DEINIT, g_mmi_syncml_cntx.is_pc_sync, g_mmi_syncml_common_cntx.curr_state);
#endif

    if (mmi_syncml_is_device_or_pc_sync())
	{
		/* The conf handler will be called after the sync finshed*/
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_DEINIT);
	}
    else
    {
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_IDLE);
        mmi_syncml_device_bt_pwr_switch_notify(MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF);
    }	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_deactivate
 * DESCRIPTION
 *  BT CM deactivate or poweroff this device, SyncML will abort this sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_bt_activate(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (g_mmi_syncml_common_cntx.curr_state == MMI_SYNCML_DEVICE_STATE_IDLE)
    {
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_PWR_ON);
        mmi_syncml_device_bt_pwr_switch_notify(MMI_SYNCML_DEVICE_STATE_BT_PWR_ON);
    }
    else
    {
        srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_deactivate
 * DESCRIPTION
 *  BT CM deactivate or poweroff this device, SyncML will abort this sync
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_bt_deactivate(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    MMI_SYNCML_TRACE1(MMI_SYNCML_DEV_BT_DEACTIVE, g_mmi_syncml_cntx.is_dev_sync);
#endif
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    MMI_SYNCML_TRACE1(MMI_SYNCML_DEV_BT_DEACTIVE, g_mmi_syncml_cntx.is_pc_sync);
#endif

    if (g_mmi_syncml_common_cntx.curr_state > MMI_SYNCML_DEVICE_STATE_IDLE &&
        g_mmi_syncml_common_cntx.curr_state < MMI_SYNCML_DEVICE_STATE_ABORTING)
    {
    	if (mmi_syncml_is_device_or_pc_sync()) 
        {
        /* The conf handler will be called after the sync finshed*/
            mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_DEACTIVE);
            return;
        }
        else
        {
            mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF);
            mmi_syncml_device_bt_pwr_switch_notify(MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF);
        }
    }
    else
    {
        srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
    }
}

/*BT concurrency: start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_bt_conn_callback
 * DESCRIPTION
 *  After mmi_bth_connect_req, CM will invoke this callback.
 * PARAMETERS
 *  srv_bt_cm_bt_addr		[IN]	device bt address
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_bt_conn_callback(srv_bt_cm_bt_addr bt_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_START);

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if(mmi_syncml_is_pc_sync())
    {        
        /* parent_id may be ROOT/SYNC_MAIN/APP_SYNC */
        mmi_syncml_group_entry_sync_pre_check(g_mmi_syncml_cntx.temp_gid, MMI_FALSE); 
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_bt_conn_callback
 * DESCRIPTION
 *  BT cm connect confirm screen callback
 * PARAMETERS
 *  srv_bt_cm_bt_addr		[IN]	device bt address
 *	result				[IN]	true or false
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_bt_conn_cnf_res_callback(srv_bt_cm_bt_addr bt_addr, U32 result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
		
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (result == 1)
    {
		/* sometimes do not run here, because connection authorization is passed */
		mmi_syncml_device_clear_all_screen();
    	mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_ACCEPT);
    }
    else
    {
        mmi_syncml_device_ask_accept_conn_ind_res(MMI_SYNCML_DEV_CONN_REJECT);
    }
}
/*BT concurrency End*/


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_disconn
 * DESCRIPTION
 *  BTCM disconnected the device, SyncML MMI will send abort sync to Syncml task
 * PARAMETERS
 *  srv_bt_cm_bt_addr		[IN]	device bt address
 *	conn_id				[IN]	connect id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_bt_disconn(U32 conn_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MMI_BOOL sync_flag = MMI_FALSE;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    MMI_SYNCML_TRACE5(MMI_SYNCML_DEV_BT_DISCONN, 
                      0, 
                      0, 
                      0, 
                      conn_id, 
                      g_mmi_syncml_cntx.is_dev_sync);
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SYNC__
        MMI_SYNCML_TRACE5(MMI_SYNCML_DEV_BT_DISCONN, 
                          0, 
                          0, 
                          0, 
                          conn_id, 
                          g_mmi_syncml_cntx.is_dev_sync);
#endif /* __MMI_SYNCML_PC_SYNC_SYNC__ */


#ifdef __MMI_SYNCML_DEVICE_SYNC__
	if (mmi_syncml_is_device_sync())
	{
       sync_flag = MMI_TRUE;
    }   
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */   

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync())
	{        
        sync_flag = MMI_TRUE;
	}
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

    if (sync_flag)
	{        
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_DISCONN);
	}
    else
    {
    	srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);      
		/* If not sync, back to the idle state */
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_ON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_sync_hdlr
 * DESCRIPTION
 *  To Test whether it can show comfirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_syncml_device_entry_sync_hdlr(mmi_scenario_id scen_id, void *arg)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
     mmi_syncml_device_group_entry_sync_confirm();
	
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_remoteinfo_confirm_check
 * DESCRIPTION
 *  To Test whether it can show comfirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_remoteinfo_confirm_check(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_AUTO_SYNC, MMI_EVENT_QUERY, mmi_syncml_device_entry_sync_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_group_entry_sync_confirm
 * DESCRIPTION
 *  Ask usr's confirm to start sync.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_device_group_entry_sync_confirm(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/   
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SYNC_BT_SYNC_REQ, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_SYNC_BT_SYNC_REQ, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_syncml_device_entry_sync_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_entry_sync_confirm
 * DESCRIPTION
 *  Ask usr's confirm to start sync.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_entry_sync_confirm(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/   
    U8 *gui_buffer; 
    U16 img_id;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_BT_SYNC_REQ,
            SCR_ID_SYNC_DEV_SYNC_CONFIRM, 
            mmi_syncml_device_exit_sync_confirm, 
            mmi_syncml_device_entry_sync_confirm, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

	mmi_frm_start_scenario(MMI_SCENARIO_ID_AUTO_SYNC);
   
    mmi_frm_scrn_set_leave_proc(GRP_ID_SYNC_BT_SYNC_REQ, SCR_ID_SYNC_DEV_SYNC_CONFIRM, mmi_syncml_device_sync_confirm_leave_proc);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    memset(&g_syncml_device_tmp_string, 0, 2);
    
	mmi_ucs2cpy((CHAR*)g_syncml_device_tmp_string, GetString(STR_ID_SYNC_DEV_SYNC_ACCEPT_ASK));
    mmi_ucs2cat((CHAR*)g_syncml_device_tmp_string, (CHAR*)g_mmi_syncml_common_cntx.remote_dev_name);
	mmi_ucs2cat((CHAR*)g_syncml_device_tmp_string, GetString(STR_ID_SYNCML_QUETION_MARK));    

    img_id = mmi_get_event_based_image(MMI_EVENT_QUERY);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

	ShowCategory165Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type)g_syncml_device_tmp_string,
        img_id,
        gui_buffer);
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (mmi_syncml_is_device_sync())
    {
        SetLeftSoftkeyFunction(mmi_syncml_device_sync_yes, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_syncml_device_sync_no, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_syncml_device_sync_yes, KEY_EVENT_UP);
        return;
    }   
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync())
    {
        SetLeftSoftkeyFunction(mmi_syncml_pc_sync_yes, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_syncml_pc_sync_no, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_syncml_pc_sync_yes, KEY_EVENT_UP);
    }    
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_lock_all_db
 * DESCRIPTION
 *  As device B acception, MMI don't know which db will be synced, so lock all the db. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_lock_all_db(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    /* Lock all the databases before we know the sync databases*/   
    g_mmi_syncml_cntx.contact_sync_state = MMI_TRUE;
 #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    g_mmi_syncml_cntx.calendar_sync_state = MMI_TRUE;
 #endif
 #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__   
    g_mmi_syncml_cntx.task_sync_state = MMI_TRUE;
 #endif
 #ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    g_mmi_syncml_cntx.note_sync_state = MMI_TRUE;
 #endif
    mmi_syncml_disable_alarm(); /* disable alarm */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_unlock_all_db
 * DESCRIPTION
 *  unlock all database when sync check fail(only used bt act as B)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_device_unlock_all_db(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    /*
     * Lock all the databases before we know the sync databases
     */
    g_mmi_syncml_cntx.contact_sync_state = MMI_FALSE;
 #ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    g_mmi_syncml_cntx.calendar_sync_state = MMI_FALSE;
 #endif
 #ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    g_mmi_syncml_cntx.task_sync_state = MMI_FALSE;
 #endif
 #ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    g_mmi_syncml_cntx.note_sync_state = MMI_FALSE;
 #endif
    mmi_syncml_enable_alarm(); /* enable alarm */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_addr_compare
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_device_bt_addr_compare(srv_bt_cm_bt_addr *addr1, srv_bt_cm_bt_addr *addr2)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	return (MMI_BOOL)(addr1->lap == addr2->lap && 
			addr1->nap == addr2->nap && 
			addr1->uap == addr2->uap);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_bt_addr_compare
 * DESCRIPTION
 *  To test whether the two address is same
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_device_or_pc_sync(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

    if (
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        mmi_syncml_is_device_sync() ||
#endif
#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__ 
        mmi_syncml_is_pc_sync() ||
#endif
        MMI_FALSE)
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
 *  mmi_syncml_device_get_curr_state
 * DESCRIPTION
 *  get current state
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_syncml_device_get_curr_state(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    return g_mmi_syncml_common_cntx.curr_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_get_curr_state
 * DESCRIPTION
 *  get current state
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_syncml_device_get_curr_role(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_syncml_common_cntx.dev_role; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_device_is_connected
 * DESCRIPTION
 *  To check whether this device is syncable,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_syncml_device_is_connected(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    return (MMI_BOOL)(g_mmi_syncml_common_cntx.cm_conn_id != MMI_SYNCML_DEV_INVALID_CONN_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_is_device_or_pc_sync_active
 * DESCRIPTION
 *  Check function if device sync is active
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_device_or_pc_sync_active()
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
	U16 active_scr;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	active_scr = mmi_frm_scrn_get_active_id();
	
	if (mmi_syncml_is_sync_now() && !mmi_syncml_is_background_sync())
	{
		ret = MMI_TRUE;
	}
	if (active_scr == SCR_ID_SYNC_DEV_SYNC_CONFIRM ||
		ret)
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
 *  mmi_syncml_is_obex_sync
 * DESCRIPTION
 *  Check function if device sync or pc sync is going on
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_syncml_is_obex_sync(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    if (mmi_syncml_device_is_connected () ||
        mmi_syncml_device_get_curr_state() == MMI_SYNCML_DEVICE_STATE_BT_CONNECTING ||
        mmi_syncml_is_device_or_pc_sync())
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
 *  mmi_syncml_common_finish_hdlr
 * DESCRIPTION
 *  Bt related handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_common_finish_hdlr(void)
{	
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
	srv_bt_cm_bt_addr *bt_addr = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	/*
	* BT deinit will don't call deactive callback, so set it back
	*/
	if (g_mmi_syncml_common_cntx.cm_opr_flag & SYNCML_DEV_BTCM_OPR_MASK_DEINIT)
	{
		mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_IDLE);
	}
	else
	{
		mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_ON);
	}

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (mmi_syncml_is_device_sync())
    {      
        bt_addr = (srv_bt_cm_bt_addr *)&mmi_syncml_dev_p->accnt_ptr->dev_bt_addr;
    }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
    if (mmi_syncml_is_pc_sync())
    {
        bt_addr = &(g_mmi_syncml_common_cntx.remote_bt_addr);      
    }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

    /* passkey screen del callback */
    mmi_bt_reject_passkey_ind(bt_addr->lap, 
        bt_addr->uap, 
        bt_addr->nap);
		
	/* BT power off case this finish sync */
	if (g_mmi_syncml_common_cntx.cm_opr_flag & SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE)
	{
		g_mmi_syncml_common_cntx.cm_opr_flag &= ~SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE;
        mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF);
        mmi_syncml_device_bt_pwr_switch_notify(MMI_SYNCML_DEVICE_STATE_BT_PWR_OFF);
	}
	
    /* BT disconn casued this finish sync */
	if (g_mmi_syncml_common_cntx.cm_opr_flag & SYNCML_DEV_BTCM_OPR_MASK_DISCONN)
	{
		g_mmi_syncml_common_cntx.cm_opr_flag &= ~SYNCML_DEV_BTCM_OPR_MASK_DISCONN;
        
		srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);
        /*srv_bt_cm_disconnect_cnf_hdler(            MMI_TRUE,
            bt_addr, 
            SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, 
            g_mmi_syncml_common_cntx.cm_conn_id);*/
	}    

	/* 
	    enable bt popup, MAUI_1787503, bt and syncml popup are very close, 
	    the popup sound is abnormal;
	*/
    mmi_bt_suppress_profile_popup(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, MMI_FALSE);

    g_mmi_syncml_common_cntx.cm_opr_flag = 0;
	g_mmi_syncml_common_cntx.cm_conn_id = MMI_SYNCML_DEV_INVALID_CONN_ID;
	g_mmi_syncml_common_cntx.dev_role = MMI_SYNCML_DEV_ROLE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_comm_disconn
 * DESCRIPTION
 *  Bt disconn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_comm_disconn(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                					   */
	/*----------------------------------------------------------------*/
	//srv_bt_cm_bt_addr *bt_addr;
    
	/*----------------------------------------------------------------*/
	/* Code Body                                                      					  */
	/*----------------------------------------------------------------*/
	//bt_addr = &g_mmi_syncml_common_cntx.remote_bt_addr; /*BT concurrency*/

	srv_bt_cm_stop_conn(g_mmi_syncml_common_cntx.cm_conn_id);
	/*srv_bt_cm_disconnect_ind_hdler(
		bt_addr,
		SRV_BT_CM_SYNCML_DEV_PROFILE_UUID, 
		g_mmi_syncml_common_cntx.cm_conn_id); */
}

#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */
#endif /* __SYNCML_SUPPORT__ */
