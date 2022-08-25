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
 * TypicalStopwatch.c
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

   FILENAME : TypicalStopwatch.c

   PURPOSE     : Typical Stopwatch application implementation

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 05/01/2004

**************************************************************/
#include "MMI_features.h"
//#include "MMI_include.h"
#ifdef __MMI_STOPWATCH__

//#include "ProtocolEvents.h"
//#include "HardwareEvents.h"
#include "CommonScreens.h"
//#include "MainMenuDef.h"
//#include "ProfileGprots.h"

#include "Menucuigprot.h"
#include "Fseditorcuigprot.h"
#include "mmi_rp_app_stopwatch_def.h"
//#include "StopwatchGprot.h"
#include "StopwatchProt.h"

#include "wgui_categories_util.h"


#include "wgui_categories_multimedia.h"
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "wgui_categories_stopwatch.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "CustMenuRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CustDataRes.h"
#include "gui_typedef.h"
#include "wgui_touch_screen.h"
#include "wgui_categories.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "AlertScreen.h"
#include "ImeGprot.h"
#include "Unicodexdcl.h"
#include "gui_data_types.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#if (!defined(NVRAM_EF_STOPWATCH_RECORD_SIZE))
#define NVRAM_EF_STOPWATCH_RECORD_SIZE sizeof(gTimerRecordList)
#endif 

#ifdef __MMI_FTE_SUPPORT__
#define MMI_STOPWATCH_FTE_TB_ITEM_CNT   2
#endif

/***************************************************************************** 
* Global Function
*****************************************************************************/
#if !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
    void ResetKeyUpCallback(void);
    void StartKeyUpCallback(void);
    void NwayKeyUpCallback(void);
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/


/***************************************************************************** 
* Local Variable (Local to this file - static)
*****************************************************************************/
#if !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
    static wgui_panel_area_struct panel_area_data_stopwatch;
    static  wgui_panel_element_struct list[3]=
    {
        {-1,-1,-1,-1,KEY_1,NULL, ResetKeyUpCallback, NULL, 0, IMG_TYPICAL_RESET_UP, IMG_TYPICAL_RESET_UP, IMG_TYPICAL_RESET_DOWN,1},
        {-1,-1,-1,-1,KEY_2,NULL, StartKeyUpCallback, NULL, 0, IMG_TYPICAL_START_UP, IMG_TYPICAL_START_UP, IMG_TYPICAL_START_DOWN,1},
        {-1,-1,-1,-1,KEY_3,NULL, NwayKeyUpCallback, NULL, 0, IMG_TYPICAL_NWAY_UP, IMG_TYPICAL_NWAY_UP, IMG_TYPICAL_NWAY_DOWN,1}
    };
#endif

static S32 selcitemforStopwatch;
static U8 isfromstopwatch;


/***************************************************************************** 
* Local Function (local to this file - static)
*****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
void mmi_stopwatch_fte_item_callback_start_reset(S32 index);
void mmi_stopwatch_fte_item_callback_stop_split(S32 index);
void mmi_stopwatch_fte_option_split(void);
void mmi_stopwatch_fte_option_lap(void);
#endif
void ResetTypicalStopwatch(void);
void mmi_stopwatch_main_entry_init(void);
void mmi_stopwatch_split_lap_timing_entry(void);
void mmi_stopwatch_split_lap_timing_exit(void);
void StartSplitLapTimer(void);
mmi_ret mmi_stopwatch_proc(mmi_event_struct *evt);
void mmi_stopwatch_timing_option_entry(void);
void ConfirmSaveTimerRecord(void);
void StopSplitLapTimer(void);
void RecordSplitLapTime(void);
void ResumeSplitLapTimer(void);
void ResetSplitLapTimer(void);
void mmi_stopwatch_enter_record_name_entry(void);
void EntryWtchScrMemoryFull(void);
void GoBackToStopwatchMenu(void);
void SaveTimerRecord(void);
void mmi_stopwatch_view_record_entry(void);
void GetSelectedItemIndex(S32 hilitedIndex);
void EntryWtchScrViewRecordOptions(void);
void DeleteSelectedRecord(void);
void DeleteAllTimerRecord(void);
void ReplaceSelectedRecord(void);
void DisplayDiscontinueTimerQuery(void);
void EntryWtchScrViewSavedRecord(void);
void EntryWtchScrDeleteRecord(void);
void EntryWtchScrDeleteAllRecord(void);
void EntryWtchScrReplaceRecord(void);
void DiscontinuePreviousStopwatch(void);


/***************************************************************************** 
* Global Variable
*****************************************************************************/
mmi_stopwatch_cntx_struct gStopwatchAppInfo;    
stopwatchRecord gTimerRecordList[MAX_STOPWATCH_RECORDS];
UI_stop_watch gCurrentRecords[MAX_TIMER_RECORDS];
CHAR gTimerRecords[MAX_TIMER_RECORDS][(MAX_TIMER_RECORD_DIGITS + 1) * ENCODING_LENGTH];
U8 *gTimerRecordListNamep[MAX_STOPWATCH_RECORDS];
U8 *gTimerRecordsp[MAX_TIMER_RECORDS];
extern U8 isfrommul;
//extern U16 GetCurrScreenID(void);


/**********************************************************************
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  InitStopwatchApp
 * DESCRIPTION
 *  Initialize stopwatch Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitStopwatchApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selcitemforStopwatch = 0;
    isfromstopwatch = 0;
#ifndef __MMI_FTE_SUPPORT__
    InitMultipurposeStopwatch();
#endif
    ResetTypicalStopwatch();
#ifdef __MMI_FTE_SUPPORT__
    /* When running stopwatch for the first time, the default timing is SPLIT. */
    gStopwatchAppInfo.splitLapTimer = SPLIT_TIMER;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  InitStopwatchNVRAM
 * DESCRIPTION
 *  Initialize NVRAM for Stopwatch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitStopwatchNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 m,i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], MAX_STOPWATCH_RECORDS * sizeof(stopwatchRecord), &error);
    ReadValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);

    if ((gStopwatchAppInfo.numOfSavedTimerRecords == 0xFF) || (gStopwatchAppInfo.numOfSavedTimerRecords > MAX_STOPWATCH_RECORDS))
    {
        gStopwatchAppInfo.numOfSavedTimerRecords = 0;
        WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
    }

    m = 0 ;
    for (i = 0;i < gStopwatchAppInfo.numOfSavedTimerRecords; i++)
    {
        if(gTimerRecordList[i].numOfRecords == 0xFF)
        {
            
            continue;
        }
        else
        {   
            memcpy(&gTimerRecordList[m], &gTimerRecordList[i], sizeof(stopwatchRecord));
            m++;
            
        }
    }
    gStopwatchAppInfo.numOfSavedTimerRecords = m;
}


void mmi_stopwatch_notify(mmi_event_menu_struct *menu_notify)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_main_entry
 * DESCRIPTION
 *  Entry fn for Stopwatch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_main_entry(void)
{
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_STOPWATCH, mmi_stopwatch_proc, (void*)NULL);
    mmi_frm_group_enter(GRP_ID_STOPWATCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#ifdef __MMI_FTE_SUPPORT__
    mmi_stopwatch_split_lap_timing_entry();
#else
    mmi_stopwatch_main_entry_init();
#endif
}

