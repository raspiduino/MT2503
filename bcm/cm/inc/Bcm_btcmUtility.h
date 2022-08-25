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
 * BtcmSrvProt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the internal header file for BT CM
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
#ifndef BT_CM_UTILITY_H
#define BT_CM_UTILITY_H
// RHR: add
//#include "TimerEvents.h"
#include "kal_general_types.h"
// RHR: add

//#include "bluetooth_bm_struct.h"
#include "Bcm_btcmSrvGprot.h"
#include "bcmadp.h"
#include "nvram_data_items.h"
#include "kal_public_defs.h"
#include "comm_post_event.h"

/***************************************************************************** 
* Macro
*****************************************************************************/
#ifdef __BCM_SUPPORT__
typedef enum
{
    BCM_NO_TIMER_STATUS = 0,
    BCM_TIMER_RUNNING,
    BCM_TIMER_NOT_RUNNING,
    BCM_TIMER_STOPPED,
    BCM_TIMER_TIMED_OUT
} bcm_timer_status_enum;

typedef struct
{
    kal_uint8 timer_data[8];            /* Time Out Value */
    eventid event_id;   /* Event Id returned by 
                           EventSchedular when an 
                           event is set */
    kal_uint32 ref_ticks;               /* the ticks while the timer is set */
    kal_uint8 current_module;
    kal_uint8 dure;
    bcm_timer_status_enum timer_status; /* Timer Status */
} bcm_timer_info_struct;

#define __BCM_TRACE_ON__
#ifdef __BCM_TRACE_ON__
#define BCM_FUNC_ENTRY(...)    kal_brief_trace(TRACE_FUNC, __VA_ARGS__)        
#define BCM_STATE_ENTRY(...)  kal_brief_trace(TRACE_STATE, __VA_ARGS__)       
#define BCM_INFO_ENTRY(...)   kal_brief_trace(TRACE_INFO,  __VA_ARGS__)  
#define BCM_WARNING_ENTRY(...) kal_brief_trace(TRACE_WARNING, __VA_ARGS__)     
#define BCM_ERROR_ENTRY(...)      kal_brief_trace(TRACE_ERROR, __VA_ARGS__)       
#define BCM_TIMING_ENTRY(...) kal_trace(TRACE_GROUP_1, __VA_ARGS__)     
#define BCM_GROUP7_ENTRY(...)        kal_brief_trace(TRACE_GROUP_7, __VA_ARGS__)
#define POST_EVT_TRC(...)  kal_brief_trace(TRACE_GROUP_6, __VA_ARGS__)
#else /* __BCM_TRACE_ON__ */ 
#define BCM_FUNC_ENTRY(...)       
#define BCM_STATE_ENTRY(...)      
#define BCM_INFO_ENTRY(...)   
#define BCM_WARNING_ENTRY(...)    
#define BCM_ERROR_ENTRY(...)      
#define BCM_TIMING_ENTRY(...)     
#define BCM_GROUP7_ENTRY(...)
#define POST_EVT_TRC(...)
#endif /* __BCM_TRACE_ON__ */ 
extern void bcm_restart_timer(kal_uint16 timer_id,kal_uint32 dure,FuncPtr_void handler);
extern void bcm_restart_timerEx(kal_uint16 timer_id,kal_uint32 dure,FuncPtr_void handler,void* arg);
extern void bcm_stop_timer(kal_uint16 timer_id);
#endif /* __BCM_SUPPORT__ */

#endif /* BT_CM_UTILITY_H */
