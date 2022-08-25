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
 * CbmAppMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
#ifdef __TCPIP__

#include "MMI_features.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIprot.h"

#include "MMIDataType.h"
#include "CommonScreensResDef.h"
#include "mmi_cb_mgr_gprot.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "cbm_consts.h"
#include "cbm_api.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"
#include "mmi_rp_app_cbm_def.h"
#include "AlertScreen.h"

#ifdef __MMI_WLAN_FEATURES__
#include "WlanCuiGprot.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "DataAccountGprot.h"
#include "DataLockSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#ifdef __MMI_TETHERING_WIFI__
#include "TetheringSrvGprot.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
#include "ScrLockerGprot.h"
#endif

#include "UcmSrvGprot.h"
#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "vapp_ncenter_gprot.h"
#endif
#endif /* __MMI_WLAN_FEATURES__ */
#include "mmi_rp_app_scr_locker_def.h"

#ifdef __USB_EEM_SUPPORT__
static U8 mmi_cbm_eem_ip_conflict_ind_hdlr(void *info);
static mmi_ret mmi_cbm_eem_ip_conflict_cnf_popup_cb(mmi_event_struct *evt);
static void mmi_cbm_eem_ip_conflict_select_cnf_hdlr(MMI_BOOL use_wifi);
#endif /* __USB_EEM_SUPPORT__ */

#ifdef __MMI_WLAN_FEATURES__

typedef enum
{
    MMI_CBM_RET_SUCC,
    MMI_CBM_RET_FAIL,
    MMI_CBM_RET_WOULDBLOCK,
    MMI_CBM_RET_YES,
    MMI_CBM_RET_NO,
    MMI_CBM_RET_TOTAL
} mmi_cbm_ret_enum;


#define MMI_CBM_CHOOSE_ITEM_MAX_NUM 2

typedef enum
{
    MMI_CBM_ITEM_USE_WLAN = 0,
    MMI_CBM_ITEM_USE_CELLULAR,
    MMI_CBM_ITEM_USE_CANCEL,
    MMI_CBM_ITEM_USE_TYPE_TOTAL
} mmi_cbm_item_type;

typedef void (*mmi_cbm_ptr)(mmi_cbm_item_type result, void* userdata);

typedef struct
{
    srv_cbm_wlan_query_type_enum query_type;
    U16      title_str;
    U16      item_num;
    U16      hilight;
    mmi_id   wlan_cui_id;
    mmi_cbm_ptr callback;
    void*       userdata;
    mmi_cbm_item_type item_type[MMI_CBM_CHOOSE_ITEM_MAX_NUM];
    MMI_BOOL auto_conn_wlan;
#ifdef __MMI_OP01_WIFI__
    MMI_BOOL show_ask_cellular;
    mmi_cbm_item_type callback_item;
#endif /* __MMI_OP01_WIFI__ */
    mmi_cbm_ptr reentry_callback;
} mmi_cbm_scr_struct;

typedef struct
{
    srv_cbm_wlan_query_type_enum query_type;
    U16 title_str;
    MMI_BOOL show_wlan_item;
    MMI_BOOL show_cellular_item;
    MMI_BOOL auto_conn_wlan;
    mmi_cbm_ptr callback;
    void *userdata;
#ifdef __MMI_OP01_WIFI__
    MMI_BOOL show_ask_cellular;
#endif
} mmi_cbm_parm_struct;

typedef struct
{
    srv_cbm_wlan_query_evt_struct *wlan_query_evt;
    MMI_BOOL is_waiting_scan;
    MMI_BOOL auto_conn;
    MMI_BOOL need_notify;
} mmi_cbm_cntx_struct;

static mmi_cbm_scr_struct g_cbm_scr;
static mmi_cbm_cntx_struct g_mmi_cbm_cntx;
static mmi_cbm_cntx_struct *g_mmi_cbm_cntx_ptr = NULL;
static MMI_BOOL g_mmi_cbm_reentry_defered = MMI_FALSE;

static void mmi_cbm_wlan_scan_callback(
                U32 job_id,
                void *user_data,
                srv_dtcnt_wlan_scan_result_struct *scan_res);
static void mmi_cbm_cancel_if_existed(void);
static void mmi_cbm_reentry_if_existed(MMI_BOOL defer_reentry);
static MMI_BOOL mmi_cbm_cancel_if_not_active(void);
static mmi_ret mmi_cbm_reentry_callback(mmi_event_struct *evt);
static S32 mmi_cbm_is_wlan_query_needed(
            srv_cbm_wlan_query_type_enum query_type,
            U8 ap_num,
            U32 *bearer_type);
static void mmi_cbm_fill_wlan_query_param(
                mmi_cbm_parm_struct *param,
                srv_cbm_wlan_query_type_enum query_type,
                U8 ap_num);
static void mmi_cbm_wlan_auto_conn_dummy_callback(mmi_wlan_auto_conn_action_enum action);

static void mmi_cbm_launch(mmi_cbm_parm_struct*);

static MMI_BOOL mmi_cbm_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg);

#endif /* __MMI_WLAN_FEATURES__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_app_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cbm_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    g_mmi_cbm_cntx_ptr = &g_mmi_cbm_cntx;
    memset(g_mmi_cbm_cntx_ptr, 0, sizeof(mmi_cbm_cntx_struct));
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __USB_EEM_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_ABM_EEM_IP_CONFLICT_IND, 
        (PsIntFuncPtr)mmi_cbm_eem_ip_conflict_ind_hdlr, MMI_FALSE);
