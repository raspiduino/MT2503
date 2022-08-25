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
 *  IdleObject.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the idle object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"

#include "MMIDataType.h"
#include "IdleObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "IdleFactory.h"
#include "mmi_frm_scenario_gprot.h"
#include "IdleMain.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "IdleCommon.h"
#include "IdleGprot.h"
#include "mmi_rp_app_idle_def.h"
#include "FactoryGprot.h"


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_evt_hdlr
 * DESCRIPTION
 *  This function is the event handler of the idle object.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_obj_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    obj = (mmi_idle_obj_struct *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_factory_delete_obj(
                (mmi_factory_obj_struct *)obj,
                mmi_idle_get_cfg_table(),
                mmi_idle_buffer_free);
            mmi_idle_launch_new_obj();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_leave_proc
 * DESCRIPTION
 *  This function is the leave proc.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_obj_leave_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    obj = (mmi_idle_obj_struct *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:                /* fall-throught */
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            /*
             * This is a fail-safe. This is to avoid APP from deleting the idle
             * group by accident.
             */
            if (!obj->is_self_deleted)
            {
                return -1; /* Cannot delete me. */
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_exit
 * DESCRIPTION
 *  This function is the exit function.
 * PARAMETERS
 *  param           : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_obj_exit(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_LOG((TRC_MMI_IDLE_OBJ_EXIT, 200));

    MMI_ASSERT(param && param->user_data);

    obj = (mmi_idle_obj_struct *)param->user_data;

    MMI_ASSERT(obj && obj->on_exit);
    obj->on_exit(obj);

    if (!mmi_is_redrawing_bk_screens())
    {
        mmi_idle_emit_exit(obj);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_enter
 * DESCRIPTION
 *  This function is the enter function.
 * PARAMETERS
 *  param           : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_obj_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    obj = (mmi_idle_obj_struct *)param->user_data;

    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            (FuncPtr)mmi_idle_obj_exit,
            (FuncPtr)mmi_idle_obj_enter,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        MMI_IDLE_LOG((TRC_MMI_IDLE_OBJ_ENTER, 500));
        return;
    }

    MMI_IDLE_LOG((TRC_MMI_IDLE_OBJ_ENTER, 200));

    /* Fail-safe to avoid APP from deleting the idle screen incorrectly. */
    mmi_frm_scrn_set_leave_proc(
        param->group_id,
        param->scrn_id,
        mmi_idle_obj_leave_proc);

    /* Enter idle screen and update the service area. */
    MMI_ASSERT(obj && obj->on_enter && obj->on_update_service_area);
    obj->on_enter(obj);
    obj->on_update_service_area(obj);

   // mmi_idle_wrap_soft_key_hdlr();

    /* Emit the event if this isn't used to draw the background. */
    if (!mmi_is_redrawing_bk_screens())
    {
        mmi_idle_emit_enter(obj);
        mmi_idle_notify_event();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_on_create
 * DESCRIPTION
 *  This function creates the idle group.
 * PARAMETERS
 *  obj                 : [IN]          Idle object
 *  parent_gid          : [IN]          Parent group id
 * RETURNS
 *  Idle group id.
 *****************************************************************************/
mmi_id mmi_idle_obj_on_create(mmi_idle_obj_struct *obj, mmi_id parent_gid)
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
                parent_gid,
                GRP_ID_AUTO_GEN,
                mmi_idle_obj_evt_hdlr,
                obj);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);

    obj->parent_gid = parent_gid;
    obj->this_gid = this_gid;

    return this_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_on_close
 * DESCRIPTION
 *  This function closes the idle group.
 * PARAMETERS
 *  obj           : [IN]        Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_close(mmi_idle_obj_struct *obj)
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
 *  mmi_idle_obj_on_run
 * DESCRIPTION
 *  This function runs the idle.
 * PARAMETERS
 *  obj           : [IN]        Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_run(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_IDLE_MAIN,
        (FuncPtr)mmi_idle_obj_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_on_enter
 * DESCRIPTION
 *  This function is the enter function.
 * PARAMETERS
 *  obj             : [IN]          Idle object.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_enter(mmi_idle_obj_struct *obj)
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
 *  mmi_idle_obj_on_exit
 * DESCRIPTION
 *  This function is the exit function
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_exit(mmi_idle_obj_struct *obj)
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
 *  mmi_idle_obj_on_update_service_area
 * DESCRIPTION
 *  This function updates the service string.
 * PARAMETERS
 *  obj           : [IN]        Idle object.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_update_service_area(mmi_idle_obj_struct *obj)
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
 *  mmi_idle_obj_on_before_display
 * DESCRIPTION
 *  This function used to configure before idle display by end key
 * PARAMETERS
 *  obj           : [IN]        Idle object.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_before_idle_display(mmi_idle_obj_struct *obj)
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
 *  mmi_idle_obj_on_want_to_run
 * DESCRIPTION
 *  This function checks the idle wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_idle_obj_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_on_init
 * DESCRIPTION
 *  This function initializes the idle object.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_init(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    obj->capability = ENABLE_FULL;

    /* Member function. */
    obj->on_create = mmi_idle_obj_on_create;
    obj->on_close = mmi_idle_obj_on_close;
    obj->on_run = mmi_idle_obj_on_run;
    obj->on_enter = mmi_idle_obj_on_enter;
    obj->on_exit = mmi_idle_obj_on_exit;
    obj->on_update_service_area = mmi_idle_obj_on_update_service_area;
    obj->on_before_idle_display = mmi_idle_obj_on_before_idle_display;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_obj_on_deinit
 * DESCRIPTION
 *  This function deinitializes the idle object.
 * PARAMETERS
 *  obj             : [IN]          Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_obj_on_deinit(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
}

