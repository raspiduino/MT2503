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
 *  PhoneBookExtraNumber.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Implementation of feature "Owner Number", "Service Dial Number", and "SOS Number"
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "PhbCuiGprot.h"

#ifdef __MMI_LOCAL_PHB_SUPPORT__

#include "MMI_include.h"
#ifndef PHONEBOOKEXTRANUMBER_C
#define PHONEBOOKEXTRANUMBER_C

#include "CommonScreens.h"
#include "PhonebookResDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookProt.h"
#include "PhoneBookExtraNumber.h"
#include "IdleAppProt.h"
#include "SettingDefs.h"
#include "SettingGprots.h"
#include "UCMGProt.h"
#include "CallSetSrvGprot.h"
#include "custom_ecc.h"
#include "app_usedetails.h"

#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"
#include "SimCtrlSrvGprot.h"
#include "MenuCuiGprot.h"
#include "SecSetCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "InlineCuiGprot.h"
#include "mmi_frm_scenario_gprot.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UMGprot.h"
#endif
#include "SmsSrvGprot.h"
#ifdef __MMI_MMS__
#include "mmsadp.h"
#endif

#ifdef __MMI_VCARD__
#include "mmi_rp_srv_vcard_def.h"
#endif
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif

#include "ModeSwitchSrvGprot.h"
#include "NwUsabSrvGprot.h"

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "kal_general_types.h"
#include "PhoneBookCore.h"
#include "mmi_rp_app_phonebook_def.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "customer_email_num.h"
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "ps_public_enum.h"
#include "sim_common_enums.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "PhoneBookGprot.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_util.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "SettingResDef.h"
#include "vCard.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "PhbSrvIprot.h"
#include "gui_typedef.h"
#include "UcmSrvGprot.h"
#include "wgui_categories_CM.h"
#include "IdleAppDef.h"
#include "mmi_frm_history_gprot.h"
#include "nvram_data_items.h"
/* auto add by kw_check end */
#include "mmi_frm_utility_gprot.h"
#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
#endif
#endif
#ifndef __MMI_PHB_ALS_SUPPORT__
#define __MMI_PHB_ALS_SUPPORT__
#endif

#ifndef __MMI_PHB_ECC_DIRECT_DIAL__
#define __MMI_PHB_ECC_DIRECT_DIAL__
#endif

#define MMI_PHB_EXTRA_NUMBER

typedef struct
{
    mmi_id sg_id;
    U16 select_index;
    U16 store_index;
    U32 num_type;
    WCHAR display_name[MMI_PHB_NAME_LENGTH + 1];
    mmi_phb_contact_info_struct* contact;
} mmi_phb_speed_dial_pre_set_cntx_struct;

/*
 * Local Variable
 */
static SRV_PHB_XMGNT_HANDLE g_mmi_phb_handle;
static MMI_BOOL g_mmi_phb_in_operation;
static MMI_BOOL g_mmi_phb_in_edit, g_mmi_phb_in_new;
static U8 g_mmi_phb_sim_interface;
static U16 g_mmi_phb_active_index, g_mmi_phb_message;
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static mmi_phb_sos_number_struct g_mmi_phb_sos_list[MMI_PHB_SOS_NUMBER_COUNT];
static U8 *g_mmi_phb_display_list[SRV_PHB_XMGNT_SOS_ENTRIES + MMI_PHB_SOS_NUMBER_COUNT];
#endif
#if (MMI_MAX_SIM_NUM > 1)
static U32 hilited_extra_number;
#endif

static const cui_inline_item_text_edit_struct g_mmi_phb_inline_edit[] =
{
    {
        0,
        0,
        MMI_PHB_NAME_FIELD_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING,
    #if defined(__PHB_0x81_SUPPORT__)
        INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    #else
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    #endif
        NULL
    },
    {
        0,
        0,
        MMI_PHB_NUMBER_LENGTH + 1,
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
        0,
        NULL
    },
    {
        0,
        0,
        MMI_PHB_NUMBER_LENGTH + 1,
        IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
        0,
        NULL
    }
};
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP11__ */
#endif

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static const cui_inline_item_text_edit_struct g_mmi_phb_inline_name[] =
{
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    {
        0,
        0,
        MMI_PHB_NAME_FIELD_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
    },
    {
        0,
        0,
        MMI_PHB_NAME_FIELD_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
    }
#else /* __MMI_PHB_LAST_NAME_FIELD__ */
    {
        0,
        0,
        MMI_PHB_NAME_FIELD_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
    }
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */
};

#ifdef __MMI_PHB_OPTIONAL_FIELD__
static const cui_inline_item_text_edit_struct g_mmi_phb_inline_number[] =
{
    {
        0,
        0,
        MMI_PHB_NUMBER_LENGTH + 1,
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
        0,
        NULL
    },
    {
        0,
        0,
        MMI_PHB_COMPANY_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE,
        0,
        NULL
    },
    {
        0,
        0,
        MMI_PHB_NUMBER_LENGTH + 1,
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
        0,
        NULL
    },
    {
        0,
        0,
        MMI_PHB_NUMBER_LENGTH + 1,
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
        0,
        NULL
    }
};
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

#ifdef __MMI_PHB_OPTIONAL_FIELD__
static const cui_inline_item_text_edit_struct g_mmi_phb_inline_email[] =
{
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    {
        0,
        0,
        MMI_PHB_EMAIL_LENGTH + 1,
        IMM_INPUT_TYPE_EMAIL,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
    },
    {
        0,
        0,
        MMI_PHB_EMAIL_LENGTH + 1,
        IMM_INPUT_TYPE_EMAIL,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
    }
#else /* defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
    {
        0,
        0,
        MMI_PHB_EMAIL_LENGTH + 1,
        IMM_INPUT_TYPE_EMAIL,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
};
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
static const cui_inline_item_text_edit_struct g_mmi_phb_inline_group_name[] =
{
    {
        0,
        0,
        MMI_PHB_GROUP_NAME_LENGTH + 1,
        IMM_INPUT_TYPE_SENTENCE,
        0,
        NULL
    }
};

static const cui_inline_item_select_struct g_mmi_phb_inline_resource[] =
{
    {
        0,
        0,
        NULL
    },
    {
        0,
        0,
        NULL
    }
#if defined(__MMI_PHB_CALLER_VIDEO__)
    ,
    {
        0,
        0,
        NULL
    }
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
};
#endif /* __MMI_PHB_CALLER_GROUP__ */

static cui_inline_item_caption_struct extra_name_caption = 
{
    STR_ID_PHB_NAME
};
static cui_inline_item_caption_struct extra_number_caption = 
{
    STR_ID_PHB_NUMBER
};

static const cui_inline_set_item_struct g_mmi_phb_inline_extra_number[] =
{
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &extra_name_caption},
    #else
	{INLINE_ID_PHB_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &extra_name_caption},
	#endif
    {INLINE_ID_PHB_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[0]},
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_MOBILE_NUMBER, &extra_number_caption},
    #else
	{INLINE_ID_PHB_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &extra_number_caption},
	#endif
    {INLINE_ID_PHB_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[1]},
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_EXTRA_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &extra_name_caption},
    #else
	{INLINE_ID_PHB_EXTRA_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &extra_name_caption},
	#endif
    {INLINE_ID_PHB_EXTRA_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[0]},
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_EXTRA_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_MOBILE_NUMBER, &extra_number_caption},
    #else
	{INLINE_ID_PHB_EXTRA_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &extra_number_caption},
	#endif
    {INLINE_ID_PHB_EXTRA_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[2]}, //FDN
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_EXTRA_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &extra_name_caption},
    #else
	{INLINE_ID_PHB_EXTRA_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &extra_name_caption},
	#endif
    {INLINE_ID_PHB_EXTRA_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[0]},
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_EXTRA_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_MOBILE_NUMBER, &extra_number_caption},
    #else
	{INLINE_ID_PHB_EXTRA_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &extra_number_caption},
	#endif
    {INLINE_ID_PHB_EXTRA_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[2]}  //BDN
#endif
};
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static cui_inline_item_caption_struct my_name_caption = 
{
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    STR_ID_PHB_FIRST_NAME
#else
    STR_ID_PHB_NAME
#endif
};

#ifdef __MMI_PHB_LAST_NAME_FIELD__
static cui_inline_item_caption_struct my_name_caption2 = 
{
    STR_ID_PHB_LAST_NAME
};
#endif

static cui_inline_item_caption_struct my_number_caption = 
{
    STR_ID_PHB_MOBILE_NUMBER
};

#ifdef __MMI_PHB_OPTIONAL_FIELD__
static cui_inline_item_caption_struct my_home_caption = 
{
    STR_HOME_NUMBER
};
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
static cui_inline_item_caption_struct my_company_caption = 
{
    STR_COMPNAY_NAME
};
static cui_inline_item_caption_struct my_email_caption = 
{
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    STR_ID_PHB_EMAIL1_ADRESS
#else
    STR_EMAIL_ADRESS
#endif
};
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
static cui_inline_item_caption_struct my_email_caption2 = 
{
    STR_ID_PHB_EMAIL2_ADRESS
};
#endif
static cui_inline_item_caption_struct my_fax_caption = 
{
    STR_FAX_NUMBER
};
#else
static cui_inline_item_caption_struct my_email_caption = 
{
    STR_EMAIL_ADRESS
};
#endif
static cui_inline_item_caption_struct my_office_caption = 
{
    STR_OFFICE_NUMBER
};
#endif

static const cui_inline_set_item_struct g_mmi_phb_inline_my_number[] =
{
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_FIRST_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &my_name_caption},
    #else
	{INLINE_ID_PHB_FIRST_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &my_name_caption},
	#endif
    {INLINE_ID_PHB_FIRST_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_name[0]},
#ifdef __MMI_PHB_LAST_NAME_FIELD__
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_LAST_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &my_name_caption2},
    #else
	{INLINE_ID_PHB_LAST_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &my_name_caption2},
	#endif
    {INLINE_ID_PHB_LAST_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_name[1]},
#endif
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_MOBILE_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_MOBILE_NUMBER, &my_number_caption},
    #else
	{INLINE_ID_PHB_MOBILE_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &my_number_caption},
	#endif
    {INLINE_ID_PHB_MOBILE_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_edit[1]},
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    {INLINE_ID_PHB_HOME_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_HOME_NUMBER, &my_home_caption},
    {INLINE_ID_PHB_HOME_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_number[0]},
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    {INLINE_ID_PHB_COMPANY_NAME + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_COMPANY_NAME, &my_company_caption},
    {INLINE_ID_PHB_COMPANY_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_number[1]},
    {INLINE_ID_PHB_EMAIL_ADDR + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_EMAIL_ADDRESS, &my_email_caption},
    {INLINE_ID_PHB_EMAIL_ADDR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_email[0]},
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
#if 0
#ifndef __OP01__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
    {INLINE_ID_PHB_EMAIL_ADDR2 + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_EMAIL_ADDRESS, &my_email_caption2},
#endif
	{INLINE_ID_PHB_EMAIL_ADDR2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_email[1]},
#endif
    {INLINE_ID_PHB_OFFICE_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_OFFICE_NUMBER, &my_office_caption},
    {INLINE_ID_PHB_OFFICE_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_number[2]},
    {INLINE_ID_PHB_FAX_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_FAX_NUMBER, &my_fax_caption},
    {INLINE_ID_PHB_FAX_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_number[3]}
#else /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
    {INLINE_ID_PHB_OFFICE_NUMBER + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_OFFICE_NUMBER, &my_office_caption},
    {INLINE_ID_PHB_OFFICE_NUMBER, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, IMG_OFFICE_NUMBER, &g_mmi_phb_inline_number[2]},
    {INLINE_ID_PHB_EMAIL_ADDR + 100, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_EMAIL_ADDRESS, &my_email_caption},
    {INLINE_ID_PHB_EMAIL_ADDR, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, IMG_EMAIL_ADDRESS, &g_mmi_phb_inline_email[0]}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
};
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
static const cui_inline_item_caption_struct g_mmi_phb_inline_group_caption =
{
    STR_GRP_NAME_CAPTION
};

#if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
static const cui_inline_item_caption_struct g_mmi_phb_inline_group_caption1 =
{
    STR_ID_PHB_CALLER_PIC
};
#endif

static const cui_inline_item_caption_struct g_mmi_phb_inline_group_caption2 =
{
    STR_ID_PHB_CALLER_RING
};

#if defined(__MMI_PHB_CALLER_VIDEO__)
static const cui_inline_item_caption_struct g_mmi_phb_inline_group_caption3 =
{
    STR_ID_PHB_ASSOCIATE_VIDEO
};
#endif

static const cui_inline_set_item_struct g_mmi_phb_inline_group_editor[] =
{
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_GROUP_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &g_mmi_phb_inline_group_caption},
    #else
	{INLINE_ID_PHB_GROUP_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_phb_inline_group_caption},
	#endif
    {INLINE_ID_PHB_GROUP_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_group_name[0]}
#ifdef __MMI_PHB_CALLER_RES__
#if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
    ,
    {INLINE_ID_PHB_GROUP_PICTURE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_PICTURE, &g_mmi_phb_inline_group_caption1},
    {INLINE_ID_PHB_GROUP_PICTURE, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_mmi_phb_inline_resource[0]}
#endif
    ,
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_GROUP_RINGTONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_RING_TONE, &g_mmi_phb_inline_group_caption2},
    #else
	{INLINE_ID_PHB_GROUP_RINGTONE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_phb_inline_group_caption2},
	#endif
    {INLINE_ID_PHB_GROUP_RINGTONE, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_mmi_phb_inline_resource[1]}
#if defined(__MMI_PHB_CALLER_VIDEO__)
    ,
    {INLINE_ID_PHB_GROUP_VIDEO_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_ID_PHB_ASSOCIATE_VIDEO, &g_mmi_phb_inline_group_caption3},
    {INLINE_ID_PHB_GROUP_VIDEO, CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_mmi_phb_inline_resource[2]}
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
#endif
};

/*group manager change */
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
static const cui_inline_set_item_struct g_mmi_phb_inline_usim_group_editor[] =
{
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
    {INLINE_ID_PHB_GROUP_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_NAME, &g_mmi_phb_inline_group_caption},
    #else
	{INLINE_ID_PHB_GROUP_NAME_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_phb_inline_group_caption},
	#endif
    {INLINE_ID_PHB_GROUP_NAME, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_phb_inline_group_name[0]}
};
#endif
#endif /* __MMI_PHB_CALLER_GROUP__ */

static const cui_inline_struct g_mmi_phb_inline_screen =
{
    4,
    STR_GLOBAL_EDIT,
    IMG_SCR_PBOOK_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    &g_mmi_phb_inline_extra_number[0]
};

static const cui_inline_struct g_mmi_phb_inline_screen2 =
{
    4,
    STR_GLOBAL_EDIT,
    IMG_SCR_PBOOK_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    &g_mmi_phb_inline_extra_number[4]
};

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static const cui_inline_struct g_mmi_phb_inline_screen3 =
{
    4,
    STR_GLOBAL_EDIT,
    IMG_SCR_PBOOK_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    &g_mmi_phb_inline_extra_number[8]
};
#endif
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static const cui_inline_struct g_mmi_phb_inline_screen5 =
{
    sizeof(g_mmi_phb_inline_my_number) / sizeof(cui_inline_set_item_struct),
    STR_GLOBAL_EDIT,
    IMG_SCR_PBOOK_CAPTION,
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    &g_mmi_phb_inline_my_number[0]
};
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
static const cui_inline_struct g_mmi_phb_inline_screen6 =
{
    sizeof(g_mmi_phb_inline_group_editor) / sizeof(cui_inline_set_item_struct),
    STR_GLOBAL_EDIT,
    IMG_SCR_PBOOK_CAPTION,
#ifndef __MMI_PHB_UI_IN_TABS__
    CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
#else
    CUI_INLINE_SCREEN_DISABLE_DONE,
#endif
    NULL,
    &g_mmi_phb_inline_group_editor[0]
};

/* group manager change */
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__
static const cui_inline_struct g_mmi_phb_inline_screen7 =
{
    sizeof(g_mmi_phb_inline_usim_group_editor) / sizeof(cui_inline_set_item_struct),
    STR_GLOBAL_EDIT,
    IMG_SCR_PBOOK_CAPTION,
#ifndef __MMI_PHB_UI_IN_TABS__
    CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
#else
    CUI_INLINE_SCREEN_DISABLE_DONE,
#endif
    NULL,
    &g_mmi_phb_inline_usim_group_editor[0]
};
#endif
#endif /* __MMI_PHB_CALLER_GROUP__*/

