/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#if (defined(__MMI_MENSTRUAL__) && !defined(__COSMOS_MMI_PACKAGE__))
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_HEALTHMENSTRUAL">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_SCR_HEALTH_MENSIS_CAPTION"/>
    <STRING id="STR_HEALTH_MENSIS_DATE_CAPTION"/>
    <STRING id="STR_LAST_DATE"/>
    <STRING id="STR_DATE_FORMAT_HEALTH_MENSIS"/>
    <STRING id="STR_AVERAGE_DAYS_HEALTH_MENSIS"/>
    <STRING id="STR_INVALID_AVERAGE_DAY_MESSAGE"/>
    <STRING id="STR_SCR_HEALTH_MENSIS_PROBABILITY_CAPTION"/>
    <STRING id="STR_SCR_HEALTH_MENSIS_PROBABILITY_MESSAGE"/>
    <STRING id="STR_CANNOT_NAVIGATE_FURTHER_MESSAGE"/>
    <STRING id="STR_CALENDER_MESSAAGE1_PP"/>
    <STRING id="STR_CALENDER_MESSAAGE2_MENS"/>
    <STRING id="STR_CALENDER_MESSAAGE2_SHORT_MENS"/>
    <STRING id="STR_HEALTH_WRONG_DATE_MSG"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_SCR_HEALTH_MENSIS">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_MENS.BMP"</IMAGE>
    <IMAGE id="IMG_HEALTH_MENSIS_PP">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\PP.bmp"</IMAGE>
    <IMAGE id="IMG_HEALTH_MENSIS_MENSES">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\MENS.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_MENS"/>
    <SCREEN id="SCR_ID_MENS_WELCOME"/>
    <SCREEN id="SCR_ID_MENS_INPUT"/>
    <SCREEN id="SCR_ID_MENS_RESULT"/>
    <SCREEN id="SCR_ID_MENS_PROB"/>

</APP>
#endif
