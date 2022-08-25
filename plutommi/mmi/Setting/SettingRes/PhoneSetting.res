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
 * PhoneSeetting.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Phone setting resource file with XML format.   
 *
 * Author:
 * -------
 *   Lina Yuan
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 20 2013 yunliu.mao
 * [MAUI_03480584] [BT Dialer] rename BT Box with LCD compile options
 * .[BT Dialer] rename BT Box with LCD compile options
 *
 * 10 22 2013 yunliu.mao
 * [MAUI_03463453] [11BW1332OF_6260Slim_Dev] check in 11c
 * .[11BW1332OF_6260Slim_Dev] check in 11c
 *
 * 10 19 2013 yunliu.mao
 * [MAUI_03463453] [11BW1332OF_6260Slim_Dev] check in 11c
 * .[11BW1332OF_6260Slim_Dev] check in 11c
 *
 * 10 11 2013 yunliu.mao
 * [MAUI_03462439] [BT box] BT box feature check in to 11C
 * .[BT box] BT box feature check in to 11C
 *
 * 03 22 2013 yunliu.mao
 * [MAUI_03363784] [SWPL Approved][Change feature]BT Dialer Package Check in
 * .setting menu hiden
 *
 * 03 12 2013 yunliu.mao
 * [MAUI_03333215] [MT6260] Can not acess internet after switch UART port from 1 to 2.
 * .[MT6260] Can not acess internet after switch UART port from 1 to 2.
 *
 * 01 02 2013 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * .
 *
 * 12 28 2012 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * .
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 12 25 2012 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * PhoneSetting  Slim check in 11B.
 *
 * 06 26 2012 xiangnan.qi
 * [MAUI_03162966] KEY launcher settting UE revise.
 * .
 *
 * 06 18 2012 xiangnan.qi
 * [MAUI_03162966] KEY launcher settting UE revise.
 * .for java code slim revise.
 *
 * 04 26 2012 xiangnan.qi
 * [MAUI_03175860] [Remove code] remove MMI contrast relation code, this feature already phase out
 * .
 *
 * 04 25 2012 xiangnan.qi
 * [MAUI_03174740] Add compile option for schedule power on off.
 * .
 *
 * 04 21 2012 yiping.xie
 * [MAUI_03169501] [UE] the item "auto keypad lock" should remove to display , and change the string to 'Screen auto lock"
 * .
 *
 * 04 05 2012 kuldeep.chaudhary
 * [MAUI_03136488] Checkins for IMEV3
 * Common Checkin for issue submitted on 12.13 for IMEv3
 *
 * 04 05 2012 xiangnan.qi
 * [MAUI_03162966] KEY launcher settting UE revise.
 * .
 *
 * 03 21 2012 kuldeep.chaudhary
 * [MAUI_03136488] Checkins for IMEV3
 * IMEv3 Checkin
 *
 * 03 21 2012 xiangnan.qi
 * [MAUI_03149632] When Single SIM is inserted should not show SIM numbers in UART settings
 * .
 *
 * 03 20 2012 xiangnan.qi
 * [MAUI_03149632] When Single SIM is inserted should not show SIM numbers in UART settings
 * .
 *
 * 03 13 2012 xiangnan.qi
 * [MAUI_03147803] FTE launcher support main menu effect.
 * .
 *
 * 03 11 2012 xiangnan.qi
 * [MAUI_03143108] [UE]delete the mre , but still show the mre shortcut
 * .
 *
 * 03 08 2012 xiangnan.qi
 * [MAUI_03143554] [UE][Key Launcher]show 2 same items after change the widget order for several times
 * .
 *
 * 02 27 2012 kuldeep.chaudhary
 * [MAUI_03136488] Checkins for IMEV3
 * HW compile option dependency checkin
 *
 * 02 26 2012 kuldeep.chaudhary
 * [MAUI_03136488] Checkins for IMEV3
 * IMEv3 Pluto settings Checkin
 *
 * 02 22 2012 xiangnan.qi
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 02 22 2012 mengmeng.cao
 * [MAUI_03135149] [Sensor service]mCube motion sensor porting support
 * .
 *
 * 02 22 2012 f.wang
 * [MAUI_03134994] Dialer tts voice report check in
 * .
 *
 * 02 21 2012 yiping.xie
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 02 21 2012 xiangnan.qi
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 12 13 2011 xiangnan.qi
 * [MAUI_03097129] [DM][Lawmo] App/Srv split and cosmos implement
 * .
 *
 * 11 07 2011 xiangnan.qi
 * [MAUI_03071215] [Settings] Main menu effect does not restore to default after restore factory settings
 * .
 *
 * 08 30 2011 yiruei.wu
 * [MAUI_03015971] Google search: idle shortcut bar - check in
 * .
 *
 * 08 30 2011 wen.qi
 * [MAUI_03015965] [NTP] Check in
 * .
 *
 * 08 18 2011 xiangnan.qi
 * [MAUI_02983278] [BW_FWT][Phonebook] The "As text message" select screen should be removed when send Vcard.
 * .
 *
 * 07 13 2011 cong.zhou
 * [MAUI_02946289] Check in TTS setting
 * .
 *
 * 07 09 2011 cong.zhou
 * [MAUI_02979243] [SLIM_UI]SIM4 in UART settings alignment abnormal.
 * .
 *
 * 06 30 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 06 20 2011 cong.zhou
 * [MAUI_02965708] [Known Issue]Icon appears Red X in Wall paper settings
 * .
 *
 * 06 18 2011 cong.zhou
 * [MAUI_02964171] [Need Patch] [Sanity Fail][NFST] Sanity Test of TSSQA00008783 is Fail. Assert fail: Caller Address: 0x83711a2 Line: 7532 - MMI Product: 11B UNICORN53V6_DEMO Version: MAUI.11B.W11.25 BuildTime: 2011/06/16 15:05
 * .
 *
 * 06 17 2011 cong.zhou
 * [MAUI_02964148] [Need Patch][Build Error] 11B.W11.25 build error for UNICORN53V4_DEMO_gprs(OG_MEDIAENTRY)
 * .
 *
 * 06 16 2011 yixiong.zhao
 * [MAUI_02964102] [Shortcut] Shortcuts appears both in phone setting and main menu
 * .
 *
 * 06 13 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 05 25 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 05 20 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 05 19 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 05 19 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 05 10 2011 cong.zhou
 * [MAUI_02660428] [FO_CF][UE][Setting] It will be better if don't restart phone when change UART setting
 * .
 *
 * 03 22 2011 cong.zhou
 * [MAUI_02657293] [Setting] Check in __MMI_SCREEN_SAVER__ for 10A
 * .
 *
 * 03 21 2011 yixiong.zhao
 * [MAUI_02657087] [Settings]It should show only one shortcuts
 * .
 *
 * 03 04 2011 cathytr.huang
 * [MAUI_02888116] Phase out TVOUT
 * .
 *
 * 02 18 2011 cong.zhou
 * [MAUI_02652105] [Setting] NITZ check in
 * .
 *
 * 02 09 2011 hongxi.shi
 * [MAUI_02650968] [check in] Mainmenu option revise
 * .
 *
 * 01 13 2011 cong.zhou
 * [MAUI_02648131] [Setting] Remove unused string
 * .
 *
 * 01 13 2011 cong.zhou
 * [MAUI_02648131] [Setting] Remove unused string
 * .
 *
 * 12 24 2010 cong.zhou
 * [MAUI_02731860] Gemini+][SZ][CMCC]handset can't show owner number
 * .
 *
 * 12 23 2010 cong.zhou
 * [MAUI_02645192] [Setting] Check in setting for FTO
 * .
 *
 * 12 23 2010 yuanzhe.guo
 * [MAUI_02645489] [New feature] check in IME Plugin
 * .
 *
 * 12 17 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 12 14 2010 cong.zhou
 * [MAUI_02643804] [Setting] Check in show owner number for GEMINI+
 * .
 *
 * 12 14 2010 diamond.lee
 * [MAUI_02846075] [MMI][Gemini+] 10A and MAUI check in
 * Mode switch app part
 *
 * 12 10 2010 cong.zhou
 * [MAUI_02643804] [Setting] Check in show owner number for GEMINI+
 * .
 *
 * 12 06 2010 dinesh.solanki
 * [MAUI_02446184] CR for build error
 * .
 *
 * 12 03 2010 cong.zhou
 * [MAUI_02642758] [Setting] Add pen calibration to avoid sanity test error
 * .
 *
 * 12 02 2010 dinesh.solanki
 * [MAUI_02446184] CR for build error
 * .
 *
 * 12 01 2010 dinesh.solanki
 * [MAUI_02445773] For cache checkin
 * .
 *
 * 11 30 2010 yixiong.zhao
 * [MAUI_02642530] [Build error] Modify the res range declaration
 * .
 *
 * 11 24 2010 dinesh.solanki
 * [MAUI_02445773] For cache checkin
 * .
 *
 * 11 23 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 11 22 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 11 19 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 11 18 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 10 30 2010 cong.zhou
 * [MAUI_02639207] [Need Patch] Fix error for 02833289
 * .
 *
 * 10 28 2010 cong.zhou
 * [MAUI_02638571] The option is wrong
 * .
 *
 * 10 25 2010 cong.zhou
 * [MAUI_02638603] Language setting API and notification revise
 * .
 *
 * 10 22 2010 cong.zhou
 * [MAUI_02638362] When change state of the Homescreen settings is abnormal.
 * .
 *
 * 09 10 2010 cong.zhou
 * [MAUI_02441940] Phone stuck of Done pop up until remove USB.
 * .
 *
 * 08 11 2010 cong.zhou
 * [MAUI_02631461] [Setting] Move resource from Res_Setting.c to APP res file
 * .
 *
 * Jul 19 2010 mtk33054
 * [MAUI_02435328] checkins for phonesettings ime settings 10  resource
 * 
 *
 * Jul 12 2010 mtk33054
 * [MAUI_02435328] checkins for phonesettings ime settings 10  resource
 * 
 *
 * Jul 8 2010 mtk01877
 * [MAUI_02582258] [Pluto10A] XML resource
 * 
 *
 * Jul 8 2010 mtk80518
 * [MAUI_02221544] CMCC 240x400
 * 
 *
 * Jun 10 2010 mtk80585
 * [MAUI_02423062] [Known Issue][Idle]Show owner number item should be displayed in display menu list
 * 
 *
 * Jun 9 2010 mtk80585
 * [MAUI_02208090] [Settings] Remove unused resource ID
 * 
 *
 * Jun 8 2010 mtk80585
 * [MAUI_02114878] Interactive screen is not getting off
 * 
 *
 * Jun 4 2010 mtk80585
 * [MAUI_02205949] [Need patch] Fix build error
 * 
 *
 * May 16 2010 mtk80585
 * [MAUI_02282393] it lack Dedicated key item
 * 
 *
 * Apr 17 2010 mtk80047
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 * Apr 16 2010 mtk80585
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 * Apr 14 2010 mtk80047
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 * Apr 14 2010 mtk80047
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"
#include "custom_mmi_default_value.h"
#include "PhoneSetupSlim.h"
#include "MainMenuDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_PHONESETTING_NEW">
    <INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_srv_wallpaper_def.h"/>
