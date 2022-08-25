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
 * BTMMISPP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for SPP application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_SIMAP_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "BtcmSrvGprot.h"

/* SIM Access Profile */
#include "bluetooth_struct.h"
#include "BTMMISIMAP.h"
#include "BTMMISIMAPGprots.h"
#include "btbm_adp.h"
#include "BTMMIScrGprots.h"
#include "mmi_rp_app_bluetooth_def.h"

#include "xatypes.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "SimCtrlSrvGprot.h"


/***************************************************************************** 
* External Variable
*****************************************************************************/
extern U8 *BTBMGetLocalStoredName(U8 *bdAddr);
extern void CONVERT_BDADDR2ARRAY(U8 *dest, U32 lap, U8 uap, U16 nap);
extern MMI_BOOL srv_ucm_is_any_call(void);
/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_simap_cntx_struct g_mmi_simap_cntx[MMI_BTH_SIMAP_MAX_CONNECTION];
mmi_simap_cntx_struct* g_mmi_simap_cntx_p = g_mmi_simap_cntx;
static const srv_bt_cm_profile_struct g_simap_prof = {
    SRV_BT_CM_SIM_ACCESS_PROFILE_UUID,
    mmi_bt_simap_activate,
    mmi_bt_simap_deactivate,
    mmi_bt_simap_disconnect
};

/***************************************************************************** 
* Function
*****************************************************************************/
/*****************************************************************************
* FUNCTION
*	mmi_bth_simap_init
* DESCRIPTION
*	 This function is to
*
* PARAMETERS
*	a	IN/OUT		first variable, used as returns
*	b	IN 		second variable
* RETURNS
*	NONE.
* GLOBALS AFFECTED
*	 external_global
*****************************************************************************/
void mmi_bth_simap_init(void)
{
    U32 i = 0;
	mmi_bth_simap_event_handler();

	for(i = 0; i < MMI_BTH_SIMAP_MAX_CONNECTION; i++)
	{
	    g_mmi_simap_cntx[i].state = MMI_BTH_SIMAP_STAT_IDLE;
	    g_mmi_simap_cntx[i].connect_id = 0;
        g_mmi_simap_cntx[i].bt_addr.lap = 0;
	    g_mmi_simap_cntx[i].bt_addr.uap = 0;
	    g_mmi_simap_cntx[i].bt_addr.nap = 0;
	}

    srv_bt_cm_profile_register(&g_simap_prof);
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_init_simap_event_handler
* DESCRIPTION
*   This function is to
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_simap_event_handler(void)
{
    /* Init protocol event handler */
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_SIMAP_ACTIVATE_CNF, (PsIntFuncPtr)mmi_bth_simap_activate_cnf, MMI_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_SIMAP_DEACTIVATE_CNF, (PsIntFuncPtr)mmi_bth_simap_deactivate_cnf, MMI_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_SIMAP_DISCONNECT_CNF, (PsIntFuncPtr)mmi_bth_simap_disconnect_cnf, MMI_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_SIMAP_CONNECT_IND, (PsIntFuncPtr)mmi_bth_simap_connect_ind, MMI_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_SIMAP_DISCONNECT_IND, (PsIntFuncPtr)mmi_bth_simap_disconnect_ind, MMI_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_SIMAP_AUTH_REQ, (PsIntFuncPtr)mmi_bth_simap_authorize_ind, MMI_FALSE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}



/* For BT2.0 and 2.1 SIMAP Usage */
void mmi_bth_simap_authorize_ind(void* msg)
{
    /* In this case: it is applied for after BT Profile v2.1 and is requested by operator */
    bt_simap_auth_req_struct* bt_simap_auth_req = (bt_simap_auth_req_struct*)msg;
    U8* name = NULL;
	U8 bd_addr[6];
    S32 conn_id;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_SIMAP_AUTHORIZE_IND, g_mmi_simap_cntx_p->state);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_ACTIVATE:
        {
            if (!srv_ucm_is_any_call() && srv_sim_ctrl_any_sim_is_available())
    		{
				g_mmi_simap_cntx_p->used_sim_id = 0;
                g_mmi_simap_cntx_p->bt_addr.lap = bt_simap_auth_req->lap;
                g_mmi_simap_cntx_p->bt_addr.uap = bt_simap_auth_req->uap;
                g_mmi_simap_cntx_p->bt_addr.nap = bt_simap_auth_req->nap;

				CONVERT_BDADDR2ARRAY(bd_addr, bt_simap_auth_req->lap, bt_simap_auth_req->uap, bt_simap_auth_req->nap);
    			name = BTBMGetLocalStoredName(bd_addr);
				
                conn_id = srv_bt_cm_start_conn(MMI_TRUE, SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, &g_mmi_simap_cntx_p->bt_addr, (CHAR* )name);
		        if (conn_id < 0)
		        {
		            mmi_bt_simap_authorize_rsp(&g_mmi_simap_cntx_p->bt_addr, (U32)SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, MMI_FALSE);
		            return;
		        }
                g_mmi_simap_cntx_p->cmgr_id = conn_id;
                g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_AUTHORIZING;

        		mmi_bt_authorize_ind_notify(
					name, 
					&g_mmi_simap_cntx_p->bt_addr,
					SRV_BT_CM_SIM_ACCESS_PROFILE_UUID,
					(void *)mmi_bt_simap_authorize_rsp
					);
    		}
    		else
                mmi_bt_simap_authorize_rsp(&g_mmi_simap_cntx_p->bt_addr, (U32)SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, MMI_FALSE);
            break;
        }
        default:
            mmi_bt_simap_authorize_rsp(&g_mmi_simap_cntx_p->bt_addr, (U32)SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, MMI_FALSE);
            break;
    }
}

