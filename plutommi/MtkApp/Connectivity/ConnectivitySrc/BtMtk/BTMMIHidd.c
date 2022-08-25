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
 * BTMMIHIDD.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for HIDD application.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 ****************************************************************************/
//#include "MMI_include.h"
/* RHR ADD */
#include "MMI_features.h"
/* RHR ADD end */
#if defined(__MMI_HIDD_SUPPORT__)
/***************************************************************************** 
* Included files
*****************************************************************************/
//#include "ProtocolEvents.h"
//#include "CommonScreens.h"
//#include "IdleAppProt.h"
#include "Conversions.h"
 
/* External Device Header Files */
//#include "ExtDeviceDefs.h"
#include "BtcmSrvGprot.h"


/* BT CM callback */
#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"

/* HIDD */
#include "bt_dm_struct.h"
#include "bluetooth_hid_struct.h"
#include "BTMMIHidd.h"
#include "BTMMIHiddGprots.h"
//#include "BTMMIHIDScrGprots.h"
#include "BTMMIHidScr.h"

/* RHR ADD */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_common.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "app_ltlcom.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
/* RHR ADD end */

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_bth_hidd_cntx_struct g_hidd_cntx;
static const srv_bt_cm_profile_struct g_hidd_prof = {
    SRV_BT_CM_HID_PROFILE_UUID,
    mmi_hidd_activate_req,
    mmi_hidd_deactivate_req,
    mmi_hidd_disconnect_req
};

/***************************************************************************** 
* Function
*****************************************************************************/
static void mmi_hid_disc_req_hdlr(srv_bt_cm_bt_addr* addr, U32 conn_id);
static void hidd_auth_timeout(void);

