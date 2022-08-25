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
 *   NetSetApp.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file
 *
 * Author:
 * -------
 *   Xiangjun Dan
 *
 *******************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"
#include "PhoneSetupSlim.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_NETSET">
    <INCLUDE file = "GlobalResDef.h"/>
	<INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>  
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--Network Setup String-->
//    <STRING id="STR_ID_NETSET_MAIN"/>
#if( MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_NETSET_SIM3"/>
#endif
#if(MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_NETSET_SIM4"/>
#endif

    <!--NetSet Network Selection-->
	<STRING id="STR_ID_NETSET_NETWORK_SELECTION"/>
#ifdef __MANUAL_MODE_NW_SEL__
   #ifndef __MMI_NETSET_SLIM__	
	<STRING id="STR_ID_NETSET_NETSEL_NEW_SEARCH"/>
	<STRING id="STR_ID_NETSET_NETSEL_SELECT_NETWORK"/>
	#endif
#endif
	<STRING id="STR_ID_NETSET_NETSEL_SELECTION_MODE"/>
	<STRING id="STR_ID_NETSET_NETSEL_NETWORK_LIST"/>
	<STRING id="STR_ID_NETSET_NW_LIST_FAIL"/>
	<STRING id="STD_ID_NETSET_NW_SELECT_FAIL"/>
	<STRING id="STR_ID_NETSET_REGISTERING_NW"/>
#ifdef __REL7__
        <STRING id="STR_ID_NETSET_NETSEL_ADDITIONAL_INFO"/>
#endif
    <!--Network selection 3G enhancement-->
#ifdef __MMI_NETSET_3G_ENHANCE__    
    <STRING id="STR_ID_NETSET_3G_CHANGE_AUTO"/>
    <STRING id="STR_ID_NETSET_3G_SERVICE_INVALID_TITLE"/>
#endif	
	<!--NetSet Preferences-->
#ifdef __MMI_PREF_NETWORK__
	<STRING id="STR_ID_NETSET_PREF_LIST"/>
	<STRING id="STR_ID_NETSET_PRF_NWK_ADD"/>
	<STRING id="STR_ID_NETSET_PRF_NWK_NEW"/>
	<STRING id="STR_ID_NETSET_PRF_NWK_EDIT"/>
	<STRING id="STR_ID_NETSET_PRF_ADD_SHW_NWK_TITLE"/>
	<STRING id="STR_ID_NETSET_PRF_NWK_ADDED_ERR"/>
	<STRING id="STR_ID_NETSET_PRF_NWK_INVALID_MCCMNC"/>
	<STRING id="STR_ID_NETSET_PREF_LIST_MCC_MNC"/>
	<STRING id="STR_ID_NETSET_DELETE_QUERY"/>	
#endif /* __MMI_PREF_NETWORK__ */
	<!--NetSet Preferred Mode-->
#ifdef __MMI_WLAN_FEATURES__
	<STRING id="STR_ID_NETSET_PREF_MODE"/>
	<STRING id="STR_ID_NETSET_PREF_MODE_GSM_ONLY"/>
	<STRING id="STR_ID_NETSET_PREF_MODE_WLAN_ONLY"/>
	<STRING id="STR_ID_NETSET_PREF_MODE_GSM_PREF"/>
	<STRING id="STR_ID_NETSET_PREF_MODE_WLAN_PREF"/>
#endif /* __MMI_WLAN_FEATURES__ */

	<!--NetSet Service Selection-->
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)	
	<STRING id="STR_ID_NETSET_SERVICE_SELECTION"/>
	<STRING id="STR_ID_NETSET_ITEM_GSM"/>
	<STRING id="STR_ID_NETSET_ITEM_WCDMA"/>
	<STRING id="STR_ID_NETSET_ITEM_TDSCDMA"/>
	<STRING id="STR_ID_NETSET_ITEM_ALL"/>
#endif
	
	<!--NetSet Network Information-->

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)	
	<STRING id="STR_ID_NETSET_SERVICE"/>
	<STRING id="STR_ID_NETSET_NETWORK_INFO"/>
	<STRING id="STR_ID_NETSET_OPERATOR"/>
	<STRING id="STR_ID_NETSET_NO_SERVICE"/>
	<STRING id="STR_ID_NETSET_FULL_SERVICE"/>
	<STRING id="STR_ID_NETSET_LIMITED_SERVICE"/>
	<STRING id="STR_ID_NETSET_NETWORK_STATUS"/>
