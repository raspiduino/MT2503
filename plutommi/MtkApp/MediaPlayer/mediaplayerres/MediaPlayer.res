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
*	MediaPlayer.res
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media Player resource xml
*
* Author:
* -------
*   Baoqi Liu (mtk80496)
*
*==============================================================================
* HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 06 2013 deepak.singhrawat
 * [MAUI_03323779] [FTE slim] Media player is showing all red x
 * .
 *
 * 01 10 2013 deepak.singhrawat
 * [MAUI_03307357] [MT6260 pre-SQC] Image does not appear on static wallpaper to preview
 * Images changed to png in media player
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 06 26 2012 deepak.singhrawat
 * [MAUI_03206782] [video] VIdeo player OSD layout show abnormal .
 * .
 *
 * 06 08 2012 konark.mehra
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * Wrap image for media player icon
 *
 * 04 25 2012 qiang.zhang
 * [MAUI_03172209] [Pre-SQC][LD-Eng]Popup string need modification
 * .
 *
 * 03 20 2012 qiang.zhang
 * [MAUI_03149695] Video player_Pop out "Insufficient memory " always to play any video file
 * .
 *
 * 03 19 2012 qiang.zhang
 * [MAUI_03143588] [CHAMPAGNE55][FET][Mesiaplayer] After remove currently playing song from playlist , the widget show no song
 * .
 *
 * 03 16 2012 qiang.zhang
 * [MAUI_03150595] [ASAP][Need Patch] MAUI.11B.W11.32.MP.V19 build error for BXWY52_12864_11B_gprs
 * .
 *
 * 03 14 2012 qiang.zhang
 * [MAUI_03148308] [Need Patch] [Sanity Fail] Sanity Test of   11B_LUFFY76V3_DEMO_HSPA(3G_SWITCH_FTE).W12.12  Video Streaming  is Fail!!
 * .
 *
 * 03 12 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 03 07 2012 qiang.zhang
 * [MAUI_03143743] [Pluto Memory Enhancement] Merge ASM and MED
 * .
 *
 * 03 04 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 02 25 2012 qiang.zhang
 * [MAUI_03136739] [Player]modify brightness constract compile options
 * .
 *
 * 02 25 2012 qiang.zhang
 * [MAUI_03136739] [Player]modify brightness constract compile options
 * .
 *
 * 02 24 2012 qiang.zhang
 * [MAUI_03136739] [Player]modify brightness constract compile options
 * .
 *
 * 02 23 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 02 22 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 02 21 2012 qiang.zhang
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 02 08 2012 qiang.zhang
 * [MAUI_03123704] [Known Issue]option is not available while we change sound effect in media player
 * .
 *
 * 02 08 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 02 08 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 02 08 2012 qiang.zhang
 * [MAUI_03118648] [CMCC 20120109 New Case]本地功能][M]进入播放器，一键清空播放列表。
 * .
 *
 * 01 19 2012 qiang.zhang
 * [MAUI_03080711] [New design] Support .mkv files and subtitle
 * .
 *
 * 01 17 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 01 13 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 01 11 2012 qiang.zhang
 * [MAUI_03115645] [Media player]FTE2.0 code check in
 * .
 *
 * 01 06 2012 qiang.zhang
 * [MAUI_03081642] [Side-by-Side 3D Video] New Feature Check in
 * .
 *
 * 12 29 2011 qiang.zhang
 * [MAUI_03086845] [SIM Recovery]when plug out sim card,now should not enter data account list
 * .
 *
 * 12 13 2011 qiang.zhang
 * [MAUI_03097129] [DM][Lawmo] App/Srv split and cosmos implement
 * .
 *
 * 11 29 2011 qiang.zhang
 * [MAUI_03081642] [Side-by-Side 3D Video] New Feature Check in
 * .
 *
 * 11 16 2011 qiang.zhang
 * [MAUI_03080318] [Media player]dialy build error fix
 * .
 *
 * 11 10 2011 yan.liang
 * [MAUI_03077746] [MMI FRM]Fix callback manager spelling mistake
 * <saved by Perforce>
 *
 * 09 29 2011 qiang.zhang
 * [MAUI_03031853] [Media player&Video player]2D 3D video switch support
 * .
 *
 * 09 28 2011 qiang.zhang
 * [MAUI_03022471] [player]mmi features reduction
 * .
 *
 * 09 13 2011 qiang.zhang
 * [MAUI_03026249] [FTE Launcher] integration and check-in
 * .
 *
 * 08 10 2011 qiang.zhang
 * [MAUI_03003156] [Media player]FTE Slim support
 * .
 *
 * 08 10 2011 baoqi.liu
 * [MAUI_03002655] [@general]check in for FTE SLIM
 * .
 *
 * 07 26 2011 baoqi.liu
 * [MAUI_02986079] [LuffyV22][FTE][Shell AP-Audio Player] Player play status not update immediately
 * .
 *
 * 07 05 2011 qiang.zhang
 * [MAUI_02977560] [Media Player]wrap MENU_ID_FMGR_GEN_OPTION_MORE_RITS using __MMI_RMGR__
 * .
 *
 * 05 17 2011 qiang.zhang
 * [MAUI_02943351] [Media player]Porting media player key version to autocategory
 * .
 *
 * 05 13 2011 qiang.zhang
 * [MAUI_02940655] [player]handle delete/update data account event
 * .
 *
 * 03 15 2011 kinse.lin
 * [MAUI_02896210] [LuffyV22][FTE][Audio] Mediaplayer playing still no sound after swich mode back to General mode
 * .
 *
 * 03 01 2011 baoqi.liu
 * [MAUI_02653150] [@general]check in for USB
 * .
 *
 * 01 16 2011 ruoyao.liu
 * [MAUI_02648377] [Streaming][Case 71] User should can input HTTP URL in video player
 * .
 *
 * 12 31 2010 ruoyao.liu
 * [MAUI_02646417] HAL patch 1230
 * .
 *
 * 12 17 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 12 16 2010 baoqi.liu
 * [MAUI_02644103] [@general]check in for RHR build error
 * .
 *
 * 12 14 2010 baoqi.liu
 * [MAUI_02639654] [@general]check in for RHR
 * .
 *
 * 11 25 2010 aidan.hung
 * [MAUI_02842272] [FTO FMGR] Fixed build error
 * Remove Pluto FMGR resource file from Cosmos project
 *
 * 11 22 2010 baoqi.liu
 * [MAUI_02641602] [@general]check in for daily build error
 * .
 *
 * 11 22 2010 baoqi.liu
 * [MAUI_02641602] [@general]check in for daily build error
 * .
 *
 * 11 20 2010 baoqi.liu
 * [MAUI_02641602] [@general]check in for daily build error
 * .
 *
 * 11 18 2010 baoqi.liu
 * [MAUI_02641435] [@general]check in for NVRAM resource
 * .
 *
 * 11 05 2010 baoqi.liu
 * [MAUI_02639785] [@general]check in for callback mgr build error
 * .
 *
 * 11 01 2010 baoqi.liu
 * [MAUI_02639240] [@general]check in for mediaplayer callback manager revise
 * .
 *
 * 11 01 2010 baoqi.liu
 * [MAUI_02639240] [@general]check in for mediaplayer callback manager revise
 * .
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 10 11 2010 ruoyao.liu
 * [MAUI_02637091] the star level doesn't show after view the detail of a song
 * .
 *
 * 10 05 2010 ruoyao.liu
 * [MAUI_02636931] [PLST SRV ADV] plst service enhance check in
 * .
 *
 * 09 26 2010 kinse.lin
 * [MAUI_02623467] [Medply] check in event populate in reource
 * .
 *
 * 09 26 2010 kinse.lin
 * [MAUI_02623467] [Medply] check in event populate in reource
 * .
 *
 * 07 29 2010 baoqi.liu
 * [MAUI_02317548] not have kyro stores to downlod kuro file
 * .
 *
 * Jul 13 2010 mtk80496
 * [MAUI_02223994] [@general]check in for media player res
 * 
 *
 * Jul 12 2010 mtk80496
 * [MAUI_02220020] [@general]check in for mediaplayer enhancement (partial)
 * 
 *
 * Jul 8 2010 mtk80202
 * [MAUI_02220562] [APE] check in for new feature
 * 
 *
 * Jul 6 2010 mtk80496
 * [MAUI_02220020] [@general]check in for mediaplayer enhancement (partial)
 * 
 *
 * Jun 17 2010 mtk80202
 * [MAUI_02211298] Media player code clean for switch Audio/Video compile option.
 * 
 *
 * Jun 16 2010 mtk80496
 * [MAUI_02206032] media player not obey the rule of memory card
 * 
 *
 * May 31 2010 mtk80202
 * [MAUI_02200993] Image flow check in
 * 
 *
 * May 28 2010 mtk80496
 * [MAUI_02201832] [@general]Need patch .res
 * 
 *
 * May 27 2010 mtk80202
 * [MAUI_02200993] Image flow check in
 * 
 *
 * May 26 2010 mtk80496
 * [MAUI_02200781] [@general]check in for mediaplayer FW10A
 * 
 *
 * May 24 2010 mtk00676
 * [MAUI_02533917] [10A FW] Add confirm screen for reset database
 * 
 *
 * May 19 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 18 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 14 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 14 2010 mtk00676
 * [MAUI_02423863] [10A FW] Modify Media Player FTE for 10A framework change
 * 
 *
 * May 14 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 11 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 9 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 7 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * May 4 2010 mtk80144
 * [MAUI_02182067] [path] code check in 10A
 * 
 *
 * May 3 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * Apr 28 2010 mtk80496
 * [MAUI_02186167] check in for mediaplayermsghandler removing compile option
 * 
 *
 * Apr 28 2010 mtk80496
 * [MAUI_02185745] [@general]check in mediaplayer for FW10A_
 * 
 *
 * Apr 22 2010 mtk80496
 * [MAUI_02183313] [@general]check in for pre-sanity patch
 * 
 *
 * Apr 21 2010 mtk80496
 * [MAUI_02182177] [@general]check in for internal build error
 * 
 *
 * Apr 17 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * 
 *
 * Apr 16 2010 mtk00676
 * [MAUI_02398183] [MEDPLY]  Fix 10A build error for media player auto category
 * 
 *
 * Apr 13 2010 mtk80496
 * [MAUI_02179117] [@general]check in mediaplayer for FW10A
 * add to source control recursely
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __COSMOS_MMI_PACKAGE__

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h" 
#ifdef __MMI_MEDIA_PLAYER__

#include "CustResDef.h"         /* for image/audio path */
#include "mmi_features_mediaplayer.h"



