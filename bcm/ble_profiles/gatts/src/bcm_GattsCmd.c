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
 * bcm_GattsCmd.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__BT_GATTS_PROFILE__)
#include "bcmadp.h"

#include "bcm_GattsGprot.h"
#include "bcm_struct.h"
#include "bcm_Gattsrv.h"
#include "bcm_Gattssrv.h"
#include "btostypes.h"

static void bcm_gatts_register_cb(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
static void bcm_gatts_connection_cb(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
static void bcm_gatts_listen_cb(void *reg_ctx, OS_STATUS status);
static void bcm_gatts_add_service_cb(OS_STATUS status, void *reg_ctx,
                GATT_SVC_UUID *srvc_id, ATT_HANDLE srvc_handle);
static void bcm_gatts_add_include_service_cb(OS_STATUS status, void *reg_ctx,
                ATT_HANDLE srvc_handle, ATT_HANDLE incl_srvc_handle);
static void bcm_gatts_add_caharacteristic_cb(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle);
static void bcm_gatts_add_descriptor_cb(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE descr_handle);
static void bcm_gatts_start_service_cb(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);
static void bcm_gatts_stop_service_cb(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

static void bcm_gatts_delete_service_cb(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);
static void bcm_gatts_read_request_cb(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);
static void bcm_gatts_write_request_cb(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);
static void bcm_gatts_excute_write_cb(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel);
static void bcm_gatts_send_response_cb(gatt_conn_struct *conn, OS_STATUS status, U8 need_confirm, ATT_HANDLE handle);
//static void bcm_gatts_read_tx_cb(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, U8 tx_power);
static void bcm_gatts_deregister_cb(void *reg_ctx, OS_STATUS status);
//static void bcm_gatts_connection_ext_cb(gattsrv_conn_struct *conn);
static void bcm_gatts_send_indication_cb(gatt_conn_struct *conn, OS_STATUS status, U8 need_confirm, ATT_HANDLE handle);


gatts_callback_struct bcm_gatts_cbs = {
	bcm_gatts_register_cb,
    bcm_gatts_connection_cb,
	bcm_gatts_listen_cb,
	bcm_gatts_add_service_cb,
	bcm_gatts_add_include_service_cb,
	bcm_gatts_add_caharacteristic_cb,
	bcm_gatts_add_descriptor_cb,
	bcm_gatts_start_service_cb,
	bcm_gatts_stop_service_cb,
	bcm_gatts_delete_service_cb,
	bcm_gatts_read_request_cb,
	bcm_gatts_write_request_cb,
	bcm_gatts_excute_write_cb,
	bcm_gatts_send_response_cb,
	NULL,
	bcm_gatts_deregister_cb,
	NULL,
	bcm_gatts_send_indication_cb,
};

#ifdef MMI_SRV_BT_FMPT_PROFILE 	
#include "bcm_fmptapp.h"
void bcm_fmps_register_req_handler(ilm_struct *msg)
{
    bcm_fmps_register_req_struct *req;
    
    req = (bcm_fmps_register_req_struct*)msg->local_para_ptr;
	fmpt_app_enable();
    return;    
}

void bcm_fmps_deregister_req_handler(ilm_struct *msg)
{
	bcm_fmps_register_req_struct *req;
	
	req = (bcm_fmps_register_req_struct*)msg->local_para_ptr;
	fmpt_app_disable();
	return;    
}


#endif
#ifdef MMI_SRV_BT_PRXR_PROFILE 
#include "bcm_prxrApp.h"
void bcm_pxps_register_req_handler(ilm_struct *msg)
{
	bcm_pxps_register_req_struct *req;
	req = (bcm_pxps_register_req_struct*)msg->local_para_ptr;	
	pxp_app_enable();
	return;    
}

void bcm_pxps_deregister_req_handler(ilm_struct *msg)
{
	bcm_pxps_register_req_struct *req;
	req = (bcm_pxps_register_req_struct*)msg->local_para_ptr;	
	pxp_app_disable();
	return;    
}

#endif

void bcm_gatts_register_req_handler(ilm_struct *msg)
{
    bcm_gatts_register_req_struct *req;
    
    req = (bcm_gatts_register_req_struct*)msg->local_para_ptr;
    srv_gatts_register((bt_uuid_struct *)req->user_id, &bcm_gatts_cbs);
    return;    
}

void bcm_gatts_deregister_req_handler(ilm_struct *msg)
{
    bcm_gatts_deregister_req_struct *req;
    
    req = (bcm_gatts_deregister_req_struct*)msg->local_para_ptr;
    srv_gatts_deregister(req->reg_ctx);
    return;    
}

void bcm_gatts_connect_req_handler(ilm_struct *msg)
{
    bcm_gatts_connect_req_struct *req;
    BD_ADDR addrT;
    req = (bcm_gatts_connect_req_struct*)msg->local_para_ptr;
	
	memcpy(&(addrT.addr), &(req->bd_addr), BD_ADDR_SIZE);
    addrT.linkType = 0;//BT_DEV_TYPE_UNKNOWN
	
    srv_gatts_connect(req->reg_ctx, &addrT, req->direct);
    return;    
}

void bcm_gatts_disconnect_req_handler(ilm_struct *msg)
{
	bcm_gatts_disconnect_req_struct *req;
	gatt_conn_struct *conn;
    BD_ADDR addrT;
	
	req = (bcm_gatts_disconnect_req_struct*)msg->local_para_ptr;
	conn->conn_ctx = req->conn_ctx;
	conn->reg_ctx = req->reg_ctx;
	
	memcpy(&(addrT.addr), &(req->bd_addr), BD_ADDR_SIZE);
    addrT.linkType = 0; //BT_DEV_TYPE_UNKNOWN
	srv_gatts_disconnect(conn, &addrT);
	return;    
}

void bcm_gatts_add_service_req_handler(ilm_struct *msg)
{
	bcm_gatts_add_service_req_struct *req;
	
	req = (bcm_gatts_add_service_req_struct*)msg->local_para_ptr;
	srv_gatts_add_service(req->reg_ctx, &(req->uuid), req->num_handles);
	return;    
}

void bcm_gatts_delete_service_req_handler(ilm_struct *msg)
{
	bcm_gatts_delete_service_req_struct *req;
	
	req = (bcm_gatts_delete_service_req_struct*)msg->local_para_ptr;
	srv_gatts_delete_service(req->reg_ctx, req->service_handle);
	return;    
}	

void bcm_gatts_add_include_service_req_handler(ilm_struct *msg)
{
	bcm_gatts_add_incl_service_req_struct *req;
	
	req = (bcm_gatts_add_incl_service_req_struct*)msg->local_para_ptr;
	srv_gatts_add_included_service(req->reg_ctx, req->service_handle, req->incl_service_handle);
	return;    
}

void bcm_gatts_add_char_req_handler(ilm_struct *msg)
{
	bcm_gatts_add_char_req_struct *req;
	
	req = (bcm_gatts_add_char_req_struct*)msg->local_para_ptr;
	srv_gatts_add_characteristic(req->reg_ctx, req->service_handle, &(req->char_uuid), req->properties, req->permission);
	return;    
}

void bcm_gatts_add_descriptor_req_handler(ilm_struct *msg)
{
	bcm_gatts_add_descr_req_struct *req;
	
	req = (bcm_gatts_add_descr_req_struct*)msg->local_para_ptr;
	srv_gatts_add_descriptor(req->reg_ctx, req->service_handle, &(req->descr_uuid), req->permission);
	return;    
}

extern void bcm_gatts_start_service_req_handler(ilm_struct *msg)
{
	bcm_gatts_start_service_req_struct *req;
	
	req = (bcm_gatts_start_service_req_struct*)msg->local_para_ptr;
	srv_gatts_start_service(req->reg_ctx, req->service_handle, req->transport);
	return;    
}

void bcm_gatts_stop_service_req_handler(ilm_struct *msg)
{
	bcm_gatts_stop_service_req_struct *req;
	
	req = (bcm_gatts_stop_service_req_struct*)msg->local_para_ptr;
	srv_gatts_stop_service(req->reg_ctx, req->service_handle);
	return;    
}

void bcm_gatts_send_indication_req_handler(ilm_struct *msg)
{
	bcm_gatts_send_indication_req_struct *req;
	gatt_conn_struct *conn;
	
	req = (bcm_gatts_send_indication_req_struct*)msg->local_para_ptr;
	conn->conn_ctx = req->conn_ctx;
	conn->reg_ctx = req->reg_ctx;
	srv_gatts_send_indication(conn, req->handle, req->need_confirm, &(req->value));
	return;    
}

void bcm_gatts_send_response_req_handler(ilm_struct *msg)
{
	bcm_gatts_send_response_req_struct *req;
	gatt_conn_struct *conn;
	
	req = (bcm_gatts_send_response_req_struct*)msg->local_para_ptr;
	conn->conn_ctx = req->conn_ctx;
	conn->reg_ctx = req->reg_ctx;
	srv_gatts_send_response(conn, req->trans_id, req->result, req->handle, &(req->value));
	return;    
}

void bcm_gatt_read_local_addr_req_handler(ilm_struct* msg)
{
    bcm_gatt_read_local_addr_req_struct *req = (bcm_gatt_read_local_addr_req_struct*)msg->local_para_ptr;
    
	srv_gatts_read_random_addr();
	return;    
}

void bcm_gatts_listen_req_handler(ilm_struct *msg)
{
	bcm_gatts_listen_req_struct *req;
	
	req = (bcm_gatts_listen_req_struct*)msg->local_para_ptr;
	srv_gatts_listen(req->reg_ctx, req->start);
	return;    
}


static void bcm_gatts_register_cb(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bcm_gatts_register_cnf_struct *cnf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf = construct_local_para(sizeof(bcm_gatts_register_cnf_struct), TD_RESET);

    cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	memcpy(&(cnf->user_id), app_uuid, sizeof(bt_uuid_struct));

    bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_REGISTER_CNF, cnf, NULL);
}
static void bcm_gatts_deregister_cb(void *reg_ctx, OS_STATUS status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_deregister_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_deregister_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;

	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_DEREGISTER_CNF, cnf, NULL);
}

static void bcm_gatts_connection_cb(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bcm_gatts_connect_cnf_struct *cnf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf = construct_local_para(sizeof(bcm_gatts_connect_cnf_struct), TD_RESET);

    cnf->reg_ctx = conn->reg_ctx;
    cnf->conn_ctx = conn->conn_ctx;
	memcpy(&(cnf->bd_addr), bd_addr, BD_ADDR_SIZE);
	if (TRUE == connected) {//connect ind
	    cnf->result = 0;
		bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_CONNECTED_IND, cnf, NULL);
	} else {//disconnect ind
	    cnf->result = 0;
		bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_DISCONNECTED_IND, cnf, NULL);
	}

}
static void bcm_gatts_listen_cb(void *reg_ctx, OS_STATUS status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bcm_gatts_listen_cnf_struct *cnf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf = construct_local_para(sizeof(bcm_gatts_listen_cnf_struct), TD_RESET);

    cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_LISTEN_CNF, cnf, NULL);
}

