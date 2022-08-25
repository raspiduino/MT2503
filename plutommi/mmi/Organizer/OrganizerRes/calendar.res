
#include "MMI_features.h"
#include "CustResDef.h"
//lhm add for optiom slim
#include "gui_calendar.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_CALENDAR" 
#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_CALENDAR__)
    package_name="native.mtk.calendar"
    name="ORGANIZER_MENU_CALENDER_STRINGID"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON      
    img="MAIN_MENU_CALENDAR_ICON"
#endif    
    launch="ClndrPreEntryApp"
#endif /*defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_CALENDAR__)*/
>
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file = "OrganizerResDef.h"/>
#if defined (__MMI_HIJRI_CALENDAR__)
    <INCLUDE file = "mmi_rp_app_hijri_calendar_def.h"/>
#endif
#ifdef __MMI_INDICAL__
	<INCLUDE file = "mmi_rp_app_indical_def.h"/>
#endif
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

#ifdef __MMI_CALENDAR__
    <STRING id="ORGANIZER_MENU_CALENDER_STRINGID"/>
#ifdef __MMI_CALENDAR_CHINESE_SUPPORT__
    <STRING id="CAL_STRING_LUNAR"/>
    <STRING id="STR_CAL_CHINESE_NO1"/>
    <STRING id="STR_CAL_CHINESE_NO2"/>
    <STRING id="STR_CAL_CHINESE_NO3"/>
    <STRING id="STR_CAL_CHINESE_NO4"/>
    <STRING id="STR_CAL_CHINESE_NO5"/>
    <STRING id="STR_CAL_CHINESE_NO6"/>
    <STRING id="STR_CAL_CHINESE_NO7"/>
    <STRING id="STR_CAL_CHINESE_NO8"/>
    <STRING id="STR_CAL_CHINESE_NO9"/>
    <STRING id="STR_CAL_CHINESE_NO10"/>
    <STRING id="STR_CAL_CHINESE_NO20"/>
    <STRING id="STR_CAL_CHINESE_NO30"/>
    <STRING id="STR_CAL_SOLARTERM1"/>
    <STRING id="STR_CAL_SOLARTERM2"/>
    <STRING id="STR_CAL_SOLARTERM3"/>
    <STRING id="STR_CAL_SOLARTERM4"/>
    <STRING id="STR_CAL_SOLARTERM5"/>
    <STRING id="STR_CAL_SOLARTERM6"/>
    <STRING id="STR_CAL_SOLARTERM7"/>
    <STRING id="STR_CAL_SOLARTERM8"/>
    <STRING id="STR_CAL_SOLARTERM9"/>
    <STRING id="STR_CAL_SOLARTERM10"/>
    <STRING id="STR_CAL_SOLARTERM11"/>
    <STRING id="STR_CAL_SOLARTERM12"/>
    <STRING id="STR_CAL_SOLARTERM13"/>
    <STRING id="STR_CAL_SOLARTERM14"/>
    <STRING id="STR_CAL_SOLARTERM15"/>
    <STRING id="STR_CAL_SOLARTERM16"/>
    <STRING id="STR_CAL_SOLARTERM17"/>
    <STRING id="STR_CAL_SOLARTERM18"/>
    <STRING id="STR_CAL_SOLARTERM19"/>
    <STRING id="STR_CAL_SOLARTERM20"/>
    <STRING id="STR_CAL_SOLARTERM21"/>
    <STRING id="STR_CAL_SOLARTERM22"/>
    <STRING id="STR_CAL_SOLARTERM23"/>
    <STRING id="STR_CAL_SOLARTERM24"/>
#if 0
    <STRING id="STR_CAL_KAN1"/>
    <STRING id="STR_CAL_KAN2"/>
    <STRING id="STR_CAL_KAN3"/>
    <STRING id="STR_CAL_KAN4"/>
    <STRING id="STR_CAL_KAN5"/>
    <STRING id="STR_CAL_KAN6"/>
    <STRING id="STR_CAL_KAN7"/>
    <STRING id="STR_CAL_KAN8"/>
    <STRING id="STR_CAL_KAN9"/>
    <STRING id="STR_CAL_KAN10"/>
    <STRING id="STR_CAL_CHI1"/>
    <STRING id="STR_CAL_CHI2"/>
    <STRING id="STR_CAL_CHI3"/>
    <STRING id="STR_CAL_CHI4"/>
    <STRING id="STR_CAL_CHI5"/>
    <STRING id="STR_CAL_CHI6"/>
    <STRING id="STR_CAL_CHI7"/>
    <STRING id="STR_CAL_CHI8"/>
    <STRING id="STR_CAL_CHI9"/>
    <STRING id="STR_CAL_CHI10"/>
    <STRING id="STR_CAL_CHI11"/>
    <STRING id="STR_CAL_CHI12"/>
