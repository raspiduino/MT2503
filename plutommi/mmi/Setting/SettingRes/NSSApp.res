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
 * NotificationSettings.Res
 *
 * Project:
 * --------
 * PlutoMMI
 *
 * Description:
 * ------------
 * Resource XML file
 *
 * Author:
 * -------
 * Mengmeng Cao mtk81194
 *
*============================================================================
 *			   HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 18 2012 mengmeng.cao
 * [MAUI_03151306] FTE/PLUTO NSS of Setting
 * nss check in 11b.
 *
 * 05 02 2012 mengmeng.cao
 * [MAUI_03151306] FTE/PLUTO NSS of Setting
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

<APP id = "APP_NSS">

    #ifdef __MMI_NSS_SUPPORT__
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/> 
    <!----------------- String Id ----------------------------------------->             
    <STRING id="STR_ID_SETTING_NOTIFICATIONSETTINGS"/>
    
    <STRING id="STR_ID_SETTING_NOTIFICATIONSETTINGS_BACKGROUND_DATA"/>
    
    <STRING id="STR_ID_APPNAME_NOTIFICATION_CENTER"/>
    <STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT"/> 
		<STRING id="STR_ID_APPNAME_BADGE_APP_ICON"/>
		<STRING id="STR_ID_APPNAME_SOUND"/>
		<STRING id="STR_ID_APPNAME_VIEW_IN_LOCK_SCREEN"/>
		<STRING id="STR_ID_APPNAME_POPUP"/>
		
		<STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT_NONE"/>
		<STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT_STATUSBAR"/>
		<STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT_POPUP"/>
		
		<STRING id="STR_ID_SETTING_BACKGROUND_DATA_RESULT"/>
            
    <!----------------------Image Id----------------------------------------------------------------------->
    <!-- Notification settings image need update the image----------------------------------------SB_NSS.PBM------------------------------->
    <IMAGE id = "IMG_NSS_NCENTER">CUST_IMG_PATH"\\\\MainLCD\\\\Ncenter\\\\NCenter.png"</IMAGE>
    
    <!----------------- Menu Id ------------------------------------------->                       
    <MENU id = "MENU_ID_NSS_APP"  str = "STR_ID_SETTING_NOTIFICATIONSETTINGS" parent = "MAIN_MENU_SETTINGS_MENUID" img = "IMG_NSS_NCENTER" highlight = "mmi_nss_hilight"/>
    
    <!----------------- Screen Id ----------------------------------------->             
    <SCREEN id="GRP_ID_NSS_GROUP"/>
    <SCREEN id="SRN_ID_NSS_APPLIST_SCREEN"/>
    <SCREEN id="SRN_ID_NSS_BACKGROUND_DATA_SCREEN"/>
    
   #endif    
</APP>
