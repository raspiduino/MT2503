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
 *  IdleCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the common part of the idle application.
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
#include "IdleGprot.h"
#include "DialerGprot.h"
#include "ScrLockerGprot.h"
#include "NwInfoSrvGprot.h"
#include "NwNameSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "CphsSrvGprot.h"
#include "NetworkSetupGprot.h"
#include "BrowserGprots.h"
#include "browser_api.h"
#include "MiscFunctions.h"
#include "PhbCuiGprot.h"
#include "CallLogGprot.h"
#include "ShortcutsProts.h"
#include "VolumeHandler.h"
#include "CallSetSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "ImeiSrvGprot.h"
#include "netsetsrvgprot.h"
#include "AmGprot.h"
#include "NetworkSetupGProt.h"

#ifdef __MMI_BT_DIALER_SUPPORT__
#include "SettingGprots.h"
#include "UMGProt.h"
#include "AllAppGprot.h"
#ifdef __MMI_CALENDAR__
#include "CalendarGprot.h"
#endif
#include "BTMMIScrGprots.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "btcmSrvGprot.h"
#include "wgui_categories_idlescreen.h"
#endif

#if defined(__MMI_SEARCH_WEB__)
#include "SearchWebGProt.h"
#endif

#if 0
#if defined(__MMI_VRSD__)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_VRSI__)
/* under construction !*/
#endif
#endif

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#include "MMI_features_camera.h"
#include "CameraApp.h"
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
#include "CamcorderGprot.h"
#endif

#if defined(__MMI_ATV_SUPPORT__)
#include "MobileTVPlayerGProt.h"
#endif

#if (MMI_MAX_SIM_NUM >= 3)
#include "SimSpaceGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "IdleMain.h"
#include "IdleObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "mmi_rp_app_idle_def.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "gui_effect_oem.h"
#include "Unicodexdcl.h"
#include "l4c_nw_cmd.h"
#include "IdleCommon.h"
#include "wgui_inputs.h"

#if 0
#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_FM_RADIO__
/* under construction !*/
    #endif
#endif
#endif

/****************************************************************************
 * Global context
 ****************************************************************************/

typedef struct
{
    U8          flag;
    FuncPtr     right_softkey_hdlr;
    FuncPtr     left_softkey_hdlr;
} mmi_idle_key_cntx_struct;


static mmi_idle_key_cntx_struct g_idle_key_cntx;


/****************************************************************************
 * Define
 ****************************************************************************/

#define MMI_IDLE_KEY_DELAYED_RSK_TIMEOUT_VALUE      (500)


/****************************************************************************
 * Option Flag
 ****************************************************************************/

#define MMI_IDLE_KEY_FLAG_DISABLE_LOCK_BY_END       (1 << 0)


/* Macro: (1) set flag (2) clear flag and (3) check if flag is set. */
#define MMI_IDLE_KEY_SET(_f)       (g_idle_key_cntx.flag |= _f)
#define MMI_IDLE_KEY_CLR(_f)       (g_idle_key_cntx.flag &= ~_f)
#define MMI_IDLE_KEY_HAS(_f)       (((g_idle_key_cntx.flag & _f) == _f))


/****************************************************************************
 * Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_rsk_hdlr
 * DESCRIPTION
 *  This function sets the right softkey handler.
 * PARAMETERS
 *  hdlr                : [IN]          Key handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_rsk_hdlr(FuncPtr hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (hdlr)
    {
        if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
        {
            //SetKeyHandler(hdlr, KEY_RSK, KEY_EVENT_DOWN);
			SetKeyDownHandler(hdlr, KEY_RSK);
        }
        else
        {
            SetRightSoftkeyFunction(hdlr, KEY_EVENT_UP);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_rsk_view
 * DESCRIPTION
 *  This function sets the right softkey string and image.
 * PARAMETERS
 *  string_id           : [IN]          String ID
 *  image_id            : [IN]          Image ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_rsk_view(U16 string_id, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
   
    if (obj->capability & ENABLE_SOFT_KEY_AREA)
    {
        ChangeRightSoftkey(string_id, image_id);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_csk_hdlr
 * DESCRIPTION
 *  This function sets the center softkey handler.
 * PARAMETERS
 *  hdlr                : [IN]          Key handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_csk_hdlr(FuncPtr hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (hdlr)
    {
        if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
        {
            //SetKeyHandler(hdlr, KEY_CSK, KEY_EVENT_DOWN);
			SetKeyDownHandler(hdlr, KEY_CSK);
        }
        else
        {
            SetCenterSoftkeyFunction(hdlr, KEY_EVENT_UP);
        }
    }
}

#ifndef __MMI_WGUI_DISABLE_CSK__

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_csk_view
 * DESCRIPTION
 *  This function sets the center softkey string and image.
 * PARAMETERS
 *  string_id           : [IN]          String ID
 *  image_id            : [IN]          Image ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_csk_view(U16 string_id, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (obj->capability & ENABLE_SOFT_KEY_AREA)
    {
        ChangeCenterSoftkey(string_id, image_id);
    }
}
#endif /*__MMI_WGUI_DISABLE_CSK__*/


