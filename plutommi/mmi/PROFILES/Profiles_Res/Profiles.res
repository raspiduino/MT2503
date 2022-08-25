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
*  Profiles.res
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   
*
* Author:
* -------
*  Xudong Sun
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
 *
 * 03 21 2014 deepak.singhrawat
 * [MAUI_03458470] [SLIM]6260 Slim Checkin
 * corrected the macro and complete telephony patch.
 *
 * 10 27 2013 deepak.singhrawat
 * [MAUI_03463864] [Pluto Slim Phase3 IT Test] [11BW1332OF_6260Slim_Dev][Free test][Profile]when change profile, the popup string is error
 * .
 *
 * 10 21 2013 deepak.singhrawat
 * [MAUI_03463180] [Pluto Slim][MTI] Pluto slim checkin to 11C for MTI
 * .
 *
 * 01 14 2013 deepak.singhrawat
 * [MAUI_03313198] [MT6260 pre-SQC][Auto_test][ART][1] Assert fail: Caller Address: 0x105db6e1 Line: 2342 0x122, 0x126, 0x8 - MMI
 * .
 *
 * 12 25 2012 deepak.singhrawat
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 11 27 2012 deepak.singhrawat
 * [MAUI_03258560] [MTI] Pack back Pluto slim modification into 11BW1224_RESTRICT_SP
 * unused string checkin to 11B.
 *
 * 06 15 2012 boli.li
 * [MAUI_03161514] it should be incoming all ringtone in this case
 * .
 *
 * 06 11 2012 boli.li
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 04 19 2012 boli.li
 * [MAUI_03171020] remove timer id
 * .
 *
 * 04 18 2012 boli.li
 * [MAUI_03171020] remove timer id
 * .
 *
 * 03 08 2012 boli.li
 * [MAUI_03143458] [FTE2.0][Dynamic_SIM_DYNAMIC_UI_and_SIM_name]New feature check in
 * .
 *
 * 11 08 2011 boli.li
 * [MAUI_03074522] [Need Patch][Build Error] MAUI.W11.45 build error for ASTRO21V1_DEMO_tdd128dpa
 * .
 *
 * 11 04 2011 boli.li
 * [MAUI_03068776] my style can be rename as blank
 * .
 *
 * 08 31 2011 bingbing.ma
 * [MAUI_03017670] [sndrec/profile]: change lauch for fte using cosmos icon
 * .
 *
 * 08 04 2011 bingbing.ma
 * [MAUI_02998117] [BW FWT]ȩ¾°ģʽµétemĻ³Ʋ»?¹»¸��?�»µŌ⊾?Ϣ
 * .
 *
 * 07 14 2011 zhanlei.feng
 * [MAUI_02984036] change icon name
 * .
 *
 * 07 13 2011 zhanlei.feng
 * [MAUI_02982844] [User profile]¸�龰ģʽµéconȫ²¿¹Ҵ?? .
 *
 * 06 29 2011 zhanlei.feng
 * [MAUI_02973419] replace STR_ID_PROF_VIDEO_CALL_TONE to STR_GLOBAL_VIDEO_CALL
 * .
 *
 * 06 29 2011 zhanlei.feng
 * [MAUI_02973218] modify sLIM CODE
 * .
 *
 * 06 28 2011 zhanlei.feng
 * [MAUI_02972610] check in code (add and delete profile) for cmcc td project
 * .
 *
 * 06 15 2011 zhanlei.feng
 * [MAUI_02962623] modify slim code
 * .
 *
 * 06 09 2011 zhanlei.feng
 * [MAUI_02959103] roll back compile option " __PLUTO_MMI_PACKAGE__"
 * .
 *
 * 06 09 2011 zhanlei.feng
 * [MAUI_02958511] check in CMCC TD WB FWT project code
 * .
 *
 * 06 08 2011 zhanlei.feng
 * [MAUI_02957385] change options "__MMI_PROF_SLIM_SUPPORT" to slim option
 * .
 *
 * 06 07 2011 zhanlei.feng
 * [MAUI_02957019] modify profiles code for slim
 * .
 *
 * 06 02 2011 zhanlei.feng
 * [MAUI_02943492] Inline Slim for 3232
 * .
 *
 * 02 24 2011 zhanlei.feng
 * [MAUI_02653189] remove unused resource res in cosmos project
 * .
 *
 * 02 16 2011 zhanlei.feng
 * [MAUI_02651910] remove mainnenu res
 * .
 *
 * 12 28 2010 zhanlei.feng
 * [MAUI_02845196] 1032 ȩ¾°ģʽo?·¨ʨ?clamshel¥ʹ
 * .
 *
 * 12 14 2010 zhanlei.feng
 * [MAUI_02644009] [Gemini +] check in Profiles cui related files
 * .
 *
 * 12 14 2010 zhanlei.feng
 * [MAUI_02644004] RHR check in MAUI
 * .
 *
 * 11 04 2010 zhanlei.feng
 * [MAUI_02727290] [user profiles] rename has no change nor any remind ,it is unreasonable
 * .
 *
 * 10 28 2010 zhanlei.feng
 * [MAUI_02726785] the question mark should use full type in SC
 * .
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 10 20 2010 baoqi.liu
 * [MAUI_02638257] [@general]check in for User profile build error
 * .
 *
 * 10 12 2010 xudong.sun
 * [MAUI_02441901] Rings plays but pop up "earphone plugged in " comes later
 * .
 *
 * 09 26 2010 xudong.sun
 * [MAUI_02636052] Check in FTE touch feedback support
 * .
 *
 * Jun 21 2010 mtk80223
 * [MAUI_02288711] the default value is wrong
 * 
 *
 * May 31 2010 mtk80223
 * [MAUI_02289601] [IMPS] display blank
 * 
 *
 * May 17 2010 mtk80223
 * [MAUI_02193665] [User profiles] New Profiles app check in
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "custom_equipment.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_PROFILES"
#ifdef __MMI_APP_MANAGER_SUPPORT__
    package_name = "native.mtk.profile"
    name = "STR_ID_PROF_CAPTION"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    img = "MAIN_MENU_USER_PROFILES_ICON"
