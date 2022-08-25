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
 *   wallpaper resource file with XML format.   
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
 * 10 19 2013 yunliu.mao
 * [MAUI_03463453] [11BW1332OF_6260Slim_Dev] check in 11c
 * .[11BW1332OF_6260Slim_Dev] check in 11c
 *
 * 01 21 2013 shengxi.xu
 * [MAUI_03320389] Wallpaper Check in
 * - VLW Check in
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 12 25 2012 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * PhoneSetting  Slim check in 11B.
 *
 * 06 25 2012 xiangnan.qi
 * [MAUI_03205991] [CAT2.0] 恢复出厂设置错误
 * .
 *
 * 06 07 2012 xiangnan.qi
 * [MAUI_03198981] [CAT2.0]Wallpaper没有修改正确
 * .
 *
 * 06 01 2012 xiangnan.qi
 * [MAUI_03195195] [CAT2.0]Wall paper 显示不完全
 * .
 *
 * 05 16 2012 xiangnan.qi
 * [MAUI_03185748] [UE]wrong translation for "file " in TC.
 * .
 *
 * 05 16 2012 pablo.sun
 * [MAUI_03185609] Wallpaper fail
 * .wrap option accordingly
 *
 * 04 06 2012 xiangnan.qi
 * [MAUI_03163448] highlight a JPG picture,use as ,find do not have "lock screen wallpaper" menu
 * .
 *
 * 03 16 2012 xiangnan.qi
 * [MAUI_03149349] should both return to wallpaper list screen
 * .
 *
 * 03 08 2012 xiangnan.qi
 * [MAUI_03142734] after restore factory, lock screen wallpaper hint do not show anything
 * .
 *
 * 02 21 2012 xiangnan.qi
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 12 05 2011 xiangnan.qi
 * [MAUI_03085891] [SubLCD]Sublcd wallpaper always show white screen .
 * .
 *
 * 12 01 2011 xiangnan.qi
 * [MAUI_03090344] [LiveWallpaper] support getName in wallpapers
 * .
 *
 * 09 23 2011 xiangnan.qi
 * [MAUI_03035934] MMI Features reduce
 * .
 *
 * 09 01 2011 ch.ko
 * [MAUI_03018122] [Home] Check-in FTE launcher
 * Check-in new feature.
 *
 * 06 11 2011 cong.zhou
 * [MAUI_02960348] Check in view setting revise for wallpaper, screen saver and power on/off display
 * .
 *
 * 05 27 2011 cong.zhou
 * [MAUI_02950472] CMCC TD ASTRO branch patch back to MAUI
 * .
 *
 * 05 25 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 03 03 2011 cong.zhou
 * [MAUI_02654557] [Setting] Revise USB compile option
 * .
 *
 * 01 27 2011 cong.zhou
 * [MAUI_02650411] [Setting] Check in IG Live wallpaper
 * .
 *
 * 12 21 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 12 20 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 11 18 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 10 30 2010 cong.zhou
 * [MAUI_02639211] [Setting] Move callback handler to res file
 * .
 *
 * 10 21 2010 cong.zhou
 * [MAUI_02638391] [Setting] Sub-LCD wallpaper check in
 * .
 *
 * 09 06 2010 cong.zhou
 * [MAUI_02634057] [Setting] Fix error for live wallpaper
 * .
 *
 * 09 03 2010 cong.zhou
 * [MAUI_02634057] [Setting] Fix error for live wallpaper
 * .
 *
 * 09 02 2010 cong.zhou
 * [MAUI_02634057] [Setting] Fix error for live wallpaper
 * .
 *
 * 08 31 2010 cong.zhou
 * [MAUI_02633818] [Setting] Live wallpaper setting
 * .
 *
 * 08 18 2010 cong.zhou
 * [MAUI_02319642] check pic format have differently when select wallpaper
 * .
 *
 * Jun 12 2010 mtk80585
 * [MAUI_02209822] [Settings] Wallpaper, screen save,r power on off display file manager service handle
 * 
 *
 * Jun 9 2010 mtk80585
 * [MAUI_02208090] [Settings] Remove unused resource ID
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

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_WALLPAPER">
    <INCLUDE file = "GlobalResDef.h"/>
    <!-- string ---------------------------------------------------------------------------------->
#ifndef __MMI_MAINLCD_96X64__    
#ifdef __DAILY_WALLPAPER__
    <STRING id = "STR_WALLPAPER_CAPTION"/>
    <STRING id = "STR_WALLPAPER_FIX"/>
    <STRING id = "STR_WALLPAPER_ROTATE"/>
