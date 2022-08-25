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
 *    DCDMain.c
 *
 * Project:
 * --------
 *    MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "DateTimeType.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "DCDGprot.h"
#include "DCDProt.h"
#include "plDefine.h"
#include "DCDAgentInterface.h"
#include "plx_IConfig.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "sdktypedef.h"
#include "dcdagentdefine.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_release.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "plx_dcd_wrapper.h"
#include "string.h"
#include "app_datetime.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DCD_PUSH_URL_LEN   512

typedef enum
{
    DCD_SYNC_REQ_TYPE_MAN,
    DCD_SYNC_REQ_TYPE_START,
    DCD_SYNC_REQ_TYPE_SVR,
    DCD_SYNC_REQ_TYPE_TTL,
    DCD_SYNC_REQ_TYPE_RETRY,

    DCD_SYNC_REQ_TYPE_RESET,
    DCD_SYNC_REQ_TYPE_SIM,
    DCD_SYNC_REQ_TYPE_MAX
} dcd_sync_req_type_enum;

typedef enum
{
    DCD_STATE_IDLE,
    DCD_STATE_POSTPONED,
    DCD_STATE_SYNCING,
    DCD_STATE_SUSPENDED,
    DCD_STATE_MAX
} dcd_state_enum;

typedef enum
{
    DCD_ROAM_SHIFT_TO_FOREIGN,
    DCD_ROAM_SHIFT_TO_HOME,
    DCD_ROAM_SHIFT_MAX
} dcd_roam_shift_enum;

typedef enum
{
    DCD_RETURN_SUCCESS,
    DCD_RETURN_FAILURE,
    DCD_RETURN_HIGH_PRIORITY_SYNC_EXIST,
    DCD_RETURN_SYNC_POSTPONED,
    DCD_RETURN_SYNC_NOT_ALLOWED,
    DCD_RETURN_MAX
}dcd_return_enum;

typedef struct
{
    MMI_BOOL    ttl_timer_on;
    MMI_BOOL    retry_timer_on;
    MMI_BOOL    is_retrying;
    U32         retry_times;
    MMI_BOOL    is_syncing;
    U8          sync_type;
    S32         line_taken;
    U8          state;
    U8          postponed_req;
    S8          push_url[DCD_PUSH_URL_LEN];

    MMI_BOOL    is_new_sim;
    MMI_BOOL    is_reset;
    MMI_BOOL    dcd_switch;
    U8          conn_mode;
    MMI_BOOL    is_roaming;

    dcd_sync_callback man_callback;
    S32         errcode;
    U32         last_sync_end;
    U32         last_ttl;
} dcd_struct;

dcd_agent_struct g_dcd_agent;


#define MMI_DCD_GET_SYNC_SWITCH(on_off,flymode)   (((on_off)&&(!(flymode)))?1:0)

#define DCD_ENGINE_FINALIZE_WHEN_OFF
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/*******************************************************************
non-roaming
	always connect	 home only    manual		
man	    v		     v            v
start	v		     v            v
svr	    v		     v            x
ttl	    v		     v            x
retry	v		     v            x
*********************************************************************/
static U8 sync_allow_tbl_non_roming[5][3] = 
{
    /* always home  manual */
    {1,     1,      1}, /* man */
    {1,     1,      1}, /* start */
    {1,     1,      0}, /* svr */
    {1,     1,      0}, /* ttl */
    {1,     1,      0}  /* retry */
};

/********************************************************************
roaming
  	always connect	 home only                      manual
man	    v		     v(prompt user when roaming)    v(roaming) 	
start	v		     x(roaming)                     x(roaming)	
svr	    v		     x(roaming)                     x			
ttl	    v		     x(roaming)                     x			
retry	v		     x(roaming)                     x			
*******************************************************************/
static U8 sync_allow_tbl_roming[5][3] = 
{
    /* always home  manual */
    {1,     1,      1}, /* man */
    {1,     0,      0}, /* start */
    {1,     0,      0}, /* svr */
    {1,     0,      0}, /* ttl */
    {1,     0,      0}  /* retry */
};

static dcd_struct   g_dcd;
static MMI_BOOL     g_dcd_is_ready_to_sync = MMI_FALSE;
static MMI_BOOL     g_dcd_is_initialized   = MMI_FALSE;

static mmi_dcd_update_log_struct   g_dcd_update_log;
mmi_dcd_update_log_struct *        g_dcd_update_log_p = &g_dcd_update_log;

static MMI_BOOL mmi_dcd_engine_initialize(void);
static BRINT mmi_dcd_message_proc(EDCD_MSG_CODE a_eMsgCode, BRVOID *a_pUserData, BRVOID *a_pParam);
static void mmi_dcd_ttl_timer_handler(void);
static void mmi_dcd_retry_timer_handler(void);

static dcd_return_enum mmi_dcd_start_sync(U8 req_type, S8 *url);
static void mmi_dcd_retry(void);
static void mmi_dcd_stop_retry(void);

static void mmi_dcd_roam_to_sync(dcd_roam_shift_enum shift);
static S32  mmi_dcd_sync_request(HDCD_Agent agent, U8 req_type, S8 *url, S32 errcode);
static U8   mmi_dcd_mapping_err_code(EDCD_MSG_CODE code);

static void mmi_dcd_sync_get_data(void);
static void mmi_dcd_sync_set_data(void);

static MMI_BOOL mmi_dcd_sync_is_allowed(dcd_sync_req_type_enum sync_type,
                                        dcd_conn_mode_enum     conn_mode,
                                        MMI_BOOL               is_roming);
static void mmi_dcd_startup_to_sync(void);
static void mmi_dcd_log_reset(void);
static void mmi_dcd_log_last_sync_time(void);
static void mmi_dcd_log_sync_result(U8 sync_result, U8 fail_cause);
static void mmi_dcd_log_next_sync_time(U32 secs);
static void mmi_dcd_log_next_sync_type(U8 sync_type);
static void mmi_dcd_log_reset_next_sync_time(void);