#endif /* __USB_EEM_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_handle_cbm_bearer_info
 * DESCRIPTION
 *  This function handles the CBM bearer info to display CSD icon. (Obsolete)
 *  This feature should be handled by data account application in the future.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_cbm_handle_cbm_bearer_info(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum sim_id;
    srv_cbm_bearer_info_struct *evt = (srv_cbm_bearer_info_struct *)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt);

    if ((evt->type & SRV_CBM_BEARER_CSD) && evt->state == SRV_CBM_ACTIVATED)
    {
        #ifdef __MMI_STATUS_ICON_BAR_SLIM__       
        MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 1, evt->state);
        wgui_status_icon_bar_show_icon(STATUS_ICON_CSD);
        #else  //__MMI_STATUS_ICON_BAR_SLIM__
        sim_id = cbm_get_sim_id(evt->account_id);

        switch (sim_id)
        {
            case CBM_SIM_ID_SIM1:
                {
                    MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 1, evt->state);
                    wgui_status_icon_bar_show_icon(STATUS_ICON_CSD);
                }
                break;
                
        #ifdef __GEMINI__
        #if (MMI_MAX_SIM_NUM >= 2)
            case CBM_SIM_ID_SIM2:
                {
                    MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 2, evt->state);
                    wgui_status_icon_bar_show_icon(STATUS_ICON_SLAVE_CSD);
                }
                break;
        #endif

        #if (MMI_MAX_SIM_NUM >= 3)
            case CBM_SIM_ID_SIM3:
                {
                    MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 3, evt->state);
                    wgui_status_icon_bar_show_icon(STATUS_ICON_SIM3_CSD);
                }
                break;
        #endif

       #if (MMI_MAX_SIM_NUM >= 4)
            case CBM_SIM_ID_SIM4:
                {
                    MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 4, evt->state);
                    wgui_status_icon_bar_show_icon(STATUS_ICON_SIM4_CSD);
                }
                break;
        #endif
        
        #endif

            default:
                 {
                    MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 1, evt->state);
                    wgui_status_icon_bar_show_icon(STATUS_ICON_CSD);
                }
                break;
        }
        #endif  //__MMI_STATUS_ICON_BAR_SLIM__
    }
    else if ((evt->type & SRV_CBM_BEARER_CSD) && evt->state == SRV_CBM_DEACTIVATED)
    {
        #ifdef __MMI_STATUS_ICON_BAR_SLIM__        
        MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 1, evt->state);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CSD);
        #else  //__MMI_STATUS_ICON_BAR_SLIM__
        sim_id = cbm_get_sim_id(evt->account_id);
       
        switch (sim_id)
        {
            case CBM_SIM_ID_SIM1:
            {
                MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 1, evt->state);
                wgui_status_icon_bar_hide_icon(STATUS_ICON_CSD);
            }
            break;
                
        #ifdef __GEMINI__
        #if (MMI_MAX_SIM_NUM >= 2)
            case CBM_SIM_ID_SIM2:
            {
                MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 2, evt->state);
                wgui_status_icon_bar_hide_icon(STATUS_ICON_SLAVE_CSD);
            }
            break;
        #endif

        #if (MMI_MAX_SIM_NUM >= 3)
            case CBM_SIM_ID_SIM3:
            {
                MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 3, evt->state);
                wgui_status_icon_bar_hide_icon(STATUS_ICON_SIM3_CSD);
            }
            break;
        #endif

       #if (MMI_MAX_SIM_NUM >= 4)
            case CBM_SIM_ID_SIM4:
            {
                MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 3, evt->state);
                wgui_status_icon_bar_hide_icon(STATUS_ICON_SIM4_CSD);
            }
            break;
        #endif
        
        #endif

            default:
            {
                MMI_TRACE(MMI_CONN_TRC_INFO, MMI_CBM_DISPLAY_CSD_ICON, 1, evt->state);
                wgui_status_icon_bar_hide_icon(STATUS_ICON_CSD);
            }
            break;
        }
        #endif  //__MMI_STATUS_ICON_BAR_SLIM__
    }

    return MMI_RET_OK;
}


