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
 *   Screen saver resource file with XML format.   
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
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 09 23 2011 xiangnan.qi
 * [MAUI_03035934] MMI Features reduce
 * .
 *
 * 05 25 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 03 23 2011 cong.zhou
 * [MAUI_02657293] [Setting] Check in __MMI_SCREEN_SAVER__ for 10A
 * .
 *
 * 03 22 2011 cong.zhou
 * [MAUI_02657293] [Setting] Check in __MMI_SCREEN_SAVER__ for 10A
 * .
 *
 * 03 22 2011 cong.zhou
 * [MAUI_02657293] [Setting] Check in __MMI_SCREEN_SAVER__ for 10A
 * .
 *
 * 11 23 2010 cong.zhou
 * [MAUI_02638573] [Settings] Popup Error when the input is invalid.
 * .
 *
 * 11 19 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 11 18 2010 cong.zhou
 * [MAUI_02641438] [Setting] Move NVRAM cache ID to res file
 * .
 *
 * 11 02 2010 cong.zhou
 * [MAUI_02634694] [Setting] Schedule power off is still execute when the phone is being call
 * .
 *
 * 08 18 2010 cong.zhou
 * [MAUI_02319642] check pic format have differently when select wallpaper
 * .
 *
 * Jun 12 2010 mtk80585
 * [MAUI_02209822] [Settings] Wallpaper, screen save,r power on off display file manager service handle
 * 
 *
 * Jun 9 2010 mtk80585
 * [MAUI_02208090] [Settings] Remove unused resource ID
 * 
 *
 * Apr 14 2010 mtk80047
 * [MAUI_02179055] [new feature][phone setting][PlutoFW 10A] check in
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"
#include "custom_mmi_default_value.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_SCREENSAVER">
    <INCLUDE file = "GlobalResDef.h"/>

    <!-- string ----------------------------------------------------------------------------------->
#ifdef __MMI_SCREEN_SAVER__
    <STRING id = "STR_MENU_SETTING_SCREEN_SVR"/>
    <STRING id = "STR_SCR_SCREENSAVER_CAPTION"/>
    <STRING id = "STR_SCR_SCREENSAVER_SYSTEM"/>
    <STRING id = "STR_SCR_SCREENSAVER_DOWNLOAD"/>
    <STRING id = "STR_SCREENSAVER_5SEC"/>
    <STRING id = "STR_SCREENSAVER_15SEC"/>
    <STRING id = "STR_SCREENSAVER_30SEC"/>
    <STRING id = "STR_SCREENSAVER_1MINUTE"/>
    <STRING id = "STR_SCREENSAVER_STATUS"/>
    <STRING id = "STR_SCREENSAVER_WAITING"/>
    <STRING id = "STR_IDLE_SS_DECODE_ERR"/>
    <STRING id = "STR_SCREENSAVER_INVALID_INPUT"/>    
    
#ifdef __MMI_SETTING_SS_WAITTIME_SELECT__
    <STRING id = "STR_SCREENSAVER_WAITING_COMMENT"/>
#endif /* __MMI_SETTING_SS_WAITTIME_SELECT__ */

#ifdef __MMI_LCD_PARTIAL_ON__
    <STRING id = "STR_SCREENSAVER_DISPLAY_TIME"/>
#endif /* __MMI_LCD_PARTIAL_ON__ */
  
#ifdef __MMI_THEMES_V2_SUPPORT__
    <STRING id = "STR_ID_DISPCHAR_THEME_SCREENSAVER"/>
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    
#ifdef __MMI_FILE_MANAGER__
#ifdef __MMI_AVATAR__
    <STRING id = "STR_ID_PHNSET_SS_AVATAR"/>
#endif /* __MMI_AVATAR__ */
#endif /* __MMI_FILE_MANAGER__ */

   
    <!-- image ------------------------------------------------------------------------------------>
    <IMAGE id = "IMAGE_SETTING_TIME">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\Common\\\\ST_TIME.bmp"</IMAGE>

