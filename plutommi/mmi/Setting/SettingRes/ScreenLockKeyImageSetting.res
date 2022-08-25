/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrlockKeyImageSetting.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * Yiping Xie (mtk80652)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 18 2012 yiping.xie
 * [MAUI_03170518] after restore factory successful,lock screen image do not restore
 * .
 *
 * 04 18 2012 yiping.xie
 * [MAUI_03137863] [Key Launcher]
 * .add lock image setting hint
 *
 * 03 29 2012 yiping.xie
 * [MAUI_03158347] Red cross icon in shown while selecting the image for "Lock screen Image"
 * .
 *
 * 03 06 2012 yiping.xie
 * [MAUI_03142597] should not use "lock screen"string at display settings
 * .
 *
 * 03 02 2012 yiping.xie
 * [MAUI_03140753] [Need Patch] [Sanity Fail][NFST] Sanity Test of TSSQA00210032(cross icon is displayed on screen lock icon.)
 * .
 *
 * 02 21 2012 yiping.xie
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h" 

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SCREEN_LOCK_KEY_IMG_SETTING">

/* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
<!--Include Area-->
<INCLUDE file="GlobalResDef.h"/>

#define LOCK_SETTING_PATH  CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\ScreenLockKey\\\\"

/*****************************************************************************
 * string id 
 *****************************************************************************/

    <STRING id="STR_ID_SCREEN_LOCK_KEY_IMG_SETTING"/>
    <STRING id="STR_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS"/>
    <STRING id="STR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR"/>
     
 /*****************************************************************************
 * image id 
 *****************************************************************************/

    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_START">LOCK_SETTING_PATH"should_not_exist_only_add_enum.png"</IMAGE>
    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_0">LOCK_SETTING_PATH"lock.png"</IMAGE>
    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_1">LOCK_SETTING_PATH"Lock_1.png"</IMAGE>
    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_2">LOCK_SETTING_PATH"Lock_2.png"</IMAGE>
    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_3">LOCK_SETTING_PATH"Lock_3.png"</IMAGE>
    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_END">LOCK_SETTING_PATH"should_not_exist_only_add_enum.png"</IMAGE>

    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_LOADING">LOCK_SETTING_PATH"PF_loading.gif"</IMAGE>
    <IMAGE id="IMG_ID_SCREEN_LOCK_KEY_IMG_SETTING_SELECT">LOCK_SETTING_PATH"Lock_select.png"</IMAGE>

 /*****************************************************************************
 * menu id 
 *****************************************************************************/

    <MENU id="MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING" type="APP_SUB" str="STR_ID_SCREEN_LOCK_KEY_IMG_SETTING">
		<MENUITEM_ID>MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR</MENUITEM_ID>
	</MENU>

    <MENUITEM id="MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS" str="STR_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS"/>
    <MENUITEM id="MENU_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR" str="STR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR"/>

/*****************************************************************************
 * screen id 
 *****************************************************************************/

    <SCREEN id="SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_SYS"/>    
    <SCREEN id="SCR_ID_SCREEN_LOCK_KEY_IMG_SETTING_USR_STORE"/>

/*****************************************************************************
* nvram id 
*****************************************************************************/

    <CACHEDATA type="short" id="NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_SCREEN_LOCK_KEY_SETTING_IMG_SYS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

</APP>

#endif
