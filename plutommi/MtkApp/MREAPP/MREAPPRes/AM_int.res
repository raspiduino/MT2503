#include "MMI_features.h"
#include "custresdef.h"
#include "AMSwitch.h"
#include "vmswitch.h"
#include "GlobalResDef.h"
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_AM" name="STR_ID_APP_MRE_AM">
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MRE_AM__

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
   #if defined( __PLUTO_MMI_PACKAGE__) && defined(__MMI_FILE_MANAGER__) && !defined(__IOT__)
    <INCLUDE file="mmi_rp_app_filemanager_def.h"/>
    #endif
    #if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
    <MEMORY heap="$(MMI_AM_MAX_DYN_MEM_SIZE)" inc="AMGprot.h"/>
    <APPCONCURRENT concurrent_w_order="APP_MRE, APP_AM"/>
   #endif

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id ="STR_ID_APP_MRE_AM"/>
    <STRING id="STR_ID_AM_UNINSTALL"/>
    <STRING id ="STR_ID_AM_APP_NAME"/>
    <STRING id="STR_ID_AM_OPTION_CREATE_SHORTCUT"/>
    <STRING id="STR_ID_AM_OPTION_DELETE_SHORTCUT"/>
    <STRING id="STR_ID_AM_DETAILS_INFO"/>
    <STRING id="STR_ID_AM_DETAILS_SIZE"/>
    <STRING id="STR_ID_AM_DETAILS_PATH"/>
    <STRING id="STR_ID_AM_DETAILS_DEVELOPER"/>
    <STRING id="STR_ID_AM_DETAILS_TEL"/>
    <STRING id="STR_ID_AM_DETAILS_STORAGE_PHONE"/>
    <STRING id="STR_ID_AM_DETAILS_STORAGE_ROM"/>
    <STRING id="STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD"/>
    <STRING id="STR_ID_AM_CDR_NEW_VERSION"/>
    <STRING id="STR_ID_AM_CDR_UPDATE_SUCC"/>
    <STRING id="STR_ID_AM_CDR_UPDATE_FAIL"/>
    <STRING id="STR_ID_AM_USER_BALANCE"/>
    <STRING id="STR_ID_AM_FILE_OVERFLOW"/>
    <STRING id="STR_ID_AM_MRE_INIT_FAILURE"/>
    <STRING id="STR_ID_AM_DELETE_APP_QUERY"/>
    <STRING id="STR_ID_AM_DELETE_APP_FAILURE"/>
    <STRING id="STR_ID_AM_SHORTCUT_SET_DONE"/>
    <STRING id="STR_ID_AM_SHORTCUT_SET_DUPLICATE"/>
    <STRING id="STR_ID_AM_SHORTCUT_OLD_VER_SET_FAILURE"/>
    <STRING id="STR_ID_AM_SHORTCUT_SET_FAILURE"/>
    <STRING id="STR_ID_AM_SHORTCUT_SET_MAX"/>
    <STRING id="STR_ID_AM_SHORTCUT_DEL_QUERY"/>
    <STRING id="STR_ID_AM_SHORTCUT_DEL_DONE"/>
    <STRING id="STR_ID_AM_SHORTCUT_HS_DEL"/>
    <STRING id="STR_ID_AM_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_FILE_NOT_EXIST"/>
    <STRING id="STR_ID_AM_TAG_ERR_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_DATE_ERR_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_INVALID_SIM_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_CERT_EXPIRED_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_POPUP_LIMITATION_APP"/>
	//<STRING id="STR_ID_VAPP_AM_POPUP_NO_AUTH"/>
    //<STRING id="STR_ID_VAPP_AM_INSTALL_POPUP_NO_AUTH"/>
    <STRING id="STR_ID_AM_APP_NAME_DEFAULT"/>
    <STRING id="STR_ID_AM_APP_NAME_MRE20"/>


    <!-----------------------------------------------------DLA of String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_AM_DLA_OPTION_LAUNCH"/>
    <STRING id="STR_ID_AM_DLA_OPTION_DOWNLOAD_STATUS"/>
    <STRING id="STR_ID_AM_DLA_OPTION_DOWNLOAD_LIST"/>
    <STRING id="STR_ID_AM_DLA_LIST_OPTION_RETRY"/>
    <STRING id="STR_ID_AM_DLA_POP_LIST_FULL"/>
    <STRING id="STR_ID_AM_DLA_TXT_STATUS"/>
    <STRING id="STR_ID_AM_DLA_TXT_EXIST"/>
    <STRING id="STR_ID_AM_DLA_TXT_TOTAL"/>
    <STRING id="STR_ID_AM_DLA_TXT_REASON"/>
    <STRING id="STR_ID_AM_DLA_TXT_DOWNLOADING"/>
    <STRING id="STR_ID_AM_DLA_TXT_WAITING"/>
    <STRING id="STR_ID_AM_DLA_TXT_PAUSED"/>
    <STRING id="STR_ID_AM_DLA_TXT_FAILURE"/>
    <STRING id="STR_ID_AM_DLA_TXT_FAILED_TO_DOWNLOAD"/>

    <!------------------------------------------------------PSMGR of Other Resource---------------------------------------------------------->
    <STRING id="STR_ID_AM_PSMGR_TXT_TITLE"/>
    <STRING id="STR_ID_AM_PSMGR_TXT_OPTION_LAUNCH"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    //<IMAGE id="IMG_ID_AM_LOADING" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Loading.bmp"</IMAGE>
    <IMAGE id="IMG_ID_AM_TITLE" >CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MRE.bmp"</IMAGE>
    <IMAGE id="IMG_ID_AM_STATE_UNDOWNLOAD" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Undownload.png"</IMAGE>
    <IMAGE id="IMG_ID_AM_STATE_BG" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_AM_STATE_SHORTCUT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Shortcut.png"</IMAGE>
    #ifdef __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_ID_AM_HIGHLIGHT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Highlight.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_AM_HIGHLIGHT_SCROLLBAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Highlight.9slice.png"</IMAGE>
    #else
    <IMAGE id="IMG_ID_AM_HIGHLIGHT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Highlight.png"</IMAGE>
    <IMAGE id="IMG_ID_AM_HIGHLIGHT_SCROLLBAR" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Highlight_Scrollbar.png"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_AM_APP_DEFAULT" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Default.gif"</IMAGE>

      /***********************************************/
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_AM"/>
    <SCREEN id="SCR_ID_AM_LOADING"/>
    <SCREEN id="SCR_ID_AM_LAUNCH_APP_LOADING"/>
    <SCREEN id="SCR_ID_AM_MAIN"/>
    <SCREEN id="SCR_ID_AM_UPDATE_CDR"/>
    <SCREEN id="SCR_ID_AM_UPDATE_CDR_WAIT"/>
    <SCREEN id="SCR_ID_AM_DETAILS"/>

    <!------------------------------------------------------DLA of Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_DLA_APP"/>
    <SCREEN id="SCR_ID_DLA_MAIN"/>
    <SCREEN id="SCR_ID_DLA_LIST"/>
    <SCREEN id="SCR_ID_DLA_LIST_DETAIL"/>

    <!------------------------------------------------------PSMGR of Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_AM_PSMGR_APP"/>
    <SCREEN id="SCR_ID_AM_PSMGR_MAIN"/>
    

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="MENU_ID_AM_OPTION_DOWNLOAD" str="STR_GLOBAL_DOWNLOAD"/>
    <MENUITEM id="MENU_ID_AM_OPTION_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_AM_OPTION_CREATE_SHORTCUT" str="STR_ID_AM_OPTION_CREATE_SHORTCUT"/>
    <MENUITEM id="MENU_ID_AM_OPTION_DELETE_SHORTCUT" str="STR_ID_AM_OPTION_DELETE_SHORTCUT"/>
    <MENUITEM id="MENU_ID_AM_OPTION_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_AM_OPTION_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_AM_OPTION_UNINSTALL" str="STR_ID_AM_UNINSTALL"/>
    <MENUITEM id="MENU_ID_AM_OPTION_SETTINGS" str="STR_GLOBAL_SETTINGS"/>
    <MENUITEM id="MENU_ID_AM_OPTION_PSMGR" str="STR_ID_AM_PSMGR_TXT_TITLE"/>
    <MENU id="MENU_ID_AM_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_AM_OPTION_OPEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AM_OPTION_CREATE_SHORTCUT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AM_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AM_OPTION_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AM_OPTION_SETTINGS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AM_OPTION_PSMGR</MENUITEM_ID>
    </MENU>
    <!------------------------------------------------------DLA of Menu Resource Area------------------------------------------------------>

    
    <MENU id="MENU_ID_DLA_OPTION_MAIN" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_DLA_OPTION_MAIN_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DLA_OPTION_MAIN_LIST</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_DLA_OPTION_MAIN_DETAIL" str="STR_ID_AM_DLA_OPTION_DOWNLOAD_STATUS"/>
    <MENUITEM id="MENU_ID_DLA_OPTION_MAIN_LIST" str="STR_ID_AM_DLA_OPTION_DOWNLOAD_LIST"/>



    
    <MENU id="MENU_ID_DLA_OPTION_LIST" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_DLA_OPTION_LIST_DETAIL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DLA_OPTION_LIST_RETRY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DLA_OPTION_LIST_PAUSE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DLA_OPTION_LIST_RESUME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_DLA_OPTION_LIST_REMOVE</MENUITEM_ID>
        
        
    </MENU>    
    <MENUITEM id="MENU_ID_DLA_OPTION_LIST_NONE" str="STR_GLOBAL_RENAME"/>
    <MENUITEM id="MENU_ID_DLA_OPTION_LIST_DETAIL" str="STR_ID_AM_DLA_OPTION_DOWNLOAD_STATUS"/>
    <MENUITEM id="MENU_ID_DLA_OPTION_LIST_RETRY" str="STR_ID_AM_DLA_LIST_OPTION_RETRY"/>
    <MENUITEM id="MENU_ID_DLA_OPTION_LIST_PAUSE" str="STR_GLOBAL_PAUSE"/>
    <MENUITEM id="MENU_ID_DLA_OPTION_LIST_RESUME" str="STR_GLOBAL_RESUME"/>
    <MENUITEM id="MENU_ID_DLA_OPTION_LIST_REMOVE" str="STR_GLOBAL_REMOVE"/>
    

    <!------------------------------------------------------PSMGR of Menu Resource Area------------------------------------------------------>
    <MENU id="MENU_ID_AM_PSMGR_OPTION_BG_LIST" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_AM_PSMGR_OPTION_BG_LIST_LAUNCH</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AM_PSMGR_OPTION_BG_LIST_EXIT</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_AM_PSMGR_OPTION_BG_LIST_LAUNCH" str="STR_ID_AM_PSMGR_TXT_OPTION_LAUNCH"/>
    <MENUITEM id="MENU_ID_AM_PSMGR_OPTION_BG_LIST_EXIT" str="STR_GLOBAL_EXIT"/>

