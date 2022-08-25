/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SHUTDOWN">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

#ifdef __MMI_SUBLCD__
    <IMAGE id="IMG_ID_SHUTDOWN_SUBLCD_ANIMATION">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_OFF.gif"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SHUTDOWN"/>
    <SCREEN id="SCR_ID_SHUTDOWN_BASE"/>
    <SCREEN id="SCR_ID_SHUTDOWN_ANIMATION"/>

    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="mmi_shutdown_normal_start"/>

    <TIMER id="SHUTDOWN_PROCESS_TIMER"/>

</APP>