#if defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_camera_ex
 * DESCRIPTION
 *  This function entry the camera application. In addition, it will stop the
 *  current audio player.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_camera_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Stop playing audio by camera key.
     */
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        mmi_audply_do_stop_action(MMI_TRUE);
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_power_on_check(MMI_FALSE);
    }
    else
#endif /* __MMI_FM_RADIO__ */
#if 0
#ifdef __A8BOX_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __A8BOX_SUPPORT__ */
#endif

    /*
     * Launch camera.
     */
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    mmi_camera_lauch();
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
    mmi_camco_launch();
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
}
#endif /* defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__) */


#if (__MRE_AM__) && defined(__MMI_MRE_APP_OPERA_MINI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_mre_opera
 * DESCRIPTION
 *  This function launches the MRE Opera Mini browser.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_mre_opera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_start_from_mm(APPID_OPERA);
}
#endif /* (__MRE_AM__) && defined(__MMI_MRE_APP_OPERA_MINI__) */

#if 0
#if defined(__OP12__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP12__ */
/* under construction !*/
/* under construction !*/
#if defined(__MMI_OP01_WITH_WAP_KEY__)
#if defined(__OP01_0202__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP01_0202__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__OP01_0202__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* defined(__MMI_OP01_WITH_WAP_KEY__)  */
/* under construction !*/
/* under construction !*/
#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
#if defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /* 0 */


#ifdef __MMI_BT_DIALER_SUPPORT__
static MMI_ID s_idleGrpId;
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_show_BT_dialer_popup_screen
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_BT_dialer_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s_idleGrpId = mmi_frm_group_get_active_id();
    mmi_bt_dialer_show_popup(s_idleGrpId);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_BT_disconnect_notify
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_idle_BT_dialer_disconnect(void)
{
    //mmi_bt_dialer_disconnect_notify(mmi_frm_group_get_active_id());
    s_idleGrpId = mmi_frm_group_get_active_id();
    if (srv_bt_cm_get_busy_dev() == NULL)
	{    
        mmi_bt_dialer_enter_disconnect_candidate_list(s_idleGrpId);
	}
	else
	{
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR*)GetString(STR_BT_SERVICE_UNAVAILABLE));
	}     
    
}


void mmi_idle_close_bt_ask_scr(void)
{
    if (MMI_TRUE == mmi_frm_scrn_is_present(s_idleGrpId, SCR_BT_DIALER_DISCONNECT_ASK, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(s_idleGrpId, SCR_BT_DIALER_DISCONNECT_ASK);
    }
}

#ifndef __MMI_BTD_BOX_UI_STYLE__
static void mmi_idle_set_right_soft_key_hdlr(void);
void mmi_idle_BT_dialer_update_RSK(void)
{
    mmi_idle_set_right_soft_key_hdlr();
}
#endif

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_right_soft_key_hdlr
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_right_soft_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    FuncPtr hdlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Get the handler and string.
     */
#if 0     
#if defined(__MMI_OP01_DCD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP01_DCD__) */
#if defined(__OP12__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP12__) */
#endif 

#ifdef __MMI_BT_DIALER_SUPPORT__
    {     
        if (GetIdleScreenBTDialerConnectionStatus())  
        {
            str_id = STR_ID_IDLE_BTDIALER_DISCONNECT;
            hdlr = mmi_idle_BT_dialer_disconnect;          
        }
        else
        {
            str_id = STR_ID_IDLE_BTDIALER_CONNECT;          
            hdlr   = mmi_idle_BT_dialer_connect;
        }
    }
#else
    {
        str_id = STR_ID_IDLE_CONTACT;
        hdlr   = mmi_phb_idle_launch;
    }
#endif

    /*
     * Set the handler and string.
     */
    mmi_idle_set_rsk_hdlr(hdlr);
    mmi_idle_set_rsk_view(str_id, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_center_soft_key_hdlr
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_center_soft_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = 0;
    FuncPtr hdlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Get the handler and string.
 	 * for FTE_KEY_ONLY, the UE of CSK is the same as LSK 
	*/
#if defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_MAINLCD_128X128__)
    img_id = IMG_GLOBAL_COMMON_CSK;     
    hdlr   = EntryMainMenuFromIdleScreen;    
#elif defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__)
	img_id = IMG_GLOBAL_COMMON_CSK;     
    hdlr   = EntryMainMenuFromIdleScreen;    
#elif defined(__MMI_MAINLCD_96X64__)
	img_id = IMG_GLOBAL_COMMON_CSK;    
#ifdef __MMI_DIALER_CUI_SUPPORT__
    hdlr   = mmi_dialer_launch;    
#endif
#else
	img_id = IMG_GLOBAL_DIAL_PAD_CSK;    
#ifdef __MMI_DIALER_CUI_SUPPORT__
    hdlr   = mmi_dialer_launch;    
#endif
#endif
    /*
     * Set the handler and string.
     */
    mmi_idle_set_csk_hdlr(hdlr);
#ifndef __MMI_WGUI_DISABLE_CSK__
    mmi_idle_set_csk_view(0, img_id);
#endif /*__MMI_WGUI_DISABLE_CSK__*/
}


#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_send_key_hdlr
 * DESCRIPTION
 *  This function sets the send key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__SENDKEY2_SUPPORT__)
    //SetKeyHandler(mmi_clog_sendkey_launch, KEY_SEND, KEY_EVENT_DOWN);
    SetKeyDownHandler(mmi_clog_sendkey_launch, KEY_SEND);
