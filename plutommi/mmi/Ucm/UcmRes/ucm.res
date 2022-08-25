/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#ifdef __MMI_TELEPHONY_SUPPORT__
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_UCM"
#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__)
    package_name = "native.mtk.ucm"
    name = "STR_ID_UCM_VIDEO_CALL"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MMI_ICON
    img = "IMG_ID_UCM_VT_APPMGR_MAIN_ICON"
#endif /* defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) */
    launch = "mmi_ucm_vt_appmgr_launch"
#endif /* defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__) */
>

    <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="mmi_rp_app_ucm_def.h"/>
    <INCLUDE file="ConnectivityResDef.h"/>
#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
    <INCLUDE file="ServiceDefs.h"/>
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
#ifdef __MMI_BG_SOUND_EFFECT__
    <INCLUDE file="mmi_rp_app_bgsound_def.h"/>
#endif
#ifdef __VOICE_CHANGER_SUPPORT__
    <INCLUDE file="mmi_rp_app_callset_def.h"/>
#endif

    <INCLUDE file="mmi_rp_srv_editor_def.h"/> 

    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/> 

    <!-- 
    ***************************************************************
    Callback mgnt Area
    ***************************************************************
    -->
    #ifdef __MMI_DIALER_CUI_SUPPORT__
  <RECEIVER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" proc="vm_ivr_handler"/>
	<RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="vm_ivr_handler"/>
	<RECEIVER id="EVT_ID_SRV_UCM_STATUS_CHANGE" proc="vm_ivr_handler"/>
	#endif
	
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_ucm_flight_mode_processing_hdlr"/>    
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" proc="mmi_ucm_flight_mode_processing_hdlr"/>    
	<RECEIVER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" proc="mmi_ucm_act_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_ucm_ind_hdlr"/>
#ifdef __MMI_URI_AGENT__	
	<RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_ucm_uha_ind_hdlr"/>
#endif /* __MMI_URI_AGENT__ */	
    <RECEIVER id="EVT_ID_SRV_UCM_CNF_INDICATION" proc="mmi_ucm_conf_ind_hdlr"/>

    <RECEIVER id="EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND" proc="mmi_ucm_speech_status_ind_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_EXT_DEV_KEY_1" proc="mmi_ucm_headset_key_hdlr"/>

#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_ucm_remove_cipher_icon"/>
	<RECEIVER id="EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED" proc="mmi_ucm_update_cipher_icon"/>
#endif	
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_BACKGROUND_CALL__)
    <RECEIVER id="EVT_ID_SRV_UCM_APP_EXIT_QUERY" proc="mmi_ucm_if_ucm_exit_callback"/>
#endif /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_BACKGROUND_CALL__) */
#ifdef __PXS_APP_ENABLE__
	<RECEIVER id="EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE" proc="mmi_ucm_pxs_detect_obj_close_hdlr"/>
	<RECEIVER id="EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY" proc="mmi_ucm_pxs_detect_obj_away_hdlr"/>
#endif /* __PXS_APP_ENABLE__ */
#ifdef __OP01_FWPBW__
	<RECEIVER id="EVT_ID_GPIO_TRANSMITTER_HOLD_ON" proc="mmi_ucm_transmitter_status_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_TRANSMITTER_PUT_DOWN" proc="mmi_ucm_transmitter_status_hdlr"/>
#endif /* __OP01_FWPBW__ */
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_ucm_sim_availability_changed_hdlr"/>

#ifdef MOTION_SENSOR_SUPPORT
    <RECEIVER id="EVT_ID_SRV_FLIP_TO_MUTE_CALL" proc="mmi_ucm_motion_setting_change_hdlr"/>
#if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
    <RECEIVER id="EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL" proc="mmi_ucm_motion_setting_change_hdlr"/>
#endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */
#endif /* MOTION_SENSOR_SUPPORT */

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_ucm_process_screen_lock"/>
#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
    <RECEIVER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" proc="mmi_ucm_backlight_turn_off_query_hdlr"/>

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__)
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_ucm_mode_switch_hdlr"/>
#endif /* defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__) */
#if defined(__MMI_NCENTER_SUPPORT__) 
    <RECEIVER id="EVT_ID_VAPP_NCENTER_DRAG" proc="mmi_ucm_ncenter_drag_hdlr"/>
#endif /* defined(__MMI_NCENTER_SUPPORT__) */

    <!-- 
    ***************************************************************
    NVRAM Area
    ***************************************************************
    -->
#ifdef __MMI_VIDEO_TELEPHONY__
    <CACHEDATA type="byte" id="NVRAM_VT_ANSWER_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VT answer mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VT_DIAL_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VT dial mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VT_AUDIO_OPT_MIC" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VT microphone </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VT_AUDIO_OPT_SPEAKER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VT speaker </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_VT_MIRROR" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT Mirror </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VT_VIDEO_QUALITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> VT video quality </DESCRIPTION>
    </CACHEDATA>    
    
    <CACHEDATA type="byte" id="NVRAM_VT_AUTO_REDIAL_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> VT video auto redial setting </DESCRIPTION>
    </CACHEDATA>

#ifdef __OP01__
    <CACHEDATA type="byte" id="NVRAM_VT_INCALL_IMAGE_STATE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> VT video incall pic state setting</DESCRIPTION>
    </CACHEDATA>
#endif /* __OP01__ */

#endif /* __MMI_VIDEO_TELEPHONY__ */

    <!-- 
    ***************************************************************
    TIMER Area
    ***************************************************************
    -->

    <TIMER id="UCM_NOTIFY_DURATION_TIMER"/>
    <TIMER id="UCM_FTE_AUTO_LOCK_TIMER_ID"/>
    <TIMER id="UCM_VT_FALL_TO_VOICE_NOTIFY_TIMER_ID"/>
    <TIMER id="VT_START_CAMERA_QUERY_TIMER"/>
    <TIMER id="CM_UPDATE_NCENTER_TIMER"/>
    <TIMER id="TIMER_ID_UCM_DELAY_RING"/>


    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    
#ifdef __MMI_VIDEO_TELEPHONY__
    <STRING id="STR_ID_UCM_VT_MAKE_VIDEO_CALL"/>
    <STRING id="STR_ID_UCM_VT_START_CAMERA"/>
    <STRING id="STR_ID_UCM_VT_STOP_CAMERA"/>
    <STRING id="STR_ID_UCM_VT_USE_MAIN_CAMERA"/>
    <STRING id="STR_ID_UCM_VT_USE_SUB_CAMERA"/>
    <STRING id="STR_ID_UCM_VT_TURN_ON_NIGHT_MODE"/>
    <STRING id="STR_ID_UCM_VT_TURN_OFF_NIGHT_MODE"/>
    <STRING id="STR_ID_UCM_VT_MUTE_MIC"/>
    <STRING id="STR_ID_UCM_VT_UNMUTE_MIC"/>
    <STRING id="STR_ID_UCM_VT_MUTE_SPEAKER"/>
    <STRING id="STR_ID_UCM_VT_UNMUTE_SPEAKER"/>
    <STRING id="STR_ID_UCM_VT_SWITCH_PIC"/>
    <STRING id="STR_ID_UCM_VT_HIDE_SMALL_PIC"/>
    <STRING id="STR_ID_UCM_VT_UNHIDE_SMALL_PIC"/>
    <STRING id="STR_ID_UCM_VT_ALTERNATIVE_PIC"/>
    <STRING id="STR_ID_UCM_VIDEO_CALL_SETTING"/>
    <STRING id="STR_ID_UCM_VT_ADVANCED"/>
    <STRING id="STR_ID_UCM_VT_SWTICH_TO_VOICE_CALL"/>
    <STRING id="STR_ID_UCM_VT_SWTICH_TO_VOICE_CALL_QUERY"/>
    <STRING id="STR_ID_UCM_VT_ANSWER_MODE"/>
    <STRING id="STR_ID_UCM_VT_DIAL_MODE"/>
#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) 
    <STRING id="STR_ID_UCM_VT_AUTO_REDIAL_MODE"/>
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */    
#ifdef __OP01__ 
    <STRING id="STR_ID_UCM_VT_FALL_TO_VOICE_NOTIFY"/>
    <STRING id="STR_ID_UCM_VT_FALL_TO_VOICE_END_CAUSE"/>
#endif /* __OP01__ */
    <STRING id="STR_ID_UCM_VT_IMAGE_IN_VIDEO_CALL"/>
#ifdef __OP01__
    <STRING id="STR_ID_UCM_VT_REMOTE_IMAGE_IN_VIDEO_CALL"/>
