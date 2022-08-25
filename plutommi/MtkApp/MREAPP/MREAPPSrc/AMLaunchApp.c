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
 *   AMLaunchApp.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_APP_LAUNCH__
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "Gui.h"
#include "gui_data_types.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "FileMgrSrvGProt.h"
#include "mmi_trc_int.h"
#include "gdi_include.h"

#include "mmi_rp_app_am_def.h"
#include "AMGprot.h"
#include "AMConfig.h"
#include "AMUtil.h"
#include "AMMainScreen.h"
#include "MMI_mre_trc.h"
#include "MRESrvGProt.h"


#ifdef __MMI_MRE_APP_QQ2010__
extern const __align(4) U8 mre_app_qq2010_vxp[];
#endif

#ifdef __MMI_MRE_APP_QQBROWSER__
extern const __align(4) U8 mre_app_qqbrowser_vxp[];
#endif
#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
extern const __align(4) U8 mre_app_yahoo_messengerv1[];
#endif

//#ifdef __MMI_MRE_APP_FBLITE__
#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__)
extern const __align(4) U8 mre_app_facebook_lite[];
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
extern const __align(4) U8 mre_app_facebook_v2[];
extern const __align(4) U8 mre_app_facebook_v2_messenger[];
#endif

#ifdef __MMI_MRE_APP_TWITTER__
extern const __align(4) U8 mre_app_twitter[];
#endif 

#ifdef __MMI_MRE_APP_YOUTUBE__
extern const __align(4) U8 mre_app_YouTube[];
#endif 

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
extern const __align(4) U8 mre_app_yahoo_finance[];
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__
extern const __align(4) U8 mre_app_yahoo_weather[];
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
extern const __align(4) U8 mre_app_yahoo_news[];
#endif

#ifdef __MMI_MRE_APP_YAHOOCRICKET__
extern const __align(4) U8 mre_app_yahoo_cricket[];
#endif

#ifdef __MMI_MRE_APP_OPERA__
extern const __align(4) U8 mre_app_opera_vxp[];
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
extern const __align(4) U8 mre_app_opera_mini_v6_vxp[];
#endif

#ifdef __MMI_MRE_APP_RENREN__
extern const __align(4) U8 mre_app_renren_vxp[];
#endif

#ifdef __MMI_MRE_APP_KAIXIN__
extern const __align(4) U8 mre_app_kaixin_vxp[];
#endif

#ifdef __MMI_MRE_APP_YOUKU__
extern const __align(4) U8 mre_app_youku_vxp[];
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
extern const __align(4) U8 mre_app_FruitNinja_sc_vxp[];
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
extern const __align(4) U8 mre_app_FruitNinja_en_vxp[];
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
extern const __align(4) U8 mre_app_FishingFun_en_vxp[];
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
extern const __align(4) U8 mre_app_FishingFun_sc_vxp[];
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
extern const __align(4) U8 mre_app_AngryBird_sc_vxp[];
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
extern const __align(4) U8 mre_app_AngryBird_en_vxp[];
#endif


/* zhibo add start for 15 preload app*/
/***********************************************/
#ifdef __MMI_MRE_APP_CALCULATOR__
extern const __align(4) U8 mre_app_calculator_vxp[];
#endif

#ifdef __MMI_MRE_APP_CONVERTER__
extern const __align(4) U8 mre_app_converter[];
#endif

#ifdef __MMI_MRE_APP_HEALTH__
extern const __align(4) U8 mre_app_health[];
#endif

#ifdef __MMI_MRE_APP_STOPWATCH__
extern const __align(4) U8 mre_app_stopwatch[];
#endif

#ifdef __MMI_MRE_APP_ZAKAT__
extern const __align(4) U8 mre_app_zakat[];
#endif
/***********************************************/
#ifdef __MMI_MRE_APP_ZY_EBOOK__
extern const __align(4) U8 mre_app_zy_ebook[];
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_EN__
extern const __align(4) U8 mre_app_happy_war_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_CHS__
extern const __align(4) U8 mre_app_happy_war_chs_vxp[];
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_EN__
extern const __align(4) U8 mre_app_egypt_code_en_vxp[];
#endif


#ifdef __MMI_MRE_GAME_EGYPTCODE_CHS__
extern const __align(4) U8 mre_app_egypt_code_chs_vxp[];
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN__
extern const __align(4) U8 mre_app_king_combat_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_CHS__
extern const __align(4) U8 mre_app_king_combat_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_GOLDMINER_EN__
extern const __align(4) U8 mre_app_gold_miner_en_vxp[];
#endif


#ifdef __MMI_MRE_GAME_GOLDMINER_CHS__
extern const __align(4) U8 mre_app_gold_miner_chs_vxp[];
#endif

/***********************************************/
#ifdef __MMI_MRE_GAME_MOTO_EN__
extern const __align(4) U8 mre_app_moto_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_MOTO_CHS__
extern const __align(4) U8 mre_app_moto_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_GIRLSLOT_EN__
extern const __align(4) U8 mre_app_girl_slot_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_CHS__
extern const __align(4) U8 mre_app_girl_slot_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_PARKOUR_EN__
extern const __align(4) U8 mre_app_parkour_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_CHS__
extern const __align(4) U8 mre_app_parkour_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_TEARDRESS_EN__
extern const __align(4) U8 mre_app_tear_dress_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_CHS__
extern const __align(4) U8 mre_app_tear_dress_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_HAPPYEGG_EN__
extern const __align(4) U8 mre_app_happy_egg_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_CHS__
extern const __align(4) U8 mre_app_happy_egg_en_vxp[];
#endif