#ifdef __MMI_TELEPHONY_SUPPORT__
    <INCLUDE file = "mmi_rp_srv_flight_mode_def.h"/>
#endif
#ifdef __MMI_PHNSET_APPICON_SUPPORT__  
    <INCLUDE file = "mmi_rp_app_setting_appicon_def.h"/>
#endif
    <INCLUDE file = "mmi_rp_srv_phnset_onoff_def.h"/>    
    <INCLUDE file = "mmi_rp_srv_screensaver_def.h"/>
    <INCLUDE file = "mmi_rp_srv_spof_def.h"/>
    <INCLUDE file = "mmi_rp_app_nitz_def.h"/>
	<INCLUDE file = "mmi_rp_srv_editor_def.h"/>
#ifdef MOTION_SENSOR_SUPPORT
    <INCLUDE file = "mmi_rp_motion_sensor_def.h"/>
#endif
#ifdef __NTPD_SUPPORT__
    <INCLUDE file = "mmi_rp_app_ntp_def.h"/>
#endif
    <INCLUDE file = "mmi_rp_srv_mmi_theme_def.h"/>
#ifndef __DISABLE_SHORTCUTS_IMPL__
    <INCLUDE file = "mmi_rp_app_shortcuts_def.h"/>
#endif /* __DISABLE_SHORTCUTS_IMPL__ */
    <INCLUDE file = "mmi_rp_app_gpio_def.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
#ifdef __MMI_GADGET_SUPPORT__    
    <INCLUDE file = "mmi_rp_app_wgtmgr_def.h"/>
#endif
#ifdef __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__
    <INCLUDE file = "mmi_rp_app_font_manager_def.h"/>
#endif    
#ifdef __MMI_PREFER_INPUT_METHOD__
    <INCLUDE file = "SettingResDef.h"/>
#endif
#ifdef __GENERAL_TTS__
    <INCLUDE file = "mmi_rp_app_tts_setting_def.h"/>
    <INCLUDE file = "mmi_rp_cui_dialer_def.h"/>
#endif
#ifdef __MMI_SEARCH_WEB_GOOGLE__
    <INCLUDE file = "mmi_rp_app_search_web_def.h"/>
#endif
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
    <INCLUDE file = "mmi_rp_app_screen_lock_key_img_setting_def.h"/>
#endif
#ifdef __MMI_AUTO_KEYPAD_LOCK__
    <INCLUDE file = "mmi_rp_app_scr_locker_def.h"/>
#endif

    <!-- string ----------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------->
    
    <!-- phone setting string --------------------------------------------------------------------->
    <STRING id = "STR_MENU9102_INITIAL_SETUP"/>


    <!-- time and date setting string -->
    <STRING id = "STR_MENU9141_TIME_AND_DATE"/>
#if !defined(__MMI_HIDE_HOMECITY__) && !defined(__MMI_TWO_LAYER_HOMECITY__)
    <STRING id = "STR_MENU9142_SETHOMECITY"/>
#endif    

#ifdef __MMI_TIMEZONE_CHANGE_DATETIME__    
    <STRING id = "STR_ID_TZ_CHANGE_DATETIME_TITLE"/>
#endif
    <STRING id = "STR_ID_PHNSET_SET_DT"/>
#if 0
#ifdef __MMI_SEPARATE_DT_SETTING__
    <STRING id = "STR_ID_PHNSET_SET_DATEANDFORMAT"/>
    <STRING id = "STR_ID_PHNSET_SET_TIMEANDFORMAT"/>
#endif    
#endif   
    <STRING id = "STR_MENU9144_SETTIMEANDDATEFORMAT"/>
#ifndef __MMI_MAINLCD_96X64__   
    <STRING id = "STR_ID_PHNSET_SET_DST"/>
#endif
#ifndef __MMI_MAINLCD_96X64__
    <STRING id = "STR_ENTER_TIME_FORMAT_DISP_CAPTION"/>
    <STRING id = "STR_ENTER_DATE_FORMAT_DISP_CAPTION"/>
#ifdef __MMI_BTD_BOX_UI_STYLE__
    <STRING id = "STR_ENTER_YEAR_FORMAT_DISP_CAPTION"/>
    <STRING id = "STR_ENTER_MONTH_AND_DAY_FORMAT_DISP_CAPTION"/>
#endif
    <STRING id = "STR_ID_PHNSET_SET_DATE_SEP"/>
