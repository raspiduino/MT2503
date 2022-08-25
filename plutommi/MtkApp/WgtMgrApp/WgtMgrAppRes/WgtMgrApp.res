/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_WGTMGR">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    #ifdef __PLUTO_MMI_PACKAGE__
    <INCLUDE file="mmi_rp_app_filemanager_def.h"/>
    #endif

#ifdef __MMI_GADGET_SUPPORT__

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_WGTMGR_WIDGET_MANAGER"/>
    <STRING id="STR_ID_WGTMGR_PHONE_WIDGETS"/>
    <STRING id="STR_ID_WGTMGR_DOWNLOADED_WIDGETS"/>
    <STRING id="STR_ID_WGTMGR_ENABLE"/>
    <STRING id="STR_ID_WGTMGR_DISABLE"/>
    <STRING id="STR_ID_WGTMGR_ENABLED"/>
    <STRING id="STR_ID_WGTMGR_DISABLED"/>
    <STRING id="STR_ID_WGTMGR_DELETE_THIS_WIDGET"/>
    <STRING id="STR_ID_WGTMGR_NAME"/>
    <STRING id="STR_ID_WGTMGR_INSTALLED_TIME"/>
    <STRING id="STR_ID_WGTMGR_NETWORK_ACCESS"/>
    <STRING id="STR_ID_WGTMGR_ALLOW"/>
    <STRING id="STR_ID_WGTMGR_ALWAYS_ASK"/>
    <STRING id="STR_ID_WGTMGR_CANCELED"/>
    <STRING id="STR_ID_WGTMGR_WIDGET_IS_CORRUPTED"/>
    <STRING id="STR_ID_WGTMGR_WIDGET_IS_NOT_VALID"/>
    <STRING id="STR_ID_WGTMGR_STOP_INSTALLATION"/>
    <STRING id="STR_ID_WGTMGR_VERSION"/>
    <STRING id="STR_ID_WGTMGR_QUERY_FOR_INSTALL"/>
    <STRING id="STR_ID_WGTMGR_INSTALLING"/>    
    <STRING id="STR_ID_WGTMGR_INSTALLED"/>
    <STRING id="STR_ID_WGTMGR_VERSION_FOUND"/>
    <STRING id="STR_ID_WGTMGR_CURRENT_VERSION"/>
    <STRING id="STR_ID_WGTMGR_NEW_VERSION"/>
    <STRING id="STR_ID_WGTMGR_OLD_VERSION"/>
    <STRING id="STR_ID_WGTMGR_ALREADY_INSTALLED"/>
    <STRING id="STR_ID_WGTMGR_REPLACE_WIDGET"/>
    <STRING id="STR_ID_WGTMGR_OVER_MAX_INSTALL"/>
    <STRING id="STR_ID_WGTMGR_CONTINUE_INSTALL"/>
    <STRING id="STR_ID_WGTMGR_WGT_NAME"/>
    <STRING id="STR_ID_WGTMGR_WGT_AUTHOR"/>
    <STRING id="STR_ID_WGTMGR_WGT_COPYRIGHT"/>
    <STRING id="STR_ID_WGTMGR_OVER_MAX_ENABLED"/>
    <STRING id="STR_ID_WGTMGR_DISK_SPACE_IS_NOT_ENOUGH"/>
    <STRING id="STR_ID_WGTMGR_DECLARE_STATEMENT"/>
    <STRING id="STR_ID_WGTMGR_INSTALLING_WIDGETS"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    /*
    <IMAGE id="IMG_ID_TEMPLATE_01" >CUST_IMG_PATH"\\\\MainLCD\\\\Test\\\\01.bmp"</IMAGE>
    <IMAGE id="IMG_ID_TEMPLATE_02" >CUST_IMG_PATH"\\\\MainLCD\\\\Test\\\\02.bmp"</IMAGE>
    <IMAGE id="IMG_ID_TEMPLATE_03" force_type="FORCE_AB2">CUST_IMG_PATH"\\\\MainLCD\\\\Test\\\\03.bmp"</IMAGE>
     */
    /* Example: How to use compile option in path, __MMI_RES_TYPE_WALLPAPER__ is defined in mmi_features.h */
    /* #define __MMI_RES_TYPE__ ".gif" */

    /* For the detail of scope="XML" please check user manual */

    <IMAGE id="IMG_ID_WGTMGR_APP">CUST_IMG_PATH"\\\\MainLCD\\\\WgtMgr\\\\WM_SB.bmp"</IMAGE>
    <IMAGE id="IMG_ID_WGTMGR_PHONE_WIDGETS">CUST_IMG_PATH"\\\\MainLCD\\\\WgtMgr\\\\WM_Tab_Phone.bmp"</IMAGE>
    <IMAGE id="IMG_ID_WGTMGR_DOWNLOADED_WIDGETS">CUST_IMG_PATH"\\\\MainLCD\\\\WgtMgr\\\\WM_Tab_Download.bmp"</IMAGE>
    <IMAGE id="IMG_ID_WGTMGR_ENABLED">CUST_IMG_PATH"\\\\MainLCD\\\\WgtMgr\\\\WM_SB_Enable.bmp"</IMAGE>
    <IMAGE id="IMG_ID_WGTMGR_WEB">CUST_IMG_PATH"\\\\MainLCD\\\\WgtMgr\\\\WM_SB_Web.bmp"</IMAGE>

    /* <IMAGE id="VAPP_HS_IMG_SC_WIDGET_MANAGER">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Shortcut\\\\SC_WgtMgr.png"</IMAGE> */
    <IMAGE id="IMG_ID_FMGR_FILE_TYPE_WGT">CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_WgtMgr.gif"</IMAGE>
    <IMAGE id="IMG_ID_FMGR_ICON_FILE_TYPE_WGT">CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SMALL_WgtMgr.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */    
    <MENUITEM id="MENU_ID_WGTMGR_ENABLE" str="STR_ID_WGTMGR_ENABLE"/>
    <MENUITEM id="MENU_ID_WGTMGR_DISABLE" str="STR_ID_WGTMGR_DISABLE"/>
    <MENUITEM id="MENU_ID_WGTMGR_DELETE" str="STR_GLOBAL_DELETE"/>
    /*<MENUITEM id="MENU_ID_WGTMGR_SETTINGS" str="STR_GLOBAL_SETTINGS"/>*/
    <MENUITEM id="MENU_ID_WGTMGR_SORT_BY_NAME" str="STR_ID_WGTMGR_NAME"/>
    <MENUITEM id="MENU_ID_WGTMGR_SORT_BY_INSTALLED_TIME" str="STR_ID_WGTMGR_INSTALLED_TIME"/>
    <MENUITEM id="MENU_ID_FMGR_WGT_INSTALL" str="STR_GLOBAL_INSTALL"/>
    /*<MENUITEM id="MENU_ID_WGTMGR_NETWORK_ACCESS" str="STR_ID_WGTMGR_NETWORK_ACCESS"/>*/
    <MENUITEM id="MENU_ID_WGTMGR_DATA_ACCOUNT" str="STR_GLOBAL_DATA_ACCOUNT"/>
    
    <!--Menu Tree Area-->
    <MENU id="MENU_ID_WGTMGR" str="STR_ID_WGTMGR_WIDGET_MANAGER">
        <MENUITEM_ID>MENU_ID_FMGR_WGT_INSTALL</MENUITEM_ID>     
    </MENU>

    <MENU id="MENU_ID_WGTMGR_OPTIONS" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_WGTMGR_ENABLE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WGTMGR_DISABLE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WGTMGR_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WGTMGR_SORT_BY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WGTMGR_SETTINGS</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_WGTMGR_SORT_BY" str="STR_GLOBAL_SORT_BY" flag="MMI_RG_MENU_FLAG_RADIO">
        <MENUITEM_ID>MENU_ID_WGTMGR_SORT_BY_NAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_WGTMGR_SORT_BY_INSTALLED_TIME</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_WGTMGR_SETTINGS" str="STR_GLOBAL_SETTINGS">
        <MENUITEM_ID>MENU_ID_WGTMGR_NETWORK_ACCESS</MENUITEM_ID>     
        <MENUITEM_ID>MENU_ID_WGTMGR_DATA_ACCOUNT</MENUITEM_ID> 
    </MENU>
    
    <MENU id="MENU_ID_WGTMGR_NETWORK_ACCESS" str="STR_ID_WGTMGR_NETWORK_ACCESS" flag="RADIO">
        <MENUITEM id="MENU_ID_WGTMGR_NETWORK_ACCESS_ALLOW" str="STR_ID_WGTMGR_ALLOW"/>
        <MENUITEM id="MENU_ID_WGTMGR_NETWORK_ACCESS_ALWAYS_ASK" str="STR_ID_WGTMGR_ALWAYS_ASK"/>
    </MENU>

    <MENU id="MENU_ID_FMGR_WGT_TYPE_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_FMGR_WGT_INSTALL</MENUITEM_ID>
        #ifdef __PLUTO_MMI_PACKAGE__
        <MENUSET_ID>MENU_ID_FMGR_GENERAL_OPTION</MENUSET_ID>
        #endif
    </MENU>   


    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <SCREEN id="GRP_ID_WGTMGR_OPTIONS"/>
    <SCREEN id="GRP_ID_WGTMGR_INSTALL"/>
    <SCREEN id="GRP_ID_WGTMGR_SETTINGS"/>
    <SCREEN id="SCR_ID_WGTMGR_MAIN"/>
    <SCREEN id="SCR_ID_WGTMGR_TAB_PHONE_WIDGETS"/>
    <SCREEN id="SCR_ID_WGTMGR_TAB_DOWNLOADED_WIDGETS"/>
    <SCREEN id="SCR_ID_WGTMGR_OPTIONS"/>
    <SCREEN id="SCR_ID_WGTMGR_INSTALL"/>
    <SCREEN id="SCR_ID_WGTMGR_PLEASE_WAIT"/>
    <SCREEN id="SCR_ID_WGTMGR_DELETING"/>    
    <SCREEN id="SCR_ID_WGTMGR_INSTALLING"/>
    <SCREEN id="SCR_ID_WGTMGR_STATEMENT"/>

#endif /* __MMI_GADGET_SUPPORT__ */
</APP>



<!------------------------------------------------------File type---------------------------------------------------------->    


#ifdef __MMI_GADGET_SUPPORT__
<FILE_TYPES>
    <FILE_TYPE_INC file="mmi_rp_app_wgtmgr_def.h"/>
    <FILE_TYPE type_id="FMGR_TYPE_WGT"
               extension="WGT"
               large_icon="IMG_ID_FMGR_FILE_TYPE_WGT"
               small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_WGT"
               option="MENU_ID_FMGR_WGT_TYPE_OPTIONS">
    </FILE_TYPE>

    <FILE_OPTION_HDLR option="MENU_ID_FMGR_WGT_INSTALL" handler="mmi_wgtmgr_install_wgt"/>
</FILE_TYPES>
#endif /* __MMI_GADGET_SUPPORT__ */