#endif	
#ifdef __MMI_NETSET_3G_ENHANCE__
    <STRING id="STR_ID_NETSET_3G_NO_SERVICE_INFO"/>
#endif    
	<!--NetSet GPRS Connection-->
#ifdef __MMI_GPRS_FEATURES__	
	<STRING id="STR_ID_NETSET_GPRS_CONNECTION"/>
	<STRING id="STR_ID_NETSET_GPRS_CONNECTION_ALWAYS"/>
	<STRING id="STR_ID_NETSET_GPRS_CONNECTION_WHENNEEDED"/>
#endif /* __MMI_GPRS_FEATURES__ */

	<!--NetSet PCH Monitor-->
#ifdef __MONITOR_PAGE_DURING_TRANSFER__	
	<STRING id="STR_ID_NETSET_PCH"/>
	<STRING id="STR_ID_NETSET_PCH_DATA_PREFER"/>
	<STRING id="STR_ID_NETSET_PCH_CALL_PREFER"/>
#ifndef __MMI_NETSET_SLIM__
	<STRING id="STR_ID_NETSET_PCH_QUERY"/>
#endif
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

	<!--NetSet HSPA-->
#ifdef __UMTS_FDD_MODE__	
#ifdef __HSPA_PREFERENCE_SETTING__	
#ifdef __DYNAMIC_HSPA_PREFERENCE__
	<STRING id="STR_ID_NETSET_HSPA"/>
	<STRING id="STR_ID_NETSET_HSPA_CONFIRM_ASK"/>
	<STRING id="STR_ID_NETSET_HSPA_OFF"/>
	<STRING id="STR_ID_NETSET_HSDPA_ON"/>
	<STRING id="STR_ID_NETSET_HSDPA_HSUPA_ON"/>
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif	
	<!--Network Setup String-->
#ifdef __MMI_WLAN_FEATURES__	
	<STRING id="STR_ID_NETSET_WLAN_OFF"/>	
	<STRING id="STR_ID_NETSET_WLAN_ON"/>	
	<STRING id="STR_ID_NETSET_INVALID_WLAN"/>		
#endif

	<!--Network 3G service switch String-->
#ifdef __MMI_3G_SWITCH__
	<STRING id="STR_ID_NETSET_3G_SERVICE_SWITCH"/>	
	<STRING id="STR_ID_NETSET_3G_SERVICE_SWITCH_PROGRESS"/>	
	<STRING id="STR_ID_NETSET_3G_SERVICE_SWITCH_QUERY"/> 
#endif

    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Network Setup Image-->
#ifndef __MMI_NETSET_SLIM__	
	<IMAGE id="IMG_SETTING_NETWORK">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\meeting.bmp"</IMAGE>
#endif
	<IMAGE id="IMG_ID_NETSET_HOME_PLMN">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\ST_HOME.bmp"</IMAGE>
	<IMAGE id="IMG_ID_NETSET_UNKNOWN_PLMN">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_Unknow.bmp"</IMAGE>
	<IMAGE id="IMG_ID_NETSET_FORBIDDEN_PLMN">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_Off.bmp"</IMAGE>
    <!--Network Setup Image-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Audio Resource Area-->
	<!--Network Setup Audio-->
	
	<!--Network Setup Audio-->
	<!--End Audio Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Media Resource Area-->
	<!--Network Setup Media-->
	<!--Network Setup Media-->
	<!--End Media Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Network Setup Group-->
    <SCREEN id = "GRP_ID_NETSET_MAIN"/>
    <SCREEN id = "GRP_ID_NETSET_NW_SELECT"/>
	<SCREEN id = "GRP_ID_NETSET_PREF_MODE"/>
	<SCREEN id = "GRP_ID_NETSET_PREF_LIST"/>
	<SCREEN id = "GRP_ID_NETSET_SERVICE_SELECTION"/>
#ifdef __MMI_3G_SWITCH__
	<SCREEN id = "GRP_ID_NETSET_3G_SERVICE_SWITCH"/>
