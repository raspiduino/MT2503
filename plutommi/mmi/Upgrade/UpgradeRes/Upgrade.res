/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#ifdef __MMI_VPP_UPGRADE__

#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_UPGRADE">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_app_mainmenu_def.h, mmi_rp_srv_upgrade_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_UPGRADE_APP"/>

    <STRING id="STR_ID_UPGRADE_NEW_UPGRADES"/>
    <STRING id="STR_ID_UPGRADE_NEW_UPGRADE"/>
    <STRING id="STR_ID_UPGRADE_TAP_TO_DOWNLOAD"/>
    <STRING id="STR_ID_UPGRADE_DOWNLOAD"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_UPGRADE_NC_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Upgrade\\\\Upgrade.png"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Option Menu Tree Area-->


    <!------------------------------------------------------Screen Resource--------------------------------------------------------->


    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_UPGRADE_DOWNLOAD_REQ"        proc="mmi_upgrade_download_proc"/>    


    <!------------------------------------------------------Other Resource---------------------------------------------------------->


</APP>

#endif
