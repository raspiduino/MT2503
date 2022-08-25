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
/****************************************************************************
 *
 * Filename:
 * ---------
 *  MMI_features.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI feature file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #define __MMI_CHSET_GB2312__
#if defined (EMPTY_MMI) || defined (EXTERNAL_MMI)
#define __MMI_FEATURES__    /* skip MMI_features.h for EMPTY_MMI and EXTERNAL_MMI */
#endif

#ifndef __MMI_FEATURES__
#define __MMI_FEATURES__

#include "MMI_features_switch.h"

/*****************************************************************************
* MTK Internal MMI Features                                                                     
*****************************************************************************/

#if defined(MTK_INTERNAL_MMI_FEATURES) && defined(USE_COMMON_MMI_FEATURES_SWITCH)
/* under construction !*/
#endif /* defined(MTK_INTERNAL_MMI_FEATURES) && defined(USE_COMMON_MMI_FEATURES_SWITCH) */

#ifndef __OPTR_NONE__
#include "operator_mmi.h"
#endif
/*
  Description: used by internal project, to choose different Traditional Chinese font database
  Option: n/a
  Reference: n/a
*/
#if defined(CFG_MMI_LANG_TR_CHINESE) && (CFG_MMI_LANG_TR_CHINESE != __OFF__)
    #define __MMI_CHAR_SET_BIG5__												
#endif

/*
  Description: used by internal project, to choose different Simple Chinese font database
  Option: n/a
  Reference: n/a
*/
#if defined(CFG_MMI_LANG_SM_CHINESE) && (CFG_MMI_LANG_SM_CHINESE != __OFF__)
    #define __MMI_CHAR_SET_GB2312__
#endif




/*****************************************************************************
* Dependency Description
*****************************************************************************/

#if (defined(WAP_SUPPORT))
	#ifndef __MMI_DOWNLOAD_AGENT__
	#define __MMI_DOWNLOAD_AGENT__
	#endif
#endif


#if defined(CFG_MMI_OMA_DD_DOWNLOAD) && ((CFG_MMI_OMA_DD_DOWNLOAD == __ON__)||(CFG_MMI_OMA_DD_DOWNLOAD == __AUTO__)) && \
	(defined(__MMI_DOWNLOAD_AGENT__) && defined(__XML_SUPPORT__) && defined(__HTTP_INTERFACE__))
	#ifndef __MMI_OMA_DD_DOWNLOAD__
	#define __MMI_OMA_DD_DOWNLOAD__
	#endif
#endif


#if (defined(SYNCML_DM_SUPPORT) && !defined(__MMI_OMA_DD_DOWNLOAD__))
	#error "Setting conflict, SYNCML_DL_SUPPORT require enable of __MMI_OMA_DD_DOWNLOAD__"
#endif


#if defined(CFG_MMI_DOWNLOAD_AGENT_MULTI_DL) && ((CFG_MMI_DOWNLOAD_AGENT_MULTI_DL == __ON__)||(CFG_MMI_DOWNLOAD_AGENT_MULTI_DL == __AUTO__)) && \
	(defined(__MMI_DOWNLOAD_AGENT__) && (defined(BROWSER_SUPPORT) || defined(SYNCML_DM_SUPPORT)))
	#ifndef __MMI_DOWNLOAD_AGENT_MULTI_DL__
	#define __MMI_DOWNLOAD_AGENT_MULTI_DL__
	#endif
#endif


#if (defined(SYNCML_DM_SUPPORT) && !defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__))
	#error "Setting conflict, SYNCML_DL_SUPPORT require enable of __MMI_DOWNLOAD_AGENT_MULTI_DL__"
#endif


#if defined(CFG_MMI_UM_CONVERSATION_BOX_ENHANCE) && ((CFG_MMI_UM_CONVERSATION_BOX_ENHANCE == __ON__)||(CFG_MMI_UM_CONVERSATION_BOX_ENHANCE == __AUTO__))
	#ifndef __MMI_UM_CONVERSATION_BOX_ENHANCE__
	#define __MMI_UM_CONVERSATION_BOX_ENHANCE__
	#endif
#endif


#if defined(CFG_MMI_UM_CONVERSATION_BOX) && (CFG_MMI_UM_CONVERSATION_BOX == __ON__) || \
	((CFG_MMI_UM_CONVERSATION_BOX == __AUTO__) || defined(__MMI_UM_CONVERSATION_BOX_ENHANCE__) ||  (defined(__MMI_VUI_SHELL_MULTI_PAGE__) || (defined(__COSMOS_MMI_PACKAGE__) && defined(__UM_FOLDER__))))
	#ifndef __MMI_UM_CONVERSATION_BOX__
	#define __MMI_UM_CONVERSATION_BOX__
	#endif
#endif


#if (defined(__MMI_UM_CONVERSATION_BOX__) &&!defined(__UM_FOLDER__) && !defined(__COSMOS_MMI_PACKAGE__))
	#error "UM Conversation box feature needs to enable UM_FOLDER. Please turn off CFG_MMI_UM_CONVERSATION_BOX or turn on UM_FOLDER"
#endif


#if defined(CFG_MMI_UM_REPORT_BOX) && ((CFG_MMI_UM_REPORT_BOX == __ON__)||(CFG_MMI_UM_REPORT_BOX == __AUTO__))
	#if (defined(__SLIM_MMS__))
	#error "UM report box must turn off __SLIM_MMS__ features. Please turn MMS_FEATURES as FULL or turn off CFG_MMI_UM_REPORT_BOX"
	#endif
	#ifndef __MMI_UM_REPORT_BOX__
	#define __MMI_UM_REPORT_BOX__
	#endif
#endif


#if (defined(__MMI_UM_REPORT_BOX__) && (CFG_MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE == __UM_LIST_NORMAL__))
	#error "UM report box must turn folder list style as __UM_LIST_INLINE__"
#endif


#if defined(CFG_MMI_UM_REPORT_STATUS_IN_SENT_BOX) && ((CFG_MMI_UM_REPORT_STATUS_IN_SENT_BOX == __ON__)||(CFG_MMI_UM_REPORT_STATUS_IN_SENT_BOX == __AUTO__))
	#ifndef __MMI_UM_REPORT_STATUS_IN_SENT_BOX__
	#define __MMI_UM_REPORT_STATUS_IN_SENT_BOX__
	#endif
#endif


#if (defined(__MMI_UM_REPORT_STATUS_IN_SENT_BOX__) && !defined(__MMI_UM_REPORT_BOX__))
	#error "It should turn on __MMI_UM_REPORT_BOX__ or disable __MMI_UM_REPORT_STATUS_IN_SENT_BOX__"
#endif


#if (defined(__MMI_UM_REPORT_STATUS_IN_SENT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
	#error "It should turn on __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ or disable __MMI_UM_REPORT_STATUS_IN_SENT_BOX__"
#endif


#if (defined(__MMI_UM_REPORT_STATUS_IN_SENT_BOX__) && defined(__EMS_NON_STD_7BIT_CHAR__))
	#error "It should turn off __EMS_NON_STD_7BIT_CHAR__ or disable __MMI_UM_REPORT_STATUS_IN_SENT_BOX__"
#endif


#if defined(CFG_MMI_PREFER_INPUT_METHOD) && ((CFG_MMI_PREFER_INPUT_METHOD == __ON__)||(CFG_MMI_PREFER_INPUT_METHOD == __AUTO__)) && \
	(!defined(MMI_IME_V3_SUPPORT))
	#ifndef __MMI_PREFER_INPUT_METHOD__
	#define __MMI_PREFER_INPUT_METHOD__
	#endif
#endif


#if defined(CFG_MMI_IME_PREFER_WRITING_LANG) && ((CFG_MMI_IME_PREFER_WRITING_LANG == __ON__)||(CFG_MMI_IME_PREFER_WRITING_LANG == __AUTO__)) && \
	(!defined(__MMI_PREFER_INPUT_METHOD__)) || (defined(MMI_IME_V3_SUPPORT) && (!defined(__MMI_PREFER_INPUT_METHOD__)))
	#ifndef __MMI_IME_PREFER_WRITING_LANG__
	#define __MMI_IME_PREFER_WRITING_LANG__
	#endif
#endif


#if defined(CFG_MMI_IME_MIXED_LANG_SUPPORT) && ((CFG_MMI_IME_MIXED_LANG_SUPPORT == __ON__)||(CFG_MMI_IME_MIXED_LANG_SUPPORT == __AUTO__))
	#ifndef __MMI_IME_MIXED_LANG_SUPPORT__
	#define __MMI_IME_MIXED_LANG_SUPPORT__
	#endif
#endif


#if (!defined(__MMI_IME_PREFER_WRITING_LANG__) && !defined(__MMI_IME_MIXED_LANG_SUPPORT__) && !defined(__MMI_PREFER_INPUT_METHOD__))
	#error "Please  turn on  one out of prefer input language or prefered input mode.Both are off"
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__))
	#error "setting conflicts, please turn on UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT in COSMOS project"
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
	#error "setting conflicts, please turn on UNIFIED_MESSAGE_SIMBOX_SUPPORT in COSMOS project"
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_UM_REPORT_BOX__))
	#error "setting conflicts, please turn off CFG_MMI_UM_REPORT_BOX in COSMOS project"
#endif


#if defined(CFG_MMI_MESSAGES_COPY) && ((CFG_MMI_MESSAGES_COPY == __ON__)||(CFG_MMI_MESSAGES_COPY == __AUTO__)) && \
	(defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_COPY__
	#define __MMI_MESSAGES_COPY__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) && defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) && !defined(__MMI_MESSAGES_COPY__))
	#error "please define __MMI_MESSAGES_COPY__ for __MMI_FTE_SUPPORT__ && __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ opening condition."
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_UM_REPORT_STATUS_IN_SENT_BOX__))
	#error "setting conflicts, please turn off CFG_MMI_UM_REPORT_STATUS_IN_SENT_BOX in COSMOS project"
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
	#error "setting conflicts, please turn on __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ in COSMOS project"
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__))
	#error "setting conflicts, please turn off __UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__ in COSMOS project"
#endif


#if (defined(CFG_MMI_EDITOR_OPTION_MENU_STYLE))
	#ifndef __MMI_EDITOR_OPTION_MENU_STYLE__
	#define __MMI_EDITOR_OPTION_MENU_STYLE__	CFG_MMI_EDITOR_OPTION_MENU_STYLE
	#endif
#endif


#if (!defined(MMI_IME_V3_SUPPORT) && ((defined(__MMI_EDITOR_OPTION_MENU_STYLE__) && (__MMI_EDITOR_OPTION_MENU_STYLE__ == __STYLE_1__))))
	#ifndef __MMI_EDITOR_OPTION_MENU_STYLE_1__
	#define __MMI_EDITOR_OPTION_MENU_STYLE_1__
	#endif
#endif


#if (!defined(MMI_IME_V3_SUPPORT) && ((defined(__MMI_EDITOR_OPTION_MENU_STYLE__) && (__MMI_EDITOR_OPTION_MENU_STYLE__ == __STYLE_2__))))
	#ifndef __MMI_EDITOR_OPTION_MENU_STYLE_2__
	#define __MMI_EDITOR_OPTION_MENU_STYLE_2__
	#endif
#endif


#if (defined(MMI_IME_V3_SUPPORT) || ((defined(__MMI_EDITOR_OPTION_MENU_STYLE__) && (__MMI_EDITOR_OPTION_MENU_STYLE__ == __STYLE_3__))))
	#ifndef __MMI_EDITOR_OPTION_MENU_STYLE_3__
	#define __MMI_EDITOR_OPTION_MENU_STYLE_3__
	#endif
#endif


#if (defined(__MMI_KOMOXO__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_IME_PLUG_IN_SETTING__
	#define __MMI_IME_PLUG_IN_SETTING__
	#endif
#endif


#if ((defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)) && defined(__MMI_IME_PLUG_IN_SETTING__))
	#error "cannot turn on __MMI_EDITOR_OPTION_MENU_STYLE_1__ , __MMI_EDITOR_OPTION_MENU_STYLE_2__ or __MMI_EDITOR_OPTION_MENU_STYLE_3__ when __MMI_IME_PLUG_IN_SETTING__ is on"
#endif


#if defined(CFG_MMI_TIMEZONE_SETTING) && ((CFG_MMI_TIMEZONE_SETTING == __ON__)||(CFG_MMI_TIMEZONE_SETTING == __AUTO__))
	#ifndef __MMI_TIMEZONE_SETTING__
	#define __MMI_TIMEZONE_SETTING__
	#endif
#endif


#if defined(CFG_MMI_WORLD_CLOCK) && ((CFG_MMI_WORLD_CLOCK == __ON__)||(CFG_MMI_WORLD_CLOCK == __AUTO__)) && \
	(!defined(__MMI_MRE_WORLD_CLOCK__) && defined(__MMI_TIMEZONE_SETTING__))
	#ifndef __MMI_WORLD_CLOCK__
	#define __MMI_WORLD_CLOCK__
	#endif
#endif


#if defined(CFG_MMI_NITZ) && ((CFG_MMI_NITZ == __ON__)||(CFG_MMI_NITZ == __AUTO__)) && \
	(defined(__MMI_WORLD_CLOCK__) || defined(__MMI_MRE_WORLD_CLOCK__))
	#ifndef __MMI_NITZ__
	#define __MMI_NITZ__
	#endif
#endif


#if (defined(__DRM_SEC_CLK_NITZ__) && !defined(__MMI_NITZ__))
	#error "NITZ application should be turned ON, for NITZ based DRM clock"
#endif


#if ((defined(__MMI_KOMOXO__) && !defined(__COSMOS_MMI_PACKAGE__)) && !defined(__MMI_IME_PREFER_WRITING_LANG__))
	#error "the komoxo only support the feature of prefer writing language"
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX) && ((CFG_MMI_3D_GAME_INTERGRAFX == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX__
	#define __MMI_3D_GAME_INTERGRAFX__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_DANCING) && ((CFG_MMI_3D_GAME_INTERGRAFX_DANCING == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_DANCING == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL))  &&defined(__MMI_3D_GAME_INTERGRAFX__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_DANCING__
	#define __MMI_3D_GAME_INTERGRAFX_DANCING__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_TOWER) && ((CFG_MMI_3D_GAME_INTERGRAFX_TOWER == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_TOWER == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL))  && defined(__MMI_3D_GAME_INTERGRAFX__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_TOWER__
	#define __MMI_3D_GAME_INTERGRAFX_TOWER__
	#endif
#endif


#if (defined(__MMI_3D_GAME_INTERGRAFX__)  && !defined(__MMI_3D_GAME_INTERGRAFX_DANCING__) && !defined(__MMI_3D_GAME_INTERGRAFX_TOWER__))
	#error "Please turn off CFG_MMI_3D_GAME_INTERGRAFX to disable IG 3D Game"
#endif


#if (defined(__VENUS_UI_ENGINE__))
	#ifndef __MMI_VUI_ENGINE__
	#define __MMI_VUI_ENGINE__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_KEY) && ((CFG_MMI_VUI_LAUNCHER_KEY == __ON__)||(CFG_MMI_VUI_LAUNCHER_KEY == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__)&& defined(__MMI_FTE_SUPPORT__) && defined(__FANCY_PLUTO_APP_ON_VENUS_UI__) && defined(__MMI_VUI_ENGINE__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)))
	#ifndef __MMI_VUI_LAUNCHER_KEY__
	#define __MMI_VUI_LAUNCHER_KEY__
	#endif
#endif


#if (defined(TOUCH_PANEL_SUPPORT))
	#ifndef __MMI_TOUCH_SCREEN__
	#define __MMI_TOUCH_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER) && ((CFG_MMI_VUI_LAUNCHER == __ON__)||(CFG_MMI_VUI_LAUNCHER == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__) && defined(__FANCY_PLUTO_APP_ON_VENUS_UI__) && defined(__MMI_VUI_ENGINE__) && defined(__MMI_TOUCH_SCREEN__) && (defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_VUI_LAUNCHER__
	#define __MMI_VUI_LAUNCHER__
	#endif
#endif


#if (defined(__MMI_VUI_ENGINE__) && (defined(__COSMOS_MMI_PACKAGE__) || (defined(__PLUTO_MMI_PACKAGE__) && (defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__)))))
	#ifndef __MMI_VUI_HOMESCREEN_WALLPAPER__
	#define __MMI_VUI_HOMESCREEN_WALLPAPER__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X240__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH == __AUTO__)) && \
	(defined(INTERGRAFX_ENGINE_FULL) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL))  && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER) && ((CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER == __ON__)||(CFG_MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__
	#endif
#endif


#if ((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && (!defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__) && !defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__) && !defined(__MMI_3D_GAME_INTERGRAFX_DANCING__) && !defined(__MMI_3D_GAME_INTERGRAFX_TOWER__)))
	#error "Turn on at least one IG LW or Game, or turn off the INTERGRAFX_SUPPORT"
#endif


#if (defined(__MMI_FTE_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_IME_FTE_ENHANCE__
	#define __MMI_IME_FTE_ENHANCE__
	#endif
#endif


#if (defined(NORMAL_KEYPAD))
	#ifndef __MMI_NORMAL_KEYPAD__
	#define __MMI_NORMAL_KEYPAD__
	#endif
#endif


#if (defined(MMI_IME_V3_SUPPORT))
	#ifndef __MMI_IME_V3__
	#define __MMI_IME_V3__
	#endif
#endif


#if (defined(QWERTY_KEYPAD))
	#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
	#define __MMI_QWERTY_KEYPAD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_IME_VK_TYPE_QWERTY) && ((CFG_MMI_IME_VK_TYPE_QWERTY == __ON__)||(CFG_MMI_IME_VK_TYPE_QWERTY == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__)&& defined (__MMI_IME_V3__) && !((CFG_MMI_IME_VK_TYPE_QWERTY == __AUTO__)  && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)) && (!defined(__PHONE_SLIDE__))))
	#ifndef __MMI_IME_VK_TYPE_QWERTY__
	#define __MMI_IME_VK_TYPE_QWERTY__
	#endif
#endif


#if defined(CFG_MMI_IME_VK_TYPE_ALPHANUMERIC) && ((CFG_MMI_IME_VK_TYPE_ALPHANUMERIC == __ON__)||(CFG_MMI_IME_VK_TYPE_ALPHANUMERIC == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__)&& defined (__MMI_IME_V3__) && !((CFG_MMI_IME_VK_TYPE_ALPHANUMERIC == __AUTO__)  && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)) && (!defined(__PHONE_SLIDE__))))
	#ifndef __MMI_IME_VK_TYPE_ALPHANUMERIC__
	#define __MMI_IME_VK_TYPE_ALPHANUMERIC__
	#endif
#endif


#if defined(CFG_MMI_VIRTUAL_KEYBOARD) && ((CFG_MMI_VIRTUAL_KEYBOARD == __ON__)||(CFG_MMI_VIRTUAL_KEYBOARD == __AUTO__)) && \
	(((defined(__MMI_TOUCH_SCREEN__) && (defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) || !defined(__NO_HANDWRITING__))) && defined (__MMI_IME_V3__)) || ((defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__))) && !defined(__MMI_IME_V3__)))
	#ifndef __MMI_VIRTUAL_KEYBOARD__
	#define __MMI_VIRTUAL_KEYBOARD__
	#endif
#endif


#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
	#ifndef __MMI_CLAMSHELL__
	#define __MMI_CLAMSHELL__
	#endif
#endif


#if (defined(REDUCED_KEYPAD))
	#ifndef __MMI_REDUCED_KEYPAD__
	#define __MMI_REDUCED_KEYPAD__
	#endif
#endif


#if ((defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_IME_V3__)) && (defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__) || (!defined(__NO_HANDWRITING__))))
	#ifndef __MMI_COSMOS_KEYPAD_SUPPORT_VK__
	#define __MMI_COSMOS_KEYPAD_SUPPORT_VK__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_CLAMSHELL__) && !defined(__MMI_REDUCED_KEYPAD__)&& !defined (__MMI_COSMOS_KEYPAD_SUPPORT_VK__))
	#ifndef __MMI_COSMOS_KEYPAD_BAR__
	#define __MMI_COSMOS_KEYPAD_BAR__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__MMI_COSMOS_KEYPAD_BAR__))
	#ifndef __MMI_IME_ALPHANUMERIC_VK_SUPPORT__
	#define __MMI_IME_ALPHANUMERIC_VK_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_LANG_SM_CHINESE) && ((CFG_MMI_LANG_SM_CHINESE == __ON__)||(CFG_MMI_LANG_SM_CHINESE == __AUTO__))
	#ifndef __MMI_LANG_SM_CHINESE__
	#define __MMI_LANG_SM_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_TR_CHINESE) && ((CFG_MMI_LANG_TR_CHINESE == __ON__)||(CFG_MMI_LANG_TR_CHINESE == __AUTO__))
	#ifndef __MMI_LANG_TR_CHINESE__
	#define __MMI_LANG_TR_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_HK_CHINESE) && ((CFG_MMI_LANG_HK_CHINESE == __ON__)||(CFG_MMI_LANG_HK_CHINESE == __AUTO__))
	#ifndef __MMI_LANG_HK_CHINESE__
	#define __MMI_LANG_HK_CHINESE__
	#endif
#endif


#if ((((defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)) && (defined(__MMI_CSTAR__) || defined(__MMI_ZI__) || defined(__MMI_T9__)) || defined(__MMI_KOMOXO__)|| defined(__MMI_GUOBI__))&& (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))))
	#ifndef __MMI_SMART_PHONETIC_INPUT_METHODS__
	#define __MMI_SMART_PHONETIC_INPUT_METHODS__
	#endif
#endif


#if (defined(__MMI_SMART_PHONETIC_INPUT_METHODS__) && (defined(__MMI_CSTAR__) && defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)))
	#ifndef __MMI_CSTAR_SMART_PHONETIC_INPUT__
	#define __MMI_CSTAR_SMART_PHONETIC_INPUT__
	#endif
#endif


#if defined(CFG_MMI_CSTAR_PHRASE_INPUT) && ((CFG_MMI_CSTAR_PHRASE_INPUT == __ON__)||(CFG_MMI_CSTAR_PHRASE_INPUT == __AUTO__)) && \
	(defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_CSTAR_V2__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__ ) && !defined(__MMI_KOMOXO__) && (defined(REDUCED_KEYPAD) || defined(__MMI_IME_V3__)))
	#ifndef __MMI_CSTAR_PHRASE_INPUT__
	#define __MMI_CSTAR_PHRASE_INPUT__
	#endif
#endif


#if defined(CFG_MMI_IME_SMART_WITH_INPUT_AREA) && ((CFG_MMI_IME_SMART_WITH_INPUT_AREA == __ON__)||(CFG_MMI_IME_SMART_WITH_INPUT_AREA == __AUTO__)) && \
	(defined(__MMI_CSTAR_V2__) && !defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_NORMAL_KEYPAD__) && !defined(__OP01_FWPBW__)) || (defined(__MMI_CSTAR_PHRASE_INPUT__))
	#ifndef __MMI_IME_SMART_WITH_INPUT_AREA__
	#define __MMI_IME_SMART_WITH_INPUT_AREA__
	#endif
#endif


#if defined(CFG_MMI_IME_FLOATING_CAND_BOX) && ((CFG_MMI_IME_FLOATING_CAND_BOX == __ON__)||(CFG_MMI_IME_FLOATING_CAND_BOX == __AUTO__)) && \
	((!defined(__MMI_IME_SMART_WITH_INPUT_AREA__)&& !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) && !(defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_SCREEN__))) || (defined(__MMI_IME_FTE_ENHANCE__) && !defined(__MMI_IME_SMART_WITH_INPUT_AREA__)&& (!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) && !(defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_SCREEN__))))) || (defined(__MMI_IME_FTE_ENHANCE__) && (!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) && !(defined(__MMI_MAINLCD_176X220__) && defined(__MMI_TOUCH_SCREEN__))) ||defined(__ATV_SMS_SUPPORT__)) || (defined(__MMI_CSTAR_PHRASE_INPUT__))
	#ifndef __MMI_IME_FLOATING_CAND_BOX__
	#define __MMI_IME_FLOATING_CAND_BOX__
	#endif
#endif


#if (defined(__MMI_CSTAR_PHRASE_INPUT__) && (!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || !defined(__MMI_IME_FLOATING_CAND_BOX__) || (!defined(REDUCED_KEYPAD) && !defined(__MMI_IME_V3__))))
	#error "the smart pinyin input method need the feature option __MMI_IME_SMART_WITH_INPUT_AREA__ ,__MMI_IME_FLOATING_CAND_BOX__ and REDUCED_KEYPAD to be defined, please turn on thess features"
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_MRE) && ((CFG_MMI_VUI_SCREEN_LOCK_MRE == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_MRE == __AUTO__)) && \
	(defined(__MMI_VUI_ENGINE__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_VUI_SCREEN_LOCK_MRE__
	#define __MMI_VUI_SCREEN_LOCK_MRE__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_SCREEN_LOCK_MRE__))
	#ifndef __MMI_VUI_SCREEN_LOCK_FACTORY__
	#define __MMI_VUI_SCREEN_LOCK_FACTORY__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_COSMOS) && ((CFG_MMI_VUI_SCREEN_LOCK_COSMOS == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_COSMOS == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__))
	#error "Please define __MMI_VUI_SCREEN_LOCK_FACTORY__"
	#endif
	#ifndef __MMI_VUI_SCREEN_LOCK_COSMOS__
	#define __MMI_VUI_SCREEN_LOCK_COSMOS__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_PATTERN) && ((CFG_MMI_VUI_SCREEN_LOCK_PATTERN == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_PATTERN == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__))
	#error "Please define __MMI_VUI_SCREEN_LOCK_FACTORY__"
	#endif
	#ifndef __MMI_VUI_SCREEN_LOCK_PATTERN__
	#define __MMI_VUI_SCREEN_LOCK_PATTERN__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_STEAM) && ((CFG_MMI_VUI_SCREEN_LOCK_STEAM == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_STEAM == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__) && defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__))
	#error "Please define __MMI_VUI_SCREEN_LOCK_FACTORY__"
	#endif
	#ifndef __MMI_VUI_SCREEN_LOCK_STEAM__
	#define __MMI_VUI_SCREEN_LOCK_STEAM__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_PAINTING) && ((CFG_MMI_VUI_SCREEN_LOCK_PAINTING == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_PAINTING == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__))
	#error "Please define __MMI_VUI_SCREEN_LOCK_FACTORY__"
	#endif
	#ifndef __MMI_VUI_SCREEN_LOCK_PAINTING__
	#define __MMI_VUI_SCREEN_LOCK_PAINTING__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_ZIPPER) && ((CFG_MMI_VUI_SCREEN_LOCK_ZIPPER == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_ZIPPER == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__) && !defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__))
	#error "Please define __MMI_VUI_SCREEN_LOCK_FACTORY__"
	#endif
	#ifndef __MMI_VUI_SCREEN_LOCK_ZIPPER__
	#define __MMI_VUI_SCREEN_LOCK_ZIPPER__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_RHYTHM) && ((CFG_MMI_VUI_SCREEN_LOCK_RHYTHM == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_RHYTHM == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__) && !defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_SCREEN_LOCK_FACTORY__))
	#error "Please define __MMI_VUI_SCREEN_LOCK_FACTORY__"
	#endif
	#ifndef __MMI_VUI_SCREEN_LOCK_RHYTHM__
	#define __MMI_VUI_SCREEN_LOCK_RHYTHM__
	#endif
#endif


#if ((defined(__COSMOS_MMI_PACKAGE__)) && (!defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && !defined(__MMI_VUI_SCREEN_LOCK_PATTERN__) && !defined(__MMI_VUI_SCREEN_LOCK_STEAM__) && !defined(__MMI_VUI_SCREEN_LOCK_PAINTING__) && !defined(__MMI_VUI_SCREEN_LOCK_ZIPPER__) && !defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)))
	#error "Please turn on at least one screen lock option, e.g., CFG_MMI_VUI_SCREEN_LOCK_COSMOS."
#endif


#if (defined(__CPU_ARM7EJ_S__) || defined(__CPU_ARM9EJ_S__) || defined(__MMI_FTE_SUPPORT__))
	#ifndef __MMI_LIST_MENU_SMOOTH_SCROLLING_CAPABLE__
	#define __MMI_LIST_MENU_SMOOTH_SCROLLING_CAPABLE__
	#endif
#endif


#if defined(CFG_MMI_UI_DISABLE_FANCY_EFFECT) && ((CFG_MMI_UI_DISABLE_FANCY_EFFECT == __ON__)||(CFG_MMI_UI_DISABLE_FANCY_EFFECT == __AUTO__)) && \
	((defined(MCU_13M) || defined(MCU_26M) || defined(MCU_39M) || defined(MCU_52M)) && !defined(__MMI_FTE_SUPPORT))
	#ifndef __MMI_UI_DISABLE_FANCY_EFFECT__
	#define __MMI_UI_DISABLE_FANCY_EFFECT__
	#endif
#endif


#if defined(CFG_MMI_UI_LIST_HIGHLIGHT_EFFECTS) && ((CFG_MMI_UI_LIST_HIGHLIGHT_EFFECTS == __ON__)||(CFG_MMI_UI_LIST_HIGHLIGHT_EFFECTS == __AUTO__)) && \
	(!defined(__MMI_UI_DISABLE_FANCY_EFFECT__))
	#ifndef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
	#define __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
	#endif
#endif


#if (defined(CFG_MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL)) &&\
	 (defined(__MMI_UI_LIST_HIGHLIGHT_EFFECTS__))
	#ifndef __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__
	#define __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__	CFG_MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL
	#endif
#endif


#if (defined(__MMI_MAINLCD_128X128__) || defined(LOW_COST_SUPPORT) || (defined(__MMI_UI_DISABLE_FANCY_EFFECT__)))
	#ifndef __MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__
	#define __MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__
	#endif
#endif


#if (defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__) && (__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__ == HIGHLIGHT_EFFECT_AUTO) && !defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__))
	#ifndef __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__
	#define __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	HIGHLIGHT_EFFECT_SLIDE
	#endif
#elif (defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__) && (__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__ == HIGHLIGHT_EFFECT_AUTO) && defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__))
	#ifndef __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__
	#define __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	HIGHLIGHT_EFFECT_NONE
	#endif
#elif (defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__))
	#if ((__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__ == HIGHLIGHT_EFFECT_SLIDE) && defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__))
	#error "HIGHLIGHT_EFFECT_SLIDE is not supported on this chip for __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__"
	#endif
	#ifndef __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__
	#define __MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__	__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE_SEL__
	#endif
#endif


#if (defined(__MMI_LIST_MENU_SMOOTH_SCROLLING_CAPABLE__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__) && (__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__ == HIGHLIGHT_EFFECT_SLIDE))
	#ifndef __MMI_LIST_MENU_SMOOTH_SCROLLING__
	#define __MMI_LIST_MENU_SMOOTH_SCROLLING__	MENU_SMOOTH_SCROLLING_PEN_AND_KEY
	#endif
#elif (defined(__MMI_LIST_MENU_SMOOTH_SCROLLING_CAPABLE__) && !defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__) && (__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__ == HIGHLIGHT_EFFECT_SLIDE))
	#ifndef __MMI_LIST_MENU_SMOOTH_SCROLLING__
	#define __MMI_LIST_MENU_SMOOTH_SCROLLING__	MENU_SMOOTH_SCROLLING_KEY
	#endif
#elif (defined(__MMI_LIST_MENU_SMOOTH_SCROLLING_CAPABLE__))
	#ifndef __MMI_LIST_MENU_SMOOTH_SCROLLING__
	#define __MMI_LIST_MENU_SMOOTH_SCROLLING__	MENU_SMOOTH_SCROLLING_AUTO 
	#endif
#else
	#ifndef __MMI_LIST_MENU_SMOOTH_SCROLLING__
	#define __MMI_LIST_MENU_SMOOTH_SCROLLING__	MENU_SMOOTH_SCROLLING_NONE
	#endif
#endif


#if (!defined(__MMI_TOUCH_SCREEN__) && ((__MMI_LIST_MENU_SMOOTH_SCROLLING__ == MENU_SMOOTH_SCROLLING_PEN) || (__MMI_LIST_MENU_SMOOTH_SCROLLING__ == MENU_SMOOTH_SCROLLING_PEN_AND_KEY)))
	#error "Cannot enable menu smooth scrolling by pen if there is no touch panel."
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_MRE) && ((CFG_MMI_VUI_LAUNCHER_MRE == __ON__)||(CFG_MMI_VUI_LAUNCHER_MRE == __AUTO__)) && \
	(defined(__MMI_VUI_ENGINE__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_VUI_LAUNCHER_MRE__
	#define __MMI_VUI_LAUNCHER_MRE__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_LAUNCHER_MRE__))
	#ifndef __MMI_VUI_LAUNCHER_FACTORY__
	#define __MMI_VUI_LAUNCHER_FACTORY__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_COSMOS) && ((CFG_MMI_VUI_LAUNCHER_COSMOS == __ON__)||(CFG_MMI_VUI_LAUNCHER_COSMOS == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_LAUNCHER_FACTORY__))
	#error "Please define __MMI_VUI_LAUNCHER_FACTORY__"
	#endif
	#ifndef __MMI_VUI_LAUNCHER_COSMOS__
	#define __MMI_VUI_LAUNCHER_COSMOS__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_MM) && ((CFG_MMI_VUI_LAUNCHER_MM == __ON__)||(CFG_MMI_VUI_LAUNCHER_MM == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_LAUNCHER_FACTORY__))
	#error "Please define __MMI_VUI_LAUNCHER_FACTORY__"
	#endif
	#ifndef __MMI_VUI_LAUNCHER_MM__
	#define __MMI_VUI_LAUNCHER_MM__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_ROBOT) && ((CFG_MMI_VUI_LAUNCHER_ROBOT == __ON__)||(CFG_MMI_VUI_LAUNCHER_ROBOT == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#if (!defined(__MMI_VUI_LAUNCHER_FACTORY__))
	#error "Please define __MMI_VUI_LAUNCHER_FACTORY__"
	#endif
	#ifndef __MMI_VUI_LAUNCHER_ROBOT__
	#define __MMI_VUI_LAUNCHER_ROBOT__
	#endif
#endif


#if ((defined(__COSMOS_MMI_PACKAGE__)) && (!defined(__MMI_VUI_LAUNCHER_COSMOS__) && !defined(__MMI_VUI_LAUNCHER_MM__) && !defined(__MMI_VUI_LAUNCHER_ROBOT__)))
	#error "Please turn on at least one launcher option, e.g., CFG_MMI_VUI_LAUNCHER_COSMOS."
#endif


#if (defined(__MMI_IME_MIXED_LANG_SUPPORT__) && defined(__MMI_CSTAR__))
	#error "CSTAR is incompatible with mixed language support"
#endif


#if (defined(__GEMINI_3G_SWITCH__))
	#ifndef __MMI_3G_SWITCH__
	#define __MMI_3G_SWITCH__
	#endif
#endif


#if (defined(__MMI_3G_SWITCH__) && defined(__COSMOS_MMI_PACKAGE__))
	#error "setting conflicts, 3G switch does not support in COSMOS project"
#endif


#if (defined(__MMI_3G_SWITCH__) && defined(__SIM_HOT_SWAP_SUPPORT__))
	#error "setting conflicts, 3G switch does not support SIM hot swap"
#endif


#if defined(CFG_SRV_PHB_CALLER_RES_DATA_STORE) && (CFG_SRV_PHB_CALLER_RES_DATA_STORE == __ON__) || \
	((CFG_SRV_PHB_CALLER_RES_DATA_STORE == __AUTO__) || defined(__MMI_VUI_SHELL_FAV_CONTACT__))
	#ifndef __SRV_PHB_CALLER_RES_DATA_STORE__
	#define __SRV_PHB_CALLER_RES_DATA_STORE__
	#endif
#endif


#if (!defined(FMT_NOT_PRESENT))
	#ifndef __MMI_FILE_MANAGER__
	#define __MMI_FILE_MANAGER__
	#endif
#endif


#if defined(CFG_MMI_PHB_CALLER_VIDEO) && ((CFG_MMI_PHB_CALLER_VIDEO == __ON__)||(CFG_MMI_PHB_CALLER_VIDEO == __AUTO__)) && \
	(((defined(MP4_DECODE) && (defined(__MP4_DEC_HW_SUPPORT__) || (defined(__MP4_DEC_SW_SUPPORT__) && !defined(MT6225)))) || (defined(MJPG_DECODE) && !defined(__DIRECT_SENSOR_SUPPORT__)) || defined(__RM_DEC_SUPPORT__)) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__) && defined(__MMI_FILE_MANAGER__) && !defined(__MMI_MAINLCD_128X128__))
	#ifndef __MMI_PHB_CALLER_VIDEO__
	#define __MMI_PHB_CALLER_VIDEO__
	#endif
#endif


#if (defined(__MMI_PHB_CALLER_VIDEO__) && defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__))
	#error "dependence conflict, __DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__ and __MMI_PHB_CALLER_VIDEO__ are NOT allowed to enable at the same time"
#endif


#if defined(CFG_MMI_MMS_V02_TEMPLATES_SUPPORT) && ((CFG_MMI_MMS_V02_TEMPLATES_SUPPORT == __ON__)||(CFG_MMI_MMS_V02_TEMPLATES_SUPPORT == __AUTO__)) && \
	(defined(MMS_SUPPORT) && defined(OBIGO_Q03C_MMS_V02))
	#ifndef __MMI_MMS_V02_TEMPLATES_SUPPORT__
	#define __MMI_MMS_V02_TEMPLATES_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_V01_TEMPLATES_SUPPORT__) || defined(__MMI_MMS_V02_TEMPLATES_SUPPORT__))
	#ifndef __MMI_MMS_TEMPLATE_SUPPORT__
	#define __MMI_MMS_TEMPLATE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_PREDEFINED_TEMPLATE) && ((CFG_MMI_MESSAGES_PREDEFINED_TEMPLATE == __ON__)||(CFG_MMI_MESSAGES_PREDEFINED_TEMPLATE == __AUTO__)) && \
	(defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
	#define __MMI_MESSAGES_PREDEFINED_TEMPLATE__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_USERDEFINED_TEMPLATE) && ((CFG_MMI_MESSAGES_USERDEFINED_TEMPLATE == __ON__)||(CFG_MMI_MESSAGES_USERDEFINED_TEMPLATE == __AUTO__)) && \
	(defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
	#define __MMI_MESSAGES_USERDEFINED_TEMPLATE__
	#endif
#endif


#if (defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__) || defined(__MMI_MESSAGES_USERDEFINED_TEMPLATE__))
	#ifndef __MMI_MESSAGES_TEMPLATE__
	#define __MMI_MESSAGES_TEMPLATE__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && ((defined(__MMI_MMS_TEMPLATE_SUPPORT__) && !defined(__MMI_MESSAGES_TEMPLATE__)) || (!defined(__MMI_MMS_TEMPLATE_SUPPORT__) && defined(__MMI_MESSAGES_TEMPLATE__))))
	#error "setting conflicts, please define __MMI_MMS_TEMPLATE_SUPPORT__ and __MMI_MESSAGES_TEMPLATE__ at the same time in COSMOS MMI package"
#endif


#if (defined(__GADGET_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__))
	#error "Google Gadget is no longer supported by PLUTO MMI"
#endif


#if (defined(__COSMOS_NO_USER_DRIVE__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
	#error "Cosmos no user drive feature can't support archive. Please turn off __COSMOS_NO_USER_DRIVE__ or trun off __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__"
#endif


#if (defined(__MMI_IME_V3__) && defined(__MMI_REDUCED_KEYPAD__) && (defined(CFG_MMI_IME_VK_TYPE_ALPHANUMERIC) && (CFG_MMI_IME_VK_TYPE_ALPHANUMERIC == __OFF__)) && (defined(CFG_MMI_IME_VK_TYPE_QWERTY) && (CFG_MMI_IME_VK_TYPE_QWERTY == __OFF__)))
	#error "please turn on VK on reduce keypad project"
#endif


#if defined(CFG_MMI_NCENTER_SUPPORT) && ((CFG_MMI_NCENTER_SUPPORT == __ON__)||(CFG_MMI_NCENTER_SUPPORT == __AUTO__)) && \
	(defined(__MMI_VUI_ENGINE__) && ((defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_FTE_SUPPORT__)) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_NCENTER_SUPPORT__
	#define __MMI_NCENTER_SUPPORT__
	#endif
#endif


#if (defined(__BACKGROUND_CALL_SUPPORT__))
	#if (!defined(__UCM_SUPPORT__))
	#error "please define __UCM_SUPPORT__ for __MMI_BACKGROUND_CALL__"
	#endif
	#ifndef __MMI_BACKGROUND_CALL__
	#define __MMI_BACKGROUND_CALL__
	#endif
#endif


#if (defined(__MMI_NCENTER_SUPPORT__) && (!defined(__MMI_BACKGROUND_CALL__)))
	#error "please define __MMI_BACKGROUND_CALL__ for __MMI_NCENTER_SUPPORT__"
#endif


#if (((__MMI_LIST_MENU_SMOOTH_SCROLLING__ == MENU_SMOOTH_SCROLLING_KEY) || (__MMI_LIST_MENU_SMOOTH_SCROLLING__ == MENU_SMOOTH_SCROLLING_PEN_AND_KEY)) && (!defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__) || (__MMI_UI_LIST_HIGHLIGHT_EFFECT_TYPE__ != HIGHLIGHT_EFFECT_SLIDE)))
	#error "The highlight list effect must be HIGHLIGHT_EFFECT_SLIDE when using smooth scrolling by key."
#endif


#if defined(CFG_MMI_SSO) && ((CFG_MMI_SSO == __ON__)||(CFG_MMI_SSO == __AUTO__)) && \
	(defined(__CLOUD_SUPPORT__))
	#ifndef __MMI_SSO__
	#define __MMI_SSO__
	#endif
#endif


#if (defined(__CLOUD_SUPPORT__) && !defined(__MMI_SSO__))
	#error "It should turn on __MMI_SSO__ or disable __CLOUD_SUPPORT__"
#endif


#if (defined(CFG_MMI_NCENTER_SUPPORT) && (CFG_MMI_NCENTER_SUPPORT == __OFF__) && defined(__COSMOS_MMI_PACKAGE__))
	#error "Dependence conflict, please turn on CFG_MMI_NCENTER_SUPPORT in COSMOS project"
#endif


#if defined(CFG_MMI_CONTACT_SLIM) && ((CFG_MMI_CONTACT_SLIM == __ON__)||(CFG_MMI_CONTACT_SLIM == __AUTO__))
	#ifndef __MMI_CONTACT_SLIM__
	#define __MMI_CONTACT_SLIM__
	#endif
#endif


#if defined(CFG_MMI_VCARD) && ((CFG_MMI_VCARD == __ON__)||(CFG_MMI_VCARD == __AUTO__)) && \
	(defined(__MMI_FILE_MANAGER__) && defined(__VCARD_SUPPORT__)) || (defined(__SYNCML_SUPPORT__)) && (!defined (__MMI_CONTACT_SLIM__))
	#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_FILE_MANAGER__))
	#error "setting conflicts, please define __MMI_FILE_MANAGER__ or undef __SYNCML_SUPPORT__"
	#endif
	#ifndef __MMI_VCARD__
	#define __MMI_VCARD__
	#endif
#endif


#if defined(CFG_MMI_MULTI_VCARD) && ((CFG_MMI_MULTI_VCARD == __ON__)||(CFG_MMI_MULTI_VCARD == __AUTO__)) && \
	((defined(__MULTI_VCARD_SUPPORT__) && defined(__MMI_VCARD__))&&  (!defined (__MMI_CONTACT_SLIM__) ))
	#ifndef __MMI_MULTI_VCARD__
	#define __MMI_MULTI_VCARD__
	#endif
#endif


#if (defined(__VCARD_CLOUD_SUPPORT__) && !defined(__MMI_MULTI_VCARD__))
	#error "Vcard cloud feature needs to enable __MMI_MULTI_VCARD__. Please turn off VCARD_CLOUD_SUPPORT or turn on CFG_MMI_VCARD and CFG_MMI_MULTI_VCARD"
#endif


#if (defined(__MMI_CLOUD_VPP_UPGRADE__))
	#error "__MMI_CLOUD_VPP_UPGRADE__ can only be turned on if sso & cloud plug-in are in 2 VPP files, there is only 1 VPP file in MTK deafult package, so enabling __MMI_SSO_VPP_UPGRADE__ is enough"
#endif


#if defined(CFG_MMI_SMS_TCARD_STORAGE_SUPPORT) && ((CFG_MMI_SMS_TCARD_STORAGE_SUPPORT == __ON__)||(CFG_MMI_SMS_TCARD_STORAGE_SUPPORT == __AUTO__)) && \
	(defined(SMS_TCARD_ENTRY) && (SMS_TCARD_ENTRY > 0))
	#ifndef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	#define __MMI_SMS_TCARD_STORAGE_SUPPORT__
	#endif
#endif


#if (defined(__MMI_SMS_TCARD_STORAGE_SUPPORT__) && !defined(__LOW_COST_SUPPORT_COMMON__))
	#error "SMS Tcard storage only support on SLIM project. Please turn off CFG_MMI_SMS_TCARD_STORAGE_SUPPORT or set LOW_COST_SUPPORT = COMMON"
#endif


#if defined(CFG_MMI_PHB_TCARD_STORAGE_SUPPORT) && ((CFG_MMI_PHB_TCARD_STORAGE_SUPPORT == __ON__)||(CFG_MMI_PHB_TCARD_STORAGE_SUPPORT == __AUTO__)) && \
	(defined(MAX_PHB_TCARD_ENTRY) && (MAX_PHB_TCARD_ENTRY > 0))
	#ifndef __MMI_PHB_TCARD_STORAGE_SUPPORT__
	#define __MMI_PHB_TCARD_STORAGE_SUPPORT__
	#endif
#endif


#if (defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__) && !defined(__LOW_COST_SUPPORT_COMMON__))
	#error "Contact Tcard storage only support on SLIM project. Please turn off CFG_MMI_PHB_TCARD_STORAGE_SUPPORT or set LOW_COST_SUPPORT = COMMON"
#endif


#if (defined(__MRE_BGMEM_SIZE__) && (__MRE_BGMEM_SIZE__ > 200) && (!defined(__MRE_BG_CONC_LAUNCHER__)))
	#error "Please define MRE_BG_CONC_LAUNCHER is TRUE"
#endif


#if (!defined(__CLOUD_SUPPORT__) && defined(__MMI_SSO__))
	#error "It should disable __MMI_SSO__ or enable __CLOUD_SUPPORT__"
#endif


#if (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__) && defined (__MMI_IME_V3__))
	#ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
	#define __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
	#endif
#endif


#if (defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_FTE_SUPPORT) && !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))
	#ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__
	#define __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__
	#endif
#endif


#if (defined(__MMI_MAINLCD_320X240__) && defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)))
	#error "320X240 does not support VK for IMEV2 & IMEV3,Please turn off HAND_WRITING in option.mak,and CFG_MMI_IME_VK_TYPE_QWERTY and CFG_MMI_IME_VK_TYPE_ALPHANUMERIC in mmi_featureswitch*.h"
#endif


#if defined(CFG_MMI_SSO_BACKGROUND_LOGIN) && ((CFG_MMI_SSO_BACKGROUND_LOGIN == __ON__)||(CFG_MMI_SSO_BACKGROUND_LOGIN == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)) || (defined(__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_SSO_BACKGROUND_LOGIN__
	#define __MMI_SSO_BACKGROUND_LOGIN__
	#endif
#endif


#if (!defined(__MMI_SSO_BACKGROUND_LOGIN__) && ((CFG_MMI_SSO_BACKGROUND_LOGIN == __ON__) || (CFG_MMI_SSO_BACKGROUND_LOGIN == __AUTO__)))
	#error "__MMI_SSO_BACKGROUND_LOGIN__ can only be turned on when __MMI_SSO__ or __SOCIAL_NETWORK_SUPPORT__ is on"
#endif


#if defined(CFG_MMI_DA_OMA_ICONURI_SUPPORT) && ((CFG_MMI_DA_OMA_ICONURI_SUPPORT == __ON__)||(CFG_MMI_DA_OMA_ICONURI_SUPPORT == __AUTO__)) && \
	(defined(__MMI_OMA_DD_DOWNLOAD__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_DA_OMA_ICONURI_SUPPORT__
	#define __MMI_DA_OMA_ICONURI_SUPPORT__
	#endif
#endif


#if (defined(__MMI_FILE_MANAGER__) && defined(__MMI_DA_OMA_ICONURI_SUPPORT__))
	#ifndef __MMI_FMGR_CUSTICON_SUPPORT__
	#define __MMI_FMGR_CUSTICON_SUPPORT__
	#endif
#endif


#if (defined(__MMI_DA_OMA_ICONURI_SUPPORT__) && !defined(__MMI_FMGR_CUSTICON_SUPPORT__))
	#error "__MMI_DA_OMA_ICONURI_SUPPORT__ requires __MMI_FMGR_CUSTICON_SUPPORT__"
#endif


#if defined(CFG_MMI_KEY_ONLY_NCENTER) && ((CFG_MMI_KEY_ONLY_NCENTER == __ON__)||(CFG_MMI_KEY_ONLY_NCENTER == __AUTO__)) && \
	(defined(__MMI_NCENTER_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_FTE_SUPPORT__)) || ((CFG_MMI_KEY_ONLY_NCENTER == __OFF__) && defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__))
	#ifndef __MMI_KEY_ONLY_NCENTER__
	#define __MMI_KEY_ONLY_NCENTER__
	#endif
#endif


#if (defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_KEY_ONLY_NCENTER__))
	#error "please define __MMI_TOUCH_SCREEN__ or __MMI_KEY_ONLY_NCENTER__ for __MMI_NCENTER_SUPPORT__"
#endif


#if defined(CFG_MMI_MESSAGE_SLIM) && ((CFG_MMI_MESSAGE_SLIM == __ON__)||(CFG_MMI_MESSAGE_SLIM == __AUTO__)) && \
	(defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_MESSAGE_SLIM__
	#define __MMI_MESSAGE_SLIM__
	#endif
#endif


#if defined(CFG_MMI_CCA_SUPPORT) && ((CFG_MMI_CCA_SUPPORT == __ON__)||(CFG_MMI_CCA_SUPPORT == __AUTO__)) && \
	(defined (__CCA_SUPPORT__))
	#ifndef __MMI_CCA_SUPPORT__
	#define __MMI_CCA_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PROV_MESSAGE_SUPPORT) && (CFG_MMI_PROV_MESSAGE_SUPPORT == __ON__) || \
	(CFG_MMI_PROV_MESSAGE_SUPPORT == __AUTO__ && !defined(__MMI_MESSAGE_SLIM__))
	#if (!defined(__MMI_CCA_SUPPORT__))
	#error "Dependence conflict, please make sure that OBIGO_FEATURE is not equal NONE and turn on CFG_MMI_CCA_SUPPORT if want to support provisioning feature"
	#endif
	#ifndef __MMI_PROV_MESSAGE_SUPPORT__
	#define __MMI_PROV_MESSAGE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PROV_IN_UM) && ((CFG_MMI_PROV_IN_UM == __ON__)||(CFG_MMI_PROV_IN_UM == __AUTO__)) && \
	(defined (__MMI_PROV_MESSAGE_SUPPORT__) && defined(__UM_FOLDER__))
	#ifndef __MMI_PROV_IN_UM__
	#define __MMI_PROV_IN_UM__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__CCA_SUPPORT__) && defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__))
	#error "Dependence conflict, please turn on CFG__MMI_PROV_MESSAGE_SUPPORT__ and CFG__MMI_PROV_IN_UM__ on COSMOS if want to support  provisioning feature"
#endif


#if (defined(SUPPORT_JSR_75_PIM) && (defined(__IJET_VM__) || defined(__NEMO_VM__)))
	#ifndef __MMI_JSR_75_PIM_SUPPORT__
	#define __MMI_JSR_75_PIM_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CALENDAR) && ((CFG_MMI_CALENDAR == __ON__)||(CFG_MMI_CALENDAR == __AUTO__)) && \
	(!defined(__COSMOS_MMI_PACKAGE__)) || (defined(__MMI_JSR_75_PIM_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_CALENDAR__
	#define __MMI_CALENDAR__
	#endif
#endif


#if (defined(__LOW_COST_SUPPORT_COMMON__) && (defined(__MMI_MAINLCD_96X64__)||defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X240__)|| defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_320X240__)))
	#ifndef __MMI_SLIM_IMG_RES__
	#define __MMI_SLIM_IMG_RES__
	#endif
#endif


#if defined(CFG_MMI_BASIC_UI_STYLE) && ((CFG_MMI_BASIC_UI_STYLE == __ON__)||(CFG_MMI_BASIC_UI_STYLE == __AUTO__)) && \
	(defined(__MMI_SLIM_IMG_RES__))
	#ifndef __MMI_BASIC_UI_STYLE__
	#define __MMI_BASIC_UI_STYLE__
	#endif
#endif


#if defined(CFG_MMI_FWUI_SLIM) && ((CFG_MMI_FWUI_SLIM == __ON__)||(CFG_MMI_FWUI_SLIM == __AUTO__))
	#ifndef __MMI_FWUI_SLIM__
	#define __MMI_FWUI_SLIM__
	#endif
#endif


#if ((defined(__MMI_BASIC_UI_STYLE__)||defined(__MMI_FWUI_SLIM__)) && (!defined(__MMI_FTE_SUPPORT__)) && (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)|| defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_96X64__))) ||\
	 (defined(__COSMOS_MMI_PACKAGE__) && defined(LOW_COST_SUPPORT))
	#ifndef __MMI_INLINE_SLIM__
	#define __MMI_INLINE_SLIM__
	#endif
#endif


#if defined(CFG_MMI_TODOLIST) && ((CFG_MMI_TODOLIST == __ON__)||(CFG_MMI_TODOLIST == __AUTO__)) && \
	(defined(__MMI_CALENDAR__) && !defined(__MMI_INLINE_SLIM__)) || (defined(__MMI_JSR_75_PIM_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_INLINE_SLIM__))
	#ifndef __MMI_TODOLIST__
	#define __MMI_TODOLIST__
	#endif
#endif


#if defined(CFG_MMI_VCALENDAR) && ((CFG_MMI_VCALENDAR == __ON__)||(CFG_MMI_VCALENDAR == __AUTO__)) && \
	((defined(__MMI_TODOLIST__) || defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_FILE_MANAGER__) || defined(__SYNCML_SUPPORT__)))
	#if (defined(__SYNCML_SUPPORT__) && !defined(__MMI_FILE_MANAGER__))
	#error "setting conflicts, please define __MMI_FILE_MANAGER__ or undef __SYNCML_SUPPORT__"
	#endif
	#ifndef __MMI_VCALENDAR__
	#define __MMI_VCALENDAR__
	#endif
#endif


#if (defined(__UNIFIED_COMPOSER_SUPPORT__))
	#ifndef __MMI_UNIFIED_COMPOSER__
	#define __MMI_UNIFIED_COMPOSER__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_VCARD__) || defined (__MMI_VCALENDAR__)) && !defined(__MMI_UNIFIED_COMPOSER__))
	#error "Dependence conflict, please turn on UNIFIED_MESSAGE_ADVANCE_FEATURE with composer if want to support Vcard or VCalendar in COSMOS"
#endif


#if defined(CFG_MMI_UCM_SLIM) && ((CFG_MMI_UCM_SLIM == __ON__)||(CFG_MMI_UCM_SLIM == __AUTO__))
	#ifndef __MMI_UCM_SLIM__
	#define __MMI_UCM_SLIM__
	#endif
#endif


#if (!defined(__MMI_UCM_SLIM__) && !defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && defined(__COSMOS_MMI_PACKAGE__))
	#error "setting conflicts, please define __MMI_VUI_SCREEN_LOCK_COSMOS__"
#endif


#if defined(CFG_MMI_VUI_WIDGET_VIP_CONTACT) && ((CFG_MMI_VUI_WIDGET_VIP_CONTACT == __ON__)||(CFG_MMI_VUI_WIDGET_VIP_CONTACT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_VIP_CONTACT__
	#define __MMI_VUI_WIDGET_VIP_CONTACT__
	#endif
#endif


#if (defined(__MMI_VUI_WIDGET_VIP_CONTACT__) && !defined(__UNIFIED_COMPOSER_SUPPORT__))
	#error "Dependence conflict, please turn on __UNIFIED_COMPOSER_SUPPORT__ if want to support VIP Contact"
#endif


#if (defined(__EMAIL__))
	#ifndef __MMI_EMAIL__
	#define __MMI_EMAIL__
	#endif
#endif


#if ((defined(__COSMOS_MMI_PACKAGE__) && defined (__MMI_EMAIL__) && defined(__LOW_COST_SUPPORT_COMMON__)) && (!defined(__UNIFIED_COMPOSER_SUPPORT__)))
	#error "Dependence conflict, please turn on UNIFIED_MESSAGE_ADVANCE_FEATURE with composer if want to support Email in COSMOS"
#endif


#if defined(CFG_MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT) && ((CFG_MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT == __ON__)||(CFG_MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__))
	#ifndef __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__
	#define __MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__
	#endif
#endif


#if ((defined(__COSMOS_MMI_PACKAGE__) && defined (__MMI_EMAIL__) && defined(__LOW_COST_SUPPORT_COMMON__) && defined(__UNIFIED_COMPOSER_SUPPORT__)) && (!defined(__MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT__)))
	#error "Dependence conflict, please turn on CFG_MMI_COSMOS_UC_VIDEO_SLIM_SUPPORT if want to support Email in COSMOS"
#endif


#if defined(CFG_MMI_GALLERY_SLIM) && ((CFG_MMI_GALLERY_SLIM == __ON__)||(CFG_MMI_GALLERY_SLIM == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_GALLERY_SLIM__
	#define __MMI_GALLERY_SLIM__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_GALLERY_SLIM__))
	#ifndef __MMI_FTO_GALLERY__
	#define __MMI_FTO_GALLERY__
	#endif
#endif


#if (defined(__MMI_FTO_GALLERY__) && !defined(__SQLITE3_SUPPORT__))
	#error "Setting conflict, Gallery none slim version need DB, please turn on SQLITE3_SUPPORT = TRUE in project.mak"
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__UNIFIED_COMPOSER_SUPPORT__) && !defined(__MMI_MESSAGE_SLIM__))
	#error "Dependence conflict, please turn on UNIFIED_MESSAGE_ADVANCE_FEATURE with composer while CFG_MMI_MESSAGE_SLIM is __OFF__"
#endif


#if defined(CFG_MMI_SEARCH_WEB_BAIDU) && ((CFG_MMI_SEARCH_WEB_BAIDU == __ON__)||(CFG_MMI_SEARCH_WEB_BAIDU == __AUTO__)) && \
	(defined(BROWSER_SUPPORT) && !defined(__MMI_MAINLCD_128X128__) && !defined(__GOOGLE_SEARCH_SUPPORT__))
	#ifndef __MMI_SEARCH_WEB_BAIDU__
	#define __MMI_SEARCH_WEB_BAIDU__
	#endif
#endif


#if defined(CFG_MMI_BAIDU_SEARCH_COSMOS) && ((CFG_MMI_BAIDU_SEARCH_COSMOS == __ON__)||(CFG_MMI_BAIDU_SEARCH_COSMOS == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_BAIDU_SEARCH_COSMOS__
	#define __MMI_BAIDU_SEARCH_COSMOS__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_BAIDU_SEARCH) && ((CFG_MMI_VUI_WIDGET_BAIDU_SEARCH == __ON__)||(CFG_MMI_VUI_WIDGET_BAIDU_SEARCH == __AUTO__)) && \
	(defined(__MMI_BAIDU_SEARCH_COSMOS__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) ||    defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_BAIDU_SEARCH__
	#define __MMI_VUI_WIDGET_BAIDU_SEARCH__
	#endif
#endif


#if (defined(BROWSER_SUPPORT) && !defined(__MMI_MAINLCD_128X128__) && defined(__GOOGLE_SEARCH_SUPPORT__))
	#ifndef __MMI_SEARCH_WEB_GOOGLE__
	#define __MMI_SEARCH_WEB_GOOGLE__
	#endif
#endif


#if (defined(__GOOGLE_SEARCH_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_GOOGLE_SEARCH_COSMOS__
	#define __MMI_GOOGLE_SEARCH_COSMOS__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_GOOGLE) && ((CFG_MMI_VUI_WIDGET_GOOGLE == __ON__)||(CFG_MMI_VUI_WIDGET_GOOGLE == __AUTO__)) && \
	(defined(__MMI_GOOGLE_SEARCH_COSMOS__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_GOOGLE__
	#define __MMI_VUI_WIDGET_GOOGLE__
	#endif
#endif


#if (defined(BROWSER_SUPPORT) && defined(__GUOBI_WINGUO_V2_SUPPORT__) && (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined(__MMI_SEARCH_WEB_GOOGLE__) || defined(__MMI_VUI_WIDGET_GOOGLE__))) ||\
	 ((!defined(BROWSER_SUPPORT)) && defined(__GUOBI_WINGUO_V2_SUPPORT__))
	#ifndef __MMI_GB_WINGUO_V2__
	#define __MMI_GB_WINGUO_V2__
	#endif
#endif


#if (defined(__MMI_GB_WINGUO_V2__) && !defined(__COSMOS_MMI_PACKAGE__))
	#error "Setting conflict, WINGUO_SLIM_V2 only support in cosmos package, please check GUOBI_WINGUO_SUPPORT in makefile"
#endif


#if (defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) && defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__))
	#error "cannot turn on __MMI_EDITOR_OPTION_MENU_STYLE_1__ and __MMI_EDITOR_OPTION_MENU_STYLE_2__ at the same time"
#endif


#if defined(CFG_MMI_RESOURCE_AUDIO_COMPRESS) && ((CFG_MMI_RESOURCE_AUDIO_COMPRESS == __ON__)||(CFG_MMI_RESOURCE_AUDIO_COMPRESS == __AUTO__))
	#ifndef __MMI_RESOURCE_AUDIO_COMPRESS__
	#define __MMI_RESOURCE_AUDIO_COMPRESS__
	#endif
#endif


#if (defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_AUDIO_COMPRESS__))
	#error "MMI Resource Compress(Audio) can not set to ON, when __MULTIPLE_BINARY_FILES__ is defined"
#endif


#if (defined (BROWSER_SUPPORT) && (defined(__GUOBI_WINGUO_SUPPORT__) && (!defined(__GB_WINGUO_4_U__)) && (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined(__MMI_SEARCH_WEB_GOOGLE__) || defined(__MMI_VUI_WIDGET_GOOGLE__)))) ||\
	 ((!defined(BROWSER_SUPPORT)) && defined(__GUOBI_WINGUO_SUPPORT__) && (!defined(__GB_WINGUO_4_U__)))
	#ifndef __MMI_GB_WINGUO__
	#define __MMI_GB_WINGUO__
	#endif
#endif


#if (defined(__GUOBI_WINGUO_SUPPORT__) && (!defined(__GB_WINGUO_4_U__)) && (!defined(__MMI_GB_WINGUO__))) ||\
	 (defined(__GUOBI_WINGUO_V2_SUPPORT__) && !defined(__MMI_GB_WINGUO_V2__))
	#error "WINGUO is not defined,Please turn on BROWSER_SUPPORT,and turn on Baidu or Google"
#endif


#if (defined(__NFB_THIRD_ROM_SUPPORT__))
	#ifndef __MMI_HANDWRITING_THIRD_ROM_SUPPORT__
	#define __MMI_HANDWRITING_THIRD_ROM_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_HANDWRITING_MEMORY_CARD_SUPPORT) && ((CFG_MMI_HANDWRITING_MEMORY_CARD_SUPPORT == __ON__)||(CFG_MMI_HANDWRITING_MEMORY_CARD_SUPPORT == __AUTO__)) && \
	(defined(__MMI_IME_V3__) || !defined(__MMI_FTE_SUPPORT__)) && (defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__
	#define __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__
	#endif
#endif


#if (defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__) && defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__))
	#error "Please turn off __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__ macro, for get better perfermance and lower risk."
#endif


#if (defined(BROWSER_SUPPORT) && (defined(__GUOBI_WINGUO_SUPPORT__) && (defined(__GB_WINGUO_4_U__)) && (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_VUI_WIDGET_BAIDU_SEARCH__) || defined(__MMI_SEARCH_WEB_GOOGLE__) || defined(__MMI_VUI_WIDGET_GOOGLE__)))) ||\
	 ((!defined(BROWSER_SUPPORT)) && defined(__GUOBI_WINGUO_SUPPORT__) && (defined(__GB_WINGUO_4_U__)))
	#ifndef __MMI_GB_WINGUO_ULTRA__
	#define __MMI_GB_WINGUO_ULTRA__
	#endif
#endif


#if (defined(BROWSER_SUPPORT) && (defined(__GUOBI_WINGUO_SUPPORT__)) && (defined(__GB_WINGUO_4_U__))&& (!defined(__MMI_GB_WINGUO_ULTRA__)))
	#error "WINGUO is not defined,If open BROWSER_SUPPORT,need turn on Baidu or Google ,or turn off BROWSER_SUPPORT"
#endif


#if defined(CFG_MMI_COSMOS_APP_MANAGER) && ((CFG_MMI_COSMOS_APP_MANAGER == __ON__)||(CFG_MMI_COSMOS_APP_MANAGER == __AUTO__))
	#ifndef __MMI_COSMOS_APP_MANAGER__
	#define __MMI_COSMOS_APP_MANAGER__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VUI_LAUNCHER_ROBOT__) && !defined(__MMI_COSMOS_APP_MANAGER__))
	#error "Please turn on __MMI_COSMOS_APP_MANAGER__ because robot launcher is enabled"
#endif


#if (defined(__BTVCSR_HCI_BCHS__) || defined(__BTMTK__))
	#ifndef __MMI_BT_SUPPORT__
	#define __MMI_BT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BT_DIALER_SUPPORT) && ((CFG_MMI_BT_DIALER_SUPPORT == __ON__)||(CFG_MMI_BT_DIALER_SUPPORT == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) && defined(__BT_DIALER_SUPPORT__))
	#ifndef __MMI_BT_DIALER_SUPPORT__
	#define __MMI_BT_DIALER_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_SPP_PROFILE__))
	#ifndef __MMI_SPP_SUPPORT__
	#define __MMI_SPP_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BT_DIALER_SUPPORT__) && defined(__XML_SUPPORT__) && defined(__MMI_SPP_SUPPORT__))
	#ifndef __MMI_BT_NOTI_SRV__
	#define __MMI_BT_NOTI_SRV__
	#endif
#endif


#if defined(CFG_MMI_BT_APPLICATION_BQB) && ((CFG_MMI_BT_APPLICATION_BQB == __ON__)||(CFG_MMI_BT_APPLICATION_BQB == __AUTO__))
	#ifndef __MMI_BT_APPLICATION_BQB__
	#define __MMI_BT_APPLICATION_BQB__
	#endif
#endif


#if defined(CFG_MMI_BT_MAPC_BY_SPP) && ((CFG_MMI_BT_MAPC_BY_SPP == __ON__)||(CFG_MMI_BT_MAPC_BY_SPP == __AUTO__)) && \
	(defined(__MMI_BT_NOTI_SRV__) && !defined(__MMI_BT_APPLICATION_BQB__))
	#ifndef __MMI_BT_MAPC_BY_SPP__
	#define __MMI_BT_MAPC_BY_SPP__
	#endif
#endif


#if (defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_BT_SUPPORT__) && defined(__BT_DIALER_SUPPORT__) && (defined(__BT_MAPC_PROFILE__) || defined(__MMI_BT_MAPC_BY_SPP__)))
	#ifndef __MMI_BT_MAP_CLIENT__
	#define __MMI_BT_MAP_CLIENT__
	#endif
#endif


#if (defined(__MMI_BT_MAP_CLIENT__) && (defined(__MMI_UM_CONVERSATION_BOX__) || defined(__MMI_UM_CONVERSATION_BOX_ENHANCE__)))
	#error "MMI_BT_MAP_CLIENT caonnot support conversation box. Please turn off CFG_MMI_UM_CONVERSATION_BOX,CFG_MMI_UM_CONVERSATION_BOX_ENHANCE or turn off BT_MAPC_PROFILE"
#endif


#if (defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_BT_SUPPORT__) && defined(__BT_DIALER_SUPPORT__) && defined(__BT_PBAP_CLIENT__))
	#if (!defined(__MULTI_VCARD_SUPPORT__))
	#error "Dependency conflicts, please turn on __MULTI_VCARD_SUPPORT__ if __MMI_BT_PBAP_CLIENT__ is turn on or turn off __MMI_BT_PBAP_CLIENT__"
	#endif
	#ifndef __MMI_BT_PBAP_CLIENT__
	#define __MMI_BT_PBAP_CLIENT__
	#endif
#endif


#if defined(CFG_MMI_CLOG_TAB_SUPPORT) && ((CFG_MMI_CLOG_TAB_SUPPORT == __ON__)||(CFG_MMI_CLOG_TAB_SUPPORT == __AUTO__)) && \
	(!defined(__MMI_BT_PBAP_CLIENT__))
	#ifndef __MMI_CLOG_TAB_SUPPORT__
	#define __MMI_CLOG_TAB_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PHB_QUICK_SEARCH) && ((CFG_MMI_PHB_QUICK_SEARCH == __ON__)||(CFG_MMI_PHB_QUICK_SEARCH == __AUTO__)) && \
	(((defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)) && (defined(__MMI_T9__) || defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_GUOBI__))) || (!(defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__))))
	#ifndef __MMI_PHB_QUICK_SEARCH__
	#define __MMI_PHB_QUICK_SEARCH__
	#endif
#endif


#if defined(CFG_MMI_PHB_UI_IN_TABS) && ((CFG_MMI_PHB_UI_IN_TABS == __ON__)||(CFG_MMI_PHB_UI_IN_TABS == __AUTO__)) && \
	(defined(__MMI_PHB_QUICK_SEARCH__))
	#ifndef __MMI_PHB_UI_IN_TABS__
	#define __MMI_PHB_UI_IN_TABS__
	#endif
#endif


#if defined(CFG_MMI_SNS_CENTER) && ((CFG_MMI_SNS_CENTER == __ON__)||(CFG_MMI_SNS_CENTER == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__) && (!defined(__FACEBOOK_SNS_SUPPORT__) && !defined(__TWITTER_SNS_SUPPORT__)))
	#ifndef __MMI_SNS_CENTER__
	#define __MMI_SNS_CENTER__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_SNS) && ((CFG_MMI_VUI_HOMESCREEN_SNS == __ON__)||(CFG_MMI_VUI_HOMESCREEN_SNS == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_VUI_HOMESCREEN_SNS__
	#define __MMI_VUI_HOMESCREEN_SNS__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_SNS_TABBAR) && ((CFG_MMI_VUI_WIDGET_SNS_TABBAR == __ON__)||(CFG_MMI_VUI_WIDGET_SNS_TABBAR == __AUTO__)) && \
	(defined (__MMI_VUI_HOMESCREEN_SNS__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_SNS_TABBAR__
	#define __MMI_VUI_WIDGET_SNS_TABBAR__
	#endif
#endif


#if (defined(__MTV_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_MOBILE_TV_CMMB_SUPPORT__
	#define __MMI_MOBILE_TV_CMMB_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_TAB_BARS_SUPPORT) && (CFG_MMI_TAB_BARS_SUPPORT == __ON__) || \
	(defined(__MMI_FTE_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_CLOG_TAB_SUPPORT__) || defined(__MMI_PHB_UI_IN_TABS__) || defined(__MMI_SNS_CENTER__) || defined(__MMI_VUI_WIDGET_SNS_TABBAR__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) || defined(__MMI_BT_DIALER_SUPPORT__) || defined(__MMI_EMAIL__))
	#ifndef __MMI_TAB_BARS_SUPPORT__
	#define __MMI_TAB_BARS_SUPPORT__
	#endif
#endif


#if (defined( __MMI_TOUCH_SCREEN__))
	#ifndef __MMI_TOUCH_DIAL_SCREEN__
	#define __MMI_TOUCH_DIAL_SCREEN__
	#endif
#endif


#if ((!defined(__MMI_TAB_BARS_SUPPORT__)) && (!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_TOUCH_SCREEN__)) && (!defined(__MMI_TOUCH_DIAL_SCREEN__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)))
	#ifndef __MMI_CATE_CM_TAB_BAR_SLIM__
	#define __MMI_CATE_CM_TAB_BAR_SLIM__
	#endif
#endif


#if (defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_UCM_PLUTO_BW__
	#define __MMI_UCM_PLUTO_BW__
	#endif
#endif


#if ((!defined(__MMI_TAB_BARS_SUPPORT__)) && (!defined(__MMI_CATE_CM_TAB_BAR_SLIM__)) && (!defined(__MMI_UCM_PLUTO_BW__)))
	#error "Dependence conflict, please turn on __MMI_TAB_BARS_SUPPORT__"
#endif


#if defined(CFG_MMI_LAUNCHER_APP_LIST) && ((CFG_MMI_LAUNCHER_APP_LIST == __ON__)||(CFG_MMI_LAUNCHER_APP_LIST == __AUTO__)) && \
	(defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_LAUNCHER_APP_LIST__
	#define __MMI_LAUNCHER_APP_LIST__
	#endif
#endif


#if (defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_LAUNCHER_APP_LIST__))
	#error "Setting conflicts, please turn off CFG_MMI_LAUNCHER_APP_LIST in BT dialer enabled project"
#endif


#if (defined(PGDL_SUPPORT) && !defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__))
	#error "When PGDL_SUPPORT is turned on, please turn on __MMI_DOWNLOAD_AGENT_MULTI_DL__"
#endif


#if defined(CFG_MMI_DA_RESUME) && ((CFG_MMI_DA_RESUME == __ON__)||(CFG_MMI_DA_RESUME == __AUTO__)) && \
	(defined(__MMI_DOWNLOAD_AGENT__) && defined(__HTTP_INTERFACE__) && defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__))
	#ifndef __MMI_DA_RESUME__
	#define __MMI_DA_RESUME__
	#endif
#endif


#if (defined(PGDL_SUPPORT) && !defined(__MMI_DA_RESUME__))
	#error "When PGDL_SUPPORT is turned on, please turn on __MMI_DA_RESUME__"
#endif


#if defined(CFG_MMI_LANG_CHSET_DEPENDENCE) && ((CFG_MMI_LANG_CHSET_DEPENDENCE == __ON__)||(CFG_MMI_LANG_CHSET_DEPENDENCE == __AUTO__))
	#ifndef __MMI_LANG_CHSET_DEPENDENCE__
	#define __MMI_LANG_CHSET_DEPENDENCE__
	#endif
#endif


#if defined(CFG_MMI_CHSET_HKSCS) && (CFG_MMI_CHSET_HKSCS == __ON__) || \
	(defined(CFG_MMI_CHSET_HKSCS) && (CFG_MMI_CHSET_HKSCS == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_HK_CHINESE__)))
	#ifndef __MMI_CHSET_HKSCS__
	#define __MMI_CHSET_HKSCS__
	#endif
#endif


#if defined(CFG_MMI_CHSET_BIG5) && (CFG_MMI_CHSET_BIG5 == __ON__) || \
	(defined(CFG_MMI_CHSET_BIG5) && (CFG_MMI_CHSET_BIG5 == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))))
	#ifndef __MMI_CHSET_BIG5__
	#define __MMI_CHSET_BIG5__
	#endif
#endif


#if (defined (__MMI_CHSET_HKSCS__) && !defined (__MMI_CHSET_BIG5__))
	#error "Please switch ON CFG_MMI_CHSET_BIG5 , if CFG_MMI_CHSET_HKSCS is kept ON or AUTO"
#endif


#if defined(CFG_MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT) && ((CFG_MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT == __ON__)||(CFG_MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT == __AUTO__)) && \
	(defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__
	#define __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__
	#endif
#endif


#if (defined(PGDL_SUPPORT) && !defined(__MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__))
	#error "When PGDL_SUPPORT is turned on, please turn on __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__"
#endif


#if defined(CFG_MMI_DA_CONF_PAGE_SLIM) && ((CFG_MMI_DA_CONF_PAGE_SLIM == __ON__)||(CFG_MMI_DA_CONF_PAGE_SLIM == __AUTO__)) && \
	(defined(__MMI_DOWNLOAD_AGENT__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_DA_CONF_PAGE_SLIM__
	#define __MMI_DA_CONF_PAGE_SLIM__
	#endif
#endif


#if (defined(PGDL_SUPPORT) && defined(__MMI_DA_CONF_PAGE_SLIM__))
	#error "When PGDL_SUPPORT is turned on, please turn off __MMI_DA_CONF_PAGE_SLIM__"
#endif


#if (defined(__MMI_UM_CONVERSATION_BOX__) && defined(__UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__))
	#error "UM Conversation box feature needs to disable UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT. Please turn off CFG_MMI_UM_CONVERSATION_BOX or turn off UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT"
#endif


#if (defined(__MMI_UM_CONVERSATION_BOX__) && !defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__))
	#error "UM Conversation box feature needs to enable UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE. Please turn off CFG_MMI_UM_CONVERSATION_BOX or turn on UNIFIED_MESSAGE_MARK_SEVERAL_FEATURE"
#endif


#if (defined(JPG_DECODE) && (defined(CAMERA_MODULE) || defined(ISP_SUPPORT)) && defined(__MMI_FILE_MANAGER__) && (defined(MP4_ENCODE) || defined(MJPG_ENCODE)) && defined (__CAMCORDER_SUPPORT__))
	#ifndef __MMI_CAMCORDER__
	#define __MMI_CAMCORDER__
	#endif
#endif


#if (defined(__MMI_CAMCORDER__) && (defined (__CAMCORDER_PACKAGE_STANDARD__) || defined (__CAMCORDER_PACKAGE_FULL__) || defined (__CAMCORDER_PACKAGE_CUSTOM__)))
	#ifndef __CAMCORDER_CAPMODE_ADDFRAME__
	#define __CAMCORDER_CAPMODE_ADDFRAME__
	#endif
#endif


#if (defined(__MMI_CAMCORDER__) && defined(__CAMCORDER_PACKAGE_FULL__))
	#ifndef __CAMCORDER_CAPMODE_BSS__
	#define __CAMCORDER_CAPMODE_BSS__
	#endif
#endif


#if (defined(__MMI_CAMCORDER__) && (defined(__CAMCORDER_PACKAGE_FULL__) || defined (__CAMCORDER_PACKAGE_CUSTOM__) ))
	#ifndef __CAMCORDER_CAPMODE_BURSTSHOT__
	#define __CAMCORDER_CAPMODE_BURSTSHOT__
	#endif
#endif


#if (defined(__MMI_CAMCORDER__) && (defined(__CAMCORDER_PACKAGE_FULL__) ||  defined (__CAMCORDER_PACKAGE_CUSTOM__)))
	#ifndef __CAMCORDER_CAPMODE_EBS__
	#define __CAMCORDER_CAPMODE_EBS__
	#endif
#endif


#if (defined(__UM_FOLDER__))
	#ifndef __MMI_MMS_IN_UM__
	#define __MMI_MMS_IN_UM__
	#endif
#endif


#if (defined(MMS_SUPPORT) && defined(__MMI_MMS_IN_UM__))
	#ifndef __MMI_MMS_BGSR_SUPPORT__
	#define __MMI_MMS_BGSR_SUPPORT__
	#endif
#endif


#if (defined(OBIGO_Q03C_MMS_V02) && defined(__MMI_MMS_BGSR_SUPPORT__ ))
	#ifndef __MMI_MMS_2__
	#define __MMI_MMS_2__
	#endif
#endif


#if defined(CFG_COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON) && ((CFG_COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON == __ON__)||(CFG_COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON == __AUTO__)) && \
	(defined(__MMI_MMS_2__))
	#ifndef __COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON__
	#define __COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON__
	#endif
#endif


#if defined(CFG_COSMOS_MUSICPLY_COVER_FLOW) && ((CFG_COSMOS_MUSICPLY_COVER_FLOW == __ON__)||(CFG_COSMOS_MUSICPLY_COVER_FLOW == __AUTO__)) && \
	(defined(__COSMOS_MUSICPLY__))
	#ifndef __COSMOS_MUSICPLY_COVER_FLOW__
	#define __COSMOS_MUSICPLY_COVER_FLOW__
	#endif
#endif


#if (defined(__COSMOS_MUSICPLY__) && !defined(MOTION_SENSOR_SUPPORT))
	#ifndef __COSMOS_MUSICPLY_COVER_FLOW_TOOLBAR__
	#define __COSMOS_MUSICPLY_COVER_FLOW_TOOLBAR__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_MUSIC_PLAYER) && ((CFG_MMI_VUI_WIDGET_MUSIC_PLAYER == __ON__)||(CFG_MMI_VUI_WIDGET_MUSIC_PLAYER == __AUTO__)) && \
	(defined(__COSMOS_MUSICPLY__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_MUSIC_PLAYER__
	#define __MMI_VUI_WIDGET_MUSIC_PLAYER__
	#endif
#endif


#if (defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__) && !defined(__LOW_COST_SUPPORT_COMMON__))
	#ifndef __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
	#define __COSMOS_WIDGET_MUSICPLY_COVER_SUPPORT__
	#endif
#endif


#if (defined(__BT_BOX_SUPPORT__))
	#ifndef __MMI_BTBOX_NOLCD__
	#define __MMI_BTBOX_NOLCD__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__) && !defined(__IOT__))
	#ifndef __MMI_FACTORY_MODE__
	#define __MMI_FACTORY_MODE__
	#endif
#endif


#if defined(CFG_DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP) && ((CFG_DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP == __ON__)||(CFG_DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP == __AUTO__)) && \
	(defined(__MMI_FACTORY_MODE__))
	#ifndef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
	#define __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
	#endif
#endif


#if defined(CFG_DISABLE_SHORTCUTS_IMPL) && ((CFG_DISABLE_SHORTCUTS_IMPL == __ON__)||(CFG_DISABLE_SHORTCUTS_IMPL == __AUTO__)) && \
	(!defined(__MMI_VUI_SHELL_SHORTCUTS__) && (CFG_DISABLE_SHORTCUTS_IMPL != __AUTO__)) || (defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_VUI_SHELL_SHORTCUTS__))
	#ifndef __DISABLE_SHORTCUTS_IMPL__
	#define __DISABLE_SHORTCUTS_IMPL__
	#endif
#endif


#if (defined(__DISABLE_SHORTCUTS_IMPL__) || defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_VUI_SHELL_SHORTCUTS__))
	#ifndef __DISABLE_SHORTCUTS_MENU__
	#define __DISABLE_SHORTCUTS_MENU__
	#endif
#endif


#if (defined(__GEMINI__) && (!defined(__SINGLE_SIM_MMI_ONLY__)))
	#ifndef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_MAINLCD_128X128__))
	#ifndef __DUAL_SIM_IDLE_TEXT_AT_SAME_POSITION__
/* under construction !*/
	#endif
#endif


#if (defined(__GEMINI__))
	#ifndef MMI_MAX_SIM_NUM
/* under construction !*/
	#endif
#else
	#ifndef MMI_MAX_SIM_NUM
	#define MMI_MAX_SIM_NUM	1
	#endif
#endif


#if (defined(__MMI_TOUCH_DIAL_SCREEN__) && (((defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)) && defined(__MMI_DUAL_SIM_MASTER__)) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
	#define __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
	#endif
#endif


#if (defined(__MMI_DUAL_SIM_MASTER__) && (MMI_MAX_SIM_NUM == 2) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
	#ifndef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
/* under construction !*/
	#endif
#endif


#if defined(CFG_EMS_DYNAMIC_SEG_NUM) && ((CFG_EMS_DYNAMIC_SEG_NUM == __ON__)||(CFG_EMS_DYNAMIC_SEG_NUM == __AUTO__)) && \
	(!defined(__MMI_UNIFIED_COMPOSER__))
	#ifndef __EMS_DYNAMIC_SEG_NUM__
	#define __EMS_DYNAMIC_SEG_NUM__
	#endif
#endif


#if defined(CFG_FMGR_CSK_FORWARD) && ((CFG_FMGR_CSK_FORWARD == __ON__)||(CFG_FMGR_CSK_FORWARD == __AUTO__)) && \
	(defined(__MMI_FILE_MANAGER__))
	#ifndef __FMGR_CSK_FORWARD__
	#define __FMGR_CSK_FORWARD__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) && !defined(__32_32_SEG__)&& !defined(__64_32_SEG__)&& !defined(__32_64_SEG__))
	#ifndef __FTE_NON_SLIM_RES__
	#define __FTE_NON_SLIM_RES__
	#endif
#endif


#if ((((defined(MT6223)|| defined(MT6268T) || defined(MT6223P)) && defined(LOW_COST_SUPPORT) && defined(__MMI_MAINLCD_128X128__)) || defined(__MMI_MAINLCD_128X64__)))
	#ifndef __GDI_MEMORY_PROFILE_1__
	#define __GDI_MEMORY_PROFILE_1__
	#endif
#endif


#if defined(CFG_GDI_MEMORY_PROFILE_2) && ((CFG_GDI_MEMORY_PROFILE_2 == __ON__)||(CFG_GDI_MEMORY_PROFILE_2 == __AUTO__)) && \
	(defined(__MMI_FTE_SUPPORT__) ||(CFG_GDI_MEMORY_PROFILE_2 == __AUTO__))
	#ifndef __GDI_MEMORY_PROFILE_2__
	#define __GDI_MEMORY_PROFILE_2__
	#endif
#endif


#if ((defined(__OP11_ATK__) || defined(__AUTO_ATK__)) && defined(__J2ME__))
	#ifndef __JAVA_MANAGER__
	#define __JAVA_MANAGER__
	#endif
#endif


#if defined(CFG_MMI_16X16_CHINESE_FONT) && ((CFG_MMI_16X16_CHINESE_FONT == __ON__)||(CFG_MMI_16X16_CHINESE_FONT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__))
	#ifndef __MMI_16X16_CHINESE_FONT__
	#define __MMI_16X16_CHINESE_FONT__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE) && ((CFG_MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE__
	#define __MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_CUBEWORLD) && ((CFG_MMI_3D_GAME_INTERGRAFX_CUBEWORLD == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_CUBEWORLD == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL))  && defined(__MMI_3D_GAME_INTERGRAFX__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_CUBEWORLD__
	#define __MMI_3D_GAME_INTERGRAFX_CUBEWORLD__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_JUMPEMPEROR) && ((CFG_MMI_3D_GAME_INTERGRAFX_JUMPEMPEROR == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_JUMPEMPEROR == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL))  && defined(__MMI_3D_GAME_INTERGRAFX__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_JUMPEMPEROR__
	#define __MMI_3D_GAME_INTERGRAFX_JUMPEMPEROR__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_NO_CG) && ((CFG_MMI_3D_GAME_INTERGRAFX_NO_CG == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_NO_CG == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_NO_CG__
	#define __MMI_3D_GAME_INTERGRAFX_NO_CG__
	#endif
#endif


#if defined(CFG_MMI_3D_GAME_INTERGRAFX_TANKFANTASY) && ((CFG_MMI_3D_GAME_INTERGRAFX_TANKFANTASY == __ON__)||(CFG_MMI_3D_GAME_INTERGRAFX_TANKFANTASY == __AUTO__)) && \
	((defined(INTERGRAFX_ENGINE_BASIC) || defined(INTERGRAFX_ENGINE_VALUED) || defined(INTERGRAFX_ENGINE_FULL))  && defined(__MMI_3D_GAME_INTERGRAFX__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_GAME_INTERGRAFX_TANKFANTASY__
	#define __MMI_3D_GAME_INTERGRAFX_TANKFANTASY__
	#endif
#endif


#if defined(CFG_MMI_3D_MEDIA_CENTER) && ((CFG_MMI_3D_MEDIA_CENTER == __ON__)||(CFG_MMI_3D_MEDIA_CENTER == __AUTO__)) && \
	((defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_3D_MEDIA_CENTER__
	#define __MMI_3D_MEDIA_CENTER__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_A2DP_PROFILE__))
	#ifndef __MMI_A2DP_SUPPORT__
	#define __MMI_A2DP_SUPPORT__
	#endif
#endif


#if (defined(__MMI_A2DP_SUPPORT__))
	#ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
	#define __MMI_A2DP_HIDE_BT_SETTINGS__
	#endif
#endif


#if (defined (__ACL_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_ACL_SUPPORT__
	#define __MMI_ACL_SUPPORT__
	#endif
#endif


#if (defined(__AGPS_USER_PLANE__) && defined(__SUPL_SUPPORT__) && defined(__MMI_CCA_SUPPORT__))
	#ifndef __MMI_AGPS_OTAP__
	#define __MMI_AGPS_OTAP__
	#endif
#endif


#if defined(CFG_MMI_ALARM_SLIM) && ((CFG_MMI_ALARM_SLIM == __ON__)||(CFG_MMI_ALARM_SLIM == __AUTO__))
	#ifndef __MMI_ALARM_SLIM__
	#define __MMI_ALARM_SLIM__
	#endif
#endif


#ifndef __MMI_ALM_SLIM_CUSTOMIZE_TONE_FROM_FMGR__
#define __MMI_ALM_SLIM_CUSTOMIZE_TONE_FROM_FMGR__
#endif


#ifndef __MMI_ALPHA_BLENDING__
#define __MMI_ALPHA_BLENDING__
#endif


#if defined(CFG_MMI_ANALOG_CLOCK) && ((CFG_MMI_ANALOG_CLOCK == __ON__)||(CFG_MMI_ANALOG_CLOCK == __AUTO__))
	#ifndef __MMI_ANALOG_CLOCK__
	#define __MMI_ANALOG_CLOCK__
	#endif
#endif


#ifndef __MMI_UI_CATEGORY_DIAL_TYPE_SEL__
#define __MMI_UI_CATEGORY_DIAL_TYPE_SEL__	DIAL_TYPE_DEFAULT
#endif


#if (defined(__MMI_UI_CATEGORY_DIAL_TYPE_SEL__) && (__MMI_UI_CATEGORY_DIAL_TYPE_SEL__ == DIAL_TYPE_ANIMATED) && !defined(__MMI_TOUCH_SCREEN__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__)))
	#ifndef __MMI_ANIMATED_DIAL__
	#define __MMI_ANIMATED_DIAL__
	#endif
#endif


#if defined(CFG_MMI_APP_ICON_FW_SUPPORT) && ((CFG_MMI_APP_ICON_FW_SUPPORT == __ON__)||(CFG_MMI_APP_ICON_FW_SUPPORT == __AUTO__)) && \
	(defined(__MMI_LAUNCHER_APP_LIST__))
	#ifndef __MMI_APP_ICON_FW_SUPPORT__
	#define __MMI_APP_ICON_FW_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MAINMENU_SPREAD_SUPPORT) && ((CFG_MMI_MAINMENU_SPREAD_SUPPORT == __ON__)||(CFG_MMI_MAINMENU_SPREAD_SUPPORT == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__) && !defined(__MMI_FTE_SUPPORT__)) || (defined (__MRE_SAL_PN__))
	#ifndef __MMI_MAINMENU_SPREAD_SUPPORT__
	#define __MMI_MAINMENU_SPREAD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_WEARABLE_DEVICE) && ((CFG_MMI_WEARABLE_DEVICE == __ON__)||(CFG_MMI_WEARABLE_DEVICE == __AUTO__))
	#ifndef __MMI_WEARABLE_DEVICE__
	#define __MMI_WEARABLE_DEVICE__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) || defined(__MMI_LAUNCHER_APP_LIST__) || defined(__MMI_WEARABLE_DEVICE__))
	#ifndef __MMI_APP_MANAGER_SUPPORT__
	#define __MMI_APP_MANAGER_SUPPORT__
	#endif
#endif


#if (defined(__MMI_LAUNCHER_APP_LIST__))
	#ifndef __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
	#define __MMI_APPLIST_APP_UNINSTALL_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_APPLIST_BARREL_SUPPORT) && ((CFG_MMI_APPLIST_BARREL_SUPPORT == __ON__)||(CFG_MMI_APPLIST_BARREL_SUPPORT == __AUTO__)) && \
	(defined(__MMI_LAUNCHER_APP_LIST__) && defined(G2D_SUPPORT))
	#ifndef __MMI_APPLIST_BARREL_SUPPORT__
	#define __MMI_APPLIST_BARREL_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_APPLIST_KEY_SUPPORT) && ((CFG_MMI_APPLIST_KEY_SUPPORT == __ON__)||(CFG_MMI_APPLIST_KEY_SUPPORT == __AUTO__)) && \
	(defined(__MMI_LAUNCHER_APP_LIST__)) || (defined(__MMI_LAUNCHER_APP_LIST__) && !defined(__MMI_TOUCH_SCREEN__))||( defined(__MMI_LAUNCHER_APP_LIST__) && defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_VECTOR_FONT_SUPPORT))
	#ifndef __MMI_APPLIST_KEY_SUPPORT__
	#define __MMI_APPLIST_KEY_SUPPORT__
	#endif
#endif


#if (defined(__MMI_LAUNCHER_APP_LIST__)&&defined(__MMI_MAINLCD_240X320__)&&!defined(__MMI_VECTOR_FONT_SUPPORT__))
	#ifndef __MMI_APPLIST_ONLY_ICON_SUPPORT__
	#define __MMI_APPLIST_ONLY_ICON_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_LANG_ARABIC) && ((CFG_MMI_LANG_ARABIC == __ON__)||(CFG_MMI_LANG_ARABIC == __AUTO__))
	#ifndef __MMI_LANG_ARABIC__
	#define __MMI_LANG_ARABIC__
	#endif
#endif


#if defined(CFG_MMI_LANG_PERSIAN) && ((CFG_MMI_LANG_PERSIAN == __ON__)||(CFG_MMI_LANG_PERSIAN == __AUTO__))
	#ifndef __MMI_LANG_PERSIAN__
	#define __MMI_LANG_PERSIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_URDU) && ((CFG_MMI_LANG_URDU == __ON__)||(CFG_MMI_LANG_URDU == __AUTO__))
	#ifndef __MMI_LANG_URDU__
	#define __MMI_LANG_URDU__
	#endif
#endif


#if (defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__))
	#ifndef __MMI_ARSHAPING_ENGINE__
	#define __MMI_ARSHAPING_ENGINE__
	#endif
#endif


#if defined(CFG_MMI_ASM_OOM_AUTO_KILL) && ((CFG_MMI_ASM_OOM_AUTO_KILL == __ON__)||(CFG_MMI_ASM_OOM_AUTO_KILL == __AUTO__)) && \
	(defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_ASM_OOM_AUTO_KILL__
	#define __MMI_ASM_OOM_AUTO_KILL__
	#endif
#endif


#if (defined(__GDI_MEMORY_PROFILE_2__) && defined(__ATV_SUPPORT__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_ATV_SUPPORT__
	#define __MMI_ATV_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_ATV_PHONE_DRIVE_SUPPORT) && ((CFG_MMI_ATV_PHONE_DRIVE_SUPPORT == __ON__)||(CFG_MMI_ATV_PHONE_DRIVE_SUPPORT == __AUTO__)) && \
	(defined (__MMI_ATV_SUPPORT__))
	#ifndef __MMI_ATV_PHONE_DRIVE_SUPPORT__
	#define __MMI_ATV_PHONE_DRIVE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_ATV_SLIM) && ((CFG_MMI_ATV_SLIM == __ON__)||(CFG_MMI_ATV_SLIM == __AUTO__)) && \
	(defined(__MMI_ATV_SUPPORT__))
	#ifndef __MMI_ATV_SLIM__
	#define __MMI_ATV_SLIM__
	#endif
#endif


#if (defined(__BES_BASS_SUPPORT__))
	#ifndef __MMI_AUDIO_BASS_ENHANCEMENT__
	#define __MMI_AUDIO_BASS_ENHANCEMENT__
	#endif
#endif


#if (!defined(__LOW_COST_SUPPORT_COMMON__))
	#ifndef __MMI_AUDIO_CRESCENDO_SUPPORT__
	#define __MMI_AUDIO_CRESCENDO_SUPPORT__
	#endif
#endif


#if (defined(__BES_EQ_SUPPORT__))
	#ifndef __MMI_AUDIO_EQUALIZER__
	#define __MMI_AUDIO_EQUALIZER__
	#endif
#endif


#if (defined(PGDL_SUPPORT))
	#ifndef __MMI_AUDIO_PDL__
	#define __MMI_AUDIO_PDL__
	#endif
#endif


#if (defined(__INTEGRATED_PLAYER__) || defined(__INTEGRATED_PLAYER_DB_VF__) || defined(__INTEGRATED_PLAYER_FTE_DB__) || defined(__INTEGRATED_PLAYER_DB__))
	#ifndef __MMI_MEDIA_PLAYER__
	#define __MMI_MEDIA_PLAYER__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER) && ((CFG_MMI_AUDIO_PLAYER == __ON__)||(CFG_MMI_AUDIO_PLAYER == __AUTO__)) && \
	(defined(DAF_DECODE) && !defined(MED_V_NOT_PRESENT) && defined(__MMI_FILE_MANAGER__) && !defined(__MMI_MEDIA_PLAYER__) &&    defined(__PLUTO_MMI_PACKAGE__) &&  !defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_AUDIO_PLAYER__
	#define __MMI_AUDIO_PLAYER__
	#endif
#endif


#if (defined(__MMI_MEDIA_PLAYER__))
	#ifndef __MMI_MEDIA_PLAYER_AUDIO__
	#define __MMI_MEDIA_PLAYER_AUDIO__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_SPECTRUM_DISPLAY) && ((CFG_MMI_AUDIO_SPECTRUM_DISPLAY == __ON__)||(CFG_MMI_AUDIO_SPECTRUM_DISPLAY == __AUTO__)) && \
	(defined(__SPECTRUM_DISPLAY_SUPPORT__) && (defined(__MMI_AUDIO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_AUDIO__) || defined(__A8BOX_SUPPORT__))&& (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_AUDIO_SPECTRUM_DISPLAY__
	#define __MMI_AUDIO_SPECTRUM_DISPLAY__
	#endif
#endif


#if (defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__A2DP_BLOCK_SPECTRUM__))
	#ifndef __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
	#define __MMI_AUDIO_PLAYER_A2DP_BLOCK_SPECTRUM__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__))
	#ifndef __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__
	#define __MMI_AUDIO_PLAYER_FTE_20_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_ANIMATION) && ((CFG_MMI_AUDIO_PLAYER_ANIMATION == __ON__)||(CFG_MMI_AUDIO_PLAYER_ANIMATION == __AUTO__)) && \
	(!defined(__MMI_SLIM_IMG_RES__) && (defined(__MMI_AUDIO_PLAYER__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))) || (defined(__MMI_MAINLCD_320X240__) && defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__))
	#ifndef __MMI_AUDIO_PLAYER_ANIMATION__
	#define __MMI_AUDIO_PLAYER_ANIMATION__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON) && ((CFG_MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON == __ON__)||(CFG_MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON == __AUTO__)) && \
	(defined(__MMI_AUDIO_PLAYER__))
	#ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
	#define __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_BT) && ((CFG_MMI_AUDIO_PLAYER_BT == __ON__)||(CFG_MMI_AUDIO_PLAYER_BT == __AUTO__)) && \
	(defined(__MMI_BT_DIALER_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__) && defined(__MMI_AUDIO_PLAYER__))
	#ifndef __MMI_AUDIO_PLAYER_BT__
	#define __MMI_AUDIO_PLAYER_BT__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO) && ((CFG_MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO == __ON__)||(CFG_MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO == __AUTO__)) && \
	(defined(__MMI_AUDIO_PLAYER__))
	#ifndef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
	#define __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_DETAILS_SUPPORT) && ((CFG_MMI_AUDIO_PLAYER_DETAILS_SUPPORT == __ON__)||(CFG_MMI_AUDIO_PLAYER_DETAILS_SUPPORT == __AUTO__)) && \
	(defined(__MMI_AUDIO_PLAYER__))
	#ifndef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
	#define __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY) && ((CFG_MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY == __ON__)||(CFG_MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY == __AUTO__)) && \
	(defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_MAINLCD_320X240__) && defined(__MMI_AUDIO_PLAYER_FTE_20_SUPPORT__))
	#ifndef __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
	#define __MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_LYRIC_DISPLAY) && ((CFG_MMI_AUDIO_PLAYER_LYRIC_DISPLAY == __ON__)||(CFG_MMI_AUDIO_PLAYER_LYRIC_DISPLAY == __AUTO__)) && \
	(defined(__MMI_AUDIO_PLAYER__) && !defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)&& (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
	#define __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
	#endif
#endif


#if (defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
	#define __MMI_AUDIO_PLAYER_LYRIC_SCREEN_BASED_ASM__
	#endif
#endif


#if (defined(__MMI_AUDIO_PLAYER__))
	#ifndef __MMI_AUDIO_PLAYER_SINGLE_LIST__
	#define __MMI_AUDIO_PLAYER_SINGLE_LIST__
	#endif
#endif


#if defined(CFG_MMI_AUDIO_PLAYER_ULTRA_SLIM) && ((CFG_MMI_AUDIO_PLAYER_ULTRA_SLIM == __ON__)||(CFG_MMI_AUDIO_PLAYER_ULTRA_SLIM == __AUTO__)) && \
	(defined(__MMI_AUDIO_PLAYER__))
	#ifndef __MMI_AUDIO_PLAYER_ULTRA_SLIM__
	#define __MMI_AUDIO_PLAYER_ULTRA_SLIM__
	#endif
#endif


#if (defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_BT_SUPPORT__) && defined(__BT_DIALER_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__))
	#ifndef __MMI_BT_SPEAKER_SUPPORT__
	#define __MMI_BT_SPEAKER_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BTD_BOX_UI_STYLE) && ((CFG_MMI_BTD_BOX_UI_STYLE == __ON__)||(CFG_MMI_BTD_BOX_UI_STYLE == __AUTO__)) && \
	(defined(__MMI_BT_SPEAKER_SUPPORT__))
	#ifndef __MMI_BTD_BOX_UI_STYLE__
	#define __MMI_BTD_BOX_UI_STYLE__
	#endif
#endif


#if (defined(__MMI_BTD_BOX_UI_STYLE__))
	#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	#define __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	#endif
#endif


#if ((defined(__MMI_AUDIO_PLAYER__) && (!defined(__MMI_AUDIO_PLAYER_ULTRA_SLIM__))&& (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) || defined(__MMI_SLIM_IMG_RES__)) && (!defined (__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)))
	#ifndef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
	#define __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
	#endif
#endif


#if (defined(__BES_LIVE_SUPPORT__))
	#ifndef __MMI_AUDIO_REVERB_EFFECT__
	#define __MMI_AUDIO_REVERB_EFFECT__
	#endif
#endif


#if (!defined(__BES_SURROUND_LSPK__) && defined(__BES_SURROUND_EARP__))
	#ifndef __MMI_AUDIO_SURROUND_BIND_EARPHONE__
	#define __MMI_AUDIO_SURROUND_BIND_EARPHONE__
	#endif
#endif


#if (defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__))
	#ifndef __MMI_AUDIO_SURROUND_EFFECT__
	#define __MMI_AUDIO_SURROUND_EFFECT__
	#endif
#endif


#if (defined(__BES_TS_SUPPORT__))
	#ifndef __MMI_AUDIO_TIME_STRETCH__
	#define __MMI_AUDIO_TIME_STRETCH__
	#endif
#endif


#if (defined (__MMI_AUDIO_PLAYER_ULTRA_SLIM__))
	#ifndef __MMI_AUDPLY_SINGLE_LAYER_SETTING__
	#define __MMI_AUDPLY_SINGLE_LAYER_SETTING__
	#endif
#endif


#if (defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_AUDPLY_WALK_PLAY__
	#define __MMI_AUDPLY_WALK_PLAY__
	#endif
#endif


#if (defined(__MMI_FILE_MANAGER__) && defined(AUD_REC_ENABLE) && !defined(__MMI_MAINLCD_128X64__) && !defined(__IOT__))
	#ifndef __MMI_SOUND_RECORDER__
	#define __MMI_SOUND_RECORDER__
	#endif
#endif


#if defined(CFG_MMI_AUTO_ANSWER_MACHINE) && ((CFG_MMI_AUTO_ANSWER_MACHINE == __ON__)||(CFG_MMI_AUTO_ANSWER_MACHINE == __AUTO__)) && \
	(defined(__UCM_SUPPORT__) && defined (BGSND_ENABLE) && defined (__MMI_SOUND_RECORDER__) && defined (__KEY_TONE_DETECTION__))
	#ifndef __MMI_AUTO_ANSWER_MACHINE__
	#define __MMI_AUTO_ANSWER_MACHINE__
	#endif
#endif


#if defined(CFG_MMI_AUTO_KEYPAD_LOCK) && ((CFG_MMI_AUTO_KEYPAD_LOCK == __ON__)||(CFG_MMI_AUTO_KEYPAD_LOCK == __AUTO__))
	#ifndef __MMI_AUTO_KEYPAD_LOCK__
	#define __MMI_AUTO_KEYPAD_LOCK__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_AVRCP_PROFILE__))
	#ifndef __MMI_AVRCP_SUPPORT__
	#define __MMI_AVRCP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_AZAAN_ALARM) && ((CFG_MMI_AZAAN_ALARM == __ON__)||(CFG_MMI_AZAAN_ALARM == __AUTO__))
	#ifndef __MMI_AZAAN_ALARM__
	#define __MMI_AZAAN_ALARM__
	#endif
#endif


#if (defined(__MMI_NCENTER_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_BACKGROUND_CALL_WITH_NCENTER__
	#define __MMI_BACKGROUND_CALL_WITH_NCENTER__
	#endif
#endif


#if (defined(__LCD_SUPPORT__))
	#ifndef __MMI_BACKLIGHT_SUPPORT__
	#define __MMI_BACKLIGHT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BDF_SW_COMPRESSION) && ((CFG_MMI_BDF_SW_COMPRESSION == __ON__)||(CFG_MMI_BDF_SW_COMPRESSION == __AUTO__)) && \
	(!defined(__IOT__))
	#ifndef __MMI_BDF_SW_COMPRESSION__
	#define __MMI_BDF_SW_COMPRESSION__
	#endif
#endif


#if (defined(BGSND_ENABLE) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_BG_SOUND_EFFECT__
	#define __MMI_BG_SOUND_EFFECT__
	#endif
#endif


#if defined(CFG_MMI_LANG_HEBREW) && ((CFG_MMI_LANG_HEBREW == __ON__)||(CFG_MMI_LANG_HEBREW == __AUTO__))
	#ifndef __MMI_LANG_HEBREW__
	#define __MMI_LANG_HEBREW__
	#endif
#endif


#if (defined(__MMI_LANG_HEBREW__) || defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_URDU__))
	#ifndef __MMI_BIDI_ALG__
	#define __MMI_BIDI_ALG__
	#endif
#endif


#if (defined(SUPPORT_JSR_75_PIM_MSA) && defined(SUPPORT_JSR_75_PIM))
	#ifndef __MMI_JSR_75_PIM_MSA_SUPPORT__
	#define __MMI_JSR_75_PIM_MSA_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PHB_BIRTHDAY_FIELD) && ((CFG_MMI_PHB_BIRTHDAY_FIELD == __ON__)||(CFG_MMI_PHB_BIRTHDAY_FIELD == __AUTO__)) && \
	(!defined(__MMI_CONTACT_SLIM__)) || (defined(__MMI_JSR_75_PIM_MSA_SUPPORT__))
	#ifndef __MMI_PHB_BIRTHDAY_FIELD__
	#define __MMI_PHB_BIRTHDAY_FIELD__
	#endif
#endif


#if defined(CFG_MMI_BIRTHDAY_REMINDER) && ((CFG_MMI_BIRTHDAY_REMINDER == __ON__)||(CFG_MMI_BIRTHDAY_REMINDER == __AUTO__)) && \
	(defined(__MMI_CALENDAR__) && defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_ADVANCED_TODO__))
	#ifndef __MMI_BIRTHDAY_REMINDER__
	#define __MMI_BIRTHDAY_REMINDER__
	#endif
#endif


#if defined(CFG_MMI_BOOTUP_DISK_CHECK_SLIM) && ((CFG_MMI_BOOTUP_DISK_CHECK_SLIM == __ON__)||(CFG_MMI_BOOTUP_DISK_CHECK_SLIM == __AUTO__))
	#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__
	#define __MMI_BOOTUP_DISK_CHECK_SLIM__
	#endif
#endif


#if defined(CFG_MMI_BOOTUP_MODE_SEL_SUPPORT) && ((CFG_MMI_BOOTUP_MODE_SEL_SUPPORT == __ON__)||(CFG_MMI_BOOTUP_MODE_SEL_SUPPORT == __AUTO__))
	#ifndef __MMI_BOOTUP_MODE_SEL_SUPPORT__
	#define __MMI_BOOTUP_MODE_SEL_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BOOTUP_SLIM) && ((CFG_MMI_BOOTUP_SLIM == __ON__)||(CFG_MMI_BOOTUP_SLIM == __AUTO__))
	#ifndef __MMI_BOOTUP_SLIM__
	#define __MMI_BOOTUP_SLIM__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_BPP_PROFILE__))
	#ifndef __MMI_BPP_SUPPORT__
	#define __MMI_BPP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRIEF_TEXT) && ((CFG_MMI_BRIEF_TEXT == __ON__)||(CFG_MMI_BRIEF_TEXT == __AUTO__))
	#ifndef __MMI_BRIEF_TEXT__
	#define __MMI_BRIEF_TEXT__
	#endif
#endif


#if (defined(OBIGO_Q05A) || defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_BROWSER_2__
	#define __MMI_BROWSER_2__
	#endif
#endif


#if (defined (__MMI_BROWSER_2__) && !defined (SLIM_WAP_MMS))
	#ifndef __MMI_BRW_ADVANCED_APP_FEATURES__
	#define __MMI_BRW_ADVANCED_APP_FEATURES__
	#endif
#endif


#if (defined(__MMI_BRW_ADVANCED_APP_FEATURES__))
	#ifndef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
	#define __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BROWSER_2__))
	#ifndef __MMI_VBOOKMARK__
	#define __MMI_VBOOKMARK__
	#endif
#endif


#if (defined (__MMI_BROWSER_2__) && defined (__MMI_VBOOKMARK__) && !defined (SLIM_WAP_MMS))
	#ifndef __MMI_BRW_BKM_FOLDER_SUPPORT__
	#define __MMI_BRW_BKM_FOLDER_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRW_SLIM_BOOKMARK_SUPPORT) && ((CFG_MMI_BRW_SLIM_BOOKMARK_SUPPORT == __ON__)||(CFG_MMI_BRW_SLIM_BOOKMARK_SUPPORT == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__) && defined(SLIM_WAP_MMS))
	#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
	#define __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRW_BKM_INTERFACE_SUPPORT) && ((CFG_MMI_BRW_BKM_INTERFACE_SUPPORT == __ON__)||(CFG_MMI_BRW_BKM_INTERFACE_SUPPORT == __AUTO__)) && \
	(!defined(OPERA_V11_BROWSER) && !defined(__MMI_BRW_SLIM_BOOKMARK_SUPPORT__))
	#ifndef __MMI_BRW_BKM_INTERFACE_SUPPORT__
	#define __MMI_BRW_BKM_INTERFACE_SUPPORT__
	#endif
#endif


#if (defined (__MMI_BRW_ADVANCED_APP_FEATURES__))
	#ifndef __MMI_BRW_BOOKMARK_IN_FMGR__
	#define __MMI_BRW_BOOKMARK_IN_FMGR__
	#endif
#endif


#if defined(CFG_MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH) && ((CFG_MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH == __ON__)||(CFG_MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH__
	#define __MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH__
	#endif
#endif


#if defined(CFG_MMI_BRW_DISABLE_PUSH_URL_DISPLAY) && ((CFG_MMI_BRW_DISABLE_PUSH_URL_DISPLAY == __ON__)||(CFG_MMI_BRW_DISABLE_PUSH_URL_DISPLAY == __AUTO__)) && \
	(defined(OBIGO_Q05A) && defined(__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
	#define __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
	#endif
#endif


#if defined(CFG_MMI_BRW_FILE_UPLOAD_SUPPORT) && (CFG_MMI_BRW_FILE_UPLOAD_SUPPORT == __ON__) || \
	(!defined (SLIM_WAP_MMS)&& defined(__MMI_BROWSER_2__))
	#if (!defined(__MMI_BROWSER_2__))
	#error "Please chage BROWSER_SUPPORT as OBIGO_Q03C or OBIGO_Q05A or turn off CFG_MMI_BRW_FILE_UPLOAD_SUPPORT"
	#endif
	#ifndef __MMI_BRW_FILE_UPLOAD_SUPPORT__
	#define __MMI_BRW_FILE_UPLOAD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRW_IMG_RES_SLIM) && ((CFG_MMI_BRW_IMG_RES_SLIM == __ON__)||(CFG_MMI_BRW_IMG_RES_SLIM == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_IMG_RES_SLIM__
	#define __MMI_BRW_IMG_RES_SLIM__
	#endif
#endif


#if defined(CFG_MMI_BRW_PAGE_FETCHING_STATUS) && ((CFG_MMI_BRW_PAGE_FETCHING_STATUS == __ON__)||(CFG_MMI_BRW_PAGE_FETCHING_STATUS == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_PAGE_FETCHING_STATUS__
	#define __MMI_BRW_PAGE_FETCHING_STATUS__
	#endif
#endif


#if (defined(OBIGO_Q05A))
	#ifndef __MMI_BRW_POST_SESSION_INFO__
	#define __MMI_BRW_POST_SESSION_INFO__
	#endif
#endif


#if defined(CFG_MMI_BRW_PUSH_CONNECT_CONF) && ((CFG_MMI_BRW_PUSH_CONNECT_CONF == __ON__)||(CFG_MMI_BRW_PUSH_CONNECT_CONF == __AUTO__)) && \
	(defined(WAP_SUPPORT))
	#ifndef __MMI_BRW_PUSH_CONNECT_CONF__
	#define __MMI_BRW_PUSH_CONNECT_CONF__
	#endif
#endif


#if defined(CFG_MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT) && ((CFG_MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT == __ON__)||(CFG_MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT == __AUTO__)) && \
	(defined(WAP_SUPPORT))
	#ifndef __MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT__
	#define __MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT__
	#endif
#endif


#if (defined(__WAP_PUSH_SUPPORT__) && !defined(__SLIM_PUSH_FEATURE_SUPPORT__))
	#ifndef __MMI_WAP_PUSH_WHITE_LIST__
	#define __MMI_WAP_PUSH_WHITE_LIST__
	#endif
#endif


#if defined(CFG_MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT) && ((CFG_MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT == __ON__)||(CFG_MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT == __AUTO__)) && \
	(defined(__MMI_CCA_SUPPORT__) && defined(__MMI_WAP_PUSH_WHITE_LIST__) && defined(__FULL_PUSH_FEATURE_SUPPORT__))
	#ifndef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
	#define __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRW_RECENT_PAGES_SLIM) && ((CFG_MMI_BRW_RECENT_PAGES_SLIM == __ON__)||(CFG_MMI_BRW_RECENT_PAGES_SLIM == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	#define __MMI_BRW_RECENT_PAGES_SLIM__
	#endif
#endif


#if (defined (__MMI_BROWSER_2__) && (defined (__GOOGLE_SEARCH_SUPPORT__) || defined(__MMI_SEARCH_WEB_BAIDU__)) && !defined (SLIM_WAP_MMS))
	#ifndef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
	#define __MMI_BRW_SEARCH_HISTORY_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRW_SEND_ADDRESS_SLIM) && ((CFG_MMI_BRW_SEND_ADDRESS_SLIM == __ON__)||(CFG_MMI_BRW_SEND_ADDRESS_SLIM == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
	#define __MMI_BRW_SEND_ADDRESS_SLIM__
	#endif
#endif


#if defined(CFG_MMI_BRW_SLIM) && ((CFG_MMI_BRW_SLIM == __ON__)||(CFG_MMI_BRW_SLIM == __AUTO__)) && \
	(defined (__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_SLIM__
	#define __MMI_BRW_SLIM__
	#endif
#endif


#if (((defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) || defined(__COSMOS_MMI_PACKAGE__))&& defined (__MMI_BROWSER_2__))
	#ifndef __MMI_BRW_SMOOTH_SCROLLING_SUPPORT__
	#define __MMI_BRW_SMOOTH_SCROLLING_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY) && ((CFG_MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY == __ON__)||(CFG_MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__))
	#ifndef __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
	#define __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
	#endif
#endif


#if defined(CFG_MMI_BRW_URL_AUTO_COMPLETION) && ((CFG_MMI_BRW_URL_AUTO_COMPLETION == __ON__)||(CFG_MMI_BRW_URL_AUTO_COMPLETION == __AUTO__)) && \
	(defined(__MMI_BROWSER_2__)&& defined(__MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__)) || (defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
	#ifndef __MMI_BRW_URL_AUTO_COMPLETION__
	#define __MMI_BRW_URL_AUTO_COMPLETION__
	#endif
#endif


#if defined(CFG_MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM) && ((CFG_MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM == __ON__)||(CFG_MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM == __AUTO__))
	#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
	#define __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
	#endif
#endif


#if (defined(__MMI_BTD_BOX_UI_STYLE__))
	#ifndef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
	#define __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
	#endif
#endif


#if defined(CFG_MMI_BT_ANTI_LOST_BY_RSSI) && ((CFG_MMI_BT_ANTI_LOST_BY_RSSI == __ON__)||(CFG_MMI_BT_ANTI_LOST_BY_RSSI == __AUTO__)) && \
	(defined(__MMI_BT_DIALER_SUPPORT__))
	#ifndef __MMI_BT_ANTI_LOST_BY_RSSI__
	#define __MMI_BT_ANTI_LOST_BY_RSSI__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_HFG_PROFILE__))
	#ifndef __MMI_HFP_SUPPORT__
	#define __MMI_HFP_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_DIALER_SUPPORT__) && defined(__BT_HF_PROFILE__))
	#ifndef __MMI_HF_SUPPORT__
	#define __MMI_HF_SUPPORT__
	#endif
#endif


#if (defined(__MMI_A2DP_SUPPORT__) || defined(__MMI_HFP_SUPPORT__ ) || defined(__MMI_HF_SUPPORT__))
	#ifndef __MMI_BT_AUDIO_SUPPORT__
	#define __MMI_BT_AUDIO_SUPPORT__
	#endif
#endif


#if (defined(__BT_AUDIO_VIA_SCO__) && defined(__MMI_HFP_SUPPORT__))
	#ifndef __MMI_BT_AUDIO_VIA_SCO__
	#define __MMI_BT_AUDIO_VIA_SCO__
	#endif
#endif


#if defined(CFG_MMI_BT_SLIM) && ((CFG_MMI_BT_SLIM == __ON__)||(CFG_MMI_BT_SLIM == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__))
	#ifndef __MMI_BT_SLIM__
	#define __MMI_BT_SLIM__
	#endif
#endif


#if defined(CFG_MMI_BT_AUTHORIZE) && ((CFG_MMI_BT_AUTHORIZE == __ON__)||(CFG_MMI_BT_AUTHORIZE == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) && !defined(__MMI_BT_SLIM__))
	#ifndef __MMI_BT_AUTHORIZE__
	#define __MMI_BT_AUTHORIZE__
	#endif
#endif


#if defined(CFG_MMI_BT_AUTO_POWER_SWITCH) && ((CFG_MMI_BT_AUTO_POWER_SWITCH == __ON__)||(CFG_MMI_BT_AUTO_POWER_SWITCH == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__))
	#ifndef __MMI_BT_AUTO_POWER_SWITCH__
	#define __MMI_BT_AUTO_POWER_SWITCH__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_AVRCP_V13__))
	#ifndef __MMI_BT_AVRCP_V13__
	#define __MMI_BT_AVRCP_V13__
	#endif
#endif


#if defined(CFG_MMI_BTBOX_KEYBOARD_STYLE) && ((CFG_MMI_BTBOX_KEYBOARD_STYLE == __ON__)||(CFG_MMI_BTBOX_KEYBOARD_STYLE == __AUTO__)) && \
	(defined(__BTBOX_KEYBOARD_STYLE__))
	#ifndef __MMI_BTBOX_KEYBOARD_STYLE__
	#define __MMI_BTBOX_KEYBOARD_STYLE__
	#endif
#endif


#if (defined(__MMI_BTBOX_KEYBOARD_STYLE__))
	#ifndef __MMI_BT_BOX_MULTIMEDIA_CAT_STYLE__
	#define __MMI_BT_BOX_MULTIMEDIA_CAT_STYLE__
	#endif
#endif


#if (defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_BT_BTBOX_NOLCD__
	#define __MMI_BT_BTBOX_NOLCD__
	#endif
#endif


#if (defined(__MMI_HF_SUPPORT__) && defined(__MMI_BT_DIALER_SUPPORT__))
	#ifndef __MMI_BT_CALL_SUPPORT__
	#define __MMI_BT_CALL_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_OPP_PROFILE__))
	#ifndef __MMI_OPP_SUPPORT__
	#define __MMI_OPP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BT_DEF_SEND_DEVICE) && ((CFG_MMI_BT_DEF_SEND_DEVICE == __ON__)||(CFG_MMI_BT_DEF_SEND_DEVICE == __AUTO__)) && \
	(defined(__MMI_OPP_SUPPORT__))
	#ifndef __MMI_BT_DEF_SEND_DEVICE__
	#define __MMI_BT_DEF_SEND_DEVICE__
	#endif
#endif


#if (defined(__BT_FM_VIA_SCO__) && defined(__MMI_HFP_SUPPORT__))
	#ifndef __MMI_BT_FM_VIA_SCO__
	#define __MMI_BT_FM_VIA_SCO__
	#endif
#endif


#if defined(CFG_MMI_BT_IN_FLIGHT_MODE) && ((CFG_MMI_BT_IN_FLIGHT_MODE == __ON__)||(CFG_MMI_BT_IN_FLIGHT_MODE == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) && defined(__FLIGHT_MODE_SUPPORT__) && !defined(__MMI_BT_SLIM__)) || (defined(__BT_DIALER_PACKAGE) || defined(__MMI_BT_DIALER_SUPPORT__))
	#ifndef __MMI_BT_IN_FLIGHT_MODE__
	#define __MMI_BT_IN_FLIGHT_MODE__
	#endif
#endif


#if defined(CFG_MMI_ENGINEER_MODE) && ((CFG_MMI_ENGINEER_MODE == __ON__)||(CFG_MMI_ENGINEER_MODE == __AUTO__)) && \
	(!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_ENGINEER_MODE__
	#define __MMI_ENGINEER_MODE__
	#endif
#endif


#if defined(CFG_MMI_SLIM_ENGINEER_MODE) && ((CFG_MMI_SLIM_ENGINEER_MODE == __ON__)||(CFG_MMI_SLIM_ENGINEER_MODE == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_SLIM_ENGINEER_MODE__
	#define __MMI_SLIM_ENGINEER_MODE__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(__BT_HIDD_PROFILE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && !defined(__MMI_BT_SLIM__))
	#ifndef __MMI_EM_BT_BQB_HID_SUPPORT__
	#define __MMI_EM_BT_BQB_HID_SUPPORT__
	#endif
#endif


#if (defined (__MMI_EM_BT_BQB_HID_SUPPORT__))
	#ifndef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
	#define __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_BT_MUSIC) && ((CFG_MMI_BT_MUSIC == __ON__)||(CFG_MMI_BT_MUSIC == __AUTO__)) && \
	(defined(__MMI_BT_DIALER_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__) && !defined(__MMI_AUDIO_PLAYER_BT__))
	#ifndef __MMI_BT_MUSIC__
	#define __MMI_BT_MUSIC__
	#endif
#endif


#if (defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_BT_MUSIC_NOLCD__
	#define __MMI_BT_MUSIC_NOLCD__
	#endif
#endif


#if defined(CFG_MMI_BT_NOTIFICATION) && ((CFG_MMI_BT_NOTIFICATION == __ON__)||(CFG_MMI_BT_NOTIFICATION == __AUTO__)) && \
	(defined(__MMI_BT_DIALER_SUPPORT__) && defined(__XML_SUPPORT__) && defined(__MMI_SPP_SUPPORT__))
	#ifndef __MMI_BT_NOTIFICATION__
	#define __MMI_BT_NOTIFICATION__
	#endif
#endif


#if defined(CFG_MMI_BT_RECV_FDR_SWITCH) && ((CFG_MMI_BT_RECV_FDR_SWITCH == __ON__)||(CFG_MMI_BT_RECV_FDR_SWITCH == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) && (defined(__BT_FTC_PROFILE__) || defined(__BT_OPP_PROFILE__) || defined(__BT_BIP_PROFILE__))  &&  !defined(__MMI_BT_SLIM__))
	#ifndef __MMI_BT_RECV_FDR_SWITCH__
	#define __MMI_BT_RECV_FDR_SWITCH__
	#endif
#endif


#if defined(CFG_MMI_BT_RECV_OBJ_DETAIL) && ((CFG_MMI_BT_RECV_OBJ_DETAIL == __ON__)||(CFG_MMI_BT_RECV_OBJ_DETAIL == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) && (defined(__BT_OPP_PROFILE__) || defined(__BT_BIP_PROFILE__)) && !defined(__MMI_BT_SLIM__))
	#ifndef __MMI_BT_RECV_OBJ_DETAIL__
	#define __MMI_BT_RECV_OBJ_DETAIL__
	#endif
#endif


#if defined(CFG_MMI_BT_REMOTE_CAPTURE) && ((CFG_MMI_BT_REMOTE_CAPTURE == __ON__)||(CFG_MMI_BT_REMOTE_CAPTURE == __AUTO__)) && \
	(defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_BT_NOTI_SRV__))
	#ifndef __MMI_BT_REMOTE_CAPTURE__
	#define __MMI_BT_REMOTE_CAPTURE__
	#endif
#endif


#if defined(CFG_MMI_BT_RX_ENHANCE) && ((CFG_MMI_BT_RX_ENHANCE == __ON__)||(CFG_MMI_BT_RX_ENHANCE == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) && defined(__BT_OPP_PROFILE__) && (!defined(__LOW_COST_SUPPORT_COMMON__)))
	#ifndef __MMI_BT_RX_ENHANCE__
	#define __MMI_BT_RX_ENHANCE__
	#endif
#endif


#if defined(CFG_MMI_BT_TEMP_VISIBILITY) && ((CFG_MMI_BT_TEMP_VISIBILITY == __ON__)||(CFG_MMI_BT_TEMP_VISIBILITY == __AUTO__)) && \
	((defined(__MMI_BT_SUPPORT__) && !defined(__MMI_BT_SLIM__)) || defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_BT_TEMP_VISIBILITY__
	#define __MMI_BT_TEMP_VISIBILITY__
	#endif
#endif


#if (defined(__MMI_BTBOX_KEYBOARD_STYLE__) && (defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)))
	#ifndef __MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__
	#define __MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__
	#endif
#endif


#if defined(CFG_MMI_CABC) && ((CFG_MMI_CABC == __ON__)||(CFG_MMI_CABC == __AUTO__))
	#ifndef __MMI_CABC__
	#define __MMI_CABC__
	#endif
#endif


#if defined(CFG_MMI_CAL_SLIM) && ((CFG_MMI_CAL_SLIM == __ON__)||(CFG_MMI_CAL_SLIM == __AUTO__))
	#if (defined(__MMI_VCALENDAR__))
	#error "Dependency conflicts, please turnoff __MMI_VCALENDAR__ if __MMI_CAL_SLIM__ is turn on or turnoff __MMI_CAL_SLIM__ "
	#endif
	#ifndef __MMI_CAL_SLIM__
	#define __MMI_CAL_SLIM__
	#endif
#endif


#if defined(CFG_MMI_CALCULATOR) && ((CFG_MMI_CALCULATOR == __ON__)||(CFG_MMI_CALCULATOR == __AUTO__)) && \
	(!defined(__MMI_MRE_CALCULATOR__))
	#ifndef __MMI_CALCULATOR__
	#define __MMI_CALCULATOR__
	#endif
#endif


#if defined(CFG_MMI_CALENDAR_EVENT) && ((CFG_MMI_CALENDAR_EVENT == __ON__)||(CFG_MMI_CALENDAR_EVENT == __AUTO__)) && \
	(defined(__MMI_CALENDAR__) && !defined(__MMI_INLINE_SLIM__)) || (defined(__MMI_TODOLIST__) && !defined(__MMI_INLINE_SLIM__))
	#ifndef __MMI_CALENDAR_EVENT__
	#define __MMI_CALENDAR_EVENT__
	#endif
#endif


#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
	#ifndef __MMI_CALENDAR_IDLESCREEN_DEFAULT__
	#define __MMI_CALENDAR_IDLESCREEN_DEFAULT__	1
	#endif
#else
	#ifndef __MMI_CALENDAR_IDLESCREEN_DEFAULT__
	#define __MMI_CALENDAR_IDLESCREEN_DEFAULT__	0
	#endif
#endif


#if defined(CFG_MMI_CALENDAR_ON_IDLE_SCREEN) && ((CFG_MMI_CALENDAR_ON_IDLE_SCREEN == __ON__)||(CFG_MMI_CALENDAR_ON_IDLE_SCREEN == __AUTO__)) && \
	((((defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__)) && defined(__MMI_CALENDAR__) && ( defined(__MMI_VUI_HOMESCREEN__) || !defined(__MMI_DUAL_SIM_MASTER__))) || (defined(__MMI_MAINLCD_320X240__) && defined(__MMI_CALENDAR__) && defined(__MMI_VUI_HOMESCREEN__)) || (defined(__MMI_CALENDAR__) && ((defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)) && !defined(__MMI_OP11_HOMESCREEN_US__)))))
	#ifndef __MMI_CALENDAR_ON_IDLE_SCREEN__
	#define __MMI_CALENDAR_ON_IDLE_SCREEN__
	#endif
#endif


#if (defined(__UCM_SUPPORT__))
	#ifndef __MMI_UCM__
	#define __MMI_UCM__
	#endif
#endif


#if defined(CFG_MMI_CALL_INDICATOR) && ((CFG_MMI_CALL_INDICATOR == __ON__)||(CFG_MMI_CALL_INDICATOR == __AUTO__)) && \
	(defined(__MMI_UCM__)) || (defined(__MMI_BACKGROUND_CALL__))
	#ifndef __MMI_CALL_INDICATOR__
	#define __MMI_CALL_INDICATOR__
	#endif
#endif


#if defined(CFG_MMI_CALLSET_SLIM) && ((CFG_MMI_CALLSET_SLIM == __ON__)||(CFG_MMI_CALLSET_SLIM == __AUTO__))
	#ifndef __MMI_CALLSET_SLIM__
	#define __MMI_CALLSET_SLIM__
	#endif
#endif


#if (!defined(__MMI_CALLSET_SLIM__) && !defined(__OP01_FWPBW__))
	#ifndef __MMI_CALLSET_AUTO_REDIAL__
	#define __MMI_CALLSET_AUTO_REDIAL__
	#endif
#endif


#if (!defined(__MMI_CALLSET_SLIM__))
	#ifndef __MMI_CALLSET_CALL_BARRING__
	#define __MMI_CALLSET_CALL_BARRING__
	#endif
#endif


#if defined(CFG_MMI_CALLSET_CALLER_ID) && ((CFG_MMI_CALLSET_CALLER_ID == __ON__)||(CFG_MMI_CALLSET_CALLER_ID == __AUTO__))
	#ifndef __MMI_CALLSET_CALLER_ID__
	#define __MMI_CALLSET_CALLER_ID__
	#endif
#endif


#if (!defined(__MMI_CALLSET_SLIM__) && !defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_CALLSET_CALLTIME_REMINDER__
	#define __MMI_CALLSET_CALLTIME_REMINDER__
	#endif
#endif


#if defined(CFG_MMI_CALLSET_CTD_CONFIGURABLE) && ((CFG_MMI_CALLSET_CTD_CONFIGURABLE == __ON__)||(CFG_MMI_CALLSET_CTD_CONFIGURABLE == __AUTO__))
	#ifndef __MMI_CALLSET_CTD_CONFIGURABLE__
	#define __MMI_CALLSET_CTD_CONFIGURABLE__
	#endif
#endif


#if defined(CFG_MMI_CALLSET_CUG) && ((CFG_MMI_CALLSET_CUG == __ON__)||(CFG_MMI_CALLSET_CUG == __AUTO__))
	#ifndef __MMI_CALLSET_CUG__
	#define __MMI_CALLSET_CUG__
	#endif
#endif


#if (!defined(__MMI_CALLSET_SLIM__) && !defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_CALLSET_LINE_SWITCHING__
	#define __MMI_CALLSET_LINE_SWITCHING__
	#endif
#endif


#if defined(CFG_MMI_CAMCO_NOPHONEDRIVE) && ((CFG_MMI_CAMCO_NOPHONEDRIVE == __ON__)||(CFG_MMI_CAMCO_NOPHONEDRIVE == __AUTO__))
	#ifndef __MMI_CAMCO_NOPHONEDRIVE__
	#define __MMI_CAMCO_NOPHONEDRIVE__
	#endif
#endif


#if defined(CFG_MMI_CAMCO_SLIM) && ((CFG_MMI_CAMCO_SLIM == __ON__)||(CFG_MMI_CAMCO_SLIM == __AUTO__))
	#ifndef __MMI_CAMCO_SLIM__
	#define __MMI_CAMCO_SLIM__
	#endif
#endif


#if (!defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_FILE_MANAGER__) && (defined(__IMAGE_VIEWER_SLIM__) || defined(__IMAGE_VIEWER_STANDARD__) || defined(__IMAGE_VIEWER_EX__) || defined(__IMAGE_VIEWER_EX_DB__)))
	#ifndef __MMI_IMAGE_VIEWER__
	#define __MMI_IMAGE_VIEWER__
	#endif
#endif


#if ((!defined(__COSMOS_MMI_PACKAGE__) && defined(JPG_DECODE) && (defined(CAMERA_MODULE) || defined(ISP_SUPPORT)) && defined(__MMI_FILE_MANAGER__)) && !defined(__STREAM_SERVER_SUPPORT__))
	#if (!defined(__MMI_IMAGE_VIEWER__))
	#error "please turn on image viewer!"
	#endif
	#ifndef __MMI_CAMERA__
	#define __MMI_CAMERA__
	#endif
#endif


#if ((defined(MP4_ENCODE) || defined(MJPG_ENCODE)) && (defined(ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)) && !defined(__COSMOS_MMI_PACKAGE__) && !defined(__STREAM_SERVER_SUPPORT__))
	#ifndef __MMI_VIDEO_RECORDER__
	#define __MMI_VIDEO_RECORDER__
	#endif
#endif


#if defined(CFG_MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE) && ((CFG_MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE == __ON__)||(CFG_MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE == __AUTO__)) && \
	(defined(__MMI_CAMERA__) && defined(__MMI_VIDEO_RECORDER__))
	#ifndef __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__
	#define __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__
	#endif
#endif


#if defined(CFG_MMI_CAMERA_SLIM) && ((CFG_MMI_CAMERA_SLIM == __ON__)||(CFG_MMI_CAMERA_SLIM == __AUTO__)) && \
	(defined(JPG_DECODE) && (defined(CAMERA_MODULE) || defined(ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)) && defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_CAMERA_SLIM__
	#define __MMI_CAMERA_SLIM__
	#endif
#endif


#if defined(CFG_MMI_CASCADE_MENU) && ((CFG_MMI_CASCADE_MENU == __ON__)||(CFG_MMI_CASCADE_MENU == __AUTO__))
	#ifndef __MMI_CASCADE_MENU__
	#define __MMI_CASCADE_MENU__
	#endif
#endif


#if defined(CFG_MMI_CASCADED_OPTION_MENU) && ((CFG_MMI_CASCADED_OPTION_MENU == __ON__)||(CFG_MMI_CASCADED_OPTION_MENU == __AUTO__)) && \
	(((defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)) && defined(__PLUTO_MMI_PACKAGE__)))
	#ifndef __MMI_CASCADED_OPTION_MENU__
	#define __MMI_CASCADED_OPTION_MENU__
	#endif
#endif


#if (defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__))
	#ifndef __MMI_CAT103_SUPPORT__
	#define __MMI_CAT103_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__))
	#ifndef __MMI_CAT113_SUPPORT__
	#define __MMI_CAT113_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_USSD_REPLY_IN_SAME_SCREEN) && (CFG_MMI_USSD_REPLY_IN_SAME_SCREEN == __ON__) || \
	(defined(__OP11__))
	#ifndef __MMI_USSD_REPLY_IN_SAME_SCREEN__
	#define __MMI_USSD_REPLY_IN_SAME_SCREEN__
	#endif
#endif


#if (defined(__MMI_USSD_REPLY_IN_SAME_SCREEN__))
	#ifndef __MMI_CAT116_SUPPORT__
	#define __MMI_CAT116_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_DIALER_SLIM) && ((CFG_MMI_DIALER_SLIM == __ON__)||(CFG_MMI_DIALER_SLIM == __AUTO__))
	#ifndef __MMI_DIALER_SLIM__
	#define __MMI_DIALER_SLIM__
	#endif
#endif


#if defined(CFG_MMI_DIALER_SEARCH) && ((CFG_MMI_DIALER_SEARCH == __ON__)||(CFG_MMI_DIALER_SEARCH == __AUTO__)) && \
	(!defined(__MMI_QWERTY_KEYPAD_SUPPORT__)&& !defined(__MMI_DIALER_SLIM__))
	#ifndef __MMI_DIALER_SEARCH__
	#define __MMI_DIALER_SEARCH__
	#endif
#endif


#if (defined(__MMI_DIALER_SEARCH__))
	#ifndef __MMI_CAT203_SUPPORT__
	#define __MMI_CAT203_SUPPORT__
	#endif
#endif


#if ((defined(__MMI_ATV_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__))
	#ifndef __MMI_CAT265_SUPPORT__
	#define __MMI_CAT265_SUPPORT__
	#endif
#endif


#if (defined(__MMI_FWUI_SLIM__))
	#ifndef __MMI_CATEGORY_LIST_SLIM__
	#define __MMI_CATEGORY_LIST_SLIM__
	#endif
#endif


#if (defined(__CBM_CONNECTION_MANAGER__))
	#ifndef __MMI_CBM_CONNECTION_MANAGER__
	#define __MMI_CBM_CONNECTION_MANAGER__
	#endif
#endif


#if defined(CFG_MMI_CBS_SUPPORT) && ((CFG_MMI_CBS_SUPPORT == __ON__)||(CFG_MMI_CBS_SUPPORT == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__))
	#if (!defined (__CB__))
	#error "Please set CB_SUPPORT = TRUE from the project make file"
	#endif
	#ifndef __MMI_CBS_SUPPORT__
	#define __MMI_CBS_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT) && ((CFG_MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT == __ON__)||(CFG_MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT == __AUTO__)) && \
	(defined(__MMI_CCA_SUPPORT__))
	#ifndef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	#define __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CH_QUICK_END) && ((CFG_MMI_CH_QUICK_END == __ON__)||(CFG_MMI_CH_QUICK_END == __AUTO__))
	#ifndef __MMI_CH_QUICK_END__
	#define __MMI_CH_QUICK_END__
	#endif
#endif


#if defined(CFG_MMI_FTE_SUPPORT_SLIM) && ((CFG_MMI_FTE_SUPPORT_SLIM == __ON__)||(CFG_MMI_FTE_SUPPORT_SLIM == __AUTO__)) && \
	(defined(__MMI_FTE_SUPPORT__))
	#ifndef __MMI_FTE_SUPPORT_SLIM__
	#define __MMI_FTE_SUPPORT_SLIM__
	#endif
#endif


#if (((defined(__MMI_VUI_SHELL_APP__) || defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)) && !defined (__MMI_VECTOR_FONT_SUPPORT__)))
	#ifndef __MMI_CHINESE_WITH_SMALL_FONT__
	#define __MMI_CHINESE_WITH_SMALL_FONT__
	#endif
#endif


#if defined(CFG_MMI_CHSET_ARABIC_ISO) && (CFG_MMI_CHSET_ARABIC_ISO == __ON__) || \
	(defined(CFG_MMI_CHSET_ARABIC_ISO) && (CFG_MMI_CHSET_ARABIC_ISO == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_ARABIC__)))
	#ifndef __MMI_CHSET_ARABIC_ISO__
	#define __MMI_CHSET_ARABIC_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_ARABIC_WIN) && (CFG_MMI_CHSET_ARABIC_WIN == __ON__) || \
	(defined(CFG_MMI_CHSET_ARABIC_WIN) && (CFG_MMI_CHSET_ARABIC_WIN == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_ARABIC__)))
	#ifndef __MMI_CHSET_ARABIC_WIN__
	#define __MMI_CHSET_ARABIC_WIN__
	#endif
#endif


#if defined(CFG_MMI_LANG_ARMENIAN) && ((CFG_MMI_LANG_ARMENIAN == __ON__)||(CFG_MMI_LANG_ARMENIAN == __AUTO__))
	#ifndef __MMI_LANG_ARMENIAN__
	#define __MMI_LANG_ARMENIAN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_ARMENIAN_ISO) && (CFG_MMI_CHSET_ARMENIAN_ISO == __ON__) || \
	(defined(CFG_MMI_CHSET_ARMENIAN_ISO) && (CFG_MMI_CHSET_ARMENIAN_ISO == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_ARMENIAN__)))
	#ifndef __MMI_CHSET_ARMENIAN_ISO__
	#define __MMI_CHSET_ARMENIAN_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_BALTIC_ISO) && ((CFG_MMI_CHSET_BALTIC_ISO == __ON__)||(CFG_MMI_CHSET_BALTIC_ISO == __AUTO__))
	#ifndef __MMI_CHSET_BALTIC_ISO__
	#define __MMI_CHSET_BALTIC_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_BALTIC_WIN) && ((CFG_MMI_CHSET_BALTIC_WIN == __ON__)||(CFG_MMI_CHSET_BALTIC_WIN == __AUTO__))
	#ifndef __MMI_CHSET_BALTIC_WIN__
	#define __MMI_CHSET_BALTIC_WIN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_CEURO_ISO) && ((CFG_MMI_CHSET_CEURO_ISO == __ON__)||(CFG_MMI_CHSET_CEURO_ISO == __AUTO__))
	#ifndef __MMI_CHSET_CEURO_ISO__
	#define __MMI_CHSET_CEURO_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_CEURO_WIN) && ((CFG_MMI_CHSET_CEURO_WIN == __ON__)||(CFG_MMI_CHSET_CEURO_WIN == __AUTO__))
	#ifndef __MMI_CHSET_CEURO_WIN__
	#define __MMI_CHSET_CEURO_WIN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_CYRILLIC_ISO) && ((CFG_MMI_CHSET_CYRILLIC_ISO == __ON__)||(CFG_MMI_CHSET_CYRILLIC_ISO == __AUTO__))
	#ifndef __MMI_CHSET_CYRILLIC_ISO__
	#define __MMI_CHSET_CYRILLIC_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_CYRILLIC_WIN) && ((CFG_MMI_CHSET_CYRILLIC_WIN == __ON__)||(CFG_MMI_CHSET_CYRILLIC_WIN == __AUTO__))
	#ifndef __MMI_CHSET_CYRILLIC_WIN__
	#define __MMI_CHSET_CYRILLIC_WIN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_EUCKR_WIN) && ((CFG_MMI_CHSET_EUCKR_WIN == __ON__)||(CFG_MMI_CHSET_EUCKR_WIN == __AUTO__))
	#ifndef __MMI_CHSET_EUCKR_WIN__
	#define __MMI_CHSET_EUCKR_WIN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_GB18030) && ((CFG_MMI_CHSET_GB18030 == __ON__)||(CFG_MMI_CHSET_GB18030 == __AUTO__))
	#ifndef __MMI_CHSET_GB18030__
	#define __MMI_CHSET_GB18030__
	#endif
#endif


#if defined(CFG_MMI_CHSET_GB2312) && (CFG_MMI_CHSET_GB2312 == __ON__) || \
	(defined(CFG_MMI_CHSET_GB2312) && (CFG_MMI_CHSET_GB2312 == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_SM_CHINESE__)))
	#ifndef __MMI_CHSET_GB2312__
	#define __MMI_CHSET_GB2312__
	#endif
#endif


#if defined(CFG_MMI_CHSET_GREEK_ISO) && ((CFG_MMI_CHSET_GREEK_ISO == __ON__)||(CFG_MMI_CHSET_GREEK_ISO == __AUTO__))
	#ifndef __MMI_CHSET_GREEK_ISO__
	#define __MMI_CHSET_GREEK_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_GREEK_WIN) && ((CFG_MMI_CHSET_GREEK_WIN == __ON__)||(CFG_MMI_CHSET_GREEK_WIN == __AUTO__))
	#ifndef __MMI_CHSET_GREEK_WIN__
	#define __MMI_CHSET_GREEK_WIN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_HEBREW_ISO) && ((CFG_MMI_CHSET_HEBREW_ISO == __ON__)||(CFG_MMI_CHSET_HEBREW_ISO == __AUTO__))
	#ifndef __MMI_CHSET_HEBREW_ISO__
	#define __MMI_CHSET_HEBREW_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_HEBREW_WIN) && ((CFG_MMI_CHSET_HEBREW_WIN == __ON__)||(CFG_MMI_CHSET_HEBREW_WIN == __AUTO__))
	#ifndef __MMI_CHSET_HEBREW_WIN__
	#define __MMI_CHSET_HEBREW_WIN__
	#endif
#endif


#if defined(CFG_MMI_LANG_RUSSIAN) && ((CFG_MMI_LANG_RUSSIAN == __ON__)||(CFG_MMI_LANG_RUSSIAN == __AUTO__))
	#ifndef __MMI_LANG_RUSSIAN__
	#define __MMI_LANG_RUSSIAN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_KOI8_R) && (CFG_MMI_CHSET_KOI8_R == __ON__) || \
	(defined(CFG_MMI_CHSET_KOI8_R) && (CFG_MMI_CHSET_KOI8_R == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_RUSSIAN__)))
	#ifndef __MMI_CHSET_KOI8_R__
	#define __MMI_CHSET_KOI8_R__
	#endif
#endif


#if defined(CFG_MMI_CHSET_LATIN_ISO) && ((CFG_MMI_CHSET_LATIN_ISO == __ON__)||(CFG_MMI_CHSET_LATIN_ISO == __AUTO__))
	#ifndef __MMI_CHSET_LATIN_ISO__
	#define __MMI_CHSET_LATIN_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_NORDIC_ISO) && ((CFG_MMI_CHSET_NORDIC_ISO == __ON__)||(CFG_MMI_CHSET_NORDIC_ISO == __AUTO__))
	#ifndef __MMI_CHSET_NORDIC_ISO__
	#define __MMI_CHSET_NORDIC_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_PERSIAN_CP1097) && (CFG_MMI_CHSET_PERSIAN_CP1097 == __ON__) || \
	(defined(CFG_MMI_CHSET_PERSIAN_CP1097) && (CFG_MMI_CHSET_PERSIAN_CP1097 == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_PERSIAN__)))
	#ifndef __MMI_CHSET_PERSIAN_CP1097__
	#define __MMI_CHSET_PERSIAN_CP1097__
	#endif
#endif


#if defined(CFG_MMI_CHSET_PERSIAN_CP1098) && (CFG_MMI_CHSET_PERSIAN_CP1098 == __ON__) || \
	(defined(CFG_MMI_CHSET_PERSIAN_CP1098) && (CFG_MMI_CHSET_PERSIAN_CP1098 == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_PERSIAN__)))
	#ifndef __MMI_CHSET_PERSIAN_CP1098__
	#define __MMI_CHSET_PERSIAN_CP1098__
	#endif
#endif


#if defined(CFG_MMI_CHSET_SEURO_ISO) && ((CFG_MMI_CHSET_SEURO_ISO == __ON__)||(CFG_MMI_CHSET_SEURO_ISO == __AUTO__))
	#ifndef __MMI_CHSET_SEURO_ISO__
	#define __MMI_CHSET_SEURO_ISO__
	#endif
#endif


#if defined(CFG_MMI_LANG_THAI) && ((CFG_MMI_LANG_THAI == __ON__)||(CFG_MMI_LANG_THAI == __AUTO__))
	#ifndef __MMI_LANG_THAI__
	#define __MMI_LANG_THAI__
	#endif
#endif


#if defined(CFG_MMI_CHSET_THAI_WINDOWS) && (CFG_MMI_CHSET_THAI_WINDOWS == __ON__) || \
	(defined(CFG_MMI_CHSET_THAI_WINDOWS) && (CFG_MMI_CHSET_THAI_WINDOWS == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_THAI__)))
	#ifndef __MMI_CHSET_THAI_WINDOWS__
	#define __MMI_CHSET_THAI_WINDOWS__
	#endif
#endif


#if defined(CFG_MMI_CHSET_TIS_620) && (CFG_MMI_CHSET_TIS_620 == __ON__) || \
	(defined(CFG_MMI_CHSET_TIS_620) && (CFG_MMI_CHSET_TIS_620 == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_THAI__)))
	#ifndef __MMI_CHSET_TIS_620__
	#define __MMI_CHSET_TIS_620__
	#endif
#endif


#if defined(CFG_MMI_LANG_TURKISH) && ((CFG_MMI_LANG_TURKISH == __ON__)||(CFG_MMI_LANG_TURKISH == __AUTO__))
	#ifndef __MMI_LANG_TURKISH__
	#define __MMI_LANG_TURKISH__
	#endif
#endif


#if defined(CFG_MMI_CHSET_TURKISH_ISO) && (CFG_MMI_CHSET_TURKISH_ISO == __ON__) || \
	(defined(CFG_MMI_CHSET_TURKISH_ISO) && (CFG_MMI_CHSET_TURKISH_ISO == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_TURKISH__)))
	#ifndef __MMI_CHSET_TURKISH_ISO__
	#define __MMI_CHSET_TURKISH_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_TURKISH_WIN) && (CFG_MMI_CHSET_TURKISH_WIN == __ON__) || \
	(defined(CFG_MMI_CHSET_TURKISH_WIN) && (CFG_MMI_CHSET_TURKISH_WIN == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_TURKISH__)))
	#ifndef __MMI_CHSET_TURKISH_WIN__
	#define __MMI_CHSET_TURKISH_WIN__
	#endif
#endif


#if defined(CFG_MMI_CHSET_UTF7) && ((CFG_MMI_CHSET_UTF7 == __ON__)||(CFG_MMI_CHSET_UTF7 == __AUTO__))
	#ifndef __MMI_CHSET_UTF7__
	#define __MMI_CHSET_UTF7__
	#endif
#endif


#if defined(CFG_MMI_LANG_VIETNAMESE) && ((CFG_MMI_LANG_VIETNAMESE == __ON__)||(CFG_MMI_LANG_VIETNAMESE == __AUTO__))
	#ifndef __MMI_LANG_VIETNAMESE__
	#define __MMI_LANG_VIETNAMESE__
	#endif
#endif


#if defined(CFG_MMI_CHSET_VIETNAMESE_WINDOWS) && (CFG_MMI_CHSET_VIETNAMESE_WINDOWS == __ON__) || \
	(defined(CFG_MMI_CHSET_VIETNAMESE_WINDOWS) && (CFG_MMI_CHSET_VIETNAMESE_WINDOWS == __AUTO__) && (!defined(__MMI_LANG_CHSET_DEPENDENCE__) || defined(__MMI_LANG_CHSET_DEPENDENCE__) && defined(__MMI_LANG_VIETNAMESE__)))
	#ifndef __MMI_CHSET_VIETNAMESE_WINDOWS__
	#define __MMI_CHSET_VIETNAMESE_WINDOWS__
	#endif
#endif


#if defined(CFG_MMI_CHSET_WESTERN_ISO) && (CFG_MMI_CHSET_WESTERN_ISO == __ON__) || \
	(defined(__EMAIL__))
	#ifndef __MMI_CHSET_WESTERN_ISO__
	#define __MMI_CHSET_WESTERN_ISO__
	#endif
#endif


#if defined(CFG_MMI_CHSET_WESTERN_WIN) && (CFG_MMI_CHSET_WESTERN_WIN == __ON__) || \
	(defined(__EMAIL__))
	#ifndef __MMI_CHSET_WESTERN_WIN__
	#define __MMI_CHSET_WESTERN_WIN__
	#endif
#endif


#if defined(CFG_MMI_CLAMCLOSE_BACK2IDLE) && ((CFG_MMI_CLAMCLOSE_BACK2IDLE == __ON__)||(CFG_MMI_CLAMCLOSE_BACK2IDLE == __AUTO__)) && \
	(defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
	#ifndef __MMI_CLAMCLOSE_BACK2IDLE__
	#define __MMI_CLAMCLOSE_BACK2IDLE__
	#endif
#endif


#if defined(CFG_MMI_CLAMOPEN_STOP_SCRSAVER) && ((CFG_MMI_CLAMOPEN_STOP_SCRSAVER == __ON__)||(CFG_MMI_CLAMOPEN_STOP_SCRSAVER == __AUTO__))
	#ifndef __MMI_CLAMOPEN_STOP_SCRSAVER__
	#define __MMI_CLAMOPEN_STOP_SCRSAVER__
	#endif
#endif


#if defined(CFG_MMI_CLIPBOARD) && ((CFG_MMI_CLIPBOARD == __ON__)||(CFG_MMI_CLIPBOARD == __AUTO__))
	#ifndef __MMI_CLIPBOARD__
	#define __MMI_CLIPBOARD__
	#endif
#endif


#if (defined(__MMI_IME_FLOATING_CAND_BOX__) && defined(__MMI_FTE_SUPPORT__)  && defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_CLIPBOARD__))
	#ifndef __MMI_CLIPBOARD_FLOATING_MENU__
	#define __MMI_CLIPBOARD_FLOATING_MENU__
	#endif
#endif


#if (defined(__MMI_CALENDAR__) && (defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__)))
	#ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
	#define __MMI_CLNDR_SMALL_SIZE_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_CLOG_CALL_COST) && ((CFG_MMI_CLOG_CALL_COST == __ON__)||(CFG_MMI_CLOG_CALL_COST == __AUTO__)) && \
	(defined(__AOC_SUPPORT__))
	#ifndef __MMI_CLOG_CALL_COST__
	#define __MMI_CLOG_CALL_COST__
	#endif
#endif


#if defined(CFG_MMI_CLOG_CALL_TIME) && ((CFG_MMI_CLOG_CALL_TIME == __ON__)||(CFG_MMI_CLOG_CALL_TIME == __AUTO__))
	#ifndef __MMI_CLOG_CALL_TIME__
	#define __MMI_CLOG_CALL_TIME__
	#endif
#endif


#if (defined(__PS_SERVICE__))
	#ifndef __MMI_GPRS_FEATURES__
	#define __MMI_GPRS_FEATURES__
	#endif
#endif


#if defined(CFG_MMI_CLOG_GPRS_COUNT) && ((CFG_MMI_CLOG_GPRS_COUNT == __ON__)||(CFG_MMI_CLOG_GPRS_COUNT == __AUTO__)) && \
	(defined(__MMI_GPRS_FEATURES__) && defined(__TCPIP__) && defined(__DIALUP_GPRS_COUNTER_SUPPORT__))
	#ifndef __MMI_CLOG_GPRS_COUNT__
	#define __MMI_CLOG_GPRS_COUNT__
	#endif
#endif


#if defined(CFG_MMI_CLOG_MARK_SEVERAL) && ((CFG_MMI_CLOG_MARK_SEVERAL == __ON__)||(CFG_MMI_CLOG_MARK_SEVERAL == __AUTO__))
	#ifndef __MMI_CLOG_MARK_SEVERAL__
	#define __MMI_CLOG_MARK_SEVERAL__
	#endif
#endif


#if (!defined(__8_32_SEG__) && !defined(__32_32_SEG__) && !defined(__64_64_SEG__))
	#ifndef __MMI_CLOG_PHB_SYNC_SUPPORT__
	#define __MMI_CLOG_PHB_SYNC_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT) && ((CFG_MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT == __ON__)||(CFG_MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT == __AUTO__))
	#ifndef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__
	#define __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CLOG_SIM_FILTER) && ((CFG_MMI_CLOG_SIM_FILTER == __ON__)||(CFG_MMI_CLOG_SIM_FILTER == __AUTO__)) && \
	(defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
	#ifndef __MMI_CLOG_SIM_FILTER__
	#define __MMI_CLOG_SIM_FILTER__
	#endif
#endif


#if defined(CFG_MMI_CLOG_SIM_SYNC_SUPPORT) && ((CFG_MMI_CLOG_SIM_SYNC_SUPPORT == __ON__)||(CFG_MMI_CLOG_SIM_SYNC_SUPPORT == __AUTO__)) && \
	(defined(__PHB_ACCESS_SIM_LN__) && !defined(__SIM_HOT_SWAP_SUPPORT__) && (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM <= 2)))
	#ifndef __MMI_CLOG_SIM_SYNC_SUPPORT__
	#define __MMI_CLOG_SIM_SYNC_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CLOG_SLIM) && ((CFG_MMI_CLOG_SLIM == __ON__)||(CFG_MMI_CLOG_SLIM == __AUTO__))
	#ifndef __MMI_CLOG_SLIM__
	#define __MMI_CLOG_SLIM__
	#endif
#endif


#if defined(CFG_MMI_CLOG_SLIM_FOR_MT6261) && ((CFG_MMI_CLOG_SLIM_FOR_MT6261 == __ON__)||(CFG_MMI_CLOG_SLIM_FOR_MT6261 == __AUTO__)) && \
	(defined(__MMI_CLOG_SLIM__))
	#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
	#define __MMI_CLOG_SLIM_FOR_MT6261__
	#endif
#endif


#if defined(CFG_MMI_CLOG_SMS_COUNT) && ((CFG_MMI_CLOG_SMS_COUNT == __ON__)||(CFG_MMI_CLOG_SMS_COUNT == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_CLOG_SMS_COUNT__
	#define __MMI_CLOG_SMS_COUNT__
	#endif
#endif


#if defined(CFG_MMI_SSO_PRELOAD_YAHOO) && ((CFG_MMI_SSO_PRELOAD_YAHOO == __ON__)||(CFG_MMI_SSO_PRELOAD_YAHOO == __AUTO__))
	#if (!defined(__MMI_SSO__))
	#error "It should turn on __MMI_SSO__ or disable __MMI_SSO_PRELOAD_YAHOO__"
	#endif
	#ifndef __MMI_SSO_PRELOAD_YAHOO__
	#define __MMI_SSO_PRELOAD_YAHOO__
	#endif
#endif


#if (defined(__CLOUD_SUPPORT__) && defined(__MMI_SSO_PRELOAD_YAHOO__))
	#ifndef __MMI_CLOUD_PRELOAD_YAHOO__
	#define __MMI_CLOUD_PRELOAD_YAHOO__
	#endif
#endif


#if defined(CFG_MMI_CM_BLACK_LIST) && ((CFG_MMI_CM_BLACK_LIST == __ON__)||(CFG_MMI_CM_BLACK_LIST == __AUTO__))
	#ifndef __MMI_CM_BLACK_LIST__
	#define __MMI_CM_BLACK_LIST__
	#endif
#endif


#if (defined(__CNAP_SUPPORT__))
	#ifndef __MMI_CM_CNAP_SUPPORT__
	#define __MMI_CM_CNAP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_CM_WHITE_LIST) && ((CFG_MMI_CM_WHITE_LIST == __ON__)||(CFG_MMI_CM_WHITE_LIST == __AUTO__))
	#ifndef __MMI_CM_WHITE_LIST__
	#define __MMI_CM_WHITE_LIST__
	#endif
#endif


#if defined(CFG_MMI_CONNECT_NOTICE) && ((CFG_MMI_CONNECT_NOTICE == __ON__)||(CFG_MMI_CONNECT_NOTICE == __AUTO__))
	#ifndef __MMI_CONNECT_NOTICE__
	#define __MMI_CONNECT_NOTICE__
	#endif
#endif


#if defined(CFG_MMI_CONVERTER) && ((CFG_MMI_CONVERTER == __ON__)||(CFG_MMI_CONVERTER == __AUTO__))
	#ifndef __MMI_CONVERTER__
	#define __MMI_CONVERTER__
	#endif
#endif


#if (defined(__DOWNLOADABLE_THEME__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
	#define __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_GALLERY_3D_SLIDESHOW) && ((CFG_MMI_COSMOS_GALLERY_3D_SLIDESHOW == __ON__)||(CFG_MMI_COSMOS_GALLERY_3D_SLIDESHOW == __AUTO__)) && \
	(defined(__MMI_FTO_GALLERY__) && defined(__COSMOS_3D_V10__) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_COSMOS_GALLERY_3D_SLIDESHOW__
	#define __MMI_COSMOS_GALLERY_3D_SLIDESHOW__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_GALLERY_IMAGE_VIEWER_MAGNIFICATION_SLIM) && ((CFG_MMI_COSMOS_GALLERY_IMAGE_VIEWER_MAGNIFICATION_SLIM == __ON__)||(CFG_MMI_COSMOS_GALLERY_IMAGE_VIEWER_MAGNIFICATION_SLIM == __AUTO__)) && \
	(defined(__MMI_FTO_GALLERY__))
	#ifndef __MMI_COSMOS_GALLERY_IMAGE_VIEWER_MAGNIFICATION_SLIM__
	#define __MMI_COSMOS_GALLERY_IMAGE_VIEWER_MAGNIFICATION_SLIM__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_GALLERY_SLIM_PROFILE_5M) && ((CFG_MMI_COSMOS_GALLERY_SLIM_PROFILE_5M == __ON__)||(CFG_MMI_COSMOS_GALLERY_SLIM_PROFILE_5M == __AUTO__)) && \
	(defined(__MMI_FTO_GALLERY__) && defined(__LOW_COST_SUPPORT_COMMON__))
	#ifndef __MMI_COSMOS_GALLERY_SLIM_PROFILE_5M__
	#define __MMI_COSMOS_GALLERY_SLIM_PROFILE_5M__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_PHOTOEDITOR) && ((CFG_MMI_COSMOS_PHOTOEDITOR == __ON__)||(CFG_MMI_COSMOS_PHOTOEDITOR == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)|| defined(__MMI_MAINLCD_480X800__)) && defined(VENDOR_NONE))
	#ifndef __MMI_COSMOS_PHOTOEDITOR__
	#define __MMI_COSMOS_PHOTOEDITOR__
	#endif
#endif


#if (defined(__MMI_COSMOS_PHOTOEDITOR__))
	#ifndef __MMI_COSMOS_IMAGECLIPPER__
	#define __MMI_COSMOS_IMAGECLIPPER__
	#endif
#endif


#if (defined(__MMI_IMAGE_VIEWER__) && (defined(__IMAGE_VIEWER_EX__) || defined(__IMAGE_VIEWER_EX_DB__)))
	#ifndef __MMI_IMAGE_VIEWER_EX__
	#define __MMI_IMAGE_VIEWER_EX__
	#endif
#endif


#if (defined(__MMI_IMAGE_VIEWER__) && defined(__MMI_IMAGE_VIEWER_EX__) && defined(__IMAGE_VIEWER_EX_DB__))
	#ifndef __MMI_IMAGE_VIEWER_EX_DB__
	#define __MMI_IMAGE_VIEWER_EX_DB__
	#endif
#endif


#if (defined(__MMI_COSMOS_PHOTOEDITOR__) || (defined(__SCALADO_SUPPORT__) && (defined(__MMI_IMAGE_VIEWER_EX__) || defined(__MMI_IMAGE_VIEWER_EX_DB__) || defined(__MMI_PHOTOEDITOR__))))
	#if (!defined(__SCALADO_SUPPORT__ ))
	#error "When __MMI_SRV_IES__ is turned on, please turn on __SCALADO_SUPPORT__"
	#endif
	#ifndef __MMI_SRV_IES__
	#define __MMI_SRV_IES__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_IMGEDT_SLIM) && ((CFG_MMI_COSMOS_IMGEDT_SLIM == __ON__)||(CFG_MMI_COSMOS_IMGEDT_SLIM == __AUTO__)) && \
	(defined(__MMI_COSMOS_PHOTOEDITOR__))
	#ifndef __MMI_COSMOS_IMGEDT_SLIM__
	#define __MMI_COSMOS_IMGEDT_SLIM__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_IMGEDT_PARTIAL) && ((CFG_MMI_COSMOS_IMGEDT_PARTIAL == __ON__)||(CFG_MMI_COSMOS_IMGEDT_PARTIAL == __AUTO__)) && \
	(defined(__MMI_COSMOS_PHOTOEDITOR__) && defined(__MMI_SRV_IES__) && (!defined(__MMI_COSMOS_IMGEDT_SLIM__)))
	#ifndef __MMI_COSMOS_IMGEDT_PARTIAL__
	#define __MMI_COSMOS_IMGEDT_PARTIAL__
	#endif
#endif


#if (defined(__PHONE_SLIDE__))
	#ifndef __MMI_SLIDE__
	#define __MMI_SLIDE__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SLIDE__) && !defined(__MMI_REDUCED_KEYPAD__) || defined (__MMI_COSMOS_KEYPAD_SUPPORT_VK__))
	#ifndef __MMI_COSMOS_KEYPAD_SLIDER__
	#define __MMI_COSMOS_KEYPAD_SLIDER__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_MOT_NO_USER_DRIVE) && (CFG_MMI_COSMOS_MOT_NO_USER_DRIVE == __ON__) || \
	(defined(__COSMOS_NO_USER_DRIVE__))
	#ifndef __MMI_COSMOS_MOT_NO_USER_DRIVE__
	#define __MMI_COSMOS_MOT_NO_USER_DRIVE__
	#endif
#endif


#if (defined(__MOT_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_COSMOS_MOVIE_THEATER__
	#define __MMI_COSMOS_MOVIE_THEATER__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_STATUS_BAR_SLIM) && ((CFG_MMI_COSMOS_STATUS_BAR_SLIM == __ON__)||(CFG_MMI_COSMOS_STATUS_BAR_SLIM == __AUTO__))
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
	#define __MMI_COSMOS_STATUS_BAR_SLIM__
	#endif
#endif


#if defined(CFG_MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT) && ((CFG_MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT == __ON__)||(CFG_MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT == __AUTO__)) && \
	(defined(__MMI_UNIFIED_COMPOSER__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	#define __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	#endif
#endif


#if ((!defined(__MMI_SLIM_ENGINEER_MODE__)) && defined(__MMI_FTE_SUPPORT__)  && defined(__PLUTO_MMI_PACKAGE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_CSB_BROWSER__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_IME_SLIM) && ((CFG_MMI_IME_SLIM == __ON__)||(CFG_MMI_IME_SLIM == __AUTO__))
	#ifndef __MMI_IME_SLIM__
	#define __MMI_IME_SLIM__
	#endif
#endif


#if (defined(__MMI_IME_SLIM__) && !defined(__COSMOS_MMI__))
	#ifndef __MMI_IME_PLUTO_SLIM__
	#define __MMI_IME_PLUTO_SLIM__
	#endif
#endif


#if (((((defined(__MMI_NORMAL_KEYPAD__)||defined(__MMI_XT9__) || (defined (__MMI_IME_V3__) && defined(__MMI_CSTAR__)) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)) && (defined(__MMI_CSTAR__) || defined(__MMI_ZI__) || defined(__MMI_T9__)))) ||  (defined(__MMI_KOMOXO__) || defined(__MMI_GUOBI__))) && !defined(__MMI_IME_PLUTO_SLIM__)) ||\
	 (defined(__MMI_KOMOXO__) || defined(__MMI_GUOBI__))
	#ifndef __MMI_SMART_ALPHABETIC_INPUT_METHODS__
	#define __MMI_SMART_ALPHABETIC_INPUT_METHODS__
	#endif
#endif


#if defined(CFG_MMI_IME_ARABIC) && ((CFG_MMI_IME_ARABIC == __ON__)||(CFG_MMI_IME_ARABIC == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_ARABIC__))
	#ifndef __MMI_IME_ARABIC__
	#define __MMI_IME_ARABIC__
	#endif
#endif


#if (defined(__MMI_IME_ARABIC__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_ARABIC__
	#define __MMI_CSTAR_ARABIC__
	#endif
#endif


#if defined(CFG_MMI_LANG_BENGALI) && ((CFG_MMI_LANG_BENGALI == __ON__)||(CFG_MMI_LANG_BENGALI == __AUTO__))
	#ifndef __MMI_LANG_BENGALI__
	#define __MMI_LANG_BENGALI__
	#endif
#endif


#if defined(CFG_MMI_IME_BENGALI) && ((CFG_MMI_IME_BENGALI == __ON__)||(CFG_MMI_IME_BENGALI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_BENGALI__))
	#ifndef __MMI_IME_BENGALI__
	#define __MMI_IME_BENGALI__
	#endif
#endif


#if (defined(__MMI_IME_BENGALI__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_BENGALI__
	#define __MMI_CSTAR_BENGALI__
	#endif
#endif


#if defined(CFG_MMI_LANG_BULGARIAN) && ((CFG_MMI_LANG_BULGARIAN == __ON__)||(CFG_MMI_LANG_BULGARIAN == __AUTO__))
	#ifndef __MMI_LANG_BULGARIAN__
	#define __MMI_LANG_BULGARIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_BULGARIAN) && ((CFG_MMI_IME_BULGARIAN == __ON__)||(CFG_MMI_IME_BULGARIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_BULGARIAN__))
	#ifndef __MMI_IME_BULGARIAN__
	#define __MMI_IME_BULGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_BULGARIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_BULGARIAN__
	#define __MMI_CSTAR_BULGARIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_CZECH) && ((CFG_MMI_LANG_CZECH == __ON__)||(CFG_MMI_LANG_CZECH == __AUTO__))
	#ifndef __MMI_LANG_CZECH__
	#define __MMI_LANG_CZECH__
	#endif
#endif


#if defined(CFG_MMI_IME_CZECH) && ((CFG_MMI_IME_CZECH == __ON__)||(CFG_MMI_IME_CZECH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_CZECH__))
	#ifndef __MMI_IME_CZECH__
	#define __MMI_IME_CZECH__
	#endif
#endif


#if (defined(__MMI_IME_CZECH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_CZECH__
	#define __MMI_CSTAR_CZECH__
	#endif
#endif


#if defined(CFG_MMI_LANG_DANISH) && ((CFG_MMI_LANG_DANISH == __ON__)||(CFG_MMI_LANG_DANISH == __AUTO__))
	#ifndef __MMI_LANG_DANISH__
	#define __MMI_LANG_DANISH__
	#endif
#endif


#if defined(CFG_MMI_IME_DANISH) && ((CFG_MMI_IME_DANISH == __ON__)||(CFG_MMI_IME_DANISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_DANISH__))
	#ifndef __MMI_IME_DANISH__
	#define __MMI_IME_DANISH__
	#endif
#endif


#if (defined(__MMI_IME_DANISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_DANISH__
	#define __MMI_CSTAR_DANISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_DUTCH) && ((CFG_MMI_LANG_DUTCH == __ON__)||(CFG_MMI_LANG_DUTCH == __AUTO__))
	#ifndef __MMI_LANG_DUTCH__
	#define __MMI_LANG_DUTCH__
	#endif
#endif


#if defined(CFG_MMI_IME_DUTCH) && ((CFG_MMI_IME_DUTCH == __ON__)||(CFG_MMI_IME_DUTCH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_DUTCH__))
	#ifndef __MMI_IME_DUTCH__
	#define __MMI_IME_DUTCH__
	#endif
#endif


#if (defined(__MMI_IME_DUTCH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_DUTCH__
	#define __MMI_CSTAR_DUTCH__
	#endif
#endif


#if defined(CFG_MMI_LANG_ENGLISH) && ((CFG_MMI_LANG_ENGLISH == __ON__)||(CFG_MMI_LANG_ENGLISH == __AUTO__))
	#ifndef __MMI_LANG_ENGLISH__
	#define __MMI_LANG_ENGLISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_UK_ENGLISH) && ((CFG_MMI_LANG_UK_ENGLISH == __ON__)||(CFG_MMI_LANG_UK_ENGLISH == __AUTO__))
	#ifndef __MMI_LANG_UK_ENGLISH__
	#define __MMI_LANG_UK_ENGLISH__
	#endif
#endif


#if defined(CFG_MMI_IME_ENGLISH) && ((CFG_MMI_IME_ENGLISH == __ON__)||(CFG_MMI_IME_ENGLISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& (defined(__MMI_LANG_ENGLISH__) || defined(__MMI_LANG_UK_ENGLISH__)))
	#ifndef __MMI_IME_ENGLISH__
	#define __MMI_IME_ENGLISH__
	#endif
#endif


#if (defined(__MMI_IME_ENGLISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_ENGLISH__
	#define __MMI_CSTAR_ENGLISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_FINNISH) && ((CFG_MMI_LANG_FINNISH == __ON__)||(CFG_MMI_LANG_FINNISH == __AUTO__))
	#ifndef __MMI_LANG_FINNISH__
	#define __MMI_LANG_FINNISH__
	#endif
#endif


#if defined(CFG_MMI_IME_FINNISH) && ((CFG_MMI_IME_FINNISH == __ON__)||(CFG_MMI_IME_FINNISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_FINNISH__))
	#ifndef __MMI_IME_FINNISH__
	#define __MMI_IME_FINNISH__
	#endif
#endif


#if (defined(__MMI_IME_FINNISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_FINNISH__
	#define __MMI_CSTAR_FINNISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_FRENCH) && ((CFG_MMI_LANG_FRENCH == __ON__)||(CFG_MMI_LANG_FRENCH == __AUTO__))
	#ifndef __MMI_LANG_FRENCH__
	#define __MMI_LANG_FRENCH__
	#endif
#endif


#if defined(CFG_MMI_LANG_CA_FRENCH) && ((CFG_MMI_LANG_CA_FRENCH == __ON__)||(CFG_MMI_LANG_CA_FRENCH == __AUTO__))
	#ifndef __MMI_LANG_CA_FRENCH__
	#define __MMI_LANG_CA_FRENCH__
	#endif
#endif


#if defined(CFG_MMI_IME_FRENCH) && ((CFG_MMI_IME_FRENCH == __ON__)||(CFG_MMI_IME_FRENCH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& (defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__)))
	#ifndef __MMI_IME_FRENCH__
	#define __MMI_IME_FRENCH__
	#endif
#endif


#if (defined(__MMI_IME_FRENCH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_FRENCH__
	#define __MMI_CSTAR_FRENCH__
	#endif
#endif


#if defined(CFG_MMI_LANG_GERMAN) && ((CFG_MMI_LANG_GERMAN == __ON__)||(CFG_MMI_LANG_GERMAN == __AUTO__))
	#ifndef __MMI_LANG_GERMAN__
	#define __MMI_LANG_GERMAN__
	#endif
#endif


#if defined(CFG_MMI_IME_GERMAN) && ((CFG_MMI_IME_GERMAN == __ON__)||(CFG_MMI_IME_GERMAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_GERMAN__))
	#ifndef __MMI_IME_GERMAN__
	#define __MMI_IME_GERMAN__
	#endif
#endif


#if (defined(__MMI_IME_GERMAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_GERMAN__
	#define __MMI_CSTAR_GERMAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_GREEK) && ((CFG_MMI_LANG_GREEK == __ON__)||(CFG_MMI_LANG_GREEK == __AUTO__))
	#ifndef __MMI_LANG_GREEK__
	#define __MMI_LANG_GREEK__
	#endif
#endif


#if defined(CFG_MMI_IME_GREEK) && ((CFG_MMI_IME_GREEK == __ON__)||(CFG_MMI_IME_GREEK == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_GREEK__))
	#ifndef __MMI_IME_GREEK__
	#define __MMI_IME_GREEK__
	#endif
#endif


#if (defined(__MMI_IME_GREEK__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_GREEK__
	#define __MMI_CSTAR_GREEK__
	#endif
#endif


#if defined(CFG_MMI_IME_HEBREW) && ((CFG_MMI_IME_HEBREW == __ON__)||(CFG_MMI_IME_HEBREW == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) &&  defined(__MMI_LANG_HEBREW__))
	#ifndef __MMI_IME_HEBREW__
	#define __MMI_IME_HEBREW__
	#endif
#endif


#if (defined(__MMI_IME_HEBREW__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_HEBREW__
	#define __MMI_CSTAR_HEBREW__
	#endif
#endif


#if defined(CFG_MMI_LANG_HINDI) && ((CFG_MMI_LANG_HINDI == __ON__)||(CFG_MMI_LANG_HINDI == __AUTO__))
	#ifndef __MMI_LANG_HINDI__
	#define __MMI_LANG_HINDI__
	#endif
#endif


#if defined(CFG_MMI_IME_HINDI) && ((CFG_MMI_IME_HINDI == __ON__)||(CFG_MMI_IME_HINDI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_HINDI__))
	#ifndef __MMI_IME_HINDI__
	#define __MMI_IME_HINDI__
	#endif
#endif


#if (defined(__MMI_IME_HINDI__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_HINDI__
	#define __MMI_CSTAR_HINDI__
	#endif
#endif


#if defined(CFG_MMI_IME_HINGLISH) && ((CFG_MMI_IME_HINGLISH == __ON__)||(CFG_MMI_IME_HINGLISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_HINDI__))
	#ifndef __MMI_IME_HINGLISH__
	#define __MMI_IME_HINGLISH__
	#endif
#endif


#if (defined(__MMI_IME_HINGLISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_HINGLISH__
	#define __MMI_CSTAR_HINGLISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_HUNGARIAN) && ((CFG_MMI_LANG_HUNGARIAN == __ON__)||(CFG_MMI_LANG_HUNGARIAN == __AUTO__))
	#ifndef __MMI_LANG_HUNGARIAN__
	#define __MMI_LANG_HUNGARIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HUNGARIAN) && ((CFG_MMI_IME_HUNGARIAN == __ON__)||(CFG_MMI_IME_HUNGARIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_HUNGARIAN__))
	#ifndef __MMI_IME_HUNGARIAN__
	#define __MMI_IME_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_HUNGARIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_HUNGARIAN__
	#define __MMI_CSTAR_HUNGARIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_INDONESIAN) && ((CFG_MMI_LANG_INDONESIAN == __ON__)||(CFG_MMI_LANG_INDONESIAN == __AUTO__))
	#ifndef __MMI_LANG_INDONESIAN__
	#define __MMI_LANG_INDONESIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_INDONESIAN) && ((CFG_MMI_IME_INDONESIAN == __ON__)||(CFG_MMI_IME_INDONESIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_INDONESIAN__))
	#ifndef __MMI_IME_INDONESIAN__
	#define __MMI_IME_INDONESIAN__
	#endif
#endif


#if (defined(__MMI_IME_INDONESIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_INDONESIAN__
	#define __MMI_CSTAR_INDONESIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_ITALIAN) && ((CFG_MMI_LANG_ITALIAN == __ON__)||(CFG_MMI_LANG_ITALIAN == __AUTO__))
	#ifndef __MMI_LANG_ITALIAN__
	#define __MMI_LANG_ITALIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_ITALIAN) && ((CFG_MMI_IME_ITALIAN == __ON__)||(CFG_MMI_IME_ITALIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_ITALIAN__))
	#ifndef __MMI_IME_ITALIAN__
	#define __MMI_IME_ITALIAN__
	#endif
#endif


#if (defined(__MMI_IME_ITALIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_ITALIAN__
	#define __MMI_CSTAR_ITALIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_LITHUANIAN) && ((CFG_MMI_LANG_LITHUANIAN == __ON__)||(CFG_MMI_LANG_LITHUANIAN == __AUTO__))
	#ifndef __MMI_LANG_LITHUANIAN__
	#define __MMI_LANG_LITHUANIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_LITHUANIAN) && ((CFG_MMI_IME_LITHUANIAN == __ON__)||(CFG_MMI_IME_LITHUANIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_LITHUANIAN__))
	#ifndef __MMI_IME_LITHUANIAN__
	#define __MMI_IME_LITHUANIAN__
	#endif
#endif


#if (defined(__MMI_IME_LITHUANIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_LITHUANIAN__
	#define __MMI_CSTAR_LITHUANIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_MALAY) && ((CFG_MMI_LANG_MALAY == __ON__)||(CFG_MMI_LANG_MALAY == __AUTO__))
	#ifndef __MMI_LANG_MALAY__
	#define __MMI_LANG_MALAY__
	#endif
#endif


#if defined(CFG_MMI_IME_MALAY) && ((CFG_MMI_IME_MALAY == __ON__)||(CFG_MMI_IME_MALAY == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_MALAY__))
	#ifndef __MMI_IME_MALAY__
	#define __MMI_IME_MALAY__
	#endif
#endif


#if (defined(__MMI_IME_MALAY__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_MALAY__
	#define __MMI_CSTAR_MALAY__
	#endif
#endif


#if defined(CFG_MMI_IME_MALDOVAN) && ((CFG_MMI_IME_MALDOVAN == __ON__)||(CFG_MMI_IME_MALDOVAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_MALDOVAN__))
	#ifndef __MMI_IME_MALDOVAN__
	#define __MMI_IME_MALDOVAN__
	#endif
#endif


#if (defined(__MMI_IME_MALDOVAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_MALDOVAN__
	#define __MMI_CSTAR_MALDOVAN__
	#endif
#endif


#if (defined(__MMI_IME_MOLDOVAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_MOLDOVAN__
	#define __MMI_CSTAR_MOLDOVAN__
	#endif
#endif


#if defined(CFG_MMI_CSTAR_MULTITAP) && ((CFG_MMI_CSTAR_MULTITAP == __ON__)||(CFG_MMI_CSTAR_MULTITAP == __AUTO__)) && \
	((defined(__MMI_CSTAR__) || defined(__MMI_CSTAR_V2__)) && (defined(__MMI_NORMAL_KEYPAD__)  || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)))
	#ifndef __MMI_CSTAR_MULTITAP__
	#define __MMI_CSTAR_MULTITAP__
	#endif
#endif


#if defined(CFG_MMI_IME_MULTITAP_PHONETIC_INPUT) && ((CFG_MMI_IME_MULTITAP_PHONETIC_INPUT == __ON__)||(CFG_MMI_IME_MULTITAP_PHONETIC_INPUT == __AUTO__)) && \
	(!defined (__MMI_IME_SLIM__))
	#ifndef __MMI_IME_MULTITAP_PHONETIC_INPUT__
	#define __MMI_IME_MULTITAP_PHONETIC_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_MULTITAP_PHONETIC_INPUT__
	#define __MMI_CSTAR_MULTITAP_PHONETIC_INPUT__
	#endif
#endif


#if defined(CFG_MMI_LANG_MYANMAR) && ((CFG_MMI_LANG_MYANMAR == __ON__)||(CFG_MMI_LANG_MYANMAR == __AUTO__))
	#ifndef __MMI_LANG_MYANMAR__
	#define __MMI_LANG_MYANMAR__
	#endif
#endif


#if defined(CFG_MMI_IME_MYANMAR) && ((CFG_MMI_IME_MYANMAR == __ON__)||(CFG_MMI_IME_MYANMAR == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_MYANMAR__))
	#ifndef __MMI_IME_MYANMAR__
	#define __MMI_IME_MYANMAR__
	#endif
#endif


#if (defined(__MMI_IME_MYANMAR__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_MYANMAR__
	#define __MMI_CSTAR_MYANMAR__
	#endif
#endif


#if defined(CFG_MMI_IME_PERSIAN) && ((CFG_MMI_IME_PERSIAN == __ON__)||(CFG_MMI_IME_PERSIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_PERSIAN__))
	#ifndef __MMI_IME_PERSIAN__
	#define __MMI_IME_PERSIAN__
	#endif
#endif


#if (defined(__MMI_IME_PERSIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_PERSIAN__
	#define __MMI_CSTAR_PERSIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_POLISH) && ((CFG_MMI_LANG_POLISH == __ON__)||(CFG_MMI_LANG_POLISH == __AUTO__))
	#ifndef __MMI_LANG_POLISH__
	#define __MMI_LANG_POLISH__
	#endif
#endif


#if defined(CFG_MMI_IME_POLISH) && ((CFG_MMI_IME_POLISH == __ON__)||(CFG_MMI_IME_POLISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_POLISH__))
	#ifndef __MMI_IME_POLISH__
	#define __MMI_IME_POLISH__
	#endif
#endif


#if (defined(__MMI_IME_POLISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_POLISH__
	#define __MMI_CSTAR_POLISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_PORTUGUESE) && ((CFG_MMI_LANG_PORTUGUESE == __ON__)||(CFG_MMI_LANG_PORTUGUESE == __AUTO__))
	#ifndef __MMI_LANG_PORTUGUESE__
	#define __MMI_LANG_PORTUGUESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_SA_PORTUGUESE) && ((CFG_MMI_LANG_SA_PORTUGUESE == __ON__)||(CFG_MMI_LANG_SA_PORTUGUESE == __AUTO__))
	#ifndef __MMI_LANG_SA_PORTUGUESE__
	#define __MMI_LANG_SA_PORTUGUESE__
	#endif
#endif


#if defined(CFG_MMI_IME_PORTUGUESE) && ((CFG_MMI_IME_PORTUGUESE == __ON__)||(CFG_MMI_IME_PORTUGUESE == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& (defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__)))
	#ifndef __MMI_IME_PORTUGUESE__
	#define __MMI_IME_PORTUGUESE__
	#endif
#endif


#if (defined(__MMI_IME_PORTUGUESE__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_PORTUGUESE__
	#define __MMI_CSTAR_PORTUGUESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_ROMANIAN) && ((CFG_MMI_LANG_ROMANIAN == __ON__)||(CFG_MMI_LANG_ROMANIAN == __AUTO__))
	#ifndef __MMI_LANG_ROMANIAN__
	#define __MMI_LANG_ROMANIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_ROMANIAN) && ((CFG_MMI_IME_ROMANIAN == __ON__)||(CFG_MMI_IME_ROMANIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_ROMANIAN__))
	#ifndef __MMI_IME_ROMANIAN__
	#define __MMI_IME_ROMANIAN__
	#endif
#endif


#if (defined(__MMI_IME_ROMANIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_ROMANIAN__
	#define __MMI_CSTAR_ROMANIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_RUSSIAN) && ((CFG_MMI_IME_RUSSIAN == __ON__)||(CFG_MMI_IME_RUSSIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_RUSSIAN__))
	#ifndef __MMI_IME_RUSSIAN__
	#define __MMI_IME_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_IME_RUSSIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_RUSSIAN__
	#define __MMI_CSTAR_RUSSIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_SLOVAK) && ((CFG_MMI_LANG_SLOVAK == __ON__)||(CFG_MMI_LANG_SLOVAK == __AUTO__))
	#ifndef __MMI_LANG_SLOVAK__
	#define __MMI_LANG_SLOVAK__
	#endif
#endif


#if defined(CFG_MMI_IME_SLOVAK) && ((CFG_MMI_IME_SLOVAK == __ON__)||(CFG_MMI_IME_SLOVAK == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_SLOVAK__))
	#ifndef __MMI_IME_SLOVAK__
	#define __MMI_IME_SLOVAK__
	#endif
#endif


#if (defined(__MMI_IME_SLOVAK__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SLOVAK__
	#define __MMI_CSTAR_SLOVAK__
	#endif
#endif


#if (defined(__MMI_IME_SLOVAKIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SLOVAKIAN__
	#define __MMI_CSTAR_SLOVAKIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_SLOVENIAN) && ((CFG_MMI_LANG_SLOVENIAN == __ON__)||(CFG_MMI_LANG_SLOVENIAN == __AUTO__))
	#ifndef __MMI_LANG_SLOVENIAN__
	#define __MMI_LANG_SLOVENIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_SLOVENIAN) && ((CFG_MMI_IME_SLOVENIAN == __ON__)||(CFG_MMI_IME_SLOVENIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_SLOVENIAN__))
	#ifndef __MMI_IME_SLOVENIAN__
	#define __MMI_IME_SLOVENIAN__
	#endif
#endif


#if (defined(__MMI_IME_SLOVENIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SLOVENIAN__
	#define __MMI_CSTAR_SLOVENIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_SM_CHINESE) && ((CFG_MMI_IME_SM_CHINESE == __ON__)||(CFG_MMI_IME_SM_CHINESE == __AUTO__)) && \
	(defined(__MMI_LANG_SM_CHINESE__))
	#ifndef __MMI_IME_SM_CHINESE__
	#define __MMI_IME_SM_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_SM_CHINESE__)  && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SM_CHINESE__
	#define __MMI_CSTAR_SM_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_SPANISH) && ((CFG_MMI_LANG_SPANISH == __ON__)||(CFG_MMI_LANG_SPANISH == __AUTO__))
	#ifndef __MMI_LANG_SPANISH__
	#define __MMI_LANG_SPANISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_SA_SPANISH) && ((CFG_MMI_LANG_SA_SPANISH == __ON__)||(CFG_MMI_LANG_SA_SPANISH == __AUTO__))
	#ifndef __MMI_LANG_SA_SPANISH__
	#define __MMI_LANG_SA_SPANISH__
	#endif
#endif


#if defined(CFG_MMI_IME_SPANISH) && ((CFG_MMI_IME_SPANISH == __ON__)||(CFG_MMI_IME_SPANISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && (defined(__MMI_LANG_SPANISH__)||defined(__MMI_LANG_SA_SPANISH__)))
	#ifndef __MMI_IME_SPANISH__
	#define __MMI_IME_SPANISH__
	#endif
#endif


#if (defined(__MMI_IME_SPANISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SPANISH__
	#define __MMI_CSTAR_SPANISH__
	#endif
#endif


#if defined(CFG_MMI_IME_STROKE_INPUT) && ((CFG_MMI_IME_STROKE_INPUT == __ON__)||(CFG_MMI_IME_STROKE_INPUT == __AUTO__))
	#ifndef __MMI_IME_STROKE_INPUT__
	#define __MMI_IME_STROKE_INPUT__
	#endif
#endif


#if (defined (__MMI_IME_STROKE_INPUT__) && (defined(__MMI_CSTAR__) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)|| defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)) && (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))))
	#ifndef __MMI_CSTAR_STROKE_INPUT__
	#define __MMI_CSTAR_STROKE_INPUT__
	#endif
#endif


#if defined(CFG_MMI_LANG_SWAHILI) && ((CFG_MMI_LANG_SWAHILI == __ON__)||(CFG_MMI_LANG_SWAHILI == __AUTO__))
	#ifndef __MMI_LANG_SWAHILI__
	#define __MMI_LANG_SWAHILI__
	#endif
#endif


#if defined(CFG_MMI_IME_SWAHILI) && ((CFG_MMI_IME_SWAHILI == __ON__)||(CFG_MMI_IME_SWAHILI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_SWAHILI__))
	#ifndef __MMI_IME_SWAHILI__
	#define __MMI_IME_SWAHILI__
	#endif
#endif


#if (defined(__MMI_IME_SWAHILI__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SWAHILI__
	#define __MMI_CSTAR_SWAHILI__
	#endif
#endif


#if defined(CFG_MMI_LANG_SWEDISH) && ((CFG_MMI_LANG_SWEDISH == __ON__)||(CFG_MMI_LANG_SWEDISH == __AUTO__))
	#ifndef __MMI_LANG_SWEDISH__
	#define __MMI_LANG_SWEDISH__
	#endif
#endif


#if defined(CFG_MMI_IME_SWEDISH) && ((CFG_MMI_IME_SWEDISH == __ON__)||(CFG_MMI_IME_SWEDISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_SWEDISH__))
	#ifndef __MMI_IME_SWEDISH__
	#define __MMI_IME_SWEDISH__
	#endif
#endif


#if (defined(__MMI_IME_SWEDISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_SWEDISH__
	#define __MMI_CSTAR_SWEDISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_TAGALOG) && ((CFG_MMI_LANG_TAGALOG == __ON__)||(CFG_MMI_LANG_TAGALOG == __AUTO__))
	#ifndef __MMI_LANG_TAGALOG__
	#define __MMI_LANG_TAGALOG__
	#endif
#endif


#if defined(CFG_MMI_IME_TAGALOG) && ((CFG_MMI_IME_TAGALOG == __ON__)||(CFG_MMI_IME_TAGALOG == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_TAGALOG__))
	#ifndef __MMI_IME_TAGALOG__
	#define __MMI_IME_TAGALOG__
	#endif
#endif


#if (defined(__MMI_IME_TAGALOG__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_TAGALOG__
	#define __MMI_CSTAR_TAGALOG__
	#endif
#endif


#if defined(CFG_MMI_IME_THAI) && ((CFG_MMI_IME_THAI == __ON__)||(CFG_MMI_IME_THAI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_THAI__))
	#ifndef __MMI_IME_THAI__
	#define __MMI_IME_THAI__
	#endif
#endif


#if (defined(__MMI_IME_THAI__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_THAI__
	#define __MMI_CSTAR_THAI__
	#endif
#endif


#if defined(CFG_MMI_IME_TR_CHINESE) && ((CFG_MMI_IME_TR_CHINESE == __ON__)||(CFG_MMI_IME_TR_CHINESE == __AUTO__)) && \
	(defined(__MMI_LANG_TR_CHINESE__))
	#ifndef __MMI_IME_TR_CHINESE__
	#define __MMI_IME_TR_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_TR_CHINESE__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_TR_CHINESE__
	#define __MMI_CSTAR_TR_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_IME_TURKISH) && ((CFG_MMI_IME_TURKISH == __ON__)||(CFG_MMI_IME_TURKISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_TURKISH__))
	#ifndef __MMI_IME_TURKISH__
	#define __MMI_IME_TURKISH__
	#endif
#endif


#if (defined(__MMI_IME_TURKISH__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_TURKISH__
	#define __MMI_CSTAR_TURKISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_UKRAINIAN) && ((CFG_MMI_LANG_UKRAINIAN == __ON__)||(CFG_MMI_LANG_UKRAINIAN == __AUTO__))
	#ifndef __MMI_LANG_UKRAINIAN__
	#define __MMI_LANG_UKRAINIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_UKRAINIAN) && ((CFG_MMI_IME_UKRAINIAN == __ON__)||(CFG_MMI_IME_UKRAINIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_UKRAINIAN__))
	#ifndef __MMI_IME_UKRAINIAN__
	#define __MMI_IME_UKRAINIAN__
	#endif
#endif


#if (defined(__MMI_IME_UKRAINIAN__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_UKRAINIAN__
	#define __MMI_CSTAR_UKRAINIAN__
	#endif
#endif


#if defined(CFG_MMI_CSTAR_USE_CUSTOMIZED_THEME) && ((CFG_MMI_CSTAR_USE_CUSTOMIZED_THEME == __ON__)||(CFG_MMI_CSTAR_USE_CUSTOMIZED_THEME == __AUTO__)) && \
	(defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_USE_CUSTOMIZED_THEME__
	#define __MMI_CSTAR_USE_CUSTOMIZED_THEME__
	#endif
#endif


#if defined(CFG_MMI_IME_VIETNAMESE) && ((CFG_MMI_IME_VIETNAMESE == __ON__)||(CFG_MMI_IME_VIETNAMESE == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_VIETNAMESE__))
	#ifndef __MMI_IME_VIETNAMESE__
	#define __MMI_IME_VIETNAMESE__
	#endif
#endif


#if (defined(__MMI_IME_VIETNAMESE__) && defined(__MMI_CSTAR__))
	#ifndef __MMI_CSTAR_VIETNAMESE__
	#define __MMI_CSTAR_VIETNAMESE__
	#endif
#endif


#if (defined(CUST_KEYPAD_TONE_SUPPORT))
	#ifndef __MMI_CUST_KEYPAD_TONE__
	#define __MMI_CUST_KEYPAD_TONE__
	#endif
#endif


#if (defined(CFG_MMI_DA_DOWNLOAD_FLOW))
	#ifndef __MMI_DA_DOWNLOAD_FLOW__
	#define __MMI_DA_DOWNLOAD_FLOW__	CFG_MMI_DA_DOWNLOAD_FLOW
	#endif
#endif


#if defined(CFG_MMI_DA_OBJECT_DESCRIPTION_SUPPORT) && ((CFG_MMI_DA_OBJECT_DESCRIPTION_SUPPORT == __ON__)||(CFG_MMI_DA_OBJECT_DESCRIPTION_SUPPORT == __AUTO__)) && \
	(defined(__MMI_OMA_DD_DOWNLOAD__))
	#ifndef __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__
	#define __MMI_DA_OBJECT_DESCRIPTION_SUPPORT__
	#endif
#endif


#if (defined(SYNCML_DM_SUPPORT))
	#ifndef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
	#define __MMI_DA_OMADL_CUST_CHL_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_DATA_LOCK) && ((CFG_MMI_DATA_LOCK == __ON__)||(CFG_MMI_DATA_LOCK == __AUTO__)) && \
	(defined(__TCPIP__) && !defined(LOW_COST_SUPPORT))
	#ifndef __MMI_DATA_LOCK__
	#define __MMI_DATA_LOCK__
	#endif
#endif


#if defined(CFG_MMI_DEDICATED_KEY_SHORTCUTS) && ((CFG_MMI_DEDICATED_KEY_SHORTCUTS == __ON__)||(CFG_MMI_DEDICATED_KEY_SHORTCUTS == __AUTO__)) && \
	(!defined(__DISABLE_SHORTCUTS_MENU__))
	#ifndef __MMI_DEDICATED_KEY_SHORTCUTS__
	#define __MMI_DEDICATED_KEY_SHORTCUTS__
	#endif
#endif


#if ((defined(__MMI_UI_CATEGORY_DIAL_TYPE_SEL__) && (__MMI_UI_CATEGORY_DIAL_TYPE_SEL__ == DIAL_TYPE_DEFAULT)))
	#ifndef __MMI_DEFAULT_DIAL__
	#define __MMI_DEFAULT_DIAL__
	#endif
#endif


#if defined(CFG_MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE) && ((CFG_MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE == __ON__)||(CFG_MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE == __AUTO__))
	#ifndef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
	#define __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
	#endif
#endif


#ifndef __MMI_DEFAULT_THEME_1__
#define __MMI_DEFAULT_THEME_1__
#endif


#if (defined(MMI_MAIN_LCD_DEFAULT_FORMAT) && (MMI_MAIN_LCD_DEFAULT_FORMAT == 24))
	#ifndef MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL
	#define MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL	24
	#endif
#elif (defined(MMI_MAIN_LCD_DEFAULT_FORMAT) && (MMI_MAIN_LCD_DEFAULT_FORMAT == 32))
	#ifndef MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL
	#define MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL	32
	#endif
#else
	#ifndef MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL
	#define MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL	16
	#endif
#endif


#ifndef __MMI_DEVICE_BMP_FORMAT__
#define __MMI_DEVICE_BMP_FORMAT__	MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_DIALER_CUI_SUPPORT__
	#define __MMI_DIALER_CUI_SUPPORT__
	#endif
#endif


#if (defined(__MEDIA_VT__))
	#ifndef __MMI_VIDEO_TELEPHONY__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2)) ||\
	 (defined(__MMI_FTE_SUPPORT__) && (MMI_MAX_SIM_NUM > 2))
	#ifndef __MMI_DIALER_DYNAMIC_CALL_UI__
	#define __MMI_DIALER_DYNAMIC_CALL_UI__
	#endif
#endif


#if defined(CFG_MMI_DIGITAL_CLOCK) && ((CFG_MMI_DIGITAL_CLOCK == __ON__)||(CFG_MMI_DIGITAL_CLOCK == __AUTO__))
	#ifndef __MMI_DIGITAL_CLOCK__
	#define __MMI_DIGITAL_CLOCK__
	#endif
#endif


#if defined(CFG_MMI_UI_TECHNO_IDLESCREEN_BAR) && ((CFG_MMI_UI_TECHNO_IDLESCREEN_BAR == __ON__)||(CFG_MMI_UI_TECHNO_IDLESCREEN_BAR == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X480__))
	#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__
	#define __MMI_UI_TECHNO_IDLESCREEN_BAR__
	#endif
#endif


#if defined(CFG_MMI_DIGITAL_CLOCK_IMAGE_NUMBER) && ((CFG_MMI_DIGITAL_CLOCK_IMAGE_NUMBER == __ON__)||(CFG_MMI_DIGITAL_CLOCK_IMAGE_NUMBER == __AUTO__)) && \
	(defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__))
	#ifndef __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
	#define __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
	#endif
#endif


#if defined(CFG_MMI_DLA_SLIM) && ((CFG_MMI_DLA_SLIM == __ON__)||(CFG_MMI_DLA_SLIM == __AUTO__)) && \
	(defined (__MMI_DOWNLOAD_AGENT__))
	#ifndef __MMI_DLA_SLIM__
	#define __MMI_DLA_SLIM__
	#endif
#endif


#if defined(CFG_MMI_THEMES_APPLICATION) && ((CFG_MMI_THEMES_APPLICATION == __ON__)||(CFG_MMI_THEMES_APPLICATION == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__) || defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_THEMES_APPLICATION__
	#define __MMI_THEMES_APPLICATION__
	#endif
#endif


#if (defined(__MMI_THEMES_APPLICATION__) && defined(__DOWNLOADABLE_THEME__) && !defined(__COSMOS_MMI_PACKAGE__) && defined(__XML_SUPPORT__) && defined(WAP_SUPPORT) && defined(BROWSER_SUPPORT))
	#if (!defined(__MMI_FILE_MANAGER__))
	#error "please define __MMI_FILE_MANAGER__ for __MMI_DOWNLOADABLE_THEMES_SUPPORT__"
	#endif
	#ifndef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
	#define __MMI_DOWNLOADABLE_THEMES_SUPPORT__
	#endif
#endif


#if (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) && ((__DLT_LOAD_ON_DEMAND_BUFFER_SIZE__ > 0) || (__DLT_ALWAYS_LOAD_BUFFER_SIZE__ > 0)))
	#ifndef __MMI_DLT_CACHE_SUPPORT__
	#define __MMI_DLT_CACHE_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_DM_BW_WITHOUT_WALLPAPER__
	#define __MMI_DM_BW_WITHOUT_WALLPAPER__
	#endif
#endif


#if defined(CFG_MMI_DM_SELF_REGISTER_SUPPORT) && ((CFG_MMI_DM_SELF_REGISTER_SUPPORT == __ON__)||(CFG_MMI_DM_SELF_REGISTER_SUPPORT == __AUTO__))
	#ifndef __MMI_DM_SELF_REGISTER_SUPPORT__
	#define __MMI_DM_SELF_REGISTER_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT) && ((CFG_MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT == __ON__)||(CFG_MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT == __AUTO__)) && \
	(defined(__MMI_APP_ICON_FW_SUPPORT__))
	#ifndef __MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__
	#define __MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__
	#endif
#endif


#if (defined(__MMI_APP_ICON_FW_SUPPORT__))
	#ifndef __MMI_PHNSET_APPICON_SUPPORT__
	#define __MMI_PHNSET_APPICON_SUPPORT__
	#endif
#endif


#if (defined(__MMI_DOWNLOADABLE_APP_ICON_FW_SUPPORT__)  && defined(__MMI_PHNSET_APPICON_SUPPORT__))
	#ifndef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
	#define __MMI_DOWNLOADABLE_APPICON_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_DTCNT_SLIM) && ((CFG_MMI_DTCNT_SLIM == __ON__)||(CFG_MMI_DTCNT_SLIM == __AUTO__)) && \
	(defined(__TCPIP__))
	#ifndef __MMI_DTCNT_SLIM__
	#define __MMI_DTCNT_SLIM__
	#endif
#endif


#if defined(CFG_MMI_DTCNT_XML_SLIM) && ((CFG_MMI_DTCNT_XML_SLIM == __ON__)||(CFG_MMI_DTCNT_XML_SLIM == __AUTO__)) && \
	(defined(__TCPIP__))
	#ifndef __MMI_DTCNT_XML_SLIM__
	#define __MMI_DTCNT_XML_SLIM__
	#endif
#endif


#if defined(CFG_MMI_DUAL_CLOCK) && ((CFG_MMI_DUAL_CLOCK == __ON__)||(CFG_MMI_DUAL_CLOCK == __AUTO__)) && \
	(defined(__MMI_TIMEZONE_SETTING__) &&  ( defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)))
	#ifndef __MMI_DUAL_CLOCK__
	#define __MMI_DUAL_CLOCK__
	#endif
#endif


#if (defined(__DUAL_MIC_SUPPORT__) && (defined(__PLUTO_MMI_PACKAGE__) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_DUAL_MIC_SUPPORT__
	#define __MMI_DUAL_MIC_SUPPORT__
	#endif
#endif


#if (defined(__GEMINI__) && (!defined(__SINGLE_SIM_MMI_ONLY__)))
	#ifndef __MMI_DUAL_SIM_SINGLE_CALL_SLAVE__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_DUAL_SIM_MASTER__) && defined(__MMI_DUAL_SIM_SINGLE_CALL_SLAVE__) && (!defined(__SINGLE_SIM_MMI_ONLY__)))
	#ifndef __MMI_DUAL_SIM_SINGLE_CALL__
/* under construction !*/
	#endif
#endif


#if ((defined(__MMI_DUAL_SIM_MASTER__) && !defined(__MMI_DUAL_SIM_SINGLE_CALL_SLAVE__)) || defined(__MMI_DUAL_SIM_DUAL_CALL_SLAVE__)&& (!defined(__SINGLE_SIM_MMI_ONLY__)))
	#ifndef __MMI_DUAL_SIM_DUAL_CALL__
	#define __MMI_DUAL_SIM_DUAL_CALL__
	#endif
#endif


#if ((defined(__MMI_DUAL_SIM_SINGLE_CALL__) || defined(__MMI_DUAL_SIM_DUAL_CALL__))&& (!defined(__SINGLE_SIM_MMI_ONLY__)))
	#ifndef __MMI_DUAL_SIM__
/* under construction !*/
	#endif
#endif


#if (defined( __CTA_DUAL_SIM_STANDARD__) && defined(__GEMINI__))
	#ifndef __MMI_DUAL_SIM_DYNAMIC_MODE__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_DUAL_SIM_STATIC_MODE) && ((CFG_MMI_DUAL_SIM_STATIC_MODE == __ON__)||(CFG_MMI_DUAL_SIM_STATIC_MODE == __AUTO__)) && \
	(defined(__MMI_DUAL_SIM_DYNAMIC_MODE__)) || (!defined(__MMI_DUAL_SIM_DYNAMIC_MODE__) && defined(__GEMINI__))
	#ifndef __MMI_DUAL_SIM_STATIC_MODE__
	#define __MMI_DUAL_SIM_STATIC_MODE__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_DUN_PROFILE__))
	#ifndef __MMI_DUN_SUPPORT__
	#define __MMI_DUN_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_DYNAMIC_SIM_DYNAMIC_UI) && ((CFG_MMI_DYNAMIC_SIM_DYNAMIC_UI == __ON__)||(CFG_MMI_DYNAMIC_SIM_DYNAMIC_UI == __AUTO__)) && \
	(defined(__MMI_FTE_SUPPORT__) && (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
	#ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	#define __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	#endif
#endif


#if defined(CFG_MMI_EBOOK_READER) && ((CFG_MMI_EBOOK_READER == __ON__)||(CFG_MMI_EBOOK_READER == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_EBOOK_READER__
	#define __MMI_EBOOK_READER__
	#endif
#endif


#if defined(CFG_MMI_ECOMPASS) && ((CFG_MMI_ECOMPASS == __ON__)||(CFG_MMI_ECOMPASS == __AUTO__))
	#ifndef __MMI_ECOMPASS__
	#define __MMI_ECOMPASS__
	#endif
#endif


#if defined(CFG_MMI_EDITABLE_AUDIO_EQUALIZER) && ((CFG_MMI_EDITABLE_AUDIO_EQUALIZER == __ON__)||(CFG_MMI_EDITABLE_AUDIO_EQUALIZER == __AUTO__)) && \
	(defined(__BES_EQ_SUPPORT__) && defined(__MMI_AUDIO_EQUALIZER__))
	#ifndef __MMI_EDITABLE_AUDIO_EQUALIZER__
	#define __MMI_EDITABLE_AUDIO_EQUALIZER__
	#endif
#endif


#if defined(CFG_MMI_IME_EDITOR_PEN_VK_UNFOLD) && ((CFG_MMI_IME_EDITOR_PEN_VK_UNFOLD == __ON__)||(CFG_MMI_IME_EDITOR_PEN_VK_UNFOLD == __AUTO__)) && \
	(defined( __MMI_TOUCH_SCREEN__))
	#ifndef __MMI_IME_EDITOR_PEN_VK_UNFOLD__
	#define __MMI_IME_EDITOR_PEN_VK_UNFOLD__
	#endif
#endif


#if (defined(__MMI_IME_EDITOR_PEN_VK_UNFOLD__))
	#ifndef __MMI_EDITOR_PEN_VK_UNFOLD__
	#define __MMI_EDITOR_PEN_VK_UNFOLD__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__))
	#ifndef __MMI_EM_DEV_BACKLIGHT__
	#define __MMI_EM_DEV_BACKLIGHT__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(DRV_PWM_DRV_TOOL_SUPPORT) &&   !defined(__MMI_EM_DEV_BACKLIGHT__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_60BACKLIGHT__
	#define __MMI_EM_60BACKLIGHT__
	#endif
#endif


#if defined(CFG_MMI_EM_AUDIO) && ((CFG_MMI_EM_AUDIO == __ON__)||(CFG_MMI_EM_AUDIO == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__) && ((CFG_MMI_EM_AUDIO == __ON__) || !defined(__MMI_SLIM_ENGINEER_MODE__)))
	#ifndef __MMI_EM_AUDIO__
	#define __MMI_EM_AUDIO__
	#endif
#endif


#if (defined(AUD_REC_ENABLE) && defined(__VM_CODEC_SUPPORT__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_AUDIO_AUTO_VM__
	#define __MMI_EM_AUDIO_AUTO_VM__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_AUDIO_DEBUG_INFO__
	#define __MMI_EM_AUDIO_DEBUG_INFO__
	#endif
#endif


#if defined(CFG_MMI_EM_BT_AUDIO_CONN) && ((CFG_MMI_EM_BT_AUDIO_CONN == __ON__)||(CFG_MMI_EM_BT_AUDIO_CONN == __AUTO__)) && \
	(defined(__MMI_HFP_SUPPORT__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_BT_AUDIO_CONN__
	#define __MMI_EM_BT_AUDIO_CONN__
	#endif
#endif


#if defined(CFG_MMI_EM_BT_TEST_SLIM) && ((CFG_MMI_EM_BT_TEST_SLIM == __ON__)||(CFG_MMI_EM_BT_TEST_SLIM == __AUTO__))
	#ifndef __MMI_EM_BT_TEST_SLIM__
	#define __MMI_EM_BT_TEST_SLIM__
	#endif
#endif


#if ((defined(__MMI_BT_SUPPORT__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_BT_TEST_SLIM__)))
	#ifndef __MMI_EM_BT_GENERAL_TEST__
	#define __MMI_EM_BT_GENERAL_TEST__
	#endif
#endif


#if (defined(__MMI_AVRCP_SUPPORT__) && defined(__MMI_ENGINEER_MODE__) && defined(__MMI_EM_BT_GENERAL_TEST__))
	#ifndef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
	#define __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
	#endif
#endif


#if (defined(__MMI_EM_BT_BQB_HID_SUPPORT__))
	#ifndef __MMI_EM_BT_BQB_SUPPORT__
	#define __MMI_EM_BT_BQB_SUPPORT__
	#endif
#endif


#if (defined (__MMI_BT_SUPPORT__) && defined(__MMI_ENGINEER_MODE__) && !defined (__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_BT_GET_CHIP_VERION__
/* under construction !*/
	#endif
#endif


#if ((defined(__MMI_BT_SUPPORT__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_BT_TEST_SLIM__)))
	#ifndef __MMI_EM_BT_RF_TEST__
	#define __MMI_EM_BT_RF_TEST__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_BT_UPF_IOT_TEST__
	#define __MMI_EM_BT_UPF_IOT_TEST__
	#endif
#endif


#if (defined(AAA_ENGINEER_MODE))
	#ifndef __MMI_EM_CAM_AF_CONTSHOT__
	#define __MMI_EM_CAM_AF_CONTSHOT__
	#endif
#endif


#if (defined(__SEARCH_ALL_EHPLMN_TOGETHER__)&& defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_CTA_OPERATOR_TEST__
	#define __MMI_EM_CTA_OPERATOR_TEST__
	#endif
#endif


#if defined(CFG_MMI_EM_CTM_CTA_TDD) && ((CFG_MMI_EM_CTM_CTA_TDD == __ON__)||(CFG_MMI_EM_CTM_CTA_TDD == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_CTM_CTA_TDD__
	#define __MMI_EM_CTM_CTA_TDD__
	#endif
#endif


#if (defined(__MMI_FILE_MANAGER__) && defined(__MMI_ENGINEER_MODE__)&& !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_DEBUG_INFO_DRIVE_LETTER__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_DEBUG_INFO_SYS_STATS__
/* under construction !*/
	#endif
#endif


#if (defined(__GPS_SUPPORT__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_AGPS__
	#define __MMI_EM_DEV_AGPS__
	#endif
#endif


#if (defined(__AGPS_CONTROL_PLANE__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_AGPS_CONTROL_PLANE__
	#define __MMI_EM_DEV_AGPS_CONTROL_PLANE__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_CLAM) && ((CFG_MMI_EM_DEV_CLAM == __ON__)||(CFG_MMI_EM_DEV_CLAM == __AUTO__)) && \
	(defined(__MMI_CLAMSHELL__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_CLAM__
	#define __MMI_EM_DEV_CLAM__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_DCM_MODE) && ((CFG_MMI_EM_DEV_DCM_MODE == __ON__)||(CFG_MMI_EM_DEV_DCM_MODE == __AUTO__)) && \
	(defined(DCM_ENABLE) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_DCM_MODE__
	#define __MMI_EM_DEV_DCM_MODE__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_EINT) && ((CFG_MMI_EM_DEV_EINT == __ON__)||(CFG_MMI_EM_DEV_EINT == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_EINT__
	#define __MMI_EM_DEV_EINT__
	#endif
#endif


#if (defined(FM_RADIO_ENABLE))
	#ifndef __MMI_FM_RADIO__
	#define __MMI_FM_RADIO__
	#endif
#endif


#if (defined(__MMI_FM_RADIO__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_FM_RADIO__
	#define __MMI_EM_DEV_FM_RADIO__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_GPIO__
	#define __MMI_EM_DEV_GPIO__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_MEMORY_TEST) && ((CFG_MMI_EM_DEV_MEMORY_TEST == __ON__)||(CFG_MMI_EM_DEV_MEMORY_TEST == __AUTO__)) && \
	(defined (__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_MEMORY_TEST__
	#define __MMI_EM_DEV_MEMORY_TEST__
	#endif
#endif


#if (defined(NAND_SUPPORT) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_DEV_NAND_FORMAT__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_PMU_REGISTER_SETTING) && ((CFG_MMI_EM_DEV_PMU_REGISTER_SETTING == __ON__)||(CFG_MMI_EM_DEV_PMU_REGISTER_SETTING == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_PMU_REGISTER_SETTING__
	#define __MMI_EM_DEV_PMU_REGISTER_SETTING__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_PXS_SENSOR) && ((CFG_MMI_EM_DEV_PXS_SENSOR == __ON__)||(CFG_MMI_EM_DEV_PXS_SENSOR == __AUTO__)) && \
	(defined(__PXS_APP_ENABLE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_PXS_SENSOR__
	#define __MMI_EM_DEV_PXS_SENSOR__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_SET_HW_LEVEL__
	#define __MMI_EM_DEV_SET_HW_LEVEL__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_SET_UART__
	#define __MMI_EM_DEV_SET_UART__
	#endif
#endif


#if defined(CFG_MMI_EM_SLEEP_MODE_SLIM) && ((CFG_MMI_EM_SLEEP_MODE_SLIM == __ON__)||(CFG_MMI_EM_SLEEP_MODE_SLIM == __AUTO__))
	#ifndef __MMI_EM_SLEEP_MODE_SLIM__
	#define __MMI_EM_SLEEP_MODE_SLIM__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_SLEEP_MODE) && ((CFG_MMI_EM_DEV_SLEEP_MODE == __ON__)||(CFG_MMI_EM_DEV_SLEEP_MODE == __AUTO__)) && \
	((defined(__MMI_ENGINEER_MODE__)&&!defined(__MMI_EM_SLEEP_MODE_SLIM__)))
	#ifndef __MMI_EM_DEV_SLEEP_MODE__
	#define __MMI_EM_DEV_SLEEP_MODE__
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_TST_OUTPUT_MODE) && ((CFG_MMI_EM_DEV_TST_OUTPUT_MODE == __ON__)||(CFG_MMI_EM_DEV_TST_OUTPUT_MODE == __AUTO__)) && \
	(defined(__TST_WRITE_TO_FILE__) && defined(__MMI_ENGINEER_MODE__) && (CFG_MMI_EM_DEV_TST_OUTPUT_MODE ==__ON__ || !defined(__MMI_SLIM_ENGINEER_MODE__)))
	#ifndef __MMI_EM_DEV_TST_OUTPUT_MODE__
	#define __MMI_EM_DEV_TST_OUTPUT_MODE__
	#endif
#endif


#if ((defined(__USB_MASS_STORAGE_ENABLE__ ) || defined(__MTP_ENABLE__)) && defined(__MMI_ENGINEER_MODE__)  && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_DEV_USB_BOOT_MODE__
/* under construction !*/
	#endif
#endif


#if (defined(__USB_LOGGING__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
	#endif
#endif


#if (defined(__OTG_ENABLE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_DEV_USB_OTG_SRP__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_DEV_USB_TETHERING) && ((CFG_MMI_EM_DEV_USB_TETHERING == __ON__)||(CFG_MMI_EM_DEV_USB_TETHERING == __AUTO__)) && \
	(defined(__USB_TETHERING__) && defined(__MMI_ENGINEER_MODE__)  && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_USB_TETHERING__
	#define __MMI_EM_DEV_USB_TETHERING__
	#endif
#endif


#if (defined (__WIFI_SUPPORT__) && defined (__CUSTOM_WIFI_FEATURES_SWITCH__))
	#ifndef __MMI_WLAN_FEATURES__
	#define __MMI_WLAN_FEATURES__
	#endif
#endif


#if (defined(__MMI_WLAN_FEATURES__) && defined(WIFI_AUTH_FULL_EAP) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_DEV_WLAN_EAP_MODE__
	#define __MMI_EM_DEV_WLAN_EAP_MODE__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(__TC01__))
	#ifndef __MMI_EM_FACTORY_LCD_TEST__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_GPRS_AUTO_ATTACH) && ((CFG_MMI_EM_GPRS_AUTO_ATTACH == __ON__)||(CFG_MMI_EM_GPRS_AUTO_ATTACH == __AUTO__)) && \
	(defined(__PS_SERVICE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_GPRS_AUTO_ATTACH__
	#define __MMI_EM_GPRS_AUTO_ATTACH__
	#endif
#endif


#if (defined(__TCPIP__) && (defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_GPRS_FAST_DORMANCY) && ((CFG_MMI_EM_GPRS_FAST_DORMANCY == __ON__)||(CFG_MMI_EM_GPRS_FAST_DORMANCY == __AUTO__)) && \
	((defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_GPRS_FAST_DORMANCY__
	#define __MMI_EM_GPRS_FAST_DORMANCY__
	#endif
#endif


#if defined(CFG_MMI_EM_GPRS_PDP_SLIM) && ((CFG_MMI_EM_GPRS_PDP_SLIM == __ON__)||(CFG_MMI_EM_GPRS_PDP_SLIM == __AUTO__))
	#ifndef __MMI_EM_GPRS_PDP_SLIM__
	#define __MMI_EM_GPRS_PDP_SLIM__
	#endif
#endif


#if defined(CFG_MMI_EM_GPRS_PDP) && ((CFG_MMI_EM_GPRS_PDP == __ON__)||(CFG_MMI_EM_GPRS_PDP == __AUTO__)) && \
	((defined(__PS_SERVICE__) && defined(__MMI_ENGINEER_MODE__)&& !defined(__MMI_EM_GPRS_PDP_SLIM__)))
	#ifndef __MMI_EM_GPRS_PDP__
	#define __MMI_EM_GPRS_PDP__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_INET_APP_SLIM__
	#define __MMI_EM_INET_APP_SLIM__
	#endif
#endif


#if (defined (__IPERF__) && defined(__MMI_ENGINEER_MODE__)&&!defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_IPERF__
	#define __MMI_EM_IPERF__
	#endif
#endif


#if (defined(__J2ME__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_JAVA_HEAP_SIZE_SETTING__
/* under construction !*/
	#endif
#endif


#if (defined(__J2ME__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_JAVA_J2ME__
	#define __MMI_EM_JAVA_J2ME__
	#endif
#endif


#if (defined(__J2ME__) && defined(__MMI_ENGINEER_MODE__)  && !defined (__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_JAVA_PERFORMANCE__
/* under construction !*/
	#endif
#endif


#if (defined(__J2ME__) && defined(__MMI_ENGINEER_MODE__)  && !defined (__MMI_SLIM_ENGINEER_MODE__) &&defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_JUI_DEBUG__
/* under construction !*/
	#endif
#endif


#if (defined(__J2ME__) || defined(__MMI_EM_JAVA_HEAP_SIZE_SETTING__) || defined(__MMI_EM_MISC_JAVA_PERFORMANCE__) || defined(__MMI_EM_MISC_JUI_DEBUG__))
	#ifndef __MMI_EM_JAVA_SUPPORT__
	#define __MMI_EM_JAVA_SUPPORT__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_AUTO_RESET__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && (defined(__RF_DESENSE_TEST__) || !defined(__MMI_SLIM_ENGINEER_MODE__)) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_BACKLIGHT__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_CELL_RESELECTION__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_ULTRA_SLIM_FILE_MANAGER) && ((CFG_MMI_ULTRA_SLIM_FILE_MANAGER == __ON__)||(CFG_MMI_ULTRA_SLIM_FILE_MANAGER == __AUTO__)) && \
	(defined(__MMI_FILE_MANAGER__) && (((defined(__32_32_SEG__)||defined(__24_32_SEG__)||defined(__16_32_SEG__)||defined(__8_32_SEG__)) && !defined(__COSMOS_MMI_PACKAGE__)) || (defined(__COSMOS_MMI_PACKAGE__) && defined(__COSMOS_NO_USER_DRIVE__))))
	#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
	#define __MMI_ULTRA_SLIM_FILE_MANAGER__
	#endif
#endif


#if defined(CFG_MMI_SLIM_FILE_MANAGER) && ((CFG_MMI_SLIM_FILE_MANAGER == __ON__)||(CFG_MMI_SLIM_FILE_MANAGER == __AUTO__)) && \
	(defined(__MMI_ULTRA_SLIM_FILE_MANAGER__) || (defined(__MMI_FILE_MANAGER__)&& (defined(__32_32_SEG__)||defined(__24_32_SEG__)||defined(__16_32_SEG__)||defined(__8_32_SEG__)))|| (defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_SLIM_FILE_MANAGER__
	#define __MMI_SLIM_FILE_MANAGER__
	#endif
#endif


#if (defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(__MMI_SLIM_FILE_MANAGER__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_CHECK_DRIVE__
/* under construction !*/
	#endif
#endif


#if (defined(__DCD_SUPPORT__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_DCD__
	#define __MMI_EM_MISC_DCD__
	#endif
#endif


#if (defined(__MMI_DM_SELF_REGISTER_SUPPORT__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_DM_REGISTER__
	#define __MMI_EM_MISC_DM_REGISTER__
	#endif
#endif


#if (defined(__FOTA_DM__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_FOTA_DEBUG__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_HIGHSPEED_SIM__
/* under construction !*/
	#endif
#endif


#if (!defined (MED_NOT_PRESENT) && defined(__MMI_ENGINEER_MODE__) && !defined (__MMI_SLIM_ENGINEER_MODE__) && defined (__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_MEDIA_MEMORY_SETTING__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_MEMORY_DUMP__
	#define __MMI_EM_MISC_MEMORY_DUMP__
	#endif
#endif


#if defined(CFG_MMI_EM_MISC_MULTI_TOUCH) && ((CFG_MMI_EM_MISC_MULTI_TOUCH == __ON__)||(CFG_MMI_EM_MISC_MULTI_TOUCH == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && defined(__MMI_VUI_ENGINE__)&& defined(__VENUS_UI_ENGINE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_MULTI_TOUCH__
	#define __MMI_EM_MISC_MULTI_TOUCH__
	#endif
#endif


#if defined(CFG_MMI_EM_MISC_POWER_ON_CPU_QUERY) && ((CFG_MMI_EM_MISC_POWER_ON_CPU_QUERY == __ON__)||(CFG_MMI_EM_MISC_POWER_ON_CPU_QUERY == __AUTO__)) && \
	((defined(__UMTS_TDD128_MODE__) || (CFG_MMI_EM_MISC_POWER_ON_CPU_QUERY == __ON__) || !defined(__MMI_SLIM_ENGINEER_MODE__)) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
	#define __MMI_EM_MISC_POWER_ON_CPU_QUERY__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_RAM_TEST__
	#define __MMI_EM_MISC_RAM_TEST__
	#endif
#endif


#if ((defined (__MMI_CAMCORDER__) || defined (__MMI_VIDEO_RECORDER__)) && defined(__MMI_ENGINEER_MODE__) && !defined (__MMI_SLIM_ENGINEER_MODE__)  && defined (__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_RECORDER_SETTING__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_MISC_TOUCH_SCREEN) && ((CFG_MMI_EM_MISC_TOUCH_SCREEN == __ON__)||(CFG_MMI_EM_MISC_TOUCH_SCREEN == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_MISC_TOUCH_SCREEN__
	#define __MMI_EM_MISC_TOUCH_SCREEN__
	#endif
#endif


#if (defined(__MMI_VIDEO_RECORDER__) && defined(ISP_SUPPORT) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_VIDEO_HI_BITRATE__
/* under construction !*/
	#endif
#endif


#if (defined(__3G_VIDEO_CALL__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_VIDEO_PARAM__
/* under construction !*/
	#endif
#endif


#if (defined(__CARD_DOWNLOAD__) && defined(__MMI_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_MISC_X_DOWNLOAD__
/* under construction !*/
	#endif
#endif


#if ((defined (__MTV_SUPPORT__)  || defined (__ATV_SUPPORT__)) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_MOBILE_TV_SETTING__
	#define __MMI_EM_MOBILE_TV_SETTING__
	#endif
#endif


#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_MOTION_APP__
	#define __MMI_EM_MOTION_APP__
	#endif
#endif


#if defined(CFG_MMI_EM_NW_NETWORK_INFO) && ((CFG_MMI_EM_NW_NETWORK_INFO == __ON__)||(CFG_MMI_EM_NW_NETWORK_INFO == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_NETWORK_INFO__
	#define __MMI_EM_NW_NETWORK_INFO__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_BAND_SEL__
	#define __MMI_EM_NW_BAND_SEL__
	#endif
#endif


#if (defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_NW_PREFER_RAT__
/* under construction !*/
	#endif
#endif


#if (defined(__MODEM_EM_MODE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_NW_CELL_LOCK__
/* under construction !*/
	#endif
#endif


#if (defined(__MODEM_EM_MODE__)  && defined( __UMTS_RAT__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__)&& defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_NW_PLMN_LIST) && ((CFG_MMI_EM_NW_PLMN_LIST == __ON__)||(CFG_MMI_EM_NW_PLMN_LIST == __AUTO__)) && \
	(defined(__PLMN_LIST_PREF_SUPPORT__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_PLMN_LIST__
	#define __MMI_EM_NW_PLMN_LIST__
	#endif
#endif


#if defined(CFG_MMI_EM_NW_SERVICE_MODE_SELECTION) && ((CFG_MMI_EM_NW_SERVICE_MODE_SELECTION == __ON__)||(CFG_MMI_EM_NW_SERVICE_MODE_SELECTION == __AUTO__)) && \
	(defined(__GSM_RAT__) && defined(__UMTS_RAT__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_SERVICE_MODE_SELECTION__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_EM_NW_NETWORK_INFO__) || defined(__MMI_EM_NW_BAND_SEL__) || defined(__MMI_EM_NW_PREFER_RAT__) || defined(__MMI_EM_NW_CELL_LOCK__) || defined(__MMI_EM_NW_EVENT_NOTIFY__) || defined(__MMI_EM_NW_PLMN_LIST__) || defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__) || defined(__MMI_EM_NW_GPRS_CONN__))
	#ifndef __MMI_EM_NETWORK_SETTINGS__
	#define __MMI_EM_NETWORK_SETTINGS__
	#endif
#endif


#if defined(CFG_MMI_EM_NFC_SUPPORT) && ((CFG_MMI_EM_NFC_SUPPORT == __ON__)||(CFG_MMI_EM_NFC_SUPPORT == __AUTO__)) && \
	(defined(__NFC_SUPPORT__) && (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__)))
	#ifndef __MMI_EM_NFC_SUPPORT__
	#define __MMI_EM_NFC_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_EM_NW_FDD_NETWORK_INFO) && ((CFG_MMI_EM_NW_FDD_NETWORK_INFO == __ON__)||(CFG_MMI_EM_NW_FDD_NETWORK_INFO == __AUTO__)) && \
	(defined(__MODEM_EM_MODE__) && defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_FDD_NETWORK_INFO__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_NW_TDD_NETWORK_INFO) && ((CFG_MMI_EM_NW_TDD_NETWORK_INFO == __ON__)||(CFG_MMI_EM_NW_TDD_NETWORK_INFO == __AUTO__)) && \
	(defined(__MODEM_EM_MODE__) && defined(__UMTS_TDD128_MODE__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_TDD_NETWORK_INFO__
	#define __MMI_EM_NW_TDD_NETWORK_INFO__
	#endif
#endif


#if defined(CFG_MMI_EM_NW_WCDMA_PREFERRED) && ((CFG_MMI_EM_NW_WCDMA_PREFERRED == __ON__)||(CFG_MMI_EM_NW_WCDMA_PREFERRED == __AUTO__)) && \
	(defined(__UMTS_FDD_PREFER__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_NW_WCDMA_PREFERRED__
	#define __MMI_EM_NW_WCDMA_PREFERRED__
	#endif
#endif


#if (defined(__PLUTO_MMI_PACKAGE__) && ((defined(MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__)) && !defined(__MMI_MEDIA_PLAYER__)) && (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) ||defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)|| defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)))
	#ifndef __MMI_VIDEO_PLAYER__
	#define __MMI_VIDEO_PLAYER__
	#endif
#endif


#if (defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_PROFILING_VT_LOOKBACK__
/* under construction !*/
	#endif
#endif


#if ((defined(__MMI_CAMERA__) || defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_EM_PROFILING_VT_LOOKBACK__)) &&   defined(__MMI_ENGINEER_MODE__)  &&   defined(__MTK_INTERNAL__) &&   !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_PROFILING_MULTIMEDIA_PROFILING__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_INTERACTIVE_PROFILNG) && ((CFG_MMI_INTERACTIVE_PROFILNG == __ON__)||(CFG_MMI_INTERACTIVE_PROFILNG == __AUTO__)) && \
	(defined(__MMI_ENGINEER_MODE__) && ((CFG_MMI_INTERACTIVE_PROFILNG == __ON__) || !defined(__MMI_SLIM_ENGINEER_MODE__)))
	#ifndef __MMI_INTERACTIVE_PROFILNG__
	#define __MMI_INTERACTIVE_PROFILNG__
	#endif
#endif


#if defined(CFG_MMI_UI_BENCHMARK) && ((CFG_MMI_UI_BENCHMARK == __ON__)||(CFG_MMI_UI_BENCHMARK == __AUTO__)) && \
	(!defined(LOW_COST_SUPPORT) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_UI_BENCHMARK__
	#define __MMI_UI_BENCHMARK__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(__MTK_INTERNAL__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_PROFILING_GDI_PROFILING__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_PROFILING_SWLA) && ((CFG_MMI_EM_PROFILING_SWLA == __ON__)||(CFG_MMI_EM_PROFILING_SWLA == __AUTO__)) && \
	(((CFG_MMI_EM_PROFILING_SWLA == __ON__) || !defined(__MMI_SLIM_ENGINEER_MODE__)) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_PROFILING_SWLA__
	#define __MMI_EM_PROFILING_SWLA__
	#endif
#endif


#if (defined(__MMI_EM_PROFILING_MULTIMEDIA_PROFILING__) || defined(__MMI_INTERACTIVE_PROFILNG__) || defined(__MMI_UI_BENCHMARK__) || defined(__MMI_EM_PROFILING_FS_TEST__) || defined(__MMI_CSB_BROWSER__) || defined(__MMI_EM_PROFILING_GDI_PROFILING__) || defined(__MMI_EM_PROFILING_SWLA__))
	#ifndef __MMI_EM_PROFILING__
	#define __MMI_EM_PROFILING__
	#endif
#endif


#if (defined(__MMI_EM_PROFILING_GDI_PROFILING__) && (!defined(__LOW_COST_SUPPORT_COMMON__)))
	#ifndef __MMI_EM_PROFILING_GDI_UI_INDEX__
	#define __MMI_EM_PROFILING_GDI_UI_INDEX__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && defined(__MTK_INTERNAL__) && defined (__MMI_FILE_MANAGER__) && defined(__MMI_EM_PROFILING_GDI_PROFILING__))
	#ifndef __MMI_EM_PROFILING_IMG_DEC__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_VUI_ENGINE__) && defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
	#define __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
	#endif
#endif


#if (defined(__RF_DESENSE_TEST__) && defined(__MMI_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_RF_DESENSE_TEST__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_EM_RF_GSM) && ((CFG_MMI_EM_RF_GSM == __ON__)||(CFG_MMI_EM_RF_GSM == __AUTO__)) && \
	(((CFG_MMI_EM_RF_GSM == __ON__) && defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_ENGINEER_MODE__)) || ((CFG_MMI_EM_RF_GSM == __AUTO__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_ENGINEER_MODE__)))
	#ifndef __MMI_EM_RF_GSM__
	#define __MMI_EM_RF_GSM__
	#endif
#endif


#if defined(CFG_MMI_EM_RF_WIFI) && ((CFG_MMI_EM_RF_WIFI == __ON__)||(CFG_MMI_EM_RF_WIFI == __AUTO__)) && \
	(defined(__MMI_WLAN_FEATURES__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_RF_WIFI__
	#define __MMI_EM_RF_WIFI__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MTK_INTERNAL__))
	#ifndef __MMI_EM_SW_PATCH__
/* under construction !*/
	#endif
#endif


#if (defined (__VIDEO_ARCHI_V2__) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_VIDEO_SETTING__
	#define __MMI_EM_VIDEO_SETTING__
	#endif
#endif


#if defined(CFG_MMI_EM_VIDEO_STREAMING_SETTING) && ((CFG_MMI_EM_VIDEO_STREAMING_SETTING == __ON__)||(CFG_MMI_EM_VIDEO_STREAMING_SETTING == __AUTO__)) && \
	(defined(STREAM_SUPPORT) && defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_SLIM_ENGINEER_MODE__))
	#ifndef __MMI_EM_VIDEO_STREAMING_SETTING__
	#define __MMI_EM_VIDEO_STREAMING_SETTING__
	#endif
#endif


#if (defined(__EMAIL__) && defined(EMAIL_BCC))
	#ifndef __MMI_EMAIL_BCC__
	#define __MMI_EMAIL_BCC__
	#endif
#endif


#if defined(CFG_MMI_EMAIL_HTML) && ((CFG_MMI_EMAIL_HTML == __ON__)||(CFG_MMI_EMAIL_HTML == __AUTO__)) && \
	(defined(__MMI_EMAIL__))
	#ifndef __MMI_EMAIL_HTML__
	#define __MMI_EMAIL_HTML__
	#endif
#endif


#if defined(CFG_MMI_EMAIL_IMAP_PUSH) && ((CFG_MMI_EMAIL_IMAP_PUSH == __ON__)||(CFG_MMI_EMAIL_IMAP_PUSH == __AUTO__)) && \
	(defined(__EMAIL__) && !defined(__NO_IMAP__))
	#ifndef __MMI_EMAIL_IMAP_PUSH__
	#define __MMI_EMAIL_IMAP_PUSH__
	#endif
#endif


#if (defined(__EMAIL__) && defined(__MMI_CCA_SUPPORT__))
	#ifndef __MMI_EMAIL_OTAP__
	#define __MMI_EMAIL_OTAP__
	#endif
#endif


#if (defined(__EMAIL__) && !defined(__NO_IMAP__) && defined(__IMAP_REMOTE_FOLDER__))
	#ifndef __MMI_EMAIL_REMOTE_FOLDER__
	#define __MMI_EMAIL_REMOTE_FOLDER__
	#endif
#endif


#if defined(CFG_MMI_EMAIL_SEND_BEFORE_SYNC) && ((CFG_MMI_EMAIL_SEND_BEFORE_SYNC == __ON__)||(CFG_MMI_EMAIL_SEND_BEFORE_SYNC == __AUTO__)) && \
	(defined(__EMAIL__))
	#ifndef __MMI_EMAIL_SEND_BEFORE_SYNC__
	#define __MMI_EMAIL_SEND_BEFORE_SYNC__
	#endif
#endif


#if (defined(__EMAIL__) && defined(JADE36V2_DEMO_BB) && defined(__FLAVOR_COSMOS__))
	#ifndef __MMI_EMAIL_SUPPORT_1000_MAILS__
	#define __MMI_EMAIL_SUPPORT_1000_MAILS__
	#endif
#endif


#if defined(CFG_MMI_EONS_SRV) && ((CFG_MMI_EONS_SRV == __ON__)||(CFG_MMI_EONS_SRV == __AUTO__))
	#ifndef __MMI_EONS_SRV__
	#define __MMI_EONS_SRV__
	#endif
#endif


#if (defined(JPG_DECODE) && defined(EXIF_SUPPORT))
	#ifndef __MMI_EXIF__
	#define __MMI_EXIF__
	#endif
#endif


#if (defined(__MMI_LAUNCHER_APP_LIST__))
	#ifndef __MMI_FANCY_SCREEN_LOCK__
	#define __MMI_FANCY_SCREEN_LOCK__
	#endif
#endif


#if defined(CFG_MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM) && ((CFG_MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM == __ON__)||(CFG_MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM == __AUTO__)) && \
	(defined(FONT_ENGINE_FREETYPE) || defined(FONT_ENGINE_FREETYPE_DEMO) || defined(FONT_ENGINE_ETRUMP))
	#ifndef __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__
	#define __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__
	#endif
#endif


#if defined(CFG_MMI_FILE_USEAS_SUPPORT) && (CFG_MMI_FILE_USEAS_SUPPORT == __ON__) || \
	((CFG_MMI_FILE_USEAS_SUPPORT == __AUTO__) || (defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_VUI_SHELL_FAV_CONTACT__)))
	#ifndef __MMI_FILE_USEAS_SUPPORT__
	#define __MMI_FILE_USEAS_SUPPORT__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_FM_AUTO_TEST__
	#define __MMI_FM_AUTO_TEST__
	#endif
#endif


#if (defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) && defined(__MMI_FACTORY_MODE__)&& defined(__MTK_TARGET__))
	#ifndef __MMI_FM_CAMERA_PREVIEW__
	#define __MMI_FM_CAMERA_PREVIEW__
	#endif
#endif


#if (defined(__DUAL_MIC_SUPPORT__) && defined(__MMI_FACTORY_MODE__))
	#ifndef __MMI_FM_DUAL_MIC_ECHO_LOOP__
	#define __MMI_FM_DUAL_MIC_ECHO_LOOP__
	#endif
#endif


#if (defined (__MMI_FACTORY_MODE__))
	#ifndef __MMI_FM_KEYPAD_TEST__
	#define __MMI_FM_KEYPAD_TEST__
	#endif
#endif


#if (defined(__MMI_ENGINEER_MODE__))
	#ifndef __MMI_FM_MERGE_AUTO_TEST__
	#define __MMI_FM_MERGE_AUTO_TEST__
	#endif
#endif


#if defined(CFG_MMI_SLIM_FACTORY_MODE) && ((CFG_MMI_SLIM_FACTORY_MODE == __ON__)||(CFG_MMI_SLIM_FACTORY_MODE == __AUTO__)) && \
	(defined(__MMI_FACTORY_MODE__))
	#ifndef __MMI_SLIM_FACTORY_MODE__
	#define __MMI_SLIM_FACTORY_MODE__
	#endif
#endif


#if (defined(__MMI_FACTORY_MODE__) && !defined(__MMI_SLIM_FACTORY_MODE__))
	#ifndef __MMI_FM_MTBF__
	#define __MMI_FM_MTBF__
	#endif
#endif


#if defined(CFG_MMI_FM_NFC_SUPPORT) && ((CFG_MMI_FM_NFC_SUPPORT == __ON__)||(CFG_MMI_FM_NFC_SUPPORT == __AUTO__)) && \
	(defined(__NFC_SUPPORT__) && defined(__MMI_FACTORY_MODE__))
	#ifndef __MMI_FM_NFC_SUPPORT__
	#define __MMI_FM_NFC_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_FM_PLUTO_SLIM) && ((CFG_MMI_FM_PLUTO_SLIM == __ON__)||(CFG_MMI_FM_PLUTO_SLIM == __AUTO__)) && \
	(defined(__MMI_FM_RADIO__))
	#ifndef __MMI_FM_PLUTO_SLIM__
	#define __MMI_FM_PLUTO_SLIM__
	#endif
#endif


#if (defined(__PXS_APP_ENABLE__) && defined(__MMI_FACTORY_MODE__))
	#ifndef __MMI_FM_PXS_SENSOR__
	#define __MMI_FM_PXS_SENSOR__
	#endif
#endif


#if defined(CFG_MMI_FM_RADIO_ANIMATION) && ((CFG_MMI_FM_RADIO_ANIMATION == __ON__)||(CFG_MMI_FM_RADIO_ANIMATION == __AUTO__)) && \
	((defined(FM_RADIO_ENABLE) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)||defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) ) && !defined(__RF_DESENSE_STOP_FM_RADIO_ANIMATION__)) && !defined(__MMI_SLIM_IMG_RES__))
	#ifndef __MMI_FM_RADIO_ANIMATION__
	#define __MMI_FM_RADIO_ANIMATION__
	#endif
#endif


#if defined(CFG_MMI_FM_RADIO_BIND_EARPHONE) && ((CFG_MMI_FM_RADIO_BIND_EARPHONE == __ON__)||(CFG_MMI_FM_RADIO_BIND_EARPHONE == __AUTO__)) && \
	(defined(FM_RADIO_ENABLE) && !defined(INTERNAL_ANTENNAL_SUPPORT))
	#ifndef __MMI_FM_RADIO_BIND_EARPHONE__
	#define __MMI_FM_RADIO_BIND_EARPHONE__
	#endif
#endif


#if defined(CFG_MMI_FM_RADIO_FIRST_CHANNEL) && ((CFG_MMI_FM_RADIO_FIRST_CHANNEL == __ON__)||(CFG_MMI_FM_RADIO_FIRST_CHANNEL == __AUTO__)) && \
	(defined(FM_RADIO_ENABLE))
	#ifndef __MMI_FM_RADIO_FIRST_CHANNEL__
	#define __MMI_FM_RADIO_FIRST_CHANNEL__
	#endif
#endif


#if defined(CFG_MMI_FM_RADIO_LOUD_SPEAK) && ((CFG_MMI_FM_RADIO_LOUD_SPEAK == __ON__)||(CFG_MMI_FM_RADIO_LOUD_SPEAK == __AUTO__)) && \
	(defined(FM_RADIO_ENABLE))
	#ifndef __MMI_FM_RADIO_LOUD_SPEAK__
	#define __MMI_FM_RADIO_LOUD_SPEAK__
	#endif
#endif


#if (defined(FM_RADIO_ENABLE) && (defined(MT6189A1) || defined(MT6188A1)))
	#ifndef __MMI_FM_RADIO_MONO__
	#define __MMI_FM_RADIO_MONO__
	#endif
#endif


#if defined(CFG_MMI_FM_RADIO_PRESET_TOP_N) && ((CFG_MMI_FM_RADIO_PRESET_TOP_N == __ON__)||(CFG_MMI_FM_RADIO_PRESET_TOP_N == __AUTO__)) && \
	(defined(FM_RADIO_ENABLE))
	#ifndef __MMI_FM_RADIO_PRESET_TOP_N__
	#define __MMI_FM_RADIO_PRESET_TOP_N__
	#endif
#endif


#if (defined(FM_RADIO_ENABLE) && defined(__FM_RADIO_RDS_SUPPORT__) && !defined(__MMI_MAINLCD_128X128__))
	#ifndef __MMI_FM_RADIO_RDS__
	#define __MMI_FM_RADIO_RDS__
	#endif
#endif


#if (defined(FM_RADIO_ENABLE) && defined(FM_RADIO_RECORD) && defined(AUD_REC_ENABLE))
	#ifndef __MMI_FM_RADIO_RECORD__
	#define __MMI_FM_RADIO_RECORD__
	#endif
#endif


#if defined(CFG_MMI_FM_RADIO_SLIM) && ((CFG_MMI_FM_RADIO_SLIM == __ON__)||(CFG_MMI_FM_RADIO_SLIM == __AUTO__))
	#ifndef __MMI_FM_RADIO_SLIM__
	#define __MMI_FM_RADIO_SLIM__
	#endif
#endif


#if (!defined(__MMI_SLIM_ENGINEER_MODE__) && defined(__MMI_FACTORY_MODE__))
	#ifndef __MMI_FM_RES_BIN__
	#define __MMI_FM_RES_BIN__
	#endif
#endif


#if defined(CFG_MMI_FM_SKIN_SYN_TO_THEME) && ((CFG_MMI_FM_SKIN_SYN_TO_THEME == __ON__)||(CFG_MMI_FM_SKIN_SYN_TO_THEME == __AUTO__)) && \
	(defined(FM_RADIO_ENABLE) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__)))
	#ifndef __MMI_FM_SKIN_SYN_TO_THEME__
	#define __MMI_FM_SKIN_SYN_TO_THEME__
	#endif
#endif


#if defined(CFG_MMI_FM_SLIM_SKIN) && ((CFG_MMI_FM_SLIM_SKIN == __ON__)||(CFG_MMI_FM_SLIM_SKIN == __AUTO__)) && \
	(defined(FM_RADIO_ENABLE)) || (defined(__MMI_FM_SKIN_SYN_TO_THEME__) || defined(__MMI_SLIM_IMG_RES__))
	#ifndef __MMI_FM_SLIM_SKIN__
	#define __MMI_FM_SLIM_SKIN__
	#endif
#endif


#if (defined(__MMI_CAMERA__) && defined(__MMI_FACTORY_MODE__) && (defined(__MTK_INTERNAL__) || defined(__MMI_TC01_MTKUI__)) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_FM_TC01_CAMERA_TEST__
	#define __MMI_FM_TC01_CAMERA_TEST__
	#endif
#endif


#if (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_FACTORY_MODE__))
	#ifndef __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__
	#define __MMI_FM_TOUCH_PANEL_ACCURACY_TEST__
	#endif
#endif


#if (defined(FM_RADIO_ENABLE) && defined(__MMI_A2DP_SUPPORT__) && defined(__FMRADIO_I2S_SUPPORT__))
	#ifndef __MMI_FM_VIA_A2DP__
	#define __MMI_FM_VIA_A2DP__
	#endif
#endif


#if defined(CFG_MMI_FMGR_FOLDER_COPY_SUPPORT) && ((CFG_MMI_FMGR_FOLDER_COPY_SUPPORT == __ON__)||(CFG_MMI_FMGR_FOLDER_COPY_SUPPORT == __AUTO__)) && \
	(defined(__MMI_FILE_MANAGER__)) || (defined(__OP01__))
	#ifndef __MMI_FMGR_FOLDER_COPY_SUPPORT__
	#define __MMI_FMGR_FOLDER_COPY_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_FMGR_HIDE_FORMAT_DRIVE) && ((CFG_MMI_FMGR_HIDE_FORMAT_DRIVE == __ON__)||(CFG_MMI_FMGR_HIDE_FORMAT_DRIVE == __AUTO__)) && \
	(defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__
	#define __MMI_FMGR_HIDE_FORMAT_DRIVE__
	#endif
#endif


#if (!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_SLIM_FILE_MANAGER__))
	#ifndef __MMI_FMGR_MULTI_SELECT_SUPPORT__
	#define __MMI_FMGR_MULTI_SELECT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_FMGR_SUPPORT_DEFAULT_STORAGE) && ((CFG_MMI_FMGR_SUPPORT_DEFAULT_STORAGE == __ON__)||(CFG_MMI_FMGR_SUPPORT_DEFAULT_STORAGE == __AUTO__)) && \
	(defined(__FS_CARD_SUPPORT__)  && defined(__MMI_FILE_MANAGER__) && !defined(__COSMOS_MMI__)&& !defined(__MMI_SLIM_FILE_MANAGER__))
	#ifndef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
	#define __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
	#endif
#endif


#if (defined (__MMI_FILE_MANAGER__))
	#ifndef __MMI_FMGR_SUPPORT_SOFT_UNMOUNT__
	#define __MMI_FMGR_SUPPORT_SOFT_UNMOUNT__
	#endif
#endif


#if defined(CFG_MMI_FMGR_SUPPORT_THUMB_DECODE) && ((CFG_MMI_FMGR_SUPPORT_THUMB_DECODE == __ON__)||(CFG_MMI_FMGR_SUPPORT_THUMB_DECODE == __AUTO__)) && \
	((defined(JPG_DECODE) && !defined(__MMI_SLIM_FILE_MANAGER__) && !defined(MT6223P) && !defined(MT6223) && !defined(MT6223P_S00)) || defined(__OP01__) || (defined(MT6250) && (defined(__FLAVOR_SERIAL_LCM_HX8347I__) || defined(__FLAVOR_16BITLCM_WIFI__))))
	#ifndef __MMI_FMGR_SUPPORT_THUMB_DECODE__
	#define __MMI_FMGR_SUPPORT_THUMB_DECODE__
	#endif
#endif


#if defined(CFG_MMI_FONT_COMPRESSION) && ((CFG_MMI_FONT_COMPRESSION == __ON__)||(CFG_MMI_FONT_COMPRESSION == __AUTO__)) && \
	((defined(__FONT_RESOURCE_OFFICIAL__)) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)) && !defined(__MMI_BDF_SW_COMPRESSION__))
	#ifndef __MMI_FONT_COMPRESSION__
	#define __MMI_FONT_COMPRESSION__
	#endif
#endif


#if defined(CFG_MMI_FONT_GROUP_COMPRESSION) && ((CFG_MMI_FONT_GROUP_COMPRESSION == __ON__)||(CFG_MMI_FONT_GROUP_COMPRESSION == __AUTO__)) && \
	((defined(__MMI_BDF_SW_COMPRESSION__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)))
	#ifndef __MMI_FONT_GROUP_COMPRESSION__
	#define __MMI_FONT_GROUP_COMPRESSION__
	#endif
#endif


#if (defined(__GADGET_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_GADGET_SUPPORT__
	#define __MMI_GADGET_SUPPORT__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) || defined(__MMI_GADGET_SUPPORT__))
	#ifndef __MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__
	#define __MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__
	#endif
#endif


#if (defined(__NFB_THIRD_ROM_SUPPORT__) && defined(FONT_ENGINE_ETRUMP))
	#ifndef __MMI_FONT_THIRD_ROM_SUPPORT__
	#define __MMI_FONT_THIRD_ROM_SUPPORT__
	#endif
#endif


#if (defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_FRM_INPUT_EVT__
	#define __MMI_FRM_INPUT_EVT__
	#endif
#endif


#if defined(CFG_MMI_FRM_REMOVE_HISTORY) && ((CFG_MMI_FRM_REMOVE_HISTORY == __ON__)||(CFG_MMI_FRM_REMOVE_HISTORY == __AUTO__)) && \
	(defined(__32_32_SEG__) || defined(__24_32_SEG__) || defined(__16_32_SEG__) || defined(__8_32_SEG__))
	#ifndef __MMI_FRM_REMOVE_HISTORY__
	#define __MMI_FRM_REMOVE_HISTORY__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_FTC_PROFILE__))
	#ifndef __MMI_FTC_SUPPORT__
	#define __MMI_FTC_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_FTC_MULTIPULL_SUPPORT) && ((CFG_MMI_FTC_MULTIPULL_SUPPORT == __ON__)||(CFG_MMI_FTC_MULTIPULL_SUPPORT == __AUTO__)) && \
	(defined(__MMI_FTC_SUPPORT__) && defined(__BTMTK__))
	#ifndef __MMI_FTC_MULTIPULL_SUPPORT__
	#define __MMI_FTC_MULTIPULL_SUPPORT__
	#endif
#endif


#if (defined(__TOUCH_PANEL_TRUE_MULTITOUCH__) && defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_FTO_PIANO__
	#define __MMI_FTO_PIANO__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_FTS_PROFILE__))
	#ifndef __MMI_FTS_SUPPORT__
	#define __MMI_FTS_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER) && ((CFG_MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER == __ON__)||(CFG_MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER == __AUTO__)) && \
	(defined(__MMI_FTO_GALLERY__) || defined(__MMI_GALLERY_SLIM__))
	#ifndef __MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__
	#define __MMI_GALLERY_VIDEO_IN_IMAGE_VIEWER__
	#endif
#endif


#if defined(CFG_MMI_GAME_FRUITNINJA) && ((CFG_MMI_GAME_FRUITNINJA == __ON__)||(CFG_MMI_GAME_FRUITNINJA == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__))
	#ifndef __MMI_GAME_FRUITNINJA__
	#define __MMI_GAME_FRUITNINJA__
	#endif
#endif


#if defined(CFG_MMI_GAME_DIAMOND) && ((CFG_MMI_GAME_DIAMOND == __ON__)||(CFG_MMI_GAME_DIAMOND == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__))
	#ifndef __MMI_GAME_DIAMOND__
	#define __MMI_GAME_DIAMOND__
	#endif
#endif


#if defined(CFG_MMI_GAME_NINJACLIMB) && ((CFG_MMI_GAME_NINJACLIMB == __ON__)||(CFG_MMI_GAME_NINJACLIMB == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__))
	#ifndef __MMI_GAME_NINJACLIMB__
	#define __MMI_GAME_NINJACLIMB__
	#endif
#endif


#if defined(CFG_MMI_GAME_FROGCANDY) && ((CFG_MMI_GAME_FROGCANDY == __ON__)||(CFG_MMI_GAME_FROGCANDY == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__))
	#ifndef __MMI_GAME_FROGCANDY__
	#define __MMI_GAME_FROGCANDY__
	#endif
#endif


#if defined(CFG_MMI_GAME_TRUEMAN) && ((CFG_MMI_GAME_TRUEMAN == __ON__)||(CFG_MMI_GAME_TRUEMAN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__))
	#ifndef __MMI_GAME_TRUEMAN__
	#define __MMI_GAME_TRUEMAN__
	#endif
#endif


#if defined(CFG_MMI_GAME_TOPGUN) && ((CFG_MMI_GAME_TOPGUN == __ON__)||(CFG_MMI_GAME_TOPGUN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__))
	#ifndef __MMI_GAME_TOPGUN__
	#define __MMI_GAME_TOPGUN__
	#endif
#endif


#if ((defined(__MMI_GAME_FRUITNINJA__) || defined(__MMI_GAME_DIAMOND__) || defined(__MMI_GAME_NINJACLIMB__) || defined(__MMI_GAME_FROGCANDY__) || defined(__MMI_GAME_TRUEMAN__) || defined(__MMI_GAME_TOPGUN__)) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_GAME__
	#define __MMI_GAME__
	#endif
#endif


#if (defined(__MMI_GAME__))
	#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	#define __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_LANG_AFRIKAANS) && ((CFG_MMI_LANG_AFRIKAANS == __ON__)||(CFG_MMI_LANG_AFRIKAANS == __AUTO__))
	#ifndef __MMI_LANG_AFRIKAANS__
	#define __MMI_LANG_AFRIKAANS__
	#endif
#endif


#if defined(CFG_MMI_IME_AFRIKAANS) && ((CFG_MMI_IME_AFRIKAANS == __ON__)||(CFG_MMI_IME_AFRIKAANS == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_AFRIKAANS__))
	#ifndef __MMI_IME_AFRIKAANS__
	#define __MMI_IME_AFRIKAANS__
	#endif
#endif


#if (defined(__MMI_IME_AFRIKAANS__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_AFRIKAANS__
	#define __MMI_GB_AFRIKAANS__
	#endif
#endif


#if defined(CFG_MMI_LANG_ALBANIAN) && ((CFG_MMI_LANG_ALBANIAN == __ON__)||(CFG_MMI_LANG_ALBANIAN == __AUTO__))
	#ifndef __MMI_LANG_ALBANIAN__
	#define __MMI_LANG_ALBANIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_ALBANIAN) && ((CFG_MMI_IME_ALBANIAN == __ON__)||(CFG_MMI_IME_ALBANIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_ALBANIAN__))
	#ifndef __MMI_IME_ALBANIAN__
	#define __MMI_IME_ALBANIAN__
	#endif
#endif


#if (defined(__MMI_IME_ALBANIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_ALBANIAN__
	#define __MMI_GB_ALBANIAN__
	#endif
#endif


#if (defined(__MMI_IME_ARABIC__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_ARABIC__
	#define __MMI_GB_ARABIC__
	#endif
#endif


#if defined(CFG_MMI_LANG_BASQUE) && ((CFG_MMI_LANG_BASQUE == __ON__)||(CFG_MMI_LANG_BASQUE == __AUTO__))
	#ifndef __MMI_LANG_BASQUE__
	#define __MMI_LANG_BASQUE__
	#endif
#endif


#if defined(CFG_MMI_IME_BASQUE) && ((CFG_MMI_IME_BASQUE == __ON__)||(CFG_MMI_IME_BASQUE == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_BASQUE__))
	#ifndef __MMI_IME_BASQUE__
	#define __MMI_IME_BASQUE__
	#endif
#endif


#if (defined(__MMI_IME_BASQUE__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_BASQUE__
	#define __MMI_GB_BASQUE__
	#endif
#endif


#if (defined(__MMI_IME_BENGALI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_BENGALI__
	#define __MMI_GB_BENGALI__
	#endif
#endif


#if (defined(__MMI_IME_BULGARIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_BULGARIAN__
	#define __MMI_GB_BULGARIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_CROATIAN) && ((CFG_MMI_LANG_CROATIAN == __ON__)||(CFG_MMI_LANG_CROATIAN == __AUTO__))
	#ifndef __MMI_LANG_CROATIAN__
	#define __MMI_LANG_CROATIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_CROATIAN) && ((CFG_MMI_IME_CROATIAN == __ON__)||(CFG_MMI_IME_CROATIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_CROATIAN__))
	#ifndef __MMI_IME_CROATIAN__
	#define __MMI_IME_CROATIAN__
	#endif
#endif


#if (defined(__MMI_IME_CROATIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_CROATIAN__
	#define __MMI_GB_CROATIAN__
	#endif
#endif


#if (defined(__MMI_IME_CZECH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_CZECH__
	#define __MMI_GB_CZECH__
	#endif
#endif


#if (defined(__MMI_IME_DANISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_DANISH__
	#define __MMI_GB_DANISH__
	#endif
#endif


#if (defined(__MMI_IME_DUTCH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_DUTCH__
	#define __MMI_GB_DUTCH__
	#endif
#endif


#if (defined(__MMI_IME_ENGLISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_ENGLISH__
	#define __MMI_GB_ENGLISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_ESTONIAN) && ((CFG_MMI_LANG_ESTONIAN == __ON__)||(CFG_MMI_LANG_ESTONIAN == __AUTO__))
	#ifndef __MMI_LANG_ESTONIAN__
	#define __MMI_LANG_ESTONIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_ESTONIAN) && ((CFG_MMI_IME_ESTONIAN == __ON__)||(CFG_MMI_IME_ESTONIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_ESTONIAN__))
	#ifndef __MMI_IME_ESTONIAN__
	#define __MMI_IME_ESTONIAN__
	#endif
#endif


#if (defined(__MMI_IME_ESTONIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_ESTONIAN__
	#define __MMI_GB_ESTONIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_FILIPINO) && ((CFG_MMI_LANG_FILIPINO == __ON__)||(CFG_MMI_LANG_FILIPINO == __AUTO__))
	#ifndef __MMI_LANG_FILIPINO__
	#define __MMI_LANG_FILIPINO__
	#endif
#endif


#if defined(CFG_MMI_IME_FILIPINO) && ((CFG_MMI_IME_FILIPINO == __ON__)||(CFG_MMI_IME_FILIPINO == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_FILIPINO__))
	#ifndef __MMI_IME_FILIPINO__
	#define __MMI_IME_FILIPINO__
	#endif
#endif


#if (defined(__MMI_IME_FILIPINO__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_FILIPINO__
	#define __MMI_GB_FILIPINO__
	#endif
#endif


#if (defined(__MMI_IME_FINNISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_FINNISH__
	#define __MMI_GB_FINNISH__
	#endif
#endif


#if (defined(__MMI_IME_FRENCH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_FRENCH__
	#define __MMI_GB_FRENCH__
	#endif
#endif


#if defined(CFG_MMI_LANG_GEORGIAN) && ((CFG_MMI_LANG_GEORGIAN == __ON__)||(CFG_MMI_LANG_GEORGIAN == __AUTO__))
	#ifndef __MMI_LANG_GEORGIAN__
	#define __MMI_LANG_GEORGIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_GEORGIAN) && ((CFG_MMI_IME_GEORGIAN == __ON__)||(CFG_MMI_IME_GEORGIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_GEORGIAN__))
	#ifndef __MMI_IME_GEORGIAN__
	#define __MMI_IME_GEORGIAN__
	#endif
#endif


#if (defined(__MMI_IME_GEORGIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_GEORGIAN__
	#define __MMI_GB_GEORGIAN__
	#endif
#endif


#if (defined(__MMI_IME_GERMAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_GERMAN__
	#define __MMI_GB_GERMAN__
	#endif
#endif


#if (defined(__MMI_IME_GREEK__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_GREEK__
	#define __MMI_GB_GREEK__
	#endif
#endif


#if defined(CFG_MMI_LANG_GUJARATI) && ((CFG_MMI_LANG_GUJARATI == __ON__)||(CFG_MMI_LANG_GUJARATI == __AUTO__))
	#ifndef __MMI_LANG_GUJARATI__
	#define __MMI_LANG_GUJARATI__
	#endif
#endif


#if defined(CFG_MMI_IME_GUJARATI) && ((CFG_MMI_IME_GUJARATI == __ON__)||(CFG_MMI_IME_GUJARATI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_GUJARATI__))
	#ifndef __MMI_IME_GUJARATI__
	#define __MMI_IME_GUJARATI__
	#endif
#endif


#if (defined(__MMI_IME_GUJARATI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_GUJARATI__
	#define __MMI_GB_GUJARATI__
	#endif
#endif


#if (defined(__MMI_IME_HEBREW__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_HEBREW__
	#define __MMI_GB_HEBREW__
	#endif
#endif


#if (defined(__MMI_IME_HINDI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_HINDI__
	#define __MMI_GB_HINDI__
	#endif
#endif


#if (defined(__MMI_IME_HINGLISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_HINGLISH__
	#define __MMI_GB_HINGLISH__
	#endif
#endif


#if (defined(__MMI_IME_HUNGARIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_HUNGARIAN__
	#define __MMI_GB_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_INDONESIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_INDONESIAN__
	#define __MMI_GB_INDONESIAN__
	#endif
#endif


#if (defined(__MMI_IME_ITALIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_ITALIAN__
	#define __MMI_GB_ITALIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_KAZAKH) && ((CFG_MMI_LANG_KAZAKH == __ON__)||(CFG_MMI_LANG_KAZAKH == __AUTO__))
	#ifndef __MMI_LANG_KAZAKH__
	#define __MMI_LANG_KAZAKH__
	#endif
#endif


#if defined(CFG_MMI_IME_KAZAKH) && ((CFG_MMI_IME_KAZAKH == __ON__)||(CFG_MMI_IME_KAZAKH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_KAZAKH__))
	#ifndef __MMI_IME_KAZAKH__
	#define __MMI_IME_KAZAKH__
	#endif
#endif


#if (defined(__MMI_IME_KAZAKH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_KAZAKH__
	#define __MMI_GB_KAZAKH__
	#endif
#endif


#if defined(CFG_MMI_LANG_KHMER) && ((CFG_MMI_LANG_KHMER == __ON__)||(CFG_MMI_LANG_KHMER == __AUTO__))
	#ifndef __MMI_LANG_KHMER__
	#define __MMI_LANG_KHMER__
	#endif
#endif


#if defined(CFG_MMI_IME_KHMER) && ((CFG_MMI_IME_KHMER == __ON__)||(CFG_MMI_IME_KHMER == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_KHMER__))
	#ifndef __MMI_IME_KHMER__
	#define __MMI_IME_KHMER__
	#endif
#endif


#if (defined(__MMI_IME_KHMER__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_KHMER__
	#define __MMI_GB_KHMER__
	#endif
#endif


#if defined(CFG_MMI_LANG_LAO) && ((CFG_MMI_LANG_LAO == __ON__)||(CFG_MMI_LANG_LAO == __AUTO__))
	#ifndef __MMI_LANG_LAO__
	#define __MMI_LANG_LAO__
	#endif
#endif


#if defined(CFG_MMI_IME_LAO) && ((CFG_MMI_IME_LAO == __ON__)||(CFG_MMI_IME_LAO == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_LAO__))
	#ifndef __MMI_IME_LAO__
	#define __MMI_IME_LAO__
	#endif
#endif


#if (defined(__MMI_IME_LAO__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_LAO__
	#define __MMI_GB_LAO__
	#endif
#endif


#if defined(CFG_MMI_LANG_LATVIAN) && ((CFG_MMI_LANG_LATVIAN == __ON__)||(CFG_MMI_LANG_LATVIAN == __AUTO__))
	#ifndef __MMI_LANG_LATVIAN__
	#define __MMI_LANG_LATVIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_LATVIAN) && ((CFG_MMI_IME_LATVIAN == __ON__)||(CFG_MMI_IME_LATVIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_LATVIAN__))
	#ifndef __MMI_IME_LATVIAN__
	#define __MMI_IME_LATVIAN__
	#endif
#endif


#if (defined(__MMI_IME_LATVIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_LATVIAN__
	#define __MMI_GB_LATVIAN__
	#endif
#endif


#if (defined(__MMI_IME_LITHUANIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_LITHUANIAN__
	#define __MMI_GB_LITHUANIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_MACEDONIAN) && ((CFG_MMI_LANG_MACEDONIAN == __ON__)||(CFG_MMI_LANG_MACEDONIAN == __AUTO__))
	#ifndef __MMI_LANG_MACEDONIAN__
	#define __MMI_LANG_MACEDONIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_MACEDONIAN) && ((CFG_MMI_IME_MACEDONIAN == __ON__)||(CFG_MMI_IME_MACEDONIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_MACEDONIAN__))
	#ifndef __MMI_IME_MACEDONIAN__
	#define __MMI_IME_MACEDONIAN__
	#endif
#endif


#if (defined(__MMI_IME_MACEDONIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_MACEDONIAN__
	#define __MMI_GB_MACEDONIAN__
	#endif
#endif


#if (defined(__MMI_IME_MALAY__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_MALAY__
	#define __MMI_GB_MALAY__
	#endif
#endif


#if defined(CFG_MMI_LANG_MALAYALAM) && ((CFG_MMI_LANG_MALAYALAM == __ON__)||(CFG_MMI_LANG_MALAYALAM == __AUTO__))
	#ifndef __MMI_LANG_MALAYALAM__
	#define __MMI_LANG_MALAYALAM__
	#endif
#endif


#if defined(CFG_MMI_IME_MALAYALAM) && ((CFG_MMI_IME_MALAYALAM == __ON__)||(CFG_MMI_IME_MALAYALAM == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_MALAYALAM__))
	#ifndef __MMI_IME_MALAYALAM__
	#define __MMI_IME_MALAYALAM__
	#endif
#endif


#if (defined(__MMI_IME_MALAYALAM__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_MALAYALAM__
	#define __MMI_GB_MALAYALAM__
	#endif
#endif


#if defined(CFG_MMI_LANG_MARATHI) && ((CFG_MMI_LANG_MARATHI == __ON__)||(CFG_MMI_LANG_MARATHI == __AUTO__))
	#ifndef __MMI_LANG_MARATHI__
	#define __MMI_LANG_MARATHI__
	#endif
#endif


#if defined(CFG_MMI_IME_MARATHI) && ((CFG_MMI_IME_MARATHI == __ON__)||(CFG_MMI_IME_MARATHI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_MARATHI__))
	#ifndef __MMI_IME_MARATHI__
	#define __MMI_IME_MARATHI__
	#endif
#endif


#if (defined(__MMI_IME_MARATHI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_MARATHI__
	#define __MMI_GB_MARATHI__
	#endif
#endif


#if (defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_MULTITAP_PHONETIC_INPUT__
	#define __MMI_GB_MULTITAP_PHONETIC_INPUT__
	#endif
#endif


#if defined(CFG_MMI_LANG_NORWEGIAN) && ((CFG_MMI_LANG_NORWEGIAN == __ON__)||(CFG_MMI_LANG_NORWEGIAN == __AUTO__))
	#ifndef __MMI_LANG_NORWEGIAN__
	#define __MMI_LANG_NORWEGIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_NORWEGIAN) && ((CFG_MMI_IME_NORWEGIAN == __ON__)||(CFG_MMI_IME_NORWEGIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_NORWEGIAN__))
	#ifndef __MMI_IME_NORWEGIAN__
	#define __MMI_IME_NORWEGIAN__
	#endif
#endif


#if (defined(__MMI_IME_NORWEGIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_NORWEGIAN__
	#define __MMI_GB_NORWEGIAN__
	#endif
#endif


#if (defined(__MMI_IME_PERSIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_PERSIAN__
	#define __MMI_GB_PERSIAN__
	#endif
#endif


#if (defined(__MMI_IME_POLISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_POLISH__
	#define __MMI_GB_POLISH__
	#endif
#endif


#if (defined(__MMI_IME_PORTUGUESE__) && defined(__MMI_LANG_PORTUGUESE__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_PORTUGUESE__
	#define __MMI_GB_PORTUGUESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_PUNJABI) && ((CFG_MMI_LANG_PUNJABI == __ON__)||(CFG_MMI_LANG_PUNJABI == __AUTO__))
	#ifndef __MMI_LANG_PUNJABI__
	#define __MMI_LANG_PUNJABI__
	#endif
#endif


#if defined(CFG_MMI_IME_PUNJABI) && ((CFG_MMI_IME_PUNJABI == __ON__)||(CFG_MMI_IME_PUNJABI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_PUNJABI__))
	#ifndef __MMI_IME_PUNJABI__
	#define __MMI_IME_PUNJABI__
	#endif
#endif


#if (defined(__MMI_IME_PUNJABI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_PUNJABI__
	#define __MMI_GB_PUNJABI__
	#endif
#endif


#if (defined(__MMI_IME_ROMANIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_ROMANIAN__
	#define __MMI_GB_ROMANIAN__
	#endif
#endif


#if (defined(__MMI_IME_RUSSIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_RUSSIAN__
	#define __MMI_GB_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_IME_PORTUGUESE__)&& (defined(__MMI_LANG_SA_PORTUGUESE__) && defined(__MMI_GUOBI__)))
	#ifndef __MMI_GB_SA_PORTUGUESE__
	#define __MMI_GB_SA_PORTUGUESE__
	#endif
#endif


#if (defined(__MMI_IME_SPANISH__)&& (defined(__MMI_LANG_SA_SPANISH__) && defined(__MMI_GUOBI__)))
	#ifndef __MMI_GB_SA_SPANISH__
	#define __MMI_GB_SA_SPANISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_SERBIAN) && ((CFG_MMI_LANG_SERBIAN == __ON__)||(CFG_MMI_LANG_SERBIAN == __AUTO__))
	#ifndef __MMI_LANG_SERBIAN__
	#define __MMI_LANG_SERBIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_SERBIAN) && ((CFG_MMI_IME_SERBIAN == __ON__)||(CFG_MMI_IME_SERBIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_SERBIAN__))
	#ifndef __MMI_IME_SERBIAN__
	#define __MMI_IME_SERBIAN__
	#endif
#endif


#if (defined(__MMI_IME_SERBIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_SERBIAN__
	#define __MMI_GB_SERBIAN__
	#endif
#endif


#if (defined(__MMI_IME_SM_CHINESE__)  && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_SM_CHINESE__
	#define __MMI_GB_SM_CHINESE__
	#endif
#endif


#if (defined(__MMI_GUOBI__) && defined(__MMI_SMART_PHONETIC_INPUT_METHODS__))
	#ifndef __MMI_GB_SMART_PHONETIC_INPUT__
	#define __MMI_GB_SMART_PHONETIC_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_SPANISH__) && defined(__MMI_LANG_SPANISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_SPANISH__
	#define __MMI_GB_SPANISH__
	#endif
#endif


#if (defined (__MMI_IME_STROKE_INPUT__) && (defined(__MMI_GUOBI__) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)|| defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)) && defined(__MMI_LANG_SM_CHINESE__)|| defined(__MMI_LANG_TR_CHINESE__)))
	#ifndef __MMI_GB_STROKE_INPUT__
	#define __MMI_GB_STROKE_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_SWAHILI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_SWAHILI__
	#define __MMI_GB_SWAHILI__
	#endif
#endif


#if (defined(__MMI_IME_SWEDISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_SWEDISH__
	#define __MMI_GB_SWEDISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_TAMIL) && ((CFG_MMI_LANG_TAMIL == __ON__)||(CFG_MMI_LANG_TAMIL == __AUTO__))
	#ifndef __MMI_LANG_TAMIL__
	#define __MMI_LANG_TAMIL__
	#endif
#endif


#if defined(CFG_MMI_IME_TAMIL) && ((CFG_MMI_IME_TAMIL == __ON__)||(CFG_MMI_IME_TAMIL == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_TAMIL__))
	#ifndef __MMI_IME_TAMIL__
	#define __MMI_IME_TAMIL__
	#endif
#endif


#if (defined(__MMI_IME_TAMIL__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_TAMIL__
	#define __MMI_GB_TAMIL__
	#endif
#endif


#if defined(CFG_MMI_LANG_TELUGU) && ((CFG_MMI_LANG_TELUGU == __ON__)||(CFG_MMI_LANG_TELUGU == __AUTO__))
	#ifndef __MMI_LANG_TELUGU__
	#define __MMI_LANG_TELUGU__
	#endif
#endif


#if defined(CFG_MMI_IME_TELUGU) && ((CFG_MMI_IME_TELUGU == __ON__)||(CFG_MMI_IME_TELUGU == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_TELUGU__))
	#ifndef __MMI_IME_TELUGU__
	#define __MMI_IME_TELUGU__
	#endif
#endif


#if (defined(__MMI_IME_TELUGU__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_TELUGU__
	#define __MMI_GB_TELUGU__
	#endif
#endif


#if (defined(__MMI_IME_THAI__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_THAI__
	#define __MMI_GB_THAI__
	#endif
#endif


#if (defined(__MMI_IME_TR_CHINESE__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_TR_CHINESE__
	#define __MMI_GB_TR_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_TURKISH__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_TURKISH__
	#define __MMI_GB_TURKISH__
	#endif
#endif


#if (defined(__MMI_IME_UKRAINIAN__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_UKRAINIAN__
	#define __MMI_GB_UKRAINIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_URDU) && ((CFG_MMI_IME_URDU == __ON__)||(CFG_MMI_IME_URDU == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_URDU__))
	#ifndef __MMI_IME_URDU__
	#define __MMI_IME_URDU__
	#endif
#endif


#if (defined(__MMI_IME_URDU__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_URDU__
	#define __MMI_GB_URDU__
	#endif
#endif


#if (defined(__MMI_IME_VIETNAMESE__) && defined(__MMI_GUOBI__))
	#ifndef __MMI_GB_VIETNAMESE__
	#define __MMI_GB_VIETNAMESE__
	#endif
#endif


#ifndef __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__
#define __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__	32
#endif


#if (defined(__MMI_TOUCH_SCREEN__)&& !defined(__32_32_SEG__) && !defined(__16_32_SEG__) && !defined(__24_32_SEG__) && !defined(__8_32_SEG__))
	#ifndef __MMI_GESTURES_FRAMEWORK__
	#define __MMI_GESTURES_FRAMEWORK__
	#endif
#endif


#if defined(CFG_MMI_GPIO_DISABLE_SLEEP_MODE) && ((CFG_MMI_GPIO_DISABLE_SLEEP_MODE == __ON__)||(CFG_MMI_GPIO_DISABLE_SLEEP_MODE == __AUTO__))
	#ifndef __MMI_GPIO_DISABLE_SLEEP_MODE__
	#define __MMI_GPIO_DISABLE_SLEEP_MODE__
	#endif
#endif


#if defined(CFG_MMI_GUI_PICKER) && ((CFG_MMI_GUI_PICKER == __ON__)||(CFG_MMI_GUI_PICKER == __AUTO__)) && \
	(defined(__MMI_BTD_BOX_UI_STYLE__))
	#ifndef __MMI_GUI_PICKER__
	#define __MMI_GUI_PICKER__
	#endif
#endif


#if defined(CFG_MMI_GUOBI_BDF_FONT) && ((CFG_MMI_GUOBI_BDF_FONT == __ON__)||(CFG_MMI_GUOBI_BDF_FONT == __AUTO__))
	#if (defined(__MMI_VECTOR_FONT_SUPPORT__) || !(defined(__MMI_GB_WINGUO__) || defined(__MMI_GB_WINGUO_ULTRA__)))
	#error "Setting conflict, CFG_MMI_GUOBI_BDF_FONT require FONT_ENGINE = NONE"
	#endif
	#ifndef __MMI_GUOBI_BDF_FONT__
	#define __MMI_GUOBI_BDF_FONT__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_FRENCH) && ((CFG_MMI_IME_HANDWRITING_FRENCH == __ON__)||(CFG_MMI_IME_HANDWRITING_FRENCH == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_FRENCH__))
	#ifndef __MMI_IME_HANDWRITING_FRENCH__
	#define __MMI_IME_HANDWRITING_FRENCH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_FRENCH__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_FRENCH__
	#define __MMI_GUOBI_HW_FRENCH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_GERMAN) && ((CFG_MMI_IME_HANDWRITING_GERMAN == __ON__)||(CFG_MMI_IME_HANDWRITING_GERMAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_GERMAN__))
	#ifndef __MMI_IME_HANDWRITING_GERMAN__
	#define __MMI_IME_HANDWRITING_GERMAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_GERMAN__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_GERMAN__
	#define __MMI_GUOBI_HW_GERMAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_INDONESIAN) && ((CFG_MMI_IME_HANDWRITING_INDONESIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_INDONESIAN == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_INDONESIAN__))
	#ifndef __MMI_IME_HANDWRITING_INDONESIAN__
	#define __MMI_IME_HANDWRITING_INDONESIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_INDONESIAN__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_INDONESIAN__
	#define __MMI_GUOBI_HW_INDONESIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_ITALIAN) && ((CFG_MMI_IME_HANDWRITING_ITALIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_ITALIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_ITALIAN__))
	#ifndef __MMI_IME_HANDWRITING_ITALIAN__
	#define __MMI_IME_HANDWRITING_ITALIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ITALIAN__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_ITALIAN__
	#define __MMI_GUOBI_HW_ITALIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_MALAY) && ((CFG_MMI_IME_HANDWRITING_MALAY == __ON__)||(CFG_MMI_IME_HANDWRITING_MALAY == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_MALAY__))
	#ifndef __MMI_IME_HANDWRITING_MALAY__
	#define __MMI_IME_HANDWRITING_MALAY__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_MALAY__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_MALAY__
	#define __MMI_GUOBI_HW_MALAY__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_PORTUGESE) && ((CFG_MMI_IME_HANDWRITING_PORTUGESE == __ON__)||(CFG_MMI_IME_HANDWRITING_PORTUGESE == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_PORTUGUESE__))
	#ifndef __MMI_IME_HANDWRITING_PORTUGESE__
	#define __MMI_IME_HANDWRITING_PORTUGESE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_PORTUGESE__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_PORTUGESE__
	#define __MMI_GUOBI_HW_PORTUGESE__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_SM_CHINESE) && ((CFG_MMI_IME_HANDWRITING_SM_CHINESE == __ON__)||(CFG_MMI_IME_HANDWRITING_SM_CHINESE == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_SM_CHINESE__))
	#ifndef __MMI_IME_HANDWRITING_SM_CHINESE__
	#define __MMI_IME_HANDWRITING_SM_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SM_CHINESE__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_SM_CHINESE__
	#define __MMI_GUOBI_HW_SM_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_SPANISH) && ((CFG_MMI_IME_HANDWRITING_SPANISH == __ON__)||(CFG_MMI_IME_HANDWRITING_SPANISH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_SPANISH__))
	#ifndef __MMI_IME_HANDWRITING_SPANISH__
	#define __MMI_IME_HANDWRITING_SPANISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SPANISH__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_SPANISH__
	#define __MMI_GUOBI_HW_SPANISH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_TR_CHINESE) && ((CFG_MMI_IME_HANDWRITING_TR_CHINESE == __ON__)||(CFG_MMI_IME_HANDWRITING_TR_CHINESE == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_TR_CHINESE__))
	#ifndef __MMI_IME_HANDWRITING_TR_CHINESE__
	#define __MMI_IME_HANDWRITING_TR_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_TR_CHINESE__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_TR_CHINESE__
	#define __MMI_GUOBI_HW_TR_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_TURKISH) && ((CFG_MMI_IME_HANDWRITING_TURKISH == __ON__)||(CFG_MMI_IME_HANDWRITING_TURKISH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_TURKISH__))
	#ifndef __MMI_IME_HANDWRITING_TURKISH__
	#define __MMI_IME_HANDWRITING_TURKISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_TURKISH__) && defined(__MMI_GUOBI_HW__))
	#ifndef __MMI_GUOBI_HW_TURKISH__
	#define __MMI_GUOBI_HW_TURKISH__
	#endif
#endif


#if defined(CFG_MMI_GUOBI_MULTITAP) && ((CFG_MMI_GUOBI_MULTITAP == __ON__)||(CFG_MMI_GUOBI_MULTITAP == __AUTO__)) && \
	(defined(__MMI_GUOBI__) && ( defined(__MMI_NORMAL_KEYPAD__)  || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)))
	#ifndef __MMI_GUOBI_MULTITAP__
	#define __MMI_GUOBI_MULTITAP__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_PHRASE) && ((CFG_MMI_IME_HANDWRITING_PHRASE == __ON__)||(CFG_MMI_IME_HANDWRITING_PHRASE == __AUTO__)) && \
	(defined(__MMI_PENPOWER__))
	#ifndef __MMI_IME_HANDWRITING_PHRASE__
	#define __MMI_IME_HANDWRITING_PHRASE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_PHRASE__))
	#ifndef __MMI_HANDWRITING_PHRASE__
	#define __MMI_HANDWRITING_PHRASE__
	#endif
#endif


#if (defined( __MMI_TOUCH_SCREEN__))
	#ifndef __MMI_HANDWRITING_WORD_PREDICTION__
	#define __MMI_HANDWRITING_WORD_PREDICTION__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_ARABIC) && ((CFG_MMI_IME_HANDWRITING_ARABIC == __ON__)||(CFG_MMI_IME_HANDWRITING_ARABIC == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_ARABIC__))
	#ifndef __MMI_IME_HANDWRITING_ARABIC__
	#define __MMI_IME_HANDWRITING_ARABIC__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ARABIC__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_ARABIC__
	#define __MMI_HANWANG_ARABIC__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_BULGARIAN) && ((CFG_MMI_IME_HANDWRITING_BULGARIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_BULGARIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_BULGARIAN__))
	#ifndef __MMI_IME_HANDWRITING_BULGARIAN__
	#define __MMI_IME_HANDWRITING_BULGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_BULGARIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_BULGARIAN__
	#define __MMI_HANWANG_BULGARIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_CROATIAN) && ((CFG_MMI_IME_HANDWRITING_CROATIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_CROATIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_CROATIAN__))
	#ifndef __MMI_IME_HANDWRITING_CROATIAN__
	#define __MMI_IME_HANDWRITING_CROATIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_CROATIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_CROATIAN__
	#define __MMI_HANWANG_CROATIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_CZECH) && ((CFG_MMI_IME_HANDWRITING_CZECH == __ON__)||(CFG_MMI_IME_HANDWRITING_CZECH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_CZECH__))
	#ifndef __MMI_IME_HANDWRITING_CZECH__
	#define __MMI_IME_HANDWRITING_CZECH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_CZECH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_CZECH__
	#define __MMI_HANWANG_CZECH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_DANISH) && ((CFG_MMI_IME_HANDWRITING_DANISH == __ON__)||(CFG_MMI_IME_HANDWRITING_DANISH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_DANISH__))
	#ifndef __MMI_IME_HANDWRITING_DANISH__
	#define __MMI_IME_HANDWRITING_DANISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_DANISH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_DANISH__
	#define __MMI_HANWANG_DANISH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_DUTCH) && ((CFG_MMI_IME_HANDWRITING_DUTCH == __ON__)||(CFG_MMI_IME_HANDWRITING_DUTCH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_DUTCH__))
	#ifndef __MMI_IME_HANDWRITING_DUTCH__
	#define __MMI_IME_HANDWRITING_DUTCH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_DUTCH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_DUTCH__
	#define __MMI_HANWANG_DUTCH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_ESTONIAN) && ((CFG_MMI_IME_HANDWRITING_ESTONIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_ESTONIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_ESTONIAN__))
	#ifndef __MMI_IME_HANDWRITING_ESTONIAN__
	#define __MMI_IME_HANDWRITING_ESTONIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ESTONIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_ESTONIAN__
	#define __MMI_HANWANG_ESTONIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_FINNISH) && ((CFG_MMI_IME_HANDWRITING_FINNISH == __ON__)||(CFG_MMI_IME_HANDWRITING_FINNISH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_FINNISH__))
	#ifndef __MMI_IME_HANDWRITING_FINNISH__
	#define __MMI_IME_HANDWRITING_FINNISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_FINNISH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_FINNISH__
	#define __MMI_HANWANG_FINNISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_FRENCH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_FRENCH__
	#define __MMI_HANWANG_FRENCH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_GERMAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_GERMAN__
	#define __MMI_HANWANG_GERMAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_GREEK) && ((CFG_MMI_IME_HANDWRITING_GREEK == __ON__)||(CFG_MMI_IME_HANDWRITING_GREEK == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_GREEK__))
	#ifndef __MMI_IME_HANDWRITING_GREEK__
	#define __MMI_IME_HANDWRITING_GREEK__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_GREEK__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_GREEK__
	#define __MMI_HANWANG_GREEK__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_HUNGARIAN) && ((CFG_MMI_IME_HANDWRITING_HUNGARIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_HUNGARIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_HUNGARIAN__))
	#ifndef __MMI_IME_HANDWRITING_HUNGARIAN__
	#define __MMI_IME_HANDWRITING_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_HUNGARIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_HUNGARIAN__
	#define __MMI_HANWANG_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ITALIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_ITALIAN__
	#define __MMI_HANWANG_ITALIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_LATVIAN) && ((CFG_MMI_IME_HANDWRITING_LATVIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_LATVIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_LATVIAN__))
	#ifndef __MMI_IME_HANDWRITING_LATVIAN__
	#define __MMI_IME_HANDWRITING_LATVIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_LATVIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_LATVIAN__
	#define __MMI_HANWANG_LATVIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_LITHUANIAN) && ((CFG_MMI_IME_HANDWRITING_LITHUANIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_LITHUANIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_LITHUANIAN__))
	#ifndef __MMI_IME_HANDWRITING_LITHUANIAN__
	#define __MMI_IME_HANDWRITING_LITHUANIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_LITHUANIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_LITHUANIAN__
	#define __MMI_HANWANG_LITHUANIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_MALDOVAN) && ((CFG_MMI_IME_HANDWRITING_MALDOVAN == __ON__)||(CFG_MMI_IME_HANDWRITING_MALDOVAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_MALDOVAN__))
	#ifndef __MMI_IME_HANDWRITING_MALDOVAN__
	#define __MMI_IME_HANDWRITING_MALDOVAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_MALDOVAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_MALDOVAN__
	#define __MMI_HANWANG_MALDOVAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_NORWEGIAN) && ((CFG_MMI_IME_HANDWRITING_NORWEGIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_NORWEGIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_NORWEGIAN__))
	#ifndef __MMI_IME_HANDWRITING_NORWEGIAN__
	#define __MMI_IME_HANDWRITING_NORWEGIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_NORWEGIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_NORWEGIAN__
	#define __MMI_HANWANG_NORWEGIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_POLISH) && ((CFG_MMI_IME_HANDWRITING_POLISH == __ON__)||(CFG_MMI_IME_HANDWRITING_POLISH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_POLISH__))
	#ifndef __MMI_IME_HANDWRITING_POLISH__
	#define __MMI_IME_HANDWRITING_POLISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_POLISH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_POLISH__
	#define __MMI_HANWANG_POLISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_PORTUGESE__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_PORTUGESE__
	#define __MMI_HANWANG_PORTUGESE__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_ROMANIAN) && ((CFG_MMI_IME_HANDWRITING_ROMANIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_ROMANIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_ROMANIAN__))
	#ifndef __MMI_IME_HANDWRITING_ROMANIAN__
	#define __MMI_IME_HANDWRITING_ROMANIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ROMANIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_ROMANIAN__
	#define __MMI_HANWANG_ROMANIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_RUSSIAN) && ((CFG_MMI_IME_HANDWRITING_RUSSIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_RUSSIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_RUSSIAN__))
	#ifndef __MMI_IME_HANDWRITING_RUSSIAN__
	#define __MMI_IME_HANDWRITING_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_RUSSIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_RUSSIAN__
	#define __MMI_HANWANG_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SLOVAKIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_SLOVAKIAN__
	#define __MMI_HANWANG_SLOVAKIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SLOVENE__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_SLOVENE__
	#define __MMI_HANWANG_SLOVENE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SPANISH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_SPANISH__
	#define __MMI_HANWANG_SPANISH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_SWEDISH) && ((CFG_MMI_IME_HANDWRITING_SWEDISH == __ON__)||(CFG_MMI_IME_HANDWRITING_SWEDISH == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_SWEDISH__))
	#ifndef __MMI_IME_HANDWRITING_SWEDISH__
	#define __MMI_IME_HANDWRITING_SWEDISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SWEDISH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_SWEDISH__
	#define __MMI_HANWANG_SWEDISH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_THAI) && ((CFG_MMI_IME_HANDWRITING_THAI == __ON__)||(CFG_MMI_IME_HANDWRITING_THAI == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_THAI__))
	#ifndef __MMI_IME_HANDWRITING_THAI__
	#define __MMI_IME_HANDWRITING_THAI__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_THAI__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_THAI__
	#define __MMI_HANWANG_THAI__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_TURKISH__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_TURKISH__
	#define __MMI_HANWANG_TURKISH__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_UKRANIAN) && ((CFG_MMI_IME_HANDWRITING_UKRANIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_UKRANIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_UKRANIAN__))
	#ifndef __MMI_IME_HANDWRITING_UKRANIAN__
	#define __MMI_IME_HANDWRITING_UKRANIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_UKRANIAN__) && defined(__MMI_HANWANG__))
	#ifndef __MMI_HANWANG_UKRANIAN__
	#define __MMI_HANWANG_UKRANIAN__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_HIDD_PROFILE__))
	#ifndef __MMI_HIDD_SUPPORT__
	#define __MMI_HIDD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_HIJRI_CALENDAR) && ((CFG_MMI_HIJRI_CALENDAR == __ON__)||(CFG_MMI_HIJRI_CALENDAR == __AUTO__)) && \
	(!defined(__COSMOS_MMI_PACKAGE__))
	#if (!defined(__MMI_CALENDAR__))
	#error "Please turn on CFG_MMI_CALENDAR to enable Hijri Calendar"
	#endif
	#ifndef __MMI_HIJRI_CALENDAR__
	#define __MMI_HIJRI_CALENDAR__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_320X240__)&&!defined(__MMI_FWUI_SLIM__))
	#ifndef __MMI_ICON_BAR_SUPPORT__
	#define __MMI_ICON_BAR_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT) && (CFG_MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT == __ON__) || \
	(!defined(__MMI_LAUNCHER_APP_LIST__))
	#ifndef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__
	#define __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_IDLE_FULL_SCREEN) && ((CFG_MMI_IDLE_FULL_SCREEN == __ON__)||(CFG_MMI_IDLE_FULL_SCREEN == __AUTO__))
	#ifndef __MMI_IDLE_FULL_SCREEN__
	#define __MMI_IDLE_FULL_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_IDLE_SCREEN_ICON_SHORTCUT) && ((CFG_MMI_IDLE_SCREEN_ICON_SHORTCUT == __ON__)||(CFG_MMI_IDLE_SCREEN_ICON_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_320X480__)) && (defined(__MMI_ICON_BAR_SUPPORT__))
	#ifndef __MMI_IDLE_SCREEN_ICON_SHORTCUT__
	#define __MMI_IDLE_SCREEN_ICON_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_IMAGE_CLIP_CUI) && ((CFG_MMI_IMAGE_CLIP_CUI == __ON__)||(CFG_MMI_IMAGE_CLIP_CUI == __AUTO__)) && \
	((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_IMAGE_CLIP_CUI__
	#define __MMI_IMAGE_CLIP_CUI__
	#endif
#endif


#if (defined(__MMI_IMAGE_VIEWER__) && defined(__IMAGE_VIEWER_STANDARD__) && defined(JPG_DECODE) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_IMAGE_VIEWER_STD__
	#define __MMI_IMAGE_VIEWER_STD__
	#endif
#endif


#if (defined(__MMI_IMAGE_VIEWER__) && !defined(__MMI_IMAGE_VIEWER_STD__) && !defined(__MMI_IMAGE_VIEWER_EX__))
	#ifndef __MMI_IMAGE_VIEWER_BASIC__
	#define __MMI_IMAGE_VIEWER_BASIC__
	#endif
#endif


#if (defined(__IMAGE_VIEWER_EX_SHARE_ASMMEM__) && defined(__MMI_IMAGE_VIEWER_EX__))
	#ifndef __MMI_IMAGE_VIEWER_EX_MEM_SRC__
	#define __MMI_IMAGE_VIEWER_EX_MEM_SRC__	MMI_IMAGE_VIEWER_EX_MEM_SRC_ASM
	#endif
#elif (defined(__IMAGE_VIEWER_EX_SHARE_MEDMEM__) && defined(__MMI_IMAGE_VIEWER_EX__))
	#ifndef __MMI_IMAGE_VIEWER_EX_MEM_SRC__
	#define __MMI_IMAGE_VIEWER_EX_MEM_SRC__	MMI_IMAGE_VIEWER_EX_MEM_SRC_MED
	#endif
#elif (defined(__MMI_IMAGE_VIEWER_EX__))
	#ifndef __MMI_IMAGE_VIEWER_EX_MEM_SRC__
	#define __MMI_IMAGE_VIEWER_EX_MEM_SRC__	MMI_IMAGE_VIEWER_EX_MEM_SRC_DEF
	#endif
#endif


#if defined(CFG_MMI_IME_T9_DEFAULT_KEY_DEFINITION) && ((CFG_MMI_IME_T9_DEFAULT_KEY_DEFINITION == __ON__)||(CFG_MMI_IME_T9_DEFAULT_KEY_DEFINITION == __AUTO__)) && \
	(defined(__MMI_T9__) && defined(__MMI_NORMAL_KEYPAD__))
	#ifndef __MMI_IME_T9_DEFAULT_KEY_DEFINITION__
	#define __MMI_IME_T9_DEFAULT_KEY_DEFINITION__
	#endif
#endif


#if defined(CFG_MMI_MULTITAP) && ((CFG_MMI_MULTITAP == __ON__)||(CFG_MMI_MULTITAP == __AUTO__))
	#ifndef __MMI_MULTITAP__
	#define __MMI_MULTITAP__
	#endif
#endif


#if defined(CFG_MMI_T9_MULTITAP) && ((CFG_MMI_T9_MULTITAP == __ON__)||(CFG_MMI_T9_MULTITAP == __AUTO__)) && \
	(defined(__MMI_T9__) && ( defined(__MMI_NORMAL_KEYPAD__)  || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)))
	#ifndef __MMI_T9_MULTITAP__
	#define __MMI_T9_MULTITAP__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_THAI__)&& (defined(__MMI_IME_V3__) || defined(__MMI_T9_MULTITAP__) || defined(__MMI_CSTAR_MULTITAP__)))
	#ifndef __MMI_MULTITAP_THAI__
	#define __MMI_MULTITAP_THAI__
	#endif
#endif


#if (defined(__MMI_IME_THAI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_THAI__
	#define __MMI_T9_THAI__
	#endif
#endif


#if defined(CFG_MMI_IME_MULTITAP_THAI_PROFILE_1) && ((CFG_MMI_IME_MULTITAP_THAI_PROFILE_1 == __ON__)||(CFG_MMI_IME_MULTITAP_THAI_PROFILE_1 == __AUTO__)) && \
	(defined(__MMI_MULTITAP_THAI__) && defined(__MMI_T9_THAI__) && defined(__MMI_NORMAL_KEYPAD__))
	#ifndef __MMI_IME_MULTITAP_THAI_PROFILE_1__
	#define __MMI_IME_MULTITAP_THAI_PROFILE_1__
	#endif
#endif


#if (defined(__MMI_IME_T9_DEFAULT_KEY_DEFINITION__) || defined(__MMI_IME_MULTITAP_THAI_PROFILE_1__))
	#ifndef __MMI_MULTITAP_FOR_STAR_AND_POUND__
	#define __MMI_MULTITAP_FOR_STAR_AND_POUND__
	#endif
#endif


#if defined(CFG_MMI_IME_IMC_CAPITAL_SWITCH) && ((CFG_MMI_IME_IMC_CAPITAL_SWITCH == __ON__)||(CFG_MMI_IME_IMC_CAPITAL_SWITCH == __AUTO__)) && \
	(((defined(__MMI_IME_PREFER_WRITING_LANG__) || defined(__MMI_IME_MIXED_LANG_SUPPORT__)) && !(defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) && !defined(__MMI_TOUCH_SCREEN__)) && !(defined(__MMI_REDUCED_KEYPAD__) && !defined(__MMI_FTE_SUPPORT__))) && !defined(__MMI_IME_V3__))
	#ifndef __MMI_IME_IMC_CAPITAL_SWITCH__
	#define __MMI_IME_IMC_CAPITAL_SWITCH__
	#endif
#endif


#if (defined (__MMI_IME_IMC_CAPITAL_SWITCH__))
	#ifndef __MMI_IMC_CAPITAL_SWITCH__
	#define __MMI_IMC_CAPITAL_SWITCH__
	#endif
#endif


#if defined(CFG_MMI_IME_USER_DATABASE) && ((CFG_MMI_IME_USER_DATABASE == __ON__)||(CFG_MMI_IME_USER_DATABASE == __AUTO__)) && \
	((defined(__MMI_ZI__) || (defined(__MMI_T9__)|| defined(__MMI_GUOBI__) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__))) || ((defined(__MMI_CSTAR__) || defined(__MMI_CSTAR_V2__)) && defined(__MMI_NORMAL_KEYPAD__) && !defined(__MMI_TOUCH_SCREEN__)))) || ((defined(__MMI_CSTAR_PHRASE_INPUT__)) && !defined(__MMI_IME_PLUTO_SLIM__))
	#ifndef __MMI_IME_USER_DATABASE__
	#define __MMI_IME_USER_DATABASE__
	#endif
#endif


#if defined(CFG_MMI_IME_ALPHABETIC_WORD_PREDICTION) && ((CFG_MMI_IME_ALPHABETIC_WORD_PREDICTION == __ON__)||(CFG_MMI_IME_ALPHABETIC_WORD_PREDICTION == __AUTO__)) && \
	(defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__))
	#ifndef __MMI_IME_ALPHABETIC_WORD_PREDICTION__
	#define __MMI_IME_ALPHABETIC_WORD_PREDICTION__
	#endif
#endif


#if defined(CFG_MMI_LANG_ASSAMESE) && ((CFG_MMI_LANG_ASSAMESE == __ON__)||(CFG_MMI_LANG_ASSAMESE == __AUTO__))
	#ifndef __MMI_LANG_ASSAMESE__
	#define __MMI_LANG_ASSAMESE__
	#endif
#endif


#if defined(CFG_MMI_IME_ASSAMESE) && ((CFG_MMI_IME_ASSAMESE == __ON__)||(CFG_MMI_IME_ASSAMESE == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_ASSAMESE__))
	#ifndef __MMI_IME_ASSAMESE__
	#define __MMI_IME_ASSAMESE__
	#endif
#endif


#if (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__))
	#ifndef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
	#define __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__
	#endif
#endif


#if defined(CFG_MMI_IME_SMART_FIRST_UPPERCASE) && ((CFG_MMI_IME_SMART_FIRST_UPPERCASE == __ON__)||(CFG_MMI_IME_SMART_FIRST_UPPERCASE == __AUTO__)) && \
	((defined(__MMI_ZI__) || defined(__MMI_T9__) || defined(__MMI_CSTAR__)|| defined(__MMI_GUOBI__)) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__))) || (defined(MMI_IME_V3_SUPPORT) && ((defined(__MMI_ZI__) || defined(__MMI_T9__) || defined(__MMI_CSTAR__)|| defined(__MMI_GUOBI__)) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__))))
	#ifndef __MMI_IME_SMART_FIRST_UPPERCASE__
	#define __MMI_IME_SMART_FIRST_UPPERCASE__
	#endif
#endif


#if (defined(__MMI_IME_SMART_FIRST_UPPERCASE__))
	#ifndef __MMI_SMART_FIRST_UPPERCASE__
	#define __MMI_SMART_FIRST_UPPERCASE__
	#endif
#endif


#if defined(CFG_MMI_IME_MULTITAP_FIRST_UPPERCASE) && ((CFG_MMI_IME_MULTITAP_FIRST_UPPERCASE == __ON__)||(CFG_MMI_IME_MULTITAP_FIRST_UPPERCASE == __AUTO__)) && \
	(defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)) || (defined(MMI_IME_V3_SUPPORT) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)))
	#ifndef __MMI_IME_MULTITAP_FIRST_UPPERCASE__
	#define __MMI_IME_MULTITAP_FIRST_UPPERCASE__
	#endif
#endif


#if (defined(__MMI_IME_MULTITAP_FIRST_UPPERCASE__))
	#ifndef __MMI_MULTITAP_FIRST_UPPERCASE__
	#define __MMI_MULTITAP_FIRST_UPPERCASE__
	#endif
#endif


#if defined(CFG_MMI_IME_AUTO_CAPITALIZATION) && ((CFG_MMI_IME_AUTO_CAPITALIZATION == __ON__)||(CFG_MMI_IME_AUTO_CAPITALIZATION == __AUTO__)) && \
	(defined(__MMI_IME_FTE_ENHANCE__) && !defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) && (defined( __MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)))
	#ifndef __MMI_IME_AUTO_CAPITALIZATION__
	#define __MMI_IME_AUTO_CAPITALIZATION__
	#endif
#endif


#if defined(CFG_MMI_LANG_AZERBAIJANI) && ((CFG_MMI_LANG_AZERBAIJANI == __ON__)||(CFG_MMI_LANG_AZERBAIJANI == __AUTO__))
	#ifndef __MMI_LANG_AZERBAIJANI__
	#define __MMI_LANG_AZERBAIJANI__
	#endif
#endif


#if defined(CFG_MMI_IME_AZERBAIJANI) && ((CFG_MMI_IME_AZERBAIJANI == __ON__)||(CFG_MMI_IME_AZERBAIJANI == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_AZERBAIJANI__))
	#ifndef __MMI_IME_AZERBAIJANI__
	#define __MMI_IME_AZERBAIJANI__
	#endif
#endif


#if (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) && !defined(__MMI_IME_PLUTO_SLIM__))
	#ifndef __MMI_IME_CANDIDATE_GRID__
	#define __MMI_IME_CANDIDATE_GRID__
	#endif
#endif


#if defined(CFG_MMI_LANG_CATALAN) && ((CFG_MMI_LANG_CATALAN == __ON__)||(CFG_MMI_LANG_CATALAN == __AUTO__))
	#ifndef __MMI_LANG_CATALAN__
	#define __MMI_LANG_CATALAN__
	#endif
#endif


#if defined(CFG_MMI_IME_CATALAN) && ((CFG_MMI_IME_CATALAN == __ON__)||(CFG_MMI_IME_CATALAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_CATALAN__))
	#ifndef __MMI_IME_CATALAN__
	#define __MMI_IME_CATALAN__
	#endif
#endif


#if (defined(__MMI_IME_SLIM__) && defined(__COSMOS_MMI__))
	#ifndef __MMI_IME_COSMOS_SLIM__
	#define __MMI_IME_COSMOS_SLIM__
	#endif
#endif


#if defined(CFG_MMI_IME_CSTAR_USER_DICT) && ((CFG_MMI_IME_CSTAR_USER_DICT == __ON__)||(CFG_MMI_IME_CSTAR_USER_DICT == __AUTO__)) && \
	((defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_CSTAR__)) || defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) ||  defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__))
	#ifndef __MMI_IME_CSTAR_USER_DICT__
	#define __MMI_IME_CSTAR_USER_DICT__
	#endif
#endif


#if defined(CFG_MMI_IME_FUZZY_PINYIN) && ((CFG_MMI_IME_FUZZY_PINYIN == __ON__)||(CFG_MMI_IME_FUZZY_PINYIN == __AUTO__)) && \
	(defined (__MMI_IME_V3__) && defined (__MMI_IME_SM_CHINESE__))
	#ifndef __MMI_IME_FUZZY_PINYIN__
	#define __MMI_IME_FUZZY_PINYIN__
	#endif
#endif


#if defined(CFG_MMI_LANG_GALICIAN) && ((CFG_MMI_LANG_GALICIAN == __ON__)||(CFG_MMI_LANG_GALICIAN == __AUTO__))
	#ifndef __MMI_LANG_GALICIAN__
	#define __MMI_LANG_GALICIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_GALICIAN) && ((CFG_MMI_IME_GALICIAN == __ON__)||(CFG_MMI_IME_GALICIAN == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_GALICIAN__))
	#ifndef __MMI_IME_GALICIAN__
	#define __MMI_IME_GALICIAN__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_MULTI_BLOCK) && ((CFG_MMI_IME_HANDWRITING_MULTI_BLOCK == __ON__)||(CFG_MMI_IME_HANDWRITING_MULTI_BLOCK == __AUTO__)) && \
	(!defined(__MMI_IME_FTE_ENHANCE__) && defined( __MMI_TOUCH_SCREEN__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_IME_HANDWRITING_MULTI_BLOCK__
	#define __MMI_IME_HANDWRITING_MULTI_BLOCK__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_SLOVAK) && ((CFG_MMI_IME_HANDWRITING_SLOVAK == __ON__)||(CFG_MMI_IME_HANDWRITING_SLOVAK == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_SLOVAK__))
	#ifndef __MMI_IME_HANDWRITING_SLOVAK__
	#define __MMI_IME_HANDWRITING_SLOVAK__
	#endif
#endif


#if defined(CFG_MMI_IME_HANDWRITING_SLOVENIAN) && ((CFG_MMI_IME_HANDWRITING_SLOVENIAN == __ON__)||(CFG_MMI_IME_HANDWRITING_SLOVENIAN == __AUTO__)) && \
	(defined (__MMI_TOUCH_SCREEN__) && defined(__MMI_LANG_SLOVENIAN__))
	#ifndef __MMI_IME_HANDWRITING_SLOVENIAN__
	#define __MMI_IME_HANDWRITING_SLOVENIAN__
	#endif
#endif


#if defined(CFG_MMI_LANG_HAUSA) && ((CFG_MMI_LANG_HAUSA == __ON__)||(CFG_MMI_LANG_HAUSA == __AUTO__))
	#ifndef __MMI_LANG_HAUSA__
	#define __MMI_LANG_HAUSA__
	#endif
#endif


#if defined(CFG_MMI_IME_HAUSA) && ((CFG_MMI_IME_HAUSA == __ON__)||(CFG_MMI_IME_HAUSA == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_HAUSA__))
	#ifndef __MMI_IME_HAUSA__
	#define __MMI_IME_HAUSA__
	#endif
#endif


#if defined(CFG_MMI_IME_HK_CHINESE) && ((CFG_MMI_IME_HK_CHINESE == __ON__)||(CFG_MMI_IME_HK_CHINESE == __AUTO__)) && \
	(defined(__MMI_LANG_HK_CHINESE__))
	#ifndef __MMI_IME_HK_CHINESE__
	#define __MMI_IME_HK_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_LANG_ICELANDIC) && ((CFG_MMI_LANG_ICELANDIC == __ON__)||(CFG_MMI_LANG_ICELANDIC == __AUTO__))
	#ifndef __MMI_LANG_ICELANDIC__
	#define __MMI_LANG_ICELANDIC__
	#endif
#endif


#if defined(CFG_MMI_IME_ICELANDIC) && ((CFG_MMI_IME_ICELANDIC == __ON__)||(CFG_MMI_IME_ICELANDIC == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_ICELANDIC__))
	#ifndef __MMI_IME_ICELANDIC__
	#define __MMI_IME_ICELANDIC__
	#endif
#endif


#if defined(CFG_MMI_LANG_IGBO) && ((CFG_MMI_LANG_IGBO == __ON__)||(CFG_MMI_LANG_IGBO == __AUTO__))
	#ifndef __MMI_LANG_IGBO__
	#define __MMI_LANG_IGBO__
	#endif
#endif


#if defined(CFG_MMI_IME_IGBO) && ((CFG_MMI_IME_IGBO == __ON__)||(CFG_MMI_IME_IGBO == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_IGBO__))
	#ifndef __MMI_IME_IGBO__
	#define __MMI_IME_IGBO__
	#endif
#endif


#if (defined(__MMI_IME_FTE_ENHANCE__) || (defined(__MMI_VUI_HOMESCREEN_BAIDU_SEARCH__) && defined(__MMI_QWERTY_KEYPAD_SUPPORT__)))
	#ifndef __MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__
	#define __MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__
	#endif
#endif


#if defined(CFG_MMI_IME_INPUT_MODE_CHANGE_RULES) && ((CFG_MMI_IME_INPUT_MODE_CHANGE_RULES == __ON__)||(CFG_MMI_IME_INPUT_MODE_CHANGE_RULES == __AUTO__)) && \
	(defined(__MMI_IME_IMC_CAPITAL_SWITCH__))
	#ifndef __MMI_IME_INPUT_MODE_CHANGE_RULES__
	#define __MMI_IME_INPUT_MODE_CHANGE_RULES__
	#endif
#endif


#if defined(CFG_MMI_LANG_IRISH) && ((CFG_MMI_LANG_IRISH == __ON__)||(CFG_MMI_LANG_IRISH == __AUTO__))
	#ifndef __MMI_LANG_IRISH__
	#define __MMI_LANG_IRISH__
	#endif
#endif


#if defined(CFG_MMI_IME_IRISH) && ((CFG_MMI_IME_IRISH == __ON__)||(CFG_MMI_IME_IRISH == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_IRISH__))
	#ifndef __MMI_IME_IRISH__
	#define __MMI_IME_IRISH__
	#endif
#endif


#if defined(CFG_MMI_LANG_KANNADA) && ((CFG_MMI_LANG_KANNADA == __ON__)||(CFG_MMI_LANG_KANNADA == __AUTO__))
	#ifndef __MMI_LANG_KANNADA__
	#define __MMI_LANG_KANNADA__
	#endif
#endif


#if defined(CFG_MMI_IME_KANNADA) && ((CFG_MMI_IME_KANNADA == __ON__)||(CFG_MMI_IME_KANNADA == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_KANNADA__))
	#ifndef __MMI_IME_KANNADA__
	#define __MMI_IME_KANNADA__
	#endif
#endif


#if defined(CFG_MMI_IME_MAGIC_ONE) && ((CFG_MMI_IME_MAGIC_ONE == __ON__)||(CFG_MMI_IME_MAGIC_ONE == __AUTO__)) && \
	(defined(__MMI_CSTAR_V2__) && !defined(__MMI_TOUCH_SCREEN__)&& defined(__MMI_NORMAL_KEYPAD__) && (defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)  || defined(__MMI_CSTAR_STROKE_INPUT__))&& defined(__MMI_CSTAR_ENGLISH__) && !defined(__OP01_FWPBW__))
	#ifndef __MMI_IME_MAGIC_ONE__
	#define __MMI_IME_MAGIC_ONE__
	#endif
#endif


#if defined(CFG_MMI_IME_MEMORY_CARD_SUPPORT) && ((CFG_MMI_IME_MEMORY_CARD_SUPPORT == __ON__)||(CFG_MMI_IME_MEMORY_CARD_SUPPORT == __AUTO__)) && \
	((defined(__MMI_IME_V3__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__) || !defined(__MMI_FTE_SUPPORT__)) && defined(__MMI_GUOBI__))
	#ifndef __MMI_IME_MEMORY_CARD_SUPPORT__
	#define __MMI_IME_MEMORY_CARD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_IME_MULTITAP_THAI_PROFILE_2) && ((CFG_MMI_IME_MULTITAP_THAI_PROFILE_2 == __ON__)||(CFG_MMI_IME_MULTITAP_THAI_PROFILE_2 == __AUTO__)) && \
	(defined(__MMI_MULTITAP_THAI__) && !defined(__MMI_T9_THAI__))
	#ifndef __MMI_IME_MULTITAP_THAI_PROFILE_2__
	#define __MMI_IME_MULTITAP_THAI_PROFILE_2__
	#endif
#endif


#if defined(CFG_MMI_LANG_ORIYA) && ((CFG_MMI_LANG_ORIYA == __ON__)||(CFG_MMI_LANG_ORIYA == __AUTO__))
	#ifndef __MMI_LANG_ORIYA__
	#define __MMI_LANG_ORIYA__
	#endif
#endif


#if defined(CFG_MMI_IME_ORIYA) && ((CFG_MMI_IME_ORIYA == __ON__)||(CFG_MMI_IME_ORIYA == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_ORIYA__))
	#ifndef __MMI_IME_ORIYA__
	#define __MMI_IME_ORIYA__
	#endif
#endif


#if (defined(__MMI_KOMOXO__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_IME_PLUG_IN__
	#define __MMI_IME_PLUG_IN__
	#endif
#endif


#if (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)&& !defined(__MMI_IME_PLUTO_SLIM__))
	#ifndef __MMI_IME_SCROLLING_COMPOSITION__
	#define __MMI_IME_SCROLLING_COMPOSITION__
	#endif
#endif


#if defined(CFG_MMI_LANG_SESOTHO) && ((CFG_MMI_LANG_SESOTHO == __ON__)||(CFG_MMI_LANG_SESOTHO == __AUTO__))
	#ifndef __MMI_LANG_SESOTHO__
	#define __MMI_LANG_SESOTHO__
	#endif
#endif


#if defined(CFG_MMI_IME_SESOTHO) && ((CFG_MMI_IME_SESOTHO == __ON__)||(CFG_MMI_IME_SESOTHO == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)&& defined(__MMI_LANG_SESOTHO__))
	#ifndef __MMI_IME_SESOTHO__
	#define __MMI_IME_SESOTHO__
	#endif
#endif


#if defined(CFG_MMI_IME_VERTICAL_CAND_BOX) && ((CFG_MMI_IME_VERTICAL_CAND_BOX == __ON__)||(CFG_MMI_IME_VERTICAL_CAND_BOX == __AUTO__)) && \
	(defined(__MMI_IME_FLOATING_CAND_BOX__)  && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && !defined(__MMI_IME_FTE_ENHANCE__))
	#ifndef __MMI_IME_VERTICAL_CAND_BOX__
	#define __MMI_IME_VERTICAL_CAND_BOX__
	#endif
#endif


#if defined(CFG_MMI_LANG_XHOSA) && ((CFG_MMI_LANG_XHOSA == __ON__)||(CFG_MMI_LANG_XHOSA == __AUTO__))
	#ifndef __MMI_LANG_XHOSA__
	#define __MMI_LANG_XHOSA__
	#endif
#endif


#if defined(CFG_MMI_IME_XHOSA) && ((CFG_MMI_IME_XHOSA == __ON__)||(CFG_MMI_IME_XHOSA == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_XHOSA__))
	#ifndef __MMI_IME_XHOSA__
	#define __MMI_IME_XHOSA__
	#endif
#endif


#if defined(CFG_MMI_LANG_YORUBA) && ((CFG_MMI_LANG_YORUBA == __ON__)||(CFG_MMI_LANG_YORUBA == __AUTO__))
	#ifndef __MMI_LANG_YORUBA__
	#define __MMI_LANG_YORUBA__
	#endif
#endif


#if defined(CFG_MMI_IME_YORUBA) && ((CFG_MMI_IME_YORUBA == __ON__)||(CFG_MMI_IME_YORUBA == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_YORUBA__))
	#ifndef __MMI_IME_YORUBA__
	#define __MMI_IME_YORUBA__
	#endif
#endif


#if defined(CFG_MMI_LANG_ZULU) && ((CFG_MMI_LANG_ZULU == __ON__)||(CFG_MMI_LANG_ZULU == __AUTO__))
	#ifndef __MMI_LANG_ZULU__
	#define __MMI_LANG_ZULU__
	#endif
#endif


#if defined(CFG_MMI_IME_ZULU) && ((CFG_MMI_IME_ZULU == __ON__)||(CFG_MMI_IME_ZULU == __AUTO__)) && \
	(defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_LANG_ZULU__))
	#ifndef __MMI_IME_ZULU__
	#define __MMI_IME_ZULU__
	#endif
#endif


#if (defined(DSP_WT_SYN))
	#ifndef __MMI_IMELODY_SUPPORT__
	#define __MMI_IMELODY_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_IMGVIEW_CACHE) && ((CFG_MMI_IMGVIEW_CACHE == __ON__)||(CFG_MMI_IMGVIEW_CACHE == __AUTO__)) && \
	(defined(__IMAGE_VIEWER_STANDARD__))
	#ifndef __MMI_IMGVIEW_CACHE__
	#define __MMI_IMGVIEW_CACHE__
	#endif
#endif


#if (defined(__MMI_IME_INPUT_MODE_CHANGE_RULES__))
	#ifndef __MMI_IMM_INPUT_MODE_CHANGE_RULES__
	#define __MMI_IMM_INPUT_MODE_CHANGE_RULES__
	#endif
#endif


#if (defined(__IMPS__))
	#ifndef __MMI_IMPS__
	#define __MMI_IMPS__
	#endif
#endif


#if (defined(__MMI_IMPS__) && defined(__MMI_CCA_SUPPORT__))
	#ifndef __MMI_IMPS_OTA__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_LANG_ZAWGYI_MYANMAR) && ((CFG_MMI_LANG_ZAWGYI_MYANMAR == __ON__)||(CFG_MMI_LANG_ZAWGYI_MYANMAR == __AUTO__))
	#ifndef __MMI_LANG_ZAWGYI_MYANMAR__
	#define __MMI_LANG_ZAWGYI_MYANMAR__
	#endif
#endif


#if (defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_TAMIL__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__) || defined(__MMI_LANG_TELUGU__) || defined(__MMI_LANG_PUNJABI__) || defined(__MMI_LANG_KANNADA__) || defined(__MMI_LANG_GUJARATI__) || defined(__MMI_LANG_MALAYALAM__) || defined(__MMI_LANG_ORIYA__) || defined(__MMI_LANG_LAO__) || defined(__MMI_LANG_KHMER__) || defined(__MMI_LANG_MYANMAR__) || defined(__MMI_LANG_ZAWGYI_MYANMAR__))
	#ifndef __MMI_INDIC_ALG__
	#define __MMI_INDIC_ALG__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_HINDI__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_HINDI__
	#define __MMI_INDIC_VK_HINDI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_TAMIL__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_TAMIL__
	#define __MMI_INDIC_VK_TAMIL__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_MARATHI__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_MARATHI__
	#define __MMI_INDIC_VK_MARATHI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_BENGALI__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_BENGALI__
	#define __MMI_INDIC_VK_BENGALI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_TELUGU__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_TELUGU__
	#define __MMI_INDIC_VK_TELUGU__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_PUNJABI__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_PUNJABI__
	#define __MMI_INDIC_VK_PUNJABI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_KANNADA__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_KANNADA__
	#define __MMI_INDIC_VK_KANNADA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_GUJARATI__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_GUJARATI__
	#define __MMI_INDIC_VK_GUJARATI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_ORIYA__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_ORIYA__
	#define __MMI_INDIC_VK_ORIYA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_MALAYALAM__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_MALAYALAM__
	#define __MMI_INDIC_VK_MALAYALAM__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_ASSAMESE__)  &&  defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_INDIC_VK_ASSAMESE__
	#define __MMI_INDIC_VK_ASSAMESE__
	#endif
#endif


#if ((!defined(__MMI_IME_V3__)) && (defined(__MMI_INDIC_VK_HINDI__) || defined(__MMI_INDIC_VK_TAMIL__) || defined(__MMI_INDIC_VK_MARATHI__)  || defined(__MMI_INDIC_VK_BENGALI__) || defined(__MMI_INDIC_VK_TELUGU__) || defined(__MMI_INDIC_VK_PUNJABI__) || defined(__MMI_INDIC_VK_KANNADA__) || defined(__MMI_INDIC_VK_GUJARATI__)|| defined(__MMI_INDIC_VK_ORIYA__)|| defined(__MMI_INDIC_VK_MALAYALAM__) || defined(__MMI_INDIC_VK_ASSAMESE__)))
	#ifndef __MMI_INDIC_VK__
	#define __MMI_INDIC_VK__
	#endif
#endif


#if defined(CFG_MMI_INDICAL) && ((CFG_MMI_INDICAL == __ON__)||(CFG_MMI_INDICAL == __AUTO__)) && \
	(defined(__MMI_CALENDAR__))
	#ifndef __MMI_INDICAL__
	#define __MMI_INDICAL__
	#endif
#endif


#if ((!defined(__MMI_BASIC_UI_STYLE__) && (!(defined(__COSMOS_MMI_PACKAGE__) && defined(LOW_COST_SUPPORT))))) ||\
	 (defined(__MMI_EMAIL__))
	#ifndef __MMI_INLINE_ITEM_ATTACHMENT__
	#define __MMI_INLINE_ITEM_ATTACHMENT__
	#endif
#endif


#if (defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_INLINE_ITEM_BUTTON__
	#define __MMI_INLINE_ITEM_BUTTON__
	#endif
#endif


#if (defined(__MMI_MOBILE_TV_CMMB_SUPPORT__))
	#ifndef __MMI_INLINE_ITEM_CHECKBOX__
	#define __MMI_INLINE_ITEM_CHECKBOX__
	#endif
#endif


#if ((!defined(__MMI_BASIC_UI_STYLE__) && (!(defined(__COSMOS_MMI_PACKAGE__) && defined(LOW_COST_SUPPORT))))) ||\
	 (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_PHOTOEDITOR__))
	#ifndef __MMI_INLINE_ITEM_COLOR_SELECT__
	#define __MMI_INLINE_ITEM_COLOR_SELECT__
	#endif
#endif


#if (defined(__MMI_INLINE_SLIM__))
	#ifndef __MMI_INLINE_ITEM_DATE__
	#define __MMI_INLINE_ITEM_DATE__
	#endif
#endif


#if (!defined(__MMI_BASIC_UI_STYLE__) && (!(defined(__COSMOS_MMI_PACKAGE__) && defined(LOW_COST_SUPPORT))))
	#ifndef __MMI_INLINE_ITEM_DOW__
	#define __MMI_INLINE_ITEM_DOW__
	#endif
#endif


#if (defined(__MMI_INLINE_SLIM__))
	#ifndef __MMI_INLINE_ITEM_IP4__
	#define __MMI_INLINE_ITEM_IP4__
	#endif
#endif


#if (!defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_EMAIL__))
	#ifndef __MMI_INLINE_ITEM_MULTILINE_EDIT__
	#define __MMI_INLINE_ITEM_MULTILINE_EDIT__
	#endif
#endif


#if (!defined(__MMI_BASIC_UI_STYLE__) || (defined(__MMI_ZAKAT_CALCULATOR__) || defined(__MMI_EMAIL__))) ||\
	 (defined(__MMI_ZAKAT_CALCULATOR__) || defined(__MMI_EMAIL__))
	#ifndef __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__
	#define __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__
	#endif
#endif


#if (defined(__MMI_EM_MISC_TOUCH_SCREEN__) || !defined(__MMI_BASIC_UI_STYLE__))
	#ifndef __MMI_INLINE_ITEM_PROGRESS_BAR__
	#define __MMI_INLINE_ITEM_PROGRESS_BAR__
	#endif
#endif


#if (defined(__MMI_MOBILE_TV_CMMB_SUPPORT__))
	#ifndef __MMI_INLINE_ITEM_RADIO__
	#define __MMI_INLINE_ITEM_RADIO__
	#endif
#endif


#if (defined(__MMI_INLINE_SLIM__))
	#ifndef __MMI_INLINE_ITEM_TIME__
	#define __MMI_INLINE_ITEM_TIME__
	#endif
#endif


#if (defined(__IPSEC__))
	#ifndef __MMI_IPSEC__
	#define __MMI_IPSEC__
	#endif
#endif


#if defined(CFG_MMI_IRE_SLIM) && ((CFG_MMI_IRE_SLIM == __ON__)||(CFG_MMI_IRE_SLIM == __AUTO__))
	#ifndef __MMI_IRE_SLIM__
	#define __MMI_IRE_SLIM__
	#endif
#endif


#if defined(CFG_MMI_IV_PLUTO_SLIM) && ((CFG_MMI_IV_PLUTO_SLIM == __ON__)||(CFG_MMI_IV_PLUTO_SLIM == __AUTO__)) && \
	(defined(__MMI_IMAGE_VIEWER__))
	#ifndef __MMI_IV_PLUTO_SLIM__
	#define __MMI_IV_PLUTO_SLIM__
	#endif
#endif


#if (defined(__J2ME__) && defined (__NEMO_VM__) && !defined(J2ME_SHARE_MED_EXT_MEM))
	#ifndef __MMI_JAVA_PACKAGE_MIDS__
	#define __MMI_JAVA_PACKAGE_MIDS__
	#endif
#endif


#if defined(CFG_MMI_KARAOKE) && ((CFG_MMI_KARAOKE == __ON__)||(CFG_MMI_KARAOKE == __AUTO__)) && \
	(defined(__KARAOKE_SUPPORT__))
	#ifndef __MMI_KARAOKE__
	#define __MMI_KARAOKE__
	#endif
#endif


#if defined(CFG_MMI_LANG_MOLDOVAN) && ((CFG_MMI_LANG_MOLDOVAN == __ON__)||(CFG_MMI_LANG_MOLDOVAN == __AUTO__))
	#ifndef __MMI_LANG_MOLDOVAN__
	#define __MMI_LANG_MOLDOVAN__
	#endif
#endif


#if defined(CFG_MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER) && ((CFG_MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER == __ON__)||(CFG_MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER == __AUTO__)) && \
	(defined(__MMI_LAUNCHER_APP_LIST__))
	#ifndef __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
	#define __MMI_LAUNCHER_APP_LIST_INTERACTIVE_VIDEO_WALLPAPER__
	#endif
#endif


#if defined(CFG_MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER) && ((CFG_MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER == __ON__)||(CFG_MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER == __AUTO__)) && \
	(defined(__MMI_LAUNCHER_APP_LIST__) && defined(MP4_DECODE) && !defined(MCU_245_76M))
	#ifndef __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
	#define __MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__
	#endif
#endif


#if defined(CFG_MMI_LCD_PARTIAL_ON) && ((CFG_MMI_LCD_PARTIAL_ON == __ON__)||(CFG_MMI_LCD_PARTIAL_ON == __AUTO__)) && \
	(!defined(__MMI_CLAMSHELL__))
	#ifndef __MMI_LCD_PARTIAL_ON__
	#define __MMI_LCD_PARTIAL_ON__
	#endif
#endif


#if defined(CFG_MMI_LCD_PARTIAL_ON_ENABLED) && ((CFG_MMI_LCD_PARTIAL_ON_ENABLED == __ON__)||(CFG_MMI_LCD_PARTIAL_ON_ENABLED == __AUTO__)) && \
	(!defined(__MMI_CLAMSHELL__) && defined(__MMI_GPIO_DISABLE_SLEEP_MODE__))
	#ifndef __MMI_LCD_PARTIAL_ON_ENABLED__
	#define __MMI_LCD_PARTIAL_ON_ENABLED__
	#endif
#endif


#if defined(CFG_MMI_LINE_IN) && ((CFG_MMI_LINE_IN == __ON__)||(CFG_MMI_LINE_IN == __AUTO__)) && \
	((defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_BTBOX_NOLCD__)) && defined(__LINE_IN_SUPPORT__))
	#ifndef __MMI_LINE_IN__
	#define __MMI_LINE_IN__
	#endif
#endif


#if defined(CFG_MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT) && ((CFG_MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT == __ON__)||(CFG_MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT == __AUTO__))
	#ifndef __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
	#define __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_LUNAR_QUERY) && ((CFG_MMI_LUNAR_QUERY == __ON__)||(CFG_MMI_LUNAR_QUERY == __AUTO__))
	#ifndef __MMI_LUNAR_QUERY__
	#define __MMI_LUNAR_QUERY__
	#endif
#endif


#if (defined(MMI_MAIN_LCD_DEFAULT_FORMAT) && (MMI_MAIN_LCD_DEFAULT_FORMAT == 24))
	#ifndef __MMI_MAIN_BASE_LAYER_FORMAT__
	#define __MMI_MAIN_BASE_LAYER_FORMAT__	GDI_COLOR_FORMAT_24
	#endif
#elif (defined(MMI_MAIN_LCD_DEFAULT_FORMAT) && (MMI_MAIN_LCD_DEFAULT_FORMAT == 32))
	#ifndef __MMI_MAIN_BASE_LAYER_FORMAT__
	#define __MMI_MAIN_BASE_LAYER_FORMAT__	GDI_COLOR_FORMAT_32
	#endif
#else
	#ifndef __MMI_MAIN_BASE_LAYER_FORMAT__
	#define __MMI_MAIN_BASE_LAYER_FORMAT__	GDI_COLOR_FORMAT_16
	#endif
#endif


#if (defined(CFG_MMI_MAINMENU_ICON_DEFAULT_SEL))
	#ifndef __MMI_MAINMENU_ICON_DEFAULT_SEL__
	#define __MMI_MAINMENU_ICON_DEFAULT_SEL__	CFG_MMI_MAINMENU_ICON_DEFAULT_SEL
	#endif
#endif


#if ((defined(__MMI_MAINMENU_ICON_DEFAULT_SEL__) && (__MMI_MAINMENU_ICON_DEFAULT_SEL__ == __MAINMENU_ICON_SEL_0__)) || !defined(__MMI_MAINMENU_ICON_DEFAULT_SEL__))
	#ifndef __MMI_MAINMENU_ICON_DEFAULT_PATH__
	#define __MMI_MAINMENU_ICON_DEFAULT_PATH__	"Mainmenu_Icon"
	#endif
#elif ((defined(__MMI_MAINMENU_ICON_DEFAULT_SEL__) && (__MMI_MAINMENU_ICON_DEFAULT_SEL__ == __MAINMENU_ICON_SEL_1__)))
	#ifndef __MMI_MAINMENU_ICON_DEFAULT_PATH__
	#define __MMI_MAINMENU_ICON_DEFAULT_PATH__	"Mainmenu_Icon2"
	#endif
#elif ((defined(__MMI_MAINMENU_ICON_DEFAULT_SEL__) && (__MMI_MAINMENU_ICON_DEFAULT_SEL__ == __MAINMENU_ICON_SEL_2__)))
	#ifndef __MMI_MAINMENU_ICON_DEFAULT_PATH__
	#define __MMI_MAINMENU_ICON_DEFAULT_PATH__	"Mainmenu_Icon3"
	#endif
#else
	#error "Wrong option"
#endif


#if defined(CFG_MMI_MAINMENU_LIST_SUPPORT) && ((CFG_MMI_MAINMENU_LIST_SUPPORT == __ON__)||(CFG_MMI_MAINMENU_LIST_SUPPORT == __AUTO__)) && \
	(!defined(__MMI_VUI_MAINMENU__)) || (__MMI_MAIN_MENU_TYPE__ == __LIST__)
	#ifndef __MMI_MAINMENU_LIST_SUPPORT__
	#define __MMI_MAINMENU_LIST_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MAINMENU_MATRIX_SUPPORT) && ((CFG_MMI_MAINMENU_MATRIX_SUPPORT == __ON__)||(CFG_MMI_MAINMENU_MATRIX_SUPPORT == __AUTO__)) && \
	((!defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_VUI_MAINMENU__)) && (!defined(__MMI_APP_MANAGER_SUPPORT__)||defined(__MMI_LAUNCHER_APP_LIST__)))
	#ifndef __MMI_MAINMENU_MATRIX_SUPPORT__
	#define __MMI_MAINMENU_MATRIX_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MAINMENU_PAGE_SUPPORT) && ((CFG_MMI_MAINMENU_PAGE_SUPPORT == __ON__)||(CFG_MMI_MAINMENU_PAGE_SUPPORT == __AUTO__)) && \
	(!defined(__MMI_TOUCH_SCREEN__)) || ((__MMI_MAIN_MENU_TYPE__ == __PAGE__) && !defined(__MMI_TOUCH_SCREEN__))
	#ifndef __MMI_MAINMENU_PAGE_SUPPORT__
	#define __MMI_MAINMENU_PAGE_SUPPORT__
	#endif
#endif


#if ((defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && defined(__MMI_MAINMENU_PAGE_SUPPORT__)) || (defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && defined(__MMI_MAINMENU_LIST_SUPPORT__)) || (defined(__MMI_MAINMENU_PAGE_SUPPORT__) && defined(__MMI_MAINMENU_LIST_SUPPORT__)))
	#ifndef __MMI_MAINMENU_STYLE_CHANGE_EN__
	#define __MMI_MAINMENU_STYLE_CHANGE_EN__
	#endif
#endif


#if (defined(__MMI_MAINMENU_MATRIX_SUPPORT__))
	#ifndef __MMI_MAINMENU_TYPE__
	#define __MMI_MAINMENU_TYPE__	MATRIX
	#endif
#elif (defined(__MMI_MAINMENU_PAGE_SUPPORT__))
	#ifndef __MMI_MAINMENU_TYPE__
	#define __MMI_MAINMENU_TYPE__	PAGE
	#endif
#else
	#ifndef __MMI_MAINMENU_TYPE__
	#define __MMI_MAINMENU_TYPE__	LIST
	#endif
#endif


#if defined(CFG_MMI_MATRIX_MAIN_MENU_OPTIMIZE) && ((CFG_MMI_MATRIX_MAIN_MENU_OPTIMIZE == __ON__)||(CFG_MMI_MATRIX_MAIN_MENU_OPTIMIZE == __AUTO__)) && \
	(!defined( __MMI_BI_DEGREE_MAIN_MENU_STYLE__))
	#ifndef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
	#define __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
	#endif
#endif


#if defined(CFG_MMI_MATV_SLIM) && ((CFG_MMI_MATV_SLIM == __ON__)||(CFG_MMI_MATV_SLIM == __AUTO__))
	#ifndef __MMI_MATV_SLIM__
	#define __MMI_MATV_SLIM__
	#endif
#endif


#if (defined(__INTEGRATED_PLAYER_FTE__) || defined(__INTEGRATED_PLAYER_FTE_DB__))
	#ifndef __MMI_MEDIA_PLAYER_FTE__
	#define __MMI_MEDIA_PLAYER_FTE__
	#endif
#endif


#if (defined(__INTEGRATED_PLAYER_FTE__))
	#ifndef __MMI_MEDIA_PLAYER_FTE_PLST_MULTIPLE_STYLE__
	#define __MMI_MEDIA_PLAYER_FTE_PLST_MULTIPLE_STYLE__
	#endif
#endif


#if ((defined(__INTEGRATED_PLAYER_FTE_DB__) || defined(__INTEGRATED_PLAYER_DB__)) && defined(__SQLITE3_SUPPORT__))
	#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
	#define __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
	#endif
#endif


#if defined(CFG_MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT) && ((CFG_MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT == __ON__)||(CFG_MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT == __AUTO__)) && \
	(defined(__VENUS_UI_ENGINE__) && defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__ ) && defined(__MMI_FTE_SUPPORT__ ))
	#ifndef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
	#define __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
	#endif
#endif


#if (defined(__INTEGRATED_PLAYER_DB_VF__) && defined(__SQLITE3_SUPPORT__))
	#ifndef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
	#define __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
	#endif
#endif


#if (defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__))
	#ifndef __MMI_MEDIA_PLAYER_INTRO_PLAY__
	#define __MMI_MEDIA_PLAYER_INTRO_PLAY__
	#endif
#endif


#if defined(CFG_MMI_MEDIA_PLAYER_LYRIC_DISPLAY) && ((CFG_MMI_MEDIA_PLAYER_LYRIC_DISPLAY == __ON__)||(CFG_MMI_MEDIA_PLAYER_LYRIC_DISPLAY == __AUTO__)) && \
	(defined(__MMI_MEDIA_PLAYER_AUDIO__))
	#ifndef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
	#define __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
	#endif
#endif


#if defined(CFG_MMI_MEDIA_PLAYER_PLST_DB_ENHANCE) && ((CFG_MMI_MEDIA_PLAYER_PLST_DB_ENHANCE == __ON__)||(CFG_MMI_MEDIA_PLAYER_PLST_DB_ENHANCE == __AUTO__)) && \
	(defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__ ))
	#ifndef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
	#define __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
	#endif
#endif


#if (defined(__INTEGRATED_PLAYER__))
	#ifndef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
	#define __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
	#endif
#endif


#if (defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__))
	#ifndef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__
	#define __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__
	#endif
#endif


#if (defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__))
	#ifndef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_AUDIO_VIDEO_SPLIT__
	#define __MMI_MEDIA_PLAYER_PLST_MULTIPLE_AUDIO_VIDEO_SPLIT__
	#endif
#endif


#if (defined(MP4_DECODE) && defined(STREAM_SUPPORT))
	#ifndef __MMI_VIDEO_STREAM__
	#define __MMI_VIDEO_STREAM__
	#endif
#endif


#if (defined(__MMI_VIDEO_STREAM__) && defined(__MMI_MEDIA_PLAYER__))
	#ifndef __MMI_MEDIA_PLAYER_STREAM__
	#define __MMI_MEDIA_PLAYER_STREAM__
	#endif
#endif


#if ((defined(MP4_DECODE) || defined(MJPG_SUPPORT) || defined(MJPG_DECODE)) && defined(__MMI_MEDIA_PLAYER__))
	#ifndef __MMI_MEDIA_PLAYER_VIDEO__
	#define __MMI_MEDIA_PLAYER_VIDEO__
	#endif
#endif


#if defined(CFG_MMI_MEGAPHONE_SUPPORT) && ((CFG_MMI_MEGAPHONE_SUPPORT == __ON__)||(CFG_MMI_MEGAPHONE_SUPPORT == __AUTO__))
	#ifndef __MMI_MEGAPHONE_SUPPORT__
	#define __MMI_MEGAPHONE_SUPPORT__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_MESSAGE_APP_SUPPORT__
	#define __MMI_MESSAGE_APP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MESSAGE_MAIN_MENU_HINT_INLINE) && ((CFG_MMI_MESSAGE_MAIN_MENU_HINT_INLINE == __ON__)||(CFG_MMI_MESSAGE_MAIN_MENU_HINT_INLINE == __AUTO__))
	#ifndef __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__
	#define __MMI_MESSAGE_MAIN_MENU_HINT_INLINE__
	#endif
#endif


#if defined(CFG_MMI_MESSAGE_SMS_HILITE_VIEWER) && ((CFG_MMI_MESSAGE_SMS_HILITE_VIEWER == __ON__)||(CFG_MMI_MESSAGE_SMS_HILITE_VIEWER == __AUTO__)) && \
	(!defined(__ULC_SLIM_EMS__))
	#ifndef __MMI_MESSAGE_SMS_HILITE_VIEWER__
	#define __MMI_MESSAGE_SMS_HILITE_VIEWER__
	#endif
#endif


#if (!defined(__MMI_MESSAGE_SMS_HILITE_VIEWER__))
	#ifndef __MMI_MESSAGE_SMS_USE_DETAIL__
	#define __MMI_MESSAGE_SMS_USE_DETAIL__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_CB_DISPLAY_IN_IDLE) && ((CFG_MMI_MESSAGES_CB_DISPLAY_IN_IDLE == __ON__)||(CFG_MMI_MESSAGES_CB_DISPLAY_IN_IDLE == __AUTO__)) && \
	(defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
	#define __MMI_MESSAGES_CB_DISPLAY_IN_IDLE__
	#endif
#endif


#if (defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_CONCAT_SMS__
	#define __MMI_MESSAGES_CONCAT_SMS__
	#endif
#endif


#if (!defined(__MMI_BTD_BOX_UI_STYLE__))
	#ifndef __MMI_MESSAGES_DRAFT_BOX__
	#define __MMI_MESSAGES_DRAFT_BOX__
	#endif
#endif


#if (!defined(__SLIM_EMS__))
	#ifndef __MMI_MESSAGES_EMS__
	#define __MMI_MESSAGES_EMS__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_EMS_REMAINING_COUNTER) && ((CFG_MMI_MESSAGES_EMS_REMAINING_COUNTER == __ON__)||(CFG_MMI_MESSAGES_EMS_REMAINING_COUNTER == __AUTO__)) && \
	(defined(__MMI_MESSAGES_EMS__))
	#ifndef __MMI_MESSAGES_EMS_REMAINING_COUNTER__
	#define __MMI_MESSAGES_EMS_REMAINING_COUNTER__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_LIST_ADVANCED) && ((CFG_MMI_MESSAGES_LIST_ADVANCED == __ON__)||(CFG_MMI_MESSAGES_LIST_ADVANCED == __AUTO__)) && \
	(((defined(__MOD_SMSAL__)) && ((defined(__MMI_MESSAGES_COPY__)) && (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)))))
	#ifndef __MMI_MESSAGES_LIST_ADVANCED__
	#define __MMI_MESSAGES_LIST_ADVANCED__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS) && ((CFG_MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS == __ON__)||(CFG_MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS == __AUTO__)) && \
	(defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
	#define __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
	#endif
#endif


#if (defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
	#define __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
	#endif
#endif


#if (defined(__MSG_SMS_EMAIL_SUPPORT__))
	#ifndef __MMI_MESSAGES_SMS_EMAIL__
	#define __MMI_MESSAGES_SMS_EMAIL__
	#endif
#endif


#if defined(CFG_MMI_MESSAGES_TWO_CB_MODES_DISPLAY) && ((CFG_MMI_MESSAGES_TWO_CB_MODES_DISPLAY == __ON__)||(CFG_MMI_MESSAGES_TWO_CB_MODES_DISPLAY == __AUTO__)) && \
	(defined(__MOD_SMSAL__))
	#ifndef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
	#define __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
	#endif
#endif


#if (defined(__MOD_SMSAL__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MESSAGES_USE_URL__
	#define __MMI_MESSAGES_USE_URL__
	#endif
#endif


#if defined(CFG_MMI_MExE_SUPPORT) && ((CFG_MMI_MExE_SUPPORT == __ON__)||(CFG_MMI_MExE_SUPPORT == __AUTO__))
	#ifndef __MMI_MExE_SUPPORT__
	#define __MMI_MExE_SUPPORT__
	#endif
#endif


#if (defined(__MMI_IME_MIXED_LANG_SUPPORT__))
	#ifndef __MMI_MIXED_LANG_SUPPORT__
	#define __MMI_MIXED_LANG_SUPPORT__
	#endif
#endif


#if (defined(MMS_SUPPORT))
	#ifndef __MMI_MMS__
	#define __MMI_MMS__
	#endif
#endif


#if defined(CFG_MMI_MMS_BEST_PAGE_SUPPORT) && ((CFG_MMI_MMS_BEST_PAGE_SUPPORT == __ON__)||(CFG_MMI_MMS_BEST_PAGE_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MMS_2__))
	#ifndef __MMI_MMS_BEST_PAGE_SUPPORT__
	#define __MMI_MMS_BEST_PAGE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_BGSR_CANCEL_PROHIBIT) && ((CFG_MMI_MMS_BGSR_CANCEL_PROHIBIT == __ON__)||(CFG_MMI_MMS_BGSR_CANCEL_PROHIBIT == __AUTO__)) && \
	(defined(__MMI_MMS_BGSR_SUPPORT__))
	#ifndef __MMI_MMS_BGSR_CANCEL_PROHIBIT__
	#define __MMI_MMS_BGSR_CANCEL_PROHIBIT__
	#endif
#endif


#if (defined(__SLIM_MMS__))
	#ifndef __MMI_SLIM_MMS_2__
	#define __MMI_SLIM_MMS_2__
	#endif
#endif


#if (defined(__MMI_DUAL_SIM__) && defined(MMS_SUPPORT))
	#ifndef __MMI_MMS_DUAL_SIM__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS) && ((CFG_MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS == __ON__)||(CFG_MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS == __AUTO__)) && \
	(defined(MMS_SUPPORT) &&  defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && !defined(__MMI_MMS_DUAL_SIM__))
	#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
	#define __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
	#endif
#endif


#if defined(CFG_MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT) && ((CFG_MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT == __ON__)||(CFG_MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT == __AUTO__)) && \
	(defined(__MMI_UNIFIED_COMPOSER__) && !defined(__MMI_SLIM_MMS_2__))
	#ifndef __MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__
	#define __MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__
	#endif
#endif


#if (defined(__MMI_UM_CONVERSATION_BOX__))
	#ifndef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
	#define __MMI_MMS_CONVERSATION_BOX_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_2__ ) && defined(__COSMOS_MMI_PACKAGE__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
	#ifndef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
	#define __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
	#endif
#endif


#if (defined(__CBM_BEARER_FALLBACK__) && defined(__MMI_MMS_BGSR_SUPPORT__) && (defined(OBIGO_Q05A) || defined(OBIGO_Q03C_MMS_V02)))
	#ifndef __MMI_MMS_FALLBACK__
	#define __MMI_MMS_FALLBACK__
	#endif
#endif


#if (defined(OBIGO_Q03C_MMS_V02) && defined(__LOW_TIER_SLIM_MMS__))
	#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	#define __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_FOR_6261_SLIM) && ((CFG_MMI_MMS_FOR_6261_SLIM == __ON__)||(CFG_MMI_MMS_FOR_6261_SLIM == __AUTO__)) && \
	(defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
	#ifndef __MMI_MMS_FOR_6261_SLIM__
	#define __MMI_MMS_FOR_6261_SLIM__
	#endif
#endif


#if defined(CFG_MMI_MMS_IMAGE_VIEW_ENHANCEMENT) && ((CFG_MMI_MMS_IMAGE_VIEW_ENHANCEMENT == __ON__)||(CFG_MMI_MMS_IMAGE_VIEW_ENHANCEMENT == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !(defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__) && !defined(__MMI_FTE_SUPPORT__)))
	#ifndef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
	#define __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
	#endif
#endif


#if defined(CFG_MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM) && ((CFG_MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM == __ON__)||(CFG_MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM == __AUTO__)) && \
	(defined(MMS_SUPPORT) && defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__))
	#ifndef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
	#define __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
	#endif
#endif


#if defined(CFG_MMI_MMS_IOT_TEST_SUPPORT) && ((CFG_MMI_MMS_IOT_TEST_SUPPORT == __ON__)||(CFG_MMI_MMS_IOT_TEST_SUPPORT == __AUTO__))
	#ifndef __MMI_MMS_IOT_TEST_SUPPORT__
	#define __MMI_MMS_IOT_TEST_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_UM_ITERATOR_VIEWER) && ((CFG_MMI_UM_ITERATOR_VIEWER == __ON__)||(CFG_MMI_UM_ITERATOR_VIEWER == __AUTO__))
	#if (defined(__COSMOS_MMI_PACKAGE__))
	#error "etting conflicts, please turn off CFG_MMI_UM_ITERATOR_VIEWER in COSMOS project"
	#endif
	#ifndef __MMI_UM_ITERATOR_VIEWER__
	#define __MMI_UM_ITERATOR_VIEWER__
	#endif
#endif


#if (defined(__MMI_UM_ITERATOR_VIEWER__))
	#ifndef __MMI_MMS_ITERATOR_VIEWER__
	#define __MMI_MMS_ITERATOR_VIEWER__
	#endif
#endif


#if defined(CFG_MMI_MMS_LOW_TIER_BGSR_SUPPORT) && ((CFG_MMI_MMS_LOW_TIER_BGSR_SUPPORT == __ON__)||(CFG_MMI_MMS_LOW_TIER_BGSR_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
	#ifndef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
	#define __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_LT_NO_ATTACHMENT_SUPPORT) && ((CFG_MMI_MMS_LT_NO_ATTACHMENT_SUPPORT == __ON__)||(CFG_MMI_MMS_LT_NO_ATTACHMENT_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
	#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
	#define __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_LT_NO_AUDIO_SUPPORT) && ((CFG_MMI_MMS_LT_NO_AUDIO_SUPPORT == __ON__)||(CFG_MMI_MMS_LT_NO_AUDIO_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__))
	#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
	#define __MMI_MMS_LT_NO_AUDIO_SUPPORT__
	#endif
#endif


#if (defined(CFG_MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION)) &&\
	 (defined(MMS_SUPPORT))
	#ifndef __MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__
	#define __MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__	CFG_MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION
	#endif
#endif


#if (defined(__MMS_MEMORY_CARD_STORAGE_SUPPORT__) && defined(__MMI_MMS_2__) && defined(__FS_CARD_SUPPORT__))
	#ifndef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	#define __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_MMA_DRM_ENCODING) && ((CFG_MMI_MMS_MMA_DRM_ENCODING == __ON__)||(CFG_MMI_MMS_MMA_DRM_ENCODING == __AUTO__)) && \
	(defined(MMS_SUPPORT) && defined(__MMI_MMS_2__) && defined(__MMI_MMS_BGSR_SUPPORT__) && defined(__DRM_SUPPORT__) && !defined(__MMI_SLIM_MMS_2__))
	#ifndef __MMI_MMS_MMA_DRM_ENCODING__
	#define __MMI_MMS_MMA_DRM_ENCODING__
	#endif
#endif


#if (defined(__MMI_MMS_2__))
	#ifndef __MMI_MMS_MMA_MMS_OBJECT_IND__
	#define __MMI_MMS_MMA_MMS_OBJECT_IND__
	#endif
#endif


#if (defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && defined(__MMI_SMS_TCARD_STORAGE_SUPPORT__))
	#ifndef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
	#define __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_FOR_6261_SLIM__))
	#ifndef __MMI_MMS_NO_REPORT_SUPPORT__
	#define __MMI_MMS_NO_REPORT_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_FOR_6261_SLIM__))
	#ifndef __MMI_MMS_NO_SMIL_SUPPORT__
	#define __MMI_MMS_NO_SMIL_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG) && ((CFG_MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG == __ON__)||(CFG_MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG == __AUTO__)) && \
	(defined(MMS_SUPPORT) && defined(__MMI_MMS_2__) && defined(__MMI_MMS_BGSR_SUPPORT__) && !defined(__MMI_SLIM_MMS_2__))
	#ifndef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
	#define __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
	#endif
#endif


#if defined(CFG_MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT) && ((CFG_MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT == __ON__)||(CFG_MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT == __AUTO__)) && \
	(defined(MMS_SUPPORT))
	#ifndef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
	#define __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_FOR_6261_SLIM__) && defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__))
	#ifndef __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
	#define __MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__
	#endif
#endif


#if (defined(OBIGO_Q03C_MMS_V02) && defined(__MMI_MMS_POSTCARD__))
	#ifndef __MMI_MMS_POSTCARD_WITH_OUT_SMIL__
	#define __MMI_MMS_POSTCARD_WITH_OUT_SMIL__
	#endif
#endif


#if (defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_MMS_PREVIEW_GOTO__
	#define __MMI_MMS_PREVIEW_GOTO__
	#endif
#endif


#if (defined(__MMI_UM_REPORT_BOX__))
	#ifndef __MMI_MMS_REPORT_BOX_SUPPORT__
	#define __MMI_MMS_REPORT_BOX_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_2__) && (defined(__MMI_UM_REPORT_STATUS_IN_SENT_BOX__) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
	#define __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MMS_2__) && (defined(__MMI_UM_REPORT_BOX__) || (defined(__COSMOS_MMI_PACKAGE__) && !defined(__LOW_COST_SUPPORT_COMMON__))))
	#ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
	#define __MMI_MMS_REPORT_STATUS_SUPPORT__
	#endif
#endif


#if (defined(CFG_MMI_MMS_SETTING_SEL))
	#ifndef __MMI_MMS_SETTING_SEL__
	#define __MMI_MMS_SETTING_SEL__	CFG_MMI_MMS_SETTING_SEL
	#endif
#endif


#if (defined(__MMI_MMS_SETTING_SEL__) && (( __MMI_MMS_SETTING_SEL__ == MMS_SETTING_FULL)  ||     ((__MMI_MMS_SETTING_SEL__ == MMS_SETTING_AUTO) &&  !defined(__MMI_MESSAGE_SLIM__))))
	#ifndef __MMI_MMS_SETTING__
	#define __MMI_MMS_SETTING__	MMS_SETTING_FULL
	#endif
#elif (defined(__MMI_MMS_SETTING_SEL__) && ((__MMI_MMS_SETTING_SEL__ == MMS_SETTING_OMA_ONLY) ||     ((__MMI_MMS_SETTING_SEL__ == MMS_SETTING_AUTO) && defined(__MMI_MESSAGE_SLIM__))))
	#ifndef __MMI_MMS_SETTING__
	#define __MMI_MMS_SETTING__	MMS_SETTING_OMA_ONLY
	#endif
#else
	#ifndef __MMI_MMS_SETTING__
	#define __MMI_MMS_SETTING__	MMS_SETTING_NONE
	#endif
#endif


#if defined(CFG_MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY) && ((CFG_MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY == __ON__)||(CFG_MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY == __AUTO__)) && \
	(defined( __MMI_MMS_2__))
	#ifndef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
	#define __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
	#endif
#endif


#if (defined(__MMI_MMS_2__) && !defined(__LOW_TIER_SLIM_MMS__))
	#ifndef __MMI_MMS_SIGNATURE__
	#define __MMI_MMS_SIGNATURE__
	#endif
#endif


#if (defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
	#ifndef __MMI_MMS_STANDALONE_COMPOSER__
	#define __MMI_MMS_STANDALONE_COMPOSER__
	#endif
#endif


#if defined(CFG_MMI_MMS_SWITCH_MSG_READ_STATUS) && ((CFG_MMI_MMS_SWITCH_MSG_READ_STATUS == __ON__)||(CFG_MMI_MMS_SWITCH_MSG_READ_STATUS == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && defined(__MMI_MMS_IN_UM__))
	#ifndef __MMI_MMS_SWITCH_MSG_READ_STATUS__
	#define __MMI_MMS_SWITCH_MSG_READ_STATUS__
	#endif
#endif


#if (defined(MMS_SUPPORT))
	#ifndef __MMI_MMS_TEMPLATES_NUM__
	#define __MMI_MMS_TEMPLATES_NUM__	5
	#endif
#endif


#if defined(CFG_MMI_MMS_UMMS_AUDIO_FEATURE) && ((CFG_MMI_MMS_UMMS_AUDIO_FEATURE == __ON__)||(CFG_MMI_MMS_UMMS_AUDIO_FEATURE == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_MMS_UMMS_AUDIO_FEATURE__
	#define __MMI_MMS_UMMS_AUDIO_FEATURE__
	#endif
#endif


#if defined(CFG_MMI_MMS_UMMS_IMAGE_FEATURE) && ((CFG_MMI_MMS_UMMS_IMAGE_FEATURE == __ON__)||(CFG_MMI_MMS_UMMS_IMAGE_FEATURE == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_MMS_UMMS_IMAGE_FEATURE__
	#define __MMI_MMS_UMMS_IMAGE_FEATURE__
	#endif
#endif


#if (defined(MMS_SUPPORT) && (defined(MP4_DECODE) || defined(__RM_DEC_SUPPORT__) || defined(MJPG_DECODE) && !defined(__DIRECT_SENSOR_SUPPORT__)))
	#ifndef __MMI_MMS_VIDEO_FEATURE__
	#define __MMI_MMS_VIDEO_FEATURE__
	#endif
#endif


#if defined(CFG_MMI_MMS_UMMS_VIDEO_FEATURE) && ((CFG_MMI_MMS_UMMS_VIDEO_FEATURE == __ON__)||(CFG_MMI_MMS_UMMS_VIDEO_FEATURE == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && defined(__MMI_MMS_VIDEO_FEATURE__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_MMS_UMMS_VIDEO_FEATURE__
	#define __MMI_MMS_UMMS_VIDEO_FEATURE__
	#endif
#endif


#if defined(CFG_MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT) && ((CFG_MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT == __ON__)||(CFG_MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
	#define __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
	#endif
#endif


#if (defined(WAP_SUPPORT) && !(defined(LOW_COST_SUPPORT ) && !defined(STREAM_SUPPORT )))
	#ifndef __MMI_URI_AGENT__
	#define __MMI_URI_AGENT__
	#endif
#endif


#if (defined(__MMI_MMS_2__) && defined(__MMI_URI_AGENT__) && !(defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__)))
	#ifndef __MMI_MMS_URI_AGENT__
	#define __MMI_MMS_URI_AGENT__
	#endif
#endif


#if ((defined(__MMI_SLIM_MMS_2__) || (defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__))) && defined (OBIGO_Q03C_MMS_V02))
	#ifndef __MMI_MMS_USE_ASM__
	#define __MMI_MMS_USE_ASM__
	#endif
#endif


#if (defined(__DISABLE_SANDBOX_LIB__))
	#ifndef __MMI_MRE_DISABLE_FMGR__
	#define __MMI_MRE_DISABLE_FMGR__
	#endif
#endif


#if (((defined(__MRE_PACKAGE_FULL__)||defined(__MRE_PACKAGE_NORMAL__)||defined(__MRE_PACKAGE_SLIM__)) && defined(__MMI_MMS__) && !defined(__MMI_MRE_DISABLE_FMGR__)))
	#if (!defined(__XML_SUPPORT__))
	#error "Setting conflict, __MMI_MMS_VENDOR_APP_SUPPORT__ require enable of __XML_SUPPORT__"
	#endif
	#ifndef __MMI_MMS_VENDOR_APP_SUPPORT__
	#define __MMI_MMS_VENDOR_APP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT) && ((CFG_MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT == __ON__)||(CFG_MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__) && !defined(__MMI_MMS_DUAL_SIM__))
	#ifndef __MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__
	#define __MMI_MMS_WAP_CONNECTION_MAX_SIZE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MMS2_MV_MANUAL_PLAY) && ((CFG_MMI_MMS2_MV_MANUAL_PLAY == __ON__)||(CFG_MMI_MMS2_MV_MANUAL_PLAY == __AUTO__)) && \
	(defined(__MMI_MMS_2__ )) || (defined(__MMI_FTE_SUPPORT__ ))
	#ifndef __MMI_MMS2_MV_MANUAL_PLAY__
	#define __MMI_MMS2_MV_MANUAL_PLAY__
	#endif
#endif


#if (defined(__MOBILE_VIDEO_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_MOBILE_VIDEO__
	#define __MMI_MOBILE_VIDEO__
	#endif
#endif


#if (defined(__MOT_SUPPORT__) && (defined(MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__)))
	#ifndef __MMI_MOT_SUPPORT__
	#define __MMI_MOT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MRE_3RD_ROM_PRELOAD) && ((CFG_MMI_MRE_3RD_ROM_PRELOAD == __ON__)||(CFG_MMI_MRE_3RD_ROM_PRELOAD == __AUTO__)) && \
	(defined(__NFB_THIRD_ROM_SUPPORT__))
	#ifndef __MMI_MRE_3RD_ROM_PRELOAD__
	#define __MMI_MRE_3RD_ROM_PRELOAD__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS) && ((CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (!defined(MOTION_SENSOR_SUPPORT))
	#error "setting conflicts, please define MOTION_SENSOR_SUPPORT or turn off CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS"
	#endif
	#ifndef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
	#define __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT) && ((CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (!defined(MOTION_SENSOR_SUPPORT))
	#error "setting conflicts, please define MOTION_SENSOR_SUPPORT or turn off CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT"
	#endif
	#ifndef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
	#define __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG) && ((CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (!defined(MOTION_SENSOR_SUPPORT))
	#error "setting conflicts, please define MOTION_SENSOR_SUPPORT or turn off CFG_MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG"
	#endif
	#ifndef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
	#define __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_BOWLING_CHS) && ((CFG_MMI_MRE_APP_3GT_GAME_BOWLING_CHS == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_BOWLING_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
	#define __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_BOWLING_CHT) && ((CFG_MMI_MRE_APP_3GT_GAME_BOWLING_CHT == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_BOWLING_CHT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
	#define __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_BOWLING_ENG) && ((CFG_MMI_MRE_APP_3GT_GAME_BOWLING_ENG == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_BOWLING_ENG == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
	#define __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_DANDELION) && ((CFG_MMI_MRE_APP_3GT_GAME_DANDELION == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_DANDELION == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_DANDELION__
	#define __MMI_MRE_APP_3GT_GAME_DANDELION__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS) && ((CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
	#define __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT) && ((CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
	#define __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG) && ((CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG == __ON__)||(CFG_MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
	#define __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_ANGRYBIRDS_EN) && ((CFG_MMI_MRE_APP_ANGRYBIRDS_EN == __ON__)||(CFG_MMI_MRE_APP_ANGRYBIRDS_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_ANGRYBIRDS_EN__
	#define __MMI_MRE_APP_ANGRYBIRDS_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_ANGRYBIRDS_SC) && ((CFG_MMI_MRE_APP_ANGRYBIRDS_SC == __ON__)||(CFG_MMI_MRE_APP_ANGRYBIRDS_SC == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_ANGRYBIRDS_SC__
	#define __MMI_MRE_APP_ANGRYBIRDS_SC__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_CALCULATOR) && ((CFG_MMI_MRE_APP_CALCULATOR == __ON__)||(CFG_MMI_MRE_APP_CALCULATOR == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_CALCULATOR__
	#define __MMI_MRE_APP_CALCULATOR__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_CALCULATOR_SHORTCUT) && ((CFG_MMI_MRE_APP_CALCULATOR_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_CALCULATOR_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_APP_CALCULATOR__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_CALCULATOR_SHORTCUT__
	#define __MMI_MRE_APP_CALCULATOR_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_CONVERTER) && ((CFG_MMI_MRE_APP_CONVERTER == __ON__)||(CFG_MMI_MRE_APP_CONVERTER == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_CONVERTER__
	#define __MMI_MRE_APP_CONVERTER__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_CONVERTER_SHORTCUT) && ((CFG_MMI_MRE_APP_CONVERTER_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_CONVERTER_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_APP_CONVERTER__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_CONVERTER_SHORTCUT__
	#define __MMI_MRE_APP_CONVERTER_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FACEBOOK_V2) && ((CFG_MMI_MRE_APP_FACEBOOK_V2 == __ON__)||(CFG_MMI_MRE_APP_FACEBOOK_V2 == __AUTO__)) && \
	(defined(__FACEBOOK_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_FACEBOOK_V2__
	#define __MMI_MRE_APP_FACEBOOK_V2__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FACEBOOK_V2_SHORTCUT) && ((CFG_MMI_MRE_APP_FACEBOOK_V2_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_FACEBOOK_V2_SHORTCUT == __AUTO__)) && \
	(defined(__FACEBOOK_CONTENT_SUPPORT__))
	#if (defined(__MMI_MRE_APP_FACEBOOK_V2__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__
	#define __MMI_MRE_APP_FACEBOOK_V2_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FACEBOOK_V2_STANDARD) && ((CFG_MMI_MRE_APP_FACEBOOK_V2_STANDARD == __ON__)||(CFG_MMI_MRE_APP_FACEBOOK_V2_STANDARD == __AUTO__)) && \
	(defined(__FACEBOOK_CONTENT_SUPPORT__) && (!defined(__MMI_MRE_APP_FACEBOOK_V2__)))
	#ifndef __MMI_MRE_APP_FACEBOOK_V2_STANDARD__
	#define __MMI_MRE_APP_FACEBOOK_V2_STANDARD__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT) && ((CFG_MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT == __AUTO__)) && \
	(defined(__FACEBOOK_CONTENT_SUPPORT__) && (!defined(__MMI_MRE_APP_FACEBOOK_V2__)))
	#ifndef __MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__
	#define __MMI_MRE_APP_FACEBOOK_V2_STANDARD_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FBLITEV11) && ((CFG_MMI_MRE_APP_FBLITEV11 == __ON__)||(CFG_MMI_MRE_APP_FBLITEV11 == __AUTO__)) && \
	(defined(__FACEBOOK_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_FBLITEV11__
	#define __MMI_MRE_APP_FBLITEV11__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FBLITE) && ((CFG_MMI_MRE_APP_FBLITE == __ON__)||(CFG_MMI_MRE_APP_FBLITE == __AUTO__)) && \
	(defined(__FACEBOOK_CONTENT_SUPPORT__) && (!defined(__MMI_MRE_APP_FBLITEV11__)))
	#ifndef __MMI_MRE_APP_FBLITE__
	#define __MMI_MRE_APP_FBLITE__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FISHINGFUN_EN) && ((CFG_MMI_MRE_APP_FISHINGFUN_EN == __ON__)||(CFG_MMI_MRE_APP_FISHINGFUN_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_FISHINGFUN_EN__
	#define __MMI_MRE_APP_FISHINGFUN_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FISHINGFUN_SC) && ((CFG_MMI_MRE_APP_FISHINGFUN_SC == __ON__)||(CFG_MMI_MRE_APP_FISHINGFUN_SC == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_FISHINGFUN_SC__
	#define __MMI_MRE_APP_FISHINGFUN_SC__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FRUITNINJA_EN) && ((CFG_MMI_MRE_APP_FRUITNINJA_EN == __ON__)||(CFG_MMI_MRE_APP_FRUITNINJA_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_FRUITNINJA_EN__
	#define __MMI_MRE_APP_FRUITNINJA_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_FRUITNINJA_SC) && ((CFG_MMI_MRE_APP_FRUITNINJA_SC == __ON__)||(CFG_MMI_MRE_APP_FRUITNINJA_SC == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_FRUITNINJA_SC__
	#define __MMI_MRE_APP_FRUITNINJA_SC__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_2ND_PACKAGE) && ((CFG_MMI_MRE_APP_GAMELOFT_2ND_PACKAGE == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_2ND_PACKAGE == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	#define __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_AC_SHORTCUT) && ((CFG_MMI_MRE_APP_GAMELOFT_AC_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_AC_SHORTCUT == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_AC_SHORTCUT__
	#define __MMI_MRE_APP_GAMELOFT_AC_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250) && ((CFG_MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && defined(__MMI_MAINLCD_320X480__) && defined(MT6250))
	#ifndef __MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__
	#define __MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250) && ((CFG_MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && defined(__MMI_MAINLCD_320X480__) && defined(MT6250))
	#ifndef __MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__
	#define __MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT) && ((CFG_MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT__
	#define __MMI_MRE_APP_GAMELOFT_AS6_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_BB_SHORTCUT) && ((CFG_MMI_MRE_APP_GAMELOFT_BB_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_BB_SHORTCUT == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_BB_SHORTCUT__
	#define __MMI_MRE_APP_GAMELOFT_BB_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_BC_SHORTCUT) && ((CFG_MMI_MRE_APP_GAMELOFT_BC_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_BC_SHORTCUT == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_BC_SHORTCUT__
	#define __MMI_MRE_APP_GAMELOFT_BC_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE1) && ((CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE1 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE1 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__
	#define __MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE2) && ((CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE2 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE2 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__
	#define __MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE3) && ((CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE3 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE3 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__
	#define __MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE4) && ((CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE4 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_CN_PACKAGE4 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__
	#define __MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE1) && ((CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE1 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE1 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__
	#define __MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE2) && ((CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE2 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE2 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__
	#define __MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE3) && ((CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE3 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE3 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__
	#define __MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE4) && ((CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE4 == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_GB_PACKAGE4 == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__
	#define __MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT) && ((CFG_MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT__
	#define __MMI_MRE_APP_GAMELOFT_LIVE_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT) && ((CFG_MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT == __AUTO__)) && \
	(defined(__GAMELOFT_CONTENT_SUPPORT__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT__
	#define __MMI_MRE_APP_GAMELOFT_MC2_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT) && ((CFG_MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT == __AUTO__))
	#ifndef __MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT__
	#define __MMI_MRE_APP_GMOBI_APPSTORE_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_HEALTH) && ((CFG_MMI_MRE_APP_HEALTH == __ON__)||(CFG_MMI_MRE_APP_HEALTH == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_HEALTH__
	#define __MMI_MRE_APP_HEALTH__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_HEALTH_SHORTCUT) && ((CFG_MMI_MRE_APP_HEALTH_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_HEALTH_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_APP_HEALTH__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_HEALTH_SHORTCUT__
	#define __MMI_MRE_APP_HEALTH_SHORTCUT__
	#endif
#endif


#if (defined(CFG_MMI_MRE_APP_IBINGO_UISTORE)) &&\
	 ((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_MRE_APP_IBINGO_UISTORE__
	#define __MMI_MRE_APP_IBINGO_UISTORE__	CFG_MMI_MRE_APP_IBINGO_UISTORE
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_KAIXIN) && ((CFG_MMI_MRE_APP_KAIXIN == __ON__)||(CFG_MMI_MRE_APP_KAIXIN == __AUTO__)) && \
	(!defined(__MRE_PACKAGE_SLIM__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_KAIXIN__
	#define __MMI_MRE_APP_KAIXIN__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT) && ((CFG_MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT == __AUTO__))
	#ifndef __MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT__
	#define __MMI_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT) && ((CFG_MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT == __AUTO__))
	#ifndef __MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT__
	#define __MMI_MRE_APP_MOBIM_APPSTORE_SHORTCUT__
	#endif
#endif


#if (defined(CFG_MMI_MRE_APP_MOBIM_FCWR)) &&\
	 (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_MOBIM_FCWR__
	#define __MMI_MRE_APP_MOBIM_FCWR__	CFG_MMI_MRE_APP_MOBIM_FCWR
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT) && ((CFG_MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
	#ifndef __MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT__
	#define __MMI_MRE_APP_MOMAGIC_APPSTORE_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_OPERA) && ((CFG_MMI_MRE_APP_OPERA == __ON__)||(CFG_MMI_MRE_APP_OPERA == __AUTO__))
	#ifndef __MMI_MRE_APP_OPERA__
	#define __MMI_MRE_APP_OPERA__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_OPERA_MINI_V6) && ((CFG_MMI_MRE_APP_OPERA_MINI_V6 == __ON__)||(CFG_MMI_MRE_APP_OPERA_MINI_V6 == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X320__) || defined(__MMI_MAINLCD_480X640__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_OPERA_MINI_V6__
	#define __MMI_MRE_APP_OPERA_MINI_V6__
	#endif
#endif


#if (defined(CFG_MMI_MRE_APP_SINA_WEIBO)) &&\
	 (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_SINA_WEIBO__
	#define __MMI_MRE_APP_SINA_WEIBO__	CFG_MMI_MRE_APP_SINA_WEIBO
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_STOPWATCH) && ((CFG_MMI_MRE_APP_STOPWATCH == __ON__)||(CFG_MMI_MRE_APP_STOPWATCH == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_STOPWATCH__
	#define __MMI_MRE_APP_STOPWATCH__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_STOPWATCH_SHORTCUT) && ((CFG_MMI_MRE_APP_STOPWATCH_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_STOPWATCH_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_APP_STOPWATCH__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_STOPWATCH_SHORTCUT__
	#define __MMI_MRE_APP_STOPWATCH_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_TWITTER) && ((CFG_MMI_MRE_APP_TWITTER == __ON__)||(CFG_MMI_MRE_APP_TWITTER == __AUTO__)) && \
	(defined(__TWITTER_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_TWITTER__
	#define __MMI_MRE_APP_TWITTER__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_TWITTER_SHORTCUT) && ((CFG_MMI_MRE_APP_TWITTER_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_TWITTER_SHORTCUT == __AUTO__)) && \
	(defined(__TWITTER_CONTENT_SUPPORT__))
	#if (defined(__MMI_MRE_APP_TWITTER__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_TWITTER_SHORTCUT__
	#define __MMI_MRE_APP_TWITTER_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_TWITTER_KEY_SUPPORT) && ((CFG_MMI_MRE_APP_TWITTER_KEY_SUPPORT == __ON__)||(CFG_MMI_MRE_APP_TWITTER_KEY_SUPPORT == __AUTO__)) && \
	(defined(__MMI_MRE_APP_TWITTER__) || defined (__MMI_MRE_APP_TWITTER_SHORTCUT__))
	#ifndef __MMI_MRE_APP_TWITTER_KEY_SUPPORT__
	#define __MMI_MRE_APP_TWITTER_KEY_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_WOCHACHA) && ((CFG_MMI_MRE_APP_WOCHACHA == __ON__)||(CFG_MMI_MRE_APP_WOCHACHA == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_WOCHACHA__
	#define __MMI_MRE_APP_WOCHACHA__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOCRICKET) && ((CFG_MMI_MRE_APP_YAHOOCRICKET == __ON__)||(CFG_MMI_MRE_APP_YAHOOCRICKET == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#if (!defined(PNG_DECODE))
	#error "Yahoo Cricket application cannot execute without PNG_DECODE"
	#endif
	#ifndef __MMI_MRE_APP_YAHOOCRICKET__
	#define __MMI_MRE_APP_YAHOOCRICKET__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOCRICKET_SHORTCUT) && ((CFG_MMI_MRE_APP_YAHOOCRICKET_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_YAHOOCRICKET_SHORTCUT == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#if (defined(__MRE_PACKAGE_SLIM__) || !defined(PNG_DECODE) || defined(__MMI_MRE_APP_YAHOOCRICKET__))
	#error "Yahoo Cricket application cannot execute without PNG_DECODE or HTTP(HTTP is not supported in MRE SLIM package) or setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__
	#define __MMI_MRE_APP_YAHOOCRICKET_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOFINANCE) && ((CFG_MMI_MRE_APP_YAHOOFINANCE == __ON__)||(CFG_MMI_MRE_APP_YAHOOFINANCE == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_YAHOOFINANCE__
	#define __MMI_MRE_APP_YAHOOFINANCE__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOFINANCE_SHORTCUT) && ((CFG_MMI_MRE_APP_YAHOOFINANCE_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_YAHOOFINANCE_SHORTCUT == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#if (defined(__MRE_PACKAGE_SLIM__) || defined(__MMI_MRE_APP_YAHOOFINANCE__))
	#error "Yahoo Finance application cannot execute without HTTP, HTTP is not supported in MRE SLIM package or setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__
	#define __MMI_MRE_APP_YAHOOFINANCE_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOMV2) && ((CFG_MMI_MRE_APP_YAHOOMV2 == __ON__)||(CFG_MMI_MRE_APP_YAHOOMV2 == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_YAHOOMV2__
	#define __MMI_MRE_APP_YAHOOMV2__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOMV2_SHORTCUT) && ((CFG_MMI_MRE_APP_YAHOOMV2_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_YAHOOMV2_SHORTCUT == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#if (defined(__MMI_MRE_APP_YAHOOMV2__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_YAHOOMV2_SHORTCUT__
	#define __MMI_MRE_APP_YAHOOMV2_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOONEWS) && ((CFG_MMI_MRE_APP_YAHOONEWS == __ON__)||(CFG_MMI_MRE_APP_YAHOONEWS == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_YAHOONEWS__
	#define __MMI_MRE_APP_YAHOONEWS__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOONEWS_SHORTCUT) && ((CFG_MMI_MRE_APP_YAHOONEWS_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_YAHOONEWS_SHORTCUT == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#if (defined(__MRE_PACKAGE_SLIM__) || defined(__MMI_MRE_APP_YAHOONEWS__))
	#error "ahoo News application cannot execute without HTTP, HTTP is not supported in MRE SLIM package or setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_YAHOONEWS_SHORTCUT__
	#define __MMI_MRE_APP_YAHOONEWS_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOWEATHER) && ((CFG_MMI_MRE_APP_YAHOOWEATHER == __ON__)||(CFG_MMI_MRE_APP_YAHOOWEATHER == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#ifndef __MMI_MRE_APP_YAHOOWEATHER__
	#define __MMI_MRE_APP_YAHOOWEATHER__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YAHOOWEATHER_SHORTCUT) && ((CFG_MMI_MRE_APP_YAHOOWEATHER_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_YAHOOWEATHER_SHORTCUT == __AUTO__)) && \
	(defined(__YAHOO_CONTENT_SUPPORT__))
	#if (defined(__MRE_PACKAGE_SLIM__) || defined(__MMI_MRE_APP_YAHOOWEATHER__))
	#error "Yahoo Weather application cannot execute without HTTP, HTTP is not supported in MRE SLIM package or setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__
	#define __MMI_MRE_APP_YAHOOWEATHER_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YOUKU) && ((CFG_MMI_MRE_APP_YOUKU == __ON__)||(CFG_MMI_MRE_APP_YOUKU == __AUTO__)) && \
	(!defined(__MRE_PACKAGE_SLIM__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_MRE_APP_YOUKU__
	#define __MMI_MRE_APP_YOUKU__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_YOUTUBE) && ((CFG_MMI_MRE_APP_YOUTUBE == __ON__)||(CFG_MMI_MRE_APP_YOUTUBE == __AUTO__)) && \
	(defined(BROWSER_SUPPORT) && defined(PGDL_SUPPORT_YOUTUBE))
	#ifndef __MMI_MRE_APP_YOUTUBE__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_ZAKAT) && ((CFG_MMI_MRE_APP_ZAKAT == __ON__)||(CFG_MMI_MRE_APP_ZAKAT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_APP_ZAKAT__
	#define __MMI_MRE_APP_ZAKAT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_ZAKAT_SHORTCUT) && ((CFG_MMI_MRE_APP_ZAKAT_SHORTCUT == __ON__)||(CFG_MMI_MRE_APP_ZAKAT_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_APP_ZAKAT__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_APP_ZAKAT_SHORTCUT__
	#define __MMI_MRE_APP_ZAKAT_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_APP_ZY_EBOOK) && ((CFG_MMI_MRE_APP_ZY_EBOOK == __ON__)||(CFG_MMI_MRE_APP_ZY_EBOOK == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (!defined(__MMI_VECTOR_FONT_SUPPORT__))
	#error "FONT_ENGINE should not be setted as NONE in project make file"
	#endif
	#ifndef __MMI_MRE_APP_ZY_EBOOK__
	#define __MMI_MRE_APP_ZY_EBOOK__
	#endif
#endif


#if defined(CFG_MMI_MRE_AUTO_START) && ((CFG_MMI_MRE_AUTO_START == __ON__)||(CFG_MMI_MRE_AUTO_START == __AUTO__))
	#ifndef __MMI_MRE_AUTO_START__
	#define __MMI_MRE_AUTO_START__
	#endif
#endif


#if (defined(__DISABLE_SANDBOX_LIB__))
	#ifndef __MMI_MRE_DISABLE_ALARM__
	#define __MMI_MRE_DISABLE_ALARM__
	#endif
#endif


#if (defined(__DISABLE_SANDBOX_LIB__))
	#ifndef __MMI_MRE_DISABLE_APPCOMM__
	#define __MMI_MRE_DISABLE_APPCOMM__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_EGYPTCODE_CHS) && ((CFG_MMI_MRE_GAME_EGYPTCODE_CHS == __ON__)||(CFG_MMI_MRE_GAME_EGYPTCODE_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_EGYPTCODE_CHS__
	#define __MMI_MRE_GAME_EGYPTCODE_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_EGYPTCODE_EN) && ((CFG_MMI_MRE_GAME_EGYPTCODE_EN == __ON__)||(CFG_MMI_MRE_GAME_EGYPTCODE_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_EGYPTCODE_EN__
	#define __MMI_MRE_GAME_EGYPTCODE_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_EGYPTCODE_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT__
	#define __MMI_MRE_GAME_EGYPTCODE_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_GIRLSLOT_CHS) && ((CFG_MMI_MRE_GAME_GIRLSLOT_CHS == __ON__)||(CFG_MMI_MRE_GAME_GIRLSLOT_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_GIRLSLOT_CHS__
	#define __MMI_MRE_GAME_GIRLSLOT_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_GIRLSLOT_EN) && ((CFG_MMI_MRE_GAME_GIRLSLOT_EN == __ON__)||(CFG_MMI_MRE_GAME_GIRLSLOT_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_GIRLSLOT_EN__
	#define __MMI_MRE_GAME_GIRLSLOT_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_GIRLSLOT_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT__
	#define __MMI_MRE_GAME_GIRLSLOT_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_GOLDMINER_CHS) && ((CFG_MMI_MRE_GAME_GOLDMINER_CHS == __ON__)||(CFG_MMI_MRE_GAME_GOLDMINER_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_GOLDMINER_CHS__
	#define __MMI_MRE_GAME_GOLDMINER_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_GOLDMINER_EN) && ((CFG_MMI_MRE_GAME_GOLDMINER_EN == __ON__)||(CFG_MMI_MRE_GAME_GOLDMINER_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_GOLDMINER_EN__
	#define __MMI_MRE_GAME_GOLDMINER_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_GOLDMINER_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT__
	#define __MMI_MRE_GAME_GOLDMINER_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_HAPPYEGG_CHS) && ((CFG_MMI_MRE_GAME_HAPPYEGG_CHS == __ON__)||(CFG_MMI_MRE_GAME_HAPPYEGG_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_HAPPYEGG_CHS__
	#define __MMI_MRE_GAME_HAPPYEGG_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_HAPPYEGG_EN) && ((CFG_MMI_MRE_GAME_HAPPYEGG_EN == __ON__)||(CFG_MMI_MRE_GAME_HAPPYEGG_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_HAPPYEGG_EN__
	#define __MMI_MRE_GAME_HAPPYEGG_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_HAPPYEGG_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT__
	#define __MMI_MRE_GAME_HAPPYEGG_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_HAPPYWAR_CHS) && ((CFG_MMI_MRE_GAME_HAPPYWAR_CHS == __ON__)||(CFG_MMI_MRE_GAME_HAPPYWAR_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_HAPPYWAR_CHS__
	#define __MMI_MRE_GAME_HAPPYWAR_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_HAPPYWAR_EN) && ((CFG_MMI_MRE_GAME_HAPPYWAR_EN == __ON__)||(CFG_MMI_MRE_GAME_HAPPYWAR_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_HAPPYWAR_EN__
	#define __MMI_MRE_GAME_HAPPYWAR_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_HAPPYWAR_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT__
	#define __MMI_MRE_GAME_HAPPYWAR_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_KINGCOMBAT_CHS) && ((CFG_MMI_MRE_GAME_KINGCOMBAT_CHS == __ON__)||(CFG_MMI_MRE_GAME_KINGCOMBAT_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_KINGCOMBAT_CHS__
	#define __MMI_MRE_GAME_KINGCOMBAT_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_KINGCOMBAT_EN) && ((CFG_MMI_MRE_GAME_KINGCOMBAT_EN == __ON__)||(CFG_MMI_MRE_GAME_KINGCOMBAT_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_KINGCOMBAT_EN__
	#define __MMI_MRE_GAME_KINGCOMBAT_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_KINGCOMBAT_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT__
	#define __MMI_MRE_GAME_KINGCOMBAT_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_MOTO_CHS) && ((CFG_MMI_MRE_GAME_MOTO_CHS == __ON__)||(CFG_MMI_MRE_GAME_MOTO_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_MOTO_CHS__
	#define __MMI_MRE_GAME_MOTO_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_MOTO_EN) && ((CFG_MMI_MRE_GAME_MOTO_EN == __ON__)||(CFG_MMI_MRE_GAME_MOTO_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_MOTO_EN__
	#define __MMI_MRE_GAME_MOTO_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_MOTO_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_MOTO_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_MOTO_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_MOTO_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_MOTO_EN_SHORTCUT__
	#define __MMI_MRE_GAME_MOTO_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_PARKOUR_CHS) && ((CFG_MMI_MRE_GAME_PARKOUR_CHS == __ON__)||(CFG_MMI_MRE_GAME_PARKOUR_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_PARKOUR_CHS__
	#define __MMI_MRE_GAME_PARKOUR_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_PARKOUR_EN) && ((CFG_MMI_MRE_GAME_PARKOUR_EN == __ON__)||(CFG_MMI_MRE_GAME_PARKOUR_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_PARKOUR_EN__
	#define __MMI_MRE_GAME_PARKOUR_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_PARKOUR_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_PARKOUR_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_PARKOUR_EN_SHORTCUT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#if (defined(__MMI_MRE_GAME_PARKOUR_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_PARKOUR_EN_SHORTCUT__
	#define __MMI_MRE_GAME_PARKOUR_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_TEARDRESS_CHS) && ((CFG_MMI_MRE_GAME_TEARDRESS_CHS == __ON__)||(CFG_MMI_MRE_GAME_TEARDRESS_CHS == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_TEARDRESS_CHS__
	#define __MMI_MRE_GAME_TEARDRESS_CHS__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_TEARDRESS_EN) && ((CFG_MMI_MRE_GAME_TEARDRESS_EN == __ON__)||(CFG_MMI_MRE_GAME_TEARDRESS_EN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_GAME_TEARDRESS_EN__
	#define __MMI_MRE_GAME_TEARDRESS_EN__
	#endif
#endif


#if defined(CFG_MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT) && ((CFG_MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT == __ON__)||(CFG_MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT == __AUTO__)) && \
	((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)) && defined(__MMI_TOUCH_SCREEN__))
	#if (defined(__MMI_MRE_GAME_TEARDRESS_EN__))
	#error "setting conflicts, build-in app and build-in app shortcut could not be turned on at the same time"
	#endif
	#ifndef __MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT__
	#define __MMI_MRE_GAME_TEARDRESS_EN_SHORTCUT__
	#endif
#endif


#if defined(CFG_MMI_MRE_MAIN_MENU) && ((CFG_MMI_MRE_MAIN_MENU == __ON__)||(CFG_MMI_MRE_MAIN_MENU == __AUTO__)) && \
	(defined(__MRE_AM__))
	#ifndef __MMI_MRE_MAIN_MENU__
	#define __MMI_MRE_MAIN_MENU__
	#endif
#endif


#if defined(CFG_MMI_MRE_MSPACE) && ((CFG_MMI_MRE_MSPACE == __ON__)||(CFG_MMI_MRE_MSPACE == __AUTO__)) && \
	(!defined(__MMI_MRE_DISABLE_FMGR__))
	#if (defined(__PLUTO_MMI_PACKAGE__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINMENU_SPREAD_SUPPORT__))
	#error "please define __MMI_MAINMENU_SPREAD_SUPPORT__"
	#endif
	#ifndef __MMI_MRE_MSPACE__
	#define __MMI_MRE_MSPACE__
	#endif
#endif


#if defined(CFG_MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT) && ((CFG_MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT == __ON__)||(CFG_MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT == __AUTO__))
	#ifndef __MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT__
	#define __MMI_MRE_NO_POPUP_AUTHENTICATION_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MRE_PREINSTALL_TCARD_PACKAGE) && ((CFG_MMI_MRE_PREINSTALL_TCARD_PACKAGE == __ON__)||(CFG_MMI_MRE_PREINSTALL_TCARD_PACKAGE == __AUTO__))
	#ifndef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
	#define __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
	#endif
#endif


#if defined(CFG_MMI_MRE_SHORTCUT_OPERA) && ((CFG_MMI_MRE_SHORTCUT_OPERA == __ON__)||(CFG_MMI_MRE_SHORTCUT_OPERA == __AUTO__)) && \
	(!defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_SHORTCUT_OPERA__
	#define __MMI_MRE_SHORTCUT_OPERA__
	#endif
#endif


#if defined(CFG_MMI_MRE_SUB_MENU) && ((CFG_MMI_MRE_SUB_MENU == __ON__)||(CFG_MMI_MRE_SUB_MENU == __AUTO__)) && \
	(!defined(__MMI_MRE_MAIN_MENU__) && defined(__MRE_AM__))
	#ifndef __MMI_MRE_SUB_MENU__
	#define __MMI_MRE_SUB_MENU__
	#endif
#endif


#if defined(CFG_MMI_MRE_SUPPORT_UPDATE) && ((CFG_MMI_MRE_SUPPORT_UPDATE == __ON__)||(CFG_MMI_MRE_SUPPORT_UPDATE == __AUTO__)) && \
	(!defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_MRE_SUPPORT_UPDATE__
	#define __MMI_MRE_SUPPORT_UPDATE__
	#endif
#endif


#if defined(CFG_MMI_MSG_EDITOR_WITH_RECIPIENT) && ((CFG_MMI_MSG_EDITOR_WITH_RECIPIENT == __ON__)||(CFG_MMI_MSG_EDITOR_WITH_RECIPIENT == __AUTO__)) && \
	((!defined(__MMI_MESSAGES_SMS_EMAIL__)) && (!defined(__MMI_MMS_POSTCARD__)) && (!defined(__ULC_SLIM_EMS__)) && (!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)))
	#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
	#define __MMI_MSG_EDITOR_WITH_RECIPIENT__
	#endif
#endif


#if defined(CFG_MMI_MSG_FTE_ENHANCE) && ((CFG_MMI_MSG_FTE_ENHANCE == __ON__)||(CFG_MMI_MSG_FTE_ENHANCE == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_SLIM_MMS_2__))
	#ifndef __MMI_MSG_FTE_ENHANCE__
	#define __MMI_MSG_FTE_ENHANCE__
	#endif
#endif


#if (defined(__REL4__) || defined(__REL5__))
	#ifndef __MMI_MSG_REL4_SUPPORT__
	#define __MMI_MSG_REL4_SUPPORT__
	#endif
#endif


#if (defined(__UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__))
	#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
	#define __MMI_MSG_UM_LOW_MEMORY_COST__
	#endif
#endif


#if defined(CFG_MMI_MULTITAP_BANGLA_SPEC) && ((CFG_MMI_MULTITAP_BANGLA_SPEC == __ON__)||(CFG_MMI_MULTITAP_BANGLA_SPEC == __AUTO__)) && \
	(defined(__MMI_LANG_BENGALI__))
	#ifndef __MMI_MULTITAP_BANGLA_SPEC__
	#define __MMI_MULTITAP_BANGLA_SPEC__
	#endif
#endif


#if defined(CFG_MMI_MULTIGRAPH_SUPPORT) && (CFG_MMI_MULTIGRAPH_SUPPORT == __ON__) || \
	((CFG_MMI_MULTIGRAPH_SUPPORT == __AUTO__)|| defined(__MMI_MULTITAP_BANGLA_SPEC__))
	#ifndef __MMI_MULTIGRAPH_SUPPORT__
	#define __MMI_MULTIGRAPH_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_AFRIKAANS__))
	#ifndef __MMI_MULTITAP_AFRIKAANS__
	#define __MMI_MULTITAP_AFRIKAANS__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ALBANIAN__))
	#ifndef __MMI_MULTITAP_ALBANIAN__
	#define __MMI_MULTITAP_ALBANIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ARABIC__))
	#ifndef __MMI_MULTITAP_ARABIC__
	#define __MMI_MULTITAP_ARABIC__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ARMENIAN__))
	#ifndef __MMI_MULTITAP_ARMENIAN__
	#define __MMI_MULTITAP_ARMENIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ASSAMESE__))
	#ifndef __MMI_MULTITAP_ASSAMESE__
	#define __MMI_MULTITAP_ASSAMESE__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_AZERBAIJANI__))
	#ifndef __MMI_MULTITAP_AZERBAIJANI__
	#define __MMI_MULTITAP_AZERBAIJANI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_BASQUE__))
	#ifndef __MMI_MULTITAP_BASQUE__
	#define __MMI_MULTITAP_BASQUE__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_BENGALI__))
	#ifndef __MMI_MULTITAP_BENGALI__
	#define __MMI_MULTITAP_BENGALI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_BULGARIAN__))
	#ifndef __MMI_MULTITAP_BULGARIAN__
	#define __MMI_MULTITAP_BULGARIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_CATALAN__))
	#ifndef __MMI_MULTITAP_CATALAN__
	#define __MMI_MULTITAP_CATALAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_CROATIAN__))
	#ifndef __MMI_MULTITAP_CROATIAN__
	#define __MMI_MULTITAP_CROATIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_CZECH__))
	#ifndef __MMI_MULTITAP_CZECH__
	#define __MMI_MULTITAP_CZECH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_DANISH__))
	#ifndef __MMI_MULTITAP_DANISH__
	#define __MMI_MULTITAP_DANISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_DUTCH__))
	#ifndef __MMI_MULTITAP_DUTCH__
	#define __MMI_MULTITAP_DUTCH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ESTONIAN__))
	#ifndef __MMI_MULTITAP_ESTONIAN__
	#define __MMI_MULTITAP_ESTONIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_FILIPINO__))
	#ifndef __MMI_MULTITAP_FILIPINO__
	#define __MMI_MULTITAP_FILIPINO__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_FINNISH__))
	#ifndef __MMI_MULTITAP_FINNISH__
	#define __MMI_MULTITAP_FINNISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__)))
	#ifndef __MMI_MULTITAP_FRENCH__
	#define __MMI_MULTITAP_FRENCH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_GALICIAN__))
	#ifndef __MMI_MULTITAP_GALICIAN__
	#define __MMI_MULTITAP_GALICIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_GEORGIAN__))
	#ifndef __MMI_MULTITAP_GEORGIAN__
	#define __MMI_MULTITAP_GEORGIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_GERMAN__))
	#ifndef __MMI_MULTITAP_GERMAN__
	#define __MMI_MULTITAP_GERMAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_GREEK__))
	#ifndef __MMI_MULTITAP_GREEK__
	#define __MMI_MULTITAP_GREEK__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_GUJARATI__))
	#ifndef __MMI_MULTITAP_GUJARATI__
	#define __MMI_MULTITAP_GUJARATI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_HAUSA__))
	#ifndef __MMI_MULTITAP_HAUSA__
	#define __MMI_MULTITAP_HAUSA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_HEBREW__))
	#ifndef __MMI_MULTITAP_HEBREW__
	#define __MMI_MULTITAP_HEBREW__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_HINDI__))
	#ifndef __MMI_MULTITAP_HINDI__
	#define __MMI_MULTITAP_HINDI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_HUNGARIAN__))
	#ifndef __MMI_MULTITAP_HUNGARIAN__
	#define __MMI_MULTITAP_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ICELANDIC__))
	#ifndef __MMI_MULTITAP_ICELANDIC__
	#define __MMI_MULTITAP_ICELANDIC__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_IGBO__))
	#ifndef __MMI_MULTITAP_IGBO__
	#define __MMI_MULTITAP_IGBO__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_INDONESIAN__))
	#ifndef __MMI_MULTITAP_INDONESIAN__
	#define __MMI_MULTITAP_INDONESIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_IRISH__))
	#ifndef __MMI_MULTITAP_IRISH__
	#define __MMI_MULTITAP_IRISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ITALIAN__))
	#ifndef __MMI_MULTITAP_ITALIAN__
	#define __MMI_MULTITAP_ITALIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_KANNADA__))
	#ifndef __MMI_MULTITAP_KANNADA__
	#define __MMI_MULTITAP_KANNADA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_KAZAKH__))
	#ifndef __MMI_MULTITAP_KAZAKH__
	#define __MMI_MULTITAP_KAZAKH__
	#endif
#endif


#if defined(CFG_MMI_MULTITAP_KEY_0) && (CFG_MMI_MULTITAP_KEY_0 == __ON__) || \
	(defined(__COSMOS_MMI_PACKAGE__) || (CFG_MMI_MULTITAP_KEY_0 == __AUTO__))
	#ifndef __MMI_MULTITAP_KEY_0__
	#define __MMI_MULTITAP_KEY_0__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_KHMER__))
	#ifndef __MMI_MULTITAP_KHMER__
	#define __MMI_MULTITAP_KHMER__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_LAO__))
	#ifndef __MMI_MULTITAP_LAO__
	#define __MMI_MULTITAP_LAO__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_LATVIAN__))
	#ifndef __MMI_MULTITAP_LATVIAN__
	#define __MMI_MULTITAP_LATVIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_LITHUANIAN__))
	#ifndef __MMI_MULTITAP_LITHUANIAN__
	#define __MMI_MULTITAP_LITHUANIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_MACEDONIAN__))
	#ifndef __MMI_MULTITAP_MACEDONIAN__
	#define __MMI_MULTITAP_MACEDONIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_MALAY__))
	#ifndef __MMI_MULTITAP_MALAY__
	#define __MMI_MULTITAP_MALAY__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_MALAYALAM__))
	#ifndef __MMI_MULTITAP_MALAYALAM__
	#define __MMI_MULTITAP_MALAYALAM__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_MARATHI__))
	#ifndef __MMI_MULTITAP_MARATHI__
	#define __MMI_MULTITAP_MARATHI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_MOLDOVAN__))
	#ifndef __MMI_MULTITAP_MOLDOVAN__
	#define __MMI_MULTITAP_MOLDOVAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_MYANMAR__) || defined(__MMI_LANG_ZAWGYI_MYANMAR__)))
	#ifndef __MMI_MULTITAP_MYANMAR__
	#define __MMI_MULTITAP_MYANMAR__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_NORWEGIAN__))
	#ifndef __MMI_MULTITAP_NORWEGIAN__
	#define __MMI_MULTITAP_NORWEGIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ORIYA__))
	#ifndef __MMI_MULTITAP_ORIYA__
	#define __MMI_MULTITAP_ORIYA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_PERSIAN__))
	#ifndef __MMI_MULTITAP_PERSIAN__
	#define __MMI_MULTITAP_PERSIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_POLISH__))
	#ifndef __MMI_MULTITAP_POLISH__
	#define __MMI_MULTITAP_POLISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__ )))
	#ifndef __MMI_MULTITAP_PORTUGUESE__
	#define __MMI_MULTITAP_PORTUGUESE__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_PUNJABI__))
	#ifndef __MMI_MULTITAP_PUNJABI__
	#define __MMI_MULTITAP_PUNJABI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ROMANIAN__))
	#ifndef __MMI_MULTITAP_ROMANIAN__
	#define __MMI_MULTITAP_ROMANIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_RUSSIAN__))
	#ifndef __MMI_MULTITAP_RUSSIAN__
	#define __MMI_MULTITAP_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_SERBIAN__))
	#ifndef __MMI_MULTITAP_SERBIAN__
	#define __MMI_MULTITAP_SERBIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_SESOTHO__))
	#ifndef __MMI_MULTITAP_SESOTHO__
	#define __MMI_MULTITAP_SESOTHO__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_SLOVAK__))
	#ifndef __MMI_MULTITAP_SLOVAK__
	#define __MMI_MULTITAP_SLOVAK__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_SLOVENIAN__))
	#ifndef __MMI_MULTITAP_SLOVENIAN__
	#define __MMI_MULTITAP_SLOVENIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && (defined(__MMI_LANG_SPANISH__)||defined(__MMI_LANG_SA_SPANISH__)))
	#ifndef __MMI_MULTITAP_SPANISH__
	#define __MMI_MULTITAP_SPANISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_SWAHILI__))
	#ifndef __MMI_MULTITAP_SWAHILI__
	#define __MMI_MULTITAP_SWAHILI__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_SWEDISH__))
	#ifndef __MMI_MULTITAP_SWEDISH__
	#define __MMI_MULTITAP_SWEDISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_TAGALOG__))
	#ifndef __MMI_MULTITAP_TAGALOG__
	#define __MMI_MULTITAP_TAGALOG__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_TAMIL__))
	#ifndef __MMI_MULTITAP_TAMIL__
	#define __MMI_MULTITAP_TAMIL__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_TELUGU__))
	#ifndef __MMI_MULTITAP_TELUGU__
	#define __MMI_MULTITAP_TELUGU__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_TURKISH__))
	#ifndef __MMI_MULTITAP_TURKISH__
	#define __MMI_MULTITAP_TURKISH__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_UKRAINIAN__))
	#ifndef __MMI_MULTITAP_UKRAINIAN__
	#define __MMI_MULTITAP_UKRAINIAN__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_URDU__))
	#ifndef __MMI_MULTITAP_URDU__
	#define __MMI_MULTITAP_URDU__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_VIETNAMESE__))
	#ifndef __MMI_MULTITAP_VIETNAMESE__
	#define __MMI_MULTITAP_VIETNAMESE__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_XHOSA__))
	#ifndef __MMI_MULTITAP_XHOSA__
	#define __MMI_MULTITAP_XHOSA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_YORUBA__))
	#ifndef __MMI_MULTITAP_YORUBA__
	#define __MMI_MULTITAP_YORUBA__
	#endif
#endif


#if (defined(__MMI_MULTITAP__) && defined(__MMI_LANG_ZULU__))
	#ifndef __MMI_MULTITAP_ZULU__
	#define __MMI_MULTITAP_ZULU__
	#endif
#endif


#if defined(CFG_MMI_MUSIC_PLAYER_PHONE_DRIVE) && ((CFG_MMI_MUSIC_PLAYER_PHONE_DRIVE == __ON__)||(CFG_MMI_MUSIC_PLAYER_PHONE_DRIVE == __AUTO__)) && \
	(defined(__COSMOS_MUSICPLY_SLIM__) && defined(__PLAYLIST_SERVICE_SLIM__) && !defined(__COSMOS_NO_USER_DRIVE__))
	#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
	#define __MMI_MUSIC_PLAYER_PHONE_DRIVE__
	#endif
#endif


#if (defined(__COSMOS_MUSICPLY_SLIM__) && defined(__PLAYLIST_SERVICE_SLIM__))
	#ifndef __MMI_MUSIC_PLAYER_SLIM__
	#define __MMI_MUSIC_PLAYER_SLIM__
	#endif
#endif


#if defined(CFG_MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT) && ((CFG_MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT == __ON__)||(CFG_MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT == __AUTO__)) && \
	(defined(__COSMOS_MUSICPLY_SLIM__) && defined(__PLAYLIST_SERVICE_SLIM__))
	#ifndef __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
	#define __MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__
	#endif
#endif


#if defined(CFG_MMI_MV_SUPPORT_LANDSCAPE_MODE) && ((CFG_MMI_MV_SUPPORT_LANDSCAPE_MODE == __ON__)||(CFG_MMI_MV_SUPPORT_LANDSCAPE_MODE == __AUTO__)) && \
	(defined(__MMI_MMS_2__ ))
	#ifndef __MMI_MV_SUPPORT_LANDSCAPE_MODE__
	#define __MMI_MV_SUPPORT_LANDSCAPE_MODE__
	#endif
#endif


#if defined(CFG_MMI_MV_SUPPORT_REF_ID) && ((CFG_MMI_MV_SUPPORT_REF_ID == __ON__)||(CFG_MMI_MV_SUPPORT_REF_ID == __AUTO__)) && \
	(defined(__MMI_MMS_2__ ))
	#ifndef __MMI_MV_SUPPORT_REF_ID__
	#define __MMI_MV_SUPPORT_REF_ID__
	#endif
#endif


#if (defined(__MMI_MMS_2__) && !(defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	#define __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_AUDIO) && ((CFG_MMI_MY_FAVORITE_AUDIO == __ON__)||(CFG_MMI_MY_FAVORITE_AUDIO == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__))
	#ifndef __MMI_MY_FAVORITE_AUDIO__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_AUDIO_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_AUDIO_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_AUDIO_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_AUDIO__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_AUDIO_HYPERLINK__
	#define __MMI_MY_FAVORITE_AUDIO_HYPERLINK__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_GPLUSGAME) && ((CFG_MMI_MY_FAVORITE_GPLUSGAME == __ON__)||(CFG_MMI_MY_FAVORITE_GPLUSGAME == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__) && defined(__J2ME__))
	#ifndef __MMI_MY_FAVORITE_GPLUSGAME__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_SWFLASH_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_SWFLASH_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_SWFLASH_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_SWFLASH__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_SWFLASH_HYPERLINK__
	#define __MMI_MY_FAVORITE_SWFLASH_HYPERLINK__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_IMAGES) && ((CFG_MMI_MY_FAVORITE_IMAGES == __ON__)||(CFG_MMI_MY_FAVORITE_IMAGES == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__))
	#ifndef __MMI_MY_FAVORITE_IMAGES__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_IMAGES_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_IMAGES_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_IMAGES_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_IMAGES__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_IMAGES_HYPERLINK__
	#define __MMI_MY_FAVORITE_IMAGES_HYPERLINK__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_MMSBOX) && ((CFG_MMI_MY_FAVORITE_MMSBOX == __ON__)||(CFG_MMI_MY_FAVORITE_MMSBOX == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__) && defined(MMS_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_MMSBOX__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_MMSBOX_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_MMSBOX_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_MMSBOX_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_MMSBOX__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_MMSBOX_HYPERLINK__
	#define __MMI_MY_FAVORITE_MMSBOX_HYPERLINK__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_OTHERS) && ((CFG_MMI_MY_FAVORITE_OTHERS == __ON__)||(CFG_MMI_MY_FAVORITE_OTHERS == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__))
	#ifndef __MMI_MY_FAVORITE_OTHERS__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_OTHERS_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_OTHERS_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_OTHERS_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_OTHERS__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_OTHERS_HYPERLINK__
	#define __MMI_MY_FAVORITE_OTHERS_HYPERLINK__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_THEME) && ((CFG_MMI_MY_FAVORITE_THEME == __ON__)||(CFG_MMI_MY_FAVORITE_THEME == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__) && defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))
	#ifndef __MMI_MY_FAVORITE_THEME__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_THEME_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_THEME_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_THEME_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_THEME__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_THEME_HYPERLINK__
	#define __MMI_MY_FAVORITE_THEME_HYPERLINK__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_VIDEO) && ((CFG_MMI_MY_FAVORITE_VIDEO == __ON__)||(CFG_MMI_MY_FAVORITE_VIDEO == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__))
	#ifndef __MMI_MY_FAVORITE_VIDEO__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_VIDEO_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_VIDEO_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_VIDEO_HYPERLINK == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE_VIDEO__) && defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_VIDEO_HYPERLINK__
	#define __MMI_MY_FAVORITE_VIDEO_HYPERLINK__
	#endif
#endif


#if (defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__) || defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__) || defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__) || defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__) || defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__) || defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__) ||   defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__))
	#ifndef __MMI_MY_FAVORITE_HYPERLINK_SUPPORT__
	#define __MMI_MY_FAVORITE_HYPERLINK_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_JAVA_HYPERLINK) && ((CFG_MMI_MY_FAVORITE_JAVA_HYPERLINK == __ON__)||(CFG_MMI_MY_FAVORITE_JAVA_HYPERLINK == __AUTO__)) && \
	(defined(__J2ME__) && defined(__MMI_MY_FAVORITE__)&& defined(BROWSER_SUPPORT))
	#ifndef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_JAVABOX) && ((CFG_MMI_MY_FAVORITE_JAVABOX == __ON__)||(CFG_MMI_MY_FAVORITE_JAVABOX == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__) && defined(__J2ME__))
	#ifndef __MMI_MY_FAVORITE_JAVABOX__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_MY_FAVORITE_MEMORYCARD) && ((CFG_MMI_MY_FAVORITE_MEMORYCARD == __ON__)||(CFG_MMI_MY_FAVORITE_MEMORYCARD == __AUTO__)) && \
	(defined(__MMI_MY_FAVORITE__))
	#ifndef __MMI_MY_FAVORITE_MEMORYCARD__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_NETSET_3G_ENHANCE) && ((CFG_MMI_NETSET_3G_ENHANCE == __ON__)||(CFG_MMI_NETSET_3G_ENHANCE == __AUTO__)) && \
	(defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__GEMINI__))
	#ifndef __MMI_NETSET_3G_ENHANCE__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_NETWORK_CIPHER_SUPPORT) && ((CFG_MMI_NETWORK_CIPHER_SUPPORT == __ON__)||(CFG_MMI_NETWORK_CIPHER_SUPPORT == __AUTO__))
	#ifndef __MMI_NETWORK_CIPHER_SUPPORT__
	#define __MMI_NETWORK_CIPHER_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_NETWORKSETTING_SLIM) && ((CFG_MMI_NETWORKSETTING_SLIM == __ON__)||(CFG_MMI_NETWORKSETTING_SLIM == __AUTO__))
	#ifndef __MMI_NETWORKSETTING_SLIM__
	#define __MMI_NETWORKSETTING_SLIM__
	#endif
#endif


#if defined(CFG_MMI_NITZ_TZ_SUPPORT) && ((CFG_MMI_NITZ_TZ_SUPPORT == __ON__)||(CFG_MMI_NITZ_TZ_SUPPORT == __AUTO__)) && \
	(defined(__MMI_WORLD_CLOCK__) || defined(__MMI_MRE_WORLD_CLOCK__))
	#ifndef __MMI_NITZ_TZ_SUPPORT__
	#define __MMI_NITZ_TZ_SUPPORT__
	#endif
#endif


#if (defined(TFT_MAINLCD))
	#ifndef __MMI_NO_CONTRAST_LEVEL__
	#define __MMI_NO_CONTRAST_LEVEL__
	#endif
#endif


#if (defined(__NO_HANDWRITING__))
	#ifndef __MMI_NO_HANDWRITING__
	#define __MMI_NO_HANDWRITING__
	#endif
#endif


#if (defined(MT6223) || defined(MT6223P) || defined(MT6268T))
	#ifndef __MMI_NONBLOCKING_DECODE__
	#define __MMI_NONBLOCKING_DECODE__
	#endif
#endif


#if defined(CFG_MMI_NOTE_APP) && ((CFG_MMI_NOTE_APP == __ON__)||(CFG_MMI_NOTE_APP == __AUTO__))
	#ifndef __MMI_NOTE_APP__
	#define __MMI_NOTE_APP__
	#endif
#endif


#if defined(CFG_MMI_PNS) && ((CFG_MMI_PNS == __ON__)||(CFG_MMI_PNS == __AUTO__)) && \
	(defined(PNS_SUPPORT))
	#ifndef __MMI_PNS__
	#define __MMI_PNS__
	#endif
#endif


#if (defined(__MMI_PNS__))
	#ifndef __MMI_NSS_SUPPORT__
	#define __MMI_NSS_SUPPORT__
	#endif
#endif


#if ((defined(__MMI_FWUI_SLIM__)))
	#ifndef __MMI_STATUS_ICON_BAR_SLIM__
	#define __MMI_STATUS_ICON_BAR_SLIM__
	#endif
#endif


#if (defined(__MMI_STATUS_ICON_BAR_SLIM__))
	#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
	#define __MMI_NW_INFO_DN_STATUS_SLIM__
	#endif
#endif


#if defined(CFG_MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS) && ((CFG_MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS == __ON__)||(CFG_MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS == __AUTO__))
	#ifndef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
	#define __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
	#endif
#endif


#if defined(CFG_MMI_NW_INFO_INVALID_SIM_MESSAGE) && ((CFG_MMI_NW_INFO_INVALID_SIM_MESSAGE == __ON__)||(CFG_MMI_NW_INFO_INVALID_SIM_MESSAGE == __AUTO__))
	#ifndef __MMI_NW_INFO_INVALID_SIM_MESSAGE__
	#define __MMI_NW_INFO_INVALID_SIM_MESSAGE__
	#endif
#endif


#if (defined(__ONLY_ONE_UART__))
	#ifndef __MMI_ONLY_ONE_UART_AVAILABLE__
	#define __MMI_ONLY_ONE_UART_AVAILABLE__
	#endif
#endif


#if defined(CFG_MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE) && ((CFG_MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE == __ON__)||(CFG_MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE == __AUTO__)) && \
	(defined(__MMI_UNIFIED_COMPOSER__))
	#ifndef __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__
	#define __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__
	#endif
#endif


#if (!defined(__MMI_SLIM_MMS_2__) && ((defined(__OP12__) && defined(__MMI_MMS_2__) && defined(__MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__) && defined (__OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__)) || (defined(__MTK_INTERNAL__) && defined(__MMI_MMS_2__) && defined(__OPTR_NONE__)&& !defined(__MMI_MMS_DUAL_SIM__))))
	#ifndef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
	#define __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
	#endif
#endif


#if (defined(__MMI_LAUNCHER_APP_LIST__))
	#ifndef __MMI_OPERATOR_ON_FANCY_SCREEN__
	#define __MMI_OPERATOR_ON_FANCY_SCREEN__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_ORGANIZER_SUPPORT__
	#define __MMI_ORGANIZER_SUPPORT__
	#endif
#endif


#if ((defined(__MMI_BT_SUPPORT__) && defined(__BT_PBAP_PROFILE__)))
	#if (!defined(__MMI_VCARD__))
	#error "please define __MMI_VCARD__"
	#endif
	#ifndef __MMI_PBAP_SUPPORT__
	#define __MMI_PBAP_SUPPORT__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_BULGARIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_BULGARIAN__
	#define __MMI_PENPOWER_BULGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_CROATIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_CROATIAN__
	#define __MMI_PENPOWER_CROATIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_CZECH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_CZECH__
	#define __MMI_PENPOWER_CZECH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_DANISH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_DANISH__
	#define __MMI_PENPOWER_DANISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_DUTCH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_DUTCH__
	#define __MMI_PENPOWER_DUTCH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_FINNISH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_FINNISH__
	#define __MMI_PENPOWER_FINNISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_FRENCH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_FRENCH__
	#define __MMI_PENPOWER_FRENCH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_GERMAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_GERMAN__
	#define __MMI_PENPOWER_GERMAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_HUNGARIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_HUNGARIAN__
	#define __MMI_PENPOWER_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ITALIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_ITALIAN__
	#define __MMI_PENPOWER_ITALIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_MOLDOVAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_MOLDOVAN__
	#define __MMI_PENPOWER_MOLDOVAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_NORWEGIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_NORWEGIAN__
	#define __MMI_PENPOWER_NORWEGIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_PORTUGESE__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_PORTUGESE__
	#define __MMI_PENPOWER_PORTUGESE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_ROMANIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_ROMANIAN__
	#define __MMI_PENPOWER_ROMANIAN__
	#endif
#endif


#if (defined( __MMI_TOUCH_SCREEN__) && defined(__MMI_PENPOWER__) && defined(__MMI_LANG_RUSSIAN__))
	#ifndef __MMI_PENPOWER_RUSSIAN__
	#define __MMI_PENPOWER_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SLOVAK__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_SLOVAK__
	#define __MMI_PENPOWER_SLOVAK__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SLOVENIAN__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_SLOVENIAN__
	#define __MMI_PENPOWER_SLOVENIAN__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SM_CHINESE__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_SM_CHINESE__
	#define __MMI_PENPOWER_SM_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SPANISH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_SPANISH__
	#define __MMI_PENPOWER_SPANISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_SWEDISH__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_SWEDISH__
	#define __MMI_PENPOWER_SWEDISH__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_THAI__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_THAI__
	#define __MMI_PENPOWER_THAI__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_TR_CHINESE__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_PENPOWER_TR_CHINESE__
	#define __MMI_PENPOWER_TR_CHINESE__
	#endif
#endif


#if defined(CFG_MMI_PHB_ADV_NUM_MATCH_MOBILE) && ((CFG_MMI_PHB_ADV_NUM_MATCH_MOBILE == __ON__)||(CFG_MMI_PHB_ADV_NUM_MATCH_MOBILE == __AUTO__))
	#ifndef __MMI_PHB_ADV_NUM_MATCH_MOBILE__
	#define __MMI_PHB_ADV_NUM_MATCH_MOBILE__
	#endif
#endif


#if defined(CFG_MMI_PHB_CALLER_GROUP) && ((CFG_MMI_PHB_CALLER_GROUP == __ON__)||(CFG_MMI_PHB_CALLER_GROUP == __AUTO__)) && \
	(!defined(__MMI_CONTACT_SLIM__))
	#ifndef __MMI_PHB_CALLER_GROUP__
	#define __MMI_PHB_CALLER_GROUP__
	#endif
#endif


#if defined(CFG_MMI_PHB_CALLER_RES) && ((CFG_MMI_PHB_CALLER_RES == __ON__)||(CFG_MMI_PHB_CALLER_RES == __AUTO__))
	#ifndef __MMI_PHB_CALLER_RES__
	#define __MMI_PHB_CALLER_RES__
	#endif
#endif


#if defined(CFG_MMI_PHB_CUSTOM_FIELD_TYPE) && ((CFG_MMI_PHB_CUSTOM_FIELD_TYPE == __ON__)||(CFG_MMI_PHB_CUSTOM_FIELD_TYPE == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_PHB_CUSTOM_FIELD_TYPE__
	#define __MMI_PHB_CUSTOM_FIELD_TYPE__
	#endif
#endif


#if defined(CFG_MMI_PHB_OPTIONAL_FIELD) && ((CFG_MMI_PHB_OPTIONAL_FIELD == __ON__)||(CFG_MMI_PHB_OPTIONAL_FIELD == __AUTO__))
	#ifndef __MMI_PHB_OPTIONAL_FIELD__
	#define __MMI_PHB_OPTIONAL_FIELD__
	#endif
#endif


#if defined(CFG_MMI_PHB_DEFAULT_NUMBER) && (CFG_MMI_PHB_DEFAULT_NUMBER == __ON__) || \
	(defined(__MMI_JSR_75_PIM_MSA_SUPPORT__))
	#if (!defined(__MMI_PHB_OPTIONAL_FIELD__))
	#error "dependence conflict, pls turn on __MMI_PHB_OPTIONAL_FIELD__ or turn off __MMI_PHB_DEFAULT_NUMBER__"
	#endif
	#ifndef __MMI_PHB_DEFAULT_NUMBER__
	#define __MMI_PHB_DEFAULT_NUMBER__
	#endif
#endif


#if defined(CFG_MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK) && ((CFG_MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK == __ON__)||(CFG_MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK == __AUTO__))
	#ifndef __MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__
	#define __MMI_PHB_DELETE_ALL_CHECK_PHONE_LOCK__
	#endif
#endif


#if (defined(__MMI_DIALER_SEARCH__) && defined(__MMI_PHB_OPTIONAL_FIELD__))
	#ifndef __MMI_PHB_DS_SEARCH_OP_NUMBER__
	#define __MMI_PHB_DS_SEARCH_OP_NUMBER__
	#endif
#endif


#if defined(CFG_MMI_PHB_EMPTY_NAME_TOP) && ((CFG_MMI_PHB_EMPTY_NAME_TOP == __ON__)||(CFG_MMI_PHB_EMPTY_NAME_TOP == __AUTO__))
	#ifndef __MMI_PHB_EMPTY_NAME_TOP__
	#define __MMI_PHB_EMPTY_NAME_TOP__
	#endif
#endif


#if defined(CFG_MMI_PHB_GENERIC_MULTI_SELECT) && ((CFG_MMI_PHB_GENERIC_MULTI_SELECT == __ON__)||(CFG_MMI_PHB_GENERIC_MULTI_SELECT == __AUTO__)) && \
	(defined(__MMI_PHB_UI_IN_TABS__))
	#ifndef __MMI_PHB_GENERIC_MULTI_SELECT__
	#define __MMI_PHB_GENERIC_MULTI_SELECT__
	#endif
#endif


#if defined(CFG_MMI_PHB_INFO_FIELD) && (CFG_MMI_PHB_INFO_FIELD == __ON__) || \
	(defined(__MMI_JSR_75_PIM_MSA_SUPPORT__))
	#ifndef __MMI_PHB_INFO_FIELD__
	#define __MMI_PHB_INFO_FIELD__
	#endif
#endif


#if defined(CFG_MMI_PHB_LAST_NAME_FIELD) && ((CFG_MMI_PHB_LAST_NAME_FIELD == __ON__)||(CFG_MMI_PHB_LAST_NAME_FIELD == __AUTO__))
	#ifndef __MMI_PHB_LAST_NAME_FIELD__
	#define __MMI_PHB_LAST_NAME_FIELD__
	#endif
#endif


#if defined(CFG_MMI_PHB_MSN_FIELD) && ((CFG_MMI_PHB_MSN_FIELD == __ON__)||(CFG_MMI_PHB_MSN_FIELD == __AUTO__))
	#ifndef __MMI_PHB_MSN_FIELD__
	#define __MMI_PHB_MSN_FIELD__
	#endif
#endif


#if defined(CFG_MMI_PHB_MULTI_OPERATION) && ((CFG_MMI_PHB_MULTI_OPERATION == __ON__)||(CFG_MMI_PHB_MULTI_OPERATION == __AUTO__))
	#ifndef __MMI_PHB_MULTI_OPERATION__
	#define __MMI_PHB_MULTI_OPERATION__
	#endif
#endif


#if defined(CFG_MMI_PHB_OPTIONAL_FIELD_ADDITIONAL) && ((CFG_MMI_PHB_OPTIONAL_FIELD_ADDITIONAL == __ON__)||(CFG_MMI_PHB_OPTIONAL_FIELD_ADDITIONAL == __AUTO__)) && \
	(defined(__MMI_PHB_OPTIONAL_FIELD__))
	#ifndef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
	#define __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
	#endif
#endif


#if defined(CFG_MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL) && (CFG_MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL == __ON__) || \
	(defined(__MMI_JSR_75_PIM_MSA_SUPPORT__))
	#ifndef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
	#define __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
	#endif
#endif


#if defined(CFG_MMI_PHB_PBAPC_SYNC_CONTACT) && ((CFG_MMI_PHB_PBAPC_SYNC_CONTACT == __ON__)||(CFG_MMI_PHB_PBAPC_SYNC_CONTACT == __AUTO__)) && \
	(defined(__BT_PBAP_CLIENT__))
	#ifndef __MMI_PHB_PBAPC_SYNC_CONTACT__
	#define __MMI_PHB_PBAPC_SYNC_CONTACT__
	#endif
#endif


#if defined(CFG_MMI_PHB_PHOTO_STICKER_SUPPORT) && ((CFG_MMI_PHB_PHOTO_STICKER_SUPPORT == __ON__)||(CFG_MMI_PHB_PHOTO_STICKER_SUPPORT == __AUTO__)) && \
	(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_PHB_QUICK_SEARCH__) && defined(__MMI_PHB_CALLER_RES__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
	#ifndef __MMI_PHB_PHOTO_STICKER_SUPPORT__
	#define __MMI_PHB_PHOTO_STICKER_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PHB_PINYIN_SORT) && ((CFG_MMI_PHB_PINYIN_SORT == __ON__)||(CFG_MMI_PHB_PINYIN_SORT == __AUTO__)) && \
	(defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__) || defined(__MMI_ITAP__) || defined(__MMI_GUOBI__))
	#ifndef __MMI_PHB_PINYIN_SORT__
	#define __MMI_PHB_PINYIN_SORT__
	#endif
#endif


#if defined(CFG_MMI_PHB_SAVE_CONTACT_NOTIFY) && ((CFG_MMI_PHB_SAVE_CONTACT_NOTIFY == __ON__)||(CFG_MMI_PHB_SAVE_CONTACT_NOTIFY == __AUTO__))
	#ifndef __MMI_PHB_SAVE_CONTACT_NOTIFY__
	#define __MMI_PHB_SAVE_CONTACT_NOTIFY__
	#endif
#endif


#if defined(CFG_MMI_PHB_SOS_NUM_EDIT) && ((CFG_MMI_PHB_SOS_NUM_EDIT == __ON__)||(CFG_MMI_PHB_SOS_NUM_EDIT == __AUTO__))
	#ifndef __MMI_PHB_SOS_NUM_EDIT__
	#define __MMI_PHB_SOS_NUM_EDIT__
	#endif
#endif


#if defined(CFG_MMI_PHB_SPEED_DIAL) && ((CFG_MMI_PHB_SPEED_DIAL == __ON__)||(CFG_MMI_PHB_SPEED_DIAL == __AUTO__)) && \
	(!defined (__MMI_CONTACT_SLIM__))
	#ifndef __MMI_PHB_SPEED_DIAL__
	#define __MMI_PHB_SPEED_DIAL__
	#endif
#endif


#if defined(CFG_MMI_PHB_STARTUP_COPY_SIM) && ((CFG_MMI_PHB_STARTUP_COPY_SIM == __ON__)||(CFG_MMI_PHB_STARTUP_COPY_SIM == __AUTO__))
	#ifndef __MMI_PHB_STARTUP_COPY_SIM__
	#define __MMI_PHB_STARTUP_COPY_SIM__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_PHB_SUPPORT__
	#define __MMI_PHB_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PHB_TWO_LINE_MENUITEM_DISPLAY) && ((CFG_MMI_PHB_TWO_LINE_MENUITEM_DISPLAY == __ON__)||(CFG_MMI_PHB_TWO_LINE_MENUITEM_DISPLAY == __AUTO__)) && \
	(!defined(__MMI_MAINLCD_128X128__) || !defined(__MMI_MAINLCD_128X160__))
	#ifndef __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
	#define __MMI_PHB_TWO_LINE_MENUITEM_DISPLAY__
	#endif
#endif


#if (defined(__PHB_USIM_ADDITIONAL_SUPPORT__))
	#ifndef __MMI_PHB_USIM_SUPPORT__
	#define __MMI_PHB_USIM_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PHNSET_SCHEDULE_POWER_ON_OFF) && ((CFG_MMI_PHNSET_SCHEDULE_POWER_ON_OFF == __ON__)||(CFG_MMI_PHNSET_SCHEDULE_POWER_ON_OFF == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
	#define __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
	#endif
#endif


#if defined(CFG_MMI_PHONESETTING_SLIM) && ((CFG_MMI_PHONESETTING_SLIM == __ON__)||(CFG_MMI_PHONESETTING_SLIM == __AUTO__))
	#ifndef __MMI_PHONESETTING_SLIM__
	#define __MMI_PHONESETTING_SLIM__
	#endif
#endif


#if (defined(__COSMOS_MUSICPLY_SLIM__) && defined(__PLAYLIST_SERVICE_SLIM__))
	#ifndef __MMI_PLAYLIST_SERVICE_SLIM__
	#define __MMI_PLAYLIST_SERVICE_SLIM__
	#endif
#endif


#if (defined(__MMI_FWUI_SLIM__))
	#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
	#define __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
	#endif
#endif


#if (defined(__MMI_FWUI_SLIM__))
	#ifndef __MMI_POPUP_NO_SHOW_ICON__
	#define __MMI_POPUP_NO_SHOW_ICON__
	#endif
#endif


#if defined(CFG_MMI_POWER_ON_OFF_DISPLAY) && ((CFG_MMI_POWER_ON_OFF_DISPLAY == __ON__)||(CFG_MMI_POWER_ON_OFF_DISPLAY == __AUTO__)) && \
	(!defined(__LOW_COST_SUPPORT_COMMON__) || defined(__MMI_MAINLCD_96X64__ ))
	#ifndef __MMI_POWER_ON_OFF_DISPLAY__
	#define __MMI_POWER_ON_OFF_DISPLAY__
	#endif
#endif


#if (defined(MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__) ||defined(__MMI_MEDIA_PLAYER_VIDEO__) ||defined(__MMI_VIDEO_PLAYER__))
	#ifndef __MMI_VIDEO_PLAY_SUPPORT__
	#define __MMI_VIDEO_PLAY_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_POWER_ON_OFF_DISPLAY_VIDEO) && ((CFG_MMI_POWER_ON_OFF_DISPLAY_VIDEO == __ON__)||(CFG_MMI_POWER_ON_OFF_DISPLAY_VIDEO == __AUTO__)) && \
	((((defined(MP4_DECODE) && (defined(__MP4_DEC_HW_SUPPORT__) || (defined(__MP4_DEC_SW_SUPPORT__) && !defined(MT6225)))) || (defined(MJPG_DECODE) && !defined(__DIRECT_SENSOR_SUPPORT__)) || defined(__RM_DEC_SUPPORT__)) && defined(__MMI_POWER_ON_OFF_DISPLAY__)) && defined(__MMI_VIDEO_PLAY_SUPPORT__))
	#ifndef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
	#define __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
	#endif
#endif


#if defined(CFG_MMI_POWER_ON_OFF_MUTE) && ((CFG_MMI_POWER_ON_OFF_MUTE == __ON__)||(CFG_MMI_POWER_ON_OFF_MUTE == __AUTO__))
	#ifndef __MMI_POWER_ON_OFF_MUTE__
	#define __MMI_POWER_ON_OFF_MUTE__
	#endif
#endif


#if defined(CFG_MMI_POWER_ON_OFF_NO_CUSTOMIZE) && ((CFG_MMI_POWER_ON_OFF_NO_CUSTOMIZE == __ON__)||(CFG_MMI_POWER_ON_OFF_NO_CUSTOMIZE == __AUTO__))
	#ifndef __MMI_POWER_ON_OFF_NO_CUSTOMIZE__
	#define __MMI_POWER_ON_OFF_NO_CUSTOMIZE__
	#endif
#endif


#if defined(CFG_MMI_PREF_NETWORK) && ((CFG_MMI_PREF_NETWORK == __ON__)||(CFG_MMI_PREF_NETWORK == __AUTO__))
	#ifndef __MMI_PREF_NETWORK__
	#define __MMI_PREF_NETWORK__
	#endif
#endif


#if (defined(__MMI_IME_PREFER_WRITING_LANG__))
	#ifndef __MMI_PREFER_WRITING_LANG__
	#define __MMI_PREFER_WRITING_LANG__
	#endif
#endif


#if defined(CFG_MMI_PROF_ADD_DEL_PROF_SUPPORT) && ((CFG_MMI_PROF_ADD_DEL_PROF_SUPPORT == __ON__)||(CFG_MMI_PROF_ADD_DEL_PROF_SUPPORT == __AUTO__))
	#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
	#define __MMI_PROF_ADD_DEL_PROF_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_PROF_SLIM) && ((CFG_MMI_PROF_SLIM == __ON__)||(CFG_MMI_PROF_SLIM == __AUTO__))
	#ifndef __MMI_PROF_SLIM__
	#define __MMI_PROF_SLIM__
	#endif
#endif


#if defined(CFG_MMI_PROF_SLIM_PROFILES) && ((CFG_MMI_PROF_SLIM_PROFILES == __ON__)||(CFG_MMI_PROF_SLIM_PROFILES == __AUTO__))
	#ifndef __MMI_PROF_SLIM_PROFILES__
	#define __MMI_PROF_SLIM_PROFILES__
	#endif
#endif


#if defined(CFG_MMI_PROF_SPLIT_MSG_TONES) && ((CFG_MMI_PROF_SPLIT_MSG_TONES == __ON__)||(CFG_MMI_PROF_SPLIT_MSG_TONES == __AUTO__))
	#ifndef __MMI_PROF_SPLIT_MSG_TONES__
	#define __MMI_PROF_SPLIT_MSG_TONES__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_PROFILES_APP__
	#define __MMI_PROFILES_APP__
	#endif
#endif


#if (defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_PROFILES_EXT_FILE_SUPPORT__
	#define __MMI_PROFILES_EXT_FILE_SUPPORT__
	#endif
#endif


#if (defined(__MMI_PROV_IN_UM__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
	#define __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
	#endif
#endif


#if (defined (__MMI_CCA_SUPPORT__))
	#ifndef __MMI_PROVISIONING_SERVICE_SUPPORT__
	#define __MMI_PROVISIONING_SERVICE_SUPPORT__
	#endif
#endif


#if (defined(PURE_AUDIO_SUPPORT))
	#ifndef __MMI_PURE_AUDIO__
	#define __MMI_PURE_AUDIO__
	#endif
#endif


#if (defined(__UM_FOLDER__) && defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__))
	#ifndef __MMI_PUSH_IN_UM__
	#define __MMI_PUSH_IN_UM__
	#endif
#endif


#if (!defined(__MMI_PUSH_IN_UM__) && defined(__WAP_PUSH_SUPPORT__))
	#ifndef __MMI_PUSH_IN_MSG__
	#define __MMI_PUSH_IN_MSG__
	#endif
#endif


#if (defined(__MMI_PUSH_IN_UM__))
	#ifndef __MMI_PUSH_SETTING_IN_UM__
	#define __MMI_PUSH_SETTING_IN_UM__
	#endif
#endif


#if defined(CFG_MMI_PUSH_TURN_ON_OFF_SWITCH) && ((CFG_MMI_PUSH_TURN_ON_OFF_SWITCH == __ON__)||(CFG_MMI_PUSH_TURN_ON_OFF_SWITCH == __AUTO__)) && \
	(defined(__WAP_PUSH_SUPPORT__)&&!defined(__SLIM_PUSH_FEATURE_SUPPORT))
	#ifndef __MMI_PUSH_TURN_ON_OFF_SWITCH__
	#define __MMI_PUSH_TURN_ON_OFF_SWITCH__
	#endif
#endif


#if defined(CFG_MMI_Q05A_LAUNCH_SCREEN) && ((CFG_MMI_Q05A_LAUNCH_SCREEN == __ON__)||(CFG_MMI_Q05A_LAUNCH_SCREEN == __AUTO__))
	#ifndef __MMI_Q05A_LAUNCH_SCREEN__
	#define __MMI_Q05A_LAUNCH_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_RECEIVE_USSD_TONE) && ((CFG_MMI_RECEIVE_USSD_TONE == __ON__)||(CFG_MMI_RECEIVE_USSD_TONE == __AUTO__))
	#ifndef __MMI_RECEIVE_USSD_TONE__
	#define __MMI_RECEIVE_USSD_TONE__
	#endif
#endif


#if defined(CFG_MMI_REDUCED_UI_BUFFER) && ((CFG_MMI_REDUCED_UI_BUFFER == __ON__)||(CFG_MMI_REDUCED_UI_BUFFER == __AUTO__))
	#ifndef __MMI_REDUCED_UI_BUFFER__
	#define __MMI_REDUCED_UI_BUFFER__
	#endif
#endif


#if (defined(CFG_MMI_RES_TYPE_ACTIVE_SCREEN_SEL)&&(CFG_MMI_RES_TYPE_ACTIVE_SCREEN_SEL != __OFF__))
	#ifndef __MMI_RES_TYPE_ACTIVE_SCREEN_SEL__
	#define __MMI_RES_TYPE_ACTIVE_SCREEN_SEL__	CFG_MMI_RES_TYPE_ACTIVE_SCREEN_SEL
	#endif
#endif


#if ((defined(__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__) && (__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__ == __RES_TYPE_BMP__)))
	#ifndef __MMI_RES_TYPE_ACTIVE_SCREEN__
	#define __MMI_RES_TYPE_ACTIVE_SCREEN__	"BMP"
	#endif
#elif ((defined(__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__) && (__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__ == __RES_TYPE_JPG__)))
	#ifndef __MMI_RES_TYPE_ACTIVE_SCREEN__
	#define __MMI_RES_TYPE_ACTIVE_SCREEN__	"JPG"
	#endif
#elif ((defined(__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__) && (__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__ == __RES_TYPE_GIF__)) || !defined(__MMI_RES_TYPE_ACTIVE_SCREEN_SEL__))
	#ifndef __MMI_RES_TYPE_ACTIVE_SCREEN__
	#define __MMI_RES_TYPE_ACTIVE_SCREEN__	"GIF"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL))
	#ifndef __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL__
	#define __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL__	CFG_MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL
	#endif
#endif


#if (defined(__MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL__) && (__MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL__ == __RES_TYPE_BMP__))
	#ifndef __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__
	#define __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__	"BMP"
	#endif
#elif (defined(__MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL__) && (__MMI_RES_TYPE_BOOTUP_LOGO_IMAGE_SEL__ == __RES_TYPE_GIF__))
	#ifndef __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__
	#define __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__	"GIF"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_MAINMENU_MATRIX_SEL))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX_SEL__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX_SEL__	CFG_MMI_RES_TYPE_MAINMENU_MATRIX_SEL
	#endif
#endif


#if (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_SEL__ == __RES_TYPE_PNG__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX__	".PNG"
	#endif
#elif (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_SEL__ == __RES_TYPE_GIF__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX__	".GIF"
	#endif
#elif (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_SEL__ == __RES_TYPE_BMP__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX__	".BMP"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__	CFG_MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL
	#endif
#endif


#if (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__ == __RES_TYPE_PNG__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__	".PNG"
	#endif
#elif (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__ == __RES_TYPE_GIF__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__	".GIF"
	#endif
#elif (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__ == __RES_TYPE_SEQUENCE__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__	""
	#endif
#elif (defined(__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__) && (__MMI_RES_TYPE_MAINMENU_MATRIX_ANI_SEL__ == __RES_TYPE_BMP__))
	#ifndef __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__
	#define __MMI_RES_TYPE_MAINMENU_MATRIX_ANI__	".BMP"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_POPUP_SCREEN_SEL))
	#ifndef __MMI_RES_TYPE_POPUP_SCREEN_SEL__
	#define __MMI_RES_TYPE_POPUP_SCREEN_SEL__	CFG_MMI_RES_TYPE_POPUP_SCREEN_SEL
	#endif
#endif


#if ((defined(__MMI_RES_TYPE_POPUP_SCREEN_SEL__) && (__MMI_RES_TYPE_POPUP_SCREEN_SEL__ == __RES_TYPE_GIF__)))
	#ifndef __MMI_RES_TYPE_POPUP_SCREEN__
	#define __MMI_RES_TYPE_POPUP_SCREEN__	".GIF"
	#endif
#elif ((defined(__MMI_RES_TYPE_POPUP_SCREEN_SEL__) && (__MMI_RES_TYPE_POPUP_SCREEN_SEL__ == __RES_TYPE_PNG__)))
	#ifndef __MMI_RES_TYPE_POPUP_SCREEN__
	#define __MMI_RES_TYPE_POPUP_SCREEN__	".PNG"
	#endif
#elif ((defined(__MMI_RES_TYPE_POPUP_SCREEN_SEL__) && (__MMI_RES_TYPE_POPUP_SCREEN_SEL__ == __RES_TYPE_JPG__)))
	#ifndef __MMI_RES_TYPE_POPUP_SCREEN__
	#define __MMI_RES_TYPE_POPUP_SCREEN__	".JPG"
	#endif
#elif ((defined(__MMI_RES_TYPE_POPUP_SCREEN_SEL__) && (__MMI_RES_TYPE_POPUP_SCREEN_SEL__ == __RES_TYPE_SEQUENCE__)))
	#ifndef __MMI_RES_TYPE_POPUP_SCREEN__
	#define __MMI_RES_TYPE_POPUP_SCREEN__	""
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_POWER_ONOFF_SEL)&&(CFG_MMI_RES_TYPE_POWER_ONOFF_SEL != __OFF__))
	#ifndef __MMI_RES_TYPE_POWER_ONOFF_SEL__
	#define __MMI_RES_TYPE_POWER_ONOFF_SEL__	CFG_MMI_RES_TYPE_POWER_ONOFF_SEL
	#endif
#endif


#if (defined(__MMI_RES_TYPE_POWER_ONOFF_SEL__) && (__MMI_RES_TYPE_POWER_ONOFF_SEL__ == __RES_TYPE_BMP__))
	#ifndef __MMI_RES_TYPE_POWER_ONOFF__
	#define __MMI_RES_TYPE_POWER_ONOFF__	"BMP"
	#endif
#elif (defined(__MMI_RES_TYPE_POWER_ONOFF_SEL__) && (__MMI_RES_TYPE_POWER_ONOFF_SEL__ == __RES_TYPE_JPG__))
	#ifndef __MMI_RES_TYPE_POWER_ONOFF__
	#define __MMI_RES_TYPE_POWER_ONOFF__	"JPG"
	#endif
#elif ((defined(__MMI_RES_TYPE_POWER_ONOFF_SEL__) && (__MMI_RES_TYPE_POWER_ONOFF_SEL__ == __RES_TYPE_GIF__)) || !defined(__MMI_RES_TYPE_POWER_ONOFF_SEL__))
	#ifndef __MMI_RES_TYPE_POWER_ONOFF__
	#define __MMI_RES_TYPE_POWER_ONOFF__	"GIF"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_SCREEN_SAVER_SEL)&&(CFG_MMI_RES_TYPE_SCREEN_SAVER_SEL != __OFF__))
	#ifndef __MMI_RES_TYPE_SCREEN_SAVER_SEL__
	#define __MMI_RES_TYPE_SCREEN_SAVER_SEL__	CFG_MMI_RES_TYPE_SCREEN_SAVER_SEL
	#endif
#endif


#if ((defined(__MMI_RES_TYPE_SCREEN_SAVER_SEL__) && (__MMI_RES_TYPE_SCREEN_SAVER_SEL__ == __RES_TYPE_BMP__)))
	#ifndef __MMI_RES_TYPE_SCREEN_SAVER__
	#define __MMI_RES_TYPE_SCREEN_SAVER__	"BMP"
	#endif
#elif ((defined(__MMI_RES_TYPE_SCREEN_SAVER_SEL__) && (__MMI_RES_TYPE_SCREEN_SAVER_SEL__ == __RES_TYPE_JPG__)))
	#ifndef __MMI_RES_TYPE_SCREEN_SAVER__
	#define __MMI_RES_TYPE_SCREEN_SAVER__	"JPG"
	#endif
#elif ((defined(__MMI_RES_TYPE_SCREEN_SAVER_SEL__) && (__MMI_RES_TYPE_SCREEN_SAVER_SEL__ == __RES_TYPE_GIF__)) || !defined(__MMI_RES_TYPE_SCREEN_SAVER_SEL__))
	#ifndef __MMI_RES_TYPE_SCREEN_SAVER__
	#define __MMI_RES_TYPE_SCREEN_SAVER__	"GIF"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL)&&(CFG_MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL != __OFF__))
	#ifndef __MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__
	#define __MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__	CFG_MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL
	#endif
#endif


#if ((defined(__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__) && (__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__ == __RES_TYPE_BMP__)))
	#ifndef __MMI_RES_TYPE_SUBLCD_WALLPAPER__
	#define __MMI_RES_TYPE_SUBLCD_WALLPAPER__	"BMP"
	#endif
#elif ((defined(__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__) && (__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__ == __RES_TYPE_GIF__)) || !defined(__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__))
	#ifndef __MMI_RES_TYPE_SUBLCD_WALLPAPER__
	#define __MMI_RES_TYPE_SUBLCD_WALLPAPER__	"GIF"
	#endif
#elif (defined(__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__) && (__MMI_RES_TYPE_SUBLCD_WALLPAPER_SEL__ == __RES_TYPE_JPG__))
	#error "JPG is not allowed in SubLCD wallpaper"
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RES_TYPE_WALLPAPER_SEL)&&(CFG_MMI_RES_TYPE_WALLPAPER_SEL != __OFF__))
	#ifndef __MMI_RES_TYPE_WALLPAPER_SEL__
	#define __MMI_RES_TYPE_WALLPAPER_SEL__	CFG_MMI_RES_TYPE_WALLPAPER_SEL
	#endif
#endif


#if (((!defined(__MMI_FWUI_SLIM__)) && ((defined(__MMI_RES_TYPE_WALLPAPER_SEL__) && (__MMI_RES_TYPE_WALLPAPER_SEL__ == __RES_TYPE_BMP__)) || (defined(__MMI_VUI_LAUNCHER_KEY__)) || ((defined(__CPU_ARM7EJ_S__) && !defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)))))) || defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__))
	#ifndef __MMI_RES_TYPE_WALLPAPER__
	#define __MMI_RES_TYPE_WALLPAPER__	"BMP"
	#endif
#elif ((defined(__MMI_FWUI_SLIM__) || ((defined(__MMI_RES_TYPE_WALLPAPER_SEL__) && (__MMI_RES_TYPE_WALLPAPER_SEL__ == __RES_TYPE_JPG__)) || (!defined(__MMI_RES_TYPE_WALLPAPER_SEL__) &&  (defined(__MMI_MAINLCD_320X480__) || defined(__VENUS_UI_ENGINE__))))))
	#ifndef __MMI_RES_TYPE_WALLPAPER__
	#define __MMI_RES_TYPE_WALLPAPER__	"JPG"
	#endif
#elif (((defined(__MMI_RES_TYPE_WALLPAPER_SEL__) && (__MMI_RES_TYPE_WALLPAPER_SEL__ == __RES_TYPE_GIF__)) || !defined(__MMI_RES_TYPE_WALLPAPER_SEL__)))
	#ifndef __MMI_RES_TYPE_WALLPAPER__
	#define __MMI_RES_TYPE_WALLPAPER__	"GIF"
	#endif
#else
	#error "Wrong option"
#endif


#if (defined(CFG_MMI_RESOURCE_IMAGE_COMPRESS_RATE)&&(CFG_MMI_RESOURCE_IMAGE_COMPRESS_RATE != __OFF__))
	#ifndef __MMI_RESOURCE_IMAGE_COMPRESS_RATE__
	#define __MMI_RESOURCE_IMAGE_COMPRESS_RATE__	CFG_MMI_RESOURCE_IMAGE_COMPRESS_RATE
	#endif
#endif


#if (defined(__MMI_RESOURCE_IMAGE_COMPRESS_RATE__))
	#ifndef __MMI_RESOURCE_IMAGE_COMPRESS__
	#define __MMI_RESOURCE_IMAGE_COMPRESS__
	#endif
#endif


#if defined(CFG_MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS) && ((CFG_MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS == __ON__)||(CFG_MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS == __AUTO__))
	#if (defined(__NFB_THIRD_ROM_SUPPORT__))
	#error "Setting conflict, CFG_MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS should be disabled when __NFB_THIRD_ROM_SUPPORT__ is enabled"
	#endif
	#ifndef __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
	#define __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
	#endif
#endif


#if (defined(__NFB_THIRD_ROM_SUPPORT__)|| defined(__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__))
	#ifndef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	#define __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	#endif
#endif


#if (defined(__NFB_THIRD_ROM_SUPPORT__))
	#ifndef __MMI_RESOURCE_IMAGE_THIRD_ROM__
	#define __MMI_RESOURCE_IMAGE_THIRD_ROM__
	#endif
#endif


#if defined(CFG_MMI_RESOURCE_STR_COMPRESS) && ((CFG_MMI_RESOURCE_STR_COMPRESS == __ON__)||(CFG_MMI_RESOURCE_STR_COMPRESS == __AUTO__))
	#ifndef __MMI_RESOURCE_STR_COMPRESS__
	#define __MMI_RESOURCE_STR_COMPRESS__
	#endif
#endif


#if (defined(__NFB_THIRD_ROM_SUPPORT__)  && !defined(__CAT_SUPPORT__))
	#ifndef __MMI_RESOURCE_STR_THIRD_ROM__
	#define __MMI_RESOURCE_STR_THIRD_ROM__
	#endif
#endif


#if (defined(__DRM_SUPPORT__) && defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_RMGR__
	#define __MMI_RMGR__
	#endif
#endif


#if (defined(__DRM_SUPPORT__) && defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
	#define __MMI_RMGR_EXTEND_RIGHTS_AFTER_EXIT_AP__
	#endif
#endif


#if (defined(__DRM_SUPPORT__) && defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_RMGR_REPLACE_FILE_ICON__
	#define __MMI_RMGR_REPLACE_FILE_ICON__
	#endif
#endif


#if (defined(__DRM_SUPPORT__) && defined(__MMI_FILE_MANAGER__))
	#ifndef __MMI_RMGR_SIMPLE_DETAILS__
	#define __MMI_RMGR_SIMPLE_DETAILS__
	#endif
#endif


#if defined(CFG_MMI_RTC_TEST_SLIM) && ((CFG_MMI_RTC_TEST_SLIM == __ON__)||(CFG_MMI_RTC_TEST_SLIM == __AUTO__))
	#ifndef __MMI_RTC_TEST_SLIM__
	#define __MMI_RTC_TEST_SLIM__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_MRE) && ((CFG_MMI_VUI_WIDGET_MRE == __ON__)||(CFG_MMI_VUI_WIDGET_MRE == __AUTO__)) && \
	(defined(__MMI_VUI_ENGINE__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_VUI_WIDGET_MRE__
	#define __MMI_VUI_WIDGET_MRE__
	#endif
#endif


#if (defined(__MMI_VUI_WIDGET_MRE__) || defined(__MMI_VUI_LAUNCHER_MRE__) || defined(__MMI_VUI_SCREEN_LOCK_MRE__) || defined(__MMI_MRE_AUTO_START__))
	#ifndef __MMI_SAFE_MODE__
	#define __MMI_SAFE_MODE__
	#endif
#endif


#if defined(CFG_MMI_SAT_ULTRA_SLIM) && ((CFG_MMI_SAT_ULTRA_SLIM == __ON__)||(CFG_MMI_SAT_ULTRA_SLIM == __AUTO__))
	#ifndef __MMI_SAT_ULTRA_SLIM__
	#define __MMI_SAT_ULTRA_SLIM__
	#endif
#endif


#if defined(CFG_MMI_SAVE_CONTACT_REPLACE) && ((CFG_MMI_SAVE_CONTACT_REPLACE == __ON__)||(CFG_MMI_SAVE_CONTACT_REPLACE == __AUTO__))
	#ifndef __MMI_SAVE_CONTACT_REPLACE__
	#define __MMI_SAVE_CONTACT_REPLACE__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_KEY) && ((CFG_MMI_VUI_SCREEN_LOCK_KEY == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_KEY == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_FTE_SUPPORT__) && defined(__FANCY_PLUTO_APP_ON_VENUS_UI__) && defined(__MMI_VUI_ENGINE__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__)|| defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__)))
	#ifndef __MMI_VUI_SCREEN_LOCK_KEY__
	#define __MMI_VUI_SCREEN_LOCK_KEY__
	#endif
#endif


#if (defined( __MMI_VUI_SCREEN_LOCK_KEY__) && !defined(__MMI_FTE_SUPPORT_SLIM__))
	#ifndef __MMI_SCREEN_LOCK_ANY_TIME__
	#define __MMI_SCREEN_LOCK_ANY_TIME__
	#endif
#endif


#if (defined( __MMI_WEARABLE_DEVICE__))
	#ifndef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
	#define __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
	#endif
#endif


#if defined(CFG_MMI_VUI_SHELL_SCREEN_LOCK) && ((CFG_MMI_VUI_SHELL_SCREEN_LOCK == __ON__)||(CFG_MMI_VUI_SHELL_SCREEN_LOCK == __AUTO__)) && \
	((defined(__FANCY_PLUTO_APP_ON_VENUS_UI__) && defined(__MMI_VUI_ENGINE__) && defined(__MMI_TOUCH_SCREEN__)) &&  (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)))
	#ifndef __MMI_VUI_SHELL_SCREEN_LOCK__
	#define __MMI_VUI_SHELL_SCREEN_LOCK__
	#endif
#endif


#if (!defined(__MMI_VUI_SCREEN_LOCK_KEY__) && !defined(__MMI_VUI_SHELL_SCREEN_LOCK__))
	#ifndef __MMI_SCREEN_LOCK_CLASSIC__
	#define __MMI_SCREEN_LOCK_CLASSIC__
	#endif
#endif


#if defined(CFG_MMI_SCREEN_ROTATE) && ((CFG_MMI_SCREEN_ROTATE == __ON__)||(CFG_MMI_SCREEN_ROTATE == __AUTO__)) && \
	((!(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)) && (defined(HORIZONTAL_CAMERA) || (defined(JPG_DECODE) && (!defined(HORIZONTAL_CAMERA) && (defined(__MMI_IMAGE_VIEWER_STD__) ||  defined(__MMI_IMAGE_VIEWER_EX__) || defined(__MMI_SLIDESHOW__)))))) || (!(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)) && (defined(HORIZONTAL_CAMERA))) || defined(__COSMOS_MMI__))
	#ifndef __MMI_SCREEN_ROTATE__
	#define __MMI_SCREEN_ROTATE__
	#endif
#endif


#if defined(CFG_MMI_SCREEN_SAVER) && ((CFG_MMI_SCREEN_SAVER == __ON__)||(CFG_MMI_SCREEN_SAVER == __AUTO__)) && \
	(defined(__MMI_SCREEN_LOCK_CLASSIC__))
	#ifndef __MMI_SCREEN_SAVER__
	#define __MMI_SCREEN_SAVER__
	#endif
#endif


#if defined(CFG_MMI_SCREEN_SWITCH_EFFECT) && (CFG_MMI_SCREEN_SWITCH_EFFECT == __ON__) || \
	((defined(__COSMOS_MMI_PACKAGE__) || (defined(__MMI_FTE_SUPPORT__) && defined(__VENUS_UI_ENGINE__))) && !defined(__MMI_OP11_HOMESCREEN_VERSION__) && (CFG_MMI_SCREEN_SWITCH_EFFECT == __AUTO__))
	#ifndef __MMI_SCREEN_SWITCH_EFFECT__
	#define __MMI_SCREEN_SWITCH_EFFECT__
	#endif
#endif


#if ((defined(__COSMOS_MMI_PACKAGE__) || (defined(__MMI_FTE_SUPPORT__) && defined(__VENUS_UI_ENGINE__))) && !defined(__MMI_OP11_HOMESCREEN_VERSION__) && defined(__MMI_SCREEN_SWITCH_EFFECT__))
	#ifndef __MMI_SCREEN_SWITCH_EFFECT_VENUS__
	#define __MMI_SCREEN_SWITCH_EFFECT_VENUS__
	#endif
#endif


#if (!defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) && defined(__MMI_SCREEN_SWITCH_EFFECT__))
	#ifndef __MMI_SCREEN_SWITCH_EFFECT_PLUTO__
	#define __MMI_SCREEN_SWITCH_EFFECT_PLUTO__
	#endif
#endif


#if (defined(CFG_MMI_SCREEN_SWITCH_EFFECT_SETTING)) &&\
	 (defined(__MMI_SCREEN_SWITCH_EFFECT__))
	#ifndef __MMI_SCREEN_SWITCH_EFFECT_SETTING__
	#define __MMI_SCREEN_SWITCH_EFFECT_SETTING__	CFG_MMI_SCREEN_SWITCH_EFFECT_SETTING
	#endif
#endif


#if defined(CFG_MMI_SCREENSAVER_DISPLAY_VIDEO) && ((CFG_MMI_SCREENSAVER_DISPLAY_VIDEO == __ON__)||(CFG_MMI_SCREENSAVER_DISPLAY_VIDEO == __AUTO__)) && \
	((defined(MP4_DECODE) || (defined(MJPG_DECODE) && !defined(__DIRECT_SENSOR_SUPPORT__)) || defined(__RM_DEC_SUPPORT__)) && (!defined(__CPU_ARM7EJ_S__)) && defined(__MMI_VIDEO_PLAY_SUPPORT__))
	#ifndef __MMI_SCREENSAVER_DISPLAY_VIDEO__
	#define __MMI_SCREENSAVER_DISPLAY_VIDEO__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_SCRLOCKER_APP__
	#define __MMI_SCRLOCKER_APP__
	#endif
#endif


#if (defined(__MMI_SEARCH_WEB_BAIDU__) || defined(__MMI_SEARCH_WEB_GOOGLE__)|| defined(__MMI_GB_WINGUO__)|| defined(__MMI_GB_WINGUO_V2__))
	#ifndef __MMI_SEARCH_WEB__
	#define __MMI_SEARCH_WEB__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_SECSET_APP_SUPPORT__
	#define __MMI_SECSET_APP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SECSET_SLIM) && ((CFG_MMI_SECSET_SLIM == __ON__)||(CFG_MMI_SECSET_SLIM == __AUTO__))
	#ifndef __MMI_SECSET_SLIM__
	#define __MMI_SECSET_SLIM__
	#endif
#endif


#if (defined(__MMI_DIALER_SLIM__))
	#ifndef __MMI_SSC_SLIM__
	#define __MMI_SSC_SLIM__
	#endif
#endif


#if (defined(__MMI_SECSET_SLIM__) && defined(__MMI_SSC_SLIM__))
	#ifndef __MMI_SECSET_SLIM_FOR_61__
	#define __MMI_SECSET_SLIM_FOR_61__
	#endif
#endif


#if (!defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_SET_AS_RINGTONE_POPUP__
	#define __MMI_SET_AS_RINGTONE_POPUP__
	#endif
#endif


#if defined(CFG_MMI_SET_DEF_ENCODING_TYPE) && ((CFG_MMI_SET_DEF_ENCODING_TYPE == __ON__)||(CFG_MMI_SET_DEF_ENCODING_TYPE == __AUTO__))
	#ifndef __MMI_SET_DEF_ENCODING_TYPE__
	#define __MMI_SET_DEF_ENCODING_TYPE__
	#endif
#endif


#if defined(CFG_MMI_SETTING_SS_WAITTIME_SELECT) && ((CFG_MMI_SETTING_SS_WAITTIME_SELECT == __ON__)||(CFG_MMI_SETTING_SS_WAITTIME_SELECT == __AUTO__))
	#ifndef __MMI_SETTING_SS_WAITTIME_SELECT__
	#define __MMI_SETTING_SS_WAITTIME_SELECT__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_SETTINGS_SUPPORT__
	#define __MMI_SETTINGS_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SHOW_DAF_FILE_EXT) && ((CFG_MMI_SHOW_DAF_FILE_EXT == __ON__)||(CFG_MMI_SHOW_DAF_FILE_EXT == __AUTO__)) && \
	(!defined(FMT_NOT_PRESENT))
	#ifndef __MMI_SHOW_DAF_FILE_EXT__
	#define __MMI_SHOW_DAF_FILE_EXT__
	#endif
#endif


#if defined(CFG_MMI_SHOW_FILE_EXT) && ((CFG_MMI_SHOW_FILE_EXT == __ON__)||(CFG_MMI_SHOW_FILE_EXT == __AUTO__)) && \
	(!defined(FMT_NOT_PRESENT))
	#ifndef __MMI_SHOW_FILE_EXT__
	#define __MMI_SHOW_FILE_EXT__
	#endif
#endif


#if defined(CFG_MMI_SIM_CTRL_SLIM) && ((CFG_MMI_SIM_CTRL_SLIM == __ON__)||(CFG_MMI_SIM_CTRL_SLIM == __AUTO__))
	#ifndef __MMI_SIM_CTRL_SLIM__
	#define __MMI_SIM_CTRL_SLIM__
	#endif
#endif


#if (defined(__MMI_BT_SUPPORT__) && defined(__BT_SIM_PROFILE__))
	#ifndef __MMI_SIMAP_SUPPORT__
	#define __MMI_SIMAP_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SLIM_AUDIO_PLAYER) && ((CFG_MMI_SLIM_AUDIO_PLAYER == __ON__)||(CFG_MMI_SLIM_AUDIO_PLAYER == __AUTO__)) && \
	(defined(DAF_DECODE) && !defined(MED_V_NOT_PRESENT))
	#ifndef __MMI_SLIM_AUDIO_PLAYER__
	#define __MMI_SLIM_AUDIO_PLAYER__
	#endif
#endif


#if (defined(__EMAIL__) && defined(__NO_IMAP__))
	#ifndef __MMI_SLIM_EMAIL_NO_IMAP4__
	#define __MMI_SLIM_EMAIL_NO_IMAP4__
	#endif
#endif


#if (defined(__MMI_BASIC_UI_STYLE__))
	#ifndef __MMI_SLIM_LISTMENU__
	#define __MMI_SLIM_LISTMENU__
	#endif
#endif


#if (defined(__MMI_BASIC_UI_STYLE__) && defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_SLIM_LISTMENU_NO_ICON__
	#define __MMI_SLIM_LISTMENU_NO_ICON__
	#endif
#endif


#if (defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_SLIM_LISTMENU_NUMBER__
	#define __MMI_SLIM_LISTMENU_NUMBER__
	#endif
#endif


#if defined(CFG_MMI_SMALL_EDIT_SCREEN) && ((CFG_MMI_SMALL_EDIT_SCREEN == __ON__)||(CFG_MMI_SMALL_EDIT_SCREEN == __AUTO__)) && \
	((defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) && !defined(__MMI_TOUCH_SCREEN__)  && !(defined(__MMI_MAINLCD_320X240__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__) && defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_IME_SMART_WITH_INPUT_AREA__)))
	#ifndef __MMI_SMALL_EDIT_SCREEN__
	#define __MMI_SMALL_EDIT_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_SMALL_IMAGE_SELECTOR_SCREEN) && ((CFG_MMI_SMALL_IMAGE_SELECTOR_SCREEN == __ON__)||(CFG_MMI_SMALL_IMAGE_SELECTOR_SCREEN == __AUTO__)) && \
	((defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) && defined(__MMI_MESSAGES_EMS__))
	#ifndef __MMI_SMALL_IMAGE_SELECTOR_SCREEN__
	#define __MMI_SMALL_IMAGE_SELECTOR_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_SMALL_LIST_SCREEN) && ((CFG_MMI_SMALL_LIST_SCREEN == __ON__)||(CFG_MMI_SMALL_LIST_SCREEN == __AUTO__)) && \
	(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X480__))
	#ifndef __MMI_SMALL_LIST_SCREEN__
	#define __MMI_SMALL_LIST_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_SMALL_PIN_EDIT_SCREEN) && ((CFG_MMI_SMALL_PIN_EDIT_SCREEN == __ON__)||(CFG_MMI_SMALL_PIN_EDIT_SCREEN == __AUTO__)) && \
	(!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__))
	#ifndef __MMI_SMALL_PIN_EDIT_SCREEN__
	#define __MMI_SMALL_PIN_EDIT_SCREEN__
	#endif
#endif


#if defined(CFG_MMI_SMART_ALPHABETIC_RESELECTION) && ((CFG_MMI_SMART_ALPHABETIC_RESELECTION == __ON__)||(CFG_MMI_SMART_ALPHABETIC_RESELECTION == __AUTO__)) && \
	((defined(__MMI_ZI__) ||  defined(__MMI_T9__))&& (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_XT9__) ))
	#ifndef __MMI_SMART_ALPHABETIC_RESELECTION__
	#define __MMI_SMART_ALPHABETIC_RESELECTION__
	#endif
#endif


#if defined(CFG_MMI_SML_MENU) && ((CFG_MMI_SML_MENU == __ON__)||(CFG_MMI_SML_MENU == __AUTO__)) && \
	(defined(__SIM_ME_LOCK__))
	#ifndef __MMI_SML_MENU__
	#define __MMI_SML_MENU__
	#endif
#endif


#if (defined(__MMI_MESSAGES_EMS__) && !defined(__SLIM_EMS__) && !defined(__UNIFIED_COMPOSER_SUPPORT__))
	#ifndef __MMI_SMS_APP_EMS_SUPPORT__
	#define __MMI_SMS_APP_EMS_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SMS_SLIM) && (CFG_MMI_SMS_SLIM == __ON__) || \
	((CFG_MMI_SMS_SLIM == __AUTO__) && (defined(__PLUTO_MMI_PACKAGE__) || defined(__MMI_MESSAGE_SLIM__)))
	#ifndef __MMI_SMS_SLIM__
	#define __MMI_SMS_SLIM__
	#endif
#endif


#if (defined(__MMI_SMS_SLIM__))
	#ifndef __MMI_SMS_BOX_ICON_SLIM__
	#define __MMI_SMS_BOX_ICON_SLIM__
	#endif
#endif


#if (defined(__MMI_SMS_SLIM__))
	#ifndef __MMI_SMS_CLASS0_MSG_SLIM__
	#define __MMI_SMS_CLASS0_MSG_SLIM__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined (__UNIFIED_COMPOSER_SUPPORT__))
	#ifndef __MMI_SMS_COMPOSER__
	#define __MMI_SMS_COMPOSER__
	#endif
#endif


#if (!defined(__MMI_SMS_SLIM__) || !defined(__MMI_BRIEF_TEXT__) || !defined(__MMI_SLIM_IMG_RES__))
	#ifndef __MMI_SMS_COUNTER__
	#define __MMI_SMS_COUNTER__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_SMS_CUI_SUPPORT__
	#define __MMI_SMS_CUI_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SMS_DETAILS_INFO) && ((CFG_MMI_SMS_DETAILS_INFO == __ON__)||(CFG_MMI_SMS_DETAILS_INFO == __AUTO__)) && \
	(!defined(__MMI_MESSAGES_SMS_EMAIL__))
	#ifndef __MMI_SMS_DETAILS_INFO__
	#define __MMI_SMS_DETAILS_INFO__
	#endif
#endif


#if (defined (__MMI_VCARD__)) ||\
	 (defined (__MMI_VCALENDAR__))
	#ifndef __MMI_SMS_PORT_MSG__
	#define __MMI_SMS_PORT_MSG__
	#endif
#endif


#if (defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) && (defined(__OP01__) || (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || defined(__MMI_SMS_TCARD_STORAGE_SUPPORT__))))
	#ifndef __MMI_SMS_PREFER_STORAGE_SETTING__
	#define __MMI_SMS_PREFER_STORAGE_SETTING__
	#endif
#endif


#if defined(CFG_MMI_SMS_SET_AS_REMINDER) && ((CFG_MMI_SMS_SET_AS_REMINDER == __ON__)||(CFG_MMI_SMS_SET_AS_REMINDER == __AUTO__)) && \
	(defined(__MMI_TODOLIST__))
	#ifndef __MMI_SMS_SET_AS_REMINDER__
	#define __MMI_SMS_SET_AS_REMINDER__
	#endif
#endif


#if (defined(__MMI_SMS_SLIM__))
	#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
	#define __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
	#endif
#endif


#if (defined(__MMI_SMS_SLIM__))
	#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
	#define __MMI_SMS_SETTINGS_VP_SLIM__
	#endif
#endif


#if defined(CFG_MMI_SMS_SWITCH_MSG_READ_STATUS) && ((CFG_MMI_SMS_SWITCH_MSG_READ_STATUS == __ON__)||(CFG_MMI_SMS_SWITCH_MSG_READ_STATUS == __AUTO__)) && \
	(!defined (__MMI_UM_CONVERSATION_BOX_ENHANCE__))
	#ifndef __MMI_SMS_SWITCH_MSG_READ_STATUS__
	#define __MMI_SMS_SWITCH_MSG_READ_STATUS__
	#endif
#endif


#if (defined(__MMI_SMS_SLIM__))
	#ifndef __MMI_SMS_VOICEMAIL_SLIM__
	#define __MMI_SMS_VOICEMAIL_SLIM__
	#endif
#endif


#if (defined(__MMI_SOUND_RECORDER__) && (defined(__MMI_FTE_SUPPORT__) || !(defined(__MMI_FWUI_SLIM__) || defined(__MMI_MAINLCD_96X64__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__))))
	#ifndef __MMI_SNDREC_SKIN__
	#define __MMI_SNDREC_SKIN__
	#endif
#endif


#if defined(CFG_MMI_SNDREC_SLIM) && ((CFG_MMI_SNDREC_SLIM == __ON__)||(CFG_MMI_SNDREC_SLIM == __AUTO__)) && \
	(defined(__MMI_SOUND_RECORDER__))
	#ifndef __MMI_SNDREC_SLIM__
	#define __MMI_SNDREC_SLIM__
	#endif
#endif


#if defined(CFG_MMI_SNDREC_SLIM_SETTINGS) && ((CFG_MMI_SNDREC_SLIM_SETTINGS == __ON__)||(CFG_MMI_SNDREC_SLIM_SETTINGS == __AUTO__)) && \
	(defined(__MMI_SNDREC_SLIM__))
	#ifndef __MMI_SNDREC_SLIM_SETTINGS__
	#define __MMI_SNDREC_SLIM_SETTINGS__
	#endif
#endif


#if defined(CFG_MMI_SNS_ALBUM) && ((CFG_MMI_SNS_ALBUM == __ON__)||(CFG_MMI_SNS_ALBUM == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_SNS_ALBUM__
	#define __MMI_SNS_ALBUM__
	#endif
#endif


#if defined(CFG_MMI_SNS_CALENDAR) && ((CFG_MMI_SNS_CALENDAR == __ON__)||(CFG_MMI_SNS_CALENDAR == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__) && (defined(__MMI_CALENDAR_EVENT__) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_SNS_CALENDAR__
	#define __MMI_SNS_CALENDAR__
	#endif
#endif


#if (!defined(__LOW_COST_SUPPORT_COMMON__) && defined(__MMI_SNS_CENTER__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_SNS_CENTER_TAKE_PHOTO__
	#define __MMI_SNS_CENTER_TAKE_PHOTO__
	#endif
#endif


#if defined(CFG_MMI_SNS_CONTACTS) && ((CFG_MMI_SNS_CONTACTS == __ON__)||(CFG_MMI_SNS_CONTACTS == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__) && (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_PHB_UI_IN_TABS__)))
	#ifndef __MMI_SNS_CONTACTS__
	#define __MMI_SNS_CONTACTS__
	#endif
#endif


#if defined(CFG_MMI_SNS_MESSAGES) && ((CFG_MMI_SNS_MESSAGES == __ON__)||(CFG_MMI_SNS_MESSAGES == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__) && (!defined(__FACEBOOK_SNS_SUPPORT__) && !defined(__TWITTER_SNS_SUPPORT__)))
	#ifndef __MMI_SNS_MESSAGES__
	#define __MMI_SNS_MESSAGES__
	#endif
#endif


#if defined(CFG_MMI_SNS_PHOTO_UPLOAD) && ((CFG_MMI_SNS_PHOTO_UPLOAD == __ON__)||(CFG_MMI_SNS_PHOTO_UPLOAD == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_SNS_PHOTO_UPLOAD__
	#define __MMI_SNS_PHOTO_UPLOAD__
	#endif
#endif


#if defined(CFG_MMI_SNS_PRELOAD_FACEBOOK) && ((CFG_MMI_SNS_PRELOAD_FACEBOOK == __ON__)||(CFG_MMI_SNS_PRELOAD_FACEBOOK == __AUTO__)) && \
	(defined(__FACEBOOK_SNS_SUPPORT__))
	#ifndef __MMI_SNS_PRELOAD_FACEBOOK__
	#define __MMI_SNS_PRELOAD_FACEBOOK__
	#endif
#endif


#if defined(CFG_MMI_SNS_PRELOAD_RENREN) && ((CFG_MMI_SNS_PRELOAD_RENREN == __ON__)||(CFG_MMI_SNS_PRELOAD_RENREN == __AUTO__))
	#ifndef __MMI_SNS_PRELOAD_RENREN__
	#define __MMI_SNS_PRELOAD_RENREN__
	#endif
#endif


#if defined(CFG_MMI_SNS_PRELOAD_TWITTER) && ((CFG_MMI_SNS_PRELOAD_TWITTER == __ON__)||(CFG_MMI_SNS_PRELOAD_TWITTER == __AUTO__)) && \
	(defined(__TWITTER_SNS_SUPPORT__))
	#ifndef __MMI_SNS_PRELOAD_TWITTER__
	#define __MMI_SNS_PRELOAD_TWITTER__
	#endif
#endif


#if defined(CFG_MMI_SNS_VPP_UPGRADE) && ((CFG_MMI_SNS_VPP_UPGRADE == __ON__)||(CFG_MMI_SNS_VPP_UPGRADE == __AUTO__)) && \
	(defined(__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_SNS_VPP_UPGRADE__
	#define __MMI_SNS_VPP_UPGRADE__
	#endif
#endif


#if (defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_REVERB_EFFECT__) || (defined(__MMI_BG_SOUND_EFFECT__) && !defined(__UCM_SUPPORT__)) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_BASS_ENHANCEMENT__))
	#ifndef __MMI_SOUND_EFFECT__
	#define __MMI_SOUND_EFFECT__
	#endif
#endif


#if (!defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_SOUNDREC_CUI__
	#define __MMI_SOUNDREC_CUI__
	#endif
#endif


#if defined(CFG_MMI_SOUNDREC_SLIM) && ((CFG_MMI_SOUNDREC_SLIM == __ON__)||(CFG_MMI_SOUNDREC_SLIM == __AUTO__))
	#ifndef __MMI_SOUNDREC_SLIM__
	#define __MMI_SOUNDREC_SLIM__
	#endif
#endif


#if defined(CFG_MMI_SRV_IES_META) && ((CFG_MMI_SRV_IES_META == __ON__)||(CFG_MMI_SRV_IES_META == __AUTO__)) && \
	(defined(__MMI_SRV_IES__))
	#ifndef __MMI_SRV_IES_META__
	#define __MMI_SRV_IES_META__
	#endif
#endif


#if defined(CFG_MMI_SRV_IES_META_DB) && ((CFG_MMI_SRV_IES_META_DB == __ON__)||(CFG_MMI_SRV_IES_META_DB == __AUTO__)) && \
	(defined(__MMI_SRV_IES_META__))
	#ifndef __MMI_SRV_IES_META_DB__
	#define __MMI_SRV_IES_META_DB__
	#endif
#endif


#if ((defined(__MMI_IMAGE_VIEWER_EX__) || defined(__MMI_IMAGE_VIEWER_EX_DB__)) && defined(__VENUS_UI_ENGINE__) && defined(__MMI_FTE_SUPPORT__) && defined(__FS_SORT_SUPPORT__))
	#ifndef __MMI_VUI_MEDIAWALL__
	#define __MMI_VUI_MEDIAWALL__
	#endif
#endif


#if (defined(__MMI_IMAGE_VIEWER_EX__) || defined(__MMI_IMAGE_VIEWER_EX_DB__) || defined(__MMI_VUI_MEDIAWALL__) || defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__) || defined(__MMI_FTO_GALLERY__))
	#ifndef __MMI_SRV_MEDIACACHE__
	#define __MMI_SRV_MEDIACACHE__
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_SSC_CUI_SUPPORT__
	#define __MMI_SSC_CUI_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SSO_OOBE) && ((CFG_MMI_SSO_OOBE == __ON__)||(CFG_MMI_SSO_OOBE == __AUTO__))
	#if (!defined(__MMI_SSO__))
	#error "It should turn on __MMI_SSO__ or disable __MMI_SSO_OOBE__"
	#endif
	#ifndef __MMI_SSO_OOBE__
	#define __MMI_SSO_OOBE__
	#endif
#endif


#if defined(CFG_MMI_SSO_VPP_UPGRADE) && ((CFG_MMI_SSO_VPP_UPGRADE == __ON__)||(CFG_MMI_SSO_VPP_UPGRADE == __AUTO__))
	#if (!defined(__MMI_SSO__))
	#error "It should turn on __MMI_SSO__ or disable __MMI_SSO_VPP_UPGRADE__"
	#endif
	#ifndef __MMI_SSO_VPP_UPGRADE__
	#define __MMI_SSO_VPP_UPGRADE__
	#endif
#endif


#if defined(CFG_MMI_STATUS_BAR_NO_UNDERLINE) && ((CFG_MMI_STATUS_BAR_NO_UNDERLINE == __ON__)||(CFG_MMI_STATUS_BAR_NO_UNDERLINE == __AUTO__))
	#ifndef __MMI_STATUS_BAR_NO_UNDERLINE__
	#define __MMI_STATUS_BAR_NO_UNDERLINE__
	#endif
#endif


#if defined(CFG_MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH) && (CFG_MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH == __ON__) || \
	(defined(__GEMINI__))
	#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
	#define __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	#define __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	#endif
#endif


#if (defined(__MMI_VIDEO_STREAM__) && (defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER__)))
	#ifndef __MMI_STREAMING__
	#define __MMI_STREAMING__
	#endif
#endif


#if defined(CFG_MMI_STREAMING_OTAP) && ((CFG_MMI_STREAMING_OTAP == __ON__)||(CFG_MMI_STREAMING_OTAP == __AUTO__)) && \
	(defined(__MMI_STREAMING__) && defined(__MMI_CCA_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_STREAMING_OTAP__
	#define __MMI_STREAMING_OTAP__
	#endif
#endif


#if (defined(MMI_SUB_LCD_DEFAULT_FORMAT) && (MMI_SUB_LCD_DEFAULT_FORMAT == 24))
	#ifndef __MMI_SUB_BASE_LAYER_FORMAT__
	#define __MMI_SUB_BASE_LAYER_FORMAT__	GDI_COLOR_FORMAT_24
	#endif
#elif (defined(MMI_SUB_LCD_DEFAULT_FORMAT) && (MMI_SUB_LCD_DEFAULT_FORMAT == 32))
	#ifndef __MMI_SUB_BASE_LAYER_FORMAT__
	#define __MMI_SUB_BASE_LAYER_FORMAT__	GDI_COLOR_FORMAT_32
	#endif
#else
	#ifndef __MMI_SUB_BASE_LAYER_FORMAT__
	#define __MMI_SUB_BASE_LAYER_FORMAT__	GDI_COLOR_FORMAT_16
	#endif
#endif


#if defined(CFG_MMI_SUB_WALLPAPER) && ((CFG_MMI_SUB_WALLPAPER == __ON__)||(CFG_MMI_SUB_WALLPAPER == __AUTO__)) && \
	(defined(DUAL_LCD) && defined(COLOR_SUBLCD))
	#ifndef __MMI_SUB_WALLPAPER__
	#define __MMI_SUB_WALLPAPER__
	#endif
#endif


#if (defined(DUAL_LCD))
	#ifndef __MMI_SUBLCD__
	#define __MMI_SUBLCD__
	#endif
#endif


#if (defined(DUAL_LCD) && defined(COLOR_SUBLCD))
	#ifndef __MMI_SUBLCD_COLOR__
	#define __MMI_SUBLCD_COLOR__
	#endif
#endif


#if defined(CFG_MMI_SUBLCD_SHOW_DATE) && ((CFG_MMI_SUBLCD_SHOW_DATE == __ON__)||(CFG_MMI_SUBLCD_SHOW_DATE == __AUTO__)) && \
	(defined(DUAL_LCD))
	#ifndef __MMI_SUBLCD_SHOW_DATE__
	#define __MMI_SUBLCD_SHOW_DATE__
	#endif
#endif


#if defined(CFG_MMI_SUBLCD_SHOW_ONE_CITY) && ((CFG_MMI_SUBLCD_SHOW_ONE_CITY == __ON__)||(CFG_MMI_SUBLCD_SHOW_ONE_CITY == __AUTO__)) && \
	(defined(DUAL_LCD))
	#ifndef __MMI_SUBLCD_SHOW_ONE_CITY__
	#define __MMI_SUBLCD_SHOW_ONE_CITY__
	#endif
#endif


#if defined(CFG_MMI_SUBLCD_SHOW_TIME) && ((CFG_MMI_SUBLCD_SHOW_TIME == __ON__)||(CFG_MMI_SUBLCD_SHOW_TIME == __AUTO__)) && \
	(defined(DUAL_LCD))
	#ifndef __MMI_SUBLCD_SHOW_TIME__
	#define __MMI_SUBLCD_SHOW_TIME__
	#endif
#endif


#if defined(CFG_MMI_SUPPORT_ASMV2) && (CFG_MMI_SUPPORT_ASMV2 == __ON__) || \
	(defined(__MCAREV31__))
	#ifndef __MMI_SUPPORT_ASMV2__
	#define __MMI_SUPPORT_ASMV2__
	#endif
#endif


#if defined(CFG_MMI_SUPPORT_DUMP_SCREEN_STRING) && ((CFG_MMI_SUPPORT_DUMP_SCREEN_STRING == __ON__)||(CFG_MMI_SUPPORT_DUMP_SCREEN_STRING == __AUTO__))
	#ifndef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	#define __MMI_SUPPORT_DUMP_SCREEN_STRING__
	#endif
#endif


#if defined(CFG_MMI_SYNC_LCD_GPIO_MODE) && ((CFG_MMI_SYNC_LCD_GPIO_MODE == __ON__)||(CFG_MMI_SYNC_LCD_GPIO_MODE == __AUTO__)) && \
	(defined(__MMI_CLAMSHELL__))
	#ifndef __MMI_SYNC_LCD_GPIO_MODE__
	#define __MMI_SYNC_LCD_GPIO_MODE__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_APP_SYNC_MENU_SUPPORT) && ((CFG_MMI_SYNCML_APP_SYNC_MENU_SUPPORT == __ON__)||(CFG_MMI_SYNCML_APP_SYNC_MENU_SUPPORT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__))
	#ifndef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
	#define __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_CCA_SUPPORT) && ((CFG_MMI_SYNCML_CCA_SUPPORT == __ON__)||(CFG_MMI_SYNCML_CCA_SUPPORT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__) && defined(__MMI_CCA_SUPPORT__))
	#ifndef __MMI_SYNCML_CCA_SUPPORT__
	#define __MMI_SYNCML_CCA_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_DATA_CHANGE_SYNC_DELAY) && ((CFG_MMI_SYNCML_DATA_CHANGE_SYNC_DELAY == __ON__)||(CFG_MMI_SYNCML_DATA_CHANGE_SYNC_DELAY == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__))
	#ifndef __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
	#define __MMI_SYNCML_DATA_CHANGE_SYNC_DELAY__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_SYNC_CALENDAR_SUPPORT) && ((CFG_MMI_SYNCML_SYNC_CALENDAR_SUPPORT == __ON__)||(CFG_MMI_SYNCML_SYNC_CALENDAR_SUPPORT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__) && ((defined(__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	#define __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_DEVICE_SYNC) && ((CFG_MMI_SYNCML_DEVICE_SYNC == __ON__)||(CFG_MMI_SYNCML_DEVICE_SYNC == __AUTO__)) && \
	(defined(__SYNCML_DEVICE_SYNC__))
	#ifndef __MMI_SYNCML_DEVICE_SYNC__
	#define __MMI_SYNCML_DEVICE_SYNC__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_DEVICE_CALENDAR_SUPPORT) && ((CFG_MMI_SYNCML_DEVICE_CALENDAR_SUPPORT == __ON__)||(CFG_MMI_SYNCML_DEVICE_CALENDAR_SUPPORT == __AUTO__)) && \
	(defined(__MMI_SYNCML_SYNC_CALENDAR_SUPPORT__) && defined(__MMI_SYNCML_DEVICE_SYNC__))
	#ifndef __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
	#define __MMI_SYNCML_DEVICE_CALENDAR_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_SYNC_TASK_SUPPORT) && ((CFG_MMI_SYNCML_SYNC_TASK_SUPPORT == __ON__)||(CFG_MMI_SYNCML_SYNC_TASK_SUPPORT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__) && ((defined(__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	#define __MMI_SYNCML_SYNC_TASK_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_DEVICE_TASK_SUPPORT) && ((CFG_MMI_SYNCML_DEVICE_TASK_SUPPORT == __ON__)||(CFG_MMI_SYNCML_DEVICE_TASK_SUPPORT == __AUTO__)) && \
	(defined(__MMI_SYNCML_SYNC_TASK_SUPPORT__) && defined(__MMI_SYNCML_DEVICE_SYNC__))
	#ifndef __MMI_SYNCML_DEVICE_TASK_SUPPORT__
	#define __MMI_SYNCML_DEVICE_TASK_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_PC_SYNC_SUPPORT) && ((CFG_MMI_SYNCML_PC_SYNC_SUPPORT == __ON__)||(CFG_MMI_SYNCML_PC_SYNC_SUPPORT == __AUTO__)) && \
	(defined (__SYNCML_PC_SYNC_SUPPORT__))
	#ifndef __MMI_SYNCML_PC_SYNC_SUPPORT__
	#define __MMI_SYNCML_PC_SYNC_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_RESTORE_FACTORY_DEFAULT) && ((CFG_MMI_SYNCML_RESTORE_FACTORY_DEFAULT == __ON__)||(CFG_MMI_SYNCML_RESTORE_FACTORY_DEFAULT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__))
	#ifndef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
	#define __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_STATUS_ICON_SUPPORT) && ((CFG_MMI_SYNCML_STATUS_ICON_SUPPORT == __ON__)||(CFG_MMI_SYNCML_STATUS_ICON_SUPPORT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__))
	#ifndef __MMI_SYNCML_STATUS_ICON_SUPPORT__
	#define __MMI_SYNCML_STATUS_ICON_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_SYNC_NOTE_SUPPORT) && ((CFG_MMI_SYNCML_SYNC_NOTE_SUPPORT == __ON__)||(CFG_MMI_SYNCML_SYNC_NOTE_SUPPORT == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__) && defined(__MMI_NOTE_APP__) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	#define __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_SYNCML_VF_DATA_CHANGE_SYNC) && ((CFG_MMI_SYNCML_VF_DATA_CHANGE_SYNC == __ON__)||(CFG_MMI_SYNCML_VF_DATA_CHANGE_SYNC == __AUTO__)) && \
	(defined(__SYNCML_SUPPORT__))
	#ifndef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
	#define __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
	#endif
#endif


#if (defined(__MMI_IME_HANDWRITING_AFRIKAANS__) && defined(__MMI_PENPOWER__))
	#ifndef __MMI_T9_AFRIKAANS__
	#define __MMI_T9_AFRIKAANS__
	#endif
#endif


#if (defined(__MMI_IME_ALBANIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ALBANIAN__
	#define __MMI_T9_ALBANIAN__
	#endif
#endif


#if (defined(__MMI_IME_AMB_BPMF_INPUT__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_AMB_BPMF_INPUT__
	#define __MMI_T9_AMB_BPMF_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_ARABIC__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ARABIC__
	#define __MMI_T9_ARABIC__
	#endif
#endif


#if (defined(__MMI_IME_ASSAMESE__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ASSAMESE__
	#define __MMI_T9_ASSAMESE__
	#endif
#endif


#if (defined(__MMI_IME_AZERBAIJANI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_AZERBAIJANI__
	#define __MMI_T9_AZERBAIJANI__
	#endif
#endif


#if (defined(__MMI_IME_BASQUE__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_BASQUE__
	#define __MMI_T9_BASQUE__
	#endif
#endif


#if (defined(__MMI_IME_BENGALI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_BENGALI__
	#define __MMI_T9_BENGALI__
	#endif
#endif


#if (defined(__MMI_IME_BULGARIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_BULGARIAN__
	#define __MMI_T9_BULGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_CATALAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_CATALAN__
	#define __MMI_T9_CATALAN__
	#endif
#endif


#if (defined(__MMI_IME_CROATIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_CROATIAN__
	#define __MMI_T9_CROATIAN__
	#endif
#endif


#if (defined(__MMI_IME_CZECH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_CZECH__
	#define __MMI_T9_CZECH__
	#endif
#endif


#if (defined(__MMI_IME_DANISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_DANISH__
	#define __MMI_T9_DANISH__
	#endif
#endif


#if (defined(__MMI_IME_DUTCH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_DUTCH__
	#define __MMI_T9_DUTCH__
	#endif
#endif


#if (defined(__MMI_IME_ENGLISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ENGLISH__
	#define __MMI_T9_ENGLISH__
	#endif
#endif


#if (defined(__MMI_IME_ESTONIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ESTONIAN__
	#define __MMI_T9_ESTONIAN__
	#endif
#endif


#if (defined(__MMI_IME_FINNISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_FINNISH__
	#define __MMI_T9_FINNISH__
	#endif
#endif


#if (defined(__MMI_IME_FRENCH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_FRENCH__
	#define __MMI_T9_FRENCH__
	#endif
#endif


#if (defined(__MMI_IME_GALICIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_GALICIAN__
	#define __MMI_T9_GALICIAN__
	#endif
#endif


#if (defined(__MMI_IME_GEORGIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_GEORGIAN__
	#define __MMI_T9_GEORGIAN__
	#endif
#endif


#if (defined(__MMI_IME_GERMAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_GERMAN__
	#define __MMI_T9_GERMAN__
	#endif
#endif


#if (defined(__MMI_IME_GREEK__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_GREEK__
	#define __MMI_T9_GREEK__
	#endif
#endif


#if (defined(__MMI_IME_GUJARATI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_GUJARATI__
	#define __MMI_T9_GUJARATI__
	#endif
#endif


#if (defined(__MMI_IME_HAUSA__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_HAUSA__
	#define __MMI_T9_HAUSA__
	#endif
#endif


#if (defined(__MMI_IME_HEBREW__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_HEBREW__
	#define __MMI_T9_HEBREW__
	#endif
#endif


#if (defined(__MMI_IME_HINDI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_HINDI__
	#define __MMI_T9_HINDI__
	#endif
#endif


#if (defined(__MMI_IME_HKCHINESE__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_HK_CHINESE__
	#define __MMI_T9_HK_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_HUNGARIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_HUNGARIAN__
	#define __MMI_T9_HUNGARIAN__
	#endif
#endif


#if (defined(__MMI_IME_ICELANDIC__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ICELANDIC__
	#define __MMI_T9_ICELANDIC__
	#endif
#endif


#if (defined(__MMI_IME_IGBO__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_IGBO__
	#define __MMI_T9_IGBO__
	#endif
#endif


#if (defined(__MMI_IME_INDONESIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_INDONESIAN__
	#define __MMI_T9_INDONESIAN__
	#endif
#endif


#if (defined(__MMI_IME_IRISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_IRISH__
	#define __MMI_T9_IRISH__
	#endif
#endif


#if (defined(__MMI_IME_ITALIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ITALIAN__
	#define __MMI_T9_ITALIAN__
	#endif
#endif


#if (defined(__MMI_IME_KANNADA__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_KANNADA__
	#define __MMI_T9_KANNADA__
	#endif
#endif


#if (defined(__MMI_IME_KAZAKH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_KAZAKH__
	#define __MMI_T9_KAZAKH__
	#endif
#endif


#if (defined(__MMI_IME_KHMER__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_KHMER__
	#define __MMI_T9_KHMER__
	#endif
#endif


#if (defined(__MMI_IME_LATVIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_LATVIAN__
	#define __MMI_T9_LATVIAN__
	#endif
#endif


#if (defined(__MMI_IME_LITHUANIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_LITHUANIAN__
	#define __MMI_T9_LITHUANIAN__
	#endif
#endif


#if (defined(__MMI_IME_MACEDONIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_MACEDONIAN__
	#define __MMI_T9_MACEDONIAN__
	#endif
#endif


#if (defined(__MMI_IME_MALAY__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_MALAY__
	#define __MMI_T9_MALAY__
	#endif
#endif


#if (defined(__MMI_IME_MALAYALAM__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_MALAYALAM__
	#define __MMI_T9_MALAYALAM__
	#endif
#endif


#if (defined(__MMI_IME_MARATHI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_MARATHI__
	#define __MMI_T9_MARATHI__
	#endif
#endif


#if (defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__)  && (defined __MMI_T9__ ))
	#ifndef __MMI_T9_MULTITAP_PHONETIC_INPUT__
	#define __MMI_T9_MULTITAP_PHONETIC_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_NORWEGIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_NORWEGIAN__
	#define __MMI_T9_NORWEGIAN__
	#endif
#endif


#if (defined(__MMI_IME_ORIYA__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ORIYA__
	#define __MMI_T9_ORIYA__
	#endif
#endif


#if (defined(__MMI_IME_PERSIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_PERSIAN__
	#define __MMI_T9_PERSIAN__
	#endif
#endif


#if (defined(__MMI_IME_POLISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_POLISH__
	#define __MMI_T9_POLISH__
	#endif
#endif


#if (defined(__MMI_IME_PORTUGUESE__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_PORTUGUESE__
	#define __MMI_T9_PORTUGUESE__
	#endif
#endif


#if (defined(__MMI_IME_PUNJABI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_PUNJABI__
	#define __MMI_T9_PUNJABI__
	#endif
#endif


#if (defined(__MMI_IME_ROMANIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ROMANIAN__
	#define __MMI_T9_ROMANIAN__
	#endif
#endif


#if (defined(__MMI_IME_RUSSIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_RUSSIAN__
	#define __MMI_T9_RUSSIAN__
	#endif
#endif


#if (defined(__MMI_IME_SERBIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SERBIAN__
	#define __MMI_T9_SERBIAN__
	#endif
#endif


#if (defined(__MMI_IME_SESOTHO__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SESOTHO__
	#define __MMI_T9_SESOTHO__
	#endif
#endif


#if (defined(__MMI_IME_SLOVAK__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SLOVAK__
	#define __MMI_T9_SLOVAK__
	#endif
#endif


#if (defined(__MMI_IME_SLOVENIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SLOVENIAN__
	#define __MMI_T9_SLOVENIAN__
	#endif
#endif


#if (defined(__MMI_IME_SM_CHINESE__)   && defined(__MMI_T9__))
	#ifndef __MMI_T9_SM_CHINESE__
	#define __MMI_T9_SM_CHINESE__
	#endif
#endif


#if (defined(__MMI_T9__) && defined(__MMI_SMART_PHONETIC_INPUT_METHODS__))
	#ifndef __MMI_T9_SMART_PHONETIC_INPUT__
	#define __MMI_T9_SMART_PHONETIC_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_SPANISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SPANISH__
	#define __MMI_T9_SPANISH__
	#endif
#endif


#if (defined(__MMI_IME_STROKE_INPUT__)  && (defined(__MMI_T9__) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)|| defined(__MMI_IME_ALPHANUMERIC_VK_SUPPORT__))))
	#ifndef __MMI_T9_STROKE_INPUT__
	#define __MMI_T9_STROKE_INPUT__
	#endif
#endif


#if (defined(__MMI_IME_SWAHILI__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SWAHILI__
	#define __MMI_T9_SWAHILI__
	#endif
#endif


#if (defined(__MMI_IME_SWEDISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_SWEDISH__
	#define __MMI_T9_SWEDISH__
	#endif
#endif


#if (defined(__MMI_IME_TAGALOG__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_TAGALOG__
	#define __MMI_T9_TAGALOG__
	#endif
#endif


#if (defined(__MMI_IME_TAMIL__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_TAMIL__
	#define __MMI_T9_TAMIL__
	#endif
#endif


#if (defined(__MMI_IME_TELUGU__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_TELUGU__
	#define __MMI_T9_TELUGU__
	#endif
#endif


#if (defined(__MMI_IME_TR_CHINESE__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_TR_CHINESE__
	#define __MMI_T9_TR_CHINESE__
	#endif
#endif


#if (defined(__MMI_IME_TURKISH__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_TURKISH__
	#define __MMI_T9_TURKISH__
	#endif
#endif


#if (defined(__MMI_IME_UKRAINIAN__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_UKRAINIAN__
	#define __MMI_T9_UKRAINIAN__
	#endif
#endif


#if (defined(__MMI_IME_URDU__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_URDU__
	#define __MMI_T9_URDU__
	#endif
#endif


#if (defined(__MMI_IME_VIETNAMESE__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_VIETNAMESE__
	#define __MMI_T9_VIETNAMESE__
	#endif
#endif


#if (defined(__MMI_IME_XHOSA__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_XHOSA__
	#define __MMI_T9_XHOSA__
	#endif
#endif


#if (defined(__MMI_IME_YORUBA__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_YORUBA__
	#define __MMI_T9_YORUBA__
	#endif
#endif


#if (defined(__MMI_IME_ZULU__) && defined(__MMI_T9__))
	#ifndef __MMI_T9_ZULU__
	#define __MMI_T9_ZULU__
	#endif
#endif


#if (defined(__MMI_TAB_BARS_SUPPORT__))
	#ifndef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	#define __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	#endif
#endif


#if defined(CFG_MMI_TDL_NITZ_SUPPORT) && ((CFG_MMI_TDL_NITZ_SUPPORT == __ON__)||(CFG_MMI_TDL_NITZ_SUPPORT == __AUTO__)) && \
	(defined(__MMI_NITZ__) && (defined(__MMI_CALENDAR__) || defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_TDL_NITZ_SUPPORT__
	#define __MMI_TDL_NITZ_SUPPORT__
	#endif
#endif


#if (!defined(TELEPHONY_APP_NOT_PRESENT) && !defined(__BT_PRODUCT_LINE_BT_DIALER_BTONLY_W_PS__))
	#ifndef __MMI_TELEPHONY_SUPPORT__
	#define __MMI_TELEPHONY_SUPPORT__
	#endif
#endif


#if (defined(__HOTSPOT_SUPPORT__) && defined(__CUSTOM_WIFI_FEATURES_SWITCH__))
	#ifndef __MMI_TETHERING_WIFI__
	#define __MMI_TETHERING_WIFI__
	#endif
#endif


#if (defined(__MMI_TETHERING_WIFI__) || defined(__USB_TETHERING__))
	#ifndef __MMI_TETHERING__
	#define __MMI_TETHERING__
	#endif
#endif


#if (defined(CFG_MMI_THEME_MAX_NUMBER)) &&\
	 (!defined(__MMI_THEMES_APPLICATION__))
	#ifndef __MMI_THEME_MAX_NUMBER__
	#define __MMI_THEME_MAX_NUMBER__	1
	#endif
#elif (defined(CFG_MMI_THEME_MAX_NUMBER))
	#ifndef __MMI_THEME_MAX_NUMBER__
	#define __MMI_THEME_MAX_NUMBER__	CFG_MMI_THEME_MAX_NUMBER
	#endif
#endif


#if (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))
	#ifndef __MMI_THEMES_V2_SUPPORT__
	#define __MMI_THEMES_V2_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_TOUCH_FEEDBACK_SUPPORT) && ((CFG_MMI_TOUCH_FEEDBACK_SUPPORT == __ON__)||(CFG_MMI_TOUCH_FEEDBACK_SUPPORT == __AUTO__)) && \
	(((!defined(__VENUS_UI_ENGINE__)) && defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) || (defined(__COSMOS_MMI_PACKAGE__)))
	#ifndef __MMI_TOUCH_FEEDBACK_SUPPORT__
	#define __MMI_TOUCH_FEEDBACK_SUPPORT__
	#endif
#endif


#if (defined(__MMI_TOUCH_FEEDBACK_SUPPORT__) && defined(UNICORN53V6_DEMO_BB))
	#ifndef __MMI_TOUCH_FEEDBACK_VIBRATE_LEVEL_SUPPORT__
/* under construction !*/
	#endif
#endif


#if defined(CFG_MMI_TOUCH_IDLESCREEN_SHORTCUTS) && ((CFG_MMI_TOUCH_IDLESCREEN_SHORTCUTS == __ON__)||(CFG_MMI_TOUCH_IDLESCREEN_SHORTCUTS == __AUTO__)) && \
	((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)) && defined (__MMI_TOUCH_SCREEN__))
	#ifndef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
	#define __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
	#endif
#endif


#if (defined(TOUCH_PANEL_SHORTCUT_SUPPORT))
	#ifndef __MMI_TOUCH_PANEL_SHORTCUT__
	#define __MMI_TOUCH_PANEL_SHORTCUT__
	#endif
#endif


#if (defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24))
	#ifndef __MMI_TRUE_COLOR__
	#define __MMI_TRUE_COLOR__
	#endif
#endif


#if defined(CFG_MMI_WC_TZ_SUPPORT) && ((CFG_MMI_WC_TZ_SUPPORT == __ON__)||(CFG_MMI_WC_TZ_SUPPORT == __AUTO__)) && \
	((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__)) && defined(__MMI_WORLD_CLOCK__))
	#ifndef __MMI_WC_TZ_SUPPORT__
	#define __MMI_WC_TZ_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_TWO_LAYER_HOMECITY) && ((CFG_MMI_TWO_LAYER_HOMECITY == __ON__)||(CFG_MMI_TWO_LAYER_HOMECITY == __AUTO__)) && \
	(!defined(__MMI_HIDE_HOMECITY__) && !defined(__MMI_WC_TZ_SUPPORT__))
	#ifndef __MMI_TWO_LAYER_HOMECITY__
	#define __MMI_TWO_LAYER_HOMECITY__
	#endif
#endif


#if defined(CFG_MMI_UART_SETTING) && ((CFG_MMI_UART_SETTING == __ON__)||(CFG_MMI_UART_SETTING == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__)) || (defined(__COSMOS_MMI_PACKAGE__) &&  defined(__MTK_INTERNAL__))
	#ifndef __MMI_UART_SETTING__
	#define __MMI_UART_SETTING__
	#endif
#endif


#if defined(CFG_MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT) && ((CFG_MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT == __ON__)||(CFG_MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT == __AUTO__)) && \
	(defined(MMS_SUPPORT))
	#ifndef __MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT__
	#define __MMI_UC_ENCODING_BASED_SLIDE_TEXT_LENGTH_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_UC_MMS_IMG_RESOLUTION) && ((CFG_MMI_UC_MMS_IMG_RESOLUTION == __ON__)||(CFG_MMI_UC_MMS_IMG_RESOLUTION == __AUTO__)) && \
	((defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) && defined (JPG_ENCODE))
	#ifndef __MMI_UC_MMS_IMG_RESOLUTION__
	#define __MMI_UC_MMS_IMG_RESOLUTION__
	#endif
#endif


#if ((defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) && defined(__MMI_PHB_GENERIC_MULTI_SELECT__))
	#ifndef __MMI_UC_MULTI_SELECT__
	#define __MMI_UC_MULTI_SELECT__
	#endif
#endif


#if ((defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) && !defined(__MMI_SLIM_MMS_2__))
	#ifndef __MMI_UC_REPLACE_MEDIA_SUPPORT__
	#define __MMI_UC_REPLACE_MEDIA_SUPPORT__
	#endif
#endif


#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
	#ifndef __MMI_UC_SUB_PREFIX_MMS__
	#define __MMI_UC_SUB_PREFIX_MMS__
	#endif
#endif


#if (defined(__SLIM_MMS__ ) && defined(__MMI_MMS_STANDALONE_COMPOSER__))
	#ifndef __MMI_UC_USE_ASM__
	#define __MMI_UC_USE_ASM__
	#endif
#endif


#if defined(CFG_MMI_UCM_AUTO_ANSWER_NOTIFICATION) && ((CFG_MMI_UCM_AUTO_ANSWER_NOTIFICATION == __ON__)||(CFG_MMI_UCM_AUTO_ANSWER_NOTIFICATION == __AUTO__)) && \
	(defined(__MMI_UCM__))
	#ifndef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
	#define __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
	#endif
#endif


#if defined(CFG_MMI_UCM_AUTO_REJECT_NO_CALL_ID) && ((CFG_MMI_UCM_AUTO_REJECT_NO_CALL_ID == __ON__)||(CFG_MMI_UCM_AUTO_REJECT_NO_CALL_ID == __AUTO__)) && \
	(defined(__MMI_UCM__))
	#ifndef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
	#define __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
	#endif
#endif


#if (defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_UCM_BT_BTBOX_NOLCD__
	#define __MMI_UCM_BT_BTBOX_NOLCD__
	#endif
#endif


#if defined(CFG_MMI_UCM_BT_CALL_RECORDER) && ((CFG_MMI_UCM_BT_CALL_RECORDER == __ON__)||(CFG_MMI_UCM_BT_CALL_RECORDER == __AUTO__)) && \
	(defined(__MMI_BTD_BOX_UI_STYLE__))
	#ifndef __MMI_UCM_BT_CALL_RECORDER__
	#define __MMI_UCM_BT_CALL_RECORDER__
	#endif
#endif


#if defined(CFG_MMI_UCM_DEFLECT) && ((CFG_MMI_UCM_DEFLECT == __ON__)||(CFG_MMI_UCM_DEFLECT == __AUTO__))
	#ifndef __MMI_UCM_DEFLECT__
	#define __MMI_UCM_DEFLECT__
	#endif
#endif


#if defined(CFG_MMI_UCM_DETAIL_ERROR_MSG) && ((CFG_MMI_UCM_DETAIL_ERROR_MSG == __ON__)||(CFG_MMI_UCM_DETAIL_ERROR_MSG == __AUTO__))
	#ifndef __MMI_UCM_DETAIL_ERROR_MSG__
	#define __MMI_UCM_DETAIL_ERROR_MSG__
	#endif
#endif


#if defined(CFG_MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI) && ((CFG_MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI == __ON__)||(CFG_MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI == __AUTO__)) && \
	(defined(__MMI_UCM__))
	#ifndef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
	#define __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
	#endif
#endif


#if defined(CFG_MMI_UCM_ECC_BEST_EFFORT) && ((CFG_MMI_UCM_ECC_BEST_EFFORT == __ON__)||(CFG_MMI_UCM_ECC_BEST_EFFORT == __AUTO__)) && \
	(defined(__MMI_UCM__) && defined(__PLUTO_MMI_PACKAGE__) && (!defined(__MMI_UCM_SLIM__)))
	#ifndef __MMI_UCM_ECC_BEST_EFFORT__
	#define __MMI_UCM_ECC_BEST_EFFORT__
	#endif
#endif


#if defined(CFG_MMI_UCM_ECT) && ((CFG_MMI_UCM_ECT == __ON__)||(CFG_MMI_UCM_ECT == __AUTO__))
	#ifndef __MMI_UCM_ECT__
	#define __MMI_UCM_ECT__
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && (!defined (__MMI_UCM_SLIM__)))
	#ifndef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
	#define __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
	#endif
#endif


#if defined(CFG_MMI_UCM_HIDE_SAT_MO_NUMBER) && ((CFG_MMI_UCM_HIDE_SAT_MO_NUMBER == __ON__)||(CFG_MMI_UCM_HIDE_SAT_MO_NUMBER == __AUTO__)) && \
	(defined(__SAT__) && defined(__MMI_UCM__))
	#ifndef __MMI_UCM_HIDE_SAT_MO_NUMBER__
	#define __MMI_UCM_HIDE_SAT_MO_NUMBER__
	#endif
#endif


#if defined(CFG_MMI_UCM_MO_FAIL_POST_ACTION) && ((CFG_MMI_UCM_MO_FAIL_POST_ACTION == __ON__)||(CFG_MMI_UCM_MO_FAIL_POST_ACTION == __AUTO__))
	#ifndef __MMI_UCM_MO_FAIL_POST_ACTION__
	#define __MMI_UCM_MO_FAIL_POST_ACTION__
	#endif
#endif


#if defined(CFG_MMI_UCM_NOTIFY_TIMEOUT_5S) && ((CFG_MMI_UCM_NOTIFY_TIMEOUT_5S == __ON__)||(CFG_MMI_UCM_NOTIFY_TIMEOUT_5S == __AUTO__)) && \
	(defined(__MMI_UCM__))
	#ifndef __MMI_UCM_NOTIFY_TIMEOUT_5S__
	#define __MMI_UCM_NOTIFY_TIMEOUT_5S__
	#endif
#endif


#if defined(CFG_MMI_UCM_NUMBER_TYPE) && ((CFG_MMI_UCM_NUMBER_TYPE == __ON__)||(CFG_MMI_UCM_NUMBER_TYPE == __AUTO__))
	#ifndef __MMI_UCM_NUMBER_TYPE__
	#define __MMI_UCM_NUMBER_TYPE__
	#endif
#endif


#if defined(CFG_MMI_UCM_REJECT_BY_SMS) && ((CFG_MMI_UCM_REJECT_BY_SMS == __ON__)||(CFG_MMI_UCM_REJECT_BY_SMS == __AUTO__)) && \
	((!defined(__MMI_UCM_SLIM__) && defined(__PLUTO_MMI_PACKAGE__)) || (!defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_UCM_SLIM__) && defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MESSAGES_TEMPLATE__) && defined(__MMI_UNIFIED_COMPOSER__)))
	#ifndef __MMI_UCM_REJECT_BY_SMS__
	#define __MMI_UCM_REJECT_BY_SMS__
	#endif
#endif


#if defined(CFG_MMI_UCM_RSK_MUTE) && ((CFG_MMI_UCM_RSK_MUTE == __ON__)||(CFG_MMI_UCM_RSK_MUTE == __AUTO__)) && \
	(!defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_FTE_SUPPORT__))
	#ifndef __MMI_UCM_RSK_MUTE__
	#define __MMI_UCM_RSK_MUTE__
	#endif
#endif


#if defined(CFG_MMI_UCM_RSK_SUPPRESS_RING) && ((CFG_MMI_UCM_RSK_SUPPRESS_RING == __ON__)||(CFG_MMI_UCM_RSK_SUPPRESS_RING == __AUTO__)) && \
	(defined(__PLUTO_MMI_PACKAGE__) && !(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_FTE_SUPPORT__)))
	#ifndef __MMI_UCM_RSK_SUPPRESS_RING__
	#define __MMI_UCM_RSK_SUPPRESS_RING__
	#endif
#endif


#if defined(CFG_MMI_UCM_SHORT_STIRNG_CRSS) && ((CFG_MMI_UCM_SHORT_STIRNG_CRSS == __ON__)||(CFG_MMI_UCM_SHORT_STIRNG_CRSS == __AUTO__)) && \
	(!defined(__MMI_UCM_SLIM__))
	#ifndef __MMI_UCM_SHORT_STIRNG_CRSS__
	#define __MMI_UCM_SHORT_STIRNG_CRSS__
	#endif
#endif


#if defined(CFG_MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE) && ((CFG_MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE == __ON__)||(CFG_MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE == __AUTO__)) && \
	(defined(__MMI_MAINLCD_320X480__) && defined(__MMI_UCM__) && !defined(__MMI_FTE_SUPPORT__ ))
	#ifndef __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__
	#define __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__
	#endif
#endif


#if defined(CFG_MMI_UM_BOX_LIST_SUPPORT) && ((CFG_MMI_UM_BOX_LIST_SUPPORT == __ON__)||(CFG_MMI_UM_BOX_LIST_SUPPORT == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_UM_BOX_LIST_SUPPORT__
	#define __MMI_UM_BOX_LIST_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_UCM_VT_MSG) && ((CFG_MMI_UCM_VT_MSG == __ON__)||(CFG_MMI_UCM_VT_MSG == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VIDEO_TELEPHONY__) && !defined(__LOW_COST_SUPPORT_COMMON__)  && defined(__MMI_UM_BOX_LIST_SUPPORT__))
	#ifndef __MMI_UCM_VT_MSG__
	#define __MMI_UCM_VT_MSG__
	#endif
#endif


#if (defined(__UDX_SUPPORT__))
	#if (!(defined(__MMI_FILE_MANAGER__) && defined(__MMI_VCARD__) && defined(__MMI_PHB_GENERIC_MULTI_SELECT__) && defined(__MMI_PHB_MULTI_OPERATION__)))
	#error "#error dependence conflict, pls turn on __MMI_FILE_MANAGER__, __MMI_VCARD__, __MMI_PHB_GENERIC_MULTI_SELECT__, __MMI_PHB_MULTI_OPERATION__ or turn off __UDX_SUPPORT__"
	#endif
	#ifndef __MMI_UDX_SUPPORT__
	#define __MMI_UDX_SUPPORT__
	#endif
#endif


#if (defined(__MMI_UDX_SUPPORT__) && defined(__MMI_VCARD__) && defined(__MMI_PHB_GENERIC_MULTI_SELECT__))
	#ifndef __MMI_UDX_VCARD_SUPPORT__
	#define __MMI_UDX_VCARD_SUPPORT__
	#endif
#endif


#if (defined(__MMI_UI_ANIMATED_TITLE_EFFECT_TYPE__) && (__MMI_UI_ANIMATED_TITLE_EFFECT_TYPE__ == __ONCE__))
	#ifndef __MMI_UI_ANIMATED_TITLE_EFFECT__
	#define __MMI_UI_ANIMATED_TITLE_EFFECT__	ONCE
	#endif
#elif (defined(__MMI_UI_ANIMATED_TITLE_EFFECT_TYPE__) && (__MMI_UI_ANIMATED_TITLE_EFFECT_TYPE__ == __CONTINUOUS__))
	#ifndef __MMI_UI_ANIMATED_TITLE_EFFECT__
	#define __MMI_UI_ANIMATED_TITLE_EFFECT__	CONTINUOUS
	#endif
#endif


#if defined(CFG_MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK) && ((CFG_MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK == __ON__)||(CFG_MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK == __AUTO__)) && \
	(defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_480X800__)|| defined(__MMI_MAINLCD_320X240__))
	#ifndef __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__
	#define __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__
	#endif
#endif


#if defined(CFG_MMI_UI_DIALER_PAD) && ((CFG_MMI_UI_DIALER_PAD == __ON__)||(CFG_MMI_UI_DIALER_PAD == __AUTO__)) && \
	(defined(__MMI_BTD_BOX_UI_STYLE__))
	#ifndef __MMI_UI_DIALER_PAD__
	#define __MMI_UI_DIALER_PAD__
	#endif
#endif


#if (!defined(__LCD_SUPPORT__))
	#ifndef __MMI_UI_DISPLAY_LEVEL_NONE__
	#define __MMI_UI_DISPLAY_LEVEL_NONE__
	#endif
#endif


#if (defined(CFG_MMI_UI_FADE_EFFECT_STYLE))
	#ifndef __MMI_UI_FADE_EFFECT_STYLE__
	#define __MMI_UI_FADE_EFFECT_STYLE__	CFG_MMI_UI_FADE_EFFECT_STYLE
	#endif
#endif


#if (defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_FTE_SUPPORT__))
	#ifndef __MMI_UI_HINT_TOGGLE_TRANSITION__
	#define __MMI_UI_HINT_TOGGLE_TRANSITION__
	#endif
#endif


#if defined(CFG_MMI_UI_HINTS_IN_MENUITEM) && ((CFG_MMI_UI_HINTS_IN_MENUITEM == __ON__)||(CFG_MMI_UI_HINTS_IN_MENUITEM == __AUTO__)) && \
	(!defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_MAINLCD_96X64__)&&!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__))) || (defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_FTE_SUPPORT__)&& !defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_UI_HINTS_IN_MENUITEM__
	#define __MMI_UI_HINTS_IN_MENUITEM__
	#endif
#endif


#if defined(CFG_MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT) && ((CFG_MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT == __ON__)||(CFG_MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT == __AUTO__))
	#ifndef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
	#define __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
	#endif
#endif


#if defined(CFG_MMI_UI_LIST_HIGHLIGHT_BOLD) && ((CFG_MMI_UI_LIST_HIGHLIGHT_BOLD == __ON__)||(CFG_MMI_UI_LIST_HIGHLIGHT_BOLD == __AUTO__))
	#ifndef __MMI_UI_LIST_HIGHLIGHT_BOLD__
	#define __MMI_UI_LIST_HIGHLIGHT_BOLD__
	#endif
#endif


#if (defined(CFG_MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL))
	#ifndef __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__
	#define __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__	CFG_MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL
	#endif
#endif


#if (defined(__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__) && (__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__ == HIGHLIGHT_EFFECT_AUTO) && !defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__))
	#ifndef __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__
	#define __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__	HIGHLIGHT_EFFECT_SLIDE
	#endif
#elif (defined(__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__) && (__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__ == HIGHLIGHT_EFFECT_AUTO))
	#ifndef __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__
	#define __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__	HIGHLIGHT_EFFECT_NONE
	#endif
#elif (defined(__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__))
	#if ((__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__ == HIGHLIGHT_EFFECT_SLIDE) && defined(__MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE_CONSTRAINT__))
	#error "HIGHLIGHT_EFFECT_SLIDE is not supported on this chip for __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE __"
	#endif
	#ifndef __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__
	#define __MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__	__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE_SEL__
	#endif
#endif


#if defined(CFG_MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT) && ((CFG_MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT == __ON__)||(CFG_MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT == __AUTO__)) && \
	(defined(__CPU_ARM9EJ_S__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)) && defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && defined(__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__) && (__MMI_UI_MAIN_MENU_MATRIX_HIGHLIGHT_EFFECT_TYPE__ == HIGHLIGHT_EFFECT_SLIDE))
	#ifndef __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
	#define __MMI_UI_MATRIX_MAIN_MENU_SCALING_EFFECT__
	#endif
#endif


#if (defined(__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE__) && (__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE__ == 1))
	#ifndef __MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_1__
	#define __MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_1__
	#endif
#endif


#if (defined(__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE__) && (__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE__ == 2))
	#ifndef __MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_2__
	#define __MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_2__
	#endif
#endif


#if (defined(__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE__) && (__MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE__ == 3))
	#ifndef __MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_3__
	#define __MMI_UI_POPUP_DESCRIPTION_DEFAULT_STYLE_3__
	#endif
#endif


#if (defined(CFG_MMI_UI_SCROLLBAR_DEFAULT_STYLE)&&(CFG_MMI_UI_SCROLLBAR_DEFAULT_STYLE != __OFF__))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE__	CFG_MMI_UI_SCROLLBAR_DEFAULT_STYLE
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE__) && (__MMI_UI_SCROLLBAR_DEFAULT_STYLE__ == 1))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE_1__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE_1__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE__) && (__MMI_UI_SCROLLBAR_DEFAULT_STYLE__ == 2))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE_2__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE_2__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE__) && (__MMI_UI_SCROLLBAR_DEFAULT_STYLE__ == 3))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE_3__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE_3__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE__) && (__MMI_UI_SCROLLBAR_DEFAULT_STYLE__ == 4))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE_4__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE_4__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE__) && (__MMI_UI_SCROLLBAR_DEFAULT_STYLE__ == 5))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE_5__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_DEFAULT_STYLE__) && (__MMI_UI_SCROLLBAR_DEFAULT_STYLE__ == 6))
	#ifndef __MMI_UI_SCROLLBAR_DEFAULT_STYLE_6__
	#define __MMI_UI_SCROLLBAR_DEFAULT_STYLE_6__
	#endif
#endif


#if (defined(CFG_MMI_UI_SCROLLBAR_WIDER_STYLE)&&(CFG_MMI_UI_SCROLLBAR_WIDER_STYLE != __OFF__))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE__	CFG_MMI_UI_SCROLLBAR_WIDER_STYLE
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 1))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_1__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_1__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 2))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_2__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_2__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 3))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_3__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_3__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 4))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_4__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_4__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 5))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_5__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_5__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 6))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_6__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_6__
	#endif
#endif


#if (defined(__MMI_UI_SCROLLBAR_WIDER_STYLE__) && (__MMI_UI_SCROLLBAR_WIDER_STYLE__ == 7))
	#ifndef __MMI_UI_SCROLLBAR_WIDER_STYLE_7__
	#define __MMI_UI_SCROLLBAR_WIDER_STYLE_7__
	#endif
#endif


#ifndef __MMI_UI_SOFTKEY_STYLE__
#define __MMI_UI_SOFTKEY_STYLE__	SOFTKEY_STYLE_NONE
#endif


#if defined(CFG_MMI_UI_STATUS_BAR_AT_BOTTOM) && ((CFG_MMI_UI_STATUS_BAR_AT_BOTTOM == __ON__)||(CFG_MMI_UI_STATUS_BAR_AT_BOTTOM == __AUTO__)) && \
	(!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__))
	#ifndef __MMI_UI_STATUS_BAR_AT_BOTTOM__
	#define __MMI_UI_STATUS_BAR_AT_BOTTOM__
	#endif
#endif


#ifndef __MMI_UI_STATUSBAR_STYLE__
#define __MMI_UI_STATUSBAR_STYLE__	STATUSBAR_STYLE_NONE
#endif


#if defined(CFG_MMI_UI_TIME_PICKER) && ((CFG_MMI_UI_TIME_PICKER == __ON__)||(CFG_MMI_UI_TIME_PICKER == __AUTO__)) && \
	(defined(__MMI_BT_BOX__))
	#ifndef __MMI_UI_TIME_PICKER__
	#define __MMI_UI_TIME_PICKER__
	#endif
#endif


#if (!defined(__MMI_UI_DISABLE_FANCY_EFFECT__))
	#ifndef __MMI_UI_TRANSPARENT_EFFECT__
	#define __MMI_UI_TRANSPARENT_EFFECT__
	#endif
#endif


#if defined(CFG_MMI_UI_TWO_LINE_MENUITEM_STYLES) && ((CFG_MMI_UI_TWO_LINE_MENUITEM_STYLES == __ON__)||(CFG_MMI_UI_TWO_LINE_MENUITEM_STYLES == __AUTO__))
	#ifndef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
	#define __MMI_UI_TWO_LINE_MENUITEM_STYLES__
	#endif
#endif


#if defined(CFG_MMI_ULTRA_SLIM_AUDIO_PLAYER) && ((CFG_MMI_ULTRA_SLIM_AUDIO_PLAYER == __ON__)||(CFG_MMI_ULTRA_SLIM_AUDIO_PLAYER == __AUTO__))
	#ifndef __MMI_ULTRA_SLIM_AUDIO_PLAYER__
	#define __MMI_ULTRA_SLIM_AUDIO_PLAYER__
	#endif
#endif


#if (defined(SLIM_WAP_MMS))
	#ifndef __MMI_ULTRA_SLIM_MMS_2__
	#define __MMI_ULTRA_SLIM_MMS_2__
	#endif
#endif


#if defined(CFG_MMI_UM_CONVERSATION_BOX_WITH_OUTBOX) && ((CFG_MMI_UM_CONVERSATION_BOX_WITH_OUTBOX == __ON__)||(CFG_MMI_UM_CONVERSATION_BOX_WITH_OUTBOX == __AUTO__)) && \
	(defined(__MMI_UM_CONVERSATION_BOX__))
	#ifndef __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__
	#define __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__
	#endif
#endif


#if defined(CFG_MMI_UM_DIAL_FROM_FOLDER) && ((CFG_MMI_UM_DIAL_FROM_FOLDER == __ON__)||(CFG_MMI_UM_DIAL_FROM_FOLDER == __AUTO__))
	#ifndef __MMI_UM_DIAL_FROM_FOLDER__
	#define __MMI_UM_DIAL_FROM_FOLDER__
	#endif
#endif


#if defined(CFG_MMI_UM_SLIM) && ((CFG_MMI_UM_SLIM == __ON__)||(CFG_MMI_UM_SLIM == __AUTO__))
	#ifndef __MMI_UM_SLIM__
	#define __MMI_UM_SLIM__
	#endif
#endif


#if (defined(__UM_FOLDER__) && (defined(__MMI_MMS_TEMPLATE_SUPPORT__) || defined(__MMI_MESSAGES_TEMPLATE__)))
	#ifndef __MMI_UM_TEMPLATE_SUPPORT__
	#define __MMI_UM_TEMPLATE_SUPPORT__
	#endif
#endif


#if (defined(__MMS_JSR_205_SUPPORT__))
	#ifndef __MMI_UMMS_JSR205__
	#define __MMI_UMMS_JSR205__
	#endif
#endif


#if defined(CFG_MMI_UMMS_PREVIEW_SEND) && ((CFG_MMI_UMMS_PREVIEW_SEND == __ON__)||(CFG_MMI_UMMS_PREVIEW_SEND == __AUTO__)) && \
	(defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__) && !defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__))
	#ifndef __MMI_UMMS_PREVIEW_SEND__
	#define __MMI_UMMS_PREVIEW_SEND__
	#endif
#endif


#if ((defined(__DT_SUPPORT__) || defined(__MMI_MMS_IOT_TEST_SUPPORT__)) && defined(__MMI_MMS_2__))
	#ifndef __MMI_UMMS_PST__
	#define __MMI_UMMS_PST__
	#endif
#endif


#if (defined(CFG_MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE))
	#ifndef __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__
	#define __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__	CFG_MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE
	#endif
#endif


#if (!defined(__MMI_BTBOX_NOLCD__))
	#ifndef __MMI_UNIFIEDMESSAGE_APP_SUPPORT__
	#define __MMI_UNIFIEDMESSAGE_APP_SUPPORT__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_UNIQUE_MEDIA_VOL__
	#define __MMI_UNIQUE_MEDIA_VOL__
	#endif
#endif


#if (defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT__))
	#ifndef __MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__
	#define __MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__
	#endif
#endif


#if (defined(__USB_ENABLE__) && defined(__P_PROPRIETARY_COPYRIGHT__))
	#ifndef __MMI_USB_COPY_RIGHT__
/* under construction !*/
	#endif
#endif


#if (defined(__USB_ENABLE__))
	#ifndef __MMI_USB_SUPPORT__
	#define __MMI_USB_SUPPORT__
	#endif
#endif


#if (defined(__MMI_USB_SUPPORT__) && defined(__USB_MULTIPLE_COMPORT_SUPPORT__))
	#ifndef __MMI_USB_MULTIPLE_COMPORT_SUPPORT__
	#define __MMI_USB_MULTIPLE_COMPORT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_USB_SLIM) && ((CFG_MMI_USB_SLIM == __ON__)||(CFG_MMI_USB_SLIM == __AUTO__))
	#ifndef __MMI_USB_SLIM__
	#define __MMI_USB_SLIM__
	#endif
#endif


#if (defined (__KAL_VM__) && defined (__COSMOS_MMI_PACKAGE__) && !defined (__FLAVOR_COSMOS_MMV2_OFF__) && !defined (__FLAVOR_COSMOS_WQVGA_MMV2_OFF__))
	#ifndef __MMI_USE_MMV2__
	#define __MMI_USE_MMV2__
	#endif
#endif


#if defined(CFG_MMI_VCARD_TEL_VOICE_CELL_DIFFERENT) && ((CFG_MMI_VCARD_TEL_VOICE_CELL_DIFFERENT == __ON__)||(CFG_MMI_VCARD_TEL_VOICE_CELL_DIFFERENT == __AUTO__)) && \
	(defined(__MMI_VCARD__))
	#ifndef __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__
	#define __MMI_VCARD_TEL_VOICE_CELL_DIFFERENT__
	#endif
#endif


#if defined(CFG_MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT) && ((CFG_MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT == __ON__)||(CFG_MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT == __AUTO__)) && \
	(defined(FONT_ENGINE_ETRUMP))
	#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	#define __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_VUI_WALLPAPER_MRE) && ((CFG_MMI_VUI_WALLPAPER_MRE == __ON__)||(CFG_MMI_VUI_WALLPAPER_MRE == __AUTO__)) && \
	(defined(__MMI_VUI_ENGINE__) && defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_VUI_WALLPAPER_MRE__
	#define __MMI_VUI_WALLPAPER_MRE__
	#endif
#endif


#if (defined(__MMI_VUI_WIDGET_MRE__) || defined(__MMI_VUI_LAUNCHER_MRE__) || defined(__MMI_VUI_SCREEN_LOCK_MRE__)|| defined(__MMI_VUI_WALLPAPER_MRE__))
	#ifndef __MMI_VENUS_PLUG_IN_ENGINE__
	#define __MMI_VENUS_PLUG_IN_ENGINE__
	#endif
#endif


#if defined(CFG_MMI_VENUS_RT) && ((CFG_MMI_VENUS_RT == __ON__)||(CFG_MMI_VENUS_RT == __AUTO__)) && \
	(defined(__MMI_VUI_ENGINE__))
	#ifndef __MMI_VENUS_RT__
	#define __MMI_VENUS_RT__
	#endif
#endif


#if (defined(CFG_MMI_VFX_SYS_GLOBAL_MEM_SIZE)&&(CFG_MMI_VFX_SYS_GLOBAL_MEM_SIZE != __OFF__))
	#ifndef __MMI_VFX_SYS_GLOBAL_MEM_SIZE__
	#define __MMI_VFX_SYS_GLOBAL_MEM_SIZE__	CFG_MMI_VFX_SYS_GLOBAL_MEM_SIZE
	#endif
#endif


#if (defined(__VIDEO_3D_ANAGLYPH__))
	#ifndef __MMI_VIDEO_3D_ANAGLYPH__
	#define __MMI_VIDEO_3D_ANAGLYPH__
	#endif
#endif


#if (defined(__VIDEO_3D_SIDE_BY_SIDE__))
	#ifndef __MMI_VIDEO_3D_SIDE_BY_SIDE__
	#define __MMI_VIDEO_3D_SIDE_BY_SIDE__
	#endif
#endif


#if defined(CFG_MMI_VIDEO_CLIPPER) && ((CFG_MMI_VIDEO_CLIPPER == __ON__)||(CFG_MMI_VIDEO_CLIPPER == __AUTO__)) && \
	(defined(__VIDEO_CLIPPER_SUPPORT__))
	#ifndef __MMI_VIDEO_CLIPPER__
	#define __MMI_VIDEO_CLIPPER__
	#endif
#endif


#if (defined(MP4_DECODE) && defined(PGDL_SUPPORT))
	#ifndef __MMI_VIDEO_PDL__
	#define __MMI_VIDEO_PDL__
	#endif
#endif


#if (defined(__MMI_VIDEO_PDL__) && defined(PGDL_SUPPORT_YOUTUBE))
	#ifndef __MMI_VIDEO_PDL_YOUTUBE__
/* under construction !*/
	#endif
#endif


#if ((defined(MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__)) && !defined(LOW_COST_SUPPORT))
	#ifndef __MMI_VIDEO_PLY_SNAPSHOT_SUPPORT__
	#define __MMI_VIDEO_PLY_SNAPSHOT_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_VIDEO_RECORDER_SLIM) && ((CFG_MMI_VIDEO_RECORDER_SLIM == __ON__)||(CFG_MMI_VIDEO_RECORDER_SLIM == __AUTO__)) && \
	((defined(MP4_ENCODE) || defined(MJPG_ENCODE)) && (defined(ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)))
	#ifndef __MMI_VIDEO_RECORDER_SLIM__
	#define __MMI_VIDEO_RECORDER_SLIM__
	#endif
#endif


#if (defined(__VIDEO_SUBTITLE_SUPPORT__))
	#ifndef __MMI_VIDEO_SUBTITLE_SUPPORT__
	#define __MMI_VIDEO_SUBTITLE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_VK_POPUP_HINT) && ((CFG_MMI_VK_POPUP_HINT == __ON__)||(CFG_MMI_VK_POPUP_HINT == __AUTO__)) && \
	(defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__) && (defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))) || (defined(MMI_IME_V3_SUPPORT) && (defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_VIRTUAL_KEYBOARD__) && (defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))))
	#ifndef __MMI_VK_POPUP_HINT__
	#define __MMI_VK_POPUP_HINT__
	#endif
#endif


#if (defined(__MMI_SNS_VPP_UPGRADE__) || defined(__MMI_SSO_VPP_UPGRADE__) || defined (__MMI_CLOUD_VPP_UPGRADE__))
	#ifndef __MMI_VPP_UPGRADE__
	#define __MMI_VPP_UPGRADE__
	#endif
#endif


#if (defined(CFG_MMI_VRT_CACHE_SIZE_FACTOR)&&(CFG_MMI_VRT_CACHE_SIZE_FACTOR != __OFF__))
	#ifndef __MMI_VRT_CACHE_SIZE_FACTOR__
	#define __MMI_VRT_CACHE_SIZE_FACTOR__	CFG_MMI_VRT_CACHE_SIZE_FACTOR
	#endif
#endif


#if defined(CFG_MMI_VUI_APP_ICON_MM) && ((CFG_MMI_VUI_APP_ICON_MM == __ON__)||(CFG_MMI_VUI_APP_ICON_MM == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && (__MMI_MAINMENU_ICON_DEFAULT_SEL__ != __MAINMENU_ICON_SEL_1__))
	#ifndef __MMI_VUI_APP_ICON_MM__
	#define __MMI_VUI_APP_ICON_MM__
	#endif
#endif


#if defined(CFG_MMI_VUI_APP_ICON_ROBOT) && ((CFG_MMI_VUI_APP_ICON_ROBOT == __ON__)||(CFG_MMI_VUI_APP_ICON_ROBOT == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && (__MMI_MAINMENU_ICON_DEFAULT_SEL__ != __MAINMENU_ICON_SEL_2__))
	#ifndef __MMI_VUI_APP_ICON_ROBOT__
	#define __MMI_VUI_APP_ICON_ROBOT__
	#endif
#endif


#if (defined(__COSMOS_MMI__))
	#ifndef __MMI_VUI_COSMOS_CP__
	#define __MMI_VUI_COSMOS_CP__
	#endif
#endif


#if (defined(__MMI_VUI_COSMOS_CP__) && defined(LOW_COST_SUPPORT))
	#ifndef __MMI_VUI_COSMOS_CP_SLIM__
	#define __MMI_VUI_COSMOS_CP_SLIM__
	#endif
#endif


#if defined(CFG_MMI_VUI_DOWNLOADABLE_APP_ICON) && ((CFG_MMI_VUI_DOWNLOADABLE_APP_ICON == __ON__)||(CFG_MMI_VUI_DOWNLOADABLE_APP_ICON == __AUTO__)) && \
	((defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_DOWNLOADABLE_APP_ICON__
	#define __MMI_VUI_DOWNLOADABLE_APP_ICON__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOME_SCREEN_SWITCH_EFFECT) && ((CFG_MMI_VUI_HOME_SCREEN_SWITCH_EFFECT == __ON__)||(CFG_MMI_VUI_HOME_SCREEN_SWITCH_EFFECT == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__
	#define __MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__
	#endif
#endif


#if (defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__))
	#ifndef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__
	#define __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__COSMOS_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MED_IN_ASM__) || !defined(__VENUS_3D_UI_ENGINE__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET == __AUTO__)) && \
	((defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))) && !defined(__VENUS_3D_UI_ENGINE__))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MED_IN_ASM__) || !defined(__VENUS_3D_UI_ENGINE__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV == __AUTO__)) && \
	(defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) && defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)|| defined(__MMI_MAINLCD_320X240__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MED_IN_ASM__) || !defined(__VENUS_3D_UI_ENGINE__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MED_IN_ASM__) || !defined(__VENUS_3D_UI_ENGINE__)) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD) && ((CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD == __ON__)||(CFG_MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__
	#define __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__
	#endif
#endif


#if defined(CFG_MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER) && ((CFG_MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER == __ON__)||(CFG_MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER == __AUTO__)) && \
	(defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && defined(MP4_DECODE) && !defined(MCU_245_76M))
	#ifndef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
	#define __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
	#endif
#endif


#if (defined(__VENUS_UI_ENGINE__) && (defined(__CPU_ARM7EJ_S__) || defined(__CPU_ARM9EJ_S__)))
	#ifndef __MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__
	#define __MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__
	#endif
#endif


#if defined(CFG_MMI_VUI_PLATFORM_CONTEXT_SLIM) && ((CFG_MMI_VUI_PLATFORM_CONTEXT_SLIM == __ON__)||(CFG_MMI_VUI_PLATFORM_CONTEXT_SLIM == __AUTO__))
	#ifndef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
	#define __MMI_VUI_PLATFORM_CONTEXT_SLIM__
	#endif
#endif


#if ((defined(__COSMOS_SLIM_ASM3X_PROFILE__)||defined(__MMI_VUI_PLATFORM_CONTEXT_SLIM__)) && defined(__MMI_VUI_LAUNCHER_FACTORY__))
	#ifndef __MMI_VUI_LAUNCHER_HEAP_USE_ASM__
	#define __MMI_VUI_LAUNCHER_HEAP_USE_ASM__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY) && ((CFG_MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY == __ON__)||(CFG_MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY__
	#define __MMI_VUI_LAUNCHER_JAVA_VIDEO_CONCURRENCY__
	#endif
#endif


#if defined(CFG_MMI_VUI_LAUNCHER_MRE_USE_ASM) && ((CFG_MMI_VUI_LAUNCHER_MRE_USE_ASM == __ON__)||(CFG_MMI_VUI_LAUNCHER_MRE_USE_ASM == __AUTO__)) && \
	(defined(__MMI_VUI_LAUNCHER_MRE__))
	#ifndef __MMI_VUI_LAUNCHER_MRE_USE_ASM__
	#define __MMI_VUI_LAUNCHER_MRE_USE_ASM__
	#endif
#endif


#if (defined(__VENUS_UI_ENGINE__) && defined(__CPU_ARM7EJ_S__))
	#ifndef __MMI_VUI_LITE_DISPLAY__
	#define __MMI_VUI_LITE_DISPLAY__
	#endif
#endif


#if defined(CFG_MMI_VUI_MAIN_MENU_SWITCH_EFFECT) && ((CFG_MMI_VUI_MAIN_MENU_SWITCH_EFFECT == __ON__)||(CFG_MMI_VUI_MAIN_MENU_SWITCH_EFFECT == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	#define __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
	#endif
#endif


#if defined(CFG_MMI_VUI_SAVE_BOOKMARK_SUPPORT) && (CFG_MMI_VUI_SAVE_BOOKMARK_SUPPORT == __ON__) || \
	((CFG_MMI_VUI_SAVE_BOOKMARK_SUPPORT == __AUTO__) && !defined(OPERA_BROWSER))
	#ifndef __MMI_VUI_SAVE_BOOKMARK_SUPPORT__
	#define __MMI_VUI_SAVE_BOOKMARK_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_VUI_SCREEN_LOCK_MRE_USE_ASM) && ((CFG_MMI_VUI_SCREEN_LOCK_MRE_USE_ASM == __ON__)||(CFG_MMI_VUI_SCREEN_LOCK_MRE_USE_ASM == __AUTO__)) && \
	(defined(__MMI_VUI_SCREEN_LOCK_MRE__))
	#ifndef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
	#define __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
	#endif
#endif


#if ((defined(__COSMOS_MMI_PACKAGE__)) && ((defined(__MMI_VUI_LAUNCHER_COSMOS__) && defined(__MMI_VUI_LAUNCHER_MM__)) || (defined(__MMI_VUI_LAUNCHER_COSMOS__) && defined(__MMI_VUI_LAUNCHER_ROBOT__)) || (defined(__MMI_VUI_LAUNCHER_MM__) && defined(__MMI_VUI_LAUNCHER_ROBOT__))))
	#ifndef __MMI_VUI_SETTING_LAUNCHER_SELECTION__
	#define __MMI_VUI_SETTING_LAUNCHER_SELECTION__
	#endif
#endif


#if (((defined(__COSMOS_MMI_PACKAGE__)) && ((defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && defined(__MMI_VUI_SCREEN_LOCK_STEAM__)) || (defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && defined(__MMI_VUI_SCREEN_LOCK_PATTERN__)) || (defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)) || (defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && defined(__MMI_VUI_SCREEN_LOCK_ZIPPER__)) || (defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)) || (defined(__MMI_VUI_SCREEN_LOCK_STEAM__) && defined(__MMI_VUI_SCREEN_LOCK_PATTERN__)) || (defined(__MMI_VUI_SCREEN_LOCK_STEAM__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)) || (defined(__MMI_VUI_SCREEN_LOCK_STEAM__) && defined(__MMI_VUI_SCREEN_LOCK_ZIPPER__)) || (defined(__MMI_VUI_SCREEN_LOCK_STEAM__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)) || (defined(__MMI_VUI_SCREEN_LOCK_PATTERN__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)) || (defined(__MMI_VUI_SCREEN_LOCK_PATTERN__) && defined(__MMI_VUI_SCREEN_LOCK_ZIPPER__)) || (defined(__MMI_VUI_SCREEN_LOCK_PATTERN__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)) ||(defined(__MMI_VUI_SCREEN_LOCK_PAINTING__) && defined(__MMI_VUI_SCREEN_LOCK_ZIPPER__)) || (defined(__MMI_VUI_SCREEN_LOCK_PAINTING__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)) || (defined(__MMI_VUI_SCREEN_LOCK_ZIPPER__) && defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)))))
	#ifndef __MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__
	#define __MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__
	#endif
#endif


#if ((defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) && defined(__PLUTO_MMI_PACKAGE__))  || defined(__MMI_VUI_SHELL_MULTI_PAGE__) || defined(__MMI_VUI_3D_MAINMENU__))
	#ifndef __MMI_VUI_SHELL_CP__
	#define __MMI_VUI_SHELL_CP__
	#endif
#endif


#if defined(CFG_MMI_VUI_TEXT_EMOTION_ICON_SUPPORT) && ((CFG_MMI_VUI_TEXT_EMOTION_ICON_SUPPORT == __ON__)||(CFG_MMI_VUI_TEXT_EMOTION_ICON_SUPPORT == __AUTO__))
	#ifndef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
	#define __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_3D_CLOCK) && ((CFG_MMI_VUI_WIDGET_3D_CLOCK == __ON__)||(CFG_MMI_VUI_WIDGET_3D_CLOCK == __AUTO__)) && \
	(defined(__COSMOS_3D_V10__) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_3D_CLOCK__
	#define __MMI_VUI_WIDGET_3D_CLOCK__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_3D_MUSIC_PLAYER) && ((CFG_MMI_VUI_WIDGET_3D_MUSIC_PLAYER == __ON__)||(CFG_MMI_VUI_WIDGET_3D_MUSIC_PLAYER == __AUTO__)) && \
	(defined(__COSMOS_3D_V10__) && (defined(__COSMOS_MUSICPLY__))&& (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_3D_MUSIC_PLAYER__
	#define __MMI_VUI_WIDGET_3D_MUSIC_PLAYER__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_3D_PET) && ((CFG_MMI_VUI_WIDGET_3D_PET == __ON__)||(CFG_MMI_VUI_WIDGET_3D_PET == __AUTO__)) && \
	(defined(__COSMOS_3D_V10__) || (defined(__PLUTO_3D_V10__)) && (defined(__MMI_MAINLCD_240X320__) ||  defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_3D_PET__
	#define __MMI_VUI_WIDGET_3D_PET__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_CALENDAR) && ((CFG_MMI_VUI_WIDGET_CALENDAR == __ON__)||(CFG_MMI_VUI_WIDGET_CALENDAR == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_CALENDAR__
	#define __MMI_VUI_WIDGET_CALENDAR__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_CLOCK1) && ((CFG_MMI_VUI_WIDGET_CLOCK1 == __ON__)||(CFG_MMI_VUI_WIDGET_CLOCK1 == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_CLOCK1__
	#define __MMI_VUI_WIDGET_CLOCK1__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_CLOCK2) && ((CFG_MMI_VUI_WIDGET_CLOCK2 == __ON__)||(CFG_MMI_VUI_WIDGET_CLOCK2 == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_CLOCK2__
	#define __MMI_VUI_WIDGET_CLOCK2__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_CLOCK3) && ((CFG_MMI_VUI_WIDGET_CLOCK3 == __ON__)||(CFG_MMI_VUI_WIDGET_CLOCK3 == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_CLOCK3__
	#define __MMI_VUI_WIDGET_CLOCK3__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_CLOCK4) && ((CFG_MMI_VUI_WIDGET_CLOCK4 == __ON__)||(CFG_MMI_VUI_WIDGET_CLOCK4 == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_CLOCK4__
	#define __MMI_VUI_WIDGET_CLOCK4__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_DCLOCK) && ((CFG_MMI_VUI_WIDGET_DCLOCK == __ON__)||(CFG_MMI_VUI_WIDGET_DCLOCK == __AUTO__)) && \
	(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__))
	#ifndef __MMI_VUI_WIDGET_DCLOCK__
	#define __MMI_VUI_WIDGET_DCLOCK__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_COSMOS__) || defined(__MMI_VUI_LAUNCHER_ROBOT__) || defined(__MMI_VUI_WIDGET_MRE__) || defined(__MMI_VUI_LAUNCHER_KEY__))
	#ifndef __MMI_VUI_WIDGET_FACTORY__
	#define __MMI_VUI_WIDGET_FACTORY__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_FLIP_CLOCK) && ((CFG_MMI_VUI_WIDGET_FLIP_CLOCK == __ON__)||(CFG_MMI_VUI_WIDGET_FLIP_CLOCK == __AUTO__)) && \
	(defined(__COSMOS_MMI_PACKAGE__) && !defined(__COSMOS_3D_V10__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_FLIP_CLOCK__
	#define __MMI_VUI_WIDGET_FLIP_CLOCK__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_FM_RADIO) && ((CFG_MMI_VUI_WIDGET_FM_RADIO == __ON__)||(CFG_MMI_VUI_WIDGET_FM_RADIO == __AUTO__)) && \
	(defined(__MMI_FM_RADIO__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_FM_RADIO__
	#define __MMI_VUI_WIDGET_FM_RADIO__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_GALLERY) && ((CFG_MMI_VUI_WIDGET_GALLERY == __ON__)||(CFG_MMI_VUI_WIDGET_GALLERY == __AUTO__)) && \
	(defined(__MMI_FTO_GALLERY__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_GALLERY__
	#define __MMI_VUI_WIDGET_GALLERY__
	#endif
#endif


#if (defined( __MMI_VUI_LAUNCHER_KEY__))
	#ifndef __MMI_VUI_WIDGET_KEY_ALARM__
	#define __MMI_VUI_WIDGET_KEY_ALARM__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_FM_RADIO__))
	#ifndef __MMI_VUI_WIDGET_KEY_FM_RADIO__
	#define __MMI_VUI_WIDGET_KEY_FM_RADIO__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_SRV_MEDIACACHE__))
	#ifndef __MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__
	#define __MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__UM_FOLDER__))
	#ifndef __MMI_VUI_WIDGET_KEY_MESSAGE__
	#define __MMI_VUI_WIDGET_KEY_MESSAGE__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_KEY__) && (defined(__MMI_AUDIO_PLAYER__) || defined(__MMI_MEDIA_PLAYER__)))
	#ifndef __MMI_VUI_WIDGET_KEY_MUSIC_PLAYER__
	#define __MMI_VUI_WIDGET_KEY_MUSIC_PLAYER__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__SOCIAL_NETWORK_SUPPORT__))
	#ifndef __MMI_VUI_WIDGET_KEY_SNS__
	#define __MMI_VUI_WIDGET_KEY_SNS__
	#endif
#endif


#if (defined(__MMI_VUI_LAUNCHER_KEY__))
	#ifndef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
	#define __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
	#endif
#endif


#if (defined(CFG_MMI_VUI_WIDGET_MRE_MEM_SIZE))
	#ifndef __MMI_VUI_WIDGET_MRE_MEM_SIZE__
	#define __MMI_VUI_WIDGET_MRE_MEM_SIZE__	CFG_MMI_VUI_WIDGET_MRE_MEM_SIZE
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_MUSIC_PLAYER_SLIM) && ((CFG_MMI_VUI_WIDGET_MUSIC_PLAYER_SLIM == __ON__)||(CFG_MMI_VUI_WIDGET_MUSIC_PLAYER_SLIM == __AUTO__)) && \
	(defined(__COSMOS_MUSICPLY_SLIM__) && defined(__PLAYLIST_SERVICE_SLIM__))
	#ifndef __MMI_VUI_WIDGET_MUSIC_PLAYER_SLIM__
	#define __MMI_VUI_WIDGET_MUSIC_PLAYER_SLIM__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_QUICK_SWITCH) && ((CFG_MMI_VUI_WIDGET_QUICK_SWITCH == __ON__)||(CFG_MMI_VUI_WIDGET_QUICK_SWITCH == __AUTO__)) && \
	(defined(__MMI_BT_SUPPORT__) &&  defined(__MMI_WLAN_FEATURES__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_QUICK_SWITCH__
	#define __MMI_VUI_WIDGET_QUICK_SWITCH__
	#endif
#endif


#if defined(CFG_MMI_VUI_WIDGET_SNS_STICKY) && ((CFG_MMI_VUI_WIDGET_SNS_STICKY == __ON__)||(CFG_MMI_VUI_WIDGET_SNS_STICKY == __AUTO__)) && \
	(defined (__MMI_VUI_HOMESCREEN_SNS__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_480X800__)))
	#ifndef __MMI_VUI_WIDGET_SNS_STICKY__
	#define __MMI_VUI_WIDGET_SNS_STICKY__
	#endif
#endif


#if (defined(CFG_MMI_WALLPAPER_NUM)&&(CFG_MMI_WALLPAPER_NUM != __OFF__))
	#ifndef __MMI_WALLPAPER_NUM__
	#define __MMI_WALLPAPER_NUM__	CFG_MMI_WALLPAPER_NUM
	#endif
#endif


#if (!defined(SLIM_WAP_MMS) && defined(OBIGO_Q03C) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)))
	#ifndef __MMI_WAP_9W_NAVIGATION_SUPPORT__
	#define __MMI_WAP_9W_NAVIGATION_SUPPORT__
	#endif
#endif


#if (defined(__MMI_WAP_9W_NAVIGATION_SUPPORT__))
	#ifndef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
	#define __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
	#endif
#endif


#if (defined(WAP_SUPPORT) && !defined(SLIM_WAP_MMS) && defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_ACCESSKEY_SUPPORT__
	#define __MMI_WAP_ACCESSKEY_SUPPORT__
	#endif
#endif


#if (defined(WAP_SUPPORT) && !defined(SLIM_WAP_MMS) && defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_ANIMATED_GIF_SUPPORT__
	#define __MMI_WAP_ANIMATED_GIF_SUPPORT__
	#endif
#endif


#if (defined(WAP_SUPPORT) && !defined(SLIM_WAP_MMS) && defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_BLINKING_TEXT_SUPPORT__
	#define __MMI_WAP_BLINKING_TEXT_SUPPORT__
	#endif
#endif


#if (!defined(SLIM_WAP_MMS) && defined(WAP_SUPPORT) && defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_CORE_PICTOGRAM_SUPPORT__
	#define __MMI_WAP_CORE_PICTOGRAM_SUPPORT__
	#endif
#endif


#if (defined(CFG_MMI_WAP_IMAGE_CACHE_OPTION))
	#ifndef __MMI_WAP_IMAGE_CACHE_OPTION__
	#define __MMI_WAP_IMAGE_CACHE_OPTION__	CFG_MMI_WAP_IMAGE_CACHE_OPTION
	#endif
#endif


#if ((defined(__MMI_WAP_IMAGE_CACHE_OPTION__) && (__MMI_WAP_IMAGE_CACHE_OPTION__ == __ASM__)) &&  defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_IMAGE_CACHE_ASM__
	#define __MMI_WAP_IMAGE_CACHE_ASM__
	#endif
#endif


#if ((defined(__MMI_WAP_IMAGE_CACHE_OPTION__) && (__MMI_WAP_IMAGE_CACHE_OPTION__ == __PH_DRIVE__)) &&  defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_IMAGE_CACHE_PHONE_DRIVE__
	#define __MMI_WAP_IMAGE_CACHE_PHONE_DRIVE__
	#endif
#endif


#if ((defined(__MMI_WAP_IMAGE_CACHE_OPTION__) && (__MMI_WAP_IMAGE_CACHE_OPTION__ == __SYS_DRIVE__)) &&  defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_IMAGE_CACHE_SYSTEM_DRIVE__
	#define __MMI_WAP_IMAGE_CACHE_SYSTEM_DRIVE__
	#endif
#endif


#if ((defined(__MMI_WAP_IMAGE_CACHE_OPTION__) && (__MMI_WAP_IMAGE_CACHE_OPTION__ == __TCARD__)) &&  defined(OBIGO_Q03C_BROWSER))
	#if (!defined(__FS_CARD_SUPPORT__))
	#error "Project does not support memory card, please use another option for image caching"
	#endif
	#ifndef __MMI_WAP_IMAGE_CACHE_TCARD__
	#define __MMI_WAP_IMAGE_CACHE_TCARD__
	#endif
#endif


#if ((defined(__MMI_WAP_IMAGE_CACHE_OPTION__) && (__MMI_WAP_IMAGE_CACHE_OPTION__ == __TCARD_PLUS_PH__)) &&  defined(OBIGO_Q03C_BROWSER))
	#if (!defined(__FS_CARD_SUPPORT__))
	#error "Project does not support memory card, please use another option for image caching."
	#endif
	#ifndef __MMI_WAP_IMAGE_CACHE_TCARD_PLUS_PHONE_DRIVE__
	#define __MMI_WAP_IMAGE_CACHE_TCARD_PLUS_PHONE_DRIVE__
	#endif
#endif


#if ((defined(__MMI_WAP_IMAGE_CACHE_OPTION__) && (__MMI_WAP_IMAGE_CACHE_OPTION__ == __TCARD_PLUS_SYS__)) &&  defined(OBIGO_Q03C_BROWSER))
	#if (!defined(__FS_CARD_SUPPORT__))
	#error "Project does not support memory card, please use another option for image caching"
	#endif
	#ifndef __MMI_WAP_IMAGE_CACHE_TCARD_PLUS_SYS_DRIVE__
	#define __MMI_WAP_IMAGE_CACHE_TCARD_PLUS_SYS_DRIVE__
	#endif
#endif


#if (defined(WAP_SUPPORT) && !defined(SLIM_WAP_MMS) && defined(OBIGO_Q03C_BROWSER))
	#ifndef __MMI_WAP_MARQUEE_SUPPORT__
	#define __MMI_WAP_MARQUEE_SUPPORT__
	#endif
#endif


#if defined(CFG_MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE) && ((CFG_MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE == __ON__)||(CFG_MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE == __AUTO__)) && \
	(defined(__MMI_MMS_2__))
	#ifndef __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__
	#define __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__
	#endif
#endif


#if defined(CFG_MMI_WAP_MMS_SEND_INSTANT_RETRY) && ((CFG_MMI_WAP_MMS_SEND_INSTANT_RETRY == __ON__)||(CFG_MMI_WAP_MMS_SEND_INSTANT_RETRY == __AUTO__)) && \
	(defined(__MMI_MMS_2__))
	#ifndef __MMI_WAP_MMS_SEND_INSTANT_RETRY__
	#define __MMI_WAP_MMS_SEND_INSTANT_RETRY__
	#endif
#endif


#if (!defined(SLIM_WAP_MMS) && defined(OBIGO_Q03C) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)) && !defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_WAP_MOUSE_POINTER_SUPPORT__
	#define __MMI_WAP_MOUSE_POINTER_SUPPORT__
	#endif
#endif


#if (!defined(SLIM_WAP_MMS) && defined(WAP_SUPPORT) && defined(__MMI_BROWSER_2__))
	#ifndef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
	#define __MMI_WAP_OFFLINE_PAGES_SUPPORT__
	#endif
#endif


#if (defined(__WAP_PUSH_SUPPORT__) && defined(__SLIM_PUSH_FEATURE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
	#define __MMI_WAP_PUSH_ADVANCED_FEATURE_SLIM__
	#endif
#endif


#if (defined(__WAP_PUSH_SUPPORT__) && defined(__MMI_WAP_PUSH_WHITE_LIST__) && defined(__FULL_PUSH_FEATURE_SUPPORT__))
	#ifndef __MMI_WAP_PUSH_BLACK_LIST__
	#define __MMI_WAP_PUSH_BLACK_LIST__
	#endif
#endif


#if (defined(__WAP_PUSH_SUPPORT__) && defined(__SLIM_PUSH_FEATURE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_WAP_PUSH_SIA_SLIM__
	#define __MMI_WAP_PUSH_SIA_SLIM__
	#endif
#endif


#if defined(CFG_MMI_WAP_SPLASH_SCREEN_SUPPORT) && ((CFG_MMI_WAP_SPLASH_SCREEN_SUPPORT == __ON__)||(CFG_MMI_WAP_SPLASH_SCREEN_SUPPORT == __AUTO__)) && \
	(defined(WAP_SUPPORT) && defined(__MMI_BROWSER_2__))
	#ifndef __MMI_WAP_SPLASH_SCREEN_SUPPORT__
	#define __MMI_WAP_SPLASH_SCREEN_SUPPORT__
	#endif
#endif


#if (defined(WAP_SUPPORT) && defined(SLIM_WAP_MMS) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __MMI_WAP_UPP_SLIM__
	#define __MMI_WAP_UPP_SLIM__
	#endif
#endif


#if (!defined(__MMI_WCLOCK_CITY_LIST_3__))
	#ifndef __MMI_WCLOCK_CITY_LIST_2__
	#define __MMI_WCLOCK_CITY_LIST_2__
	#endif
#endif


#if (!defined(SLIM_WAP_MMS) && defined (WAP_SUPPORT) && !defined (__COSMOS_MMI_PACKAGE__))
	#ifndef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
	#define __MMI_WCSS_INPUT_FORMAT_SUPPORT__
	#endif
#endif


#if (defined(WEBCAM_SUPPORT))
	#ifndef __MMI_WEBCAM__
	#define __MMI_WEBCAM__
	#endif
#endif


#if (defined (__MMI_FWUI_SLIM__)&&!defined(__MMI_MAINLCD_96X64__))
	#ifndef __MMI_WGUI_DISABLE_CSK__
	#define __MMI_WGUI_DISABLE_CSK__
	#endif
#endif


#if defined(CFG_MMI_WITH_C_KEY) && ((CFG_MMI_WITH_C_KEY == __ON__)||(CFG_MMI_WITH_C_KEY == __AUTO__)) && \
	(defined(__MMI_NORMAL_KEYPAD__))
	#ifndef __MMI_WITH_C_KEY__
	#define __MMI_WITH_C_KEY__
	#endif
#endif


#if defined(CFG_MMI_WITH_WAP_KEY) && ((CFG_MMI_WITH_WAP_KEY == __ON__)||(CFG_MMI_WITH_WAP_KEY == __AUTO__))
	#ifndef __MMI_WITH_WAP_KEY__
	#define __MMI_WITH_WAP_KEY__
	#endif
#endif


#if defined(CFG_MMI_WLAN_OTAP_DMP) && ((CFG_MMI_WLAN_OTAP_DMP == __ON__)||(CFG_MMI_WLAN_OTAP_DMP == __AUTO__)) && \
	(defined(__WIFI_SUPPORT__) && defined(__MMI_WLAN_FEATURES__) && defined(__MMI_CCA_SUPPORT__))
	#ifndef __MMI_WLAN_OTAP_DMP__
	#define __MMI_WLAN_OTAP_DMP__
	#endif
#endif


#if (defined(__MMI_WORLD_CLOCK__) || defined(__MMI_MRE_WORLD_CLOCK__))
	#ifndef __MMI_WORLDCLOCK_DST__
	#define __MMI_WORLDCLOCK_DST__
	#endif
#endif


#if defined(CFG_MMI_WORLDCLOCK_SLIM) && ((CFG_MMI_WORLDCLOCK_SLIM == __ON__)||(CFG_MMI_WORLDCLOCK_SLIM == __AUTO__)) && \
	(defined(__LOW_COST_SUPPORT_COMMON__)) || (defined(__MMI_MAINLCD_480X800__) && defined(__LOW_COST_SUPPORT_COMMON__))
	#ifndef __MMI_WORLDCLOCK_SLIM__
	#define __MMI_WORLDCLOCK_SLIM__
	#endif
#endif


#if defined(CFG_MMI_YOUTUBE_SHORTCUT) && ((CFG_MMI_YOUTUBE_SHORTCUT == __ON__)||(CFG_MMI_YOUTUBE_SHORTCUT == __AUTO__)) && \
	(defined(BROWSER_SUPPORT) && defined(PGDL_SUPPORT_YOUTUBE))
	#ifndef __MMI_YOUTUBE_SHORTCUT__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_UCM_SLIM__))
	#ifndef __SLIM_UCM__
	#define __SLIM_UCM__
	#endif
#endif


#if (defined(__MMI_CBS_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __SRV_CBS_SUPPORT__
	#define __SRV_CBS_SUPPORT__
	#endif
#endif


#if (defined(__SQLITE3_SUPPORT__) && (defined(__MMI_IMAGE_VIEWER_EX_DB__) || defined(__MMI_FTO_GALLERY__)))
	#ifndef __SRV_MEDIACACHE_DB_SUPPORT__
	#define __SRV_MEDIACACHE_DB_SUPPORT__
	#endif
#endif


#if (defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__))
	#ifndef __SRV_PHB_TCARD_STORAGE_SUPPORT__
	#define __SRV_PHB_TCARD_STORAGE_SUPPORT__
	#endif
#endif


#if (defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
	#ifndef __SRV_SMS_ARCHIVE__
	#define __SRV_SMS_ARCHIVE__
	#endif
#endif


#if (!defined( __ULC_AT__))
	#ifndef __SRV_SMS_AT_SUPPORT__
	#define __SRV_SMS_AT_SUPPORT__
	#endif
#endif


#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
	#ifndef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
	#define __SRV_SMS_BACKGROUND_SEND_SUPPORT__
	#endif
#endif


#if (defined(__MMI_MESSAGES_SINGLE_DELIVERY_REPORT__) && defined(__MMI_UM_REPORT_STATUS_IN_SENT_BOX__))
	#ifndef __SRV_SMS_DELIVERY_STATUS__
	#define __SRV_SMS_DELIVERY_STATUS__
	#endif
#endif


#if (defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
	#ifndef __SRV_SMS_MSG_EXT_STATUS__
	#define __SRV_SMS_MSG_EXT_STATUS__
	#endif
#endif


#if (!defined(__UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__) && (defined(__PLUTO_MMI_PACKAGE__)  || !defined(LOW_COST_SUPPORT)))
	#ifndef __SRV_SMS_MSG_INFO_CONTENT__
	#define __SRV_SMS_MSG_INFO_CONTENT__
	#endif
#endif


#if (defined(__EMS_NON_STD_7BIT_CHAR__))
	#ifndef __SRV_SMS_MSG_INFO_DCS__
	#define __SRV_SMS_MSG_INFO_DCS__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __SRV_SMS_MSG_INFO_PORT__
	#define __SRV_SMS_MSG_INFO_PORT__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(__MMI_MESSAGE_SLIM__))
	#ifndef __SRV_SMS_MULTI_ADDR__
	#define __SRV_SMS_MULTI_ADDR__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__))
	#ifndef __SRV_SMS_MULTI_ADDR_REPORT__
	#define __SRV_SMS_MULTI_ADDR_REPORT__
	#endif
#endif


#if (defined(__MMI_DUAL_SIM_MASTER__))
	#ifndef __SRV_SMS_MULTI_SIM__
/* under construction !*/
	#endif
#endif


#if (defined(__MMI_MESSAGES_NOT_DISPLAY_8BIT_DCS_SMS_CONTENT__))
	#ifndef __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__
	#define __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MESSAGES_TEMPLATE__))
	#ifndef __SRV_SMS_PREDEFINED_TEMPLATE__
	#define __SRV_SMS_PREDEFINED_TEMPLATE__
	#endif
#endif


#if (defined(__MMI_SMS_PREFER_STORAGE_SETTING__))
	#ifndef __SRV_SMS_PREFER_STORAGE_SETTING__
	#define __SRV_SMS_PREFER_STORAGE_SETTING__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(LOW_COST_SUPPORT))
	#ifndef __SRV_SMS_RESEND_COUNT__
	#define __SRV_SMS_RESEND_COUNT__
	#endif
#endif


#if (!defined(__UNIFIED_MESSAGE_LOW_MEMORY_SUPPORT__))
	#ifndef __SRV_SMS_SIM_TIMESTAMP__
	#define __SRV_SMS_SIM_TIMESTAMP__
	#endif
#endif


#if (defined(__SRV_SMS_SIM_TIMESTAMP__) || defined(__SRV_SMS_RESEND_COUNT__))
	#ifndef __SRV_SMS_SIM_CUST_DATA__
	#define __SRV_SMS_SIM_CUST_DATA__
	#endif
#endif


#if (!defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
	#ifndef __SRV_SMS_SIM_MEMORY_BASE__
	#define __SRV_SMS_SIM_MEMORY_BASE__
	#endif
#endif


#if (defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__))
	#ifndef __SRV_SMS_SIMBOX_SUPPORT__
	#define __SRV_SMS_SIMBOX_SUPPORT__
	#endif
#endif


#if (!defined( __ULC_AT__) && defined(__SLIM_AT__))
	#ifndef __SRV_SMS_SLIM_AT_SUPPORT__
	#define __SRV_SMS_SLIM_AT_SUPPORT__
	#endif
#endif


#if (defined(__MMI_SMS_TCARD_STORAGE_SUPPORT__))
	#ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	#define __SRV_SMS_TCARD_STORAGE_SUPPORT__
	#endif
#endif


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MESSAGES_TEMPLATE__))
	#ifndef __SRV_SMS_USERDEFINED_TEMPLATE__
	#define __SRV_SMS_USERDEFINED_TEMPLATE__
	#endif
#endif


#if (defined(__SRV_SMS_USERDEFINED_TEMPLATE__) || defined(__SRV_SMS_PREDEFINED_TEMPLATE__))
	#ifndef __SRV_SMS_TEMPLATE__
	#define __SRV_SMS_TEMPLATE__
	#endif
#endif


#ifndef __SRV_SMS_UNSENT_LIST__
#define __SRV_SMS_UNSENT_LIST__
#endif


#if (defined(__SRV_SMS_TCARD_STORAGE_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__))
	#ifndef __SRV_TCARD_DATA_STORE__
	#define __SRV_TCARD_DATA_STORE__
	#endif
#endif


#if (defined(__MMI_UM_CONVERSATION_BOX__) && defined( __COSMOS_MMI_PACKAGE__))
	#ifndef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
	#define __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
	#endif
#endif


#if (defined(__MMI_UM_CONVERSATION_BOX__))
	#ifndef __SRV_UM_THREAD_MESSAGE_SUPPORT__
	#define __SRV_UM_THREAD_MESSAGE_SUPPORT__
	#endif
#endif


#if (defined(__J2ME__) && defined(__NEMO_VM__) && (defined(__COSMOS_MMI_PACKAGE__)) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)) && (defined(REDUCED_KEYPAD)))
	#ifndef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
	#define __SUPPORT_JAVA_VIRTUAL_KEYPAD__
	#endif
#endif


#if (defined(__J2ME__) && defined(__NEMO_VM__) && (defined(__COSMOS_MMI_PACKAGE__) ) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)) && (defined(NORMAL_KEYPAD) || defined(QWERTY_KEYPAD)))
	#ifndef __SUPPORT_JUI_COSMOS_SLIM_VIRTUAL_KEYPAD__
	#define __SUPPORT_JUI_COSMOS_SLIM_VIRTUAL_KEYPAD__
	#endif
#endif


#ifndef __UCS2_ENCODING
#define __UCS2_ENCODING
#endif


#if (defined(__MMI_MMS_2__) && defined(__PLUTO_MMI_PACKAGE__))
	#ifndef __UI_MMS_VIEWER_CATEGORY__
	#define __UI_MMS_VIEWER_CATEGORY__
	#endif
#endif


#if (defined(__UI_MMS_VIEWER_CATEGORY__))
	#ifndef __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
	#define __UI_ENHANCED_HILITE_IN_MULTILINE_EDITOR__
	#endif
#endif


#if ((defined(__UI_MMS_VIEWER_CATEGORY__)&&!defined(__MMI_FWUI_SLIM__)) || defined(__MMI_EBOOK_READER__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__))
	#ifndef __UI_PAGING_IN_MULTILINE_EDITOR__
	#define __UI_PAGING_IN_MULTILINE_EDITOR__
	#endif
#endif


#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
	#ifndef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
	#define __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
	#endif
#endif


#if (defined(__BT_DIALER_SUPPORT__) || defined(__UM_FOLDER__) || (!defined(__MMI_SMS_SLIM__)))
	#ifndef __UM_SUPPORT__
	#define __UM_SUPPORT__
	#endif
#endif


#if defined(CFG_ZIMAGE_LOGO_ANIMATED_SUPPORT) && ((CFG_ZIMAGE_LOGO_ANIMATED_SUPPORT == __ON__)||(CFG_ZIMAGE_LOGO_ANIMATED_SUPPORT == __AUTO__)) && \
	(defined(__ZIMAGE_SUPPORT__) && (CFG_ZIMAGE_LOGO_ANIMATED_SUPPORT == __ON__))
	#ifndef __ZIMAGE_LOGO_ANIMATED_SUPPORT__
	#define __ZIMAGE_LOGO_ANIMATED_SUPPORT__
	#endif
#endif


#if (defined(__MOD_SMSAL__) && defined(__MMI_MESSAGES_PREDEFINED_TEMPLATE__))
	#ifndef _MUTILANG_TEMPLATE_
	#define _MUTILANG_TEMPLATE_
	#endif
#endif


#if (defined(__MMI_FTE_SUPPORT__)&&!defined(__MMI_FWUI_SLIM__))
	#ifndef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
	#define GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
	#endif
#endif


#if (defined(__MMI_DOWNLOAD_AGENT__) && defined(__HTTP_INTERFACE__))
	#ifndef MMI_DA_HTTP_DOWNLOAD_SUPPORT
	#define MMI_DA_HTTP_DOWNLOAD_SUPPORT
	#endif
#endif


#if (defined(MMI_SUB_LCD_DEFAULT_FORMAT) && (MMI_SUB_LCD_DEFAULT_FORMAT == 24))
	#ifndef MMI_SUB_BASE_LAYER_BITS_PER_PIXEL
	#define MMI_SUB_BASE_LAYER_BITS_PER_PIXEL	24
	#endif
#elif (defined(MMI_SUB_LCD_DEFAULT_FORMAT) && (MMI_SUB_LCD_DEFAULT_FORMAT == 32))
	#ifndef MMI_SUB_BASE_LAYER_BITS_PER_PIXEL
	#define MMI_SUB_BASE_LAYER_BITS_PER_PIXEL	32
	#endif
#else
	#ifndef MMI_SUB_BASE_LAYER_BITS_PER_PIXEL
	#define MMI_SUB_BASE_LAYER_BITS_PER_PIXEL	16
	#endif
#endif


#if ((defined(__MMI_MOTION_DIAL__) && defined(__MMI_UI_CATEGORY_DIAL_TYPE_SEL_MOTION_NUM__)))
	#ifndef PHNSET_MOTION_DIAL_NUM
	#define PHNSET_MOTION_DIAL_NUM	__MMI_UI_CATEGORY_DIAL_TYPE_SEL_MOTION_NUM__
	#endif
#endif


#if (defined(__MMI_MOTION_MAINMENU__) && defined(__MMI_MAINMENU_MOTION_SUPPORT_NUM__))
	#ifndef PHNSET_MOTION_MAINMENU_NUM
	#define PHNSET_MOTION_MAINMENU_NUM	__MMI_MAINMENU_MOTION_SUPPORT_NUM__
	#endif
#endif


#if (defined(SUPPORT_JSR_257) && defined(__NEMO_VM__))
	#ifndef SUPPORT_JSR_257_PUSH
	#define SUPPORT_JSR_257_PUSH
	#endif
#endif


#if defined(CFG_WGUI_STATUS_ICON_ALIGN_RIGHT) && ((CFG_WGUI_STATUS_ICON_ALIGN_RIGHT == __ON__)||(CFG_WGUI_STATUS_ICON_ALIGN_RIGHT == __AUTO__))
	#ifndef WGUI_STATUS_ICON_ALIGN_RIGHT
	#define WGUI_STATUS_ICON_ALIGN_RIGHT
	#endif
#endif


#if defined(CFG_WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT) && ((CFG_WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT == __ON__)||(CFG_WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT == __AUTO__)) && \
	((defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X240__)|| defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_480X800__)|| defined(__MMI_MAINLCD_320X240__)) && defined(__MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__))
	#ifndef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
	#define WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
	#endif
#endif


#if (!defined(__MMI_FWUI_SLIM__))
	#ifndef WGUI_STATUS_ICON_SHOW_V_BAR
	#define WGUI_STATUS_ICON_SHOW_V_BAR
	#endif
#endif


#endif /* __MMI_FEATURES__ */