#endif
	<!--Network Setup Group-->
	
	<!--Network Setup Screen-->
	<SCREEN id = "SCR_ID_NETSET_MAIN"/>
	<SCREEN id = "SCR_ID_NETSET_SIM"/>
	
	<!--NetSet Network Selection-->
	<SCREEN id = "SCR_ID_NETSET_NETWORK_SELECTION"/>
	<SCREEN id = "SCR_ID_NETSET_NETWORK_SELECTION_REGISTER_PROGRESS"/>
	<SCREEN id = "SCR_ID_NETSEL_AUTO_REGISTER_PROGRESS"/>
	<SCREEN id = "SCR_ID_NETSEL_MANUAL_SEARCH_PROGRESS"/>
	<SCREEN id = "SCR_ID_NETSEL_MANUAL_REGISTER_PROGRESS"/>
	<SCREEN id = "SCR_ID_NETSEL_MANUAL_SEARCH_SHOW_PLMN"/>
	<SCREEN id = "SCR_ID_NETSEL_SELECT_MODE"/>
	<SCREEN id = "SCR_ID_NETSEL_ADDTIONAL_INFORMATION"/>
	<SCREEN id = "SCR_ID_NETSEL_ADDTIONAL_INFORMATION_PROGRESS"/>
	
	<!--NetSet Preferences-->
	#ifdef __MMI_PREF_NETWORK__
	<SCREEN id = "SCR_ID_NETSET_PREF_LIST"/>
	<SCREEN id = "SCR_ID_NETSET_PREF_LIST_OPT_ADD_NWK_LIST"/>
	<SCREEN id = "SCR_ID_NETSET_PREF_LIST_OPT_ADD_NWK_LIST_INFO"/>
	#endif /* __MMI_PREF_NETWORK__ */
    
	<!--NetSet Preferred Mode-->	
	<SCREEN id = "SCR_ID_NETSET_PREF_MODE"/>
	<SCREEN id = "SCR_ID_NETSET_PREF_MODE_PROGRESS"/>

    <!--NetSet Service Selection-->
	<SCREEN id = "SCR_ID_NETSET_SERVICE_SELECTION"/>
	<SCREEN id = "SCR_ID_NETSET_SET_RAT_PROGRESS"/>
	<SCREEN id = "SCR_ID_NETSET_RAT_QUERY"/>
	
	<!--NetSet Network Information-->
	<SCREEN id = "SCR_ID_NETSET_NETWORK_INFO"/>	
	
    <!--NetSet GPRS Connection-->
	<SCREEN id = "SCR_ID_NETSET_GPRS_CONNECTION"/>	
	<SCREEN id = "SCR_ID_NETSET_SET_GPRS_PROGRESS"/>	
	
	<!--NetSet PCH Monitor-->
	<SCREEN id = "SCR_ID_NETSET_SET_PCH_PROGRESS"/>	
	<SCREEN id = "SCR_ID_NETSET_SET_PCH_CONFIRM"/>
	
    <!--NetSet HSPA-->
	<SCREEN id = "SCR_ID_NETSET_HSPA"/>	
	<SCREEN id = "SCR_ID_NETSET_HSPA_PROGRESS"/>
	<SCREEN id = "SCR_ID_NETSET_HSPA_LIST"/>
	
	
    <!--NetSet 3G switch-->
#ifdef __MMI_3G_SWITCH__
	<SCREEN id = "SCR_ID_NETSET_3G_SERVICE_SWITCH"/>
	<SCREEN id = "SCR_ID_NETSET_3G_SERVICE_SWITCH_PROGRESS"/>
#endif
	
    <!--Network Setup Screen-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Network Setup Menu Item-->

    
