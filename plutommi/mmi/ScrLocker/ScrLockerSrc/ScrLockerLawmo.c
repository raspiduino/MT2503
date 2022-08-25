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
 *  ScrLockerLawmo.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the Lock and Wipe Management Object (LAWMO) screen
 *  locker.
 *
 *  LAWMO lock is required by the operator. When the operator wants to lock the
 *  handset, it will send a message to the handset. After the Device Management
 *  (DM) parses the message, it will notify the screen locker to lock the
 *  handset.
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

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#if defined(__DM_LAWMO_SUPPORT__)

#include "IdleGprot.h"
#include "DialerGprot.h"
#include "GpioSrvGprot.h"
#include "GpioSrvGprot.h"
#include "UcmSrvGprot.h"
#include "dmuigprot.h"
#include "ScrSaverGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MMIDataType.h"
#include "mmiapi_dm_struct.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "ScrLockerMain.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "ScrLockerLawmo.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "ScrLockerGprot.h"
#include "DialerCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "ScrLockerObject.h"
#include "gui_typedef.h"
#include "mmi_frm_input_gprot.h"
#include "DmSrvGprot.h"
#include "UcmGProt.h"

/**********************************************************************
 * Typedef
 **********************************************************************/

/* LAWMO screen locker state. */
typedef enum
{
    MMI_SLK_LAWMO_STATE_NULL,
    MMI_SLK_LAWMO_STATE_LOCK,
    MMI_SLK_LAWMO_STATE_LOCK_FOR_WIPE
} mmi_slk_lawmo_state_enum;

/* LAWMO screen locker context structure. */
typedef struct
{
    U8                          flag;
    mmi_slk_lawmo_state_enum    state;
    mmi_slk_lawmo_state_enum    prev_state;
} mmi_slk_lawmo_context_struct;


/**********************************************************************
 * Global variables
 **********************************************************************/

static mmi_slk_lawmo_context_struct g_mmi_slk_lawmo_cntx;


/**********************************************************************
 * Prototype
 **********************************************************************/

static void mmi_slk_lawmo_sync_state(void);


/****************************************************************************
 * Unit Test
 ****************************************************************************/

//#define SCR_LOCKER_LAWMO_UNIT_TEST

#if defined(SCR_LOCKER_LAWMO_UNIT_TEST)

mmi_dmui_status_enum g_mmi_slk_lawmo_ut_status;

static void mmi_slk_lawmo_lock_cmd_hdlr(
    mmi_dmui_app_id_enum app_id,
    mmi_dmui_cmd_enum cmd);

#if !defined(__DM_LAWMO_SUPPORT__)
/*
 * Adaptation if LAWMO is not turned on.
 */

/* Fake string ID: */
#define STR_ID_SLK_LAWMO_LOCKED            STR_GLOBAL_NOT_AVAILABLE
#define STR_ID_SLK_LAWMO_WIPING            STR_GLOBAL_BUSY_TRY_LATER
#define STR_ID_SLK_LAWMO_POPUP_WIPING      STR_GLOBAL_ON
#define STR_ID_SLK_LAWMO_POPUP_WIPING_DONE STR_GLOBAL_OFF
#define STR_ID_SLK_LAWMO_POPUP_LOCKED      STR_GLOBAL_YES
#define STR_ID_SLK_LAWMO_POPUP_UNLOCKED    STR_GLOBAL_NO
#define STR_ID_SLK_LAWMO_DEVICE_MANAGEMENT STR_GLOBAL_LOGO