/*<---------------------------- ADD 3GT Game START ---------------------------->*/

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
extern const __align(4) U8 mre_app_3GT_Game_Bowling_ENG_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
extern const __align(4) U8 mre_app_3GT_Game_Bowling_CHS_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
extern const __align(4) U8 mre_app_3GT_Game_Bowling_CHT_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
extern const __align(4) U8 mre_app_3GT_Game_DanDelion_ALL_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
extern const __align(4) U8 mre_app_3gt_rash_motor_chs_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
extern const __align(4) U8 mre_app_3gt_rash_motor_cht_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
extern const __align(4) U8 mre_app_3gt_rash_motor_eng_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
extern const __align(4) U8 mre_app_3gt_balance_ball_chs_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
extern const __align(4) U8 mre_app_3gt_balance_ball_cht_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
extern const __align(4) U8 mre_app_3gt_balance_ball_eng_vxp[];
#endif

/*<---------------------------- ADD 3GT Game END ------------------------------>*/

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__)
	extern const __align(4) U8 mre_app_gl_asphalt6[];
	extern const __align(4) U8 mre_app_gl_brainchallenge[];
	extern const __align(4) U8 mre_app_gl_blockbreaker[];
	extern const __align(4) U8 mre_app_gl_assassincreed[];
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__)
	extern const __align(4) U8 mre_app_gl_asphalt6[];
	extern const __align(4) U8 mre_app_gl_brainchallenge[];
	extern const __align(4) U8 mre_app_gl_blockbreaker[];
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__)
	extern const __align(4) U8 mre_app_gl_asphalt6[];
	extern const __align(4) U8 mre_app_gl_blockbreaker[];
	extern const __align(4) U8 mre_app_gl_assassincreed[];
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__)
	extern const __align(4) U8 mre_app_gl_asphalt6[];
	extern const __align(4) U8 mre_app_gl_brainchallenge[];
	extern const __align(4) U8 mre_app_gl_assassincreed[];
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	extern const __align(4) U8 mre_app_gl_glive[];
	extern const __align(4) U8 mre_app_gl_mortalcombat2[];
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)
	extern const __align(4) U8 mre_app_gl_asphalt6[];
	extern const __align(4) U8 mre_app_gl_glive[];
#endif

#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
extern const __align(4) U8 mre_app_sina_weibo_vxp[];
#endif



