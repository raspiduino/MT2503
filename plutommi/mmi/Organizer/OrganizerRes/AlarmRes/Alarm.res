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

/*******************************************************************************
 * Filename:
 * ---------
 *   Alarm.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file for alarm app
 *
 * Author:
 * -------
 *   Wen Wu(MTK80153)
 *
 *******************************************************************************/

#include "mmi_features.h"
#include "custresdef.h"
#include "AlarmSlim.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_ALARM" 
#ifdef __MMI_APP_MANAGER_SUPPORT__
    package_name="native.mtk.alarm"
    name="@OID:STR_GLOBAL_ALARM"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON      
    img="MAIN_MENU_ALARM_ICON"
#endif    
    launch="EntryAlmMenu"
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>

    <TIMER id="ALARM_ALERT_NOTIFYDURATION_TIMER"/>
    <TIMER id="ALARM_TIMER_WAIT_FOR_CALL"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="ALARMS_SNOOZE_STRINGID"/>
    <STRING id="ALARM_REPEAT_STRING"/>
    <STRING id="ALARM_ONCE_STRING"/>
   #if 0
    <STRING id="ALARM_HOURLY_STRING"/>
    <STRING id="ALARM_SEASONLY_STRING"/>
    #endif
    <STRING id="ALARM_EVREYDAY_STRING"/>
    <STRING id="ALARM_DAYS_STRING"/>
#if defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)
    <STRING id="ALARM_WEEKLY_STRING"/>
    <STRING id="ALARM_MONTHLY_STRING"/>
    <STRING id="ALARM_YEARLY_STRING"/>
#endif
  #ifdef __MMI_INDICAL__   
    <STRING id="ALARM_TITHI_STRING"/>
  #endif
    <STRING id="ALARMS_POWER_ON"/>
#ifdef __MMI_ALM_CUSTOMIZE_TONE__    
    <STRING id="STR_ID_ALM_AUDIO_OPTIONS"/>
#if 0
    <STRING id="STR_ID_ALM_AUDIO_OPTIONS_TONE"/>
#endif
    <STRING id="STR_ID_ALM_AUDIO_OPTIONS_TONE_FILE_NOT_AVAILABLE"/>
#endif
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    <STRING id="STR_ID_ALM_AUDIO_OPTIONS_FMRADIO"/>
    <STRING id="STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_CHANNELLIST"/>
    <STRING id="STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_MAN_INPUT"/>
    <STRING id="STR_ID_ALM_FMRDO_VALID_FM_BANDWIDTH"/>
    <STRING id="STR_ID_ALM_FMRDO_HEADFONE_REMINDER"/>
    <STRING id="STR_ID_ALM_FMRDO_AUD_OPT_INCOMPLETE_NOTIFY"/>
    <STRING id="STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE"/>
    <STRING id="STR_ID_ALM_FMRDO_INCOMPLETE_CHANNEL_INFO"/>
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */
    <STRING id="ALARMS_SETTING_SNOOZE_INTERVAL"/> 
#ifndef __MMI_DEV_NEW_SLIM__
    <STRING id="STR_ID_ALM_DISABLE_ASK"/> 
#endif
    <STRING id="STR_ID_ALM_NO_MARKED"/> 
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="ALARMS_EDIT_SOFTKEY_IMAGEID" >CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
 #ifndef __MMI_ALARM_SLIM__
    <IMAGE id="ALARM_ANIMATION_INDICATION_IMAGEID">CUST_IMG_PATH"\\\\MAINLCD\\\\Alarm\\\\ALARM.png"</IMAGE>
 #endif 
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON  
    <IMAGE id = "MAIN_MENU_ALARM_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Alarm.png"</IMAGE>
#endif
#endif
#ifndef __MMI_ALARM_SLIM__ 
    <IMAGE id="ORGANIZER_MENU_ALARMS_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Alarm\\\\SB_OAM.bmp"</IMAGE>  
#endif
#ifdef __MMI_ALM_CUST_VOLUME__
    <IMAGE id="ALARM_VOLUME_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\OA_VOLUME.bmp"</IMAGE>
#endif
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#ifndef __MMI_DEV_NEW_SLIM__    
    <IMAGE id="IMG_ALM_AUD_OPT">CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\OA_AUDIO.bmp"</IMAGE>
#endif
#endif
#ifndef __MMI_ALARM_SLIM__
#ifdef __MMI_ALM_ALERT_TYPE__
#ifndef __MMI_SLIM_IMG_RES__
    <IMAGE id="ALARMS_SET_ALERT_TYPE_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Alarm\\\\SB_alert.bmp"</IMAGE>    
#else    
    <IMAGE id="ALARMS_SET_ALERT_TYPE_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\SB_alert.bmp"</IMAGE>
