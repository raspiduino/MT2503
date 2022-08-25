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
 *  EngineerModeMisc.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode misc items. It includes:
 *      - Auto answer
 *      - High Speed SIM
 *      - Power on duration
 *      - Backlight
 *      - Serial Port Enable(Detecttion mode)
 *      - Auto Reset(Assert Testing)
 *      - RAM Test 
 *      - Memory Dump
 *      - MMI Debug
 *      - AMR
 *      - Cell Reselection
 *      - Fix Gain for Helios2 
 *      - MT6223 Debug Mode
 *      - LSD Slower
 *      - Auto Test
 *      - Power Down Control
 *      - SW Patch
 *      - Video parameter
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "EngineerModeUtil.h"   
#ifdef __MMI_ENGINEER_MODE__ 

#if defined(COSMOS_EM_INTERNAL_DCM)
#include "dcmgr.h"
#elif defined (PLUTO_EM_INTERNAL_DCM)
#include "MMI_ap_dcm_config.h"  
#endif /* COSMOS_EM_INTERNAL_DCM */

#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 


#include "MMI_features.h"
#include "MMIDataType.h"
#include "ps_public_struct.h"
#include "wgui_touch_screen.h"
#include "nvram_data_items.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#ifdef __MMI_EM_MISC_MMI_DEBUG__
#include "DebugInitDef_Int.h"
#endif
#include "string.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_public_api.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "gui_typedef.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "device.h"
#include "stack_msgs.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "custom_em.h"
#include "CustDataRes.h"
#include "wgui_include.h"
#include "mmi_frm_input_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "wgui_categories.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "CustDataProts.h"
#include "wgui_inline_edit.h"
#include "stdlib.h"
#include "ImeGprot.h"
#include "CommonScreens.h"
#include "init.h"
#include "med_api.h"
#include "CallSetSrvGprot.h"

#if defined(__MMI_EM_MISC_BACKLIGHT__)
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_MEMORY_DUMP__
#include "ex_public.h"
#endif

#include "EngineerModeAppResDef.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeMisc.h"
#include "EngineerModeMultimedia.h"
#include "EngineerModeDM.h"

//#include "FactoryModeDef.h"
#include "menucuigprot.h"

#ifdef __J2ME__
#include "mmi_rp_app_java_def.h"
#endif

#include "mmi_rp_app_engineermode1_def.h"

#include "inlinecuigprot.h"
#if defined(__MMI_EM_MISC_TOUCH_SCREEN__)
#include "EngineerModeTouchPanel.h"
#endif /*defined(__MMI_EM_MISC_TOUCH_SCREEN__)*/

#ifdef __MMI_EM_MISC_MULTI_TOUCH__
#include "vadp_p2v_multi_touch_test.h"
#endif

/* For MRE version detail info item */
#include "vmsys.h"

#if defined(__MMI_EM_MISC_HIGHSPEED_SIM__)
/* under construction !*/
#endif

#define APP_CAPTION_1    (CUI_INLINE_ITEM_ID_BASE+0)
#define APP_TEXT_EDIT_2  (CUI_INLINE_ITEM_ID_BASE+1)
#define APP_CAPTION_3    (CUI_INLINE_ITEM_ID_BASE+2)
#define APP_TEXT_EDIT_4  (CUI_INLINE_ITEM_ID_BASE+3)
#define APP_CAPTION_5    (CUI_INLINE_ITEM_ID_BASE+4)
#define APP_TEXT_EDIT_6  (CUI_INLINE_ITEM_ID_BASE+5)
#define APP_CAPTION_7    (CUI_INLINE_ITEM_ID_BASE+6)
#define APP_TEXT_EDIT_8  (CUI_INLINE_ITEM_ID_BASE+7)
#define APP_CAPTION_9    (CUI_INLINE_ITEM_ID_BASE+8)
#define APP_TEXT_EDIT_10  (CUI_INLINE_ITEM_ID_BASE+9)
#define APP_CAPTION_11    (CUI_INLINE_ITEM_ID_BASE+10)
#define APP_TEXT_EDIT_12  (CUI_INLINE_ITEM_ID_BASE+11)
#define APP_CAPTION_13    (CUI_INLINE_ITEM_ID_BASE+12)
#define APP_TEXT_EDIT_14  (CUI_INLINE_ITEM_ID_BASE+13)
#define APP_CAPTION_15    (CUI_INLINE_ITEM_ID_BASE+14)
#define APP_TEXT_EDIT_16  (CUI_INLINE_ITEM_ID_BASE+15)
#define APP_CAPTION_17    (CUI_INLINE_ITEM_ID_BASE+16)
#define APP_TEXT_EDIT_18  (CUI_INLINE_ITEM_ID_BASE+17)
#define APP_CAPTION_19    (CUI_INLINE_ITEM_ID_BASE+18)
#define APP_TEXT_EDIT_20  (CUI_INLINE_ITEM_ID_BASE+19)
#define APP_CAPTION_21    (CUI_INLINE_ITEM_ID_BASE+20)
#define APP_TEXT_EDIT_22  (CUI_INLINE_ITEM_ID_BASE+21)
#define APP_CAPTION_23    (CUI_INLINE_ITEM_ID_BASE+22)
#define APP_TEXT_EDIT_24  (CUI_INLINE_ITEM_ID_BASE+23)


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
/* Backlight */
#if defined(__MMI_EM_MISC_BACKLIGHT__)
/* under construction !*/
#endif

