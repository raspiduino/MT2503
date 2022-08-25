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
 * SppSrv.h
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
#ifndef __SRV_SPP_H__
#define __SRV_SPP_H__

#ifdef __BT_SPP_PROFILE__

#include "kal_general_types.h"

#include "Bcm_btcmSrvGprot.h"
#include "BcmSppSrvGprot.h"
#include "Bcm_btcmSrvProt.h"

#include "Bluetooth_struct.h"
#include "bt_common_config.h"
#include "dcl.h"

/***************************************************************************** 
 * define
 *****************************************************************************/
//bt spp instance number
//currently only 1 server is support.
#define SRV_SPP_MAX_SERVER_INSTANCE 2
#define SRV_SPP_MAX_CLIENT_INSTANCE 1
#define SRV_SPP_MAX_INSTANCE (SRV_SPP_MAX_SERVER_INSTANCE + SRV_SPP_MAX_CLIENT_INSTANCE)

//bt spp port number
#if defined (__MMI_HFP_SUPPORT__) || defined(__MMI_HSP_SUPPORT__) 
#define MMI_NUM_HFG_PORT 1
#else
#define MMI_NUM_HFG_PORT 0
#endif

#ifdef __MMI_DUN_SUPPORT__
#define MMI_NUM_DUN_PORT 1
#else
#define MMI_NUM_DUN_PORT 0
#endif

#ifdef __MMI_FAX_SUPPORT__
#define MMI_NUM_FAX_PORT 1
#else
#define MMI_NUM_FAX_PORT 0
#endif

#define SRV_SPP_MAX_CONNECT_NUM (BT_SPP_VIRTUAL_PORTS_NUM - MMI_NUM_HFG_PORT - MMI_NUM_DUN_PORT - MMI_NUM_FAX_PORT + 1)

#define __MMI_SRV_SPP_DEBUG__
#ifdef __MMI_SRV_SPP_DEBUG__
#define SRV_SPP_LOG(trc) MMI_TRACE(MMI_CONN_TRC_G7_BT, trc);
#define SRV_SPP_LOG1(trc, x1) MMI_TRACE(MMI_CONN_TRC_G7_BT, trc, x1);
#define SRV_SPP_LOG2(trc, x1, x2) MMI_TRACE(MMI_CONN_TRC_G7_BT, trc, x1, x2);
#define SRV_SPP_LOG3(trc, x1, x2, x3) MMI_TRACE(MMI_CONN_TRC_G7_BT, trc, x1, x2, x3);
#define SRV_SPP_LOG4(trc, x1, x2, x3, x4) MMI_TRACE(MMI_CONN_TRC_G7_BT, trc, x1, x2, x3, x4);
#define SRV_SPP_LOG_DISPLAY_CNTX() srv_spp_debug_display_cntx()
#define SRV_SPP_LOG_DISPLAY_UUID(uuid) srv_spp_debug_display_uuid(uuid)
#else
#define SRV_SPP_LOG(trc)
#define SRV_SPP_LOG1(trc, x1)
#define SRV_SPP_LOG2(trc, x1, x2)
#define SRV_SPP_LOG3(trc, x1, x2, x3)
#define SRV_SPP_LOG4(trc, x1, x2, x3, x4)
#define SRV_SPP_LOG_DISPLAY_CNTX()
#define SRV_SPP_LOG_DISPLAY_UUID(uuid)
#endif

/***************************************************************************** 
 * enum
 *****************************************************************************/
typedef enum{
    SRV_SPP_CONN_STATE_IDLE,
    SRV_SPP_CONN_STATE_ACTIVATE,//for server
    SRV_SPP_CONN_STATE_AUTHORIZING,//just for server
    SRV_SPP_CONN_STATE_CONNECTED,
    SRV_SPP_CONN_STATE_DISCONNECTING,
    SRV_SPP_CONN_STATE_DEACTIVATING
}srv_spp_connect_state;

typedef enum{
    SRV_SPP_ACTIVATE_FAIL,
    SRV_SPP_ACTIVATE_SUCCESS
}srv_spp_activate_result;

typedef enum{
    //0x00000001,0x00000002 for conn type in gport.h
    //mark a instance for server
    SRV_SPP_FLAG_ROLE_SERVER = 0x00000004,
    //mark a instance for client
    SRV_SPP_FLAG_ROLE_CLIENT = 0x00000008,
    //mark a instance that will be closed
    SRV_SPP_FLAG_CLOSE_INSTANCE = 0x00000010,
    //mark a connect is disconnect from cm, just using in native app.
    SRV_SPP_FLAG_DISCONNECT_FROM_CM = 0x00000020,
}srv_spp_flag;

