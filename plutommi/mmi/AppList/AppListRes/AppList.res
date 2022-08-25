/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  AppList.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the applist launcher homescreen resources.
 *
 * Author:
 * -------
 *  Stella Yang (mtk01564)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 13 2014 renxiao.zeng
 * [MAUI_03485009] [Daily build]C Launcher porting to pluto
 * .
 *
 * 04 16 2013 shengxi.xu
 * [MAUI_03379856] [SWPL Approved] BT Dialer Phase 3 check-in
 * .
 *
 * 03 04 2013 renxiao.zeng
 * [MAUI_03344449] [Exclude from W1308MP] [UIUE Performance] Main menu display takes much time as compare to MT6250
 * .
 *
 * 02 22 2013 renxiao.zeng
 * [MAUI_03343499] The ¡°TimeAlarm push¡± MIDlet is not uninstalled in this case
 * .
 *
 * 02 19 2013 renxiao.zeng
 * [MAUI_03331636] Assert fail: Caller Address: 0x10d6f5be Line: 276 - MMI File: plutommi\MMI\AppList\AppListSrc\AppListData.c, Function: mmi_applist_allocate_appmgr_list
 * fix bugs and check in app uninstall support
 *
 * 12 28 2012 renxiao.zeng
 * [MAUI_03272376] [New Feature] Fruit Launcher
 * .
 *
 * 12 25 2012 renxiao.zeng
 * [MAUI_03272376] [New Feature] Fruit Launcher Check in
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_LAUNCHER_APP_LIST__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"

/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_APPLIST">

    <APPCONCURRENT concurrent_w_order="SRV_VENUS_THEME, APP_IDLE" />

    <!----- Screen Resource Area ---------------------------------------------->

    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_APPLIST_APP_NAME"/>


    <!-- Image Resource Area--------------------------------------------------->

    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\AppList\\\\"
    <IMAGE id="IMG_ID_APPLIST_HILIGHT_FRAME">ROOT_PATH"hilight_frame.png"</IMAGE>
    
    #ifndef G2D_SUPPORT
    <IMAGE id="IMG_ID_APPLIST_ICON_BG">ROOT_PATH"icon_bg.png"</IMAGE>
    #endif

    #define INDICATOR_PATH CUST_IMG_PATH"\\\\MainLCD\\\\AppList\\\\Indicator\\\\"
    <IMAGE id="IMG_ID_APPLIST_INDICATOR_DOT_N">INDICATOR_PATH"Indicator_n.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_INDICATOR_DOT_H">INDICATOR_PATH"Indicator_h.png"</IMAGE>
    
    #define ROOT_ICONS_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherAppList\\\\MainMenu\\\\"
    <IMAGE id="IMG_ID_APPLIST_APP_DOWNLOAD_ICON">ROOT_ICONS_PATH"App_download.png"</IMAGE>
    #ifdef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
    <STRING id="STR_ID_APPLIST_UNINSTALL"/>
    <STRING id="STR_ID_APPLIST_UNINSTALLING"/>
    <STRING id="STR_ID_APPLIST_DELETE_FAILED"/>
    <STRING id="STR_ID_APPLIST_EXIT_RUNNING_APP"/>
    <STRING id="STR_ID_APPLIST_LIMIT_NUM"/>
    <IMAGE id="IMG_ID_APPLIST_APP_UNINSTALL_ICON">ROOT_ICONS_PATH"App_uninstall.png"</IMAGE>
    #endif
    
    <THEME>
    <IMAGE id="IMG_ID_APPLIST_ALARM_ICON">ROOT_ICONS_PATH"Alarm.png"</IMAGE>
#if defined(__MMI_AUDIO_PLAYER__)
    <IMAGE id="IMG_ID_APPLIST_APLY_ICON">ROOT_ICONS_PATH"AudioPlayer.png"</IMAGE>
#endif
#ifdef __MMI_AZAAN_ALARM__
    <IMAGE id="IMG_ID_APPLIST_AALARM_ICON">ROOT_ICONS_PATH"Azaan_alarm.png"</IMAGE>
#endif
#if defined(__MMI_SEARCH_WEB_BAIDU__)
    <IMAGE id="IMG_ID_APPLIST_BAIDU_ICON">ROOT_ICONS_PATH"Baidu.png"</IMAGE>
#endif
#ifdef __MMI_BT_SUPPORT__
    <IMAGE id="IMG_ID_APPLIST_BT_ICON">ROOT_ICONS_PATH"BlueTooth.png"</IMAGE>
#endif
#if defined(__MMI_CALCULATOR__)
    <IMAGE id="IMG_ID_APPLIST_CALCULATOR_ICON">ROOT_ICONS_PATH"Calculator.png"</IMAGE>
#endif
#if defined(__MMI_CALENDAR__)
    <IMAGE id="IMG_ID_APPLIST_CALENDAR_ICON">ROOT_ICONS_PATH"Calendar.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_CLOG_ICON">ROOT_ICONS_PATH"CallLog.png"</IMAGE>
#if defined(__MMI_CAMCORDER__)
    <IMAGE id="IMG_ID_APPLIST_CAMCORDER_ICON">ROOT_ICONS_PATH"Camcorder.png"</IMAGE>
#endif
#if defined (__MMI_CAMERA__)
    <IMAGE id="IMG_ID_APPLIST_CAMERA_ICON">ROOT_ICONS_PATH"Camera.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_CONNECT_ICON">ROOT_ICONS_PATH"Connect.png"</IMAGE>
#if defined(__MMI_CURRENCY_CONVERTER__)
    <IMAGE id="IMG_ID_APPLIST_CURRENCY_ICON">ROOT_ICONS_PATH"Currency.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_DIALER_ICON">ROOT_ICONS_PATH"Call.png"</IMAGE>