#ifdef __MMI_AVATAR__
    <STRING id = "STR_ID_PHNSET_WP_AVATAR"/>
#endif      
#endif /* __DAILY_WALLPAPER__ */

    <STRING id = "STR_WALLPAPER_SYSTEM"/>
    <STRING id = "STR_WALLPAPER_DOWNLOAD"/>
    <STRING id = "STR_WP_IDLE_WP_DECODE_ERR"/>
//  <STRING id = "STR_SETTING_WALLPAPER"/>
#ifdef __MMI_SUB_WALLPAPER__
    <STRING id = "STR_SETTING_WALLPAPER_SUB"/>
#endif 
    <STRING id = "STR_ID_DISPCHAR_THEME_WALLPAPER"/>    
#ifdef __MMI_VUI_SHELL_SETTINGS__ 
    <STRING id = "STR_ID_WALLPAPER_GALLERY"/> 
#endif
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__)
    <STRING id = "STR_ID_WALLPAPER_LIVE_WALLPAPER"/>    
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__ */
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
    <STRING id = "STR_ID_WALLPAPER_VUI_START"/>
#endif

	<STRING id = "STR_ID_STATIC_WALLPAPER"/>
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
	<STRING id = "STR_ID_VIDEO_WALLPAPER"/>
#endif	
	<STRING id = "STR_ID_HOMESCREEN_WALLPAPER"/>
	<STRING id = "STR_ID_LOCKSCREEN_WALLPAPER"/>
	
    <!-- image ------------------------------------------------------------------------------------>
#if 0
#ifdef __MMI_THEMES_V2_SUPPORT__    
    #ifdef __MMI_RES_TYPE_WALLPAPER__
        <IMAGE id = "IMG_ID_DISPCHAR_THEME_WALLPAPER" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01."__MMI_RES_TYPE_WALLPAPER__</IMAGE>
    #else
        <IMAGE id = "IMG_ID_DISPCHAR_THEME_WALLPAPER" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01.gif"</IMAGE>
    #endif /* __MMI_RES_TYPE_WALLPAPER__ */

    #ifdef __MMI_RES_TYPE_SCREEN_SAVER__
        <IMAGE id = "IMG_ID_DISPCHAR_THEME_SCREENSAVER" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01."__MMI_RES_TYPE_SCREEN_SAVER__</IMAGE>
    #elif defined __MMI_RES_TYPE_WALLPAPER__
        <IMAGE id = "IMG_ID_DISPCHAR_THEME_SCREENSAVER" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01."__MMI_RES_TYPE_WALLPAPER__</IMAGE>
    #else
        <IMAGE id = "IMG_ID_DISPCHAR_THEME_SCREENSAVER" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01.gif"</IMAGE>
    #endif /* __MMI_RES_TYPE_WALLPAPER__ */
#endif /* __MMI_THEMES_V2_SUPPORT__ */

    <!-- Venus home screen wallpaper image -->
#ifdef __MMI_VUI_HOMESCREEN__
    #ifdef __MMI_VUI_HOMESCREEN_LITE_DISPLAY__
        <IMAGE id = "IMG_ID_PHNSET_WP_START" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Venus_wall01.bmp"</IMAGE>    
    #else
        <IMAGE id = "IMG_ID_PHNSET_WP_START" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Venus_wall01.jpg"</IMAGE>    
    #endif /* __MMI_VUI_HOMESCREEN_LITE_DISPLAY__ */
#endif /* __MMI_VUI_HOMESCREEN__ */
#endif

    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_MAIN_WALLPAPER"/>
    <SCREEN id = "SCR_MAIN_WALLPAPER_FIX"/>
    <SCREEN id = "SCR_WALLPAPER_SYSTEM_LIST"/>
    <SCREEN id = "SCR_WALLPAPER_VIEW"/>
    <SCREEN id = "SCR_WALLPAPER_VIEW_2"/>
    <SCREEN id = "SCR_WALLPAPER_DOWNLOAD_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_IDLE_CLOCK_TYPE"/>
    <SCREEN id = "SCR_IDLE_SCR_DISP_WP_PREVIEW"/>
    <SCREEN id = "SCR_IDLE_SCR_DISP_WPSS_WAITING"/>

    <!-- screen group id -------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_DISPLAY_FMGR_COMMON"/>
    <SCREEN id = "GRP_ID_WALLPAPER_MAIN"/>
    <SCREEN id = "GRP_ID_WALLPAPER_SYSTEM"/>
    <SCREEN id = "GRP_ID_WALLPAPER_SYSTEM_SUB"/>
    <SCREEN id = "GRP_ID_WALLPAPER_PREVIEW"/>
    <SCREEN id = "GRP_ID_WALLPAPER_LIVE_WALLPAPER"/>
    <SCREEN id = "GRP_ID_WALLPAPER_ROTATE"/>    
    
    <SCREEN id = "GRP_ID_WALLPAPER_HOME_WALLPAPER"/>
    <SCREEN id = "GRP_ID_WALLPAPER_LOCK_WALLPAPER"/>    
    
    <!-- menu ------------------------------------------------------------------------------------->