#ifdef __MMI_DUAL_SIM_MASTER__    
   #ifndef __MMI_NETSET_SLIM__
		<MENU id="MENU_ID_NETSET_MAIN" parent="MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_GLOBAL_NETWORK_SETTINGS" img="IMG_SETTING_NETWORK" highlight="mmi_highlight_netset_main">
   #else
        <MENU id="MENU_ID_NETSET_MAIN" parent="MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_GLOBAL_NETWORK_SETTINGS" highlight="mmi_highlight_netset_main">
   #endif
				<MENUITEM_ID>MENU_ID_NETSET_SIM1</MENUITEM_ID>
				<MENUITEM_ID>MENU_ID_NETSET_SIM2</MENUITEM_ID>
        #if(GEMINI_PLUS >= 3)		
				<MENUITEM_ID>MENU_ID_NETSET_SIM3</MENUITEM_ID>
	#endif
	#if(GEMINI_PLUS >= 4)	
				<MENUITEM_ID>MENU_ID_NETSET_SIM4</MENUITEM_ID>
	#endif
	#ifdef __MMI_WLAN_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_MODE</MENUITEM_ID>
    	#endif
		#ifdef __MONITOR_PAGE_DURING_TRANSFER__
				<MENUITEM_ID>MENU_ID_NETSET_PCH_MODE</MENUITEM_ID>
		#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */    
		#ifdef __MMI_3G_SWITCH__
				<MENUITEM_ID>MENU_ID_NETSET_3G_SERVICE_SWITCH</MENUITEM_ID>
		#endif /* __MMI_3G_SWITCH__ */
    </MENU>
    
    		
		<MENU id="MENU_ID_NETSET_SIM1" type="APP_SUB" str="STR_GLOBAL_SIM_1">
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_SELECTION</MENUITEM_ID>
	    #ifdef __MMI_PREF_NETWORK__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_LIST</MENUITEM_ID>
	    #endif /* __MMI_PREF_NETWORK__ */
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
        #if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
				<MENUITEM_ID>MENU_ID_NETSET_SERVICE_SELECTION</MENUITEM_ID>
		#endif
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_INFO</MENUITEM_ID>
		#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
		#ifdef __MMI_GPRS_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_GPRS_CONNECTION</MENUITEM_ID>
		#endif /* __MMI_GPRS_FEATURES__ */
        #ifdef __UMTS_FDD_MODE__
		#ifdef __HSPA_PREFERENCE_SETTING__
        #ifdef __DYNAMIC_HSPA_PREFERENCE__
        #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
				<MENUITEM_ID>MENU_ID_NETSET_HSPA_MODE</MENUITEM_ID>
	    #endif /* defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) */
		#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
		#endif /* __HSPA_PREFERENCE_SETTING__ */
        #endif
		</MENU>	
    
		<MENU id="MENU_ID_NETSET_SIM2" type="APP_SUB" str="STR_GLOBAL_SIM_2">
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_SELECTION</MENUITEM_ID>
		#ifdef __MMI_PREF_NETWORK__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_LIST</MENUITEM_ID>
		#endif /* __MMI_PREF_NETWORK__ */

		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
		#ifdef __MMI_3G_SWITCH__
        #if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
				<MENUITEM_ID>MENU_ID_NETSET_SERVICE_SELECTION</MENUITEM_ID>
	    #endif
		#endif /* __MMI_3G_SWITCH__ */
		
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_INFO</MENUITEM_ID>
		#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
		#ifdef __MMI_GPRS_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_GPRS_CONNECTION</MENUITEM_ID>
		#endif /* __MMI_GPRS_FEATURES__ */
		
		#ifdef __MMI_3G_SWITCH__
        #ifdef __UMTS_FDD_MODE__
        #ifdef __HSPA_PREFERENCE_SETTING__
        #ifdef __DYNAMIC_HSPA_PREFERENCE__
        #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
        		<MENUITEM_ID>MENU_ID_NETSET_HSPA_MODE</MENUITEM_ID>
        #endif /* defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) */
        #endif /* __DYNAMIC_HSPA_PREFERENCE__ */
        #endif /* __HSPA_PREFERENCE_SETTING__ */
        #endif /* __UMTS_FDD_MODE__ */
		#endif /* __MMI_3G_SWITCH__ */
		
		</MENU>	
#if( GEMINI_PLUS >= 3)		
		<MENU id="MENU_ID_NETSET_SIM3" type="APP_SUB" str="STR_GLOBAL_SIM_3">
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_SELECTION</MENUITEM_ID>
		#ifdef __MMI_PREF_NETWORK__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_LIST</MENUITEM_ID>
		#endif /* __MMI_PREF_NETWORK__ */
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
        #if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
				<MENUITEM_ID>MENU_ID_NETSET_SERVICE_SELECTION</MENUITEM_ID>
		#endif
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_INFO</MENUITEM_ID>
		#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
		#ifdef __MMI_GPRS_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_GPRS_CONNECTION</MENUITEM_ID>
		#endif /* __MMI_GPRS_FEATURES__ */
		#ifdef __HSPA_PREFERENCE_SETTING__
        #ifdef __DYNAMIC_HSPA_PREFERENCE__
				<MENUITEM_ID>MENU_ID_NETSET_HSPA_MODE</MENUITEM_ID>
		#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
		#endif /* __HSPA_PREFERENCE_SETTING__ */
		</MENU>
