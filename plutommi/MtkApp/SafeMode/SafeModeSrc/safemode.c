/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  safemode.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the safe mode in pluto package..
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SAFE_MODE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "wgui_categories_util.h"
#include "SafeModeSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "ProfilesSrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "safemode.h"
#include "mmi_rp_app_safemode_def.h"
#include "gui_touch_feedback.h"
#include "GeneralSettingSrvGprot.h" // for EVT_ID_SETTING_LANGUAGE_CHANGED
extern MMI_BOOL mmi_bootup_ani_is_playing(void);

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

static SafeModeStruct g_SafeMode = {MMI_FALSE,0};
/*****************************************************************************
 * Define
 *****************************************************************************/
#define SAFE_MODE_KEY_0  KEY_RSK   // first pressed key
#define SAFE_MODE_KEY_1  KEY_RSK   // next pressed key

/*****************************************************************************
 * Prototype
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_handle_bootup_early_init
 * DESCRIPTION
 *  This function handles the "bootup-early-init" event.
 * PARAMETERS
 *  event           : [IN]
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret mmi_safe_mode_handle_bootup_early_init(
    mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_handle_pre_key_routing
 * DESCRIPTION
 *  This function handles the "pre-key-routing" event.
 * PARAMETERS
 *  event           : [IN]
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret mmi_safe_mode_handle_pre_key_routing(
    mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_get_last_time
 * DESCRIPTION
 *  This function gets the last time that the abnormal reset happens.
 * PARAMETERS
 *  time           : [OUT]      Time
 * RETURNS
 *  If it is present, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_safe_mode_get_last_time(
    U32 *time);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_set_time
 * DESCRIPTION
 *  This function sets the time that the abnormal reset happens.
 * PARAMETERS
 *  time           : [IN]       Time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_safe_mode_set_time(
    U32 time);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_activate
 * DESCRIPTION
 *  This function activates the safe mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_safe_mode_activate();

static mmi_ret mmi_safe_mode_handle_language_changed(mmi_event_struct *event);
/*****************************************************************************
 * Function
 *****************************************************************************/
mmi_ret mmi_safe_mode_handle_language_changed(mmi_event_struct *event)
{
    if (srv_safe_mode_is_active())
    {
        wgui_status_icon_bar_show_warning_info(
            (UI_string_type)GetString(STR_ID_SAFE_MODE_EXIT));
    }

    return MMI_RET_OK;
}

mmi_ret mmi_safe_mode_handle_bootup_early_init(mmi_event_struct *event)
{
#if defined(CFG_VAPP_SAFE_MODE_UNIT_TEST)
    mmi_safe_mode_activate();
#else
    //
    // Auto activation of the safe mode:
    //
    // The mobile abnormally resets twices in a short time.
    //

    if (srv_bootup_is_exception_mode())
    {
        // Get the last time that the abnormal reset happens.
        U32 lastTime=0;
        MMI_BOOL ret = mmi_safe_mode_get_last_time(&lastTime);

        // Update the time that the abnromal reset happens.
        U32 currTime = app_getcurrtime();
        mmi_safe_mode_set_time(currTime);

        // Check if criteria is matched to activate safe mode.
        if (ret && currTime < lastTime + MMI_SAFE_MODE_AUTO_CRITERIA)
        {
            mmi_safe_mode_activate();
        }
    }
#endif /* defined(CFG_VAPP_SAFE_MODE_UNIT_TEST) */

    return MMI_RET_OK;
}

mmi_ret mmi_safe_mode_handle_pre_key_routing(mmi_event_struct *event)
{
    //
    // Manual activation of the safe mode:
    //
    // The user presses the "Power" key and then the "End" key in a short time.
    //
    mmi_frm_key_evt_struct *evt = (mmi_frm_key_evt_struct *)event;
    U32 criteria;
    
    // If bootup is completed or safe mode is already active, do nothing.
    if (srv_bootup_is_completed() || srv_safe_mode_is_active())
    {
        return MMI_RET_OK;
    }
	if(mmi_bootup_ani_is_playing() == MMI_FALSE)
	{
		    return MMI_RET_OK;  // Avoid verfication screen.
    }
    if (!g_SafeMode.isKeyPressed)
    {
        // Wait until the first define key down event.
        if (evt->key_code != SAFE_MODE_KEY_0 || evt->key_type != KEY_EVENT_DOWN)
        {
            return MMI_RET_OK;
        }

        g_SafeMode.isKeyPressed = MMI_TRUE;
        g_SafeMode.keyTime = app_getcurrtime();
    }
    else
    {
        // First key has been pressed down. Wait until the next key down event.
        if (evt->key_type != KEY_EVENT_DOWN)
        {
            return MMI_RET_OK;
        }

        criteria = g_SafeMode.keyTime + MMI_SAFE_MODE_MANUAL_CRITERIA;

        if (evt->key_code == SAFE_MODE_KEY_1 && app_getcurrtime() <= criteria)
        {
            // Play a tone if the user activates it manually.
            srv_prof_play_tone(SRV_PROF_TONE_WARNING, NULL);

            // Activate the safe mode.
            mmi_safe_mode_activate();
        }

        g_SafeMode.isKeyPressed = MMI_FALSE;
    }

    return MMI_RET_OK;
}

mmi_ret mmi_safe_mode_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = mmi_safe_mode_handle_bootup_early_init(event);
            break;

        case EVT_ID_PRE_KEY_EVT_ROUTING:
            ret = mmi_safe_mode_handle_pre_key_routing(event);
            break;
        case EVT_ID_SETTING_LANGUAGE_CHANGED:
            ret = mmi_safe_mode_handle_language_changed(event);
            break;
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


MMI_BOOL mmi_safe_mode_get_last_time(U32 *time)
{
    //
    // Check if the last time is available.
    //
    U8 flag;
    S16 err;
    U64 tempValue;
    
    ReadValue(NVRAM_MMI_SAFE_MODE_FLAG, &flag, DS_BYTE, &err);
    MMI_ASSERT(err == NVRAM_READ_SUCCESS);

    if (!flag)
    {
        return MMI_FALSE;
    }

    //
    // Get the last time.
    //
    ReadValue(NVRAM_MMI_SAFE_MODE_TIME, &tempValue, DS_DOUBLE, &err);
    MMI_ASSERT(err == NVRAM_READ_SUCCESS);

    *time = (U32)tempValue;

    return MMI_TRUE;
}


void mmi_safe_mode_set_time(U32 time)
{
    //
    // Set flag.
    //
    U8 flag = 0x01;
    S16 err;
	U64 tempValue;
	
    WriteValue(NVRAM_MMI_SAFE_MODE_FLAG, &flag, DS_BYTE, &err);
    MMI_ASSERT(err == NVRAM_WRITE_SUCCESS);

    //
    // Set the time.
    //
    tempValue = time;

    WriteValue(NVRAM_MMI_SAFE_MODE_TIME, &tempValue, DS_DOUBLE, &err);
    MMI_ASSERT(err == NVRAM_WRITE_SUCCESS);
}


void mmi_safe_mode_activate()
{
    // Vibrate the phone.
    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);

    // Set text on the status icon bar.
    wgui_status_icon_bar_show_warning_info(
        (UI_string_type)GetString(STR_ID_SAFE_MODE_EXIT));
    // Activate the service.
    srv_safe_mode_activate();
}

#endif /* defined(__MMI_SAFE_MODE__) */