#endif    
#if 0    
#ifdef __MMI_SEPARATE_DT_SETTING__    
    <STRING id = "STR_TIME_FORMAT_CAPTION"/>
    <STRING id = "STR_DATE_FORMAT_CAPTION"/>
#endif
#endif
    <STRING id = "STR_ID_DD_MM_YYYY_S"/>
    <STRING id = "STR_ID_MM_DD_YYYY_S"/>
    <STRING id = "STR_ID_YYYY_MM_DD_S"/>

#ifdef __MMI_TIMEZONE_SETTING__
#ifndef __MMI_HIDE_HOMECITY__
#ifdef __MMI_TWO_LAYER_HOMECITY__
    <STRING id = "STR_MENU9142_SETTIMEZONE"/>
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
#endif /* __MMI_HIDE_HOMECITY__ */

#ifdef __MMI_DUAL_CLOCK__
    <STRING id = "STR_MENU9142_SETFRNCITY"/>
#endif /* __MMI_DUAL_CLOCK__ */

#if defined(__MMI_TIMEZONE_CHANGE_DATETIME__)
    <STRING id = "STR_ID_TZ_CHANGE_DATETIME"/>
#endif /* defined(__MMI_TIMEZONE_CHANGE_DATETIME__) */
#endif /* __MMI_TIMEZONE_SETTING__ */

    <!-- greeting text string -->


    <!-- language setting string -->
    <STRING id = "STR_MENU_LANGUAGE"/>


    <!-- encoding type string -->
#if defined(__MMI_SET_DEF_ENCODING_TYPE__)    
    <STRING id = "STR_DEF_ENCODING_TYPE_TITLE"/>
#endif    





    <!-- font size setting menu ---------------------------------------------------------->
#ifdef __MMI_CHANGABLE_FONT__

    <STRING id = "STR_ID_PHNSET_FONT_SIZE"/>
    <STRING id = "STR_ID_PHNSET_FONT_SIZE_THEME_DEFAULT"/>
    <STRING id = "STR_ID_PHNSET_FONT_SIZE_SMALL"/>
#ifndef __MMI_DIALLING_FONT__
    <STRING id = "STR_ID_PHNSET_FONT_SIZE_LARGE"/>
#endif 
#endif /* __MMI_CHANGABLE_FONT__ */


    <!-- UART setting string -->
#ifdef __MMI_DUAL_SIM_MASTER__    
	<STRING id = "STR_ID_PHNSET_UART_SETUP_TITLE"/>
#endif


    <!-- Display setting string ------------------------------------------------------------------->
    <STRING id = "STR_IDLE_SCR_DISP"/>
    #if defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANALOG"/>
    #endif
    #if defined(__MMI_DIGITAL_CLOCK__) || defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    <STRING id = "STR_ID_PHNSET_DISPCHAR_DIGITAL"/>
    #endif
    <!-- string : for image, animation, vedio, swflash used by wallpaper screensaver poweronoffdisplay --> 
#ifndef __MMI_MAINLCD_96X64__   
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_START"/>
#ifndef __MMI_PHNSET_WP_SLIM__
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_1"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_2"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_3"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_4"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_5"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_6"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_7"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_8"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_9"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_10"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_11"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_12"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_13"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_14"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_IMGID_15"/>
#endif
#endif    
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_START"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_1"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_2"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_3"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_4"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_5"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_6"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_7"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_8"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_9"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_10"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_11"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_12"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_13"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_14"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_ANMID_15"/>
    #endif
#ifndef __MMI_MAINLCD_96X64__
#if defined( __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__) ||defined (__MMI_SCREEN_SAVER__)
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_START"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_1"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_2"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_3"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_4"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_5"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_6"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_7"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_8"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_9"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_10"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_11"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_12"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_13"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_14"/>
    <STRING id = "STR_ID_PHNSET_DISPCHAR_VDOID_15"/>
#endif    
#endif

    

    <!-- Dial style string -->
#ifdef __MMI_MOTION_DIAL__
    <STRING id = "STR_ID_PHNSET_DIAL_STYLE"/>
    <STRING id = "STR_ID_PHNSET_MOTION_DIAL_1"/>
    <STRING id = "STR_ID_PHNSET_MOTION_DIAL_2"/>    
    <STRING id = "STR_ID_PHNSET_MOTION_DIAL_3"/>    
    <STRING id = "STR_ID_PHNSET_MOTION_DIAL_4"/>    
    <STRING id = "STR_ID_PHNSET_MOTION_DIAL_5"/>    
#endif /* __MMI_MOTION_DIAL__ */


    <!-- VUI homescreen string -->
#ifdef __MMI_VUI_HOMESCREEN__
    <STRING id = "STR_ID_VUI_PHNSET_HOMESCREEN"/>
#endif /* __MMI_VUI_HOMESCREEN__ */

    <!-- VUI mainmenu effect string -->
#if defined(__MMI_VUI_MAINMENU__)    
    <STRING id = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT"/>
#endif    
#ifdef __MMI_VUI_MAINMENU__
    <STRING id = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT1"/>
    <STRING id = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT2"/>
    <STRING id = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT3"/>
    <STRING id = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT4"/>
    <STRING id = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT5"/>	
#endif /* __MMI_VUI_MAINMENU__ */

#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
    <STRING id = "STR_ID_VUI_PHNSET_LAUNCHER">"Launcher"</STRING>    
#if defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
    <STRING id = "STR_ID_VUI_PHNSET_LAUNCHER_1">"Launcher FTE"</STRING> 	 
    <STRING id = "STR_ID_VUI_PHNSET_LAUNCHER_2">"Launcher KEY"</STRING>
#else
    <STRING id = "STR_ID_VUI_PHNSET_LAUNCHER_0">"Launcher Classic"</STRING>    
#endif
#ifdef __MMI_LAUNCHER_APP_LIST__    
    <STRING id = "STR_ID_VUI_PHNSET_LAUNCHER_3">"Friut Launcher"</STRING> 
#endif    
#endif
    
#if (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
<!-- VUI mainmenu effect string -->
    <STRING id = "STR_ID_VUI_PHNSET_KEY_LAUNCHER_MAINMENU_EFFECT"/>
#endif

    <!-- calendar idle screen setting string -->
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    <STRING id = "STR_ID_PHNSET_CALENDAR_SCREEN"/>
#endif

    <!-- show date and time setting string -->
 #ifndef __MMI_MAINLCD_96X64__   
    <STRING id = "STR_SETTING_SHOW_DT_TIME"/>
 #endif   


    <!-- dual clock setting string -->
#ifdef __MMI_DUAL_CLOCK__    
#ifndef __MMI_VUI_HOMESCREEN_DUALCLOCK__
	<STRING id = "STR_ID_PHNSET_DUAL_CLOCK_SCREEN"/>
#endif /* __MMI_VUI_HOMESCREEN_DUALCLOCK__ */
#endif /* __MMI_DUAL_CLOCK__ */


    <!-- operator homescreen setting string-->
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
    <STRING id = "STR_ID_PHNSET_HOMESCREEN"/>
#endif /* __MMI_OP11_HOMESCREEN__ */


    <!-- screen switch effect setting string-->
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    <STRING id = "STR_ID_PHNSET_SCREEN_SWITCH_EFFECT"/>
    <STRING id = "STR_ID_PHNSET_SSE_SIMPLE"/>
    <STRING id = "STR_ID_PHNSET_SSE_FULL"/>
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */


    <!-- show operator name setting string-->
#if defined(__MMI_OPERATOR_NAME_MENU__)
    <STRING id = "STR_OPN"/>
#endif 


    <!-- Idle clock type setting string-->
#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    <STRING id = "STR_ID_IDLE_CLOCK_TYPE"/>
#endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */

    <!-- Owner number display setting string-->
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__    
    <STRING id = "STR_ID_PHNSET_SHOW_OWNER_NUMBER"/>
