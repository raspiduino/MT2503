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
 * ABM_MAIN.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for creating ABM module.
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
 *============================================================================
 ****************************************************************************/
#ifndef _ABM_MAIN_H
#define _ABM_MAIN_H

#include "abm_feature.h"
#include "abm_api.h"
#include "abm_def.h"
#include "cbm_consts.h"
#include "abm_soc_enums.h"
#include "abm2soc_struct.h"
#include "app2soc_struct.h"
#include "mmi2abm_struct.h"
#include "custom_data_account.h"
#include "stacklib.h"
#include "event_shed.h"         /* event schedulet */
#include "stack_timer.h"


#include "kal_public_api.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "nvram_editor_data_item.h"
#include "kal_public_defs.h"

typedef void (*Wifi_FuncPtr) (void *);

#if defined(__ABM_GPRS_GUARD_TIMER_SUPPORT__) && defined(__PS_SERVICE__)
typedef struct
{
    kal_bool  is_used;
    kal_uint8 timer_id;
    kal_uint8 qos_id;
    eventid event_id;
    kal_uint32 account_id;
} abm_timer_info_struct;

typedef struct
{
    event_scheduler         *evt_scheduler;
} abm_timer_struct;
#endif /* defined(__ABM_GPRS_GUARD_TIMER_SUPPORT__) && defined(__PS_SERVICE__) */

typedef struct
{
    kal_uint16 ps_qos_rec_num;     /* total PS QoS profile record numbers */
    kal_uint16 ps_qos_rec_size;    /* one PS QoS profile record size */

    kal_uint16 ps_qos_batch_num;   /* batch PS QoS profile record numbers */
    kal_uint16 ps_qos_current_rec; /* current PS QoS profile record number */
} abm_nvram_struct;

typedef struct
{
    module_type mod_id;
    kal_uint32 type;
} abm_app_report_mod_id;

/* Application id */
typedef struct
{
    module_type activate_mod_id; /* activated module id */
    abm_app_report_mod_id report_mod_id[ABM_MAX_REPORT_BEARER_NUM]; /* module id set by application */
    kal_uint8   ap_id; /* application id */
} abm_app_id_struct;

typedef struct
{
    module_type mod_id;
    kal_uint8   event;  /* whcih bearer info ind will be reported */
    kal_uint8   type;
} abm_send_bearer_info_struct;

/* ABM application pool */
typedef struct
{
#ifdef __ABM_DISALLOW_NWK_SRV_SUPPRT__
    kal_uint32          allow_bearer;
#endif
    kal_uint32          app_event; /* application current events */
    kal_uint32          ori_account_id[ABM_MAX_APP_ACCT_NUM]; /* original account id: account id + ap id */ 
    
    kal_uint32           account_id[ABM_MAX_APP_ACCT_NUM]; /* sim id+ account id */
    abm_app_id_struct   app; /* application id */
    abm_bearer_state_enum  app_state[ABM_MAX_APP_ACCT_NUM]; /* bearer is activated or deactivated by SOC */
    
    kal_uint8           account_state[ABM_MAX_APP_ACCT_NUM]; /* application's account state */    
    kal_uint8           reg_state; /* application's registered bearer status */
    kal_uint8           reg_type;  /* application's registered bearer type */
#ifdef __APP_SECONDARY_PDP_SUPPORT__
    kal_uint8           qos_profile_id[ABM_MAX_APP_ACCT_NUM]; /* qos profile id*/
    kal_uint8           context_id[ABM_MAX_APP_ACCT_NUM]; /* context id */
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */

#ifdef __CBM_BEARER_SWITCH__
    kal_uint8            cur_fb_status;
    kal_uint8           next_acct_num; /* next account id whcih will be used to activate the bearer */
#endif /* __CBM_BEARER_SWITCH__ */

#if defined(__APP_STATIC_QOS_PROFILE_SUPPORT__) || defined(__APP_DYNAMIC_QOS_PROFILE_SUPPORT__)
    kal_uint8                               qos_profile_idx; /* qos profile index */
    nvram_ef_abm_ps_qos_profile_struct      *qos_profile;
#endif /* defined(__APP_STATIC_QOS_PROFILE_SUPPORT__) || defined(__APP_DYNAMIC_QOS_PROFILE_SUPPORT__) */
} abm_app_proc_struct;

