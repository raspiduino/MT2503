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
 * Appicon.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Phone setting Application Icon resource file with XML format.   
 *
 * Author:
 * -------
 *   Ligen Li
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * PhoneSetting  Slim check in 11B.
 *
 * 12 10 2012 ligen.li
 * [MAUI_03273225] [appicon setting] appicon setting check in
 * .
 *
 * 12 05 2012 ligen.li
 * [MAUI_03237682] [Pluto slim] Phonesetting and network setting slim
 * .
 *
 * 12 04 2012 ligen.li
 * [MAUI_03273225] [appicon setting] appicon setting check in
 * .
 *
 * 11 29 2012 ligen.li
 * [MAUI_03273225] [appicon setting] appicon setting check in
 * modify img path.
 *
 * 11 29 2012 ligen.li
 * [MAUI_03273225] [appicon setting] appicon setting check in
 * appicon setting add EVT ID.
 *
 * 11 28 2012 ligen.li
 * [MAUI_03273225] [appicon setting] appicon setting check in
 * launcher switch  add applist.
 *
 * 11 23 2012 ligen.li
 * [MAUI_03273225] [appicon setting] appicon setting check in
 * appicon setting check in.
 *
 * 11 23 2012 ligen.li
 * NULL
 * .
 *
 * 11 22 2012 ligen.li
 * NULL
 * add option menu.
 *
 * 11 20 2012 ligen.li
 * NULL
 * APPICON SETTING.
 *
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_SETTING_APPICON" name="STR_ID_PHNSET_APP_ICON" package_name = "native.mtk.setting" hidden_in_mainmenu = "true" launch = "mmi_phnset_appicon_launcher">
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_filemanager_def.h"/>
	<APPCONCURRENT concurrent_w_order="SRV_VENUS_THEME, APP_SETTING_APPICON" />
    <!-- string ----------------------------------------------------------------------------------->  
    <STRING id = "STR_ID_PHNSET_APP_ICON"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON1"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON2"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON3"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON_SYSTEM"/>
    <STRING id = "STR_ID_PHNSET_APPICON_CHANGED"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON_CHNAGE_ASK"/>
    <STRING id = "STR_ID_PHNSET_APPICON_SWITCH"/>
    <STRING id = "STR_ID_PHNSET_APPICON_INVALID"/>
#if 0    
    <STRING id = "STR_ID_PHNSET_APP_ICON_SYSTEM_TITTLE"/>
#endif    
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__  
    <STRING id = "STR_ID_PHNSET_APPICON_COMPATIBLE_ASK"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON_DOWNLOAD"/>
#if 0    
    <STRING id = "STR_ID_PHNSET_APP_ICON_DOWNLOAD_TITTLE"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON_DLT_ERROR_PROJECT"/>
    <STRING id = "STR_ID_PHNSET_APP_ICON_DLT_ERROR_VERSION"/>
#endif    
#endif

    <!-- image ----------------------------------------------------------------------------------->
#if 0    
    <IMAGE id="IMG_ID_PHNSET_APPICON_PREVIEW">CUST_IMG_PATH"\\\\MainLCD\\\\preview.jpg"</IMAGE> 
#endif    
    <IMAGE id="IMG_ID_PHNSET_APPICON_FILECORRUPTED">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\\Settings\\\\File_corrupted.png"</IMAGE>
#if 0    
    <IMAGE id="IMG_ID_PHNSET_APPICON_PHONE">CUST_IMG_PATH"\\\\MainLCD\\\\FM_phone.pbm"</IMAGE>
 #ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__   
    <IMAGE id="IMG_ID_PHNSET_APPICON_CARD">CUST_IMG_PATH"\\\\MainLCD\\\\FM_card.pbm"</IMAGE>
 #endif   
#endif 


    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_ID_PHNSET_APP_ICON_MAIN"/>
    <SCREEN id = "SCR_ID_APPICON_MAIN"/>
    <SCREEN id = "SCRN_ID_APPICON_SYSTEM_LIST_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_APPICON_DOWNLOAD"/>
    <SCREEN id = "SCR_ID_PHNSET_APPICON_SYSTEM"/>
    <SCREEN id = "SCRN_ID_APPICON_VIEW1"/>
    <SCREEN id = "SCRN_ID_APPICON_VIEW2"/>



    <!-- screen group id -------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_APPICON_MAIN"/>
    <SCREEN id = "GRP_ID_APPICON_VIEW"/>
    <SCREEN id = "GRP_ID_APPICON_SYSTEM"/>
    <!-- menu ------------------------------------------------------------------------------------->
     

    <!-- APP icon display main menu -->
    <MENU id = "MENU_SETTING_APP_ICON" type = "APP_MAIN" str = "STR_ID_PHNSET_APP_ICON"/>
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
  #ifdef __MMI_FILE_MANAGER__
    <MENUITEM id = "MENU_ID_APPICON_FMGR_ACTIVATE" str = "@OID:STR_GLOBAL_ACTIVATE"/>

    <MENU id="MENU_ID_FMGR_APPICON_TYPE_OPTIONS" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_APPICON_FMGR_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_FOLDER_CREATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_COPY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MOVE</MENUITEM_ID>
        #ifndef __MMI_SLIM_FILE_MANAGER__
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>
        #endif
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DETAIL</MENUITEM_ID>
    </MENU>
    <FILE_TYPES>
       #if 0
    		<FILE_TYPE type_id="FMGR_TYPE_APPICON" extension="ACO" option="MENU_ID_FMGR_APPICON_TYPE_OPTIONS">
    		</FILE_TYPE>
    	 #endif	

    		<FILE_OPTION_HDLR option="MENU_ID_APPICON_FMGR_ACTIVATE" enabler="mmi_phnset_appicon_fmgr_use_enabler" handler="mmi_phnset_appicon_fmgr_use_handler"/>
		</FILE_TYPES>
    
    /*<SENDER id="EVT_ID_PHNSET_APPICON_CHANGED">*/
    
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_phnset_appicon_notify_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_phnset_appicon_notify_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_phnset_appicon_notify_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_phnset_appicon_notify_hdlr"/>
	#ifdef __MMI_USB_SUPPORT__	
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_phnset_appicon_notify_hdlr"/>
		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_phnset_appicon_notify_hdlr"/>
	#endif
	#endif	   
#endif    
    <EVENT id="EVT_ID_PHNSET_APPICON_CHANGED" type="SENDER"/> 
    <!-- Application icon main menu --> 
    <CACHEDATA type="short" id="NVRAM_RESTORE_APP_ICON_ID" restore_flag="TRUE" restore_id="@NVRAM_DEFAULT_RESTORE_APP_ICON_ID">
        <DEFAULT_VALUE> [0x0000, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current appicon id </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_DEFAULT_RESTORE_APP_ICON_ID">
        <DEFAULT_VALUE> [0x0000, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> byte Cache </DESCRIPTION>
    </CACHEDATA>     
     <!-----------------------------------------------------ASM2.0------------------------------------------------------>
 #ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__    
     <MEMORY base="MMI_APPICON_BASE_SIZE" inc = "Appicon.h"/>
 #endif    
</APP>
#endif