/* Auto Testing Settings */
S32 gPriorityValue = 0;
S16 gAutoTestListSize = 0;
U16 gHiliteAutoTestCurrSelIdx = 0;
U16 gHiliteAllTestListIdx = 0;
U16 newPriority = 0;


#if 0 /*auto test */
#ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
#endif
#endif 

#if defined(__MMI_EM_MISC_AMR__)
/* AMR Info */
static BOOL AMR_ON = FALSE;
U8 mscap[NVRAM_EF_MSCAP_SIZE];
#endif /* __AMR_SUPPORT__ */ 

/* Cell Reselection */
typedef enum
{
    CELL_RESELECT_SUSPEND_IN_ALL,
    CELL_RESELECT_SUSPEND_IN_TRANSFER
} CELL_RESELECT_SUSPEND_ENUM;

U8 g_cell_reselection_item = 0;

/* Video parameter */
#ifdef __MMI_EM_MISC_VIDEO_PARAM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_VIDEO_PARAM__ */


/* J2ME*/
#ifdef __J2ME__
extern void mmi_java_em_tck_enter(void);
#endif

#if !defined(__MMI_EM_INET_APP_SLIM__)
extern S32 mmi_em_inet_menu_entry_handler(cui_menu_event_struct *event);
extern S32 mmi_em_inet_menu_select_handler(cui_menu_event_struct *event);
#endif

#ifdef __MMI_EM_MISC_CHECK_DRIVE__
/* under construction !*/
#endif
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* MMI Memory Dump */
extern kal_uint32 INT_MemoryDumpFlag;

#if defined(__MMI_EM_MISC_VIDEO_HI_BITRATE__)
/* under construction !*/
#endif

extern U8 g_em_set_uart_req_type;

#if defined(__MMI_EM_MISC_HIGHSPEED_SIM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__MMI_EM_MISC_HIGHSPEED_SIM__

//extern U8 EmAppPortArray[EM_APP_MAX_NUM];
//extern U8 EmAppBaudArray[EM_APP_MAX_NUM];
//extern U8 UART_POWER_SETTING;

extern kal_bool UART_setting;
//extern U8 SWDBG_Profile;
extern U8 g_EmDevTST_Ouput_mode;

#ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
typedef enum
{
    EM_MISC_POWER_ON_CPU_DEFAULT_STATUS,
    EM_MISC_POWER_ON_CPU_NO_QUERY_STATUS,
    EM_MISC_POWER_ON_CPU_QUERY_STATUS
} EM_MISC_POWER_ON_CPU_QUERY_STATUS_ENUM;

typedef struct {
    U32 sel_cntx_index;
} em_misc_power_on_cpu_query_struct;
em_misc_power_on_cpu_query_struct g_em_misc_power_on_cpu_query_cntx;
void mmi_em_misc_power_on_cpu_query_list_hdlr(cui_menu_event_struct *evt);
void mmi_em_nw_get_power_on_cpu_query_rsp(void *msg);
void mmi_em_misc_power_on_cpu_query_pre_hdlr(cui_menu_event_struct *menu_evt);
void mmi_em_misc_power_on_cpu_query_hdlr(void);

