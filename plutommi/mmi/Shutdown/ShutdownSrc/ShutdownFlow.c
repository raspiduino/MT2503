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
 *  ShutdownFlow.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Shutdown flow control
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "ShutdownSrvIprot.h"
#include "ShutdownProt.h"
#include "mmi_rp_app_shutdown_def.h"
#include "GpioSrvGprot.h" /* srv_vibrator_play_once */
#include "ProcedureGprot.h"
#ifdef OPERA_BROWSER
#include "opera_adp_shutdown.h"
#endif

#include "CallLogSrvGprot.h"  /* For srv_clog_shutdown_hdlr() */
#include "ProcedureConfig.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_res_range_def.h"
#include "ShutdownSrvGprot.h"
#include "custom_led_patterns.h"
#include "gpiosrvgprot.h"
#ifdef __MMI_BT_DIALER_SUPPORT__
#include "BTMMIScrGprots.h"
#endif


/****************************************************************************
 * Configurations
 ****************************************************************************/

/* Timeout to shutdown directly even if something not complete */
#define MMI_SHUTDOWN_PROCESS_TIMEOUT    15000 /* ms */

/*
 * Asynchronous deinit procedures
 */
static mmi_frm_proc_result_enum mmi_shutdown_flow_deinit(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
                                    
static mmi_frm_proc_result_enum mmi_shutdown_flow_deinit_protocol(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);
                                    
static mmi_frm_proc_result_enum mmi_shutdown_conc_dummy(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);                                    

MMI_FRM_PROC_CON_DECLARE_BEGIN(g_mmi_shutdown_waiting)
#ifdef __MTK_TARGET__
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_PROTOCOL, mmi_shutdown_flow_deinit_protocol, NULL)
#endif
#if defined(OBIGO_Q03C_MMS_V02) && defined(WAP_SUPPORT)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_MMS_WAP, mmi_mms_deinit, NULL)
#elif defined(WAP_SUPPORT)
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_WAP, mmi_wap_deinit, NULL)
#endif
#ifdef OPERA_BROWSER
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_OPERA_BROWSER, mmi_opera_brw_deinit, NULL)
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_CALL_LOG, srv_clog_shutdown_hdlr, NULL)
#else
		MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_BOOTUP_SHUTDOWN_DUMMY, mmi_shutdown_conc_dummy, NULL)  //just for avoid build error in bt only project    
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    /* --- Register the non-blocking deinit procedure before this entry --- */
#ifndef __MMI_BTBOX_NOLCD__
    MMI_FRM_PROC_CON_ENTRY(MMI_FRM_PROC_ID_SHUTDOWN_ANIMATION, mmi_shutdown_play_animation, NULL)
#endif    
MMI_FRM_PROC_CON_DECLARE_END(g_mmi_shutdown_waiting, NULL, NULL)


/*
 * Sequential main flow of shutdown
 */
static const mmi_frm_proc_struct g_mmi_shutdown_main_flow[] =
{
#ifdef __MMI_BT_DIALER_SUPPORT__
    { MMI_FRM_PROC_ID_SHUTDOWN_BT_DIALER_OFF, mmi_bt_dialer_shutdown, NULL},
#endif
    { MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_APPS, mmi_shutdown_flow_deinit, NULL },
    { MMI_FRM_PROC_ID_SHUTDOWN_WAITING, mmi_frm_proc_con_create_and_execute, (void*)&g_mmi_shutdown_waiting }
};


/****************************************************************************
 * Global functions
 ****************************************************************************/

typedef struct
{
    mmi_frm_proc_struct *flow_proc;
    mmi_frm_proc_id_info_struct animation_id_info;
    mmi_frm_proc_id_info_struct deinit_protocol_id_info;
} mmi_shutdown_cntx_struct;


static mmi_shutdown_cntx_struct *g_mmi_shutdown_cntx = NULL;

/****************************************************************************
 * Functions
 ****************************************************************************/

static void mmi_shutdown_flow_deinit_protocol_completed(void *user_data);
static mmi_ret mmi_shutdown_flow_completed(mmi_event_struct *evt);
static void mmi_shutdown_process_timeout_handler(void *arg);


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_grp_proc
 * DESCRIPTION
 *  Proc function for shutdown group
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_shutdown_grp_proc(mmi_event_struct *evt)
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
 *  mmi_shutdown_base_leave_proc
 * DESCRIPTION
 *  Leave proc for shutdown base screen.
 *  To prevent shutdown screen from being deleted.
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  -1 for delete events.
 *****************************************************************************/
static mmi_ret mmi_shutdown_base_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK ||
        evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        return -1;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_block_all_keys
 * DESCRIPTION
 *  Key proc to block all key on the dummy screen
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_KEY_HANDLED for all PRE_KEY events
 *****************************************************************************/
