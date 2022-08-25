/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#ifdef __MMI_AUDPLY_WALK_PLAY__
#include "CustResDef.h"         /* for image/audio path */
#include "custom_mmi_default_value.h"
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_AUDIOPLAYER">

    <INCLUDE file="GlobalResDef.h"/>
    
	<STRING id="STR_ID_AUDPLY_SETTINGS_PLAY_STYLE"/>
	<STRING id="STR_ID_AUDPLY_SETTINGS_PLAY_BY_FILE_ORDER"/>
	<STRING id="STR_ID_AUDPLY_SETTINGS_PLAY_BY_PLAYLIST"/>
	<STRING id="STR_ID_AUDPLY_ERR_NO_AUDIO_FILE"/>
	<STRING id="STR_ID_AUDPLY_FIRST_HINT"/>
	<STRING id="STR_ID_AUDPLY_LAST_HINT"/>
	<STRING id="STR_ID_AUDPLY_STACK_CORRECT"/>
	
    <CACHEDATA type="byte" id="NVRAM_AUDPLY_PLAY_STYLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Audio player play style </DESCRIPTION>
    </CACHEDATA>

    <RECEIVER id="EVT_ID_SRV_STACK_STATUS_READY" proc="mmi_auddply_play_event_callback_hdlr"/> 
    <RECEIVER id="EVT_ID_PLC_WORK_FINISH" proc="mmi_auddply_cache_work_event_hdlr"/> 
    
    <TIMER id="AUDIO_PLAYER_DO_CACHE_TIMER"/>
    
#ifdef __MMI_BTBOX_NOLCD__
    <CACHEDATA type="byte" id="NVRAM_AUDPLY_VOLUME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x05] </DEFAULT_VALUE>
        <DESCRIPTION> Audio player - volume </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_AUDPLY_ENABLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Audio Player Enable or not</DESCRIPTION>
    </CACHEDATA>

    <SCREEN id="GRP_ID_AUDPLY_MAIN"/>
    <SCREEN id="SCR_ID_AUDPLY_MAIN"/>
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_audply_btbox_msdc_plug_out_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_audply_btbox_msdc_plug_in_hdlr"/>
    
    <TIMER id="AUDIO_PLAYER_KARAOKE_SWITCH_TIMER"/>
    <TIMER id="AUDIO_PLAYER_KARAOKE_SWITCH_PROCESSING_TIMER"/>
    <TIMER id="AUDIO_PLAYER_KARAOKE_CB_TIMER"/>
    <TIMER id="AUDIO_PLAYER_PROGRESS_TIME_TIMER"/>
    
    <TIMER id="AUDIO_PLAYER_KARAOKE_PLAY_TIMER"/>
    <TIMER id="AUDIO_PLAYER_KARAOKE_RESUME_TIMER"/>
    <TIMER id="AUDIO_PLAYER_KARAOKE_PLAY_COMPLETED_TIMER"/>
#endif 
</APP>