void mmi_dcd_wakeup_prompt(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_initialize(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL          init_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_INITIALIZE);

    if (!srv_sim_ctrl_is_available(MMI_SIM1))
    {
        return MMI_RET_OK;
    }
    mmi_dcd_mem_initialize();
    mmi_dcd_cbm_register_app_id();
    mmi_dcd_settings_init();
//    mmi_dcd_network_init();

    mmi_dcd_sync_get_data();
   
	MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_VALUE, g_dcd.dcd_switch);

#ifdef DCD_ENGINE_FINALIZE_WHEN_OFF
    if (!g_dcd.dcd_switch)
    {
        return MMI_RET_OK;
    }
#endif /* DCD_ENGINE_FINALIZE_WHEN_OFF */

    init_flag = mmi_dcd_engine_initialize();
    if (!init_flag)
    {
        g_dcd_agent.agent_handle = NULL;
    }

    if (g_dcd.is_reset)
    {
        g_dcd.is_new_sim = MMI_FALSE;
        g_dcd.is_reset = MMI_FALSE;
        mmi_dcd_sync_set_data();
    }

    g_dcd_is_initialized = MMI_TRUE;
    if (g_dcd_is_ready_to_sync)
    {
        mmi_dcd_startup_to_sync();
    }


    //mmi_dcd_main_option_init();
    //mmi_dcd_saved_story_list_init();
    //mmi_dcd_story_viewer_init();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_engine_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_engine_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_dcd_agent.agent_handle = emDCDAgent_Create(EMBIDER_MEM_SIZE);
    ASSERT(g_dcd_agent.agent_handle);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_AFTER_AGENT_CREATED, g_dcd_agent.agent_handle);
    
    if (g_dcd.is_reset)
    {
        emDCDAgent_RemoveAll(g_dcd_agent.agent_handle);
    }

    result = emDCDAgent_SetConfigDCDServer(g_dcd_agent.agent_handle, (BRSTR) plx_IConfig_GetHomeUrl());
    if (result != eDCD_SUCCESS)
    {
        emDCDAgent_Destroy(g_dcd_agent.agent_handle);
        g_dcd_agent.agent_handle = NULL;
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_FAILED_TO_CONFIG_SERVER);
        return MMI_FALSE;
    }
    
    result = emDCDAgent_SetMaxNumOfPermanenceEntry(g_dcd_agent.agent_handle,MMI_DCD_MAX_SAVED_STORY_COUNT);
    if (result != eDCD_SUCCESS)
    {
        emDCDAgent_Destroy(g_dcd_agent.agent_handle);
        g_dcd_agent.agent_handle = NULL;
        return MMI_FALSE;
    }
    
    if (!mmi_dcd_set_scroll_speed())
    {
        emDCDAgent_Destroy(g_dcd_agent.agent_handle);
        g_dcd_agent.agent_handle = NULL;
        return MMI_FALSE;
    }
    if (!mmi_dcd_set_read_item_display())
    {
        emDCDAgent_Destroy(g_dcd_agent.agent_handle);
        g_dcd_agent.agent_handle = NULL;
        return MMI_FALSE;
    }
    
    if (eDCD_SUCCESS != emDCDAgent_Start(g_dcd_agent.agent_handle, mmi_dcd_message_proc, NULL))
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_FAILED_TO_START);
        emDCDAgent_Destroy(g_dcd_agent.agent_handle);
        g_dcd_agent.agent_handle = NULL;
        return MMI_FALSE;
    }    
    
    if (g_dcd.is_reset)
    {
        result = emDCDAgent_SetRestoreFlag(g_dcd_agent.agent_handle, BRTRUE);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_FINALIZE);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_VALUE, g_dcd.dcd_switch);

    g_dcd.dcd_switch = MMI_FALSE;

    if (g_dcd.is_retrying)
    {
        mmi_dcd_stop_retry();
    }
    if (g_dcd.ttl_timer_on)
    {
		MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_STOP_TTL_TIMER);
        g_dcd.ttl_timer_on = MMI_FALSE;
        StopTimer(DCD_TTL_TIMER);
    }

    if (g_dcd.is_syncing)
    {
        mmi_dcd_stop_sync();
    }

    result = emDCDAgent_End(g_dcd_agent.agent_handle);
    result = emDCDAgent_Destroy(g_dcd_agent.agent_handle);

    mmi_dcd_mem_finalize();
    g_dcd_is_initialized = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_finalize_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_finalize_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_finalize();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_agent_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
