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
 *  BootupMode.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Bootup mode selection
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "BootupSrvIprot.h"
#include "ProcedureGprot.h"
#include "BootupAppProt.h"
#include "ShutdownSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "ModeSwitchSrvGprot.h"
#include "Gpiosrvgprot.h"       /* srv_backlight_turn_on */
#include "PhoneSetup.h"         /* PHNSET_CNTX */
#include "SimCtrlSrvGprot.h" // Gemini+
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "MMIDataType.h"
#include "BootupScrUtil.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_rp_app_bootup_def.h"
#include "GlobalResDef.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "custom_events_notify.h"
#include "ProfilesSrvGprot.h"
#include "l4c_nw_cmd.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustMenuRes.h"
#include "string.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"
#include "mmi_frm_utility_gprot.h"

#if (MMI_MAX_SIM_NUM >= 3)
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#endif


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_bootup_sim_selection_handle sim_sel_handle;
#endif
    mmi_frm_proc_id_info_struct id_info;
    srv_bootup_protocol_mode_enum mode;
} mmi_bootup_mode_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static mmi_bootup_mode_cntx_struct g_mmi_bootup_mode_cntx
#if (MMI_MAX_SIM_NUM >= 2)
    = { NULL }
#endif
;

extern PHNSET_CNTX g_phnset_cntx;


/****************************************************************************
 * Local functions
 ****************************************************************************/

static void mmi_bootup_on_protocol_ready(void *user_data);

#if (MMI_MAX_SIM_NUM >= 2)
static void mmi_bootup_on_sim_module_ready(void *user_data);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_init_sim_module
 * DESCRIPTION
 *  Initialize SIM modules and query SIMs inserted or not
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be carried back to mmi_frm_proc_notify_completed()
 * RETURNS
 *  MMI_FRM_PROC_RESULT_NOTIFY_LATER
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_flow_init_sim_module(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)

    g_mmi_bootup_mode_cntx.id_info = id_info;

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_FLOW_INIT_SIM_MODULE);

    srv_bootup_init_sim_module(
        mmi_bootup_on_sim_module_ready,
        &(g_mmi_bootup_mode_cntx));

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;

#else

    /* Only dual SIM projects need to be initialized now */
    return MMI_FRM_PROC_RESULT_COMPLETED;

#endif
}