#endif
    <STRING id="STR_CAL_MONTH"/>
	<STRING id="STR_CLNDR_LEAP"/>
    <STRING id="STR_CLNDR_CHINESE_CHU"/>
    <STRING id="STR_CLNDR_CHINESE_ZHENG_YUE"/>
    <STRING id="STR_CLNDR_CHINESE_LA_YUE"/>
    <STRING id="STR_ID_CLNDR_HDAY_NEW_YEAR"/>
    <STRING id="STR_ID_CLNDR_HDAY_SPRING"/>
    <STRING id="STR_ID_CLNDR_HDAY_DRAGON_BOAT"/>
    <STRING id="STR_ID_CLNDR_HDAY_LABOR"/>
    <STRING id="STR_ID_CLNDR_HDAY_MID_AUTUMN"/>
    <STRING id="STR_ID_CLNDR_HDAY_NATIONAL"/>
#endif /*__MMI_CALENDAR_CHINESE_SUPPORT__*/
    <STRING id="STR_CLNDR_JUMP_TO"/>
    <STRING id="STR_CLNDR_GOTO_TODAY"/>
    <STRING id="STR_CLNDR_WRONG_DATE"/>
    <STRING id="STR_CLNDR_OUT_OF_CALENDAR"/>
#ifdef __MMI_BTD_BOX_UI_STYLE__
    <STRING id="STR_CLNDR_GOTO_YEAR_DISP_CAPTION"/>
    <STRING id="STR_CLNDR_GOTO_MONTH_AND_DAY_DISP_CAPTION"/>
#endif /* __MMI_BTD_BOX_UI_STYLE__ */
#if 0
    <STRING id="STR_ID_CLNDR_OVERWRITE_QUERY"/>
#endif
#if !defined( __MMI_MAINLCD_96X64__) && defined(__MMI_CALENDAR_EVENT__)
    <STRING id="STR_CLNDR_WEEKLY_VIEW"/>
    <STRING id="STR_CLNDR_MONTHLY_VIEW"/>
#endif    
#ifdef __MMI_SNS_CALENDAR__   
	<STRING id="STR_ID_CLNDR_EVENT_FILTER"/>
#endif /*__MMI_SNS_CALENDAR__*/
#ifdef __MMI_CALENDAR_EVENT__
    <STRING id="STR_CLNDR_DAILY_VIEW"/>
    <STRING id="STR_ID_CLNDR_DELETE_EVENT"/>
    <STRING id="STR_ID_CLNDR_DELETE_ALL"/>
    <STRING id="STR_ID_CLNDR_DELETE_ALL_OVERDUE_QUERY"/>
    <STRING id="STR_ID_CLNDR_DELETE_ALL_QUERY"/>
    <STRING id="STR_ID_CLNDR_DELETE_ALL_OVERDUE"/>
    <STRING id="STR_ID_CLNDR_DELETE_SPEC_PERIOD_QUERY"/>
    <STRING id="STR_ID_CLNDR_DELETE_SPEC_PERIOD"/>
    <STRING id="STR_CLNDR_ADD_TASK"/>
    <STRING id="STR_ID_CLNDR_VIEW_ALL"/>
    <STRING id="STR_ID_TDL_EVENT_DELETED"/>
    <STRING id="STR_ID_TDL_EVENTS_DELETED"/>

	  <STRING id="STR_ID_CLNDR_EVENT_SELECT_ALL"/>
    <STRING id="STR_ID_CLNDR_EVENT_LOCAL"/>
    <STRING id="STR_ID_CLNDR_EVENT_FACEBOOK"/>
    <STRING id="STR_ID_CLNDR_EVENT_KAIXIN"/>
    <STRING id="STR_ID_CLNDR_EVENT_RENREN"/>
    <STRING id="STR_ID_CLNDR_EVENT_TWITTER"/>

    <STRING id="STR_ID_CAL_COLON"/>
