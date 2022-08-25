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
 *  SmsAppSetting.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Setting 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "smsal_l4c_enum.h"
#include "GlobalResDef.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
#include "wgui_touch_screen.h"
#endif
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "gui_fixed_menuitems.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stdio.h"
#include "wgui_categories_text_viewer.h"
#include "ps_public_enum.h"
#include "csmcc_enums.h"
#include "MessagesMiscell.h"
#include "custom_mmi_default_value.h"

#include "SmsAppSetting.h"
#include "wgui_inline_edit.h"
#include "CommonScreens.h"
#include "SmsAppProt.h"
#include "SmsSrvGprot.h"
#include "SmsGuiInterfaceType.h"
#include "PhbSrvGprot.h"
#include "CphsSrvGprot.h"
#include "Voicemail.h"
#include "InlineCuiGprot.h"
#include "MenucuiGprot.h"
#include "mmi_rp_app_sms_def.h"
#include "Phbsrvgprot.h"
#if (MMI_MAX_SIM_NUM >= 1)
#include "SimCtrlSrvGProt.h"
#endif
#include "smsAppUtil.h"
#include "mmi_frm_utility_gprot.h"
#include "smsAppProt.h"
#if defined( __SMS_CLOUD_SUPPORT__)
#include "SsoCuiGprot.h"
#include "SsoSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "Mmi_rp_srv_sns_def.h"
#include "mmi_rp_app_sso_def.h" /* sso app gen about yahoo service */
#include "NwUsabSrvGprot.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

/**************************************************************
* Global Variables Declaration
**************************************************************/
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];

/**************************************************************
* Global Function Declaration
**************************************************************/

/**************************************************************
* Static Variables Defination
**************************************************************/
#define MMI_SMS_COMM_SET_ITEM_NUM        3
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#define MMI_SMS_SET_MAX_NAME_LEN        (30+MMI_NETSET_SIM_NAME_MAX_LEN)
#endif

#ifdef __SMS_OVER_PS_SUPPORT__
typedef enum
{
    MMI_SMS_CON_PREFER_GPRS,
    MMI_SMS_CON_PREFER_GSM,
    MMI_SMS_CON_GSM_ONLY
} mmi_sms_connection_enum;
#endif /* defined(__SMS_OVER_PS_SUPPORT__) */ 

/* Total Profiles' detail informaiton structure */
typedef struct
{
    MMI_ID main_set_gid;
    MMI_ID sim_set_gid;

    srv_sms_sim_enum sim_id;
    mmi_sim_enum mmi_sim;

    U8 vp_index;           /* Validity period index */
    U8 pid_index;     /* Message protocol identifier index */
    U8 status_report;
    U8 reply_path;
#ifdef __SMS_OVER_PS_SUPPORT__
    U8 connection;
#endif

    U8 save_sent;
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__)
    U8 pre_storage;
#endif
#ifdef __EMS_NON_STD_7BIT_CHAR__
    U8 ns7char;
#endif
#ifdef __EMS_DYNAMIC_SEG_NUM__
    U8 longsms;
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_filter_enum sms_filter;
#endif

#ifdef __MMI_SMS_SLIM__
    CHAR sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];                           /* Sc address */
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    CHAR email_addr[SRV_SMS_MAX_ADDR_LEN + 1];          /* Email sc address */
#endif
#else
    U8 cur_hilite_index;
    U8 active_profile_no;  /* Current request to get profile index information */
    U8 profile_count; /* Total profiles number */
    U8 profile_name_len;    /* Maximum profile name length */
    U16 profile_name[SRV_SMS_MAX_LFOUR_PROFILES][SRV_SMS_MAX_PROFILE_NAME_LEN + 1]; /* Profiles' name */
    MMI_ID edit_pf_gid;
    srv_sms_profile_ext_struct *editInfo;
#endif
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    WCHAR* sim_name;
#endif
} srv_sms_main_set_struct;

typedef enum
{
    MMI_SMS_INLINE_ITEM_SIM1 = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_SMS_INLINE_ITEM_SIM2,
    MMI_SMS_INLINE_ITEM_SIM3,
    MMI_SMS_INLINE_ITEM_SIM4,
    MMI_SMS_INLINE_ITEM_MEM_STATUS,
    MMI_SMS_INLINE_ITEM_SMS_COUNTER,
    MMI_SMS_INLINE_ITEM_SAVE_SENT_1,
    MMI_SMS_INLINE_ITEM_SAVE_SENT_2,
    MMI_SMS_INLINE_ITEM_PRE_MEM_1,
    MMI_SMS_INLINE_ITEM_PRE_MEM_2,
    MMI_SMS_INLINE_ITEM_FILTER,
    MMI_SMS_INLINE_ITEM_7BIT_1,
    MMI_SMS_INLINE_ITEM_7BIT_2,
    MMI_SMS_INLINE_ITEM_LONG_SMS_1,
    MMI_SMS_INLINE_ITEM_LONG_SMS_2,
    
    MMI_SMS_INLINE_ITEM_BACKUP,
    MMI_SMS_INLINE_ITEM_RESTORE,
    MMI_SMS_INLINE_ITEM_MAIN_TOTAL
} mmi_sms_main_set_item_enum;

typedef enum
{
    MMI_SMS_INLINE_ITEM_SMSC_1 = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_SMS_INLINE_ITEM_SMSC_2,
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
	MMI_SMS_INLINE_ITEM_PRE_STOR_1,
	MMI_SMS_INLINE_ITEM_PRE_STOR_2,
#endif
    MMI_SMS_INLINE_ITEM_VP_1,
    MMI_SMS_INLINE_ITEM_VP_2,
    MMI_SMS_INLINE_ITEM_PID_1,
    MMI_SMS_INLINE_ITEM_PID_2,
    MMI_SMS_INLINE_ITEM_DELIVER_1,
    MMI_SMS_INLINE_ITEM_DELIVER_2,
    MMI_SMS_INLINE_ITEM_REPLY_PATH_1,
    MMI_SMS_INLINE_ITEM_REPLY_PATH_2,
    MMI_SMS_INLINE_ITEM_CONNECTION_1,
    MMI_SMS_INLINE_ITEM_CONNECTION_2,
    MMI_SMS_INLINE_ITEM_EMAIL_SC_1,
    MMI_SMS_INLINE_ITEM_EMAIL_SC_2,
    MMI_SMS_INLINE_ITEM_VM_SERVER,
    MMI_SMS_INLINE_ITEM_SIM_TOTAL
} mmi_sms_sim_set_item_enum;
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__

static const U8 vp_enum[] = 
{
    SRV_SMS_VP_1_HR,
    SRV_SMS_VP_6_HR,
    SRV_SMS_VP_12_HR,
    SRV_SMS_VP_24_HR,
    SRV_SMS_VP_72_HR,
    SRV_SMS_VP_1_WEEK,
    SRV_SMS_VP_MAX
};
#endif
#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
static const U8 pid_enum[] = 
{
    SMSAL_DEFAULT_PID,
    SMSAL_G3_FAX_PID,
    SMSAL_G4_FAX_PID,
    SMSAL_PAGING_PID,
    SMSAL_EMAIL_PID
};

#endif

static cui_inline_item_display_only_struct sim_name[MMI_SIM_TOTAL] = 
{
#if (MMI_MAX_SIM_NUM == 1)
    {STR_GLOBAL_SIM, 0}
#else
    {STR_GLOBAL_SIM_1, 0}
    ,{STR_GLOBAL_SIM_2, 0}
#if (MMI_MAX_SIM_NUM >= 3)
    ,{STR_GLOBAL_SIM_3, 0}
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    ,{STR_GLOBAL_SIM_4, 0}
#endif
#endif
};

#if defined( __SMS_CLOUD_SUPPORT__)
static cui_inline_item_display_only_struct back_restore[] = 
{
    {STR_ID_SMS_BACKUP, 0},
    {STR_ID_SMS_RESTORE, 0}
};
#endif /* __SMS_CLOUD_SUPPORT__ */

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
static cui_inline_item_display_only_struct memstatus_name = 
{
    STR_GLOBAL_MEMORY_STATUS, 0
};
#endif

#ifdef __MMI_SMS_COUNTER__
static cui_inline_item_display_only_struct counter_name = 
{
    STR_ID_SMS_COUNTER, 0
};
#endif

static cui_inline_item_caption_struct savesent_name = 
{
    STR_ID_SMS_SAVE_SENT_SMS
};

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__)
static cui_inline_item_caption_struct premem_name = 
{
    STR_GLOBAL_PREFERRED_STORAGE
};
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
static cui_inline_item_caption_struct filter_name = 
{
    STR_ID_SMS_FILTER,
};
#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
static cui_inline_item_caption_struct ns7char_name = 
{
    STR_ID_SMS_SETUP_CHARACTER_MENUENTRY
};
#endif

#ifdef __EMS_DYNAMIC_SEG_NUM__
static cui_inline_item_caption_struct longsms_name = 
{
    STR_ID_SMS_SETUP_LONG_SMS_MENUENTRY
};
#endif

