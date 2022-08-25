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
 * SppSrv.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT SPP service.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/

#ifdef __BT_SPP_PROFILE__

#include "string.h"
#include "kal_public_api.h"
#include "Conversions.h"

#include "Bcm_btcmSrvGprot.h"
#include "BcmSppSrv.h"
#include "BcmSppSrvGprot.h"
#include "bcm_trc.h"


#include "bluetooth_struct.h"
#include "bt_common_config.h"

#include "dcl.h"
#include "dcl_uart.h"

static srv_spp_conn_cntx sppConn[SRV_SPP_MAX_CONNECT_NUM];

static srv_spp_instance sppInstance[SRV_SPP_MAX_INSTANCE];
static srv_spp_instance* spp_inst_head;

#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
static srv_spp_instance* srv_spp_get_noconn_inst_by_req_id(U32 req_id);
#endif

MMI_BOOL g_spp_need_confirm_to_cm = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *	srv_spp_init
 * DESCRIPTION
 *	This function is for spp server init
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_spp_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_spp_init_cntx();
	srv_spp_init_event_hdler();
}

/*****************************************************************************
 * FUNCTION
 *	srv_spps_init_cntx
 * DESCRIPTION
 *	This function is for spp server init
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_spp_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_bt_cm_profile_struct original_spp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SPP_MAX_INSTANCE; ++i)
        sppInstance[i].handle = SRV_SPP_INVALID_HANDLE;
    for (i = 0; i < SRV_SPP_MAX_CONNECT_NUM; ++i)
        sppConn[i].conn_state = SRV_SPP_CONN_STATE_IDLE;

    spp_inst_head = NULL;

    original_spp.profile_id = SRV_BT_CM_SPP_PROFILE_UUID;
    original_spp.activater = srv_spp_default_activate;
    original_spp.deactivater = srv_spp_default_deactivate;
    original_spp.disconnector = srv_spp_disconnect_from_cm;
    srv_bt_cm_profile_register(&original_spp);
}

/*****************************************************************************
 * FUNCTION
 *	srv_spp_init_event_hdler
 * DESCRIPTION
 *	This function is for spp init message handler from bt task(server and client)
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_spp_init_event_hdler(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/****************************************************************************
 * FUNCTION
 *	srv_spp_default_activate
 * DESCRIPTION
 *	This function is for native app activate
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_spp_default_activate(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_instance* inst = spp_inst_head;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(inst)
	{
	    if ((!inst->cntx.connect) && (SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_ROLE_SERVER)))
	    {
			srv_spp_port_activate_req(inst->handle);
			g_spp_need_confirm_to_cm = MMI_TRUE;
	    }	
		inst = inst->next;
	}
}


/*****************************************************************************
 * FUNCTION
 *	srv_spp_default_deactivate
 * DESCRIPTION
 *	This function is for native app deactivate
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_spp_default_deactivate(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_instance* inst = spp_inst_head;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(inst)
	{
		for (conn = inst->cntx.connect; conn; conn = conn->next)
		{
			srv_spp_port_deactivate_req(conn->port);
			g_spp_need_confirm_to_cm = MMI_TRUE;
		}	
		inst = inst->next;
	}
}

/*****************************************************************************
 * FUNCTION
 *	srv_spp_disconnect_from_cm
 * DESCRIPTION
 *	This function is for disconnect from cm, it's as a callback register to cm
 * PARAMETERS
 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_spp_disconnect_from_cm(S32 conn_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inst = srv_spp_get_inst_by_conn_id(conn_id);
	if(inst)
	{
	SRV_SPP_SET_FLAG(inst, SRV_SPP_FLAG_DISCONNECT_FROM_CM);
	srv_spp_disconnect(conn_id);
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_open
 * DESCRIPTION
 *  This function is for app create a spp instance
 * PARAMETERS
 * RETURNS
 *  spp instance hdlr
 *****************************************************************************/
SppHandle srv_spp_open(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG(SRV_BT_SPP_OPEN);
	if (inst = srv_spp_create_inst())
		return inst->handle;
	else return SRV_SPP_INVALID_HANDLE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_set_notify_hdlr
 * DESCRIPTION
 *  This function is for app set a notify callback 
 * PARAMETERS
 *  hdlr:          srv instance handler id
 *  event_mask: the event of app care
 *  notifier:  the notify callback function
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_set_notify_hdlr(SppHandle handle, U32 event_mask, btSppNotify notifier, void* user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG4(SRV_BT_SPP_SET_NOTIFY, handle, event_mask, notifier, user_data);
	
	inst = srv_spp_get_inst_by_handle(handle);
	inst->event_mask = event_mask;
	inst->notifier = notifier;
	inst->user_data = user_data;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_uuid_convert_16bit_to_128bit
 * DESCRIPTION
 *  conver 16 bit uuid to 128 bit  
 * PARAMETERS
 *  uuid_16bit:   [IN]16 bit uuid
 *  uuid_128bit: [OUT]  buffer to 128 bit uuid
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_uuid_convert_16bit_to_128bit(U16 uuid_16bit, U8* uuid_128bit)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/	
	U8 bt_based_uuid[16]={
	                   0x00,0x00,0x00,0x00,
	                   0x00,0x00,0x10,0x00,
	                   0x80,0x00,0x00,0x80,
	                   0x5F,0x9B,0x34,0xFB
	                  };
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SPP_LOG1(SRV_BT_SPP_CONVERT_UUID_TO_128BIT,uuid_16bit);
	
	if (NULL != uuid_128bit)
	{
	  memcpy(uuid_128bit, bt_based_uuid, 16);
      uuid_128bit[2] = (U8)(((uuid_16bit) & 0xff00) >> 8);
      uuid_128bit[3] = (U8)((uuid_16bit) & 0x00ff);
	}

	SRV_SPP_LOG_DISPLAY_UUID(uuid_128bit);

	return;

}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_uuid_convert_128bit_to_16bit
 * DESCRIPTION
 *  conver 128 bit uuid to 16 bit  
 * PARAMETERS
 *  uuid_128bit:   [IN]buffer to 128 bit uuid
 * RETURNS
 *  U16 : 16 bit uuid
 *****************************************************************************/
U16 srv_spp_uuid_convert_128bit_to_16bit(U8* uuid_128bit)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/	
	U8 based_uuid[16]={
	                   0x00,0x00,0x00,0x00,
	                   0x00,0x00,0x10,0x00,
	                   0x80,0x00,0x00,0x80,
	                   0x5F,0x9B,0x34,0xFB
	                  };
	int i;
	U16 uuid_16bit = -1;
	MMI_BOOL invaild_uuid = MMI_FALSE;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SPP_LOG(SRV_BT_SPP_CONVERT_UUID_TO_16BIT1);
	SRV_SPP_LOG_DISPLAY_UUID(uuid_128bit);

	if(uuid_128bit == NULL) return -1;

	for(i = 0; i < 16; i++)
	{
		if(i == 2 || i == 3 || based_uuid[i] == uuid_128bit[i])
		{
		  continue;
		}	
		else
		{
		   invaild_uuid = MMI_TRUE;
		   break;
		}
	}

	if(!invaild_uuid)
	{
		uuid_16bit = (U16)((uuid_128bit[2]) << 8 & 0xff00);
		uuid_16bit |= uuid_128bit[3];
	}

	SRV_SPP_LOG1(SRV_BT_SPP_CONVERT_UUID_TO_16BIT2,uuid_16bit);

	return uuid_16bit;

}

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_bind_128bit_uuid
 * DESCRIPTION
 *  	This function is for server app bind a spp service with 128 bit uuid
 * PARAMETERS
 *  	handle: spp instance handler         
 *  	uuid: spp server uuid
 * RETURNS
 *  	void
 *****************************************************************************/