mmi_ret mmi_cbm_srv_cbm_wlan_query_evt_hdlr(mmi_event_struct *param)
{
#ifdef __MMI_WLAN_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_evt_struct *wlan_query_p;
    srv_dtcnt_wlan_state_enum wlan_state;
    MMI_BOOL result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_query_p = (srv_cbm_wlan_query_evt_struct*)param;

    if (wlan_query_p->query_type == SRV_CBM_WLAN_QUERY_TYPE_REQUERY)
    {
        MMI_ASSERT(g_mmi_cbm_cntx_ptr->wlan_query_evt);

        if (g_mmi_cbm_cntx_ptr->is_waiting_scan)
        {
            return MMI_RET_OK;
        }

        result = mmi_cbm_cancel_if_not_active();
        if (!result)
        {
            return MMI_RET_OK;
        }
    }
    else if (wlan_query_p->query_type == SRV_CBM_WLAN_QUERY_TYPE_AUTO_CONN)
    {
        mmi_wlan_auto_conn_networks(mmi_cbm_wlan_auto_conn_dummy_callback);
        wlan_query_p->rsp_callback(CBM_BEARER_WIFI);
        return MMI_RET_OK;
    }
    else
    {
        MMI_ASSERT(!g_mmi_cbm_cntx_ptr->wlan_query_evt && !g_mmi_cbm_cntx_ptr->is_waiting_scan);

        g_mmi_cbm_cntx_ptr->wlan_query_evt = (srv_cbm_wlan_query_evt_struct*)
            OslMalloc(sizeof(srv_cbm_wlan_query_evt_struct));

        memcpy(
            g_mmi_cbm_cntx_ptr->wlan_query_evt,
            wlan_query_p,
            sizeof(srv_cbm_wlan_query_evt_struct));
    }

    srv_cbm_get_wlan_prefer_setting(
        wlan_query_p->query_type,
        &g_mmi_cbm_cntx_ptr->auto_conn,
        &g_mmi_cbm_cntx_ptr->need_notify);

    g_mmi_cbm_cntx_ptr->is_waiting_scan = MMI_TRUE;

    wlan_state = srv_dtcnt_wlan_state();

    if (
    #ifdef __MMI_OP01_WIFI__
        !srv_mode_switch_is_network_service_available() ||
    #endif
    #ifdef __MMI_TELEPHONY_SUPPORT__
        srv_mode_switch_is_switching() ||
    #endif
        wlan_state == SRV_DTCNT_WLAN_STATE_NULL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_TOTAL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT
    #ifdef __MMI_TETHERING_WIFI__
        || !srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS)
    #endif
        )
    {
        srv_dtcnt_wlan_scan_result_struct scan_res;
        scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS;
        scan_res.ap_list_num = 0;
        mmi_cbm_wlan_scan_callback(0, NULL, &scan_res);
        return MMI_RET_OK;
    }

#ifndef WENKE_TEST
    srv_dtcnt_wlan_scan(mmi_cbm_wlan_scan_callback, NULL);
#else
    {
        srv_dtcnt_wlan_scan_result_struct scan;
        scan.result = SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS;
        scan.ap_list_num = 1;
        mmi_cbm_wlan_scan_callback(0, NULL, &scan);
    }
#endif
#endif /* __MMI_WLAN_FEATURES__ */

    return MMI_RET_OK;
}


mmi_ret mmi_cbm_evt_proc_hdlr(mmi_event_struct *evt)
{
#ifdef __MMI_WLAN_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCR_LOCKER_LOCKED:
            mmi_cbm_reentry_if_existed(MMI_FALSE);
            break;

        case EVT_ID_SRV_UCM_INDICATION:
            {
                srv_ucm_ind_evt_struct *ucm_ind = (srv_ucm_ind_evt_struct*)evt;
                if (ucm_ind->ind_type == SRV_UCM_INCOMING_CALL_IND)
                {
                    mmi_cbm_reentry_if_existed(MMI_FALSE);
                }
            }
            break;

    #if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        case EVT_ID_VAPP_NCENTER_ENTERED:
            break;

        case EVT_ID_VAPP_NCENTER_EXITED:
            mmi_cbm_reentry_if_existed(MMI_FALSE);
            break;
    #endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

        case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
            {
                srv_dtcnt_wlan_deinit_res_ind_evt_struct *wlan_deinit_ind =
                    (srv_dtcnt_wlan_deinit_res_ind_evt_struct*)evt;

                if (wlan_deinit_ind->res == SRV_DTCNT_WLAN_REQ_RES_DONE)
                {
                    mmi_cbm_cancel_if_existed();
                }
            }
            break;

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
            {
                srv_mode_switch_notify_struct *flight_mode =
                    (srv_mode_switch_notify_struct*)evt;

                if (flight_mode->curr_flight_mode == SRV_MODE_SWITCH_OFF &&
                    flight_mode->select_flight_mode == SRV_MODE_SWITCH_ON)
                {
                    mmi_cbm_cancel_if_existed();
                }
            }
            break;

        default:
            break;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    return MMI_RET_OK;
}

#ifdef __USB_EEM_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_bearer_info_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_cbm_eem_ip_conflict_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    U8* prefix = NULL;
    U8 *suffix = NULL;
    U8* message = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* display alert notification for user */
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE); 
    arg.softkey[0].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_YES));	
    arg.softkey[1].img = GetImage(IMG_GLOBAL_COMMON_CSK);	
    arg.softkey[2].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_NO));
    
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_ROOT;
    arg.callback = (mmi_proc_func)mmi_cbm_eem_ip_conflict_cnf_popup_cb;
    /* prepare string */
    prefix = (U8*)GetString(STR_ID_MMI_CBM_EEM_IP_CONFLICT);    
    suffix = (U8*)GetString(STR_ID_MMI_CBM_EEM_IP_SELECT); 
    message = OslMalloc((mmi_ucs2strlen((CHAR*)prefix) + mmi_ucs2strlen((CHAR*)suffix) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)message, (CHAR*)prefix);
    mmi_ucs2cat((CHAR*)message, (CHAR*) L"\n");
    mmi_ucs2cat((CHAR*)message, (CHAR*)suffix);
    
    mmi_confirm_display((WCHAR *)message, MMI_EVENT_QUERY, &arg);
    
    OslMfree(message);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_eem_ip_conflict_cnf_popup_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_cbm_eem_ip_conflict_cnf_popup_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = 
                    (mmi_alert_result_evt_struct*)evt;
            switch (alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                    mmi_cbm_eem_ip_conflict_select_cnf_hdlr(MMI_TRUE);
                    break;
                    
                case MMI_ALERT_CNFM_NO:
                    mmi_cbm_eem_ip_conflict_select_cnf_hdlr(MMI_FALSE);
                    break;
            }
        }
        break;
    }
    
    return MMI_RET_OK;
}


