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
 *   bcm_spp_app.h
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

typedef struct
{
	SppHandle handle;
	kal_int32 conn_id;
	kal_uint8 buf[SRV_SPP_MIN_BUFF_SIZE];
	kal_int32 is_connected;
}bcm_app_spp_cntx;



typedef  void (*srv_bt_cm_spp_callback)(srv_bt_cm_connection_type conn_type,kal_bool result,kal_bool is_connect);

typedef struct{
	SppHandle handle;
	kal_int32 conn_id;
	kal_uint8 recv_buf[SRV_SPP_MIN_BUFF_SIZE];
	kal_int32 is_connected;	
	kal_int32 is_connect_req_sent;
	srv_bt_cm_bt_addr bt_addr;	
	srv_bt_cm_spp_callback cm_callback;
	kal_bool is_initted;	
}bcm_app_spp_client_cntxt;

extern bcm_app_spp_cntx *g_bcm_spp_cntx_p;
extern bcm_app_spp_client_cntxt* g_bcm_spp_client_cntx;

void bcm_app_spp_server_init(void);

kal_int32 bcm_app_spp_event_handler(kal_uint32 evt, void* para);

void bcm_app_spp_authorize_rsp(srv_bt_cm_bt_addr bt_addr, U32 profile_id, kal_bool result);

void bcm_app_sppc_init(void);

kal_int32 bcm_sppc_notify_hdlr(kal_uint32 evt, void* para);


void bcm_app_spp_connect(srv_bt_cm_bt_addr bt_addr);

void bcm_app_spp_init(void);
#endif

#endif
