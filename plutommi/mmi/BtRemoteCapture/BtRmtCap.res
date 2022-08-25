/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_BT_REMOTE_CAPTURE__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BTREMOTECAPTURE" 
		package_name="native.mtk.btremotecapture"
		name="STR_ID_BTRMTCAP_APPLICATION_APP_NAME"
		launch="mmi_btrmtcap_entry_main_message_menu"
		package_proc="mmi_bt_rmtcap_package_proc">	   
    <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="MainMenuDef.h"/>
    
    <!-- 
    ***************************************************************
    string Area
    ***************************************************************
    -->
    <STRING id="STR_ID_BTRMTCAP_APPLICATION_APP_NAME"/>
    <STRING id="STR_ID_BTRMTCAP_CAPTURE"/>
    <STRING id="STR_ID_BTRMTCAP_CAPTURE_ING"/>
    <STRING id="STR_ID_BTRMTCAP_LAUNCH_FAILED"/>
    
    <!-- 
    ***************************************************************
    image Area
    ***************************************************************
    --> 
	<IMAGE id="IMG_BT_RMTCAP_DFAULT_BG">CUST_IMG_PATH"\\\\MainLCD\\\\BTRmtCap\\\\rmtcap_default_bg.jpg"</IMAGE>

	<AUDIO id="AUD_ID_BTRMTCAP_CAMCO_CAPTURE">CUST_ADO_PATH"\\\\Camcorder\\\\pic1.wav"</AUDIO>
    <!-- 
    ***************************************************************
    MENU Area
    ***************************************************************
    -->
    <MENU id="MAIN_MENU_BTRMTCAP_MENUID" type="APP_MAIN" str="STR_ID_BTRMTCAP_APPLICATION_APP_NAME" img="MAIN_MENU_BTRMTCAP_ICON"
        highlight="highlight_mainmenu_btrmtcap" shortcut="ON" shortcut_img="MAIN_MENU_BTRMTCAP_ICON" launch="mmi_btrmtcap_entry_main_message_menu">    	
    </MENU>
    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_BTRMTCAP_APP"/>
    <SCREEN id="GRP_ID_BTRMTCAP_POPUP"/>
    
    <SCREEN id="SCR_ID_BTRMTCAP_MAIN_SCRN"/>
    <SCREEN id="SCR_ID_BTRMTCAP_POPUP_SCRN"/>
    <SCREEN id="SCR_ID_BTRMTCAP_PROCESSING"/>
    <SCREEN id="SCR_ID_BTRMTCAP_SHOW_PICTURE"/>
    <SCREEN id="SCR_ID_BTRMTCAP_DEVICE_LIST"/>
    <!-- 
    ***************************************************************
    event Area
    ***************************************************************   
    -->    
    <RECEIVER id="EVT_ID_SRV_BT_NOTI_CAP_CMD_NOTIFY" proc="mmi_bt_rmtcap_event_hdlr"/>

	<TIMER id="MMI_BT_RMTCAP_TIMER_ID"/>
   
</APP>
#endif/*__MMI_BT_REMOTE_CAPTURE__*/