static const cui_inline_set_item_struct main_set_items[] = 
{
    {MMI_SMS_INLINE_ITEM_SIM1, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &sim_name[0]},
#if (MMI_MAX_SIM_NUM >= 2)
    {MMI_SMS_INLINE_ITEM_SIM2, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &sim_name[1]},
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    {MMI_SMS_INLINE_ITEM_SIM3, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &sim_name[2]},
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    {MMI_SMS_INLINE_ITEM_SIM4, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &sim_name[3]},
#endif

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
    {MMI_SMS_INLINE_ITEM_MEM_STATUS, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &memstatus_name},
#endif

#ifdef __MMI_SMS_COUNTER__
    {MMI_SMS_INLINE_ITEM_SMS_COUNTER, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &counter_name},
#endif

    {MMI_SMS_INLINE_ITEM_SAVE_SENT_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &savesent_name},
    {MMI_SMS_INLINE_ITEM_SAVE_SENT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
    {MMI_SMS_INLINE_ITEM_PRE_MEM_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &premem_name},
    {MMI_SMS_INLINE_ITEM_PRE_MEM_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    {MMI_SMS_INLINE_ITEM_FILTER, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &filter_name},
#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
    {MMI_SMS_INLINE_ITEM_7BIT_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &ns7char_name},
    {MMI_SMS_INLINE_ITEM_7BIT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif

#ifdef __EMS_DYNAMIC_SEG_NUM__
    {MMI_SMS_INLINE_ITEM_LONG_SMS_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &longsms_name},
    {MMI_SMS_INLINE_ITEM_LONG_SMS_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif
#if defined( __SMS_CLOUD_SUPPORT__ )
    {MMI_SMS_INLINE_ITEM_BACKUP, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &(back_restore[0])},
    {MMI_SMS_INLINE_ITEM_RESTORE, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &(back_restore[1])},
#endif /* __SMS_CLOUD_SUPPORT__ */
};

#ifdef __MMI_SMS_SLIM__
static cui_inline_item_caption_struct smsc_name = 
{
    STR_ID_SMS_PROFILE_SC
};

static const cui_inline_item_text_edit_struct smsc_data = 
{
    0,
    STR_ID_SMS_PROFILE_SC,
    SRV_SMS_MAX_ADDR_LEN,
    IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
    0,
    NULL
};
#else
static cui_inline_item_display_only_struct smsc_name = 
{
    STR_ID_SMS_PROFILE_SETTING_MENUENTRY, 0
};
#endif

     
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
static cui_inline_item_caption_struct vp_name = 
{
    STR_ID_SMS_PROFILE_VP
};
#endif

#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
static cui_inline_item_caption_struct pid_name = 
{
    STR_ID_SMS_PROFILE_MSG_TYPE
};
#endif

static cui_inline_item_caption_struct deliver_name = 
{
    STR_SR_DELIVERD_ID
};

static cui_inline_item_caption_struct reply_name = 
{
    STR_ID_SMS_REPLY_PATH_MENUENTRY
};

#ifdef __SMS_OVER_PS_SUPPORT__
static cui_inline_item_caption_struct bearer_name = 
{
    STR_ID_SMS_PREFERED_BEARER_MENUENTRY
};
#endif

#ifdef __MMI_MESSAGES_SMS_EMAIL__
#ifdef __MMI_SMS_SLIM__
static cui_inline_item_caption_struct emailsc_name = 
{
    STR_ID_SMS_EMAIL_SC
};
static const cui_inline_item_text_edit_struct emailsc_data = 
{
    0,
    STR_ID_SMS_EMAIL_SC,
    SRV_SMS_MAX_ADDR_LEN,
    IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
    0,
    NULL
};
#endif
#endif

static cui_inline_item_display_only_struct vm_name = 
{
    STR_ID_SMS_VM_VMAIL_MENUENTRY, 0
};

static const cui_inline_set_item_struct sim_set_items[] = 
{
#ifdef __MMI_SMS_SLIM__
    {MMI_SMS_INLINE_ITEM_SMSC_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_SC, &smsc_name},
    {MMI_SMS_INLINE_ITEM_SMSC_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &smsc_data},
#else
    {MMI_SMS_INLINE_ITEM_SMSC_1, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &smsc_name},
#endif
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
    {MMI_SMS_INLINE_ITEM_PRE_STOR_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &premem_name},
    {MMI_SMS_INLINE_ITEM_PRE_STOR_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
    {MMI_SMS_INLINE_ITEM_VP_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_VP, &vp_name},
    {MMI_SMS_INLINE_ITEM_VP_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif
#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
    {MMI_SMS_INLINE_ITEM_PID_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_MSG_TYPE, &pid_name},
    {MMI_SMS_INLINE_ITEM_PID_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif
    {MMI_SMS_INLINE_ITEM_DELIVER_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &deliver_name},
    {MMI_SMS_INLINE_ITEM_DELIVER_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
    {MMI_SMS_INLINE_ITEM_REPLY_PATH_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &reply_name},
    {MMI_SMS_INLINE_ITEM_REPLY_PATH_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#ifdef __SMS_OVER_PS_SUPPORT__
    {MMI_SMS_INLINE_ITEM_CONNECTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_MSG_SETTINGS_MENUENTRY, &bearer_name},
    {MMI_SMS_INLINE_ITEM_CONNECTION_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif
#ifdef __MMI_MESSAGES_SMS_EMAIL__
#ifdef __MMI_SMS_SLIM__
    {MMI_SMS_INLINE_ITEM_EMAIL_SC_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_SC, &emailsc_name},
    {MMI_SMS_INLINE_ITEM_EMAIL_SC_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, NULL},
#endif
#endif
    {MMI_SMS_INLINE_ITEM_VM_SERVER, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_SMS_VMAIL_MENUENTRY, &vm_name}
};

#ifndef __MMI_SMS_SLIM__
typedef enum
{
    MMI_SMS_INLINE_PF_NAME_1 = CUI_INLINE_ITEM_ID_BASE + 0,
    MMI_SMS_INLINE_PF_NAME_2,
    MMI_SMS_INLINE_PF_SC_1,
    MMI_SMS_INLINE_PF_SC_2,
    MMI_SMS_INLINE_PF_EMAILSC_1,
    MMI_SMS_INLINE_PF_EMAILSC_2,
    MMI_SMS_INLINE_PF_TOTAL
} mmi_sms_profile_item_enum;

static cui_inline_item_caption_struct pf_name = 
{
    STR_ID_SMS_PROFILE_NAME
};

static const cui_inline_item_text_edit_struct pf_data = 
{
    0,
    0,
    SRV_SMS_MAX_PROFILE_NAME_LEN + 1,
    INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_GSM_EXTENDED_HANDLING,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    NULL
};

static cui_inline_item_caption_struct pf_sc_name = 
{
    STR_ID_SMS_PROFILE_SC
};

static const cui_inline_item_text_edit_struct pf_sc_data = 
{
    0,
    0,
    SRV_SMS_MAX_ADDR_LEN,
    IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
    0,
    NULL
};

#ifdef __MMI_MESSAGES_SMS_EMAIL__
static cui_inline_item_caption_struct pf_emailsc_name = 
{
    STR_ID_SMS_EMAIL_SC
};

static const cui_inline_item_text_edit_struct pf_emailsc_data = 
{
    0,
    0,
    SRV_SMS_MAX_ADDR_LEN,
    IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
    0,
    NULL
};
#endif

static const U16 defaultProfileNames[MAX_LFOUR_PROFILES] = 
{
    STR_ID_SMS_SET0_MENUENTRY,
    STR_ID_SMS_SET1_MENUENTRY,
    STR_ID_SMS_SET2_MENUENTRY,
    STR_ID_SMS_SET3_MENUENTRY
};

static const cui_inline_set_item_struct edit_pf_items[] = 
{
    {MMI_SMS_INLINE_PF_NAME_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_NAME, &pf_name},
    {MMI_SMS_INLINE_PF_NAME_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &pf_data},
    {MMI_SMS_INLINE_PF_SC_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_SC, &pf_sc_name},
    {MMI_SMS_INLINE_PF_SC_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &pf_sc_data},
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    {MMI_SMS_INLINE_PF_EMAILSC_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_SMS_PROFILE_SC, &pf_emailsc_name},
    {MMI_SMS_INLINE_PF_EMAILSC_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &pf_emailsc_data}
#endif
};
#endif

#if(MMI_MAX_SIM_NUM >= 2)
static const U16 sms_sim_str_id[] = 
{
     STR_GLOBAL_SIM_1
    ,STR_GLOBAL_SIM_2
#if (MMI_MAX_SIM_NUM >= 3)
    ,STR_GLOBAL_SIM_3
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    ,STR_GLOBAL_SIM_4
#endif
};
#endif


static MMI_ID mmi_sms_setting_gid = GRP_ID_INVALID;
static srv_sms_main_set_struct *sms_set_user_data;


#if defined( __SMS_CLOUD_SUPPORT__ )
typedef enum
{
    MMI_SMS_BACKUP_RESTORE_ACTION_NONE,
        
    MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP,
    MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE,
    
    MMI_SMS_BACKUP_RESTORE_ACTION_MAX
}mmi_sms_backup_restore_action_type_enum;

typedef struct
{
    MMI_ID group;
    mmi_sms_backup_restore_action_type_enum action;
    S32 highlight_index;
    SMS_HANDLE handler;
    S32 provider_count;
    U32 *provider_ids;
    S32 finish_count;
    S32 total_count;
	MMI_BOOL processing_ongoing;
}mmi_sms_backup_restore_cntx;

static mmi_sms_backup_restore_cntx *s_backup_restore_cntx;
static void mmi_sms_msg_backup_start(void);
static void mmi_sms_msg_restore_start(void);

#endif

/**************************************************************
* Extern Function Declaration
**************************************************************/
extern U8 mmi_msg_check_interrupt(void);


/**************************************************************
* Static Function Declaration
**************************************************************/
static void mmi_sms_set_save_result(MMI_BOOL result, MMI_ID close_gid);

#ifdef __SMS_OVER_PS_SUPPORT__
static void mmi_sms_get_bearer_service_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_set_bearer_service_rsp(srv_sms_callback_struct* callback_data);
#endif /* defined(__SMS_OVER_PS_SUPPORT__) */
static void mmi_sms_set_common_settings_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_sim_set_save_req(void);
static void mmi_sms_sim_set_save_rsp(srv_sms_callback_struct* callback_data);
#ifndef __MMI_SMS_SLIM__
static void mmi_sms_get_profile_number_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_set_profile_inline_item_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_set_profile_inline_item_req(void);
static void mmi_sms_edit_profile_submit_hdlr(cui_event_inline_submit_struct *evt);
static void mmi_sms_entry_profile_edit(void);
static void mmi_sms_get_profile_inline_item_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_get_profile_inline_item_req(void);
static void mmi_sms_set_profile_active_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_set_profile_active_req(void);
static void mmi_sms_profile_options_select_hdlr(mmi_menu_id highlighted_menu_id);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_sms_fte_profile_setting_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
static void mmi_sms_entry_profile_settings_option(void);
static void mmi_sms_get_profile_highlight_index(S32 nIndex);
static void mmi_sms_entry_profile_settings(void);
static void mmi_sms_get_profile_list_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_pre_entry_sc_list(void);
#endif /* __MMI_SMS_SLIM__ */
static void mmi_sms_entry_vm_server(void);
static void mmi_sms_sim_set_highlight_hdlr(cui_event_inline_notify_struct *evt);
static void mmi_sms_sim_set_submit_hdlr(cui_event_inline_submit_struct *evt);
static void mmi_sms_sim_set_entry(void);
static void mmi_sms_sim_set_pre_entry(void);
static void mmi_sms_main_setting_entry(void);
static void mmi_sms_main_set_submit_hdlr(cui_event_inline_submit_struct *evt);
static void mmi_sms_main_set_highlight_hdlr(cui_event_inline_notify_struct *evt);
#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
static void mmi_sms_entry_memory_status(void);
#endif
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
static void mmi_sms_entry_msg_filter(void);
#endif

#ifdef __MMI_SMS_COUNTER__
static void mmi_sms_entry_msg_counter(void);
#endif
static mmi_ret mmi_sms_msg_setting_group_proc(mmi_event_struct *evt);
static MMI_BOOL mmi_sms_setting_check_group_valid(void);
#if defined( __SMS_CLOUD_SUPPORT__ )
static U8 mmi_sms_account_nw_available(void);
#endif
/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  DialVoiceMail
 * DESCRIPTION
 *  Dial voice mail server number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_save_result(MMI_BOOL result, MMI_ID close_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID title = STR_GLOBAL_UNFINISHED;
    mmi_event_notify_enum event_id = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        title = STR_GLOBAL_SAVED;
        event_id = MMI_EVENT_EXPLICITLY_SAVED;
    }

    mmi_sms_display_popup_ext(
        title,
        event_id);

    if (GRP_ID_INVALID != close_gid)
    {
        mmi_frm_group_close(close_gid);
    }
}


#ifdef __SMS_OVER_PS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_bearer_service_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearer      [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_bearer_service_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (!mmi_sms_setting_check_group_valid())
    {
        return;
    }

    if (callback_data->result == MMI_TRUE)
    {
        sms_set_user_data->connection = (mmi_sms_connection_enum) (*(U8*)callback_data->action_data);

        mmi_sms_sim_set_entry();
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_MESSAGES_UNKNOWN_ERROR,
            MMI_EVENT_FAILURE);
    }

	mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_bearer_service_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_bearer_service_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROCESSING);

	if (callback_data->result == MMI_FALSE)
	{
		mmi_sms_display_popup_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
	}
	mmi_frm_group_close(sms_set_user_data->sim_set_gid);

    sms_set_user_data->sim_set_gid = GRP_ID_INVALID;
}
#endif /* defined(__SMS_OVER_PS_SUPPORT__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_common_settings_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_common_settings_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_OVER_PS_SUPPORT__
    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_set_setting_para(SRV_SMS_PRE_BEARER, 
                     (void *)&sms_set_user_data->connection, 
                     sms_set_user_data->sim_id, 
                     mmi_sms_set_bearer_service_rsp, 
                     NULL);
    }
    else
#endif
    {
		mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROCESSING);

		if (callback_data->result == MMI_FALSE)
		{
			mmi_sms_display_popup_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
		}
		mmi_frm_group_close(sms_set_user_data->sim_set_gid);

        sms_set_user_data->sim_set_gid = GRP_ID_INVALID;
    }
}


#ifdef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_setting_get_profile_data_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_sms_setting_get_profile_data_id(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
    #if  (MMI_MAX_SIM_NUM >= 2)
        case SRV_SMS_SIM_2:
            item_id = NVRAM_SIM2_ACTIVE_PROFILE_IDX;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_SMS_SIM_3:
            item_id = NVRAM_SIM3_ACTIVE_PROFILE_IDX;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_SMS_SIM_4:
            item_id = NVRAM_SIM4_ACTIVE_PROFILE_IDX;
            break;
    #endif

        case SRV_SMS_SIM_1:
        default:
            item_id = NVRAM_SMS_ACTIVE_PROFILE_INDEX;
            break;
    }

    return item_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_set_save_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profiledetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_save_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback_data->result == MMI_TRUE)
    {
        U8 CommonSettingItem[MMI_SMS_COMM_SET_ITEM_NUM];

        CommonSettingItem[0] = sms_set_user_data->status_report;
        CommonSettingItem[1] = sms_set_user_data->reply_path;

        srv_sms_set_setting_para(
            SRV_SMS_COMMON_SETTINGS, 
            (void *)CommonSettingItem, 
            sms_set_user_data->sim_id, 
            mmi_sms_set_common_settings_rsp, 
            NULL);
    }
    else
    {
        mmi_sms_set_save_result(MMI_FALSE, sms_set_user_data->sim_set_gid);
        sms_set_user_data->sim_set_gid = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_profile_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_save_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scAddress;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U8 *emailScAddress;
#endif
    srv_sms_profile_ext_struct profile_info;
    //S16 error_code = 0;
    U16 data_item_id;
    srv_sms_sim_enum sim_id = sms_set_user_data->sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scAddress = (U8*)(sms_set_user_data->sc_addr);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    emailScAddress = (U8*)sms_set_user_data->email_addr;
#endif

    if (scAddress[0] == '\0'
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        || ((sms_set_user_data.pid_index == 4) && (sms_set_user_data->email_addr[0] == '\0'))
    #endif
        )
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
            mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROCESSING);
            return;
    }

    else if (!srv_sms_check_sc_number(scAddress, (U8)strlen(sms_set_user_data->sc_addr))
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        || (emailScAddress[0] && (!srv_sms_check_sc_number(emailScAddress, (U8)strlen(sms_set_user_data->email_addr))))
    #endif
        )
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_INVALID_NUMBER,
            MMI_EVENT_FAILURE);
            mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROCESSING);
            return;
    }
    else
    {
        if ((sms_set_user_data->vp_index < MAX_LFOUR_VP) && (sms_set_user_data->pid_index < MAX_LFOUR_MSG_TYPE))
        {
            #ifndef __MMI_SMS_SETTINGS_VP_SLIM__
            profile_info.vp_index = vp_enum[sms_set_user_data->vp_index];
            #else
            profile_info.vp_index = SRV_SMS_VP_MAX;
            #endif
            #ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__   
            profile_info.msg_type_index = pid_enum[sms_set_user_data->pid_index];
            #else
            profile_info.msg_type_index = SMSAL_DEFAULT_PID;
            #endif  
        }
        else
        {
            MMI_ASSERT(0);
        }
        memcpy(profile_info.sc_addr, sms_set_user_data->sc_addr, SRV_SMS_MAX_ADDR_LEN + 1);
        profile_info.para = SRV_SMS_PROFILE_SCA |SRV_SMS_PROFILE_VP | SRV_SMS_PROFILE_PID;

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        memcpy(profile_info.email_addr, sms_set_user_data->email_addr, SRV_SMS_MAX_ADDR_LEN + 1);
        profile_info.para |= SRV_SMS_PROFILE_EMAILSC;
    #endif

        data_item_id = mmi_sms_setting_get_profile_data_id(sim_id);
        //ReadValue(data_item_id, &profile_info.profile_index, DS_BYTE, &error_code);
        ReadValueSlim(data_item_id, &profile_info.profile_index, DS_BYTE);

        srv_sms_set_setting_para(SRV_SMS_PROFILE_DETAIL_PARTIAL, 
                                 (void *)&profile_info, 
                                 sim_id, 
                                 mmi_sms_sim_set_save_rsp, 
                                 NULL);
    }
}

