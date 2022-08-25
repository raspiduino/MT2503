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

/*******************************************************************************
 * Filename:
 * ---------
 * EngineerModePCSNetwork.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the tracer for PS log
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*****************************************************************/
/*************************  Header Files *************************/
/*****************************************************************/

#include "MMI_features.h"


#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

#if defined(__MMI_ENGINEER_MODE__) 

#include "MMIDataType.h"
#include "custom_em.h"
#include "EngineerModeResDef.h"
#include "kal_general_types.h"
#include "em_struct.h"
#include "ps_public_struct.h"
//#include "l4c_common_enum.h"
#include "ps_public_enum.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "GlobalResDef.h"
#include "stack_msgs.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "ImeGprot.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "string.h"
#include "stack_config.h"
#include "wgui_categories.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_rp_app_idle_def.h"
#include "IdleAppResDef.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_frm_input_gprot.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif
#include "gui_switch.h"
#include "wgui.h"
#include "gui.h"
#include "gdi_include.h"
#include "FontRes.h"
#include "gui_themes.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#include "EngineerModeAppResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "stack_common.h"
#ifdef __MMI_EM_NW_BAND_SEL__
#include "NetworkSetupResDef.h"
#endif
#if defined(__MMI_EM_NW_BAND_SEL__)
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif
#endif
#include "wgui_categories_popup.h"

#include "ProtocolEvents.h"
#include "PixcomFontEngine.h"   

#include "SimCtrlSrvGprot.h"

#include "CommonScreens.h"

#ifdef __MODEM_EM_MODE__

#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"
#endif /* #ifdef __MODEM_EM_MODE__ */

#include "NetworkSetupGProt.h"
#include "mmi_frm_utility_gprot.h"

#if defined(__MMI_EM_NW_EVENT_NOTIFY__)
/* under construction !*/
#endif
#include "InlineCuiGprot.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeCommUI.h"
#include "EngineerModePCSNetwork.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommMem.h"
#include "mmi_rp_app_engineermode1_def.h"

#if defined(__MMI_EM_NW_NETWORK_INFO__)||defined(__MMI_EM_NW_EVENT_NOTIFY__)
#include "EngineerMode.h"
#endif

#include "hal_ul1_struct.h"

#ifdef __MMI_EM_NW_SERVICE_MODE_SELECTION__
#include "NetSetAppGprot.h"
#endif

#ifdef __MMI_EM_NW_FDD_NETWORK_INFO__
#include"EngineerMode3GInfo.h"
#endif  /* __MMI_EM_NW_FDD_NETWORK_INFO__*/

#ifdef __MMI_EM_NW_WCDMA_PREFERRED__
/* WCDMA Preferred */
#include "ModeSwitchSrvGProt.h"
#include "SimCtrlSrvGprot.h"
#include "NetSetSrvGprot.h" /*judeg 3g capbility*/

typedef struct {
	S32 sel_cntx_index; 
} em_nw_wcdma_preferred_struct;

em_nw_wcdma_preferred_struct g_em_nw_wcdma_preferred_cntx;
#endif  /* __MMI_EM_NW_WCDMA_PREFERRED__ */

/*****************************************************************/
/****************  Structure / Variables Declaration *************/
/*****************************************************************/

#if defined(__MMI_EM_NW_BAND_SEL__)
typedef enum
{ 
   EM_BAND_SEL_OFF,
   EM_BAND_SEL_ON,
   EM_BAND_SEL_OPT_NUM
} EM_BAND_SEL_OPT;

typedef enum
{
    MMI_3G_BAND_I   = 0x0001,
    MMI_3G_BAND_II  = 0x0002,
    MMI_3G_BAND_III  = 0x0004,
    MMI_3G_BAND_IV   = 0x0008,

    MMI_3G_BAND_V   = 0x0010,

    MMI_3G_BAND_VI   = 0x0020,
    MMI_3G_BAND_VII  = 0x0040,
    MMI_3G_BAND_VIII = 0x0080,
    MMI_3G_BAND_IX   = 0x0100,
    MMI_3G_BAND_X    = 0x0200
} MMI_3G_BAND_SELECTION;

static const U16 BandSel2GInfoList[] = 
{
#ifdef __GSM850__
    MMI_BAND_850,
#endif 
#ifdef __EGSM900__
    MMI_BAND_900,
#endif 
#ifdef __DCS1800__
    MMI_BAND_1800,
#endif 
#ifdef __PCS1900__
    MMI_BAND_1900,
#endif 
#ifdef __GSM850__
#ifdef __DCS1800__
    MMI_BAND_850_1800,
#endif 
#endif /* __GSM850__ */ 
#ifdef __EGSM900__
#ifdef __DCS1800__
    MMI_BAND_DUAL,
#endif 
#endif /* __EGSM900__ */ 
#ifdef __GSM850__
#ifdef __PCS1900__
    MMI_BAND_850_1900,
#endif 
#endif /* __GSM850__ */ 
    MMI_BAND_AUTO,
};

typedef struct {
    U16 band_string;
    U16 band_enum;
} em_nw_band_sel_info_struct;

#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */

typedef struct {
    U32 EmNW2GBandSelHighlight;
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif
} em_nw_band_sel_struct;


