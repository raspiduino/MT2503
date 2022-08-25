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
 * MobileService.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Mobile Service resource file with XML format.
 *
 * Author:
 * -------
 *   Jia Liu
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 04 06 2012 guoyi.zhao
 * [MAUI_03160247] No need to have the menu Connectivity in Settings
 * .
 *
 * 03 26 2012 jiaowei.li
 * [MAUI_03155822] CMCC TD key launcher homescreen and mainmenu check in
 * modify feature resource App Tag attribute with key launcher function.
 *
 * 03 23 2012 jiaowei.li
 * [MAUI_03149892] [TD Gemini 2.0][APOLLO55V2][STK] SAT 不符合移动白皮书要求
 * CMCC merge sim1 + Sim2 to SIM.
 *
 * 09 26 2011 jiaowei.li
 * [MAUI_03036813] SIM Recovery Enhancement check-in
 * .Simcard Recovery Add Event ID Process.
 *
 * 08 15 2011 jiaowei.li
 * [MAUI_03005152] Cu Simcard APP Change
 * .As the requirement of CUNICOM,  Merge the SimCardAPP(SIM1 + SIM2) in MobileService to SimcardAPP(SIM), Add the MenuLevel. Original, MobileService have Sim1+SIm2 MenuItem; Now, MobileService have SIM MenuItem, and SIM Menu have SIM1 + Sim2 MenuItem.
 *
 * 05 10 2011 jia.liu
 * [MAUI_02936919] [CU 2.0] [New spec mainmenu revise] check-in
 * .
 *
 * 05 03 2011 jia.liu
 * [MAUI_02929098] [Need Patch][Build Error] MAUI.W11.19 build error for MT6253D_EVB_gprs(SIM_HOT_SWAP_GEMINI)
 * .
 *
 * 04 26 2011 jia.liu
 * [MAUI_02922314] SIM Hot Swap Check in
 * .
 *
 * 04 15 2011 jia.liu
 * [MAUI_02659289] [CU 2.0] Wo Read Check in
 * change mobile internet to wo 3g
 *
 * 04 11 2011 jia.liu
 * [MAUI_02659289] [CU 2.0] Wo Read Check in
 * .
 *
 * 01 19 2011 jia.liu
 * [MAUI_02649057] CU2.0 Support Check in
 * .
 *
 * 12 30 2010 jia.liu
 * [MAUI_02642876] Revise Check in
 * CU 2.0 Compile Option Revise
 *
 * 11 10 2010 jia.liu
 * [MAUI_02727843] [1] Assert fail: nvraminterface.c 1036 - MMI
 * .
 *
 * 10 26 2010 jia.liu
 * [MAUI_02638714] MTPNP API and Callback Mgr Revise
 * .
 *
 * Jun 23 2010 mtk80517
 * [MAUI_02213846] No Browser but MMS Support
 * 
 *
 * Jun 2 2010 mtk80517
 * [MAUI_02291972] go to wrong screen when click CSK icon
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_MOBILE_SERVICE"
	 #if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
	 package_name="native.mtk.phonebookmanager" 
     name ="STR_ID_OPTRSER_PIM" 
     img = "IMG_ID_KEY_LAUNCH_PBM_APP_ICON"
     launch="mmi_phonebookmanager_launch"
     #endif
>

#ifdef __MMI_MOBILE_SERVICE__

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_OPTRSER_TITLE"/>
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)    
    <STRING id="STR_ID_OPTRSER_STK1"/>
    <STRING id="STR_ID_OPTRSER_STK2"/>
#endif    
    <STRING id="STR_ID_OPTRSER_STK"/>
#ifdef __OP01__
#ifdef BROWSER_SUPPORT
    <STRING id="STR_ID_OPTRSER_MUSIC"/>
    <STRING id="STR_ID_OPTRSER_GAME"/>
    <STRING id="STR_ID_OPTRSER_WEATHER"/>
    <STRING id="STR_ID_OPTRSER_FETION"/>
    <STRING id="STR_ID_OPTRSER_VIDEO"/>
    <STRING id="STR_ID_OPTRSER_NEW"/>
    <STRING id="STR_ID_OPTRSER_MYMONWAP"/>
    <STRING id="STR_ID_OPTRSER_MONWAP"/>
    <STRING id="STR_ID_OPTRSER_MONSEARCH"/>
