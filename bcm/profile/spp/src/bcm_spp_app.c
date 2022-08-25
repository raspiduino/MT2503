/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE: BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES:
*  EXPRESS OR IMPLIED: INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY: FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY: INCORPORATED IN: OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE: AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE:
*  AT MEDIATEK'S OPTION: TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE:
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA: USA: EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES: CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO: CA: UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bcm_spp_app.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for instead of app layer in BCM (just like MMI BT APP) .
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_AT_CMD__


#ifdef __BT_SPP_PROFILE__

/*****************
Include Statements
******************/
//#include "kal_release.h"      	/* Basic data type */

//#include "stack_common.h"  
//#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */

//#include "stacklib.h"        	/* Basic type for dll: evshed: stacktimer */

//#include "event_shed.h"       	/* Event scheduler */

//#include "stack_timer.h"      	/* Stack timer */
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "Bcm_btcmSrvProt.h"
#include "BcmSppSrv.h"
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"
#include "bcmadp.h"
#include "bcm_struct.h"
#include "bcm_btcmApp.h"
#include "BcmSppSrvGprot.h"
#include "bcm_spp_app.h"

//create a SPP server instance
bcm_app_spp_cntx bcm_spp_context;
bcm_app_spp_cntx *g_bcm_spp_cntx_p = &bcm_spp_context;
//create a spp client instance
bcm_app_spp_client_cntxt bcm_spp_client_cntx;
bcm_app_spp_client_cntxt* g_bcm_spp_client_cntx = &bcm_spp_client_cntx;

void bcm_app_spp_server_init(void)
{	
	kal_uint32 evt_mask = 0;
	g_bcm_spp_cntx_p->handle = srv_spp_open();	
	if (g_bcm_spp_cntx_p->handle == SRV_SPP_INVALID_HANDLE)
		return;
	
	evt_mask = SRV_SPP_EVENT_BIND_FAIL|
		SRV_SPP_EVENT_AUTHORIZE|
		SRV_SPP_EVENT_CONNECT|
		SRV_SPP_EVENT_READY_TO_WRITE|
		SRV_SPP_EVENT_READY_TO_READ|
		SRV_SPP_EVENT_DISCONNECT;	
	srv_spp_set_notify_hdlr(g_bcm_spp_cntx_p->handle, evt_mask, bcm_app_spp_event_handler, NULL);

	srv_spp_bind(g_bcm_spp_cntx_p->handle, SRV_BT_CM_SPP_PROFILE_UUID);

	g_bcm_spp_cntx_p->conn_id = -1;
	g_bcm_spp_cntx_p->is_connected = 0;
}

/*验证蓝牙SPP协议 -- chengjun  2017-05-22*/
#define TEST_BT_SPP	

#if defined (TEST_BT_SPP)
static void bt_spp_write_test(void)
{
    static int i=0;
    char sppBuff[128];
    sprintf(sppBuff,"BT spp write %d#",i++);				  
    srv_spp_write(g_bcm_spp_cntx_p->conn_id, sppBuff, sizeof(sppBuff));
    U_PutUARTBytes(0, (kal_uint8*)sppBuff, strlen(sppBuff));
}
#endif /* TEST_BT_SPP */