/*****************************************************************************
 * FUNCTION
 *  HID_CONVERT_BDADDRSRC2ARRAY
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [OUT]         
 *  source         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HID_CONVERT_BDADDRSRC2ARRAY(U8 *dest, srv_bt_cm_bt_addr *source)
{
    dest[0] = (U8) (source->lap & 0x000000FF);
    dest[1] = (U8) ((source->lap & 0x0000FF00) >> 8);
    dest[2] = (U8) ((source->lap & 0x00FF0000) >> 16);
    dest[3] = source->uap;
    dest[4] = (U8) (source->nap & 0x00FF);
    dest[5] = (U8) ((source->nap & 0xFF00) >> 8);

}

/*****************************************************************************
 * FUNCTION
 *  HID_CONVERT_ARRAY2BDADDR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [OUT]     
 *  src         [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void HID_CONVERT_ARRAY2BDADDR(srv_bt_cm_bt_addr *dest, const U8 *src)
{
    dest->nap = (((U16) src[4])) | ((U16) src[5] << 8);
    dest->uap = (U8) src[3];
    dest->lap = (((U32) src[2]) << 16) | ((U32) src[1] << 8) | ((U32) src[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *addr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_hidd_cntx, 0, sizeof(mmi_bth_hidd_cntx_struct));
    addr = srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HID);
    if (addr)
        g_hidd_cntx.last_device = *addr;
    mmi_hidd_init_event_hdlr();

    srv_bt_cm_profile_register(&g_hidd_prof);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_init_event_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_init_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE( MMI_CONN_TRC_G7_BT, MMI_BT_G7_INIT_EVENT_HDLR);

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_hidd_activate_cnf_hdlr, MSG_ID_BT_HIDD_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_hidd_deactivate_cnf_hdlr, MSG_ID_BT_HIDD_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_hidd_connect_cnf_hdlr, MSG_ID_BT_HIDD_CONNECT_CNF);
    SetProtocolEventHandler(mmi_hidd_connect_ind_hdlr, MSG_ID_BT_HIDD_CONNECT_IND);
    SetProtocolEventHandler(mmi_hidd_disconnect_cnf_hdlr, MSG_ID_BT_HIDD_DISCONNECT_CNF);
    SetProtocolEventHandler(mmi_hidd_disconnect_ind_hdlr, MSG_ID_BT_HIDD_DISCONNECT_IND);

    SetProtocolEventHandler(mmi_hidd_authorize_ind_hdlr, MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_IND);
    SetProtocolEventHandler(mmi_hidd_interrupt_data_cnf_hdlr, MSG_ID_BT_HIDD_INTERRUPT_DATA_CNF);
#if 1
    SetProtocolEventHandler(mmi_hidd_unplug_ind_hdlr, MSG_ID_BT_HIDD_CONTROL_IND);
	SetProtocolEventHandler(mmi_hidd_interrupt_data_ind_hdlr, MSG_ID_BT_HIDD_INTERRUPT_DATA_IND);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_activate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hidd_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_IDLE:
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_ACTIVATE_REQ, NULL, NULL);
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATING);
            break;

        case MMI_BTH_HIDD_STAT_ACTIVATED:
            srv_bt_cm_activate_cnf_hdler((U32)SRV_BT_CM_HID_PROFILE_UUID);
            break;

        default:
            MMI_BT_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_activate_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_activate_cnf_struct *msg_p = (bt_hidd_activate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == hidd_result_ok)
    {
        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
        srv_bt_cm_activate_cnf_hdler((U32)SRV_BT_CM_HID_PROFILE_UUID);
    }
    else
    {
        switch (g_hidd_cntx.state)
        {
            case MMI_BTH_HIDD_STAT_ACTIVATING:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_IDLE);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_deactivate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hidd_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_ACTIVATED:
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            break;

        case MMI_BTH_HIDD_STAT_CONNECTED:
            if (mmi_hidd_disconnect() != HID_RESULT_PENDING)
                srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            break;
            
        case MMI_BTH_HIDD_STAT_AUTHORIZING:
            mmi_hidd_reject();
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            break;

        case MMI_BTH_HIDD_STAT_WAITCONNECT:
        case MMI_BTH_HIDD_STAT_CONNECTING:
        case MMI_BTH_HIDD_STAT_CONNCANCEL:
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTCANCEL);
            return;

        case MMI_BTH_HIDD_STAT_DISCONNECTING:
            break;

        default:
            MMI_BT_ASSERT(0);
    }

    MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTIVATING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_deactivate_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_deactivate_cnf_struct *msg_p = (bt_hidd_deactivate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result == hidd_result_ok)
    {
        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_IDLE);
        srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_HID_PROFILE_UUID);
    }
    else
    {
        switch (g_hidd_cntx.state)
        {
            case MMI_BTH_HIDD_STAT_DEACTIVATING:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_connect_cnf_struct *msg_p = (bt_hidd_connect_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_CONNCANCEL:
        case MMI_BTH_HIDD_STAT_DEACTCANCEL:
        case MMI_BTH_HIDD_STAT_CONNECTING:
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        case MMI_BTH_HIDD_STAT_WAITCONNECT:
        case MMI_BTH_HIDD_STAT_DISCONNECTING:
            break;
        case MMI_BTH_HIDD_STAT_IDLE:
            /* ignore this case, receiving connect cnf at idle state */
            /* for BT abnormal reset case, hidd module may receive the connect cnf at idle state */
        default:
            return;
    }

    if (msg_p->result == hidd_result_ok)
    {
        g_hidd_cntx.conn.conn_id = msg_p->connection_id;
		HID_CONVERT_ARRAY2BDADDR((srv_bt_cm_bt_addr *)&g_hidd_cntx.conn.bd_addr, msg_p->bt_addr.addr);

        srv_bt_cm_connect_ind(g_hidd_cntx.conn.cmgr_id);

        switch (g_hidd_cntx.state)
        {
            case MMI_BTH_HIDD_STAT_DISCONNECTING:
            case MMI_BTH_HIDD_STAT_CONNCANCEL:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTED);
                mmi_hidd_disconnect();
                break;
                
            case MMI_BTH_HIDD_STAT_DEACTCANCEL:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTED);
                mmi_hidd_disconnect();
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTIVATING);
                break;

            case MMI_BTH_HIDD_STAT_ACTIVATED:
            case MMI_BTH_HIDD_STAT_WAITCONNECT:
            case MMI_BTH_HIDD_STAT_CONNECTING:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTED);
				HID_CONVERT_ARRAY2BDADDR((srv_bt_cm_bt_addr *)&g_hidd_cntx.last_device, msg_p->bt_addr.addr);
    			srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HID, &g_hidd_cntx.last_device);
                mmi_hid_scrn_notify(HID_EVT_CONN_IND, 0);
                break;
        }
    }
    else
    {
        srv_bt_cm_stop_conn(g_hidd_cntx.conn.cmgr_id);
        g_hidd_cntx.conn.active = MMI_FALSE;
		g_hidd_cntx.conn.cmgr_id = 0xFF;
		
        switch (g_hidd_cntx.state)
        {
            case MMI_BTH_HIDD_STAT_DEACTCANCEL:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTIVATING);
                srv_bt_cm_send_msg(
                    MOD_BT, BT_APP_SAP, 
                    MSG_ID_BT_HIDD_DEACTIVATE_REQ,
                    NULL, NULL);
                return;

            case MMI_BTH_HIDD_STAT_CONNCANCEL:
            case MMI_BTH_HIDD_STAT_ACTIVATED:           
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
                return;
				
			case MMI_BTH_HIDD_STAT_WAITCONNECT:
            case MMI_BTH_HIDD_STAT_CONNECTING:
            case MMI_BTH_HIDD_STAT_DISCONNECTING:
                MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
                break;
        }
        
        if (msg_p->result == hidd_result_sco_reject)
        {
            mmi_hid_scrn_notify(HID_EVT_CONN_FAIL, HID_E_NOT_ALLOW);
        }
        else
        {
            mmi_hid_scrn_notify(HID_EVT_CONN_FAIL, HID_E_CONN_FAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_connect_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_connect_ind_struct *ind = (bt_hidd_connect_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_hidd_connect_cnf_struct *cnf = construct_local_para(sizeof(*cnf), TD_CTRL);
    
    cnf->result = ind->result;//hidd_result_ok;
	
	memcpy((void *)&cnf->bt_addr , (void *)&ind->bt_addr, sizeof(BD_ADDR));
    cnf->connection_id = ind->connection_id;

    mmi_hidd_connect_cnf_hdlr(cnf);

    free_local_para((local_para_struct *)cnf);
    
	//HID_CONVERT_ARRAY2BDADDR((srv_bt_cm_bt_addr *)&g_hidd_cntx.last_device, ind->bt_addr.addr); 
    //srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HID, &g_hidd_cntx.last_device);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_disconnect_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  device_addr     [IN]            
 *  connect_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hidd_disconnect_req(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_hidd_cntx.conn.cmgr_id != conn_id)
        return;
    
    mmi_hid_disc_req_hdlr(&g_hidd_cntx.conn.bd_addr, g_hidd_cntx.conn.conn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hid_disc_req_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  device_addr     [IN]            
 *  connect_id      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hid_disc_req_hdlr(srv_bt_cm_bt_addr* addr, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_disconnect_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_CONNECTED:
        case MMI_BTH_HIDD_STAT_WAITCONNECT:
            msg = (bt_hidd_disconnect_req_struct*)construct_local_para(sizeof(*msg), TD_CTRL);
#if 0			
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
			
			HID_CONVERT_BDADDRSRC2ARRAY(msg->bt_addr.addr, addr);
#endif
            msg->connection_id = conn_id;
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DISCONNECTING);
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DISCONNECT_REQ, (void*)msg, NULL);
            break;
            
        case MMI_BTH_HIDD_STAT_AUTHORIZING:
            mmi_hidd_reject();
            break;

        case MMI_BTH_HIDD_STAT_ACTIVATED:
            srv_bt_cm_stop_conn(g_hidd_cntx.conn.cmgr_id);
			g_hidd_cntx.conn.cmgr_id = 0xFF;
            break;

        case MMI_BTH_HIDD_STAT_CONNECTING:
            /* Connect cancel case */
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNCANCEL);
            break;

        case MMI_BTH_HIDD_STAT_CONNCANCEL:
        case MMI_BTH_HIDD_STAT_DEACTCANCEL:
        case MMI_BTH_HIDD_STAT_DISCONNECTING:
        case MMI_BTH_HIDD_STAT_IDLE:            
            break;

        default:
            MMI_BT_ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_disconnect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_disconnect_cnf_struct *msg_p = (bt_hidd_disconnect_cnf_struct*)msg;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 1
		srv_bt_cm_bt_addr bd_addr_temp;
		HID_CONVERT_ARRAY2BDADDR(&bd_addr_temp, msg_p->bt_addr.addr);
	#endif
    if (!g_hidd_cntx.conn.active ||
        !HIDD_SAME_DEVICE(g_hidd_cntx.conn.bd_addr, bd_addr_temp))
    {
        return;
    }

    if (msg_p->result == hidd_result_ok)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_DEACTIVATING:
            srv_bt_cm_stop_conn(g_hidd_cntx.conn.cmgr_id);
			g_hidd_cntx.conn.cmgr_id = 0xFF;
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            break;

        case MMI_BTH_HIDD_STAT_DISCONNECTING:
            srv_bt_cm_stop_conn(g_hidd_cntx.conn.cmgr_id);
			g_hidd_cntx.conn.cmgr_id = 0xFF;
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;

        default:
            break;
    }

    if (result)
    {
        g_hidd_cntx.conn.active = MMI_FALSE;
        mmi_hid_scrn_notify(HID_EVT_DISC_IND, HID_E_DISC_SUCC);
    }
    else
    {
        mmi_hid_scrn_notify(HID_EVT_DISC_IND, HID_E_DISC_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_disconnect_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [?]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_disconnect_ind_struct *msg_p = (bt_hidd_disconnect_ind_struct*)msg;
    U32 result = HID_E_DISC_IND;
#if 1
		srv_bt_cm_bt_addr bd_addr_temp;
		HID_CONVERT_ARRAY2BDADDR(&bd_addr_temp, msg_p->bt_addr.addr);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_hidd_cntx.conn.active ||
        !HIDD_SAME_DEVICE(g_hidd_cntx.conn.bd_addr, bd_addr_temp))
    {
        return;
    }

    srv_bt_cm_stop_conn(g_hidd_cntx.conn.cmgr_id);
    g_hidd_cntx.conn.cmgr_id = 0xFF;
    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_DEACTCANCEL:
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_DEACTIVATING);
            
        case MMI_BTH_HIDD_STAT_DEACTIVATING:
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_DEACTIVATE_REQ, NULL, NULL);
            break;

        case MMI_BTH_HIDD_STAT_AUTHORIZING:
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            StopTimer(BT_HID_USER_CNF_TIMER);
            g_hidd_cntx.conn.active = MMI_FALSE;
            return;
            
        case MMI_BTH_HIDD_STAT_CONNECTING:
        case MMI_BTH_HIDD_STAT_WAITCONNECT:
            result = HID_E_CONN_FAIL;
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
            
        case MMI_BTH_HIDD_STAT_DISCONNECTING:
            result = HID_E_DISC_SUCC;
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
            
        case MMI_BTH_HIDD_STAT_CONNCANCEL:
        case MMI_BTH_HIDD_STAT_CONNECTED:
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
            break;
            
        default:
            break;
    }

    g_hidd_cntx.conn.active = MMI_FALSE;

    mmi_hid_scrn_notify(HID_EVT_DISC_IND, result);
}