#endif
    launch = "mmi_profiles_launch_function"
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
>
    
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="MainMenuDef.h"/>
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
#if defined( __PLUTO_MMI_PACKAGE__ )
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>
#endif

    /* Basic menu style profiles UI support */
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__INLINE_CUI_SLIM_SELECT_ITEM_STYLE__)
    #define __MMI_PROF_BASIC_UI_STYLE__
#endif

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#if defined( __PLUTO_MMI_PACKAGE__ )
    <STRING id="STR_ID_PROF_CAPTION"/>

    <STRING id="STR_ID_PROF_GENERAL"/>
    <STRING id="STR_ID_PROF_SILENT"/>
#ifndef __MMI_MAINLCD_96X64__
    <STRING id="STR_ID_PROF_MEETING"/>
    <STRING id="STR_ID_PROF_OUTDOOR"/>
#endif
#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)    
    <STRING id="STR_ID_PROF_MY_STYLE"/>
#endif    

#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    <STRING id="STR_ID_PROF_NEW_PROF"/>
    <STRING id="STR_ID_PROF_ADD_PROFILE"/>
#endif

#ifndef __MMI_PROF_SLIM_PROFILES__
    <STRING id="STR_ID_PROF_GENERAL_ACTIVATED"/>
    <STRING id="STR_ID_PROF_SILENT_ACTIVATED"/>
#ifndef __MMI_MAINLCD_96X64__
    <STRING id="STR_ID_PROF_MEETING_ACTIVATED"/>
    <STRING id="STR_ID_PROF_OUTDOOR_ACTIVATED"/>
#endif
#endif

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) || defined(__MMI_PROF_SLIM_PROFILES__)
    <STRING id="STR_ID_PROF_MODE_ACTIVATED"/>
#endif

    <STRING id="STR_ID_PROF_CUSTOMIZE"/>
    
    <STRING id="STR_ID_PROF_ALERT_TYPE"/>
    <STRING id="STR_ID_PROF_RING_ONLY"/>
    <STRING id="STR_ID_PROF_VIB_ONLY"/>
    <STRING id="STR_ID_PROF_VIB_AND_RING"/>
    <STRING id="STR_ID_PROF_VIB_THEN_RING"/>
    
    <STRING id="STR_ID_PROF_RING_TYPE"/>
    <STRING id="STR_ID_PROF_RINGING"/>
#ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__
    <STRING id="STR_ID_PROF_ASCENDING"/>
#endif
    <STRING id="STR_ID_PROF_BEEP_ONCE"/>

    <STRING id="STR_ID_PROF_RING_TONE"/>
    <STRING id="STR_ID_PROF_SIM1_RING_TONE"/>
    <STRING id="STR_ID_PROF_SIM2_RING_TONE"/>    
    <STRING id="STR_ID_PROF_SIM3_RING_TONE"/>    
    <STRING id="STR_ID_PROF_SIM4_RING_TONE"/>    

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    <STRING id="STR_ID_PROF_SIM1"/>
    <STRING id="STR_ID_PROF_SIM2"/>
    <STRING id="STR_ID_PROF_SIM3"/>
    <STRING id="STR_ID_PROF_SIM4"/>

#endif