/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_MEDPLY"
        name = "STR_ID_MEDPLY_APP_TITLE"                    /* The string to be displayed under the main menu icon */
        type="pluto"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
        package_name = "native.mtk.mediaplayer"         /* Use "native.mtk." as the prefix of application name */
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
        img = "IMG_ID_MEDPLY_VUI_MAIN_MENU_APP_ICON"   /* Main menu icon image */
    #endif 
        launch = "mmi_medply_app_pre_entry"               /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
                                                         * the function prototype should be:
                                                         *
                                                         *    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
                                                         *
                                                         * Note that the group_id of the application should be returned if launch successfully.
                                                         * If the application could not be launched for some reason, GRP_ID_INVALID should be returned. */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="MainMenuDef.h,GlobalResDef.h,GlobalMenuItems.h,SettingResDef.h,FunAndGamesResDef.h"/>
    <INCLUDE file="mmi_rp_app_filemanager_def.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>
 #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    <INCLUDE file="mmi_rp_srv_editor_def.h"/>
 #endif
 #ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    <INCLUDE file="mmi_rp_app_soundeffect_def.h"/>
 #endif
    <!----------------------------------------------------- Memory Config Area ----------------------------------------------------->
    <MEMORY heap= "0" extra_base="MMI_MEDPLY_MEM_POOL_SIZE + max3(base(SRV_MDI_AUDPLY)+base(SRV_MDI_AUD_INFO), base(SRV_MDI_VDOPLY_SUBTITLE), base(SRV_MDI_STREAMING))" fg="MEDPLY_MAIN_SCREEN_SCR_MEM_SIZE + max3(fg(SRV_MDI_AUDPLY), fg(SRV_MDI_VDOPLY_SUBTITLE), fg(SRV_MDI_STREAMING))" inc="MediaplayerGprot.h"/> 
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
	/* Populate MediaPlayer String Start */
	<STRING id="STR_ID_MEDPLY_APP_TITLE"/>
    <STRING id="STR_ID_MEDPLY_MSCR_NO_LYRICS_FILE"/>
    <STRING id="STR_ID_MEDPLY_MSCR_ERR_OPEN_LYRICS_FILE"/>
    <STRING id="STR_ID_MEDPLY_MSCR_ERR_DATA_LYRICS_FILE"/>
    <STRING id="STR_ID_MEDPLY_MAIN_SCREEN"/>
    <STRING id="STR_ID_MEDPLY_ALL_MEDIA"/>
    <STRING id="STR_ID_MEDPLY_NOW_PLAYING"/>
    <STRING id="STR_ID_MEDPLY_MY_PLAYLIST"/>
    <STRING id="STR_ID_MEDPLY_MUSIC_PLAYLIST"/>
    <STRING id="STR_ID_MEDPLY_ALL_AUDIO"/>
    <STRING id="STR_ID_MEDPLY_ALL_VIDEO"/>
	<STRING id="STR_ID_MEDPLY_HISTORY"/>
	<STRING id="STR_ID_MEDPLY_BOOKMARK"/>
	<STRING id="STR_ID_MEDPLY_STREAMING_URL"/>
	<STRING id="STR_ID_MEDPLY_CUR_PLAYLIST"/>
	<STRING id="STR_ID_MEDPLY_SHUFFLE"/>
	<STRING id="STR_ID_MEDPLY_REPEAT"/>
	<STRING id="STR_ID_MEDPLY_GO_TO_LIB"/>
	<STRING id="STR_ID_MEDPLY_PLAY_ALL_FAIL"/>
	<STRING id="STR_ID_MEDPLY_NO_EXIST_LIST_AVAILABLE"/>
	<STRING id="STR_ID_MEDPLY_NO_EXIST_LIST_AVAILABLE_EXT"/>
	<STRING id="STR_ID_MEDPLY_NO_RECENTLY_LIST_AVAILABLE"/>
	<STRING id="STR_ID_MEDPLY_NO_RECENTLY_LIST_AVAILABLE_EXT"/>
    
	//<STRING id="STR_ID_MEDPLY_SHUFFLE"/>
	//<STRING id="STR_ID_MEDPLY_REPEAT"/>
	<STRING id="STR_ID_MEDPLY_VDOREC"/>
	/*Error str*/
    /*common*/
	<STRING id="STR_ID_MEDPLY_ERR_INVALID_FILE"/>
	<STRING id="STR_ID_MEDPLY_ERR_OPEN_FAILED"/>
	<STRING id="STR_ID_MEDPLY_ERR_PLAY_FAILED"/>
    /*audio*/
	<STRING id="STR_ID_MEDPLY_ERR_DEVICE_BUSY"/>
	<STRING id="STR_ID_MEDPLY_ERR_NOT_SUPPORTED_SPEED"/>
	<STRING id="STR_ID_MEDPLY_ERR_NO_AUD_TRACK"/>
	<STRING id="STR_ID_MEDPLY_ERR_BUILD_CACHE_FAIL"/>
	<STRING id="STR_ID_MEDPLY_ERR_ADIF_NOT_SUPPORT_PAUSE"/>
	/*video*/
	<STRING id="STR_ID_MEDPLY_ERR_FILE_TOO_LARGE"/>
	<STRING id="STR_ID_MEDPLY_ERR_SNAPSHOT_FAILED"/>
	<STRING id="STR_ID_MEDPLY_ERR_VIDEO_ALREADY_FINISHED"/>
	<STRING id="STR_ID_MEDPLY_ERR_WRITE_PROTECTION"/>
	<STRING id="STR_ID_MEDPLY_ERR_CONNECT_FAILED"/>
	<STRING id="STR_ID_MEDPLY_ERR_INVALID_RESOLUTION"/>
	<STRING id="STR_ID_MEDPLY_ERR_NETWORK_ERROR"/>
	<STRING id="STR_ID_MEDPLY_ERR_NOT_SUPPORT_PURE_AUDIO"/>
    /*single*/
	<STRING id="STR_ID_MEDPLY_NOTIFY_CONFIRM_STREAMING"/>
    /*activate*/
	<STRING id="STR_ID_MEDPLY_KURO_ACTIVATE_NO_SONGS"/>
	<STRING id="STR_ID_MEDPLY_KURO_ACTIVATE_GET_TOTAL_FEE_FAIL"/>
	<STRING id="STR_ID_MEDPLY_KURO_FEE_PREFIX"/>
	<STRING id="STR_ID_MEDPLY_KURO_FEE_ONE_FILE"/>
	<STRING id="STR_ID_MEDPLY_KURO_FEE_ALL"/>
	/* Populate MediaPlayer String End */

	/* Populate MediaplayerPlaylist String Start */
	<STRING id="STR_ID_MEDPLY_PLST_TITLE"/>
	<STRING id="STR_ID_MEDPLY_PLST_LISTMGR"/>
	<STRING id="STR_ID_MEDPLY_PLST_MOVEUP"/>
	<STRING id="STR_ID_MEDPLY_PLST_MOVEDOWN"/>
	<STRING id="STR_ID_MEDPLY_PLST_NEW"/>
	<STRING id="STR_ID_MEDPLY_PLST_MY_FAVOURITE"/>
	<STRING id="STR_ID_MEDPLY_PLST_RECENTLY"/>
	<STRING id="STR_ID_MEDPLY_PLST_MOST"/>
	<STRING id="STR_ID_MEDPLY_PLST_ON_THE_FLY"/>
	<STRING id="STR_ID_MEDPLY_PLST_UNKNOWN_ARTIST"/>
	<STRING id="STR_ID_MEDPLY_PLST_UNKNOWN_ALBUM"/>
	<STRING id="STR_ID_MEDPLY_PLST_ORGANIZE_LIST"/>
	<STRING id="STR_ID_MEDPLY_PLST_MOVE"/>
	<STRING id="STR_ID_MEDPLY_PLST_INTRO"/>
	<STRING id="STR_ID_MEDPLY_PLST_ADD_TO"/>
	<STRING id="STR_ID_MEDPLY_PLST_ADD_MARKED"/>
	<STRING id="STR_ID_MEDPLY_PLST_ADD_TO_NOWPLAYING"/>
	<STRING id="STR_ID_MEDPLY_PLST_UPDATE_DB"/>
	<STRING id="STR_ID_MEDPLY_PLST_ADD_TO_BOOKMARK"/>
	<STRING id="STR_ID_MEDPLY_PLST_REMOVE_ALL"/>
	<STRING id="STR_ID_MEDPLY_PLST_NO_LIST_LOAD"/>
	<STRING id="STR_ID_MEDPLY_PLST_INPUT_URL"/>
	<STRING id="STR_ID_MEDPLY_PLST_CREATE_BOOKMARK"/>
	<STRING id="STR_ID_MEDPLY_PLST_PREDEFINEDURL"/>
	<STRING id="STR_ID_MEDPLY_PLST_ADD_TO_CREATE"/>
	<STRING id="STR_ID_MEDPLY_PLST_REMOVE_ASK"/>
	<STRING id="STR_ID_MEDPLY_PLST_REMOVE_ALL_ASK"/>
	<STRING id="STR_ID_MEDPLY_PLST_CLEAR_LIST"/>
	<STRING id="STR_ID_MEDPLY_LISTMGR_OPT_NEW"/>
	<STRING id="STR_ID_MEDPLY_PLST_CANCELED"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_ARTIST"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_ALBUM"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_TITLE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_GENRE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_YEAR"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_CHANNEL"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_BITRATE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_SAMPLE_RATE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_QUALITY"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_SIZE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_MONO"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STEREO"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_LAST_MODIFIED"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_LAST_PLAYED"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_DURATION"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_AUTHOR"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_PLAY_COUNT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_USER_RATING"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_SINGLE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_MULTIPLE"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_0"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_1"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_2"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_3"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_4"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_5"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_FORMAT"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_LOCAL"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_VOLUME"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_UNKNOWN"/>
	<STRING id="STR_ID_MEDPLY_PLST_DETAILS_NEVER_PLAYED"/>
	<STRING id="STR_ID_MEDPLY_PLST_SET_RATING"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_BEFORE_UPDATE"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_UPDATE"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_INIT"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_LIST_FULL"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_EMPTY_LIST"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_WRITE_FAILED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_READ_FAILED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_UNKNOWN_ERROR"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_NO_SPACE"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_CREATE_FAILED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_OPEN_FAILED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_DAMAGED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_INVALID"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_WRONG_VERSION"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_REMOVE_ASK"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_DELETE_ASK"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_REMOVE_ALL_ASK"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_PRESS_STAR"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_PRESS_CENTER"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_TOUCH_BOX"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_PRESS_STAR_TOUCH_BOX"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_PRESS_CENTER_TOUCH_BOX"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_FLIGHT_MODE"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_INVALID_CURRENT_PLST"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_DB_ERROR"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_PARSE_FILE_FAILED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_INIT_DB_FAILED"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_ALREADY_EXIST"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_NOTADB"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_IOERROR"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_CANTOPEN"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_DBCORRUPT"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_ASKREBUILD"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_NO_CONDITION"/>
	<STRING id="STR_ID_MEDPLY_PLST_NOTIFY_NOT_FOUND"/>
	<STRING id="STR_ID_MEDPLY_PLST_SEARCH_RESULTS"/>
	<STRING id="STR_ID_MEDPLY_PLST_FOUND"/>
	<STRING id="STR_ID_MEDPLY_PLST_APPENDED"/>
	<STRING id="STR_ID_MEDPLY_PLST_FOUND_ONE"/>
	<STRING id="STR_ID_MEDPLY_PLST_APPENDED_ONE"/>
	<STRING id="STR_ID_MEDPLY_PLST_FAILED"/>
	<STRING id="STR_ID_MEDPLY_BMK_OPT_SAVE_CONNECTION"/>
	<STRING id="STR_ID_MEDPLY_PLST_INSERT_CARD"/>
	<STRING id="STR_ID_MEDPLY_PLST_CARD_REMOVED"/>
	<STRING id="STR_ID_MEDPLY_PLST_CARD_REMOVED_AND_USE"/>
	<STRING id="STR_ID_MEDPLY_PLST_ADD_TO_PLAYLIST"/>
	<STRING id="STR_ID_MEDPLY_CLEAR_PLST"/>
	/* Populate MediaplayerPlaylist String End */
	
	/* Populate Mediaplayersettings String Start */
	<STRING id="STR_ID_MEDPLY_SETTINGS_PLAYER"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_AUDIO"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_VIDEO"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_BLUETOOTH"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_NETWORK"/>
    /* Player settings */
	<STRING id="STR_ID_MEDPLY_SKIN"/>
	<STRING id="STR_ID_MEDPLY_SKIN_THEME"/>
	<STRING id="STR_ID_MEDPLY_SKIN_FROM_THEME"/>
	<STRING id="STR_ID_MEDPLY_SKIN_FROM_FILE"/>
	<STRING id="STR_ID_MEDPLY_DEFAULT_STORAGE"/>
	<STRING id="STR_ID_MEDPLY_BG_PLAY"/>
	<STRING id="STR_ID_MEDPLY_SOUND_EFFECT"/>
	<STRING id="STR_ID_MEDPLY_SKIN_FILE_SELECTED"/>
	<STRING id="STR_ID_MEDPLY_SKIN_DELETED"/>
	<STRING id="STR_ID_MEDPLY_RESTORE_DEFAULT"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_AUTO_FULLSCR_BYSENSOR"/>
	/* Audio settings*/
	<STRING id="STR_ID_MEDPLY_AUDIO_PLAY_SPEED"/>
	<STRING id="STR_ID_MEDPLY_MAINSCR_DISP"/>
	<STRING id="STR_ID_MEDPLY_SPEED_FAST2"/>
	<STRING id="STR_ID_MEDPLY_SPEED_SLOW2"/>
	<STRING id="STR_ID_MEDPLY_SPECTRUM"/>
	<STRING id="STR_ID_MEDPLY_LYRICS"/>
	<STRING id="STR_ID_MEDPLY_ARTWORK"/>
    /* Video settings*/
	<STRING id="STR_ID_MEDPLY_BRIGHTNESS"/>
	<STRING id="STR_ID_MEDPLY_CONTRAST"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_PLAY_SPEED"/>
	<STRING id="STR_ID_MEDPLY_AUTO_FULSCR_DISP"/>
	<STRING id="STR_ID_MEDPLY_PLAY_BY_FRAME"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_N5"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_N4"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_N3"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_N2"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_N1"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_0"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_P1"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_P2"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_P3"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_P4"/>
	<STRING id="STR_ID_MEDPLY_ADJUST_P5"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED0"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED1"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED2"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED3"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED4"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED5"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED6"/>
	<STRING id="STR_ID_MEDPLY_VIDEO_SPEED7"/>

    /* Bluetooth settings*/
	<STRING id="STR_ID_MEDPLY_BT_STEREO_OUTPUT"/>
	<STRING id="STR_ID_MEDPLY_BT_STEREO_HEADSET"/>
    /* Network settings*/
	<STRING id="STR_ID_MEDPLY_PROFILE_NAME"/>
	<STRING id="STR_ID_MEDPLY_USER_PROXY"/>
	<STRING id="STR_ID_MEDPLY_PROXY_SERVER"/>
	<STRING id="STR_ID_MEDPLY_PROXY_PORT"/>
	<STRING id="STR_ID_MEDPLY_LOWEST_UDP_PORT"/>
	<STRING id="STR_ID_MEDPLY_HIGHEST_UDP_PORT"/>
	<STRING id="STR_ID_MEDPLY_RENAME_PROFILE"/>
	<STRING id="STR_ID_MEDPLY_REPEAT_ONE"/>
	<STRING id="STR_ID_MEDPLY_REPEAT_ALL"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_PROFILE1"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_PROFILE2"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_PROFILE3"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_PROFILE4"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_PROFILE5"/>
	<STRING id="STR_ID_MEDPLY_NOTIFY_IMG_UNFIT_FOR_SKIN"/>
    /* Error string*/
	<STRING id="STR_ID_MEDPLY_ERROR_FILE_TOO_LARGE"/>
	<STRING id="STR_ID_MEDPLY_ERROR_FILE_TOO_SMALL"/>
	<STRING id="STR_ID_MEDPLY_ERROR_TYPE_INDEX"/>
	<STRING id="STR_ID_MEDPLY_ERROR_VALID_PROXY"/>
	<STRING id="STR_ID_MEDPLY_ERROR_INVALID_PORT_ADDERSS"/>
	<STRING id="STR_ID_MEDPLY_ERROR_VALID_LOWEST_UDP"/>
	<STRING id="STR_ID_MEDPLY_ERROR_VALID_HIGHEST_UDP"/>
	<STRING id="STR_ID_MEDPLY_ERROR_VALID_UDP_PORT"/>
	<STRING id="STR_ID_MEDPLY_ERROR_CANNOT_USE_BLUETOOTH_IN_FLIGHT_MODE"/>
	<STRING id="STR_ID_MEDPLY_A2DP_BLOCK_SPECTRUM"/>
	<STRING id="STR_ID_MEDPLY_A2DP_BLOCK_PITCH"/>
	<STRING id="STR_ID_MEDPLY_A2DP_BLOCK_SPECTRUM_PITCH"/>
	<STRING id="STR_ID_MEDPLY_SETTINGS_ERR_MUST_SELECT_HEADSET"/>
	<STRING id="STR_ID_MEDPLY_BT_PROHIBIT_BY_SIMAP"/>
	/* Populate Mediaplayersettings String End */
	
	/* Populate Mediaplayerkurolist String Start */
	<STRING id="STR_ID_MEDPLY_KURO_LIST_NEWEST_SONG"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_AIRSONG"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HOTSONG"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_POPULAR_ARTIST"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_RECOMMEND_ALBUM"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_CONFIRM_PRE"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_CONFIRM_MID"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_CONFIRM_LAST"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_REPLACE"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_CONNECTING"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_WAITING"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_PROCESSING"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_COMPLETED"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_FAILED"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_MANAGER"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_TIMEOUT"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_CLUB"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_KUROSONG"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_ALL_SONGS"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_ALL_KURO_SONGS"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_PRESET_SONGS"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_SONGS"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_ACTIVATE_ASK"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_ADD_TO_PLAYLIST"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_ADD_AND_PLAY"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_ADD_TO"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DELETE_FILE"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DELETE_ASK"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOADLIST_WAITING"/>
	<STRING id="STR_ID_MEDPLY_PLST_SIM1"/>
	<STRING id="STR_ID_MEDPLY_PLST_SIM2"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DOWNLOAD_STOP"/>
	<STRING id="STR_ID_MEDPLY_KURO_DOWNLOAD_START_ALL"/>
	<STRING id="STR_ID_MEDPLY_KURO_DOWNLOAD_DELETE_ALL_COMPLETED"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_DELETE_ALL_ASK"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_SYS"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_AIRLOAD_TIMEOUT"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_AIRLOAD_FILE_OP"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_AIRLOAD_CONTEXT_FORMAT"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_AIRLOAD_ADD_DL_TASK"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_AIRLOAD_INVALID_INDEX"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_AIRLOAD_DOWNLOAD_FAILED"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_FILGHMODE"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_NOSIM"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_WIFI"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_INVALID_SIM"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_GIVEN_SIM_NOT_EXIST"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_UNKOWN_OPERATOR"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_SMS_BUSY"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_NO_SIM1"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_NO_SIM2"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_INVALID_SIM1"/>
	<STRING id="STR_ID_MEDPLY_KURO_ERR_INVALID_SIM2"/>
	<STRING id="STR_ID_MEDPLY_KURO_DOWNLOAD_BLOCK_BY_BT_PLAY"/>
	<STRING id="STR_ID_MEDPLY_KURO_NOTIFY_STOP_DOWNLOAD"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT1"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT2"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT3"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT4"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT5"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT6"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT7"/>
	<STRING id="STR_ID_MEDPLY_KURO_LIST_HELP_TEXT8"/>
	<STRING id="STR_ID_MEDPLY_KURO_STORE"/>
	/* Populate Mediaplayerkurolist String End */
	
	/* Populate Mediaplayerftelist String Start */
	<STRING id="STR_ID_MEDPLY_ALL_SONGS"/>
	<STRING id="STR_ID_MEDPLY_ARTISTS"/>
	<STRING id="STR_ID_MEDPLY_ALBUMS"/>
	<STRING id="STR_ID_MEDPLY_GENRES"/>
	<STRING id="STR_ID_MEDPLY_PLAYLISTS"/>
	<STRING id="STR_ID_MEDPLY_ALL_VIDEOS"/>
	<STRING id="STR_ID_MEDPLY_STREAMING_LINKS"/>
	<STRING id="STR_ID_MEDPLY_REFRESH_LIB"/>
	<STRING id="STR_ID_MEDPLY_ADDFRM_FLODER"/>
	<STRING id="STR_ID_MEDPLY_REMOVE_ALL"/>
	<STRING id="STR_ID_MEDPLY_USE_AS"/>
	<STRING id="STR_ID_MEDPLY_ADDTO_PLST"/>
	<STRING id="STR_ID_MEDPLY_MARKSVR"/>
	<STRING id="STR_ID_MEDPLY_EDIT_ALBUM"/>
	<STRING id="STR_ID_MEDPLY_IMAGE_FLOW"/>
	<STRING id="STR_ID_MEDPLY_GOTO_MAINMENU"/>
	<STRING id="STR_ID_MEDPLY_ALL_KURO_SONGS"/>
	<STRING id="STR_ID_MEDPLY_RESET_LIB"/>
	<STRING id="STR_ID_MEDPLY_RESET_CONFIRM"/>
	<STRING id="STR_ID_MEDPLY_PAUSE_CONFIRM"/>
	<STRING id="STR_ID_MEDPLY_FTE_LOADING"/>
	<STRING id="STR_ID_MEDPLY_FTE_SNAPSHOT"/>
	<STRING id="STR_ID_MEDPLY_FTE_OPENING"/>
	<STRING id="STR_ID_MEDPLY_FTE_BT_CONNECT"/>
	<STRING id="STR_ID_MEDPLY_FTE_RTP_CONNECT"/>
	<STRING id="STR_ID_MEDPLY_PLST_CANNOT_DELETE_ACTIVE"/>
	#ifdef __MMI_VIDEO_3D_ANAGLYPH__
	<STRING id="STR_ID_MEDPLY_PLAY_MODE"/>
	<STRING id="STR_ID_MEDPLY_3D_ONLY"/>
        #endif
  
 #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
 <STRING id="STR_ID_MEDPLY_SETTINGS_SUBTITLE_LANGUAGE"/>
 #endif
 <STRING id="STR_ID_MEDPLY_NCENTER_CLOSE_NOTIFY"/>
	/* Populate Mediaplayerftelist String End */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
