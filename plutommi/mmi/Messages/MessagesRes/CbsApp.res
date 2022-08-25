#include "mmi_features.h"
#ifdef __MMI_CBS_SUPPORT__
#ifndef __COSMOS_MMI__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_CBS">
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SmsAppResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_CBS_CAPTION"/>
#if (MMI_MAX_SIM_NUM >=2)

#if 0
    <STRING id="STR_ID_CBS_SIM1_CB"/>
    <STRING id="STR_ID_CBS_SIM2_CB"/>
#endif

    <STRING id="STR_ID_CBS_SIM1_NEW_MSG_TITLE"/>
    <STRING id="STR_ID_CBS_SIM2_NEW_MSG_TITLE"/>
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    <STRING id="STR_ID_CBS_NEW_SIM1_MSG_FROM"/>
    <STRING id="STR_ID_CBS_NEW_SIM2_MSG_FROM"/>
#endif
#if(MMI_MAX_SIM_NUM>=3)

#if 0
    <STRING id="STR_ID_CBS_SIM3_CB"/>
#endif
    <STRING id="STR_ID_CBS_SIM3_NEW_MSG_TITLE"/>
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    <STRING id="STR_ID_CBS_NEW_SIM3_MSG_FROM"/>
#endif
#if(MMI_MAX_SIM_NUM>=4)
#if 0
    <STRING id="STR_ID_CBS_SIM4_CB"/>
#endif
    <STRING id="STR_ID_CBS_SIM4_NEW_MSG_TITLE"/>
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    <STRING id="STR_ID_CBS_NEW_SIM4_MSG_FROM"/>
#endif
#endif
#endif
#else
    <STRING id="STR_ID_CBS_NEW_MSG_TITLE"/>
    <STRING id="STR_ID_CBS_NEW_MSG_FROM"/>
#endif
    <STRING id="STR_ID_CBS_RECEIVE_MODE"/>
    <STRING id="STR_ID_CBS_CHANNELS"/>
    <STRING id="STR_ID_CBS_LANGUAGES"/>
    <STRING id="STR_ID_CBS_INBOX"/>
    <STRING id="STR_ID_CBS_SUBSCRIBE"/>
    <STRING id="STR_ID_CBS_CANCEL_SUBSCRIPTION"/>
    <STRING id="STR_ID_CBS_NOT_READY_YET"/>
    <STRING id="STR_ID_CBS_CHNL_FULL"/>
    <STRING id="STR_ID_CBS_CHNL_DUPLICTED"/>
    <STRING id="STR_ID_CBS_ALL_LANGS"/>
    <STRING id="STR_ID_CBS_LANG_OTHERS"/>
    <STRING id="STR_ID_CBS_LANG_UNSPECIFIED"/>
    <STRING id="STR_ID_CBS_CHNL_NAME"/>
    <STRING id="STR_ID_CBS_CHNL_NUMBER"/>
    <STRING id="STR_ID_CBS_MSG_BODY"/>
    <STRING id="STR_ID_CBS_ADD_CHNL"/>
    <STRING id="STR_ID_CBS_EDIT_CHNL"/>

	<STRING id="STR_ID_CBS_LANG_ARABIC"/>
	<STRING id="STR_ID_CBS_LANG_CZECH"/>
	<STRING id="STR_ID_CBS_LANG_DANISH"/>
	<STRING id="STR_ID_CBS_LANG_GERMAN"/>
	<STRING id="STR_ID_CBS_LANG_GREEK"/>
	<STRING id="STR_ID_CBS_LANG_ENGLISH"/>
	<STRING id="STR_ID_CBS_LANG_SPANISH"/>
	<STRING id="STR_ID_CBS_LANG_FINNISH"/>
	<STRING id="STR_ID_CBS_LANG_FRENCH"/>
	<STRING id="STR_ID_CBS_LANG_HEBREW"/>
	<STRING id="STR_ID_CBS_LANG_HUNGARIAN"/>
	<STRING id="STR_ID_CBS_LANG_ICELANDIC"/>
	<STRING id="STR_ID_CBS_LANG_ITALIAN"/>
	<STRING id="STR_ID_CBS_LANG_DUTCH"/>
	<STRING id="STR_ID_CBS_LANG_NORWEGIAN"/>
	<STRING id="STR_ID_CBS_LANG_POLISH"/>
	<STRING id="STR_ID_CBS_LANG_PORTUGUESE"/>
	<STRING id="STR_ID_CBS_LANG_RUSSIAN"/>
	<STRING id="STR_ID_CBS_LANG_SWEDISH"/>
	<STRING id="STR_ID_CBS_LANG_TURKISH"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#ifdef __MMI_SLIM_IMG_RES__
	<IMAGE id="IMG_ID_CBS_COMMON">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Sms\\\\SB_WRITE.bmp"</IMAGE>
	<IMAGE id="IMG_ID_CBS_CHNL_NAME">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Sms\\\\Channel\\\\CH_TITLE.bmp"</IMAGE>
	<IMAGE id="IMG_ID_CBS_CHNL_NUMBER">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Sms\\\\Channel\\\\CH_NB.bmp"</IMAGE>
