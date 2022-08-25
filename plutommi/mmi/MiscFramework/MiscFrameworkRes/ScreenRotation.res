/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_AUTO_ROTATE">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

	<!-----------------------------------------NVRAM CACHE---------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_EF_SENSOR_UI_ROTATION_SWITCH" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> UI rotation is on </DESCRIPTION>
    </CACHEDATA>
    
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
		#ifdef __MMI_CLAMSHELL__
		<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_auto_rotate_ssq_handler"/>
		<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_auto_rotate_ssq_handler"/>
		#endif
		
		<SENDER id="EVT_ID_AUTO_ROTATE_QUERY" hfile="ScreenRotationGprot.h"/>
		<SENDER id="EVT_ID_ORIENTATION_CHANGED" hfile="ScreenRotationGprot.h"/>

</APP>

