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
 * MultiPurposeStopwatch.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for phone setup application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Stopwatch Application implementation *********************/

/**************************************************************

   FILENAME : MultiPurposeStopwatch.c

   PURPOSE     : Multi Purpose Stopwatch application implementation

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 05/01/2004

**************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_STOPWATCH__
#ifndef __MMI_FTE_SUPPORT__

/***********  Include: MMI header file **************/
//#include "ProtocolEvents.h"
//#include "HardwareEvents.h"
//#include "CommonScreens.h"
//#include "MainMenuDef.h"
//#include "ProfileGprots.h"

#include "mmi_rp_app_stopwatch_def.h"
//#include "StopwatchGprot.h"
#include "StopwatchProt.h"

#include "wgui_categories_stopwatch.h"
#include "MMIDataType.h"
#include "wgui_categories_multimedia.h"
#include "GlobalConstants.h"
#include "string.h"
#include "CustDataRes.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "CustMenuRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_input_gprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable (Local to this file - static)
*****************************************************************************/

/***************************************************************************** 
* Local Function (local to this file - static)
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/
UI_stop_watch gLastMPTimeRecord;
UI_stop_watch gMultiPurposeTimerList[MAX_MULTIPURPOSE_TIMER];
nWayTimerStruct gMPTimerInit;
U8 isfrommul;   /* change from nWay to Typical directly */
void ResetAllTimerKey(void);
void StopCurrentTimer(void);
void StartKeyTimer(void);
void StopCurrentTimer(void);
void SetLSKMultiPurposeTimerResumeLongPress(void);

#ifdef __MMI_MAINLCD_320X480__
    static void ResetUpCallback(void);
    static void TypUpCallback(void);
    void StartUpCallback(void);
    static wgui_panel_area_struct panel_area_data_stopwatch;
    static  wgui_panel_element_struct list[3]=
    {
        {-1,-1,-1,-1,KEY_1,NULL, ResetUpCallback, NULL, 0, IMG_TYPICAL_RESET_UP, IMG_TYPICAL_RESET_UP, IMG_TYPICAL_RESET_DOWN,1},
        {-1,-1,-1,-1,KEY_2,NULL, StartUpCallback, NULL, 0, IMG_TYPICAL_START_UP, IMG_TYPICAL_START_UP, IMG_TYPICAL_START_DOWN,1},
        {-1,-1,-1,-1,KEY_3,NULL, TypUpCallback, NULL, 0, IMG_TYPICAL_NWAY_UP, IMG_TYPICAL_NWAY_UP, IMG_TYPICAL_NWAY_DOWN,1},
    };
#endif

