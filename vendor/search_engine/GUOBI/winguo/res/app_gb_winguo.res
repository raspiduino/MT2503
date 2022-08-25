
#include "MMI_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_GB_WINGUO__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GB_WINGUO" 
#if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
    package_name="native.guobi.winguo"
    name="STR_GB_WINGUO_SMARTSEARCH"
    img="IMG_WG_WINGUO_NATIVE_ICON"
    launch="vapp_winguo_launch" type="venus"
    #ifndef BROWSER_SUPPORT
		hidden_in_mainmenu = "true"
		#endif
#else
    name="STR_ID_UM_MAIN_MENU_MESSAGES_TEXT" 
#endif // #if defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)
    >
#ifdef __COSMOS_MMI_PACKAGE__
    <MEMORY heap = "300*1024"
            cui = "VCUI_CONTACT_SAVE"
	/>
#else
	<MEMORY base = "300*1024"/>
                    
#endif

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    
    <!-----------------------------------------------------Event handle----------------------------------------------------->
/*		
		<RECIEVER id="EVT_ID_PHB_ADD_CONTACT" proc="srv_sync_contact_addition_notification"/>
		<RECIEVER id="EVT_ID_PHB_UPD_CONTACT" proc="srv_sync_contact_modification_notification"/>
		<RECIEVER id="EVT_ID_PHB_DEL_CONTACT" proc="srv_sync_contact_deletion_notification"/>
		<RECEIVER id="EVT_ID_PHB_READY" proc="mmi_phb_ready_hdlr"/>
*/
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    
		<STRING id="STR_GB_WINGUO_SMARTSEARCH"/>
		<STRING id="STR_GUOBI_COMMON_MOVING_ID"/>
		<STRING id="STR_GB_WINGUO_SKIN_SETTING"/>
		<STRING id="STR_GB_WINGUO_SKIN_BLACK"/>
		<STRING id="STR_GB_WINGUO_SKIN_BLUE"/>
		<STRING id="STR_GB_WINGUO_SKIN_OUTDOOR"/>
		<STRING id="STR_GB_WINGUO_SKIN_DREAMWORLD"/>
		<STRING id="STR_GB_WINGUO_SKIN_NIGHT"/>
		<STRING id="STR_GB_WINGUO_SAVE"/>
		<STRING id="STR_GB_WINGUO_SEND_SMS"/>
		<STRING id="STR_GB_WINGUO_SEND_MMS"/>
		<STRING id="STR_GB_WINGUO_IP_CALL"/>
		<STRING id="STR_GB_WINGUO_CALL"/>
		<STRING id="STR_GB_WINGUO_DELETE"/>
		<STRING id="STR_GB_WINGUO_OPTION"/>
		<STRING id="STR_GB_WINGUO_BACK"/>
		<STRING id="STR_GB_WINGUO_OK"/>
		<STRING id="STR_GB_WINGUO_SETSUCC"/>
		<STRING id="STR_GB_WINGUO_SETFAIL"/>
		<STRING id="STR_GB_WINGUO_YES"/>
		<STRING id="STR_GB_WINGUO_NO"/>
		<STRING id="STR_GB_WINGUO_ADD"/>
		<STRING id="STR_GB_WINGUO_SELECT"/>
		<STRING id="STR_GB_WINGUO_EXIT"/>
		<STRING id="STR_GB_WINGUO_SEARCH"/>
		<STRING id="STR_GB_WINGUO_SIMNOSERVICE"/>
		<STRING id="STR_GB_WINGUO_ENTRY"/>
		<STRING id="STR_GB_WINGUO_ENTRY_CALL"/>
		<STRING id="STR_GB_WINGUO_ENTRY_EDIT_SMS"/>
		<STRING id="STR_GB_WINGUO_SEND_BUSINESS_CARD"/>
		<STRING id="STR_GB_WINGUO_USB_MODE_TIP"/>
		<STRING id="STR_GB_WINGUO_FLIGHT_MODE_TIP"/>
		<STRING id="STR_GB_WINGUO_NOSIM_MODE_TIP"/>
		<STRING id="STR_GB_WINGUO_SELECTPHONENUM"/>
		<STRING id="STR_GB_WINGUO_DECYPTPHONEBOOK"/>
		<STRING id="STR_GB_WINGUO_INPUTPASSWORD"/>
		<STRING id="STR_GB_WINGUO_PASSWORDERROR"/>
		<STRING id="STR_GB_WINGUO_HIDE"/>
		<STRING id="STR_GB_WINGUO_WGSMS"/>
		<STRING id="STR_GB_WINGUO_INVALID_NUMBER"/>
		<STRING id="STR_GB_WINGUO_NOT_USE"/>
		<STRING id="STR_GB_WINGUO_VALID_SIM"/>
		<STRING id="STR_GB_WINGUO_NODISKSPACE"/>
		<STRING id="STR_GB_WINGUO_SMS"/>
		<STRING id="STR_GB_WINGUO_MMS"/>
		<STRING id="STR_GB_WINGUO_SAVE_ITEM"/>
		<STRING id="STR_ID_WINGUO_EMPTY_MOBILE_NUMBER"/>
		<STRING id="STR_GB_WINGUO_CANCEL"/>
		<STRING id="STR_GB_WINGUO_APP"/>
		<STRING id="STR_GB_WINGUO_PHONE"/>
		<STRING id="STR_GB_WINGUO_HOMENUMBER"/>
		<STRING id="STR_GB_WINGUO_OFFICENUMBER"/>
		<STRING id="STR_GB_WINGUO_FAX"/>
		<STRING id="STR_GB_WINGUO_EMAIL"/>
		<STRING id="STR_GB_WINGUO_UNKNOW"/>
		<STRING id="STR_GB_WINGUO_EDIT_CONTENT_FULL"/>
		<STRING id="STR_GB_WINGUO_SIM1"/>
		<STRING id="STR_GB_WINGUO_SIM2"/>
		<STRING id="STR_GB_WINGUO"/>
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    
    <IMAGE id="IMG_GB_SMARTWINGUO_APPLICATIOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\application.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\winguo.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_ADDR">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\addr.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\winguo_call.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_CALL.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_NO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_CALL_NO.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SAVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_SAVE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SAVE_NO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_SAVE_NO.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_SMS.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SMS_NO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_SMS_NO.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MMS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_MMS.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MMS_NO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_MMS_NO.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MENU">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_MENU.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MENU_NO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_MENU_NO.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_BACK">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_BACK.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_BACK_NO">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_BACK_NO.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_LOGO_OUT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_GB_WG.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCH">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_search.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKIN_LIST_SELECT_FLAG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skin_list_select_flag.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKIN_LIST_NORMAL_FLAG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skin_list_normal_flag.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_ICON_OPTION">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\icon_option.png"</IMAGE>	
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_ICON_BACK">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\icon_back.png"</IMAGE>	
		<IMAGE id="IMG_WG_SMARTDAIL_ARROW_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_ARROW_LEFT.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_ARROW_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_SMARTDAIL_ARROW_RIGHT.png"</IMAGE>
	
			<IMAGE id="IMG_WG_SMARTDAIL_APP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_APP.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_EMAIL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_EMAIL.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_FAX">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_FAX.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_HOME_PHONE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_HOME_PHONE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_IMAGE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM1.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM2.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MOBILEPHONE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MOBILEPHONE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MUSIC">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MUSIC.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_OFFICE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_OFFICE.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_SMS1">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_SMS1.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_ARROW_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_arrow_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_arrow_normal.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_ARROW_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_arrow_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_arrow_normal.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_ARROW_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_arrow_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_arrow_normal.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_ARROW_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_arrow_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_arrow_normal.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_ARROW_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_arrow_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_arrow_normal.png"</IMAGE>
