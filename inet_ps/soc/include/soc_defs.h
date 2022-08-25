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

/*******************************************************************************
 * Filename:
 * ---------
 * soc_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constants and macros for Socket.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_DEFS_H
#define _SOC_DEFS_H

#include "soc_feature.h"
#include "kal_public_api.h"
#include "soc_consts.h"
#include "soc_trc.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"


#ifdef __MTK_INTERNAL__
/* under construction !*/
#else /* !__MTK_INTERNAL__ */
#define SOC_ASSERT(x)
#endif /* !__MTK_INTERNAL__ */

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif /* !min */

#define SOC_CNTX(X)  (socket_cntx.X)

#define DNS_MAX_DUP_QUERY (8)

#ifndef __SOC_25_SOCKETS_SUPPPORT__ //xxd
#define MAX_MOD_SOCKETS     (12)    /* max allowed sockets for each module */
#else
#define MAX_MOD_SOCKETS     (25)
#endif

#ifdef __APP_SECONDARY_PDP_SUPPORT__

#ifdef __WIFI_SUPPORT__
#define MAX_SOC_ACCOUNT_NUM         (8)
#else /* !__WIFI_SUPPORT__ */
#define MAX_SOC_ACCOUNT_NUM         (4)
#endif /* !__WIFI_SUPPORT__ */

#else /* !__APP_SECONDARY_PDP_SUPPORT__ */
#ifdef __WIFI_SUPPORT__
#define MAX_SOC_ACCOUNT_NUM         (4)
#else /* !__WIFI_SUPPORT__ */
	#ifdef __CUST_SOC_ABM__
		#define MAX_SOC_ACCOUNT_NUM         (4)
	#else
		#define MAX_SOC_ACCOUNT_NUM         (2)
	#endif
#endif /* !__WIFI_SUPPORT__ */
#endif /* !__APP_SECONDARY_PDP_SUPPORT__ */
#define LOOPBACK_MTU_SIZE   (1460)

/* Each AP has a slot instead of depending on the module id */
/* WAP(7 APs)/Email/PoC/SIP(2 APs)/VoIP/DHCP/TFTP/RTSP */
//#define MAX_SOC_APP                 (16)

#define MAX_UL_IP_FRAGMENT          (4)
#define IP_HDR_SIZE                 (20)
#define UDP_IP_HDR_SIZE             (28)
#define UDP_HDR_SIZE                (8)
//#define TCP_IP_HDR_SIZE             (40)
#define TCP_IP_HDR_SIZE             (52)
#define MAX_SOCKET_DGRM_SIZE        (1500 - UDP_IP_HDR_SIZE)      /* 1500 - 28 (udp+ip hdr) */
#define MAX_SOCKET_STREAM_SIZE      (1500 - TCP_IP_HDR_SIZE)      /* 1500 - 40 (tcp+ip hdr) */
#define MAX_SOC_TIMER_ITEM          (MAX_SOCKET_NUM + 1)
#define SOC_SMS_RCV_QUEUE_SIZE      (2)
#define SOC_SMS_PARTIAL_QUEUE_SIZE  (4)     /* need <= 9 */
#define SOC_SMS_MAX_SEG             (12)

#define SOC_INVALID_APP_ID          (0)
#define SOC_INVALID_MOD_ID          (MOD_NIL)   /* 0 */
#define SOC_DEFAULT_QOS_PROFILE     (0)
#define SOC_ALL_QOS_PROFILE         (0xff)
#define SOC_UNKNOWN_BEARER_CTX      (0xff)
#define SOC_EMPTY_BEARER_CTX        (0)
#define SOC_QOS_ACCT_DIFF           (1)

#define SOC_AUTO_DEACT_TIMER_VAL    (1)

#define SOC_SOCKET_PTR(_s_)         (&SOC_CNTX(socket_pool.slots[_s_]))
#define SOC_ACC_PTR(a)              (&SOC_CNTX(account_pool[a]))
#define SOC_SEL_PTR(s)              (SOC_SOCKET_PTR(s)->so_proc->so_sel)
#define SOC_PROC_PTR(s)             (SOC_SOCKET_PTR(s)->so_proc)
#define SOC_IP_Q_PTR(q)             ((peer_buff_struct*)(q))
#define SOC_SMS_Q_PTR(q)            ((soc_sms_q_struct*)(q))
#define SOC_SMS_PQ_PTR(so,idx)      (SOC_SMS_Q_PTR(so->so_rcv)->pq[idx])
#define IS_SOC_RECV_QUEUE_EMPTY(sp) (((sp)->so_type==SOC_SOCK_SMS) ? (lcd_cqueue_is_empty(SOC_SMS_Q_PTR((sp)->so_rcv)->q)) : ((sp)->so_rcv == NULL) )
#define IS_SOCKET_INUSE(s)          (SOC_SOCKET_PTR(s)->so_state & SOC_S_INUSE)
#define IS_SOCKET_ATTACHED(s)       (SOC_SOCKET_PTR(s)->so_state & SOC_S_ATTACHED)
#define IS_SOCKET_VALID(s)          (IS_SOCKET_INUSE(s) && IS_SOCKET_ATTACHED(s))
#define soc_drop_mbuf(m)            do { m = mfree(m, 0); } while (m)

/* ICMP staff */
#define SOC_ECHO_REQ                (8)
#define MIN_ICMP_HDR_SIZE           (4)
#define ECHO_REQ_HDR_SIZE           (8)

