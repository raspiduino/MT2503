/* Needed header files of the compile option in XML files, if you need others need to add here */

#include "mmi_features.h"
#include "custresdef.h"
#include "CustomCfg.h"
#ifdef __MMI_BT_DIALER_SUPPORT__
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SMSBTUNIFIEDMESSAGE">   
 <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="MainMenuDef.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>
#ifndef __COSMOS_MMI_PACKAGE__
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    <INCLUDE file="mmi_rp_app_unifiedcomposer_def.h"/>
#endif
#endif
    <INCLUDE file="WapResDef.h"/>
    <!-- 
    ***************************************************************
    STRING Area
    ***************************************************************
    -->
    <STRING id="STR_ID_SMS_UM_BT_MAIN_MENU_MESSAGES_TEXT"/>
	<STRING id="STR_SMS_UM_BT_INBOX_ID"/>
    <STRING id="STR_SMS_UM_BT_WRITE_MSG_ID"/>
    <STRING id="STR_SMS_UM_BT_SENT_ID"/>
	<STRING id="STR_SMS_UM_BT_DRAFTS_ID"/>
    <STRING id="STR_SMS_UM_BT_SEND_FAILED_MSG"/>
    <STRING id="STR_ID_SMS_BT_REPLY_BY_SMS"/>
    <STRING id="STR_ID_SMS_BT_DELETE"/>
    <STRING id="STR_ID_SMS_BT_FORWARD"/>
    <STRING id="STR_ID_SMS_BT_SEND_TO"/>
    <STRING id="STR_ID_SMS_BT_SAVE"/>
    <STRING id="STR_ID_SMS_BT_CALL_SENDER"/>
    <STRING id="STR_ID_SMS_BT_NEW_MESSAGE"/>
    <STRING id="STR_ID_SMS_BT_RMOT_NOT_SUPPORT"/>
    <STRING id="STR_ID_SMS_BT_NO_CONN"/>
    <STRING id="STR_ID_SMS_BT_CONN"/>
    <STRING id="STR_ID_SMS_BT_FROM"/>
    <STRING id="STR_ID_SMS_BT_CREATION_DATE"/>
    <STRING id="STR_ID_SMS_BT_RECEIVE_DATE"/>
    <STRING id="STR_ID_SMS_BT_TYPE"/>
    <STRING id="STR_ID_SMS_BT_DELIVERY_STATUS"/>
    <STRING id="STR_ID_SMS_BT_STORAGE"/>
    <STRING id="STR_ID_SMS_BT_MESSAGE_MENUENTRY"/>
    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
	<IMAGE id="MAIN_MENU_SMS_BT_MESSAGES_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
    <IMAGE id="IMG_SMS_UM_WRITE_MSG_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
	<IMAGE id="IMG_SMS_UM_INBOX_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
	<IMAGE id="IMG_SMS_UM_DRAFTS_MSG_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
	<IMAGE id="IMG_SMS_UM_SEND_FAILED_MSG_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
	<IMAGE id="IMG_SMS_UM_SENT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
    
	<!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="SCR_ID_SMS_UM_BT_MAIN"/>
    <SCREEN id="SCR_ID_SMS_UM_BT_MAIN_MESSAGE"/>
    <SCREEN id="SCR_ID_SMS_UM_BT_WRITE_MSG"/>
    <SCREEN id="SCR_ID_SMS_UM_BT_PROCESSING"/>
    <SCREEN id="SCR_ID_SMS_UM_BT_FOLDER"/>
    <SCREEN id="SCR_ID_SMS_BT_SENDER"/>
    <SCREEN id="SCR_ID_SMS_BT_EDITOR"/>
    <SCREEN id="SCR_ID_SMS_BT_VIEWER"/>
    <SCREEN id="SCR_ID_SMS_BT_PROCESSING"/>
    <SCREEN id="SCR_ID_SMS_BT_DETAIL"/>
    
    <TIMER id="SMS_BT_TIMER_ID"/>
    
