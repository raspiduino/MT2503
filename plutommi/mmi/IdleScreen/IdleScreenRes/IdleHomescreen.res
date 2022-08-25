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
 *  IdleHomescreen.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for OP11 home screen.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
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
 * Jun 23 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_IDLE_HOMESCREEN">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="mmi_rp_cui_dialer_def.h"/>

#if defined(__MMI_OP11_HOMESCREEN__)

    <!----- String Resource Area ---------------------------------------------->
    <STRING id="STR_ID_HS_CALENDAR"/>
    <STRING id="STR_ID_HS_TODAY"/>
    <STRING id="STR_ID_HS_ADD_APPOINTMENT"/>
    <STRING id="STR_ID_HS_SET_ALARM"/>
    <STRING id="STR_ID_HS_CLOCK_SETTINGS"/>
    <STRING id="STR_ID_HS_PHONEBOOK"/>
    <STRING id="STR_ID_HS_CONTACTS"/>
    <STRING id="STR_ID_HS_ADD_CONTACTS"/>
    <STRING id="STR_ID_HS_SET_VIP_CONTACTS"/>
    <STRING id="STR_ID_HS_MY_VIP_CONTACTS"/>
    <STRING id="STR_ID_HS_CALL_LOG"/>
    <STRING id="STR_ID_HS_CALL_HISTORY"/>
    <STRING id="STR_ID_HS_MISSED_CALLS"/>
    <STRING id="STR_ID_HS_RECEIVED_CALLS"/>
    <STRING id="STR_ID_HS_DIALLED_CALLS"/>
    <STRING id="STR_ID_HS_MESSAGES"/>
    <STRING id="STR_ID_HS_WRITE_MESSAGES"/>
    <STRING id="STR_ID_HS_SMS_INBOX"/>
    <STRING id="STR_ID_HS_MMS_INBOX"/>
    <STRING id="STR_ID_HS_EMAIL_INBOX"/>
    <STRING id="STR_ID_HS_INSTANT_MESSAGING"/>
    <STRING id="STR_ID_HS_MEDIA"/>
    <STRING id="STR_ID_HS_ADD_SHORTCUT"/>
    <STRING id="STR_ID_HS_MENU_SETTINGS"/>
    <STRING id="STR_ID_HS_CHANGE_ITEM"/>
    <STRING id="STR_ID_HS_CHANGE_ITEM_PROMPT"/>
    <STRING id="STR_ID_HS_REMOVE_ITEM"/>
    <STRING id="STR_ID_HS_MOVE_ITEM"/>
    <STRING id="STR_ID_HS_WWW"/>
    <STRING id="STR_ID_HS_WWW_LINK1"/>
    <STRING id="STR_ID_HS_WWW_LINK2"/>
    <STRING id="STR_ID_HS_WWW_LINK3"/>
    <STRING id="STR_ID_HS_WWW_LINK4"/>
    <STRING id="STR_ID_HS_WWW_LINK5"/>
    <STRING id="STR_ID_HS_WWW_LINK6"/>
#if defined(__MMI_BROWSER_2__)
    <STRING id="STR_ID_HS_WWW_MY_BOOKMARKS"/>
#endif
    <STRING id="STR_ID_HS_GOTO"/>
    <STRING id="STR_ID_HS_RECENT_EVENTS"/>
    <STRING id="STR_ID_HS_CALL_PLAN"/>
    <STRING id="STR_ID_HS_DEVICE_STATUS"/>
    <STRING id="STR_ID_HS_SIGNAL"/>
    <STRING id="STR_ID_HS_SIGNAL_EXCELLENT"/>
    <STRING id="STR_ID_HS_SIGNAL_HIGH"/>
    <STRING id="STR_ID_HS_SIGNAL_MEDIUM"/>
    <STRING id="STR_ID_HS_SIGNAL_LOW"/>
    <STRING id="STR_ID_HS_BATTERY"/>
    <STRING id="STR_ID_HS_BATTERY_FULL"/>
    <STRING id="STR_ID_HS_BATTERY_HIGH"/>
    <STRING id="STR_ID_HS_BATTERY_MEDIUM"/>
    <STRING id="STR_ID_HS_BATTERY_LOW"/>
    <STRING id="STR_ID_HS_INTERNAL_MEMORY"/>
    <STRING id="STR_ID_HS_EXTERNAL_MEMORY"/>
    <STRING id="STR_ID_HS_PERSONALISATION"/>
    <STRING id="STR_ID_HS_CHANGE_WALLPAPER"/>
    <STRING id="STR_ID_HS_ORGANIZE_SIDEBAR"/>
    <STRING id="STR_ID_HS_SN_MISSED_CALLS"/>
    <STRING id="STR_ID_HS_SN_NEW_MESSAGES"/>
    <STRING id="STR_ID_HS_SN_NEW_EMAILS"/>
    <STRING id="STR_ID_HS_CLEAR_ASK"/>
    <STRING id="STR_ID_HS_CLEARED"/>
    <STRING id="STR_ID_HS_PROCESSING"/>
    <STRING id="STR_ID_HS_CLEAR_ALL_EVENTS"/>
    <STRING id="STR_ID_HS_CLEAR_ALL_EVENTS_ASK"/>
    <STRING id="STR_ID_HS_SOFTNOTE_MISSED_CALL"/>
    <STRING id="STR_ID_HS_SOFTNOTE_MISSED_CALLS"/>
    <STRING id="STR_ID_HS_SOFTNOTE_NEW_SMS"/>
    <STRING id="STR_ID_HS_SOFTNOTE_NEW_SMSS"/>
