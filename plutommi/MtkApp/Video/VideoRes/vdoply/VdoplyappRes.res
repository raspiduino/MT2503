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
*  VdoPlyRes.res
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
* Video Player resource population file
*
* Author:
* -------
*  Qiang Zhang (MTK80693)
*                      
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
*
* 04 03 2014 wenxian.zhao
* [MAUI_03489338] [Pre SQC][Video player] It show abnormal icon when seek to next or previous video file .
* .
*
* 11 25 2013 wenxian.zhao
* [MAUI_03476914] [BTMusic] Not asking user to disconnect BT Music firstly
* .
*
* 10 25 2013 wenxian.zhao
* [MAUI_03464289] [[Pluto Slim Phase3 IT Test] ]Video player can't enter Storage normally
* .
*
* 10 21 2013 wenxian.zhao
* [MAUI_03463174] [Pluto Slim][MSZ] Pluto slim checkin to 11C for MSZ
* .
 *
 * 07 17 2013 wenxian.zhao
 * [MAUI_03445461] [Video Player] Video not play for 1st time
 * .
 *
 * 07 16 2013 wenxian.zhao
 * [MAUI_03445461] [Video Player] Video not play for 1st time
 * .
 *
 * 02 02 2013 chengquan.dou
 * [MAUI_03326736] [3232FTE_Image] Some images which need to be removed still gen out
 * Remove loading ani.
 *
 * 01 21 2013 chengquan.dou
 * [MAUI_03318161] [MT6260 pre-SQC][Video Player] Red cross shown
 * Red cross shown when press mute icon.
 *
 * 01 02 2013 chengquan.dou
 * [MAUI_03305144] [Need Patch][Build Error] 11B.W13.01 build error for COBRAS60A_DEMO_gprs(FTE_SLIM_HVGA)
 * check in some str resource, which was removed before because of slim.
 *
 * 12 25 2012 chengquan.dou
 * [MAUI_03299772] 11B check in slim modify
 * Check in slim modify to 11B.
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 06 11 2012 sameer.sethi
 * [MAUI_03200928] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 05 07 2012 sameer.sethi
 * [MAUI_03181398] video player slim image checkin
 * .
 *
 * 03 14 2012 qiang.zhang
 * [MAUI_03148308] [Need Patch] [Sanity Fail] Sanity Test of   11B_LUFFY76V3_DEMO_HSPA(3G_SWITCH_FTE).W12.12  Video Streaming  is Fail!!
 * .
 *
 * 03 10 2012 qiang.zhang
 * [MAUI_03143414] Video player_3D icon is not showing although mode switching is happening on tapping the region.
 * .
 *
 * 03 07 2012 qiang.zhang
 * [MAUI_03143743] [Pluto Memory Enhancement] Merge ASM and MED
 * .
 *
 * 02 24 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 02 21 2012 qiang.zhang
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 12 29 2011 qiang.zhang
 * [MAUI_03086845] [SIM Recovery]when plug out sim card,now should not enter data account list
 * .
 *
 * 12 06 2011 qiang.zhang
 * [MAUI_03090584] [FMGR] It will display abnormal while playing video file.
 * .
 *
 * 11 22 2011 qiang.zhang
 * [MAUI_03083736] [Need help] 11B.W11.44 build error for LION52_V2_3232_gprs
 * .
 *
 * 09 29 2011 qiang.zhang
 * [MAUI_03031853] [Media player&Video player]2D 3D video switch support
 * .
 *
 * 09 29 2011 qiang.zhang
 * [MAUI_03039075] [Need Patch][Build Error] 11B.W11.38 build error for ATOM52_V1_DEMO_gprs(MRE_SDK_VENDOR)
 * .
 *
 * 09 20 2011 qiang.zhang
 * [MAUI_03022471] [player]mmi features reduction
 * .
 *
 * 09 13 2011 qiang.zhang
 * [MAUI_03026249] [FTE Launcher] integration and check-in
 * .
 *
 * 08 30 2011 qiang.zhang
 * [MAUI_03013017] [BT]The bt connecting animation show abnormal
 * .
 *
 * 08 23 2011 qiang.zhang
 * [MAUI_03011091] [Video Player]revise mmi video features config
 * .
 *
 * 08 01 2011 qiang.zhang
 * [MAUI_02995141] [Video]when play this video, it will always play but total time shows 0s
 * .
 *
 * 07 06 2011 qiang.zhang
 * [MAUI_02961578] [Video Player]Slim code check in
 * .
 *
 * 06 30 2011 qiang.zhang
 * [MAUI_02961578] [Video Player]Slim code check in
 * .
 *
 * 06 17 2011 qiang.zhang
 * [MAUI_02961578] [Video Player]Slim code check in
 * .
 *
 * 06 14 2011 qiang.zhang
 * [MAUI_02961578] [Video Player]Slim code check in
 * .
 *
 * 06 13 2011 qiang.zhang
 * [MAUI_02961281] [Video Player]3232 slim video player hal revise code check in
 * .
 *
 * 05 14 2011 qiang.zhang
 * [MAUI_02940655] [player]handle delete/update data account event
 * .
 *
 * 01 20 2011 qiang.zhang
 * [MAUI_02448839] [Gemini+][RTSP] No Invalid Proxy address pop up
 * .
 *
 * 01 12 2011 qiang.zhang
 * [MAUI_02647890] [video player]remove some unused string on slim project
 * .
 *
 * 12 27 2010 qiang.zhang
 * [MAUI_02645954] [video player]32+32 slim video player audio only amination show abnormal
 * .
 *
 * 12 23 2010 qiang.zhang
 * [MAUI_02645433] [video player]32+32 slim feature set compile option modify
 * .
 *
 * 12 21 2010 qiang.zhang
 * [MAUI_02644946] [video player]32+32 slim (low cost ultra video player) code check in
 * .
 *
 * 12 17 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 12 14 2010 qiang.zhang
 * [MAUI_02643312] [videoplayer, streamingOTAP]RHR code check in
 * .
 *
 * 12 07 2010 qiang.zhang
 * [MAUI_02643287] [videoplayer]Reduce vol image on slim project
 * .
 *
 * 12 07 2010 qiang.zhang
 * [MAUI_02643132] [video player]remove full screen osd resouce when full screen osd turn off
 * .
 *
 * 11 26 2010 aidan.hung
 * [MAUI_02842265] [FTO FMGR] Remove Pluto FMGR resource file on COSMOS project
 * Remove Pluto FMGR resource file on COSMOS project
 *
 * 11 25 2010 aidan.hung
 * [MAUI_02842272] [FTO FMGR] Fixed build error
 * Remove Pluto FMGR resource file from Cosmos project
 *
 * 11 19 2010 qiang.zhang
 * [MAUI_02641550] [Video player]move NVRAM to app res file
 * .
 *
 * 11 09 2010 qiang.zhang
 * [MAUI_02640258] [dialy build]
 * .
 *
 * 11 05 2010 qiang.zhang
 * [MAUI_02639832] [video player]move adjust compile option
 * .
 *
 * 11 05 2010 qiang.zhang
 * [MAUI_02639783] [videoplayer]build error check in
 * .
 *
 * 11 05 2010 qiang.zhang
 * [MAUI_02639783] [videoplayer]build error check in
 * .
 *
 * 11 02 2010 qiang.zhang
 * [MAUI_02639326] build error patch
 * .
 *
 * 11 01 2010 qiang.zhang
 * [MAUI_02639286] [video player]build error check in
 * .
 *
 * 10 29 2010 qiang.zhang
 * [MAUI_02639165] [Video player FW 10A Revise]Check in
 * .
 *
 *
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#include "custresdef.h"
#include "MMI_features_video.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VDOPLY"
name = "STR_ID_VDOPLY_APP_NAME"                    /* The string to be displayed under the main menu icon */
type="pluto"
#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_VIDEO_PLAYER__)
        package_name = "native.mtk.videoplayer"         /* Use "native.mtk." as the prefix of application name */
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
        img = "IMG_ID_VDOPLY_VUI_MAIN_MENU_APP_ICON"   /* Main menu icon image */
