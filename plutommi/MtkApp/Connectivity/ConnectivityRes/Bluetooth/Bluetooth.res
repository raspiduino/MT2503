/* Needed header files of the compile option in XML files, if you need others need to add here */



#include "mmi_features.h"

#include "custresdef.h"

#ifdef __MMI_BT_SLIM__
#ifndef _MMI_BT_ULTRA_SLIM_
#define _MMI_BT_ULTRA_SLIM_
#endif 
#endif


/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>


/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BLUETOOTH" 
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#ifdef __MMI_BT_SUPPORT__
    package_name = "native.mtk.bluetooth"
    name = "STR_BT_MENU_TITLE"
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    img = "IMG_BT_MAIN_MENU_ICON"
    #endif
    launch = "mmi_bt_launch_bt"
#endif
#else /*__MMI_APP_MANAGER_SUPPORT__*/
#ifdef __MMI_BT_SUPPORT__
    name = "STR_BT_MENU_TITLE"
#endif
#endif
    >

#ifdef __MMI_BT_SUPPORT__
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <INCLUDE file="ConnectivityResDef.h"/>
    <INCLUDE file="GlobalResDef.h"/> 
    <INCLUDE file="MainMenuDef.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>

    <!-- MMI CACHE DATA -->
    <CACHEDATA type="byte" id="NVRAM_BT_RECEIVE_DRIVE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth Storage </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BT_RECEIVE_DRIVE_ASK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth Storage </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BT_POWER_STATUS" restore_flag="TRUE">
    #ifndef __MMI_BTBOX_NOLCD__
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #endif /* __MMI_BTBOX_NOLCD__ */
        <DESCRIPTION> Bluetooth setting </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
  #ifndef __MMI_BT_BTBOX_NOLCD__
    <CACHEDATA type="byte" id="NVRAM_BT_ANTI_LOST_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth anti-lost status setting</DESCRIPTION>
    </CACHEDATA>

	<CACHEDATA type="byte" id="NVRAM_BT_ANTI_LOST_ALERT_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth anti-lost alert mode setting </DESCRIPTION>
    </CACHEDATA>
  #endif /* __MMI_BT_BTBOX_NOLCD__ */

  #ifdef __MMI_BT_BTBOX_NOLCD__
    <CACHEDATA type="byte" id="NVRAM_BT_ANTI_LOST_CONFIG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x05] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth anti-lost configuration </DESCRIPTION>
    </CACHEDATA>
  #endif

    <TIMER id="BT_READ_RSSI_TIMER"/>
    <TIMER id="BT_ANTI_LOST_ALARM_DURATION_TIMER"/>
    <TIMER id="BT_ANTI_LOST_ALARM_DURATION_TIMER_1"/>
    <TIMER id="BT_ANTI_LOST_ALARM_DURATION_TIMER_2"/>
    <TIMER id="BT_ANTI_LOST_ALARM_DURATION_TIMER_3"/>
    <TIMER id="BT_ANTI_LOST_ALARM_DURATION_TIMER_4"/>
    <TIMER id="BT_ANTI_LOST_ALARM_DURATION_TIMER_5"/>
  #endif 

    <TIMER id="BT_LP2_TESTING_TIMER"/>
    <TIMER id="BT_LP2_DELAY_TIMER"/>
    <TIMER id="BT_MMI_MAP_CONNECT_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_OPP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_FTP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_BIP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_HID_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_HFP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_HSP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_SPP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_DUN_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_FAX_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_SIMAP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_PBAP_TIMER"/>
    <TIMER id="BT_AUTHORIZE_SCREEN_SYNC_TIMER"/>
    <TIMER id="BT_SEND_DUMMY_TIMER"/>
    <TIMER id="BT_PROG_UPDATE_TIMER"/>
#ifdef __MMI_BT_DIALER_SUPPORT__
    <TIMER id="BT_AUTO_CONN_HEADSET_AFTER_PAIRED_TIMER"/>
    <TIMER id="BT_DIALER_SEARCH_CANCEL_SCREEN_SHOW_TIMER"/>
#endif

    <!-- ASM Config -->
#ifdef __MMI_OPP_SUPPORT__
    <MEMORY heap = "$(OPPC_MAX_OBEX_PACKET_LENGTH)" inc = "OppSrvGprot.h"/>
#endif

    <!-- FLIGHT MODE CALLBACK -->
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY" proc="mmi_bt_switch_flight_mode"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_bt_switch_flight_mode"/>

    <!-- BT BOX acl timeout disconnect notify -->
#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
    <RECEIVER id="EVT_ID_BT_DIALER_ACL_DISCONN_EVENT_ID" proc="mmi_bt_dialer_acl_timeout_discon_hdlr"/>
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/

#if defined( __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) && defined(__MMI_WEARABLE_DEVICE__)
    <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_bt_notify_screen_lock_hdlr"/>
#endif

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_BT_MENU_TITLE"/>
/* xuewei delete */
/*    <STRING id="STR_BT_LSK_DISC"/> */
#ifdef __MMI_BT_AUDIO_SUPPORT__
    <STRING id="STR_BT_CM_SETPATH"/>
    <STRING id="STR_BT_AUDIO_CONN_ED"/>
    <STRING id="STR_BT_AUDIO_DISC_ED"/>
#endif
    /* Configure Default Headset */
/* xuewei delete */
/*    <STRING id="STR_BT_CONNECT_LAST_HEADSET"/> */
#ifdef __MMI_BT_AUDIO_SUPPORT__
    <STRING id="STR_BT_NO_DEFAULT_HEADSET"/>
#endif

#ifdef __MMI_BT_LIMITED_DISCOVERY_SUPPORT__
    <STRING id="STR_BT_IN_LIMIT_DISCOVERABLE_MODE"/>
#endif /*__MMI_BT_LIMITED_DISCOVERY_SUPPORT__*/
/* xuewei delete */
/*    <STRING id="STR_BT_LSK_CONN"/> */
    <STRING id="STR_BT_POWER"/>
#ifdef __MMI_BT_DIALER_SUPPORT__
    <STRING id="STR_BT_PHONEBOOK"/>
    <STRING id="STR_BT_CALLLOG"/>
    <STRING id="STR_BT_CALL"/>
#endif
    <STRING id="STR_BT_SWITCHING"/>
//    <STRING id="STR_BT_SWITCHED_ON"/>
//    <STRING id="STR_BT_SWITCHED_OFF"/>
    <STRING id="STR_BT_RELEASE_ALL_CONN"/>
    <STRING id="STR_BT_RELEASE_DEV_CONN"/>
    <STRING id="STR_BT_RELEASING"/>
#ifndef _MMI_BT_ULTRA_SLIM_
    <STRING id="STR_BT_SCH_AUD_DEV"/>
#endif
    /* Put Inquiry NEW Device at the first item of Mydev menu */
    <STRING id="STR_BT_SCH_ALL_DEV"/>
    <STRING id="STR_BT_SCH_RESULT"/>
    #ifdef __MMI_BTD_BOX_UI_STYLE__
    <STRING id="STR_BT_MYDEV_HELP_CONTENT_BT_BOX"/>
    #endif
#ifdef __MMI_BT_DIALER_SUPPORT__
    <STRING id="STR_BT_MYDEV_HELP_CONTENT"/>
#endif
    <STRING id="STR_BT_INQUIRY_STOPPING"/>
    <STRING id="STR_BT_DEVICE_BEING_CONNECTED"/>
    <STRING id="STR_BT_ENTER_PASSCODE"/>
    <STRING id="STR_BT_PAIR_REQ"/>
    <STRING id="STR_BT_PAIR_FAILED"/>
    <STRING id="STR_BT_START_PAIRING"/>
#ifdef __MMI_BT_DIALER_SUPPORT__
    <STRING id="STR_BT_DIALER_HELP_CONTENT"/>
    <STRING id="STR_BT_REMOTE_CAPTURE_INFO"/>/**/
    <STRING id="STR_BT_ANTI_LOST_INFO"/>
    <STRING id="STR_BT_DIALER_ETC"/>
#endif
#ifdef __MMI_BT_AUTHORIZE__
    <STRING id="STR_BT_CONNECT_AND_SET_AS_DEFAULT_HF"/>
    <STRING id="STR_BT_SET_AS_DEFAULT_HF"/>
#else
    <STRING id="STR_BT_CONNECT_CONFIRM"/>
#endif
/* xuewei delete */
    <STRING id="STR_BT_ACCEPT_CONNECT_FROM"/>
    <STRING id="STR_BT_REACH_MAX_PAIR_NUM"/>
#if defined(__MMI_FTC_SUPPORT__)||!defined(__MMI_BT_SLIM__)
    <STRING id="STR_BT_REFRESHING"/>
#endif 
//    <STRING id="STR_BT_DELETE_CONFIRM"/>
//    <STRING id="STR_BT_DELETE_ALL_CONFIRM"/>

    <STRING id="STR_BT_CONN_FAILED"/>

    
    <STRING id="STR_BT_MYDEVICE"/>
/* xuewei delete */
/*    <STRING id="STR_BT_MYDEV_OPT_CONNECTED_PROF"/> */
    /* Configure Default Headset */
/* xuewei delete */
/*    <STRING id="STR_BT_MYDEV_OPT_SET_DEFAULT_HS"/> */
//    <STRING id="STR_BT_MYDEV_OPT_REN"/>
#if MMI_MAX_SIM_NUM > 1
    <STRING id="STR_BT_MYDEV_OPT_SIM"/>
    <STRING id="STR_BT_SIM_QUERY"/>
#endif
#ifdef __MMI_BT_AUTHORIZE__
    <STRING id="STR_BT_MYDEV_OPT_AUTHORIZE"/>
    <STRING id="STR_BT_MYDEV_OPT_AUTHORIZE_ALWAYS_CONNECT"/>
    <STRING id="STR_BT_MYDEV_OPT_AUTHORIZE_ALWAYS_ASK"/>
    <STRING id="STR_BT_MYDEV_OPT_AUTHORIZE_ALWAYS_REJECT"/>
#endif	/*__MMI_BT_AUTHORIZE__*/
#ifndef __MMI_BT_SLIM__
    <STRING id="STR_BT_MYDEV_OPT_SUP_SER"/>
#endif 
/* xuewei delete */
/*    <STRING id="STR_BT_ACT_DEV"/> */
    <STRING id="STR_BT_DEV_SET_VIS"/>
#ifdef __MMI_BT_TEMP_VISIBILITY__
    <STRING id="STR_BT_DEV_SET_VIS_PERMANENT_ON"/>
    <STRING id="STR_BT_DEV_SET_VIS_TEMPORARY_ON"/>
    <STRING id="STR_BT_DEV_SET_VIS_X_MINUTES_1"/>
    <STRING id="STR_BT_DEV_SET_VIS_X_MINUTES_2"/>
    <STRING id="STR_BT_DEV_SET_VIS_X_MINUTE_2"/>
#endif /*__MMI_BT_TEMP_VISIBILITY__*/
    <STRING id="STR_BT_DEV_SET_NAME"/>
    <STRING id="STR_BT_DEV_SET_AUDIO_PATH"/>
#ifndef _MMI_BT_ULTRA_SLIM_
    <STRING id="STR_BT_DEV_SET_AUDIO_PATH_PHONE"/>
    <STRING id="STR_BT_DEV_SET_AUDIO_PATH_HF"/>
#endif
/* xuewei delete */
/*    <STRING id="STR_BT_DEV_SET_BLOCK_LIST"/> */
#ifdef __MMI_SIMAP_SUPPORT__
    <STRING id="STR_BT_DEV_SET_SIMAP"/>
