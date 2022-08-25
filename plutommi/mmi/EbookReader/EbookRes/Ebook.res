/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef __MMI_EBOOK_READER__

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
#ifdef __COSMOS_MMI_PACKAGE__
<APP id="APP_EBOOK" 
    package_name="native.mtk.ebook"
    name="MAIN_MENU_EBOOK_TEXT"
//#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON      
    img="MAIN_MENU_EBOOK_ICON"
//#endif    
    launch="mmi_ebr_pre_entry_book_shel_screen"
    type="venus"
>
<MEMORY heap = "500*1024" />
#else
<APP id="APP_EBOOK" 
#ifdef __MMI_APP_MANAGER_SUPPORT__
    package_name="native.mtk.ebook"
    name="MAIN_MENU_EBOOK_TEXT"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON      
    img="MAIN_MENU_EBOOK_ICON"
#endif    
    launch="mmi_ebr_pre_entry_book_shel_screen"
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
#endif
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,FileMgrResDef.h"/>

    <TIMER id="EBOOK_RECURSIVE_TIMER"/>
    <TIMER id="EBR_SEARCH_BLOCK_TIMER"/>
    <TIMER id="EBOOK_RESTORE_DEFAULT_SETTING_TIMER"/>
    <TIMER id="EBOOK_REFRESH_BOOK_SHELF_TIMER"/>
    <TIMER id="EBOOK_FTE_REFRESH_OPEN_BOOK_TIMER"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __COSMOS_MMI_PACKAGE__
    <STRING id="STR_BOLLON_NOT_AVALIABLE"/>
