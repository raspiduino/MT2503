/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#ifdef __UM_SUPPORT__
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_UNIFIEDMESSAGE"
#if defined (__MMI_APP_MANAGER_SUPPORT__)
    package_name="native.mtk.messaging"
    name="STR_ID_UM_MAIN_MENU_MESSAGES_TEXT"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    img="IMG_UM_LAUNCHER_ICON"
#endif
    launch="mmi_um_entry_main_message_menu"
    package_proc="mmi_um_package_proc"
#else
    name="STR_ID_UM_MAIN_MENU_MESSAGES_TEXT"
#endif
    >   

#if defined(__MMI_CAMCORDER__) && defined(__MMI_APP_MANAGER_SUPPORT__)
    <MEMORY cui="CUI_CAMERACUI"/>
#endif

    <!-- 
    ***************************************************************
    Include Area
    ***************************************************************
    -->
    <INCLUDE file="GlobalResDef.h"/>
#ifndef __COSMOS_MMI_PACKAGE__
    <INCLUDE file="mmi_rp_app_sms_def.h"/>
#if defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
    <INCLUDE file="mmi_rp_app_mmi_wap_push_def.h"/>
#endif /* __WAP_PUSH_SUPPORT__ */
#endif /* __COSMOS_MMI_PACKAGE__ */
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    <INCLUDE file="mmi_rp_app_provbox_def.h"/>
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
#ifdef __MMI_EMAIL__
    <INCLUDE file="mmi_rp_app_email_def.h"/>
#endif /* __MMI_EMAIL__ */
#ifdef __MMI_IMPS__
    <INCLUDE file="mmi_rp_app_imps_def.h"/>
#endif /* __MMI_IMPS__ */
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
    <STRING id="STR_ID_UM_MAIN_MENU_MESSAGES_TEXT"/>
    <STRING id="STR_UM_WRITE_MSG_ID"/>
    <STRING id="STR_UM_SENT_ID"/>

#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    <STRING id="STR_UM_TEMPLATE_ID"/>
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
    <STRING id="STR_UM_SETTING_ID"/>
    <STRING id="STR_UM_MSG_ID"/>
    <STRING id="STR_UM_MSGS_ID"/>
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__    
    <STRING id="STR_UM_MSG_WITH_QUESTION_MARK_ID"/>
    <STRING id="STR_UM_MSGS_WITH_QUESTION_MARK_ID"/>
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    <STRING id="STR_UM_UNREAD_MSG_NUMBER_ID"/>
#endif
    <STRING id="STR_UM_UNREAD_MSG"/>
    <STRING id="STR_UM_UNREAD_MSG_WITH_NUMBER"/>
    <STRING id="STR_UM_UNREAD_MSGS_WITH_NUMBER"/>
#if !defined (__MMI_UM_SLIM__) || defined(__MMI_NCENTER_SUPPORT__ )
    <STRING id="STR_UM_SEND_FAILED_MSG"/>
    <STRING id="STR_UM_SEND_FAILED_MSG_NUMBER"/>
    <STRING id="STR_UM_SEND_FAILED_MSGS_NUMBER"/>
#endif
#ifdef __MMI_UM_REPORT_BOX__
    <STRING id="STR_UM_UNREAD_REPORT"/>
#endif /* __MMI_UM_REPORT_BOX__ */
    <STRING id="STR_UM_SEND_FAILED_SAVE_SUCCESS_ID"/>

    <STRING id="STR_UM_EMPTY_SUBJECT_ID"/>
    <STRING id="STR_UM_EMPTY_CONTENT_ID"/>

    <STRING id="STR_UM_INCOMPLETE_ID"/>
    <STRING id="STR_UM_NOT_SUPPORT_ID"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    <STRING id="STR_UM_ARCHIVE_ID"/>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    <STRING id="STR_UM_SIM_ID"/>
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    <STRING id="STR_UM_REPORT_ID"/>
    <STRING id="STR_UM_NEW_REPORT_MSG_ID"/>
#endif /* __MMI_UM_REPORT_FOLDER__ */
#if defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__) && (!defined(__UM_FOLDER__) || defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)) || defined(__MMI_FTE_SUPPORT__)
    <STRING id="STR_UM_MOVE_ID"/>
#endif /* defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__) && (!defined(__UM_FOLDER__) || defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)) || defined(__MMI_FTE_SUPPORT__) */
#if defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__) && !defined(__UM_FOLDER__) || defined(__MMI_FTE_SUPPORT__)
    <STRING id="STR_UM_COPY_ID"/>
#endif /* defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__) && !defined(__UM_FOLDER__) || defined(__MMI_FTE_SUPPORT__) */
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    <STRING id="STR_UM_MOVE_MARKED_TO_ARCHIVE_ID"/>
    <STRING id="STR_UM_DELETE_MARKED_ID"/>
    <STRING id="STR_UM_MULTI_OP_PRESS_STAR"/>
    <STRING id="STR_UM_MULTI_OP_TOUCH_BOX"/>
    <STRING id="STR_UM_MULTI_OP_UNDELETED_WITH_MSG_ID"/>
    <STRING id="STR_UM_MULTI_OP_UNDELETED_WITH_MSGS_ID"/>
    <STRING id="STR_UM_MULTI_OP_UNMOVED_WITH_MSG_ID"/>
    <STRING id="STR_UM_MULTI_OP_UNMOVED_WITH_MSGS_ID"/>
    <STRING id="STR_UM_MULTI_OP_UNCOPIED_WITH_MSG_ID"/>
    <STRING id="STR_UM_MULTI_OP_UNCOPIED_WITH_MSGS_ID"/>
    
    <STRING id="STR_UM_MOVE_MARKED_TO_ARCHIVE_ID_PRE"/>
    <STRING id="STR_UM_DELETE_MARKED_ID_PRE"/>
    
    <STRING id="STR_UM_DELETE_SEVERAL_ID_PRE"/>
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */



#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    <STRING id="STR_UM_SORT_BY_SENDER_NAME"/>
    <STRING id="STR_UM_SORT_BY_RECIPIENT_NAME"/>
    <STRING id="STR_UM_SORT_BY_SENDER_RECIPIENT_NAME"/>
    <STRING id="STR_UM_SORT_BY_READ_STATUS"/>
    <STRING id="STR_UM_SORT_BY_MSG_SIZE"/>
    <STRING id="STR_UM_SORT_BY_MSG_TYPE"/>
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#if defined(__MMI_UM_DIAL_FROM_FOLDER__) || defined(__MMI_UM_CONVERSATION_BOX__)
    <STRING id="STR_UM_QUESTION_MARK"/>
#endif /* defined(__MMI_UM_DIAL_FROM_FOLDER__) || defined(__MMI_UM_CONVERSATION_BOX__) */    
    <STRING id="STR_UM_EMPTY_MSG_ID"/>

#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__
    <STRING id="STR_UM_ALL_MSG"/>
#endif

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
#ifndef __UM_FOLDER__
    <STRING id="STR_UM_MOVE_TO_SIM"/>
    <STRING id="STR_UM_COPY_TO_SIM"/>
    <STRING id="STR_UM_MOVE_TO_PHONE"/>
    <STRING id="STR_UM_COPY_TO_PHONE"/>
    <STRING id="STR_UM_MOVE_TO_SIM_PRE"/>
    <STRING id="STR_UM_COPY_TO_SIM_PRE"/>
    <STRING id="STR_UM_MOVE_TO_PHONE_PRE"/>
    <STRING id="STR_UM_COPY_TO_PHONE_PRE"/>
#endif /* __UM_FOLDER__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


#if defined ( __MMI_UM_FILTER_BY_SIM_SUPPORT__ )
    <STRING id="STR_UM_FILTER_BY"/>
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */
#ifdef __MMI_UM_CONVERSATION_BOX__
    <STRING id="STR_UM_CONVERSATION_BOX"/>
    <STRING id="STR_UM_CONVERSATION_BOX_ASK"/>
    <STRING id="STR_UM_CONVERSATION_BOXES_ASK"/>
    <STRING id="STR_UM_DELETE_ALL_MSG_IN_CONTACT"/>
    #if (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__))
        <STRING id="STR_UM_REPLY_BY_SMS"/>
        <STRING id="STR_UM_REPLY_BY_MMS"/>
    #endif
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <STRING id="STR_UM_MOVE_TO_ARCHIVE"/>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    <STRING id="STR_UM_MARK_SEVERAL"/> 
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    <STRING id="STR_UM_CB"/>
    
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
    <STRING id="STR_UM_PREFER_SIM"/>
#endif

    <STRING id="STR_UM_DELETE_FOLDER_ID"/>
#if 0
    <STRING id="STR_UM_DELETE_FOLDER_INBOX_ID"/>
    <STRING id="STR_UM_DELETE_FOLDER_UNSENT_ID"/>
    <STRING id="STR_UM_DELETE_FOLDER_SENT_ID"/>
    <STRING id="STR_UM_DELETE_FOLDER_DRAFT_ID"/>
    <STRING id="STR_UM_DELETE_FOLDER_ALL_ID"/>
    <STRING id="STR_UM_MENU_DELETE_FOLDER_ALL_ID"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    <STRING id="STR_UM_DELETE_FOLDER_ARCHIVE_ID"/>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    <STRING id="STR_UM_DELETE_FOLDER_SIM_ID"/>
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    <STRING id="STR_UM_DELETE_FOLDER_REPORT_ID"/>
#endif /* __MMI_UM_REPORT_FOLDER__ */
#endif /* 0 */

#ifdef __MMI_BT_MAP_CLIENT__
    <STRING id="STR_UM_LOCAL"/>
    <STRING id="STR_UM_BT"/>
#endif /* __MMI_BT_MAP_CLIENT__ */

    <!-- 
    ***************************************************************
    IMAGE Area
    ***************************************************************
    -->
    <IMAGE id="IMG_UM_UNREAD_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\icon_msg_unread.png"</IMAGE>
#ifdef __MMI_NCENTER_SUPPORT__
	<IMAGE id="IMG_UM_SEND_FAILED_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\icon_msg_unsent_msg.png"</IMAGE>
#endif
    
#if defined(__MMI_APP_MANAGER_SUPPORT__)
  #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
    <IMAGE id="IMG_UM_LAUNCHER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Message.png"</IMAGE>
  #endif
#endif /* __MMI_APP_MANAGER_SUPPORT__ */
#ifndef __MMI_UM_SLIM__
    <IMAGE id="IMG_UM_MAIN_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_MG.bmp"</IMAGE>
#endif 
    <IMAGE id="IMG_UM_WRITE_MSG_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_WRITE.bmp"</IMAGE>
    <IMAGE id="IMG_UM_INBOX_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_INBOX.bmp"</IMAGE>
    <IMAGE id="IMG_UM_UNSENT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_Unsent.bmp"</IMAGE>
    <IMAGE id="IMG_UM_SENT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_Sent.bmp"</IMAGE>
    <IMAGE id="IMG_UM_DRAFT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_DraftsBox.bmp"</IMAGE>
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    <IMAGE id="IMG_UM_SIM_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_SIMBox.bmp"</IMAGE>
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    <IMAGE id="IMG_UM_REPORT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_ReportBox.bmp"</IMAGE>
#endif /* __MMI_UM_REPORT_BOX__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <IMAGE id="IMG_UM_ARCHIVE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_ArchiveBox.bmp"</IMAGE>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    <IMAGE id="IMG_UM_DELETE_FOLDER_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_Delete.bmp"</IMAGE>
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    <IMAGE id="IMG_UM_TEMPLATE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_Temp.bmp"</IMAGE>
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
    <IMAGE id="IMG_UM_SETTING_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_Set.bmp"</IMAGE>