#if 1
/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_unplug_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg                     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_unplug_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_control_ind_struct *msg_p = (bt_hidd_control_ind_struct*)msg;
	srv_bt_cm_bt_addr bd_addr_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	HID_CONVERT_ARRAY2BDADDR(&bd_addr_temp, msg_p->bt_addr.addr);
	
    if (!g_hidd_cntx.conn.active ||
        !HIDD_SAME_DEVICE(g_hidd_cntx.conn.bd_addr, bd_addr_temp))
    {
        return;
    }
    
    /* If this device has been unplugged by PC, means 
        we are not able to establish connection to it anymore */
    if (HIDD_SAME_DEVICE(bd_addr_temp, g_hidd_cntx.last_device))
    {
        mmi_bth_hidd_clear_last_dev_info();
        srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HID, NULL);
    }

    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_CONNECTED:
			if(msg_p->ctrl_op == hidd_ctrl_op_virtual_cable_unplug)
            	mmi_hid_scrn_notify(HID_EVT_UNPLUG_IND, 0);
            break;

        default:
            break;
    }
}

#endif 
/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_disconnect
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
HIDResult mmi_hidd_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_hid_disc_req_hdlr(
        &(g_hidd_cntx.conn.bd_addr),
        g_hidd_cntx.conn.conn_id);
    if (g_hidd_cntx.state == MMI_BTH_HIDD_STAT_DISCONNECTING)
    {
        return HID_RESULT_PENDING;
    }

    return HID_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_authorize_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_authorize_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *bt_addr;
