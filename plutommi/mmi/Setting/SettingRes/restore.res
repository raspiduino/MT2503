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
 *   restore resource file with XML format.   
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
 * 11 22 2012 ligen.li
 * [MAUI_03260501] [MSZ] Remove unused string in 11BW1232OF_SLIM_DEV
 * remove unused string.
 *
 * 03 20 2012 xiangnan.qi
 * [MAUI_03152540] Restore&Schedule power on off lock any time support.
 * .
 *
 * 05 25 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 08 11 2010 cong.zhou
 * [MAUI_02631461] [Setting] Move resource from Res_Setting.c to APP res file
 * .
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

<APP id = "APP_RESTORE">


    <!-- string ----------------------------------------------------------------------------------->
    <STRING id = "STR_SETTING_RESTORE_CONFIRM"/>
    <STRING id = "STR_SETTING_RESTORE_PROCESSING"/>
#if 0
    <STRING id = "STR_SETTING_NOTICE_SUCCESS_REBOOT_TEXT"/>    
    <STRING id = "STR_MENU_RESTORE"/>
#endif
    <STRING id = "STR_ID_RESTORE_TITLE"/>      

   
    <!-- image ------------------------------------------------------------------------------------>  
    <IMAGE id = "IMG_SETTING_STORE">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_STORE.bmp"</IMAGE>


    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_RESTORE"/>
    <SCREEN id = "SCR_RESTORE_PROCESSING"/>
    <SCREEN id = "SCR_SETTING_RESTORE_CONFIRM"/>    
    

    <!-- group ----------------------------------------------------------------------------------->
	<SCREEN id = "GRP_ID_PHNSET_RESTORE"/>


    <!-- menu ------------------------------------------------------------------------------------->
    <MENU id = "MENU_SETTING_RESTORE" type = "APP_MAIN" str = "STR_ID_RESTORE_TITLE" img = "IMG_SETTING_STORE" highlight = "HighlightRstScr">
    </MENU>

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__   
	<RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_restore_notify_screen_lock_hdlr"/>   
#endif


</APP>