#endif
    <STRING id="STR_SETTINGS_SELECT_MEMORY"/>
    <STRING id="EBOOK_TITLE_BOOKSHELF"/>
    <STRING id="STR_REFRESH_EBOOK"/>
    <STRING id="STR_OPEN_EBOOK"/>
    <STRING id="STR_INFO_EBOOK"/>
    <STRING id="STR_SETTINGS_EBOOK"/>
    <STRING id="STR_FIND_EBOOK"/>
    <STRING id="STR_FIND_NEXT_EBOOK"/>
    <STRING id="STR_SRCH_CASE_EBOOK"/>
    <STRING id="STR_SRCH_CASEIN_EBOOK"/>   
    <STRING id="STR_JUMP_EBOOK"/>
    <STRING id="STR_GOTO_BOOKMARK_EBOOK"/>
    <STRING id="STR_ADD_BOOKMARK_EBOOK"/>
    <STRING id="STR_RMV_BOOKMARK_EBOOK"/>
    <STRING id="STR_SETTINGS_FONT_SIZE"/>
    <STRING id="STR_SETTINGS_SCROLL_BY"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL_SPEED"/>
    <STRING id="STR_SETTINGS_FULL_SCREEN"/>
    <STRING id="STR_SETTINGS_FONT_SIZE_LARGE"/>
    <STRING id="STR_SETTINGS_FONT_SIZE_SMALL"/>
    <STRING id="STR_SETTINGS_SCROLL_BY_PAGE"/>
    <STRING id="STR_SETTINGS_SCROLL_BY_LINE"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL_SPEED_1"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL_SPEED_2"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL_SPEED_3"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL_SPEED_4"/>
    <STRING id="STR_SETTINGS_AUTO_SCROLL_SPEED_5"/>
    <STRING id="STR_SETTINGS_LEFT_ALIGNMENT"/>
    <STRING id="STR_SETTINGS_RIGHT_ALIGNMENT"/>
    <STRING id="STR_SETTINGS_ALIGNMENT_STYLE"/>
    <STRING id="STR_EBOOK_BOOKMARK_ADDED"/>
    <STRING id="STR_EBOOK_BOOKMARK_ADD_FAIL"/>
    <STRING id="STR_EBOOK_DEFAULT_BOOKMARK"/>
    <STRING id="STR_EBOOK_BOOKMARK_DELETED"/>
    <STRING id="STR_MAX_BOOK_MARK"/>
    <STRING id="STR_EBOOK_TOUCH_SCREEN_HELP"/>
    <STRING id="STR_EBOOK_TOUCH_SCREEN_HELP_NO_FIND"/>
    <STRING id="STR_DELETE_EBOOK_CONFIRM"/>
    <STRING id="STR_DELETE_BOOK_MARK"/>
    <STRING id="STR_BOOK_SHELF_REFRESHED"/>
    <STRING id="STR_BOOK_SHELF_REFRESH_FAILED"/>
    <STRING id="STR_DUPLICATE_BOOK_MARK"/>
    <STRING id="STR_FULL_SCREEN_OFF"/>
    <STRING id="STR_FULL_SCREEN_ON"/>
    <STRING id="STR_AUTO_SCROLL_ON"/>
    <STRING id="STR_AUTO_SCROLL_OFF"/>
    <STRING id="STR_ERROR_OPENINIG_BOOK"/>
    <STRING id="STR_EBOOK_SEARCH_UN_SUCESSFULL"/>
    <STRING id="STR_RESTORE_DEFAULT"/>
    <STRING id="STR_SUCESSFULL_RESTORE_DEFAULT"/>
    <STRING id="STR_UNSUCESSFULL_RESTORE_DEFAULT"/>
    <STRING id="STR_RESTORE_DEFAULT_SETTINGS"/>
    <STRING id="STR_EBOOK_WAIT"/>
    <STRING id="STR_NO_BOOK_MARK_PRESENT"/>
    <STRING id="STR_CONFIRM_SAVE_SETTINGS"/>
    <STRING id="STR_BOOK_MARK_NAME_IS_EMPTY"/>
    <STRING id="STR_INCOMPLETE_SEARCH_STRING"/>
    <STRING id="STR_EBOOK_BOOK_INFO_TITLE"/>
    <STRING id="STR_EBOOK_BOOK_INFO_SIZE"/>
    <STRING id="STR_EBOOK_BOOK_INFO_FORMAT"/>
    <STRING id="STR_EBOOK_SEARCH_INVALID"/>
    <STRING id="STR_EBOOK_DELETE_INQUIRE"/>
    <STRING id="STR_EBOOK_QUESTION_SIGN"/>
    <STRING id="STR_EBOOK_FUNCTION_NOT_AVAILABLE_IN_CALL"/>
    <STRING id="STR_STOP_CONVERTING"/>
    <STRING id="STR_EBOOK_JUMP_ERROR"/>
    <STRING id="STR_EBOOK_FS_OP_ERROR"/>
    <STRING id="STR_EBOOK_FUNCTION_NOT_ALLOWED"/>
    <STRING id="STR_EBOOK_OPEN_THE_CONVERTING_EBOOK"/>
    <STRING id="STR_EBOOK_SUCCESS"/>
    <STRING id="STR_EBOOK_IS_STOPING_CONVERTING"/>
    <STRING id="STR_EBOOK_TOTAL_LINE_NUMS"/>
    <STRING id="STR_EBOOK_CONVERTING_COMPLETED"/>
    <STRING id="STR_EBOOK_FUNCTION_NOT_ALLOWED_IN_BLUETOOTH_PRINT"/>
    <STRING id="STR_EBOOK_EXIT_EBOOK_READER"/>
    <STRING id="STR_EBOOK_TOGGLE_FAILED"/>
    <STRING id="STR_EBOOK_DELETE_BOOKMARK_FAILED"/>
    <STRING id="STR_EBOOK_SAVE_SETTINGS_FAILED"/>
    <STRING id="STR_EBOOK_CONVERTING_BOOK_MEMORY_NOT_DEFAULT_STORAGE"/>
    <STRING id="STR_EBOOK_CANCELLED"/>
    <STRING id="STR_EBOOK_GOTO_BOOKMARK_FAILED"/>
    <STRING id="MAIN_MENU_EBOOK_TEXT"/>
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <STRING id="STR_ID_EBOOK_FTE_BOOKMARK_LIST"/>
    <STRING id="STR_ID_EBOOK_FTE_ENTRY_BOOKMARK_LIST_FAILED"/>
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    <EVENT id="EVT_ID_EBOOK_ASYNC_OPEN_SUCCESS_RSP" type="SENDER"/>
    <EVENT id="EVT_ID_EBOOK_ASYNC_OPEN_FAIL_RSP" type="SENDER"/>

    <RECEIVER id="EVT_ID_EBOOK_ASYNC_OPEN_SUCCESS_RSP" proc="mmi_ebr_app_entry_open_book"/>
    <RECEIVER id="EVT_ID_EBOOK_ASYNC_OPEN_FAIL_RSP" proc="mmi_ebr_app_entry_open_book"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __COSMOS_MMI_PACKAGE__

   // <IMAGE id="MAIN_MENU_EBOOK_ICON" >RES_IMG_ROOT"\\\\Ebook\\\\Ebook.png"</IMAGE>   
     <IMAGE id="MAIN_MENU_EBOOK_ICON" desc="Main menu ebook icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Ebook.png"</IMAGE>
    <IMAGE id="IMG_EBOOK_FMGR_TXT_LARGE_TYPE_NEW" >RES_IMG_ROOT"\\\\Ebook\\\\Type.png"</IMAGE>
    <IMAGE id="IMG_EBOOK_FMGR_TXT_SMALL_TYPE_NEW" >RES_IMG_ROOT"\\\\Ebook\\\\Type.png"</IMAGE>
    <IMAGE id="IMAGE_EBOOK_FTE_AUTO_SCROLL" >RES_IMG_ROOT"\\\\Ebook\\\\Auto_scrol.png"</IMAGE>
    <IMAGE id="IMAGE_EBOOK_FTE_FULL_SCREEN" >RES_IMG_ROOT"\\\\Ebook\\\\Full_screen.png"</IMAGE>
    <IMAGE id="IMAGE_EBOOK_FTE_NORMAL_SCREEN" >RES_IMG_ROOT"\\\\Ebook\\\\Normal_screen.png"</IMAGE>
    <IMAGE id="IMAGE_EBOOK_BOOKMARK_LIST" >RES_IMG_ROOT"\\\\Ebook\\\\Bookmark_list.png"</IMAGE>


