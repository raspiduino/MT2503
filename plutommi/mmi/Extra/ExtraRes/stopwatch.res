/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#if (defined(__MMI_STOPWATCH__) && !defined(__COSMOS_MMI_PACKAGE__))

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_STOPWATCH">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_STOPWATCH_TITLE"/>
	<STRING id="STR_TYPICAL_STOPWATCH"/>
	<STRING id="STR_MULTIPURPOSE_STOPWATCH"/>

	<STRING id="STR_SPLIT_TIMING"/>
	<STRING id="STR_LAP_TIMING"/>
	<STRING id="STR_VIEW_RECORD"/>

	<STRING id="STR_OPTION_CON"/>
	<STRING id="STR_STOPWATCH_SPLIT"/>
	<STRING id="STR_STOPWATCH_LAP"/>
	<STRING id="STR_STOPWATCH_MEMORY_FULL"/>
	<STRING id="STR_STOPWATCH_NOT_SAVED"/>
	<STRING id="STR_STOPWATCH_REPLACE_RECORD"/>
	<STRING id="STR_CONFIRM_DELETE_ALL_RECORD"/>
	<STRING id="STR_CONFIRM_DELETE_RECORD"/>
	<STRING id="STR_EMPTY_NAME"/>
	<STRING id="STR_MUTIPURPOSE_TITLE_MSG"/>
	<STRING id="STR_MUTIPURPOSE_TITLE_SIDE_MSG"/>

	<STRING id="STR_DISCONTINUE_TIMER_QUERY"/>
    <STRING id="STR_STOPWATCH_SAVE_STOPWATCH"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Example: How to use compile option in path, __MMI_RES_TYPE_WALLPAPER__ is defined in mmi_features.h */
#ifdef __MMI_MAINLCD_320X480__
    <IMAGE id="IMG_TYPICAL_START_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-start-normal.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_START_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-start-highlight.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_STOP_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-stop-normal.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_STOP_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-stop-highlight.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_CON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-continue-normal.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_CON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-continue-highlight.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_RESET_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-reset-normal.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_RESET_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-reset-highlight.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_NWAY_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-turn-normal.PNG"</IMAGE>
    <IMAGE id="IMG_TYPICAL_NWAY_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\Icon-bar-turn-highlight.PNG"</IMAGE>
#endif

    <IMAGE id="IMG_MULTIPURPOSE_TIMER1">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\LEFT.bmp"</IMAGE>
    <IMAGE id="IMG_MULTIPURPOSE_TIMER2">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\UP.bmp"</IMAGE>
    <IMAGE id="IMG_MULTIPURPOSE_TIMER3">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\RIGHT.bmp"</IMAGE>
    <IMAGE id="IMG_MULTIPURPOSE_TIMER4">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\DOWN.bmp"</IMAGE>
    
#if defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X480__)
    <IMAGE id="IMG_TYPICALSW_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW.png"</IMAGE>
#else
    <IMAGE id="IMG_TYPICALSW_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW.gif"</IMAGE>
#endif

    <IMAGE id="IMG_STOPWATCH_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SB_STWCH.bmp"</IMAGE>
    <IMAGE id="IMG_STOPWATCH_NWAY_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\nway_bg.png"</IMAGE>

#ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_TYPICALSW_FTE_BTN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_COLON">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_colon.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_DOT">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_dot.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_0.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_1.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_2.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_3.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_4.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_5.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_6.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_7.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_8.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\Stopwatch\\\\SW_9.png"</IMAGE>
    
    <IMAGE id="IMG_TYPICALSW_FTE_TB_LAP">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_lap.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_RESET">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_reset.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_SPLIT">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_split.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_START">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_start.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_STOP">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_stop.png"</IMAGE>

    <IMAGE id="IMG_TYPICALSW_FTE_TB_LAP_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_lap_dis.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_RESET_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_reset_dis.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_SPLIT_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_split_dis.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_START_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_start_dis.png"</IMAGE>
    <IMAGE id="IMG_TYPICALSW_FTE_TB_STOP_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Stopwatch\\\\TB_timer_stop_dis.png"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* typical */
#ifndef __MMI_FTE_SUPPORT__
    <MENUITEM id="MENU_SPLIT_TIMING" str="STR_SPLIT_TIMING" img="IMG_GLOBAL_L1"/>
    <MENUITEM id="MENU_LAP_TIMING" str="STR_LAP_TIMING" img="IMG_GLOBAL_L2"/>
    <MENUITEM id="MENU_VIEW_RECORD" str="STR_VIEW_RECORD" img="IMG_GLOBAL_L3"/>
    <MENU id="MENU_TYPICALSTOPWATCH" str="STR_TYPICAL_STOPWATCH" type="APP_SUB">
        <MENUITEM_ID>MENU_SPLIT_TIMING</MENUITEM_ID>
        <MENUITEM_ID>MENU_LAP_TIMING</MENUITEM_ID>
        <MENUITEM_ID>MENU_VIEW_RECORD</MENUITEM_ID>
    </MENU>
