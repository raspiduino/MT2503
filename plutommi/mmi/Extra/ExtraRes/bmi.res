/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#if (defined(__MMI_BMI__) && !defined(__COSMOS_MMI_PACKAGE__))
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_HEALTHBMI">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_BMI_WELCOME_CAPTION"/>
    <STRING id="STR_BMI_INPUT_CAPTION"/>
    <STRING id="STR_BMI_RESULT_CAPTION"/>
    <STRING id="STR_BMI_MALE_TEXT"/>
    <STRING id="STR_BMI_FEMALE_TEXT"/>
    <STRING id="STR_BMI_HEIGHT_TEXT"/>
    <STRING id="STR_BMI_WEIGHT_TEXT"/>
    <STRING id="STR_BMI_HEIGHT_ERROR_TEXT"/>
    <STRING id="STR_BMI_WEIGHT_ERROR_TEXT"/>
    <STRING id="STR_BMI_HEIGHT_WEIGHT_ERROR"/>
    <STRING id="STR_BMI_BMI_TEXT"/>
    <STRING id="STR_BMI_FAT"/>
    <STRING id="STR_BMI_THIN"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_BMI_WELCOME_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_BMI.bmp"</IMAGE>
    <IMAGE id="IMG_BMI_RED_FLOWER">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_RF.bmp"</IMAGE>
    <IMAGE id="IMG_BMI_BLUE_FLOWER">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_BF.bmp"</IMAGE>
    


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_BMI"/>
    <SCREEN id="SCR_BMI_WELCOME"/>
    <SCREEN id="SCR_BMI_INPUT"/>
    <SCREEN id="SCR_BMI_RESULT"/>
    <SCREEN id="SCR_POPUP_HEALTH"/>


</APP>
#endif
