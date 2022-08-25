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

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    /* CS Main Menu */
    <STRING id="STR_ID_AVK">"AVK"</STRING>
    <STRING id="STR_ID_AVK_PASS">"Pass"</STRING>
    <STRING id="STR_ID_AVK_FAIL">"Fail"</STRING>

    <!------------------------------------------------------Screen Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_AVK"/>
    //framework use
    <SCREEN id="SCR_ID_AVK_SCN_0"/>
    <SCREEN id="SCR_ID_AVK_SCN_1"/>
    <SCREEN id="SCR_ID_AVK_SCN_2"/>
    <SCREEN id="SCR_ID_AVK_SCN_3"/>
    <SCREEN id="SCR_ID_AVK_SCN_4"/>
    <SCREEN id="SCR_ID_AVK_SCN_5"/>
    <SCREEN id="SCR_ID_AVK_SCN_6"/>
    <SCREEN id="SCR_ID_AVK_SCN_7"/>
    <SCREEN id="SCR_ID_AVK_SCN_8"/>
    <SCREEN id="SCR_ID_AVK_SCN_9"/>
    //user use
    <SCREEN id="SCR_ID_AVK_SCN_10"/>
    <SCREEN id="SCR_ID_AVK_SCN_11"/>
    <SCREEN id="SCR_ID_AVK_SCN_12"/>
    <SCREEN id="SCR_ID_AVK_SCN_13"/>
    <SCREEN id="SCR_ID_AVK_SCN_14"/>

    <SCREEN id="GRP_ID_1"/>
    <SCREEN id="GRP_ID_2"/>
</APP>

#endif