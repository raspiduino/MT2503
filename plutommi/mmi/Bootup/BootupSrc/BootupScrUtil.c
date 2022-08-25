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
 *  BootupScrUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Screen utilities for bootup.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "BootupScrUtil.h"
#include "mmi_rp_app_bootup_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories.h"
#include "BootupScrUtil.h"


#if 0 /* slim_unused_api : bootup_count_down */
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
#ifndef __MMI_WGUI_DISABLE_CSK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */
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
#ifndef __MMI_WGUI_DISABLE_CSK__		
/* under construction !*/
#endif /* #ifndef __MMI_WGUI_DISABLE_CSK__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* slim_unused_api : bootup_count_down */

#if !defined(__MMI_BOOTUP_SLIM__)
/*****************************************************************************
 * [Waiting screen]
 *
 *
 *****************************************************************************/

#define MMI_BOOTUP_WAITING_SCREEN_DUMMY_TIMEOUT 200 /* ms */


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_id grp_id;
    U16 img_id;
    U16 prompt_str_id;
} mmi_bootup_waiting_scr_cntx_struct;


/****************************************************************************
 * Global variable
 ****************************************************************************/

static mmi_bootup_waiting_scr_cntx_struct g_mmi_bootup_waiting_scr_cntx;


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_waiting_screen_leave_proc
 * DESCRIPTION
 *  Handler of leave event of the waiting screen.
 *  To prevent screen from being deleted.
 * PARAMETERS
 *  evt     [IN] mmi_scenario_evt_struct*
 * RETURNS
 *  -1 for deleting events
 *****************************************************************************/
static mmi_ret mmi_bootup_waiting_screen_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
         return -1; /* Forbid closing */
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_waiting_key_proc
 * DESCRIPTION
 *  Key proc only allows power off
 * PARAMETERS
 *  evt     [IN] mmi_frm_key_evt_struct*
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_bootup_waiting_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_evt = (mmi_frm_key_evt_struct*)evt;

    if ((key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_LONG_PRESS) ||
        (key_evt->key_code == KEY_POWER && key_evt->key_type == KEY_EVENT_LONG_PRESS))
    {
        /* Power off */
        return MMI_RET_OK;
    }

    return MMI_RET_KEY_HANDLED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_entry_real_waiting_screen
 * DESCRIPTION
 *  The entry function of real waiting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_entry_real_waiting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_waiting_scr_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_waiting_scr_cntx);

    mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_DUMMY_WAITING, NULL);
    StopTimer(BOOTUP_WAITING_SCREEN_TIMER);

    if (!mmi_frm_scrn_enter(
        cntx->grp_id,
        SCR_ID_BOOTUP_REAL_WAITING,
        NULL,
        mmi_bootup_entry_real_waiting_screen,
        MMI_FRM_SMALL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_REAL_WAITING, mmi_bootup_waiting_screen_leave_proc);
        return;
    }
    else
    {
        mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_REAL_WAITING, mmi_bootup_waiting_screen_leave_proc);
    }

    ShowCategory66Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        (U8*)get_string(cntx->prompt_str_id),
        cntx->img_id,
        mmi_frm_scrn_get_active_gui_buf());

    mmi_frm_scrn_set_key_proc(
        cntx->grp_id,
        SCR_ID_BOOTUP_REAL_WAITING,
        mmi_bootup_waiting_key_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_waiting_screen_replace_by_real_waiting
 * DESCRIPTION
 *  Replace the dummy waiting screen by real waiting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_waiting_screen_replace_by_real_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_waiting_scr_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_waiting_scr_cntx);

    if (mmi_frm_group_get_active_id() == cntx->grp_id &&
        mmi_frm_scrn_get_active_id() == SCR_ID_BOOTUP_DUMMY_WAITING)
    {
        mmi_bootup_entry_real_waiting_screen();
        mmi_frm_scrn_close(cntx->grp_id, SCR_ID_BOOTUP_DUMMY_WAITING);
    }
	// slim_ifelse
    //else
    //{
        /*
         * mmi_bootup_entry_real_waiting_screen() was already set to
         * be the entry function.
         */
    //}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_waiting_screen_put_dummy
 * DESCRIPTION
 *  Put a dummy screen first and start a timer. We show real waiting screen
 *  to user until timeout to enhance UE.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bootup_waiting_screen_put_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_waiting_scr_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_waiting_scr_cntx);

    if (!mmi_frm_scrn_enter(
        cntx->grp_id,
        SCR_ID_BOOTUP_DUMMY_WAITING,
        NULL,
        mmi_bootup_entry_real_waiting_screen,
        MMI_FRM_SMALL_SCRN))
    {
        return;
    }

    ShowCategoryDummyScreen();

    mmi_frm_scrn_set_key_proc(
        cntx->grp_id,
        SCR_ID_BOOTUP_DUMMY_WAITING,
        mmi_bootup_block_all_keys);

    StartTimer(
        BOOTUP_WAITING_SCREEN_TIMER,
        MMI_BOOTUP_WAITING_SCREEN_DUMMY_TIMEOUT,
        mmi_bootup_waiting_screen_replace_by_real_waiting);
}
#endif /* !defined(__MMI_BOOTUP_SLIM__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_waiting_screen_show
 * DESCRIPTION
 *  Show a waiting screen.
 * PARAMETERS
 *  grp_id          [IN] Group ID
 *  img_id          [IN] Image ID
 *  prompt_str_id   [IN] The string to be shown to user
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_waiting_screen_show(
        mmi_id grp_id,
        U16 img_id,
        U16 prompt_str_id)
{
#if !defined(__MMI_BOOTUP_SLIM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bootup_waiting_scr_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_mmi_bootup_waiting_scr_cntx);

    if (mmi_frm_group_get_active_id() == grp_id &&
        mmi_frm_scrn_get_active_id() == SCR_ID_BOOTUP_REAL_WAITING &&
        img_id == cntx->img_id &&
        prompt_str_id == cntx->prompt_str_id)
    {
        /* Screen is already shown there */
        return;
    }

    cntx->grp_id = grp_id;
    cntx->prompt_str_id = prompt_str_id;
    cntx->img_id = img_id;

    if (mmi_frm_group_get_active_id() == grp_id &&
        mmi_frm_scrn_get_active_id() == SCR_ID_BOOTUP_DUMMY_WAITING)
    {
        /* Real waiting screen will come later, and show for the new parameters */
        return;
    }

    /* Close under dummy waiting in the history if any */
    StopTimer(BOOTUP_WAITING_SCREEN_TIMER);
    mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_DUMMY_WAITING, NULL);
    mmi_frm_scrn_close(grp_id, SCR_ID_BOOTUP_DUMMY_WAITING);

    /* Put dummy waiting */
    mmi_frm_scrn_first_enter(
        cntx->grp_id,
        SCR_ID_BOOTUP_DUMMY_WAITING,
        (FuncPtr)mmi_bootup_waiting_screen_put_dummy,
        cntx);
    
    mmi_frm_scrn_set_leave_proc(
        cntx->grp_id,
        SCR_ID_BOOTUP_DUMMY_WAITING,
        mmi_bootup_waiting_screen_leave_proc);

    /* Close under real waiting in the history if any */
    mmi_frm_scrn_set_leave_proc(cntx->grp_id, SCR_ID_BOOTUP_REAL_WAITING, NULL);
    mmi_frm_scrn_close(grp_id, SCR_ID_BOOTUP_REAL_WAITING);