#endif /* __OP01__ */
    <STRING id="STR_ID_UCM_VT_AUDIO_OPTION"/>
    <STRING id="STR_ID_UCM_VT_PROMPT"/>
    <STRING id="STR_ID_UCM_VT_MIC_OFF"/>
    <STRING id="STR_ID_UCM_VT_SPEAKER_OFF"/>
    <STRING id="STR_ID_UCM_VT_START_CALL_WITH"/>
    <STRING id="STR_ID_UCM_VT_DEFAULT"/>
    <STRING id="STR_ID_UCM_VT_USER_DEFINE"/>
    <STRING id="STR_ID_UCM_VT_FAIL_TO_MAKE_VIDEO_CALL"/>
    <STRING id="STR_ID_UCM_VT_REDIAL_VIDEO_CALL"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_UCM_VT_REDIAL_SIM1_VIDEO_CALL"/>
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    <STRING id="STR_ID_UCM_VT_VIDEO_QUALITY"/>
    <STRING id="STR_ID_UCM_VT_SMOOTH"/>
    <STRING id="STR_ID_UCM_VT_NORMAL"/>
    <STRING id="STR_ID_UCM_VT_SHARP"/>
    <STRING id="STR_ID_UCM_VT_START_CAMERA_QUERY"/>
    <STRING id="STR_ID_UCM_VT_SWITCH_AUDIO_PATH"/>
    <STRING id="STR_ID_UCM_VT_RSK_HANDS_FREE"/>
    <STRING id="STR_ID_UCM_VT_RSK_HANDS_HELD"/>
    <STRING id="STR_ID_UCM_SMS"/>
    <STRING id="STR_ID_UCM_SWITCH_TO_VIDEO_CALL"/>
    <STRING id="STR_ID_UCM_SWITCH_TO_VIDEO_CALL_QUERY"/>
    <STRING id="STR_ID_UCM_VIDEO_CALLING"/>
    <STRING id="STR_ID_UCM_VIDEO_INCOMING"/>
    <STRING id="STR_ID_UCM_VIDEO_CALL"/>
#ifdef __MMI_3G_SWITCH__
	<STRING id="STR_ID_UCM_VIDEO_CALLING_SIM1"/>
	<STRING id="STR_ID_UCM_VIDEO_CALLING_SIM2"/>
    <STRING id="STR_ID_UCM_VIDEO_INCOMING_SIM1"/>
    <STRING id="STR_ID_UCM_VIDEO_INCOMING_SIM2"/>
#endif /* __MMI_3G_SWITCH__ */
    <STRING id="STR_ID_UCM_VT_PEER_CAMERA_OFF">"Peer camera off"</STRING>
    <STRING id="STR_ID_UCM_VT_PEER_CAMERA_ON">"Peer camera on"</STRING>
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_FTE_SUPPORT__
    <STRING id="STR_ID_UCM_TOUCH_TO_UNLOCK"/>
#endif /* __MMI_FTE_SUPPORT__ */
#if !defined(__MMI_UCM_SLIM__) || defined(__MMI_FTE_SUPPORT__)
    <STRING id="STR_ID_UCM_DIALER"/>
#endif /* !defined(__MMI_UCM_SLIM__) || defined(__MMI_FTE_SUPPORT__) */
#ifdef __MMI_VOIP__
    <STRING id="STR_ID_UCM_VOIP_CALLING"/>
    <STRING id="STR_ID_UCM_VOIP_CALL"/>
#endif /* __MMI_VOIP__ */

    <STRING id="STR_ID_UCM_CALLING"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_UCM_VOICE_CALLING_SIM1"/>
    <STRING id="STR_ID_UCM_VOICE_CALLING_SIM2"/>
    <STRING id="STR_ID_UCM_VOICE_INCOMING_SIM1"/>
    <STRING id="STR_ID_UCM_VOICE_INCOMING_SIM2"/>
    <STRING id="STR_ID_UCM_SIM1_VOICE_CALL"/>
    <STRING id="STR_ID_UCM_SIM2_VOICE_CALL"/>
    <STRING id="STR_ID_UCM_SIM1_VOICE_ACTIVE"/>
    <STRING id="STR_ID_UCM_SIM1_VOICE_HOLD"/>
    <STRING id="STR_ID_UCM_SIM2_VOICE_ACTIVE"/>
    <STRING id="STR_ID_UCM_SIM2_VOICE_HOLD"/>
#if defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__)
    <STRING id="STR_ID_UCM_REDIAL_SIM1_VOICE_CALL"/>
    <STRING id="STR_ID_UCM_REDIAL_SIM2_VOICE_CALL"/>
#endif /* defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__) */
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_UCM_VOICE_CALLING_SIM3"/>
    <STRING id="STR_ID_UCM_VOICE_INCOMING_SIM3"/>
    <STRING id="STR_ID_UCM_SIM3_VOICE_ACTIVE"/>
    <STRING id="STR_ID_UCM_SIM3_VOICE_HOLD"/>
    <STRING id="STR_ID_UCM_SIM3_VOICE_CALL"/>
#if defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__)
	<STRING id="STR_ID_UCM_REDIAL_SIM3_VOICE_CALL"/>
#endif /* defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__) */
#if (MMI_MAX_SIM_NUM == 4)
    <STRING id="STR_ID_UCM_VOICE_CALLING_SIM4"/>
    <STRING id="STR_ID_UCM_VOICE_INCOMING_SIM4"/>
    <STRING id="STR_ID_UCM_SIM4_VOICE_ACTIVE"/>
    <STRING id="STR_ID_UCM_SIM4_VOICE_HOLD"/>
    <STRING id="STR_ID_UCM_SIM4_VOICE_CALL"/>
#if defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__)
	<STRING id="STR_ID_UCM_REDIAL_SIM4_VOICE_CALL"/>
#endif /* defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__) */
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_UCM_VOICE_ACTIVE"/>
    <STRING id="STR_ID_UCM_VOICE_HOLD"/>
#if defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__)
    <STRING id="STR_ID_UCM_REDIAL_VOICE_CALL"/>
#endif /* defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__) */
#endif /* (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */

    <STRING id="STR_ID_UCM_REJECT"/>

#if defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined (__MMI_FTE_SUPPORT__)
    <STRING id="STR_ID_UCM_SILENT"/>
#endif /* __MMI_UCM_RSK_SUPPRESS_RING__ || __MMI_FTE_SUPPORT__ */
    <STRING id="STR_ID_UCM_ANSWER"/>
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    <STRING id="STR_ID_UCM_ANSWER_BY_VOICE"/>
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))*/
#ifdef __MMI_UCM_DEFLECT__
    <STRING id="STR_ID_UCM_DEFLECT"/>
#endif /* __MMI_UCM_DEFLECT__ */
#ifdef __MMI_BG_SOUND_EFFECT__
    <STRING id="STR_ID_UCM_CALL_BACKGROUND_SOUND"/>
#endif /* __MMI_BG_SOUND_EFFECT__ */
    <STRING id="STR_ID_UCM_HAND_HELD"/>
    <STRING id="STR_ID_UCM_HAND_FREE"/>
#ifdef __MMI_VOIP__
    <STRING id="STR_ID_UCM_VOIP_ACTIVE"/>
    <STRING id="STR_ID_UCM_VOIP_HOLD"/>
#endif /* __MMI_VOIP__ */

    <STRING id="STR_ID_UCM_PROCESSING"/>
    <STRING id="STR_ID_UCM_NOT_ALLOW_TO_HOLD"/>
    <STRING id="STR_ID_UCM_NOT_ALLOW_TO_SWAP"/>
    <STRING id="STR_ID_UCM_HOLD"/>
    <STRING id="STR_ID_UCM_RETRIEVE"/>
    <STRING id="STR_ID_UCM_SWAP"/>
    <STRING id="STR_ID_UCM_CONFERENCE"/>
    <STRING id="STR_ID_UCM_SPLIT"/>
    <STRING id="STR_ID_UCM_END_SINGLE"/>
    <STRING id="STR_ID_UCM_END_CONFERENCE"/>
    <STRING id="STR_ID_UCM_END_ALL"/>
    <STRING id="STR_ID_UCM_END_CALL"/>
#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
    <STRING id="STR_ID_UCM_TRANSFER"/>
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */
#ifndef __MMI_UCM_SLIM__
    <STRING id="STR_ID_UCM_NEW_CALL"/>
#endif /* __MMI_UCM_SLIM__ */
    <STRING id="STR_ID_UCM_PHONEBOOK"/>
#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
    <STRING id="STR_ID_UCM_BROWSER"/>
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
#ifdef __MMI_SOUND_RECORDER__
    <STRING id="STR_ID_UCM_SOUND_RECORDER"/>
#endif /* __MMI_SOUND_RECORDER__ */   
#ifdef __MMI_BG_SOUND_EFFECT__  
    <STRING id="STR_ID_UCM_BACKGROUND_SOUND"/>
#endif /*__MMI_BG_SOUND_EFFECT__*/
#ifdef __SLIM_UCM__
    <STRING id="STR_ID_UCM_UNMUTE"/>
#endif
#if defined(__MMI_UCM_RSK_MUTE__) || defined (__MMI_FTE_SUPPORT__)
#ifndef __SLIM_UCM__
    <STRING id="STR_ID_UCM_UNMUTE"/>
#endif
    <STRING id="STR_ID_UCM_MUTE_ON"/>
    <STRING id="STR_ID_UCM_MUTE_OFF"/>
#endif /* __MMI_UCM_RSK_MUTE__ || __MMI_FTE_SUPPORT__ */
#if defined(__MMI_URI_AGENT__) || !defined(__MMI_UCM_SLIM__)
    <STRING id="STR_ID_UCM_DTMF"/>
#endif /* defined(__MMI_URI_AGENT__) || !defined(__MMI_UCM_SLIM__) */

