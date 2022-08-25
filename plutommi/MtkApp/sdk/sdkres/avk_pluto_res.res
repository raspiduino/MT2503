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
    <STRING id="STR_ID_AVK_PLUTO_RES">"Add menuitem"</STRING>
    <STRING id="STR_ID_AVK_PLUTO_RES_MENUITEM_1">"Item1"</STRING>
    <STRING id="STR_ID_AVK_PLUTO_RES_MENUITEM_2">"Itme2"</STRING>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_AVK_PLUTO_RES_1">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\bootup.bmp"</IMAGE>
    <IMAGE id="IMG_ID_AVK_PLUTO_RES_2">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\EmptyImage.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Tree Area-->
    /* DEVAPP Main Menu*/
    <MENUITEM id="MENU_ID_AVK_PLUTO_RES_1" str="STR_ID_AVK_PLUTO_RES_MENUITEM_1" img="IMG_ID_AVK_PLUTO_RES_2" />   
    <MENUITEM id="MENU_ID_AVK_PLUTO_RES_2" str="STR_ID_AVK_PLUTO_RES_MENUITEM_2" img="IMG_ID_AVK_PLUTO_RES_2" />   
    
    <MENU id="MENU_ID_AVK_PLUTO_RES" str="STR_ID_AVK_PLUTO_RES" img="IMG_ID_AVK_PLUTO_RES_1" >
        <MENUITEM_ID>MENU_ID_AVK_PLUTO_RES_1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_AVK_PLUTO_RES_2</MENUITEM_ID>
    </MENU>

    <!------------------------------------------------------Audio---------------------------------------------------------->  
    <AUDIO id="ADO_ID_AVK_PLUTO_RES">CUST_ADO_PATH"\\\\SDK_TEST\\\\aaa.wav"</AUDIO>
    
    <!----------------------------------------------- Pluto Timer Res Begin ---------------------------------------------------->
    <TIMER id="AVK_MYTIMER_BASE_ID"/>
    
    <!-- Regist Callback Receiver -->
    <RECEIVER id="EVT_ID_MMI_TIMER_INIT_EXT" proc="avk_mytimer_init"/>
    <RECEIVER id="EVT_ID_MMI_TIMER_EXPIRY_PROC_EXT" proc="avk_mytimer_expiry_handler"/>
    <!----------------------------------------------- Pluto Timer Res End ------------------------------------------------------>

</APP>

#endif