/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#ifdef __MMI_BTBOX_NOLCD__
#include "CustResDef.h"
#include "custom_mmi_default_value.h"

<?xml version = "1.0" encoding = "UTF-8"?>
<APP id="APP_FMRDO"
    package_name = "native.mtk.fmrdo"
>
  <SCREEN id="GRP_ID_FMRADIO"/>	
  <MENU id="MENU_ID_FMRDO_MAIN" type="APP_MAIN" />
        
  <EVENT id="BTBOX_NOLCD_FM_ON_OFF" type="SENDER" />
  <EVENT id="BTBOX_NOLCD_FM_VOL_UP" type="SENDER" />
  <EVENT id="BTBOX_NOLCD_FM_VOL_DOWN" type="SENDER" />
  <EVENT id="BTBOX_NOLCD_FM_FREQ_UP" type="SENDER" />
  <EVENT id="BTBOX_NOLCD_FM_FREQ_DOWN" type="SENDER" />
	
<!--INPUT EVENT callback Area-->	
	<RECEIVER id="EVT_ID_INPUT_EVENT_LAUNCH_FM" proc="mmi_fmradio_launch"/>
	<RECEIVER id="EVT_ID_INPUT_EVENT_APP_SWITCH" proc="mmi_fmradio_switch_app_hdlr"/>

<!--INPUT EVENT notify Area-->
  <AUDIO id="AUD_ID_BTBOX_FMRADIO_ENTER" desc="Audio For Entry FM Radio" path="FMRadio_Enter.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\FMRadio_Enter.mp3"</AUDIO>
  <NOTIFY id="BTBOX_FMRADIO_ENTER" desc="Notify ID For Entry FMRadio" voice="AUD_ID_BTBOX_FMRADIO_ENTER" />
	<NOTIFY id="INPUT_EVENT_NOTIFY_FM_VOL_UP" desc="Notify ID For Increase FMRadio Volume" led="INPUT_EVENT_LED_ID_15"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_FM_VOL_DOWN" desc="Notify ID For Decrease FMRadio Volume" led="INPUT_EVENT_LED_ID_15"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_FM_VOL_MUTE" desc="Notify ID For FMRadio Volume Mute" led="INPUT_EVENT_LED_ID_14"/>
	<NOTIFY id="INPUT_EVENT_NOTIFY_FM_ERROR" desc="Notify ID For FMRadio Error" led="INPUT_EVENT_LED_ID_8"/>

<!--BTBOX input event Area-->	
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_ON_OFF" evt_desc="Event For FM Radio Power On/Off" key_code="KEY_2" key_type="KEY_EVENT_UP"/>
	
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_VOL_UP" evt_desc="Event For FM Radio Volume Up" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_VOL_UP" evt_desc="Event For FM Radio Volume Up" key_code="KEY_0" key_type="KEY_EVENT_REPEAT"/>
	
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_VOL_DOWN" evt_desc="Event For FM Radio Volume Down" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS"/>
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_VOL_DOWN" evt_desc="Event For FM Radio Volume Down" key_code="KEY_1" key_type="KEY_EVENT_REPEAT"/>
	
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_FREQ_UP" evt_desc="Event For Switch To Next FM Radio Frequency" key_code="KEY_0" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_FREQ_DOWN" evt_desc="Event For Switch To Prev FM Radio Frequency" key_code="KEY_1" key_type="KEY_EVENT_UP"/>
	
	#ifdef __MMI_BTB_AT_KEY_SUPPORT__
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_VOL_UP" evt_desc="Event For FM Radio Volume Up" key_code="KEY_8" key_type="KEY_EVENT_UP"/>
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="BTBOX_NOLCD_FM_VOL_DOWN" evt_desc="Event For FM Radio Volume Down" key_code="KEY_9" key_type="KEY_EVENT_UP"/>
	#endif
	
	<INPUT_EVENT grp_id="GRP_ID_FMRADIO" grp_desc="FM Radio" evt_id="EVT_ID_INPUT_EVENT_LAUNCH_FM" evt_desc="Event For Lanuch FM Radio"/>

<!--BTBOX app info Area-->		
	<APP_INFO app_indx="INPUT_EVENT_APP_INDX_FM" grp_id="GRP_ID_FMRADIO" launch_evt="EVT_ID_INPUT_EVENT_LAUNCH_FM"/>     
  <TIMER id="FMRDO_DELAY_CALLBACK_TIMER"/>
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--NVRAM LID -->
	  <CACHEDATA type="byte" id="NVRAM_FMRADIO_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X0C] </DEFAULT_VALUE>
        <DESCRIPTION> fm volume</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_FMRADIO_ENABLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio Enable or not</DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_FMRADIO_FREQ">
        <DEFAULT_VALUE> [0x0A, 0x3D] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio frequency </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_FM_FM_RADIO_CHANNEL_1">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FM_FM_RADIO_CHANNEL_2">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FM_FM_RADIO_CHANNEL_3">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
	<!--End NVRAM LID -->
	<!--------------------------------------------------------------------------------------------------------------------->
	