#endif

/* Profile */
//extern const testlet Tests[MAX_AUTO_TEST_ITEMS];

#ifdef __MMI_EM_DEV_USB_LOGGING__
/* under construction !*/
#endif

/***************************************************************************** 
 * Static Function
 *****************************************************************************/
static void mmi_em_misc_set_item_on_off(MMI_BOOL is_bool, cui_menu_event_struct *event);


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern kal_bool SST_AdvRAMTest(void);
#ifdef __MMI_EM_MISC_DM_REGISTER__
extern void set_highlightIndex(U8 select_item);
extern void mmi_em_misc_dm_self_register_result_select(void);
extern void mmi_em_misc_dm_self_register_master_switch_select(void);

extern void mmi_em_misc_dm_self_register_entry(void);
extern U8 mmi_em_misc_dm_self_register_get_result(void);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
#ifdef __OP02_DM__
extern void EmMisDMGetSelfRegisterPort();
#endif
#endif





#define EM_MISC_AUTO_ANSWER
/*-----------------------------------------------------------------------------*/
/*--------------------------- Misc -> Auto answer -----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_AUTO_ANSWER__
static void mmi_em_misc_auto_answer_hdlr(mmi_menu_id menu_id)
{
    srv_callset_answer_mode_switch_mode(SRV_CALLSET_ANSWER_MODE_AUTO, MENU_ID_EM_MISC_ON == menu_id);
    mmi_em_success_popup();
}
#endif /*__MMI_EM_MISC_AUTO_ANSWER__*/
#define EM_MISC_HIGHSPEED_SIM
/*-----------------------------------------------------------------------------*/
/*------------------------------ High Speed SIM -------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_HIGHSPEED_SIM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
#if defined(__MTK_TARGET__)
/* under construction !*/
#endif /* defined(__MTK_TARGET__)) */ 
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_MISC_HIGHSPEED_SIM__) */



#define EM_MISC_BACKLIGHT
/*-----------------------------------------------------------------------------*/
/*-------------------------------- Backlight ----------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_BACKLIGHT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_MISC_BACKLIGHT__) */


#define EM_MISC_AUTO_RESET
/*-----------------------------------------------------------------------------*/
/*--------------------- Auto Reset(Assert Testing) ----------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_AUTO_RESET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_MISC_AUTO_RESET__) */


#define EM_MISC_RAM_TEST
/*-----------------------------------------------------------------------------*/
/*------------------------------- RAM test ------------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_RAM_TEST__
static void mmi_em_misc_ram_test_hdlr(void)
{
    mmi_em_display_notify_popup((MMI_BOOL)(SST_AdvRAMTest() == KAL_TRUE));
}
#endif /*__MMI_EM_MISC_RAM_TEST__*/
#define EM_MISC_MEMORY_DUMP
/*-----------------------------------------------------------------------------*/
/*------------------------------- Memory dump ---------------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_MEMORY_DUMP__
static void mmi_em_misc_memory_dump_hdlr(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MENU_ID_EM_MISC_ON == menu_id)
    {
        ex_set_memorydump_flag();
    }
    else if (MENU_ID_EM_MISC_OFF == menu_id)
    {
        ex_clear_memorydump_flag();
    }
    
    mmi_em_success_popup();
}
#endif /*__MMI_EM_MISC_MEMORY_DUMP__*/

