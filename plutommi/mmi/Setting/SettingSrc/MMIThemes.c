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
 * MMIthemes.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Theme application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
                                                                               ****************************************************************************//**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************
   FILENAME : MMIThemes.c
   PURPOSE     : Theme application
   REMARKS     : nil
   AUTHOR      : Restructured by manju
   DATE     : Restructured on May-24-2003
**************************************************************/
#include "MMI_features.h"

/*  Include: MMI header file */
#ifdef __MMI_THEMES_APPLICATION__
#include "CommonScreens.h"
#include "AlarmFrameworkProt.h"
#include "AlarmGprot.h"
#include "FileMgrSrvGProt.h"


#include "WPSSProtos.h"
#include "InlineCuiGprot.h"
#include "AlarmGprot.h"
#include "Menucuigprot.h"
#include "BootupSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"

#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "mmi_rp_srv_mmi_theme_def.h"
#include "MMIThemesGprot.h"
#include "MMIThemesDef.h"
#include "MMIThemes.h"
#include "JavaAgencyDef.h"

    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "MMIDataType.h"
    #include "kal_non_specific_general_types.h"
    #include "GlobalResDef.h"
    #include "wgui_categories_list.h"
    #include "wgui_touch_screen.h"
    #include "wgui_inline_edit.h"
    #include "wgui_categories_util.h"
    #include "custom_mmi_default_value.h"
    #include "mmi_theme_mgr.h"
    #include "mmi_frm_history_gprot.h"
    #include "CommonScreensResDef.h"
    #include "AlertScreen.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "string.h"
    #include "GlobalConstants.h"
    #include "wgui_draw_manager.h"
    #include "gui_typedef.h"
    #include "wgui_categories.h"
    #include "mmi_frm_input_gprot.h"
    #include "mmi_frm_gprot.h"
    #include "NotificationGprot.h"
    #include "kal_trace.h"
    #include "nvram_common_defs.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "gui_data_types.h"
    #include "custom_events_notify.h"
    #include "wgui_categories_popup.h"
    #include "browser_api.h"
    #include "kal_general_types.h"
    #include "mmi_common_app_trc.h"
    #include "Unicodexdcl.h"
    #include "kal_public_api.h"
    #include "ImeGprot.h"
    #include "wgui_categories_inputs.h"
    #include "CustMenuRes.h"
    #include "wgui_inputs.h"
    #include "FileMgrServiceResDef.h"
    #include "MMI_fw_trc.h"
    #include "mmi_fw_trc.h"
    #include "stdio.h"
    #include "fs_func.h"
    #include "fs_errcode.h"
    #include "fs_type.h"
    #include "PhoneSetupResList.h"
    #include "lcd_sw_inc.h"
    #include "stdlib.h"
    #include "FileMgrType.h"
#include "IdleGprot.h"    
#include "ModeSwitchSrvGprot.h"
#include "AlarmProt.h"      
#include "MMI_ap_dcm_config.h"
#include "AlarmDef.h"
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif
/******************************************************************************
 * typedef
 *****************************************************************************/
typedef void (*soft_key_hdlr) (MMI_ID);
typedef void (*del_callback_hdlr) (MMI_ID);

typedef struct
{
    mmi_id sg_id;
    soft_key_hdlr LSK_function;
    soft_key_hdlr CSK_function;
    soft_key_hdlr RSK_function;
}mmi_theme_confirm_user_data_struct;

typedef struct
{
    mmi_id sg_id;
    del_callback_hdlr callback_function;
}mmi_theme_popup_user_data_struct;
    
    
typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
}mmi_theme_common_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_inline_id;
}mmi_theme_set_order_group_data_struct;

#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif

#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
#else
typedef struct
{
    U8 freq_type;
    U8 current_theme_index;
    S16 set_order_flag;
    U8 themes_order[4];
} thm_nvram_struct;
#endif  

/******************************************************************************
 * Define
 *****************************************************************************/
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#else
#define MMI_THEME_INLINE_ITEM_COUNT		    (NO_OF_ORDERS)
#endif

#define NO_OF_THEME_OPTION_MENUITEMS_IN_USB_MODE 2
#define THM_MAX_URL_LENGTH      255
#define THM_DEFAULT_URI_SCHEME	"http://"
#define MAX_URL_LIST_ENTRIES 		7

#define MMI_THM_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_THM_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_THM_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_THM_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

/******************************************************************************
 * Local Variable
 *****************************************************************************/
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif

static const cui_inline_set_item_struct cui_set_order[4] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L1, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L2, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L3, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L4, NULL}
};
//static mmi_id mmi_theme_set_order_child_gid = GRP_ID_INVALID;
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif

thm_contex_struct g_thm_cntx;

/* map update period to index */
static const U8 g_themes_freq_set[THMEM_FREQ_NUM] =
{
    ALM_FREQ_OFF, 
    ALM_FREQ_HOURLY, 
    ALM_FREQ_EVERYDAY, 
    ALM_FREQ_WEEKLY, 
    ALM_FREQ_MONTHLY, 
    ALM_FREQ_SEASONALLY
};

/******************************************************************************
 * Local Function
 *****************************************************************************/
static mmi_ret mmi_theme_main_group_proc(mmi_event_struct *evt);
static void mmi_theme_entry_int(void);
static mmi_ret mmi_theme_option_group_proc(mmi_event_struct* evt);
static void EntryThmOptions(void);
static void mmi_theme_option_menu_cui_entry_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_option_menu_cui_highlight_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_theme_set_order_group_proc(mmi_event_struct* evt);
static void mmi_theme_inline_submit_proc(mmi_event_struct *evt);
static void SaveOrderThemes(mmi_id parent_id);
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#else
static U8 mmi_thm_reset_current_theme(void);
#endif

//static void mmi_thm_display_confirm(U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns);

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_thm_tap_list_callback(mmi_tap_type_enum tap_type, S32 index);
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
#endif
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

#if 0
#ifndef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
#endif
#else
static void ReadThemesFromNVRAM(void);
#endif

/****************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef OBIGO_SUPPORT
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif

/* Leo end */
#ifdef __J2ME__
extern void jam_pause_dummy_screen(void);
extern void jam_resume_dummy_screen(void);
#endif /* __J2ME__ */ 

extern void UpdateUITheme(void);
extern const CHAR *gDefaultDLT_URL;

/* Leo add for DLT */
extern int wap_is_ready(void);
/* Leo end */