typedef struct
{
    FuncPtr lsk_func;
    FuncPtr rsk_func;
} mmi_phb_confirm_data_struct;

typedef struct
{
    mmi_id sender_id;
    U16 name[MMI_PHB_NAME_LENGTH + 1];
    U16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    FuncPtr verify_cb;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__    
    WCHAR* title;
#endif
} mmi_phb_extra_number_cntx_struct;


#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
typedef struct
{
    mmi_id sender_id;
    U16 first_name[MMI_PHB_NAME_FIELD_LENGTH + 1];
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    U16 last_name[MMI_PHB_NAME_FIELD_LENGTH + 1];
#endif
    U16 mobile_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    U16 home_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U16 company_name[MMI_PHB_COMPANY_LENGTH + 1];
    U16 email_address[MMI_PHB_EMAIL_LENGTH + 1];
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    U16 email_address2[MMI_PHB_EMAIL_LENGTH + 1];
#endif
    U16 office_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U16 fax_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
} mmi_phb_my_number_cntx_struct;
static mmi_phb_my_number_cntx_struct *mmi_phb_my_number_p;
#endif

static mmi_phb_extra_number_cntx_struct *mmi_phb_extra_number_p; 
#ifdef __MMI_PHB_SPEED_DIAL__
static mmi_phb_extra_number_cntx_struct *mmi_phb_speed_dial_p;
#endif
static U8 mmi_phb_extra_type;

/*
 * Local Function
 */
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static void mmi_phb_extra_number_group_check(void);
#endif
static mmi_ret mmi_phb_entry_extra_number_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_extra_number_edit_proc(mmi_event_struct *evt);
static void mmi_phb_entry_extra_number_edit(U8 phb_type);
static mmi_ret mmi_phb_extra_sim_set_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_extra_select_mode_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_extra_number_list_option_proc(mmi_event_struct *evt);
static void mmi_phb_extra_number_make_call(void);

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
static mmi_ret mmi_phb_entry_owner_number_option_proc(mmi_event_struct *evt);
#if defined(__MMI_PHB_SOS_NUM_EDIT__)
static mmi_ret mmi_phb_entry_sos_edit_proc(mmi_event_struct *evt);
#endif
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

#if (MMI_MAX_SIM_NUM >= 2)
static sim_interface_enum mmi_phb_sim_menu_to_index(U16 phb_sim_menu_id);
static void mmi_phb_extra_number_select_sim_entry(U16 menu_id);
#endif

static void mmi_phb_extra_set_hint(U16 sender_id, U16 menu_id, U32 sim_index, phb_type_enum phb_type);
static mmi_sim_enum TO_MMI_SIM(U8 sim_interface);

static MMI_ID mmi_phb_entry_menu_cui_create(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id);


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_list_tap_callback
 * DESCRIPTION
 *  fte fdn list callback
 * PARAMETERS
 *  tap_type        [IN]        Hilite or not hilite
 *  index           [IN]        List index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_extra_number_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_extra_number_edit_pre_entry();
    }
}


#ifdef __MMI_PHB_SPEED_DIAL__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_list_tap_callback
 * DESCRIPTION
 *  fte speed dial list callback
 * PARAMETERS
 *  tap_type        [IN]        Hilite or not hilite
 *  index           [IN]        List index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_speed_dial_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_entry_speed_dial_select_contact();
    }
}
#endif


#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_owner_number_list_tap_callback
 * DESCRIPTION
 *  fte owner number list callback
 * PARAMETERS
 *  tap_type        [IN]        Hilite or not hilite
 *  index           [IN]        List index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_owner_number_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_entry_owner_number_edit_prepare();
    }
}
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_extra_number_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_entry_group_extra_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U16 menu_id = (U16) (U32) menu_evt->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__ 
            mmi_phb_mem_free(mmi_phb_extra_number_p->title);
        #endif
            mmi_phb_mem_free(mmi_phb_extra_number_p);
            break;

        case EVT_ID_GROUP_ACTIVE:
            if (mmi_frm_is_in_backward_scenario() && mmi_frm_scrn_get_count(GRP_ID_PHB_EXTRA_NUMBER) == 0)
            {
                mmi_frm_group_close(GRP_ID_PHB_EXTRA_NUMBER);
            }
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 700);
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, menu_id);
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, menu_evt->evt_id);
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, menu_evt->sender_id);
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, menu_evt->parent_menu_id);
            MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, menu_evt->highlighted_menu_id);
            switch(menu_id)
            {
                case MENU_ID_PHB_EXTRA_NUMBER:
                    mmi_phb_entry_extra_number_proc(evt);
                    break;

                case MENU9167_FIXED_DIAL:
                    mmi_phb_extra_sim_set_proc(evt);
                    break;

                case MENU_SETTING_FDL_MODE:
                    mmi_phb_extra_select_mode_proc(evt);
                    break;

                case MENU8234_FDL_VIEW_OPTIONS_MAIN:
                    mmi_phb_extra_number_list_option_proc(evt);
                    break;

            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                case MITEM105_OWNER_NUMBER_OPTIONS:
                    mmi_phb_entry_owner_number_option_proc(evt);
                    break;

                case MENU9168_BARRED_DAIL:
                    mmi_phb_extra_sim_set_proc(evt);
                    break;
            #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

                default:
                    break;
            }
            break;

    #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    #if defined(__MMI_PHB_SOS_NUM_EDIT__)
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FSEDITOR_CHANGED:
            mmi_phb_entry_sos_edit_proc(evt);
            break;
    #endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */
    #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
	#if 0		
    #ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
    #endif
    #endif
        case EVT_ID_CUI_INLINE_NOTIFY:
            mmi_phb_entry_extra_number_edit_proc(evt);
            break;

        case EVT_ID_CUI_VERIFY_RESULT:
        {
            cui_verify_result_evt_struct *result_evt = (cui_verify_result_evt_struct*)evt;
            if (result_evt->success)
            {
                if (mmi_phb_extra_number_p->verify_cb != NULL)
                {
                    mmi_phb_extra_number_p->verify_cb();
                }
            }
            cui_verify_close(result_evt->sender_id);
            break;
        }

        case EVT_ID_CUI_VERIFY_CANCEL:
        {
            cui_verify_cancel_evt_struct *cancel_evt = (cui_verify_cancel_evt_struct*)evt;
            cui_verify_close(cancel_evt->sender_id);
            break;
        }

        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

                mmi_phb_confirm_display_handle(alert_result);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_extra_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_extra_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_extra_number_p = mmi_phb_mem_malloc(
                                sizeof(mmi_phb_extra_number_cntx_struct),
                                SRV_PHB_MEMORY_TYPE_ADM);
    
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_phb_extra_number_p->title = (WCHAR *)mmi_phb_mem_malloc(sizeof(WCHAR) * MMI_PHB_MAX_DYNAMIC_SIM_NAME_LENGTH, SRV_PHB_MEMORY_TYPE_CTR);
#endif

#ifndef __MMI_MAINLCD_96X64__
    mmi_frm_group_create_ex(
        GRP_ID_PHB_SETTING,
        GRP_ID_PHB_EXTRA_NUMBER,
        mmi_phb_entry_group_extra_number_proc,
        mmi_phb_extra_number_p,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_EXTRA_NUMBER,
        mmi_phb_entry_group_extra_number_proc,
        mmi_phb_extra_number_p,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#endif

    mmi_phb_entry_extra_number();
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_extra_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_extra_number_entry_multiple_sim_list(mmi_menu_id parent_menu_id, MMI_MENU_ID highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_menu_id == MENU_ID_SELECT_SIM)
    {
        g_mmi_phb_sim_interface = mmi_phb_sim_menu_to_index(highlighted_menu_id);

    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (!srv_phb_startup_is_phb_support(g_mmi_phb_sim_interface, mmi_phb_extra_type)
        #if defined(__MMI_PHB_ECC_DIRECT_DIAL__) || defined(__MMI_PHB_SOS_NUM_EDIT__)
            && (mmi_phb_extra_type != PHB_ECC)
        #endif
            )
        {
            mmi_phb_popup_display_ext(STR_GLOBAL_UNAVAILABLE_SIM, MMI_EVENT_INFO);
        }
        else
    #endif
        {
            switch (hilited_extra_number)
            {
                case MENU9167_FIXED_DIAL:
                    mmi_phb_extra_sim_set_entry();
                    break;
                    
            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                case MITEM105_PBOOK_OWNER_NUMBER:
                    mmi_phb_get_extra_number_list_check();
                    break;
                    
                case MENU_PHONEBOOK_SERVICENUMBER:
                    mmi_phb_get_extra_number_list_check();
                    break;
                    
                case MITEM116_PBOOK_SOS_NUMBER:
                    mmi_phb_get_extra_number_list_check();
                    break;
                    
                case MENU9168_BARRED_DAIL:
                    mmi_phb_extra_sim_set_entry();
                    break;
              #endif
            }
        }
    }
#if 0	
#ifdef __OP11__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif
    else
    {
        hilited_extra_number = (U32)highlighted_menu_id;

        switch (hilited_extra_number)
        {
            case MENU9167_FIXED_DIAL:
                mmi_phb_extra_type = PHB_FDN;
                break;
                
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            case MITEM105_PBOOK_OWNER_NUMBER:
                mmi_phb_extra_type = PHB_MSISDN;
                break;
                
            case MENU_PHONEBOOK_SERVICENUMBER:
                mmi_phb_extra_type = PHB_SDN;
                break;
                
            case MITEM116_PBOOK_SOS_NUMBER:
                mmi_phb_extra_type = PHB_ECC;
                break;
                
            case MENU9168_BARRED_DAIL:
                mmi_phb_extra_type = PHB_BDN;
                break;
                
        #endif
            default:
                MMI_ASSERT(0);
                break;
        }
        mmi_phb_extra_number_select_sim_entry(hilited_extra_number);
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 710);
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, hilited_extra_number);
    }
}
#endif


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_check_sim_insert
 * DESCRIPTION
 *  find which sim insert when only insert one sim card
 * PARAMETERS
 *  void
 * RETURNS
 *  SIM index
 *****************************************************************************/
static U8 mmi_phb_extra_number_check_sim_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if(srv_sim_ctrl_is_inserted(MMI_SIM1 << i))
        {
            break;
        }
    }

    return (U8)i;
}
#endif