#endif
        launch = "mmi_vdoply_entry_app"               /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                         * the function prototype should be:
                                                         *
                                                         *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                         *
                                                         * Note that the group_id of the application should be returned if launch successfully.
                                                         * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
<INCLUDE file="GlobalResDef.h"/>
<INCLUDE file="MainMenuDef.h"/>
<INCLUDE file="CustomCfg.h"/>
#ifdef __PLUTO_MMI_PACKAGE__
<INCLUDE file="mmi_rp_app_filemanager_def.h"/>
#endif
#ifdef __MMI_A2DP_SUPPORT__
<INCLUDE file="mmi_rp_app_a2dp_def.h"/>
#endif

#ifdef __MMI_FTE_SUPPORT__
    #define VDOPLY_IMG_PATH_FTE CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\"
#endif

#ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
    #define VDOPLY_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\OSD_HOR\\\\"
#else
    #if defined(__DIRECT_SENSOR_SUPPORT__) && ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
        #define VDOPLY_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\OSD_VER_6223C\\\\"
    #else
        #define VDOPLY_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\OSD_VER\\\\"
    #endif
#endif

#ifdef __VDOPLY_FEATURE_SLIM_IMG_RES__
    #define VDOPLY_SLIM_PATH CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\"
    #define VDOPLY_SLIM_BG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\"
#endif

#ifdef __VDOPLY_FEATURE_FTE20__
    #define VDOPLY_SLIM_PATH CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\"
    #define VDOPLY_SLIM_BG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\"
#endif

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    #define VDOPLY_FULLSCR_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\OSD_FULLSCR\\\\"
#endif 

#ifdef __MMI_VIDEO_PLAYER__

<!-------------------------------------- Memory config area ------------------->
#ifdef __MMI_SUPPORT_ASMV2__
    <MEMORY heap= "0" extra_base="max(base(SRV_MDI_VDOPLY), base(SRV_MDI_STREAMING))" fg="VDOPLY_OSD_BUFFER_SIZE + max(fg(SRV_MDI_VDOPLY), fg(SRV_MDI_STREAMING))" inc="VdoplyGprot.h"/> 