em_nw_band_sel_struct g_em_nw_band_sel_cntx = {0};

#endif /* #if defined(__MMI_EM_NW_BAND_SEL__) */


#if defined(__MMI_EM_NW_CELL_LOCK__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_NW_CELL_LOCK__) */

#if defined(__MMI_EM_NW_PLMN_LIST__)

#include "EngineerModeCommUI.h"

typedef struct
{
    U8 item_val;
    U16 item_text;
} mmi_em_nw_plmn_sel_item_struct;

typedef struct
{
    U8 plmn_prefer_val;
    S32 highlight_index;
} mmi_em_nw_plmn_sel_context_struct;

static mmi_em_nw_plmn_sel_context_struct g_em_nw_plmn_sel_cntx;

static const U16 g_em_nw_plmn_sel_item_table[] =
{
    L4C_SPEED_PREFERED,
    L4C_ACCURACY_PREFERED,
};

static void mmi_em_nw_send_get_plmn_list_preference_req(void);
static void mmi_em_nw_get_plmn_list_preference_rsp(void *msg);
static void mmi_em_nw_send_set_plmn_list_preference_req(U8 val);
static void mmi_em_nw_set_plmn_list_preference_rsp(void *msg);
static void mmi_em_nw_plwn_list_hdlr(cui_menu_event_struct *evt);
static void mmi_em_nw_plwn_hdlr(void);
static void mmi_em_nw_plwn_list_pre_hdlr(cui_menu_event_struct *evt);

#ifdef PLMN_TEST
static U8 plmn_test_val = 0;
static void mmi_em_nw_plmn_test_get_req_hdlr(void *msg);
static void mmi_em_nw_plmn_test_set_req_hdlr(void *msg);
#endif

#endif /* __MMI_EM_NW_PLMN_LIST__ */

/*****************************************************************/
/******************  External functions / variables **************/
/*****************************************************************/
#define MMI_EM_NE_ENT_BASE_ID    	  (CUI_INLINE_ITEM_ID_BASE+0)

#if defined(__MMI_EM_NW_CELL_LOCK__) || defined(__MMI_EM_NW_BAND_SEL__)
/*
static const U16 g_mmi_em_nw_evt_onoff_str[] = {STR_GLOBAL_OFF, 
	                                       STR_GLOBAL_ON};

static const cui_inline_item_select_struct g_mmi_em_nw_onoff_sel = 
{
    2, 0, (U16*)g_mmi_em_nw_evt_onoff_str,
};
*/
#endif


/* TDD Network info */
#ifdef __MMI_EM_NW_TDD_NETWORK_INFO__
extern void mmi_em_enter_tdd(cui_menu_event_struct *evt);
#endif


#define EM_NW_PREFER_RAT
/*-----------------------------------------------------------------------------*/
/*-------------------------- Network -> Prefer RAT ----------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_NW_PREFER_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_NW_PREFER_RAT__) */


#define EM_NW_CELL_LOCK
/*-----------------------------------------------------------------------------*/
/*--------------------------- Network -> Cell lock ----------------------------*/
/*-----------------------------------------------------------------------------*/

#if defined(__MMI_EM_NW_CELL_LOCK__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MODEM_EM_MODE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*  */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_NW_CELL_LOCK__) */


#define EM_NW_BAND_SELECTION
/*-----------------------------------------------------------------------------*/
/*----------------------- Network -> Band selection ---------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_NW_BAND_SEL__)
#define MMI_EM_BAND_CHECK_BIT_VALID(_value, _pos) (_value) & (1 << (_pos))
#define MMI_EM_BAND_SET_BIT_VALUE(_value, _pos) (_value) = ((_value) | (1 << (_pos)))
#define MMI_EM_BAND_RESET_BIT_VALUE(_value, _pos) (_value) = ((_value) & (~(1 << (_pos))))

#if defined(__UMTS_RAT__)
/* under construction !*/
#endif /* __UMTS_RAT__ */

typedef enum
{
    MMI_EM_NW_BAND_SEL_HDLR_TYPE_SET_VALUE,
    MMI_EM_NW_BAND_SEL_HDLR_TYPE_GET_VALUE,
    MMI_EM_NW_BAND_SEL_HDLR_TYPE_END_OF_ITEM
} mmi_em_nw_band_sel_hdlr_type_enum;

typedef struct
{
#ifndef __UMTS_RAT__
    cui_inline_set_item_struct inline_cntx[2];
#else
/* under construction !*/
#endif
	
    cui_inline_struct inline_scr;
} mmi_em_nw_evt_band_sel_cntx_struct;

static void mmi_em_nw_band_sel_hdlr(void);

static MMI_RET mmi_em_nw_band_sel_power_off_confirm_proc(mmi_event_struct *evt);

static void mmi_em_nw_band_sel_menu_init(void);

static void mmi_em_nw_band_sel_mem_init(void);

static void mmi_em_nw_band_sel_hdlr_menu_items(
                MMI_ID inline_id,
                mmi_em_nw_band_sel_hdlr_type_enum hdlr_type);
                
static void mmi_em_nw_band_sel_inline_hdlr(void);

