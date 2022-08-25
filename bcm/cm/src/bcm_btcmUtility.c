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
 * BtcmSrvPrmt.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MTK bluetooth primitive handle with BT stack
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "Bcm_btcmSrvProt.h"
#include "Bcm_btcmSrvGprot.h"
#include "Bcm_btcmUtility.h"
#include "bcm_trc.h"
#include "bluetooth_bm_struct.h"


// #ifdef __DM_LAWMO_SUPPORT__
// #include "dmuigprot.h"
// #endif /*__DM_LAWMO_SUPPORT__*/

#include "conversions.h"
#include "bluetooth_struct.h"

// RHR: add
#include "app_ltlcom.h"
#include "l4c_common_enum.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
//#include "TimerEvents.h"
#include "kal_public_api.h"
// RHR: add

void bcm_stop_timer(kal_uint16 timer_id)
{
    ASSERT(timer_id < BCM_MAX_TIMER_NUM);
    if(BCM_PTR->timer_pool[timer_id].timer_status == BCM_TIMER_RUNNING && BCM_PTR->timer_pool[timer_id].event_id)
    {    
        BCM_INFO_ENTRY( GROUP1_BCM_STOP_TIMER_INFO,timer_id);
        evshed_cancel_event(BCM_PTR->event_scheduler_ptr, &(BCM_PTR->timer_pool[timer_id].event_id));
        BCM_PTR->timer_pool[timer_id].timer_status = BCM_TIMER_STOPPED;
        BCM_PTR->timer_pool[timer_id].event_id = 0;
    }    
}

void bcm_restart_timer(kal_uint16 timer_id,kal_uint32 dure,FuncPtr_void handler)
{
    ASSERT(handler);
    ASSERT(dure);
    ASSERT(timer_id < BCM_MAX_TIMER_NUM); 
    
    bcm_stop_timer(timer_id);    
    BCM_PTR->timer_pool[timer_id].dure = dure / 1000; // convert ms to sec
    BCM_PTR->timer_pool[timer_id].event_id = evshed_set_event(
                                BCM_PTR->event_scheduler_ptr,
                                (kal_timer_func_ptr)handler,
                                (void*)timer_id,
                                KAL_TICKS_1_SEC * (dure / 1000));
    BCM_PTR->timer_pool[timer_id].timer_status = BCM_TIMER_RUNNING;
    BCM_INFO_ENTRY(GROUP1_BCM_START_TIMER_INFO,timer_id,dure / 1000,handler);
}


void bcm_restart_timerEx(kal_uint16 timer_id,kal_uint32 dure,FuncPtr_void handler,void* arg)
{
    ASSERT(handler);
    ASSERT(dure);
    ASSERT(timer_id < BCM_MAX_TIMER_NUM); 
    
    bcm_stop_timer(timer_id);    
    BCM_PTR->timer_pool[timer_id].dure = dure / 1000; // convert ms to sec
    BCM_PTR->timer_pool[timer_id].event_id = evshed_set_event(
                                BCM_PTR->event_scheduler_ptr,
                                (kal_timer_func_ptr)handler,
                                (void*)arg,
                                KAL_TICKS_1_SEC * (dure / 1000));
    BCM_PTR->timer_pool[timer_id].timer_status = BCM_TIMER_RUNNING;
    BCM_INFO_ENTRY(GROUP1_BCM_START_TIMER_INFO,timer_id,dure / 1000,handler);
}

void bcm_timer_expiry_handler(ilm_struct *sim_ilm_ptr)
{
    BCM_FUNC_ENTRY(FUNC_BCM_TIMER_EXPIRY_HANDLER);
    /* Execute event's timeout handler */
    evshed_timer_handler(BCM_PTR->event_scheduler_ptr);
    
    return;
}   /* end of sim_timer_expiry_handler */


void bcm_send_ilm(
        module_type dest_id,
        kal_uint16 msg_id,
        void *local_param_ptr,
        void *peer_buf_ptr)
{
    ilm_struct *ilm_ptr = NULL;
    
 
    ilm_ptr = allocate_ilm(kal_get_active_module_id());
    
    ilm_ptr->src_mod_id = kal_get_active_module_id();
    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    ilm_ptr->dest_mod_id = dest_id;
//    ilm_ptr->sap_id = PS_SIM_SAP;
    msg_send_ext_queue(ilm_ptr);

}   /* End of sim_send_ilm */

#endif /* __BCM_SUPPORT__ */ 