#if 0
    <IMAGE id="IMG_UM_DELETE_FOLDER_ALL_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_DeleteAll.bmp"</IMAGE>
#endif /* 0 */
#ifdef __MMI_ICON_BAR_SUPPORT__
    <IMAGE id="IMG_UM_ENTRY_SCRN_CAPTION">CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PNG"</IMAGE>
#else
    <IMAGE id="IMG_UM_ENTRY_SCRN_CAPTION">CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PNG"</IMAGE>
#endif
#ifdef __MMI_ICON_BAR_SUPPORT__
    <IMAGE id="IMG_UM_COPY_TOOLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\UniMessage\\\\TB_copy.png"</IMAGE>
    <IMAGE id="IMG_UM_DISABLED_COPY_TOOLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\UniMessage\\\\TB_copy_dis.png"</IMAGE>
    <IMAGE id="IMG_UM_MOVE_TOOLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\UniMessage\\\\TB_move.png"</IMAGE>
    <IMAGE id="IMG_UM_DISABLED_MOVE_TOOLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\UniMessage\\\\TB_move_dis.png"</IMAGE>
#endif /* __MMI_ICON_BAR_SUPPORT__ */
#ifdef __MMI_UM_CONVERSATION_BOX__
    <IMAGE id="IMG_UM_CONVERSATION_BOX">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\SB_ConversationBox.bmp"</IMAGE>
    <IMAGE id="IMG_UM_UNREAD_THREAD_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\UniMessage\\\\CB_UNREAD.bmp"</IMAGE>
    <IMAGE id="IMG_UM_READ_THREAD_MSG">CUST_IMG_PATH"\\\\MainLCD\\\\UniMessage\\\\CB_READ.bmp"</IMAGE>
#endif /* __MMI_UM_CONVERSATION_BOX__ */


#ifdef __MMI_BT_MAP_CLIENT__
    //<IMAGE id="IMG_UM_LOCAL">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_Local.bmp"</IMAGE>
    <IMAGE id="IMG_UM_LOCAL">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\Uni_Local.bmp"</IMAGE>
    //<IMAGE id="IMG_UM_BT">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\UniMessage\\\\Uni_BT.bmp"</IMAGE>
    <IMAGE id="IMG_UM_BT">CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\icons\\\\Uni_BT.bmp"</IMAGE>
#endif

    <!-- 
    ***************************************************************
    SCREEN Area
    ***************************************************************
    -->
    <SCREEN id="GRP_ID_UM_ROOT"/>
    <SCREEN id="SCR_ID_UM_START"/>
    <SCREEN id="SCR_ID_UM_MAIN"/>
    <SCREEN id="SCR_ID_UM_MAIN_MESSAGE"/>
    <SCREEN id="SCR_ID_UM_WRITE_MSG"/>
    <SCREEN id="SCR_ID_UM_DELETE_FOLDER"/>
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    <SCREEN id="SCR_ID_UM_TEMPLATE"/>
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
    <SCREEN id="SCR_ID_UM_SETTING"/>
    <SCREEN id="SCR_ID_UM_PROCESSING"/>
    <SCREEN id="SCR_ID_UM_FOLDER"/>
    <SCREEN id="SCR_ID_UM_MULTI_OP"/>
    <SCREEN id="SCR_ID_UM_CONVERSATION_BOX"/>
    <SCREEN id="SCR_ID_UM_MS_CONVERSATION_BOX"/>
    <SCREEN id="SCR_ID_UM_THREAD_MSG"/>
    <SCREEN id="SCR_ID_UM_MS_THREAD_MSG"/>
    <SCREEN id="SCR_ID_UM_CONVERSATION_BOX_SETTING"/>
    <SCREEN id="SCR_ID_UM_PREFER_SIM_SETTING"/>
#ifndef __COSMOS_MMI_PACKAGE__
    <!-- 
    ***************************************************************
    MENU Area
    ***************************************************************
    -->
#ifdef __MMI_TELEPHONY_SUPPORT__
    <MENU id="MAIN_MENU_MESSAGES_MENUID" type="APP_MAIN" str="MAIN_MENU_MESSAGES_TEXT" img="MAIN_MENU_MESSAGES_ICON" highlight="highlight_mainmenu_messages"
    	shortcut="ON" shortcut_img="MAIN_MENU_MESSAGES_ICON" launch="mmi_um_entry_main_message_menu_with_check">
		#else
    <MENU id="MAIN_MENU_MESSAGES_MENUID" type="APP_MAIN" str="MAIN_MENU_MESSAGES_TEXT" img="MAIN_MENU_MESSAGES_ICON" highlight="highlight_mainmenu_messages"
    	launch="mmi_um_entry_main_message_menu_with_check">
#endif
                                    <MENUITEM_ID>MENU_ID_UM_WRITE_MSG</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_INBOX</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_DRAFT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_UNSENT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SENT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_ARCHIVE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SIM</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_REPORT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_FOLDER</MENUITEM_ID>
