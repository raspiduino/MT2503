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
 * SSOAPPGprot.h
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	This file is intends for Yahoo service Settings Acconuts
 *
 * Author:
 * -------
 * Mengmeng Cao
 *
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 28 2013 yunliu.mao
 * [MAUI_03464222] [Pluto Slim Phase3 IT Test]进入Settings->accounts&sync，press OK,无反应
 * .SSO ASM2.0 modify to ASM1.0
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 * 
 * 07 27 2012 mengmeng.cao
 * [MAUI_03220134] accounts setting code review
 * .
 * 
 * 07 24 2012 mengmeng.cao
 * [MAUI_03217035] When the pop up comes as   "No message to backup"  , tone pop up tone comes with it
 * .
 *
 * 07 06 2012 mengmeng.cao
 * [MAUI_03211834] yahoo login screen should not cover on pen calibration screen
 * .MAUI_03211410....03219114
 *
 * 07 02 2012 mengmeng.cao
 * [MAUI_03209713] Backing up option takes place even when we havenot selected SMS
 * .sms error code
 *
 * 07 01 2012 mengmeng.cao
 * [MAUI_03208028] unable to save sync information properly
 * .
 *
 * 06 21 2012 mengmeng.cao
 * [MAUI_03206249] sso suport asm of phb
 * .phb of sso support asm
 *
 * 06 15 2012 mengmeng.cao
 * [MAUI_03201196] Log In option shown at wrong position in the options menu
 * .daily error of no str_id_mmi_sso_ple_memory_card
 *
 * 06 15 2012 mengmeng.cao
 * [MAUI_03201196] Log In option shown at wrong position in the options menu
 * .option item of login postion, log in --->login, avoid receive sms evt when no power setting account of sms, SNS setting-->SNS settings
 *
 * 06 06 2012 mengmeng.cao
 * [MAUI_03194937] [Block]can not find the setting item of SNS
 * .daily error
 *
 * 05 31 2012 mengmeng.cao
 * [MAUI_03194937] [Block]can not find the setting item of SNS
 * .ews error
 *
 * 05 31 2012 mengmeng.cao
 * [MAUI_03194937] [Block]can not find the setting item of SNS
 * .
 *
 * 05 31 2012 mengmeng.cao
 * [MAUI_03194937] [Block]can not find the setting item of SNS
 * .MAUI_03194928 03194268 03195021 03199137
 *
 * 05 25 2012 mengmeng.cao
 * [MAUI_03191673] nss download bug
 * .
 *
 * 04 26 2012 mengmeng.cao
 * [MAUI_03168301] [Setting] SSOApp and SSOCUI
 * .
 *
 * 04 18 2012 mengmeng.cao
 * [MAUI_03168301] [Setting] SSOApp and SSOCUI
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_SSO" name = "STR_ID_MMI_SSO_ACCOUNTS">
#if defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__)
    <INCLUDE file = "GlobalResDef.h"/> 
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/> 