HDCD_Agent mmi_dcd_get_agent_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_GET_AGENT_HANDLE, g_dcd_agent.agent_handle);

    return g_dcd_agent.agent_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_bt_access_profile_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_bt_access_profile_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) ==  SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE)
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
 *  mmi_dcd_is_switch_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_switch_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_IS_SWITCH_ON, g_dcd.dcd_switch);
    if (g_dcd.dcd_switch && !mmi_dcd_is_bt_access_profile_mode())
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
 *  mmi_dcd_line_taken
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_line_taken(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_LINE_TAKEN);

    if (g_dcd.state == DCD_STATE_SYNCING)
    {
        result = emDCDAgent_OnSuspendSyncRequest(g_dcd_agent.agent_handle);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNC_SUSPENDED);
        g_dcd.state = DCD_STATE_SUSPENDED;
    }

    g_dcd.line_taken++;
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_LINE_TAKEN_VALUE, g_dcd.line_taken);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_line_given
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_line_given(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL          result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_LINE_GIVEN);
    g_dcd.line_taken--;
	MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_LINE_GIVEN_VALUE, g_dcd.line_taken);

    if (g_dcd.line_taken == 0)
    {
        if (g_dcd.state == DCD_STATE_SUSPENDED)
        {
            result = emDCDAgent_OnResumeSyncRequest(g_dcd_agent.agent_handle);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNC_RESUMED);
			g_dcd.state = DCD_STATE_SYNCING;
        }
        else if (DCD_STATE_POSTPONED == g_dcd.state)
        {
            g_dcd.sync_type = g_dcd.postponed_req;
			MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_POSTPONED_SYNC_RESUMED, g_dcd.sync_type);

            if (g_dcd.is_retrying)
			{
				mmi_dcd_stop_retry();
			}

            result = mmi_dcd_sync_request(g_dcd_agent.agent_handle, g_dcd.sync_type, g_dcd.push_url, g_dcd.errcode);

			if (result == eDCD_SUCCESS)
			{
				g_dcd.state = DCD_STATE_SYNCING;
			}
			else
			{				
				if (eDCD_ERR_CONFIG_NO_DCD_NEXTURL == result || eDCD_ERR_CONFIG_NO_DCD_SERVER == result)
				{					
					g_dcd.is_syncing = MMI_FALSE;
					g_dcd.state = DCD_STATE_IDLE;
					g_dcd.sync_type     = DCD_SYNC_REQ_TYPE_MAX;
					g_dcd.postponed_req = DCD_SYNC_REQ_TYPE_MAX;
				}
				else
                {
					g_dcd.is_syncing    = MMI_FALSE;
					g_dcd.state         = DCD_STATE_IDLE;
					g_dcd.postponed_req = DCD_SYNC_REQ_TYPE_MAX;
                    mmi_dcd_retry();
                }
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_is_allowed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_syncing      [OUT]         [?]         [?]
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dcd_sync_is_allowed(dcd_sync_req_type_enum sync_type,
                                        dcd_conn_mode_enum     conn_mode,
                                        MMI_BOOL               is_roming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  is_allowed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((sync_type>=DCD_SYNC_REQ_TYPE_MAN)&&(sync_type<=DCD_SYNC_REQ_TYPE_RETRY));
    ASSERT((conn_mode>=DCD_CONN_MODE_ALWAYS)&&(conn_mode<=DCD_CONN_MODE_MANUAL));

    if (is_roming)
    {
        is_allowed = sync_allow_tbl_roming[sync_type][conn_mode];
    }
    else
    {
        is_allowed = sync_allow_tbl_non_roming[sync_type][conn_mode];
    }
    return is_allowed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_network_indication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  foreign_roaming     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_network_indication(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL  foreign_roaming;     
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_NETWORK_INDICATION, evt->evt_id);    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_IS_READY_TO_SYNC, g_dcd_is_ready_to_sync);

    if (!g_dcd_is_initialized && g_dcd.dcd_switch) 
    {
        return MMI_RET_OK;
    }
    
    if (evt->evt_id == EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED)
    {
        srv_nw_info_service_availability_changed_evt_struct * service_evt;
        service_evt = (srv_nw_info_service_availability_changed_evt_struct *)evt;
        if (service_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE && !g_dcd_is_ready_to_sync)
        {
            g_dcd_is_ready_to_sync = MMI_TRUE;
		    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_IS_READY_TO_SYNC, g_dcd_is_ready_to_sync);
            g_dcd.is_roaming = srv_nw_info_is_roaming(MMI_SIM1);             
            mmi_dcd_startup_to_sync();
        }
        return MMI_RET_OK;
    }
    else if (evt->evt_id == EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED) 
    {
        srv_nw_info_roaming_status_changed_evt_struct * roaming_evt;  
        roaming_evt = (srv_nw_info_roaming_status_changed_evt_struct*)evt;
        foreign_roaming = roaming_evt->is_roaming_now;
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ROAMING_STATUS, g_dcd.is_roaming, foreign_roaming);

        if (g_dcd_is_ready_to_sync == MMI_FALSE)
        {
            g_dcd_is_ready_to_sync = MMI_TRUE;
		    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_IS_READY_TO_SYNC, g_dcd_is_ready_to_sync);
            g_dcd.is_roaming = foreign_roaming;             
            mmi_dcd_startup_to_sync();
        }
        else if (MMI_TRUE == g_dcd.is_roaming && MMI_FALSE == foreign_roaming)
        {
            g_dcd.is_roaming = foreign_roaming;  
            mmi_dcd_roam_to_sync(DCD_ROAM_SHIFT_TO_HOME);
        }
        else if (MMI_FALSE == g_dcd.is_roaming && MMI_TRUE == foreign_roaming)
        {
            g_dcd.is_roaming = foreign_roaming;  
            mmi_dcd_roam_to_sync(DCD_ROAM_SHIFT_TO_FOREIGN);
        }
        else
        {
            /* do nothing */
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sim_unavailable_hdlr
 * DESCRIPTION
 *  when sim is unavailable, app should close dcd screen group.
 * PARAMETERS
 *  foreign_roaming     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dcd_sim_unavailable_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SIM_UNAVAILABLE);
    
    if ((g_dcd_grp_id != 0) && mmi_frm_group_is_present(g_dcd_grp_id))
    {
        mmi_frm_group_close(g_dcd_grp_id);

        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_CLOSE_GROUP);
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_startup_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_startup_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	dcd_return_enum  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_READY_TO_SYNC);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_VALUE, g_dcd.dcd_switch);
    //g_dcd.man_callback = NULL;
    if (g_dcd.dcd_switch == MMI_FALSE)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_DEVICE_STATUS, g_dcd.is_new_sim, g_dcd.is_reset);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_STATUS, g_dcd.conn_mode, g_dcd.is_roaming);
    
    result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_START, NULL);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_START, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_reset_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_reset_to_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	dcd_return_enum  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd.is_retrying)
    {
        mmi_dcd_stop_retry();
    }
    if (g_dcd.ttl_timer_on)
    {
		MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_STOP_TTL_TIMER);
        g_dcd.ttl_timer_on = MMI_FALSE;
        StopTimer(DCD_TTL_TIMER);
    }
    if (g_dcd.is_syncing)
    {
        mmi_dcd_stop_sync();
    }

    mmi_dcd_sync_get_data();
    if (g_dcd.is_reset)
    {
        ASSERT(g_dcd_agent.agent_handle!=NULL);
        emDCDAgent_RemoveAll(g_dcd_agent.agent_handle);
        emDCDAgent_SetRestoreFlag(g_dcd_agent.agent_handle, BRTRUE);
    }

    if (g_dcd.is_reset)
    {
        g_dcd.is_new_sim = MMI_FALSE;
        g_dcd.is_reset = MMI_FALSE;
        mmi_dcd_sync_set_data();
    }

    mmi_dcd_set_scroll_speed();
    mmi_dcd_set_read_item_display();

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_READY_TO_SYNC);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_VALUE, g_dcd.dcd_switch);

    if (g_dcd.dcd_switch == MMI_FALSE)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_DEVICE_STATUS, g_dcd.is_new_sim, g_dcd.is_reset);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_STATUS, g_dcd.conn_mode, g_dcd.is_roaming);
    
    result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_START, NULL);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_START, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_switch_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_switch_to_sync(MMI_BOOL on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DCD_ENGINE_FINALIZE_WHEN_OFF
    S32     result;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_TO_SYNC_FUNC, on);

    if (MMI_TRUE == on)
    {
        g_dcd.dcd_switch = MMI_TRUE;

#ifdef DCD_ENGINE_FINALIZE_WHEN_OFF
        result = mmi_dcd_engine_initialize();
        if (!result)
        {
            g_dcd_agent.agent_handle = NULL;
            return;
        }
        g_dcd_is_initialized = TRUE;
#endif /* DCD_ENGINE_FINALIZE_WHEN_OFF */

        if (g_dcd_is_ready_to_sync)
        {
            mmi_dcd_startup_to_sync();
        }
    }
    else
    {
        g_dcd.dcd_switch = MMI_FALSE;

        if (g_dcd.is_retrying)
        {
            mmi_dcd_stop_retry();
        }
        if (g_dcd.is_syncing)
        {
            mmi_dcd_stop_sync();
        }

        if (g_dcd.ttl_timer_on)
        {
			MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_STOP_TTL_TIMER);
            g_dcd.ttl_timer_on = MMI_FALSE;
            StopTimer(DCD_TTL_TIMER);
        }

