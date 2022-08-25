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
 *   udx.res
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
 *   Jinchuan Gou mtk80241
 *
 *******************************************************************************/
 
#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_UDX">
    <INCLUDE file = "GlobalResDef.h"/> 
#ifdef __PLUTO_MMI_PACKAGE__ 
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/> 
#endif
   
#ifdef __MMI_UDX_SUPPORT__
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
	<STRING id="STR_ID_UDX_MAIN_MENU"/>
	<STRING id="STR_ID_UDX_BUILD"/>
	<STRING id="STR_ID_UDX_PARSE"/>
	<STRING id="STR_ID_UDX_DATA_USE_WAY"/>
	<STRING id="STR_ID_UDX_USER_INFO"/>
	<STRING id="STR_ID_UDX_DATA_USE_ADD_NEW"/>
	<STRING id="STR_ID_UDX_FILE_VIEW_INFO"/>
	<STRING id="STR_ID_UDX_PARSE_TYPE_SELECT"/>
	<STRING id="STR_ID_UDX_SAVE_AS_FILE"/>
	<STRING id="STR_ID_UDX_SEND_VIA_BLUETOOTH"/>
	<STRING id="STR_ID_UDX_HELP_INFO"/>
	<STRING id="STR_ID_UDX_VCARD"/>
	<STRING id="STR_ID_UDX_VCALENDAR"/>
	<STRING id="STR_ID_UDX_EMAIL"/>
	<STRING id="STR_ID_UDX_NO_DATA_TYPE_SELECTED"/>
	<STRING id="STR_ID_UDX_BUSY"/>
	<STRING id="STR_ID_UDX_NO_DATA"/>
	<STRING id="STR_ID_UDX_BUILDING"/>
	<STRING id="STR_ID_UDX_VCARD_SELECT_QUERY"/>
	<STRING id="STR_ID_UDX_DUPLICATE_FILENAME"/>
	<STRING id="STR_ID_UDX_FILE_PATH_TOO_LONG"/>
	<STRING id="STR_ID_UDX_PARSE_SAVING"/>
	<STRING id="STR_ID_UDX_RECEIVE"/>
	<STRING id="STR_ID_UDX_CANCEL_QUERY"/>
	<STRING id="STR_ID_UDX_PROCESSING"/>
	<STRING id="STR_ID_UDX_PARSE_FAIL"/>
	<STRING id="STR_ID_UDX_BUILD_FIAL"/>
	<STRING id="STR_ID_UDX_ABORTED"/>
	<STRING id="STR_ID_UDX_TYPE_SELECT_PRESS_STAR"/>
	<STRING id="STR_ID_UDX_TYPE_SELECT_TOUCH_BOX"/>
	<STRING id="STR_ID_UDX_VENDOR_INFO"/>
	<STRING id="STR_ID_UDX_DEVICE_INFO"/>
	<STRING id="STR_ID_UDX_UDX_VERSION"/>
	<STRING id="STR_ID_UDX_USER_AGENT"/>
	<STRING id="STR_ID_UDX_USER_INFO_FROM"/>
	<STRING id="STR_ID_UDX_VERSION"/>
	<STRING id="STR_ID_UDX_COUNTS"/>
	<STRING id="STR_ID_UDX_COLON"/>
	<STRING id="STR_ID_UDX_PARSE_LOG"/>
	<STRING id="STR_ID_UDX_PARSE_LOG_PARSE"/>
    <STRING id="STR_ID_UDX_DATA_NOT_ADDED"/>
    <STRING id="STR_ID_UDX_IS_PROCESSING"/>
    <STRING id="STR_ID_UDX_FMGR_FWD_UDX"/>
    
	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
    <IMAGE id="IMG_ID_UDX_MAIN_MENU">CUST_IMG_PATH"\\\\MainLCD\\\\UDX\\\\SB_UDX.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UDX_BUILD">CUST_IMG_PATH"\\\\MainLCD\\\\UDX\\\\UDX_BUILD.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UDX_PARSE">CUST_IMG_PATH"\\\\MainLCD\\\\UDX\\\\UDX_PARSE.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UDX_SET">CUST_IMG_PATH"\\\\MainLCD\\\\UDX\\\\UDX_SET.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UDX_HELP">CUST_IMG_PATH"\\\\MainLCD\\\\UDX\\\\UDX_HELP.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UDX_VCARD">CUST_IMG_PATH"\\\\MainLCD\\\\UDX\\\\UDX_CONTACT.bmp"</IMAGE>
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
    <SCREEN id = "SCR_ID_SYNC_ABORT"/>
    <SCREEN id = "SCR_ID_UDX_DATA_TYPE_SELECT"/>
    <SCREEN id = "SCR_ID_UDX_USER_INFO"/>    
    <SCREEN id = "SCR_ID_UDX_HELP"/>    
    <SCREEN id = "SCR_ID_UDX_SEND_WAY"/>
    <SCREEN id = "SCR_ID_UDX_FILE_VIEW_INFO"/>      
    <SCREEN id = "SCR_ID_UDX_PARSE_LOG"/>
    <SCREEN id = "SCR_ID_UDX_PROCESSING"/>
    <SCREEN id = "SCR_ID_UDX_PROCESSING_PERCENTAGE"/>         
    <SCREEN id = "SCR_ID_UDX_ABORTING"/>
    <SCREEN id = "GRP_ID_UDX_MAIN"/>
	<!--Screen ID Area-->
    <!--End Screen Resource Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Menu Item Area-->