#endif
<!--------------------------------------String resource area------------------->
    <STRING id="STR_ID_VDOPLY_APP_NAME"/>
    
    #ifdef __VDOPLY_FEATURE_LSK_OPTION__
    <STRING id="STR_ID_VDOPLY_OPTION_VIDEO_SETTING"/>
    #endif
    
    #ifdef MMI_VDOPLY_AUTO_CHANGE_STORAGE_FEATURE
    <STRING id="STR_ID_VDOPLY_NOTIFY_CHANGE_STORAGE_TO_MEMORY_CARD"/>
    #endif

    #ifdef MMI_VDOPLY_SHOW_STORAGE_IN_FILE_LIST
    <STRING id="STR_ID_VDOPLY_STORAGE_PHONE"/>
    <STRING id="STR_ID_VDOPLY_STORAGE_MEMORY_CARD"/>
    #endif
    
    #if defined(__MMI_VIDEO_STREAM__)
    <STRING id="STR_ID_VDOPLY_NETWORK_PROFILE"/>
    <STRING id="STR_ID_VDOPLY_NETWORK_ACTIVE_PROFILE"/>
    <STRING id="STR_ID_VDOPLY_NETWORK_EDIT_PROFILE"/>
    
    <STRING id="STR_ID_VDOPLY_NETWORK_PROFILE_NAME"/>
    <STRING id="STR_ID_VDOPLY_NETWORK_RENAME_PROFILE"/>
    
    <STRING id="STR_ID_VDOPLY_PROXY_USE_PROXY"/>
    <STRING id="STR_ID_VDOPLY_PROXY_ADDR"/>
    <STRING id="STR_ID_VDOPLY_PROXY_PORT"/>
    
    <STRING id="STR_ID_VDOPLY_LOWEST_UDP_PORT"/>
    <STRING id="STR_ID_VDOPLY_HIGHEST_UDP_PORT"/>
    
    <STRING id="STR_ID_VDOPLY_STREAMING_URL"/>
    <STRING id="STR_ID_VDOPLY_INPUT_URL"/>
    <STRING id="STR_ID_VDOPLY_PREDEFINED_URL"/>
    <STRING id="STR_ID_VDOPLY_HISTORY_URL"/>
    
    <STRING id="STR_ID_VDOPLY_OPTION_SAVE_CONNECTION"/>
    <STRING id="STR_ID_VDOPLY_EDIT_FILENAME"/>
    #endif

    <STRING id="STR_ID_VDOPLY_NOTIFY_STORAGE_NOT_READY"/>
    #ifdef __DRM_SUPPORT__
    <STRING id="STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE"/>
    #endif
    
    #ifdef __MMI_VIDEO_STREAM__ 
    <STRING id="STR_ID_VDOPLY_NOTIFY_CONNECT_FAILED"/>
    #endif
    
    #ifdef __MMI_VIDEO_PDL__
    <STRING id="STR_ID_VDOPLY_NOTIFY_PDL_TERMINATED"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_TEMINATE_PDL"/>
    #endif

    #ifdef __MMI_VIDEO_STREAM__
    <STRING id="STR_ID_VDOPLY_REMOVE_ALL"/>
    #endif    
       
    #ifdef __VDOPLY_FEATURE_LSK_OPTION__
    <STRING id="STR_ID_VDOPLY_NOT_SUPPORT_AUTO_REPEAT"/>
    <STRING id="STR_ID_VDOPLY_AUTO_REPEAT"/>
    
    #if defined(__VDOPLY_FEATURE_VIDEO_ADJUSTMENT__)
    <STRING id="STR_ID_VDOPLY_BRIGHTNESS"/>
    <STRING id="STR_ID_VDOPLY_CONTRAST"/>
    
    <STRING id="STR_ID_VDOPLY_ADJUST_N5"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_N4"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_N3"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_N2"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_N1"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_0"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_P1"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_P2"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_P3"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_P4"/>
    <STRING id="STR_ID_VDOPLY_ADJUST_P5"/>
    #endif
    #endif
    
    #if defined(__MMI_VIDEO_PDL__) || defined(__MMI_VIDEO_STREAM__)
    <STRING id="STR_ID_VDOPLY_NOTIFY_INVALID_SETTING"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_NETWORK_ERROR"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_INVALID_RESOLUTION"/>
    
    <STRING id="STR_ID_VDOPLY_NOTIFY_REMOVE_URL_CONFIRM"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_REMOVE_URL_ALL_CONFIRM"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_HISTORY_REMOVED"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_VALID_PROXY_PORT"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_VALID_HIGHEST_UDP_PORT"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_VALID_LOWEST_UDP_PORT"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_INVALID_UDP_PORT"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_INVALID_SERVER"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_FILE_TOO_LARGE"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_FLIGHT_MODE"/>
    <STRING id="STR_ID_VDOPLY_NOTIFY_CONFIRM_STREAMING"/>
    #endif
    
    #ifdef MMI_VDOPLY_3D_ANAGLYPH
    <STRING id="STR_ID_VDOPLY_PLAY_MODE"/>
    <STRING id="STR_ID_VDOPLY_3D_ONLY"/>
    #endif
    
    #ifdef __VDOPLY_FEATURE_SLIM_IMG_RES__
    <STRING id="STR_ID_VDOPLY_AUDIO_ONLY"/>
    #endif 
    