#ifdef DCD_ENGINE_FINALIZE_WHEN_OFF
        result = emDCDAgent_End(g_dcd_agent.agent_handle);
        result = emDCDAgent_Destroy(g_dcd_agent.agent_handle);
        g_dcd_agent.agent_handle = NULL;
        g_dcd_is_initialized = MMI_FALSE;
#endif /* DCD_ENGINE_FINALIZE_WHEN_OFF */
        mmi_dcd_disconnect_bearer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_push_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  push_url        [IN]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_push_to_sync(S8 *push_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dcd_return_enum  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_PUSH_TO_SYNC, push_url);

    if (!g_mmi_dcd_setting_cntx_p->dcd_switch)
    {
        g_mmi_dcd_setting_cntx_p->dcd_switch = MMI_TRUE;
        mmi_dcd_write_setting_value();
        mmi_dcd_wakeup_prompt();
    }

#ifdef DCD_ENGINE_FINALIZE_WHEN_OFF
    if (!g_dcd_is_initialized)
    {
        S32     result;
        result = mmi_dcd_engine_initialize();
        if (!result)
        {
            g_dcd_agent.agent_handle = NULL;
            return;
        }
        mmi_dcd_show_reset();
        g_dcd_is_initialized = TRUE;
    }
#endif /* DCD_ENGINE_FINALIZE_WHEN_OFF */

    g_dcd.dcd_switch = MMI_DCD_GET_SYNC_SWITCH(g_mmi_dcd_setting_cntx_p->dcd_switch, g_mmi_dcd_setting_cntx_p->dcd_flymode);
	MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SWITCH_VALUE, g_dcd.dcd_switch);
    if (MMI_TRUE == g_dcd.dcd_switch)
    {
        result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_SVR, push_url);
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_SVR, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_conn_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_conn_to_sync(dcd_conn_mode_enum  conn_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	dcd_return_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_TO_SYNC_FUNC, conn_mode);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_STATUS, g_dcd.conn_mode, g_dcd.is_roaming);

    if (g_dcd.conn_mode == DCD_CONN_MODE_MANUAL)
    {
        if (conn_mode == DCD_CONN_MODE_ALWAYS)
        {
            g_dcd.conn_mode = DCD_CONN_MODE_ALWAYS;
            result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_MAN, NULL);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_MAN, result);
        }
        else if(conn_mode == DCD_CONN_MODE_HOME)
        {
            g_dcd.conn_mode = DCD_CONN_MODE_HOME;
            result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_MAN, NULL);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_MAN, result);
        }
        else
        {
            g_dcd.conn_mode = conn_mode;
        }
    }
    else if ((g_dcd.conn_mode == DCD_CONN_MODE_HOME) && g_dcd.is_roaming)
    {
        if (conn_mode == DCD_CONN_MODE_ALWAYS)
        {
            g_dcd.conn_mode = DCD_CONN_MODE_ALWAYS;
            result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_MAN, NULL);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_MAN, result);
        }
        else
        {
            g_dcd.conn_mode = conn_mode;
        }
    }
    else
    {
        g_dcd.conn_mode = conn_mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_roam_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  shift       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_roam_to_sync(dcd_roam_shift_enum shift)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	dcd_return_enum  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ROAM_TO_SYNC, shift);

    if (DCD_ROAM_SHIFT_TO_HOME == shift)
    {
        g_dcd.is_roaming = MMI_FALSE;

        if (DCD_CONN_MODE_HOME == g_dcd.conn_mode)
        {
            result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_MAN, NULL);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_MAN, result);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_user_to_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_syncing      [OUT]         [?]         [?]
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_user_to_sync(MMI_BOOL *is_syncing, dcd_sync_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	dcd_return_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_USER_TO_SYNC);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNCING_STATUS, g_dcd.is_syncing, g_dcd.is_retrying);
    *is_syncing = MMI_FALSE;

    result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_MAN, NULL);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_MAN, result);

    if (result == DCD_RETURN_HIGH_PRIORITY_SYNC_EXIST)
    {
        *is_syncing = MMI_TRUE;
        return MMI_TRUE;
    }
    else if (result == DCD_RETURN_SUCCESS)
    {
        g_dcd.man_callback = callback;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_user_sync_fail_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_syncing      [OUT]         [?]         [?]
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_user_sync_fail_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32       ticks;
    S32              ttl_delay;
    MMI_BOOL         sync_allowed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_USER_TO_SYNC);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNCING_STATUS, g_dcd.is_syncing, g_dcd.is_retrying);

    sync_allowed = mmi_dcd_sync_is_allowed(DCD_SYNC_REQ_TYPE_TTL, g_dcd.conn_mode, g_dcd.is_roaming);
    if (!sync_allowed)
    {
        return;
    }

    kal_get_time(&ticks);
    ticks = kal_ticks_to_milli_secs(ticks);

    if (g_dcd.last_sync_end + g_dcd.last_ttl > ticks)
    {
        ttl_delay = g_dcd.last_sync_end + g_dcd.last_ttl - ticks;
        ttl_delay = (ttl_delay > 200) ? ttl_delay : 200;
    }
    else
    {
        ttl_delay = 5 * 60 * 1000; /* 5 minutes */
    }

    if (g_dcd.ttl_timer_on)
    {
        StopTimer(DCD_TTL_TIMER);
        g_dcd.ttl_timer_on = MMI_FALSE;
    }

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TTL_VALUE, ttl_delay);
    StartTimer(DCD_TTL_TIMER, ttl_delay, mmi_dcd_ttl_timer_handler);
    g_dcd.ttl_timer_on = MMI_TRUE;

    mmi_dcd_log_next_sync_time(ttl_delay/1000);
    mmi_dcd_log_next_sync_type(DCD_SYNC_REQ_TYPE_TTL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_mapping_err_code
 * DESCRIPTION
 *  mapping DCD engine error code to Operator Error code
 * PARAMETERS
 *  code: DCD engine error code 
 * RETURNS
 *  Operator needed error code 
 *****************************************************************************/
static U8 mmi_dcd_mapping_err_code(EDCD_MSG_CODE code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(code)
    {
        case eDCD_MSG_ERR_SYNCPKG_PARSING: /* 701.Parsing SyncPkg Fail */
            return 0;

        case eDCD_MSG_ERR_NO_SYNCPKG:       /* 702.No XML content in package */
            return 1;

        case eDCD_MSG_ERR_CONTENT_PARSING:  /* 703.Parsing MIME Content Fail ErrorCode */
            return 2;

        case eDCD_MSG_ERR_NO_CONTENT:       /* 704.Fail to get sync package or no content in it*/
            return 3;

        case eDCD_MSG_ERR_STORAGE_FULL:     /* 705.Insufficient memory */
        case eDCD_MSG_ERR_INSUFFICIENT_MEMORY:
            return 4;

        case eDCD_MSG_ERR_NETWORK_DISABLE:  /* 706.Network is not available	*/
            return 5;

        case eDCD_MSG_ERR_NETWORK_BUSY:     /* 707.Network is busy */
            return 6;

        case eDCD_MSG_ERR_DOWNLOAD_SYNCPKG: /* 708.Server abnormal, Download SyncPkg Fail */
        case eDCD_MSG_ERR_DOWNLOAD_CONTENT: /* Content Download Fail */
        case eDCD_MSG_ERR_CONNECT_TIME_OUT: /* timeout */
        case eDCD_MSG_ERR_SYNC:             /* Synchronization Fail */
            return 7;

        default:
            return 0;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_message_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a_eMsgCode      [IN]        
 *  a_pUserData     [?]         [?]         [?]
 *  a_pParam        [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static BRINT mmi_dcd_message_proc(EDCD_MSG_CODE a_eMsgCode, BRVOID *a_pUserData, BRVOID *a_pParam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ttl_delay = 0;
    static U8  received_conn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (a_eMsgCode)
    {
        case eDCD_MSG_SYNC_START:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNC_START);
            received_conn = 0;
            g_dcd.errcode = -1;
            mmi_dcd_log_reset();
            mmi_dcd_log_last_sync_time();
            break;

        case eDCD_MSG_CONNECT_SERVER_SUCCESS:
        	if (received_conn == 0)
        	{
                mmi_dcd_display_manual_update_info(eDCD_MSG_CONNECT_SERVER_SUCCESS);
                received_conn = 1;
            }
            break;

        case eDCD_MSG_DOWNLOAD_SYNCPKG_COMPLETE:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNC_DOWNLOAD_SYNCPKG_COMPLETE);
            break;

        case eDCD_MSG_SYNCPKG_PARSING_SUCCESS:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNCPKG_PARSING_SUCCESS);
            mmi_dcd_display_manual_update_info(eDCD_MSG_SYNCPKG_PARSING_SUCCESS);
            break;

        case eDCD_MSG_DOWNLOAD_CONTENT_SUCCESS:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_DOWNLOAD_CONTENT_SUCCESS);
            break;

        case eDCD_MSG_CONTENT_PARSING_SUCCESS:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_CONTENT_PARSING_SUCCESS);
            break;

        case eDCD_MSG_SYNC_COMPLETE:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNC_COMPLETE);
            if (g_dcd.is_retrying)
            {
                mmi_dcd_stop_retry();
            }
            if (g_dcd.ttl_timer_on)
            {
                StopTimer(DCD_TTL_TIMER);
                g_dcd.ttl_timer_on = MMI_FALSE;
            }

            if (DCD_SYNC_REQ_TYPE_MAN == g_dcd.sync_type && g_dcd.man_callback != NULL)
            {
                mmi_dcd_display_manual_update_info(eDCD_MSG_SYNC_COMPLETE);
            }
            else
            {
                mmi_dcd_sync_prompt(MMI_TRUE);
            }

            ttl_delay = emDCDAgent_GetSyncPkgTTL(g_dcd_agent.agent_handle);
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TTL_VALUE, ttl_delay);

            mmi_dcd_log_sync_result(1, 0);
            if (ttl_delay > 0)
            {
                kal_uint32  ticks;
                if ((g_dcd.sync_type == DCD_SYNC_REQ_TYPE_MAN) && (g_dcd.man_callback != NULL) &&
                    (g_dcd.conn_mode == DCD_CONN_MODE_MANUAL))
                {
                    /* when conn_mode is manual, need to manual update after manual update */
                }
                else
                {
                    MMI_BOOL        sync_allowed;
                    sync_allowed = mmi_dcd_sync_is_allowed(DCD_SYNC_REQ_TYPE_TTL, g_dcd.conn_mode, g_dcd.is_roaming);
                    if (sync_allowed)
                    {
                        mmi_dcd_log_next_sync_time(ttl_delay/1000);
                        mmi_dcd_log_next_sync_type(DCD_SYNC_REQ_TYPE_TTL);
                        StartTimer(DCD_TTL_TIMER, ttl_delay, mmi_dcd_ttl_timer_handler);
                        g_dcd.ttl_timer_on = MMI_TRUE;
                    }
                }
                kal_get_time(&ticks);
                ticks = kal_ticks_to_milli_secs(ticks);
                g_dcd.last_sync_end = ticks;
                g_dcd.last_ttl      = ttl_delay;
            }

            g_dcd.man_callback  = NULL;
            g_dcd.is_syncing    = MMI_FALSE;
            g_dcd.state         = DCD_STATE_IDLE;
            g_dcd.sync_type     = DCD_SYNC_REQ_TYPE_MAX;
            g_dcd.postponed_req = DCD_SYNC_REQ_TYPE_MAX;

            mmi_dcd_disconnect_bearer();
            break;
            
        case eDCD_MSG_ERR_STORAGE_FULL:
        case eDCD_MSG_ERR_SYNCPKG_PARSING: 
        case eDCD_MSG_ERR_NO_SYNCPKG:
        case eDCD_MSG_ERR_CONTENT_PARSING:
        case eDCD_MSG_ERR_NO_CONTENT:
        case eDCD_MSG_ERR_NETWORK_DISABLE:
        case eDCD_MSG_ERR_NETWORK_BUSY:
        case eDCD_MSG_ERR_DOWNLOAD_SYNCPKG:
        case eDCD_MSG_ERR_DOWNLOAD_CONTENT:
        case eDCD_MSG_ERR_CONNECT_TIME_OUT:
        case eDCD_MSG_ERR_SYNC:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_ERR_SYNC, a_eMsgCode);
            g_dcd.errcode = mmi_dcd_mapping_err_code(a_eMsgCode);
            mmi_dcd_log_sync_result(0, (U8)g_dcd.errcode);                
            if (g_dcd.sync_type == DCD_SYNC_REQ_TYPE_MAN && g_dcd.man_callback != NULL)
            {
                if (a_eMsgCode == eDCD_MSG_ERR_STORAGE_FULL)
                {
                    mmi_dcd_display_manual_update_info(eDCD_MSG_ERR_STORAGE_FULL);
                }
                else
                {
                    mmi_dcd_display_manual_update_info(eDCD_MSG_ERR_SYNC);
                }
            }
            else
            {
                mmi_dcd_sync_prompt(MMI_FALSE);
            }

            g_dcd.is_syncing = MMI_FALSE;
            g_dcd.state = DCD_STATE_IDLE;
            g_dcd.postponed_req = DCD_SYNC_REQ_TYPE_MAX;
            if (!((g_dcd.sync_type == DCD_SYNC_REQ_TYPE_MAN) && (g_dcd.man_callback != NULL)))
            {
                mmi_dcd_retry();
            }
            g_dcd.man_callback = NULL;
            mmi_dcd_disconnect_bearer();
            break;

        case eDCD_MSG_ERR_INSUFFICIENT_MEMORY:
            /* just ignore it */
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNC_DEFAULT, a_eMsgCode);
            break;

        case eDCD_MSG_SYNCPKG_UPDATE:
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNC_DEFAULT, a_eMsgCode);
            break;

        default:
            /* default handling */
            MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_MSG_SYNC_DEFAULT, a_eMsgCode);
            break;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_ttl_timer_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_ttl_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dcd_return_enum  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TTL_TIMER_HANDLER);
    StopTimer(DCD_TTL_TIMER);
    g_dcd.ttl_timer_on = FALSE;

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_STATUS, g_dcd.conn_mode, g_dcd.is_roaming);

    result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_TTL, NULL);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_TTL, result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_retry_timer_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_retry_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dcd_return_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_RETRY_TIMER_HANDLER);
    StopTimer(DCD_RETRY_TIMER);
    g_dcd.retry_timer_on = MMI_FALSE;
    result = mmi_dcd_start_sync(DCD_SYNC_REQ_TYPE_RETRY, NULL);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SYNC_RESULT, DCD_SYNC_REQ_TYPE_RETRY, result);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  agent        [IN] dcd agent handle
 *  req_type     [IN] request type
 *  url          [IN] url for push sync
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_dcd_sync_request(HDCD_Agent agent, U8 req_type, S8 *url, S32 errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_REQUEST_TYPE  request;
    EDCD_AGENT_RESULT  result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dcd_sync_before(); /* register protocol event handler */

    switch (req_type)
    {
    case DCD_SYNC_REQ_TYPE_SIM:
        request = eDCD_RT_START_REQUEST;
        break;

    case DCD_SYNC_REQ_TYPE_RESET:
        request = eDCD_RT_START_REQUEST;
        break;

    case DCD_SYNC_REQ_TYPE_START:
        request = eDCD_RT_START_REQUEST;
        break;

    case DCD_SYNC_REQ_TYPE_SVR:
        request = eDCD_RT_SERVER_REQUEST;
        break;

    case DCD_SYNC_REQ_TYPE_TTL:
        request = eDCD_RT_TTL_EXPIRED_REQUEST;
        break;

    case DCD_SYNC_REQ_TYPE_RETRY:
        request = eDCD_RT_RETRY_REQUEST;
        break;

    default:
        request = eDCD_RT_USER_REQUEST;
        break;
    }
    
    if (request == eDCD_RT_SERVER_REQUEST)
    {
        result = emDCDAgent_OnWAPPush(agent, (BRSTR)url);
    }
    else if (request == eDCD_RT_RETRY_REQUEST)
    {
        result = emDCDAgent_OnRetrySyncRequest(agent, errcode);
    }
    else
    {
        result = emDCDAgent_OnSyncRequest(agent, request);
    }
    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_AFTER_SYNC_REQUEST, result);

    return result; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_start_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_type        [IN]        
 *  url             [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
static dcd_return_enum mmi_dcd_start_sync(U8 req_type, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             result;
    MMI_BOOL        sync_allowed;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_START_SYNC, req_type);

    /* sync type priority handle */
    if (g_dcd.is_syncing == MMI_TRUE)
    {
        /*
        if (req_type < g_dcd.sync_type) {
            mmi_dcd_stop_sync();
        }
        else
        {
            return DCD_RETURN_HIGH_PRIORITY_SYNC_EXIST;
        }

        */
        return DCD_RETURN_HIGH_PRIORITY_SYNC_EXIST;
    }

    /* connection parameter handle */    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_CONN_STATUS, g_dcd.conn_mode, g_dcd.is_roaming);
    sync_allowed = mmi_dcd_sync_is_allowed(req_type, g_dcd.conn_mode, g_dcd.is_roaming);
    if (!sync_allowed)
    {
        if ((req_type == DCD_SYNC_REQ_TYPE_RETRY) || (req_type == DCD_SYNC_REQ_TYPE_TTL))
        {
            if (g_dcd_update_log.next_sync_type == req_type)
            {
                mmi_dcd_log_reset_next_sync_time();
            }
        }
        if (req_type == DCD_SYNC_REQ_TYPE_RETRY)
        {
            g_dcd.is_retrying = MMI_FALSE;
        }
        return DCD_RETURN_SYNC_NOT_ALLOWED;
    }

    /* stop retry timer */
    if (!(g_dcd.is_retrying && req_type == DCD_SYNC_REQ_TYPE_RETRY))
    {
        if (g_dcd.retry_timer_on)
        {
            StopTimer(DCD_RETRY_TIMER);
            g_dcd.retry_timer_on = MMI_FALSE;
        }
		g_dcd.is_retrying = MMI_FALSE;
		g_dcd.retry_times = 0;
    }
    
    /* stop ttl timer */
    if (g_dcd.ttl_timer_on)
    {
		MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_STOP_TTL_TIMER);
        g_dcd.ttl_timer_on = MMI_FALSE;
        StopTimer(DCD_TTL_TIMER);
    }

    g_dcd.sync_type = req_type;
    /* go to sync */
    if (g_dcd.line_taken > 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNC_POSTPONED, g_dcd.line_taken);
        g_dcd.state         = DCD_STATE_POSTPONED;
        g_dcd.postponed_req = req_type;
        g_dcd.is_syncing    = MMI_TRUE;
		return DCD_RETURN_SYNC_POSTPONED;
    }
    else
    {
        result = mmi_dcd_sync_request(g_dcd_agent.agent_handle, req_type, url, g_dcd.errcode);

        if (result != eDCD_SUCCESS)
        {
            if ((req_type == DCD_SYNC_REQ_TYPE_MAN) && (g_dcd.man_callback != NULL))
            {
                g_dcd.man_callback(MMI_FALSE);
                g_dcd.man_callback = NULL;
            }
            g_dcd.is_syncing = MMI_FALSE;
            g_dcd.state      = DCD_STATE_IDLE;
			return DCD_RETURN_FAILURE;
        }
		else
		{
            g_dcd.is_syncing = MMI_TRUE;
            g_dcd.state      = DCD_STATE_SYNCING;
			return DCD_RETURN_SUCCESS;
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_stop_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_stop_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EDCD_AGENT_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_STOP_SYNC, g_dcd.sync_type);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNC_STATE, g_dcd.state);

    if (DCD_STATE_SYNCING == g_dcd.state || DCD_STATE_SUSPENDED == g_dcd.state)
    {
        /* stop sync */
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_SYNC_TYPE_VALUE, g_dcd.sync_type);
        result = emDCDAgent_OnStopSyncRequest(g_dcd_agent.agent_handle);
        if (DCD_SYNC_REQ_TYPE_MAN == g_dcd.sync_type && NULL != g_dcd.man_callback)
        {
            g_dcd.man_callback(MMI_FALSE);
            g_dcd.man_callback = NULL;
        }
    }
    else if (DCD_STATE_POSTPONED == g_dcd.state)
    {
        /* delete postponed sync request */
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_POSTPONED_SYNC_TYPE_VALUE, g_dcd.postponed_req);
        if (DCD_SYNC_REQ_TYPE_MAN == g_dcd.postponed_req && NULL != g_dcd.man_callback)
        {
            g_dcd.man_callback(MMI_FALSE);
            g_dcd.man_callback = NULL;
        }

        g_dcd.postponed_req = DCD_SYNC_REQ_TYPE_MAX;
    }

    g_dcd.is_syncing = MMI_FALSE;
    g_dcd.sync_type  = DCD_SYNC_REQ_TYPE_MAX;
    g_dcd.state      = DCD_STATE_IDLE;

    mmi_dcd_log_sync_result(3, 0);
    mmi_dcd_disconnect_bearer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_retry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_retry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 retry_delay;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_RETRY, g_dcd.sync_type);
 
    g_dcd.is_retrying = MMI_TRUE;

    g_dcd.retry_times++;
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_RETRY_TIMES_VALUE, g_dcd.retry_times);
    retry_delay = g_dcd.retry_times * 5;
    retry_delay = (retry_delay > 120) ? 120 : retry_delay;
    retry_delay = retry_delay * 60 * 1000;
    StartTimer(DCD_RETRY_TIMER, retry_delay, mmi_dcd_retry_timer_handler);
    g_dcd.retry_timer_on = MMI_TRUE;

    mmi_dcd_log_next_sync_time(retry_delay/1000);
    mmi_dcd_log_next_sync_type(DCD_SYNC_REQ_TYPE_RETRY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_stop_retry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_stop_retry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_STOP_RETRY, g_dcd.sync_type);

    if (g_dcd.retry_timer_on)
    {
        g_dcd.retry_timer_on = MMI_FALSE;
        StopTimer(DCD_RETRY_TIMER);
    }

    g_dcd.is_retrying = MMI_FALSE;
    g_dcd.retry_times = 0;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_get_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_sync_get_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_dcd.conn_mode = g_mmi_dcd_setting_cntx_p->dcd_conn_mode;

    g_dcd.dcd_switch = MMI_DCD_GET_SYNC_SWITCH(g_mmi_dcd_setting_cntx_p->dcd_switch, g_mmi_dcd_setting_cntx_p->dcd_flymode);

    if (g_mmi_dcd_setting_cntx_p->dcd_new_sim)
    {
        g_dcd.is_new_sim = MMI_TRUE;
    }
    else
    {
        g_dcd.is_new_sim = MMI_FALSE;
    }

    if (g_mmi_dcd_setting_cntx_p->dcd_restore)
    {
        g_dcd.is_reset = MMI_TRUE;
    }
    else
    {
        g_dcd.is_reset = MMI_FALSE;
    }

    /* foreign roaming state has not been initialized */
    if (!g_dcd_is_ready_to_sync)
    {
        g_dcd.is_roaming = MMI_FALSE;
    }

    g_dcd.line_taken     = 0;
    g_dcd.postponed_req  = DCD_SYNC_REQ_TYPE_MAX;
    g_dcd.is_retrying    = MMI_FALSE;
    g_dcd.retry_timer_on = MMI_FALSE;
    g_dcd.retry_times    = 0;
    g_dcd.is_syncing     = MMI_FALSE;
    g_dcd.state          = DCD_STATE_IDLE;
    g_dcd.sync_type      = DCD_SYNC_REQ_TYPE_MAX;
    g_dcd.ttl_timer_on   = MMI_FALSE;
    g_dcd.man_callback   = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_sync_set_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE != g_dcd.is_new_sim)
    {
        g_mmi_dcd_setting_cntx_p->dcd_new_sim = TRUE;
    }
    else
    {
        g_mmi_dcd_setting_cntx_p->dcd_new_sim = FALSE;
    }

    if (MMI_FALSE != g_dcd.is_reset)
    {
        g_mmi_dcd_setting_cntx_p->dcd_restore = TRUE;
    }
    else
    {
        g_mmi_dcd_setting_cntx_p->dcd_restore = FALSE;
    }

    mmi_dcd_write_setting_value();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_get_sync_err_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_dcd_get_sync_err_code(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd.errcode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_manual_updte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_manual_updte(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DCD_SYNC_REQ_TYPE_MAN == g_dcd.sync_type && g_dcd.man_callback != NULL)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_line_taken
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_line_taken(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd.line_taken > 0)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_syncing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_syncing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd.is_syncing)
    {
        if (g_dcd.state == DCD_STATE_SYNCING)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_log_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_log_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_dcd_update_log, 0, sizeof(mmi_dcd_update_log_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_log_last_sync_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_log_last_sync_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct  dt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&dt);

    g_dcd_update_log.last_year  = dt.nYear;      /* last sync time */
    g_dcd_update_log.last_month = dt.nMonth;
    g_dcd_update_log.last_day   = dt.nDay;
    g_dcd_update_log.last_hour  = dt.nHour;
    g_dcd_update_log.last_minute= dt.nMin;
    g_dcd_update_log.last_second= dt.nSec;

    g_dcd_update_log.sync_result= 2;
    g_dcd_update_log.last_sync_type = g_dcd.sync_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_log_next_sync_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_log_next_sync_time(U32 secs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct  dt;
    U32     utc_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&dt);

    utc_sec = mmi_dt_mytime_2_utc_sec(&dt, 0);
    utc_sec += secs;
    mmi_dt_utc_sec_2_mytime(utc_sec, &dt, 0);

    g_dcd_update_log.next_year  = dt.nYear;      /* last sync time */
    g_dcd_update_log.next_month = dt.nMonth;
    g_dcd_update_log.next_day   = dt.nDay;
    g_dcd_update_log.next_hour  = dt.nHour;
    g_dcd_update_log.next_minute= dt.nMin;
    g_dcd_update_log.next_second= dt.nSec;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_log_sync_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sync_result:  0:failed;  1:success;  2: syncing; 3: cancel 
 *  fail_cause: 1->701  ~~ 7->707
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_log_sync_result(U8 sync_result, U8 fail_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_update_log.sync_result    = sync_result;
    g_dcd_update_log.fail_cause     = fail_cause;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_log_sync_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sync_result:  0:failed;  1:success;  2: syncing 
 *  fail_cause: 1->701  ~~ 7->707
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_log_next_sync_type(U8 sync_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_update_log.next_sync_type = sync_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_log_reset_next_sync_time
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_log_reset_next_sync_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dcd_update_log.next_year  = 0;
    g_dcd_update_log.next_month = 0;
    g_dcd_update_log.next_day   = 0;
    g_dcd_update_log.next_hour  = 0;
    g_dcd_update_log.next_minute= 0;
    g_dcd_update_log.next_second= 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_is_roaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_dcd_is_roaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dcd.is_roaming;
}

#endif /* __MMI_OP01_DCD__ */ 