void srv_spp_bind_128bit_uuid(SppHandle handle, U8* uuid)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inst = srv_spp_get_inst_by_handle(handle);
	SRV_SPP_SET_FLAG(inst, SRV_SPP_FLAG_ROLE_SERVER);
	SRV_SPP_LOG2(SRV_BT_SPP_BIND_128BIT_UUID, handle,inst);
	inst->req_id = handle;
	memcpy(inst->uuid, (U8*)uuid, 16);
	
	if (SRV_BT_CM_POWER_ON  == srv_bt_cm_get_power_status())
		srv_spp_port_activate_req(handle);
	return;
}

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_connect_128bit_uuid_ex
 * DESCRIPTION
 *  	This function is for client connect remote server with 128 bit uuid
 * PARAMETERS
 *  	handle : client app service handle
 *  	uuid: app uuid
 *  	bt_addr: bt address.
 *  	buf: for tx rx buffer
 *  	tx_size: tx buffer size
 *  	rx_size: rx_size
 *  	connect_type: with sco or not
 * RETURNS
 *  	void
 *****************************************************************************/
void srv_spp_connect_128bit_uuid_ex(SppHandle handle, 
					U8* uuid,
					srv_bt_cm_bt_addr* bt_addr,
					void* buf,
  					U32 tx_size,
  					U32 rx_size,
  					srv_spp_connect_type conn_type
  					)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_connect_req_struct* conn_req;
	srv_spp_instance* inst = srv_spp_get_inst_by_handle(handle);
	srv_spp_conn_cntx* conn;
	srv_spp_conn_cntx* tempconn = inst->cntx.connect;
	srv_spp_event_cntx notify_cntx;		
	S32 conn_id;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG4(SRV_BT_SPP_CONNECT_128BIT_UUID_EX, handle,conn_type,tx_size,rx_size);
	SRV_SPP_LOG_DISPLAY_UUID(uuid);

	//rx tx size is not right, return.
	if (!buf || tx_size < SPP_MIN_TX_BUFSIZE || rx_size < SPP_MIN_RX_BUFSIZE)
		return;
	
	if (tempconn->conn_id >0 ) { /*this means that one conn_id map to one instance*/
		srv_bt_cm_stop_conn(conn_id);
		srv_spp_destroy_conn(inst, conn->port);
	}
	conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_SPP_PROFILE_UUID, bt_addr, NULL);
	if (conn_id < 0)
	{
		notify_cntx.ret = MMI_FALSE;
		srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, &notify_cntx, MMI_FALSE);
		return;		
	}
	
	if (!(conn = srv_spp_create_conn(inst)))
	{	
		notify_cntx.ret = MMI_FALSE;
		srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, &notify_cntx, MMI_FALSE);

		srv_bt_cm_stop_conn(conn_id);
		return;			
	}
	inst->req_id = conn_id;
	conn->conn_id = conn_id;
	conn->bt_addr = *bt_addr;
	SRV_SPP_SET_FLAG(inst, conn_type);
	SRV_SPP_SET_FLAG(inst, SRV_SPP_FLAG_ROLE_CLIENT);	

	conn_req = (bt_spp_connect_req_struct*)construct_local_para(sizeof(*conn_req), TD_CTRL);
	
	conn_req->lap = bt_addr->lap;
	conn_req->uap = bt_addr->uap;
	conn_req->nap = bt_addr->nap;
	
	conn_req->txBufPtr = (U8*)buf;
	conn_req->txBufSize = tx_size;
	conn_req->rxBufPtr = conn_req->txBufPtr + tx_size;
	conn_req->rxBufSize = rx_size;
	
	memcpy(conn_req->uuid, (U8*)uuid, 16);

	conn_req->sec_level = inst->cntx.sec_level;
	conn_req->req_id = inst->req_id;

	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_CONNECT_REQ, (void*)conn_req, NULL);		
}

/*****************************************************************************
 * FUNCTION
 *  	srv_spp_connect_128bit_uuid
 * DESCRIPTION
 *  	This function is for client app connect remote server with no sco support with 128 bit uuid
 * PARAMETERS
 *  	handle: client service handle
 * 	uuid: app uuid
 *  	bt_addr: remote server bt address
 *  	buf: for tx rx buffer
 *  	tx_size: tx buffer size
 *  	rx_size: rx buffer size
 * RETURNS
 *  	void
 *****************************************************************************/
