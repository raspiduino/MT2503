/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#ifdef __MMI_SML_MENU__

#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SIM_ME_LOCK">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file = "GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_CATEGORY_NP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_NSP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_CP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_SP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_SIMP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_NSP_SP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_SIMP_CP_LOCK"/>

    <STRING id="STR_ID_SML_LOCK_MENU"/>
    <STRING id="STR_ID_SML_UNLOCK_MENU"/>
    <STRING id="STR_ID_SML_ADD_MENU"/>
    <STRING id="STR_ID_SML_REMOVE_MENU"/>
    <STRING id="STR_ID_SML_DEACTIVATE_MENU"/>

    <STRING id="STR_ID_SML_REBOOT_MSG"/>
    <STRING id="STR_ID_SML_QUREY_MSG"/>
    <STRING id="STR_ID_SML_BLOCK_MSG"/>
    <STRING id="STR_ID_SML_NO_EF_GID"/>

    <STRING id="STR_ID_SML_AUTOKEY_CONFIRM"/>
    <STRING id="STR_ID_LAST_RETRY_MSG"/>
    <STRING id="STR_ID_GENERAL_RETRY_MSG"/>
    <STRING id="STR_ID_UNLOCK_FIRST_MSG"/>
    <STRING id="STR_ID_EMPTY_CATEGORY_MSG"/>
    <STRING id="STR_ID_NO_RECORD_MSG"/>
    <STRING id="STR_ID_NO_DATA_MSG"/>

    <STRING id="STR_ID_SML_CAT_LOCKED"/>
    <STRING id="STR_ID_SML_CAT_UNLOCKED"/>
    <STRING id="STR_ID_SML_CAT_AUTOLOCKED"/>
    <STRING id="STR_ID_SML_CAT_DISABLED"/>

    <STRING id="STR_ID_SML_AUTOLOCKED"/>
    <STRING id="STR_ID_SML_FAIL_TO_AUTOLOCK"/>

    <STRING id="STR_ID_SML_NP_DATA"/>
    <STRING id="STR_ID_SML_NSP_DATA"/>
    <STRING id="STR_ID_SML_SP_DATA"/>
    <STRING id="STR_ID_SML_CP_DATA"/>
    <STRING id="STR_ID_SML_SIMP_DATA"/>

    <STRING id="STR_ID_SML_ASK_DELETE_CATEGORY"/>
    <STRING id="STR_ID_SML_ASK_DISABLE_CATEGORY"/>



#ifdef __MMI_DUAL_SIM_MASTER__
    <STRING id="STR_ID_SML_SIM1_AUTO_LOCKED"/>
    <STRING id="STR_ID_SML_SIM2_AUTO_LOCKED"/>
    <STRING id="STR_ID_SML_SIM1_SIM2_AUTO_LOCKED"/>
    <STRING id="STR_ID_SML_SELECT_SIM"/>
#endif

    <STRING id="STR_ID_SML_INPUT_PASSWORD"/>
    <STRING id="STR_ID_SML_CONFIRM_PASSWORD"/>
    <STRING id="STR_ID_SML_DIFF_PASSWORD"/>
    <STRING id="STR_ID_SML_REMAIN_TRIALS"/>
    <STRING id="STR_ID_SML_INVALID_LENGTH"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

#ifdef __MMI_DUAL_SIM_MASTER__
    <MENUITEM id="MENU_ID_SML_SIM1_SELECTED" str="STR_GLOBAL_SIM_1"/>
    <MENUITEM id="MENU_ID_SML_SIM2_SELECTED" str="STR_GLOBAL_SIM_2"/>

    <MENU id="MENU_ID_SML_SIM_SELECTION" type="APP_MAIN">
        <MENUITEM_ID>MENU_ID_SML_SIM1_SELECTED</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SML_SIM2_SELECTED</MENUITEM_ID>
    </MENU>     
#endif

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_SML_LOCK_MENU"/>
    <SCREEN id="SCR_ID_SML_UNLOCK_MENU"/>
    <SCREEN id="SCR_ID_SML_ADD_MENU"/>
    <SCREEN id="SCR_ID_SML_REMOVE_MENU"/>
    <SCREEN id="SCR_ID_SML_DEACTIVATE_MENU"/>

    <SCREEN id="SCR_ID_SML_QUERY_POPUP"/>
    <SCREEN id="SCR_ID_SML_FILL_DATA"/>
    <SCREEN id="SCR_ID_SML_AUTOKEY_CONFIRM"/>
    <SCREEN id="SCR_ID_SML_REMOVE_CONFIRM"/>
    <SCREEN id="SCR_ID_SML_DEACTIVATE_CONFIRM"/>
    <SCREEN id="SCR_ID_SML_INPUT_KEY"/>
    <SCREEN id="SCR_ID_SML_CONFIRM_KEY"/>
    <SCREEN id="SCR_ID_SML_DUMMY"/>

    <SCREEN id="GRP_ID_SML_SIMS"/>
    <SCREEN id="GRP_ID_SML_MAIN"/>
    <SCREEN id="GRP_ID_SML_DATA"/>
    <SCREEN id="GRP_ID_SML_PSWD"/>

    <TIMER id="SML_AUTOLOCK_IDLE_NOTIFY_TIMER"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_sml_sim_status_change"/>
#ifdef __SIM_HOT_SWAP_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_sml_sim_event_detetced"/>
#endif

</APP>

#endif