/************************************ Main screen layout Start ****************************************************/
    <IMAGE id="IMG_ID_MEDPLY_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\SB_MPLAYER.bmp"</IMAGE>
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    <IMAGE id="IMG_ID_MEDPLY_VUI_MAIN_MENU_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\MediaPlayer.png"</IMAGE>
#endif 
    #endif
#ifndef __MMI_MEDIA_PLAYER_FTE__
    #if defined (__MMI_FTE_SUPPORT__)
    /*
    * FTE Changes:
    *                    - Remove background images change with theme background
    *                    - Remove unused images, cross
    *                    - Remove disabled images use 50% tranparency
    */
    #ifdef __MMI_FTE_SUPPORT_SLIM__
    /*FTE Key version revise*/
    /* For LQVGA the layout is different */

    #ifdef __MMI_MAINLCD_320X240__
    //<IMAGE id="IMG_ID_MEDPLY_BACK_GROUND" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_bg.9slice.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_BUTTON_BACKGROUND" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_Button_BG.png"</IMAGE>
    #else
    //<IMAGE id="IMG_ID_MEDPLY_BACK_GROUND" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\BG.9slice.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_BUTTON_BACKGROUND" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\Button_BG.png"</IMAGE>
    #endif

    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_EMPTY" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_loading_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_ONE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_TWO" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_THREE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_FOUR" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_FIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_SIX" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_SEVEN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_EIGHT" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_NINE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_COLON" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_col.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BIAS" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_diagonal.png"</IMAGE>
    <IMAGE id="IMG_ID_VOLUME_BAR" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_VOLUME_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_MUTE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_MUTE_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_META_DEFAULT_COVER" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_meta_def_cover.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_META_LINE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\line.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_HL_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>

    <IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\prev_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_LSK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_LSK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_LSK_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_RSK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_RSK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_RSK_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_ON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_ON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ONE_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_one_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ONE_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_one_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ALL_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_all_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ALL_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_all_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\fullscreen.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\fullscreen_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_snapshot_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_snapshot_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_snapshot_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_active_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_active_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_active_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_fg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg_disable.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_BG_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg_disable.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_MD" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_md.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_inc_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_inc_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_inc_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_dec_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_dec_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_dec_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STARS_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_user_rate_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STARS_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_user_rate_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VIDEO_SHADOW_TOP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_video_shadow_top.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VIDEO_SHADOW_BOTTOM" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_video_shadow_bottom.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_AUD_ONLY_ANIM" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_aud_only.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_OPENING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_video_open.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_SNAPSHOTING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_snapshoting.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_RTP_CONNECTING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_rtp_connect.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_BT_CONNECTING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_bt_connect.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\process_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_loading_fg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_FG_ANI" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\loading"</IMAGE>
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_off_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_3D_BUTTON_DISABLE" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_on_down.png"</IMAGE>
    #endif
    
    #else /*__MMI_FTE_SUPPORT_SLIM__*/
    <IMAGE id="IMG_ID_MEDPLY_BACK_GROUND" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MEDIAPLAYER_BG.png"</IMAGE>

    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_EMPTY" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_loading_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_ONE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_TWO" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_THREE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_FOUR" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_FIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_SIX" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_SEVEN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_EIGHT" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_NINE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_COLON" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_col.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BIAS" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_diagonal.png"</IMAGE>
    <IMAGE id="IMG_ID_VOLUME_BAR" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_VOLUME_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_MUTE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_MUTE_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_off_down.png"</IMAGE>    
    <IMAGE id="IMG_ID_MEDPLY_META_DEFAULT_COVER" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_meta_def_cover.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_META_LINE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\line.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_HL_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>

    <IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\prev_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_LSK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_LSK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_LSK_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_RSK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_RSK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_RSK_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_ON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_ON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_shuffle_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ONE_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_one_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ONE_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_one_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ALL_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_all_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ALL_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_repeat_all_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\fullscreen.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\fullscreen_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_snapshot_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_snapshot_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_snapshot_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_active_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_active_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_active_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_fg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg_disable.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_BG_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg_disable.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_MD" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_md.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_inc_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_inc_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_inc_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_dec_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_dec_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_volume_dec_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STARS_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_user_rate_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STARS_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_user_rate_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VIDEO_SHADOW_TOP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_video_shadow_top.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VIDEO_SHADOW_BOTTOM" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_video_shadow_bottom.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_AUD_ONLY_ANIM" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_aud_only.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_OPENING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_video_open.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_SNAPSHOTING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_snapshoting.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_RTP_CONNECTING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_rtp_connect.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_BT_CONNECTING" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_ani_bt_connect.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\process_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_loading_fg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_FG_ANI" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\loading"</IMAGE>
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_off_down.png"</IMAGE>
    //<IMAGE id="IMG_ID_MEDPLY_3D_BUTTON_DISABLE" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_3d_on_down.png"</IMAGE>
    #endif
    #endif /*__MMI_FTE_SUPPORT_SLIM__*/
    #else /* __MMI_FTE_SUPPORT__ */
	<IMAGE id="IMG_ID_MEDPLY_BACK_GROUND" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_BG.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_ONE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_TWO" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_THREE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_FOUR" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_FIVE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_SIX" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_SEVEN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_EIGHT" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BASIC_NUM_NINE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_COLON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_col.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_BIAS" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_num_diagonal.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_META_DEFAULT_COVER" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_meta_def_cover.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_play_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_play_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLAY_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_play_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_pause_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_pause_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PAUSE_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_pause_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_prev_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\MPLAYER_prev_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PREV_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\MPLAYER_prev_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_next_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_next_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_NEXT_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_next_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_stop_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_stop_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STOP_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_stop_disable.png"</IMAGE>
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_3d_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_3d_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_BUTTON_DISABLE" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_3d_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_3d_on_down.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_ON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_shuffle_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_ON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_shuffle_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_shuffle_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SHUFFLE_BUTTON_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_shuffle_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_repeat_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_repeat_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ONE_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_repeat_one_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ONE_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_repeat_one_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ALL_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_repeat_all_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_REPEAT_BUTTON_ALL_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_repeat_all_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_zoom_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_zoom_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ZOOM_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_zoom_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_snapshot_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_snapshot_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_SNAP_SHOT_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_snapshot_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_active_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_active_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_ACT_KEY_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_active_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_progress_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_progress_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_BG_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_progress_bg_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_DURATION_PROGRESS_BAR_MD" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_progress_md.png"</IMAGE>
    <IMAGE id="IMG_ID_VOLUME_BAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_VOLUME_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_inc_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_inc_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_INC_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_inc_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_dec_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_dec_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_DEC_BUTTON_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_volume_dec_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_speaker_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_speaker_on_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_MUTE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_speaker_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VOLUME_SPEAK_MUTE_BUTTON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_speaker_off_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STARS_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_user_rate_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_STARS_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_user_rate_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VIDEO_SHADOW_TOP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_video_shadow_top.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_VIDEO_SHADOW_BOTTOM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_video_shadow_bottom.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_AUD_ONLY_ANIM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_ani_aud_only.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_OPENING" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_ani_video_open.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_SNAPSHOTING" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_ani_snapshoting.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_RTP_CONNECTING" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_ani_rtp_connect.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_BT_CONNECTING" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_ani_bt_connect.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_loading_bg.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_OSD_LOADING_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MPLAYER_loading_fg.bmp"</IMAGE>
        #ifdef __MMI_KURO_SUPPORT__
    <IMAGE id="IMG_ID_MEDPLY_KURO_MUTE_VOICE_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_mute_voice_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_MUTE_VOICE_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_mute_voice_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_UNMUTE_VOICE_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_unmute_voice_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_UNMUTE_VOICE_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_unmute_voice_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_MUTE_VOICE_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_mute_voice_diable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_RISING_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_rising_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_RISING_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_rising_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_RISING_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_rising_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_FALLING_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_falling_up.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_FALLING_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_falling_down.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_FALLING_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_falling_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_TONEBAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_tone_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_TONEBAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_tone_fg.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_KURO_DEF_IMG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\kuro\\\\MPLAYER_kuro_def_bg.gif"</IMAGE>
        #endif /*__MMI_KURO_SUPPORT__*/
    #endif /*__MMI_FTE_SUPPORT__*/