#if (MMI_MAX_SIM_NUM != 2) || !defined(__MMI_UCM_SLIM__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_UCM_VOICE_CALL"/>
#endif /* (MMI_MAX_SIM_NUM != 2) || !defined(__MMI_UCM_SLIM__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
#ifdef __MMI_BT_SUPPORT__
    <STRING id="STR_ID_UCM_SWITCH_AUDIO_PATH"/>
#endif /* __MMI_BT_SUPPORT__ */
    <STRING id="STR_ID_UCM_ACTIVE"/>
#ifdef __MMI_BT_CALL_SUPPORT__
    <STRING id="STR_ID_UCM_CALL_SELECT"/>
    <STRING id="STR_ID_UCM_FROM_LOCAL_CALL"/>
    <STRING id="STR_ID_UCM_FROM_BT_CALL"/>
#endif /* __MMI_BT_CALL_SUPPORT__ */
#ifdef __CTM_SUPPORT__
    <STRING id="STR_ID_UCM_CTM_CONNECT"/>
    <STRING id="STR_ID_UCM_CTM_SETTING"/>
#endif /* __CTM_SUPPORT__ */
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
    <STRING id="STR_ID_UCM_REDIAL_FROM_OTHER_SIM"/>
#endif
    <STRING id="STR_ID_UCM_END_ALL_ACTIVE"/>
    <STRING id="STR_ID_UCM_END_ALL_HELD"/>
#if defined(__MMI_URI_AGENT__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    <STRING id="STR_ID_UCM_QUESTION_MARK"/>
#endif /* defined(__MMI_URI_AGENT__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
#ifdef __MMI_URI_AGENT__
    <STRING id="STR_ID_UCM_SENDING_DTMF"/>
#endif /* __MMI_URI_AGENT__ */

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    <STRING id="STR_ID_UCM_HOMESCREEN"/>
    <STRING id="STR_ID_UCM_BACKGROUND"/>
    <STRING id="STR_ID_UCM_NCENTER_TITLE"/>
    <STRING id="STR_ID_UCM_NCENTER_MAINTEXT_ACTIVE"/>
    <STRING id="STR_ID_UCM_NCENTER_MAINTEXT_HELD"/>
    <STRING id="STR_ID_UCM_NCENTER_SUBTEXT_CONFERENCE"/>
    <STRING id="STR_ID_UCM_END_THIS_CALL_Q_MARK"/>
    
#else  /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */
#if defined(__MMI_BACKGROUND_CALL__)
    <STRING id="STR_ID_UCM_MAIN_MENU"/>
#endif /* __MMI_BACKGROUND_CALL__ */
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

#ifdef __MMI_UCM_REJECT_BY_SMS__
    <STRING id="STR_ID_UCM_REJ_BY_SMS"/>
    <STRING id="STR_ID_UCM_REJ_BY_SMS_CONFIRM"/>
    <STRING id="STR_ID_UCM_REJ_BY_SMS_DEFAULT_MSG"/>
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
    <STRING id="STR_ID_UCM_FAIL_TO_MAKE_VOICE_CALL"/>
#endif /*__MMI_UCM_MO_FAIL_POST_ACTION__ */
#ifdef __MMI_VIDEO_TELEPHONY__
    <STRING id="STR_ID_UCM_OUT_OF_3G_COVERAGE"/>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#ifdef __MMI_UCM_ECT__
    <STRING id="STR_ID_UCM_ECT_CONFIRM_QUERY"/>
#endif /* __MMI_UCM_ECT__ */
#ifdef __MMI_DUAL_MIC_SUPPORT__
    <STRING id="STR_ID_UCM_ENABLE_NOICE_REDUCTION"/>
    <STRING id="STR_ID_UCM_DISABLE_NOICE_REDUCTION"/>
    <STRING id="STR_ID_UCM_ENABLED"/> 
    <STRING id="STR_ID_UCM_DISABLED"/>
#endif /* __MMI_DUAL_MIC_SUPPORT__ */ 

#ifdef __OP01_FWPBW__
    <STRING id="STR_ID_UCM_HANGUP"/>
    <STRING id="STR_ID_UCM_VOLUME"/>
#endif /* __OP01_FWPBW__ */

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    <STRING id="STR_ID_UCM_SIM_SELECT"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_UCM_FROM_SIM1"/>
    <STRING id="STR_ID_UCM_FROM_SIM2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_UCM_FROM_SIM3"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_UCM_FROM_SIM4"/>
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
#if defined(__MMI_MAINLCD_128X160__)
    <STRING id="STR_ID_UCM_ACCEPT"/>
#endif /* __MMI_MAINLCD_128X160__ */
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
#ifdef __MMI_VIDEO_TELEPHONY__

/* please syn with resource_vt_skins.h or merge one place */
#ifdef  __MMI_FTE_SUPPORT__
#if defined(__MMI_MAINLCD_320X480__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__)
#define __MMI_FTE_VT_ENHANCE__
#endif
#if defined(__MMI_MAINLCD_240X320__)
#define __MMI_FTE_VT_SUBWND_BG__
#endif
#endif
#if defined(__MMI_TOUCH_SCREEN__)&& (defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__))
#define __MMI_TOUCH_OP01__
#endif
#if defined(__MMI_FTE_VT_ENHANCE__)
#define IMAGE_FORMAT png
#else
#define IMAGE_FORMAT bmp
#endif

    #define VT_OSD_PATH	CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\"
	<IMAGE id="IMG_ID_UCM_VT_BG_STATUS">VT_OSD_PATH"VT_bg_status."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BG_TITLE">VT_OSD_PATH"VT_bg_title."IMAGE_FORMAT""</IMAGE>

	#if defined(__MMI_FTE_VT_ENHANCE__)&& defined (__OP01__)
	<IMAGE id="IMG_ID_UCM_VT_BG_BODY">VT_OSD_PATH"VT_bg_body_CMCC."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BG_PANEL_0">VT_OSD_PATH"VT_bg_CMCC_panel_0."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_BG">VT_OSD_PATH"VT_contrast_BG."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_OP01_ICON_BG">VT_OSD_PATH"VT_CMCC_BG."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SINGLE_ICON_BG">VT_OSD_PATH"VT_CMCC_fullscreen_BG."IMAGE_FORMAT""</IMAGE>
	#else
	<IMAGE id="IMG_ID_UCM_VT_BG_BODY">VT_OSD_PATH"VT_bg_body."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BG_PANEL_0">VT_OSD_PATH"VT_bg_panel_0."IMAGE_FORMAT""</IMAGE>
	#endif

	#if defined(__MMI_FTE_VT_SUBWND_BG__)
		<IMAGE id="IMG_ID_UCM_VT_SUBWND_BG">VT_OSD_PATH"VT_fg."IMAGE_FORMAT""</IMAGE>	
	#endif
	
	#if defined(__OP01__)
	  <IMAGE id="IMG_ID_UCM_VT_FULLSCREEN_BG">VT_OSD_PATH"Fullscreen_BG_black.PNG"</IMAGE>
	#endif
	
#if defined(__MMI_MAINLCD_176X220__)
	<IMAGE id="IMG_ID_UCM_VT_BG_PANEL_0_SHORT">VT_OSD_PATH"VT_bg_panel_0_short."IMAGE_FORMAT""</IMAGE>
