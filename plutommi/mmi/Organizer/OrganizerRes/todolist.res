
#include "MMI_features.h"
#include "CustResDef.h"
#include "TodolistProt.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP 
    id = "APP_TODOLIST"
#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_TODOLIST__)
    package_name = "native.mtk.todo"
    name = "ORGANIZER_MENU_TODOLIST_STRINGID"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON      
    img = "MAIN_MENU_TODOLIST_IMAGEID"
#endif    
    launch = "mmi_tdl_launch"
#endif
    >

    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_vcalendar_def.h"/>
    <INCLUDE file = "mmi_rp_srv_vobject_def.h"/>
    <INCLUDE file = "mmi_rp_app_calendar_def.h"/>
    <INCLUDE file = "Mmi_rp_app_alarm_def.h"/>    
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file = "OrganizerResDef.h"/>
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
#if defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)
    <STRING id = "STR_TODO_LIST_USE_TEMPLATE"/>
	<STRING id = "STR_TODO_LIST_DELETE_ONE_TASK_QUERY"/>
	<STRING id = "STR_TODO_LIST_DELETE_ALL_TASK_QUERY"/>
	<STRING id = "STR_TODO_TEMPLATE_1"/>
	<STRING id = "STR_TODO_TEMPLATE_2"/>
	<STRING id = "STR_TODO_TEMPLATE_3"/>
	<STRING id = "STR_TODO_TEMPLATE_4"/>
	<STRING id = "STR_TODO_TEMPLATE_5"/>
	<STRING id = "STR_TODO_TEMPLATE_6"/>
	<STRING id = "STR_TODO_TEMPLATE_7"/>
	<STRING id = "STR_TODO_TEMPLATE_8"/>
	<STRING id = "STR_TODO_TEMPLATE_9"/>
	<STRING id = "STR_TODO_TEMPLATE_10"/>
	<STRING id = "STR_TODO_TEMPLATE_NOT_ENOUGH_SPACE"/>
    <STRING id = "STR_TODO_REPEAT"/>
    <STRING id = "STR_TODO_ALARM_BEFORE_5_MINS"/>
	<STRING id = "STR_TODO_ALARM_BEFORE_10_MINS"/>
    <STRING id = "STR_TODO_ALARM_BEFORE_15_MINS"/>
    <STRING id = "STR_TODO_ALARM_BEFORE_30_MINS"/>
    <STRING id = "STR_TODO_SET_REPEAT_ONCE"/>
    <STRING id = "STR_TODO_REPEAT_INVALID"/>
    <STRING id = "STR_ID_TDL_TODAY"/>
    <STRING id = "STR_ID_TDL_SELECT"/>
    <STRING id = "STR_ID_TDL_NO_CONTENT"/>
    <STRING id = "STR_ID_TDL_CATEGORY"/>
	<STRING id = "STR_ID_TODO_STATUS_UNDONE"/>
    <STRING id = "STR_TODO_ALARM_OFF_DONE"/>
#ifdef __MMI_BIRTHDAY_REMINDER__
    <STRING id = "STR_ID_BDAY_TIME"/>
    <STRING id = "STR_ID_BDAY_ALERT_ADD_QUERY"/>
    <STRING id = "STR_ID_BDAY_ALERT_DEL_QUERY"/>
    <STRING id = "STR_ID_BDAY_ALERT_EDIT"/>
    <STRING id = "STR_ID_BDAY_REMINDER"/>
    <STRING id = "STR_ID_BDAY_REMINDER_TIME"/>
    <STRING id = "STR_ID_BDAY_REMINDER_NONE"/>
    <STRING id = "STR_ID_BDAY_REMINDER_SAME_DAY"/>
    <STRING id = "STR_ID_BDAY_REMINDER_PREV_DAY"/>
    <STRING id = "STR_ID_TDL_NO_NAME"/>
#endif
#ifdef __MMI_TODO_SEARCH__
	<STRING id = "STR_ID_TODO_SEARCH_BY_TIME"/>
	<STRING id = "STR_ID_TODO_SEARCH_BY_NOTE"/>
	<STRING id = "STR_ID_TODO_SEARCH_BY_LOCATION"/>
