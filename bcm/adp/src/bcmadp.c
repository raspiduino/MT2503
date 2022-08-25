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
 *   bcm_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for bcm porting adapter layer.
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
 * 03 13 2017 hongjian.zhao
 * removed!
 * .
 *
 * 02 13 2017 hongjian.zhao
 * removed!
 *
 * 02 13 2017 hongjian.zhao
 * removed!
 *
 * 02 13 2017 hongjian.zhao
 * removed!
 *
 * 01 23 2017 hongjian.zhao
 * removed!
 * BLE porting to BCM module.
 *
 * 03 04 2015 xiaowei.wang
 * removed!
 * .
 *
 * 03 04 2015 xiaowei.wang
 * removed!
 * .
 *
 * 08 18 2014 hujin.hu
 * removed!
 * .
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line: this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_SUPPORT__

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
#ifdef __BT_SPP_PROFILE__
#include "BcmSppSrv.h"
#endif
#include "bcm_trc.h"
#include "Bcm_btcmUtility.h"
#include "bcmadp.h"

/******************************
* Timer Hander Adapter
*******************************/
extern void srv_bt_cm_set_temp_visibility_timeout(void);
extern void srv_bt_cm_release_all_conn_timeout_hdlr(void);
extern void srv_bt_cm_switch_off_timeout_hdlr(void);
extern void srv_bt_cm_set_limit_visibility_timeout_hdlr(void);
#ifdef __BT_A2DP_PROFILE__
extern void mmi_a2dp_delay_open_callback_hdlr();
extern void srv_a2dp_pause_stream_hdlr();
#endif

#ifdef __BT_AVRCP_PROFILE__
extern void srv_avrcp_auto_release_cmd(void *arg);
#endif

#ifdef __MMI_BLE_LOW_POWER__
void srv_gattc_conn_param_interval_reset(void);
void srv_gattc_conn_param_interval_reset_bcm_adp(void *data);
void srv_gattc_conn_param_update_req_retry_bcm_adp(void *data,void *arg);
#endif

void srv_bt_cm_set_temp_visibility_timeout_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;
    
    srv_bt_cm_set_temp_visibility_timeout();
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}

void srv_bt_cm_release_all_conn_timeout_hdlr_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;
    srv_bt_cm_release_all_conn_timeout_hdlr();
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}

void srv_bt_cm_switch_off_timeout_hdlr_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;
    srv_bt_cm_switch_off_timeout_hdlr();
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}
#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
void srv_bt_cm_set_limit_visibility_timeout_hdlr_bcm_adp(void *data)
{
    kal_uint8 *timer_id = (kal_uint8*) data;
    srv_bt_cm_set_limit_visibility_timeout_hdlr();
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}
#endif

#ifdef __BT_A2DP_PROFILE__
void mmi_a2dp_delay_open_callback_hdlr_bcm_adp(void *data)
{
	kal_uint8 *timer_id = (kal_uint8*) data;
    
    mmi_a2dp_delay_open_callback_hdlr();
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;

}
void srv_a2dp_pause_stream_hdlr_bcm_adp(void *data)
{
	kal_uint8 *timer_id = (kal_uint8*) data;
    
    srv_a2dp_pause_stream_hdlr();
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
    BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;

}
#endif

#ifdef __BT_AVRCP_PROFILE__
void srv_avrcp_auto_release_cmd_bcm_adp(void *data,void *arg)
{
	kal_uint8 *timer_id = (kal_uint8*) data;
		
	srv_avrcp_auto_release_cmd(arg);
	BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
	BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;

}
#endif

#ifdef __MMI_BLE_LOW_POWER__
void srv_gattc_conn_param_update_req_retry_bcm_adp(void *data,void *arg)
{
	kal_uint8 *timer_id = (kal_uint8*) data;
	
	srv_gattc_conn_param_update_req_retry(arg);
	BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
	BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}

void srv_gattc_conn_param_interval_reset_bcm_adp(void *data)
{
	kal_uint8 *timer_id = (kal_uint8*) data;
	
	srv_gattc_conn_param_interval_reset();
	BCM_PTR->timer_pool[(kal_uint32) (timer_id)].timer_status = BCM_TIMER_TIMED_OUT;
	BCM_PTR->timer_pool[(kal_uint32) (timer_id)].event_id = 0;
}

#endif

#include "custom_bcm_btcm_config.h"
#include "Bcm_btcmSrvGprot.h"
void mmi_bt_dialor_callback(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
}


#endif

