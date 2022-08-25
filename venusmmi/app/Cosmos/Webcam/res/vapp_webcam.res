#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WEBCAM" name="STR_ID_APP_WEBCAM" type="venus">
    <MEMORY heap ="300*1024" extra_base="base(SRV_MDI_WEBCAM)" fg ="fg(SRV_MDI_WEBCAM)"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_USB_CONFIG_WEBCAM"/>
    <STRING id="STR_ID_VAPP_WEBCAM_NOTIFY_ERROR"/>
    <STRING id="STR_ID_VAPP_WEBCAM_NOTIFY_CAM_ERROR"/>
    <STRING id="STR_ID_VAPP_WEBCAM_STOPPED"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>    
    <IMAGE id="IMG_ID_WEBCAM_BG">RES_IMG_ROOT"\\\\Webcam\\\\Webcam.png"</IMAGE>

    <RECEIVER id="EVT_ID_USB_CONFIG_RSP" proc="vapp_webcam_usb_config_rsp_callback"/>
    
</APP>

