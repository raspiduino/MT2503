/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#if ((defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__)) && !defined(__COSMOS_MMI_PACKAGE__))
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_HEALTH"
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
        package_name = "native.mtk.health"         /* Use "native.mtk." as the prefix of application name */
        name = "EXTRA_MENU_HEALTH_STRINGID"                /* The string to be displayed under the main menu icon */
        img = "MAIN_MENU_HEALTH_ICON"    /* Main menu icon image */
        launch = "mmi_health_entry_app"                /* Launch function of application. When tap on the icon in main menu, the function will be invoked. */
    #endif /*__MMI_APP_MANAGER_SUPPORT__*/
>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="EXTRA_MENU_HEALTH_STRINGID"/>
    <STRING id="EXTRA_HEALTH_MENU_BMI_STRINGID"/>
    <STRING id="EXTRA_HEALTH_MENU_MENSTRUAL_STRINGID"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="EXTRA_MENU_HEALTH_IMAGEID">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\SB_HEAL.bmp"</IMAGE>
#if defined(__MMI_APP_MANAGER_SUPPORT__)
    <IMAGE id="MAIN_MENU_HEALTH_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\MainMenu\\\\Icons\\\\Health.png"</IMAGE>
#endif


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
#ifdef __MMI_BMI__
    <MENUITEM id="EXTRA_HEALTH_MENU_BMI" str="EXTRA_HEALTH_MENU_BMI_STRINGID" img="IMG_GLOBAL_L1" shortcut="ON" shortcut_img="EXTRA_MENU_HEALTH_IMAGEID" launch="mmi_bmi_pre_entry_welcome_screen"/>
#endif    
#if defined(__MMI_MENSTRUAL__) && defined(__MMI_BMI__)
    <MENUITEM id="EXTRA_HEALTH_MENU_MENSTRUAL" str="EXTRA_HEALTH_MENU_MENSTRUAL_STRINGID" img="IMG_GLOBAL_L2" shortcut="ON" shortcut_img="EXTRA_MENU_HEALTH_IMAGEID" launch="mmi_mens_pre_entry_welcome_screen"/>
#elif defined(__MMI_MENSTRUAL__) && !defined(__MMI_BMI__)
	<MENUITEM id="EXTRA_HEALTH_MENU_MENSTRUAL" str="EXTRA_HEALTH_MENU_MENSTRUAL_STRINGID" img="IMG_GLOBAL_L1" shortcut="ON" shortcut_img="EXTRA_MENU_HEALTH_IMAGEID" launch="mmi_mens_pre_entry_welcome_screen"/>
#endif
	<MENU id="EXTRA_HEALTH_MENU" type="APP_SUB" str="EXTRA_MENU_HEALTH_STRINGID" img="EXTRA_MENU_HEALTH_IMAGEID" highlight="mmi_health_highlight_hdlr">       
		<MENUITEM_ID>EXTRA_HEALTH_MENU_BMI</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_HEALTH_MENU_MENSTRUAL</MENUITEM_ID>
    </MENU> 


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
	<SCREEN id="SCR_HEALTH_MENU"/>

</APP>
#endif
