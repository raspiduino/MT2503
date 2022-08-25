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
 * soc_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains structures for Socket.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_STRUCT_H
#define _SOC_STRUCT_H

#include "soc_feature.h"
#include "soc_api.h"
#include "soc_dns.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "soc_enum.h"
#include "soc_defs.h"
#include "kal_public_defs.h"
#include "app_ltlcom.h"
#include "lcd_cqueue.h"
#include "soc_consts.h"
#include "app2soc_struct.h"
#include "kal_public_api.h"

#ifdef SOC_SUPPORT_SELECT
/* select info */
typedef struct
{
    soc_fd_set *in;
    soc_fd_set *out;
    soc_fd_set *ex;
    kal_uint8 ndesc;
    kal_bool is_timer_started;
    kal_bool is_timer_expired;
} soc_select_struct;
#endif /* SOC_SUPPORT_SELECT */ 

typedef struct
{
    module_type mod_id; /* store module id to notify */
    kal_uint8   ap_id;
} soc_app_id_struct;

typedef struct
{
    kal_int8 deact_so_id;
    kal_uint8  state;   /* refer to soc_account_state_enum, per app account state */
#ifdef __APP_SECONDARY_PDP_SUPPORT__
    kal_uint8  qos_profile_id;      /* qos profile id for realtime app */
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */
    kal_uint8  ps_ctx_id;           /* bearer context id for realtime app  */
    kal_uint32 account_id;      /* account id: ap id + account id */
    /* the account id used in auto deactivation 
     * Current design is to auto deactivate the bearer by default
     * when all sockets of the same bearer created by this AP are closed.
     */
    kal_uint32 auto_deact_acct_id;
    soc_ip_state_enum ip_state;     /* soc_ip_state_enum */
    kal_uint32  activate_account_id; /* the real activated account id */
    kal_bool is_force_deact;
    kal_bool deact_directly;   /* deactivate the bearer directly */
} soc_app_account_struct;

typedef struct
{
    kal_uint8 no_so;                                /* number of socket created by the application */
    kal_int8  so_id;

#ifdef __CBM_BEARER_SWITCH__
    kal_bool  delay_deact;
#endif
    soc_app_account_struct account[MAX_SOC_ACCOUNT_NUM]; /* application account */ 
    
    soc_app_id_struct app;
#ifdef SOC_SUPPORT_SELECT
    soc_select_struct *so_sel;  /* for select */
#endif /* SOC_SUPPORT_SELECT */    
    kal_uint32 so_wait; /* type of waiting event */
    /* 
     * Two purposes for using events
     * 1. wait confirm sent from TCP/IP
     * 2. support blocking-mode
     */
    kal_eventgrpid so_event;

} soc_app_proc_struct;


typedef struct
{
    peer_buff_struct **concat_q1;   /* queue for incomplete MT SMS */
    kal_uint16 concat_ref;
    kal_uint8 total_seg;
    kal_uint8 dcs;
    kal_uint8 sim_src;
} soc_sms_partial_q_struct;


typedef struct
{
    lcd_cqueue *q;  /* queue for completed MT SMS */
    soc_sms_partial_q_struct pq[SOC_SMS_PARTIAL_QUEUE_SIZE];    /* queue for incomplete MT SMS */
} soc_sms_q_struct;


typedef struct socket
{
    kal_uint8 so_id;          /* start from 0, 1, ... */
    socket_type_enum so_type; /* socket type, see soc_api.h */
    module_type mod_id;       /* store module id to notify */
#ifdef __SSL_SUPPORT__
    module_type notify_mod_id;  /* soc_set_module sets this module id,
                                 * send notify to this one if it is set */
#endif /* __SSL_SUPPORT__ */

    kal_uint8 protocol;       /* protocol for raw sockets */
    kal_uint8 so_qlimit;      /* max number TCP queued connections */
    kal_uint8 so_qlen;        /* current connection number in accepted queue */

    kal_int8 so_error;        /* error cause */
    kal_int8 last_error;      /* last error */
    kal_uint8 aysnc_event;    /* events expected to be notified */
#ifdef __APP_SECONDARY_PDP_SUPPORT__
    kal_uint8 qos_profile_id;      /* qos profile id for realtime app  */
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */

    kal_bool used_by_soc;     /* eg, dns query, etc */
    kal_bool is_acct_updated; /* check if the real account is updated to TCPIP or not */

    kal_uint8 flc_window;
    kal_uint16 linger_time; /* unit: sec */
    kal_uint16 rt_mtu; /* route MTU, UDP only */
#ifdef SOC_STAT
    kal_uint16 no_grow_attemp;
    kal_uint16 no_grow_fail;
    kal_uint16 no_get_fail;
#endif /* SOC_STAT */ 
    
    kal_uint32 account_id;   /* account id */
    kal_uint32 so_options;  /* soc_option_enum */
    kal_uint32 so_state;    /* soc_state_enum */
    kal_int32 detail_cause; /* detailed error cause depends on so_error */
 
    void *aux_info;
    soc_app_proc_struct *so_proc;
    struct socket *so_head; /* pointer to server socket */
    lcd_cqueue *so_comp;    /* for server socket to accommodate incoming tcp connections */
    sockaddr_struct *fsockaddr; /* foreign address */
    sockaddr_struct *lsockaddr; /* local address */
              
    /* Socket Receive Buffer */
    void *so_rcv;
    kal_uint32 data_rcvd;
    kal_uint32 data_freed;
} socket_struct;