void mmi_stopwatch_main_entry_init(void)
{
    mmi_id menu_gid = cui_menu_create(GRP_ID_STOPWATCH,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_STOPWATCH,
        MMI_FALSE,
        NULL);
    cui_menu_set_default_title(menu_gid, get_string(STR_STOPWATCH_TITLE), get_image(GetRootTitleIcon(MENU_STOPWATCH)));
    cui_menu_run(menu_gid);

#if (!defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__))
    isfrommul = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  HighlightStopwatch
 * DESCRIPTION
 *  Highlight handler fn for stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_stopwatch_main_entry, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_stopwatch_main_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

void mmi_stopwatch_select_option_reset(void)
{
    gStopwatchAppInfo.TimerState = TIMER_NOT_STARTED;
    ResetSplitLapTimer();
}

void mmi_stopwatch_select_option_continue(void)
{
    mmi_frm_scrn_close_active_id();
    ResumeSplitLapTimer();
}

void mmi_stopwatch_select_typical_stopwatch(void)
{
    isfromstopwatch = 1;
    mmi_stopwatch_typical_entry();
}

void mmi_stopwatch_select_split_timing(void)
{
    gStopwatchAppInfo.splitLapTimer = SPLIT_TIMER;
    mmi_stopwatch_split_lap_timing_entry();
}

void mmi_stopwatch_select_lap_timing(void)
{
    gStopwatchAppInfo.splitLapTimer = LAP_TIMER;
    mmi_stopwatch_split_lap_timing_entry();
}

mmi_ret mmi_stopwatch_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_menu_id hilight_menu = menu_evt->highlighted_menu_id;;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:           /* framework de-init the group */
        break;
        
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:   /* Handler when user confirm input */
        cui_fseditor_get_text(gStopwatchAppInfo.editor_cui_record_name, (WCHAR*)gStopwatchAppInfo.recordName, (MAX_RECORD_NAME_LENGTH + 1) * ENCODING_LENGTH);
        if (gStopwatchAppInfo.replaceRecord == TRUE)
        {
            ReplaceSelectedRecord();
        }
        else
        {
            SaveTimerRecord();
        }
        break;
    case EVT_ID_CUI_FSEDITOR_ABORT:    /* Handler when user Cancel input or Back */
        mmi_frm_scrn_close_active_id();
        cui_fseditor_close(gStopwatchAppInfo.editor_cui_record_name);
        break;
    }
    
    switch (menu_evt->evt_id)
    {
    case EVT_ID_CUI_MENU_ITEM_HILITE:   /* to set the CSK */
        if (hilight_menu == MENU_SPLIT_TIMING || hilight_menu == MENU_LAP_TIMING)         /* split timing */
        {
            if ((gStopwatchAppInfo.TimerState != TIMER_NOT_STARTED) 
                && ( (hilight_menu == MENU_SPLIT_TIMING && gStopwatchAppInfo.splitLapTimer == LAP_TIMER)
                || (hilight_menu == MENU_LAP_TIMING && gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)))
            {
                //SetCenterSoftkeyFunction(DisplayDiscontinueTimerQuery, KEY_EVENT_UP);
            }
            else
            {
            #ifndef __MMI_FTE_SUPPORT__
                //SetCenterSoftkeyFunction(hilight_menu == MENU_SPLIT_TIMING ? mmi_stopwatch_select_split_timing : mmi_stopwatch_select_lap_timing, KEY_EVENT_UP);
            #endif
            }
        }
        else if (hilight_menu == MENU_VIEW_RECORD)          /* view record */
        {
            //SetCenterSoftkeyFunction(mmi_stopwatch_view_record_entry, KEY_EVENT_UP);
        }
        if (hilight_menu == MENU_OPTION_VR_VIEW)            /* view one record */
        {
            //SetCenterSoftkeyFunction(EntryWtchScrViewSavedRecord, KEY_EVENT_UP);
        }
        else if (hilight_menu == MENU_OPTION_VR_DELETE)     /* delete one record */
        {
            //SetCenterSoftkeyFunction(EntryWtchScrDeleteRecord, KEY_EVENT_UP);
        }
        else if (hilight_menu == MENU_OPTION_VR_DELETE_ALL) /* delete all */
        {
            //SetCenterSoftkeyFunction(EntryWtchScrDeleteAllRecord, KEY_EVENT_UP);
        }
    #ifndef __MMI_FTE_SUPPORT__
        if (hilight_menu == MENU_TYPICALSTOPWATCH_ITEM)     /* typical */
        {
            //SetCenterSoftkeyFunction(mmi_stopwatch_select_typical_stopwatch, KEY_EVENT_UP);
        }
        else if (hilight_menu == MENU_MULTIPURPOSEWATCH)    /* multipurpose */
        {
            //SetCenterSoftkeyFunction(mmi_stopwatch_multi_purpose_entry, KEY_EVENT_UP);
        }
        else if (hilight_menu == MENU_RESET_OPTION)         /* reset timer */
        {
            //SetCenterSoftkeyFunction(mmi_stopwatch_select_option_reset, KEY_EVENT_UP);
        }
        else if (hilight_menu == MENU_CONTINUE_OPTION)      /* continue timer */
        {
            //SetCenterSoftkeyFunction(mmi_stopwatch_select_option_continue, KEY_EVENT_UP);
        }
    #endif
        //ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        break;
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        if (menu_evt->parent_menu_id == MENU_STOPWATCH_STOP_OPTIONS)
        {
        #ifdef __MMI_FTE_SUPPORT__
            if (gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED)
            {
                cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_STOPWATCH_SAVE_RECORD_OPTION, MMI_TRUE);
                if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
                {
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_SPLIT_TIMING, MMI_TRUE);
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_LAP_TIMING, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_SPLIT_TIMING, MMI_FALSE);
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_LAP_TIMING, MMI_TRUE);
                }
                cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_VIEW_RECORD, MMI_FALSE);
            }
            else if (gStopwatchAppInfo.TimerState == TIMER_RUNNING)
            {
                MMI_ASSERT(0);
            }
            else if (gStopwatchAppInfo.TimerState == TIMER_STOPPED)
            {
                if (gStopwatchAppInfo.isRecordPresent)
                {
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_STOPWATCH_SAVE_RECORD_OPTION, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_STOPWATCH_SAVE_RECORD_OPTION, MMI_TRUE);
                }
                if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
                {
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_SPLIT_TIMING, MMI_TRUE);
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_LAP_TIMING, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_SPLIT_TIMING, MMI_FALSE);
                    cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_LAP_TIMING, MMI_TRUE);
                }
                cui_menu_set_item_hidden(gStopwatchAppInfo.menu_cui_timing_option, MENU_VIEW_RECORD, MMI_FALSE);
            }
        #endif /* ifdef __MMI_FTE_SUPPORT__ */
        }
        break;
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        if (hilight_menu == MENU_SPLIT_TIMING || hilight_menu == MENU_LAP_TIMING)         /* split timing */
        {
            if ((gStopwatchAppInfo.TimerState != TIMER_NOT_STARTED) 
                && ( (hilight_menu == MENU_SPLIT_TIMING && gStopwatchAppInfo.splitLapTimer == LAP_TIMER)
                     || (hilight_menu == MENU_LAP_TIMING && gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)))
            {
                DisplayDiscontinueTimerQuery();
            }
            else
            {
            #ifdef __MMI_FTE_SUPPORT__
                if (hilight_menu == MENU_SPLIT_TIMING)
                {
                    mmi_stopwatch_fte_option_split();
                }
                else
                {
                    mmi_stopwatch_fte_option_lap();
                }
            #else
                gStopwatchAppInfo.splitLapTimer = (hilight_menu == MENU_SPLIT_TIMING ? SPLIT_TIMER : LAP_TIMER);
                mmi_stopwatch_split_lap_timing_entry();
            #endif
            }
        }
        else if (hilight_menu == MENU_VIEW_RECORD)          /* view record */
        {
            mmi_stopwatch_view_record_entry();
        }
        if (hilight_menu == MENU_OPTION_VR_VIEW)            /* view one record */
        {
            EntryWtchScrViewSavedRecord();
        }
        else if (hilight_menu == MENU_OPTION_VR_DELETE)     /* delete one record */
        {
            EntryWtchScrDeleteRecord();
        }
        else if (hilight_menu == MENU_OPTION_VR_DELETE_ALL) /* delete all */
        {
            EntryWtchScrDeleteAllRecord();
        }
    #ifdef __MMI_FTE_SUPPORT__
        else if (hilight_menu == MENU_STOPWATCH_SAVE_RECORD_OPTION)
        {
            ConfirmSaveTimerRecord();
        }
    #else
        else if (hilight_menu == MENU_TYPICALSTOPWATCH_ITEM)     /* typical */
        {
            mmi_stopwatch_select_typical_stopwatch();
        }
        else if (hilight_menu == MENU_MULTIPURPOSEWATCH)    /* multipurpose */
        {
            mmi_stopwatch_multi_purpose_entry();
        }
        else if (hilight_menu == MENU_RESET_OPTION)         /* reset timer */
        {
            mmi_stopwatch_select_option_reset();
        }
        else if (hilight_menu == MENU_CONTINUE_OPTION)      /* continue timer */
        {
            mmi_stopwatch_select_option_continue();
        }
    #endif
        break;
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        if (gStopwatchAppInfo.menu_cui_typical == menu_evt->sender_id)
        {
            gStopwatchAppInfo.menu_cui_typical = 0;
        }
        cui_menu_close(menu_evt->sender_id);
        break;
    }
    
    return MMI_RET_OK;
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_option_split
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_option_split(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.splitLapTimer = SPLIT_TIMER;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_option_lap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_option_lap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.splitLapTimer = LAP_TIMER;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_item_callback_start_reset
 * DESCRIPTION
 *  Callback function of Toolbar clicking START/RESET.
 * PARAMETERS
 *  index           [IN]        Toolbar index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_item_callback_start_reset(S32 index)
{
    S32 fte_item_count = MMI_STOPWATCH_FTE_TB_ITEM_CNT;
    PU8 fte_item_icon[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    PU8 fte_item_disabled_icon[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    PU8 fte_item_string[MMI_STOPWATCH_FTE_TB_ITEM_CNT];

    if (index == 0)     /* click START */
    {
        fte_item_string[0] = (PU8)GetString(STR_GLOBAL_STOP);
        fte_item_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_STOP);
        fte_item_disabled_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_STOP_DIS);

        if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
        {
            fte_item_string[1]  = (PU8)GetString(STR_STOPWATCH_SPLIT);
            fte_item_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_SPLIT);            
            fte_item_disabled_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_SPLIT_DIS);
        } 
        else if (gStopwatchAppInfo.splitLapTimer == LAP_TIMER)
        {
            fte_item_string[1]  = (PU8)GetString(STR_STOPWATCH_LAP);
            fte_item_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_LAP);            
            fte_item_disabled_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_LAP_DIS);
        }

        wgui_icon_bar_setup(
            fte_item_count,
            fte_item_icon,
            fte_item_disabled_icon,
            fte_item_string,
            mmi_stopwatch_fte_item_callback_stop_split);
        if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS)
        {
            /* make SPLIT/LAP invalid */
            wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
        }
        wgui_icon_bar_update();

        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);

        StartSplitLapTimer();
    }
    else if (index == 1) /* click RESET */
    {
        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
        wgui_icon_bar_update();
  
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS,0);
        SetLeftSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);

        ResetTypicalStopwatch();
        reset_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_item_callback_stop_split
 * DESCRIPTION
 *  Callback function of Toolbar clicking STOP/SPLIT(LAP).
 * PARAMETERS
 *  index           [IN]        Toolbar index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_item_callback_stop_split(S32 index)
{
    S32 fte_item_count = MMI_STOPWATCH_FTE_TB_ITEM_CNT;
    PU8 fte_item_icon[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    PU8 fte_item_disabled_icon[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    PU8 fte_item_string[MMI_STOPWATCH_FTE_TB_ITEM_CNT];

    if (index == 0)         /* click STOP */
    {
        fte_item_string[0] = (PU8)GetString(STR_GLOBAL_START);
        fte_item_string[1] = (PU8)GetString(STR_GLOBAL_RESET);
    
        fte_item_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_START);
        fte_item_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_RESET);
        fte_item_disabled_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_START_DIS);
        fte_item_disabled_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_RESET_DIS);

        wgui_icon_bar_setup(
            fte_item_count,
            fte_item_icon,
            fte_item_disabled_icon,
            fte_item_string,
            mmi_stopwatch_fte_item_callback_start_reset);
        wgui_icon_bar_update();

        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS,0);
        SetLeftSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);

        StopSplitLapTimer();
    }
    else if (index == 1)    /* click SPLIT/LAP */
    {
        MMI_ASSERT(gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS);
        if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS - 1)   /* make SPLIT/LAP invalid */
        {
            wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
            wgui_icon_bar_update();
        }
        RecordSplitLapTime();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_show_toolbar
 * DESCRIPTION
 *  Show toolbar, used when entry a screen(NOT update toolbar).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_show_toolbar(void)
{
    S32 fte_item_count = MMI_STOPWATCH_FTE_TB_ITEM_CNT;
    PU8 fte_item_icon[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    PU8 fte_item_disabled_icon[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    PU8 fte_item_string[MMI_STOPWATCH_FTE_TB_ITEM_CNT];
    GUIIconbarItemCallback callback;

    if (gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED || gStopwatchAppInfo.TimerState == TIMER_STOPPED)
    {
        fte_item_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_START);
        fte_item_string[0] = (U8*)GetString(STR_GLOBAL_START);
        fte_item_disabled_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_START_DIS);

        fte_item_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_RESET);
        fte_item_string[1] = (U8*)GetString(STR_GLOBAL_RESET);
        fte_item_disabled_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_RESET_DIS);
        callback = mmi_stopwatch_fte_item_callback_start_reset;
    }
    else
    {
        fte_item_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_STOP);
        fte_item_string[0] = (U8*)GetString(STR_GLOBAL_STOP);
        fte_item_disabled_icon[0] = get_image(IMG_TYPICALSW_FTE_TB_STOP_DIS);
        
        if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
        {        
            fte_item_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_SPLIT);
            fte_item_disabled_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_SPLIT_DIS);
            fte_item_string[1] = (U8*)GetString(STR_STOPWATCH_SPLIT);
        }
        else
        {
            fte_item_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_LAP);
            fte_item_disabled_icon[1] = get_image(IMG_TYPICALSW_FTE_TB_LAP_DIS);
            fte_item_string[1] = (U8*)GetString(STR_STOPWATCH_LAP);
        }
        callback = mmi_stopwatch_fte_item_callback_stop_split;
    }

    wgui_icon_bar_setup(fte_item_count, fte_item_icon, fte_item_disabled_icon, fte_item_string, callback);

    if (gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED || 
        (gStopwatchAppInfo.TimerState == TIMER_RUNNING && gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS))
    {
        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_tap_timer_callback
 * DESCRIPTION
 *  FTE tap callback.
 * PARAMETERS
 *  tap_type        [IN]        Tap type
 *  index           [IN]        Tapped item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_tap_timer_callback(mmi_tap_type_enum tap_type, S32 index)
{
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
        /* only change highlight.  do nothing in tap callback function */
        return;
    }
    /* No intuitive command here, just return! */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_fte_tap_record_view_callback
 * DESCRIPTION
 *  FTE tap callback.
 * PARAMETERS
 *  tap_type        [IN]        Tap type
 *  index           [IN]        Tapped item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_fte_tap_record_view_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
        /* only change highlight.  do nothing in tap callback function */
        return;
    }
    EntryWtchScrViewSavedRecord();
}
#endif /* ifdef __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_entry_category307
 * DESCRIPTION
 *  A wrapper of ShowCategory307Screen.
 * PARAMETERS
 *  left_softkey            [IN]        LSK string
 *  left_softkey_icon       [IN]        LSK icon
 *  right_softkey           [IN]        RSK string
 *  right_softkey_icon      [IN]        RSK icon
 *  number_of_items         [IN]        Number of items
 *  list_watch              [IN]        watch list
 *  highlighted_item        [IN]        highlighted item
 *  history_buffer          [IN]        history buffer
 *  bkg_image               [IN]        background image ID
 *  num_image               [IN]        number image
 *  colon_image             [IN]        colon image
 *  dot_image               [IN]        dot image
 *  start_continue_flag     [IN]        start continue flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_entry_category307(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        UI_stop_watch *list_watch,
        S32 highlighted_item,
        U8 *history_buffer,
        U16 bkg_image,
        S32 start_continue_flag)
{
#ifdef __MMI_FTE_SUPPORT__
    static PU8 num_image[10];

    num_image[0] = get_image(IMG_TYPICALSW_FTE_NUM_0);
    num_image[1] = get_image(IMG_TYPICALSW_FTE_NUM_1);
    num_image[2] = get_image(IMG_TYPICALSW_FTE_NUM_2);
    num_image[3] = get_image(IMG_TYPICALSW_FTE_NUM_3);
    num_image[4] = get_image(IMG_TYPICALSW_FTE_NUM_4);
    num_image[5] = get_image(IMG_TYPICALSW_FTE_NUM_5);
    num_image[6] = get_image(IMG_TYPICALSW_FTE_NUM_6);
    num_image[7] = get_image(IMG_TYPICALSW_FTE_NUM_7);
    num_image[8] = get_image(IMG_TYPICALSW_FTE_NUM_8);
    num_image[9] = get_image(IMG_TYPICALSW_FTE_NUM_9);

    mmi_stopwatch_fte_show_toolbar();
#endif

#ifdef __MMI_FTE_SUPPORT__
    ShowCategory307Screen(
            (U16)(gStopwatchAppInfo.TimerState == TIMER_RUNNING ? 0 : STR_GLOBAL_OPTIONS),
            (U16)0,
            (U16)STR_GLOBAL_BACK,
            (U16)0,
        number_of_items, 
        list_watch,
        highlighted_item, 
        history_buffer, 
        bkg_image,
        num_image, 
        get_image(IMG_TYPICALSW_FTE_COLON), 
        get_image(IMG_TYPICALSW_FTE_DOT),
        start_continue_flag);    
#else
    ShowCategory307Screen(
            left_softkey, 
            left_softkey_icon, 
            right_softkey, 
            right_softkey_icon,
            number_of_items, 
            list_watch,
            highlighted_item, 
            history_buffer, 
            bkg_image,
            start_continue_flag);
#endif

#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_stopwatch_fte_tap_timer_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_split_lap_timing_entry
 * DESCRIPTION
 *  Entry fn for Split/Lap timing stopwatch screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_split_lap_timing_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 start_continue_flag;
#if (!defined( __MMI_MAINLCD_320X480__ ) || defined( __MMI_FTE_SUPPORT__))
    U16 rsk_str;
#endif
#if (defined( __MMI_MAINLCD_320X480__ ) && !defined( __MMI_FTE_SUPPORT__))
    U16 lsk_str;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_STOPWATCH,
                           SCR_SPLIT_TIMING,
                           mmi_stopwatch_split_lap_timing_exit,
                           mmi_stopwatch_split_lap_timing_entry,
                           MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    SetParentHandler(MENU_SPLIT_TIMING);
    
    memset(gStopwatchAppInfo.recordName, 0, (MAX_RECORD_NAME_LENGTH + 1) * ENCODING_LENGTH);
    start_continue_flag = (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER ? CONTINUE_TIMER : STOP_START_AGAIN);

#if (!defined( __MMI_MAINLCD_320X480__ ) || defined( __MMI_FTE_SUPPORT__))
    if (gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED)
    {
        mmi_stopwatch_entry_category307(
            STR_GLOBAL_START, 0, 
            STR_GLOBAL_BACK, 0,
            0, 
            NULL,
            0,
            guiBuffer, 
            IMG_TYPICALSW_BACKGROUND,
            start_continue_flag);
    #ifndef __MMI_FTE_SUPPORT__
        SetLeftSoftkeyFunction(StartSplitLapTimer, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        
        SetCenterSoftkeyFunction(StartSplitLapTimer, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
    }
    else if (gStopwatchAppInfo.TimerState == TIMER_STOPPED)
    {
        mmi_stopwatch_entry_category307(
            STR_GLOBAL_OPTIONS, 0 , 
            0, 0,
            gStopwatchAppInfo.numofCurrTimerRecords, 
            gCurrentRecords,
            0,
            guiBuffer,
            IMG_TYPICALSW_BACKGROUND,
            start_continue_flag);
    #ifndef __MMI_FTE_SUPPORT__
        ChangeRightSoftkey((U16)(gStopwatchAppInfo.isRecordPresent > 0 ? STR_GLOBAL_DONE : STR_GLOBAL_BACK), 0);
        SetLeftSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);
        SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(ResumeSplitLapTimer, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
    }
    else    /* running */
    {
        if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
        {
            rsk_str = (gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS ? STR_STOPWATCH_SPLIT : 0);
        }
        else
        {
            rsk_str = (gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS ? STR_STOPWATCH_LAP : 0);
        }
        mmi_stopwatch_entry_category307(
            STR_GLOBAL_PAUSE, 0,
            rsk_str, 0,
            gStopwatchAppInfo.numofCurrTimerRecords,
            gCurrentRecords,
            0,
            guiBuffer,
            IMG_TYPICALSW_BACKGROUND,
            start_continue_flag);
    #ifndef __MMI_FTE_SUPPORT__
        SetLeftSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
        SetRightSoftkeyFunction(gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS ? RecordSplitLapTime : 0, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
    }

    #ifdef __MMI_FTE_SUPPORT__
    SetLeftSoftkeyFunction(gStopwatchAppInfo.TimerState == TIMER_RUNNING ? 0 : mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    #endif


#else  /* if (!defined( __MMI_MAINLCD_320X480__ ) || defined( __MMI_FTE_SUPPORT__)) */
    selcitemforStopwatch = gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER ? 0 : 1;
    if (gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED)
    {   
        panel_area_data_stopwatch.element_list = list;
         panel_area_data_stopwatch.focused_element = 0;
        panel_area_data_stopwatch.num_of_element = 3;
        panel_area_data_stopwatch.panel_bg_img_id = 0;
        panel_area_data_stopwatch.repeat_period = 0;
        ShowCategory307PanelScreen(
            0,
            0,
            STR_GLOBAL_BACK,
            0,
            0,
            NULL,
            0,
            IMG_TYPICALSW_BACKGROUND,
            &panel_area_data_stopwatch,
            start_continue_flag,
            guiBuffer
            );
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    else if (gStopwatchAppInfo.TimerState == TIMER_STOPPED)
    {
        ShowCategory307PanelScreen(
            0,
            0,
            0,
            0,
            gStopwatchAppInfo.numofCurrTimerRecords,
            gCurrentRecords,
            0,
            IMG_TYPICALSW_BACKGROUND,
            &panel_area_data_stopwatch,
            start_continue_flag,
            guiBuffer);         
        ChangeRightSoftkey((U16)(gStopwatchAppInfo.isRecordPresent == TRUE ? STR_GLOBAL_DONE : STR_GLOBAL_BACK), 0);
        SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);

        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
    }
    else
    {
        if (gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS)
        {
            lsk_str = (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER) ? STR_STOPWATCH_SPLIT : STR_STOPWATCH_LAP;
        }
        else
        {
            lsk_str = 0;
        }

        ShowCategory307PanelScreen(
            lsk_str,
            0,
            STR_GLOBAL_BACK,
            0,
            gStopwatchAppInfo.numofCurrTimerRecords,
            gCurrentRecords,
            0,
            IMG_TYPICALSW_BACKGROUND,
            &panel_area_data_stopwatch,
            start_continue_flag,
            guiBuffer);

        if (gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS)
        {
            SetLeftSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        else
        {
            SetCenterSoftkeyFunction(0, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, 0);
        }

        if (gStopwatchAppInfo.isRecordPresent)
        {
            SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);
        }
        else
        {
            ChangeRightSoftkey(0, 0);
        } 
    }

#endif /* if (!defined( __MMI_MAINLCD_320X480__ ) || defined( __MMI_FTE_SUPPORT__)) */
}


#if !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
/*****************************************************************************
 * FUNCTION
 *  StartKeyUpCallback
 * DESCRIPTION
 *  callback function start key up event 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  StartKeyUpCallback(void)
{
    if(gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED)
    {
        StartSplitLapTimer();
    }
    else if(gStopwatchAppInfo.TimerState == TIMER_RUNNING)
    {
        StopSplitLapTimer();
    }
    else if(gStopwatchAppInfo.TimerState == TIMER_STOPPED)
    {
        ResumeSplitLapTimer();
    }
} 


/*****************************************************************************
 * FUNCTION
 *  ResetKeyUpCallback
 * DESCRIPTION
 *  callback function reset key up event 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetKeyUpCallback(void)
{
    ResetSplitLapTimer();
}


/*****************************************************************************
 * FUNCTION
 *  NwayKeyUpCallback
 * DESCRIPTION
 *  callback function Nway key up event 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NwayKeyUpCallback(void)
{
    mmi_stopwatch_multi_purpose_entry();
}
#endif /* ifdef __MMI_MAINLCD_320X480__ */


void mmi_stopwatch_typical_entry(void)
{
    // to fix build warnings
    ((void)(isfromstopwatch));
    ((void)(selcitemforStopwatch));

#if (!defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__))
    if (isfrommul == 1)
    {
        if (gStopwatchAppInfo.menu_cui_typical > 0)
        {
            cui_menu_close(gStopwatchAppInfo.menu_cui_typical);
        }
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_SPLIT_TIMING);
        //mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_MULTIPURPOSE_STOPWATCH);
        isfrommul = 0;
    }
    if (isfromstopwatch == 1)
    {
        selcitemforStopwatch = 0;
        isfromstopwatch = 0;
    }
#endif

#ifndef __MMI_FTE_SUPPORT__
    gStopwatchAppInfo.menu_cui_typical = cui_menu_create(GRP_ID_STOPWATCH,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPSUB,
        MENU_TYPICALSTOPWATCH,
        MMI_FALSE,
        NULL);
    cui_menu_set_default_title(gStopwatchAppInfo.menu_cui_typical, get_string(STR_TYPICAL_STOPWATCH), get_image(GetRootTitleIcon(MENU_STOPWATCH)));
    cui_menu_run(gStopwatchAppInfo.menu_cui_typical);
    
    #ifdef __MMI_MAINLCD_320X480__
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_MULTIPURPOSE_STOPWATCH);
    #endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_split_lap_timing_exit
 * DESCRIPTION
 *  Exit fn for Split/Lap timing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_split_lap_timing_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gStopwatchAppInfo.TimerState == TIMER_RUNNING || gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
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
 *  StartSplitLapTimer
 * DESCRIPTION
 *  Start Split/lap Timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_stop_watch_timer(TIMER_START);
#ifndef __MMI_FTE_SUPPORT__
    #ifndef __MMI_MAINLCD_320X480__
        ChangeLeftSoftkey(STR_GLOBAL_PAUSE, 0);
        SetLeftSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
        SetRightSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
        ChangeRightSoftkey((U16)(gStopwatchAppInfo.splitLapTimer ? STR_STOPWATCH_SPLIT : STR_STOPWATCH_LAP), 0);
    #else /* ifndef __MMI_MAINLCD_320X480__ */
        list[1].off_imageid = IMG_TYPICAL_STOP_UP;
        list[1].on_imageid = IMG_TYPICAL_STOP_UP;
        list[1].down_imageid = IMG_TYPICAL_STOP_DOWN;
        wgui_catsw_update_panel(&panel_area_data_stopwatch);

        ChangeLeftSoftkey((U16)(gStopwatchAppInfo.splitLapTimer ? STR_STOPWATCH_SPLIT : STR_STOPWATCH_LAP), 0);
        SetLeftSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);

        ChangeRightSoftkey(0, 0);
        SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    #endif /* ifndef __MMI_MAINLCD_320X480__ */
#endif /* ifndef __MMI_FTE_SUPPORT__ */

    gStopwatchAppInfo.TimerState = TIMER_RUNNING;

    if (gStopwatchAppInfo.TimerState == TIMER_RUNNING || gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
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
 *  mmi_stopwatch_timing_option_entry
 * DESCRIPTION
 *  Entry Option Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_timing_option_entry(void)
{    
    gStopwatchAppInfo.menu_cui_timing_option = cui_menu_create(GRP_ID_STOPWATCH,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_STOPWATCH_STOP_OPTIONS,
        MMI_FALSE,
        NULL);
    cui_menu_set_default_title(gStopwatchAppInfo.menu_cui_timing_option, get_string(STR_GLOBAL_OPTIONS), get_image(GetRootTitleIcon(MENU_STOPWATCH)));
    cui_menu_run(gStopwatchAppInfo.menu_cui_timing_option);
}


/*****************************************************************************
 * FUNCTION
 *  StopSplitLapTimer
 * DESCRIPTION
 *  Stop split/Lap timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_stop_watch_timer(TIMER_STOP);
    
#ifndef __MMI_FTE_SUPPORT__
    #ifndef __MMI_MAINLCD_320X480__
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(ResumeSplitLapTimer, KEY_EVENT_UP);/*ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);*/
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);/*SetCenterSoftkeyFunction(mmi_stopwatch_timing_option_entry, KEY_EVENT_UP);*/
    #else
        list[1].off_imageid = IMG_TYPICAL_CON_UP;
        list[1].on_imageid = IMG_TYPICAL_CON_UP;
        list[1].down_imageid = IMG_TYPICAL_CON_DOWN;
        wgui_catsw_update_panel(&panel_area_data_stopwatch);
        ChangeLeftSoftkey(0,0);
        SetLeftSoftkeyFunction(NULL,KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
    #endif
    
    if (gStopwatchAppInfo.isRecordPresent == TRUE)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    }
    SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);
#endif /* ifndef __MMI_FTE_SUPPORT__ */

    gStopwatchAppInfo.TimerState = TIMER_STOPPED;

    if (gStopwatchAppInfo.TimerState == TIMER_RUNNING || gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
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
 *  ResumeSplitLapTimer
 * DESCRIPTION
 *  Resume current split/Lap timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResumeSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    start_stop_watch_timer(TIMER_START);
    #ifndef __MMI_MAINLCD_320X480__
        ChangeLeftSoftkey(STR_GLOBAL_PAUSE, 0);
        SetLeftSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);

        if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS)
        {
            ChangeRightSoftkey(0, 0);
        }
        else
        {
            if (gStopwatchAppInfo.splitLapTimer)
            {
                ChangeRightSoftkey(STR_STOPWATCH_SPLIT, 0);
            }
            else
            {
                ChangeRightSoftkey(STR_STOPWATCH_LAP, 0);
            }
            SetRightSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
        }        
    #else
        list[1].off_imageid = IMG_TYPICAL_STOP_UP;
        list[1].on_imageid = IMG_TYPICAL_STOP_UP;
        list[1].down_imageid = IMG_TYPICAL_STOP_DOWN;
        wgui_catsw_update_panel(&panel_area_data_stopwatch);
        if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS)
        {
            ChangeLeftSoftkey(0, 0);
            ChangeCenterSoftkey(0, 0);
        }
        else
        {
            if (gStopwatchAppInfo.splitLapTimer)
            {
                ChangeLeftSoftkey(STR_STOPWATCH_SPLIT, 0);
            }
            else
            {
                ChangeLeftSoftkey(STR_STOPWATCH_LAP, 0);
            }
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
        }
        
        if(gStopwatchAppInfo.isRecordPresent == TRUE)
        {
            ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
            SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);
        }
        else
        { 
            ChangeRightSoftkey(0,0);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        }
    #endif

    gStopwatchAppInfo.TimerState = TIMER_RUNNING;

    if (gStopwatchAppInfo.TimerState == TIMER_RUNNING || gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_STOP_WATCH);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_STOP_WATCH);
    }
    wgui_status_icon_bar_update();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ResetSplitLapTimer
 * DESCRIPTION
 *  Reset the Split/Lap Timer when Resume is long
 *  pressed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__    
    #ifdef __MMI_MAINLCD_320X480__
    reset_timer();
    #endif