static mmi_ret mmi_shutdown_block_all_keys(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
        return MMI_RET_KEY_HANDLED;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_entry_base_dummy
 * DESCRIPTION
 *  Entry function for the base dummy screen of shutdown.
 * PARAMETERS
 *  es_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_shutdown_entry_base_dummy(mmi_scrn_essential_struct *es_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        GRP_ID_SHUTDOWN,
        SCR_ID_SHUTDOWN_BASE,
        NULL,
        (FuncPtr)mmi_shutdown_entry_base_dummy,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategoryDummyScreen();
    mmi_frm_scrn_set_key_proc(GRP_ID_SHUTDOWN, SCR_ID_SHUTDOWN_BASE, mmi_shutdown_block_all_keys);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_normal_start
 * DESCRIPTION
 *  Entry point of shutdown flow.
 * PARAMETERS
 *  evt     [IN] srv_shutdown_normal_start_evt_struct*
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_shutdown_normal_start(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_shutdown_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_shutdown_cntx != NULL)
    {
        return MMI_RET_OK;
    }

    g_mmi_shutdown_cntx = (mmi_shutdown_cntx_struct*)
        OslMalloc(sizeof(mmi_shutdown_cntx_struct));
    cntx = g_mmi_shutdown_cntx;

    MMI_TRACE(MMI_SHUTDOWN_TRC_GROUP, TRC_MMI_SHUTDOWN_NORMAL_START, (U32)cntx);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);

#ifdef __MMI_POWER_ON_OFF_MUTE__
    srv_vibrator_play_once();
#endif

    /* Create screen group for shutdown and put a base screen */
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_SHUTDOWN,
        mmi_shutdown_grp_proc,
        cntx);
    mmi_frm_group_enter(GRP_ID_SHUTDOWN, MMI_FRM_NODE_NONE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_SHUTDOWN,
        SCR_ID_SHUTDOWN_BASE,
        (FuncPtr)mmi_shutdown_entry_base_dummy,
        cntx);
    mmi_frm_scrn_set_leave_proc(
        GRP_ID_SHUTDOWN,
        SCR_ID_SHUTDOWN_BASE,
        mmi_shutdown_base_leave_proc);

    /* Execute shutdown flow */
    cntx->flow_proc = mmi_frm_proc_seq_create(
        mmi_frm_proc_allocate_id(),
        g_mmi_shutdown_main_flow,
        sizeof(g_mmi_shutdown_main_flow) / sizeof(g_mmi_shutdown_main_flow[0]));

    mmi_frm_proc_post_complete_execute(
        MMI_FRM_PROC_ID_SHUTDOWN,
        mmi_shutdown_flow_completed,
        cntx,
        cntx->flow_proc);

    return MMI_RET_OK;
}



static mmi_frm_proc_result_enum mmi_shutdown_conc_dummy(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
                                    
{
         return MMI_FRM_PROC_RESULT_COMPLETED;                  	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_flow_deinit
 * DESCRIPTION
 *  Deinit procedure for shutdown flow.
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] ID info; unused
 * RETURNS
 *  MMI_FRM_PROC_RESULT_COMPLETED
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_shutdown_flow_deinit(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_shutdown_deinit();

    StartTimerEx(
        SHUTDOWN_PROCESS_TIMER,
        MMI_SHUTDOWN_PROCESS_TIMEOUT,
        mmi_shutdown_process_timeout_handler,
        &g_mmi_shutdown_cntx);

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_flow_deinit_protocol
 * DESCRIPTION
 *  Deinitialize protocol
 * PARAMETERS
 *  arg         [IN] Unused
 *  id_info     [IN] To be passed into mmi_frm_proc_notify_completed
 * RETURNS
 *  MMI_FRM_PROC_RESULT_COMPLETED
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_shutdown_flow_deinit_protocol(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_shutdown_cntx->deinit_protocol_id_info = id_info;
    
    srv_shutdown_deinit_protocol(
        mmi_shutdown_flow_deinit_protocol_completed,
        g_mmi_shutdown_cntx);

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_flow_deinit_protocol_completed
 * DESCRIPTION
 *  Completed callback for protocol deinitialization.
 * PARAMETERS
 *  user_data   [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_shutdown_flow_deinit_protocol_completed(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_notify_completed(g_mmi_shutdown_cntx->deinit_protocol_id_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_flow_completed
 * DESCRIPTION
 *  Callback for shutdown flow completed.
 * PARAMETERS
 *  evt     [IN] mmi_frm_proc_completed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_shutdown_flow_completed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_SHUTDOWN_TRC_GROUP, TRC_MMI_SHUTDOWN_FLOW_COMPLETED);
    
    StopTimer(SHUTDOWN_PROCESS_TIMER);

    mmi_frm_proc_seq_destroy(g_mmi_shutdown_cntx->flow_proc);
    g_mmi_shutdown_cntx->flow_proc = NULL;
    
    srv_shutdown_exit_system(APP_SHUTDOWN);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_shutdown_process_timeout_handler
 * DESCRIPTION
 *  Timeout for shutdown procedure. Power-off directly.
 * PARAMETERS
 *  arg     [IN] Unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_shutdown_process_timeout_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_SHUTDOWN_TRC_GROUP, TRC_MMI_SHUTDOWN_TIMEOUT);

    /* Force to stop animation */
#ifndef	__MMI_BTBOX_NOLCD__
    mmi_shutdown_ani_stop();
#endif    
    /* Shutdown abnormally */
    srv_shutdown_exit_system(APP_SHUTDOWN);
}