#ifdef GB_WINGUO_IMGSKIN	
		<IMAGE id="IMG_WG_WINGUO_SKIN_SUBLIST_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skin_sublist_icon.png"</IMAGE>
#else
		<IMAGE id="IMG_WG_WINGUO_SKIN_SUBLIST_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skin_sublist_icon_40.png"</IMAGE>
#endif
#ifdef GB_WINGUO_IMGSKIN		
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_PENDOWN_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_down_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_PENDOWN_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_down_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_PENDOWN_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_down_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_btn_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_BOTTOM_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_bottom_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_BOTTOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_bottom_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_BOTTOM_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_bottom_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_ITEM_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_item_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_MIDDLE_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_middle_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_MIDDLE_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_middle_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_MIDDLE_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_middle_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_TOP_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_top_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_TOP_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_top_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_MENU_TOP_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_menu_top_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SEARCHBAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_searchbar_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_TOOLBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_toolbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_TOOLBAR_PRESS_GB">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_toolbar_press_bg.png"</IMAGE>
		
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_INPUTMODE_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_inputmode_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_INPUTMODE_SEL_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_inputmode_sel_down_bg.png"</IMAGE>	
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_INPUTMODE_SEL_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_inputmode_sel_up_bg.png"</IMAGE>	
		
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SIDEBAR_H_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_sidebar_h_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SIDEBAR_H_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_sidebar_h_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SIDEBAR_H_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_sidebar_h_bottom.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SIDEBAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_sidebar_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SIDEBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_sidebar_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLUE_SIDEBAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblue_sidebar_bottom.png"</IMAGE>
		
		
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_PENDOWN_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_down_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_PENDOWN_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_down_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_PENDOWN_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_down_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_btn_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_BOTTOM_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_bottom_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_BOTTOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_bottom_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_BOTTOM_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_bottom_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_ITEM_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_item_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_MIDDLE_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_middle_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_MIDDLE_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_middle_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_MIDDLE_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_middle_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_TOP_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_top_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_TOP_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_top_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_MENU_TOP_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_menu_top_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SEARCHBAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_searchbar_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_TOOLBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_toolbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_TOOLBAR_PRESS_GB">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_toolbar_press_bg.png"</IMAGE>
		
		
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_INPUTMODE_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_inputmode_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_INPUTMODE_SEL_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_inputmode_sel_down_bg.png"</IMAGE>	
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_INPUTMODE_SEL_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_inputmode_sel_up_bg.png"</IMAGE>	
		
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SIDEBAR_H_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_sidebar_h_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SIDEBAR_H_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_sidebar_h_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SIDEBAR_H_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_sidebar_h_bottom.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SIDEBAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_sidebar_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SIDEBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_sidebar_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINDREAMWORLD_SIDEBAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skindreamworld_sidebar_bottom.png"</IMAGE>
				
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_PENDOWN_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_down_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_PENDOWN_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_down_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_PENDOWN_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_down_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_btn_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_BOTTOM_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_bottom_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_BOTTOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_bottom_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_BOTTOM_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_bottom_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_ITEM_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_item_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_MIDDLE_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_middle_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_MIDDLE_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_middle_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_MIDDLE_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_middle_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_TOP_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_top_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_TOP_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_top_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_MENU_TOP_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_menu_top_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SEARCHBAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_searchbar_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_TOOLBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_toolbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_TOOLBAR_PRESS_GB">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_toolbar_press_bg.png"</IMAGE>
		
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_INPUTMODE_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_inputmode_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_INPUTMODE_SEL_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_inputmode_sel_down_bg.png"</IMAGE>	
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_INPUTMODE_SEL_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_inputmode_sel_up_bg.png"</IMAGE>	
		
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SIDEBAR_H_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_sidebar_h_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SIDEBAR_H_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_sidebar_h_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SIDEBAR_H_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_sidebar_h_bottom.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SIDEBAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_sidebar_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SIDEBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_sidebar_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINBLACK_SIDEBAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinblack_sidebar_bottom.png"</IMAGE>
		
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_PENDOWN_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_down_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_PENDOWN_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_down_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_PENDOWN_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_down_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_btn_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_BOTTOM_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_bottom_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_BOTTOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_bottom_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_BOTTOM_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_bottom_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_ITEM_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_item_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_MIDDLE_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_middle_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_MIDDLE_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_middle_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_MIDDLE_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_middle_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_TOP_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_top_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_TOP_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_top_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_MENU_TOP_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_menu_top_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SEARCHBAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_searchbar_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_TOOLBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_toolbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_TOOLBAR_PRESS_GB">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_toolbar_press_bg.png"</IMAGE>
		
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_INPUTMODE_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_inputmode_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_INPUTMODE_SEL_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_inputmode_sel_down_bg.png"</IMAGE>	
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_INPUTMODE_SEL_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_inputmode_sel_up_bg.png"</IMAGE>	
		
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SIDEBAR_H_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_sidebar_h_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SIDEBAR_H_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_sidebar_h_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SIDEBAR_H_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_sidebar_h_bottom.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SIDEBAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_sidebar_top.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SIDEBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_sidebar_middle.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINNIGHT_SIDEBAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinnight_sidebar_bottom.png"</IMAGE>
				
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_PENDOWN_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_down_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_PENDOWN_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_down_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_PENDOWN_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_down_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_btn_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_BOTTOM_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_bottom_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_BOTTOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_bottom_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_BOTTOM_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_bottom_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_ITEM_FOCUS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_item_hot.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_MIDDLE_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_middle_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_TOP_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_top_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_TOP_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_top_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_MENU_TOP_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_menu_top_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_FOCUS_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_hot_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_FOCUS_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_hot_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_FOCUS_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_hot_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_normal_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_normal_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SEARCHBAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_searchbar_normal_r.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_TOOLBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_toolbar_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_TOOLBAR_PRESS_GB">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_toolbar_press_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_SHADOW_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_shadow_bg.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUBBLE_L">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_bubble_l.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUBBLE_M">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_bubble_m.png"</IMAGE>
		<IMAGE id="IMG_GB_WINGUO_SKINWHITE_BUBBLE_R">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_bubble_r.png"</IMAGE>
		

	  <IMAGE id="IMG_WG_WINGUO_HALFDLG_TOP_L">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_top_l.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_TOP_M">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_top_m.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_TOP_R">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_top_r.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_MIDDLE_L">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_middle_left.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_middle.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_MIDDLE_R">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_middle_right.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_UNDER_L">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_under_l.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_UNDER_M">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_under_m.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_HALFDLG_UNDER_R">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_halfdlg_under_r.png"</IMAGE>		
		
		<IMAGE id="IMG_WG_WINGUO_SKINWHITE_SMALL_BTN_HOT_L">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_small_btn_hot_l.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKINWHITE_SMALL_BTN_HOT_M">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_small_btn_hot_m.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKINWHITE_SMALL_BTN_HOT_R">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_small_btn_hot_r.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKINWHITE_SMALL_BTN_NORMAL_L">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_small_btn_normal_l.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKINWHITE_SMALL_BTN_NORMAL_M">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_small_btn_normal_m.png"</IMAGE>
		<IMAGE id="IMG_WG_WINGUO_SKINWHITE_SMALL_BTN_NORMAL_R">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\skinwhite_small_btn_normal_r.png"</IMAGE>
