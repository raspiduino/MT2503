/*Needed header files of the compile option in XML files */
#include "mmi_features.h"
#include "CustResDef.h"
<?xml version = "1.0" encoding = "UTF-8"?>

#ifdef __MMI_AZAAN_ALARM__

<APP id="APP_AZAAN_ALARM"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
     package_name = "native.mtk.azaanalarm"            
     name = "STR_ID_AZAAN_ALARM"
	 #if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) // MMI ICON                 
     img = "MAIN_MENU_AZAAN_ICON"            
	 #endif
     launch = "mmi_azaan_entry_main_menu"
#else /*__MMI_APP_MANAGER_SUPPORT__*/
 name="STR_ID_AZAAN_ALARM"
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
 >
	<INCLUDE file="GlobalResDef.h"/>
	<INCLUDE file="mmi_rp_app_mainmenu_def.h"/>
	<INCLUDE file="mmi_rp_app_alarm_def.h"/>

<!--------------------------------------------------------------------------------------------------------------------->
         <!--String Resource Area-->
         <!--String Resource Area-->	
	<STRING id="STR_ID_AZAAN_FAJR"/>
	<STRING id="STR_ID_AZAAN_ZUHR"/>
	<STRING id="STR_ID_AZAAN_ASR"/>
	<STRING id="STR_ID_AZAAN_MAGRIB"/>
	<STRING id="STR_ID_AZAAN_ISHA"/>
	<STRING id="STR_ID_AZAAN_TONE"/>
	<STRING id="STR_ID_AZAAN_ALM_TONE_FILE_NOT_AVAILABLE"/>
        <!--End String Resource Area-->
        <!--End String Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

<!--------------------------------------------------------------------------------------------------------------------->
        <!--Image Resource Area-->
        <!--Image Resource Area-->
#if defined(__MMI_APP_MANAGER_SUPPORT__)
	#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) // MMI ICON
	<IMAGE id = "MAIN_MENU_AZAAN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Azaan_alarm.png"</IMAGE>
	#endif
#endif
	<IMAGE id="IMG_AZAAN_ALM_TONE">CUST_IMG_PATH"\\\\MainLCD\\\\Alarm\\\\OA_AUDIO.bmp"</IMAGE>
	<IMAGE id="ORGANIZER_MENU_AZAAN_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Alarm\\\\Azaan_alarm.bmp"</IMAGE>
	
			  <!--End Image Resource Area-->
        <!--End Image Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

	
<!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Menu Resource Area-->
        <!--Menu Menu Resource Area-->

	<MENU id="MENU_ID_AZAAN_ALARM" parent="MAIN_MENU_ORGANIZER_MENUID" str="STR_ID_AZAAN_ALARM" img="@OID:ORGANIZER_MENU_AZAAN_IMAGEID" highlight="mmi_azaan_highlight_azaan_alarm" shortcut="ON" shortcut_img="ORGANIZER_MENU_AZAAN_IMAGEID" launch="mmi_azaan_entry_main_menu">
	</MENU>
				
				<!--End Menu Resource Area-->
        <!--End Menu Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

<!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->	

	<SCREEN id="SCR_ID_AZAAN_LIST"/>
	<SCREEN id="SCR_ID_AZAAN_EDITOR"/>
	<SCREEN id="SCR_ID_AZAAN_TONE_SETUP"/>
	<SCREEN id="SCR_ID_AZAAN_TONE_SETUP_EXT_MELODY"/>
	<SCREEN id="SCR_ID_AZAAN_ALM_INDICATION"/>
		<!--Screen Group ID-->
	<SCREEN id="GRP_ID_AZAAN_IND"/>
	
				<!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->
	<RECEIVER id="EVT_ID_NMGR_PLAY_TONE" proc="mmi_azaan_nmgr_evt_tone_handlr"/>
	<RECEIVER id="EVT_ID_NMGR_PLAY_VIB" proc="mmi_azaan_play_vib"/>
	<RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_azaan_alm_init_cb_hdlr"/>
   	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_azaan_tone_notify_hdlr"/>
</APP>

#endif /* __MMI_AZAAN_ALARM__ */