#endif

#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
    <STRING id="STR_CLNDR_ONSCREEN_DISPLAY"/>
    <STRING id="STR_HIJRI_ONSCREEN_HIJRI"/>
    <STRING id="STR_INDICAL_ONSCREEN_INDIAN"/>
    <STRING id="STR_CLNDR_ENGLISH"/>
    <STRING id="STR_CLNDR_ENGLISH_HELP"/>
    <STRING id="STR_CLNDR_CHINESE_HELP"/>
    <STRING id="STR_CLNDR_INFO_DISP_OFF"/>
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <STRING id="STR_CLNDR_NEXT_VIEW"/>
    <STRING id="STR_CLNDR_NEW_MEETING"/>
#endif
#ifdef	__MMI_CALENDAR_FDOW__
	<STRING id="STR_ID_CLNDR_FIRST_DAY_OF_WEEK"/>
#endif	
	<!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON  
    <IMAGE id = "MAIN_MENU_CALENDAR_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Calendar.png"</IMAGE>
#endif
#endif
    <IMAGE id="ORGANIZER_MENU_CALENDER_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Organizer\\\\SB_OCDAR.bmp"</IMAGE>

#ifdef __MMI_CALENDAR_EVENT__
#ifdef __MMI_SNS_CALENDAR__        
    <IMAGE id="IMG_CLNDR_EVENT_KAIXIN">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\kaixin_s.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_EVENT_RENREN">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\renren_s.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_EVENT_FACEBOOK">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\facebook_s.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_EVENT_TWITTER">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\kaixin_s.png"</IMAGE>
#endif 
#endif
   
#ifdef __MMI_CLNDR_EVENT_INFO__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <IMAGE id="IMG_CLNDR_TASK_CLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\time.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_REMINDER">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\reminder.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_MEETING">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\meeting.png"</IMAGE>    
    <IMAGE id="IMG_CLNDR_ICON_COURSE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\course.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_DATE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\date.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\call.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_ANNIVERSIRY">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\celebrate.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_BIRTHDAY_REMINDER">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\birthday.bmp"</IMAGE>
#else /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    <IMAGE id="IMG_CLNDR_TASK_CLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\time.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_REMINDER">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\reminder.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_MEETING">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\meeting.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_COURSE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\course.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_DATE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\date.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\call.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_ICON_ANNIVERSIRY">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\celebrate.bmp"</IMAGE>
    <IMAGE id="IMG_CLNDR_BIRTHDAY_REMINDER">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\birthday.bmp"</IMAGE>
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
#endif /* __MMI_CLNDR_EVENT_INFO__ */


#if defined(__MMI_ICON_BAR_SUPPORT__)
    <IMAGE id="IMG_CLNDR_TOOLBAR_NEW_MEETING">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_new_meeting.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_TOOLBAR_NEW_MEETING_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_new_meeting_dis.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_TOOLBAR_VIEW_MONTH">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_view_month.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_TOOLBAR_VIEW_MONTH_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_view_month_dis.png"</IMAGE>
#ifdef __MMI_CALENDAR_EVENT__
    <IMAGE id="IMG_CLNDR_TOOLBAR_VIEW_WEEK">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_view_week.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_TOOLBAR_VIEW_WEEK_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_view_week_dis.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_TOOLBAR_VIEW_DAY">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_view_day.png"</IMAGE>
    <IMAGE id="IMG_CLNDR_TOOLBAR_VIEW_DAY_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Calendar\\\\TB_view_day_dis.png"</IMAGE>