#ifdef __OP01_FWPBW__
    <STRING id="STR_ID_PROF_POWER_ON_OFF"/>
    <STRING id="STR_ID_PROF_POWER_ON_OFF_TONE"/>
    <STRING id="STR_ID_PROF_SOUND_SET_SILENT"/>
    <STRING id="STR_ID_PROF_TDBW_INCOMING_CALL_RING"/>
    <STRING id="STR_ID_PROF_TDBW_MSG_RING"/>
    <STRING id="STR_ID_PROF_TDBW_KEYPAD_TONE"/>
    <STRING id="STR_ID_PROF_TDBW_SYSTEM_TONE"/>
#endif

#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
    <STRING id="STR_ID_PROF_VOICE_TONE"/>
#endif
    <STRING id="STR_ID_PROF_RING_VOL"/>
#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
    <STRING id="STR_ID_PROF_SIM1_MSG_TONE"/>
    <STRING id="STR_ID_PROF_SIM2_MSG_TONE"/>
#endif 
#if (SRV_PROF_SMS_TONE_AMOUNT > 2)
    <STRING id="STR_ID_PROF_SIM3_MSG_TONE"/>
#endif 
#if (SRV_PROF_SMS_TONE_AMOUNT > 3)
    <STRING id="STR_ID_PROF_SIM4_MSG_TONE"/>
#endif 
    <STRING id="STR_ID_PROF_MSG_VOL"/>
#endif

    <STRING id="STR_ID_PROF_KEYPAD_TONE"/>
#if defined( __PLUTO_MMI_PACKAGE__ )    
    <STRING id="STR_ID_PROF_CLICK"/>
    <STRING id="STR_ID_PROF_TONE"/>
    
#if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )
    <STRING id="STR_ID_PROF_KEYPAD_HUMAN_VOICE_1"/>
    <STRING id="STR_ID_PROF_KEYPAD_HUMAN_VOICE_2"/>
    <STRING id="STR_ID_PROF_KEYPAD_HUMAN_VOICE_3"/>
    <STRING id="STR_ID_PROF_KEYPAD_HUMAN_VOICE_4"/>
    <STRING id="STR_ID_PROF_KEYPAD_HUMAN_VOICE_5"/>
    <STRING id="STR_ID_PROF_KEYPAD_HUMAN_VOICE_6"/>
#endif
#if defined( __MMI_CUST_KEYPAD_TONE__ )
    <STRING id="STR_ID_PROF_KEYPAD_TONE_CUST_1"/>
    <STRING id="STR_ID_PROF_KEYPAD_TONE_CUST_2"/>
    <STRING id="STR_ID_PROF_KEYPAD_TONE_CUST_3"/>
    <STRING id="STR_ID_PROF_KEYPAD_TONE_CUST_4"/>
    <STRING id="STR_ID_PROF_KEYPAD_TONE_CUST_5"/>
    <STRING id="STR_ID_PROF_KEYPAD_TONE_CUST_6"/>
#endif

    <STRING id="STR_ID_PROF_KEYPAD_VOL"/>
#if !defined(__MMI_POWER_ON_OFF_MUTE__) && !defined(__MMI_POWER_ON_OFF_NO_CUSTOMIZE__)
    <STRING id="STR_ID_PROF_POWER_ON_TONE"/>
    <STRING id="STR_ID_PROF_POWER_OFF_TONE"/>
#endif
#ifdef __MMI_CLAMSHELL__
    <STRING id="STR_ID_PROF_COVER_OPEN_TONE"/>
    <STRING id="STR_ID_PROF_COVER_CLOSE_TONE"/>
#endif
    <STRING id="STR_ID_PROF_SYSTEM_ALERT"/>

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    <STRING id="STR_ID_PROF_INTELLIGENT_CALL_ALERT"/>
#endif

#if !defined(HARDWARE_LED_NOT_SUPPORT)
    <STRING id="STR_ID_PROF_STATUS_LED"/>
    <STRING id="STR_ID_PROF_COLOR_PATTERN_1"/>
    <STRING id="STR_ID_PROF_COLOR_PATTERN_2"/>
    <STRING id="STR_ID_PROF_COLOR_PATTERN_3"/>
    <STRING id="STR_ID_PROF_COLOR_PATTERN_4"/>
    <STRING id="STR_ID_PROF_COLOR_PATTERN_5"/>
    <STRING id="STR_ID_PROF_COLOR_PATTERN_6"/>
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__	
    <STRING id="STR_ID_PROF_CURR_THEME"/>
#endif

    <STRING id="STR_ID_PROF_CHANGE"/>
#endif /*#if defined( __PLUTO_MMI_PACKAGE__ )*/

    <STRING id="STR_ID_PROF_SELECT_FROM_FILE"/>

    <STRING id="STR_ID_PROF_FILE_TOO_LARGE"/>
