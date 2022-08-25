#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if 0
#ifdef __PLUTO_MMI_PACKAGE__
<APP id="APP_DMUI">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_DMUI_MAIN"/>
    <STRING id="STR_ID_DMUI_SERVERID"/>
    <STRING id="STR_ID_DMUI_SERVER_PASSWORD"/>
    <STRING id="STR_ID_DMUI_SERVER_ADDRESS"/>
    <STRING id="STR_ID_DMUI_USER_PASSWORD"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE_BASIC"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE_MD5"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE_HMAC"/>
    <STRING id="STR_ID_DMUI_INFO_INVALID_SERVER_ADDRESS"/>
    <STRING id="STR_ID_DMUI_INFO_SERVERID_EMPTY"/>
    <STRING id="STR_ID_DMUI_INFO_SERVERID_EXIST"/>
    <STRING id="STR_ID_DMUI_INFO_SERVERID_INVALID"/>
    <STRING id="STR_ID_DMUI_NOTIF_INIT_SESSION_INFO"/>
    <STRING id="STR_ID_DMUI_NOTIF_INIT_SESSION_CONFIRM"/>
    <STRING id="STR_ID_DMUI_NOTIF_ENTER_PIN"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_CAPTION"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_TITLE"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_INFO"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_RESUME"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_CAPTION"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_TITLE"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_INFO"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_REBOOT"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_DEFER"/>
    <STRING id="STR_ID_DMUI_UPDATE_DEFER_INFO"/>
    <STRING id="STR_ID_DMUI_UPDATE_DEFER_HOUR_LATER"/>
    <STRING id="STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER"/>
    <STRING id="STR_ID_DMUI_UPDATE_SUCCESS"/>
    <STRING id="STR_ID_DMUI_UPDATE_FAILURE"/>
    <STRING id="STR_ID_DMUI_NOTIF_NAME"/>
    <STRING id="STR_ID_DMUI_NOTIF_TYPE"/>
    <STRING id="STR_ID_DMUI_NOTIF_SIZE"/>
    <STRING id="STR_ID_DMUI_NOTIF_DESCRIPTION"/>
    <STRING id="STR_ID_DMUI_TIMEOUT_POPUP"/>
    <STRING id="STR_ID_DMUI_DELETE_ASK"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_REQUEST"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_REQUEST"/>
    <STRING id="STR_ID_DMUI_NOTIF_REBOOT"/>
    <STRING id="STR_ID_DMUI_NOTIF_REBOOT_PROGRESS"/>
    <STRING id="STR_ID_DMUI_NOTIF_REBOOT_FAIL"/>
    <STRING id="STR_ID_DMUI_ALERT_DM_INFO_CAPTION"/>
    <STRING id="STR_ID_DM_OTA_PROFILE"/>
    <STRING id="STR_ID_DM_OTA_SERVERID_EXIST_REPLACE"/>
    <STRING id="STR_ID_DM_OTA_SERVERID_FULL_REPLACE"/>
    <STRING id="STR_ID_DM_OTA_SERVERID"/>
    <STRING id="STR_ID_DM_OTA_SERVER_ADDRESS"/>
    <STRING id="STR_ID_DMUI_SESSION_FAILURE"/>
    <STRING id="STR_ID_DMUI_DOWNLOAD_FAILURE"/>
    <STRING id="STR_ID_DMUI_DOWNLOAD_PAUSE_BY_NETWORK_ANOMALY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_DMUI_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Device_manangerment.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_NO_IMAGE" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SEL_IMAGE" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SERVERID" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_ID.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SERVER_PASSWORD" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_Password.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_CONNECTION_SETTING" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Date_account.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SERVER_ADDRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_add.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_USERNAME" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_User_name.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_USER_PASSWORD" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_User_password.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_AUTHTYPE" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Auth_type.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="MENU_ID_DMUI_OP_ACTIVATE" str="@OID:STR_GLOBAL_ACTIVATE"/>
    <MENUITEM id="MENU_ID_DMUI_OP_EDIT" str="@OID:STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_DMUI_OP_ERASE" str="@OID:STR_GLOBAL_DELETE"/>