#else
    //SetKeyHandler(mmi_clog_sendkey_launch, KEY_SEND1, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_clog_sendkey_launch, KEY_SEND2, KEY_EVENT_DOWN);
    SetKeyDownHandler(mmi_clog_sendkey_launch, KEY_SEND1);
    SetKeyDownHandler(mmi_clog_sendkey_launch, KEY_SEND2);
#endif /* __SENDKEY2_SUPPORT__ */
}
#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */

extern void mmi_btdialer_launch_func(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_navigation_key_hdlr
 * DESCRIPTION
 *  This function sets the navigation key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_navigation_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0    
#if defined(__MMI_OP01_DCD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP01_DCD__) */
#endif

    {
    #ifdef __MMI_BT_DIALER_SUPPORT__
    #if !defined(__DISABLE_SHORTCUTS_MENU__)
        //SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyDownHandler(EntryShctInIdle, KEY_UP_ARROW);
    #endif
        //SetKeyHandler(mmi_phb_entry_main_menu, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        //SetKeyHandler(mmi_btdialer_launch_func, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        //SetKeyHandler(mmi_clndr_entry_main_menu, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyDownHandler(mmi_phb_entry_main_menu, KEY_DOWN_ARROW);
        SetKeyDownHandler(mmi_btdialer_launch_func, KEY_RIGHT_ARROW);
    #ifdef __MMI_CALENDAR__
        SetKeyDownHandler(mmi_clndr_entry_main_menu, KEY_LEFT_ARROW);
    #endif
	#else
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        RegisterDedicatedKeyHandlers();
    #else
    #if !defined(__DISABLE_SHORTCUTS_MENU__)
        //SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyDownHandler(EntryShctInIdle, KEY_UP_ARROW);
    #if (__MRE_AM__) && defined(__MMI_MRE_APP_OPERA_MINI__)
        //SetKeyHandler(mmi_idle_entry_mre_opera, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyDownHandler(mmi_idle_entry_mre_opera, KEY_RIGHT_ARROW);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        //SetKeyHandler(mmi_sim_space_launch, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyDownHandler(mmi_sim_space_launch, KEY_LEFT_ARROW);
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* !defined(__DISABLE_SHORTCUTS_MENU__) */
    #endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */

    // google search handler is the highest priority
    #if defined(__MMI_SEARCH_WEB__)
        if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY))
        {
            //SetKeyHandler(mmi_search_web_trigger_by_down_key, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyDownHandler(mmi_search_web_trigger_by_down_key, KEY_DOWN_ARROW);
        }
    #endif /* defined(__MMI_SEARCH_WEB__) */
	#endif /*__BT_DIALER_PACKAGE__*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_disable_lock_by_end_key
 * DESCRIPTION
 *  This function turns off the availability to lock the keypad by END key. When
 *  the unit testing is running using the tool, e.g., MSC composer, it sometimes
 *  needs to emit some END key events to make sure the handset is in the idle
 *  screen. If the "Lock keypad?" confirm screen is shown, the unit test case
 *  might fail since the handset is not in the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_disable_lock_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_KEY_SET(MMI_IDLE_KEY_FLAG_DISABLE_LOCK_BY_END);

    mmi_popup_display_simple(
        (WCHAR *)get_string(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        GRP_ID_ROOT,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_lock_keypad_confirm_evt_hdlr
 * DESCRIPTION
 *  This function handles the event of the lock keypad confirm screen.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_lock_keypad_confirm_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt);

    if (evt->evt_id == EVT_ID_ALERT_QUIT && evt->result == MMI_ALERT_CNFM_YES)
    {
        mmi_idle_display();
        mmi_scr_locker_launch();
    }

    return MMI_RET_OK;
}

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
#ifdef __MMI_DIALER_CUI_SUPPORT__
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dialer_by_translate_key
 * DESCRIPTION
 *  This function is the translate key handler if APP wants to launch dialer by
 *  the tranlate key.
 * PARAMETERS
 *  key_code                : [IN]      Key code
 *  key_type                : [IN]      Key type
 *  ucs2_value              : [IN]      UCS2 value
 *  key_flag                : [IN]      Key flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_idle_entry_dialer_by_translate_key(
    S16 key_code,
    S16 key_type,
    U16 ucs2_value,
    U32 key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip non-dialer key. */
    if ((!wgui_inputs_dialer_is_dialer_keys(key_code)) ||
        (key_type != KEY_EVENT_DOWN))
    {
        return MMI_FALSE; /* continue the key routing. */
    }

    /* set SSE effect */
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_IDLE);

	mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);

    /* Show the dial pad. */
    mmi_dialer_launch_by_translate_key(key_code, key_type, ucs2_value, key_flag);

    return MMI_TRUE; /* stop the key routing. */
}
#else /* defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dialer_by_key
 * DESCRIPTION
 *  This function is the digital key handler if APP wants to launch dialer by
 *  the digital key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_dialer_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);

	mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    /* set SSE effect */
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_IDLE);

    //mmi_dialer_launch_by_key(key_code);
    mmi_dialer_launch_by_key_ex(CUI_DIALER_TYPE_UNSPECIFIED, key_code);
}
#endif /* defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_dial_pad_hdlr
 * DESCRIPTION
 *  This function sets the dial pad handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_dial_pad_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    mmi_frm_set_app_translate_key_handler(mmi_idle_entry_dialer_by_translate_key);

    /*
     * On QWERTY phone, the DTMF tones are played when the user wants to dial
     * calls; otherwise, normal key tone is played, e.g. in the editor. Enable
     * the DTMF tone here.
     *
     * PS. Our non-QWERTY phone will always play DTMF tone no matter in the dial
     *     pad or editor.
     */