static MMI_RET mmi_em_nw_band_sel_inline_proc(mmi_event_struct *evt);
#if defined(__UMTS_RAT__)
/* under construction !*/
#endif /*__UMTS_RAT__*/
U32 g_em_nw_band_sel_sim_flag = 0;

static void mmi_em_nw_band_sel_hdlr(void)
{
    if (mmi_em_ctrl_sim_is_available((mmi_sim_enum)(0x01 << g_em_nw_band_sel_sim_flag)))
    {
        mmi_em_display_confirm(STR_ID_EM_RF_TEST_GSM_CONFIRM_NOTIFY_TEST,
            mmi_em_get_root_group(), MMI_EVENT_QUERY,
            mmi_em_nw_band_sel_power_off_confirm_proc);
    }
}

static MMI_RET mmi_em_nw_band_sel_power_off_confirm_proc(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) evt;
    
    switch (alert->result)
    {
    case MMI_ALERT_CNFM_YES:
    	EmNWBandSelGetBandReq();
    	break;
    default:
        break;
    }

    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  EmNWBandSelGetBandReq
 * DESCRIPTION
 *  function for making req to get band selection
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWBandSelGetBandReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EmNWBandSelGetBandRsp, MSG_ID_MMI_NW_GET_BAND_RSP);
    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(g_em_nw_band_sel_sim_flag)), MSG_ID_MMI_NW_GET_BAND_REQ,
                        (oslParaType*)NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EmNWBandSelGetBandRsp
 * DESCRIPTION
 *  response handler req to get band selection
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWBandSelGetBandRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_band_rsp_struct *localPtr;
    U16 num_of_2g_band_item;
    U16 total_num_2g = sizeof(BandSel2GInfoList)/sizeof(U16);
#if defined(__UMTS_RAT__)	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
	 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    localPtr = (mmi_nw_get_band_rsp_struct*) info;
	
    if (localPtr->result)
    {
        /*********
         * handle 2G band info
         *********/
        for (num_of_2g_band_item = 0; num_of_2g_band_item <= total_num_2g; num_of_2g_band_item++);
        
        for (g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight = 0;
             ((localPtr->gsm_band != BandSel2GInfoList[g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight]) && (g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight < num_of_2g_band_item));
             g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight++);


    #if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
    #if defined (__MTK_TARGET__)
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __UMTS_RAT__ */
    }
    else
    {
        g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight = 1;
    }

    mmi_em_nw_band_sel_inline_hdlr();
}

static const cui_inline_item_caption_struct g_mmi_em_nw_band_2g_cap = 
{
    STR_ID_EM_NW_BAND_SEL_2G,
};

static const U16 g_mmi_em_nw_band_sel_str[] = {
	         #ifdef __GSM850__
                     STR_ID_EM_NW_BAND_SEL_GSM850,
                 #endif
                 #ifdef __EGSM900__
                     STR_ID_EM_NW_BAND_SEL_EGSM900,
                 #endif
                 #ifdef __DCS1800__
                     STR_ID_EM_NW_BAND_SEL_DCS1800,
                 #endif
                 #ifdef __PCS1900__
                     STR_ID_EM_NW_BAND_SEL_PCS1900,
                 #endif
                 #if defined( __GSM850__ ) && defined(__DCS1800__)
                     STR_ID_EM_NW_BAND_SEL_850_1800,
                 #endif /* __GSM850__ */ 
                 #if defined( __EGSM900__ ) && defined(__DCS1800__)
                     STR_ID_EM_NW_BAND_SEL_900_1800,
                 #endif /* __EGSM900__ */
                 #if defined( __GSM850__ ) && defined(__PCS1900__)
                     STR_ID_EM_NW_BAND_SEL_850_1900,
                 #endif /* __GSM850__ */ 
                     STR_ID_EM_GLOBAL_AUTO};

static const cui_inline_item_select_struct g_mmi_em_nw_band_sel = 
{
    sizeof(g_mmi_em_nw_band_sel_str)/sizeof(U16), 
	0, 
	(U16*)g_mmi_em_nw_band_sel_str
};

#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */
mmi_em_nw_evt_band_sel_cntx_struct *mmi_em_nw_evt_band_sel_cntx_p = NULL;

MMI_EM_INIT_ASM(nw_band_sel, mmi_em_nw_evt_band_sel_cntx_p, sizeof(mmi_em_nw_evt_band_sel_cntx_struct))
	
static void mmi_em_nw_band_sel_mem_init(void)
{
    MMI_EM_ASM_INIT_FUNC(nw_band_sel);
}

static void mmi_em_nw_band_sel_menu_init(void)
{
    mmi_em_nw_evt_band_sel_cntx_struct *cntx = mmi_em_nw_evt_band_sel_cntx_p;
    U32 item_id = MMI_EM_NE_ENT_BASE_ID;
    U32 i = 0;	
#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */

    cntx->inline_cntx[i].item_id = item_id;
    cntx->inline_cntx[i].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    cntx->inline_cntx[i].image_id = 0;
    cntx->inline_cntx[i].item_data = (const void *)&g_mmi_em_nw_band_2g_cap;
    item_id++;
    i++;
    cntx->inline_cntx[i].item_id = item_id;
    cntx->inline_cntx[i].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    cntx->inline_cntx[i].image_id = 0;
    cntx->inline_cntx[i].item_data = (const void *)&g_mmi_em_nw_band_sel;
    item_id++;
    i++;

#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
/* under construction !*/
#else
/* under construction !*/
#endif /* __ENHANCED_UMTS_RF_CUSTOMIZATION__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */
    cntx->inline_scr.items_count = item_id - MMI_EM_NE_ENT_BASE_ID;
    cntx->inline_scr.title = STR_ID_EM_NW_BAND_SELECTION;
    cntx->inline_scr.title_icon= 0;
    cntx->inline_scr.screen_flag = CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE;
    cntx->inline_scr.softkey = NULL;
    cntx->inline_scr.items = cntx->inline_cntx;	
}