/**********************************************************************
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  InitMultipurposeStopwatch
 * DESCRIPTION
 *  Init fn for Multipurpose stop watch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitMultipurposeStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&gLastMPTimeRecord, 0, sizeof(UI_stop_watch));
    memset(gMultiPurposeTimerList, 0, sizeof(UI_stop_watch) * MAX_MULTIPURPOSE_TIMER);
    for (index = 0; index < MAX_MULTIPURPOSE_TIMER; index++)
    {
        gMultiPurposeTimerList[index].normalimagedata = GetImage((U16) (IMG_MULTIPURPOSE_TIMER1 + index));
        gMultiPurposeTimerList[index].highlightimagedata = GetImage((U16) (IMG_MULTIPURPOSE_TIMER1 + index));
    }

    gMPTimerInit.assignedKey[0] = KEY_LEFT_ARROW;
    gMPTimerInit.timerIndex[0] = 0;

    gMPTimerInit.assignedKey[1] = KEY_UP_ARROW;
    gMPTimerInit.timerIndex[1] = 1;

    gMPTimerInit.assignedKey[2] = KEY_RIGHT_ARROW;
    gMPTimerInit.timerIndex[2] = 2;

    gMPTimerInit.assignedKey[3] = KEY_DOWN_ARROW;
    gMPTimerInit.timerIndex[3] = 3;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_multi_purpose_exit
 * DESCRIPTION
 *  Exit fn for Multipurpose Stopwatch screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_multi_purpose_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetMultipurposeTimeValues( /* &gLastMPTimeRecord,gMultiPurposeTimerList, */ &gStopwatchAppInfo.currentHiliteTimer);

    if (gStopwatchAppInfo.MPTimerState == TIMER_RUNNING || gStopwatchAppInfo.TimerState == TIMER_RUNNING)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_STOP_WATCH);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_STOP_WATCH);
    }
    wgui_status_icon_bar_update();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_multi_purpose_entry
 * DESCRIPTION
 *  Entry fn for Multipurpose stop watch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_multi_purpose_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[15];   /* Stores the strings id of submenus returned */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    //EntryNewScreen(SCR_MULTIPURPOSE_STOPWATCH, mmi_stopwatch_multi_purpose_exit, mmi_stopwatch_multi_purpose_entry,NULL);
    if (mmi_frm_scrn_enter(GRP_ID_STOPWATCH, SCR_MULTIPURPOSE_STOPWATCH, mmi_stopwatch_multi_purpose_exit, mmi_stopwatch_multi_purpose_entry, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    GetDispAttributeOfItem(MENU_MULTIPURPOSEWATCH);
    GetSequenceStringIds(MENU_MULTIPURPOSEWATCH, nStrItemList);
    SetParentHandler(MENU_MULTIPURPOSEWATCH);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

 #ifndef __MMI_MAINLCD_320X480__
    if (gStopwatchAppInfo.MPTimerState == TIMER_NOT_STARTED)
    {
        ShowCategory306Screen(
            &gLastMPTimeRecord,
            STR_GLOBAL_START,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gMultiPurposeTimerList,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);

        SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    }
    else if (gStopwatchAppInfo.MPTimerState == TIMER_STOPPED)
    {
        ShowCategory306Screen(
            &gLastMPTimeRecord,
            STR_GLOBAL_CONTINUE,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gMultiPurposeTimerList,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
		ChangeRightSoftkey(STR_GLOBAL_RESET, 0);
        SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
		SetRightSoftkeyFunction(ResetAllTimerKey,KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory306Screen(
            &gLastMPTimeRecord,
            STR_GLOBAL_PAUSE,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gMultiPurposeTimerList,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
        SetLeftSoftkeyFunction(StopCurrentTimer, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(0, KEY_LONG_PRESS);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(StopCurrentTimer, KEY_EVENT_UP);
    }
#else
	if (gStopwatchAppInfo.MPTimerState == TIMER_NOT_STARTED)
    {
        panel_area_data_stopwatch.element_list = list;
     	panel_area_data_stopwatch.focused_element = 0;
		panel_area_data_stopwatch.num_of_element = 3;
		panel_area_data_stopwatch.panel_bg_img_id = 0;
		panel_area_data_stopwatch.repeat_period = 0;
        ShowCategory306PanelScreen(
            &gLastMPTimeRecord,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gMultiPurposeTimerList,
            &panel_area_data_stopwatch,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, 0);
        SetCenterSoftkeyFunction(0, KEY_EVENT_UP);
    }
    else if (gStopwatchAppInfo.MPTimerState == TIMER_STOPPED)
    {
        ShowCategory306PanelScreen(
            &gLastMPTimeRecord,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gMultiPurposeTimerList,
            &panel_area_data_stopwatch,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
	    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);

        ChangeCenterSoftkey(0, 0);
        SetCenterSoftkeyFunction(0, KEY_EVENT_UP);
    }
    else
    {  
        ShowCategory306PanelScreen(
            &gLastMPTimeRecord,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gMultiPurposeTimerList,
            &panel_area_data_stopwatch,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
        SetLeftSoftkeyFunction(0, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, 0);
        SetCenterSoftkeyFunction(0, KEY_EVENT_UP);
    }
#endif

    /* Robin 0728 */
    /* If using EVENT_UP as action key event, when pressing left key entering the nWay Stopwatch at the previous menu */
    /* The key up event will trigger the related stopwatch start */
    SetGroupKeyHandler(StartKeyTimer, gMPTimerInit.assignedKey, MAX_MULTIPURPOSE_TIMER, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  StartUpCallback
 * DESCRIPTION
 *  callback function start key up event 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartUpCallback(void)
{
    if (gStopwatchAppInfo.MPTimerState == TIMER_NOT_STARTED)
    {
        StartIndexTimer();
    }
    else if (gStopwatchAppInfo.MPTimerState == TIMER_STOPPED)
    {
        StartIndexTimer();
    }
    else
    {
        StopCurrentTimer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetKeyUpCallback
 * DESCRIPTION
 *  callback function start key up event 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetUpCallback(void)
{
    ResetAllTimerKey();
}


/*****************************************************************************
 * FUNCTION
 *  TypUpCallback
 * DESCRIPTION
 *  callback function start key up event 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void TypUpCallback(void)
{
    isfrommul = 1;
    mmi_stopwatch_typical_entry();
}


/*****************************************************************************
 * FUNCTION
 *  StartKeyTimer
 * DESCRIPTION
 *  Start timer associated with any Key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartKeyTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);

    for (count = 0; count < MAX_MULTIPURPOSE_TIMER; count++)
    {
        if (keycode == gMPTimerInit.assignedKey[count])
        {
            gStopwatchAppInfo.currentTimerIndex = gMPTimerInit.timerIndex[count];
            StartIndexTimer();
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  StopCurrentTimer
 * DESCRIPTION
 *  Stop Currently active timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopCurrentTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_320X480__
    ChangeLeftSoftkey(STR_GLOBAL_CONTINUE, 0);
    SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    
	ChangeRightSoftkey(STR_GLOBAL_RESET, 0);
    SetRightSoftkeyFunction(ResetAllTimerKey,KEY_EVENT_UP);
#else
    list[1].off_imageid = IMG_TYPICAL_CON_UP;
    list[1].on_imageid = IMG_TYPICAL_CON_UP;
    list[1].down_imageid = IMG_TYPICAL_CON_DOWN;
    wgui_catsw_update_panel(&panel_area_data_stopwatch);
#endif
    stop_multipurpose_timers();

    gStopwatchAppInfo.MPTimerState = TIMER_STOPPED;
}


/*****************************************************************************
 * FUNCTION
 *  ResetAllTimer
 * DESCRIPTION
 *  Reset All Timer when Resume is long
 *  pressed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetAllTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_START, 0);
    SetLeftSoftkeyFunction(SetLSKMultiPurposeTimerResumeLongPress, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(SetLSKMultiPurposeTimerResumeLongPress, KEY_EVENT_UP);

    reset_all_multipurpose_time();
    
    gStopwatchAppInfo.currentTimerIndex = 0;
    gStopwatchAppInfo.currentHiliteTimer = 0;
    gStopwatchAppInfo.MPTimerState = TIMER_NOT_STARTED;
}


/*****************************************************************************
 * FUNCTION
 *  ResetAllTimerKey
 * DESCRIPTION
 *  Reset All Timer when Resume is long
 *  pressed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetAllTimerKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_320X480__
    ChangeLeftSoftkey(STR_GLOBAL_START, 0);
    SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
#else
    if(gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
    {
    	list[1].off_imageid = IMG_TYPICAL_CON_UP;
        list[1].on_imageid = IMG_TYPICAL_CON_UP;
    	list[1].down_imageid = IMG_TYPICAL_CON_DOWN;
		wgui_catsw_update_panel(&panel_area_data_stopwatch);
    }
	 
    ChangeLeftSoftkey(0, 0);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, 0);
    SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
#endif

    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    reset_all_multipurpose_time();
    gStopwatchAppInfo.currentTimerIndex = 0;
    gStopwatchAppInfo.currentHiliteTimer = 0;
    gStopwatchAppInfo.MPTimerState = TIMER_NOT_STARTED;
}

/*****************************************************************************
 * FUNCTION
 *  SetLSKMultiPurposeTimerResumeLongPress
 * DESCRIPTION
 *  Set LSK handler fn when Resume is long
 *  pressed to reset the Multipurpose timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetLSKMultiPurposeTimerResumeLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.currentTimerIndex = 0;
    SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  StartIndexTimer
 * DESCRIPTION
 *  Call back fn to start Timer set in gCurrentTimerIndex.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartIndexTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_320X480__
    ChangeLeftSoftkey(STR_GLOBAL_PAUSE, 0);
    SetLeftSoftkeyFunction(StopCurrentTimer, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(StopCurrentTimer, KEY_EVENT_UP);
	ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#else
    list[1].off_imageid = IMG_TYPICAL_STOP_UP;
    list[1].on_imageid = IMG_TYPICAL_STOP_UP;
    list[1].down_imageid = IMG_TYPICAL_STOP_DOWN;
    wgui_catsw_update_panel(&panel_area_data_stopwatch);
#endif
    gStopwatchAppInfo.MPTimerState = TIMER_RUNNING;
    start_multipurpose_list_watch(gStopwatchAppInfo.currentTimerIndex);
}

#else /* __MMI_FTE_SUPPORT__ */
    /* in FTE mode, StartIndexTimer is undefined, but wgui_categories_stopwatch will use this function. */
    void StartIndexTimer(void){}
#endif

#endif /* __MMI_STOPWATCH__ */ 