#if 0
    <STRING id = "STR_ID_PHNSET_OWNER_NUMBER_SIM1"/>
    <STRING id = "STR_ID_PHNSET_OWNER_NUMBER_SIM2"/>
    <STRING id = "STR_ID_PHNSET_OWNER_NUMBER_SIM3"/>
    <STRING id = "STR_ID_PHNSET_OWNER_NUMBER_SIM4"/>
#endif    
#endif
    <!-- main menu style string-->
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    <STRING id = "STR_MAINMENU_STYLE"/>
    <STRING id = "STR_MAINMENU_STYLE_MATRIX"/>
    <STRING id = "STR_MAINMENU_STYLE_PAGE"/>
    <STRING id = "STR_MAINMENU_STYLE_CIRCULAR"/>
    <STRING id = "STR_MAINMENU_STYLE_ROTATE"/>
    <STRING id = "STR_MAINMENU_STYLE_LIST"/>
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
#ifdef __MMI_MOTION_MAINMENU__
    <STRING id = "STR_ID_PHNSET_MOTION_MAINMENU_1"/>
    <STRING id = "STR_ID_PHNSET_MOTION_MAINMENU_2"/>    
    <STRING id = "STR_ID_PHNSET_MOTION_MAINMENU_3"/>    
    <STRING id = "STR_ID_PHNSET_MOTION_MAINMENU_4"/>    
    <STRING id = "STR_ID_PHNSET_MOTION_MAINMENU_5"/>    
#endif /* __MMI_MOTION_MAINMENU__ */


#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ 
	<STRING id = "STR_ID_PHNSET_BT_BOX_UT"/>
	<STRING id = "STR_ID_PHNSET_BT_BOX_UT1"/>
	<STRING id = "STR_ID_PHNSET_BT_BOX_UT2"/>
	<STRING id = "STR_ID_PHNSET_BT_BOX_UT3"/>
	
	<STRING id = "STR_ID_PHNSET_BT_BOX_PICKER_UT"/>
	<STRING id = "STR_ID_PHNSET_BT_BOX_PICKER_UT1"/>
	<STRING id = "STR_ID_PHNSET_BT_BOX_PICKER_UT2"/>
#endif  //__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__


#if defined(__MMI_IME_PLUG_IN_SETTING__)
         <STRING id= "STR_IME_SETTINGS_SDK_SETTING"/>
#endif

    <!-- Single language string ------------------------------------------------------------------------------------>
    <STRING id = "STR_DT_SEP_DOT">"."</STRING>
    <STRING id = "STR_DT_SEP_COLON">":"</STRING>
    <STRING id = "STR_DT_SEP_SLOPE">"/"</STRING>
    <STRING id = "STR_DT_SEP_LINE">"-"</STRING>
    <STRING id = "STR_24">"24"</STRING>
    <STRING id = "STR_12">"12"</STRING>

#ifdef __MMI_VUI_LAUNCHER_KEY__    	
	<!-- widget setting string  ---------------------------------------------------------->
	<STRING id = "STR_ID_KEY_LAUNGCHER_WGTMGR"/>
	<STRING id = "STR_ID_KEY_LAUNGCHER_WGTMGR_DISP_SETTINGS"/>
	<STRING id = "STR_ID_KEY_LAUNGCHER_WGTMGR_ORDER_SETTINGS"/>
	<STRING id = "STR_ID_WIDGET_FAIL_TO_DISABLE"/>
#endif
	
#ifdef __MMI_VUI_LAUNCHER_KEY__    	
	<!-- shortcut setting string  ---------------------------------------------------------->	
	<STRING id = "STR_ID_FTE_LAUNGCHER_SHORTCUT"/>
	<STRING id = "STR_ID_FAIL_TO_ADD"/>
#endif

#ifdef __GEMINI__
#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef __MMI_PHNSET_AT_DISABLE__
	<STRING id = "STR_PHNSET_UART_1"/>
	<STRING id = "STR_PHNSET_UART_2"/>
#if (MMI_MAX_SIM_NUM >= 3)
	<STRING id = "STR_PHNSET_UART_3"/>
#if (MMI_MAX_SIM_NUM >= 4)
	<STRING id = "STR_PHNSET_UART_4"/>
#endif
#endif
	<STRING id = "STR_ID_PHNSET_UART_REBOOT"/>
	<STRING id = "STR_ID_PHNSET_UART_SETUP_REBOOT_PROCESSING"/>
#endif
#endif
#endif
#ifdef __MMI_VUI_LAUNCHER_KEY__
	<STRING id = "STR_PHNSET_WIDGET_ON"/>
#endif	
#ifdef __MMI_MAINLCD_96X64__   
	<STRING id = "STR_PHNSET_DATETIME_DATE"/>
	<STRING id = "STR_PHNSET_DATETIME_TIME"/>
	<STRING id = "STR_PHNSET_DATETIME_DISPLAY"/>
	<STRING id = "STR_PHNSET_FORMATE_TIMEFORMATE"/>
	<STRING id = "STR_PHNSET_FORMATE_DATEFORMATE"/>
#endif

    <!-- image ------------------------------------------------------------------------------------>
    <!--------------------------------------------------------------------------------------------->
    
    <!-- phone setting image----------------------------------------------------------------------->
    <IMAGE id = "IMG_SETTING_PHONE">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SPH.bmp"</IMAGE>


    <!-- greeting text image -->
    <!-- IMG_SETTING_GREET_STATUS is not wrapped with __MMI_PHNSET_GREET_TEXT__ because screensaver use it.-->    
#if 0
#ifndef __MMI_SLIM_IMG_RES__    
    <IMAGE id = "IMG_SETTING_GREET_STATUS">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\Common\\\\ST_STATU.bmp"</IMAGE>
#else
    <IMAGE id = "IMG_SETTING_GREET_STATUS">CUST_IMG_PATH"\\\\MainLCD\\\\Settings\\\\Common\\\\ST_STATU.bmp"</IMAGE>
#endif
#endif
    <IMAGE id = "IMG_SCR_SETTING_CAPTION">CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_ST.PNG"</IMAGE>    
#if 0
#ifndef __MMI_SLIM_IMG_RES__
    <IMAGE id = "IMG_SETTING_CAL">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\DateAndTime\\\\ST_CALEN.bmp"</IMAGE>    
#else
    <IMAGE id = "IMG_SETTING_CAL">CUST_IMG_PATH"\\\\MainLCD\\\\\Settings\\\\DateAndTime\\\\ST_CALEN.bmp"</IMAGE>    
#endif
#endif
    <!-- screen ----------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------->
    <!-- phone setting main screen -->
    <SCREEN id = "SCR9003_INITIALSETUP"/>
    
    
    <!-- greeting text screen -->
    <SCREEN id = "SCR9146_WELCOME_TEXT"/>

    <!-- time and date setting scrren -->
    <SCREEN id = "SETTINGS_SETHOMECITY_SCREENID"/>

    <!-- UART setting screen -->
	<SCREEN id = "SCR_ID_PHNSET_UART_REBOOT_PROCESSING"/>

	<!-- GROUP ID --------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------->

	<!-- phone setting group ID -->
	<SCREEN id = "GRP_ID_PHNSET_MENU"/>

	<SCREEN id = "GRP_ID_PHNSET_DISP_SETUP"/>
	<SCREEN id = "GRP_ID_PHNSET_TIME_DATE"/>
	<SCREEN id = "GRP_ID_PHNSET_FLIGHT_MODE"/>
	<SCREEN id = "GRP_ID_PHNSET_SCHEDULE_POWER"/>
	<SCREEN id = "GRP_ID_PHNSET_UART_SETUP"/>
	<SCREEN id = "GRP_ID_PHNSET_FONT_SIZE"/>
	<SCREEN id = "GRP_ID_PHNSET_DEF_ENCODING_TYPE"/>
	<SCREEN id = "GRP_ID_PHNSET_WELCOME_TEXT"/>
	
	<SCREEN id = "SCR_LANGUAGE_SELECTION"/>
    <SCREEN id = "GRP_ID_PHNSET_LANGUAGE"/>  
