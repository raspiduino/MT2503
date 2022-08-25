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
 *  SsUi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS (Supplementary Service) application user interface
 *
 * Author:
 * -------
 * 
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
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/

#include "MMI_features.h"

#include "Menucuigprot.h"
#include "SsProt.h"
#include "SsCore.h"
#include "mmi_rp_app_ss_def.h"

#include "SsSrvGprot.h"
#include "UcmSrvGprot.h"
#include "UcmGprot.h" /* EVT_ID_UCM_CLOSE_GRP_QUERY */
#include "ProfilesSrvGprot.h" /* srv_prof_if_can_vibrate, srv_prof_play_tone, srv_profiles_stop_tone */
#include "FSEditorCuiGprot.h"
#include "Dmuigprot.h" /* mmi_dmui_is_phone_lock */
#include "Custom_ussd.h" /* ussd_custom_get_request_code */

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */

#include "string.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "kal_non_specific_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_features.h"
#include "custom_led_patterns.h"
#include "l4c_common_enum.h"
#include "mmi_frm_timer_gprot.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "NotificationGprot.h"
#include "wgui_categories_list.h"
#include "gpiosrvgprot.h"
#include "mdi_audio.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "mmi_cb_mgr_gprot.h"
#include "wgui_categories_CM.h"
#include "gui_inputs.h"
#include "UseDetailCuiGprot.h"
#include "mmi_frm_utility_gprot.h"   /* For MMI_SIM_TOTAL & MMI_SIM_ALL */
#include "NetSetAppGprot.h"
#include "SimCtrlSrvGprot.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static mmi_ret mmi_ss_proc_common(mmi_event_struct *evt);
static mmi_ret mmi_ss_proc_sim(mmi_event_struct *evt);
static mmi_ret mmi_ss_proc_grp_ussr(mmi_event_struct *evt);
static mmi_ret mmi_ss_proc_requesting(mmi_event_struct *evt);
static mmi_ret mmi_ss_proc_ussr(mmi_event_struct *evt);
static mmi_ret mmi_ss_proc_ussn(mmi_event_struct *evt);
static mmi_ret mmi_ss_proc_result(mmi_event_struct *evt);
static void mmi_ss_sel_type(void* evt);
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
static void mmi_ss_entry_sim_select(mmi_sim_enum target_sim, mmi_ss_send_struct *send_evt);
static void mmi_ss_add_sim_name(mmi_id owner_gid);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
static void mmi_ss_sim_highlight_hdlr(void* evt);
static void mmi_ss_sel_type_hdlr(void);
static mmi_ret mmi_ss_hdlr_rsp_type_select(mmi_event_struct* info);
static FuncPtr mmi_ss_get_ussr_timeout_hdlr(mmi_sim_enum sim);
static void mmi_ss_hdlr_ussr_timeout(void);
#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_ss_hdlr_ussr_timeout_sim2(void);
#if (MMI_MAX_SIM_NUM >= 3)
static void mmi_ss_hdlr_ussr_timeout_sim3(void);
#if (MMI_MAX_SIM_NUM == 4)
static void mmi_ss_hdlr_ussr_timeout_sim4(void);
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
static void mmi_ss_abort_at_screen_deinit(mmi_sim_enum sim);
static void mmi_ss_op_reg_adj_grp_cb(mmi_sim_enum sim);
static void mmi_ss_op_dereg_adj_grp_cb(mmi_sim_enum sim);
static mmi_ret mmi_ss_op_adjust_group(mmi_event_struct * evt);
static void mmi_ss_hdlr_abort(void);
static void mmi_ss_op_abort(mmi_sim_enum sim, MMI_BOOL local_rel);
static void mmi_ss_op_start_action(void* info);
static void mmi_ss_op_end_action(void* info);
static void mmi_ss_op_ussr(void* info);
static void mmi_ss_op_ussn(void* info);
#ifdef __MMI_RECEIVE_USSD_TONE__
static void mmi_ss_op_play_ussd_alert(srv_ss_direction_enum dir);
#endif /* __MMI_RECEIVE_USSD_TONE__ */
static srv_ss_result_enum mmi_ss_op_send(mmi_sim_enum sim, U8 len, WCHAR *str, mmi_proc_func rsp_cb, void *user_data);
static MMI_BOOL mmi_ss_op_start_action_cb(mmi_scenario_id scen_id, void *arg);
static MMI_BOOL mmi_ss_op_end_action_cb(mmi_scenario_id scen_id, void *arg);
static MMI_BOOL mmi_ss_op_ussr_cb(mmi_scenario_id scen_id, void *arg);
static MMI_BOOL mmi_ss_op_ussn_cb(mmi_scenario_id scen_id, void *arg);
static MMI_ID mmi_ss_create_sim_group(mmi_sim_enum sim);
static void mmi_ss_pre_entry_dummy(MMI_ID group_id, MMI_ID scrn_id);
static void mmi_ss_entry_dummy(MMI_ID gid);
static void mmi_ss_entry_requesting(mmi_scrn_essential_struct *data);
static void mmi_ss_entry_result(mmi_scrn_essential_struct *data);
static void mmi_ss_entry_ussr(mmi_scrn_essential_struct *data);
static void mmi_ss_entry_ussn(mmi_scrn_essential_struct *data);
static void mmi_ss_entry_edit_ussr(void);
static void mmi_ss_hdlr_ussr_edit_empty(mmi_id gid);
static void mmi_ss_hdlr_ussr_edit_not_empty(mmi_id gid);
static void mmi_ss_hdlr_ussr_edit_done(mmi_id gid);
static mmi_id mmi_ss_get_ussr_gid_by_sim(mmi_sim_enum sim);
static mmi_id mmi_ss_get_gid_by_sim(mmi_sim_enum sim);
static mmi_sim_enum mmi_ss_get_sim_by_gid(mmi_id gid);
#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
static void mmi_ss_ussd_pre_use_detail_info(void);
static void mmi_ss_ussd_use_detail_info(S32 idx);
static void mmi_ss_ussd_set_hilight_info(void);
static void mmi_ss_ussd_hilite_cb(S32 idx);
static void mmi_ss_ussd_click_cb(S32 idx);
static mmi_sim_enum mmi_ss_ussd_get_current_sim(void);
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */
static void mmi_ss_op_defer(mmi_sim_enum sim, mmi_noti_scrn_func_ptr func_p, void *data);
static void mmi_ss_reset_defer(mmi_sim_enum sim);
static void mmi_ss_op_cancel_defer(mmi_sim_enum sim);
static void mmi_ss_result_proceed(mmi_sim_enum sim);
static void mmi_ss_op_scrn_proceed(mmi_sim_enum sim);
static void mmi_ss_op_scrn_proceed_ex(mmi_sim_enum sim, MMI_ID scrn_id);
static void mmi_ss_reset_proceed(mmi_sim_enum sim);
static void mmi_ss_display_error_popup_by_result(srv_ss_result_enum result);
static void mmi_ss_display_error_popup_by_id(MMI_STR_ID title);
static void mmi_ss_clear_vol_key_handler(void);


/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
#if (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
cui_menu_event_struct g_highlight_menu_info;
#endif /* (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */


/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_request_from_menu
 * DESCRIPTION
 *  send ussd from menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_ussd_request_from_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_operation_req_struct req;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_ss_operation_req_struct));
    req.sim = MMI_SIM1;
    mmi_asc_to_ucs2((CHAR*)req.string, (CHAR*)ussd_custom_get_request_code());
    
    result = srv_ss_act_req(SRV_SS_ACT_SS_OPERATION, &req, NULL, NULL);
    mmi_ss_display_error_popup_by_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_common
 * DESCRIPTION
 *  process for ss common screen group (GRP_ID_SS_COMMON)
 * PARAMETERS
 *  evt     [IN]    event data
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ss_proc_common(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
#endif /* (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
#if (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    cui_sim_sel_result_event_struct* sim_sel_evt = (cui_sim_sel_result_event_struct*)evt;
#endif /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
    #if (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
       /* menu event */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (menu_evt->parent_menu_id == MENU_ID_SS_TYPE_SELECT)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                mmi_ss_add_sim_name(menu_evt->sender_id);
            #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            mmi_ss_sim_highlight_hdlr((void *)menu_evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->parent_menu_id == MENU_ID_SS_TYPE_SELECT)
            {
                mmi_ss_sel_type((void *)menu_evt);
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_LIST_DEINIT:
            MMI_ASSERT(menu_evt->app_data);
            OslMfree(menu_evt->app_data);
            break;
    #endif /* (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

    #if (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        /* sim select event */
        case EVT_ID_CUI_SIM_SEL_RESULT:
            if (sim_sel_evt->result == CUI_SIM_SEL_OK)
            {
                mmi_ss_sel_type((void *)sim_sel_evt);
            }
            else if (sim_sel_evt->result == CUI_SIM_SEL_ABORT)
            {
                MMI_ASSERT(sim_sel_evt->parent_data);
                cui_sim_sel_close(sim_sel_evt->sender_id);
                OslMfree(sim_sel_evt->parent_data);
            }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

        /* ucm event */
        case EVT_ID_UCM_CLOSE_GRP_QUERY:
            return 1;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_sim
 * DESCRIPTION
 *  process for ss sim screen group (GRP_ID_SS_SIM1 / GRP_ID_SS_SIM2)
 * PARAMETERS
 *  evt     [IN]    event data
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ss_proc_sim(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *group_evt = (mmi_scenario_evt_struct*)evt;
#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
    cui_use_detail_result_event_struct *use_detail_evt = (cui_use_detail_result_event_struct *)evt;
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* SG event */
        case EVT_ID_GROUP_DEINIT:
//            MI_ASSERT(grp_info);
            mmi_ss_op_dereg_adj_grp_cb(mmi_ss_get_sim_by_gid(group_evt->targ_group));
//            OslMfree(grp_info);
            break;

    #ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
        case EVT_ID_CUI_USE_DETAIL_RESULT:
            cui_use_detail_close(use_detail_evt->sender_id);
            break;
    #endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

        /* ucm event */
        case EVT_ID_UCM_CLOSE_GRP_QUERY:
            return 1;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_grp_ussr
 * DESCRIPTION
 *  process for ussr screen group (GRP_ID_SS_SIM1_USSR / GRP_ID_SS_SIM2_USSR)
 * PARAMETERS
 *  evt     [IN]    event data
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ss_proc_grp_ussr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct *fsedit_evt = (cui_fseditor_evt_struct*)evt;
#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
    cui_use_detail_result_event_struct *use_detail_evt = (cui_use_detail_result_event_struct *)evt;
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* SG event */
//        case EVT_ID_GROUP_DEINIT:
//            MMI_ASSERT(grp_info);
//            OslMfree(grp_info);
//            break;

        /* FS editor event */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            mmi_ss_hdlr_ussr_edit_done(fsedit_evt->sender_id);
            break;

        case EVT_ID_CUI_FSEDITOR_EMPTY:
            mmi_ss_hdlr_ussr_edit_empty(fsedit_evt->sender_id);
            break;

        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            mmi_ss_hdlr_ussr_edit_not_empty(fsedit_evt->sender_id);
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(fsedit_evt->sender_id);
            break;

    #ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
        case EVT_ID_CUI_USE_DETAIL_RESULT:
            cui_use_detail_close(use_detail_evt->sender_id);
            break;
    #endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

        /* ucm event */
        case EVT_ID_UCM_CLOSE_GRP_QUERY:
            return 1;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_requesting
 * DESCRIPTION
 *  process for ss requesting screen
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_ss_proc_requesting(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(evt->user_data);
//    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            MMI_ASSERT(scrn_info);
            mmi_ss_abort_at_screen_deinit(scrn_info->sim);
            OslMfree(scrn_info);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_ussr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_ss_proc_ussr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(evt->user_data);
//    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
    #ifdef __MMI_RECEIVE_USSD_TONE__
        case EVT_ID_SCRN_INACTIVE:
            srv_vibrator_off();
            srv_profiles_stop_tone(SRV_PROF_TONE_WARNING);
            break;
        #endif /* __MMI_RECEIVE_USSD_TONE__ */

        case EVT_ID_SCRN_DEINIT:
            MMI_ASSERT(scrn_info);
            MMI_ASSERT(scrn_info->data);
            mmi_ss_abort_at_screen_deinit(scrn_info->sim);
            OslMfree(scrn_info->data);
            OslMfree(scrn_info);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_ussn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_ss_proc_ussn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(evt->user_data);
//    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
    #ifdef __MMI_RECEIVE_USSD_TONE__
        case EVT_ID_SCRN_INACTIVE:
            srv_vibrator_off();
            srv_profiles_stop_tone(SRV_PROF_TONE_WARNING);
            break;
    #endif /* __MMI_RECEIVE_USSD_TONE__ */

        case EVT_ID_SCRN_DEINIT:
            MMI_ASSERT(scrn_info);
            MMI_ASSERT(scrn_info->data);
            mmi_ss_reset_proceed(scrn_info->sim);
            OslMfree(scrn_info->data);
            OslMfree(scrn_info);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_proc_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_RET_ALLOW_CLOSE
 *****************************************************************************/
mmi_ret mmi_ss_proc_result(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(evt->user_data);
//    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        /* screen event */
        case EVT_ID_SCRN_DEINIT:
            MMI_ASSERT(scrn_info);
            MMI_ASSERT(scrn_info->data);
            mmi_ss_reset_proceed(scrn_info->sim);
            OslMfree(scrn_info->data);
            OslMfree(scrn_info);
            break;

        default:
            break;
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_intercept
 * DESCRIPTION
 *  This function is to intercept outgoing call, if the number is ss string
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  SRV_UCM_INTERCEPT_QUERY_RESULT_YES means the number is ss; 
 *  SRV_UCM_INTERCEPT_QUERY_RESULT_NO means the number is not ss.
 *****************************************************************************/
mmi_ret mmi_ss_intercept(mmi_event_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_intercept_query_evt_struct *evt = (srv_ucm_intercept_query_evt_struct*)info;
    U8 length, i, sim_total = 0;
    WCHAR ucs2_str[SRV_SS_MAX_LENGTH + 1];
    mmi_sim_enum target_sim, sim_id, first_sim = MMI_SIM_NONE;
    srv_ss_result_enum result;
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_ss_send_struct *send_evt;
#if (MMI_MAX_SIM_NUM != 2)
    MMI_ID sim_sel_gid;
#endif /* (MMI_MAX_SIM_NUM != 2) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    target_sim = mmi_ss_get_sim_by_ucm_call_type(evt->call_type);
    mmi_asc_n_to_ucs2((CHAR*)ucs2_str, (CHAR*)(evt->num_uri), SRV_SS_MAX_LENGTH);
    length = (U8)mmi_ucs2strlen((CHAR*)ucs2_str);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (!srv_ss_is_valid_ss_string(sim_id, length, ucs2_str))
        {
            target_sim &= (~sim_id);
        }
        else if (!first_sim)
        {
            first_sim = (mmi_sim_enum)(sim_id & target_sim);
        }
    }

    if ((evt->module_id == SRV_UCM_MODULE_ORIGIN_AT) || 
    #if (MMI_MAX_SIM_NUM >= 2)
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM2) ||
    #if (MMI_MAX_SIM_NUM >= 3)
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM3) ||
    #if (MMI_MAX_SIM_NUM == 4)
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM4) ||
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_SAT) ||
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_CCBS) ||
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_VOICE_MAIL) || 
        !target_sim)
    {
        return SRV_UCM_INTERCEPT_QUERY_RESULT_NO;
    }

    /* intercept */