static void bcm_gatts_add_service_cb(OS_STATUS status, void *reg_ctx,
                GATT_SVC_UUID *srvc_id, ATT_HANDLE srvc_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_add_service_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_add_service_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
	memcpy(&(cnf->uuid), srvc_id, sizeof(GATT_SVC_UUID));
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_ADD_SERVICE_CNF, cnf, NULL);
}

static void bcm_gatts_add_include_service_cb(OS_STATUS status, void *reg_ctx,
                ATT_HANDLE srvc_handle, ATT_HANDLE incl_srvc_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_add_incl_service_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_add_incl_service_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
	cnf->incl_service_handle = incl_srvc_handle;
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_ADD_INCL_SERVICE_CNF, cnf, NULL);
}

static void bcm_gatts_add_caharacteristic_cb(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_add_char_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_add_char_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
	cnf->char_handle = char_handle;
	memcpy(&(cnf->char_uuid), uuid, sizeof(ATT_UUID));
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_ADD_CHAR_CNF, cnf, NULL);
}

static void bcm_gatts_add_descriptor_cb(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE descr_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_add_descr_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_add_descr_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
	cnf->descr_handle = descr_handle;
	memcpy(&(cnf->descr_uuid), uuid, sizeof(ATT_UUID));
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_ADD_DESCR_CNF, cnf, NULL);
}

