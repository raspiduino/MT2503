/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "../../../custom/common/custom_gadget_config.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_WIDGET_DELEGATOR_IDLE"
    name="STR_ID_APP_WIDGET_DELEGATOR_IDLE"
    hidden_in_mainmenu="true">

    <MEMORY extra_base="$(APP_WIDGET_IDLE_FG_SIZE)"            
            inc="../../../plutommi/MtkApp/WidgetDelegator/WidgetDelegatorInc/widget_defs.h"/>
</APP>
 
<APP id="APP_WIDGET_ADP" 
    name="STR_ID_APP_WIDGET_ADP" 
    hidden_in_mainmenu="true">
    
    <MEMORY extra_base="$(GADGET_CUSTOM_CFG_ASM_MEM_SIZE)" 
            inc="custom_gadget_config.h"/>   

    <APPCONCURRENT concurrent_w_order ="APP_WIDGET_ADP, APP_WIDGET_DELEGATOR"/>
</APP>
 
<APP id="APP_WIDGET_DELEGATOR"
    name="STR_ID_APP_WIDGET_DELEGATOR"    
    hidden_in_mainmenu="true">
    
    <MEMORY heap="1024*200"
            fg="max($(APP_WIDGET_IDLE_FG_SIZE), $(APP_WIDGET_DETAILS_FG_SIZE))"            
            inc="../../../plutommi/MtkApp/WidgetDelegator/WidgetDelegatorInc/widget_defs.h"/>
            
#if defined(OPERA_V10_BROWSER) && defined(GADGE_BROWSER_CONCURRENCE)
    <APPCONCURRENT concurrent_w_order ="APP_WIDGET_DELEGATOR, APP_WIDGET_DELEGATOR, APP_OPERA"/>
#endif

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

#ifdef __MMI_GADGET_SUPPORT__

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_WIDGET_PERMISSION_NOT_GRANTED"/>
    <STRING id="STR_ID_WIDGET_PATH_NOT_FOUND"/>
    <STRING id="STR_ID_WIDGET_FAILED_LOAD_WIDGET"/>
    <STRING id="STR_ID_WIDGET_MEMORY_FULL"/>
    <STRING id="STR_ID_WIDGET_ALLOW_NETWORK_ACCESS"/>
    <STRING id="STR_ID_WIDGET_EDIT_TEXT"/>
    <STRING id="STR_ID_WIDGET_MAXIMUM_REACHED"/>
    <STRING id="STR_ID_WIDGET_ALLOW_SEND_SMS"/>
    <STRING id="STR_ID_WIDGET_BUSY_NOW_PLEASE_TRY_LATER"/>
    
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

    <IMAGE id="IMG_ID_WIDGET_LOADING_0">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\0.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_1">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\1.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_2">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\2.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_3">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\3.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_4">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\4.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_5">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\5.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_6">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\6.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOADING_7">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\COMMON\\\\PROGRESS\\\\7.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_SETTING_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Homescreen\\\\widget\\\\WidgetDelegator\\\\Widget_setting_up.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_SETTING_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Homescreen\\\\widget\\\\WidgetDelegator\\\\Widget_setting_down.png"</IMAGE>
    <IMAGE id="IMG_ID_WIDGET_LOAD_FAILED">CUST_IMG_PATH"\\\\MainLCD\\\\\WgtMgr\\\\WidgetIcon_default.png"</IMAGE>    

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <SCREEN id="GRP_ID_WIDGET_ADP"/>
    <SCREEN id="GRP_ID_WIDGET_VIEW"/>
    <SCREEN id="GRP_ID_WIDGET_EDITOR"/>
    <SCREEN id="SCR_ID_WIDGET_VIEW"/>
    <SCREEN id="SCR_ID_WIDGET_EDITOR"/>
#ifdef __MTK_INTERNAL__
    <SCREEN id="SCR_ID_WIDGET_MEM_USAGE"/>
#endif 

    <!------------------------------------------------------CallBack Manager---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="widget_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="widget_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" proc="widget_mode_switch_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND" proc="widget_wgtmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_WGTMGR_DELETE_WIDGET_IND" proc="widget_wgtmgr_notify_hdlr"/>
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="widget_usb_notify_hdlr"/>
#endif 

#endif /* __MMI_GADGET_SUPPORT__ */
</APP>