#else

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_set_save_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profiledetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_save_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_setting_gid != GRP_ID_INVALID)
    {
        if (callback_data->result == MMI_TRUE)
        {
            if (sms_set_user_data->cur_hilite_index < sms_set_user_data->profile_count)
            {
                mmi_sms_sim_set_save_req();
            }
            else
            {
                U8 CommonSettingItem[MMI_SMS_COMM_SET_ITEM_NUM];

                CommonSettingItem[0] = sms_set_user_data->status_report;
                CommonSettingItem[1] = sms_set_user_data->reply_path;

                srv_sms_set_setting_para(
                    SRV_SMS_COMMON_SETTINGS, 
                    (void *)CommonSettingItem, 
                    sms_set_user_data->sim_id, 
                    mmi_sms_set_common_settings_rsp, 
                    NULL);
            }
        }
        else
        {
            mmi_sms_set_save_result(MMI_FALSE, sms_set_user_data->sim_set_gid);
            sms_set_user_data->sim_set_gid = GRP_ID_INVALID;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_profile_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_save_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_ext_struct profile_info;
    srv_sms_sim_enum sim_id = sms_set_user_data->sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((sms_set_user_data->vp_index < MAX_LFOUR_VP) && (sms_set_user_data->pid_index < MAX_LFOUR_MSG_TYPE))
    {
        #ifndef __MMI_SMS_SETTINGS_VP_SLIM__     
        profile_info.vp_index = vp_enum[sms_set_user_data->vp_index];
        #else       
        profile_info.vp_index = SRV_SMS_VP_MAX;
        #endif
        #ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__   
        profile_info.msg_type_index = pid_enum[sms_set_user_data->pid_index];
        #else
         profile_info.msg_type_index = SMSAL_DEFAULT_PID;
         #endif  
        profile_info.para = SRV_SMS_PROFILE_VP | SRV_SMS_PROFILE_PID;
    }
    else
    {
        MMI_ASSERT(0);
    }

    profile_info.profile_index = sms_set_user_data->cur_hilite_index;
    sms_set_user_data->cur_hilite_index++;

    srv_sms_set_setting_para(SRV_SMS_PROFILE_DETAIL_PARTIAL, 
                             (void *)&profile_info, 
                             sim_id, 
                             mmi_sms_sim_set_save_rsp, 
                             NULL);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_profile_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profilelist     [?]         
 *  mod             [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_profile_number_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_sms_setting_check_group_valid())
    {
        if (callback_data->result == MMI_TRUE)
        {
            srv_sms_profile_list_struct *psProfileNameList = (srv_sms_profile_list_struct*)callback_data->action_data;

            sms_set_user_data->profile_count = psProfileNameList->cur_max_ps_profiles;
            sms_set_user_data->cur_hilite_index = 0;

            mmi_sms_sim_set_save_req();
        }
        else
        {
            mmi_sms_display_popup_ext(
                STR_GLOBAL_UNFINISHED, 
                MMI_EVENT_FAILURE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_profile_inline_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profiledetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_profile_inline_item_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = callback_data->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROCESSING);

    if (mmi_sms_setting_gid != GRP_ID_INVALID)
    {
        if (result == MMI_TRUE)
        {
            mmi_ucs2ncpy(
                (CHAR*) sms_set_user_data->profile_name[sms_set_user_data->cur_hilite_index],
                (CHAR*) sms_set_user_data->editInfo->profile_name,
                SRV_SMS_MAX_PROFILE_NAME_LEN);
        }
		else
		{
        	mmi_sms_set_save_result(MMI_FALSE, GRP_ID_INVALID);
		}

        cui_inline_close(sms_set_user_data->edit_pf_gid);
        sms_set_user_data->edit_pf_gid = GRP_ID_INVALID;
        OslMfree(sms_set_user_data->editInfo);
        sms_set_user_data->editInfo = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_profile_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_profile_inline_item_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *scAddress;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U8 *emailScAddress;
#endif
    srv_sms_profile_ext_struct *editInfo = sms_set_user_data->editInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    scAddress = editInfo->sc_addr;
    editInfo->para = SRV_SMS_PROFILE_SCA | SRV_SMS_PROFILE_NAME;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    emailScAddress = editInfo->email_addr;
    editInfo->para |= SRV_SMS_PROFILE_EMAILSC;
#endif

    if ((scAddress[0] == '\0')
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        || ((editInfo->msg_type_index == 4) && (emailScAddress[0] == '\0'))
    #endif
        )
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NO_NUMBER,
            MMI_EVENT_FAILURE);
    }
    else if (!srv_sms_check_sc_number(scAddress, (U8)strlen((CHAR*)scAddress))
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        || (emailScAddress[0] && (!srv_sms_check_sc_number(emailScAddress, (U8)strlen((CHAR*)emailScAddress))))
    #endif
        )
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_INVALID_NUMBER,
            MMI_EVENT_FAILURE);
    }
    else
    {
		mmi_sms_set_and_entry_processing_sg(mmi_sms_setting_gid, STR_GLOBAL_PLEASE_WAIT, 0);
        
        srv_sms_set_setting_para(SRV_SMS_PROFILE_DETAIL_PARTIAL, 
                                 (void *)editInfo, 
                                 sms_set_user_data->sim_id, 
                                 mmi_sms_set_profile_inline_item_rsp, 
                                 NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_edit_profile_inline_submit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_edit_profile_submit_hdlr(cui_event_inline_submit_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_ext_struct *editInfo = sms_set_user_data->editInfo;
    MMI_ID inline_gid = evt->sender_id;
    U16 addr_len;
    U16 sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];                           /* Sc address */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
       inline_gid,
       MMI_SMS_INLINE_PF_NAME_2,
       editInfo->profile_name);

    if (srv_phb_check_ucs2_character((U16*) editInfo->profile_name))
    {
        editInfo->profile_name_dcs= PHB_UCS2;
    }
    else
    {
        editInfo->profile_name_dcs = PHB_ASCII;
    }

    cui_inline_get_value(
       inline_gid,
       MMI_SMS_INLINE_PF_SC_2,
       sc_addr);

    addr_len = mmi_ucs2_n_to_asc((CHAR*)editInfo->sc_addr, (CHAR*)sc_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
    editInfo->sc_addr[addr_len] = '\0';

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_SM_MO_EMAIL, sms_set_user_data->mmi_sim))
    {
        cui_inline_get_value(
           inline_gid,
           MMI_SMS_INLINE_PF_EMAILSC_2,
           sc_addr);
        addr_len = mmi_ucs2_n_to_asc((CHAR*)editInfo->email_addr, (CHAR*)sc_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
        editInfo->email_addr[addr_len] = '\0';
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    mmi_sms_set_profile_inline_item_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_profile_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_ext_struct *editInfo;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    MMI_BOOL email_valid;
#endif
    MMI_ID edit_pf_gid;
    cui_inline_struct inline_data;
    U16 sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editInfo = sms_set_user_data->editInfo;
    
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    email_valid = srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_PROTOLCOL_ID, sms_set_user_data->mmi_sim);

    if (email_valid)
    {
        inline_data.items_count = 6;
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    {
        inline_data.items_count = 4;
    }

    inline_data.title = STR_ID_SMS_EDIT_PROFILE;
    inline_data.title_icon = IMG_SMS_ENTRY_SCRN_CAPTION;
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_data.softkey = NULL;
    inline_data.items = edit_pf_items;

    edit_pf_gid = cui_inline_create(mmi_sms_setting_gid, &inline_data);

    if (edit_pf_gid != GRP_ID_INVALID)
    {
        sms_set_user_data->edit_pf_gid = edit_pf_gid;

        if (sms_set_user_data->profile_name_len < SRV_SMS_MAX_PROFILE_NAME_LEN)
        {
            cui_inline_set_text_len(
                edit_pf_gid,
                MMI_SMS_INLINE_PF_NAME_2,
                sms_set_user_data->profile_name_len + 1);
        }

        cui_inline_set_value(
            edit_pf_gid,
            MMI_SMS_INLINE_PF_NAME_2,
            editInfo->profile_name);

        mmi_asc_n_to_ucs2((CHAR*)sc_addr, (CHAR*)editInfo->sc_addr, SRV_SMS_MAX_ADDR_LEN + 1);

        cui_inline_set_value(
            edit_pf_gid,
            MMI_SMS_INLINE_PF_SC_2,
            sc_addr);

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (email_valid)
        {
            mmi_asc_n_to_ucs2((CHAR*)sc_addr, (CHAR*)editInfo->email_addr, SRV_SMS_MAX_ADDR_LEN + 1);

            cui_inline_set_value(
                edit_pf_gid,
                MMI_SMS_INLINE_PF_EMAILSC_2,
                sc_addr);
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        cui_inline_run (edit_pf_gid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_profile_inline_item_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profiledetail       [?]         
 *  mod                 [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_profile_inline_item_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (!mmi_sms_setting_check_group_valid())
    {
        return;
    }
    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_profile_ext_struct *editInfo;
        U16 addr_len;
        srv_sms_profile_struct *profile_detail = (srv_sms_profile_struct*)callback_data->action_data;

        sms_set_user_data->editInfo = OslMalloc(sizeof(srv_sms_profile_ext_struct));
        editInfo = sms_set_user_data->editInfo;

        editInfo->vp_index = profile_detail->vp_index;
        editInfo->msg_type_index = profile_detail->msg_type_index;
        memcpy(editInfo->profile_name, profile_detail->profile_name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH);
        editInfo->profile_name_dcs = profile_detail->profile_name_dcs;
        editInfo->profile_index = sms_set_user_data->cur_hilite_index;
        addr_len = mmi_ucs2_n_to_asc((CHAR*)editInfo->sc_addr, (CHAR*) profile_detail->sc_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
        editInfo->sc_addr[addr_len] = '\0';
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        addr_len = mmi_ucs2_n_to_asc((CHAR*)editInfo->email_addr, (CHAR*) profile_detail->email_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
        editInfo->email_addr[addr_len] = '\0';
    #endif

        mmi_sms_entry_profile_edit();
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_profile_inline_item_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_profile_inline_item_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    srv_sms_get_setting_para(SRV_SMS_PROFILE_DETAIL, 
                             (void *)&sms_set_user_data->cur_hilite_index,
                             sms_set_user_data->sim_id, 
                             mmi_sms_get_profile_inline_item_rsp, 
                             NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_profile_active_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [?]         
 *  mod_src     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_profile_active_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sms_setting_gid != GRP_ID_INVALID)
    {
        sms_set_user_data->active_profile_no = *((U8*)callback_data->action_data);  

        //mmi_sms_display_popup_ext(
        //    STR_GLOBAL_ACTIVATED,
        //    MMI_EVENT_SUCCESS);

        mmi_frm_scrn_close(mmi_sms_setting_gid, SCR_ID_SMS_PROFILE_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_profile_active_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_profile_active_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_ext_struct profile_info;
    srv_sms_sim_enum sim_id = sms_set_user_data->sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_display_popup_ext(STR_GLOBAL_PLEASE_WAIT, MMI_EVENT_PROGRESS);

    if ((sms_set_user_data->vp_index < MAX_LFOUR_VP) && (sms_set_user_data->pid_index < MAX_LFOUR_MSG_TYPE))
    {
 #ifndef __MMI_SMS_SETTINGS_VP_SLIM__
      profile_info.vp_index = SRV_SMS_VP_MAX;
#else
        profile_info.vp_index = vp_enum[sms_set_user_data->vp_index];
#endif
        #ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__   
        profile_info.msg_type_index = pid_enum[sms_set_user_data->pid_index];
#else
 profile_info.msg_type_index = SMSAL_DEFAULT_PID;
#endif  
        profile_info.para = SRV_SMS_PROFILE_VP | SRV_SMS_PROFILE_PID;
    }
    else
    {
        MMI_ASSERT(0);
    }

    profile_info.profile_index = sms_set_user_data->cur_hilite_index;

    srv_sms_set_setting_para(SRV_SMS_PROFILE_DETAIL_PARTIAL, 
                             (void *)&profile_info, 
                             sim_id, 
                             NULL, 
                             NULL);

    srv_sms_set_setting_para(
        SRV_SMS_SET_ACTIVE_PROFILE, 
        &sms_set_user_data->cur_hilite_index, 
        sms_set_user_data->sim_id, 
        mmi_sms_set_profile_active_rsp, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_profile_options_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_profile_options_select_hdlr(mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id = highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MENU_ID_SMS_PROFILE_SETTING_OPTION_ACTIVE:
            mmi_sms_set_profile_active_req();
            break;

        case MENU_ID_SMS_PROFILE_SETTING_OPTION_EDIT:
            mmi_sms_get_profile_inline_item_req();
            break;

        default:
            break;
    }
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_fte_profile_setting_tap_callback
 * DESCRIPTION
 *  Set intuitive command function for profile settings Screen
 * PARAMETERS
 *  tap_type: [IN]   The current tap menu status highlight or not
 *  index   : [IN]   The tap menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_fte_profile_setting_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_sms_set_profile_active_req();
    }
    else
    {
        return;
    }
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_profile_settings_option
 * DESCRIPTION
 *  Entry profile settings option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_profile_settings_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_entry_menu_cui_options_generic(
        mmi_sms_setting_gid,
        MENU_ID_SMS_PROFILE_SETTING_OPTION,
        STR_GLOBAL_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_profile_highlight_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_profile_highlight_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_set_user_data->cur_hilite_index = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_profile_settings
 * DESCRIPTION
 *  Entry profile settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_profile_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;
    S32 hiliteitem;
    U16 nIconItemList[MAX_LFOUR_PROFILES] = {0, 0, 0, 0};
    U32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            mmi_sms_setting_gid,
            SCR_ID_SMS_PROFILE_LIST,
            NULL,
            mmi_sms_entry_profile_settings,
            MMI_FRM_FULL_SCRN))
    {
        for (index = 0; (index < sms_set_user_data->profile_count) && (index < MAX_LFOUR_PROFILES); index++)
        {
            if (sms_set_user_data->profile_name[index][0] == '\0')
            {
                subMenuDataPtrs[index] = (PU8) GetString((U16) defaultProfileNames[index]);
            }
            else
            {
                subMenuDataPtrs[index] = (PU8) sms_set_user_data->profile_name[index];
            }
        }

        guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_sms_setting_gid, SCR_ID_SMS_PROFILE_LIST);
    
        if (guiBuffer != NULL)
        {
            hiliteitem = sms_set_user_data->cur_hilite_index;
        }
        else
        {
            hiliteitem = sms_set_user_data->active_profile_no;
        }

        RegisterHighlightHandler(mmi_sms_get_profile_highlight_index);

        nIconItemList[sms_set_user_data->active_profile_no] = IMG_VICON;

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory73Screen(
            STR_ID_SMS_PROFILE_SETTING_MENUENTRY,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_OPTIONS,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            index,
            subMenuDataPtrs,
            nIconItemList,
            (U16*)gIndexIconsImageList,
            (U16) hiliteitem,
            guiBuffer,
            ICON_ICON_TEXT);

        SetLeftSoftkeyFunction(mmi_sms_entry_profile_settings_option, KEY_EVENT_UP);;
        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_sms_set_profile_active_req, KEY_EVENT_UP);
    
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_list_tap_callback(mmi_sms_fte_profile_setting_tap_callback);
    #endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_profile_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profilelist     [?]         
 *  mod             [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_profile_list_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (!mmi_sms_setting_check_group_valid())
    {
        return;
    }

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_profile_list_struct *psProfileNameList = (srv_sms_profile_list_struct*)callback_data->action_data;

        sms_set_user_data->active_profile_no = psProfileNameList->cur_req_profile_no;
        sms_set_user_data->profile_count = psProfileNameList->cur_max_ps_profiles;
        sms_set_user_data->profile_name_len = psProfileNameList->profile_name_len;
        memcpy((CHAR*)sms_set_user_data->profile_name, psProfileNameList->profile_name, (SRV_SMS_MAX_PROFILE_NAME_LEN+1) *ENCODING_LENGTH *SRV_SMS_MAX_LFOUR_PROFILES);

        if (sms_set_user_data->profile_count > 1)
        {
            mmi_sms_entry_profile_settings();
        }
        /* Enter to profile edit screen when only one profile */
        else if (sms_set_user_data->profile_count == 1)
        {
            sms_set_user_data->cur_hilite_index = 0;
            mmi_sms_get_profile_inline_item_req();
        }
        else
        {
            mmi_sms_display_popup_ext(
                STR_GLOBAL_EMPTY, 
                MMI_EVENT_FAILURE);
        }
    }
    else
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED, 
            MMI_EVENT_FAILURE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_sc_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_pre_entry_sc_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    srv_sms_get_setting_para(
        SRV_SMS_GET_PROFILE_LIST, 
        NULL, 
        sms_set_user_data->sim_id, 
        mmi_sms_get_profile_list_rsp, 
        NULL);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_sc_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_vm_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_msg_cntx.msg_dial_voicemail_from_idle_longpress = MMI_FALSE;

    mmi_sms_vm_pre_entry_hdlr(mmi_sms_setting_gid, sms_set_user_data->mmi_sim);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_highlight_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_sms_sim_set_highlight_hdlr(cui_event_inline_notify_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SMS_SLIM__
    if (evt->item_id < MMI_SMS_INLINE_ITEM_SIM1 + MMI_SIM_TOTAL)
    {
        cui_inline_set_softkey_text(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_sms_pre_entry_sc_list, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_sms_pre_entry_sc_list);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_pre_entry_sc_list, KEY_EVENT_UP);
    }
    else 
#endif
    if (evt->item_id == MMI_SMS_INLINE_ITEM_VM_SERVER)
    {
        cui_inline_set_softkey_text(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_sms_entry_vm_server, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_sms_entry_vm_server);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_entry_vm_server, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_set_submit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_submit_hdlr(cui_event_inline_submit_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SMS_SLIM__
    U16 sc[SRV_SMS_MAX_ADDR_LEN + 1];
    U16 addr_len;
#endif
    MMI_ID sim_set_gid = sms_set_user_data->sim_set_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SMS_SLIM__
    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_SMSC_2,
       sc);
    addr_len = mmi_ucs2_n_to_asc(sms_set_user_data->sc_addr, (CHAR*)sc, SRV_SMS_MAX_ADDR_LEN);
    sms_set_user_data->sc_addr[addr_len] = '\0';
#endif

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
	cui_inline_get_value(sim_set_gid, MMI_SMS_INLINE_ITEM_PRE_STOR_2, &(sms_set_user_data->pre_storage));
#endif
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_VP_2,
       &sms_set_user_data->vp_index);
#endif
#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_PID_2,
       &sms_set_user_data->pid_index);

       #endif

    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_DELIVER_2,
       &sms_set_user_data->status_report);

    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_REPLY_PATH_2,
       &sms_set_user_data->reply_path);

#ifdef __SMS_OVER_PS_SUPPORT__
    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_CONNECTION_2,
       &sms_set_user_data->connection);
#endif

#ifdef __MMI_MESSAGES_SMS_EMAIL__
#ifdef __MMI_SMS_SLIM__
    cui_inline_get_value(
       sim_set_gid,
       MMI_SMS_INLINE_ITEM_EMAIL_SC_2,
       sc);
    mmi_ucs2_n_to_asc(sms_set_user_data->email_addr, (CHAR*)sc, SRV_SMS_MAX_ADDR_LEN);
    sms_set_user_data->email_addr[addr_len] = '\0';
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#endif

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
	srv_sms_set_prefer_storage((srv_sms_storage_enum)sms_set_user_data->pre_storage, sms_set_user_data->sim_id);
#endif

	mmi_sms_set_and_entry_processing_sg(mmi_sms_setting_gid, STR_GLOBAL_PLEASE_WAIT, 0);

#ifdef __MMI_SMS_SLIM__
    mmi_sms_sim_set_save_req();
#else
    srv_sms_get_setting_para(
        SRV_SMS_GET_PROFILE_LIST, 
        NULL, 
        sms_set_user_data->sim_id, 
        mmi_sms_get_profile_number_rsp, 
        NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_profile_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SMS_SLIM__
#if defined(__MMI_SMS_SETTINGS_VP_SLIM__) && defined(__MMI_SMS_SETTINGS_MSG_TYPE_SLIM__)
    U32 item_count = 11;
#else
	 #if defined(__MMI_SMS_SETTINGS_VP_SLIM__) || defined(__MMI_SMS_SETTINGS_MSG_TYPE_SLIM__)
		 U32 item_count = 13;
	#else
    U32 item_count = 15;
	#endif
#endif
#else
    U32 item_count = 12;
#endif
    U32 index;
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
    PU8 vp_items[MAX_LFOUR_VP];
#endif
#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
    PU8 pid_items[MAX_LFOUR_MSG_TYPE];
#endif
    PU8 onoff_items[2];
#ifdef __SMS_OVER_PS_SUPPORT__
    PU8 connection_items[3];
#endif
    MMI_ID cur_gid;
    mmi_sim_enum mmi_sim = sms_set_user_data->mmi_sim;
#if (MMI_MAX_SIM_NUM >= 2)
    U16 title = STR_GLOBAL_SIM_1;
#else
    U16 title = STR_GLOBAL_SIM;
#endif
    srv_sms_setting_struct default_setting;
    cui_inline_struct inline_data;
    #ifndef __MMI_SMS_SETTINGS_VP_SLIM__
    U16 vp_str[] =
    {
        STR_ID_SMS_VP_1HOUR_MENUENTRY,
        STR_ID_SMS_VP_6HOUR_MENUENTRY,
        STR_ID_SMS_VP_12HOUR_MENUENTRY,
        STR_ID_SMS_VP_24HOUR_MENUENTRY,
        STR_ID_SMS_VP_3DAY_MENUENTRY,
        STR_ID_SMS_VP_1WEEK_MENUENTRY,
        STR_GLOBAL_MAXIMUM
    };
 #endif

   #ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
    U16 pid_str[] = 
    {
        STR_GLOBAL_TEXT,
        STR_ID_SMS_TYPE_FAX_MENUENTRY,
        STR_ID_SMS_TYPE_GROUP4_FAX_MENUENTRY,
        STR_ID_SMS_TYPE_PAGE_MENUENTRY,
        STR_GLOBAL_EMAIL
    };
#endif

#ifdef __SMS_OVER_PS_SUPPORT__
    U16 connection_str[] = 
    {
        STR_ID_SMS_PREFER_GPRS_BEARER_MENUENTRY,
        STR_ID_SMS_PREFER_GSM_BEARER_MENUENTRY,
        STR_ID_SMS_GSM_BEARER_MENUENTRY
    };
#endif
#ifdef __MMI_SLIM_IMG_RES__
    U16 sim_set_item_icons[] =
    {
        IMG_GLOBAL_L1,
    #ifdef __MMI_SMS_SLIM__
        0,
    #endif
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
        IMG_GLOBAL_L5,
        0,
        IMG_GLOBAL_L6,
        0,
        IMG_GLOBAL_L7,
        0,
        IMG_GLOBAL_L8,
        0,
        IMG_GLOBAL_L9
    };
#endif
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
	PU8 premem_items[2];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
	premem_items[0] = (PU8) GetString(STR_GLOBAL_PHONE);
	premem_items[1] = (PU8) GetString(STR_GLOBAL_SIM);
	item_count += 2;
#endif

    memcpy(&default_setting, srv_sms_get_default_setting(sms_set_user_data->sim_id), sizeof(srv_sms_setting_struct));

    /* validate period*/
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__    
    for (index = 0; index < MAX_LFOUR_VP; index++)
    {
        vp_items[index] = (PU8)GetString(vp_str[index]);
    }
#endif
#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
    /* message type */
    for (index = 0; index < MAX_LFOUR_MSG_TYPE; index++)
    {
        pid_items[index] = (PU8)GetString(pid_str[index]);
    }
    #endif

    onoff_items[0] = (PU8) GetString(STR_GLOBAL_OFF);
    onoff_items[1] = (PU8) GetString(STR_GLOBAL_ON);

#ifdef __SMS_OVER_PS_SUPPORT__
    for (index = 0; index < 3; index++)
    {
        connection_items[index] = (PU8)GetString(connection_str[index]);
    }
#else
    item_count -= 2;
#endif

#ifdef __MMI_SMS_SLIM__
#ifndef __MMI_MESSAGES_SMS_EMAIL__
    item_count -= 2;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#endif

#if (MMI_MAX_SIM_NUM >= 2)
    if (sms_set_user_data->sim_id == SRV_SMS_SIM_2)
    {
        title = STR_GLOBAL_SIM_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sms_set_user_data->sim_id == SRV_SMS_SIM_3)
    {
        title = STR_GLOBAL_SIM_3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sms_set_user_data->sim_id == SRV_SMS_SIM_4)
    {
        title = STR_GLOBAL_SIM_4;
    }
#endif
#endif

    inline_data.items_count = item_count;
    inline_data.title = title;
    inline_data.title_icon = IMG_SMS_ENTRY_SCRN_CAPTION;
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_data.softkey = NULL;
    inline_data.items = sim_set_items;

    cur_gid = cui_inline_create(
                    mmi_sms_setting_gid,
                    &inline_data);
    sms_set_user_data->sim_set_gid = cur_gid;

    if (cur_gid != GRP_ID_INVALID)
    {
    #ifdef __MMI_SMS_SLIM__
        U16 sc[SRV_SMS_MAX_ADDR_LEN + 1];

        mmi_asc_n_to_ucs2((CHAR*)sc, default_setting.sc_addr, SRV_SMS_MAX_ADDR_LEN + 1);
 
        cui_inline_set_value(
            cur_gid,
            MMI_SMS_INLINE_ITEM_SMSC_2,
            sc);
    #endif

    #if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && defined(__OP01__)
	    sms_set_user_data->pre_storage = srv_sms_get_prefer_storage(sms_set_user_data->sim_id);

        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_PRE_STOR_2,
            2,
            premem_items,
            sms_set_user_data->pre_storage);
    #endif
        #ifdef __MMI_SMS_SETTINGS_VP_SLIM__
	        sms_set_user_data->vp_index = 0;
         #else
          sms_set_user_data->vp_index = SRV_SMS_VP_MAX;
          #endif
	
        sms_set_user_data->pid_index = 0;

#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
        for (index = 0; index < MAX_LFOUR_VP; index++)
        {
            if (default_setting.vp == vp_enum[index])
            {
                sms_set_user_data->vp_index = index;
            }
        }
   #endif    
 #ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__     
        for (index = 0; index < MAX_LFOUR_MSG_TYPE ; index++)
        {
            if (default_setting.pid == pid_enum[index])
            {
                sms_set_user_data->pid_index = index;
            }
        }
#endif
#ifndef __MMI_SMS_SETTINGS_VP_SLIM__
        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_VP_2,
            MAX_LFOUR_VP,
            vp_items,
            sms_set_user_data->vp_index);
#endif

#ifndef __MMI_SMS_SETTINGS_MSG_TYPE_SLIM__
        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_PID_2,
            MAX_LFOUR_MSG_TYPE,
            pid_items,
            sms_set_user_data->pid_index);
            #endif

        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_DELIVER_2,
            2,
            onoff_items,
            (U8)default_setting.status_report);

        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_REPLY_PATH_2,
            2,
            onoff_items,
            (U8)default_setting.reply_path);

    #ifdef __SMS_OVER_PS_SUPPORT__
        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_CONNECTION_2,
            3,
            connection_items,
            sms_set_user_data->connection);
    #endif

    #ifdef __MMI_SMS_SLIM__
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        strncpy((CHAR*)sc, srv_sms_get_email_sc_address(), (SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH);
        cui_inline_set_value(
            cur_gid,
            MMI_SMS_INLINE_ITEM_EMAIL_SC_2,
            sc);
    #endif
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    #ifdef __MMI_SLIM_IMG_RES__
        cui_inline_set_icon_list(cur_gid, sim_set_item_icons);
    #endif

        cui_inline_run (cur_gid);

        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_PROTOLCOL_ID, mmi_sim))
        {
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_PID_1);
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_PID_2);
        }

        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_VALIDITY_PERIOD, mmi_sim))
        {
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_VP_1);
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_VP_2);
        }

        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_DEL_CONF, mmi_sim))
        {
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_DELIVER_1);
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_DELIVER_2);
        }

        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_REPLY_PATH, mmi_sim))
        {
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_REPLY_PATH_1);
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_REPLY_PATH_2);
        }

    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (!srv_sim_ctrl_is_inserted(mmi_sim)
            || !srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, mmi_sim)
            )
    #else
        if (!mmi_sms_is_vm_available(mmi_sim))
    #endif
        {
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_VM_SERVER);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_profile_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_set_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (!srv_sim_ctrl_is_inserted(sms_set_user_data->mmi_sim))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_INSERT_SIM_CARD,
            MMI_EVENT_FAILURE);
    }
    else if (!srv_sim_ctrl_is_available(sms_set_user_data->mmi_sim))
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNAVAILABLE_SIM,
            MMI_EVENT_FAILURE);
    }
    else
