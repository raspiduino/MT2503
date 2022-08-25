/*Needed header files of the compile option in XML files */
#include "mmi_features.h"

#ifdef __MMI_LINE_IN__

#include "CustResDef.h"
#include "custom_mmi_default_value.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id="APP_LINEIN"
    #if defined(__MMI_APP_MANAGER_SUPPORT__)
    package_name = "native.mtk.linein"
    name = "STR_ID_LINEIN_TITLE"
    launch = "mmi_linein_launch"
    #endif /*__MMI_APP_MANAGER_SUPPORT__*/
>
    <INCLUDE file="GlobalResDef.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <STRING id="STR_ID_LINEIN_TITLE"/>
    <STRING id="STR_ID_LINEIN_MUTE_ON"/>
    <STRING id="STR_ID_LINEIN_MUTE_OFF"/>
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Image Resource Area-->   
    <IMAGE id="IMG_ID_LINEIN_PLAY_ANIMATION">CUST_IMG_PATH"\\\\MainLCD\\\\Linein\\\\Linein.png"</IMAGE> 
    <!--End Image Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Tree Area-->
    <MENU id="MENU_ID_LINEIN_MAIN" type="APP_MAIN" str="STR_ID_LINEIN_TITLE"
        highlight="mmi_linein_highlight_menu" shortcut="ON" 
        launch="mmi_linein_launch"/>
    <!--End Menu Tree Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
    <SCREEN id="GRP_ID_LINEIN"/>    
    <SCREEN id="SCR_ID_LINEIN_MAIN"/>
    <!--End Screen ID Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Receiving Evt ID -->
    #if 0
    //move to callback_mgr.res
    /* Linein */
    <RECEIVER id="EVT_ID_GPIO_LINEIN_PLUG_IN" proc="mmi_linein_proc" />
    <RECEIVER id="EVT_ID_GPIO_LINEIN_PLUG_OUT" proc="mmi_linein_proc" />
    #endif
    /* Earphone */
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_linein_proc" />
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_linein_proc" />
    <!--End Receiving Evt ID -->
    <!--------------------------------------------------------------------------------------------------------------------->

    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Sending Evt ID -->
    <!--End Sending Evt ID -->
    <!--------------------------------------------------------------------------------------------------------------------->
    
    
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--NVRAM LID -->
    <CACHEDATA type="byte" id="NVRAM_LINEIN_VOLUME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x08] </DEFAULT_VALUE>
        <DESCRIPTION> line-in volume </DESCRIPTION>
    </CACHEDATA>
    #ifdef __MMI_BTBOX_NOLCD__
    <CACHEDATA type="byte" id="NVRAM_LINEIN_ENABLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xff] </DEFAULT_VALUE>
        <DESCRIPTION> line-in is enable or not </DESCRIPTION>
    </CACHEDATA>
    #endif  //__MMI_BTBOX_NOLCD__
    <!--End NVRAM LID -->
    <!--------------------------------------------------------------------------------------------------------------------->

    
    #ifdef __MMI_BTBOX_NOLCD__
    <AUDIO id="AUD_ID_BTBOX_LINE_IN_ENTER" desc="Line In Enter" path="Linein_Plugin.mp3">CUST_ADO_PATH"\\\\BTBOX\\\\Linein_Plugin.mp3"</AUDIO>
    
    <NOTIFY id="BTBOX_LINE_IN_ENTER" desc="Line In Enter" led="INPUT_EVENT_LED_ID_3" voice="AUD_ID_BTBOX_LINE_IN_ENTER" />
    <NOTIFY id="BTBOX_LINE_IN_VOL_CHANGE" desc="Line In Volume Change" led="INPUT_EVENT_LED_ID_15" />
    <NOTIFY id="BTBOX_LINE_IN_MUTE" desc="Line In Mute" led="INPUT_EVENT_LED_ID_14" />

    <EVENT id="EVT_ID_BTBOX_LINE_IN_MUTE_UNMUTE" type="SENDER" />
    <EVENT id="EVT_ID_BTBOX_LINE_IN_VOL_UP" type="SENDER" />
    <EVENT id="EVT_ID_BTBOX_LINE_IN_VOL_DOWN" type="SENDER" />
    
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_MUTE_UNMUTE" key_code="KEY_2" key_type="KEY_EVENT_UP" evt_desc="Line In Mute/Unmute" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_UP" key_code="KEY_0" key_type="KEY_EVENT_UP" evt_desc="Line In Volume Up" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_DOWN" key_code="KEY_1" key_type="KEY_EVENT_UP" evt_desc="Line Volume Down" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_UP" key_code="KEY_0" key_type="KEY_EVENT_REPEAT" evt_desc="Line Volume Up" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_DOWN" key_code="KEY_1" key_type="KEY_EVENT_REPEAT" evt_desc="Line Volume Down" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_UP" key_code="KEY_0" key_type="KEY_EVENT_LONG_PRESS" evt_desc="Line Volume Up" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_DOWN" key_code="KEY_1" key_type="KEY_EVENT_LONG_PRESS" evt_desc="Line Volume Down" />
    #ifdef __MMI_BTB_AT_KEY_SUPPORT__
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_UP" key_code="KEY_8" key_type="KEY_EVENT_UP" evt_desc="Line Volume Up" />
    <INPUT_EVENT grp_id="GRP_ID_LINEIN" evt_id="EVT_ID_BTBOX_LINE_IN_VOL_DOWN" key_code="KEY_9" key_type="KEY_EVENT_UP" evt_desc="Line Volume Down" />
    #endif  //__MMI_BTB_AT_KEY_SUPPORT__
    #endif  //__MMI_BTBOX_NOLCD__
</APP>

#endif  //__MMI_LINE_IN__