#else
    SetGroupKeyHandler(
        mmi_idle_entry_dialer_by_key,
        (PU16)PresentAllDialerKeys,
        TOTAL_DIALER_KEYS,
        KEY_EVENT_DOWN);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
}
#endif
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
#if defined(__MMI_VRSD__) || defined(__MMI_VRSI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_VRSD__)
/* under construction !*/
#elif defined(__MMI_VRSI__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VRSD__) || defined(__MMI_VRSI__) */
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_camera_hdlr
 * DESCRIPTION
 *  This function sets the camera key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined (__MMI_CAMERA__)
static void mmi_idle_set_camera_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    /*
     * Not support camcoder
     */
#if defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__)
    //SetKeyHandler(mmi_idle_entry_camera_ex, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_idle_entry_camera_ex, CAMERA_SHORTCUT_KEY);
#else
    //SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
    SetKeyDownHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY);
#endif /* defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__) */
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
    /*
     * Support camcoder
     */
#if defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__)
    //SetKeyHandler(mmi_idle_entry_camera_ex, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_idle_entry_camera_ex, CAMERA_SHORTCUT_KEY);
#else
    //SetKeyHandler(mmi_camco_launch, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyDownHandler(mmi_camco_launch, KEY_CAMERA);
#endif /* defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__) */
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
}
#endif/*defined (__MMI_CAMERA__)*/