#if defined( __PLUTO_MMI_PACKAGE__ )
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    <STRING id="STR_ID_PROF_NAME_EMPTY"/>
    <STRING id="STR_ID_PROF_NAME_INVALID"/>
 #endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
    <STRING id="STR_ID_PROF_TOUCH_VIB"/>
    <STRING id="STR_ID_PROF_TOUCH_VOL"/>
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
    <STRING id="STR_ID_PROF_LEVEL_1"/>
    <STRING id="STR_ID_PROF_LEVEL_2"/>
    <STRING id="STR_ID_PROF_LEVEL_3"/>
#endif
#endif

<STRING id="STR_ID_PROF_QUESTION_MARK"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#ifdef __MMI_APP_MANAGER_SUPPORT__
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    <IMAGE id="MAIN_MENU_USER_PROFILES_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Profile.PNG"</IMAGE>
#endif
#endif /* __MMI_APP_MANAGER_SUPPORT__ */

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__OP01_FWPBW__)
    <IMAGE id="IMG_ID_PROF_GENERAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_POG.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PROF_SILENT" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_SILENT.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PROF_MEETING" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_PMEET.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PROF_OUTDOOR" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_POUT.bmp"</IMAGE>
    <IMAGE id="IMG_ID_PROF_MY_STYLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_UserDefine.bmp"</IMAGE>
    #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    <IMAGE id="IMG_ID_PROF_ADD" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_PADD.bmp"</IMAGE>
    #endif
#elif defined(__OP01_FWPBW__) 
    <IMAGE id="IMG_ID_PROF_GENERAL" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_POG.BMP"</IMAGE>
    <IMAGE id="IMG_ID_PROF_SILENT" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_SILENT.BMP"</IMAGE>
    <IMAGE id="IMG_ID_PROF_MEETING" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_PMEET.BMP"</IMAGE>
    <IMAGE id="IMG_ID_PROF_OUTDOOR" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_POUT.BMP"</IMAGE>
    <IMAGE id="IMG_ID_PROF_MY_STYLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Profile\\\\SB_UserDefine.bmp"</IMAGE>
#endif
#endif/*#if defined( __PLUTO_MMI_PACKAGE__ )*/

#if !defined(__MMI_PROF_BASIC_UI_STYLE__) && !defined(__OP01_FWPBW__)    
    <IMAGE id="IMG_ID_PROF_TITLEE" >CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_PR.bmp"</IMAGE>
#elif defined(__OP01_FWPBW__)
    <IMAGE id="IMG_ID_PROF_TITLEE" >CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_PR.BMP"</IMAGE>
#endif
#if defined( __PLUTO_MMI_PACKAGE__ )
#ifndef __MMI_PROF_SLIM_PROFILES__
    <IMAGE id="IMG_ID_PROF_NO_IMAGE" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
#endif
#ifndef  __MMI_MAINLCD_96X64__
    <IMAGE id="IMG_ID_PROF_ACTIVATED" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.BMP"</IMAGE>
#else
    <IMAGE id="IMG_ID_PROF_ACTIVATED" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_S.BMP"</IMAGE>
#endif
#endif

    <!-----------------------------------------------------Audio Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#if defined( __PLUTO_MMI_PACKAGE__ )
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    #ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    <MENUITEM id="MENU_ID_PROF_GENERAL" str="STR_ID_PROF_GENERAL" img="IMG_ID_PROF_GENERAL"/>
    <MENUITEM id="MENU_ID_PROF_SILENT" str="STR_ID_PROF_SILENT" img="IMG_ID_PROF_SILENT"/>
    <MENUITEM id="MENU_ID_PROF_MEETING" str="STR_ID_PROF_MEETING" img="IMG_ID_PROF_MEETING"/>
    <MENUITEM id="MENU_ID_PROF_OUTDOOR" str="STR_ID_PROF_OUTDOOR" img="IMG_ID_PROF_OUTDOOR"/>
    <MENUITEM id="MENU_ID_PROF_MY_STYLE" str="STR_ID_PROF_MY_STYLE" img="IMG_ID_PROF_MY_STYLE"/>
    #else
    <MENUITEM id="MENU_ID_PROF_ADD_PROF"/>  /*need new image*/
    <MENUITEM id="MENU_ID_PROF_GENERAL"/>
    <MENUITEM id="MENU_ID_PROF_SILENT"/>
    <MENUITEM id="MENU_ID_PROF_MEETING"/>
    <MENUITEM id="MENU_ID_PROF_OUTDOOR"/>
    <MENUITEM id="MENU_ID_PROF_NEW_1"/>
    <MENUITEM id="MENU_ID_PROF_NEW_2"/>
    <MENUITEM id="MENU_ID_PROF_NEW_3"/>
    <MENUITEM id="MENU_ID_PROF_NEW_4"/>
    <MENUITEM id="MENU_ID_PROF_NEW_5"/>
    <MENUITEM id="MENU_ID_PROF_NEW_6"/>
    <MENUITEM id="MENU_ID_PROF_NEW_7"/>
    <MENUITEM id="MENU_ID_PROF_NEW_8"/>
    <MENUITEM id="MENU_ID_PROF_NEW_9"/>
    <MENUITEM id="MENU_ID_PROF_NEW_10"/>
    #endif