#else
	<IMAGE id="IMG_ID_CBS_COMMON">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.bmp"</IMAGE>
	<IMAGE id="IMG_ID_CBS_CHNL_NAME">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\Channel\\\\CH_TITLE.bmp"</IMAGE>
	<IMAGE id="IMG_ID_CBS_CHNL_NUMBER">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\Channel\\\\CH_NB.bmp"</IMAGE>
#endif

#ifndef __OP01_FWPBW__
	<IMAGE id="IMG_ID_CBS_SUBSCRIBE">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_BROAD.bmp"</IMAGE>
	<IMAGE id="IMG_ID_CBS_UNSUBSCRIBE">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_CBS_UNSUB.bmp"</IMAGE>
#else /* __OP01_FWPBW__ */
	<IMAGE id="IMG_ID_CBS_SUBSCRIBE">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_BROAD.bmp"</IMAGE>
	<IMAGE id="IMG_ID_CBS_UNSUBSCRIBE">CUST_IMG_PATH"\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_CBS_UNSUB.bmp"</IMAGE>
#endif /* __OP01_FWPBW__ */
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Item Area-->
#if (MMI_MAX_SIM_NUM >=2)
    <MENUITEM id="MENU_ID_CBS_SIM_SELECT_SIM_1" str="STR_GLOBAL_SIM_1"/>
    <MENUITEM id="MENU_ID_CBS_SIM_SELECT_SIM_2" str="STR_GLOBAL_SIM_2"/>
 #if(MMI_MAX_SIM_NUM>=3)
    <MENUITEM id="MENU_ID_CBS_SIM_SELECT_SIM_3" str="STR_GLOBAL_SIM_3"/>
 #if(MMI_MAX_SIM_NUM>=4)
    <MENUITEM id="MENU_ID_CBS_SIM_SELECT_SIM_4" str="STR_GLOBAL_SIM_4"/>
 #endif
 #endif
#endif

    <MENUITEM id="MENU_ID_CBS_CHANNELS" str="STR_ID_CBS_CHANNELS" img="IMG_ID_CBS_COMMON"/>
    <MENUITEM id="MENU_ID_CBS_LANGUAGES" str="STR_ID_CBS_LANGUAGES" img="IMG_ID_CBS_COMMON"/>
    <MENUITEM id="MENU_ID_CBS_INBOX" str="STR_ID_CBS_INBOX" img="IMG_ID_CBS_COMMON"/>

    <MENUITEM id="MENU_ID_CBS_RECEIVE_MODE_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_CBS_RECEIVE_MODE_OFF" str="STR_GLOBAL_OFF"/>

    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_SUBSCRIBE" str="STR_ID_CBS_SUBSCRIBE"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE" str="STR_ID_CBS_CANCEL_SUBSCRIPTION"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_ADD" str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_DELETE" str="STR_GLOBAL_DELETE"/>

    <MENUITEM id="MENU_ID_CBS_VIEWER_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_CBS_VIEWER_OPT_USE_NUM" str="STR_ID_SMS_USE_NUM_ADDRESS"/>
#ifdef __MMI_MESSAGES_USE_URL__
    <MENUITEM id="MENU_ID_CBS_VIEWER_OPT_USE_URL" str="STR_ID_SMS_USE_URL_ADDRESS"/>