static void mmi_cbm_eem_ip_conflict_select_cnf_hdlr(MMI_BOOL use_wifi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_eem_ip_conflict_rsp_struct *rsp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_abm_eem_ip_conflict_rsp_struct*) OslConstructDataPtr(sizeof(mmi_abm_eem_ip_conflict_rsp_struct));
    
    if (use_wifi)
    {
        rsp->bearer = CBM_WIFI;
    }
    else
    {
        rsp->bearer = CBM_IC_USB;
    }

    mmi_frm_send_ilm(
        MOD_ABM,
        MSG_ID_MMI_ABM_EEM_IP_CONFLICT_RSP,
        (oslParaType*)rsp,
        NULL);
}

#endif /* __USB_EEM_SUPPORT__ */

#ifdef __MMI_WLAN_FEATURES__

#ifdef __MMI_OP01_WIFI__
static mmi_ret mmi_cbm_ask_cellular_popup_callback(mmi_alert_result_evt_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_ALERT_QUIT &&
        (param->result == MMI_ALERT_CNFM_YES ||
         param->result == MMI_ALERT_CNFM_NO))
    {
        if (param->result == MMI_ALERT_CNFM_YES)
        {
            srv_cbm_set_ask_cellular_setting(MMI_FALSE);
        }

        g_cbm_scr.callback(MMI_CBM_ITEM_USE_CELLULAR, g_cbm_scr.userdata);
        g_cbm_scr.callback = NULL;
        mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
    }

    return MMI_RET_OK;
}
#endif /* __MMI_OP01_WIFI__ */


static void mmi_cbm_cancel_if_existed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_app_exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cbm_scr.callback)
    {
        is_app_exist = mmi_frm_group_is_present(GRP_ID_MMI_CBM_APP);
        if (is_app_exist)
        {
            mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
        }
        else
        {
            mmi_event_struct cancel_evt;

            mmi_frm_nmgr_cancel_deferred_scenario(
                MMI_SCENARIO_ID_DEFAULT,
                mmi_cbm_nmgr_expiry_callback,
                NULL);

            cancel_evt.evt_id = EVT_ID_GROUP_DEINIT;
            mmi_cbm_group_proc(&cancel_evt);
        }
    }
}


static void mmi_cbm_reentry_if_existed(MMI_BOOL defer_reentry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_app_exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cbm_scr.callback)
    {
        is_app_exist = mmi_frm_group_is_present(GRP_ID_MMI_CBM_APP);
        if (is_app_exist)
        {
            if (defer_reentry)
            {
                g_mmi_cbm_reentry_defered = MMI_TRUE;
            }

            g_cbm_scr.reentry_callback = g_cbm_scr.callback;
            g_cbm_scr.callback = NULL;

            mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
        }
    }
}


static MMI_BOOL mmi_cbm_cancel_if_not_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_app_exist;
    MMI_BOOL is_app_active;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_app_exist = mmi_frm_group_is_present(GRP_ID_MMI_CBM_APP);
    if (is_app_exist)
    {
        is_app_active = mmi_frm_group_is_in_active_serial(GRP_ID_MMI_CBM_APP);
        if (is_app_active)
        {
            return MMI_FALSE;
        }
        else
        {
            g_cbm_scr.callback = NULL;
            mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
            return MMI_TRUE;
        }
    }
    else
    {
        MMI_BOOL is_defer;

        is_defer = mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_DEFAULT, mmi_cbm_nmgr_expiry_callback, NULL);

        if (is_defer)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}


static mmi_ret mmi_cbm_reentry_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_NON_TONE,
        mmi_cbm_nmgr_expiry_callback,
        NULL);
    return MMI_RET_OK;
}