static void mmi_em_nw_band_sel_hdlr_menu_items(
                MMI_ID inline_id,
                mmi_em_nw_band_sel_hdlr_type_enum hdlr_type)
{
#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */	
    U32 item_id = MMI_EM_NE_ENT_BASE_ID + 1;

    if (MMI_EM_NW_BAND_SEL_HDLR_TYPE_SET_VALUE == hdlr_type)
        cui_inline_set_value(inline_id, item_id, (void*)g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight);
    else
        cui_inline_get_value(inline_id, item_id, (void*)&g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight);
         
#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */
}

static void mmi_em_nw_band_sel_inline_hdlr(void)
{
    MMI_ID gid;
    MMI_ID inline_id;

	
    mmi_em_nw_band_sel_mem_init();
    mmi_em_nw_band_sel_menu_init();

    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
              GRP_ID_AUTO_GEN, 
              mmi_em_nw_band_sel_inline_proc, NULL,
              MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    inline_id = cui_inline_create(gid, &mmi_em_nw_evt_band_sel_cntx_p->inline_scr);
    mmi_em_nw_band_sel_hdlr_menu_items(inline_id, MMI_EM_NW_BAND_SEL_HDLR_TYPE_SET_VALUE);
    cui_inline_run(inline_id);
}

static MMI_RET mmi_em_nw_band_sel_inline_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
   

    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            mmi_em_nw_band_sel_hdlr_menu_items(inline_evt->sender_id, MMI_EM_NW_BAND_SEL_HDLR_TYPE_GET_VALUE);
            EmNWBandSelSetBandReq();
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
            MMI_EM_ASM_FREE_FUNC(nw_band_sel);
            MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(nw_band_sel));
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  EmNWBandSelSetBandReq
 * DESCRIPTION
 *  function to make req for set band selection.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWBandSelSetBandReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_preferred_band_req_struct *myMsgPtr;
#if defined(__UMTS_RAT__)		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(EmNwBandSelSetBandRsp, MSG_ID_MMI_NW_SET_PREFERRED_BAND_RSP);
	
    myMsgPtr =
        (mmi_nw_set_preferred_band_req_struct*) OslConstructDataPtr(sizeof(mmi_nw_set_preferred_band_req_struct));
    myMsgPtr->gsm_band = (U8) BandSel2GInfoList[g_em_nw_band_sel_cntx.EmNW2GBandSelHighlight];

#if defined(__UMTS_RAT__)
#if defined (__MTK_TARGET__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    mmi_frm_send_ilm(mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(g_em_nw_band_sel_sim_flag)), 
        MSG_ID_MMI_NW_SET_PREFERRED_BAND_REQ,
        (oslParaType*)myMsgPtr, NULL);


    EntryEmNWBandSelSetBandProgress();

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmNWBandSelSetBandProgress
 * DESCRIPTION
 *  entry function for band selection in progress screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmNWBandSelSetBandProgress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_progress_cntx_struct cntx = {0};
    
    cntx.title_id = STR_ID_EM_NW_BAND_SELECTION;
    cntx.message = (U8*)GetString(STR_GLOBAL_SEARCHING);
    cntx.message_icon = IMG_ID_NETSET_NW_SEARCH;
    cntx.scrn_id = SCR_ID_NETSET_BAND_SELECTION_PROGRESS;
    cntx.esk_func = mmi_em_progress_sftkey_null_hdlr;
    
    mmi_em_show_progress_scrn(&cntx);

}


/*****************************************************************************
 * FUNCTION
 *  EmNwBandSelSetBandRsp
 * DESCRIPTION
 *  response handler for set band selection req
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmNwBandSelSetBandRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_preferred_band_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    localPtr = (mmi_nw_set_preferred_band_rsp_struct*) info;
    if (localPtr->result == MMI_TRUE)
    {
        EngineerModeSuccessRebootNotice(STR_ID_EM_NOTICE_SUCCESS_REBOO);
        mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_NETSET_BAND_SELECTION_PROGRESS);
    }
    else
    {
        mmi_em_fail_popup();
        mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_NETSET_BAND_SELECTION_PROGRESS);
    }
}

#if defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MTK_TARGET__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__UMTS_RAT__*/
#endif /* defined(__MMI_EM_NW_BAND_SEL__) */