#endif

    <!--Menu Tree Area-->
#if (MMI_MAX_SIM_NUM >=2)
	<MENU id="MENU_ID_CBS_SIM_SELECT" type="APP_MAIN" str="STR_ID_CBS_CAPTION">
			<MENUITEM_ID>MENU_ID_CBS_SIM_SELECT_SIM_1</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_CBS_SIM_SELECT_SIM_2</MENUITEM_ID>
 #if(MMI_MAX_SIM_NUM>=3)
                     <MENUITEM_ID>MENU_ID_CBS_SIM_SELECT_SIM_3</MENUITEM_ID>
 #if(MMI_MAX_SIM_NUM>=4)
                    <MENUITEM_ID>MENU_ID_CBS_SIM_SELECT_SIM_4</MENUITEM_ID>
 #endif
 #endif
	</MENU>
#endif

    <MENU id="MENU_ID_CBS_RECEIVE_MODE" type="APP_SUB" flag = "MMI_RG_MENU_FLAG_CHECKBOX" str="STR_ID_CBS_RECEIVE_MODE" img="IMG_ID_CBS_COMMON">
        <MENUITEM_ID>MENU_ID_CBS_RECEIVE_MODE_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_RECEIVE_MODE_OFF</MENUITEM_ID>
    </MENU>

	<MENU id="MENU_ID_CBS_MAIN" type="APP_MAIN" str="STR_ID_CBS_CAPTION">
		<MENUITEM_ID>MENU_ID_CBS_RECEIVE_MODE</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_CBS_CHANNELS</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_CBS_LANGUAGES</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_CBS_INBOX</MENUITEM_ID>
	</MENU>

    <MENU id="MENU_ID_CBS_CHNL_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_SUBSCRIBE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_DELETE</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_CBS_VIEWER_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CBS_VIEWER_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_VIEWER_OPT_USE_NUM</MENUITEM_ID>
#ifdef __MMI_MESSAGES_USE_URL__
        <MENUITEM_ID>MENU_ID_CBS_VIEWER_OPT_USE_URL</MENUITEM_ID>
#endif
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_CBS_SIM_SELECT"/>
    <SCREEN id="SCR_ID_CBS_MAIN_MENU"/>
    <SCREEN id="SCR_ID_CBS_RECEIVE_MODE"/>
    <SCREEN id="SCR_ID_CBS_LANG_LIST"/>
    <SCREEN id="SCR_ID_CBS_CHNL_LIST"/>
    <SCREEN id="SCR_ID_CBS_CHNL_LIST_OPTIONS"/>
    <SCREEN id="SCR_ID_CBS_ADD_CHNL"/>
    <SCREEN id="SCR_ID_CBS_EDIT_CHNL"/>
    <SCREEN id="SCR_ID_CBS_INBOX_LIST"/>
    <SCREEN id="SCR_ID_CBS_VIEWER"/>
    <SCREEN id="SCR_ID_CBS_VIEWER_OPTION"/>
    <SCREEN id="SCR_ID_CBS_NEW_NORMAL_IND"/>
    <SCREEN id="SCR_ID_CBS_NEW_IMMEDIATE_IND"/>

    <!-----------------------------------------------Callback Manager Register------------------------------------------------------>
	<RECEIVER id="EVT_ID_SRV_CBS_NEW_MSG_IND" proc="mmi_cbs_new_msg_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_GS_CHANGE_IND" proc="mmi_cbs_gs_change_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_ADD_MSG" proc="mmi_cbs_msg_changed_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_DEL_MSG" proc="mmi_cbs_msg_changed_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_ADD_CHNL" proc="mmi_cbs_setting_changed_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_DEL_CHNL" proc="mmi_cbs_setting_changed_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_UPDATE_CHNL" proc="mmi_cbs_setting_changed_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_CBS_MODE_CHANGE" proc="mmi_cbs_setting_changed_event_proc"/>
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_cbs_mode_switch_event_hdlr"/>

</APP>
#endif /* __COSMOS_MMI__ */
#endif /*__MMI_CBS_SUPPORT__*/