#if 0
#if defined(__MMI_OP01_DCD__) || defined(__MMI_OP01_WITH_WAP_KEY__) || defined(__MMI_OP02_WITH_WAP_KEY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*defined(__MMI_OP01_DCD__) || defined(__MMI_OP01_WITH_WAP_KEY__) || defined(__MMI_OP02_WITH_WAP_KEY__)*/
#endif /*0*/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_browser_hdlr
 * DESCRIPTION
 *  This function sets up the wap key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_wap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#if defined(__MMI_OP01_DCD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_OP01_WITH_WAP_KEY__)
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP01_DCD__) */
/* under construction !*/
    #if defined(__MMI_OP01_WITH_WAP_KEY__)
        #if defined(__OP01_3G__) && defined(__MMI_REDUCED_KEYPAD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else /* defined(__OP01_3G__) && defined(__MMI_REDUCED_KEYPAD__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__OP01_3G__) && defined(__MMI_REDUCED_KEYPAD__) */
    #elif defined(__MMI_OP02_WITH_WAP_KEY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #elif defined(BROWSER_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
/* under construction !*/
    #endif
/* under construction !*/
#else /*0*/
    #if defined(BROWSER_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
        //SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_LONG_PRESS);
        SetKeyLongpressHandler(wap_internet_key_hdlr, KEY_WAP);
    #endif
#endif /* 0 */

}

#if 0
#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__OP01_FWPCOLOR__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_FM_RADIO__
/* under construction !*/
    #endif
#endif
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_handler
 * DESCRIPTION
 *  This function sets the default handler according to the capability of the
 *  idle object.
 * PARAMETERS
 *  obj           : [IN]        Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_handler(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 capability; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    capability = obj->capability;
   
#ifdef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__
    if (capability & ENABLE_LEFT_SOFT_KEY)
    {
        if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
        {
            //SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyDownHandler(EntryMainMenuFromIdleScreen, KEY_LSK);            
        }
        else
        {
            SetLeftSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_ID_IDLE_MAIN_MENU, 0);
        }
    }
#endif /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/

#ifndef __MMI_BTD_BOX_UI_STYLE__
    if (capability & ENABLE_RIGHT_SOFT_KEY)
    {
        mmi_idle_set_right_soft_key_hdlr();
    }
#else
  SetKeyHandler(mmi_scr_locker_launch, KEY_RSK, KEY_EVENT_UP);
#endif
    if (capability & ENABLE_CENTER_SOFT_KEY)
    {
        mmi_idle_set_center_soft_key_hdlr();
    }
#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
    if (capability & ENABLE_SEND_KEY)
    {
        mmi_idle_set_send_key_hdlr();
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */
    if (capability & ENABLE_NAVIGATION_KEY)
    {
        mmi_idle_set_navigation_key_hdlr();
    }

#ifndef __MMI_BTD_BOX_UI_STYLE__
    if (capability & ENABLE_END_KEY)
    {
        //SetKeyHandler(mmi_idle_entry_lock_keypad_confirm, KEY_END, KEY_EVENT_UP);
        //SetKeyHandler(mmi_scr_locker_launch, KEY_END, KEY_EVENT_UP);
        SetKeyUpHandler(mmi_scr_locker_launch, KEY_END);
    }
#endif
#ifdef __MMI_DIALER_CUI_SUPPORT__
    if (capability & ENABLE_DIALER)
    {
        mmi_idle_set_dial_pad_hdlr();
    }
#endif
    if (capability & ENABLE_VOLUME_CONTROL)
    {
        SetDefaultVolumeKeyHandlers();
    }
#if 0
#if defined(__MMI_VRSD__) || defined(__MMI_VRSI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if defined (__MMI_CAMERA__)
    if (capability & ENABLE_CAMERA)
    {
        mmi_idle_set_camera_hdlr();
    }
#endif

    if (capability & ENABLE_WAP)
    {
        mmi_idle_set_wap_hdlr();
    }

#if defined(__MMI_MAPBAR_GIS__)
    if (capability & ENABLE_GIS)
    {
        //SetKeyHandler(mmi_gis_enter_app_check_conform, KEY_EXTRA_2, KEY_EVENT_UP);   
        SetKeyUpHandler(mmi_gis_enter_app_check_conform, KEY_EXTRA_2);
    }
#endif

#if defined(__MMI_ATV_SUPPORT__)
    if (capability & ENABLE_MTV)
    {        
        //SetKeyHandler(mmi_mtv_player_launch, KEY_EXTRA_1, KEY_EVENT_DOWN);    
        SetKeyDownHandler(mmi_mtv_player_launch, KEY_EXTRA_1);
    }
#endif

#if 0
#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
}