#ifdef __MMI_EM_NW_WCDMA_PREFERRED__
/* WCDMA Preferred */
/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_get_plmn_list_preference_rsp
 * DESCRIPTION
 *  deal with get rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_get_wcdma_preferred_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_rat_mode_rsp_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = (mmi_nw_get_rat_mode_rsp_struct*)msg;

    if (!msg_data->result)
    {
        mmi_em_popup_by_str(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }
    
    if ((msg_data->rat_mode == L4C_RAT_GSM_UMTS) && (msg_data->prefer_rat == L4C_PREFER_RAT_UMTS))
    {
        g_em_nw_wcdma_preferred_cntx.sel_cntx_index = 0; /* MENU_ID_EM_WCDMA_PREFERRED_ON */
    }
    else
    {
        g_em_nw_wcdma_preferred_cntx.sel_cntx_index = 1; /* MENU_ID_EM_WCDMA_PREFERRED_OFF */
    }
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_GET_RAT_MODE_RSP, (PsIntFuncPtr)NULL);
    cui_menu_play(mmi_em_get_main_menu_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_wcdma_preferred_hdlr
 * DESCRIPTION
 *  deal with wcdma preferred
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_wcdma_preferred_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum sim_info;
    mmi_sim_enum sim_3g;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info = (srv_mode_switch_get_current_mode() & (SRV_MODE_SWITCH_SIM1 | SRV_MODE_SWITCH_SIM2));
    /*whether have 3g capbility */
    sim_3g = (srv_netset_get_3g_capability_sim() & (MMI_SIM1 | MMI_SIM2));
    if( (!sim_3g) || (!sim_info) || (!srv_mode_switch_is_network_service_available()))
    {
        mmi_em_fail_popup();
        return;/* only support sim1,sim2 and not in flight mode */
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_GET_RAT_MODE_RSP, 
                                       (PsIntFuncPtr)mmi_em_nw_get_wcdma_preferred_rsp, 
                                       MMI_FALSE);
    if(srv_netset_get_3g_capability_sim() & (MMI_SIM1))
    {
         mmi_frm_send_ilm((oslModuleType)MOD_L4C, MSG_ID_MMI_NW_GET_RAT_MODE_REQ, NULL, NULL);
    }

    #if (MMI_MAX_SIM_NUM >= 2)
    if(srv_netset_get_3g_capability_sim() & (MMI_SIM2))
    {
         mmi_frm_send_ilm((oslModuleType)MOD_L4C_2, MSG_ID_MMI_NW_GET_RAT_MODE_REQ, NULL, NULL);
    }
    #endif
    cui_menu_pause(mmi_em_get_main_menu_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_wcdma_preferred_pre_hdlr
 * DESCRIPTION
 *  prepare for wcdma preferred
 * PARAMETERS
 *  cui_menu_event_struct *evt [IN] about wcdma preferred menue
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_wcdma_preferred_pre_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    menu_id = cui_menu_get_currlist_menu_id_from_index(evt->sender_id, g_em_nw_wcdma_preferred_cntx.sel_cntx_index);
    cui_menu_set_currlist_highlighted_id(evt->sender_id, menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_set_wcdma_preferred_rsp
 * DESCRIPTION
 *  about set wcdma preferred rsp info
 * PARAMETERS
 *  void *msg [IN] about set wcdma preferred rsp info pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_set_wcdma_preferred_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_rat_mode_rsp_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_em_get_root_group(), SCR_ID_EM_NW_WCDMA_PRO);
    msg_data = (mmi_nw_set_rat_mode_rsp_struct*)msg;
    mmi_em_display_notify_popup(msg_data->result);
    
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_SET_RAT_MODE_RSP, (PsIntFuncPtr)NULL);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_GET_RAT_MODE_RSP, 
                           (PsIntFuncPtr)mmi_em_nw_get_wcdma_preferred_rsp, 
                           MMI_FALSE);


    if(srv_netset_get_3g_capability_sim() & (MMI_SIM1))
    {
        mmi_frm_send_ilm((oslModuleType)MOD_L4C, MSG_ID_MMI_NW_GET_RAT_MODE_REQ, NULL, NULL);
    }

    #if (MMI_MAX_SIM_NUM >= 2)
    if(srv_netset_get_3g_capability_sim() & (MMI_SIM2))
    {
        mmi_frm_send_ilm((oslModuleType)MOD_L4C_2, MSG_ID_MMI_NW_GET_RAT_MODE_REQ, NULL, NULL);
    }
    #endif
    cui_menu_pause(mmi_em_get_main_menu_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_setting_nss_bgdata_sproc
 * DESCRIPTION
 * pro background data seting screen
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_em_nw_wcdma_wait_sproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
 
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                ShowCategory8Screen(
                    STR_ID_EM_NW_WCDMA_PREFERRED,
                    0,
                    0,
                    0,
                    STR_GLOBAL_ABORT,
                    0,
                    STR_GLOBAL_PLEASE_WAIT,
                    IMG_GLOBAL_PROGRESS,
                    NULL);

            }
        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
            {
                break;
            }
        case EVT_ID_WGUI_LSK_CLICK:
            {
                break;
            }

    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_wcdma_preferred_list_hdlr
 * DESCRIPTION
 *  switch wcdma preferred
 * PARAMETERS
 *  cui_menu_event_struct *evt [IN] about wcdma preferred menue
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_wcdma_preferred_list_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    mmi_nw_set_rat_mode_req_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/                             
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_SET_RAT_MODE_RSP, 
                                       (PsIntFuncPtr)mmi_em_nw_set_wcdma_preferred_rsp, 
                                       MMI_FALSE);
    /* when is off index = 1, when is on index = 0  */
    index = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
    msg_data = MMI_EM_CONSTRUCT_MSG_DATA(mmi_nw_set_rat_mode_req_struct);

    /* need to modify when the struct update */
    if(!index)
    {
        msg_data->rat_mode = L4C_RAT_GSM_UMTS;
        msg_data->prefer_rat = L4C_PREFER_RAT_UMTS;
    }
    else
    {
        msg_data->rat_mode = L4C_RAT_GSM_UMTS;
        msg_data->prefer_rat = L4C_PREFER_RAT_NONE;
    }

    if(srv_netset_get_3g_capability_sim() & (MMI_SIM1))
    {
        mmi_frm_send_ilm((oslModuleType)MOD_L4C, 
                 (oslMsgType)MSG_ID_MMI_NW_SET_RAT_MODE_REQ, 
                 (oslParaType*)msg_data, 
                 NULL);
    }

    #if (MMI_MAX_SIM_NUM >= 2)
    if(srv_netset_get_3g_capability_sim() & (MMI_SIM2))
    {
         mmi_frm_send_ilm((oslModuleType)MOD_L4C_2, 
                 (oslMsgType)MSG_ID_MMI_NW_SET_RAT_MODE_REQ, 
                 (oslParaType*)msg_data, 
                 NULL);
    }
    #endif
    /* for many sets, to avoid sent message connectively */
    mmi_frm_scrn_create(mmi_em_get_root_group(), SCR_ID_EM_NW_WCDMA_PRO, mmi_em_nw_wcdma_wait_sproc, NULL);
    
}
#endif /* __MMI_EM_NW_WCDMA_PREFERRED__ */

