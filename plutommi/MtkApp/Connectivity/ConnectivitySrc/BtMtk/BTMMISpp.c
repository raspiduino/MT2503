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
 * btmmispp.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT SPP app.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_SPP_SUPPORT__

#include "MMIDataType.h"

#include "SppSrvGprot.h"
#include "BTMMISpp.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
mmi_bt_spp_cntx mmi_spp_context;
mmi_bt_spp_cntx* g_mmi_spp_cntx_p = &mmi_spp_context;
#else /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
mmi_bt_spp_cntx mmi_spp_context[MMI_ENNABLE_SRV_NUM];
mmi_bt_spp_cntx* g_mmi_spp_cntx_p = NULL;
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/

extern kal_bool mmi_frm_nmgr_popup(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string);

void mmi_bt_spp_init(void)
{
	srv_spp_init();
	mmi_bt_spp_server_init();

	
#ifdef __MMI_BT_SPP_CLIENT_SUPPORT__
	mmi_bt_sppc_init();	
#endif /*__MMI_BT_SPP_CLIENT_SUPPORT__*/
}

void mmi_bt_spp_server_init(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 evt_mask = 0;
	#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__	
	U32 i;
	#endif 
	
    /*----------------------------------------------------------------*/
    /* Code Body	                                              */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_INIT);
	#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__	
	g_mmi_spp_cntx_p->handle = srv_spp_open();	
	if (g_mmi_spp_cntx_p->handle == SRV_SPP_INVALID_HANDLE)
		return;
	
	evt_mask = SRV_SPP_EVENT_BIND_FAIL|
		SRV_SPP_EVENT_AUTHORIZE|
		SRV_SPP_EVENT_CONNECT|
		SRV_SPP_EVENT_READY_TO_WRITE|
		SRV_SPP_EVENT_READY_TO_READ|
		SRV_SPP_EVENT_DISCONNECT;	
	srv_spp_set_notify_hdlr(g_mmi_spp_cntx_p->handle, evt_mask, mmi_bt_spp_event_handler, NULL);

	srv_spp_bind(g_mmi_spp_cntx_p->handle, SRV_BT_CM_SPP_PROFILE_UUID);

	g_mmi_spp_cntx_p->conn_id = -1;
	g_mmi_spp_cntx_p->is_connected = 0;
	
	#else /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
	for (i = 0; i < MMI_ENNABLE_SRV_NUM; ++i)
    {
	   mmi_spp_context[i].handle = srv_spp_open();
	   MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_OPEN, i, mmi_spp_context[i].handle); 
	   if (mmi_spp_context[i].handle == SRV_SPP_INVALID_HANDLE)
		  return;

	   evt_mask = SRV_SPP_EVENT_BIND_FAIL|
		   SRV_SPP_EVENT_AUTHORIZE|
		   SRV_SPP_EVENT_CONNECT|
		   SRV_SPP_EVENT_READY_TO_WRITE|
		   SRV_SPP_EVENT_READY_TO_READ|
		   SRV_SPP_EVENT_DISCONNECT;		
	  
	   #ifdef  __MMI_BT_SPP_MULITLINK_TEST__
	     g_spp_multi_recv_cntx[i].handle = mmi_spp_context[i].handle;
	   #endif
	   srv_spp_set_notify_hdlr(mmi_spp_context[i].handle, evt_mask, mmi_bt_spp_event_handler, NULL);

	   srv_spp_bind(mmi_spp_context[i].handle, SRV_BT_CM_SPP_PROFILE_UUID);

	   mmi_spp_context[i].conn_id = -1;
	   mmi_spp_context[i].is_connected = 0;
	   mmi_spp_context[i].cm_callback = NULL;
    }
	#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/

}
extern void mmi_bt_spp_receive_data(void);
S32 mmi_bt_spp_event_handler(U32 evt, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;

	/*----------------------------------------------------------------*/
    /* Code Body	                                              */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_GET_EVENT_ID, evt);
		
	switch (evt)
	{
		case SRV_SPP_EVENT_BIND_FAIL:
		#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
			mmi_bt_spp_bind_handler();
		#else
		    mmi_bt_spp_bind_handler(&notify_para);
		#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
			break;
		case SRV_SPP_EVENT_AUTHORIZE:
			mmi_bt_spp_authorize_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_CONNECT:
			mmi_bt_spp_connect_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
		#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
			mmi_bt_spps_handle_ready_to_write_ind(&notify_para);
		#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
			break;
		case SRV_SPP_EVENT_READY_TO_READ:
			#ifdef __MMI_BT_SPP_TEST__
			mmi_bt_spp_receive_data();
			#endif
		#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
			mmi_bt_spps_handle_ready_to_read_ind(&notify_para);
		#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
			break;
		case SRV_SPP_EVENT_DISCONNECT:
			mmi_bt_spp_disconnect(&notify_para);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}