#ifdef __MMI_FILE_MANAGER__
/* Daily Wallpaper */
#ifdef __DAILY_WALLPAPER__   /* Wallpaper daily change */

    <!-- wallpaper main menu -->
    <MENU id = "MENU_SETTING_WALLPAPER" type = "APP_SUB" str = "STR_GLOBAL_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_FIX</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_ROTATE</MENUITEM_ID>
    </MENU>
    <!-- wallpaper Fix sub menu -->
    <MENU id = "MENU_SETTING_WALLPAPER_FIX" type = "APP_SUB" str = "STR_WALLPAPER_FIX">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SYSTEM</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_DOWNLOAD</MENUITEM_ID>
    </MENU>
    <MENUITEM id = "MENU_SETTING_WALLPAPER_ROTATE" str = "STR_WALLPAPER_ROTATE"/>
    <MENUITEM id = "MENU_SETTING_WALLPAPER_SYSTEM" str = "STR_WALLPAPER_SYSTEM"/>
    <MENUITEM id = "MENU_SETTING_WALLPAPER_DOWNLOAD" str = "STR_WALLPAPER_DOWNLOAD"/>
    
#ifdef __MMI_SUB_WALLPAPER__

    <!-- wallpaper subLCD main menu -->
    <MENU id = "MENU_SETTING_WALLPAPER_SUB" type = "APP_SUB" str = "STR_SETTING_WALLPAPER_SUB">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_FIX</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_ROTATE</MENUITEM_ID>
    </MENU>
    
#endif /* __MMI_SUB_WALLPAPER__ */

/* Live wallpaper */
#else /* __DAILY_WALLPAPER__ */
    <!-- wallpaper main menu -->
    <MENU id = "MENU_SETTING_WALLPAPER" type = "APP_SUB" str = "STR_GLOBAL_WALLPAPER">
    	<MENUITEM_ID>MENU_SETTING_WALLPAPER_HOMESCREEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_LOCKSCREEN</MENUITEM_ID>
    </MENU>    
    <MENU id = "MENU_SETTING_WALLPAPER_HOMESCREEN" type = "APP_SUB" str = "STR_ID_HOMESCREEN_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SYSTEM</MENUITEM_ID>
#if defined(__MMI_FILE_USEAS_SUPPORT__)
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_DOWNLOAD</MENUITEM_ID>
#endif /* __MMI_FILE_USEAS_SUPPORT__ */
#ifdef __MMI_AVATAR__
        <MENUITEM_ID>MENU_ID_PHNSET_WP_AVATAR</MENUITEM_ID>
#endif /* __MMI_AVATAR__ */
    </MENU>

    <MENU id = "MENU_SETTING_WALLPAPER_LOCKSCREEN" type = "APP_SUB" str = "STR_ID_LOCKSCREEN_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SYSTEM</MENUITEM_ID>
#if defined(__MMI_FILE_USEAS_SUPPORT__)
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_DOWNLOAD</MENUITEM_ID>
#endif /* __MMI_FILE_USEAS_SUPPORT__ */
    </MENU>   
#ifndef __MMI_PHNSET_WP_SLIM__    
    <MENU id = "MENU_SETTING_WALLPAPER_SYSTEM" type = "APP_SUB" str = "STR_WALLPAPER_SYSTEM">    
		#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) || defined(__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__)
        <MENUITEM_ID>MENU_SETTING_LIVE_WALLPAPER</MENUITEM_ID>
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__ */
        <MENUITEM_ID>MENU_SETTING_STATIC_WALLPAPER</MENUITEM_ID>
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
		<MENUITEM_ID>MENU_SETTING_VIDEO_WALLPAPER</MENUITEM_ID>
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */
#ifdef __MMI_AVATAR__
        <MENUITEM_ID>MENU_ID_PHNSET_WP_AVATAR</MENUITEM_ID>