#else
    <MENUITEM id="MENU_ID_PROF_GENERAL" str="STR_ID_PROF_GENERAL"/>
#ifndef __MMI_MAINLCD_96X64__ 
    <MENUITEM id="MENU_ID_PROF_SILENT" str="STR_ID_PROF_SILENT"/>
    <MENUITEM id="MENU_ID_PROF_MEETING" str="STR_ID_PROF_MEETING"/>
    <MENUITEM id="MENU_ID_PROF_OUTDOOR" str="STR_ID_PROF_OUTDOOR"/>    
#endif    // __MMI_MAINLCD_96X64__
#endif
  
	<MENU id = "MAIN_MENU_PROFILES_MENUID" type = "APP_MAIN" 
	      str = "STR_ID_PROF_CAPTION" img="MAIN_MENU_PROFILES_ICON" 
	      highlight = "highlight_mainmenu_profiles"
	      shortcut="ON" shortcut_img="MAIN_MENU_PROFILES_ICON" launch="mmi_profiles_entry_main_screen">
	        <MENUITEM_ID>MENU_ID_PROF_ADD_PROF</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_GENERAL</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_SILENT</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_MEETING</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_OUTDOOR</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_MY_STYLE</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_1</MENUITEM_ID>        
                <MENUITEM_ID>MENU_ID_PROF_NEW_2</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_3</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_4</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_5</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_6</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_7</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_8</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_9</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_PROF_NEW_10</MENUITEM_ID>
	</MENU>

    <MENUITEM id="MENU_ID_PROF_ACTIVATE" str="STR_GLOBAL_ACTIVATE"/>
    <MENUITEM id="MENU_ID_PROF_CUSTOMIZE" str="STR_ID_PROF_CUSTOMIZE"/>
#ifndef __MMI_MAINLCD_96X64__
    <MENUITEM id="MENU_ID_PROF_RESET" str="STR_GLOBAL_RESET"/>
#endif    // __MMI_MAINLCD_96X64__
#ifndef __MMI_PROF_BASIC_UI_STYLE__
    <MENUITEM id="MENU_ID_PROF_RENAME" str="STR_GLOBAL_RENAME"/>
#endif
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    <MENUITEM id="MENU_ID_PROF_DELETE" str="STR_GLOBAL_DELETE"/>
#endif
    <MENU id = "MENU_ID_PROF_MAIN_OPTIONS" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_PROF_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_CUSTOMIZE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RESET</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RENAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_DELETE</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_PROF_CHANGE" str="STR_ID_PROF_CHANGE"/>
    <MENUITEM id="MENU_ID_PROF_SAVE" str="STR_GLOBAL_SAVE"/>
#ifdef __OP01_FWPBW__
    <MENU id = "MENU_ID_PROF_CUSTOMIZE_OPTIONS" type = "OPTION">
#else
	<MENU id = "MENU_ID_PROF_CUSTOMIZE_OPTIONS" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
#endif
		<MENUITEM_ID>MENU_ID_PROF_CHANGE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_SAVE</MENUITEM_ID>
	</MENU>
#ifndef __OP01_FWPBW__
    <MENUITEM id="MENU_ID_PROF_RING_ONLY" str="STR_ID_PROF_RING_ONLY"/>
    <MENUITEM id="MENU_ID_PROF_VIB_ONLY" str="STR_ID_PROF_VIB_ONLY"/>
    <MENUITEM id="MENU_ID_PROF_VIB_AND_RING" str="STR_ID_PROF_VIB_AND_RING"/>
    <MENUITEM id="MENU_ID_PROF_VIB_THEN_RING" str="STR_ID_PROF_VIB_THEN_RING"/>
    
	<MENU id = "MENU_ID_PROF_ALERT_TYPE" type = "APP_SUB" str = "STR_ID_PROF_ALERT_TYPE">
		<MENUITEM_ID>MENU_ID_PROF_RING_ONLY</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_VIB_ONLY</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_VIB_AND_RING</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_VIB_THEN_RING</MENUITEM_ID>
	</MENU>

    <MENUITEM id="MENU_ID_PROF_RINGING" str="STR_ID_PROF_RINGING"/>
#ifdef __MMI_AUDIO_CRESCENDO_SUPPORT__
    <MENUITEM id="MENU_ID_PROF_ASCENDING" str="STR_ID_PROF_ASCENDING"/>