#else /*!__MMI_MEDIA_PLAYER_FTE__*/
    <IMAGE id="IMG_ID_MEDPLY_FTE_AUDIO_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_BG_AUDIO.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VIDEO_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_BG_VIDEO.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_HL_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_HIGHLIGHT.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PLAY_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_PLAY.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PLAY_BTN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_PLAY_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PAUSE_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_PAUSE.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PAUSE_BTN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_PAUSE_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_STOP_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_STOP.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_STOP_BTN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_STOP_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PREV_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_PREVIOUS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PREV_BTN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_PREVIOUS_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_NEXT_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_NEXT.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_NEXT_BTN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_NEXT_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_LSK_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_OPTION.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RSK_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_BACK.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_ZOOM_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_FULLSCREEN.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_ZOOM_BTN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SK_FULLSCREEN_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_SHUFFLE_ON_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SHUFFLE_ON.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_SHUFFLE_OFF_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SHUFFLE_OFF.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_REPEAT_ONE_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_REPEAT_ONE.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_REPEAT_OFF_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_REPEAT_OFF.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_REPEAT_ALL_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_REPEAT_ALL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BTN0" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_0.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BTN1" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_1.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BTN2" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_2.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BTN3" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_3.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BTN4" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_4.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BTN5" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_5.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PROGRESS_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SCROLL_INDEX.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PROGRESS_BTN_HL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_SCROLL_INDEX_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PROGRESS_BAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_PROGRESS_FILL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PROGRESS_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_PROGRESS_EMPTY.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PROGRESS_BAR_MG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_PROGRESS_BUFFER.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_PROGRESS_BAR_BG_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_PROGRESS_EMPTY.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_COVER_DEFAULT" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_COVER_DEFAULT.PNG"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_SEPERATE_LINE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_LINE.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_SET_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_VOLUME_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_ON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_VOLUME_ON.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_VOLUME_OFF.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_VOLUME_EMPTY.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_VOLUME_TUNE.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_01.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_02.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_03.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_R1" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_04.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_R2" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_05.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_HL_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_01_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_HL_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_02_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_HL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_03_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_HL_R1" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_04_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_VOLUME_BTN_HL_R2" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\FMR_SCROLL_INDEX_05_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_POPUP_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_RATING_START" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_RATE_POPUP_STAR.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_LOADING_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_LOAD_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_LOADING_ANI" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\loading"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_AUDIO_ANI" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_FULLSCREEN_ANI.gif"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_ANI" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_FULLSCREEN_ANI_KURO.gif"</IMAGE>
    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_3D_OFF.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_OFF_BUTTON_HL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_3D_OFF_HL.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_BUTTON_DIS" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_3D_ON.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_3D_ON_BUTTON_HL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_3D_ON_HL.png"</IMAGE>
    #endif
    /*Kuro related*/ 
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_SET_BTN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_VOCAL_ON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_VOCAL_ON.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_VOCAL_ON_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_VOCAL_ON_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_VOCAL_OFF_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_VOCAL_OFF.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_VOCAL_OFF_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_VOCAL_OFF_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_VOCAL_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_VOCAL_ON_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_RISING_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_INC.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_RISING_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_INC_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_RISING_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_INC_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_FALLING_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_DEC.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_FALLING_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_DEC_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_FALLING_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_DEC_DIS.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_TONEBAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_TONEBAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_KEY_INDEX.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_UNLOCK_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_UNLOCK.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_UNLOCK_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_UNLOCK_DOWN.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FTE_KURO_UNLOCK_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\MP_KURO_UNLOCK_DIS.png"</IMAGE>
#endif /*!__MMI_MEDIA_PLAYER_FTE__*/
    /* Main screen layout End */