#endif
#ifdef __MMI_TODOLIST__
	<STRING id = "ORGANIZER_MENU_TODOLIST_STRINGID"/>
    <STRING id = "STR_TODO_LIST_LIST_FULL_MSG"/>
    <STRING id = "STR_ID_TDL_NO_TASKS"/>
    <STRING id = "STR_ID_TDL_TASK_DELETED"/>
	<STRING id = "STR_ID_TDL_TASKS_DELETED"/>
	<STRING id = "STR_ID_TDL_ADD_TASK"/>
    <STRING id = "STR_ID_TDL_TASKS"/>
    <STRING id = "STR_ID_TODO_STATUS"/>
    <STRING id = "STR_TODO_LIST_VIEW_UNDONE"/>
    <STRING id = "STR_TODO_LIST_JUMP_TO_DATE"/>
    <STRING id = "STR_TODO_LIST_OVERWRITE_QUERY"/>
    <STRING id = "STR_TODO_LIST_DELETE_ALL_QUERY"/>
    <STRING id = "STR_TODO_LIST_DELETE_OVERDUE_QUERY"/>
    <STRING id = "STR_TODO_LIST_DELETE_OVERDUE"/>
    <STRING id = "STR_ID_TDL_DUETIME"/>

#endif
#ifdef __MMI_CALENDAR_EVENT__
	<STRING id = "STR_TODO_LIST_WRONG_DATE_MSG"/>
    <STRING id = "STR_TODO_START_TIME"/>
    <STRING id = "STR_TODO_END_TIME"/>
    <STRING id = "STR_TODO_LOCATION"/>
	<STRING id = "STR_ID_TDL_CAL"/>
	<STRING id = "STR_ID_TDL_NO_EVENTS"/>
	<STRING id = "STR_ID_TDL_CAL_FULL"/>
    <STRING id = "STR_ID_TDL_ADD_APPOINTMENT"/>
	<STRING id = "STR_ID_TDL_ADD_EVENT"/>
	<STRING id = "STR_ID_TDL_EVENTS"/>
    /* Not change the order begin: */	
    <STRING id = "STR_TODO_REMINDER"/>
    <STRING id = "STR_TODO_MEETING"/>
    <STRING id = "STR_TODO_COURSE"/>
    <STRING id = "STR_TODO_DATE"/>
    <STRING id = "STR_TODO_CALL"/>
    <STRING id = "STR_TODO_ANNIVERSARY"/>
    <STRING id = "STR_TODO_BIRTHDAY"/>
	/* Not change the order end */
    <STRING id = "STR_ID_TDL_EVENT_DELETED"/>
    <STRING id = "STR_ID_TDL_EVENT_INVALID_END_TIME"/>
#endif

#if 0    
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
	<STRING id = "STR_ID_TODO_DIARY_REMINDER_DISMISS"/>
	<STRING id = "STR_ID_TODO_DIARY_REMINDER_POSTPONE"/>
#endif
#endif

#ifdef __MMI_VCALENDAR__
    <STRING id = "STR_TODO_NO_CONTENT_TO_SELECT"/>
#endif
	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->

#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON  
    <IMAGE id = "MAIN_MENU_TODOLIST_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Tasks.png"</IMAGE>
#endif
#endif
	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
#if defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)
    <IMAGE id = "IMG_TODO_LIST_DATE">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_CALEN.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_TIME">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_TIME.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_NOTE">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_NOTE.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ALARM">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_ALARM.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_REPEAT">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_REPT.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_DETAILS">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_DETAILS.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ALARM_TIME">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\OT_ALARMTIME.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_ALARM">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\daily\\\\alarm.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_LOCATION">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\OT_LOCATION.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_PRIORITY">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\\OT_PRIORITY.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_STATUS">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\\OT_PRIORITY.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_DONE">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\\daily\\\\done.png"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_UNDONE">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\\daily\\\\undone.png"</IMAGE>
#endif
#ifdef __MMI_TODOLIST__
	<IMAGE id = "ORGANIZER_MENU_TODOLIST_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\SB_OLIST.bmp"</IMAGE>
#endif
#ifdef __MMI_CALENDAR_EVENT__
    /* Not change the order begin: */
    <IMAGE id = "IMG_TODO_LIST_ICON_REMINDER">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\reminder.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_MEETING">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\meeting.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_COURSE">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\course.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_DATE">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\date.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\call.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_ICON_ANNIVERSIRY">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\celebrate.bmp"</IMAGE>
    <IMAGE id = "IMG_TODO_LIST_BIRTHDAY_REMINDER">CUST_IMG_PATH"\\\\MainLCD\\\\ToDoList\\\\icon\\\\birthday.bmp"</IMAGE>
    /* Not change the order end */
