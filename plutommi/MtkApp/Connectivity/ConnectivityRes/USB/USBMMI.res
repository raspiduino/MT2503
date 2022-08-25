#include "mmi_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_USBMMI">

#ifdef __MMI_USB_SUPPORT__

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
	<INCLUDE file = "gdi_features.h"/>

<!----------------- Common Area ----------------------------------------------->

<!----------------- String Id ----------------------------------------->             
    <STRING id = "STR_USB_CONFIG_TITLE">USB Config.</STRING>
    
#if defined(__MMI_USB_CDCACM_ONLY__)
	#if defined(__USB_COM_PORT_ENABLE__)
    <STRING id = "STR_USB_CONFIG_CDCACM_ONLY">USB Detect! Set as COM port?</STRING>
    #endif
#elif defined(__MMI_USB_MS_ONLY__)
#else
    <STRING id = "STR_USB_CONFIG_MS">Mass Storage</STRING>
    <STRING id = "STR_USB_CONFIG_CDCACM_DATA">Data Port</STRING>
#endif  /* __MMI_USB_CDCACM_ONLY__ && __MMI_USB_CDCACM_ONLY__  */ 

    <STRING id = "STR_USB_CONFIG_MS_ONLY">USB Detect! Shutdown for Mass storage?</STRING>

#ifdef __MMI_WEBCAM__
    <STRING id = "STR_ID_USB_WEBCAM">Web camera</STRING>
#endif

#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
    <STRING id = "STR_USB_CONFIG_COMPORT_JAVA">JAVA connection</STRING>
#endif   

#ifdef  __MTP_ENABLE__
    <STRING id = "STR_USB_CONFIG_MTP">MTP storage</STRING>
    <STRING id = "STR_ID_USB_NOT_AVAILABLE_IN_MTP_MODE">Not available in MTP mode</STRING>
#endif   

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    <STRING id = "STR_USB_CONFIG_PICT_BRIGE">PictBridge</STRING>
    <STRING id = "STR_USB_PICT_BRIGE_CONFIGING">PictBridge Configuring...</STRING>
#endif

#if defined(__MMI_USB_COPY_RIGHT__)
    <STRING id = "STR_USB_POWER_ON_PROCESSING">Power on for Mass Storage...</STRING>
#endif

    <STRING id = "STR_ID_USB_NO_MS_FOR_PC">USB: No storage for PC</STRING>
    <STRING id = "STR_ID_USB_SYS_NOT_READY">System not ready, Please try later!</STRING>    

#ifdef __MMI_IRDA_SUPPORT__
    <STRING id = "STR_ID_USB_IRCOMM_OCCUPY_CDCACM">Please turn off IrDA</STRING>
#endif
    <STRING id = "STR_ID_USB_UART2_OCCUPIED">Not allow when PS set to None</STRING>
#ifdef __USB_TETHERING__
    <STRING id = "STR_ID_USB_TETHERING">USB tethering</STRING>
#endif

#ifdef __USB_DATA_CONNECTION__
    <STRING id = "STR_ID_USB_CDROM">Data connection</STRING>
#endif

<!----------------- Menu Id -----------------------------------------> 
#if 0
#ifdef __USB_MASS_STORAGE_ENABLE__
<MENUITEM id="MENU_ID_USB_MS" str="STR_USB_CONFIG_MS"/>    
#endif
#ifdef __MMI_WEBCAM__
<MENUITEM id="MENU_ID_USB_WEBCAM" str="STR_ID_USB_WEBCAM"/>    
#endif
#ifdef __USB_COM_PORT_ENABLE__
<MENUITEM id="MENU_ID_USB_CDCAM_DATA" str="STR_USB_CONFIG_CDCACM_DATA"/>    
#endif
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
<MENUITEM id="MENU_ID_USB_PICTBRIDGE" str="STR_USB_CONFIG_PICT_BRIGE"/>    
#endif
#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
<MENUITEM id="MENU_ID_USB_COMPORT_JAVA" str="STR_USB_CONFIG_COMPORT_JAVA"/>    
#endif
#ifdef  __MTP_ENABLE__
<MENUITEM id="MENU_ID_USB_MTP" str="STR_USB_CONFIG_MTP"/>    
#endif
<MENUITEM id="MENU_ID_USB_TETHERING" str="STR_ID_USB_TETHERING"/>    

   <MENU id = "MENU_ID_USB_CFG" type = "APP_SUB" str = "STR_USB_CONFIG_TITLE">
        <MENUITEM_ID>MENU_ID_USB_MS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_USB_WEBCAM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_USB_CDCAM_DATA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_USB_PICTBRIDGE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_USB_COMPORT_JAVA</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_USB_MTP</MENUITEM_ID>
    </MENU>
#endif
<!----------------- Event callbacks------------------------------------> 

#ifndef __MMI_USB_FTO_SUPPORT__
<RECEIVER id="EVT_ID_USB_PERMIT_CFG" proc="mmi_usb_handle_query_permit_show"/>
<RECEIVER id="EVT_ID_USB_PERMIT_CFG_PRE_CHECK" proc="mmi_usb_handle_query_permit_pre_check"/>
<RECEIVER id="EVT_ID_USB_PLUG_IN" proc="mmi_usb_handle_plug_in"/>
<RECEIVER id="EVT_ID_USB_CONFIG_RSP" proc="mmi_usb_config_rsp_callback"/>
<RECEIVER id="EVT_ID_USB_MMI_NOTIFY" proc="mmi_usb_mmi_notify_callback"/>
<RECEIVER id="EVT_ID_USB_ALM_STATE" proc="mmi_usb_alm_state_callback"/>
#endif



<!----------------- Screen Id ----------------------------------------->             
    <SCREEN id = "GRP_ID_USB_BOOT_MODE"/>
    <SCREEN id = "GRP_ID_USB_MMI"/>
    <SCREEN id = "SCR_DEV_USBDETECT"/>
    <SCREEN id = "SCR_USB_POWER_ON"/>
    <SCREEN id = "SCR_USB_CHGR_CMPLT"/>
    <SCREEN id = "SCR_USB_POWER_ON_DONE"/>
    <SCREEN id = "SCR_ID_USB_WEBCAM"/>
    <SCREEN id = "SCR_ID_USB_PROGRESS"/>
    <SCREEN id = "SCR_ID_USB_WAIT"/>


<!----------------- Image Id ------------------------------------------->

#if defined(__MMI_USB_CHARGER_POWER_ON_SLIM_IMAGE__)    
#else
    <IMAGE id = "IMG_USB_POWER_ON">CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_noanimation."__MMI_RES_TYPE_ACTIVE_SCREEN__</IMAGE>
    <IMAGE id = "IMG_USB_CHGR_CMPLT">CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_ChgrCmplt."__MMI_RES_TYPE_ACTIVE_SCREEN__</IMAGE>
    <IMAGE id = "IMG_ID_USB_CHARGING">CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_on.gif"</IMAGE>
#endif
    
#ifdef __MMI_SUBLCD__
    <IMAGE id = "IMG_SUB_USB_POWER_ON">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_USB_on.gif"</IMAGE>
    <IMAGE id = "IMG_USB_SUB_CHGR_CMPLT">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_USB_ChgrCmplt.gif"</IMAGE>
#endif /* __MMI_SUBLCD__ */

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__) || defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
<TIMER id="USB_SHUTDOWN_FOR_MASS_STORAGE"/>
#endif
<TIMER id="USB_WAIT_FOR_MASS_STORAGE"/>

<!----------------- XML END --------------------------------------------------->

#endif /* __MMI_USB_SUPPORT__ */

</APP>