#endif

    /* main menu */
#ifdef __MMI_FTE_SUPPORT__
    <MENU id="MENU_STOPWATCH" str="STR_STOPWATCH_TITLE" type="APP_MAIN" img="IMG_STOPWATCH_ICON" highlight="HighlightStopwatch"/>
#else
    <MENUITEM id="MENU_TYPICALSTOPWATCH_ITEM" str="STR_TYPICAL_STOPWATCH" img="IMG_GLOBAL_L1"/>
    <MENUITEM id="MENU_MULTIPURPOSEWATCH" str="STR_MULTIPURPOSE_STOPWATCH" img="IMG_GLOBAL_L2"/>
    <MENU id="MENU_STOPWATCH" str="STR_STOPWATCH_TITLE" type="APP_MAIN" highlight="HighlightStopwatch" img="IMG_STOPWATCH_ICON">
        <MENUITEM_ID>MENU_TYPICALSTOPWATCH_ITEM</MENUITEM_ID>
        <MENUITEM_ID>MENU_MULTIPURPOSEWATCH</MENUITEM_ID>
    </MENU>
#endif

    /* stop option */
#ifdef __MMI_FTE_SUPPORT__
    <MENUITEM id="MENU_STOPWATCH_SAVE_RECORD_OPTION" str="STR_GLOBAL_SAVE"/>
    <MENUITEM id="MENU_SPLIT_TIMING" str="STR_SPLIT_TIMING"/>
    <MENUITEM id="MENU_LAP_TIMING" str="STR_LAP_TIMING"/>
    <MENUITEM id="MENU_VIEW_RECORD" str="STR_VIEW_RECORD"/>
    <MENU id="MENU_STOPWATCH_STOP_OPTIONS" str="STR_GLOBAL_OPTIONS" type="OPTION">
        <MENUITEM_ID>MENU_STOPWATCH_SAVE_RECORD_OPTION</MENUITEM_ID>
        <MENUITEM_ID>MENU_SPLIT_TIMING</MENUITEM_ID>
        <MENUITEM_ID>MENU_LAP_TIMING</MENUITEM_ID>
        <MENUITEM_ID>MENU_VIEW_RECORD</MENUITEM_ID>
    </MENU>
#else
    <MENUITEM id="MENU_CONTINUE_OPTION" str="STR_GLOBAL_CONTINUE"/>
    <MENUITEM id="MENU_RESET_OPTION" str="STR_GLOBAL_RESET"/>
    <MENU id="MENU_STOPWATCH_STOP_OPTIONS" str="STR_GLOBAL_OPTIONS" type="OPTION">
        <MENUITEM_ID>MENU_CONTINUE_OPTION</MENUITEM_ID>
        <MENUITEM_ID>MENU_RESET_OPTION</MENUITEM_ID>
    </MENU>
#endif

    /* view record options */
    <MENUITEM id="MENU_OPTION_VR_VIEW" str="STR_GLOBAL_VIEW"/>
    <MENUITEM id="MENU_OPTION_VR_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_OPTION_VR_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL"/>
    <MENU id="MENU_VIEW_RECORD_OPTIONS" str="STR_VIEW_RECORD" type="OPTION">
        <MENUITEM_ID>MENU_OPTION_VR_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_OPTION_VR_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_OPTION_VR_DELETE_ALL</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_STOPWATCH"/>
    <SCREEN id="SCR_TYPICAL_STOPWATCH"/>
    <SCREEN id="SCR_MULTIPURPOSE_STOPWATCH"/>
    <SCREEN id="SCR_STOP_OPTIONS"/>
    <SCREEN id="SCR_SPLIT_TIMING"/>
    <SCREEN id="SCR_VIEW_RECORD"/>
    <SCREEN id="SCR_ENTER_RECORD_NAME"/>
    <SCREEN id="SCR_SAVE_OPTIONS"/>
    <SCREEN id="SCR_VIEW_RECORD_OPTIONS"/>
    <SCREEN id="SCR_VIEW_SAVED_RECORD"/>
    <SCREEN id="SCR_REPLACE_RECORD"/>
    <SCREEN id="GRP_ID_STOPWATCH"/>
    
    <!----------------------------- NVRAM ----------------------------->
    <CACHEDATA type="byte" id="NVRAM_STOPWATCH_TOTAL_RECORDS">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    <!----------------------------- NVRAM ----------------------------->
    
</APP>
#endif /* __MMI_STOPWATCH__ */