#endif
    <!--End Image Resource Area-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->
  
    <SCREEN id = "SCR_TDL_EDIT_NOTE"/>
    <SCREEN id = "SCR_TDL_NOTE_OPTION"/>    
    <SCREEN id = "SCR_TDL_LIST_TEMPLATE"/>
    <SCREEN id = "SCR_TDL_REMINDER"/>    
    <SCREEN id = "SCR_TDL_EDIT_LOCATION"/>    
    <SCREEN id = "SCR_BIRTHDAY_OPTION"/>    
    <SCREEN id = "SCR_ID_TDL_SEARCH"/>    
    <SCREEN id = "SCR_ID_TDL_SEARCH_BY_TIME"/>    
    <SCREEN id = "SCR_ID_TDL_SEARCH_BY_NOTE"/>    
    <SCREEN id = "SCR_ID_TDL_SEARCH_BY_LOC"/>    
    <SCREEN id = "SCR_ID_TDL_SEARCH_RES_LIST"/>    
    <SCREEN id = "SCR_ID_TDL_SEARCH_KEYWORD_OPTION"/>    
    <SCREEN id = "SCR_ID_TDL_BR_ADD"/>    
    <SCREEN id = "SCR_ID_TDL_BR_VIEW"/>    
    <SCREEN id = "SCR_ID_TDL_BR_LIST"/>    
    <SCREEN id = "SCR_ID_TDL_DIARY_REMINDER_OPTION"/>    
    <SCREEN id = "SCR_ID_TDL_HS_SELECT_TYPE"/>   
    <SCREEN id = "SCR_ID_TDL_HS_ADD_SELECT_TYPE"/>       
    <SCREEN id = "SCR_ID_TDL_ADD_SELECT_TYPE"/>    
    <SCREEN id = "SCR_ID_TDL_DELETE_ALL"/>    
    <SCREEN id = "SCR_ID_TDL_DELETE_ALL_ABORT"/>    
    <SCREEN id = "SCR_ID_TDL_DELET_ALL_PASSCODE"/>    
    <SCREEN id = "SCR_ID_TDL_JUMP_TO_DATE"/>
    <SCREEN id = "SCR_ID_TDL_VIEW_UNDONE"/>    
    <SCREEN id = "SCR_ID_TDL_JUMP_TO_DATE_TASK_LIST"/>    
    <SCREEN id = "SCR_ID_TDL_UNDONE_OPTION_LIST"/>    
    <SCREEN id = "SCR_ID_TDL_DAILY_TASK_OPTION"/>    
    <SCREEN id = "SCR_ID_TDL_DETAILS_EDIT"/>    
    <SCREEN id = "SCR_TDL_TASK_DAILY_LIST"/>    
    <SCREEN id = "SCR_TDL_TASK_ALL_LIST"/>    
    <SCREEN id = "SCR_TDL_IMPS_LIST"/>    
    <SCREEN id = "SCR_TDL_SELECT_CATEGORY"/> 
    <SCREEN id = "SCR_TDL_REPEAT_SELECT_TYPE"/> 
    <SCREEN id = "SCR_TDL_ALARM_SELECT_TYPE"/> 
    <SCREEN id = "SCR_TDL_ALARM_SELECT_CUSTOM"/> 
    <SCREEN id = "SCR_TDL_VIEW"/>
    <SCREEN id = "SCR_TDL_TOTAL"/>
	<SCREEN id = "SCR_TDL_EDIT_OPTIONS_LIST"/>

	<!--Screen Group Id-->
	<SCREEN id = "GRP_ID_TDL_BEGIN"/>	
	<SCREEN id = "GRP_ID_TDL_MAIN"/>	
	<SCREEN id = "GRP_ID_TDL_VIEW"/>
	<SCREEN id = "GRP_ID_TDL_EDIT"/>
	<SCREEN id = "GRP_ID_TDL_EDIT_OPTIONS"/>
    <SCREEN id = "GRP_ID_TDL_SEARCH"/>
    <SCREEN id = "GRP_ID_TDL_REMINDER"/>
    <SCREEN id = "GRP_ID_TDL_GOTO_DATE"/>
    <SCREEN id = "GRP_ID_TDL_DELETE"/>
    <SCREEN id = "GRP_ID_TDL_HOME_SCREEN"/>
    <SCREEN id = "GRP_ID_TDL_BR_SAVE"/>
    <SCREEN id = "GRP_ID_TDL_BR_VIEW"/>
    <SCREEN id = "GRP_ID_TDL_BR_REMINDER"/>
    <SCREEN id = "GRP_ID_TDL_END"/>
    <SCREEN id = "SCR_TDL_CAL_DAILY_LIST"/>
    <SCREEN id = "SCR_TDL_CAL_ALL_LIST"/>

	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->

