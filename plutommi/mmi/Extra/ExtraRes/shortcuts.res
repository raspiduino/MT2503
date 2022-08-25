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
 * Shortcuts.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Shortcuts resource file with XML format.   
 *
 * Author:
 * -------
 *   Yixiong Zhao(MTK80274)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 19 2013 yunliu.mao
 * [MAUI_03463453] [11BW1332OF_6260Slim_Dev] check in 11c
 * .[11BW1332OF_6260Slim_Dev] check in 11c
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 08 02 2011 yixiong.zhao
 * [MAUI_02991670] [BW FWT]指定快捷键用户体验不好
 * .
 *
 * 06 28 2011 yixiong.zhao
 * [MAUI_02657441] [Shortcuts] SLIM
 * Remove the duplicated strings. Replaced with global strings.
 *
 * 05 17 2011 yixiong.zhao
 * [MAUI_02657441] [Shortcuts] SLIM
 * .
 *
 * 11 30 2010 yixiong.zhao
 * [MAUI_02642530] [Build error] Modify the res range declaration
 * .
 *
 * 11 30 2010 yixiong.zhao
 * [MAUI_02642530] [Build error] Modify the res range declaration
 * .
 *
 * Jul 6 2010 mtk80274
 * [MAUI_02431291] There is no Icon for Shortcuts
 * 
 *
 * Jun 8 2010 mtk80274
 * [MAUI_02206533] [Settings] List show x icon
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef SHORTCUTS_APP
#if !defined(__DISABLE_SHORTCUTS_IMPL__) && defined(__PLUTO_MMI_PACKAGE__)
<APP id="APP_SHORTCUTS">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="Mmi_rp_app_phonesetting_new_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
    <STRING id="STR_MAIN_MENU_ID"/>
#endif
    <STRING id="SHORTCUTS_TITLE_STRING_ID"/>
    <STRING id="SHORTCUTS_FULL_MSG_STRING_ID"/>
    <STRING id="SHORTCUTS_CHANGE_ORDER_STRING_ID"/>
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
    <STRING id="STR_DEDICATED_KEY"/>
    <STRING id="STR_DEDICATED_UP_KEY"/>
    <STRING id="STR_DEDICATED_DOWN"/>
    <STRING id="STR_DEDICATED_LEFT"/>
    <STRING id="STR_DEDICATED_RIGHT"/>
#endif /* __MMI_DEDICATED_KEY_SHORTCUTS__ */
#ifdef __MMI_OP01_DCD__
    <STRING id="SHORTCUTS_DCD_CONFLICT_WARNING_ID"/>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_SHORTCUTS_MAINMENU" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Toolbar_mainmenu.bmp"</IMAGE>
 #if !(defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__) || !defined (__WIFI_WIZARD_SUPPORT__))   
    <IMAGE id="IMG_SETTING_SHORTCUT" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Shortcut\\\\SB_SC.bmp"</IMAGE>
 #endif   
#ifdef __OP01_FWPBW__
    <IMAGE id="IMG_ID_SHCT_ARROW_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Shortcut\\\\arrow_up.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SHCT_ARROW_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Shortcut\\\\arrow_down.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SHCT_ARROW_LEFT" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Shortcut\\\\arrow_left.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SHCT_ARROW_RIGHT" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Shortcut\\\\arrow_right.bmp"</IMAGE>
#endif /* __OP01_FWPBW__ */
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_ADD_MENUID" str="@OID:STR_GLOBAL_ADD"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_EDIT_MENUID" str="@OID:STR_GLOBAL_EDIT"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_DELETE_MENUID" str="@OID:STR_GLOBAL_DELETE"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID" str="@OID:STR_GLOBAL_DELETE_ALL"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID" str="SHORTCUTS_CHANGE_ORDER_STRING_ID"/>
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
#ifdef __OP01_FWPBW__
    <MENUITEM id="MENU_SETTING_DEDICATED_UP_KEY" img="IMG_ID_SHCT_ARROW_UP"/>
    <MENUITEM id="MENU_SETTING_DEDICATED_DOWN_KEY" img="IMG_ID_SHCT_ARROW_DOWN"/>
    <MENUITEM id="MENU_SETTING_DEDICATED_LEFT_KEY" img="IMG_ID_SHCT_ARROW_LEFT"/>
    <MENUITEM id="MENU_SETTING_DEDICATED_RIGHT_KEY" img="IMG_ID_SHCT_ARROW_RIGHT"/>
