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
 * abm_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the ABM network internal APIs 
 *   and these APIs can only be used by MMI CBM and DA
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ABM_API_H
#define _ABM_API_H

#ifndef _CBM_API_H
#include "cbm_api.h"
#endif /* !_CBM_API_H */

#include "cbm_consts.h"
#include "kal_general_types.h"

/*************************************************************************
* Constants
*************************************************************************/
#define MAX_APP_CALLBACK_NUM    (2)

#ifdef __TCPIP_OVER_CSD__
#define MAX_ACTIVE_CSD_NUM       (1)
#else
#define MAX_ACTIVE_CSD_NUM       (0)
#endif
#ifdef __WIFI_SUPPORT__
#define MAX_ACTIVE_WIFI_NUM      (1)
#else
#define MAX_ACTIVE_WIFI_NUM      (0)
#endif

#define MAX_ACTIVE_BEARER_NUM    (GPRS_MAX_PDP_SUPPORT+MAX_ACTIVE_CSD_NUM+MAX_ACTIVE_WIFI_NUM)

/*************************************************************************
* Constants
*************************************************************************/
typedef enum
{
    ABM_APP_BEARER_NONE,
    ABM_APP_BEARER_EVENT = 0x01,
    ABM_APP_BEARER_INFO = 0x02,
    ABM_APP_BEARER_TOTAL
} abm_app_callback_type_enum;

typedef enum
{
    ABM_CONNECT_TYPE_LOCAL,
    ABM_CONNECT_TYPE_DIALUP,
    ABM_CONNECT_TYPE_TOTAL
} abm_connect_type_enum;

/*************************************************************************
* Structures
*************************************************************************/
/* for bearer status api */
typedef void (*FuncPtrBearerStatus) (cbm_bearer_state_enum, cbm_bearer_enum, kal_uint32);

typedef struct  
{
    kal_uint8   app_id;
    void        *callback;
    void        *data;
} abm_app_register_info_struct;

/*************************************************************************
* External APIs for MMI CBM
*************************************************************************/
extern kal_int8 abm_get_registered_app_name(kal_uint8 app_id, cbm_app_info_struct *info);
extern kal_int8 abm_deregister_app_callback(abm_app_callback_type_enum type,
                                             kal_uint8 app_id);
extern kal_int8 abm_register_app_callback(abm_app_callback_type_enum type,
                                          kal_uint8 app_id, void *callback, void *data);
extern kal_int8 abm_get_registered_app_callback_info(kal_uint8 app_id,
                                              abm_app_callback_type_enum type,
                                              abm_app_register_info_struct *app_register_info);
extern kal_int8 abm_check_app_id(kal_uint8 app_id);
extern kal_int8 abm_set_allowed_app_nwk_srv(kal_uint32 type, kal_uint8 app_id);
extern kal_int32 abm_get_bearer_available_status(kal_uint32 bearer, cbm_sim_id_enum sim_id);
extern kal_int8 abm_get_switchable_app_id(kal_uint8 app_id[], kal_uint32 acct_id[], kal_uint32 *app_num);
extern kal_bool abm_is_bearer_detached(cbm_bearer_enum bearer_type, cbm_sim_id_enum sim_id);
extern kal_int32 abm_get_bearer_status_by_app_type(kal_uint32 app_type, cbm_bearer_enum bearer, cbm_sim_id_enum sim_id);

#ifdef __WIFI_SUPPORT__
extern kal_bool abm_is_wifi_used(void);
#endif

/*************************************************************************
* External APIs for Custom ABM
*************************************************************************/
#ifdef __WIFI_SUPPORT__

extern void abm_wifi_init(void);
extern kal_uint8 abm_wifi_get_state(kal_bool state_only);
extern kal_uint8 abm_wifi_get_dhcp_state(void);
extern void abm_wifi_get_ip_addr(kal_uint8 ip_addr[], kal_uint8 pri_dns_addr[], kal_uint8 sec_dns_addr[]);

extern kal_bool abm_wifi_is_app_bypass(kal_uint8 app_id);
extern kal_bool abm_wifi_skip_bearer_info2app(
                    kal_uint8 acct_id,
                    cbm_bearer_state_enum state,
                    kal_uint8 ip_addr[],
                    module_type mod_id,
                    kal_uint8 app_id);
extern kal_bool abm_wifi_is_zero_ip(kal_uint32 nw_acct_id, cbm_bearer_enum bearer, module_type mod_id);
extern kal_bool abm_wifi_check_acct_hold(
                    kal_uint32 nw_acct_id,
                    module_type mod_id,
                    kal_uint32 app_acct_id,
                    module_type app_mod_id,
                    kal_bool *is_hold);
extern kal_int32 abm_wifi_convert_app_active_state(kal_uint32 acct_id, module_type mod_id, kal_uint8 app_id);

extern kal_int32 abm_wifi_activate_req_hdlr(void);
extern kal_int32 abm_wifi_deactivate_req_hdlr(kal_bool is_deact_by_soc);
extern kal_bool abm_wifi_is_reactive(kal_uint32 nw_acct_id, module_type mod_id);

extern kal_bool abm_wifi_is_protal_app(kal_uint32 nw_acct_id);
extern kal_uint8 abm_wifi_get_portal_state(void);

extern kal_int32 abm_wifi_bearer_hdlr(msg_type msg_id, void *msg_p);

extern void abm_wifi_app_bearer_hdlr(
                kal_uint8 state,
                ilm_struct *msg_p,
                void *app_proc_p,
                kal_uint8 id_perapp,
                kal_uint32 ori_acct_id);

extern void abm_wifi_msg_pre_proc(ilm_struct *msg_p);
extern void abm_wifi_msg_hdlr(ilm_struct *msg_p);

extern kal_int32 abm_wifi_disc_req_hdlr(kal_uint32 app_state);

extern kal_bool abm_wifi_is_used_by_app(kal_uint32 acct_id);
extern void abm_wifi_nwk_srv_req_hdlr(kal_bool is_used_by_app);

extern void abm_wifi_proc_bearer_switch(msg_type msg_id, kal_uint8 pre_state);

extern kal_bool abm_wifi_is_used(void);
extern void abm_wifi_proc_power_save(kal_bool wifi_used_state);

#ifdef __GAS_SUPPORT__
extern kal_int32 abm_wifi_gas_hdlr(msg_type msg_id, void *msg_p);
#endif

#endif /* __WIFI_SUPPORT__ */

#endif /* _ABM_API_H */