#ifndef __MTK_TARGET__
extern S32 mmi_mte_is_active(void);
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  InitThemes
 * DESCRIPTION
 *  Initialize themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitThemes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__        /* ritesh */
    mmi_theme_manager_init();
    ConstructThemeList();

    /* ConstructThemeOrderList(); */
    mmi_tm_activate_theme_at_bootup();
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    SetThemes((U8)g_thm_cntx.CurrTheme);
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    FillThemesList();
    ReadThemesFromNVRAM();
    MMI_apply_current_theme();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ /* ritesh */

    /* Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  ThemesFCBInit
 * DESCRIPTION
 *  Set calback function of alarm framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesFCBInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mmi_alm_set_start_index(ALM_TYPE_THEME, ALM_THM_START);
    AlmSetExpiryTimeCB(ALM_TYPE_THEME, ThemesExpiryTimeCBH);
    AlmSetExpiryHandlerCB(ALM_TYPE_THEME, ThemeAlarmCallBack);
#ifdef __MMI_THEMES_V2_SUPPORT__
    AlmSetInitHandlerCB(ALM_TYPE_THEME, ConstructThemeOrderList, ThemesReInitQueueCBH);
#else
	AlmSetInitHandlerCB(ALM_TYPE_THEME, ReadThemesFromNVRAM, ThemesReInitQueueCBH);
#endif */

}

mmi_ret mmi_theme_rmdr_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables																	   */
	/*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;
	U16 period;

	/*----------------------------------------------------------------*/
	/* Code Body																		   */
	/*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_THEME && 
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
		#ifdef __MMI_THEMES_V2_SUPPORT__
			ConstructThemeOrderList();
		#else
			ReadThemesFromNVRAM();
#endif
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
			ThemeAlarmCallBack(remdr_evt->usr_data, &period, !remdr_evt->pwr_off);
			break;

		case SRV_REMINDER_NOTIFY_REINIT:
			ThemesReInitQueueCBH();
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			break;

		default:
			break;
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ThemesExpiryTimeCBH
 * DESCRIPTION
 *  Callback handler to get information of theme expiry setting.
 * PARAMETERS
 *  index           [IN]            
 *  alarmTime       [?]             
 *  Freq            [?]             
 *  WeekDays        [?]             
 *  MYTIME(?)       [IN/OUT]        Expiry time set by user
 *  U8(?)           [IN/OUT]        Expiry days of week
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME* preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *Freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];
    *WeekDays = 1;
}


/*****************************************************************************
 * FUNCTION
 *  ThemesReInitQueueCBH
 * DESCRIPTION
 *  Reinit themes to alarm queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (freq != ALM_FREQ_OFF)
    {
    	MYTIME currTime, almTime;
		
    	DTGetRTCTime(&currTime);
		currTime.nMin = 0;
		currTime.nSec = 0;
        almTime = srv_reminder_calc_time(&currTime, (srv_reminder_repeat_enum)freq, 0);
	srv_reminder_set(SRV_REMINDER_TYPE_THEME, &almTime, 0);
    }
}

extern void ExecSubLCDCurrExitHandler(void);
extern void GoBackSubLCDHistory(void);


/*****************************************************************************
 * FUNCTION
 *  SetBothLCDThemes
 * DESCRIPTION
 *  Set themes of both main and sub lcd
 * PARAMETERS
 *  index       [IN]        Index of theme
 * RETURNS
 *  void
 *****************************************************************************/
void SetBothLCDThemes(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    ExecSubLCDCurrExitHandler();
    GoBackSubLCDHistory();
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetThemes(index);
    UpdateUITheme();
    //MTK Leo add, fix theme update issue
    //      SUBLCD_RedrawCategoryFunction();
    ExecSubLCDCurrExitHandler();
    GoBackSubLCDHistory();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_confirm_user_data_init
 * DESCRIPTION
 *  Highlight handler of to do list task list, store the index of selected task.
 * PARAMETERS
 *  nIndex      [IN]        Index of selected task.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_confirm_user_data_init(mmi_theme_confirm_user_data_struct* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arg->sg_id = GRP_ID_INVALID;
    arg->LSK_function = NULL;
    arg->CSK_function = NULL;
    arg->RSK_function = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_comfirm_proc
 * DESCRIPTION
 *  Highlight handler of to do list task list, store the index of selected task.
 * PARAMETERS
 *  nIndex      [IN]        Index of selected task.
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_theme_comfirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            mmi_theme_confirm_user_data_struct* confirm_data = 
                (mmi_theme_confirm_user_data_struct*)alert->user_tag;

            switch (alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                {
                    mmi_frm_group_close(alert->alert_id);
                    break;
                }
                case MMI_ALERT_CNFM_YES:
                {
                    if (confirm_data->LSK_function != NULL)
                    {
                        confirm_data->LSK_function(confirm_data->sg_id);
                    }
                    break;
                }
                case MMI_ALERT_CNFM_NO:
                {
                    if (confirm_data->RSK_function != NULL)
                    {
                        confirm_data->RSK_function(confirm_data->sg_id);
                    }
                    break;
                }
                default:
                    break;
            }
        }
        default:
        {
            break;
        }        
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_popup_user_data_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_popup_user_data_init(mmi_theme_popup_user_data_struct* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arg->sg_id = GRP_ID_INVALID;
    arg->callback_function = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_popup_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_theme_popup_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {        
            mmi_event_popoupcallback_result_struct *popup_evt = (mmi_event_popoupcallback_result_struct*)evt;
            mmi_theme_popup_user_data_struct *popup_data = popup_evt->user_tag;
            popup_data->callback_function(popup_data->sg_id);
            break;
        }
        default:
        {
            break;
        }
    }
	return MMI_RET_OK;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
/* under construction !*/
#else
/*****************************************************************************
 * FUNCTION
 *  FillThemesList
 * DESCRIPTION
 *  Fill inline item selection items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillThemesList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.TmpOrderList[0] = (S32) g_thm_cntx.CurrOrderList[0];
    g_thm_cntx.TmpOrderList[1] = (S32) g_thm_cntx.CurrOrderList[1];
    g_thm_cntx.TmpOrderList[2] = (S32) g_thm_cntx.CurrOrderList[2];
    g_thm_cntx.TmpOrderList[3] = (S32) g_thm_cntx.CurrOrderList[3];

    for (index = 0; index < g_thm_cntx.TotalTheme; index++)
    {
        g_thm_cntx.ThemeName[index] = (PU8) GetString((U16) (STR_THEME_DEFAULT + index));
    }

    g_thm_cntx.ThemeName[index] = (PU8) GetString(STR_GLOBAL_NONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_reset_current_theme
 * DESCRIPTION
 *  delete callback function of theme menu screen.
 *  used to reset preview theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_thm_reset_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrTheme);
    }
    
    g_thm_cntx.IsInThmApp = 0;
    
    return MMI_FALSE;
    
}

#endif  //0
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  SaveOrderThemes
 * DESCRIPTION
 *  set order themes and save in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveOrderThemes(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 flag = 0;

    /* Leo add for DLT */
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#else  
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        if (g_thm_cntx.CurrOrderList[index] != (U8) g_thm_cntx.TmpOrderList[index])
        {
            flag = 1;
            break;
        }
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    if (flag)   /* order changed */
    {
        g_thm_cntx.CurrOrderIndex = -1;
        g_thm_cntx.IsOrderChanged = 1;
#if 0
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#else  
        g_thm_cntx.CurrOrderList[0] = (CHAR) g_thm_cntx.TmpOrderList[0];
        g_thm_cntx.CurrOrderList[1] = (CHAR) g_thm_cntx.TmpOrderList[1];
        g_thm_cntx.CurrOrderList[2] = (CHAR) g_thm_cntx.TmpOrderList[2];
        g_thm_cntx.CurrOrderList[3] = (CHAR) g_thm_cntx.TmpOrderList[3];
        g_thm_cntx.IsOrderChanged = 1;
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        SetStartPositionofCurIndex();
        WriteThemesToNVRAM();
#if 0
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
    #endif 
    #endif 
    }

	mmi_popup_display_simple(
                	(WCHAR*)get_string(STR_GLOBAL_DONE),
                	MMI_EVENT_SUCCESS,
                	parent_id,
                	0);
    g_thm_cntx.IsInThmApp = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmSetOrder
 * DESCRIPTION
 *  Set LSK of set order list
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmSetOrder(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);    /* Force LSK label to "Ok" each time */
//    SetCategory57LeftSoftkeyFunction(SaveOrderThemes);  
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);    
//    SetCenterSoftkeyFunction(SaveOrderThemes, KEY_EVENT_UP);                            
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_get_period_hint_string
 * DESCRIPTION
 *  hint the update period menu
 * PARAMETERS
 *  index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHNSET_SLIM__    
