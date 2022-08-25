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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_MTK_SUPPORT__
#ifdef __MMI_FAX_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ExtDeviceDefs.h"
#include "BtcmSrvGprot.h"
#include "bluetooth_struct.h"
#include "BTMMIFax.h"
#include "BTMMIFaxGprots.h"

#include "bluetooth_bm_struct.h"
#include "btbm_adp.h"
#include "BTMMIScrGprots.h"
#include "mmi_rp_app_bluetooth_def.h"

#include "xatypes.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "MMIDataType.h"
#include "string.h"
#include "stack_common.h"
#include "stack_config.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"


/***************************************************************************** 
* External Variable
*****************************************************************************/

extern U8 *BTBMGetLocalStoredName(U8 *bdAddr);

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_fax_cntx_struct g_mmi_fax_cntx[MMI_BTH_FAX_MAX_CONNECTION];

static const srv_bt_cm_profile_struct g_fax_prof = {
    SRV_BT_CM_FAX_PROFILE_UUID,
    mmi_bt_fax_activate,
    mmi_bt_fax_deactivate,
    mmi_bt_fax_disconnect
};


/***************************************************************************** 
* Function
*****************************************************************************/
/*****************************************************************************
* FUNCTION
* mmi_bth_spp_init
* DESCRIPTION
* This function is to
*
* PARAMETERS
* N/OUT		first variable, used as returns
* N 		second variable
* RETURNS
* ONE.
* GLOBALS AFFECTED
*	 external_global
*****************************************************************************/
void mmi_bth_fax_init(void)
{
    kal_int8 i = 0;
    
    mmi_bth_init_fax_event_handler();
    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_IDLE;
        g_mmi_fax_cntx[i].connect_id = 0;
        g_mmi_fax_cntx[i].port = 0;
        g_mmi_fax_cntx[i].lap = 0;
        g_mmi_fax_cntx[i].uap = 0;
        g_mmi_fax_cntx[i].nap = 0;
    }

    srv_bt_cm_profile_register(&g_fax_prof);
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_init_event_handler
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
void mmi_bth_init_fax_event_handler(void)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_INIT_EVENT_HDLR );

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_bth_fax_activate_cnf_hdler, MSG_ID_BT_FAX_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_fax_deactivate_cnf_hdler, MSG_ID_BT_FAX_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_fax_disconnect_cnf_hdler, MSG_ID_BT_FAX_DISCONNECT_CNF);
    SetProtocolEventHandler(mmi_bth_fax_connect_ind_hdler, MSG_ID_BT_FAX_CONNECT_IND);
    SetProtocolEventHandler(mmi_bth_fax_disconnect_ind_hdler, MSG_ID_BT_FAX_DISCONNECT_IND);
    SetProtocolEventHandler(mmi_bth_fax_connect_ind_req_hdler, MSG_ID_BT_FAX_CONNECT_IND_REQ);
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_activate_req_hdler
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
void mmi_bt_fax_activate(void)
{
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_FAX_ACTIVATE_REQ, NULL, NULL);
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_activate_cnf_hdler
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
void mmi_bth_fax_activate_cnf_hdler(void *msg)
{
    kal_uint8 i;
    srv_bt_cm_activate_cnf_hdler((U32)SRV_BT_CM_FAX_PROFILE_UUID);
    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_ACTIVATE;
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_deactivate_req_hdler
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
void mmi_bt_fax_deactivate(void)
{
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_FAX_DEACTIVATE_REQ, NULL, NULL);
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_deactivate_cnf_hdler
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
void mmi_bth_fax_deactivate_cnf_hdler(void *msg)
{
    kal_uint8 i;
    srv_bt_cm_deactivate_cnf_hdler((U32)SRV_BT_CM_FAX_PROFILE_UUID);

    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_IDLE;
        g_mmi_fax_cntx[i].connect_id = 0;
        g_mmi_fax_cntx[i].port = 0;
        g_mmi_fax_cntx[i].lap = 0;
        g_mmi_fax_cntx[i].uap = 0;
        g_mmi_fax_cntx[i].nap = 0;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_connect_ind_hdler
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
void mmi_bth_fax_connect_ind_hdler(void *msg)
{
    bt_fax_connect_ind_struct *msg_p = (bt_fax_connect_ind_struct *)msg;
    kal_uint8 i;
    kal_uint8 bd_addr[6];
    kal_uint8* name = NULL;
    srv_bt_cm_bt_addr bt_addr;
    U16 str_popup[60];

    bt_addr.lap = msg_p->lap;
    bt_addr.uap = msg_p->uap;
    bt_addr.nap = msg_p->nap;

    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        if(g_mmi_fax_cntx[i].state == MMI_BTH_FAX_STAT_AUTHORIZED)
        {
            g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_CONNECT;
            g_mmi_fax_cntx[i].connect_id = msg_p->cid;
            g_mmi_fax_cntx[i].port = (U16)msg_p->port;
            g_mmi_fax_cntx[i].lap = msg_p->lap;
            g_mmi_fax_cntx[i].uap = msg_p->uap;
            g_mmi_fax_cntx[i].nap = msg_p->nap;
            srv_bt_cm_connect_ind(g_mmi_fax_cntx[i].cmgr_id);
            kal_wsprintf(
                str_popup,
                "%w%w",
                (WCHAR*)GetString(STR_BT_PROF_FAX),
                (WCHAR*)GetString(STR_BT_CONN_ED)
                );
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)str_popup);
            break;
        }
    }

    CONVERT_BDADDR2ARRAY(bd_addr, msg_p->lap, msg_p->uap, msg_p->nap);
    name = BTBMGetLocalStoredName(bd_addr);
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_disconnect_req_hdler
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
void mmi_bt_fax_disconnect(U32 cmgr_id)
{
    kal_uint8 i;
    bt_fax_disconnect_req_struct* msg_p;

    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        if(g_mmi_fax_cntx[i].cmgr_id == cmgr_id)
        {
            msg_p = (bt_fax_disconnect_req_struct*)construct_local_para(sizeof(bt_fax_disconnect_req_struct), TD_CTRL);
            msg_p->port = g_mmi_fax_cntx[i].port;

            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_FAX_DISCONNECT_REQ, msg_p, NULL);
            g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_DISCONNECT;
            break;
        }
    }

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_disconnect_cnf_hdler
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
void mmi_bth_fax_disconnect_cnf_hdler(void *msg)
{
    kal_uint8 i;
    srv_bt_cm_bt_addr bt_addr;
    
    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        bt_addr.lap = g_mmi_fax_cntx[i]..lap;
        bt_addr.uap = g_mmi_fax_cntx[i]..uap;
        bt_addr.nap = g_mmi_fax_cntx[i]..nap;
        
        if(g_mmi_fax_cntx[i].state == MMI_BTH_FAX_STAT_DISCONNECT)
        {
            srv_bt_cm_stop_conn(g_mmi_fax_cntx[i].cmgr_id);
            g_mmi_fax_cntx[i].cmgr_id = 0;
            g_mmi_fax_cntx[i].connect_id = 0;
            g_mmi_fax_cntx[i].port = 0;
            g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_ACTIVATE;
            g_mmi_fax_cntx[i].lap = 0;
            g_mmi_fax_cntx[i].uap = 0;
            g_mmi_fax_cntx[i].nap = 0;
            break;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_disconnect_ind_hdler
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
void mmi_bth_fax_disconnect_ind_hdler(void *msg)
{
    bt_fax_disconnect_ind_struct *msg_p = (bt_fax_disconnect_ind_struct *)msg;
    U32 i;
    srv_bt_cm_bt_addr bt_addr;
	U32 string[30];
    
    for(i = 0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        bt_addr.lap = g_mmi_fax_cntx[i]..lap;
        bt_addr.uap = g_mmi_fax_cntx[i]..uap;
        bt_addr.nap = g_mmi_fax_cntx[i]..nap;
        
        if(msg_p->port == g_mmi_fax_cntx[i].port)
        {
            if(g_mmi_fax_cntx[i].state == MMI_BTH_FAX_STAT_AUTHORIZING)
            {
                mmi_bt_authorize_screen_close(SRV_BT_CM_FAX_PROFILE_UUID);
	        }
			else
            {
				mmi_wcscpy((WCHAR *)string, (const WCHAR *) GetString(STR_BT_PROF_FAX));
		
				mmi_wcscat((WCHAR *)string, (const WCHAR *)GetString(STR_BT_DISCON_ED));
		
				mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR *)string);
			}
            
                srv_bt_cm_stop_conn(g_mmi_fax_cntx[i].cmgr_id);
                g_mmi_fax_cntx[i].cmgr_id = 0;

            g_mmi_fax_cntx[i].connect_id = 0;
            g_mmi_fax_cntx[i].port = 0;
            g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_ACTIVATE;
            g_mmi_fax_cntx[i].lap = 0;
            g_mmi_fax_cntx[i].uap = 0;
            g_mmi_fax_cntx[i].nap = 0;

            break;
        }
    }
}

