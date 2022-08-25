#include "MMI_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_LUNAR_QUERY">

    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <INCLUDE file = "OrganizerResDef.h"/>
    
#ifdef __MMI_LUNAR_QUERY__   
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->

    <STRING id="STR_LUNAR_QUERY_MENU_STR"/>   
    <STRING id="STR_LUNAR_CHINESE_NO1"/>
    <STRING id="STR_LUNAR_CHINESE_NO2"/>
    <STRING id="STR_LUNAR_CHINESE_NO3"/>
    <STRING id="STR_LUNAR_CHINESE_NO4"/>
    <STRING id="STR_LUNAR_CHINESE_NO5"/>
    <STRING id="STR_LUNAR_CHINESE_NO6"/>
    <STRING id="STR_LUNAR_CHINESE_NO7"/>
    <STRING id="STR_LUNAR_CHINESE_NO8"/>
    <STRING id="STR_LUNAR_CHINESE_NO9"/>
    <STRING id="STR_LUNAR_CHINESE_NO10"/>
    <STRING id="STR_LUNAR_CHINESE_NO20"/>
    <STRING id="STR_LUNAR_CHINESE_NO30"/>

    <STRING id="STR_LUNAR_SOLARTERM1"/>
    <STRING id="STR_LUNAR_SOLARTERM2"/>
    <STRING id="STR_LUNAR_SOLARTERM3"/>
    <STRING id="STR_LUNAR_SOLARTERM4"/>
    <STRING id="STR_LUNAR_SOLARTERM5"/>
    <STRING id="STR_LUNAR_SOLARTERM6"/>
    <STRING id="STR_LUNAR_SOLARTERM7"/>
    <STRING id="STR_LUNAR_SOLARTERM8"/>
    <STRING id="STR_LUNAR_SOLARTERM9"/>
    <STRING id="STR_LUNAR_SOLARTERM10"/>
    <STRING id="STR_LUNAR_SOLARTERM11"/>
    <STRING id="STR_LUNAR_SOLARTERM12"/>
    <STRING id="STR_LUNAR_SOLARTERM13"/>
    <STRING id="STR_LUNAR_SOLARTERM14"/>
    <STRING id="STR_LUNAR_SOLARTERM15"/>
    <STRING id="STR_LUNAR_SOLARTERM16"/>
    <STRING id="STR_LUNAR_SOLARTERM17"/>
    <STRING id="STR_LUNAR_SOLARTERM18"/>
    <STRING id="STR_LUNAR_SOLARTERM19"/>
    <STRING id="STR_LUNAR_SOLARTERM20"/>
    <STRING id="STR_LUNAR_SOLARTERM21"/>
    <STRING id="STR_LUNAR_SOLARTERM22"/>
    <STRING id="STR_LUNAR_SOLARTERM23"/>
    <STRING id="STR_LUNAR_SOLARTERM24"/>

    <STRING id="STR_LUNAR_KAN1"/>
    <STRING id="STR_LUNAR_KAN2"/>
    <STRING id="STR_LUNAR_KAN3"/>
    <STRING id="STR_LUNAR_KAN4"/>
    <STRING id="STR_LUNAR_KAN5"/>
    <STRING id="STR_LUNAR_KAN6"/>
    <STRING id="STR_LUNAR_KAN7"/>
    <STRING id="STR_LUNAR_KAN8"/>
    <STRING id="STR_LUNAR_KAN9"/>
    <STRING id="STR_LUNAR_KAN10"/>
    <STRING id="STR_LUNAR_CHI1"/>
    <STRING id="STR_LUNAR_CHI2"/>
    <STRING id="STR_LUNAR_CHI3"/>
    <STRING id="STR_LUNAR_CHI4"/>
    <STRING id="STR_LUNAR_CHI5"/>
    <STRING id="STR_LUNAR_CHI6"/>
    <STRING id="STR_LUNAR_CHI7"/>
    <STRING id="STR_LUNAR_CHI8"/>
    <STRING id="STR_LUNAR_CHI9"/>
    <STRING id="STR_LUNAR_CHI10"/>
    <STRING id="STR_LUNAR_CHI11"/>
    <STRING id="STR_LUNAR_CHI12"/>
    
    <STRING id="STR_LUNAR_CHINESE_YEAR"/>
    <STRING id="STR_LUNAR_CHINESE_MONTH"/>
    <STRING id="STR_LUNAR_CHINESE_DAY"/>
    <STRING id="STR_LUNAR_LEAP_MONTH"/>
    <STRING id="STR_LUNAR_CHINESE_ZHENG_YUE"/>
    <STRING id="STR_LUNAR_CHINESE_LA_YUE"/>
    <STRING id="STR_LUNAR_CHINESE_CHU"/>
     
    <STRING id="STR_LUNAR_LUNAR_QUERY"/>
    <STRING id="STR_LUNAR_FESTIVAL_QUERY"/>
    <STRING id="STR_LUNAR_SOLAR_TERMS_QUERY"/>

   <!--Begin Festival String Area -->
   // new added festical must aftet "STR_LUNAR_NEW_YEARS_DAY" and change 
   // "SOLAR_FESTIVAL_TOTAL" in LunarQuery.h
    <STRING id="STR_LUNAR_NEW_YEARS_DAY"/>  
    <STRING id="STR_LUNAR_SPRING_FESTIVAL"/>
    <STRING id="STR_LUNAR_LANTERN_FESTIVAL"/>
    <STRING id="STR_LUNAR_INTERNATION_WOMEN_DAY"/>
    <STRING id="STR_LUNAR_INTERNATION_LABOUR_DAY"/>
    <STRING id="STR_LUNAR_DRAGON_BOAT_FESTIVAL"/>
    <STRING id="STR_LUNAR_INTERNATION_CHILDRENS_DAY"/>
    <STRING id="STR_LUNAR_DOUBLE_SEVENTH_DAY"/>
    <STRING id="STR_LUNAR_MID_AUTUMN_FESTIVAL"/>
    <STRING id="STR_LUNAR_DOUBLE_NINTH_DAY"/>
    <STRING id="STR_LUNAR_NATIONAL_DAY"/> 
    <!--End Festival String Area-->
    
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	
	<IMAGE id="ORGANIZER_MENU_LUNAR_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\SB_OCDAR.bmp"</IMAGE>
	
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->

    <SCREEN id = "SCR_ID_LUNAR_MAIN_SCREEN"/>
    <SCREEN id = "SCR_ID_LUNAR_JUMP_DATE"/>
    <SCREEN id = "SCR_ID_LUNAR_SELECT_YEAR"/>
    <SCREEN id = "SCR_ID_LUNAR_SOLAR_TERMS"/>
    <SCREEN id = "SCR_ID_LUNAR_FESTIVALS"/>
    <SCREEN id = "SCR_ID_LUNAR_QUERY_INFO"/>
    <SCREEN id = "SCR_ID_LUNAR_END_OF_ENUM"/>
    
	<!--Screen Group Id-->
    <SCREEN id = "GRP_ID_LUNAR_MAIN"/>
    <SCREEN id = "GRP_ID_LUNAR_JUMP_DATE"/>
    <SCREEN id = "GRP_ID_LUNAR_SELECT_YEAR"/>
    <SCREEN id = "GRP_ID_LUNAR_END"/> 

	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
    
	<MENU id="ORGANIZER_LUNAR_QUERY_MENU" str="STR_LUNAR_QUERY_MENU_STR" img="ORGANIZER_MENU_LUNAR_IMAGEID" highlight="HighlightLunarQueryMenu" 
	            shortcut="ON" shortcut_img="ORGANIZER_MENU_LUNAR_IMAGEID" launch="EntryLunarQueryMenu">
    </MENU>

    <MENUITEM id="MENU_ID_LUNAR_JUMP_TO_DATE" str="STR_LUNAR_LUNAR_QUERY"/>
    <MENUITEM id="MENU_ID_LUNAR_SOLARTERM_QUERY" str="STR_LUNAR_SOLAR_TERMS_QUERY"/>
    <MENUITEM id="MENU_ID_LUNAR_FESTIVAL_QUERY" str="STR_LUNAR_FESTIVAL_QUERY"/>

	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->
 
#endif /* __MMI_LUNAR_QUERY__ */ 
       
</APP>