#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_extra_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_extra_number_entry_single_sim_list(MMI_MENU_ID highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (highlighted_menu_id == MENU9167_FIXED_DIAL)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        g_mmi_phb_sim_interface = mmi_phb_extra_number_check_sim_insert();
    #else
        g_mmi_phb_sim_interface = SIM1;
    #endif
        mmi_phb_extra_type = PHB_FDN;
        mmi_phb_extra_sim_set_entry();
    }
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    else if (highlighted_menu_id == MITEM105_PBOOK_OWNER_NUMBER)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        g_mmi_phb_sim_interface = mmi_phb_extra_number_check_sim_insert();
    #else
        g_mmi_phb_sim_interface = SIM1;
    #endif
        mmi_phb_extra_type = PHB_MSISDN;
        mmi_phb_get_extra_number_list_check();
    }
    else if (highlighted_menu_id == MENU_PHONEBOOK_SERVICENUMBER)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        g_mmi_phb_sim_interface = mmi_phb_extra_number_check_sim_insert();
    #else
        g_mmi_phb_sim_interface = SIM1;
    #endif
        mmi_phb_extra_type = PHB_SDN;
        mmi_phb_get_extra_number_list_check();
    }
    else if (highlighted_menu_id == MITEM116_PBOOK_SOS_NUMBER)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        g_mmi_phb_sim_interface = mmi_phb_extra_number_check_sim_insert();
    #else
        g_mmi_phb_sim_interface = SIM1;
    #endif
        mmi_phb_extra_type = PHB_ECC;
        mmi_phb_get_extra_number_list_check();
    }
    else if (highlighted_menu_id == MENU9168_BARRED_DAIL)
    {
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        g_mmi_phb_sim_interface = mmi_phb_extra_number_check_sim_insert();
    #else
        g_mmi_phb_sim_interface = SIM1;
    #endif
        mmi_phb_extra_type = PHB_BDN;
        mmi_phb_extra_sim_set_entry();
    }
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_extra_number_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_extra_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    sim_interface_enum sim_interface_id;
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;
#if (MMI_MAX_SIM_NUM >= 2) 
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    U16 string_id;
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            if (menu_evt->parent_menu_id == MENU_ID_PHB_EXTRA_NUMBER)
            {
            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                cui_menu_set_item_hidden(sender_id, MITEM105_PBOOK_OWNER_NUMBER, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU9168_BARRED_DAIL, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MENU_PHONEBOOK_SERVICENUMBER, MMI_TRUE);
                cui_menu_set_item_hidden(sender_id, MITEM116_PBOOK_SOS_NUMBER, MMI_TRUE);
            #endif

                for (sim_interface_id = SIM1; sim_interface_id < MMI_SIM_TOTAL; sim_interface_id++)
                {
                    if (srv_phb_startup_is_phb_support(sim_interface_id, PHB_FDN))
                    {
                        cui_menu_set_item_hidden(sender_id, MENU9167_FIXED_DIAL, MMI_FALSE);
                        break;
                    }
                    else
                    {
                        cui_menu_set_item_hidden(sender_id, MENU9167_FIXED_DIAL, MMI_TRUE);
                    }
                }

            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                for (sim_interface_id = SIM1; sim_interface_id < MMI_SIM_TOTAL; sim_interface_id++)
                {
                    if (srv_phb_startup_is_phb_support(sim_interface_id, PHB_MSISDN))
                    {
                        cui_menu_set_item_hidden(sender_id, MITEM105_PBOOK_OWNER_NUMBER, MMI_FALSE);
                        break;
                    }
                    else
                    {
                        cui_menu_set_item_hidden(sender_id, MITEM105_PBOOK_OWNER_NUMBER, MMI_TRUE);
                    }
                }

                for (sim_interface_id = SIM1; sim_interface_id < MMI_SIM_TOTAL; sim_interface_id++)
                {
                    if (srv_phb_startup_is_phb_support(sim_interface_id, PHB_BDN))
                    {
                        cui_menu_set_item_hidden(sender_id, MENU9168_BARRED_DAIL, MMI_FALSE);
                        break;
                    }
                    else
                    {
                        cui_menu_set_item_hidden(sender_id, MENU9168_BARRED_DAIL, MMI_TRUE);
                    }
                }
            
                for (sim_interface_id = SIM1; sim_interface_id < MMI_SIM_TOTAL; sim_interface_id++)
                {
                    if (srv_phb_startup_is_phb_support(sim_interface_id, PHB_SDN))
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_PHONEBOOK_SERVICENUMBER, MMI_FALSE);
                        break;
                    }
                    else
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_PHONEBOOK_SERVICENUMBER, MMI_TRUE);
                    }
                }

            #if !defined(__MMI_PHB_ECC_DIRECT_DIAL__) && !defined(__MMI_PHB_SOS_NUM_EDIT__)
                for (sim_interface_id = SIM1; sim_interface_id < MMI_SIM_TOTAL; sim_interface_id++)
                {
                    if (srv_phb_startup_is_phb_support(sim_interface_id, PHB_ECC))
                    {
                        cui_menu_set_item_hidden(sender_id, MITEM116_PBOOK_SOS_NUMBER, MMI_FALSE);
                        break;
                    }
                    else
                    {
                        cui_menu_set_item_hidden(sender_id, MITEM116_PBOOK_SOS_NUMBER, MMI_TRUE);
                    }
                }
            #else
               cui_menu_set_item_hidden(sender_id, MITEM116_PBOOK_SOS_NUMBER, MMI_FALSE);
            #endif
            #endif
            }
        #if (MMI_MAX_SIM_NUM >= 2)
            else if (menu_evt->parent_menu_id == MENU_ID_SELECT_SIM)
            {
                for (sim_interface_id = SIM1; sim_interface_id < MMI_SIM_TOTAL; sim_interface_id++)
                {
                    if (srv_phb_startup_is_phb_support(sim_interface_id, mmi_phb_extra_type)
                    #if defined(__MMI_PHB_ECC_DIRECT_DIAL__) || defined(__MMI_PHB_SOS_NUM_EDIT__)
                        || (mmi_phb_extra_type == PHB_ECC)
                    #endif
                        )
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SIM1 + sim_interface_id, MMI_FALSE);
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                        string_id = mmi_phb_sim_dynamic_name_string_index(sim_interface_id);
                        mmi_phb_sim_dynamic_name(MMI_SIM1 << sim_interface_id, sender_id, MENU_ID_PHB_SIM1 + sim_interface_id, string_id);
                    #endif
                    }
                    else
                    {
                        cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SIM1 + sim_interface_id, MMI_TRUE);
                    }
                } 
            }
        #endif
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        #if (MMI_MAX_SIM_NUM >= 2)
            if (menu_evt->parent_menu_id == MENU_ID_SELECT_SIM)
            {
                U32 sim_index = mmi_phb_sim_menu_to_index(highlighted_menu_id);

                switch (hilited_extra_number)
                {
                    case MENU9167_FIXED_DIAL:
                        mmi_phb_extra_set_hint(sender_id, highlighted_menu_id, sim_index, PHB_FDN);
						redraw_left_softkey();
						redraw_center_softkey();
					    redraw_right_softkey();
                        break;

                #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                    case MENU9168_BARRED_DAIL:
                        mmi_phb_extra_set_hint(sender_id, highlighted_menu_id, sim_index, PHB_BDN);
                        break;
                #endif
                }
            }
        #else
            mmi_phb_extra_set_hint(sender_id, MENU9167_FIXED_DIAL, SIM1, PHB_FDN);
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            mmi_phb_extra_set_hint(sender_id, MENU9168_BARRED_DAIL, SIM1, PHB_BDN);
        #endif
        #endif
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        #if (MMI_MAX_SIM_NUM >= 2)
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            if (1 == srv_sim_ctrl_get_num_of_inserted())
            {
                mmi_phb_extra_number_entry_single_sim_list(highlighted_menu_id);
            }
            else
        #endif
            {
                mmi_phb_extra_number_entry_multiple_sim_list(menu_evt->parent_menu_id, highlighted_menu_id);
            }
        #else
            mmi_phb_extra_number_entry_single_sim_list(highlighted_menu_id);
        #endif
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_menu_to_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static sim_interface_enum mmi_phb_sim_menu_to_index(U16 phb_sim_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sim_interface_enum sim_index = SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (phb_sim_menu_id)
    {
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_PHB_SIM4:
            sim_index = SIM4;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_PHB_SIM3:
            sim_index = SIM3;
            break;
    #endif

        case MENU_ID_PHB_SIM2:
            sim_index = SIM2;
            break;

        case MENU_ID_PHB_SIM1:
        default:
            sim_index = SIM1;
            break;
    }

    return sim_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_select_sim_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_select_sim_entry(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
    #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__                
        case MITEM105_PBOOK_OWNER_NUMBER:
            str_id = STR_MITEM105;
            break;
        case MENU_PHONEBOOK_SERVICENUMBER:
            str_id = STR_SDL_MAIN_MENU;
            break;
        case MITEM116_PBOOK_SOS_NUMBER:
            str_id = STR_SOS_MENU_ITEM;
            break;
    #endif            
        case MENU9167_FIXED_DIAL:
            str_id = STR_MENU9167_FIXED_DIAL;
            break;
    #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__            
        case MENU9168_BARRED_DAIL:
             str_id = STR_MENU9168_BARRED_DAIL;
             break;
    #endif             
    }

    mmi_phb_entry_menu_cui_generic_ext(
        GRP_ID_PHB_EXTRA_NUMBER,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_SELECT_SIM,
        str_id,
        (void*)(U32)MENU_ID_PHB_EXTRA_NUMBER);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_set_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sender_id   [IN]
 *  menu_id     [IN]
 *  phb_type    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_extra_set_hint(U16 sender_id, U16 menu_id, U32 sim_index, phb_type_enum phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_xmgnt_query_dial_mode(sim_index, phb_type) == 1)
    {
        str_id = STR_GLOBAL_ON;
    }
    else
    {
        str_id = STR_GLOBAL_OFF;
    }

    cui_menu_set_item_hint(sender_id, menu_id, (UI_string_type) GetString(str_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_extra_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_extra_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_EXTRA_NUMBER,
        MENU_ID_PHB_EXTRA_NUMBER,
        STR_ID_PHB_EXTRA_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_in_progress_ex
 * DESCRIPTION
 *  Draws the in-progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_in_progress_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_PHB_EXTRA_NUMBER,
            SCR_IN_PROGRESS_PHB,
            NULL,
            mmi_phb_entry_in_progress_ex,
            MMI_FRM_UNKNOW_SCRN))
    {
    #if 0
    #ifdef __MMI_MAINLCD_240X320__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* __MMI_MAINLCD_240X320__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_MAINLCD_240X320__ */
	#else
	ShowCategory8Screen(
            0xffff,
            0xffff,
            0,
            0,
            0,
            0,
            g_mmi_phb_message,
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);
	#endif

        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_show_in_progress_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_show_in_progress_ex(U16 msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_message = msg;
    mmi_phb_entry_in_progress_ex();
}


/*****************************************************************************
 * FUNCTION
 *  TO_MMI_SIM
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
static mmi_sim_enum TO_MMI_SIM(U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum mmi_sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_interface)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        case SIM2:
            mmi_sim = MMI_SIM2;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3:
            mmi_sim = MMI_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            mmi_sim = MMI_SIM4;
            break;
    #endif

    	case SIM1:
        default:
            mmi_sim = MMI_SIM1;
            break;
    }

    return mmi_sim;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item                [IN]        
 *  hint                [IN]        
 *  index               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_get_item(U8 **item, U8 **hint, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wcslen(srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, index)))
    {
        *item = (PU8) srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, index);
        if (mmi_wcslen(srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, index)))
        {
            *hint = (PU8) srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, index);
        }
        else
        {
            *hint = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }
    else
    {
        if (mmi_wcslen(srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, index)))
        {
            *item = (PU8) srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, index);
        }
        else
        {
            *item = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
        }
        *hint = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_get_item_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item                [IN]        
 *  hint                [IN]        
 *  icon                [IN]        
 *  index               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_get_item_ex(U8 **item, U8 **hint, U16 *icon, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wcslen(srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, index)))
    {
        *item = (PU8) srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, index);
        *hint = (PU8) srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, index);
    }
    else
    {
        *item = (PU8) srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, index);
        *hint = NULL;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    if (g_mmi_phb_sim_interface == SIM1)
    {
        *icon = (U16) IMG_GLOBAL_SIM1;
    }
    else if (g_mmi_phb_sim_interface == SIM2)
    {
        *icon = (U16) IMG_GLOBAL_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (g_mmi_phb_sim_interface == SIM3)
    {
        *icon = (U16) IMG_GLOBAL_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (g_mmi_phb_sim_interface == SIM4)
    {
        *icon = (U16) IMG_GLOBAL_SIM4;
    }
#endif
#else /* MMI_MAX_SIM_NUM >= 2 */
    *icon = (U16) IMG_STORAGE_SIM;
#endif /* MMI_MAX_SIM_NUM >= 2 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_active_index = (U16) index;
}

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
#define MMI_PHB_OWNER_NUMBER
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sc_owner_number_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sc_owner_number_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_phb_extra_number_group_check();

    hilited_extra_number = MITEM105_PBOOK_OWNER_NUMBER;
    mmi_phb_extra_number_select_sim_entry(hilited_extra_number);
#else
    g_mmi_phb_sim_interface = SIM1;
    mmi_phb_get_extra_number_list_check();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_owner_number_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_owner_number_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_handle = srv_phb_xmgnt_get_list(
                            g_mmi_phb_sim_interface,
                            PHB_MSISDN,
                            mmi_phb_get_owner_number_list_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_owner_number_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_owner_number_list_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_in_operation)
    {
        if (g_mmi_phb_in_edit)
        {
            cui_inline_close(mmi_phb_extra_number_p->sender_id);
        }
        g_mmi_phb_in_edit = MMI_FALSE;
        g_mmi_phb_in_operation = MMI_FALSE;
    }
    else if (srv_phb_xmgnt_get_list_count(g_mmi_phb_handle) != 0)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_IN_PROGRESS_PHB)
        {
        #if defined(__MMI_PHB_ALS_SUPPORT__)
            if ((srv_callset_line_switch_get_id(TO_MMI_SIM(g_mmi_phb_sim_interface)) == SRV_CALLSET_LINE2)
                && (srv_phb_xmgnt_get_list_count(g_mmi_phb_handle) == 1)
                )
            {
                mmi_phb_popup_display_ext(
                    STR_NO_OWNER_NUMBER_MESSAGE,
                    MMI_EVENT_FAILURE);
            }
            else
        #endif /* defined(__MMI_PHB_ALS_SUPPORT__) */
            {
                mmi_phb_entry_owner_number();
            }
        }
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_NO_OWNER_NUMBER_MESSAGE,
            MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *item_list[SRV_PHB_XMGNT_OWNER_NUMBERS], *hint_list[SRV_PHB_XMGNT_OWNER_NUMBERS];
    S32 num_of_items;
    U16 i, str_id = 0;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        GRP_ID_PHB_EXTRA_NUMBER,
	    SCR_OWNER_NUMBERS,
        NULL,
		mmi_phb_entry_owner_number,
		MMI_FRM_FULL_SCRN))
	{
    	return;
	}
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
#if 0
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
#endif
#endif

    num_of_items = srv_phb_xmgnt_get_list_count(g_mmi_phb_handle);
    MMI_ASSERT(num_of_items <= SRV_PHB_XMGNT_OWNER_NUMBERS);

#if defined(__MMI_PHB_ALS_SUPPORT__)
    num_of_items = 1;

    i = srv_callset_line_switch_get_id(TO_MMI_SIM(g_mmi_phb_sim_interface));
    if (i != SRV_CALLSET_LINE1 && i != SRV_CALLSET_LINE2)
    {
        i = SRV_CALLSET_LINE1;
    }
    mmi_phb_extra_number_get_item(&item_list[0], &hint_list[0], (U16) (i - SRV_CALLSET_LINE1));

    g_mmi_phb_active_index = (U16) (i - SRV_CALLSET_LINE1);
#else /* defined(__MMI_PHB_ALS_SUPPORT__) */

#if 0 /* phase out */
#if defined(__MMI_PHB_DISPLAY_ONE_MSISDN__)
/* under construction !*/
#endif 
#endif

    for (i = 0; i < num_of_items; i++)
    {
        mmi_phb_extra_number_get_item(&item_list[i], &hint_list[i], i);
    }

    RegisterHighlightHandler(mmi_phb_extra_number_highlight_hdlr);
#endif /* defined(__MMI_PHB_ALS_SUPPORT__) */

#ifndef __MMI_WGUI_DISABLE_CSK__  
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif 	

    switch (g_mmi_phb_sim_interface)
    {
        case SIM1:
        #if (MMI_MAX_SIM_NUM == 1)
            str_id = STR_MITEM105;
        #else
            str_id = STRING_MTPNP_SIM1_OWNER_NUMBER;
            break;
        case SIM2:
            str_id = STRING_MTPNP_OWNER_NUMBER;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3:
            str_id = STRING_MTPNP_SIM3_OWNER_NUMBER;
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            str_id = STRING_MTPNP_SIM4_OWNER_NUMBER;
            break;
    #endif
        #endif
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (1 == srv_sim_ctrl_get_num_of_inserted())
    {
        str_id = STR_MITEM105; 
    }
    mmi_phb_sim_dynamic_name_simx_title(
        MMI_SIM1 << g_mmi_phb_sim_interface,
        0,
        str_id,
        mmi_phb_extra_number_p->title);
    ShowCategory353Screen(
        (U8*)mmi_phb_extra_number_p->title,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        item_list,
        (U16*) gIndexIconsImageList,
        hint_list,
        0,
        0,
        gui_buffer);
#else
    ShowCategory53Screen(
        str_id,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        item_list,
        (U16*) gIndexIconsImageList,
        hint_list,
        0,
        0,
        gui_buffer);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    SetCenterSoftkeyFunction(mmi_phb_entry_owner_number_edit_prepare, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_phb_entry_owner_number_option, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_owner_number_list_tap_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_owner_number_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MITEM1052_OWNER_NUMBER_EDIT:
                    mmi_phb_entry_owner_number_edit_prepare();
                    break;

                case MITEM1051_OWNER_NUMBER_ERASE:
                    mmi_phb_entry_owner_number_erase_confirm();
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_EXTRA_NUMBER,
        MITEM105_OWNER_NUMBER_OPTIONS,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_edit_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_edit_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(
        mmi_phb_extra_number_p->name,
        srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, g_mmi_phb_active_index));
    mmi_wcscpy(
        mmi_phb_extra_number_p->number,
        srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, g_mmi_phb_active_index));
    mmi_phb_entry_owner_number_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_extra_number_edit(PHB_MSISDN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_owner_number_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_owner_number_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *number = mmi_phb_extra_number_p->number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(mmi_phb_extra_number_p->sender_id, INLINE_ID_PHB_NAME, mmi_phb_extra_number_p->name);
    cui_inline_get_value(mmi_phb_extra_number_p->sender_id, INLINE_ID_PHB_NUMBER, number);

    if (!srv_phb_check_valid_number(number) ||
        mmi_wcsstr(number, L"w") || mmi_wcsstr(number, L"W"))
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_INVALID_NUMBER, MMI_EVENT_FAILURE);
        return;
    }

    mmi_phb_edit_owner_number_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_owner_number_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_owner_number_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_in_operation = MMI_TRUE;

    /* When the length of owner number is longer than 20, it should be deleted from EFext1 first. */
    if (srv_phb_xmgnt_get_entry_number_length(g_mmi_phb_handle, g_mmi_phb_active_index) > 20)
    {
        if (!g_mmi_phb_in_edit)
        {
            g_mmi_phb_in_edit = MMI_TRUE;
            mmi_phb_show_in_progress_ex(STR_GLOBAL_SAVING);
            mmi_phb_erase_owner_number_req();
            return;
        }
    }
    else
    {
        g_mmi_phb_in_edit = MMI_TRUE;
        mmi_phb_show_in_progress_ex(STR_GLOBAL_SAVING);
    }

    srv_phb_xmgnt_set_entry(
        g_mmi_phb_sim_interface,
        PHB_MSISDN,
        0xFFFF,
        srv_phb_xmgnt_get_entry_index(g_mmi_phb_handle, g_mmi_phb_active_index),
        mmi_phb_extra_number_p->name,
        mmi_phb_extra_number_p->number,
        mmi_phb_edit_owner_number_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_owner_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_owner_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        mmi_phb_get_owner_number_list_req();
    }
    else
    {
        if (result == SRV_PHB_XMGNT_RESULT_EF_FULL)
        {
            mmi_phb_popup_display_ext(STR_NOT_SAVED_NUMBER_TOO_LONG, MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
        g_mmi_phb_in_edit = MMI_FALSE;
        g_mmi_phb_in_operation = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_owner_number_erase_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_owner_number_erase_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wcslen(srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, g_mmi_phb_active_index)) ||
        mmi_wcslen(srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, g_mmi_phb_active_index)))
    {
        mmi_phb_confirm_display_ext(
            STR_GLOBAL_DELETE_ASK,
            GRP_ID_PHB_EXTRA_NUMBER,
            mmi_phb_erase_owner_number_req,
            mmi_frm_scrn_close_active_id,
            MMI_TRUE);
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_erase_owner_number_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_erase_owner_number_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_phb_in_edit)
    {
        g_mmi_phb_in_operation = MMI_TRUE;
        mmi_phb_show_in_progress_ex(STR_GLOBAL_DELETING);
    }

    srv_phb_xmgnt_delete_entry(
        g_mmi_phb_sim_interface,
        PHB_MSISDN,
        0xFFFF,
        srv_phb_xmgnt_get_entry_index(g_mmi_phb_handle, g_mmi_phb_active_index),
        mmi_phb_erase_owner_number_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_erase_owner_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_erase_owner_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        if (g_mmi_phb_in_edit)
        {
            mmi_phb_edit_owner_number_req();
        }
        else
        {
            mmi_phb_get_owner_number_list_req();
        }
    }
    else
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
        mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
        g_mmi_phb_in_edit = MMI_FALSE;
        g_mmi_phb_in_operation = MMI_FALSE;
    }
}


#define MMI_PHB_SDN_LIST
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_sdn_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_sdn_list_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_xmgnt_get_list_count(g_mmi_phb_handle) != 0)
    {
        mmi_phb_entry_sdn_list();
    }
    else
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_NOT_SUPPORTED, MMI_EVENT_FAILURE);
    }
    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sdn_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sdn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *item_list[SRV_PHB_XMGNT_SIM_ENTRIES], *hint_list[SRV_PHB_XMGNT_SIM_ENTRIES];
    U16 icon_list[SRV_PHB_XMGNT_SIM_ENTRIES];
    S32 num_of_items;
    U16 i, lsk_id = 0, str_id = 0;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, SCR_SDN_LIST, NULL, mmi_phb_entry_sdn_list, MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    num_of_items = srv_phb_xmgnt_get_list_count(g_mmi_phb_handle);
    MMI_ASSERT(num_of_items <= SRV_PHB_XMGNT_SIM_ENTRIES);

    for (i = 0; i < num_of_items; ++i)
    {
        mmi_phb_extra_number_get_item_ex(&item_list[i], &hint_list[i], &icon_list[i], i);
    }

    RegisterHighlightHandler(mmi_phb_extra_number_highlight_hdlr);

    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_is_usable(TO_MMI_SIM(g_mmi_phb_sim_interface)))
    {
        lsk_id = STR_GLOBAL_DIAL;
    }