</APP>

#else

#ifdef __MMI_FM_RADIO__

#include "CustResDef.h"
#include "custom_mmi_default_value.h"

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_FMRDO"
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name = "native.mtk.fmrdo"
    name = "STR_ID_FMRDO_TITLE"
  #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    img = "IMG_ID_FMRDO_ICON_COSMOS_STYLE"
  #endif 
    launch = "mmi_fmrado_launch"
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
	<INCLUDE file="GlobalResDef.h"/>
			<!--------------------------------------------------------------------------------------------------------------------->
         <!--String Resource Area-->
         <!--String Resource Area-->	
         
	<STRING id="STR_ID_FMRDO_TITLE"/>
	<STRING id="STR_ID_FMRDO_CHANNEL_LIST"/>
	<STRING id="STR_ID_FMRDO_MANUAL_INPUT"/>
	<STRING id="STR_ID_FMRDO_PRESET_AUTO_SEARCH"/>
	#ifndef __MMI_FM_PLUTO_SLIM__
	<STRING id="STR_ID_FMRDO_BACKGROUND_PLAY"/>
	#endif
	<STRING id="STR_ID_FMRDO_PRESET_LIST"/>
	<STRING id="STR_ID_FMRDO_CHANNEL_NAME"/>
	<STRING id="STR_ID_FMRDO_FREQUENCY"/>
	<STRING id="STR_ID_FMRDO_VALID_FM_BANDWIDTH"/>
	<STRING id="STR_ID_FMRDO_VALID_FM_DECIMAL"/>
	<STRING id="STR_ID_FMRDO_NEW_CHANNEL"/>
	<STRING id="STR_ID_FMRDO_SET_CH_LIST"/>
#ifdef __MMI_MAINLCD_96X64__
	<STRING id="STR_ID_FMRDO_POWER_ON"/>
	<STRING id="STR_ID_FMRDO_POWER_OFF"/>
	<STRING id="STR_ID_FMRDO_VOLUME"/>
	<STRING id="STR_ID_FMRDO_AUTO_SEARCH"/>
#endif
	#ifndef __MMI_FM_SLIM_SKIN__
	<STRING id="STR_ID_FMRDO_SKIN"/>
	<STRING id="STR_ID_FMRDO_SKIN_1"/>
	<STRING id="STR_ID_FMRDO_SKIN_2"/>
	<STRING id="STR_ID_FMRDO_SKIN_3"/>
	#endif

	#ifdef __MMI_FM_RADIO_MONO__
	<STRING id="STR_ID_FMRDO_CHANNEL_EFFECT"/>
	<STRING id="STR_ID_FMRDO_CHANNEL_MONO"/>
	<STRING id="STR_ID_FMRDO_CHANNEL_STEREO"/>
	#endif
	
	#ifdef __MMI_NCENTER_SUPPORT__
	<STRING id="STR_ID_FMRDO_CLOSE_NOTIFICATION"/>
	#endif

	#ifdef __MMI_FM_RADIO_ON_SUBLCD__
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_MODE_SELECT"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_STEP_MODE"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_MODE"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_SEARCH_MODE"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_BACK_TO_MAINMENU"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_NAME_CH"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_NAME_RADIO"/>
	<STRING id="STR_ID_FM_RADIO_ON_SUBLCD_CHANNEL_NAME_SEARCH"/>
	#endif  /*__MMI_FM_RADIO_ON_SUBLCD__*/

	#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
	<STRING id="STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE"/>
	#else
	<STRING id="STR_ID_FMRDO_POWER_ON_FIRST"/>
	#endif
	#ifndef __MMI_FM_PLUTO_SLIM__
	#ifdef __MMI_FM_RADIO_LOUD_SPEAK__
	<STRING id="STR_ID_FMRDO_LOUD_SPEAKER"/>
	#endif
	#endif

	#ifdef __MMI_FM_RADIO_RECORD__
	<STRING id="STR_ID_FMRDO_CANCEL_ASK"/>
	<STRING id="STR_ID_FMRDO_RECORD"/>
	<STRING id="STR_ID_FMRDO_APPEND"/>
	<STRING id="STR_ID_FMRDO_FILE_LIST"/>
	<STRING id="STR_ID_FMRDO_RECORD_FORMAT"/>
	<STRING id="STR_ID_FMRDO_RECORD_STORAGE"/>
	<STRING id="STR_ID_FMRDO_FORMAT_AMR"/>
	<STRING id="STR_ID_FMRDO_FORMAT_WAV"/>
	<STRING id="STR_ID_FMRDO_BAD_FORMAT"/>
	<STRING id="STR_ID_FMRDO_INVALID_FORMAT"/>
	<STRING id="STR_ID_FMRDO_DEVICE_BUSY"/>
	<STRING id="STR_ID_FMRDO_OPEN_FILE_ERROR"/>
	<STRING id="STR_ID_FMRDO_NO_CARD"/>
	<STRING id="STR_ID_FMRDO_WRITE_PROTECTION_ERROR"/>
	<STRING id="STR_ID_FMRDO_RECORD_IN_BT_SCO"/>
	<STRING id="STR_ID_FMRDO_RECORD_FAILED"/>
	<STRING id="STR_ID_FMRDO_RECORD_QUALITY"/>
	<STRING id="STR_ID_FMRDOREC_SIZE_LIMIT"/>
	#endif /*__MMI_FM_RADIO_RECORD__ */

	#ifdef __MMI_FM_RADIO_SCHEDULER__
	<STRING id="STR_ID_FMRDO_SCHEDULER_SCHEDULE"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_CUSTOMIZE"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_SETTINGS"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_REPEAT"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_MANUAL_INPUT"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_CHANNEL_SETTINGS"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_SCHEDULE_LIST"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_NO_CHANNEL_SCHEDULED"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_ERROR_TIME"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_INVALID_TIME"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_ERROR_FREQ"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_STARTED_MSG"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_STOPPED_MSG"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_ONCE"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_EVERYDAY"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_WEEKLY"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_MONTHLY"/>
	<STRING id="STR_ID_FMRDO_SCHEDULER_DEACTIVATED"/>
	#endif /* __MMI_FM_RADIO_SCHEDULER__ */

	#ifdef __MMI_FM_RADIO_RDS__
	<STRING id="STR_ID_FMRDO_RDS_SETTING"/>
	<STRING id="STR_ID_FMRDO_RDS_AF_SERVICE"/>
	<STRING id="STR_ID_FMRDO_RDS_TP_SERVICE"/>
	#endif /*__MMI_FM_RADIO_RDS__*/

	#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__) && defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	<STRING id="STR_ID_FMRDO_LOUD_SPEAKER_ON"/>
	<STRING id="STR_ID_FMRDO_LOUD_SPEAKER_OFF"/>
	#endif

        <!--End String Resource Area-->
        <!--End String Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