static mmi_ret mmi_cbm_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case CUI_WLAN_LIST_EVENT_RESULT_OK:
            if (g_cbm_scr.callback != NULL)
            {
                g_cbm_scr.callback(MMI_CBM_ITEM_USE_WLAN, g_cbm_scr.userdata);
                g_cbm_scr.callback = NULL;
            }
            mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
            break;

        case CUI_WLAN_LIST_EVENT_RESULT_CANCEL:
            if (g_cbm_scr.callback != NULL)
            {
            #ifdef __CBM_BEARER_SWITCH__
                if (g_cbm_scr.query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
                {
                    g_cbm_scr.callback(MMI_CBM_ITEM_USE_CELLULAR, g_cbm_scr.userdata);
                }
                else
            #endif /* __CBM_BEARER_SWITCH__ */
                {
                    g_cbm_scr.callback(MMI_CBM_ITEM_USE_CANCEL, g_cbm_scr.userdata);
                }
                g_cbm_scr.callback = NULL;
            }
            mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
            break;

        case CUI_WLAN_LIST_EVENT_RESULT_FAILED:
        case CUI_WLAN_LIST_EVENT_CLOSE:
            mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
            break;

        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            if (g_cbm_scr.reentry_callback)
            {
                g_cbm_scr.callback = g_cbm_scr.reentry_callback;
                g_cbm_scr.reentry_callback = NULL;
            }
            break;

        case EVT_ID_GROUP_DEINIT:
            if (g_cbm_scr.callback != NULL)
            {
            #ifdef __MMI_OP01_WIFI__
                if (g_cbm_scr.callback_item < MMI_CBM_ITEM_USE_TYPE_TOTAL)
                {
                    g_cbm_scr.callback(g_cbm_scr.callback_item, g_cbm_scr.userdata);
                }
                else
            #endif
                {
                #ifdef __CBM_BEARER_SWITCH__
                    if (g_cbm_scr.query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
                    {
                        g_cbm_scr.callback(MMI_CBM_ITEM_USE_CELLULAR, g_cbm_scr.userdata);
                    }
                    else
                #endif /* __CBM_BEARER_SWITCH__ */
                    {
                        g_cbm_scr.callback(MMI_CBM_ITEM_USE_CANCEL, g_cbm_scr.userdata);
                    }
                }
                g_cbm_scr.callback = NULL;
            }
            else if (g_cbm_scr.reentry_callback)
            {
                g_cbm_scr.callback = g_cbm_scr.reentry_callback;
                g_cbm_scr.reentry_callback = NULL;

                if (!g_mmi_cbm_reentry_defered)
                {
                    mmi_event_struct reentry_evt;

                    MMI_FRM_INIT_EVENT(&reentry_evt, 0);
                    MMI_FRM_POST_EVENT(&reentry_evt, mmi_cbm_reentry_callback, NULL);
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


static void mmi_cbm_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cbm_scr.hilight = index;
}


static void mmi_cbm_use_wlan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cbm_scr.auto_conn_wlan)
    {
        if (g_cbm_scr.callback != NULL)
        {
            g_cbm_scr.callback(MMI_CBM_ITEM_USE_WLAN, g_cbm_scr.userdata);
            g_cbm_scr.callback = NULL;
        }
        mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
    }
    else
    {
        g_cbm_scr.wlan_cui_id = cui_wlan_list_create(GRP_ID_MMI_CBM_APP, NULL);
        if(g_cbm_scr.wlan_cui_id != GRP_ID_INVALID)
        {
            cui_wlan_list_run(g_cbm_scr.wlan_cui_id);
        }
        mmi_frm_scrn_close(GRP_ID_MMI_CBM_APP, SCR_ID_MMI_CBM_NOTIFY);
    }
}


static void mmi_cbm_use_cellular(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_WIFI__
    if (g_cbm_scr.show_ask_cellular &&
        srv_cbm_get_ask_cellular_setting())
    {
        mmi_confirm_property_struct arg;

        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.parent_id = GRP_ID_MMI_CBM_APP;
        arg.callback  = (mmi_proc_func)mmi_cbm_ask_cellular_popup_callback;
        mmi_confirm_display_ext(
            STR_ID_MMI_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR_NO_MORE_ASK,
            MMI_EVENT_QUERY,
            &arg);

        g_cbm_scr.callback_item = MMI_CBM_ITEM_USE_CELLULAR;
    }
    else
#endif /* __MMI_OP01_WIFI__ */
    {
        if (g_cbm_scr.callback != NULL)
        {
            g_cbm_scr.callback(MMI_CBM_ITEM_USE_CELLULAR, g_cbm_scr.userdata);
            g_cbm_scr.callback = NULL;
        }
        mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
    }
}


static void mmi_cbm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_cbm_scr.hilight < g_cbm_scr.item_num);

    switch (g_cbm_scr.item_type[g_cbm_scr.hilight])
    {
        case MMI_CBM_ITEM_USE_WLAN:
            mmi_cbm_use_wlan();
            break;
        case MMI_CBM_ITEM_USE_CELLULAR:
            mmi_cbm_use_cellular();
            break;
    }
}


static void mmi_cbm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cbm_scr.callback != NULL)
    {
        g_cbm_scr.callback(MMI_CBM_ITEM_USE_CANCEL, g_cbm_scr.userdata);
        g_cbm_scr.callback = NULL;
    }
    mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
}


U8* mmi_cbm_item_type_to_str(mmi_cbm_item_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_CBM_ITEM_USE_WLAN)
    {
        return (U8*)GetString(STR_ID_MMI_CBM_USE_WLAN_NETWORK);
    }
    return (U8*)GetString(STR_ID_MMI_CBM_USE_CELLULAR);
}


static mmi_ret mmi_cbm_popup_callback(mmi_alert_result_evt_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_ALERT_QUIT &&
        param->result == MMI_ALERT_CNFM_OK)
    {
        g_cbm_scr.callback(MMI_CBM_ITEM_USE_CANCEL, g_cbm_scr.userdata);
        g_cbm_scr.callback = NULL;
        mmi_frm_group_close(GRP_ID_MMI_CBM_APP);
    }

    return MMI_RET_OK;
}