#ifdef __MMI_SMS_SLIM__ 
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER</MENUITEM_ID>
#endif
                                    <MENUITEM_ID>MENU_ID_UM_MMS_V01_MAIN</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_PBOX_MAIN</MENUITEM_ID>
                                #if !(defined(__MMI_VUI_3D_MAINMENU__) || defined(__MMI_VUI_LAUNCHER_KEY__) || defined(__MMI_VUI_LAUNCHER__))
                                    <MENUITEM_ID>MENU_ID_UM_EMAIL_MAIN</MENUITEM_ID>
                                #endif /* __MMI_VUI_3D_MAINMENU__ */
                                    <MENUITEM_ID>MENU_ID_UM_IMPS_MAIN</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CB_MAIN</MENUITEM_ID>
                                #if defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
                                    <MENUITEM_ID>MENU_ID_UM_WAP_PUSH_MSG_MAIN</MENUITEM_ID>
                                #endif
                                #ifdef __UM_FOLDER__
                                    <MENUITEM_ID>MENU_ID_UM_TEMPLATE</MENUITEM_ID>
                                #else
                                    <MENUITEM_ID>MENU_ID_UM_TEMPLATE_SMS_ONLY</MENUITEM_ID>
                                #endif /* __UM_FOLDER__ */
                                #ifdef __UM_FOLDER__
                                    <MENUITEM_ID>MENU_ID_UM_SETTING</MENUITEM_ID>
                                #else
                                #if ((defined(__MMI_BT_MAP_CLIENT__) && defined(__MMI_TELEPHONY_SUPPORT__)) || (!defined(__MMI_BT_MAP_CLIENT__)) || (!defined(__MMI_TELEPHONY_SUPPORT__)))
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_SMS_ONLY</MENUITEM_ID>
                                #endif
                                #endif /* __UM_FOLDER__ */
    </MENU>

#ifdef __MMI_TELEPHONY_SUPPORT__
    <MENU id="MENU_ID_UM_WRITE_MSG" type="APP_SUB" str="STR_UM_WRITE_MSG_ID" img="IMG_UM_WRITE_MSG_ID" highlight="mmi_um_highlight_write_msg"
     shortcut="ON" shortcut_img="IMG_UM_WRITE_MSG_ID" launch="mmi_um_entry_write_msg_ext">
#else
    <MENU id="MENU_ID_UM_WRITE_MSG" type="APP_SUB" str="STR_UM_WRITE_MSG_ID" img="IMG_UM_WRITE_MSG_ID" highlight="mmi_um_highlight_write_msg"
    launch="mmi_um_entry_write_msg_ext">
#endif

                                    <MENUITEM_ID>MENU_ID_UM_WRITE_MSG_SMS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_WRITE_MSG_MMS</MENUITEM_ID></MENU>

#ifdef __MMI_UM_CONVERSATION_BOX__
    <MENU id="MENU_ID_UM_CS_BOX" type="APP_SUB" str="STR_UM_CONVERSATION_BOX" img="IMG_UM_CONVERSATION_BOX" highlight="mmi_um_highlight_conversation"></MENU>
    <MENU id="MENU_ID_UM_CS_BOX_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_VIEW</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_REPLY</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_REPLY_BY_SMS</MENUITEM_ID>
        				            <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_REPLY_BY_MMS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_CALL</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_DELETE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_DELETE_ALL</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_ADD_TO_PHB</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_SORT_BY</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_MS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_CS_BOX_OPT_MOVE_TO_ARCH</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_CS_BOX_OPT_VIEW" type="OPTION" str="STR_GLOBAL_OPEN"> </MENU>
    
#if (defined (__MMI_MMS_IN_UM__) && !defined(__MMI_UNIFIED_COMPOSER__))
    <MENU id="MENU_ID_UM_CS_BOX_OPT_REPLY_BY_SMS" type="OPTION" str="STR_UM_REPLY_BY_SMS"> </MENU>
    <MENU id="MENU_ID_UM_CS_BOX_OPT_REPLY_BY_MMS" type="OPTION" str="STR_UM_REPLY_BY_MMS"> </MENU>
#else
    <MENU id="MENU_ID_UM_CS_BOX_OPT_REPLY" type="OPTION" str="STR_GLOBAL_REPLY">  </MENU>
#endif

    <MENU id="MENU_ID_UM_CS_BOX_OPT_CALL" type="OPTION" str="STR_GLOBAL_DIAL"> </MENU>
    <MENU id="MENU_ID_UM_CS_BOX_OPT_DELETE" type="OPTION" str="STR_GLOBAL_DELETE"> </MENU>
    <MENU id="MENU_ID_UM_CS_BOX_OPT_DELETE_ALL" type="OPTION" str="STR_GLOBAL_DELETE_ALL"> </MENU>
    <MENU id="MENU_ID_UM_CS_BOX_OPT_ADD_TO_PHB" type="OPTION" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"> </MENU>
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    <MENU id="MENU_ID_UM_CS_BOX_OPT_SORT_BY" type="OPTION" str="STR_GLOBAL_SORT_BY">
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_TIME</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_RECIPIENT</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_TIME" type="OPTION" str="STR_GLOBAL_TIME"> </MENU>
    <MENU id="MENU_ID_UM_SORT_BY_RECIPIENT" type="OPTION" str="STR_GLOBAL_RECIPIENTS"> </MENU>
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    <MENU id="MENU_ID_UM_CS_BOX_OPT_MS" type="OPTION" str="STR_UM_MARK_SEVERAL"> 
        <MENUITEM_ID>MENU_ID_UM_MS_CS_BOX_OPT_DELETE_PRE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH_PRE</MENUITEM_ID>
    </MENU>
    
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT_DELETE_PRE" type="OPTION" str="STR_UM_DELETE_MARKED_ID_PRE"> </MENU>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH_PRE" type="OPTION" str="STR_UM_MOVE_MARKED_TO_ARCHIVE_ID_PRE"> </MENU>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <MENU id="MENU_ID_UM_CS_BOX_OPT_MOVE_TO_ARCH" type="OPTION" str="STR_UM_MOVE_TO_ARCHIVE"></MENU>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
                                    <MENUITEM_ID>MENU_ID_UM_MS_CS_BOX_OPT_DELETE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MS_CS_BOX_OPT_MARK_ALL</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MS_CS_BOX_OPT_UNMARK_ALL</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT_DELETE" type="OPTION" str="STR_UM_DELETE_MARKED_ID"> </MENU>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT_MOVE_TO_ARCH" type="OPTION" str="STR_UM_MOVE_MARKED_TO_ARCHIVE_ID"> </MENU>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT_MARK_ALL" type="OPTION" str="STR_GLOBAL_MARK_ALL"> </MENU>
    <MENU id="MENU_ID_UM_MS_CS_BOX_OPT_UNMARK_ALL" type="OPTION" str="STR_GLOBAL_UNMARK_ALL"> </MENU>
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_UM_CONVERSATION_BOX__ */