#else
#if defined(__MMI_APP_MANAGER_SUPPORT__)
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__)  //MM_ICON  
    <IMAGE id = "MAIN_MENU_EBOOK_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Ebook.png"</IMAGE>
#else
    <IMAGE id="MAIN_MENU_EBOOK_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Ebook\\\\EbookAppIcon.bmp"</IMAGE>
#endif
#else    
    <IMAGE id="MAIN_MENU_EBOOK_ICON" >CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Ebook\\\\EbookAppIcon.bmp"</IMAGE>
#endif    
    <IMAGE id="IMG_EBOOK_FMGR_TXT_LARGE_TYPE_NEW" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\EBOOK_TXT.gif"</IMAGE>
    <IMAGE id="IMG_EBOOK_FMGR_TXT_SMALL_TYPE_NEW" >CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\EBOOK_SMALL_TXT.bmp"</IMAGE>
 #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <IMAGE id="IMAGE_EBOOK_FTE_AUTO_SCROLL" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Ebook\\\\TB_auto_scroll.png"</IMAGE>
    <IMAGE id="IMAGE_EBOOK_FTE_FULL_SCREEN" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Ebook\\\\TB_fullscreen.png"</IMAGE>
    <IMAGE id="IMAGE_EBOOK_FTE_NORMAL_SCREEN" >CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Ebook\\\\TB_normalscreen.png"</IMAGE>
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */ 
#endif
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->
    <MENUITEM id="MENU_ID_EBK_OPEN_EBOOK_STOP_CONVERTING" str="STR_STOP_CONVERTING"/>
    <MENUITEM id="MENU_ID_EBK_FIND_NEXT" str="STR_FIND_NEXT_EBOOK"/>
    <MENUITEM id="MENU_ID_EBK_CASE_SENSITIVE" str="STR_SRCH_CASE_EBOOK"/>
    <MENUITEM id="MENU_ID_EBK_CASE_INSENSITIVE" str="STR_SRCH_CASEIN_EBOOK"/>  
    <MENUITEM id="MENU_ID_EBK_JUMP" str="STR_JUMP_EBOOK"/>
    <MENUITEM id="MENU_ID_EBK_ADD_BOOKMARK" str="STR_ADD_BOOKMARK_EBOOK"/>
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <MENUITEM id="MENU_ID_EBK_FTE_BOOKMARK_LIST" str="STR_ID_EBOOK_FTE_BOOKMARK_LIST"/>
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    <MENUITEM id="MENU_ID_EBK_GOTO_BOOKMARK" str="STR_GOTO_BOOKMARK_EBOOK"/>        
    <MENUITEM id="MENU_ID_EBK_REMOVE_BOOKMARK" str="STR_RMV_BOOKMARK_EBOOK"/>       
    <MENUITEM id="MENU_ID_EBK_CLOSE" str="STR_GLOBAL_CLOSE"/>   
    <MENUITEM id="MENU_ID_EBK_AUTO_SCROLL_ON" str="STR_AUTO_SCROLL_ON"/>
    <MENUITEM id="MENU_ID_EBK_AUTO_SCROLL_OFF" str="STR_AUTO_SCROLL_OFF"/>   
    <MENUITEM id="MENU_ID_EBK_FULL_SCREEN_ON" str="STR_FULL_SCREEN_ON"/> 
    <MENUITEM id="MENU_ID_EBK_FULL_SCREEN_OFF" str="STR_FULL_SCREEN_OFF"/> 

    <MENUITEM id="MENU_ID_FMGR_EBOOK_OPTION_OPEN_NEW" str="STR_OPEN_EBOOK"/>

    <MENU id="MENU_ID_EBK_OPEN_OPTIONS" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS" >
        <MENUITEM_ID>MENU_ID_EBK_OPEN_EBOOK_STOP_CONVERTING</MENUITEM_ID>
        <MENU id="MENU_ID_EBK_FIND" type="OPTION" str="STR_FIND_EBOOK" >
            <MENUITEM_ID>MENU_ID_EBK_CASE_SENSITIVE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_EBK_CASE_INSENSITIVE</MENUITEM_ID>
        </MENU>
        <MENUITEM_ID>MENU_ID_EBK_FIND_NEXT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_FULL_SCREEN_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_FULL_SCREEN_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_JUMP</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_ADD_BOOKMARK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_FTE_BOOKMARK_LIST</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_GOTO_BOOKMARK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_ADD_BOOKMARK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_REMOVE_BOOKMARK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_AUTO_SCROLL_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_AUTO_SCROLL_OFF</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EBK_CLOSE</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_EBK_BOOKSHELF_OPTION" type="OPTION" str="@OID:MAIN_MENU_EBOOK_TEXT" >
        /* Could write MENUITEM in menu directly */
        <MENUITEM id="MENU_ID_EBK_OPEN" str="STR_OPEN_EBOOK" highlight="mmi_ebr_highlight_open_ebook"/>
        <MENUITEM id="MENU_ID_EBK_SETTINGS" str="STR_SETTINGS_EBOOK" highlight="mmi_ebr_highlight_book_shelf_settings"/>
        <MENUITEM id="MENU_ID_EBK_INFO" str="STR_INFO_EBOOK" highlight="mmi_ebr_higlight_book_info"/>
        <MENUITEM id="MENU_ID_EBK_DELETE" str="STR_GLOBAL_DELETE" highlight="mmi_ebr_highlight_delete_ebook"/>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_SORT</MENUITEM_ID>
        <MENUITEM id="MENU_ID_EBK_BOOKSHELF_HELP" str="STR_GLOBAL_HELP" highlight="mmi_ebr_highlight_help"/>        
    </MENU>
    
    <MENU id="MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION" type="OPTION" str="@OID:MAIN_MENU_EBOOK_TEXT" >
        <MENUITEM_ID>MENU_ID_EBK_SETTINGS</MENUITEM_ID>
    </MENU>
    
    <MENU id="MENU_ID_FMGR_EBOOK_TYPE_OPTIONS_NEW" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS" >
        <MENUITEM_ID>MENU_ID_FMGR_EBOOK_OPTION_OPEN_NEW</MENUITEM_ID>
