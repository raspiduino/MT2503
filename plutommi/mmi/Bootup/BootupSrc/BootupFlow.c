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
 *  BootupFlow.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Bootup flow control
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "BootupSrvIprot.h"
#include "ProcedureGprot.h"
#include "ShutdownSrvGprot.h"
#include "BootupAppProt.h"
#include "GpioSrvGprot.h" /* srv_vibrator_play_once */
#include "ProcedureConfig.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BootupSrvGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_bootup_def.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "BootupScrUtil.h"
#include "GlobalResDef.h"
#include "BootupAppGprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "custom_led_patterns.h"
#include "gpiosrvgprot.h"
#include "IdleGprot.h"

#if defined(__MMI_BTBOX_NOLCD__)//__MMI_FRM_INPUT_EVT__
#include "mmi_frm_input_event.h"
#endif/*#if defined(__MMI_BTBOX_NOLCD__)*/
#ifdef __MMI_LINE_IN__
#include "LineinGprot.h"
#endif /* __MMI_LINE_IN__ */


/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_BOOTUP_WAITING_TIMEOUT_VALUE 2000 /* ms */


/****************************************************************************
 * Flow configurations
 ****************************************************************************/

/*
 * Configuration dependency:
 *
 * EARLY_INIT   -> DISK_CHECK
 *              -> ANIMATION
 *              -> PEN CALIBRATION
 *              -> Any UI screens
 * INIT_SIM_MODULE   -> MODE_DECISION    -> PROTOCOL     -> SECURITY
 */

/* ------ Waiting for events ------ */

static mmi_frm_proc_result_enum mmi_bootup_start_events_timer(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

static mmi_frm_proc_ctrl_enum mmi_bootup_events_stop_on_timeout(
    void *user_data,
    const mmi_frm_proc_set_status_struct *info);

MMI_FRM_PROC_CON_DECLARE_BEGIN(g_bootup_waiting_con_proc)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_WAITING_TIMER, mmi_bootup_start_events_timer, NULL)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_WAIT_FOR_GPIO, mmi_bootup_wait_for_gpio, NULL)
MMI_FRM_PROC_CON_DECLARE_END(g_bootup_waiting_con_proc, mmi_bootup_events_stop_on_timeout, NULL)


/* ------ Animation ------ */

MMI_FRM_PROC_CON_DECLARE_BEGIN(g_bootup_animation_phase)
#if (defined (__MOD_RAC__) && defined (__MMI_TELEPHONY_SUPPORT__))
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_PROTOCOL, mmi_bootup_boot_protocol, NULL)
#endif /* __MOD_RAC__ */
#ifndef __MMI_BTBOX_NOLCD__
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_ANIMATION, mmi_bootup_play_animation, NULL)
#else
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_PLAYTONE, mmi_bootup_play_tone, NULL)
#endif


    /*
     * NORMAL_INIT should be the last entry, because:
     * 1. It is a time-consuming blocking function. As we call it, following procedures should be
     *    delayed to it completes
     * 2. Apps in NORMAL_INIT may determines the state set in boot_protocol()
     */
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_NORMAL_INIT, mmi_bootup_normal_init, NULL)
MMI_FRM_PROC_CON_DECLARE_END(g_bootup_animation_phase, mmi_bootup_ani_notify_completion_info, NULL)


/* ------ Main flow ------ */