#endif 
#ifndef _MMI_BT_ULTRA_SLIM_
    <STRING id="STR_BT_DEV_SET_DEV_ADDR"/>
#endif
    <STRING id="STR_BT_ABOUT"/>
    <STRING id="STR_BT_HELP"/>
    <STRING id="STR_BT_BD_NAME"/>
    <STRING id="STR_BT_SERVICE"/>
    <STRING id="STR_BT_BD_ADDR"/>

#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    <STRING id="STR_BT_SET_ANTI_LOST"/>
    <STRING id="STR_BT_SET_ANTI_LOST_STATUS"/>
    <STRING id="STR_BT_ANTI_LOST_ALERT_TYPE"/>
    <STRING id="STR_BT_ANTI_LOST_NOTIFY"/>
    <STRING id="STR_BT_ANTI_LOST_PRE_ENTRY"/>
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */

#if  defined(__MMI_SPP_SUPPORT__)||defined(__MMI_DUN_SUPPORT__)||defined(__MMI_FAX_SUPPORT__)||defined(__MMI_PBAP_SUPPORT__)||defined(__MMI_SIMAP_SUPPORT__)|| defined(__MMI_BT_DIALER_SUPPORT__)
    <STRING id="STR_BT_CONN_ED"/>
#endif
#if defined(__MMI_SPP_SUPPORT__)||defined(__MMI_DUN_SUPPORT__)||defined(__MMI_FAX_SUPPORT__)||defined(__MMI_PBAP_SUPPORT__)||defined(__MMI_SIMAP_SUPPORT__)||defined(__MMI_HIDD_SUPPORT__) || defined(__MMI_BT_DIALER_SUPPORT__)
    <STRING id="STR_BT_DISCON_ED"/>
#endif
/* xuewei delete */
/*    <STRING id="STR_BT_AUDIO_SCO_CON"/> */
/*    <STRING id="STR_BT_AUDIO_SCO_DISCON"/> */
#ifdef __MMI_SPP_SUPPORT__
    <STRING id="STR_BT_PROF_SPP"/>
#endif
#ifdef __MMI_DUN_SUPPORT__
    <STRING id="STR_BT_PROF_DUN"/>
#endif
#if defined(__MMI_SYNCML_DEVICE_SYNC__)||defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
    <STRING id="STR_BT_PROF_SYNC"/>
    <STRING id="STR_BT_SRV_SYNCML"/>
#endif
#ifdef __MMI_OPP_SUPPORT__
    <STRING id="STR_BT_PROF_OPP"/>
#endif
#if defined(__MMI_FTS_SUPPORT__)|| defined(__MMI_FTC_SUPPORT__)
    <STRING id="STR_BT_PROF_FTP"/>
#endif
#ifdef __MMI_FAX_SUPPORT__	
    <STRING id="STR_BT_PROF_FAX"/>
#endif
#ifdef __MMI_A2DP_SUPPORT__
    <STRING id="STR_BT_PROF_A2DP"/>
#endif
#if defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
    <STRING id="STR_BT_PROF_AVRCP"/>
#endif
#ifdef __MMI_HFP_SUPPORT__
    <STRING id="STR_BT_PROF_HF"/>
    <STRING id="STR_BT_PROF_HS"/>
#endif
#ifdef __MMI_BPP_SUPPORT__
    <STRING id="STR_BT_PROF_BASIC_PRINTING"/>
#endif
#ifdef __MMI_HIDD_SUPPORT__
    <STRING id="STR_BT_PROF_HID"/>
#endif

#ifdef __MMI_SIMAP_SUPPORT__
    <STRING id="STR_BT_PROF_SAP"/>
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_bt_sim_hot_swap_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" proc="mmi_bt_sim_event_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_bt_sim_event_hdlr"/>
#endif


#ifdef __MMI_BT_BTBOX_NOLCD__
  #ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    <EVENT id="EVT_BTB_RECONN_CANCEL" type="SENDER" />
    <EVENT id="EVT_BTB_RECONN_RESTART" type="SENDER" />

    <AUDIO id="AUD_BTB_SRC1_LOST" desc="SP1 Device Lost" path="BT_Lost.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Lost.mp3"</AUDIO>
    <AUDIO id="AUD_BTB_SRC1_ABDISCONNECT" desc="SP1 abnormal disc" path="BT_Abdisc.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Abnomal_Disc.mp3"</AUDIO>
    <AUDIO id="AUD_BTB_SRC1_RECONNECT" desc="SP1 reconnection" path="BT_Reconnect.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Reconnect.mp3"</AUDIO>
    <AUDIO id="AUD_BTB_SRC1_RECONNECT_FINISH" desc="SP1 reconnect finish" path="BT_Recoonect_OK.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\BT_Recoonect_OK.mp3"</AUDIO>

    <NOTIFY id="NOTIFY_BTB_SRC1_LOST" desc="SP1 Device Lost" led="INPUT_EVENT_LED_ID_9" vib="INPUT_EVENT_VIB_INDX_0" voice="AUD_BTB_SRC1_LOST"/>
    <NOTIFY id="NOTIFY_BTB_SRC1_ABDISCONNECT" desc="SP1 abnormal disc" led="INPUT_EVENT_LED_ID_9" vib="INPUT_EVENT_VIB_INDX_0" voice="AUD_BTB_SRC1_ABDISCONNECT"/>
    <NOTIFY id="NOTIFY_BTB_SRC1_RECONNECT" desc="reconnect SP1" led="INPUT_EVENT_LED_ID_7" voice="AUD_BTB_SRC1_RECONNECT"/>
    <NOTIFY id="NOTIFY_BTB_SRC1_RECONN_FINISH" desc="finish reconnect SP1" voice="AUD_BTB_SRC1_RECONNECT_FINISH"/>

    // Key Event
    <INPUT_EVENT grp_id="GRP_ID_BT_ANTI_LOST_IND" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="stop reconnect" key_code="KEY_2" key_type="KEY_LONG_PRESS"/>
   #ifdef __MMI_BTB_AT_KEY_SUPPORT__
    <INPUT_EVENT grp_id="GRP_ID_BT_ANTI_LOST_IND" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_CANCEL" evt_desc="stop reconnect" key_code="KEY_STAR" key_type="KEY_EVENT_UP"/>
   #endif /* __MMI_BTB_AT_KEY_SUPPORT__ */

   #ifdef __MMI_BTB_AT_KEY_SUPPORT__
    <INPUT_EVENT grp_id="GRP_ID_BT_ANTI_LOST_IND" grp_desc="SP abnormal disc" evt_id="EVT_BTB_RECONN_RESTART" evt_desc="start reconnect" key_code="KEY_5" key_type="KEY_EVENT_UP"/>
   #endif /* __MMI_BTB_AT_KEY_SUPPORT__ */
  #endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ */
#endif 

#if defined(__MMI_PBAP_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
    <STRING id="STR_BT_PROF_PBAP"/>
#endif
    <STRING id="STR_BT_PROF_UNKNOWN"/>
    <STRING id="STR_BT_NOT_READY"/>
#if defined(__MMI_HIDD_SUPPORT__)
    <STRING id="STR_BT_FAILED"/>
#endif 
/* xuewei delete */
/*    <STRING id="STR_BT_NOT_SUPPORT"/> */
/*    <STRING id="STR_BT_NOT_ALLOW"/> */
#if !defined(__MMI_BT_SLIM__)
    <STRING id="STR_BT_NO_SUPPORTED_PROFILE"/>
#endif 
    <STRING id="STR_BT_PWR_ON_CNF"/>
    <STRING id="STR_BT_POWER_ON_IN_FLIGHT_MODE_CNF"/>
#ifndef __MMI_BT_SLIM__
    <STRING id="STR_BT_DISCONN_ALL_CONN_CNF"/>
#endif
    <STRING id="STR_BT_DISCONN_ALL_CONN"/>
    <STRING id="STR_BT_DISCONN_DEV_CONN_CNF"/>
    <STRING id="STR_BT_DISCONN_DEV_CONN"/>
    <STRING id="STR_BT_DISCONN_AUD_DEV_CONN_CNF"/>
/* xuewei delete */
/*    <STRING id="STR_BT_DEVICE_WITH_THE_SAME_NAME_EXIST"/> */
    /* BT receive drive switch */

/* xuewei delete */
/*    <STRING id="STR_BT_RECV_DRV_NOT_AVAIL_CNF"/> */
//    <STRING id="STR_BT_RECV_DRV_ALWAYS_ASK"/>
/*    <STRING id="STR_BT_RECV_DRV_MEMORY_CARD_REMOVED"/> */
/*    <STRING id="STR_BT_RECV_DRV_OTG_DEVICE_REMOVED"/> */
/*    <STRING id="STR_BT_RECV_DRV_OTG2PHONE"/> */

    <STRING id="STR_BT_PAIRED_DEV_FULL"/>
    <STRING id="STR_BT_PROHIBIT_VIS_BY_A2DP"/>
    <STRING id="STR_BT_OPERATION_NOT_ALLOWED_DIS_HFP_FIRST"/>
/* xuewei delete */
/*    <STRING id="STR_BT_PROHIBIT_VIS_BY_MAX_ACL"/> */
    <STRING id="STR_BT_PROHIBIT_BY_SIMAP"/>
#if defined(__MMI_BIP_SUPPORT__) || defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
    <STRING id="STR_BT_NO_CARD"/>
    <STRING id="STR_BT_WRITE_FILE_FAIL"/>
    <STRING id="STR_BT_RECEIVE_FAIL"/>
#endif
    /* BT sending auto prompt switch */
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    <STRING id="STR_BT_SEND_OPTION_SETDEF"/>
    <STRING id="STR_BT_SEND_OPTION_CLEARDEF"/>
    <STRING id="STR_BT_SEND_CNF_TO_DEFAULT"/>
    <STRING id="STR_BT_SEND_CNF_SET_DEFAULT"/>
#endif
#ifdef __MMI_OPP_SUPPORT__
    <STRING id="STR_BT_SEND_ALL_SENT"/>
    <STRING id="STR_BT_SEND_PARTIAL_1"/>
    <STRING id="STR_BT_SEND_PARTIAL"/>
#endif

#ifdef __MMI_OPP_SUPPORT__
<TIMER id="BT_OPP_PUSH_IND_TIMER"/>
<TIMER id="BT_OPP_CACULATE_SENDING_SIZE"/>
#endif
    /* SAP-16 */
    <STRING id="STR_BT_16_DIGITS_PASSKEY"/>
#ifdef __MMI_BT_AUTHORIZE__
    <STRING id="STR_BT_LSK_UNBLOCK"/>
#endif
    <STRING id="STR_BT_INPUT_PASSCODE"/>
    <STRING id="STR_BT_NUMERIC_COMPARISON"/>
    <STRING id="STR_BT_ACCEPT_PAIRING"/>
    <STRING id="STR_BT_FROM"/>
#ifdef __MMI_BT_AUTHORIZE__
    <STRING id="STR_BT_DEVICE_BLOCKED"/>
#endif
    <STRING id="STR_BT_QUESTION_MARK"/>
//    <STRING id="STR_BT_ADVANCED"/>
 #ifdef __MMI_FTC_SUPPORT__
    <STRING id="STR_BT_TRANSFER_FILES"/>