<!--------------------------------------Image resource area------------------->
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    <IMAGE id="IMG_ID_VDOPLY_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\VideoPlayer.png"</IMAGE>
#endif
#endif
    #ifdef  __VDOPLY_FEATURE_SLIM_IMG_RES__
    <IMAGE id="IMG_ID_VDOPLY_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Video\\\\VideoPlayer\\\\SB_VP.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON">VDOPLY_SLIM_PATH"button.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PLAY">VDOPLY_SLIM_PATH"play.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PAUSE">VDOPLY_SLIM_PATH"pause.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_STOP">VDOPLY_SLIM_PATH"stop.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_BACK">VDOPLY_SLIM_PATH"back.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_FORWARD">VDOPLY_SLIM_PATH"forward.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_FULLSCREEN">VDOPLY_SLIM_PATH"fullscreen.bmp"</IMAGE>    
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_VOL_NULL">VDOPLY_SLIM_PATH"vol_none.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_VOL_FULL">VDOPLY_SLIM_PATH"vol_full.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_0">VDOPLY_SLIM_PATH"0.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_1">VDOPLY_SLIM_PATH"1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_2">VDOPLY_SLIM_PATH"2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_3">VDOPLY_SLIM_PATH"3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_4">VDOPLY_SLIM_PATH"4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_5">VDOPLY_SLIM_PATH"5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_6">VDOPLY_SLIM_PATH"6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_7">VDOPLY_SLIM_PATH"7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_8">VDOPLY_SLIM_PATH"8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_9">VDOPLY_SLIM_PATH"9.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_COL">VDOPLY_SLIM_PATH"col.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_TITLE_BG">VDOPLY_SLIM_PATH"title.9slice.png"</IMAGE>    
    <IMAGE id="IMG_ID_VDOPLY_OSD_DISABLE">VDOPLY_SLIM_PATH"disable.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_HIGHLIGHT">VDOPLY_SLIM_PATH"highlight.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_BG">VDOPLY_SLIM_PATH"progress_bg.9slice.png"</IMAGE>
    #ifdef __MMI_VIDEO_PDL__
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_CATHE">VDOPLY_SLIM_PATH"progress_cathe.9slice.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_FILL">VDOPLY_SLIM_PATH"progress_fill.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_BG">VDOPLY_SLIM_PATH"process_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_FULL">VDOPLY_SLIM_PATH"progress_fill.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_EMPTY">VDOPLY_SLIM_PATH"progress_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_FILL">VDOPLY_SLIM_PATH"progress_fill.9slice.png"</IMAGE>
    #if defined(__VDOPLY_FEATURE_BT__)
        <IMAGE id="IMG_ID_VDOPLY_OSD_BT_CONNECTING">VDOPLY_SLIM_PATH"bt_connecting.gif"</IMAGE>
    #endif
    #ifdef __MMI_VIDEO_STREAM__
        <IMAGE id="IMG_ID_VDOPLY_OSD_CONNECTING">VDOPLY_SLIM_PATH"connecting.gif"</IMAGE>
    #endif
    
    #ifdef MMI_VDOPLY_3D_ANAGLYPH
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_OFF">VDOPLY_SLIM_PATH"3d_off.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_ON">VDOPLY_SLIM_PATH"3d_on.bmp"</IMAGE>
    #endif
    
    #elif defined(__VDOPLY_FEATURE_FTE20__)
    <IMAGE id="IMG_ID_VDOPLY_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\SB_VP.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Video\\\\VideoPlayer\\\\SB_VP.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PLAY">VDOPLY_SLIM_PATH"play.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PAUSE">VDOPLY_SLIM_PATH"pause.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_STOP">VDOPLY_SLIM_PATH"stop.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_BACK">VDOPLY_SLIM_PATH"next.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_FORWARD">VDOPLY_SLIM_PATH"prev.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_FULLSCREEN">VDOPLY_SLIM_PATH"fullscreen.png"</IMAGE> 
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_VOL_NULL">VDOPLY_SLIM_PATH"volume_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_VOL_FULL">VDOPLY_SLIM_PATH"volume_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_MUTE">VDOPLY_SLIM_PATH"speaker_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_MUTE_DOWN">VDOPLY_SLIM_PATH"speaker_HIGHLIGHT.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_UNMUTE">VDOPLY_SLIM_PATH"speaker_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_UNMUTE_DOWN">VDOPLY_SLIM_PATH"speaker_HIGHLIGHT.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_0">VDOPLY_SLIM_PATH"num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_1">VDOPLY_SLIM_PATH"num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_2">VDOPLY_SLIM_PATH"num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_3">VDOPLY_SLIM_PATH"num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_4">VDOPLY_SLIM_PATH"num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_5">VDOPLY_SLIM_PATH"num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_6">VDOPLY_SLIM_PATH"num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_7">VDOPLY_SLIM_PATH"num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_8">VDOPLY_SLIM_PATH"num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_9">VDOPLY_SLIM_PATH"num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_COL">VDOPLY_SLIM_PATH"num_col.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_OPTION_UP" >VDOPLY_SLIM_PATH"option.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_OPTION_DOWN" >VDOPLY_SLIM_PATH"option_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_BACK_UP" >VDOPLY_SLIM_PATH"back.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_BACK_DOWN" >VDOPLY_SLIM_PATH"back_down.png"</IMAGE>

    <IMAGE id="IMG_ID_VDOPLY_OSD_HIGHLIGHT">VDOPLY_SLIM_PATH"HIGHLIGHT.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_BG">VDOPLY_SLIM_PATH"MPLAYER_progress_bg.9slice.png"</IMAGE>
    #ifdef __MMI_VIDEO_PDL__
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_CATHE">VDOPLY_SLIM_PATH"MPLAYER_progress_md.9slice.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_FILL">VDOPLY_SLIM_PATH"MPLAYER_progress_fg.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_BG">VDOPLY_SLIM_PATH"process_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_FULL">VDOPLY_SLIM_BG_PATH"load_bg.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_EMPTY">VDOPLY_SLIM_PATH"MPLAYER_loading_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_FILL">VDOPLY_SLIM_PATH"MPLAYER_loading_fg.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM">VDOPLY_SLIM_PATH"MPLAYER_ANI_AUD_ONLY.png"</IMAGE>
    
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_OFF_BUTTON_UP" >VDOPLY_SLIM_PATH"MPLAYER_3d_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_OFF_BUTTON_DOWN" >VDOPLY_SLIM_PATH"MPLAYER_3d_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_BUTTON_DISABLE" >VDOPLY_SLIM_PATH"EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_ON_BUTTON_UP" >VDOPLY_SLIM_PATH"MPLAYER_3d_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_3D_ON_BUTTON_DOWN" >VDOPLY_SLIM_PATH"MPLAYER_3d_on_down.png"</IMAGE>
    #endif
    #else
    <IMAGE id="IMG_ID_VDOPLY_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\SB_VP.bmp"</IMAGE>
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PLAY">VDOPLY_IMG_PATH_FTE"VP_play_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PLAY_SEL">VDOPLY_IMG_PATH_FTE"VP_play_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PLAY_DIS">VDOPLY_IMG_PATH_FTE"VP_play_disable.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PAUSE">VDOPLY_IMG_PATH_FTE"VP_pause_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PAUSE_SEL">VDOPLY_IMG_PATH_FTE"VP_pause_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_PAUSE_DIS">VDOPLY_IMG_PATH_FTE"VP_pause_disable.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_STOP">VDOPLY_IMG_PATH_FTE"VP_stop_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_STOP_SEL">VDOPLY_IMG_PATH_FTE"VP_stop_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTON_STOP_DIS">VDOPLY_IMG_PATH_FTE"VP_stop_disable.png"</IMAGE>
    #endif

    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_EMPTY">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_loading_empty.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_FILL">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_loading_fill.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_LOADING_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_loading_bg.gif"</IMAGE>
    
    #ifdef __MMI_VIDEO_STREAM__
        <IMAGE id="IMG_ID_VDOPLY_OSD_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_connecting.gif"</IMAGE>
    #endif
    
    #if defined(__VDOPLY_FEATURE_BT__)
    <IMAGE id="IMG_ID_VDOPLY_OSD_BT_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_bt_connecting.gif"</IMAGE>
    #endif
    
    <IMAGE id="IMG_ID_VDOPLY_OSD_OPENING">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_opening.gif"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SNAPSHOTING">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_snapshoting.gif"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoPlayer\\\\VP_aud_only.gif"</IMAGE>

    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_OSD_BG">VDOPLY_IMG_PATH_FTE"VP_transparent_backgro.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_OSD_BG">VDOPLY_OSD_PATH"VP_bg.gif"</IMAGE>
    #endif

    <IMAGE id="IMG_ID_VDOPLY_OSD_BUTTOM_BAR_BG">VDOPLY_OSD_PATH"VP_buttombar_bg.bmp"</IMAGE>
    
    #ifdef __VDOPLY_FEATURE_SPEED__
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_50">VDOPLY_OSD_PATH"VP_speed_50.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_75">VDOPLY_OSD_PATH"VP_speed_75.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_100">VDOPLY_OSD_PATH"VP_speed_100.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_125">VDOPLY_OSD_PATH"VP_speed_125.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_150">VDOPLY_OSD_PATH"VP_speed_150.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_200">VDOPLY_OSD_PATH"VP_speed_200.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_400">VDOPLY_OSD_PATH"VP_speed_400.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_800">VDOPLY_OSD_PATH"VP_speed_800.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_FWD">VDOPLY_OSD_PATH"VP_speed_fwd.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_BWD">VDOPLY_OSD_PATH"VP_speed_bwd.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_SPEED_UNDEF">VDOPLY_OSD_PATH"VP_speed_undef.bmp"</IMAGE>
    #endif

    #ifdef __VDOPLY_FEATURE_VOLUME__
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_BG">VDOPLY_IMG_PATH_FTE"VP_volume_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_FG">VDOPLY_IMG_PATH_FTE"VP_volume_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_SPEAKER_ON">VDOPLY_IMG_PATH_FTE"VP_speaker_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_SPEAKER_ON_SEL">VDOPLY_IMG_PATH_FTE"VP_speaker_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_SPEAKER_OFF">VDOPLY_IMG_PATH_FTE"VP_speaker_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_SPEAKER_OFF_DOWN">VDOPLY_IMG_PATH_FTE"VP_speaker_off_down.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_1">VDOPLY_OSD_PATH"VP_vol_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_2">VDOPLY_OSD_PATH"VP_vol_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_3">VDOPLY_OSD_PATH"VP_vol_3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_4">VDOPLY_OSD_PATH"VP_vol_4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_5">VDOPLY_OSD_PATH"VP_vol_5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_6">VDOPLY_OSD_PATH"VP_vol_6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_7">VDOPLY_OSD_PATH"VP_vol_7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_8">VDOPLY_OSD_PATH"VP_vol_8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_9">VDOPLY_OSD_PATH"VP_vol_9.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_10">VDOPLY_OSD_PATH"VP_vol_10.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_11">VDOPLY_OSD_PATH"VP_vol_11.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_12">VDOPLY_OSD_PATH"VP_vol_12.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_13">VDOPLY_OSD_PATH"VP_vol_13.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_14">VDOPLY_OSD_PATH"VP_vol_14.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_15">VDOPLY_OSD_PATH"VP_vol_15.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_16">VDOPLY_OSD_PATH"VP_vol_16.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_VOLUME_MUTE">VDOPLY_OSD_PATH"VP_vol_mute.bmp"</IMAGE>
    #endif
    #endif

    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_FILL">VDOPLY_IMG_PATH_FTE"VP_progress_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY">VDOPLY_IMG_PATH_FTE"VP_progress_bg.png"</IMAGE> 
    #else
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_FILL">VDOPLY_OSD_PATH"VP_progress_fill.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY">VDOPLY_OSD_PATH"VP_progress_empty.bmp"</IMAGE>
    #endif

    #ifdef __MMI_VIDEO_PDL__
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_BUFFER">VDOPLY_IMG_PATH_FTE"VP_progress_md.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_BUFFER">VDOPLY_OSD_PATH"VP_progress_buff.bmp"</IMAGE>
    #endif
    #endif   
 
    <IMAGE id="IMG_ID_VDOPLY_OSD_PROGRESS_DIS">VDOPLY_OSD_PATH"VP_progress_dis.bmp"</IMAGE>

    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_0">VDOPLY_IMG_PATH_FTE"VP_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_1">VDOPLY_IMG_PATH_FTE"VP_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_2">VDOPLY_IMG_PATH_FTE"VP_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_3">VDOPLY_IMG_PATH_FTE"VP_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_4">VDOPLY_IMG_PATH_FTE"VP_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_5">VDOPLY_IMG_PATH_FTE"VP_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_6">VDOPLY_IMG_PATH_FTE"VP_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_7">VDOPLY_IMG_PATH_FTE"VP_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_8">VDOPLY_IMG_PATH_FTE"VP_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_9">VDOPLY_IMG_PATH_FTE"VP_num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_COL">VDOPLY_IMG_PATH_FTE"VP_num_col.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_BIAS">VDOPLY_IMG_PATH_FTE"VP_num_diagonal.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_BG">VDOPLY_OSD_PATH"VP_timer_bg.bmp"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_0">VDOPLY_OSD_PATH"VP_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_1">VDOPLY_OSD_PATH"VP_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_2">VDOPLY_OSD_PATH"VP_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_3">VDOPLY_OSD_PATH"VP_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_4">VDOPLY_OSD_PATH"VP_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_5">VDOPLY_OSD_PATH"VP_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_6">VDOPLY_OSD_PATH"VP_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_7">VDOPLY_OSD_PATH"VP_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_8">VDOPLY_OSD_PATH"VP_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_9">VDOPLY_OSD_PATH"VP_num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_COL">VDOPLY_OSD_PATH"VP_num_col.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_BIAS">VDOPLY_OSD_PATH"VP_num_diagonal.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_OSD_TIMER_BG">VDOPLY_OSD_PATH"VP_timer_bg.bmp"</IMAGE>
    #endif

    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_CK_PLAY">VDOPLY_IMG_PATH_FTE"VP_play_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_PLAY_SEL">VDOPLY_IMG_PATH_FTE"VP_prev_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_PLAY_DIS">VDOPLY_IMG_PATH_FTE"VP_prev_disable.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_CK_PLAY">VDOPLY_OSD_PATH"VP_ck_play.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_PLAY_SEL">VDOPLY_OSD_PATH"VP_ck_play_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_PLAY_DIS">VDOPLY_OSD_PATH"VP_ck_play_dis.bmp"</IMAGE>
    #endif

    <IMAGE id="IMG_ID_VDOPLY_CK_PAUSE">VDOPLY_OSD_PATH"VP_ck_pause.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_PAUSE_SEL">VDOPLY_OSD_PATH"VP_ck_pause_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_PAUSE_DIS">VDOPLY_OSD_PATH"VP_ck_pause_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_RESUME">VDOPLY_OSD_PATH"VP_ck_resume.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_RESUME_SEL">VDOPLY_OSD_PATH"VP_ck_resume_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_CK_RESUME_DIS">VDOPLY_OSD_PATH"VP_ck_resume_dis.bmp"</IMAGE>
    
    
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
    #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_BG">VDOPLY_FULLSCR_OSD_PATH"VP_full_bg.gif"</IMAGE>
    
    #ifdef __VDOPLY_FEATURE_SPEED__
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_50">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_50.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_75">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_75.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_100">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_100.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_125">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_125.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_150">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_150.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_200">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_200.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_400">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_400.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_800">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_800.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_FWD">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_fwd.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_BWD">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_bwd.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_UNDEF">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_undef.bmp"</IMAGE>
    #endif
    
    #ifdef __VDOPLY_FEATURE_VOLUME__
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_1">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_2">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_3">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_4">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_5">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_6">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_7">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_8">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_9">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_9.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_10">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_10.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_11">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_11.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_12">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_12.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_13">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_13.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_14">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_14.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_15">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_15.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_16">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_16.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_MUTE">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_mute.bmp"</IMAGE>
    #endif
    
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_FILL">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_fill.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_EMPTY">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_empty.bmp"</IMAGE>
    
    #ifdef __MMI_VIDEO_PDL__
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_BUFFER">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_buff.bmp"</IMAGE>
    #endif
    
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_dis.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_0.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_1">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_2">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_3">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_4">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_5">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_6">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_7">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_8">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_9">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_9.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_COL">VDOPLY_FULLSCR_OSD_PATH"VP_full_num_col.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_BG">VDOPLY_FULLSCR_OSD_PATH"VP_full_timer_bg.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_play.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_play_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_play_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_PAUSE">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_pause.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_PAUSE_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_pause_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_PAUSE_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_pause_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_RESUME">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_resume.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_RESUME_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_resume_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_OSD_CK_RESUME_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_ck_resume_dis.bmp"</IMAGE>
    #endif
    #endif

    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC">VDOPLY_OSD_PATH"VP_vol_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC_SEL">VDOPLY_OSD_PATH"VP_vol_inc_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC_DIS">VDOPLY_OSD_PATH"VP_vol_inc_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC">VDOPLY_OSD_PATH"VP_vol_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC_SEL">VDOPLY_OSD_PATH"VP_vol_dec_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC_DIS">VDOPLY_OSD_PATH"VP_vol_dec_dis.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC">VDOPLY_OSD_PATH"VP_speed_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC_SEL">VDOPLY_OSD_PATH"VP_speed_inc_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC_DIS">VDOPLY_OSD_PATH"VP_speed_inc_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC">VDOPLY_OSD_PATH"VP_speed_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC_SEL">VDOPLY_OSD_PATH"VP_speed_dec_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC_DIS">VDOPLY_OSD_PATH"VP_speed_dec_dis.bmp"</IMAGE>
    
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC">VDOPLY_IMG_PATH_FTE"VP_next_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_SEL">VDOPLY_IMG_PATH_FTE"VP_next_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_DIS">VDOPLY_IMG_PATH_FTE"VP_next_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC">VDOPLY_IMG_PATH_FTE"VP_prev_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_SEL">VDOPLY_IMG_PATH_FTE"VP_prev_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_DIS">VDOPLY_IMG_PATH_FTE"VP_prev_disable.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC">VDOPLY_OSD_PATH"VP_progress_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_SEL">VDOPLY_OSD_PATH"VP_progress_inc_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_DIS">VDOPLY_OSD_PATH"VP_progress_inc_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC">VDOPLY_OSD_PATH"VP_progress_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_SEL">VDOPLY_OSD_PATH"VP_progress_dec_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_DIS">VDOPLY_OSD_PATH"VP_progress_dec_dis.bmp"</IMAGE>
    #endif

    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SNAPSHOT">VDOPLY_OSD_PATH"VP_snap.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SNAPSHOT_SEL">VDOPLY_OSD_PATH"VP_snap_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_SNAPSHOT_DIS">VDOPLY_OSD_PATH"VP_snap_dis.bmp"</IMAGE>
    
    #ifdef MMI_VDOPLY_3D_ANAGLYPH
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_3D_OFF">VDOPLY_IMG_PATH_FTE"VP_3d_off.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_3D_OFF_SEL">VDOPLY_IMG_PATH_FTE"VP_3d_off_SEL.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_3D_ON">VDOPLY_IMG_PATH_FTE"VP_3d_ON.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_3D_ON_SEL">VDOPLY_IMG_PATH_FTE"VP_3d_ON_SEL.png"</IMAGE>
    #else    /* __MMI_FTE_SUPPORT__ */
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_2D">VDOPLY_OSD_PATH"VP_3d_off.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_2D_SEL">VDOPLY_OSD_PATH"VP_3d_off_SEL.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_3D">VDOPLY_OSD_PATH"VP_3d_on.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_3D_SEL">VDOPLY_OSD_PATH"VP_3d_on_SEL.bmp"</IMAGE>
    #endif /* __MMI_FTE_SUPPORT__ */
    #endif
    
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN">VDOPLY_IMG_PATH_FTE"VP_fullscreen.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN_SEL">VDOPLY_IMG_PATH_FTE"VP_fullscreen_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN_DIS">VDOPLY_IMG_PATH_FTE"VP_fullscreen_disable.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN">VDOPLY_OSD_PATH"VP_fullscreen.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN_SEL">VDOPLY_OSD_PATH"VP_fullscreen_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN_DIS">VDOPLY_OSD_PATH"VP_fullscreen_dis.bmp"</IMAGE>
    #endif

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
    #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_INC">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_INC_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_inc_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_INC_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_inc_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_dec_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_vol_dec_dis.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_inc_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_inc_dis.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_dec_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_speed_dec_dis.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_inc.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_inc_sel.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_inc_dis.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_dec.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC_SEL">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_dec_sel.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC_DIS">VDOPLY_FULLSCR_OSD_PATH"VP_full_progress_dec_dis.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_RSK_BACK">VDOPLY_FULLSCR_OSD_PATH"VP_fullscr_rsk_back.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_LSK_PLAY">VDOPLY_FULLSCR_OSD_PATH"VP_fullscr_lsk_play.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_LSK_PAUSE">VDOPLY_FULLSCR_OSD_PATH"VP_fullscr_lsk_pause.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_FULLSCR_LSK_RESUME">VDOPLY_FULLSCR_OSD_PATH"VP_fullscr_lsk_resume.bmp"</IMAGE>
    #endif
    #endif

    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_RSK_BACK">VDOPLY_IMG_PATH_FTE"VP_back.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_BACK_SEL">VDOPLY_IMG_PATH_FTE"VP_back_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_STOP">VDOPLY_IMG_PATH_FTE"VP_stop_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_STOP_SEL">VDOPLY_IMG_PATH_FTE"VP_stop_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_STOP_DIS">VDOPLY_IMG_PATH_FTE"VP_stop_disable.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_RSK_BACK">VDOPLY_OSD_PATH"VP_rsk_back.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_BACK_SEL">VDOPLY_OSD_PATH"VP_rsk_back_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_STOP">VDOPLY_OSD_PATH"VP_rsk_stop.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_RSK_STOP_SEL">VDOPLY_OSD_PATH"VP_rsk_stop_sel.bmp"</IMAGE>
    #endif

    <IMAGE id="IMG_ID_VDOPLY_LSK_PLAY">VDOPLY_OSD_PATH"VP_lsk_play.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_PLAY_SEL">VDOPLY_OSD_PATH"VP_lsk_play_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_PAUSE">VDOPLY_OSD_PATH"VP_lsk_pause.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_PAUSE_SEL">VDOPLY_OSD_PATH"VP_lsk_pause_sel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_RESUME">VDOPLY_OSD_PATH"VP_lsk_resume.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_RESUME_SEL">VDOPLY_OSD_PATH"VP_lsk_resume_sel.bmp"</IMAGE>
    
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_VDOPLY_LSK_OPTION">VDOPLY_IMG_PATH_FTE"VP_opton.png"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_OPTION_SEL">VDOPLY_IMG_PATH_FTE"VP_option_down.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_VDOPLY_LSK_OPTION">VDOPLY_OSD_PATH"VP_lsk_option.bmp"</IMAGE>
    <IMAGE id="IMG_ID_VDOPLY_LSK_OPTION_SEL">VDOPLY_OSD_PATH"VP_lsk_option_sel.bmp"</IMAGE>
    #endif
    #endif

    
    
    
    
