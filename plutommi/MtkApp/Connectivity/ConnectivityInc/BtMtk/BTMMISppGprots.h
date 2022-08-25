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
 * BTMMISppGprots.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module to use btmmihfg related apis
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #ifndef BT_MMI_SPP_GPROTS_H
#define BT_MMI_SPP_GPROTS_H
#if 0
#ifndef BT_MMI_SPP_GPROTS_H
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
#endif//end of BT_MMI_DUN_GPROTS_H
#endif

#ifdef __MMI_BT_SPP_CLIENT_SUPPORT__


typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;
	MMI_BOOL result;
	srv_bt_cm_bt_addr bt_addr;	
}mmi_sppc_connect_cnf_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;
}mmi_sppc_disconnect_cnf_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;		
}mmi_sppc_ready_to_read_ind_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;	
}mmi_sppc_ready_to_write_ind_struct;

extern S32 mmi_bt_sppc_send_data(S32 conn_id, char* send_buf, U32 len);
extern S32 mmi_bt_sppc_read_data(S32 conn_id, char* read_buf, U32 buf_len);
extern void mmi_bt_sppc_send_connect_req(srv_bt_cm_bt_addr *dev_addr);
extern void mmi_bt_sppc_send_disconnect_req(S32 conn_id);


#endif /*__MMI_BT_SPP_CLIENT_SUPPORT__*/
#ifdef __MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__
typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;
	MMI_BOOL result;
	//srv_bt_cm_bt_addr bt_addr;	
}mmi_spps_connect_ind_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;
}mmi_spps_disconnect_cnf_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;		
}mmi_spps_ready_to_read_ind_struct;

typedef struct{
    MMI_EVT_PARAM_HEADER
	S32 conn_id;	
	MMI_BOOL result;	
}mmi_spps_ready_to_write_ind_struct;


typedef  void (*srv_bt_cm_spps_callback)(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);

extern void mmi_bt_spps_send_disconnect_req_from_cm(srv_bt_cm_bt_addr *bt_addr, srv_bt_cm_spps_callback mmi_spp_cm_cb);
extern void mmi_bt_spps_handle_ready_to_write_ind(srv_spp_event_cntx* notify_para);
extern void mmi_bt_spps_handle_ready_to_read_ind(srv_spp_event_cntx* notify_para);
#endif /*__MMI_BT_SPP_SERVER_MULTILINK_SUPPORT__*/

#endif