/* main menu shortcut app list */
mmi_am_launch_app_info_struct g_am_la_info_list[] = 
{
    {APPID_NONE, 0, 0, NULL},

#ifdef __MMI_MRE_APP_QQ2010__
    {APPID_QQ_2010, IMG_ID_AM_APP_QQ, STR_ID_AM_APP_NAME_QQ_2010, mre_app_qq2010_vxp},
#endif

#ifdef __MMI_MRE_APP_QQBROWSER__
    {APPID_QQBROWSER, IMG_ID_AM_APP_QQBROWSER, STR_ID_AM_APP_NAME_QQBROWSER, mre_app_qqbrowser_vxp},
#endif
#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
    {APPID_YAHOOMV1, IMG_ID_AM_APP_YAHOO, STR_ID_AM_APP_NAME_YAHOO, mre_app_yahoo_messengerv1},
#endif

//#ifdef __MMI_MRE_APP_FBLITE__
#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__)
    {APPID_FBLITE, IMG_ID_AM_APP_FBLITE, STR_ID_AM_APP_NAME_FBLITE, mre_app_facebook_lite},
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
    {APPID_FACEBOOK_V2, IMG_ID_AM_APP_FBLITE, STR_ID_AM_APP_NAME_FBLITE, mre_app_facebook_v2},
	{APPID_FACEBOOK_V2_MESSENGER, IMG_ID_AM_APP_FBLITE, STR_ID_AM_APP_NAME_FBV2_MESSENGER, mre_app_facebook_v2_messenger},
#endif

#ifdef __MMI_MRE_APP_TWITTER__
    {APPID_TWITTER, IMG_ID_AM_APP_TWITTER, STR_ID_AM_APP_NAME_TWITTER, mre_app_twitter},
#endif

#ifdef __MMI_MRE_APP_YOUTUBE__
    {APPID_YOUTUBE, IMG_ID_AM_APP_YOUTUBE, STR_ID_AM_APP_NAME_YOUTUBE, mre_app_YouTube},
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
    {APPID_YAHOOFINANCE, IMG_ID_AM_APP_YAHOOFINANCE, STR_ID_AM_APP_NAME_YAHOOFINANCE, mre_app_yahoo_finance},
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__
    {APPID_YAHOOWEATHER, IMG_ID_AM_APP_YAHOOWEATHER, STR_ID_AM_APP_NAME_YAHOOWEATHER, mre_app_yahoo_weather},
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
    {APPID_YAHOONEWS, IMG_ID_AM_APP_YAHOONEWS, STR_ID_AM_APP_NAME_YAHOONEWS, mre_app_yahoo_news},
#endif

#ifdef __MMI_MRE_APP_YAHOOCRICKET__
    {APPID_YAHOOCRICKET, IMG_ID_AM_APP_YAHOOCRICKET, STR_ID_AM_APP_NAME_YAHOOCRICKET, mre_app_yahoo_cricket},
#endif

#ifdef __MMI_MRE_APP_OPERA__
    {APPID_OPERA, IMG_ID_AM_APP_OPERA, STR_ID_AM_APP_NAME_OPERA, mre_app_opera_vxp},
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
    {APPID_OPERA_MINI_V6, IMG_ID_AM_APP_OPERA_MINI_V6, STR_ID_AM_APP_NAME_OPERA_MINI_V6, mre_app_opera_mini_v6_vxp},
#endif

#ifdef __MMI_MRE_APP_RENREN__
    {APPID_RENREN, IMG_ID_AM_APP_RENREN, STR_ID_AM_APP_NAME_RENREN, mre_app_renren_vxp},
#endif

#ifdef __MMI_MRE_APP_KAIXIN__
    {APPID_KAIXIN, IMG_ID_AM_APP_KAIXIN, STR_ID_AM_APP_NAME_KAIXIN, mre_app_kaixin_vxp},
#endif

#ifdef __MMI_MRE_APP_YOUKU__
    {APPID_YOUKU, IMG_ID_AM_APP_YOUKU, STR_ID_AM_APP_NAME_YOUKU, mre_app_youku_vxp},
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
    {APPID_FRUITNINJA_SC, IMG_ID_AM_APP_FRUITNINJA_SC, STR_ID_AM_APP_NAME_FRUITNINJA_SC, mre_app_FruitNinja_sc_vxp},
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
    {APPID_FRUITNINJA_EN, IMG_ID_AM_APP_FRUITNINJA_EN, STR_ID_AM_APP_NAME_FRUITNINJA_EN, mre_app_FruitNinja_en_vxp},
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
    {APPID_FISHINGFUN_SC, IMG_ID_AM_APP_FISHINGFUN_SC, STR_ID_AM_APP_NAME_FISHINGFUN_SC, mre_app_FishingFun_sc_vxp},
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
    {APPID_FISHINGFUN_EN, IMG_ID_AM_APP_FISHINGFUN_EN, STR_ID_AM_APP_NAME_FISHINGFUN_EN, mre_app_FishingFun_en_vxp},
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
    {APPID_ANGRYBIRD_SC, IMG_ID_AM_APP_ANGRYBIRD_SC, STR_ID_AM_APP_NAME_ANGRYBIRD_SC, mre_app_AngryBird_sc_vxp},
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
    {APPID_ANGRYBIRD_EN, IMG_ID_AM_APP_ANGRYBIRD_EN, STR_ID_AM_APP_NAME_ANGRYBIRD_EN, mre_app_AngryBird_en_vxp},
#endif


/* zhibo add start for 15 preload app*/
/***********************************************/
#ifdef __MMI_MRE_APP_CALCULATOR__
    {APPID_CALCULATOR, IMG_ID_AM_APP_CALCULATOR, STR_ID_AM_APP_NAME_CALCULATOR, mre_app_calculator_vxp},
#endif

#ifdef __MMI_MRE_APP_CONVERTER__
    {APPID_CONVERTER, IMG_ID_AM_APP_CONVERTER, STR_ID_AM_APP_NAME_CONVERTER, mre_app_converter},
#endif

#ifdef __MMI_MRE_APP_HEALTH__
    {APPID_HEALTH, IMG_ID_AM_APP_HEALTH, STR_ID_AM_APP_NAME_HEALTH, mre_app_health},
#endif

#ifdef __MMI_MRE_APP_STOPWATCH__
    {APPID_STOPWATCH, IMG_ID_AM_APP_STOPWATCH, STR_ID_AM_APP_NAME_STOPWATCH, mre_app_stopwatch},
#endif

#ifdef __MMI_MRE_APP_ZAKAT__
    {APPID_ZAKAT, IMG_ID_AM_APP_ZAKAT, STR_ID_AM_APP_NAME_ZAKAT, mre_app_zakat},
#endif
/***********************************************/
#ifdef __MMI_MRE_APP_ZY_EBOOK__
    {APPID_ZY_EBOOK, IMG_ID_AM_APP_EBOOK, STR_ID_AM_APP_NAME_ZY_EBOOK, mre_app_zy_ebook},
#endif
	
#ifdef __MMI_MRE_GAME_HAPPYWAR_EN__
    {APPID_HAPPYWAR_EN, IMG_ID_AM_APP_HAPPYWAR, STR_ID_AM_APP_NAME_HAPPYWAR, mre_app_happy_war_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_CHS__
    {APPID_HAPPYWAR_CHS, IMG_ID_AM_APP_HAPPYWAR, STR_ID_AM_APP_NAME_HAPPYWAR, mre_app_happy_war_chs_vxp},
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_EN__
    {APPID_EGYPTCODE_EN, IMG_ID_AM_APP_EGYPTCODE, STR_ID_AM_APP_NAME_EGYPTCODE, mre_app_egypt_code_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_CHS__
    {APPID_EGYPTCODE_CHS, IMG_ID_AM_APP_EGYPTCODE, STR_ID_AM_APP_NAME_EGYPTCODE, mre_app_egypt_code_chs_vxp},
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN__
    {APPID_KINGCOMBAT_EN, IMG_ID_AM_APP_KINGCOMBAT, STR_ID_AM_APP_NAME_KINGCOMBAT, mre_app_king_combat_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_CHS__
    {APPID_KINGCOMBAT_CHS, IMG_ID_AM_APP_KINGCOMBAT, STR_ID_AM_APP_NAME_KINGCOMBAT, mre_app_king_combat_chs_vxp},
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN__
    {APPID_GOLDMINER_EN, IMG_ID_AM_APP_GOLDMINER, STR_ID_AM_APP_NAME_GOLDMINER, mre_app_gold_miner_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_CHS__
    {APPID_GOLDMINER_CHS, IMG_ID_AM_APP_GOLDMINER, STR_ID_AM_APP_NAME_GOLDMINER, mre_app_gold_miner_chs_vxp},
#endif

/***********************************************/
#ifdef __MMI_MRE_GAME_MOTO_EN__
    {APPID_MOTO_EN, IMG_ID_AM_APP_MOTO, STR_ID_AM_APP_NAME_MOTO, mre_app_moto_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_MOTO_CHS__
    {APPID_MOTO_CHS, IMG_ID_AM_APP_MOTO, STR_ID_AM_APP_NAME_MOTO, mre_app_moto_chs_vxp},
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_EN__
    {APPID_GIRLSLOT_EN, IMG_ID_AM_APP_GIRLSLOT, STR_ID_AM_APP_NAME_GIRLSLOT, mre_app_girl_slot_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_CHS__
    {APPID_GIRLSLOT_CHS, IMG_ID_AM_APP_GIRLSLOT, STR_ID_AM_APP_NAME_GIRLSLOT, mre_app_girl_slot_chs_vxp},
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_EN__
    {APPID_PARKOUR_EN, IMG_ID_AM_APP_PARKOUR, STR_ID_AM_APP_NAME_PARKOUR, mre_app_parkour_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_CHS__
    {APPID_PARKOUR_CHS, IMG_ID_AM_APP_PARKOUR, STR_ID_AM_APP_NAME_PARKOUR, mre_app_parkour_chs_vxp},
#endif


#ifdef __MMI_MRE_GAME_TEARDRESS_EN__
    {APPID_TEARDRESS_EN, IMG_ID_AM_APP_TEARDRESS, STR_ID_AM_APP_NAME_TEARDRESS, mre_app_tear_dress_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_CHS__
    {APPID_TEARDRESS_CHS, IMG_ID_AM_APP_TEARDRESS, STR_ID_AM_APP_NAME_TEARDRESS, mre_app_tear_dress_chs_vxp},
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_EN__
    {APPID_HAPPYEGG_EN, IMG_ID_AM_APP_HAPPYEGG, STR_ID_AM_APP_NAME_HAPPYEGG, mre_app_happy_egg_en_vxp},
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_CHS__
    {APPID_HAPPYEGG_CHS, IMG_ID_AM_APP_HAPPYEGG, STR_ID_AM_APP_NAME_HAPPYEGG, mre_app_happy_egg_chs_vxp},
#endif



/***********************************************/
/* zhibo add end for 15 preload app*/
/*<---------------------------- ADD 3GT Game START ---------------------------->*/

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
    {APPID_BOWLING_ENG, IMG_ID_AM_APP_BOWLING_ENG, STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_ENG, mre_app_3GT_Game_Bowling_ENG_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
    {APPID_BOWLING_CHS, IMG_ID_AM_APP_BOWLING_CHS, STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHS, mre_app_3GT_Game_Bowling_CHS_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
    {APPID_BOWLING_CHT, IMG_ID_AM_APP_BOWLING_CHT, STR_ID_AM_APP_NAME_3GT_GAME_BOWLING_CHT, mre_app_3GT_Game_Bowling_CHT_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
    {APPID_DANDELION,   IMG_ID_AM_APP_DANDELION,   STR_ID_AM_APP_NAME_3GT_GAME_DANDELION, mre_app_3GT_Game_DanDelion_ALL_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
    {APPID_3GT_RASH_MOTOR_CHS, IMG_ID_AM_APP_3GT_RASH_MOTOR, STR_ID_AM_APP_NAME_3GT_RASH_MOTOR, mre_app_3gt_rash_motor_chs_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
    {APPID_3GT_RASH_MOTOR_CHT, IMG_ID_AM_APP_3GT_RASH_MOTOR, STR_ID_AM_APP_NAME_3GT_RASH_MOTOR, mre_app_3gt_rash_motor_cht_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
    {APPID_3GT_RASH_MOTOR_ENG, IMG_ID_AM_APP_3GT_RASH_MOTOR, STR_ID_AM_APP_NAME_3GT_RASH_MOTOR, mre_app_3gt_rash_motor_eng_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
    {APPID_3GT_BALANCE_BALL_CHS, IMG_ID_AM_APP_3GT_BALANCE_BALL, STR_ID_AM_APP_NAME_3GT_BALANCE_BALL, mre_app_3gt_balance_ball_chs_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
    {APPID_3GT_BALANCE_BALL_CHT, IMG_ID_AM_APP_3GT_BALANCE_BALL, STR_ID_AM_APP_NAME_3GT_BALANCE_BALL, mre_app_3gt_balance_ball_cht_vxp},
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
    {APPID_3GT_BALANCE_BALL_ENG, IMG_ID_AM_APP_3GT_BALANCE_BALL, STR_ID_AM_APP_NAME_3GT_BALANCE_BALL, mre_app_3gt_balance_ball_eng_vxp},
#endif


/*<---------------------------- ADD 3GT Game END ------------------------------>*/
#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	{APPID_GAMELOFT_GLIVE, IMG_ID_AM_APP_GAMELOFT_GLIVE, STR_ID_AM_APP_NAME_GAMELOFT_GLIVE, mre_app_gl_glive},
	{APPID_GAMELOFT_MC2, IMG_ID_AM_APP_GAMELOFT_MC2, STR_ID_AM_APP_NAME_GAMELOFT_MC2, mre_app_gl_mortalcombat2},
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)
	{APPID_GAMELOFT_ASPHALT6, IMG_ID_AM_APP_GAMELOFT_ASPHALT6, STR_ID_AM_APP_NAME_GAMELOFT_ASPHALT6, mre_app_gl_asphalt6},
	{APPID_GAMELOFT_GLIVE, IMG_ID_AM_APP_GAMELOFT_GLIVE, STR_ID_AM_APP_NAME_GAMELOFT_GLIVE, mre_app_gl_glive},
#endif

#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
    {APPID_SINA_WEIBO, IMG_ID_AM_APP_SINA_WEIBO, STR_ID_AM_APP_NAME_SINA_WEIBO, mre_app_sina_weibo_vxp},
#endif
};

/*add a function to konw the array's size*/
U32 mmi_la_get_build_in_app_array_size()
{
	 return sizeof(g_am_la_info_list);
}
/*end*/

#ifdef __MMI_MRE_APP_QQ2010__
static void mmi_am_la_launch_QQ_2010(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_QQ_2010);
}


void mmi_am_la_highlight_QQ_2010(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_QQ_2010, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_QQ_2010, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_APP_QQBROWSER__
static void mmi_am_la_launch_QQBrowser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_QQBROWSER);
}


void mmi_am_la_highlight_QQBrowser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_QQBrowser, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_QQBrowser, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_QQBROWSER__ */ 


#if (defined (__MMI_MRE_APP_YAHOOMV1__) || defined(__MMI_MRE_APP_YAHOOMV2__))
 void mmi_am_la_launch_Yahoo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YAHOOMV1);
}


void mmi_am_la_highlight_Yahoo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_Yahoo, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_Yahoo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

//#ifdef __MMI_MRE_APP_FBLITE__
#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__)
static void mmi_am_la_launch_fblite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_FBLITE);
}


void mmi_am_la_highlight_fblite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_fblite, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_fblite, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#if defined(__MMI_MRE_APP_FACEBOOK_V2__) || defined(__MMI_MRE_APP_FACEBOOK_V2_STANDARD__)
static void mmi_am_la_launch_facebook_v2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_FACEBOOK_V2);
}
static void mmi_am_la_launch_facebook_v2_messenger(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_FACEBOOK_V2_MESSENGER);
}

void mmi_am_la_highlight_facebook_v2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_facebook_v2, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_facebook_v2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
void mmi_am_la_highlight_facebook_v2_messenger(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_facebook_v2_messenger, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_facebook_v2_messenger, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_YOUTUBE__
static void mmi_am_la_launch_youtube(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YOUTUBE);
}


void mmi_am_la_highlight_YouTube(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_youtube, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_youtube, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif



#ifdef __MMI_MRE_APP_TWITTER__
static void mmi_am_la_launch_twitter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_TWITTER);
}


void mmi_am_la_highlight_twitter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_twitter, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_twitter, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
static void mmi_am_la_launch_yahoofinance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YAHOOFINANCE);
}


void mmi_am_la_highlight_yahoofinance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_yahoofinance, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_yahoofinance, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__
static void mmi_am_la_launch_yahooweather(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YAHOOWEATHER);
}


void mmi_am_la_highlight_yahooweather(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_yahooweather, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_yahooweather, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
static void mmi_am_la_launch_yahoonews(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YAHOONEWS);
}


void mmi_am_la_highlight_yahoonews(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_yahoonews, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_yahoonews, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}   
#endif

#ifdef __MMI_MRE_APP_YAHOOCRICKET__
static void mmi_am_la_launch_yahoocricket(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YAHOOCRICKET);
}


void mmi_am_la_highlight_yahoocricket(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_yahoocricket, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_yahoocricket, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}   
#endif


#ifdef __MMI_MRE_APP_OPERA__
void mmi_am_la_launch_opera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_OPERA);
}