/************************************ List and Menu icon Start ****************************************************/
    /* list file icon */
#ifdef  __FTE_NON_SLIM_RES__
    /* Use PNG format icon */
    <IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_PLAYLIST_Creat.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_PLAYLIST.png"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_UNKNOWN_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_PLAYLIST_Creat.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_PLAYLIST.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_UNKNOWN_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
#endif

#if defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)
    <IMAGE id="IMG_ID_MEDPLY_FTE_ALL_SONGS" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\AP_ALLSONG.bmp"</IMAGE>
#endif

#if defined(__MMI_SLIM_IMG_RES__)
    /* details icon no used in slim */
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_DURATION" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_ARTIST" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_ALBUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_GENRE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_YEAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_TRACK_NUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LAST_MODIFIED" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LAST_PLAYED" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_AUTHOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_DESCRIPTION" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_PLAY_COUNT" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_USER_RATING" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LOCAL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_CHANNEL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_FILENAME" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_QUALITY" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_SIZE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
    /* Audio file icon */
    <IMAGE id="IMG_ID_MEDPLY_FILE_WAV_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_AMR_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_AAC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_AUD_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_MID_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_IMY_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_AWB_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_AIF_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_AU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_SND_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_M4A_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_MMF_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_WMA_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_3GP_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_MP4_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_BSAC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MEDPLY_FILE_APE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    /* Video file icon */
    <IMAGE id="IMG_ID_MEDPLY_FILE_VIDEO_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVIDEO.bmp"</IMAGE>
    /* Streaming icon */
    <IMAGE id="IMG_ID_MEDPLY_FILE_STREAM_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVSTREAM.bmp"</IMAGE>

#elif defined(__MMI_FTE_SUPPORT_SLIM__)

/* list file icon - already defined above */
//<IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_FILE_PLAYLIST_Creat.bmp"</IMAGE>
//<IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_FILE_PLAYLIST.bmp"</IMAGE>
//<IMAGE id="IMG_ID_MEDPLY_FILE_UNKNOWN_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>

/* details icon no used in slim */
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_DURATION" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_ARTIST" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_ALBUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_GENRE" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_YEAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_TRACK_NUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LAST_MODIFIED" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LAST_PLAYED" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_AUTHOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_DESCRIPTION" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_PLAY_COUNT" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_USER_RATING" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LOCAL" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_CHANNEL" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_FILENAME" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_QUALITY" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_SIZE" >CUST_IMG_PATH"\\\\MainLCD\\\\MultiMedia\\\\MP_unknown.bmp"</IMAGE>
/* Audio file icon */
<IMAGE id="IMG_ID_MEDPLY_FILE_WAV_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AMR_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AAC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AUD_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_MID_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_IMY_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AWB_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AIF_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_SND_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_M4A_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_MMF_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_WMA_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_3GP_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_MP4_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_BSAC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_APE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
/* Video file icon */
<IMAGE id="IMG_ID_MEDPLY_FILE_VIDEO_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVIDEO.bmp"</IMAGE>
/* Streaming icon */
<IMAGE id="IMG_ID_MEDPLY_FILE_STREAM_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVSTREAM.bmp"</IMAGE>

#else /*none SLIM*/

/* list file icon - already defined above */
//<IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_PLAYLIST_Creat.bmp"</IMAGE>
//<IMAGE id="IMG_ID_MEDPLY_FILE_PLAYLIST_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_PLAYLIST.bmp"</IMAGE>
//<IMAGE id="IMG_ID_MEDPLY_FILE_UNKNOWN_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_unknown.bmp"</IMAGE>
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)
//<IMAGE id="IMG_ID_MEDPLY_FTE_ALL_SONGS" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\AP_ALLSONG.bmp"</IMAGE>
#endif

/* details icon */
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_DURATION" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_TIME.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_TITLE.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_ARTIST" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_ARTIST.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_ALBUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_ALBUM.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_GENRE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_GENRE.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_YEAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_YEAR.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_TRACK_NUM" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_TRACK_NUMBER.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LAST_MODIFIED" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_REPEAT.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LAST_PLAYED" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_SPECTRUM.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_AUTHOR" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_TEXT_ENCODING.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_DESCRIPTION" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_words.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_copyright.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_PLAY_COUNT" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_BGPlay.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_USER_RATING" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_SHUFFLE.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_LOCAL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_PREFER_LIST.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_CHANNEL" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_CHANNEL.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_FILENAME" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_FILENAME.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_QUALITY" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_QUALITY.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_PLST_DETAILS_SIZE" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\Details\\\\MP_SIZE.bmp"</IMAGE>
/* Audio file icon */
<IMAGE id="IMG_ID_MEDPLY_FILE_WAV_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_WAV.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AMR_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_AMR.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AAC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_AAC.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AUD_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_MID_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_MID.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_IMY_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_IMY.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AWB_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\\MP_FILE_AWB.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AIF_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_AIF.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_AU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_AU.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_SND_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_SND.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_M4A_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_M4A.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_MMF_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_MMF.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_WMA_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_WMA.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_3GP_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_3GP.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_MP4_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_MP4.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_BSAC_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_BSAC.bmp"</IMAGE>
<IMAGE id="IMG_ID_MEDPLY_FILE_APE_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_APE.bmp"</IMAGE>
/* Video file icon */
<IMAGE id="IMG_ID_MEDPLY_FILE_VIDEO_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_VIDEO.bmp"</IMAGE>
/* Streaming icon */
<IMAGE id="IMG_ID_MEDPLY_FILE_STREAM_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\MediaPlayer\\\\playlist\\\\MP_FILE_STREAM.bmp"</IMAGE>

#endif /*__MMI_SLIM_IMG_RES__*/

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

/******************************************** app menu under main menu ***********************************************/
#if  defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
    <MENU id = "MENU_ID_MEDPLY_MAIN" type = "APP_MAIN" str = "STR_ID_MEDPLY_APP_TITLE" img = "MAIN_MENU_MEDPLY_ICON" highlight = "mmi_medply_highlight_app"
        shortcut="ON" shortcut_img="IMG_ID_MEDPLY_ICON" launch="mmi_medply_app_pre_entry"/>
    <MENU id = "MAIN_MENU_OPTION_MEDPLY_APP" type = "APP_MAIN" str = "STR_ID_MEDPLY_APP_TITLE" img = "IMG_ID_MEDPLY_ICON" highlight = "mmi_medply_highlight_app"/>
#else /*__MMI_BI_DEGREE_MAIN_MENU_STYLE__*/
    <MENU id = "MENU_ID_MEDPLY_MAIN" type = "APP_MAIN" str = "STR_ID_MEDPLY_APP_TITLE" img = "IMG_ID_MEDPLY_ICON" highlight = "mmi_medply_highlight_app"
        shortcut="ON" shortcut_img="IMG_ID_MEDPLY_ICON" launch="mmi_medply_app_pre_entry"/>
#endif   /*__MMI_BI_DEGREE_MAIN_MENU_STYLE__*/


#if defined  (__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
/******************************************** main menu list ***********************************************/
#ifdef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_AUDIO_VIDEO_SPLIT__
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_MY_PLAYLIST" str="STR_ID_MEDPLY_MUSIC_PLAYLIST"/>
#else
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_MY_PLAYLIST" str="STR_ID_MEDPLY_MY_PLAYLIST"/>
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */

    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_NOW_PLAYING" str="STR_ID_MEDPLY_NOW_PLAYING"/>
    
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_ALL_AUDIO" str="STR_ID_MEDPLY_ALL_AUDIO"/>
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_ALL_VIDEO" str="STR_ID_MEDPLY_ALL_VIDEO"/>
    <MENU id = "MENU_ID_MEDPLY_MAIN_LIST" type = "APP_MAIN"  str = "STR_ID_MEDPLY_APP_TITLE">
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_NOW_PLAYING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_ALL_AUDIO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_ALL_VIDEO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_MY_PLAYLIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_MENU</MENUITEM_ID>
    </MENU>
    

/******************************************** main screen options ***********************************************/
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST"  str="STR_ID_MEDPLY_CUR_PLAYLIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS"  str="STR_GLOBAL_DETAILS"/>
    #if defined(__MMI_MEDIA_PLAYER_VDOREC__)
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_VDOREC" str="STR_ID_MEDPLY_VDOREC"/>
    #endif
    <MENUITEM id="MENU_ID_MEDPLY_OPTION_GO_TO_LIB"  str="STR_ID_MEDPLY_GO_TO_LIB"/>
    <MENU id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_OPTION_GO_TO_LIB</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS</MENUITEM_ID>
        //<MENUITEM_ID>MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_VDOREC</MENUITEM_ID>
    </MENU>