<!-------------------------------------------------------------------Screen resource area----------------------------------------------------------->
    <SCREEN id="SCR_ID_VDOPLY_START"/>
    <SCREEN id="GRP_ID_VDOPLY_APP"/>
    <SCREEN id="SCR_ID_VDOPLY_APP"/>
    <SCREEN id="GRP_ID_VDOPLY_PLAYER"/>
    <SCREEN id="GRP_ID_VDOPLY_STREAMING_URL"/>
    <SCREEN id="SCR_ID_VDOPLY_STREAMING_URL"/>
    <SCREEN id="SCR_ID_VDOPLY_PREDEFINED_URL"/>
    <SCREEN id="SCR_ID_VDOPLY_HISTORY_URL"/>
    <SCREEN id="GRP_ID_VDOPLY_HISTORY_OPTION"/>
    <SCREEN id="SCR_ID_VDOPLY_HISTORY_OPTION"/>
    <SCREEN id="GRP_ID_VDOPLY_URL_EDITOR"/>
    <SCREEN id="SCR_ID_VDOPLY_URL_EDITOR"/>
    <SCREEN id="SCR_ID_VDOPLY_URL_EDITOR_OPTION"/>
    <SCREEN id="GRP_ID_VDOPLY_SINGLE_PLAYER"/>
    <SCREEN id="SCR_ID_VDOPLY_PLAYER"/>
    <SCREEN id="SCR_ID_VDOPLY_OPTION"/>

    <SCREEN id="GRP_ID_VDOPLY_BROWSER"/>
    <SCREEN id="GRP_ID_VDOPLY_STORAGE"/>
    <SCREEN id="SCR_ID_VDOPLY_STORAGE"/>
    <SCREEN id="GRP_ID_VDOPLY_NETWORK_PROFILE"/>
    <SCREEN id="SCR_ID_VDOPLY_NETWORK_PROFILE"/>
    <SCREEN id="SCR_ID_VDOPLY_NETWORK_PROFILE_OPTION"/>
    <SCREEN id="GRP_ID_VDOPLY_NETWORK_PROFILE_EDIT"/>
    <SCREEN id="GRP_ID_VDOPLY_NETWORK_PROFILE_EDIT_DA"/>
    <SCREEN id="SCR_ID_VDOPLY_NETWORK_PROFILE_EDIT"/>
    <SCREEN id="SCR_ID_VDOPLY_NETWORK_PROFILE_RENAME"/>
    <SCREEN id="GRP_ID_VDOPLY_SETTINGS"/>
    <SCREEN id="GRP_ID_VDOPLY_ADJUST_OPTION"/>
    <SCREEN id="SCR_ID_VDOPLY_ADJUST_OPTION"/>
    <SCREEN id="GRP_ID_VDOPLY_STREAM_EDITOR"/>
    <SCREEN id="SCR_ID_VDOPLY_STREAM_EDITOR"/>
    <SCREEN id="SCR_ID_VDOPLY_STREAM_EDITOR_OPTION"/>
    <SCREEN id="SCR_ID_VDOPLY_END"/>