#ifdef __MMI_TODOLIST__
#ifdef __MMI_OP12_MENU_12MATRIX__
	<MENU id="ORGANIZER_TODOLIST_MENU" type="APP_MAIN" parent="MAIN_MENU_EXTRA_MENUID" 
	      str="ORGANIZER_MENU_TODOLIST_STRINGID" img="ORGANIZER_MENU_TODOLIST_IMAGEID" highlight="mmi_tdl_highlight_menu" 
	      shortcut="ON" shortcut_img="ORGANIZER_MENU_TODOLIST_IMAGEID" launch="mmi_tdl_entry_task_view_all">
    </MENU>
#else
	<MENU id="ORGANIZER_TODOLIST_MENU" type="APP_MAIN" parent="MAIN_MENU_ORGANIZER_MENUID" 
	      str="ORGANIZER_MENU_TODOLIST_STRINGID" img="ORGANIZER_MENU_TODOLIST_IMAGEID" highlight="mmi_tdl_highlight_menu" 
	      shortcut="ON" shortcut_img="ORGANIZER_MENU_TODOLIST_IMAGEID" launch="mmi_tdl_entry_task_view_all">
    </MENU>
#endif
    <MENUITEM id = "MITEM_TODO_LIST_VIEW_UNDONE" str = "STR_TODO_LIST_VIEW_UNDONE"/>
    <MENUITEM id = "MITEM_TODO_LIST_JUMP_TO_DATE" str = "STR_TODO_LIST_JUMP_TO_DATE"/>
    <MENUITEM id = "MITEM_TODO_LIST_DELETE_ALL_OVERDUE" str = "STR_TODO_LIST_DELETE_OVERDUE"/>
#endif
    <MENUITEM id = "MITEM_TODO_LIST_VIEW" str = "STR_GLOBAL_VIEW"/>
    <MENUITEM id = "MITEM_TODO_LIST_ADD" str = "STR_GLOBAL_ADD"/>
    <MENUITEM id = "MITEM_TODO_LIST_EDIT" str = "STR_GLOBAL_EDIT"/>
    <MENUITEM id = "MITEM_TODO_LIST_DELETE" str = "STR_GLOBAL_DELETE"/>
    <MENUITEM id = "MITEM_TODO_LIST_DELETE_ALL" str = "STR_GLOBAL_DELETE_ALL"/>
    <MENU id = "MITEM_TODO_LIST_USE_TEMPLATE" type = "OPTION" str = "STR_GLOBAL_USE_TEMPLATE">
    </MENU>
#ifdef __MMI_VCALENDAR__
    #ifdef __MMI_FILE_MANAGER__
    <MENUITEM id = "MENU_VCLNDR_SEND_BY_FILEMGR" str = "@OID:STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>
    #endif
    <MENU id="MENU_VCLNDR_FORWARD" type="OPTION" str="@OID:STR_ID_VCLNDR_FORWARD">
        #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
        <MENUITEM id="MENU_VCLNDR_SEND_BY_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE"/>
        #endif
        #if defined(__MMI_MMS__)
        <MENUITEM id="MENU_VCLNDR_SEND_BY_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
        #endif
        #if  defined(__MMI_EMAIL__)
        <MENUITEM id="MENU_VCLNDR_SEND_BY_EMAIL" str="STR_GLOBAL_AS_EMAIL"/>
        #endif
        #if  defined(__MMI_OPP_SUPPORT__)
        <MENUITEM id="MENU_VCLNDR_SEND_BY_BT" str="STR_GLOBAL_VIA_BLUETOOTH"/>
        #endif        
    </MENU>    