#define MMI_EM_MISC_AMR
/*-----------------------------------------------------------------------------*/
/*----------------------------------- AMR -------------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_AMR__)

static void mmi_em_misc_arm_enter(cui_menu_event_struct *event)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ret;
    S16 error_code;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = ReadRecord(NVRAM_EF_MSCAP_LID, 1, &mscap, NVRAM_EF_MSCAP_SIZE, &error_code);
    if (!(error_code == NVRAM_READ_SUCCESS && ret == NVRAM_EF_MSCAP_SIZE))
    {
        ASSERT(0);
    }
    if (mscap[0] == 0x1f)
    {
        AMR_ON = TRUE;
    }
    else
    {
        AMR_ON = FALSE;
    }
    mmi_em_misc_set_item_on_off((MMI_BOOL)AMR_ON, event);
}




static void mmi_em_misc_amr_hdlr(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 Ret;
    S16 ErrorCode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MENU_ID_EM_MISC_ON == menu_id)
    {
        AMR_ON = TRUE;
    }
    else if (MENU_ID_EM_MISC_OFF == menu_id)
    {
        AMR_ON = FALSE;
    }
	
    if (AMR_ON == TRUE)
    {
        mscap[0] = 0x1f;
        Ret = WriteRecord(NVRAM_EF_MSCAP_LID, 1, &mscap, NVRAM_EF_MSCAP_SIZE, &ErrorCode);
    }
    else
    {
        mscap[0] = 0x07;
        Ret = WriteRecord(NVRAM_EF_MSCAP_LID, 1, &mscap, NVRAM_EF_MSCAP_SIZE, &ErrorCode);
    }

    mmi_em_display_notify_popup((MMI_BOOL)(ErrorCode == NVRAM_WRITE_SUCCESS && Ret == NVRAM_EF_MSCAP_SIZE));
}
#endif /* #if defined(__MMI_EM_MISC_AMR__) */ 


#define EM_MISC_CELL_RESELECTION
/*-----------------------------------------------------------------------------*/
/*----------------------------- Cell reselection ------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_MISC_CELL_RESELECTION__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_MISC_CELL_RESELECTION__) */


#define EM_SW_PATCH
/*-----------------------------------------------------------------------------*/
/*---------------------------------- SW patch ---------------------------------*/
/*-----------------------------------------------------------------------------*/
#if defined(__MMI_EM_SW_PATCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__MMI_EM_SW_PATCH__) */


#define EM_MISC_VIDEO_PARAM
/*-----------------------------------------------------------------------------*/
/*------------------------- Misc -> Video parameter ---------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_VIDEO_PARAM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_VIDEO_PARAM__ */

#ifdef __MMI_EM_MISC_X_DOWNLOAD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#ifdef __MMI_EM_RF_DESENSE_TEST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#ifdef __MMI_EM_MISC_MULTI_TOUCH__
static void mmi_em_multi_touch_test_launch()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH, NULL, NULL);
    mmi_frm_group_enter(GRP_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(!mmi_frm_scrn_enter(GRP_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH,
                           SCR_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH,
                           vadp_p2v_multi_touch_test_exit,
                           vadp_p2v_multi_touch_test_entry,
                           MMI_FRM_FULL_SCRN))
    {
        return;
    }

    vadp_p2v_multi_touch_test_entry();
}
#endif
/*-----------------------------------------------------------------------------*/
/*---------------------------  Misc -> Comm func  -----------------------------*/
/*-----------------------------------------------------------------------------*/
static void mmi_em_misc_set_item_on_off(MMI_BOOL is_bool, cui_menu_event_struct *event)
{
    mmi_menu_id id = is_bool ? MENU_ID_EM_MISC_ON : MENU_ID_EM_MISC_OFF;
    cui_menu_set_currlist_highlighted_id(event->sender_id, id);
}


#ifdef __MMI_EM_MISC_DM_REGISTER__
static void mmi_em_misc_set_item_true_false(MMI_BOOL is_bool, cui_menu_event_struct *event)
{
    mmi_menu_id id = is_bool ? MENU_ID_EM_TRUE : MENU_ID_EM_FALSE;
    cui_menu_set_currlist_highlighted_id(event->sender_id, id);
}
#endif /*__MMI_EM_MISC_DM_REGISTER__*/

/*-----------------------------------------------------------------------------*/
/*---------------------------  Misc -> Event hdlr  ----------------------------*/
/*-----------------------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_MEDIA_MEMORY_SETTING__
/* under construction !*/
#endif
#ifdef __MMI_EM_MISC_TOUCH_SCREEN__
extern void mmi_em_entry_ssp_settings_option_menu(void);
#endif
extern MMI_ID mmi_em_misc_ts_pen_event_test_launch(MMI_ID parent_id);
#ifdef __MMI_EM_MISC_JAVA_PERFORMANCE__
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_EM_MISC_JUI_DEBUG__
/* under construction !*/
#endif
#if defined(__MMI_EM_MISC_RECORDER_SETTING__)
/* under construction !*/
#endif