#if (MMI_MAX_SIM_NUM >= 2)

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_on_sim_module_ready
 * DESCRIPTION
 *  The callback for the arrival of SIM status.
 * PARAMETERS
 *  user_data   [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_on_sim_module_ready(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_notify_completed(g_mmi_bootup_mode_cntx.id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_get_protocol_mode_setting
 * DESCRIPTION
 *  Get mode setting from dual mode manager:
 *  Dual DIM, SIM1 only, SIM2 only or flight mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  Mode setting
 *****************************************************************************/
static srv_bootup_protocol_mode_enum mmi_bootup_get_protocol_mode_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_bootup_protocol_mode_enum) srv_mode_switch_get_current_mode();
}


#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_multiple_sim_on_mode_selected
 * DESCRIPTION
 *  The callback of user selected protocol mode.
 *  Store the selection and continue the main flow.
 * PARAMETERS
 *  user_data   [IN] Unused
 *  handle      [IN] The handle of SIM selection UI
 *  mode        [IN] Protocol mode
 * RETURNS
 *  MMI_BOOTUP_SCR_ALLOW_TO_CLOSE
 *****************************************************************************/
static mmi_ret mmi_bootup_multiple_sim_on_mode_selected(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selected_event_struct *selected_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_MMI_BOOTUP_SCR_SELECTED_POSITIVE);
    
    selected_evt = (mmi_bootup_sim_selected_event_struct*)evt;
    g_mmi_bootup_mode_cntx.sim_sel_handle = NULL;
    g_mmi_bootup_mode_cntx.mode = selected_evt->mode;
    
    mmi_frm_proc_notify_completed(g_mmi_bootup_mode_cntx.id_info);
    
    return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_multiple_sim_forbid_cancel
 * DESCRIPTION
 *  Callback of SIM selection to avoid user leave the SIM selection without
 *  selecting anything.
 *  User should always select one protocol mode.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_BOOTUP_SCR_DONT_CLOSE
 *****************************************************************************/
static mmi_ret mmi_bootup_multiple_sim_forbid_cancel(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We don't allow the SIM selection to be cancelled */
    return MMI_BOOTUP_SCR_DONT_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_mode_show_sim_selection
 * DESCRIPTION
 *  Show SIM selection screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_mode_show_sim_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_mode_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &g_mmi_bootup_mode_cntx;
    
    cntx->sim_sel_handle = mmi_bootup_sim_selection_show(
        GRP_ID_BOOTUP,
        STR_ID_BOOTUP_SELECT_SIM,
        0,
        cntx,
        STR_GLOBAL_OK,
        mmi_bootup_multiple_sim_on_mode_selected,
        0,
        mmi_bootup_multiple_sim_forbid_cancel);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_decide_mode_multiple_sim
 * DESCRIPTION
 *  Decide protocol booting mode on dual multiple project.
 *  It determines the mode setting, and may query user if necessary. Once mode
 *  is decided, the mode will be stored in g_mmi_bootup_mode_cntx.mode for
 *  the mmi_bootup_boot_protocol() in the future.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_bootup_decide_mode_multiple_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_mode_cntx_struct *cntx;
    srv_bootup_protocol_mode_enum inserted_sim_set;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_mode_cntx);
    
    if (srv_bootup_is_exception_mode())
    {
        /* Apply previous selection */
        cntx->mode = mmi_bootup_get_protocol_mode_setting();
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    
    /* Flight mode's priority is more than dynamic selection */
    if (!srv_mode_switch_is_network_service_available())
    {
        cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_NONE;
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    inserted_sim_set = SRV_BOOTUP_PROTOCOL_MODE_NONE;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (srv_bootup_sim_is_inserted(sim))
        {
            inserted_sim_set |= sim;
        }
    }

#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    if (srv_bootup_protocol_get_query_setting() == SRV_BOOTUP_PROTOCOL_QUERY_APPLY_DEFAULT)
    {
#endif
        MMI_TRACE(MMI_COMMON_TRC_G3_BOOTUP, TRC_MMI_BOOTUP_STATIC_OR_DYNAMIC, 'S');
        
        // cntx->mode = mmi_bootup_get_protocol_mode_setting();
        if (!inserted_sim_set) /* No SIM inserted */
        {
            /* Turn on SIM1 for emergency call */
            cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_SIM1_ONLY;
        }
        else
        {
            cntx->mode = inserted_sim_set;
        }
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G3_BOOTUP, TRC_MMI_BOOTUP_STATIC_OR_DYNAMIC, 'D');

        if (inserted_sim_set == 0) /* No SIM inserted */
        {
            /* Turn on SIM1 for emergency call */
            cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_SIM1_ONLY;
        }
        else if (inserted_sim_set == MMI_SIM1)
        {
            cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_SIM1_ONLY;
        }
        else if (inserted_sim_set == MMI_SIM2)
        {
            cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_SIM2_ONLY;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if  (inserted_sim_set == MMI_SIM3)
        {
            cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_SIM3_ONLY;
        }
    #if (MMI_MAX_SIM_NUM >= 4)
        else if  (inserted_sim_set == MMI_SIM4)
        {
            cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_SIM4_ONLY;
        }
    #endif
    #endif
        else /* at lease 2 SIM cards inserted */
        {
            if (srv_bootup_is_auto_power_on_test())
            {
            #if (MMI_MAX_SIM_NUM >= 3)
                cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_ALL_SIM; // Gemini+
            #else
                cntx->mode = SRV_BOOTUP_PROTOCOL_MODE_DUAL_SIM;
            #endif
            }
            else
            {
            #ifdef __MMI_TOUCH_SCREEN__
                if (mmi_bootup_needs_pen_calibration())
                {
                    EntryPhnseFactoryDefaultCalibrationScr(GoBackHistory);
                    /*
                     * Add the SIM selection screen node to history first.
                     * So that it can be shown as pen calibration be closed.
                     */
                    mmi_bootup_mode_show_sim_selection();
                }
                else
            #endif /* __MMI_TOUCH_SCREEN__ */
                {
                    mmi_bootup_mode_show_sim_selection();
                }
                
                srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
               
                return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
            }
        }
    }
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
mmi_ret mmi_bootup_mode_on_sim_status_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_mode_cntx_struct *cntx;
    mmi_sim_enum one_inserted_sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED);

    cntx = &(g_mmi_bootup_mode_cntx);

    if (cntx->sim_sel_handle != NULL)
    {
        S32 i;
        S32 sim_count;

        sim_count = 0;
        one_inserted_sim = MMI_SIM_NONE;
        for (i = MMI_SIM_TOTAL - 1; i >= 0; i--)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (srv_bootup_sim_is_inserted(sim))
            {
                one_inserted_sim = sim;
                sim_count++;
            }
        }

        if (sim_count < 2) /* Less than 2 SIMs to select */
        {
            if (one_inserted_sim == MMI_SIM_NONE)
            {
                one_inserted_sim = MMI_SIM1; /* At least enable SIM1 for emergency call */
            }
            cntx->mode = (srv_bootup_protocol_mode_enum)one_inserted_sim;
            mmi_frm_proc_notify_completed(cntx->id_info);
            mmi_bootup_sim_selection_close(cntx->sim_sel_handle);
            cntx->sim_sel_handle = NULL;
        }
        else
        {
            /* Force screen refresh */
            mmi_bootup_put_dummy_screen(GRP_ID_BOOTUP);
            mmi_bootup_close_dummy_screen(GRP_ID_BOOTUP);
        }
    }
    return MMI_RET_OK;
}
#endif

