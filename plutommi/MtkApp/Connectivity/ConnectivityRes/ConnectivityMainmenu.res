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
 *   connectivity main menu resource file with XML format.   
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
 * 03 22 2013 yunliu.mao
 * [MAUI_03363784] [SWPL Approved][Change feature]BT Dialer Package Check in
 * .setting menu hiden
 *
 * 01 08 2013 bhupender.tabiyad
 * [MAUI_03307344] [MT6260 pre-SQC][Blocking] cant find BT in main menu or connectivity menu in Classic launcher
 * .
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 06 11 2012 na.chen
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 06 11 2012 na.chen
 * [MAUI_03199297] [FTE2.0][Slim] FTE Launcher Main menu icon Slim on key launcher only projects
 * .
 *
 * 01 05 2012 xiangnan.qi
 * [MAUI_03089286] [Sonim_AT&T][Network]Data Services and International Data Roaming–Ë«Û∆¿π¿
 * .
 *
 * 10 27 2011 hongxi.shi
 * [MAUI_03064566] [Need Patch] [Sanity Fail] Sanity Test of MAUI\LUFFY76V22_DEMO_HSPA(FTE).W11.44 "no Connectivity" is Fail!!
 * .
 *
 * 10 24 2011 hongxi.shi
 * [MAUI_03053835] [UE]Shortcut main menu icon is missing.
 * .
 *
 * 10 10 2011 huilong.yin
 * [MAUI_03036704] [Phonebook]phb compile option revise
 * Pluto NFC.
 *
 * 09 30 2011 xiangnan.qi
 * [MAUI_03040003] [11B][NFC] MMI on/off setting for PLUTO and COSMOS
 * .
 *
 * 09 27 2011 zhanying.liu
 * [MAUI_03036737] when main menu show BTmenu,connectivity list should hide BT menu
 * .update bt menu compile option is connectivity
 *
 * 09 06 2011 yunpeng.li
 * [MAUI_03021579] [FTE Launcher] Check in code for Connectivity WLAN and Note
 * FTE Launcher Project - Note WLAN Connectivity.
 *
 * 08 30 2011 youzhong.cheng
 * [MAUI_03016518] [Data account UE enhancement] check in
 * Pluto part check in.
 *
 * 08 16 2011 youzhong.cheng
 * NULL
 * [Data account UE enhancement] pluto check in.
 *
 * 06 11 2011 jia.liu
 * [MAUI_02959671] Push Switch & Data Lock call for Check in
 * .
 *
 * 06 08 2011 guoyi.zhao
 * [MAUI_02957480] [Need Patch][Build Error] MAUI.W11.24 build error for LUFFY76V22_1G512_hspa(CU20_COSMOS_WVGA_11B)
 * .
 *
 * 06 07 2011 iris.chang
 * [MAUI_02956693] [Connection Management] Pluto CNMGR App/Srv Split
 * Pluto CNMGR app/srv split
 *
 * 06 02 2011 yixiong.zhao
 * [MAUI_02954526] [DM] App/Srv split check in
 * .
 *
 * 03 25 2011 guoyi.zhao
 * [MAUI_02657979] Fix connectivity resource build error
 * .
 *
 * 02 22 2011 youzhong.cheng
 * [MAUI_02652705] [cosmos rename] data account
 * .
 *
 * 02 22 2011 hongxi.shi
 * [MAUI_02652824] [check in] Remove pluto mainmenu res from cosmos project
 * .
 *
 * 01 21 2011 yunpeng.li
 * [MAUI_02649589] [RT][Shortcut case] Can't select WLAN
 * Modify res file to add shortcut for WLAN.
 *
 * 12 31 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * solve resgen error.
 *
 * 12 30 2010 yixiong.zhao
 * [MAUI_02643373] [RHR] Check-in
 * .
 *
 * 12 30 2010 yixiong.zhao
 * [MAUI_02643373] [RHR] Check-in
 * .
 *
 * 12 25 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * .
 *
 * 11 28 2010 leona.chou
 * [MAUI_02842306] [ABM] check in hal
 * .
 *
 * 11 28 2010 leona.chou
 * [MAUI_02842306] [ABM] check in hal
 * .
 *
 * 09 10 2010 hongxi.shi
 * [MAUI_02633743] [check in] 3D mainmenu code check in
 * .
 *
 * 09 03 2010 hongxi.shi
 * [MAUI_02633743] [check in] 3D mainmenu code check in
 * .
 *
 * Jul 8 2010 mtk80518
 * [MAUI_02221544] CMCC 240x400
 * 
 *
 * May 11 2010 mtk80047
 * [MAUI_02191992] [new feature]connectivity setting main menu MMI resource and setting shortcut UE rul
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