#endif
	<IMAGE id="IMG_ID_UCM_VT_BG_PANEL_1">VT_OSD_PATH"VT_bg_panel_1."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BG_SOFTKEY">VT_OSD_PATH"VT_bg_softkey."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BG_SUB">VT_OSD_PATH"VT_bg_sub."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MAIN_WND_LOCAL">VT_OSD_PATH"VT_main_wnd_local.gif"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MAIN_WND_PEER">VT_OSD_PATH"VT_main_wnd_peer.gif"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SUB_WND_LOCAL">VT_OSD_PATH"VT_sub_wnd_local.gif"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SUB_WND_PEER">VT_OSD_PATH"VT_sub_wnd_peer.gif"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ICON_HIGHLIGHT">VT_OSD_PATH"VT_icon_highlight."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_OFF">VT_OSD_PATH"VT_camera_off."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_OFF_PRESS">VT_OSD_PATH"VT_camera_off_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_OFF_DISABLE">VT_OSD_PATH"VT_camera_off_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_ON">VT_OSD_PATH"VT_camera_on."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_ON_PRESS">VT_OSD_PATH"VT_camera_on_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_ON_DISABLE">VT_OSD_PATH"VT_camera_on_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_FRONT">VT_OSD_PATH"VT_camera_front."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_FRONT_PRESS">VT_OSD_PATH"VT_camera_front_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_FRONT_DISABLE">VT_OSD_PATH"VT_camera_front_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_BACK">VT_OSD_PATH"VT_camera_back."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_BACK_PRESS">VT_OSD_PATH"VT_camera_back_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CAMERA_BACK_DISABLE">VT_OSD_PATH"VT_camera_back_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MIC_ON">VT_OSD_PATH"VT_mic_on."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MIC_ON_PRESS">VT_OSD_PATH"VT_mic_on_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MIC_ON_DISABLE">VT_OSD_PATH"VT_mic_on_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MIC_OFF">VT_OSD_PATH"VT_mic_off."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MIC_OFF_PRESS">VT_OSD_PATH"VT_mic_off_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_MIC_OFF_DISABLE">VT_OSD_PATH"VT_mic_off_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SPEAKER_ON">VT_OSD_PATH"VT_speaker_on."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SPEAKER_ON_PRESS">VT_OSD_PATH"VT_speaker_on_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SPEAKER_ON_DISABLE">VT_OSD_PATH"VT_speaker_on_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SPEAKER_OFF">VT_OSD_PATH"VT_speaker_off."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SPEAKER_OFF_PRESS">VT_OSD_PATH"VT_speaker_off_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SPEAKER_OFF_DISABLE">VT_OSD_PATH"VT_speaker_off_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_AUD_REC_ON">VT_OSD_PATH"VT_aud_rec_on."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_AUD_REC_ON_PRESS">VT_OSD_PATH"VT_aud_rec_on_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_AUD_REC_ON_DISABLE">VT_OSD_PATH"VT_aud_rec_on_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_AUD_REC_OFF">VT_OSD_PATH"VT_aud_rec_off."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_AUD_REC_OFF_PRESS">VT_OSD_PATH"VT_aud_rec_off_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_AUD_REC_OFF_DISABLE">VT_OSD_PATH"VT_aud_rec_off_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV">VT_OSD_PATH"VT_ev."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV_PRESS">VT_OSD_PATH"VT_ev_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV_DISABLE">VT_OSD_PATH"VT_ev_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM">VT_OSD_PATH"VT_zoom."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM_PRESS">VT_OSD_PATH"VT_zoom_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM_DISABLE">VT_OSD_PATH"VT_zoom_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SNAPSHOT">VT_OSD_PATH"VT_snapshot."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SNAPSHOT_PRESS">VT_OSD_PATH"VT_snapshot_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SNAPSHOT_DISABLE">VT_OSD_PATH"VT_snapshot_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM_IN">VT_OSD_PATH"VT_zoom_in."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM_IN_PRESS">VT_OSD_PATH"VT_zoom_in_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM_OUT">VT_OSD_PATH"VT_zoom_out."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_ZOOM_OUT_PRESS">VT_OSD_PATH"VT_zoom_out_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV_INC">VT_OSD_PATH"VT_ev_inc."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV_INC_PRESS">VT_OSD_PATH"VT_ev_inc_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV_DEC">VT_OSD_PATH"VT_ev_dec."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_EV_DEC_PRESS">VT_OSD_PATH"VT_ev_dec_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VOL_UP">VT_OSD_PATH"VT_vol_up."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VOL_UP_PRESS">VT_OSD_PATH"VT_vol_up_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VOL_DOWN">VT_OSD_PATH"VT_vol_down."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VOL_DOWN_PRESS">VT_OSD_PATH"VT_vol_down_press."IMAGE_FORMAT""</IMAGE>

#if defined (__OP01__)
	#if defined(__MMI_FTE_VT_ENHANCE__)
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_UP">VT_OSD_PATH"VideoTelephony\\\\VT_Bright_up.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_UP_PRESS">VT_OSD_PATH"VideoTelephony\\\\VT_Bright_up_press.png"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_DOWN">VT_OSD_PATH"VideoTelephony\\\\VT_Bright_down.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_DOWN_PRESS">VT_OSD_PATH"VideoTelephony\\\\VT_Bright_down_press.png"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_ENHANCE">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_enhance.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_ENHANCE_PRESS">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_enhance_press.png"</IMAGE>    
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_NORMAL">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_normal.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_NORMAL_PRESS">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_normal_press.png"</IMAGE>   
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_RESUCED">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_reduced.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_RESUCED_PRESS">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_reduced_press.png"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_FULLSCR_ICON">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_fullscreen.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_FULLSCR_ICON_PRESS">VT_OSD_PATH"VideoTelephony\\\\VT_contrast_fullscreen_press.png"</IMAGE> 
	#elif defined(__MMI_TOUCH_OP01__)
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_UP">VT_OSD_PATH"VT_Bright_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_UP_PRESS">VT_OSD_PATH"VT_Bright_up_press.bmp"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_DOWN">VT_OSD_PATH"VT_Bright_down.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_DOWN_PRESS">VT_OSD_PATH"VT_Bright_down_press.bmp"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_ENHANCE">VT_OSD_PATH"VT_contrast_enhance.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_ENHANCE_PRESS">VT_OSD_PATH"VT_contrast_enhance_press.bmp"</IMAGE>    
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_NORMAL">VT_OSD_PATH"VT_contrast_normal.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_NORMAL_PRESS">VT_OSD_PATH"VT_contrast_normal_press.bmp"</IMAGE>   
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_RESUCED">VT_OSD_PATH"VT_contrast_reduced.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_RESUCED_PRESS">VT_OSD_PATH"VT_contrast_reduced_press.bmp"</IMAGE> 
	<IMAGE id="IMG_ID_UCM_VT_FULLSCR_ICON">VT_OSD_PATH"VT_contrast_fullscreen.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_FULLSCR_ICON_PRESS">VT_OSD_PATH"VT_contrast_fullscreen_press.bmp"</IMAGE>  
	#else 
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_UP">VT_OSD_PATH"VT_Bright_up.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_UP_PRESS">VT_OSD_PATH"VT_Bright_up_press.png"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_DOWN">VT_OSD_PATH"VT_Bright_down.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BRIGHTNESS_DOWN_PRESS">VT_OSD_PATH"VT_Bright_down_press.png"</IMAGE>  
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_ENHANCE">VT_OSD_PATH"VT_contrast_enhance.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_ENHANCE_PRESS">VT_OSD_PATH"VT_contrast_enhance_press.png"</IMAGE>    
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_NORMAL">VT_OSD_PATH"VT_contrast_normal.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_NORMAL_PRESS">VT_OSD_PATH"VT_contrast_normal_press.png"</IMAGE>   
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_RESUCED">VT_OSD_PATH"VT_contrast_reduced.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_CONTRAST_RESUCED_PRESS">VT_OSD_PATH"VT_contrast_reduced_press.png"</IMAGE> 
	<IMAGE id="IMG_ID_UCM_VT_FULLSCR_ICON">VT_OSD_PATH"VT_contrast_fullscreen.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_FULLSCR_ICON_PRESS">VT_OSD_PATH"VT_contrast_fullscreen_press.png"</IMAGE>  
	#endif
#endif   
    
	<IMAGE id="IMG_ID_UCM_VT_SCROLL_BAR">VT_OSD_PATH"VT_scroll_bar."IMAGE_FORMAT""</IMAGE>
#if defined(__MMI_MAINLCD_176X220__)
	<IMAGE id="IMG_ID_UCM_VT_SCROLL_BAR_SHORT">VT_OSD_PATH"VT_scroll_bar_short."IMAGE_FORMAT""</IMAGE>
#endif
	<IMAGE id="IMG_ID_UCM_VT_SCROLL_SLIDER">VT_OSD_PATH"VT_scroll_slider."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SNAPSHOTING">VT_OSD_PATH"VT_snapshoting.gif"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_SNAPSHOTING_FAIL">VT_OSD_PATH"VT_snapshoting_fail.gif"</IMAGE>	
	<IMAGE id="IMG_ID_UCM_VT_VK">VT_OSD_PATH"VT_vk."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_PRESS">VT_OSD_PATH"VT_vk_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_DISABLE">VT_OSD_PATH"VT_vk_disable"IMAGE_FORMAT""</IMAGE>
#ifdef __MMI_FTE_SUPPORT__	
	<IMAGE id="IMG_ID_UCM_VT_VK_0">VT_OSD_PATH"VT_vk_0.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_0_PRESS">VT_OSD_PATH"VT_vk_0_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_1">VT_OSD_PATH"VT_vk_1.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_1_PRESS">VT_OSD_PATH"VT_vk_1_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_2">VT_OSD_PATH"VT_vk_2.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_2_PRESS">VT_OSD_PATH"VT_vk_2_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_3">VT_OSD_PATH"VT_vk_3.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_3_PRESS">VT_OSD_PATH"VT_vk_3_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_4">VT_OSD_PATH"VT_vk_4.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_4_PRESS">VT_OSD_PATH"VT_vk_4_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_5">VT_OSD_PATH"VT_vk_5.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_5_PRESS">VT_OSD_PATH"VT_vk_5_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_6">VT_OSD_PATH"VT_vk_6.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_6_PRESS">VT_OSD_PATH"VT_vk_6_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_7">VT_OSD_PATH"VT_vk_7.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_7_PRESS">VT_OSD_PATH"VT_vk_7_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_8">VT_OSD_PATH"VT_vk_8.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_8_PRESS">VT_OSD_PATH"VT_vk_8_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_9">VT_OSD_PATH"VT_vk_9.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_9_PRESS">VT_OSD_PATH"VT_vk_9_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_STAR">VT_OSD_PATH"VT_vk_STAR.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_STAR_PRESS">VT_OSD_PATH"VT_vk_STAR_press.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_POUND">VT_OSD_PATH"VT_vk_HASH.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_POUND_PRESS">VT_OSD_PATH"VT_vk_HASH_press.png"</IMAGE>