void mmi_cbm_launch_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 *guiBuffer;
    U8 *icon_items[2];
    U8 *text_items[MMI_CBM_CHOOSE_ITEM_MAX_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_MMI_CBM_APP,
        mmi_cbm_group_proc,
        NULL);

    mmi_frm_group_enter(GRP_ID_MMI_CBM_APP, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!mmi_frm_scrn_enter(
            GRP_ID_MMI_CBM_APP,
            SCR_ID_MMI_CBM_NOTIFY,
            NULL,
            mmi_cbm_launch_main,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    if (g_cbm_scr.item_num == 0)
    {
        mmi_confirm_property_struct arg;

        mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
        arg.parent_id = GRP_ID_MMI_CBM_APP;
        arg.callback  = (mmi_proc_func)mmi_cbm_popup_callback;
        mmi_confirm_display_ext(g_cbm_scr.title_str, MMI_EVENT_FAILURE, &arg);
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MMI_CBM_APP, SCR_ID_MMI_CBM_NOTIFY);

    RegisterHighlightHandler(mmi_cbm_highlight_handler);

    memset(icon_items, 0, sizeof(icon_items));

    MMI_ASSERT(g_cbm_scr.item_num <= MMI_CBM_CHOOSE_ITEM_MAX_NUM);

    for (i = 0; i < g_cbm_scr.item_num; ++i)
    {
        text_items[i] = mmi_cbm_item_type_to_str(g_cbm_scr.item_type[i]);
    }

    //ShowCategory32Screen(
    wgui_cat1049_show(
        (PU8)GetString(g_cbm_scr.title_str),
        STR_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        g_cbm_scr.item_num,
        text_items,
        icon_items,
        0,
        0,
        guiBuffer);
#ifndef __MMI_WGUI_DISABLE_CSK__ 
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetLeftSoftkeyFunction(mmi_cbm_yes_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cbm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_cbm_no_hdlr, KEY_EVENT_UP);
}


static MMI_BOOL mmi_cbm_nmgr_expiry_callback(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_cbm_is_wlan_query_needed())
    {
        g_cbm_scr.callback = NULL;
        OslMfree(g_mmi_cbm_cntx_ptr->wlan_query_evt);
        g_mmi_cbm_cntx_ptr->wlan_query_evt = NULL;
        return MMI_FALSE;
    }

    mmi_cbm_launch_main();
    return MMI_TRUE;
}


static void mmi_cbm_launch(mmi_cbm_parm_struct *parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_cbm_scr, 0, sizeof(g_cbm_scr));
    g_cbm_scr.query_type = parm->query_type;
    g_cbm_scr.title_str = parm->title_str;
    if (parm->show_wlan_item)
    {
        g_cbm_scr.item_type[g_cbm_scr.item_num] = MMI_CBM_ITEM_USE_WLAN;
        ++g_cbm_scr.item_num;
    }
    if (parm->show_cellular_item)
    {
        g_cbm_scr.item_type[g_cbm_scr.item_num] = MMI_CBM_ITEM_USE_CELLULAR;
        ++g_cbm_scr.item_num;
    }
    g_cbm_scr.callback = parm->callback;
    g_cbm_scr.userdata = parm->userdata;
    g_cbm_scr.auto_conn_wlan = parm->auto_conn_wlan;
#ifdef __MMI_OP01_WIFI__
    g_cbm_scr.show_ask_cellular = parm->show_ask_cellular;
    g_cbm_scr.callback_item = MMI_CBM_ITEM_USE_TYPE_TOTAL;
#endif /* __MMI_OP01_WIFI__ */
    g_cbm_scr.reentry_callback = NULL;

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT,
                               MMI_EVENT_NON_TONE,
                               mmi_cbm_nmgr_expiry_callback,
                               NULL);
}


static MMI_BOOL mmi_cbm_cellular_need_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_mode_switch_is_network_service_available() ||
        srv_mode_switch_is_switching() ||
    #ifdef __MMI_DATA_LOCK__
        !srv_data_lock_get_setting() ||
    #endif
        srv_sim_ctrl_get_num_of_inserted() == 0 ||
        !srv_sim_ctrl_any_sim_is_available() ||
        srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
        return MMI_FALSE;
    }
    else
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            sim_id = mmi_frm_index_to_sim(i);
            if (srv_sim_ctrl_is_available(sim_id) &&
                srv_mode_switch_get_network_mode(sim_id) == SRV_MODE_SWITCH_ON)
            {
                return MMI_TRUE;
            }
        }

        return MMI_FALSE;
    }
#else
    return MMI_FALSE; //No telephony, no need show cellular.
#endif /* __MMI_TELEPHONY_SUPPORT__ */

}


static void mmi_cbm_wlan_auto_conn_dummy_callback(mmi_wlan_auto_conn_action_enum action)
{
}


#ifdef __CBM_BEARER_SWITCH__
static void mmi_cbm_wlan_auto_conn_found_callback(mmi_wlan_auto_conn_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bearer_type = CBM_BEARER_WIFI;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_cbm_cntx_ptr->wlan_query_evt);

    if (action != WLAN_AUTO_CONN_ACTION_START)
    {
        bearer_type = CBM_BEARER_TOTAL;
    }

    g_mmi_cbm_cntx_ptr->wlan_query_evt->rsp_callback(bearer_type);
    OslMfree(g_mmi_cbm_cntx_ptr->wlan_query_evt);
    g_mmi_cbm_cntx_ptr->wlan_query_evt = NULL;
}
#endif /* __CBM_BEARER_SWITCH__ */


static void mmi_cbm_wlan_query_callback(mmi_cbm_item_type result, void* userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bearer_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_cbm_cntx_ptr->wlan_query_evt);