#endif /* __MMI_SCREEN_SAVER__ */
    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_MAIN_SCREENSAVER"/>
    <SCREEN id = "SCR_SCREENSAVER_SETTING"/>
    <SCREEN id = "SCR_SCREENSAVER_SELECT"/>
    <SCREEN id = "SCR_SCREENSAVER_SYSTEM_LIST"/>
    <SCREEN id = "SCR_SCREENSAVER_VIEW"/>
	<SCREEN id = "SCR_SCREENSAVER_VIEW_2"/>
    <SCREEN id = "SCR_SCREENSAVER_DOWNLOAD_VIEW"/>
    <!-- screen group ID -->
	<SCREEN id = "GRP_ID_SCREENSAVER_SETTING"/>
	<SCREEN id = "GRP_ID_SCREENSAVER_SYSTEM"/>
	<SCREEN id = "GRP_ID_SCREENSAVER_MAIN"/>
    
#ifdef __MMI_SCREEN_SAVER__
    <!-- menu ------------------------------------------------------------------------------------->
    
    <!-- screensaver main menu -->
    <MENU id = "MENU_SETTING_SCR_SVR" type = "APP_SUB" str = "STR_MENU_SETTING_SCREEN_SVR">
        <MENUITEM_ID>MENU_SETTING_SS_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_SS_SELECT</MENUITEM_ID>
    </MENU>
    <MENUITEM id = "MENU_SETTING_SS_SETTING" str = "STR_GLOBAL_SETTINGS"/>
    
    <!-- Select sub menu -->
#if defined(__MMI_FILE_MANAGER__)
    <MENU id = "MENU_SETTING_SS_SELECT" type = "APP_SUB" str = "STR_GLOBAL_SELECT">
        <MENUITEM_ID>MENU_SELECT_SS_SELECT_SYSTEM</MENUITEM_ID>
#if defined(__MMI_FILE_USEAS_SUPPORT__)
        <MENUITEM_ID>MEUN_SELECT_SS_SELECT_DOWNLOAD</MENUITEM_ID>
#endif 
#ifdef __MMI_AVATAR__
        <MENUITEM_ID>MENU_ID_PHNSET_SS_SELECT_AVATAR</MENUITEM_ID>
#endif
    </MENU>
    <MENUITEM id = "MENU_SELECT_SS_SELECT_SYSTEM" str = "STR_SCR_SCREENSAVER_SYSTEM"/>
    <MENUITEM id = "MEUN_SELECT_SS_SELECT_DOWNLOAD" str = "STR_SCR_SCREENSAVER_DOWNLOAD"/>


#ifdef __MMI_AVATAR__
    <MENUITEM id = "MENU_ID_PHNSET_SS_SELECT_AVATAR" str = "STR_ID_PHNSET_SS_AVATAR"/>
#endif

#else /* defined(__MMI_FILE_MANAGER__) */ 

    <MENUITEM id = "MENU_SETTING_SS_SELECT" str = "STR_GLOBAL_SELECT"/>

#endif /* defined(__MMI_FILE_MANAGER__) */

    <CACHEDATA type="byte" id="NVRAM_SCREENSAVER_STATUS" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_SCREENSAVER_STATUS">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> current screen saver status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SCREENSAVER_WAITING" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_SCREENSAVER_WAITING">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SCREENSAVER_WAITING_TIME] </DEFAULT_VALUE>
        <DESCRIPTION> current screen saver waiting time </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_SCREENSAVER_STATUS">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SCREENSAVER_STATUS] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_SCREENSAVER_WAITING">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_SCREENSAVER_WAITING_TIME] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CURRENT_SCREENSVER_ID" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_CURRENT_SCREENSVER_ID">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current screen id </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="RESTORE_DEFAULT_CURRENT_SCREENSVER_ID">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>    

#if defined(__MMI_FILE_MANAGER__)
    <!-- For file manager service handler -->
    <MENUITEM id = "MENU_ID_FMGR_FWD_SCREENSAVER" str = "STR_MENU_SETTING_SCREEN_SVR"/>
    <FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_SCREENSAVER" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_screensaver_hdlr"/>
    </FILE_TYPES>
#endif
#endif /* __MMI_SCREEN_SAVER__ */
</APP>