<!--------------------------------------Menu resource area-------------------> 
    <MENU id="MENU_ID_VDOPLY_APP" type="APP_MAIN" str="STR_ID_VDOPLY_APP_NAME" img="IMG_ID_VDOPLY_APP_ICON" highlight="mmi_vdoply_highlight_app">
    </MENU>
    
    <MENU id="MENU_ID_VDOPLY_FILE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_VDOPLY_PLAY</MENUITEM_ID>
                    #ifdef __PLUTO_MMI_PACKAGE__
                    <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_USE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_SORT</MENUITEM_ID>
                    #endif
                    <MENUITEM_ID>MENU_ID_VDOPLY_STREAMING_URL</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_NETWORK_PROFILE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_STORAGE</MENUITEM_ID>           
    </MENU>
    
    <MENU id="MENU_ID_VDOPLY_EMPTY_FOLDER_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_VDOPLY_STREAMING_URL</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_NETWORK_PROFILE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_STORAGE</MENUITEM_ID>           
    </MENU>
    
    <MENU id="MENU_ID_VDOPLY_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_VDOPLY_OPTION_VIDEO_SETTING</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_BLUETOOTH_SETTING</MENUITEM_ID>                    
    </MENU>
    
    <MENU id="MENU_ID_VDOPLY_OPTION_STREAMING" type="OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_VDOPLY_OPTION_VIDEO_SETTING</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_OPTION_SAVE_CONNECTION</MENUITEM_ID> 
                    <MENUITEM_ID>MENU_ID_VDOPLY_BLUETOOTH_SETTING</MENUITEM_ID>           
    </MENU>
    
    #ifdef __MMI_VIDEO_STREAM__
    <MENUITEM id="MENU_ID_VDOPLY_NETWORK_PROFILE" str="STR_ID_VDOPLY_NETWORK_PROFILE"/>
    #endif
    <MENU id="MENU_ID_VDOPLY_PLAY" str="STR_GLOBAL_PLAY" highlight="mmi_vdoply_highlight_play">
    </MENU>
    
    <MENUITEM id="MENU_ID_VDOPLY_STORAGE" str="STR_GLOBAL_STORAGE"/>
    
    
    #if defined(__MMI_VIDEO_STREAM__)
    <MENUITEM id="MENU_ID_VDOPLY_OPTION_SAVE_CONNECTION" str="STR_ID_VDOPLY_OPTION_SAVE_CONNECTION"/>
    <MENUITEM id="MENU_ID_VDOPLY_STREAM_EDITOR_OPTION" str="STR_GLOBAL_OPTIONS"/>
    #endif
    
    #if defined( __VDOPLY_FEATURE_BT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    <MENUITEM id="MENU_ID_VDOPLY_BLUETOOTH_SETTING" str="STR_ID_A2DP_BLUETOOTH_SETTINGS"/>
    #endif
    
     #ifdef __VDOPLY_FEATURE_LSK_OPTION__
    <MENUITEM id="MENU_ID_VDOPLY_OPTION_VIDEO_SETTING" str="STR_ID_VDOPLY_OPTION_VIDEO_SETTING"/>
    #endif
    
    #if defined(__MMI_VIDEO_STREAM__)
    <MENU id="MENU_ID_VDOPLY_HISTORY_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_VDOPLY_HISTORY_PLAY</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_HISTORY_REMOVE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_HISTORY_REMOVE_ALL</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_VDOPLY_HISTORY_PLAY" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_VDOPLY_HISTORY_REMOVE" str="STR_GLOBAL_REMOVE"/>
    <MENUITEM id="MENU_ID_VDOPLY_HISTORY_REMOVE_ALL" str="STR_ID_VDOPLY_REMOVE_ALL"/>
                      
    <MENU id="MENU_ID_VDOPLY_NETWORK_PROFILE_OPTION" str="STR_GLOBAL_OPTIONS">
                    <MENUITEM_ID>MENU_ID_VDOPLY_NETWORK_ACTIVE_PROFILE</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_NETWORK_EDIT_PROFILE</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_VDOPLY_NETWORK_ACTIVE_PROFILE" str="STR_ID_VDOPLY_NETWORK_ACTIVE_PROFILE"/>
    <MENUITEM id="MENU_ID_VDOPLY_NETWORK_EDIT_PROFILE" str="STR_ID_VDOPLY_NETWORK_EDIT_PROFILE"/>
    
    <MENU id="MENU_ID_VDOPLY_STREAMING_URL" type="OPTION" str="STR_ID_VDOPLY_STREAMING_URL">
                    <MENUITEM_ID>MENU_ID_VDOPLY_PREDEFINED_URL</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_HISTORY_URL</MENUITEM_ID>
                    <MENUITEM_ID>MENU_ID_VDOPLY_INPUT_URL</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_VDOPLY_INPUT_URL" str="STR_ID_VDOPLY_INPUT_URL"/>
    <MENUITEM id="MENU_ID_VDOPLY_PREDEFINED_URL" str="STR_ID_VDOPLY_PREDEFINED_URL"/>
    <MENUITEM id="MENU_ID_VDOPLY_HISTORY_URL" str="STR_ID_VDOPLY_HISTORY_URL"/>
    #endif
    
    #if defined(__MMI_VIDEO_STREAM__)    
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="mmi_vdoply_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="mmi_vdoply_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_vdoply_sim_unavailable_hdlr"/>
    #endif
    #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_vdoply_event_screen_locker_callback_hdlr"/>
    #endif
    #if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
    <RECEIVER id="EVT_ID_SRV_A2DP_CONNECT" proc="mmi_vdoply_a2dp_connect_callback_hdlr"/>
	#endif