#ifdef __MMI_TELEPHONY_SUPPORT__
    <MENUITEM id="MENU_ID_UM_INBOX" str="STR_GLOBAL_INBOX" img="IMG_UM_INBOX_ID" highlight="mmi_um_highlight_inbox" shortcut="ON" shortcut_img="IMG_UM_INBOX_ID" launch="mmi_um_entry_inbox"/>
#else
	<MENUITEM id="MENU_ID_UM_INBOX" str="STR_GLOBAL_INBOX" img="IMG_UM_INBOX_ID" highlight="mmi_um_highlight_inbox" launch="mmi_um_entry_inbox"/>
#endif

    <MENUITEM id="MENU_ID_UM_DRAFT" str="STR_GLOBAL_DRAFTS" img="IMG_UM_DRAFT_ID" highlight="mmi_um_highlight_draft"/>
    <MENUITEM id="MENU_ID_UM_UNSENT" str="STR_GLOBAL_OUTBOX" img="IMG_UM_UNSENT_ID" highlight="mmi_um_highlight_unsent"/>

#ifdef __MMI_TELEPHONY_SUPPORT__
    <MENUITEM id="MENU_ID_UM_SENT" str="STR_UM_SENT_ID" img="IMG_UM_SENT_ID" highlight="mmi_um_highlight_sent" shortcut="ON" shortcut_img="IMG_UM_SENT_ID" launch="mmi_um_entry_sent"/>
#else
	<MENUITEM id="MENU_ID_UM_SENT" str="STR_UM_SENT_ID" img="IMG_UM_SENT_ID" highlight="mmi_um_highlight_sent" launch="mmi_um_entry_sent"/>
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        <MENUITEM id="MENU_ID_UM_ARCHIVE" str="STR_UM_ARCHIVE_ID" img="IMG_UM_ARCHIVE_ID"/>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    <MENUITEM id="MENU_ID_UM_SIM" str="STR_UM_SIM_ID" img="IMG_UM_SIM_ID"/>
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    <MENUITEM id="MENU_ID_UM_REPORT" str="STR_UM_REPORT_ID" img="IMG_UM_REPORT_ID"/>
#endif /* __MMI_UM_REPORT_BOX__ */
    <MENU id="MENU_ID_UM_DEL_ALL_OPT" type="OPTION" str="STR_GLOBAL_DELETE_ALL"></MENU>
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    <MENU id="MENU_ID_UM_MS_OPT" type="OPTION" str="STR_UM_MARK_SEVERAL">
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_DELETE_PRE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE_PRE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MOVE_TO_SIM_PRE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_COPY_TO_SIM_PRE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE_PRE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_COPY_TO_PHONE_PRE</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_MS_DELETE_OPT" type="OPTION" str="STR_UM_DELETE_SEVERAL_ID_PRE"></MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_DELETE_PRE" type="OPTION" str="STR_UM_DELETE_MARKED_ID_PRE"></MENU>
    
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <MENU id="MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE_PRE" type="OPTION" str="STR_UM_MOVE_MARKED_TO_ARCHIVE_ID_PRE"></MENU>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifndef __UM_FOLDER__
    <MENU id="MENU_ID_UM_MULTI_OP_MOVE_TO_SIM_PRE" type="OPTION" str="STR_UM_MOVE_TO_SIM_PRE"> </MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_COPY_TO_SIM_PRE" type="OPTION" str="STR_UM_COPY_TO_SIM_PRE"> </MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE_PRE" type="OPTION" str="STR_UM_MOVE_TO_PHONE_PRE"> </MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_COPY_TO_PHONE_PRE" type="OPTION" str="STR_UM_COPY_TO_PHONE_PRE"> </MENU>