typedef struct
{
    socket_struct slots[MAX_SOCKET_NUM];
    kal_uint8 num;
    kal_uint8 ip_soc_num;   /* non-SMS socket number */

    /*
     * avoid race condition, eg, SOC sends close_ind (so=0)to application(app)
     * * before app receives close_ind, application (app) close socket 0.
     * * app create a new socket, get the socket id 0, then app receive close_ind, 
     * * app closes socket 0
     */
    kal_int8 last_used_id;  /* counting non-SMS socket only */
} soc_socket_pool_struct;

/* 
 * connection statistics 
 */
typedef struct
{
    kal_uint32 last_access_time;    /* unit: ticks */
    kal_uint32 activated_time;      /* connection starting time, unit: ticks */
    kal_uint32 sent_bytes;
    kal_uint32 recv_bytes;
} soc_conn_stat_struct;


typedef struct
{
    kal_bool auto_disc_timer_running;
    kal_uint8 activated_account_id;
    soc_conn_stat_struct conn_stat; /* connection statistics */
} soc_csd_timer_struct;


#define PS_OCTETS        ((MAX_IP_SOCKET_NUM+7)/8)
#define MAX_DL_FILTERS   (8)

/* The mapping of (acct_id, qos_profile_id, ps_ctx_id) */
typedef struct
{
    kal_uint32              acct_id;
    kal_uint8               qos_profile_id;   /* return to application */

    kal_uint8               app_type;         /* applicatoin type for encode function */

    kal_uint8               sockets[PS_OCTETS];
    kal_uint16              bandwidth;
    kal_uint8               dl_filter_num;
    soc_dl_filter_struct    *dl_filters[MAX_DL_FILTERS];
} soc_app_qos_struct;


typedef struct
{
    event_scheduler *evt_scheduler;
} soc_timer_struct;


typedef struct
{
    kal_uint8 is_used;
    kal_uint8 timer_id;
    eventid event_id;
    kal_uint8 sub_id;
    kal_int32 invoke_id;
} soc_timer_info_struct;

typedef struct
{   
    kal_uint16 mtu;
    kal_uint8 account_flag; /* reference source for dns srv addr (dns_ref_enum) */
    kal_uint32 account_id;
    kal_uint8 local_ip[4];
    kal_uint8 dns_server[DNS_MAX_SERVER][DNS_ADDR_LEN]; /* 0: primary, 1: secondary */
    kal_bool auto_disc_timer_running;
    soc_conn_stat_struct conn_stat; /* connection statistics */
} soc_account_struct;

typedef struct
{
    kal_uint32  account_id;
    kal_uint16  auto_disc_gprs_sec;
} soc_auto_disc_gprs_struct;

typedef struct
{
    /* pools */
    soc_socket_pool_struct socket_pool;
    soc_account_struct account_pool[MAX_SOC_ACCOUNT_NUM];

#ifdef __APP_SECONDARY_PDP_SUPPORT__
    soc_app_qos_struct  pdp_context_pool[MAX_SOC_ACCOUNT_NUM];
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */

    soc_app_proc_struct app_pool[MAX_SOC_APP];

    /* timer */
    soc_timer_struct soc_timer;
    soc_timer_info_struct timer_pool[MAX_SOC_TIMER_ITEM];

    /* DNS context */
    dns_context_struct dns;
    kal_uint8 dns_server[SOC_MAX_APP_DNS_SRV_ADDR][DNS_ADDR_LEN]; /* 0: primary, 1: secondary */

    kal_uint8 local_ip[4];

    kal_mutexid lock;

    kal_uint32 nwk_status;

#ifdef SOC_UT
    /* for detecting potential deadlock */
    kal_uint32 soc_index;
#endif /* SOC_UT */
} socket_context_struct;


extern socket_context_struct socket_cntx;
#ifdef AUTO_DISCONNECT_GPRS_BEARER
extern soc_auto_disc_gprs_struct gprs_linger_val[];
#endif

#endif /* !_SOC_STRUCT_H */