#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
void mmi_bt_spp_bind_handler(void)
{
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP,MMI_BT_SPP_SERVER_BIND_HANDLER);
	srv_spp_close(g_mmi_spp_cntx_p->handle);
}
#else/*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
void mmi_bt_spp_bind_handler(srv_spp_event_cntx* para)
{
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP,MMI_BT_SPP_SERVER_BIND_HANDLER);
	srv_spp_close(para->handle);
}
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/


void mmi_bt_spp_authorize_ind(srv_spp_event_cntx* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_event_cntx auth_ind = *(srv_spp_event_cntx*)para;
	srv_bt_cm_bt_addr dev_addr;
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
    mmi_bt_spp_cntx * mmi_bt_spp_cntx_temp;
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP,MMI_BT_SPP_SERVER_AUTHORIZE_IND, auth_ind.para, auth_ind.ret);

#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	if (g_mmi_spp_cntx_p->conn_id > 0) 
		srv_spp_reject(auth_ind.para);
	else
		g_mmi_spp_cntx_p->conn_id = auth_ind.para;

	srv_spp_get_dev_addr(g_mmi_spp_cntx_p->conn_id, &dev_addr);

	mmi_bt_authorize_ind_notify(
		NULL,
		&dev_addr,
		SRV_BT_CM_SPP_PROFILE_UUID,
		(void*)mmi_bt_spp_authorize_rsp
		);
#else/*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
	mmi_bt_spp_cntx_temp = mmi_bt_spp_get_cntx_by_handle(para->handle);

	if (mmi_bt_spp_cntx_temp->conn_id > 0) 
	   srv_spp_reject(auth_ind.para);
	else
    {
	   mmi_bt_spp_cntx_temp->conn_id = auth_ind.para;
	   srv_spp_accept(
			   mmi_bt_spp_cntx_temp->conn_id, 
			   mmi_bt_spp_cntx_temp->buf, 
			   sizeof(mmi_bt_spp_cntx_temp->buf)/2,
			   sizeof(mmi_bt_spp_cntx_temp->buf)/2
			   );
    }
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
}

void mmi_bt_spp_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 profile_id, U32 result)
{
	if (result)
		srv_spp_accept(
			g_mmi_spp_cntx_p->conn_id, 
			g_mmi_spp_cntx_p->buf, 
			sizeof(g_mmi_spp_cntx_p->buf)/2,
			sizeof(g_mmi_spp_cntx_p->buf)/2
			);
	else
	{		
		srv_spp_reject(g_mmi_spp_cntx_p->conn_id);
		g_mmi_spp_cntx_p->conn_id = -1;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_spp_connect_ind
 * DESCRIPTION
 * 
 * PARAMETERS
 *  para
 * RETURNS
 *  
 *****************************************************************************/
void mmi_bt_spp_connect_ind(srv_spp_event_cntx* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 str_popup[60];
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	srv_bt_cm_bt_addr dev_addr;
	mmi_spps_connect_ind_struct event;
	mmi_bt_spp_cntx * mmi_bt_spp_cntx_temp;
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_CONN_IND, para->para, para->ret);

#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__	
	g_mmi_spp_cntx_p->is_connected = 1;
	kal_wsprintf(
        str_popup,
        "%w%w",
        (WCHAR*)GetString(STR_BT_PROF_SPP),
        (WCHAR*)GetString(STR_BT_CONN_ED)
        );
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)str_popup);	
#else
  mmi_bt_spp_cntx_temp = mmi_bt_spp_get_cntx_by_handle(para->handle);
  mmi_bt_spp_cntx_temp->is_connected = 1;
  srv_spp_get_dev_addr(mmi_bt_spp_cntx_temp->conn_id, &dev_addr);
  MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_GET_ADDR, dev_addr.lap, dev_addr.uap,dev_addr.nap);
  if(!mmi_bt_spps_is_profie_connected_ex(&dev_addr) && !srv_bt_cm_is_dev_busy(&dev_addr))
	mmi_bt_dialor_connect(&dev_addr); 
    
	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPS_CONNECT_IND);
	event.conn_id = para->para; 		   
	event.result = para->ret; 
	MMI_FRM_CB_EMIT_EVENT(&event);	