#endif /* __UM_FOLDER__ */

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    <MENU id="MENU_ID_UM_SORT_BY_OPT" type="OPTION" str="STR_GLOBAL_SORT_BY">
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_TIME</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_RECIPIENT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_SUBJECT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_READ_STATUS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_SIZE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_TYPE</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_TIME" type="OPTION" str="STR_GLOBAL_DATE"></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_RECIPIENT" type="OPTION" str="STR_GLOBAL_RECIPIENTS"></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_SUBJECT" type="OPTION" str="STR_GLOBAL_SUBJECT"></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_READ_STATUS" type="OPTION" str="STR_UM_SORT_BY_READ_STATUS"></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_SIZE" type="OPTION" str="STR_UM_SORT_BY_MSG_SIZE"></MENU>
    <MENU id="MENU_ID_UM_SORT_BY_TYPE" type="OPTION" str="STR_UM_SORT_BY_MSG_TYPE"></MENU>
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
#if defined(__MMI_UM_FILTER_BY_SIM_SUPPORT__)
    <MENU id="MENU_ID_UM_FILTER_BY_OPT" type="OPTION" str="STR_UM_FILTER_BY">
                                    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT_SIM1</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT_SIM2</MENUITEM_ID>
                                    #if (MMI_MAX_SIM_NUM >= 3)
                                    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT_SIM3</MENUITEM_ID>
                                    #endif
                                    #if (MMI_MAX_SIM_NUM >= 4)
                                    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT_SIM4</MENUITEM_ID>
                                    #endif
                                    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT_ALL</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_FILTER_BY_OPT_SIM1" type="OPTION" str="STR_GLOBAL_SIM_1"></MENU>
    <MENU id="MENU_ID_UM_FILTER_BY_OPT_SIM2" type="OPTION" str="STR_GLOBAL_SIM_2"></MENU>
    #if (MMI_MAX_SIM_NUM >= 3)
	<MENU id="MENU_ID_UM_FILTER_BY_OPT_SIM3" type="OPTION" str="STR_GLOBAL_SIM_3"></MENU>
	#endif
    #if (MMI_MAX_SIM_NUM >= 4)
	<MENU id="MENU_ID_UM_FILTER_BY_OPT_SIM4" type="OPTION" str="STR_GLOBAL_SIM_4"></MENU>
	#endif
    <MENU id="MENU_ID_UM_FILTER_BY_OPT_ALL" type="OPTION" str="STR_UM_ALL_MSG"></MENU>
#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

#ifdef __MMI_SMS_SLIM__ 
    <MENU id="MENU_ID_UM_DELETE_MSG_FOLDER" type="APP_SUB" str="STR_UM_DELETE_FOLDER_ID" img="IMG_UM_DELETE_FOLDER_ID" highlight="mmi_um_ui_sh_main_msg_entry_del_msg_folder">
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_INBOX</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_UNSENT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_SENT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_DRAFT</MENUITEM_ID>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_ARCHIVE</MENUITEM_ID>
#endif
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_SIM</MENUITEM_ID>
#endif
#ifdef __MMI_UM_REPORT_BOX__
                                    <MENUITEM_ID>MENU_ID_UM_DELETE_MSG_FOLDER_REPORT</MENUITEM_ID>
#endif
                                    </MENU>
#endif

#if defined(MMS_SUPPORT) && !defined(__UM_FOLDER__)
    <MENUITEM id="MENU_ID_UM_MMS_V01_MAIN" str="STR_GLOBAL_MULTIMEDIA_MESSAGE" img="@OID:MEA_IMG_IMAGE_MMS_MENUENTRY"/>
#endif /* MMS_SUPPORT & !__UM_FOLDER__ */
#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__) && !defined(__MMI_APP_MANAGER_SUPPORT__)
    <MENUITEM id="MENU_ID_UM_PBOX_MAIN" str="STR_ID_PROVBOX_APP" img="IMG_ID_PROVBOX_APP_ICON"/>
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ & !__MMI_PROV_IN_UM__ */
#ifdef __MMI_EMAIL__
    <MENUITEM id="MENU_ID_UM_EMAIL_MAIN" str="STR_GLOBAL_EMAIL" img="IMG_EMAIL_MAIN_ID"/>
#endif /* __MMI_EMAIL__ */
#ifdef __MMI_IMPS__
    <MENUITEM id="MENU_ID_UM_IMPS_MAIN" str="STR_ID_IMPS" img="IMG_ID_IMPS_MENU"/>
#endif /* __MMI_IMPS__ */
    <MENUITEM id="MENU_ID_UM_CB_MAIN" str="STR_UM_CB" img="IMG_SMS_CB_MENUENTRY"/>
#if !defined(__MMI_PUSH_IN_UM__) && defined(BROWSER_SUPPORT) && defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
    <MENUITEM id="MENU_ID_UM_WAP_PUSH_MSG_MAIN" str="STR_ID_PUSH_SERVICE_MESSAGE" img="IMG_ID_WAP_PUSH_INBOX"/>
#endif /* !__MMI_PUSH_IN_UM__ && BROWSER_SUPPORT */
#ifdef __MMI_UM_TEMPLATE_SUPPORT__
    <MENU id="MENU_ID_UM_TEMPLATE" type="APP_SUB" str="STR_UM_TEMPLATE_ID" img="IMG_UM_TEMPLATE_ID" highlight="mmi_um_highlight_template">
                                    <MENUITEM_ID>MENU_ID_UM_TEMPLATE_SMS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_TEMPLATE_MMS</MENUITEM_ID></MENU>
#endif /* __MMI_UM_TEMPLATE_SUPPORT__ */
#if !defined(__UM_FOLDER__) && defined(__MMI_MESSAGES_TEMPLATE__)
    <MENUITEM id="MENU_ID_UM_TEMPLATE_SMS_ONLY" str="STR_ID_SMS_SMS_TEMPLATES_MENUENTRY" img="IMG_MESSAGE_SMS_MENUENTRY"/>
