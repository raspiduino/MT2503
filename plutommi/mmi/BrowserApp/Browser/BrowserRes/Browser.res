#include "MMI_features.h"
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */
#ifdef __MMI_BROWSER_2__


/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BROWSER" 
     name = "STR_ID_BRW_BROWSER" type="pluto"                /* The string to be displayed under the main menu icon */
#if defined(__MMI_APP_MANAGER_SUPPORT__)
     package_name = "native.mtk.browser"             /* Use "native.mtk." as the prefix of application name */
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__))
     img = "IMG_ID_BROWSER_ICON"            /* Main menu icon image */                  /* Application will be default shown on the main menu (if not defining this tag).
* If your application is not expected to be displayed on main menu, you have to define this tag.
*/
#endif
     launch = "mmi_browser_app_launch_func"   /* Launch function of application. When tap on the icon in main menu, the function will be invoked.
 * the function prototype should be:
 *
*    typedef MMI_ID (*mmi_app_launch_func) (void* param, U32 param_size);
*
 * Note that the group_id of the application should be returned if launch successfully.
 * If the application could not be launched for some reason, GRP_ID_INVALID should be returned.
 */
#endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
#ifdef __MMI_SUPPORT_ASMV2__
/* the 220000 bytes is for the menu CUI and GDI as browser is the biggest ASM pool owner */
    <MEMORY heap= "BROWSER_POOL_SIZE + 220000" inc="BrowserConfig.h"/> 
#endif

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can file the ID */
    <!--Include Area--> 
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_editor_def.h"/>
    <INCLUDE file = "ServiceDefs.h"/>
    <INCLUDE file = "FileMgrResDef.h"/>
    <INCLUDE file = "mmi_rp_all_defs.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */



    /* String ID's Start */
    <STRING id="STR_ID_BRW_INTERNET_SERVICES"/>
    <STRING id="STR_ID_BRW_HOMEPAGE"/>
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_BRW_BOOKMARKS"/>
    #endif
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_OPEN_FILE"/>
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    <STRING id="STR_ID_BRW_LAST_WEB_ADDR"/>
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    <STRING id="STR_ID_BRW_RECENT_PAGES"/>
	#ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_RECENT_HOSTS"/>
	#endif
#endif
    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    <STRING id="STR_ID_BRW_STORED_PAGES"/>
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
    <STRING id="STR_ID_BRW_BROWSER_OPTIONS"/>
    <STRING id="STR_ID_BRW_PREFERENCES"/>
    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_BRW_SECURITY_SETTINGS"/>
    #endif
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    <STRING id="STR_ID_BRW_RESTORE_BROWSER_SETTINGS"/>
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    <STRING id="STR_ID_BRW_SET_AS_HOMEPAGE"/>
    #endif
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_BRW_ADD_TO_BOOKMARK"/>
    #endif
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
    <STRING id="STR_ID_BRW_SEND_ADDRESS"/>
    #endif
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_BRW_SEND_BOOKMARK"/>
    #endif
    #endif
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_SORT_BY_SITE"/>
    <STRING id="STR_ID_BRW_SORT_BY_LAST_VISITED"/>
    <STRING id="STR_ID_BRW_SORT_BY_MOST_VISITED"/>
    #endif /* OBIGO_Q05A */
    /*<STRING id="STR_ID_BRW_THIS_LINK"/>*/
    <STRING id="STR_ID_BRW_SELECT_MODE"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_PROPERTIES"/>
    #endif /* OBIGO_Q05A */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    <STRING id="STR_ID_BRW_TITLE"/>
#endif
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_RENDERING_MODES"/>
    <STRING id="STR_ID_BRW_STANDARD"/>
    <STRING id="STR_ID_BRW_TEXT_WRAP"/>
    <STRING id="STR_ID_BRW_SCREEN_OPTIMIZED"/>
    <STRING id="STR_ID_BRW_TEXT_ONLY"/>
    <STRING id="STR_ID_BRW_NAVIGATION_MODES"/>
    <STRING id="STR_ID_BRW_FOUR_WAY"/>
    <STRING id="STR_ID_BRW_TWO_WAY"/>
    <STRING id="STR_ID_BRW_SCROLLING"/>
    <STRING id="STR_ID_BRW_SCREEN_SIZE"/>
    <STRING id="STR_ID_BRW_SMALL"/>
    <STRING id="STR_ID_BRW_FULL"/>
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    <STRING id="STR_ID_BRW_LARGE"/>
    #endif
    <STRING id="STR_ID_BRW_ENCODING"/>
    #endif /* OBIGO_Q05A */

    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_BRW_TRUSTED_CERTIFICATES"/>
    #endif
    <STRING id="STR_ID_BRW_SAVE_AS"/>
    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    <STRING id="STR_ID_BRW_STORE_OFFLINE"/>
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_PAGE_OBJECTS"/>
    <STRING id="STR_ID_BRW_THUMBNAIL"/>
    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_BRW_SESSION_INFO"/>
    <STRING id="STR_ID_BRW_CURRENT_CERTIFICATE"/>
    #endif
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_BRW_TIMEOUT"/>
    <STRING id="STR_ID_BRW_SHOW_IMAGES"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_SHOW_VIDEOS"/>
    <STRING id="STR_ID_BRW_PLAY_SOUNDS"/>
    <STRING id="STR_ID_BRW_LOAD_UNKNOWN_MEDIA"/>
    <STRING id="STR_ID_BRW_CSS"/>
    <STRING id="STR_ID_BRW_SCRIPT"/>
    #endif /* OBIGO_Q05A */
#ifndef SLIM_WAP_MMS
    <STRING id="STR_ID_BRW_CACHE"/>
#endif
    <STRING id="STR_ID_BRW_COOKIE"/>

    #ifdef OBIGO_Q05A
    #ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    <STRING id="STR_ID_BRW_SHORTCUTS"/>
    #endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

    #ifdef BRW_SECURITY_WARNINGS_SUPPORT
    <STRING id="STR_ID_BRW_SECURITY_WARNINGS"/>
    #endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

    #ifdef BRW_SEND_DEVICE_ID_SUPPORT
    <STRING id="STR_ID_BRW_SEND_DEVICE_ID"/>
    #endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_BRW_ENABLE"/>
    <STRING id="STR_ID_BRW_DISABLE"/>
    <STRING id="STR_ID_BRW_ALWAYS"/>
    <STRING id="STR_ID_BRW_NEVER"/>
    <STRING id="STR_ID_BRW_INVAL_TIMEOUT"/>
    <STRING id="STR_ID_BRW_NAME"/>
	#ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_CONTENT_SIZE"/>
	#endif
    <STRING id="STR_ID_BRW_BACKWARD"/>
    <STRING id="STR_ID_BRW_FORWARD"/>
#ifndef SLIM_WAP_MMS
    <STRING id="STR_ID_BRW_PAGE_ACTIONS"/>
#endif
    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    <STRING id="STR_ID_BRW_ENTER_NAME"/>
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
    <STRING id="STR_ID_BRW_CLEAR_AUTH_INFO"/>
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    <STRING id="STR_ID_BRW_CREATE_FOLDER"/>
#endif
    #ifdef __MMI_VBOOKMARK__
    #if (defined __MMI_BRW_BKM_FOLDER_SUPPORT__ || defined __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__)
    <STRING id="STR_ID_BRW_COPY_TO"/>
    <STRING id="STR_ID_BRW_MOVE_TO"/>
    #endif
    #endif
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_IMAGES"/>
    <STRING id="STR_ID_BRW_BG_IMAGES"/>
    <STRING id="STR_ID_BRW_SOUNDS"/>
    <STRING id="STR_ID_BRW_OTHERS"/>
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_BRW_INVALID_PARAM"/>
    <STRING id="STR_ID_BRW_ERROR_COMMUNICATION"/>
    <STRING id="STR_ID_BRW_HOST_NOT_FOUND"/>
    <STRING id="STR_ID_BRW_REQUEST_TIMEOUT"/>
    <STRING id="STR_ID_BRW_CONNECTION_FAILED"/>
    <STRING id="STR_ID_BRW_SECURE_CONNECTION_FAILED"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_ERROR_AUTHENTICATION"/>
    <STRING id="STR_ID_BRW_SECURE_CONNECTION_CANCELLED"/>
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_BRW_ERROR_GPRS_UNKNOWN_APN"/>
    <STRING id="STR_ID_BRW_ERROR_GPRS_AUTHENTICATION_FAILURE"/>
    <STRING id="STR_ID_BRW_ERROR_GPRS_UNSUPPORTED"/>
    <STRING id="STR_ID_BRW_ERROR_GPRS_NOT_SUBSCRIBED"/>
    <STRING id="STR_ID_BRW_ERROR_CSD_AUTHENTICATION_FAILURE"/>
    <STRING id="STR_ID_BRW_PAGE_NOT_FOUND"/>
    <STRING id="STR_ID_BRW_PAGE_ALREADY_EXISTS"/>
    <STRING id="STR_ID_BRW_REQUEST_FAILED"/>
    <STRING id="STR_ID_BRW_PAGE_SAVED_PARTIALLY"/>
    <STRING id="STR_ID_BRW_PAGE_LIMIT_EXCEEDED"/>
    <STRING id="STR_ID_BRW_UNSUPPORTED_SCHEME"/>
    <STRING id="STR_ID_BRW_UNSUPPORTED_ENCODING"/>
    <STRING id="STR_ID_BRW_SYNTAX_ERROR"/>
    <STRING id="STR_ID_BRW_UNKNOWN_DOC_TYPE"/>
    <STRING id="STR_ID_BRW_UNSUPPORTED_WBXML"/>
    <STRING id="STR_ID_BRW_DOC_VALIDATION_ERROR"/>
    <STRING id="STR_ID_BRW_PARSER_NOT_INITIALIZED"/>
    <STRING id="STR_ID_BRW_INTERNAL_ERROR"/>
    <STRING id="STR_ID_BRW_RESEND_POST_WARNING"/>
    <STRING id="STR_ID_BRW_CONTENT_TOO_LARGE"/>
    <STRING id="STR_ID_BRW_INVAL_CHANNEL_ID"/>
    <STRING id="STR_ID_BRW_INVAL_REQUEST_ID"/>
    <STRING id="STR_ID_BRW_INVAL_SEQUENCE_NUM"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_SAVE_BOTH"/>
    <STRING id="STR_ID_BRW_SAVE_ONLY_USERNAME"/>
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_BRW_DELETE_ALL_FILES"/>
    <STRING id="STR_ID_BRW_INVALID_TITLE"/>
    <STRING id="STR_ID_BRW_INVALID_BOOKMARK_FILE"/>
    <STRING id="STR_ID_BRW_NOT_ENOUGH_MEMORY"/>
    #endif
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_SAVE_NONE"/>
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    <STRING id="STR_ID_BRW_FONT_SIZE"/>
    #endif
    <STRING id="STR_ID_BRW_UNSUPPORTED_ACTION"/>
    <STRING id="STR_ID_BRW_ERR_WML_ACCESS_VIOLATION"/>
    <STRING id="STR_ID_BRW_ERR_WML_SCRIPT_ACCESS_VIOLATION"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_ERROR_LOW_MEMORY"/>
    <STRING id="STR_ID_BRW_CHARSET_AUTO_SELECT"/>
    #endif /* OBIGO_Q05A */
    <STRING id="STR_ID_BRW_ACCESS_DENIED"/>
    <STRING id="STR_ID_BRW_NOT_FOUND"/>
    <STRING id="STR_ID_BRW_REQUEST_ABORTED"/>
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    <STRING id="STR_ID_BRW_DOWNLOADS"/>
#endif
    <STRING id="STR_ID_BRW_WAP_NOT_READY"/>
    #ifdef __MMI_DA_RESUME__
    <STRING id="STR_ID_BRW_BKGRD_DOWNLOAD_SUSPEND"/>
    #else
