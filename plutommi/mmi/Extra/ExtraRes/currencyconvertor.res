/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#if (defined(__MMI_CURRENCY_CONVERTER__) && !defined(__COSMOS_MMI_PACKAGE__))
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_CURRENCYCONVERTER"
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
        package_name = "native.mtk.currencyconverter"         /* Use "native.mtk." as the prefix of application name */
        name = "EXTRA_MENU_CURRENCYCONVERTOR_STRINGID"                /* The string to be displayed under the main menu icon */
        img = "MAIN_MENU_CCONV_ICON"    /* Main menu icon image */
        launch = "mmi_cconv_pre_entry_app"                /* Launch function of application. When tap on the icon in main menu, the function will be invoked. */
    #endif /*__MMI_APP_MANAGER_SUPPORT__*/
>


    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_CURRENCYCONVERTOR_RATEINPUT"/>
    <STRING id="STR_CURRENCYCONVERTOR_RATE"/>
    <STRING id="STR_CURRENCYCONVERTOR_INPUT"/>
    <STRING id="STR_CURRENCYCONVERTOR_LOCAL"/>
    <STRING id="STR_CURRENCYCONVERTOR_FOREIGN"/>
    <STRING id="ERROR_CURRENCYCONVERTOR_RATE1"/>
    <STRING id="EXTRA_MENU_CURRENCYCONVERTOR_STRINGID"/>
    <STRING id="STR_CURRENCYCONVERTOR_SAVE_RATE"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Currency\\\\SB_OCUR.bmp"</IMAGE>
    <IMAGE id="CURRENCY_CONVERTOR_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Currency\\\\C_RATE.bmp"</IMAGE>
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    <IMAGE id="MAIN_MENU_CCONV_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Currency.png"</IMAGE>
#endif


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENU id="EXTRA_CURRENCYCONVERTOR_MENU" type="APP_SUB" str="EXTRA_MENU_CURRENCYCONVERTOR_STRINGID" img="EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID" highlight="mmi_cconv_highlight_menu"
    shortcut="ON" shortcut_img="EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID" launch="mmi_cconv_pre_entry_app">       
    </MENU>

    <CACHEDATA type="double" id="CURRENCY_CONVERTOR_EXCHANGE_RATE">
    <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
    <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
	<SCREEN id="GRP_ID_CCONV"/>
	<SCREEN id="SCR_ID_CCONV_RATE_INPUT"/>
    <SCREEN id="SCR_ID_CCONV_COMPUTE"/>
    <SCREEN id="SCR_ID_CCONV_SAVE_CONFIRM"/>
</APP>
#endif