#else /* (MMI_MAX_SIM_NUM >= 2) */

#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_BOOTUP_MODE_SEL_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flight_mode_on_selected
 * DESCRIPTION
 *  User selected Yes for flight mode or No for normal mode.
 *  Store the selection and continue next step.
 * PARAMETERS
 *  evt     [IN] mmi_bootup_count_down_selected_evt_struct*
 * RETURNS
 *  MMI_BOOTUP_SCR_ALLOW_TO_CLOSE
 *****************************************************************************/
static mmi_ret mmi_bootup_flight_mode_on_selected(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_MMI_BOOTUP_SCR_SELECTED_POSITIVE)
    {
        g_mmi_bootup_mode_cntx.mode = SRV_BOOTUP_PROTOCOL_MODE_FLIGHT_MODE;
    }
    else
    {
        g_mmi_bootup_mode_cntx.mode = SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE;
    }

    mmi_frm_proc_notify_completed(g_mmi_bootup_mode_cntx.id_info);
    
    return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flight_mode_query_close
 * DESCRIPTION
 *  Flight mode query screen is going to close. We allow the closing only if
 *  timeout, and set mode to normal mode by default.
 * PARAMETERS
 *  evt     [IN] mmi_bootup_count_down_close_evt_struct*
 * RETURNS
 *  MMI_BOOTUP_SCR_ALLOW_TO_CLOSE only if timeout
 *****************************************************************************/
static mmi_ret mmi_bootup_flight_mode_query_close(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_MMI_BOOTUP_SCR_TIMEOUT:
            g_mmi_bootup_mode_cntx.mode = SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE;

            if (!srv_shutdown_is_running())
            {
                mmi_frm_proc_notify_completed(g_mmi_bootup_mode_cntx.id_info);
            }
			// slim_ifelse
            //else
            //{
                /*
                 * If timeout when shutdown has been started on the query screen,
                 * we don't need to continue the booting flow.
                 */
            //}
            
            return MMI_BOOTUP_SCR_ALLOW_TO_CLOSE;

        case EVT_ID_MMI_BOOTUP_SCR_DELETING:
            return MMI_BOOTUP_SCR_DONT_CLOSE;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_single_sim_show_mode_query
 * DESCRIPTION
 *  Show flight mode query screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_single_sim_show_mode_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 0
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
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_single_sim_on_calibration_done
 * DESCRIPTION
 *  Callback for pen calibration. Show flight mode query.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
static void mmi_bootup_single_sim_on_calibration_done(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bootup_single_sim_show_mode_query();
}
#endif /* defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_BOOTUP_MODE_SEL_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_decide_mode_single_sim
 * DESCRIPTION
 *  Decide the mode of protocol booting for single SIM.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_bootup_decide_mode_single_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FLIGHT_MODE_SUPPORT__

#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    if (!srv_bootup_is_exception_mode() &&
        srv_bootup_protocol_get_query_setting() == SRV_BOOTUP_PROTOCOL_QUERY_ASK_USER)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        if (mmi_bootup_needs_pen_calibration())
        {
            mmi_bootup_show_pen_calibration(
                GRP_ID_BOOTUP,
                mmi_bootup_single_sim_on_calibration_done,
                NULL);
        }
        else
    #endif /* __MMI_TOUCH_SCREEN__ */
        {
            mmi_bootup_single_sim_show_mode_query();
        }
        
        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }
    else
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
    {
        if (srv_mode_switch_is_network_service_available())
        {
            g_mmi_bootup_mode_cntx.mode = SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE;
        }
        else
        {
            g_mmi_bootup_mode_cntx.mode = SRV_BOOTUP_PROTOCOL_MODE_FLIGHT_MODE;
        }
    }
    
