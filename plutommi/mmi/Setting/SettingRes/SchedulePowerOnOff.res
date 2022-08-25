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
 *   Schedule power on/off resource file with XML format.   
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
 * 12 25 2012 ligen.li
 * [MAUI_03299514] [pluto_slim]check in 11B
 * PhoneSetting  Slim check in 11B.
 *
 * 04 25 2012 xiangnan.qi
 * [MAUI_03174740] Add compile option for schedule power on off.
 * .
 *
 * 03 20 2012 xiangnan.qi
 * [MAUI_03152540] Restore&Schedule power on off lock any time support.
 * .
 *
 * 06 30 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 06 21 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 06 21 2011 cong.zhou
 * [MAUI_02965893] [Settings]The title should be Edit power off
 * .
 *
 * 06 13 2011 cong.zhou
 * [MAUI_02945437] [SLIM] Code review
 * .
 *
 * 06 09 2011 cong.zhou
 * [MAUI_02958485] Schedule power on/off list menu revise
 * .
 *
 * 12 24 2010 cong.zhou
 * [MAUI_02645729] [Setting] Check in schedule power on / off for reminder service
 * .
 *
 * 09 15 2010 cong.zhou
 * [MAUI_02634694] [Setting] Schedule power off is still execute when the phone is being call
 * .
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

<APP id = "SRV_SPOF">
#ifdef __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__
    <!-- string ----------------------------------------------------------------------------------->
    <STRING id = "SPOF_MAIN_TITLE_STRINGID"/>
    <STRING id = "SPOF_STATUS_STRINGID"/>
    <STRING id = "SPOF_DISABLE_STRINGID"/>
    <STRING id = "SPOF_ENABLE_STRINGID"/>
    <STRING id = "SPOF_TIME_CONFLICT"/>
    <STRING id = "SPOF_POWER_OFF_CONFIRM"/>
    <STRING id = "STR_MENU_SETTING_SCHEDULE_POWER"/>
    <STRING id = "STR_MENU_SETTING_SCH_POW_SET1_POW_ON"/>
    <STRING id = "STR_MENU_SETTING_SCH_POW_SET1_POW_OFF"/>
    

    <!-- image ------------------------------------------------------------------------------------>
//    <IMAGE id = "SPOF_TYPEPOWERON_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\Poweronoff\\\\ST_PON.bmp"</IMAGE>
//    <IMAGE id = "SPOF_TYPEPOWEROFF_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\Poweronoff\\\\ST_POFF.bmp"</IMAGE>
#if 0
#ifndef __MMI_SLIM_IMG_RES__
    <IMAGE id = "SPOF_SETTING_STATUS_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Settings\\\\common\\\\ST_STATU.bmp"</IMAGE>  
#else
    <IMAGE id = "SPOF_SETTING_STATUS_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Settings\\\\common\\\\ST_STATU.bmp"</IMAGE>  
#endif
#endif
    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM"/>
    <SCREEN id = "SCR_ID_SPOF_CONFIRM"/>



    <!-- menu ------------------------------------------------------------------------------------->

    <MENU id = "MENU_SETTING_SCHEDULE_POWER" type = "APP_SUB" str = "STR_MENU_SETTING_SCHEDULE_POWER">
        <MENUITEM id = "MENU_SETTING_SCHEDULE_POWER_ON" str = "STR_MENU_SETTING_SCH_POW_SET1_POW_ON"/>
        <MENUITEM id = "MENU_SETTING_SCHEDULE_POWER_OFF" str = "STR_MENU_SETTING_SCH_POW_SET1_POW_OFF"/>
    </MENU>

    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_spof_reminder_srv_proc"/>

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__   
	<RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_schedule_power_onoff_notify_screen_lock_hdlr"/>   
#endif
#endif /* __MMI_PHNSET_SCHEDULE_POWER_ON_OFF__ */

</APP>