#if defined(__HOMEZONE_SUPPORT__ )
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_homezone_string
 * DESCRIPTION
 *  This function prepares the service string in the homezone situation.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  In homezone, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_idle_get_homezone_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_homezone_info_struct homezone;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_nw_info_get_homezone_info(sim, &homezone);
    if (!ret || !homezone.is_in_homezone)
    {
        return MMI_FALSE; /* It's not in home zone. */
    }

    mmi_wcsncpy(service_indication->line2, homezone.tag, MMI_IDLE_NW_NAME_MAX_STR_LEN);

    return MMI_TRUE;
}
#endif /* defined(__HOMEZONE_SUPPORT__ ) */

#if 0
#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP12__) && defined(__NBR_CELL_INFO__) */
#endif /*0*/


#if defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_msisdn_type
 * DESCRIPTION
 *  This function gets the MSISDN type.
 * PARAMETERS
 *  sim             : [IN]              SIM id
 * RETURNS
 *  srv_cphs_msisdn_type_enum
 *****************************************************************************/
static srv_cphs_msisdn_type_enum mmi_idle_get_msisdn_type(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_line_id_enum line_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line_id = srv_callset_line_switch_get_id(sim);

    return line_id == SRV_CALLSET_LINE2 ?
           SRV_CPHS_MSISDN_TYPE_LINE2 : SRV_CPHS_MSISDN_TYPE_LINE1;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_owner_number_string
 * DESCRIPTION
 *  This function gets the owner number string.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  On available, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_idle_get_owner_number_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cphs_msisdn_type_enum msisdn_type;
    const WCHAR *string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phnset_show_owner_number_is_on(sim) &&
        srv_sim_ctrl_is_available(sim))
    {
        /*
         * Priority: owner name > owner number.
         */
        msisdn_type = mmi_idle_get_msisdn_type(sim);

        string = srv_cphs_get_msisdn_name(msisdn_type, sim);
        if (!string || !mmi_wcslen(string))
        {
            string = srv_cphs_get_msisdn_number(msisdn_type, sim);
        }

        if (string && mmi_wcslen(string))
        {
            mmi_wcsncpy(service_indication->line2, string, SRV_NW_NAME_MAX_STR_LEN);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}
#endif /* defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_extra_indication_for_line2_string
 * DESCRIPTION
 *  This function gets the extra infomation string instead of spn for specific UE.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_extra_indication_for_line2_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
 /*----------------------------------------------------------------*/
 /* Local Variables                                                */
 /*----------------------------------------------------------------*/

 /*----------------------------------------------------------------*/
 /* Code Body                                                      */
 /*----------------------------------------------------------------*/

    /*
      * Override 2nd line if there is other information required.
      */
#if 0
#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP12__) */
#endif

#if defined(__HOMEZONE_SUPPORT__ )
     if (mmi_idle_get_homezone_string(sim,service_indication))
     {
         return;
     }
#endif /* defined(__HOMEZONE_SUPPORT__ ) */

#if defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__)
     if (mmi_idle_get_owner_number_string(sim,service_indication))
     {
         return;
     }
#endif /* defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__) */
}


#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_service_indication_string
 * DESCRIPTION
 *  This function gets the service indication string of the specified SIM in the idle.
 *  include special info , like homezone, cell info, owner number
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS

 *  void
 *****************************************************************************/
void mmi_idle_get_service_indication_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_service_indication_struct tmp_indication;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_nw_name_get_service_indication_string(sim, &tmp_indication);

    mmi_wcsncpy(service_indication->line1, tmp_indication.line1, MMI_IDLE_NW_NAME_MAX_STR_LEN);
    mmi_wcsncpy(service_indication->line2, tmp_indication.line2, MMI_IDLE_NW_NAME_MAX_STR_LEN);

    /*
     * Override 2nd line if there is other information required.
     */
    mmi_idle_get_extra_indication_for_line2_string(sim, service_indication);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_service_indication_context
 * DESCRIPTION
 *  This function updates service indication of idle context
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_service_indication_context(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_service_indication_struct *service_indication;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        service_indication = mmi_idle_get_service_indication_context(obj, mmi_frm_index_to_sim(i));
        mmi_idle_get_service_indication_string(mmi_frm_index_to_sim(i), service_indication);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_service_indication_context
 * DESCRIPTION
 *  This function gets the context of the service string.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  sim                 : [IN]              SIM ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_idle_service_indication_struct *mmi_idle_get_service_indication_context(
    mmi_idle_obj_struct *obj,
    mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(obj->service_indication[mmi_frm_sim_to_index(sim)]);
}

