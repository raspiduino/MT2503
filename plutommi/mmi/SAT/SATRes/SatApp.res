/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * SatApp.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 *  Xiaolin Chen (mtk80776)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 12 04 2012 vikrant.jaiswal
 * [MAUI_03282851] Remove SAT related image  IMG_ID_SAT_SIM1_TITLE for Slim
 * .
 *
 * 06 13 2012 sparsh.birla
 * [MAUI_03200013] the "setup idle mode text" icon on the status bar shows wrong
 * .
 *
 * 05 09 2012 xiaolin.chen
 * [MAUI_03181400] It should close STK screen when flight mode is on
 * .
 *
 * 05 02 2012 xiaolin.chen
 * [MAUI_03178055] STK icons not coming
 * .
 *
 * 11 23 2011 xiaolin.chen
 * [MAUI_03085402] [SAT][Pluto] language notification
 * .
 *
 * 11 18 2011 xiaolin.chen
 * [MAUI_03011995] [STK]UE displays unexpected text "Done" after rejecting to send USSD
 * .
 *
 * 11 10 2011 yan.liang
 * [MAUI_03077746] [MMI FRM]Fix callback manager spelling mistake
 * <saved by Perforce>
 *
 * 07 19 2011 xiaolin.chen
 * [MAUI_02985261] There should be icon or number for the STK in the service menu
 * .
 *
 * 05 30 2011 xiaolin.chen
 * [MAUI_02951937] [SAT][Slim] Resource Image revise
 * .
 *
 * 05 27 2011 xiaolin.chen
 * [MAUI_02949184] STK icon missing
 * .
 *
 * 04 28 2011 xiaolin.chen
 * [MAUI_02924334] [SAT] Refresh String ID and remove header files
 * .
 *
 * 01 13 2011 xiaolin.chen
 * [MAUI_02648267] [SAT][Gemini+]Setup call modify
 * .
 *
 * 12 14 2010 gajendra.dadheech
 * [MAUI_02446785] [GEMINI+] MAUI Checkins
 * .GEMINI+ changes
 *
 * 12 07 2010 xiaolin.chen
 * [MAUI_02643090] [SAT] Fix build error
 * Fix Build error.
 *
 * 12 03 2010 mingliang.xu
 * [MAUI_02639002] [New feature] SAT app/srv split check in
 * .
 *
 * 11 26 2010 xiaolin.chen
 * [MAUI_02639002] [New feature] SAT app/srv split check in
 * SAT app/srv split check in.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SAT">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_srv_sat_def.h, mmi_rp_app_mainmenu_def.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_SAT_SIM_REFRESH"/>
    <STRING id="STR_ID_SAT_GET_INPUT_LENGTH_NOT_ENOUGH"/>
    <STRING id="STR_ID_SAT_LANGUAGE_CHANGED"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* For the detail of scope="XML" please check user manual */
#ifndef __MMI_OP12_MENU_12MATRIX__
#ifndef __MMI_SLIM_IMG_RES__

#if (MMI_MAX_SIM_NUM >= 2)
#ifndef __MMI_SAT_ULTRA_SLIM__		//MAUI_03282851  -slim
    <IMAGE id="IMG_ID_SAT_SIM1_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\SAT\\\\SB_SIM_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SAT_SIM2_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\SAT\\\\SB_SIM_2.bmp"</IMAGE>
#endif /*__MMI_SAT_ULTRA_SLIM__*/

#if (MMI_MAX_SIM_NUM >= 3)
#ifndef __MMI_SAT_ULTRA_SLIM__		//MAUI_03282851  -slim
    <IMAGE id="IMG_ID_SAT_SIM3_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\SAT\\\\SB_SIM_3.bmp"</IMAGE>
#endif /*__MMI_SAT_ULTRA_SLIM__*/

#if (MMI_MAX_SIM_NUM >= 4)
#ifndef __MMI_SAT_ULTRA_SLIM__		//MAUI_03282851  -slim
    <IMAGE id="IMG_ID_SAT_SIM4_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\GeminiPlus\\\\SAT\\\\SB_SIM_4.bmp"</IMAGE>
#endif /*__MMI_SAT_ULTRA_SLIM__*/

#endif
#endif