#else /* __FLIGHT_MODE_SUPPORT__ */

    g_mmi_bootup_mode_cntx.mode = SRV_BOOTUP_PROTOCOL_MODE_NORMAL_MODE;

#endif

    return MMI_FRM_PROC_RESULT_COMPLETED;
}

#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_decide_mode
 * DESCRIPTION
 *  Decide booting mode.
 *  According to the user setting, it may show flight mode query or SIM selection
 *  screen to user.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be carried back to mmi_frm_proc_notify_completed()
 * RETURNS
 *  void
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_decide_mode(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_mode_cntx.id_info = id_info;
    
#if (MMI_MAX_SIM_NUM >= 2)

    return mmi_bootup_decide_mode_multiple_sim();
    
#else

    return mmi_bootup_decide_mode_single_sim();
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_boot_protocol
 * DESCRIPTION
 *  Boot protocol layer. That is, send power-on indication to L4Cs.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed()
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_bootup_boot_protocol(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_mode_cntx.id_info = id_info;

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_BOOT_PROTOCOL, g_mmi_bootup_mode_cntx.mode);
    
    srv_bootup_boot_protocol(
        g_mmi_bootup_mode_cntx.mode,
        mmi_bootup_on_protocol_ready,
        NULL);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_on_protocol_ready
 * DESCRIPTION
 *  Callback for protocol booting completed.
 *  This callback will notify bootup main flow to continue.
 * PARAMETERS
 *  user_data   [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_on_protocol_ready(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_PROTOCOL_READY);
    
    mmi_frm_proc_notify_completed(g_mmi_bootup_mode_cntx.id_info);
}

#if 0 // slim_unused_api
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
#endif

#if (MMI_MAX_SIM_NUM >= 2) && defined(__MMI_BOOTUP_MODE_SEL_SUPPORT__)

/****************************************************************************
 * [SIM-selection UI utility]
 *
 * This utility provides a UI screen that shows SIM choices.
 * User can call mmi_bootup_sim_selection_show() to show a SIM-selection
 * screen may call mmi_bootup_sim_selection_close() to close it finally.
 ****************************************************************************/
#define MMI_BOOTUP_SIM_SELECTION

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    U16 title_str_id;
    U16 title_icon_id;
    U16 select_str_id;
    U16 cancel_str_id;
    void *user_data;
    mmi_proc_func selected_proc;
    mmi_proc_func neg_proc;
    S32 selected_index;
    MMI_BOOL is_deleting;
#if (MMI_MAX_SIM_NUM >= 3)
    U8 mark_flag[SRV_SIM_CTRL_MAX_SIM_NUM]; // Gemini+
#endif
} mmi_bootup_sim_selection_cntx_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/
#if (MMI_MAX_SIM_NUM >= 3)
static srv_bootup_protocol_mode_enum mmi_bootup_sim_selection_get_mark_result(mmi_bootup_sim_selection_cntx_struct *cntx);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of SIM-selection.
 *  This handler stores the index of current highlighted item.
 * PARAMETERS
 *  index   [IN] The index of highlighted
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_selection_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_sim_selection_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                SCR_ID_BOOTUP_SIM_SELECTION);
    
    if (cntx != NULL && cntx->grp_id == mmi_frm_group_get_active_id())
    {
        cntx->selected_index = index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_get_selected_mode
 * DESCRIPTION
 *  Get current selected mode on the SIM-selection menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  The mode selected.
 *****************************************************************************/
static srv_bootup_protocol_mode_enum mmi_bootup_sim_selection_get_selected_mode(
    mmi_bootup_sim_selection_cntx_struct *cntx)
{
#if (MMI_MAX_SIM_NUM >= 3) // Gemini+

    return mmi_bootup_sim_selection_get_mark_result(cntx);

#else /* MMI_MAX_SIM_NUM >= 3 */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const struct
    {
        U16 menu_id;
        srv_bootup_protocol_mode_enum mode;
    } menu_id_to_sim_mode[] =
    {
        { MENU_ID_BOOTUP_DUAL_SIM,  SRV_BOOTUP_PROTOCOL_MODE_DUAL_SIM },
        { MENU_ID_BOOTUP_SIM1_ONLY, SRV_BOOTUP_PROTOCOL_MODE_SIM1_ONLY },
        { MENU_ID_BOOTUP_SIM2_ONLY, SRV_BOOTUP_PROTOCOL_MODE_SIM2_ONLY },
        { 0, 0 }
    };
    
    U16 menu_id;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = GetSeqItemId_Ext(MENU_ID_BOOTUP_SIM_SELECTION, (U16)cntx->selected_index);

    for (i = 0; menu_id_to_sim_mode[i].menu_id != 0; i++)
    {
        if (menu_id_to_sim_mode[i].menu_id == menu_id)
        {
            return menu_id_to_sim_mode[i].mode;
        }
    }

    return SRV_BOOTUP_PROTOCOL_MODE_NONE;

#endif /* MMI_MAX_SIM_NUM >= 3 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_lsk_hdlr
 * DESCRIPTION
 *  LSK handler of SIM-selection screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_selection_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_sim_selection_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                SCR_ID_BOOTUP_SIM_SELECTION);

    if (cntx != NULL && cntx->grp_id == mmi_frm_group_get_active_id())
    {
        mmi_bootup_sim_selected_event_struct sel_evt;
        
        MMI_ASSERT(cntx->selected_proc != NULL);

        MMI_FRM_INIT_EVENT(&sel_evt, EVT_ID_MMI_BOOTUP_SCR_SELECTED_POSITIVE);
        sel_evt.handle = cntx;
        sel_evt.mode = mmi_bootup_sim_selection_get_selected_mode(cntx);

        if (MMI_FRM_SEND_EVENT(&sel_evt, cntx->selected_proc, cntx->user_data) ==
            MMI_BOOTUP_SCR_ALLOW_TO_CLOSE)
        {
            mmi_bootup_sim_selection_close(cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_rsk_hdlr
 * DESCRIPTION
 *  RSK handler of SIM-selection screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_selection_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_sim_selection_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                SCR_ID_BOOTUP_SIM_SELECTION);

    if (cntx != NULL && cntx->grp_id == mmi_frm_group_get_active_id())
    {
        mmi_bootup_sim_sel_negative_event_struct cancel_evt;
        
        MMI_ASSERT(cntx->neg_proc != NULL);

        MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_MMI_BOOTUP_SCR_SELECTED_NEGATIVE);
        cancel_evt.handle = cntx;
        if (MMI_FRM_SEND_EVENT(&cancel_evt, cntx->neg_proc, cntx->user_data) ==
            MMI_BOOTUP_SCR_ALLOW_TO_CLOSE)
        {
            mmi_bootup_sim_selection_close(cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_end_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bootup_sim_selection_end_key_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
        mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct*)evt;

        if (key_evt->key_code == KEY_END &&
            key_evt->key_type == KEY_EVENT_DOWN)
        {
            cntx = (mmi_bootup_sim_selection_cntx_struct*)evt->user_data;

            if (cntx != NULL &&
                cntx->grp_id == mmi_frm_group_get_active_id() &&
                cntx->neg_proc != NULL)
            {
                mmi_bootup_sim_sel_negative_event_struct del_evt;
                
                MMI_FRM_INIT_EVENT(&del_evt, EVT_ID_MMI_BOOTUP_SCR_DELETING);
                del_evt.handle = cntx;
                if (MMI_FRM_SEND_EVENT(&del_evt, cntx->neg_proc, cntx->user_data) ==
                    MMI_BOOTUP_SCR_ALLOW_TO_CLOSE)
                {
                    cntx->is_deleting = MMI_TRUE;
                    mmi_bootup_sim_selection_close(cntx);
                }
                else
                {
                    return MMI_RET_KEY_HANDLED;
                }
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_leave_proc
 * DESCRIPTION
 *  Handler of the leave event of the SIM selection screen.
 * PARAMETERS
 *  evt     [IN] mmi_scenario_evt_struct*
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bootup_sim_selection_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *scen_evt;
    mmi_bootup_sim_selection_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        scen_evt = (mmi_scenario_evt_struct*)evt;
    
        cntx = (mmi_bootup_sim_selection_cntx_struct*)
            mmi_frm_scrn_get_user_data(scen_evt->curr_group, scen_evt->curr_scrn);

        if (cntx != NULL &&
            cntx->neg_proc != NULL)
        {
            mmi_bootup_sim_sel_negative_event_struct del_evt;
            
            MMI_FRM_INIT_EVENT(&del_evt, EVT_ID_MMI_BOOTUP_SCR_DELETING);
            del_evt.handle = cntx;
            if (MMI_FRM_SEND_EVENT(&del_evt, cntx->neg_proc, cntx->user_data) ==
                MMI_BOOTUP_SCR_ALLOW_TO_CLOSE)
            {
                cntx->is_deleting = MMI_TRUE;
                mmi_bootup_sim_selection_close(cntx);
                return MMI_RET_ALLOW_CLOSE;
            }
            else
            {
                return -1; /* Forbid closing */
            }
        }
        
        return MMI_RET_ALLOW_CLOSE;
    }
    
    return MMI_RET_OK;
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_get_mark_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  *cntx
 * RETURNS
 *  srv_bootup_protocol_mode_enum
 *****************************************************************************/
static srv_bootup_protocol_mode_enum mmi_bootup_sim_selection_get_mark_result(mmi_bootup_sim_selection_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_protocol_mode_enum sel_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx != NULL);

    sel_setting =  (cntx->mark_flag[0]     )  // to count MMI_SIM1
                 | (cntx->mark_flag[1] << 1)  // to count MMI_SIM2
                 | (cntx->mark_flag[2] << 2)  // to count MMI_SIM3
    #if (MMI_MAX_SIM_NUM >= 4)
                 | (cntx->mark_flag[3] << 3)  // to count MMI_SIM4
    #endif
    ;

    return sel_setting;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_query_disable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_selection_query_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.callback = NULL;
    confirm_arg.parent_id = GRP_ID_BOOTUP;
    mmi_confirm_display(
        get_string(STR_ID_BOOTUP_SIM_NOT_SELECTED),
		MMI_EVENT_QUERY,
        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_query_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  *param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bootup_sim_selection_query_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {    
        case EVT_ID_ALERT_QUIT:
	    {
            mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)param;
            switch (confirm_evt->result)
    	    {
                case MMI_ALERT_CNFM_YES:
                	GoBackHistory();
                    mmi_bootup_sim_selection_lsk_hdlr();
                    break;

                case MMI_ALERT_CNFM_NO:
                    GoBackHistory();
                    break;

                default:
                    break;
            }
    	}
    }

    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_change_mark_state
 * DESCRIPTION
 *  The entry function to toggle SIM selection mark screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_selection_change_mark_state(void) // Gemini+
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_sim_selection_cntx_struct*)mmi_frm_scrn_get_user_data(
                mmi_frm_group_get_active_id(),
                SCR_ID_BOOTUP_SIM_SELECTION);

    standard_check_list_handle_item_select(cntx->selected_index);   

    cntx->mark_flag[cntx->selected_index] = !cntx->mark_flag[cntx->selected_index];

    if (mmi_bootup_sim_selection_get_mark_result(cntx) == 0)
    {
        SetLeftSoftkeyFunction(mmi_bootup_sim_selection_query_disable, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bootup_sim_selection_lsk_hdlr, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_disable_sim
 * DESCRIPTION
 *  The function to disable the item of SIM not inserted.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bootup_sim_selection_disable_sim(S32 index, U32 *flag, U32 *flag_ex) // Gemini+
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_bootup_sim_is_inserted(mmi_frm_index_to_sim(index)))
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_fte_tap_callback
 * DESCRIPTION
 *  The entry function to toggle SIM selection mark screen for FTE.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_sim_selection_fte_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_bootup_sim_selection_change_mark_state();
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


#endif /* (MMI_MAX_SIM_NUM >= 3) */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_sim_selection
 * DESCRIPTION
 *  The entry function of SIM selection screen.
 * PARAMETERS
 *  es_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_entry_sim_selection(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;
    U8 *gui_buffer;
    U16 num_of_items;

#if (MMI_MAX_SIM_NUM >= 3) 
    S32 index;
    
    static const U16 SIM_STR[] =
    {
        STR_GLOBAL_SIM_1,
        STR_GLOBAL_SIM_2,
        STR_GLOBAL_SIM_3,
#if (MMI_MAX_SIM_NUM >= 4) 
        STR_GLOBAL_SIM_4,
#endif
    };
#else
    U16 *item_string_ids;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(es_data != NULL && es_data->user_data != NULL);
    
    cntx = (mmi_bootup_sim_selection_cntx_struct*)es_data->user_data;

    if (!mmi_frm_scrn_enter(
            cntx->grp_id,
            SCR_ID_BOOTUP_SIM_SELECTION,
            NULL,
            (FuncPtr)mmi_bootup_entry_sim_selection,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

#if (MMI_MAX_SIM_NUM >= 3)
    num_of_items = MMI_SIM_TOTAL;

    for (index = 0; index < num_of_items; index++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(index);
        if (srv_bootup_sim_is_inserted(sim))
        {
            mmi_wcsncpy(
                (WCHAR*)subMenuData[index],
                get_string(SIM_STR[index]),
                sizeof(subMenuData[0]) / sizeof(WCHAR) - 1);
        }
        else
        {
            cntx->mark_flag[index] = 0;
            mmi_sim_ctrl_gen_str(
                (WCHAR*)subMenuData[index],
                sizeof(subMenuData[0]) / sizeof(WCHAR) - 1,
                STR_ID_BOOTUP_SIMX_NOT_INSERTED,
                sim);
        }
    }

    RegisterHighlightHandler(mmi_bootup_sim_selection_highlight_hdlr);
    wgui_fixed_list_register_get_flags_handler(mmi_bootup_sim_selection_disable_sim);

#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */

    ShowCategory12Screen(
        cntx->title_str_id,
        cntx->title_icon_id,
        cntx->select_str_id,
        0, /* left_softkey_icon */
        cntx->cancel_str_id,
        0, /* right_softkey_icon */
        num_of_items,
        (U8 **) subMenuDataPtrs,
        cntx->mark_flag,
        0,
        gui_buffer);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(mmi_bootup_sim_selection_change_mark_state);
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_bootup_sim_selection_fte_tap_callback);
#endif

#ifndef __MMI_WGUI_DISABLE_CSK__
    SetCenterSoftkeyFunction(mmi_bootup_sim_selection_change_mark_state, KEY_EVENT_UP);
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */

    if (mmi_bootup_sim_selection_get_mark_result(cntx) == 0)
    {
        SetLeftSoftkeyFunction(mmi_bootup_sim_selection_query_disable, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_bootup_sim_selection_lsk_hdlr, KEY_EVENT_UP);
    }

#else /* (MMI_MAX_SIM_NUM >= 3) */

    num_of_items = GetNumOfChild(MENU_ID_BOOTUP_SIM_SELECTION);
    item_string_ids = (U16*)OslMalloc(sizeof(U16) * num_of_items);
    GetSequenceStringIds(MENU_ID_BOOTUP_SIM_SELECTION, item_string_ids);

    RegisterHighlightHandler(mmi_bootup_sim_selection_highlight_hdlr);

#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */

    ShowCategory11Screen(
        cntx->title_str_id,
        cntx->title_icon_id,
        cntx->select_str_id,
        0, /* left_softkey_icon */
        cntx->cancel_str_id,
        0, /* right_softkey_icon */
        (S32)num_of_items,
        item_string_ids,
        (U16)cntx->selected_index,
        gui_buffer);

    OslMfree(item_string_ids);

#ifndef __MMI_WGUI_DISABLE_CSK__
    SetCenterSoftkeyFunction(mmi_bootup_sim_selection_lsk_hdlr, KEY_EVENT_UP);
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */
    SetLeftSoftkeyFunction(mmi_bootup_sim_selection_lsk_hdlr, KEY_EVENT_UP);

#endif /* (MMI_MAX_SIM_NUM >= 3) */

    SetRightSoftkeyFunction(mmi_bootup_sim_selection_rsk_hdlr, KEY_EVENT_UP);

    mmi_frm_scrn_set_key_proc(cntx->grp_id, SCR_ID_BOOTUP_SIM_SELECTION, mmi_bootup_sim_selection_end_key_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_show
 * DESCRIPTION
 *  Show SIM-selection menu.
 * PARAMETERS
 *  title_str_id    [IN] Title string ID.
 *  title_icon_id   [IN] Title icon ID.
 *  user_data       [IN] Will be passed into selected_hdlr and cancel_hdlr.
 *  select_str_id   [IN] String ID to prompt "Select"
 *  selected_proc   [IN] 
 *  cancel_str_id   [IN] String ID to prompt "Cancel"
 *  neg_proc        [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
mmi_bootup_sim_selection_handle mmi_bootup_sim_selection_show(
    mmi_id grp_id,
    U16 title_str_id,
    U16 title_icon_id,
    void *user_data,
    U16 select_str_id,
    mmi_proc_func selected_proc,
    U16 cancel_str_id,
    mmi_proc_func neg_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;

#if (MMI_MAX_SIM_NUM >= 3)
// slim_var
    U32 index;
    MMI_BOOL sim_currently_inserted, sim_previously_selected;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_bootup_sim_selection_cntx_struct*)OslMalloc(sizeof(mmi_bootup_sim_selection_cntx_struct));

    cntx->grp_id = grp_id;
    cntx->title_str_id = title_str_id;
    cntx->title_icon_id = title_icon_id;
    cntx->select_str_id = select_str_id;
    cntx->cancel_str_id = cancel_str_id;
    cntx->user_data = user_data;
    cntx->selected_proc = selected_proc;
    cntx->neg_proc = neg_proc;
    cntx->selected_index = 0;
    cntx->is_deleting = MMI_FALSE;

#if (MMI_MAX_SIM_NUM >= 3) 
    for (index = 0; index < SRV_SIM_CTRL_MAX_SIM_NUM; index++)
    {
        sim_currently_inserted = srv_bootup_sim_is_inserted(mmi_frm_index_to_sim(index)); // Gemini+
        sim_previously_selected = (MMI_BOOL)(mmi_bootup_get_protocol_mode_setting() & (1<<index));
        cntx->mark_flag[index] = (sim_currently_inserted && sim_previously_selected) ? 1 : 0;
    }

    mmi_frm_group_set_proc_data(cntx->grp_id, mmi_bootup_sim_selection_query_proc, NULL);
#endif

    mmi_frm_scrn_first_enter(
        cntx->grp_id,
        SCR_ID_BOOTUP_SIM_SELECTION,
        (FuncPtr)mmi_bootup_entry_sim_selection,
        cntx);

    mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_SIM_SELECTION, mmi_bootup_sim_selection_leave_proc);

    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_sim_selection_close
 * DESCRIPTION
 *  Close SIM-selection screen.
 * PARAMETERS
 *  handle  [IN] The handle of SIM selection screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_sim_selection_close(mmi_bootup_sim_selection_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_sim_selection_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == NULL)
    {
        return;
    }

    cntx = (mmi_bootup_sim_selection_cntx_struct*)handle;

    mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_SIM_SELECTION, NULL);

    if (!cntx->is_deleting)
    {
        mmi_frm_scrn_close(cntx->grp_id, SCR_ID_BOOTUP_SIM_SELECTION);
    }
    
    OslMfree(cntx);
}

#endif /* (MMI_MAX_SIM_NUM >= 2) && defined(__MMI_BOOTUP_MODE_SEL_SUPPORT__) */