static void bcm_gatts_start_service_cb(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_start_service_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_start_service_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_START_SERVICE_CNF, cnf, NULL);
}

static void bcm_gatts_stop_service_cb(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_stop_service_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_stop_service_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_STOP_SERVICE_CNF, cnf, NULL);
}

static void bcm_gatts_delete_service_cb(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_delete_service_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_delete_service_cnf_struct), TD_RESET);

	cnf->reg_ctx = reg_ctx;
	cnf->result = (U8)status;
	cnf->service_handle = srvc_handle;
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_DELETE_SERVICE_CNF, cnf, NULL);
}

static void bcm_gatts_send_response_cb(gatt_conn_struct *conn, OS_STATUS status, U8 need_confirm, ATT_HANDLE handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_send_response_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_send_response_cnf_struct), TD_RESET);

	cnf->reg_ctx = conn->reg_ctx;
	cnf->conn_ctx = conn->conn_ctx;
	cnf->result = (U8)status;
	cnf->handle = handle;
	cnf->need_confirm = need_confirm;
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_SEND_RESPONSE_CNF, cnf, NULL);
}


static void bcm_gatts_send_indication_cb(gatt_conn_struct *conn, OS_STATUS status, U8 need_confirm, ATT_HANDLE handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_send_indication_cnf_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_send_indication_cnf_struct), TD_RESET);

	cnf->reg_ctx = conn->reg_ctx;
	cnf->conn_ctx = conn->conn_ctx;
	cnf->result = (U8)status;
	cnf->handle = handle;
	cnf->need_confirm = need_confirm;
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_SEND_INDICATION_CNF, cnf, NULL);
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
#endif