#else
    <MENUITEM id="MENU_SETTING_DEDICATED_UP_KEY" str="STR_DEDICATED_UP_KEY" img="IMG_SETTING_PHONE"/>
    <MENUITEM id="MENU_SETTING_DEDICATED_DOWN_KEY" str="STR_DEDICATED_DOWN" img="IMG_SETTING_PHONE"/>
    <MENUITEM id="MENU_SETTING_DEDICATED_LEFT_KEY" str="STR_DEDICATED_LEFT" img="IMG_SETTING_PHONE"/>
    <MENUITEM id="MENU_SETTING_DEDICATED_RIGHT_KEY" str="STR_DEDICATED_RIGHT" img="IMG_SETTING_PHONE"/>
#endif /* __OP01_FWPBW__ */
    <MENUITEM id="MAIN_MENU_FOR_SHORTCUTS" str="STR_MAIN_MENU_ID" img="IMG_ID_SHORTCUTS_MAINMENU"/>
#endif /* __MMI_DEDICATED_KEY_SHORTCUTS__ */
    <!--Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <MENU id="EXTRA_SHORTCUTS_OPTION_MENUID" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_ADD_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_EDIT_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_DELETE_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID</MENUITEM_ID>
    </MENU>

    <MENU id="EXTRA_SHORTCUTS_MENUID" type="APP_MAIN" str="SHORTCUTS_TITLE_STRING_ID"
#if defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__) || !defined (__WIFI_WIZARD_SUPPORT__)
    img="IMG_ID_SHORTCUTS_MAINMENU"
    highlight="highlight_mainmenu_shortcuts"
#else
    img="IMG_SETTING_SHORTCUT"
    highlight="mmi_highlight_shortcuts"
#endif
    >
    </MENU>
#ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
    <MENU id="MENU_SETTING_DEDICATED_KEYS" type="APP_MAIN" str="STR_DEDICATED_KEY" img="IMG_SETTING_PHONE" highlight="HighlightDedicatedKeys">
        <MENUITEM_ID>MENU_SETTING_DEDICATED_UP_KEY</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_DEDICATED_DOWN_KEY</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_DEDICATED_LEFT_KEY</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_DEDICATED_RIGHT_KEY</MENUITEM_ID>
    </MENU>
#endif /* __MMI_DEDICATED_KEY_SHORTCUTS__ */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SHCT_QUICK_MENU_CFG"/>
    <SCREEN id="GRP_ID_SHCT_DEDICATED_KEY_CFG"/>
    <SCREEN id="GRP_ID_SHCT_QUICK_MENU"/>

    <SCREEN id="SCR_ID_SHCT_IDLE_SHORTCUT"/>
    <SCREEN id="SCR_ID_SHCT_MAIN_MENU"/>
    <SCREEN id="SCR_ID_SHCT_EDIT"/>
    <SCREEN id="SCR_ID_SHCT_ORDER"/>
    <SCREEN id="SCR_ID_SHCT_DEDICATED_KEYS"/>
    <SCREEN id="SCR_ID_SHCT_EDIT_DEDICATED_KEYS"/>
    <SCREEN id="SCR_ID_SHCT_APP_SELECT"/>

</APP>
#endif /* __DISABLE_SHORTCUTS_IMPL__ */ 
#endif /* !defined(__DISABLE_SHORTCUTS_IMPL__) && defined(__PLUTO_MMI_PACKAGE__) */