#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
}

#ifdef __MMI_BT_SPP_TEST__
extern spp_rev_cntx g_spp_rev_cntx;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_spp_disconnect
 * DESCRIPTION
 * 
 * PARAMETERS
 *  para
 * RETURNS
 *  
 *****************************************************************************/
void mmi_bt_spp_disconnect(srv_spp_event_cntx* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_event_cntx disconn_ind = *(srv_spp_event_cntx*)para;
	U16 str_popup[60];
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	mmi_bt_spp_cntx * mmi_bt_spp_cntx_temp ; 
    mmi_spps_disconnect_cnf_struct event;
	srv_bt_cm_bt_addr dev_addr; 
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/	

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_DISCONN, disconn_ind.para, disconn_ind.ret);

#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	if (g_mmi_spp_cntx_p->conn_id == disconn_ind.para)
	{		
		mmi_bt_authorize_screen_close(SRV_BT_CM_SPP_PROFILE_UUID);
		if (!disconn_ind.ret && g_mmi_spp_cntx_p->is_connected)
		{
			kal_wsprintf(
		        str_popup,
		        "%w%w",
		        (WCHAR*)GetString(STR_BT_PROF_SPP),
		        (WCHAR*)GetString(STR_BT_DISCON_ED)
		        );
	    	mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)str_popup);
		}
		g_mmi_spp_cntx_p->conn_id = -1;
		g_mmi_spp_cntx_p->is_connected = 0;
		#ifdef __MMI_BT_SPP_TEST__
		if (g_spp_rev_cntx.fs_handle > FS_NO_ERROR)
			FS_Close(g_spp_rev_cntx.fs_handle);
		#endif
	}
#else /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
	mmi_bt_spp_cntx_temp = mmi_bt_spp_get_cntx_by_handle(para->handle);
	if((mmi_bt_spp_cntx_temp->conn_id == disconn_ind.para) && mmi_bt_spp_cntx_temp->is_connected)
	{
       /*
		if (!disconn_ind.ret)
			{
				kal_wsprintf(
						str_popup,
						"%w%w",
						(WCHAR*)GetString(STR_BT_PROF_SPP),
						(WCHAR*)GetString(STR_BT_DISCON_ED)
						);
				mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)str_popup);
			}
	    */
		if(mmi_bt_spp_cntx_temp->cm_callback != NULL)
			{
			   MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_INFORM_DISCONN_INFO);
			   
			   srv_spp_get_dev_addr(mmi_bt_spp_cntx_temp->conn_id ,&dev_addr);
			   MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_GET_ADDR, dev_addr.lap,dev_addr.uap,dev_addr.nap);
			   mmi_bt_spp_cntx_temp->cm_callback(&dev_addr, SRV_BT_CM_SPP_CONNECTION, MMI_TRUE, MMI_FALSE, MMI_FALSE);
			}
			
		mmi_bt_spp_cntx_temp->conn_id = -1;
		mmi_bt_spp_cntx_temp->is_connected = 0;

	#ifdef __MMI_BT_SPP_MULITLINK_TEST__
		if (mmi_bt_spp_recv_temp->fs_handle > FS_NO_ERROR)
			FS_Close(mmi_bt_spp_recv_temp->fs_handle);
	#endif	

     	/*Notify calling APP about disconnection*/	
	    MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPS_DISCONNECT_CNF);
	    event.conn_id = disconn_ind.para; 		   
	    event.result = disconn_ind.ret; 		
	    MMI_FRM_CB_EMIT_EVENT(&event);	
 
	}
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/
	else
		return;
}

#ifdef __MMI_BT_SPP_TEST__
spp_rev_cntx g_spp_rev_cntx;
void mmi_bt_spp_receiving_data(void);
void mmi_bt_spp_pre_receive_data(void);