<APP id = "APP_CONNECTIVITY_MAINMENU"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
     package_name = "native.mtk.connectivity"   /* Use "native.mtk." as the prefix of application name */
     name = "STR_ID_CONNECTIVITY_TEXT"          /* The string to be displayed under the main menu icon */
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
     img = "IMG_ID_CONNECTIVITY_ICON"           /* Main menu icon image */
#endif
     launch = "mmi_connectivity_app_launch_func"/* Launch function of application. When tap on the icon in main menu, the function will be invoked. */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
    <INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_bluetooth_def.h"/>
#ifdef __PLUTO_MMI_PACKAGE__ 
#ifdef __NFC_SUPPORT__
    <INCLUDE file = "mmi_rp_app_nfc_def.h"/>
#endif  
#endif
#ifdef __PLUTO_MMI_PACKAGE__ 
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
#endif
#if (defined(__TCPIP__) && defined(__PLUTO_MMI_PACKAGE__))        
    <INCLUDE file = "mmi_rp_app_dataaccount_def.h"/>
#endif
#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__ )
    <INCLUDE file = "mmi_rp_app_connectmanage_def.h"/>
#endif 
#if defined (__MMI_IPSEC__) && defined(__MMI_VUI_3D_MAINMENU__)
		<INCLUDE file = "mmi_rp_app_ipsec_def.h"/>
#endif
#if defined(__MMI_TETHERING__) && defined(__PLUTO_MMI_PACKAGE__)
    <INCLUDE file = "mmi_rp_app_tethering_def.h"/>
#endif /* __MMI_TETHERING__ */
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_DATA_LOCK__)
    <INCLUDE file = "mmi_rp_app_data_service_def.h"/>
#endif
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_PUSH_TURN_ON_OFF_SWITCH__)
    <INCLUDE file = "mmi_rp_app_push_switch_def.h"/>
#endif

    <!-- string ----------------------------------------------------------------------------------->

    <STRING id = "STR_MENU_ID_CONNECTIVITY_TEXT"/>
    <STRING id = "STR_ID_CONNECTIVITY_TEXT"/>
#if !defined(__OPTR_NONE__)
#if defined (__WIFI_WIZARD_SUPPORT__) && defined (__MMI_WLAN_FEATURES__) 
    <STRING id = "MAIN_MENU_WLAN_TEXT"/>
#endif
#endif
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_DATA_LOCK__) 
	<STRING id = "STR_ID_DATA_ROAMING"/>
#endif


    <!-- image ------------------------------------------------------------------------------------>

    <IMAGE id = "IMG_MENU_ID_CONNECTIVITY_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\ST_connect.bmp"</IMAGE>
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) //MM_ICON
    <IMAGE id = "IMG_ID_CONNECTIVITY_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\launcher\\\\Mainmenu\\\\Icons\\\\Connect.png"</IMAGE>
#endif
#if !defined(__OPTR_NONE__)   
#if defined (__WIFI_WIZARD_SUPPORT__) && defined (__MMI_WLAN_FEATURES__) 
    <IMAGE id = "IMG_MENU_ID_CONNECTIVITY_WLAN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\BI_DEGREE\\\\MM_WF.png"</IMAGE>
#endif    
#endif


    <!-- screen ----------------------------------------------------------------------------------->


    <!-- menu ------------------------------------------------------------------------------------->
#ifdef __PLUTO_MMI_PACKAGE__ 
#if (!defined(__DISABLE_SHORTCUTS_MENU__) || defined (__WIFI_WIZARD_SUPPORT__) && defined (__MMI_WLAN_FEATURES__)) || !defined(__OPTR_NONE__)
    <MENU id = "MENU_ID_CONNECTIVITY" type = "APP_MAIN" str = "STR_MENU_ID_CONNECTIVITY_TEXT" parent = "MAIN_MENU_SETTINGS_MENUID" img = "IMG_MENU_ID_CONNECTIVITY_ICON" highlight = "HighlightConnectivity">
#else
    <MENU id = "MENU_ID_CONNECTIVITY" type = "APP_MAIN" str = "STR_MENU_ID_CONNECTIVITY_TEXT" parent = "IDLE_SCREEN_MENU_ID" img = "MAIN_MENU_CONNECTIVITY_ICON" highlight = "highlight_mainmenu_connectivity">
