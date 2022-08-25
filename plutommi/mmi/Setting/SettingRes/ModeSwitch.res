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
 *   ModeSwitch.res
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
 *   
 *
 *******************************************************************************/
 
#include "MMI_features.h"
#include "CustResDef.h"
#include "PhoneSetupSlim.h"
#ifdef __MMI_TELEPHONY_SUPPORT__
<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_MODE_SWITCH">

    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
#if (MMI_MAX_SIM_NUM >= 2)

    /* Mode Switch Type Menu String */
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    <STRING id="STR_ID_MODE_SWITCH_TYPE_2SIM"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_MODE_SWITCH_TYPE_3SIM"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_MODE_SWITCH_TYPE_4SIM"/>
#endif
#endif
    <STRING id="STR_ID_MODE_SWITCH_STATIC_MODE"/>
    <STRING id="STR_ID_MODE_SWITCH_DYNAMIC_MODE"/>
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
    
    /* Mode Switch Setting Menu String */
    <STRING id="STR_ID_MODE_SWITCH_SETTING_2SIM"/>
#if (MMI_MAX_SIM_NUM >= 3)    
    <STRING id="STR_ID_MODE_SWITCH_SETTING_3SIM"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_MODE_SWITCH_SETTING_4SIM"/>
#endif
#endif

    <STRING id="STR_ID_MODE_SWITCH_DUALCARD"/>
    <STRING id="STR_ID_MODE_SWITCH_CARD1"/>
    <STRING id="STR_ID_MODE_SWITCH_CARD2"/>
    <STRING id="STR_ID_MODE_SWITCH_FLIGHTMODE"/>        
    
    <STRING id="STR_ID_MODE_SWITCH_QUERY_CONFIRM"/>        
    <STRING id="STR_ID_MODE_SWITCH_QUERY_REMOVED_WITH_VALID_NW"/>

#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    <STRING id="STR_ID_MODE_SWITCH_RESET_MODE_CONFIRM"/>
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))  */   

#else /* (MMI_MAX_SIM_NUM >= 2) */
    
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    <STRING id="STR_ID_MODE_SWITCH_SWITCHING"/>
    <STRING id="STR_ID_MODE_SWITCH_INVALID"/>  
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	<STRING id = "STR_ID_NETSET_SETTING_SIM_NAME"/>
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    

	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
    <IMAGE id="IMG_ID_MODE_SWITCH_TYPE">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Settings\\\\SB_DMTYPE.bmp"</IMAGE>
#endif
#ifndef __MMI_NETSET_SLIM__
 	<IMAGE id="IMG_ID_MODE_SWITCH_SETTING">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\SETUP\\\\DM_SETUP.bmp"</IMAGE>
#endif
#else /* (MMI_MAX_SIM_NUM >= 2) */

#endif /* (MMI_MAX_SIM_NUM >= 2) */    
	<!--End Image Resource Area-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Audio Resource Area-->
	<!--Audio Resource Area-->
	<!--End Audio Resource Area-->
	<!--End Audio Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Media Resource Area-->
	<!--Media Resource Area-->
	<!--End Media Resource Area-->
	<!--End Media Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->       
	<!--Screen ID Area-->
    <SCREEN id = "SCR_ID_MODE_SWITCH_START"/>
    <SCREEN id = "SCR_ID_MODE_SWITCH_SIM_SELECTION"/>
    <SCREEN id = "SCR_ID_MODE_SWITCH_QUERY_CONFIRM"/>
    <SCREEN id = "SCR_ID_MODE_SWITCH_SWITCH_PROGRESS"/>
    <SCREEN id = "GRP_ID_MODE_SWITCH_SETTING"/>    
    <SCREEN id = "GRP_ID_MODE_SWITCH_TYPE"/>        
    <SCREEN id = "GRP_ID_MODE_SWITCH_QUERY"/>           
    <SCREEN id = "SCR_ID_MODE_SWITCH_END"/>

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	<SCREEN id = "GRP_ID_NETSET_SIM_NAME_SETTING"/>	
	<SCREEN id = "GRP_ID_NETSET_SIM_NAME_EDIT"/>
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    <!--End Screen Resource Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Menu Item Area-->
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__
        /* Mode Switch Dual SIM mode switch type menu */
#if (MMI_MAX_SIM_NUM == 4)
        <MENU id="MENU_ID_MODE_SWITCH_TYPE" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_TYPE_4SIM" img="IMG_ID_MODE_SWITCH_TYPE" highlight="mmi_highlight_mode_switch_type">
#elif (MMI_MAX_SIM_NUM == 3)
        <MENU id="MENU_ID_MODE_SWITCH_TYPE" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_TYPE_3SIM" img="IMG_ID_MODE_SWITCH_TYPE" highlight="mmi_highlight_mode_switch_type">
#else
        <MENU id="MENU_ID_MODE_SWITCH_TYPE" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_TYPE_2SIM" img="IMG_ID_MODE_SWITCH_TYPE" highlight="mmi_highlight_mode_switch_type">
#endif
        </MENU>
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
        /* Mode Switch Dual SIM mode switch type menu */
    
        /* Mode Switch Dual SIM mode switch setting menu */
#ifndef __MMI_NETSET_SLIM__       
#if (MMI_MAX_SIM_NUM == 4)
        <MENU id="MENU_ID_MODE_SWITCH_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_4SIM" img="IMG_ID_MODE_SWITCH_SETTING" highlight="mmi_highlight_mode_switch_setting">