#endif
/* xuewei delete */
/*    <STRING id="STR_BT_BROWSE_IMAGES"/> */
#ifdef __MMI_BT_DEFAULT_HEADSET__
#ifdef __MMI_HFP_SUPPORT__
    <STRING id="STR_BT_SET_DEFAULT_HEADSET"/>
#endif
#endif 

#if defined(__MMI_HIDD_SUPPORT__)
    <STRING id="STR_BT_REMOTE_CONTROL"/>
    <STRING id="STR_BT_REMOTE_CTRL_NO_LAST_DEV_INFO"/>
    <STRING id="STR_BT_REMOTE_CTRL_DESKTOP"/>
    <STRING id="STR_BT_REMOTE_CTRL_MEDIA_PLAYER"/>
    //<STRING id="STR_BT_REMOTE_CTRL_PRESENTER"/>
    <STRING id="STR_BT_REMOTE_CTRL_UNPLUG_CONFIRM"/>
    <STRING id="STR_BT_REMOTE_CTRL_DISC_CONFIRM"/>
    //<STRING id="STR_BT_REMOTE_CTRL_KEYBOARD"/>
   // <STRING id="STR_BT_UNSUPPORTED_KEY_CMD"/>
    <STRING id="STR_BT_REMOTE_CTRL_CONN_AUTH"/>
    <STRING id="STR_BT_REMOTE_CTRL_CONN_FAIL"/>
#endif
#ifdef __MMI_BT_AUTHORIZE__
    <STRING id="STR_BT_ALWAYS_ACCEPT_CONNECTION"/>
#endif

#ifdef __MMI_AVRCP_DEBUG__
    /* AVRCP command string*/                                                 
    <STRING id="STR_BT_AVRCP_CMD_UNIT_COMMAND"/>
    <STRING id="STR_BT_AVRCP_CMD_SUBUNIT_COMMAND"/>
    <STRING id="STR_BT_AVRCP_CMD_SELECT"/>
    <STRING id="STR_BT_AVRCP_CMD_UP"/>
    <STRING id="STR_BT_AVRCP_CMD_DOWN"/>
    <STRING id="STR_BT_AVRCP_CMD_LEFT"/>
    <STRING id="STR_BT_AVRCP_CMD_RIGHT"/>
    <STRING id="STR_BT_AVRCP_CMD_RIGHT_UP"/>
    <STRING id="STR_BT_AVRCP_CMD_RIGHT_DOWN"/>
    <STRING id="STR_BT_AVRCP_CMD_LEFT_UP"/>                                       
    <STRING id="STR_BT_AVRCP_CMD_LEFT_DOWN"/>
    <STRING id="STR_BT_AVRCP_CMD_ROOT_MENU"/>
    <STRING id="STR_BT_AVRCP_CMD_SETUP"/>
    <STRING id="STR_BT_AVRCP_CMD_CONTENTS"/>
    <STRING id="STR_BT_AVRCP_CMD_FAVORITE"/>
    <STRING id="STR_BT_AVRCP_CMD_EXIT"/>
    <STRING id="STR_BT_AVRCP_CMD_0"/>
    <STRING id="STR_BT_AVRCP_CMD_1"/>
    <STRING id="STR_BT_AVRCP_CMD_2"/>
    <STRING id="STR_BT_AVRCP_CMD_3"/>
    <STRING id="STR_BT_AVRCP_CMD_4"/>
    <STRING id="STR_BT_AVRCP_CMD_5"/>
    <STRING id="STR_BT_AVRCP_CMD_6"/>
    <STRING id="STR_BT_AVRCP_CMD_7"/>
    <STRING id="STR_BT_AVRCP_CMD_8"/>
    <STRING id="STR_BT_AVRCP_CMD_9"/>
    <STRING id="STR_BT_AVRCP_CMD_DOT"/>
    <STRING id="STR_BT_AVRCP_CMD_ENTER"/>
    <STRING id="STR_BT_AVRCP_CMD_CLEAR"/>
    <STRING id="STR_BT_AVRCP_CMD_CHANNEL_UP"/>
    <STRING id="STR_BT_AVRCP_CMD_CHANNEL_DOWN"/>
    <STRING id="STR_BT_AVRCP_CMD_PREVIOUS_CHANNEL"/>
    <STRING id="STR_BT_AVRCP_CMD_SOUND_SELECT"/>
    <STRING id="STR_BT_AVRCP_CMD_INPUT_SELECT"/>
    <STRING id="STR_BT_AVRCP_CMD_DISPLAY_INFO"/>
    <STRING id="STR_BT_AVRCP_CMD_HELP"/>
    <STRING id="STR_BT_AVRCP_CMD_PAGE_UP"/>
    <STRING id="STR_BT_AVRCP_CMD_PAGE_DOWN"/>
    <STRING id="STR_BT_AVRCP_CMD_POWER"/>
    <STRING id="STR_BT_AVRCP_CMD_VOLUME_UP"/>
    <STRING id="STR_BT_AVRCP_CMD_VOLUME_DOWN"/>
    <STRING id="STR_BT_AVRCP_CMD_MUTE"/>
    <STRING id="STR_BT_AVRCP_CMD_PLAY"/>
    <STRING id="STR_BT_AVRCP_CMD_STOP"/>
    <STRING id="STR_BT_AVRCP_CMD_PAUSE"/>
    <STRING id="STR_BT_AVRCP_CMD_RECORD"/>
    <STRING id="STR_BT_AVRCP_CMD_REWIND"/>
    <STRING id="STR_BT_AVRCP_CMD_FAST_FORWARD"/>
    <STRING id="STR_BT_AVRCP_CMD_EJECT"/>
    <STRING id="STR_BT_AVRCP_CMD_FORWARD"/>
    <STRING id="STR_BT_AVRCP_CMD_BACKWARD"/>
    <STRING id="STR_BT_AVRCP_CMD_ANGLE"/>
    <STRING id="STR_BT_AVRCP_CMD_SUBPICTURE"/>
    <STRING id="STR_BT_AVRCP_CMD_F1"/>
    <STRING id="STR_BT_AVRCP_CMD_F2"/>
    <STRING id="STR_BT_AVRCP_CMD_F3"/>
    <STRING id="STR_BT_AVRCP_CMD_F4"/>
    <STRING id="STR_BT_AVRCP_CMD_F5"/>
    /* End of AVRCP command string*/                                          
#endif  /* __MMI_AVRCP_DEBUG__ */
    
#ifdef __MMI_BT_RECV_OBJ_DETAIL__
    <STRING id="STR_BT_OBJ_TILE"/>
    <STRING id="STR_BT_OBJ_NAME"/>
    <STRING id="STR_BT_OBJ_TYPE"/>
    <STRING id="STR_BT_OBJ_SIZE"/>
    <STRING id="STR_BT_OBJ_UNKNOWN"/>
#endif

#if defined(__MMI_BIP_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    <STRING id="STR_BT_PARTIAL_CONTENT"/>
    <STRING id="STR_BT_ALL_FILE_RECEIVED"/>
#endif

#if defined (__MMI_FTS_SUPPORT__) || \
    defined(__MMI_FTC_SUPPORT__) || \
    defined(__MMI_OPP_SUPPORT__)	

    <STRING id="STR_OBEX_INPUT_AUTHPWD"/>

#endif

#ifdef __MMI_BPP_SUPPORT__
    <STRING id="STR_BT_BPP_NEGOTIATING"/>
    <STRING id="STR_BT_BPP_GET_ATTR"/>
    <STRING id="STR_BT_BPP_APPLAY_SETTING"/>
    <STRING id="STR_BT_BPP_PRINTER_NAME"/>
    
    <STRING id="STR_BT_BPP_GETTING_CAPABILITY"/>
    <STRING id="STR_BT_BPP_PRINT_SETTING"/>
    
    <STRING id="STR_BT_BPP_SETTING_PAPER"/>
    <STRING id="STR_BT_BPP_SETTING_PAPER_A4"/>
    <STRING id="STR_BT_BPP_SETTING_PAPER_US"/>
    <STRING id="STR_BT_BPP_SETTING_PAPER_4X6"/>
    
    <STRING id="STR_BT_BPP_SETTING_SIDES"/>
    <STRING id="STR_BT_BPP_SETTING_SIDES_ONE"/>
    <STRING id="STR_BT_BPP_SETTING_SIDES_TWO_LONG"/>
    <STRING id="STR_BT_BPP_SETTING_SIDES_TWO_SHORT"/>
    
    <STRING id="STR_BT_BPP_SETTING_PAGES"/>
    
    <STRING id="STR_BT_BPP_SETTING_ORIENTATION"/>
    <STRING id="STR_BT_BPP_SETTING_ORIENTATION_PORTRAIT"/>
    <STRING id="STR_BT_BPP_SETTING_ORIENTATION_LANDSCAP"/>
    <STRING id="STR_BT_BPP_SETTING_ORIENTATION_R_PORTRAIT"/>
    <STRING id="STR_BT_BPP_SETTING_ORIENTATION_R_LANDSCAP"/>
    
    <STRING id="STR_BT_BPP_SETTING_QUALITY"/>
    <STRING id="STR_BT_BPP_SETTING_QUALITY_DRAFT"/>
    
    <STRING id="STR_BT_BPP_SETTING_COPIES"/>
    <STRING id="STR_BT_BPP_SETTING_COPIES_ERROR"/>
    <STRING id="STR_BT_BPP_SETTING_COPIES_EXCEED"/>
    <STRING id="STR_BT_BPP_SETTING_COPIES_EXCEED_END"/>
    
    <STRING id="STR_BT_BPP_LAYOUT_PREVIEW"/>
    <STRING id="STR_BT_BPP_PRINTING"/>
    
    <STRING id="STR_BT_BPP_PRINT_JOB_CREATING"/>
    <STRING id="STR_BT_BPP_PRINT_DOCUMENT_COMPOSING"/>
    <STRING id="STR_BT_BPP_TROUBLE_NOTICE"/>
    <STRING id="STR_BT_BPP_TROUBLE_JAM"/>
    <STRING id="STR_BT_BPP_TROUBLE_PAUSED"/>
    <STRING id="STR_BT_BPP_TROUBLE_DOOR"/>
    <STRING id="STR_BT_BPP_TROUBLE_MARKER"/>
    <STRING id="STR_BT_BPP_TROUBLE_MEDIA"/>
    
    <STRING id="STR_BT_BPP_POPUP_PRINTER_BUSY"/>
    <STRING id="STR_BT_BPP_POPUP_AUTH_FAILED"/>
    <STRING id="STR_BT_BPP_POPUP_CONNECT_FAILED"/>
    <STRING id="STR_BT_BPP_POPUP_GET_ATTR_FAILED"/>
    <STRING id="STR_BT_BPP_POPUP_CREATE_JOB_FAILED"/>
    <STRING id="STR_BT_BPP_POPUP_COMPOSE_FAILED"/>
    <STRING id="STR_BT_BPP_POPUP_READ_FILE_FAILED"/>
    
    <STRING id="STR_BT_BPP_POPUP_PRINTED"/>
    <STRING id="STR_BT_BPP_POPUP_CANCELED"/>
    <STRING id="STR_BT_BPP_POPUP_DISCONNECTED"/>
    <STRING id="STR_BT_BPP_POPUP_FORMAT_WARNING"/>
    <STRING id="STR_BT_BPP_POPUP_NO_PREVIEW"/>
    
    <STRING id="STR_BT_BPP_CANCEL"/>
    <STRING id="STR_BT_BPP_SP_PRINT_SETUP"/>
    <STRING id="STR_BT_BPP_SP_AUTHENTICATING"/>
    <STRING id="STR_BT_BPP_SP_CHANGE_PRINTER"/>
    <STRING id="STR_BT_BPP_SP_DEFAULT_PRINTER"/>
    <STRING id="STR_BT_BPP_SP_MEDIA_SIZE"/>
    
    <STRING id="STR_BT_BPP_SP_CANCEL"/>                                       
    <STRING id="STR_BT_BPP_SP_PRINT_CANCEL"/>
    <STRING id="STR_BT_BPP_SP_PRINT_DONE"/>
    <STRING id="STR_BT_BPP_SP_SAVE_AS_DEFAULT"/>
    <STRING id="STR_BT_BPP_SP_PREVIEW"/>
    <STRING id="STR_BT_BPP_SP_ZOOM_IN"/>
    <STRING id="STR_BT_BPP_SP_ZOOM_OUT"/>
    <STRING id="STR_BT_BPP_SP_ERR_PRT_NOT_FOUND"/>
    <STRING id="STR_BT_BPP_SP_ERR_LINK_DISC"/>
    <STRING id="STR_BT_BPP_SP_ERR_DEVICE_BUSY"/>
    <STRING id="STR_BT_BPP_SP_ERR_PRINT_ERROR"/>
    <STRING id="STR_BT_BPP_SP_ERR_NOTICE"/>
    <STRING id="STR_BT_BPP_SP_ERR_NEED_POWERON"/>
    <STRING id="STR_BT_BPP_SP_ERR_FORMAT_UNSUPPORT"/>

    <STRING id="STR_BT_BPP_NOTICE"/>
    <STRING id="STR_BT_BPP_MEDIA_JAM"/>
    <STRING id="STR_BT_BPP_PAUSED"/>
    <STRING id="STR_BT_BPP_DOOR_OPEN"/>
    <STRING id="STR_BT_BPP_MEDIA_LOW"/>
    <STRING id="STR_BT_BPP_MEIDA_EMPTY"/>
    <STRING id="STR_BT_BPP_OUTP_AREA_ALMOST_FULL"/>
    <STRING id="STR_BT_BPP_OUTP_AREA_FULL"/>
    
    <STRING id="STR_BT_BPP_SUPPLY_LOW"/>
    <STRING id="STR_BT_BPP_SUPPLY_EMPTY"/>
    <STRING id="STR_BT_BPP_SUPPLY_FAILURE"/>
    <STRING id="STR_BT_BPP_NO_PREVIEW"/>
    <STRING id="STR_BT_BPP_SETTING_WARNING"/>
    <STRING id="STR_BT_BPP_UNSUPPORT_FORMAT"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_bpp_card_plug_out_hdlr"/>