#ifdef __MMI_BTBOX_NOLCD__
<APP id="APP_AUDIOPLAYER">

  <AUDIO id="AUD_ID_BTBOX_AUDPLY_ENABLE_KARAOKE" desc="Enable Karaoke" path="enable_karaoke.mp3">CUST_ADO_PATH"\\\\BTBox\\\\enable_karaoke.mp3"</AUDIO>
  <AUDIO id="AUD_ID_BTBOX_AUDPLY_NO_MEMORY_CARD" desc="No Memory Card" path="insert_card.mp3">CUST_ADO_PATH"\\\\BTBox\\\\insert_card.mp3"</AUDIO>
  <AUDIO id="AUD_ID_BTBOX_AUDPLY_NO_MUSIC" desc="No Music" path="no_file.mp3">CUST_ADO_PATH"\\\\BTBox\\\\no_file.mp3"</AUDIO>
  <AUDIO id="AUD_ID_BTBOX_AUDPLY_MEMCARD_PLUG_IN" desc="Plugin Memory Card" path="memory_plug_in.mp3">CUST_ADO_PATH"\\\\BTBox\\\\memory_plug_in.mp3"</AUDIO>
  <AUDIO id="AUD_ID_BTBOX_AUDPLY_MEMCARD_PLUG_OUT" desc="Plugout Memory Card" path="remove_card.mp3">CUST_ADO_PATH"\\\\BTBox\\\\remove_card.mp3"</AUDIO>
  <AUDIO id="AUD_ID_BTBOX_AUDPLY_ENTER" desc="Audio Player Enter" path="enter_audply.mp3">CUST_ADO_PATH"\\\\BTBox\\\\enter_audply.mp3"</AUDIO>
  
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_FIRST_FILE" desc="First File" led="INPUT_EVENT_LED_ID_8"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_KARAOKE_MODE" desc="Enter Karaoke" led="INPUT_EVENT_LED_ID_11" voice="AUD_ID_BTBOX_AUDPLY_ENABLE_KARAOKE"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_VOLUME_UP" desc="Audio Player Inc Vol" led="INPUT_EVENT_LED_ID_15"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_VOLUME_DOWN" desc="Audio Player Dec Vol" led="INPUT_EVENT_LED_ID_15"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_SDCARD_NOT_FOUND" desc="No Memory Card" led="INPUT_EVENT_LED_ID_8" voice="AUD_ID_BTBOX_AUDPLY_NO_MEMORY_CARD"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_NO_MUSIC" desc="No Music" led="INPUT_EVENT_LED_ID_8" voice="AUD_ID_BTBOX_AUDPLY_NO_MUSIC"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_PROCOSSING" desc="Audio Player Processing" led="INPUT_EVENT_LED_ID_8"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_INVALID_ERROR" desc="Invalid Audio File" led="INPUT_EVENT_LED_ID_8"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_PLUG_IN" desc="Plugin Memory Card" led="INPUT_EVENT_LED_ID_8" voice="AUD_ID_BTBOX_AUDPLY_MEMCARD_PLUG_IN"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_PLUG_OUT" desc="Plugout Memory Card" led="INPUT_EVENT_LED_ID_8" voice="AUD_ID_BTBOX_AUDPLY_MEMCARD_PLUG_OUT"/>
	<NOTIFY id="BTBOX_AUDPLY_NOTIFY_ENTER_AUDIO_PLAYER" desc="Audio Player Enter" voice="AUD_ID_BTBOX_AUDPLY_ENTER"/>
	
	
  <EVENT id="EVT_ID_BTBOX_PLAY_PAUSE" type="SENDER"/>
  <EVENT id="EVT_ID_BTBOX_NEXT" type="SENDER"/>
  <EVENT id="EVT_ID_BTBOX_PREV" type="SENDER"/>
  <EVENT id="EVT_ID_BTBOX_VOL_UP" type="SENDER"/>
  <EVENT id="EVT_ID_BTBOX_VOL_DOWN" type="SENDER"/>
  #ifdef __MMI_BTB_AT_KEY_SUPPORT__
  <EVENT id="EVT_ID_BTBOX_KARAOKE_SWITCH" type="SENDER"/>
  #endif
  
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_PLAY_PAUSE" evt_desc="Audio Player Play Pause" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_NEXT" evt_desc="Audio Player Next Music" key_code="KEY_0" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_PREV" evt_desc="Audio Player Previous Music" key_code="KEY_1" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_VOL_UP" evt_desc="Audio Player Inc Vol" key_code="KEY_0" key_type="KEY_REPEAT"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_VOL_DOWN" evt_desc="Audio Player Dec Vol" key_code="KEY_1" key_type="KEY_REPEAT"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_VOL_UP" evt_desc="Audio Player Inc Vol" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_VOL_DOWN" evt_desc="Audio Player Dec Vol" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS"/>
  
  #ifdef __MMI_BTB_AT_KEY_SUPPORT__
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_KARAOKE_SWITCH" evt_desc="Audio Player Karaoke Switch" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_VOL_UP" evt_desc="Audio Player Inc Vol" key_code="KEY_8" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_AUDPLY_MAIN" evt_id="EVT_ID_BTBOX_VOL_DOWN" evt_desc="Audio Player Dec Vol" key_code="KEY_9" key_type="KEY_EVENT_UP"/>
  #endif
  
</APP>

<APP id="APP_AUDIOPLAYER">
	<APP_INFO app_indx="INPUT_EVENT_APP_INDX_AUDPLY" grp_id="GRP_ID_AUDPLY_MAIN" launch_evt="EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY"/>
	<RECEIVER id="EVT_ID_INPUT_EVENT_LAUNCH_AUDPLY" proc="mmi_auddply_bt_box_event_hdlr"/>
	<RECEIVER id="EVT_ID_INPUT_EVENT_APP_SWITCH" proc="mmi_auddply_bt_box_event_hdlr"/>
</APP>
#endif

#endif  //__MMI_AUDPLY_WALK_PLAY__