/* ABM WIFI account pool */
typedef struct
{
    kal_uint8 account_id;
    kal_uint8 state;
    abm_bearer_state_enum app_state;
    kal_bool  is_activated_by_soc;
    /* abm is in waiting the connection request sent from MMI */
    kal_bool  is_waiting_connect;
    /* abm is in waiting the disconnection request sent from MMI */
    kal_bool  is_waiting_disconnect;
#ifdef __OP01__
    abm_portal_state_enum portal_verify_state;
    kal_uint8 portal_app_id;
#endif
    kal_bool use_dhcp;
    kal_uint8 dhcp_state;
    kal_uint8 ip_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_bool ip_update_pending;
    kal_uint8 ip_addr_new[4];
    kal_uint8 gateway_new[4];
    kal_uint8 netmask_new[4];
    kal_uint8 pri_dns_addr_new[4];
    kal_uint8 sec_dns_addr_new[4];
    kal_uint8 mac_addr[6];
    kal_uint8 wndrv_handle;

    Wifi_FuncPtr todo;
    void *data;

#ifdef __GAS_SUPPORT__
    kal_bool use_gas;
    kal_uint8 gas_src_id;
#endif /* __GAS_SUPPORT__ */
} abm_wifi_bearer_struct;

/* ABM CSD account pool */
typedef struct
{
    kal_uint8   state;
    kal_uint32   account_id; /* sim id + account id*/
    abm_bearer_state_enum  app_state; /* bearer is deactivated by SOC or MMI CBM */

    kal_uint8   ip_addr[4];
    kal_uint8   pri_dns_addr[4];
    kal_uint8   sec_dns_addr[4];
    kal_uint16  mtu;
    void        *profile;
} abm_csd_bearer_struct;

typedef struct
{
    kal_uint32   account_id; /* sim id + account id*/
#if defined(__HOTSPOT_SUPPORT__) || defined(__WIFI_AP_MODE_SUPPORT__)
    void *profile;
#endif
    kal_uint16   mtu;
    abm_dhcp_state_enum dhcp_state;
    cbm_bearer_enum bearer;
    kal_bool      is_activate;
#ifdef __USB_TETHERING__
    kal_bool      is_suspend;
#endif
    kal_uint8     state;
    kal_uint8     ip_addr[4];
    kal_uint8     dns1[4];
    kal_uint8     dns2[4];
#if defined(__HOTSPOT_SUPPORT__) || defined(__WIFI_AP_MODE_SUPPORT__)
    kal_uint8     mac_addr[6];
    kal_bool      is_waiting_init_rsp;
#endif 
} abm_share_bearer_struct;

#ifdef __PS_SERVICE__
/* ABM PS account pool */
typedef struct
{
    kal_uint8 account_id;
#ifdef __APP_SECONDARY_PDP_SUPPORT__
    kal_uint8 context_id;
#endif
    kal_uint8 *profile;
} abm_ps_nwk_neg_qos_struct;

typedef struct
{
#ifdef  __GPRS_BEARER_REPORT_NEGOTIATED_QOS__
    abm_ps_nwk_neg_qos_struct *nwk_neg_qos;
#endif

    void *profile;
    kal_uint32  account_id;
    kal_uint8  state;
    kal_uint8  app_state; 
    kal_uint8  ip_addr[4];
    kal_uint8  pri_dns_addr[4];
    kal_uint8  sec_dns_addr[4];
    kal_uint8  context_id;
#ifdef __APP_SECONDARY_PDP_SUPPORT__
    kal_uint8  qos_profile_id;
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */
    
} abm_ps_bearer_struct;
#endif /* __PS_SERVICE__ */

/* ABM DCD account pool */
typedef struct
{
    kal_uint8   state;
    kal_uint8   account_id;
    kal_uint8   ip_addr[4];
    kal_uint8   pri_dns_addr[4];
    kal_uint8   sec_dns_addr[4];
} abm_internal_ps_bearer_struct;

