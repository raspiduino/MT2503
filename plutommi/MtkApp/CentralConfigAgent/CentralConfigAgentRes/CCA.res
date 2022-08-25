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
 *  CCA.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA resource file.
 *
 * Author:
 * -------
 *  Jianhua Zhao (mtk80037)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 sushil.sagar
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * Pluto slim check in.
 *
 * 05 15 2012 jianhua.zhao
 * [MAUI_03184353] [1] Fatal Error (0xe01, 0xe59f) - MMI
 * .
 *
 * 05 09 2012 jianhua.zhao
 * [MAUI_03178649] the title of the settings msg in the N-centre should not be new settings
 * .
 *
 * 09 23 2011 yixiong.zhao
 * [MAUI_03021997] MMI Feature Option Revise
 * .
 *
 * 07 22 2011 kefeng.lian
 * [MAUI_02990003] [CCA][Slim]Remove unused IMG_ID_CCA_NEW_SETTING
 * .
 *
 * 03 02 2011 kefeng.lian
 * [MAUI_02654414] [CCA] Revise code
 * .
 *
 * 01 25 2011 kefeng.lian
 * [MAUI_02649889] [CCA] CCA Revise head file stage 3
 * Rollback //MAUI/TRUNK/MAUI/mcu/plutommi/MtkApp/CentralConfigAgent to changelist 196011
 *
 * 01 21 2011 kefeng.lian
 * [MAUI_02649595] [CCA] Head file revise stage 2 - restore it
 * .
 *
 * 01 19 2011 kefeng.lian
 * [MAUI_02649275] [CCA] remove plutommi CcaApp from COSMOS stage 1
 * .
 *
 * 01 10 2011 kefeng.lian
 * [MAUI_02647517] Unused string removal
 * .
 *
 * 12 14 2010 kefeng.lian
 * [MAUI_02643203] [CCA] Sync Gemini+ to 10A and MAUI
 * .
 *
 * 12 07 2010 kefeng.lian
 * [MAUI_02643203] [CCA] Sync Gemini+ to 10A and MAUI
 * .
 *
 * 09 14 2010 kefeng.lian
 * [MAUI_02635470] [CCA] CCA revise stage 2
 * .
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



 /***************************************************************************** 
  * Include 
  *****************************************************************************/
  
/*!---- 20 char --!------------------------------ total 81 char ---------------*/

#include "MMI_features.h"


/* Add new compile option to MMI_Features.h */

#ifdef __MMI_CCA_SUPPORT__

#include "CustResDef.h"

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_CCA">

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>


<!----------------- Common Area ----------------------------------------------->

<!----------------- String Id ----------------------------------------->             
    <STRING id= "STR_ID_CCA_SETTINGS_MESSAGE"/>
    <STRING id = "STR_ID_CCA_PROGRESS_CONTENT">Configuring system, please wait</STRING>
    <STRING id = "STR_ID_CCA_PREINFO_CONTENT">Settings for:</STRING>
    <STRING id = "STR_ID_CCA_POSTINFO_TITLE">Summary report</STRING>
    <STRING id = "STR_ID_CCA_AUTH_CONTENT">Please input PIN</STRING>

    <STRING id = "STR_ID_CCA_CONFIGURED">Configured</STRING>
    <STRING id = "STR_ID_CCA_INVALID_SETTING">Invalid settings</STRING>
    <STRING id = "STR_ID_CCA_SETTING_SKIPPED">Skipped</STRING>
    <STRING id = "STR_ID_CCA_CORRUPTED_SETTING">Corrupted settings</STRING>
    <STRING id = "STR_ID_CCA_MISSING_DATA">Incomplete settings</STRING>

    <STRING id = "STR_ID_CCA_INSTALL_SETTING">Install settings</STRING>
    <STRING id = "STR_ID_CCA_REPLACE_SETTING">Replace settings</STRING>
    <STRING id = "STR_ID_CCA_SKIP_PROFILE">Skip this profile?</STRING>
    <STRING id = "STR_ID_CCA_PROFILE_IN_USE">Profile in use</STRING>
    <STRING id = "STR_ID_CCA_SKIP">Skip</STRING>
    <STRING id = "STR_ID_CCA_ABORT_ASK">Cancel?</STRING>

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    <STRING id = "STR_ID_CCA_UPDATE_PROFILE">Update existing profile</STRING>
#endif

    <STRING id = "STR_ID_CCA_UPDATED">Updated</STRING>
    <STRING id = "STR_ID_CCA_FAILED">Failed</STRING>


    <STRING id = "STR_ID_CCA_PROFILE">Profile</STRING>
    <STRING id = "STR_ID_CCA_NEW_SETTING">New settings</STRING> 
    <STRING id = "STR_ID_CCA_SETTING_INFO">Settings info</STRING>

    <STRING id = "STR_ID_CCA_PIN_RETRY">Incorrect PIN, please try again</STRING>
    <STRING id = "STR_ID_CCA_PIN_EMPTY">Please input PIN</STRING>

    <STRING id = "STR_ID_CCA_DATA_ACCOUNT_WITH_COLON">Data account:</STRING>