<!--------------------------------------------------------------------------------------------------------------------->
        <!--Image Resource Area-->
        <!--Image Resource Area-->
#if defined(__MMI_APP_MANAGER_SUPPORT__)
  #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
  <IMAGE id="IMG_ID_FMRDO_ICON_COSMOS_STYLE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\FmRadio.png"</IMAGE>
  #endif 
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
#ifdef __MMI_MAINLCD_96X64__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_ANIMATION" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_ANIMATION_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\0.bmp"</IMAGE>
#else
#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT

#ifdef __MMI_FM_RADIO_ANIMATION__
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_animation"</IMAGE>
#endif /*__MMI_FM_RADIO_ANIMATION__*/

    // TODO: if neccesary
    #ifdef __MMI_FTE_SUPPORT_SLIM__
    <IMAGE id="IMG_ID_FMRDO_SKIN_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\line.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_BG.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_DEC.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_INC.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_PWR_ON.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_PWR_OFF.png"</IMAGE>
   	#ifdef __FTE_NON_SLIM_RES__
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_0.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_1.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_2.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_3.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_4.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_5.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_6.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_7.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_8.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_9.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_DOT.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_MHZ">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_MHZ.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_LSK">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_RSK">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back.png"</IMAGE>

    <IMAGE id="IMG_ID_FMRDO_SPEAKER_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_on_up.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SPEAKER_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_off_up.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SPEAKER_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SPEAKER_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\speaker_highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_FRMDO_VOLUME_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_bg.png"</IMAGE>
    <IMAGE id="IMG_ID_FRMDO_VOLUME_FG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\volume_fg.png"</IMAGE>
	
    <IMAGE id="IMG_ID_FMRDO_SKIN_LSK_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option_down.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_RSK_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back_down.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>

#ifdef __MMI_FM_RADIO_RECORD__
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_SGN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\SIGN_REC.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_SGN_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\SIGN_PAUSE.png"</IMAGE>
	
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_0.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_1.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_2.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_3.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_4.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_5.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_6.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_7.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_8.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_9.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\num_col.png"</IMAGE>

    <IMAGE id="IMG_ID_FMRDO_SKIN_REC_PAUSE_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_REC_PAUSE_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause_down_sk.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_REC_RESUME_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_REC_RESUME_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC_down_sk.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_REC_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_SKIN_REC_STOP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop_down_sk.png"</IMAGE>
#endif /* __MMI_FM_RADIO_RECORD__ */