#endif
#if( GEMINI_PLUS >= 4)		
		<MENU id="MENU_ID_NETSET_SIM4" type="APP_SUB" str="STR_GLOBAL_SIM_4">
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_SELECTION</MENUITEM_ID>
		#ifdef __MMI_PREF_NETWORK__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_LIST</MENUITEM_ID>
		#endif /* __MMI_PREF_NETWORK__ */
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
        #if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
				<MENUITEM_ID>MENU_ID_NETSET_SERVICE_SELECTION</MENUITEM_ID>
		#endif
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_INFO</MENUITEM_ID>
		#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
		#ifdef __MMI_GPRS_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_GPRS_CONNECTION</MENUITEM_ID>
		#endif /* __MMI_GPRS_FEATURES__ */
		#ifdef __HSPA_PREFERENCE_SETTING__
        #ifdef __DYNAMIC_HSPA_PREFERENCE__
				<MENUITEM_ID>MENU_ID_NETSET_HSPA_MODE</MENUITEM_ID>
		#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
		#endif /* __HSPA_PREFERENCE_SETTING__ */
		</MENU>
#endif
#ifndef __MMI_NETSET_SLIM__
		<MENU id="MENU_ID_NETSET_NETWORK_SELECTION" parent="MENU_ID_NETSET_SIM1" type="APP_SUB" str="STR_ID_NETSET_NETWORK_SELECTION">
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_AUTO</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_MANUAL</MENUITEM_ID>
#ifdef __MANUAL_MODE_NW_SEL__    		
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_SELECT_MODE</MENUITEM_ID>
#endif /* __MANUAL_MODE_NW_SEL__ */
		</MENU>
#endif		
		
#ifndef __MMI_NETSET_SLIM__		
		<MENU id="MENU_ID_NETSET_NETWORK_SELECTION" parent="MENU_ID_NETSET_SIM2" type="APP_SUB" str="STR_ID_NETSET_NETWORK_SELECTION">
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_AUTO</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_MANUAL</MENUITEM_ID>
#ifdef __MANUAL_MODE_NW_SEL__    		
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_SELECT_MODE</MENUITEM_ID>
#endif /* __MANUAL_MODE_NW_SEL__ */
		</MENU>
#endif			
		
#if(GEMINI_PLUS >= 3)			
#ifndef __MMI_NETSET_SLIM__			
		<MENU id="MENU_ID_NETSET_NETWORK_SELECTION" parent="MENU_ID_NETSET_SIM3" type="APP_SUB" str="STR_ID_NETSET_NETWORK_SELECTION">
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_AUTO</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_MANUAL</MENUITEM_ID>
#ifdef __MANUAL_MODE_NW_SEL__    		
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_SELECT_MODE</MENUITEM_ID>
#endif /* __MANUAL_MODE_NW_SEL__ */
		</MENU>
#endif			
#endif /*(GEMINI_PLUS >= 3)*/	

#if(GEMINI_PLUS >= 4)	
#ifndef __MMI_NETSET_SLIM__
		<MENU id="MENU_ID_NETSET_NETWORK_SELECTION" parent="MENU_ID_NETSET_SIM4" type="APP_SUB" str="STR_ID_NETSET_NETWORK_SELECTION">
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_AUTO</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_MANUAL</MENUITEM_ID>
#ifdef __MANUAL_MODE_NW_SEL__    		
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_SELECT_MODE</MENUITEM_ID>
#endif /* __MANUAL_MODE_NW_SEL__ */
		</MENU>
#endif			
#endif/*(GEMINI_PLUS >= 4)	*/
		