/********************************* playlist menu start ************************************************/
    #if defined(__MMI_MEDIA_PLAYER_STREAM__)
    /* history url */    
    <MENUITEM id="MENU_ID_MEDPLY_BOOKMARK_MENU_INPUT"  str="STR_ID_MEDPLY_PLST_INPUT_URL"/>
    <MENUITEM id="MENU_ID_MEDPLY_BOOKMARK_MENU_HISTORY"  str="STR_ID_MEDPLY_HISTORY"/>
    <MENUITEM id="MENU_ID_MEDPLY_BOOKMARK_PREDEFINEDURL"  str="STR_ID_MEDPLY_PLST_PREDEFINEDURL"/>
    <MENU id="MENU_ID_MEDPLY_BOOKMARK_MENU" type="OPTION" str="STR_ID_MEDPLY_STREAMING_URL">
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_PREDEFINEDURL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_MENU_INPUT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_MENU_HISTORY</MENUITEM_ID>
    </MENU>
        
    <MENUITEM id="MENU_ID_MEDPLY_BOOKMARK_OPTION_PLAY"  str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_BOOKMARK_OPTION_REMOVE"  str="STR_GLOBAL_REMOVE"/>
    <MENUITEM id="MENU_ID_MEDPLY_BOOKMARK_OPTION_CLEAR"  str="STR_ID_MEDPLY_PLST_REMOVE_ALL"/>
    <MENU id="MENU_ID_MEDPLY_BOOKMARK_OPTION_MENU" type="OPTION" str="STR_ID_MEDPLY_BOOKMARK">
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_OPTION_PLAY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_OPTION_REMOVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_BOOKMARK_OPTION_CLEAR</MENUITEM_ID>
    </MENU>
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

    <MENUITEM id="MENU_ID_MEDPLY_HISTORY_OPTION_PLAY"  str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_HISTORY_OPTION_ADD_TO_PLAYLIST"  str="STR_ID_MEDPLY_PLST_ADD_TO"/>
    <MENUITEM id="MENU_ID_MEDPLY_HISTORY_OPTION_ADD_TO_BOOKMARK"  str="STR_ID_MEDPLY_PLST_ADD_TO_BOOKMARK"/>
    <MENUITEM id="MENU_ID_MEDPLY_HISTORY_OPTION_CLEAR_HISTORY"  str="STR_ID_MEDPLY_PLST_REMOVE_ALL"/>
    <MENU id="MENU_ID_MEDPLY_HISTORY_OPTION_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_HISTORY_OPTION_PLAY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_HISTORY_OPTION_ADD_TO_PLAYLIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_HISTORY_OPTION_ADD_TO_BOOKMARK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_HISTORY_OPTION_CLEAR_HISTORY</MENUITEM_ID>
    </MENU>

    /* list */
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_NEW"  str="STR_ID_MEDPLY_PLST_NEW"/>
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_LOAD"  str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_DELETE"  str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_DELETEALL"  str="STR_GLOBAL_DELETE_ALL"/>
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_RENAME"  str="STR_GLOBAL_RENAME"/>
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_STORAGE"  str="STR_GLOBAL_STORAGE"/>
    <MENUITEM id="MENU_ID_MEDPLY_LISTMGR_OPTION_SETTINGS"  str="STR_GLOBAL_SETTINGS"/>
    <MENU id="MENU_ID_MEDPLY_LISTMGR_OPTION_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_LOAD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_NEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_DELETEALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_RENAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_STORAGE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_LISTMGR_OPTION_SETTINGS</MENUITEM_ID>
    </MENU>


    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_PLAY"  str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_DETAILS"  str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_MOVEUP"  str="STR_ID_MEDPLY_PLST_MOVEUP"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN"  str="STR_ID_MEDPLY_PLST_MOVEDOWN"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_ADD"  str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_REFRESH"  str="STR_GLOBAL_REFRESH"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST"  str="STR_ID_MEDPLY_PLST_ADD_TO_PLAYLIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_DELETE"  str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_REMOVE"  str="STR_GLOBAL_REMOVE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_SEND"  str="STR_GLOBAL_SEND"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_USE"  str="STR_GLOBAL_USE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_OPTION_SETTINGS"  str="STR_GLOBAL_SETTINGS"/>
    <MENU id="MENU_ID_MEDPLY_PLST_OPTION_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_PLAY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_REMOVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_USE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_MOVEUP</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_OPTION_SETTINGS</MENUITEM_ID>
    </MENU>


#elif defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
/******************************************** main menu list ***********************************************/
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_NOW_PLAYING" str="STR_ID_MEDPLY_NOW_PLAYING"/>
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_MY_PLAYLIST" str="STR_ID_MEDPLY_MY_PLAYLIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_ALL_MEDIA" str="STR_ID_MEDPLY_ALL_MEDIA"/>
    #if defined(__MMI_MEDIA_PLAYER_STREAM__)
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_MENU_BOOKMARK" str="STR_ID_MEDPLY_BOOKMARK"/>
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
    <MENU id = "MENU_ID_MEDPLY_MAIN_LIST" type = "APP_MAIN"  str = "STR_ID_MEDPLY_APP_TITLE">
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_NOW_PLAYING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_ALL_MEDIA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_MY_PLAYLIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_MENU_BOOKMARK</MENUITEM_ID>
    </MENU>
/******************************************** main screen options ***********************************************/
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST"  str="STR_ID_MEDPLY_CUR_PLAYLIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS"  str="STR_GLOBAL_DETAILS"/>
#if defined(__MMI_MEDIA_PLAYER_VDOREC__)
    <MENUITEM id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_VDOREC" str="STR_ID_MEDPLY_VDOREC"/>
#endif
    <MENU id="MENU_ID_MEDPLY_MAIN_SCREEN_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_VDOREC</MENUITEM_ID>
    </MENU>
/********************************* playlist menu start ************************************************/
    /* db style */
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_PLAY"  str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS"  str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_UPDATE"  str="STR_GLOBAL_UPDATE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_ADD"  str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LIST_OPT_ADD"  str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE"  str="STR_GLOBAL_REMOVE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR"  str="STR_ID_MEDPLY_PLST_CLEAR_LIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST"  str="STR_ID_MEDPLY_PLST_ORGANIZE_LIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO"  str="STR_ID_MEDPLY_PLST_ADD_TO"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND"  str="STR_GLOBAL_SEND"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_USE"  str="STR_GLOBAL_USE"/>
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO"  str="STR_ID_MEDPLY_PLST_INTRO"/>
#endif
    <MENUITEM id="MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_SEARCH"  str="STR_GLOBAL_SEARCH"/>
    <MENU id="MENU_ID_MEDPLY_PLST_LIST_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_PLAY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_UPDATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LIST_OPT_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_USE</MENUITEM_ID>
    #ifdef __MMI_RMGR__
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_MORE_RITS</MENUITEM_ID>
    #endif    
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_SEARCH</MENUITEM_ID>
    </MENU>


    <MENUITEM id="MENU_ID_MEDPLY_PLST_LISTMGR_OPT_NEW"  str="STR_ID_MEDPLY_LISTMGR_OPT_NEW"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LISTMGR_OPT_LOAD"  str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LISTMGR_OPT_DELETE"  str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_LISTMGR_OPT_RENAME"  str="STR_GLOBAL_RENAME"/>
    <MENU id="MENU_ID_MEDPLY_PLST_LISTMGR_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LISTMGR_OPT_LOAD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LISTMGR_OPT_NEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LISTMGR_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_LISTMGR_OPT_RENAME</MENUITEM_ID>
    </MENU>
    
    <MENUITEM id="MENU_ID_MEDPLY_MULTI_SELECT_ADD_MARKED" str="STR_ID_MEDPLY_PLST_ADD_MARKED"/>
    <MENUITEM id="MENU_ID_MEDPLY_MULTI_SELECT_MARK_ALL" str="STR_GLOBAL_MARK_ALL"/>
    <MENUITEM id="MENU_ID_MEDPLY_MULTI_SELECT_UNMARK_ALL" str="STR_GLOBAL_UNMARK_ALL"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_SORT_BY" str="STR_GLOBAL_SORT_BY"/>
    <MENU id="MENU_ID_MEDPLY_MULTI_SELECT_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_MULTI_SELECT_ADD_MARKED</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_MULTI_SELECT_MARK_ALL</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_MULTI_SELECT_UNMARK_ALL</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_SORT_BY</MENUITEM_ID>
	</MENU>
    
    <MENUITEM id="MENU_ID_MEDPLY_PLST_SEARCH_OPT_PREVIEW" str="STR_GLOBAL_PREVIEW"/>
    //<MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS" str="STR_GLOBAL_DETAILS"/>
    //<MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO" str="STR_ID_MEDPLY_PLST_ADD_TO"/>
    //<MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND" str="STR_GLOBAL_SEND"/>
    //<MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_USE" str="STR_FMGR_USE"/>
    //<MENUITEM id="MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO" str="STR_ID_MEDPLY_PLST_INTRO"/>
    <MENU id="MENU_ID_MEDPLY_PLST_SEARCH_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_SEARCH_OPT_PREVIEW</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_USE</MENUITEM_ID>
        #ifdef __MMI_RMGR__
        <MENUITEM_ID>@OID:MENU_ID_FMGR_GEN_OPTION_MORE_RITS</MENUITEM_ID>
        #endif
        <MENUITEM_ID>MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO</MENUITEM_ID>
        
    </MENU>

    <MENUITEM id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_PREVIEW" str="STR_GLOBAL_PREVIEW"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_NEW" str="STR_ID_MEDPLY_PLST_NEW"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_SAVE_RAM" str="STR_ID_MEDPLY_BMK_OPT_SAVE_CONNECTION"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETEALL" str="STR_GLOBAL_DELETE_ALL"/>
    <MENU id="MENU_ID_MEDPLY_PLST_BOOKMARK_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
	    <MENUITEM_ID>MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_PREVIEW</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_NEW</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_EDIT</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_SAVE_RAM</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETEALL</MENUITEM_ID>
	</MENU>


#elif defined (__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)


    /* Main Menu */
    <MENUITEM id="MENU_ID_MEDPLY_FTE_NOW_PLAYING" str="STR_ID_MEDPLY_NOW_PLAYING"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_ALL_AUDIO_LIST" str="STR_ID_MEDPLY_ALL_SONGS"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_ARTIST_LIST" str="STR_ID_MEDPLY_ARTISTS"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_ALBUM_LIST" str="STR_ID_MEDPLY_ALBUMS"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_GENRE_LIST" str="STR_ID_MEDPLY_GENRES"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_PLAYLIST_LIST" str="STR_ID_MEDPLY_PLAYLISTS"/>
