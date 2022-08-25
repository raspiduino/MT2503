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
 *  ScrlockerScreenLockKey.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
 
#if defined(__MMI_VUI_SCREEN_LOCK_KEY__)
 
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "gui_typedef.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "ScrLockerObject.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "ScrLockerGprot.h"
#include "ScrlockerScreenLockKey.h"
#include "ScrLockerGprot.h"
#include "DialerGprot.h"
#include "ScrLockerMain.h"

/****************************************************************************
 * Defines
 ****************************************************************************/

/* Option flag. */
#define MMI_SLK_FLAG_ANIMATION_LOCK                 (1 << 0)
#define MMI_SLK_FLAG_EMERGENCY_CALL                 (1 << 1)

/* Set / Clear / Has flag. */
#define VAPP_SLK_SET_FLAG(_obj, _f) (_obj->flag |= _f)
#define VAPP_SLK_CLR_FLAG(_obj, _f) (_obj->flag &= ~_f)
#define VAPP_SLK_HAS_FLAG(_obj, _f) (((_obj->flag & _f) == _f))

/****************************************************************************
 * Function
 ****************************************************************************/

#ifdef __MMI_REDUCED_KEYPAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_sos_dialer
 * DESCRIPTION
 *  This function launches the SOS dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_leave_proc
 * DESCRIPTION
 *  This function is the leave proc.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_scrlock_key_leave_proc(mmi_event_struct *event)
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
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:     /* fall-throught */
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            ret = 1; /* Do not close me. */
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_handle_group_deinit
 * DESCRIPTION
 *  This function handles the group deinit event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_scrlock_key_handle_group_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_slk_obj_handle_group_deinit(event);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_slk_scrlock_key_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
         case EVT_ID_GROUP_ACTIVE:
            mmi_scr_locker_resume();
            mmi_scr_locker_stop_timer();
            break;

        case EVT_ID_GROUP_INACTIVE:
            /* UCM need to receive screen lock pre lock event to launch its own lock */
            mmi_scr_locker_suspend();
            mmi_scr_locker_start_timer();
            break;

        case EVT_ID_GROUP_DEINIT:
            ret = mmi_slk_scrlock_key_handle_group_deinit(event);
            break;

		case EVT_ID_GROUP_GOBACK_IN_END_KEY:     /* fall-throught */
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            ret = 1; /* Do not close me. */
            break;
            
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_on_create
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id mmi_slk_scrlock_key_on_create(mmi_slk_obj_struct *obj, mmi_proc_func parent_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    /* we want to launch this lock in any screen, so we use root as parent ID */
    this_gid = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_SLK_MAIN,
                mmi_slk_scrlock_key_evt_hdlr,
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
 *  mmi_slk_scrlock_key_enter
 * DESCRIPTION
 *  This function enter the key launcher screen lock.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_scrlock_key_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            (FuncPtr)mmi_slk_scrlock_key_enter,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        param->group_id,
        param->scrn_id,
        mmi_slk_scrlock_key_leave_proc);

    if (vapp_screen_lock_key_init() < 0)
    {
        mmi_slk_obj_struct *obj = (mmi_slk_obj_struct*)param->user_data;
        //obj->scenario = -1;
        obj->on_create = NULL;
        return;
    }
    
    ExitCategoryFunction = vapp_screen_lock_key_deinit;

#ifdef __MMI_REDUCED_KEYPAD__ 
    //SetKeyHandler(mmi_slk_scrlock_key_sos_dialer, KEY_SEND, KEY_EVENT_DOWN);
#endif

    /* Do not allow to shutdown the handset. */
    if (mmi_frm_kbd_is_key_supported(KEY_POWER))
    {
        ClearKeyHandler(KEY_POWER, KEY_LONG_PRESS);
    }
    else
    {
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_on_run
 * DESCRIPTION
 *  This function runs the screen locker.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_scrlock_key_on_run(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_run(obj);

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_SLK_MAIN,
        (FuncPtr)mmi_slk_scrlock_key_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_on_emcall
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_scrlock_key_on_emcall(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(obj != NULL);

    p = (mmi_slk_scrlock_key_struct *)obj;    
    
    VAPP_SLK_SET_FLAG(p, MMI_SLK_FLAG_EMERGENCY_CALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_scrlock_key_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_scrlock_key_on_init(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_init(obj);

    p = (mmi_slk_scrlock_key_struct *)obj;

    p->type = MMI_SCR_LOCKER_TYPE_SCRLOCK_KEY;
    
    p->on_create = mmi_slk_scrlock_key_on_create;
    p->on_run    = mmi_slk_scrlock_key_on_run;
    p->on_emcall = mmi_slk_scrlock_key_on_emcall;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_store_state
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_screen_lock_key_store_state(U32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);
    
    obj->state = state;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_get_stored_state
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
U32 vapp_screen_lock_key_get_stored_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);
    
    return obj->state;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_lock_state_machine
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_screen_lock_key_lock_state_machine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);
    
    VAPP_SLK_SET_FLAG(obj, MMI_SLK_FLAG_ANIMATION_LOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_unlock_state_machine
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_screen_lock_key_unlock_state_machine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);
    
    VAPP_SLK_CLR_FLAG(obj, MMI_SLK_FLAG_ANIMATION_LOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_check_state_machine
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vapp_screen_lock_key_check_state_machine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);

    if (VAPP_SLK_HAS_FLAG(obj, MMI_SLK_FLAG_ANIMATION_LOCK))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_check_emcall
 * DESCRIPTION
 *  if launch dialer when screen lock is backlight off, will cause flash screen
 *  so dialer do this after launched insteed of screen lock.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vapp_screen_lock_key_check_emcall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);

    if (VAPP_SLK_HAS_FLAG(obj, MMI_SLK_FLAG_EMERGENCY_CALL))
    {
        VAPP_SLK_CLR_FLAG(obj, MMI_SLK_FLAG_EMERGENCY_CALL);
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  vapp_screen_lock_key_is_first_enter
 * DESCRIPTION
 *  if launch dialer when screen lock is backlight off, will cause flash screen
 *  so dialer do this after launched insteed of screen lock.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vapp_screen_lock_key_is_first_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_scrlock_key_struct *obj;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (mmi_slk_scrlock_key_struct*)mmi_frm_group_get_user_data(GRP_ID_SLK_MAIN);

    MMI_ASSERT(obj != NULL);
    
    return (mmi_frm_scrn_get_gui_buf(obj->this_gid, (MMI_ID)SCR_ID_SLK_MAIN) == NULL);
}


#endif