#ifdef __MMI_OP01_DCD__
    <STRING id="STR_ID_OPTRSER_DCD"/>
#endif /*__MMI_OP01_DCD__*/
#endif /* BROWSER_SUPPORT */
#ifdef __SYNCML_SUPPORT__
    <STRING id="STR_ID_OPTRSER_PIM"/>
    <STRING id="STR_ID_OPTRSER_PIM_INTRO"/>
    <STRING id="STR_ID_OPTRSER_PIM_ENTER"/>
    <STRING id="STR_ID_OPTRSER_PIM_SYNC"/>
    <STRING id="STR_ID_OPTRSER_PIM_PB"/>
    <STRING id="STR_ID_OPTRSER_PIM_SETTING"/>
#ifdef BROWSER_SUPPORT
    <STRING id="STR_ID_OPTRSER_PIM_FEE"/>
    <STRING id="STR_ID_OPTRSER_PIM_ORDER"/>
    <STRING id="STR_ID_OPTRSER_PIM_CHECK"/>
#endif /* BROWSER_SUPPORT */ 
#endif
#endif/*__OP01__*/

#ifdef __OP02__
    <STRING id="STR_ID_OPTRSER_MUSIC"/>
#ifdef BROWSER_SUPPORT
    <STRING id="STR_ID_OPTRSER_NEWS"/>
#endif
    <STRING id="STR_ID_OPTRSER_HOTLINE"/>
    <STRING id="STR_ID_OPTRSER_GUIDE"/>
    <STRING id="STR_ID_OPTRSER_GUIDE_CONTENT"/>
#if ((defined __MMI_OP02_MAINMENU_9MATRIX__) || (defined __OP02_0200__))
    <STRING id="STR_ID_OPTRSER_MOBILE_TV"/>
    <STRING id="STR_ID_OPTRSER_PUSH_MAIL"/>
    <STRING id="STR_ID_OPTRSER_MOBILE_STOCK"/>
#endif /* (defined __MMI_OP02_MAINMENU_9MATRIX__) || (defined __OP02_0200__) */
#ifdef __OP02_0200__
    <STRING id="STR_ID_OPTRSER_116114"/>
    <STRING id="STR_ID_OPTRSER_ONLINE_SALES"/>
    <STRING id="STR_ID_OPTRSER_STORE"/>
    <STRING id="STR_ID_OPTRSER_LEMEI"/>
    <STRING id="STR_ID_OPTRSER_USIM_APP"/>
#ifdef BROWSER_SUPPORT
#ifdef __MMI_OP02_WO_PORTAL__
    <STRING id="STR_ID_OPTRSER_PORTAL"/>
#else
    <STRING id="STR_ID_OPTRSER_MOWAP"/>
#endif
    <STRING id="STR_ID_OPTRSER_READ"/>
#endif
#endif /* __OP02_0200__ */
#endif/*__OP02__*/


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#ifdef __OP01__
#ifdef BROWSER_SUPPORT
    <IMAGE id="IMG_ID_OPTRSER_MUSIC">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MusicChannel.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_GAME">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_Games.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_WEATHER">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_NewsWeather.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_FETION">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_Fetion.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_VIDEO">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MobileVideo.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_NEW">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_WhatNews.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_MYMONWAP">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_MONWAP">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_Monternet.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_MONSEARCH">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_MonternetSearch.bmp"</IMAGE>
#ifdef __MMI_OP01_DCD__
    <IMAGE id="IMG_ID_OPTRSER_DCD">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_DCD.bmp"</IMAGE>
#endif
#endif /* BROWSER_SUPPORT */

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    <IMAGE id="IMG_ID_OPTRSER_STK1">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_STK1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_STK2">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_STK2.bmp"</IMAGE>
#endif    
    <IMAGE id="IMG_ID_OPTRSER_STK">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_STK.bmp"</IMAGE>
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    <IMAGE id="IMG_ID_KEY_LAUNCH_bmp_APP_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\MainMenu\\\\bmpanager.png"</IMAGE>
#endif
#ifdef __SYNCML_SUPPORT__
    <IMAGE id="IMG_ID_OPTRSER_PIM">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\CMI_PhonebookManager.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_PIM_SYNC">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\bmp_PhonebookUpdate.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_PIM_PB">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\bmp_Phonebook.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_PIM_SETTING">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\bmp_Setting.bmp"</IMAGE>