void mmi_bt_spp_receive_data(void)
{
	if (g_spp_rev_cntx.fs_handle <= 0)
		mmi_bt_spp_pre_receive_data();
	mmi_bt_spp_receiving_data();
}

void mmi_bt_spp_pre_receive_data(void)
{
	WCHAR file_name[50];
	U8 drive = (U8)FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE);
	kal_wsprintf(file_name, "%c:\\Mp3.mp3", drive);
	g_spp_rev_cntx.fs_handle = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS);	
}

void mmi_bt_spp_receiving_data(void)
{
	U32 read_size;
	while (1)
	{ 
		read_size = srv_spp_read(
			g_mmi_spp_cntx_p->conn_id,
			g_spp_rev_cntx.buf,
			2048
			);
		if (read_size > 0)
			FS_Write(g_spp_rev_cntx.fs_handle, g_spp_rev_cntx.buf, read_size, NULL); 
		else break;
	}
}
#endif

#ifdef __MMI_BT_SPP_TEST__
typedef struct{
	SppHandle handle;
	S32 conn_id;
	U8 buf[SRV_SPP_MIN_BUFF_SIZE];
	U8 send_buf[2048];
	FS_HANDLE send_file_handle;
	U32 total_size;
	U32 send_remain_size;
}mmi_spp_client;

mmi_spp_client spp_client_cntx;
void mmi_bt_sppc_disconnect_ind(srv_spp_event_cntx* notify_para);
S32 mmi_bt_spp_client_hdlr(U32 evt, void* para);
void mmi_bt_sppc_bind_handler(void);
void mmi_bt_sppc_connect_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_sppc_pre_send_data(void);
void mmi_bt_sppc_send_data(void);
void mmi_bt_sppc_send_data_end(void);
void mmi_bt_sppc_disconnect_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_spp_after_send_data(void);


void mmi_bt_spp_test()
{
	srv_bt_cm_bt_addr bt_addr;
	U32 evt_mask;
	
	bt_addr.lap = 0x005c6612;
	bt_addr.uap = 0x63;
	bt_addr.nap = 0x441b;

	spp_client_cntx.handle = srv_spp_open();
	if (spp_client_cntx.handle == SRV_SPP_INVALID_HANDLE)
		return;
	evt_mask = SRV_SPP_EVENT_CONNECT|
			SRV_SPP_EVENT_READY_TO_WRITE|
			SRV_SPP_EVENT_READY_TO_READ|
			SRV_SPP_EVENT_DISCONNECT;	
	srv_spp_set_notify_hdlr(spp_client_cntx.handle, evt_mask, mmi_bt_spp_client_hdlr, NULL);
	srv_spp_connect(spp_client_cntx.handle,
					SRV_BT_CM_SPP_PROFILE_UUID,
					&bt_addr,
					spp_client_cntx.buf,
					SRV_SPP_MIN_BUFF_SIZE/2,
					SRV_SPP_MIN_BUFF_SIZE/2
					);
}

S32 mmi_bt_spp_client_hdlr(U32 evt, void* para)
{
	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;
	switch (evt)
	{
		case SRV_SPP_EVENT_BIND_FAIL:
			mmi_bt_sppc_bind_handler();
			break;
		case SRV_SPP_EVENT_CONNECT:
			mmi_bt_sppc_connect_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
			mmi_bt_sppc_send_data();
			break;
		case SRV_SPP_EVENT_READY_TO_READ:
			break;
		case SRV_SPP_EVENT_DISCONNECT:
			mmi_bt_sppc_disconnect_ind(&notify_para);
		default:
			break;
	}
	return MMI_RET_OK;
}

void mmi_bt_sppc_bind_handler(void)
{
	srv_spp_close(spp_client_cntx.handle);
}

void mmi_bt_sppc_connect_ind(srv_spp_event_cntx* notify_para)
{
	spp_client_cntx.conn_id = notify_para->para;
//	mmi_bt_sppc_pre_send_data();
}

void mmi_bt_sppc_pre_send_data(void)
{
	FS_HANDLE send_file_hd = FS_Open(L"D:\\Audio\\Mp3.mp3", FS_READ_ONLY);
	spp_client_cntx.send_file_handle = send_file_hd;
	FS_GetFileSize(send_file_hd, &spp_client_cntx.total_size);
	spp_client_cntx.send_remain_size = 0;
	
	mmi_bt_sppc_send_data();
}