#if defined(__MMI_EMAIL__)
    <STRING id="STR_ID_HS_SOFTNOTE_NEW_EMAIL"/>
    <STRING id="STR_ID_HS_SOFTNOTE_NEW_EMAILS"/>
#endif /* defined(__MMI_EMAIL__) */


    <!----- Image Resource Area ----------------------------------------------->
    <IMAGE id="IMG_ID_HS_SIDEBAR_INACTIVE_APPOINTMENT">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Calendar.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_INACTIVE_PHONEBOOK">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_PhoneBook.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_INACTIVE_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Phone.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_INACTIVE_MESSAGE">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Msg.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_INACTIVE_MEDIA">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Camera.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_INACTIVE_WWW">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Earth.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_ACTIVE_APPOINTMENT">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Calendar2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_ACTIVE_PHONEBOOK">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_PhoneBook2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_ACTIVE_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Phone2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_ACTIVE_MESSAGE">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Msg2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_ACTIVE_MEDIA">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Camera2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SIDEBAR_ACTIVE_WWW">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Earth2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_INDICATOR_APPOINTMENT">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Calender_Alert.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_INDICATOR_MISSED_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_Call_messed.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_INDICATOR_NEW_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_msg_info.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_INDICATOR_NEW_MMS">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_msg_movie.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_INDICATOR_NEW_EMAIL">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_msg_at.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_INDICATOR_NEW_IM">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HomeICON_msg_voice.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_DEVICE_STATUS_BATTERY">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\SI_BAT"</IMAGE>
    <IMAGE id="IMG_ID_HS_DEVICE_STATUS_SIGNAL">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\SI_SIG"</IMAGE>
    <IMAGE id="IMG_ID_HS_SOFTNOTE">CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_Calllog.gif"</IMAGE>
    <IMAGE id="IMG_ID_HS_SOFTNOTE_MISSED_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_Call.bmp"</IMAGE>
    <IMAGE id="IMG_ID_HS_SOFTNOTE_NEW_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_Message.bmp"</IMAGE>
#if defined(__MMI_EMAIL__)
    <IMAGE id="IMG_ID_HS_SOFTNOTE_NEW_EMAIL">CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_Email.bmp"</IMAGE>
#endif


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="SCR_ID_HS_WRITE_MESSAGE"/>
    <SCREEN id="SCR_ID_HS_MENU_SETTING"/>
    <SCREEN id="SCR_ID_HS_MENU_SETTING_OPT"/>
    <SCREEN id="SCR_ID_HS_GOTO"/>
    <SCREEN id="SCR_ID_HS_DEVICE_STATUS"/>
    <SCREEN id="SCR_ID_HS_PERSONALISATION"/>
    <SCREEN id="SCR_ID_HS_ORGANIZE_SIDEBAR"/>
    <SCREEN id="SCR_ID_HS_PRE_DND"/>
    <SCREEN id="SCR_ID_HS_DND"/>
    <SCREEN id="SCR_ID_HS_SOFTNOTE"/>
    <SCREEN id="SCR_ID_HS_SOFTNOTE_DUMMY"/>
    <SCREEN id="SCR_ID_HS_RECENT_EVENT"/>
    <SCREEN id="SCR_ID_HS_RECENT_EVENT_RETRY"/>
    <SCREEN id="SCR_ID_HS_RECENT_EVENT_PROCESSING"/>
    <SCREEN id="SCR_ID_HS_RECENT_EVENT_CLEAR_ALL_PROCESSING"/>


    <!----- Menu Resource Area ------------------------------------------------>
    <MENU id="MENU_ID_HS_GOTO" type="APP_SUB" str="STR_ID_HS_GOTO">
        <MENUITEM id="MENU_ID_HS_GOTO_RECENT_EVENT" str="STR_ID_HS_RECENT_EVENTS"/>
        <MENUITEM id="MENU_ID_HS_GOTO_CALL_PLAN" str="STR_ID_HS_CALL_PLAN"/>
        <MENUITEM id="MENU_ID_HS_GOTO_DEVICE_STATUS" str="STR_ID_HS_DEVICE_STATUS"/>

        <MENU id="MENU_ID_HS_GOTO_PERSONALISATION" type="APP_SUB" str="STR_ID_HS_PERSONALISATION">
            <MENUITEM id="MENU_ID_HS_GOTO_PERSONALISATION_CHANGE_WALLPAPER" str="STR_ID_HS_CHANGE_WALLPAPER"/>
            <MENUITEM id="MENU_ID_HS_GOTO_PERSONALISATION_ORGANIZE_SIDEBAR" str="STR_ID_HS_ORGANIZE_SIDEBAR"/>
        #if defined(__MMI_DIALER_SEARCH__)
            <MENUITEM id="MENU_ID_HS_GOTO_PERSONALISATION_DIALLER_SEARCH" str="STR_ID_CUI_DIALER_SEARCH"/>
        #endif
        </MENU>
    </MENU>

    <MENU id="MENU_ID_HS_MENU_SETTING_OPT" type="OPTION" str="STR_ID_HS_MENU_SETTINGS">
        <MENUITEM id="MENU_ID_HS_MENU_SETTING_OPT_CHANGE_ITEM" str="STR_ID_HS_CHANGE_ITEM"/>
        <MENUITEM id="MENU_ID_HS_MENU_SETTING_OPT_REMOVE_ITEM" str="STR_ID_HS_REMOVE_ITEM"/>
        <MENUITEM id="MENU_ID_HS_MENU_SETTING_OPT_MOVE_ITEM" str="STR_ID_HS_MOVE_ITEM"/>
    </MENU>

#endif /* defined(__MMI_OP11_HOMESCREEN__) */

</APP>