#ifdef BROWSER_SUPPORT
    <IMAGE id="IMG_ID_OPTRSER_PIM_ORDER">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\bmp_OnlineInquiry.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_PIM_CHECK">CUST_IMG_PATH"\\\\MainLCD\\\\ChinaMobileIn\\\\PhonebookManager\\\\bmp_SubscribeSservices.bmp"</IMAGE>
#endif /* BROWSER_SUPPORT */
#endif /* __SYNCML_SUPPORT__ */
#endif /*__OP01__*/

#ifdef __OP02__
    <IMAGE id="IMG_ID_OPTRSER_MUSIC">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_Music.bmp"</IMAGE>
#ifdef BROWSER_SUPPORT
    <IMAGE id="IMG_ID_OPTRSER_NEWS">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_News.bmp"</IMAGE>
#endif

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    <IMAGE id="IMG_ID_OPTRSER_STK1">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_USIM1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_STK2">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_USIM2.bmp"</IMAGE>
#endif
    <IMAGE id="IMG_ID_OPTRSER_STK">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_USIM.bmp"</IMAGE>

    <IMAGE id="IMG_ID_OPTRSER_HOTLINE">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_Hotline.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_GUIDE">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_Guide.bmp"</IMAGE>
#if ((defined __MMI_OP02_MAINMENU_9MATRIX__) || (defined __OP02_0200__))
    <IMAGE id="IMG_ID_OPTRSER_MOBILE_TV">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_MobileTV.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_PUSH_MAIL">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_PushMail.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_MOBILE_STOCK">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_MobileStock.bmp"</IMAGE>
#endif /* (defined __MMI_OP02_MAINMENU_9MATRIX__) || (defined __OP02_0200__) */
#ifdef __OP02_0200__
    <IMAGE id="IMG_ID_OPTRSER_116114">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_116114.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_ONLINE_SALES">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_OS.bmp"</IMAGE>
    <IMAGE id="IMG_ID_OPTRSER_STORE">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_STORE.bmp"</IMAGE>
#ifdef __MMI_OP02_LEMEI__
    <IMAGE id="IMG_ID_OPTRSER_LEMEI">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_LM.bmp"</IMAGE>
#endif
#ifdef BROWSER_SUPPORT
#ifdef __MMI_OP02_WO_PORTAL__
    <IMAGE id="IMG_ID_OPTRSER_PORTAL">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_3G.bmp"</IMAGE>
#else
    <IMAGE id="IMG_ID_OPTRSER_MOWAP">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_MO.bmp"</IMAGE>
#endif
    <IMAGE id="IMG_ID_OPTRSER_READ">CUST_IMG_PATH"\\\\MainLCD\\\\UnicomService\\\\UNISER_Read.bmp"</IMAGE>
#endif
#endif /* __OP02_0200__ */
#endif/*__OP02__*/


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
#ifdef __OP01__
#ifdef BROWSER_SUPPORT
    <MENU id="MENU_ID_OPTRSER_MUSIC" str="STR_ID_OPTRSER_MUSIC" img="IMG_ID_OPTRSER_MUSIC"/>
    <MENU id="MENU_ID_OPTRSER_GAME" str="STR_ID_OPTRSER_GAME" img="IMG_ID_OPTRSER_GAME"/>
    <MENU id="MENU_ID_OPTRSER_WEATHER" str="STR_ID_OPTRSER_WEATHER" img="IMG_ID_OPTRSER_WEATHER"/>
    <MENU id="MENU_ID_OPTRSER_FETION" str="STR_ID_OPTRSER_FETION" img="IMG_ID_OPTRSER_FETION"/>
    <MENU id="MENU_ID_OPTRSER_VIDEO" str="STR_ID_OPTRSER_VIDEO" img="IMG_ID_OPTRSER_VIDEO"/>
    <MENU id="MENU_ID_OPTRSER_NEW" str="STR_ID_OPTRSER_NEW" img="IMG_ID_OPTRSER_NEW"/>
    <MENU id="MENU_ID_OPTRSER_MYMONWAP" str="STR_ID_OPTRSER_MYMONWAP" img="IMG_ID_OPTRSER_MYMONWAP"/>
    <MENU id="MENU_ID_OPTRSER_MONWAP" str="STR_ID_OPTRSER_MONWAP" img="IMG_ID_OPTRSER_MONWAP"/>
    <MENU id="MENU_ID_OPTRSER_MONSEARCH" str="STR_ID_OPTRSER_MONSEARCH" img="IMG_ID_OPTRSER_MONSEARCH"/>
