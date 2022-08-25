/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "CustomCfg.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_SS">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SS_ACT_NOTIFY" proc="mmi_ss_hdlr_act_notify"/>
    <RECEIVER id="EVT_ID_SRV_SS_INDICATION" proc="mmi_ss_hdlr_ind"/>
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_ss_sim_availability_changed_hdlr"/>
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */    
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_SS_TITLE"/>
    <STRING id="STR_ID_SS_REQUESTING"/>
    <STRING id="STR_ID_SS_USSD_MSG"/>
    <STRING id="STR_ID_SS_PERIOD"/>
    <STRING id="STR_ID_SS_SECOND"/>
    <STRING id="STR_ID_SS_CHANGE_PSW_SUC"/>
    <STRING id="STR_ID_SS_CANCELLED"/>


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* Timer ID of you Application */

    <TIMER id="USSR_SESSION_TIMER"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* For the detail of scope="XML" please check user manual */



    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <MENUITEM id="MENU_ID_SS_SIM1" str="STR_GLOBAL_SIM_1"/>
    <MENUITEM id="MENU_ID_SS_SIM2" str="STR_GLOBAL_SIM_2"/>
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#if (MMI_MAX_SIM_NUM >= 3)
    <MENUITEM id="MENU_ID_SS_SIM3" str="STR_GLOBAL_SIM_3"/>
#if (MMI_MAX_SIM_NUM >= 4)
    <MENUITEM id="MENU_ID_SS_SIM4" str="STR_GLOBAL_SIM_4"/>
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    <MENU id="MENU_ID_SS_TYPE_SELECT" type="APP_SUB" str="STR_ID_SS_TITLE" flag="NONMOVEABLE">
        <MENUITEM_ID>MENU_ID_SS_SIM1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SS_SIM2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SS_SIM3</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SS_SIM4</MENUITEM_ID>
    </MENU>
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    <MENU id="MENU_ID_SS_TYPE_SELECT" type="APP_SUB" str="STR_ID_SS_TITLE" flag="NONMOVEABLE">
        <MENUITEM_ID>MENU_ID_SS_SIM1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SS_SIM2</MENUITEM_ID>
    </MENU>
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */



    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <SCREEN id="GRP_ID_SS_COMMON"/>
    <SCREEN id="GRP_ID_SS_SIM1"/>
    <SCREEN id="GRP_ID_SS_SIM1_USSR"/>
    <SCREEN id="GRP_ID_SS_SIM2"/>
    <SCREEN id="GRP_ID_SS_SIM2_USSR"/>
    <SCREEN id="GRP_ID_SS_SIM3"/>
    <SCREEN id="GRP_ID_SS_SIM3_USSR"/>
    <SCREEN id="GRP_ID_SS_SIM4"/>
    <SCREEN id="GRP_ID_SS_SIM4_USSR"/>

    <SCREEN id="SCR_ID_SS_REQUESTING"/>
    <SCREEN id="SCR_ID_SS_USSR"/>
    <SCREEN id="SCR_ID_SS_USSN"/>
    <SCREEN id="SCR_ID_SS_RESULT"/>





</APP>
