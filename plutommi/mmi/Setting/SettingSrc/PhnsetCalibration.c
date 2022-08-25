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
 *  PhnsetCalibration.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phone setup calibration 
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
/*  Include: MMI header file */
#include "PhoneSetup.h"
#include "PhoneSetupGprots.h"
#include "GpioSrvGprot.h"
#include "Mmi_frm_input_gprot.h"
#include "mmi_rp_app_calibration_def.h"
#include "PenCalibrationSrvGprot.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_popup.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CommonScreensResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "wgui.h"
/* auto add by kw_check end */


#ifdef __MMI_TOUCH_SCREEN__

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef
*****************************************************************************/
/* Current state of calibration screen */
typedef struct
{
    PHNSET_CALIBRATION_STATE_ENUM state;
    /* Flag to check whether calibration has finished or not */
    BOOL finished;
    /* Sasve to factory default or user calibration data */
    BOOL save_to_factory_default;
    /* Finish callback */
    void (*finish_callback) (void);
} mmi_phnset_calibration_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static mmi_phnset_calibration_struct g_phnset_calibration_cntx;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern PHNSET_CNTX *g_phnset_cntx_p;

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/

/*****************************************************************************
* Local Function 
*****************************************************************************/
static void EntryCalibrationSettingScr(void);
static void ExitCalibrationSettingScr(void);
static void mmi_phnset_entry_calibration_scrn(mmi_scrn_essential_struct *scrn_data);
static mmi_ret mmi_phnset_calibration_proc(mmi_event_struct *param);
#ifdef __MTK_TARGET__
static void PhnsetCalibrationDriverRsp(MMI_BOOL result);
#endif
/*****************************************************************************
 * FUNCTION
 *  HighlightCalibrationSetting
 * DESCRIPTION
 *  This function is highlight handler for Calibration setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCalibrationSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryCalibrationSettingScr, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(EntryCalibrationSettingScr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  CalibrationSettingPenDown
 * DESCRIPTION
 *  PenDown Handler for Calibration Setting Screen
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void CalibrationSettingPenDown(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__	/* Emulate driver's response */
    mmi_popup_property_struct popup_arg;
#endif
    mmi_pen_point_struct *calibrate_point;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_phnset_calibration_cntx.state)
    {
        case CALIBRATION_WELCOME_STATE:
            g_phnset_calibration_cntx.state = CALIBRATION_TOP_LEFT_POINT_STATE;
            calibrate_point = srv_setting_pen_calibration_get_point(0);
            UpdateCalibrationScreen(
                IMG_CALIBRATION_TOP_LEFT,
                calibrate_point->x,
                calibrate_point->y,
                STR_CALIBRATION_TOP_LEFT_TEXT,
                CALIBRATION_TOP_LEFT_POINT_STATE,
                MMI_TRUE);
            srv_setting_pen_calibration_start(mmi_phnset_calibration_proc, NULL);
            break;

        case CALIBRATION_TOP_LEFT_POINT_STATE:
            g_phnset_calibration_cntx.state = CALIBRATION_BOTTOM_RIGHT_POINT_STATE;
            calibrate_point = srv_setting_pen_calibration_get_point(1);
            UpdateCalibrationScreen(
                IMG_CALIBRAION_BOTTOM_RIGHT,
                calibrate_point->x,
                calibrate_point->y,
                STR_CALIBRATION_BOTTOM_RIGHT_TEXT,
                CALIBRATION_BOTTOM_RIGHT_POINT_STATE,
                MMI_TRUE);
            break;

        case CALIBRATION_BOTTOM_RIGHT_POINT_STATE:
            g_phnset_calibration_cntx.state = CALIBRATION_CENTER_POINT_STATE;
            calibrate_point = srv_setting_pen_calibration_get_point(2);
            UpdateCalibrationScreen(
                IMG_CALIBRATION_CENTER,
                calibrate_point->x,
                calibrate_point->y,
                STR_CALIBRATION_CENTER_TEXT,
                CALIBRATION_CENTER_POINT_STATE,
                MMI_TRUE);
            break;

        case CALIBRATION_CENTER_POINT_STATE:
    #ifndef __MTK_TARGET__  /* Emulate driver's response */
        {
            g_phnset_calibration_cntx.finished = MMI_TRUE;
            
            srv_setting_pen_calibration_update_data_in_modis();
            
            mmi_popup_property_init(&popup_arg);
            popup_arg.callback = NULL;
            popup_arg.parent_id = GRP_ID_PHNSET_CALIBRATION;
            mmi_popup_display_ext(
                STR_GLOBAL_DONE,
                    MMI_EVENT_SUCCESS, 
                &popup_arg);
            }
    #endif /* __MTK_TARGET__ */ 
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_calibration_done_callback
 * DESCRIPTION
 *  Call the callback function if it is set 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static mmi_ret mmi_phnset_calibration_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
	{
	case EVT_ID_GROUP_DEINIT:
	case EVT_ID_GROUP_DELETE_REQ:
	case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:        
  		ExitCalibrationSettingScr();
		break;
        
    case EVT_ID_ALERT_QUIT:
	{
        mmi_frm_scrn_close(GRP_ID_PHNSET_CALIBRATION, SCR_CALIBRATION_SETTING);
        if (g_phnset_calibration_cntx.finish_callback)
        {
            g_phnset_calibration_cntx.finish_callback();
        }
        break;
	}
#ifdef __MTK_TARGET__    
    case EVT_ID_SRV_PEN_CALIBRATION_DONE:
    {
        srv_setting_pen_calibration_event_struct *calibration_evt = (srv_setting_pen_calibration_event_struct*)param;
        PhnsetCalibrationDriverRsp(calibration_evt->result);
    }
#endif /* __MTK_TARGET__ */    
    default:
        break;
	}
	return MMI_RET_OK;
}

 
 