void srv_spp_connect_128bit_uuid(SppHandle handle,
				U8* uuid,
				srv_bt_cm_bt_addr* bt_addr,
				void* buf,
				U32 tx_size,
				U32 rx_size
				)
{
	/*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_spp_connect_128bit_uuid_ex(handle, uuid, bt_addr, buf, tx_size, rx_size, SRV_SPP_CONNECT_WITHOUT_SCO);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_bind
 * DESCRIPTION
 *  This function is for app create a spp instance
 * PARAMETERS
 *  handle: spp instance handler         
 *  uuid: spp server uuid
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_bind(SppHandle handle, U32 uuid)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inst = srv_spp_get_inst_by_handle(handle);
	SRV_SPP_SET_FLAG(inst, SRV_SPP_FLAG_ROLE_SERVER);
        inst->req_id = handle; 

	SRV_SPP_LOG3(SRV_BT_SPP_BIND, handle, uuid, inst);
	srv_spp_uuid_convert_16bit_to_128bit((U16)uuid, inst->uuid);
	
	if (SRV_BT_CM_POWER_ON  == srv_bt_cm_get_power_status())
		srv_spp_port_activate_req(handle);
	return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_port_activate_req
 * DESCRIPTION
 *  activate a port request for a spp instance
 * PARAMETERS
 *  handle: spp instance handler         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_port_activate_req(SppHandle handle)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_spp_activate_req_struct* activate_req;
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	activate_req = (bt_spp_activate_req_struct*)construct_local_para(sizeof(*activate_req), TD_CTRL);
	inst = srv_spp_get_inst_by_handle(handle);
	
	//about native spp port owner, spp profile will set L4c or L4c2, mmi dont konw the real owner.

	if (srv_spp_uuid_convert_128bit_to_16bit(inst->uuid) == SRV_BT_CM_SPP_PROFILE_UUID)
		//activate_req->owner = MOD_MMI;
		activate_req->owner = (module_type)NULL;
	else activate_req->owner = MOD_MMI;
	
	activate_req->secLevel = inst->cntx.sec_level;
	memcpy(activate_req->svcName, inst->cntx.srv_name, SRV_SPP_SERVICE_NAME_LENGTH*3 + 1);
	memcpy(activate_req->svcUUID, inst->uuid, 16);
	activate_req->req_id = (U16)inst->handle; 

	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_ACTIVATE_REQ, (void*)activate_req, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_port_activate_cnf
 * DESCRIPTION
 *  This function is for port activate confirm
 * PARAMETERS
 *  msg: para for activate confirm    
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_spp_port_activate_cnf(void* msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_spp_activate_cnf_struct* activate_cnf = (bt_spp_activate_cnf_struct*)msg;
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	srv_spp_event_cntx notify;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG(SRV_BT_SPP_PORT_ACTIVATE_CNF);

	inst = srv_spp_get_inst_by_req_id(activate_cnf->req_id);
    if(!inst) ASSERT(0);

	if (activate_cnf->result == SRV_SPP_ACTIVATE_SUCCESS)
	{
		//if (srv_spp_uuid_convert_128bit_to_16bit(inst->uuid) == SRV_BT_CM_SPP_PROFILE_UUID)
		if (g_spp_need_confirm_to_cm)
		{
		    srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_SPP_PROFILE_UUID);
			g_spp_need_confirm_to_cm = MMI_FALSE;
		}	

		if (conn = srv_spp_create_conn(inst)) 
		{			
			conn->port = activate_cnf->port;

		}
		else//limitation by srv conn number. 
		{
			srv_spp_port_deactivate_req(activate_cnf->port);
			if (!inst->cntx.connect)
				srv_spp_notify_app(inst, SRV_SPP_BIND_FAIL, NULL, MMI_FALSE);
		}
	}
	else
	{
		if (!inst->cntx.connect)
			srv_spp_notify_app(inst, SRV_SPP_BIND_FAIL, NULL, MMI_FALSE);			
	}
#ifdef __BCM_SUPPORT__
    if (activate_cnf->req_id == SRV_BT_CM_SPP_PROFILE_UUID)
    {//only the last active cnf msg of spp will take the req_id.
        cmd_hdlr_bt_profile_act_cnf((activate_cnf->result == SRV_SPP_ACTIVATE_SUCCESS),KAL_TRUE,SRV_BT_CM_SPP_PROFILE_UUID);
    }
#endif

	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_authorize_ind
 * DESCRIPTION
 *  This function is for app create a spp instance
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_authorize_ind(void* msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	S32 conn_id;
	srv_bt_cm_bt_addr bt_addr;
	srv_spp_event_cntx notify;
	bt_spp_connect_ind_req_struct* auth_ind = (bt_spp_connect_ind_req_struct*)msg;
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG_DISPLAY_CNTX();

	inst = srv_spp_get_inst_by_port(auth_ind->port);
	conn = srv_spp_get_conn_by_port(auth_ind->port);

	if (!inst || !conn) return;
	
	if (conn->conn_state == SRV_SPP_CONN_STATE_ACTIVATE)//avoid other device's authorize
	{
		bt_addr.lap = auth_ind->lap;
		bt_addr.uap = auth_ind->uap;
		bt_addr.nap = auth_ind->nap;
		conn->bt_addr = bt_addr;
		conn->port = auth_ind->port;
		//conn_id = srv_bt_cm_start_conn(MMI_TRUE, SRV_BT_CM_SPP_PROFILE_UUID, &bt_addr, auth_ind->dev_name);
		conn_id = srv_bt_cm_start_conn(MMI_TRUE, SRV_BT_CM_SPP_PROFILE_UUID, &bt_addr, NULL); //no need give dev name to cm 
		if (conn_id < 0) srv_spp_authorize_rsp(conn, NULL, 0, 0, MMI_FALSE);
		else
		{
			conn->conn_id = conn_id;
			conn->conn_state = SRV_SPP_CONN_STATE_AUTHORIZING;

			notify.ret = MMI_TRUE;
			notify.para = conn_id;
		#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
 			notify.handle = inst->handle;
		#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
			srv_spp_notify_app(inst, SRV_SPP_EVENT_AUTHORIZE, &notify, MMI_TRUE);
		#if 0 // app can active non SRV_BT_CM_SPP_PROFILE_UUID uuid for spp server
/* under construction !*/
/* under construction !*/
		#endif 
		}			
	}	
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_accept
 * DESCRIPTION
 *  This function is for accept a connect
 * PARAMETERS
 *  conn_id: connect id         
 *  buf: tx rx buffer
 *  tx_size: tx buffer size
 *  rx_size: rx buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_accept(S32 conn_id,
				void* buf, 
				U32 tx_size, 
				U32 rx_size
				)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_spp_conn_cntx* conn;
	conn = srv_spp_get_conn_by_conn_id(conn_id);
	if (tx_size < SPP_MIN_TX_BUFSIZE || rx_size < SPP_MIN_RX_BUFSIZE)
	{
		srv_spp_authorize_rsp(conn, NULL, 0, 0, MMI_FALSE);
		return;
	}
	srv_spp_authorize_rsp(conn, (U8*)buf, tx_size, rx_size, MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_reject
 * DESCRIPTION
 *  This function is for reject a connect
 * PARAMETERS
 *  conn_id: connect id         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_reject(S32 conn_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_spp_conn_cntx* conn;
	conn = srv_spp_get_conn_by_conn_id(conn_id);
	srv_spp_authorize_rsp(conn, NULL, 0, 0, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_authorize_rsp
 * DESCRIPTION
 *  This function is for authorize response.
 * PARAMETERS
 *  conn: connect cntx        
 *  buf: tx, rx buffer
 *  tx_size: tx buffer size
 *  rx_size: rx buffer size
 *  ret: response result
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_authorize_rsp(srv_spp_conn_cntx* conn, 
						U8* buf,
						U32 tx_size,
						U32 rx_size,
						MMI_BOOL ret
						)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_connect_ind_res_struct* auth_rsp;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG4(SRV_BT_SPP_AUTHORIZE_RSP, conn->conn_id, tx_size, rx_size, ret);
	
	auth_rsp = (bt_spp_connect_ind_res_struct*)construct_local_para(sizeof(*auth_rsp), TD_CTRL);
	auth_rsp->lap = conn->bt_addr.lap;
	auth_rsp->uap = conn->bt_addr.uap;
	auth_rsp->nap = conn->bt_addr.nap;

	auth_rsp->port = conn->port;
	auth_rsp->result = ret;

	if (buf)
	{
		auth_rsp->txBufPtr = buf;
		auth_rsp->txBufSize = tx_size;
		auth_rsp->rxBufPtr = buf + tx_size;
		auth_rsp->rxBufSize = rx_size;
	}
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_CONNECT_IND_RES, (void*)auth_rsp, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_connect
 * DESCRIPTION
 *  This function is for app connect server
 * PARAMETERS
 *  handle:indicate a spp instance
 *  uuid : indicate the connect server service
 *  bt_addr: server bt address
 *  buf: for tx rx buffer
 *  tx_size: tx buffer size
 *  rx_size: rx buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_connect(SppHandle handle,
				U32 uuid,
				srv_bt_cm_bt_addr* bt_addr,
				void* buf,
				U32 tx_size,
				U32 rx_size
				)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_spp_connect_ex(handle, uuid, bt_addr, buf, tx_size, rx_size, SRV_SPP_CONNECT_WITHOUT_SCO);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_connect_ex
 * DESCRIPTION
 *  This function is for app create a spp instance
 * PARAMETERS
 *  handle : indicate a spp instance
 *  uuid: indicate which service the client will connect.
 *  bt_addr: bt address.
 *  buf: for tx rx buffer
 *  tx_size: tx buffer size
 *  rx_size: rx_size
 *  connect_type: with sco or not
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_connect_ex(SppHandle handle, 
					U32 uuid,
					srv_bt_cm_bt_addr* bt_addr,
					void* buf,
  					U32 tx_size,
  					U32 rx_size,
  					srv_spp_connect_type conn_type
  					)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_connect_req_struct* conn_req;
	srv_spp_instance* inst = srv_spp_get_inst_by_handle(handle);
	srv_spp_conn_cntx* conn;
	srv_spp_conn_cntx* tempconn = inst->cntx.connect;
	srv_spp_event_cntx notify_cntx;		
	S32 conn_id;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG3(SRV_BT_SPP_CONNECT_EX, handle, uuid, conn_type);
	//rx tx size is not right, return.
	if (!buf || tx_size < SPP_MIN_TX_BUFSIZE || rx_size < SPP_MIN_RX_BUFSIZE)
		return;
	
	if (tempconn->conn_id >0 ) { /*this means that one conn_id map to one instance*/
		srv_bt_cm_stop_conn(conn_id);
		srv_spp_destroy_conn(inst, conn->port);
	}
	conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_SPP_PROFILE_UUID, bt_addr, NULL);
#ifdef __BCM_SUPPORT__
    //sppc connect fail also need to destory inst.
    notify_cntx.inst = inst;
#endif

	if (conn_id < 0)
	{
		notify_cntx.ret = MMI_FALSE;
		srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, &notify_cntx, MMI_FALSE);
		return;		
	}
	
	if (!(conn = srv_spp_create_conn(inst)))
	{	
		notify_cntx.ret = MMI_FALSE;
		srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, &notify_cntx, MMI_FALSE);

		srv_bt_cm_stop_conn(conn_id);
		return;			
	}

	//inst->req_id = conn_id; 
	inst->req_id =  inst->handle;
	conn->conn_id = conn_id;
	conn->bt_addr = *bt_addr;
	SRV_SPP_SET_FLAG(inst, conn_type);
	SRV_SPP_SET_FLAG(inst, SRV_SPP_FLAG_ROLE_CLIENT);	

	conn_req = (bt_spp_connect_req_struct*)construct_local_para(sizeof(*conn_req), TD_CTRL);
	
	conn_req->lap = bt_addr->lap;
	conn_req->uap = bt_addr->uap;
	conn_req->nap = bt_addr->nap;
	
	conn_req->txBufPtr = (U8*)buf;
	conn_req->txBufSize = tx_size;
	conn_req->rxBufPtr = conn_req->txBufPtr + tx_size;
	conn_req->rxBufSize = rx_size;
	srv_spp_uuid_convert_16bit_to_128bit((U16)uuid, conn_req->uuid); 

	conn_req->sec_level = inst->cntx.sec_level;
	conn_req->req_id = inst->req_id;

	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_CONNECT_REQ, (void*)conn_req, NULL);		
}


