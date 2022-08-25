#include "MMI_features.h"
#include "custresdef.h"

#if defined(__MMI_MRE_MSPACE__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MSPACE"
        package_name = "native.mtk.mspace"
        name = "STR_ID_MSPACE_NAME"                   
        img = "IMG_ID_MSPACE_MAIN_MENU_ICON"  
        launch = "mmi_mspace_start"              
>

    <MEMORY heap="$(MMI_MSPACE_MAX_DYN_MEM_SIZE)" inc="MSpaceGprot.h"/>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id ="STR_ID_MSPACE_NAME"/>
    <STRING id ="STR_ID_MSPACE_TITLE"/>
    <STRING id ="STR_ID_MSPACE_INSTALL"/>
    <STRING id ="STR_ID_MSPACE_UPDATE"/>
    <STRING id ="STR_ID_MSPACE_UPDATING"/>
    <STRING id ="STR_ID_MSPACE_CONNECT_SERVER_FAILED"/>
    <STRING id ="STR_ID_MSPACE_NO_APP"/>
    <STRING id ="STR_ID_MSPACE_RETRY"/>
    <STRING id ="STR_ID_MSPACE_DOWNLOADING"/>
    <STRING id ="STR_ID_MSPACE_DOWNLOAD_SUCCESS"/>
    <STRING id ="STR_ID_MSPACE_DOWNLOAD_FAIL"/>
    <STRING id ="STR_ID_MSPACE_INSTALLING"/>
    <STRING id ="STR_ID_MSPACE_INSTALL_SUCCESS"/>
    <STRING id ="STR_ID_MSPACE_INSTALL_FAIL"/>
    <STRING id ="STR_ID_MSPACE_APP_TIME"/>
    <STRING id ="STR_ID_MSPACE_APP_SIZE"/>
    <STRING id ="STR_ID_MSPACE_APP_PROVIDER"/>
    <STRING id ="STR_ID_MSPACE_APP_INTRODUCTION"/>
    <STRING id ="STR_ID_MSPACE_CONNECTION_FAILED"/>
    <STRING id ="STR_ID_MSPACE_WAITING"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_MEMORY_LIMITATION"/>    

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    
    <MENUITEM id="MENU_ID_MSPACE_ENTRY" str="STR_ID_MSPACE_NAME" img="IMG_ID_MSPACE_SUB_MENU_ICON" highlight="HighlightMSpace"/>
    
    <MENUITEM id="MENU_ID_MSPACE_OPTION_TO_UPDATE_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_MSPACE_OPTION_TO_INSTALL_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_MSPACE_OPTION_TO_DETAILS_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENUITEM id="MENU_ID_MSPACE_OPTION_TO_UPDATE_UPDATE" str="STR_ID_MSPACE_UPDATE"/>
    <MENUITEM id="MENU_ID_MSPACE_OPTION_TO_INSTALL_INSTALL" str="STR_ID_MSPACE_INSTALL"/>    
    <MENU id="MENU_ID_MSPACE_OPTIONS_TO_UPDATE" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MSPACE_OPTION_TO_UPDATE_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MSPACE_OPTION_TO_UPDATE_UPDATE</MENUITEM_ID>
    </MENU>
    <MENU id="MENU_ID_MSPACE_OPTIONS_TO_INSTALL" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MSPACE_OPTION_TO_INSTALL_DETAILS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MSPACE_OPTION_TO_INSTALL_INSTALL</MENUITEM_ID>
    </MENU>
    <MENU id="MENU_ID_MSPACE_OPTIONS_TO_DETAILS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MSPACE_OPTION_TO_DETAILS_DETAILS</MENUITEM_ID>
    </MENU>        

    <!-----------------------------------------------------DLA of String Resource Area----------------------------------------------------->


    <!------------------------------------------------------PSMGR of Other Resource---------------------------------------------------------->



    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_MSPACE_MAIN_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MSpace\\\\M_Space.png"</IMAGE>
    <IMAGE id="IMG_ID_MSPACE_SUB_MENU_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MSpace\\\\Mspace_sub.png"</IMAGE>
    <IMAGE id="IMG_ID_MSPACE_APP_DEFAULT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MSpace\\\\MRE.png"</IMAGE>    
    <IMAGE id="IMG_ID_MSPACE_APP_STATUS_DEFAULT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MSpace\\\\Default_01.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_MSPACE_APP_STATUS_INSTALLED_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MSpace\\\\done.png"</IMAGE>
    <IMAGE id="IMG_ID_MSPACE_APP_STATUS_UPDATE_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\MSpace\\\\update.png"</IMAGE>


    <!-----------------------------------------------------AM Shortcut app Resource Area------------------------------------------------------>

  
    /***********************************************/
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_MSPACE"/>
    <SCREEN id="SCR_ID_MSPACE_MAIN"/>
    <SCREEN id="SCR_ID_MSPACE_APP_MAIN"/>
    <SCREEN id="SCR_ID_MSPACE_APP_INSTALL"/>
    <SCREEN id="SCR_ID_MSPACE_APP_UPDATE"/>
    <SCREEN id="SCR_ID_MSPACE_WAITING"/>
    <SCREEN id="SCR_ID_MSPACE_DOWNLOADING"/>

    <!------------------------------------------------------DLA of Other Resource---------------------------------------------------------->


    <!------------------------------------------------------PSMGR of Other Resource---------------------------------------------------------->


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------DLA of Menu Resource Area------------------------------------------------------>
    

    <!------------------------------------------------------PSMGR of Menu Resource Area------------------------------------------------------>

    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_mspace_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_mspace_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_mspace_enter_usb_mode_ms_callback"/>

    <RECEIVER id="EVT_ID_SRV_APPMGR_INSTALL_PACKAGE" proc="mmi_mspace_srv_appmgr_install_package_callback"/>
    <RECEIVER id="EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE" proc="mmi_mspace_srv_appmgr_update_install_package_callback"/>

</APP>

#endif /* __MMI_MRE_MSPACE__ */