#ifdef __MMI_OP01_DCD__
    <MENU id="MENU_ID_OPTRSER_DCD" str="STR_ID_OPTRSER_DCD" img="IMG_ID_OPTRSER_DCD"/>
#endif
#endif /* BROWSER_SUPPORT */

#ifdef __SYNCML_SUPPORT__
    <MENU id="MENU_ID_OPTRSER_PIM" str="STR_ID_OPTRSER_PIM" img="IMG_ID_OPTRSER_PIM"/>
#ifdef BROWSER_SUPPORT
    <MENUITEM id="MENU_ID_OPTRSER_PIM_ORDER" str="STR_ID_OPTRSER_PIM_ORDER" img="IMG_ID_OPTRSER_PIM_ORDER"/>
    <MENUITEM id="MENU_ID_OPTRSER_PIM_CHECK" str="STR_ID_OPTRSER_PIM_CHECK" img="IMG_ID_OPTRSER_PIM_CHECK"/>
#endif
    <MENUITEM id="MENU_ID_OPTRSER_PIM_PB" str="STR_ID_OPTRSER_PIM_PB" img="IMG_ID_OPTRSER_PIM_PB"/>
    <MENUITEM id="MENU_ID_OPTRSER_PIM_SETTING" str="STR_ID_OPTRSER_PIM_SETTING" img="IMG_ID_OPTRSER_PIM_SETTING"/>
    <MENUITEM id="MENU_ID_OPTRSER_PIM_SYNC" str="STR_ID_OPTRSER_PIM_SYNC" img="IMG_ID_OPTRSER_PIM_SYNC"/>

    <MENU id="MENU_ID_OPTRSER_PIM_ENTER" type="APP_SUB" str="STR_ID_OPTRSER_PIM" img="IMG_ID_OPTRSER_PIM">
        <MENUITEM_ID>MENU_ID_OPTRSER_PIM_ORDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_OPTRSER_PIM_SYNC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_OPTRSER_PIM_PB</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_OPTRSER_PIM_CHECK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_OPTRSER_PIM_SETTING</MENUITEM_ID>
    </MENU>
#endif /* __SYNCML_SUPPORT__ */
#endif /* __OP01__ */

#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    <MENU id="MENU_ID_OPTRSER_STK1" str="STR_ID_OPTRSER_STK1" img="IMG_ID_OPTRSER_STK1"/>
    <MENU id="MENU_ID_OPTRSER_STK2" str="STR_ID_OPTRSER_STK2" img="IMG_ID_OPTRSER_STK2"/>
#endif
	<MENU id="MENU_ID_OPTRSER_STK" str="STR_ID_OPTRSER_STK" img="IMG_ID_OPTRSER_STK">
		<MENUITEM_ID>MENU_ID_OPTRSER_STK1</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_OPTRSER_STK2</MENUITEM_ID>
	</MENU>

#ifdef __OP02__
    <MENUITEM id="MENU_ID_OPTRSER_MUSIC" str="STR_ID_OPTRSER_MUSIC" img="IMG_ID_OPTRSER_MUSIC"/>
#ifdef BROWSER_SUPPORT
    <MENUITEM id="MENU_ID_OPTRSER_NEWS" str="STR_ID_OPTRSER_NEWS" img="IMG_ID_OPTRSER_NEWS"/>
#endif
    <MENUITEM id="MENU_ID_OPTRSER_HOTLINE" str="STR_ID_OPTRSER_HOTLINE" img="IMG_ID_OPTRSER_HOTLINE"/>
    <MENUITEM id="MENU_ID_OPTRSER_GUIDE" str="STR_ID_OPTRSER_GUIDE" img="IMG_ID_OPTRSER_GUIDE"/>