#ifdef __CBM_BEARER_SWITCH__
    if (g_mmi_cbm_cntx_ptr->wlan_query_evt->query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
    {
        if (result == MMI_CBM_ITEM_USE_WLAN &&
            g_mmi_cbm_cntx_ptr->auto_conn)
        {
            mmi_wlan_auto_conn_networks(mmi_cbm_wlan_auto_conn_found_callback);
            return;
        }
    }
#endif /* __CBM_BEARER_SWITCH__ */

    switch (result)
    {
        case MMI_CBM_ITEM_USE_WLAN:
            bearer_type = CBM_BEARER_WIFI;
            break;

        case MMI_CBM_ITEM_USE_CELLULAR:
            bearer_type = CBM_BEARER_PS;
            break;

        default:
            bearer_type = CBM_BEARER_NONE;
            break;
    }

    g_mmi_cbm_cntx_ptr->wlan_query_evt->rsp_callback(bearer_type);
    OslMfree(g_mmi_cbm_cntx_ptr->wlan_query_evt);
    g_mmi_cbm_cntx_ptr->wlan_query_evt = NULL;
}


#ifdef __CBM_BEARER_SWITCH__
static void mmi_cbm_wlan_auto_conn_callback(mmi_wlan_auto_conn_action_enum action)
{
    srv_cbm_wlan_query_evt_struct *evtPtr = g_mmi_cbm_cntx_ptr->wlan_query_evt;
    mmi_cbm_parm_struct param;
    U32 need_query;
    U32 bearer_type = CBM_BEARER_NONE;

    if (action == WLAN_AUTO_CONN_ACTION_START)
    {
        evtPtr->rsp_callback(CBM_BEARER_WIFI);
        OslMfree(g_mmi_cbm_cntx_ptr->wlan_query_evt);
        g_mmi_cbm_cntx_ptr->wlan_query_evt = NULL;
    }
    else
    {
        need_query = mmi_cbm_is_wlan_query_needed(evtPtr->query_type, 0, &bearer_type);
        if (need_query == MMI_CBM_RET_YES)
        {
            mmi_cbm_fill_wlan_query_param(&param, evtPtr->query_type, 0);
            mmi_cbm_launch(&param);
        }
        else if (need_query == MMI_CBM_RET_NO)
        {
            evtPtr->rsp_callback(bearer_type);
            OslMfree(g_mmi_cbm_cntx_ptr->wlan_query_evt);
            g_mmi_cbm_cntx_ptr->wlan_query_evt = NULL;
        }
    }
}
#endif /* __CBM_BEARER_SWITCH__ */