#ifdef __MMI_FM_RADIO_RDS__
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_on.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_off.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_on.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_off.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_on.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_off.png"</IMAGE>
    <IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_dis.png"</IMAGE>
#endif /*__MMI_FM_RADIO_RDS__*/

#elif defined(__MMI_FTE_SUPPORT_SLIM__)   

	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\BG.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\line.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_DEC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_INC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_PREV_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_DEC_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_NEXT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_INC_dis.png"</IMAGE>	
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_PWR_ON.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_PWR_OFF.png"</IMAGE>
	#ifdef __FTE_NON_SLIM_RES__
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_0.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_1.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_2.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_3.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_4.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_5.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_6.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_7.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_8.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_9.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_DOT.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_MHZ">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_TUNE_MHZ.png"</IMAGE>
	#endif
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_LSK">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_RSK">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_LSK_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\option_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_RSK_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\HIGHLIGHT.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\VOLUME_BG.9SLICE.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_ON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\VOLUME_ON.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\VOLUME_OFF.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_TUNE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\VOLUME_TUNE.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_EMPTY">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\VOLUME_EMPTY.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_IND">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\SCROLL_INDEX.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_IND_HL">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\SCROLL_INDEX_HL.bmp"</IMAGE>

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_0.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_1.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_2.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_3.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_4.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_5.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_6.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_7.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_8.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_9.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_NUM_COL.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC_BG.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_PAUSE_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_PAUSE_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\pause.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_RESUME_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_RESUME_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_STOP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\stop.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_BTN_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\REC.9SLICE.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_BTN_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\FMR_REC_DOWN.9SLICE.png"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/	
	
	#elif defined(__MMI_FTE_SUPPORT__)  /*__MMI_FTE_SUPPORT_SLIM__*/

	#ifdef __MMI_FM_RADIO_ANIMATION__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_animation"</IMAGE>
	#endif /*__MMI_FM_RADIO_ANIMATION__*/

	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_BG.gif"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_PREV">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_MEMO_PRE.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_NEXT">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_MEMO_NEXT.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_PWR_ON.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_PWR_OFF.png"</IMAGE>
	#ifdef __FTE_NON_SLIM_RES__
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_0">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_0.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_1">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_1.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_2">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_2.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_3">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_3.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_4">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_4.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_5">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_5.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_6">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_6.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_7">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_7.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_8">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_8.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_9">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_9.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_DOT.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_TUNE_MHZ">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_MHZ.png"</IMAGE>
	#endif
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_INC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_DEC.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_LSK">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_SK_OPTION.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_RSK">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_SK_BACK.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_LSK_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_SK_OPTION_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_RSK_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_SK_BACK_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_HIGHLIGHT.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_INC_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_TUNE_DEC_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_NEXT_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_MEMO_NEXT_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_MEMO_PREV_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_MEMO_PRE_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_VOLUME_BG.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_ON">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_VOLUME_ON.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_VOLUME_OFF.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_TUNE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_VOLUME_TUNE.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_EMPTY">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_VOLUME_EMPTY.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_IND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_SCROLL_INDEX.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_VOL_IND_HL">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_SCROLL_INDEX_HL.bmp"</IMAGE>

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_ON.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_DIS.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_0.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_1.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_2.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_3.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_4.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_5.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_6.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_7.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_8.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_9.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_NUM_COL.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_BG">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_BG.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_PAUSE_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_PAUSE.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_PAUSE_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_PAUSE_DOWN.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_RESUME_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_RESUME.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_RESUME_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_RESUME_DOWN.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_STOP.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_REC_STOP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\FTE\\\\FMR_REC_STOP_DOWN.png"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	#elif defined(__MMI_FM_SKIN_SYN_TO_THEME__)  /*__MMI_FTE_SUPPORT__*/
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_transparent_background.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TUNER_SCALE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_tuner_scale.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_tuner_scale_indicator.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_power_on_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_power_on_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_power_off_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_power_off_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_power_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_search_on_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_search_on_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_search_off_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_search_off_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_search_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_right_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_right_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_right_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_left_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_left_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_left_dis.png"</IMAGE>

	#ifdef __MMI_FM_RADIO_ANIMATION__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_animation"</IMAGE>
	#endif /*__MMI_FM_RADIO_ANIMATION__*/

	#ifdef __MMI_TOUCH_SCREEN__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume_inc_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume_inc_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume_inc_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume_dec_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume_dec_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_volume_dec_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SETTING_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_setting_up.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SETTING_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_setting_down.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SETTING_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_setting_dis.png"</IMAGE>
	#endif /*__MMI_TOUCH_SCREEN__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_rec.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_rec_disable.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_rec_pause.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_0.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_1.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_2.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_3.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_4.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_5.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_6.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_7.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_8.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_9.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_num_col.png"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	#ifdef __MMI_FM_RADIO_RDS__
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_on.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_off.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_on.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_off.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_on.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_off.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_dis.png"</IMAGE>
	#endif /*__MMI_FM_RADIO_RDS__*/

	#else /*__MMI_FM_SKIN_SYN_TO_THEME__*/ /*__MMI_FTE_SUPPORT__*/

	#ifdef __MMI_SLIM_IMG_RES__

	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TITLE_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\title.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TUNER_SCALE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\indicator.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\ind.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\vol_full.png"</IMAGE>	
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\vol_none.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\power.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\power_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_UP_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\forward.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_DOWN_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\back.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\next.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\prev.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BUTTON_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\button.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\disable.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BUTTON_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\highlight.9slice.png"</IMAGE>

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\record.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\record_pause.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\Multimedia\\\\col.bmp"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	#ifdef __MMI_FM_RADIO_RDS__
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_on.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_off.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_RDS_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_on.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_off.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_TP_dis.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_on.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_off.png"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\SkinTheme\\\\FMR_AF_dis.png"</IMAGE>
	#endif /*__MMI_FM_RADIO_RDS__*/
		
	
	#else /*__MMI_SLIM_IMG_RES__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_background_rec.gif"</IMAGE>
	#else
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_background.gif"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TUNER_SCALE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_tuner_scale.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_TUNER_SCALE_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_tuner_scale_indicator.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_power_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_power_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_power_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_POWER_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_power_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_search_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_search_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_search_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SEARCH_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_search_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_right_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_UP_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_right_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_left_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_STEP_DOWN_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_left_down.bmp"</IMAGE>

	#ifdef __MMI_FM_RADIO_ANIMATION__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_animation.gif"</IMAGE>
	#endif /*__MMI_FM_RADIO_ANIMATION__*/

	#ifdef __MMI_TOUCH_SCREEN__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume_inc_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_INC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume_inc_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_INC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume_inc_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume_dec_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume_dec_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_VOLUME_DEC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_volume_dec_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SETTING_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_setting_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_SETTING_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_setting_down.bmp"</IMAGE>
	#endif /*__MMI_TOUCH_SCREEN__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_rec.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_rec_pause.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_1_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_num_col.bmp"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	#ifdef __MMI_FM_RADIO_RDS__
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_RDS_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_RDS_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_RDS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_RDS_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_TP_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_TP_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_TP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_TP_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_AF_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_AF_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_1_AF_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin1\\\\FMR_AF_dis.bmp"</IMAGE>
	#endif /*__MMI_FM_RADIO_RDS__*/

	#endif/*__MMI_SLIM_IMG_RES__*/

	#endif /*__MMI_FM_SKIN_SYN_TO_THEME__*/ /*__MMI_FTE_SUPPORT__*/

	#if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_background_rec.gif"</IMAGE>
	#else
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_background.gif"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	<IMAGE id="IMG_ID_FMRDO_SKIN_2_TUNER_SCALE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_tuner_scale.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_TUNER_SCALE_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_tuner_scale_indicator.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_power_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_power_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_power_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_POWER_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_power_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_search_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_search_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_search_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_SEARCH_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_search_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_right_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_STEP_UP_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_right_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_left_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_STEP_DOWN_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_left_down.bmp"</IMAGE>

	#ifdef __MMI_FM_RADIO_ANIMATION__
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_animation.gif"</IMAGE>
	#endif /*__MMI_FM_RADIO_ANIMATION__*/

	#ifdef __MMI_TOUCH_SCREEN__
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME_INC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume_inc_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME_INC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume_inc_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME_INC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume_inc_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume_dec_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume_dec_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_VOLUME_DEC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_volume_dec_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_SETTING_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_setting_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_SETTING_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_setting_down.bmp"</IMAGE>
	#endif /*__MMI_TOUCH_SCREEN__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_REC">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_rec.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_rec_pause.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_2_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_num_col.bmp"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	#ifdef __MMI_FM_RADIO_RDS__
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_RDS_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_RDS_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_RDS_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_RDS_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_RDS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_RDS_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_TP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_TP_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_TP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_TP_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_TP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_TP_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_AF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_AF_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_AF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_AF_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_2_AF_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin2\\\\FMR_AF_dis.bmp"</IMAGE>
	#endif/*__MMI_FM_RADIO_RDS__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_background_rec.gif"</IMAGE>
	#else
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_background.gif"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	<IMAGE id="IMG_ID_FMRDO_SKIN_3_TUNER_SCALE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_tuner_scale.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_TUNER_SCALE_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_tuner_scale_indicator.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_power_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_power_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_power_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_POWER_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_power_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_search_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_search_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_search_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_SEARCH_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_search_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_right_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_STEP_UP_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_right_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_left_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_STEP_DOWN_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_left_down.bmp"</IMAGE>

	#ifdef __MMI_FM_RADIO_ANIMATION__
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_animation.gif"</IMAGE>
	#endif /*__MMI_FM_RADIO_ANIMATION__*/

	#ifdef __MMI_TOUCH_SCREEN__
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME_INC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume_inc_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME_INC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume_inc_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME_INC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume_inc_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume_dec_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume_dec_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_VOLUME_DEC_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_volume_dec_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_SETTING_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_setting_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_SETTING_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_setting_down.bmp"</IMAGE>
	#endif /*__MMI_TOUCH_SCREEN__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_REC">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_rec.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_REC_PAUSE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_rec_pause.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SKIN_3_NUM_COL">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_num_col.bmp"</IMAGE>
	#endif /*__MMI_FM_RADIO_RECORD__*/

	#ifdef __MMI_FM_RADIO_ON_SUBLCD__
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_BACKGROUND">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_background.gif"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_VOLUME">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_volume.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_TUNER_SCALE">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_tuner_scale.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_TUNER_SCALE_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_tuner_scale_indicator.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_ON_UP">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_power_on_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_power_on_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_power_off_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_POWER_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_power_off_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_ON_UP">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\step.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_ON_DOWN">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\channel.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_OFF_UP">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\search.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_SEARCH_BUTTON_OFF_DOWN">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\search.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_STEP_UP_BUTTON_UP">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_right_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_STEP_UP_BUTTON_DOWN">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_right_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_STEP_DOWN_BUTTON_UP">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_left_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_SUB_SKIN_STEP_DOWN_BUTTON_DOWN">CUST_IMG_PATH"\\\\SubLCD\\\\Application\\\\FMRadio\\\\skin\\\\FMR_left_down.bmp"</IMAGE>
	#endif /*__MMI_FM_RADIO_ON_SUBLCD__*/

	#ifdef __MMI_FM_RADIO_RDS__
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_RDS_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_RDS_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_RDS_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_RDS_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_RDS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_RDS_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_TP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_TP_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_TP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_TP_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_TP_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_TP_dis.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_AF_UP">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_AF_on.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_AF_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_AF_off.bmp"</IMAGE>
	<IMAGE id="IMG_ID_FMRDO_RDS_SKIN_3_AF_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\FMRadio\\\\Skin3\\\\FMR_AF_dis.bmp"</IMAGE>
	#endif/*__MMI_FM_RADIO_RDS__*/
	
	#endif /* (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))*/
