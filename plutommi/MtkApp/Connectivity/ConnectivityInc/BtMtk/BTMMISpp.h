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
 * btmmispp.h
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
#ifndef __BT_MMI_SPP_H__
#define __BT_MMI_SPP_H__


#include "MMI_features.h"
#ifdef __MMI_SPP_SUPPORT__

//#define __MMI_BT_SPP_CLIENT_SUPPORT__

#include "MMIDataType.h"
#include "SppSrvGprot.h"
#include "fs_gprot.h"
#if defined(__MMI_BT_SPP_CLIENT_SUPPORT__) || defined(__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__)
#include "BTMMISppGprots.h"
#endif

#include "MMI_conn_app_trc.h"
#define MMI_BT_SPP_TRACE_GROUP           MMI_CONN_TRC_G7_BT


#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
#define MMI_ENNABLE_SRV_NUM  BT_MAX_LINK_NUM 
#endif

typedef struct
{
	SppHandle handle;
	S32 conn_id;
	U8 buf[SRV_SPP_MIN_BUFF_SIZE];
	S32 is_connected;
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
	srv_bt_cm_spps_callback cm_callback;
#endif
}mmi_bt_spp_cntx;


extern void mmi_bt_spp_init(void);
extern void mmi_bt_spp_server_init(void);
extern S32 mmi_bt_spp_event_handler(U32 evt, void* para);
#ifndef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
extern void mmi_bt_spp_bind_handler(void);
#else
extern void mmi_bt_spp_bind_handler(srv_spp_event_cntx* para);
mmi_bt_spp_cntx *mmi_bt_spp_get_cntx_by_handle(SppHandle handle);
extern MMI_BOOL mmi_bt_spps_is_profie_connected_ex(srv_bt_cm_bt_addr* dev_addr);
#endif
extern void mmi_bt_spp_authorize_ind(srv_spp_event_cntx* para);
extern void mmi_bt_spp_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 profile_id, U32 result);
extern void mmi_bt_spp_connect_ind(srv_spp_event_cntx* para);
extern void mmi_bt_spp_disconnect(srv_spp_event_cntx* para);
extern void mmi_bt_authorize_ind_notify(U8* dev_name,
                                 srv_bt_cm_bt_addr *dev_addr,
                                 U32 profile_id,
                                 void *callback);
extern void  mmi_bt_authorize_screen_close(U32 profile_id);

extern S8 *GetString(U16 StringId);

#ifdef __MMI_BT_SPP_TEST__
void mmi_bt_spp_test();
typedef struct{
	FS_HANDLE fs_handle;
	U8 buf[2048];
}spp_rev_cntx;
#endif/*__MMI_BT_SPP_TEST__*/

#ifdef __MMI_BT_SPP_CLIENT_SUPPORT__

//typedef  void (*srv_bt_cm_spp_callback)(srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect);
typedef  void (*srv_bt_cm_spp_callback)(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);

typedef struct{
	SppHandle handle;
	S32 conn_id;
	U8 recv_buf[SRV_SPP_MIN_BUFF_SIZE];
	S32 is_connected;	
	S32 is_connect_req_sent;
	srv_bt_cm_bt_addr bt_addr;	
	srv_bt_cm_spp_callback cm_callback;
}mmi_spp_client_cntxt;



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
#endif


void mmi_bt_sppc_init();
void mmi_bt_sppc_handle_disconnect_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_sppc_handle_connect_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_sppc_handle_ready_to_write_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_sppc_handle_ready_to_read_ind(srv_spp_event_cntx* notify_para);

S32 mmi_bt_sppc_notify_hdlr(U32 evt, void* para);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#endif /*__MMI_BT_SPP_CLIENT_SUPPORT__*/

#endif/*__MMI_SPP_SUPPORT__*/

#endif/*__BT_MMI_SPP_H__*/