#ifndef __MMI_DA_RESUME__
    <STRING id="STR_ID_BRW_BKGRD_DOWNLOAD_CANCEL"/>
#endif
    #endif /* __MMI_DA_RESUME__ */
    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_BRW_EMPTY_TRUSTED_CERT_LIST"/>
    #endif

    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_BRW_ADD_BOOKMARK"/>
    <STRING id="STR_ID_BRW_SAVE_BOOKMARK"/>
#ifndef SLIM_WAP_MMS
    <STRING id="STR_ID_BRW_DELETE_BOOKMARK"/>
#endif
    #endif
#ifndef SLIM_WAP_MMS
    <STRING id="STR_ID_BRW_CLEAR_CACHE"/>
#endif
    <STRING id="STR_ID_BRW_CLEAR_COOKIE"/>
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    <STRING id="STR_ID_BRW_BAIDU_PROXY"/>
    <STRING id="STR_ID_BRW_BAIDU_PROXY_USER_CONFIRM"/>
	<STRING id="STR_ID_BRW_SWITCH_OFF_BAIDU_PROXY_CONFIRM"/>       
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
	#ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_BYTES"/>
	#endif
#if (defined(OBIGO_Q05A) || !defined(SLIM_WAP_MMS))
    <STRING id="STR_ID_BRW_UNKNOWN"/>
#endif
    #ifdef __MMI_VBOOKMARK__
    <STRING id="STR_ID_BRW_AVAILABLE"/>
    <STRING id="STR_ID_BRW_ALLOCATED"/>
    <STRING id="STR_ID_BRW_TOTAL"/>
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    <STRING id="STR_ID_BRW_DIR_PATH_TOO_DEEP"/>
#endif
    #endif
    <STRING id="STR_ID_BRW_LONG_IDLE_TIMEOUT"/>
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_VIDEO_OBJS_EXCEED_MAX_LIMIT"/>
    #endif /* OBIGO_Q05A */
    #ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_BRW_ISSUER"/>
    <STRING id="STR_ID_BRW_VAL_NOT_BEF"/>
    <STRING id="STR_ID_BRW_VAL_NOT_AFT"/>
    <STRING id="STR_ID_BRW_SUBJECT"/>
    <STRING id="STR_ID_BRW_TYPE"/>
    <STRING id="STR_ID_BRW_VERSION"/>
    <STRING id="STR_ID_BRW_SERIAL_NUM"/>
    <STRING id="STR_ID_BRW_SIG_ALG"/>
#ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_KEY_EXCH_ALG"/>
    <STRING id="STR_ID_BRW_BULK_ENCR_ALG"/>
    <STRING id="STR_ID_BRW_HASH_ALG"/>
    <STRING id="STR_ID_BRW_SEC_CONN_TYPE"/>
#endif
    #endif
    <STRING id="STR_ID_BRW_QUESTION_MARK"/>
    <STRING id="STR_ID_BRW_CERTIFICATE_DETAILS"/>
    #ifdef __MMI_URI_AGENT__
    <STRING id="STR_ID_BRW_UHA_CONNECT_TO_BROWSER"/>
    #endif
#ifdef __MMI_BRW_PAGE_SIZE_CHECKING__
    <STRING id="STR_ID_BRW_PAGE_SIZE_CHECKING"/>
#endif
#ifdef __MMI_BRW_LOADING_TIME_CHECKING__
    <STRING id="STR_ID_BRW_LOADING_TIME_CHECKING"/>
#endif
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_FUNCTION_NOT_ALLOWED"/>
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_1"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_2"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_3"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_4"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_5"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_6"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_7"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_8"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_9"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_10"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_11"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_12"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_13"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_14"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_15"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_16"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_17"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_18"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_19"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_20"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_21"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_22"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_23"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_24"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_25"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_26"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_27"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_28"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_29"/>
    <STRING id="STR_ID_BRW_EMBEDDED_LINK_30"/>
    #endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */ 
    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        /* File Upload Feature */
    <STRING id="STR_ID_BRW_SELECT_FILE"/>
    <STRING id="STR_ID_BRW_UPLOADING"/>
    <STRING id="STR_ID_BRW_UPLOAD_COMPLETED"/>
    <STRING id="STR_ID_BRW_FILE_SIZE_TOO_LARGE"/>
    <STRING id="STR_ID_BRW_CANCEL_UPLOADING"/>
        /* File Upload Feature END */
    #endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    #ifdef  __MMI_BRW_POST_SESSION_INFO__
    <STRING id="STR_ID_BRW_POST_SESSION_INFO"/>
    <STRING id="STR_ID_BRW_SESSION_START_TIME"/>
    <STRING id="STR_ID_BRW_SESSION_END_TIME"/>
    <STRING id="STR_ID_TOTAL_DATA_DOWNLOADED"/>
    <STRING id="STR_ID_TOTAL_DATA_UPLOADED"/>
    #endif /* __MMI_BRW_POST_SESSION_INFO__ */
    #ifdef  __MMI_BRW_PAGE_FETCHING_STATUS__
    <STRING id="STR_ID_BRW_CONNECTING"/>
    <STRING id="STR_ID_BRW_PROCESSING"/>
    <STRING id="STR_ID_BRW_LOADING"/>
    #endif /* __MMI_BRW_PAGE_FETCHING_STATUS__ */
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    <STRING id="STR_ID_BRW_VBOOKMARKS"/>
#endif
    #ifdef  __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__
    <STRING id="STR_ID_BRW_EXTERNAL_MEMORY"/>
    #endif /* __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__ */
    #ifdef OBIGO_Q05A
    <STRING id="STR_ID_BRW_FILE_PATH_TOO_LONG"/>
    #endif /* OBIGO_Q05A */

    #ifdef __MMI_CBM_CONNECTION_MANAGER__	
    <STRING id="STR_ID_BRW_CONNECTION_INFO"/>
    #endif /* __MMI_CBM_CONNECTION_MANAGER__ */
    #ifdef OBIGO_Q03C_BROWSER
    <STRING id="STR_ID_BRW_UNSUPPORTED_SCRIPTS"/>
    <STRING id="STR_ID_BRW_REQUIRES_FRAME_SUPPORT"/>
    #endif /* OBIGO_Q03C_BROWSER */

    <STRING id="STR_ID_BRW_NAVIGATION_OPTIONS"/>
    <STRING id="STR_ID_BRW_REN_PAGE_ADVANCED_OPTIONS"/>
#ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
	<STRING id="STR_ID_BRW_9WAY"/>
#endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
#ifdef __OP02__
	<STRING id="STR_ID_BRW_SPLASH_CONNECTING"/>
#endif /* __OP02__ */
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
#ifdef __MMI_DA_RESUME__
	<STRING id="STR_ID_BRW_DOWNLOAD_SUSPENDED"/>
#else
	<STRING id="STR_ID_BRW_DOWNLOAD_CANCELLED"/>
#endif /* __MMI_DA_RESUME__ */
#endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
	<STRING id="STR_ID_BRW_USER_DEFINED"/>
#endif
#ifdef OBIGO_Q03C_BROWSER
	<STRING id="STR_ID_BRW_NO_DISPLAY_CONTENT"/>
#endif
#ifdef WAP_SEC_SUPPORT
    <STRING id="STR_ID_BRW_READ_ONLY_CERTIFICATE"/>
#endif
    <STRING id="STR_ID_BRW_PLEASE_INPUT_USERNAME"/>
<STRING id="STR_ID_BRW_BROWSER"/>
#ifdef __OP01__
    <STRING id="STR_ID_BRW_VIEW_URL"/>
#endif /* __OP01__ */
    /* String ID's End */

    <STRING id="STR_ID_BRW_SEARCH_OR_INPUT_URL"/>

#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    <STRING id="STR_ID_BRW_CLEAR_URL_HISTORY"/>
#endif    
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    <STRING id="STR_ID_BRW_CLEAR_SEARCH_HISTORY"/>
#endif    
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    <STRING id="STR_ID_BRW_BEARER_SWITCH_RETRY"/>
#endif
#ifdef __MMI_URI_AGENT__
    <STRING id="STR_ID_BRW_URI_BUSY"/>
#endif
#if (defined(__SAT__) && defined(__MMI_WLAN_FEATURES__))
    <STRING id="STR_ID_BRW_SIM_IN_USE"/>
#endif

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    <STRING id="STR_ID_BRW_LAUNCH_PAGE"/>
    <STRING id="STR_ID_BRW_ADD_SHORTCUT"/>
    <STRING id="STR_ID_BRW_EDIT_SHORTCUT"/>
    <STRING id="STR_ID_BRW_DELETE_SHORTCUT"/>
    <STRING id="STR_ID_BRW_SAVE_SHORTCUT"/>
#endif
#ifdef SLIM_WAP_MMS
    <STRING id="STR_ID_BRW_IMAGES_NOT_AVAILABLE"/>