void mmi_bt_sppc_send_data(void)
{
	U32 read_size, retval;
	U32 send_size;
	while (spp_client_cntx.total_size || spp_client_cntx.send_remain_size)
	{
		if (!spp_client_cntx.send_remain_size)
		{		
			retval = FS_Read(
				spp_client_cntx.send_file_handle,
				spp_client_cntx.send_buf,
				2048,
				&read_size
				);		
			if (retval < FS_NO_ERROR) MMI_ASSERT(0);
			spp_client_cntx.total_size -= read_size;
			spp_client_cntx.send_remain_size = read_size;
		}
		send_size = srv_spp_write(
							spp_client_cntx.conn_id, 
							spp_client_cntx.send_buf + 2048 - spp_client_cntx.send_remain_size, 
							spp_client_cntx.send_remain_size
							);
		spp_client_cntx.send_remain_size -= send_size;
		if (!spp_client_cntx.total_size || !spp_client_cntx.send_remain_size)
		{
			mmi_bt_sppc_send_data_end();
			break;
		}
		if (spp_client_cntx.send_remain_size) break;
	}
	return;
}

void mmi_bt_sppc_send_data_end(void)
{
	mmi_popup_display_simple((WCHAR*)L"spp send end",
							MMI_EVENT_SUCCESS,
							GRP_ID_ROOT, NULL);
}

void mmi_bt_sppc_disconnect_ind(srv_spp_event_cntx* notify_para)
{
	if (spp_client_cntx.conn_id != notify_para->para)
		return;
	mmi_bt_spp_after_send_data();
	srv_spp_close(spp_client_cntx.handle);
}

void mmi_bt_spp_after_send_data(void)
{
	if (spp_client_cntx.send_file_handle >= 0)
		FS_Close(spp_client_cntx.send_file_handle);
	
}
#endif/*__MMI_BT_SPP_TEST__*/

#ifdef __MMI_BT_SPP_CLIENT_SUPPORT__

mmi_spp_client_cntxt spp_client_cntx;
mmi_spp_client_cntxt* g_spp_client_cntx = &spp_client_cntx;


/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_init
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int evt_msk = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_spp_client_cntx,0,sizeof(g_spp_client_cntx));
	g_spp_client_cntx->handle = srv_spp_open();
	kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_init ");
	
if(g_spp_client_cntx->handle != SRV_SPP_INVALID_HANDLE){
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_init handle : %d",g_spp_client_cntx->handle);
	evt_msk =  SRV_SPP_EVENT_AUTHORIZE|
			SRV_SPP_EVENT_CONNECT|
			SRV_SPP_EVENT_READY_TO_WRITE|
			SRV_SPP_EVENT_READY_TO_READ|
			SRV_SPP_EVENT_DISCONNECT;	

	srv_spp_set_notify_hdlr(g_spp_client_cntx->handle, evt_msk, mmi_bt_sppc_notify_hdlr, NULL);
	//srv_spp_port_activate_req(g_spp_client_cntx->handle);
}

    g_spp_client_cntx->conn_id = -1;
    g_spp_client_cntx->is_connected= -1;	
	g_spp_client_cntx->is_connect_req_sent = -1;
	g_spp_client_cntx->cm_callback = NULL;

	memset(g_spp_client_cntx->recv_buf, 0, SRV_SPP_MIN_BUFF_SIZE);

}

/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_handle_connect_ind
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_handle_connect_ind(srv_spp_event_cntx* notify_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sppc_connect_cnf_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_handle_connect_ind :%d Success: %d",notify_para->para,notify_para->ret);
	if(g_spp_client_cntx->cm_callback)
			//g_spp_client_cntx->cm_callback(SRV_BT_CM_SPP_CONNECTION,(MMI_BOOL)notify_para->ret,MMI_TRUE);
	     g_spp_client_cntx->cm_callback(&g_spp_client_cntx->bt_addr, SRV_BT_CM_SPP_CONNECTION,(MMI_BOOL)notify_para->ret, MMI_TRUE, MMI_FALSE);

	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPC_CONNECT_CNF);
	
	event.conn_id = notify_para->para; 		   
	event.result = notify_para->ret; 

	if(notify_para->ret == MMI_TRUE)
	{
		g_spp_client_cntx->is_connected= 1; 
		g_spp_client_cntx->conn_id= notify_para->para; 		
	}
	else
	{
			g_spp_client_cntx->is_connected = -1; 
	}
  g_spp_client_cntx->is_connect_req_sent = -1;		
		
	MMI_FRM_CB_EMIT_EVENT(&event);	 

}


