/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SEARCH_WEB"
#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_SEARCH_WEB_BAIDU__)
     package_name = "native.mtk.baidu"
     name = "STR_ID_SEARCH_WEB_BAIDU_ENTRY"
 #if defined(__MMI_VUI_LAUNCHER__)||defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON
     img = "IMG_ID_SEARCH_WEB_BAIDU_MAIN_MENU_ICON"
  #endif
     launch = "mmi_search_web_baidu_launch_from_mainmenu"
#endif /* defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_SEARCH_WEB_BAIDU__) */
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="mmi_rp_srv_editor_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __MMI_SEARCH_WEB_BAIDU__
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_ENTRY"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_DEFAULT_CATEGORY"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_INTERNET"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_FORUM"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_KNOWLEDGE"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_SPACE"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_WEATHER"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_MAP"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_DICTIONARY"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_WEB_HELP"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_HELP_TEXT_USAGE"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_HELP_TEXT_CHARGE"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_HELP_TEXT_FEEDBACK"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_SEARCH_APP_NAME"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_PLEASE_DISABLE_HOT_KEY_FIRST"/>
#endif

#ifdef __MMI_SEARCH_WEB_GOOGLE__
    <STRING id="STR_ID_SEARCH_WEB_GOOGLE_APP_NAME"/>
    <STRING id="STR_ID_SEARCH_WEB_GOOGLE_IDLE_HINT_TEXT"/>
    <STRING id="STR_ID_SEARCH_WEB_GOOGLE_HINT_SETTING"/>
    <STRING id="STR_ID_SEARCH_WEB_GOOGLE_PLUS_LSK"/>
#endif

#ifdef __MMI_SEARCH_WEB__
    <STRING id="STR_ID_SEARCH_WEB_REQUEST_SEARCH"/>
#endif

#ifdef __MMI_SEARCH_WEB_BAIDU__
    <STRING id="STR_ID_SEARCH_WEB_NEWS"/>
    <STRING id="STR_ID_SEARCH_WEB_IMAGE"/>
    <STRING id="STR_ID_SEARCH_WEB_HISTORY"/>
    <STRING id="STR_ID_SEARCH_WEB_CLEAR_HISTORY"/>
    <STRING id="STR_ID_SEARCH_WEB_HOT_KEY"/>
    <STRING id="STR_ID_SEARCH_WEB_DOWN_KEY"/>
    <STRING id="STR_ID_SEARCH_WEB_LONG_PRESS_STAR"/>
    <STRING id="STR_ID_SEARCH_WEB_DISABLE"/>
    <STRING id="STR_ID_SEARCH_WEB_MORE"/>
    <STRING id="STR_ID_SEARCH_WEB_OTHERS"/>
    <STRING id="STR_ID_SEARCH_WEB_VERSION"/>
    <STRING id="STR_ID_SEARCH_WEB_BAIDU_IDLE_HINT_TEXT"/>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __MMI_SEARCH_WEB__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <IMAGE id="IMG_ID_SEARCH_WEB_SEARCH_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\search_button.png"</IMAGE>
    <IMAGE id="IMG_ID_SEARCH_WEB_SEARCH_BUTTON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\search_button_pressed.png"</IMAGE>
#endif
#endif

#ifdef __MMI_SEARCH_WEB_BAIDU__
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\SB_baidu.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_INTERNET">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\baidu_logo_internet.png"</IMAGE>
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\baidu_logo_image.png"</IMAGE>
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_NEWS">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\baidu_logo_news.png"</IMAGE>
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_FORUM">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\baidu_logo_forum.png"</IMAGE>
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_KNOWLEDGE">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\baidu_logo_knowledge.png"</IMAGE>
#ifdef __MMI_VUI_LAUNCHER_KEY__ 
		<IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_IDLE_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\baidu.jpg"</IMAGE>
#else
	<IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_IDLE_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\SearchWeb\\\\SB_baidu.bmp"</IMAGE>
#endif    
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__)||defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    <IMAGE id="IMG_ID_SEARCH_WEB_BAIDU_MAIN_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Baidu.png"</IMAGE>
#endif //MM_ICON
#endif /* defined(__MMI_APP_MANAGER_SUPPORT__) */
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#ifdef __MMI_SEARCH_WEB_BAIDU__
	<MENU id="MENU_ID_SEARCH_WEB_BAIDU_ENTRY" str="STR_ID_SEARCH_WEB_BAIDU_ENTRY" img="IMG_ID_SEARCH_WEB_BAIDU_MENU_ICON" highlight="mmi_search_web_baidu_entry_highlight_hdlr"></MENU>
#endif

#ifdef __MMI_SEARCH_WEB_GOOGLE__
    <MENU id="MENU_ID_SEARCH_WEB_GOOGLE_HINT_SETTING" type="APP_SUB" str="STR_ID_SEARCH_WEB_GOOGLE_HINT_SETTING">
        <MENUITEM_ID>MENU_ID_SEARCH_WEB_GOOGLE_HINT_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SEARCH_WEB_GOOGLE_HINT_ON</MENUITEM_ID>
    </MENU>
    
    <MENUITEM id="MENU_ID_SEARCH_WEB_GOOGLE_HINT_OFF" str="STR_GLOBAL_OFF"/>
    <MENUITEM id="MENU_ID_SEARCH_WEB_GOOGLE_HINT_ON" str="STR_GLOBAL_ON"/>
    
    <MENU id="MENU_ID_SEARCH_WEB_GOOGLE_OPTIONS" type="APP_MAIN" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SEARCH_WEB_GOOGLE_SEARCH</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>
    
    <MENUITEM id="MENU_ID_SEARCH_WEB_GOOGLE_SEARCH" str="STR_ID_SEARCH_WEB_REQUEST_SEARCH"/>
#endif

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_SEARCH_WEB_DUMMY"/>
    
#ifdef __MMI_SEARCH_WEB_BAIDU__
    <SCREEN id="GRP_ID_SEARCH_WEB_BAIDU"/>
    <SCREEN id="SCR_ID_SEARCH_WEB_BAIDU_SEARCH_BAR"/>
    <SCREEN id="SCR_ID_SEARCH_WEB_BAIDU_HISTORY_LIST"/>
    <SCREEN id="SCR_ID_SEARCH_WEB_BAIDU_HELP"/>
#endif
#ifdef __MMI_SEARCH_WEB_GOOGLE__
    <SCREEN id="GRP_ID_SEARCH_WEB_GOOGLE"/>
    <SCREEN id="SCR_ID_SEARCH_WEB_GOOGLE_SEARCH_BAR"/>
#endif

#ifdef __MMI_SEARCH_WEB_BAIDU__
    <CACHEDATA type="short" id="NVRAM_SEARCH_WEB_BAIDU_HOT_KEY_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Baidu Search - Hot key </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SEARCH_WEB_BAIDU_DEFAULT_CATEGORY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Baidu Search - Default category </DESCRIPTION>
    </CACHEDATA>
#endif

#ifdef __MMI_SEARCH_WEB_GOOGLE__
    <CACHEDATA type="byte" id="NVRAM_SEARCH_WEB_GOOGLE_HINT_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Google Search - Hint setting </DESCRIPTION>
    </CACHEDATA>
#endif

</APP>

