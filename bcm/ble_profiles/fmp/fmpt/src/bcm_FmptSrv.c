#ifdef __BT_GATTS_PROFILE__ 

//#include "DebugInitDef_Int.h"
#include "bcm_FmptSrv.h"
#include "bcm_Fmpt_def.h"
#include "bcm_FmpCommon.h"

//#include "MMI_features.h"
#include "bcmadp.h"
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
#include "BLESrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "mmi_cb_mgr_gprot.h"
#endif

#include "bcm_trc.h"

#ifdef MMI_SRV_BT_FMPT_PROFILE 

/** BT-GATT Server callback structure. */
void fmpt_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void fmpt_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void fmpt_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);
void fmpt_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

//void fmpt_get_services_callback(OS_STATUS status, void *reg_ctx);
void fmpt_add_services_callback(OS_STATUS status, void *reg_ctx);
//void fmpt_delete_services_callback(OS_STATUS status, void *reg_ctx);
BtStatus fmpt_init(fmpt_callback_t *cb);
BtStatus fmpt_deinit();
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
mmi_ret fmpt_handle_cm_disconnect(mmi_event_struct *para);
#endif
void fmpt_connection_ext_callback(gattsrv_conn_struct *conn);

#define FMPT_MAX_VALUE_LEN 1

FmptCntx  g_fmpt_cntx = {0};
U8        g_fmpt_uid[] = {
	0xB6, 0x75, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};
gatts_callback_struct g_fmpt_cb = {
	fmpt_register_server_callback,
    fmpt_connection_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	fmpt_service_started_callback,
	NULL,
	NULL,
	NULL,
	fmpt_request_write_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	fmpt_connection_ext_callback,
	NULL,
};
gatts_factory_callback_struct g_fmpt_factory_cb = {
	NULL,
	NULL,
	fmpt_add_services_callback,
	NULL,
};

int fmpt_find_uuid_by_handle(ATT_HANDLE att_handle, ATT_UUID *svc_uuid, ATT_UUID *chr_uuid)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_fmpt_cntx.srv_list.srvlist);

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_find_uuid_by_handle %x!\n", att_handle);
	if(mmi_IsListEmpty(&g_fmpt_cntx.srv_list.srvlist))
		return TYPE_UNKNOW;
	
	while((ListEntry *)svc_list != &g_fmpt_cntx.srv_list.srvlist)
	{
		if(svc_list->handle == att_handle)
		{
			kal_prompt_trace(MOD_BT, "[FMPT] svc_list->type %d!\n", svc_list->type);
			switch(svc_list->type)
			{
			case TYPE_SERVICE:
				memcpy(svc_uuid, &svc_list->uuid, sizeof(ATT_UUID));
				return TYPE_SERVICE;
			case TYPE_CHARACTERISTIC:
				memcpy(chr_uuid, &svc_list->uuid, sizeof(ATT_UUID));
				fmpt_find_uuid_by_handle(svc_list->srvhandle, svc_uuid, chr_uuid);
				return TYPE_CHARACTERISTIC;
			default:
				return svc_list->type;
			}
		}
			
		svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
	}
	return TYPE_UNKNOW;
}