#endif /* __MMI_AVATAR__ */
    </MENU>    
#else     
    <MENUITEM id = "MENU_SETTING_WALLPAPER_SYSTEM" str = "STR_WALLPAPER_SYSTEM"/> 
#endif           

    <MENUITEM id = "MENU_SETTING_WALLPAPER_DOWNLOAD" str = "STR_WALLPAPER_DOWNLOAD"/>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__)
    <MENUITEM id = "MENU_SETTING_LIVE_WALLPAPER" str = "STR_ID_WALLPAPER_LIVE_WALLPAPER"/>    
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__ */ 
    <MENUITEM id = "MENU_SETTING_STATIC_WALLPAPER" str = "STR_ID_STATIC_WALLPAPER"/>   
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)
    <MENUITEM id = "MENU_SETTING_VIDEO_WALLPAPER" str = "STR_ID_VIDEO_WALLPAPER"/>
#endif /* __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ */ 

#ifdef __MMI_AVATAR__    
    <MENUITEM id = "MENU_ID_PHNSET_WP_AVATAR" str = "STR_ID_PHNSET_WP_AVATAR"/>
#endif /* __MMI_AVATAR__ */    

#ifdef __MMI_SUB_WALLPAPER__

    <!-- wallpaper subLCD main menu -->
    <MENU id = "MENU_SETTING_WALLPAPER_SUB" type = "APP_SUB" str = "STR_SETTING_WALLPAPER_SUB">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SYSTEM</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_DOWNLOAD</MENUITEM_ID>
    </MENU>   
    
#endif /* __MMI_SUB_WALLPAPER__ */ 

#endif /* __DAILY_WALLPAPER__ */

    <!-- For file manager service handler -->
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
	<MENUITEM id = "MENU_ID_FMGR_FWD_HOME_WALLPAPER" str = "STR_ID_HOMESCREEN_WALLPAPER"/>
    <MENUITEM id = "MENU_ID_FMGR_FWD_LOCK_WALLPAPER" str = "STR_ID_LOCKSCREEN_WALLPAPER"/>
#else /* __MMI_VUI_SCREEN_LOCK_KEY__ */
    <MENUITEM id = "MENU_ID_FMGR_FWD_WALLPAPER" str = "STR_GLOBAL_WALLPAPER"/>
#endif /* __MMI_VUI_SCREEN_LOCK_KEY__ */

#ifdef __MMI_SUB_WALLPAPER__
    <MENUITEM id = "MENU_ID_FMGR_FWD_SUB_WALLPAPER" str = "STR_SETTING_WALLPAPER_SUB"/>    
#endif /* __MMI_SUB_WALLPAPER__ */
    <FILE_TYPES>
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__		
		<FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_HOME_WALLPAPER" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_wallpaper_hdlr"/>
		<FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_LOCK_WALLPAPER" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_wallpaper_hdlr"/>
#else /* __MMI_VUI_SCREEN_LOCK_KEY__ */
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_WALLPAPER" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_wallpaper_hdlr"/>
#endif /* __MMI_VUI_SCREEN_LOCK_KEY__ */
#ifdef __MMI_SUB_WALLPAPER__
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_SUB_WALLPAPER" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_sub_wallpaper_hdlr"/>
#endif /* __MMI_SUB_WALLPAPER__ */        
    </FILE_TYPES>
    

#else /* __MMI_FILE_MANAGER__ */


#ifdef __DAILY_WALLPAPER__   /* Wallpaper daily change */    

    <MENU id = "MENU_SETTING_WALLPAPER" type = "APP_SUB" str = "STR_GLOBAL_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_FIX</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_ROTATE</MENUITEM_ID>
    </MENU>
    <MENUITEM id = "MENU_SETTING_WALLPAPER_FIX" str = "STR_WALLPAPER_FIX"/>
    <MENUITEM id = "MENU_SETTING_WALLPAPER_ROTATE" str = "STR_WALLPAPER_ROTATE"/>
    
#ifdef __MMI_SUB_WALLPAPER__

    <MENU id = "MENU_SETTING_WALLPAPER_SUB" type = "APP_SUB" str = "STR_SETTING_WALLPAPER_SUB">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_FIX</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_ROTATE</MENUITEM_ID>
    </MENU>