#endif /* __MMI_CALENDAR_EVENT__ */
#endif /* defined(__MMI_ICON_BAR_SUPPORT__) */


    <!--End Image Resource Area-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Audio Resource Area-->
	<!--Audio Resource Area-->

	<!--End Audio Resource Area-->
	<!--End Audio Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Media Resource Area-->
	<!--Media Resource Area-->

	<!--End Media Resource Area-->
	<!--End Media Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->

    <SCREEN id = "SCR_ID_CLNDR_SCREEN"/>
    <SCREEN id = "SCR_ID_CLNDR_OPTION"/>
    <SCREEN id = "SCR_ID_CLNDR_JUMP"/>
    <SCREEN id = "SCR_ID_CLNDR_DELETE_EVENT"/>
    <SCREEN id = "SCR_ID_CLNDR_DELETE_SPEC_TIME"/>
    <SCREEN id = "SCR_ID_CLNDR_SETTINGS"/>
    <SCREEN id = "SCR_ID_CLNDR_HELP"/>
    <SCREEN id = "SCR_ID_CLNDR_END_OF_ENUM"/>
    <SCREEN id = "SCR_ID_CLNDR_EVENT_FILTER"/>
    <SCREEN id = "SCR_ID_CLNDR_SWITCH_WEEK_FIRST_DAY"/>
	<!--Screen Group Id-->
    <SCREEN id = "GRP_ID_CAL_BEGIN"/>	
    <SCREEN id = "GRP_ID_CAL_MAIN"/>
    <SCREEN id = "GRP_ID_CAL_JUMP"/>
    <SCREEN id = "GRP_ID_CAL_DELETE"/>
    <SCREEN id = "GRP_ID_CAL_DAILY_VIEW"/>
    <SCREEN id = "GRP_ID_CAL_ALL_VIEW"/>
    <SCREEN id = "GRP_ID_CAL_SAVE"/>
    <SCREEN id = "GRP_ID_CAL_END"/>    

	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->
#ifdef __MMI_CALENDAR__	
#ifdef __MMI_OP12_MENU_12MATRIX__
	<MENU id="ORGANIZER_CALENDER_MENU" type="APP_MAIN" parent="MAIN_MENU_EXTRA_MENUID" 
	      str="ORGANIZER_MENU_CALENDER_STRINGID" img="ORGANIZER_MENU_CALENDER_IMAGEID" highlight="HighlightClndrMenu" 
	      shortcut="ON" shortcut_img="ORGANIZER_MENU_CALENDER_IMAGEID" launch="ClndrPreEntryApp">
    </MENU>
#else
	<MENU id="ORGANIZER_CALENDER_MENU" type="APP_MAIN" parent="MAIN_MENU_ORGANIZER_MENUID" 
	      str="ORGANIZER_MENU_CALENDER_STRINGID" img="ORGANIZER_MENU_CALENDER_IMAGEID" highlight="HighlightClndrMenu" 
	      shortcut="ON" shortcut_img="ORGANIZER_MENU_CALENDER_IMAGEID" launch="ClndrPreEntryApp">
    </MENU>
#endif
#endif

#ifdef __MMI_CALENDAR_EVENT__
    <MENUITEM id="MENU_GOTO_TASK_CAL" str="STR_GLOBAL_VIEW"/>
    <MENUITEM id="MENU_ID_CLNDR_VIEW_ALL" str="STR_ID_CLNDR_VIEW_ALL"/>
    <MENUITEM id="MENU_ID_CLNDR_ADD_TASK" str="STR_CLNDR_ADD_TASK"/>
#ifdef __MMI_SNS_CALENDAR__   	
	<MENUITEM id = "MENU_ID_CLNDR_EVENT_FILTER" str = "@OID:STR_ID_CLNDR_EVENT_FILTER"/>
#endif     
#endif /* __MMI_CALENDAR_EVENT__ */

    <MENUITEM id="MENU_ID_CLNDR_JUMP_TO_DATE" str="STR_CLNDR_JUMP_TO"/>
    <MENUITEM id="MENU_ID_CLNDR_GOTO_TODAY" str="STR_CLNDR_GOTO_TODAY"/>
#if !defined(__MMI_MAINLCD_96X64__)&&defined(__MMI_CALENDAR_EVENT__)
    <MENUITEM id="MENU_ID_CLNDR_MONTHLY_VIEW" str="STR_CLNDR_MONTHLY_VIEW"/>
#endif
#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)	
    <MENUITEM id="MENU_CAL_TYPE" str="CAL_STRING_LUNAR"/>
#endif
    
