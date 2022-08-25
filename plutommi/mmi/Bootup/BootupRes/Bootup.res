/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_BOOTUP">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__  // slim_string
    <STRING id="STR_ID_BOOTUP_NAND_NOT_SUPPORTED"/>
    <STRING id="STR_ID_BOOTUP_USER_DRIVE_CORRUPTED"/>
    <STRING id="STR_ID_BOOTUP_SYSTEM_DRIVE_CORRUPTED"/>
    <STRING id="STR_ID_BOOTUP_NAND_VERSION_MISMATCH"/>
#endif // slim_string

    <STRING id="STR_ID_BOOTUP_NAND_QUOTA_OVER_DISK"/>
    <STRING id="STR_ID_BOOTUP_NAND_QUOTA_USAGE_WARNING"/>
#ifdef __FLIGHT_MODE_SUPPORT__
    <STRING id="STR_ID_BOOTUP_FLIGHT_MODE_ASK"/>
#endif    
    <STRING id="STR_ID_BOOTUP_SOFTKEY_EMERGENCY"/>
    <STRING id="STR_ID_BOOTUP_INPUT_PHONE_PASSWORD"/>
    <STRING id="STR_ID_BOOTUP_WRONG_PHONE_PASSWORD"/>
    <STRING id="STR_ID_BOOTUP_EMERGENCY_CALL_ASK"/>
    <STRING id="STR_ID_BOOTUP_REMAINING_TRIALS_PROMPT"/>
    
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_BOOTUP_INPUT_CHV1"/>
    <STRING id="STR_ID_BOOTUP_INPUT_UBCHV1"/>
    <STRING id="STR_ID_BOOTUP_NEW_CHV1"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
#ifndef __MMI_MAINLCD_96X64__
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_CHV1"/>
#else
		<STRING id="STR_ID_BOOTUP_SIMX_INPUT_CHV1_BWUI"/>
#endif
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_UBCHV1"/>
    <STRING id="STR_ID_BOOTUP_SIMX_NEW_CHV1"/>
#endif

    <STRING id="STR_ID_BOOTUP_WRONG_CHV1"/>
    <STRING id="STR_ID_BOOTUP_WRONG_UBCHV1"/>
    <STRING id="STR_ID_BOOTUP_CONFIRM_NEW_CHV1"/>
    <STRING id="STR_ID_BOOTUP_CHV1_NOT_MATCH"/>

#ifdef __SIM_ME_LOCK__

#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_BOOTUP_INPUT_NP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_NSP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_SP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_CP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_SIMP"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_NP"/>
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_NSP"/>
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_SP"/>
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_CP"/>
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_SIMP"/>
#endif

#ifdef __MMI_SML_MENU__
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_BOOTUP_INPUT_NSSP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_SIMCP"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_NSSP"/>
    <STRING id="STR_ID_BOOTUP_SIMX_INPUT_SIMCP"/>
#endif
#endif /* __MMI_SML_MENU__ */

    <STRING id="STR_ID_BOOTUP_WRONG_NP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_NSP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_SP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_CP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_SIMP"/>
#ifdef __MMI_SML_MENU__
    <STRING id="STR_ID_BOOTUP_WRONG_NSSP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_SIMCP"/>
#endif /* __MMI_SML_MENU__ */

#endif /* __SIM_ME_LOCK__ */

#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_BOOTUP_SIM_ACCESS_ERROR"/>
    <STRING id="STR_ID_BOOTUP_SIM_CHV1_BLOCKED"/>
    <STRING id="STR_ID_BOOTUP_SIM_BLOCKED"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_BOOTUP_SIMX_ACCESS_ERROR"/>
    <STRING id="STR_ID_BOOTUP_SIMX_CHV1_BLOCKED"/>
    <STRING id="STR_ID_BOOTUP_SIMX_BLOCKED"/>
#endif

#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__  // slim_string
    <STRING id="STR_ID_BOOTUP_FORMATING"/>
#endif // slim_string
    
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_BOOTUP_SELECT_SIM"/>
#endif
#if (MMI_MAX_SIM_NUM == 2)
    <STRING id="STR_ID_BOOTUP_DUAL_SIM"/>
    <STRING id="STR_ID_BOOTUP_SIM1_ONLY"/>
    <STRING id="STR_ID_BOOTUP_SIM2_ONLY"/>
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_BOOTUP_SIMX_NOT_INSERTED"/>
    <STRING id="STR_ID_BOOTUP_SIM_NOT_SELECTED"/>
#endif

    <STRING id="STR_ID_BOOTUP_WAIT_FOR_SIM"/>


