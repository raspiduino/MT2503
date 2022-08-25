
#include "MMI_features.h" 
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
    
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_CBM">

#ifdef __TCPIP__

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!------------------------String Resource Area-------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __MMI_WLAN_FEATURES__
    <STRING id="STR_ID_MMI_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR"/>
#ifdef __MMI_OP01_WIFI__
    <STRING id="STR_ID_MMI_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR_NO_MORE_ASK"/>
#endif
    <STRING id="STR_ID_MMI_CBM_WLAN_SIGNAL_AVAILABLE_USE_NOW"/>
    <STRING id="STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED_USE_OTHER"/>
    <STRING id="STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED_USE_CELLULAR"/>
#ifdef __CBM_BEARER_SWITCH__
    <STRING id="STR_ID_MMI_CBM_WLAN_DISCONNECTED_USE_OTHER"/>
    <STRING id="STR_ID_MMI_CBM_WLAN_DISCONNECTED_USE_CELLULAR"/>
    <STRING id="STR_ID_MMI_CBM_WLAN_SIGNAL_AVAILABLE_WARNING"/>
    <STRING id="STR_ID_MMI_CBM_WLAN_DISCONNECTED"/>
#endif
    <STRING id="STR_ID_MMI_CBM_WLAN_CONNECTION_FAILED"/>
    <STRING id="STR_ID_MMI_CBM_USE_WLAN_NETWORK"/>
    <STRING id="STR_ID_MMI_CBM_USE_CELLULAR"/>
#endif /* __MMI_WLAN_FEATURES__ */

    <!------------------------Image Resource Area--------------------------->

    <!-------------------------Menu Resource Area--------------------------->

    <!------------------------Screen Resource Area-------------------------->
    <SCREEN id="GRP_ID_MMI_CBM_APP"/>
    <SCREEN id="SCR_ID_MMI_CBM_NOTIFY"/>

    <!---------------------------Other Resource----------------------------->
    <RECEIVER id="EVT_ID_SRV_CBM_BEARER_INFO" proc="mmi_cbm_handle_cbm_bearer_info"/>
    <RECEIVER id="EVT_ID_SRV_CBM_WLAN_QUERY" proc="mmi_cbm_srv_cbm_wlan_query_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_LOCKED" proc="mmi_cbm_evt_proc_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_cbm_evt_proc_hdlr"/>
#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <RECEIVER id="EVT_ID_VAPP_NCENTER_ENTERED" proc="mmi_cbm_evt_proc_hdlr"/>
    <RECEIVER id="EVT_ID_VAPP_NCENTER_EXITED" proc="mmi_cbm_evt_proc_hdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND" proc="mmi_cbm_evt_proc_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_cbm_evt_proc_hdlr"/>

#endif /* __TCPIP__ */

</APP>
