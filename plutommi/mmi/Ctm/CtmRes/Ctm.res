#ifdef __CTM_SUPPORT__
#include "MMI_features.h"
#ifdef DEVELOPER_BUILD_FIRST_PASS

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_CTM">


<!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_CTM_INDICATION" proc="mmi_ctm_ind_hdlr"/>

<!-- 
**************************************** String section ***************************************
-->

    <STRING id="STR_ID_CTM_DROP"/>
    <STRING id="STR_ID_CTM_CONNECTING"/>
    <STRING id="STR_ID_CTM_CONVERSATION"/>
    <STRING id="STR_ID_CTM_REMOTE"/>
    <STRING id="STR_ID_CTM_LOCAL"/>
    <STRING id="STR_ID_CTM_TTY_PLUG_IN"/>
    <STRING id="STR_ID_CTM_TTY_PLUG_OUT"/>

<!-- 
**************************************** Screen section ***************************************
-->

    <SCREEN id ="GRP_ID_CTM"/>
    <SCREEN id ="SCR_ID_CTM_CONNECTING"/>    
    <SCREEN id ="SCR_ID_CTM_TALKING"/>

</APP>

#endif
#endif

