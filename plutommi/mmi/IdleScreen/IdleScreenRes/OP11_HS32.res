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
 *  OP11_HS32.res
 *
 * Project:
 * -------- 
 *  MAUI, 10A
 *
 * Description:
 * ------------
 *  Resource refered from: HomeScreenOp11V32.c, HomeScreenOp11Setting.c, vadp_v2p_op11_hs.c
 *
 * Author:
 * -------
 *  Jie Hao (mtk80027)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 21 2013 lu.xiao
 * [MAUI_03463174] [Pluto Slim][MSZ] Pluto slim checkin to 11C for MSZ
 * .
 *
 * 09 30 2011 jie.hao
 * [MAUI_03036685] [OGDR FTE] Home Screen support WIFI
 * .
 *
 * 09 26 2011 jie.hao
 * [MAUI_03036685] [OGDR FTE] Home Screen support WIFI
 * .
 *
 * 09 26 2011 guoyi.zhao
 * [MAUI_03035607] OGDR HS3.2 WLAN shortcut panel support
 * .
 *
 * 09 26 2011 guoyi.zhao
 * [MAUI_03035607] OGDR HS3.2 WLAN shortcut panel support
 * .
 *
 * 08 04 2011 guoyi.zhao
 * [MAUI_02998752] Orange Homescreen 3.2 FTE implementation
 * .
 *
 * 12 06 2010 jie.hao
 * [MAUI_02642955] [NVRAM Revise] New MMI Catch register (xml)
 * .
 *
 * Jun 6 2010 mtk80027
 * [MAUI_02203630] [10A_OG_HS32] can not change wallpaper
 * 
 *
 * May 13 2010 mtk80027
 * [MAUI_02178279] [OG_HS31/32][10A Revise] check-in
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "CustResDef.h"

#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)

#define OP11_HS_ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HS32\\\\"

<?xml version = "1.0" encoding="UTF-8"?>