#ifdef __MMI_EMAIL_OTAP__
    <STRING id = "STR_ID_CCA_EMAIL_WITH_COLON">Email:</STRING>
#endif 

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    <STRING id = "STR_ID_CCA_WLAN">Wireless LAN</STRING>
    <STRING id = "STR_ID_CCA_WLAN_WITH_COLON">Wireless LAN:</STRING>
#endif /* __MMI_WLAN_OTAP_OMAEXT__ || __MMI_WLAN_OTAP_DMP__ */

#ifdef BROWSER_SUPPORT
    <STRING id = "STR_ID_CCA_BROWSER">Browser</STRING>
    <STRING id = "STR_ID_CCA_BROWSER_WITH_COLON">Browser:</STRING>
#endif /* BROWSER_SUPPORT */

#ifdef MMS_SUPPORT
    <STRING id = "STR_ID_CCA_MMS">MMS</STRING>
    <STRING id = "STR_ID_CCA_MMS_WITH_COLON">MMS:</STRING>
#endif /* MMS_SUPPORT */

#ifdef __MMI_VOIP_OTAP_DMP__
    <STRING id = "STR_ID_CCA_SIP">VoIP</STRING>
    <STRING id = "STR_ID_CCA_SIP_WITH_COLON">VoIP:</STRING>
#endif /* __MMI_VOIP_OTAP_DMP__*/

#ifdef __MMI_IMPS_OTA__
    <STRING id = "STR_ID_CCA_IMPS">Instant message</STRING>
    <STRING id = "STR_ID_CCA_IMPS_WITH_COLON">Instant message:</STRING>
#endif /* __MMI_IMPS_OTA__ */ 

#ifdef __MMI_SYNCML_CCA_SUPPORT__
    <STRING id = "STR_ID_CCA_SYNCMLDS">Synchronization</STRING>
    <STRING id = "STR_ID_CCA_SYNCMLDS_WITH_COLON">Synchronization:</STRING>
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */ 

#ifdef SYNCML_DM_SUPPORT
    <STRING id = "STR_ID_CCA_SYNCMLDM">Device management</STRING>
    <STRING id = "STR_ID_CCA_SYNCMLDM_WITH_COLON">Device management:</STRING>
#endif /* SYNCML_DM_SUPPORT */ 

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
    <STRING id = "STR_ID_CCA_PUSH">Service message</STRING>
    <STRING id = "STR_ID_CCA_PUSH_WITH_COLON">Service message:</STRING>
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */ 

#ifdef __MMI_STREAMING_OTAP__
    <STRING id = "STR_ID_CCA_RTSP">Streaming</STRING>
    <STRING id = "STR_ID_CCA_RTSP_WITH_COLON">Streaming:</STRING>
#endif /* __MMI_STREAMING_OTAP__ */ 