#ifdef __PLUTO_MMI_PACKAGE__ 
	<MENU id="MENU_ID_UDX_MAIN_MENU" parent = "MAIN_MENU_ORGANIZER_MENUID" type="APP_MAIN" str="STR_ID_UDX_MAIN_MENU" img="IMG_ID_UDX_MAIN_MENU" highlight="mmi_udx_highlight_main_menu" group="MAIN_MENU_ORGANIZER_MENUID">
	    <MENUITEM_ID>MENU_ID_UDX_BUILD</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_UDX_PARSE</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_UDX_SETTINGS</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_UDX_HELP</MENUITEM_ID>
    </MENU>
#else
	<MENU id="MENU_ID_UDX_MAIN_MENU" type="APP_MAIN" str="STR_ID_UDX_MAIN_MENU" img="IMG_ID_UDX_MAIN_MENU" highlight="mmi_udx_highlight_main_menu" group="MAIN_MENU_ORGANIZER_MENUID">
	    <MENUITEM_ID>MENU_ID_UDX_BUILD</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_UDX_PARSE</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_UDX_SETTINGS</MENUITEM_ID>
	    <MENUITEM_ID>MENU_ID_UDX_HELP</MENUITEM_ID>
    </MENU>
#endif
	<MENUITEM id="MENU_ID_UDX_BUILD" str="STR_ID_UDX_BUILD" img="IMG_ID_UDX_BUILD"/>
    <MENUITEM id="MENU_ID_UDX_PARSE" str="STR_ID_UDX_PARSE" img="IMG_ID_UDX_PARSE"/>
	<MENU id="MENU_ID_UDX_SETTINGS" type="APP_SUB" str="STR_GLOBAL_SETTINGS" img="IMG_ID_UDX_SET">
        <MENUITEM id="MENU_ID_UDX_CONFLICT_SOLUTION" str="STR_ID_UDX_DATA_USE_WAY" img="IMG_GLOBAL_L1"/>
    	<MENUITEM id="MENU_ID_UDX_USER_INFO" str="STR_ID_UDX_USER_INFO" img="IMG_GLOBAL_L2"/>
    </MENU>
	<MENUITEM id="MENU_ID_UDX_HELP" str="STR_GLOBAL_HELP" img="IMG_ID_UDX_HELP"/>
	
	<MENU id="MENU_ID_UDX_PARSE_FILE_SUBMENU" type="APP_SUB" str="STR_ID_UDX_PARSE">
        <MENUITEM id="MENU_ID_UDX_PARSE_USE_UDX_FILE" str="STR_ID_UDX_PARSE_TYPE_SELECT" img="IMG_GLOBAL_L1"/>
        <MENUITEM id="MENU_ID_UDX_PARSE_FILE_INFO" str="STR_ID_UDX_FILE_VIEW_INFO" img="IMG_GLOBAL_L2"/>
    </MENU>

    
	<MENUITEM id="MENU_ID_UDX_FMGR_FWD_UDX" str="STR_ID_UDX_FMGR_FWD_UDX"/>
	
	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_udx_driver_plug_out_event_hdlr"/>

    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--MMI Cache Area-->
    <!--MMI Cache Area-->
    
    <CACHEDATA type="byte" id="NVRAM_UDX_DATA_USE_WAY">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <!--MMI Cache Area-->
    <!--MMI Cache Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    

#endif /* __MMI_UDX_SUPPORT__ */

</APP>



#ifdef __MMI_UDX_SUPPORT__

<FILE_TYPES>
    <FILE_OPTION_HDLR option = "MENU_ID_UDX_FMGR_FWD_UDX" handler = "mmi_udx_fmgr_to_udx_handler"/>
</FILE_TYPES>

#endif /* __MMI_UDX_SUPPORT__ */