#endif
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of CUST_IMG_PATH"" */




    /* Image ID's Start */
    <IMAGE id="IMG_ID_BRW_HOMEPAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_HOME.bmp"</IMAGE>
    #ifdef __MMI_VBOOKMARK__
    
#ifndef __MMI_BRW_IMG_RES_SLIM__
    <IMAGE id="IMG_ID_BRW_BOOKMARKS">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_BOMK.bmp"</IMAGE>
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
	#if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_BRW_BOOKMARKS_FOLDER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Folder.pbm"</IMAGE>
    #else
    <IMAGE id="IMG_ID_BRW_BOOKMARKS_FOLDER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Folder.bmp"</IMAGE>
    #endif
#endif
#if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_BRW_BOOKMARKS_DEFAULT_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_PDefine.pbm"</IMAGE>
#else
	<IMAGE id="IMG_ID_BRW_BOOKMARKS_DEFAULT_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_PDefine.bmp"</IMAGE>
#endif
#ifdef __FTE_NON_SLIM_RES__
	#if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_BRW_BOOKMARKS_USER_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_USER.pbm"</IMAGE>
    #else
    <IMAGE id="IMG_ID_BRW_BOOKMARKS_USER_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_USER.png"</IMAGE>
    #endif
#else
    <IMAGE id="IMG_ID_BRW_BOOKMARKS_USER_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_USER.bmp"</IMAGE>
#endif
#endif
    #endif
#ifndef __MMI_BRW_IMG_RES_SLIM__
    <IMAGE id="IMG_ID_BRW_ENTER_ADDRESS_SEARCH_KEYWORD">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\URL_Search.bmp"</IMAGE>
#endif
    #ifdef OBIGO_Q05A
    <IMAGE id="IMG_ID_BRW_OPEN_FILE">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_BStorage.bmp"</IMAGE>
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    <IMAGE id="IMG_ID_BRW_LAST_WEB_ADDR">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_BLast.bmp"</IMAGE>
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifndef __MMI_BRW_IMG_RES_SLIM__
    <IMAGE id="IMG_ID_BRW_RECENT_PAGES">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_RTPAGE.bmp"</IMAGE>
#endif    
#endif
    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    <IMAGE id="IMG_ID_BRW_STORED_PAGES">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_OFLN.bmp"</IMAGE>
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
    <IMAGE id="IMG_ID_BRW_SETTINGS">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\WAP\\\\SW_SET.bmp"</IMAGE>
    
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    
    #if (MMI_MAX_SIM_NUM >= 2)

        #ifdef SLIM_WAP_MMS
            #ifdef __FTE_NON_SLIM_RES__
                <IMAGE id="IMG_ID_BRW_WAP_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_CONNECT.png"</IMAGE>
                <IMAGE id="IMG_ID_BRW_WAP_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_STOP.png"</IMAGE>
            #else
                <IMAGE id="IMG_ID_BRW_WAP_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_CONNECT.gif"</IMAGE>
                <IMAGE id="IMG_ID_BRW_WAP_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_STOP.gif"</IMAGE>
            #endif
        #else /* SLIM_WAP_MMS */

	        #if defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)
		        <IMAGE id="IMG_ID_BRW_WAP_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_SV_sim1.png"</IMAGE>
		        <IMAGE id="IMG_ID_BRW_WAP_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_SV_sim2.png"</IMAGE>
	        #else
		        <IMAGE id="IMG_ID_BRW_WAP_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_SV_sim1.bmp"</IMAGE>
		        <IMAGE id="IMG_ID_BRW_WAP_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_SV_sim2.bmp"</IMAGE>
                    #if (MMI_MAX_SIM_NUM >= 3)
	                <IMAGE id="IMG_ID_BRW_WAP_SIM3">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\Titlebar\\\\TB_SV_sim3.bmp"</IMAGE>
                    #endif
                    #if (MMI_MAX_SIM_NUM >= 4)
    	            <IMAGE id="IMG_ID_BRW_WAP_SIM4">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\Titlebar\\\\TB_SV_sim4.bmp"</IMAGE>
	            #endif
	        #endif

            <IMAGE id="IMG_ID_BRW_WAP_SIM1_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_CONNECT1.gif"</IMAGE>
            <IMAGE id="IMG_ID_BRW_WAP_SIM1_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_STOP1.gif"</IMAGE>
            <IMAGE id="IMG_ID_BRW_WAP_SIM2_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_CONNECT2.gif"</IMAGE>
            <IMAGE id="IMG_ID_BRW_WAP_SIM2_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_STOP2.gif"</IMAGE>
            #if (MMI_MAX_SIM_NUM >= 3)
                <IMAGE id="IMG_ID_BRW_WAP_SIM3_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\WAP\\\\WAP_CONNECT3.gif"</IMAGE>
                <IMAGE id="IMG_ID_BRW_WAP_SIM3_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\WAP\\\\WAP_STOP3.gif"</IMAGE>
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                <IMAGE id="IMG_ID_BRW_WAP_SIM4_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\WAP\\\\WAP_CONNECT4.gif"</IMAGE>
                <IMAGE id="IMG_ID_BRW_WAP_SIM4_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\WAP\\\\WAP_STOP4.gif"</IMAGE>
            #endif

        #endif /* SLIM_WAP_MMS */

    #else /* (MMI_MAX_SIM_NUM >= 2) */

        #ifdef __FTE_NON_SLIM_RES__
            <IMAGE id="IMG_ID_BRW_WAP_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_CONNECT.png"</IMAGE>
            <IMAGE id="IMG_ID_BRW_WAP_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_STOP.png"</IMAGE>
        #else
            <IMAGE id="IMG_ID_BRW_WAP_CONNECTING">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_CONNECT.gif"</IMAGE>
            <IMAGE id="IMG_ID_BRW_WAP_CONNECTED">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\WAP_STOP.gif"</IMAGE>
        #endif
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

    #ifndef __MMI_SLIM_IMG_RES__
        #ifdef __WIFI_SUPPORT__
            <IMAGE id="IMG_ID_BRW_CONNECTION_STATUS_WIFI">CUST_IMG_PATH"\\\\MainLCD\\\\WLAN\\\\Titlebar\\\\TB_busy.gif"</IMAGE>
            <IMAGE id="IMG_ID_BRW_CONNECTION_STATUS_WIFI_STATIC">CUST_IMG_PATH"\\\\MainLCD\\\\WLAN\\\\Titlebar\\\\TB_disconnect.gif"</IMAGE>
        #endif /* __WIFI_SUPPORT__ */
    #endif
#endif

    #ifdef __MMI_WAP_SPLASH_SCREEN_SUPPORT__
    <IMAGE id="IMG_ID_BRW_SPLASH_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\BroswerLoading.gif"</IMAGE>
    #endif /* __MMI_WAP_SPLASH_SCREEN_SUPPORT__ */
    #ifdef OBIGO_Q05A
    	#if defined(__COSMOS_MMI__)
    	<IMAGE id="IMG_ID_BRW_PAGE_OBJECTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_objects.pbm"</IMAGE>
    	#else
    	<IMAGE id="IMG_ID_BRW_PAGE_OBJECTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_objects.bmp"</IMAGE>
    	#endif
    #endif /*	OBIGO_Q05A */
    #ifdef WAP_SEC_SUPPORT	
    #ifdef __FTE_NON_SLIM_RES__
    	#if defined(__COSMOS_MMI__)
        <IMAGE id="IMG_ID_BRW_TRUSTED_CERTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Certificates.pbm"</IMAGE>
        #else
        <IMAGE id="IMG_ID_BRW_TRUSTED_CERTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Certificates.png"</IMAGE>
        #endif
    #else
        <IMAGE id="IMG_ID_BRW_TRUSTED_CERTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Certificates.bmp"</IMAGE>
    #endif
    #endif
#ifndef SLIM_WAP_MMS
	#if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_BRW_DO_ELEMENTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_elements.pbm"</IMAGE>
    #else
    <IMAGE id="IMG_ID_BRW_DO_ELEMENTS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_elements.bmp"</IMAGE>
    #endif
#endif
    #ifdef __MMI_OP12_BRW_SEARCH_MENU__
    <IMAGE id="IMG_ID_BRW_SEARCH">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_Searching.bmp"</IMAGE>
    #endif /* __MMI_OP12_BRW_SEARCH_MENU__ */ 

    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        /* File Upload Feature */
    #ifndef SLIM_WAP_MMS
    <IMAGE id="IMG_ID_BRW_UPLOAD_PROGRESS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\File_Uploading"</IMAGE>
    <IMAGE id="IMG_ID_BRW_UPLOAD_PROGRESS_STATIC">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\File_Uploading\\\\0.png"</IMAGE>
        /* File Upload Feature END */
    #endif
    #endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    #ifdef WAP_SEC_SUPPORT
    <IMAGE id="IMG_ID_BRW_SECURE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\KEY.bmp"</IMAGE>
    #endif /* WAP_SEC_SUPPORT */
    #ifdef __MMI_ICON_BAR_SUPPORT__
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_BRW_FTE_BOOKMARKS_LIST_ENABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_bookmark.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_BOOKMARKS_LIST_DISABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_bookmark_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_ADD_BOOKMARK_ENABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_add_bookmark.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_ADD_BOOKMARK_DISABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_add_bookmark_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_SAVE_BOOKMARK_ENABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_save_bookmark.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_SAVE_BOOKMARK_DISABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_save_bookmark_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_FORWARD_ENABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_browser_forward.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_FORWARD_DISABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_browser_forward_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_BACKWARD_ENABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_browser_back.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_BACKWARD_DISABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_browser_back_dis.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_INPUT_ADDRESS_ENABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_input_address.png"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FTE_INPUT_ADDRESS_DISABLE"> CUST_IMG_PATH"\\\\MainLCD\\\\ToolBar\\\\Browser\\\\TB_input_address_dis.png"</IMAGE>
    #endif /* __MMI_FTE_SUPPORT__ */
    #endif
    /* Image ID's End */


#if defined(OBIGO_Q05A)
    <IMAGE id="IMG_ID_BRW_FMGR_FILE_TYPE_HTM"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIWEB.bmp"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FMGR_HTM_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTM.gif"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FMGR_HTML_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTML.gif"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FMGR_WML_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_WML.gif"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FMGR_XHTML_LARGE_TYPE"> CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_XHTML.gif"</IMAGE>