#else /* !defined(__MMI_BOOTUP_SLIM__) */

    mmi_bootup_put_dummy_screen(grp_id);

#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_waiting_screen_close
 * DESCRIPTION
 *  Close waiting screen.
 * PARAMETERS
 *  grp_id          [IN] Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_waiting_screen_close(mmi_id grp_id)
{
#if !defined(__MMI_BOOTUP_SLIM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(grp_id, SCR_ID_BOOTUP_DUMMY_WAITING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_BOOTUP_DUMMY_WAITING, NULL);
        mmi_frm_scrn_close(grp_id, SCR_ID_BOOTUP_DUMMY_WAITING);
    }
    if (mmi_frm_scrn_is_present(grp_id, SCR_ID_BOOTUP_REAL_WAITING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(grp_id, SCR_ID_BOOTUP_REAL_WAITING, NULL);
        mmi_frm_scrn_close(grp_id, SCR_ID_BOOTUP_REAL_WAITING);
    }
    StopTimer(BOOTUP_WAITING_SCREEN_TIMER);
    
#else /* !defined(__MMI_BOOTUP_SLIM__) */

    mmi_bootup_close_dummy_screen(grp_id);

#endif
}



/*****************************************************************************
 * [Dummy screen]
 *
 *
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_put_dummy_screen
 * DESCRIPTION
 *  Put a dummy screen on the top. As another screen comes, the dummy screen
 *  will be removed.
 * PARAMETERS
 *  grp_id          [IN] Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_put_dummy_screen(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * If a screen will not be pushed into history, we should check
     * whether the active group is we required. Otherwise, when the
     * given group is entered from other group, framework can not
     * find the entry function and will hang.
     */
    if (!mmi_frm_group_is_in_active_serial(grp_id))
    {
        return;
    }
    
    if (!mmi_frm_scrn_enter(
        grp_id,
        SCR_ID_DUMMY,
        NULL,
        NULL,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategoryDummyScreen();

    mmi_frm_scrn_set_key_proc(
        grp_id,
        SCR_ID_DUMMY,
        mmi_bootup_block_all_keys);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_close_dummy_screen
 * DESCRIPTION
 *  Remove dummy screen if there is.
 * PARAMETERS
 *  grp_id          [IN] Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bootup_close_dummy_screen(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(grp_id, SCR_ID_DUMMY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bootup_block_all_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_bootup_block_all_keys(mmi_event_struct *evt)
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
 *  mmi_bootup_block_scr_deleting
 * DESCRIPTION
 *  To avoid the  screen from being deleted
 * PARAMETERS
 *  evt     [IN] mmi_scenario_evt_struct*
 * RETURNS
 *  -1 for deleting events
 *****************************************************************************/
mmi_ret mmi_bootup_block_scr_deleting(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
         return -1; /* Forbid closing */
    }
    
    return MMI_RET_OK;
}