/* Fake callback type: */
typedef void(*mmi_dmui_lawmo_cb)(mmi_dmui_app_id_enum, mmi_dmui_cmd_enum);


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_report
 * DESCRIPTION
 *  This function is the fake function for LAWMO locker UT.
 * PARAMETERS
 *  result              : [IN]          Fake
 *  cmd                 : [IN]          Fake
 *  app_id              : [IN]          Fake
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dmui_lawmo_report(
        mmi_dmui_app_id_enum app_id,
        mmi_dmui_cmd_enum cmd,
        mmi_dmui_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_get_status
 * DESCRIPTION
 *  This function is the fake function for LAWMO locker UT.
 * PARAMETERS
 *  mo_type             : [IN]          Fake
 * RETURNS
 *  Fake
 *****************************************************************************/
mmi_dmui_status_enum mmi_dmui_get_status(mmi_dmui_mo_type_enum mo_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_slk_lawmo_ut_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_lawmo_register_notify
 * DESCRIPTION
 *  This function is the fake function for LAWMO locker UT.
 * PARAMETERS
 *  app_id                  : [IN]              Fake
 *  mo_type                 : [IN]              Fake
 *  lawmo_callback          : [IN]              Fake
 * RETURNS
 *  Fake
 *****************************************************************************/
mmi_dmui_result_enum mmi_dmui_lawmo_register_notify(
                        mmi_dmui_app_id_enum app_id,
                        mmi_dmui_mo_type_enum mo_type,
                        mmi_dmui_lawmo_cb lawmo_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_DMUI_RESULT_SUCCESS;
}
#endif /* !defined(__DM_LAWMO_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_inject_msg_hdlr
 * DESCRIPTION
 *  This function handles the inject message for LAWMO locker UT.
 * PARAMETERS
 *  string              : [IN]          String
 *  index               : [IN]          Index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_lawmo_inject_msg_hdlr(kal_uint8 *string, kal_uint8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_cmd_enum cmd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((S8 *)string, "lock") == 0)
    {
        g_mmi_slk_lawmo_ut_status = MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK;
        cmd = MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK;
    }
    else if (strcmp((S8 *)string, "wipe") == 0)
    {
        g_mmi_slk_lawmo_ut_status = MMI_DMUI_STATUS_LAWMO_WIPE_WIPE;
        cmd = MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK;
    }
    else if (strcmp((S8 *)string, "unlock") == 0)
    {
        g_mmi_slk_lawmo_ut_status = MMI_DMUI_STATUS_IDLE;
        cmd = MMI_DMUI_CMD_LAWMO_UNLOCK;
    }

    mmi_slk_lawmo_lock_cmd_hdlr(MMI_DMUI_APP_ID_IDLE, cmd);
}
#endif /* defined(SCR_LOCKER_LAWMO_UNIT_TEST) */


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_initialize
 * DESCRIPTION
 *  This function initializes the idle application for the DM LAWMO feature.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Reset the context structure. */
    memset(&g_mmi_slk_lawmo_cntx, 0, sizeof(mmi_slk_lawmo_context_struct));

    /* Sync the state with DM. */
    mmi_slk_lawmo_sync_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_get_state
 * DESCRIPTION
 *  This function gets the state of the LAWMO screen locker.
 * PARAMETERS
 *  void
 * RETURNS
 *  State.
 *****************************************************************************/
static mmi_slk_lawmo_state_enum mmi_slk_lawmo_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_GET_STATE, g_mmi_slk_lawmo_cntx.state));

    return g_mmi_slk_lawmo_cntx.state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_set_state
 * DESCRIPTION
 *  This function sets the state of the LAWMO screen locker.
 * PARAMETERS
 *  state           : [IN]          State
 * RETURNS
 *  If state is changed, return MMI_TRUE. Otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_slk_lawmo_set_state(mmi_slk_lawmo_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_SET_STATE, g_mmi_slk_lawmo_cntx.state, state));

    if (g_mmi_slk_lawmo_cntx.state == state)
    {
        return MMI_FALSE;
    }
    else
    {
        g_mmi_slk_lawmo_cntx.state = state;
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_sync_state
 * DESCRIPTION
 *  This function synchronizes the state between Idle and DM after the handset
 *  re-boots.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_sync_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_dmui_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_SYNC_STATE));

    //status = mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK);

    if (srv_dm_lawmo_is_locked())
    {
        mmi_slk_lawmo_set_state(MMI_SLK_LAWMO_STATE_LOCK);
    }
    else
    {
        mmi_slk_lawmo_set_state(MMI_SLK_LAWMO_STATE_NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_is_locked
 * DESCRIPTION
 *  This function checks if the LAWMO lock happens.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_slk_lawmo_is_locked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_lawmo_state_enum state = mmi_slk_lawmo_get_state();
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state != MMI_SLK_LAWMO_STATE_NULL)
    {
        ret = MMI_TRUE;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_IS_LOCKED, ret));

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_is_in_puk
 * DESCRIPTION
 *  This function checks if the handset is in the "Enter PUK:" screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_slk_lawmo_is_in_puk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sim_ctrl_any_verifying_sim();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_get_slk_hist
 * DESCRIPTION
 *  This function check if the handset is in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_slk_lawmo_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_ucm_is_any_call();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_delete_non_puk_screen
 * DESCRIPTION
 *  This function deletes all non-PUK screen in the history.
 *
 *  Prepare the history to display after the popup finishes.
 *
 *  History (left: buttom, right: top):
 *
 *      {idle screen}, {UCM related screen}
 *
 *  TODO: this solution is not good. After 10A, when all APP use the
 *  screen group, we should terminate all APP except UCM.
 *
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

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_display_idle
 * DESCRIPTION
 * PARAMETERS
 *  popup_str_id        : [IN]      String ID for the popup
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_display_idle(U16 popup_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    // framework supports that delete all screen in history 
    // except the screen which return -1 in their leave proc
    mmi_idle_display();

    // popup indication if screen is still active
    if (mmi_slk_lawmo_is_in_call())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_DISPLAY_IDLE, 201));

        mmi_popup_display_simple(
            (WCHAR *)get_string(popup_str_id),
            MMI_EVENT_WARNING,
            GRP_ID_ROOT,
            NULL);
    }
    else if (mmi_slk_lawmo_is_in_puk())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_DISPLAY_IDLE, 202));

        mmi_popup_display_simple(
            (WCHAR *)get_string(popup_str_id),
            MMI_EVENT_WARNING,
            GRP_ID_ROOT,
            NULL);
    }

    MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_DISPLAY_IDLE, 200));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_proc_partial_lock
 * DESCRIPTION
 *  This function processes the command of the LAWMO lock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_proc_partial_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_dmui_status_enum status;
    MMI_BOOL ret = MMI_FALSE;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* For the LAWMO WIPE, the handset will go to the idle screen and lock to
       prevent from unwanted operations. Different strings are used to notify
       the user about the lock event. */
    //status = mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_WIPE);

    if (srv_dm_lawmo_is_wiping())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_PROC_PARTIAL_LOCK, 100));
        ret = mmi_slk_lawmo_set_state(MMI_SLK_LAWMO_STATE_LOCK_FOR_WIPE);
        str_id = STR_ID_SLK_LAWMO_POPUP_WIPING;
    }
    else if (srv_dm_lawmo_is_locked())
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_PROC_PARTIAL_LOCK, 101));
        ret = mmi_slk_lawmo_set_state(MMI_SLK_LAWMO_STATE_LOCK);
        str_id = STR_ID_SLK_LAWMO_POPUP_LOCKED;
    }

    if (ret)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_PROC_PARTIAL_LOCK, 200));
        mmi_slk_lawmo_display_idle(str_id);

        mmi_scr_locker_close();
        mmi_scr_locker_launch_ex(MMI_SCR_LOCKER_TYPE_LAWMO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_proc_unlock
 * DESCRIPTION
 *  This function processes the command the LAWMO unlock.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_proc_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* For the LAWMO WIPE, the handset will go to the idle screen and lock to
       prevent from unwanted operations. Different strings are used to notify
       the user about the unlock event. */
    if (mmi_slk_lawmo_get_state() == MMI_SLK_LAWMO_STATE_LOCK_FOR_WIPE)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_PROC_UNLOCK, 100));
        str_id = STR_ID_SLK_LAWMO_POPUP_WIPING_DONE;
    }
    else
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_PROC_UNLOCK, 101));
        str_id = STR_ID_SLK_LAWMO_POPUP_UNLOCKED;
    }

    ret = mmi_slk_lawmo_set_state(MMI_SLK_LAWMO_STATE_NULL);
    if (ret)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_PROC_UNLOCK, 200));
        mmi_scr_locker_close();
        mmi_slk_lawmo_display_idle(str_id);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_handle_dm_lawmo_lock
 * DESCRIPTION
 *  This function is the command handler for the MO type of LAWMO lock.
 * PARAMETERS
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_lawmo_handle_dm_lawmo_lock(mmi_event_struct *evt )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_lock_ind_evt_struct *lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;

    switch (lawmo_lock_ind->cmd)
    {
        case SRV_DM_LAWMO_LOCK_CMD_LOCK:
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LOCK_CMD_HDLR, 200));
            mmi_slk_lawmo_proc_partial_lock();
            break;

        case SRV_DM_LAWMO_LOCK_CMD_UNLOCK:
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LOCK_CMD_HDLR, 201));
            mmi_slk_lawmo_proc_unlock();
            break;

        default:
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LOCK_CMD_HDLR, 400));
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_handle_dm_lawmo_wipe
 * DESCRIPTION
 *  This function is the command handler for the MO type of LAWMO wipe.
 * PARAMETERS
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_lawmo_handle_dm_lawmo_wipe(mmi_event_struct *evt )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind = (srv_dm_lawmo_wipe_ind_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    switch (lawmo_wipe_ind->cmd)
    {
        case SRV_DM_LAWMO_WIPE_CMD_START:
            g_mmi_slk_lawmo_cntx.prev_state = g_mmi_slk_lawmo_cntx.state;
            mmi_slk_lawmo_proc_partial_lock();
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LOCK_CMD_HDLR, 400));
            break;

        case SRV_DM_LAWMO_WIPE_CMD_FINISH:
            mmi_slk_lawmo_proc_unlock();
            if (g_mmi_slk_lawmo_cntx.prev_state != MMI_SLK_LAWMO_STATE_NULL)
            {
                mmi_scr_locker_launch_ex(MMI_SCR_LOCKER_TYPE_LAWMO);
            }
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LOCK_CMD_HDLR, 401)); // 401?
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_launch_sos_dialer
 * DESCRIPTION
 *  This function launches the SOS dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_launch_sos_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dialer_launch_by_string_ex(CUI_DIALER_TYPE_SOS, L"112");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_leave_proc
 * DESCRIPTION
 *  This function is the leave proc.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_lawmo_leave_proc(mmi_event_struct *event)
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
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:     /* fall-throught */
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LEAVE_PROC, event->evt_id, 300));
            ret = -1; /* Do not close me. */
            break;

        default:
            MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_LEAVE_PROC, event->evt_id, 200));
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_entry_locked_screen
 * DESCRIPTION
 *  This function enters the DM LAWMO lock screen.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_lawmo_state_enum state;
    U16 str_id;
    U16 img_id;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            (FuncPtr)mmi_slk_lawmo_enter,
            MMI_FRM_FULL_SCRN);

    // set leave proc even the screen is not active
    mmi_frm_scrn_set_leave_proc(
        param->group_id,
        param->scrn_id,
        mmi_slk_lawmo_leave_proc);

    if (!ret)
    {
        MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_ENTER, 300));
        return;
    }

    MMI_SLK_LOG((TRC_MMI_SLK_LAWMO_ENTER, 200));

    /*
     * Determine the string and image in the screen.
     */
    state = mmi_slk_lawmo_get_state();

    MMI_DBG_ASSERT(state != MMI_SLK_LAWMO_STATE_NULL);

    if (state == MMI_SLK_LAWMO_STATE_LOCK_FOR_WIPE)
    {
        str_id = STR_ID_SLK_LAWMO_WIPING;
        img_id = IMG_GLOBAL_PROGRESS;
    }
    else
    {
        str_id = STR_ID_SLK_LAWMO_LOCKED;
        img_id = IMG_ID_SLK_LOCKED;
    }

    ShowCategory154Screen(
        STR_ID_SLK_LAWMO_DEVICE_MANAGEMENT,
        0,
        0,
        0,
        STR_ID_SLK_SOS,
        0,
        (U8 *)GetString(str_id),    /* message line 1 */
        NULL,                       /* message line 2 */
        img_id,                     /* image */
        NULL);

    SetRightSoftkeyFunction(mmi_slk_lawmo_launch_sos_dialer, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_on_run
 * DESCRIPTION
 *  This function runs the screen locker.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_lawmo_on_run(mmi_slk_obj_struct *obj)
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
        (FuncPtr)mmi_slk_lawmo_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_on_suspend
 * DESCRIPTION
 *  This function handles the suspend event.
 * PARAMETERS
 *  obj             : [IN]          Object
 *  is_closed       : [IN]          Suspend because the lock is closed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_lawmo_on_suspend(mmi_slk_obj_struct *obj, MMI_BOOL is_closed)
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

    /*
     * For LAWMO, UE requires the lower priority events cannot be shown until
     * the lock is closed by the operator. Thus, we never end the scenario until
     * the lock is closed.
     */
    if (is_closed && obj->scenario != MMI_SCENARIO_ID_INVALID)
    {
        mmi_frm_end_scenario(obj->scenario);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_on_want_to_run
 * DESCRIPTION
 *  This function checks if the locker wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_slk_lawmo_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Ask parent.
     */
    if (!mmi_slk_obj_on_want_to_run())
    {
        return MMI_FALSE;
    }

    return mmi_slk_lawmo_is_locked();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_lawmo_on_init(void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_lawmo_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_init((mmi_slk_obj_struct *)obj);

    p = (mmi_slk_lawmo_struct *)obj;

    /* Member variable. */
    p->type = MMI_SCR_LOCKER_TYPE_LAWMO;
    p->scenario = MMI_SCENARIO_ID_HIGHEST_SCRN;

    /* Member function. */
    p->on_run = mmi_slk_lawmo_on_run;
    p->on_suspend = mmi_slk_lawmo_on_suspend;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_handle_idle_launched
 * DESCRIPTION
 *  This function handles the Idle launched event for LAWMO locker.
 * PARAMETERS
 *  void
 * RETURNS
 *  On handled, return -1 to stop the event routing; otherwise, return
 *  MMI_RET_OK;
 *****************************************************************************/
mmi_ret mmi_slk_lawmo_handle_idle_launched(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_lawmo_init();

    if (mmi_slk_lawmo_is_locked())
    {
        mmi_scr_locker_launch_ex(MMI_SCR_LOCKER_TYPE_LAWMO);
        return -1; /* Stop the event routing. */
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_lawmo_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler of lawmo screen locker.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_slk_lawmo_evt_hdlr(mmi_event_struct *event)
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
        case EVT_ID_SRV_DM_LAWMO_LOCK_IND:
            ret = mmi_slk_lawmo_handle_dm_lawmo_lock(event);
            break;
            
        case EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND:
            ret = mmi_slk_lawmo_handle_dm_lawmo_wipe(event);
            break;
            
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


#endif /* defined(__DM_LAWMO_SUPPORT__) */