<APP id="APP_OP11_HS32">

    <!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>


    <!----------------- Screen Id -----------------------------------------> 
    <SCREEN id = "SCR_ID_OP11_HS_PERSONALISATION"/>
    <SCREEN id = "SCR_ID_OP11_HS_EDIT_HS_ITEM"/>
    <SCREEN id = "SCR_ID_OP11_HS_SELECT_HS_ITEM"/>
    <SCREEN id = "SCR_ID_OP11_HS_PLACE_HS_ITEM"/>
    <SCREEN id = "SCR_ID_OP11_HS_PLACE_HS_AGAIN"/>
    <SCREEN id = "SCR_ID_OP11_HS_ADD_HS_ITEM_SELECT"/>
    <SCREEN id = "SCR_ID_OP11_HS_ADD_HS_ITEM_PLACE"/>
    <SCREEN id = "SCR_ID_OP11_HS_ADD_HS_ITEM_REORDER"/>
    <SCREEN id = "SCR_ID_OP11_HS_REMOVE_HS_ITEM"/>
    <SCREEN id = "SCR_ID_OP11_HS_REMOVE_HS_ITEM_CONF"/>
    <SCREEN id = "SCR_ID_OP11_HS_OPTIONS"/>
    <SCREEN id = "SCR_ID_OP11_HS_MORE_SETTING"/>
    <SCREEN id = "SCR_ID_OP11_HS_SETTING_CLK_SIZE"/>
    <SCREEN id = "SCR_ID_OP11_HS_SETTING_DUAL_CLK"/>
    <SCREEN id = "SCR_ID_OP11_HS_SETTING_SHOW_MY_NUM"/>

    <SCREEN id = "SCR_ID_OP11_HS_DUMMY"/>
    <SCREEN id = "SCR_ID_OP11_HS_SET_VIP"/>
    <SCREEN id = "SCR_ID_OP11_HS_EDIT_VIP"/>
    <SCREEN id = "SCR_ID_OP11_HS_SET_ACCOUNT"/>
    <SCREEN id = "SCR_ID_OP11_HS_EDIT_ACCOUNT"/>
    <SCREEN id = "SCR_ID_OP11_HS_DEV_STATUS"/>

    <SCREEN id = "SCR_ID_OP11_HS_US_VIP"/>
    <SCREEN id = "SCR_ID_OP11_HS_VIP_OPTION"/>
    
    <SCREEN id = "SCR_ID_OP11_HS_WP_MGR"/>
    <SCREEN id = "SCR_ID_OP11_HS_WP_SEL"/>
    <SCREEN id = "SCR_ID_OP11_HS_WP_ATTACH"/>
    
    <SCREEN id = "SCR_ID_OP11_HS_SETTING_KEYPAD_SEARCH"/>
    <SCREEN id = "SCR_ID_OP11_HS_MORE_SETTING_HELP"/>
    <SCREEN id = "SCR_ID_OP11_RRD_SHCT_SELECT"/>
    <SCREEN id = "SCR_ID_OP11_RRD_SHCT_PLACE"/>
    <SCREEN id = "SCR_ID_OP11_HS_MAX_ITEMS_REACHED"/>
    <SCREEN id = "SCR_ID_OP11_HS_INPUT_MY_NUMBER"/>
    <SCREEN id = "SCR_ID_OP11_HS_EDIT_SIDEBAR_ICONS"/>

    <SCREEN id = "SCR_ID_OP11_HS_FLIGHTMODE_PROGRESS"/>


    <!----------------- String Id -----------------------------------------> 
    <STRING id="STR_ID_OP11_HS_CLL"/>
    <STRING id="STR_ID_OP11_HS_CON"/>
    <STRING id="STR_ID_OP11_HS_MES"/>
    <STRING id="STR_ID_OP11_HS_EML"/>
    <STRING id="STR_ID_OP11_HS_OMR"/>
    <STRING id="STR_ID_OP11_HS_OWD"/>
    <STRING id="STR_ID_OP11_HS_PRO"/>
    <STRING id="STR_ID_OP11_HS_ALM"/>
    <STRING id="STR_ID_OP11_HS_CAL"/>
    <STRING id="STR_ID_OP11_HS_MUS"/>
    <STRING id="STR_ID_OP11_HS_PHO"/>
    <STRING id="STR_ID_OP11_HS_CNX"/>
    <STRING id="STR_ID_OP11_HS_DST"/>
    <STRING id="STR_ID_OP11_HS_STK"/>
    <STRING id="STR_ID_OP11_HS_USVIP"/>

    <STRING id="STR_ID_OP11_HS_PERSONALISE_HS"/>
    <STRING id="STR_ID_OP11_HS_EDIT_ITEMS"/>
    <STRING id="STR_ID_OP11_HS_REORDER_ITEMS"/>
    <STRING id="STR_ID_OP11_HS_REORDER_HS_ITEM"/>
    <STRING id="STR_ID_OP11_HS_ADD_ITEM"/>
    <STRING id="STR_ID_OP11_HS_ADD_ITEM_TO_HS"/>
    <STRING id="STR_ID_OP11_HS_REMOV_ITEMS"/>
    <STRING id="STR_ID_OP11_HS_MOVE_TO_NEW_LOC"/>
    <STRING id="STR_ID_OP11_HS_MORE_SETTGINGS"/>

    <STRING id="STR_ID_OP11_HS_PERSONALISE_INFO"/>

    <STRING id="STR_ID_OP11_HS_PERSONALISE_INFO_S"/>
      
    <STRING id="STR_ID_OP11_HS_CHS_TO_MOV"/>
    <STRING id="STR_ID_OP11_HS_CHS_ANOTHER_MOV"/>
    <STRING id="STR_ID_OP11_HS_ITEM_MOVE_TO"/>
    <STRING id="STR_ID_OP11_HS_CHS_TO_ADD"/>
    <STRING id="STR_ID_OP11_HS_ADD_LIMIT_INFO8"/>
    <STRING id="STR_ID_OP11_HS_ADD_LIMIT_INFO12"/>
    <STRING id="STR_ID_OP11_HS_REMOVE"/>
    <STRING id="STR_ID_OP11_HS_FROM_YOUR_HS"/>
    <STRING id="STR_ID_OP11_HS_REMOVE_HS_ITEMS"/>
    <STRING id="STR_ID_OP11_HS_CHS_TO_REMOVE"/>
    
    <STRING id="STR_ID_OP11_HS_REORDER_SHCTS"/>

    <STRING id="STR_ID_OP11_HS_SHCT_CHS_TO_MOV"/>
    <STRING id="STR_ID_OP11_HS_SHCT_MOV_TO"/>
    <STRING id="STR_ID_OP11_HS_SHCT_CHS_OTH_MOV"/>
    <STRING id="STR_ID_OP11_HS_MORE_HS_SETTING"/>
    <STRING id="STR_ID_OP11_HS_WALLPAPER"/>
    <STRING id="STR_ID_OP11_HS_TIME_FMT"/>
    <STRING id="STR_ID_OP11_HS_CLK_SIZE"/>
    <STRING id="STR_ID_OP11_HS_DUAL_CLK"/>
    <STRING id="STR_ID_OP11_HS_DAT_FMT"/>
    <STRING id="STR_ID_OP11_HS_MY_NUMBER"/>
    <STRING id="STR_ID_OP11_HS_LEFT_KEY"/>
    <STRING id="STR_ID_OP11_HS_RIGHT_KEY"/>

    <STRING id="STR_ID_OP11_HS_KEYPAD_SEARCH"/>

    <STRING id="STR_ID_OP11_HS_PLACE_HERE"/>
    <STRING id="STR_ID_OP11_HS_SMALL"/>
    <STRING id="STR_ID_OP11_HS_LARGE"/>
    <STRING id="STR_ID_OP11_HS_SHOW"/>  
    <STRING id="STR_ID_OP11_HS_HIDE"/>  
    
    <STRING id="STR_ID_OP11_HS32_CLL_VOICEMAIL"/>
    <STRING id="STR_ID_OP11_HS32_CLL_CALL_LOG"/>
    <STRING id="STR_ID_OP11_HS32_CLL_CALL_PLAN"/>
    <STRING id="STR_ID_OP11_HS32_CLL_MISSED_CALLS"/>

    <STRING id="STR_ID_OP11_HS32_CON_CONTACT_LIST"/>
    <STRING id="STR_ID_OP11_HS32_CON_SET_VIP"/>
    <STRING id="STR_ID_OP11_HS32_CON_VIP"/>
    <STRING id="STR_ID_OP11_HS32_CON_EDIT_VIP"/>

    <STRING id="STR_ID_OP11_HS32_CON_VIP_1"/>
    <STRING id="STR_ID_OP11_HS32_CON_VIP_2"/>
    <STRING id="STR_ID_OP11_HS32_CON_VIP_3"/>
    <STRING id="STR_ID_OP11_HS32_CON_VIP_4"/>
    <STRING id="STR_ID_OP11_HS32_CON_VIP_5"/>

    <STRING id="STR_ID_OP11_HS32_NO_NEW_MSG"/>
    <STRING id="STR_ID_OP11_HS32_NO_MISS_CALL"/>
    <STRING id="STR_ID_OP11_HS32_NO_CONTENT"/>
    <STRING id="STR_ID_OP11_HS32_NO_DETAILS"/>
    <STRING id="STR_ID_OP11_HS32_NOT_SET"/>
    <STRING id="STR_ID_OP11_HS32_UNKNOWN"/>
    <STRING id="STR_ID_OP11_HS32_NO_SUBJECT"/>

    <STRING id="STR_ID_OP11_HS32_MES_WRITE_MSG"/>
    <STRING id="STR_ID_OP11_HS32_MES_WRITE_TXT_MSG"/>
    <STRING id="STR_ID_OP11_HS32_MES_WRITE_PIC_MSG"/>
    <STRING id="STR_ID_OP11_HS32_MES_INBOX"/>
    <STRING id="STR_ID_OP11_HS32_MES_VIEW_MSG_1"/>

    <STRING id="STR_ID_OP11_HS32_EML_SET_ACCOUNT"/>
    <STRING id="STR_ID_OP11_HS32_EML_TO_S"/>
    <STRING id="STR_ID_OP11_HS32_EML_S_OR_R"/>

    <STRING id="STR_ID_OP11_HS32_EML_WRITE_EMAIL"/>
    <STRING id="STR_ID_OP11_HS32_EML_INBOX"/>
    <STRING id="STR_ID_OP11_HS32_EML_EDIT_ACCOUNT"/>

    <STRING id="STR_ID_OP11_HS32_EML_ACCOUNT_1"/>
    <STRING id="STR_ID_OP11_HS32_EML_ACCOUNT_2"/>
    <STRING id="STR_ID_OP11_HS32_EML_ACCOUNT_3"/>
    <STRING id="STR_ID_OP11_HS32_EML_ACCOUNT_4"/>
    <STRING id="STR_ID_OP11_HS32_EML_ACCOUNT_5"/>

    <STRING id="STR_ID_OP11_HS32_OMR_OM"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CV"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CT"/>
    <STRING id="STR_ID_OP11_HS32_OMR_SP"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CV_VIEW"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CV_NO_NEW"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CT_NO"/>
    <STRING id="STR_ID_OP11_HS32_OMR_AVAIL"/>
    <STRING id="STR_ID_OP11_HS32_OMR_INVISI"/>
    <STRING id="STR_ID_OP11_HS32_OMR_BUSY"/>
    <STRING id="STR_ID_OP11_HS32_OMR_AWAY"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CV_SHORT"/>
    <STRING id="STR_ID_OP11_HS32_OMR_CT_SHORT"/>

    <STRING id="STR_ID_OP11_HS32_OWD_OW"/>
    <STRING id="STR_ID_OP11_HS32_OWD_EU"/>
    <STRING id="STR_ID_OP11_HS32_OWD_MB"/>
    <STRING id="STR_ID_OP11_HS32_OWD_NO_BK"/>

    <STRING id="STR_ID_OP11_HS32_OWD_BK1"/>
    <STRING id="STR_ID_OP11_HS32_OWD_BK2"/>
    <STRING id="STR_ID_OP11_HS32_OWD_BK3"/>

    <STRING id="STR_ID_OP11_HS32_PRO"/>
    <STRING id="STR_ID_OP11_HS32_PRO_SILENT"/>

    <STRING id="STR_ID_OP11_HS32_ALM_ALARMS"/>

    <STRING id="STR_ID_OP11_HS32_CAL_CL"/>
    <STRING id="STR_ID_OP11_HS32_CAL_TODAY"/>
    <STRING id="STR_ID_OP11_HS32_CAL_TW"/>
    <STRING id="STR_ID_OP11_HS32_CAL_CA"/>

    <STRING id="STR_ID_OP11_HS32_MUS_PL"/>
    <STRING id="STR_ID_OP11_HS32_MUS_MM"/>

    <STRING id="STR_ID_OP11_HS32_PHO_TP"/>
    <STRING id="STR_ID_OP11_HS32_PHO_MP"/>
    <STRING id="STR_ID_OP11_HS32_PHO_MV"/>

    <STRING id="STR_ID_OP11_HS32_CNX_WIFI"/>
    <STRING id="STR_ID_OP11_HS32_CNX_BT"/>
    <STRING id="STR_ID_OP11_HS32_CNX_FM"/>

    <STRING id="STR_ID_OP11_HS32_DST"/>

    <STRING id="STR_ID_OP11_HS32_STK"/>

    <STRING id="STR_ID_OP11_HS32_VIP_TO_S"/>
    <STRING id="STR_ID_OP11_HS32_VIP_TO_S_OR_R"/>

    <STRING id="STR_ID_OP11_HS32_VIP_SET"/>
    <STRING id="STR_ID_OP11_HS32_VIP_REMOVE"/>

    <STRING id="STR_ID_OP11_HS_MES_WRITE_TXT_MSG"/>
    <STRING id="STR_ID_OP11_HS_MES_WRITE_PIC_MSG"/>
   
    <STRING id="STR_ID_OP11_HS_REMOV_ITEM"/>
    
    <STRING id="STR_ID_OP11_HS_HELP_CONTENT"/>
    
    <STRING id="STR_ID_OP11_HS_MY_NUM_DISPLAY"/>
    <STRING id="STR_ID_OP11_HS_INPUT_MY_NUMBER"/>

    <STRING id="STR_ID_OP11_HS_TIME_FMT_12H"/>
    <STRING id="STR_ID_OP11_HS_TIME_FMT_24H"/>
    <STRING id="STR_ID_OP11_HS_NO_ITEM_TO_REMOVE"/>

    <STRING id="STR_ID_OP11_HS32_TURN_ON"/>
    <STRING id="STR_ID_OP11_HS32_TURN_OFF"/>
    <STRING id="STR_ID_OP11_HS32_TURN_OFF_ALARM"/>

    <STRING id="STR_ID_OP11_HS_NO_ITEM_TO_ADD"/>

    /* __MMI_OP11_HOMESCREEN_US__ */

    <STRING id="STR_ID_OP11_HS32_SET_KEY_CONTACT"/>
    <STRING id="STR_ID_OP11_HS32_KEY_CONTACT"/>

    <STRING id="STR_ID_OP11_HS32_PRO_SET_SILENT"/>
    <STRING id="STR_ID_OP11_HS32_PRO_SET_NORMAL"/>

    <STRING id="STR_ID_OP11_HS32_MES_US_WRITE_MSG"/>
    <STRING id="STR_ID_OP11_HS32_US_VOICEMAIL"/>


    <STRING id="STR_ID_OP11_HS_US_PERSONALISE_HS"/>
    <STRING id="STR_ID_OP11_HS_EDIT_SIDEBAR_ICON"/>
    <STRING id="STR_ID_OP11_HS_CHANGE_WALLPAPER"/>

    <STRING id="STR_ID_OP11_HS_HIDE_MYNUMBER"/>
    <STRING id="STR_ID_OP11_HS_SHOW_MYNUMBER"/>

    <STRING id="STR_ID_OP11_HS32_SET_ALARM"/>
    <STRING id="STR_ID_OP11_HS32_ALM_SET"/>

    <STRING id="STR_ID_OP11_HS32_US_MES_VIEW_MSG_1"/>
    <STRING id="STR_ID_OP11_HS32_US_CLL_MISSED_CALLS"/>

    <STRING id="STR_ID_OP11_HS_TO_SHOW_HIDE"/>
    <STRING id="STR_ID_OP11_HS_SHOW_ICON"/>
    <STRING id="STR_ID_OP11_HS_HIDE_ICON"/>

    <STRING id="STR_ID_OP11_HS32_US_VIP_SEND_MES"/>
    <STRING id="STR_ID_OP11_HS32_US_VIP_MAKE_CALL"/>
    <STRING id="STR_ID_OP11_HS32_US_VIP_SWITCH"/>
    <STRING id="STR_ID_OP11_HS32_US_VIP_REMOVE_CON"/>
    <STRING id="STR_ID_OP11_HS32_US_VIP_CONTACT"/>
    

    /* (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__)) */

    <STRING id="STR_ID_OP11_HS_SWITCH_VIEWS"/>
    <STRING id="STR_ID_OP11_HS_SET_WP_PANELS"/>
    <STRING id="STR_ID_OP11_HS_EDIT_WP_PANELS"/>

    <STRING id="STR_ID_OP11_HS_ATTACH_WP"/>
    <STRING id="STR_ID_OP11_HS_DETACH_WP"/>

    <STRING id="STR_ID_OP11_HS32_ALARM_1"/>
    <STRING id="STR_ID_OP11_HS32_ALARM_2"/>

    <STRING id="STR_ID_OP11_HS32_PANEL"/>
    <STRING id="STR_ID_OP11_HS32_ATTACH"/>
    <STRING id="STR_ID_OP11_HS32_WP_TO_A"/>
    <STRING id="STR_ID_OP11_HS32_WP_TO_S"/>
    <STRING id="STR_ID_OP11_HS32_WP_TO_S_OR_R"/>

    <!-- ******** below string is used for Venus UI *******-->
    <STRING id="VAPP_OP11_HS_STR_DEVICE_STATUS"/>
    <STRING id="VAPP_OP11_HS_STR_SIGNAL_STRENGTH"/>
    <STRING id="VAPP_OP11_HS_STR_SIGNAL_EXCELLENT"/>
    <STRING id="VAPP_OP11_HS_STR_SIGNAL_HIGH"/>
    <STRING id="VAPP_OP11_HS_STR_SIGNAL_MEDIUM"/> 
    <STRING id="VAPP_OP11_HS_STR_SIGNAL_LOW"/>  
    <STRING id="VAPP_OP11_HS_STR_BATTERY"/>  
    <STRING id="VAPP_OP11_HS_STR_INTERNAL_MEMORY"/>  
    <STRING id="VAPP_OP11_HS_STR_EXTERNAL_MEMORY"/>  
    <STRING id="VAPP_OP11_HS_STR_PHONE"/>  
    <STRING id="VAPP_OP11_HS_STR_CARD"/>
    <STRING id="VAPP_OP11_HS_STR_PERSONALISE"/> 
    <STRING id="VAPP_OP11_HS_STR_MENU"/>
    <STRING id="VAPP_OP11_HS_STR_MAIN_MENU"/>
    <STRING id="VAPP_OP11_HS_STR_UNLOCK"/>
    <STRING id="VAPP_OP11_HS_STR_STATUS"/>  
    <STRING id="VAPP_OP11_HS_STR_STATUS_ON"/>  
    <STRING id="VAPP_OP11_HS_STR_STATUS_OFF"/>
    <STRING id="VAPP_OP11_HS_STR_NAME"/> 
    <STRING id="VAPP_OP11_HS_STR_VISIBLE"/>
    <STRING id="VAPP_OP11_HS_STR_INVISIBLE"/>
    <STRING id="VAPP_OP11_HS_STR_SIGNAL_VALUE"/>
    <STRING id="VAPP_OP11_HS_STR_NW"/> 
    <STRING id="VAPP_OP11_HS_STR_NO_ALARM"/>
    <STRING id="VAPP_OP11_HS_STR_TODAY"/>
    <STRING id="VAPP_HS32_STR_MUSIC_PLAYER_NOT_READY"/>
    <STRING id="VAPP_HS32_STR_MUSIC_PLAYER_PLAYED"/>
    <STRING id="VAPP_HS32_STR_MUSIC_PLAYER_PLAYING"/>
    <STRING id="VAPP_HS32_STR_MUSIC_PLAYER_PLAYING_S"/>
    <STRING id="VAPP_HS32_STR_MUSIC_PLAYER_UNKNOWN_TITLE"/>
    <STRING id="VAPP_HS32_STR_MUSIC_PLAYER_UNKNOWN_ARTIST"/>

    <STRING id="VAPP_HS32_STR_VIP_CONTACT_TITLE"/>
    <STRING id="VAPP_HS32_STR_VIP_CONTACT_TITLE_SET"/>
    <STRING id="VAPP_HS32_STR_VIP_CONTACT_HELP_INFO"/>
    <STRING id="VAPP_HS32_STR_VIP_CONTACT_THIN_ITEM_INFO"/>
    <STRING id="VAPP_HS32_STR_VIP_CONTACT_UNKNOWN"/>


    <!----------------- Image Id -----------------------------------------> 

    <IMAGE id ="VAPP_HS32_IMG_EVT_APPOITMENT">CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_Appointments.pbm"</IMAGE>
    
    <IMAGE id ="VAPP_HS32_IMG_EVT_EMAIL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_Emails.pbm" </IMAGE>  

    <IMAGE id="VAPP_HS32_IMG_EVT_OG_MSG" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_OG_Messengers.pbm" </IMAGE>  

    <IMAGE id="VAPP_HS32_IMG_EVT_MMS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_PicMSG.pbm" </IMAGE>  

    <IMAGE id="VAPP_HS32_IMG_EVT_SMS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_TextMSG.pbm" </IMAGE>  

    <IMAGE id="VAPP_HS32_IMG_EVT_VOCALL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_VoiceCalls.pbm" </IMAGE>  

    <IMAGE id="VAPP_HS32_IMG_EVT_VOMAIL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_EventIcon_Voicemail_1.pbm" </IMAGE>  
 
    <IMAGE id="IMG_ID_OP11_HS_CLL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Call.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_CON" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Contact.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_MES" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Message.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_EML" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Email.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_OMR" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_OG_Messenger.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_OMR_DYNAMIC_AVAIL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Msgr_Green.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_OMR_DYNAMIC_UNAVAIL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Msgr_Red.png" </IMAGE>

    
    <IMAGE id="IMG_ID_OP11_HS_OWD" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_OG_World.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_PRO" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Pfofile.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_PRO_SILENT" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Profile_Silent.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ALM" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Alarm.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_CAL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Calendar.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_MUS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_MusicPlayer.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_MUS_PROGRESS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Music_Play.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_MUS_NOT_PROGRESS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Music_Favorite.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_PHO" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_OG_Photography.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_CNX" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Connection.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_DST" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_DeviceStates.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_STK" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_STK.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_TPH" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_USTPH.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_VIP" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_USVIP.png" </IMAGE>
        
    <!-- ******** below image is used for menu list *******-->
    <IMAGE id="IMG_ID_OP11_HS_ML_CLL" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Call.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_CON" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Contacts.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_MES" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Message.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_EML" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Email.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_OMR" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_OrangeMessenger.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_OWD" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_OrangeWorld.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_PRO" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Profile.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_ALM" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Alarms.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_CAL" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Calendar.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_MUS" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Music.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_PHO" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Photography.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_CNX" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_Connections.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_DST" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_DeviceStatus.pbm" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_ML_STK" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_SIMToolkit.pbm" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_ML_TPH" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_USTPH.pbm" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_ML_VIP" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_USVIP.pbm" </IMAGE>


    <IMAGE id="IMG_ID_OP11_HS_ML_TOPLINE" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_LIST_Topline.png" </IMAGE> 
        
    <IMAGE id="IMG_ID_OP11_HS_ML_BOTTOMLINE" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_LIST_Bottomline.png" </IMAGE> 

    <IMAGE id="IMG_ID_OP11_HS_ML_LOCK" > CUST_IMG_PATH"\\\\MainLCD\\\\IdleAPP\\\\MENU_LIST_Lock.pbm" </IMAGE> 

    <IMAGE id="IMG_ID_OP11_HS32_SHCT_VOICE_CALL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_VoiceCall.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_VIDEO_CALL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_VideoCall.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_SMS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_Message_SMS.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_MMS" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_Message_MMS.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_EML" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_Email.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_OMR_CV" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_OM_Conversation.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_OMR_AVAIL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_OM_Available.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_OMR_INVISI" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_OM_Invisible.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_OMR_BUSY" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_OM_Busy.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_OMR_AWAY" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_OM_Away.pbm" </IMAGE>  
    <IMAGE id="IMG_ID_OP11_HS32_SHCT_CAL" > CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Shct_Calendar.pbm" </IMAGE>  
   
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))

    <IMAGE id="IMG_ID_OP11_HS_WPANEL_ALM"> CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Alarm_Large.png" </IMAGE>
    
    <IMAGE id="IMG_ID_OP11_HS_WPANEL_CNX"> CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_Connection_Large.png" </IMAGE>

    <IMAGE id="IMG_ID_OP11_HS_WPANEL_DST"> CUST_IMG_PATH"\\\\MainLCD\\\\HS\\\\HS_Icon_DeviceStatus_Large.png" </IMAGE>
        
