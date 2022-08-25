/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SDK_TEST">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <IMAGE id="IMG_ID_AVK_DEVAPP_1">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\CL_ABORT.gif"</IMAGE>    
    <IMAGE id="IMG_ID_AVK_DEVAPP_2">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\webcam_jpeg_1.jpg"</IMAGE>
    <IMAGE id="IMG_ID_AVK_DEVAPP_3">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\smile.png"</IMAGE>
    
</APP>

#endif