#if 1
	srv_bt_cm_bt_addr bt_addr_temp;
#endif
    bt_hidd_connection_authorize_ind_struct *msg_p = (bt_hidd_connection_authorize_ind_struct *)msg;
    S32 conn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
	bt_addr = &bt_addr_temp;
	HID_CONVERT_ARRAY2BDADDR(bt_addr, msg_p->bt_addr.addr);
#endif
    /* We don't support multiple connection now */
    if (g_hidd_cntx.conn.active)
    {
        mmi_hidd_authorize_rsp(bt_addr, 0, MMI_FALSE);
        return;
    }

    /* get device name from CM */
    if (srv_bt_cm_dev_property_check(bt_addr, SRV_BT_CM_DEV_PROPERTY_PAIR))
    {
        ((U16 *)g_hidd_cntx.hidd_dev_name)[0] = '\0';
        srv_bt_cm_get_dev_name(bt_addr, 
                    (U8)BT_HIDD_MAX_DEV_NAME_LEN,
                    g_hidd_cntx.hidd_dev_name);
    }
    else
    {
        strcpy((S8 *)g_hidd_cntx.hidd_dev_name, (S8 *)msg_p->dev_name);
    }

    conn_id = srv_bt_cm_start_conn(
                MMI_TRUE, 
                SRV_BT_CM_HID_PROFILE_UUID,
                bt_addr,
                g_hidd_cntx.hidd_dev_name);
    if (conn_id < 0)
    {
        mmi_hidd_authorize_rsp(bt_addr, 0, MMI_FALSE);
        return;
    }
    
    g_hidd_cntx.conn.active = MMI_TRUE;
    g_hidd_cntx.conn.bd_addr = *bt_addr;
    g_hidd_cntx.conn.conn_id = 0xffffffff;
    g_hidd_cntx.conn.cmgr_id = conn_id;
    

    if (g_hidd_cntx.state == MMI_BTH_HIDD_STAT_ACTIVATED)
    {
        MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_AUTHORIZING);
    }

    mmi_bt_authorize_ind_notify(
        g_hidd_cntx.hidd_dev_name,
        bt_addr, 
        SRV_BT_CM_HID_PROFILE_UUID,
        (void *)mmi_hidd_authorize_rsp);

    StartTimer(BT_HID_USER_CNF_TIMER, HID_USER_CNF_TIMEOUT, hidd_auth_timeout);
}