void mmi_em_misc_mre_select_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_text_viewer_struct em_text;
    WCHAR* strBuffer = NULL;
    U32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    vm_get_system_info(NULL,&size);
    strBuffer = (WCHAR*)MMI_EM_MALLOC(size);
    if (strBuffer)
    {
        vm_get_system_info((VMCHAR*)strBuffer,&size);
    }

    em_text.title_id = STR_ID_EM_MRE;
    em_text.text = strBuffer;
    mmi_em_show_text_viewer(&em_text);
    MMI_EM_FREE(strBuffer);
}


void mmi_em_misc_menu_event_hdlr(cui_menu_event_struct *event)
{
    /* For ON/OFF select*/
    if (event->highlighted_menu_id == MENU_ID_EM_MISC_ON ||
        event->highlighted_menu_id == MENU_ID_EM_MISC_OFF)
    {
        switch(event->parent_menu_id)
        {
    #ifdef __MMI_EM_MISC_VIDEO_HI_BITRATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        
    #ifdef __MMI_EM_MISC_AUTO_ANSWER__
        case MENU_ID_EM_MISC_AUTO_ANSWER:
            mmi_em_misc_auto_answer_hdlr(event->highlighted_menu_id);
            break;
    #endif/*__MMI_EM_MISC_AUTO_ANSWER__*/
                
    #ifdef __MMI_EM_MISC_HIGHSPEED_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        
    #ifdef __MMI_EM_MISC_BACKLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #ifdef __MMI_EM_MISC_MEMORY_DUMP__		
        case MENU_ID_EM_MISC_MEMORY_DUMP:
            mmi_em_misc_memory_dump_hdlr(event->highlighted_menu_id);
            break;
    #endif /*__MMI_EM_MISC_MEMORY_DUMP__*/

    #ifdef __MMI_EM_MISC_AMR__
        case MENU_ID_EM_MISC_AMR:
            mmi_em_misc_amr_hdlr(event->highlighted_menu_id);
            break;
    #endif

    #ifdef __MMI_EM_MISC_DCD__
    #ifdef __MMI_OP01_DCD_V30__
        case MENU_ID_EM_MISC_DCD_STORAGE_SWITCH:
            mmi_em_misc_dcd_storage_switch_hdlr(event->highlighted_menu_id);
            break;
    #endif
    #endif

        default:
            return;
        }
        return;
    }


    if (event->highlighted_menu_id == MENU_ID_EM_TRUE||
        event->highlighted_menu_id == MENU_ID_EM_FALSE)
    {
        switch(event->parent_menu_id)
        {
    #ifdef __MMI_EM_MISC_DM_REGISTER__
        case MENU_ID_EM_MISC_DM_SELF_REGISTER:

            break;
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
    #else
        case MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT:
    #endif /*__MMI_DUAL_SIM_MASTER__*/
        {
            if(event->highlighted_menu_id == MENU_ID_EM_TRUE)
            {
                set_highlightIndex(1);
            }
            else if(event->highlighted_menu_id == MENU_ID_EM_FALSE)
            {
                set_highlightIndex(0);
            }
            mmi_em_misc_dm_self_register_result_select();
            break;
        }
        /*add for master switch*/
        case MENU_ID_EM_MISC_DM_SELF_REGISTER_MASTER_SWITCH:
        {
            if(event->highlighted_menu_id == MENU_ID_EM_TRUE)
            {
                set_highlightIndex(1);
            }
            else if(event->highlighted_menu_id == MENU_ID_EM_FALSE)
            {
                set_highlightIndex(0);
            }
            mmi_em_misc_dm_self_register_master_switch_select();
            break;
        }
    #endif

        default:
            break;
        }
        return;
    }


    switch(event->highlighted_menu_id)
    {
#ifdef __MMI_EM_RF_DESENSE_TEST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_MEDIA_MEMORY_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_SW_PATCH__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_AUTO_RESET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_RAM_TEST__
    case MENU_ID_EM_MISC_RAM_TEST:
        mmi_em_misc_ram_test_hdlr();
        break;
#endif /*__MMI_EM_MISC_RAM_TEST__*/

#ifdef __MMI_EM_MISC_TOUCH_SCREEN__
    case MENU_ID_SSP_SETTINGS:
        {
            mmi_em_entry_ssp_settings_option_menu();
        }
        break;
    case MENU_ID_EM_MISC_TOUCH_SCREEN_PEN_EVENT:
        {
            mmi_em_misc_ts_pen_event_test_launch(GRP_ID_ROOT);
        }
        break;
        
     
    case MENU_ID_EM_MISC_TOUCH_SCREEN_ACCURACY:
        mmi_em_misc_tp_accuracy_enter(mmi_em_get_root_group());
        break;
        
    case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_SETTING: 
        mmi_em_misc_tp_param_setting_enter(mmi_em_get_root_group());
        break;

    case MENU_ID_EM_MISC_TOUCH_SCREEN_PARAM_RESET:
        mmi_em_misc_tp_param_reset_enter(mmi_em_get_root_group());
        break;
        
        
#ifdef __MMI_EM_MISC_MULTI_TOUCH__
    case MENU_ID_EM_MISC_TOUCH_SCREEN_MULTI_TOUCH:
        {
            mmi_em_multi_touch_test_launch();
        }
        break;
#endif /* __MMI_EM_MISC_TOUCH_SCREEN__ */

#endif

#ifdef __MMI_EM_MISC_CELL_RESELECTION__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    
#ifdef  __MMI_EM_MISC_VIDEO_PARAM__ //1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if 0
/* under construction !*/
#ifdef __MMI_FM_AUTO_TEST__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_FM_AUTO_TEST__*/
#endif

#if !defined(__MMI_EM_INET_APP_SLIM__)
    case MENU_ID_EM_MISC_INET_APP_USER_AGENT:
    case MENU_ID_EM_MISC_INET_APP_ACCEPT_HEADER:
    case MENU_ID_EM_MISC_INET_APP_MMS_VERSION:	
        mmi_em_inet_menu_select_handler(event);
        break;
#endif

#ifdef __MMI_EM_JAVA_SUPPORT__
    case MENU_ID_JAVA_EM_TCK:
        mmi_java_em_tck_enter();
        break;
#ifdef __MMI_EM_MISC_JAVA_PERFORMANCE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_EM_MISC_JUI_DEBUG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif     

#ifdef __MMI_EM_MISC_DM_REGISTER__
    case MENU_ID_EM_MISC_DM_SELF_REGISTER_NUMBER:
        mmi_em_misc_dm_self_register_entry();
        break;
        
    case MENU_ID_EM_MISC_DM_SELF_REGISTER_DEVICE_NAME:
        mmi_em_misc_dm_self_register_device_name_entry();
        break;
        
#ifdef __OP02_DM__
    case MENU_ID_EM_MISC_DM_SELF_REGISTER_PORT:
        EmMisDMGetSelfRegisterPort();
        break;
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_DUAL_SIM_MASTER__*/
#endif /*__MMI_EM_MISC_DM_REGISTER__*/
    
#ifdef __MMI_EM_MISC_X_DOWNLOAD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_X_DOWNLOAD__ */
#if (defined(__MMI_EM_MISC_CHECK_DRIVE__) && defined(__PLUTO_MMI_PACKAGE__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_EM_MISC_RECORDER_SETTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_DM_ADD_APN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef __MMI_MAINLCD_96X64__
    case MENU_ID_EM_MRE:
        mmi_em_misc_mre_select_hdlr();
        break;
#endif

    #ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
    case MENU_ID_EM_MISC_POWER_ON_CPU_QUERY:
        mmi_em_misc_power_on_cpu_query_hdlr();
        break;
    #endif

    default:
        break;
    }

    #ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
    switch(event->parent_menu_id)
    {
        case MENU_ID_EM_MISC_POWER_ON_CPU_QUERY:
            mmi_em_misc_power_on_cpu_query_list_hdlr(event);
        break;
    }
    #endif

    return;
}

