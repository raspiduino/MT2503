/*Needed header files of the compile option in XML files */
#include "mmi_features.h"
#ifdef __MMI_BTBOX_NOLCD__
#include "CustResDef.h"
#include "custom_mmi_default_value.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_MEGAPHONE">
  <SCREEN id="GRP_ID_MEGAPHONE"/>	
  <EVENT id="BTBOX_NOLCD_MEGAPHONE_ON_OFF" type="SENDER" />
  <EVENT id="BTBOX_NOLCD_MEGAPHONE_VOL_UP" type="SENDER" />
  <EVENT id="BTBOX_NOLCD_MEGAPHONE_VOL_DOWN" type="SENDER" />
	
<!--INPUT EVENT callback Area-->	
	<RECEIVER id="EVT_ID_INPUT_EVENT_LAUNCH_MEGAPHONE" proc="mmi_megaphone_launch"/>
	<RECEIVER id="EVT_ID_INPUT_EVENT_APP_SWITCH" proc="mmi_megaphone_switch_app_hdlr"/>

<!--INPUT EVENT notify Area-->
  <AUDIO id="AUD_ID_BTBOX_MEGAPHONE_ENTER" desc="Audio For Entry Megaphone" path="Megaphone_Enter.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\Megaphone_Enter.mp3"</AUDIO>
  <NOTIFY id="BTBOX_MEGAPHONE_ENTER" desc="Notify ID For Entry Megaphone" voice="AUD_ID_BTBOX_MEGAPHONE_ENTER" />
	<NOTIFY id="INPUT_EVENT_NOTIFY_MEGAPHONE_VOL_UP" desc="Notify ID For Increase Megaphone Volume" led="INPUT_EVENT_LED_ID_15"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_MEGAPHONE_VOL_DOWN" desc="Notify ID For Decrease Megaphone Volume" led="INPUT_EVENT_LED_ID_15"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_MEGAPHONE_VOL_MUTE" desc="Notify ID For Megaphone Volume Mute" led="INPUT_EVENT_LED_ID_14"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_MEGAPHONE_ERROR" desc="Notify ID For Megaphone Error" led="INPUT_EVENT_LED_ID_8"/>

<!--BTBOX input event Area-->	
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_ON_OFF" evt_desc="Event For Megaphone Power On/Off" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
	
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_VOL_UP" evt_desc="Event For Megaphone Volume Up" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_VOL_UP" evt_desc="Event For Megaphone Volume Up" key_code="KEY_0" key_type="KEY_EVENT_REPEAT"/>
	
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_VOL_DOWN" evt_desc="Event For Megaphone Volume Down" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_VOL_DOWN" evt_desc="Event For Megaphone Volume Down" key_code="KEY_1" key_type="KEY_EVENT_REPEAT"/>
	
	#ifdef __MMI_BTB_AT_KEY_SUPPORT__
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_VOL_UP" evt_desc="Event For Megaphone Volume Up" key_code="KEY_8" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="BTBOX_NOLCD_MEGAPHONE_VOL_DOWN" evt_desc="Event For Megaphone Volume Down" key_code="KEY_9" key_type="KEY_EVENT_UP"/>
	#endif
	
	<INPUT_EVENT grp_id="GRP_ID_MEGAPHONE" grp_desc="Megaphone" evt_id="EVT_ID_INPUT_EVENT_LAUNCH_MEGAPHONE" evt_desc="Event For Lanuch Megaphone"/>

<!--BTBOX app info Area-->		
	<APP_INFO app_indx="INPUT_EVENT_APP_INDX_MEGAPHONE" grp_id="GRP_ID_MEGAPHONE" launch_evt="EVT_ID_INPUT_EVENT_LAUNCH_MEGAPHONE"/>     
  <TIMER id="MEGAPHONE_DELAY_CALLBACK_TIMER"/>
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--NVRAM LID -->
	  <CACHEDATA type="byte" id="NVRAM_MEGAPHONE_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X06] </DEFAULT_VALUE>
        <DESCRIPTION>Megaphone volume</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_MEGAPHONE_ENABLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION>Megaphone Enable or not</DESCRIPTION>
    </CACHEDATA>
	<!--End NVRAM LID -->
	<!--------------------------------------------------------------------------------------------------------------------->
	
</APP>

#else /* __MMI_BTBOX_NOLCD__ */

#ifdef  __MMI_MEGAPHONE_SUPPORT__

#include "CustResDef.h"
#include "custom_mmi_default_value.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_MEGAPHONE"
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name = "native.mtk.megaphone"
    name = "STR_ID_MEGAPHONE_TITLE"
    launch = "mmi_megaphone_launch"
    #endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
	<INCLUDE file="GlobalResDef.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
	<STRING id="STR_ID_MEGAPHONE_TITLE"/>
	<STRING id="STR_ID_MEGAPHONE_POWER_ON"/>
	<STRING id="STR_ID_MEGAPHONE_POWER_OFF"/>
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->   
    <IMAGE id="IMG_ID_MEGAPHONE_PLAY_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\Megaphone\\\\Megaphone.png"</IMAGE> 
    <IMAGE id="IMG_ID_MEGAPHONE_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\Megaphone\\\\Speaker.jpg"</IMAGE> 
    <!--End Image Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

	
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    

    <!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Tree Area-->
	<MENU id="MENU_ID_MEGAPHONE_MAIN" type="APP_MAIN" str="STR_ID_MEGAPHONE_TITLE"
        highlight="mmi_megaphone_highlight_menu" shortcut="ON" 
        launch="mmi_megaphone_launch"/>
	<!--End Menu Tree Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
	<SCREEN id="GRP_ID_MEGAPHONE"/>	
	<SCREEN id="SCR_ID_MEGAPHONE_MAIN"/>
    <!--End Screen ID Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

    
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Receiving Evt ID -->
    /* Linein */
    <RECEIVER id="EVT_ID_GPIO_LINEIN_PLUG_IN" proc="mmi_megaphone_proc" />
    <RECEIVER id="EVT_ID_GPIO_LINEIN_PLUG_OUT" proc="mmi_megaphone_proc" />
    /* Earphone */
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_megaphone_proc" />
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_megaphone_proc" />
    #if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
    <RECEIVER id="EVT_ID_SRV_A2DP_CONNECT" proc="mmi_megaphone_proc"/>
    #endif  //defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
	<!--End Receiving Evt ID -->
	<!--------------------------------------------------------------------------------------------------------------------->

    
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Sending Evt ID -->
	<!--End Sending Evt ID -->
	<!--------------------------------------------------------------------------------------------------------------------->
	
	
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--NVRAM LID -->
	  <CACHEDATA type="byte" id="NVRAM_MEGAPHONE_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X06] </DEFAULT_VALUE>
        <DESCRIPTION>Megaphone volume</DESCRIPTION>
    </CACHEDATA>
	<!--End NVRAM LID -->
	<!--------------------------------------------------------------------------------------------------------------------->
</APP>

#endif  // __MMI_MEGAPHONE_SUPPORT__
#endif //__MMI_BTBOX_NOLCD__
