/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_EXTRA">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#if defined(__MMI_APHORISM__)

    <STRING id="EXTRA_MENU_APHORISM_STRINGID"/>
    <STRING id="EXTRA_APHORISM_ON"/>
    <STRING id="EXTRA_APHORISM_OFF"/>
    <STRING id="STR_SCR9147_APHORISM_TEXT_CAPTION"/>
#endif /* defined(__MMI_APHORISM__) */ 

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Tree Area-->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_EXTRA"/>
    <SCREEN id="SCR9147_APHORISM_TEXT"/>


</APP>
