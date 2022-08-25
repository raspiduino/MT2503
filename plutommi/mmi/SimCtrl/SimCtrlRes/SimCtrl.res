/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SIM_CTRL">

#if !defined(__MMI_SIM_CTRL_SLIM__)

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#if (MMI_MAX_SIM_NUM == 1)
    <STRING id="STR_ID_SIM_CTRL_SIM_ACCESS_ERROR"/>
#else
    <STRING id="STR_ID_SIM_CTRL_SIMX_ACCESS_ERROR"/>
#endif

#endif /* !defined(__MMI_SIM_CTRL_SLIM__) */

#ifdef __SIM_HOT_SWAP_SUPPORT__

#if (MMI_MAX_SIM_NUM == 1)
    <STRING id="STR_ID_SIM_CTRL_SIM_INSERTED"/>
    <STRING id="STR_ID_SIM_CTRL_SIM_REMOVED"/>
#else
    <STRING id="STR_ID_SIM_CTRL_SIMX_INSERTED"/>
    <STRING id="STR_ID_SIM_CTRL_SIMX_REMOVED"/>
#endif

#endif /* __SIM_HOT_SWAP_SUPPORT__ */

#if !defined(__MMI_SIM_CTRL_SLIM__)

#if !defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
#if (MMI_MAX_SIM_NUM == 1)
    <STRING id="STR_ID_SIM_CTRL_SIM_CAME_OFF"/>
#else
    <STRING id="STR_ID_SIM_CTRL_SIMX_CAME_OFF"/>
#endif
#endif

#endif /* !defined(__MMI_SIM_CTRL_SLIM__) */


#if (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__)
    <STRING id="STR_ID_SIM_CTRL_SIM_TIP"/>
#ifdef __MMI_3G_SWITCH__
    <STRING id="STR_ID_SIM_CTRL_3G_SLOT_HINT_SWITCH_CFG"/>
#else
    <STRING id="STR_ID_SIM_CTRL_3G_SLOT_HINT"/>
#endif
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SIM_CTRL"/>
#if (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__)
    <SCREEN id="SCR_ID_SIM_CTRL_3G_SLOT_HINT"/>
#endif
    
#if !defined(__MMI_SIM_CTRL_SLIM__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_sim_ctrl_on_sim_availability_changed"/>
#endif
#ifdef  __SIM_HOT_SWAP_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_sim_ctrl_on_sim_event_detected"/>
#endif

</APP>