/* PLMN list*/
#if defined(__MMI_EM_NW_PLMN_LIST__)
static void mmi_em_nw_plwn_hdlr(void)
{
    #ifdef PLMN_TEST
    SetProtocolEventHandler(mmi_em_nw_plmn_test_get_req_hdlr, MSG_ID_MMI_NW_GET_PLMN_LIST_PREFERENCE_REQ);
    SetProtocolEventHandler(mmi_em_nw_plmn_test_set_req_hdlr, MSG_ID_MMI_NW_SET_PLMN_LIST_PREFERENCE_REQ);
    #endif
    SetProtocolEventHandler(mmi_em_nw_get_plmn_list_preference_rsp, MSG_ID_MMI_NW_GET_PLMN_LIST_PREFERENCE_RSP);
    mmi_em_nw_send_get_plmn_list_preference_req();
    cui_menu_pause(mmi_em_get_main_menu_id());
}

static void mmi_em_nw_plwn_list_pre_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;
    U32 i;
    mmi_menu_id menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = cui_menu_get_currlist_item_count(evt->sender_id);
    for (i = 0; i < count; i++)
    {
        if (g_em_nw_plmn_sel_cntx.plmn_prefer_val == g_em_nw_plmn_sel_item_table[i])
        {
            g_em_nw_plmn_sel_cntx.highlight_index = i;
            break;
        }
    }
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    menu_id = cui_menu_get_currlist_menu_id_from_index(evt->sender_id, i);
    cui_menu_set_currlist_highlighted_id(evt->sender_id, menu_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_plmn_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_plwn_list_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_em_nw_set_plmn_list_preference_rsp, 
        MSG_ID_MMI_NW_SET_PLMN_LIST_PREFERENCE_RSP);
    index = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
    g_em_nw_plmn_sel_cntx.highlight_index = index;
    mmi_em_nw_send_set_plmn_list_preference_req(g_em_nw_plmn_sel_item_table[g_em_nw_plmn_sel_cntx.highlight_index]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_send_get_plmn_list_preference_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_send_get_plmn_list_preference_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EngineerModeSendMsg(MSG_ID_MMI_NW_GET_PLMN_LIST_PREFERENCE_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_get_plmn_list_preference_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_get_plmn_list_preference_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_plmn_list_preference_rsp_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = (mmi_nw_get_plmn_list_preference_rsp_struct*)msg;

    if (!msg_data->result)
    {
        mmi_em_popup_by_str(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }

    g_em_nw_plmn_sel_cntx.plmn_prefer_val = msg_data->preference;
    g_em_nw_plmn_sel_cntx.highlight_index = 0;
    cui_menu_play(mmi_em_get_main_menu_id());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_plmn_sel_send_set_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_send_set_plmn_list_preference_req(U8 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_list_preference_req_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = MMI_EM_CONSTRUCT_MSG_DATA(mmi_nw_set_plmn_list_preference_req_struct);

    data->preference = val;

    EngineerModeSendMsg(MSG_ID_MMI_NW_SET_PLMN_LIST_PREFERENCE_REQ, data, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_set_plmn_list_preference_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nw_set_plmn_list_preference_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_set_plmn_list_preference_rsp_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = (mmi_nw_set_plmn_list_preference_rsp_struct*)msg;

    mmi_em_display_notify_popup(msg_data->result);
    mmi_em_nw_send_get_plmn_list_preference_req();
    cui_menu_pause(mmi_em_get_main_menu_id());
}

#ifdef PLMN_TEST
static void mmi_em_nw_plmn_test_get_req_hdlr(void *msg)
{
    mmi_nw_get_plmn_list_preference_rsp_struct *msg_data;

    msg_data = MMI_EM_CONSTRUCT_MSG_DATA(mmi_nw_get_plmn_list_preference_rsp_struct);
    msg_data->result = 1;
    msg_data->preference = plmn_test_val;

    EngineerModeSendMsg_Ext(MSG_ID_MMI_NW_GET_PLMN_LIST_PREFERENCE_RSP, MOD_MMI, msg_data, NULL);
}

static void mmi_em_nw_plmn_test_set_req_hdlr(void *msg)
{
    mmi_nw_set_plmn_list_preference_req_struct *data;
    mmi_nw_set_plmn_list_preference_rsp_struct *rsp_data;
    
    data = (mmi_nw_set_plmn_list_preference_req_struct*)msg;
    plmn_test_val = data->preference;

    rsp_data = MMI_EM_CONSTRUCT_MSG_DATA(mmi_nw_set_plmn_list_preference_rsp_struct);
    rsp_data->result = 1;
    EngineerModeSendMsg_Ext(MSG_ID_MMI_NW_SET_PLMN_LIST_PREFERENCE_RSP, MOD_MMI, rsp_data, NULL);
}

#endif

#endif /* __MMI_EM_NW_PLMN_LIST__ */

#ifdef __GSMCDMA_DUALSIM__
static void mmi_em_nw_ivsr_menu_pre_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;
    S16 error;
    S8 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    ReadValue(
        NVRAM_EM_IVSR,
        &value,
        DS_BYTE,
        &error);
    if (value == 0)
    {
        menu_id = MENU_ID_EM_IVSR_OFF;
    }
    else
    {
        menu_id = MENU_ID_EM_IVSR_ON;
    }

    cui_menu_set_currlist_highlighted_id(evt->sender_id, menu_id);
}

void mmi_em_nw_ivsr_menu_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S8 value;
    FuncPtr funcptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->highlighted_menu_id == MENU_ID_EM_IVSR_ON)
    {
        srv_nw_info_enable_ivsr(MMI_TRUE);
        value = 1;
    }
    else if (evt->highlighted_menu_id == MENU_ID_EM_IVSR_OFF)
    {
        srv_nw_info_enable_ivsr(MMI_FALSE);
        value = 0;
    }
    cui_menu_set_currlist_highlighted_id(evt->sender_id, evt->highlighted_menu_id);
    WriteValue(
        NVRAM_EM_IVSR,
        &value,
        DS_BYTE,
        &error);
    funcptr = get_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
    funcptr();
}
#endif /* __GSMCDMA_DUALSIM__ */

#ifdef __MMI_EM_NETWORK_SETTINGS__

void mmi_em_nw_menu_entry_event_hdlr(cui_menu_event_struct *evt)
{
    #ifdef __MMI_EM_NW_WCDMA_PREFERRED__
    /* WCDMA Preferred */
    MMI_BOOL sim1_insert = MMI_FALSE;
    MMI_BOOL sim2_insert = MMI_FALSE;
    /* whether sim1 is inserted */
	sim1_insert = (MMI_BOOL)srv_sim_ctrl_is_inserted(MMI_SIM1);
    sim2_insert = (MMI_BOOL)srv_sim_ctrl_is_inserted(MMI_SIM2);
    if ((!sim1_insert) && (!sim2_insert))
    {
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_EM_NW_WCDMA_PREFERRED, MMI_TRUE);
    }
    /* whether sim1 is opend */
    sim1_insert = srv_mode_switch_get_current_mode() & SRV_MODE_SWITCH_SIM1;
    sim2_insert = srv_mode_switch_get_current_mode() & SRV_MODE_SWITCH_SIM2;
    if ((!sim1_insert) && (!sim2_insert))
    {
        cui_menu_set_item_hidden(evt->sender_id, MENU_ID_EM_NW_WCDMA_PREFERRED, MMI_TRUE);
    }
    #endif /* __MMI_EM_NW_WCDMA_PREFERRED__ */
    
    switch(evt->parent_menu_id)
    {
    #ifdef __MMI_EM_NW_PREFER_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_NW_EVENT_NOTIFY__ */
	
    #ifdef __MMI_EM_NW_PLMN_LIST__
        case MENU_ID_EM_NW_PLMN_LIST_PREFERENCE:
            mmi_em_nw_plwn_list_pre_hdlr(evt);
            break;
    #endif /* __MMI_EM_NW_PLMN_LIST__ */
    
    #ifdef __MMI_EM_NW_WCDMA_PREFERRED__
    /* WCDMA Preferred */
    	case MENU_ID_EM_NW_WCDMA_PREFERRED:
        	mmi_em_nw_wcdma_preferred_pre_hdlr(evt);
        	break;
    #endif /* __MMI_EM_NW_WCDMA_PREFERRED__ */    

    #ifdef __GSMCDMA_DUALSIM__
        case MENU_ID_EM_IVSR:
            mmi_em_nw_ivsr_menu_pre_hdlr(evt);
            break;
    #endif /* __GSMCDMA_DUALSIM__ */
    }
}
void mmi_em_nw_menu_event_hdlr(cui_menu_event_struct *evt)
{
    /* For ON/OFF select*/
    if ((evt->highlighted_menu_id == MENU_ID_EM_MISC_ON ||
        evt->highlighted_menu_id == MENU_ID_EM_MISC_OFF) &&
        evt->evt_id == EVT_ID_CUI_MENU_ITEM_SELECT)
    {
        switch(evt->parent_menu_id)
        {		
        #ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_EM_NW_EVENT_NOTIFY__ */
            default:
                break;
        }
    }

    /* For select item handler */
    switch(evt->highlighted_menu_id)
    {
    #ifdef __MMI_EM_NW_NETWORK_INFO__
        case MENU_ID_EM_NW_SETTING_SIM_1:
    #if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_EM_NW_SETTING_SIM_2:
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_EM_NW_SETTING_SIM_3:
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_EM_NW_SETTING_SIM_4:
    #endif
            mmi_em_nw_info_checkbox_list_hdlr(evt);
            break;
    #endif /* __MMI_EM_NW_NETWORK_INFO__ */
    
    #ifdef __MMI_EM_NW_PREFER_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_NW_PREFER_RAT__ */

    #ifdef __MMI_EM_NW_CELL_LOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_NW_CELL_LOCK__ */

    #ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_NW_EVENT_NOTIFY__ */

    #ifdef __MMI_EM_NW_BAND_SEL__
        case MENU_ID_EM_NW_BD_SL_SIM_1:
            g_em_nw_band_sel_sim_flag = 0;
            mmi_em_nw_band_sel_hdlr();
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_EM_NW_BD_SL_SIM_2:
            g_em_nw_band_sel_sim_flag = 1;
            mmi_em_nw_band_sel_hdlr();
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_EM_NW_BD_SL_SIM_3:
            g_em_nw_band_sel_sim_flag = 2;
            mmi_em_nw_band_sel_hdlr();
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_EM_NW_BD_SL_SIM_4:
            g_em_nw_band_sel_sim_flag = 3;
            mmi_em_nw_band_sel_hdlr();
            break;
    #endif
    #endif /* __MMI_EM_NW_BAND_SEL__ */
    #if defined(__MMI_EM_NW_PLMN_LIST__)
        case MENU_ID_EM_NW_PLMN_LIST_PREFERENCE:
            mmi_em_nw_plwn_hdlr();
            break;
    #endif
    #ifdef __MMI_EM_NW_WCDMA_PREFERRED__
		case MENU_ID_EM_NW_WCDMA_PREFERRED:
        mmi_em_nw_wcdma_preferred_hdlr();
        break;/* WCDMA Preferred*/
    #endif /* __MMI_EM_NW_WCDMA_PREFERRED__ */
        
    #ifdef __MMI_EM_NW_SERVICE_MODE_SELECTION__
        case MENU_ID_EM_NW_SERVICE_SELECTION:
            mmi_netset_entry_service_mode_selection();
            break;
    #endif  
    #if defined(__MMI_EM_NW_GPRS_CONN__)
		case MENU_ID_EM_NW_GPRS_CONN:
            mmi_nw_entry_gprs_conn_mode(evt->sender_id);
			break;
    #endif /*__MMI_EM_NW_GPRS_CONN__*/
        default:
            break;
    }

    switch(evt->parent_menu_id)
    {
    #ifdef __MMI_EM_NW_PREFER_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_NW_PREFER_RAT__ */

    #if defined(__MMI_EM_NW_PLMN_LIST__)
        case MENU_ID_EM_NW_PLMN_LIST_PREFERENCE:
            mmi_em_nw_plwn_list_hdlr(evt);
            break;
    #endif
    
    #ifdef __MMI_EM_NW_WCDMA_PREFERRED__
    /* WCDMA Preferred */
        case MENU_ID_EM_NW_WCDMA_PREFERRED:
            mmi_em_nw_wcdma_preferred_list_hdlr(evt);
        break;
    #endif /* __MMI_EM_NW_WCDMA_PREFERRED__ */

    #ifdef __GSMCDMA_DUALSIM__
        case MENU_ID_EM_IVSR:
            mmi_em_nw_ivsr_menu_hdlr(evt);
            break;
    #endif /* __GSMCDMA_DUALSIM__ */
    }


    
#ifdef __MMI_EM_NW_FDD_NETWORK_INFO__

        mmi_em_3g_info_menu_event_hdlr(evt);

#endif /*__MMI_EM_NW_FDD_NETWORK_INFO__*/

#ifdef __MMI_EM_NW_TDD_NETWORK_INFO__

        mmi_em_enter_tdd(evt);

 #endif /*__MMI_EM_NW_TDD_NETWORK_INFO__*/            
           


}

void mmi_em_nw_menu_exit_event_hdlr(cui_menu_event_struct *evt)
{
    switch(evt->parent_menu_id)
    {
    #ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_EM_NW_EVENT_NOTIFY__ */
    }
}
#endif /* __MMI_EM_NETWORK_SETTINGS__ */
#endif /* defined(__MMI_ENGINEER_MODE__) && defined(__MODEM_EM_MODE__) */