#ifdef __SIM_HOT_SWAP_SUPPORT__
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_BOOTUP_SIM_REMOVED"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_BOOTUP_SIMX_REMOVED"/>
#endif
#endif

#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_BOOTUP_SIM_CAME_OFF"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_BOOTUP_SIMX_CAME_OFF"/>
#endif


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __MMI_SUBLCD__
    <IMAGE id="IMG_ID_BOOTUP_SUBLCD_ANIMATION">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_ON.gif"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

#if (MMI_MAX_SIM_NUM == 2)
    <MENU id="MENU_ID_BOOTUP_SIM_SELECTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_BOOTUP_DUAL_SIM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_BOOTUP_SIM1_ONLY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_BOOTUP_SIM2_ONLY</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_BOOTUP_DUAL_SIM" str="STR_ID_BOOTUP_DUAL_SIM"/>
    <MENUITEM id="MENU_ID_BOOTUP_SIM1_ONLY" str="STR_ID_BOOTUP_SIM1_ONLY"/>
    <MENUITEM id="MENU_ID_BOOTUP_SIM2_ONLY" str="STR_ID_BOOTUP_SIM2_ONLY"/>
#endif

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_BOOTUP"/>
    <SCREEN id="SCR_ID_BOOTUP_BASE"/>
#ifndef __MMI_BOOTUP_DISK_CHECK_SLIM__ // slim_string
    <SCREEN id="SCR_ID_BOOTUP_DISK_CHECK_FORMAT_QUERY"/>
    <SCREEN id="SCR_ID_BOOTUP_DISK_CHECK_FORMATTING"/>
#endif // slim_string

    <SCREEN id="SCR_ID_BOOTUP_SIM_SELECTION"/>
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    <SCREEN id="SCR_ID_BOOTUP_FLIGHT_MODE_QUERY"/>
#endif
    <SCREEN id="SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END"/>
    <SCREEN id="SCR_ID_BOOTUP_ANIMATION"/>
    <SCREEN id="SCR_ID_BOOTUP_DUMMY_WAITING"/>
    <SCREEN id="SCR_ID_BOOTUP_REAL_WAITING"/>
    <SCREEN id="SCR_ID_BOOTUP_PHONE_LOCK"/>
    <SCREEN id="SCR_ID_BOOTUP_CHV1_OR_PER"/>
    <SCREEN id="SCR_ID_BOOTUP_UBCHV1"/>
    <SCREEN id="SCR_ID_BOOTUP_NEW_CHV1"/>
    <SCREEN id="SCR_ID_BOOTUP_CONFIRM_NEW_CHV1"/>
    <SCREEN id="SCR_ID_BOOTUP_PER_LOCK_WAITING"/>
    <SCREEN id="SCR_ID_BOOTUP_PEN_CALIBRATION_BASE"/>

#if 0 // slim_string
    <SCREEN id="SCR_ID_BOOTUP_WELCOME"/>
#endif // slim_string

    <SENDER id="EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED" hfile="BootupAppGprot.h"/>
        
    <RECEIVER id="EVT_ID_SRV_BOOTUP_START" proc="mmi_bootup_flow_start"/>
    <RECEIVER id="EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED" proc="mmi_bootup_set_scenario_for_interrupt"/>
#ifdef __MMI_TELEPHONY_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED" proc="mmi_bootup_sec_on_sim_status_changed"/>
#if defined (__MMI_BOOTUP_MODE_SEL_SUPPORT__) && (MMI_MAX_SIM_NUM >= 2)
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED" proc="mmi_bootup_mode_on_sim_status_changed"/>
#endif
#endif
    <CACHEDATA type="short" id="NVRAM_POWER_ON_DISPLAY_SUCCESS">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
    
#ifdef __MMI_BT_DIALER_SUPPORT__    
        <CACHEDATA type="short" id="NVRAM_BT_DIALER_FIRST_BOOT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION>first boot </DESCRIPTION>
    </CACHEDATA>
#endif    
    <TIMER id="BOOTUP_WAITING_EVENT_TIMER"/>
    <TIMER id="BOOTUP_ANIMATION_TIMER"/>
    <TIMER id="BOOTUP_WAITING_SCREEN_TIMER"/>

#ifdef __MMI_BTBOX_NOLCD__
    <!--INPUT EVENT notify area-->
    <NOTIFY id="INPUT_EVENT_NOTIFY_AUDPLY" led="INPUT_EVENT_LED_ID_1"  voice="AUD_ID_BOOTUP_BTBOX_WELCOME"/>
    <AUDIO id="AUD_ID_BOOTUP_BTBOX_WELCOME">CUST_ADO_PATH"\\\\BTBox\\\\bootup.mp3"</AUDIO>
#endif
</APP>