CHAR*  mmi_theme_get_period_hint_string(FREQ_ALARM theme_freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR *hint_string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (theme_freq)
    {
    case ALM_FREQ_OFF:
        hint_string = GetString(STR_GLOBAL_OFF);
        break;
        
    case ALM_FREQ_HOURLY:
        hint_string = GetString(STR_MENU3302_UPDATE_HOURLY);
        break;
        
    case ALM_FREQ_EVERYDAY:
        hint_string = GetString(STR_MENU3303_UPDATE_DAILY);
        break;

    case ALM_FREQ_WEEKLY:
        hint_string = GetString(STR_MENU3304_UPDATE_WEEKLY);
        break;
        
    case ALM_FREQ_MONTHLY:
        hint_string = GetString(STR_MENU_UPDATE_MONTHLY);
        break;
        
    case ALM_FREQ_SEASONALLY:
        hint_string = GetString(STR_MENU_UPDATE_SEASONALLY);
        break;
        
    default:
        break;
    }
    
	return hint_string;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryThmSetOrder
 * DESCRIPTION
 *  Entry function of set order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmSetOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    mmi_theme_set_order_group_data_struct *set_order_user_data;         
    cui_inline_struct inline_data;
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
#endif
#endif
    U8 item_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_order_user_data = (mmi_theme_set_order_group_data_struct*)
                                    OslMalloc(sizeof(mmi_theme_set_order_group_data_struct));
    memset(set_order_user_data, 0, sizeof(mmi_theme_set_order_group_data_struct));
    set_order_user_data->parent_id = GRP_ID_THM_MAIN;

    set_order_user_data->group_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_MAIN,
                                                GRP_ID_THM_SET_ORDER,
                                                mmi_theme_set_order_group_proc,
                                                set_order_user_data,
                                                MMI_FRM_NODE_NONE_FLAG);
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#else
    g_thm_cntx.IsInThmApp = 2;
    for (i = 0; i < NO_OF_ORDERS; i++)
    {
        g_thm_cntx.TmpOrderList[i] = (S32)g_thm_cntx.CurrOrderList[i];
    }
    item_number = MMI_THEME_INLINE_ITEM_COUNT;