#elif (MMI_MAX_SIM_NUM == 3)
        <MENU id="MENU_ID_MODE_SWITCH_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_3SIM" img="IMG_ID_MODE_SWITCH_SETTING" highlight="mmi_highlight_mode_switch_setting">
#else
        <MENU id="MENU_ID_MODE_SWITCH_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_2SIM" img="IMG_ID_MODE_SWITCH_SETTING" highlight="mmi_highlight_mode_switch_setting">
   #endif
#else
   #if (MMI_MAX_SIM_NUM == 4)
        <MENU id="MENU_ID_MODE_SWITCH_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_4SIM" highlight="mmi_highlight_mode_switch_setting">
   #elif (MMI_MAX_SIM_NUM == 3)
        <MENU id="MENU_ID_MODE_SWITCH_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_3SIM" highlight="mmi_highlight_mode_switch_setting">
   #else
        <MENU id="MENU_ID_MODE_SWITCH_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_2SIM" highlight="mmi_highlight_mode_switch_setting">
   #endif
#endif
            <MENUITEM_ID>MENU_ID_MODE_SWITCH_DUALCARD</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MODE_SWITCH_CARD1</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MODE_SWITCH_CARD2</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MODE_SWITCH_FLIGHTMODE</MENUITEM_ID>
        </MENU>

        <MENUITEM id="MENU_ID_MODE_SWITCH_DUALCARD" str="STR_ID_MODE_SWITCH_DUALCARD"/>
        <MENUITEM id="MENU_ID_MODE_SWITCH_CARD1" str="STR_ID_MODE_SWITCH_CARD1"/>
        <MENUITEM id="MENU_ID_MODE_SWITCH_CARD2" str="STR_ID_MODE_SWITCH_CARD2"/>
        <MENUITEM id="MENU_ID_MODE_SWITCH_FLIGHTMODE" str="STR_ID_MODE_SWITCH_FLIGHTMODE"/>
    
        /* Mode Switch Dual SIM mode switch setting menu */
    
#else /* (MMI_MAX_SIM_NUM >= 2) */
        
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#ifndef __MMI_NETSET_SLIM__		
#if (MMI_MAX_SIM_NUM == 4)
        <MENU id="MENU_ID_MODE_SWITCH_SIM_NAME" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_4SIM" img="IMG_ID_MODE_SWITCH_SETTING" highlight="mmi_highlight_mode_switch_setting">
#elif (MMI_MAX_SIM_NUM == 3)
        <MENU id="MENU_ID_MODE_SWITCH_SIM_NAME" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_3SIM" img="IMG_ID_MODE_SWITCH_SETTING" highlight="mmi_highlight_mode_switch_setting">
#else
        <MENU id="MENU_ID_MODE_SWITCH_SIM_NAME" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_2SIM" img="IMG_ID_MODE_SWITCH_SETTING" highlight="mmi_highlight_mode_switch_setting">
   #endif
#else
   #if (MMI_MAX_SIM_NUM == 4)
        <MENU id="MENU_ID_MODE_SWITCH_SIM_NAME" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_4SIM" highlight="mmi_highlight_mode_switch_setting">
   #elif (MMI_MAX_SIM_NUM == 3)
        <MENU id="MENU_ID_MODE_SWITCH_SIM_NAME" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_3SIM" highlight="mmi_highlight_mode_switch_setting">
   #else
        <MENU id="MENU_ID_MODE_SWITCH_SIM_NAME" parent = "MAIN_MENU_SETTINGS_MENUID" type="APP_MAIN" str="STR_ID_MODE_SWITCH_SETTING_2SIM" highlight="mmi_highlight_mode_switch_setting">
   #endif
#endif
			<MENUITEM id="MENU_ID_NETSET_SIM_NAME1" str="STR_GLOBAL_SIM_1" img="IMG_GLOBAL_SIM1"/>
			#if (MMI_MAX_SIM_NUM >= 2) 
			<MENUITEM id="MENU_ID_NETSET_SIM_NAME2" str="STR_GLOBAL_SIM_2" img="IMG_GLOBAL_SIM2"/>
			#if (MMI_MAX_SIM_NUM >= 3) 
			<MENUITEM id="MENU_ID_NETSET_SIM_NAME3" str="STR_GLOBAL_SIM_3" img="IMG_GLOBAL_SIM3"/>
			#if (MMI_MAX_SIM_NUM == 4) 
			<MENUITEM id="MENU_ID_NETSET_SIM_NAME4" str="STR_GLOBAL_SIM_4" img="IMG_GLOBAL_SIM4"/>
			#endif /* (MMI_MAX_SIM_NUM == 4) */
			#endif /* (MMI_MAX_SIM_NUM >= 3) */
			#endif /* (MMI_MAX_SIM_NUM >= 2) */ 
	</MENU>
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

	#if (MMI_MAX_SIM_NUM >= 2)
        <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_mode_switch_query_nw_attach_hdlr"/>	
        #endif
	
	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		<EVENT id="EVT_ID_MODE_SWITCH_FAIL" type="SENDER"/>
		
		<RECEIVER id="EVT_ID_MODE_SWITCH_FAIL" proc="mmi_netset_sim_name_sim_avaliable_hdlr"/>	
		<RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" proc="mmi_netset_sim_name_sim_avaliable_hdlr"/>	
		<RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_netset_sim_name_sim_avaliable_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_netset_sim_name_sim_avaliable_hdlr"/>
	#endif
	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

</APP>

#endif