/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_handle_disconnect_ind
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_handle_disconnect_ind(srv_spp_event_cntx* notify_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sppc_disconnect_cnf_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_handle_disconnect_ind connId:%d Success: %d",notify_para->para,notify_para->ret);
    
    if(g_spp_client_cntx->cm_callback && (g_spp_client_cntx->is_connected == 1))
    {
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"INFORM CM about SPP disconnect");
	//g_spp_client_cntx->cm_callback(SRV_BT_CM_SPP_CONNECTION,(MMI_BOOL)notify_para->ret,MMI_FALSE);
	g_spp_client_cntx->cm_callback(&g_spp_client_cntx->bt_addr, SRV_BT_CM_SPP_CONNECTION,(MMI_BOOL)notify_para->ret, MMI_FALSE, MMI_FALSE);
    }

	if (g_spp_client_cntx->conn_id != notify_para->para)
		return;

	g_spp_client_cntx->conn_id = -1;
	g_spp_client_cntx->is_connected= -1;
    g_spp_client_cntx->is_connect_req_sent = -1;	
	/*Notify calling APP about disconnection*/	

	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPC_DISCONNECT_CNF);
	
	event.conn_id = notify_para->para; 		   
	event.result = notify_para->ret; 		
	MMI_FRM_CB_EMIT_EVENT(&event);	 
}


/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_handle_ready_to_write_ind
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_handle_ready_to_write_ind(srv_spp_event_cntx* notify_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sppc_ready_to_write_ind_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_handle_ready_to_write_ind :d",notify_para->ret);
    
	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPC_READY_TO_WRITE);
	
	event.conn_id = notify_para->para; 		   
	event.result = notify_para->ret; 		

	MMI_FRM_CB_EMIT_EVENT(&event);	 
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_handle_ready_to_read_ind
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_handle_ready_to_read_ind(srv_spp_event_cntx* notify_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sppc_disconnect_cnf_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_handle_ready_to_read_ind :d",notify_para->ret);
    
	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPC_READY_TO_READ);
	
	event.conn_id = notify_para->para; 		
	event.result = notify_para->ret; 	

	MMI_FRM_CB_EMIT_EVENT(&event);	 
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_notify_hdlr
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
S32 mmi_bt_sppc_notify_hdlr(U32 evt, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;

  kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_notify_hdlr event :%d",evt);

		switch (evt)
		{
			case SRV_SPP_EVENT_CONNECT:
				mmi_bt_sppc_handle_connect_ind(&notify_para);
				break;
			case SRV_SPP_EVENT_READY_TO_WRITE:
				mmi_bt_sppc_handle_ready_to_write_ind(&notify_para);				
				break;
			case SRV_SPP_EVENT_READY_TO_READ:
				mmi_bt_sppc_handle_ready_to_read_ind(&notify_para);
				break;
			case SRV_SPP_EVENT_DISCONNECT:
				mmi_bt_sppc_handle_disconnect_ind(&notify_para);
			default:
				break;
		}
	return MMI_RET_OK;
}