#endif /* __MMI_BPP_SUPPORT__ */
    /* BIP */
#ifdef __MMI_BIP_SUPPORT__
    <STRING id="STR_BIP_SETTING"/>
    <STRING id="STR_BIP_SHARED_FOLDER"/>
    <STRING id="STR_BIP_CON_AUTH"/>   
    <STRING id="STR_BIP_RECV_FILE_IND"/>
    <STRING id="STR_BIP_STATUS_DISCONNECTING"/>
    
    <STRING id="STR_BIP_CON_DISCONNECTED"/> 
    <STRING id="STR_BIP_OPEN_FILE_FAIL"/>
    <STRING id="STR_BIP_READ_FILE_FAIL"/>
    <STRING id="STR_BIP_XML_GEN_FAIL"/>
    <STRING id="STR_BIP_NOTY_RECV_FILE_BROWSE"/>
    
    <STRING id="STR_BIP_CONNECTING_CLIENT"/>
    <STRING id="STR_ID_BT_BIP"/>
    <STRING id="STR_BIP_UNKNOWN"/>
    <STRING id="STR_BIP_BROWSE_FAILED"/>
    <STRING id="STR_BIP_SERVICE_UNAVAILABLE"/>

    <STRING id="STR_BIP_CONT_SEND_CNF_PRE"/>    
    <STRING id="STR_BIP_CONT_SEND_CNF_POST"/>
    <STRING id="STR_BIP_WARNING"/>
    <STRING id="STR_BIP_CONT_SEND_CNF_NOT_SUPPORT"/>
    <STRING id="STR_BIP_OUT_OF_MEMORY"/>
    
    <STRING id="STR_BIP_QUESTION_MARK"/>
    <STRING id="STR_BIP_REQ_TIMEOUT"/>
    <STRING id="STR_BIP_NOT_FOUND"/>
    <STRING id="STR_BIP_FORBIDDEN"/>
    <STRING id="STR_BIP_BAD_REQUEST"/>
    
    <STRING id="STR_BIP_UNAUTHORIZED"/>
    <STRING id="STR_BIP_METHOD_NOT_ALLOWED"/>
    <STRING id="STR_BIP_NOT_ACCEPTABLE"/>
    <STRING id="STR_BIP_UNSUPPORT_MEDIA_TYPE"/>
    <STRING id="STR_BIP_INTERNAL_SERVER_ERR"/>
    
    <STRING id="STR_BIP_XML_PARSE_FAILED"/>
    <STRING id="STR_BIP_FSQUOTA_FULL"/>
    <STRING id="STR_BIP_RECEIVED"/>
    <STRING id="STR_BIP_RECEIVE_FAILED"/>
    <STRING id="STR_BIP_COMMA_MARK"/>
    
    <STRING id="STR_BIP_NO_FILES_RECEIVED"/>
    <STRING id="STR_BIP_CURRENT_UNAVAILABLE"/>
    <STRING id="STR_BIP_FILE"/>
    <STRING id="STR_BIP_FILES"/>
    <STRING id="STR_BIP_NOTY_RECV_FOLDER"/>
#ifdef __MMI_USB_SUPPORT__
#ifdef __MMI_USB_SPLIT_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_bt_bip_enter_usb_mode_hdlr"/>
#endif /* __MMI_USB_SPLIT_SUPPORT__ */
#endif /* __MMI_USB_SUPPORT__ */
#ifdef __BIP_PULL_SUPPORT__

    <STRING id="STR_BIP_OPTION_GET"/>
    <STRING id="STR_BIP_OPTION_GET_ALL"/>
    <STRING id="STR_BIP_OPTION_DETAIL"/>
    <STRING id="STR_BIP_OPTION_GET_THM"/>
    <STRING id="STR_BIP_IMGLIST_BROWSER"/>

    <STRING id="STR_BIP_STATUS_GETTING_IMGPROP"/>
    <STRING id="STR_BIP_STATUS_GETTING_IMGTHM"/>
    <STRING id="STR_BIP_STATUS_GETTING"/>
    <STRING id="STR_BIP_STATUS_REFRESHING"/>
    <STRING id="STR_BIP_CON_EXIT"/>
    
    <STRING id="STR_BIP_DETAIL_ENCODING"/>
    <STRING id="STR_BIP_DETAIL_PIXEL"/>
    <STRING id="STR_BIP_DETAIL_SIZE"/>
    <STRING id="STR_BIP_DETAIL_NAME"/>
    <STRING id="STR_BIP_ADDTO_GETLIST"/>
    <STRING id="STR_BIP_SHAREDFOLDER_GONE"/>
#endif /* __BIP_PULL_SUPPORT__ */

#endif /* __MMI_BIP_SUPPORT__ */

#if defined(__MMI_OPP_SUPPORT__) || defined(__MMI_BIP_SUPPORT__)
    <STRING id="STR_OPP_NOTY_RECV_FILE_BROWSE"/>
    <STRING id="STR_OPP_NOTY_RECV_FILE_HED"/>
    <STRING id="STR_OPP_NOTY_RECV_FILE_TIL"/>
    <STRING id="STR_OPP_NOTY_RECV_MULTI_FILE_TIL"/>
    <STRING id="STR_BT_DRM_PROHIBITED"/>
#endif 
    /* OBEX authentication*/  

#if defined(__MMI_PBAP_SUPPORT__) 
    /* PBAP */
    <STRING id="STR_PBAP_QUESTION_MARK_ID"/>
    <STRING id="STR_PBAP_CON_AUTH_ID"/>
#endif /* __MMI_PBAP_SUPPORT__ */

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

#ifdef __MMI_FTS_SUPPORT__
    /* __MMI_FTS_SUPPORT__ */ 
    <STRING id="STR_FTP_OPTION_FULLY_CONTROL"/>
    <STRING id="STR_FTP_OPTION_READ_ONLY"/>
    /* Ask for user's permission to be connected via FTP profile */

    <CACHEDATA type="byte" id="NVRAM_FTP_ACCESS_RIGHT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Bluetooth FTP Access Mode </DESCRIPTION>
    </CACHEDATA>

#endif
    /*  received */
#ifdef __MMI_FTC_SUPPORT__
    /* __MMI_FTC_SUPPORT__ */ 
   <STRING id="STR_FTP_FILE_RECEIVED"/>
    <STRING id="STR_FTP_FILE_BROWSER"/>
    <STRING id="STR_FTP_OPTION_GET"/>
    <STRING id="STR_FTP_OPTION_BACK_TO_ROOT_DIR"/>
    /* Ask for exit FTP connection ? */
    <STRING id="STR_FTP_CON_EXIT"/>
    <STRING id="STR_FTP_NOTY_RECV_FILE_BROWSE"/>
    <STRING id="STR_FTP_NOTY_RECV_FILE_TIL"/>
    <STRING id="STR_FTP_NOTY_RECV_FILE_TIL_SINGLE"/>
    <STRING id="STR_FTP_DETAIL_DATE"/>
    <STRING id="STR_FTP_DETAIL_SIZE"/>
    <STRING id="STR_FTP_DETAIL_NAME"/>

    <STRING id="STR_FTP_NOTIFY_BROWSE_FILES_FAILED"/>
    <STRING id="STR_FTP_NOTIFY_GOEP_STATUS_BUSY"/>
    <STRING id="STR_FTP_NOTIFY_WORK_FOLDER_NO_EXIST"/>
    <STRING id="STR_FTP_DEV_BUSY"/>
#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    <STRING id="STR_FTP_OPTION_GET_SEVERAL"/>
    <STRING id="STR_FTP_OPTION_GET_ALL"/>
    <STRING id="STR_FTP_LIST_ARRIVE_MAX"/>
    <STRING id="STR_FTP_NO_FILE_CURR_FOLDER"/>
    <STRING id="STR_FTP_GET_ALL_CONFIRM_HEAD"/>
    <STRING id="STR_FTP_GET_ALL_CONFIRM_TAIL"/>
    <STRING id="STR_FTP_FILE_UNFINISHED"/>
    <STRING id="STR_FTP_GET_SEVERAL_GET_MARKED_FILE"/>
#endif /*__MMI_FTC_MULTIPULL_SUPPORT__*/

    /* FTP General */
    /* FTP profile disconnected */
    <STRING id="STR_FTP_CON_DISCONNECTED"/>
#endif

#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_ftp_enter_usb_ms_callback"/>
#endif /* __MMI_USB_SUPPORT__ */

#endif  /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__) && !defined(_MMI_BT_ULTRA_SLIM_)
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_bt_setting_storage_fmgr_notify_hdlr"/>
#endif

#ifdef __MMI_OPP_SUPPORT__
    <STRING id="STR_OPP_APPNAME"/>
    <STRING id="STR_OPP_RECV_ROOT_DIR_FULL"/>
    <STRING id="STR_OPP_RECV_FILE_IND"/>
    <STRING id="STR_OPP_RECV_FILES_IND"/>