#endif
    {
    #ifdef __SMS_OVER_PS_SUPPORT__
		mmi_sms_set_and_entry_processing_sg(mmi_sms_setting_gid, STR_GLOBAL_PLEASE_WAIT, 0);

        srv_sms_get_setting_para(
            SRV_SMS_PRE_BEARER, 
            NULL, 
            sms_set_user_data->sim_id, 
            mmi_sms_get_bearer_service_rsp, 
            NULL);
    #else
        mmi_sms_sim_set_entry();
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_main_setting_entry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_sms_main_setting_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    PU8 savesent_items[2];
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    PU8 premem_items[3];
#else
PU8 premem_items[2];
#endif
#endif
#ifdef __EMS_NON_STD_7BIT_CHAR__
    PU8 ns7char_items[2];
#endif  
#ifdef __EMS_DYNAMIC_SEG_NUM__
    PU8 longsms_items[2];
#endif
    MMI_BOOL sim_enabled[MMI_SIM_TOTAL];
    U32 items_count = 0;
    U32 disablesim_count = 0;
    MMI_ID cur_gid;
    cui_inline_struct inline_data;
#ifdef __MMI_SLIM_IMG_RES__
    U16 main_set_item_icons[MMI_SMS_INLINE_ITEM_MAIN_TOTAL] = { 0 };
    U32 reduce_count = 1;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        sim_enabled[index] = (MMI_BOOL)srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index));
    #else
        sim_enabled[index] = srv_sim_ctrl_is_available(mmi_frm_index_to_sim(index));
    #endif

        if (sim_enabled[index])
        {
        #ifdef __MMI_SLIM_IMG_RES__
            main_set_item_icons[items_count] = gIndexIconsImageList[items_count];
        #endif
            items_count++;
        }
        else
        {
            disablesim_count++;
        }
    }

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count];
#endif
    items_count++;
#endif

#ifdef __MMI_SMS_COUNTER__
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count];
#endif
    items_count++; /* for SMS counter*/
#endif

    /* save sent*/
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count];
#endif
    savesent_items[0] = (PU8) GetString(STR_GLOBAL_OFF);
    savesent_items[1] = (PU8) GetString(STR_GLOBAL_ON);
    items_count += 2;

    /* prefer storage */
#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count - reduce_count];
    reduce_count++;
#endif
    premem_items[0] = (PU8) GetString(STR_GLOBAL_PHONE);
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    premem_items[1] = (PU8) GetString(STR_GLOBAL_MEMORY_CARD);
    premem_items[2] = (PU8) GetString(STR_GLOBAL_SIM);
#else
    premem_items[1] = (PU8) GetString(STR_GLOBAL_SIM);
#endif
    items_count += 2;
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count - reduce_count];
#endif
    items_count++;
#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count - reduce_count];
    reduce_count++;