#ifndef __COSMOS_MMI_PACKAGE__
        <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
#endif
    </MENU>
    
    <MENU id="MAIN_MENU_EBOOK_MENUID" highlight="highlight_mainmenu_ebook" str="MAIN_MENU_EBOOK_TEXT" img="MAIN_MENU_EBOOK_ICON" 
    shortcut="ON" shortcut_img="MAIN_MENU_EBOOK_ICON" launch="mmi_ebr_pre_entry_book_shel_screen">
    </MENU>

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */
    /*
        <MENU id="TEST_APP_OPTION" type="OPTION" str="STR_ID_MM_OPTION">
            <MENUITEM_ID>MENU_ID_TEMPLATE_01</MENUITEM_ID>
            <MENUITEM_ID default="TRUE">MENU_ID_TEMPLATE_02</MENUITEM_ID>
            <MENUITEM_ID type="SEPARATOR"></MENUITEM_ID>
            <MENUITEM_ID type="MENU">MENU_ID_TEMPLATE_SUB_01</MENUITEM_ID>
        </MENU>
    */
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_EBOOK_BOOKSHELF"/>
    <SCREEN id="GRP_ID_EBOOK_OPEN_BOOK"/>

    <SCREEN id="SCR_ID_EBOOK_BOOKSHELF_SCREENID"/>
    <SCREEN id="SCR_ID_EBOOK_OPEN_SCREENID"/>
    <SCREEN id="SCR_ID_EBOOK_INFO_SCREENID"/>
    <SCREEN id="SCR_ID_EBOOK_BOOK_SETTINGS_SCREENID"/>
    <SCREEN id="SCR_ID_EBOOK_REMOVE_BOOKMARK_SCREENID"/>
    <SCREEN id="SCR_ID_EBOOK_GOTO_BOOKMARK_SCREENID"/>
    <SCREEN id="SCR_ID_EBOOK_WAITSCREEN"/>
    <SCREEN id="SCR_ID_EBOOK_LOADINGSCREEN"/>
    <SCREEN id="SCR_ID_EBOOK_HELP_SCREEN"/>
    <SCREEN id="SCR_ID_EBOOK_FTE_BOOKMARK_LIST"/>


    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_ebook_usb_mode_off"/>
	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_ebook_usb_mode_on"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_ebr_app_dev_plug_out_handler"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_ebr_app_format_handler"/>
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_ebr_app_lcd_sleepout_handler"/>
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_ebr_app_lcd_sleepin_handler"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_ebr_app_set_def_storage_handler"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_ebr_app_action_adv_handler"/>

    <FILE_TYPES>
        <FILE_TYPE type_id="FMGR_TYPE_EBOOK_TXT" extension="TXT" small_icon="IMG_EBOOK_FMGR_TXT_SMALL_TYPE_NEW" large_icon="IMG_EBOOK_FMGR_TXT_LARGE_TYPE_NEW" option="MENU_ID_FMGR_EBOOK_TYPE_OPTIONS_NEW"/>
        <FILE_TYPE type_id="FMGR_TYPE_EBOOK_TXZ" extension="TXZ"/>
        <FILE_TYPE type_id="FMGR_TYPE_EBOOK_NF2" extension="NF2"/>
        <FILE_TYPE type_id="FMGR_TYPE_EBOOK_LTS" extension="LTS"/>
        <FILE_TYPE type_id="FMGR_TYPE_EBOOK_LTM" extension="LTM"/>
        <FILE_TYPE type_id="FMGR_TYPE_EBOOK_LTL" extension="LTL"/>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_EBOOK_OPTION_OPEN_NEW" handler="mmi_fmgr_ebook_option_hdlr"/>
    </FILE_TYPES>

</APP>

#endif /* __MMI_EBOOK_READER__ */
