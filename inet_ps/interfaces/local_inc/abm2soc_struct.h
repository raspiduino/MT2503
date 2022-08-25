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
 * ABM2SOC_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of ABM and SOC.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ABM2SOC_STRUCT_H
#define _ABM2SOC_STRUCT_H

#include "cbm_consts.h"

#include "kal_general_types.h"
#include "stack_config.h"


typedef enum
{
    ABM_APP_BEARER_FB_L1                    = 0x0001,
    ABM_APP_BEARER_FB_L2                    = 0x0002,
    ABM_APP_ALWAYS_ASK                      = 0x0004,
    /* Need report the notification to AP */
    ABM_APP_ACCT_NEED_NOTIFY                = 0x0008,
    /* Hold the bearer deactivation state */
    ABM_APP_BEARER_DELAY_DISC               = 0x0010,
    /* The account query is canceled in always-ask case */
    ABM_APP_CANCEL_ACCT_QUERY               = 0x0020,
    /* CSD timer is expired and we need ABM to report the CSD auto time-out info */
    ABM_APP_CSD_AUTO_DISC_EXPIRE            = 0x0040,
    ABM_APP_GPRS_AUTO_DISC_EXPIRE           = 0x0080,
    ABM_APP_NON_AUTO_DEACT                  = 0x0100,
    ABM_APP_ACCT_HAS_SELECTED               = 0x0200,
    ABM_APP_ABORT_NWK_SRV                   = 0x0400,
    ABM_APP_STATUS_TOTAL
} abm_app_status_enum;

typedef struct
{
    kal_uint32  ipsec_spi;            /* IPSec */
    kal_uint32  flow_label;           /* IPv6 */

    kal_uint16  remote_start_port;    /* inclusive */
    kal_uint16  remote_end_port;      /* inclusive */
    kal_uint16  local_start_port;
    kal_uint16  local_end_port;
    
    kal_uint8   pfi;                  /* filter id */
    kal_uint8   epi;                  /* evaluation precedence */
    kal_uint8   protocol;             /* TCP, UDP, ... */
    kal_uint8   remote_addr[4]; 
    kal_uint8   remote_addr_prefix_len;     /* 0..32 */
    kal_uint8   tos_mask;             /* set to 0 if not required to exam ToS */
    kal_uint8   tos;
} soc_abm_dl_filter_struct  ;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 nw_acc_id; /* Network account ID */    
    kal_uint16 bandwidth;
    kal_uint16 cause;
    
    soc_abm_dl_filter_struct  dl_filter[8];
    module_type mod_id;

    kal_uint8  qos_profile_id;      /* >0: implies qos_required */
    kal_uint8  app_type;       /* app type to call encode function */
    kal_uint8  dl_filter_num;
} soc_abm_activate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 nw_acc_id;
    kal_uint32 activate_acct_id;
    
    kal_uint16 err_cause;
    kal_uint16  cause;

    kal_bool result;
    kal_bool   qos_fulfilled;

    module_type mod_id;
    cbm_bearer_enum bearer;
    kal_uint8  qos_profile_id;
    kal_uint8  bearer_ctx_id;
    kal_uint8 ip_addr[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
    kal_uint8 mac_addr[6];
    kal_uint16 mtu;
    kal_uint8 dhcp_state;
} soc_abm_activate_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 nw_acc_id;

    kal_uint16 err_cause;
    kal_uint16 mtu;
    
    kal_bool result;
    module_type mod_id;
    kal_uint8 bearer;
    kal_uint8 ip_addr[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
    kal_uint8 mac_addr[6];
    kal_uint8 dhcp_state;
} soc_abm_activate_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 nw_acc_id;
    kal_uint16 err_cause;
    kal_bool result;
    cbm_bearer_enum bearer;
    module_type mod_id;
    kal_uint8 ip_addr[4];
    kal_uint8 pri_dns_addr[4];
    kal_uint8 sec_dns_addr[4];
    kal_uint8 gateway[4];
    kal_uint8 netmask[4];
    kal_uint8 mac_addr[6];
    kal_uint8 dhcp_state;
} soc_abm_ipaddr_update_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 nw_acc_id; /* Network account ID */ 
    kal_uint16 cause;
    module_type mod_id;
    kal_uint8  qos_profile_id;
    kal_uint8  bearer_ctx_id;
} soc_abm_deactivate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 nw_acc_id;
    kal_uint16 err_cause;
    kal_uint16  cause;
    module_type mod_id;
    kal_bool result;
    kal_uint8  qos_profile_id;
    kal_uint8  bearer_ctx_id;
} soc_abm_deactivate_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;

    kal_uint32 nw_acc_id;
    kal_uint16 err_cause;
    kal_uint16 cause;
    module_type mod_id;
    kal_uint8  qos_profile_id;
    kal_uint8  bearer_ctx_id;
}  soc_abm_deactivate_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    
    kal_uint32 nw_acc_id; /* Network account ID */    
    kal_uint8  qos_profile_id;
    kal_uint8  bearer_ctx_id;
} soc_abm_resume_qos_ctx_req;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    
    kal_uint16 err_cause;
    kal_bool result;
    kal_bool is_qos_fulfilled; // Flag indicates whether the requested QoS is fulfilled by established bearer
    
    kal_uint8 profile_id;
    kal_uint8 qos_id;	      // Qos Profile ID
    kal_uint8 context_id;
} soc_abm_resume_qos_ctx_cnf;


#endif /* ~_ABM2SOC_STRUCT_H */