#ifdef SOC_WAIT_FUNC
#define SOC_WAIT_EVENT(s_, evt_) soc_wait_event(s_, evt_)
#define SOC_WAKEUP_EVENT(s_, evt_) soc_wakeup_event(s_, evt_)
#else /* !SOC_WAIT_FUNC */ 
#define SOC_WAIT_EVENT(s_, evt_) do {                            \
    kal_uint32 retrieved_events;                                 \
    soc_app_proc_struct *so_proc;                                \
    so_proc = SOC_PROC_PTR((s_));                                \
    so_proc->so_id = (s_);                            \
    so_proc->so_wait = (evt_);                        \
    SOCKET_GLOBAL_UNLOCK;/* SOCKET_UNLOCK((s_)); */              \
    kal_lib_trace(TRACE_SOC_EVENT, SOC_EVENT_SOC_WAIT_EVENT, (evt_), (s_)); \
    SOC_DEADLOCK_CHECK;                                          \
    kal_retrieve_eg_events(so_proc->so_event, (evt_), \
        KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);         \
        kal_lib_trace(TRACE_SOC_EVENT, SOC_EVENT_SOC_RECV_EVENT, (evt_), (s_)); \
        SOCKET_GLOBAL_LOCK;/* SOCKET_LOCK((s_)); */              \
    } while(0)

#define SOC_WAKEUP_EVENT(s_, evt_) do {                          \
    soc_app_proc_struct *so_proc;                                \
    so_proc = SOC_PROC_PTR((s_));                                \
    kal_set_eg_events(so_proc->so_event, (evt_), KAL_OR);        \
    so_proc->so_id = -1;                          \
    so_proc->so_wait = SOC_EVT_NOWAIT;            \
    } while(0)

#endif /* !SOC_WAIT_FUNC */ 

#ifdef __APP_SECONDARY_PDP_SUPPORT__
#define MAX_SHIFT (7)
#define SOC_SET_PDP_CTX_SOCKET(i, s)    \
    socket_cntx.pdp_context_pool[(i)].sockets[(s) / 8] |= (0x1 << (MAX_SHIFT - ((s) % 8)))

#define SOC_CLR_PDP_CTX_SOCKET(i, s)    \
    socket_cntx.pdp_context_pool[(i)].sockets[(s) / 8] &= ~(0x1 << (MAX_SHIFT - ((s) % 8)))

#define SOC_ISSET_PDP_CTX_SOCKET(i, s)  \
    socket_cntx.pdp_context_pool[(i)].sockets[(s) / 8] & (0x1 << (MAX_SHIFT - ((s) % 8)))
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */


#ifndef __MTK_TARGET__
#define SOCDBG_(x) x
#else /* __MTK_TARGET__ */
#define SOCDBG_(x)
#endif /* __MTK_TARGET__ */ 

#ifdef SOC_UT
#define SOC_print kal_printf
#endif /* SOC_UT */

/* SSPDU/SRPDU */
#define SSPDU_INIT_SIZE             (1536)
// #define SSPDU_GROW_LIMIT         (2)     /* allow to grow twice */
#define SSPDU_GROW_LIMIT            (100)   /* unlimited */
#define SSPDU_GROW_PKT_NUM          (3)

/* Timer Timeout Value */
#define SOC_NWK_CONGESTED_TIMEOUT_VAL (KAL_TICKS_1_SEC)
#define SOC_DELAY_CLOSE_TIMEOUT_VAL (KAL_TICKS_5_SEC)
#define SOC_DNS_TIMEOUT_VAL         (KAL_TICKS_1_SEC * 2)       /* 2 sec */
#ifdef SOC_UT
#define SOC_CONC_TIMEOUT_VAL        (KAL_TICKS_1_SEC * 20)      /* 20 sec */
#else /* !SOC_UT */
#define SOC_CONC_TIMEOUT_VAL        (KAL_TICKS_1_MIN * 5)       /* 5 min */
#endif /* !SOC_UT */

/*
 * Maximum queue length specifiable by listen.
 */
#define  SOC_SOMAXCONN     (5)

// #define      SOC_HDR_SIZE     (sizeof(struct mbuf)+28) /* mbuf + UDP + IP */
#define  SOC_TAIL_SIZE (0)

#if 1   /* use only one lock to protect socket global data */

#define SOCKET_GLOBAL_LOCK   kal_take_mutex(SOC_CNTX(lock))
#define SOCKET_GLOBAL_UNLOCK kal_give_mutex(SOC_CNTX(lock))

#else /* 0 */ 
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
#endif /* 0 */ 

#ifdef SOC_UT
extern kal_int8 soc_send_error;

#define SOC_DEADLOCK_CHECK                      \
    do {                                        \
        kal_uint32 my_index;                    \
        kal_get_my_task_index(&my_index);       \
        if(SOC_CNTX(soc_index) == my_index)     \
            SOC_print("there is a deadlock!!"); \
    } while(0);
#define SOC_UT_SIMULATE_SEND_ERROR if(soc_send_error) return soc_send_error
#else /* !SOC_UT */ 
#define SOC_DEADLOCK_CHECK      /* empty */
#define SOC_UT_SIMULATE_SEND_ERROR      /* empty */
#endif /* !SOC_UT */ 

#define SOC_ATOMIC(so_type) ((so_type == SOC_SOCK_STREAM) ? 0 : 1)

#define SOC_TIMER(X) SOC_CNTX(soc_timer.X)

#ifdef SUPPORT_OTA_PROC_IN_SOC
#define SOC_PUSH_PORT         (2948)
#define SOC_WAP_OTA_PUSH_PORT     (49999)
#define SOC_SYNCML_OTA_PORT   (49996) 
#endif /* SUPPORT_OTA_PROC_IN_SOC */ 

#endif /* !_SOC_DEFS_H */

