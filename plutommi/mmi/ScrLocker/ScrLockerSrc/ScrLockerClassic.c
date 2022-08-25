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
 *  ScrLockerClassic.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the classic screen locker.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SCREEN_LOCK_CLASSIC__

#include "IdleGprot.h"
#include "ScrSaverGprot.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "ScrLockerPopup.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "ScrLockerClassic.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "l4c_nw_cmd.h"
#include "mmi_rp_app_uiframework_def.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "ScrLockerMain.h"
#include "mmi_frm_input_gprot.h"
#include "ScrLockerGprot.h"
#include "ScrLockerObject.h"
#include "gui_typedef.h"
#include "ScrLockerFactory.h"
#include "FactoryGprot.h"
#include "CommonScreens.h"
#include "CommonScreensResDef.h"
#include "ProfilesSrvGprot.h"
#include "gpiosrvgprot.h"

#include "MMI_ap_dcm_config.h"

#if defined(__MMI_BT_DIALER_SUPPORT__)
#include "BTMMIScr.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "IdleObject.h"
#endif

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata = "DYNAMIC_CODE_SCRLOCK_RODATA" , code = "DYNAMIC_CODE_SCRLOCK_ROCODE"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_get_unlock_trigger_key
 * DESCRIPTION
 *  This function gets the key code to trigger the unlock process.
 * PARAMETERS
 *  void
 * RETURNS
 *  Key code.
 *****************************************************************************/
static U16 mmi_slk_classic_get_unlock_trigger_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BTD_BOX_UI_STYLE__
#ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
    if (mmi_frm_kbd_is_key_supported(KEY_RSK))
    {
        return KEY_RSK;
    }

#else

    if (mmi_frm_kbd_is_key_supported(KEY_LSK))
    {
        return KEY_LSK;
    }
#endif
    else
    {
        return KEY_SEND;
    }
#else/*__MMI_BTD_BOX_UI_STYLE__*/
       return  KEY_RSK;
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_get_unlock_final_key
 * DESCRIPTION
 *  This function gets the key code to unlock the handset.
 * PARAMETERS
 *  void
 * RETURNS
 *  key code.
 *****************************************************************************/
static U16 mmi_slk_classic_get_unlock_final_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
    return KEY_POUND;

#else
    return KEY_END;
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_get_soft_key
 * DESCRIPTION
 *  This function gets the soft key string used when the handset is locked.
 *  Basically, screen locker will automatically handle the softkey string and
 *  image. But, for some APP that dose not use framework softkey component, e.g.
 *  media or Java APP, they can use this API to get the softkey string if they
 *  wants to support the locked state.
 * PARAMETERS
 *  lsk_str_id           : [IN]      Left softkey string ID
 *  rsk_str_id           : [IN]      Right softkey string ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_get_softkey_id(U16 *lsk_str_id, U16 *rsk_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lsk_str_id)
    {
        *lsk_str_id = 0; /* reset */
    }

    if (rsk_str_id)
    {
        *rsk_str_id = 0; /* reset */
    }
    
  #ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
  if (rsk_str_id)
  {
      *rsk_str_id = STR_ID_SLK_UNLOCK;
  }

  #else
    if (lsk_str_id)
    {
        *lsk_str_id = STR_ID_SLK_UNLOCK;
    }

  #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_popup_callback
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  event           : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_slk_classic_popup_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)event;
    mmi_slk_classic_struct *obj = (mmi_slk_classic_struct *)evt->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_ALERT_ENTER:
            obj->is_unlocking = MMI_TRUE;
            break;
        
        case EVT_ID_ALERT_QUIT:
        {
            switch(evt->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                    obj->popup_id = 0;
                    obj->is_unlocking = MMI_FALSE;
                    break;
                default:
                    break;
            }
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_unlock_popup_bt
 * DESCRIPTION
 *  This function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BTD_BOX_UI_STYLE__
void mmi_slk_classic_unlock_popup_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(obj);
    mmi_popup_property_init(&arg);
    arg.parent_id = mmi_idle_get_group_id();
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_popup_display(get_string(STR_ID_SLK_UNLOCK_2), MMI_EVENT_INFO, &arg);
    #else /*__MMI_TOUCH_SCREEN__*/
        mmi_popup_display(get_string(STR_ID_SLK_UNLOCK_3), MMI_EVENT_INFO, &arg);
    #endif /*__MMI_TOUCH_SCREEN__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_popup_unlocked_done_bt
 * DESCRIPTION
 *  This function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_classic_popup_unlocked_done_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(obj);

    mmi_popup_property_init(&arg);
    arg.parent_id = mmi_idle_get_group_id();

    mmi_popup_display(get_string(STR_ID_SLK_KBD_UNLOCKED_MSG), MMI_EVENT_INFO, &arg);
}
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

#ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_handle_popup_close_req
 * DESCRIPTION
 *  This function handles the close req of the popup.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_classic_handle_popup_close_req(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_close_req_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    evt = (mmi_slk_popup_close_req_evt_struct *)event;

    mmi_slk_popup_close(evt->sender_id);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_group_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_classic_group_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch(event->evt_id)
    {
        case EVT_ID_SLK_POPUP_CLOSE_REQ:
            ret = mmi_slk_classic_handle_popup_close_req(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_create_popup
 * DESCRIPTION
 *  This function creates a popup group.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  proc            : [IN]          Parent proc function
 * RETURNS
 *  Group id.
 *****************************************************************************/
static mmi_id mmi_slk_classic_create_popup(
    mmi_slk_classic_struct *obj,
    mmi_proc_func proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create(
                mmi_idle_get_group_id(),
                GRP_ID_AUTO_GEN,
                proc,
                obj);

    MMI_ASSERT(grp_id != GRP_ID_INVALID);

    mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return mmi_slk_popup_create(grp_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_enter_unlock_me_by_key
 * DESCRIPTION
 *  This function is the enter function of the "Unlock me" screen. (Keypad only)
 * PARAMETERS
 *  user_data           : [IN]          User data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_enter_unlock_me_by_key(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_classic_struct *obj = (mmi_slk_classic_struct *)user_data;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

#ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
    str_id = STR_ID_SLK_KBD_UNLOCK_ME_MSG_BWUI;

#else
    str_id = STR_ID_SLK_KBD_UNLOCK_ME_MSG;
#endif

    ShowCategory64Screen(str_id, IMG_ID_SLK_LOCKED, NULL);

    SetKeyDownHandler(
        mmi_scr_locker_close,
        mmi_slk_classic_get_unlock_final_key());

    obj->is_unlocking = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_exit_unlock_me_by_key
 * DESCRIPTION
 *  This function is the exit function of the "unlock me" popup.
 * PARAMETERS
 *  user_data           : [IN]          User data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_exit_unlock_me_by_key(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_classic_struct *obj = (mmi_slk_classic_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    obj->is_unlocking = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_popup_unlocked
 * DESCRIPTION
 *  This function displays the "Unlocked" popup.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_popup_unlocked(mmi_slk_classic_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = mmi_slk_classic_create_popup(obj, mmi_slk_classic_group_evt_hdlr);

    mmi_slk_popup_set_string(cui_id, STR_ID_SLK_KBD_UNLOCKED_MSG);

    mmi_slk_popup_set_image(cui_id, IMG_ID_SLK_UNLOCKED);

    mmi_slk_popup_run(cui_id);
}

#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_popup_unlock_me
 * DESCRIPTION
 *  This function displays the "Unlock me" popup.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_popup_unlock_me(mmi_slk_classic_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    U16 str_id;
    #ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
        mmi_id cui_id;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

   #ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
   mmi_scr_locker_close();
   return;
   #endif /*__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__*/
    #ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
        cui_id = mmi_slk_classic_create_popup(obj, mmi_slk_classic_group_evt_hdlr);

        mmi_slk_popup_set_display(
             cui_id,
             mmi_slk_classic_enter_unlock_me_by_key,
             mmi_slk_classic_exit_unlock_me_by_key,
             obj);

         mmi_slk_popup_run(cui_id);

    #else
    mmi_popup_property_init(&arg);
    arg.parent_id = mmi_idle_get_group_id();
    arg.callback = mmi_slk_classic_popup_callback;
    arg.user_tag = obj;
    str_id = STR_ID_SLK_KBD_UNLOCK_ME_MSG;
    obj->popup_id = mmi_popup_display(get_string(str_id), MMI_EVENT_INFO, &arg);

    SetKeyDownHandler(
        mmi_scr_locker_close,
        mmi_slk_classic_get_unlock_final_key());

    srv_prof_play_tone(SRV_PROF_TONE_SUCCESS, NULL);
    #endif
}


#ifndef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_popup_help_msg
 * DESCRIPTION
 *  This function displays the help message.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_popup_help_msg(mmi_slk_classic_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    mmi_popup_property_init(&arg);
    arg.parent_id = mmi_idle_get_group_id();
    if (mmi_frm_kbd_is_key_supported(KEY_LSK))
    {
        mmi_popup_display(get_string(STR_ID_SLK_KBD_HELP_MSG), MMI_EVENT_INFO, &arg);
    }
    else
    {
        mmi_popup_display(get_string(STR_ID_SLK_KBD_HELP_MSG2), MMI_EVENT_INFO, &arg);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_suspend
 * DESCRIPTION
 *  This function handles the suspend event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_closed       : [IN]          Suspend because the lock is closed
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_on_suspend(
    mmi_slk_obj_struct *obj,
    MMI_BOOL is_closed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_suspend(obj, is_closed);

#ifndef __MMI_BTD_BOX_UI_STYLE__
#ifdef __MMI_TOUCH_SCREEN__
    mmi_slk_pen_unblock();
#endif
    wgui_softkey_unlock_softkey(MMI_LEFT_SOFTKEY);
    wgui_softkey_unlock_softkey(MMI_RIGHT_SOFTKEY);
    wgui_softkey_unlock_softkey(MMI_CENTER_SOFTKEY);

#ifdef __MMI_CLAMSHELL__ //for MAUI_03343481
    change_left_softkey(STR_ID_IDLE_MAIN_MENU,0);
    change_left_softkey(STR_ID_IDLE_CONTACT, 0);
    wgui_softkey_update();
#endif
#endif /*__MMI_BTD_BOX_UI_STYLE__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_resume
 * DESCRIPTION
 *  This function handles the resume event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_created      : [IN]          Resume because the lock is created
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_on_resume(
    mmi_slk_obj_struct *obj,
    MMI_BOOL is_created)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lsk_str_id, rsk_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_resume(obj, is_created);

#ifndef __MMI_BTD_BOX_UI_STYLE__
#ifdef __MMI_TOUCH_SCREEN__
    mmi_slk_pen_block();
#endif
    mmi_slk_classic_get_softkey_id(&lsk_str_id, &rsk_str_id);

    wgui_softkey_lock_softkey(lsk_str_id, 0, MMI_LEFT_SOFTKEY);
    wgui_softkey_lock_softkey(rsk_str_id, 0, MMI_RIGHT_SOFTKEY);
    wgui_softkey_lock_softkey(0, 0, MMI_CENTER_SOFTKEY);
 #endif /*__MMI_BTD_BOX_UI_STYLE__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_create
 * DESCRIPTION
 *  This function creates the screen locker.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  parent_proc         : [IN]          Parent proc function
 * RETURNS
 *  Group id.
 *****************************************************************************/
static mmi_id mmi_slk_classic_on_create(
    mmi_slk_obj_struct *obj,
    mmi_proc_func parent_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_classic_struct *p = (mmi_slk_classic_struct *)obj;

#if defined(__MMI_BT_DIALER_SUPPORT__)
    mmi_id parent_id;
    mmi_idle_obj_struct * idle_object;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(p);

    /*
     * Shall not callback to parent.
     */
    p->parent_proc = parent_proc;
    p->this_gid = GRP_ID_INVALID;

    mmi_slk_classic_on_resume(obj, MMI_TRUE);

#if defined(__MMI_BT_DIALER_SUPPORT__)
    //There must be a button bar at the bottom of idle screen.
    //so need to update first time.
#ifndef __MMI_BTD_BOX_UI_STYLE__
    wgui_softkey_update();
#endif /*__MMI_BTD_BOX_UI_STYLE__*/

    idle_object = (mmi_idle_obj_struct *)mmi_idle_get_obj();
    parent_id = idle_object->this_gid;
    /* check the SCR_BT_CONNECTING screen is exist or not */
    if (mmi_frm_scrn_is_present(parent_id,SCR_BT_CONNECTING,MMI_FRM_NODE_ALL_FLAG))
    {
        /* check the SCR_BT_CONNECTING screen is active or not.
        note: if the screen is active, return flase */
        if (!(mmi_frm_scrn_is_present(parent_id,SCR_BT_CONNECTING,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)))
        {
            mmi_frm_scrn_close(parent_id, SCR_BT_CONNECTING);  
            mmi_bt_entry_progress_scr();
        }
    }
#elif !defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__) && !defined(__MMI_BT_BOX_IDLE_SHORTCUTS__)
    // softkey needs to update first time,
    // other time like go back history, it will be updated by idle enter function
    // TODO: framework should emit the event after show category
    // then update can be done by scrlocker self.
    wgui_softkey_update();
#endif /* defined(__MMI_BT_DIALER_SUPPORT__) */

    mmi_slk_emit_locked(obj);

    return GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_close
 * DESCRIPTION
 *  This function closes the screen locker.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_on_close(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_classic_struct *p = (mmi_slk_classic_struct *)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    #ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
        mmi_slk_classic_popup_unlocked(NULL);
    #endif

    #ifdef __MMI_BTD_BOX_UI_STYLE__
        mmi_slk_classic_popup_unlocked_done_bt();
    #endif 

    if(p->popup_id)
    {
        mmi_alert_dismiss(p->popup_id);
    }

    mmi_slk_classic_on_suspend(obj, MMI_TRUE);

    //mmi_slk_emit_unlocked(obj);

    mmi_slk_obj_emit_closed_ind(obj);

    mmi_factory_delete_obj(
        (mmi_factory_obj_struct *)obj,
        mmi_slk_get_cfg_table(), 
        mmi_slk_buffer_free);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_run
 * DESCRIPTION
 *  This function runs the screen locker.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_classic_on_run(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_backlight_half_mode();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_key
 * DESCRIPTION
 *  This function handles the key event.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  key_evt             : [IN]          Key event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_slk_classic_on_key(
    mmi_slk_obj_struct *obj,
    mmi_frm_key_evt_struct *key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_classic_struct *p;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Ask parent.
     */
    ret = mmi_slk_obj_on_key(obj, key_evt);
    if (ret != MMI_RET_OK)
    {
        return ret;
    }

    p = (mmi_slk_classic_struct *)obj;

    /*
     * Continue the key routing for unlocking screen (non-touch project only).
     */
    if ((p->is_unlocking == MMI_TRUE) &&
        (key_evt->key_code == mmi_slk_classic_get_unlock_final_key()))
    {
        return MMI_RET_OK;
    }

    /*
     * Start unlock process or prompt the user to unlock phone.
     */
    #ifndef __MMI_BTD_BOX_UI_STYLE__
    if (key_evt->key_type == KEY_EVENT_DOWN)
    #else
    if (key_evt->key_type == KEY_EVENT_UP)
    #endif /*__MMI_BTD_BOX_UI_STYLE__*/
    {
        if (key_evt->key_code == mmi_slk_classic_get_unlock_trigger_key())
        {
          #ifndef __MMI_BTD_BOX_UI_STYLE__
            mmi_slk_classic_popup_unlock_me(p); /* Shall stop key routing. */
	  #else	
	    mmi_scr_locker_close();
	    srv_prof_play_tone(SRV_PROF_TONE_SUCCESS, NULL);
	  #endif /*__MMI_BTD_BOX_UI_STYLE__*/
        }
        #ifndef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__
        else
        {
          #ifndef __MMI_BTD_BOX_UI_STYLE__
            mmi_slk_classic_popup_help_msg(p);  /* Shall stop key routing. */
          #else
	    mmi_slk_classic_unlock_popup_bt();
          #endif /*__MMI_BTD_BOX_UI_STYLE__*/
        }
        #endif
    }

    return MMI_RET_STOP_KEY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_classic_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_classic_on_init(void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_classic_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_init((mmi_slk_obj_struct *)obj);

    p = (mmi_slk_classic_struct *)obj;

    /* Member variable. */
    p->type = MMI_SCR_LOCKER_TYPE_CLASSIC;
    //if invalid, ncenter notification will show when locked
    //p->scenario = MMI_SCENARIO_ID_INVALID; /* Do not modify scenario. */

    /* Member function. */
    p->on_create = mmi_slk_classic_on_create;
    p->on_close = mmi_slk_classic_on_close;
    p->on_run = mmi_slk_classic_on_run;
    p->on_key = mmi_slk_classic_on_key;
    p->on_suspend = mmi_slk_classic_on_suspend;
    p->on_resume = mmi_slk_classic_on_resume;
}

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata , code
#endif

#endif