#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_am_enter_usb_mode_ms_callback"/>

<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_am_handle_event"/>
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_am_handle_event"/>
<RECEIVER id="EVT_ID_SRV_APPMGR_INSTALL_PACKAGE" proc="mmi_am_handle_event"/>
<RECEIVER id="EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE" proc="mmi_am_handle_event"/>

/***MRE Service***/
<SENDER id="EVT_ID_MRE_DLTM_LIST_CHANGE" hfile="MreDLTaskMgr.h"/>
<RECEIVER id="EVT_ID_MRE_DLTM_LIST_CHANGE" proc="mmi_am_dla_ds_cb"/>

#endif
#endif /* __MRE_AM__ */

//#ifndef __MMI_MRE_DISABLE_FMGR__
//<STRING id="STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE"/>
//#endif
#ifdef __MRE_APP_LAUNCH__

    <SCREEN id="GRP_ID_AM"/>
    <SCREEN id="SCR_ID_AM_LAUNCH_APP_LOADING"/>
    <STRING id="STR_ID_AM_FILE_NOT_EXIST"/>    
    <STRING id="STR_ID_AM_FAIL_TO_START"/>
//    <STRING id="STR_ID_AM_NOT_ENOUGH_MEMORY"/>
	<STRING id="STR_ID_VAPP_AM_POPUP_NO_AUTH"/>
    <STRING id="STR_ID_VAPP_AM_INSTALL_POPUP_NO_AUTH"/>
    <STRING id="STR_ID_AM_TAG_ERR_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_DATE_ERR_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_INVALID_SIM_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_CERT_EXPIRED_FAIL_TO_START"/>
    <STRING id="STR_ID_AM_POPUP_LIMITATION_APP"/>
    <STRING id="STR_ID_AM_FILE_OVERFLOW"/>
   
    <IMAGE id="IMG_ID_AM_LOADING" >CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_Loading.bmp"</IMAGE>

#endif /* __MRE_APP_LAUNCH__ */
#endif /* __PLUTO_MMI_PACKAGE__ */
</APP>