#ifdef __MMI_BT_RECV_FDR_SWITCH__
    <STRING id="STR_OPP_RECV_FILE_IND2"/>
    
    <STRING id="STR_OPP_RECV_FILES_IND2"/>
#endif
/* xuewei delete */
/*    <STRING id="STR_OPP_NOTY_RECV_ACCEPT"/> */
    <STRING id="STR_OPP_UNKNOWN_FILE_TYPE"/>
    <STRING id="STR_OPP_NOTY_RECV_FOLDER"/>
/* xuewei delete */
/*    <STRING id="STR_OPP_OBJ_FROM"/> */
    <STRING id="STR_OPP_UNSUPPORT_FILE_TYPE"/>
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_opp_usb_plugin_hdlr"/>
#endif /* __MMI_USB_SUPPORT__ */
#endif /* __MMI_OPP_SUPPORT__ */ 
#ifdef __MMI_BT_MAP_CLIENT__
   <STRING id="STR_BT_PROF_MAP"/>  
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
    <STRING id="STR_BT_DIALER_USED_BY_APP"/>  
    <STRING id="STR_ID_BT_DIALER"/>
    <STRING id="STR_BT_MESSAGE"/>
    <STRING id="STR_BT_BTMUSIC"/>
    <STRING id="STR_BT_DIALER_RELEASE_DEV_CONN"/>
    <STRING id="STR_BT_DISCONN_ALL_CONN_CNF" />
    <STRING id="STR_BT_CONN_POP"/>
    <STRING id="STR_BT_DISCONN_POP"/>
    <STRING id="STR_BT_DISCONN_PROMPT"/>
    <STRING id="STR_BT_RELEASE_CONN_PROMPT"/>
    <STRING id="STR_BT_QUICK_CONN_PROMPT"/>
    <STRING id="STR_BT_HEADSET_CONN_PROMPT"/>
#endif //__MMI_BT_DIALER_SUPPORT__
    <STRING id="STR_BT_SERVICE_UNAVAILABLE"/>
#ifdef __MMI_BTD_BOX_UI_STYLE__
    <STRING id="STR_BT_BOX_USED_BY_APP"/>  
    <STRING id="STR_BT_DISCONN_BTBOX_PROMPT"/>  
#endif
	/*  BT BOX acl timeout disconnect notify string */
#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
   <STRING id="STR_BT_TIMEOUT_DISCON_ED"/>
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

#if defined(__MMI_APP_MANAGER_SUPPORT__)
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    <IMAGE id="IMG_BT_MAIN_MENU_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\BlueTooth.png"</IMAGE>
    #endif
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
#ifdef  __FTE_NON_SLIM_RES__
<IMAGE id="IMG_BT_MENU_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\SB_BT.png"</IMAGE>
#if !defined(_MMI_BT_ULTRA_SLIM_) || defined (__MMI_BT_DIALER_SUPPORT__)
    <IMAGE id="IMG_BT_SCH_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_Search"</IMAGE>
    <IMAGE id="IMG_BT_DEV_PRT" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_print.png"</IMAGE>
    <IMAGE id="IMG_BT_DEV_LAP" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_LAP.png"</IMAGE>
  #endif
    <IMAGE id="IMG_BT_DEV_MOB" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_MOB.png"</IMAGE>
    <IMAGE id="IMG_BT_DEV_EAR" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_EAR.png"</IMAGE>
    <IMAGE id="IMG_BT_DEV_OTHER" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_other.png"</IMAGE>
    //<IMAGE id="IMG_BT_PASSKEY_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\star.png"</IMAGE>
    //<IMAGE id="IMG_BT_CONNECTION_AUDIO" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\Audio_channel.bmp"</IMAGE>
    <IMAGE id="IMG_BT_CONNECTION_DATA" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\Data_channel.png"</IMAGE>
#else
    <IMAGE id="IMG_BT_MENU_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\SB_BT.bmp"</IMAGE>
#if !defined(_MMI_BT_ULTRA_SLIM_) || defined (__MMI_BT_DIALER_SUPPORT__)
    <IMAGE id="IMG_BT_SCH_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_Search"</IMAGE>
    <IMAGE id="IMG_BT_DEV_PRT" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_print.png"</IMAGE>
    <IMAGE id="IMG_BT_DEV_LAP" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_LAP.png"</IMAGE>
#endif
    <IMAGE id="IMG_BT_DEV_MOB" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_MOB.png"</IMAGE>
    <IMAGE id="IMG_BT_DEV_EAR" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_EAR.png"</IMAGE>
    <IMAGE id="IMG_BT_DEV_OTHER" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\OBT_other.png"</IMAGE>
    //<IMAGE id="IMG_BT_PASSKEY_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\star.png"</IMAGE>
    //<IMAGE id="IMG_BT_CONNECTION_AUDIO" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\Audio_channel.bmp"</IMAGE>
    <IMAGE id="IMG_BT_CONNECTION_DATA" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\Data_channel.bmp"</IMAGE>
#endif 
#ifdef __MMI_BIP_SUPPORT__
    <IMAGE id="IMG_BIP_DEFAULT_THM" >CUST_IMG_PATH"\\\\MainLCD\\\\Bluetooth\\\\BIP\\\\default_thm.gif"</IMAGE>
#endif /* __MMI_BIP_SUPPORT__  */

#if defined(__MMI_HIDD_SUPPORT__)
#ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="HID_IMG_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_BACKGROUND.gif"</IMAGE>

    <IMAGE id="MOUSE_IMG_UP_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_UP_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_UP_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_UP_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_DOWN.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_DOWN.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_DOWN.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_DOWN.gif"</IMAGE>
    <IMAGE id="MOUSE_IMG_COMMON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_ICON.gif"</IMAGE>
    
    <IMAGE id="DESKTOP_IMG_01_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_01_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_01_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_01_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_DOWN.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_DOWN.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_DOWN.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_DOWN.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_DOWN.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_DOWN.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_DOWN.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_DOWN.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_DOWN.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_DOWN.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>

    <IMAGE id="MEDIA_PLAYER_IMG_01_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_01_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_01_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_01_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_DOWN.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_DOWN.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_DOWN.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_DOWN.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>

#if 0
    <IMAGE id="PRESENTER_IMG_01_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_01_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_01_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_01_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY01_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_KEY03_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_COMMON_EMPTY_DISABLE.gif"</IMAGE>

    <IMAGE id="PRESENTER_MOUSE_IMG_UP_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_UP_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_UP_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_UP_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_DOWN.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_DISABLE.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_OFF.gif"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_DOWN.gif"</IMAGE>
#endif
#else
    <IMAGE id="HID_IMG_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_BACKGROUND.gif"</IMAGE>

    <IMAGE id="DESKTOP_IMG_01_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_01_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_01_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_01_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_02_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY02_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_03_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_04_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY04_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_05_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY05_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_06_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY06_DOWN.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_07_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY07_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_08_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY08_DOWN.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_09_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY09_DOWN.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_10_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY10_DOWN.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_OFF.bmp"</IMAGE>
    //<IMAGE id="DESKTOP_IMG_11_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY11_DOWN.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="DESKTOP_IMG_12_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY12_DOWN.bmp"</IMAGE>

    <IMAGE id="MOUSE_IMG_UP_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_UP_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_UP_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_UP_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_UP_DOWN.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_DOWN_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_DOWN_DOWN.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_LEFT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_LEFT_DOWN.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_OFF.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_RIGHT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_RIGHT_DOWN.bmp"</IMAGE>
    <IMAGE id="MOUSE_IMG_COMMON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_COMMON_ICON.bmp"</IMAGE>

    <IMAGE id="MEDIA_PLAYER_IMG_01_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_01_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_01_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_01_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY01_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_02_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY02_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_03_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_DESKTOP_KEY03_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_04_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY04_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_05_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY05_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_06_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY06_DOWN.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_07_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY07_DOWN.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_08_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY08_DOWN.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_OFF.bmp"</IMAGE>
    //<IMAGE id="MEDIA_PLAYER_IMG_09_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY09_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_10_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY10_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_11_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY11_DOWN.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="MEDIA_PLAYER_IMG_12_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MEDIA_KEY12_DOWN.bmp"</IMAGE>
#if 0
    <IMAGE id="PRESENTER_IMG_01_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_01_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_01_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_01_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY01_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_02_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY02_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_03_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY03_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_04_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY04_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_05_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY05_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_06_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY06_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_07_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY07_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_08_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY08_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_09_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY09_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_10_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY10_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_11_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY11_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY12_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY12_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_IMG_12_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_PRESENT_KEY12_DOWN.bmp"</IMAGE>

    <IMAGE id="PRESENTER_MOUSE_IMG_UP_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_UP_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_UP_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_UP_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGUP_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_DOWN_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_PGDOWN_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_LEFT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_HOME_DOWN.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_DISALBE" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_DISABLE.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_OFF" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_ON" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_OFF.bmp"</IMAGE>
    <IMAGE id="PRESENTER_MOUSE_IMG_RIGHT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\HID\\\\HID_MOUSE_PRESENT_END_DOWN.bmp"</IMAGE>
#endif /* 0*/
#endif /* __MMI_FTE_SUPPORT__ */
#endif  /* __MMI_HIDD_SUPPORT__ */

#ifdef __MMI_BPP_SUPPORT__
#ifdef __MMI_ICON_BAR_SUPPORT__
    <IMAGE id="IMG_BPP_TB_PRINT" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\BPP\\\\TB_print.png"</IMAGE>
    <IMAGE id="IMG_BPP_TB_PRINT_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\BPP\\\\TB_print_dis.png"</IMAGE>
    <IMAGE id="IMG_BPP_TB_ZOOM_IN" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\BPP\\\\TB_zoom_in.png"</IMAGE>
    <IMAGE id="IMG_BPP_TB_ZOOM_IN_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\BPP\\\\TB_zoom_in_dis.png"</IMAGE>
    <IMAGE id="IMG_BPP_TB_ZOOM_OUT" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\BPP\\\\TB_zoom_out.png"</IMAGE>
    <IMAGE id="IMG_BPP_TB_ZOOM_OUT_DISABLED" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\BPP\\\\TB_zoom_out_dis.png"</IMAGE>
#endif
#endif /* __MMI_BPP_SUPPORT__ */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <MENUITEM id="MENU_CONN_BT_POWER" str="STR_BT_POWER" img="IMG_BT_POWER"/>
	
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    <MENUITEM id="MENU_CONN_BT_SET_ANTI_LOST" str="STR_BT_SET_ANTI_LOST" img="IMG_BT_ABOUT"/>    
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */

#ifndef _MMI_BT_ULTRA_SLIM_
    <MENUITEM id="MENU_CONN_BT_SCH_AUDIO_DEV" str="STR_BT_SCH_AUD_DEV" img="IMG_BT_SCH_AUD_DEV"/>
#endif 
#ifndef __MMI_BT_DIALER_SUPPORT__
    <MENUITEM id="MENU_CONN_BT_MYDEV" str="STR_BT_MYDEVICE" img="IMG_BT_MYDEV"/>
#endif
#if defined(__MMI_HIDD_SUPPORT__)
    <MENUITEM id="MENU_CONN_BT_REMOTE_CONTROL" str="STR_BT_REMOTE_CONTROL" img="IMG_BT_REMOTE_CONTROL" highlight="mmi_bt_remote_control_menu_hilight_handler" hint="mmi_bt_remote_control_menu_hint_handler"/>