#if defined(__MMI_OP01_DM_PROFILE_SETTING__) || defined(__MMI_OP12_DM_PROFILE_SETTING__) || defined(__OP02_DM__)
    <MENUITEM id="MENU_ID_DMUI_OP_VIEW" str="@OID:STR_GLOBAL_VIEW"/>
#endif

    <!--Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */
#if defined(__MMI_OP01_DM_PROFILE_SETTING__) || defined(__MMI_OP12_DM_PROFILE_SETTING__) || defined(__OP02_DM__)
    <MENU id="MENU_ID_DMUI_OPTION_DEFAULT_PROFILE" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID default="TRUE">MENU_ID_DMUI_OP_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DMUI_OP_VIEW</MENUITEM_ID>
    </MENU>
#endif

    <MENU id="MENU_ID_DMUI_OPTION" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID default="TRUE">MENU_ID_DMUI_OP_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DMUI_OP_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DMUI_OP_ERASE</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_DMUI_MAIN" type="APP_MAIN" str="STR_ID_DMUI_MAIN" img="IMG_ID_DMUI_MAIN" highlight="mmi_dmui_highlight_main">
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_DMAPP_SETTING"/>
    <SCREEN id="GRP_ID_DMAPP_GLOBAL"/>
    <SCREEN id="GRP_ID_DMAPP_OTA"/>

    <SCREEN id="SCR_ID_DMUI_MAIN"/>
    <SCREEN id="SCR_ID_DMUI_OPTION"/>
    <SCREEN id="SCR_ID_DMUI_UPDATE"/>
    <SCREEN id="SCR_ID_DMUI_UPDATE_DEFER"/>
    <SCREEN id="SCR_ID_DMUI_DOWNLOAD"/>
    <SCREEN id="SCR_ID_DMUI_DOWNLOAD_PROGRESS"/>
    <SCREEN id="SCR_ID_DMUI_ENTER_PIN"/>
    <SCREEN id="SCR_ID_DMUI_REBOOT"/>
    <SCREEN id="SCR_ID_DMUI_ALERT_INPUT"/>
    <SCREEN id="SCR_ID_DMUI_VIEW_INFO"/>
    <SCREEN id="SCR_ID_DMUI_ALERT_SINGLE_CHOICE"/>
    <SCREEN id="SCR_ID_DMUI_ALERT_MULTI_CHOICE"/>
    <SCREEN id="SCR_ID_DMUI_WAITING"/>
    <SCREEN id="SCR_ID_DMUI_OTA_CONFIRM"/>
    <SCREEN id="SCR_ID_DM_OTA_PROVISIONING_INFO"/>
    <SCREEN id="SCR_ID_DM_OTA_SERVERID_LIST"/>
    <SCREEN id="SCR_ID_DMUI_PROMPT_MESSAGE"/>
    <SCREEN id="SCR_ID_DMUI_POPUP"/>
    <SCREEN id="SCR_ID_DMUI_POPUP_CONFIRM"/>

#ifdef __DM_LAWMO_SUPPORT__
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_dmui_lawmo_pre_key_routing_cb"/>
#endif /* __DM_LAWMO_SUPPORT__ */
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_dmui_sim_unavailable_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_dmui_nw_info_srv_availability_changed"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="mmi_dmui_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="mmi_dmui_dtcnt_changed_hdlr"/>

#ifdef __SIM_HOT_SWAP_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_dm_sim_ctrl_det_hdlr"/>
#endif /* __SIM_HOT_SWAP_SUPPORT__ */

    <CACHEDATA type="byte" id="NVRAM_DM_OTA_PROFILE_INIT">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> DM operator default profile setting init flag </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DM_FOTA_UPDATE_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> DM is doing fota flag </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DM_LOCK_STATUS">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> DM Lawmo lock flag </DESCRIPTION>
    </CACHEDATA>

</APP>
#endif
#endif /* SYNCML_DM_SUPPORT */