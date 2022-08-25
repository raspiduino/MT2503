
#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_MMI_THEME">

#ifdef __MMI_THEMES_APPLICATION__
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file = "mmi_rp_app_phonesetting_new_def.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

    <STRING id="STR_MENU3101_THEMES"/>
    <STRING id="STR_MENU3201_UPDATE_PERIOD"/>
    <STRING id="STR_MENU3202_SET_ORDER"/>
    <STRING id="STR_MENU3302_UPDATE_HOURLY"/>
    <STRING id="STR_MENU3303_UPDATE_DAILY"/>
    <STRING id="STR_MENU3304_UPDATE_WEEKLY"/>
    <STRING id="STR_THEME_DEFAULT"/>
    <STRING id="STR_THEME_THEME2"/>
    <STRING id="STR_THEME_THEME3"/>
    <STRING id="STR_THEME_THEME4"/>
    <STRING id="STR_THEME_THEME5"/>
    <STRING id="STR_THEME_THEME6"/>
    <STRING id="STR_THEME_THEME7"/>
    <STRING id="STR_THEME_THEME8"/>
    <STRING id="STR_THEME_THEME9"/>
    <STRING id="STR_THEME_THEME10"/>
    <STRING id="STR_MENU_UPDATE_MONTHLY"/>
    <STRING id="STR_MENU_UPDATE_SEASONALLY"/>
    <STRING id="STR_SCR3001_THEMES_CAPTION"/>
    <STRING id="STR_THEMES_ALARM_ACTIVATION"/>
    <STRING id="STR_THEME_NOT_AVAILABLE"/>
    <STRING id="STR_THEME_ALREADY_ACTIVATED"/>

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    <STRING id="STR_THEMES_DOWNLOAD"/>
    <STRING id="STR_DOWNLOAD_INFO_TITLE_ID"/>
    <STRING id="STR_DOWNLOAD_THEME_UNSUPPORTED"/>
    <STRING id="STR_LCD_SIZE_MISMATCH"/>
    <STRING id="STR_ID_DOWNLOAD_THEME_FILE_NAME"/>
    <STRING id="STR_ID_DOWNLOAD_THEME_FILE_SIZE"/>
    <STRING id="STR_ID_DOWNLOAD_THEME_URL"/>
    <STRING id="STR_ID_THEME_DOWNLOAD_COMPLETE"/>
    <STRING id="STR_ID_DLT_DISK_FULL"/>
    <STRING id="STR_ID_DLT_WRITE_PROTECTED"/>
    <STRING id="STR_ID_DLT_NO_MEMORY_CARD"/>
    <STRING id="STR_ID_DLT_UNSUFFICIENT_MEMORY"/>
    <STRING id="STR_ID_THEME_DOWNLOAD_ABORT"/>
    <STRING id="STR_ID_USER_CANCEL"/>
    <STRING id="STR_ID_CONNECTION_BREAK"/>
    <STRING id="STR_ID_ERROR_DOWNLOAD"/>
    <STRING id="STR_ID_DLT_ERROR_CREATE_FILE"/>
    <STRING id="STR_ID_DLT_ERROR_IN_FILE"/>
    <STRING id="STR_DOWNLOAD_ENTER_ADDRESS"/>
    <STRING id="STR_ID_DLT_THM_PROGRESS"/>
    <STRING id="STR_DEFAULT_THEME_ACTIVATION"/>
    <STRING id="STR_THEMES_ENTER_ADR_GOTO"/>
    <STRING id="STR_DOWNLOAD_ENTER_ADDRESS"/>
    <STRING id="STR_THEME_FORMAT_NOT_SUPPORTED"/>
    <STRING id="STR_THEME_UNKNOWN_ERROR"/>
    <STRING id="STR_THEME_ERROR_FILENAME_INCORRECT"/>
    <STRING id="STR_THEME_ERROR_PHONE_MODEL_MISMATCH"/>
    <STRING id="STR_THEME_ERROR_WAP_ALREADY_ACTIVE"/>
    <STRING id="STR_THEME_FILE_DOWNLOADED"/>
    <STRING id="STR_THEME_DELETE_SUCCESS"/>
    <STRING id="STR_ID_DLT_THM_PROGRESS"/>
    <STRING id="STR_DEFAULT_THEME_ACTIVATION"/>        
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */


    <!--End String Resource Area-->
    <!--End String Resource Area-->
    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_fmgr_theme_notify_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_fmgr_theme_notify_hdlr"/>
		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_theme_exit_usb_ms_callback"/>
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_theme_enter_usb_ms_callback"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_fmgr_theme_notify_hdlr"/>
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->
    <!--Image Resource Area-->

    <IMAGE id="IMG_MENU3201_UPDATE_PERIOD">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_MENU3202_SET_ORDER">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_SET_ORDER_MENU_CAPTION">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMAGE_THEME_SELECTED">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMAGE_NOIMAGE_THEME">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_MENU_UPDATE_MONTHLY">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_MENU_UPDATE_SEASONALLY">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
	<IMAGE id="IMG_THEMES_CAPTION">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_MENU3101_THEMES">CUST_IMG_PATH"\\\\MainLCD\\\\Theme\\\\SB_FTH.bmp"</IMAGE>
    <IMAGE id="IMG_SET_THEME">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp"</IMAGE>

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    <IMAGE id="IMG_DOWNLOAD_TITLE_ID">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_SELECT_STORAGE_TITLE_ID">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMAGE_PHONE_THEME">CUST_IMG_PATH"\\\\MainLCD\\\\Theme\\\\theme_p.bmp"</IMAGE>
    <IMAGE id="IMAGE_CARD_THEME">CUST_IMG_PATH"\\\\MainLCD\\\\Theme\\\\theme_c.bmp"</IMAGE>
    <IMAGE id="IMAGE_SYSTEM_THEME">CUST_IMG_PATH"\\\\MainLCD\\\\Theme\\\\theme_s.bmp"</IMAGE>
    <IMAGE id="IMAGE_ACTIVATED_THEME">CUST_IMG_PATH"\\\\MainLCD\\\\Theme\\\\theme_a.bmp"</IMAGE>
    <IMAGE id="IMG_THEME_ACTIVATION">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\PROGRESS"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