#endif


#if defined (__MMI_VBOOKMARK__ )
    <IMAGE id="IMG_ID_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_USER.bmp"</IMAGE>
#ifndef __MMI_SLIM_FILE_MANAGER__
	#if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_BRW_FMGR_FILE_TYPE_URL"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.pbm"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FMGR_FILE_TYPE_VBM"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.pbm"</IMAGE>
    #else
    <IMAGE id="IMG_ID_BRW_FMGR_FILE_TYPE_URL"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.bmp"</IMAGE>
    <IMAGE id="IMG_ID_BRW_FMGR_FILE_TYPE_VBM"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.bmp"</IMAGE>
    #endif
#endif
#endif /* #if defined (__MMI_VBOOKMARK__ ) */
#if (defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__))
	<IMAGE id="IMG_ID_BROWSER_ICON"> CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\launcher\\\\Mainmenu\\\\Icons\\\\Browser.png"</IMAGE>
#endif	


#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    <IMAGE id="IMG_ID_BRW_LIST_ICON_URL_RESULT"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\URL.bmp"</IMAGE>
#endif
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    <IMAGE id="IMG_ID_BRW_LIST_ICON_SEARCH_RESULT"> CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Search.bmp"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
        <MENU id="MENU_ID_BRW_INTERNET_SERVICES" str="STR_ID_BRW_INTERNET_SERVICES" img="SERVICES_WAP_IMAGE_ID" shortcut ="ON" shortcut_img="IMG_ID_BRW_HOMEPAGE" launch="goto_mobile_suite_screen"/>
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    /* Launch Page Options*//*START*/
        <MENU id="MENU_ID_BRW_LAUNCH_PAGE_OPTIONS" type="OPTION" >
            <MENUITEM_ID>MENU_ID_BRW_LAUNCH_PAGE_ADD_SHORTCUT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_LAUNCH_PAGE_GOTO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_LAUNCH_PAGE_EDIT_SHORTCUT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_LAUNCH_PAGE_DELETE_SHORTCUT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SEARCH_WEB</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_LAUNCH_PAGE_DOWNLOADS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_HOMEPAGE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BOOKMARKS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADDRESS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_OPEN_FILE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_LAST_WEB_ADDR</MENUITEM_ID>
        #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGES</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_LAUNCH_PAGE_SETTINGS</MENUITEM_ID>
        </MENU>

        <MENU id="MENU_ID_BRW_LAUNCH_PAGE_ADD_SHORTCUT" str="STR_ID_BRW_ADD_SHORTCUT"/>

        <MENU id="MENU_ID_BRW_LAUNCH_PAGE_GOTO" str="STR_GLOBAL_GO_TO"/>

        <MENU id="MENU_ID_BRW_LAUNCH_PAGE_EDIT_SHORTCUT" str="STR_ID_BRW_EDIT_SHORTCUT"/>

        <MENU id="MENU_ID_BRW_LAUNCH_PAGE_DELETE_SHORTCUT" str="STR_ID_BRW_DELETE_SHORTCUT"/>

        <MENU id="MENU_ID_BRW_LAUNCH_PAGE_SETTINGS" str="STR_GLOBAL_SETTINGS"/>
#endif

    /*Internet Services Menu*//*START*/
    #ifdef __MMI_OP12_BRW_SEARCH_MENU__
        <MENU id="MENU_ID_BRW_SEARCH_WEB" str="@OID:STR_GLOBAL_SEARCH" img="IMG_ID_BRW_SEARCH" />
    #endif /* __MMI_OP12_BRW_SEARCH_MENU__ */ 
        <MENUITEM id="MENU_ID_BRW_HOMEPAGE" str="STR_ID_BRW_HOMEPAGE" img="IMG_ID_BRW_HOMEPAGE" />
    #ifdef __MMI_VBOOKMARK__
    #ifndef __MMI_BRW_IMG_RES_SLIM__
        <MENUITEM id="MENU_ID_BRW_BOOKMARKS" str="STR_ID_BRW_BOOKMARKS" img="IMG_ID_BRW_BOOKMARKS" />
    #else
        <MENUITEM id="MENU_ID_BRW_BOOKMARKS" str="STR_ID_BRW_BOOKMARKS" />
    #endif
        
    #endif /*__MMI_VBOOKMARK__*/

#ifndef __MMI_BRW_IMG_RES_SLIM__
    <MENUITEM id="MENU_ID_BRW_ENTER_ADDRESS" str="STR_ID_BRW_SEARCH_OR_INPUT_URL" img="IMG_ID_BRW_ENTER_ADDRESS_SEARCH_KEYWORD" />
#else
    <MENUITEM id="MENU_ID_BRW_ENTER_ADDRESS" str="STR_ID_BRW_SEARCH_OR_INPUT_URL" />
#endif    
    #ifdef OBIGO_Q05A
        <MENUITEM id="MENU_ID_BRW_OPEN_FILE" str="STR_ID_BRW_OPEN_FILE" img="IMG_ID_BRW_OPEN_FILE" />
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
        <MENU id="MENU_ID_BRW_LAST_WEB_ADDR" str="STR_ID_BRW_LAST_WEB_ADDR" img="IMG_ID_BRW_LAST_WEB_ADDR" />
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    #ifndef __MMI_BRW_IMG_RES_SLIM__
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGES" str="STR_ID_BRW_RECENT_PAGES" img="IMG_ID_BRW_RECENT_PAGES" />
    #else
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGES" str="STR_ID_BRW_RECENT_PAGES" />
    #endif
#endif
#ifdef __OP01__
		<MENUITEM id="MENU_ID_BRW_VIEW_URL" str="STR_ID_BRW_VIEW_URL"/>
#endif /* __OP01__ */
    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_STORED_PAGES" str="STR_ID_BRW_STORED_PAGES" img="IMG_ID_BRW_STORED_PAGES" />
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */


        <MENU id="MENU_ID_BRW_SETTINGS" type="APP_SUB" str="STR_GLOBAL_SETTINGS" img="IMG_ID_BRW_SETTINGS" >
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_SETTINGS_HOMEPAGE</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_DATA_ACCOUNT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_PREFERENCES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SECURITY_SETTINGS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SETTINGS_CONNECTION_INFO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RESTORE_BROWSER_SETTINGS</MENUITEM_ID>
        </MENU>
    /*Internet Services Menu*//*END*/

        <MENUITEM id="MENU_ID_BRW_DATA_ACCOUNT" str="STR_GLOBAL_DATA_ACCOUNT" />

    /* Bookmark Menu Start */
    #ifdef __MMI_VBOOKMARK__

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        <MENU id="MENU_ID_BRW_BKM_OPTIONS_FOR_FOLDER" type="OPTION">
            <MENUITEM_ID>MENU_ID_BRW_BKM_OPEN_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_RENAME_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_DELETE_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_ADD_BOOKMARK</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_CREATE_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_MEMORY_STATUS</MENUITEM_ID>
        </MENU>
	#endif
        <MENU id="MENU_ID_BRW_BKM_OPTIONS_FOR_EMPTY_FOLDER" type="OPTION">
            <MENUITEM_ID>MENU_ID_BRW_BKM_ADD_BOOKMARK</MENUITEM_ID>
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BKM_CREATE_FOLDER</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_BKM_MEMORY_STATUS</MENUITEM_ID>
        </MENU>

        <MENU id="MENU_ID_BRW_BKM_OPTIONS_FOR_DEFAULT_FILE" type="OPTION">
            <MENUITEM_ID>MENU_ID_BRW_BKM_GOTO</MENUITEM_ID>
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__            
            <MENUITEM_ID>MENU_ID_BRW_BKM_VIEW</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_ADD_BOOKMARK</MENUITEM_ID>
        #endif            
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_BKM_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BKM_CREATE_FOLDER</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_BKM_MEMORY_STATUS</MENUITEM_ID>
        </MENU>


        <MENU id="MENU_ID_BRW_BKM_OPTIONS_FOR_USER_FILE" type="OPTION">
            <MENUITEM_ID>MENU_ID_BRW_BKM_GOTO</MENUITEM_ID>
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BKM_VIEW</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_EDIT</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_BKM_DELETE</MENUITEM_ID>
        #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BKM_DELETE_ALL_USER_FILES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_ADD_BOOKMARK</MENUITEM_ID>
        #endif
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_BKM_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS</MENUITEM_ID>
        #endif
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BKM_CREATE_FOLDER</MENUITEM_ID>
        #endif
    #if (defined __MMI_BRW_BKM_FOLDER_SUPPORT__ || defined __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__)
            <MENUITEM_ID>MENU_ID_BRW_BKM_COPY_TO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_MOVE_TO</MENUITEM_ID>
    #endif
            <MENUITEM_ID>MENU_ID_BRW_BKM_MEMORY_STATUS</MENUITEM_ID>
        </MENU>


    #ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
        <MENU id="MENU_ID_BRW_BKM_OPTIONS_OPEN_FROM_FMGR" type="APP_SUB" str="STR_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_BRW_BKM_VIEW</MENUITEM_ID>
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_BKM_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_BKM_ADD_TO_BOOKMARK_FROM_FMGR</MENUITEM_ID>
        </MENU>
    #endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        <MENU id="MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS" type="OPTION">
            <MENUITEM_ID>MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER</MENUITEM_ID>
        </MENU>
    #endif

    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BKM_OPEN_FOLDER" str="STR_GLOBAL_OPEN" />
        <MENUITEM id="MENU_ID_BRW_BKM_RENAME_FOLDER" str="STR_GLOBAL_RENAME"/>
        <MENUITEM id="MENU_ID_BRW_BKM_DELETE_FOLDER" str="STR_GLOBAL_DELETE"/>
    #endif
        <MENUITEM id="MENU_ID_BRW_BKM_GOTO" str="STR_GLOBAL_GO_TO" />
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__            
        <MENUITEM id="MENU_ID_BRW_BKM_VIEW" str="STR_GLOBAL_VIEW" />
        <MENUITEM id="MENU_ID_BRW_BKM_EDIT" str="STR_GLOBAL_EDIT" />
    #endif
        <MENUITEM id="MENU_ID_BRW_BKM_DELETE" str="STR_GLOBAL_DELETE" />
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__            
        <MENUITEM id="MENU_ID_BRW_BKM_DELETE_ALL_USER_FILES" str="STR_ID_BRW_DELETE_ALL_FILES" />
        <MENUITEM id="MENU_ID_BRW_BKM_ADD_BOOKMARK" str="STR_ID_BRW_ADD_BOOKMARK" />
    #endif
    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        <MENUITEM id="MENU_ID_BRW_BKM_SET_AS_HOMEPAGE" str="STR_ID_BRW_SET_AS_HOMEPAGE" />
    #endif
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BKM_CREATE_FOLDER" str="STR_ID_BRW_CREATE_FOLDER" />
    #endif
    #if (defined __MMI_BRW_BKM_FOLDER_SUPPORT__ || defined __MMI_BRW_TRANSFER_BOOKMARK_TO_EXT_MEMORY__)
        <MENUITEM id="MENU_ID_BRW_BKM_COPY_TO" str="STR_ID_BRW_COPY_TO" />
        <MENUITEM id="MENU_ID_BRW_BKM_MOVE_TO" str="STR_ID_BRW_MOVE_TO" />
    #endif
        <MENUITEM id="MENU_ID_BRW_BKM_MEMORY_STATUS" str="STR_GLOBAL_MEMORY_STATUS" />
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT" str="STR_GLOBAL_SELECT" />
        <MENUITEM id="MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER" str="STR_GLOBAL_OPEN" />
        <MENUITEM id="MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER" str="STR_ID_BRW_CREATE_FOLDER" />
    #endif
    #ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
        <MENUITEM id="MENU_ID_BRW_BKM_ADD_TO_BOOKMARK_FROM_FMGR" str="STR_ID_BRW_ADD_TO_BOOKMARK" />
    #endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
	    /* Send Bookmark Options Start */


    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        <MENU id="MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS" type="OPTION" str="STR_ID_BRW_SEND_BOOKMARK">
            <MENUITEM_ID>MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_SMS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_MMS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_INFRARED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_EMAIL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_BLUETOOTH</MENUITEM_ID>
        </MENU>

    #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
        <MENUITEM id="MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE" />
    #endif
    #if defined(__MMI_MMS__)
        <MENUITEM id="MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG"/>
    #endif
    #if  defined(__MMI_IRDA_SUPPORT__)
        <MENUITEM id="MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_INFRARED" str="STR_GLOBAL_VIA_INFRARED" />
    #endif
    #ifdef __MMI_OPP_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_BLUETOOTH" str="STR_GLOBAL_VIA_BLUETOOTH" />
    #endif
    #if  defined(__MMI_EMAIL__)
        <MENUITEM id="MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_EMAIL" str="STR_GLOBAL_AS_EMAIL" />
    #endif
    #endif
	    /* Send Bookmark Options End */
    #endif /*__MMI_VBOOKMARK__*/
    /* Bookmark Menu End */

    /*Enter Address Options Menu*//*START*/

        <MENU id="MENU_ID_BRW_ENTER_ADR_OPTIONS" type="OPTION">
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADR_GOTO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADR_EDIT</MENUITEM_ID>
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADR_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADR_ADD_TO_BOOKMARK</MENUITEM_ID>
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_OPTIONS</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADR_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADR_DELETE_ALL</MENUITEM_ID>
        </MENU>


        <MENUITEM id="MENU_ID_BRW_ENTER_ADR_GOTO" str="STR_GLOBAL_GO_TO" />
        <MENUITEM id="MENU_ID_BRW_ENTER_ADR_EDIT" str="STR_GLOBAL_EDIT" />
    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        <MENUITEM id="MENU_ID_BRW_ENTER_ADR_SET_AS_HOMEPAGE" str="STR_ID_BRW_SET_AS_HOMEPAGE" />
    #endif
    #ifdef __MMI_VBOOKMARK__
        <MENUITEM id="MENU_ID_BRW_ENTER_ADR_ADD_TO_BOOKMARK" str="STR_ID_BRW_ADD_TO_BOOKMARK" />
    #endif /*__MMI_VBOOKMARK__*/
        <MENUITEM id="MENU_ID_BRW_ENTER_ADR_DELETE" str="STR_GLOBAL_DELETE" />
        <MENUITEM id="MENU_ID_BRW_ENTER_ADR_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL" />
    /*Enter Address Options Menu*//*END*/


#ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
    /*Send Address Options Menu*//*START*/

        <MENU id="MENU_ID_BRW_SEND_ADDRESS_OPTIONS" type="OPTION" str="STR_ID_BRW_SEND_ADDRESS">
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_AS_SMS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_AS_MMS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_VIA_INFRARED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH</MENUITEM_ID>
        </MENU>


    #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
        <MENUITEM id="MENU_ID_BRW_SEND_ADDRESS_AS_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE" />
    #endif
    #if defined(__MMI_MMS__)
        <MENUITEM id="MENU_ID_BRW_SEND_ADDRESS_AS_MMS" str="STR_GLOBAL_AS_MULTIMEDIA_MSG" />
    #endif
    #if  defined(__MMI_IRDA_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
        <MENUITEM id="MENU_ID_BRW_SEND_ADDRESS_VIA_INFRARED" str="STR_GLOBAL_VIA_INFRARED" />
    #endif
    #if  defined(__MMI_OPP_SUPPORT__)	&&  defined(__MMI_VBOOKMARK__)
        <MENUITEM id="MENU_ID_BRW_SEND_ADDRESS_VIA_BLUETOOTH" str="STR_GLOBAL_VIA_BLUETOOTH" />
    #endif
    #if  defined(__MMI_EMAIL__)
        <MENUITEM id="MENU_ID_BRW_SEND_ADDRESS_VIA_EMAIL" str="STR_GLOBAL_AS_EMAIL" />
    #endif
    /*Send Address Options Menu*//*END*/
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    /* Recent Pages Options Menu*//*Start*/
	    /* Recent Pages Options Menu - for sorted by last visited or most visited*//*Start*/
        <MENU id="MENU_ID_BRW_RECENT_PAGE_OPTIONS" type="OPTION" >
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_GOTO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_DELETE_ALL</MENUITEM_ID>
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_ADD_TO_BOOKMARK</MENUITEM_ID>
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_OPTIONS</MENUITEM_ID>
        #endif
        </MENU>
	    /* Recent Pages Options Menu - for sorted by last visited or most visited*//*End*/

    #ifdef OBIGO_Q05A
	    /* Recent Pages Options Menu - for sorted by site*//*Start*/
        <MENU id="MENU_ID_BRW_RECENT_PAGE_OPTIONS_1" type="OPTION" >
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_OPEN_HOST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_HOST_SORT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_DELETE_HOST</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_DELETE_ALL_HOST</MENUITEM_ID>
        </MENU>
	    /* Recent Pages Options Menu - for sorted by site*//*End*/
    #endif /* OBIGO_Q05A */
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_GOTO" str="STR_GLOBAL_GO_TO" />
    #ifdef OBIGO_Q05A
        <MENU id="MENU_ID_BRW_RECENT_PAGE_SORT" type="OPTION" str="STR_GLOBAL_SORT_BY" >
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT_BY_LAST_VISITED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT_BY_MOST_VISITED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT_BY_SITE</MENUITEM_ID>
        </MENU>
		<MENU id="MENU_ID_BRW_RECENT_HOST_SORT" type="OPTION" str="STR_GLOBAL_SORT_BY" >
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT_BY_LAST_VISITED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT_BY_MOST_VISITED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGE_SORT_BY_SITE</MENUITEM_ID>
        </MENU>

    #endif /* OBIGO_Q05A */
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_DELETE" str="STR_GLOBAL_DELETE" />
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL" />
    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_SET_AS_HOMEPAGE" str="STR_ID_BRW_SET_AS_HOMEPAGE" />
    #endif
    #ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    #ifdef __MMI_VBOOKMARK__
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_ADD_TO_BOOKMARK" str="STR_ID_BRW_ADD_TO_BOOKMARK" />
    #endif /*__MMI_VBOOKMARK__*/
    #endif
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_SEND_ADDRESS" str="STR_ID_BRW_SEND_ADDRESS" />
    #endif
    #ifdef OBIGO_Q05A
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_OPEN_HOST" str="STR_GLOBAL_OPEN" />
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_DELETE_HOST" str="STR_GLOBAL_DELETE" />
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_DELETE_ALL_HOST" str="STR_GLOBAL_DELETE_ALL" />
    /*Sort Recent Pages Menu*//*Start*/
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_SORT_BY_LAST_VISITED" str="STR_ID_BRW_SORT_BY_LAST_VISITED" />
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_SORT_BY_MOST_VISITED" str="STR_ID_BRW_SORT_BY_MOST_VISITED" />
        <MENUITEM id="MENU_ID_BRW_RECENT_PAGE_SORT_BY_SITE" str="STR_ID_BRW_SORT_BY_SITE" />
    /*Sort Recent Pages Menu*//*END*/
    #endif /* OBIGO_Q05A */
    /* Recent Pages Options Menu*//*End*/
#endif

    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
    /*Stored Pages Options Menu*//*Start*/
        <MENU id="MENU_ID_BRW_STORED_PAGE_OPTIONS" type="OPTION" >
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_OPEN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_PROPERTIES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_RENAME</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_DELETE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_DELETE_ALL</MENUITEM_ID>
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGE_ADD_TO_BOOKMARK</MENUITEM_ID>
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_OPTIONS</MENUITEM_ID>
        #endif
        </MENU>

        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_OPEN" str="STR_GLOBAL_GO_TO" />
    #ifdef OBIGO_Q05A
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_PROPERTIES" str="STR_ID_BRW_PROPERTIES" />
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_RENAME" str="STR_GLOBAL_RENAME" />
    #endif /* OBIGO_Q05A */
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_DELETE" str="STR_GLOBAL_DELETE" />
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_DELETE_ALL" str="STR_GLOBAL_DELETE_ALL" />
    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_SET_AS_HOMEPAGE" str="STR_ID_BRW_SET_AS_HOMEPAGE" />
    #endif
    #ifdef __MMI_VBOOKMARK__
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_ADD_TO_BOOKMARK" str="STR_ID_BRW_ADD_TO_BOOKMARK" />
    #endif /*__MMI_VBOOKMARK__*/
    #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
        <MENUITEM id="MENU_ID_BRW_STORED_PAGE_SEND_ADDRESS" str="STR_ID_BRW_SEND_ADDRESS" />
    #endif
    /*Stored Pages Options Menu*//*End*/
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */

#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    <MENU id="MENU_ID_BRW_SETTINGS_HOMEPAGE" type="APP_SUB" str="STR_ID_BRW_HOMEPAGE" >
        <MENUITEM_ID>MENU_ID_BRW_SETTING_HOMEPAGE_DEFAULT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_BRW_SETTING_HOMEPAGE_USER_DEFINED</MENUITEM_ID>
    </MENU>

	<MENUITEM id="MENU_ID_BRW_SETTING_HOMEPAGE_DEFAULT" str="STR_GLOBAL_DEFAULT" />
	<MENUITEM id="MENU_ID_BRW_SETTING_HOMEPAGE_USER_DEFINED" str="STR_ID_BRW_USER_DEFINED" />
#endif
    /*Browser Settings Menu*//*START*/

        <MENU id="MENU_ID_BRW_BROWSER_OPTIONS" type="APP_SUB" str="STR_ID_BRW_BROWSER_OPTIONS" >
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_ENCODING</MENUITEM_ID>
			<MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_9WAY</MENUITEM_ID>
        #ifndef SLIM_WAP_MMS
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_CACHE</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_COOKIE</MENUITEM_ID>
		    <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_AUTH_INFO</MENUITEM_ID>
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_SEARCH_HISTORY</MENUITEM_ID>
#endif
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_URL_HISTORY</MENUITEM_ID>
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
			<MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_USE_BAIDU_PROXY</MENUITEM_ID>
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
        </MENU>


        <MENUITEM id="MENU_ID_BRW_PREFERENCES" str="STR_ID_BRW_PREFERENCES" />
    #ifdef WAP_SEC_SUPPORT

        <MENU id="MENU_ID_BRW_SECURITY_SETTINGS" type="APP_SUB" str="STR_ID_BRW_SECURITY_SETTINGS" >
	    #ifdef OBIGO_Q05A
            <MENUITEM_ID>MENU_ID_BRW_SECURITY_SETTINGS_SESSION_INFO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SECURITY_SETTINGS_CURRENT_CERTIFICATE</MENUITEM_ID>
	    #endif /* OBIGO_Q05A */

            <MENUITEM_ID>MENU_ID_BRW_SECURITY_SETTINGS_TRUSTED_CERTIFICATES</MENUITEM_ID>
        </MENU>

    #endif
    #ifdef __MMI_CBM_CONNECTION_MANAGER__	
        <MENUITEM id="MENU_ID_BRW_SETTINGS_CONNECTION_INFO" str="STR_ID_BRW_CONNECTION_INFO" />
    #endif /* __MMI_CBM_CONNECTION_MANAGER__ */
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
        <MENUITEM id="MENU_ID_BRW_RESTORE_BROWSER_SETTINGS" str="STR_ID_BRW_RESTORE_BROWSER_SETTINGS" />
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */

    /*Browser Settings Menu*//*END*/


    /*Browsing Options*//*START*/
	    /*Rendering Modes*//*START*/
    #ifdef OBIGO_Q05A
        <MENU id="MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES" type="APP_SUB" str="STR_ID_BRW_RENDERING_MODES" >
            <MENUITEM_ID>MENU_ID_BRW_RENDERING_MODES_STANDARD</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RENDERING_MODES_TEXT_WRAP</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RENDERING_MODES_SCREEN_OPTIMIZED</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_RENDERING_MODES_TEXT_ONLY</MENUITEM_ID>
        </MENU>
	    <MENUITEM id="MENU_ID_BRW_RENDERING_MODES_STANDARD" str="STR_ID_BRW_STANDARD" />
	    <MENUITEM id="MENU_ID_BRW_RENDERING_MODES_TEXT_WRAP" str="STR_ID_BRW_TEXT_WRAP" />
	    <MENUITEM id="MENU_ID_BRW_RENDERING_MODES_SCREEN_OPTIMIZED" str="STR_ID_BRW_SCREEN_OPTIMIZED" />
	    <MENUITEM id="MENU_ID_BRW_RENDERING_MODES_TEXT_ONLY" str="STR_ID_BRW_TEXT_ONLY" />
	    /*Rendering Modes*//*END*/

	    /*Navigation Modes*//*START*/
        <MENU id="MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES" type="APP_SUB" str="STR_ID_BRW_NAVIGATION_MODES" >
            <MENUITEM_ID>MENU_ID_BRW_NAVIGATION_MODES_FOUR_WAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_NAVIGATION_MODES_TWO_WAY</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_NAVIGATION_MODES_SCROLLING</MENUITEM_ID>
        </MENU>

	    <MENUITEM id="MENU_ID_BRW_NAVIGATION_MODES_FOUR_WAY" str="STR_ID_BRW_FOUR_WAY" />
	    <MENUITEM id="MENU_ID_BRW_NAVIGATION_MODES_TWO_WAY" str="STR_ID_BRW_TWO_WAY" />
	    <MENUITEM id="MENU_ID_BRW_NAVIGATION_MODES_SCROLLING" str="STR_ID_BRW_SCROLLING" />
	    /*Navigation Modes*//*END*/

    #ifdef __MMI_VECTOR_FONT_SUPPORT__
	    /*Font Sizes*//*START*/
        <MENU id="MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE" type="APP_SUB" str="STR_ID_BRW_FONT_SIZE" >
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_SMALL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_MEDIUM</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_LARGE</MENUITEM_ID>
       </MENU>

        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_SMALL" str="STR_ID_BRW_SMALL" />
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_MEDIUM" str="STR_GLOBAL_MEDIUM" />
	    <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_LARGE" str="STR_ID_BRW_LARGE" />
	    /*Font Sizes*//*END*/
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
	    <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL" str="STR_ID_BRW_THUMBNAIL" />
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE" str="STR_ID_BRW_SCREEN_SIZE" />

#if 0
	    /*Screen Size Options*//*START*/
	        <MENU id="MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE" type="APP_SUB" str="STR_ID_BRW_SCREEN_SIZE" >
            <MENUITEM_ID>MENU_ID_BRW_SCREEN_SIZE_FULL</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SCREEN_SIZE_SMALL</MENUITEM_ID>
         </MENU>

	    <MENUITEM id="MENU_ID_BRW_SCREEN_SIZE_FULL" str="STR_ID_BRW_FULL"/>		
	    <MENUITEM id="MENU_ID_BRW_SCREEN_SIZE_SMALL" str="STR_ID_BRW_SMALL"/>		