#endif
    
    
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || (defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)) 
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_VOLUMN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x07] </DEFAULT_VALUE>   /* VDOPLY_VOL_8 */
        <DESCRIPTION> Video Player settings </DESCRIPTION>
        <FIELD min="0" max="16">
            <OPTION hint="level 0"> [0x00]</OPTION>
			<OPTION hint="level 1"> [0x01]</OPTION>
			<OPTION hint="level 2"> [0x02]</OPTION>
			<OPTION hint="level 3"> [0x03]</OPTION>
			<OPTION hint="level 4"> [0x04]</OPTION>
			<OPTION hint="level 5"> [0x05]</OPTION>
			<OPTION hint="level 6"> [0x06]</OPTION>
			<OPTION hint="level 7"> [0x07]</OPTION>
			<OPTION hint="level 8"> [0x08]</OPTION>
			<OPTION hint="level 9"> [0x09]</OPTION>
			<OPTION hint="level 10"> [0x0A]</OPTION>
			<OPTION hint="level 11"> [0x0B]</OPTION>
			<OPTION hint="level 12"> [0x0C]</OPTION>
			<OPTION hint="level 13"> [0x0D]</OPTION>
			<OPTION hint="level 14"> [0x0E]</OPTION>
			<OPTION hint="level 15"> [0x0F]</OPTION>
			<OPTION hint="mute"> [0x10]</OPTION>            
		</FIELD>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_ACTIVE_PROFILE_IDX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP1">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP2">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP3">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP4">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_ON_OFF">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_SNAPSHOT_SEQ_NO">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player Storage </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_BRIGHTNESS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_CONTRAST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_REPEAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_PLAY_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_VDOPLY_STREAM_SEQ_NO">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="double" id="NVRAM_VDOPLY_PROXY_PORT">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="double" id="NVRAM_VDOPLY_HIGHEST_UDP_PORT">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="double" id="NVRAM_VDOPLY_LOWEST_UDP_PORT">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>
    
#endif

    
</APP>
