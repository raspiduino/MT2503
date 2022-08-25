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
 *  ScrSaverObject.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the screen saver object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SCREEN_SAVER__)
#include "IdleGprot.h"
#include "ScrLockerGprot.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_input_gprot.h"
#include "ScrSaverGprot.h"
#include "ScrSaverObject.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "wgui_touch_screen.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_rp_app_scr_saver_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "ScrSaverMain.h"
#include "ScrSaverFactory.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "FactoryGprot.h" 


/****************************************************************************
 * Function
 ****************************************************************************/

#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_do_close_by_pen
 * DESCRIPTION
 *  This function closes the screen saver.
 * PARAMETERS
 *  pos             : [IN]          Position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssv_obj_do_close_by_pen(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_scr_saver_close();
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_set_handler
 * DESCRIPTION
 *  This function sets the handler.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_set_handler(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_group_key_handler(
        mmi_scr_saver_close,
        (PU16)PresentAllKeys,
        (U8)TOTAL_KEYS,
        KEY_EVENT_DOWN);

#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_up_handler(mmi_ssv_obj_do_close_by_pen);
    wgui_register_pen_down_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_move_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_abort_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_repeat_handler(mmi_pen_dummy_hdlr);
    wgui_register_pen_long_tap_handler(mmi_pen_dummy_hdlr);
#endif /* defined(__MMI_TOUCH_SCREEN__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_emit_close_req
 * DESCRIPTION
 *  This function emits the close request.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_emit_close_req(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_close_req_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_SSV_OBJ_CLOSE_REQ, obj->this_gid);
    MMI_FRM_POST_EVENT(&evt, obj->parent_proc, obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_emit_closed_ind
 * DESCRIPTION
 *  This function emits the closed indication.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_emit_closed_ind(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_closed_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_SSV_OBJ_CLOSED_IND, obj->this_gid);
    MMI_FRM_SEND_EVENT(&evt, obj->parent_proc, obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_handle_group_deinit
 * DESCRIPTION
 *  This function handles the group deinit event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_ssv_obj_handle_group_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ssv_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    obj = (mmi_ssv_obj_struct *)event->user_data;

    if (obj->suspend_scr_locker)
    {
        mmi_scr_locker_resume();
    }

    mmi_ssv_emit_exit(obj);

    mmi_ssv_obj_emit_closed_ind(obj);

    mmi_factory_delete_obj((mmi_factory_obj_struct *)obj, mmi_ssv_get_cfg_table(), mmi_ssv_buffer_free);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ssv_obj_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            ret = mmi_ssv_obj_handle_group_deinit(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_create
 * DESCRIPTION
 *  This function creates the group.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  parent_proc         : [IN]          Parent proc function
 * RETURNS
 *  Group id.
 *****************************************************************************/
mmi_id mmi_ssv_obj_on_create(
    mmi_ssv_obj_struct *obj,
    mmi_proc_func parent_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    this_gid = mmi_frm_group_create(
                mmi_idle_get_group_id(),
                GRP_ID_SSV_MAIN,
                mmi_ssv_obj_evt_hdlr,
                obj);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);

    obj->parent_proc = parent_proc;
    obj->this_gid = this_gid;

    /*
     * Suspend the classic locker such that the user can touch the screen to
     * close the screen saver.
     *
     * Here, handle the case that locker is already locked.
     */
    if (mmi_scr_locker_is_locked() &&
        mmi_scr_locker_get_type() == MMI_SCR_LOCKER_TYPE_CLASSIC)
    {
        mmi_scr_locker_suspend();
        obj->suspend_scr_locker = MMI_TRUE;
    }

    mmi_ssv_emit_enter(obj);

    return this_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_close
 * DESCRIPTION
 *  This function closes the group.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_close(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    mmi_frm_group_close(obj->this_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_run
 * DESCRIPTION
 *  This function runs the screen saver.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_run(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_scr_locker_locked
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_scr_locker_locked(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Suspend the classic locker such that the user can touch the screen to
     * close the screen saver.
     *
     * Here, handle the case that locker is locked when the screen saver is
     * already running.
     */
    if (mmi_scr_locker_is_locked() &&
        mmi_scr_locker_get_type() == MMI_SCR_LOCKER_TYPE_CLASSIC)
    {
        mmi_scr_locker_suspend();
        obj->suspend_scr_locker = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_backlight_changed
 * DESCRIPTION
 *  This function handles the backlight changed event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_light        : [IN]          Is backlight on or off
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_backlight_changed(
    mmi_ssv_obj_struct *obj,
    MMI_BOOL is_light)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_time_changed
 * DESCRIPTION
 *  This function handles the time changed event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_time_changed(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_want_to_run
 * DESCRIPTION
 *  This function checks if the screen saver wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_ssv_obj_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_SLIDE__)
    if (srv_clam_is_close())
    {
        return MMI_FALSE;
    }
#endif /* !defined(__MMI_SLIDE__) */

#if !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__)
    if (srv_backlight_is_lcd_sleep())
    {
        return MMI_FALSE;
    }
#endif /* !defined(__MMI_GPIO_DISABLE_SLEEP_MODE__) */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_init(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    /* Member variable. */
    obj->type = MMI_SCR_SAVER_TYPE_INVALID;
    obj->parent_proc = NULL;
    obj->this_gid = GRP_ID_INVALID;

    /* Member function. */
    obj->on_create = mmi_ssv_obj_on_create;
    obj->on_close = mmi_ssv_obj_on_close;
    obj->on_run = mmi_ssv_obj_on_run;
    obj->on_scr_locker_locked = mmi_ssv_obj_on_scr_locker_locked;
    obj->on_backlight_changed = mmi_ssv_obj_on_backlight_changed;
    obj->on_time_changed = mmi_ssv_obj_on_time_changed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssv_obj_on_deinit
 * DESCRIPTION
 *  This function deinitializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssv_obj_on_deinit(mmi_ssv_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
}
#endif /* defined(__MMI_SCREEN_SAVER__) */
