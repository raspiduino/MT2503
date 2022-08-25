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
 *  ScrLockerShell.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the shell screen locker.
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

#if defined(__MMI_VUI_SHELL_SCREEN_LOCK__)

#include "vadp_p2v_shell_scrlock.h"

// auto add by kw_check begin
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
#include "ScrLockerShell.h"
#include "ScrLockerGprot.h"
#ifdef __MMI_REDUCED_KEYPAD__
#include "DialerGprot.h"
#endif
// auto add by kw_check end 
#include "MMI_ap_dcm_config.h"
#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata = "DYNAMIC_CODE_SCRLOCK_RODATA" , code = "DYNAMIC_CODE_SCRLOCK_ROCODE"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

#ifdef __MMI_REDUCED_KEYPAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_shell_launch_sos_dialer
 * DESCRIPTION
 *  This function launches the SOS dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_shell_launch_sos_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dialer_launch_by_string_ex(CUI_DIALER_TYPE_SOS, L"112");
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_shell_leave_proc
 * DESCRIPTION
 *  This function is the leave proc.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_shell_leave_proc(mmi_event_struct *event)
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
            ret = -1; /* Do not close me. */
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_shell_enter
 * DESCRIPTION
 *  This function enters the shell screen lock.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_shell_enter(mmi_scrn_essential_struct *param)
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
            (FuncPtr)mmi_slk_shell_enter,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        param->group_id,
        param->scrn_id,
        mmi_slk_shell_leave_proc);

    vadp_p2v_shell_scrlock_init();
    ExitCategoryFunction = vadp_p2v_shell_scrlock_deinit;

    /* [MAUI_02634724] 
     * In locked screen,
     * if no digital key: call sos when pressing send key
     * Otherwise, input "112" and then press send key to call sos
     *
     * __MMI_REDUCED_KEYPAD__ : no digital key
     *
     */
#ifdef __MMI_REDUCED_KEYPAD__ 
    SetKeyHandler(mmi_slk_shell_launch_sos_dialer, KEY_SEND, KEY_EVENT_DOWN);
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
 *  mmi_slk_shell_on_run
 * DESCRIPTION
 *  This function runs the screen locker.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_shell_on_run(mmi_slk_obj_struct *obj)
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
        (FuncPtr)mmi_slk_shell_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_shell_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_shell_on_init(void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_shell_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_init((mmi_slk_obj_struct *)obj);

    p = (mmi_slk_shell_struct *)obj;

    /* Member variable. */
    p->type = MMI_SCR_LOCKER_TYPE_SHELL;

    /* Member function. */
    p->on_run = mmi_slk_shell_on_run;
}

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata , code
#endif

#endif /* defined(__MMI_VUI_SHELL_SCREEN_LOCK__) */