/* ABM Account Pool */
#if defined(__TCPIP_OVER_CSD__) || defined(__PS_SERVICE__) || defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)

typedef struct
{
#ifdef __TCPIP_OVER_CSD__
    /* CSD account table */
    abm_csd_bearer_struct         csd_bearer;
#endif
#if defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)
   abm_share_bearer_struct share_bearer;
#endif
#ifdef __PS_SERVICE__
    /* GPRS table size can be adjusted by the customer */
    abm_ps_bearer_struct          ps_bearer[GPRS_MAX_PDP_SUPPORT];
#endif /* __PS_SERVICE__ */
} abm_account_pool_struct;

#endif /* defined(__TCPIP_OVER_CSD__) || defined(__PS_SERVICE__) || defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)*/

typedef struct
{
    void *data;
    void *func;
    kal_uint8 type;
} abm_app_callback_struct;

typedef struct  
{
    kal_uint64              app_type;
    kal_uint16              app_str_id;
    kal_uint16              app_icon_id;
    abm_app_callback_struct callback[MAX_APP_CALLBACK_NUM];
    kal_uint8               valid;
    kal_uint8               app_id;
} abm_app_id_table_struct;

typedef struct
{
    kal_uint32                  acct_id;
    kal_uint16                  bandwidth;
    kal_uint8                   qos_profile_id;   /* return to application */
    kal_uint8                   app_type;         /* applicatoin type for encode function */
    soc_abm_dl_filter_struct    dl_filters[ABM_MAX_DL_FILTERS];
    kal_uint8                   dl_filter_num;
} abm_app_qos_struct;

#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
typedef struct
{
    kal_uint8                   qos_profile_idx;
    module_type                 mod_id;
} abm_qos_report_event_struct;

typedef struct
{
    abm_qos_report_event_struct event[ABM_MAX_APP_NUM];
} abm_qos_event_struct;
#endif /* __APP_STATIC_QOS_PROFILE_SUPPORT__ */

typedef struct
{
    kal_uint32          account_id;
    cbm_bearer_enum     bearer_type;
} abm_account_info_struct;

typedef struct
{
    mmi_abm_dialup_struct info;
    kal_uint32 state;
    kal_uint32 app_state;
} abm_dialup_info_struct;

/* ABM context */
typedef struct
{
    kal_mutexid                 lock;
    kal_uint32                  app_id_list[ABM_MAX_APP_ID_LIST_NUM];
#ifdef __APP_DYNAMIC_QOS_PROFILE_SUPPORT__
    kal_uint32                  dynamic_qos_id;
#endif
#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
    abm_qos_event_struct        *static_qos_event; 
#endif

#if defined(__TCPIP_OVER_CSD__) || defined(__PS_SERVICE__) || defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)
    abm_account_pool_struct     account_pool;
#endif
    abm_app_proc_struct         app_pool[ABM_MAX_APP_NUM]; /* applicaiton pool */
#ifdef __APP_SECONDARY_PDP_SUPPORT__
    /* pool to store the pdp context data whcih will be used when we in reactive state */
    abm_app_qos_struct          pdp_context_pool[ABM_MAX_APP_NUM]; 
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */
    abm_app_id_table_struct     app_tbl_pool[ABM_MAX_APP_NUM]; /* MMI CBM application table */
    abm_send_bearer_info_struct bearer_event[ABM_MAX_APP_NUM]; /* Define which bearer info should be reported */
#if defined(__ABM_GPRS_GUARD_TIMER_SUPPORT__) && defined(__PS_SERVICE__)
    abm_timer_struct            abm_timer; /* GPRS guard timer */
#endif
#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
    abm_nvram_struct            nvram_info;
#endif
    abm_account_info_struct        acct_info[MAX_ACCOUNT_UPDATE_NUM]; /* updated account list */
#ifdef __ABM_DISALLOW_NWK_SRV_SUPPRT__
    cbm_bearer_enum             nwk_srv_disallow[CBM_SIM_ID_TOTAL]; /* disallow network service or not*/
    mmi_abm_nwk_srv_req_struct  *nwk_srv_req;
#endif /* __ABM_DISALLOW_NWK_SRV_SUPPRT__ */
    kal_uint8                   avail_app_id; /* current available global app id */
#if !defined(EMPTY_MMI) && defined(__GEMINI__)
    kal_uint8                   rcv_approve_src; /* received response from L4C */
    kal_bool                    rcv_approve_rsp; /* received result from L4C */
#endif /* !defined(EMPTY_MMI) && defined(__GEMINI__) */
    
#ifdef __PS_SERVICE__
    cbm_bearer_enum bearer_type; /* real packet swith service type */
    kal_uint8 gprs_status[CBM_SIM_ID_TOTAL];
#endif /* __PS_SERVICE__ */

    abm_dialup_info_struct dialup_info[ABM_MAX_DIALUP_NUM];

    kal_uint32 disc_bearer_type;
    cbm_sim_id_enum disc_sim_id;

    mmi_abm_update_app_info_struct  invalid_app_info[ABM_MAX_APP_NUM]; /* invalid app list */
} abm_context_struct;