static S32 mmi_cbm_is_wlan_query_needed(
            srv_cbm_wlan_query_type_enum query_type,
            U8 ap_num,
            U32 *bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MMI_CBM_RET_YES;
    MMI_BOOL show_cellular;
    srv_dtcnt_wlan_state_enum wlan_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_state = srv_dtcnt_wlan_state();
    if (wlan_state == SRV_DTCNT_WLAN_STATE_NULL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_TOTAL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT)
    {
    #ifdef __CBM_BEARER_SWITCH__
        if (query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
        {
            *bearer_type = CBM_BEARER_TOTAL;
        }
        else
    #endif /* __CBM_BEARER_SWITCH__ */
        {
            *bearer_type = CBM_BEARER_NONE;
        }

        return MMI_CBM_RET_NO;
    }

    show_cellular = mmi_cbm_cellular_need_show();

    switch (query_type)
    {
        case SRV_CBM_WLAN_QUERY_TYPE_STARTUP:
        #ifdef __MMI_OP01_WIFI__
            if (ap_num == 0)
            {
                MMI_BOOL ask_cellular = srv_cbm_get_ask_cellular_setting();

                if (!show_cellular || !ask_cellular)
                {
                    if (show_cellular)
                    {
                        *bearer_type = CBM_BEARER_PS;
                    }
                    else
                    {
                        *bearer_type = CBM_BEARER_NONE;
                    }
                    ret = MMI_CBM_RET_NO;
                }
            }
        #else /* __MMI_OP01_WIFI__ */
            if (ap_num == 0)
            {
                if (show_cellular)
                {
                    *bearer_type = CBM_BEARER_PS;
                }
                else
                {
                    *bearer_type = CBM_BEARER_NONE;
                }
                ret = MMI_CBM_RET_NO;
            }
        #endif /* __MMI_OP01_WIFI__ */
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RECONNECT:
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            break;

    #ifdef __CBM_BEARER_SWITCH__
        case SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED:
            if (ap_num == 0)
            {
                if (!show_cellular)
                {
                    *bearer_type = CBM_BEARER_NONE;
                    ret = MMI_CBM_RET_NO;
                }
            }
            else
            {
                if (g_mmi_cbm_cntx_ptr->auto_conn)
                {
                    mmi_wlan_auto_conn_networks(mmi_cbm_wlan_auto_conn_callback);
                    ret = MMI_CBM_RET_WOULDBLOCK;
                }
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RESWITCH:
            if (g_mmi_cbm_cntx_ptr->auto_conn && !show_cellular)
            {
                *bearer_type = CBM_BEARER_NONE;
                ret = MMI_CBM_RET_NO;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_FOUND:
            if (ap_num == 0 || !g_mmi_cbm_cntx_ptr->need_notify)
            {
                if (ap_num != 0 && g_mmi_cbm_cntx_ptr->auto_conn)
                {
                    mmi_wlan_auto_conn_networks(mmi_cbm_wlan_auto_conn_found_callback);
                    ret = MMI_CBM_RET_WOULDBLOCK;
                }
                else
                {
                    *bearer_type = CBM_BEARER_TOTAL;
                    ret = MMI_CBM_RET_NO;
                }
            }
            break;
    #endif /* __CBM_BEARER_SWITCH__ */

        default:
            break;
    }

    return ret;
}


static void mmi_cbm_fill_wlan_query_param(
                mmi_cbm_parm_struct *param,
                srv_cbm_wlan_query_type_enum query_type,
                U8 ap_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param->query_type = query_type;
    param->title_str = 0;
    param->show_wlan_item = MMI_FALSE;
    param->show_cellular_item = mmi_cbm_cellular_need_show();
    param->auto_conn_wlan = g_mmi_cbm_cntx_ptr->auto_conn;
    param->callback = mmi_cbm_wlan_query_callback;
    param->userdata = NULL;
#ifdef __MMI_OP01_WIFI__
    param->show_ask_cellular = MMI_FALSE;
#endif

    switch (query_type)
    {
        case SRV_CBM_WLAN_QUERY_TYPE_STARTUP:
            if (ap_num == 0)
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR;
            #ifdef __MMI_OP01_WIFI__
                param->show_ask_cellular = MMI_TRUE;
            #endif
            }
            else
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_SIGNAL_AVAILABLE_USE_NOW;
                param->show_wlan_item = MMI_TRUE;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RECONNECT:
            if (ap_num != 0)
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED_USE_OTHER;
                param->show_wlan_item = MMI_TRUE;
            }
            else if (param->show_cellular_item)
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED_USE_CELLULAR;
            }
            else
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED;
            }
            break;

    #ifdef __CBM_BEARER_SWITCH__
        case SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED:
            if (ap_num != 0)
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_DISCONNECTED_USE_OTHER;
                param->show_wlan_item = MMI_TRUE;
            }
            else if (param->show_cellular_item)
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_DISCONNECTED_USE_CELLULAR;
            }
            else
            {
                param->title_str = STR_ID_MMI_CBM_WLAN_DISCONNECTED;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RESWITCH:
            if (g_mmi_cbm_cntx_ptr->auto_conn)
            {
                if (param->show_cellular_item)
                {
                    param->title_str = STR_ID_MMI_CBM_WLAN_DISCONNECTED_USE_CELLULAR;
                }
                else
                {
                    param->title_str = STR_ID_MMI_CBM_WLAN_DISCONNECTED;
                }
            }
            else
            {
                if (ap_num != 0)
                {
                    param->title_str = STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED_USE_OTHER;
                    param->show_wlan_item = MMI_TRUE;
                }
                else if (param->show_cellular_item)
                {
                    param->title_str = STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED_USE_CELLULAR;
                }
                else
                {
                    param->title_str = STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED;
                }
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_FOUND:
            param->title_str = STR_ID_MMI_CBM_WLAN_SIGNAL_AVAILABLE_WARNING;
            param->show_wlan_item = MMI_TRUE;
            param->show_cellular_item = MMI_FALSE;
            break;
    #endif /* __CBM_BEARER_SWITCH__ */

        default:
            break;
    }
}


static void mmi_cbm_wlan_scan_callback(
                U32 job_id,
                void *user_data,
                srv_dtcnt_wlan_scan_result_struct *scan_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_evt_struct *evt_ptr = g_mmi_cbm_cntx_ptr->wlan_query_evt;
    mmi_cbm_parm_struct param;
    S32 need_query;
    U32 bearer_type = CBM_BEARER_NONE;
    U8 wlan_ap_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_MMI_CBM_WLAN_SCAN_CALLBACK,
        scan_res->result,
        scan_res->ap_list_num,
        g_mmi_cbm_cntx_ptr->is_waiting_scan,
        (evt_ptr ? evt_ptr->query_type : -1));

    if (!g_mmi_cbm_cntx_ptr->is_waiting_scan)
    {
        return;
    }
    g_mmi_cbm_cntx_ptr->is_waiting_scan = MMI_FALSE;

    if (scan_res->result == SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS &&
        scan_res->ap_list_num > 0)
    {
        wlan_ap_num = srv_cbm_get_valid_wlan_ap_num(MMI_FALSE, scan_res);
    }

    need_query = mmi_cbm_is_wlan_query_needed(
                    evt_ptr->query_type,
                    wlan_ap_num,
                    &bearer_type);

    if (need_query == MMI_CBM_RET_YES)
    {
        mmi_cbm_fill_wlan_query_param(&param, evt_ptr->query_type, wlan_ap_num);
        mmi_cbm_launch(&param);
    }
    else if (need_query == MMI_CBM_RET_NO)
    {
        evt_ptr->rsp_callback(bearer_type);
        OslMfree(g_mmi_cbm_cntx_ptr->wlan_query_evt);
        g_mmi_cbm_cntx_ptr->wlan_query_evt = NULL;
    }
}

#endif /* __MMI_WLAN_FEATURES__ */

#endif /* #ifdef __TCPIP__ */