void fmpt_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_register_server_callback status %x, state %d, op_flag %d!\n", 
		             status, g_fmpt_cntx.state, g_fmpt_cntx.op_flag);
	if(memcmp(app_uuid, &g_fmpt_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if(g_fmpt_cntx.state == FMP_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_fmpt_cntx.reg_ctx = reg_ctx;
				if(g_fmpt_cntx.op_flag == FMPT_OP_INIT)
				{
					g_fmpt_cntx.op_flag = FMPT_OP_ADD_SERVICE;
					#ifndef FMPT_UT
					srv_gatts_profile_factory_get_services(g_fmpt_cntx.reg_ctx, PROFILE_ID_FINDME, &g_fmpt_cntx.srv_list);
					srv_gatts_profile_factory_add_services(g_fmpt_cntx.reg_ctx, &g_fmpt_cntx.srv_list);
					#endif
				}
			}
			else
			{
				g_fmpt_cntx.reg_ctx = NULL;
				g_fmpt_cntx.callback = NULL;
				g_fmpt_cntx.op_flag = FMPT_OP_DEINIT;
				g_fmpt_cntx.state = FMP_STATUS_DISABLED;
			}
		}
		else if(g_fmpt_cntx.state == FMP_STATUS_DISABLING)
		{	
			if(g_fmpt_cntx.op_flag == FMPT_OP_INIT)
			{
				g_fmpt_cntx.state = FMP_STATUS_ENABLING;
				#ifndef FMPT_UT
				srv_gatts_profile_factory_register(&g_fmpt_cntx.uid, &g_fmpt_cb, &g_fmpt_factory_cb);
				#endif
			}
			else
			{
				g_fmpt_cntx.reg_ctx = NULL;
				g_fmpt_cntx.callback = NULL;
				g_fmpt_cntx.op_flag = FMPT_OP_DEINIT;
				g_fmpt_cntx.state = FMP_STATUS_DISABLED;
			}
		}
	}
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_register_server_callback -!\n");
}

void fmpt_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	FmptConnCntx    *pConnNode = (FmptConnCntx *)mmi_GetHeadList(&g_fmpt_cntx.conn_list);
	FmptConnCntx    *pConnNext = NULL;

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_connection_callback connected %d!\n", connected);
	if(!mmi_IsListEmpty(&g_fmpt_cntx.conn_list))
	{
	while ((ListEntry *)pConnNode != &g_fmpt_cntx.conn_list)
	{
		pConnNext = (FmptConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			kal_prompt_trace(MOD_BT, "[FMPT] find in list!\n");
			pConnNode->conn_ctx = conn->conn_ctx;
			if(connected && (pConnNode->conn_status != FMP_STATUS_CONNECTED))
			{
				//do next step Discovery all
				#ifndef FMPT_UT
				
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
                    if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
#endif
				srv_gatts_listen(conn->reg_ctx, FALSE);
    				//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
				#endif
				pConnNode->conn_status = FMP_STATUS_CONNECTED;
				if(g_fmpt_cntx.callback != NULL)
					g_fmpt_cntx.callback->connection_state_cb(bd_addr->addr, FMP_STATUS_CONNECTED);
			}
			else if(!connected)
			{
				#ifndef FMPT_UT
				srv_gatts_listen(conn->reg_ctx, TRUE);
				#endif
				mmi_RemoveEntryList(&pConnNode->conn_node);
				free_ctrl_buffer(pConnNode);
				if(g_fmpt_cntx.callback != NULL)
					g_fmpt_cntx.callback->connection_state_cb(bd_addr->addr, FMP_STATUS_DISCONNECTED);
			}
			return;
		}
		pConnNode = pConnNext;
	}
	}
	else
	{
	if(connected)
	{
		kal_prompt_trace(MOD_BT, "[FMPT] not find in list!\n");
		pConnNode = (FmptConnCntx *)get_ctrl_buffer(sizeof(FmptConnCntx));
		memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
		pConnNode->conn_ctx = conn->conn_ctx;
		#ifndef FMPT_UT
		
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
            if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
#endif
		srv_gatts_listen(conn->reg_ctx, FALSE);
    		//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
		#endif
		pConnNode->conn_status = FMP_STATUS_CONNECTED;
		mmi_InsertTailList(&g_fmpt_cntx.conn_list, &pConnNode->conn_node);
		if(g_fmpt_cntx.callback != NULL)
			g_fmpt_cntx.callback->connection_state_cb(bd_addr->addr, FMP_STATUS_CONNECTED);
	}
}
}

void fmpt_connection_ext_callback(gattsrv_conn_struct *conn)
{
    if (!conn)
    {
        return;
    }
    
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_connection_ext_callback connected %d, is_ind:%d!\n", conn->connected, conn->is_ind);
}

