#include "mmi_features.h"
#include "CustResDef.h"         /* for image/audio path */
#include "custom_mmi_default_value.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
<APP id="APP_AUDIO_PLAYER_BT">

   <INCLUDE file="GlobalResDef.h"/>

  <STRING id="STR_ID_BT_MUSIC_TITLE"/>
  <STRING id="STR_ID_BT_MUSIC_CONN_FAILED"/>
  <STRING id="STR_ID_BT_MUSIC_DISCONNECT_CONFIRM"/>
  <STRING id="STR_ID_BT_MUSIC_DISCONNECTING"/>
  <STRING id="STR_ID_BT_MUSIC_UNSUPPORT"/>
  <STRING id="STR_ID_OPTION_LOCAL_MUSIC"/>
	<STRING id="STR_ID_BT_MUSIC_NO_CONN"/>


	#ifdef __MMI_FTE_SUPPORT__
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_STOP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\button.png"</IMAGE>
	<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_HIGHLIGHT_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>
	
#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\Audioplayer_ANI.gif"</IMAGE>
#endif
#if !defined(__MMI_MAINLCD_320X240__)
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\BG.9slice.png"</IMAGE>
#else
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\AUDIO_BG.png"</IMAGE>
#endif
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\Title.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_PROGRESS">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_bg.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\Button_BG.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_FG_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_FG_DISABLE">CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_FG_DISABLE">CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_FG_DISABLE">CUST_IMG_PATH"\\\\EmptyImage.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_VOLUME_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_fg.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PROGRESSBAR">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_fg.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PROGRESSBAR_FAIL">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\MPLAYER_progress_bg_disable.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_0.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_1.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_2.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_3.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_4.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_5.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_6.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_7.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_8.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_9.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUMC">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_col.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_VOLUME_SPEAK_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_on_up.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_VOLUME_SPEAK_MUTE_BUTTON_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_off_up.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_OPTION_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_OPTION_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option_down.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BACK_UP" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BACK_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back_down.png"</IMAGE>
#else /*__MMI_FTE_SUPPORT__*/	
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\play.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_STOP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\button.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_HIGHLIGHT_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\highlight.9slice.png"</IMAGE>	
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\title.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_PROGRESS">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\progress_bg.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\vol_none.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_BG_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\button.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_FG_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\highlight.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_FG_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\disable.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_VOLUME_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\vol_full.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PROGRESSBAR">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\progress_fill.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_PROGRESSBAR_FAIL">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\progress_fail.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\0.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\1.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\2.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\3.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\4.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\5.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\6.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\7.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\8.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUM9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\9.bmp"</IMAGE>
<IMAGE id="IMG_ID_BT_MUSIC_MAIN_SKIN1_NUMC">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\col.bmp"</IMAGE>
#endif /*__MMI_FTE_SUPPORT__*/
	
<!--Menu Tree Area-->
#ifdef __MMI_AUDIO_PLAYER_BT__
<!--Menu Item Area-->
<MENUITEM id="MENU_ID_AUDPLY_OPTION_LOCAL_MUSIC" str="STR_ID_OPTION_LOCAL_MUSIC"/>
<MENU id="MENU_ID_AUDPLY_BT_OPTION_CUI" type="APP_SUB" str="STR_GLOBAL_OPTIONS">
<MENUITEM_ID>MENU_ID_AUDPLY_OPTION_LOCAL_MUSIC</MENUITEM_ID>
</MENU>
#endif


/* please add all screen IDs below this line */
#ifdef __MMI_AUDIO_PLAYER_BT__
<SCREEN id="GRP_ID_AUDPLY_OPTION_TO_LOCAL"/>
#endif
<SCREEN id="GRP_ID_BT_MUSIC_APP"/>
<SCREEN id="SCR_ID_BT_MUSIC_APP"/>
<SCREEN id="SCR_ID_BT_MUSIC_DEVICE_LIST"/>
<SCREEN id="SCR_ID_BT_MUSIC_CONN_SCREEN"/>
<SCREEN id="SCR_ID_BT_MUSIC_CLOSE_CONFIRM"/>
<SCREEN id="SCR_ID_BT_MUSIC_CLOSE_WAITING"/>
<!----------------------------nvram id begin------------------------------------------------------>
  <CACHEDATA type="byte" id="NVRAM_BT_MUSIC" restore_flag="TRUE">
      <DEFAULT_VALUE> [0X06] </DEFAULT_VALUE>
      <DESCRIPTION>BT Music</DESCRIPTION>
  </CACHEDATA>
  
  <RECEIVER id="EVT_ID_SRV_PROF_IS_PLAYING" proc="mmi_bt_music_profile_evt_hdlr"/>
  <RECEIVER id="EVT_ID_SRV_A2DP_SINK_CONNECT" proc="mmi_bt_music_a2dp_connect_callback_hdlr"/>
  <RECEIVER id="EVT_ID_DIALER_DISCONN_EVENT_ID" proc="mmi_bt_music_dialer_disconn_evt_hdlr"/>
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
  <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_bt_music_scrlocker_event_notify_handler"/>
#endif
<!-----------------Timer begin--------------------------------------------------------------------->
	<TIMER id="BT_MUSIC_SEEKING_TIMER"/>
	<TIMER id="BT_MUSIC_SYNC_POS_TIMER"/>
	<TIMER id="BT_MUSIC_STATUS_ICON_TIMER"/>
	#ifdef __MMI_BTMUSIC_BTBOX_KEYBOARD_STYLE__
	<TIMER id="BT_MUSIC_DISPLAY_BUTTON_TIMER"/>
	#endif
	<TIMER id="BT_MUSIC_STREAM_TIMER"/> 
 	<TIMER id="BT_MUSIC_AVRCP_TRACK_CHANGE_TIMER"/> 
 	<TIMER id="BT_MUSIC_TITLE_DISPLAY_DELAY_TIMER"/>
<!------------------------------------------------------Other Resource------------------------------> 
  
</APP>
#endif //defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