#ifndef __COSMOS_MMI_PACKAGE__
    <!-- 
    ***************************************************************
    MENU Area
    ***************************************************************
    -->
    <MENU id="MAIN_MENU_SMS_BT_MESSAGES_MENUID" type="APP_MAIN" str="STR_ID_SMS_UM_BT_MAIN_MENU_MESSAGES_TEXT" img="MAIN_MENU_SMS_BT_MESSAGES_ICON" highlight="highlight_mainmenu_phonebook"
    	 >
                                    <MENUITEM_ID>MENU_ID_SMS_UM_WRITE_MSG</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_SMS_UM_INBOX</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_SMS_UM_DRAFT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_SMS_UM_UNSENT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_SMS_UM_SENT</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_SMS_UM_WRITE_MSG" str="STR_SMS_UM_BT_WRITE_MSG_ID" img="IMG_SMS_UM_WRITE_MSG_ICON"/>
	<MENUITEM id="MENU_ID_SMS_UM_INBOX" str="STR_SMS_UM_BT_INBOX_ID" img="IMG_SMS_UM_INBOX_ICON"/>
	<MENUITEM id="MENU_ID_SMS_UM_DRAFT" str="STR_SMS_UM_BT_DRAFTS_ID" img="IMG_SMS_UM_INBOX_ICON"/>
	<MENUITEM id="MENU_ID_SMS_UM_UNSENT" str="STR_SMS_UM_BT_SEND_FAILED_MSG" img="IMG_SMS_UM_INBOX_ICON"/>
	<MENUITEM id="MENU_ID_SMS_UM_SENT" str="STR_SMS_UM_BT_SENT_ID" img="IMG_SMS_UM_INBOX_ICON"/>

	<EVENT id="EVT_ID_MMI_SMS_UM_BT_REFRESH" type="SENDER"/>
    <EVENT id="EVT_ID_MMI_SMS_UM_BT_ENTRY_MAIN_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_MMI_SMS_UM_BT_ENTRY_FOLDER" type="SENDER"/>	
#endif

	<!-- 
    ***************************************************************
    MENU Area for viewer
    ***************************************************************
    -->

<MENU id="MENU_ID_SMS_BT_INBOX_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_REPLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_CALL_SENDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DETAIL</MENUITEM_ID>
</MENU>

<MENU id="MENU_ID_SMS_BT_OUTBOX_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DETAIL</MENUITEM_ID>
</MENU>

<MENU id="MENU_ID_SMS_BT_SENT_FAIL_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DETAIL</MENUITEM_ID>
</MENU>

<MENU id="MENU_ID_SMS_BT_DRAFT_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_VIEWER_OPT_DELETE</MENUITEM_ID>
</MENU>

 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_OPT_REPLY" str="STR_ID_SMS_BT_REPLY_BY_SMS"/>
 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_OPT_DELETE" str="STR_ID_SMS_BT_DELETE"/>
 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_OPT_FORWARD" str="STR_ID_SMS_BT_FORWARD"/>
 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_CALL_SENDER" str="STR_ID_SMS_BT_CALL_SENDER"/>
 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_OPT_RESEND" str="STR_GLOBAL_RESEND"/>
 <MENUITEM id="MENU_ID_SMS_BT_VIEWER_OPT_DETAIL" str="STR_GLOBAL_DETAILS"/>
 
 <!-- 
    ***************************************************************
    MENU Area for editor
    ***************************************************************
    -->
 
 
 <MENU id="MENU_ID_SMS_BT_EDITOR_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_BT_ED_OPT_SEND_TO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_ED_OPT_SAVE_TO_DRAFTS</MENUITEM_ID>
 </MENU>
 
 <MENUITEM id="MENU_ID_SMS_BT_ED_OPT_SEND_TO" str="STR_ID_SMS_BT_SEND_TO"/>
 <MENUITEM id="MENU_ID_SMS_BT_ED_OPT_SAVE_TO_DRAFTS" str="STR_ID_SMS_BT_SAVE"/>
 

    <MENU id="MENU_ID_SMS_BT_ED_OPT_SAVE_TO_DRAFTS" type="OPTION">
        <MENUITEM_ID>MENU_ID_SMS_BT_ED_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_BT_ED_SAVE_TO</MENUITEM_ID>
    </MENU>


			<MENUITEM id="MENU_ID_SMS_BT_ED_EDIT" str="STR_GLOBAL_EDIT"/>
		   <MENUITEM id="MENU_ID_SMS_BT_ED_SAVE_TO" str="STR_GLOBAL_SAVE"/>
		   
		   
#ifdef __MMI_BT_MAP_CLIENT__  
<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_um_bt_ui_aprc_key_proc"/>
<RECEIVER id="EVT_ID_SRV_SMS_BTMAPC_NEW_MSG" proc="mmi_sms_bt_new_msg_receive"/>
<RECEIVER id="EVT_ID_SRV_SMS_BTMAPC_RESET_LIST" proc="mmi_sms_um_bt_deinit_grp_cntx_on_shift"/>
<RECEIVER id="EVT_ID_SRV_SMS_BTMAPC_CONNECTED" proc="mmi_sms_bt_connected"/>
<RECEIVER id="EVT_ID_SRV_SMS_BTMAPC_DISCONNECTED" proc="mmi_sms_bt_disconnected"/>
<RECEIVER id="EVT_ID_SRV_SMS_BTMAPC_DEL_MSG" proc="mmi_sms_bt_msg_deleted"/>
<RECEIVER id="EVT_ID_BT_DIALER_ACL_DISCONN_EVENT_ID" proc="mmi_sms_bt_disconnected"/>
<RECEIVER id="EVT_ID_DIALER_CONN_EVENT_ID" proc="mmi_sms_bt_update_ui"/>
#endif/*__MMI_BT_MAP_CLIENT__*/
</APP>

#endif