#endif /*__MMI_MAINLCD_96X64__*/
	 <!--End Image Resource Area-->
        <!--End Image Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

	
<!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->
        
	

<!--
	#ifdef __MMI_FM_RADIO_ON_SUBLCD__
	<!--REMOVED_SCRIPT  ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SUB_FMRADIO, mmi_fmrdo_sub_highlight_menu);-->
	#endif
-->

	<!--Menu Tree Area-->
	<MENU id="MENU_ID_FMRDO_MAIN" type="APP_MAIN" str="STR_ID_FMRDO_TITLE"
        highlight="mmi_fmrdo_highlight_menu" shortcut="ON" 
        launch="mmi_fmrdo_run_app"/>

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    <MENUITEM id="MENU_ID_FMRDO_PLAY" str="@OID:STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_FMRDO_STOP" str="@OID:STR_GLOBAL_STOP"/>
    #ifdef __MMI_FM_RADIO_LOUD_SPEAK__
    <MENUITEM id="MENU_ID_FMRDO_LOUD_SPEAKER_ON" str="STR_ID_FMRDO_LOUD_SPEAKER_ON"/>
    <MENUITEM id="MENU_ID_FMRDO_LOUD_SPEAKER_OFF" str="STR_ID_FMRDO_LOUD_SPEAKER_OFF"/>
    #endif