/*****************************************************************************
 * FUNCTION
 *  PhnsetCalibrationDriverRsp
 * DESCRIPTION
 *  Protocol event handler of driver response
 * PARAMETERS
 *  msg     [IN]        Local parameter
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MTK_TARGET__
static void PhnsetCalibrationDriverRsp(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_CALIBRATION_SETTING)
    {
        /* Race condition that screen is changed. */
        return;
    }
    if (result)
    {

        g_phnset_calibration_cntx.finished = MMI_TRUE;

        /* Write calibration data in NVRAM */

        mmi_popup_property_init(&popup_arg);
        popup_arg.callback = NULL;
        popup_arg.parent_id = GRP_ID_PHNSET_CALIBRATION;
        mmi_popup_display_ext(
             STR_GLOBAL_DONE,
             MMI_EVENT_SUCCESS, 
            &popup_arg);
    }
    else
    {
        /* Restart calibration process */
        mmi_pen_point_struct *point = srv_setting_pen_calibration_get_point(0);
        
        g_phnset_calibration_cntx.state = CALIBRATION_TOP_LEFT_POINT_STATE;
        UpdateCalibrationScreen(
            IMG_CALIBRATION_TOP_LEFT,
            point->x,
            point->y,
            STR_CALIBRATION_TOP_LEFT_TEXT,
            CALIBRATION_TOP_LEFT_POINT_STATE,
            MMI_TRUE);

        srv_setting_pen_calibration_restart(mmi_phnset_calibration_proc, NULL);
    }
}
#endif /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryCalibrationSettingScr
 * DESCRIPTION
 *  Entry function for Calibration Setting Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryCalibrationSettingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_CALIBRATION) || !srv_setting_pen_calibration_pre_start())
	{
	    mmi_popup_display_simple_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}

    //parent_id = GRP_ID_ROOT;


    mmi_frm_group_create_ex(
        GRP_ID_ROOT,//parent_id,
        GRP_ID_PHNSET_CALIBRATION,
        mmi_phnset_calibration_proc,
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_PHNSET_CALIBRATION,
        SCR_CALIBRATION_SETTING,
        (FuncPtr)mmi_phnset_entry_calibration_scrn,
        NULL);
}        


/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_entry_calibration_scrn
 * DESCRIPTION
 *  Entry pen calibration screen 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_phnset_entry_calibration_scrn(mmi_scrn_essential_struct *scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
        GRP_ID_PHNSET_CALIBRATION,
        SCR_CALIBRATION_SETTING,
        NULL,
        (FuncPtr)mmi_phnset_entry_calibration_scrn,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    /*EntryNewScreen(SCR_CALIBRATION_SETTING, ExitCalibrationSettingScr, NULL, NULL);*/

    g_phnset_calibration_cntx.finished = MMI_FALSE;
    g_phnset_calibration_cntx.save_to_factory_default = MMI_FALSE;
    g_phnset_calibration_cntx.finish_callback = NULL;
    /* 1 Show Calibration Welcome screen */
    g_phnset_calibration_cntx.state = CALIBRATION_WELCOME_STATE;

    ShowCalibrationScreen(0, 0, 0, STR_CALIBRATION_WELCOME_TEXT, CALIBRATION_WELCOME_STATE);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* 2. Register Pen Handlers 
       Because hardware can not get correct ADC value on PenUp, we use PenDown for calibration. */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_pen_register_up_handler(mmi_pen_dummy_hdlr);
    mmi_pen_register_down_handler(CalibrationSettingPenDown);
    mmi_pen_register_move_handler(mmi_pen_dummy_hdlr);
    mmi_pen_register_abort_handler(mmi_pen_dummy_hdlr);
    mmi_pen_register_repeat_handler(mmi_pen_dummy_hdlr);
    mmi_pen_register_long_tap_handler(mmi_pen_dummy_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPhnseFactoryDefaultCalibrationScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPhnseFactoryDefaultCalibrationScr(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryCalibrationSettingScr();
    /* Cannot quit when it is entered at boot up */
    SetKeyHandler(MMI_dummy_function, KEY_END, KEY_EVENT_DOWN);
    /* Update the default data because it is the first calibration */
    srv_setting_pen_calibration_update_default_data();
    g_phnset_calibration_cntx.save_to_factory_default = MMI_TRUE;
    g_phnset_calibration_cntx.finish_callback = callback;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCalibrationSettingScr
 * DESCRIPTION
 *  Exit function for Calibration Setting Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCalibrationSettingScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_phnset_calibration_cntx.finished)
    {
        /* Restore calibration previously set */
        srv_setting_pen_calibration_cancel_calibration();
    }

    g_phnset_calibration_cntx.state = CALIBRATION_NULL_STATE;
    g_phnset_calibration_cntx.finished = MMI_FALSE;
    g_phnset_calibration_cntx.save_to_factory_default = MMI_FALSE;
    g_phnset_calibration_cntx.finish_callback= NULL;    
    srv_backlight_turn_off();
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetNeedFactoryDefaultCalibration
 * DESCRIPTION
 *  Whether pen is calibrated.
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL PhnsetNeedFactoryDefaultCalibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)srv_setting_pen_calibration_is_calibration_needed();
}

void PhnsetReadNvramCalibrationData(void)
{
    srv_setting_pen_calibration_init_data();
}
#endif /* __MMI_TOUCH_SCREEN__ */
