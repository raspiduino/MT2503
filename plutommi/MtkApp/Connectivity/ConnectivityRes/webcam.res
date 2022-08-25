#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
#if !defined(__COSMOS_MMI__)
<APP id="APP_WEBCAM">
#if defined(__MMI_WEBCAM__)
    <RECEIVER id="EVT_ID_USB_CONFIG_RSP" proc="mmi_webcam_usb_config_rsp_callback"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_USB_CONFIG_WEBCAM"/>
    <STRING id="STR_ID_USB_NOTIFY_WEBCAM_ERROR"/>
    <STRING id="STR_ID_USB_NOTIFY_WEBCAM_CAM_ERROR"/>
    <STRING id="STR_ID_USB_WEBCAM_STOPPED"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>    
    <IMAGE id="IMG_ID_WEBCAM_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_bg.gif"</IMAGE>
    #ifdef __MMI_SUBLCD__
    <IMAGE id="IMG_ID_WEBCAM_SUB_BG">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_USB_Webcam.gif"</IMAGE>
    #endif
    #ifdef  __MMI_BACKGROUND_CALL__
    <IMAGE id="IMG_ID_WEBCAM_BG_INCALL">CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\webcam\\\\webcam_bg_incall.gif"</IMAGE>
    #endif
    
	<!------------------------------------------------------Other Resource---------------------------------------------------------->
	<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_webcam_gpio_event_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_webcam_gpio_event_hdlr"/>
	  #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
        <RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_webcam_notify_screen_lock_hdlr"/> 
    #endif
#endif // defined(__MMI_WEBCAM__)
</APP>

#endif // !defined(__COSMOS_MMI__)