#else
#ifndef __MMI_SAT_ULTRA_SLIM__		//MAUI_03282851  -slim
    <IMAGE id="IMG_ID_SAT_SIM1_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Services\\\\SIMToolKit\\\\SB_SIM.bmp"</IMAGE>
#endif /*__MMI_SAT_ULTRA_SLIM__*/

#endif /* MMI_MAX_SIM_NUM */

#endif /* __MMI_SLIM_IMG_RES__ */
#endif /* __MMI_OP12_MENU_12MATRIX__ */

#ifdef __MMI_NCENTER_SUPPORT__
     <IMAGE id="IMG_ID_APP_SAT_PREVIEW">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\SAT.png"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#ifndef __MMI_OP12_MENU_12MATRIX__
    <MENUITEM id="MENU_ID_SAT1_ENTRY" str="STR_ID_SAT_MENU_TITLE"
#ifndef __MMI_SAT_ULTRA_SLIM__			//MAUI_03282851  -slim
        #ifndef __MMI_SLIM_IMG_RES__
            img="IMG_ID_SAT_SIM1_TITLE"
        #endif
#endif /* __MMI_SAT_ULTRA_SLIM__ */
        highlight="mmi_service_hilite_sat_hdlr" parent = "MAIN_MENU_SERVICES_MENUID"/>

#if (MMI_MAX_SIM_NUM >=2)
    <MENUITEM id="MENU_ID_SAT2_ENTRY" str="STR_ID_SAT_MENU_TITLE"
#ifndef __MMI_SAT_ULTRA_SLIM__			//MAUI_03282851  -slim
        #ifndef __MMI_SLIM_IMG_RES__
            img="IMG_ID_SAT_SIM2_TITLE"
        #endif
#endif /* __MMI_SAT_ULTRA_SLIM__ */
        highlight="mmi_service_hilite_sat_hdlr" parent = "MAIN_MENU_SERVICES_MENUID"/>

#if (MMI_MAX_SIM_NUM >= 3)
    <MENUITEM id="MENU_ID_SAT3_ENTRY" str="STR_ID_SAT_MENU_TITLE"
#ifndef __MMI_SAT_ULTRA_SLIM__				//MAUI_03282851  -slim
        #ifndef __MMI_SLIM_IMG_RES__
            img="IMG_ID_SAT_SIM3_TITLE"
        #endif
#endif /* __MMI_SAT_ULTRA_SLIM__ */
        highlight="mmi_service_hilite_sat_hdlr" parent = "MAIN_MENU_SERVICES_MENUID"/>

#if (MMI_MAX_SIM_NUM >= 4)
    <MENUITEM id="MENU_ID_SAT4_ENTRY" str="STR_ID_SAT_MENU_TITLE"
#ifndef __MMI_SAT_ULTRA_SLIM__				//MAUI_03282851  -slim
        #ifndef __MMI_SLIM_IMG_RES__
            img="IMG_ID_SAT_SIM4_TITLE"
        #endif
#endif /* __MMI_SAT_ULTRA_SLIM__ */
        highlight="mmi_service_hilite_sat_hdlr" parent = "MAIN_MENU_SERVICES_MENUID"/>

#endif
#endif
#endif /* MMI_MAX_SIM_NUM */

#endif /* __MMI_OP12_MENU_12MATRIX__ */

    <!--Option Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */
    <MENUITEM id="MENU_ID_SAT_INPUT_DONE_OPT" str="STR_GLOBAL_DONE"/>

    <MENU id="MENU_ID_SAT_INPUT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SAT_INPUT_DONE_OPT</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SAT_INPUT_OPT"/>
    <SCREEN id="SCR_ID_SAT_CMD_SCREEN"/>

    <RECEIVER id="EVT_ID_SRV_SAT_PROACTIVE_SIM" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SETUP_MENU" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SESSION_END" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_CTRL_INFO" proc="mmi_sat_recv_ind"/>

    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_sat_recv_ucm_ind"/>
    <RECEIVER id="EVT_ID_IDLE_ENTER" proc="mmi_sat_recv_idle_ind"/>

#ifdef __MMI_NCENTER_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_sat_mode_switch_proc"/>
#endif

</APP>