/* For BT2.1 SIMAP Usage */
void mmi_bt_simap_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 profile_id, U32 result)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_SIMAP_AUTHORIZE_RSP, g_mmi_simap_cntx_p->state, result);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_AUTHORIZING:
        { 
	        bt_simap_auth_rsp_struct* bt_simap_auth_rsp = NULL;
	        bt_simap_auth_rsp = construct_local_para (sizeof(bt_simap_auth_rsp_struct),TD_UL);
	        bt_simap_auth_rsp->result = (MMI_BOOL)result;     
            #ifdef __GEMINI__
			bt_simap_auth_rsp->sim_card_id = (U8)srv_bt_cm_get_binding_sim(&g_mmi_simap_cntx_p->bt_addr);
			g_mmi_simap_cntx_p->used_sim_id = bt_simap_auth_rsp->sim_card_id;
            #endif
	        
	        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_AUTH_RSP, (local_para_struct*)bt_simap_auth_rsp, NULL);

	        if (!result)
	        {
                srv_bt_cm_stop_conn(g_mmi_simap_cntx_p->cmgr_id);
    			g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_ACTIVATE;
	        }
	        else
				g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_AUTHORIZED;
	            break;
	    }
		case MMI_BTH_SIMAP_STAT_ACTIVATE:
		{	bt_simap_auth_rsp_struct* bt_simap_auth_rsp = NULL;
	        bt_simap_auth_rsp = construct_local_para (sizeof(bt_simap_auth_rsp_struct),TD_UL);
	        bt_simap_auth_rsp->result = (MMI_BOOL)result; 
			srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_AUTH_RSP, (local_para_struct*)bt_simap_auth_rsp, NULL);
			break;
		}
        default:
            break;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_activate_req_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