/***************************************************************************** 
 * Structure
 ****************************************************************************/
typedef struct
{
    U16 evt_id;
    U16 size;
    void *user_data;
    srv_spp_event_cntx spp_notify;	
}srv_spp_event_struct;


typedef struct srv_spp_conn_cntx{
    S32 conn_id;
    DCL_DEV port;
    srv_bt_cm_bt_addr bt_addr;
    srv_spp_connect_state conn_state;
    struct srv_spp_conn_cntx* next;
}srv_spp_conn_cntx;

typedef struct{	
    srv_spp_conn_cntx* connect;
    SppSecurityLevel sec_level;
    CHAR srv_name[SRV_SPP_SERVICE_NAME_LENGTH*3 + 1];
}srv_spp_cntx;

typedef struct srv_spp_instance{
    U32 req_id;
	U8  uuid[16];
    SppHandle handle;
    U32 event_mask;
    btSppNotify notifier;
    srv_spp_cntx cntx;
    void* user_data;
    U32 flag;
    struct srv_spp_instance* next;
}srv_spp_instance;

#define SRV_SPP_FLAG_INIT(x) do{(x)->flag = 0x00000000;}while(0)
#define SRV_SPP_FLAG_SET_ALL(x) do{(x)->flag = 0xffffffff;}while(0)
#define SRV_SPP_SET_FLAG(x, f) do{(x)->flag |= f; }while(0)
#define SRV_SPP_CLEAR_FLAG(x, f) do{(x)->flag &= ~f;}while(0)
#define SRV_SPP_FLAG_IS_SET(x, f) (((x)->flag & f)? 1 : 0)

/****************************************************************************
 * Function declare
 ****************************************************************************/
//for init
void srv_spp_init_cntx(void);
void srv_spp_init_event_hdler(void);
//for cm
void srv_spp_default_activate(void);
void srv_spp_default_deactivate(void);
void srv_spp_disconnect_from_cm(S32 conn_id);

void srv_spp_port_activate_req(SppHandle handle);
U8 srv_spp_authorize_ind(void* msg);
void srv_spp_authorize_rsp(srv_spp_conn_cntx* conn, 
                            U8* buf,
                            U32 tx_size,
                            U32 rx_size,
                            MMI_BOOL ret
                            );
U8 srv_spp_connect_ind(void* msg);
U8 srv_spp_connect_cnf(void * msg);
U8 srv_spp_port_activate_cnf(void* msg);
U8 srv_spp_uart_ready_to_read_ind(void* msg);
U8 srv_spp_uart_ready_to_write_ind(void * msg);
U8 srv_spp_uart_plugout_ind(void* msg);
U8 srv_spp_disconnect_ind(void * msg);
void srv_spp_port_deactivate_req(DCL_DEV port);
U8 srv_spp_port_deactivate_cnf();
void srv_spp_notify_app(srv_spp_instance* inst, U32 evt_id, void* para, MMI_BOOL is_post);
mmi_ret srv_spp_post_notify_proc(mmi_event_struct* evt);
srv_spp_instance* srv_spp_create_inst();
void srv_spp_destroy_inst(srv_spp_instance* inst);
srv_spp_conn_cntx* srv_spp_create_conn(srv_spp_instance* inst);
void srv_spp_destroy_conn(srv_spp_instance* inst, DCL_DEV port);
srv_spp_instance* srv_spp_get_inst_by_handle(SppHandle handle);
srv_spp_instance* srv_spp_get_inst_by_req_id(U32 req_id);
srv_spp_instance* srv_spp_get_inst_by_port(DCL_DEV port);
srv_spp_conn_cntx* srv_spp_get_conn_by_port(DCL_DEV port);
srv_spp_instance* srv_spp_get_inst_by_conn_id(S32 conn_id);
srv_spp_conn_cntx* srv_spp_get_conn_by_conn_id(S32 conn_id);
void srv_spp_debug_display_cntx(void);
U8 srv_spp_uart_set_owner_ind(void* msg);
void srv_spp_uart_set_owner_cnf(DCL_DEV port);
void srv_spp_server_close(srv_spp_instance* inst);
void srv_spp_client_close(srv_spp_instance* inst);
void srv_spp_debug_display_uuid(U8* uuid);
void srv_spp_uuid_convert_16bit_to_128bit(U16 uuid_16bit, U8* uuid_128bit);
U16 srv_spp_uuid_convert_128bit_to_16bit(U8* uuid_128bit);
#endif/*__BT_SPP_PROFILE__*/

#endif/*SRV_SPP_H*/



