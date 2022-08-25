/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the main component of the idle application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "PhbSrvGprot.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "CallSetSrvGprot.h"
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#include "DtcntSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "GpioSrvGprot.h"

#if defined(__TCPIP__)
#include "CbmSrvGprot.h"        /* Bearer info for CSD icon */
#endif

#include "IdleObject.h"
#include "IdleGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "IdleMain.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "mmi_rp_app_idle_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "IdleFactory.h"
#include "IdleEventCfg.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "cbm_consts.h"
#include "cbm_api.h"
#include "GlobalResDef.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "mmi_rp_srv_nw_name_def.h"
#endif
#include "IdleAdapter.h"
#include "mmi_frm_mem_gprot.h"
#include "FactoryGprot.h"
#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
#endif
#endif
#include "PhoneSetupGprots.h"

/****************************************************************************
 * Global Context
 ****************************************************************************/

/* This structure defines the global context of the idle application. */
typedef struct
{
    mmi_idle_obj_struct *obj;
} mmi_idle_cntx_struct;

/* Idle global context. */
static mmi_idle_cntx_struct g_mmi_idle_cntx;


#if !(defined(__MMI_SUPPORT_ASMv2__) || defined(__MMI_VUI_SHELL_APP__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_LAUNCHER_APP_LIST__)) || defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__))
#define __MMI_IDLE_APP_NOT_USE_ASMv2__
#endif


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_obj
 * DESCRIPTION
 *  This function gets the current idle object.
 * PARAMETERS
 *  void
 * RETURNS
 *  OBject
 *****************************************************************************/