#endif    
#endif
#endif
    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
    <SCREEN id="SCR_ID_ALM_LIST"/>
    <SCREEN id="SCR_ID_ALM_SAVE_CONFIRM"/>
    <SCREEN id="SCR_ID_ALM_INDICATION"/>
    <SCREEN id="SCR_ID_ALM_PWRON_CONFIRM"/>
    <SCREEN id="SCR_ID_ALM_EDITOR"/>
    <SCREEN id="SCR_ID_ALM_AUDIO_OPT_FMRADIO"/>
    <SCREEN id="SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST"/>
    <SCREEN id="SCR_ID_ALM_AUDIO_OPT_FMRDO_CHANNEL_OPT"/>
    <SCREEN id="SCR_ID_ALM_FMRDO_PREV"/>
    <SCREEN id="SCR_ID_ALM_FMRDO_MANUAL_INPUT"/>
    <SCREEN id="SCR_ID_ALM_FMRDO_MANUAL_INPUT_OPT"/>
    <SCREEN id="SCR_ID_ALM_TONE_SETUP"/>
    <SCREEN id="SCR_ID_ALM_TONE_SETUP_EXT_MELODY"/>
    <SCREEN id="SCR_ID_ALM_TONE_SETUP_EXT_MELODY_DRV"/>
    <SCREEN id="SCR_ID_ALM_SETTING"/>
    <SCREEN id="SCR_ID_ALM_CUSTOM_REPEAT_TYPE"/>
    <SCREEN id="SCR_ID_ALM_TOTAL"/>
    <!--Screen Group Id-->
    <SCREEN id="GRP_ID_ALM_LIST"/>
    <SCREEN id="GRP_ID_ALM_IND"/>
    <SCREEN id="GRP_ID_ALM_EDITOR"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_OPTION"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT"/>    
    <SCREEN id="GRP_ID_ALM_AUDIO_FM_CHANNEL_OPTION"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_FM_MAN_OPTION"/>
    <SCREEN id="GRP_ID_ALM_REPEAT_TYPE_MENU"/>
    <SCREEN id="GRP_ID_ALM_TOTAL"/>   
 	<!--Screen ID Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

#ifdef __MMI_ALARM_SLIM__
#ifndef __MMI_MAINLCD_96X64__

    <MENU id="ORGANIZER_ALARM_MENU" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_ORGANIZER_MENUID"
    	  str="STR_GLOBAL_ALARM"
    	  highlight="HighlightAlmMenu"
          shortcut="ON" launch="EntryAlmMenu">

#else

    <MENU id="ORGANIZER_ALARM_MENU" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_ORGANIZER_MENUID"
    	  str="STR_GLOBAL_ALARM"
    	  highlight="HighlightAlmMenu"
          shortcut="ON" launch="AlmPrepareInlineScreen">

#endif
#else

    <MENU id="ORGANIZER_ALARM_MENU" 
    	  type="APP_MAIN" 
    	  parent="MAIN_MENU_ORGANIZER_MENUID"
    	  str="STR_GLOBAL_ALARM"
    	  img="ORGANIZER_MENU_ALARMS_IMAGEID" 
    	  highlight="HighlightAlmMenu"
          shortcut="ON" shortcut_img="ORGANIZER_MENU_ALARMS_IMAGEID" launch="EntryAlmMenu">

#endif
    </MENU>
#if 0
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    <MENU id="MENU_ID_ALM_AUDIO_OPT_FMRADIO" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENU id="MENU_ID_ALM_FMRADIO_CHANNEL_LIST" type="APP_SUB" str="STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_CHANNELLIST">
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH1"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH2"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH3"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH4"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH5"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH6"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH7"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH8"></MENUITEM>
            <MENUITEM id="MENU_ID_ALM_FMRADIO_CH9"></MENUITEM>
        </MENU>
        <MENUITEM id="MENU_ID_ALM_FMRADIO_MANUAL_INPUT" str="STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_MAN_INPUT"></MENUITEM>
    </MENU>  
    
    <MENU id="MENU_ID_ALM_FMRADIO_CHANNEL_LIST_OPTION" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_ALM_FMRADIO_OPTION_SELECT"></MENUITEM>
        <MENUITEM id="MENU_ID_ALM_FMRADIO_OPTION_PREVIEW"></MENUITEM>
    </MENU>
    
    <MENU id="MENU_ID_ALM_FMRADIO_MAN_INPUT_OPTION" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_ALM_FMRADIO_OPTION_DONE"></MENUITEM>
        <MENUITEM id="MENU_ID_ALM_FMRADIO_OPTION_PREVIEW"></MENUITEM>
    </MENU>
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
#endif

#ifndef __ORIGINAL_DOW__
#ifdef __MMI_ALARM_SLIM__
		 <MENU id="MENU_ID_ALM_REPEAT_TYPE_MAIN" type="APP_SUB" str="ALARM_REPEAT_STRING">
		 		<MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_ONCE" str="ALARM_ONCE_STRING"></MENUITEM>
		 		<MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_EVREYDAY" str="ALARM_EVREYDAY_STRING"></MENUITEM>
		 		<MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_DAYS" str="ALARM_DAYS_STRING"></MENUITEM>
		</MENU>
		
		 <MENU id="MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">
		 		<MENUITEM id="MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_ON" str="STR_GLOBAL_ON"></MENUITEM>
		 		<MENUITEM id="MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_OFF" str="STR_GLOBAL_OFF"></MENUITEM>
		 		<MENUITEM id="MENU_ID_ALARM_CUSTOM_OPTIONS_DONE" str="STR_GLOBAL_DONE"></MENUITEM>
		 </MENU>
#else
    <MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_MAIN" str="ALARM_REPEAT_STRING"/>
    <MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU" str="STR_GLOBAL_OPTIONS"/>
#endif
#endif

    <!------------------------------------------------------ event handler ------------------------------------------------------>

	<RECEIVER id="EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED" proc="mmi_alarm_enable_pending_alarm"/>
	<RECEIVER id="EVT_ID_NMGR_PLAY_TONE" proc="mmi_alm_nmgr_evt_tone_handlr"/>
	<RECEIVER id="EVT_ID_NMGR_PLAY_VIB" proc="mmi_alm_nmgr_evt_vib_handlr"/>
	<RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_alm_remdr_notify_hdlr"/>
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#ifndef __MMI_ALARM_SLIM2__
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_alm_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_alm_notify_hdlr"/>	
#endif
#endif
    <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_alm_clam_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_ALM_OP" proc="mmi_alm_srv_alm_op_hdlr"/>
</APP>