extern abm_context_struct *const abm_cxt_ptr;

#define ABM_CTX(x) (abm_cxt_ptr->x)

#if defined(__TCPIP_OVER_CSD__) || defined(__PS_SERVICE__) || defined(__HOTSPOT_SUPPORT__) || defined(__USB_TETHERING__) || defined(__WIFI_AP_MODE_SUPPORT__)
#define ABM_ACCT_PTR(X) (&ABM_CTX(account_pool.X))
#endif

#define ABM_APP_PTR(_s_)   (&ABM_CTX(app_pool[_s_]))
#define ABM_BEARER_INFO_PTR(_s_)    (&ABM_CTX(bearer_event[_s_]))
#ifdef __PS_SERVICE__
#define ABM_TIMER(X) ABM_CTX(abm_timer.X)
#define ABM_PS_ACCT_POOL_STATE(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].state)
#define ABM_PS_ACCT_POOL_APP_STATE(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].app_state)
#define ABM_PS_ACCT_POOL_ACCT_ID(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].account_id)
#define ABM_PS_ACCT_POOL_IP_ADDR(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].ip_addr)
#define ABM_PS_ACCT_POOL_PRI_DNS_ADDR(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].pri_dns_addr)
#define ABM_PS_ACCT_POOL_SEC_DNS_ADDR(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].sec_dns_addr)
#define ABM_PS_ACCT_POOL_CTX_ID(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].context_id)
#ifdef __APP_SECONDARY_PDP_SUPPORT__
#define ABM_QOS_POOL_PTR(_s_)   (&ABM_CTX(pdp_context_pool[_s_]))
#define ABM_PS_ACCT_POOL_QOS_ID(_s_)   (ABM_CTX(account_pool).ps_bearer[_s_].qos_profile_id)
#endif /* __APP_SECONDARY_PDP_SUPPORT */
#endif /* __PS_SERVICE__ */
#define ABM_GLOBAL_LOCK   kal_take_mutex(ABM_CTX(lock))
#define ABM_GLOBAL_UNLOCK kal_give_mutex(ABM_CTX(lock))
#define ABM_APP_TBL_PTR(_s_)   (&ABM_CTX(app_tbl_pool[_s_]))

typedef union
{
    kal_uint32 acct_id;
    struct  
    {
        kal_uint8 ori_acct_id[2]; /* 1 bit:always-ask  7 bits: account id*/
        kal_uint8 sim_id;
        kal_uint8 app_data; /* 8 bits: ap id*/
    } acct_mask;
    
} abm_acct_union_struct; 

#define ABM_ENCODE_MASK_ALWAYS_ASK          (0x80)
#define ABM_ENCODE_MASK_APP_ID              (0xff)
#define ABM_ENCODE_MASK_ACCT_ID             (0x7f)
#define ABM_ENCODE_ACCT_MASK                (0xffffffff)

#endif /* _ABM_MAIN_H */ 