mmi_idle_obj_struct *mmi_idle_get_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_idle_cntx.obj;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_enter
 * DESCRIPTION
 *  This function emits the enter event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_emit_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_enter_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_ENTER, 200, obj->type));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_ENTER);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_exit
 * DESCRIPTION
 *  This function emits the exit event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_emit_exit(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_exit_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_EXIT, 200, obj->type));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_EXIT);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_before_group_enter
 * DESCRIPTION
 *  This function emits the before group enter event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_before_group_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_before_group_enter_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_BEFORE_GROUP_ENTER, 200, obj->type));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_BEFORE_GROUP_ENTER);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_group_enter
 * DESCRIPTION
 *  This function posts the group enter event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_group_enter(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_group_enter_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_GROUP_ENTER, 200, obj->type));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_GROUP_ENTER);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_before_group_exit
 * DESCRIPTION
 *  This function posts the group exit event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_before_group_exit(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_before_group_exit_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_BEFORE_GROUP_EXIT, 200, obj->type));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_BEFORE_GROUP_EXIT);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_group_exit
 * DESCRIPTION
 *  This function posts the group exit event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_group_exit(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_group_exit_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_GROUP_EXIT, 200, obj->type));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_GROUP_EXIT);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_launched
 * DESCRIPTION
 *  This function posts the after launch event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_launched(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_launched_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IDLE_LAUNCHED);
    evt.type = (mmi_idle_type_enum)obj->type;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_notify_req
 * DESCRIPTION
 *  This function emits the notify event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_notify_req(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_main_notify_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_NOTIFY_REQ, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_IDLE_MAIN_NOTIFY_REQ, obj->this_gid);
    evt.active_grp_id = mmi_frm_group_get_active_id();
    evt.active_scr_id = mmi_frm_scrn_get_active_id();

    mmi_frm_group_post_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_emit_update_req
 * DESCRIPTION
 *  This function emits the update event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_emit_update_req(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_main_update_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_EMIT_UPDATE_REQ, 200));

    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_IDLE_MAIN_UPDATE_REQ, obj->this_gid);

    mmi_frm_group_post_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_bootup_normal_init
 * DESCRIPTION
 *  This function handles the bootup normal init.
 * PARAMETERS
 *  event           : [IN]      Event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_bootup_normal_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_BOOTUP_NORMAL_INIT, 200));

    kal_mem_set(&g_mmi_idle_cntx, 0, sizeof(mmi_idle_cntx_struct));

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_group_active
 * DESCRIPTION
 *  This function handle the idle group active event.
 * PARAMETERS
 *  event           : [IN]      Event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_group_active(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();
    S16 new_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_GROUP_ACTIVE, 200));

    MMI_ASSERT(obj);

    /*
     * Enter idle group. Deinit the scenario to release all resources and start
     * the idle scenario with the lowest priority.
     */
    mmi_frm_deinit_scenario();
    mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);
    mmi_frm_start_scenario(MMI_SCENARIO_ID_IDLE);

    /*
     * Emit events.
     */
    mmi_idle_emit_before_group_enter(obj);
    mmi_idle_emit_group_enter(obj);

    /*
     * Handle the situation that the favorite type of the idle is changed.
     */
    new_type = mmi_factory_get_favorite_type(mmi_idle_get_cfg_table());

    if (obj->type != new_type)
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_RECREATE, 200, obj->type, new_type));

        /* Set the flag on such that the old idle group can be deleted.  */
        obj->is_self_deleted = MMI_TRUE;

        /* Close the previous idle object. */
        MMI_ASSERT(obj->on_close);
        obj->on_close(obj);


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

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_group_inactive
 * DESCRIPTION
 *  This function handles the group inactive event.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_group_inactive(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_GROUP_INACTIVE, 200));

    MMI_ASSERT(obj);

    /*
     * Enter other groups.
     */
    mmi_frm_end_scenario(MMI_SCENARIO_ID_IDLE);

    /*
     * If other groups don't start another scenario, the scenario will become
     * invalid after we end the idle scenario. Set it to default scenario.
     *
     * TODO: Framework should use the default scenario directly in this case.
     *
     * Remove the condition to check invalid scenario.
     * Because when inactive idle group if there is another low priority scenario is
     * started(Cell Broad cast message, which is not shown in idle group), we will not
     * start the default scenario, so when CBS's scenario is ended, the scenario will
     * be changed to invalid, it will make the priority compare lose effect.
     *
     * We cannot start default scenario here direcly
     * because before idle inactive, highest scenario
     * may be started, if we started here it will
     * change the active scenario to medium
     * So we move this call after deinit scenario
     * and before start idle scenario
     * TODO: control the default scenario in NMGR internal
     */

    /*
     * Emit events.
     */
    mmi_idle_emit_before_group_exit(obj);
    mmi_idle_emit_group_exit(obj);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_main_notify_req
 * DESCRIPTION
 *  This function handle the idle main notify event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_main_notify_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_idle_event_struct *idle_event;
    mmi_idle_main_notify_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (mmi_idle_main_notify_evt_struct *)event;
    MMI_ASSERT(evt);

    /*
     * Skip if the active group or screen is changed.
     */
    if (evt->active_grp_id != mmi_frm_group_get_active_id())
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_MAIN_NOTIFY_REQ, 500));
        return MMI_RET_OK;
    }

    if (evt->active_scr_id != mmi_frm_scrn_get_active_id())
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_MAIN_NOTIFY_REQ, 501));
        return MMI_RET_OK;
    }

    /*
     * Find an event with the highest priority to notify the user.
     */
    MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_MAIN_NOTIFY_REQ, 200));

    idle_event = mmi_idle_find_event();

    if (idle_event && idle_event->notify)
    {
        MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,
                  TRC_MMI_IDLE_DUMP_FUNC_ADDR,
                  (U32)idle_event->want_to_notify,
                  (U32)idle_event->notify);

        idle_event->notify();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_main_update_req
 * DESCRIPTION
 *  This function handles the idle main update event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_main_update_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_idle_is_active())
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_MAIN_UPDATE_REQ, 500));
        return MMI_RET_OK;  /* fail-safe */
    }

    MMI_IDLE_LOG((TRC_MMI_IDLE_HANDLE_MAIN_UPDATE_REQ, 200));

    MMI_ASSERT(obj && obj->on_update_service_area);
    obj->on_update_service_area(obj);

    return MMI_RET_OK;
}