#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined (__MMI_MEDIA_PLAYER_VIDEO__)
    <MENUITEM id="MENU_ID_MEDPLY_FTE_ALL_VIDEO_LIST" str="STR_ID_MEDPLY_ALL_VIDEOS"/>
#endif
#if defined(MMI_MEDPLY_FTE_SUPPORT_INPUT_URL)
    <MENUITEM id="MENU_ID_MEDPLY_FTE_INPUT_URL"  str="STR_ID_MEDPLY_PLST_INPUT_URL"/>
#endif
    //<MENUITEM id="MENU_ID_MEDPLY_FTE_STREAM_LIST" str="STR_ID_MEDPLY_STREAMING_LINKS"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_REFRESH_LIB" str="STR_ID_MEDPLY_REFRESH_LIB"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_SETTINGS" str="STR_GLOBAL_SETTINGS" highlight="mmi_medply_settings_highlight"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_RESET_LIB" str="STR_ID_MEDPLY_RESET_LIB"/>
    <MENU id="MENU_ID_MEDPLY_FTE_MAIN_LIST" type="APP_SUB" str="STR_ID_MEDPLY_APP_TITLE">
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_NOW_PLAYING</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_ALL_AUDIO_LIST</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_ARTIST_LIST</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_ALBUM_LIST</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_GENRE_LIST</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLAYLIST_LIST</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_ALL_VIDEO_LIST</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_INPUT_URL</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_REFRESH_LIB</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_SETTINGS</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_MEDPLY_FTE_RESET_LIB</MENUITEM_ID>
    </MENU>

    /* File Options */
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_PLAY" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_SEND" str="STR_GLOBAL_SEND"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_PLST_ADD" str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER" str="STR_ID_MEDPLY_ADDFRM_FLODER"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER" str="STR_ID_MEDPLY_ADDFRM_FLODER"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE" str="STR_GLOBAL_REMOVE"/>
    //<MENUITEM id="MENU_ID_MEPPLY_FTE_FILE_PLST_CLEAR" str="STR_ID_MEDPLY_REMOVE_ALL"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_USE" str="STR_ID_MEDPLY_USE_AS"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST" str="STR_ID_MEDPLY_ADDTO_PLST"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_CLEAR_PLST" str="STR_ID_MEDPLY_CLEAR_PLST"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_MARKSVR" str="STR_ID_MEDPLY_MARKSVR"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ" str="STR_ID_MEDPLY_PLST_ORGANIZE_LIST"/>
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    <MENUITEM id="MENU_ID_MEDPLY_FTE_FILE_SEARCH_PREFIX" str="STR_GLOBAL_SEARCH"/>
#endif
    <MENU id="MENU_ID_MEDPLY_FTE_FILE_LIST_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_PLAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_SEND</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_PLST_ADD</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_USE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_CLEAR_PLST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_MARKSVR</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_DETAILS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_SEARCH_PREFIX</MENUITEM_ID>
    </MENU>
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    <MENU id="MENU_ID_MEDPLY_FTE_FILE_LIST_SEARCH_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_PLAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_SEND</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_USE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_FILE_DETAILS</MENUITEM_ID>
            <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>
    #endif

    /* Type Options */
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_PLAY" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW" str="STR_ID_MEDPLY_IMAGE_FLOW"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST" str="STR_ID_MEDPLY_ADDTO_PLST"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_DELETE" str="STR_GLOBAL_DELETE"/>
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_SEARCH_PREFIX" str="STR_GLOBAL_SEARCH"/>
    #endif    
    <MENUITEM id="MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM" str="STR_ID_MEDPLY_EDIT_ALBUM"/>    
    <MENU id="MENU_ID_MEDPLY_FTE_TYPE_LIST_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_OPEN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_PLAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_SEARCH_PREFIX</MENUITEM_ID>            
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM</MENUITEM_ID>            
    </MENU>
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    <MENU id="MENU_ID_MEDPLY_FTE_TYPE_LIST_SEARCH_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_OPEN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_PLAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM</MENUITEM_ID>
            <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>
    #endif

    /* Play List Options */
    <MENUITEM id="MENU_ID_MEDPLY_FTE_PLST_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_PLST_PLAY" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_PLST_CREATE" str="STR_ID_MEDPLY_PLST_NEW"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_PLST_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_PLST_RENAME" str="STR_GLOBAL_RENAME"/>
    //#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    //<MENUITEM id="MENU_ID_MEDPLY_FTE_PLST_SEARCH_PREFIX" str="STR_GLOBAL_SEARCH"/>
    //#endif
    <MENU id="MENU_ID_MEDPLY_FTE_PLST_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLST_OPEN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLST_PLAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLST_CREATE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLST_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLST_RENAME</MENUITEM_ID>
            //<MENUITEM_ID>MENU_ID_MEDPLY_FTE_PLST_SEARCH_PREFIX</MENUITEM_ID>
    </MENU>

    /* Multiple Add Options */
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL" str="STR_GLOBAL_MARK_ALL"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL" str="STR_GLOBAL_UNMARK_ALL"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_ADD_MARKED" str="STR_ID_MEDPLY_PLST_ADD_MARKED"/>
    <MENU id="MENU_ID_MEDPLY_FTE_MULTIADD_LIST_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_ADD_MARKED</MENUITEM_ID>
    </MENU>

    /* Multiple Select Options */
    //<MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL" str="STR_GLOBAL_MARK_ALL"/>
    //<MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL" str="STR_GLOBAL_UNMARK_ALL"/>
#ifdef __MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_PLAY" str="STR_GLOBAL_PLAY"/>
#endif
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST" str="STR_ID_MEDPLY_ADDTO_PLST"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE" str="STR_GLOBAL_REMOVE"/>
    <MENU id="MENU_ID_MEDPLY_FTE_MULTISEL_LIST_OPTION" type="OPTION" str="STR_ID_MEDPLY_APP_TITLE">
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_PLAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE</MENUITEM_ID>
    </MENU>

    /* Playback Screen Options */
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_CURRENT_LIST" str="STR_ID_MEDPLY_CUR_PLAYLIST"/>
    <MENUITEM id="MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_MAIN_MENU" str="STR_ID_MEDPLY_GOTO_MAINMENU"/>
    <MENU id="MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_CURRENT_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_MAIN_MENU</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS</MENUITEM_ID>
    </MENU>

#endif /*__MMI_MEDIA_PLAYER_PLST_DB_STYLE__*/
    /* playlist menu end */




/********************************* settings menu start ************************************************/
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_PLAYER" str="STR_ID_MEDPLY_SETTINGS_PLAYER"/>
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_AUDIO" str="STR_ID_MEDPLY_SETTINGS_AUDIO"/>
#endif
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
#if defined(__MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__)  || defined(__MMI_MEDIA_PLAYER_VIDEO_SPEED__) || defined(__MMI_VIDEO_3D_ANAGLYPH__) 
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_VIDEO" str="STR_ID_MEDPLY_SETTINGS_VIDEO"/>
#endif    
#endif
#if defined(__MMI_A2DP_SUPPORT__) && !defined(__MMI_A2DP_HIDE_BT_SETTINGS__)
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_BLUETOOTH" str="STR_ID_MEDPLY_SETTINGS_BLUETOOTH"/>
#endif
#if defined(__MMI_VIDEO_SUBTITLE_SUPPORT__)
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_SUBTITLE" str="STR_ID_MEDPLY_SETTINGS_SUBTITLE_LANGUAGE"/>
#endif
#if defined(__MMI_MEDIA_PLAYER_STREAM__) 
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_NETWORK" str="STR_ID_MEDPLY_SETTINGS_NETWORK"/>
#endif
    <MENU id="MENU_ID_MEDPLY_SETTINGS" type="APP_SUB" str="STR_GLOBAL_SETTINGS" highlight="mmi_medply_settings_highlight">
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_PLAYER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_AUDIO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_VIDEO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_BLUETOOTH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_SUBTITLE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_NETWORK</MENUITEM_ID>
    </MENU>


    <MENUITEM id="MENU_ID_MEDPLY_VIEW_SKIN" str="STR_ID_MEDPLY_SKIN_FROM_THEME" />
    <MENUITEM id="MENU_ID_MEDPLY_SELECT_FROM_FILE" str="STR_ID_MEDPLY_SKIN_FROM_FILE" />
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_DONE" str="STR_GLOBAL_DONE" />
    <MENU id="MENU_ID_MEDPLY_SELECT_FILE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_MEDPLY_VIEW_SKIN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_SELECT_FROM_FILE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_DONE</MENUITEM_ID>
    </MENU>

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    <MENUITEM id="MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_SELECT" str="STR_GLOBAL_SELECT"/>
    <MENUITEM id="MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_SAVE" str="STR_GLOBAL_SAVE"/>
    <MENUITEM id="MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_RENAME" str="STR_GLOBAL_RENAME"/>
    <MENUITEM id="MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_RESTORE" str="STR_ID_SETTING_AUDIO_EQUALIZER_REST_FACT_DEFAULT"/>
    <MENU id="MENU_ID_MEDPLY_SOUNDEFFECT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                              <MENUITEM_ID>MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_SAVE</MENUITEM_ID>
                              <MENUITEM_ID>MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_EDIT</MENUITEM_ID>
                              <MENUITEM_ID>MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_RENAME</MENUITEM_ID>
                              <MENUITEM_ID>MENU_ID_MEDPLY_SOUNDEFFECT_OPTION_RESTORE</MENUITEM_ID>
    </MENU>
#endif

#if defined(__MMI_MEDIA_PLAYER_STREAM__)
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_NETWORK_ACTIVE_PROFILE" str="STR_GLOBAL_ACTIVATE"/>
    <MENUITEM id="MENU_ID_MEDPLY_SETTINGS_NETWORK_EDIT_PROFILE" str="STR_GLOBAL_EDIT"/>
    <MENU id="MENU_ID_MEDPLY_SETTINGS_NETWORK_OPTION" type="OPTION" str="STR_ID_MEDPLY_SETTINGS_NETWORK">
            <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_NETWORK_ACTIVE_PROFILE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MEDPLY_SETTINGS_NETWORK_EDIT_PROFILE</MENUITEM_ID>
    </MENU>