#endif

    <MENUITEM id="MENU_CONN_BT_SET_NAME" str="STR_BT_DEV_SET_NAME" img="IMG_BT_SET_NAME"/>
#ifndef _MMI_BT_ULTRA_SLIM_
    <MENUITEM id="MENU_CONN_BT_SET_AUDIO_PATH_PHONE" str="STR_BT_DEV_SET_AUDIO_PATH_PHONE" img="IMG_BT_SET_AUDIO_PATH_PHONE"/>

    <MENUITEM id="MENU_CONN_BT_SET_AUDIO_PATH_HF" str="STR_BT_DEV_SET_AUDIO_PATH_HF" img="IMG_BT_SET_AUDIO_PATH_HF"/>
#endif 
#if defined(__MMI_SIMAP_SUPPORT__)
    <MENUITEM id="MENU_CONN_BT_SET_SIMAP" str="STR_BT_DEV_SET_SIMAP" img="IMG_BT_SET_SIMAP"/>
#endif
#ifndef _MMI_BT_ULTRA_SLIM_
    <MENUITEM id="MENU_CONN_BT_SET_DEV_ADDR" str="STR_BT_DEV_SET_DEV_ADDR" img="IMG_BT_SET_DEV_ADDR"/>
#endif 
    <MENUITEM id="MENU_CONN_BT_SET_STORAGE" str="STR_GLOBAL_STORAGE" img="IMG_BT_SET_STORAGE"/>

#if defined(__MTK_INTERNAL__)
    <MENUITEM id="MENU_CONN_BT_ABOUT" str="STR_BT_ABOUT" img="IMG_BT_ABOUT"/>
#endif
#ifndef _MMI_BT_ULTRA_SLIM_
    <MENU id="MENU_CONN_BT_SET_AUDIO_PATH" type="APP_SUB" str="STR_BT_DEV_SET_AUDIO_PATH" img="IMG_BT_SET_AUDIO_PATH"> 
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_SET_AUDIO_PATH_PHONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_AUDIO_PATH_HF</MENUITEM_ID>
    </MENU>
#endif 

#ifdef __MMI_FTS_SUPPORT__
    <MENUITEM id="MENU_CONN_BT_SET_PERMISSION" str="STR_BT_SET_SHARE_PERMISSION" img="IMG_BT_SET_PERMISSION"/>    
#elif defined (__BIP_PULL_SUPPORT__)
    <MENUITEM id="MENU_CONN_BT_SET_IMAGE_FOLDER" str="STR_BT_SET_SHARE_IMAGE_FOLDER" img="IMG_BT_SET_IMAGE_FOLDER" highlight="mmi_bt_img_fldr_setting_hilight_hdlr" hint="mmi_bt_img_fldr_setting_hint_hdlr"/>        
#endif	

#ifdef __MMI_FTS_SUPPORT__
    <STRING id="STR_BT_SET_PERMISSION"/>
    <STRING id="STR_BT_SET_SHARE_PERMISSION"/>
#endif
#if defined (__BIP_PULL_SUPPORT__)
    <STRING id="STR_BT_SET_IMAGE_FOLDER"/>
    <STRING id="STR_BT_SET_SHARE_IMAGE_FOLDER"/>
#endif
    <STRING id="STR_ID_FAILED_SHARE_AS_DILAER_CONNED"/>
#ifdef __MMI_BTD_BOX_UI_STYLE__
    <STRING id="STR_ID_FAILED_SHARE_AS_BTBOX_CONNED"/>
#endif

/* Dialor support */
#ifdef __MMI_BT_DIALER_SUPPORT__
#if 0 
 <MENU id="MENU_CONN_BT_DIALOR_CALL" str="STR_BT_CALL"></MENU>
#ifdef __MMI_BT_MAP_CLIENT__
 <MENU id="MENU_CONN_BT_DIALOR_MESSAGE" str="STR_BT_MESSAGE"></MENU>
#endif
#ifdef __MMI_BT_PBAP_CLIENT__
 <MENU id="MENU_CONN_BT_DIALOR_PHONEBOOK" str="STR_BT_PHONEBOOK"></MENU>
 <MENU id="MENU_CONN_BT_DIALOR_CALLLOGS" str="STR_BT_CALLLOG"></MENU>
#endif
#ifdef __MMI_BT_SPEAKER_SUPPORT__
 <MENU id="MENU_CONN_BT_DIALOR_BTMUSIC" str="STR_BT_BTMUSIC"></MENU>
#endif
    <MENU id="MENU_CONN_BT_DIALOR" type="APP_SUB" str="STR_ID_BT_DIALER" img="IMG_BT_SET_VIS">             
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_DIALOR_CALL</MENUITEM_ID>
#ifdef __MMI_BT_MAP_CLIENT__  
        <MENUITEM_ID>MENU_CONN_BT_DIALOR_MESSAGE</MENUITEM_ID>
#endif
#ifdef __MMI_BT_PBAP_CLIENT__
        <MENUITEM_ID>MENU_CONN_BT_DIALOR_PHONEBOOK</MENUITEM_ID>
		<MENUITEM_ID>MENU_CONN_BT_DIALOR_CALLLOGS</MENUITEM_ID>
#endif
#ifdef __MMI_BT_SPEAKER_SUPPORT__
		<MENUITEM_ID>MENU_CONN_BT_DIALOR_BTMUSIC</MENUITEM_ID>
#endif
    </MENU>
    #endif
#endif 
/* visibility configuration menu */
#if !defined(__MMI_BT_TEMP_VISIBILITY__)
    <MENU id="MENU_CONN_BT_SET_VIS" str="STR_BT_DEV_SET_VIS" img="IMG_BT_SET_VIS"></MENU>
#else
    <MENU id="MENU_CONN_BT_SET_VIS_PERMANENT_ON" str="STR_BT_DEV_SET_VIS_PERMANENT_ON" img="IMG_BT_SET_VIS_PERMANENT_ON"></MENU>

    <MENU id="MENU_CONN_BT_SET_VIS_TEMPORARY_ON" str="STR_BT_DEV_SET_VIS_TEMPORARY_ON" img="IMG_BT_SET_VIS_TEMPORARY_ON"></MENU>

    <MENU id="MENU_CONN_BT_SET_VIS_OFF" str="STR_GLOBAL_OFF" img="IMG_BT_SET_VIS_OFF"></MENU>

    <MENU id="MENU_CONN_BT_SET_VIS" type="APP_SUB" str="STR_BT_DEV_SET_VIS" img="IMG_BT_SET_VIS">             
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_SET_VIS_PERMANENT_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_VIS_TEMPORARY_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_VIS_OFF</MENUITEM_ID>
    </MENU>
#endif
#if !defined(_MMI_BT_ULTRA_SLIM_) || defined(__MMI_BT_APPLICATION_BQB__)
    <MENU id="MENU_CONN_BT_SET" type="APP_SUB" str="STR_GLOBAL_ADVANCED" img="IMG_BT_SET">
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_SET_AUTH</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_AUDIO_PATH</MENUITEM_ID>
#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
        <MENUITEM_ID>MENU_CONN_BT_SET_STORAGE</MENUITEM_ID>
#endif  // defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
        <MENUITEM_ID>MENU_CONN_BT_SET_SHARING</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_PERMISSION</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_IMAGE_FOLDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_REMOTE_CONTROL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_SIMAP</MENUITEM_ID> 
        <MENUITEM_ID>MENU_CONN_BT_SET_DEV_ADDR</MENUITEM_ID>
    </MENU>
 #endif


#if (defined(__MMI_MAINLCD_240X400__) && defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__))
    <MENU id="MENU_CONN_BT_MAIN" type="APP_SUB" str="STR_GLOBAL_BLUETOOTH" img="MAIN_MENU_BT_ICON" highlight="mmi_bt_main_hilight_handler"
      shortcut="ON" shortcut_img="MAIN_MENU_BT_ICON" launch="mmi_bt_entry_main_menu">
#else
    <MENU id="MENU_CONN_BT_MAIN" type="APP_SUB" str="STR_GLOBAL_BLUETOOTH" img="IMG_BT_MENU_TITLE" highlight="mmi_bt_main_hilight_handler"
      shortcut="ON" shortcut_img="IMG_BT_MENU_TITLE" launch="mmi_bt_entry_main_menu">             
#endif
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_POWER</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_VIS</MENUITEM_ID>
#ifndef __MMI_BT_DIALER_SUPPORT__
        <MENUITEM_ID>MENU_CONN_BT_MYDEV</MENUITEM_ID>
#endif
#ifndef _MMI_BT_ULTRA_SLIM_
        <MENUITEM_ID>MENU_CONN_BT_SCH_AUDIO_DEV</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_NAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_ABOUT</MENUITEM_ID>
#else
        <MENUITEM_ID>MENU_CONN_BT_SET_NAME</MENUITEM_ID>
    #ifdef __MMI_BT_APPLICATION_BQB__
        <MENUITEM_ID>MENU_CONN_BT_SET</MENUITEM_ID>
    #else
      #if defined(__MMI_HIDD_SUPPORT__)
        <MENUITEM_ID>MENU_CONN_BT_REMOTE_CONTROL</MENUITEM_ID>
      #endif /*__MMI_HIDD_SUPPORT__*/
    #endif
        <MENUITEM_ID>MENU_CONN_BT_ABOUT</MENUITEM_ID>
#endif 
#if defined(__MMI_BT_ANTI_LOST_BY_RSSI__) && !defined(__MMI_BT_BTBOX_NOLCD__)
       <MENUITEM_ID>MENU_CONN_BT_SET_ANTI_LOST</MENUITEM_ID>
#endif /* __MMI_BT_ANTI_LOST_BY_RSSI__ && !__MMI_BT_BTBOX_NOLCD__ */
    </MENU>

#else

#if (defined(__MMI_MAINLCD_240X400__) && defined (__MMI_BI_DEGREE_MAIN_MENU_STYLE__))
    <MENU id="MENU_CONN_BT_MAIN" type="APP_SUB" highlight="mmi_bt_main_hilight_handler">
#else
    <MENU id="MENU_CONN_BT_MAIN" type="APP_SUB" highlight="mmi_bt_main_hilight_handler">             
#endif
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_POWER</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET_VIS</MENUITEM_ID>
        #ifndef __MMI_BT_DIALER_SUPPORT__
        <MENUITEM_ID>MENU_CONN_BT_MYDEV</MENUITEM_ID>
        #endif
#ifndef _MMI_BT_ULTRA_SLIM_
        <MENUITEM_ID>MENU_CONN_BT_SCH_AUDIO_DEV</MENUITEM_ID>
#endif 
        <MENUITEM_ID>MENU_CONN_BT_SET_NAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_SET</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_ABOUT</MENUITEM_ID>
    </MENU>

#endif    

#ifdef __MMI_BT_SUPPORT__

#if defined(__MMI_BT_AUTHORIZE__)
    <MENU id="MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_ASK" str="STR_BT_MYDEV_OPT_AUTHORIZE_ALWAYS_ASK"></MENU>

    <MENU id="MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_CONNECT" str="STR_BT_MYDEV_OPT_AUTHORIZE_ALWAYS_CONNECT"></MENU>

    <MENU id="MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_REJECT" str="STR_BT_MYDEV_OPT_AUTHORIZE_ALWAYS_REJECT"></MENU>

    <MENU id="MENU_CONN_BT_MYDEV_AUTHORIZE" type="APP_SUB" str="STR_BT_MYDEV_OPT_AUTHORIZE">             
        /* Could write MENUITEM in menu directly */
        <MENUITEM_ID>MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_ASK</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_CONNECT</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BT_MYDEV_AUTHORIZE_ALWAYS_REJECT</MENUITEM_ID>
    </MENU>
