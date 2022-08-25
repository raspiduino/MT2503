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
 *   Phone setting Power on off display resource file with XML format.   
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
 * 12 25 2012 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * PhoneSetting  Slim check in 11B.
 *
 * 09 23 2011 xiangnan.qi
 * [MAUI_03035934] MMI Features reduce
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


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_PHNSET_ONOFF">

    <!-- string ----------------------------------------------------------------------------------->
#ifdef __MMI_POWER_ON_OFF_DISPLAY__    
    <STRING id = "STR_ID_PHNSET_ON_OFF_SYSTEM"/>
    <STRING id = "STR_ID_PHNSET_ON_OFF_DOWNLOAD"/>
#ifdef __MMI_AVATAR__    
    <STRING id = "STR_ID_PHNSET_ON_OFF_AVATAR"/>
#endif    
    <STRING id = "STR_SETTING_POWER_ON_DISPLAY"/>
    <STRING id = "STR_SETTING_POWER_OFF_DISPLAY"/>
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */


    <!-- image ----------------------------------------------------------------------------------->



    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_SYSTEM_LIST"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW_2"/>    
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_USER_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_SYSTEM_LIST"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW_2"/>    
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_USER_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_OFF_LAST"/>

    <!-- screen group id -------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_POWER_ON_OFF_MAIN"/>
    <SCREEN id = "GRP_ID_POWER_ON_OFF_SYSTEM"/>
    <SCREEN id = "GRP_ID_POWER_ON_OFF_PREVIEW"/>
    
    <!-- menu ------------------------------------------------------------------------------------->
     
#ifdef __MMI_POWER_ON_OFF_DISPLAY__

    <!-- Power on display main menu -->
    <MENU id = "MENU_SETTING_POWER_ON_DISPLAY" type = "APP_SUB" str = "STR_SETTING_POWER_ON_DISPLAY">
        <MENUITEM_ID>MENU_SETTING_POWER_ON_SYSTEM</MENUITEM_ID>                
#if defined(__MMI_FILE_USEAS_SUPPORT__)
    <MENUITEM_ID>MENU_SETTING_POWER_ON_DOWNLOAD</MENUITEM_ID>
#endif
#ifdef __MMI_AVATAR__
    <MENUITEM_ID>MENU_ID_PHNSET_PWRON_AVATAR</MENUITEM_ID>
#endif
    </MENU>
    <MENUITEM id = "MENU_SETTING_POWER_ON_SYSTEM" str = "STR_ID_PHNSET_ON_OFF_SYSTEM"/>
    <MENUITEM id = "MENU_SETTING_POWER_ON_DOWNLOAD" str = "STR_ID_PHNSET_ON_OFF_DOWNLOAD"/>
#ifdef __MMI_AVATAR__
    <MENUITEM id = "MENU_ID_PHNSET_PWRON_AVATAR" str = "STR_ID_PHNSET_ON_OFF_AVATAR"/>
#endif

    <!-- Power off display main menu -->

    <MENU id = "MENU_SETTING_POWER_OFF_DISPLAY" type = "APP_SUB" str = "STR_SETTING_POWER_OFF_DISPLAY">
        <MENUITEM_ID>MENU_SETTING_POWER_OFF_SYSTEM</MENUITEM_ID>                
#if defined(__MMI_FILE_USEAS_SUPPORT__)
    <MENUITEM_ID>MENU_SETTING_POWER_OFF_DOWNLOAD</MENUITEM_ID>
#endif
#ifdef __MMI_AVATAR__
    <MENUITEM_ID>MENU_ID_PHNSET_PWROFF_AVATAR</MENUITEM_ID>
#endif
    </MENU>
    <MENUITEM id = "MENU_SETTING_POWER_OFF_SYSTEM" str = "STR_ID_PHNSET_ON_OFF_SYSTEM"/>
    <MENUITEM id = "MENU_SETTING_POWER_OFF_DOWNLOAD" str = "STR_ID_PHNSET_ON_OFF_DOWNLOAD"/>
#ifdef __MMI_AVATAR__
    <MENUITEM id = "MENU_ID_PHNSET_PWROFF_AVATAR" str = "STR_ID_PHNSET_ON_OFF_AVATAR"/>
#endif
#ifndef __MMI_MAINLCD_96X64__ 
#ifdef __MMI_FILE_MANAGER__
    <!-- For file manager service handler -->
    <MENUITEM id = "MENU_ID_FMGR_FWD_POWER_ON" str = "STR_SETTING_POWER_ON_DISPLAY"/>
    <MENUITEM id = "MENU_ID_FMGR_FWD_POWER_OFF" str = "STR_SETTING_POWER_OFF_DISPLAY"/>    
    <FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_POWER_ON" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_power_on_display_hdlr"/>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_POWER_OFF" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_power_off_display_hdlr"/>
    </FILE_TYPES>
#endif /* __MMI_FILE_MANAGER__ */
#endif
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */     
    <CACHEDATA type="short" id="NVRAM_RESTORE_POWER_ON_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RESTORE_POWER_OFF_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CURRENT_POWER_ON_DISPLAY" restore_flag="TRUE" restore_id="@NVRAM_RESTORE_POWER_ON_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current power on display </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CURRENT_POWER_OFF_DISPLAY" restore_flag="TRUE" restore_id="@NVRAM_RESTORE_POWER_OFF_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current power off display </DESCRIPTION>
    </CACHEDATA>        
</APP>

