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
 * Filename:
 * ---------
 *	 Res_Game.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Game Resource
 *
 * Author:
 * -------
 *	 Bear Wang (MTK00612)
 *   Vincent Cho (MTK01166)
 *   Yingchun Zhang (MTK80069)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 08 01 2013 junkai.yang
 * [MAUI_03440388] [NativeGame] NativeGame re-design
 * .
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 02 19 2011 yiping.xie
 * [MAUI_02652442] [game] __mmi_motion_app__ roll back
 * .
 *
 * 11 17 2010 yiping.xie
 * [MAUI_02641274] [Game,VdoRec] NVRAM move to resource file
 * .
 *
 * 10 11 2010 yiping.xie
 * [MAUI_02725093] The title should be "Options "
 * .
 *
 * 09 19 2010 yiping.xie
 * [MAUI_02323105] the number's background show abnormal
 * .
 *
 * 08 03 2010 yiping.xie
 * [MAUI_02317815] [GAME] button should not display out border
 * .
 *
 * 08 03 2010 yiping.xie
 * [MAUI_02317811] [GAME] display wrong line
 * .
 *
 * 07 27 2010 yiping.xie
 * [MAUI_02597958] Games_The game display "X".
 * .
 *
 * Jul 11 2010 mtk80069
 * [MAUI_02309900] [FTE-VID]the csk no use
 * 
 *
 * Jul 11 2010 mtk80069
 * [MAUI_02309900] [FTE-VID]the csk no use
 * 
 *
 * Apr 28 2010 mtk80069
 * [MAUI_02186528] [Need Patch] [Build Error] MAUI.W10.17 build error for MT6253_EVB_gprs [MAUI_0240878
 * 
 *
 * Apr 26 2010 mtk80069
 * [MAUI_02184841] [Need Patch] [Build Error] MAUI.W10.17 build error for MT6235_EVB_gprs [MAUI_0240561
 * 
 *
 * Apr 13 2010 mtk80069
 * [MAUI_02178875] 10A modify  slideshow + Funandgame + motion Dice + motion DJ
 * 
 *
 * Apr 13 2010 mtk80069
 * [MAUI_02178875] 10A modify  slideshow + Funandgame + motion Dice + motion DJ
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#include "GameResDef.h"
#include "GameProts.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_GAME__)
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GAMES"
     package_name="native.mtk.fun"
     name="MAIN_MENU_FUNANDGAMES_TEXT"    
     img="MAIN_MENU_FUNANDGAMES_ICON"
     launch="mmi_fng_entry_screen">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="mmi_rp_app_mainmenu_def.h,GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
#define GX_OLD_IMG_TYPE ".bmp"
#define GX_IMG_TYPE ".png"
#define GX_ANIMATION_IMG_TYPE ".gif"
#define GX_JPEG_TYPE ".jpg"
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __MMI_GAME_DANCE__
   <IMAGE id="IMG_ID_GX_DANCE_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_icon"GX_OLD_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_BACKGROUND">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_display"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIVEDISPLAY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_live_display"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHTDISPLAY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_display"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_SCOREDISPLAY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_score_display"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_STANDBY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_standby"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_RIGHT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_right_up"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_RIGHT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_right_down"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_LEFT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_left_up"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_LEFT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_left_down"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_STANDBY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_standby"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_RIGHT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_right_up"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_RIGHT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_right_down"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_LEFT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_left_up"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_LEFT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_left_down"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_LIVE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_live"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
   <IMAGE id="IMG_ID_GX_DANCE_GAME_OVER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gameover\\\\gx_dance_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
#else
   <IMAGE id="IMG_ID_GX_DANCE_GAMEOVER_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\multi_lan\\\\gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_GAMEOVER_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\multi_lan\\\\gameover_C"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
   <IMAGE id="IMG_ID_GX_DANCE_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gameover\\\\gx_dance_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_PIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gameover\\\\gx_dance_pic"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_0"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_1"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_2"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_3"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_4"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_5"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_6"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_7"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_8"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_9"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHT_TRUE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_true"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHT_FALSE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_false"GX_ANIMATION_IMG_TYPE</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHT_EMPTY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_empty"GX_ANIMATION_IMG_TYPE</IMAGE>
   <STRING id="STR_ID_GX_DANCE_GAME_NAME"/>
#if defined(__MMI_TOUCH_SCREEN__)
   <STRING id="STR_ID_GX_DANCE_HELP_DESCRIPTION_TP"/>
#else
   <STRING id="STR_ID_GX_DANCE_HELP_DESCRIPTION"/>
#endif /*__MMI_TOUCH_SCREEN__*/

    /* Dance NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_DANCE_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_DANCE__


#ifdef __MMI_GAME_DOLL__
    <IMAGE id="IMG_GX_DOLL_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\doll_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_SEAL_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_SEAL_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_SEAL_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_SEAL_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_ARM">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\arm"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_ARM_BASE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\arm_base"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CATCHED">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\catched_doll"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CLAW_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CLAW_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CLAW_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CLAW_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CAN_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CAN_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CAN_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_CAN_BOX">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_coin_box"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_NUM_10">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num10"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_DOLL_SMALLDOLL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\dollsmall"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_DOLL_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
#else
       <IMAGE id="IMG_GX_DOLL_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\multi_lan\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
       <IMAGE id="IMG_GX_DOLL_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_DOLL_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
	<STRING id="STR_GX_DOLL_GAME_NAME"/>
	<STRING id="STR_GX_DOLL_HELP_DESCRIPTION"/>

    /* Doll NVRAM */
    <CACHEDATA type="short" id="NVRAM_GAME_DOLL_GRADE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_DOLL__



#ifdef __MMI_GAME_F1RACE__
	<STRING id="STR_GX_F1RACE_GAME_NAME"/>
	<STRING id="STR_GX_F1RACE_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_GX_F1RACE_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\Race"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_PLAYER_CAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_FLY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_FLY_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY_DOWN"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_FLY_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY_UP"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_CRASH">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_CRASH"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_HEAD_LIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_HEAD_LIGHT"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_LOGO">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_LOGO"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_F1RACE_STATUS_SCORE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_SCORE"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_LEVEL"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_F1RACE_STATUS_BOX">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_BOX"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_F1RACE_STATUS_FLY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_FLY"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_F1RACE_NUMBER_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_NUMBER_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_9"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_F1RACE_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_F1RACE_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\pic"GX_OLD_IMG_TYPE</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_SCORE"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_LEVEL"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_FLY_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_FLY"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_SCORE_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_LEVEL_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_FLY_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_FLY_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* F1RACE NVRAM */
    <CACHEDATA type="short" id="NVRAM_F1RACE_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*__MMI_GAME_F1RACE__*/



#ifdef __MMI_GAME_SMASH__
	<STRING id="STR_GX_SMASH_GAME_NAME"/>
	<STRING id="STR_GX_SMASH_TIME_SEC"/>
	<STRING id="STR_GX_SMASH_NORMAL"/>
	<STRING id="STR_GX_SMASH_SPEEDY"/>
	<STRING id="STR_GX_SMASH_ACCURACY"/>
	<STRING id="STR_GX_SMASH_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_GX_SMASH_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\smash"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BG_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_MOUSE_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_MOUSE_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_MOUSE_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_MOUSE_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_MOUSE_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_MOUSE_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_COW_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_COW_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_COW_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_COW_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_COW_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_COW_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BONE_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BONE_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BONE_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BONE_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BONE_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_BONE_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_PIG_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_PIG_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_PIG_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_PIG_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_PIG_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_PIG_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_HAND_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\hand\\\\hand01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_HAND_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\hand\\\\hand03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\pic"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   
    <IMAGE id="IMG_GX_SMASH_HITTHIS">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\hitthis"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_SMASH_SCORE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_HITTHIS_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\hitthis"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_SCORE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\bg_1_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_HITTHIS_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\hitthis_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SMASH_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Smash NVRAM */    
    <CACHEDATA type="byte" id="SMASH_CURRENT_LEVEL">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMASH_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMASH_SPEEDY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMASH_ACCURACY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_SMASH__

#ifdef __MMI_GAME_RICHES__
	<STRING id="STR_GX_RICHES_GAME_NAME"/>
	<STRING id="STR_GX_RICHES_EASY"/>
	<STRING id="STR_GX_RICHES_NORMAL"/>
	<STRING id="STR_GX_RICHES_HARD"/>
	<STRING id="STR_GX_RICHES_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_GX_RICHES_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\riches"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BASKET">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\basket"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_APPLE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\apple"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_BOMB">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bomb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_GIFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\gift"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_GOLDNOTE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\goldnote"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_SPIDER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\spider"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_ANGLE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\angel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_BATTERY20">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bluebattery"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_DENONATOR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\detonator"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_EVIL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\evil"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_MONEY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\money"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_BATTERYFULL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\redbattery"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_THEIF">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\thief"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_ENERGYBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\energybg"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_ENERGYBAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\enerygybar"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_BAT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bat"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY20">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY40">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY60">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY80">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY100">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_OBJECT_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\level\\\\basket"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_RICHES_BACKGROUND">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_TIMER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\timer"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\level"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_RICHES_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\pic"GX_OLD_IMG_TYPE</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_TIMER_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\timer"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\level"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\bg_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_TIMER_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\timer_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\level_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_RICHES_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Riches NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GAME_RICHES_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_RICHES_OPTION_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RICHES_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RICHES_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RICHES_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_RICHES__


#ifdef __MMI_GAME_SNAKE__
    <IMAGE id="IMG_GX_SNAKE_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\snake"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_UP"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_DOWN"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_RIGHT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_LEFT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_UP_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_UP_DOWN"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_RIGHT_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_RIGHT_LEFT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_UP_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_UP_RIGHT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_UP_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_UP_LEFT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_DOWN_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_DOWN_RIGHT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_DOWN_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_DOWN_LEFT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_UP"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_DOWN"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_RIGHT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_LEFT"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_EGG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_EGG"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_EGG_NEXT_STAGE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_EGG_NEXT_STAGE"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_NUMBER_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_WALL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_WALL"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_SNAKE_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
        <IMAGE id="IMG_GX_SNAKE_STAGE_TXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_STAGE_TXT"GX_ANIMATION_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_SNAKE_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\multi_lan\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_STAGE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_STAGE_TXT"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_STAGE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\multi_lan\\\\STAGE_C"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_SNAKE_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\gameover\\\\pic"GX_OLD_IMG_TYPE</IMAGE>
	<STRING id="STR_GX_SNAKE_GAME_NAME"/>
	<STRING id="STR_GX_SNAKE_EASY"/>
	<STRING id="STR_GX_SNAKE_NORMAL"/>
	<STRING id="STR_GX_SNAKE_HARD"/>
	<STRING id="STR_GX_SNAKE_HELP_DESCRIPTION"/>

    /* Snake NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GAME_SNAKE_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL1_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL2_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL3_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL4_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_SNAKE__

#ifdef __MMI_GAME_HANOI__
	<STRING id="STR_GX_TOH_GAME_NAME"/>
	<STRING id="STR_GX_TOH_TITLE"/>
	<STRING id="STR_GX_TOH_LEVEL"/>
	<STRING id="STR_GX_TOH_SEC"/>
	<STRING id="STR_GX_TOH_LEVEL1"/>
	<STRING id="STR_GX_TOH_LEVEL2"/>
	<STRING id="STR_GX_TOH_LEVEL3"/>
	<STRING id="STR_GX_TOH_LEVEL4"/>
	<STRING id="STR_GX_TOH_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_GX_TOH_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\hanoi"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\1brick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK1_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\1brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\2brick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK2_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\2brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\3brick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK3_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\3brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\4brick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK4_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\4brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\5brick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK5_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\5brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\6brick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BRICK6_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\6brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\level\\\\2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_LEVEL_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\level\\\\1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_BG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\map\\\\bgpicture"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_TOWER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\tower bar\\\\tower bar"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_TOWER_IN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\Indicator\\\\finger"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_TOH_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_TOH_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\multi_lan\\\\level_E"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\multi_lan\\\\level_C"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_TOH_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\pic"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_TOH_TITLEBAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\titlebar\\\\titlebar"GX_OLD_IMG_TYPE</IMAGE>

    /* Hanoi NVRAM */
    <CACHEDATA type="byte" id="TOH_CURRENT_LEVEL" restore_flag="TRUE">
            <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
            <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL1_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL2_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL3_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL4_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_HANOI__


#ifdef __MMI_GAME_COLORBALL__
	<STRING id="STR_GX_COLORBALLS_GAME_NAME"/>
	<STRING id="STR_GX_COLORBALLS_EASY"/>
	<STRING id="STR_GX_COLORBALLS_NORMAL"/>
	<STRING id="STR_GX_COLORBALLS_HARD"/>
	<STRING id="STR_GX_COLORBALLS_DESCRIPTION"/>
    <IMAGE id="IMG_GX_COLORBALLS_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\colorball"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_BIG_BLUE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\blue"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_BIG_GREEN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\green"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_BIG_LIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\light"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_BIG_PINK">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\pink"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_SMALL_BLUE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\blue"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_SMALL_GREEN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\green"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_SMALL_LIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\light"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_SMALL_PINK">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\pink"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_SCORE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_LAUNCH">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\indicator"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_ENERGYBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\energymap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GRADEBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_LEVELBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\levelmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_ENERGYBAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\energy\\\\bar"GX_OLD_IMG_TYPE</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_COLORBALLS_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\gameover\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_BG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\bg"GX_ANIMATION_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_COLORBALLS_BG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\level_E"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GRADE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\grade_E"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_ENERGY_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\power_E"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\level_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GRADE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\grade_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_ENERGY_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\power_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\gameover_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_COLORBALLS_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\gameover\\\\gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\gameover\\\\pic"GX_OLD_IMG_TYPE</IMAGE>

    /* ColorBalls NVRAM */
    <CACHEDATA type="byte" id="NVRAM_COLORBALLS_OPTION_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_COLORBALLS_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_COLORBALLS_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_COLORBALLS_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_COLORBALL__


#ifdef __MMI_GAME_MAJUNG__
#if defined(__MMI_MAINLCD_176X220__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_176x220_majung\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_240x320_majung\\\\"
#elif defined(__MMI_MAINLCD_320X240__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_320x240_majung\\\\"
#elif defined(__MMI_MAINLCD_240X400__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_240x400_majung\\\\"
#elif defined(__MMI_MAINLCD_320X480__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_320x480_majung\\\\"
#endif
	<STRING id="STR_GX_MAJUNG_GAME_NAME"/>
	<STRING id="STR_GX_MAJUNG_LEVEL_EASY"/>
	<STRING id="STR_GX_MAJUNG_LEVEL_NORMAL"/>
	<STRING id="STR_GX_MAJUNG_LEVEL_HARD"/>
	<STRING id="STR_GX_MAJUNG_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_GX_MAJUNG_GAME_ICON">MAJUNG_IMG_PATH"majung_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_1W">MAJUNG_IMG_PATH"brick_1w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_2W">MAJUNG_IMG_PATH"brick_2w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_3W">MAJUNG_IMG_PATH"brick_3w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_4W">MAJUNG_IMG_PATH"brick_4w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_5W">MAJUNG_IMG_PATH"brick_5w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_6W">MAJUNG_IMG_PATH"brick_6w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_7W">MAJUNG_IMG_PATH"brick_7w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_8W">MAJUNG_IMG_PATH"brick_8w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_9W">MAJUNG_IMG_PATH"brick_9w"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_2S">MAJUNG_IMG_PATH"brick_2s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_3S">MAJUNG_IMG_PATH"brick_3s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_4S">MAJUNG_IMG_PATH"brick_4s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_5S">MAJUNG_IMG_PATH"brick_5s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_6S">MAJUNG_IMG_PATH"brick_6s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_7S">MAJUNG_IMG_PATH"brick_7s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_8S">MAJUNG_IMG_PATH"brick_8s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_9S">MAJUNG_IMG_PATH"brick_9s"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_1T">MAJUNG_IMG_PATH"brick_1t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_2T">MAJUNG_IMG_PATH"brick_2t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_3T">MAJUNG_IMG_PATH"brick_3t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_4T">MAJUNG_IMG_PATH"brick_4t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_5T">MAJUNG_IMG_PATH"brick_5t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_6T">MAJUNG_IMG_PATH"brick_6t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_7T">MAJUNG_IMG_PATH"brick_7t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_8T">MAJUNG_IMG_PATH"brick_8t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_9T">MAJUNG_IMG_PATH"brick_9t"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_A">MAJUNG_IMG_PATH"brick_a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_B">MAJUNG_IMG_PATH"brick_b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_C">MAJUNG_IMG_PATH"brick_c"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_D">MAJUNG_IMG_PATH"brick_d"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_F">MAJUNG_IMG_PATH"brick_f"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_G">MAJUNG_IMG_PATH"brick_g"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_H">MAJUNG_IMG_PATH"brick_h"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_1W_SEL">MAJUNG_IMG_PATH"brick_1w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_2W_SEL">MAJUNG_IMG_PATH"brick_2w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_3W_SEL">MAJUNG_IMG_PATH"brick_3w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_4W_SEL">MAJUNG_IMG_PATH"brick_4w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_5W_SEL">MAJUNG_IMG_PATH"brick_5w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_6W_SEL">MAJUNG_IMG_PATH"brick_6w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_7W_SEL">MAJUNG_IMG_PATH"brick_7w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_8W_SEL">MAJUNG_IMG_PATH"brick_8w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_9W_SEL">MAJUNG_IMG_PATH"brick_9w_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_2S_SEL">MAJUNG_IMG_PATH"brick_2s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_3S_SEL">MAJUNG_IMG_PATH"brick_3s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_4S_SEL">MAJUNG_IMG_PATH"brick_4s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_5S_SEL">MAJUNG_IMG_PATH"brick_5s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_6S_SEL">MAJUNG_IMG_PATH"brick_6s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_7S_SEL">MAJUNG_IMG_PATH"brick_7s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_8S_SEL">MAJUNG_IMG_PATH"brick_8s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_9S_SEL">MAJUNG_IMG_PATH"brick_9s_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_1T_SEL">MAJUNG_IMG_PATH"brick_1t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_2T_SEL">MAJUNG_IMG_PATH"brick_2t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_3T_SEL">MAJUNG_IMG_PATH"brick_3t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_4T_SEL">MAJUNG_IMG_PATH"brick_4t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_5T_SEL">MAJUNG_IMG_PATH"brick_5t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_6T_SEL">MAJUNG_IMG_PATH"brick_6t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_7T_SEL">MAJUNG_IMG_PATH"brick_7t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_8T_SEL">MAJUNG_IMG_PATH"brick_8t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_9T_SEL">MAJUNG_IMG_PATH"brick_9t_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_A_SEL">MAJUNG_IMG_PATH"brick_a_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_B_SEL">MAJUNG_IMG_PATH"brick_b_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_C_SEL">MAJUNG_IMG_PATH"brick_c_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_D_SEL">MAJUNG_IMG_PATH"brick_d_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_F_SEL">MAJUNG_IMG_PATH"brick_f_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_G_SEL">MAJUNG_IMG_PATH"brick_g_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BRICK_H_SEL">MAJUNG_IMG_PATH"brick_h_sel"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_CONNECT_HOR">MAJUNG_IMG_PATH"connect_hor"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_CONNECT_VER">MAJUNG_IMG_PATH"connect_ver"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_CONNECT_LU">MAJUNG_IMG_PATH"connect_lu"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_CONNECT_RU">MAJUNG_IMG_PATH"connect_ru"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_CONNECT_LD">MAJUNG_IMG_PATH"connect_ld"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_CONNECT_RD">MAJUNG_IMG_PATH"connect_rd"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_THICK">MAJUNG_IMG_PATH"thick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_1">MAJUNG_IMG_PATH"bar_fill_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_2">MAJUNG_IMG_PATH"bar_fill_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_3">MAJUNG_IMG_PATH"bar_fill_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_4">MAJUNG_IMG_PATH"bar_fill_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_5">MAJUNG_IMG_PATH"bar_fill_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_6">MAJUNG_IMG_PATH"bar_fill_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_7">MAJUNG_IMG_PATH"bar_fill_07"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_8">MAJUNG_IMG_PATH"bar_fill_08"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_9">MAJUNG_IMG_PATH"bar_fill_09"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_10">MAJUNG_IMG_PATH"bar_fill_10"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_11">MAJUNG_IMG_PATH"bar_fill_11"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_12">MAJUNG_IMG_PATH"bar_fill_12"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_13">MAJUNG_IMG_PATH"bar_fill_13"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_14">MAJUNG_IMG_PATH"bar_fill_14"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_15">MAJUNG_IMG_PATH"bar_fill_15"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_16">MAJUNG_IMG_PATH"bar_fill_16"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_17">MAJUNG_IMG_PATH"bar_fill_17"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_18">MAJUNG_IMG_PATH"bar_fill_18"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_19">MAJUNG_IMG_PATH"bar_fill_19"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_FILL_20">MAJUNG_IMG_PATH"bar_fill_20"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_1">MAJUNG_IMG_PATH"bar_empty_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_2">MAJUNG_IMG_PATH"bar_empty_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_3">MAJUNG_IMG_PATH"bar_empty_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_4">MAJUNG_IMG_PATH"bar_empty_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_5">MAJUNG_IMG_PATH"bar_empty_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_6">MAJUNG_IMG_PATH"bar_empty_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_7">MAJUNG_IMG_PATH"bar_empty_07"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_8">MAJUNG_IMG_PATH"bar_empty_08"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_9">MAJUNG_IMG_PATH"bar_empty_09"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_10">MAJUNG_IMG_PATH"bar_empty_10"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_11">MAJUNG_IMG_PATH"bar_empty_11"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_12">MAJUNG_IMG_PATH"bar_empty_12"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_13">MAJUNG_IMG_PATH"bar_empty_13"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_14">MAJUNG_IMG_PATH"bar_empty_14"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_15">MAJUNG_IMG_PATH"bar_empty_15"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_16">MAJUNG_IMG_PATH"bar_empty_16"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_17">MAJUNG_IMG_PATH"bar_empty_17"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_18">MAJUNG_IMG_PATH"bar_empty_18"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_19">MAJUNG_IMG_PATH"bar_empty_19"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_20">MAJUNG_IMG_PATH"bar_empty_20"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_MAJUNG_GAMEOVER">MAJUNG_IMG_PATH"gameover"GX_OLD_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_MAJUNG_GAMEOVER_LANGUAGE0">MAJUNG_IMG_PATH"gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_GAMEOVER_LANGUAGE1">MAJUNG_IMG_PATH"multi_lan\\\\gameover_c"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_MAJUNG_GRADESMAP">MAJUNG_IMG_PATH"gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_COUNT">MAJUNG_IMG_PATH"count"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_0">MAJUNG_IMG_PATH"MAJUNG_NUMBER_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_1">MAJUNG_IMG_PATH"MAJUNG_NUMBER_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_2">MAJUNG_IMG_PATH"MAJUNG_NUMBER_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_3">MAJUNG_IMG_PATH"MAJUNG_NUMBER_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_4">MAJUNG_IMG_PATH"MAJUNG_NUMBER_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_5">MAJUNG_IMG_PATH"MAJUNG_NUMBER_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_6">MAJUNG_IMG_PATH"MAJUNG_NUMBER_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_7">MAJUNG_IMG_PATH"MAJUNG_NUMBER_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_8">MAJUNG_IMG_PATH"MAJUNG_NUMBER_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_9">MAJUNG_IMG_PATH"MAJUNG_NUMBER_9"GX_ANIMATION_IMG_TYPE</IMAGE>
	
    <IMAGE id="IMG_GX_MAJUNG_BOX">MAJUNG_IMG_PATH"MAJUNG_box"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_EXIT_UP">MAJUNG_IMG_PATH"MAJUNG_exit_up"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_EXIT_DOWN">MAJUNG_IMG_PATH"MAJUNG_exit_down"GX_OLD_IMG_TYPE</IMAGE>

    /* Majung NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_MAJUNG_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_MAJUNG_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_MAJUNG_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_MAJUNG_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_MAJUNG__


#ifdef __MMI_GAME_COPTER__
#if defined(__MMI_MAINLCD_128X128__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x128_copter\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x160_copter\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_176x220_copter\\\\"
#endif

	<STRING id="STR_ID_GX_COPTER_GAME_NAME"/>
	#if defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_TP"/>
	#else
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION"/>
	#endif
#endif  //__MMI_GAME_COPTER__


#ifdef __MMI_GAME_SUBMARINE__
#if defined(__MMI_MAINLCD_128X128__)
    #define COPTER_IMG_PATH    CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x128_submarine\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
    #define COPTER_IMG_PATH    CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x160_submarine\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
    #define COPTER_IMG_PATH    CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_176x220_submarine\\\\"
#endif

	<STRING id="STR_ID_GX_COPTER_GAME_NAME_SUBMARINE"/>
	#if defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_SUBMARINE_TP"/>
	#else
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_SUBMARINE"/>
	#endif
#endif  //__MMI_GAME_SUBMARINE__


#ifdef __MMI_GAME_JET__
#if defined(__MMI_MAINLCD_128X128__)
    #define COPTER_IMG_PATH    CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x128_jet\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
    #define COPTER_IMG_PATH    CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x160_jet\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
    #define COPTER_IMG_PATH    CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_176x220_jet\\\\"
#endif

	<STRING id="STR_ID_GX_COPTER_GAME_NAME_JET"/>
	#if defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_JET_TP"/>
	#else
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_JET"/>
	#endif
#endif  //__MMI_GAME_JET__


#if defined(__MMI_GAME_COPTER__) || defined(__MMI_GAME_SUBMARINE__) || defined(__MMI_GAME_JET__)
    <IMAGE id="IMG_ID_GX_COPTER_GAME_ICON">COPTER_IMG_PATH"gx_copter_copter_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_OBSTACLE">COPTER_IMG_PATH"gx_copter_obstacle"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_0">COPTER_IMG_PATH"gx_copter_number_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_1">COPTER_IMG_PATH"gx_copter_number_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_2">COPTER_IMG_PATH"gx_copter_number_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_3">COPTER_IMG_PATH"gx_copter_number_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_4">COPTER_IMG_PATH"gx_copter_number_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_5">COPTER_IMG_PATH"gx_copter_number_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_6">COPTER_IMG_PATH"gx_copter_number_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_7">COPTER_IMG_PATH"gx_copter_number_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_8">COPTER_IMG_PATH"gx_copter_number_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_NUMBER_9">COPTER_IMG_PATH"gx_copter_number_9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_BOX">COPTER_IMG_PATH"gx_copter_box"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_COPTER_SCORE">COPTER_IMG_PATH"gx_copter_number_score"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_COPTER_TITLE">COPTER_IMG_PATH"gx_copter_title"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_BACKGROUND">COPTER_IMG_PATH"gx_copter_bg"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_0">COPTER_IMG_PATH"gx_copter_frame_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_1">COPTER_IMG_PATH"gx_copter_frame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_2">COPTER_IMG_PATH"gx_copter_frame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_CRASHED_0">COPTER_IMG_PATH"gx_copter_crashed_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_CRASHED_1">COPTER_IMG_PATH"gx_copter_crashed_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_CRASHED_2">COPTER_IMG_PATH"gx_copter_crashed_2"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_COPTER_GOTEXT">COPTER_IMG_PATH"gameover\\\\gx_copter_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_COPTER_GRADESMAP">COPTER_IMG_PATH"gameover\\\\gx_copter_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_GOPIC">COPTER_IMG_PATH"gameover\\\\gx_copter_pic"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_COPTER_GOTEXT_LANGUAGE0">COPTER_IMG_PATH"multi_lan\\\\gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_COPTER_GOTEXT_LANGUAGE1">COPTER_IMG_PATH"multi_lan\\\\gameover_c"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Copter NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_COPTER_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //defined(__MMI_GAME_COPTER__) || defined(__MMI_GAME_SUBMARINE__) || defined(__MMI_GAME_JET__)


#ifdef __MMI_GAME_PUZZLE__
#if defined(__MMI_MAINLCD_128X128__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_128x128_puzzle\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_128x160_puzzle\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_176x220_puzzle\\\\"
#elif  defined(__MMI_MAINLCD_240X320__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_240x320_puzzle\\\\"
#elif  defined(__MMI_MAINLCD_320X240__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_320x240_puzzle\\\\"
#elif  defined(__MMI_MAINLCD_240X400__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_240x400_puzzle\\\\"
#elif  defined(__MMI_MAINLCD_320X480__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_320x480_puzzle\\\\"
#endif
	<STRING id="STR_ID_GX_PUZZLE_GAME_NAME"/>
#if defined(__MMI_TOUCH_SCREEN__)
    <STRING id="STR_ID_GX_PUZZLE_HELP_DESCRIPTION_TP"/>
#elif defined(__MMI_MAINLCD_128X128__)
    <STRING id="STR_ID_GX_PUZZLE_HELP_DESCRIPTION_128"/>
#else
    <STRING id="STR_ID_GX_PUZZLE_HELP_DESCRIPTION"/>
#endif
	<STRING id="STR_ID_GX_PUZZLE_LEVEL_EASY"/>
	<STRING id="STR_ID_GX_PUZZLE_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_PUZZLE_LEVEL_HARD"/>
    <IMAGE id="IMG_ID_GX_PUZZLE_GAME_ICON">PUZZLE_IMG_PATH"gx_puzzle_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_0">PUZZLE_IMG_PATH"gx_puzzle_number_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_1">PUZZLE_IMG_PATH"gx_puzzle_number_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_2">PUZZLE_IMG_PATH"gx_puzzle_number_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_3">PUZZLE_IMG_PATH"gx_puzzle_number_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_4">PUZZLE_IMG_PATH"gx_puzzle_number_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_5">PUZZLE_IMG_PATH"gx_puzzle_number_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_6">PUZZLE_IMG_PATH"gx_puzzle_number_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_7">PUZZLE_IMG_PATH"gx_puzzle_number_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_8">PUZZLE_IMG_PATH"gx_puzzle_number_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_9">PUZZLE_IMG_PATH"gx_puzzle_number_9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_BOX">PUZZLE_IMG_PATH"gx_puzzle_box"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_PUZZLE_STEP">PUZZLE_IMG_PATH"gx_puzzle_step"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_TIME">PUZZLE_IMG_PATH"gx_puzzle_time"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_PUZZLE_LEFT_BAR">PUZZLE_IMG_PATH"gx_puzzle_left_bar"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_RIGHT_BAR">PUZZLE_IMG_PATH"gx_puzzle_right_bar"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_TOP_BAR">PUZZLE_IMG_PATH"gx_puzzle_top_bar"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_BOTTOM_BAR">PUZZLE_IMG_PATH"gx_puzzle_bottom_bar"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_SPACE">PUZZLE_IMG_PATH"gx_puzzle_3_space"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_SPACE">PUZZLE_IMG_PATH"gx_puzzle_4_space"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_SPACE">PUZZLE_IMG_PATH"gx_puzzle_5_space"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_SMALL_3">PUZZLE_IMG_PATH"gx_puzzle_small_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_SMALL_4">PUZZLE_IMG_PATH"gx_puzzle_small_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_SMALL_5">PUZZLE_IMG_PATH"gx_puzzle_small_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_1">PUZZLE_IMG_PATH"gx_puzzle_3_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_2">PUZZLE_IMG_PATH"gx_puzzle_3_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_3">PUZZLE_IMG_PATH"gx_puzzle_3_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_4">PUZZLE_IMG_PATH"gx_puzzle_3_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_5">PUZZLE_IMG_PATH"gx_puzzle_3_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_6">PUZZLE_IMG_PATH"gx_puzzle_3_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_7">PUZZLE_IMG_PATH"gx_puzzle_3_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_3_8">PUZZLE_IMG_PATH"gx_puzzle_3_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_1">PUZZLE_IMG_PATH"gx_puzzle_4_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_2">PUZZLE_IMG_PATH"gx_puzzle_4_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_3">PUZZLE_IMG_PATH"gx_puzzle_4_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_4">PUZZLE_IMG_PATH"gx_puzzle_4_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_5">PUZZLE_IMG_PATH"gx_puzzle_4_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_6">PUZZLE_IMG_PATH"gx_puzzle_4_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_7">PUZZLE_IMG_PATH"gx_puzzle_4_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_8">PUZZLE_IMG_PATH"gx_puzzle_4_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_9">PUZZLE_IMG_PATH"gx_puzzle_4_9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_10">PUZZLE_IMG_PATH"gx_puzzle_4_10"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_11">PUZZLE_IMG_PATH"gx_puzzle_4_11"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_12">PUZZLE_IMG_PATH"gx_puzzle_4_12"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_13">PUZZLE_IMG_PATH"gx_puzzle_4_13"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_14">PUZZLE_IMG_PATH"gx_puzzle_4_14"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_4_15">PUZZLE_IMG_PATH"gx_puzzle_4_15"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_1">PUZZLE_IMG_PATH"gx_puzzle_5_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_2">PUZZLE_IMG_PATH"gx_puzzle_5_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_3">PUZZLE_IMG_PATH"gx_puzzle_5_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_4">PUZZLE_IMG_PATH"gx_puzzle_5_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_5">PUZZLE_IMG_PATH"gx_puzzle_5_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_6">PUZZLE_IMG_PATH"gx_puzzle_5_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_7">PUZZLE_IMG_PATH"gx_puzzle_5_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_8">PUZZLE_IMG_PATH"gx_puzzle_5_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_9">PUZZLE_IMG_PATH"gx_puzzle_5_9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_10">PUZZLE_IMG_PATH"gx_puzzle_5_10"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_11">PUZZLE_IMG_PATH"gx_puzzle_5_11"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_12">PUZZLE_IMG_PATH"gx_puzzle_5_12"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_13">PUZZLE_IMG_PATH"gx_puzzle_5_13"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_14">PUZZLE_IMG_PATH"gx_puzzle_5_14"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_15">PUZZLE_IMG_PATH"gx_puzzle_5_15"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_16">PUZZLE_IMG_PATH"gx_puzzle_5_16"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_17">PUZZLE_IMG_PATH"gx_puzzle_5_17"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_18">PUZZLE_IMG_PATH"gx_puzzle_5_18"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_19">PUZZLE_IMG_PATH"gx_puzzle_5_19"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_20">PUZZLE_IMG_PATH"gx_puzzle_5_20"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_21">PUZZLE_IMG_PATH"gx_puzzle_5_21"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_22">PUZZLE_IMG_PATH"gx_puzzle_5_22"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_23">PUZZLE_IMG_PATH"gx_puzzle_5_23"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_5_24">PUZZLE_IMG_PATH"gx_puzzle_5_24"GX_ANIMATION_IMG_TYPE</IMAGE>
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    <IMAGE id="IMG_ID_GX_PUZZLE_BG">PUZZLE_IMG_PATH"gx_puzzle_bg"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_PUZZLE_GOTEXT">PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_complete"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_PUZZLE_GRADESMAP">PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_GOPIC">PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_pic"GX_ANIMATION_IMG_TYPE</IMAGE>
#if defined(__MMI_TOUCH_SCREEN__)
#ifdef __MMI_MAINLCD_320X240__
    <IMAGE id="IMG_ID_GX_PUZZLE_UP">PUZZLE_IMG_PATH"gx_puzzle_up"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_DOWN">PUZZLE_IMG_PATH"gx_puzzle_down"GX_OLD_IMG_TYPE</IMAGE>
#else defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || \
     defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    <IMAGE id="IMG_ID_GX_PUZZLE_UP">PUZZLE_IMG_PATH"gx_puzzle_button_off"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_DOWN">PUZZLE_IMG_PATH"gx_puzzle_button_down"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif
#endif
	
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE0">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_complete"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_TIME_LANGUAGE0">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_time"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_STEP_LANGUAGE0">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_step"GX_ANIMATION_IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE1">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_complete_c"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_TIME_LANGUAGE1">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_time_c"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_STEP_LANGUAGE1">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_step_c"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Puzzle NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_PUZZLE_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_GX_PUZZLE_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_PUZZLE_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_PUZZLE_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_PUZZLE__


#ifdef __MMI_GAME_PANDA__
#if defined(__MMI_MAINLCD_128X128__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x128_panda\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x160_panda\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_176x220_panda\\\\"
#endif

    <STRING id="STR_ID_GX_PANDA_GAME_NAME"/>
    <STRING id="STR_ID_GX_PANDA_HELP_DESCRIPTION"/>
#endif  //__MMI_GAME_PANDA__

#ifdef __MMI_GAME_MONKEY__
#if defined(__MMI_MAINLCD_128X128__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x128_monkey\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x160_monkey\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_176x220_monkey\\\\"
#endif

	<STRING id="STR_ID_GX_PANDA_GAME_NAME_MONKEY"/>
	<STRING id="STR_ID_GX_PANDA_HELP_DESCRIPTION_MONKEY"/>
#endif  //__MMI_GAME_MONKEY__

#if defined(__MMI_GAME_PANDA__) || defined(__MMI_GAME_MONKEY__)
    <IMAGE id="IMG_ID_GX_PANDA_GAME_ICON">PANDA_IMG_PATH"gx_panda_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_BACKGROUND">PANDA_IMG_PATH"gx_panda_background"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_CLOCK">PANDA_IMG_PATH"gx_panda_clock"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_JUMP">PANDA_IMG_PATH"gx_panda_role_jump"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_FALL_FRAME_0">PANDA_IMG_PATH"gx_panda_role_fall_frame_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_FALL_FRAME_1">PANDA_IMG_PATH"gx_panda_role_fall_frame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_0">PANDA_IMG_PATH"gx_panda_role_left_frame_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_1">PANDA_IMG_PATH"gx_panda_role_left_frame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_0">PANDA_IMG_PATH"gx_panda_role_right_frame_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_1">PANDA_IMG_PATH"gx_panda_role_right_frame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_0">PANDA_IMG_PATH"gx_panda_role_attack_l_frame_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_1">PANDA_IMG_PATH"gx_panda_role_attack_l_frame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_0">PANDA_IMG_PATH"gx_panda_role_attack_r_frame_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_1">PANDA_IMG_PATH"gx_panda_role_attack_r_frame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_LEFT">PANDA_IMG_PATH"gx_panda_enemy_1_left"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_LEFT">PANDA_IMG_PATH"gx_panda_enemy_2_left"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_LEFT">PANDA_IMG_PATH"gx_panda_enemy_3_left"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_LEFT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_1_left_frame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_LEFT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_2_left_frame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_LEFT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_3_left_frame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_RIGHT">PANDA_IMG_PATH"gx_panda_enemy_1_right"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_RIGHT">PANDA_IMG_PATH"gx_panda_enemy_2_right"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_RIGHT">PANDA_IMG_PATH"gx_panda_enemy_3_right"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_RIGHT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_1_right_frame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_RIGHT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_2_right_frame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_RIGHT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_3_right_frame_2"GX_OLD_IMG_TYPE</IMAGE>
	
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_0">PANDA_IMG_PATH"gx_panda_digit_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_1">PANDA_IMG_PATH"gx_panda_digit_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_2">PANDA_IMG_PATH"gx_panda_digit_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_3">PANDA_IMG_PATH"gx_panda_digit_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_4">PANDA_IMG_PATH"gx_panda_digit_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_5">PANDA_IMG_PATH"gx_panda_digit_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_6">PANDA_IMG_PATH"gx_panda_digit_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_7">PANDA_IMG_PATH"gx_panda_digit_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_8">PANDA_IMG_PATH"gx_panda_digit_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_DIGIT_9">PANDA_IMG_PATH"gx_panda_digit_9"GX_OLD_IMG_TYPE</IMAGE>
	
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
        <IMAGE id="IMG_ID_GX_PANDA_SCORE">PANDA_IMG_PATH"gx_panda_score"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_GOTEXT">PANDA_IMG_PATH"gameover\\\\gx_panda_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_PANDA_SCORE_LANGUAGE0">PANDA_IMG_PATH"gx_panda_score"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_SCORE_LANGUAGE1">PANDA_IMG_PATH"multi_lan\\\\gx_panda_score_c"GX_OLD_IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_GX_PANDA_GOTEXT_LANGUAGE0">PANDA_IMG_PATH"gameover\\\\gx_panda_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_GOTEXT_LANGUAGE1">PANDA_IMG_PATH"multi_lan\\\\gameover_c"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_PANDA_GRADESMAP">PANDA_IMG_PATH"gameover\\\\gx_panda_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_GOPIC">PANDA_IMG_PATH"gameover\\\\gx_panda_pic"GX_ANIMATION_IMG_TYPE</IMAGE>

    /* Panda NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_PANDA_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //defined(__MMI_GAME_PANDA__) || defined(__MMI_GAME_MONKEY__)


#ifdef __MMI_GAME_CHICKEN__
#if defined(__MMI_MAINLCD_128X128__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x128_chicken\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x160_chicken\\\\"
#endif

	<STRING id="STR_ID_GX_STAIR_GAME_NAME_CHICKEN"/>
	<STRING id="STR_ID_GX_STAIR_HELP_DESCRIPTION_CHICKEN"/>
#endif  //__MMI_GAME_CHICKEN__

#ifdef __MMI_GAME_ROBOT__
#if defined(__MMI_MAINLCD_176X220__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_176x220_robot\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x160_robot\\\\"
#endif

	<STRING id="STR_ID_GX_STAIR_GAME_NAME_ROBOT"/>
	<STRING id="STR_ID_GX_STAIR_HELP_DESCRIPTION_ROBOT"/>
#endif  //__MMI_GAME_ROBOT__


#if defined(__MMI_GAME_CHICKEN__) || defined(__MMI_GAME_ROBOT__)
	<STRING id="STR_ID_GX_STAIR_LEVEL_EASY"/>
	<STRING id="STR_ID_GX_STAIR_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_STAIR_LEVEL_HARD"/>
    <IMAGE id="IMG_ID_GX_STAIR_BOX">STAIR_IMG_PATH"gx_stair_box"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_FLOAT_STAIR_1">STAIR_IMG_PATH"gx_stair_float_stair_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_FLOAT_STAIR_2">STAIR_IMG_PATH"gx_stair_float_stair_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GAME_ICON">STAIR_IMG_PATH"gx_stair_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE">STAIR_IMG_PATH"gx_stair_role"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_DYING">STAIR_IMG_PATH"gx_stair_role_dying"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_FALLING_0">STAIR_IMG_PATH"gx_stair_role_falling_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_FALLING_1">STAIR_IMG_PATH"gx_stair_role_falling_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_LEFT_0">STAIR_IMG_PATH"gx_stair_role_left_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_LEFT_1">STAIR_IMG_PATH"gx_stair_role_left_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_RIGHT_0">STAIR_IMG_PATH"gx_stair_role_right_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_RIGHT_1">STAIR_IMG_PATH"gx_stair_role_right_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_STAIR">STAIR_IMG_PATH"gx_stair_stair"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_THORN">STAIR_IMG_PATH"gx_stair_thorn"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_THORN_STAIR">STAIR_IMG_PATH"gx_stair_thorn_stair"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_TITLE">STAIR_IMG_PATH"gx_stair_title"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_WALL">STAIR_IMG_PATH"gx_stair_wall"GX_OLD_IMG_TYPE</IMAGE>
    #if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)
    <IMAGE id="IMG_ID_GX_STAIR_ENERGY_BAR">STAIR_IMG_PATH"gx_stair_energy_bar"GX_OLD_IMG_TYPE</IMAGE>
    #elif defined(__MMI_MAINLCD_128X128__)
    <IMAGE id="IMG_ID_GX_STAIR_ENERGY_BAR_HORIZONTAL">STAIR_IMG_PATH"gx_stair_energy_bar_horizontal"GX_OLD_IMG_TYPE</IMAGE>
	#endif
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_FLYING_0">STAIR_IMG_PATH"gx_stair_role_flying_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_ROLE_FLYING_1">STAIR_IMG_PATH"gx_stair_role_flying_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_0">STAIR_IMG_PATH"gx_stair_number_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_1">STAIR_IMG_PATH"gx_stair_number_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_2">STAIR_IMG_PATH"gx_stair_number_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_3">STAIR_IMG_PATH"gx_stair_number_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_4">STAIR_IMG_PATH"gx_stair_number_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_5">STAIR_IMG_PATH"gx_stair_number_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_6">STAIR_IMG_PATH"gx_stair_number_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_7">STAIR_IMG_PATH"gx_stair_number_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_8">STAIR_IMG_PATH"gx_stair_number_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_NUMBER_9">STAIR_IMG_PATH"gx_stair_number_9"GX_ANIMATION_IMG_TYPE</IMAGE>
        <IMAGE id="IMG_ID_GX_STAIR_GRADESMAP">STAIR_IMG_PATH"gameover\\\\gx_stair_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GOPIC">STAIR_IMG_PATH"gameover\\\\gx_stair_pic"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_BACKGROUND">STAIR_IMG_PATH"gx_stair_bg"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
        <IMAGE id="IMG_ID_GX_STAIR_SCORE">STAIR_IMG_PATH"gx_stair_score"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GOTEXT">STAIR_IMG_PATH"gameover\\\\gx_stair_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
        <IMAGE id="IMG_ID_GX_STAIR_FLYING_MARK">STAIR_IMG_PATH"gx_stair_flying_mark"GX_OLD_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_STAIR_SCORE">STAIR_IMG_PATH"multi_lan\\\\score_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GOTEXT_LANGUAGE0">STAIR_IMG_PATH"multi_lan\\\\gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_FLYING_MARK_LANGUAGE0">STAIR_IMG_PATH"gx_stair_flying_mark"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GOTEXT_LANGUAGE1">STAIR_IMG_PATH"multi_lan\\\\gameover_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_FLYING_MARK_LANGUAGE1">STAIR_IMG_PATH"multi_lan\\\\flying_mark_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* stair NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_STAIR_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_GX_STAIR_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_STAIR_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_STAIR_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

#endif  //defined(__MMI_GAME_CHICKEN__) || defined(__MMI_GAME_ROBOT__)


#ifdef __MMI_GAME_UFO__
#if defined(__MMI_MAINLCD_128X128__)
	#define UFO_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\ufo\\\\ufo_128x128_ufo\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
	#define UFO_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\ufo\\\\ufo_128x160_ufo\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
	#define UFO_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\ufo\\\\ufo_176x220_ufo\\\\"
#endif
	<STRING id="STR_ID_GX_UFO_GAME_NAME"/>
	<STRING id="STR_ID_GX_UFO_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_ID_GX_UFO_GAME_ICON">UFO_IMG_PATH"gx_ufo_icon"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_0">UFO_IMG_PATH"gx_ufo_digit_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_1">UFO_IMG_PATH"gx_ufo_digit_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_2">UFO_IMG_PATH"gx_ufo_digit_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_3">UFO_IMG_PATH"gx_ufo_digit_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_4">UFO_IMG_PATH"gx_ufo_digit_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_5">UFO_IMG_PATH"gx_ufo_digit_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_6">UFO_IMG_PATH"gx_ufo_digit_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_7">UFO_IMG_PATH"gx_ufo_digit_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_8">UFO_IMG_PATH"gx_ufo_digit_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_DIGIT_9">UFO_IMG_PATH"gx_ufo_digit_9"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BACKGROUND_1">UFO_IMG_PATH"gx_ufo_background_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BACKGROUND_2">UFO_IMG_PATH"gx_ufo_background_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BACKGROUND_3">UFO_IMG_PATH"gx_ufo_background_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BACKGROUND_4">UFO_IMG_PATH"gx_ufo_background_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BACKGROUND_5">UFO_IMG_PATH"gx_ufo_background_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BACKGROUND_6">UFO_IMG_PATH"gx_ufo_background_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BOSS">UFO_IMG_PATH"gx_ufo_boss"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BOSS_HIT">UFO_IMG_PATH"gx_ufo_boss_hit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_1">UFO_IMG_PATH"gx_ufo_enemy_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_2">UFO_IMG_PATH"gx_ufo_enemy_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_3">UFO_IMG_PATH"gx_ufo_enemy_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_4">UFO_IMG_PATH"gx_ufo_enemy_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_1_HIT">UFO_IMG_PATH"gx_ufo_enemy_1_hit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_2_HIT">UFO_IMG_PATH"gx_ufo_enemy_2_hit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_3_HIT">UFO_IMG_PATH"gx_ufo_enemy_3_hit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_4_HIT">UFO_IMG_PATH"gx_ufo_enemy_4_hit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_1">UFO_IMG_PATH"gx_ufo_enemy_bullet_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_2">UFO_IMG_PATH"gx_ufo_enemy_bullet_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_3">UFO_IMG_PATH"gx_ufo_enemy_bullet_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_4">UFO_IMG_PATH"gx_ufo_enemy_bullet_4"GX_OLD_IMG_TYPE</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_UFO_ENERGY">UFO_IMG_PATH"gx_ufo_energy"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_SCORE">UFO_IMG_PATH"gx_ufo_score"GX_OLD_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_UFO_ENERGY_UNIT">UFO_IMG_PATH"gx_ufo_energy_unit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_WEAPON_1">UFO_IMG_PATH"gx_ufo_weapon_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_WEAPON_2">UFO_IMG_PATH"gx_ufo_weapon_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENERGY_FILL_1">UFO_IMG_PATH"gx_ufo_energy_fill_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ENERGY_FILL_2">UFO_IMG_PATH"gx_ufo_energy_fill_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BOMB_1">UFO_IMG_PATH"gx_ufo_bomb_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_BOMB_2">UFO_IMG_PATH"gx_ufo_bomb_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_FLAME_1">UFO_IMG_PATH"gx_ufo_flame_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_FLAME_2">UFO_IMG_PATH"gx_ufo_flame_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_FLAME_3">UFO_IMG_PATH"gx_ufo_flame_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ROLE">UFO_IMG_PATH"gx_ufo_role"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ROLE_HIT">UFO_IMG_PATH"gx_ufo_role_hit"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_ROLE_BULLET">UFO_IMG_PATH"gx_ufo_role_bullet"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_INVINCIBLE_1">UFO_IMG_PATH"gx_ufo_invincible_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_INVINCIBLE_2">UFO_IMG_PATH"gx_ufo_invincible_2"GX_OLD_IMG_TYPE</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_UFO_LEVEL_CLEAR">UFO_IMG_PATH"gx_ufo_level_clear"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_GOTEXT">UFO_IMG_PATH"gameover\\\\gx_ufo_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_UFO_GRADESMAP">UFO_IMG_PATH"gameover\\\\gx_ufo_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_GOPIC">UFO_IMG_PATH"gameover\\\\gx_ufo_pic"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE0">UFO_IMG_PATH"gx_ufo_level_clear"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_GOTEXT_LANGUAGE0">UFO_IMG_PATH"multi_lan\\\\gx_dance_gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE1">UFO_IMG_PATH"multi_lan\\\\gx_ufo_level_clear_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_GOTEXT_LANGUAGE1">UFO_IMG_PATH"multi_lan\\\\gx_dance_gameover_C"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* UFO NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_UFO_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_UFO__


#ifdef __MMI_GAME_MAGICSUSHI__
#if defined(__MMI_MAINLCD_240X320__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_240x320_magicsushi\\\\"
#elif defined(__MMI_MAINLCD_320X240__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_320x240_magicsushi\\\\"
#elif defined(__MMI_MAINLCD_240X400__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_240x400_magicsushi\\\\"
#elif defined(__MMI_MAINLCD_320X480__)
    #define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_320x480_magicsushi\\\\"
#endif
	<STRING id="STR_ID_GX_MAGICSUSHI_GAME_NAME"/>
	<STRING id="STR_ID_GX_MAGICSUSHI_HELP_DESCRIPTION"/>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAME_ICON">MAGICSUSHI_IMG_PATH"Magicsushi"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_0">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_1">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_2">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_3">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_4">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_5">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_6">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_7">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_8">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_9">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_9"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_NULL">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_null"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_SELECTED">MAGICSUSHI_IMG_PATH"gx_magicsushi_select"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_PROGRESS">MAGICSUSHI_IMG_PATH"gx_magicsushi_progress"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_0">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_1">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_2">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_3">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_4">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_5">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_6">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_7">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC1">MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC2">MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC3">MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_3"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAME_BACKGROUND">MAGICSUSHI_IMG_PATH"gx_magicsushi_background"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER">MAGICSUSHI_IMG_PATH"gx_magicsushi_gameover_TimeOut_E"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_UPLEVEL">MAGICSUSHI_IMG_PATH"gx_magicsushi_uplevel"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NOMOREMOVE">MAGICSUSHI_IMG_PATH"gx_magicsushi_nomoremove"GX_ANIMATION_IMG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_BACKGROUND_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_background"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_gameover_TimeOut_E"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_UPLEVEL_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_uplevel"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NOMOREMOVE_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_nomoremove"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_BACKGROUND_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\bkg_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\gx_magicsushi_gameover_TimeOut_C"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_UPLEVEL_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\uplevel_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NOMOREMOVE_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\nomoremove_C"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_CURSOR">MAGICSUSHI_IMG_PATH"gx_magicsushi_select1"GX_OLD_IMG_TYPE</IMAGE>
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_UP">MAGICSUSHI_IMG_PATH"gx_magicsushi_up"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_DOWN">MAGICSUSHI_IMG_PATH"gx_magicsushi_down"GX_OLD_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GRADEMAP">MAGICSUSHI_IMG_PATH"gx_magicsushi_ScoreBG"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GOPIC">MAGICSUSHI_IMG_PATH"gx_magicsushi_Food"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER_BG">MAGICSUSHI_IMG_PATH"gx_magicsushi_BG"GX_ANIMATION_IMG_TYPE</IMAGE>

    /* Magicsushi NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_MAGICSUSHI_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_MAGICSUSHI__


#ifdef __MMI_GAME_FRUIT__
#if defined(__MMI_MAINLCD_176X220__)
	#define FRUIT_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Fruit\\\\fruit_176x220_fruit\\\\"
#endif
	<STRING id="STR_ID_GX_FRUIT_GAME_NAME"/>
	<STRING id="STR_ID_GX_FRUIT_HELP_DESCRIPTION"/>
	<STRING id="STR_ID_GX_FRUIT_LEVEL_EASY"/>
	<STRING id="STR_ID_GX_FRUIT_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_FRUIT_LEVEL_HARD"/>
    <IMAGE id="IMG_ID_GX_FRUIT_GAME_ICON">FRUIT_IMG_PATH"gx_fruit_icon"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_FRUIT_GOTEXT">FRUIT_IMG_PATH"gx_fruit_gameover_title"GX_OLD_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_FRUIT_GRADESMAP">FRUIT_IMG_PATH"gx_fruit_gradesmap"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_GOPIC">FRUIT_IMG_PATH"gx_fruit_gameover_pic"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODA_ONE_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODA_TWO_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODA_THREE_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODA_MAX_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODB_ONE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODB_TWO_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODB_THREE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODB_MAX_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODC_ONE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODC_TWO_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODC_THREE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_FOODC_MAX_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_ROCK_ONEPIECE">FRUIT_IMG_PATH"gx_fruit_rock"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TREASURE_1">FRUIT_IMG_PATH"gx_fruit_item_treasure_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TREASURE_2">FRUIT_IMG_PATH"gx_fruit_item_treasure_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TREASURE_3">FRUIT_IMG_PATH"gx_fruit_item_treasure_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TREASURE_4">FRUIT_IMG_PATH"gx_fruit_item_treasure_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TREASURE_5">FRUIT_IMG_PATH"gx_fruit_item_treasure_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_left_1a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_left_1b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_left_2a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_left_2b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_left_3a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_left_3b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_right_1a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_right_1b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_right_2a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_right_2b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_right_3a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_right_3b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_A">FRUIT_IMG_PATH"gx_fruit_kickwavela"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_B">FRUIT_IMG_PATH"gx_fruit_kickwavelb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_kickwavera"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_kickwaverb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_GAMEOVER">FRUIT_IMG_PATH"gx_fruit_chef_gameover"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_CUTPREP">FRUIT_IMG_PATH"gx_fruit_chef_right_cutprep"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_CUT">FRUIT_IMG_PATH"gx_fruit_chef_right_cut"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_KICKPREP">FRUIT_IMG_PATH"gx_fruit_chef_right_kickprep"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_KICK">FRUIT_IMG_PATH"gx_fruit_chef_right_kick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_CUTPREP">FRUIT_IMG_PATH"gx_fruit_chef_left_cutprep"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_CUT">FRUIT_IMG_PATH"gx_fruit_chef_left_cut"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_KICKPREP">FRUIT_IMG_PATH"gx_fruit_chef_left_kickprep"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_KICK">FRUIT_IMG_PATH"gx_fruit_chef_left_kick"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_FAINTA">FRUIT_IMG_PATH"gx_fruit_chef_fainta"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_FAINTB">FRUIT_IMG_PATH"gx_fruit_chef_faintb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKA">FRUIT_IMG_PATH"gx_fruit_chef_right_walka"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKB">FRUIT_IMG_PATH"gx_fruit_chef_right_walkb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_WALKA">FRUIT_IMG_PATH"gx_fruit_chef_left_walka"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_WALKB">FRUIT_IMG_PATH"gx_fruit_chef_left_walkb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_PLATFORM">FRUIT_IMG_PATH"gx_fruit_platform"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TRACKA">FRUIT_IMG_PATH"gx_fruit_tracka"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_TRACKB">FRUIT_IMG_PATH"gx_fruit_trackb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_OKA">FRUIT_IMG_PATH"gx_fruit_shaker_ok_a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_OKB">FRUIT_IMG_PATH"gx_fruit_shaker_ok_b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVA_A">FRUIT_IMG_PATH"gx_fruit_shaker_pblva_a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVA_B">FRUIT_IMG_PATH"gx_fruit_shaker_pblva_b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVB_A">FRUIT_IMG_PATH"gx_fruit_shaker_pblvb_a"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVB_B">FRUIT_IMG_PATH"gx_fruit_shaker_pblvb_b"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_SHAKER_BROKEN">FRUIT_IMG_PATH"gx_fruit_shaker_broken"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_WORKER_STEPA">FRUIT_IMG_PATH"gx_fruit_worker_walka"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_WORKER_STEPB">FRUIT_IMG_PATH"gx_fruit_worker_walkb"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_WORKER_FIXA">FRUIT_IMG_PATH"gx_fruit_worker_fixa"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_WORKER_FIXB">FRUIT_IMG_PATH"gx_fruit_worker_fixb"GX_OLD_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_FRUIT_BGROUND">FRUIT_IMG_PATH"gx_fruit_bg"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_FRUIT_BGROUND_LANGUAGE0">FRUIT_IMG_PATH"gx_fruit_bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE0">FRUIT_IMG_PATH"gx_fruit_gameover_title"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_BGROUND_LANGUAGE1">FRUIT_IMG_PATH"multi_lan\\\\gx_fruit_bg_C"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE1">FRUIT_IMG_PATH"multi_lan\\\\gx_fruit_gameover_C"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Fruit NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_FRUIT_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_NO_USE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_FRUIT__


#ifdef __MMI_GAME_VSMJ__
#if defined(__MMI_MAINLCD_240X320__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_240x320_vsmj\\\\"
#elif defined(__MMI_MAINLCD_320X240__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_320x240_vsmj\\\\"
#elif defined(__MMI_MAINLCD_240X400__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_240x400_vsmj\\\\"
#elif defined(__MMI_MAINLCD_320X480__)
    #define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_320x480_vsmj\\\\"
#endif
	<STRING id="STR_ID_GX_VSMJ_GAME_NAME"/>
	<STRING id="STR_ID_GX_VSMJ_HELP_DESCRIPTION"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL_CPUVSCPU"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL1"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL2"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL3"/>
	<STRING id="STR_ID_GX_VSMJ_CUR_GAME"/>
    <IMAGE id="IMG_ID_GX_VSMJ_GAME_ICON">VSMJ_IMG_PATH"gx_vsmj_icon"GX_ANIMATION_IMG_TYPE</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_VSMJ_GOTEXT">VSMJ_IMG_PATH"gx_vsmj_gameover_title"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_YOU_WIN">VSMJ_IMG_PATH"multi_lan\\\\gx_vsmj_complete"GX_ANIMATION_IMG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE0">VSMJ_IMG_PATH"gameover"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_YOU_WIN_LANGUAGE0">VSMJ_IMG_PATH"multi_lan\\\\gx_vsmj_complete"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE1">VSMJ_IMG_PATH"multi_lan\\\\gameover_c"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_YOU_WIN_LANGUAGE1">VSMJ_IMG_PATH"multi_lan\\\\gx_vsmj_complete_c"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_VSMJ_GRADESMAP">VSMJ_IMG_PATH"gx_vsmj_gradesmap"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GOPIC">VSMJ_IMG_PATH"gx_vsmj_gameover_pic"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_EAST">VSMJ_IMG_PATH"T28"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_WEST">VSMJ_IMG_PATH"T29"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_SOUTH">VSMJ_IMG_PATH"T30"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_NORTH">VSMJ_IMG_PATH"T31"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_CHUNG">VSMJ_IMG_PATH"T32"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_FA">VSMJ_IMG_PATH"T33"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_BAI">VSMJ_IMG_PATH"T34"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_1W">VSMJ_IMG_PATH"T1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_2W">VSMJ_IMG_PATH"T2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_3W">VSMJ_IMG_PATH"T3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_4W">VSMJ_IMG_PATH"T4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_5W">VSMJ_IMG_PATH"T5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_6W">VSMJ_IMG_PATH"T6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_7W">VSMJ_IMG_PATH"T7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_8W">VSMJ_IMG_PATH"T8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_9W">VSMJ_IMG_PATH"T9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_1S">VSMJ_IMG_PATH"T19"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_2S">VSMJ_IMG_PATH"T20"GX_ANIMATION_IMG_TYPE</IMAGE>
     <IMAGE id="IMG_ID_GX_VSMJ_BRICK_3S">VSMJ_IMG_PATH"T21"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_4S">VSMJ_IMG_PATH"T22"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_5S">VSMJ_IMG_PATH"T23"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_6S">VSMJ_IMG_PATH"T24"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_7S">VSMJ_IMG_PATH"T25"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_8S">VSMJ_IMG_PATH"T26"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_9S">VSMJ_IMG_PATH"T27"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_1T">VSMJ_IMG_PATH"T10"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_2T">VSMJ_IMG_PATH"T11"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_3T">VSMJ_IMG_PATH"T12"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_4T">VSMJ_IMG_PATH"T13"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_5T">VSMJ_IMG_PATH"T14"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_6T">VSMJ_IMG_PATH"T15"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_7T">VSMJ_IMG_PATH"T16"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_8T">VSMJ_IMG_PATH"T17"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_9T">VSMJ_IMG_PATH"T18"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_SPRING">VSMJ_IMG_PATH"T35"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_SUMMER">VSMJ_IMG_PATH"T36"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_AUTUMN">VSMJ_IMG_PATH"T37"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_WINTER">VSMJ_IMG_PATH"T38"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_M">VSMJ_IMG_PATH"T39"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_L">VSMJ_IMG_PATH"T40"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_Z">VSMJ_IMG_PATH"T41"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_J">VSMJ_IMG_PATH"T42"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_TABLE_VER_BACK">VSMJ_IMG_PATH"table_ver_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_TABLE_HOR_BACK">VSMJ_IMG_PATH"table_hor_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_LEFT_BACK">VSMJ_IMG_PATH"user_left_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_RIGHT_BACK">VSMJ_IMG_PATH"user_right_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_UP_BACK">VSMJ_IMG_PATH"user_up_back"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_LR_HIDE_BACK">VSMJ_IMG_PATH"user_lr_hide_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK">VSMJ_IMG_PATH"user_ud_hide_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_eat_base"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_eat_invalid"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_eat_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_0">VSMJ_IMG_PATH"gx_vsmj_sign_eat_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_1">VSMJ_IMG_PATH"gx_vsmj_sign_eat_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_2">VSMJ_IMG_PATH"gx_vsmj_sign_eat_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_PON_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_pon_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_PON_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_pon_invalid"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_PON_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_pon_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_GUN_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_gun_base"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_GUN_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_gun_invalid"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_GUN_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_gun_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_HOU_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_hou_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_HOU_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_hou_invalid"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_HOU_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_hou_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_CANCEL_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_cancel"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_CANCEL_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_cancel_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_LIOU_GU">VSMJ_IMG_PATH"gx_vsmj_sign_liou_gu"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_PEN_CURSOR_OFF">VSMJ_IMG_PATH"gx_vsmj_pen_cursor_off"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_PEN_CURSOR_ON">VSMJ_IMG_PATH"gx_vsmj_pen_cursor_on"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_8_FLOWER">VSMJ_IMG_PATH"score_8_flower"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_7_1_FLOWER">VSMJ_IMG_PATH"score_7_1_flower"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_ZE_MO">VSMJ_IMG_PATH"score_ze_mo"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_HUO_BY_GUN">VSMJ_IMG_PATH"score_hou_by_gun"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_MEN_CHIN">VSMJ_IMG_PATH"score_men_chin"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_MENCHIN_ZEMO">VSMJ_IMG_PATH"score_menchin_zemo"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_FLOWER_SEASON_SET">VSMJ_IMG_PATH"score_flower_season_set"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_FLOWER_PLANT_SET">VSMJ_IMG_PATH"score_flower_plant_set"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_SEA_MOON">VSMJ_IMG_PATH"score_sea_moon"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_ALL_ASK">VSMJ_IMG_PATH"score_chuan_chio"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_BIG_3_YUANG">VSMJ_IMG_PATH"score_big_3_yuang"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_SMALL_3_YUANG">VSMJ_IMG_PATH"score_small_3_yuang"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_CHUNG">VSMJ_IMG_PATH"score_chung"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_FA">VSMJ_IMG_PATH"score_fa"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_BAI">VSMJ_IMG_PATH"score_bai"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_BIG_4_WIND">VSMJ_IMG_PATH"score_big_4_shi"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_SMALL_4_WIND">VSMJ_IMG_PATH"score_small_4_shi"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_3_ENKE">VSMJ_IMG_PATH"score_3_enke"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_4_ENKE">VSMJ_IMG_PATH"score_4_enke"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_5_ENKE">VSMJ_IMG_PATH"score_5_enke"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_NUM_1_COLOR">VSMJ_IMG_PATH"score_chin_1_color"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_MIX_1_COLOR">VSMJ_IMG_PATH"score_mix_1_color"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_PAIR_PAIR_HOU">VSMJ_IMG_PATH"score_pair_pair_hou"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_SCORE_NOTHING">VSMJ_IMG_PATH"score_nothing"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_0">VSMJ_IMG_PATH"gx_VSMJ_number_0"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_1">VSMJ_IMG_PATH"gx_VSMJ_number_1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_2">VSMJ_IMG_PATH"gx_VSMJ_number_2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_3">VSMJ_IMG_PATH"gx_VSMJ_number_3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_4">VSMJ_IMG_PATH"gx_VSMJ_number_4"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_5">VSMJ_IMG_PATH"gx_VSMJ_number_5"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_6">VSMJ_IMG_PATH"gx_VSMJ_number_6"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_7">VSMJ_IMG_PATH"gx_VSMJ_number_7"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_8">VSMJ_IMG_PATH"gx_VSMJ_number_8"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_NUMBER_9">VSMJ_IMG_PATH"gx_VSMJ_number_9"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_ARROWHEAD">VSMJ_IMG_PATH"gx_vsmj_arrowhead"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_TOP_SOLID">VSMJ_IMG_PATH"gx_vsmj_user_top_solid"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BOTTOM_SOLID">VSMJ_IMG_PATH"gx_vsmj_user_bottom_solid"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_EATCASE_BG1">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_EATCASE_BG2">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_EATCASE_BG3">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_EATCASE_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_BG1">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG1"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_BG2">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG2"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_BG3">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG3"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_highlight"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GAMES">VSMJ_IMG_PATH"gx_vsmj_Games"GX_ANIMATION_IMG_TYPE</IMAGE>
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    <IMAGE id="IMG_ID_GX_VSMJ_BACK_UP">VSMJ_IMG_PATH"gx_vsmj_back_up"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BACK_DOWN">VSMJ_IMG_PATH"gx_vsmj_back_down"GX_OLD_IMG_TYPE</IMAGE>
#endif /*__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__*/
#endif /*__MMI_TOUCH_SCREEN__*/

    /* VSMJ NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_VSMJ_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_VSMJ_LEVEL1" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_VSMJ_LEVEL2" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_VSMJ_LEVEL3" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_VSMJ__

#ifdef __MMI_GAME_FRUITNINJA__
#if defined(__MMI_MAINLCD_176X220__)
    #define FRUITNINJA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\FruitNinja\\\\FruitNinja_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define FRUITNINJA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\FruitNinja\\\\FruitNinja_240x320\\\\"
#endif
    <STRING id="STR_ID_GX_FRUITNINJA_GAME_NAME"/>
    <STRING id="STR_ID_GX_FRUITNINJA_HELP_DESCRIPTION"/>
    <STRING id="STR_ID_GX_FRUITNINJA_LEVEL_EASY"/>
    <STRING id="STR_ID_GX_FRUITNINJA_LEVEL_NORMAL"/>
    <STRING id="STR_ID_GX_FRUITNINJA_LEVEL_HARD"/>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODA_ONE_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_fooda1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODA_TWO_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_fooda2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODA_THREE_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_fooda3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODA_MAX_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_fooda4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODB_ONE_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodb1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODB_TWO_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodb2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODB_THREE_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodb3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODB_MAX_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodb4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODC_ONE_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodc1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODC_TWO_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodc2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODC_THREE_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodc3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_FOODC_MAX_PIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_foodc4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_ROCK_ONEPIECE">FRUITNINJA_IMG_PATH"gx_fruitninja_rock"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_TREASURE_1">FRUITNINJA_IMG_PATH"gx_fruitninja_item_treasure_01"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_TREASURE_2">FRUITNINJA_IMG_PATH"gx_fruitninja_item_treasure_02"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_TREASURE_3">FRUITNINJA_IMG_PATH"gx_fruitninja_item_treasure_03"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_TREASURE_4">FRUITNINJA_IMG_PATH"gx_fruitninja_item_treasure_04"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_TREASURE_5">FRUITNINJA_IMG_PATH"gx_fruitninja_item_treasure_05"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_SWDWAVELOW_LEFT_A">FRUITNINJA_IMG_PATH"gx_fruitninja_item_wave_left_1a"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_SWDWAVELOW_LEFT_B">FRUITNINJA_IMG_PATH"gx_fruitninja_item_wave_left_1b"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_SWDWAVELOW_RIGHT_A">FRUITNINJA_IMG_PATH"gx_fruitninja_item_wave_right_1a"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_SWDWAVELOW_RIGHT_B">FRUITNINJA_IMG_PATH"gx_fruitninja_item_wave_right_1b"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_CUTPREP">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_right_cutprep"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_CUT">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_right_cut"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_KICKPREP">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_right_kickprep"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_LEFT_CUTPREP">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_left_cutprep"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_LEFT_CUT">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_left_cut"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_LEFT_KICKPREP">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_left_kickprep"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_RIGHT_WALKA">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_right_walka"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_LEFT_WALKA">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_left_walka"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_NINJA_SHADOW">FRUITNINJA_IMG_PATH"gx_fruitninja_ninja_shadow"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_MONSTER_OKA">FRUITNINJA_IMG_PATH"gx_fruitninja_monster_ok_a"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_MONSTER_PBLVA_A">FRUITNINJA_IMG_PATH"gx_fruitninja_monster_pblva_a"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_MONSTER_PBLVB_A">FRUITNINJA_IMG_PATH"gx_fruitninja_monster_pblvb_a"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_MONSTER_BROKEN">FRUITNINJA_IMG_PATH"gx_fruitninja_monster_broken"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_MONSTER_SHADOW">FRUITNINJA_IMG_PATH"gx_fruitninja_monster_shadow"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_WORKER_STEPA">FRUITNINJA_IMG_PATH"gx_fruitninja_worker_walka"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_WORKER_STEPB">FRUITNINJA_IMG_PATH"gx_fruitninja_worker_walkb"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_WORKER_FIXA">FRUITNINJA_IMG_PATH"gx_fruitninja_worker_fixa"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_WORKER_FIXB">FRUITNINJA_IMG_PATH"gx_fruitninja_worker_fixb"GX_IMG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_FRUITNINJA_BGROUND">FRUITNINJA_IMG_PATH"gx_fruitninja_bg"GX_JPEG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_FRUITNINJA_BGROUND_LANGUAGE0">FRUITNINJA_IMG_PATH"gx_fruitninja_bg"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUITNINJA_BGROUND_LANGUAGE1">FRUITNINJA_IMG_PATH"multi_lan\\\\gx_fruitninja_bg_C"GX_JPEG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* FruitNinja NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_FRUITNINJA_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUITNINJA_NO_USE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUITNINJA_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUITNINJA_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUITNINJA_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_FRUITNINJA__

#ifdef __MMI_GAME_DIAMOND__
#if defined(__MMI_MAINLCD_176X220__)
    #define DIAMOND_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Diamond\\\\Diamond_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define DIAMOND_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Diamond\\\\Diamond_240x320\\\\"
#endif
    <STRING id="STR_ID_GX_DIAMOND_GAME_NAME"/>
    #ifndef __MMI_TOUCH_SCREEN__
    <STRING id="STR_ID_GX_DIAMOND_HELP_DESCRIPTION"/>
    #else    
    <STRING id="STR_ID_GX_DIAMOND_HELP_DESCRIPTION_TOUCH"/>
    #endif
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_0">DIAMOND_IMG_PATH"gx_diamond_num_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_1">DIAMOND_IMG_PATH"gx_diamond_num_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_2">DIAMOND_IMG_PATH"gx_diamond_num_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_3">DIAMOND_IMG_PATH"gx_diamond_num_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_4">DIAMOND_IMG_PATH"gx_diamond_num_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_5">DIAMOND_IMG_PATH"gx_diamond_num_5"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_6">DIAMOND_IMG_PATH"gx_diamond_num_6"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_7">DIAMOND_IMG_PATH"gx_diamond_num_7"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_8">DIAMOND_IMG_PATH"gx_diamond_num_8"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NUMBER_9">DIAMOND_IMG_PATH"gx_diamond_num_9"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_NULL">DIAMOND_IMG_PATH"gx_diamond_item_null"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_SELECTED">DIAMOND_IMG_PATH"gx_diamond_select"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_PROGRESS_1">DIAMOND_IMG_PATH"gx_diamond_progress1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_PROGRESS_2">DIAMOND_IMG_PATH"gx_diamond_progress2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_0">DIAMOND_IMG_PATH"gx_diamond_item_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_1">DIAMOND_IMG_PATH"gx_diamond_item_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_2">DIAMOND_IMG_PATH"gx_diamond_item_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_3">DIAMOND_IMG_PATH"gx_diamond_item_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_4">DIAMOND_IMG_PATH"gx_diamond_item_5"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_5">DIAMOND_IMG_PATH"gx_diamond_item_6"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_6">DIAMOND_IMG_PATH"gx_diamond_item_7"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_7">DIAMOND_IMG_PATH"gx_diamond_item_8"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_MAGIC1">DIAMOND_IMG_PATH"gx_diamond_magic_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_MAGIC2">DIAMOND_IMG_PATH"gx_diamond_magic_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_TYPE_MAGIC3">DIAMOND_IMG_PATH"gx_diamond_magic_3"GX_IMG_TYPE</IMAGE>
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_DIAMOND_BACKGROUND_LANGUAGE0">DIAMOND_IMG_PATH"gx_diamond_background"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_UPLEVEL_LANGUAGE0">DIAMOND_IMG_PATH"gx_diamond_uplevel"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NOMOREMOVE_LANGUAGE0">DIAMOND_IMG_PATH"gx_diamond_nomoremove"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_BACKGROUND_LANGUAGE1">DIAMOND_IMG_PATH"multi_lan\\\\gx_diamond_background_C"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_UPLEVEL_LANGUAGE1">DIAMOND_IMG_PATH"multi_lan\\\\gx_diamond_uplevel_C"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NOMOREMOVE_LANGUAGE1">DIAMOND_IMG_PATH"multi_lan\\\\gx_diamond_nomoremove_c"GX_IMG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_DIAMOND_BACKGROUND">DIAMOND_IMG_PATH"gx_diamond_background"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_UPLEVEL">DIAMOND_IMG_PATH"gx_diamond_uplevel"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_NOMOREMOVE">DIAMOND_IMG_PATH"gx_diamond_nomoremove"GX_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_DIAMOND_CURSOR">DIAMOND_IMG_PATH"gx_diamond_select1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_DIAMOND_GRADEMAP">DIAMOND_IMG_PATH"gx_diamond_score_bg"GX_JPEG_TYPE</IMAGE>

    /* Diamond NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_DIAMOND_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_DIAMOND__

#ifdef __MMI_GAME_NINJACLIMB__
#if defined(__MMI_MAINLCD_128X128__)
    #define NINJACLIMB_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\NinjaClimb\\\\NinjaClimb_128x128\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
    #define NINJACLIMB_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\NinjaClimb\\\\NinjaClimb_128x160\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
    #define NINJACLIMB_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\NinjaClimb\\\\NinjaClimb_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define NINJACLIMB_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\NinjaClimb\\\\NinjaClimb_240x320\\\\"
#endif

    <STRING id="STR_ID_GX_NINJACLIMB_GAME_NAME"/>
    #ifndef __MMI_TOUCH_SCREEN__
    <STRING id="STR_ID_GX_NINJACLIMB_HELP_DESCRIPTION"/>
    #else
    <STRING id="STR_ID_GX_NINJACLIMB_HELP_DESCRIPTION_TOUCH"/>
    #endif

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_NINJACLIMB_BACKGROUND">NINJACLIMB_IMG_PATH"gx_ninjaclimb_background"GX_JPEG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_NINJACLIMB_BACKGROUND_LANGUAGE0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_background"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_BACKGROUND_LANGUAGE1">NINJACLIMB_IMG_PATH"multi_lan\\\\gx_ninjaclimb_background_C"GX_JPEG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_NINJACLIMB_CLOCK">NINJACLIMB_IMG_PATH"gx_ninjaclimb_clock"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_FALL_LEFT_FRAME_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_fall_left_frame_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_FALL_LEFT_FRAME_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_fall_left_frame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_FALL_RIGHT_FRAME_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_fall_right_frame_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_FALL_RIGHT_FRAME_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_fall_right_frame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_LEFT_FRAME_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_left_frame_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_LEFT_FRAME_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_left_frame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_RIGHT_FRAME_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_right_frame_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_RIGHT_FRAME_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_right_frame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_ATTACK_L_FRAME_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_attack_l_frame_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_ATTACK_L_FRAME_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_attack_l_frame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_ATTACK_R_FRAME_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_attack_r_frame_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ROLE_ATTACK_R_FRAME_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_role_attack_r_frame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_1_LEFT">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_1_left"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_2_LEFT">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_2_left"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_1_LEFT_FRAME_2">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_1_left_frame_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_2_LEFT_FRAME_2">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_2_left_frame_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_1_RIGHT">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_1_right"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_2_RIGHT">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_2_right"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_1_RIGHT_FRAME_2">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_1_right_frame_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_ENEMY_2_RIGHT_FRAME_2">NINJACLIMB_IMG_PATH"gx_ninjaclimb_enemy_2_right_frame_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_0">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_1">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_2">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_3">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_4">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_5">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_5"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_6">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_6"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_7">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_7"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_8">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_8"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_NINJACLIMB_DIGIT_9">NINJACLIMB_IMG_PATH"gx_ninjaclimb_digit_9"GX_IMG_TYPE</IMAGE>
    
    /* NinjaClimb NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_NINJACLIMB_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //defined(__MMI_GAME_NINJACLIMB__)

#ifdef __MMI_GAME_FROGCANDY__
#if defined(__MMI_MAINLCD_128X128__)
    #define FROGCANDY_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\FrogCandy\\\\FrogCandy_128x128\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
    #define FROGCANDY_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\FrogCandy\\\\FrogCandy_128x160\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
    #define FROGCANDY_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\FrogCandy\\\\FrogCandy_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define FROGCANDY_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\FrogCandy\\\\FrogCandy_240x320\\\\"
#endif
    <STRING id="STR_GX_FROGCANDY_GAME_NAME"/>
    <STRING id="STR_GX_FROGCANDY_EASY"/>
    <STRING id="STR_GX_FROGCANDY_NORMAL"/>
    <STRING id="STR_GX_FROGCANDY_HARD"/>
    #ifndef __MMI_TOUCH_SCREEN__
    <STRING id="STR_GX_FROGCANDY_HELP_DESCRIPTION"/>
    #else
    <STRING id="STR_GX_FROGCANDY_HELP_DESCRIPTION_TOUCH"/>
    #endif
    /*<IMAGE id="IMG_GX_FROGCANDY_GAME_ICON">FROGCANDY_IMG_PATH"frogcandy"GX_IMG_TYPE</IMAGE>*/
    <IMAGE id="IMG_GX_FROGCANDY_BASKET">FROGCANDY_IMG_PATH"picture\\\\basket"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_GIFT">FROGCANDY_IMG_PATH"picture\\\\gift"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_GOLDNOTE">FROGCANDY_IMG_PATH"picture\\\\goldnote"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_BOMB">FROGCANDY_IMG_PATH"picture\\\\bomb"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_APPLE">FROGCANDY_IMG_PATH"picture\\\\apple"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_SPIDER">FROGCANDY_IMG_PATH"picture\\\\spider"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_BATTERY20">FROGCANDY_IMG_PATH"picture\\\\bluebattery"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_BATTERYFULL">FROGCANDY_IMG_PATH"picture\\\\redbattery"GX_IMG_TYPE</IMAGE>    
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_ANGLE">FROGCANDY_IMG_PATH"picture\\\\angel"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_THEIF">FROGCANDY_IMG_PATH"picture\\\\thief"GX_IMG_TYPE</IMAGE>    
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_DENONATOR">FROGCANDY_IMG_PATH"picture\\\\detonator"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_MONEY">FROGCANDY_IMG_PATH"picture\\\\money"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_BAT">FROGCANDY_IMG_PATH"picture\\\\bat"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_EVIL">FROGCANDY_IMG_PATH"picture\\\\evil"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_ENERGYBAR">FROGCANDY_IMG_PATH"energy\\\\enerygybar"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_OBJECT_LEVEL">FROGCANDY_IMG_PATH"level\\\\level"GX_IMG_TYPE</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_LANGUAGE0">FROGCANDY_IMG_PATH"map\\\\bg"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_TIMER_LANGUAGE0">FROGCANDY_IMG_PATH"map\\\\timer"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_LEVEL_LANGUAGE0">FROGCANDY_IMG_PATH"map\\\\level"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_LANGUAGE1">FROGCANDY_IMG_PATH"multi_lan\\\\bg_C"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_TIMER_LANGUAGE1">FROGCANDY_IMG_PATH"multi_lan\\\\timer_C"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_LEVEL_LANGUAGE1">FROGCANDY_IMG_PATH"multi_lan\\\\level_C"GX_IMG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND">FROGCANDY_IMG_PATH"map\\\\bg"GX_JPEG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_TIMER">FROGCANDY_IMG_PATH"map\\\\timer"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_GX_FROGCANDY_BACKGROUND_LEVEL">FROGCANDY_IMG_PATH"map\\\\level"GX_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* FrogCandy NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GAME_FROGCANDY_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FROGCANDY_OPTION_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FROGCANDY_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FROGCANDY_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FROGCANDY_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_FROGCANDY__

#ifdef __MMI_GAME_TRUEMAN__
#if defined(__MMI_MAINLCD_128X128__)
    #define TRUEMAN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TrueMan\\\\TrueMan_128x128\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
    #define TRUEMAN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TrueMan\\\\TrueMan_128x160\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
    #define TRUEMAN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TrueMan\\\\TrueMan_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define TRUEMAN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TrueMan\\\\TrueMan_240x320\\\\"
#endif

    <STRING id="STR_ID_GX_TRUEMAN_GAME_NAME"/>
    <STRING id="STR_ID_GX_TRUEMAN_HELP_DESCRIPTION"/>

    <STRING id="STR_ID_GX_TRUEMAN_LEVEL_EASY"/>
    <STRING id="STR_ID_GX_TRUEMAN_LEVEL_NORMAL"/>
    <STRING id="STR_ID_GX_TRUEMAN_LEVEL_HARD"/>
    <IMAGE id="IMG_ID_GX_TRUEMAN_FLOAT_STEP_1">TRUEMAN_IMG_PATH"gx_trueman_float_step_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_FLOAT_STEP_2">TRUEMAN_IMG_PATH"gx_trueman_float_step_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE">TRUEMAN_IMG_PATH"gx_trueman_role"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_DYING">TRUEMAN_IMG_PATH"gx_trueman_role_dying"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_FALLING_0">TRUEMAN_IMG_PATH"gx_trueman_role_falling_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_FALLING_1">TRUEMAN_IMG_PATH"gx_trueman_role_falling_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_LEFT_0">TRUEMAN_IMG_PATH"gx_trueman_role_left_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_LEFT_1">TRUEMAN_IMG_PATH"gx_trueman_role_left_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_RIGHT_0">TRUEMAN_IMG_PATH"gx_trueman_role_right_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_RIGHT_1">TRUEMAN_IMG_PATH"gx_trueman_role_right_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_STEP">TRUEMAN_IMG_PATH"gx_trueman_step"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_THORN">TRUEMAN_IMG_PATH"gx_trueman_thorn"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_THORN_STEP">TRUEMAN_IMG_PATH"gx_trueman_thorn_step"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ENERGY_BAR_1">TRUEMAN_IMG_PATH"gx_trueman_energy_bar_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ENERGY_BAR_2">TRUEMAN_IMG_PATH"gx_trueman_energy_bar_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ENERGY_BAR_3">TRUEMAN_IMG_PATH"gx_trueman_energy_bar_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ENERGY_BAR_4">TRUEMAN_IMG_PATH"gx_trueman_energy_bar_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ENERGY_BAR_5">TRUEMAN_IMG_PATH"gx_trueman_energy_bar_5"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_ROLE_FLYING">TRUEMAN_IMG_PATH"gx_trueman_role_flying"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_0">TRUEMAN_IMG_PATH"gx_trueman_number_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_1">TRUEMAN_IMG_PATH"gx_trueman_number_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_2">TRUEMAN_IMG_PATH"gx_trueman_number_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_3">TRUEMAN_IMG_PATH"gx_trueman_number_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_4">TRUEMAN_IMG_PATH"gx_trueman_number_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_5">TRUEMAN_IMG_PATH"gx_trueman_number_5"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_6">TRUEMAN_IMG_PATH"gx_trueman_number_6"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_7">TRUEMAN_IMG_PATH"gx_trueman_number_7"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_8">TRUEMAN_IMG_PATH"gx_trueman_number_8"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_NUMBER_9">TRUEMAN_IMG_PATH"gx_trueman_number_9"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_BACKGROUND">TRUEMAN_IMG_PATH"gx_trueman_bg"GX_JPEG_TYPE</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
        <IMAGE id="IMG_ID_GX_TRUEMAN_SCORE">TRUEMAN_IMG_PATH"gx_trueman_score"GX_IMG_TYPE</IMAGE>
        <IMAGE id="IMG_ID_GX_TRUEMAN_FLYING_MARK">TRUEMAN_IMG_PATH"gx_trueman_flying_mark"GX_IMG_TYPE</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_TRUEMAN_SCORE_LANGUAGE0">TRUEMAN_IMG_PATH"gx_trueman_score"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_FLYING_MARK_LANGUAGE0">TRUEMAN_IMG_PATH"gx_trueman_flying_mark"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_SCORE_LANGUAGE1">TRUEMAN_IMG_PATH"multi_lan\\\\score_C"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TRUEMAN_FLYING_MARK_LANGUAGE1">TRUEMAN_IMG_PATH"multi_lan\\\\flying_mark_C"GX_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* TrueMan NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_TRUEMAN_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_GX_TRUEMAN_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_TRUEMAN_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_TRUEMAN_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

#endif  //defined(__MMI_GAME_TRUEMAN__)

#ifdef __MMI_GAME_TOPGUN__
#if defined(__MMI_MAINLCD_128X128__)
    #define TOPGUN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TopGun\\\\TopGun_128x128\\\\"
#elif defined(__MMI_MAINLCD_128X160__)
    #define TOPGUN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TopGun\\\\TopGun_128x160\\\\"
#elif defined(__MMI_MAINLCD_176X220__)
    #define TOPGUN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TopGun\\\\TopGun_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define TOPGUN_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\TopGun\\\\TopGun_240x320\\\\"
#endif
    <STRING id="STR_ID_GX_TOPGUN_GAME_NAME"/>
    #ifndef __MMI_TOUCH_SCREEN__
    <STRING id="STR_ID_GX_TOPGUN_HELP_DESCRIPTION"/>
    #else
    <STRING id="STR_ID_GX_TOPGUN_HELP_DESCRIPTION_TOUCH"/>
    #endif
    <IMAGE id="IMG_ID_GX_TOPGUN_BACKGROUND">TOPGUN_IMG_PATH"gx_topgun_background"GX_JPEG_TYPE</IMAGE>    
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_0">TOPGUN_IMG_PATH"gx_topgun_digit_0"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_1">TOPGUN_IMG_PATH"gx_topgun_digit_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_2">TOPGUN_IMG_PATH"gx_topgun_digit_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_3">TOPGUN_IMG_PATH"gx_topgun_digit_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_4">TOPGUN_IMG_PATH"gx_topgun_digit_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_5">TOPGUN_IMG_PATH"gx_topgun_digit_5"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_6">TOPGUN_IMG_PATH"gx_topgun_digit_6"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_7">TOPGUN_IMG_PATH"gx_topgun_digit_7"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_8">TOPGUN_IMG_PATH"gx_topgun_digit_8"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_DIGIT_9">TOPGUN_IMG_PATH"gx_topgun_digit_9"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENEMY_1">TOPGUN_IMG_PATH"gx_topgun_enemy_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENEMY_2">TOPGUN_IMG_PATH"gx_topgun_enemy_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENEMY_3">TOPGUN_IMG_PATH"gx_topgun_enemy_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENEMY_4">TOPGUN_IMG_PATH"gx_topgun_enemy_4"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_BOSS">TOPGUN_IMG_PATH"gx_topgun_boss"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENEMY_BULLET_1">TOPGUN_IMG_PATH"gx_topgun_enemy_bullet_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENEMY_BULLET_2">TOPGUN_IMG_PATH"gx_topgun_enemy_bullet_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_BOSS_BULLET">TOPGUN_IMG_PATH"gx_topgun_boss_bullet"GX_IMG_TYPE</IMAGE>    
    <IMAGE id="IMG_ID_GX_TOPGUN_ENERGY_UNIT">TOPGUN_IMG_PATH"gx_topgun_energy_unit"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_WEAPON">TOPGUN_IMG_PATH"gx_topgun_weapon"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENERGY_FILL">TOPGUN_IMG_PATH"gx_topgun_energy_fill"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_BOMB">TOPGUN_IMG_PATH"gx_topgun_bomb"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_INVINCIBLE">TOPGUN_IMG_PATH"gx_topgun_invincible"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_FLAME_1">TOPGUN_IMG_PATH"gx_topgun_flame_1"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_FLAME_2">TOPGUN_IMG_PATH"gx_topgun_flame_2"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_FLAME_3">TOPGUN_IMG_PATH"gx_topgun_flame_3"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ROLE">TOPGUN_IMG_PATH"gx_topgun_role"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ROLE_BULLET">TOPGUN_IMG_PATH"gx_topgun_role_bullet"GX_IMG_TYPE</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_TOPGUN_LEVEL_CLEAR_LANGUAGE0">TOPGUN_IMG_PATH"gx_topgun_level_clear"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENERGY_LANGUAGE0">TOPGUN_IMG_PATH"gx_topgun_energy"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_SCORE_LANGUAGE0">TOPGUN_IMG_PATH"gx_topgun_score"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_LEVEL_CLEAR_LANGUAGE1">TOPGUN_IMG_PATH"multi_lan\\\\gx_topgun_level_clear_C"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENERGY_LANGUAGE1">TOPGUN_IMG_PATH"multi_lan\\\\gx_topgun_energy_C"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_SCORE_LANGUAGE1">TOPGUN_IMG_PATH"multi_lan\\\\gx_topgun_score_C"GX_IMG_TYPE</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_TOPGUN_LEVEL_CLEAR">TOPGUN_IMG_PATH"gx_topgun_level_clear"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_ENERGY">TOPGUN_IMG_PATH"gx_topgun_energy"GX_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GX_TOPGUN_SCORE">TOPGUN_IMG_PATH"gx_topgun_score"GX_IMG_TYPE</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* TopGun NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_TOPGUN_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_GAME_TOPGUN__

#ifdef __MMI_MOTION_APP__

<INCLUDE file="mmi_rp_app_mainmenu_def.h,GlobalResDef.h"/>

extern void mmi_motion_dice_highlight_start(void);
extern void mmi_motion_dice_highlight_game_setting(void);
extern void mmi_motion_dice_highlight_event_setting(void);
extern void mmi_motion_dice_highlight_help(void);
extern void mmi_motion_dice_highlight_event_add(void);
extern void mmi_motion_dice_highlight_event_remove(void);
extern void mmi_motion_dice_highlight_event_remove_all(void);
extern void mmi_motion_dice_highlight_event_edit(void);
extern void mmi_motion_dice_highlight_event_view_image(void);
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
extern void mmi_motion_dice_highlight_event_play_video(void);
#endif
extern void mmi_motion_dice_highlight_event_file_select(void);

#ifdef __MMI_MOTIONGAME_DICE__
#if defined(__MMI_MAINLCD_176X220__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_240x320\\\\"
#elif defined(__MMI_MAINLCD_320X240__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_320x240\\\\"
#elif defined(__MMI_MAINLCD_240X400__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_240x400\\\\"
#elif defined(__MMI_MAINLCD_320X480__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_320x480\\\\"
#endif

    <SCREEN id="SCR_ID_MOTION_DICE_APP"/>
    <SCREEN id="SCR_ID_MOTION_DICE_PLAY"/>
    <SCREEN id="SCR_ID_MOTION_DICE_SHOW_EVENT"/>
    <SCREEN id="SCR_ID_MOTION_DICE_GAME_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DICE_HELP"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_OPTION"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_EDIT"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_TEXT_EDITOR"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_TEXT_EDITOR_OPTION"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_FILE_SELECT_OPTION"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_FILE_VIEW_IMAGE"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_FILE_PLAY_VIDEO"/>
    <SCREEN id="NUM_OF_MOTION_DICE_SCR_ID"/>
    
    <STRING id="STR_ID_MOTION_DICE_APP"/>
    <STRING id="STR_ID_MOTION_DICE_GAME_SETTING"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_SETTING"/>
    <STRING id="STR_ID_MOTION_DICE_DICE_COUNT"/>
    <STRING id="STR_ID_MOTION_DICE_SHOW_EVENT"/>
    <STRING id="STR_ID_MOTION_DICE_SOUND_SWITCH"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_ADD"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_REMOVE"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_EDIT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_EDIT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_MATCH_NUM"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_TEXT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_DEFAULT_TEXT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_EFFECT_FILE"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_FILE_SELECT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_EDITOR_TITLE"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE"/>
    <STRING id="STR_ID_MOTION_DICE_REMOVE_CONFIRM"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_REMOVED"/>
    <STRING id="STR_ID_MOTION_DICE_NUMBER_REGION"/>
    <STRING id="STR_ID_MOTION_DICE_DUP_NUMBER"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_FULL"/>
    <STRING id="STR_ID_MOTION_DICE_1"/>
    <STRING id="STR_ID_MOTION_DICE_2"/>
    <STRING id="STR_ID_MOTION_DICE_3"/>
    <STRING id="STR_ID_MOTION_DICE_4"/>
    <STRING id="STR_ID_MOTION_DICE_5"/>
    <STRING id="STR_ID_MOTION_DICE_INVALID_FILE"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_REMOVE_ALL"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_ALL_REMOVED"/>
    <STRING id="STR_ID_MOTION_DICE_REMOVE_ALL_CONFIRM"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_START"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_CONTENT_1"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_CONTENT_2"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_CONTENT_3"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_END"/>
    
    <IMAGE id="IMG_ID_MOTION_DICE_APP">MMI_MOTIONDICE_IMAGE_PATH"dice_app"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_1">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_2">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_3">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_4">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_5">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_6">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_7">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_8">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_9">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_9"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_10">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_10"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_11">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_11"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_12">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_12"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_13">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_13"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_14">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_14"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_15">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_15"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_16">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_16"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_17">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_17"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_18">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_18"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_19">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_19"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_20">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_20"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_21">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_21"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_22">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_22"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_23">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_23"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_24">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_24"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_25">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_25"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_26">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_26"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_27">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_27"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_28">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_28"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_29">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_29"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ICON_30">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_30"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_1">MMI_MOTIONDICE_IMAGE_PATH"dice_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_2">MMI_MOTIONDICE_IMAGE_PATH"dice_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_3">MMI_MOTIONDICE_IMAGE_PATH"dice_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_4">MMI_MOTIONDICE_IMAGE_PATH"dice_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_5">MMI_MOTIONDICE_IMAGE_PATH"dice_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_6">MMI_MOTIONDICE_IMAGE_PATH"dice_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_1">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_01"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_2">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_02"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_3">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_03"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_4">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_04"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_5">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_05"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_6">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_06"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_7">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_07"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_8">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_08"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_9">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_09"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_10">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_10"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_11">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_11"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_ROLL_12">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_12"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_1">MMI_MOTIONDICE_IMAGE_PATH"dice_event_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_2">MMI_MOTIONDICE_IMAGE_PATH"dice_event_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_3">MMI_MOTIONDICE_IMAGE_PATH"dice_event_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_4">MMI_MOTIONDICE_IMAGE_PATH"dice_event_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_5">MMI_MOTIONDICE_IMAGE_PATH"dice_event_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_6">MMI_MOTIONDICE_IMAGE_PATH"dice_event_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_PLAY_BG">MMI_MOTIONDICE_IMAGE_PATH"dice_bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_BG">MMI_MOTIONDICE_IMAGE_PATH"dice_event_bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_DEFAULT_IMG">MMI_MOTIONDICE_IMAGE_PATH"dice_event_def"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_DUMMY">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_dummy"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_AUD">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_aud"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_VDO">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_vdo"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_IMG">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_img"GX_OLD_IMG_TYPE</IMAGE>
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_BACK">MMI_MOTIONDICE_IMAGE_PATH"dice_back"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_BACK_DOWN">MMI_MOTIONDICE_IMAGE_PATH"dice_back_down"GX_OLD_IMG_TYPE</IMAGE>
#endif
#ifdef __MMI_BACKGROUND_CALL__
    <IMAGE id="IMG_ID_MOTION_DICE_BG_CALL_VIDEO">MMI_MOTIONDICE_IMAGE_PATH"dice_event_Video"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif

    <MENU id="MENU_ID_MOTION_DICE_APP" type="OPTION" str="STR_ID_MOTION_DICE_APP">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_START</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_GAME_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_HELP</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_START" str="STR_GLOBAL_START"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_GAME_SETTING" str="STR_ID_MOTION_DICE_GAME_SETTING"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_SETTING" str="STR_ID_MOTION_DICE_EVENT_SETTING"/>
    <MENUITEM id="MENU_ID_MOTION_DICE_HELP" str="STR_GLOBAL_HELP"/>

	<MENU id="MENU_ID_MOTION_DICE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_REMOVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_REMOVE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_EDIT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_OPTION_ADD" str="STR_ID_MOTION_DICE_OPTION_ADD"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_OPTION_REMOVE" str="STR_ID_MOTION_DICE_OPTION_REMOVE"/>
    <MENUITEM id="MENU_ID_MOTION_DICE_OPTION_REMOVE_ALL" str="STR_ID_MOTION_DICE_OPTION_REMOVE_ALL"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_OPTION_EDIT" str="STR_ID_MOTION_DICE_EVENT_EDIT"/>

	<MENU id="MENU_ID_MOTION_DICE_EDT_OPT_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EDT_OPT_DONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EDT_OPT_CANCEL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EDT_OPT_INPUT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EDT_OPT_DONE" str="STR_GLOBAL_DONE"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_EDT_OPT_CANCEL" str="STR_GLOBAL_CANCEL"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_EDT_OPT_INPUT" str="STR_GLOBAL_INPUT_METHOD"/>

	<MENU id="MENU_ID_MOTION_DICE_EVENT_FILE_SELECT_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS" /* str="STR_ID_MOTION_DICE_EVENT_EFFECT_FILE" */>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_FILE_SELECT" str="STR_ID_MOTION_DICE_EVENT_FILE_SELECT" highlight="mmi_motion_dice_highlight_event_file_select"/>

	<MENU id="MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE" str="STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE" highlight="mmi_motion_dice_highlight_event_view_image"/>

	<MENU id="MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO" str="STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO" highlight="mmi_motion_dice_highlight_event_play_video"/>
#endif

	<MENU id="MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO_ROOT" type="OPTION" str="STR_ID_MOTION_DICE_EVENT_EFFECT_FILE">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO" str="STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO"/>

    /* Motion Dice NVRAM */
    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_DICE_COUNT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_EVENT_ON" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_SOUND_ON" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_MOTIONGAME_DICE__


#ifdef __MMI_MOTIONGAME_DJ__
#include "MotionDJGprots.h"
#if defined(__MMI_MAINLCD_176X220__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_176x220\\\\"
#elif defined(__MMI_MAINLCD_240X320__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_240x320\\\\"
#elif defined(__MMI_MAINLCD_320X240__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_320x240\\\\"
#elif defined(__MMI_MAINLCD_240X400__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_240x400\\\\"
#elif defined(__MMI_MAINLCD_320X480__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_320x480\\\\"
#endif
#if defined(__MMI_MAINLCD_320X480__)
    #define MOTION_DJ_IMG_TYPE ".png"
#else
    #define MOTION_DJ_IMG_TYPE ".bmp"
#endif
    <SCREEN id="SCR_ID_MOTION_DJ_APP"/>
    <SCREEN id="SCR_ID_MOTION_DJ_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DJ_EDIT"/>
    <SCREEN id="SCR_ID_MOTION_DJ_PLAY"/>
    <SCREEN id="SCR_ID_MOTION_DJ_DUMMY"/>
    <SCREEN id="SCR_ID_MOTION_DJ_VOL_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DJ_HELP"/>
    <SCREEN id="NUM_OF_MOTION_DJ_SCR_ID"/>
    
    <STRING id="STR_ID_MOTION_DJ_APP"/>
    <STRING id="STR_ID_MOTION_DJ_START"/>
    <STRING id="STR_ID_MOTION_DJ_SETTING"/>
    <STRING id="STR_ID_MOTION_DJ_VOL_SETTING"/>
    <STRING id="STR_ID_MOTION_DJ_HELP"/>
    <STRING id="STR_ID_MOTION_DJ_HELP_CONTENT"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_TITLE_2"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_TITLE_3"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_TITLE_1"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_TITLE_2"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_TITLE_3"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_0"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_1"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_2"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_3"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_4"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_5"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_6"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_7"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_8"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_9"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_0"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_1"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_2"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_3"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_4"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_5"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_6"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_7"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_8"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_9"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_0"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_1"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_2"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_3"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_4"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_5"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_6"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_7"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_8"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_9"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_STAR"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_POUND"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_AUDIO"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_KEY"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER_SHAKE"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER_KEY_PRESS"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_PRESS_SAME_KEY"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY"/>

    <IMAGE id="IMG_ID_MOTION_DJ_APP">MOTION_DJ_IMG_PATH"dj_app"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_NONE">MOTION_DJ_IMG_PATH"dj_icon_none"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_AUTO">MOTION_DJ_IMG_PATH"dj_icon_auto"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_SHAKE">MOTION_DJ_IMG_PATH"dj_icon_shake"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_PRESS">MOTION_DJ_IMG_PATH"dj_icon_press"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_DUMMY">MOTION_DJ_IMG_PATH"dj_key_dummy"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_0">MOTION_DJ_IMG_PATH"dj_key_0"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_1">MOTION_DJ_IMG_PATH"dj_key_1"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_2">MOTION_DJ_IMG_PATH"dj_key_2"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_3">MOTION_DJ_IMG_PATH"dj_key_3"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_4">MOTION_DJ_IMG_PATH"dj_key_4"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_5">MOTION_DJ_IMG_PATH"dj_key_5"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_6">MOTION_DJ_IMG_PATH"dj_key_6"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_7">MOTION_DJ_IMG_PATH"dj_key_7"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_8">MOTION_DJ_IMG_PATH"dj_key_8"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_9">MOTION_DJ_IMG_PATH"dj_key_9"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_STAR">MOTION_DJ_IMG_PATH"dj_key_star"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_POUND">MOTION_DJ_IMG_PATH"dj_key_pound"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_BG">MOTION_DJ_IMG_PATH"dj_play_bg"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_NONE">MOTION_DJ_IMG_PATH"dj_play_none"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_AUTO">MOTION_DJ_IMG_PATH"dj_play_auto"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_SHAKE">MOTION_DJ_IMG_PATH"dj_play_shake"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_PRESS">MOTION_DJ_IMG_PATH"dj_play_press"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_NONE_SEL">MOTION_DJ_IMG_PATH"dj_play_auto_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_AUTO_SEL">MOTION_DJ_IMG_PATH"dj_play_auto_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_SHAKE_SEL">MOTION_DJ_IMG_PATH"dj_play_shake_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_PRESS_SEL">MOTION_DJ_IMG_PATH"dj_play_press_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_0">MOTION_DJ_IMG_PATH"dj_play_key_0"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_1">MOTION_DJ_IMG_PATH"dj_play_key_1"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_2">MOTION_DJ_IMG_PATH"dj_play_key_2"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_3">MOTION_DJ_IMG_PATH"dj_play_key_3"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_4">MOTION_DJ_IMG_PATH"dj_play_key_4"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_5">MOTION_DJ_IMG_PATH"dj_play_key_5"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_6">MOTION_DJ_IMG_PATH"dj_play_key_6"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_7">MOTION_DJ_IMG_PATH"dj_play_key_7"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_8">MOTION_DJ_IMG_PATH"dj_play_key_8"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_9">MOTION_DJ_IMG_PATH"dj_play_key_9"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_STAR">MOTION_DJ_IMG_PATH"dj_play_key_star"MOTION_DJ_IMG_TYPE</IMAGE>    
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_POUND">MOTION_DJ_IMG_PATH"dj_play_key_pound"MOTION_DJ_IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_0_SEL">MOTION_DJ_IMG_PATH"dj_play_key_0_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_1_SEL">MOTION_DJ_IMG_PATH"dj_play_key_1_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_2_SEL">MOTION_DJ_IMG_PATH"dj_play_key_2_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_3_SEL">MOTION_DJ_IMG_PATH"dj_play_key_3_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_4_SEL">MOTION_DJ_IMG_PATH"dj_play_key_4_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_5_SEL">MOTION_DJ_IMG_PATH"dj_play_key_5_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_6_SEL">MOTION_DJ_IMG_PATH"dj_play_key_6_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_7_SEL">MOTION_DJ_IMG_PATH"dj_play_key_7_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_8_SEL">MOTION_DJ_IMG_PATH"dj_play_key_8_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_9_SEL">MOTION_DJ_IMG_PATH"dj_play_key_9_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_STAR_SEL">MOTION_DJ_IMG_PATH"dj_play_key_star_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_POUND_SEL">MOTION_DJ_IMG_PATH"dj_play_key_pound_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_BACK">MOTION_DJ_IMG_PATH"Dj_back"GX_ANIMATION_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_BACK_DOWN">MOTION_DJ_IMG_PATH"Dj_back_down"GX_ANIMATION_IMG_TYPE</IMAGE>
#endif

    <MENU id="MENU_ID_MOTION_DJ_APP" type="OPTION" str="STR_ID_MOTION_DJ_APP">
        <MENUITEM_ID>MENU_ID_MOTION_DJ_START</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DJ_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DJ_VOL_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DJ_HELP</MENUITEM_ID></MENU>
    <MENUITEM id="MENU_ID_MOTION_DJ_START" str="STR_ID_MOTION_DJ_START" highlight="mmi_motion_dj_highlight_start"/>
    <MENUITEM id="MENU_ID_MOTION_DJ_SETTING" str="STR_ID_MOTION_DJ_SETTING" highlight="mmi_motion_dj_highlight_setting"/>
    <MENUITEM id="MENU_ID_MOTION_DJ_VOL_SETTING" str="STR_ID_MOTION_DJ_VOL_SETTING" highlight="mmi_motion_dj_highlight_vol_setting"/>
    <MENUITEM id="MENU_ID_MOTION_DJ_HELP" str="STR_GLOBAL_HELP" highlight="mmi_motion_dj_highlight_help"/>
    
    /* Motion DJ NVRAM */
    <CACHEDATA type="byte" id="NVRAM_MOTION_DJ_VOLUMN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif  //__MMI_MOTIONGAME_DJ__    
#endif  //__MMI_MOTION_APP__

/******************************************************* Motion Game End ****************************************************/


/******************************************************* Game Framework Start ****************************************************/
    <SCREEN id="SCR_ID_GAME"/>
    <SCREEN id="SCR_ID_GAME_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_APP"/>
    <SCREEN id="SCR_ID_3D_GAME_LIST"/>
    <SCREEN id="SCR_ID_3D_GAME"/>
    
    <SCREEN id="GFX_MENU_SCREEN"/>
    <SCREEN id="GFX_GAME_SCREEN"/>
    <SCREEN id="GFX_LEVEL_SCREEN"/>
    <SCREEN id="GFX_GRADE_SCREEN"/>
    <SCREEN id="GFX_HELP_SCREEN"/>
    <SCREEN id="GFX_GAMEOVER_SCREEN"/>
    
	<STRING id="STR_GAME_CAPTION"/>
	<STRING id="STR_GAME_LSK"/>
	<STRING id="STR_GAME_NEW"/>
	<STRING id="STR_GAME_LEVEL"/>
	<STRING id="STR_GAME_GRADE"/>
	<STRING id="STR_GAME_RESET_GRADE_CONFIRM"/>
	<STRING id="STR_GAME_HELP"/>
	<STRING id="STR_GAME_RESUME"/>
	<STRING id="STR_GAME_SCORE"/>
	<STRING id="STR_MENU3105_GAMES"/>
	<STRING id="STR_ID_GAME_SETTING"/>
    <IMAGE id="IMG_ID_GAME_SETTING">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_FGST"GX_OLD_IMG_TYPE</IMAGE>
	<STRING id="STR_ID_GAME_SETTING_AUD"/>
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
	<STRING id="STR_ID_GAME_SETTING_MULTICHANNEL_BACKGROUND_MUSIC"/>
	<STRING id="STR_ID_GAME_SETTING_MULTICHANNEL_SOUND_EFFECT"/>
#endif
	<STRING id="STR_ID_GAME_SETTING_VIB"/>
    <IMAGE id="IMG_ID_GAME_SETTING_AUD">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEAUD"GX_OLD_IMG_TYPE</IMAGE>
	#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
        <IMAGE id="IMG_ID_GAME_SETTING_BACK_AUD">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEBACKAUD"GX_OLD_IMG_TYPE</IMAGE>
#endif
    <IMAGE id="IMG_ID_GAME_SETTING_VIB">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEVIB"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GAME_SETTING_VOL">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEVOLUME"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_MENU3105_GAMES">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_FGGAME"GX_OLD_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_GAME_SUBLCD_ICON">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\sb_game"GX_OLD_IMG_TYPE</IMAGE>

#if defined(__MMI_GAME_MENU__) || defined(__MMI_GAME__)
	////TODO
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU3105_GAMES, mmi_game_highlight_app);
#endif

    /* Game Framework NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GFX_AUDIO_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_AUDIO_VOLUMN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_VIBRATION_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_BACKGROUND_MUSIC_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_SOUND_EFFECT_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>
    
</APP>
#endif