#else
	<IMAGE id="IMG_ID_UCM_VT_VK_0">VT_OSD_PATH"VT_vk_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_0_PRESS">VT_OSD_PATH"VT_vk_0_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_1">VT_OSD_PATH"VT_vk_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_1_PRESS">VT_OSD_PATH"VT_vk_1_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_2">VT_OSD_PATH"VT_vk_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_2_PRESS">VT_OSD_PATH"VT_vk_2_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_3">VT_OSD_PATH"VT_vk_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_3_PRESS">VT_OSD_PATH"VT_vk_3_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_4">VT_OSD_PATH"VT_vk_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_4_PRESS">VT_OSD_PATH"VT_vk_4_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_5">VT_OSD_PATH"VT_vk_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_5_PRESS">VT_OSD_PATH"VT_vk_5_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_6">VT_OSD_PATH"VT_vk_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_6_PRESS">VT_OSD_PATH"VT_vk_6_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_7">VT_OSD_PATH"VT_vk_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_7_PRESS">VT_OSD_PATH"VT_vk_7_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_8">VT_OSD_PATH"VT_vk_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_8_PRESS">VT_OSD_PATH"VT_vk_8_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_9">VT_OSD_PATH"VT_vk_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_9_PRESS">VT_OSD_PATH"VT_vk_9_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_STAR">VT_OSD_PATH"VT_vk_star.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_STAR_PRESS">VT_OSD_PATH"VT_vk_star_press.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_POUND">VT_OSD_PATH"VT_vk_pound.bmp"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_VK_POUND_PRESS">VT_OSD_PATH"VT_vk_pound_press.bmp"</IMAGE>
#endif	
	<IMAGE id="IMG_ID_UCM_VT_INPUT_BOX">VT_OSD_PATH"VT_input_box.bmp"</IMAGE>
#if defined(__MMI_MAINLCD_176X220__)
	<IMAGE id="IMG_ID_UCM_VT_INPUT_BOX_SHORT">VT_OSD_PATH"VT_input_box_short.bmp"</IMAGE>
#endif  
#ifdef __MMI_FTE_SUPPORT__
	<IMAGE id="IMG_ID_UCM_VT_OPTION">VT_OSD_PATH"VT_sk_option."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_OPTION_PRESS">VT_OSD_PATH"VT_sk_option_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_OPTION_DISABLE">VT_OSD_PATH"VT_sk_option_disable."IMAGE_FORMAT""</IMAGE> 
	<IMAGE id="IMG_ID_UCM_VT_BACK">VT_OSD_PATH"VT_sk_back."IMAGE_FORMAT""</IMAGE> 
	<IMAGE id="IMG_ID_UCM_VT_BACK_PRESS">VT_OSD_PATH"VT_sk_back_press."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_BACK_DISABLE">VT_OSD_PATH"VT_sk_back_disable."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_H_FREE">VT_OSD_PATH"VT_sk_hfree."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_H_FREE_PRESS">VT_OSD_PATH"VT_sk_hfree_press."IMAGE_FORMAT""</IMAGE>      
	<IMAGE id="IMG_ID_UCM_VT_H_FREE_DISABLE">VT_OSD_PATH"VT_sk_hfree_disable."IMAGE_FORMAT""</IMAGE>        
	<IMAGE id="IMG_ID_UCM_VT_H_HELD">VT_OSD_PATH"VT_sk_hheld."IMAGE_FORMAT""</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_H_HELD_PRESS">VT_OSD_PATH"VT_sk_hheld_press."IMAGE_FORMAT""</IMAGE>      
	<IMAGE id="IMG_ID_UCM_VT_H_HELD_DISABLE">VT_OSD_PATH"VT_sk_hheld_disable."IMAGE_FORMAT""</IMAGE>         
	<IMAGE id="IMG_ID_UCM_VT_DIAL_BG">VT_OSD_PATH"VT_dial_bg.9slice.png"</IMAGE>        
	<IMAGE id="IMG_ID_UCM_VT_DIAL_BT">VT_OSD_PATH"VT_dial_bt.9slice.png"</IMAGE> 
	<IMAGE id="IMG_ID_UCM_VT_DIAL_BT_PRESS">VT_OSD_PATH"VT_dial_bt_press.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_DIAL_INPUT">VT_OSD_PATH"VT_dial_input.9slice.png"</IMAGE>
#if defined(__MMI_FTE_VT_ENHANCE__)
	<IMAGE id="IMG_ID_UCM_VT_PANEL_LINE">VT_OSD_PATH"VT_bg_panel_line.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_PANEL_BG_3">VT_OSD_PATH"VT_bg_panel_3.png"</IMAGE>
	<IMAGE id="IMG_ID_UCM_VT_PANEL_BG_4">VT_OSD_PATH"VT_bg_panel_4.png"</IMAGE>
#endif
#endif      

#endif /* __MMI_VIDEO_TELEPHONY__ */  
 
#ifdef  __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_UCM_GREEN_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_green_button.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_GREEN_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_green_button_down.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_GREEN_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_green_button_disabled.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_RED_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_red_button.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_RED_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_red_button_down.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_RED_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_red_button_disabled.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_NORMAL_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_black_button.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_NORMAL_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_black_button_down.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_NORMAL_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Button\\\\CL_black_button_disabled.9slice.png"</IMAGE>
    #ifdef __SLIM_UCM__
	<IMAGE id="IMG_ID_UCM_LOCK_ICON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_s.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_down_s.png"</IMAGE>
	#else
	<IMAGE id="IMG_ID_UCM_LOCK_ICON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_down.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_UCM_ANSWER">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_call_answer.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_END">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_call_end.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_call_hold.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_RETRIEVE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_call_retrieve.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_CONF">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_conference.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_SPLIT">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_conference_split.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_DIALLER">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_dialler.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_MUTE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_mute.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_UNMUTE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_unmute.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_SILENCE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_silence.png"</IMAGE>
#ifdef __OP01__
#ifdef __MMI_UCM_REJECT_BY_SMS__
    <IMAGE id="IMG_ID_UCM_REJECT_BY_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_reject_by_sms.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_REJECT_BY_SMS_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_reject_by_sms_disable.png"</IMAGE>
#endif /* __MMI_UCM_REJECT_BY_SMS__ */    
#ifdef __MMI_VIDEO_TELEPHONY__
    <IMAGE id="IMG_ID_UCM_ANSWER_BY_VOICE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_answer_by_voice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_ANSWER_BY_VOICE_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_answer_by_voice_disable.png"</IMAGE>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* __OP01__ || __MMI_UCM_VT_ATUO_REDIAL_VOICE__ */        
    <IMAGE id="IMG_ID_UCM_HAND_HELD">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_h_held.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_HAND_FREE">CUST_IMG_PATH"\\\\MainLCD\\\\Toolbar\\\\UCM\\\\TB_h_free.png"</IMAGE>
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef  __FTE_NON_SLIM_RES__
    <IMAGE id="IMG_ID_UCM_CALL_STATE_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_ACT.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_CALL_STATE_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_HOLD.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_UCM_CALL_STATE_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_ACT.bmp"</IMAGE>
    <IMAGE id="IMG_ID_UCM_CALL_STATE_HOLD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_HOLD.bmp"</IMAGE>

#endif
    
#if defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__)
    <IMAGE id="IMG_ID_UCM_ACTIVE_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CallCenter\\\\CC_activecall.bmp"</IMAGE>
#endif /* defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__) */
#ifdef __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__
#ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_UCM_DEFAULT_ACTIVE_STATE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_SACT"</IMAGE>
    <IMAGE id="IMG_ID_UCM_DEFAULT_HOLD_STATE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_SHOLD"</IMAGE>
#else
    <IMAGE id="IMG_ID_UCM_DEFAULT_ACTIVE_STATE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_SACT.PNG"</IMAGE>
    <IMAGE id="IMG_ID_UCM_DEFAULT_HOLD_STATE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_SHOLD.PNG"</IMAGE>
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__ */
#ifdef __MMI_UCM_RSK_MUTE__
    <IMAGE id="IMG_ID_UCM_H_FREE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CSK\\\\H_free.BMP"</IMAGE>
    <IMAGE id="IMG_ID_UCM_H_HELD">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\CSK\\\\H_held.BMP"</IMAGE>
#endif
#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MMI_ICON
	<IMAGE id="IMG_ID_UCM_VT_APPMGR_MAIN_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\VideoCall.png"</IMAGE>
#endif /* defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) */
#endif /* defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_VIDEO_TELEPHONY__) */

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    <IMAGE id="IMG_ID_NCENTER_STATE_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\Icons\\\\icon_call_active.png"</IMAGE>
    <IMAGE id="IMG_ID_NCENTER_STATE_HELD">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\Icons\\\\icon_call_held.png"</IMAGE>
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */


    <!-- 
    ***************************************************************
    AUDIO Area
    ***************************************************************
    -->
#ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__    
    <AUDIO id="AUD_ID_UCM_AUTO_ANSWER">CUST_ADO_PATH"\\\\UCM\\\\auto_answer_tone.wav"</AUDIO>
#endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */    
    
    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    --> 
    /* should change to GROUP later */
#ifdef __MMI_BT_CALL_SUPPORT__
    <SCREEN id="GRP_ID_UCM_MO_SELECT"/>