#endif /* !__UM_FOLDER__ & __MMI_MESSAGES_TEMPLATE__ */

    <MENU id="MENU_ID_UM_SETTING" type="APP_SUB" str="STR_UM_SETTING_ID" img="IMG_UM_SETTING_ID" highlight="mmi_um_highlight_setting">
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_SMS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_MMS</MENUITEM_ID>
                                    #if defined(__WAP_PUSH_SUPPORT__) && !defined(__WAP_PUSH_SERVICE_ONLY_SUPPORT__)
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_PUSH</MENUITEM_ID>
#endif /*__WAP_PUSH_SUPPORT__*/
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_CS</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_PREFER_SIM</MENUITEM_ID></MENU>

#ifndef __UM_FOLDER__
#if ((defined(__MMI_BT_MAP_CLIENT__) && defined(__MMI_TELEPHONY_SUPPORT__)) || (!defined(__MMI_BT_MAP_CLIENT__)) || (!defined(__MMI_TELEPHONY_SUPPORT__)))
    <MENUITEM id="MENU_ID_UM_SETTING_SMS_ONLY" str="STR_ID_SMS_MESSAGESETUP_MENUENTRY" img="IMG_ID_SMS_MSG_SETTINGS_MENUENTRY"/>
#endif
#endif /* !__UM_FOLDER__ */
#ifdef __MMI_UM_CONVERSATION_BOX__
    <MENU id="MENU_ID_UM_SETTING_CS" type="APP_SUB" str="STR_UM_CONVERSATION_BOX" img="IMG_UM_CONVERSATION_BOX">
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_CS_ON</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SETTING_CS_OFF</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_SETTING_CS_ON" type="APP_SUB" str="STR_GLOBAL_ON"> </MENU>
    <MENU id="MENU_ID_UM_SETTING_CS_OFF" type="APP_SUB" str="STR_GLOBAL_OFF"> </MENU>
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifndef __MMI_UM_SLIM__
    <MENUITEM id="MENU_ID_UM_WRITE_MSG_SMS" str="STR_GLOBAL_TEXT_MESSAGE" img="IMG_MESSAGE_UNREAD"/>
#else
    <MENUITEM id="MENU_ID_UM_WRITE_MSG_SMS" str="STR_GLOBAL_TEXT_MESSAGE" img="IMG_MESSAGE_SMS_MENUENTRY"/>
#endif
#ifdef __MMI_MMS_IN_UM__
    <MENUITEM id="MENU_ID_UM_WRITE_MSG_MMS" str="STR_GLOBAL_MULTIMEDIA_MESSAGE" img="IMG_MESSAGE_MMS_MENUENTRY"/>
#endif /* __MMI_MMS_IN_UM__ */
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
<MENU id="MENU_ID_UM_SETTING_PREFER_SIM" type="APP_SUB" str="STR_UM_PREFER_SIM" img="IMG_ID_SMS_MSG_SETTINGS_MENUENTRY">
                                <MENUITEM_ID>MENU_ID_UM_SETTING_PREFER_QUERY_ALWAYS</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UM_SETTING_PREFER_SIM1</MENUITEM_ID>
                                <MENUITEM_ID>MENU_ID_UM_SETTING_PREFER_SIM2</MENUITEM_ID>
                                </MENU>
                                
<MENUITEM id="MENU_ID_UM_SETTING_PREFER_QUERY_ALWAYS" str="STR_GLOBAL_ALWAYS_ASK"/>
<MENUITEM id="MENU_ID_UM_SETTING_PREFER_SIM1" str="STR_GLOBAL_SIM_1"/>
<MENUITEM id="MENU_ID_UM_SETTING_PREFER_SIM2" str="STR_GLOBAL_SIM_2"/>

#endif
#ifdef __MMI_SMS_SLIM__ 
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_INBOX" str="STR_GLOBAL_INBOX" img="IMG_UM_INBOX_ID"/>
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_UNSENT" str="STR_GLOBAL_OUTBOX" img="IMG_UM_UNSENT_ID"/>
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_SENT" str="STR_UM_SENT_ID" img="IMG_UM_SENT_ID"/>
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_DRAFT" str="STR_GLOBAL_DRAFTS" img="IMG_UM_DRAFT_ID"/>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_ARCHIVE" str="STR_UM_ARCHIVE_ID" img="IMG_UM_ARCHIVE_ID"/>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_SIM" str="STR_UM_SIM_ID" img="IMG_UM_SIM_ID"/>
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    <MENUITEM id="MENU_ID_UM_DELETE_MSG_FOLDER_REPORT" str="STR_UM_REPORT_ID" img="IMG_UM_REPORT_ID"/>
#endif /* __MMI_UM_REPORT_BOX__ */
#endif
    
#if defined(__MMI_MESSAGES_TEMPLATE__)
#ifdef __MMI_UM_SLIM__
    <MENUITEM id="MENU_ID_UM_TEMPLATE_SMS" str="STR_GLOBAL_TEXT_MESSAGE" img="IMG_MESSAGE_UNREAD"/>
#else
    <MENUITEM id="MENU_ID_UM_TEMPLATE_SMS" str="STR_GLOBAL_TEXT_MESSAGE" img="IMG_MESSAGE_SMS_MENUENTRY"/>
#endif
#endif /* __MMI_MESSAGES_TEMPLATE__ */
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    <MENUITEM id="MENU_ID_UM_TEMPLATE_MMS" str="STR_GLOBAL_MULTIMEDIA_MESSAGE" img="IMG_MESSAGE_MMS_MENUENTRY"/>
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
#ifdef __MMI_UM_SLIM__
    <MENUITEM id="MENU_ID_UM_SETTING_SMS" str="STR_GLOBAL_TEXT_MESSAGE" img="IMG_MESSAGE_UNREAD"/>
#else
    <MENUITEM id="MENU_ID_UM_SETTING_SMS" str="STR_GLOBAL_TEXT_MESSAGE" img="IMG_MESSAGE_SMS_MENUENTRY"/>
