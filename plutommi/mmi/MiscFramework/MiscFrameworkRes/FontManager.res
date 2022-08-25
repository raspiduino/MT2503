/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_FONT_MANAGER">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,mmi_rp_file_type_def.h,SettingResDef.h,FileMgrResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    <STRING id="STR_ID_FONT_MGR_UNINSTALL"/>
    <STRING id="STR_ID_FONT_MGR_SYSTEM_FONT"/>
    <STRING id="STR_ID_FONT_MGR_INVALID_FONT"/>
    <STRING id="STR_ID_FONT_MGR_CHANGE_PRIORITY"/>
    <STRING id="STR_ID_FONT_MGR_OUT_OF_MEMORY"/>
    <STRING id="STR_ID_FONT_MGR_ACTIVATE_QUERY"/>
    <STRING id="STR_ID_FONT_MGR_LIST_FONT"/>
    <STRING id="STR_ID_FONT_MGR_UNINSTALL_QUERY"/>
    <STRING id="STR_ID_FONT_MGR_REACH_MAX_FONT_NUM"/>
    <STRING id="STR_ID_FONT_MGR_ADD_NEW_FONT"/>
    <STRING id="STR_ID_FONT_MGR_INSTALLED_FONT"/>
    <STRING id="STR_ID_FONT_MGR_INSTALLED_FONT_REMOVED"/>
    <STRING id="STR_ID_FONT_MGR_UNINSTALL_FAIL"/>
    <STRING id="STR_ID_FONT_MGR_USB_PLUG_IN"/>
    <STRING id="STR_ID_FONT_MGR_USB_PLUG_OUT"/>
    <STRING id="STR_ID_FONT_MGR_RESET_TO_SYSTEM_FONT"/>
    <STRING id="STR_ID_FONT_MGR_INVALID_ACCESS"/>
    <STRING id="STR_ID_FONT_MGR_READ_TIME_OUT"/>
    <STRING id="STR_ID_FONT_MGR_LANG_CHANGE_SUCCESS"/>
    <STRING id="STR_ID_FONT_MGR_LANG_CHANGE_FAIL"/>
    <STRING id="STR_ID_FONT_MGR_ACTIVATE_GOTO_HOME_QUERY"/>
    <STRING id="STR_ID_FONT_MGR_UNINSTALL_GOTO_HOME_QUERY"/>
    <STRING id="STR_ID_FONT_MGR_GOTO_HOME_QUERY"/>
    <STRING id="STR_ID_FONT_MGR_UNINSTALLING_FONT"/>
    <STRING id="STR_ID_FONT_MGR_CHANGING_FONT_PRIORITY"/>
    #endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* Example: How to use compile option in path, __MMI_RES_TYPE_WALLPAPER__ is defined in mmi_features.h */

    /* For the detail of scope="XML" please check user manual */
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    <IMAGE id="IMG_ID_FMGR_FILE_TYPE_VECTOR_FONT">CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LITTF.gif"</IMAGE>
    <IMAGE id="IMG_ID_FMGR_ICON_FILE_TYPE_VECTOR_FONT">CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SITTF.bmp"</IMAGE>
    #endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

#ifndef __COSMOS_MMI_PACKAGE__
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    <MENUITEM id="MENU_ID_FONT_MGR_SETTING" str="STR_ID_FONT_MGR_LIST_FONT"/>
    <MENUITEM id="MENU_FMGR_VECTOR_FONT_OPTION_INSTALL" str="STR_GLOBAL_INSTALL"/>
    <MENUITEM id="MENU_ID_FONT_MGR_OPTIONS" str="STR_GLOBAL_OPTIONS"/>
    <MENU id="MENU_ID_FMGR_VECTOR_FONT_TYPE_OPTIONS" type="OPTION" str="STR_ID_FONT_MGR_LIST_FONT">
        <MENUITEM_ID>MENU_FMGR_VECTOR_FONT_OPTION_INSTALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_USE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_FOLDER_CREATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MORE_RITS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_SORT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MARK_SEVERAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_COPY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MOVE</MENUITEM_ID>
	#ifndef __MMI_SLIM_FILE_MANAGER__ 
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE_ALL</MENUITEM_ID>
	#endif
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DETAIL</MENUITEM_ID>
    </MENU>
    #endif
#endif

    <!--Menu Tree Area-->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
#ifndef __COSMOS_MMI_PACKAGE__
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    <FILE_TYPES>
    <FILE_GROUP_TYPE type_id="FMGR_TYPE_GRP_VECTOR_FONT"
        small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_VECTOR_FONT"
        option="MENU_ID_FMGR_VECTOR_FONT_TYPE_OPTIONS"
        >
    <FILE_OPTION_HDLR option="MENU_FMGR_VECTOR_FONT_OPTION_INSTALL" handler="mmi_font_mgr_option_handler"/>
    <FILE_TYPE type_id="FMGR_TYPE_TTF" extension="TTF" large_icon="IMG_ID_FMGR_FILE_TYPE_VECTOR_FONT"/>
    <FILE_TYPE type_id="FMGR_TYPE_CCC" extension="CCC" large_icon="IMG_ID_FMGR_FILE_TYPE_VECTOR_FONT"/>
    <FILE_TYPE type_id="FMGR_TYPE_STF" extension="STF" large_icon="IMG_ID_FMGR_FILE_TYPE_VECTOR_FONT"/>
    </FILE_GROUP_TYPE>
    </FILE_TYPES>
    #endif

    /* Screen ID */
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    <SCREEN id = "GRP_ID_FONT_MGR"/>
    <SCREEN id="SCR_ID_FONT_MGR_FONT_LIST"/>
    <SCREEN id="SCR_ID_FONT_MGR_FONT_LIST_OPTION"/>
    <SCREEN id="SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY"/>
    <SCREEN id="SCR_ID_FONT_MGR_ACTIVATE_QUERY"/>
    #endif

	#ifdef __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_fmgr_font_mgr_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_fmgr_font_mgr_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_fmgr_font_mgr_notify_hdlr"/>
	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_font_mgr_usb_ms_plug_in_hdlr"/>
	#endif /* __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__ */


#endif
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
	<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_font_mgr_usb_ms_plug_out_hdlr"/>
	#endif /* __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__ */

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_lang_err_memory_card_notify_silent_reboot_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_lang_err_memory_card_notify_silent_reboot_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_lang_err_memory_card_notify_silent_reboot_hdlr"/>
#endif

	<TIMER id="FONT_SILENT_REBOOT_TIMER"/>
</APP>

