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
 * vCard.res
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
 * Li (mtk80244)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 08 29 2011 f.wang
 * [MAUI_03012945] [Phonebook] Can not exit vCard details screen directly
 * .
 *
 * 12 15 2010 varun.nayyar
 * [MAUI_02643995] [AP1][Internal] Merge GEMINI+ check-ins to MAUI
 * Wrap GEMINI code under MMI_MAX_SIM_NUM.
 *
 * 12 14 2010 varun.nayyar
 * [MAUI_02643995] [AP1][Internal] Merge GEMINI+ check-ins to MAUI
 * GEMINI+ check-ins to MAUI.
 *
 * 09 01 2010 mingliang.xu
 * [MAUI_02633806] [New feature] vCard revise check in
 * .
 *
 * Apr 14 2010 mtk80244
 * [MAUI_02179311] [Vcard] pluto_10A
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VCARD">

#ifdef __MMI_VCARD__
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_vobject_def.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
    
    <STRING id="STR_ID_VCARD_NAME_EMPTY"/>
    <STRING id="STR_ID_VCARD_FILE_TO_LARGE"/>
    <STRING id="STR_ID_VCARD_VCARD_DETAILS"/>
#ifdef __MMI_MULTI_VCARD__
    <STRING id="STR_ID_VCARD_EXPORT_WARNING"/>
    <STRING id="STR_ID_VCARD_IMPORT_WARNING"/>
    <STRING id="STR_ID_VCARD_EXPORTING"/>
    <STRING id="STR_ID_VCARD_IMPORTING"/>
    <STRING id="STR_ID_VCARD_EXPORTING"/>
    <STRING id="STR_ID_VCARD_IMPORTING"/>
    <STRING id="STR_ID_VCARD_EXPORT_COMPLETE"/>
    <STRING id="STR_ID_VCARD_IMPORT_COMPLETE"/>
    <STRING id="STR_ID_VCARD_EXPORT_COMPLETE2"/>
    <STRING id="STR_ID_VCARD_IMPORT_COMPLETE2"/>
    <STRING id="STR_ID_VCARD_EXPORT_FAIL"/>
    <STRING id="STR_ID_VCARD_IMPORT_FAIL"/>
    <STRING id="STR_ID_VCARD_EXPORT_FAIL2"/>
    <STRING id="STR_ID_VCARD_IMPORT_FAIL2"/>
#endif

#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VCARD_SAVE_TO_SIM1"/>
    <STRING id="STR_ID_VCARD_SAVE_TO_SIM2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_VCARD_SAVE_TO_SIM3"/>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_VCARD_SAVE_TO_SIM4"/>
#endif
#else
    <STRING id="STR_ID_VCARD_SAVE_TO_SIM"/>
#endif
    <STRING id="STR_ID_VCARD_SAVE_TO_PHONE"/>

    <!--End String Resource Area-->
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
    <!--Screen ID Area-->

    <SCREEN id = "SCR_ID_VCARD_FORWARD_OPTION"/>
    <SCREEN id = "SCR_ID_VCARD_RECV_VIEW_DETAIL"/>
    <SCREEN id = "SCR_ID_VCARD_RECV_OPT"/>
    <SCREEN id = "SCR_ID_VCARD_ENTER_FILENAME"/>
    <SCREEN id = "SCR_ID_VCARD_ENTER_FILENAME_OPT"/>
    <SCREEN id = "SCR_ID_VCARD_EXPORTING"/>
    <SCREEN id = "SCR_ID_VCARD_IMPORTING"/>
    <SCREEN id = "GRP_ID_VCARD_BEGIN"/>
    <SCREEN id = "GRP_ID_VCARD_RECEVE"/>
    <SCREEN id = "GRP_ID_VCARD_END"/>
    <SCREEN id = "GRP_ID_VCARD_ENUM_TOTAL"/>

    <!--End Screen Resource Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Menu Item Area-->

#if (MMI_MAX_SIM_NUM >= 2)
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_SIM" str="STR_ID_VCARD_SAVE_TO_SIM1"/>
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_SIM2" str="STR_ID_VCARD_SAVE_TO_SIM2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_SIM3" str="STR_ID_VCARD_SAVE_TO_SIM3"/>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_SIM4" str="STR_ID_VCARD_SAVE_TO_SIM4"/>
#endif
#else
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_SIM" str="STR_ID_VCARD_SAVE_TO_SIM"/>
#endif /* MMI_MAX_SIM_NUM */
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_PHONE" str="STR_ID_VCARD_SAVE_TO_PHONE"/>
#if defined(__MMI_FILE_MANAGER__)
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_FMGR" str="STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>
#endif /* defined(__MMI_FILE_MANAGER__) */

    <MENU id="MENU_ID_VCARD_RECV_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_PHONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_SIM</MENUITEM_ID>
#if (MMI_MAX_SIM_NUM >= 2)        
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_SIM2</MENUITEM_ID>
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_SIM3</MENUITEM_ID>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_SIM4</MENUITEM_ID>
#endif
#ifdef __MMI_FILE_MANAGER__
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_FMGR</MENUITEM_ID>
#endif        
    </MENU>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_vcard_sim_profile_hdlr"/>
    <!--End Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
#endif /* __MMI_VCARD__ */
</APP>