static mmi_frm_proc_result_enum mmi_bootup_flow_early_init(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

static mmi_frm_proc_result_enum mmi_bootup_flow_disable_interrupt(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

static mmi_frm_proc_result_enum mmi_bootup_flow_enable_interrupt(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);

static const mmi_frm_proc_struct g_mmi_bootup_main_flow[] =
{
    { MMI_FRM_PROC_ID_BOOTUP_WAIT_FOR_EVENTS, mmi_frm_proc_con_create_and_execute, (void*)&(g_bootup_waiting_con_proc) },
    { MMI_FRM_PROC_ID_BOOTUP_EARLY_INIT, mmi_bootup_flow_early_init, NULL },
#ifndef __MMI_BTBOX_NOLCD__
    { MMI_FRM_PROC_ID_BOOTUP_DISABLE_INTERRUPT, mmi_bootup_flow_disable_interrupt, NULL },
#endif    
#if (MMI_MAX_SIM_NUM >= 2)
    { MMI_FRM_PROC_ID_BOOTUP_INIT_SIM, mmi_bootup_flow_init_sim_module, NULL },
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
    { MMI_FRM_PROC_ID_BOOTUP_MODE_DECISION, mmi_bootup_decide_mode, NULL },
#endif    
    { MMI_FRM_PROC_ID_BOOTUP_ANI_PHASE, mmi_frm_proc_con_create_and_execute, (void*)&(g_bootup_animation_phase) },
#ifndef __MMI_BTBOX_NOLCD__
    { MMI_FRM_PROC_ID_BOOTUP_ENABLE_INTERRUPT, mmi_bootup_flow_enable_interrupt, NULL },
#endif	
#ifdef __MMI_TOUCH_SCREEN__
    { MMI_FRM_PROC_ID_BOOTUP_PEN_CALIBRATION, mmi_bootup_flow_pen_calibration, NULL },
#endif
#ifndef __MMI_BTBOX_NOLCD__
    { MMI_FRM_PROC_ID_BOOTUP_BATTERY_CHECK, mmi_bootup_flow_battery_check, NULL },
#endif    
#ifdef __MMI_TELEPHONY_SUPPORT__
    { MMI_FRM_PROC_ID_BOOTUP_SECURITY, mmi_bootup_flow_security, NULL },
#endif    
#ifdef __GADGET_SUPPORT__
    { MMI_FRM_PROC_ID_BOOTUP_PREINSTALL_WIDGET, mmi_wgtmgr_preinstall_widget, NULL },
#endif
#if (defined (__MMI_BT_DIALER_SUPPORT__) && !defined(__MMI_BTD_BOX_UI_STYLE__) && !defined(__MMI_WEARABLE_DEVICE__) && !defined(__MMI_BTBOX_NOLCD__))
    { MMI_FRM_PROC_ID_BOOTUP_FTU, mmi_bootup_flow_ftu, NULL }
#endif
};


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_frm_proc_struct *main_flow;

    struct
    {
        MMI_BOOL timeout;
        mmi_frm_proc_id_info_struct id_info;
    } events_timer;

    struct
    {
        mmi_frm_proc_id_info_struct id_info;
    } disk_check;

    struct
    {
        S8 disabled_count;
    } interrupt;
} mmi_bootup_flow_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static mmi_bootup_flow_cntx_struct g_mmi_bootup_flow_cntx;


/****************************************************************************
 * Local functions
 ****************************************************************************/

static void mmi_bootup_events_timer_timeout(void);
static mmi_ret mmi_bootup_flow_completed(mmi_event_struct *evt);
static void mmi_bootup_disk_check_completed(void *user_data, S32 error_code);
static mmi_frm_proc_ctrl_enum mmi_bootup_flow_stop_check(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status);


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_start
 * DESCRIPTION
 *  Start booting flow.
 *  This function is the handler of EVT_ID_BOOTUP_START.
 * PARAMETERS
 *  evt     [IN] srv_bootup_start_evt_struct*
 * RETURNS
 *  Always MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_bootup_flow_start(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_BOOTUP_START);

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_FLOW_START);

    g_mmi_bootup_flow_cntx.interrupt.disabled_count = 0;

    g_mmi_bootup_flow_cntx.main_flow = mmi_frm_proc_seq_create(
        mmi_frm_proc_allocate_id(),
        g_mmi_bootup_main_flow,
        sizeof(g_mmi_bootup_main_flow) / sizeof(g_mmi_bootup_main_flow[0]));

    mmi_frm_proc_seq_set_status_callback(
        g_mmi_bootup_flow_cntx.main_flow,
        mmi_bootup_flow_stop_check,
        &(g_mmi_bootup_flow_cntx));

    mmi_frm_proc_post_complete_execute(
        MMI_FRM_PROC_ID_BOOTUP_MAIN,
        mmi_bootup_flow_completed,
        &(g_mmi_bootup_flow_cntx),
        g_mmi_bootup_flow_cntx.main_flow);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_events_all_completed_or_timeout
 * DESCRIPTION
 *  The complete condition of event waiting.
 *  Waiting for all events until timeout.
 * PARAMETERS
 *  user_data   [IN] Not used
 *  info        [IN] Information of completion.
 * RETURNS
 *  MMI_FRM_PROC_CTRL_STOP if timeout
 *****************************************************************************/