#endif
    ns7char_items[0] = (PU8) GetString(STR_GLOBAL_AUTOMATIC);
    ns7char_items[1] = (PU8) GetString(STR_ID_SMS_SETUP_CHARACTER_7BIT_MENUENTRY);
    items_count += 2;
#endif

#ifdef __EMS_DYNAMIC_SEG_NUM__
#ifdef __MMI_SLIM_IMG_RES__
    main_set_item_icons[items_count] = gIndexIconsImageList[items_count - reduce_count];
#endif
    longsms_items[0] = (PU8) GetString(STR_GLOBAL_DEACTIVATE);
    longsms_items[1] = (PU8) GetString(STR_GLOBAL_ACTIVATED);
    items_count += 2;
#endif
#if defined( __SMS_CLOUD_SUPPORT__ )
    items_count += 2;
#endif
    inline_data.items_count = items_count + disablesim_count;
    inline_data.title = STR_ID_SMS_MESSAGESETUP_MENUENTRY;
    inline_data.title_icon = IMG_SMS_ENTRY_SCRN_CAPTION;
    inline_data.screen_flag = CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_data.softkey = NULL;
    inline_data.items = main_set_items;

    cur_gid = cui_inline_create(
                    mmi_sms_setting_gid,
                    &inline_data);
    sms_set_user_data->main_set_gid = cur_gid;

    if (cur_gid != GRP_ID_INVALID)
    {
        for (index = 0; index < MMI_SIM_TOTAL; index++)
        {
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            U16 str_id = 0;
        #endif

        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if ((disablesim_count == MMI_SIM_TOTAL) && (index == 0))
            {
                cui_inline_set_value(cur_gid, MMI_SMS_INLINE_ITEM_SIM1, GetString(STR_GLOBAL_SIM));
            }
            else
        #endif
            if (!sim_enabled[index])
            {
                cui_inline_delete_item(
                    cur_gid,
                    MMI_SMS_INLINE_ITEM_SIM1 + index);
            }
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            else
            {
                if ((MMI_SIM_TOTAL - disablesim_count) == 1)
                {
                    str_id = STR_GLOBAL_SIM;
                }
                else
                {
                    str_id = sms_sim_str_id[index];
                }

                 if (mmi_netset_get_sim_name(mmi_frm_index_to_sim(index)) != NULL)
                {
                    kal_wsprintf(&(sms_set_user_data->sim_name[index *MMI_SMS_SET_MAX_NAME_LEN]), 
                        "%w%w%w%w",
                        GetString(str_id),
                        (CHAR*) L"(",
                        mmi_netset_get_sim_name(mmi_frm_index_to_sim(index)),
                        (CHAR*) L")");

                    cui_inline_set_value(cur_gid, MMI_SMS_INLINE_ITEM_SIM1 + index, &(sms_set_user_data->sim_name[index *MMI_SMS_SET_MAX_NAME_LEN]));
                }
                else
                {
                    kal_wsprintf(&(sms_set_user_data->sim_name[index *MMI_SMS_SET_MAX_NAME_LEN]), 
                        "%w",
                        GetString(str_id));
                    cui_inline_set_value(cur_gid, MMI_SMS_INLINE_ITEM_SIM1 + index, GetString(str_id));
                }
            }
        #endif
        }

        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_SAVE_SENT_2,
            2,
            savesent_items,
            (U8)srv_sms_is_save_sent_sms_setting(SRV_SMS_SIM_1));

    #if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        if (sms_set_user_data->pre_storage == SRV_SMS_STORAGE_TCARD)
        {
            sms_set_user_data->pre_storage = 1;
        }
    #if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
        else if (sms_set_user_data->pre_storage == SRV_SMS_STORAGE_SIM)
        {
            sms_set_user_data->pre_storage = 2;
        }
    #endif

        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_PRE_MEM_2,
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            2,
        #else
            3,
        #endif
            premem_items,
            sms_set_user_data->pre_storage);
    #else
cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_PRE_MEM_2,
            2,
            premem_items,
            sms_set_user_data->pre_storage);
    #endif
    #endif

    #ifdef __EMS_NON_STD_7BIT_CHAR__
        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_7BIT_2,
            2,
            ns7char_items,
            (U8)srv_sms_is_7bit_setting(SRV_SMS_SIM_1));
    #endif

    #ifdef __EMS_DYNAMIC_SEG_NUM__
        cui_inline_set_item_select(
            cur_gid,
            MMI_SMS_INLINE_ITEM_LONG_SMS_2,
            2,
            longsms_items,
            (U8)srv_sms_is_long_sms_dynamic_seg_setting(SRV_SMS_SIM_1));
    #endif

    #ifdef __MMI_SLIM_IMG_RES__
        cui_inline_set_icon_list(cur_gid, main_set_item_icons);
    #endif

        if (srv_sim_ctrl_get_num_of_inserted() == 0)
        {
        #if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_PRE_MEM_1);
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_PRE_MEM_2);
            cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_FILTER);
		#endif
		#ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
			cui_inline_delete_item(cur_gid, MMI_SMS_INLINE_ITEM_SMS_COUNTER);
		#endif
        }

        cui_inline_run (cur_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_main_setting_select_hdlr
 * DESCRIPTION
 *  handle message main settings menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_main_set_submit_hdlr(cui_event_inline_submit_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cur_gid = sms_set_user_data->main_set_gid;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        cur_gid,
        MMI_SMS_INLINE_ITEM_SAVE_SENT_2,
        &(sms_set_user_data->save_sent));

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
    cui_inline_get_value(cur_gid, MMI_SMS_INLINE_ITEM_PRE_MEM_2, &(sms_set_user_data->pre_storage));
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    if (sms_set_user_data->pre_storage == 1)
    {
			#ifdef __USB_IN_NORMAL_MODE__
			if (srv_usb_is_in_mass_storage_mode())
			{
				if (srv_usb_check_path_exported((WCHAR*) L"root"))
				{
					mmi_usb_app_unavailable_popup(0);   
					return;
				}
			}
		#endif /* __USB_IN_NORMAL_MODE__ */ 
    
     if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
		 {
					mmi_sms_display_popup_ext(STR_GLOBAL_NO_MEMORY_CARD,MMI_EVENT_PROPLEM);
					return;
		 }
	  else
	  {
			sms_set_user_data->pre_storage = SRV_SMS_STORAGE_TCARD;
	   }
    }
#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    else if (sms_set_user_data->pre_storage == 2)
    {
        sms_set_user_data->pre_storage = SRV_SMS_STORAGE_SIM;
    }
#endif
#endif
#endif


    if (srv_sms_set_save_sent_sms_setting((MMI_BOOL)sms_set_user_data->save_sent, SRV_SMS_SIM_1) == MMI_FALSE)
    {
        result = MMI_FALSE;
    }

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
    cui_inline_get_value(cur_gid, MMI_SMS_INLINE_ITEM_PRE_MEM_2, &(sms_set_user_data->pre_storage));
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    if (sms_set_user_data->pre_storage == 1)
    {
        sms_set_user_data->pre_storage = SRV_SMS_STORAGE_TCARD;
    }
#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    else if (sms_set_user_data->pre_storage == 2)
    {
        sms_set_user_data->pre_storage = SRV_SMS_STORAGE_SIM;
    }
#endif
#endif
#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
    cui_inline_get_value(cur_gid, MMI_SMS_INLINE_ITEM_7BIT_2, &(sms_set_user_data->ns7char));

    if (srv_sms_set_7bit_setting((MMI_BOOL)sms_set_user_data->ns7char, SRV_SMS_SIM_1) == MMI_FALSE)
    {
        result = MMI_FALSE;
    }
#endif

#ifdef __EMS_DYNAMIC_SEG_NUM__
    cui_inline_get_value(cur_gid, MMI_SMS_INLINE_ITEM_LONG_SMS_2, &(sms_set_user_data->longsms));

    if (srv_sms_set_long_sms_dynamic_seg_setting((MMI_BOOL)sms_set_user_data->longsms, SRV_SMS_SIM_1) == MMI_FALSE)
    {
        result = MMI_FALSE;
    }
#endif

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
    if (!srv_sms_set_prefer_storage((srv_sms_storage_enum)sms_set_user_data->pre_storage, SRV_SMS_SIM_1))
    {
		result = MMI_FALSE;
    }
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    else
    {
        srv_sms_filter_enum filter;
        srv_sms_storage_enum pref_storage;

        pref_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
        filter = srv_sms_get_storage_filter();

        if (pref_storage == SRV_SMS_STORAGE_ME)
        {
            filter |= SRV_SMS_FILTER_ME;
        }
        else if (pref_storage == SRV_SMS_STORAGE_TCARD)
        {
            filter |= SRV_SMS_FILTER_TCARD;
        }
        else if (pref_storage == SRV_SMS_STORAGE_SIM)
        {
             filter |= SRV_SMS_FILTER_SIM;
        }

        srv_sms_set_storage_filter(filter);
    }
#endif

#endif

    mmi_sms_set_save_result(result, mmi_sms_setting_gid);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_highlight_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_sms_main_set_highlight_hdlr(cui_event_inline_notify_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_id = evt->item_id;
    U32 index = item_id - MMI_SMS_INLINE_ITEM_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SIM_TOTAL)
    {
        sms_set_user_data->mmi_sim = mmi_frm_index_to_sim(index);
        sms_set_user_data->sim_id = SRV_SMS_MMI_SIM_TO_SMS(sms_set_user_data->mmi_sim);

        //cui_inline_set_softkey_icon(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, 0);
        cui_inline_set_softkey_text(evt->sender_id, item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_sms_sim_set_pre_entry, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_sms_sim_set_pre_entry);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_sim_set_pre_entry, KEY_EVENT_UP);
    }
#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
    else if (item_id == MMI_SMS_INLINE_ITEM_MEM_STATUS)
    {
        cui_inline_set_softkey_text(evt->sender_id, item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_sms_entry_memory_status, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_sms_entry_memory_status);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_entry_memory_status, KEY_EVENT_UP);
    }
#endif
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    else if (item_id == MMI_SMS_INLINE_ITEM_FILTER)
    {
        cui_inline_set_softkey_text(evt->sender_id, item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        wgui_inline_set_lsk_function(mmi_sms_entry_msg_filter);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_entry_msg_filter, KEY_EVENT_UP);
    }
#endif
#ifdef __MMI_SMS_COUNTER__
    else if (item_id == MMI_SMS_INLINE_ITEM_SMS_COUNTER)
    {
        cui_inline_set_softkey_text(evt->sender_id, item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        wgui_inline_set_lsk_function(mmi_sms_entry_msg_counter);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_entry_msg_counter, KEY_EVENT_UP);
    }
#endif
#if defined( __SMS_CLOUD_SUPPORT__ )
    if (evt->item_id == MMI_SMS_INLINE_ITEM_BACKUP)
    {
        cui_inline_set_softkey_text(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_sms_msg_backup_start, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_sms_msg_backup_start);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_msg_backup_start, KEY_EVENT_UP);
    }
    if (evt->item_id == MMI_SMS_INLINE_ITEM_RESTORE)
    {
        cui_inline_set_softkey_text(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
        //SetLeftSoftkeyFunction(mmi_sms_msg_restore_start, KEY_EVENT_UP);
        wgui_inline_set_lsk_function(mmi_sms_msg_restore_start);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_sms_msg_restore_start, KEY_EVENT_UP);
    }
#endif /* __SMS_CLOUD_SUPPORT__ */
}


#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_memory_status
 * DESCRIPTION
 *  Entry memory status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    WCHAR tempBufUnicode[MAX_SUBMENU_CHARACTERS];
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    WCHAR memoryStatus[MAX_SUBMENU_CHARACTERS * (MMI_SIM_TOTAL+2)];
#else
    WCHAR memoryStatus[MAX_SUBMENU_CHARACTERS * (MMI_SIM_TOTAL+1)];
#endif
    srv_sms_memory_status_struct status_data;
    U16 str_id[] =
    {
    #if (MMI_MAX_SIM_NUM == 1)
        STR_ID_SMS_MEMSTATUS_PREFIX_SIM
    #else
        STR_ID_SMS_SIM1_COLON
        ,STR_ID_SMS_SIM2_COLON
    #if (MMI_MAX_SIM_NUM >= 3)
        ,STR_ID_SMS_SIM3_COLON
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        ,STR_ID_SMS_SIM4_COLON
    #endif
    #endif
        ,STR_ID_SMS_MEMSTATUS_PREFIX_PHONE
    };
    U8 *guiBuffer;
    mmi_sim_enum mmi_sim;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    U16 s_str_id = 0;
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
WCHAR drive_path[4];
U32 free_space = 0;
S32 fs_ret;
FS_DiskInfo disk_info;
U32 size_kb_free = 0;
 U32 size_bytes_free = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			#ifdef __USB_IN_NORMAL_MODE__
			if (srv_usb_is_in_mass_storage_mode())
			{
				if (srv_usb_check_path_exported((WCHAR*) L"root"))
				{
					mmi_usb_app_unavailable_popup(0);   
					return;
				}
			}
		#endif /* __USB_IN_NORMAL_MODE__ */     
    #endif  /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */     
    
    
    if (mmi_frm_scrn_enter(
            mmi_sms_setting_gid,
            SCR_ID_SMS_MEMORY_STATUS,
            NULL,
            mmi_sms_entry_memory_status,
            MMI_FRM_FULL_SCRN))
    {
        memoryStatus[0] = '\0';

        for (i = 0; i <= MMI_SIM_TOTAL; i++)
        {
            tempBufUnicode[0] = '\0';

            if (i < MMI_SIM_TOTAL)
            {
                mmi_sim = mmi_frm_index_to_sim(i);
 
                srv_sms_get_memory_status(SRV_SMS_MMI_SIM_TO_SMS(mmi_sim), &status_data);

            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if (srv_sim_ctrl_is_inserted(mmi_sim))
                {
                    if (srv_sim_ctrl_get_num_of_inserted() == 1)
                    {
                        s_str_id = STR_ID_SMS_MEMSTATUS_PREFIX_SIM;
                    }
                    else
                    {
                        s_str_id = str_id[i];
                    }

                    if (mmi_netset_get_sim_name(mmi_sim) != NULL)
                    {
                        kal_wsprintf(tempBufUnicode, 
                            "%w%d%w%d%w%w%w%w", 
                            GetString(s_str_id),
                            status_data.sim_used,
                            (CHAR*) L"/",
                            status_data.sim_total,
                            (CHAR*) L"(",
                            mmi_netset_get_sim_name(mmi_sim),
                            (CHAR*) L")",
                            (CHAR*)L"\n");
                    }
                    else
                    {
                        kal_wsprintf(tempBufUnicode, 
                            "%w%d%w%d%w", 
                            GetString(s_str_id),
                            status_data.sim_used,
                            (CHAR*) L"/",
                            status_data.sim_total,
                            (CHAR*)L"\n");
                    }
                }
            #else
                kal_wsprintf(tempBufUnicode, 
                    "%w%d%w%d%w", 
                    GetString(str_id[i]),
                    status_data.sim_used,
                    (CHAR*) L"/",
                    status_data.sim_total,
                    (CHAR*)L"\n");
            #endif
            }
            else
            {
                kal_wsprintf(tempBufUnicode, 
                    "%w%d%w%d",
                    GetString(str_id[i]),
                    status_data.me_used,
                    (CHAR*) L"/",
                    status_data.me_total);
            }

            if (wcslen(tempBufUnicode) < MAX_SUBMENU_CHARACTERS)
            {
                mmi_ucs2cat((CHAR*)memoryStatus, (CHAR*)tempBufUnicode);
            }
            else
            {
                MMI_ASSERT(0);
            }

        
        }
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
             if (srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
        {
            kal_wsprintf(tempBufUnicode, 
                    "%w%w%d%w%d",
                    (CHAR*)L"\n",
                GetString(STR_ID_MEMORY_CARD_COLON),
                status_data.tcard_used,
                (CHAR*) L"/",
                status_data.tcard_total);

            if (wcslen(tempBufUnicode) < MAX_SUBMENU_CHARACTERS)
            {
                mmi_ucs2cat((CHAR*)memoryStatus, (CHAR*)tempBufUnicode);
            }
            else
            {
                MMI_ASSERT(0);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif /* #if 0*/
        }
    #endif
        guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_sms_setting_gid, SCR_ID_SMS_MEMORY_STATUS);

        ShowCategory7Screen(
            STR_GLOBAL_MEMORY_STATUS,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) memoryStatus,
            guiBuffer);

        //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
}
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 