#endif /* __MMI_BT_CALL_SUPPORT__ */
    <SCREEN id="GRP_ID_UCM_PRE_MO"/>
    <SCREEN id="GRP_ID_UCM_MO"/>
    <SCREEN id="GRP_ID_UCM_MT"/>
    <SCREEN id="GRP_ID_UCM_INCALL"/>  
    <SCREEN id="GRP_ID_UCM_VT"/>
    <SCREEN id="GRP_ID_UCM_INT_MARKER"/>
    <SCREEN id="GRP_ID_UCM_MARKER"/>
    <SCREEN id="GRP_ID_UCM_CALL_END"/>    
    <SCREEN id="GRP_ID_UCM_AUTO_REDIAL"/>      
    <SCREEN id="GRP_ID_UCM_CONFIRM"/> 
    <SCREEN id="GRP_ID_UCM_MO_FAIL_POST_ACTION"/> 
    <SCREEN id="GRP_ID_UCM_UHA"/>  
    
    <SCREEN id="SCR_ID_UCM_OUTGOING"/>
    <SCREEN id="SCR_ID_UCM_INCOMING"/>
    <SCREEN id="SCR_ID_UCM_IN_CALL"/>  
    <SCREEN id="SCR_ID_UCM_DTMF_EDITOR"/>  
    <SCREEN id="SCR_ID_UCM_MULTI_HELD_CALL"/>      
    <SCREEN id="SCR_ID_UCM_CALL_END"/>    
    <SCREEN id="SCR_ID_UCM_VOIP_DIALER"/>  
    <SCREEN id="SCR_ID_UCM_VOICE_DIALER"/>  
    <SCREEN id="SCR_ID_UCM_TRANSFER"/>  
    <SCREEN id="SCR_ID_UCM_DEFLECT"/>  
    <SCREEN id="SCR_ID_UCM_CONFIRM"/>      
    <SCREEN id="SCR_ID_UCM_PROCESSING"/>  
    <SCREEN id="SCR_ID_UCM_AUTO_REDIAL"/>  
    <SCREEN id="SCR_ID_UCM_DIAL_CALL_TYPE_MENU"/>  
#ifdef __MMI_BT_CALL_SUPPORT__
    <SCREEN id="SCR_ID_UCM_DIAL_SELECT_MENU"/>
#endif /* __MMI_BT_CALL_SUPPORT__ */
    <SCREEN id="SCR_ID_UCM_BGS_EFFECT_SELECT"/>                              
    <SCREEN id="SCR_ID_UCM_URIAGENT_CONFIRM"/>  
    <SCREEN id="SCR_ID_UCM_SEND_DTMF"/>  
    <SCREEN id="SCR_ID_UCM_DUMMY"/>     
    <SCREEN id="SCR_ID_UCM_ECT_CONFIRM"/>  
    <SCREEN id="SCR_ID_UCM_REJ_BY_SMS_CONFIRM"/>  
    <SCREEN id="SCR_ID_UCM_DISCONNECT_SCREEN"/>                 
    <SCREEN id="SCR_ID_UCM_GRAY_SCREEN"/>                
    <SCREEN id="SCR_ID_UCM_MO_FAIL_POST_ACTION"/>  
    <SCREEN id="SCR_ID_UCM_VT_INCALL"/>  
    <SCREEN id="SCR_ID_UCM_VT_DIALER"/>                              
    <SCREEN id="SCR_ID_UCM_VT_MO_FAIL_POST_ACTION"/>
    <SCREEN id="SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY"/>
    <SCREEN id="SCR_ID_UCM_VT_VIDEO_QUALITY"/>
    <SCREEN id="SCR_ID_UCM_VT_PIC_VIEWER"/>

    
    <!-- 
    ***************************************************************
    EVENT Area
    ***************************************************************
    <EVENT id="EVT_ID_UCM_DISCONNECTING"/>
    -->
    
    
    
    <!-- 
    ***************************************************************
    MENU Area
    ***************************************************************
    -->
        
#ifdef __MMI_VIDEO_TELEPHONY__
  
    <MENU id="MENU_ID_UCM_VT_INCALL_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_MAKE_VIDEO_CALL</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_START_CAMERA</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_STOP_CAMERA</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_USE_MAIN_CAMERA</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_USE_SUB_CAMERA</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_TURN_ON_NIGHT_MODE</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_TURN_OFF_NIGHT_MODE</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_MUTE_MIC</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_MIC</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_MUTE_SPEAKER</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_SPEAKER</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_SWITCH_PIC</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_HIDE_SMALL_PIC</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_UNHIDE_SMALL_PIC</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPTION_SOUND_RECORDER</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_PHONEBOOK</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_MESSAGE_CENTER</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_BROWSER</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_SWTICH_TO_VOICE_CALL</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_SETTING</MENUITEM_ID>
                        #ifdef __MMI_DUAL_MIC_SUPPORT__
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_ENABLE_NOICE_REDUCTION</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_DISABLE_NOICE_REDUCTION</MENUITEM_ID>
                        #endif /* __MMI_DUAL_MIC_SUPPORT__ */
    </MENU>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_MAKE_VIDEO_CALL" str="STR_ID_UCM_VT_MAKE_VIDEO_CALL"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_START_CAMERA" str="STR_ID_UCM_VT_START_CAMERA"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_STOP_CAMERA" str="STR_ID_UCM_VT_STOP_CAMERA"/>
#ifdef DUAL_CAMERA_SUPPORT
   <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_USE_MAIN_CAMERA" str="STR_ID_UCM_VT_USE_MAIN_CAMERA"/>
   <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_USE_SUB_CAMERA" str="STR_ID_UCM_VT_USE_SUB_CAMERA"/>
#endif /* DUAL_CAMERA_SUPPORT */
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_TURN_ON_NIGHT_MODE" str="STR_ID_UCM_VT_TURN_ON_NIGHT_MODE"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_TURN_OFF_NIGHT_MODE" str="STR_ID_UCM_VT_TURN_OFF_NIGHT_MODE"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_MUTE_MIC" str="STR_ID_UCM_VT_MUTE_MIC"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_MIC" str="STR_ID_UCM_VT_UNMUTE_MIC"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_MUTE_SPEAKER" str="STR_ID_UCM_VT_MUTE_SPEAKER"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_SPEAKER" str="STR_ID_UCM_VT_UNMUTE_SPEAKER"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_SWITCH_PIC" str="STR_ID_UCM_VT_SWITCH_PIC"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_HIDE_SMALL_PIC" str="STR_ID_UCM_VT_HIDE_SMALL_PIC"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_UNHIDE_SMALL_PIC" str="STR_ID_UCM_VT_UNHIDE_SMALL_PIC"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH" str="STR_ID_UCM_VT_SWITCH_AUDIO_PATH"/>
#ifdef __MMI_SOUND_RECORDER__
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPTION_SOUND_RECORDER" str="STR_ID_UCM_SOUND_RECORDER"/>
#endif /* __MMI_SOUND_RECORDER__ */ 

    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_PHONEBOOK" str="STR_ID_UCM_PHONEBOOK"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_MESSAGE_CENTER" str="MAIN_MENU_MESSAGES_TEXT"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_SWTICH_TO_VOICE_CALL" str="STR_ID_UCM_VT_SWTICH_TO_VOICE_CALL"/>
#ifdef __MMI_DUAL_MIC_SUPPORT__
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_ENABLE_NOICE_REDUCTION" str="STR_ID_UCM_ENABLE_NOICE_REDUCTION"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_DISABLE_NOICE_REDUCTION" str="STR_ID_UCM_DISABLE_NOICE_REDUCTION"/>  
#endif /* __MMI_DUAL_MIC_SUPPORT__ */
    <MENU id="MENU_ID_UCM_VT_INCALL_OPT_SETTING" type="APP_SUB" str="STR_ID_UCM_VIDEO_CALL_SETTING">
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_ANSWER_MODE</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_DIAL_MODE</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_IMAGE</MENUITEM_ID>
                        #if defined(__OP01__) && defined(__MMI_FILE_MANAGER__)
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE</MENUITEM_ID>
                        #endif /* defined(__OP01__) && defined(__MMI_FILE_MANAGER__) */
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_AUDIO_OPT</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY" type="OPTION" str="STR_ID_UCM_VT_VIDEO_QUALITY">
                            <MENUITEM_ID>MENU_ID_UCM_VT_VIDEO_QUALITY_SMOOTH</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_VIDEO_QUALITY_NORMAL</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_VIDEO_QUALITY_SHARP</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UCM_VT_SETTING_ANSWER_MODE" type="APP_SUB" str="STR_ID_UCM_VT_ANSWER_MODE">
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_ANSWER_MODE_PROMPT</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_ANSWER_MODE_START_CAMERA</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_ANSWER_MODE_STOP_CAMERA</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UCM_VT_SETTING_DIAL_MODE" type="APP_SUB" str="STR_ID_UCM_VT_DIAL_MODE">
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_DIAL_MODE_START_CAMERA</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_DIAL_MODE_STOP_CAMERA</MENUITEM_ID></MENU>
#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
    <MENU id="MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE" type="APP_SUB" str="STR_ID_UCM_VT_AUTO_REDIAL_MODE">
                                <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_MANUAL</MENUITEM_ID>    
                                <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_ON</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_OFF</MENUITEM_ID>
    </MENU>
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */        