#endif

#ifdef __MMI_FTC_SUPPORT__

    <MENUITEM id="MENU_CONN_FTP_FILE_OPTION_GET" str="STR_FTP_OPTION_GET"/>
    <MENUITEM id="MENU_CONN_FTP_FOLDER_OPTION_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_CONN_FTP_GEN_OPTION_REFRESH" str="STR_GLOBAL_REFRESH"/>
    <MENUITEM id="MENU_CONN_FTP_GEN_OPTION_DETAIL" str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR" str="STR_FTP_OPTION_BACK_TO_ROOT_DIR"/>
    <MENUITEM id="MENU_CONN_FTP_GEN_OPTION_DISCONNECT" str="STR_GLOBAL_EXIT"/>
    
 #ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    <MENUITEM id="MENU_CONN_FTP_FILE_OPTION_GET_SEVERAL" str="STR_FTP_OPTION_GET_SEVERAL"/>
    <MENUITEM id="MENU_CONN_FTP_FILE_OPTION_GET_ALL" str="STR_FTP_OPTION_GET_ALL"/>
    <MENUITEM id="MENU_CONN_FTP_GET_SEVERAL_MARK" str="STR_GLOBAL_MARK"/>
    <MENUITEM id="MENU_CONN_FTP_GET_SEVERAL_UNMARK" str="STR_GLOBAL_UNMARK"/>
    <MENUITEM id="MENU_CONN_FTP_GET_SEVERAL_UNMARK_ALL" str="STR_GLOBAL_UNMARK_ALL"/>
    <MENUITEM id="MENU_CONN_FTP_GET_SEVERAL_GET_MARKED_FILE" str="STR_FTP_GET_SEVERAL_GET_MARKED_FILE"/>

    <MENU id="MENU_CONN_FTP_GET_SEVERAL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">             
         <MENUITEM_ID>MENU_CONN_FTP_GET_SEVERAL_MARK</MENUITEM_ID>
         <MENUITEM_ID>MENU_CONN_FTP_GET_SEVERAL_UNMARK</MENUITEM_ID>
         <MENUITEM_ID>MENU_CONN_FTP_GET_SEVERAL_UNMARK_ALL</MENUITEM_ID>
         <MENUITEM_ID>MENU_CONN_FTP_GET_SEVERAL_GET_MARKED_FILE</MENUITEM_ID>
     </MENU>

 #endif /*__MMI_FTC_MULTIPULL_SUPPORT__*/

    <MENU id="MENU_CONN_FTP_FILE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">             
        <MENUITEM_ID>MENU_CONN_FTP_FILE_OPTION_GET</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_FILE_OPTION_GET_SEVERAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_FILE_OPTION_GET_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_DISCONNECT</MENUITEM_ID>
    </MENU>
    <MENU id="MENU_CONN_FTP_FOLDER_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">             
        <MENUITEM_ID>MENU_CONN_FTP_FOLDER_OPTION_OPEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_DISCONNECT</MENUITEM_ID>
    </MENU>
    <MENU id="MENU_CONN_FTP_EMPTY_FOLDER_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">             
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_FTP_GEN_OPTION_DISCONNECT</MENUITEM_ID>
    </MENU>

#endif /* __MMI_FTC_SUPPORT__ */

#ifdef __MMI_BIP_SUPPORT__
#ifdef __BIP_PULL_SUPPORT__
    <MENUITEM id="MENU_CONN_BIP_OPTION_GET" str="STR_BIP_OPTION_GET"/>
    <MENUITEM id="MENU_CONN_BIP_OPTION_GET_ALL" str="STR_BIP_OPTION_GET_ALL"/>
    <MENUITEM id="MENU_CONN_BIP_OPTION_IMG_DETAIL" str="STR_BIP_OPTION_DETAIL"/>
    <MENUITEM id="MENU_CONN_BIP_OPTION_GET_THM" str="STR_BIP_OPTION_GET_THM"/>
    <MENUITEM id="MENU_CONN_BIP_OPTION_REFRESH" str="STR_GLOBAL_REFRESH"/>
    <MENUITEM id="MENU_CONN_BIP_OPTION_DISCONNECT" str="STR_GLOBAL_EXIT"/>
    
    <MENU id="MENU_CONN_BIP_IMGLIST_OPTION" type="APP_SUB" str="STR_GLOBAL_OPTIONS">             
        <MENUITEM_ID>MENU_CONN_BIP_OPTION_GET</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BIP_OPTION_IMG_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BIP_OPTION_GET_THM</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BIP_OPTION_GET_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BIP_OPTION_REFRESH</MENUITEM_ID>
        <MENUITEM_ID>MENU_CONN_BIP_OPTION_DISCONNECT</MENUITEM_ID>
    </MENU>

#endif /* __BIP_PULL_SUPPORT__ */
#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_BPP_SUPPORT__
    <MENUITEM id="MENU_BPP_PRINT" str="STR_GLOBAL_PRINT"/>
    <MENUITEM id="MENU_BPP_PREVIEW" str="STR_GLOBAL_PREVIEW"/>
    <MENUITEM id="MENU_BPP_SETTING" str="STR_GLOBAL_SETTINGS"/>
  
    <MENUITEM id="MENU_BPP_CHG_PRINTER" str="STR_BT_BPP_SP_CHANGE_PRINTER"/>
    <MENUITEM id="MENU_BPP_GET_CAPBILITY" str="STR_BT_BPP_GET_ATTR"/>
    <MENUITEM id="MENU_BPP_SAVE_SETTING" str="STR_GLOBAL_SAVE"/>
    <MENUITEM id="MENU_BPP_ZOOM_IN" str="STR_BT_BPP_SP_ZOOM_IN"/>
    <MENUITEM id="MENU_BPP_ZOOM_OUT" str="STR_BT_BPP_SP_ZOOM_OUT"/>

    <MENU id="MENU_BPP_PREVIEW_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_BPP_PRINT</MENUITEM_ID>
        <MENUITEM_ID>MENU_BPP_ZOOM_IN</MENUITEM_ID>
        <MENUITEM_ID>MENU_BPP_ZOOM_OUT</MENUITEM_ID>
    </MENU>
    <MENU id="MENU_BPP_SETTING_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">             
        <MENUITEM_ID>MENU_BPP_PRINT</MENUITEM_ID>
        <MENUITEM_ID>MENU_BPP_PREVIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_BPP_CHG_PRINTER</MENUITEM_ID>
        <MENUITEM_ID>MENU_BPP_GET_CAPBILITY</MENUITEM_ID>
        <MENUITEM_ID>MENU_BPP_SAVE_SETTING</MENUITEM_ID>
    </MENU>

#endif /* __MMI_BPP_SUPPORT__ */
#ifdef __MMI_OPP_SUPPORT__
    <MENUITEM id="MENU_ID_FMGR_FWD_BT" str="STR_GLOBAL_VIA_BLUETOOTH"/>