#endif
#ifdef __MMI_MMS_IN_UM__
    <MENUITEM id="MENU_ID_UM_SETTING_MMS" str="STR_GLOBAL_MULTIMEDIA_MESSAGE" img="IMG_MESSAGE_MMS_MENUENTRY"/>
#endif /* __MMI_MMS_IN_UM__ */
#ifdef __MMI_PUSH_IN_UM__
    <MENUITEM id="MENU_ID_UM_SETTING_PUSH" str="STR_ID_PUSH_SERVICE_MESSAG" img="IMG_ID_WAP_PUSH_INBOX"/>
#endif /* __MMI_PUSH_IN_UM__ */
#ifdef __MMI_UM_CONVERSATION_BOX__
    <MENUITEM id="MENU_ID_UM_SETTING_CS" str="STR_UM_CONVERSATION_BOX" img="IMG_UM_CONVERSATION_BOX"/>
#endif /* __MMI_UM_CONVERSATION_BOX__ */

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    <MENU id="MENU_ID_UM_MULTI_OP_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_DELETE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MOVE_TO_SIM</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_COPY_TO_SIM</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_COPY_TO_PHONE</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_MARK_ALL</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MULTI_OP_UNMARK_ALL</MENUITEM_ID></MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_DELETE" type="OPTION" str="STR_UM_DELETE_MARKED_ID"></MENU>
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    <MENU id="MENU_ID_UM_MULTI_OP_MOVE_TO_ARCHIVE" type="OPTION" str="STR_UM_MOVE_MARKED_TO_ARCHIVE_ID"></MENU>
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifndef __UM_FOLDER__
    <MENU id="MENU_ID_UM_MULTI_OP_MOVE_TO_SIM" type="OPTION" str="STR_UM_MOVE_TO_SIM"> </MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_COPY_TO_SIM" type="OPTION" str="STR_UM_COPY_TO_SIM"> </MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_MOVE_TO_PHONE" type="OPTION" str="STR_UM_MOVE_TO_PHONE"> </MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_COPY_TO_PHONE" type="OPTION" str="STR_UM_COPY_TO_PHONE"> </MENU>
#endif /* __UM_FOLDER__ */
    <MENU id="MENU_ID_UM_MULTI_OP_MARK_ALL" type="OPTION" str="STR_GLOBAL_MARK_ALL"></MENU>
    <MENU id="MENU_ID_UM_MULTI_OP_UNMARK_ALL" type="OPTION" str="STR_GLOBAL_UNMARK_ALL"></MENU>
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

    <MENU id="MENU_ID_UM_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
                                    <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MS_OPT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_FILTER_BY_OPT</MENUITEM_ID>
                                    <MENUITEM_ID>MENU_ID_UM_SORT_BY_OPT</MENUITEM_ID></MENU>
#endif /* __COSMOS_MMI_PACKAGE__ */


    <EVENT id="EVT_ID_MMI_UM_REFRESH" type="SENDER"/>
    <EVENT id="EVT_ID_MMI_UM_ENTRY_MAIN_MSG" type="SENDER"/>
    <EVENT id="EVT_ID_MMI_UM_ENTRY_FOLDER" type="SENDER"/>
#ifdef __MMI_TELEPHONY_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_READY" proc="mmi_um_ui_adp_receive_event"/>
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG" proc="mmi_um_ui_adp_receive_event"/>
    <RECEIVER id="EVT_ID_SRV_UM_NOTIFY_REFRESH" proc="mmi_um_ui_adp_receive_event"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="mmi_um_ui_cc_sim_ctrl_unavailable_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" proc="mmi_um_ui_cc_sim_ctrl_available_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_um_ui_cc_sim_status_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_um_ui_cc_mode_switch_status_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="mmi_um_sim_refresh_event_hdlr"/>
#endif /*__MMI_TELEPHONY_SUPPORT__*/   
#ifdef __MMI_BT_MAP_CLIENT__
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_um_ui_aprc_key_proc"/>
#endif
    <TIMER id="MESSAGES_TTS_COUNT_DOWN_TIMER_ID"/>
    <TIMER id="UM_INPROGRESS_TIMER_ID"/>
    
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_NCENTER_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" proc="mmi_um_ui_adp_receive_event"/>
#ifdef __MMI_MMS_IN_UM__
    <RECEIVER id="EVT_ID_SRV_MMS_UPDATE_STATUS" proc="mmi_um_ui_adp_receive_event"/>
#endif /* __MMI_MMS_IN_UM__ */
#endif
#endif/*__MMI_TELEPHONY_SUPPORT__*/

#ifdef __MMI_UM_CONVERSATION_BOX__
    <CACHEDATA type="byte" id="NVRAM_UM_CONVERSATION_BOX_SETTING" restore_flag="TRUE">
    #ifdef __OP01__
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #endif /* __OP01__ */
        <DESCRIPTION> UM conversation box setting on / off </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_UM_CONVERSATION_BOX__ */
#ifdef __MMI_NCENTER_SUPPORT__
<CACHEDATA type="byte" id="NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_UNREAD" restore_flag="TRUE">
		<DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
		<DESCRIPTION> UM show NCenter entry in NCenetr after bootup </DESCRIPTION>
</CACHEDATA>
<CACHEDATA type="byte" id="NVRAM_UM_BOOTUP_YES_NO_NCENTER_SHOW_FAILED" restore_flag="TRUE">
		<DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
		<DESCRIPTION> UM show NCenter entry in NCenetr after bootup </DESCRIPTION>
</CACHEDATA>	
#endif
</APP>
#endif /* __UM_SUPPORT__ */