void mmi_bth_fax_connect_ind_req_hdler(void *msg)
{
    /* In this case: it is applied for after BT Profile v2.1 and is requested by operator */
    bt_fax_connect_ind_req_struct * bt_fax_con_ind_req = (bt_fax_connect_ind_req_struct *)msg;
    U8 fax_dev_name[MMI_BTH_FAX_MAX_DEV_NAME_LEN];
    srv_bt_cm_bt_addr mmi_bt_addr;  
    kal_uint8 i;
    S32 conn_id;

    memset((kal_uint8*)fax_dev_name,0,MMI_BTH_FAX_MAX_DEV_NAME_LEN);
    memset((kal_uint8*)&mmi_bt_addr,0,sizeof(mmi_bt_addr));
    mmi_bt_addr.lap = bt_fax_con_ind_req->lap;
    mmi_bt_addr.uap = bt_fax_con_ind_req->uap;
    mmi_bt_addr.nap = bt_fax_con_ind_req->nap;
        
    for(i=0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        if(g_mmi_fax_cntx[i].state == MMI_BTH_FAX_STAT_ACTIVATE)
        {
            g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_AUTHORIZING;
            g_mmi_fax_cntx[i].lap = mmi_bt_addr.lap;
            g_mmi_fax_cntx[i].uap = mmi_bt_addr.uap;
            g_mmi_fax_cntx[i].nap = mmi_bt_addr.nap;
            g_mmi_fax_cntx[i].port = bt_fax_con_ind_req->port;
            break;
        }
    }

    if(i != MMI_BTH_FAX_MAX_CONNECTION)
    {
        srv_bt_cm_get_dev_name(
            (srv_bt_cm_bt_addr * )&mmi_bt_addr,
            (U8)MMI_BTH_FAX_MAX_DEV_NAME_LEN,
            (U8*)fax_dev_name);

        conn_id = srv_bt_cm_start_conn(MMI_TRUE, SRV_BT_CM_FAX_PROFILE_UUID, &mmi_bt_addr, (U8 *)fax_dev_name);
        if (conn_id < 0)
        {
            mmi_bt_fax_authorize_rsp(&mmi_bt_addr, 0, MMI_FALSE);
            return;
        }
        g_mmi_fax_cntx[i].cmgr_id = conn_id;

        mmi_bt_authorize_ind_notify((U8 *)fax_dev_name, &mmi_bt_addr, SRV_BT_CM_FAX_PROFILE_UUID, 
            (void *)mmi_bt_fax_authorize_rsp);
    }
    else
    {
        mmi_bt_fax_authorize_rsp(&mmi_bt_addr, 0, MMI_FALSE);
    } 
}