#ifdef	__MMI_CALENDAR_FDOW__    
	<MENUITEM id="MENU_ID_CLNDR_FIRST_DAY_OF_WEEK" str="STR_ID_CLNDR_FIRST_DAY_OF_WEEK"/>
#endif

#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
    <MENUITEM id="MENU_ID_CLNDR_SETTINGS" str="STR_GLOBAL_SETTINGS"/>
    <MENUITEM id="MENU_ID_CLNDR_HELP" str="STR_GLOBAL_HELP"/>
#endif


    <MENU id="ORGANIZER_CALENDER_MONTHLY_OPTIONS_MENU" type="OPTION" str="@OID:ORGANIZER_MENU_CALENDER_STRINGID">
#ifdef __MMI_CALENDAR_EVENT__
        <MENUITEM_ID>MENU_GOTO_TASK_CAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_VIEW_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_ADD_TASK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_DELETE_EVENT</MENUITEM_ID>
#ifdef __MMI_SNS_CALENDAR__        
        <MENUITEM_ID>MENU_ID_CLNDR_EVENT_FILTER</MENUITEM_ID>
#endif         
#endif /* __MMI_CALENDAR_EVENT__ */        
        <MENUITEM_ID>MENU_ID_CLNDR_JUMP_TO_DATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_GOTO_TODAY</MENUITEM_ID>
#if !defined(__MMI_MAINLCD_96X64__) && defined( __MMI_CALENDAR_EVENT__)
        <MENUITEM id="MENU_ID_CLNDR_WEEKLY_VIEW" str="STR_CLNDR_WEEKLY_VIEW"/>
#endif
#ifdef __MMI_HIJRI_CALENDAR__
        <MENUITEM_ID>@OID:MENU_ID_HIJRI_DAY_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_HIJRI_FESTIVALS</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_HIJRI_DATE_CORRECTION</MENUITEM_ID>
#endif /* __MMI_HIJRI_CALENDAR__ */
#ifdef __MMI_INDICAL__
        <MENUITEM_ID>@OID:MENU_ID_INDICAL_TITHI</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_INDICAL_FESTIVAL_LIST</MENUITEM_ID>
#endif
#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
        <MENUITEM_ID>MENU_ID_CLNDR_SETTINGS</MENUITEM_ID>
#endif

#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
        <MENUITEM_ID>MENU_ID_CLNDR_HELP</MENUITEM_ID>
#endif
#if (!defined(__MMI_INDICAL__)) && (!defined(__MMI_HIJRI_CALENDAR__))
        <MENUITEM_ID>MENU_CAL_TYPE</MENUITEM_ID>
#endif
#ifdef	__MMI_CALENDAR_FDOW__
        <MENUITEM_ID>MENU_ID_CLNDR_FIRST_DAY_OF_WEEK</MENUITEM_ID>
#endif
    </MENU>

#ifdef __MMI_CALENDAR_EVENT__
    <MENU id="ORGANIZER_CALENDER_WEEKLY_OPTIONS_MENU" type="OPTION" str="@OID:ORGANIZER_MENU_CALENDER_STRINGID">
        <MENUITEM_ID>MENU_GOTO_TASK_CAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_VIEW_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_ADD_TASK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_DELETE_EVENT</MENUITEM_ID>
#ifdef __MMI_SNS_CALENDAR__        
        <MENUITEM_ID>MENU_ID_CLNDR_EVENT_FILTER</MENUITEM_ID>
#endif        
       
        <MENUITEM_ID>MENU_ID_CLNDR_JUMP_TO_DATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLNDR_GOTO_TODAY</MENUITEM_ID>
#ifndef __MMI_MAINLCD_96X64__                
        <MENUITEM_ID>MENU_ID_CLNDR_MONTHLY_VIEW</MENUITEM_ID>
#endif        
#ifdef __MMI_HIJRI_CALENDAR__
        <MENUITEM_ID>@OID:MENU_ID_HIJRI_DAY_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_HIJRI_FESTIVALS</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_HIJRI_DATE_CORRECTION</MENUITEM_ID>
#endif /* __MMI_HIJRI_CALENDAR__ */
#ifdef __MMI_INDICAL__
        <MENUITEM_ID>@OID:MENU_ID_INDICAL_TITHI</MENUITEM_ID>
        <MENUITEM_ID>@OID:MENU_ID_INDICAL_FESTIVAL_LIST</MENUITEM_ID>