void mmi_em_misc_menu_event_entry_hdlr(cui_menu_event_struct *event)
{
    switch (event->parent_menu_id)
    {
#ifdef __MMI_EM_MISC_AUTO_ANSWER__
    case MENU_ID_EM_MISC_AUTO_ANSWER:
        mmi_em_misc_set_item_on_off((MMI_BOOL)(srv_callset_answer_mode_get_mode() & SRV_CALLSET_ANSWER_MODE_AUTO), event);
        break;
#endif /*__MMI_EM_MISC_AUTO_ANSWER__*/
        
#ifdef __MMI_EM_MISC_HIGHSPEED_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
#ifdef __MMI_EM_MISC_BACKLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_EM_MISC_MEMORY_DUMP__
    case MENU_ID_EM_MISC_MEMORY_DUMP:
        mmi_em_misc_set_item_on_off((MMI_BOOL)(INT_MemoryDumpFlag == EX_FORCEMEMORYDUMP), event);
        break;
#endif /*__MMI_EM_MISC_MEMORY_DUMP__*/
		
#ifdef __MMI_EM_MISC_AMR__
    case MENU_ID_EM_MISC_AMR:
        mmi_em_misc_arm_enter(event);
        break;
#endif

#ifdef __MMI_EM_MISC_DCD__
#ifdef __MMI_OP01_DCD_V30__
    case MENU_ID_EM_MISC_DCD_STORAGE_SWITCH:
        mmi_em_misc_set_item_on_off(mmi_em_misc_dcd_get_storage_switch(), event);
        break;
#endif
#endif
    
#ifdef __MMI_EM_MISC_CELL_RESELECTION__
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__MMI_EM_INET_APP_SLIM__)
    case MENU_ID_EM_MISC_INTERNET_APPLICATION:
        mmi_em_inet_menu_entry_handler(event);	
        break;
#endif
    
#ifdef __MMI_EM_MISC_DM_REGISTER__
    case MENU_ID_EM_MISC_DM_SELF_REGISTER:
        break;
        
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else /*__MMI_DUAL_SIM_MASTER__*/
    case MENU_ID_EM_MISC_DM_SELF_REGISTER_RESULT:
#endif /*__MMI_DUAL_SIM_MASTER__*/
        mmi_em_misc_set_item_true_false((MMI_BOOL)(mmi_em_misc_dm_self_register_get_result() == MMI_TRUE), event);
        break;
    case MENU_ID_EM_MISC_DM_SELF_REGISTER_MASTER_SWITCH:
        mmi_em_misc_set_item_true_false((MMI_BOOL)(mmi_em_misc_dm_self_register_get_master_swicth_result() == MMI_TRUE), event);
        break;
#endif /*__MMI_EM_MISC_DM_REGISTER__*/

#ifdef __MMI_EM_MISC_VIDEO_HI_BITRATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_EM_MISC_VIDEO_HI_BITRATE__ */

#ifdef __MMI_EM_MISC_TOUCH_SCREEN__
    case MENU_ID_EM_MISC_TOUCH_SCREEN://..
    #if !(defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) || defined(__MMI_EDITOR_SSP_SUPPORT__))
    cui_menu_set_item_hidden(event->sender_id, MENU_ID_SSP_SETTINGS, 1);
    #endif
    break;
#endif
    #ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
    case MENU_ID_EM_MISC_POWER_ON_CPU_QUERY:
        mmi_em_misc_power_on_cpu_query_pre_hdlr(event);
    break;
    #endif

    default:
        break;
    }
}

