/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SDK_TEST" name="STR_ID_AVK">
		<MEMORY heap="1024"/>
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    /* CS Main Menu */
    
    
</APP>

#endif