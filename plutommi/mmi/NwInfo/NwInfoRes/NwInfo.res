/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_NW_INFO">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

#ifdef __MMI_NW_INFO_INVALID_SIM_MESSAGE__

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_NW_INFO_INVALID_SIM_TITLE"/>
#if (MMI_MAX_SIM_NUM == 1)
    <STRING id="STR_ID_NW_INFO_INVALID_SIM_MSG"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    <STRING id="STR_ID_NW_INFO_INVALID_SIMX_MSG_NAME"/>
#else
    <STRING id="STR_ID_NW_INFO_INVALID_SIMX_MSG"/>
#endif
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_NW_INFO"/>
    <SCREEN id="SCR_ID_NW_INFO_INVALID_SIM1"/>
    <SCREEN id="SCR_ID_NW_INFO_INVALID_SIM2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <SCREEN id="SCR_ID_NW_INFO_INVALID_SIM3"/>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    <SCREEN id="SCR_ID_NW_INFO_INVALID_SIM4"/>
#endif
    
    <RECEIVER id="EVT_ID_SRV_NW_INFO_REGISTER_FAILED" proc="mmi_nw_info_on_register_failed"/>

#endif /* __MMI_NW_INFO_INVALID_SIM_MESSAGE__ */
    
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_nw_info_on_sim_availablity_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_nw_info_signal_on_mode_switched"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_STATUS_CHANGED" proc="mmi_nw_info_on_status_changed"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_nw_info_signal_on_service_avai_changed"/>
#ifdef __HOMEZONE_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED" proc="mmi_nw_info_on_homezone_status_changed"/>
#endif
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED" proc="mmi_nw_info_signal_on_strength_changed"/>

#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ // slim_icon
#if (MMI_MAX_SIM_NUM >= 2)
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_SLOT_READY" proc="mmi_nw_info_on_sim_slot_ready"/>
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_SLOT_READY" proc="mmi_nw_info_signal_on_sim_slot_ready"/>
#endif
#endif /* __MMI_NW_INFO_DN_STATUS_SLIM__ */ // slim_icon

#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    <RECEIVER id="EVT_ID_SRV_CALLSET_LINE_SWITCHED" proc="mmi_nw_info_signal_on_line_switched"/>
    <RECEIVER id="EVT_ID_SRV_CPHS_CSP_REFRESH" proc="mmi_nw_info_signal_on_csp_refreshed"/>
#endif

#if defined(__SIM_HOT_SWAP_SUPPORT__) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_nw_info_icon_on_sim_event"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_nw_info_signal_on_sim_event"/>
#endif

</APP>
