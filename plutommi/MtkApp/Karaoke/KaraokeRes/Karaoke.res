/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#ifdef __MMI_KARAOKE__

#include "CustResDef.h"
#include "custom_mmi_default_value.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_KARAOKE"
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name = "native.mtk.karaoke"
    name = "STR_ID_KARAOKE_TITLE"
    launch = "mmi_karaoke_launch"
    #endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
	<INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
	<STRING id="STR_ID_KARAOKE_NAME"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_TITLE"/>
	<STRING id="STR_ID_KARAOKE_RECORD_LIST_TITLE"/>
	
	<STRING id="STR_ID_KARAOKE_RETRY_ASK"/>
	<STRING id="STR_ID_KARAOKE_FINISH_ASK"/>
	<STRING id="STR_ID_KARAOKE_RETRY"/>
	<STRING id="STR_ID_KARAOKE_FINISH"/>
	<STRING id="STR_ID_KARAOKE_ORIGIN"/>
	<STRING id="STR_ID_KARAOKE_NO_ORIGIN"/>
	<STRING id="STR_ID_KARAOKE_DISCARD_RECORD"/>
	<STRING id="STR_ID_KARAOKE_DISCARD_RECORD_ASK"/>
	<STRING id="STR_ID_KARAOKE_SAVE_RECORD"/>
	<STRING id="STR_ID_KARAOKE_NO_LYRICS_FILE"/>
	<STRING id="STR_ID_KARAOKE_EARPHONE"/>
	<STRING id="STR_ID_KARAOKE_LINEIN_MIC"/>
	
	<STRING id="STR_ID_KARAOKE_SONG_ADDED"/>
	
	<STRING id="STR_ID_KARAOKE_ERR_DATA_LYRICS_FILE"/>
	<STRING id="STR_ID_KARAOKE_ERR_OPEN_LYRICS_FILE"/>
	<STRING id="STR_ID_KARAOKE_ERR_DISC_FULL"/>
	<STRING id="STR_ID_KARAOKE_ERR_WRITE_DATA_FAIL"/>
	<STRING id="STR_ID_KARAOKE_ERR_SING_FAIL"/>
	<STRING id="STR_ID_KARAOKE_ERR_PLAY_RECORD_FAIL"/>
    
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_SING"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_UPDATE"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_ADD"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL"/>
	
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_MANUAL_ADD"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_AUTO_ADD"/>
	
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ASK"/>
	<STRING id="STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL_ASK"/>
	
	<STRING id="STR_ID_KARAOKE_RECORD_LIST_OPTION_DELETE"/>
	#ifdef __MMI_TELEPHONY_SUPPORT__
	<STRING id="STR_ID_KARAOKE_RECORD_LIST_OPTION_USE_AS"/>
	#endif  //__MMI_TELEPHONY_SUPPORT__
	<STRING id="STR_ID_KARAOKE_RECORD_LIST_OPTION_SEND"/>
	
	<STRING id="STR_ID_KARAOKE_ERR_WRITE_FAILED"/>
	<STRING id="STR_ID_KARAOKE_ERR_READ_FAILED"/>
	<STRING id="STR_ID_KARAOKE_ERR_LIST_FULL"/>
	<STRING id="STR_ID_KARAOKE_ERR_WRONG_VERSION"/>
	<STRING id="STR_ID_KARAOKE_ERR_CREATE_FAILED"/>
	<STRING id="STR_ID_KARAOKE_ERR_DAMAGED"/>
	<STRING id="STR_ID_KARAOKE_ERR_OPEN_FAILED"/>
	<STRING id="STR_ID_KARAOKE_ERR_UNKNOWN_ERROR"/>
	<STRING id="STR_ID_KARAOKE_FILE_IN_DIFFERENT_STORAGE"/>
	<STRING id="STR_ID_KARAOKE_CANNOT_UPDATE_LIST_FS_FAIL"/>
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->
    <!--End Image Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <IMAGE id="IMG_ID_KARAOKE_PLAY_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\Audioplayer_ANI.gif"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_FILE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\Title.9slice.png"</IMAGE>
	
    /* Duration*/
    <IMAGE id="IMG_ID_KARAOKE_PROGRESS_BAR_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_fg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_PROGRESS_BAR_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_KARAOKE_PLAY_REC_PREV" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_PLAY_REC_NEXT" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_PLAY_REC_FG_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>
    
    /*Volume Related*/
    <IMAGE id="IMG_ID_KARAOKE_VOL_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_BGbar.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_FG" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_BGbar_Adjust.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_MIC" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_Mic.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_MIC_MUTE" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_Mic_Mute.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_SEL" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_Sel.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_UNSEL" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_unSel.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_SPK" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_SPK.png"</IMAGE>
    <IMAGE id="IMG_ID_KARAOKE_VOL_SPK_MUTE" >CUST_IMG_PATH"\\\\MainLCD\\\\Karaoke\\\\Karaoke_Setting_SPK_Mute.png"</IMAGE>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_SING" str="STR_ID_KARAOKE_SONG_LIST_OPTION_SING"/>
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_UPDATE" str="STR_ID_KARAOKE_SONG_LIST_OPTION_UPDATE"/>
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_ADD" str="STR_ID_KARAOKE_SONG_LIST_OPTION_ADD"/>
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE" str="STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE"/>
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL" str="STR_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL"/>
    
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_MANUAL_ADD" str="STR_ID_KARAOKE_SONG_LIST_OPTION_MANUAL_ADD"/>
    <MENUITEM id="MENU_ID_KARAOKE_SONG_LIST_OPTION_AUTO_ADD" str="STR_ID_KARAOKE_SONG_LIST_OPTION_AUTO_ADD"/>
    
    <MENUITEM id="MENU_ID_KARAOKE_RECORD_LIST_OPTION_PLAY" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_KARAOKE_RECORD_LIST_OPTION_DELETE" str="STR_ID_KARAOKE_RECORD_LIST_OPTION_DELETE"/>
    #ifdef __MMI_TELEPHONY_SUPPORT__
    <MENUITEM id="MENU_ID_KARAOKE_RECORD_LIST_OPTION_USE_AS" str="STR_ID_KARAOKE_RECORD_LIST_OPTION_USE_AS"/>
    #endif  //__MMI_TELEPHONY_SUPPORT__
    <MENUITEM id="MENU_ID_KARAOKE_RECORD_LIST_OPTION_SEND" str="STR_ID_KARAOKE_RECORD_LIST_OPTION_SEND"/>

    <MENUITEM id="MENU_ID_KARAOKE_OPTION_ORIGIN" str="STR_ID_KARAOKE_ORIGIN"/>
    <MENUITEM id="MENU_ID_KARAOKE_OPTION_NO_ORIGIN" str="STR_ID_KARAOKE_NO_ORIGIN"/>
    <MENUITEM id="MENU_ID_KARAOKE_OPTION_RETRY" str="STR_ID_KARAOKE_RETRY"/>
    #ifdef __LINE_IN_SUPPORT__
    <MENUITEM id="MENU_ID_KARAOKE_OPTION_EARPHONE" str="STR_ID_KARAOKE_EARPHONE"/>
    <MENUITEM id="MENU_ID_KARAOKE_OPTION_LINEIN_MIC" str="STR_ID_KARAOKE_LINEIN_MIC"/>
    #endif
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    

    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Tree Area-->
    <MENU id="KARAOKE_SONG_LIST_MENUID" parent="MAIN_MENU_KARAOKE_MENUID" str="STR_ID_KARAOKE_SONG_LIST_TITLE" img="IMG_GLOBAL_L1" highlight="HighlightKaraokeSongList"
    shortcut="ON" launch="mmi_karaoke_song_list_entry_main"/>
    
    <MENU id="MENU_ID_KARAOKE_SONG_LIST_OPTION_MENU" parent="0" type="OPTION" str="STR_GLOBAL_OPTIONS">
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_SING</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_UPDATE</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_ADD</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_REMOVE_ALL</MENUITEM_ID>
    	
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_MANUAL_ADD</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_SONG_LIST_OPTION_AUTO_ADD</MENUITEM_ID>
    </MENU>

    
    <MENU id="KARAOKE_RECORD_LIST_MENUID" parent="MAIN_MENU_KARAOKE_MENUID" str="STR_ID_KARAOKE_RECORD_LIST_TITLE" img="IMG_GLOBAL_L2" highlight="HighlightKaraokeRecordList"
    shortcut="ON" launch="mmi_karaoke_record_list_entry_main"/>
    
    <MENU id="MENU_ID_KARAOKE_RECORD_LIST_OPTION_MENU" parent="0" type="OPTION" str="STR_GLOBAL_OPTIONS">
    	<MENUITEM_ID>MENU_ID_KARAOKE_RECORD_LIST_OPTION_PLAY</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_RECORD_LIST_OPTION_DELETE</MENUITEM_ID>
    	#ifdef __MMI_TELEPHONY_SUPPORT__
    	<MENUITEM_ID>MENU_ID_KARAOKE_RECORD_LIST_OPTION_USE_AS</MENUITEM_ID>
    	#endif  //__MMI_TELEPHONY_SUPPORT__
    	<MENUITEM_ID>MENU_ID_KARAOKE_RECORD_LIST_OPTION_SEND</MENUITEM_ID>
    </MENU>    
    
    <MENU id="MENU_ID_KARAOKE_SING_OPTION_MENU" parent="MENU_ID_KARAOKE_SING_OPTION_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">
    	<MENUITEM_ID>MENU_ID_KARAOKE_OPTION_ORIGIN</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_OPTION_NO_ORIGIN</MENUITEM_ID>
    	#ifdef __LINE_IN_SUPPORT__
    	<MENUITEM_ID>MENU_ID_KARAOKE_OPTION_EARPHONE</MENUITEM_ID>
    	<MENUITEM_ID>MENU_ID_KARAOKE_OPTION_LINEIN_MIC</MENUITEM_ID>
    	#endif
    	<MENUITEM_ID>MENU_ID_KARAOKE_OPTION_RETRY</MENUITEM_ID>
    </MENU>  
    
	<!--End Menu Tree Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
	<SCREEN id="GRP_ID_KARAOKE"/>
	<SCREEN id="GRP_ID_KARAOKE_SONG_LIST"/>
	<SCREEN id="GRP_ID_KARAOKE_RECORD_LIST"/>
	<SCREEN id="GRP_ID_KARAOKE_LIST_OPTION"/>
	<SCREEN id="GRP_ID_KARAOKE_SONG_LIST_ADD"/>
	<SCREEN id="GRP_ID_KARAOKE_WAITSCREEN"/>
	<SCREEN id="GRP_ID_KARAOKE_REMOVE_WAITSCREEN"/>
	<SCREEN id="GRP_ID_KARAOKE_SING"/>
	<SCREEN id="GRP_ID_KARAOKE_PLAY_RECORD"/>
	<SCREEN id="GPR_ID_KARAOKE_VOLUME"/>
	
	<SCREEN id="SCR_ID_KARAOKE_MAIN"/>
	<SCREEN id="SCR_ID_KARAOKE_SONG_LIST"/>
	<SCREEN id="SCR_ID_KARAOKE_RECORD_LIST"/>
	<SCREEN id="SCR_ID_KARAOKE_WAITSCREEN"/>
	<SCREEN id="SCR_ID_KARAOKE_REMOVE_WAITSCREEN"/>
	<SCREEN id="SCR_ID_KARAOKE_SING"/>
	<SCREEN id="SCR_ID_KARAOKE_PLAY_RECORD"/>
	<SCREEN id="SCR_ID_KARAOKE_VOLUME"/>
    <!--End Screen ID Area-->
	<!--------------------------------------------------------------------------------------------------------------------->
        

	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Timer ID -->
    <TIMER id="KARAOKE_PROCESS_ADD_FILE_TIMER"/>
    <TIMER id="KARAOKE_DELAY_PLAY_TIMER"/>
    <TIMER id="KARAOKE_VOLUME_ADJUST_TIMER"/>
	<!--End Timer ID -->
	<!--------------------------------------------------------------------------------------------------------------------->

    
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Receiving Evt ID -->
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_karaoke_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_karaoke_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_karaoke_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_karaoke_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_karaoke_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_karaoke_notify_hdlr"/>
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_karaoke_usb_plug_in_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_karaoke_usb_plug_out_hdlr"/>
    #if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
    <RECEIVER id="EVT_ID_SRV_A2DP_CONNECT" proc="mmi_karaoke_notify_hdlr"/>
    #endif  //defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
	<!--End Receiving Evt ID -->
	<!--------------------------------------------------------------------------------------------------------------------->

    
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Sending Evt ID -->
	<!--End Sending Evt ID -->
	<!--------------------------------------------------------------------------------------------------------------------->
	
	
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--NVRAM LID -->
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X0C] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke volume</DESCRIPTION>
    </CACHEDATA>
  
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_AUD_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X0C] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke aud volume</DESCRIPTION>
  </CACHEDATA>
  
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_MIC_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X0C] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke mic volume</DESCRIPTION>
  </CACHEDATA>
    
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_REMIX_AUD_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X0C] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke remix aud volume</DESCRIPTION>
  </CACHEDATA>
  
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_REMIX_MIC_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X0C] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke remix mic volume</DESCRIPTION>
  </CACHEDATA>
    
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_FOCUS_AUD" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke focus on aud</DESCRIPTION>
  </CACHEDATA>
  
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_AUD_MUTE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke focus on aud</DESCRIPTION>
  </CACHEDATA>
  
  <CACHEDATA type="byte" id="NVRAM_KARAOKE_MIC_MUTE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION>Karaoke focus on aud</DESCRIPTION>
  </CACHEDATA>
	<!--End NVRAM LID -->
	<!--------------------------------------------------------------------------------------------------------------------->
</APP>

#endif  //__MMI_KARAOKE__