/*****************************************************************************
 * FUNCTION
 *  srv_spp_connect_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_connect_ind(void* msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_connect_ind_struct* conn_ind = (bt_spp_connect_ind_struct*)msg;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_port(conn_ind->port);
	srv_spp_instance* inst = srv_spp_get_inst_by_port(conn_ind->port);
	srv_spp_event_cntx notify;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!inst || !conn) return MMI_RET_OK;
	switch (conn->conn_state) 
	{
		case SRV_SPP_CONN_STATE_AUTHORIZING:
		{
			conn->conn_state = SRV_SPP_CONN_STATE_CONNECTED;
			srv_bt_cm_connect_ind(conn->conn_id);

		#ifdef __MMI_BT_DIALER_SUPPORT__
			srv_bt_cm_set_dev_link_state(&conn->bt_addr,MMI_TRUE);
		#endif

			notify.ret = MMI_TRUE;
			notify.para = conn->conn_id;
		#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
            notify.handle = inst->handle;
		#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
			srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, &notify, MMI_TRUE);
			break;
		}
		default:
			break;
	}
	SRV_SPP_LOG_DISPLAY_CNTX();
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_connect_cnf
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_connect_cnf(void * msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	bt_spp_connect_cnf_struct* conn_cnf = (bt_spp_connect_cnf_struct*)msg;
	srv_spp_conn_cntx* conn;
	srv_spp_event_cntx evt;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 0 /*code code*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	if (!(inst = srv_spp_get_inst_by_req_id(conn_cnf->req_id)))
		MMI_ASSERT(0);
	if (!(conn = srv_spp_get_conn_by_conn_id(inst->cntx.connect->conn_id)))
		MMI_ASSERT(0);
	
	switch (conn->conn_state)
	{
		case SRV_SPP_CONN_STATE_ACTIVATE:
		{
			if (conn_cnf->result == 0)//connect success
			{		
				conn->port = conn_cnf->port;
				conn->conn_state = SRV_SPP_CONN_STATE_CONNECTED;

				srv_bt_cm_connect_ind(conn->conn_id);
			#ifdef __MMI_BT_DIALER_SUPPORT__
				srv_bt_cm_set_dev_link_state(&conn->bt_addr,MMI_TRUE);
			#endif
				evt.ret = MMI_TRUE;
				evt.para = conn->conn_id;
				srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, (void*)&evt, MMI_TRUE);		
			}
			else if (conn_cnf->result > 0)//connect fail
			{
				SRV_SPP_CLEAR_FLAG(inst, SRV_SPP_FLAG_ROLE_CLIENT);
				srv_bt_cm_stop_conn(conn->conn_id);

				evt.ret = MMI_FALSE;
				srv_spp_notify_app(inst, SRV_SPP_EVENT_CONNECT, (void*)&evt, MMI_TRUE);

				srv_spp_destroy_conn(inst, SRV_SPP_INVALID_PORT);
			}
			break;
		}
		default:
			break;
	}
	SRV_SPP_LOG_DISPLAY_CNTX();
	return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_spp_read
 * DESCRIPTION
 *  This function is for app read data
 * PARAMETERS
 *  conn_id: conn_id          
 *  buf: to put the data of read
 *  size: app wish the size of to read
 * RETURNS
 *  U32: the size of data by read in fact
 *****************************************************************************/