#endif

    inline_data.items_count = MMI_THEME_INLINE_ITEM_COUNT;
    inline_data.title = STR_MENU3202_SET_ORDER;
    inline_data.title_icon = NULL;//GetRootTitleIcon(MENU3101_THEMES);
    inline_data.screen_flag = CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_data.softkey = NULL;
    inline_data.items = cui_set_order;

    set_order_user_data->cui_inline_id = cui_inline_create(
                                                GRP_ID_THM_SET_ORDER,
                                                &inline_data);

    if (set_order_user_data->cui_inline_id != GRP_ID_INVALID)
    {           
   #if 0
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
  #endif  
        for (i = 0; i < item_number; i++)
        {                                    
            cui_inline_set_item_select(
                                    set_order_user_data->cui_inline_id,
                                    CUI_INLINE_ITEM_ID_BASE + i,
                                    g_thm_cntx.TotalTheme + 1,
                                    g_thm_cntx.ThemeName,
                                    g_thm_cntx.TmpOrderList[i]);
                            
        }        
        cui_inline_run(set_order_user_data->cui_inline_id);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_THM_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_set_order_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_set_order_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_set_order_group_data_struct *set_order_user_data;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    set_order_user_data = (mmi_theme_set_order_group_data_struct*)evt->user_data;
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
        {
            mmi_frm_group_close(GRP_ID_THM_SET_ORDER);        
            break;
        }
        case EVT_ID_POPUP_QUIT:
        {        
            mmi_frm_group_close(GRP_ID_THM_SET_ORDER);
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(set_order_user_data);
            break;
        }    
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_theme_inline_submit_proc(evt);
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {        
            cui_inline_close(set_order_user_data->cui_inline_id);
            mmi_frm_group_close(set_order_user_data->group_id);
            break;
        }            
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_inline_submit_proc
 * DESCRIPTION
 *  Inline proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_inline_submit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 item_number;    
    mmi_theme_set_order_group_data_struct *set_order_user_data;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    set_order_user_data = (mmi_theme_set_order_group_data_struct*)evt->user_data;
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__    
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#else
    item_number = MMI_THEME_INLINE_ITEM_COUNT;
#endif
    
    for (i = 0; i < item_number; i++)
    {
        cui_inline_get_value(
                    set_order_user_data->cui_inline_id, 
                    CUI_INLINE_ITEM_ID_BASE + i,
                    &g_thm_cntx.TmpOrderList[i]);
    }
    SaveOrderThemes(set_order_user_data->group_id);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
#endif 
/* under construction !*/
#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_AP_DCM_SETTING__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
#endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#endif 

/*****************************************************************************
 * FUNCTION
 *  HighlightThmMenu
 * DESCRIPTION
 *  Hilite function of main themes menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_theme_launch, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_theme_launch, KEY_EVENT_UP);    
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmUpdatePeriod
 * DESCRIPTION
 *  Hilite function of pupdate period
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmUpdatePeriod(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set IsSetFromMenu flag */
    g_thm_cntx.IsSetFromMenu = 1;
    g_thm_cntx.CurrHiliteItem = (U8) nIndex;

    if (nIndex > 0) /* update theme */
    {
        SetLeftSoftkeyFunction(UpdateThemePeriod, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(UpdateThemePeriod, KEY_EVENT_UP);
    }
    else    /* OFF */
    {
        SetLeftSoftkeyFunction(UpdateThemeOff, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(UpdateThemeOff, KEY_EVENT_UP);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmItems
 * DESCRIPTION
 *  Highlight handler of Theme menu,
 *  function show the current selected theme
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmItems(S32 index)
{
#ifdef __MMI_THEMES_V2_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrHiliteTheme = thm_details[index].theme_id;
    g_temp_thm_index = index;
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    g_thm_cntx.CurrHiliteTheme = (U8) index;
    SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
    /* PMT VIKAS START 20050707 */
#if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    gOnFullScreen |= MMI_LEAVE_FULL_SCREEN; /* for showing the updated status bar on Theme menu. */
#endif 
    /* PMT VIKAS END 20050707 */
    /* Reset screen background layer */
    dm_set_scr_bg_redraw(MMI_TRUE); 
    RedrawCategoryFunction();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ThmHandleRSK
 * DESCRIPTION
 *  Change theme to original one and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes((U8)g_thm_cntx.CurrTheme);
    }

    g_thm_cntx.IsInThmApp = 0;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  ThmRedrawTheme
 * DESCRIPTION
 *  Redraw current hilite theme in option menu to make the user preceive current
 *  selecting theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmRedrawTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes((U8)g_thm_cntx.CurrHiliteTheme);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitThmMenu
 * DESCRIPTION
 *  Exit function for theme menu, restore theme after exit theme screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitThmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
        /* PMT VIKAS START 20050707 */
#if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    {
        gOnFullScreen |= MMI_LEAVE_FULL_SCREEN; /* for showing the updated status bar on Theme menu. */
#endif /* (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__) */ 
        //if (IsBackHistory == MMI_TRUE)
        {
            SetBothLCDThemes((U8)g_thm_cntx.CurrTheme);
        }
    #if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    }
    #endif 
    /* PMT VIKAS END 20050707 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_menu_handler
 * DESCRIPTION
 *  Proc function for display setup group 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_theme_menu_handler(void *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    mmi_ret ret = MMI_RET_DONT_CARE;
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (evt->highlighted_menu_id)
            {
                case MENU3101_THEMES:
                {
                    mmi_theme_launch();
                    return MMI_RET_OK;
                }
                default:
                    break;
            }    
            break;
        }
        default:
        {        
            break;
        }
    }
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_launch
 * DESCRIPTION
 *  Show a lsit of themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(GRP_ID_ROOT,
                         GRP_ID_THM_MAIN,
                         mmi_theme_main_group_proc,
                         NULL,
                         MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_thm_cntx.IsInThmApp = MMI_TRUE;
#if 0   
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif    
    {
        mmi_theme_entry_int();
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif


#if 0
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_PHNSET_SLIM__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_AP_DCM_SETTING__
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
#ifdef __OTG_ENABLE__
/* under construction !*/
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
#ifndef __OTG_ENABLE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OTG_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OTG_ENABLE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#ifdef __MMI_AP_DCM_SETTING__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
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
#ifdef __MMI_AP_DCM_SETTING__
/* under construction !*/
#endif
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/* under construction !*/
#else

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_theme_entry_int
 * DESCRIPTION
 *  Function to show theme list from theme application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_entry_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *list_icons1;
    U16 *list_icons2;
    U16 nItems;
    U8 *guiBuffer;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_frm_scrn_enter(
            GRP_ID_THM_MAIN,
            SCR_ID_THM_MENU,
            ExitThmMenu,
            mmi_theme_entry_int,
            MMI_FRM_FULL_SCRN);

    FillThemesList();
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = (U16) g_thm_cntx.TotalTheme;
    list_icons1 = (U16*) OslMalloc(nItems * sizeof(PU16));
    list_icons2 = (U16*) OslMalloc(nItems * sizeof(PU16));
    
    for (i = 0; i < nItems; i++)
    {
        if (i == g_thm_cntx.CurrTheme)
        {
            list_icons1[i] = IMG_VICON;
        }
        else
        {
            list_icons1[i] = IMAGE_NOIMAGE_THEME;
        }
    }
    
    for (i = 0; i < nItems; i++)
    {
        list_icons2[i] = IMAGE_NOIMAGE_THEME;
    }

    RegisterHighlightHandler(HighlightThmItems);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16) g_thm_cntx.CurrTheme,
        guiBuffer,
        0);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(mmi_thm_tap_list_callback);
#endif

    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(ActivateTheme, KEY_EVENT_UP); 
    
    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
    
    if (list_icons1)
    {
        OslMfree(list_icons1);
    }
    
    if (list_icons2)
    {
        OslMfree(list_icons2);
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_main_group_proc
 * DESCRIPTION
 *  Proc function of edit group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_main_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(evt->evt_id)
    {
#ifndef __MMI_PHNSET_SLIM__    
        case EVT_ID_GROUP_FIRST_ENTRY:
        {
            break;
        }
        #endif
        case EVT_ID_GROUP_DEINIT:
        {
	#if 0
        #ifndef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
        #endif
        #endif
            break;
        }
#ifndef __MMI_PHNSET_SLIM__    
        default:
            break;
        #endif    
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  ThmHandleEndKey
 * DESCRIPTION
 *  Function handle end key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmHandleEndKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes((U8)g_thm_cntx.CurrTheme);
    }

    g_thm_cntx.IsInThmApp = 0;
    mmi_idle_display();
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmOptions
 * DESCRIPTION
 *  Entry func of themes option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryThmOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id = 0;  
    mmi_theme_common_group_data_struct *opt_user_data;         
//    U16 nItems;
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opt_user_data = (mmi_theme_common_group_data_struct*)OslMalloc(sizeof(mmi_theme_common_group_data_struct));
    memset(opt_user_data, 0, sizeof(mmi_theme_common_group_data_struct));
    opt_user_data->parent_id = GRP_ID_THM_MAIN;

    opt_user_data->group_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_MAIN,
                                                GRP_ID_AUTO_GEN,
                                                mmi_theme_option_group_proc,
                                                opt_user_data,
                                                MMI_FRM_NODE_NONE_FLAG);
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __FLIGHT_MODE_SUPPORT__
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
            #ifdef __FLIGHT_MODE_SUPPORT__
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
            #ifdef __FLIGHT_MODE_SUPPORT__
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
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#else   
	 menu_id = MENU3001_THEMES_LIST;
#endif  

    opt_user_data->child_id = cui_menu_create(
                                        opt_user_data->group_id,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        menu_id,
                                        MMI_TRUE,
                                        NULL);
    cui_menu_set_default_title_by_id(
                            opt_user_data->child_id, 
                            STR_GLOBAL_OPTIONS,
                            0);

    cui_menu_run(opt_user_data->child_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_option_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_theme_common_group_data_struct *opt_user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    opt_user_data = (mmi_theme_common_group_data_struct*)evt->user_data;
    switch(menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(opt_user_data);
            break;
        }    
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_theme_option_menu_cui_entry_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_theme_option_menu_cui_highlight_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_theme_option_menu_cui_select_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(opt_user_data->child_id);
            mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_menu_cui_entry_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_option_menu_cui_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    //mmi_theme_common_group_data_struct *opt_user_data = menu_evt->user_data;     
    mmi_group_event_struct *common_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->parent_menu_id)
    {
        case MENU3201_UPDATE_PERIOD:
        {
            common_evt = (mmi_group_event_struct*)menu_evt;
			cui_menu_set_default_title_string_by_id(common_evt->sender_id,STR_MENU3201_UPDATE_PERIOD);
			cui_menu_set_default_title_image_by_id(common_evt->sender_id, GetRootTitleIcon(MENU3101_THEMES));

	    if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
	    {
            cui_menu_set_currlist_highlighted_id(
                    common_evt->sender_id, 
                    g_thm_cntx.CurrUpdatePeriod + MENU3301_UPDATE_OFF);
							
	    }
            break;
        }   
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
		case MENU3001_THEMES_LIST:
			common_evt = (mmi_group_event_struct*)menu_evt;
			cui_menu_set_default_title_image_by_id(common_evt->sender_id, GetRootTitleIcon(MENU3101_THEMES));
		cui_menu_set_non_leaf_item(common_evt->sender_id, MENU3201_UPDATE_PERIOD, MMI_FALSE);
			break;
			
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_menu_cui_highlight_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_option_menu_cui_highlight_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_theme_common_group_data_struct *thm_data = (mmi_theme_common_group_data_struct *)menu_evt->user_data;     
    //U16 hint_string;
    CHAR* hint_string;
	U8 freq;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
#ifndef __MMI_PHNSET_SLIM__    
        case MENU_THEMES_ACTIVATE:
            break;
#endif            
            
        case MENU3201_UPDATE_PERIOD:
			freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];
#ifndef __MMI_PHNSET_SLIM__    
			hint_string = mmi_theme_get_period_hint_string((FREQ_ALARM)freq);
            #else
            {
                U16 i=0;
                U16  theme_period_hint_string[]={
                                    ALM_FREQ_HOURLY,
                                    ALM_FREQ_EVERYDAY,
                                    ALM_FREQ_WEEKLY,
                                    ALM_FREQ_MONTHLY,
                                    ALM_FREQ_SEASONALLY,
                                    NULL
                                    };
                    if(freq==ALM_FREQ_OFF)
                     {
                        hint_string = (CHAR*)GetString(STR_GLOBAL_OFF);;
                     }
                     else
                    {
                        while(theme_period_hint_string[i]!=freq)
                          {
                             i++;
                          }
                        hint_string=(CHAR*)GetString(STR_MENU3302_UPDATE_HOURLY+i);
                    }
       }
       #endif     
			cui_menu_set_item_hint(thm_data->child_id, MENU3201_UPDATE_PERIOD, (WCHAR *)hint_string);
			break;
			
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_menu_cui_select_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_theme_common_group_data_struct *opt_user_data = menu_evt->user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_THEMES_ACTIVATE:
        {
            ActivateTheme();
            break;
        }   
        case MENU3202_SET_ORDER:
        {
            EntryThmSetOrder();
            break;
        }

		case MENU3201_UPDATE_PERIOD:
		{
			EntryThmUpdatePeriod();
			break;
		}
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */  
#endif
        case MENU3301_UPDATE_OFF:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 0;
            UpdateThemeOff();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU3302_UPDATE_HOURLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 1;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU3303_UPDATE_DAILY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 2;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU3304_UPDATE_WEEKLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 3;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU_UPDATE_MONTHLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 4;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU_UPDATE_SEASONALLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 5;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmUpdatePeriod
 * DESCRIPTION
 *  entry func of themes update period menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmUpdatePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_common_group_data_struct *opt_user_data;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opt_user_data = (mmi_theme_common_group_data_struct*)OslMalloc(sizeof(mmi_theme_common_group_data_struct));
    memset(opt_user_data, 0, sizeof(mmi_theme_common_group_data_struct));
    opt_user_data->parent_id = GRP_ID_THM_MAIN;

    opt_user_data->group_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_MAIN,
                                                GRP_ID_AUTO_GEN,
                                                mmi_theme_option_group_proc,
                                                opt_user_data,
                                                MMI_FRM_NODE_NONE_FLAG);

    opt_user_data->child_id = cui_menu_create(
                                        opt_user_data->group_id,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_APPMAIN,
                                        MENU3201_UPDATE_PERIOD,
                                        MMI_TRUE,
                                        NULL);
    cui_menu_set_default_title_by_id(
                            opt_user_data->child_id, 
                            STR_MENU3201_UPDATE_PERIOD,
                            0/*GetRootTitleIcon(MENU3101_THEMES)*/);
                            
    cui_menu_run(opt_user_data->child_id);


}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  ActivateTheme
 * DESCRIPTION
 *  Activate theme select bu yser and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    S32 result;
    U16 img_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MTK_TARGET__
    /* If MTE is active, no theme activation is allowed. */
    if (mmi_mte_is_active())
    {
        mmi_popup_display_simple_ext(STR_THEME_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_THM_MAIN, NULL);
        return;
    }