#endif

    <!--End Image Resource Area-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->

    <SCREEN id = "SCR_ID_THM_MENU"/>
    <SCREEN id = "SCR_ID_THM_OPTIONS"/>
    <SCREEN id = "SCR_ID_THM_UPDATE_PERIOD"/>
    <SCREEN id = "SCR_ID_THM_SET_ORDER"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_THM_INFO"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_THM_STORAGE"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_THM_COMPLETE"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_ENTER_ADDRESS"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_EDIT_ADDRESS"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_DONE_OPTION"/>
    <SCREEN id = "SCR_ID_DOWNLOAD_ENTER_ADDRESS_OPTIONS"/>
    <SCREEN id = "SCR_ID_THEME_MOVE_CHECK_CONFIRM"/>
    <SCREEN id = "SCR_ID_THEME_CONFIRM"/>
    <SCREEN id = "SCR_ID_THEME_END"/>

    <SCREEN id = "GRP_ID_THM_BEGIN"/>
    <SCREEN id = "GRP_ID_THM_MAIN"/>
    <SCREEN id = "GRP_ID_THM_SET_ORDER"/>    
    <SCREEN id = "GRP_ID_THM_DOWNLOAD"/>
    <SCREEN id = "GRP_ID_THM_FMGR_ACTIVE"/>
    <SCREEN id = "GRP_ID_THM_END"/>    

	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->

	<MENU id="MENU3101_THEMES" type="APP_MAIN" parent="MENU9102_INITIAL_SETUP" str="STR_MENU3101_THEMES" img="IMG_MENU3101_THEMES" 
	highlight="HighlightThmMenu" shortcut="ON" shortcut_img="IMG_MENU3101_THEMES" launch="mmi_theme_launch">
    </MENU>

	<MENUITEM id="MENU3101_THEMES" str="STR_MENU3101_THEMES" highlight="HighlightThmMenu"/>

	<MENUITEM id="MENU_THEMES_ACTIVATE" str="@OID:STR_GLOBAL_ACTIVATE"/>
	<MENUITEM id="MENU3202_SET_ORDER" str="STR_MENU3202_SET_ORDER"/>

	<MENU id="MENU3201_UPDATE_PERIOD" type="APPMAIN" str="STR_MENU3201_UPDATE_PERIOD" flag="RADIO">
    	<MENUITEM id="MENU3301_UPDATE_OFF" str="@OID:STR_GLOBAL_OFF"/>
    	<MENUITEM id="MENU3302_UPDATE_HOURLY" str="STR_MENU3302_UPDATE_HOURLY"/>
    	<MENUITEM id="MENU3303_UPDATE_DAILY" str="STR_MENU3303_UPDATE_DAILY"/>
    	<MENUITEM id="MENU3304_UPDATE_WEEKLY" str="STR_MENU3304_UPDATE_WEEKLY"/>
    	<MENUITEM id="MENU_UPDATE_MONTHLY" str="STR_MENU_UPDATE_MONTHLY"/>
    	<MENUITEM id="MENU_UPDATE_SEASONALLY" str="STR_MENU_UPDATE_SEASONALLY"/>
    </MENU>

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    <MENUITEM id="MENU_THEMES_DELETE" str="@OID:STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_THEMES_DOWNLOAD" str="@OID:STR_THEMES_DOWNLOAD"/>

	<MENU id="MENU3001_THEMES_LIST" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_THEMES_ACTIVATE</MENUITEM_ID>
		<MENUITEM_ID>MENU3201_UPDATE_PERIOD</MENUITEM_ID>
		<MENUITEM_ID>MENU3202_SET_ORDER</MENUITEM_ID>
		<MENUITEM_ID>MENU_THEMES_DOWNLOAD</MENUITEM_ID>
		<MENUITEM_ID>MENU_THEMES_DELETE</MENUITEM_ID>
	</MENU>
	
	<MENU id="MENU3001_THEMES_LIST_FLIGHTMODE" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_THEMES_ACTIVATE</MENUITEM_ID>
		<MENUITEM_ID>MENU3201_UPDATE_PERIOD</MENUITEM_ID>
		<MENUITEM_ID>MENU3202_SET_ORDER</MENUITEM_ID>
		<MENUITEM_ID>MENU_THEMES_DELETE</MENUITEM_ID>
	</MENU>

    <MENU id="MENU3001_THEMES_LIST_1" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_THEMES_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU3201_UPDATE_PERIOD</MENUITEM_ID>
        <MENUITEM_ID>MENU3202_SET_ORDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_THEMES_DOWNLOAD</MENUITEM_ID>
    </MENU>
    
    <MENU id="MENU3001_THEMES_LIST_1_FLIGHTMODE" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_THEMES_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU3201_UPDATE_PERIOD</MENUITEM_ID>
        <MENUITEM_ID>MENU3202_SET_ORDER</MENUITEM_ID>
    </MENU>
    
    <MENU id="MENU_THEMES_ENTER_ADR_OPTIONS" type="OPTION" str="0">
        <MENUITEM id="MENU_THEMES_ENTER_ADR_GOTO" str="@OID:STR_GLOBAL_GO_TO" highlight="mmi_thm_address_list_goto_highlight_hdlr"/>
        <MENUITEM id="MENU_THEMES_ENTER_ADR_EDIT" str="@OID:STR_GLOBAL_EDIT" highlight="mmi_thm_address_list_edit_highlight_hdlr"/>
        <MENUITEM id="MENU_THEMES_ENTER_ADR_DELETE" str="@OID:STR_GLOBAL_DELETE" highlight="mmi_thm_address_list_delete_highlight_hdlr"/>
        <MENUITEM id="MENU_THEMES_ENTER_ADR_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL" highlight="mmi_thm_address_list_delete_all_highlight_hdlr"/>
    </MENU>
    
	<MENU id="MENU_DOWNLOAD_THEMES_STORAGE" type="OPTION" str="STR_GLOBAL_STORAGE">
        <MENUITEM id="MENU_STORAGE_THEMES_PHONE" str="STR_GLOBAL_PHONE"/>
        <MENUITEM id="MENU_STORAGE_THEMES_CARD" str="STR_GLOBAL_MEMORY_CARD"/>
    </MENU>
	

	<MENU id="MENU_THM_DOWNLOAD_INPUT_METHOD_AND_DONE_OPTION_ID" type="OPTION" str="STR_GLOBAL_OPTIONS">
        //<MENUITEM id="MENU_THM_DOWNLOAD_DONE_OPTION_ID" str="STR_GLOBAL_DONE"/>
    	//<MENUITEM id="MENU_INPUT_METHOD_OPTION_ID" str="STR_GLOBAL_INPUT_METHOD"/>
    </MENU>