#endif
    <!------------------------------------------------------Screen Resource Area------------------------------------------------------>
    <SCREEN id="SCR_EXTDEV_BT_BEGIN"/>
    <SCREEN id="GRP_ID_BT_CM"/>
    <SCREEN id="GRP_ID_BT_CM_POWER_ON_CNF"/>
    <SCREEN id="GRP_ID_BT_CM_SELECT_DEVICE"/>
	<SCREEN id="GRP_ID_BT_CM_INQUIRY_DEVICE"/>
    <SCREEN id="GRP_ID_BT_CM_PROGRESS"/>
    <SCREEN id="GRP_ID_BT_CM_PASSKEY_INPUT"/>
    <SCREEN id="GRP_ID_BT_CM_SECURITY_CNF"/>
    <SCREEN id="GRP_ID_BT_CM_PASSKEY_NOTIFY"/>
    <SCREEN id="GRP_ID_BT_CM_AUTH"/>
    <SCREEN id="GRP_ID_BT_CM_BLOCK_CNF"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_HFP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_HSP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_BIP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_FTP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_OPP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_SPP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_DUN"/>    
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_FAX"/>        
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_PBAP"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_HID"/>    
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_SYNC"/>    
    <SCREEN id="GRP_ID_BT_CM_CONNECT_ACCEPT_CNF_SAP"/>
    <SCREEN id="GRP_ID_BT_PBAPC_AUTHENTICATE"/>
    /* common screen id */        
    <SCREEN id="SCR_BT_MAIN"/>
    <SCREEN id="SCR_BT_POWER_ON_CNF"/>
    <SCREEN id="SCR_BT_RELEASE_DEV_CONN_CNF"/>
    <SCREEN id="SCR_BT_RELEASE_ALL_CONN_CNF"/>    
    <SCREEN id="SCR_BT_RELEASE_AUD_CONN_CNF"/>
    <SCREEN id="SCR_BT_POWER_PRO"/>
    <SCREEN id="SCR_BT_REL_ALL_CONN_PRO"/>
    <SCREEN id="SCR_BT_REL_DEV_CONN_PRO"/>
    <SCREEN id="SCR_BT_REL_PROFILE_CONN_PRO"/>
    <SCREEN id="SCR_BT_SWITCH_LIMIT_DISCOVER_MODE"/>
    <SCREEN id="SCR_BT_LIMIT_DISCOVER_MODE"/>

    <SCREEN id="SCR_BT_SCH_PRO"/>
    <SCREEN id="SCR_BT_SCH_DISCONNECT_SCO"/>    
    <SCREEN id="SCR_BT_SCH_RES"/>
    <SCREEN id="SCR_BT_SCH_CANCEL_PRO"/>
    <SCREEN id="SCR_BT_BOND"/>
    <SCREEN id="SCR_BT_REFREAH_PROFILE"/>
    <SCREEN id="SCR_BT_PIN_INPUT"/>
    <SCREEN id="SCR_PBAPC_PASSWORD"/>
    <SCREEN id="SCR_BT_PAIR_PRO"/>
    <SCREEN id="SCR_BT_AUTH_CONFIRM"/>
    <SCREEN id="SCR_BT_CONNECT_CNF"/>
    <SCREEN id="SCR_BT_CONNECTING"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_HFP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_HSP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_BIP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_FTP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_OPP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_SPP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_DUN"/>    
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_FAX"/>        
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_PBAP"/>
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_HID"/>    
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_SYNC"/>    
    <SCREEN id="SCR_BT_CONNECT_ACCEPT_CNF_SAP"/>
    <SCREEN id="SCR_BT_NUMERIC_CONFIRM"/>
    <SCREEN id="SCR_BT_PASSKEY_NOTIFY"/>
    <SCREEN id="SCR_BT_UNBLOCKING"/>
    <SCREEN id="SCR_BT_DEVICE_BLOCK_CNF"/>

    <SCREEN id="SCR_BT_REMOTE_CTRL_POWER_CONFIRM"/>
    <SCREEN id="SCR_BT_REMOTE_CTRL_CONN_AUTH"/>
    <SCREEN id="SCR_BT_REMOTE_CTRL_APP_SELECT"/>
    <SCREEN id="SCR_BT_REMOTE_CTRL_APP"/>
    <SCREEN id="SCR_BT_REMOTE_CTRL_UNPLUG_CONFIRM"/>
    <SCREEN id="SCR_BT_REMOTE_CTRL_DISC_CONFIRM"/>
    <SCREEN id="SCR_BT_REMOTE_CTRL_PROGRESS"/>

    <SCREEN id="SCR_BT_MYDEV"/>
    <SCREEN id="SCR_BT_MYDEV_OPT"/>
    <SCREEN id="SCR_BT_MYDEV_PROF_CHO"/>
    <SCREEN id="SCR_BT_MYDEV_CON"/>
    <SCREEN id="SCR_BT_MYDEV_CONNECTED_PROF"/>
    <SCREEN id="SCR_BT_MYDEV_DISCON"/>
    <SCREEN id="SCR_BT_MYDEV_SIM_CNF"/>
    <SCREEN id="SCR_BT_MYDEV_SIM_SEL"/>
    <SCREEN id="SCR_BT_MYDEV_REN"/>
    <SCREEN id="SCR_BT_MYDEV_REN_OPT"/>
    <SCREEN id="SCR_BT_MYDEV_AUTH"/>
    <SCREEN id="SCR_BT_MYDEV_DEL"/>
    <SCREEN id="SCR_BT_MYDEV_DEL_ALL"/>
    <SCREEN id="SCR_BT_MYDEV_SUP_PROFILE"/>
    <SCREEN id="SCR_BT_MYDEV_SCH"/>

    <SCREEN id="SCR_BT_ACT_DEV"/>
    <SCREEN id="SCR_BT_DISC_PROC"/>
    <SCREEN id="SCR_BT_ENFORCE_DISC_CNF"/>

    <SCREEN id="SCR_BT_SET"/>
    <SCREEN id="SCR_BT_SET_NAME"/>
    <SCREEN id="SCR_BT_SET_NAME_OPT"/>
    <SCREEN id="SCR_BT_SET_VIS"/>
    <SCREEN id="SCR_BT_SET_VIS_MENU"/>
    <SCREEN id="SCR_BT_SET_AUTH"/>
    <SCREEN id="SCR_BT_SET_AUDIO_PATH"/>
    <SCREEN id="SCR_BT_SET_BLOCK_LIST"/>    
    <SCREEN id="SCR_BT_SET_FTP"/>
    <SCREEN id="SCR_BT_SET_SIMAP"/>
    <SCREEN id="SCR_BT_SET_STORAGE"/>
    <SCREEN id="SCR_BT_SET_SHARING"/>
    <SCREEN id="SCR_BT_SET_PERMISSION"/>
    <SCREEN id="SCR_BT_SET_IMAGE_FOLDER"/>
    <SCREEN id="SCR_BT_SET_STORAGE_CONFIRM"/>
    <SCREEN id="SCR_BT_SEL_DRV1"/>
    <SCREEN id="SCR_BT_SEL_DRV2"/>
    <SCREEN id="SCR_BT_SEL_DRV3"/>
    <SCREEN id="SCR_BT_SEL_DRV4"/>

    /* BT sending auto prompt switch */
    <SCREEN id="SCR_BT_SEND_DUMMY"/>
    <SCREEN id="SCR_BT_SEND_DEVICE_OPTION"/>
    <SCREEN id="SCR_BT_SEND_CNF_TO_DEFAULT"/>
    <SCREEN id="SCR_BT_SEND_CNF_SET_DEFAULT"/>
    <SCREEN id="SCR_BT_SEND_CNF_POWER_ON"/>

    <SCREEN id="SCR_BT_ABOUT"/>
    <SCREEN id="SCR_BT_MY_SPECIFIC_DEV"/>
    <SCREEN id="SCR_BT_MY_SPECIFIC_DEV_DUMMY"/>
    <SCREEN id="SCR_BT_SWITCH_SPEECH_PATH"/>
    /* Configure Default Headset */
    <SCREEN id="SCR_BT_CONNECT_LAST_HEADSET"/>
    <SCREEN id="SCR_BT_NOT_ALLOWED"/>
    <SCREEN id="SCR_BT_NOT_PROHIBIT_BY_SIMAP"/>
    <SCREEN id="SCR_BT_SET_DEFAULT_HS"/>
    <SCREEN id="SCR_BT_CM_LAST"/>
    
    <SCREEN id="SCR_HF_CONNECTING"/>
    <SCREEN id="SCR_HF_RELEASING"/>
    
    <SCREEN id="SCR_OPP_NOTY_FILE_RECV"/>
    <SCREEN id="SCR_OPP_NOTY_RECV_ACCEPT"/>
    <SCREEN id="SCR_OPP_SENDING"/>
    <SCREEN id="SCR_OPP_ABORTING"/>
    <SCREEN id="SCR_OPP_DISCONNECTING"/>

    <SCREEN id="SCR_FTP_SETTING"/>
    <SCREEN id="SCR_FTP_ACCESS_RIGHT_OPTION"/>
    <SCREEN id="SCR_FTP_SELECT_SHARED_FOLDER"/>
    <SCREEN id="SCR_FTP_NOTY_CONN_REQ"/>
    <SCREEN id="SCR_FTP_FILE_BROWSER"/>
    <SCREEN id="SCR_FTP_NOTY_FILE_RECV"/>
    <SCREEN id="SCR_FTP_RECEIVING"/>
    <SCREEN id="SCR_FTP_DISCONNECTING"/>
    <SCREEN id="SCR_FTP_ABORTING"/>
    <SCREEN id="SCR_FTP_DETAIL_INFO"/>
    <SCREEN id="SCR_FTP_MARK_SEVERAL"/>
    <SCREEN id="SCR_FTP_CONNECTING"/>
    <SCREEN id="SCR_FTP_OPENING_FOLDER"/>    
    <SCREEN id="SCR_FTP_CONNECT_CANCELING"/>
    <SCREEN id="SCR_ID_BT_AVCRP_CT_MAIN"/>
    <SCREEN id="SCR_BPP_DUMMY"/>
    <SCREEN id="SCR_BPP_CONNECTING"/>
    <SCREEN id="SCR_BPP_AUTHENTICATING"/>
    <SCREEN id="SCR_BPP_GETTING"/>
    <SCREEN id="SCR_BPP_PRINT_SETTING"/>
    <SCREEN id="SCR_BPP_LAYOUT_PREVIEW"/>    
    <SCREEN id="SCR_BPP_CREATING"/>    
    <SCREEN id="SCR_BPP_COMPOSING"/>    
    <SCREEN id="SCR_BPP_PRINTING"/>    
    <SCREEN id="SCR_BPP_TROUBLE"/>    
    <SCREEN id="SCR_BPP_DISCONNECTING"/>    
    <SCREEN id="SCR_OBEX_INPUT_AUTHPWD"/>
    <SCREEN id="SCR_BPP_SP_PRINT_SETUP"/>
    <SCREEN id="SCR_BPP_SP_PREVIEW"/>    
    <SCREEN id="SCR_BPP_SP_PRINTING"/>    
    <SCREEN id="SCR_BPP_SP_PASSWORD_INPUT"/>    
    <SCREEN id="SCR_BPP_SP_TROUBLE"/>    
    <SCREEN id="SCR_BPP_SP_DUMMY"/>
    <SCREEN id="SCR_BPP_SP_PRINT_OPTION"/>
    <SCREEN id="SCR_BPP_PRINTER_SETUP_OPTION"/>

    <SCREEN id="GRP_ID_BIP_OBJ_DETAIL"/>
    <SCREEN id="SCR_BIP_SETTING"/>
    <SCREEN id="SCR_BIP_SENDING"/>
    <SCREEN id="SCR_BIP_CONNECTING"/>
    <SCREEN id="SCR_BIP_ABORTING"/>
    <SCREEN id="SCR_BIP_RECEIVING"/>
    <SCREEN id="SCR_BIP_DISCONNECTING"/>
    <SCREEN id="SCR_BIP_IMGLIST_BROWSER"/>
    <SCREEN id="SCR_BIP_IMG_DETAIL"/>
    <SCREEN id="SCR_BIP_THM_PREVIEW"/>
    <SCREEN id="SCR_BIP_IMGLIST_OPTION"/>
    <SCREEN id="SCR_BIP_GETTING_IMGPROP"/>
    <SCREEN id="SCR_BIP_NOTY_CONN_REQ"/>
    <SCREEN id="SCR_BIP_NOTY_FILE_RECV"/>
    <SCREEN id="SCR_BIP_NOTY_CONTINUE_SEND"/>
    <SCREEN id="SCR_BIP_EXIT_CONFIRM"/>
    <SCREEN id="SCR_BIP_CONNECT_CANCELING"/>
    <SCREEN id="SCR_BIP_PUSH_ABORTING"/>
    <SCREEN id="SCR_BIP_RECV_FILE_CONFIRM"/>

    <SCREEN id="GRP_ID_PBAP_AUTHENTICATION"/>
    <SCREEN id="SCR_PBAP_AUTHENTICATING_ID"/>
    <SCREEN id="SCR_PBAP_NOTY_CONN_REQ_ID"/>
    <SCREEN id="SCR_EXTDEV_BT_LAST"/>
    <SCREEN id="GRP_ID_BT_BPP"/>
#ifdef __MMI_BT_DIALER_SUPPORT__   
    <SCREEN id="SCR_BT_INQUIRED_POWER_ON"/>
    <SCREEN id="SCR_BT_DIALER_FRIST_ASK"/>
    <SCREEN id="SCR_BT_DIALER_DISCONNECT_ASK"/>
    <SCREEN id="GRP_ID_BT_CM_CONNECTING_SCR"/>
#endif
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    <SCREEN id="GRP_ID_BT_ANTI_LOST_SETTING"/>
    <SCREEN id="GRP_ID_BT_ANTI_LOST_IND"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND_2"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND_3"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND_4"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND_5"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND_6"/>
    <SCREEN id="SCR_ID_BT_ANTI_LOST_IND_7"/>
#endif

    <EVENT id="EVT_ID_SPPC_CONNECT_CNF" type="SENDER"/>
    <EVENT id="EVT_ID_SPPC_DISCONNECT_CNF" type="SENDER"/>	
    <EVENT id="EVT_ID_SPPC_READY_TO_READ" type="SENDER"/>
    <EVENT id="EVT_ID_SPPC_READY_TO_WRITE" type="SENDER"/>	
    
/*__MMI_BT_SPP_SERVER_MULTI_LINK_SUPPORT__*/
    <EVENT id="EVT_ID_SPPS_CONNECT_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SPPS_DISCONNECT_CNF" type="SENDER"/>	
    <EVENT id="EVT_ID_SPPS_READY_TO_READ" type="SENDER"/>
    <EVENT id="EVT_ID_SPPS_READY_TO_WRITE" type="SENDER"/>	
   
    <!-----------------BT Dialer Service Events begin--------------------------------------------------->
 #ifdef __MMI_BT_DIALER_SUPPORT__
    <EVENT id="EVT_ID_DIALER_EVENT_ID" type="SENDER"/>
    <EVENT id="EVT_ID_DIALER_CONN_EVENT_ID" type="SENDER"/>
    <EVENT id="EVT_ID_DIALER_DISCONN_EVENT_ID" type="SENDER"/>
    <TIMER id="BT_DIALER_DISCONN_TIMER"/>
    <TIMER id="BT_DIALER_CONN_NMGR_POP_TIMER"/>
    <TIMER id="BT_DIALER_AUTO_RECONN_TIMER"/>
 #endif
#endif/*__MMI_BT_SUPPORT__*/
</APP>

#ifdef __MMI_OPP_SUPPORT__
<FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_BT" enabler="mmi_fmgr_forward_bt_send_enabler" handler="mmi_fmgr_to_bt_hdlr"/>
</FILE_TYPES>
#endif