void fmpt_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                     ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                     BOOL need_rsp, BOOL is_prep)
{
	FmptConnCntx    *pConnNode = (FmptConnCntx *)mmi_GetHeadList(&g_fmpt_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = fmpt_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_request_write_callback attr_handle %x, svc_uuid16 %x, chr_uuid16 %x!\n", 
		             attr_handle, svc_uuid16, chr_uuid16);
	if(mmi_IsListEmpty(&g_fmpt_cntx.conn_list))
	{
		kal_prompt_trace(MOD_BT, "[FMPT] fmpt_request_write_callback doesn't connected!\n");
		return;
	}
	while ((ListEntry *)pConnNode != &g_fmpt_cntx.conn_list)
	{
		if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			kal_prompt_trace(MOD_BT, "[FMPT] alert level %d!\n", value->value[offset]);
			if(svc_uuid16 == IMMEDIATE_ALERT_SERVICE && chr_uuid16 == ALERT_LEVEL_CHAR_UUID)
			{
				if(g_fmpt_cntx.callback)
					g_fmpt_cntx.callback->alert_notify_cb(bd_addr->addr, value->value[offset]);
			}
			return;
		}
		pConnNode = (FmptConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void fmpt_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_service_started_callback status %d, srvc_handle %d!\n", 
		             status, srvc_handle);
	if(status == OS_STATUS_SUCCESS)
	{
		srv_gatts_listen(reg_ctx, TRUE);
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
					#ifndef FMPT_UT
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#ifndef FMPT_UT
/* under construction !*/
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#ifndef FMPT_UT
/* under construction !*/
/* under construction !*/
				#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void fmpt_add_services_callback(OS_STATUS status, void *reg_ctx)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_fmpt_cntx.srv_list.srvlist);

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_add_services_callback status %d, state %d, op_flag %d!\n", 
		             status, g_fmpt_cntx.state, g_fmpt_cntx.op_flag);
	if(g_fmpt_cntx.reg_ctx == reg_ctx)
	{
		if(g_fmpt_cntx.state == FMP_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				if(g_fmpt_cntx.op_flag == FMPT_OP_ADD_SERVICE)
				{
					if(mmi_IsListEmpty(&g_fmpt_cntx.srv_list.srvlist))
					{
						kal_prompt_trace(MOD_BT, "[FMPT] is empty service list!\n");
						return;
					}
					while((ListEntry *)svc_list != &g_fmpt_cntx.srv_list.srvlist)
					{
						if(svc_list->type == TYPE_SERVICE)
						{
							#ifndef FMPT_UT
							srv_gatts_start_service(reg_ctx, svc_list->handle, GATT_TRANSPORT_LE);
							#endif
						}
						svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
					}
					g_fmpt_cntx.state = FMP_STATUS_ENABLED;
				}
			}
			else
			{
				fmpt_deinit();
			}
		}	
		
	}
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_add_services_callback -!\n");
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
					#ifndef FMPT_UT
/* under construction !*/
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#ifndef FMPT_UT
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#ifndef FMPT_UT
/* under construction !*/
/* under construction !*/
				#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

BtStatus fmpt_init(fmpt_callback_t *cb)
{
	BtStatus status = BT_STATUS_SUCCESS;

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_init state %d, op_flag %d!\n", 
		             g_fmpt_cntx.state, g_fmpt_cntx.op_flag);
	if(g_fmpt_cntx.state == FMP_STATUS_DISABLED)
	{
		g_fmpt_cntx.state = FMP_STATUS_ENABLING;
		g_fmpt_cntx.op_flag = FMPT_OP_INIT;
		g_fmpt_cntx.callback = cb;
		memcpy(g_fmpt_cntx.uid.uu, &g_fmpt_uid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_fmpt_cntx.conn_list);
		#ifndef FMPT_UT
		srv_gatts_profile_factory_register(&g_fmpt_cntx.uid, &g_fmpt_cb, &g_fmpt_factory_cb);
		#endif
        
        #ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
        mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, fmpt_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
        #endif
	}
	else if(g_fmpt_cntx.state == FMP_STATUS_DISABLING)
	{
		if(g_fmpt_cntx.op_flag == FMPT_OP_DEINIT)
		{
			g_fmpt_cntx.op_flag = FMPT_OP_INIT;
		}
		g_fmpt_cntx.callback = cb;
		memcpy(g_fmpt_cntx.uid.uu, &g_fmpt_uid, sizeof(bt_uuid_struct));
	}
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_init -!\n");
	return status;
}