#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ 
	<SCREEN id = "GRP_ID_PHNSET_BTBOX_DIALER_TYPE"/>
	<SCREEN id = "GRP_ID_PHNSET_BTBOX_PICKER_TYPE"/>
#endif  //__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__
    
    <!-- Group ID ofr Time and Date setting menu -->
#ifdef __MMI_MAINLCD_96X64__        
     <SCREEN id = "GRP_ID_PHNSET_DATETIME_MAIN"/>
#endif    
    <SCREEN id = "GRP_ID_PHNSET_SET_HOME_FOREIGN_CITY"/>
    <SCREEN id = "GRP_ID_PHNSET_CHANGE_DATE_TIME"/> 
    <SCREEN id = "GRP_ID_PHNSET_SET_TIME_AND_DATE"/>
    <SCREEN id = "GRP_ID_PHNSET_SET_TIME_AND_DATE_FORMAT"/> 
    <SCREEN id = "GRP_ID_PHNSET_SEPARATE_SET_DT_AND_FORMAT"/> 

    
    <!-- Group ID for Display setup menu -->
    <SCREEN id = "GRP_ID_PHNSET_MAINMENU_STYLE"/>
    <SCREEN id = "GRP_ID_PHNSET_DIAL_STYLE"/>
    <SCREEN id = "GRP_ID_PHNSET_VUI_HOMESCREEN"/>
    <SCREEN id = "GRP_ID_PHNSET_VUI_MAINMENU_EFFECT"/>
    <SCREEN id = "GRP_ID_PHNSET_HOMESCREEN"/>
    <SCREEN id = "GRP_ID_PHNSET_SCRSWITCH_EFFECT"/>
    <SCREEN id = "GRP_ID_PHNSET_IDLE_CLOCK_TYPE"/>
    <SCREEN id = "GRP_ID_PHNSET_SHOW_OPN"/>
    <SCREEN id = "GRP_ID_PHNSET_SHOW_DT_TIME"/>
    <SCREEN id = "GRP_ID_PHNSET_DUAL_CLOCK_IDLESCREEN"/>
	<SCREEN id = "GRP_ID_PHNSET_CALENDAR_IDLESCREEN"/>
	<SCREEN id = "GRP_ID_PHNSET_SHOW_OWNER_NUMBER"/>

    <SCREEN id = "GRP_ID_SETTING_MAIN_MENU"/>

#ifdef __MMI_VUI_LAUNCHER_KEY__    
	<!-- widget setting group id  ---------------------------------------------------------->
    <SCREEN id = "GRP_ID_PHNSET_WIDGET_MGR"/>
    <SCREEN id = "SCR_ID_PHNSET_WIDGET_MGR_DISP_SETTINGS"/>
    <SCREEN id = "SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS"/>
    <SCREEN id = "SCR_ID_PHNSET_WIDGET_MGR_ORDER_SETTINGS_2"/>   
#endif
    
#ifdef __MMI_VUI_LAUNCHER_KEY__    
	<!-- shortcut setting group id  ---------------------------------------------------------->
    <SCREEN id = "GRP_ID_PHNSET_SHORT_CUT"/>
    <SCREEN id = "SCR_ID_PHNSET_SHORT_CUT"/>
#endif
    <!-- menu ------------------------------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------->
 

    <!-- phone setting main menu ------------------------------------------------------------------>
    <!--------------------------------------------------------------------------------------------->
    <MENU id = "MENU9102_INITIAL_SETUP" type = "APP_MAIN" str = "STR_MENU9102_INITIAL_SETUP" img = "IMG_SETTING_PHONE" highlight = "HighlightPhnsetScr">
#ifndef __MMI_MAINLCD_96X64__        
        <MENUITEM_ID>MENU9141_TIME_AND_DATE</MENUITEM_ID>
#endif        
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
        <MENUITEM_ID>MENU_SETTING_SCHEDULE_POWER</MENUITEM_ID>
#endif /* __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__ */
        <MENUITEM id = "MENU_SETTING_LANGUAGE" str = "STR_MENU_LANGUAGE"/>
#if defined(__MMI_IME_V3__)
		<MENUITEM_ID>MENU_ITEM_IME_SETTING</MENUITEM_ID>
#else
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
#if  defined(__MMI_MIXED_LANG_SUPPORT__)
      <MENU id="MENU_ID_PHNSET_PREFERED_WRITING_LANG" str="STR_IME_SETTINGS_WRITING_LANGUAGE" highlight = "mmi_imesettings_writing_lang_highlighthandler" >
      <MENUITEM id="MENU_ID_COMMONSCREENS_IME_SUB_LANGUAGE" str="STR_IME_SETTINGS_WRITING_LANGUAGE_SUB" hint = "mmi_imesettings_sub_writing_lang_hint" highlight = "mmi_imesettings_sub_writing_lang_highlight"/>
      <MENUITEM id="MENU_ID_COMMONSCREENS_IME_MAIN_LANGUAGE" str="STR_IME_SETTINGS_WRITING_LANGUAGE_MAIN" hint =  "mmi_imesettings_main_writing_lang_hint" highlight = "mmi_imesettings_main_writing_lang_highlight"/>
      </MENU>
#else
      <MENUITEM id="MENU_ID_PHNSET_PREFERED_WRITING_LANG" str="STR_IME_SETTINGS_WRITING_LANGUAGE" hint = "mmi_imesettings_main_writing_lang_hint" highlight = "mmi_imesettings_writing_lang_highlighthandler"/>
#endif
#endif
#endif


#ifdef __MMI_PREFER_INPUT_METHOD__
        <MENUITEM id="MENU_SETTING_PREFERED_INPUT_METHOD" str="STR_MENU_INPUT_METHOD" hint = "HintPhnsetPreferedInputMethod"  highlight = "mmi_ime_settings_inputmethodsettings_highlight"/>
#endif

#if defined(__MMI_IME_PLUG_IN_SETTING__)
        <MENUITEM id="MENU_SETTING_SDK_IME_SETTING" str="STR_IME_SETTINGS_SDK_SETTING"/>
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
        <MENUITEM_ID>@OID:MENU_ID_FONT_MGR_SETTING</MENUITEM_ID><!-- external menu owned by YL Wang -->
#endif
#ifdef __MMI_GADGET_SUPPORT__
        <MENUITEM_ID>@OID:MENU_ID_WGTMGR</MENUITEM_ID><!-- external menu owned by Tim Chang -->
#endif
#ifdef __MMI_VUI_LAUNCHER_KEY__
		<MENUITEM_ID>MENU_ID_KEY_LAUNGCHER_WGTMGR</MENUITEM_ID>
#endif /* __KEY_LANGCHER_FOR_SETTING__ */
#ifdef __MMI_VUI_LAUNCHER_KEY__
		<MENUITEM_ID>MENU_ID_FTE_LAUNGCHER_SHORTCUT</MENUITEM_ID>
#endif
#ifdef __MMI_SET_DEF_ENCODING_TYPE__
        <MENUITEM id = "MENU_SETTING_DEF_ENCODING_TYPE" str = "STR_DEF_ENCODING_TYPE_TITLE"/>
#endif 
#ifndef __OP01_FWPBW__
#ifndef __MMI_MAINLCD_96X64__
        <MENUITEM_ID>MENU_IDLE_SCR_DISP</MENUITEM_ID>