#endif   

    <!-- ******** below image is used for Venus UI *******-->
    <IMAGE id="VAPP_OP11_HS_IMG_SHORTCUT_BAR">OP11_HS_ROOT_PATH"Shortcut_Bar_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_START_LINE">OP11_HS_ROOT_PATH"Sidebar_start_line.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SIDEBAR_BG_LARGE">OP11_HS_ROOT_PATH"SidebarBG_Large.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SIDEBAR_BG_6">OP11_HS_ROOT_PATH"SidebarBG_6icons.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SIDEBAR_BG_5">OP11_HS_ROOT_PATH"SidebarBG_5icons.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SIDEBAR_BG_4">OP11_HS_ROOT_PATH"SidebarBG_4icons.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SIDEBAR_BG_3">OP11_HS_ROOT_PATH"SidebarBG_3icons.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SIDEBAR_BG_2">OP11_HS_ROOT_PATH"SidebarBG_2icons.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DOWN_ARROW">OP11_HS_ROOT_PATH"Sidebar_Arrow_Down.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DOWN_ARROW_SELECT">OP11_HS_ROOT_PATH"Sidebar_Arrow_Down_Select.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_UP_ARROW">OP11_HS_ROOT_PATH"Sidebar_Arrow_UP.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_UP_ARROW_SELECT">OP11_HS_ROOT_PATH"Sidebar_Arrow_UP_Select.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_LEFT_ARROW_UP">OP11_HS_ROOT_PATH"Shortcut_Arrow_L_Unselect.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_LEFT_ARROW_DOWN">OP11_HS_ROOT_PATH"Shortcut_Arrow_L_Select.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_RIGHT_ARROW_UP">OP11_HS_ROOT_PATH"Shortcut_Arrow_R_Unselect.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_RIGHT_ARROW_DOWN">OP11_HS_ROOT_PATH"Shortcut_Arrow_R_Select.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DOT_UNFOCUSED">OP11_HS_ROOT_PATH"Shortcut_dot_unfocused.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DOT_FOCUSED">OP11_HS_ROOT_PATH"Shortcut_dot_focused.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_BG">OP11_HS_ROOT_PATH"Shortcut_Bar_BigBG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SHORTCUT_PANEL_BG">OP11_HS_ROOT_PATH"Shortcut_Panel_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_BG_S">OP11_HS_ROOT_PATH"HS_EventIcon_BG_S.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_BG_L">OP11_HS_ROOT_PATH"HS_EventIcon_BG_L.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_0">OP11_HS_ROOT_PATH"HS_EventIcon_Num0.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_1">OP11_HS_ROOT_PATH"HS_EventIcon_Num1.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_2">OP11_HS_ROOT_PATH"HS_EventIcon_Num2.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_3">OP11_HS_ROOT_PATH"HS_EventIcon_Num3.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_4">OP11_HS_ROOT_PATH"HS_EventIcon_Num4.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_5">OP11_HS_ROOT_PATH"HS_EventIcon_Num5.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_6">OP11_HS_ROOT_PATH"HS_EventIcon_Num6.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_7">OP11_HS_ROOT_PATH"HS_EventIcon_Num7.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_8">OP11_HS_ROOT_PATH"HS_EventIcon_Num8.png"</IMAGE>
        <IMAGE id="VAPP_OP11_HS_IMG_IND_NUM_9">OP11_HS_ROOT_PATH"HS_EventIcon_Num9.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_MISC_PANEL_BG">OP11_HS_ROOT_PATH"Panel_Msic_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_ALARM">OP11_HS_ROOT_PATH"HS_Alarm.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SILENT">OP11_HS_ROOT_PATH"Panel_Silent.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_KEY_LOCK">OP11_HS_ROOT_PATH"Panel_Lock.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_BAT_LEV0">OP11_HS_ROOT_PATH"Device_Battery_Level0.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_BAT_LEV1">OP11_HS_ROOT_PATH"Device_Battery_Level1.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_BAT_LEV2">OP11_HS_ROOT_PATH"Device_Battery_Level2.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_BAT_LEV3">OP11_HS_ROOT_PATH"Device_Battery_Level3.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_SIG_LOW">OP11_HS_ROOT_PATH"Device_Signal_Low.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_SIG_MID">OP11_HS_ROOT_PATH"Device_Signal_Med.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_SIG_HIGH">OP11_HS_ROOT_PATH"Device_Signal_High.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_DEV_SIG_EXC">OP11_HS_ROOT_PATH"Device_Signal_Excellent.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_PROG_BG">OP11_HS_ROOT_PATH"Progress_Status_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_PROG">OP11_HS_ROOT_PATH"Progress_Status.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_STATUS_LINE_V">OP11_HS_ROOT_PATH"Device_Status_Line_V.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_STATUS_LINE_H">OP11_HS_ROOT_PATH"Device_Status_Line_H.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_MUSIC_PLAYER_DEFAULT_COVER">OP11_HS_ROOT_PATH"MusicPlayer_Default.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_MUSIC_PLAYER_PROGRESS_BAR_BG">OP11_HS_ROOT_PATH"Progress_Status_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_MUSIC_PLAYER_PROGRESS_BAR_FG">OP11_HS_ROOT_PATH"Progress_Status.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_MUSIC_PLAYER_PROGRESS_BAR_DISABLE">OP11_HS_ROOT_PATH"Progress_Status_Disable.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_LIST_THIN_HIGHLIGHT_BG">OP11_HS_ROOT_PATH"List_Thin_Highlight_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_LIST_THICK_HIGHLIGHT_BG">OP11_HS_ROOT_PATH"List_Thick_Highlight_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_LIST_THICK_NORMAL_BG">OP11_HS_ROOT_PATH"List_Thick_Normal_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_VIP_CONTACT_DEFAULT">OP11_HS_ROOT_PATH"HS_Icon_USVIP_Default.png"</IMAGE>
