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
 *  ScrLockerPopup.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the popup used by classic screen locker.
 *
 *  TODO: check if this part can be handled by framework's popup mechanism.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "ScrLockerGprot.h"

#ifdef __MMI_SCREEN_LOCK_CLASSIC_NEPTUNE_LIKE_BWUI__

#include "ProfilesSrvGprot.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "ScrLockerPopup.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalResDef.h"
// auto add by kw_check end 

/****************************************************************************
 * Define
 ****************************************************************************/

/* Popup duration time in msec. */
#define MMI_SLK_POPUP_TIME              (2000)

/* Max number of the popup object. */
#define MMI_SLK_MAX_POPUP_OBJ_NUM       (2)


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_id                      parent_gid;
    mmi_id                      this_gid;
    U16                         str_id;
    U16                         img_id;
    mmi_slk_popup_enter_cb      enter;
    mmi_slk_popup_exit_cb       exit;
    void                       *user_data;
} mmi_slk_popup_struct;


/****************************************************************************
 * Global Context
 ****************************************************************************/

// TODO: Development only. Remove it later.
static S32 g_mmi_slk_popup_count = 0;


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_emit_popup_close_req
 * DESCRIPTION
 *  This function emits the popup close req event.
 * PARAMETERS
 *  obj             : [IN]          Popup object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_popup_emit_popup_close_req(mmi_slk_popup_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_close_req_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_SLK_POPUP_CLOSE_REQ, obj->this_gid);
    mmi_frm_group_post_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_emit_popup_closed_ind
 * DESCRIPTION
 *  This function emits the popup closed indication event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_popup_emit_popup_closed_ind(mmi_slk_popup_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_closed_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_SLK_POPUP_CLOSED_IND, obj->this_gid);
    mmi_frm_group_send_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_default_display
 * DESCRIPTION
 *  This function displays the default popup.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_popup_default_display(mmi_slk_popup_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    ShowCategory64Screen(obj->str_id, obj->img_id, NULL);

    mmi_frm_set_group_key_handler(
        mmi_frm_scrn_close_active_id,
        (PU16)PresentAllKeys,
        TOTAL_KEYS,
        KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_exit
 * DESCRIPTION
 *  This function is the exit function of the popup.
 * PARAMETERS
 *  param               : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_popup_exit(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    obj = (mmi_slk_popup_struct *)param->user_data;

    if (obj->exit)
    {
        obj->exit(obj->user_data);
    }

    mmi_slk_popup_emit_popup_close_req(obj);

    StopTimer(KEYPADUNLOCKEDMESSAGE_TIMER);
    srv_prof_stop_tone(SRV_PROF_TONE_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_enter
 * DESCRIPTION
 *  This function is the enter function of the popup.
 * PARAMETERS
 *  param               : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_popup_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    /*
     * Enter screen.
     */
    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            (FuncPtr)mmi_slk_popup_exit,
            NULL,
            MMI_FRM_SMALL_SCRN);

    if (!ret)
    {
        return;
    }

    obj = (mmi_slk_popup_struct *)param->user_data;

    /*
     * Display.
     */
    if (obj->enter)
    {
        obj->enter(obj->user_data);
    }
    else
    {
        mmi_slk_popup_default_display(obj);
    }

    StartTimer(
        KEYPADUNLOCKEDMESSAGE_TIMER,
        MMI_SLK_POPUP_TIME,
        mmi_frm_scrn_close_active_id);

    srv_prof_play_tone(SRV_PROF_TONE_SUCCESS, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_handle_group_deinit
 * DESCRIPTION
 *  This function handles the group deinit event.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_popup_handle_group_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    obj = (mmi_slk_popup_struct *)event->user_data;

    mmi_slk_popup_emit_popup_closed_ind(obj);
    mmi_mfree(obj);
    --g_mmi_slk_popup_count;

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_group_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_popup_group_evt_hdlr(mmi_event_struct *event)
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
            ret = mmi_slk_popup_handle_group_deinit(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_create
 * DESCRIPTION
 *  This function creates the popup.
 * PARAMETERS
 *  parent_gid              : [IN]          Parent group ID
 * RETURNS
 *  Group id of the popup.
 *****************************************************************************/
mmi_id mmi_slk_popup_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_slk_popup_struct *)mmi_malloc(sizeof(mmi_slk_popup_struct));
    ++g_mmi_slk_popup_count;
    MMI_ASSERT(g_mmi_slk_popup_count <= MMI_SLK_MAX_POPUP_OBJ_NUM); /* leak. */

    kal_mem_set(obj, 0, sizeof(mmi_slk_popup_struct));

    this_gid = mmi_frm_group_create(
                parent_gid,
                GRP_ID_AUTO_GEN,
                mmi_slk_popup_group_evt_hdlr,
                obj);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);

    obj->parent_gid = parent_gid;
    obj->this_gid = this_gid;

    return this_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_run
 * DESCRIPTION
 *  This function runs the popup.
 * PARAMETERS
 *  this_gid            : [IN]          Group ID of the popup
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_popup_run(mmi_id this_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_slk_popup_struct *)mmi_frm_group_get_user_data(this_gid);
    MMI_ASSERT(obj && obj->this_gid == this_gid);

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_SLK_POPUP,
        (FuncPtr)mmi_slk_popup_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_close
 * DESCRIPTION
 *  This function closes the popup.
 * PARAMETERS
 *  this_gid            : [IN]          Group ID of the popup
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_popup_close(mmi_id this_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_slk_popup_struct *)mmi_frm_group_get_user_data(this_gid);
    MMI_ASSERT(obj && obj->this_gid == this_gid);

    mmi_frm_group_close(obj->this_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_set_string
 * DESCRIPTION
 *  This function sets the string of the popup.
 * PARAMETERS
 *  this_gid            : [IN]          Group ID of the popup
 *  str_id              : [IN]          String ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_popup_set_string(mmi_id this_gid, U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_slk_popup_struct *)mmi_frm_group_get_user_data(this_gid);
    MMI_ASSERT(obj && obj->this_gid == this_gid);

    obj->str_id = str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_set_image
 * DESCRIPTION
 *  This function sets the image of the popup.
 * PARAMETERS
 *  this_gid            : [IN]          Group ID of the popup
 *  img_id              : [IN]          Image ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_popup_set_image(mmi_id this_gid, U16 img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_slk_popup_struct *)mmi_frm_group_get_user_data(this_gid);
    MMI_ASSERT(obj && obj->this_gid == this_gid);

    obj->img_id = img_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_popup_set_display
 * DESCRIPTION
 *  This function sets the display function of the popup.
 * PARAMETERS
 *  this_gid            : [IN]          Group ID of the popup
 *  enter               : [IN]          Enter function for the display
 *  exit                : [IN]          Exit function for the display
 *  user_data           : [IN]          User data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_popup_set_display(
    mmi_id this_gid,
    mmi_slk_popup_enter_cb enter,
    mmi_slk_popup_exit_cb exit,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_popup_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (mmi_slk_popup_struct *)mmi_frm_group_get_user_data(this_gid);
    MMI_ASSERT(obj && obj->this_gid == this_gid);

    obj->enter = enter;
    obj->exit = exit;
    obj->user_data = user_data;
}
#endif