#ifdef __MMI_EBOOK_READER__
    <IMAGE id="IMG_ID_APPLIST_EBOOK_ICON">ROOT_ICONS_PATH"Ebook.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_EMAIL_ICON">ROOT_ICONS_PATH"Email.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_FMGR_ICON">ROOT_ICONS_PATH"FMGR.png"</IMAGE>
#ifdef __MMI_FM_RADIO__
    <IMAGE id="IMG_ID_APPLIST_FMRDO_ICON">ROOT_ICONS_PATH"FmRadio.png"</IMAGE>
#endif
#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__)
    <IMAGE id="IMG_ID_APPLIST_HEALTH_ICON">ROOT_ICONS_PATH"Health.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_IVIEWER_ICON">ROOT_ICONS_PATH"ImageViewer.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_JAVA_ICON">ROOT_ICONS_PATH"Java.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_MPLYER_ICON">ROOT_ICONS_PATH"MediaPlayer.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_MESSAGE_ICON">ROOT_ICONS_PATH"Message.png"</IMAGE>
#if defined(__MMI_ATV_SUPPORT__)
    <IMAGE id="IMG_ID_APPLIST_MTV_ICON">ROOT_ICONS_PATH"MobileTV.png"</IMAGE>
#endif
#ifdef __MMI_NOTE_APP__
    <IMAGE id="IMG_ID_APPLIST_NOTE_ICON">ROOT_ICONS_PATH"Note.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_PHB_ICON">ROOT_ICONS_PATH"Contact.png"</IMAGE>
#ifdef __MMI_PHOTOEDITOR__
    <IMAGE id="IMG_ID_APPLIST_PEDITOR_ICON">ROOT_ICONS_PATH"PhotoEditor.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_PROFILES_ICON">ROOT_ICONS_PATH"Profile.png"</IMAGE>
#ifdef __SYNCML_SUPPORT__
    <IMAGE id="IMG_ID_APPLIST_PSYNC_ICON">ROOT_ICONS_PATH"PSync.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_SYNC_ICON">ROOT_ICONS_PATH"Sync.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_SETTING_ICON">ROOT_ICONS_PATH"Setting.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_SERVICE_ICON">ROOT_ICONS_PATH"SAT.png"</IMAGE>
        <IMAGE id="IMG_ID_APPLIST_BARREL_ICON">ROOT_ICONS_PATH"barrel.png"</IMAGE>
    <IMAGE id="IMG_ID_APPLIST_RECORDER_ICON">ROOT_ICONS_PATH"SoundRecorder.png"</IMAGE>
#if defined(__MMI_TODOLIST__)
    <IMAGE id="IMG_ID_APPLIST_TODO_ICON">ROOT_ICONS_PATH"Tasks.png"</IMAGE>
#endif
#if defined(__MMI_UNIT_CONVERTER__)
    <IMAGE id="IMG_ID_APPLIST_UCONVERTER_ICON">ROOT_ICONS_PATH"Converter.png"</IMAGE>
#endif
#if defined(__MMI_VIDEO_PLAYER__)
    <IMAGE id="IMG_ID_APPLIST_VPLY_ICON">ROOT_ICONS_PATH"VideoPlayer.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_WIFI_ICON">ROOT_ICONS_PATH"WiFi.png"</IMAGE>
#ifdef __MMI_BROWSER_2__
    <IMAGE id="IMG_ID_APPLIST_BROWSER_ICON">ROOT_ICONS_PATH"Browser.png"</IMAGE>
#endif
#if defined (__MMI_WORLD_CLOCK__)
    <IMAGE id="IMG_ID_APPLIST_WCLOCK_ICON">ROOT_ICONS_PATH"WorldClock.png"</IMAGE>
#endif
#ifdef __SOCIAL_NETWORK_SUPPORT__
    <IMAGE id="IMG_ID_APPLIST_SNS_ICON">ROOT_ICONS_PATH"Sns.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_VCALL_ICON">ROOT_ICONS_PATH"VideoCall.png"</IMAGE>
#if defined(__MMI_3D_GAME_INTERGRAFX__)
    <IMAGE id="IMG_ID_APPLIST_3DGAME_ICON">ROOT_ICONS_PATH"3dGame.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_APPLIST_OPERA_ICON">ROOT_ICONS_PATH"Opera.png"</IMAGE>
#if defined(__MMI_VIDEO_RECORDER__)
    <IMAGE id="IMG_ID_APPLIST_VREC_ICON">ROOT_ICONS_PATH"VideoRecorder.png"</IMAGE>
#endif
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    <IMAGE id="IMG_ID_APPLIST_SETTINGMSG_ICON">ROOT_ICONS_PATH"setting_message.png"</IMAGE>
#endif
#ifdef __MMI_MOT_SUPPORT__
    <IMAGE id="IMG_ID_APPLIST_MOT_ICON">ROOT_ICONS_PATH"MOT.png"</IMAGE>
#endif
#if defined(__MMI_YOUTUBE_SHORTCUT__)
    <IMAGE id="IMG_ID_APPLIST_YOUTUBE_ICON">ROOT_ICONS_PATH"youtube.png"</IMAGE>
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
    <IMAGE id="IMG_ID_APPLIST_BT_DIALER_ICON">ROOT_ICONS_PATH"BT_DIALER.png"</IMAGE>  
#endif
    </THEME>
    
    <RECEIVER id="EVT_ID_IDLE_BEFORE_GROUP_EXIT" proc="mmi_applist_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_APPMGR_INSTALL_PACKAGE" proc="mmi_applist_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE" proc="mmi_applist_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE" proc="mmi_applist_event_handler"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_applist_event_handler"/>
</APP>

#endif /* defined(__MMI_LAUNCHER_APP_LIST__) */