#endif    
    <MENUITEM id="MENU_ID_PROF_BEEP_ONCE" str="STR_ID_PROF_BEEP_ONCE"/>
    
	<MENU id = "MENU_ID_PROF_RING_TYPE" type = "APP_SUB" str = "STR_ID_PROF_RING_TYPE">
		<MENUITEM_ID>MENU_ID_PROF_RINGING</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_ASCENDING</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_BEEP_ONCE</MENUITEM_ID>
	</MENU>

    <MENUITEM id="MENU_ID_PROF_SILENT_TONE" str="STR_GLOBAL_SILENT"/>
    <MENUITEM id="MENU_ID_PROF_CLICK" str="STR_ID_PROF_CLICK"/>
    <MENUITEM id="MENU_ID_PROF_TONE" str="STR_ID_PROF_TONE"/>
#if defined( __MMI_HUMAN_VOICE_KEYPAD_TONE__ )
    <MENUITEM id="MENU_ID_PROF_KEYPAD_HUMAN_VOICE_BEGIN"/>
    <MENUITEM id="MENU_ID_PROF_KEYPAD_HUMAN_VOICE_1" str="STR_ID_PROF_KEYPAD_HUMAN_VOICE_1"/>
    <MENUITEM id="MENU_ID_PROF_KEYPAD_HUMAN_VOICE_END"/>
#endif
#if defined( __MMI_CUST_KEYPAD_TONE__ )
    <MENUITEM id="MENU_ID_PROF_KEYPAD_TONE_CUST_BEGIN"/>
    <MENUITEM id="MENU_ID_PROF_KEYPAD_TONE_CUST_1" str="STR_ID_PROF_KEYPAD_TONE_CUST_1"/>
    <MENUITEM id="MENU_ID_PROF_KEYPAD_TONE_CUST_END"/>
#endif

	<MENU id = "MENU_ID_PROF_KEYPAD_TONE" type = "APP_SUB" str = "STR_ID_PROF_KEYPAD_TONE">
	        <MENUITEM_ID>MENU_ID_PROF_SILENT_TONE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_CLICK</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_TONE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_KEYPAD_HUMAN_VOICE_1</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_KEYPAD_TONE_CUST_1</MENUITEM_ID>
	</MENU>
#endif

#ifdef __OP01_FWPBW__
    <MENUITEM id="MENU_ID_PROF_POWER_ONOFF_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_PROF_POWER_ONOFF_OFF" str="STR_GLOBAL_OFF"/>
   
    <MENU id = "MENU_ID_PROF_POWER_ONOFF" type = "APP_SUB">
        <MENUITEM_ID>MENU_ID_PROF_POWER_ONOFF_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_POWER_ONOFF_OFF</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_PROF_KEYPAD_TONE_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_PROF_KEYPAD_TONE_OFF" str="STR_GLOBAL_OFF"/>
    
    <MENU id = "MENU_ID_PROF_KEYPAD_TONE" type = "APP_SUB">
        <MENUITEM_ID>MENU_ID_PROF_KEYPAD_TONE_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_KEYPAD_TONE_OFF</MENUITEM_ID>
    </MENU>
#endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
#ifdef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
    <MENUITEM id="MENU_ID_PROF_TOUCH_OFF" str="STR_GLOBAL_OFF"/>
    <MENUITEM id="MENU_ID_PROF_TOUCH_LEVEL_1" str="STR_ID_PROF_LEVEL_1"/>
    <MENUITEM id="MENU_ID_PROF_TOUCH_LEVEL_2" str="STR_ID_PROF_LEVEL_2"/>
    <MENUITEM id="MENU_ID_PROF_TOUCH_LEVEL_3" str="STR_ID_PROF_LEVEL_3"/>

  	<MENU id = "MENU_ID_PROF_TOUCH_VIB" type = "APP_SUB" str = "STR_ID_PROF_TOUCH_VIB">
	    <MENUITEM_ID>MENU_ID_PROF_TOUCH_OFF</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_TOUCH_LEVEL_1</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_TOUCH_LEVEL_2</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_TOUCH_LEVEL_3</MENUITEM_ID>
	</MENU>
#else
    <MENUITEM id="MENU_ID_PROF_TOUCH_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_PROF_TOUCH_OFF" str="STR_GLOBAL_OFF"/>

  	<MENU id = "MENU_ID_PROF_TOUCH_VIB" type = "APP_SUB" str = "STR_ID_PROF_TOUCH_VIB">
	    <MENUITEM_ID>MENU_ID_PROF_TOUCH_ON</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_TOUCH_OFF</MENUITEM_ID>
	</MENU>
#endif
#endif