void mmi_spp_connect_req_from_cm(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_spp_callback  mmi_spp_cm_cb)
{
	
	  kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_spp_connect_req_from_cm ");
	  
	if(mmi_spp_cm_cb!=NULL)
	{
	g_spp_client_cntx->cm_callback = mmi_spp_cm_cb;
	}
	 if(g_spp_client_cntx->is_connected != 1  && (g_spp_client_cntx->is_connect_req_sent != 1)) 
	 {
      kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"SEND SPP CONNECT REQ");	 	
	mmi_bt_sppc_send_connect_req(dev_addr);
}
   else
   {
   		 kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_spp_connect_req_from_cm already connected");
      // mmi_spp_cm_cb(SRV_BT_CM_SPP_CONNECTION,(MMI_BOOL)MMI_TRUE,MMI_TRUE); 
        mmi_spp_cm_cb(dev_addr, SRV_BT_CM_SPP_CONNECTION, MMI_TRUE, MMI_FALSE, MMI_FALSE);
   }

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
#else
void mmi_bt_sppc_send_disconnect_req_from_cm(srv_bt_cm_bt_addr *bt_addr, srv_bt_cm_spp_callback mmi_spp_cm_cb)
{	
	kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_send_disconnect_req_from_cm 1 ");
		
	if(mmi_spp_cm_cb)
	  g_spp_client_cntx->cm_callback = mmi_spp_cm_cb;
	
	if(g_spp_client_cntx->is_connected != 1)
	  {
		 kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_send_disconnect_req_from_cm 2 ");	
		 mmi_spp_cm_cb(bt_addr, SRV_BT_CM_SPP_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	  }
	else
		mmi_bt_sppc_send_disconnect_req(g_spp_client_cntx->conn_id);
				
	g_spp_client_cntx->is_connect_req_sent = -1;
				
	kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_send_disconnect_req_from_cm Conn Id: %d Is Connected: %d",g_spp_client_cntx->conn_id,g_spp_client_cntx->is_connected);
	
	}


#endif

/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_send_connect_req
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_send_connect_req(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_send_connect_req ");

	g_spp_client_cntx->is_connect_req_sent = 1;	
	g_spp_client_cntx->bt_addr.lap = dev_addr->lap;
	g_spp_client_cntx->bt_addr.nap = dev_addr->nap;
	g_spp_client_cntx->bt_addr.uap = dev_addr->uap;

	srv_spp_connect(g_spp_client_cntx->handle,
					SRV_BT_CM_SPP_PROFILE_UUID,
					&g_spp_client_cntx->bt_addr,
					g_spp_client_cntx->recv_buf,
					SRV_SPP_MIN_BUFF_SIZE/2,
					SRV_SPP_MIN_BUFF_SIZE/2
					);
}


/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_send_disconnect_req
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_sppc_send_disconnect_req(S32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_spp_disconnect(g_spp_client_cntx->conn_id);	

}


/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_send_data
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
S32 mmi_bt_sppc_send_data(S32 conn_id, char* send_buf, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 send_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_send_data ");
    
	if(g_spp_client_cntx->conn_id != conn_id && (len > 0))
	{
		return MMI_RET_ERR;
	}

	while (len > 0)
	{
		send_size = send_size + srv_spp_write( g_spp_client_cntx->conn_id, 
											   send_buf + send_size, 
											   len );
		len = len - send_size;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_sppc_read_data
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
*****************************************************************************/
S32 mmi_bt_sppc_read_data(S32 conn_id, char* read_buf, U32 buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 read_size = 0;
	U32 read_len = buf_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mmi_bt_sppc_read_data ");
     
	while (read_len > 0 )
	{
		read_size = srv_spp_read( g_spp_client_cntx->conn_id, 
							read_buf + read_size, 
							read_len );

		read_len = read_len - read_size;
		
		if(read_size == 0)
			break;
	}
	return MMI_RET_OK;
}

#endif/*__MMI_BT_SPP_CLIENT_SUPPORT__*/



#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_spp_get_cntx_by_handle
 * DESCRIPTION
 * 
 *SppHandle handle
 * PARAMETERS
 *  screen_id
 * RETURNS
 *  
 *****************************************************************************/
mmi_bt_spp_cntx *mmi_bt_spp_get_cntx_by_handle(SppHandle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_GET_CTNX, handle);
	
	for (i = 0; i < MMI_ENNABLE_SRV_NUM; i++)
  	   if(mmi_spp_context[i].handle == handle)
   	  	{ 
   	  	  MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_GET_CTNX_INDEX, i);
 	   	  return &(mmi_spp_context[i]);
		}

	if(MMI_ENNABLE_SRV_NUM == i)
	  {
	    MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_GET_NO_CTNX);
	    return NULL;
	  }
	
}