#else /* __MMI_DUAL_SIM_MASTER__  */
    #ifndef __MMI_NETSET_SLIM__		
		<MENU id="MENU_ID_NETSET_MAIN" parent="MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_GLOBAL_NETWORK_SETTINGS" img="IMG_SETTING_NETWORK" highlight="mmi_highlight_netset_main">
    #else
        <MENU id="MENU_ID_NETSET_MAIN" parent="MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_GLOBAL_NETWORK_SETTINGS" highlight="mmi_highlight_netset_main">
    #endif
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_SELECTION</MENUITEM_ID>
		#ifdef __MMI_PREF_NETWORK__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_LIST</MENUITEM_ID>
		#endif /* __MMI_PREF_NETWORK__ */
		#ifdef __MMI_WLAN_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_PREF_MODE</MENUITEM_ID>
		#endif /* __MMI_WLAN_FEATURES__ */
		#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
        #if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
				<MENUITEM_ID>MENU_ID_NETSET_SERVICE_SELECTION</MENUITEM_ID>
		#endif
				<MENUITEM_ID>MENU_ID_NETSET_NETWORK_INFO</MENUITEM_ID>
		#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
		#ifdef __MMI_GPRS_FEATURES__
				<MENUITEM_ID>MENU_ID_NETSET_GPRS_CONNECTION</MENUITEM_ID>
		#endif /* __MMI_GPRS_FEATURES__ */
		#ifdef __MONITOR_PAGE_DURING_TRANSFER__
				<MENUITEM_ID>MENU_ID_NETSET_PCH_MODE</MENUITEM_ID>
		#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */		
        #ifdef __UMTS_FDD_MODE__
		#ifdef __HSPA_PREFERENCE_SETTING__
        #ifdef __DYNAMIC_HSPA_PREFERENCE__
        #if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
				<MENUITEM_ID>MENU_ID_NETSET_HSPA_MODE</MENUITEM_ID>
		#endif /* defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) */
        #endif /* __DYNAMIC_HSPA_PREFERENCE__ */				
		#endif /* __HSPA_PREFERENCE_SETTING__ */				
        #endif
    </MENU>
    
#ifndef __MMI_NETSET_SLIM__    
    <MENU id="MENU_ID_NETSET_NETWORK_SELECTION" type="APP_SUB" str="STR_ID_NETSET_NETWORK_SELECTION">
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_AUTO</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_MANUAL</MENUITEM_ID>
#ifdef __MANUAL_MODE_NW_SEL__    		
    		<MENUITEM_ID>MENU_ID_NETSET_NETSEL_SELECT_MODE</MENUITEM_ID>
#endif /* __MANUAL_MODE_NW_SEL__ */
	</MENU>
#endif		
		
#endif /* __MMI_DUAL_SIM_MASTER__ */
    		

#ifdef __MANUAL_MODE_NW_SEL__
   #ifndef __MMI_NETSET_SLIM__
    <MENUITEM id="MENU_ID_NETSET_NETSEL_AUTO" str="STR_ID_NETSET_NETSEL_NEW_SEARCH"/>
    <MENUITEM id="MENU_ID_NETSET_NETSEL_MANUAL" str="STR_ID_NETSET_NETSEL_SELECT_NETWORK"/>
    <MENUITEM id="MENU_ID_NETSET_NETSEL_SELECT_MODE" str="STR_ID_NETSET_NETSEL_SELECTION_MODE"/>
   #else
    <MENUITEM id="MENU_ID_NETSET_NETWORK_SELECTION" str="STR_ID_NETSET_NETWORK_SELECTION"/>
   #endif 
#else /* __MANUAL_MODE_NW_SEL__ */
   #ifndef __MMI_NETSET_SLIM__  
	<MENUITEM id="MENU_ID_NETSET_NETSEL_AUTO" str="STR_GLOBAL_AUTOMATIC"/>
	<MENUITEM id="MENU_ID_NETSET_NETSEL_MANUAL" str="STR_GLOBAL_MANUAL"/>
    #else /*__MMI_NETSET_SLIM__*/
        <MENUITEM id="MENU_ID_NETSET_NETWORK_SELECTION" str="STR_ID_NETSET_NETWORK_SELECTION"/>
   #endif /*__MMI_NETSET_SLIM__*/
#endif /* __MANUAL_MODE_NW_SEL__ */