#endif
	<MENUITEM id="MENU_ID_FMRDO_CHANNEL_LIST" str="STR_ID_FMRDO_CHANNEL_LIST"/>
	<MENUITEM id="MENU_ID_FMRDO_MANUAL_INPUT" str="STR_ID_FMRDO_MANUAL_INPUT"/>
	<MENUITEM id="MENU_ID_FMRDO_PRESET_AUTO_SEARCH" str="STR_ID_FMRDO_PRESET_AUTO_SEARCH"/>
	#ifndef __MMI_FM_PLUTO_SLIM__
	<MENUITEM id="MENU_ID_FMRDO_SETTINGS" str="@OID:STR_GLOBAL_SETTINGS"/>
	#endif
	#ifdef __MMI_FM_RADIO_SCHEDULER__
	<MENUITEM id="MENU_ID_FMRDO_SCHEDULER_MENU" str="STR_ID_FMRDO_SCHEDULER_SCHEDULE"/>
	#endif /*__MMI_FM_RADIO_SCHEDULER__*/

	#ifdef __MMI_FM_RADIO_RECORD__
	<MENUITEM id="MENU_ID_FMRDO_RECORD" str="STR_ID_FMRDO_RECORD"/>
	<MENUITEM id="MENU_ID_FMRDO_FILE_LIST" str="STR_ID_FMRDO_FILE_LIST"/>
	#endif /*__MMI_FM_RADIO_RECORD__*/