MMI_BOOL mmi_bt_simap_activate()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SIMAP_ACTIVATE, g_mmi_simap_cntx_p->state);
    if (g_mmi_simap_cntx_p->state == MMI_BTH_SIMAP_STAT_IDLE)
	    g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_ACTIVATING;
    else
        return MMI_FALSE;

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_ACTIVATE_REQ, NULL, NULL);
    return MMI_TRUE;
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_activate_cnf_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_simap_activate_cnf(void *msg)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SIMAP_ACTIVATE_CNF, g_mmi_simap_cntx_p->state);
    if (g_mmi_simap_cntx_p->state != MMI_BTH_SIMAP_STAT_ACTIVATING) MMI_ASSERT(0);
	
    g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_ACTIVATE;
    srv_bt_cm_activate_cnf_hdler((U32)SRV_BT_CM_SIM_ACCESS_PROFILE_UUID);
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_deactivate_req_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_simap_deactivate(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SIMAP_DEACTIVATE, g_mmi_simap_cntx_p->state);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_ACTIVATE:
        case MMI_BTH_SIMAP_STAT_ACTIVATING:
		case MMI_BTH_SIMAP_STAT_AUTHORIZING:
		{
			mmi_bt_authorize_screen_close(SRV_BT_CM_SIM_ACCESS_PROFILE_UUID);
			mmi_bt_simap_authorize_rsp(&g_mmi_simap_cntx_p->bt_addr, SRV_BT_CM_SIM_ACCESS_PROFILE_UUID, MMI_FALSE);
		}
        case MMI_BTH_SIMAP_STAT_AUTHORIZED:
        {
			srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_DEACTIVATE_REQ, NULL, NULL);
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_DEACTIVATING;
            break;
        }
        case MMI_BTH_SIMAP_STAT_CONNECT:
        {
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_DISCONNECT_REQ, NULL, NULL);
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_DEACTIVATING;
            break;
        }
        default:
            break;
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_deactivate_cnf_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_simap_deactivate_cnf(void *msg)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BTH_SIMAP_DEACTIVATE_CNF, g_mmi_simap_cntx_p->state);
    srv_bt_cm_deactivate_cnf_hdler((U32)SRV_BT_CM_SIM_ACCESS_PROFILE_UUID);
    switch (g_mmi_simap_cntx_p->state)
	{
        case MMI_BTH_SIMAP_STAT_DEACTIVATING:
		{
			g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_IDLE;
           	break;
        }
        default:
            break;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_connect_ind_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_simap_connect_ind(void *msg)
{
    bt_simap_connect_ind_struct *msg_p = (bt_simap_connect_ind_struct *)msg;
    U16 str_popup[60];

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BTH_SIMAP_CONNECT_IND, g_mmi_simap_cntx_p->state);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_AUTHORIZED:
        {
            if (g_mmi_simap_cntx_p->bt_addr.lap != msg_p->lap ||
                g_mmi_simap_cntx_p->bt_addr.uap != msg_p->uap ||
                g_mmi_simap_cntx_p->bt_addr.nap != msg_p->nap)
        {
                MMI_ASSERT(0);
            }
            g_mmi_simap_cntx_p->connect_id = msg_p->cid;
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_CONNECT;
            srv_bt_cm_connect_ind(g_mmi_simap_cntx_p->cmgr_id);

            kal_wsprintf(
                str_popup,
                "%w%w",
                (WCHAR*)GetString(STR_BT_PROF_SAP),
                (WCHAR*)GetString(STR_BT_CONN_ED)
                );
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)str_popup);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_disconnect_req_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bt_simap_disconnect(U32 cmgr_id)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_SIMAP_DISCONNECT, g_mmi_simap_cntx_p->state);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_CONNECT:
        {
            if (g_mmi_simap_cntx_p->cmgr_id == cmgr_id)
        	{
            	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_DISCONNECT_REQ, NULL, NULL);
                g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_DISCONNECT;
            }
            break;
        }
        default:
            break;
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_disconnect_cnf_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_simap_disconnect_cnf(void *msg)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BTH_SIMAP_DISCONNECT_CNF, g_mmi_simap_cntx_p->state);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_DISCONNECT:
        {
            g_mmi_simap_cntx_p->connect_id = 0;
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_ACTIVATE;

            srv_bt_cm_stop_conn(g_mmi_simap_cntx_p->cmgr_id);
            g_mmi_simap_cntx_p->cmgr_id = 0;
            g_mmi_simap_cntx_p->bt_addr.lap = 0;
            g_mmi_simap_cntx_p->bt_addr.uap = 0;
            g_mmi_simap_cntx_p->bt_addr.nap = 0;

            break;
        }
        case MMI_BTH_SIMAP_STAT_DEACTIVATING:
        {
            g_mmi_simap_cntx_p->connect_id = 0;
            srv_bt_cm_stop_conn(g_mmi_simap_cntx_p->cmgr_id);
            g_mmi_simap_cntx_p->cmgr_id = 0;
            g_mmi_simap_cntx_p->bt_addr.lap = 0;
            g_mmi_simap_cntx_p->bt_addr.uap = 0;
            g_mmi_simap_cntx_p->bt_addr.nap = 0;
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_DEACTIVATE_REQ, NULL, NULL);
            break;
    	}
        default:
            break;       
	}
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_simap_disconnect_ind_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_simap_disconnect_ind(void *msg)
{
    U16 string[60];
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BTH_SIMAP_DISCONNECT_IND, g_mmi_simap_cntx_p->state);
    switch (g_mmi_simap_cntx_p->state)
    {
        case MMI_BTH_SIMAP_STAT_AUTHORIZING:
		case MMI_BTH_SIMAP_STAT_AUTHORIZED:
    	{
    		mmi_bt_authorize_screen_close(SRV_BT_CM_SIM_ACCESS_PROFILE_UUID);
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_ACTIVATE;
            break;
    	}
        case MMI_BTH_SIMAP_STAT_DEACTIVATING:
        {
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_IDLE;
            break;
        }
        default:
		{
			mmi_wcscpy((WCHAR *)string, (const WCHAR *) GetString(STR_BT_PROF_SAP));
			mmi_wcscat((WCHAR *)string, (const WCHAR *)GetString(STR_BT_DISCON_ED));
			mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)string);
            g_mmi_simap_cntx_p->state = MMI_BTH_SIMAP_STAT_ACTIVATE;
            break;
		}
   
	}
    srv_bt_cm_stop_conn(g_mmi_simap_cntx_p->cmgr_id);
    g_mmi_simap_cntx_p->cmgr_id = 0;
    g_mmi_simap_cntx_p->connect_id = 0;
        
    g_mmi_simap_cntx_p->bt_addr.lap = 0;
    g_mmi_simap_cntx_p->bt_addr.uap = 0;
    g_mmi_simap_cntx_p->bt_addr.nap = 0;
}