#endif
    /* settings menu end */


    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <SCREEN id="GRP_ID_MEDPLY"/>
    <SCREEN id="SCR_ID_MEDPLY_BASE"/>
    <SCREEN id="GRP_ID_MEDPLY_SINGLE"/>  /* single */
    <SCREEN id="SCR_ID_MEDPLY_SINGLE_MAIN"/>  /* single */
    <SCREEN id="SCR_ID_MEDPLY_SINGLE_CONFIRM"/>
    <SCREEN id="GRP_ID_MEDPLY_MAIN_LIST"/> 
    <SCREEN id="SCR_ID_MEDPLY_MAIN_LIST"/> 
    <SCREEN id="GRP_ID_MEDPLY_MAIN_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_MAIN_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_MAIN_SCREEN_OPTION"/> /* dummy */
    <SCREEN id="GRP_ID_MEDPLY_MAIN_SCREEN_OPTION"/>

    /* popup */
    <SCREEN id="GRP_ID_MEDPLY_POPUP"/>

    /* settings */
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_MAIN"/>
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_PLAYER"/>
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_AUDIO"/>
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_VIDEO"/>
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_BLUETOOTH"/>
    <SCREEN id="SCR_ID_MEDPLY_SETTINGS_NETWORK"/>

    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_SKIN_OPTION"/> 
    <SCREEN id="SCR_ID_MEDPLY_SETTINGS_SKIN_VIEW"/>
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_SELECT_FILE"/> 
    
    <SCREEN id="GRP_ID_MEDPLY_PROFILE_EDIT"/>
    <SCREEN id="GRP_ID_MEDPLY_DATA_ACCOUNT"/>
    <SCREEN id="GRP_ID_MEDPLY_NETWORK_OPTION"/>
    <SCREEN id="GRP_ID_MEDPLY_SETTINGS_SOUNDEFFECT_OPTION"/>

     <SCREEN id="SCR_ID_MEDPLY_SETTINGS_SUBTITLE_ISO"/>
    

    /* playlist start */
    /************************************ multiple style ********************************************/
        /*Group list manager*/
    <SCREEN id="GRP_ID_MEDPLY_LIST_MGR"/>
    <SCREEN id="SCR_ID_MEDPLY_LIST_MGR"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_MGR_OPT"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_EDITOR"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_DELETE"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_DELETE_ALL"/>

        /*Group playlist*/
    <SCREEN id="GRP_ID_MEDPLY_LIST_BROWSER"/>
    <SCREEN id="SCR_ID_MEDPLY_LIST_BROWSER"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_BROWSER_CURR"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_BROWSER_OPT"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_ADD"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_ADD_TO"/>
    <SCREEN id="SCR_ID_MEDPLY_LIST_ADD_TO"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_DETAILS"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_SELECT_STORAGE"/>

        /*Group bookmark*/
    <SCREEN id="GRP_ID_MEDPLY_LIST_BOOKMARK"/>
    <SCREEN id="SCR_ID_MEDPLY_LIST_HISTORY_URL"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_HISTORY_URL_OPT"/>
    <SCREEN id="SCR_ID_MEDPLY_LIST_HISTORY_DEF_URL"/>
    <SCREEN id="GRP_ID_MEDPLY_LIST_HISTORY_EDITOR"/>

      /* Group generate */
    <SCREEN id="GRP_ID_MEDPLY_LIST_GEN"/>
   
       /* wait screen. */    
    <SCREEN id="SCR_ID_MEDPLY_LIST_WAIT_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN"/>
       /* confirm screen */
    <SCREEN id="GRP_ID_MEDPLY_LIST_STORAGE_CHANGE"/>
    
    /************************************ database style ********************************************/
    <SCREEN id="SCR_ID_MEDPLY_PLST_INIT"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_ALL_MEDIA"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_ALL_MEDIA_OPT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_PLAYLIST"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_PLAYLIST"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_PLAYLIST_OPT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_BOOKMARK"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_BOOKMARK"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_BOOKMARK_OPT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_LISTMGR"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_LISTMGR"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_LISTMGR_OPT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_MULTI_SELECT"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_MULTI_SELECT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_MULTI_SELECT_OPT"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_GENERATE_LAYER"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_MODULE_REBUILD"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_COMMON_NOTIFY_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_COMMON_NOTIFY_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_BROWSER_OPTION"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_ADDTO"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_ADDTO"/>
    /* details */    
    <SCREEN id="GRP_ID_MEDPLY_PLST_DETAILS_EDIT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_DETAILS_PREVIEW"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_DETAILS_SAVE_CONFIRM"/>
    /* editor */    
    <SCREEN id="SCR_ID_MEDPLY_PLST_EDITOR_OPTION"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_EDITOR"/>
    /* user rated */
    <SCREEN id="GRP_ID_MEDPLY_PLST_SET_RATE"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_SET_RATE"/>
    /* Organize screen */
    <SCREEN id="GRP_ID_MEDPLY_PLST_ORGANIZE"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_ORGANIZE"/>
    /* search screen */
    <SCREEN id="GRP_ID_MEDPLY_PLST_SEARCH"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_SEARCH"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_SEARCH_RESULT"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_SEARCH_RESULT_OPT"/>
    /* wait screen. */ 
    <SCREEN id="GRP_ID_MEDPLY_PLST_WAIT_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_WAIT_SCREEN"/>
    <SCREEN id="GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN"/>

    /************************************ fte_db style ********************************************/
    <SCREEN id="GRP_ID_MEDPLY_FTE"/>
    <SCREEN id="GRP_ID_MEDPLY_FTE_SUB_MENU"/>
    <SCREEN id="GRP_ID_MEDPLY_FTE_ORGANIZE"/>
    //<SCREEN id="GRP_ID_MEDPLY_POPUP"/>    /* common popup screen id for control*/
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ALL_SONGS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ALL_GENRES"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ALL_PLSTS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_SONGS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ARTIST_SONGS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_GENRE_SONGS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_MULTISEL"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_MULTIADD"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_IMAGE_FLOW"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_COVER_PREVIEW"/>
    //<SCREEN id="SCR_ID_MEDPLY_LISTUI_MULTIADD_OPT"/>
    //<SCREEN id="SCR_ID_MEDPLY_LISTUI_MULTISEL_OPT"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_DETAILS"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_DETAILS_EDIT"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_DETAIL_SET_RATE"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_EDITOR"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_EDITOR_OPT"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_ORGANIZE"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_WAITING"/>
    <SCREEN id="SCR_ID_MEDPLY_LISTUI_OPENING"/>
    //<SCREEN id="SCR_ID_MEDPLY_LISTUI_SONG_LIST_OPT"/>
    //<SCREEN id="SCR_ID_MEDPLY_LISTUI_TYPE_LIST_OPT"/>
    //<SCREEN id="SCR_ID_MEDPLY_LISTUI_PLST_LIST_OPT"/>
    /* forward */
    <SCREEN id="SCR_ID_MEDPLY_FWD"/>
    /* playlist end. */


    /************************************ kuro list ********************************************/
    <SCREEN id="GRP_ID_MEDPLY_KURO_STORE"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_ACTIVATE_SCREEN"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_ACTIVATE_ALL_COUNT_SCREEN"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_NEWEST_SONG"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_NEWEST_SONG"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_AIRSONG"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_AIRSONG"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_AIRSONG_HOTSONG"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_AIRSONG_HOTSONG"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_AIRSONG_ARTIST"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_AIRSONG_ARTIST"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_AIRSONG_ALBUM"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_AIRSONG_ALBUM"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_AIRSONG_LIST"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_AIRSONG_LIST"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_DOWNLOAD_MANAGE"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_DOWNLOAD_MANAGE"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_DOANLOAD_MANAGE_OPTION"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_CLUB"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_CLUB"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_KURO_SONG"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_KURO_SONG"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_PRESER_SONG"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_PRESER_SONG"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_KURO_SONG_LIST"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_KURO_SONG_LIST"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_KURO_SONG_LIST_OPTION"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_KURO_SONG_LIST_ADD_TO"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_KURO_SONG_LIST_ADD_TO"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_HELP"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_HELP"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_DUMMY"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_WAITING"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_WAITING"/>
    <SCREEN id="GRP_ID_MEDPLY_KURO_LIST_SCAN_WAITING"/>
    <SCREEN id="SCR_ID_MEDPLY_KURO_LIST_SCAN_WAITING"/>

    <SCREEN id="NO_OF_SCR_MEDPLY"/>

<!------------------------------------------------------CM Resource---------------------------------------------------------->
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__) || defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_medply_plst_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_medply_plst_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_medply_plst_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_medply_plst_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_medply_plst_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_medply_plst_notify_hdlr"/>
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_medply_plst_notify_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_medply_plst_notify_hdlr"/>
#endif
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/

    <RECEIVER id="EVT_ID_SRV_PROF_PROFILE_SWITCHED" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_AFTER_LCD_SLEEP_IN" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_medply_broadcast_event_callback_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_PROF_IS_PLAYING" proc="mmi_medply_broadcast_event_callback_hdlr"/>
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_medply_broadcast_event_callback_hdlr"/>
#endif
#if defined(__MMI_MEDIA_PLAYER_STREAM__)    
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="mmi_medply_settings_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="mmi_medply_settings_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_medply_settings_sim_unavailable_hdlr"/>
#endif
#ifdef __DM_LAWMO_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="mmi_medply_lawmo_lock_callback_hdlr"/>
#endif
<!------------------------------------------------------NVRAM Resource---------------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_MEDPLY_PREFER_LIST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MEDIA_PLAYER_VOLUME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
        <FIELD min="0" max="15"></FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MEDIA_PLAYER_SINGLE_VOLUME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
		<FIELD min="0" max="15"></FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MEDIA_PLAYER_MUTE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
        <FIELD>
            <OPTION hint="true:mute (please set volume as 0 too)"> [0x01]</OPTION>
            <OPTION hint="false:not mute"> [0x00]</OPTION>
        </FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MEDIA_PLAYER_SINGLE_MUTE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_EF_MEDPLY_SETTINGS_ACTIVE_PROFILE_INX </DESCRIPTION>
    </CACHEDATA>
    #if 0
    <CACHEDATA type="byte" id="NVRAM_EF_MEDPLY_SETTINGS_REPEAT_PLAY">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_EF_MEDPLY_SETTINGS_REPEAT_PLAY </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_EF_MEDPLY_SETTINGS_SHUFFLE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_EF_MEDPLY_SETTINGS_SHUFFLE </DESCRIPTION>
    </CACHEDATA>
    #endif
    <CACHEDATA type="short" id="NVRAM_MEDPLY_LAST_PLAYLIST_INDEX">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_MEDPLY_LAST_PLAYLIST_INDEX
     </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_MEDPLY_SNAPSHOT_SEQ_NO">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_MEDPLY_SNAPSHOT_SEQ_NO </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="double" id="NVRAM_MEDPLY_LAST_PLAYLIST_ID">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_MEDPLY_LAST_PLAYLIST_ID </DESCRIPTION>
    </CACHEDATA>

</APP>
#endif

#endif //__COSMOS_MMI_PACKAGE__