#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_msg_filter
 * DESCRIPTION
 *  Entry sms filter screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_msg_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id msg_setting_menu_gid;
    srv_sms_storage_enum prefer_storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
     #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			#ifdef __USB_IN_NORMAL_MODE__
			if (srv_usb_is_in_mass_storage_mode())
			{
				if (srv_usb_check_path_exported((WCHAR*) L"root"))
				{
					mmi_usb_app_unavailable_popup(0);   
					return;
				}
			}
		#endif /* __USB_IN_NORMAL_MODE__ */     
    #endif  /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */     
    
    
    prefer_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
    sms_set_user_data->sms_filter = srv_sms_get_storage_filter();

    msg_setting_menu_gid = cui_menu_create(
                mmi_sms_setting_gid,
                CUI_MENU_SRC_TYPE_APPCREATE,
                CUI_MENU_TYPE_APPSUB,
                MENU_ID_SMS_FILTER,
                MMI_FALSE,
                NULL);

    cui_menu_set_default_title(
        msg_setting_menu_gid,
        (WCHAR*)GetString(STR_ID_SMS_FILTER),
        (UI_image_type)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION));

    cui_menu_run(msg_setting_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_filter_entry_hdlr
 * DESCRIPTION
 *  Entry sms filter screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_filter_entry_hdlr(mmi_id cui_menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 items_index = 0;
    mmi_menu_id list_of_ids[3];
    U8 list_of_states[3] = {0, 0, 0};
    srv_sms_storage_enum prefer_storage;
    srv_sms_filter_enum filter;
    S32 disable_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    prefer_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
    filter = sms_set_user_data->sms_filter;

     list_of_ids[0] = (mmi_menu_id)0;
     if (filter & SRV_SMS_FILTER_ME)
    {
        list_of_states[0] = MMI_TRUE;
    }
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    if (1)
    {
        items_index++;
        list_of_ids[items_index] = (mmi_menu_id)items_index;
        if (filter & SRV_SMS_FILTER_TCARD)
        {
            list_of_states[items_index] = MMI_TRUE;
        }
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        if (prefer_storage == SRV_SMS_STORAGE_TCARD)
        {
            disable_index = items_index;
        }
    }
#endif

#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    if (srv_sim_ctrl_get_num_of_inserted())
    {
        items_index++;
        list_of_ids[items_index] = (mmi_menu_id)items_index;
        if (filter & SRV_SMS_FILTER_SIM)
        {
            list_of_states[items_index] = MMI_TRUE;
        }
        if (prefer_storage == SRV_SMS_STORAGE_SIM)
        {
            disable_index = items_index;
        }
    }
#endif

    cui_menu_set_currlist(cui_menu_gid, items_index + 1, list_of_ids);

    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_CHECK_BOX_LIST);

    cui_menu_set_item_string(
        cui_menu_gid,
        (mmi_menu_id)0,
        (WCHAR*) GetString((U16) STR_GLOBAL_PHONE));

    items_index = 1;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if (1)
    {
        cui_menu_set_item_string(
            cui_menu_gid,
            (mmi_menu_id)items_index,
            (WCHAR*) GetString((U16) STR_GLOBAL_MEMORY_CARD));
           	 if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
             cui_menu_set_item_disabled(cui_menu_gid, (mmi_menu_id)items_index, MMI_TRUE);
            else
            cui_menu_set_item_disabled(cui_menu_gid, (mmi_menu_id)items_index, MMI_FALSE);
    }
    #endif

#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    if (srv_sim_ctrl_get_num_of_inserted())
    {
        items_index++;
        cui_menu_set_item_string(
            cui_menu_gid,
            (mmi_menu_id)items_index,
            (WCHAR*) GetString((U16) STR_GLOBAL_SIM));
        
        cui_menu_set_item_disabled(cui_menu_gid, (mmi_menu_id)items_index, MMI_TRUE);
    }
#endif

    cui_menu_set_item_disabled(cui_menu_gid, (mmi_menu_id)disable_index, MMI_TRUE);

    cui_menu_set_checkbox_state(cui_menu_gid, list_of_states);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_filter_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_filter_select_hdlr(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 list_of_states[3];
    S32 items_index = 0;
    srv_sms_filter_enum filter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //prefer_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);

    cui_menu_get_checkbox_state(menu_gid, list_of_states);

    if (list_of_states[items_index])
    {
        filter |= SRV_SMS_FILTER_ME;
    }
    items_index++;

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    if (1)
    {
        if (list_of_states[items_index])
        {
            filter |= SRV_SMS_FILTER_TCARD;
        }
        items_index++;
    }
#endif
#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    if (srv_sim_ctrl_get_num_of_inserted())
    {
        if (list_of_states[items_index])
        {
            filter |= SRV_SMS_FILTER_SIM;
        }
    }
#endif

    srv_sms_set_storage_filter(filter);

    cui_menu_close(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_filter_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_filter_change_hdlr(mmi_id menu_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 list_of_states[3];
    S32 items_index = 0;
    srv_sms_storage_enum prefer_storage;
    MMI_BOOL is_error = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prefer_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);

    cui_menu_get_checkbox_state(menu_gid, list_of_states);

    sms_set_user_data->sms_filter = 0;

    if (prefer_storage == SRV_SMS_STORAGE_ME && list_of_states[items_index] == MMI_FALSE)
    {
         cui_menu_set_default_left_softkey_by_id(menu_gid, 0);
         list_of_states[items_index] = MMI_TRUE;
         is_error = MMI_TRUE;
         sms_set_user_data->sms_filter |= SRV_SMS_FILTER_ME;
    }
    else if (list_of_states[items_index])
    {
        sms_set_user_data->sms_filter |= SRV_SMS_FILTER_ME;
    }


    items_index++;
    if (prefer_storage == SRV_SMS_STORAGE_TCARD && list_of_states[items_index] == MMI_FALSE)
    {
        list_of_states[items_index] = MMI_TRUE;
        is_error = MMI_TRUE;
        sms_set_user_data->sms_filter |= SRV_SMS_FILTER_TCARD;
    }
    else if (list_of_states[items_index])
    {
        sms_set_user_data->sms_filter |= SRV_SMS_FILTER_TCARD;
    }

#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    items_index++;
    if (prefer_storage == SRV_SMS_STORAGE_ME && list_of_states[items_index] == MMI_FALSE)
    {
        list_of_states[items_index] = MMI_TRUE;
        is_error = MMI_TRUE;
        sms_set_user_data->sms_filter |= SRV_SMS_FILTER_SIM;
    }
    else if (list_of_states[items_index])
    {
        sms_set_user_data->sms_filter |= SRV_SMS_FILTER_SIM;
    }
#endif

    if (is_error)
    {
        cui_menu_set_checkbox_state(menu_gid, list_of_states);
        //mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO, (WCHAR*)GetString(STR_GLOBAL_ERROR));
        //mmi_sms_display_popup_ext(STR_GLOBAL_ERROR, MMI_EVENT_WARNING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_filter_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_filter_hilite_hdlr(mmi_id menu_gid, mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 items_index = 0;
    srv_sms_storage_enum prefer_storage;
    MMI_BOOL is_error = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prefer_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);

    if ((prefer_storage == SRV_SMS_STORAGE_ME) && (highlighted_menu_id == 0))
    {
        cui_menu_set_default_left_softkey_by_id(menu_gid, 0);
    }

     items_index++;
    if (prefer_storage == SRV_SMS_STORAGE_TCARD && highlighted_menu_id == items_index)
    {
        cui_menu_set_currlist_left_softkey_by_id(menu_gid, 0);
    }

#if !defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
    items_index++;
    if (prefer_storage == SRV_SMS_STORAGE_ME &&  highlighted_menu_id == items_index)
    {
        cui_menu_set_currlist_left_softkey_by_id(menu_gid, 0);
    }
#endif
}

#endif


#ifdef __MMI_SMS_COUNTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_sms_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_RET mmi_sms_update_sms_counter(mmi_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_SMS_COUNTER_STATUS == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_reset_sim_counter
 * DESCRIPTION
 *  reset SMS counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_reset_sim_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = SRV_SMS_MMI_SIM_TO_SMS(sms_set_user_data->mmi_sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_reset_sms_counter(sim_id, SRV_SMS_COUNT_SENT);
    srv_sms_reset_sms_counter(sim_id, SRV_SMS_COUNT_RECV);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_reset_sim_counter
 * DESCRIPTION
 *  reset SMS counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_pre_reset_sim_counter(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_set_user_data->mmi_sim = mmi_sim;

    mmi_sms_entry_confirm_sg(mmi_sms_setting_gid,
        STR_ID_SMS_RESET_COUNTER_QUERY,
        mmi_sms_reset_sim_counter,
        mmi_frm_scrn_close_active_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_reset_counter
 * DESCRIPTION
 *  reset SMS counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_reset_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(MMI_MAX_SIM_NUM == 1)
    mmi_sms_pre_reset_sim_counter(MMI_SIM1);
#else
    if (srv_sim_ctrl_get_num_of_inserted() == 1)
    {
        mmi_sms_pre_reset_sim_counter((mmi_sim_enum)srv_sim_ctrl_get_one_available_sim());
    }
    else
    {
        mmi_sms_entry_menu_cui_options_generic(
            mmi_sms_setting_gid,
            MENU_ID_SMS_COUNTER_RESET,
            STR_GLOBAL_RESET);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_msg_counter
 * DESCRIPTION
 *  Entry SMS counter screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_entry_msg_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    WCHAR counter_status[MAX_SUBMENU_CHARACTERS * (MMI_SIM_TOTAL*2)];
#if(MMI_MAX_SIM_NUM >= 2)
    srv_sms_sim_enum sms_sim;
    mmi_sim_enum mmi_sim;
    WCHAR tempBufUnicode[2][MAX_SUBMENU_CHARACTERS];
    U32 i;
    WCHAR* temp_name[2];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	if (srv_sim_ctrl_get_num_of_inserted() == 0)
	{
        mmi_sms_display_popup_ext(
            STR_GLOBAL_INSERT_SIM_CARD,
            MMI_EVENT_FAILURE);
		return;
	}
#endif

    if (mmi_frm_scrn_enter(
            mmi_sms_setting_gid,
            SCR_ID_SMS_COUNTER_STATUS,
            NULL,
            mmi_sms_entry_msg_counter,
            MMI_FRM_FULL_SCRN))
    {
    #if(MMI_MAX_SIM_NUM >= 2)
        counter_status[0] = '\0';

        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            tempBufUnicode[0][0] = '\0';
            tempBufUnicode[1][0] = '\0';

            mmi_sim = mmi_frm_index_to_sim(i);
            sms_sim = SRV_SMS_MMI_SIM_TO_SMS(mmi_sim);

            if (srv_sim_ctrl_is_inserted(mmi_sim))
            {
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if (srv_sim_ctrl_get_num_of_inserted() == 1)
                {
                    temp_name[0] = (WCHAR*)GetString(STR_GLOBAL_SENT);
                    temp_name[1] = (WCHAR*)GetString(STR_GLOBAL_RECEIVED);
                }
                else
            #endif
                {
                    mmi_wsprintf(
                        tempBufUnicode[0],
                        MAX_SUBMENU_CHARACTERS*2,
                        STR_ID_SMS_COUNTER_SENT,
                        (WCHAR*)GetString(sms_sim_str_id[i]));
                    mmi_wsprintf(
                        tempBufUnicode[1],
                        MAX_SUBMENU_CHARACTERS*2,
                        STR_ID_SMS_COUNTER_RECEIVED,
                        (WCHAR*)GetString(sms_sim_str_id[i]));
                    temp_name[0] = tempBufUnicode[0];
                    temp_name[1] = tempBufUnicode[1];
                }
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                if (mmi_netset_get_sim_name(mmi_frm_index_to_sim(i)) != NULL)
                {
                    kal_wsprintf(counter_status, 
                        "%w%w%w%w%w%d%w%w%w%w%w%d%w",
                        counter_status,
                        temp_name[0],
                        (CHAR*) L"(",
                        mmi_netset_get_sim_name(mmi_sim),
                        (CHAR*) L")\n",
                        srv_sms_get_sms_counter(sms_sim, SRV_SMS_COUNT_SENT),
                        (CHAR*) L"\n\n",
                        temp_name[1],
                        (CHAR*) L"(",
                        mmi_netset_get_sim_name(mmi_sim),
                        (CHAR*) L")\n",
                        srv_sms_get_sms_counter(sms_sim, SRV_SMS_COUNT_RECV),
                        (CHAR*) L"\n\n");
                }
                else
            #endif
                {
                    kal_wsprintf(counter_status, 
                        "%w%w%w%d%w%w%w%d%w",
                        counter_status,
                        temp_name[0],
                        (CHAR*) L"\n",
                        srv_sms_get_sms_counter(sms_sim, SRV_SMS_COUNT_SENT),
                        (CHAR*)L"\n\n",
                        temp_name[1],
                        (CHAR*) L"\n",
                        srv_sms_get_sms_counter(sms_sim, SRV_SMS_COUNT_RECV),
                        (CHAR*)L"\n\n");
                }
            }

            MMI_ASSERT((wcslen(counter_status) < (MAX_SUBMENU_CHARACTERS * MMI_SIM_TOTAL * 2)));
        }

        counter_status[wcslen(counter_status) - 2] = '\0'; /* remove the last "\n\n" */
    #else
        kal_wsprintf(counter_status, 
            "%w%w%d%w%w%w%d",
            GetString(STR_GLOBAL_SENT),
            (CHAR*) L"\n",
            srv_sms_get_sms_counter(SRV_SMS_SIM_1, SRV_SMS_COUNT_SENT),
            (CHAR*)L"\n\n",
            GetString(STR_GLOBAL_RECEIVED),
            (CHAR*) L"\n",
            srv_sms_get_sms_counter(SRV_SMS_SIM_1, SRV_SMS_COUNT_RECV));
    #endif

        guiBuffer = mmi_frm_scrn_get_gui_buf(mmi_sms_setting_gid, SCR_ID_SMS_COUNTER_STATUS);

		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory7Screen(
            STR_ID_SMS_COUNTER,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_RESET,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) counter_status,
            guiBuffer);
        SetLeftSoftkeyFunction(mmi_sms_reset_counter, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_sms_reset_counter, KEY_EVENT_UP);
    }
}
#endif /* __MMI_SMS_COUNTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_msg_setting_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_msg_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            if (mmi_sms_setting_gid !=  GRP_ID_INVALID)
            {
            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                OslMfree(sms_set_user_data->sim_name);
            #endif
                OslMfree(sms_set_user_data);
                mmi_sms_setting_gid = GRP_ID_INVALID;
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                mmi_group_event_struct *event = (mmi_group_event_struct*)evt;

                cui_inline_close(event->sender_id);
                if (sms_set_user_data->main_set_gid == event->sender_id)
                {
                    sms_set_user_data->main_set_gid = GRP_ID_INVALID;
                }
                else if (sms_set_user_data->sim_set_gid == event->sender_id)
                {
                    sms_set_user_data->sim_set_gid = GRP_ID_INVALID;
                }
            #ifndef __MMI_SMS_SLIM__
                else if (sms_set_user_data->edit_pf_gid == event->sender_id)
                {
                    sms_set_user_data->edit_pf_gid = GRP_ID_INVALID;
                    OslMfree(sms_set_user_data->editInfo);
                    sms_set_user_data->editInfo = NULL;
                }
            #endif
            }
            break;

    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
            {
                mmi_group_event_struct *event = (mmi_group_event_struct*)evt;

                if (sms_set_user_data->sim_set_gid == event->sender_id)
                {
                    cui_inline_set_title_string(
                        sms_set_user_data->sim_set_gid,
                        (UI_string_type)&(sms_set_user_data->sim_name[mmi_frm_sim_to_index(sms_set_user_data->mmi_sim)*MMI_SMS_SET_MAX_NAME_LEN]));
                }
            }
            break;
    #endif

        case EVT_ID_CUI_INLINE_NOTIFY:
            {
                cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct*)evt;

                if (sms_set_user_data->main_set_gid == inline_evt->sender_id)
                {
                    if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
                    {
                        mmi_sms_main_set_highlight_hdlr(inline_evt);
                    }
                }
                else if (sms_set_user_data->sim_set_gid == inline_evt->sender_id)
                {
                    if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
                    {
                        mmi_sms_sim_set_highlight_hdlr(inline_evt);
                    }
                }
            }
            break;

        case EVT_ID_CUI_INLINE_SUBMIT :
            {
                cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct*)evt;

                if (sms_set_user_data->main_set_gid == inline_evt->sender_id)
                {
                    mmi_sms_main_set_submit_hdlr(inline_evt);
                }
                else if (sms_set_user_data->sim_set_gid == inline_evt->sender_id)
                {
                    mmi_sms_sim_set_submit_hdlr(inline_evt);
                }
            #ifndef __MMI_SMS_SLIM__
                else if (sms_set_user_data->edit_pf_gid == inline_evt->sender_id)
                {
                    mmi_sms_edit_profile_submit_hdlr(inline_evt);
                }
            #endif
            }
            break;
            
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

             #if (MMI_MAX_SIM_NUM >= 2) && defined(__MMI_SMS_COUNTER__)
                if (menu_evt->parent_menu_id == MENU_ID_SMS_COUNTER_RESET)
                {
                    U32 i = 0;
                    mmi_sim_enum mmi_sim;
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    WCHAR temp_buff[MAX_SUBMENU_CHARACTERS];
                #endif

                    for (i = 0; i < MMI_SIM_TOTAL; i++)
                    {
                        mmi_sim = mmi_frm_index_to_sim(i);

                        if (!srv_sim_ctrl_is_inserted(mmi_sim))
                        {
                            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_COUNTER_RESET_SIM1 + i, MMI_TRUE);
                        }
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                        else
                        {
                            if (mmi_netset_get_sim_name(mmi_sim) != NULL)
                            {
                                kal_wsprintf(temp_buff, 
                                    "%w%w%w%w", 
                                    GetString(sms_sim_str_id[i]),
                                    (CHAR*) L"(",
                                    mmi_netset_get_sim_name(mmi_frm_index_to_sim(i)),
                                    (CHAR*) L")");
                    
                                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_COUNTER_RESET_SIM1 + i, temp_buff);
                            }
                        }
                    #endif
                    }
                }
            #endif /* (MMI_MAX_SIM_NUM >= 2) && defined(__MMI_SMS_COUNTER__) */

            #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                if (menu_evt->parent_menu_id == MENU_ID_SMS_FILTER)
                {
                    mmi_sms_filter_entry_hdlr(menu_evt->sender_id);
                }
            #endif
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            #if !defined(__MMI_SMS_SLIM__)
                if (menu_evt->parent_menu_id == MENU_ID_SMS_PROFILE_SETTING_OPTION)
                {
                    mmi_sms_profile_options_select_hdlr(menu_evt->highlighted_menu_id);
                }
            #endif
            #if (MMI_MAX_SIM_NUM >= 2) && defined(__MMI_SMS_COUNTER__)
                if (menu_evt->parent_menu_id == MENU_ID_SMS_COUNTER_RESET)
                {
                    U32 index = menu_evt->highlighted_menu_id - MENU_ID_COUNTER_RESET_SIM1;
                    mmi_sms_pre_reset_sim_counter((mmi_sim_enum)(MMI_SIM1<<index));
                }
            #endif
            #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                if (menu_evt->parent_menu_id == MENU_ID_SMS_FILTER)
                {
                    mmi_sms_filter_select_hdlr(menu_evt->sender_id);
                }
            #endif
            }
            break;

     #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                if (menu_evt->parent_menu_id == MENU_ID_SMS_FILTER)
                {
                    //mmi_sms_filter_hilite_hdlr(menu_evt->sender_id, menu_evt->highlighted_menu_id);
                }
            }
            break;

        case EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                if (menu_evt->parent_menu_id == MENU_ID_SMS_FILTER)
                {
                    mmi_sms_filter_change_hdlr(menu_evt->sender_id);
                }
            }
            break;
    #endif

    #if ((MMI_MAX_SIM_NUM >= 2) && defined(__MMI_SMS_COUNTER__)) || !defined(__MMI_SMS_SLIM__) || defined(__MMI_SMS_TCARD_STORAGE_SUPPORT__)
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;
    #endif

        default:
            break;
    }

    return MMI_RET_OK;
}


