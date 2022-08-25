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

/*******************************************************************************
* Filename:
* ---------
*  DCDNetEventHandler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD network event handler
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "app2soc_struct.h"     /* interface with Applications */
#include "CbmSrvGprot.h"
#include "cbm_api.h"
#include "plDefine.h"
#include "DCDProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "cbm_consts.h"
#include "soc_consts.h"
#include "l3_inc_enums.h"
#include "sdktypedef.h"
#include "dcdagentinterface.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static U8 mmi_dcd_hdlr_soc_notify_ind(void* msg);
static U8 mmi_dcd_hdlr_get_host_by_name_ind(void * msg);
static void mmi_dcd_postmessage(long nEventType, unsigned long param1, unsigned long param2, unsigned long platform);
static mmi_ret mmi_dcd_bearer_status_cb(mmi_event_struct *param);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern PAL_NET_DNS_DATA stDNS; /*pl_INetMgr.c*/
static kal_uint8  g_dcd_cbm_app_id = 0;

extern kal_bool   dcd_pl_sock_check(kal_int8 sock);  /* defined in pl_ISocket.c */
extern kal_int32  dcd_pl_get_request_id(void);       /* defined in pl_INetMgr.c */
extern kal_bool  dcd_sock_queue_connected(kal_int8 sock); 
extern kal_bool  dcd_sock_queue_closed(kal_int8 sock);


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_before
 * DESCRIPTION
 *  this function is used to register protocol event handler before sync
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_sync_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_state_enum  state = SRV_CBM_DEACTIVATED | SRV_CBM_ACTIVATING | SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATING;
    srv_cbm_bearer_type_enum   type  = SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_EDGE | SRV_CBM_BEARER_UMTS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_ENTER_SYNC_BEFORE);

    mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,           mmi_dcd_hdlr_soc_notify_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, mmi_dcd_hdlr_get_host_by_name_ind, MMI_TRUE);
    srv_cbm_register_bearer_info(g_dcd_cbm_app_id, state, type, mmi_dcd_bearer_status_cb, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_sync_after
 * DESCRIPTION
 *  this function is used to register protocol event handler before sync
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_sync_after(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_ENTER_SYNC_AFTER);

    mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND,           mmi_dcd_hdlr_soc_notify_ind);
    mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, mmi_dcd_hdlr_get_host_by_name_ind);
    srv_cbm_deregister_bearer_info(g_dcd_cbm_app_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cbm_register_app_id
 * DESCRIPTION
 *  this function is used to register application id for network manager
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mmi_dcd_get_acct_id(void)
{
    kal_uint32		networkAccountID;
    kal_uint32      cbm_net_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    networkAccountID = CBM_DCD_ACCT_ID;

    cbm_net_id = cbm_set_app_id(networkAccountID, g_dcd_cbm_app_id);

    return cbm_net_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cbm_register_app_id
 * DESCRIPTION
 *  this function is used to register application id for network manager
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_cbm_register_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int8  ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_cbm_app_id == 0)
    {
        ret = cbm_register_app_id(&g_dcd_cbm_app_id);
        if (ret == CBM_OK)
        {
            return;
        }
        else
        {
            g_dcd_cbm_app_id = 0;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_cbm_deregister_app_id
 * DESCRIPTION
 *  this function is used to deregister application id for network manager
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_cbm_deregister_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dcd_cbm_app_id != 0)
    {
        ret = cbm_deregister_app_id (g_dcd_cbm_app_id);
        if (ret)
        {
            g_dcd_cbm_app_id = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_disconnect_bearer
 * DESCRIPTION
 *  This is the function to disconnect the bearer.
 * PARAMETERS
 *  networkAccountID     [IN]        Network Account ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dcd_disconnect_bearer(void)
{
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    mmi_dcd_sync_after();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_hdlr_soc_notify_ind
 * DESCRIPTION
 *  This is the callback function for SOCKET.
 * PARAMETERS
 *  msg     [OUT]        The message data from SOC.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_dcd_hdlr_soc_notify_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int8    sock;
	kal_uint8   count;
	kal_uint16  msg_len;	
	kal_uint8   event_type;   /* soc_event_enum */
	kal_int8    error_cause;  /* used only when EVENT is close/connect */
    kal_bool    result;
	kal_int32   detail_cause; /* refer to cm_cause_enum if error_cause is SOC_BEARER_FAIL */
	app_soc_notify_ind_struct* soc_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SOC_NOTIFICATION);

	soc_ind = (app_soc_notify_ind_struct*) msg;

	sock = soc_ind->socket_id;
	event_type = soc_ind->event_type;
	result = soc_ind->result;
	msg_len = soc_ind->msg_len;
	count = soc_ind->ref_count;
	error_cause = soc_ind->error_cause;
	detail_cause = soc_ind->detail_cause;

    /* to check whether the socket is used by dcd */
    if ( ! dcd_pl_sock_check(sock))
    {
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_SOC_NOTIFY_DETAIL, sock, event_type);

	switch(event_type)
	{
	case SOC_READ:		
		if(result == KAL_TRUE)
		{
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_RECEIVE_ENABLE, sock+1, 0);
		}
		break;

	case SOC_WRITE:	
		if (result == KAL_TRUE)
		{
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_SEND_ENABLE, sock+1, 0);
		}
		break;

	case SOC_CONNECT:		
		if(result == KAL_TRUE)
		{
            dcd_sock_queue_connected(sock);
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_CONNECT_SUCCESS, sock+1, 0);
		}
        else
        {
            unsigned long net_err_type;
            if(error_cause == SOC_BEARER_FAIL && detail_cause == INSUFF_RESOURCE) 
            {
                net_err_type = SOCKET_ERR_NET_BUSY;
            } 
            else 
            {
                net_err_type = SOCKET_ERR_NET_DISABLE; 
            }
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_CONNECT_FAIL, sock+1, net_err_type);
		}
		break;

	case SOC_CLOSE:
		if (result == KAL_TRUE)
		{
            dcd_sock_queue_closed(sock);
			mmi_dcd_postmessage(eMSG_SOCKET, SOCKET_CLOSED, sock+1, 0);
		}
		break;

    default:
        break;
	}
    return KAL_TRUE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_bearer_status_cb
 * DESCRIPTION
 *  This is the callback function for bearer information.
 * PARAMETERS
 *  param     [IN]      srv_cbm_bearer_info_struct.
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_dcd_bearer_status_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32                   nwaccount;
    srv_cbm_bearer_info_struct * info = (srv_cbm_bearer_info_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_BEARER_STATUS_IND);

    nwaccount = mmi_dcd_get_acct_id();
    if (info->account_id != nwaccount)
    {
        return MMI_RET_OK;
    }

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_BEARER_STAT_DETAIL, nwaccount, info->state);

	switch(info->state)
	{
		case SRV_CBM_ACTIVATING:
            /* no need to notify dcd, because when synchronizing, ppp must open. */
			break;

		case SRV_CBM_ACTIVATED:
            /* no need to notify dcd, because when synchronizing, ppp must open. */
			break;

		case SRV_CBM_DEACTIVATING:
            /* no need to notify dcd, because when synchronizing, ppp must open. */
			break;

		case SRV_CBM_DEACTIVATED:
			mmi_dcd_postmessage(eMSG_NETWORK, eNET_PPP_CLOSE, 0, 0);
			break;

		default:
			break;
	}
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_hdlr_get_host_by_name_ind
 * DESCRIPTION
 *  This is the callback function for gethostbyname.
 * PARAMETERS
 *  msg     [OUT]        The message data from SOC.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_dcd_hdlr_get_host_by_name_ind(void * msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    kal_uint8 *p;
    app_soc_get_host_by_name_ind_struct * addr_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_GET_HOST_BY_NAME);

    addr_ind = (app_soc_get_host_by_name_ind_struct *)msg;

    if ( addr_ind->request_id != dcd_pl_get_request_id())
    {
        return MMI_FALSE;
    }    
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_TRC_GET_HOST_BY_NAME_HANDLED);

    p = (kal_uint8 *)&stDNS.m_nIP;
    for ( i = 0; i < addr_ind->addr_len; i++)
    {
        *p++ = addr_ind->addr[i];
    }

    mmi_dcd_postmessage(eMSG_NETWORK, eNET_DNS_GETHOST, 0, 0);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_postmessage
 * DESCRIPTION
 *  This is the callback function for gethostbyname.
 * PARAMETERS
 *  nEventType      [IN]        Event type
 *  param1          [IN]        Parameter 1
 *  param2          [IN]        Parameter 2
 *  platform        [IN]        socket error
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dcd_postmessage(long nEventType, unsigned long param1, unsigned long param2, unsigned long platform)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	emEventType Event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	Event.EventType = (EMBIDER_EVENT)nEventType;
	Event.nPlatformType = platform;
	Event.nParam1       = param1;
	Event.nParam2       = param2;
/*    agent_handle = mmi_dcd_get_agent_handle();*/
	emDCDAgent_PostMessage(g_dcd_agent.agent_handle, (BRVOID*)&Event);
}

#endif /* __MMI_OP01_DCD__*/