void mmi_bt_fax_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 prof_id, U32 result)
{
    int i=0;
    
    for(i=0; i < MMI_BTH_FAX_MAX_CONNECTION; i++)
    {
        if(g_mmi_fax_cntx[i].state == MMI_BTH_FAX_STAT_AUTHORIZING
           && g_mmi_fax_cntx[i].lap == bt_addr->lap
           && g_mmi_fax_cntx[i].uap == bt_addr->uap
           && g_mmi_fax_cntx[i].nap == bt_addr->nap)
        {
            break;
        }
    }

    if(i != MMI_BTH_FAX_MAX_CONNECTION)
    {
        bt_fax_connect_ind_res_struct* bt_fax_con_ind_res = construct_local_para(sizeof(bt_fax_connect_ind_res_struct),TD_UL);
        bt_fax_con_ind_res->lap = bt_addr->lap;
        bt_fax_con_ind_res->uap = bt_addr->uap;
        bt_fax_con_ind_res->nap = bt_addr->nap;
        bt_fax_con_ind_res->result = result;
        bt_fax_con_ind_res->port =  g_mmi_fax_cntx[i].port;

        /* Reset context to initialization state: If this con_req is accepted, it will receive con_ind later 
          * In con_ind_hdler: it will update port, lap, uap and nap information
          */ 
        g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_AUTHORIZED;
        g_mmi_fax_cntx[i].lap = 0;
        g_mmi_fax_cntx[i].uap = 0;
        g_mmi_fax_cntx[i].nap = 0;
        g_mmi_fax_cntx[i].port = 0;

        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_FAX_CONNECT_IND_RES, (void*)bt_fax_con_ind_res, NULL);
        if (!result)
        {
        	g_mmi_fax_cntx[i].state = MMI_BTH_FAX_STAT_ACTIVATE;
            srv_bt_cm_stop_conn(g_mmi_fax_cntx[i].cmgr_id);
            g_mmi_fax_cntx[i].cmgr_id = 0;
        }
    }
}


#endif //__MMI_FAX_SUPPORT__
#endif //__MMI_BT_MTK_SUPPORT__
