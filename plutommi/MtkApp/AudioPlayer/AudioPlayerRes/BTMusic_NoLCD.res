/*Needed header files of the compile option in XML files */
#include "mmi_features.h"
#ifdef __MMI_BT_MUSIC_NOLCD__
#include "CustResDef.h"
#include "custom_mmi_default_value.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_BT_MUSIC_NOLCD">
  <SCREEN id="GRP_ID_BT_MUSIC_NOLCD"/>	
	
<!--INPUT EVENT callback Area-->	
    <RECEIVER id="EVT_ID_BTB_A2DP_CONNECTED" proc="mmi_bt_music_nolcd_launch"/>
    <RECEIVER id="EVT_ID_BTB_A2DP_DISCONNECTED" proc="mmi_bt_music_nolcd_delaunch"/>

<!--INPUT EVENT notify Area-->
  <AUDIO id="AUD_ID_BTBOX_BT_MUSIC_NOLCD_ENTER" desc="Audio For Entry BTMusic" path="BTMusic_Enter.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BTMusic_Enter.mp3"</AUDIO>
  <AUDIO id="AUD_ID_BTBOX_BT_MUSIC_NOLCD_ENABLE_KARAOKE" desc="Audio For Enable BTMusic Karaoke" path="enable_karaoke.mp3">CUST_ADO_PATH"\\\\BTBox\\\\enable_karaoke.mp3"</AUDIO>
  <NOTIFY id="BTBOX_BT_MUSIC_NOLCD_ENTER" desc="Notify ID For Entry BT Music" voice="AUD_ID_BTBOX_BT_MUSIC_NOLCD_ENTER" />
  <NOTIFY id="BTBOX_BT_MUSIC_NOLCD_KARAOKE" desc="Notify ID For Enable BT Music Karaoke" led="INPUT_EVENT_LED_ID_12" voice="AUD_ID_BTBOX_BT_MUSIC_NOLCD_ENABLE_KARAOKE"/>
  <NOTIFY id="BTBOX_BT_MUSIC_NOLCD_KARAOKE_NO_AUD" desc="Notify ID For BT Music Karaoke LED only" led="INPUT_EVENT_LED_ID_18" />
  
	<NOTIFY id="INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_UP" desc="Notify ID For Increase BT Music Volume" led="INPUT_EVENT_LED_ID_0"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_DOWN" desc="Notify ID For Decrease BT Music Volume" led="INPUT_EVENT_LED_ID_0"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_VOL_MUTE" desc="Notify ID For BT Music Volume Mute" led="INPUT_EVENT_LED_ID_14"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_BT_MUSIC_NOLCD_ERROR" desc="Notify ID For BT Music Error" led="INPUT_EVENT_LED_ID_0"/>

<!--BTBOX input event Area-->	
  <EVENT id="BTBOX_BT_MUSIC_NOLCD_PLAY_PAUSE" type="SENDER" />
  <EVENT id="BTBOX_BT_MUSIC_NOLCD_VOL_UP" type="SENDER" />
  <EVENT id="BTBOX_BT_MUSIC_NOLCD_VOL_DOWN" type="SENDER" />
  <EVENT id="BTBOX_BT_MUSIC_NOLCD_PREV" type="SENDER" />
  <EVENT id="BTBOX_BT_MUSIC_NOLCD_NEXT" type="SENDER" />
  <EVENT id="EVT_ID_INPUT_EVENT_BT_MUSIC_DIAL_LAST_CALL" type="SENDER" />
  <EVENT id="EVT_ID_INPUT_EVENT_BT_MUSIC_KARAOKE" type="SENDER" />
  <EVENT id="EVT_ID_INPUT_EVENT_BT_MUSIC_SWITCH_SRC" type="SENDER" />
  
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_PLAY_PAUSE" evt_desc="Event For Play/Pause BT Music" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_NEXT" evt_desc="Event For BT Music Switch To Next Song" key_code="KEY_0" key_type="KEY_EVENT_UP"/>
  <INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_PREV" evt_desc="Event For BT Music Switch To Prev Song" key_code="KEY_1" key_type="KEY_EVENT_UP"/>
  	
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_VOL_UP" evt_desc="Event For BT Music Volume Up" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_VOL_UP" evt_desc="Event For BT Music Volume Up" key_code="KEY_0" key_type="KEY_EVENT_REPEAT"/>
	
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_VOL_DOWN" evt_desc="Event For BT Music Volume Down" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_VOL_DOWN" evt_desc="Event For BT Music Volume Down" key_code="KEY_1" key_type="KEY_EVENT_REPEAT"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="EVT_ID_INPUT_EVENT_BT_MUSIC_DIAL_LAST_CALL" evt_desc="Event For BT Music Dial last call" key_code="KEY_2" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="EVT_ID_INPUT_EVENT_BT_MUSIC_KARAOKE" evt_desc="Event For BT Music Enable/Disable Karaoke" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
	
	#ifdef __MMI_BTB_AT_KEY_SUPPORT__
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_VOL_UP" evt_desc="Event For BT Music Volume Up" key_code="KEY_8" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="BTBOX_BT_MUSIC_NOLCD_VOL_DOWN" evt_desc="Event For BT Music Volume Down" key_code="KEY_9" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="EVT_ID_INPUT_EVENT_BT_MUSIC_DIAL_LAST_CALL" evt_desc="Event For BT Music Dial last call" key_code="KEY_STAR" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="GRP_ID_BT_MUSIC_NOLCD"  grp_desc="BT Music" evt_id="EVT_ID_INPUT_EVENT_BT_MUSIC_SWITCH_SRC" evt_desc="Event For BT Music Switch SRC" key_code="KEY_POUND" key_type="KEY_EVENT_UP"/>
	#endif

<!--BTBOX app info Area-->		 
	
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--NVRAM LID -->
    <CACHEDATA type="byte" id="NVRAM_BT_MUSIC_NOLCD_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X06] </DEFAULT_VALUE>
        <DESCRIPTION>BT Music volume</DESCRIPTION>
    </CACHEDATA>
    <!--End NVRAM LID -->

    <!--------------------------------------------------------------------------------------------------------------------->
    <TIMER id="BT_MUSIC_NOLCD_KARAOKE_SWITCH_TIMER"/>
</APP>
#endif //__MMI_BTBOX_NOLCD__
