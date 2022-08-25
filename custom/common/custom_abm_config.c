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
 *  custom_abm_config.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for include file of abm customization parameters. 
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__TCPIP__) && defined(__WIFI_SUPPORT__)

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "stack_msgs.h"
#include "cbm_consts.h"
#include "abm_api.h"

/*************************************************************************
 * Constant values
 *************************************************************************/

/*************************************************************************
 * Enums
 *************************************************************************/

/*************************************************************************
 * Extern
 *************************************************************************/

/********************************************
 * Following are added for WiFi Option Switchable
 *********************************************/
void custom_abm_wifi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_init();
#endif
}


kal_uint8 custom_abm_wifi_get_state(kal_bool state_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_get_state(state_only);
#else
    return 0;
#endif
}


kal_uint8 custom_abm_wifi_get_dhcp_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_get_dhcp_state();
#else
    return 0;
#endif
}


void custom_abm_wifi_get_ip_addr(kal_uint8 ip_addr[], kal_uint8 pri_dns_addr[], kal_uint8 sec_dns_addr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_get_ip_addr(ip_addr, pri_dns_addr, sec_dns_addr);
#endif
}


kal_bool custom_abm_wifi_is_app_bypass(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_is_app_bypass(app_id);
#else
    return KAL_FALSE;
#endif
}


kal_bool custom_abm_wifi_skip_bearer_info2app(
                    kal_uint8 acct_id,
                    cbm_bearer_state_enum state,
                    kal_uint8 ip_addr[],
                    module_type mod_id,
                    kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_skip_bearer_info2app(acct_id, state, ip_addr, mod_id, app_id);
#else
    return KAL_FALSE;
#endif
}


kal_bool custom_abm_wifi_is_zero_ip(kal_uint32 nw_acct_id, cbm_bearer_enum bearer, module_type mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_is_zero_ip(nw_acct_id, bearer, mod_id);
#else
    return KAL_FALSE;
#endif
}


kal_bool custom_abm_wifi_check_acct_hold(
            kal_uint32 nw_acct_id,
            module_type mod_id,
            kal_uint32 app_acct_id,
            module_type app_mod_id,
            kal_bool *is_hold)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_check_acct_hold(nw_acct_id, mod_id, app_acct_id, app_mod_id, is_hold);
#else
    return KAL_FALSE;
#endif
}


kal_int32 custom_abm_wifi_convert_app_active_state(kal_uint32 acct_id, module_type mod_id, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_convert_app_active_state(acct_id, mod_id, app_id);
#else
    return CBM_ACTIVATED;
#endif
}


kal_int32 custom_abm_wifi_activate_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_activate_req_hdlr();
#else
    return 0;
#endif
}


kal_int32 custom_abm_wifi_deactivate_req_hdlr(kal_bool is_deact_by_soc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_deactivate_req_hdlr(is_deact_by_soc);
#else
    return 0;
#endif
}


kal_bool custom_abm_wifi_is_reactive(kal_uint32 nw_acct_id, module_type mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_is_reactive(nw_acct_id, mod_id);
#else
    return KAL_FALSE;
#endif
}


kal_bool custom_abm_wifi_is_protal_app(kal_uint32 nw_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_is_protal_app(nw_acct_id);
#else
    return KAL_FALSE;
#endif
}


kal_uint8 custom_abm_wifi_get_portal_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_get_portal_state();
#else
    return 0;
#endif
}


kal_int32 custom_abm_wifi_bearer_hdlr(msg_type msg_id, void *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_bearer_hdlr(msg_id, msg_p);
#else
    return CBM_BEARER_FAIL;
#endif
}


void custom_abm_wifi_app_bearer_hdlr(
        kal_uint8 state,
        ilm_struct *msg_p,
        void *app_proc_p,
        kal_uint8 id_perapp,
        kal_uint32 ori_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_app_bearer_hdlr(state, msg_p, app_proc_p, id_perapp, ori_acct_id);
#endif
}


void custom_abm_wifi_msg_pre_proc(ilm_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_msg_pre_proc(msg_p);
#endif
}


void custom_abm_wifi_msg_hdlr(ilm_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_msg_hdlr(msg_p);
#endif
}


kal_int32 custom_abm_wifi_disc_req_hdlr(kal_uint32 app_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_disc_req_hdlr(app_state);
#else
    return CBM_OK;
#endif
}


kal_bool custom_abm_wifi_is_used_by_app(kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_is_used_by_app(acct_id);
#else
    return KAL_FALSE;
#endif
}


void custom_abm_wifi_nwk_srv_req_hdlr(kal_bool is_used_by_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_nwk_srv_req_hdlr(is_used_by_app);
#endif
}


void custom_abm_wifi_proc_bearer_switch(msg_type msg_id, kal_uint8 pre_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_proc_bearer_switch(msg_id, pre_state);
#endif
}


kal_bool custom_abm_wifi_is_used(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_is_used();
#else
    return KAL_FALSE;
#endif
}


void custom_abm_wifi_proc_power_save(kal_bool wifi_used_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    abm_wifi_proc_power_save(wifi_used_state);
#endif
}


#ifdef __GAS_SUPPORT__
kal_int32 custom_abm_wifi_gas_hdlr(msg_type msg_id, void *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return abm_wifi_gas_hdlr(msg_id, msg_p);
#else
    return CBM_ERROR;
#endif
}
#endif /* __GAS_SUPPORT__ */

#endif /* defined(__TCPIP__) && defined(__WIFI_SUPPORT__) */