#endif		
		<IMAGE id="IMG_WG_SHARE_SMS">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\sms.png"</IMAGE>
#if defined( __COSMOS_MMI_PACKAGE__) || defined( __MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_SHELL_MULTI_PAGE__) || defined(__MMI_VUI_HOMESCREEN__)
		<IMAGE id="IMG_WG_WINGUO_ENTRY_BG0">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\winguo\\\\IM_WG_ENTRY0.png"</IMAGE>
#endif
		<IMAGE id="IMG_WG_WINGUO_NATIVE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\IMG_WG_WINGUO_NATIVE_ICON.png"</IMAGE>
		<IMAGE id="IMG_WG_LEFTARROW_UNACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\left_arrow_unactive.png"</IMAGE>
		<IMAGE id="IMG_WG_LEFTARROW_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\left_arrow_active.png"</IMAGE>
		<IMAGE id="IMG_WG_RIGHTARROW_UNACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\right_arrow_unactive.png"</IMAGE>
		<IMAGE id="IMG_WG_RIGHTARROW_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\right_arrow_active.png"</IMAGE>
		
#if (MMI_MAX_SIM_NUM >= 3)
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM3.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM3.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM3.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM3.png"</IMAGE>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
		<IMAGE id="IMG_WG_SMARTDAIL_CONTACT_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CONTACT_SIM4.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_OUT_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_OUT_SIM4.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_MISSCALL_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_MISSCALL_SIM4.png"</IMAGE>
		<IMAGE id="IMG_WG_SMARTDAIL_CALL_IN_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\Guobi\\\\Winguo\\\\Smartdial\\\\IMG_WG_SMARTDAIL_CALL_IN_SIM4.png"</IMAGE>
#endif

	/* ----------------------------------------------------------screen id----------------------------------------------------------------- */
		<SCREEN id="GRP_GB_WINGUO_SCREEN"/>
    <SCREEN id="SCR_GB_WINGUO_SCREEN"/>
    <SCREEN id="SCR_GB_WINGUO_SHOW_SIM"/>
    <SCREEN id="SCR_GB_WINGUO_SELECT_SIM"/>
    <SCREEN id="SCR_GB_WINGUO_SELECT_GPRS"/>
    <SCREEN id="SCR_ID_GB_IDLEHW"/>

/***************************************** Timer ****************************************/
    <TIMER id="GB_WG2_TIME"/>
    <TIMER id="GB_WG2_HW_TIME"/>
    <TIMER id="GB_WG2_SMD_RELEAS_TIME"/>
      
///#if (defined(__MMI_APP_MANAGER_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__)) && defined(MT6255)
///    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetWinguoPublisher"/>
///#endif
</APP>
#endif /* #ifdef __MMI_GB_WINGUO__ */