#if defined( __SMS_CLOUD_SUPPORT__ )
static mmi_ret mmi_sms_backup_restore_group_proc(mmi_event_struct *evt);
static void mmi_sms_msg_backup_restore_common(mmi_sms_backup_restore_action_type_enum action);
static void mmi_sms_msg_backup_restore_show_provider_entry(void);
static mmi_ret mmi_sms_backup_restore_group_proc(mmi_event_struct *evt);
static void mmi_sms_backup_restore_provider_list_highlight_hdlr(S32 item_index);
static S32 mmi_sms_backup_restore_provider_list_get_item(S32 start_index, cat_iconlist_menu_item *menu_data, S32 num_items);
static void mmi_sms_backup_restore_provider_list_selected(void);
static void mmi_sms_backup_restore_cloud_action(U32 provider, U8 account_id);
static void mmi_sms_backup_restore_cloud_action_callback(srv_sms_callback_struct* callback_data);
static void mmi_sms_backup_restore_cloud_processing_entry();
static mmi_ret mmi_sms_backup_restore_group_proc(mmi_event_struct *evt);
static mmi_ret mmi_sms_backup_restore_cloud_processing_exit(mmi_event_struct *param);
static void mmi_sms_backup_restore_cloud_processing_cancel(void);
static void mmi_sms_backup_restore_cloud_processing_dismissed();
static mmi_ret mmi_sms_backup_restore_processing_proc(mmi_event_struct *evt);
static void mmi_sms_msg_backup_restore_show_provider_tap_callback_funtion(mmi_tap_type_enum tap_type,S32 index);
static void mmi_sms_backup_restore_cloud_processing_create();

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_msg_setting_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_msg_backup_start(void)
{
    mmi_sms_msg_backup_restore_common(MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_msg_setting_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_msg_restore_start(void)
{
    mmi_sms_msg_backup_restore_common(MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_msg_setting_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_msg_backup_restore_common(mmi_sms_backup_restore_action_type_enum action)
{
	U8 ret_val =  mmi_sms_account_nw_available();

	 if(ret_val == 1)
	{
			mmi_popup_display_ext(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE, MMI_EVENT_FAILURE, NULL);
			return;
	}
	else if (ret_val == 2)
	{
			mmi_popup_display_ext(STR_ID_MMI_SSO_NO_NW_CONNECTION, MMI_EVENT_FAILURE, NULL);
		return;
	}
#ifdef __USB_IN_NORMAL_MODE__ 
                        if (srv_usb_is_in_mass_storage_mode()) 
                        { 
                                if (srv_usb_check_path_exported((WCHAR*) L"root")) 
                                { 
                                        mmi_usb_app_unavailable_popup(0); 
                                        return; 
                                } 
                        } 
#endif /* __USB_IN_NORMAL_MODE__ */
    if (srv_sso_get_provider_count() ==0)
    {
        mmi_sms_display_popup_ext(
            STR_ID_SRV_SNS_NOT_READY,
            MMI_EVENT_FAILURE);
		return;
    }
	/*
if((action == MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP) && (srv_sms_get_list_size(SRV_SMS_BOX_INBOX) == 0))
    {
        mmi_sms_display_popup_ext(
            STR_ID_SMS_BACKUP_NO_MESSAGE,
            MMI_EVENT_FAILURE);
		return;
    }*/
   if (NULL != s_backup_restore_cntx)
    {
        OslMfree(s_backup_restore_cntx);
    }
    
// Already getting freeed on group deinit.
    s_backup_restore_cntx = OslMalloc(sizeof(mmi_sms_backup_restore_cntx));
    memset(s_backup_restore_cntx, 0, (sizeof(mmi_sms_backup_restore_cntx)));
    s_backup_restore_cntx->group = mmi_frm_group_create(mmi_sms_setting_gid, GRP_ID_AUTO_GEN, mmi_sms_backup_restore_group_proc, NULL);
    s_backup_restore_cntx->provider_ids = OslMalloc(sizeof(U32) * srv_sso_get_provider_count());
    s_backup_restore_cntx->action = action;
    mmi_frm_group_enter(s_backup_restore_cntx->group, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* show list*/
    mmi_sms_msg_backup_restore_show_provider_entry();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_msg_backup_restore_show_provider_list
 * DESCRIPTION
 *  show provider list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: is s
 *****************************************************************************/
static void mmi_sms_msg_backup_restore_show_provider_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 item_count;
    S32 error_flag;
    U16 string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
		s_backup_restore_cntx->group,
        SCR_ID_SMS_SCR_BACKUP_RESTORE_PROVIDER_LIST,
 		NULL,
        mmi_sms_msg_backup_restore_show_provider_entry,
        MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_group_close(s_backup_restore_cntx->group);
    	return;
    }
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_sms_backup_restore_provider_list_highlight_hdlr);
    EnableCenterSoftkey(0, IMG_GLOBAL_OK);
    
    if (s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP)
    {
        string_id = STR_ID_SMS_BACKUP;
    }
    else if (s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE)
    {
        string_id = STR_ID_SMS_RESTORE;
    }

    srv_cloud_support_backup_restore_list(SRV_CLD_TYPE_SMS, s_backup_restore_cntx->provider_ids, &item_count);
    s_backup_restore_cntx->provider_count = item_count;
    wgui_cat1056_show(
        (PU8)GetString(string_id),
        NULL,
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        item_count,
        mmi_sms_backup_restore_provider_list_get_item,
        s_backup_restore_cntx->highlight_index,
        IMG_GLOBAL_L1,
        gui_buffer,
        &error_flag);

    SetLeftSoftkeyFunction(mmi_sms_backup_restore_provider_list_selected, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_sms_backup_restore_provider_list_selected, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	//mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING);
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_sms_msg_backup_restore_show_provider_tap_callback_funtion);
#endif
}


static void mmi_sms_msg_backup_restore_show_provider_tap_callback_funtion(mmi_tap_type_enum tap_type,S32 index)
{
    if (ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        s_backup_restore_cntx->highlight_index = index;
        mmi_sms_backup_restore_provider_list_selected();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_msg_setting_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_backup_restore_group_proc(mmi_event_struct *evt)
{
    mmi_group_event_struct *grp_evt = (mmi_group_event_struct *)evt;
    switch(evt->evt_id)
    {
  //      case EVT_ID_CUI_SSO_LOGIN_OK:
	case EVT_ID_CUI_SSO_LOGIN_DONE:
        {
	   cui_sso_login_done_event_struct *login_evt = (cui_sso_login_done_event_struct*)evt;
			
           // mmi_frm_group_close(grp_evt->sender_id);
            
	if(login_evt->result == EVT_ID_CUI_SSO_LOGIN_OK)
        {
	    cui_sso_login_close(login_evt->sender_id);
            mmi_sms_backup_restore_provider_list_selected();
	}
	else if(login_evt->result == EVT_ID_CUI_SS0_LOGIN_ABORT)
	{
	    cui_sso_login_close(login_evt->sender_id);
	}
            break;
        }
        
        case EVT_ID_CUI_SSO_LOGIN_FAILED:
        {
            mmi_sms_display_popup_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE);
            mmi_frm_group_close(grp_evt->sender_id);
            break;
        }
        
        case EVT_ID_CUI_SS0_LOGIN_ABORT:
        {
            mmi_frm_group_close(grp_evt->sender_id);
            break;
        }

      //  case EVT_ID_GROUP_DEINIT:
		case EVT_ID_GROUP_EXIT:
        {
            if (NULL != s_backup_restore_cntx)
            {
                OslMfree(s_backup_restore_cntx->provider_ids);
                OslMfree(s_backup_restore_cntx);						/* Akhil On deinit free the context buffer */
                s_backup_restore_cntx = NULL;
            }
        }
    }
    return MMI_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_info_highlight_hdlr
 * DESCRIPTION
 *  Highlight Handler for multi select
 * PARAMETERS
 *  item_index                   [IN]            highlight item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_backup_restore_provider_list_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s_backup_restore_cntx->highlight_index = item_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_async_get_group_items
 * DESCRIPTION
 *  Gets the async items for the Phonelist.
 * PARAMETERS
 *  start_index     [IN]
 *  *menu_data      [OUT]
 *  num_items       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_sms_backup_restore_provider_list_get_item(S32 start_index, cat_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    WCHAR provider_name[SRV_SSO_NAME_SIZE+1] = {0,};
    WCHAR account_name[SRV_SSO_NAME_SIZE+1] = {0,};
    U32 provider;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < num_items; index++)
    {
        S32 list_index;
        srv_sso_account_struct account;
        list_index = index + start_index;
        provider = s_backup_restore_cntx->provider_ids[list_index];   
        srv_sso_get_provider_name(provider, provider_name);
        mmi_wcsncpy((WCHAR*)menu_data[list_index].item_list[0], provider_name, SRV_SSO_NAME_SIZE);
        srv_sso_get_accounts(provider, SRV_SSO_LOGIN_DONT_CARE, &account, 1);
        srv_sso_get_account_name(provider, account.account, account_name);
        mmi_wcsncpy((WCHAR*)menu_data[list_index].item_list[1], account_name, SRV_SSO_NAME_SIZE);      
        menu_data[list_index].image_list[2] = (PU8)srv_sso_get_provider_icon(provider, SRV_SSO_ICON_LARGE);
    }

    return num_items;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_backup_restore_provider_list_selected
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_backup_restore_provider_list_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    srv_sso_account_struct account;
    U32 provider_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    provider_id = s_backup_restore_cntx->provider_ids[s_backup_restore_cntx->highlight_index];
    if (srv_sso_get_account_count(provider_id, SRV_SSO_LOGIN_TRUE))
    {
        srv_sso_get_accounts(provider_id, SRV_SSO_LOGIN_TRUE, &account, 1);
        mmi_sms_backup_restore_cloud_action(provider_id, account.account);
    }
    else if (srv_sso_get_account_count(provider_id, SRV_SSO_LOGIN_FALSE))
    {
        srv_sso_get_accounts(provider_id, SRV_SSO_LOGIN_FALSE, &account, 1);
        group_id = cui_sso_login_create(s_backup_restore_cntx->group, provider_id, account.account);
        cui_sso_login_run(group_id);
    }
    else
    {
        group_id = cui_sso_login_create(s_backup_restore_cntx->group, provider_id, 0);
        cui_sso_login_run(group_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_backup_restore_cloud_action(U32 provider, U8 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_backup_restore_info_struct backup_restore_info;
    srv_cloud_set_opt_acct_info_struct account_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_backup_restore_cloud_processing_create();
    backup_restore_info.backup_restore_type = SRV_SMS_BACKUP_RESTORE_CLOUD;
    backup_restore_info.box_type = (srv_sms_box_enum)(SRV_SMS_BOX_INBOX|SRV_SMS_BOX_OUTBOX) ;
    account_info.provider = provider;
    account_info.account_id = account_id;
    backup_restore_info.account_info = &account_info;
    if (MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP == s_backup_restore_cntx->action)
    {
        s_backup_restore_cntx->handler = 
            srv_sms_backup_msg (backup_restore_info,
                         mmi_sms_backup_restore_cloud_action_callback,
                         NULL);
    }
    else if (MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE == s_backup_restore_cntx->action)
    {
        s_backup_restore_cntx->handler = 
            srv_sms_restore_msg(backup_restore_info,
                         mmi_sms_backup_restore_cloud_action_callback,
                         NULL);
    }
}

void mmi_sms_backup_restore_cloud_action_callback(srv_sms_callback_struct* callback_data)
{
 if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING)
 {
if((callback_data->result == KAL_TRUE) && (callback_data->cause == SRV_SMS_CAUSE_NO_ERROR))
{


			if(s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP)
			{
			   wgui_cat6003_update_all(
					(U8*)GetString(STR_ID_SMS_BACKUP_PROGRESS),
					NULL,
					100);
				mmi_sms_display_popup_ext(STR_ID_SMS_BACKUP_SUCCESS, MMI_EVENT_SUCCESS);

			}
			else if(s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE)
			{
			wgui_cat6003_update_all(
					(U8*)GetString(STR_ID_SMS_RESTORE_PROGRESS),
					NULL,
					100);
					mmi_sms_display_popup_ext(STR_ID_SMS_RESTORE_SUCCESS, MMI_EVENT_SUCCESS);
			}
		    mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING); // Akhil Commented
/*
	 else
	 {
		mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING); // Akhil Commented
	 }
*/
	 }
   
else if(callback_data->cause ==SRV_SMS_CAUSE_CLOUD_NO_NEED_SYNC)
{
	if(s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP)
	{
		     mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING);
		     mmi_sms_display_popup_ext(STR_ID_SMS_BACKUP_NO_MESSAGE, MMI_EVENT_FAILURE);
	}
	else if(s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE)
	{
		 mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING);
		mmi_sms_display_popup_ext(STR_ID_SMS_RESTORE_NO_MESSAGE, MMI_EVENT_FAILURE);
	}
	}
}
else
{
	if(s_backup_restore_cntx != NULL)
	 mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING);
}
if(s_backup_restore_cntx != NULL)
{
               s_backup_restore_cntx->processing_ongoing = MMI_FALSE;
	       s_backup_restore_cntx->finish_count = 0;
               s_backup_restore_cntx->total_count = 0;
}

}
void mmi_sms_backup_restore_cloud_processing_create()
{
    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_BACKUP_RESTORE, mmi_sms_backup_restore_processing_proc, NULL);
    mmi_frm_scrn_first_enter(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING, (FuncPtr)mmi_sms_backup_restore_cloud_processing_entry, NULL);
}


void mmi_sms_backup_restore_cloud_processing_entry()
{
    U16 string = 0;
    
    U16 percentage;
    WCHAR content[8];
	MMI_BOOL ret;
    if (0 == s_backup_restore_cntx->total_count)
    {
        percentage = 0;
    }
    else
    {
        percentage = (s_backup_restore_cntx->finish_count * 100) / s_backup_restore_cntx->total_count;
    }
    
    kal_wsprintf(content, "%d/%d", s_backup_restore_cntx->finish_count, s_backup_restore_cntx->total_count);
    if (MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP == s_backup_restore_cntx->action)
    {
        string = STR_ID_SMS_BACKUP_PROGRESS;    
    }
    else if (MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE == s_backup_restore_cntx->action)
    {
        string = STR_ID_SMS_RESTORE_PROGRESS;
    }
    ret = mmi_frm_scrn_enter(s_backup_restore_cntx->group, 
            SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING, 
            NULL,
            (FuncPtr)mmi_sms_backup_restore_cloud_processing_entry, 
            MMI_FRM_UNKNOW_SCRN);
	if (ret == MMI_FALSE)
	{
		return;
	}
/*    ShowCategory402Screen(
            (U8*) GetString(STR_GLOBAL_TEXT_MESSAGE),
            IMG_SMS_ENTRY_SCRN_CAPTION,
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*)GetString(string),
            0,
            NULL);
  */
s_backup_restore_cntx->processing_ongoing = MMI_TRUE;
                wgui_cat6003_show(
                    0,
                    STR_GLOBAL_CANCEL,
                   (U8*)GetString(string),
                    NULL,
                   percentage);
    
    SetRightSoftkeyFunction(mmi_sms_backup_restore_cloud_processing_cancel, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(
        s_backup_restore_cntx->group,
        SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING,
        mmi_sms_backup_restore_cloud_processing_exit);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cloud_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *                 
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_sms_backup_restore_cloud_processing_exit(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            mmi_sms_backup_restore_cloud_processing_dismissed();
            mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_BACKUP_RESTORE, mmi_sms_backup_restore_processing_proc, NULL);
            break;
            
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            if (NULL != s_backup_restore_cntx->handler)
            {
                srv_sms_abort_cloud(s_backup_restore_cntx->handler, NULL, NULL);
            }
            break;
                         
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_cloud_processing
 * DESCRIPTION
 *  check SMS is processing
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_check_cloud_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[Akhil] %u = ",s_backup_restore_cntx);
	kal_prompt_trace(MOD_MMI, "[Akhil] %d=",s_backup_restore_cntx->processing_ongoing);
	if(s_backup_restore_cntx == NULL)
	{
		return MMI_FALSE;
	}
	else
	{
    return s_backup_restore_cntx->processing_ongoing;
}
}

void mmi_sms_backup_restore_cloud_processing_cancel(void)
{
    srv_sms_abort_cloud(s_backup_restore_cntx->handler, NULL, NULL);
}

void mmi_sms_backup_restore_cloud_processing_dismissed()
{
    s_backup_restore_cntx->handler = NULL;
};

static mmi_ret mmi_sms_backup_restore_processing_proc(mmi_event_struct *evt)
{
  //  srv_sms_event_backup_restore_struct * backup_restore_evt = (srv_sms_event_backup_restore_struct*)evt;
    srv_sms_event_backup_restore_struct *backup_restore_evt = (srv_sms_event_backup_restore_struct *)(((srv_sms_event_struct *)evt)->event_info);   
    U16 percentage;
    WCHAR string[20];
    if (0 == backup_restore_evt->Total_number)
    {
        percentage = 0;
    }
    else
    {
       // percentage = (backup_restore_evt->cur_index * 100) / backup_restore_evt->Total_number;
		percentage =(U8)((backup_restore_evt->cur_index * 100) / backup_restore_evt->Total_number); 
    }
   // kal_wsprintf(string, "%d/%d", backup_restore_evt->cur_index, backup_restore_evt->Total_number);
    
    if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING)
    {
      //  UpdateCategory402Value(percentage, (U8*)string);
     s_backup_restore_cntx->finish_count = backup_restore_evt->cur_index;
     s_backup_restore_cntx->total_count=  backup_restore_evt->Total_number;
	 if (backup_restore_evt->action == SRV_SMS_ACTION_RESTORE)
    {
      	 wgui_cat6003_update_all(
        (U8*)GetString(STR_ID_SMS_RESTORE_PROGRESS),
        NULL,
        percentage);
    }
	else if (backup_restore_evt->action == SRV_SMS_ACTION_BACKUP)
    {
         wgui_cat6003_update_all(
        (U8*)GetString(STR_ID_SMS_BACKUP_PROGRESS),
        NULL,
        percentage);
    }
	else
	{
		ASSERT(0);
	}
    }

    return MMI_OK;
}

MMI_RET mmi_sms_update_um_for_refresh(mmi_event_struct *event_data)
{
	//srv_sms_event_refresh_struct *evt = event_data;
	srv_um_refresh_ind_struct *um_refresh_ind = NULL;
	if(event_data ->evt_id ==  EVT_ID_SRV_SMS_REFRESH_MSG)
	{
    um_refresh_ind =
        (srv_um_refresh_ind_struct*) construct_local_para((kal_uint16) sizeof(srv_um_refresh_ind_struct), 0);
    um_refresh_ind->msg_type = SRV_UM_MSG_SMS;
    um_refresh_ind->msg_box_type = SRV_UM_MSG_BOX_INBOX;
	srv_mms_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);
	}
 return MMI_RET_OK;
}