#if defined(__MMI_CLAMSHELL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_gpio_clam_open
 * DESCRIPTION
 *  This function handles the clam open event.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_gpio_clam_open(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

#if defined(__MMI_SUBLCD__)
    if (mmi_idle_sublcd_is_active())
    {
        mmi_idle_sublcd_display();
    }
#endif /* defined(__MMI_SUBLCD__) */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_gpio_clam_close
 * DESCRIPTION
 *  This function handles the clam close event.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_handle_gpio_clam_close(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

#if defined(__MMI_SUBLCD__)
    if (mmi_idle_sublcd_is_active())
    {
        mmi_idle_sublcd_display();
    }
#endif /* defined(__MMI_SUBLCD__) */

    return MMI_RET_OK;
}


static MMI_RET mmi_idle_handle_subwallpaper_changed(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

#if defined(__MMI_SUBLCD__)
    if (mmi_idle_sublcd_is_active())
    {
        mmi_idle_sublcd_display();
    }
#endif /* defined(__MMI_SUBLCD__) */

    return MMI_RET_OK;
}

#endif /* defined(__MMI_CLAMSHELL__) */

#if 0
#ifdef __OP01_FWPBW__
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
/* under construction !*/
/* under construction !*/
#endif
#endif

/* For the detail information, please refer to the IdleGprot.h */
mmi_ret mmi_idle_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        /*
         * Main event.
         */
        case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
            return mmi_idle_handle_bootup_normal_init(event);

        case EVT_ID_GROUP_ACTIVE:
            return mmi_idle_handle_group_active(event);

        case EVT_ID_GROUP_INACTIVE:
            return mmi_idle_handle_group_inactive(event);
            
        case EVT_ID_PHB_OWNER_NUMBER_CHANGED:
    #ifdef __MMI_TELEPHONY_SUPPORT__
        case EVT_ID_SRV_CALLSET_LINE_SWITCHED:
        case EVT_ID_SRV_NW_NAME_CHANGED:
    #endif
#ifdef __TCPIP__
        case EVT_ID_SRV_DTCNT_WLAN_ACTIVE:
        case EVT_ID_SRV_DTCNT_WLAN_INACTIVE:
        case EVT_ID_SRV_DTCNT_WLAN_CONNECTED:
#endif      
#ifdef __HOMEZONE_SUPPORT__
        case EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED:
#endif
            mmi_idle_update_service_area();
            break;

        case EVT_ID_IDLE_MAIN_NOTIFY_REQ:
            return mmi_idle_handle_main_notify_req(event);

        case EVT_ID_IDLE_MAIN_UPDATE_REQ:
            return mmi_idle_handle_main_update_req(event);            

    #if defined(__MMI_CLAMSHELL__)
        case EVT_ID_GPIO_CLAM_OPEN:
            return mmi_idle_handle_gpio_clam_open(event);            

        case EVT_ID_GPIO_CLAM_CLOSE:
            return mmi_idle_handle_gpio_clam_close(event);            

        case EVT_ID_PHNSET_SUBWALLPAPER_CHANGED_NOTIFY:
            return mmi_idle_handle_subwallpaper_changed(event);            

    #endif /* defined(__MMI_CLAMSHELL__) */

    #if 0
    #ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
    #endif
    #endif

        default:
            return MMI_RET_OK;           
    }

    return MMI_RET_OK;
}

/*
* lauch idle internal
*/
static void mmi_idle_launch_internal(mmi_id base_group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;
//    mmi_frm_node_struct group_info;
    mmi_id this_gid;
//    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_LAUNCH, 200));

    /*
     * Create.
     */
    this_gid = mmi_frm_group_create(
                base_group_id,
                GRP_ID_IDLE_MAIN,
                mmi_idle_main_evt_hdlr,
                NULL);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);
    mmi_frm_group_enter(this_gid, MMI_FRM_NODE_NONE_FLAG);

    obj = mmi_idle_launch_new_obj();
    
    /*
     * Emit the event.
     */
    mmi_idle_emit_launched(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_launch_new_obj
 * DESCRIPTION
 *  This function new and run a idle object.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_idle_obj_struct * mmi_idle_launch_new_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_LAUNCH, 300));
    /*
     * New the object.
     */
    obj = (mmi_idle_obj_struct *)mmi_factory_new_obj(
                                    mmi_idle_get_cfg_table(),
                                    mmi_idle_buffer_malloc);
    MMI_ASSERT(obj);

    
    /*
    * Run the idle object.
    */
    MMI_ASSERT(obj->on_create);
    obj->on_create(obj, GRP_ID_IDLE_MAIN);

    MMI_ASSERT(obj->on_run);
    obj->on_run(obj);

    g_mmi_idle_cntx.obj = obj;
    return obj;
}