#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
    <MENU id="MENU3001_THEMES_LIST" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_THEMES_ACTIVATE</MENUITEM_ID>
        <MENUITEM_ID>MENU3201_UPDATE_PERIOD</MENUITEM_ID>
        <MENUITEM_ID>MENU3202_SET_ORDER</MENUITEM_ID>
    </MENU>
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

    <MENUITEM id = "MENU_ID_THEME_FMGR_ACTIVATE" str = "@OID:STR_GLOBAL_ACTIVATE"/>
    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    <FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_THEME_FMGR_ACTIVATE" enabler="mmi_theme_fmgr_use_enabler" handler="mmi_theme_fmgr_use_handler"/>
    </FILE_TYPES>
#endif

    <!--End Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <CACHEDATA type="double" id="THEME_MANAGER_DEFAULT_THEME_ID">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>
        
    <CACHEDATA type="double" id="THEME_MANAGER_MAX_THEME_ID">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="THEME_MANAGER_CURR_THEME_ID" restore_flag="TRUE" restore_id="@THEME_MANAGER_DEFAULT_THEME_ID">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active theme </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_USB_PREVIOUS_THEME_INDEX">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>    

		<RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_theme_rmdr_notify"/>
#endif /* __MMI_THEMES_APPLICATION__ */
		
    </APP>