U8 mmi_sms_account_nw_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_nw_usab_any_sim_is_usable())
    {
        ret = 1; /*not available*/
    }

#ifdef __MMI_WLAN_FEATURES__
    if ((srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_CONNECTED) && (srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_ACTIVE))
    {
    	if (ret == 0) 
			return ret;
        ret = 2; /*no nw*/
    }
	else
	{
		ret = 0;
	}
#endif /* __MMI_WLAN_FEATURES__ */

    return ret;
}



void mmi_sms_close_cloud_progressing()
{
if(s_backup_restore_cntx != NULL)
{
	if(s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_BACKUP)
	{
		     mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING);
			 mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROVIDER_LIST);
			 
		     //mmi_sms_display_popup_ext(STR_ID_SMS_BACKUP_NO_MESSAGE, MMI_EVENT_FAILURE);
	}
	else if(s_backup_restore_cntx->action == MMI_SMS_BACKUP_RESTORE_ACTION_RESTORE)
	{
		 mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING);
		 mmi_frm_scrn_close(s_backup_restore_cntx->group, SCR_ID_SMS_SCR_BACKUP_RESTORE_PROVIDER_LIST);
		//mmi_sms_display_popup_ext(STR_ID_SMS_RESTORE_NO_MESSAGE, MMI_EVENT_FAILURE);
	}
}
}
#endif /* ( __SMS_CLOUD_SUPPORT__ ) */


/*****************************************************************************
 * FUNCTION
 *  cui_sms_setting_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_grp_id   :   [IN]        parent group id             
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID cui_sms_setting_launch(MMI_ID parent_grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_SETTING_LAUNCH, parent_grp_id);

    if (!srv_sms_is_sms_ready())
    {
        mmi_sms_display_popup_ext(
            STR_SMS_MSG_NOT_READY_YET,
            MMI_EVENT_FAILURE);

        return GRP_ID_INVALID;
    }

    if (parent_grp_id == GRP_ID_INVALID)
    {
        parent_grp_id = GRP_ID_ROOT;
    }

    mmi_sms_settings_group_close();

    sms_set_user_data = OslMalloc(sizeof(srv_sms_main_set_struct));
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    sms_set_user_data->sim_name = OslMalloc(MMI_SMS_SET_MAX_NAME_LEN * ENCODING_LENGTH*MMI_MAX_SIM_NUM);
#endif

    mmi_sms_setting_gid = mmi_frm_group_create_ex (
                            parent_grp_id,
                            GRP_ID_AUTO_GEN,
                            mmi_sms_msg_setting_group_proc,
                            sms_set_user_data,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_SETTING_GROUP_ENTRY, mmi_sms_setting_gid);

#if defined(__MMI_SMS_PREFER_STORAGE_SETTING__) && !defined(__OP01__)
	sms_set_user_data->pre_storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
#endif 

    mmi_sms_main_setting_entry();

    return mmi_sms_setting_gid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_settings_group_close
 * DESCRIPTION
 *  Entry message settings menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_settings_group_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID != mmi_sms_setting_gid)
    {
        mmi_frm_group_close(mmi_sms_setting_gid);
    }
}
#endif/*__MMI_TELEPHONY_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  DialVoiceMail
 * DESCRIPTION
 *  Dial voice mail server number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DialVoiceMail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_sms_vm_speed_dial_voicemail();
    #endif/*__MMI_TELEPHONY_SUPPORT__*/
}
#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_setting_check_interrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_setting_check_group_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_msg_check_interrupt() == MMI_TRUE) || (mmi_sms_setting_gid == GRP_ID_INVALID))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}
#endif/*__MMI_TELEPHONY_SUPPORT__*/

