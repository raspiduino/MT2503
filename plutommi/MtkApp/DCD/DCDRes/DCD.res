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

/*******************************************************************************
* Filename:
* ---------
*  DCD.res
*
* Project:
* --------
*  10A
*
* Description:
* ------------
*  DCD resource file
*
* Author:
* -------
*  Guoyi Zhao(MTK80128)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 10 26 2010 jia.liu
 * [MAUI_02638714] MTPNP API and Callback Mgr Revise
 * .
 *
 * May 17 2010 mtk80128
 * [MAUI_02180881] DCD 10A screen group/CUI/app-srv split deploy
 * 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*==============================================================================*/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_OP01_DCD__)
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_DCD">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_DCD"/>
    <STRING id = "STR_ID_DCD_ADD_CHANNEL"/>
    <STRING id = "STR_ID_DCD_DELETE_CHANNEL"/>
    <STRING id = "STR_ID_DCD_SAVED_STORY"/>
    <STRING id = "STR_ID_DCD_REFRESH"/>
    <STRING id = "STR_ID_DCD_DOWNLOAD_SYNCPKG"/>
    <STRING id = "STR_ID_DCD_DOWNLOAD_IMAGE"/>
    <STRING id = "STR_ID_DCD_CHANNEL_LIST"/>
    <STRING id = "STR_ID_DCD_CONN_MODE"/>
    <STRING id = "STR_ID_DCD_CONN_ALWAYS"/>
    <STRING id = "STR_ID_DCD_CONN_MANUAL"/>
    <STRING id = "STR_ID_DCD_CONN_HOME_ONLY"/>
    <STRING id = "STR_ID_DCD_SCROLL_SPEED"/>
    <STRING id = "STR_ID_DCD_IDLE_DISPLAY"/>
    <STRING id = "STR_ID_DCD_READ_STORY_DISPLAY"/>
    <STRING id = "STR_ID_DCD_STORY_LIST"/>
    <STRING id = "STR_ID_DCD_BACKGROUND_SYNC_PROGRESS"/>
    <STRING id = "STR_ID_DCD_STORY_VIEWER"/>
    <STRING id = "STR_ID_DCD_SAVE_STORY"/>
    <STRING id = "STR_ID_DCD_CONTENT_UPDATED"/>
    <STRING id = "STR_ID_DCD_SYNC_COMPLETED"/>
    <STRING id = "STR_ID_DCD_QUOTA_EXCEEDED"/>
    <STRING id = "STR_ID_DCD_MANUAL_UPDATE_STORAGE_FULL"/>
    <STRING id = "STR_ID_DCD_RESTORE_FACTORY"/>
    <STRING id = "STR_ID_DCD_QUESTION_MARK"/>
    <STRING id = "STR_ID_DCD_UPDATE_LOG"/>
    <STRING id = "STR_ID_DCD_NO_UPDATE_LOG"/>
    <STRING id = "STR_ID_DCD_SWITCH_ON"/>
    <STRING id = "STR_ID_DCD_SWITCH_OFF"/>
    <STRING id = "STR_ID_DCD_PURCHASE_EXIST"/>
    <STRING id = "STR_ID_DCD_MAN_UPDATE_WHEN_ROAMING_PROMPT"/>
    <STRING id = "STR_ID_DCD_MANUAL_UPDATE_PROMPT"/>
    <STRING id = "STR_ID_DCD_MANUAL_UPDATE_AGAIN"/>
    <STRING id = "STR_ID_DCD_SWITCH_ON_PROMPT"/>
    <STRING id = "STR_ID_DCD_RESTORE_COMPLETED"/>
    <STRING id = "STR_ID_DCD_SYNC_FAILURE"/>
    <STRING id = "STR_ID_DCD_SYNC_SUCCESS"/>
    <STRING id = "STR_ID_DCD_HELP_INFO1"/>
    <STRING id = "STR_ID_DCD_HELP_INFO2"/>
    <STRING id = "STR_ID_DCD_HELP_INFO3"/>
    <STRING id = "STR_ID_DCD_HELP_INFO4"/>
    <STRING id = "STR_ID_DCD_HELP_INFO5"/>
    <STRING id = "STR_ID_DCD_HELP_INFO6"/>
    <STRING id = "STR_ID_DCD_HELP_INFO7"/>
    <STRING id = "STR_ID_DCD_MORE"/>
    <STRING id = "STR_ID_DCD_CANCELLED"/>
    <STRING id = "STR_ID_DCD_SWITCH_OFF_ASK"/>
    <STRING id = "STR_ID_DCD_SYNC_NEXT_MANUAL"/>
    <STRING id = "STR_ID_DCD_OBTAIN_SYNC_PKG"/>
    <STRING id = "STR_ID_DCD_LAST_SYNC_TIME"/>
    <STRING id = "STR_ID_DCD_LAST_SYNC_RESULT"/>
    <STRING id = "STR_ID_DCD_FAIL_CAUSE"/>
    <STRING id = "STR_ID_DCD_NEXT_SYNC_TIME"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_701"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_702"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_703"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_704"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_705"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_706"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_707"/>
    <STRING id = "STR_ID_DCD_SYNC_ERRCODE_708"/>
    <STRING id = "STR_ID_DCD_SAVE_PICTURE"/>
    <STRING id = "STR_ID_DCD_SYNCING"/>
    <STRING id = "STR_ID_DCD_CONFLICT_PROMPT"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_DCD_SUB_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_DCD.png"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Tree Area-->
    <!--Setting menu-->
    <MENU id="MENU_ID_DCD_CONN_MODE" str="STR_ID_DCD_CONN_MODE" flag="RADIO">
        <MENUITEM id="MENU_ID_DCD_CONN_MODE_ALWAYS" str="STR_ID_DCD_CONN_ALWAYS"/>
        <MENUITEM id="MENU_ID_DCD_CONN_MODE_HOME_ONLY" str="STR_ID_DCD_CONN_HOME_ONLY"/>
        <MENUITEM id="MENU_ID_DCD_CONN_MODE_MANUAL" str="STR_ID_DCD_CONN_MANUAL"/>
    </MENU>

    <MENU id="MENU_ID_DCD_CHANNEL_OPTION_SETTING" type="APP_SUB" str="STR_GLOBAL_SETTINGS">
        <MENUITEM id="MENU_ID_DCD_SETTING_IDLE_DISPLAY" str="STR_ID_DCD_IDLE_DISPLAY"/>
        <MENUITEM id="MENU_ID_DCD_SETTING_CONN_MODE" str="STR_ID_DCD_CONN_MODE"/>
        <MENUITEM id="MENU_ID_DCD_SETTING_SWITCH" str="STR_ID_DCD_SWITCH_OFF"/>
        <MENUITEM id="MENU_ID_DCD_SETTING_UPDATE_LOG" str="STR_ID_DCD_UPDATE_LOG"/>
        <MENUITEM id="MENU_ID_DCD_SETTING_RESET" str="STR_ID_DCD_RESTORE_FACTORY"/>
        <MENUITEM id="MENU_ID_DCD_SETTING_HELP" str="STR_GLOBAL_HELP"/>
    </MENU>

    <!--ChannelList option menu-->
    <MENU id="MENU_ID_DCD_CHANNEL_LIST_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_DCD_CHANNEL_OPTION_VIEW" str="STR_GLOBAL_VIEW"/>
        <MENUITEM id="MENU_ID_DCD_CHANNEL_OPTION_REFRESH" str="STR_ID_DCD_REFRESH"/>
        <MENUITEM id="MENU_ID_DCD_CHANNEL_OPTION_ADD_CHANNEL" str="STR_ID_DCD_ADD_CHANNEL"/>
        <MENUITEM id="MENU_ID_DCD_CHANNEL_OPTION_DEL_CHANNEL" str="STR_ID_DCD_DELETE_CHANNEL"/>
        <MENUITEM id="MENU_ID_DCD_CHANNEL_OPTION_SAVED_STORY" str="STR_ID_DCD_SAVED_STORY"/>
        <MENUITEM_ID>MENU_ID_DCD_CHANNEL_OPTION_SETTING</MENUITEM_ID>
    </MENU>

    <!--StoryList option menu-->
    <MENU id="MENU_ID_DCD_STORY_LIST_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_DCD_STORY_LIST_OPTION_VIEW" str="STR_GLOBAL_VIEW"/>
        <MENUITEM id="MENU_ID_DCD_STORY_LIST_OPTION_REFRESH" str="STR_ID_DCD_REFRESH"/>
        <MENUITEM id="MENU_ID_DCD_STORY_LIST_OPTION_SAVED_STORY" str="STR_ID_DCD_SAVED_STORY"/>
        <MENUITEM_ID>MENU_ID_DCD_CHANNEL_OPTION_SETTING</MENUITEM_ID>
    </MENU>

    <!--Saved storyList option menu-->
    <MENU id="MENU_ID_DCD_SAVED_STORY_LIST_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_DCD_SAVED_STORY_LIST_OPTION_VIEW" str="STR_GLOBAL_VIEW"/>
        <MENUITEM id="MENU_ID_DCD_SAVED_STORY_LIST_OPTION_DELETE" str="STR_GLOBAL_DELETE"/>
        <MENUITEM id="MENU_ID_DCD_SAVED_STORY_LIST_OPTION_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL"/>
    </MENU>

    <!--StoryViewer option forward menu-->
    <MENU id="MENU_ID_DCD_VIEWER_OPTION_FORWARD" type="APP_SUB" str="STR_GLOBAL_FORWARD">
        <MENUITEM id="MENU_ID_DCD_FORWARD_TO_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE"/>
        <MENUITEM id="MENU_ID_DCD_FORWARD_TO_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
        <MENUITEM id="MENU_ID_DCD_FORWARD_TO_EMAIL" str="STR_GLOBAL_AS_EMAIL"/>
    </MENU>


    <!--StoryViewer option menu-->
    <MENU id="MENU_ID_DCD_VIEWER_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_DCD_VIEWER_OPTION_GO_TO" str="STR_GLOBAL_GO_TO"/>
        <MENUITEM_ID>MENU_ID_DCD_VIEWER_OPTION_FORWARD</MENUITEM_ID>
        <MENUITEM id="MENU_ID_DCD_VIEWER_OPTION_SAVE_STORY" str="STR_ID_DCD_SAVE_STORY"/>
        <MENUITEM id="MENU_ID_DCD_VIEWER_OPTION_SAVE_IMAGE" str="STR_ID_DCD_SAVE_PICTURE"/>
        <MENUITEM id="MENU_ID_DCD_VIEWER_OPTION_DELETE" str="STR_GLOBAL_DELETE"/>
    </MENU>

    <!------------------------------------------------------Screen ID Resource Area---------------------------------------------------------->
    <SCREEN id="SCR_ID_DCD_CHANNEL_LIST"/>
    <SCREEN id="SCR_ID_DCD_CHANNEL_LIST_OPTION"/>
    <SCREEN id="SCR_ID_DCD_STORY_LIST"/>
    <SCREEN id="SCR_ID_DCD_STORY_LIST_OPTION"/>
    <SCREEN id="SCR_ID_DCD_STORY_VIEWER"/>
    <SCREEN id="SCR_ID_DCD_STORY_VIEWER_OPTION"/>
    <SCREEN id="SCR_ID_DCD_FORWARD"/>
    <SCREEN id="SCR_ID_DCD_SAVE_IMAGE"/>
    <SCREEN id="SCR_ID_DCD_SAVED_STORY_LIST"/>
    <SCREEN id="SCR_ID_DCD_SAVED_STORY_LIST_OPTION"/>
    <SCREEN id="SCR_ID_DCD_SAVED_STORY_VIEWER_OPTION"/>
    <SCREEN id="SCR_ID_DCD_SETTING"/>
    <SCREEN id="SCR_ID_DCD_IDLE_SETTING"/>
    <SCREEN id="SCR_ID_DCD_CONNECT_MODE"/>
    <SCREEN id="SCR_ID_DCD_SWITCH"/>
    <SCREEN id="SCR_ID_DCD_MANUAL_UPDATE_PROMPT"/>
    <SCREEN id="SCR_ID_DCD_MANUAL_UPDATE_ROAMING_PROMPT"/>
    <SCREEN id="SCR_ID_DCD_MANUAL_UPDATE_PROMPT_WHEN_ROAMING"/>
    <SCREEN id="SCR_ID_DCD_SETTING_SWITCH_OFF_PROMPT"/>
    <SCREEN id="SCR_ID_DCD_MANUAL_UPDATE_STORAGE_FULL_PROMPT"/>
    <SCREEN id="SCR_ID_DCD_UPDATE_PROGRESS"/>
    <SCREEN id="SCR_ID_DCD_UPDATE_LOG"/>
    <SCREEN id="SCR_ID_DCD_HELP"/>
    <SCREEN id="SCR_ID_DCD_IMAGE_LIST"/>
    <SCREEN id="SCR_ID_DCD_MANUAL_UPDATE_FAIL_PROMPT"/>
    <SCREEN id="SCR_ID_DCD_END"/>

    <!------------------------------------------------------Callback Mgr Resource Area------------------------------------------------------->    
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_dcd_sleepin_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_dcd_sleepout_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_dcd_sim_unavailable_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_dcd_network_indication"/>
	<RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="mmi_dcd_network_indication"/>
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_dcd_finalize_evt_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_dcd_flymode_switch_finish_hdlr"/>

</APP>

#endif /* defined(__MMI_OP01_DCD__) */