#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        mmi_ss_display_error_popup_by_id(STR_GLOBAL_NOT_AVAILABLE);
        return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (!srv_ss_is_available(sim_id))
        {
            target_sim &= (~sim_id);
        }
        else if (target_sim & sim_id)
        {
            sim_total++;
        }
    }

    switch (sim_total)
    {
        case 0:
            target_sim = first_sim;
        case 1:
        result = mmi_ss_op_send(target_sim, length, ucs2_str, NULL, NULL);
            mmi_ss_display_error_popup_by_result(result);
            break;

#if (MMI_MAX_SIM_NUM >= 2)
        default:  /* sim_total > 1  */
            /* multiple sims are available */
            if (mmi_frm_group_is_present(GRP_ID_SS_COMMON))
            {
                mmi_frm_group_close(GRP_ID_SS_COMMON);
            }

            send_evt = OslMalloc(sizeof(mmi_ss_send_struct));
            mmi_ucs2cpy((CHAR*)send_evt->string, (CHAR*)ucs2_str);
            mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_SS_COMMON, mmi_ss_proc_common, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            mmi_ss_entry_sim_select(target_sim, send_evt);
        #else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
        #if (MMI_MAX_SIM_NUM == 2)
            cui_menu_create_and_run(
                GRP_ID_SS_COMMON,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_ID_SS_TYPE_SELECT,
                MMI_TRUE,
                send_evt);
        #else /* (MMI_MAX_SIM_NUM == 2) */
            sim_sel_gid = cui_sim_sel_create(GRP_ID_SS_COMMON, target_sim, send_evt);
            cui_sim_sel_run(sim_sel_gid);
        #endif /* (MMI_MAX_SIM_NUM == 2) */
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
            break;            
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    }

    return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_sim_select
 * DESCRIPTION
 *  Enter sim select screen
 * PARAMETERS
 *  target_sim       [IN]    avaliable sim
 *  send_evt         [IN]    send event data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_entry_sim_select(mmi_sim_enum target_sim, mmi_ss_send_struct *send_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_id menu_id;
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    menu_id = cui_menu_create(
                GRP_ID_SS_COMMON,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_ID_SS_TYPE_SELECT,
                MMI_TRUE,
                send_evt);

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (target_sim & sim_id)
        {
            cui_menu_set_item_hidden(menu_id, MENU_ID_SS_SIM1 + i, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_id, MENU_ID_SS_SIM1 + i, MMI_TRUE);
        }
    }

    cui_menu_run(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_add_sim_name
 * DESCRIPTION
 *  Set menu item string with SIM name
 * PARAMETERS
 *  owner_gid       [IN]    Menu GID from cui_menu_create
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_add_sim_name(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    WCHAR *sim_name;
    WCHAR menu_str[MAX_SUBMENU_CHARACTERS];
    U16 sim_string[] = {STR_GLOBAL_SIM_1, STR_GLOBAL_SIM_2, STR_GLOBAL_SIM_3, STR_GLOBAL_SIM_4};
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        sim_name = mmi_netset_get_sim_name(sim_id);
        if (sim_name)
        {
            kal_wsprintf(menu_str, "%w(%w)", GetString(sim_string[i]), sim_name);
            cui_menu_set_item_string(owner_gid, MENU_ID_SS_SIM1 + i, menu_str);
        }
    }
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_sim_highlight_hdlr
 * DESCRIPTION
 *  set sim select highlight handler
 * PARAMETERS
 *  evt     [IN]    event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_sim_highlight_hdlr(void* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
#endif /* (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    memcpy(&g_highlight_menu_info, menu_evt, sizeof(cui_menu_event_struct));
    SetKeyUpHandler(mmi_ss_sel_type_hdlr, KEY_SEND);
#endif /* (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_sel_type_hdlr
 * DESCRIPTION
 *  send ss
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_sel_type_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    mmi_ss_sel_type(&g_highlight_menu_info);
#endif /* (MMI_MAX_SIM_NUM == 2) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_sel_type
 * DESCRIPTION
 *  send ss
 * PARAMETERS
 *  evt     [IN]    event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_sel_type(void* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    cui_sim_sel_result_event_struct *sim_sel_result = (cui_sim_sel_result_event_struct*)evt;
    mmi_ss_send_struct *send_info = (mmi_ss_send_struct*)(sim_sel_result->parent_data);
#else /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ss_send_struct *send_info = (mmi_ss_send_struct*)(menu_evt->app_data);
#endif /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
    srv_ss_result_enum result = SRV_SS_RESULT_UNSPECIFIED_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#if (MMI_MAX_SIM_NUM >= 2)
    if (menu_evt->highlighted_menu_id == MENU_ID_SS_SIM1)
    {
        result = mmi_ss_op_send(MMI_SIM1, (U8)mmi_ucs2strlen((CHAR*)send_info->string), send_info->string, NULL, NULL);
    }
    else if (menu_evt->highlighted_menu_id == MENU_ID_SS_SIM2)
    {
        result = mmi_ss_op_send(MMI_SIM2, (U8)mmi_ucs2strlen((CHAR*)send_info->string), send_info->string, NULL, NULL);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (menu_evt->highlighted_menu_id == MENU_ID_SS_SIM3)
    {
        result = mmi_ss_op_send(MMI_SIM3, (U8)mmi_ucs2strlen((CHAR*)send_info->string), send_info->string, NULL, NULL);
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (menu_evt->highlighted_menu_id == MENU_ID_SS_SIM4)
    {
        result = mmi_ss_op_send(MMI_SIM4, (U8)mmi_ucs2strlen((CHAR*)send_info->string), send_info->string, NULL, NULL);
    }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#if (MMI_MAX_SIM_NUM >= 3)
    result = mmi_ss_op_send(sim_sel_result->sim_id,
                    (U8)mmi_ucs2strlen((CHAR*)send_info->string),
                    send_info->string,
                    NULL, NULL);
#else /* (MMI_MAX_SIM_NUM >= 3) */
    if (menu_evt->highlighted_menu_id == MENU_ID_SS_SIM1 ||
        menu_evt->highlighted_menu_id == MENU_ID_SS_SIM2)
    {
        result = mmi_ss_op_send(
            (mmi_sim_enum)(MMI_SIM1 << (menu_evt->highlighted_menu_id - MENU_ID_SS_SIM1)),
            (U8)mmi_ucs2strlen((CHAR*)send_info->string),
            send_info->string,
            NULL,
            NULL);
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    if (result == SRV_SS_RESULT_OK)
    {
        /* Close the SIM selector CUI or Menu CUI */
    #if (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        cui_sim_sel_close(sim_sel_result->sender_id);
//        OslMfree(send_info);
    #else /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
        cui_menu_close(menu_evt->sender_id);
//        OslMfree(send_info);
    #endif /* (MMI_MAX_SIM_NUM >= 3) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */ 
    }
    else
    {
        mmi_ss_display_error_popup_by_result(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_act_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ss_hdlr_act_notify(mmi_event_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_notify_evt_struct *evt = (srv_ss_act_notify_evt_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        return MMI_RET_OK;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    switch (evt->type)
    {
        case SRV_SS_ACT_NOTIFY_START:
            mmi_ss_op_start_action(evt);
            break;

        case SRV_SS_ACT_NOTIFY_END:
            mmi_ss_op_end_action(evt);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ss_hdlr_ind(mmi_event_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ind_evt_struct *evt = (srv_ss_ind_evt_struct*)info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        if (evt->ind_type == SRV_SS_IND_USSR)
        {
            mmi_ss_op_abort(evt->sim, MMI_TRUE);
        }
        return MMI_RET_OK;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    switch (evt->ind_type)
    {
        case SRV_SS_IND_USSR:
            mmi_ss_op_ussr(evt);
            break;

        case SRV_SS_IND_USSN:
            mmi_ss_op_ussn(evt);
            break;

        case SRV_SS_IND_ABORT:
            mmi_ss_op_abort(evt->sim, MMI_FALSE);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_rsp_type_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ss_hdlr_rsp_type_select(mmi_event_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_timeout
 * DESCRIPTION
 *  ss timeout handler for sim1
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_hdlr_ussr_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_display_error_popup_by_id(STR_GLOBAL_NOT_AVAILABLE);
    mmi_ss_op_abort(MMI_SIM1, MMI_TRUE);
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_timeout_sim2
 * DESCRIPTION
 *  ss timeout handler for sim2
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_hdlr_ussr_timeout_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_display_error_popup_by_id(STR_GLOBAL_NOT_AVAILABLE);
    mmi_ss_op_abort(MMI_SIM2, MMI_TRUE);
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_timeout_sim3
 * DESCRIPTION
 *  ss timeout handler for sim3
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_hdlr_ussr_timeout_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_display_error_popup_by_id(STR_GLOBAL_NOT_AVAILABLE);
    mmi_ss_op_abort(MMI_SIM3, MMI_TRUE);
}


#if (MMI_MAX_SIM_NUM == 4)
/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_timeout_sim4
 * DESCRIPTION
 *  ss timeout handler for sim4
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_hdlr_ussr_timeout_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_display_error_popup_by_id(STR_GLOBAL_NOT_AVAILABLE);
    mmi_ss_op_abort(MMI_SIM4, MMI_TRUE);
}
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_edit_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_hdlr_ussr_edit_empty(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_fseditor_set_custom_options_menu(gid, MMI_TRUE, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_edit_not_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_hdlr_ussr_edit_not_empty(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_fseditor_set_custom_options_menu(gid, MMI_FALSE, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ussr_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid     [IN]    FS editor group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_hdlr_ussr_edit_done(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info;
    mmi_ss_ussr_struct *ussr_info;
    S32 len = 0;
    srv_ss_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_USSR_TIMER__  
    StopTimer(USSR_SESSION_TIMER);
#endif /* __MMI_USSR_TIMER__ */

#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
    /* allow to send empty string */
    scrn_info = (mmi_ss_scrn_info_struct*)mmi_frm_scrn_get_user_data(
            mmi_frm_group_get_active_id(), 
            mmi_frm_scrn_get_active_id());
    MMI_ASSERT(scrn_info);
    ussr_info = (mmi_ss_ussr_struct*)(scrn_info->data);
    MMI_ASSERT(ussr_info);
    len = mmi_ucs2strlen((CHAR*)ussr_info->reply_buf);
#else /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */
    /* NOT allow to send empty string */
    scrn_info = (mmi_ss_scrn_info_struct*)cui_fseditor_get_parent_data(gid);
    MMI_ASSERT(scrn_info);
    ussr_info = (mmi_ss_ussr_struct*)(scrn_info->data);
    MMI_ASSERT(ussr_info);
    len = cui_fseditor_get_text(gid, ussr_info->reply_buf, sizeof(ussr_info->reply_buf));
    MMI_ASSERT(len);
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

    result = mmi_ss_op_send(
        scrn_info->sim, 
        (U8)len, 
        ussr_info->reply_buf, 
        NULL, 
        NULL);

    mmi_ss_display_error_popup_by_result(result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_abort
 * DESCRIPTION
 *  ss abort by user operation
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_hdlr_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* must be triggerred by the active screen (key event) */

    scrn_info = (mmi_ss_scrn_info_struct*)mmi_frm_scrn_get_user_data(
                    mmi_frm_group_get_active_id(), 
                    mmi_frm_scrn_get_active_id());

    MMI_ASSERT(scrn_info);

    mmi_ss_op_abort(scrn_info->sim, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_hdlr_ucm_call_status_change
 * DESCRIPTION
 *  UCM call status change event handler
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_ss_hdlr_ucm_call_status_change(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_adjust_grp_evt_struct adj_evt;
    mmi_ss_grp_info_struct *grp_info = (mmi_ss_grp_info_struct*)(evt->user_data);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&adj_evt, EVT_ID_MMI_SS_ADJUST_GRP);
    adj_evt.sim = grp_info->sim;
    MMI_FRM_POST_EVENT(
        &adj_evt, 
        mmi_ss_op_adjust_group, 
        NULL);    

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_start_action
 * DESCRIPTION
 *  This function is to intercept outgoing call, if the number is ss string
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  SRV_UCM_INTERCEPT_QUERY_RESULT_YES means the number is short string crss; 
 *  SRV_UCM_INTERCEPT_QUERY_RESULT_NO means the number is not short string crss.
 *****************************************************************************/
void mmi_ss_op_start_action(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_notify_evt_struct *evt = (srv_ss_act_notify_evt_struct*)info;
    srv_ss_act_req_struct *req = (srv_ss_act_req_struct*)(evt->info);
    mmi_ss_act_start_struct *data;
//    mmi_ss_scr_defer_struct defer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (req->source)
    {
        /* display ss screen by other app */
        return;
    }

    if (evt->act_op == SRV_SS_ACT_ABORT)
    {
        return;
    }

    if (mmi_ss_cntx_get_curr_op(req->sim) != SRV_SS_ACT_IDLE)
    {
        /* abnormal! */
        /* ignore */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_SS_OP_START_ACTION_IGNORE);
        return;
    }

    mmi_ss_cntx_set_curr_op(req->sim, evt->act_op);

    data = OslMalloc(sizeof(mmi_ss_act_start_struct));
    data->act_op = evt->act_op;
    data->req_info = mmi_ss_copy_act_req(evt->act_op, evt->info);

    mmi_ss_op_defer(req->sim, mmi_ss_op_start_action_cb, (void *)data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_start_action_cb
 * DESCRIPTION
 *  call back to display the processing screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ss_op_start_action_cb(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_act_start_struct *data = (mmi_ss_act_start_struct*)arg;
    srv_ss_act_req_struct *req = (srv_ss_act_req_struct*)(data->req_info);
    mmi_ss_scrn_info_struct *scrn_info;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!data || !req)
    {
        /* invalid input */
        MMI_ASSERT(0);
    }

    mmi_ss_reset_defer(req->sim);

    /* requesting screen */
    gid = mmi_ss_create_sim_group(req->sim);

    mmi_ss_pre_entry_dummy(gid, SCR_ID_SS_REQUESTING);

    scrn_info = (mmi_ss_scrn_info_struct*)OslMalloc(sizeof(mmi_ss_scrn_info_struct));
    scrn_info->sim = req->sim;
    scrn_info->data = NULL;

    /* user_data is reserved, not used for now */
    mmi_frm_scrn_first_enter(gid, SCR_ID_SS_REQUESTING, (FuncPtr)mmi_ss_entry_requesting, scrn_info);

    OslMfree(data->req_info);
    OslMfree(data);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_end_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_end_action(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_notify_evt_struct *evt = (srv_ss_act_notify_evt_struct*)info;
    srv_ss_rsp_struct *rsp = (srv_ss_rsp_struct*)(evt->info);
    srv_ss_ussd_rsp_struct *ussd_rsp = (srv_ss_ussd_rsp_struct*)(rsp->data);
    srv_ss_rsp_struct *rsp_info;
    srv_ss_act_enum op = mmi_ss_cntx_get_curr_op(rsp->sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(rsp);

    if (op == SRV_SS_ACT_IDLE)
    {
        /* no requesting screen, ignore the action_end event */
        return;
    }

    if (op != evt->act_op)
    {
        /* ignore abnormal msg */
        return;
    }

    if ((rsp->opcode == SRV_SS_ACT_USSD) &&
        (rsp->result == SRV_SS_RESULT_OK) &&
        !(ussd_rsp->end_of_session))
    {
        /* don't display the result, wait for the following ss msg (ussn / ussr...) */
        return;
    }

    rsp_info = OslMalloc(sizeof(srv_ss_rsp_struct));
    memcpy(rsp_info, rsp, sizeof(srv_ss_rsp_struct));
    rsp_info->data = mmi_ss_copy_act_rsp(rsp->opcode, rsp->data);
    mmi_ss_op_defer(rsp->sim, mmi_ss_op_end_action_cb, (void*)rsp_info);

    mmi_ss_cntx_set_curr_op(rsp->sim, SRV_SS_ACT_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_end_action_cb
 * DESCRIPTION
 *  call back to display the processing screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ss_op_end_action_cb(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_rsp_struct *rsp = (srv_ss_rsp_struct*)arg;
    mmi_ss_scrn_info_struct *scrn_info;
    mmi_ss_result_struct *result;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!rsp)
    {
        /* invalid input */
        MMI_ASSERT(0);
    }

    mmi_ss_reset_defer(rsp->sim);

    /* SIM group */
    gid = mmi_ss_create_sim_group(rsp->sim);

    mmi_ss_pre_entry_dummy(gid, SCR_ID_SS_RESULT);

    /* result screen */
    scrn_info = OslMalloc(sizeof(mmi_ss_scrn_info_struct));
    scrn_info->sim = rsp->sim;
    result = OslMalloc(sizeof(mmi_ss_result_struct));
    mmi_ss_derive_result(rsp, result);
    scrn_info->data = result;

    /* user_data is reserved, not used for now */
    mmi_frm_scrn_first_enter(gid, SCR_ID_SS_RESULT, (FuncPtr)mmi_ss_entry_result, scrn_info);

    if (rsp->data)
    {
        OslMfree(rsp->data);
    }

    OslMfree(rsp);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_ussr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_ussr(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ind_evt_struct *evt = (srv_ss_ind_evt_struct*)info;
    srv_ss_ussr_ind_struct *ind = (srv_ss_ussr_ind_struct*)(evt->data);
    mmi_ss_scrn_info_struct *scrn_info;
    mmi_ss_ussr_struct *ussr_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->source != SRV_SS_SRC_COMMON)
    {
        /* display ss screen by other app */
        return;
    }

#ifdef __MMI_USSR_TIMER__  
     /* Auto expire after 3 mins if network has no action */
     StartTimer(USSR_SESSION_TIMER, 180000, mmi_ss_get_ussr_timeout_hdlr(evt->sim));
#endif /* __MMI_USSR_TIMER__ */

    scrn_info = OslMalloc(sizeof(mmi_ss_scrn_info_struct));
    scrn_info->sim = evt->sim;
    ussr_info = OslMalloc(sizeof(mmi_ss_ussr_struct));
    ussr_info->direction = ind->direction;
    mmi_ucs2ncpy((CHAR*)ussr_info->display_buf, (CHAR*)ind->string, SRV_SS_MAX_LENGTH);
    scrn_info->data = (void*)ussr_info;

    mmi_ss_op_defer(evt->sim, mmi_ss_op_ussr_cb, (void*)scrn_info);

    if (mmi_ss_cntx_get_curr_op(evt->sim) == SRV_SS_ACT_SS_OPERATION)
    {
        /* end the requesting screen */
        mmi_ss_cntx_set_curr_op(evt->sim, SRV_SS_ACT_IDLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_ussr_cb
 * DESCRIPTION
 *  call back to display the ussr screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ss_op_ussr_cb(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *data = (mmi_ss_scrn_info_struct*)arg;
    mmi_ss_scrn_info_struct *scrn_info;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!data || !data->data)
    {
        /* invalid input */
        MMI_ASSERT(0);
    }

    mmi_ss_reset_defer(data->sim);

    /* SIM group */
    mmi_ss_create_sim_group(data->sim);

    gid = mmi_ss_get_ussr_gid_by_sim(data->sim);

    mmi_ss_pre_entry_dummy(gid, SCR_ID_SS_USSR);

    /* USSR group */
    if (!mmi_frm_group_is_present(gid))
    {
        mmi_frm_group_create_ex(mmi_ss_get_gid_by_sim(data->sim), gid, mmi_ss_proc_grp_ussr, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    /* USSR screen */
    scrn_info = (mmi_ss_scrn_info_struct*)OslMalloc(sizeof(mmi_ss_scrn_info_struct));
    scrn_info->sim = data->sim;
    scrn_info->data = OslMalloc(sizeof(mmi_ss_ussr_struct));
    memcpy(scrn_info->data, data->data, sizeof(mmi_ss_ussr_struct));

#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
    memset(((mmi_ss_ussr_struct*)scrn_info->data)->reply_buf, 0, sizeof(((mmi_ss_ussr_struct*)scrn_info->data)->reply_buf));
    mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

    /* user_data is reserved, not used for now */
    mmi_frm_scrn_first_enter(gid, SCR_ID_SS_USSR, (FuncPtr)mmi_ss_entry_ussr, scrn_info);

#ifdef __MMI_RECEIVE_USSD_TONE__
    mmi_ss_op_play_ussd_alert(((mmi_ss_ussr_struct*)(data->data))->direction);
#endif /* __MMI_RECEIVE_USSD_TONE__ */

    /* free callback info */
    OslMfree(data->data);
    OslMfree(data);

    return MMI_TRUE;
}


#ifdef __MMI_RECEIVE_USSD_TONE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_play_ussd_alert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_play_ussd_alert(srv_ss_direction_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((dir == SRV_SS_DIR_MT) &&
       !srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        if (srv_prof_if_can_vibrate())
        {
            srv_vibrator_play_once();
        }

        srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_TRUE);
        srv_prof_play_tone(SRV_PROF_TONE_WARNING, NULL);
        if (srv_speech_is_phone_mute() == MMI_FALSE)
        {
            srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
        }
    }
}
#endif /* __MMI_RECEIVE_USSD_TONE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_ussn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_ussn(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ind_evt_struct *evt = (srv_ss_ind_evt_struct*)info;
    srv_ss_ussn_ind_struct *ind = (srv_ss_ussn_ind_struct*)(evt->data);
    mmi_ss_scrn_info_struct *scrn_info;
    mmi_ss_ussn_struct *ussn_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->source != SRV_SS_SRC_COMMON)
    {
        /* display ss screen by other app */
        return;
    }

    scrn_info = OslMalloc(sizeof(mmi_ss_scrn_info_struct));
    scrn_info->sim = evt->sim;
    ussn_info = OslMalloc(sizeof(mmi_ss_ussn_struct));
    ussn_info->direction = ind->direction;
    mmi_ucs2ncpy((CHAR*)ussn_info->display_buf, (CHAR*)ind->string, SRV_SS_MAX_LENGTH);
    scrn_info->data = (void*)ussn_info;

    mmi_ss_op_defer(evt->sim, mmi_ss_op_ussn_cb, (void*)scrn_info);

    if (mmi_ss_cntx_get_curr_op(evt->sim) == SRV_SS_ACT_SS_OPERATION)
    {
        /* end the requesting screen */
        mmi_ss_cntx_set_curr_op(evt->sim, SRV_SS_ACT_IDLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_ussn_cb
 * DESCRIPTION
 *  call back to display the ussn screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ss_op_ussn_cb(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *data = (mmi_ss_scrn_info_struct*)arg;
    mmi_ss_scrn_info_struct *scrn_info;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!data || !data->data)
    {
        /* invalid input */
        MMI_ASSERT(0);
    }

    mmi_ss_reset_defer(data->sim);

    gid = mmi_ss_create_sim_group(data->sim);

    mmi_ss_pre_entry_dummy(gid, SCR_ID_SS_USSN);

    scrn_info = (mmi_ss_scrn_info_struct*)OslMalloc(sizeof(mmi_ss_scrn_info_struct));
    scrn_info->sim = data->sim;
    scrn_info->data = OslMalloc(sizeof(mmi_ss_ussn_struct));
    memcpy(scrn_info->data, data->data, sizeof(mmi_ss_ussn_struct));

    /* user_data is reserved, not used for now */
    mmi_frm_scrn_first_enter(gid, SCR_ID_SS_USSN, (FuncPtr)mmi_ss_entry_ussn, scrn_info);

#ifdef __MMI_RECEIVE_USSD_TONE__
    mmi_ss_op_play_ussd_alert(((mmi_ss_ussn_struct*)(data->data))->direction);
#endif /* __MMI_RECEIVE_USSD_TONE__ */

    OslMfree(data->data);
    OslMfree(data);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_send
 * DESCRIPTION
 *  send ss
 * PARAMETERS
 *  sim     [IN]    target sim
 *  len     [IN]    ss string length
 *  str     [IN]    ss string
 * RETURNS
 *  void
 *****************************************************************************/
srv_ss_result_enum mmi_ss_op_send(mmi_sim_enum sim, U8 len, WCHAR *str, mmi_proc_func rsp_cb, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_operation_req_struct req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&req, 0, sizeof(srv_ss_operation_req_struct));

    req.sim = sim;

    mmi_ucs2ncpy((CHAR*)req.string, (CHAR*)str, len);

    return srv_ss_act_req(SRV_SS_ACT_SS_OPERATION, &req, rsp_cb, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_abort
 * DESCRIPTION
 *  ss abort by user operation
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_op_abort(mmi_sim_enum sim, MMI_BOOL local_rel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_abort_req_struct req;
    srv_ss_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_USSR_TIMER__  
    StopTimer(USSR_SESSION_TIMER);
#endif /* __MMI_USSR_TIMER__ */

    if (local_rel)
    {
        memset(&req, 0, sizeof(req));
        req.sim = sim;
        result = srv_ss_act_req(SRV_SS_ACT_ABORT, &req, NULL, NULL);
    }
    else
    {
        /* remote release */
        result = SRV_SS_RESULT_OK;
    }

    mmi_ss_cntx_set_curr_op(sim, SRV_SS_ACT_IDLE);

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_locked())
    {
        mmi_ss_result_proceed(sim);
 
        mmi_ss_op_cancel_defer(sim);
        mmi_ss_reset_defer(sim);
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    if (result != SRV_SS_RESULT_OK)
    {
        mmi_ss_display_error_popup_by_result(result);
    }
    else
    {
        mmi_ss_display_error_popup_by_id(STR_ID_SS_CANCELLED);

        mmi_ss_result_proceed(sim);

        mmi_ss_op_cancel_defer(sim);
        mmi_ss_reset_defer(sim);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_adjust_group
 * DESCRIPTION
 *  adjust group
 * PARAMETERS
 *  evt     [IN]    event information
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ss_op_adjust_group(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_adjust_grp_evt_struct *grp_evt = (mmi_ss_adjust_grp_evt_struct*)evt;
    S32 cur_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cur_num = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL);

    /* If the number of active or held call increase, it means should adjust the ss screen. */
    /* The ss screen should over the incall screen and below the incoming/outgoing call screen. */
    if (cur_num > mmi_ss_cntx_get_connected_call_num(grp_evt->sim))
    {
        mmi_frm_set_active_group(mmi_ss_get_gid_by_sim(grp_evt->sim));    
    }

    /* Set current number */
    mmi_ss_cntx_set_connected_call_num(grp_evt->sim, cur_num);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_scrn_proceed
 * DESCRIPTION
 *  proceed screen
 * PARAMETERS
 *  sim     [IN]    sim
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_scrn_proceed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_proceed_struct info;
    MMI_ID group_id = mmi_ss_get_gid_by_sim(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_proceed(sim, &info);

    if (info.from_grp)
    {
        if (mmi_frm_group_is_present(info.from_id))
        {
            info.proceeding = MMI_TRUE;
            mmi_ss_cntx_set_scr_proceed(sim, &info);
            mmi_frm_group_close(info.from_id);
        }
    }
    else
    {
        if (mmi_frm_scrn_is_present(group_id, info.from_id, MMI_FRM_NODE_ALL_FLAG))
        {
            info.proceeding = MMI_TRUE;
            mmi_ss_cntx_set_scr_proceed(sim, &info);
            mmi_frm_scrn_close(group_id, info.from_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_scrn_proceed_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_op_scrn_proceed_ex(mmi_sim_enum sim, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_proceed_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_proceed(sim, &info);

    if (info.from_grp || (info.from_id != scrn_id))
    {
        mmi_ss_op_scrn_proceed(sim);

        mmi_ss_cntx_get_scr_proceed(sim, &info);
        info.from_grp = MMI_FALSE;
        info.from_id = scrn_id;
        mmi_ss_cntx_set_scr_proceed(sim, &info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_cancel_defer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim     [IN]    sim
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_cancel_defer(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_defer_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_defer(sim, &info);

    if (info.deferring)
    {
        if (mmi_frm_nmgr_is_scenario_deferred(MMI_SCENARIO_ID_SS, info.defer_entry_func, info.defer_user_data))
        {
            mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_SS, info.defer_entry_func, info.defer_user_data);

            if (info.defer_user_data)
            {
                if ((info.defer_entry_func == mmi_ss_op_ussr_cb) ||
                    (info.defer_entry_func == mmi_ss_op_ussn_cb))
                {
                    if(((mmi_ss_scrn_info_struct*)info.defer_user_data)->data)
                    {
                        OslMfree(((mmi_ss_scrn_info_struct*)info.defer_user_data)->data);
                    }
                }
                else if (info.defer_entry_func == mmi_ss_op_start_action_cb)
                {
                    if(((mmi_ss_act_start_struct*)info.defer_user_data)->req_info)
                    {
                        OslMfree(((mmi_ss_act_start_struct*)info.defer_user_data)->req_info);
                    }
                }
                else if (info.defer_entry_func == mmi_ss_op_end_action_cb)
                {
                    if(((srv_ss_rsp_struct*)info.defer_user_data)->data)
                    {
                        OslMfree(((srv_ss_rsp_struct*)info.defer_user_data)->data);
                    }
                }

                OslMfree(info.defer_user_data);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_defer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_op_defer(mmi_sim_enum sim, mmi_noti_scrn_func_ptr func_p, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_defer_struct defer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_defer(sim, &defer);
    mmi_ss_op_cancel_defer(sim);
    
    defer.deferring = MMI_TRUE;
    defer.defer_entry_func = func_p;
    defer.defer_user_data = data;
    mmi_ss_cntx_set_scr_defer(sim, &defer);

    mmi_frm_nmgr_notify_by_app(
                  MMI_SCENARIO_ID_SS,
                  MMI_EVENT_PROGRESS,
                  func_p,
                  data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_ussr
 * DESCRIPTION
 *  enter ussr screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_entry_ussr(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(data->user_data);
    mmi_ss_ussr_struct *ussr_info = (mmi_ss_ussr_struct*)(scrn_info->data);
    mmi_ss_scr_proceed_struct info;
    MMI_BOOL enter_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(data);
    MMI_ASSERT(scrn_info);
    MMI_ASSERT(ussr_info);

    enter_res = mmi_frm_scrn_enter(
                    data->group_id, 
                    data->scrn_id, 
                    NULL, 
                    (FuncPtr)mmi_ss_entry_ussr, 
                    MMI_FRM_UNKNOW_SCRN);

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_ss_proc_ussr);

    /* only close the previous scr / grp in first entry scenarios */
    mmi_ss_cntx_get_scr_proceed(scrn_info->sim, &info);

    if (!(info.from_grp) || (info.from_id != data->group_id))
    {
        mmi_ss_op_scrn_proceed(scrn_info->sim);

        mmi_ss_cntx_get_scr_proceed(scrn_info->sim, &info);
        info.from_grp = MMI_TRUE;
        info.from_id = data->group_id; /* proceed as the unit of group */
        mmi_ss_cntx_set_scr_proceed(scrn_info->sim, &info);
    }

    if (!enter_res)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
    mmi_ss_ussd_set_hilight_info();

#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat116_set_send_btn_func(mmi_ss_hdlr_ussr_edit_done);
#endif /* __MMI_TOUCH_SCREEN__ */

    ShowCategory116Screen(
        get_string(STR_GLOBAL_OK),
        (U8*)GetImage(IMG_GLOBAL_OK),
        get_string(STR_GLOBAL_ABORT),
        (U8*)GetImage(IMG_GLOBAL_NO),
        (UI_string_type)ussr_info->display_buf,
        (U8*)ussr_info->reply_buf,
        SRV_SS_MAX_LENGTH + 1,
        IMM_INPUT_TYPE_ENGLISH_SENTENCE,
        guiBuffer);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    wgui_cat116_set_right_softkey_function(mmi_ss_hdlr_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_ss_hdlr_ussr_edit_done, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#ifdef __MMI_TOUCH_SCREEN__
    SetCenterSoftkeyFunction(mmi_ss_hdlr_ussr_edit_done, KEY_EVENT_UP);
#else /* __MMI_TOUCH_SCREEN__ */
    SetCenterSoftkeyFunction(mmi_ss_ussd_pre_use_detail_info, KEY_EVENT_UP); 
#endif /* __MMI_TOUCH_SCREEN__ */
    SetKeyDownHandler(mmi_ss_hdlr_ussr_edit_done, KEY_SEND);
    mmi_ss_clear_vol_key_handler();

#else /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

    ShowCategory74Screen(
        STR_ID_SS_USSD_MSG,
        0,
        STR_GLOBAL_REPLY,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*)(ussr_info->display_buf),
        mmi_ucs2strlen((CHAR*)(ussr_info->display_buf)),
        guiBuffer);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    SetRightSoftkeyFunction(mmi_ss_hdlr_abort, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_ss_entry_edit_ussr, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ss_entry_edit_ussr, KEY_EVENT_UP);
    mmi_ss_clear_vol_key_handler();
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_ussn
 * DESCRIPTION
 *  enter ussn screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_entry_ussn(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(data->user_data);
    mmi_ss_ussn_struct *ussn_info = (mmi_ss_ussn_struct*)(scrn_info->data);
    MMI_BOOL enter_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(data);
    MMI_ASSERT(scrn_info);
    MMI_ASSERT(ussn_info);

    enter_res = mmi_frm_scrn_enter(
                    data->group_id, 
                    data->scrn_id, 
                    NULL, 
                    (FuncPtr)mmi_ss_entry_ussn, 
                    MMI_FRM_UNKNOW_SCRN);

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_ss_proc_ussn);

    /* only close the previous scr / grp in first entry scenarios */
    mmi_ss_op_scrn_proceed_ex(scrn_info->sim, data->scrn_id);

    if (!enter_res)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
        mmi_ss_ussd_set_hilight_info();
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */

    ShowCategory74Screen(
        STR_ID_SS_USSD_MSG,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)ussn_info->display_buf,
        mmi_ucs2strlen((CHAR*)(ussn_info->display_buf)),
        guiBuffer);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
    SetCenterSoftkeyFunction(mmi_ss_ussd_pre_use_detail_info, KEY_EVENT_UP);
#else /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */
    SetCenterSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */
    mmi_ss_clear_vol_key_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_requesting
 * DESCRIPTION
 *  enter ss requesting screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_entry_requesting(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(data->user_data);
    MMI_BOOL enter_res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(data);
    MMI_ASSERT(scrn_info);

    enter_res = mmi_frm_scrn_enter(
                    data->group_id, 
                    data->scrn_id, 
                    NULL, 
                    (FuncPtr)mmi_ss_entry_requesting, 
                    MMI_FRM_UNKNOW_SCRN);

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_ss_proc_requesting);

    /* only close the previous scr / grp in first entry scenarios */
    mmi_ss_op_scrn_proceed_ex(scrn_info->sim, data->scrn_id);

    if (!enter_res)
    {
        return;
    }

    ShowCategory8Screen(
        STR_ID_SS_REQUESTING,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        STR_GLOBAL_PLEASE_WAIT,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    mmi_ss_clear_vol_key_handler();
    
    SetRightSoftkeyFunction(mmi_ss_hdlr_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_result
 * DESCRIPTION
 *  enter ss result screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_entry_result(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mmi_ss_scrn_info_struct *scrn_info = (mmi_ss_scrn_info_struct*)(data->user_data);
    mmi_ss_result_struct *result = (mmi_ss_result_struct*)(scrn_info->data);
    WCHAR* title = get_string(STR_GLOBAL_DONE);
    MMI_BOOL enter_res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(data);
    MMI_ASSERT(scrn_info);
    MMI_ASSERT(result);

    enter_res = mmi_frm_scrn_enter(
                    data->group_id, 
                    data->scrn_id, 
                    NULL, 
                    (FuncPtr)mmi_ss_entry_result, 
                    MMI_FRM_UNKNOW_SCRN);

    mmi_frm_scrn_set_leave_proc(data->group_id, data->scrn_id, mmi_ss_proc_result);

    /* only close the previous scr / grp in first entry scenarios */
    mmi_ss_op_scrn_proceed_ex(scrn_info->sim, data->scrn_id);

    if (!enter_res)
    {
        return;
    }

#ifndef __MMI_SS_SHOW_CAUSE__
    if (result->result == SRV_SS_RESULT_OK)
#endif /* __MMI_SS_SHOW_CAUSE__ */
    {
        if (mmi_ucs2strlen((CHAR*)result->string))
        {
            guiBuffer = mmi_frm_scrn_get_active_gui_buf();

            ShowCategory74Screen(
                STR_ID_SS_USSD_MSG,
                0,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                0,
                0,
                (PU8)result->string,
                mmi_ucs2strlen((CHAR*)result->string),
                guiBuffer);

            SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

            return;
        }
    }
#ifndef __MMI_SS_SHOW_CAUSE__
    else
    {
        title = result->string;
    }
#endif /* __MMI_SS_SHOW_CAUSE__ */

    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    mmi_popup_display_simple(
        title, 
        MMI_EVENT_FAILURE,
        GRP_ID_ROOT,
        NULL);

    mmi_ss_result_proceed(mmi_ss_get_sim_by_gid(data->group_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_edit_ussr
 * DESCRIPTION
 *  reply ussr by user operation
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_entry_edit_ussr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scrn_info_struct *scrn_info;
    mmi_ss_ussr_struct *ussr_info;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    scrn_info = (mmi_ss_scrn_info_struct*)mmi_frm_scrn_get_user_data(
                    mmi_frm_group_get_active_id(), 
                    mmi_frm_scrn_get_active_id());

    MMI_ASSERT(scrn_info);
    ussr_info = (mmi_ss_ussr_struct*)(scrn_info->data);
    MMI_ASSERT(ussr_info);

    gid = cui_fseditor_create(mmi_frm_group_get_active_id());
    cui_fseditor_set_parent_data(gid, (U32)scrn_info);
    cui_fseditor_set_title(gid, STR_GLOBAL_EDIT, 0);

#if 0
#ifdef __OP12__
/* under construction !*/
#endif /* __OP12__ */
#endif

#ifdef __MMI_USSD_REPLY_UCS2__
    cui_fseditor_set_input_method(gid, INPUT_TYPE_USE_ENCODING_BASED_LENGTH|INPUT_TYPE_ONE_LESS_CHARACTER|IMM_INPUT_TYPE_SENTENCE, NULL, 0);
#else /*__MMI_USSD_REPLY_UCS2__*/
    cui_fseditor_set_input_method(gid, IMM_INPUT_TYPE_ENGLISH_SENTENCE, NULL, 0);
#endif /*__MMI_USSD_REPLY_UCS2__*/

    memset(ussr_info->reply_buf, 0, sizeof(ussr_info->reply_buf));

    cui_fseditor_set_text(gid, ussr_info->reply_buf, sizeof(ussr_info->reply_buf), SRV_SS_MAX_LENGTH);
    cui_fseditor_run(gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_entry_dummy
 * DESCRIPTION
 *  entry dummy screen
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_entry_dummy(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim = mmi_ss_get_sim_by_gid(gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_enter(
        gid, 
        SCR_ID_GLOBAL_DUMMY, 
        NULL, 
        (FuncPtr)mmi_ss_entry_dummy, 
        MMI_FRM_UNKNOW_SCRN);

    /* only close the previous scr / grp in first entry scenarios */
    mmi_ss_op_scrn_proceed_ex(sim, SCR_ID_GLOBAL_DUMMY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_pre_entry_dummy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_pre_entry_dummy(MMI_ID group_id, MMI_ID scrn_id)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_is_present(group_id, scrn_id, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_ss_entry_dummy(group_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_reg_adj_grp_cb
 * DESCRIPTION
 *  exit group
 * PARAMETERS
 *  data    [IN]    parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_reg_adj_grp_cb(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_grp_info_struct *grp_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    grp_info = (mmi_ss_grp_info_struct*)OslMalloc(sizeof(mmi_ss_grp_info_struct));
    grp_info->sim = sim;

    mmi_ss_cntx_set_adj_grp_user_data(grp_info->sim, (void*)grp_info);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, mmi_ss_hdlr_ucm_call_status_change, grp_info);

    mmi_ss_cntx_set_connected_call_num(grp_info->sim, srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_reg_adj_grp_cb
 * DESCRIPTION
 *  exit group
 * PARAMETERS
 *  data    [IN]    parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_op_dereg_adj_grp_cb(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = mmi_ss_cntx_get_adj_grp_user_data(sim);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_UCM_STATUS_CHANGE, 
        mmi_ss_hdlr_ucm_call_status_change, 
        user_data);

    OslMfree(user_data);

    mmi_ss_cntx_set_adj_grp_user_data(sim, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_get_gid_by_sim
 * DESCRIPTION
 *  get group id by sim
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  group id of the correcponding sim
 *****************************************************************************/
MMI_ID mmi_ss_get_gid_by_sim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sim)
    {
        case MMI_SIM1:
            return GRP_ID_SS_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return GRP_ID_SS_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return GRP_ID_SS_SIM3;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return GRP_ID_SS_SIM4;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        default:
            MMI_ASSERT(0);
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_get_ussr_gid_by_sim
 * DESCRIPTION
 *  get ussr group id by sim
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  group id of the correcponding sim
 *****************************************************************************/
MMI_ID mmi_ss_get_ussr_gid_by_sim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sim)
    {
        case MMI_SIM1:
            return GRP_ID_SS_SIM1_USSR;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return GRP_ID_SS_SIM2_USSR;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return GRP_ID_SS_SIM3_USSR;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return GRP_ID_SS_SIM4_USSR;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            return 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ss_get_ussr_timeout_hdlr
 * DESCRIPTION
 *  get ussr timeout handler by sim
 * PARAMETERS
 *  sim     [IN]    target sim
 * RETURNS
 *  ussr timeout handler
 *****************************************************************************/
FuncPtr mmi_ss_get_ussr_timeout_hdlr(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sim)
    {
        case MMI_SIM1:
            return (FuncPtr)mmi_ss_hdlr_ussr_timeout;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return (FuncPtr)mmi_ss_hdlr_ussr_timeout_sim2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return (FuncPtr)mmi_ss_hdlr_ussr_timeout_sim3;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_SIM4:
            return (FuncPtr)mmi_ss_hdlr_ussr_timeout_sim4;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_get_sim_by_gid
 * DESCRIPTION
 *  get sim by group id
 * PARAMETERS
 *  gid     [IN] group id
 * RETURNS
 *  sim
 *****************************************************************************/
mmi_sim_enum mmi_ss_get_sim_by_gid(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (gid)
    {
        case GRP_ID_SS_SIM1:
        case GRP_ID_SS_SIM1_USSR:
            return MMI_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case GRP_ID_SS_SIM2:
        case GRP_ID_SS_SIM2_USSR:
            return MMI_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case GRP_ID_SS_SIM3:
        case GRP_ID_SS_SIM3_USSR:
            return MMI_SIM3;
    #if (MMI_MAX_SIM_NUM == 4)
        case GRP_ID_SS_SIM4:
        case GRP_ID_SS_SIM4_USSR:
            return MMI_SIM4;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            MMI_ASSERT(0);
            return MMI_SIM_NONE;
    }
}


#ifdef __MMI_USSD_REPLY_IN_SAME_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_set_hilight_info
 * DESCRIPTION
 *  Set highlight detail info in content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_ussd_set_hilight_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cate_hilite_list hilite_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    hilite_info.hilite_type = (EDITOR_HILITE_TYPE)(EDITOR_HILITE_NUMBER | EDITOR_HILITE_EMAIL | EDITOR_HILITE_URL | EDITOR_HILITE_USSD);
#if !defined(__MMI_EMAIL__) && !defined(__MMI_PHB_OPTIONAL_FIELD__)
    hilite_info.hilite_type &= (~EDITOR_HILITE_EMAIL);
#endif /* !defined(__MMI_EMAIL__) && !defined(__MMI_PHB_OPTIONAL_FIELD__) */
#ifndef BROWSER_SUPPORT
    hilite_info.hilite_type &= (~EDITOR_HILITE_URL);
#endif /* BROWSER_SUPPORT */
    hilite_info.curr_hilite_idx = 0;
    hilite_info.hilite_cb = mmi_ss_ussd_hilite_cb;
    hilite_info.click_cb = mmi_ss_ussd_click_cb;
    wgui_cate_set_highlight_list(&hilite_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_use_detail_info
 * DESCRIPTION
 *  "Use Detail CUI" is used in USSD
 * PARAMETERS
 *  idx     [IN] hilite index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_ussd_use_detail_info(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HILITE_STR *list = NULL;
    cui_use_detail_basic_obj_struct obj_list;
    mmi_id use_detail_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_cate_get_highlight_list(&list);
    obj_list.detail_txt = (U16*)list[idx].str_addr;
    obj_list.txtlen = list[idx].length;

    switch (list[idx].hilite_type)
    {
        case EDITOR_HILITE_NUMBER:
            obj_list.type = CUI_USE_DETAIL_TYPE_PHONENUMBER;
            break;
        case EDITOR_HILITE_EMAIL:
            obj_list.type = CUI_USE_DETAIL_TYPE_EMAIL;
            break;
        case EDITOR_HILITE_URL:
            obj_list.type = CUI_USE_DETAIL_TYPE_URL;
            break;
        case EDITOR_HILITE_USSD:
            obj_list.type = CUI_USE_DETAIL_TYPE_USSD;
            break;
        default:
            break;
    }

    use_detail_gid = cui_use_detail_create(mmi_frm_group_get_active_id(), &obj_list, 1, NULL);
    cui_use_detail_run(use_detail_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_pre_use_detail_info
 * DESCRIPTION
 *  "Use Detail CUI" is used in USSD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_ussd_pre_use_detail_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sim = mmi_ss_ussd_get_current_sim();
    idx = mmi_ss_get_hilight_idx(sim);
    mmi_ss_ussd_use_detail_info(idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_click_cb
 * DESCRIPTION
 *  ussd click hdlr
 * PARAMETERS
 *  idx     [IN] hilite index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_ussd_click_cb(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_ussd_use_detail_info(idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_hilite_cb
 * DESCRIPTION
 *  ussd hilite hdlr
 * PARAMETERS
 *  idx     [IN] hilite index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_ussd_hilite_cb(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sim = mmi_ss_ussd_get_current_sim();
    mmi_ss_set_hilight_idx(sim, idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_ussd_get_current_sim
 * DESCRIPTION
 *  get the sim of the active USSD screen
 * PARAMETERS
 *  void
 * RETURNS
 *  sim
 *****************************************************************************/
mmi_sim_enum mmi_ss_ussd_get_current_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id, scrn_id;
    mmi_ss_scrn_info_struct *scrn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    group_id = mmi_frm_group_get_active_id();
    scrn_id = mmi_frm_scrn_get_active_id();
    scrn_info = mmi_frm_scrn_get_user_data(group_id, scrn_id);

    return scrn_info->sim;
}
#endif /* __MMI_USSD_REPLY_IN_SAME_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_sim_availability_changed_hdlr
 * DESCRIPTION
 *  SIM availability handler
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ss_sim_availability_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *sim_evt = (srv_sim_ctrl_availability_changed_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (sim_evt->is_available_before == sim_evt->is_available_now)
    {
        return MMI_RET_OK;
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (!sim_evt->is_available_now)
    {
        if (mmi_frm_group_is_present(GRP_ID_SS_COMMON))
        {
            mmi_frm_group_close(GRP_ID_SS_COMMON);
        }
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_reset_defer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_reset_defer(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_defer_struct defer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_defer(sim, &defer);
    defer.deferring = MMI_FALSE;
    defer.defer_entry_func = NULL;
    defer.defer_user_data = NULL;
    mmi_ss_cntx_set_scr_defer(sim, &defer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_reset_proceed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_reset_proceed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_proceed(sim, &proceed_info);
    memset(&proceed_info, 0, sizeof(mmi_ss_scr_proceed_struct));
    mmi_ss_cntx_set_scr_proceed(sim, &proceed_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_create_sim_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
MMI_ID mmi_ss_create_sim_group(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;    
    //mmi_ss_grp_info_struct *grp_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = mmi_ss_get_gid_by_sim(sim);
    if (!mmi_frm_group_is_present(gid))
    {
        //grp_info = (mmi_ss_grp_info_struct*)OslMalloc(sizeof(mmi_ss_grp_info_struct));
        //grp_info->sim = sim;
        mmi_frm_group_create(GRP_ID_ROOT, gid, mmi_ss_proc_sim, NULL);
        mmi_ss_op_reg_adj_grp_cb(sim);
        mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else
    {
        mmi_frm_set_active_group(gid);
    }

    return gid;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_ss_abort_at_screen_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_abort_at_screen_deinit(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_cntx_get_scr_proceed(sim, &proceed_info);
    if (!(proceed_info.proceeding))
    {
        mmi_ss_op_abort(sim, MMI_TRUE);
    }

    proceed_info.proceeding = MMI_FALSE;

    mmi_ss_cntx_set_scr_proceed(sim, &proceed_info);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ss_result_proceed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_result_proceed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ss_scr_proceed_struct proceed_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ss_op_scrn_proceed(sim);
    mmi_ss_cntx_get_scr_proceed(sim, &proceed_info);
    proceed_info.from_grp = MMI_FALSE;
    proceed_info.from_id = 0;
    mmi_ss_cntx_set_scr_proceed(sim, &proceed_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_display_error_popup_by_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_display_error_popup_by_result(srv_ss_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result != SRV_SS_RESULT_OK)
    {
        mmi_popup_display_simple_ext(
            srv_ss_get_result_string(result), 
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_display_error_popup_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_display_error_popup_by_id(MMI_STR_ID title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_display_simple_ext(
        STR_ID_SS_CANCELLED,
        MMI_EVENT_FAILURE,
        GRP_ID_ROOT,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_clear_vol_key_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void mmi_ss_clear_vol_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyDownHandler(NULL, KEY_VOL_UP);
    SetKeyLongpressHandler(NULL, KEY_VOL_UP);
    SetKeyDownHandler(NULL, KEY_VOL_DOWN);
    SetKeyLongpressHandler(NULL, KEY_VOL_DOWN);
}