U32 srv_spp_read(U32 conn_id, void* buf, U32 size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	UART_CTRL_OWNER_T port_owner;
	UART_CTRL_GET_BYTES_T data;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_conn_id(conn_id);
	DCL_HANDLE dcl_handle = DclSerialPort_Open(conn->port, 0);
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DclSerialPort_Control(dcl_handle, SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&port_owner);
	if (port_owner.u4OwenrId != MOD_MMI || conn->conn_state != SRV_SPP_CONN_STATE_CONNECTED)
		return 0;

	data.u4OwenrId = MOD_MMI;
	data.u2Length = size;
	data.puBuffaddr = (U8*)buf;
	data.pustatus = 0;
	DclSerialPort_Control(dcl_handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);

	SRV_SPP_LOG4(SRV_BT_SPP_READ, conn_id, buf, size, data.u2RetSize);
	return data.u2RetSize;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_write
 * DESCRIPTION
 *  This function is for app to write data
 * PARAMETERS
 * conn_id : connect id
 * buf: the buffer has wrote data.
 * size: the size want to write
 * RETURNS
 *  U32 : the size of write successfully
 *****************************************************************************/
U32 srv_spp_write(U32 conn_id, void* buf, U32 size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	UART_CTRL_OWNER_T port_owner;
	UART_CTRL_PUT_BYTES_T data;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_conn_id(conn_id);
	DCL_HANDLE dcl_handle = DclSerialPort_Open(conn->port, 0);
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DclSerialPort_Control(dcl_handle, SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&port_owner);
	if (port_owner.u4OwenrId != MOD_MMI || conn->conn_state != SRV_SPP_CONN_STATE_CONNECTED) 
		return 0;

	data.u4OwenrId = MOD_MMI;
	data.puBuffaddr = buf;
	data.u2Length = size;
	DclSerialPort_Control(dcl_handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);

	SRV_SPP_LOG4(SRV_BT_SPP_WRITE, conn_id, buf, size, data.u2RetSize);
	return data.u2RetSize;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_write
 * DESCRIPTION
 *  This function is for app to write data
 * PARAMETERS
 * conn_id : connect id
 * buf: the buffer has wrote data.
 * size: the size want to write
 * err_code: error code
 * RETURNS
 *  U32 : the size of write successfully
 *****************************************************************************/
U32 srv_spp_write_ext(U32 conn_id, void* buf, U32 size, S32 *err_code)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	UART_CTRL_OWNER_T port_owner;
	UART_CTRL_PUT_BYTES_T data;
    DCL_STATUS status;
    DCL_HANDLE dcl_handle = DCL_HANDLE_NONE;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_conn_id(conn_id);

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        *err_code = 0;
        
        if (NULL == conn)
        {
            *err_code = -6;
            break;
        }
        
        dcl_handle = DclSerialPort_Open(conn->port, 0);
        if (dcl_handle <= DCL_HANDLE_NONE)
        {
            *err_code = -5;
            break;
        }
        
    	status = DclSerialPort_Control(dcl_handle, SIO_CMD_GET_OWNER_ID, (DCL_CTRL_DATA_T*)&port_owner);
        
    	if (STATUS_OK != status)
    	{
            *err_code = -4;
    		break;
    	}

        if (port_owner.u4OwenrId != MOD_MMI)
        {
            *err_code = -3;
            break;
        }

        if (conn->conn_state != SRV_SPP_CONN_STATE_CONNECTED)
        {
            *err_code = -2;
            break;
        }

    	data.u4OwenrId = MOD_MMI;
    	data.puBuffaddr = buf;
    	data.u2Length = size;
        
    	if (STATUS_OK != DclSerialPort_Control(dcl_handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data))
    	{
            *err_code = -1;
            break;
    	}

    	SRV_SPP_LOG4(SRV_BT_SPP_WRITE, conn_id, buf, size, data.u2RetSize);
    	return data.u2RetSize;
    } while(0);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_spp_uart_ready_to_read_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_uart_ready_to_read_ind(void* msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	uart_ready_to_read_ind_struct* uart_rtr_ind = (uart_ready_to_read_ind_struct*)msg;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_port(uart_rtr_ind->port);
	srv_spp_event_cntx evt;
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	srv_spp_instance* inst;
#endif
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!conn) return MMI_FALSE;//confirm the mulity message handle belong who.
	else
	{
		switch (conn->conn_state)
		{
			case SRV_SPP_CONN_STATE_CONNECTED:
			{
				evt.ret = MMI_TRUE;
				evt.para = conn->conn_id;
			#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
				srv_spp_notify_app(
					srv_spp_get_inst_by_port(uart_rtr_ind->port),
					SRV_SPP_EVENT_READY_TO_READ,
					&evt,
					MMI_FALSE
					);
			#else /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
				inst = srv_spp_get_inst_by_port(uart_rtr_ind->port);
				evt.handle = inst->handle;
				srv_spp_notify_app(inst, SRV_SPP_EVENT_READY_TO_READ, &evt, MMI_FALSE);
			#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
				break;
			}				
		}
		return MMI_TRUE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_uart_ready_to_write_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_uart_ready_to_write_ind(void * msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	uart_ready_to_write_ind_struct* uart_rtw_ind = (uart_ready_to_write_ind_struct*)msg;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_port(uart_rtw_ind->port);
	srv_spp_event_cntx evt;
	#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	srv_spp_instance* inst;
	#endif
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!conn) return MMI_FALSE;
	else
	{
		switch (conn->conn_state)
		{
			case SRV_SPP_CONN_STATE_CONNECTED:
			{
				evt.ret = MMI_TRUE;
				evt.para = conn->conn_id;
			#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__	
				srv_spp_notify_app(
					srv_spp_get_inst_by_port(uart_rtw_ind->port),
					SRV_SPP_EVENT_READY_TO_WRITE,
					&evt,
					MMI_FALSE
					);
			#else
				evt.handle = inst->handle;
				inst = srv_spp_get_inst_by_port(uart_rtw_ind->port);
				srv_spp_notify_app(inst, SRV_SPP_EVENT_READY_TO_WRITE, &evt, MMI_FALSE);
			#endif
				break;
			}
		}
		return MMI_TRUE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_uart_plugout_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_uart_plugout_ind(void* msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	uart_plugout_ind_struct* plugout_ind = (uart_plugout_ind_struct*)msg;
	bt_spp_uart_plugout_cnf_struct* spp_plugout_cnf;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	spp_plugout_cnf = (bt_spp_uart_plugout_cnf_struct*)construct_local_para(sizeof(*spp_plugout_cnf), TD_CTRL);
	spp_plugout_cnf->port = plugout_ind->port;
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_UART_PLUGOUT_CNF, (void*)spp_plugout_cnf, NULL);
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_uart_set_owner_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_uart_set_owner_ind(void* msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_uart_owner_ind_struct* uart_owner_ind = (bt_spp_uart_owner_ind_struct*)msg;
	UART_CTRL_OWNER_T uart_owner;
	DCL_HANDLE dcl_handle;
	DCL_STATUS status;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (srv_spp_get_conn_by_port(uart_owner_ind->port))	
	{
		dcl_handle = DclSerialPort_Open(uart_owner_ind->port, 0);
		uart_owner.u4OwenrId = MOD_MMI;
		status = DclSerialPort_Control(dcl_handle, SIO_CMD_SET_OWNER, (DCL_CTRL_DATA_T*)&uart_owner);
		if (status == STATUS_OK)
			srv_spp_uart_set_owner_cnf(uart_owner_ind->port);
		else MMI_ASSERT(0);
	}
	return MMI_TRUE;	
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_uart_set_owner_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_uart_set_owner_cnf(DCL_DEV port)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_uart_owner_cnf_struct* uart_owner_cnf;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	uart_owner_cnf = (bt_spp_uart_owner_cnf_struct*)construct_local_para(sizeof(*uart_owner_cnf), TD_CTRL);
	uart_owner_cnf->port = port;
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_UART_OWNER_CNF, (void*)uart_owner_cnf,NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_disconnect_ind
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_disconnect_ind(void * msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_disconnect_ind_struct* disconn_ind = (bt_spp_disconnect_ind_struct*)msg;
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_port(disconn_ind->port);
	srv_spp_instance* inst = srv_spp_get_inst_by_port(disconn_ind->port);
	srv_spp_event_cntx evt;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!inst || !conn) return MMI_RET_OK;
#ifdef __BCM_SUPPORT__
    {
        int i = g_srv_bt_cm_cntx.existed_conn[conn->conn_id - 1].index_of_dev_list;
        evt.dev_addr.lap = g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.lap;
        evt.dev_addr.nap = g_srv_bt_cm_cntx.dev_list[i].dev_info.bd_addr.nap;

        evt.inst = inst;
    }
#endif

	switch (conn->conn_state)
	{
		case SRV_SPP_CONN_STATE_AUTHORIZING:
		case SRV_SPP_CONN_STATE_CONNECTED:
		case SRV_SPP_CONN_STATE_DISCONNECTING:
		{
			conn->conn_state = SRV_SPP_CONN_STATE_ACTIVATE;			
			evt.para = conn->conn_id;
			if (SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_DISCONNECT_FROM_CM))
			{
				evt.ret = MMI_TRUE;
				SRV_SPP_CLEAR_FLAG(inst, SRV_SPP_FLAG_DISCONNECT_FROM_CM);
			}
			else
				evt.ret = MMI_FALSE;
	#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
			evt.handle= inst->handle;
	#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
			srv_bt_cm_stop_conn(conn->conn_id);
	#ifdef __MMI_BT_DIALER_SUPPORT__
			if (srv_bt_cm_get_existed_conn_num_by_addr(&conn->bt_addr) == 0)
			{
		      srv_bt_cm_set_dev_link_state(&conn->bt_addr,MMI_FALSE);
			}
	#endif
			srv_spp_notify_app(inst, SRV_SPP_EVENT_DISCONNECT, (void*)&evt, MMI_FALSE);
			
			if (SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_ROLE_CLIENT))
			{
				srv_spp_destroy_conn(inst, conn->port);

				if (SRV_SPP_FLAG_IS_SET(inst,SRV_SPP_FLAG_CLOSE_INSTANCE) && !inst->cntx.connect)
				{
					srv_spp_destroy_inst(inst);					
				}
			}
			else if (SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_ROLE_SERVER))
			{
				if (SRV_SPP_FLAG_IS_SET(inst,SRV_SPP_FLAG_CLOSE_INSTANCE))
				{
					srv_spp_port_deactivate_req(conn->port);
					break;
				}
				for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
					if (conn->conn_state == SRV_SPP_CONN_STATE_ACTIVATE)
					{
						conn->conn_id = -1; 
						// TODO:
						break;
					}					
				while (conn = conn->next)
				{
					if (conn->conn_state == SRV_SPP_CONN_STATE_ACTIVATE)
					{				
						srv_spp_port_deactivate_req(conn->port);
						conn->conn_state = SRV_SPP_CONN_STATE_IDLE;
					}
				}
			}
			break;
		}
		default:
			break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_disconnect
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_disconnect(S32 conn_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_conn_cntx* conn = srv_spp_get_conn_by_conn_id(conn_id);
	bt_spp_disconnect_req_struct* disconn_req;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG1(SRV_BT_SPP_DISCONNECT, conn_id);
	switch (conn->conn_state)
	{
		case SRV_SPP_CONN_STATE_CONNECTED:
		{
			disconn_req = (bt_spp_disconnect_req_struct*)construct_local_para(sizeof(*disconn_req), TD_CTRL);
			disconn_req->port = conn->port;
			srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_DISCONNECT_REQ, (void*)disconn_req, NULL);
			conn->conn_state = SRV_SPP_CONN_STATE_DISCONNECTING;
			break;
		}
		default:
			break;
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_port_deactivate_req
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_port_deactivate_req(DCL_DEV port)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_deactivate_req_struct* deactivate_req;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	deactivate_req = (bt_spp_deactivate_req_struct*)construct_local_para(sizeof(*deactivate_req),TD_CTRL);
	deactivate_req->port = port;
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_DEACTIVATE_REQ, (void*)deactivate_req, NULL);	
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_port_deactivate_cnf
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_spp_port_deactivate_cnf(void* msg)
{	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	bt_spp_deactivate_cnf_struct* deactivate_cnf;
	srv_spp_instance* inst;
	MMI_BOOL complete_deactivate;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	deactivate_cnf = (bt_spp_deactivate_cnf_struct*)msg;
	inst = srv_spp_get_inst_by_port(deactivate_cnf->port);
	if (!inst) return MMI_RET_OK;//maybe the connect with this port is not add to the tree.
	
	srv_spp_destroy_conn(inst, deactivate_cnf->port);

	if (!inst->cntx.connect 
		&& SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_CLOSE_INSTANCE))
	{
		srv_spp_destroy_inst(inst);
		SRV_SPP_CLEAR_FLAG(inst, SRV_SPP_FLAG_CLOSE_INSTANCE);
	}

	inst = spp_inst_head;
	complete_deactivate = MMI_TRUE;
	while (inst)
	{
		srv_spp_conn_cntx conn;
		if (inst->cntx.connect)
		{
			complete_deactivate = MMI_FALSE;
			break;
		}
		inst = inst->next;
	}
	if (complete_deactivate && g_spp_need_confirm_to_cm)
	  {
		srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_SPP_PROFILE_UUID);
		g_spp_need_confirm_to_cm = MMI_FALSE;
	  }
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_close
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_close(SppHandle handle)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG1(SRV_BT_SPP_CLOSE, handle);
	srv_spp_debug_display_cntx();
	if (inst = srv_spp_get_inst_by_handle(handle))
	{
		if (!inst->cntx.connect)
		{
			srv_spp_destroy_inst(inst);
			return;
		}
		else
		{		
			SRV_SPP_SET_FLAG(inst, SRV_SPP_FLAG_CLOSE_INSTANCE);
			if (SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_ROLE_SERVER))
				srv_spp_server_close(inst);
			else if (SRV_SPP_FLAG_IS_SET(inst, SRV_SPP_FLAG_ROLE_CLIENT))
				srv_spp_client_close(inst);			
		}
	}
	return;
}