void mmi_am_la_highlight_opera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_opera, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_opera, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
void mmi_am_la_launch_opera_mini_v6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_OPERA_MINI_V6);
}


void mmi_am_la_highlight_opera_min_v6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_opera_mini_v6, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_opera_mini_v6, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_RENREN__
static void mmi_am_la_launch_renren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_RENREN);
}

void mmi_am_la_highlight_renren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_renren, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_renren, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_RENREN__ */ 

#ifdef __MMI_MRE_APP_KAIXIN__
static void mmi_am_la_launch_kaixin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_KAIXIN);
}


void mmi_am_la_highlight_kaixin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_kaixin, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_kaixin, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_KAIXIN__ */ 

#ifdef __MMI_MRE_APP_YOUKU__
static void mmi_am_la_launch_youku(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_app_by_id(APPID_YOUKU);
}


void mmi_am_la_highlight_youku(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_youku, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_youku, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_YOUKU__ */ 

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
static void mmi_am_la_launch_fruitninja_sc(void)
{
    mmi_am_launch_app_by_id(APPID_FRUITNINJA_SC);
}


void mmi_am_la_highlight_fruitninja_sc(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_fruitninja_sc, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_fruitninja_sc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_FRUITNINJA_SC__ */ 

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
static void mmi_am_la_launch_fruitninja_en(void)
{
    mmi_am_launch_app_by_id(APPID_FRUITNINJA_EN);
}


void mmi_am_la_highlight_fruitninja_en(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_fruitninja_en, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_fruitninja_en, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_FRUITNINJA_EN__ */ 

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
static void mmi_am_la_launch_fishingfun_sc(void)
{

    mmi_am_launch_app_by_id(APPID_FISHINGFUN_SC);
}


void mmi_am_la_highlight_fishingfun_sc(void)
{

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_fishingfun_sc, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_fishingfun_sc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_FISHINGFUN_SC__ */ 

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
static void mmi_am_la_launch_fishingfun_en(void)
{
    mmi_am_launch_app_by_id(APPID_FISHINGFUN_EN);
}


void mmi_am_la_highlight_fishingfun_en(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_fishingfun_en, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_fishingfun_en, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_FISHINGFUN_EN__ */ 

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
static void mmi_am_la_launch_angrybird_sc(void)
{
    mmi_am_launch_app_by_id(APPID_ANGRYBIRD_SC);
}


void mmi_am_la_highlight_angrybird_sc(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_angrybird_sc, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_angrybird_sc, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_ANGRYBIRD_SC__ */ 

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
static void mmi_am_la_launch_angrybird_en(void)
{
    mmi_am_launch_app_by_id(APPID_ANGRYBIRD_EN);
}


void mmi_am_la_highlight_angrybird_en(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_angrybird_en, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_angrybird_en, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_MRE_APP_ANGRYBIRD_EN__ */


#ifdef __MMI_MRE_APP_CALCULATOR__
static void mmi_am_la_launch_CALCULATOR(void)
{
    mmi_am_launch_app_by_id(APPID_CALCULATOR);
}
void mmi_am_la_highlight_CALCULATOR(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_CALCULATOR, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_CALCULATOR, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_CONVERTER__
static void mmi_am_la_launch_CONVERTER(void)
{
    mmi_am_launch_app_by_id(APPID_CONVERTER);
}
void mmi_am_la_highlight_CONVERTER(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_CONVERTER, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_CONVERTER, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_APP_HEALTH__
static void mmi_am_la_launch_HEALTH(void)
{
    mmi_am_launch_app_by_id(APPID_HEALTH);
}
void mmi_am_la_highlight_HEALTH(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_HEALTH, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_HEALTH, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_APP_STOPWATCH__
static void mmi_am_la_launch_STOPWATCH(void)
{
    mmi_am_launch_app_by_id(APPID_STOPWATCH);
}
void mmi_am_la_highlight_STOPWATCH(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_STOPWATCH, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_STOPWATCH, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_APP_ZAKAT__
 static void mmi_am_la_launch_ZAKAT(void)
{
    mmi_am_launch_app_by_id(APPID_ZAKAT);
}
void mmi_am_la_highlight_ZAKAT(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_ZAKAT, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_ZAKAT, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif
/***********************************************/

#ifdef __MMI_MRE_APP_ZY_EBOOK__
static void mmi_am_la_launch_ZY_EBOOK(void)
{
    mmi_am_launch_app_by_id(APPID_ZY_EBOOK);
}
void mmi_am_la_highlight_ZY_EBOOK(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_ZY_EBOOK, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_ZY_EBOOK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_HAPPYWAR_EN__
static void mmi_am_la_launch_HAPPYWAR_EN(void)
{
    mmi_am_launch_app_by_id(APPID_HAPPYWAR_EN);
}
void mmi_am_la_highlight_HAPPYWAR_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_HAPPYWAR_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_HAPPYWAR_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_CHS__
static void mmi_am_la_launch_HAPPYWAR_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_HAPPYWAR_CHS);
}
void mmi_am_la_highlight_HAPPYWAR_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_HAPPYWAR_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_HAPPYWAR_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif



#ifdef __MMI_MRE_GAME_EGYPTCODE_EN__
static void mmi_am_la_launch_EGYPTCODE_EN(void)
{
    mmi_am_launch_app_by_id(APPID_EGYPTCODE_EN);
}
void mmi_am_la_highlight_EGYPTCODE_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_EGYPTCODE_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_EGYPTCODE_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_CHS__
static void mmi_am_la_launch_EGYPTCODE_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_EGYPTCODE_CHS);
}
void mmi_am_la_highlight_EGYPTCODE_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_EGYPTCODE_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_EGYPTCODE_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN__
static void mmi_am_la_launch_KINGCOMBAT_EN(void)
{
    mmi_am_launch_app_by_id(APPID_KINGCOMBAT_EN);
}
void mmi_am_la_highlight_KINGCOMBAT_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_KINGCOMBAT_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_KINGCOMBAT_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_KINGCOMBAT_CHS__
static void mmi_am_la_launch_KINGCOMBAT_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_KINGCOMBAT_CHS);
}
void mmi_am_la_highlight_KINGCOMBAT_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_KINGCOMBAT_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_KINGCOMBAT_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN__
static void mmi_am_la_launch_GOLDMINER_EN(void)
{
    mmi_am_launch_app_by_id(APPID_GOLDMINER_EN);
}
void mmi_am_la_highlight_GOLDMINER_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_GOLDMINER_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_GOLDMINER_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_GOLDMINER_CHS__
static void mmi_am_la_launch_GOLDMINER_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_GOLDMINER_CHS);
}
void mmi_am_la_highlight_GOLDMINER_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_GOLDMINER_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_GOLDMINER_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif
/***********************************************/

#ifdef __MMI_MRE_GAME_MOTO_EN__
static void mmi_am_la_launch_MOTO_EN(void)
{
    mmi_am_launch_app_by_id(APPID_MOTO_EN);
}
void mmi_am_la_highlight_MOTO_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_MOTO_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_MOTO_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_GAME_MOTO_CHS__
static void mmi_am_la_launch_MOTO_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_MOTO_CHS);
}
void mmi_am_la_highlight_MOTO_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_MOTO_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_MOTO_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_GIRLSLOT_EN__
static void mmi_am_la_launch_GIRLSLOT_EN(void)
{
    mmi_am_launch_app_by_id(APPID_GIRLSLOT_EN);
}
void mmi_am_la_highlight_GIRLSLOT_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_GIRLSLOT_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_GIRLSLOT_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_GIRLSLOT_CHS__
static void mmi_am_la_launch_GIRLSLOT_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_GIRLSLOT_CHS);
}
void mmi_am_la_highlight_GIRLSLOT_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_GIRLSLOT_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_GIRLSLOT_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_PARKOUR_EN__
static void mmi_am_la_launch_PARKOUR_EN(void)
{
    mmi_am_launch_app_by_id(APPID_PARKOUR_EN);
}
void mmi_am_la_highlight_PARKOUR_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_PARKOUR_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_PARKOUR_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_CHS__
static void mmi_am_la_launch_PARKOUR_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_PARKOUR_CHS);
}
void mmi_am_la_highlight_PARKOUR_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_PARKOUR_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_PARKOUR_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif



#ifdef __MMI_MRE_GAME_TEARDRESS_EN__
static void mmi_am_la_launch_TEARDRESS_EN(void)
{
    mmi_am_launch_app_by_id(APPID_TEARDRESS_EN);
}
void mmi_am_la_highlight_TEARDRESS_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_TEARDRESS_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_TEARDRESS_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_MRE_GAME_TEARDRESS_CHS__
static void mmi_am_la_launch_TEARDRESS_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_TEARDRESS_CHS);
}
void mmi_am_la_highlight_TEARDRESS_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_TEARDRESS_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_TEARDRESS_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif



#ifdef __MMI_MRE_GAME_HAPPYEGG_EN__
static void mmi_am_la_launch_HAPPYEGG_EN(void)
{
    mmi_am_launch_app_by_id(APPID_HAPPYEGG_EN);
}
void mmi_am_la_highlight_HAPPYEGG_EN(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_HAPPYEGG_EN, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_HAPPYEGG_EN, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_CHS__
static void mmi_am_la_launch_HAPPYEGG_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_HAPPYEGG_CHS);
}
void mmi_am_la_highlight_HAPPYEGG_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_HAPPYEGG_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_HAPPYEGG_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif



/**********/
/*<---------------------------- ADD 3GT Game START ---------------------------->*/

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
static void mmi_am_la_launch_BOWLING_ENG(void)
{
    mmi_am_launch_app_by_id(APPID_BOWLING_ENG);
}