#ifdef __MMI_MAINLCD_96X64__
	<MENUITEM id="MENU_ID_FMRDO_POWER_ON" str="STR_ID_FMRDO_POWER_ON"/>
	<MENUITEM id="MENU_ID_FMRDO_POWER_OFF" str="STR_ID_FMRDO_POWER_OFF"/>
	<MENUITEM id="MENU_ID_FMRDO_VOLUME" str="STR_ID_FMRDO_VOLUME"/>
	<MENU id="MENU_ID_FMRDO_MAIN_OPTION" type="OPTION" parent="MENU_ID_FMRDO_MAIN" str="@OID:STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_ID_FMRDO_POWER_ON</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_POWER_OFF</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_MANUAL_INPUT</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_CHANNEL_LIST</MENUITEM_ID>	
		<MENUITEM_ID>MENU_ID_FMRDO_VOLUME</MENUITEM_ID>	
		<MENUITEM_ID>MENU_ID_FMRDO_PRESET_AUTO_SEARCH</MENUITEM_ID>
	</MENU>
#else

	<MENU id="MENU_ID_FMRDO_MAIN_OPTION" type="OPTION" parent="MENU_ID_FMRDO_MAIN" str="@OID:STR_GLOBAL_OPTIONS">
		#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
 		<MENUITEM_ID>MENU_ID_FMRDO_PLAY</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_STOP</MENUITEM_ID>
		#endif
		<MENUITEM_ID>MENU_ID_FMRDO_CHANNEL_LIST</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_MANUAL_INPUT</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_PRESET_AUTO_SEARCH</MENUITEM_ID>
		#ifndef __MMI_FM_PLUTO_SLIM__
		<MENUITEM_ID>MENU_ID_FMRDO_SETTINGS</MENUITEM_ID>
		#endif
		<MENUITEM_ID>MENU_ID_FMRDO_SCHEDULER_MENU</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_RECORD</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_FILE_LIST</MENUITEM_ID>
		#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__) && defined(__MMI_FM_RADIO_LOUD_SPEAK__)
		<MENUITEM_ID>MENU_ID_FMRDO_LOUD_SPEAKER_ON</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_LOUD_SPEAKER_OFF</MENUITEM_ID>
		#endif
	</MENU>
#endif
	<MENUITEM id="MENU_ID_FMRDO_CHANNEL_OPT_PLAY" str="STR_GLOBAL_PLAY"/>
	<MENUITEM id="MENU_ID_FMRDO_CHANNEL_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
	<MENUITEM id="MENU_ID_FMRDO_CHANNEL_OPT_EDIT" str="STR_GLOBAL_EDIT"/>

	<MENU id="MENU_ID_FMRDO_CHANNEL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_ID_FMRDO_CHANNEL_OPT_PLAY</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_CHANNEL_OPT_DELETE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_CHANNEL_OPT_EDIT</MENUITEM_ID>
	</MENU>
	