/*****************************************************************************
 * FUNCTION
 * srv_spp_server_close
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * void
 *****************************************************************************/
void srv_spp_server_close(srv_spp_instance* inst)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_conn_cntx* conn = inst->cntx.connect;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (conn)
	{
		switch (conn->conn_state)
		{
			case SRV_SPP_CONN_STATE_ACTIVATE:
			{
				srv_spp_port_deactivate_req(conn->port);
				break;
			}
			case SRV_SPP_CONN_STATE_AUTHORIZING:
			{
				srv_spp_reject(conn->conn_id);
				break;
			}
			case SRV_SPP_CONN_STATE_CONNECTED:
			{
				srv_spp_disconnect(conn->conn_id);
				break;
			}
			case SRV_SPP_CONN_STATE_DEACTIVATING:
			case SRV_SPP_CONN_STATE_DISCONNECTING:
				break;
		}
		conn = conn->next;
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_spp_client_close
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * void
 *****************************************************************************/
void srv_spp_client_close(srv_spp_instance* inst)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_conn_cntx* conn = inst->cntx.connect;
	DCL_DEV port = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (conn)
	{
		switch (conn->conn_state)
		{
			case SRV_SPP_CONN_STATE_ACTIVATE:
			{
				srv_bt_cm_stop_conn(conn->conn_id);
				port = conn->port;
				conn = conn->next;
				srv_spp_destroy_conn(inst, port);

				if (!inst->cntx.connect)
				{
					srv_spp_destroy_inst(inst);
					return;
				}
				break;
			}
			case SRV_SPP_CONN_STATE_CONNECTED:
			{
				srv_spp_disconnect(conn->conn_id);
				conn = conn->next;
				break;
			}
			case SRV_SPP_CONN_STATE_DEACTIVATING:
			case SRV_SPP_CONN_STATE_DISCONNECTING:
				conn = conn->next;
				break;
		}
	}
	return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_notify_app
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_notify_app(srv_spp_instance* inst, U32 evt_id, void* para, MMI_BOOL is_post)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_event_struct evt;
	srv_spp_event_cntx* notify;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG1(SRV_BT_SPP_NOTIFY_APP, evt_id)
	if (is_post)
	{
		MMI_FRM_INIT_EVENT(&evt, evt_id);
		if (para)
		{
			evt.spp_notify = *((srv_spp_event_cntx*)para);
			evt.spp_notify.user_data = inst->user_data;
		}
		mmi_frm_post_event((mmi_event_struct*)&evt, srv_spp_post_notify_proc, (void*)inst);
	}
	else
	{		
		if (para)
		{
			notify = (srv_spp_event_cntx*)para;
			notify->user_data = inst->user_data;
		}
		inst->notifier(evt_id, para);
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_post_notify_proc
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_spp_post_notify_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_event_struct* spp_evt = (srv_spp_event_struct*)evt;
	srv_spp_instance* inst = (srv_spp_instance*)spp_evt->user_data;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inst->notifier(spp_evt->evt_id, &(spp_evt->spp_notify));
	return MMI_RET_OK;
}


/*utils api start*/
/*****************************************************************************
 * FUNCTION
 *  srv_spp_create_inst
 * DESCRIPTION
 *  This function is for app create a spp instance
 * PARAMETERS
 * RETURNS
 *  srv_spp_instance: spp instance
 *****************************************************************************/
srv_spp_instance* srv_spp_create_inst()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	U32 i;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG(SRV_BT_SPP_CREATE_INST);
	for (i = 0; i < SRV_SPP_MAX_INSTANCE; ++i)
		if (sppInstance[i].handle == SRV_SPP_INVALID_HANDLE) break;
	if (i == SRV_SPP_MAX_INSTANCE) return NULL;
	else 
	{
		sppInstance[i].handle = i + 1;//set handle value with i + 1, this means this instance has been used start with 1..
		//add to the head of the link list.
		sppInstance[i].next = spp_inst_head;
		spp_inst_head = &sppInstance[i];

		SRV_SPP_FLAG_INIT(&sppInstance[i]);
		sppInstance[i].cntx.connect = NULL;
		sppInstance[i].cntx.sec_level = SRV_SPP_SEC_ALL;
		memset(sppInstance[i].cntx.srv_name, 0x00, sizeof(sppInstance[i].cntx.srv_name));
		return spp_inst_head;
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_spp_destroy_inst
 * DESCRIPTION
 *  This function is for app create a spp instance
 * PARAMETERS
 *  inst: the spp instance to destroy
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_destroy_inst(srv_spp_instance* inst)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* prev, *index;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG1(SRV_BT_SPP_DESTROY_INST, inst);
	//if the inst is the head
	if (inst == spp_inst_head)
	{
		inst->handle = SRV_SPP_INVALID_HANDLE;
		spp_inst_head = spp_inst_head->next;
		return;
	}
	//not the head, so head need do specially 
	for (prev = index = spp_inst_head; index != NULL; prev = index, index = index->next)
	{
		if (inst == index )
		{
			prev->next = index->next;
			index->handle = SRV_SPP_INVALID_HANDLE;
			break;
		}
	}
	return;
}

/*****************************************************************************
 * FUNCTION
 * srv_spp_create_conn
 * DESCRIPTION
 *  This function is for creating a conn
 * PARAMETERS
 *  inst: the spp instance to create connect for.
 * RETURNS
 *  srv_spp_conn_cntx*  connect pointer.
 *****************************************************************************/
srv_spp_conn_cntx* srv_spp_create_conn(srv_spp_instance* inst)
{	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG1(SRV_BT_SPP_CREATE_CONN, inst);
	for (i = 0; i < SRV_SPP_MAX_CONNECT_NUM; ++i)
		if (sppConn[i].conn_state == SRV_SPP_CONN_STATE_IDLE) break;
	if (i == SRV_SPP_MAX_CONNECT_NUM) return NULL;
	else
	{
		sppConn[i].next = inst->cntx.connect;
		inst->cntx.connect = &sppConn[i];

		sppConn[i].conn_state = SRV_SPP_CONN_STATE_ACTIVATE;
		memset(&sppConn[i].bt_addr, 0x00, sizeof(srv_bt_cm_bt_addr));
		sppConn[i].conn_id = -1;
		sppConn[i].port = SRV_SPP_INVALID_PORT;
		return &sppConn[i];		
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_destroy_conn
 * DESCRIPTION
 *  This function is for destroy connect
 * PARAMETERS
 *  inst: which instance
 *  conn_id: which connect
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_destroy_conn(srv_spp_instance* inst, DCL_DEV port)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_conn_cntx* conn, *prev;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SPP_LOG2(SRV_BT_SPP_DESTROY_CONN, inst, port);
	if (port == inst->cntx.connect->port)
	{
		inst->cntx.connect->conn_state = SRV_SPP_CONN_STATE_IDLE;
		inst->cntx.connect = inst->cntx.connect->next;
		return;
	}
	for (conn = prev = inst->cntx.connect; conn != NULL; prev = conn, conn = conn->next)
	{
		if (port == conn->port)
		{
			prev->next = conn->next;
			conn->conn_state = SRV_SPP_CONN_STATE_IDLE;
			break;
		}		
	}
	return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_get_inst_by_handle
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 * srv_spp_instance* 
 *****************************************************************************/
srv_spp_instance* srv_spp_get_inst_by_handle(SppHandle handle)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst = spp_inst_head;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
		if (inst->handle == handle) return inst;
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_get_inst_by_req_id
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  srv_spp_instance*
 *****************************************************************************/
srv_spp_instance* srv_spp_get_inst_by_req_id(U32 req_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
		if (inst->req_id == req_id) return inst;
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 * srv_spp_get_inst_by_port
 * DESCRIPTION
 * 
 * PARAMETERS
 *  port: connect port
 * RETURNS
 *  srv_spp_instance*
 *****************************************************************************/
srv_spp_instance* srv_spp_get_inst_by_port(DCL_DEV port)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
	{
		for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
			if (conn->port == port) return inst;
	}
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_get_conn_by_port
 * DESCRIPTION
 * 
 * PARAMETERS
 *  port:      connect port
 * RETURNS
 *  srv_spp_conn_cntx*
 *****************************************************************************/
srv_spp_conn_cntx* srv_spp_get_conn_by_port(DCL_DEV port)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
	{
		for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
			if (conn->port == port) return conn;
	}
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_get_inst_by_conn_id
 * DESCRIPTION
 *  
 * PARAMETERS
 * conn_id: connect id
 * RETURNS
 * srv_spp_instance*
 *****************************************************************************/
srv_spp_instance* srv_spp_get_inst_by_conn_id(S32 conn_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
	{
		for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
			if (conn->conn_id == conn_id) return inst;
	}
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 * srv_spp_get_conn_by_conn_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_id: connect id
 * RETURNS
 *  srv_spp_conn_cntx*
 *****************************************************************************/
srv_spp_conn_cntx* srv_spp_get_conn_by_conn_id(S32 conn_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
	{
		for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
			if (conn->conn_id == conn_id) return conn;
	}
	return NULL;
}


#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 * srv_spp_get_noconn_inst_by_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  U32 : req_id
 * RETURNS
 *  srv_spp_instance*
 *****************************************************************************/
srv_spp_instance* srv_spp_get_noconn_inst_by_req_id(U32 req_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
		if ((inst->req_id == req_id)&&(!inst->cntx.connect)) 
		return inst;
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 * srv_spp_get_handle_by_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_bt_cm_bt_addr*: dev_addr
 * RETURNS
 *  SppHandle
 *****************************************************************************/
SppHandle srv_spp_get_handle_by_addr(srv_bt_cm_bt_addr* dev_addr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
		for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
          {
            if(conn->bt_addr.lap == dev_addr->lap &&
               conn->bt_addr.uap == dev_addr->uap &&
               conn->bt_addr.nap == dev_addr->nap)
              {
			    return inst->handle;
              }
}

   return SRV_SPP_INVALID_HANDLE;
}
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  srv_spp_set_security_level
 * DESCRIPTION
 *  This function is for set security level by handle
 * PARAMETERS
 *  handle: spp instance handle 
 *  level: spp instance security level 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_set_security_level(SppHandle handle, SppSecurityLevel level)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst = srv_spp_get_inst_by_handle(handle);
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inst->cntx.sec_level = level;
	return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_set_service_name
 * DESCRIPTION
 *  This function is for set security level by handle
 * PARAMETERS
 *  handle: spp instance handle 
 *  name: server name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_set_service_name(SppHandle handle, WCHAR* name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_instance* inst = srv_spp_get_inst_by_handle(handle);
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_convert(
		MMI_CHSET_UCS2, 
		MMI_CHSET_UTF8, 
		(CHAR*)name,
		inst->cntx.srv_name,
		SRV_SPP_SERVICE_NAME_LENGTH
		);
	return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_spp_get_dev_addr
 * DESCRIPTION
 *
 * PARAMETERS
 *  conn_id: connect id 
 *  bt_addr: bt_addr.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_spp_get_dev_addr(S32 conn_id, srv_bt_cm_bt_addr* bt_addr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	srv_spp_conn_cntx* conn;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	conn = srv_spp_get_conn_by_conn_id(conn_id);
	*bt_addr = conn->bt_addr;
}

void srv_spp_debug_display_cntx()
{
	srv_spp_instance* inst;
	srv_spp_conn_cntx* conn;
	for (inst = spp_inst_head; inst != NULL; inst = inst->next)
	{
		SRV_SPP_LOG2(
			SRV_BT_SPP_DEBUG_DISPLAY_CNTX_INST, 
			inst->handle, 
			inst->req_id
			);
		for (conn = inst->cntx.connect; conn != NULL; conn = conn->next)
		{
			SRV_SPP_LOG3(
				SRV_BT_SPP_DEBUG_DISPLAY_CNTX_CONN,
				conn->conn_id,
				conn->conn_state,
				conn->port
				);
		}
	}
}


void srv_spp_debug_display_uuid(U8* uuid)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(NULL == uuid)
    {
      SRV_SPP_LOG(SRV_BT_SPP_NULL_UUID);
    }  
    else
    {
	  for(i = 0; i < 4; i++)
	    SRV_SPP_LOG4(SRV_BT_SPP_DEBUG_DISPLAY_UUID, uuid[0+i*4], uuid[1+i*4], uuid[2+i*4], uuid[3+i*4]);
    }  
}
#ifdef __MMI_SPP_SCO_SUPPORT__
static U8 srv_spp_audio_connect_cnf(void* msg)
{	
	return MMI_RET_OK;
}
static U8 srv_spp_audio_connect_ind(void* msg)
{
	return MMI_RET_OK;
}
static U8 srv_spp_audio_disconnect_cnf(void* msg)
{
	return MMI_RET_OK;
}
static U8 srv_spp_audio_disconnect_ind(void* msg)
{
	return MMI_RET_OK;
}
#endif/*__MMI_SPP_SCO_SUPPORT__*/

#endif/*__MMI_SPP_SUPPORT__*/