#endif
#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
        <MENUITEM_ID>MENU_ID_CLNDR_SETTINGS</MENUITEM_ID>
#endif

#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
        <MENUITEM_ID>MENU_ID_CLNDR_HELP</MENUITEM_ID>
#endif
#if (!defined(__MMI_INDICAL__)) && (!defined(__MMI_HIJRI_CALENDAR__))
        <MENUITEM_ID>MENU_CAL_TYPE</MENUITEM_ID>
#endif
#ifdef	__MMI_CALENDAR_FDOW__
		<MENUITEM_ID>MENU_ID_CLNDR_FIRST_DAY_OF_WEEK</MENUITEM_ID>
#endif
    </MENU>

    <MENU id="MENU_ID_CLNDR_DELETE_EVENT" type="OPTION" str="STR_ID_CLNDR_DELETE_EVENT">
        <MENUITEM id="MENU_ID_CLNDR_DELETE_ALL" str="STR_ID_CLNDR_DELETE_ALL"/>
        <MENUITEM id="MENU_ID_CLNDR_DELETE_ALL_OVERDUE" str="STR_ID_CLNDR_DELETE_ALL_OVERDUE"/>
        <MENUITEM id="MENU_ID_CLNDR_DELETE_SPEC_PERIOD" str="STR_ID_CLNDR_DELETE_SPEC_PERIOD"/>
    </MENU>

    <MENU id = "MENU_ID_CLNDR_EVENT_FILTER" type = "APP_SUB">
        <MENUITEM id = "MENU_ID_CLNDR_EVENT_ALL" str = "STR_ID_CLNDR_EVENT_SELECT_ALL"/>
        <MENUITEM id = "MENU_ID_CLNDR_EVENT_LOCAL" str = "STR_ID_CLNDR_EVENT_LOCAL"/>
        <MENUITEM id = "MENU_ID_CLNDR_EVENT_FACEBOOK" str = "STR_ID_CLNDR_EVENT_FACEBOOK"/>
        <MENUITEM id = "MENU_ID_CLNDR_EVENT_KAIXIN" str = "STR_ID_CLNDR_EVENT_KAIXIN"/>
        <MENUITEM id = "MENU_ID_CLNDR_EVENT_RENREN" str = "STR_ID_CLNDR_EVENT_RENREN"/>
    </MENU>
#endif /*EVENT*/

#ifdef __MMI_BTD_BOX_UI_STYLE__
    <MENU id="MENU_ID_CLNDR_GOTO_TODAY_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_ID_CLNDR_GOTO_TODAY_OPTION_EDIT" str="STR_GLOBAL_EDIT"/>
        <MENUITEM id="MENU_ID_CLNDR_GOTO_TODAY_OPTION_GOTO" str="STR_GLOBAL_GO_TO"/>
    </MENU>
#endif /* __MMI_BTD_BOX_UI_STYLE__ */
	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
    <!--MMI Cache Area-->
    <!--MMI Cache Area-->
#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)    
    <CACHEDATA type="byte" id="LUNAR_CALENDAR" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif
#ifdef	__MMI_CALENDAR_FDOW__
	<CACHEDATA type="byte" id="NVRAM_CLNDR_FIRST_DAY_OF_WEEK" restore_flag="TRUE">
		<DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
		<DESCRIPTION> first day of week, 0x00: Sunday; 0x01: Monday </DESCRIPTION>
	</CACHEDATA>
#endif

#if defined(__MMI_INDICAL__) || defined(__MMI_HIJRI_CALENDAR__)
    <CACHEDATA type="byte" id="NVRAM_CLNDR_INFO_VAL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif

#ifdef __MMI_CALENDAR_EVENT__
	<RECEIVER id="EVT_ID_SRV_TDL_EVENT_SEARCH" proc="mmi_clndr_search_callback_handler"/>
	<RECEIVER id="EVT_ID_SRV_TDL_EVENT_OP" proc="mmi_clndr_event_op_proc"/>	
#endif
    <!--MMI Cache Area-->
    <!--MMI Cache Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    
#endif /* __MMI_CALENDAR__ */ 
       
</APP>