static void hidd_auth_timeout(void)
{
    mmi_hidd_reject();

    mmi_bt_authorize_screen_close(SRV_BT_CM_HID_PROFILE_UUID);
}

HIDResult mmi_hidd_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_HID_LOG(MMI_BT_HID_REJECT_FILE_RECV);
    
    mmi_hidd_authorize_rsp(&g_hidd_cntx.conn.bd_addr, 0, MMI_FALSE);

    return HID_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_connection_authorize_rsp_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_hidd_authorize_rsp(srv_bt_cm_bt_addr *addr, U32 prof, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_connection_authorize_rsp_struct *rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hidd_connection_authorize_rsp_struct*)construct_local_para(sizeof(*rsp), TD_CTRL);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    HID_CONVERT_BDADDRSRC2ARRAY(rsp->bt_addr.addr, addr);

#endif
    if	(result)
    {
        rsp->result = hidd_connect_authorization_result_accepted;
    }
    else
    {
        rsp->result = hidd_connect_authorization_result_rejected;
    }

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_CONNECTION_AUTHORIZE_RSP, rsp, NULL);

    StopTimer(BT_HID_USER_CNF_TIMER);

    if (g_hidd_cntx.state == MMI_BTH_HIDD_STAT_AUTHORIZING)
    {
        if (result)
        {
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_WAITCONNECT);    
            mmi_hid_scrn_notify(HID_EVT_AUTH_IND, 0);
        }
        else
        {
            g_hidd_cntx.conn.active = MMI_FALSE;
            srv_bt_cm_stop_conn(g_hidd_cntx.conn.cmgr_id);
			g_hidd_cntx.conn.cmgr_id = 0xFF;
            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_ACTIVATED);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_interrupt_data_req_hdler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_interrupt_data_req_hdler(U8 data_len, U8* data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_interrupt_data_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    msg_p = (bt_hidd_interrupt_data_req_struct*)construct_local_para(sizeof(*msg_p), TD_CTRL);
#if 0
/* under construction !*/
#else
	HID_CONVERT_BDADDRSRC2ARRAY(msg_p->bt_addr.addr, &g_hidd_cntx.conn.bd_addr);
#endif
    msg_p->connection_id = g_hidd_cntx.conn.conn_id;
    msg_p->report_type = hidd_report_input;
    msg_p->data_len = data_len;
    msg_p->data_ptr = data_ptr;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_HID_INTERRUPT_DATA, data_ptr[0],data_ptr[1],data_ptr[2],data_ptr[3]);
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_INTERRUPT_DATA_REQ, (void*)msg_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_interrupt_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_interrupt_data_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_interrupt_data_cnf_struct *msg_p = (bt_hidd_interrupt_data_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->result )
    {
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_hidd_interrupt_data_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_hidd_interrupt_data_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hidd_interrupt_data_ind_struct *msg_p = (bt_hidd_interrupt_data_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(msg_p->data_ptr != NULL)
    	free_ctrl_buffer(msg_p->data_ptr);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_hid_connect_last_dev
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
HIDResult mmi_hidd_connect_last_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 conn_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_HID_PROFILE_UUID, &g_hidd_cntx.last_device, NULL);
    if (conn_id < 0)
        return HID_RESULT_FAIL;

    g_hidd_cntx.conn.active = MMI_TRUE;
    g_hidd_cntx.conn.bd_addr = g_hidd_cntx.last_device;
    g_hidd_cntx.conn.cmgr_id = conn_id;

    switch (g_hidd_cntx.state)
    {
        case MMI_BTH_HIDD_STAT_ACTIVATED:
        {
            bt_hidd_connect_req_struct *msg;

            msg = (bt_hidd_connect_req_struct*)construct_local_para(sizeof(*msg), TD_CTRL);
	#if 0
/* under construction !*/
	#else
			HID_CONVERT_BDADDRSRC2ARRAY(msg->bt_addr.addr, &g_hidd_cntx.last_device);
	#endif
            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_HIDD_CONNECT_REQ, msg, NULL);

            MMI_BTH_HIDD_STATE_TRANS(MMI_BTH_HIDD_STAT_CONNECTING);
            
            return HID_RESULT_PENDING;
        }

        case MMI_BTH_HIDD_STAT_CONNECTED:
            srv_bt_cm_connect_ind(conn_id);
            return HID_RESULT_SUCCESS;

        default:
            MMI_BT_ASSERT(0);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_hid_is_busy
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_hid_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_hidd_cntx.state >= MMI_BTH_HIDD_STAT_IDLE &&
        g_hidd_cntx.state <= MMI_BTH_HIDD_STAT_CONNECTED)
    {
        result = MMI_FALSE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_clear_last_dev_info
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_clear_last_dev_info(void)
{
	g_hidd_cntx.last_device.lap = 0;
	g_hidd_cntx.last_device.uap = 0;
	g_hidd_cntx.last_device.nap = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_hidd_get_dev_name
 * DESCRIPTION
 *  This function is to get the bt device name from context
 * PARAMETERS
 *  name_buf        [IN]        
 *  p           [?](?)(?)(?)
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bth_hidd_get_dev_name(U8 *name_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 utf8_char_cnt = 0;
    U8 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *((U16 *)name_buf) = '\0';
    
    /* copy dev_name to MMI screen */
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt =
        (U8)((mmi_chset_utf8_strlen(g_hidd_cntx.hidd_dev_name)+1) * ENCODING_LENGTH);

    if (utf8_char_cnt > SRV_BT_CM_BD_NAME_UCS2_LEN)
    {
        ucs2_str_len =
            (U8)mmi_chset_utf8_to_ucs2_string(
                    name_buf,
                    SRV_BT_CM_BD_NAME_UCS2_LEN,
                    g_hidd_cntx.hidd_dev_name);
    }
    else
    {
        ucs2_str_len =
            (U8)mmi_chset_utf8_to_ucs2_string(
                    name_buf,
                    utf8_char_cnt,
                    g_hidd_cntx.hidd_dev_name);
    }

    /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
    /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */

    /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
    /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters) */
    if (mmi_bt_test_ucs2((U16*)name_buf, (U16) (ucs2_str_len / ENCODING_LENGTH)))
    {
        mmi_bt_truncate_ucs2_string(
            (U16*)name_buf,
            (U16)(ucs2_str_len / ENCODING_LENGTH),
            (U16)((SRV_BT_CM_BD_FNAME_LEN - 2) / 3));
    }
}

#endif /* __MMI_HIDD_SUPPORT__ */ 

