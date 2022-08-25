/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#if (defined(__MMI_UNIT_CONVERTER__) && !defined(__COSMOS_MMI_PACKAGE__))
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_UNITCONVERTER"
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
        package_name = "native.mtk.unitconverter"         /* Use "native.mtk." as the prefix of application name */
        name = "EXTRA_MENU_UNITSCONVERTOR_STRINGID"                /* The string to be displayed under the main menu icon */
        img = "MAIN_MENU_UCONV_ICON"    /* Main menu icon image */
        launch = "mmi_uconv_pre_entry_main_menu"                /* Launch function of application. When tap on the icon in main menu, the function will be invoked. */
    #endif /*__MMI_APP_MANAGER_SUPPORT__*/
>


    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_UNITCONVERTOR_WEIGHT"/>
    <STRING id="STR_UNITCONVERTOR_LENGTH"/>
    <STRING id="STR_UNITCONVERTOR_KGPOUND"/>
    <STRING id="STR_UNITCONVERTOR_KG"/>
    <STRING id="STR_UNITCONVERTOR_POUND"/>
    <STRING id="STR_UCONV_OUNCE"/>
    <STRING id="STR_UCONV_KGOUNCE"/>
    <STRING id="STR_UNITCONVERTOR_KMMILE"/>
    <STRING id="STR_UNITCONVERTOR_MYARD"/>
    <STRING id="STR_UNITCONVERTOR_MFOOT"/>
    <STRING id="STR_UNITCONVERTOR_CMINCH"/>
    <STRING id="STR_UNITCONVERTOR_KM"/>
    <STRING id="STR_UNITCONVERTOR_METER"/>
    <STRING id="STR_UNITCONVERTOR_CM"/>
    <STRING id="STR_UNITCONVERTOR_MILE"/>
    <STRING id="STR_UNITCONVERTOR_YARD"/>
    <STRING id="STR_UNITCONVERTOR_FOOT"/>
    <STRING id="STR_UNITCONVERTOR_INCH"/>
    <STRING id="UC_ERROR_WRONG_STRING"/>
    <STRING id="EXTRA_MENU_UNITSCONVERTOR_STRINGID"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="EXTRA_MENU_UNITSCONVERTOR_IMAGEID" >CUST_IMG_PATH"\\\\MainLCD\\\\UnitsConverter\\\\SB_OUNIT.bmp"</IMAGE>
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    <IMAGE id="MAIN_MENU_UCONV_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Converter.png"</IMAGE>
#endif


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Tree Area-->
    <MENU id="EXTRA_UNITCONVERTOR_MENU" type="APP_SUB" str="EXTRA_MENU_UNITSCONVERTOR_STRINGID" img="EXTRA_MENU_UNITSCONVERTOR_IMAGEID" highlight="mmi_uconv_highlight_hdlr"
    shortcut="ON" shortcut_img="EXTRA_MENU_UNITSCONVERTOR_IMAGEID" launch="mmi_uconv_pre_entry_main_menu">       
				<MENUITEM id="EXTRA_UNITCONVERTOR_WEIGHT" str="STR_UNITCONVERTOR_WEIGHT"/>
        <MENUITEM id="EXTRA_UNITCONVERTOR_LENGTH" str="STR_UNITCONVERTOR_LENGTH"/>
    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_UCONV"/>
    <SCREEN id="SCR_ID_UCONV_MENU"/>
    <SCREEN id="SCR_ID_UCONV_WEIGHT"/>
    <SCREEN id="SCR_ID_UCONV_LENGTH"/>


</APP>
#endif