#ifdef __MMI_FM_RADIO_SCHEDULER__
	<!--Menu Item Area-->
	<MENUITEM id="MENU_ID_FMRDO_SCHEDULER_CHANNEL_LIST" str="STR_ID_FMRDO_CHANNEL_LIST" img="@OID:IMG_GLOBAL_L2" highlight="mmi_fmrdo_scheduler_highlight_channel_list"/>
	<MENUITEM id="MENU_ID_FMRDO_SCHEDULER_MANUAL_INPUT" str="STR_ID_FMRDO_SCHEDULER_MANUAL_INPUT" img="@OID:IMG_GLOBAL_L1" highlight="mmi_fmrdo_scheduler_highlight_manual_input"/>

	<!--Menu Tree Area-->
	<MENU id="MENU_ID_FMRDO_SCHEDULER_CHANNEL_SETTINGS" type="OPTION" parent="0" str="@OID:STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_ID_FMRDO_SCHEDULER_CHANNEL_LIST</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_FMRDO_SCHEDULER_MANUAL_INPUT</MENUITEM_ID>
	</MENU>
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->	
	
	<SCREEN id="GRP_ID_FMRDO"/>	
	<SCREEN id="SCR_ID_FMRDO_BASE"/>
	<SCREEN id="SCR_ID_FMRDO_MAIN"/>
	<SCREEN id="SCR_ID_FMRDO_MAIN_OPTION"/>
	<SCREEN id="SCR_ID_FMRDO_CHANNEL_LIST"/>
	<SCREEN id="SCR_ID_FMRDO_MANUAL_INPUT"/>
	<SCREEN id="SCR_ID_FMRDO_PRESET_LIST_CONFIRM"/>
	#ifndef __MMI_FM_PLUTO_SLIM__
	<SCREEN id="SCR_ID_FMRDO_SETTINGS"/>
	#endif
	<SCREEN id="SCR_ID_FMRDO_CHANNEL_OPTION"/>
	<SCREEN id="SCR_ID_FMRDO_SEARCHING"/>
	#ifdef __MMI_FM_VIA_A2DP__
	<SCREEN id="SCR_ID_FMRDO_A2DP_CONNECTING"/>
	#endif
	<SCREEN id="SCR_ID_FMRDO_SUBLCD_MAIN"/>
	<SCREEN id="SCR_ID_FMRDO_SUBLCD_OPTION"/>
	<SCREEN id="SCR_ID_FMRDO_SUBLCD_SEARCHING"/>
	
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_LIST"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_RENAME"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_OPTIONS"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_EDITOR"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_SETTINGS"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_CHANNEL_OPTIONS"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_SETTINGS_REPEAT"/>
	<SCREEN id="SCR_ID_FMRDO_SCHEDULE_ALARM_PLAYING"/>


	<SCREEN id="SCR_ID_FMRDO_RDS_SETTINGS"/>
	
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Receiving Evt ID -->
	
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_fmrdo_earphone_notify_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_fmrdo_earphone_notify_hdlr"/>
	
	#ifdef __MMI_FM_RADIO_RECORD__
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_fmgr_fmrdo_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_fmgr_fmrdo_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_fmgr_fmrdo_notify_hdlr"/>	
	#endif /*__MMI_FM_RADIO_RECORD__*/
        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_fmrdo_main_scrn_proc"/>
        #if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
        <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_fmrdo_scrlocker_event_notify_handler"/>
        #endif

        <RECEIVER id="EVT_ID_SRV_PROF_IS_PLAYING" proc="mmi_fmrdo_is_power_on_callback_hdlr"/>
	#ifdef __DM_LAWMO_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="mmi_fmrdo_lawmo_lock_notify_hdlr"/>
	#endif /*__DM_LAWMO_SUPPORT__*/

	#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
  <RECEIVER id="EVT_ID_SRV_A2DP_CONNECT" proc="mmi_fmrdo_a2dp_connect_callback_hdlr"/>
	#endif

	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Sending Evt ID -->
	 
	<EVENT id="EVT_ID_FMRDO_A2DP_CONNECT" type="SENDER"/>
	
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--NVRAM LID -->
	 
	    <CACHEDATA type="byte" id="NVRAM_FMRDO_BACKGROUND_PLAY" restore_flag="TRUE">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_FMRDO_BACKGROUND_PLAY] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_SKIN" restore_flag="TRUE">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_FMRDO_SKIN] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_VOLUME" restore_flag="TRUE">
        <DEFAULT_VALUE> [FACTORY_RESTORE_DEFAULT_FMRDO_VOLUME] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - volume </DESCRIPTION>
        <FIELD min="0" max="6"></FIELD>
    </CACHEDATA>

        <CACHEDATA type="byte" id="NVRAM_FMRDO_RECORD_FORMAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - rec forma </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_RECORD_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - rec storage </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_FMRDO_SPEAKER_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - speaker status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_RDS_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio RDS- main status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_RDS_TP_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio RDS- tp status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_RDS_AF_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio RDS- af status </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_FMRDO_RECORD_QUALITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - rec quality </DESCRIPTION>
        <FIELD>
           <OPTION hint = "Low"> [0x00] </OPTION>
           <OPTION hint = "High"> [0x01] </OPTION>
        </FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_FMRDO_CHANNEL_MONO" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - channel </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_FMRDO_MUTE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_FMRDO_MUTE </DESCRIPTION>
    </CACHEDATA>
        <CACHEDATA type="short" id="NVRAM_FMRDO_LAST_CHANNEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> FM Radio - rec last channel </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_FM_FM_RADIO_CHANNEL_1">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FM_FM_RADIO_CHANNEL_2">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_FM_FM_RADIO_CHANNEL_3">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    <TIMER id="FMRDO_TWINKLE_FREQUENCY_TIMER"/>
    <TIMER id="FMRDO_REPEAT_STEP_TIMER"/>
#ifdef __MMI_FTE_SUPPORT__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    <TIMER id="FMRDO_VOLUME_DISPLAY_TMER"/>
#endif 
#endif 
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
  <TIMER id="FMRDO_DISPLAY_BUTTON_TMER"/>
#endif

<!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->
</APP>

#endif /* __MMI_FM_RADIO__ */
#endif /* __MMI_BTBOX_NOLCD__ */