#endif /* __MTK_TARGET__ */
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#else
{
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
        g_thm_cntx.CurrTheme = g_thm_cntx.CurrHiliteTheme;

        if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
        {
            SetStartPositionofCurIndex();
        }
        WriteThemesToNVRAM();
    }

    mmi_popup_display_simple_ext(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS, GRP_ID_THM_MAIN, NULL);
		
}

#endif
	g_thm_cntx.IsInThmApp = 0;
}

#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
#endif

/*****************************************************************************
 * FUNCTION
 *  UpdateThemeOff
 * DESCRIPTION
 *  Cancel the update alarm set by user and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemeOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrOrderIndex = -1;
    g_thm_cntx.IsOrderChanged = 0;

    /* if previous setting is not off, some theme-alarm is set before, cancel the alarm */
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        //AlmCancelAlarm(ALM_THM_START);
        srv_reminder_cancel(SRV_REMINDER_TYPE_THEME,0);   
    }

    g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;

    WriteThemesToNVRAM();
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    g_thm_cntx.IsInThmApp = 0;
}

/* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */


/*****************************************************************************
 * FUNCTION
 *  AlarmExpireUpdateThemeOff
 * DESCRIPTION
 *  Sets the update theme alarm to off when no theme is present in set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlarmExpireUpdateThemeOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrOrderIndex = -1;
    g_thm_cntx.IsOrderChanged = 0;

    /* if previous setting is not off, some theme-alarm is set before, cancel the alarm */
    if (g_thm_cntx.CurrUpdatePeriod > 0)
    {
        //AlmCancelAlarm(ALM_THM_START);
        srv_reminder_cancel(SRV_REMINDER_TYPE_THEME,0);
    }

    g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;

    WriteThemesToNVRAM();

    g_thm_cntx.IsInThmApp = 0;
}

/* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */


/*****************************************************************************
 * FUNCTION
 *  UpdateThemePeriod
 * DESCRIPTION
 *  Set update period and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__

    if (g_thm_cntx.IsSetFromMenu == 1 && g_thm_cntx.CurrHiliteItem != g_thm_cntx.CurrUpdatePeriod)
    {
        g_thm_cntx.CurrUpdatePeriod = g_thm_cntx.CurrHiliteItem;
        g_thm_cntx.IsOrderChanged = 1;
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (g_thm_cntx.IsSetFromMenu == 1)
    {
        g_thm_cntx.CurrUpdatePeriod = g_thm_cntx.CurrHiliteItem;
        g_thm_cntx.IsOrderChanged = 1;
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetStartPositionofCurIndex();

    WriteThemesToNVRAM();

	// set reminder
    ThemesReInitQueueCBH();

    if (g_thm_cntx.IsSetFromMenu == 1)  /* not OFF */
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        g_thm_cntx.IsInThmApp = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ThemeAlarmCallBack
 * DESCRIPTION
 *  Call back function when theme alarm expires
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 ThemeAlarmCallBack(U8 index, U16 *period, BOOL power_on)
{
#ifdef __J2ME__
	U8 IsJavaPlaying = FALSE;
#endif	

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_THEMES_V2_SUPPORT__
    U8 no_of_times;
    S32 result = THEME_ERROR_FAILURE;
    U16 order_theme_id = 0;
    U16 count, start_index;
    U32 *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 1);
    
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00221092 */
    if (mmi_thm_get_usb_mode())
    {
        g_tm_was_theme_alarm_cb = MMI_TRUE;
        *period = ALM_WITHOUD_EXPIRY_PERIOD;
        #ifndef __MMI_DEV_NEW_SLIM__
            return ALM_HAS_NO_IND;
        #else
            return MMI_FALSE;
        #endif
    }

    count = GetIDList(&p, &g_thm_cntx.CurrOrderIndex); 
    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 2);

    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();

    for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
    {
        g_thm_cntx.SetOrderIDList[no_of_times] = p[no_of_times];
    }

    start_index = (U16)g_thm_cntx.CurrOrderIndex;
    if (start_index >= g_thm_cntx.TotalTheme)
    {
        start_index = 0;
    }
	
   MMI_TRACE(MMI_COMMON_TRC_G2_ORG, 
    		 MMI_THEME_UPDATE_CALLBACK, 
    		 (S32)count, 
    		 (S32)g_thm_cntx.CurrTheme, 
    		 (S32)g_thm_cntx.TotalTheme); 
               
    /* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */
    if (count == 0)
    {
        AlarmExpireUpdateThemeOff();
    }
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */
    else
        /* Fix for dodge ball game */
    {
	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671	
	#ifdef __J2ME__
        if (GetActiveScreenId() == SCR_JAVA_APP)
        {
            IsJavaPlaying = TRUE;
            jam_pause_dummy_screen();
        }
    #endif /* __J2ME__ */ 
	//PMT DNLD FIXES 20060513: SUKRIT END MAUI_00192671

        for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
        {
            if ((g_thm_cntx.CurrOrderIndex == (g_thm_cntx.TotalTheme) - 1) ||
                g_thm_cntx.CurrOrderIndex >= g_thm_cntx.TotalTheme)
            {
                g_thm_cntx.CurrOrderIndex = 0;
            }
            else
            {
                g_thm_cntx.CurrOrderIndex++;
            }

            /* There's no theme to updated */
            if (g_thm_cntx.CurrOrderIndex == start_index && no_of_times != 0)
            {
                MMI_THM_TRACE0(MMI_THEME_UPDATE_NO_THEME);
                *period = ALM_WITHOUD_EXPIRY_PERIOD;
                #ifndef __MMI_DEV_NEW_SLIM__
                 return ALM_HAS_NO_IND;
                #else
                 return MMI_FALSE;
                #endif
            }

            order_theme_id = g_thm_cntx.SetOrderIDList[g_thm_cntx.CurrOrderIndex];

            /* if current order theme is "none" */
            if (order_theme_id != 0)
            {
                break;
            }
        }

        /* Update theme */
        if (!AlmIsRTCPwron())
        {
            MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 3);
            if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
            {
                /* To exit previous screen, error case: multimedia screen will allocate lots of memory, and then the cache wallpaper will fail */
                /* 2006/12/31 */
                EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
                result = mmi_tm_activate_theme(order_theme_id); /* PMT TM Coding Conventions - MOHD SHARIQ 20060406 */

                if (result == THEME_ERROR_SUCCESS)
                {
                    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 4);
                    g_thm_cntx.CurrTheme = order_theme_id;
                    SetThemes((U8)g_thm_cntx.CurrTheme);

					//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);
					mmi_frm_nmgr_popup(
                					MMI_SCENARIO_ID_REMINDER_OTHER, 
                					MMI_EVENT_INFO, 
                					get_string(STR_THEMES_ALARM_ACTIVATION));                    
                    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                }
                else
                {
                	if (result == THEME_ERROR_ALREADY_ACTIVATED)
            		{
            		    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 5);
            			//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);
                        mmi_frm_nmgr_popup(
                                        MMI_SCENARIO_ID_REMINDER_OTHER, 
                                        MMI_EVENT_INFO, 
                                        get_string(STR_THEMES_ALARM_ACTIVATION));
            		}
					else
					{
					    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 6);
						mmi_thm_display_error_msg(result, GRP_ID_ROOT);
					}
                    
                    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                }
            }
        }
        else
        {
            MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 7);
            result = mmi_tm_activate_theme(order_theme_id);

            /* PMT SUKRIT START PMTSW00006364 */
            if (result == THEME_ERROR_SUCCESS)
            {
                MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 8);
                g_thm_cntx.CurrTheme = order_theme_id;
                /* PMT SUKRIT END PMTSW00006364 */
                SetThemes((U8)g_thm_cntx.CurrTheme);
                SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                /* PMT SUKRIT START PMTSW00006364 */
            }
            /* PMT SUKRIT END PMTSW00006364 */
        }

	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671
	#ifdef __J2ME__
		if(IsJavaPlaying == TRUE)
		{
			if(result != THEME_ERROR_SUCCESS)
			{
                MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 9);
                jam_resume_dummy_screen();
			}
		}
	#endif
	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671
	}

    /* Leo add for DLT */
    WriteThemesToNVRAM();
    /* Leo end */