<!----------------- XML Begin ------------------------------------------------->

    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_app_mainmenu_def.h"/>

    <!----------------- Screen Id ----------------------------------------->         
    <SCREEN id = "GRP_ID_MMI_SSO"/>
    <SCREEN id = "GRP_ID_MMI_SSO_IN"/>
    <SCREEN id = "GRP_ID_MMI_SSO_OUT"/>
    <SCREEN id = "SCR_ID_MMI_SSO_ACCOUNTS"/>
    <SCREEN id = "GCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY"/>
    <SCREEN id = "SCR_ID_MMI_SSO_BACKUP_RESTORE_ENTRY_SCR"/>
    <SCREEN id = "SCR_ID_MMI_SSO_BACKUP_RESTORE_BAR"/>
    /*when error happen the info to show*/
    <SCREEN id = "SCR_ID_MMI_SSO_BACKUP_RESTORE_ERROR_RESULT"/>
    
    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS"/>  
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS_SETTING"/>   
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS_SELECT_SMS"/>  
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS_SELECT_CONTACTS"/>  
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS_SELECT_RESTORE_CAUTION"/>  
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS_SELECT_BACKUP_CAUTION"/>  
    <STRING id = "STR_ID_MMI_SSO_ACCOUNTS_BOOTUP_RESTORE_CAUTION"/>  
    /*restore*/
    <STRING id = "STR_ID_MMI_SSO_RESTORE_PRO_CONTACTS"/> 
    <STRING id = "STR_ID_MMI_SSO_RESTORE_PRO_SMS"/> 
    <STRING id = "STR_ID_MMI_SSO_RESTORE_PRO_CAUTION"/>  
    <STRING id = "STR_ID_MMI_SSO_RESTORE_FAILED_CAUTION"/> 
    <STRING id = "STR_ID_MMI_SSO_RESTORE_CONTACTS_FAILED_CAUTION"/> 
    <STRING id = "STR_ID_MMI_SSO_RESTORE_SMS_FAILED_CAUTION"/> 
    /*backup*/
    <STRING id = "STR_ID_MMI_SSO_BACKUP_PRO_CONTACTS"/> 
    <STRING id = "STR_ID_MMI_SSO_BACKUP_PRO_SMS"/> 
    <STRING id = "STR_ID_MMI_SSO_BACKUP_PRO_CAUTION"/>  
    <STRING id = "STR_ID_MMI_SSO_BACKUP_FAILED_CAUTION"/> 
    <STRING id = "STR_ID_MMI_SSO_BACKUP_CONTACTS_FAILED_CAUTION"/> 
    <STRING id = "STR_ID_MMI_SSO_BACKUP_SMS_FAILED_CAUTION"/> 
   
    <STRING id = "STR_ID_MMI_SSO_YAHOO_SERVICE"/>   
    <STRING id = "STR_ID_MMI_SSO_OPTIOM_SNS_SETTING"/>    
    <STRING id = "STR_ID_MMI_SSO_OPTIOM_SYNC"/>   
    <STRING id = "STR_ID_MMI_SSO_OPTIOM_NEWS"/> 
    <STRING id = "STR_ID_MMI_SSO_OPTIOM_APPS_SYNC"/>                
    <STRING id = "STR_ID_MMI_SSO_OPTION_LOG_OUT"/>  
    <STRING id = "STR_ID_MMI_SSO_OPTION_LOG_IN"/>         
    <STRING id = "STR_ID_MMI_SSO_LOGGING_OUT"/>  
		<STRING id = "STR_ID_MMI_SSO_RESTORE"/>
		<STRING id = "STR_ID_MMI_SSO_BACKUP"/>
		
		<STRING id = "STR_ID_MMI_SSO_COOKIE_EXOIRE"/>
		<STRING id = "STR_ID_MMI_SSO_PLE_MEMORY_CARD"/>
		<STRING id = "STR_ID_MMI_SSO_NO_NW_CONNECTION"/>
		
		
		<STRING id = "STR_ID_MMI_SSO_NO_CONTACTS_BACKUP"/>
		<STRING id = "STR_ID_MMI_SSO_NO_SMS_BACKUP"/>
		<STRING id = "STR_ID_MMI_SSO_NO_APP_DATA_BACKUP"/>
		
		<STRING id = "STR_ID_MMI_SSO_NO_CONTACTS_RESTORE"/>
		<STRING id = "STR_ID_MMI_SSO_NO_SMS_RESTORE"/>
		<STRING id = "STR_ID_MMI_SSO_NO_APP_DATA_RESTORE"/>
		
		<STRING id = "STR_ID_SSO_SNS_UPGRADE_SUCCESS"/>
		<STRING id = "STR_ID_SSO_SNS_UPGRADE_FAILURE"/>
		<STRING id = "STR_ID_SSO_SSO_UPGRADE_SUCCESS"/>
		<STRING id = "STR_ID_SSO_SSO_UPGRADE_FAILURE"/>

    <!----------------- Image Id ------------------------------------------>
    <!-- Notification settings image need update the image------------------------------------------------------->
    /*<IMAGE id = "IMG_SSO">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SPH.bmp"</IMAGE>*/
    <IMAGE id = "IMG_SSO">CUST_IMG_PATH"\\\\MainLCD\\\\SSO\\\\account_setting.png"</IMAGE>
    <!----------------- Menu Id ------------------------------------------->                       
    <MENU id = "MENU_ID_SETTING_SSO_ACCOUNTS"  str = "STR_ID_MMI_SSO_ACCOUNTS_SETTING" parent = "MAIN_MENU_SETTINGS_MENUID" img = "IMG_SSO" highlight = "mmi_sso_highlight"/>
   
    <MENUITEM id="MENU_ID_MMI_SSOAPP_LOGIN" str="STR_ID_MMI_SSO_OPTION_LOG_IN"/>
    <MENUITEM id="MENU_ID_MMI_SSOAPP_SYNC" str="STR_ID_MMI_SSO_OPTIOM_SYNC"/>
    <MENUITEM id="MENU_ID_MMI_SSOAPP_NEWS" str="STR_ID_MMI_SSO_OPTIOM_NEWS"/>
    <MENUITEM id="MENU_ID_MMI_SSOAPP_APPS_SYNC" str="STR_ID_MMI_SSO_OPTIOM_APPS_SYNC"/>
		<MENUITEM id="MENU_ID_MMI_SSOAPP_LOGOUT" str="STR_ID_MMI_SSO_OPTION_LOG_OUT"/>
    
    <MENUITEM id="MENU_ID_MMI_SSOAPP_MARK" str="STR_GLOBAL_MARK"/>
    <MENUITEM id="MENU_ID_MMI_SSOAPP_UNMARK" str="STR_GLOBAL_UNMARK"/>
		<MENUITEM id="MENU_ID_MMI_SSOAPP_MARKALL" str="STR_GLOBAL_MARK_ALL"/>
		<MENUITEM id="MENU_ID_MMI_SSOAPP_UNMARKALL" str="STR_GLOBAL_UNMARK_ALL"/>
    <MENUITEM id="MENU_ID_MMI_SSOAPP_RESTORE" str="STR_ID_MMI_SSO_RESTORE"/>
    <MENUITEM id="MENU_ID_MMI_SSOAPP_BACKUP" str="STR_ID_MMI_SSO_BACKUP"/>
    
    /*sns setting*/
		<MENU id="MENU_ID_MMI_SSOAPP_SNS_SETTING" type="APP_SUB" str="STR_ID_MMI_SSO_OPTIOM_SNS_SETTING">
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_SYNC</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_NEWS</MENUITEM_ID>
		</MENU>
	   /* about log in */
	   /* account yahoo service option log in*/
    <MENU id="MENU_ID_MMI_SSOAPP_ACCONUT_IN_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MMI_SSOAPP_LOGIN</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_MMI_SSOAPP_SNS_SETTING</MENUITEM_ID>  
    </MENU>  
	
		/*log out */
    <MENU id="MENU_ID_MMI_SSO_ACCONUTS_OUT_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
    		<MENUITEM_ID>MENU_ID_MMI_SSOAPP_APPS_SYNC</MENUITEM_ID>
    		<MENUITEM_ID>MENU_ID_MMI_SSOAPP_BACKUP</MENUITEM_ID>
 				<MENUITEM_ID>MENU_ID_MMI_SSOAPP_RESTORE</MENUITEM_ID>
				<MENUITEM_ID>MENU_ID_MMI_SSOAPP_SNS_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MMI_SSOAPP_LOGOUT</MENUITEM_ID>
    </MENU>
    
    <MENU id="MENU_ID_MMI_SSO_BACKUP_RESTORE_SCR_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
    		<MENUITEM_ID>MENU_ID_MMI_SSOAPP_MARK</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_UNMARK</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_MARKALL</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_UNMARKALL</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_RESTORE</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_MMI_SSOAPP_BACKUP</MENUITEM_ID>
    </MENU>
    
	  
		<!-----------------------------------------------------MMI cache Resource Area------------------------------------------------------>
    /*first power on*/
    #ifdef __MMI_SSO_OOBE__
    <CACHEDATA type="byte" id="NVRAM_SSOAPP_FIRST_POWER_ON" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> First power on </DESCRIPTION>
    </CACHEDATA>
    #endif
    
    /*backup restore*/
    #ifdef __VCARD_CLOUD_SUPPORT__
    <CACHEDATA type="byte" id="NVRAM_SSOAPP_CONTACTS_BACKUP_RESTORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x11] </DEFAULT_VALUE>
        <DESCRIPTION> Contacts backup restore </DESCRIPTION>
    </CACHEDATA>
    #endif
    
    #ifdef __SMS_CLOUD_SUPPORT__
    <CACHEDATA type="byte" id="NVRAM_SSOAPP_SMS_BACKUP_RESTORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x11] </DEFAULT_VALUE>
        <DESCRIPTION> SMS backup restore </DESCRIPTION>
    </CACHEDATA>
    #endif
    
    
  	<!-----------------------------------------------------Event------------------------------------------------------>
  	#ifdef __SMS_CLOUD_SUPPORT__
  	<RECEIVER id="EVT_ID_SRV_SMS_BACKUP_RESTORE" proc="mmi_sso_sms_evt_hdlr"/>
  	#endif
  	
  	#ifdef __MMI_SSO_OOBE__
  	<EVENT id="EVT_ID_MMI_SSO_BOOTUP_READY_NOTIFY" type="SENDER"/>
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_sso_contacts_sms_bootup_ready_hdlr"/>
    <RECEIVER id="EVT_ID_PHB_READY" proc="mmi_sso_contacts_sms_bootup_ready_hdlr"/>
    <RECEIVER id="EVT_ID_MMI_SSO_BOOTUP_READY_NOTIFY" proc="mmi_sso_contacts_sms_bootup_ready_hdlr"/>
    #endif
    
    #ifdef __MMI_SSO__
    <RECEIVER id="EVT_ID_SRV_SSO_PLUGINS_UPGRADED"      proc="mmi_sso_pluging_upgrade_proc"/> 
    #endif 
    
    #ifdef __SOCIAL_NETWORK_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SNS_PLUGINS_UPGRADED"      proc="mmi_sso_sns_pluging_upgrade_proc"/>
    #endif
#ifdef __MMI_SUPPORT_ASMV2__    
    <!-----------------------------------------------------ASM2.0------------------------------------------------------>
    <MEMORY extra_base="SRV_CLOUD_ASM_SIZE" inc = "CloudSrvGprot.h"/> 
<!----------------- XML END --------------------------------------------------->
#endif
#endif
</APP>