kal_int32 bcm_app_spp_event_handler(kal_uint32 evt, void* para)
{
#if defined (TEST_BT_SPP)
    char testLog[64] = {0};
    char sppBuff[128];
    sprintf(testLog, "sss bcm_app_spp_event_handler 0x%X\r\n", evt);
    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* TEST_BT_SPP */

    kal_prompt_trace(MOD_BCM,"bcm_app_spp_event_handler RECEIVED EVENT %d",evt);
	switch (evt)
	{
		case SRV_SPP_EVENT_BIND_FAIL:
			
			break;
		case SRV_SPP_EVENT_AUTHORIZE:
		{
        	srv_spp_event_cntx auth_ind = *(srv_spp_event_cntx*)para;
        	srv_bt_cm_bt_addr dev_addr;
        	const srv_bt_cm_dev_struct* dev_info_p = NULL; 
        	
        	if (g_bcm_spp_cntx_p->conn_id > 0) 
        		srv_spp_reject(auth_ind.para);
        	else
        		g_bcm_spp_cntx_p->conn_id = auth_ind.para;

        	srv_spp_get_dev_addr(g_bcm_spp_cntx_p->conn_id, &dev_addr);
            {
                bcm_spp_evt_authorize_struct *event_struct = (bcm_spp_evt_authorize_struct *)get_ctrl_buffer(sizeof(bcm_spp_evt_authorize_struct));
                event_struct->dev_addr.lap = dev_addr.lap;
                event_struct->dev_addr.uap = dev_addr.uap;
                event_struct->dev_addr.nap = dev_addr.nap;

                dev_info_p = srv_bt_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr*)&dev_addr,SRV_BT_CM_ALL_DEV);
                if(dev_info_p)
                {
                    event_struct->name_len = strlen(dev_info_p->name);
                    event_struct->name_len = event_struct->name_len < BTBM_ADP_MAX_NAME_LEN ? event_struct->name_len : BTBM_ADP_MAX_NAME_LEN;
                    memcpy(event_struct->name,dev_info_p->name,event_struct->name_len);
                }
                cmd_hdlr_profile_event_ind(SRV_BT_CM_SPP_PROFILE_UUID,evt,KAL_TRUE,(kal_uint8*)event_struct,sizeof(bcm_spp_evt_authorize_struct));
            }
        }
			break;
		case SRV_SPP_EVENT_CONNECT:
		{
            //currently , server don't care about this EVENT.
            //client care this EVENT.
		}
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
        {
            #if 0
            //-------------------------------------------------------------
            //验证蓝牙SPP协议			  chengjun  2017-02-24
            srv_spp_event_cntx conn_ind = *(srv_spp_event_cntx*)para;
            sprintf(sppBuff,"%s","BT write :1234567890#");                
            srv_spp_write(conn_ind.para, sppBuff, sizeof(sppBuff));
            U_PutUARTBytes(0, (kal_uint8*)sppBuff, strlen(sppBuff));
            //-------------------------------------------------------------
            #endif
        }
			break;
		case SRV_SPP_EVENT_READY_TO_READ:
		{
#if defined (TEST_BT_SPP)
                srv_spp_event_cntx conn_ind = *(srv_spp_event_cntx*)para;  
                memset(sppBuff, 0,sizeof(sppBuff));
                srv_spp_read(conn_ind.para, sppBuff, sizeof(sppBuff));
                U_PutUARTBytes(0, (kal_uint8*)sppBuff, strlen(sppBuff));
                bt_spp_write_test();
#endif /* TEST_BT_SPP */
		}
			break;
		case SRV_SPP_EVENT_DISCONNECT:
        {
        	srv_spp_event_cntx disconn_ind = *(srv_spp_event_cntx*)para;
        	
        	if (g_bcm_spp_cntx_p->conn_id == disconn_ind.para)
        	{
        	    srv_spp_conn_cntx* conn = NULL;
        	    //always success, so we don't use this  for cnf.

        	    //also, we need reset the connection, or the conn_id may cause mixed.
        	    conn = srv_spp_get_conn_by_conn_id(g_bcm_spp_cntx_p->conn_id);
        	    if(conn)
        	    {
            	    conn->conn_id = -1;
        	    }

        	    //also, we must reset the blow flags, or else the 2rd time of connn will failed.
        		g_bcm_spp_cntx_p->conn_id = -1;
        		g_bcm_spp_cntx_p->is_connected = 0;
        	}
        }			
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}
void bcm_app_spp_authorize_rsp(srv_bt_cm_bt_addr bt_addr, U32 profile_id, kal_bool result)
{
	if (result == KAL_TRUE)
	{
		srv_spp_accept(
			g_bcm_spp_cntx_p->conn_id, 
			g_bcm_spp_cntx_p->buf, 
			sizeof(g_bcm_spp_cntx_p->buf)/2,
			sizeof(g_bcm_spp_cntx_p->buf)/2
			);
    }
	else if(result == KAL_FALSE)
	{
		srv_spp_reject(g_bcm_spp_cntx_p->conn_id);
		g_bcm_spp_cntx_p->conn_id = -1;
	}
	else
	{
        ASSERT(0);
	}
}
void bcm_app_sppc_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int evt_msk = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_bcm_spp_client_cntx,0,sizeof(g_bcm_spp_client_cntx));
	g_bcm_spp_client_cntx->handle = srv_spp_open();
	kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"bcm_sppc_init ");
	
    if(g_bcm_spp_client_cntx->handle != SRV_SPP_INVALID_HANDLE)
    {
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"bcm_sppc_init handle : %d",g_bcm_spp_client_cntx->handle);
    	evt_msk =  SRV_SPP_EVENT_AUTHORIZE|
    			SRV_SPP_EVENT_CONNECT|
    			SRV_SPP_EVENT_READY_TO_WRITE|
    			SRV_SPP_EVENT_READY_TO_READ|
    			SRV_SPP_EVENT_DISCONNECT;	

    	srv_spp_set_notify_hdlr(g_bcm_spp_client_cntx->handle, evt_msk, bcm_sppc_notify_hdlr, NULL);
    	//srv_spp_port_activate_req(g_bcm_spp_client_cntx->handle);
    }

    g_bcm_spp_client_cntx->conn_id = -1;
    g_bcm_spp_client_cntx->is_connected= -1;	
	g_bcm_spp_client_cntx->is_connect_req_sent = -1;
	g_bcm_spp_client_cntx->cm_callback = NULL;
	//add this flag to remember whether this sppc is inited.
	g_bcm_spp_client_cntx->is_initted = KAL_TRUE;

	memset(g_bcm_spp_client_cntx->recv_buf, 0, SRV_SPP_MIN_BUFF_SIZE);

}
kal_int32 bcm_sppc_notify_hdlr(kal_uint32 evt, void* para)
{
	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;
	
#if defined (TEST_BT_SPP)
    char testLog[128] = {0};
    char sppBuff[128];
    sprintf(testLog, "ccc bcm_sppc_notify_hdlr 0x%x\r\n", evt);
    U_PutUARTBytes(0, (kal_uint8*)testLog, strlen(testLog));
#endif /* TEST_BT_SPP */

    kal_prompt_trace(MOD_BCM,"bcm_sppc_notify_hdlr RECEIVED EVENT %d",evt);

    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"bcm_sppc_notify_hdlr event :%d",evt);

	switch (evt)
	{
		case SRV_SPP_EVENT_CONNECT:
		{
            //currently , server don't care about this EVENT.
            //client care this EVENT.
            // when connect success, CM will send cnf in SRV_BT_CM_EVENT_CONNECT_RES.
            // but when connect fail, Profile will send cnf here.

            //unfortunately, MMI Service did't post addr by EVENT, so we add dev_addr SRV_SPP_EVENT_CONNECT

	
        	srv_spp_event_cntx conn_ind = *(srv_spp_event_cntx*)para;

			if(conn_ind.ret == KAL_FALSE)
            {
                srv_spp_instance* inst = (srv_spp_instance*)conn_ind.inst;
                if(srv_bt_cm_get_state() != SRV_BT_CM_STATE_DEACTIVATING)
                {
                    cmd_hdlr_bt_profile_conn_cnf(KAL_FALSE,conn_ind.dev_addr,SRV_BT_CM_SPP_PROFILE_UUID,0);
                }

                // when sppc disconnect , we need destory inst
                
                if(inst && inst->handle != SRV_SPP_INVALID_HANDLE)
                {
        	        srv_spp_destroy_inst(inst);	
        	    }
            }
            else
            {
				/*能够连接，不能通信 -- chengjun          2017-04-26*/
                g_bcm_spp_client_cntx->conn_id = conn_ind.para;
            }
		}
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
		{
            //we need set the owner of client to ATCI
            ASSERT(0);
			/*不支持作为客户端 -- chengjun          2017-04-26*/
		}
			break;
		case SRV_SPP_EVENT_READY_TO_READ:
		{
            //we need set the owner of client to ATCI
            ASSERT(0);
			/*不支持作为客户端 -- chengjun          2017-04-26*/
		}
			break;
		case SRV_SPP_EVENT_DISCONNECT:
		{
        	srv_spp_event_cntx disconn_ind = *(srv_spp_event_cntx*)para;
        	
        	if (g_bcm_spp_client_cntx->conn_id == disconn_ind.para)
        	{
        	    srv_spp_conn_cntx* conn = NULL;
        	    srv_spp_instance* inst = (srv_spp_instance*)disconn_ind.inst;
        	    //we need ind ATCI this info.
        	    bcm_spp_evt_disconnect_struct *ind = (bcm_spp_evt_disconnect_struct *)get_ctrl_buffer(sizeof(bcm_spp_evt_disconnect_struct));

                ind->dev_addr.lap = disconn_ind.dev_addr.lap;
                ind->dev_addr.uap = disconn_ind.dev_addr.uap;
                ind->dev_addr.nap = disconn_ind.dev_addr.nap;

        	    cmd_hdlr_profile_event_ind(SRV_BT_CM_SPP_PROFILE_UUID,evt,KAL_TRUE,(kal_uint8 *)ind,sizeof(bcm_spp_evt_disconnect_struct));

        	    //also, we need reset the connection, or the conn_id may cause mixed.
        	    conn = srv_spp_get_conn_by_conn_id(g_bcm_spp_client_cntx->conn_id);
        	    if(conn)
        	    {
            	    conn->conn_id = -1;
        	    }
                
        	    // when sppc disconnect , we need destory inst
                if(inst && inst->handle != SRV_SPP_INVALID_HANDLE)
                {
        	        srv_spp_destroy_inst(inst);	
        	    }
        	    g_bcm_spp_client_cntx->conn_id = -1;
        		g_bcm_spp_client_cntx->is_connected = 0;
        	}
        }
		default:
			break;
	}
	return MMI_RET_OK;
}

void bcm_app_spp_connect(srv_bt_cm_bt_addr bt_addr)
{
    //after sppc disconnected, we found that spp client inst has been reset
    // so here we need reopen it when
    
	srv_spp_connect(g_bcm_spp_client_cntx->handle,
					SRV_BT_CM_SPP_PROFILE_UUID,
					&bt_addr,
					g_bcm_spp_client_cntx->recv_buf,
					SRV_SPP_MIN_BUFF_SIZE/2,
					SRV_SPP_MIN_BUFF_SIZE/2
					);
}
void bcm_app_spp_init(void)
{
	srv_spp_init();
	bcm_app_spp_server_init();
}
#endif

#endif