#else /* __MMI_THEMES_V2_SUPPORT__ */ 

    U8 no_of_times;
    U8 order_theme = 0;

	/* check the theme in the orderlist , if all are empty, update the period*/
	if (g_thm_cntx.CurrOrderList[0] == 3 &&
		g_thm_cntx.CurrOrderList[1] == 3 &&
		g_thm_cntx.CurrOrderList[2] == 3 &&
		g_thm_cntx.CurrOrderList[3] == 3)
	{
		AlarmExpireUpdateThemeOff();
	}
	else
	{
	    /* find the next index of theme to be updated */
	    for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
	    {
	        /* move order to next one */
	        if (g_thm_cntx.CurrOrderIndex == NO_OF_ORDERS - 1)
	        {
	            g_thm_cntx.CurrOrderIndex = 0;
	        }
	        else
	        {
	            g_thm_cntx.CurrOrderIndex++;
	        }

	        order_theme = g_thm_cntx.CurrOrderList[g_thm_cntx.CurrOrderIndex];

	        /* if found theme different to current one, found the first one */
	        if (order_theme != g_thm_cntx.CurrTheme && order_theme < g_thm_cntx.TotalTheme)
	        {
	            break;
	        }
	    }
#ifdef __J2ME__
	    if (GetActiveScreenId() == SCR_JAVA_APP)
	    {
	        IsJavaPlaying = TRUE;
        jam_pause_dummy_screen();
	    }
#endif /* __J2ME__ */ 
	    if (no_of_times < NO_OF_ORDERS)
	    {
	        g_thm_cntx.CurrTheme = order_theme;
	        WriteThemesToNVRAM();

	        if (!AlmIsRTCPwron())
	        {
	            if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
	            {
	                SetThemes((U8)g_thm_cntx.CurrTheme);
					//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);					
                    mmi_frm_nmgr_popup(
                                    MMI_SCENARIO_ID_REMINDER_OTHER, 
                                    MMI_EVENT_INFO, 
                                    get_string(STR_THEMES_ALARM_ACTIVATION));
 	            }
	            else if (g_thm_cntx.IsInThmApp == 1)
	            {
					//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);                
                    mmi_frm_nmgr_popup(
                                    MMI_SCENARIO_ID_REMINDER_OTHER, 
                                    MMI_EVENT_INFO, 
                                    get_string(STR_THEMES_ALARM_ACTIVATION));					
 	            }
	            order_theme++;
	        }
	        else
	        {
	            SetThemes((U8)g_thm_cntx.CurrTheme);
	        }
	    }
#ifdef __J2ME__
	    if (IsJavaPlaying == TRUE)
	    {
        jam_resume_dummy_screen();
	    }
#endif /* __J2ME__ */ 
	}
	WriteThemesToNVRAM();
	
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* Leo add for DLT */
    /* WriteThemesToNVRAM(); */
    /* Leo end */
    *period = ALM_WITHOUD_EXPIRY_PERIOD;
    
    srv_reminder_notify_finish(MMI_FALSE);
    ThemesReInitQueueCBH();
    #ifndef __MMI_DEV_NEW_SLIM__
    return ALM_HAS_NO_IND;
    #else
    return MMI_FALSE;
    #endif
}


#ifndef __MMI_THEMES_V2_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ReadThemesFromNVRAM
 * DESCRIPTION
 *  Read theme settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ReadThemesFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
    S16 error = 0;
    U8 index = 0;
    U8 *temp_name;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize global contex */
    MMI_THM_TRACE0(MMI_THEME_ENTRY_READ_FROM_NVRAM);
    memset(&g_thm_cntx, 0, sizeof(g_thm_cntx));
    g_thm_cntx.TotalTheme = (U8) GetThemesNames((U8 ***) & temp_name);

    ReadRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, 8, &error);

    /* to present abonromal case of NVRAM default value */
    if (nvram_theme.freq_type > ALM_FREQ_SEASONALLY)
    {
        g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;
    }
    else
    {
        g_thm_cntx.CurrUpdatePeriod = (U8) (nvram_theme.freq_type);
    }

    g_thm_cntx.CurrTheme = nvram_theme.current_theme_index;

    /* set order list */
    if (nvram_theme.set_order_flag >= -1)    /* order has be set before */
    {
        g_thm_cntx.IsOrderChanged = 1;

        g_thm_cntx.CurrOrderIndex = nvram_theme.set_order_flag;

        for (index = 0; index < NO_OF_ORDERS; index++)
        {
            g_thm_cntx.CurrOrderList[index] = nvram_theme.themes_order[index];
        }
    }
    else
    {
        g_thm_cntx.IsOrderChanged = 0;
        g_thm_cntx.CurrOrderIndex = 0;
        for (index = 0; index < NO_OF_ORDERS; index++)
        {
            g_thm_cntx.CurrOrderList[index] = index;
        }
    }

    /* set and apply current theme */
    if (g_thm_cntx.CurrTheme >= g_thm_cntx.TotalTheme)
    {
        g_thm_cntx.CurrOrderIndex = 0;
        g_thm_cntx.CurrTheme = 0;
    }

    SetThemes((U8)g_thm_cntx.CurrTheme);
    /* Leo end */
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  WriteThemesToNVRAM
 * DESCRIPTION
 *  write theme settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WriteThemesToNVRAM()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S16 error = 0;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_THM_TRACE0(MMI_THEME_ENTRY_WRITE_FROM_NVRAM);
    
    nvram_theme.freq_type = g_thm_cntx.CurrUpdatePeriod;

    if (g_thm_cntx.IsOrderChanged == 1)