#if (defined(__MMI_OP11_HOMESCREEN_0302__) && !defined(__MMI_OP11_HOMESCREEN_US__))
    <IMAGE id=" VAPP_OP11_HS_IMG_INFO_BAR_BG_THIN">OP11_HS_ROOT_PATH"InfoBar_BG_Thin.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_INFO_BAR_BG_THICK">OP11_HS_ROOT_PATH"InfoBar_BG_Thick.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SVI_BG_LEFT">OP11_HS_ROOT_PATH"Expanded_LeftBG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SVI_BG_RIGHT">OP11_HS_ROOT_PATH"Expanded_RightBG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SVI_ARROW_LEFT">OP11_HS_ROOT_PATH"Expanded_Arrow_Left.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_SVI_ARROW_RIGHT">OP11_HS_ROOT_PATH"Expanded_Arrow_Right.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_UFW_BG_1LINE">OP11_HS_ROOT_PATH"Expanded_MiddleBG_1line.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_UFW_BG_2LINE">OP11_HS_ROOT_PATH"Expanded_MiddleBG_2line.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_UFW_BG_3LINE">OP11_HS_ROOT_PATH"Expanded_MiddleBG_3line.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_XDC_STL">OP11_HS_ROOT_PATH"Expanded_Start_line.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_XDC_SCP_BG">OP11_HS_ROOT_PATH"Expanded_ShortcutBar_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_WALLPAPER_PANEL_BG">OP11_HS_ROOT_PATH"Panel_Wallpaper_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_WALLPAPER_PANEL_FOCUS_BG">OP11_HS_ROOT_PATH"Panel_Wallpaper_Focus_BG.png"</IMAGE>
    <IMAGE id="VAPP_OP11_HS_IMG_WALLPAPER_PANEL_FOCUS_EMPTY_BG">OP11_HS_ROOT_PATH"Panel_Wallpaper_Focus_Empty.png"</IMAGE>