#endif        
#else /* __OP01_FWPBW__ */
  #ifndef __MMI_MAINLCD_96X64__
        <MENUITEM id = "MENU_SETTING_SHOW_DT_TIME" str = "STR_SETTING_SHOW_DT_TIME"/>
  #endif      
#endif /* __OP01_FWPBW__ */
#ifdef MOTION_SENSOR_SUPPORT
		<MENUITEM_ID>MENU_ID_MOTION</MENUITEM_ID>
#endif		
#ifdef __MMI_THEMES_APPLICATION__
        <MENUITEM_ID>@OID:MENU3101_THEMES</MENUITEM_ID><!-- external menu owned by Jie Gao -->
#endif
#if 0
#ifdef __MMI_MAINMENU_MATRIX_3X3__
#if (((!defined(__MMI_VERSION_2__) && !defined(__MMI_OP01_MENU_9MATRIX__) && !defined(__MMI_OP01_MENU_12MATRIX__)) || \
      (defined(__WIFI_WIZARD_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) && !defined(__MMI_OP02_MAINMENU_9MATRIX__) && !defined(__MMI_OP02_MAINMENU_12MATRIX__))) && \
     !defined(__DISABLE_SHORTCUTS_MENU__))
        <MENUITEM_ID>@OID:EXTRA_SHORTCUTS_MENUID</MENUITEM_ID><!-- external menu owned by Yixiong Zhao -->
#endif 
#endif
#endif
#if (defined (__WIFI_WIZARD_SUPPORT__) && defined (__MMI_WLAN_FEATURES__)) && !defined(__DISABLE_SHORTCUTS_MENU__) && \
    !defined(__MMI_MAINLCD_96X64__)
     <MENUITEM_ID>@OID:EXTRA_SHORTCUTS_MENUID</MENUITEM_ID>
#endif
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__) && !defined(__DISABLE_SHORTCUTS_MENU__)
        <MENUITEM_ID>@OID:MENU_SETTING_DEDICATED_KEYS</MENUITEM_ID><!-- external menu owned by Yixiong Zhao -->
#endif 
#if (defined(__MMI_NITZ__) && (!defined(__MMI_AUTOTIMEZONE_IN_DATEANDTIME__)))
        <MENUITEM_ID>MENU_ID_NITZ_APP</MENUITEM_ID>
#endif 
#ifdef __NTPD_SUPPORT__
        <MENUITEM_ID>MENU_ID_NTP_APP</MENUITEM_ID>
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
        <MENUITEM_ID>MENU_SETTING_FLIGHT_MODE</MENUITEM_ID>
#endif
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
	#if !defined(__MMI_IME_V3__)
        <MENUITEM id = "MENU_SETTING_HANDWRITING" str = "STR_HANDWRITING_SETTING"/>
#endif 
#endif 
#ifdef __MMI_CHANGABLE_FONT__
        <MENUITEM id = "MENU_ID_PHNSET_FONT_SIZE" str = "STR_ID_PHNSET_FONT_SIZE"/>
#endif 
#ifdef __MMI_DUAL_SIM_MASTER__
    #ifndef __MMI_PHNSET_AT_DISABLE__
        <MENUITEM id = "MENU_ID_PHNSET_UART_SETUP" str = "STR_ID_PHNSET_UART_SETUP_TITLE"/>
    #endif
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifndef __MMI_MAINLCD_96X64__
        <MENUITEM_ID>@OID:MENU_ID_PHNSET_GPIO_SETTING</MENUITEM_ID><!-- external menu owned by Guixia -->
#endif
#ifdef __GENERAL_TTS__
        <MENUITEM id="MENU_ID_PHB_TTS_SETTING" str="STR_ID_PHB_TTS_SETTING"/>
        <MENUITEM id="MENU_ID_SMS_TTS_SETTING" str="STR_ID_SMS_TTS_SETTING"/>
        <MENUITEM_ID>MENU_ID_CUI_DIALER_TTS</MENUITEM_ID>
#endif /* __GENERAL_TTS__ */
    </MENU>
  

    <!-- time and date setting main menu ---------------------------------------------------------->
#ifdef __MMI_MAINLCD_96X64__     
    <MENU id = "MENU9141_TIME_AND_DATE" type = "APP_MAIN" str = "STR_MENU9141_TIME_AND_DATE" highlight = "HighlightPhnsetDateTimeScr">
#else    
    <MENU id = "MENU9141_TIME_AND_DATE" type = "APP_SUB" str = "STR_MENU9141_TIME_AND_DATE">
#endif 
#ifdef __MMI_TIMEZONE_SETTING__
#ifndef __MMI_HIDE_HOMECITY__
        <MENUITEM_ID>MENU9142_SETHOMECITY</MENUITEM_ID>
#endif 
#ifdef __MMI_DUAL_CLOCK__
        <MENUITEM id = "MENU9142_SETFOREIGNCITY" str = "STR_MENU9142_SETFRNCITY"/>
#endif
#endif
#if 0
#ifndef __MMI_SEPARATE_DT_SETTING__
        <MENUITEM id = "MENU9143_SETTIMEANDDATE" str = "STR_ID_PHNSET_SET_DT"/>
        <MENUITEM id = "MENU9144_SETTIMEANDDATEFORMAT" str = "STR_MENU9144_SETTIMEANDDATEFORMAT"/>
#else 
        <MENUITEM id = "MENU_ID_SETTING_DATEANDFORMAT" str = "STR_ID_PHNSET_SET_DATEANDFORMAT"/>
        <MENUITEM id = "MENU_ID_SETTING_TIMEANDFORMAT" str = "STR_ID_PHNSET_SET_TIMEANDFORMAT"/>
#endif 
#else
        <MENUITEM id = "MENU9143_SETTIMEANDDATE" str = "STR_ID_PHNSET_SET_DT"/>
        <MENUITEM id = "MENU9144_SETTIMEANDDATEFORMAT" str = "STR_MENU9144_SETTIMEANDDATEFORMAT"/>
#endif 
#ifdef __MMI_TIMEZONE_SETTING__
#if defined(__MMI_TIMEZONE_CHANGE_DATETIME__)
        <MENUITEM id = "MENU_ID_TZ_CHANGE_DATETIME" str = "STR_ID_TZ_CHANGE_DATETIME"/>
#endif
#endif
#if (defined(__MMI_NITZ__) && defined(__MMI_AUTOTIMEZONE_IN_DATEANDTIME__))
        <MENUITEM_ID>MENU_ID_NITZ_APP</MENUITEM_ID>
#endif 
    </MENU>


    
#ifdef __MMI_TIMEZONE_SETTING__    
#ifndef __MMI_HIDE_HOMECITY__
#ifdef __MMI_TWO_LAYER_HOMECITY__
    <MENUITEM id = "MENU9142_SETHOMECITY" str = "STR_MENU9142_SETTIMEZONE"/>
#else /* __MMI_TWO_LAYER_HOMECITY__ */
    <MENUITEM id = "MENU9142_SETHOMECITY" str = "STR_MENU9142_SETHOMECITY"/>
#endif /* __MMI_TWO_LAYER_HOMECITY__ */
#endif /* __MMI_HIDE_HOMECITY__ */
#endif /* __MMI_TIMEZONE_SETTING__ */

    <!-- Display setting main menu ---------------------------------------------------------------->
    <!--------------------------------------------------------------------------------------------->
#ifdef __MMI_MAINLCD_96X64__     
    <MENU id = "MENU_IDLE_SCR_DISP" type = "APP_MAIN" str = "STR_IDLE_SCR_DISP" highlight = "HighlightPhnsetDispScr">
#else    
    <MENU id = "MENU_IDLE_SCR_DISP" type = "APP_SUB" str = "STR_IDLE_SCR_DISP">
#endif 
#ifndef __MMI_MAINLCD_96X64__    
        <MENUITEM_ID>MENU_SETTING_WALLPAPER</MENUITEM_ID>