#ifndef __MMI_MAINLCD_96X64__
    <MENUITEM id="MENU_ID_PROF_SYSTEM_ALERT_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_PROF_SYSTEM_ALERT_OFF" str="STR_GLOBAL_OFF"/>

#ifdef __OP01_FWPBW__
    <MENU id = "MENU_ID_PROF_SYSTEM_ALERT" type = "APP_SUB">
#else
	<MENU id = "MENU_ID_PROF_SYSTEM_ALERT" type = "APP_SUB" str = "STR_ID_PROF_SYSTEM_ALERT">
#endif
		<MENUITEM_ID>MENU_ID_PROF_SYSTEM_ALERT_ON</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_SYSTEM_ALERT_OFF</MENUITEM_ID>
	</MENU>
#endif    // __MMI_MAINLCD_96X64__
	
#if defined(__MMI_PROF_BASIC_UI_STYLE__) || defined(__OP01_FWPBW__)	
    <MENUITEM id="MENU_ID_PROF_RING_1"/>
    <MENUITEM id="MENU_ID_PROF_RING_2"/>
    <MENUITEM id="MENU_ID_PROF_RING_3"/>
    <MENUITEM id="MENU_ID_PROF_RING_4"/>
    <MENUITEM id="MENU_ID_PROF_RING_5"/>
    <MENUITEM id="MENU_ID_PROF_RING_6"/>
    <MENUITEM id="MENU_ID_PROF_RING_7"/>
    <MENUITEM id="MENU_ID_PROF_RING_8"/>
    <MENUITEM id="MENU_ID_PROF_RING_9"/>
    <MENUITEM id="MENU_ID_PROF_RING_10"/>
    <MENUITEM id="MENU_ID_PROF_RING_11"/>
    <MENUITEM id="MENU_ID_PROF_RING_12"/>
    <MENUITEM id="MENU_ID_PROF_RING_13"/>
    <MENUITEM id="MENU_ID_PROF_RING_14"/>
    <MENUITEM id="MENU_ID_PROF_RING_15"/>
    <MENUITEM id="MENU_ID_PROF_RING_16"/>
    <MENUITEM id="MENU_ID_PROF_RING_17"/>
    <MENUITEM id="MENU_ID_PROF_RING_18"/>
    <MENUITEM id="MENU_ID_PROF_RING_19"/>
    <MENUITEM id="MENU_ID_PROF_RING_20"/>
    <MENUITEM id="MENU_ID_PROF_RING_END"/>
    #if defined(__MMI_FILE_MANAGER__)
    <MENUITEM id="MENU_ID_PROF_OPEN_GALLERY"/>
    #endif /* #if defined(__MMI_FILE_MANAGER__) */
    <MENUITEM id="MENU_ID_PROF_TONE_SILENT"/>
    <MENUITEM id="MENU_ID_PROF_TONE_1"/>
    <MENUITEM id="MENU_ID_PROF_TONE_2"/>
    <MENUITEM id="MENU_ID_PROF_TONE_3"/>
    <MENUITEM id="MENU_ID_PROF_TONE_4"/>
    <MENUITEM id="MENU_ID_PROF_TONE_5"/>
    <MENUITEM id="MENU_ID_PROF_TONE_6"/>
    <MENUITEM id="MENU_ID_PROF_TONE_7"/>
    <MENUITEM id="MENU_ID_PROF_TONE_8"/>
    <MENUITEM id="MENU_ID_PROF_TONE_9"/>
    <MENUITEM id="MENU_ID_PROF_TONE_10"/>
    
    <MENU id = "MENU_ID_TONE_SELECTOR" type = "APP_SUB">
        <MENUITEM_ID>MENU_ID_PROF_RING_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_5</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_6</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_7</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_8</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_9</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_10</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_11</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_12</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_13</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_14</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_15</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_16</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_17</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_18</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_19</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_RING_20</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_OPEN_GALLERY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_SILENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_4</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_5</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_6</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_7</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_8</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_9</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_PROF_TONE_10</MENUITEM_ID>
    </MENU>
#endif

#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    <MENUITEM id="MENU_ID_PROF_INTELLIGENT_CALL_ALERT_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_PROF_INTELLIGENT_CALL_ALERT_OFF" str="STR_GLOBAL_OFF"/>
	<MENU id = "MENU_ID_PROF_INTELLIGENT_CALL_ALERT" type = "APP_SUB" str = "STR_ID_PROF_INTELLIGENT_CALL_ALERT">
		<MENUITEM_ID>MENU_ID_PROF_INTELLIGENT_CALL_ALERT_ON</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_INTELLIGENT_CALL_ALERT_OFF</MENUITEM_ID>
	</MENU>
#endif