#if ((defined __MMI_OP02_MAINMENU_9MATRIX__) || (defined __OP02_0200__))
    <MENUITEM id="MENU_ID_OPTRSER_MOBILE_TV" str="STR_ID_OPTRSER_MOBILE_TV" img="IMG_ID_OPTRSER_MOBILE_TV"/>
    <MENUITEM id="MENU_ID_OPTRSER_PUSH_MAIL" str="STR_ID_OPTRSER_PUSH_MAIL" img="IMG_ID_OPTRSER_PUSH_MAIL"/>
    <MENUITEM id="MENU_ID_OPTRSER_MOBILE_STOCK" str="STR_ID_OPTRSER_MOBILE_STOCK" img="IMG_ID_OPTRSER_MOBILE_STOCK"/>
#endif /* (defined __MMI_OP02_MAINMENU_9MATRIX__) || (defined __OP02_0200__) */
#ifdef __OP02_0200__
    <MENUITEM id="MENU_ID_OPTRSER_116114" str="STR_ID_OPTRSER_116114" img="IMG_ID_OPTRSER_116114"/>
    <MENUITEM id="MENU_ID_OPTRSER_ONLINE_SALES" str="STR_ID_OPTRSER_ONLINE_SALES" img="IMG_ID_OPTRSER_ONLINE_SALES"/>
    <MENUITEM id="MENU_ID_OPTRSER_STORE" str="STR_ID_OPTRSER_STORE" img="IMG_ID_OPTRSER_STORE"/>
#ifdef __MMI_OP02_LEMEI__
    <MENUITEM id="MENU_ID_OPTRSER_LEMEI" str="STR_ID_OPTRSER_LEMEI" img="IMG_ID_OPTRSER_LEMEI"/>
#endif
#ifdef BROWSER_SUPPORT
#ifdef __MMI_OP02_WO_PORTAL__
    <MENUITEM id="MENU_ID_OPTRSER_PORTAL" str="STR_ID_OPTRSER_PORTAL" img="IMG_ID_OPTRSER_PORTAL"/>
#else
    <MENUITEM id="MENU_ID_OPTRSER_MOWAP" str="STR_ID_OPTRSER_MOWAP" img="IMG_ID_OPTRSER_MOWAP"/>
#endif
    <MENUITEM id="MENU_ID_OPTRSER_READ" str="STR_ID_OPTRSER_READ" img="IMG_ID_OPTRSER_READ"/>
#endif
#endif /* __OP02_0200__ */
#endif /* __OP02__ */

    <!------------------------------------------------------Screen Resource--------------------------------------------------------->
    <SCREEN id="GRP_ID_MOBILE_SERVICE"/>
    <SCREEN id="GRP_ID_PIM"/>
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    <SCREEN id="GRP_ID_STK"/>
#endif    
#ifdef __OP01__
    <SCREEN id="SCR_ID_OPTRSER_PIM_INTRO"/>
#endif
#ifdef __OP02__
#ifdef __OP02_0200__
    <SCREEN id="GRP_ID_USIM_APP"/>
#endif
    <SCREEN id="SCR_ID_OPTRSER_GUIDE"/>
#endif

    <!------------------------------------------------------Callback Mgr Resource Area------------------------------------------------------->    
#if (defined __SIM_HOT_SWAP_SUPPORT__) || (defined __SIM_RECOVERY_ENHANCEMENT__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_optrser_sim_ctrl_detected_hdlr"/>
#endif

    <!------------------------------------------------------MMI Cache--------------------------------------------------------------->
#ifdef __MMI_OP01_SYNCML_SETTING__
    <CACHEDATA type="byte" id="NVRAM_PIM_DEFAULT_ACCOUNT">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> PIM Account </DESCRIPTION>
    </CACHEDATA>
#else
    <CACHEDATA type="byte" id="NVRAM_PIM_DEFAULT_ACCOUNT">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif  /* __MMI_OP01_SYNCML_SETTING__ */

#endif /* __MMI_MOBILE_SERVICE__ */

</APP>