#ifdef __MMI_AGPS_OTAP__
    <STRING id = "STR_ID_CCA_SUPL">AGPS</STRING>
    <STRING id = "STR_ID_CCA_SUPL_WITH_COLON">AGPS:</STRING>
#endif /* __MMI_AGPS_OTAP__ */ 


    <STRING id = "STR_ID_CCA_NOAPP">Unsupported settings</STRING>
    <STRING id = "STR_ID_CCA_AUTH_FAILED">Authentication failed</STRING>

#ifdef __MMI_DUAL_SIM__
    <STRING id = "STR_ID_CCA_NEW_SIM1_SETTING">New SIM1 settings</STRING>
    <STRING id = "STR_ID_CCA_NEW_SIM2_SETTING">New SIM2 settings</STRING>
#endif /* __MMI_DUAL_SIM__ */

#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3))
    <STRING id = "STR_ID_CCA_NEW_SIM3_SETTING">New SIM3 settings</STRING>
#endif

#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4))
    <STRING id = "STR_ID_CCA_NEW_SIM4_SETTING">New SIM4 settings</STRING>
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__ 
    <STRING id = "STR_ID_CCA_GET_MSG_FAILED">Failed to get settings</STRING>
    <STRING id = "STR_ID_CCA_UPDATE_MSG_FAILED">Failed to update settings</STRING>
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
    <STRING id = "STR_ID_CCA_INSTALLING_RETRY">Installing</STRING>

<!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "SCR_ID_CCA_PRE_INFO"/>
    <SCREEN id = "SCR_ID_CCA_PROGRESS"/>
    <SCREEN id = "SCR_ID_CCA_POST_INFO"/>
    <SCREEN id = "SCR_ID_CCA_NEW_SETTING_CONF"/>
    <SCREEN id = "SCR_ID_CCA_AUTH"/>
    <SCREEN id = "GRP_ID_CCA"/>


<!----------------- Image Id ------------------------------------------->

    <IMAGE id = "IMG_ID_CCA_MAIN_ICON"> CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_CCA.png"</IMAGE>

    /* Normal project*/
#ifndef __LOW_COST_SUPPORT_COMMON__
   
        /* New settings idle notification image*/
    #if defined(__MMI_SLIM_PROGRESS_ANIMATION__) && defined(__OPTR_NONE__)
        <IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE">CUST_IMG_PATH"\\\\MainLCD\\\\CCA\\\\New_settings_Idle"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
    	
    #else /* __MMI_SLIM_PROGRESS_ANIMATION__ */
        #ifdef __MMI_MAINLCD_320X480__
        	<IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE"> CUST_IMG_PATH"\\\\MainLCD\\\\CCA\\\\New_settings_Idle.png"</IMAGE>
        #else
            <IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE"> CUST_IMG_PATH"\\\\MainLCD\\\\CCA\\\\New_settings_Idle.gif"</IMAGE>
        #endif
    #endif /* __MMI_SLIM_PROGRESS_ANIMATION__ */

#else /* __LOW_COST_SUPPORT_COMMON__*/

    #ifdef __MMI_SLIM_IMG_RES__
    	<IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE">CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_ICOM.gif"</IMAGE>
    #else /* __MMI_SLIM_IMG_RES__*/
        #ifdef __MMI_SLIM_PROGRESS_ANIMATION__
        
        	<IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
        
        #else /* __MMI_SLIM_PROGRESS_ANIMATION__*/
        
        	<IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE">CUST_IMG_PATH"\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_IdleMSG.GIF"</IMAGE>
        
        #endif /* __MMI_SLIM_PROGRESS_ANIMATION__*/
    #endif /* __MMI_SLIM_IMG_RES__*/

#endif /* __LOW_COST_SUPPORT_COMMON__*/

<TIMER id = "TIMER_ID_CCA_NMGR_POPUP"/>

<!----------------- XML END --------------------------------------------------->


</APP>

#endif /* __MMI_CCA_SUPPORT__ */