void mmi_am_la_highlight_BOWLING_ENG(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_BOWLING_ENG, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_BOWLING_ENG, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
static void mmi_am_la_launch_BOWLING_CHS(void)
{
    mmi_am_launch_app_by_id(APPID_BOWLING_CHS);
}

void mmi_am_la_highlight_BOWLING_CHS(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_BOWLING_CHS, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_BOWLING_CHS, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
static void mmi_am_la_launch_BOWLING_CHT(void)
{
    mmi_am_launch_app_by_id(APPID_BOWLING_CHT);
}

void mmi_am_la_highlight_BOWLING_CHT(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_BOWLING_CHT, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_BOWLING_CHT, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
static void mmi_am_la_launch_DANDELION(void)
{
    mmi_am_launch_app_by_id(APPID_DANDELION);
}

void mmi_am_la_highlight_DANDELION(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_DANDELION, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_DANDELION, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
    static void mmi_am_la_launch_3gt_rash_motor_chs(void)
    {
        mmi_am_launch_app_by_id(APPID_3GT_RASH_MOTOR_CHS);
    }

    void mmi_am_la_highlight_3gt_rash_motor_chs(void)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_am_la_launch_3gt_rash_motor_chs, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_am_la_launch_3gt_rash_motor_chs, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
    static void mmi_am_la_launch_3gt_rash_motor_cht(void)
    {
        mmi_am_launch_app_by_id(APPID_3GT_RASH_MOTOR_CHT);
    }
    
    void mmi_am_la_highlight_3gt_rash_motor_cht(void)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_am_la_launch_3gt_rash_motor_cht, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_am_la_launch_3gt_rash_motor_cht, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
    static void mmi_am_la_launch_3gt_rash_motor_eng(void)
    {
        mmi_am_launch_app_by_id(APPID_3GT_RASH_MOTOR_ENG);
    }

    void mmi_am_la_highlight_3gt_rash_motor_eng(void)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_am_la_launch_3gt_rash_motor_eng, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_am_la_launch_3gt_rash_motor_eng, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
    static void mmi_am_la_launch_3gt_balance_ball_chs(void)
    {
        mmi_am_launch_app_by_id(APPID_3GT_BALANCE_BALL_CHS);
    }
    
    void mmi_am_la_highlight_3gt_balance_ball_chs(void)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_am_la_launch_3gt_balance_ball_chs, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_am_la_launch_3gt_balance_ball_chs, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
    static void mmi_am_la_launch_3gt_balance_ball_cht(void)
    {
        mmi_am_launch_app_by_id(APPID_3GT_BALANCE_BALL_CHT);
    }
    
    void mmi_am_la_highlight_3gt_balance_ball_cht(void)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_am_la_launch_3gt_balance_ball_cht, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_am_la_launch_3gt_balance_ball_cht, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
    static void mmi_am_la_launch_3gt_balance_ball_eng(void)
    {
        mmi_am_launch_app_by_id(APPID_3GT_BALANCE_BALL_ENG);
    }
    
    void mmi_am_la_highlight_3gt_balance_ball_eng(void)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetLeftSoftkeyFunction(mmi_am_la_launch_3gt_balance_ball_eng, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_am_la_launch_3gt_balance_ball_eng, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif

/*<---------------------------- ADD 3GT Game END ------------------------------>*/

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__)
static void mmi_am_la_launch_GameLoft_ASPHALT6(void)
{
	mmi_am_launch_app_by_id(APPID_GAMELOFT_ASPHALT6);
}
void mmi_am_la_highlight_GameLoft_ASPHALT6(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static void mmi_am_la_launch_GameLoft_BRAINCHALLENGE(void)
{
	mmi_am_launch_app_by_id(APPID_GAMELOFT_BRAINCHALLENGE);
}
void mmi_am_la_highlight_GameLoft_BRAINCHALLENGE(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_BRAINCHALLENGE, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_BRAINCHALLENGE, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static void mmi_am_la_launch_GameLoft_BLOCKBREAKER(void)
{
	mmi_am_launch_app_by_id(APPID_GAMELOFT_BLOCKBREAKER);
}
void mmi_am_la_highlight_GameLoft_BLOCKBREAKER(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_BLOCKBREAKER, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_BLOCKBREAKER, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

static void mmi_am_la_launch_GameLoft_ASSASSINCREED(void)
{
	mmi_am_launch_app_by_id(APPID_GAMELOFT_ASSASSINCREED);
}
void mmi_am_la_highlight_GameLoft_ASSASSINCREED(void)
{
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASSASSINCREED, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASSASSINCREED, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__)
	static void mmi_am_la_launch_GameLoft_ASPHALT6(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_ASPHALT6);
	}
	void mmi_am_la_highlight_GameLoft_ASPHALT6(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
	
	static void mmi_am_la_launch_GameLoft_BRAINCHALLENGE(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_BRAINCHALLENGE);
	}
	void mmi_am_la_highlight_GameLoft_BRAINCHALLENGE(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_BRAINCHALLENGE, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_BRAINCHALLENGE, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
	
	static void mmi_am_la_launch_GameLoft_BLOCKBREAKER(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_BLOCKBREAKER);
	}
	void mmi_am_la_highlight_GameLoft_BLOCKBREAKER(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_BLOCKBREAKER, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_BLOCKBREAKER, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__)
	static void mmi_am_la_launch_GameLoft_ASPHALT6(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_ASPHALT6);
	}
	void mmi_am_la_highlight_GameLoft_ASPHALT6(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
	
	static void mmi_am_la_launch_GameLoft_BLOCKBREAKER(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_BLOCKBREAKER);
	}
	void mmi_am_la_highlight_GameLoft_BLOCKBREAKER(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_BLOCKBREAKER, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_BLOCKBREAKER, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
	
	static void mmi_am_la_launch_GameLoft_ASSASSINCREED(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_ASSASSINCREED);
	}
	void mmi_am_la_highlight_GameLoft_ASSASSINCREED(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASSASSINCREED, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASSASSINCREED, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__)
	static void mmi_am_la_launch_GameLoft_ASPHALT6(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_ASPHALT6);
	}
	void mmi_am_la_highlight_GameLoft_ASPHALT6(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
	
	static void mmi_am_la_launch_GameLoft_BRAINCHALLENGE(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_BRAINCHALLENGE);
	}
	void mmi_am_la_highlight_GameLoft_BRAINCHALLENGE(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_BRAINCHALLENGE, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_BRAINCHALLENGE, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}

	static void mmi_am_la_launch_GameLoft_ASSASSINCREED(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_ASSASSINCREED);
	}
	void mmi_am_la_highlight_GameLoft_ASSASSINCREED(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASSASSINCREED, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASSASSINCREED, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	static void mmi_am_la_launch_gameloft_glive(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_GLIVE);
	}
	void mmi_am_la_highlight_gameloft_glive(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_gameloft_glive, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_gameloft_glive, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
	
	static void mmi_am_la_launch_gameloft_mc2(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_MC2);
	}
	void mmi_am_la_highlight_gameloft_mc2(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_gameloft_mc2, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_gameloft_mc2, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)

	static void mmi_am_la_launch_gameloft_glive(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_GLIVE);
	}
	void mmi_am_la_highlight_gameloft_glive(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_gameloft_glive, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_gameloft_glive, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}

	static void mmi_am_la_launch_GameLoft_ASPHALT6(void)
	{
		mmi_am_launch_app_by_id(APPID_GAMELOFT_ASPHALT6);
	}
	void mmi_am_la_highlight_GameLoft_ASPHALT6(void)
	{
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(mmi_am_la_launch_GameLoft_ASPHALT6, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	}
#endif


#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
static void mmi_am_la_launch_sina_weibo(void)
{
    mmi_am_launch_app_by_id(APPID_SINA_WEIBO);
}
    
void mmi_am_la_highlight_sina_weibo(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_am_la_launch_sina_weibo, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_am_la_launch_sina_weibo, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif


/**********/


#endif /* __MRE_APP_LAUNCH__ */ 

