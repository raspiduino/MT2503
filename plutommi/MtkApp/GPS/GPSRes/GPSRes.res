#include "MMI_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_GPS">

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <TIMER id="GPS_MGR_NOTIFY_TIMER_ID_1"/>
    <TIMER id="GPS_MGR_NOTIFY_TIMER_ID_2"/>
    <TIMER id="GPS_MGR_NOTIFY_TIMER_ID_3"/>
    <TIMER id="GPS_MGR_NOTIFY_TIMER_ID_4"/>
    <TIMER id="GPS_MGR_NOTIFY_TIMER_ID_5"/>
    <TIMER id="GPS_MGR_SET_MODE_TIMER_ID"/>

    <!-----------------------------------------------------Event handle----------------------------------------------------->
#if !defined(__IOT__)
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="mmi_gps_setting_dtcnt_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="mmi_gps_setting_dtcnt_notify_hdlr"/>
#endif
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_GPS"/>
    <STRING id="STR_ID_GPS_SETTING_MAIN"/>
    <STRING id="STR_ID_GPS_SETTING_RECEIVER"/>
    <STRING id="STR_ID_GPS_SETTING_SELECT"/>
    <STRING id="STR_ID_GPS_SETTING_SAVE"/>
    <STRING id="STR_ID_GPS_SETTING_ASK_SAVE_SETTING"/>
    <STRING id="STR_ID_GPS_SETTING_SAVE_OK"/>
    <STRING id="STR_ID_GPS_SETTING_ASK_SAVE_CHANGED_IF_SAVE"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_SETTING"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_AUTO"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_SEND_LOCATION"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE_NAME"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE_ADDR"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE_PUSH_SMS_NUM"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE_PORT"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE_INVALID_PORT"/>
    <STRING id="STR_ID_GPS_SETTING_AGPS_PROFILE_INVALID_DATA_ACCOUNT"/>
    <STRING id="STR_ID_GPS_SETTING_INPUT_EDITOR_OPTION_DONE"/>
    <STRING id="STR_ID_GPS_SETTING_INPUT_EDITOR_OPTION_CANCEL"/>
    <STRING id="STR_ID_GPS_SETTING_TIME_SYNC"/>
    <STRING id="STR_ID_GPS_SETTING_COLON"/>
    <STRING id="STR_ID_GPS_SETTING_MINI_GPS"/>
    <STRING id="STR_ID_GPS_MGR_NETWORK_CREATE_FAIL"/>
    <STRING id="STR_ID_GPS_MGR_BAD_PUSH_CONTENT"/>
    <STRING id="STR_ID_GPS_MGR_NOT_SUPPORTED"/>
    <STRING id="STR_ID_GPS_MGR_REQ_NOT_ACCEPTED"/>
    <STRING id="STR_ID_GPS_MGR_NO_RESOURCE"/>
    <STRING id="STR_ID_GPS_MGR_NETWORK_DISCONN"/>
    <STRING id="STR_ID_GPS_MGR_REMOTE_ABORT"/>
    <STRING id="STR_ID_GPS_MGR_TIMER_EXPIRY"/>
    <STRING id="STR_ID_GPS_MGR_REMOTE_MSG_ERROR"/>
    <STRING id="STR_ID_GPS_MGR_REQ_POS"/>
    <STRING id="STR_ID_GPS_MGR_REQ_POS_REQUESTOR"/>
    <STRING id="STR_ID_GPS_MGR_REQ_POS_APPLICATION"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_GPS_SETTING_MENU_ICON">CUST_IMG_PATH"\\\\\MainLCD\\\\Submenu\\\\Settings\\\\SB_GPSS.bmp"</IMAGE>
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    <IMAGE id="IMG_ID_GPS_AGPS_STATE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\GPS"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#ifndef __COSMOS_MMI__
    <MENU id="MENU_ID_GPS_SETTING" type="OPTION" img="IMG_ID_GPS_SETTING_MENU_ICON" str="STR_ID_GPS_SETTING_MAIN" 
    #if !defined(__IOT__)
        highlight="HighlightGPSSetting"
    #endif
    >
         <MENUITEM_ID>MENU_ID_GPS_RECEIVER</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_BTDEVICE</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_AGPS_SETTING</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_GPS_RECEIVER" str="STR_ID_GPS_SETTING_RECEIVER"/>