static mmi_frm_proc_ctrl_enum mmi_bootup_events_stop_on_timeout(
    void *user_data,
    const mmi_frm_proc_set_status_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->n_completed >= (info->n_total_procs - 1) ||
        g_mmi_bootup_flow_cntx.events_timer.timeout)
    {
        return MMI_FRM_PROC_CTRL_STOP;
    }

    return MMI_FRM_PROC_CTRL_CONTINUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_start_events_timer
 * DESCRIPTION
 *  Start the timer of event waiting.
 * PARAMETERS
 *  arg         [IN] Not used
 *  if_info     [IN] To be carried back to mmi_frm_proc_notify_completed()
 * RETURNS
 *  MMI_FRM_PROC_RESULT_NOTIFY_LATER
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_bootup_start_events_timer(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_flow_cntx.events_timer.timeout = MMI_FALSE;
    g_mmi_bootup_flow_cntx.events_timer.id_info = id_info;

    StartTimer(BOOTUP_WAITING_EVENT_TIMER, MMI_BOOTUP_WAITING_TIMEOUT_VALUE, mmi_bootup_events_timer_timeout);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_events_timer_timeout
 * DESCRIPTION
 *  Timeout callback of event timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_events_timer_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_EVENT_TIMER_TIMEOUT);
    
    g_mmi_bootup_flow_cntx.events_timer.timeout = MMI_TRUE;
    mmi_frm_proc_notify_completed(g_mmi_bootup_flow_cntx.events_timer.id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_dummy_base_screen
 * DESCRIPTION
 *  Put a dummy base screen in history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_entry_dummy_base_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        GRP_ID_BOOTUP,
        SCR_ID_BOOTUP_BASE,
        NULL,
        mmi_bootup_entry_dummy_base_screen,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategoryDummyScreen();

    mmi_frm_scrn_set_key_proc(GRP_ID_BOOTUP, SCR_ID_BOOTUP_BASE, mmi_bootup_block_all_keys);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_early_init
 * DESCRIPTION
 *  Early initialize & disk check.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be carried back to mmi_frm_proc_notify_completed()
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_bootup_flow_early_init(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_FLOW_EARLY_INIT);
    
    StopTimer(BOOTUP_WAITING_EVENT_TIMER);

#ifdef __MMI_POWER_ON_OFF_MUTE__
    srv_vibrator_play_once();
#endif
    
    mmi_bootup_early_init();

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_BOOTUP, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_BOOTUP, MMI_FRM_NODE_NONE_FLAG);
    /*
     * Put a dummy base screen on bottom, so that history manipulation
     * can be performed normally.
     */
    mmi_bootup_entry_dummy_base_screen();
    mmi_frm_scrn_set_leave_proc(GRP_ID_BOOTUP, SCR_ID_BOOTUP_BASE, mmi_bootup_block_scr_deleting);

#if defined(__MMI_SUBLCD__)
    /* Display the bootup animation on the sub-LCD screen. */
    ForceSubLCDScreen(mmi_bootup_sublcd_entry);
