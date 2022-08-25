/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_OP02_LEMEI__)

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_LEMEI">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="MainMenuDef.h"/>
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_LEMEI_MENUITEM"/>
    <STRING id="STR_ID_LOCAL_AUDIO"/>
    <STRING id="STR_ID_LOCAL_PICTURE"/>
    <STRING id="STR_ID_LOCAL_VIDEO"/>
    <STRING id="STR_ID_FILE_TOO_LARGE"/>
    <STRING id="STR_ID_LEMEI_SUBJECT"/>
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    <IMAGE id = "IMG_ID_LEMEI_CAMERA_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_TakePho_UP.png"</IMAGE>;
    <IMAGE id = "IMG_ID_LEMEI_CAMERA_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_TakePho_DN.png"</IMAGE>;
    <IMAGE id = "IMG_ID_LEMEI_VIDEO_RECORDER_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_Video_UP.png"</IMAGE>;
    <IMAGE id = "IMG_ID_LEMEI_VIDEO_RECORDER_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_Video_DN.png"</IMAGE>;
    <IMAGE id = "IMG_ID_LEMEI_AUDIO_RECORDER_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_REC_UP.png"</IMAGE>;
    <IMAGE id = "IMG_ID_LEMEI_AUDIO_RECORDER_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_REC_DN.png"</IMAGE>;
    <IMAGE id = "IMG_ID_LEMEI_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Lemei\\\\LM_BG.png"</IMAGE>;

    /* For the detail of scope="XML" please check user manual */

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->

    <MENU id="MENUID_LEMEI_OPTIONS_MENU" type="OPTION" str="STR_ID_LEMEI_MENUITEM" >
        /* Could write MENUITEM in menu directly */

        <MENUITEM id="MENU_ID_LEMEI_OPTIONS_LOCAL_PICTURE" str="STR_ID_LOCAL_PICTURE"/>
        <MENUITEM id="MENU_ID_LEMEI_OPTIONS_LOCAL_VIDEO" str="STR_ID_LOCAL_VIDEO"/>
        <MENUITEM id="MENU_ID_LEMEI_OPTIONS_LOCAL_AUDIO" str="STR_ID_LOCAL_AUDIO"/>

    </MENU>
    
    


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_LEMEI_MAIN"/>
    <SCREEN id="SCR_ID_LEMEI_OPTIONS"/>
    <SCREEN id="GRP_ID_LEMEI"/>

</APP>

#endif /*__MMI_OP02_LEMEI__*/