#endif

	    /*Screen Size Options*//*END*/

	    /*Encoding Methods Menu*//*START*/
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_ENCODING" str="STR_ID_BRW_ENCODING" />
	    /*Encoding Methods Menu*//*END*/
    #endif /* OBIGO_Q05A */
    #ifdef __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_9WAY" str="STR_ID_BRW_9WAY"/>
    #endif /* __MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__ */
    #ifndef SLIM_WAP_MMS
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_CACHE" str="STR_ID_BRW_CLEAR_CACHE" />
    #endif
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_COOKIE" str="STR_ID_BRW_CLEAR_COOKIE" />
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_AUTH_INFO" str="STR_ID_BRW_CLEAR_AUTH_INFO" />
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_SEARCH_HISTORY" str="STR_ID_BRW_CLEAR_SEARCH_HISTORY" />
#endif
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_URL_HISTORY" str="STR_ID_BRW_CLEAR_URL_HISTORY" />
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_BROWSER_OPTIONS_USE_BAIDU_PROXY" str="STR_ID_BRW_BAIDU_PROXY" />
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
    /*Browsing Options*//*END*/


    /*Security Settings*//*START*/
    #ifdef WAP_SEC_SUPPORT
    #ifdef OBIGO_Q05A
        <MENUITEM id="MENU_ID_BRW_SECURITY_SETTINGS_SESSION_INFO" str="STR_ID_BRW_SESSION_INFO" />
        <MENUITEM id="MENU_ID_BRW_SECURITY_SETTINGS_CURRENT_CERTIFICATE" str="STR_ID_BRW_CURRENT_CERTIFICATE" />
    #endif /* OBIGO_Q05A */
        <MENUITEM id="MENU_ID_BRW_SECURITY_SETTINGS_TRUSTED_CERTIFICATES" str="STR_ID_BRW_TRUSTED_CERTIFICATES" />

        <MENU id="MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_VIEW</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_DELETE</MENUITEM_ID>
        </MENU>

        <MENUITEM id="MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_VIEW" str="STR_GLOBAL_VIEW" />
	    <MENUITEM id="MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_DELETE" str="STR_GLOBAL_DELETE" />
    #endif
    /*Security Settings*//*END*/

    /* Rendered Page Options*//*START*/
        <MENU id="MENU_ID_BRW_RENDERED_PAGE_OPTIONS" type="OPTION" >
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_GOTO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_EDIT</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_RESET</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_SELECT_FILE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_DOWNLOADS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SEARCH_WEB</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_NAVIGATE_REFRESH</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_NAVIGATE_BACKWARD</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_NAVIGATE_FORWARD</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_NAVIGATE_PAGE_ACTIONS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_NAVIGATION_OPTIONS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_ENTER_ADDRESS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_ADD_TO_BOOKMARK</MENUITEM_ID>
        #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_SET_AS_HOMEPAGE</MENUITEM_ID>
        #endif
        #ifndef __MMI_BRW_SEND_ADDRESS_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_SEND_ADDRESS_OPTIONS</MENUITEM_ID>
        #endif
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_ADVANCED_OPTIONS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_SETTINGS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_EXIT</MENUITEM_ID>
        </MENU>

        <MENUITEM id="MENU_ID_BRW_REN_PAGE_GOTO" str="STR_GLOBAL_GO_TO" />
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_EDIT" str="STR_GLOBAL_EDIT" />
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_RESET" str="STR_GLOBAL_RESET" />
    #ifdef __MMI_BRW_FILE_UPLOAD_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_SELECT_FILE" str="STR_ID_BRW_SELECT_FILE" />
    #endif /* __MMI_BRW_FILE_UPLOAD_SUPPORT__ */
    #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    #ifdef __MMI_DA_CONF_PAGE_SLIM__
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_DOWNLOADS" str="STR_ID_BRW_DOWNLOADS" />
    #else
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_DOWNLOADS" str="STR_ID_BRW_DOWNLOADS" img="@OID:IMG_ID_DA_DOWNLOAD_ICON" />
    #endif
    #endif

    #ifdef __MMI_VBOOKMARK__
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_ADD_TO_BOOKMARK" str="STR_ID_BRW_ADD_TO_BOOKMARK" />
    #endif /*__MMI_VBOOKMARK__*/
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_NAVIGATE_REFRESH" str="STR_GLOBAL_REFRESH" />


        <MENU id="MENU_ID_BRW_REN_PAGE_NAVIGATION_OPTIONS" type="OPTION" str="STR_ID_BRW_NAVIGATION_OPTIONS" >
            <MENUITEM_ID>MENU_ID_BRW_HOMEPAGE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_BOOKMARKS</MENUITEM_ID>
        #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
            <MENUITEM_ID>MENU_ID_BRW_RECENT_PAGES</MENUITEM_ID>
        #endif
           #ifdef __OP01__
	    <MENUITEM_ID>MENU_ID_BRW_VIEW_URL</MENUITEM_ID>
	   #endif /* __OP01__ */
        </MENU>

        <MENU id="MENU_ID_BRW_REN_PAGE_ADVANCED_OPTIONS" type="OPTION" str="STR_ID_BRW_REN_PAGE_ADVANCED_OPTIONS" >
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_SELECT_MODE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_STORE_OFFLINE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_STORED_PAGES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_PAGE_OBJECTS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_REN_PAGE_PROPERTIES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_OPEN_FILE</MENUITEM_ID>
        </MENU>


        <MENUITEM id="MENU_ID_BRW_REN_PAGE_SELECT_MODE" str="STR_ID_BRW_SELECT_MODE" />

        <MENUITEM id="MENU_ID_BRW_REN_PAGE_EXIT" str="STR_GLOBAL_EXIT" />
    /* Rendered Page Options*//*END*/


    #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_SET_AS_HOMEPAGE" str="STR_ID_BRW_SET_AS_HOMEPAGE" />
    #endif
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_SETTINGS" str="STR_GLOBAL_SETTINGS" />

    #ifdef __MMI_WAP_OFFLINE_PAGES_SUPPORT__
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_STORE_OFFLINE" str="STR_ID_BRW_STORE_OFFLINE" />
    #endif /* __MMI_WAP_OFFLINE_PAGES_SUPPORT__ */
    #ifdef OBIGO_Q05A
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_PAGE_OBJECTS" str="STR_ID_BRW_PAGE_OBJECTS" />
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_PROPERTIES" str="STR_ID_BRW_PROPERTIES" />


    /*Page Objects Options*//*START*/
        <MENU id="MENU_ID_BRW_PAGE_OBJECTS_OPTIONS" type="OPTION" str="STR_ID_BRW_PAGE_OBJECTS">
            <MENUITEM_ID>MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_PAGE_OBJECTS_PROPERTIES</MENUITEM_ID>
        </MENU>

        <MENUITEM id="MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS" str="STR_ID_BRW_SAVE_AS" />
        <MENUITEM id="MENU_ID_BRW_PAGE_OBJECTS_PROPERTIES" str="STR_ID_BRW_PROPERTIES" />
    /*Page Objects Options*//*END*/
    #endif /* OBIGO_Q05A */

    /*Select Mode*//*START*/
        <MENU id="MENU_ID_BRW_SELECT_MODE_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_BRW_SELECT_MODE_SAVE_AS</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SELECT_MODE_PROPERTIES</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_SELECT_MODE_EXIT</MENUITEM_ID>
        </MENU>
        <MENUITEM id="MENU_ID_BRW_SELECT_MODE_SAVE_AS" str="STR_ID_BRW_SAVE_AS" />
    #ifdef OBIGO_Q05A
        <MENUITEM id="MENU_ID_BRW_SELECT_MODE_PROPERTIES" str="STR_ID_BRW_PROPERTIES" />
    #endif /* OBIGO_Q05A */
        <MENUITEM id="MENU_ID_BRW_SELECT_MODE_EXIT" str="STR_GLOBAL_EXIT" />
    /*Select Mode*//*END*/

        <MENUITEM id="MENU_ID_BRW_REN_PAGE_NAVIGATE_FORWARD" str="STR_ID_BRW_FORWARD" />

        <MENUITEM id="MENU_ID_BRW_REN_PAGE_NAVIGATE_BACKWARD" str="STR_ID_BRW_BACKWARD" />
    #ifndef SLIM_WAP_MMS
        <MENUITEM id="MENU_ID_BRW_REN_PAGE_NAVIGATE_PAGE_ACTIONS" str="STR_ID_BRW_PAGE_ACTIONS" />
    #endif

    /*Full Screen Editor Options Menu*//*START*/
        <MENU id="MENU_ID_BRW_EDITOR_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_BRW_EDITOR_OPTION_DONE</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_BRW_EDITOR_OPTION_CANCEL</MENUITEM_ID>
            <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
        </MENU>


        <MENUITEM id="MENU_ID_BRW_EDITOR_OPTION_DONE" str="STR_GLOBAL_GO_TO"/>

        <MENUITEM id="MENU_ID_BRW_EDITOR_OPTION_CANCEL" str="STR_GLOBAL_CANCEL" />
    /*Full Screen Editor Options Menu*//*END*/
	/* FMGR related code START*/

        <MENU id="MENU_ID_BRW_WEB_FILE_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
            <MENUITEM_ID>MENU_ID_BRW_WEB_PAGE_OPEN</MENUITEM_ID>
            #ifdef __PLUTO_MMI_PACKAGE__
            <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
            #endif
        </MENU>
        <MENUITEM id="MENU_ID_BRW_WEB_PAGE_OPEN" str="STR_GLOBAL_OPEN"/>

        <MENU id="MENU_ID_BRW_FMGR_BOOKMARK_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_GLOBAL_OPTIONS">
        #ifdef __MMI_VBOOKMARK__
            <MENUITEM_ID>MENU_ID_BRW_FMGR_BOOKMARK_GOTO</MENUITEM_ID>
        #endif
        #ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
            <MENUITEM_ID>MENU_ID_BRW_FMGR_BOOKMARK_OPEN</MENUITEM_ID>
        #endif
            #ifdef __PLUTO_MMI_PACKAGE__
            <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
            #endif
        </MENU>
        <MENUITEM id="MENU_ID_BRW_FMGR_BOOKMARK_GOTO" str="STR_GLOBAL_GO_TO"/>
        <MENUITEM id="MENU_ID_BRW_FMGR_BOOKMARK_OPEN" str="STR_GLOBAL_OPEN"/>


        <MENU id="MENU_ID_BRW_FMGR_BOOKMARK_SEND_OPTIONS" type="OPTION" str="STR_GLOBAL_SEND">
        #ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
            <MENUITEM_ID>MENU_ID_BRW_FMGR_BOOKMARK_SEND_BY_SMS</MENUITEM_ID>
        #endif
            #ifdef __PLUTO_MMI_PACKAGE__
            <MENUSET_ID>MENU_ID_FMGR_GEN_SEND_OPTION_SET</MENUSET_ID>
            #endif
        </MENU>
	#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
        <MENUITEM id="MENU_ID_BRW_FMGR_BOOKMARK_SEND_BY_SMS" str="STR_GLOBAL_AS_TEXT_MESSAGE"/>
	#endif

	/* FMGR related code  END */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->


    <SCREEN id="SCR_ID_BRW_FIRST_SCREEN_ID"/>
    /* please add all screen IDs below this line */

    <SCREEN id="SCR_ID_BRW_INTERNET_SERVICES"/>
    <SCREEN id="SCR_ID_BRW_BOOKMARKS"/>
    <SCREEN id="SCR_ID_BRW_BOOKMARK_OPTIONS"/>
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    <SCREEN id="SCR_ID_BRW_EDIT_BOOKMARK"/>
    <SCREEN id="SCR_ID_BRW_ADD_BOOKMARK"/>
    <SCREEN id="SCR_ID_BRW_ADD_TO_BOOKMARK"/>
#endif
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    <SCREEN id="SCR_ID_BRW_RECENT_PAGES"/>
    <SCREEN id="SCR_ID_BRW_RECENT_PAGE_OPTIONS"/>
#endif
    <SCREEN id="SCR_ID_BRW_ENTER_URL"/>
    <SCREEN id="SCR_ID_BRW_SETTINGS"/>
    <SCREEN id="SCR_ID_BRW_RENDERED_PAGE_OPTIONS"/>
    <SCREEN id="SCR_ID_BRW_STORED_PAGES"/>
    <SCREEN id="SCR_ID_BRW_STORED_PAGE_OPTIONS"/>
    <SCREEN id="SCR_ID_BRW_RENDERING_MODES"/>
    <SCREEN id="SCR_ID_BRW_NAVIGATION_MODES"/>
    <SCREEN id="SCR_ID_BRW_BROWSER_PREFERENCES"/>
    <SCREEN id="SCR_ID_BRW_ENCODING_METHODS"/>
    <SCREEN id="SCR_ID_BRW_BROWSER_MAIN"/>
    <SCREEN id="SCR_ID_BRW_FONT_SIZE"/>
    <SCREEN id="SCR_ID_BRW_MEMORY_STATUS"/>
    <SCREEN id="SCR_ID_BRW_STORED_PAGE_RENAME"/>
    <SCREEN id="SCR_ID_BRW_TRUSTED_CERTIFICATES"/>
    <SCREEN id="SCR_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS"/>
    <SCREEN id="SCR_ID_BRW_SETTINGS_VIEW_CERTIFICATE"/>
#ifndef SLIM_WAP_MMS
    <SCREEN id="SCR_ID_BRW_PAGE_ACTIONS"/>
#endif
    <SCREEN id="SCR_ID_BRW_EDIT_STORE_OFFLINE"/>
    <SCREEN id="SCR_ID_BRW_OBJECT_PROPERTIES"/>
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    <SCREEN id="SCR_ID_BRW_BKM_CREATE_FOLDER"/>
#endif
    <SCREEN id="SCR_ID_BRW_PAGE_OBJECT_TYPES"/>
    <SCREEN id="SCR_ID_BRW_PAGE_OBJECTS"/>
    <SCREEN id="SCR_ID_BRW_PAGE_OBJECTS_OPTIONS"/>
    <SCREEN id="SCR_ID_BRW_SHOW_AUTH_DIALOG"/>
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    <SCREEN id="SCR_ID_BRW_RECENT_PAGES_HOST"/>
    <SCREEN id="SCR_ID_BRW_RECENT_PAGE_HOST_OPTIONS"/>