#else /* MMI_MAX_SIM_NUM >= 2 */
    lsk_id = STR_GLOBAL_DIAL;
#endif /* MMI_MAX_SIM_NUM >= 2 */
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    switch (g_mmi_phb_sim_interface)
    {
        case SIM1:
        #if (MMI_MAX_SIM_NUM == 1)
            str_id = STR_SDL_MAIN_MENU;
        #else
            str_id = STRING_MTPNP_SIM1_SDL_NUMBER;
            break;
        case SIM2:
            str_id = STRING_MTPNP_SDL_NUMBER;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3:
            str_id = STR_ID_PHB_SIM3_SDL_NUMBER;
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            str_id = STR_ID_PHB_SIM4_SDL_NUMBER;
            break;
    #endif
        #endif
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (1 == srv_sim_ctrl_get_num_of_inserted())
    {
        str_id = STR_SDL_MAIN_MENU; 
    }
    mmi_phb_sim_dynamic_name_simx_title(
        MMI_SIM1 << g_mmi_phb_sim_interface,
        0,
        str_id,
        mmi_phb_extra_number_p->title);
    ShowCategory353Screen(
        (U8*)mmi_phb_extra_number_p->title,
        IMG_SCR_PBOOK_CAPTION,
        lsk_id,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        item_list,
        icon_list,
        hint_list,
        0,
        0,
        gui_buffer);
#else
    ShowCategory53Screen(
        str_id,
        IMG_SCR_PBOOK_CAPTION,
        lsk_id,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        item_list,
        icon_list,
        hint_list,
        0,
        0,
        gui_buffer);
#endif

    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
#if (MMI_MAX_SIM_NUM >= 2)
        if (srv_nw_usab_is_usable(TO_MMI_SIM(g_mmi_phb_sim_interface)))
        {
            SetLeftSoftkeyFunction(mmi_phb_extra_number_make_call, KEY_EVENT_UP);
            SetKeyHandler(mmi_phb_extra_number_make_call, KEY_SEND, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_phb_extra_number_make_call, KEY_EVENT_UP);
        }
#else /* MMI_MAX_SIM_NUM >= 2 */
        SetLeftSoftkeyFunction(mmi_phb_extra_number_make_call, KEY_EVENT_UP);
        SetKeyHandler(mmi_phb_extra_number_make_call, KEY_SEND, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_extra_number_make_call, KEY_EVENT_UP);
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    }
    else
    {
        ChangeCenterSoftkey(0, 0);
    }
}


#define MMI_PHB_SOS_LIST
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_sos_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  notify_ecc      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_read_sos_list(U8 notify_ecc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_SOS_NUMBER_COUNT; i++)
    {
        ReadRecord(NVRAM_EF_PHB_SOS_LID, (U16) (i + 1), &g_mmi_phb_sos_list[i], NVRAM_EF_PHB_SOS_SIZE, &error);

        if (notify_ecc)
        {
            ecc_custom_update_emergency_number(
                (U8*) g_mmi_phb_sos_list[i].number,
                ECC_ENCODING_UCS2,
                ECC_SRC_NVRAM,
                0,
                NULL,
                (U8) (i + 1),
                MMI_PHB_SOS_NUMBER_COUNT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_write_sos_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_write_sos_list(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_PHB_SOS_LID, (U16) (index + 1), &g_mmi_phb_sos_list[index], NVRAM_EF_PHB_SOS_SIZE, &error);

    ecc_custom_update_emergency_number(
        (U8*) g_mmi_phb_sos_list[index].number,
        ECC_ENCODING_UCS2,
        ECC_SRC_NVRAM,
        0,
        NULL,
        (U8) (index + 1),
        MMI_PHB_SOS_NUMBER_COUNT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_read_sos_list(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_sos_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_sos_list_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_sos_list();
    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_SOS_NUM_EDIT__)
    U16 sim_list_count;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_active_index = (U16) index;

#if defined(__MMI_PHB_SOS_NUM_EDIT__)
    sim_list_count = srv_phb_xmgnt_get_list_count(g_mmi_phb_handle);

    if (g_mmi_phb_active_index < sim_list_count)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, IMG_NONE);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_entry_sos_edit_prepare, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_entry_sos_edit_prepare, KEY_EVENT_UP);
    }
#else /* defined(__MMI_PHB_SOS_NUM_EDIT__) */
    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_nw_usab_is_usable(TO_MMI_SIM(g_mmi_phb_sim_interface)))
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_sos_make_call, KEY_EVENT_UP);
        }
        else
        {
            ChangeCenterSoftkey(0, IMG_NONE);
        }
    #else /* MMI_MAX_SIM_NUM >= 2 */
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_phb_sos_make_call, KEY_EVENT_UP);
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    }
    else
    {
        ChangeCenterSoftkey(0, IMG_NONE);
    }
#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sos_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *hint_list[MMI_PHB_SOS_NUMBER_COUNT + SRV_PHB_XMGNT_SOS_ENTRIES];
    S32 num_of_items = 0;
    U16 i, lsk_id = 0;
    U16 sim_list_count, str_id = 0;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_read_sos_list(MMI_FALSE);

    sim_list_count = srv_phb_xmgnt_get_list_count(g_mmi_phb_handle);
    MMI_ASSERT(sim_list_count <= SRV_PHB_XMGNT_SOS_ENTRIES);

    for (i = 0; i < sim_list_count; ++i)
    {
        g_mmi_phb_display_list[num_of_items] = (U8*) srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, i);

    #if (MMI_MAX_SIM_NUM >= 2)
        if (g_mmi_phb_sim_interface == SIM1)
        {
            hint_list[num_of_items++] = (U8*) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM1);
        }
        else if (g_mmi_phb_sim_interface == SIM2)
        {
            hint_list[num_of_items++] = (U8*) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM2);
        }
     #if (MMI_MAX_SIM_NUM >= 3)
        else if (g_mmi_phb_sim_interface == SIM3)
        {
            hint_list[num_of_items++] = (U8*) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM3);
        }
     #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        else if (g_mmi_phb_sim_interface == SIM4)
        {
            hint_list[num_of_items++] = (U8*) GetString(STRING_MTPNP_PHB_SOSLIST_INSIM4);
        }
     #endif
    #else /* MMI_MAX_SIM_NUM >= 2 */
        hint_list[num_of_items++] = (U8*) GetString(STR_ID_PHB_SOSLIST_INSIM);
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    }

#if defined(__MMI_PHB_ECC_DIRECT_DIAL__) && !defined(__MMI_PHB_SOS_NUM_EDIT__)
    if (sim_list_count == 0)
    {
        U8 *ecc_num_1, *ecc_num_2;

        ecc_custom_get_first_2_default_num(&ecc_num_1, &ecc_num_2);

        g_mmi_phb_display_list[num_of_items++] = (U8*) ecc_num_1;
        hint_list[0] = NULL;
        g_mmi_phb_display_list[num_of_items++] = (U8*) ecc_num_2;
        hint_list[1] = NULL;
    }
#endif /* defined(__MMI_PHB_ECC_DIRECT_DIAL__) && !defined(__MMI_PHB_SOS_NUM_EDIT__) */

    for (i = 0; i < MMI_PHB_SOS_NUMBER_COUNT; ++i)
    {
        if (g_mmi_phb_sos_list[i].length == 0xFF || g_mmi_phb_sos_list[i].length == 0)
        {
        #if defined(__MMI_PHB_SOS_NUM_EDIT__)
            g_mmi_phb_display_list[num_of_items] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
            hint_list[num_of_items++] = (U8*) GetString(STR_SOSLIST_NVRAM);
        #endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */
        }
        else
        {
            g_mmi_phb_display_list[num_of_items] = (U8*) g_mmi_phb_sos_list[i].number;
            hint_list[num_of_items++] = (U8*) GetString(STR_SOSLIST_NVRAM);
        }
    }

#if !defined(__MMI_PHB_SOS_NUM_EDIT__)
    if (num_of_items == 0)
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE);
        return;
    }
#endif /* !defined(__MMI_PHB_SOS_NUM_EDIT__) */

    mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, SCR_SOS_DISPLAY, NULL, mmi_phb_entry_sos_list, MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_phb_sos_list_highlight_hdlr);
    EnableCenterSoftkey(0, IMG_NONE);

#if defined(__MMI_PHB_SOS_NUM_EDIT__)
    ShowCategory53Screen(
        STR_SOS_MENU_ITEM,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        g_mmi_phb_display_list,
        (U16*) gIndexIconsImageList,
        hint_list,
        0,
        0,
        gui_buffer);
#else /* defined(__MMI_PHB_SOS_NUM_EDIT__) */
    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_is_usable(TO_MMI_SIM(g_mmi_phb_sim_interface)))
    {
        lsk_id = STR_GLOBAL_DIAL;
    }
#else /* MMI_MAX_SIM_NUM >= 2 */
    lsk_id = STR_GLOBAL_DIAL;
#endif /* MMI_MAX_SIM_NUM >= 2 */
    }

    switch (g_mmi_phb_sim_interface)
    {
        case SIM1:
        #if (MMI_MAX_SIM_NUM == 1)
            str_id = STR_SOS_MENU_ITEM;
        #else
            str_id = STRING_MTPNP_SIM1_SOS_NUMBER;
            break;
        case SIM2:
            str_id = STRING_MTPNP_SOS_NUMBER;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SIM3:
            str_id = STR_ID_PHB_SIM3_SOS_NUMBER;
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case SIM4:
            str_id = STR_ID_PHB_SIM4_SOS_NUMBER;
            break;
    #endif
    #endif
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (1 == srv_sim_ctrl_get_num_of_inserted())
    {
        str_id = STR_SOS_MENU_ITEM; 
    }
    mmi_phb_sim_dynamic_name_simx_title(
        MMI_SIM1 << g_mmi_phb_sim_interface,
        0,
        str_id,
        mmi_phb_extra_number_p->title);
    ShowCategory353Screen(
        (U8*)mmi_phb_extra_number_p->title,
        IMG_SCR_PBOOK_CAPTION,
        lsk_id,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        g_mmi_phb_display_list,
        (U16*) gIndexIconsImageList,
        hint_list,
        0,
        0,
        gui_buffer);
#else
    ShowCategory53Screen(
        str_id,
        IMG_SCR_PBOOK_CAPTION,
        lsk_id,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        g_mmi_phb_display_list,
        (U16*) gIndexIconsImageList,
        hint_list,
        0,
        0,
        gui_buffer);
#endif

    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_is_usable(TO_MMI_SIM(g_mmi_phb_sim_interface)))
    {
        SetLeftSoftkeyFunction(mmi_phb_sos_make_call, KEY_EVENT_UP);
    }
#else /* MMI_MAX_SIM_NUM >= 2 */
    SetLeftSoftkeyFunction(mmi_phb_sos_make_call, KEY_EVENT_UP);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    }
