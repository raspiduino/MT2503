/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_DEVAPP">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

#if !defined(__IOT__)
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_APP_DEVAPP">"..\\\\DevResource\\\\Images\\\\EmptyImage.bmp"</IMAGE>
#endif

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    
    <SCREEN id="SCR_ID_APP_DEVAPP"/>

</APP>