#ifdef __MMI_PREF_NETWORK__    
    <MENUITEM id="MENU_ID_NETSET_PREF_LIST" str="STR_ID_NETSET_PREF_LIST"/>

		<MENU id="MENU_ID_NETSET_PREF_LIST_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_NETSET_PREF_LIST_OPTION_ADD" str="STR_ID_NETSET_PRF_NWK_ADD"/>
        <MENUITEM id="MENU_ID_NETSET_PREF_LIST_OPTION_NEW" str="STR_ID_NETSET_PRF_NWK_NEW"/>
        <MENUITEM id="MENU_ID_NETSET_PREF_LIST_OPTION_EDIT" str="STR_ID_NETSET_PRF_NWK_EDIT"/>
        <MENUITEM id="MENU_ID_NETSET_PREF_LIST_OPTION_DELETE" str="STR_GLOBAL_DELETE"/>
    </MENU>
#endif /* __MMI_PREF_NETWORK__ */  

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
#if !defined(__MMI_EM_NW_SERVICE_MODE_SELECTION__)
    <MENUITEM id="MENU_ID_NETSET_SERVICE_SELECTION" str="STR_ID_NETSET_SERVICE_SELECTION"/>
#endif    
    <MENUITEM id="MENU_ID_NETSET_NETWORK_INFO" str="STR_ID_NETSET_NETWORK_INFO"/>
#endif /* #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#ifdef __MMI_GPRS_FEATURES__
    <MENUITEM id="MENU_ID_NETSET_GPRS_CONNECTION" str="STR_ID_NETSET_GPRS_CONNECTION"/>
#endif /* __MMI_GPRS_FEATURES__ */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    <MENUITEM id="MENU_ID_NETSET_PCH_MODE" str="STR_ID_NETSET_PCH"/>
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __UMTS_FDD_MODE__
#ifdef __HSPA_PREFERENCE_SETTING__
#ifdef __DYNAMIC_HSPA_PREFERENCE__
#if defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__)
	<MENUITEM id="MENU_ID_NETSET_HSPA_MODE" str="STR_ID_NETSET_HSPA"/>
#endif /* defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) */
#endif /* __DYNAMIC_HSPA_PREFERENCE__ */
#endif /* __HSPA_PREFERENCE_SETTING__ */
#endif
#ifdef __MMI_WLAN_FEATURES__
	<MENUITEM id="MENU_ID_NETSET_PREF_MODE" str="STR_ID_NETSET_PREF_MODE"/>
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_NETSET_3G_ENHANCE__
    <MENU id="MENU_ID_NETSET_3G_NOCELL_MENU" type="APP_MAIN" str="STR_ID_NETSET_3G_SERVICE_INVALID_TITLE" img="MAIN_MENU_TITLE_SETTINGS_ICON">
				<MENUITEM_ID>MENU_ID_NETSET_3G_CHANGE_AUTO</MENUITEM_ID>
				<MENUITEM_ID>MENU_ID_NETSET_NETSEL_MANUAL</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_NETSET_3G_CHANGE_AUTO" str="STR_ID_NETSET_3G_CHANGE_AUTO"/>
#endif    
#ifdef __MMI_3G_SWITCH__
	<MENUITEM id="MENU_ID_NETSET_3G_SERVICE_SWITCH" str="STR_ID_NETSET_3G_SERVICE_SWITCH"/>
#endif /* __MMI_3G_SWITCH__ */
#ifdef __MMI_WLAN_FEATURES__
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND" proc="mmi_netset_wlan_init_hdlr"/>
#endif    

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_netset_availability_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" proc="mmi_netset_availability_changed_hdlr"/>    
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_netset_availability_changed_hdlr"/>    

#ifdef __REL7__
    <MENU id="MENU_ID_NETSET_NETSEL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS" img="MAIN_MENU_TITLE_SETTINGS_ICON">
				<MENUITEM_ID>MENU_ID_NETSET_NETSEL_SELECT</MENUITEM_ID>
				<MENUITEM_ID>MENU_ID_NETSET_NETSEL_ADDITIONAL_INFO</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_NETSET_NETSEL_SELECT" str="STR_GLOBAL_SELECT"/>
    <MENUITEM id="MENU_ID_NETSET_NETSEL_ADDITIONAL_INFO" str="STR_ID_NETSET_NETSEL_ADDITIONAL_INFO"/>
#endif /* __REL7__ */

	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED" proc="mmi_nw_adp_on_home_plmn_changed"/>
	<RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_nw_adp_sim1_service_availability_changed"/>
	<!--Network Setup Menu Item-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->
   
</APP>

#endif