/*****************************************************************************
 * FUNCTION
 * mmi_bt_spps_send_disconnect_req_from_cm
 * DESCRIPTION
 * 
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_bt_spps_send_disconnect_req_from_cm(srv_bt_cm_bt_addr *bt_addr, srv_bt_cm_spps_callback mmi_spp_cm_cb)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	SppHandle handle;
	mmi_bt_spp_cntx * mmi_bt_spp_cntx_temp; 	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_DISCONN_FROM_CM, bt_addr->lap,bt_addr->uap,bt_addr->nap);

	/*get srv instance handle by bt addr*/
	handle =  srv_spp_get_handle_by_addr(bt_addr);
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_GET_HANDLE_BY_ADDR, handle);
	if(SRV_SPP_INVALID_HANDLE == handle)
		{
   	 	  if(mmi_spp_cm_cb)
   	  		{
		      mmi_spp_cm_cb(bt_addr, SRV_BT_CM_SPP_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	        }
	      else
	  	    {
	  	      
	  	    }
		  return;
		}
	
	/*get mmi cntx by hanle*/
	mmi_bt_spp_cntx_temp = mmi_bt_spp_get_cntx_by_handle(handle);
	if(NULL == mmi_bt_spp_cntx_temp)
		{
   	 	  if(mmi_spp_cm_cb)
   	  		{
			  MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_DISCONN_FROM_CM_ERROR);
		      mmi_spp_cm_cb(bt_addr, SRV_BT_CM_SPP_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	        }
	      else
	  	    {
	  	      
	  	    }
		  return;
		}	

	/*judge if the sppserver is connected*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_IS_CONNECTED, mmi_bt_spp_cntx_temp->is_connected);
	if(mmi_bt_spp_cntx_temp->is_connected != 1)
	  {
   	 	if(mmi_spp_cm_cb)
   	  		{
   	  		  mmi_bt_spp_cntx_temp->cm_callback = mmi_spp_cm_cb;	 
		      mmi_spp_cm_cb(bt_addr, SRV_BT_CM_SPP_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	        }
	    else
	  	    {
	  	      
	  	    }
		return;
	  }	
	else
	 {
	  mmi_bt_spp_cntx_temp->cm_callback = mmi_spp_cm_cb;
	  MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_DISCONN_GET_CONN_ID, mmi_bt_spp_cntx_temp->conn_id);
	  srv_spp_disconnect_from_cm(mmi_bt_spp_cntx_temp->conn_id);	
	 } 
	
}
 

/*****************************************************************************
* FUNCTION
*  mmi_bt_spps_handle_ready_to_write_ind
* DESCRIPTION
*
* PARAMETERS
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_spps_handle_ready_to_write_ind(srv_spp_event_cntx* notify_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_spps_ready_to_write_ind_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_READY_TO_WRITE_IND, notify_para->para, notify_para->ret);

	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPS_READY_TO_WRITE);
	event.conn_id = notify_para->para; 		   
	event.result = notify_para->ret; 		
	MMI_FRM_CB_EMIT_EVENT(&event);	 
}

/*****************************************************************************
* FUNCTION
*  mmi_bt_spps_handle_ready_to_read_ind
* DESCRIPTION
*
* PARAMETERS
* RETURNS
*  NONE.
*****************************************************************************/
void mmi_bt_spps_handle_ready_to_read_ind(srv_spp_event_cntx* notify_para)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_spps_ready_to_read_ind_struct event;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_READY_TO_READ_IND, notify_para->para, notify_para->ret);
	
	MMI_FRM_INIT_EVENT(&event, EVT_ID_SPPS_READY_TO_READ);
	
	event.conn_id = notify_para->para; 		
	event.result = notify_para->ret; 	

	MMI_FRM_CB_EMIT_EVENT(&event);	 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_dialer_app_is_connected_ex
 * DESCRIPTION
 *  This function is judged if any profile except spp is connected 
 * PARAMETERS
 *  bt addr
 * RETURNS
 *  Ture or false
 *****************************************************************************/
MMI_BOOL mmi_bt_spps_is_profie_connected_ex(srv_bt_cm_bt_addr* dev_addr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_MAPC_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_A2DP_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HFP_CONNECTION, dev_addr) ||
       srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_AVRCP_CT_CONNECTION, dev_addr))
	{
    
    	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_IS_CONNECTED); 
        return MMI_TRUE;
        
	}
	
	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_IS_NOT_CONNECTED); 
	return MMI_FALSE;
}

#endif/*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/

#endif/*__MMI_SPP_SUPPORT__*/