/* idle app proc*/
static MMI_RET mmi_idle_app_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    #ifdef __MMI_IDLE_APP_NOT_USE_ASMv2__
        case EVT_ID_GROUP_ENTER:
    #else
        case EVT_ID_APP_ENTER:
    #endif
		{
			mmi_idle_launch_internal(APP_IDLE);
			break;
		}

        default:
            break;
	}
	return MMI_RET_OK;     
}


/* For the detail information, please refer to the IdleGprot.h */
void mmi_idle_launch(mmi_id base_group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IDLE_APP_NOT_USE_ASMv2__
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_LAUNCH, 201));  
    this_gid = mmi_frm_group_create(
                GRP_ID_ROOT,
                APP_IDLE,
                mmi_idle_app_proc,
                NULL);

    mmi_frm_group_enter(this_gid, MMI_FRM_NODE_NONE_FLAG);
#else
    MMI_IDLE_LOG((TRC_MMI_IDLE_LAUNCH, 200));  
    mmi_frm_app_launch(APP_IDLE, 0, base_group_id, mmi_idle_app_proc, 
                        0,MMI_FRM_APP_LAUNCH_AFTER_BASE | MMI_FRM_APP_USE_SEND_WAY);
#endif    
}


/* For the detail information, please refer to the IdleGprot.h */
void mmi_idle_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * If the idle main screen is active. Check if there is any notification.
     * Otherwises, display the root screen in the root group, i.e. idle main
     * screen.
     */
    if (mmi_idle_is_active())
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_DISPLAY, 300));
        mmi_idle_notify_event();
    }
    else
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_DISPLAY, 200));
        obj = mmi_idle_get_obj();
        MMI_ASSERT(obj && obj->on_before_idle_display);
        obj->on_before_idle_display(obj);
        mmi_frm_display_desktop();
    }
}


/* For the detail information, please refer to the IdleGprot.h */
void mmi_idle_show_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj && obj->on_enter);
    obj->on_enter(obj);
}


/* For the detail information, please refer to the IdleGprot.h */
MMI_BOOL mmi_idle_notify_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //only idle screen and saver screen can trip notify
    if (!mmi_idle_is_active() 
    #if defined(__MMI_SCREEN_SAVER__)
         && !mmi_scr_saver_is_active()
    #endif
	)
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_NOTIFY_EVENT, 500));
        return MMI_FALSE;
    }

    MMI_IDLE_LOG((TRC_MMI_IDLE_NOTIFY_EVENT, 200));

    MMI_ASSERT(obj);

    mmi_idle_emit_notify_req(obj);

    return MMI_TRUE;
}


/* For the detail information, please refer to the IdleGprot.h */
MMI_BOOL mmi_idle_update_service_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SUBLCD__)
    if (mmi_idle_sublcd_is_active())
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_UPDATE_SERVICE_AREA, 100));
        mmi_idle_sublcd_display();
    }
#endif

    if (!mmi_idle_is_active())
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_UPDATE_SERVICE_AREA, 500));
        return MMI_FALSE;
    }

    MMI_IDLE_LOG((TRC_MMI_IDLE_UPDATE_SERVICE_AREA, 200));

    MMI_ASSERT(obj);

    mmi_idle_emit_update_req(obj);

    return MMI_TRUE;
}


/* For the detail information, please refer to the IdleGprot.h */
mmi_id mmi_idle_get_group_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_GET_GROUP_ID, 200, GRP_ID_IDLE_MAIN));

    return GRP_ID_IDLE_MAIN;
}


/* For the detail information, please refer to the IdleGprot.h */
MMI_BOOL mmi_idle_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_group_active() &&
        mmi_frm_scrn_get_active_id() == SCR_ID_IDLE_MAIN)
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_IS_ACTIVE, 200, MMI_TRUE));
        return MMI_TRUE;
    }

    MMI_IDLE_LOG((TRC_MMI_IDLE_IS_ACTIVE, 200, MMI_FALSE));

    return MMI_FALSE;
}


/* For the detail information, please refer to the IdleGprot.h */
MMI_BOOL mmi_idle_is_group_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_group_is_in_active_serial(GRP_ID_IDLE_MAIN);

    //MMI_IDLE_LOG((TRC_MMI_IDLE_IS_GROUP_ACTIVE, 200, ret));
    //return ret;
}