#endif

    ResetTypicalStopwatch();

#if defined(__MMI_FTE_SUPPORT__) || !defined(__MMI_MAINLCD_320X480__)
    mmi_frm_scrn_close_active_id();
#endif

#ifndef __MMI_FTE_SUPPORT__
    #ifndef __MMI_MAINLCD_320X480__
        ChangeLeftSoftkey(STR_GLOBAL_START, 0);
        SetLeftSoftkeyFunction(StartSplitLapTimer, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(StartSplitLapTimer, KEY_EVENT_UP);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    #else /* ifndef __MMI_MAINLCD_320X480__ */
        list[1].off_imageid = IMG_TYPICAL_START_UP;
        list[1].on_imageid = IMG_TYPICAL_START_UP;
        list[1].down_imageid = IMG_TYPICAL_START_DOWN;
        wgui_catsw_update_panel(&panel_area_data_stopwatch);
        ChangeLeftSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
        SetCenterSoftkeyFunction(0, KEY_EVENT_UP);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    #endif /* ifndef __MMI_MAINLCD_320X480__ */
#endif /* ifndef __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  RecordSplitLapTime
 * DESCRIPTION
 *  This function splits/Laps the Time..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RecordSplitLapTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mili, hr, min, sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateHistoryValue(&mili, &hr, &min, &sec);

    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].hour = hr;
    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].min = min;
    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].sec = sec;
    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].mili_sec = mili;

    gStopwatchAppInfo.numofCurrTimerRecords++;