#endif /* __MMI_VCALENDAR__ */
#ifdef __MMI_TODOLIST__
    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_1" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID default = "TRUE">MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_ADD</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_SEARCH</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL_OVERDUE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_JUMP_TO_DATE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW_UNDONE</MENUITEM_ID>
        #ifdef __MMI_VCALENDAR__
        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>
        #ifdef __MMI_FILE_MANAGER__
        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>
        #endif
        #endif /* __MMI_VCALENDAR__ */
    </MENU>
#endif
       
    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_SEARCH" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>
        #ifdef __MMI_VCALENDAR__
        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>
        #ifdef __MMI_FILE_MANAGER__
        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>
        #endif
        #endif /* __MMI_VCALENDAR__ */
    </MENU>
#ifdef __MMI_TODOLIST__
    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_GOTO_DATE" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_JUMP_TO_DATE</MENUITEM_ID>    
        #ifdef __MMI_VCALENDAR__
        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>
        #ifdef __MMI_FILE_MANAGER__
        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>
        #endif
        #endif /* __MMI_VCALENDAR__ */
    </MENU>
#endif
    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_VEVENT" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_ADD</MENUITEM_ID>        
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_SEARCH</MENUITEM_ID>        
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
#ifdef __MMI_SNS_CALENDAR__        
        <MENUITEM_ID>MENU_ID_CLNDR_EVENT_FILTER</MENUITEM_ID>
#endif 
        #ifdef __MMI_VCALENDAR__
        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>
        #ifdef __MMI_FILE_MANAGER__
        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>
        #endif
        #endif /* __MMI_VCALENDAR__ */
    </MENU>

    <MENU id = "MITEM_TODO_LIST_TASK_OPTION_VIEW_UNDONE" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MITEM_TODO_LIST_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MITEM_TODO_LIST_DELETE_ALL</MENUITEM_ID>        
        #ifdef __MMI_VCALENDAR__
        <MENUITEM_ID>MENU_VCLNDR_FORWARD</MENUITEM_ID>
        #ifdef __MMI_FILE_MANAGER__
        <MENUITEM_ID>MENU_VCLNDR_SEND_BY_FILEMGR</MENUITEM_ID>
        #endif
        #endif /* __MMI_VCALENDAR__ */
    </MENU>

#ifdef __MMI_OP11_HOMESCREEN__
    <MENU id = "MITEM_TDL_SEL_TYPE_VCAL" type = "APP_SUB" str = "0">
        <MENUITEM id = "MITEM_TDL_SEL_TYPE_VEVENT" str = "STR_ID_TDL_CAL"/>
#ifdef __MMI_TODOLIST__
    	<MENUITEM id = "MITEM_TDL_SEL_TYPE_VTODO" str = "STR_ID_TDL_TASKS"/>
#endif
    </MENU>

    <MENU id = "MITEM_TDL_ADD_TYPE_VCAL" type = "APP_SUB" str = "0">
        <MENUITEM id = "MITEM_TDL_TYPE_VEVENT" str = "STR_ID_TDL_ADD_EVENT"/>
#ifdef __MMI_TODOLIST__
        <MENUITEM id = "MITEM_TDL_TYPE_VTODO" str = "STR_ID_TDL_ADD_TASK"/>
#endif
    </MENU>
