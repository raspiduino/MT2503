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
 *  ScrLockerObject.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the screen locker object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * include
 ****************************************************************************/

#include "IdleGprot.h"
#include "gpiosrvgprot.h"

#include "ScrLockerObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "MMIDataType.h"
#include "ScrLockerMain.h"
#include "ScrLockerFactory.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "ScrLockerSos.h"
#include "ScrLockerGprot.h"
#include "ScrlockerScreenLockKey.h"
#include "FactoryGprot.h"

#include "MMI_ap_dcm_config.h"
#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata = "DYNAMIC_CODE_SCRLOCK_RODATA" , code = "DYNAMIC_CODE_SCRLOCK_ROCODE"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_emit_close_req
 * DESCRIPTION
 *  This function emits the close req event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_emit_close_req(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_close_req_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_SLK_OBJ_CLOSE_REQ, obj->this_gid);

    MMI_FRM_POST_EVENT(&evt, obj->parent_proc, obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_emit_closed_ind
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_emit_closed_ind(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_closed_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_SLK_OBJ_CLOSED_IND, obj->this_gid);

    MMI_FRM_SEND_EVENT(&evt, obj->parent_proc, obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_handle_group_deinit
 * DESCRIPTION
 *  This function handles the group deinit event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_obj_handle_group_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    MMI_SLK_LOG((TRC_MMI_SLK_OBJ_HANDLE_GROUP_DEINIT, 200));
	
    obj = (mmi_slk_obj_struct *)event->user_data;

    //mmi_slk_emit_unlocked(obj);

    mmi_slk_obj_emit_closed_ind(obj);

    mmi_factory_delete_obj(
        (mmi_factory_obj_struct *)obj,
        mmi_slk_get_cfg_table(),
        mmi_slk_buffer_free);


    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_slk_obj_evt_hdlr(mmi_event_struct *event)
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
            ret = mmi_slk_obj_handle_group_deinit(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_create
 * DESCRIPTION
 *  This function creates the screen locker application.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  parent_proc         : [IN]          Parent proc function
 * RETURNS
 *  Group id.
 *****************************************************************************/
mmi_id mmi_slk_obj_on_create(mmi_slk_obj_struct *obj, mmi_proc_func parent_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj && obj->on_resume);

    this_gid = mmi_frm_group_create(
                mmi_idle_get_group_id(),
                GRP_ID_SLK_MAIN,
                mmi_slk_obj_evt_hdlr,
                obj);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);

    obj->parent_proc = parent_proc;
    obj->this_gid = this_gid;

    obj->on_resume(obj, MMI_TRUE);

    mmi_slk_emit_locked(obj);

    return this_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_close
 * DESCRIPTION
 *  This function closes the screen locker application.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_close(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj && obj->on_suspend);

    MMI_SLK_LOG((TRC_MMI_SLK_OBJ_ON_CLOSE, 200));

    obj->on_suspend(obj, MMI_TRUE);

    mmi_frm_group_close(obj->this_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_run
 * DESCRIPTION
 *  This function runs the screen locker application.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_run(mmi_slk_obj_struct *obj)
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
 *  mmi_slk_obj_on_suspend
 * DESCRIPTION
 *  This function handles the suspend event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_closed       : [IN]          Suspend because the lock is closed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_suspend(mmi_slk_obj_struct *obj, MMI_BOOL is_closed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    wgui_status_icon_bar_hide_icon(STATUS_ICON_KEYPAD_LOCK);
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#if !defined(__MMI_VUI_SCREEN_LOCK_KEY__)  && !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)  //&& !defined(__MMI_SCREEN_LOCK_ANY_TIME__) 
    {
        srv_gpio_property_info_struct para;
        para.keypad_locked = MMI_FALSE;
        srv_gpio_set_property_info(SRV_GPIO_PROPERTY_KEYPAD_LOCKED_FLAG, &para);
    }    
#endif

    if (obj->scenario != MMI_SCENARIO_ID_INVALID)
    {
        mmi_frm_end_scenario(obj->scenario);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_resume
 * DESCRIPTION
 *  This function handles the resume event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_created      : [IN]          Resume because the lock is created
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_resume(mmi_slk_obj_struct *obj, MMI_BOOL is_created)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    wgui_status_icon_bar_show_icon(STATUS_ICON_KEYPAD_LOCK);
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

#if !defined(__MMI_VUI_SCREEN_LOCK_KEY__) && !defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)//&& !defined(__MMI_SCREEN_LOCK_ANY_TIME__) 
    {
        srv_gpio_property_info_struct para;
        para.keypad_locked = MMI_TRUE;
        srv_gpio_set_property_info(SRV_GPIO_PROPERTY_KEYPAD_LOCKED_FLAG, &para);
    }
#endif

    if (obj->scenario != MMI_SCENARIO_ID_INVALID)
    {
        mmi_frm_start_scenario(obj->scenario);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_msg_num_changed
 * DESCRIPTION
 *  This function handles the message number changed event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_msg_num_changed(mmi_slk_obj_struct *obj)
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
 *  mmi_slk_obj_on_key
 * DESCRIPTION
 *  This function handles the key event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  key_evt         : [IN]          Key event.
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_obj_on_key(
    mmi_slk_obj_struct *obj,
    mmi_frm_key_evt_struct *key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj && key_evt);

    ret = mmi_slk_sos_on_key(obj, key_evt);
    if (ret != MMI_RET_OK)
    {

    /*
     * when emergency call, screen lock do not turn on backlight.
     * dialer do this to avoid flash screen of screen lock
     */
    #ifdef __MMI_VUI_SCREEN_LOCK_KEY__ 
        if (mmi_scr_locker_get_type() == MMI_SCR_LOCKER_TYPE_SCRLOCK_KEY)
        {
            mmi_slk_scrlock_key_struct *p = (mmi_slk_scrlock_key_struct*)obj;
            p->on_emcall(obj);
        }        
    #endif
    
        mmi_slk_sos_launch(obj);
        return MMI_RET_STOP_KEY_HANDLE;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_want_to_run
 * DESCRIPTION
 *  This function checks if the screen locker wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  ON yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_slk_obj_on_want_to_run(void)
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
 *  mmi_slk_obj_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_init(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    /* Member variable. */
    obj->type = MMI_SCR_LOCKER_TYPE_INVALID;
    obj->scenario = MMI_SCENARIO_ID_HIGH_SCRN;

    /* Member function. */
    obj->on_create = mmi_slk_obj_on_create;
    obj->on_close = mmi_slk_obj_on_close;
    obj->on_run = mmi_slk_obj_on_run;
    obj->on_key = mmi_slk_obj_on_key;
    obj->on_suspend = mmi_slk_obj_on_suspend;
    obj->on_resume = mmi_slk_obj_on_resume;
    obj->on_msg_num_changed = mmi_slk_obj_on_msg_num_changed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_obj_on_deinit
 * DESCRIPTION
 *  This function deinitializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_obj_on_deinit(void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((mmi_slk_obj_struct *)obj);
}

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata , code
#endif