#ifdef __MMI_THEMES_V2_SUPPORT__
        nvram_theme.set_order_flag = currorderindex;    /* changes made on saturday 09/04/05 */
#else 
        nvram_theme.set_order_flag = g_thm_cntx.CurrOrderIndex;
#endif 

    if (g_thm_cntx.IsOrderChanged == 0)
    {
        nvram_theme.set_order_flag = -1;
    }

#ifndef __MMI_THEMES_V2_SUPPORT__
    if (g_thm_cntx.CurrTheme < g_thm_cntx.TotalTheme)
    {
        nvram_theme.current_theme_index = (U8) g_thm_cntx.CurrTheme;
    }
    else
    {
        g_thm_cntx.CurrTheme = nvram_theme.current_theme_index = 0;
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_THEMES_V2_SUPPORT__
    for (index = 0; index < TOTAL_THEMES_COUNT; index++)    /* ritesh */
    {
        nvram_theme.themes_order[index] = setorderIDList[index];
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        nvram_theme.themes_order[index] = g_thm_cntx.CurrOrderList[index];
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#if 0
#if (defined(__MMI_THEMES_V2_SUPPORT__) || defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))        /* ritesh */
/* under construction !*/
#else 
/* under construction !*/
/* under construction !*/
#endif 
#else 
    WriteRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, sizeof(thm_nvram_struct), &error);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  UpdateThemeAlarm
 * DESCRIPTION
 *  Call by settings application when time/date change
 *  and set the alam of update theme according to current time/date
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemeAlarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.IsSetFromMenu = 0;

    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF) /* not OFF */
    {
        UpdateThemePeriod();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetStartPositionofCurIndex
 * DESCRIPTION
 *  set the starting position of update order index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetStartPositionofCurIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0, flag = 0;
    U8 curr_order;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
#else 
/* under construction !*/
#endif 
#else 
    if (g_thm_cntx.CurrOrderIndex < 0)
#endif 
        curr_order = 0;
    else
    {
        curr_order = (U8) g_thm_cntx.CurrOrderIndex;
    }

    /* find the position of current selected theme */
#ifdef __MMI_THEMES_V2_SUPPORT__
    for (index = 0; index < g_thm_cntx.TotalTheme; index++) /* ritesh */
    {
        if (g_thm_cntx.SetOrderIDList[curr_order] == g_thm_cntx.CurrTheme)
        {
            flag = 1;
            break;
        }
        if (curr_order == (g_thm_cntx.TotalTheme) - 1)
        {
            curr_order = 0;
        }
        else
        {
            curr_order++;
        }
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        if (g_thm_cntx.CurrOrderList[curr_order] == g_thm_cntx.CurrTheme)
        {
            flag = 1;
            break;
        }

        if (curr_order == (NO_OF_ORDERS) - 1)
        {
            curr_order = 0;
        }
        else
        {
            curr_order++;
        }
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (flag == 1)  /* it's in the list */
    {
        g_thm_cntx.CurrOrderIndex = curr_order;
        g_thm_cntx.IsOrderChanged = 1;
    }
    else
    {
        g_thm_cntx.CurrOrderIndex = -1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ATSetTheme
 * DESCRIPTION
 *  To change theme setting from AT command
 * PARAMETERS
 *  index       [IN]        Index of theme to be set
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHNSET_AT_DISABLE__
BOOL ATSetTheme(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* added by ritesh for V2 support */
#ifdef __MMI_THEMES_V2_SUPPORT__
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.IsInThmApp == 0)
    {
        mmi_tm_get_themes(&thm_details);
        result = mmi_tm_activate_theme(thm_details[index].theme_id);    /* PMT TM Coding Conventions - MOHD SHARIQ 20060406 */
        SetThemes((U8)g_thm_cntx.CurrTheme);

        if (result == THEME_ERROR_SUCCESS)
        {
            g_thm_cntx.CurrTheme = thm_details[index].theme_id;
            if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
            {
                SetStartPositionofCurIndex();
            }
            SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
        }
        mmi_thm_display_error_msg(result, GRP_ID_ROOT);
        DeleteUptoScrID(SCR_ID_THM_MENU);

        if ((result == THEME_ERROR_SUCCESS) || (result == THEME_ERROR_ALREADY_ACTIVATED))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* index exceeds boundary or theme is not changed */
    if (index >= g_thm_cntx.TotalTheme || index == g_thm_cntx.CurrTheme)
    {
        return MMI_FALSE;
    }

    g_thm_cntx.CurrTheme = index;

    /* reset postion index of update period */
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        SetStartPositionofCurIndex();
    }

    /* write change to NVRAM */
    WriteThemesToNVRAM();

    /* change theme */
    if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
    {
        SetBothLCDThemes(index);
        /* MTK Leo add, fix theme update issue */
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        GoBackHistory();
    }
    else if (g_thm_cntx.IsInThmApp == 1)
    {
        /* SetExitHandler(SCR_ID_THM_MENU, NULL); */
        ClearExitHandler();
        mmi_theme_entry_int();
    }

    return MMI_TRUE;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}
#endif
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OTG_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OTG_ENABLE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OTG_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OTG_ENABLE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif	/* MMI_MAX_SIM_NUM */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
        #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_THEMES_V2_SUPPORT__ */
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#ifdef __MMI_TOUCH_SCREEN__
#if 0
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_tap_list_callback
 * DESCRIPTION
 *  tap on theme list, activate it.
 * PARAMETERS
 *  mmi_tap_type_enum   [IN] tap type.
 *  S32                 [IN] item index.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_tap_list_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        // only change the highlight
        return;
    } 
    ActivateTheme();
}
#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* __MMI_THEMES_APPLICATION__ */