#endif /* #if defined(__MMI_SUBLCD__) */

    /* Disk check */
    g_mmi_bootup_flow_cntx.disk_check.id_info = id_info;
    mmi_bootup_check_disk(
        GRP_ID_BOOTUP,
        mmi_bootup_disk_check_completed,
        &(g_mmi_bootup_flow_cntx.disk_check.id_info));

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disk_check_completed
 * DESCRIPTION
 *  The completed callback of disk check.
 * PARAMETERS
 *  user_data   [IN] Unused
 *  error_code  [IN] Error code from file system while checking disk
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_disk_check_completed(void *user_data, S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_DISK_CHECK_COMPLETED, error_code);
    
    mmi_frm_proc_notify_completed(
        g_mmi_bootup_flow_cntx.disk_check.id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_emit_interruptible_event
 * DESCRIPTION
 *  Emit interruptable_changed event.
 * PARAMETERS
 *  post_event      [IN] Emit event by post mechanism
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_emit_interruptible_event(MMI_BOOL post_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_interruptible_changed_evt_struct changed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_FRM_INIT_EVENT(&changed_evt, EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED);
    
    changed_evt.is_interruptible = mmi_bootup_is_interruptible();

    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_BOOTUP_EMIT_INTERRUPTIBLE_EVENT,
        changed_evt.is_interruptible, post_event);
    
    if (post_event)
    {
        MMI_FRM_CB_EMIT_POST_EVENT(&changed_evt);
    }
    else
    {
        MMI_FRM_CB_EMIT_EVENT(&changed_evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_disable_interrupt
 * DESCRIPTION
 *  Disable interrupt
 * PARAMETERS
 *  post_event      [IN] Emit event by post mechanism
 * RETURNS
 *  void
 *****************************************************************************/
// slim_static
static void mmi_bootup_disable_interrupt(MMI_BOOL post_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_flow_cntx.interrupt.disabled_count++;
    
    if (g_mmi_bootup_flow_cntx.interrupt.disabled_count == 1)
    {
        mmi_bootup_emit_interruptible_event(post_event);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_enable_interrupt
 * DESCRIPTION
 *  Enable interrupt. Enable/disable maintains a counter of disables.
 * PARAMETERS
 *  post_event      [IN] Emit event by post mechanism
 * RETURNS
 *  void
 *****************************************************************************/
// slim_static
static void mmi_bootup_enable_interrupt(MMI_BOOL post_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_bootup_flow_cntx.interrupt.disabled_count--;
    
    if (g_mmi_bootup_flow_cntx.interrupt.disabled_count == 0)
    {
        mmi_bootup_emit_interruptible_event(post_event);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_set_scenario_for_interrupt
 * DESCRIPTION
 *  Set framework scenario to launch deferred interrupts.
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bootup_set_scenario_for_interrupt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_interruptible_changed_evt_struct *changed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    changed_evt = (mmi_bootup_interruptible_changed_evt_struct*)evt;

    if (!changed_evt->is_interruptible)
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    }
    else
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_disable_interrupt
 * DESCRIPTION
 *  Disable interrupt in bootup flow.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_bootup_flow_disable_interrupt(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * Disallow all interrupts until animation completed
     */
    mmi_bootup_disable_interrupt(MMI_FALSE);

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_enable_interrupt
 * DESCRIPTION
 *  Enable interrupt in bootup flow.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_bootup_flow_enable_interrupt(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * As this event emitted, some screen may be triggered.
     * In order to avoid interrupt our control flow, emit as post
     * event here.
     */
    mmi_bootup_enable_interrupt(MMI_TRUE);

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_is_interruptible
 * DESCRIPTION
 *  Query if current screen is interruptable. Unly ultra-high priority events
 *  can interrupt booting screens; such as incoming call.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bootup_is_interruptible(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bootup_flow_cntx.interrupt.disabled_count == 0)
		return MMI_TRUE;
	else
		return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_stop_check
 * DESCRIPTION
 *  Stop the flow if shutdown is launched
 * PARAMETERS
 *  user_data       [IN]
 *  set_status      [IN] Status of procedure set
 * RETURNS
 *  mmi_frm_proc_ctrl_enum
 *****************************************************************************/
static mmi_frm_proc_ctrl_enum mmi_bootup_flow_stop_check(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_shutdown_is_running() ?
        MMI_FRM_PROC_CTRL_STOP : MMI_FRM_PROC_CTRL_CONTINUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_flow_completed
 * DESCRIPTION
 *  Query if current screen is interruptable. Only ultra-high priority events
 *  can interrupt booting screens; such as incoming call.
 * PARAMETERS
 *  evt     [IN] mmi_frm_proc_completed_evt_struct *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bootup_flow_completed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_seq_destroy(g_mmi_bootup_flow_cntx.main_flow);
    g_mmi_bootup_flow_cntx.main_flow = NULL;

    if (srv_shutdown_is_running())
    {
        return MMI_RET_OK;
    }

    /*
     * [MAUI_02288699]
     * We should close waiting first, otherwise it may be shown during
     * accessing NVRAM on BEFORE_IDLE event.
     */
    mmi_bootup_waiting_screen_close(GRP_ID_BOOTUP);
    
    mmi_bootup_notify_before_idle();

#if defined(__MMI_BTBOX_NOLCD__)//__MMI_FRM_INPUT_EVT__
    //mmi_frm_input_event_check_info_tbl();
    //mmi_frm_input_event_init();
  #ifdef __MMI_LINE_IN__
    if (!mmi_linein_is_plug_in())
  #endif /* __MMI_LINE_IN__ */
    {
        mmi_frm_input_event_goto_first_local_app();
    }
#else/*__MMI_BTBOX_NOLCD__*/
    mmi_idle_launch(GRP_ID_BOOTUP);

    /* Clear leave proc of the base screen, to allow being closed */
    mmi_frm_scrn_set_leave_proc(GRP_ID_BOOTUP, SCR_ID_BOOTUP_BASE, NULL);

    mmi_frm_group_close(GRP_ID_BOOTUP);
#endif/*#if defined(__MMI_BTBOX_NOLCD__)*/

    /* Change service status first */
    srv_bootup_notify_completed();
    /* Notify application finally */
    mmi_bootup_notify_completed();

    return MMI_RET_OK;
}