#if defined(__MMI_FILE_MANAGER__)
    <MENU id="MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC" type="OPTION" str="STR_ID_UCM_VT_IMAGE_IN_VIDEO_CALL">
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_OFF</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_DEFAULT</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_USER_DEFINE</MENUITEM_ID></MENU>

    <MENU id="MENU_ID_UCM_VT_SETTING_INCALL_IMAGE" type="APP_SUB" str="STR_ID_UCM_VT_IMAGE_IN_VIDEO_CALL" hint="mmi_ucm_vt_hint_setting_alt_incall_pic">
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_OFF</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_DEFAULT</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_USER_DEFINE</MENUITEM_ID></MENU>
#ifdef __OP01__
    <MENU id="MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE" type="APP_SUB" str="STR_ID_UCM_VT_REMOTE_IMAGE_IN_VIDEO_CALL">
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE_DEFAULT</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE_USER_DEFINE</MENUITEM_ID></MENU>
#endif /* __OP01__ */
#endif /* __MMI_FILE_MANAGER__ */
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_AUDIO_OPT" str="STR_ID_UCM_VT_AUDIO_OPTION"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_ANSWER_MODE_PROMPT" str="STR_ID_UCM_VT_PROMPT"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_ANSWER_MODE_START_CAMERA" str="STR_ID_UCM_VT_START_CAMERA"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_ANSWER_MODE_STOP_CAMERA" str="STR_ID_UCM_VT_STOP_CAMERA"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_DIAL_MODE_START_CAMERA" str="STR_ID_UCM_VT_START_CAMERA"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_DIAL_MODE_STOP_CAMERA" str="STR_ID_UCM_VT_STOP_CAMERA"/>
#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_MANUAL" str="STR_GLOBAL_MANUAL"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_OFF" str="STR_GLOBAL_OFF"/>    
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */
#if defined(__MMI_FILE_MANAGER__)
#ifdef __OP01__
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_OFF" str="STR_GLOBAL_OFF"/>
#endif /* __OP01__ */
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_DEFAULT" str="STR_ID_UCM_VT_DEFAULT"/>
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_USER_DEFINE" str="STR_ID_UCM_VT_USER_DEFINE"/>

#ifdef __OP01__
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_OFF" str="STR_GLOBAL_OFF"/>
#endif /* __OP01__ */
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_DEFAULT" str="STR_ID_UCM_VT_DEFAULT"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_USER_DEFINE" str="STR_ID_UCM_VT_USER_DEFINE"/>
#ifdef __OP01__
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE_DEFAULT" str="STR_ID_UCM_VT_DEFAULT"/>
    <MENUITEM id="MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE_USER_DEFINE" str="STR_ID_UCM_VT_USER_DEFINE"/>
#endif /* __OP01__ */
#endif /* __MMI_FILE_MANAGER__ */
    <MENUITEM id="MENU_ID_UCM_VT_VIDEO_QUALITY_SMOOTH" str="STR_ID_UCM_VT_SMOOTH"/>
    <MENUITEM id="MENU_ID_UCM_VT_VIDEO_QUALITY_NORMAL" str="STR_ID_UCM_VT_NORMAL"/>
    <MENUITEM id="MENU_ID_UCM_VT_VIDEO_QUALITY_SHARP" str="STR_ID_UCM_VT_SHARP"/>
    
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SWITCH_TO_VIDEO_CALL" str="STR_ID_UCM_SWITCH_TO_VIDEO_CALL"/>
#endif /* __MMI_VIDEO_TELEPHONY__ */

#if !defined(__MMI_UCM_SLIM__)
    <MENU id="MENU_ID_UCM_OUTGOING_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                                <MENUITEM_ID>MENU_ID_UCM_OUTGOING_OPTION_DIALER</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE</MENUITEM_ID>
                            #ifdef __VOICE_CHANGER_SUPPORT__
                                <MENUITEM_ID>MENU_ID_CALLSET_MAGIC_VOICE</MENUITEM_ID>
                            #endif /* __VOICE_CHANGER_SUPPORT__ */
    </MENU>
    
    <MENU id="MENU_ID_UCM_INCOMING_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_ANSWER</MENUITEM_ID>
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_ANSWER_BY_VOICE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_DIALER</MENUITEM_ID>
                        	#ifdef __MMI_UCM_DEFLECT__
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_DEFLECT</MENUITEM_ID>
                        	#endif /* __MMI_UCM_DEFLECT__ */
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_REPLACE</MENUITEM_ID>
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_END_ALL_ACTIVE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_END_ALL_HELD</MENUITEM_ID>
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND</MENUITEM_ID>
                            #ifdef __VOICE_CHANGER_SUPPORT__
                                <MENUITEM_ID>MENU_ID_CALLSET_MAGIC_VOICE</MENUITEM_ID>
                            #endif /* __VOICE_CHANGER_SUPPORT__ */
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH</MENUITEM_ID>
                        		<MENUITEM_ID>MENU_ID_UCM_INCOMING_OPTION_REJ_BY_SMS</MENUITEM_ID>
    </MENU>
#endif /* __MMI_UCM_SLIM__ */

    <MENU id="MENU_ID_UCM_INCALL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_HOLD</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_RETRIEVE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SWAP</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_CONF</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SPLIT</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_END_SINGLE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_END_CONF</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_END_ALL</MENUITEM_ID>
                            #if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_TRANSFER</MENUITEM_ID>
                            #endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_NEW_CALL</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_MAIN_MENU</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_PHONEBOOK</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_CALLLOG</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SMS</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_BROWSER</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_HOMESCREEN</MENUITEM_ID>                                
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_BACKGROUND</MENUITEM_ID>
                            #ifdef __VOICE_CHANGER_SUPPORT__
                                <MENUITEM_ID>MENU_ID_CALLSET_MAGIC_VOICE</MENUITEM_ID>
                            #endif /* __VOICE_CHANGER_SUPPORT__ */
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SWITCH_TO_VIDEO_CALL</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_BGSND_CM_OPT_EFFECT</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_MUTE</MENUITEM_ID>
#ifdef __SLIM_UCM__
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_UNMUTE</MENUITEM_ID>
#endif
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_DTMF</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_CTM_SETTING</MENUITEM_ID>
                            #ifdef __MMI_DUAL_MIC_SUPPORT__
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_ENABLE_NOICE_REDUCTION</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_DISABLE_NOICE_REDUCTION</MENUITEM_ID>
                            #endif /* __MMI_DUAL_MIC_SUPPORT__ */
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_SPEAKER_VOLUME</MENUITEM_ID>
   </MENU>

#if !defined(__MMI_UCM_SLIM__)
    <MENUITEM id="MENU_ID_UCM_OUTGOING_OPTION_DIALER" str="STR_ID_UCM_DIALER"/>
    <MENUITEM id="MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD" str="STR_ID_UCM_HAND_HELD"/>
    <MENUITEM id="MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE" str="STR_ID_UCM_HAND_FREE"/>
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_ANSWER" str="STR_ID_UCM_ANSWER"/>
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_ANSWER_BY_VOICE" str="STR_ID_UCM_ANSWER_BY_VOICE"/>
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */    
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_DIALER" str="STR_ID_UCM_DIALER"/>
#ifdef __MMI_UCM_DEFLECT__
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_DEFLECT" str="STR_ID_UCM_DEFLECT"/>
#endif /* __MMI_UCM_DEFLECT__ */
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_REPLACE" str="STR_GLOBAL_REPLACE"/>
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM" str="STR_ID_UCM_REDIAL_FROM_OTHER_SIM"/>
#endif
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_END_ALL_ACTIVE" str="STR_ID_UCM_END_ALL_ACTIVE"/>
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_END_ALL_HELD" str="STR_ID_UCM_END_ALL_HELD"/>
#ifdef __MMI_BG_SOUND_EFFECT__
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND" str="STR_ID_UCM_CALL_BACKGROUND_SOUND"/>
#endif /* __MMI_BG_SOUND_EFFECT__ */
#ifdef __VOICE_CHANGER_SUPPORT__
    <MENUITEM id="MENU_ID_CALLSET_MAGIC_VOICE" str="STR_ID_CALLSET_MAGIC_VOICE"/>
#endif /* __VOICE_CHANGER_SUPPORT__ */
#ifdef __MMI_BT_SUPPORT__
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH" str="STR_ID_UCM_SWITCH_AUDIO_PATH"/>
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __MMI_UCM_REJECT_BY_SMS__
    <MENUITEM id="MENU_ID_UCM_INCOMING_OPTION_REJ_BY_SMS" str="STR_ID_UCM_REJ_BY_SMS"/>
#endif
#endif /* __MMI_UCM_SLIM__ */
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_HOLD" str="STR_ID_UCM_HOLD"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_RETRIEVE" str="STR_ID_UCM_RETRIEVE"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SWAP" str="STR_ID_UCM_SWAP"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_CONF" str="STR_ID_UCM_CONFERENCE"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SPLIT" str="STR_ID_UCM_SPLIT"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_END_SINGLE" str="STR_ID_UCM_END_SINGLE"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_END_CONF" str="STR_ID_UCM_END_CONFERENCE"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_END_ALL" str="STR_ID_UCM_END_ALL"/>
#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_TRANSFER" str="STR_ID_UCM_TRANSFER"/>
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */
#ifndef __MMI_UCM_SLIM__
    <MENU id="MENU_ID_UCM_INCALL_OPTION_NEW_CALL" type="OPTION" str="STR_ID_UCM_NEW_CALL">
                        		<MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOICE</MENUITEM_ID>
                        		<MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOIP</MENUITEM_ID>
    </MENU>