static void bcm_gatts_read_request_cb(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_read_request_ind_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_read_request_ind_struct), TD_RESET);

	cnf->reg_ctx = conn->reg_ctx;
	cnf->conn_ctx = conn->conn_ctx;
	cnf->handle = attr_handle;
	cnf->is_long = is_long;
	cnf->offset = offset;
	cnf->trans_id = trans_id;
	memcpy(&(cnf->bd_addr), bd_addr, BD_ADDR_SIZE);
		
	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_READ_REQUEST_IND, cnf, NULL);
}

static void bcm_gatts_write_request_cb(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_write_request_ind_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_write_request_ind_struct), TD_RESET);

	cnf->reg_ctx = conn->reg_ctx;
	cnf->conn_ctx = conn->conn_ctx;
	cnf->handle = attr_handle;
	cnf->need_rsp = need_rsp;
	cnf->offset = offset;
	cnf->trans_id = trans_id;
	cnf->is_prepare = is_prep;
	memcpy(&(cnf->bd_addr), bd_addr, BD_ADDR_SIZE);
	memcpy(&(cnf->value), value, sizeof(ATT_VALUE));

	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_WRITE_REQUEST_IND, cnf, NULL);
}

static void bcm_gatts_excute_write_cb(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	bcm_gatts_exec_write_request_ind_struct *cnf;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cnf = construct_local_para(sizeof(bcm_gatts_exec_write_request_ind_struct), TD_RESET);

	cnf->reg_ctx = conn->reg_ctx;
	cnf->conn_ctx = conn->conn_ctx;
	cnf->trans_id = trans_id;
	cnf->cancel = cancel;
	memcpy(&(cnf->bd_addr), bd_addr, BD_ADDR_SIZE);

	bcm_send_ilm(MOD_L4C, MSG_ID_BCM_GATTS_EXEC_WRITE_REQUEST_IND, cnf, NULL);
}

#endif