#endif /* __MMI_SUB_WALLPAPER__ */

#else /* __DAILY_WALLPAPER__ */ /* No wallpaper daily change, normal case */

    <MENUITEM id = "MENU_SETTING_WALLPAPER" str = "STR_GLOBAL_WALLPAPER"/>
    <MENU id = "MENU_SETTING_WALLPAPER_HOMESCREEN" str = "STR_ID_HOMESCREEN_WALLPAPER"/>
	<MENUITEM id = "MENU_SETTING_WALLPAPER_SYSTEM" str = "STR_WALLPAPER_SYSTEM"/>
#ifdef __MMI_SUB_WALLPAPER__

    <MENUITEM id = "MENU_SETTING_WALLPAPER_SUB" str = "STR_SETTING_WALLPAPER_SUB"/>
    
#endif /* __MMI_SUB_WALLPAPER__ */ 

#endif /* __DAILY_WALLPAPER__ */

#endif /* __MMI_FILE_MANAGER__ */
#endif

#ifdef __MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__
    <THEME>
    <IMAGE id="IMG_ID_APP_LIST_THEME_WALLPAPER_0">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\wall01.jpg"</IMAGE>
    </THEME>
#endif
<SENDER id="EVT_ID_PHNSET_WALLPAPER_CHANGED_NOTIFY" hfile="PhoneSetupGprots.h"/>	
<SENDER id="EVT_ID_PHNSET_SUBWALLPAPER_CHANGED_NOTIFY" hfile="PhoneSetupGprots.h"/>	

#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
    <RECEIVER id="EVT_ID_PHNSET_APPICON_CHANGED" proc="mmi_phset_wallpaper_change_cb"/>
#endif

#ifdef __MMI_USB_SUPPORT__
<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_phnset_wp_ss_pwr_disp_ms_hdlr"/>
<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_phnset_wp_ss_pwr_disp_ms_hdlr"/>
#endif

    <CACHEDATA type="double" id="NVRAM_DISPCHAR_AVATAR_WPSS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> avatar wallpaper and ss setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NARAM_DISPCHAR_AVATAR_ONOFF" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> avatar pwr on and off setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> wallpaper and ss serial num </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> pwr on and off serial num </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_WALLPAPER_ROTATE_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> wallpaper rotate status </DESCRIPTION>
    </CACHEDATA>    

    <CACHEDATA type="byte" id="NVRAM_PHNSET_LIVE_WALLPAPER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Live Wallpaper setting </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__    
    <CACHEDATA type="byte" id="NVRAM_PHNSET_VLW_WALLPAPER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Pluto Launcher Wallpaper setting </DESCRIPTION>
    </CACHEDATA>
#endif

#ifdef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__    
    <CACHEDATA type="byte" id="NVRAM_PHNSET_IVLW_WALLPAPER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Pluto Launcher IVLW Wallpaper setting </DESCRIPTION>
    </CACHEDATA>
#endif

    <CACHEDATA type="short" id="NVRAM_FUNANDGAMES_SETWALLPAPER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current wallpaper id </DESCRIPTION>
        #ifndef __MMI_VUI_HOMESCREEN_WALLPAPER__
        <FIELD>
            #if (__MMI_WALLPAPER_NUM__ >= 1) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 1"> [0x01, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 2) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 2"> [0x02, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 3) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 3"> [0x03, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 4) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 4"> [0x04, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 5) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 5"> [0x05, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 6) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 6"> [0x06, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 7) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 7"> [0x07, 0x00] </OPTION>
            #endif
            #if (__MMI_WALLPAPER_NUM__ >= 8) || !defined(__MMI_WALLPAPER_NUM__)
            <OPTION hint="Image 8"> [0x08, 0x00] </OPTION>
            #endif
        </FIELD>          
        #endif /* __MMI_VUI_HOMESCREEN_WALLPAPER__ */
    </CACHEDATA>

    <CACHEDATA type="short" id="RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SETWALLPAPER_SUB" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_SETWALLPAPER_SUB">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current sub wallpaper id </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="RESTORE_DEFAULT_SETWALLPAPER_SUB">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <!-- For screen lock wallpaper -->
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__    
    <CACHEDATA type="short" id="SCREEN_LOCK_WALLPAPER_STATIC_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="SCREEN_LOCK_WALLPAPER_LIVE_ID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif
</APP>