#endif 
   
#ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_OP11_HS_STATUS_BAR_BG"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusBar\\\\StatusBar_BG.png" </IMAGE>
    <IMAGE id="IMG_ID_OP11_HS_SOFTKEY_BAR_BG"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\SoftkeyBar_BG.png" </IMAGE>
#endif
   
   <!--------------------------------------------------------------------------------
     * Personalise Homescreen 
     *      Switch views
     *      Edit Homescreen items
     *      Set wallpaper panels
     *      More settings...
     *      Help
     * 
     * Edit Homescreen items
     *		Reorder items
	   *		Add item
	   *		Remove items
	   *
     * Options
     *      Reorder shortcuts
     *      Attach to wallpaper
	   *		Switch views
	   *		Edit Homescreen items
     *      More settings...
	   *		Help   
   ------------------------------------------------------------------------------->
    <!-- sub menu : Edit Homescreen items -->
    <MENUITEM id="MENU_ID_OP11_HS_REORDER_ITEMS" str="STR_ID_OP11_HS_REORDER_ITEMS" highlight="mmi_op11_hs_hilight_reorder_items"/>
    <MENUITEM id="MENU_ID_OP11_HS_ADD_ITEM"      str="STR_ID_OP11_HS_ADD_ITEM"      highlight="mmi_op11_hs_hilight_add_item"/>
    <MENUITEM id="MENU_ID_OP11_HS_REMOVE_ITEMS"  str="STR_ID_OP11_HS_REMOV_ITEMS"   highlight="mmi_op11_hs_hilight_remove_items"/>
     
    <!-- Personalise Homescreen Menu  -->

    <MENUITEM id="MENU_ID_OP11_HS_SWITCH_VIEWS"  str="STR_ID_OP11_HS_SWITCH_VIEWS"   highlight="mmi_op11_hs_hilight_switch_views"/>

    <MENUITEM id="MENU_ID_OP11_HS_SET_WP_PANELS"  str="STR_ID_OP11_HS_SET_WP_PANELS"  highlight="mmi_op11_hs_hilight_set_wp_panels" />
    <MENUITEM id="MENU_ID_OP11_HS_EDIT_WP_PANELS" str="STR_ID_OP11_HS_EDIT_WP_PANELS" highlight="mmi_op11_hs_hilight_edit_wp_panels"/>

    <MENUITEM id="MENU_ID_OP11_HS_MORE_SETTINGS" str="STR_ID_OP11_HS_MORE_SETTGINGS" highlight="mmi_op11_hs_hilight_more_settings" />
    <MENUITEM id="MENU_ID_OP11_HS_HELP"          str="STR_GLOBAL_HELP"               highlight="mmi_op11_hs_hilight_help" img="0"/>
                            
    <MENUITEM id ="MENU_ID_OP11_HS_CONTEXT_ITEM"  str="STR_GLOBAL_INVALID"           highlight="mmi_op11_hs_hilight_context_item" img="0"/>
    <MENUITEM id ="MENU_ID_OP11_HS_REORDER_SHCTS" str="STR_ID_OP11_HS_REORDER_SHCTS" highlight="mmi_op11_hs_hilight_reorder_shcts" img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_ATTACH_WP"     str="STR_ID_OP11_HS_ATTACH_WP"     highlight="mmi_op11_hs_hilight_attach_wp" img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_DETACH_WP"     str="STR_ID_OP11_HS_DETACH_WP"  highlight="mmi_op11_hs_hilight_detach_wp"/>

    <MENUITEM id="MENU_ID_OP11_HS_CLOCK_SIZE_LARGE" str="STR_ID_OP11_HS_LARGE" />
    <MENUITEM id="MENU_ID_OP11_HS_CLOCK_SIZE_SMALL" str="STR_ID_OP11_HS_SMALL" />

    <MENUITEM id="MENU_ID_OP11_HS_DUAL_CLOCK_ON"    str="STR_GLOBAL_ON" />
    <MENUITEM id="MENU_ID_OP11_HS_DUAL_CLOCK_OFF"   str="STR_GLOBAL_OFF" />

    <MENUITEM id="MENU_ID_OP11_HS_KEYPAD_SEARCH_ON"    str="STR_GLOBAL_ON" />
    <MENUITEM id="MENU_ID_OP11_HS_KEYPAD_SEARCH_OFF"   str="STR_GLOBAL_OFF" />




    <!-- Personalise Homescreen - US __MMI_OP11_HOMESCREEN_US__  -->
    <MENUITEM id="MENU_ID_OP11_HS_EDIT_SIDEBAR"     str="STR_ID_OP11_HS_EDIT_SIDEBAR_ICON" highlight="mmi_op11_hs_hilight_edit_hs_item" img="0" />
    <MENUITEM id="MENU_ID_OP11_HS_CHANGE_WALLPAPER" str="STR_ID_OP11_HS_CHANGE_WALLPAPER"  highlight="mmi_op11_hs_hilight_us_change_wallpaper" img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_MYNUMBER"         str="STR_ID_OP11_HS_HIDE_MYNUMBER"     highlight="mmi_op11_hs_hilight_us_switch_mynumber" img="0"/>   
    
    <MENU id="MENU_ID_OP11_HS_US_OPTION" str="NULL" img="NULL" >
        <MENUITEM_ID> MENU_ID_OP11_HS_EDIT_SIDEBAR </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_CHANGE_WALLPAPER </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_MYNUMBER </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_HELP </MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_OP11_HS_EDIT_HS_ITEM" str="STR_ID_OP11_HS_EDIT_ITEMS" highlight="mmi_op11_hs_hilight_edit_hs_item">
        <MENUITEM_ID> MENU_ID_OP11_HS_REORDER_ITEMS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_ADD_ITEM </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_REMOVE_ITEMS </MENUITEM_ID>
    </MENU>

    <!-- Personalise Homescreen  -->
    <MENU id="MENU_ID_OP11_HS_PERSONALISATION" str="STR_ID_OP11_HS_PERSONALISE_HS">
        <MENUITEM_ID> MENU_ID_OP11_HS_SWITCH_VIEWS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_EDIT_HS_ITEM </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_SET_WP_PANELS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_EDIT_WP_PANELS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_MORE_SETTINGS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_HELP </MENUITEM_ID>
    </MENU>


    <!-- Options -->
    <MENU id="MENU_ID_OP11_HS_OPTIONS" str="STR_GLOBAL_OPTIONS" img="NULL" >
        <MENUITEM_ID> MENU_ID_OP11_HS_CONTEXT_ITEM </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_REORDER_SHCTS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_ATTACH_WP </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_DETACH_WP </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_SWITCH_VIEWS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_EDIT_HS_ITEM </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_MORE_SETTINGS </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_HELP </MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_OP11_HS_CLOCK_SIZE" str="STR_ID_OP11_HS_CLK_SIZE" flag="RADIO" >
        <MENUITEM_ID> MENU_ID_OP11_HS_CLOCK_SIZE_SMALL </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_CLOCK_SIZE_LARGE </MENUITEM_ID>
    </MENU> 

    <MENU id="MENU_ID_OP11_HS_DUAL_CLOCK" str="STR_ID_OP11_HS_DUAL_CLK" flag="RADIO" >
        <MENUITEM_ID> MENU_ID_OP11_HS_DUAL_CLOCK_OFF </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_DUAL_CLOCK_ON </MENUITEM_ID>
    </MENU> 

    <MENU id="MENU_ID_OP11_HS_KEYPAD_SEARCH" str="STR_ID_OP11_HS_KEYPAD_SEARCH" flag="RADIO" >
        <MENUITEM_ID> MENU_ID_OP11_HS_KEYPAD_SEARCH_ON </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_KEYPAD_SEARCH_OFF</MENUITEM_ID>
    </MENU> 


    <!-- VIP option menu - US  -->

    <MENUITEM id="MENU_ID_OP11_HS_VIP_SEND_MES"  str="STR_ID_OP11_HS32_US_VIP_SEND_MES"   highlight="mmi_op11_hs32_hilight_us_vip_send_mes" img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_VIP_MAKE_CALL" str="STR_ID_OP11_HS32_US_VIP_MAKE_CALL"  highlight="mmi_op11_hs32_hilight_us_vip_make_call" img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_VIP_SWITCH"    str="STR_ID_OP11_HS32_US_VIP_SWITCH"     highlight="mmi_op11_hs32_hilight_us_vip_switch" img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_VIP_REMOVE"    str="STR_ID_OP11_HS32_US_VIP_REMOVE_CON" highlight="mmi_op11_hs32_hilight_us_vip_remove"  img="0"/>
    <MENUITEM id="MENU_ID_OP11_HS_VIP_CONTACT"   str="STR_ID_OP11_HS32_US_VIP_CONTACT"    highlight="mmi_op11_hs32_hilight_us_vip_contact" img="0"/>

    <!-- US VIP option menu -->
    <MENU id="MENU_ID_OP11_HS_VIP_OPTION" str="NULL" img="NULL" >
        <MENUITEM_ID> MENU_ID_OP11_HS_VIP_SEND_MES </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_VIP_MAKE_CALL </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_VIP_SWITCH </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_VIP_REMOVE </MENUITEM_ID>
        <MENUITEM_ID> MENU_ID_OP11_HS_VIP_CONTACT </MENUITEM_ID>
    </MENU>
    

    <!-----------------NVRAM Cache data Resource-------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_OP11_HS32_CLOCK_SIZE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Clock Size </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_OP11_HS32_HISTORY_CHANGED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> History Changed </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_OP11_HS32_SHCT_PHB_CHANGED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Shct Phb Changed </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_OP11_HS32_SHCT_EML_CHANGED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Shct Eml Changed </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_OP11_HS32_VIEW_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> HS view mode </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_WLAN_FEATURES__
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_ACTIVE" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CONNECTED" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INACTIVE" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_SCAN" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CONNECT" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND" proc="mmi_op11_hs32_cnx_wifi_update"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO" proc="mmi_op11_hs32_cnx_wifi_update"/>
#endif

</APP>


#endif    /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif /*  0  */