#ifdef __MMI_EM_MISC_POWER_ON_CPU_QUERY__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_set_power_on_cpu_query_rsp
 * DESCRIPTION
 *  about set wcdma preferred rsp info
 * PARAMETERS
 *  void *msg [IN] about set power on cpu query rsp info pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_misc_set_power_on_cpu_query_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_set_essp_rsp_struct *msg_data;
    mmi_em_get_essp_rsp_struct *msgdata;//
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = (mmi_em_set_essp_rsp_struct*)msg;
    mmi_em_display_notify_popup(msg_data->result);
    
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_EM_SET_ESSP_RSP, (PsIntFuncPtr)NULL);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_GET_ESSP_RSP, 
                                       (PsIntFuncPtr)mmi_em_nw_get_power_on_cpu_query_rsp, 
                                       MMI_FALSE);
    mmi_frm_send_ilm((oslModuleType)MOD_L4C, MSG_ID_MMI_EM_GET_ESSP_REQ, NULL, NULL);
    cui_menu_pause(mmi_em_get_main_menu_id());
    msgdata = MMI_EM_CONSTRUCT_MSG_DATA(mmi_em_get_essp_rsp_struct);//
    msgdata->mode = g_em_misc_power_on_cpu_query_cntx.sel_cntx_index;//
    mmi_em_nw_get_power_on_cpu_query_rsp(msgdata);//
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_power_on_cpu_query_list_hdlr
 * DESCRIPTION
 *  switch power on cpu query status
 * PARAMETERS
 *  cui_menu_event_struct *evt [IN] about power on cpu query menu
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_misc_power_on_cpu_query_list_hdlr(cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_set_essp_req_struct *msg_data;
    mmi_em_set_essp_rsp_struct *msg;//
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/                             
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_SET_ESSP_RSP, 
                                       (PsIntFuncPtr)mmi_em_misc_set_power_on_cpu_query_rsp, 
                                       MMI_FALSE);
    
    msg_data = MMI_EM_CONSTRUCT_MSG_DATA(mmi_em_set_essp_req_struct);
    msg_data->mode = cui_menu_get_index_in_currlist_from_menu_id(evt->sender_id, evt->highlighted_menu_id);
    mmi_frm_send_ilm((oslModuleType)MOD_L4C, (oslMsgType)MSG_ID_MMI_EM_SET_ESSP_REQ, (oslParaType*)msg_data, NULL);
    msg = MMI_EM_CONSTRUCT_MSG_DATA(mmi_em_set_essp_rsp_struct);//
    msg->result = KAL_TRUE;//
    g_em_misc_power_on_cpu_query_cntx.sel_cntx_index = msg_data->mode;//
    mmi_em_misc_set_power_on_cpu_query_rsp(msg);//
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nw_get_power_on_cpu_query_rsp
 * DESCRIPTION
 *  deal with get rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_nw_get_power_on_cpu_query_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_get_essp_rsp_struct *msg_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = (mmi_em_get_essp_rsp_struct*)msg;
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_EM_SET_ESSP_RSP, (PsIntFuncPtr)NULL);
    g_em_misc_power_on_cpu_query_cntx.sel_cntx_index = msg_data->mode;
    cui_menu_play(mmi_em_get_main_menu_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_power_on_cpu_query_hdlr
 * DESCRIPTION
 *  deal with wcdma preferred
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_misc_power_on_cpu_query_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_get_essp_rsp_struct *msg_data;//
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_GET_ESSP_RSP, 
                                       (PsIntFuncPtr)mmi_em_nw_get_power_on_cpu_query_rsp, 
                                       MMI_FALSE);
    mmi_frm_send_ilm((oslModuleType)MOD_L4C, MSG_ID_MMI_EM_GET_ESSP_REQ, NULL, NULL);
   
    msg_data = MMI_EM_CONSTRUCT_MSG_DATA(mmi_em_get_essp_rsp_struct);//
    msg_data->mode = g_em_misc_power_on_cpu_query_cntx.sel_cntx_index;//
    mmi_em_nw_get_power_on_cpu_query_rsp(msg_data);//
    
    cui_menu_pause(mmi_em_get_main_menu_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_misc_power_on_cpu_query_pre_hdlr
 * DESCRIPTION
 *  deal with wcdma preferred
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_misc_power_on_cpu_query_pre_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
    if (g_em_misc_power_on_cpu_query_cntx.sel_cntx_index == EM_MISC_POWER_ON_CPU_DEFAULT_STATUS)
    {
        menu_id = MENU_ID_EM_MISC_POWER_ON_DEFAULT;
        cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, menu_id);
    }
    else if (g_em_misc_power_on_cpu_query_cntx.sel_cntx_index == EM_MISC_POWER_ON_CPU_NO_QUERY_STATUS)
    {
        menu_id = MENU_ID_EM_MISC_POWER_ON_NO_QUERY;
        cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, menu_id);
    }
    else if (g_em_misc_power_on_cpu_query_cntx.sel_cntx_index == EM_MISC_POWER_ON_CPU_QUERY_STATUS)
    {
        menu_id = MENU_ID_EM_MISC_POWER_ON_QUERY;
        cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, menu_id);
    }
    else
    {
        ASSERT(0);
    } 

}
#endif

#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 


#endif /* __MMI_ENGINEER_MODE__ */