#else
    <MENU id="MENU_ID_GPS_SETTING" type="OPTION" img="IMG_ID_GPS_SETTING_MENU_ICON" str="STR_ID_GPS_SETTING_MAIN">
         <MENUITEM_ID>MENU_ID_GPS_RECEIVER</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_BTDEVICE</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_AGPS_SETTING</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_GPS_RECEIVER" str="STR_ID_GPS_SETTING_RECEIVER"/>
#endif

#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    <MENU id="MENU_ID_GPS_AGPS_SETTING" type="OPTION" str="STR_ID_GPS_SETTING_AGPS_SETTING">
         <MENUITEM_ID>MENU_ID_GPS_AGPS_SWITCH</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_AGPS_MTLR</MENUITEM_ID>
         <MENUITEM_ID>MENU_ID_GPS_AGPS_SEND_LOCATION</MENUITEM_ID>
    </MENU>
#endif /*defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)*/

    <MENUITEM id="MENU_ID_GPS_AGPS_SWITCH" str="STR_ID_GPS_SETTING_AGPS"/>
#if defined(__AGPS_USER_PLANE__) || defined(__AGPS_CONTROL_PLANE__)
    <MENUITEM id="MENU_ID_GPS_AGPS_SEND_LOCATION" str="STR_ID_GPS_SETTING_AGPS_SEND_LOCATION"/>
#endif

#ifdef __AGPS_USER_PLANE__
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE" str="STR_ID_GPS_SETTING_AGPS_PROFILE"/>
    <MENU id="MENU_ID_GPS_AGPS_PROFILE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_ACTIVATE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_EDIT</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_GPS_AGPS_PROFILE_EDIT_LIST" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_NAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_ADDR</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_DATA_ACCOUNT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_PUSH_SMS_NUM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_GPS_AGPS_PROFILE_PORT</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_ACTIVATE" str="STR_GLOBAL_ACTIVATE"/>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_NAME" str="STR_ID_GPS_SETTING_AGPS_PROFILE_NAME"/>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_ADDR" str="STR_GLOBAL_ADDRESS"/>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_DATA_ACCOUNT" str="STR_GLOBAL_DATA_ACCOUNT"/>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_PUSH_SMS_NUM" str="STR_ID_GPS_SETTING_AGPS_PROFILE_PUSH_SMS_NUM"/>
    <MENUITEM id="MENU_ID_GPS_AGPS_PROFILE_PORT" str="STR_ID_GPS_SETTING_AGPS_PROFILE_PORT"/>

    <MENUITEM id="MENU_ID_GPS_INPUT_EDITOR_OPTION" str="STR_GLOBAL_OPTIONS"/>
#endif /*__AGPS_USER_PLANE__*/

    <MENUITEM id="MENU_ID_GPS_AGPS_CP_TEST" str="STR_ID_GPS"
    #if !defined(__IOT__)
        highlight="HighlightEMGPSMain"
    #endif
    />

    <SCREEN id="SCR_ID_GPS_SETTING_MAIN"/>
    <SCREEN id="SCR_ID_GPS_SETTING_AGPS_SETTING"/>
    <SCREEN id="SCR_ID_GPS_SETTING_AGPS_PROFILE"/>
    <SCREEN id="SCR_ID_GPS_SETTING_AGPS_PROFILE_OPTION"/>
    <SCREEN id="SCR_ID_GPS_SETTING_AGPS_PROFILE_EDIT"/>
    <SCREEN id="SCR_ID_GPS_SETTING_ASK_SAVE_SCREEN"/>
    <SCREEN id="SCR_ID_GPS_SETTING_BT_PAIRING"/>
    <SCREEN id="SCR_ID_GPS_SETTING_INPUT_EDITOR"/>
    <SCREEN id="SCR_ID_GPS_SETTING_INPUT_EDITOR_OPTION"/>

    <SCREEN id="SCR_ID_GIS_SETTING_PORT_CHOOSE"/>
    <SCREEN id="SCR_ID_GPS_SETTING_DUMMY"/>

    <SCREEN id="SRC_ID_GPS_MGR_NOTIFY"/>
    <SCREEN id="SRC_ID_GPS_MGR_MTLR_NOTIFY"/>

    <SCREEN id="SCR_ID_AGPS_SUPL_OTAP_PROF_INFO"/>
    <SCREEN id="SCR_ID_AGPS_SUPL_OTAP_PROF_LIST"/>

#endif /*defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)*/

</APP>