#ifndef __MMI_FTE_SUPPORT__
    if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS)
    {
    #ifndef __MMI_MAINLCD_320X480__
        ChangeRightSoftkey(0, 0);
    #else
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
    #endif
    }

    #ifdef __MMI_MAINLCD_320X480__
        ChangeRightSoftkey(STR_GLOBAL_BACK,0);
        SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);
    #endif
#endif /* ifndef __MMI_FTE_SUPPORT__ */
    gStopwatchAppInfo.isRecordPresent = TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  ConfirmSaveTimerRecord
 * DESCRIPTION
 *  Confirmation screen for saving the timer record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConfirmSaveTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr lsk_funcptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gStopwatchAppInfo.isRecordPresent == TRUE)
    {
#ifndef __MMI_FTE_SUPPORT__
        mmi_confirm_property_struct arg;
#endif
        if (gStopwatchAppInfo.numOfSavedTimerRecords < MAX_STOPWATCH_RECORDS)
        {
            lsk_funcptr = mmi_stopwatch_enter_record_name_entry;
        }
        else
        {
            lsk_funcptr = EntryWtchScrMemoryFull;
        }

    #ifdef __MMI_FTE_SUPPORT__
        (*lsk_funcptr)();
    #else
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_STOPWATCH;
    arg.f_enter_history = 0;
    mmi_confirm_display(get_string(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &arg);

        SetLeftSoftkeyFunction(lsk_funcptr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(lsk_funcptr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackToStopwatchMenu, KEY_EVENT_UP);
    #endif
    }
    else
    {
        ResetTypicalStopwatch();
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackToStopwatchMenu
 * DESCRIPTION
 *  This fn takes user to StopwatchMenu screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackToStopwatchMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    //DeleteUptoScrID(SCR_SPLIT_TIMING);
#else
    mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_SPLIT_TIMING);
#endif
    ResetTypicalStopwatch();
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_enter_record_name_entry
 * DESCRIPTION
 *  This function gets the record name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_enter_record_name_entry(void)
{
    gStopwatchAppInfo.editor_cui_record_name = cui_fseditor_create(GRP_ID_STOPWATCH);
    cui_fseditor_set_title(gStopwatchAppInfo.editor_cui_record_name, STR_GLOBAL_SAVE, GetRootTitleIcon(MENU_STOPWATCH));
    cui_fseditor_set_text(gStopwatchAppInfo.editor_cui_record_name, (WCHAR*)gStopwatchAppInfo.recordName, (MAX_RECORD_NAME_LENGTH + 1) * ENCODING_LENGTH, MAX_RECORD_NAME_LENGTH);
    cui_fseditor_set_input_method(gStopwatchAppInfo.editor_cui_record_name, IMM_INPUT_TYPE_SENTENCE, NULL, 0);
    //cui_fseditor_set_title_in_header(gStopwatchAppInfo.editor_cui_record_name, MMI_TRUE);
    cui_fseditor_run(gStopwatchAppInfo.editor_cui_record_name);
}


/*****************************************************************************
 * FUNCTION
 *  SaveTimerRecord
 * DESCRIPTION
 *  Saves Timer Record in NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 temprecordName[(MAX_RECORD_NAME_LENGTH + 1) *ENCODING_LENGTH];
    S16 error;
    S32 str_length,i,m;
    S32 space_all_flag = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_length = mmi_ucs2strlen((CHAR*) gStopwatchAppInfo.recordName);
    for(i = 0; i < str_length; i++)
    {
        if (gStopwatchAppInfo.recordName[i * 2] != ' ' || gStopwatchAppInfo.recordName[i * 2 + 1] != 0)
        {
            space_all_flag = 0;
            break;
        }
    }
    m = 0;
    if (space_all_flag != 1)
    {
        for (m = str_length; m > 0; m--)
        {
            if ((gStopwatchAppInfo.recordName[(m - 1) * 2] == ' ') && (gStopwatchAppInfo.recordName[m * 2 -1] == 0))
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }
    
    if((i != 0) && (space_all_flag != 1))
    {
        mmi_ucs2cpy((CHAR *)(temprecordName), (CHAR *)(gStopwatchAppInfo.recordName + i * ENCODING_LENGTH));
        mmi_ucs2cpy((CHAR *)(gStopwatchAppInfo.recordName), (CHAR *)(temprecordName));
    }
    
    if (str_length == 0 || space_all_flag == 1)
    {
        // mmi_frm_scrn_close_active_id();
        mmi_popup_display_simple((UI_string_type)GetString(STR_EMPTY_NAME), MMI_EVENT_ERROR, GRP_ID_STOPWATCH, NULL);
    }
    else
    {
        gStopwatchAppInfo.recordName[(m - i)* ENCODING_LENGTH] = 0;
        gStopwatchAppInfo.recordName[(m - i)* ENCODING_LENGTH + 1] = 0;
        memset(&gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords], 0, sizeof(stopwatchRecord));
        memcpy(
            &gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].name,
            gStopwatchAppInfo.recordName,
            MAX_RECORD_NAME_LENGTH * ENCODING_LENGTH);
        gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].numOfRecords =
            (U8) gStopwatchAppInfo.numofCurrTimerRecords;
        for (index = 0; index < gStopwatchAppInfo.numofCurrTimerRecords; index++)
        {
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recHr =
                (U8) gCurrentRecords[index].hour;
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recMin =
                (U8) gCurrentRecords[index].min;
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recSec =
                (U8) gCurrentRecords[index].sec;
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recMsec =
                (U8) gCurrentRecords[index].mili_sec;
        }

        gStopwatchAppInfo.numOfSavedTimerRecords++;

        WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
        WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

        mmi_frm_scrn_close_active_id();
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, GRP_ID_STOPWATCH, NULL);
        ResetTypicalStopwatch();
        cui_fseditor_close(gStopwatchAppInfo.editor_cui_record_name);
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_REPLACE_RECORD);
    #ifndef __MMI_FTE_SUPPORT__
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_SPLIT_TIMING);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  FailedSaveTimerRecord
 * DESCRIPTION
 *  Failed in saving timer record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FailedSaveTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((UI_string_type)GetString(STR_STOPWATCH_NOT_SAVED), MMI_EVENT_FAILURE, GRP_ID_STOPWATCH, NULL);

    mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_REPLACE_RECORD);
#ifndef __MMI_FTE_SUPPORT__
    mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_SPLIT_TIMING);
#endif
    ResetTypicalStopwatch();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_stopwatch_view_record_entry
 * DESCRIPTION
 *  Entry fn for view record list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_stopwatch_view_record_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gStopwatchAppInfo.numOfSavedTimerRecords > 0)
    {
        for (count = 0; count < gStopwatchAppInfo.numOfSavedTimerRecords; count++)
        {
            gTimerRecordListNamep[count] = (U8*)gTimerRecordList[count].name;
        }
    }

    if (gStopwatchAppInfo.numOfSavedTimerRecords == 0)
    {
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, GRP_ID_STOPWATCH, NULL);
    }
    else
    {
        if (mmi_frm_scrn_enter(GRP_ID_STOPWATCH,
                               SCR_VIEW_RECORD,
                               NULL,
                               mmi_stopwatch_view_record_entry,
                               MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
        {
            return;
        }
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();        
        SetParentHandler(MENU_VIEW_RECORD);
        RegisterHighlightHandler(GetSelectedItemIndex);
        ShowCategory84Screen(
            STR_VIEW_RECORD,
            GetRootTitleIcon(MENU_STOPWATCH),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gStopwatchAppInfo.numOfSavedTimerRecords,
            (U8 **) gTimerRecordListNamep,
            (PU16) gIndexIconsImageList,
            0,
            gStopwatchAppInfo.currHilitedRecord,
            guiBuffer);
    #ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_stopwatch_fte_tap_record_view_callback);
    #endif

        SetLeftSoftkeyFunction(EntryWtchScrViewRecordOptions, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(EntryWtchScrViewRecordOptions, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  GetSelectedItemIndex
 * DESCRIPTION
 *  Function to store current hilited record in global variable.
 * PARAMETERS
 *  hilitedIndex        [IN]        
 *  Current(?)          [IN]        Hilite Index
 * RETURNS
 *  void
 *****************************************************************************/
void GetSelectedItemIndex(S32 hilitedIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.currHilitedRecord = hilitedIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrViewRecordOptions
 * DESCRIPTION
 *  Entry fn for view record options list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrViewRecordOptions(void)
{

    gStopwatchAppInfo.menu_cui_view_record = cui_menu_create(GRP_ID_STOPWATCH,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_VIEW_RECORD_OPTIONS,
        MMI_FALSE,
        NULL);
    cui_menu_set_default_title(gStopwatchAppInfo.menu_cui_view_record, get_string(STR_GLOBAL_OPTIONS), get_image(GetRootTitleIcon(MENU_STOPWATCH)));
    cui_menu_run(gStopwatchAppInfo.menu_cui_view_record);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrViewSavedRecord
 * DESCRIPTION
 *  Entry fn To view saved record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrViewSavedRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 currRecordNum = 0;
    //U8 *listItemsIcons[MAX_SUB_MENUS];
    nRecordDetail *localRecord;
    U8 localRecordString[(MAX_TIMER_RECORD_DIGITS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_STOPWATCH,
                           SCR_VIEW_SAVED_RECORD,
                           NULL,
                           EntryWtchScrViewSavedRecord,
                           MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }

    for (currRecordNum = 0; currRecordNum < gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].numOfRecords;
         currRecordNum++)
    {
        memset(localRecordString, 0, (MAX_TIMER_RECORD_DIGITS + 1) * ENCODING_LENGTH);
        localRecord = &gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[currRecordNum];
        change_stopwatchtime_to_string(
            (S32) localRecord->recMsec,
            (S32) localRecord->recHr,
            (S32) localRecord->recMin,
            (S32) localRecord->recSec,
            &localRecordString[0],
            DISPLAY_MILISEC_TRUE);
        mmi_ucs2cpy((CHAR*) &gTimerRecords[currRecordNum][0], (CHAR*) localRecordString);
        gTimerRecordsp[currRecordNum] = (U8*)&gTimerRecords[currRecordNum][0];
        //listItemsIcons[currRecordNum] = (U8*) GetImage(gIndexIconsImageList[currRecordNum]);
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    SetParentHandler(MENU_OPTION_VR_VIEW);

    ShowCategory353Screen(
        (U8*) gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].name,
        GetRootTitleIcon(MENU_STOPWATCH),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32)currRecordNum,
        (U8 **) gTimerRecordsp,
        (U16*)gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrDeleteRecord
 * DESCRIPTION
 *  Entry fn To Delete record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrDeleteRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_STOPWATCH;
    arg.f_enter_history = 0;
    arg.f_auto_map_empty_softkey = 0;
    mmi_confirm_display(get_string(STR_CONFIRM_DELETE_RECORD), MMI_EVENT_QUERY, &arg);

    SetLeftSoftkeyFunction(DeleteSelectedRecord, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DeleteSelectedRecord
 * DESCRIPTION
 *  This function deletes curently selected record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteSelectedRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&gTimerRecordList[gStopwatchAppInfo.currHilitedRecord], 0, sizeof(stopwatchRecord));

    for (count = (U8)gStopwatchAppInfo.currHilitedRecord; count + 1 < gStopwatchAppInfo.numOfSavedTimerRecords; count++)
    {
        memcpy(&gTimerRecordList[count], &gTimerRecordList[count + 1], sizeof(stopwatchRecord));
    }
    memset(&gTimerRecordList[--gStopwatchAppInfo.numOfSavedTimerRecords], 0, sizeof(stopwatchRecord));

    WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
    WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, GRP_ID_STOPWATCH, NULL);

    if (gStopwatchAppInfo.numOfSavedTimerRecords == 0)
    {
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_VIEW_RECORD);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrDeleteAllRecord
 * DESCRIPTION
 *  Entry fn To confirm Delete all record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrDeleteAllRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_STOPWATCH;
    arg.f_enter_history = 0;
    arg.f_auto_map_empty_softkey = 0;
    
    mmi_confirm_display(get_string(STR_CONFIRM_DELETE_ALL_RECORD), MMI_EVENT_QUERY, &arg);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(DeleteAllTimerRecord, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DeleteAllTimerRecord
 * DESCRIPTION
 *  This function deletes all Saved Timer Records.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gTimerRecordList, 0, sizeof(stopwatchRecord) * MAX_STOPWATCH_RECORDS);
    gStopwatchAppInfo.numOfSavedTimerRecords = 0;

    WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
    WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

    mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, GRP_ID_STOPWATCH, NULL);

    mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_VIEW_RECORD);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrMemoryFull
 * DESCRIPTION
 *  Displays the screen for memory full
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrMemoryFull(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_STOPWATCH;
    arg.f_enter_history = 0;

    mmi_confirm_display(get_string(STR_STOPWATCH_MEMORY_FULL), MMI_EVENT_QUERY, &arg);
    
    SetLeftSoftkeyFunction(EntryWtchScrReplaceRecord, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(EntryWtchScrReplaceRecord, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FailedSaveTimerRecord, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrReplaceRecord
 * DESCRIPTION
 *  Entry fn To replace previous record when memory is full
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrReplaceRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(GRP_ID_STOPWATCH,
                           SCR_REPLACE_RECORD,
                           NULL,
                           EntryWtchScrReplaceRecord,
                           MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }

    for (count = 0; count < gStopwatchAppInfo.numOfSavedTimerRecords; count++)
    {
        gTimerRecordListNamep[count] = (U8*)gTimerRecordList[count].name;
    }
    
    gStopwatchAppInfo.replaceRecord = TRUE;

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(GetSelectedItemIndex);
    ShowCategory84Screen(
        STR_STOPWATCH_REPLACE_RECORD,
        GetRootTitleIcon(MENU_STOPWATCH),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        0,
        gStopwatchAppInfo.numOfSavedTimerRecords,
        (U8 **) gTimerRecordListNamep,
        (PU16) gIndexIconsImageList,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_stopwatch_enter_record_name_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FailedSaveTimerRecord, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ReplaceSelectedRecord
 * DESCRIPTION
 *  Replace Existing Record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReplaceSelectedRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    U8 temprecordName[(MAX_RECORD_NAME_LENGTH + 1) *ENCODING_LENGTH];
    S16 error;
    S32 str_length, i, m;
    S32 space_all_flag = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_length = mmi_ucs2strlen((CHAR*) gStopwatchAppInfo.recordName);
    for(i = 0; i < str_length; i++)
    {
        if (gStopwatchAppInfo.recordName[i * 2] != ' ' || gStopwatchAppInfo.recordName[i * 2 + 1] != 0)
        {
            space_all_flag = 0;
            break;
        }
    }

    m = 0;
    if (space_all_flag != 1)
    {
        for (m = str_length; m > 0; m--)
        {
            if ((gStopwatchAppInfo.recordName[(m - 1) * 2] == ' ') && (gStopwatchAppInfo.recordName[m * 2 -1] == 0))
            {
                continue;
            }
            else
            {
                break;
            }
                
        }
    }
    if((i != 0) && (space_all_flag != 1))
    {
        mmi_ucs2cpy((CHAR *)(temprecordName), (CHAR *)(gStopwatchAppInfo.recordName + i * ENCODING_LENGTH));
        mmi_ucs2cpy((CHAR *)(gStopwatchAppInfo.recordName), (CHAR *)(temprecordName));
    }
    
    
    if (str_length == 0 || space_all_flag == 1)
    {
        mmi_frm_scrn_close_active_id();
        mmi_popup_display_simple((UI_string_type)GetString(STR_EMPTY_NAME), MMI_EVENT_ERROR, GRP_ID_STOPWATCH, NULL);
    }
    else
    {
        gStopwatchAppInfo.recordName[(m - i)* ENCODING_LENGTH] = 0;
        gStopwatchAppInfo.recordName[(m - i)* ENCODING_LENGTH + 1] = 0;
        gStopwatchAppInfo.replaceRecord = FALSE;

        memset(&gTimerRecordList[gStopwatchAppInfo.currHilitedRecord], 0, sizeof(stopwatchRecord));
        memcpy(
            &gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].name,
            gStopwatchAppInfo.recordName,
            MAX_RECORD_NAME_LENGTH * ENCODING_LENGTH);
        gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].numOfRecords =
            (U8) gStopwatchAppInfo.numofCurrTimerRecords;

        for (count = 0; count < gStopwatchAppInfo.numofCurrTimerRecords; count++)
        {
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recHr =
                (U8) gCurrentRecords[count].hour;
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recMin =
                (U8) gCurrentRecords[count].min;
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recSec =
                (U8) gCurrentRecords[count].sec;
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recMsec =
                (U8) gCurrentRecords[count].mili_sec;
        }

        WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
        WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

        mmi_frm_scrn_close_active_id();
        mmi_popup_display_simple((UI_string_type)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, GRP_ID_STOPWATCH, NULL);

        cui_fseditor_close(gStopwatchAppInfo.editor_cui_record_name);
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_REPLACE_RECORD);
    #ifndef __MMI_FTE_SUPPORT__
        mmi_frm_scrn_close(GRP_ID_STOPWATCH, SCR_SPLIT_TIMING);
    #endif
        ResetTypicalStopwatch();
    }

}

/********************For Stopwatch running in background***************************/


/*****************************************************************************
 * FUNCTION
 *  DisplayDiscontinueTimerQuery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayDiscontinueTimerQuery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_STOPWATCH;
    arg.f_enter_history = 0;
    mmi_confirm_display(get_string(STR_DISCONTINUE_TIMER_QUERY), MMI_EVENT_QUERY, &arg);

    SetLeftSoftkeyFunction(DiscontinuePreviousStopwatch, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(DiscontinuePreviousStopwatch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DiscontinuePreviousStopwatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DiscontinuePreviousStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetTypicalStopwatch();

    gStopwatchAppInfo.splitLapTimer = gStopwatchAppInfo.splitLapTimer == LAP_TIMER ? SPLIT_TIMER : LAP_TIMER;

    if (gStopwatchAppInfo.TimerState == TIMER_RUNNING || gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_STOP_WATCH);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_STOP_WATCH);
    }
    wgui_status_icon_bar_update();
    
#ifdef __MMI_FTE_SUPPORT__
    mmi_frm_scrn_close_active_id();
#else
    mmi_stopwatch_split_lap_timing_entry();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ResetTypicalStopwatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetTypicalStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
    list[1].off_imageid = IMG_TYPICAL_START_UP;
    list[1].on_imageid = IMG_TYPICAL_START_UP;
    list[1].down_imageid = IMG_TYPICAL_START_DOWN;

    mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
    if(scrn_id == SCR_SPLIT_TIMING)
    {
        wgui_catsw_update_panel(&panel_area_data_stopwatch);
    }
    if((gStopwatchAppInfo.TimerState == TIMER_RUNNING) &&(gStopwatchAppInfo.MPTimerState != TIMER_RUNNING))
    {
      wgui_status_icon_bar_hide_icon(STATUS_ICON_STOP_WATCH);
    }
#endif 

    gStopwatchAppInfo.replaceRecord = FALSE;
    gStopwatchAppInfo.isRecordPresent = FALSE;
    gStopwatchAppInfo.numofCurrTimerRecords = 0;
    gStopwatchAppInfo.TimerState = TIMER_NOT_STARTED;
    memset(gCurrentRecords, 0, sizeof(UI_stop_watch) * MAX_TIMER_RECORDS);
    initialize_stop_watch_timer();
}

#endif /* __MMI_STOPWATCH__ */ 
