/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  Idle.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the Sim Space application.
 *
 * Author:
 * -------
 *  Digvijay Arya (mtk33160)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 10 2011 yan.liang
 * [MAUI_03077746] [MMI FRM]Fix callback manager spelling mistake
 * <saved by Perforce>
 *
 * 04 28 2011 weilun.liu
 * [MAUI_02924219] [simspace] solve build error
 * wrapped pluto compile option
 *
 * 12 30 2010 digvijay.arya
 * [MAUI_02445542] [Gemini+] IdleApp/SimSpace/Dialler Patch
 * Removed GEMINI_PLUS compile option from MMI.
 *
 * 12 21 2010 digvijay.arya
 * [MAUI_02446878] [Gemini+] SimSpace file revise
 * Sim Space file revision
 *
 * 12 14 2010 digvijay.arya
 * [MAUI_02445542] [Gemini+] IdleApp/SimSpace/Dialler Patch
 * GeminiPlus Merge to MAUI.
 *
 * 12 07 2010 digvijay.arya
 * [MAUI_02445542] [Gemini+] IdleApp/SimSpace/Dialler Patch
 * GeminiPlus chekin to 10A.
 *
 * 11 26 2010 digvijay.arya
 * [MAUI_02445542] [Gemini+] IdleApp/SimSpace/Dialler Patch
 * Separated 
 * SimSpace related code.
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_SIMSPACE">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>

#if (MMI_MAX_SIM_NUM >= 3) && defined(__PLUTO_MMI_PACKAGE__)
    <!----- String Resource Area ---------------------------------------------->
#if 0
    <STRING id="STR_ID_SS_SETTING_SIM1">"SIM1"</STRING>
    <STRING id="STR_ID_SS_SETTING_SIM2">"SIM2"</STRING>
    <STRING id="STR_ID_SS_SETTING_SIM3">"SIM3"</STRING>
    <STRING id="STR_ID_SS_SETTING_SIM4">"SIM4"</STRING>
    <STRING id="STR_ID_SIM_SPACE_SETTING">"SIM Setting"</STRING>
    <STRING id="STR_ID_SS_SETTING_ENABLE">"Enable"</STRING>
    <STRING id="STR_ID_SS_SETTING_DISABLE">"Disable"</STRING>
    <STRING id="STR_ID_SS_SETTING_ENABLED">"Enabled"</STRING>
    <STRING id="STR_ID_SS_SETTING_DISABLED">"Disabled"</STRING>
#endif
    <STRING id="STR_ID_SIM_SPACE">"SIM SPACE"</STRING>
    


    <!----- Image Resource Area ----------------------------------------------->

    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_IDLE_SIM_SPACE"/>
    <SCREEN id="SCR_ID_IDLE_SIM_SPACE_VIEW"/>
    <SCREEN id="SCR_ID_IDLE_SIM_SPACE_SETTING"/>
    

    <!----- Menu Resource Area ------------------------------------------------>
#if 0
		<MENU id = "MENU_ID_SIM_SPACE_SETTING" type = "APP_MAIN" str = "STR_ID_SIM_SPACE_SETTING">
		
        <MENUITEM id = "MENU_ID_SIM_SPACE_SET_SIM1" str = "STR_ID_SS_SETTING_SIM1"/>
        <MENUITEM id = "MENU_ID_SIM_SPACE_SET_SIM2" str = "STR_ID_SS_SETTING_SIM2"/>
        <MENUITEM id = "MENU_ID_SIM_SPACE_SET_SIM3" str = "STR_ID_SS_SETTING_SIM3"/>
        <MENUITEM id = "MENU_ID_SIM_SPACE_SET_SIM4" str = "STR_ID_SS_SETTING_SIM4"/>
        
    </MENU>

    <MENU id = "MENU_ID_SIM_SPACE_SETTING_OPTIONS" type = "OPTION" str = "STR_ID_SIM_SPACE_SETTING">
		
        <MENUITEM id = "MENU_ID_SIM_SPACE_SET_ENABLE" str = "STR_ID_SS_SETTING_ENABLE"/>
        <MENUITEM id = "MENU_ID_SIM_SPACE_SET_DISABLE" str = "STR_ID_SS_SETTING_DISABLE"/>
        
    </MENU>
#endif
		<!------------------------------------------------------Other Resource------------>    
		
		<RECEIVER id="EVT_ID_SRV_NW_NAME_CHANGED" proc="mmi_sim_space_evt_hdlr"/>

#endif

</APP>