#endif
    
    <MENU id = "MITEM_TDL_CATEGORY_TYPE" type = "APP_SUB" str = "STR_ID_TDL_CATEGORY">
        <MENUITEM id = "MITEM_TODO_LIST_REMINDER" str = "STR_TODO_REMINDER"/>
        <MENUITEM id = "MITEM_TODO_LIST_MEETING" str = "STR_TODO_MEETING"/>
        <MENUITEM id = "MITEM_TODO_LIST_COURSE" str = "STR_TODO_COURSE"/>
        <MENUITEM id = "MITEM_TODO_LIST_DATE" str = "STR_TODO_DATE"/>
        <MENUITEM id = "MITEM_TODO_LIST_CALL" str = "STR_TODO_CALL"/>
        <MENUITEM id = "MITEM_TODO_LIST_ANNIVERSARY" str = "STR_TODO_ANNIVERSARY"/>
        <MENUITEM id = "MITEM_TODO_LIST_BIRTHDAY" str = "STR_TODO_BIRTHDAY"/>
    </MENU>

    <MENU id = "MITEM_TDL_REPEAT_TYPE" type = "APP_SUB" str = "STR_ID_TDL_CATEGORY">
        <MENUITEM id = "MITEM_TDL_LIST_ONCE" str = "@OID:ALARM_ONCE_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_DAILY" str = "@OID:ALARM_EVREYDAY_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_DAYS" str = "STR_GLOBAL_CUSTOM"/>
        <MENUITEM id = "MITEM_TDL_LIST_WEEKLY" str = "@OID:ALARM_WEEKLY_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_MONTHLY" str = "@OID:ALARM_MONTHLY_STRING"/>
        <MENUITEM id = "MITEM_TDL_LIST_YEARLY" str = "@OID:ALARM_YEARLY_STRING"/>    
    #ifdef __MMI_INDICAL__
        <MENUITEM id = "MITEM_TDL_LIST_TITHI" str = "@OID:ALARM_TITHI_STRING"/>        
    #endif
    </MENU>

    <MENU id = "MITEM_TDL_ALARM_TYPE" type = "APP_SUB" str = "STR_ID_TDL_CATEGORY">
        <MENUITEM id = "MITEM_TDL_ALM_OFF"            str = "STR_GLOBAL_OFF"/>
        <MENUITEM id = "MITEM_TDL_ALM_ON"             str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_5_MINS"  str = "STR_TODO_ALARM_BEFORE_5_MINS"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_10_MINS" str = "STR_TODO_ALARM_BEFORE_10_MINS"/>
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_15_MINS" str = "STR_TODO_ALARM_BEFORE_15_MINS"/> 
        <MENUITEM id = "MITEM_TDL_ALM_BEFORE_30_MINS" str = "STR_TODO_ALARM_BEFORE_30_MINS"/>  
 //       <MENUITEM id = "MITEM_TDL_ALM_CUSTOM"         str = "STR_GLOBAL_CUSTOM"/>
    </MENU>

    <MENU id = "MITEM_TDL_EDIT_OPTIONS" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MITEM_TDL_EDIT_OPTIONS_SELECT"     str = "STR_ID_TDL_SELECT"/>
        <MENUITEM id = "MITEM_TDL_EDIT_OPTIONS_SAVE"       str = "STR_GLOBAL_SAVE"/>
    </MENU>
    
#ifdef __MMI_TODO_SEARCH__
	<MENU id = "MITEM_TODO_LIST_SEARCH" type = "APP_SUB" str = "STR_GLOBAL_SEARCH">
    	<MENUITEM id = "MITEM_TODO_LIST_SEARCH_BY_TIME" str = "STR_ID_TODO_SEARCH_BY_TIME"/>
    	<MENUITEM id = "MITEM_TODO_LIST_SEARCH_BY_NOTE" str = "STR_ID_TODO_SEARCH_BY_NOTE"/>
    	<MENUITEM id = "MITEM_TODO_LIST_SEARCH_BY_LOC" str = "STR_ID_TODO_SEARCH_BY_LOCATION"/>
    </MENU>
#endif
#if 0
#ifdef __MMI_OP11_TODOLIST_DIARY_SUPPORT__
	<MENU id = "MITEM_TDL_DIARY_REMINDER_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
    	<MENUITEM id = "MITEM_TDL_DIARY_REMINDER_OPTION_EDIT" str = "STR_GLOBAL_EDIT"/>
    	<MENUITEM id = "MITEM_TDL_DIARY_REMINDER_OPTION_POSTPONE" str = "STR_ID_TODO_DIARY_REMINDER_POSTPONE"/>
    </MENU>    	
#endif /* __MMI_OP11_TODOLIST_DIARY_SUPPORT__ */
#endif
#endif /* __MMI_CALENDAR_EVENT__ || __MMI_TODOLIST__*/
	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->

#ifdef __MMI_BIRTHDAY_REMINDER__
    <RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="mmi_tdl_phb_deletion_proc"/>    
#endif 

#if defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)
    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_tdl_reminder_notify_proc"/>    
	<RECEIVER id="EVT_ID_SRV_TDL_OP" proc="mmi_tdl_set_reminder_proc"/>	
#endif

    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

</APP>