#endif
    <SCREEN id="SCR_ID_BRW_BUSY_SCREEN"/>
#ifndef __MMI_BRW_SLIM_BOOKMARK_SUPPORT__
    <SCREEN id="SCR_ID_BRW_VIEW_BOOKMARK"/>
#endif
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
     <SCREEN id="SCR_ID_BRW_BOOKMARK_BROWSE_PATH"/>
    <SCREEN id="SCR_ID_BRW_BOOKMARK_BROWSE_PATH_OPTIONS"/>
#endif
    <SCREEN id="SCR_ID_BRW_SAVE_TO_BOOKMARK"/>
    <SCREEN id="SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR"/>
#ifdef __MMI_BRW_BKM_INTERFACE_SUPPORT__
    <SCREEN id="SCR_ID_BRW_SELECT_BOOKMARK"/>
#endif
#if defined(__MMI_BRW_URL_AUTO_COMPLETION__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    <SCREEN id="SCR_ID_BRW_EDITOR_OPTION"/>
#endif
    <SCREEN id="SCR_ID_BRW_DUMMY"/>
    <SCREEN id="SCR_ID_BRW_TEMP_BUSY_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_SECURITY_CONFIRMATION_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_OUT_OF_MEM_CONFIRMATION_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_UHA_URI_SCHEME_CONFIRM_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_PAGE_SIZE_CHECK"/>
    <SCREEN id="SCR_ID_BRW_LOADING_TIME_CHECK"/>
    <SCREEN id="SCR_ID_BRW_UPLOAD_PROGRESS_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_UPLOAD_CANCEL_CONFIRMATION_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_SELECT_FILE_DUMMY_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_POST_SESSION_INFO"/>
#ifdef __OP01__
	<SCREEN id="SCR_ID_BRW_VIEW_URL"/>
#endif /* __OP01__*/
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
	<SCREEN id="SCR_ID_BRW_LAUNCH_PAGE"/>
	<SCREEN id="SCR_ID_BRW_LAUNCH_PAGE_OPTIONS"/>
	<SCREEN id="SCR_ID_BRW_EDIT_SHORTCUT"/>
#endif /* __MMI_Q05A_LAUNCH_SCREEN__*/
    /* please add all screen IDs above this line */

    <SCREEN id="SCR_ID_BRW_SPLASH_SCREEN"/>
    <SCREEN id="SCR_ID_BRW_EDIT_URL"/>
    <SCREEN id="SCR_ID_BRW_EDIT_BOOKMARK_NAMING_RULE"/>
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    <SCREEN id="SCR_ID_BRW_EDIT_HOMEPAGE"/>
#endif
    <SCREEN id="SCR_ID_BRW_LAST_SCREEN_ID"/>
/* Event Handlers Begin*/
#if defined(__MMI_UCM__) && defined(__MMI_BACKGROUND_CALL__)
	<RECEIVER id="EVT_ID_SRV_UCM_APP_EXIT_QUERY" proc="mmi_brw_app_if_ucm_exit_callback"/>
#endif

	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_brw_app_if_memory_card_plug_out"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_brw_app_if_memory_card_plug_out"/>
	<RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_brw_app_if_idle_deinit"/>
/*****************************Browser Srv events ***********************************************/
	<SENDER id="EVT_ID_SRV_BRW_ERROR_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SHOW_POPUP" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_UPDATE_TITLE" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_DOC_INFO_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SELECT_FILE_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_URI_REQ_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_SHOW_AUTH_DLG" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_START_BROWSER_ACTION_IND" hfile="BrowserSrvGprot.h"/>
#ifdef __SAT__
	<SENDER id="EVT_ID_SRV_BRW_SAT_LAUNCH_REQ" hfile="BrowserSrvGprot.h"/>
#endif
	<SENDER id="EVT_ID_SRV_BRW_BKM_PROVISIONING_IND" hfile="BrowserSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_BRW_OPEN_BEARER_IND" hfile="BrowserSrvGprot.h"/>

	<RECEIVER id="EVT_ID_SRV_BRW_ERROR_IND" proc="mmi_brw_srv_hdlr_error_ind_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_SHOW_POPUP" proc="mmi_brw_srv_hdlr_error_popup_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_UPDATE_TITLE" proc="mmi_brw_srv_hdlr_notify_app_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND" proc="mmi_brw_srv_hdlr_start_transaction_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND" proc="mmi_brw_srv_hdlr_end_transaction_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND" proc="mmi_brw_srv_hdlr_continue_transaction_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_DOC_INFO_IND" proc="mmi_brw_srv_hdlr_document_info_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG" proc="mmi_brw_srv_hdlr_sec_confirm_dlg_proc"/>
	<RECEIVER id="EVT_ID_SRV_BRW_SELECT_FILE_IND" proc="mmi_brw_srv_hdlr_select_file_proc"/>
#ifdef __MMI_URI_AGENT__
	<RECEIVER id="EVT_ID_SRV_BRW_URI_REQ_IND" proc="mmi_brw_srv_hdlr_uri_ind_proc"/>
#endif /* #ifdef __MMI_URI_AGENT__ */
	<RECEIVER id="EVT_ID_SRV_BRW_SHOW_AUTH_DLG" proc="mmi_brw_srv_hdlr_show_auth_dialog_proc"/>
	<RECEIVER id="EVT_ID_SRV_START_BROWSER_ACTION_IND" proc="mmi_brw_srv_hdlr_start_browser_action_proc"/>s
#ifdef __SAT__
	<RECEIVER id="EVT_ID_SRV_BRW_SAT_LAUNCH_REQ" proc="mmi_brw_srv_hdlr_sat_launch_req_proc"/>
#endif

#ifdef __MMI_USB_SUPPORT__
	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_brw_app_if_enter_usb_mode"/>
#endif

#if (defined(__SIM_HOT_SWAP_SUPPORT__)|| defined(__SIM_RECOVERY_ENHANCEMENT__))
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_brw_app_if_sim_event_detected_proc"/>
#endif
	<RECEIVER id="EVT_ID_SRV_BRW_BKM_PROVISIONING_IND" proc="mmi_brw_app_if_bookmark_provisioning_handler"/>
	<RECEIVER id="EVT_ID_SRV_BRW_OPEN_BEARER_IND" proc="mmi_brw_srv_hdlr_open_bearer"/>


/* Event Handlers End*/

</APP>

<FILE_TYPES>
    #ifdef OBIGO_Q05A
    <FILE_GROUP_TYPE type_id="FMGR_GROUP_BOOKMARK" small_icon="IMG_ID_BRW_FMGR_FILE_TYPE_HTM" option="MENU_ID_BRW_WEB_FILE_OPTIONS">
        <FILE_TYPE type_id="FMGR_TYPE_WML" extension="WML" large_icon="IMG_ID_BRW_FMGR_WML_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_HTML" extension="HTML" large_icon="IMG_ID_BRW_FMGR_HTML_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_HTM" extension="HTM" large_icon="IMG_ID_BRW_FMGR_HTM_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_XHTML" extension="XHTML" large_icon="IMG_ID_BRW_FMGR_XHTML_LARGE_TYPE"/>
        <FILE_TYPE type_id="FMGR_TYPE_WMLC" extension="WMLC" large_icon="IMG_ID_BRW_FMGR_WML_LARGE_TYPE"/>
    </FILE_GROUP_TYPE>
    #endif

#ifdef __MMI_VBOOKMARK__
#ifndef __MMI_SLIM_FILE_MANAGER__
    <FILE_TYPE type_id="FMGR_TYPE_URL" extension="URL" small_icon="IMG_ID_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK" large_icon="IMG_ID_BRW_FMGR_FILE_TYPE_URL" option="MENU_ID_BRW_FMGR_BOOKMARK_OPTIONS" send_option ="MENU_ID_BRW_FMGR_BOOKMARK_SEND_OPTIONS"/>
    <FILE_TYPE type_id="FMGR_TYPE_VBM" extension="VBM" small_icon="IMG_ID_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK" large_icon="IMG_ID_BRW_FMGR_FILE_TYPE_VBM" option="MENU_ID_BRW_FMGR_BOOKMARK_OPTIONS" send_option ="MENU_ID_BRW_FMGR_BOOKMARK_SEND_OPTIONS"/>
#else
    <FILE_TYPE type_id="FMGR_TYPE_URL" extension="URL" small_icon="IMG_ID_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK" option="MENU_ID_BRW_FMGR_BOOKMARK_OPTIONS" send_option ="MENU_ID_BRW_FMGR_BOOKMARK_SEND_OPTIONS"/>
    <FILE_TYPE type_id="FMGR_TYPE_VBM" extension="VBM" small_icon="IMG_ID_BRW_FMGR_ICON_FILE_TYPE_VBOOKMARK" option="MENU_ID_BRW_FMGR_BOOKMARK_OPTIONS" send_option ="MENU_ID_BRW_FMGR_BOOKMARK_SEND_OPTIONS"/>
#endif
#endif

#ifdef OBIGO_Q05A
    <FILE_OPTION_HDLR option="MENU_ID_BRW_WEB_PAGE_OPEN" enabler="mmi_brw_app_if_web_page_open_enabler" handler="mmi_brw_app_if_web_page_open_handler"/>
#endif /* OBIGO_Q05A */
#if defined (__MMI_VBOOKMARK__ )
    <FILE_OPTION_HDLR option="MENU_ID_BRW_FMGR_BOOKMARK_GOTO" enabler="mmi_brw_app_if_fmgr_bookmark_enabler" handler="mmi_brw_app_if_fmgr_bookmark_options_handler"/>
#endif
#if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__)
    <FILE_OPTION_HDLR option="MENU_ID_BRW_FMGR_BOOKMARK_OPEN" enabler="mmi_brw_app_if_fmgr_bookmark_enabler" handler="mmi_brw_app_if_fmgr_bookmark_options_handler"/>
    <FILE_OPTION_HDLR option="MENU_ID_BRW_FMGR_BOOKMARK_SEND_BY_SMS" enabler="mmi_brw_app_if_fmgr_bookmark_enabler" handler="mmi_brw_app_if_fmgr_bookmark_options_handler"/>    
#endif
</FILE_TYPES>

#endif  /*  __MMI_BROWSER_2__  */