#if !defined(HARDWARE_LED_NOT_SUPPORT)
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_BEGIN"/>
    <MENUITEM id="MENU_ID_PROF_ITEM_NONE" str="STR_GLOBAL_NONE"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_1" str="STR_ID_PROF_COLOR_PATTERN_1"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_2" str="STR_ID_PROF_COLOR_PATTERN_2"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_3" str="STR_ID_PROF_COLOR_PATTERN_3"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_4" str="STR_ID_PROF_COLOR_PATTERN_4"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_5" str="STR_ID_PROF_COLOR_PATTERN_5"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_6" str="STR_ID_PROF_COLOR_PATTERN_6"/>
    <MENUITEM id="MENU_ID_PROF_COLOR_PATTERN_END"/>
    
	<MENU id = "MENU_ID_PROF_STATUE_LED" type = "APP_SUB" str = "STR_ID_PROF_STATUS_LED">
	    <MENUITEM_ID>MENU_ID_PROF_ITEM_NONE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_COLOR_PATTERN_1</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_COLOR_PATTERN_2</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_COLOR_PATTERN_3</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_COLOR_PATTERN_4</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_COLOR_PATTERN_5</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_PROF_COLOR_PATTERN_6</MENUITEM_ID>		
	</MENU>
#endif

    <MENUITEM id="MENU_ID_PROF_USE_AS_RINGTONE" str="STR_ID_PROF_RING_TONE"/>
    <MENUITEM id="MENU_ID_PROF_USE_AS_SIM1_RINGTONE" str="STR_ID_PROF_SIM1_RING_TONE"/>
    <MENUITEM id="MENU_ID_PROF_USE_AS_SIM2_RINGTONE" str="STR_ID_PROF_SIM2_RING_TONE"/>
    <MENUITEM id="MENU_ID_PROF_USE_AS_SIM3_RINGTONE" str="STR_ID_PROF_SIM3_RING_TONE"/>
    <MENUITEM id="MENU_ID_PROF_USE_AS_SIM4_RINGTONE" str="STR_ID_PROF_SIM4_RING_TONE"/>

#ifdef __MMI_VIDEO_TELEPHONY__    
    <MENUITEM id="MENU_ID_PROF_USE_AS_VIDEO_TONE" str="STR_GLOBAL_DIAL_VIDEO_CALL"/>
#endif

    <!--------------------------Event Handler----------------->
#if defined(__MMI_FM_RADIO__)
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_fmrdo_earphone_notify_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_fmrdo_earphone_notify_hdlr"/>
#endif

#if (defined(__MMI_MAINLCD_96X64__) || defined(__MMI_PROF_SLIM_PROFILES__))
    <RECEIVER id="EVT_ID_SRV_PROF_VOL_CHANGED" proc="mmi_prof_volume_change_hdlr"/>
#endif
#endif

    <!--------------------------Timer----------------->
    <TIMER id="TIMER_PROFILES_TONE_PLAY"/>
    <TIMER id="KEY_VOL_TIMER_ID"/>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_PROFILES"/>
    <SCREEN id="SCR_KEY_TONE_VOLUME"/>

</APP>
#ifndef __OP01_FWPBW__
#if defined( __PLUTO_MMI_PACKAGE__ )
<FILE_TYPES>

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    <FILE_OPTION_HDLR option="MENU_ID_PROF_USE_AS_RINGTONE" enabler="mmi_prof_app_filemgr_option_enabler" handler="mmi_prof_app_filemgr_option_hdlr"/>
    <FILE_OPTION_HDLR option="MENU_ID_PROF_USE_AS_SIM1_RINGTONE" enabler="mmi_prof_app_filemgr_option_enabler" handler="mmi_prof_app_filemgr_option_hdlr"/>
    <FILE_OPTION_HDLR option="MENU_ID_PROF_USE_AS_SIM2_RINGTONE" enabler="mmi_prof_app_filemgr_option_enabler" handler="mmi_prof_app_filemgr_option_hdlr"/>
    <FILE_OPTION_HDLR option="MENU_ID_PROF_USE_AS_SIM3_RINGTONE" enabler="mmi_prof_app_filemgr_option_enabler" handler="mmi_prof_app_filemgr_option_hdlr"/>
    <FILE_OPTION_HDLR option="MENU_ID_PROF_USE_AS_SIM4_RINGTONE" enabler="mmi_prof_app_filemgr_option_enabler" handler="mmi_prof_app_filemgr_option_hdlr"/>

#ifdef __MMI_VIDEO_TELEPHONY__    
    <FILE_OPTION_HDLR option="MENU_ID_PROF_USE_AS_VIDEO_TONE" enabler="mmi_prof_app_filemgr_option_enabler" handler="mmi_prof_app_filemgr_option_hdlr"/>
#endif
#endif    /* __MMI_PROFILES_EXT_FILE_SUPPORT__ */

</FILE_TYPES>
#endif
#endif