#endif /* __MMI_UCM_SLIM__ */

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_HOMESCREEN" str="STR_ID_UCM_HOMESCREEN"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_BACKGROUND" str="STR_ID_UCM_BACKGROUND"/>

#else /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

#if defined(__MMI_BACKGROUND_CALL__)
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_MAIN_MENU" str="STR_ID_UCM_MAIN_MENU"/>
#else /* __MMI_BACKGROUND_CALL__ */
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_PHONEBOOK" str="STR_ID_UCM_PHONEBOOK"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_CALLLOG" str="MAIN_MENU_CALL_LOG_TEXT"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SMS" str="MAIN_MENU_MESSAGES_TEXT"/>
#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_BROWSER" str="STR_ID_UCM_BROWSER"/>
#ifdef __MMI_VIDEO_TELEPHONY__
    <MENUITEM id="MENU_ID_UCM_VT_INCALL_OPT_BROWSER" str="STR_ID_UCM_BROWSER"/>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
#endif /* __MMI_BACKGROUND_CALL__ */

#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

#ifdef __MMI_SOUND_RECORDER__
<MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER" str="STR_ID_UCM_SOUND_RECORDER"/>
#endif /* __MMI_SOUND_RECORDER__ */ 
#ifndef __MMI_UCM_RSK_MUTE__
#ifdef __SLIM_UCM__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_MUTE" str="STR_GLOBAL_MUTE" />
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_UNMUTE" str="STR_ID_UCM_UNMUTE" />
#else
    <MENU id="MENU_ID_UCM_INCALL_OPTION_MUTE" type="OPTION" str="STR_GLOBAL_MUTE">
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_MUTE_ON</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_MUTE_OFF</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_MUTE_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_MUTE_OFF" str="STR_GLOBAL_OFF"/>
#endif
#endif
#ifndef __MMI_UCM_SLIM__
    <MENU id="MENU_ID_UCM_INCALL_OPTION_DTMF" type="OPTION" str="STR_ID_UCM_DTMF">
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_DTMF_ON</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_INCALL_OPTION_DTMF_OFF</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_DTMF_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_DTMF_OFF" str="STR_GLOBAL_OFF"/>
#endif /* __MMI_UCM_SLIM__ */
#ifdef __MMI_BT_SUPPORT__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH" str="STR_ID_UCM_SWITCH_AUDIO_PATH"/>
#endif /* __MMI_BT_SUPPORT__ */
#ifdef __CTM_SUPPORT__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT" str="STR_ID_UCM_CTM_CONNECT"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_CTM_SETTING" str="STR_ID_UCM_CTM_SETTING"/>
#endif /* __CTM_SUPPORT__ */

#ifdef __MMI_DUAL_MIC_SUPPORT__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_ENABLE_NOICE_REDUCTION" str="STR_ID_UCM_ENABLE_NOICE_REDUCTION"/>
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_DISABLE_NOICE_REDUCTION" str="STR_ID_UCM_DISABLE_NOICE_REDUCTION"/>
#endif /* __MMI_DUAL_MIC_SUPPORT__ */

#ifndef __OP01_FWPBW__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_SPEAKER_VOLUME" str="STR_GLOBAL_VOLUME"/>
#endif /* __OP01_FWPBW__ */

#ifndef __MMI_UCM_SLIM__
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOICE" str="STR_ID_UCM_VOICE_CALL"/>
#ifdef __MMI_VOIP__    
    <MENUITEM id="MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOIP" str="STR_ID_UCM_VOIP_CALL"/>
#endif /* __MMI_VOIP__ */
    <MENU id="MENU_ID_UCM_NEW_CALL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                            <MENUITEM_ID>MENU_ID_UCM_NEW_CALL_OPTION_DIAL</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_NEW_CALL_OPTION_SAVE</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_UCM_NEW_CALL_OPTION_DIAL" str="STR_GLOBAL_DIAL"/>
#if (MMI_MAX_SIM_NUM == 2)
    <MENUITEM id="MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1" str="STR_ID_UCM_SIM1_VOICE_CALL"/>
    <MENUITEM id="MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2" str="STR_ID_UCM_SIM2_VOICE_CALL"/>
#endif /* (MMI_MAX_SIM_NUM == 2) */
    <MENUITEM id="MENU_ID_UCM_NEW_CALL_OPTION_SAVE" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>
#endif /* __MMI_UCM_SLIM__*/
    <MENU id="MENU_ID_UCM_IN_CALL_DIALER_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                            <MENUITEM_ID>MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL</MENUITEM_ID>
                            <MENUITEM_ID>MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE</MENUITEM_ID>
    </MENU>
     <MENUITEM id="MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL" str="STR_GLOBAL_DIAL"/>
     <MENUITEM id="MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    <MENU id="MENU_ID_UCM_CALL_TYPE" str="STR_GLOBAL_DIAL">
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOICE</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOICE_SIM2</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOICE_SIM3</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOICE_SIM4</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOIP</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VIDEO</MENUITEM_ID>
    </MENU>

#if (MMI_MAX_SIM_NUM >= 2)
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE" str="STR_ID_UCM_SIM1_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice"/>
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE_SIM2" str="STR_ID_UCM_SIM2_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice_sim2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE_SIM3" str="STR_ID_UCM_SIM3_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice_sim3"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE_SIM4" str="STR_ID_UCM_SIM4_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice_sim4"/>
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    <MENU id="MENU_ID_UCM_CALL_TYPE" str="STR_GLOBAL_DIAL">
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOICE</MENUITEM_ID>
                            #if (MMI_MAX_SIM_NUM == 2)
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOICE_SIM2</MENUITEM_ID>
                            #endif /* (MMI_MAX_SIM_NUM == 2) */
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VOIP</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UCM_CALL_TYPE_VIDEO</MENUITEM_ID>
    </MENU>

#if (MMI_MAX_SIM_NUM == 2)
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE" str="STR_ID_UCM_SIM1_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice"/>
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE_SIM2" str="STR_ID_UCM_SIM2_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice_sim2"/>
#else /* (MMI_MAX_SIM_NUM == 2) */
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOICE" str="STR_ID_UCM_VOICE_CALL" highlight="mmi_ucm_highlight_call_type_voice"/>
#endif /* (MMI_MAX_SIM_NUM == 2) */

#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#ifdef __MMI_VOIP__
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VOIP" str="STR_ID_UCM_VOIP_CALL" highlight="mmi_ucm_highlight_call_type_voip"/>
#endif /* __MMI_VOIP__ */
#ifdef __MMI_VIDEO_TELEPHONY__
    <MENUITEM id="MENU_ID_UCM_CALL_TYPE_VIDEO" str="STR_ID_UCM_VIDEO_CALL" highlight="mmi_ucm_highlight_call_type_video"/>
#endif /* __MMI_VIDEO_TELEPHONY__ */

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
#if (MMI_MAX_SIM_NUM >= 2)
    <MENUITEM id="MENU_ID_UCM_FROM_SIM1" str="STR_ID_UCM_FROM_SIM1"/>
    <MENUITEM id="MENU_ID_UCM_FROM_SIM2" str="STR_ID_UCM_FROM_SIM2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <MENUITEM id="MENU_ID_UCM_FROM_SIM3" str="STR_ID_UCM_FROM_SIM3"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <MENUITEM id="MENU_ID_UCM_FROM_SIM4" str="STR_ID_UCM_FROM_SIM4"/>
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    <MENU id="MENU_ID_UCM_SIM_SELECT" type="OPTION" str="STR_ID_UCM_SIM_SELECT">
        <MENUITEM_ID>MENU_ID_UCM_FROM_SIM1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UCM_FROM_SIM2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UCM_FROM_SIM3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UCM_FROM_SIM4</MENUITEM_ID>
    </MENU>
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */

#ifdef __MMI_BT_CALL_SUPPORT__
        <MENUITEM id="MENU_ID_UCM_FROM_LOCAL_CALL" str="STR_ID_UCM_FROM_LOCAL_CALL"/>
        <MENUITEM id="MENU_ID_UCM_FROM_BT_CALL" str="STR_ID_UCM_FROM_BT_CALL"/>
        <MENUITEM id="MENU_ID_UCM_FROM_BT_CALL2" str="STR_ID_UCM_FROM_BT_CALL"/>
    <MENU id="MENU_ID_UCM_CALL_SELECT" type="APP_SUB" str="STR_ID_UCM_CALL_SELECT">
        <MENUITEM_ID>MENU_ID_UCM_FROM_LOCAL_CALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UCM_FROM_BT_CALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UCM_FROM_BT_CALL2</MENUITEM_ID>
    </MENU>
#endif /* __MMI_BT_CALL_SUPPORT__ */ 
</APP>

#endif /* __MMI_TELEPHONY_SUPPORT__ */