#endif        
#ifdef __MMI_SUB_WALLPAPER__        
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SUB</MENUITEM_ID>
#endif /* __MMI_SUB_WALLPAPER__ */     
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
        <MENUITEM_ID>MENU_SETTING_APP_ICON</MENUITEM_ID>
#endif
#if (defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__))
		<MENUITEM_ID>MENU_ID_VUI_PHNSET_LAUNCHER</MENUITEM_ID> 
#endif /* __MMI_VUI_LAUNCHER_KEY__ */
#if defined(__MMI_VUI_MAINMENU__)
        <MENUITEM id = "MENU_ID_VUI_PHNSET_MAINMENU_EFFECT" str = "STR_ID_VUI_PHNSET_MAINMENU_EFFECT"/>
#elif (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
		<MENUITEM id = "MENU_ID_VUI_PHNSET_MAINMENU_EFFECT" str = "STR_ID_VUI_PHNSET_KEY_LAUNCHER_MAINMENU_EFFECT"/>
#endif /* __MMI_VUI_MAINMENU__ */
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
        <MENUITEM_ID>MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING</MENUITEM_ID>
#endif
#ifdef __MMI_AUTO_KEYPAD_LOCK__
        <MENUITEM_ID>MENU_ID_SLK_TIME_SETTING_MENU</MENUITEM_ID>
#endif
#ifdef __MMI_MAINLCD_96X64__
      <MENUITEM_ID>@OID:MENU_ID_PHNSET_GPIO_BACKLITE</MENUITEM_ID>
#endif
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
        <MENUITEM id = "MENU_ID_PHNSET_SCRSWITCH_EFFECT" str = "STR_ID_PHNSET_SCREEN_SWITCH_EFFECT"/>
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */
#ifdef __MMI_SCREEN_SAVER__
        <MENUITEM_ID>MENU_SETTING_SCR_SVR</MENUITEM_ID>
#endif /* __MMI_SCREEN_SAVER__ */
#ifndef __MMI_MAINLCD_96X64__ 
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
        <MENUITEM_ID>MENU_SETTING_POWER_ON_DISPLAY</MENUITEM_ID> 
        <MENUITEM_ID>MENU_SETTING_POWER_OFF_DISPLAY</MENUITEM_ID> 
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */
#endif
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
        <MENUITEM_ID>MENU_SETTING_MAINMENU_STYLE</MENUITEM_ID> 
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
#ifdef __MMI_MOTION_DIAL__
        <MENUITEM id = "MENU_SETTING_DIAL_STYLE" str = "STR_ID_PHNSET_DIAL_STYLE"/>
#endif /* __MMI_MOTION_DIAL__ */
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        <MENUITEM id = "MENU_ID_PHNSET_CALENDAR_IDLESCREEN" str = "STR_ID_PHNSET_CALENDAR_SCREEN"/>
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
        <MENUITEM id = "MENU_ID_PHNSET_HOMESCREEN" str = "STR_ID_PHNSET_HOMESCREEN"/>
#endif /* __MMI_OP11_HOMESCREEN__ */
#ifdef __MMI_DUAL_CLOCK__
#ifndef __MMI_VUI_HOMESCREEN_DUALCLOCK__
        <MENUITEM id = "MENU_ID_PHNSET_DUAL_CLOCK_IDLESCREEN" str = "STR_ID_PHNSET_DUAL_CLOCK_SCREEN"/>
#endif /* __MMI_VUI_HOMESCREEN_DUALCLOCK__ */
#endif /* __MMI_DUAL_CLOCK__ */
#ifndef __MMI_MAINLCD_96X64__
        <MENUITEM id = "MENU_SETTING_SHOW_DT_TIME" str = "STR_SETTING_SHOW_DT_TIME"/>
#endif        
#ifdef __MMI_OPERATOR_NAME_MENU__
        <MENUITEM id = "MENU_SETTING_SHOW_OPN" str = "STR_OPN"/>
#endif /* __MMI_OPERATOR_NAME_MENU__ */
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        <MENUITEM id = "MENU_SETTING_IDLE_CLOCK_TYPE" str = "STR_ID_IDLE_CLOCK_TYPE"/>
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__
#ifdef __MMI_DUAL_SIM_MASTER__
        <MENUITEM_ID>MENU_SETTING_OWNER_NUMBER</MENUITEM_ID>
#else
        <MENUITEM id = "MENU_SETTING_OWNER_NUMBER" str = "STR_ID_PHNSET_SHOW_OWNER_NUMBER"/>
#endif
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */
#ifdef __MMI_SEARCH_WEB_GOOGLE__
        <MENUITEM id = "MENU_ID_SETTING_GOOGLE_HINT_ENTRY" str = "STR_ID_SEARCH_WEB_GOOGLE_HINT_SETTING"/>
#endif

#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__
		<MENUITEM id = "MENU_SETTING_BT_BOX_UT" str = "STR_ID_PHNSET_BT_BOX_UT"/>
		<MENUITEM id = "MENU_SETTING_BT_BOX_PICKER_UT" str = "STR_ID_PHNSET_BT_BOX_PICKER_UT"/>
#endif /* __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ */
    </MENU>


    <!-- Main Menu Style setting  menu (sub menu of Display) -->
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    <MENU id = "MENU_SETTING_MAINMENU_STYLE" type = "APP_SUB" str = "STR_MAINMENU_STYLE">
#ifdef __MMI_MAINMENU_MATRIX_SUPPORT__
        <MENUITEM id = "MENU_SETTING_MAINMENU_STYLE_MATRIX" str = "STR_MAINMENU_STYLE_MATRIX"/>
#endif 
#ifdef __MMI_MAINMENU_PAGE_SUPPORT__
#ifndef __MMI_TOUCH_SCREEN__
        <MENUITEM id = "MENU_SETTING_MAINMENU_STYLE_PAGE" str = "STR_MAINMENU_STYLE_PAGE"/>
#endif 
#endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */ 
#ifdef __MMI_MAINMENU_LIST_SUPPORT__
        <MENUITEM id = "MENU_SETTING_MAINMENU_STYLE_LIST" str = "STR_MAINMENU_STYLE_LIST"/>
#endif 
#ifdef __MMI_MAINMENU_CIRCULAR_SUPPORT__
        <MENUITEM id = "MENU_SETTING_MAINMENU_STYLE_CIRCULAR" str = "STR_MAINMENU_STYLE_CIRCULAR"/>
#endif 
#ifdef __MMI_MAINMENU_ROTATE_SUPPORT__
        <MENUITEM id = "MENU_SETTING_MAINMENU_STYLE_ROTATE" str = "STR_MAINMENU_STYLE_ROTATE"/>
#endif 
    </MENU>
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */

    <!-- Show owner number setting  menu (sub menu of Display) -->
#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__    
#ifdef __GEMINI__
    <MENU id = "MENU_SETTING_OWNER_NUMBER" type = "APP_SUB" str = "STR_ID_PHNSET_SHOW_OWNER_NUMBER">

        <MENUITEM id = "MENU_SETTING_OWNER_NUMBER_SIM1" str = "STR_GLOBAL_SIM_1"/>

        <MENUITEM id = "MENU_SETTING_OWNER_NUMBER_SIM2" str = "STR_GLOBAL_SIM_2"/>
    #if (MMI_MAX_SIM_NUM >= 3)   
        <MENUITEM id = "MENU_SETTING_OWNER_NUMBER_SIM3" str = "STR_GLOBAL_SIM_3"/>
    #if (MMI_MAX_SIM_NUM >= 4)
        <MENUITEM id = "MENU_SETTING_OWNER_NUMBER_SIM4" str = "STR_GLOBAL_SIM_4"/>        
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */   
    </MENU>
#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */

<!-- widget setting main menu ---------------------------------------------------------->
#ifdef __MMI_VUI_LAUNCHER_KEY__
	<MENU id = "MENU_ID_KEY_LAUNGCHER_WGTMGR" type = "APP_SUB" str = "STR_ID_KEY_LAUNGCHER_WGTMGR">
		<MENUITEM id = "MENU_ID_KEY_LAUNGCHER_WGTMGR_DISP_SETTINGS" str = "STR_ID_KEY_LAUNGCHER_WGTMGR_DISP_SETTINGS"/>	
		<MENUITEM id = "MENU_ID_KEY_LAUNGCHER_WGTMGR_ORDER_SETTINGS" str = "STR_ID_KEY_LAUNGCHER_WGTMGR_ORDER_SETTINGS"/>
	</MENU>

<!-- menu shortcut setting ----------------------------------------------------------------------------------->
	<MENUITEM id = "MENU_ID_FTE_LAUNGCHER_SHORTCUT" str = "STR_ID_FTE_LAUNGCHER_SHORTCUT"/> 
#endif

#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
<!-- menu launcher setting ----------------------------------------------------------------------------------->
	<MENU id="MENU_ID_VUI_PHNSET_LAUNCHER" type="APP_SUB" str="STR_ID_VUI_PHNSET_LAUNCHER" flag="RADIO" highlight="mmi_phnset_launcher_switch_hilight_hdlr">
	#if defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
		<MENUITEM id="MENU_ID_VUI_PHNSET_LAUNCHER_1" str="STR_ID_VUI_PHNSET_LAUNCHER_1"/>
		<MENUITEM id="MENU_ID_VUI_PHNSET_LAUNCHER_2" str="STR_ID_VUI_PHNSET_LAUNCHER_2"/>
	#else
	  <MENUITEM id="MENU_ID_VUI_PHNSET_LAUNCHER_1" str="STR_ID_VUI_PHNSET_LAUNCHER_0"/>	
	#endif
	#ifdef __MMI_LAUNCHER_APP_LIST__
		<MENUITEM id="MENU_ID_VUI_PHNSET_LAUNCHER_3" str="STR_ID_VUI_PHNSET_LAUNCHER_3"/>
	#endif	
	</MENU>
#endif

#ifdef __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__  
	<CACHEDATA type="byte" id="NVRAM_DISPCHAR_BT_BOX_DIALER_TYPE" >
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> bt box dialer type </DESCRIPTION>
    </CACHEDATA>
	<CACHEDATA type="byte" id="NVRAM_DISPCHAR_BT_BOX_PICKER_TYPE" >
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> bt box picker type </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__

    <CACHEDATA type="byte" id="NVRAM_SETTING_OWNER_NO" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_OWNER_NO">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> show owner number in idle status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_OWNER_NO">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_IDLE_SCREEN_OWNER_NUMBER__    
    #if (MMI_MAX_SIM_NUM >= 2)   
    <CACHEDATA type="byte" id="NVRAM_CARD2_OWNER_NUMBER" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_OWNER_NO">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> SIM 2 owner number </DESCRIPTION>
    </CACHEDATA>
    
    #if (MMI_MAX_SIM_NUM >= 3)   
    <CACHEDATA type="byte" id="NVRAM_CARD3_OWNER_NUMBER" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_OWNER_NO">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> SIM 3 owner number </DESCRIPTION>
    </CACHEDATA>

    #if (MMI_MAX_SIM_NUM >= 4)
    <CACHEDATA type="byte" id="NVRAM_CARD4_OWNER_NUMBER" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_OWNER_NO">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_OWNER_NO_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> SIM 4 owner number </DESCRIPTION>
    </CACHEDATA>
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* __MMI_IDLE_SCREEN_OWNER_NUMBER__ */
    
    <CACHEDATA type="byte" id="NVRAM_SETTING_STATUS_DT_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> show date and time in idle status </DESCRIPTION>
        <FIELD>
           <OPTION hint="OFF"> [0x00] </OPTION>
	       <OPTION hint="ON"> [0x01] </OPTION>
	    </FIELD>
    </CACHEDATA>

#ifdef __MMI_OPERATOR_NAME_MENU__
    <CACHEDATA type="byte" id="NVRAM_SETTING_OPN_DISPLAY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> display operator number in idle  </DESCRIPTION>
    </CACHEDATA>
#endif /*  __MMI_OPERATOR_NAME_MENU__ */

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    <CACHEDATA type="byte" id="NVRAM_PHNSET_IDLE_CLOCK_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> display clock in idle status </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
    <CACHEDATA type="byte" id="NVRAM_SET_CALENDAR_IDLESCREEN" restore_flag="TRUE">
    #if defined(__MMI_MAINLCD_320X240__) && defined(__MMI_VUI_HOMESCREEN__) 
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #elif defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> display calendar in idle </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

#ifdef __MMI_DUAL_CLOCK__
#ifndef __MMI_VUI_HOMESCREEN_DUALCLOCK__
    <CACHEDATA type="byte" id="NVRAM_SET_DUALCLOCK_IDLESCREEN">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_VUI_HOMESCREEN_DUALCLOCK__ */
#endif /* __MMI_DUAL_CLOCK__ */

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    <CACHEDATA type="byte" id="NVRAM_SET_SCREFFECT_STYLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Current screen effect style </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)
    <CACHEDATA type="byte" id="NVRAM_SET_HOMESCREEN">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_SET_HOMESCREEN </DESCRIPTION>
    </CACHEDATA>
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    <CACHEDATA type="byte" id="NVRAM_SET_MAINMENU_STYLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */

#ifdef __MMI_MOTION_DIAL__
    <CACHEDATA type="byte" id="NVRAM_SET_DIAL_STYLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Current dial motion style </DESCRIPTION>
    </CACHEDATA>    
#endif /* __MMI_MOTION_DIAL__ */

#ifdef __MMI_VUI_HOMESCREEN__
    <CACHEDATA type="byte" id="NVRAM_VUI_PHNSET_HOMESCREEN">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_VUI_PHNSET_HOMESCREEN </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_VUI_MAINMENU__
    <CACHEDATA type="byte" id="NVRAM_VUI_PHNSET_MAINMENU_EFFECT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_VUI_PHNSET_MAINMENU_EFFECT </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_VUI_MAINMENU__ */

#ifdef __MMI_CHANGABLE_FONT__
    <CACHEDATA type="byte" id="NVRAM_BYTE_FONT_SIZE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> current font size </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_CHANGABLE_FONT__ */

    <CACHEDATA type="byte" id="NVRAM_AUTOUPDATE_DT_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#if ((defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__) || defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)))
    #if defined(__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__)
	    <CACHEDATA type="byte" id="NVRAM_PHNSET_LAUNCHER_SETTING" restore_flag="TRUE">
		    <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
		    <DESCRIPTION> Byte Cache </DESCRIPTION>
	    </CACHEDATA>    
    #else 	
	    <CACHEDATA type="byte" id="NVRAM_PHNSET_LAUNCHER_SETTING" restore_flag="TRUE">
		    <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
		    <DESCRIPTION> Byte Cache </DESCRIPTION>
	    </CACHEDATA>
    #endif	
#endif

    <!--------------------------------------------------------------------------------------------->
    <!-- call back function------------------------------------------------------------------------>
    <!--------------------------------------------------------------------------------------------->
#ifdef __DM_LAWMO_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="mmi_phnset_dm_lock_notification_handler"/>
#endif /* __DM_LAWMO_SUPPORT__ */
#ifdef __MMI_VUI_LAUNCHER_KEY__
	<RECEIVER id="EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE" proc="mmi_phnset_shcut_appmgr_uninstall_hdlr"/>
	
	<RECEIVER id="EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE" proc="mmi_phnset_shcut_appmgr_uninstall_hdlr"/>
#endif
</APP>
 