#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */

    if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
    {
#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_nw_usab_is_usable(TO_MMI_SIM(g_mmi_phb_sim_interface)))
    {
        SetKeyHandler(mmi_phb_sos_make_call, KEY_SEND, KEY_EVENT_UP);
    }
#else /* MMI_MAX_SIM_NUM >= 2 */
    SetKeyHandler(mmi_phb_sos_make_call, KEY_SEND, KEY_EVENT_UP);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sos_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sos_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (g_mmi_phb_sim_interface == SIM2)
    {
        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (g_mmi_phb_sim_interface == SIM3)
    {
        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (g_mmi_phb_sim_interface == SIM4)
    {
        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
    }
#endif
#endif

    mmi_phb_call_launch_ex(
        NULL,
        (U16*) g_mmi_phb_display_list[g_mmi_phb_active_index], 
        call_type);
}

#if defined(__MMI_PHB_SOS_NUM_EDIT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_edit_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sos_edit_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2cmp((CHAR*) g_mmi_phb_display_list[g_mmi_phb_active_index], (CHAR*) GetString(STR_GLOBAL_EMPTY_LIST)))
    {
        memset(mmi_phb_extra_number_p->number, 0, ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((CHAR*) mmi_phb_extra_number_p->number, (CHAR*) g_mmi_phb_display_list[g_mmi_phb_active_index]);
    }
    mmi_phb_entry_sos_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_edit_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_sos_edit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
            cui_fseditor_get_text(
                mmi_phb_extra_number_p->sender_id,
                mmi_phb_extra_number_p->number,
                (MMI_PHB_NUMBER_PLUS_LENGTH + 1) * ENCODING_LENGTH);
            mmi_phb_save_sos_number();
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(mmi_phb_extra_number_p->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_sos_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_sos_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_id = cui_fseditor_create(GRP_ID_PHB_EXTRA_NUMBER);

    mmi_phb_extra_number_p->sender_id = editor_id;

    cui_fseditor_set_title(editor_id, STR_DISPLAY_SOS_CAPTION, IMG_SCR_PBOOK_CAPTION);
    cui_fseditor_set_softkey_text(editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
    cui_fseditor_set_softkey_icon(editor_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    cui_fseditor_set_text(
        editor_id,
        mmi_phb_extra_number_p->number,
        (MMI_PHB_NUMBER_PLUS_LENGTH + 1) * ENCODING_LENGTH,
        MMI_PHB_SOS_NUMBER_LENGTH);
    cui_fseditor_set_input_method(
        editor_id,
        IMM_INPUT_TYPE_NUMERIC,
        NULL,
        0);
    cui_fseditor_run(editor_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_sos_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_save_sos_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sim_list_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_list_count = srv_phb_xmgnt_get_list_count(g_mmi_phb_handle);
    MMI_ASSERT(sim_list_count <= SRV_PHB_XMGNT_SOS_ENTRIES);

    mmi_wcscpy(g_mmi_phb_sos_list[g_mmi_phb_active_index - sim_list_count].number, mmi_phb_extra_number_p->number);
    g_mmi_phb_sos_list[g_mmi_phb_active_index - sim_list_count].length =
        (U8) mmi_wcslen(mmi_phb_extra_number_p->number);
    g_mmi_phb_sos_list[g_mmi_phb_active_index - sim_list_count].type = 0x81;

    mmi_phb_write_sos_list((U16) (g_mmi_phb_active_index - sim_list_count));
    cui_fseditor_close(mmi_phb_extra_number_p->sender_id);

    mmi_phb_popup_display_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
}

#endif /* defined(__MMI_PHB_SOS_NUM_EDIT__) */
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sc_owner_number_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sc_owner_number_entry(void)
{
    mmi_phb_popup_display_ext(STR_GLOBAL_NOT_SUPPORTED, MMI_EVENT_FAILURE);
}
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
#define MMI_PHB_FDN_LIST

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_group_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_phb_extra_number_group_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_PHB_EXTRA_NUMBER))
    {
        mmi_phb_extra_number_p = mmi_phb_mem_malloc(
                                    sizeof(mmi_phb_extra_number_cntx_struct),
                                    SRV_PHB_MEMORY_TYPE_ADM);

        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_PHB_EXTRA_NUMBER,
            mmi_phb_entry_group_extra_number_proc,
            mmi_phb_extra_number_p,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_is_support
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static MMI_BOOL mmi_phb_extra_number_is_support(U32 sim_index, U8 phb_type, MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_support(sim_index, phb_type))
    {
        return MMI_TRUE;
    }
    else
    {
        if (is_popup)
        {
            mmi_phb_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE);
        }

        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_extra_number_edit_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_extra_number_edit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            {
                cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*) evt;
                U16 item_id = submit_evt->item_id;

                if (item_id == INLINE_ID_PHB_EXTRA_NAME || item_id == INLINE_ID_PHB_EXTRA_NUMBER)
                {
                    mmi_phb_edit_extra_number_check();
                }
            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                else if (item_id == INLINE_ID_PHB_NAME || item_id == INLINE_ID_PHB_NUMBER)
                {
                    mmi_phb_edit_owner_number_check();
                }
			#if 0	
            #ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_PHB_ICE_CONTACT__ */
			#endif
            #endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*) evt;
                cui_inline_close(abort_evt->sender_id);
            }
            break;
    #if 0
    #ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_PHB_ICE_CONTACT__ */
	#endif
    #if 0
    #ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_PHB_ICE_CONTACT__ */
	#endif

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_extra_number_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phb_type    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_extra_number_edit(U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;
    U16 *name = mmi_phb_extra_number_p->name;
    U16 *number = mmi_phb_extra_number_p->number;
    U32 length = srv_phb_startup_get_alpha_length(g_mmi_phb_sim_interface, phb_type) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (phb_type)
    {
        case PHB_MSISDN:
            inline_id = cui_inline_create(GRP_ID_PHB_EXTRA_NUMBER, &g_mmi_phb_inline_screen);
            cui_inline_set_text_len(inline_id, INLINE_ID_PHB_NAME, length);
            cui_inline_set_value(inline_id, INLINE_ID_PHB_NAME, name);
            cui_inline_set_value(inline_id, INLINE_ID_PHB_NUMBER, number);
            break;

        case PHB_FDN:
        case PHB_BDN:
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            if (phb_type == PHB_BDN)
            {
                inline_id = cui_inline_create(GRP_ID_PHB_EXTRA_NUMBER, &g_mmi_phb_inline_screen3);
            }
            else
        #endif
            {
                inline_id = cui_inline_create(GRP_ID_PHB_EXTRA_NUMBER, &g_mmi_phb_inline_screen2);
            }
            cui_inline_set_text_len(inline_id, INLINE_ID_PHB_EXTRA_NAME, length);
            cui_inline_set_value(inline_id, INLINE_ID_PHB_EXTRA_NAME, name);
            cui_inline_set_value(inline_id, INLINE_ID_PHB_EXTRA_NUMBER, number);
            break;

        default:
            MMI_ASSERT(0);
            return;
    }
    mmi_phb_extra_number_p->sender_id = inline_id;
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_fdn_number_add_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_extra_number_prepare(MMI_BOOL is_new, U8 extra_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name = mmi_phb_extra_number_p->name;
    U16 *number = mmi_phb_extra_number_p->number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_new)
    {
        g_mmi_phb_in_new = MMI_TRUE;
        name[0] = '\0';
        number[0] = '\0';
    }
    else
    {
        g_mmi_phb_in_new = MMI_FALSE;
        mmi_wcscpy(
            name,
            srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, g_mmi_phb_active_index));
        mmi_wcscpy(
            number,
            srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, g_mmi_phb_active_index));
    }

    mmi_phb_entry_extra_number_edit(extra_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_option_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_extra_number_option_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_EXTRA_NUMBER,
        MENU8234_FDL_VIEW_OPTIONS_MAIN,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_get_title_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_phb_extra_get_title_str_id(U32 extra_type, U32 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;
#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    const U16 extra_string[2][MMI_SIM_TOTAL] = 
#else
    const U16 extra_string[1][MMI_SIM_TOTAL] = 
#endif
    {
        {
            STRING_MTPNP_MASTER_FIXED_DIAL
            ,STRING_MTPNP_SLAVE_FIXED_DIAL
        #if (MMI_MAX_SIM_NUM >= 3)
            ,STR_ID_PHB_FIXED_DIAL_SIM3
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            ,STR_ID_PHB_FIXED_DIAL_SIM4
        #endif
        }
    #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
        ,
        {
            STRING_MTPNP_MASTER_BARRED_DIAL
            ,STRING_MTPNP_SLAVE_BARRED_DIAL
        #if (MMI_MAX_SIM_NUM >= 3)
            ,STR_ID_PHB_BARRED_DIAL_SIM3
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            ,STR_ID_PHB_BARRED_DIAL_SIM4
        #endif      
        }
    #endif
    };
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    if (extra_type == PHB_BDN)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        str_id = extra_string[1][sim_interface];
    #else
        str_id = STR_MENU9168_BARRED_DAIL;
    #endif
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (1 == srv_sim_ctrl_get_num_of_inserted())
        {
            str_id = STR_MENU9168_BARRED_DAIL;
        }
    #endif
    }
    else
#endif
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        str_id = extra_string[0][sim_interface];
    #else
        str_id = STR_MENU9167_FIXED_DIAL;
    #endif
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (1 == srv_sim_ctrl_get_num_of_inserted())
        {
            str_id = STR_MENU9167_FIXED_DIAL;
        }
    #endif
    }

    return str_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_sim_set_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_extra_sim_set_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_ID sender_id = menu_evt->sender_id;
    U32 extra_type = mmi_phb_extra_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                U16 str_id = STR_GLOBAL_OFF;

                cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                if (srv_phb_xmgnt_query_dial_mode(g_mmi_phb_sim_interface, extra_type) == 1)
                {
                    str_id = STR_GLOBAL_ON;
                }
           #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                if (extra_type == PHB_BDN)
                {
                    cui_menu_set_item_string(sender_id, MENU_SETTING_FDL_LIST, (UI_string_type) GetString(STR_SETTING_BDL_LIST));
                }
           #endif
                cui_menu_set_item_hint(sender_id, MENU_SETTING_FDL_MODE, (UI_string_type) GetString(str_id));

           #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                mmi_phb_sim_dynamic_name_simx_title(
                    MMI_SIM1 << g_mmi_phb_sim_interface, 
                    sender_id, 
                    mmi_phb_extra_get_title_str_id(extra_type, g_mmi_phb_sim_interface),
                    mmi_phb_extra_number_p->title);
            #endif           
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_SETTING_FDL_MODE)
            {
                mmi_phb_extra_mode_entry();
            }
            else if (menu_evt->highlighted_menu_id == MENU_SETTING_FDL_LIST)
            {
            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                if (extra_type == PHB_FDN)
            #endif
                {
                    mmi_phb_get_fdn_list_check();
                }
            #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
                else
                {
                    mmi_phb_get_extra_number_list_check();
                }
            #endif
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_sim_set_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_sim_set_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 extra_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extra_type = mmi_phb_extra_type;

    if (mmi_phb_check_ready(MMI_TRUE)
        && mmi_phb_extra_number_is_support(g_mmi_phb_sim_interface, mmi_phb_extra_type,MMI_TRUE)
        )
    {
        mmi_phb_entry_menu_cui_generic(
            GRP_ID_PHB_EXTRA_NUMBER,
            MENU9167_FIXED_DIAL,
            mmi_phb_extra_get_title_str_id(extra_type, g_mmi_phb_sim_interface));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_select_mode_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_extra_select_mode_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U32 extra_type = mmi_phb_extra_type;
    MMI_ID sender_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_SETTING_FDL_MODE_ON:
                    if (srv_phb_xmgnt_query_dial_mode(g_mmi_phb_sim_interface, extra_type) == 1)
                    {
                        cui_menu_close(sender_id);
                    }
                    else
                    {
                        mmi_phb_set_extra_mode_check();
                    }
                    break;

                case MENU_SETTING_FDL_MODE_OFF:
                    if (srv_phb_xmgnt_query_dial_mode(g_mmi_phb_sim_interface, extra_type) == 1)
                    {
                        mmi_phb_set_extra_mode_check();
                    }
                    else
                    {
                        cui_menu_close(sender_id);
                    }
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_mode_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_mode_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_gid = mmi_phb_entry_menu_cui_create(
                        GRP_ID_PHB_EXTRA_NUMBER,
                        MENU_SETTING_FDL_MODE,
                        STR_GLOBAL_MODE);

    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    if (srv_phb_xmgnt_query_dial_mode(g_mmi_phb_sim_interface, mmi_phb_extra_type) == 1)
    {
        cui_menu_set_radio_list_item(cui_menu_gid, MENU_SETTING_FDL_MODE_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(cui_menu_gid, MENU_SETTING_FDL_MODE_OFF);
    }

    cui_menu_run(cui_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_pin2_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_pin2_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id verify_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    verify_id = cui_verify_create(GRP_ID_PHB_EXTRA_NUMBER, CUI_VERIFY_TYPE_CHV2);

    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 722);
    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, verify_id);

    cui_verify_set_sim(verify_id, TO_MMI_SIM(g_mmi_phb_sim_interface));
    cui_verify_run(verify_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_extra_mode_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_extra_mode_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_pwd_is_enabled(TO_MMI_SIM(g_mmi_phb_sim_interface), SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 721);

        mmi_phb_extra_number_p->verify_cb = mmi_phb_set_extra_mode_req;
        mmi_phb_get_pin2_status_req();
    }
    else
    {
        MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 720);
    
        mmi_phb_set_extra_mode_req();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_extra_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_extra_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_xmgnt_toggle_dial_mode(
        g_mmi_phb_sim_interface,
        mmi_phb_extra_type,
        mmi_phb_set_extra_mode_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_extra_mode_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_extra_mode_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        if (srv_phb_xmgnt_query_dial_mode(g_mmi_phb_sim_interface, mmi_phb_extra_type) == 1)
        {
            if (mmi_phb_extra_type == PHB_FDN)
            {
                mmi_phb_popup_display_ext(STR_FDL_IS_ON, MMI_EVENT_SUCCESS);
            }
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            else if (mmi_phb_extra_type == PHB_BDN)
            {
                mmi_phb_popup_display_ext(STR_BDL_IS_ON, MMI_EVENT_SUCCESS);
            }
        #endif
        }
        else
        {
            if (mmi_phb_extra_type == PHB_FDN)
            {
                mmi_phb_popup_display_ext(STR_FDL_IS_OFF, MMI_EVENT_SUCCESS);
            }
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            else if (mmi_phb_extra_type == PHB_BDN)
            {
                mmi_phb_popup_display_ext(STR_BDL_IS_OFF, MMI_EVENT_SUCCESS);
            }
        #endif
        }
    }
    else
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
    }

    mmi_phb_cntx_mgr_clear_history();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_extra_number_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (g_mmi_phb_sim_interface == SIM2)
    {
        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (g_mmi_phb_sim_interface == SIM3)
    {
        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (g_mmi_phb_sim_interface == SIM4)
    {
        call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
    }
#endif
#endif

    mmi_phb_call_launch_ex(
        srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, g_mmi_phb_active_index),
        srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, g_mmi_phb_active_index), 
        call_type);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fdn_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fdn_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *extra_number = srv_phb_xmgnt_get_entry_number(g_mmi_phb_handle, g_mmi_phb_active_index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_wild_character(extra_number))
    {
        mmi_wcscpy(
            mmi_phb_extra_number_p->number,
            extra_number);
        mmi_phb_entry_fdn_replace_confirm();
    }
    else
    {
        mmi_phb_extra_number_make_call();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_list_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_active_index = (U16) index;

    if (mmi_phb_extra_type == PHB_FDN)
    {
        if (srv_phb_xmgnt_get_list_count(g_mmi_phb_handle) != 0)
        {
            if (srv_mode_switch_is_network_service_available() == MMI_TRUE)
            {
                mmi_ucm_handle_sendkeys_for_call(mmi_phb_fdn_make_call, KEY_EVENT_DOWN);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_list_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_list_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *item_list[SRV_PHB_XMGNT_SIM_ENTRIES], *hint_list[SRV_PHB_XMGNT_SIM_ENTRIES];
    U16 icon_list[SRV_PHB_XMGNT_SIM_ENTRIES];
    S32 num_of_items;
    S32 i;
    U16 title_id;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            GRP_ID_PHB_EXTRA_NUMBER,
            SCR_ID_SECSET_FDN_LIST,
            NULL,
            mmi_phb_extra_number_list_entry,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        num_of_items = srv_phb_xmgnt_get_list_count(g_mmi_phb_handle);

        MMI_ASSERT(num_of_items <= SRV_PHB_XMGNT_SIM_ENTRIES);

        for (i = 0; i < num_of_items; i++)
        {
            mmi_phb_extra_number_get_item_ex(&item_list[i], &hint_list[i], &icon_list[i], i);
        }

        RegisterHighlightHandler(mmi_phb_extra_number_list_highlight_hdlr);

    #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
        if (mmi_phb_extra_type == PHB_BDN)
        {
            title_id = STR_SCR8079_BDL_VIEW_LIST_CAPTION;
        }
        else
    #endif
        {
            title_id = STR_SCR8054_CALL_FDL_CAPTION;
        }

        if (num_of_items == 0)
        {
            item_list[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
#ifndef __MMI_WGUI_DISABLE_CSK__
            
#ifndef __MMI_MAINLCD_96X64__
            EnableCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
	    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 			
#endif
            ShowCategory6Screen(
                title_id,
                IMG_SCR_PBOOK_CAPTION,
                STR_GLOBAL_ADD,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                1,
                item_list,
                NULL,
                0,
                gui_buffer);

            SetLeftSoftkeyFunction(mmi_phb_extra_number_add_pre_entry, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(mmi_phb_extra_number_add_pre_entry, KEY_EVENT_UP);
        }
        else
        {
            
#ifndef __MMI_WGUI_DISABLE_CSK__            
#ifndef __MMI_MAINLCD_96X64__
            EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
	    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif 	

            ShowCategory53Screen(
                title_id,
                IMG_SCR_PBOOK_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                num_of_items,
                item_list,
                icon_list,
                hint_list,
                0,
                0,
                gui_buffer);

            SetCenterSoftkeyFunction(mmi_phb_extra_number_edit_pre_entry, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_phb_extra_number_option_entry, KEY_EVENT_UP);
        #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
            wgui_register_tap_callback(mmi_phb_extra_number_list_tap_callback);
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_fdn_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U32 mmi_phb_extra_number_get_total(U32 extra_type, U8 sim_interface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    if (extra_type == PHB_BDN)
    {
        return srv_phb_startup_get_bdn_total(g_mmi_phb_sim_interface);
    }
    else
#endif
    {
        return srv_phb_startup_get_fdn_total(g_mmi_phb_sim_interface);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_list_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_extra_number_list_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_MENU_ID menu_id = menu_evt->highlighted_menu_id;
    MMI_ID sender_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (srv_phb_xmgnt_get_list_count(g_mmi_phb_handle) == mmi_phb_extra_number_get_total(mmi_phb_extra_type, g_mmi_phb_sim_interface) ||
                srv_phb_xmgnt_get_list_count(g_mmi_phb_handle) == SRV_PHB_XMGNT_SIM_ENTRIES)
            {
                cui_menu_set_item_hidden(sender_id, MENU8234_FDL_VIEW_OPTIONS_ADD, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU8234_FDL_VIEW_OPTIONS_ADD, MMI_FALSE);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_id)
            {
                case MENU8234_FDL_VIEW_OPTIONS_ADD:
                    mmi_phb_extra_number_add_pre_entry();
                    break;
                        
                case MENU8234_FDL_VIEW_OPTIONS_EDIT:
                    mmi_phb_extra_number_edit_pre_entry();
                    break;

                case MENU8234_FDL_VIEW_OPTIONS_DELETE:
                    mmi_phb_extra_number_delete_confirm();
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_add_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_add_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_extra_number_prepare(MMI_TRUE, mmi_phb_extra_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_edit_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_edit_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_extra_number_prepare(MMI_FALSE, mmi_phb_extra_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_extra_number_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_extra_number_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name = mmi_phb_extra_number_p->name;
    U16 *number = mmi_phb_extra_number_p->number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(mmi_phb_extra_number_p->sender_id, INLINE_ID_PHB_EXTRA_NAME, name);
    cui_inline_get_value(mmi_phb_extra_number_p->sender_id, INLINE_ID_PHB_EXTRA_NUMBER, number);

    if ((name[0] == '\0') && (number[0] == '\0'))
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_NAME_NUM_REQUIRE,
            MMI_EVENT_FAILURE);
    }
    else if (!srv_phb_check_valid_number(number))
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_INVALID_NUMBER,
            MMI_EVENT_FAILURE);
    }
    else
    {
        if (srv_sim_ctrl_pwd_is_enabled(TO_MMI_SIM(g_mmi_phb_sim_interface), SRV_SIM_CTRL_PWD_TYPE_CHV2))
        {
            mmi_phb_extra_number_p->verify_cb = mmi_phb_extra_number_save_req;
            mmi_phb_get_pin2_status_req();
        }
        else
        {
            mmi_phb_extra_number_save_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_save_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_save_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_xmgnt_callback_type del_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_in_operation = MMI_TRUE;
    g_mmi_phb_in_edit = MMI_TRUE;
    mmi_phb_show_in_progress_ex(STR_GLOBAL_SAVING);

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    if (mmi_phb_extra_type == PHB_BDN)
    {
        del_cb = mmi_phb_edit_bdn_number_rsp;
    }
    else
#endif
    {
        del_cb = mmi_phb_edit_fdn_number_rsp;
    }

    srv_phb_xmgnt_set_entry(
        g_mmi_phb_sim_interface,
        mmi_phb_extra_type,
        0xFFFF,
        (U16) ((!g_mmi_phb_in_new) ? srv_phb_xmgnt_get_entry_index(g_mmi_phb_handle, g_mmi_phb_active_index) : 0xFFFF),
        mmi_phb_extra_number_p->name,
        mmi_phb_extra_number_p->number,
        del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_delete_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr lsk_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_pwd_is_enabled(TO_MMI_SIM(g_mmi_phb_sim_interface), SRV_SIM_CTRL_PWD_TYPE_CHV2))
    {
        mmi_phb_extra_number_p->verify_cb = mmi_phb_extra_number_delete_req;

        lsk_func = mmi_phb_get_pin2_status_req;
    }
    else
    {
        lsk_func = mmi_phb_extra_number_delete_req;
    }

    mmi_phb_confirm_display_ext(
        STR_GLOBAL_DELETE_ASK,
        GRP_ID_PHB_EXTRA_NUMBER,
        lsk_func,
        mmi_frm_scrn_close_active_id,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_fdn_list_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_fdn_list_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        mmi_phb_get_fdn_list();
        mmi_phb_extra_number_list_entry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_fdn_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_fdn_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_handle = srv_phb_xmgnt_get_list(
                            g_mmi_phb_sim_interface,
                            PHB_FDN,
                            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_fdn_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_fdn_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        mmi_phb_get_fdn_list();
        cui_inline_close(mmi_phb_extra_number_p->sender_id);
    }
    else
    {
        U16 str_id;
        if (result == SRV_PHB_XMGNT_RESULT_EF_FULL)
        {
            str_id = STR_NOT_SAVED_NUMBER_TOO_LONG;
        }
        else
        {
            str_id = STR_GLOBAL_UNFINISHED;
        }

        mmi_phb_popup_display_ext(
            str_id,
            MMI_EVENT_FAILURE);
    }

    g_mmi_phb_in_edit = MMI_FALSE;
    g_mmi_phb_in_operation = MMI_FALSE;
    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_extra_number_delete_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_extra_number_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_xmgnt_callback_type del_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_in_operation = MMI_TRUE;
    mmi_phb_show_in_progress_ex(STR_GLOBAL_DELETING);

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
    if (mmi_phb_extra_type == PHB_BDN)
    {
        del_cb = mmi_phb_delete_bdn_number_rsp;
    }
    else
#endif
    {
        del_cb = mmi_phb_delete_fdn_number_rsp;
    }

    srv_phb_xmgnt_delete_entry(
        g_mmi_phb_sim_interface,
        mmi_phb_extra_type,
        0xFFFF,
        srv_phb_xmgnt_get_entry_index(g_mmi_phb_handle, g_mmi_phb_active_index),
        del_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_fdn_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_delete_fdn_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        mmi_phb_get_fdn_list();
    }
    else
    {
        mmi_phb_popup_display_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
    g_mmi_phb_in_operation = MMI_FALSE;
}


#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
#define MMI_PHB_BDN_LIST

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_extra_number_list_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_extra_number_list_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE)
        && mmi_phb_extra_number_is_support(g_mmi_phb_sim_interface, mmi_phb_extra_type,MMI_TRUE)
        )
    {
        mmi_phb_extra_number_group_check(); //only for mmi_phb_sc_owner_number_entry

        mmi_phb_show_in_progress_ex(STR_GLOBAL_PLEASE_WAIT);
        mmi_phb_get_extra_number_list_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_extra_number_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_extra_number_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_xmgnt_callback_type list_cb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_phb_extra_type)
    {
        case PHB_BDN:
            list_cb = mmi_phb_get_bdn_list_rsp;
            break;

        case PHB_MSISDN:
            list_cb = mmi_phb_get_owner_number_list_rsp;
            break;

        case PHB_SDN:
            list_cb = mmi_phb_get_sdn_list_rsp;
            break;

        case PHB_ECC:
            list_cb = mmi_phb_get_sos_list_rsp;
            break;
    }

    g_mmi_phb_handle = srv_phb_xmgnt_get_list(
        g_mmi_phb_sim_interface,
        mmi_phb_extra_type,
        list_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_bdn_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_get_bdn_list_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_in_operation)
    {
        if (g_mmi_phb_in_edit)
        {
            cui_inline_close(mmi_phb_extra_number_p->sender_id);
            g_mmi_phb_in_edit = MMI_FALSE;
        }
        g_mmi_phb_in_operation = MMI_FALSE;
    }
    else if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        if (mmi_frm_scrn_get_active_id() != SCR_IN_PROGRESS_PHB)
        {
            mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
            return;
        }

        mmi_phb_extra_number_list_entry();
    }
    else
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_bdn_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_bdn_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        mmi_phb_get_extra_number_list_req();
    }
    else
    {
        if (result == SRV_PHB_XMGNT_RESULT_EF_FULL)
        {
            mmi_phb_popup_display_ext(STR_NOT_SAVED_NUMBER_TOO_LONG, MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);
        }
        mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
        g_mmi_phb_in_edit = MMI_FALSE;
        g_mmi_phb_in_operation = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_bdn_number_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_delete_bdn_number_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        mmi_phb_get_extra_number_list_req();
    }
    else
    {
        mmi_phb_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE);

        mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_IN_PROGRESS_PHB);
        g_mmi_phb_in_operation = MMI_FALSE;
    }
}
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */

#define MMI_PHB_ICE_CONTACT
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif /* __MMI_PHB_ICE_CONTACT__ */
#endif

#ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
#define MMI_PHB_MY_NUMBER

/*
 * Local Variable
 */
static mmi_id g_mmi_phb_send_sg_id;

/*
 * Local Function
 */
static mmi_ret mmi_phb_entry_my_number_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_my_number_edit_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_my_number_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_entry_group_my_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U16 menu_id = (U16) (U32) menu_evt->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_phb_mem_free(mmi_phb_my_number_p);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (menu_id == MENU_ID_PHB_MY_NUMBER)
            {
                mmi_phb_entry_my_number_option_proc(evt);
            }
            break;

        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_NOTIFY:
            mmi_phb_entry_my_number_edit_proc(evt);
            break;

    #if defined(__MMI_VCARD__)
        case EVT_ID_VCARD_DONE:
        case EVT_ID_VCARD_CANCEL:
            cui_vcard_build_vcard_close(g_mmi_phb_send_sg_id);
            break;
    #endif /* defined(__MMI_VCARD__) */

        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

                mmi_phb_confirm_display_handle(alert_result);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_my_number_p = mmi_phb_mem_malloc(sizeof(mmi_phb_my_number_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
#ifndef __MMI_MAINLCD_96X64__
    mmi_frm_group_create_ex(
        GRP_ID_PHB_SETTING,
        GRP_ID_PHB_MY_NUMBER,
        mmi_phb_entry_group_my_number_proc,
        mmi_phb_my_number_p,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_MY_NUMBER,
        mmi_phb_entry_group_my_number_proc,
        mmi_phb_my_number_p,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);


#endif
    mmi_phb_entry_my_number_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_read_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_read_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_phb_my_number_struct my_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, &my_number, NVRAM_EF_PHB_MY_NUMBER_SIZE, &error);

    mmi_wcscpy(mmi_phb_my_number_p->first_name, my_number.name);
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    mmi_wcscpy(mmi_phb_my_number_p->last_name, my_number.l_name);
#endif
    mmi_wcscpy(mmi_phb_my_number_p->mobile_number, my_number.number);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_wcscpy(mmi_phb_my_number_p->home_number, my_number.homeNumber);
    mmi_wcscpy(mmi_phb_my_number_p->company_name, my_number.companyName);
    mmi_wcscpy(mmi_phb_my_number_p->email_address, my_number.emailAddress);
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    mmi_wcscpy(mmi_phb_my_number_p->email_address2, my_number.emailAddress2);
#endif
    mmi_wcscpy(mmi_phb_my_number_p->office_number, my_number.officeNumber);
    mmi_wcscpy(mmi_phb_my_number_p->fax_number, my_number.faxNumber);
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_write_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_write_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_phb_my_number_struct my_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(my_number.name, mmi_phb_my_number_p->first_name);
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    mmi_wcscpy(my_number.l_name, mmi_phb_my_number_p->last_name);
#endif
    mmi_wcscpy(my_number.number, mmi_phb_my_number_p->mobile_number);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_wcscpy(my_number.homeNumber, mmi_phb_my_number_p->home_number);
    mmi_wcscpy(my_number.companyName, mmi_phb_my_number_p->company_name);
    mmi_wcscpy(my_number.emailAddress, mmi_phb_my_number_p->email_address);
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    mmi_wcscpy(my_number.emailAddress2, mmi_phb_my_number_p->email_address2);
#endif
    mmi_wcscpy(my_number.officeNumber, mmi_phb_my_number_p->office_number);
    mmi_wcscpy(my_number.faxNumber, mmi_phb_my_number_p->fax_number);
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    WriteRecord(NVRAM_EF_PHB_MY_NUMBER_LID, 1, &my_number, NVRAM_EF_PHB_MY_NUMBER_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_my_number_list_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static S32 mmi_phb_my_number_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[MMI_PHB_NAME_LENGTH + 1 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    srv_phb_convert_to_name(name, 
                        mmi_phb_my_number_p->first_name,
                        mmi_phb_my_number_p->last_name,
                        MMI_PHB_NAME_LENGTH);
#else
    mmi_wcscpy(name, mmi_phb_my_number_p->first_name);
#endif

    if (*name != 0)
    {
        mmi_ucs2ncpy((CHAR*) menu_data[0].item_list[0], (CHAR*) name, MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*) menu_data[0].item_list[0], GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }

    menu_data[0].image_list[0] = get_image(IMG_STORAGE_HANDSET);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_my_number_list_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_phb_my_number_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_my_number_p->mobile_number[0] != 0)
    {
        mmi_ucs2ncpy((CHAR*) hint_array[0], (CHAR*) mmi_phb_my_number_p->mobile_number, MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_my_number_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *item_list[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_read_my_number();

    mmi_frm_scrn_enter(
        GRP_ID_PHB_MY_NUMBER,
        SCR_ID_PHB_VCARD_MYCARD,
        NULL,
        mmi_phb_entry_my_number_list,
        MMI_FRM_FULL_SCRN);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (mmi_phb_my_number_p->first_name[0] == 0 && mmi_phb_my_number_p->mobile_number[0] == 0
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        && mmi_phb_my_number_p->last_name[0] == 0
    #endif
        )
    {
        item_list[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);

        
#ifndef __MMI_WGUI_DISABLE_CSK__		            
#ifndef __MMI_MAINLCD_96X64__
        EnableCenterSoftkey(0, IMG_ID_PHB_CSK_ADD);
#else
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 	
#endif 	

        ShowCategory6Screen(
            STR_ID_PHB_VCARD,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_ADD,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            item_list,
            NULL,
            0,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_phb_entry_my_number_edit, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_entry_my_number_edit, KEY_EVENT_UP);
    }
    else
    {
        
        
#ifndef __MMI_WGUI_DISABLE_CSK__		
#ifndef __MMI_MAINLCD_96X64__
        EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif 

        wgui_cat1032_show(
                (WCHAR*) GetString(STR_ID_PHB_VCARD),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                1,
                mmi_phb_my_number_list_get_item,
                mmi_phb_my_number_list_get_hint,
                0,
                0,    
                IMG_STORAGE_HANDSET,
                0,
                gui_buffer,
                NULL);

        SetCenterSoftkeyFunction(mmi_phb_entry_my_number_edit, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_phb_entry_my_number_option, KEY_EVENT_UP);
    }
}


static MMI_BOOL mmi_phb_my_number_send_is_invalid()
{
    mmi_phb_read_my_number();

    if (!mmi_phb_my_number_p->first_name[0]
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        && !mmi_phb_my_number_p->last_name[0]
    #endif
        )
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_my_number_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_ID sender_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
        #if defined(__MMI_VCARD__)
            if (mmi_phb_send_contact_menu_check(sender_id) || mmi_phb_my_number_send_is_invalid())
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SEND_MY_NUMBER, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(sender_id, MENU_ID_PHB_SEND_MY_NUMBER, MMI_FALSE);
            }
        #endif /* defined(__MMI_VCARD__) */
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_PHB_EDIT_MY_NUMBER:
                    mmi_phb_entry_my_number_edit();
                    break;

            #if defined(__MMI_VCARD__)
            //#if defined(__OP01_FWPBW__) && !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
			#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
            	case MENU_ID_PHB_SEND_MY_NUMBER:
                    mmi_phb_send_my_number(MMI_VCARD_BUILD_VCARD_SEND_SMS);
                    break;
            #endif

            #if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
                case MENU_ID_VCARD_FORWARD_SMS:
                    mmi_phb_send_my_number(MMI_VCARD_BUILD_VCARD_SEND_SMS);
                    break;
            #endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */
            #if defined(__MMI_MMS__)
                case MENU_ID_VCARD_FORWARD_MMS:
                    mmi_phb_send_my_number(MMI_VCARD_BUILD_VCARD_SEND_MMS);
                    break;

            #endif /* defined(__MMI_MMS__) */
            #if defined(__MMI_EMAIL__)
                case MENU_ID_VCARD_FORWARD_EMAIL:
                    mmi_phb_send_my_number(MMI_VCARD_BUILD_VCARD_SEND_EMAIL);
                    break;
            #endif /* defined(__MMI_EMAIL__) */
            #ifdef __MMI_OPP_SUPPORT__
                case MENU_ID_VCARD_FORWARD_BT:
                    mmi_phb_send_my_number(MMI_VCARD_BUILD_VCARD_SEND_BT);
                    break;
            #endif /* __MMI_OPP_SUPPORT__ */
            #endif /* defined(__MMI_VCARD__) */

                case MENU_ID_PHB_DELETE_MY_NUMBER:
                    mmi_phb_entry_my_number_delete_confirm();
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_my_number_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic_ext(
        GRP_ID_PHB_MY_NUMBER,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_PHB_MY_NUMBER,
        0,
        (void*) (U32) MENU_ID_PHB_MY_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_edit_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_my_number_edit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            {
                mmi_phb_entry_my_number_save_confirm();
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*) evt;
                cui_inline_close(abort_evt->sender_id);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_my_number_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_read_my_number();

    inline_id = cui_inline_create(GRP_ID_PHB_MY_NUMBER, &g_mmi_phb_inline_screen5);
    cui_inline_set_value(inline_id, INLINE_ID_PHB_FIRST_NAME, mmi_phb_my_number_p->first_name);
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    cui_inline_set_value(inline_id, INLINE_ID_PHB_LAST_NAME, mmi_phb_my_number_p->last_name);
#endif
    cui_inline_set_value(inline_id, INLINE_ID_PHB_MOBILE_NUMBER, mmi_phb_my_number_p->mobile_number);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    cui_inline_set_value(inline_id, INLINE_ID_PHB_HOME_NUMBER, mmi_phb_my_number_p->home_number);
    cui_inline_set_value(inline_id, INLINE_ID_PHB_COMPANY_NAME, mmi_phb_my_number_p->company_name);
    cui_inline_set_value(inline_id, INLINE_ID_PHB_EMAIL_ADDR, mmi_phb_my_number_p->email_address);
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    cui_inline_set_value(inline_id, INLINE_ID_PHB_EMAIL_ADDR2, mmi_phb_my_number_p->email_address2);
#endif
    cui_inline_set_value(inline_id, INLINE_ID_PHB_OFFICE_NUMBER, mmi_phb_my_number_p->office_number);
    cui_inline_set_value(inline_id, INLINE_ID_PHB_FAX_NUMBER, mmi_phb_my_number_p->fax_number);
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
    mmi_phb_my_number_p->sender_id = inline_id;

    if (mmi_phb_my_number_p->first_name[0] == 0 && mmi_phb_my_number_p->mobile_number[0] == 0
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        && mmi_phb_my_number_p->last_name[0] == 0
    #endif
        )
    {
        cui_inline_set_title_string_with_string_id(inline_id,  STR_GLOBAL_ADD);
    }
    
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_save_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_my_number_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_FIRST_NAME, mmi_phb_my_number_p->first_name);
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_LAST_NAME, mmi_phb_my_number_p->last_name);
#endif
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_MOBILE_NUMBER, mmi_phb_my_number_p->mobile_number);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_HOME_NUMBER, mmi_phb_my_number_p->home_number);
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_COMPANY_NAME, mmi_phb_my_number_p->company_name);
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_EMAIL_ADDR, mmi_phb_my_number_p->email_address);
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_EMAIL_ADDR2, mmi_phb_my_number_p->email_address2);
#endif
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_OFFICE_NUMBER, mmi_phb_my_number_p->office_number);
    cui_inline_get_value(mmi_phb_my_number_p->sender_id, INLINE_ID_PHB_FAX_NUMBER, mmi_phb_my_number_p->fax_number);
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    mmi_phb_save_my_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_save_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0	
#if defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__)
/* under construction !*/
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
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
#else /* defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__) */
/* under construction !*/
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__) */ 
#else
    if (mmi_phb_my_number_p->first_name[0] == 0 && mmi_phb_my_number_p->mobile_number[0] == 0
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        && mmi_phb_my_number_p->last_name[0] == 0
    #endif
        )
    {
        str_id = STR_ID_PHB_NAME_NUM_REQUIRE;
    }
#endif /* defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__) */ 
    else if (!mmi_phb_check_valid_number(mmi_phb_my_number_p->mobile_number, PHB_STORAGE_NVRAM))
    {
        str_id = STR_GLOBAL_INVALID_NUMBER;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if (!mmi_phb_check_valid_number(mmi_phb_my_number_p->home_number, PHB_STORAGE_NVRAM) ||
        !mmi_phb_check_valid_number(mmi_phb_my_number_p->office_number, PHB_STORAGE_NVRAM) ||
        !mmi_phb_check_valid_number(mmi_phb_my_number_p->fax_number, PHB_STORAGE_NVRAM))
    {
        str_id = STR_GLOBAL_INVALID_NUMBER;
    }
    else if (mmi_phb_my_number_p->email_address[0] &&
        !applib_is_valid_email_address_unicode(mmi_phb_my_number_p->email_address))
    {
        str_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
    }
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    else if (mmi_phb_my_number_p->email_address2[0] &&
        !applib_is_valid_email_address_unicode(mmi_phb_my_number_p->email_address2))
    {
        str_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    if (str_id != 0)
    {
        mmi_phb_popup_display_ext(str_id, MMI_EVENT_FAILURE);
        return;
    }

    mmi_phb_write_my_number();

    mmi_phb_popup_display_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
    cui_inline_close(mmi_phb_my_number_p->sender_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_go_back_from_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_go_back_from_my_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(mmi_phb_my_number_p->sender_id);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_my_number_delete_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_my_number_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_confirm_display_ext(
            STR_GLOBAL_DELETE_ASK,
            GRP_ID_PHB_MY_NUMBER,
            mmi_phb_delete_my_number,
            mmi_frm_scrn_close_active_id,
            MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_delete_my_number(void)
{
    mmi_phb_my_number_p->first_name[0] = 0;
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    mmi_phb_my_number_p->last_name[0] = 0;
#endif
    mmi_phb_my_number_p->mobile_number[0] = 0;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_phb_my_number_p->home_number[0] = 0;
    mmi_phb_my_number_p->company_name[0] = 0;
    mmi_phb_my_number_p->email_address[0] = 0;
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    mmi_phb_my_number_p->email_address2[0] = 0;
#endif
    mmi_phb_my_number_p->office_number[0] = 0;
    mmi_phb_my_number_p->fax_number[0] = 0;
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    mmi_phb_write_my_number();

    mmi_phb_popup_display_ext(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS);
}

#if defined(__MMI_VCARD__)


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_send_my_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_send_my_number(mmi_vcard_build_vcard_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vcard_field_data_struct vcard_data;
    mmi_phb_wcs_num_struct opt_num[MMI_PHB_OPT_NUM_COUNT];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_read_my_number();

    memset(&vcard_data, 0, sizeof(mmi_vcard_field_data_struct));
    vcard_data.second_name = mmi_phb_my_number_p->first_name;
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    vcard_data.first_name = mmi_phb_my_number_p->last_name;
#endif
    vcard_data.number = mmi_phb_my_number_p->mobile_number;
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (mmi_phb_my_number_p->home_number[0])
    {
        mmi_wcscpy(opt_num[0].number, mmi_phb_my_number_p->home_number);
        opt_num[0].type = MMI_PHB_NUM_TYPE_HOME;
        vcard_data.opt_num[0] = &opt_num[0];
    }
    if (mmi_phb_my_number_p->office_number[0])
    {
        mmi_wcscpy(opt_num[1].number, mmi_phb_my_number_p->office_number);
        opt_num[1].type = MMI_PHB_NUM_TYPE_OFFICE;
        vcard_data.opt_num[1] = &opt_num[1];
    }
    if (mmi_phb_my_number_p->fax_number[0])
    {
        mmi_wcscpy(opt_num[2].number, mmi_phb_my_number_p->fax_number);
        opt_num[2].type = MMI_PHB_NUM_TYPE_FAX;
        vcard_data.opt_num[2] = &opt_num[2];
    }
    vcard_data.company = mmi_phb_my_number_p->company_name;
    vcard_data.email = mmi_phb_my_number_p->email_address;
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    vcard_data.email2 = mmi_phb_my_number_p->email_address2;
#endif
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    g_mmi_phb_send_sg_id = cui_vcard_build_vcard_creat(GRP_ID_PHB_MY_NUMBER);
    cui_vcard_build_vcard_set_data(g_mmi_phb_send_sg_id, &vcard_data);
    cui_vcard_build_vcard_set_type(g_mmi_phb_send_sg_id, type);
    cui_vcard_build_vcard_run(g_mmi_phb_send_sg_id);
}

#endif /* defined(__MMI_VCARD__) */
#endif /* __MMI_PHB_SLIM_EXTRA_DEFEATURE__ */


#define MMI_PHB_SPEED_DIAL
#ifdef __MMI_PHB_SPEED_DIAL__
/*
 * Local Variable
 */
static U8 g_mmi_phb_speed_status;

static mmi_id g_mmi_phb_list_sg_id;
static U16 g_mmi_phb_store_index;
static U32 g_mmi_phb_number_type;

/*
 * Local Function
 */
static mmi_ret mmi_phb_entry_speed_dial_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_speed_dial_status_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_speed_dial_option_proc(mmi_event_struct *evt);
static mmi_ret mmi_phb_entry_speed_dial_select_contact_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_speed_dial_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_entry_group_speed_dial_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    U16 menu_id = (U16) (U32) menu_evt->app_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_phb_mem_free(mmi_phb_speed_dial_p);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            if (menu_id == MENU_ID_PHB_SPEED_DIAL)
            {
                mmi_phb_entry_speed_dial_proc(evt);
            }
            else if (menu_id == MENU_ID_PHB_SPEED_DIAL_STATUS)
            {
                mmi_phb_entry_speed_dial_status_proc(evt);
            }
            else if (menu_id == MENU_ID_PHB_SPEED_DIAL_OP)
            {
                mmi_phb_entry_speed_dial_option_proc(evt);
            }
            break;

        case EVT_ID_PHB_SELECT_CONTACT:
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            mmi_phb_entry_speed_dial_select_contact_proc(evt);
            break;

        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*) evt;

                mmi_phb_confirm_display_handle(alert_result);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_group_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_group_speed_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_speed_dial_p = mmi_phb_mem_malloc(sizeof(mmi_phb_extra_number_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
#ifndef __MMI_MAINLCD_96X64__
    mmi_frm_group_create_ex(
        GRP_ID_PHB_SETTING,
        GRP_ID_PHB_SPEED_DIAL,
        mmi_phb_entry_group_speed_dial_proc,
        mmi_phb_speed_dial_p,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else

    mmi_frm_group_create_ex(
        GRP_ID_PHB_MAIN,
        GRP_ID_PHB_SPEED_DIAL,
        mmi_phb_entry_group_speed_dial_proc,
        mmi_phb_speed_dial_p,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#endif

    mmi_phb_entry_speed_dial();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_speed_dial_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_speed_dial_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 is_first = 0xFF;
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_first == 0xFF)
    {
        ReadValue(NVRAM_SETTING_SPEED_DIAL, &data, DS_BYTE, &error);
        g_mmi_phb_speed_status = is_first = ((data == 1) ? 1 : 0);
    }

    return g_mmi_phb_speed_status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_speed_dial_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_set_speed_dial_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_SETTING_SPEED_DIAL, &g_mmi_phb_speed_status, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_speed_dial_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                U16 str_id = STR_GLOBAL_OFF;
                cui_menu_set_currlist_flags(
                    sender_id,
                    CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                if (mmi_phb_get_speed_dial_status() == 1)
                {
                    str_id = STR_GLOBAL_ON;
                }
                cui_menu_set_item_hint(
                    sender_id,
                    MENU_ID_PHB_SPEED_DIAL_STATUS,
                    (UI_string_type) GetString(str_id));
            }
            break;

        case EVT_ID_CUI_MENU_LIST_EXIT:
            mmi_phb_set_speed_dial_status();
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (highlighted_menu_id == MENU_ID_PHB_SPEED_DIAL_STATUS)
            {
                mmi_phb_entry_speed_dial_status();
            }
            else if (highlighted_menu_id == MENU_ID_PHB_SPEED_DIAL_SET_NUMBERS)
            {
                mmi_phb_entry_speed_dial_set_number();
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_speed_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_SPEED_DIAL,
        MENU_ID_PHB_SPEED_DIAL,
        STR_ID_PHB_SPEED_DIAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_status_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_speed_dial_status_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;
    MMI_ID sender_id = menu_evt->sender_id;
    MMI_MENU_ID highlighted_menu_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_currlist_flags(sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (highlighted_menu_id == MENU_ID_PHB_SPEED_DIAL_STATUS_ON)
            {
                g_mmi_phb_speed_status = 1;
            }
            else if (highlighted_menu_id == MENU_ID_PHB_SPEED_DIAL_STATUS_OFF)
            {
                g_mmi_phb_speed_status = 0;
            }
            mmi_phb_popup_display_ext(
                STR_GLOBAL_DONE,
                MMI_EVENT_SUCCESS);
            cui_menu_close(sender_id);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_speed_dial_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_gid = mmi_phb_entry_menu_cui_create(
                        GRP_ID_PHB_SPEED_DIAL,
                        MENU_ID_PHB_SPEED_DIAL_STATUS,
                        STR_ID_PHB_SPEED_DIAL_STATUS);

    cui_menu_set_currlist_flags(cui_menu_gid, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);

    if (mmi_phb_get_speed_dial_status() == 1)
    {
        cui_menu_set_radio_list_item(cui_menu_gid,  MENU_ID_PHB_SPEED_DIAL_STATUS_ON);
    }
    else
    {
        cui_menu_set_radio_list_item(cui_menu_gid,  MENU_ID_PHB_SPEED_DIAL_STATUS_OFF);
    }

    cui_menu_run(cui_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_set_number_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_set_number_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_active_index = (U16) index;

    if (srv_phb_speed_dial_is_sync(g_mmi_phb_active_index))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_phb_entry_speed_dial_option, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_phb_entry_speed_dial_select_contact, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_speed_dial_set_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *item_list[MMI_PHB_SPEED_DIAL_COUNT];
    U8 *hint_list[MMI_PHB_SPEED_DIAL_COUNT];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; ++i)
    {
        if (srv_phb_speed_dial_is_sync(i))
        {
            if (mmi_wcslen(srv_phb_speed_dial_get_name(i)))
            {
                item_list[i] = (PU8) srv_phb_speed_dial_get_name(i);
                if (mmi_wcslen(srv_phb_speed_dial_get_number(i)))
                {
                    hint_list[i] = (PU8) srv_phb_speed_dial_get_number(i);
                }
                else
                {
                    hint_list[i] = NULL;
                }
            }
            else
            {
                item_list[i] = (PU8) srv_phb_speed_dial_get_number(i);
                hint_list[i] = NULL;
            }
        }
        else
        {
            item_list[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
            hint_list[i] = NULL;
        }
    }

    mmi_frm_scrn_enter(
        GRP_ID_PHB_SPEED_DIAL,
        SCR_SPEED_DIAL_LIST,
        wgui_restore_list_menu_slim_style,
        mmi_phb_entry_speed_dial_set_number,
        MMI_FRM_FULL_SCRN);

    RegisterHighlightHandler(mmi_phb_speed_dial_set_number_highlight_hdlr);
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);

#ifndef __MMI_WGUI_DISABLE_CSK__    
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif 


    ShowCategory53Screen(
        STR_ID_PHB_SPEED_DIAL_SETTING,
        IMG_SCR_PBOOK_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_PHB_SPEED_DIAL_COUNT,
        item_list,
        (U16*) (gIndexIconsImageList + 1),
        hint_list,
        0,
        0,
        mmi_frm_scrn_get_active_gui_buf());

    SetCenterSoftkeyFunction(mmi_phb_entry_speed_dial_select_contact, KEY_EVENT_UP);
    SetKeyHandler(mmi_phb_speed_dial_make_call, KEY_SEND, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_speed_dial_list_tap_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_option_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_speed_dial_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            if (menu_evt->highlighted_menu_id == MENU_ID_PHB_SPEED_DIAL_OP_EDIT)
            {
                mmi_phb_entry_speed_dial_select_contact();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_PHB_SPEED_DIAL_OP_DEL)
            {
                mmi_phb_delete_speed_dial();
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_speed_dial_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_menu_cui_generic(
        GRP_ID_PHB_SPEED_DIAL,
        MENU_ID_PHB_SPEED_DIAL_OP,
        0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_select_contact_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phb_entry_speed_dial_select_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct *select_contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SELECT_CONTACT:
            select_contact = (cui_phb_select_contact_result_struct*) evt;
            mmi_phb_speed_dial_save(
                select_contact->store_index,
                select_contact->select_data,
                select_contact->data_type);
            break;

        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            cui_phb_list_select_contact_close(g_mmi_phb_list_sg_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_select_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_speed_dial_select_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_list_sg_id = cui_phb_list_select_contact_create(GRP_ID_PHB_SPEED_DIAL);

    if (g_mmi_phb_list_sg_id != GRP_ID_INVALID)
    {
        cui_phb_list_select_contact_set_field_filter(g_mmi_phb_list_sg_id, SRV_PHB_ENTRY_FIELD_GSM_NUM);
        cui_phb_list_select_contact_run(g_mmi_phb_list_sg_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_make_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_speed_dial_struct *speed_dial;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    speed_dial = srv_phb_speed_dial_get_entry(g_mmi_phb_active_index);

    if (speed_dial->is_sync == MMI_TRUE)
    {
        mmi_phb_call_launch_with_type(speed_dial->store_index, speed_dial->number, speed_dial->num_type);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  phb_data        [IN]        
 *  data_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_save(
        U16 store_index,
        U16 *phb_data,
        U32 data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_speed_dial_struct *speed_dial;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_store_index = store_index;
    g_mmi_phb_number_type = data_type;
    mmi_wcscpy(mmi_phb_speed_dial_p->number, phb_data);

    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; ++i)
    {
        speed_dial = srv_phb_speed_dial_get_entry(i);
        if ((speed_dial->store_index == g_mmi_phb_store_index) &&
            (speed_dial->num_type == g_mmi_phb_number_type))
        {
            mmi_phb_popup_display_ext(STR_ID_PHB_SPEED_DIAL_ALREADY_ASSIGNED, MMI_EVENT_FAILURE);
            return;
        }
    }

    srv_phb_update_speed_dial(
        g_mmi_phb_active_index,
        g_mmi_phb_store_index,
        mmi_phb_speed_dial_p->number,
        g_mmi_phb_number_type);

    cui_phb_list_select_contact_close(g_mmi_phb_list_sg_id);

    mmi_phb_popup_display_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_speed_dial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_delete_speed_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_delete_speed_dial(g_mmi_phb_active_index);

    mmi_phb_popup_display_ext(
        STR_GLOBAL_REMOVED,
        MMI_EVENT_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_id      [IN]        
 * RETURNS
 *  CHAR*
 *****************************************************************************/
CHAR* mmi_phb_speed_dial_get_number(U16 key_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_speed_dial_is_sync(key_id - 2))
    {
        return (CHAR*) srv_phb_speed_dial_get_number(key_id - 2);
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_pre_set_speed_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_pre_set_speed_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_speed_dial_pre_set_cntx_struct* cntx = 
        (mmi_phb_speed_dial_pre_set_cntx_struct*)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->select_index = (U16)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_select_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_pre_set_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_speed_dial_pre_set_cntx_struct* cntx = 
        (mmi_phb_speed_dial_pre_set_cntx_struct*)mmi_frm_group_get_user_data(mmi_frm_group_get_active_id());

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_pre_set_speed_dial(cntx->select_index, cntx->store_index, cntx->num_type);
    g_mmi_phb_save_contact_p->done_flag = 1;
    mmi_frm_group_close(cntx->sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_speed_dial_pre_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_speed_dial_pre_set_number(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *item_list[MMI_PHB_SPEED_DIAL_COUNT];
    U8 *hint_list[MMI_PHB_SPEED_DIAL_COUNT];
    U16 i;
    U8 *gui_buffer;
    mmi_phb_speed_dial_pre_set_cntx_struct* cntx;
    WCHAR* item;
    WCHAR* hint;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_check_ready(MMI_TRUE))
    {
        mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            wgui_restore_list_menu_slim_style,
            (FuncPtr)mmi_phb_entry_speed_dial_pre_set_number,
            MMI_FRM_FULL_SCRN);

        cntx = (mmi_phb_speed_dial_pre_set_cntx_struct*)mmi_frm_group_get_user_data(scrn_data->group_id);

        for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; ++i)
        {
            switch (srv_phb_speed_dial_get_sync_status(i))
            {
                case SRV_PHB_SPEED_DIAL_SYNC_STATUS_OK:
                    if (srv_phb_speed_dial_get_store_index(i) != cntx->store_index)
                    {
                        item = srv_phb_speed_dial_get_name(i);
                        hint = srv_phb_speed_dial_get_number(i);
                        break;
                    }
                case SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING:
                    item = cntx->display_name;
                    switch (srv_phb_speed_dial_get_number_type(i))
                    {
                        case SRV_PHB_ENTRY_FIELD_NUMBER:
                            hint = cntx->contact->number;
                            break;
                    #ifdef __MMI_PHB_OPTIONAL_FIELD__
                        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
                            hint = cntx->contact->opt_num[0].number;
                            break;
                        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
                            hint = cntx->contact->opt_num[1].number;
                            break;
                        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                            hint = cntx->contact->opt_num[2].number;
                            break;
                    #endif /* (defined(__MMI_PHB_OPTIONAL_FIELD__)) */
                        default:
                            hint = NULL;
                            break;
                    }
                    break;
                case SRV_PHB_SPEED_DIAL_SYNC_STATUS_FAIL:
                default :
                    item = NULL;
                    hint = NULL;
                    break;
            }
            if (item && item[0] && hint && hint[0])
            {
                item_list[i] = (U8*)item;
                hint_list[i] = (U8*)hint;
            }
            else if (hint && hint[0])
            {
                item_list[i] = (U8*)hint;
                hint_list[i] = NULL;
            }
            else
            {
                item_list[i]= (U8*)GetString(STR_GLOBAL_EMPTY_LIST);
                hint_list[i] = NULL;
            }
        }

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_phb_speed_dial_pre_set_speed_highlight_hdlr);
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory53Screen(
            STR_ID_PHB_SPEED_DIAL_SETTING,
            IMG_SCR_PBOOK_CAPTION,
            STR_GLOBAL_SELECT,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MMI_PHB_SPEED_DIAL_COUNT,
            item_list,
            (U16*) (gIndexIconsImageList + 1),
            hint_list,
            0,
            0,
            gui_buffer);
        
        SetLeftSoftkeyFunction(mmi_phb_speed_dial_pre_set_select, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_speed_dial_pre_set_select, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_pre_set_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_speed_dial_pre_set_proc(mmi_event_struct *evt)
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
            mmi_phb_mem_free(evt->user_data);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_pre_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_pre_set_number(mmi_id sg_id, U16 store_index, U32 num_type, mmi_phb_contact_info_struct* contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_speed_dial_pre_set_cntx_struct* cntx =
            (mmi_phb_speed_dial_pre_set_cntx_struct*)mmi_phb_mem_malloc(
                sizeof(mmi_phb_speed_dial_pre_set_cntx_struct),
                SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->num_type = num_type;
    cntx->store_index = store_index;
    cntx->contact = contact;

    srv_phb_convert_to_name(
        cntx->display_name,
        contact->name,
    #ifdef __MMI_PHB_LAST_NAME_FIELD__    
        contact->last_name,
    #else
        NULL,
    #endif
        MMI_PHB_NAME_LENGTH);

    cntx->sg_id = mmi_frm_group_create_ex(
                    sg_id,
                    GRP_ID_AUTO_GEN,
                    mmi_phb_speed_dial_pre_set_proc,
                    cntx,
                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        cntx->sg_id,
        SCR_SPEED_DIAL_LIST,
        (FuncPtr)mmi_phb_entry_speed_dial_pre_set_number,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_pre_del_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_pre_del_number(U16 store_index, U32 num_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; ++i)
    {
        if ((srv_phb_speed_dial_get_number_type(i) & num_index) &&
            ((srv_phb_speed_dial_get_store_index(i) == store_index) ||
            srv_phb_speed_dial_get_sync_status(i) == SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING))
        {
            srv_phb_pre_del_speed_dial(i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_pre_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_speed_dial_set_number_commit(U16 store_index, mmi_phb_contact_info_struct* contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    WCHAR* number;
    U32 num_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_SPEED_DIAL_COUNT; ++i)
    {
        switch (srv_phb_speed_dial_get_sync_status(i))
        {
            case SRV_PHB_SPEED_DIAL_SYNC_STATUS_ADDING:
                num_type = srv_phb_speed_dial_get_number_type(i);
                number = NULL;
                switch (num_type)
                {
                    case SRV_PHB_ENTRY_FIELD_NUMBER:
                        if (contact->number[0])
                        {
                            number = contact->number;
                        }
                        break;

                #ifdef __MMI_PHB_OPTIONAL_FIELD__
                    case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
                        if (contact->opt_num[0].number[0])
                        {
                            number = contact->opt_num[0].number;
                        }
                        break;
                    case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
                        if (contact->opt_num[1].number[0])
                        {
                            number = contact->opt_num[1].number;
                        }
                        break;
                    case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                        if (contact->opt_num[2].number[0])
                        {
                            number = contact->opt_num[2].number;
                        }
                        break;
                #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

                    default:
                        break;
                }
                if (number)
                {
                    srv_phb_update_speed_dial(
                        i,
                        store_index,
                        number,
                        num_type);
                }
                else
                {
                    srv_phb_revert_syncing_speed_dial(i);
                }
                break;

            case SRV_PHB_SPEED_DIAL_SYNC_STATUS_DELING:
                srv_phb_delete_speed_dial(i);
                break;

            default:
                break;
        }
    }
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_speed_dial_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phb_get_speed_dial_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_speed_dial_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_id      [IN]        
 * RETURNS
 *  CHAR*
 *****************************************************************************/
CHAR* mmi_phb_speed_dial_get_number(U16 key_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}
#endif

#if 0
/* under construction !*/
#ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
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
#endif
#endif


#define MMI_PHB_MISC


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_call_launch_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  make_call_cb_para       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_call_launch_hdlr(mmi_ucm_after_make_call_cb_struct *make_call_cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_call_launch_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name            [IN]        
 *  number          [IN]        
 *  call_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_call_launch_ex(U16 *name, U16 *number, srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.dial_type = call_type;
    make_call_para.ucs2_num_uri = number;
    make_call_para.adv_para.after_make_call_callback = mmi_phb_call_launch_hdlr;

    cm_user_data = srv_phb_create_cm_user_data(name, 0, 0xFFFF);
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;

    mmi_ucm_call_launch(0, &make_call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_call_launch_with_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  number          [IN]        
 *  number_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_call_launch_with_type(U16 store_index, U16 *number, U32 number_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    void *cm_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!number[0] || number_type == 0xFFFFFFFF)
    {
        return;
    }
    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.dial_type = SRV_UCM_CALL_TYPE_ALL;
    make_call_para.ucs2_num_uri = number;
    make_call_para.adv_para.after_make_call_callback = mmi_phb_call_launch_hdlr;

    cm_user_data = srv_phb_create_cm_user_data(NULL, number_type, store_index);
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;

    mmi_ucm_call_launch(0, &make_call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_wild_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number          [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_phb_check_wild_character(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_wcschr(number, L'?') != NULL)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_fdn_replace_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_fdn_replace_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
        GRP_ID_PHB_EXTRA_NUMBER,
        SCR_ID_SECSET_FDN_REPLACE_CONFIRM,
        NULL,
        mmi_phb_entry_fdn_replace_confirm,
        MMI_FRM_UNKNOW_SCRN);

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
#if (MMI_MAX_SIM_NUM == 1) || (MMI_MAX_SIM_NUM >= 3)
    SetDialingKeypadCallHandler(mmi_phb_make_fdn_call);
#else
    if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
    {
        SetDialingKeypadCallHandler(mmi_phb_make_sim1_fdn_call);
    }
    if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
        SetDialingKeypadCall2Handler(mmi_phb_make_sim2_fdn_call);
    }
#endif
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */

    ShowCategory16Screen(
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) mmi_phb_extra_number_p->number,
        MAX_DIAL_PAD,
        mmi_frm_scrn_get_active_gui_buf());

    mmi_ucm_handle_sendkeys_for_call(mmi_phb_make_fdn_call, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_phb_make_fdn_call, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_make_fdn_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_make_fdn_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_make_fdn_call_ex(SRV_UCM_VOICE_CALL_TYPE_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_make_fdn_call_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_make_fdn_call_ex(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add some check for ? if the number to dial still contain ? */
    if (mmi_phb_check_wild_character(mmi_phb_extra_number_p->number))
    {
        mmi_phb_popup_display_ext(
            STR_ID_SECSET_REPLACE_WILDCARD,
            MMI_EVENT_FAILURE);
    }
    else
    {
        /*  Avoid adding the replace confirmation screen to history stack */
        if (mmi_frm_scrn_get_active_id() == SCR_ID_SECSET_FDN_REPLACE_CONFIRM)
        {
            mmi_frm_scrn_enter(GRP_ID_PHB_EXTRA_NUMBER, GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
        }
        mmi_frm_scrn_close(GRP_ID_PHB_EXTRA_NUMBER, SCR_ID_SECSET_FDN_REPLACE_CONFIRM);

        mmi_phb_call_launch_ex(
            srv_phb_xmgnt_get_entry_name(g_mmi_phb_handle, g_mmi_phb_active_index),
            mmi_phb_extra_number_p->number,
            call_type);
    }
}

#if (MMI_MAX_SIM_NUM == 2)

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_make_sim1_fdn_call
 * DESCRIPTION
 *  Dual SIM: make SIM1 fdn call via call icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_make_sim1_fdn_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_make_fdn_call_ex(SRV_UCM_VOICE_CALL_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_make_sim2_fdn_call
 * DESCRIPTION
 *  Dual SIM: make SIM2 fdn call via call icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_make_sim2_fdn_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_make_fdn_call_ex(SRV_UCM_VOICE_CALL_TYPE_SIM2);
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /* MMI_MAX_SIM_NUM >= 2 */



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_extra_number_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if available, or return MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_phb_check_extra_number_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sim_index = SIM1; sim_index < MMI_MAX_SIM_NUM; sim_index++)
    {
        if (srv_phb_startup_is_phb_support(sim_index, PHB_FDN)
        #ifdef __MMI_PHB_SLIM_EXTRA_DEFEATURE__
            || srv_phb_startup_is_phb_support(sim_index, PHB_MSISDN)
            || srv_phb_startup_is_phb_support(sim_index, PHB_SDN)
            || srv_phb_startup_is_phb_support(sim_index, PHB_ECC)
            || srv_phb_startup_is_phb_support(sim_index, PHB_BDN)
        #endif
            )
        {
            return MMI_TRUE;
        }
    }
#if 0
#if (defined(__MMI_PHB_SLIM_EXTRA_DEFEATURE__) && (defined(__MMI_PHB_ECC_DIRECT_DIAL__) || defined(__MMI_PHB_SOS_NUM_EDIT__))) || defined(__OP11__) /*__OP11__ for __MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
#else
/* under construction !*/
#endif
#else
#if defined(__MMI_PHB_SLIM_EXTRA_DEFEATURE__) && (defined(__MMI_PHB_ECC_DIRECT_DIAL__) || defined(__MMI_PHB_SOS_NUM_EDIT__))
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
#endif
}


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_construct_group_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  prepare item data for inline CUI
 *****************************************************************************/
void *mmi_phb_construct_group_editor(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_GROUP_SUPPORT__ 
    if (mmi_phb_check_storage(MMI_TRUE, (U8)storage))
    {
        return (void*) &g_mmi_phb_inline_screen6;
    }   
    else
    {
        return (void*) &g_mmi_phb_inline_screen7;
    }
#else
    return (void*) &g_mmi_phb_inline_screen6;
#endif    
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_popup_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_popup_display(UI_string_type text, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display(text, event_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_popup_display_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_popup_display_ext(MMI_STR_ID title_id, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(title_id, event_id, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_confirm_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [IN]        
 *  parent_id       [IN]        
 *  lsk_func        [IN]        
 *  rsk_func        [IN]        
 *  is_enable_csk   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_confirm_display(UI_string_type text, mmi_id parent_id, FuncPtr lsk_func, FuncPtr rsk_func, MMI_BOOL is_enable_csk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_phb_confirm_data_struct *confirm_data =
        mmi_phb_mem_malloc(sizeof(mmi_phb_confirm_data_struct), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = parent_id;
    arg.f_auto_map_empty_softkey = is_enable_csk;
    confirm_data->lsk_func = lsk_func;
    confirm_data->rsk_func = rsk_func;
    arg.user_tag = confirm_data;
    mmi_confirm_display(text, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_confirm_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [IN]        
 *  parent_id       [IN]        
 *  lsk_func        [IN]        
 *  rsk_func        [IN]        
 *  is_enable_csk   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_confirm_display_ext(MMI_STR_ID title_id, mmi_id parent_id, FuncPtr lsk_func, FuncPtr rsk_func, MMI_BOOL is_enable_csk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_confirm_display(
        (UI_string_type) GetString(title_id),
        parent_id,
        lsk_func,
        rsk_func,
        is_enable_csk);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_confirm_display_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_result    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_confirm_display_handle(mmi_alert_result_evt_struct *alert_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_confirm_data_struct *confirm_data = (mmi_phb_confirm_data_struct*) alert_result->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (alert_result->result)
    {
        case MMI_ALERT_CNFM_YES:
            (confirm_data->lsk_func)();
            break;

        case MMI_ALERT_CNFM_NO:
            (confirm_data->rsk_func)();
            break;

        case MMI_ALERT_NORMAL_EXIT:
        case MMI_ALERT_INTERRUPT_EXIT:
            mmi_phb_mem_free(confirm_data);
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_menu_cui_options_generic
 * DESCRIPTION
 *  Go back two screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_phb_entry_menu_cui_generic(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        menu_id,
                        MMI_FALSE,
                        (void*) (U32)menu_id);

    if (title_id != 0)
    {
        cui_menu_set_default_title_string_by_id(menu_cui_gid, title_id);
    }
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SCR_PBOOK_CAPTION);
#endif

    cui_menu_run(menu_cui_gid);

    return menu_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_menu_cui_options_generic
 * DESCRIPTION
 *  Go back two screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_phb_entry_menu_cui_create(MMI_ID parent_gid, MMI_MENU_ID menu_id, U16 title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_FROM_RESOURCE,
                        menu_id,
                        MMI_FALSE,
                        (void*) (U32)menu_id);

    if (title_id != 0)
    {
        cui_menu_set_default_title_string_by_id(menu_cui_gid, title_id);
    }
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SCR_PBOOK_CAPTION);
#endif

    return menu_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_menu_cui_generic_ext
 * DESCRIPTION
 *  Go back two screen history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_phb_entry_menu_cui_generic_ext(MMI_ID parent_gid, cui_menu_type_enum menu_type, MMI_MENU_ID menu_id, U16 title_id, void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        menu_type,
                        menu_id,
                        MMI_FALSE,
                        parent_data);

    if (title_id != 0)
    {
        cui_menu_set_default_title_string_by_id(menu_cui_gid, title_id);
    }
#ifndef __MMI_SMS_SLIM__
    cui_menu_set_default_title_image_by_id(menu_cui_gid, IMG_SCR_PBOOK_CAPTION);
#endif
    cui_menu_run(menu_cui_gid);
    return menu_cui_gid;
}


#endif /* PHONEBOOKEXTRANUMBER_C */

#else /* __MMI_LOCAL_PHB_SUPPORT__ */

void mmi_phb_popup_display_ext(MMI_STR_ID title_id, mmi_event_notify_enum event_id)
{
}


void mmi_phb_popup_display(UI_string_type text, mmi_event_notify_enum event_id)
{
}


CHAR* mmi_phb_speed_dial_get_number(U16 key_id)
{
    return NULL;
}


U8 mmi_phb_get_speed_dial_status(void)
{
    return 0;
}


MMI_BOOL mmi_phb_check_extra_number_available(void)
{
    return MMI_TRUE;
}


void mmi_phb_entry_group_extra_number(void)
{
}

#endif /* __MMI_LOCAL_PHB_SUPPORT__ */