void mmi_bth_simap_send_status_ind_with_unavailable_req(void)
{
    if(g_mmi_simap_cntx_p->state == MMI_BTH_SIMAP_STAT_CONNECT)/* Only in connected state: it is allowed to send this message for PTS Testing */
		srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SIMAP_SEND_STATUS_IND_WITH_UNAVAILABLE_REQ, NULL, NULL);
}

MMI_BOOL mmi_bt_is_simap_activate(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_IS_SIMAP_ACTIVATE, g_mmi_simap_cntx_p->state);
	if (g_mmi_simap_cntx_p->state >= MMI_BTH_SIMAP_STAT_ACTIVATE &&
		g_mmi_simap_cntx_p->state < MMI_BTH_SIMAP_STAT_DEACTIVATING)
    {
    	return MMI_TRUE;
    }
	else
	{
		return MMI_FALSE;
	}
}

void mmi_bt_simap_hotswap_handlr(U8 sim_id)
{
	switch(g_mmi_simap_cntx_p->state)
	{
		case MMI_BTH_SIMAP_STAT_CONNECT:
		{
			if (sim_id == g_mmi_simap_cntx_p->used_sim_id
				&& !srv_sim_ctrl_any_sim_is_available())
			{
				mmi_bt_simap_deactivate();
			}
			else if (sim_id == g_mmi_simap_cntx_p->used_sim_id)
			{
				mmi_bt_simap_disconnect(g_mmi_simap_cntx_p->cmgr_id);
			}
			break;
		}
	}
}
#endif //__MMI_SIMAP_SUPPORT__