BtStatus fmpt_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	FmptConnCntx    *pConnCur = (FmptConnCntx *)mmi_GetHeadList(&g_fmpt_cntx.conn_list);
	FmptConnCntx    *pConnNext = NULL;

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_deinit state %d, op_flag %d!\n", 
		             g_fmpt_cntx.state, g_fmpt_cntx.op_flag);
	if((g_fmpt_cntx.state == FMP_STATUS_DISABLED)
		|| (g_fmpt_cntx.state == FMP_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;

	if(g_fmpt_cntx.state == FMP_STATUS_ENABLED)
	{
		if(mmi_IsListEmpty(&g_fmpt_cntx.conn_list))
		{
			kal_prompt_trace(MOD_BT, "[FMPT] is empty connection list!\n");
			goto do_deinit;
		}
		
        while ((ListEntry *)pConnCur != &g_fmpt_cntx.conn_list)
		{
			pConnNext = (FmptConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_fmpt_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if((pConnCur->conn_status == FMP_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == FMP_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				#ifndef FMPT_UT
				//srv_gatts_disconnect(&gatt_conn, &bd_addr);
				#endif
			}
			mmi_RemoveEntryList(&pConnCur->conn_node);
			free_ctrl_buffer(pConnCur);
			pConnCur = pConnNext;
		}
	}
	
do_deinit:
	#ifndef FMPT_UT
	srv_gatts_profile_factory_delete_services(g_fmpt_cntx.reg_ctx, &g_fmpt_cntx.srv_list);
	srv_gatts_profile_factory_clear_services(g_fmpt_cntx.reg_ctx, &g_fmpt_cntx.srv_list);
	srv_gatts_profile_factory_deregister(g_fmpt_cntx.reg_ctx);
	#endif
    
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
    mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, fmpt_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
#endif

	g_fmpt_cntx.state = FMP_STATUS_DISABLED;
	g_fmpt_cntx.op_flag = FMPT_OP_DEINIT;
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_deinit -!\n");
	return BT_STATUS_SUCCESS;
}

U32 fmpt_send_data(void* buf, U32 len)
{
#ifdef MMI_BLE_IAS_ALERT_STATUS_CHAR
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_fmpt_cntx.srv_list.srvlist);
    FmptConnCntx        *pConnNode = (FmptConnCntx *)mmi_GetHeadList(&g_fmpt_cntx.conn_list);
    FmptConnCntx        *pConnNext = NULL;
    gatt_conn_struct    gatt_conn;
    ATT_VALUE           *att_value = NULL;
    ATT_UUID            svc_uuid;
    ATT_UUID            chr_uuid;
    int                 type = 0;
    U16                 svc_uuid16 = 0;
    U16                 chr_uuid16 = 0;
    U32                 send_size = 0; 
    
	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_send_data ==> \n");

    if(buf == NULL)
    {
        return send_size;
    }
       
    if(!mmi_IsListEmpty(&g_fmpt_cntx.conn_list))
    {
        while ((ListEntry *)pConnNode != &g_fmpt_cntx.conn_list)
        {
            pConnNext = (FmptConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            
            if(pConnNode->conn_status == FMP_STATUS_CONNECTED) //CONNECTED
            {
                gatt_conn.reg_ctx = g_fmpt_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while((ListEntry *)svc_list != &g_fmpt_cntx.srv_list.srvlist)
                {          
                    if(svc_list->type == TYPE_CHARACTERISTIC)
                    {
                        type = fmpt_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid);   
                        if(type != TYPE_CHARACTERISTIC)
                        {
                            break;                          
                        }
                         
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
                        
                        kal_prompt_trace(MOD_BT, "[FMPT] fmpt_send_data, svc_uuid16:0x%x, chr_uuid16:0x%x \n", svc_uuid16, chr_uuid16);
                        
                        if (chr_uuid16 == ALERT_STATUS_CHAR_UUID)
                        {  
                            send_size = len;
                            if(len > FMPT_MAX_VALUE_LEN)
                            {
                                len = FMPT_MAX_VALUE_LEN;
                            }
                             
                            att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
                            memcpy(att_value->value, buf, len);
                            att_value->len = len;
                            srv_gatts_send_indication(&gatt_conn, svc_list->handle, FALSE, att_value);
                            free_ctrl_buffer(att_value);
                            att_value = NULL;
                            break;
                        }
                    }
                    
                    svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
                }
            }
            
            pConnNode = pConnNext;
        }
    }
    
    kal_prompt_trace(MOD_BT, "[FMPT] fmpt_send_data <==, send_size:%d \n", send_size);
    
    return  send_size;
#else //MMI_BLE_IAS_ALERT_STATUS_CHAR
    return  0;
#endif //MMI_BLE_IAS_ALERT_STATUS_CHAR
}

#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
BtStatus fmpt_disconnect(char *bdaddr)
{
	FmptConnCntx    *pConnCur = (FmptConnCntx *)mmi_GetHeadList(&g_fmpt_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;

	kal_prompt_trace(MOD_BT, "[FMPT] fmpt_disconnect !\n");
	if(g_fmpt_cntx.state == FMP_STATUS_DISABLED
		|| g_fmpt_cntx.state == FMP_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_fmpt_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			kal_prompt_trace(MOD_BT, "[FMPT] find in list conn_status %d !\n", pConnCur->conn_status);
			gatt_conn.reg_ctx = g_fmpt_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == FMP_STATUS_CONNECTED
				|| pConnCur->conn_status == FMP_STATUS_CONNECTING)
			{
				pConnCur->conn_status = FMP_STATUS_DISCONNECTING;
				//pConnCur->flag = FMPL_OP_IDLE;
				srv_gatts_disconnect(&gatt_conn, &bd_addr);
				if(g_fmpt_cntx.callback != NULL)
					g_fmpt_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			else if(pConnCur->conn_status == FMP_STATUS_DISCONNECTED)
			{
				if(g_fmpt_cntx.callback != NULL)
					g_fmpt_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_SUCCESS;
			}
			else
			{
				if(g_fmpt_cntx.callback != NULL)
					g_fmpt_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			break;
		}
		pConnCur = (FmptConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

void fmpt_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((U8 *)&dst->addr[0], (U8 *)&src->lap, 3);
    dst->addr[3] = src->uap;
    memcpy((U8 *)&dst->addr[4], (U8 *)&src->nap, 2);
}

mmi_ret fmpt_handle_cm_disconnect(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_le_cm_evt_disconnect_struct *evt = (srv_le_cm_evt_disconnect_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt)
    {
        BD_ADDR remote_addr;
        
		fmpt_get_bd_addr(&remote_addr, evt->dev_addr);
        fmpt_disconnect(remote_addr.addr);
    }
    
    return MMI_RET_OK;
}
#endif

#else //MMI_SRV_BT_FMPT_PROFILE

BtStatus fmpt_init(fmpt_callback_t *cb)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}


BtStatus fmpt_deinit()
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

#endif //MMI_SRV_BT_FMPT_PROFILE
#endif //__BT_GATTS_PROFILE__