#endif
#else /*__PLUTO_MMI_PACKAGE__*/
	<MENU id = "MENU_ID_CONNECTIVITY" type = "APP_MAIN" str = "STR_MENU_ID_CONNECTIVITY_TEXT" img = "IMG_MENU_ID_CONNECTIVITY_ICON">
#endif
#if defined(__MMI_BT_SUPPORT__) && !defined(__MMI_VUI_3D_MAINMENU__) && (!defined(__MMI_APP_MANAGER_SUPPORT__)||defined(__MMI_LAUNCHER_APP_LIST__))
        
        <MENUITEM_ID>MENU_CONN_BT_MAIN</MENUITEM_ID>
#endif
#ifdef __PLUTO_MMI_PACKAGE__ 
#ifdef __NFC_SUPPORT__
		<MENUITEM_ID>MENU_CONN_NFC_MAIN</MENUITEM_ID>
#endif
#endif
#if (defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)) && defined(__MMI_IRDA_SUPPORT__)
        <MENUITEM_ID>@OID:MENU_CONN_IRDA_MAIN</MENUITEM_ID>
#endif
#if defined(__MMI_CBM_CONNECTION_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__ )
        <MENUITEM_ID>MENU_ID_CNMGR_APP</MENUITEM_ID>
#endif
#ifndef __BT_DIALER_PACKAGE__
#if (defined(__TCPIP__) && defined(__PLUTO_MMI_PACKAGE__))
        <MENUITEM_ID>MENU_ID_DATA_CONNECTION_SIM</MENUITEM_ID>
#endif
#if (defined(__TCPIP__) && defined(__PLUTO_MMI_PACKAGE__))
        <MENUITEM_ID>SERVICES_DATA_CONNECT_MAIN_MENU_ID</MENUITEM_ID>
#endif
#endif

#if !defined(__OPTR_NONE__)
#if defined (__WIFI_WIZARD_SUPPORT__) && defined (__MMI_WLAN_FEATURES__)
#ifdef __PLUTO_MMI_PACKAGE__ 
    <MENUITEM id="MAIN_MENU_WLAN_WIZARD_MENUID" str="MAIN_MENU_WLAN_TEXT" img="IMG_MENU_ID_CONNECTIVITY_WLAN_ICON" highlight="highlight_mainmenu_WiFi_wizard" 
    shortcut="ON" shortcut_img="IMG_MENU_ID_CONNECTIVITY_WLAN_ICON" launch="mmi_wlan_entry_wlan_wizard_new"/>
#else /*__PLUTO_MMI_PACKAGE__*/
    <MENUITEM id="MAIN_MENU_WLAN_WIZARD_MENUID" str="MAIN_MENU_WLAN_TEXT" img="IMG_MENU_ID_CONNECTIVITY_WLAN_ICON"/>
#endif /*__PLUTO_MMI_PACKAGE__*/
#endif /* defined (__WIFI_WIZARD_SUPPORT__) && defined (__MMI_WLAN_FEATURES__) */
#endif /* !defined(__OPTR_NONE__) */
#if defined (__MMI_IPSEC__) && defined(__MMI_VUI_3D_MAINMENU__)
				 <MENUITEM_ID>MENU_ID_IPSECAPP_SETTINGS</MENUITEM_ID>   // hongxi add
#endif

#ifdef __MMI_TETHERING__
    <MENUITEM_ID>MENU_ID_TETHERING</MENUITEM_ID>
#endif /* __MMI_TETHERING__ */

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_DATA_LOCK__)
    <MENUITEM_ID>MENU_ID_DATA_SERVICE</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_DATA_ROAMING</MENUITEM_ID>
#endif

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_PUSH_TURN_ON_OFF_SWITCH__)
    <MENUITEM_ID>MENU_ID_PUSH_SWITCH</MENUITEM_ID>
#endif
</MENU>

#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_DATA_LOCK__) 
	<!-- menu data roaming ----------------------------------------------------------------------------------->
	<MENU id="MENU_ID_DATA_ROAMING" type="APP_SUB" str="STR_ID_DATA_ROAMING" flag="RADIO" highlight="mmi_data_roaming_highlight_hdlr">
			<MENUITEM id="MENU_ID_DATA_ROAMING_OFF" str="STR_GLOBAL_OFF"/>
			<MENUITEM id="MENU_ID_DATA_ROAMING_ON" str="STR_GLOBAL_ON"/>
    </MENU>
#endif


</APP>

