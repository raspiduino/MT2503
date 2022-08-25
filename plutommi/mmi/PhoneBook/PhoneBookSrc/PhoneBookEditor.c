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
 *  PhoneBookEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for phonebook main function.
 *  Including initialize procedure, main menu, common utilities, etc.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "PhoneBookGprot.h"
#include "PhoneBookProt.h"
#include "PhoneBookResDef.h"
#include "PhoneBookCore.h"
#include "PhbSrvGprot.h"
#include "PhbCuiGprot.h"
#include "MenuCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "InlineCuiGprot.h"
#include "PhoneBookEditor.h"
#include "PhoneBookTypes.h"
#include "mainmenudef.h"
#include "SettingGprots.h"
#include "SettingDefs.h"        /* For FDN on Message */
#include "SettingsGdcl.h"
#include "CommonScreens.h"
#include "datetimetype.h"
#include "app_datetime.h"
#include "MessagesExDcl.h"
#include "CallManagementGProt.h"
#include "OutgoingCallHelperProt.h"
#include "App_usedetails.h"
#include "ManageCallMain.h"

#include "App_datetime.h"
#if defined(__MMI_FILE_MANAGER__)
#include "FileManagerDef.h"     /* error string id */
#endif 

#include "FileMgr.h"    /* Should include FileMgr.h before ProfileMgrGprot.h */
#include "FileManagerGProt.h"

#if defined(__MMI_PHB_INFO_FIELD__)
#include "app_url.h"
#endif

#if defined(__MMI_PHB_CALLER_VIDEO__)
#include "DataMgr.h"
#include "VdoPlyGProt.h"
#include "VdoPlyResDef.h" /* Video Player String ID Enum */
#include "Mdi_datatype.h"
#include "Mdi_include.h"
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

#include "drm_gprot.h"

#if defined(__MMI_VCARD__)
#include "vObjects.h"
#include "vcard.h"
#endif /* defined(__MMI_VCARD__) */ 

#include "SmsSrvGprot.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UMGprot.h"
#include "UcAppGprot.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#include "MessagesMiscell.h"    /* for IsMessagesReEntering */
#include "MessagesResourceData.h"       /* for STR_SMS_MSG_NOT_READY_YET */
#include "SmsSrvGprot.h"
#include "SmsAppGprot.h"

#ifdef __MMI_MMS__
#include "Mmsadp.h"
#endif /* __MMI_MMS__ */

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGProt.h"
#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_BPP20_SUPPORT__)
#include "Conversions.h" /* for value buffer conversion */
#include "BppMmiGprot.h"
#include "BTMMIObexGprots.h"
#include "BTMMIScrGprots.h"
#endif

#include "UCMGprot.h"
#include "UcmSrvGprot.h"
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
#endif /* (__MMI_IMPS__) */
#endif

#ifdef __MMI_UDX_VCARD_SUPPORT__
#include "UDXGprot.h"
#endif

#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
#include "BirthdayGprot.h"
#endif
#endif

#include "simctrlsrvgprot.h"
#include "modeSwitchSrvGprot.h"
#include "mmi_rp_app_mainmenu_def.h"

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "wgui_inline_edit.h"
#include "GlobalResDef.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_phonebook_def.h"
#include "ps_public_enum.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "string.h"
#include "custom_phb_config.h"
#include "Unicodexdcl.h"
#include "wgui_inputs.h"
#include "stdio.h"
#include "PhbSrvIprot.h"
#include "kal_public_api.h"
#include "custom_mmi_default_value.h"
#include "gui.h"
#include "ImeGprot.h"
#include "wgui_categories_inputs.h"
#include "customer_email_num.h"
#include "gui_typedef.h"
#include "mmi_rp_app_uiframework_def.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_history_gprot.h"
/* auto add by kw_check end */
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__) && defined(__MMI_PHB_UI_IN_TABS__)
#include "wgui_fixed_menus.h" /* for show_fixed_list_specified_item */
#endif
#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvTypes.h"
#include "SnsSrvGprot.h"
#include "Browser_api.h"
#include "SnsAppGprot.h"
#include "mmi_rp_app_sns_def.h"
#endif
#include "USBSrvGprot.h"
#include "NwUsabSrvGprot.h"

/*----------------------------------------------------------------*/
/* Static Variables                                               */
/*----------------------------------------------------------------*/
#define MMI_PHB_EDIT_SCREEN_INPUT_BUFFER_SIZE 3000
#ifndef __MMI_PHB_UI_IN_TABS__
#define MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL (100)
#endif

/*----------------------------------------------------------------*/
/* Static Variables                                               */
/*----------------------------------------------------------------*/

/**
 * Edit a contact, fields order config array
 */
#ifndef __MMI_PHB_UI_IN_TABS__
/**
 * List editor default fields
 */
static const U8 phb_edit_field_default[] = 
{
    MMI_PHB_FIELD_NAME,
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    MMI_PHB_FIELD_LAST_NAME,
#endif
    MMI_PHB_FIELD_NUMBER,
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_FIELD_EMAIL,
#endif
#ifdef __MMI_PHB_CALLER_RES__
    MMI_PHB_FIELD_PIC,
    MMI_PHB_FIELD_RING,
#endif
    /**
     * Pls add field config before here
     */
    MMI_PHB_FIELD_TOTAL
};

/**
 * Add more field info
 */
const U8 phb_edit_field_optional[] =
{
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_FIELD_EMAIL,
#endif
#ifdef __MMI_PHB_CALLER_RES__
#if !defined(LOW_COST_SUPPORT) || (defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
    MMI_PHB_FIELD_PIC,
#endif
    MMI_PHB_FIELD_RING,
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_FIELD_MOBILE_NUMBER,
    MMI_PHB_FIELD_HOME_NUMBER,
    MMI_PHB_FIELD_OFFCIE_NUMBER,
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    MMI_PHB_FIELD_FAX_NUMBER,
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    MMI_PHB_FIELD_EMAIL2,
#endif
    MMI_PHB_FIELD_COMPANY_NAME,
#endif
#endif
#ifdef __MMI_PHB_CALLER_RES__
#if defined(__MMI_PHB_CALLER_VIDEO__)
    MMI_PHB_FIELD_VIDEO,
#endif
#endif
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    MMI_PHB_FIELD_BIRTHDAY,
#endif
    //MMI_PHB_FIELD_GROUP,
#if defined(__MMI_PHB_INFO_FIELD__)
    MMI_PHB_FIELD_TITLE,
    MMI_PHB_FIELD_URL,
    MMI_PHB_FIELD_ADDRESS,
    MMI_PHB_FIELD_NOTE,
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#endif
#if defined(__MMI_PHB_POC_FIELD__)
    MMI_PHB_FIELD_POC,
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
#endif
#endif

    /**
     * Pls add field config before here
     */
    MMI_PHB_FIELD_TOTAL
};

const U8 phb_edit_field_total[] =
{
    MMI_PHB_FIELD_NAME,
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    MMI_PHB_FIELD_LAST_NAME,
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
    MMI_PHB_FIELD_NICK_NAME,
#endif
    MMI_PHB_FIELD_NUMBER,
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_FIELD_EMAIL,
#endif
#ifdef __MMI_PHB_CALLER_RES__
    MMI_PHB_FIELD_PIC,
    MMI_PHB_FIELD_RING,
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_FIELD_OPT_NUM_1,
    MMI_PHB_FIELD_OPT_NUM_2,
    MMI_PHB_FIELD_OPT_NUM_3,
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    MMI_PHB_FIELD_EMAIL2,
#endif
    MMI_PHB_FIELD_COMPANY_NAME,
#endif
#ifdef __MMI_PHB_CALLER_RES__
#if defined(__MMI_PHB_CALLER_VIDEO__)
    MMI_PHB_FIELD_VIDEO,
#endif
#endif
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    MMI_PHB_FIELD_BIRTHDAY,
#endif
    MMI_PHB_FIELD_GROUP,
#if defined(__MMI_PHB_INFO_FIELD__)
    MMI_PHB_FIELD_TITLE,
    MMI_PHB_FIELD_URL,
    MMI_PHB_FIELD_ADDRESS,
    MMI_PHB_FIELD_NOTE,
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#endif
#if defined(__MMI_PHB_POC_FIELD__)
    MMI_PHB_FIELD_POC,
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
#endif
#endif

    /**
     * Pls add field config before here
     */
    MMI_PHB_FIELD_TOTAL
};


#else /* __MMI_PHB_UI_IN_TABS__ */
/**
 * Tab editor field config
 */
static const U8 phb_edit_default_field_tab[MMI_PHB_EDITOR_TAB_TOTAL][MMI_PHB_EDITOR_TAB_ITEM_TOTAL] =
{
    {
        MMI_PHB_FIELD_NAME,
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        MMI_PHB_FIELD_LAST_NAME,
    #endif
        MMI_PHB_FIELD_NUMBER,

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },
    
    {
    #ifdef __MMI_PHB_CALLER_RES__
        MMI_PHB_FIELD_PIC,
        MMI_PHB_FIELD_RING,
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        MMI_PHB_FIELD_VIDEO,
    #endif
    #endif
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        MMI_PHB_FIELD_BIRTHDAY,
    #endif
        //MMI_PHB_FIELD_GROUP,

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },
    
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        MMI_PHB_FIELD_EMAIL,
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        MMI_PHB_FIELD_EMAIL2,
    #endif
        MMI_PHB_FIELD_COMPANY_NAME,
    #endif
    #endif
    
        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },
    
    {
    #if defined(__MMI_PHB_INFO_FIELD__)
        MMI_PHB_FIELD_TITLE,
        MMI_PHB_FIELD_URL,
        MMI_PHB_FIELD_ADR_POBOX,
        MMI_PHB_FIELD_ADR_EXTENSION,
        MMI_PHB_FIELD_ADR_STREET,
        MMI_PHB_FIELD_ADR_CITY,
        MMI_PHB_FIELD_ADR_STATE,
        MMI_PHB_FIELD_ADR_POSTALCODE,
        MMI_PHB_FIELD_ADR_COUNTRY,
        MMI_PHB_FIELD_NOTE,
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
    
        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },
    
    {
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
    #endif
	#endif
    #if defined(__MMI_PHB_POC_FIELD__)
        MMI_PHB_FIELD_POC,
    #endif
	#if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
    #endif
    #endif
    
        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    }
};


#ifdef __MMI_PHB_USIM_SUPPORT__ 
static const U8 phb_usim_edit_total_field_tab[MMI_PHB_USIM_EDITOR_TAB_TOTAL][MMI_PHB_EDITOR_TAB_ITEM_TOTAL] =
{
    
    {
        MMI_PHB_FIELD_NAME,
        MMI_PHB_FIELD_NICK_NAME,
        MMI_PHB_FIELD_NUMBER,
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        MMI_PHB_FIELD_OPT_NUM_1,
        MMI_PHB_FIELD_OPT_NUM_2,
        MMI_PHB_FIELD_OPT_NUM_3,
    #endif
        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        MMI_PHB_FIELD_EMAIL,
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)      
        MMI_PHB_FIELD_EMAIL2,
    #endif
    #endif
        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },
};
#endif


static const U8 phb_edit_total_field_tab[MMI_PHB_EDITOR_TAB_TOTAL][MMI_PHB_EDITOR_TAB_ITEM_TOTAL] =
{
    {
        MMI_PHB_FIELD_NAME,
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        MMI_PHB_FIELD_LAST_NAME,
    #endif
    #ifdef __MMI_SNS_CONTACTS__
        MMI_PHB_SNS_NAME,
    #endif
        MMI_PHB_FIELD_NUMBER,
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        MMI_PHB_FIELD_OPT_NUM_1,
        MMI_PHB_FIELD_OPT_NUM_2,
        MMI_PHB_FIELD_OPT_NUM_3,
    #endif
    #ifdef __MMI_SNS_CONTACTS__
        MMI_PHB_SNS_NUMBER,
    #endif

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },

    {
    #ifdef __MMI_PHB_CALLER_RES__
        MMI_PHB_FIELD_PIC,
        MMI_PHB_FIELD_RING,
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        MMI_PHB_FIELD_VIDEO,
    #endif
    #endif
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        MMI_PHB_FIELD_BIRTHDAY,
    #endif
    #ifdef __MMI_SNS_CONTACTS__
        MMI_PHB_SNS_BIRTHDAY,
    #endif

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },

    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        MMI_PHB_FIELD_EMAIL,
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        MMI_PHB_FIELD_EMAIL2,
    #endif
    #endif
    #endif  
    #ifdef __MMI_SNS_CONTACTS__
        MMI_PHB_SNS_EMAIL,
    #endif
    #ifdef __MMI_PHB_OPTIONAL_FIELD__   
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        MMI_PHB_FIELD_COMPANY_NAME,
    #endif
    #endif

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },

    {
    #if defined(__MMI_PHB_INFO_FIELD__)
        MMI_PHB_FIELD_TITLE,
        MMI_PHB_FIELD_URL,
    #endif
    #ifdef __MMI_SNS_CONTACTS__
        MMI_PHB_SNS_URL,
    #endif
    #if defined(__MMI_PHB_INFO_FIELD__)
        MMI_PHB_FIELD_ADR_POBOX,
        MMI_PHB_FIELD_ADR_EXTENSION,
        MMI_PHB_FIELD_ADR_STREET,
        MMI_PHB_FIELD_ADR_CITY,
        MMI_PHB_FIELD_ADR_STATE,
        MMI_PHB_FIELD_ADR_POSTALCODE,
        MMI_PHB_FIELD_ADR_COUNTRY,
        MMI_PHB_FIELD_NOTE,
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    },

    {
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
    #endif
	#endif
    #if defined(__MMI_PHB_POC_FIELD__)
        MMI_PHB_FIELD_POC,
    #endif
	#if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
    #endif
    #endif

        /**
         * Pls add field config before here
         */
        MMI_PHB_FIELD_TOTAL
    }
};

#endif /* __MMI_PHB_UI_IN_TABS__ */
/**
 * Add more field info
 */
const U8 phb_edit_number_type[] =
{
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_FIELD_MOBILE_NUMBER,
    MMI_PHB_FIELD_HOME_NUMBER,
    MMI_PHB_FIELD_OFFCIE_NUMBER,
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    MMI_PHB_FIELD_FAX_NUMBER,
#endif
#endif

    /**
     * Pls add field config before here
     */
    MMI_PHB_FIELD_TOTAL
};

#ifdef __MMI_PHB_USIM_SUPPORT__
const U8 phb_edit_usim_field_optional[] =
{
    MMI_PHB_USIM_FIELD_SNE,
    MMI_PHB_USIM_FIELD_ANR1,
    MMI_PHB_USIM_FIELD_ANR2,
    MMI_PHB_USIM_FIELD_ANR3,
    MMI_PHB_USIM_FIELD_EMAIL1,
    MMI_PHB_USIM_FIELD_EMAIL2,
    /**
     * Pls add field config before here
     */
    MMI_PHB_USIM_FIELD_TOTAL
};


const U8 phb_edit_usim_number_type[]=
{
    MMI_PHB_USIM_FIELD_ANR1,
    MMI_PHB_USIM_FIELD_ANR2,
    MMI_PHB_USIM_FIELD_ANR3,
    
    MMI_PHB_USIM_FIELD_TOTAL

};
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_VOIP__) */
#endif

/*----------------------------------------------------------------*/
/* Global Variables                                               */
/*----------------------------------------------------------------*/
/**
 * For add/edit/view a contact
 */
mmi_phb_contact_info_struct *g_mmi_phb_contact_p;


/**
 * For add/edit a contact
 */
mmi_phb_save_contact_cntx_struct *g_mmi_phb_save_contact_p;

/**
 * For view a contact
 */
mmi_phb_view_contact_cntx_struct *g_mmi_phb_view_contact_p;

/**
 * For know left key whether options
 */
MMI_BOOL g_mmi_phb_edit_option;

U8 g_mmi_phb_item_list[2 * MAX_PB_FIELDS];

const UI_character_type mmi_phb_e_mail_allowed[] = L"+_\\-.@A-Za-z0-9";

/*----------------------------------------------------------------*/
/* Extern Variables                                               */
/*----------------------------------------------------------------*/
extern mmi_phb_op_cntx_struct g_mmi_phb_op_cntx;

extern wgui_inline_item wgui_inline_items[];

#ifdef __MMI_PHB_UI_IN_TABS__
extern U8 wgui_inline_list_menu_changed;
#endif

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
extern const kal_uint8 g_dt_day_per_mon[];
#endif

extern mmi_phb_confirm_user_data_struct g_mmi_phb_confirm_user_data;

/*----------------------------------------------------------------*/
/* Static function                                                */
/*----------------------------------------------------------------*/
#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
#endif
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#if defined(__MMI_PHB_UI_IN_TABS__) && defined(__MMI_FTE_SUPPORT__)
static void mmi_phb_bday_changed_callback(U16 index);
#endif
#ifdef __MMI_BIRTHDAY_REMINDER__
static void mmi_phb_edit_add_birthday_reminder(void);
#endif
#endif

extern void SetInlineIconStyle(InlineItem *item, PU8 picon, BOOL b);

#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
static void mmi_phb_entry_set_default_number(void);
static void mmi_phb_entry_cancel_default_number(void);
#endif
#ifdef __MMI_PHB_SPEED_DIAL__
static void mmi_phb_entry_set_speed_number(mmi_id sg_id);
static void mmi_phb_entry_cancel_speed_number(mmi_id sg_id);
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
MMI_BOOL mmi_phb_check_usim_detail(U8 storage,U8 field_type);
void mmi_phb_entry_usim_change_number_type(void);

#endif
#if defined(__MMI_PHB_UI_IN_TABS__) && !defined (__MMI_FTE_SUPPORT__)
static void mmi_phb_pre_entry_inline_edit_num_for_tab(void);
static void mmi_phb_entry_inline_edit_name_for_tab(void);
static void mmi_phb_entry_inline_edit_num_for_tab(void);
#endif
#ifndef __MMI_PHB_UI_IN_TABS__
static void mmi_phb_entry_edit_ok(void);
static void mmi_phb_entry_add_details(void);
static void mmi_phb_entry_edit_delete_details(void);
#endif

#ifdef __MMI_PHB_OPTIONAL_FIELD__
extern void mmi_phb_entry_change_number_type(void);
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#ifdef __MMI_INLINE_SLIM__
extern void wgui_inline_lsk_fs_cui_editor(void);
extern void wgui_inline_lsk_menu_cui_select(void);
#endif

static void mmi_phb_entry_op_add_entry(void);
static MMI_BOOL mmi_phb_edit_field_display(U8 field_type, U32 field_mask, U8 storage);
static U16 mmi_phb_get_str_by_number_type(mmi_phb_num_type_enum number_type);
static U16 mmi_phb_get_first_name_str(U8 storage);
static void mmi_phb_entry_op_remove_invalid_name_and_number(mmi_phb_contact_info_struct *contact);
static void mmi_phb_set_full_scr_lsk(void);
static void mmi_phb_set_full_scr_lsk_for_email(void);
static void mmi_phb_set_full_scr_lsk_for_number(void);
static U16 mmi_phb_get_email_address_id(U16 index,U8 storage);
static void mmi_phb_pre_entry_op_add_entry(void);
static void mmi_phb_exit_op_add_entry(void);
static void mmi_phb_op_fill_inline_item(U16 item_id, U16 pre_item_id, U8 storage, mmi_id inline_id);
static void mmi_phb_entry_choose_storage(mmi_phb_save_contact_cntx_struct* scrn_data);
static void mmi_phb_exit_op_view_entry(void);
static void mmi_phb_view_entry_send_key_hdlr(void);
static void mmi_phb_view_entry_highlight_hdlr(S32 index);
static void mmi_phb_get_value(mmi_id gid, U16 item_id, void *value);
static void mmi_phb_get_item_value(mmi_id gid);
static void mmi_phb_construct_inline_editor(cui_inline_struct* inline_struct);
static void mmi_phb_contact_delete_field(
                U32 field_mask,
                mmi_phb_contact_info_struct *contact,
                mmi_phb_caller_res_struct *res);

static void mmi_phb_delete_usim_detail(U32 field_mask,mmi_phb_contact_info_struct *contact);
#ifdef __MMI_PHB_UI_IN_TABS__
static void mmi_phb_entry_op_add_entry(void);
static void mmi_phb_entry_edit_contact_entry_inline_tab_0(void);
static void mmi_phb_entry_view_contact_entry_inline_tab_0(void);
static void mmi_phb_entry_edit_contact_entry_inline_tab_1(void);
static void mmi_phb_entry_view_contact_entry_inline_tab_1(void);
static void mmi_phb_entry_edit_contact_entry_inline_tab_2(void);
static void mmi_phb_entry_view_contact_entry_inline_tab_2(void);
static void mmi_phb_entry_edit_contact_entry_inline_tab_3(void);
static void mmi_phb_entry_view_contact_entry_inline_tab_3(void);
static void mmi_phb_entry_edit_contact_entry_inline_tab_4(void);
static void mmi_phb_entry_view_contact_entry_inline_tab_4(void);

#endif /* __MMI_PHB_UI_IN_TABS__ */




#define MMI_PHB_ADD_CONTACT
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sc_proc
 * DESCRIPTION
 *  phonebook & short cut proc function
 * PARAMETERS
 *  evt
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phb_sc_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            cui_phb_save_contact_close(((cui_phb_save_contact_result_struct*) evt)->sender_id);
            break;

        default:
            break;
    }
 
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_new_entry_ext
 * DESCRIPTION
 *  add new contact function for center key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_add_new_entry_ext(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    mmi_phb_list_cntx_struct *list_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_OP_ADD_NEW_ENTRY);

    if (parent_id != GRP_ID_INVALID)
    {
        sg_id = cui_phb_save_contact_create(parent_id);
        /**
         * get list cntx
         */
        list_cntx = mmi_frm_group_get_user_data(parent_id);

        /**
         * Save child sg id for close it
         */
        list_cntx->child_id = sg_id;

        cui_phb_save_contact_run(sg_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sc_add_new_entry
 * DESCRIPTION
 *  add entry highlight handler for shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_op_add_new_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_add_new_entry_ext(mmi_phb_cntx_mgr_get_current_sg_id());
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sc_add_new_entry
 * DESCRIPTION
 *  add entry highlight handler for shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_sc_add_new_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_PHB_SC,
        mmi_phb_sc_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    sg_id = cui_phb_save_contact_create(GRP_ID_PHB_SC);
    cui_phb_save_contact_run(sg_id);
}


#ifdef __MMI_PHB_USIM_SUPPORT__

U8 mmi_phb_get_aas_type_label(U8 index,U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *type_array = NULL;
    U8 type_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type_array = (U8 *) mmi_phb_mem_malloc(sizeof(U8)*MMI_PHB_FIELD_LABEL_COUNT ,SRV_PHB_MEMORY_TYPE_ADM);
    srv_phb_get_field_type_list(type_array, MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)storage);
    type_id = type_array[index];
    mmi_phb_mem_free(type_array);
    return type_id;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_new_entry_choose_storage_check
 * DESCRIPTION
 *  check sim valid and dynamic sim name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_new_entry_choose_storage_check(mmi_id sender_id, U16 menu_id, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#if (MMI_MAX_SIM_NUM >= 3)
    U16 new_id = STR_GLOBAL_SIM;
#endif
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < MMI_MAX_SIM_NUM; count++)
    {
        if (!srv_sim_ctrl_is_available(MMI_SIM1 << count))
        {
            cui_menu_set_item_hidden(sender_id, menu_id + count, MMI_TRUE);
        }
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__   
        else
        {
            if (count <= 1)
            {
                mmi_phb_sim_dynamic_name(MMI_SIM1 << count, sender_id, menu_id + count, string_id + count);
            }
        #if (MMI_MAX_SIM_NUM >= 3)
            else if (count == 2)
            {
                if (STR_ID_PHB_FROM_SIM1 == string_id)
                {
                    new_id = STR_ID_PHB_FROM_SIM3;    
                }
                else if (STR_ID_PHB_TO_SIM1 == string_id)
                {
                    new_id = STR_ID_PHB_TO_SIM3;      
                }
                mmi_phb_sim_dynamic_name(MMI_SIM1 << count, sender_id, menu_id + count, new_id);
            }
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            else
            {
                if (STR_ID_PHB_FROM_SIM1 == string_id)
                {
                    new_id = STR_ID_PHB_FROM_SIM4;    
                }
                else if (STR_ID_PHB_TO_SIM1 == string_id)
                {
                    new_id = STR_ID_PHB_TO_SIM4;      
                }
                mmi_phb_sim_dynamic_name(MMI_SIM1 << count, sender_id, menu_id + count, new_id);
            }
        #endif
        }
    #endif
    }
}


mmi_ret mmi_phb_choose_storage_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->parent_menu_id == MITEM102_PBOOK_NEW_ENTRY)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            #if (MMI_MAX_SIM_NUM >= 2)
                mmi_phb_new_entry_choose_storage_check(menu_evt->sender_id, MITEM_ADD_ENTRY_TO_SIM, STR_ID_PHB_TO_SIM1);
            #else
                mmi_phb_new_entry_choose_storage_check(menu_evt->sender_id, MITEM_ADD_ENTRY_TO_SIM, STR_ID_PHB_TO_SIM);
            #endif
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                mmi_phb_memory_card_not_available_hide_menu(menu_evt->sender_id, MITEM_ADD_ENTRY_TO_MEMORY_CARD);
            #endif
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MITEM_ADD_ENTRY_TO_SIM)
            {
                g_mmi_phb_save_contact_p->storage = PHB_STORAGE_SIM;
    
                if (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage) == SRV_PHB_STORAGE_STATUS_FULL)
                {
                    string_id = mmi_phb_get_storage_full_str_id(g_mmi_phb_save_contact_p->storage);                  
                    mmi_popup_display_simple_ext(
                            string_id,
                            MMI_EVENT_FAILURE,
                            g_mmi_phb_save_contact_p->sg_id,
                            0);
                }
                else
                {
                    mmi_phb_pre_entry_op_add_entry();
                }
            }
            else if (menu_evt->highlighted_menu_id == MITEM_ADD_ENTRY_TO_PHONE)
            {
                g_mmi_phb_save_contact_p->storage = PHB_STORAGE_NVRAM;
    
                if (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage) == SRV_PHB_STORAGE_STATUS_FULL)
                {
                    mmi_popup_display_simple_ext(
                            STR_PHONE_FULL_MSG,
                            MMI_EVENT_FAILURE,
                            g_mmi_phb_save_contact_p->sg_id,
                            0);
                }
                else
                {
                    mmi_phb_pre_entry_op_add_entry();
                }
            }
        #if (MMI_MAX_SIM_NUM >= 2)
            else if(menu_evt->highlighted_menu_id == MENU_MTPNP_PB_ADD_SIM2)
            {
                g_mmi_phb_save_contact_p->storage = PHB_STORAGE_SIM2;
    
                if (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage) == SRV_PHB_STORAGE_STATUS_FULL)
                {
                    string_id = mmi_phb_get_storage_full_str_id(g_mmi_phb_save_contact_p->storage);                               
                    mmi_popup_display_simple_ext(
                            string_id,
                            MMI_EVENT_FAILURE,
                            g_mmi_phb_save_contact_p->sg_id,
                            0);
                }
                else
                {
                    mmi_phb_pre_entry_op_add_entry();
                }
            }
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
            else if(menu_evt->highlighted_menu_id == MENU_MTPNP_PB_ADD_SIM3)
            {
                g_mmi_phb_save_contact_p->storage = PHB_STORAGE_SIM3;
    
                if (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage) == SRV_PHB_STORAGE_STATUS_FULL)
                {
                    string_id = mmi_phb_get_storage_full_str_id(g_mmi_phb_save_contact_p->storage);                  
                    mmi_popup_display_simple_ext(
                            string_id,
                            MMI_EVENT_FAILURE,
                            g_mmi_phb_save_contact_p->sg_id,
                            0);
                }
                else
                {
                    mmi_phb_pre_entry_op_add_entry();
                }
            }
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            else if(menu_evt->highlighted_menu_id == MENU_MTPNP_PB_ADD_SIM4)
            {
                g_mmi_phb_save_contact_p->storage = PHB_STORAGE_SIM4;
    
                if (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage) == SRV_PHB_STORAGE_STATUS_FULL)
                {
                    string_id = mmi_phb_get_storage_full_str_id(g_mmi_phb_save_contact_p->storage);                  
                    mmi_popup_display_simple_ext(
                            string_id,
                            MMI_EVENT_FAILURE,
                            g_mmi_phb_save_contact_p->sg_id,
                            0);
                }
                else
                {
                    mmi_phb_pre_entry_op_add_entry();
                }
            }
        #endif
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            else if(menu_evt->highlighted_menu_id == MITEM_ADD_ENTRY_TO_MEMORY_CARD)
            {
                g_mmi_phb_save_contact_p->storage = PHB_STORAGE_TCARD;

                if (mmi_phb_memory_card_is_ready(PHB_STORAGE_TCARD, MMI_TRUE))
                {
                    if (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage) == SRV_PHB_STORAGE_STATUS_FULL)
                    {
                        string_id = mmi_phb_get_storage_full_str_id(g_mmi_phb_save_contact_p->storage);                               
                        mmi_popup_display_simple_ext(
                                string_id,
                                MMI_EVENT_FAILURE,
                                g_mmi_phb_save_contact_p->sg_id,
                                0);
                    }
                    else
                    {
                        mmi_phb_pre_entry_op_add_entry();
                    }
                }
            }
        #endif
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
        }
        
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_choose_storage
 * DESCRIPTION
 *  choose storage entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_choose_storage(mmi_phb_save_contact_cntx_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_CHOOSE_STORAGE);
    
    menu_gid = cui_menu_create(
               scrn_data->sg_id,
               CUI_MENU_SRC_TYPE_RESOURCE,
               CUI_MENU_TYPE_APPSUB,
               MITEM102_PBOOK_NEW_ENTRY,
               MMI_FALSE, scrn_data);

    g_mmi_phb_save_contact_p->menu_storage_id = menu_gid;

#ifdef __MMI_PHB_USIM_SUPPORT__
    if (g_mmi_phb_save_contact_p->is_from_email && !mmi_phb_check_usim_detail_ex(PHB_STORAGE_SIM, 0, PHB_EMAIL))
    {
        cui_menu_set_item_hidden(menu_gid, MITEM_ADD_ENTRY_TO_SIM, MMI_TRUE);        
    }
#endif

#if (MMI_MAX_SIM_NUM >= 2)
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (g_mmi_phb_save_contact_p->is_from_email && !mmi_phb_check_usim_detail_ex(PHB_STORAGE_SIM2, 0, PHB_EMAIL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM2, MMI_TRUE);        
    }
#endif
#endif /* MMI_MAX_SIM_NUM >= 2 */

#if (MMI_MAX_SIM_NUM >= 3)
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (g_mmi_phb_save_contact_p->is_from_email && !mmi_phb_check_usim_detail_ex(PHB_STORAGE_SIM3, 0, PHB_EMAIL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM3, MMI_TRUE);        
    }
#endif
#endif

#if (MMI_MAX_SIM_NUM >= 4)
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (g_mmi_phb_save_contact_p->is_from_email && !mmi_phb_check_usim_detail_ex(PHB_STORAGE_SIM4, 0, PHB_EMAIL))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_MTPNP_PB_ADD_SIM4, MMI_TRUE);        
    }
#endif
#endif

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_add_pre_entry
 * DESCRIPTION
 *  Checks the phone book list is empty or not
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_add_pre_entry(mmi_phb_save_contact_cntx_struct *save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_string = 0;
    MMI_BOOL entry_choose_storage = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_OP_ADD_ENTRY);

    if (save_cntx->action == MMI_PHB_OP_ADD)
    {
        switch (save_cntx->storage)
        {
            case PHB_STORAGE_MAX:
                if (srv_phb_get_total_contact(PHB_STORAGE_MAX) ==
                    srv_phb_get_used_contact(PHB_STORAGE_MAX))
                {
                    error_string = STR_PBOOK_FULL_MSG;
                }
                else
                {
                    entry_choose_storage = MMI_TRUE;
                }
                break;

            case PHB_STORAGE_NVRAM:
                if (srv_phb_get_total_contact(PHB_STORAGE_NVRAM) ==
                    srv_phb_get_used_contact(PHB_STORAGE_NVRAM))
                {
                    error_string = STR_PHONE_FULL_MSG;
                }
                break;

            case PHB_STORAGE_SIM:
                if (!srv_sim_ctrl_is_available(MMI_SIM1))
                {
                    error_string = STR_ID_PHB_INVLID_PREFFER_STORAGE;
                }
                else if (srv_phb_get_total_contact(PHB_STORAGE_SIM) ==
                         srv_phb_get_used_contact(PHB_STORAGE_SIM))
                {  
                    error_string = mmi_phb_get_storage_full_str_id(save_cntx->storage);
                }
                break;

        #if (MMI_MAX_SIM_NUM >= 2)
            case PHB_STORAGE_SIM2:
                if (!srv_sim_ctrl_is_available(MMI_SIM2))
                {
                    error_string = STR_ID_PHB_INVLID_PREFFER_STORAGE;
                }
                else if (srv_phb_get_total_contact(PHB_STORAGE_SIM2) ==
                         srv_phb_get_used_contact(PHB_STORAGE_SIM2))
                {
                    error_string = mmi_phb_get_storage_full_str_id(save_cntx->storage);
                }
                break;
        #endif

        #if (MMI_MAX_SIM_NUM >= 3)
            case PHB_STORAGE_SIM3:
                if (!srv_sim_ctrl_is_available(MMI_SIM3))
                {
                    error_string = STR_ID_PHB_INVLID_PREFFER_STORAGE;
                }
                else if (srv_phb_get_total_contact(PHB_STORAGE_SIM3) ==
                         srv_phb_get_used_contact(PHB_STORAGE_SIM3))
                {
                    error_string = mmi_phb_get_storage_full_str_id(save_cntx->storage);
                }
                break;
        #endif

        #if (MMI_MAX_SIM_NUM >= 4)
            case PHB_STORAGE_SIM4:
                if (!srv_sim_ctrl_is_available(MMI_SIM4))
                {
                    error_string = STR_ID_PHB_INVLID_PREFFER_STORAGE;
                }
                else if (srv_phb_get_total_contact(PHB_STORAGE_SIM4) ==
                         srv_phb_get_used_contact(PHB_STORAGE_SIM4))
                {
                    error_string = mmi_phb_get_storage_full_str_id(save_cntx->storage);
                }
                break;
        #endif

        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            case PHB_STORAGE_TCARD:
                if (!srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
                {
                    error_string = STR_ID_PHB_INVLID_PREFFER_STORAGE;
                }
                else if (!mmi_phb_memory_card_is_ready(PHB_STORAGE_TCARD, MMI_FALSE))
                {
                    error_string = STR_ID_PHB_MEMORY_CARD_NOT_AVAILABLE;    
                }
                else if (srv_phb_get_total_contact(PHB_STORAGE_TCARD) ==
                         srv_phb_get_used_contact(PHB_STORAGE_TCARD))
                {  
                    error_string = mmi_phb_get_storage_full_str_id(save_cntx->storage);
                }
                break;
         #endif
            
            default:
                entry_choose_storage = MMI_TRUE;
                break;
        }
    }

#ifdef __MMI_PHB_USIM_SUPPORT__
    if (!entry_choose_storage
        && mmi_phb_check_storage(MMI_FALSE, save_cntx->storage)
        && save_cntx->is_from_email
        && !mmi_phb_check_usim_detail_ex((phb_storage_enum)save_cntx->storage, 0, PHB_EMAIL))
    {
        error_string = STR_ID_PHB_EMAIL_NOT_SUPPORT;
    }
#endif

    if (error_string != 0)
    {
        mmi_popup_display_simple_ext(
            error_string,
            MMI_EVENT_FAILURE,
            save_cntx->sg_id,
            NULL);
        
        return;
    }
    
    if (entry_choose_storage)
    { 
        mmi_phb_entry_choose_storage(save_cntx);
    }
    else
    {
        mmi_phb_pre_entry_op_add_entry();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_op_add_entry
 * DESCRIPTION
 *  check before add entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_pre_entry_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_PRE_ENTRY_ADD_ENTRY);
    
    if (!srv_phb_check_storage_accessible(g_mmi_phb_save_contact_p->storage))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            g_mmi_phb_save_contact_p->sg_id,
            0);

        return;
    }
    else
    {
        mmi_phb_entry_op_add_entry();
        mmi_frm_group_close(g_mmi_phb_save_contact_p->menu_add_replace_id);
        mmi_frm_group_close(g_mmi_phb_save_contact_p->menu_storage_id);
    }
}


#ifdef __MMI_SAVE_CONTACT_REPLACE__

void mmi_phb_save_replace_list_cntx_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->update_list == NULL)
    {
        MMI_PHB_LOG(TRC_MMI_PHB_SAVE_REPLACE_LIST_CNTX_CREATE);
        
        g_mmi_phb_save_contact_p->update_list = (mmi_phb_list_cntx_struct *) mmi_phb_mem_malloc(sizeof(mmi_phb_list_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(g_mmi_phb_save_contact_p->update_list, 0, sizeof(mmi_phb_list_cntx_struct));
        
        g_mmi_phb_save_contact_p->update_list->contact_array = mmi_phb_mem_malloc(sizeof(U16) * MMI_PHB_ENTRIES ,SRV_PHB_MEMORY_TYPE_ADM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_unsaved_data_update_contact
 * DESCRIPTION
 *  replace contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_save_contact_opt_update_contact(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(g_mmi_phb_save_contact_p->edit_temp_buff, g_mmi_phb_contact_p->number);
    
    mmi_phb_contact_get_contact_info(g_mmi_phb_list_p->store_index, g_mmi_phb_contact_p);
    
    switch (g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index])
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            mmi_wcscpy(g_mmi_phb_contact_p->number, g_mmi_phb_save_contact_p->edit_temp_buff);
            break;
    #ifdef __MMI_PHB_OPTIONAL_FIELD__            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            mmi_wcscpy(g_mmi_phb_contact_p->opt_num[0].number, g_mmi_phb_save_contact_p->edit_temp_buff);
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:            
            mmi_wcscpy(g_mmi_phb_contact_p->opt_num[1].number, g_mmi_phb_save_contact_p->edit_temp_buff);
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:            
            mmi_wcscpy(g_mmi_phb_contact_p->opt_num[2].number, g_mmi_phb_save_contact_p->edit_temp_buff);
            break;
    #endif
    
        default:
            break;
    }

    if (!mmi_phb_op_check_pre_save(g_mmi_phb_contact_p, srv_phb_get_storage(g_mmi_phb_list_p->store_index), MMI_TRUE))
    {
        mmi_wcscpy(g_mmi_phb_contact_p->number, g_mmi_phb_save_contact_p->edit_temp_buff);
        mmi_frm_scrn_close(sg_id, SCR_CHOOSE_NUMBER);
    }
    else
    {
        g_mmi_phb_save_contact_p->action = MMI_PHB_OP_EDIT;
        g_mmi_phb_save_contact_p->store_index = g_mmi_phb_list_p->store_index;
        g_mmi_phb_save_contact_p->storage = srv_phb_get_storage(g_mmi_phb_list_p->store_index);
        
        mmi_phb_show_in_progress(sg_id, STR_GLOBAL_SAVING);

        mmi_phb_op_save_contact_ex();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_opt_update_contact_confirm
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_opt_update_contact_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = g_mmi_phb_save_contact_p->sg_id;
    arg.callback = (mmi_proc_func)mmi_phb_comfirm_proc;

    mmi_phb_confirm_user_data_init(&g_mmi_phb_confirm_user_data);
    g_mmi_phb_confirm_user_data.sg_id = g_mmi_phb_save_contact_p->sg_id;
    g_mmi_phb_confirm_user_data.LSK_function = mmi_phb_save_contact_opt_update_contact;

    arg.user_tag = (void *)&g_mmi_phb_confirm_user_data;

    mmi_confirm_display(
        (WCHAR *) get_string(STR_ID_SAVE_CONTACT_REPLACE_QUERY),
        MMI_EVENT_QUERY,
        &arg);
}


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_opt_choose_type_done
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_opt_choose_type_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 added_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    S32 i, index;
    U8 temp_type;
    U8 storage;
    U8 type_array[MMI_PHB_FIELD_LABEL_COUNT];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage = srv_phb_get_storage(g_mmi_phb_list_p->store_index);
    srv_phb_get_field_type_list(type_array, MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)storage);
    mmi_wcscpy(g_mmi_phb_save_contact_p->edit_temp_buff, g_mmi_phb_contact_p->number);

    mmi_phb_contact_get_contact_info(g_mmi_phb_list_p->store_index, g_mmi_phb_contact_p);

    do
    {
        if (added_type == MMI_PHB_FIELD_MOBILE_NUMBER
        #ifdef __MMI_PHB_USIM_SUPPORT__
            || (g_mmi_phb_choose_field.highlight_index < 1)
        #endif
            )
        {
            if (!g_mmi_phb_contact_p->number[0])
            {
                mmi_wcscpy(g_mmi_phb_contact_p->number, g_mmi_phb_save_contact_p->edit_temp_buff);
                break;
            }
        }
        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            temp_type = g_mmi_phb_contact_p->opt_order[i];
            index = (U32)(mmi_phb_get_field_type_by_field_mask(temp_type) - MMI_PHB_FIELD_OPT_NUM_1);
            if (!g_mmi_phb_contact_p->opt_num[index].number[0])
            {
                switch (added_type)
                {
                    case MMI_PHB_FIELD_HOME_NUMBER:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_HOME;
                        break;
                        
                    case MMI_PHB_FIELD_OFFCIE_NUMBER:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_OFFICE;
                        break;
                        
                    case MMI_PHB_FIELD_FAX_NUMBER:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_FAX;
                        break;
                        
                 #ifdef __MMI_PHB_USIM_SUPPORT__
                 #ifdef __MMI_PHB_OPTIONAL_FIELD__
                     case MMI_PHB_FIELD_OPT_NUM_1:
                     case MMI_PHB_FIELD_OPT_NUM_2:
                     case MMI_PHB_FIELD_OPT_NUM_3:
                         if(g_mmi_phb_choose_field.highlight_index < 1)
                         {
                             g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                         }
                         else
                         {
                             g_mmi_phb_contact_p->opt_num[index].type = (mmi_phb_num_type_enum)mmi_phb_get_aas_type_label(g_mmi_phb_choose_field.highlight_index-1,storage);
                         }
                         break;
                #endif
                #endif
                    case MMI_PHB_FIELD_MOBILE_NUMBER:
                    default:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                        break;
                }
                mmi_wcscpy(g_mmi_phb_contact_p->opt_num[index].number, g_mmi_phb_save_contact_p->edit_temp_buff);
                break;
            }
        }
    } while (0);

    if (!mmi_phb_op_check_pre_save(g_mmi_phb_contact_p, srv_phb_get_storage(g_mmi_phb_list_p->store_index), MMI_TRUE))
    {
        mmi_wcscpy(g_mmi_phb_contact_p->number, g_mmi_phb_save_contact_p->edit_temp_buff);
        mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
    }
    else
    {
        g_mmi_phb_save_contact_p->action = MMI_PHB_OP_EDIT;
        g_mmi_phb_save_contact_p->store_index = g_mmi_phb_list_p->store_index;
        g_mmi_phb_save_contact_p->storage = srv_phb_get_storage(g_mmi_phb_list_p->store_index);
        
        mmi_phb_show_in_progress(g_mmi_phb_save_contact_p->sg_id, STR_GLOBAL_SAVING);

        mmi_phb_op_save_contact_ex();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_opt_update_contact_confirm
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_opt_choose_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
    U8 storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_name(g_mmi_phb_list_p->store_index, name, MMI_PHB_NAME_LENGTH);

    storage = srv_phb_get_storage(g_mmi_phb_list_p->store_index);
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (mmi_phb_check_storage(MMI_FALSE, storage))
    {
        mmi_phb_entry_choose_field_ex(
            g_mmi_phb_save_contact_p->sg_id,
            name,
            storage,
            phb_edit_usim_number_type,
            0,
            mmi_phb_entry_save_contact_opt_choose_type,
            mmi_phb_entry_save_contact_opt_choose_type_done,
            mmi_frm_scrn_close_active_id);
    }
    else
#endif
    {
        mmi_phb_entry_choose_field_ex(
            g_mmi_phb_save_contact_p->sg_id,
            name,
            storage,
            phb_edit_number_type,
            0,
            mmi_phb_entry_save_contact_opt_choose_type,
            mmi_phb_entry_save_contact_opt_choose_type_done,
            mmi_frm_scrn_close_active_id);
    }
}
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_opt_update_contact_confirm
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_opt_choose_field_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index] == SRV_PHB_ENTRY_FIELD_ALL)
    {
        mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
        mmi_phb_entry_save_contact_opt_choose_type();
        return;
    }
#endif
    if (g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index])
    {
        mmi_phb_entry_save_contact_opt_update_contact_confirm();
    }
    else
    {
        g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index] = SRV_PHB_ENTRY_FIELD_NUMBER;
        mmi_phb_save_contact_opt_update_contact(g_mmi_phb_save_contact_p->sg_id);
    }
    mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_opt_select_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_save_contact_opt_select_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_check_storage_accessible(srv_phb_get_storage(g_mmi_phb_list_p->store_index)))
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_ADN_FORBID,
            MMI_EVENT_FAILURE,
            g_mmi_phb_save_contact_p->sg_id,
            NULL);
        
        return;
    }

    mmi_phb_entry_choose_field(
        g_mmi_phb_save_contact_p->sg_id,
        g_mmi_phb_list_p->store_index,
        SRV_PHB_ENTRY_FIELD_GSM_NUM,
        mmi_phb_entry_save_contact_opt_select_field,
        mmi_phb_entry_save_contact_opt_choose_field_done,
        mmi_frm_scrn_close_active_id,
        NULL,
        MMI_TRUE,
        MMI_TRUE);
}

static void mmi_phb_exit_save_contact_opt_update_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INTELLIGENT_CALL_ALERT__)
    mmi_phb_speak_name_end();
#endif /* defined(__MMI_INTELLIGENT_CALL_ALERT__) */ 

    wgui_reset_multitap();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_update_list
 * DESCRIPTION
 *  entry function for update list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_phb_list_get_item_new(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_name(g_mmi_phb_list_p->contact_array[item_index], str_buff, 2 * MMI_PHB_NAME_FIELD_LENGTH + 1);

    if (str_buff[0] == 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }

    mmi_phb_contact_get_item_image(g_mmi_phb_list_p->contact_array[item_index], img_buff_p1, img_buff_p2);

    return TRUE;
}

static S32 mmi_phb_get_1024_1025_async_items_new(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_items; i++)
    {
        mmi_phb_list_get_item_new((i + start_index), menu_data[i].item_list[0], &menu_data[i].image_list[0], &menu_data[i].image_list[1]);
    }
    return num_items;
}


static S32 mmi_phb_list_get_hint_ext_new(S32 item_index, UI_string_type *hint_array)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index <= g_mmi_phb_list_p->contact_count)
    {
        store_index = g_mmi_phb_list_p->contact_array[item_index];
        
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        srv_phb_get_default_number(store_index, (U16*)hint_array[0], NULL, (MMI_PHB_NUMBER_LENGTH + 1));

        if (hint_array[0][0] == 0)
        {
            srv_phb_get_number(store_index, (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
        }
    #else /* __MMI_PHB_DEFAULT_NUMBER__ */
        srv_phb_get_number(store_index, (U16*)hint_array[0], MAX_SUBMENU_CHARACTERS);
    #endif /* __MMI_PHB_DEFAULT_NUMBER__ */

        if (hint_array[0][0] != 0)
        {
            result = 1; /* One hint data only, can be more hints. */
        }
    }

    return result;
}




void mmi_phb_entry_save_contact_opt_update_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 contact_count;
    srv_phb_filter_struct * filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        return;
    }

    mmi_phb_save_replace_list_cntx_create();
    g_mmi_phb_list_p = g_mmi_phb_save_contact_p->update_list;
    
    filter = mmi_phb_list_build_filter(
                 PHB_STORAGE_MAX,
                 MMI_PHB_LIST_DFAULT_FILTER,
                 NULL,
                 NULL,
                 0);
    
    contact_count = (U16) srv_phb_oplib_build_contact_list(filter, g_mmi_phb_list_p->contact_array, MMI_PHB_ENTRIES);
    g_mmi_phb_list_p->contact_count = contact_count;
    
    mmi_phb_list_free_filter(filter);
    
    mmi_phb_entry_list_ext(
        g_mmi_phb_save_contact_p->sg_id,
        contact_count,                                          /* Total Entry */
        STR_SCR_PBOOK_VIEW_CAPTION,                             /* Title String */
        IMG_SCR_PBOOK_CAPTION,                                  /* Title Image */
        STR_GLOBAL_OK,                                          /* LSK */
        IMG_GLOBAL_OK,                                          /* LSK */
        SCR_PBOOK_LIST,                                         /* Scr ID */
        IMG_GLOBAL_COMMON_CSK,                                  /* CSK */
        mmi_phb_list_highlight_handler,                         /* Highlight Callback */
        mmi_phb_entry_save_contact_opt_select_field,            /* LSK Callback */
        mmi_phb_entry_save_contact_opt_select_field,            /* CSK Callback */
        NULL,                                                   /* SEND Key Callback */
        NULL,
        mmi_phb_get_1024_1025_async_items_new,                       /* List Callback */
        mmi_phb_list_get_hint_ext_new,                              /* Hint Callback */
        mmi_phb_entry_save_contact_opt_update_list,             /* Re-Entry Callback */
        mmi_phb_exit_save_contact_opt_update_list,
        MMI_TRUE);                                              /* Alpha Index */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_contact_opt_update
 * DESCRIPTION
 *  save contact opt add to enter replace some duplicated field in phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_save_contact_opt_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_save_contact_opt_update_list();
    mmi_frm_group_close(g_mmi_phb_save_contact_p->menu_add_replace_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_save_contact_opt_add
 * DESCRIPTION
 *  save contact opt add to enter add new contact interface
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_save_contact_opt_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = g_mmi_phb_save_contact_p->sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_add_pre_entry((mmi_phb_save_contact_cntx_struct*)mmi_frm_group_get_user_data(sg_id));
}


mmi_ret mmi_phb_save_choose_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_GENERAL_SAVE_CONTACT_OPT)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (menu_evt->highlighted_menu_id == MENU_ID_GENERAL_SAVE_CONTACT_OPT_ADD)
            {
                mmi_phb_save_contact_opt_add();
            }
            else if (menu_evt->highlighted_menu_id == MENU_ID_GENERAL_SAVE_CONTACT_OPT_UPDATE)
            {
                mmi_phb_save_contact_opt_update();
            }
            else
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }

        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_general_save_contact_option
 * DESCRIPTION
 *  entry screen of save contact option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_general_save_contact_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                   g_mmi_phb_save_contact_p->sg_id,
                   CUI_MENU_SRC_TYPE_RESOURCE,
                   CUI_MENU_TYPE_APPSUB,
                   MENU_ID_GENERAL_SAVE_CONTACT_OPT,
                   MMI_FALSE, NULL);

    g_mmi_phb_save_contact_p->menu_add_replace_id = menu_gid;

    cui_menu_set_item_hidden(menu_gid, MENU_ID_GENERAL_SAVE_CONTACT_OPT_ADD, MMI_FALSE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_GENERAL_SAVE_CONTACT_OPT_UPDATE, MMI_FALSE);

    switch (srv_phb_check_storage_status(g_mmi_phb_save_contact_p->storage))
    {
        case SRV_PHB_STORAGE_STATUS_EMPTY:
            cui_menu_set_item_hidden(menu_gid, MENU_ID_GENERAL_SAVE_CONTACT_OPT_UPDATE, MMI_TRUE);
            break;
            
        case SRV_PHB_STORAGE_STATUS_FULL:
            cui_menu_set_item_hidden(menu_gid, MENU_ID_GENERAL_SAVE_CONTACT_OPT_ADD, MMI_TRUE);
            break;

        default:
            break;
    }

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    cui_menu_run(menu_gid);
}

#endif


void mmi_phb_entry_save_contact_prepare_data(mmi_phb_contact_info_struct* contact, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_op_remove_invalid_name_and_number(contact);

    if (mmi_phb_check_storage(MMI_FALSE, storage))
    {
    #ifdef __MMI_PHB_USIM_SUPPORT__
        U8 sim_interface = storage - PHB_STORAGE_SIM;
    #endif

        srv_phb_truncate_name(contact->name, storage);
    #ifdef __MMI_PHB_USIM_SUPPORT__
        srv_phb_truncate_name_ex(contact->nick_name, sim_interface, PHB_SNE);
    #ifdef __MMI_PHB_OPTIONAL_FIELD__  
        srv_phb_truncate_name_ex(contact->emailAddress, sim_interface,PHB_EMAIL);
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        srv_phb_truncate_name_ex(contact->emailAddress2, sim_interface, PHB_EMAIL);
    #endif
    #endif
    #endif
    }
}


#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_add_more_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_add_more_details(MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PHB_LOG(TRC_MMI_PHB_ENTRY_ADD_MORE_DETAILS);
    
    if (srv_phb_check_storage_status(PHB_STORAGE_NVRAM) == SRV_PHB_STORAGE_STATUS_FULL)
    {
        mmi_popup_display_simple_ext(
            STR_PHONE_FULL_MSG,
            MMI_EVENT_FAILURE,
            g_mmi_phb_save_contact_p->sg_id,
            NULL);
        
        return;
    }
    
    if (mmi_ucs2str((CHAR*)g_mmi_phb_contact_p->number, "?") != NULL)
    {
        mmi_popup_display_simple_ext(
            STR_ID_PHB_MOVE_NUM_WITH_QUESTION_MARK,
            MMI_EVENT_FAILURE,
            g_mmi_phb_save_contact_p->sg_id,
            NULL);
        return;
    }

    /**
     * Reset selected storage
     */
    g_mmi_phb_save_contact_p->storage = PHB_STORAGE_NVRAM;
    g_mmi_phb_save_contact_p->add_more = MMI_TRUE;

    /* after move to phone, reset default number */
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    g_mmi_phb_contact_p->default_number = 0xff;
#endif

#ifndef __MMI_PHB_UI_IN_TABS__
    cui_inline_close(g_mmi_phb_save_contact_p->editor_id);
#else
    mmi_frm_display_dummy_screen_ex(g_mmi_phb_save_contact_p->sg_id, SCR_ID_DUMMY);    
    mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_ADD_NEW_ENTRY);
#endif

    mmi_phb_entry_op_add_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_add_more_details_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_add_more_details_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_UI_IN_TABS__
    if (GetInlineListMenuChanged())
    {
        g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
    }
#endif /* __MMI_PHB_UI_IN_TABS__ */

    mmi_phb_entry_add_more_details(g_mmi_phb_save_contact_p->sg_id);
}

#endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */


#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#if defined(__MMI_PHB_UI_IN_TABS__) && defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_changed_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Changed item index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_bday_changed_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_item_list[index] == MMI_PHB_FIELD_BIRTHDAY)
    {
        g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
        g_mmi_phb_save_contact_p->bday_changed = MMI_TRUE;
    }
}
#endif


MMI_BOOL mmi_phb_edit_bday(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx_mgr.state == MMI_PHB_OP_EDIT || g_phb_cntx_mgr.state == MMI_PHB_OP_ADD)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


MMI_BOOL mmi_phb_bday_format(U16 *DateStr, U16 *day, U16 *month, U16 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (year[0] == 0 && month[0] == 0 && day[0] == 0)
    {
        mmi_ucs2cpy((CHAR*) DateStr, (CHAR*) GetString(STR_GLOBAL_NONE));
        return MMI_FALSE;
    }
    else
    {    
        mmi_ucs2cpy((CHAR*) DateStr, (CHAR*) year);
        mmi_ucs2cat((CHAR*) DateStr, (CHAR*) "/");
        mmi_ucs2cat((CHAR*) DateStr, (CHAR*) month);
        mmi_ucs2cat((CHAR*) DateStr, (CHAR*) "/");
        mmi_ucs2cat((CHAR*) DateStr, (CHAR*) day);
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_editor_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  DateStr     [?]             
 *  day         [?]             
 *  month       [?]             
 *  year        [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_editor_callback(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->bday_changed)
    {
        mmi_phb_bday_format((U16*)DateStr, (U16*)day, (U16*)month, (U16*)year);
    }
    else
    {
        mmi_ucs2cpy((CHAR*) DateStr, (CHAR*) GetString(STR_GLOBAL_NONE));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_bday_read_data_to_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  a(?)            [IN]        Store index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_bday_to_string(U16 *bday, U16 *pbYear, U16 *pbMon, U16 *pbDay, U16 b_year, U8 b_onth, U8 b_day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ascii_buff[6];
    MMI_BOOL result = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Year */
    if (b_year >= MMI_PHB_BDAY_MIN_YEAR_INT && b_year <= MMI_PHB_BDAY_MAX_YEAR_INT)
    {
        sprintf(ascii_buff, "%04d", b_year);
        mmi_asc_to_ucs2((CHAR*)pbYear, ascii_buff);
    }
    else
    {
        result = MMI_FALSE;
    }

    /* Month */
    if (b_onth > 0 && b_onth <= 12)
    {
        sprintf(ascii_buff, "%02d", b_onth);
        mmi_asc_to_ucs2((CHAR*)pbMon, ascii_buff);
    }
    else
    {
        result = MMI_FALSE;
    }

    /* Day */
    if (b_day > 0 && b_day <= 31)
    {
        sprintf(ascii_buff, "%02d", b_day);
        mmi_asc_to_ucs2((CHAR*)pbDay, ascii_buff);
    }
    else
    {
        result = MMI_FALSE;
    }

    if (result)
    {
        mmi_ucs2cpy((CHAR*) bday, (CHAR*) pbYear);
        mmi_ucs2cat((CHAR*) bday, (CHAR*) "/");
        mmi_ucs2cat((CHAR*) bday, (CHAR*) pbMon);
        mmi_ucs2cat((CHAR*) bday, (CHAR*) "/");
        mmi_ucs2cat((CHAR*) bday, (CHAR*) pbDay);
    }
}
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 


#ifdef __MMI_PHB_OPTIONAL_FIELD__
U8 mmi_phb_edit_get_opt_number_field(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_get_field_type_by_field_mask((U32)(g_mmi_phb_contact_p->opt_order[index]));
}
#endif


#ifdef __MMI_PHB_USIM_SUPPORT__
#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_usim_entry_change_number_type_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_usim_entry_change_number_type_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type_array[MMI_PHB_FIELD_LABEL_COUNT];
    S32 index = -1;
    mmi_phb_num_type_enum temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_field_type_list(
        type_array,
        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
        (phb_storage_enum)g_mmi_phb_save_contact_p->storage);
    
    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_OPT_NUM_1:
            index = 0;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            index = 1;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:
            index = 2;
            break;
        default:
            break;
    }
    
    if(g_mmi_phb_choose_field.highlight_index == 0)
    {
        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
    }
    else
    {
        g_mmi_phb_contact_p->opt_num[index].type = (mmi_phb_num_type_enum)type_array[g_mmi_phb_choose_field.highlight_index-1];
    }
    
    temp = g_mmi_phb_contact_p->opt_num[index].type;
    if (temp != g_mmi_phb_contact_p->opt_num[index].type)
    {
        g_mmi_phb_save_contact_p->done_flag = 1;
    }
    mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
}
#endif
#endif

#ifdef __MMI_PHB_UI_IN_TABS__
static U8 mmi_phb_edit_get_total_field(U8 tab_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
#ifdef __MMI_SNS_CONTACTS__
    U8 j = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (phb_edit_total_field_tab[tab_index][i] != MMI_PHB_FIELD_TOTAL)
    {
    #ifdef __MMI_SNS_CONTACTS__
        switch (tab_index)
        {
            case 0:
                if (phb_edit_total_field_tab[tab_index][i] != MMI_PHB_SNS_NAME ||
                    phb_edit_total_field_tab[tab_index][i] != MMI_PHB_SNS_NUMBER)
                {
                    j++;
                }
                break;

            case 1:
                if (phb_edit_total_field_tab[tab_index][i] != MMI_PHB_SNS_BIRTHDAY)
                {
                    j++;
                }
                break;

            case 2:
                if (phb_edit_total_field_tab[tab_index][i] != MMI_PHB_SNS_EMAIL)
                {
                    j++;
                }
                break;

            case 3:
                if (phb_edit_total_field_tab[tab_index][i] != MMI_PHB_SNS_URL)
                {
                    j++;
                }
                break;

            default:
                j++;
                break;
        }
    #endif
        i++;
    }

#ifdef __MMI_SNS_CONTACTS__
    return j;
#else
    return i;
#endif
}


#ifdef __MMI_PHB_USIM_SUPPORT__
static U8 mmi_phb_usim_edit_get_total_field(U8 tab_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    while (phb_usim_edit_total_field_tab[tab_index][i] != MMI_PHB_FIELD_TOTAL)
    {
        i++;
    }
    
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_usim_edit_get_page_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static U8 mmi_phb_usim_edit_get_page_index(U8 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tab_index, field_index;
    U8 page_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (tab_index = 0; tab_index < MMI_PHB_USIM_EDITOR_TAB_TOTAL; tab_index++)
    {
        field_index = 0;
        while (phb_usim_edit_total_field_tab[tab_index][field_index] != MMI_PHB_FIELD_TOTAL)
        {
            if (phb_usim_edit_total_field_tab[tab_index][field_index] == field_type)
            {
                return page_index;
            }

            field_index++;
        }

        if (field_index >= 1)
        {
            page_index++;
        }
    }

    return 0xff;
}    
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
#endif

static U8 mmi_phb_edit_get_field_type(U8 tab_index, U8 field_index,U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 field_type ;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__ 
    if(mmi_phb_check_storage(MMI_FALSE, storage))
    {
        field_type = phb_usim_edit_total_field_tab[tab_index][field_index];
    }
    else
#endif
    {
        field_type = phb_edit_total_field_tab[tab_index][field_index];
#ifdef __MMI_SNS_CONTACTS__
        switch (field_type)
        {
            case MMI_PHB_SNS_NAME:
            case MMI_PHB_SNS_NUMBER:
                if (!mmi_phb_sns_is_scrn_active(GRP_ID_PHB_CUI_VIEW, SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0))
                {
                   field_type = 0xF0;
                }
                else
                {
                    if (!g_mmi_phb_view_contact_p->is_load_finish || !mmi_phb_sns_is_linked(g_mmi_phb_view_contact_p->store_index))
                    {
                        field_type = 0xF0;
                    }
                }
                break;

            case MMI_PHB_SNS_BIRTHDAY:
                if (!mmi_phb_sns_is_scrn_active(GRP_ID_PHB_CUI_VIEW, SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1))
                {
                   field_type = 0xF0;
                }
                else
                {
                    if (!g_mmi_phb_view_contact_p->is_load_finish || !mmi_phb_sns_is_linked(g_mmi_phb_view_contact_p->store_index))
                    {
                        field_type = 0xF0;
                    }
                }
                break;

            case MMI_PHB_SNS_EMAIL:
                if (!mmi_phb_sns_is_scrn_active(GRP_ID_PHB_CUI_VIEW, SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2))
                {
                   field_type = 0xF0;
                }
                else
                {
                    if (!g_mmi_phb_view_contact_p->is_load_finish || !mmi_phb_sns_is_linked(g_mmi_phb_view_contact_p->store_index))
                    {
                        field_type = 0xF0;
                    }
                }
                break;

            case MMI_PHB_SNS_URL:
                if (!mmi_phb_sns_is_scrn_active(GRP_ID_PHB_CUI_VIEW, SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3))
                {
                   field_type = 0xF0;
                }
                else
                {
                    if (!g_mmi_phb_view_contact_p->is_load_finish || !mmi_phb_sns_is_linked(g_mmi_phb_view_contact_p->store_index))
                    {
                        field_type = 0xF0;
                    }
                }
                break;

            default:
                break;
        }
#endif
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if ((field_type == MMI_PHB_FIELD_OPT_NUM_1) ||
        (field_type == MMI_PHB_FIELD_OPT_NUM_2) ||
        (field_type == MMI_PHB_FIELD_OPT_NUM_3))
    {
        field_type = mmi_phb_edit_get_opt_number_field((U8)(field_type - MMI_PHB_FIELD_OPT_NUM_1));
    }
#endif

    return field_type;
}


static U8 mmi_phb_edit_get_page_index(U8 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tab_index, field_index;
    U8 page_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (tab_index = 0; tab_index < MMI_PHB_EDITOR_TAB_TOTAL; tab_index++)
    {
        field_index = 0;
        while (phb_edit_total_field_tab[tab_index][field_index] != MMI_PHB_FIELD_TOTAL)
        {
            if (phb_edit_total_field_tab[tab_index][field_index] == field_type)
            {
                return page_index;
            }

            field_index++;
        }

        if (field_index >= 1)
        {
            page_index++;
        }
    }

    return 0xff;
}

#else
#ifdef __MMI_PHB_USIM_SUPPORT__
#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_usim_edit_get_opt_number_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static U8 mmi_phb_usim_edit_get_opt_number_field(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phb_get_usim_field_mask_by_field_mask((U32)(g_mmi_phb_contact_p->opt_order[index]),MMI_TRUE);
}
#endif
#endif


static U8 mmi_phb_edit_get_default_field_type(U8 field_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return phb_edit_field_default[field_index];
}
#endif


#ifdef __MMI_PHB_GROUP_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_get_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_phb_edit_group_get_offset(U32 index, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 group_mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(storage)
    {
        case PHB_STORAGE_NVRAM:
            group_mask = 1 << (g_mmi_phb_save_contact_p->group_id_list[index]);
            break;

        case PHB_STORAGE_SIM:
            group_mask = 1 << (g_mmi_phb_save_contact_p->group_id_list[index] - MMI_PHB_GROUP_COUNT);
            break;

        case PHB_STORAGE_SIM2:
            group_mask = 1 << (g_mmi_phb_save_contact_p->group_id_list[index] - MMI_PHB_GROUP_COUNT - MMI_PHB_MAX_GAS_COUNT);
            break;

        case PHB_STORAGE_SIM3:
            group_mask = 1 << (g_mmi_phb_save_contact_p->group_id_list[index] - MMI_PHB_GROUP_COUNT - 2 * MMI_PHB_MAX_GAS_COUNT);
            break;

        case PHB_STORAGE_SIM4:
            group_mask = 1 << (g_mmi_phb_save_contact_p->group_id_list[index] - MMI_PHB_GROUP_COUNT - 3 * MMI_PHB_MAX_GAS_COUNT);
            break;

    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case PHB_STORAGE_TCARD:
            group_mask = 1 << (g_mmi_phb_save_contact_p->group_id_list[index] - MMI_PHB_GROUP_COUNT - MMI_PHB_GROUP_USIM_COUNT);
    #endif

        default:
            ASSERT (0);
            break;      
    }

    return group_mask;
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
S32 mmi_phb_async_get_group_items(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < num_items; index++)
    {
        if (!srv_phb_get_group_info(g_mmi_phb_save_contact_p->group_id_list[start_index + index], &group_info))
        {
            mmi_wcsncpy(menu_data[index].item_list[0], group_info.group_name, MAX_SUBMENU_CHARACTERS);
            menu_data[index].image_list[0] = NULL;
        }
    }

    return num_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_info_set_state
 * DESCRIPTION
 *  set check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_phb_edit_group_info_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_save_contact_p->contact->group_id ^= mmi_phb_edit_group_get_offset(item_index, (phb_storage_enum)g_mmi_phb_save_contact_p->storage);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_info_get_state
 * DESCRIPTION
 *  get check box state
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_phb_edit_group_info_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *checkbox_image = mmi_phb_edit_group_get_offset(item_index, (phb_storage_enum)g_mmi_phb_save_contact_p->storage) & (g_mmi_phb_save_contact_p->contact->group_id) ?
            (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) :
            (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID) ;
            
    return MMI_TRUE;
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
static void mmi_phb_edit_group_info_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_save_contact_p->group_highlight_index = (U8) item_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_edit_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_edit_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_set_pre_key_handler(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_info_check
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_group_info_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_edit_group_info_set_state(g_mmi_phb_save_contact_p->group_highlight_index) == MMI_TRUE)
    {
        RedrawCategoryFunction();
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_group_info_tap_callback
 * DESCRIPTION
 *  set check box
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_edit_group_info_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_edit_group_info_check();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_edit_group_info
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_edit_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U32 group_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    group_count = srv_phb_get_group_list(g_mmi_phb_save_contact_p->group_id_list, NULL, (phb_storage_enum)g_mmi_phb_save_contact_p->storage);
    if (group_count == 0)
    {        
        mmi_popup_display_simple_ext(
            STR_ID_PHB_NO_GROUP,
            MMI_EVENT_FAILURE,
            g_mmi_phb_save_contact_p->sg_id,
            NULL);
    }
    else if (mmi_frm_scrn_enter(
                g_mmi_phb_save_contact_p->sg_id,
                SCR_ID_PHB_CONTACT_EIDT_GROUP_INFO,
                mmi_phb_exit_edit_group_info,
                mmi_phb_entry_edit_group_info,
                MMI_FRM_FULL_SCRN))
    {   
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
		if (NULL == gui_buffer)
        {
        	g_mmi_phb_save_contact_p->group_highlight_index = 0;
        }

        RegisterHighlightHandler(mmi_phb_edit_group_info_highlight_hdlr);
        EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

        wgui_cat1024_show(
            (WCHAR*) GetString(STR_ID_PHB_CONTACT_EDIT_GROUP_INFO),
            (PU8)GetImage(IMG_SCR_PBOOK_CAPTION),
            (WCHAR*) GetString(STR_GLOBAL_OK),
            (PU8) GetImage(IMG_GLOBAL_OK),
            (WCHAR*) GetString(STR_GLOBAL_BACK),
            (PU8) GetImage(IMG_GLOBAL_BACK),
            NULL,
            group_count,
            mmi_phb_async_get_group_items,
            NULL,
            mmi_phb_edit_group_info_get_state,
            mmi_phb_edit_group_info_set_state,
            0,
            IMG_GLOBAL_SIM1,
            g_mmi_phb_save_contact_p->group_highlight_index,
            gui_buffer);

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif
        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_phb_edit_group_info_check, KEY_EVENT_UP);    
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_edit_group_info_tap_callback);
    #endif
    }
}
#endif


mmi_ret mmi_phb_edit_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
        #ifdef __MMI_PHB_CALLER_VIDEO__
            if (menu_evt->parent_menu_id == MENU_ID_PHB_EDIT_OPTION)
            {
                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_FALSE);
            }
            else
        #endif
            {
                result = MMI_RET_DONT_CARE;
            }
            break;
        }

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (menu_evt->highlighted_menu_id)
            {
            #ifndef __MMI_PHB_UI_IN_TABS__
                case MENU_ID_PHB_ADD_MORE_DETAILS:
                    mmi_phb_entry_add_details();
                    break;
                    
                case MENU_ID_PHB_DELETE_DETAILS:
                    mmi_phb_entry_edit_delete_details();
                    break;
            #endif
                case MENU_ID_PHB_EDIT_OK:
                    mmi_phb_entry_op_save_contact_confirm();
                break;

            #if defined(__MMI_PHB_UI_IN_TABS__) && !defined (__MMI_FTE_SUPPORT__)
			case MENU_ID_PHB_RINGTONE_SELECT:
				mmi_phb_entry_choose_caller_ringtone(); 
			break;

			case MENU_ID_PHB_PICTURE_ADD:
				mmi_phb_entry_choose_caller_pic();
			break;
		#endif
            #if defined(__MMI_PHB_UI_IN_TABS__) && !defined (__MMI_FTE_SUPPORT__)
                case MENU_ID_PHB_EDIT_NUM_OP_EDIT:
                    	if(MMI_PHB_FIELD_NAME==g_mmi_phb_save_contact_p->highlight_type)
					{
						mmi_phb_entry_inline_edit_name_for_tab();
					}
					else
					{
						mmi_phb_entry_inline_edit_num_for_tab();
					}
                    break;
            #else
                
                case MENU_ID_PHB_EDIT_CANCEL:
                    mmi_frm_group_close(g_mmi_phb_save_contact_p->sg_id);
                    break;

		    #ifdef __MMI_INLINE_SLIM__
				case MENU_ID_PHB_SLIM_EDIT:
					cui_menu_close(menu_evt->sender_id);
					wgui_inline_lsk_fs_cui_editor();
					break;

			    case MENU_ID_PHB_SLIM_RINGTONE:
					cui_menu_close(menu_evt->sender_id);
					wgui_inline_lsk_menu_cui_select();
					break;
			#endif
                    
            #ifdef __MMI_PHB_OPTIONAL_FIELD__
                case MENU_ID_PHB_EDIT_NUM_OP_CHANGE_TYPE:
                #ifdef __MMI_PHB_USIM_SUPPORT__
                    if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
                    {               
                        mmi_phb_entry_usim_change_number_type();
                    }
                    else
                #endif
                    {            
                        mmi_phb_entry_change_number_type();
                    }
                    break;
            #endif

            #ifdef __MMI_PHB_CALLER_RES__
                case MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW:
                    mmi_phb_entry_image_view_ext(g_mmi_phb_save_contact_p->sg_id);
                    break;
                    
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                case MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT:
                    mmi_phb_ringtone_select_from_file_mamager();
                    break;

                case MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT:
                    mmi_phb_entry_choose_caller_pic();
                    break;
                    
            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                case MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA:
                    mmi_phb_image_select_from_camera();
                    break;
            #endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
            #endif /* defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) */
        
            #ifdef __MMI_PHB_CALLER_VIDEO__
                case MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY:
                    mmi_phb_entry_video_view_ext(g_mmi_phb_save_contact_p->sg_id);
                    break;
                    
                case MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT:
                    mmi_phb_entry_choose_caller_video();
                    break;
                    
                case MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET:
                    if (g_mmi_phb_res_p->video_audio)
                    {
                        cui_menu_set_default_left_softkey(menu_evt->sender_id, get_string(STR_GLOBAL_OFF));
                    }
                    else
                    {
                        cui_menu_set_default_left_softkey(menu_evt->sender_id, get_string(STR_GLOBAL_ON));
                    }
                    mmi_phb_entry_video_audio_option(g_mmi_phb_save_contact_p->sg_id);
                    break;
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
            #endif /* __MMI_PHB_CALLER_RES__ */
            #if 0
            #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */
			#endif

            #if defined(__MMI_PHB_BIRTHDAY_FIELD__) && defined(__MMI_BIRTHDAY_REMINDER__)
                case MENU_ID_PHB_EDIT_ADD_BIRTHDAY_REMINDER:
                    mmi_phb_edit_add_birthday_reminder();
                    break;
            #endif /* __MMI_BIRTHDAY_REMINDER__ */
            #endif /* #if defined(__MMI_PHB_UI_IN_TABS__) && !defined (__MMI_FTE_SUPPORT__) */
            
            #if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined (__MMI_PHB_DEFAULT_NUMBER__)
                case MENU_ID_PHB_EDIT_NUM_OP_SET_DFT:
                    mmi_phb_entry_set_default_number();
                    break;
                    
                case MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT:
                    mmi_phb_entry_cancel_default_number();
                    break;
            #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined (__MMI_PHB_DEFAULT_NUMBER__) */

            #ifdef __MMI_PHB_SPEED_DIAL__
                case MENU_ID_PHB_EDIT_NUM_OP_SET_SPD:
                    mmi_phb_entry_set_speed_number(g_mmi_phb_save_contact_p->sg_id);
                    break;

                case MENU_ID_PHB_EDIT_NUM_OP_CANCEL_SPD:
                    mmi_phb_entry_cancel_speed_number(g_mmi_phb_save_contact_p->sg_id);
                    break;
             #endif
                    
	        #ifdef __MMI_PHB_GROUP_ENHANCE__
                case MENU_ID_PHB_CONTACT_EDIT_GROUP_INFO:
                    mmi_phb_entry_edit_group_info();
                    break;
	        #endif

                default:
                    result = MMI_RET_DONT_CARE;
                    break;
            }
            break;
        }
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
        default:
            result = MMI_RET_DONT_CARE;
            break;
    }

    return result;
}



/*****************************************************************************
* FUNCTION
*  mmi_phb_entry_op_edit_number_option
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
 *  the description of return value, if any.(?)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
static void mmi_phb_entry_op_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PHB_UI_IN_TABS__
    U32 i = 0;
#endif
    mmi_id menu_gid;
#ifdef __MMI_PHB_GROUP_ENHANCE__
    U32 field;
#endif
#ifndef __MMI_PHB_UI_IN_TABS__
#ifdef __MMI_PHB_USIM_SUPPORT__
    U8 *type_array= NULL;
    U8 aas_count;
#endif
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                   g_mmi_phb_save_contact_p->sg_id,
                   CUI_MENU_SRC_TYPE_RESOURCE,
                   CUI_MENU_TYPE_OPTION,
                   MENU_ID_PHB_EDIT_OPTION,
                   MMI_FALSE,
                   NULL);

    /* edit group */
#ifdef __MMI_PHB_GROUP_ENHANCE__
    field = srv_phb_get_support_field((phb_storage_enum)g_mmi_phb_save_contact_p->storage);
    if (!(field & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_CONTACT_EDIT_GROUP_INFO, MMI_TRUE);  
    }
#endif

#if defined(__MMI_PHB_UI_IN_TABS__)&&!defined(__MMI_FTE_SUPPORT__)
	cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_RINGTONE_SELECT, MMI_TRUE); 
	cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PICTURE_ADD, MMI_TRUE); 
#endif
    /* default number menu */
#ifdef __MMI_PHB_OPTIONAL_FIELD__
#if defined (__MMI_PHB_DEFAULT_NUMBER__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_DFT, MMI_TRUE);
#endif
#if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CHANGE_TYPE, MMI_TRUE);
#endif
#endif
#ifdef __MMI_PHB_SPEED_DIAL__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_SPD, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_SPD, MMI_TRUE);
#endif

#if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_VIEW, MMI_TRUE);
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_RINGTONE_OPTION_SELECT, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_SELECT, MMI_TRUE);

#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_IMAGE_OPTION_CAMERA, MMI_TRUE);
#endif /* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */
#endif

#ifdef __MMI_PHB_CALLER_VIDEO__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_PLAY, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_SELECT, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_VIDEO_OPTION_AUDIO_SET, MMI_TRUE);
#endif
#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
#endif
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_ADD_BIRTHDAY_REMINDER, MMI_TRUE);
#endif
#endif

#endif /* #if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__) */

    if(mmi_phb_check_storage(MMI_TRUE, g_mmi_phb_save_contact_p->storage))
    {
    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_NUMBER:
        #if defined (__MMI_PHB_DEFAULT_NUMBER__)
            if (g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM)
            {
                if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_NUMBER
                    || g_mmi_phb_contact_p->default_number == 0xff)
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_DFT, MMI_FALSE);
                }
            }
        #endif

        #ifdef __MMI_PHB_SPEED_DIAL__
            if (g_mmi_phb_contact_p->number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
             #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
             #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                if (srv_phb_query_speed_dial_key(g_mmi_phb_save_contact_p->store_index, SRV_PHB_ENTRY_FIELD_NUMBER))
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_SPD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_SPD, MMI_FALSE);
                }
            }
        #endif
            break;

        case MMI_PHB_FIELD_OPT_NUM_1:
        #if defined (__MMI_PHB_DEFAULT_NUMBER__)
            if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_1)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_DFT, MMI_FALSE);
            }
        #endif
        #if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__)
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CHANGE_TYPE, MMI_FALSE);
        #endif
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (g_mmi_phb_contact_p->opt_num[0].number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                if (srv_phb_query_speed_dial_key(g_mmi_phb_save_contact_p->store_index, SRV_PHB_ENTRY_FIELD_OPT_NUM_1))
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_SPD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_SPD, MMI_FALSE);
                }
            }
        #endif
            break;

        case MMI_PHB_FIELD_OPT_NUM_2:
        #if defined (__MMI_PHB_DEFAULT_NUMBER__)
            if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_2)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_DFT, MMI_FALSE);
            }
        #endif
        #if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__)
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CHANGE_TYPE, MMI_FALSE);
        #endif
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (g_mmi_phb_contact_p->opt_num[1].number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                if (srv_phb_query_speed_dial_key(g_mmi_phb_save_contact_p->store_index, SRV_PHB_ENTRY_FIELD_OPT_NUM_2))
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_SPD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_SPD, MMI_FALSE);
                }
            }
        #endif
            break;

        case MMI_PHB_FIELD_OPT_NUM_3:
        #if defined (__MMI_PHB_DEFAULT_NUMBER__)
            if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_3)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_DFT, MMI_FALSE);
            }
        #endif
        #if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__)
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CHANGE_TYPE, MMI_FALSE);
        #endif
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (g_mmi_phb_contact_p->opt_num[2].number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                if (srv_phb_query_speed_dial_key(g_mmi_phb_save_contact_p->store_index, SRV_PHB_ENTRY_FIELD_OPT_NUM_3))
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_SPD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_SPD, MMI_FALSE);
                }
            }
        #endif
            break;
        #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

        #if !defined(__MMI_PHB_UI_IN_TABS__) || defined (__MMI_FTE_SUPPORT__)
        #ifdef __MMI_PHB_CALLER_RES__
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            case MMI_PHB_FIELD_RING:
                mmi_phb_edit_option_ringtone_highlight_hdlr(menu_gid);
                break;
        #endif
            case MMI_PHB_FIELD_PIC:
                mmi_phb_edit_option_image_highlight_hdlr(menu_gid);
                break;
                
        #ifdef __MMI_PHB_CALLER_VIDEO__
            case MMI_PHB_FIELD_VIDEO:
                mmi_phb_edit_option_video_highlight_hdlr(menu_gid);
                break;
        #endif /* __MMI_PHB_CALLER_VIDEO__ */
        #endif /* __MMI_PHB_CALLER_RES__ */
    #if 0
    #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
            #ifdef __USB_IN_NORMAL_MODE__
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
    #endif
    #endif
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    #ifdef __MMI_BIRTHDAY_REMINDER__
        case MMI_PHB_FIELD_BIRTHDAY:
            if (g_mmi_phb_save_contact_p->bday_changed)
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_ADD_BIRTHDAY_REMINDER, MMI_FALSE);
            }
		break;
    #endif
    #endif
    
    #endif
	#if defined(__MMI_PHB_UI_IN_TABS__)&&!defined(__MMI_FTE_SUPPORT__)
	case MMI_PHB_FIELD_RING:
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_RINGTONE_SELECT, MMI_FALSE); 
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_EDIT, MMI_TRUE);
	break;

	case MMI_PHB_FIELD_PIC:
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_PICTURE_ADD, MMI_FALSE); 
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_EDIT, MMI_TRUE);
	break;
    #endif
    
        default:
            break;
        }
    }

/* add details menu */

#ifndef __MMI_PHB_UI_IN_TABS__
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_MORE_DETAILS, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DELETE_DETAILS, MMI_TRUE);

    if (mmi_phb_check_storage(MMI_TRUE, g_mmi_phb_save_contact_p->storage))
    {
        U32 temp_mask;
        U32 exist_num = 0;
        U32 index;

        for (index = 0; index < 31; index++)
        {
            if (g_mmi_phb_save_contact_p->field_mask & (1<<index))
            {
                exist_num++;
            }
        }

        if (exist_num < MAX_INLINE_ITEMS/2)
        {
            while (phb_edit_field_optional[i] != MMI_PHB_FIELD_TOTAL)
            {
                temp_mask = mmi_phb_get_field_mask_by_field_type(phb_edit_field_optional[i]);
                if ((temp_mask & g_mmi_phb_save_contact_p->field_mask) != temp_mask)
                {
                #if defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
                    if (phb_edit_field_optional[i] != MMI_PHB_FIELD_PIC)
                #endif
                    {
                    #if defined(__MMI_PHB_INFO_FIELD__)
                        if ((phb_edit_field_optional[i] != MMI_PHB_FIELD_ADDRESS)
                            || ((MAX_INLINE_ITEMS/2 - exist_num) > (MMI_PHB_FIELD_ADR_COUNTRY- MMI_PHB_FIELD_ADR_POBOX))
                            )
                    #endif
                        {
                            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_MORE_DETAILS, MMI_FALSE);
                            break;
                        }
                    }
                }
                i++;
            }
        }

        if (g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_NAME
        #ifdef __MMI_PHB_LAST_NAME_FIELD__
            && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_LAST_NAME
        #endif
            && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_NUMBER
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_EMAIL
        #endif
        #ifdef __MMI_PHB_CALLER_RES__
            && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_PIC
            && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_RING
        #endif
            )
        {   
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DELETE_DETAILS, MMI_FALSE);
        }
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
    {
        type_array = (U8 *) mmi_phb_mem_malloc(sizeof(U8)*MMI_PHB_FIELD_LABEL_COUNT ,SRV_PHB_MEMORY_TYPE_ADM);
        aas_count = srv_phb_get_field_type_list(type_array,MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)g_mmi_phb_save_contact_p->storage);
        mmi_phb_mem_free(type_array);
        //for change highligh type
        switch (g_mmi_phb_save_contact_p->highlight_type)
        {
        #ifdef __MMI_PHB_OPTIONAL_FIELD__  
            case MMI_PHB_FIELD_OPT_NUM_1:  
            case MMI_PHB_FIELD_OPT_NUM_2:
            case MMI_PHB_FIELD_OPT_NUM_3:   

                if(aas_count)
                {
                    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CHANGE_TYPE, MMI_FALSE);
                }
                break;
        #endif
                
            default:
                break;
        }
        //for USIM add detail
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_MORE_DETAILS, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DELETE_DETAILS, MMI_TRUE);
        while (phb_edit_usim_field_optional[i] != MMI_PHB_USIM_FIELD_TOTAL)
        {       
            if(mmi_phb_check_usim_detail(g_mmi_phb_save_contact_p->storage,phb_edit_usim_field_optional[i])) //check the storage is full or not
            {
                cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_ADD_MORE_DETAILS, MMI_FALSE);
                break;
            }
            i++;
        }
        if (g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_NAME && 
            g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_NUMBER 
         /*for 12.3*/
        #ifdef __MMI_PHB_OPTIONAL_FIELD__  
             && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_EMAIL
        #endif
            )
        {   
            cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_DELETE_DETAILS, MMI_FALSE);
        }
    }
#endif
#endif

#ifdef __MMI_INLINE_SLIM__
	cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SLIM_EDIT, MMI_TRUE);
    cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SLIM_RINGTONE, MMI_TRUE);
	if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_NAME || 
		g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_NUMBER
		)
	{
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SLIM_EDIT, MMI_FALSE);	
	}
#ifdef __MMI_PHB_CALLER_RES__	
	else if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_RING)
	{
		cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_SLIM_RINGTONE, MMI_FALSE);
	}
#endif
#endif

#ifdef __MMI_PHB_OPTIONAL_FIELD__
#if defined (__MMI_PHB_DEFAULT_NUMBER__)
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__  /* TCARD no support default number */
    if ((phb_storage_enum)g_mmi_phb_save_contact_p->storage == PHB_STORAGE_TCARD) 
    {
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_CANCEL_DFT, MMI_TRUE);
        cui_menu_set_item_hidden(menu_gid, MENU_ID_PHB_EDIT_NUM_OP_SET_DFT, MMI_TRUE);
    }
#endif
#endif
#endif

    cui_menu_set_default_title_image_by_id(menu_gid, IMG_SCR_PBOOK_CAPTION);

    cui_menu_run(menu_gid);
}


#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_set_default_number
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_entry_set_default_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NUMBER:
            g_mmi_phb_contact_p->default_number = SRV_PHB_ENTRY_FIELD_NUMBER;
            break;
        case MMI_PHB_FIELD_OPT_NUM_1:
            g_mmi_phb_contact_p->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
            break;
        case MMI_PHB_FIELD_OPT_NUM_2:
            g_mmi_phb_contact_p->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
            break;
        case MMI_PHB_FIELD_OPT_NUM_3:
            g_mmi_phb_contact_p->default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
            break;
        default:
            break;
    }

    g_mmi_phb_save_contact_p->done_flag = 1;
    
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_cancel_default_number
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_entry_cancel_default_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_contact_p->default_number = 0xfe;
    g_mmi_phb_save_contact_p->done_flag = 1;
    
    mmi_frm_scrn_close_active_id();
}
#endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_change_number_type_done
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_change_number_type_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 added_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];
    S32 index = -1;
    mmi_phb_num_type_enum temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_OPT_NUM_1:
            index = 0;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            index = 1;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:
            index = 2;
            break;
        default:
            break;
    }
    temp = g_mmi_phb_contact_p->opt_num[index].type;
    if (index != -1)
    {
        switch (added_type)
        {
            case MMI_PHB_FIELD_HOME_NUMBER:
                g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_HOME;
                break;
                
            case MMI_PHB_FIELD_OFFCIE_NUMBER:
                g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_OFFICE;
                break;
                
            case MMI_PHB_FIELD_FAX_NUMBER:
                g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_FAX;
                break;
                
            case MMI_PHB_FIELD_MOBILE_NUMBER:
            default:
                g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                break;
        }
    }
    if (temp != g_mmi_phb_contact_p->opt_num[index].type)
    {
        g_mmi_phb_save_contact_p->done_flag = 1;
    }
    mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_save_contact_opt_update_contact_confirm
 * DESCRIPTION
 *  update contact for unsaved data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_change_number_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
    U8 storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_convert_to_name(
        name,
        g_mmi_phb_contact_p->name,
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        g_mmi_phb_contact_p->last_name,
    #else
        NULL,
    #endif
        MMI_PHB_NAME_LENGTH);
    storage = srv_phb_get_storage(g_mmi_phb_save_contact_p->store_index);
    if(storage == 0xFF)
    {
        storage = g_mmi_phb_save_contact_p->storage;
    }
    
    mmi_phb_entry_choose_field_ex(
        g_mmi_phb_save_contact_p->sg_id,
        name,
        storage,
        phb_edit_number_type,
        0,
        mmi_phb_entry_change_number_type,
        mmi_phb_entry_change_number_type_done,
        mmi_frm_scrn_close_active_id);
}
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */


#ifdef __MMI_PHB_SPEED_DIAL__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_set_speed_number
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_entry_set_speed_number(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NUMBER:
            num_type = SRV_PHB_ENTRY_FIELD_NUMBER;
            break;
    #ifdef __MMI_PHB_OPTIONAL_FIELD__            
        case MMI_PHB_FIELD_OPT_NUM_1:
            num_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
            break;
        case MMI_PHB_FIELD_OPT_NUM_2:
            num_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
            break;
        case MMI_PHB_FIELD_OPT_NUM_3:
            num_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
            break;
    #endif
        default:
            break;
    }
    if (num_type)
    {
        mmi_phb_speed_dial_pre_set_number(
            sg_id,
            g_mmi_phb_save_contact_p->store_index,
            num_type,
            g_mmi_phb_contact_p);
    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_cancel_speed_number
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_entry_cancel_speed_number(mmi_id sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NUMBER:
            num_type = SRV_PHB_ENTRY_FIELD_NUMBER;
            break;
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            num_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
            break;
        case MMI_PHB_FIELD_OPT_NUM_2:
            num_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
            break;
        case MMI_PHB_FIELD_OPT_NUM_3:
            num_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
            break;
    #endif
        default:
            break;
    }
    if (num_type)
    {
        mmi_phb_speed_dial_pre_del_number(g_mmi_phb_save_contact_p->store_index, num_type);
        g_mmi_phb_save_contact_p->done_flag = 1;
    }
    mmi_frm_scrn_close_active_id();
}
#endif


#ifdef __MMI_PHB_UI_IN_TABS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_lsk_inline_edit_num_for_tab
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/

static void mmi_phb_lsk_inline_edit_name_for_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (g_mmi_phb_save_contact_p->highlight_type)
    {

        case MMI_PHB_FIELD_NAME:
            buffer = g_mmi_phb_contact_p->name;
            break;

        default:
            break;
    }

    if (g_mmi_phb_save_contact_p->edit_temp_done)
    {
        g_mmi_phb_save_contact_p->done_flag = 1;
        cui_fseditor_get_text(
            g_mmi_phb_save_contact_p->editor_id,
            g_mmi_phb_save_contact_p->edit_temp_buff,
            sizeof(g_mmi_phb_save_contact_p->edit_temp_buff));
		
        mmi_ucs2cpy((CHAR *) buffer, (CHAR *) g_mmi_phb_save_contact_p->edit_temp_buff);
		
    }
    
    cui_fseditor_close(g_mmi_phb_save_contact_p->editor_id);
	
}
static void mmi_phb_lsk_inline_edit_num_for_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NUMBER:
            buffer = g_mmi_phb_contact_p->number;
            break;

	#ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            buffer = g_mmi_phb_contact_p->opt_num[0].number;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            buffer = g_mmi_phb_contact_p->opt_num[1].number;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:
            buffer = g_mmi_phb_contact_p->opt_num[2].number;
            break;
	#endif

        default:
            break;
    }

    if (g_mmi_phb_save_contact_p->edit_temp_done)
    {
        g_mmi_phb_save_contact_p->done_flag = 1;
        cui_fseditor_get_text(
            g_mmi_phb_save_contact_p->editor_id,
            g_mmi_phb_save_contact_p->edit_temp_buff,
            sizeof(g_mmi_phb_save_contact_p->edit_temp_buff));
        mmi_ucs2cpy((CHAR *) buffer, (CHAR *) g_mmi_phb_save_contact_p->edit_temp_buff);
    }
    
    cui_fseditor_close(g_mmi_phb_save_contact_p->editor_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_editor_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_number_editor_proc(mmi_event_struct *evt)
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
	    if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_NAME)
            {
                mmi_phb_lsk_inline_edit_name_for_tab();
            }
            else if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_ADD_NUMBERS)//////////////maggie 0802
            {
                mmi_phb_edit_add_more_number();
            }
            else
            {
                mmi_phb_lsk_inline_edit_num_for_tab();
            #ifdef __MMI_PHB_OPTIONAL_FIELD__
                if (g_mmi_phb_save_contact_p->edit_temp_buff[0] && g_mmi_phb_save_contact_p->highlight_type != MMI_PHB_FIELD_NUMBER)
                {
                #ifdef __MMI_PHB_USIM_SUPPORT__
                    if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
                    {
                        U8 type_array[MMI_PHB_FIELD_LABEL_COUNT];

                        if (srv_phb_get_field_type_list(type_array, MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)g_mmi_phb_save_contact_p->storage))
                        {
                            mmi_phb_entry_usim_change_number_type();
                        }
                    }
                    else
                #endif
                    {   
                        mmi_phb_entry_change_number_type();
                    }
                }
            #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
            }
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(g_mmi_phb_save_contact_p->editor_id);
            break;

        case EVT_ID_CUI_FSEDITOR_CHANGED:
            g_mmi_phb_save_contact_p->edit_temp_done = MMI_TRUE;
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_inline_edit_num_for_tab
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/

static void mmi_phb_entry_inline_edit_name_for_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_id;
    WCHAR *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_id = cui_fseditor_create(g_mmi_phb_save_contact_p->sg_id);

    g_mmi_phb_save_contact_p->editor_id = editor_id;
    g_mmi_phb_save_contact_p->edit_temp_done = MMI_FALSE;

    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NAME:
            buffer = g_mmi_phb_contact_p->name;
            break;

        default:
            break;
    }
    if (buffer)
    {
        mmi_wcscpy(g_mmi_phb_save_contact_p->edit_temp_buff, buffer);
    }
    else
    {
        g_mmi_phb_save_contact_p->edit_temp_buff[0] = 0;
    }

    cui_fseditor_set_title(editor_id, g_mmi_phb_save_contact_p->highlight_str, IMG_SCR_PBOOK_CAPTION);
    cui_fseditor_set_softkey_text(editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
    cui_fseditor_set_softkey_icon(editor_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    cui_fseditor_set_text(
        editor_id,
        g_mmi_phb_save_contact_p->edit_temp_buff,
        sizeof(g_mmi_phb_save_contact_p->edit_temp_buff),
        MMI_PHB_NAME_LENGTH);
    cui_fseditor_set_input_method(
        editor_id,
        IMM_INPUT_TYPE_SENTENCE,
        NULL,
        0);
    cui_fseditor_run(editor_id);
}
static void mmi_phb_entry_inline_edit_num_for_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id editor_id;
    WCHAR *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_id = cui_fseditor_create(g_mmi_phb_save_contact_p->sg_id);

    g_mmi_phb_save_contact_p->editor_id = editor_id;
    g_mmi_phb_save_contact_p->edit_temp_done = MMI_FALSE;

    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NUMBER:
            buffer = g_mmi_phb_contact_p->number;
            break;
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            buffer = g_mmi_phb_contact_p->opt_num[0].number;
            break;
        case MMI_PHB_FIELD_OPT_NUM_2:
            buffer = g_mmi_phb_contact_p->opt_num[1].number;
            break;
        case MMI_PHB_FIELD_OPT_NUM_3:
            buffer = g_mmi_phb_contact_p->opt_num[2].number;
            break;
    #endif
        default:
            break;
    }
    if (buffer)
    {
        mmi_wcscpy(g_mmi_phb_save_contact_p->edit_temp_buff, buffer);
    }
    else
    {
        g_mmi_phb_save_contact_p->edit_temp_buff[0] = 0;
    }

    cui_fseditor_set_title(editor_id, g_mmi_phb_save_contact_p->highlight_str, IMG_SCR_PBOOK_CAPTION);
    cui_fseditor_set_softkey_text(editor_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
    cui_fseditor_set_softkey_icon(editor_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    cui_fseditor_set_text(
        editor_id,
        g_mmi_phb_save_contact_p->edit_temp_buff,
        sizeof(g_mmi_phb_save_contact_p->edit_temp_buff),
        MMI_PHB_NUMBER_LENGTH);
    cui_fseditor_set_input_method(
        editor_id,
        IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING,
        NULL,
        0);
    cui_fseditor_run(editor_id);
}


void mmi_phb_edit_add_more_number_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i, index;
    U8 temp_type;
#endif
    U32 added_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_phb_save_contact_p->add_detail = MMI_TRUE;

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        temp_type = g_mmi_phb_contact_p->opt_order[i];
        index = (U32)(mmi_phb_get_field_type_by_field_mask(temp_type) - MMI_PHB_FIELD_OPT_NUM_1);
        if (!(g_mmi_phb_save_contact_p->field_mask & temp_type))
        {
            switch (added_type)
            {
                case MMI_PHB_FIELD_HOME_NUMBER:
                    g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_HOME;
                    break;
                    
                case MMI_PHB_FIELD_OFFCIE_NUMBER:
                    g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_OFFICE;
                    break;
                    
                case MMI_PHB_FIELD_FAX_NUMBER:
                    g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_FAX;
                    break;
            #ifdef __MMI_PHB_USIM_SUPPORT__     /*for usim add detail*/
                case MMI_PHB_FIELD_OPT_NUM_1:
                case MMI_PHB_FIELD_OPT_NUM_2:
                case MMI_PHB_FIELD_OPT_NUM_3:
                    
                    if(g_mmi_phb_choose_field.highlight_index < 1)
                    {
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                    }
                    else
                    {
                        g_mmi_phb_contact_p->opt_num[index].type = (mmi_phb_num_type_enum)mmi_phb_get_aas_type_label(g_mmi_phb_choose_field.highlight_index-1,g_mmi_phb_save_contact_p->storage);
                    }
                    break;
            #endif
                case MMI_PHB_FIELD_MOBILE_NUMBER:
                default:
                    g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                    break;
            }
            g_mmi_phb_save_contact_p->field_mask |= (U32)temp_type;
            g_mmi_phb_save_contact_p->highlight_type = mmi_phb_get_field_type_by_field_mask((U32)temp_type);
            if (g_mmi_phb_save_contact_p->edit_temp_done)
            {
                g_mmi_phb_save_contact_p->done_flag = 1;
                cui_fseditor_get_text(
                    g_mmi_phb_save_contact_p->editor_id,
                    g_mmi_phb_save_contact_p->edit_temp_buff,
                    sizeof(g_mmi_phb_save_contact_p->edit_temp_buff));
                mmi_wcscpy(g_mmi_phb_contact_p->opt_num[index].number, g_mmi_phb_save_contact_p->edit_temp_buff);
            }
            break;
        }
    }
#endif    
    cui_fseditor_close(g_mmi_phb_save_contact_p->editor_id);
    mmi_frm_scrn_close_active_id();
}


void mmi_phb_edit_add_more_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
    U8 storage = g_mmi_phb_save_contact_p->storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_convert_to_name(
        name,
        g_mmi_phb_contact_p->name,
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        g_mmi_phb_contact_p->last_name,
    #else
        NULL,
    #endif
        MMI_PHB_NAME_LENGTH);

#ifdef __MMI_PHB_USIM_SUPPORT__
    if(mmi_phb_check_storage(MMI_TRUE, storage))
#endif
    {
        mmi_phb_entry_choose_field_ex(
            g_mmi_phb_save_contact_p->sg_id,
            name,
            storage,
            phb_edit_number_type,
            g_mmi_phb_save_contact_p->field_mask,
            mmi_phb_edit_add_more_number,
            mmi_phb_edit_add_more_number_done,
            mmi_frm_scrn_close_active_id);
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    else
    {
        U8 type_array[MMI_PHB_FIELD_LABEL_COUNT];

        if (srv_phb_get_field_type_list(type_array,MMI_PHB_CONTACT_FIELD_ID_NUMBER, (phb_storage_enum)storage))
        {
            mmi_phb_entry_choose_field_ex(
                g_mmi_phb_save_contact_p->sg_id,
                name,
                storage,
                phb_edit_usim_field_optional,
                g_mmi_phb_save_contact_p->field_mask,
                mmi_phb_edit_add_more_number,
                mmi_phb_edit_add_more_number_done,
                mmi_frm_scrn_close_active_id);
        }
        else
        {
            g_mmi_phb_choose_field.highlight_index = 0;
            g_mmi_phb_choose_field.number_to_dial[0] = (U16 *)GetString(STR_ID_PHB_MOBILE_NUMBER);
            g_mmi_phb_choose_field.number_type[0] = mmi_phb_get_usim_number_type(g_mmi_phb_save_contact_p->field_mask);
            mmi_frm_display_dummy_screen_ex(g_mmi_phb_save_contact_p->sg_id, SCR_ID_PHB_PROCESSING);
            mmi_phb_edit_add_more_number_done();
        }
    }
#endif

}


#if !(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_inline_qwerty_key_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_phb_qwerty_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imc_key_is_current_symbol_key(mmi_key_code)
        || mmi_key_code == KEY_SPACE || mmi_key_code == KEY_QWERTY_ENTER)
    {
        if (GetKeyHandler(KEY_LSK, KEY_EVENT_UP))
        {
            mmi_phb_entry_inline_edit_num_for_tab();

            if (mmi_imc_is_connected() && (gui_multi_line_reset_create_flag() == 1))
            {
                ExecuteCurrKeyHandler((S16)mmi_key_code, KEY_EVENT_DOWN);
                ExecuteCurrKeyHandler((S16)mmi_key_code, KEY_EVENT_UP);
            }
            
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif
#endif


#if !defined (__MMI_FTE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_pre_entry_inline_edit_num_for_tab
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_pre_entry_inline_edit_num_for_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_inline_edit_num_for_tab();
    
}
#endif
#else /*__MMI_PHB_UI_IN_TABS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_edit_ok
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_entry_edit_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    if (g_mmi_phb_save_contact_p->done_flag || g_mmi_phb_res_p->done)
#else
    if (g_mmi_phb_save_contact_p->done_flag)
#endif
    {
        mmi_phb_entry_op_save_contact_confirm();
    }
    else
    {
    /* For birthday part, always call birthday reminder callback */
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    #ifdef __MMI_BIRTHDAY_REMINDER__
        if (g_mmi_phb_save_contact_p->action == MMI_PHB_OP_EDIT)
        {
            mmi_phb_single_op_extra_handle_bday(0, g_mmi_phb_save_contact_p->store_index);
        }
    #endif
    #endif

        cui_inline_close(g_mmi_phb_save_contact_p->editor_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_ok_for_csk
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_edit_entry_option()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_edit_ok_for_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_edit_ok();
}

#ifdef __MMI_PHB_USIM_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_usim_entry_add_details_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_usim_entry_add_details_done(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type_array[MMI_PHB_FIELD_LABEL_COUNT];
    U8 i, field_index = 0, field_type;
    U16 pre_item_id = 0;
    MMI_BOOL found = MMI_FALSE;
    U32 added_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_get_field_type_list(
        type_array,
        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
        (phb_storage_enum)g_mmi_phb_save_contact_p->storage);
    
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (added_type == MMI_PHB_FIELD_OPT_NUM_1 ||
        added_type == MMI_PHB_FIELD_OPT_NUM_2 ||
        added_type == MMI_PHB_FIELD_OPT_NUM_3)
    {
        S32 i, index;
        U8 temp_type;
        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            temp_type = g_mmi_phb_contact_p->opt_order[i];
            field_type = mmi_phb_get_usim_field_mask_by_field_mask(temp_type,MMI_FALSE);
            index = field_type-1;
            if (!(g_mmi_phb_save_contact_p->field_mask & temp_type))
            {
                if(mmi_phb_check_usim_detail_ex((phb_storage_enum)g_mmi_phb_save_contact_p->storage,0,PHB_SNE))
                {
                    if((g_mmi_phb_save_contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NICK) == SRV_PHB_ENTRY_FIELD_NICK)
                    {
                        if(g_mmi_phb_choose_field.highlight_index == 0)
                        {
                            g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                        }   
                        else
                        {
                            g_mmi_phb_contact_p->opt_num[index].type = (mmi_phb_num_type_enum)mmi_phb_get_aas_type_label(g_mmi_phb_choose_field.highlight_index-1,g_mmi_phb_save_contact_p->storage);
                        }
                    }
                    else if(g_mmi_phb_choose_field.highlight_index == 1)
                    {
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                    }
                    else if(g_mmi_phb_choose_field.highlight_index > 1)
                    {
                        g_mmi_phb_contact_p->opt_num[index].type = (mmi_phb_num_type_enum)mmi_phb_get_aas_type_label(g_mmi_phb_choose_field.highlight_index-2,g_mmi_phb_save_contact_p->storage);
                    }
                }  
                /*if the sim not support SNE*/
                else
                {
                    if(g_mmi_phb_choose_field.highlight_index < 1)
                    {
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                    }
                    else
                    {
                        g_mmi_phb_contact_p->opt_num[index].type = (mmi_phb_num_type_enum)mmi_phb_get_aas_type_label(g_mmi_phb_choose_field.highlight_index-1,g_mmi_phb_save_contact_p->storage);
                    }
                }
                
                g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_usim_field_mask_by_field_type(field_type,MMI_FALSE);
                g_mmi_phb_save_contact_p->highlight_type = added_type;
                break;
            }
        }         
    }
    else
#endif
    {   
        g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_usim_field_mask_by_field_type((U8)added_type,MMI_FALSE);
        if(added_type == MMI_PHB_USIM_FIELD_SNE)
            added_type = MMI_PHB_FIELD_NICK_NAME;
        g_mmi_phb_save_contact_p->highlight_type = added_type;
    }
    g_mmi_phb_save_contact_p->add_detail = MMI_TRUE;
    
    field_type = g_mmi_phb_save_contact_p->highlight_type;
    for (i = MMI_PHB_FIELD_NAME; i < MMI_PHB_FIELD_TOTAL; i++)
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if ((i == MMI_PHB_FIELD_OPT_NUM_1) ||
            (i == MMI_PHB_FIELD_OPT_NUM_2) ||
            (i == MMI_PHB_FIELD_OPT_NUM_3))
        {
            field_index = mmi_phb_usim_edit_get_opt_number_field((U8)(i - MMI_PHB_FIELD_OPT_NUM_1));
        }
        else
    #endif
        {
            field_index = i;
        }
        if (mmi_phb_edit_usim_field_display(field_index, g_mmi_phb_save_contact_p->field_mask, g_mmi_phb_save_contact_p->storage))
        {
            /**
             * caculate highlight index
             */
            if (found)
            {
                pre_item_id = (U16) (field_index + CUI_INLINE_ITEM_ID_BASE);
                break;
            }
            if (field_index == field_type)
            {
                found = MMI_TRUE;
            }
        }
    }

    if (!found || pre_item_id == 0)
    {
        pre_item_id = (U16) CUI_INLINE_INSERT_TAIL;
    }
    mmi_phb_op_fill_inline_item(
        (U16) (field_type + CUI_INLINE_ITEM_ID_BASE),
        pre_item_id,
        g_mmi_phb_save_contact_p->storage,
        g_mmi_phb_save_contact_p->editor_id);
        
    cui_inline_set_highlight_item(
        g_mmi_phb_save_contact_p->editor_id,
        (U16) (field_type + CUI_INLINE_ITEM_ID_BASE));   
    mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
}


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_usim_check_opt_number
 * DESCRIPTION
 *  check option number exist
 * PARAMETERS
 *  contact info struct
 * RETURNS
 *  if no option number, then return MMI_TRUE
 *****************************************************************************/
static MMI_BOOL mmi_phb_usim_check_opt_number(mmi_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_PHB_OPT_NUM_COUNT; index++)
    {
        if (0 != contact->opt_num[index].number[0])
        {
            result = MMI_FALSE;    
        }
    }

    return result;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_delete_usim_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_delete_usim_detail(U32 field_mask,mmi_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0xff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(field_mask)
    {
        case SRV_PHB_ENTRY_FIELD_NICK:
            contact->nick_name[0] = 0;
            break;

   #ifdef __MMI_PHB_OPTIONAL_FIELD__ 
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            index = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            index = 1;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            index = 2;
            break;

        case SRV_PHB_ENTRY_FIELD_EMAIL1:
            contact->emailAddress[0] = 0;
            break;
    #endif
        
        default:
            break;
    }

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (index != 0xff)
    {
        contact->opt_num[index].number[0] = 0;

        if (mmi_phb_usim_check_opt_number(contact))
        {
            return;
        }
        
        for (index = 0; index < MMI_PHB_OPT_NUM_COUNT; index++) 
        {
            if (contact->opt_order[index] == field_mask)
            {
                while ((++index) < MMI_PHB_OPT_NUM_COUNT)
                {
                    contact->opt_order[index - 1] = contact->opt_order[index];
                }
                contact->opt_order[index - 1] = field_mask;
                break;
            }
        }      
    }
#endif
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_add_details_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_add_details_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, field_index = 0, field_type;
    U16 pre_item_id = 0;
    MMI_BOOL found = MMI_FALSE;
    U32 added_type = g_mmi_phb_choose_field.number_type[g_mmi_phb_choose_field.highlight_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if ((added_type == MMI_PHB_FIELD_MOBILE_NUMBER) ||
        (added_type == MMI_PHB_FIELD_HOME_NUMBER) ||
        (added_type == MMI_PHB_FIELD_OFFCIE_NUMBER) ||
        (added_type == MMI_PHB_FIELD_FAX_NUMBER))
    {
        S32 i, index;
        U8 temp_type;
        for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
        {
            temp_type = g_mmi_phb_contact_p->opt_order[i];
            index = (U32)(mmi_phb_get_field_type_by_field_mask(temp_type) - MMI_PHB_FIELD_OPT_NUM_1);
            if (!(g_mmi_phb_save_contact_p->field_mask & temp_type))
            {
                switch (added_type)
                {
                    case MMI_PHB_FIELD_HOME_NUMBER:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_HOME;
                        break;

                    case MMI_PHB_FIELD_OFFCIE_NUMBER:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_OFFICE;
                        break;

                    case MMI_PHB_FIELD_FAX_NUMBER:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_FAX;
                        break;

                    case MMI_PHB_FIELD_MOBILE_NUMBER:
                    default:
                        g_mmi_phb_contact_p->opt_num[index].type = MMI_PHB_NUM_TYPE_MOBILE;
                        break;
                }
                g_mmi_phb_save_contact_p->field_mask |= (U32)temp_type;
                g_mmi_phb_save_contact_p->highlight_type = mmi_phb_get_field_type_by_field_mask((U32)temp_type);
                break;
            }
        }
    }
    else
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
    {
        g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type((U8)added_type);
        g_mmi_phb_save_contact_p->highlight_type = added_type;
    }
    g_mmi_phb_save_contact_p->add_detail = MMI_TRUE;

    field_type = g_mmi_phb_save_contact_p->highlight_type;
    for (i = MMI_PHB_FIELD_NAME; i < MMI_PHB_FIELD_TOTAL; i++)
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if ((i == MMI_PHB_FIELD_OPT_NUM_1) ||
            (i == MMI_PHB_FIELD_OPT_NUM_2) ||
            (i == MMI_PHB_FIELD_OPT_NUM_3))
        {
            field_index = mmi_phb_edit_get_opt_number_field((U8)(i - MMI_PHB_FIELD_OPT_NUM_1));
        }
        else
    #endif
        {
            field_index = i;
        }
        if (mmi_phb_edit_field_display(field_index, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
        {
            /**
             * caculate highlight index
             */
            if (found)
            {
                pre_item_id = (U16) (field_index + CUI_INLINE_ITEM_ID_BASE);
                break;
            }
            if (field_index == field_type)
            {
                found = MMI_TRUE;
            }
        }
    }
    if (!found || pre_item_id == 0)
    {
        pre_item_id = (U16) CUI_INLINE_INSERT_TAIL;
    }

#ifdef __MMI_PHB_INFO_FIELD__
    if (field_type == MMI_PHB_FIELD_ADDRESS)
    {
        if (mmi_phb_edit_field_display(MMI_PHB_FIELD_NOTE, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
        {
            pre_item_id = (U16) (MMI_PHB_FIELD_NOTE + CUI_INLINE_ITEM_ID_BASE);
        }
        for (field_index = MMI_PHB_FIELD_ADR_POBOX; field_index <= MMI_PHB_FIELD_ADR_COUNTRY; field_index++)
        {
            mmi_phb_op_fill_inline_item(
                (U16) (field_index + CUI_INLINE_ITEM_ID_BASE),
                pre_item_id,
                PHB_STORAGE_NVRAM,
                g_mmi_phb_save_contact_p->editor_id);
        }
        cui_inline_set_highlight_item(
            g_mmi_phb_save_contact_p->editor_id,
            (U16) (MMI_PHB_FIELD_ADR_POBOX + CUI_INLINE_ITEM_ID_BASE));
    }
    else
#endif /* __MMI_PHB_INFO_FIELD__ */
    {
        mmi_phb_op_fill_inline_item(
            (U16) (field_type + CUI_INLINE_ITEM_ID_BASE),
            pre_item_id,
            PHB_STORAGE_NVRAM,
            g_mmi_phb_save_contact_p->editor_id);
        cui_inline_set_highlight_item(
            g_mmi_phb_save_contact_p->editor_id,
            (U16) (field_type + CUI_INLINE_ITEM_ID_BASE));
    }
    
    mmi_frm_scrn_close(g_mmi_phb_save_contact_p->sg_id, SCR_CHOOSE_NUMBER);
}


static void mmi_phb_entry_add_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
    U8 storage;
    U32 field_mask = g_mmi_phb_save_contact_p->field_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_convert_to_name(
        name,
        g_mmi_phb_contact_p->name,
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        g_mmi_phb_contact_p->last_name,
    #else
        NULL,
    #endif
        MMI_PHB_NAME_LENGTH);

    storage = srv_phb_get_storage(g_mmi_phb_save_contact_p->store_index);

    if(storage == 0xFF)
    {
        storage = g_mmi_phb_save_contact_p->storage;
    }

    if(mmi_phb_check_storage(MMI_TRUE, storage))
    {
    #if defined(__MMI_PHB_INFO_FIELD__)
        U32 exist_num = 0;
        U32 index;

        for (index = 0; index < 31; index++)
        {
            if (field_mask & (1<<index))
            {
                exist_num++;
            }
        }

        if ((MAX_INLINE_ITEMS/2 - exist_num) <= (MMI_PHB_FIELD_ADR_COUNTRY- MMI_PHB_FIELD_ADR_POBOX))
        {
            field_mask |= SRV_PHB_ENTRY_FIELD_ADDRESS;
        }
    #endif

        mmi_phb_entry_choose_field_ex(
            g_mmi_phb_save_contact_p->sg_id,
            name,
            storage,
            phb_edit_field_optional,
            field_mask,
            mmi_phb_entry_add_details,
            mmi_phb_entry_add_details_done,
            mmi_frm_scrn_close_active_id);
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    else
        mmi_phb_entry_choose_field_ex(
            g_mmi_phb_save_contact_p->sg_id,
            name,
            storage,
            phb_edit_usim_field_optional,
            field_mask,
            mmi_phb_entry_add_details,
            mmi_phb_usim_entry_add_details_done,    
            mmi_frm_scrn_close_active_id);
#endif
}


static void mmi_phb_contact_delete_field(
                U32 field_mask,
                mmi_phb_contact_info_struct *contact,
                mmi_phb_caller_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    U8 index = 0xff;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(contact != NULL);
    
    switch (field_mask)
    {
        case SRV_PHB_ENTRY_FIELD_NAME:
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            index = 0;
            contact->opt_num[0].number[0] = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            index = 1;
            contact->opt_num[1].number[0] = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            index = 2;
            contact->opt_num[2].number[0] = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_EMAIL1:
            contact->emailAddress[0] = 0;
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        case SRV_PHB_ENTRY_FIELD_EMAIL2:
            contact->emailAddress2[0] = 0;
            break;
    #endif
    
        case SRV_PHB_ENTRY_FIELD_COMPANY:
            contact->companyName[0] = 0;
            break;
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        case SRV_PHB_ENTRY_FIELD_ADDRESS:
            contact->pobox[0] = 0;
            contact->extension[0] = 0;
            contact->street[0] = 0;
            contact->city[0] = 0;
            contact->state[0] = 0;
            contact->postalcode[0] = 0;
            contact->country[0] = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_TITLE:
            contact->title[0] = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_URL:
            contact->url[0] = 0;
            break;

        case SRV_PHB_ENTRY_FIELD_NOTE:
            contact->note[0] = 0;
            break;
    #endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif

        case SRV_PHB_ENTRY_FIELD_GROUP:
            break;

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case SRV_PHB_ENTRY_FIELD_BDAY:
            contact->bday[0] = 0;
            contact->b_day[0] = 0;
            contact->b_month[0] = 0;
            contact->b_year[0] = 0;
            break;
    #endif

    #ifdef __MMI_PHB_CALLER_RES__
        case SRV_PHB_ENTRY_FIELD_RING:
            res->selected_ring_index = 0;
            res->ring_id = 0;
            res->ring_path[0] = 0;
            res->ring_location = MMI_PHB_IMAGE_NO_SELECT;
            break;

        case SRV_PHB_ENTRY_FIELD_PIC:
            res->selected_pic_index = 0;
            res->img_id = 0;
            res->img_path[0] = 0;
            res->image_location = MMI_PHB_IMAGE_NO_SELECT;
            break;

    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case SRV_PHB_ENTRY_FIELD_VIDEO:
            res->selected_video_index = 0;
            res->video_id = 0;
            res->video_path[0] = 0;
            res->video_location = MMI_PHB_IMAGE_NO_SELECT;
            break;
    #endif
    #endif /* __MMI_PHB_CALLER_RES__ */
    
        case SRV_PHB_ENTRY_FIELD_DEF:
        default:
            break;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (index != 0xff)
    {
        contact->opt_num[index].number[0] = 0;
        for (index = 0; index < MMI_PHB_OPT_NUM_COUNT; index++)
        {
            if (contact->opt_order[index] == field_mask)
            {
                while ((++index) < MMI_PHB_OPT_NUM_COUNT)
                {
                    contact->opt_order[index - 1] = contact->opt_order[index];
                }
                contact->opt_order[index - 1] = field_mask;
                break;
            }
        }
    }
#endif
}


static void mmi_phb_entry_edit_delete_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask;
    U8 field_index = 0;
    U8 field_type = g_mmi_phb_save_contact_p->highlight_type;
    U16 pre_item_id = 0;
    MMI_BOOL found = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_PHB_USIM_SUPPORT__
    if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
    {
        field_mask = mmi_phb_get_usim_field_mask_by_field_type(field_type,MMI_TRUE);
        mmi_phb_delete_usim_detail(field_mask,g_mmi_phb_contact_p);
    }
    else
    #endif
    {
        field_mask = mmi_phb_get_field_mask_by_field_type(field_type);
    #ifdef __MMI_PHB_CALLER_RES__
        mmi_phb_contact_delete_field(field_mask, g_mmi_phb_contact_p, g_mmi_phb_res_p);
    #else
        mmi_phb_contact_delete_field(field_mask, g_mmi_phb_contact_p, NULL);
    #endif
    }

    for (field_index = field_type; field_index < MMI_PHB_FIELD_TOTAL; field_index++)
    {
        if (mmi_phb_edit_field_display(field_index, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
        {
            /**
             * caculate highlight index
             */
            if (found)
            {
                pre_item_id = (U16) (field_index + CUI_INLINE_ITEM_ID_BASE);
                break;
            }
            if (field_index == field_type)
            {
                found = MMI_TRUE;
            }
        }
    }
    if (!found || pre_item_id == 0)
    {
        found = MMI_FALSE;
        for (field_index = field_type; field_index >= MMI_PHB_FIELD_NUMBER; field_index--)
        {
            if (mmi_phb_edit_field_display(field_index, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
            {
                /**
                 * caculate highlight index
                 */
                if (found)
                {
                    pre_item_id = (U16) (field_index + CUI_INLINE_ITEM_ID_BASE);
                    break;
                }
                if (field_index == field_type)
                {
                    found = MMI_TRUE;
                }
            }
        }
    }

    if (!found || pre_item_id == 0)
    {
        pre_item_id = (U16) (MMI_PHB_FIELD_NAME + CUI_INLINE_ITEM_ID_BASE);
    }

    g_mmi_phb_save_contact_p->field_mask &= ~field_mask;
    g_mmi_phb_save_contact_p->add_detail = MMI_TRUE;
    g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;

#ifdef __MMI_PHB_INFO_FIELD__
    if (field_type >= MMI_PHB_FIELD_ADR_POBOX && field_type <= MMI_PHB_FIELD_ADR_COUNTRY)
    {
        if (mmi_phb_edit_field_display(MMI_PHB_FIELD_NOTE, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
        {
            pre_item_id = (U16) (MMI_PHB_FIELD_NOTE + CUI_INLINE_ITEM_ID_BASE);
        }
        else
        {
            for (field_index = field_type; field_index >= MMI_PHB_FIELD_NUMBER; field_index--)
            {
                if (mmi_phb_edit_field_display(field_index, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
                {
                    /**
                     * caculate highlight index
                     */
                    pre_item_id = (U16) (field_index + CUI_INLINE_ITEM_ID_BASE);
                    break;
                }
            }
        }
        for (field_index = MMI_PHB_FIELD_ADR_POBOX; field_index <= MMI_PHB_FIELD_ADR_COUNTRY; field_index++)
        {
            cui_inline_delete_item(g_mmi_phb_save_contact_p->editor_id, (U16) (field_index + CUI_INLINE_ITEM_ID_BASE));
            cui_inline_delete_item(g_mmi_phb_save_contact_p->editor_id, (U16) (field_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL));
        }
        cui_inline_set_highlight_item(g_mmi_phb_save_contact_p->editor_id, pre_item_id);
    }
    else
#endif /* __MMI_PHB_INFO_FIELD__ */
    {
        cui_inline_delete_item(g_mmi_phb_save_contact_p->editor_id, (U16) (field_type + CUI_INLINE_ITEM_ID_BASE));
        cui_inline_delete_item(g_mmi_phb_save_contact_p->editor_id, (U16) (field_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL));
        cui_inline_set_highlight_item(g_mmi_phb_save_contact_p->editor_id, pre_item_id);
        if (field_mask & SRV_PHB_ENTRY_FIELD_GSM_NUM)
        {
        #ifdef __MMI_PHB_SPEED_DIAL__
            mmi_phb_speed_dial_pre_del_number(g_mmi_phb_save_contact_p->store_index, field_mask);
        #endif
        #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
            if (g_mmi_phb_contact_p->default_number == field_mask)
            {
                g_mmi_phb_contact_p->default_number = 0xfe;
            }
        #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
        }
    }
    g_mmi_phb_save_contact_p->highlight_type = (U8)(pre_item_id - CUI_INLINE_ITEM_ID_BASE);
    mmi_frm_scrn_close_active_id();
}
#endif /*__MMI_PHB_UI_IN_TABS__ */

#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

mmi_ret mmi_phb_editor_set_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        //case EVT_ID_SCRN_DEINIT:
        {
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        #ifdef __MMI_BIRTHDAY_REMINDER__
            mmi_tdl_br_clear_buffer_cb();
        #endif
        #endif
           // break;
        }
        //default:
          //  break;
    }

    return MMI_RET_OK;
}


#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#ifdef __MMI_BIRTHDAY_REMINDER__
static void mmi_phb_edit_add_birthday_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = 0xffff; /* add contact, so no store_index */
    MYTIME birthday;
    mmi_id sg_id = g_mmi_phb_save_contact_p->sg_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->action == MMI_PHB_OP_EDIT
#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        && !g_mmi_phb_save_contact_p->add_more
#endif
        )
    {
        store_index = g_mmi_phb_save_contact_p->store_index;
    }

    birthday.nYear = (U16) gui_atoi(g_mmi_phb_contact_p->b_year);
    birthday.nMonth = (U8) gui_atoi(g_mmi_phb_contact_p->b_month);
    birthday.nDay = (U8) gui_atoi(g_mmi_phb_contact_p->b_day);

    /* should check 1. store_index, 2. birhday exist in tdl */
    //mmi_tdl_birthday_add_confirm(store_index, &birthday);
    mmi_tdl_br_add_reminder_entry_edit(sg_id, store_index, &birthday);
}
#endif
#endif


#ifdef __MMI_PHB_UI_IN_TABS__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_tap_callback
 * DESCRIPTION
 *  fte contact main list tap callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_edit_contact_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_phb_edit_option)
    {
        execute_left_softkey_function(KEY_EVENT_UP);
    }
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */



#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
static void entry_inline_birthday_full_screen(void);

void DateEditorCallBack(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((U16*) DateStr, "%s/%s/%s", (CHAR*) year, (CHAR*) month, (CHAR*) day);
}


void inline_birthday_full_screen_validate_Input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *bday = g_mmi_phb_save_contact_p->edit_temp_buff;
    mmi_id sg_id = g_mmi_phb_save_contact_p->sg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    {
        mmi_ucs2cpy((CHAR*) g_mmi_phb_contact_p->b_year, (CHAR*) bday);
        mmi_ucs2cpy((CHAR*) g_mmi_phb_contact_p->b_month, (CHAR*) (bday + (MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)));
        mmi_ucs2cpy((CHAR*) g_mmi_phb_contact_p->b_day, (CHAR*) (bday + (MMI_PHB_BIRTHDAY_MONTH_LENGTH + 1 + MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)));
        
        DateEditorCallBack(
            (U8*) g_mmi_phb_contact_p->bday,
            (U8*) g_mmi_phb_contact_p->b_day,
            (U8*) g_mmi_phb_contact_p->b_month,
            (U8*) g_mmi_phb_contact_p->b_year);
        g_mmi_phb_save_contact_p->bday_changed = MMI_TRUE;
        g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
    }

#ifdef __MMI_BIRTHDAY_REMINDER__
    {
        U16 store_index = 0xffff; /* add contact, so no store_index */
        MYTIME birthday;
        
        if (g_mmi_phb_save_contact_p->action == MMI_PHB_OP_EDIT
    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
            && !g_mmi_phb_save_contact_p->add_more
    #endif
            )
        {
            store_index = g_mmi_phb_save_contact_p->store_index;
        }

        birthday.nYear = (U16) gui_atoi(g_mmi_phb_contact_p->b_year);
        birthday.nMonth = (U8) gui_atoi(g_mmi_phb_contact_p->b_month);
        birthday.nDay = (U8) gui_atoi(g_mmi_phb_contact_p->b_day);

        /* should check 1. store_index, 2. birhday exist in tdl */
        mmi_tdl_birthday_add_confirm(sg_id, store_index, &birthday);
    }        
#endif

    mmi_frm_scrn_close(sg_id, SCR_ID_PHB_TAB_EDIT_BIRTHDAY);
}


static void mmi_phb_entry_inline_birthday_full_screen_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(inline_birthday_full_screen_validate_Input, KEY_EVENT_UP);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(inline_birthday_full_screen_validate_Input, KEY_EVENT_UP);
}


void exit_inline_birthday_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //GenericExitInlineScreen(SCR_ID_PHB_TAB_EDIT_BIRTHDAY, entry_inline_birthday_full_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_inline_changed_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Changed item index
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_inline_changed_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_phb_item_list[index])
    {
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    #ifdef __MMI_BIRTHDAY_REMINDER__
        case MMI_PHB_FIELD_BIRTHDAY:
            g_mmi_phb_save_contact_p->bday_changed = MMI_TRUE;
            g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
            break;
    #endif
    #endif

        case MMI_PHB_FIELD_PIC:
        case MMI_PHB_FIELD_RING:
    #ifdef __MMI_PHB_CALLER_VIDEO__
        case MMI_PHB_FIELD_VIDEO:
    #endif  
            g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
            break;

        default:
            break;
    }
}


void entry_inline_birthday_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize;    
    U16 *bday = g_mmi_phb_save_contact_p->edit_temp_buff;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ID_PHB_TAB_EDIT_BIRTHDAY,
            exit_inline_birthday_full_screen,
            entry_inline_birthday_full_screen,
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    InitializeCategory57Screen();
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    SetInlineItemCaption(&wgui_inline_items[0], (U8*) get_string(STR_ID_PHB_BIRTHDAY));
    SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    if (guiBuffer == NULL)
    {
        if (!mmi_phb_bday_format(g_mmi_phb_contact_p->bday, g_mmi_phb_contact_p->b_day, g_mmi_phb_contact_p->b_month, g_mmi_phb_contact_p->b_year))
        {
            MYTIME current_time;
            CHAR time_string[6];
            GetDateTime(&current_time);
            sprintf(time_string, "%04d", current_time.nYear);
            mmi_asc_to_ucs2((CHAR*) bday, time_string);
            sprintf(time_string, "%02d", current_time.nMonth);
            mmi_asc_to_ucs2((CHAR*) (bday + (MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)), time_string);
            sprintf(time_string, "%02d", current_time.nDay);
            mmi_asc_to_ucs2((CHAR*) (bday + (MMI_PHB_BIRTHDAY_MONTH_LENGTH + 1 + MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)), time_string);
        }
        else
        {
            mmi_ucs2cpy((CHAR*) bday, (CHAR*) g_mmi_phb_contact_p->b_year);
            mmi_ucs2cpy((CHAR*) (bday + (MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)), (CHAR*) g_mmi_phb_contact_p->b_month);
            mmi_ucs2cpy((CHAR*) (bday + (MMI_PHB_BIRTHDAY_MONTH_LENGTH + 1 + MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)), (CHAR*) g_mmi_phb_contact_p->b_day);
        }
    }

    SetInlineItemDate(
        &(wgui_inline_items[1]),
        (U8*) (bday + (MMI_PHB_BIRTHDAY_MONTH_LENGTH + 1 + MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)),
        (U8*) (bday + (MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1)),
        (U8*) bday,
        DateEditorCallBack);

    g_mmi_phb_item_list[1] = MMI_PHB_FIELD_BIRTHDAY;

    RegisterInlineItemChangedNotification(mmi_phb_inline_changed_callback);
    RightJustifyInlineItem(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    set_inline_date_boundary(MMI_PHB_BDAY_MAX_YEAR_INT, 1900, 12, 1); 
    SetInlineItemFullWidth(&wgui_inline_items[1]);

    RegisterHighlightHandler(mmi_phb_entry_inline_birthday_full_screen_highlight_hdlr);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_PHB_TAB_EDIT_BIRTHDAY, &inputBufferSize);

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);   /* sets the data */
    }

    ShowCategory257Screen(
        STR_ID_PHB_BIRTHDAY,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_ID_PHB_BIRTHDAY_IMAGE,
        2,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(inline_birthday_full_screen_validate_Input, mmi_frm_scrn_close_active_id);
}

#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#if !(defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ime_key_handler
 * DESCRIPTION
 *  Execute left softkey handler
 * PARAMETERS
 *  key_code        [IN]        unused (just for register funchdlr)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_ime_key_handler(MMI_key_code_type key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_input_key = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_inline_edit_num_for_tab();
    
    if (mmi_imc_is_connected() && (gui_multi_line_reset_create_flag() == 1))
    {
        if (key_code == KEY_STAR || key_code == KEY_POUND)
        {
            if (mmi_imc_key_is_current_symbol_key((S16)key_code))
            {
                is_input_key = MMI_TRUE;
            }
        }
        else
        {
            is_input_key = MMI_TRUE;
        }

        if (is_input_key)
        {
            ExecuteCurrKeyHandler((S16)key_code, KEY_EVENT_DOWN);
            ExecuteCurrKeyHandler((S16)key_code, KEY_EVENT_UP);
        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_edit_number_highlight_hdlr
 * DESCRIPTION
 *  Execute left softkey handler
 * PARAMETERS
 *  key_code        [IN]        unused (just for register funchdlr)
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_phb_edit_name_highlight_hdlr(U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name[0] != 0 && (g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);


	    DisableCategory57ScreenRskBack();//////////////////////////maggie 0802

#ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
        SetCenterSoftkeyFunction(mmi_phb_entry_inline_edit_name_for_tab, KEY_EVENT_UP);
#endif    
        g_mmi_phb_edit_option = MMI_TRUE;
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(mmi_phb_entry_inline_edit_name_for_tab, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
        SetCenterSoftkeyFunction(mmi_phb_entry_inline_edit_name_for_tab, KEY_EVENT_UP);
#endif
    }
}
static void mmi_phb_edit_number_highlight_hdlr(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number[0] != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);

#ifndef __MMI_WGUI_DISABLE_CSK__
#ifndef __MMI_MAINLCD_96X64__

        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif
        DisableCategory57ScreenRskBack();
        SetCenterSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_EDITOR, mmi_phb_qwerty_key_handler);
    #else
        register_MMI_key_input_handler();
        register_MMI_key_input_extend_handler();
        clear_key_down_handler();
        register_key_up_handler(mmi_phb_ime_key_handler);
    #endif
        g_mmi_phb_edit_option = MMI_TRUE;
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
#ifndef __MMI_MAINLCD_96X64__

        ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif
        SetCenterSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);
    }
}
#endif

U16 mmi_phb_inline_tab_get_title_bar_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_mmi_phb_save_contact_p->action)
    {
        case MMI_PHB_OP_ADD:
            str = STR_SCR_ADD_NEW_ENTRY_CAPTION;
            break;
            
        case MMI_PHB_OP_EDIT:
            str = STR_SCR_INLINE_EDIT_CAPTION;
            break;
            
        default:
            break;
    }

    return str;
}


U16 mmi_phb_op_get_title_bar_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_id = GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID);
    return image_id;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_phb_op_edit_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_GROUP_ENHANCE__
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_VIEW_LSK);
    SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);
#else
    if (mmi_phb_check_storage(MMI_TRUE, g_mmi_phb_save_contact_p->storage))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_VIEW_LSK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    } 
    SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);
#endif   
}


#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_caller_res_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_caller_res_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_PIC)        
    {
        if (g_mmi_phb_save_contact_p->pre_photo_idx != index)
        {
            PU8 thumbnail_path;
            U32 max_index = 0;

        #if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
            max_index += 4;
        #endif
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
        #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
            max_index++;
        #endif
            max_index++;
        #endif

            if (index == max_index)    /* An Image in select path */     
            {
                thumbnail_path = (PU8)g_mmi_phb_res_p->img_path;
            }
            else
            {
                thumbnail_path = NULL;
            }

            if (g_mmi_phb_res_p->img_path[0]
                && ((g_mmi_phb_save_contact_p->pre_photo_idx == max_index) || (index == max_index))
                )
            {
                ReconfigureInlineItemCaptionThumbnail(
                    &wgui_inline_items[0],
                    (PU8)GetString(STR_ID_PHB_CALLER_PIC),
                    thumbnail_path,
                    NULL,
                    IMG_ID_PHB_VIEW_PHOTO,
                    1);
                show_fixed_list_specified_item(0);
            }

            g_mmi_phb_save_contact_p->pre_photo_idx = (U8)index;
        }
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  item_index      [IN]            
 *  store_index     [IN]            
 *  string_list     [?]             
 *  image_list      [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_op_fill_inline_item_for_tab(
           U8 field_index,
           U8 item_index,
           U8 storage,
           U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    U16 img_id;
#endif
#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[2 * item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemFullWidth(&wgui_inline_items[2 * item_index]);

    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
        {
            U16 first_name_str = mmi_phb_get_first_name_str(storage);
            
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(first_name_str));
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U32 name_length = mmi_phb_get_name_length(storage);
                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;

                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);    
            #if defined(__PHB_0x81_SUPPORT__)
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->name,
                    name_length + 1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    (INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL),
                    NULL);
            #else
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->name,
                    name_length + 1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);
            #endif
            }
            else
            {
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);    
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->name,
                    MMI_PHB_NAME_FIELD_LENGTH + 1,
                    (IMM_INPUT_TYPE_SENTENCE /*| INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING */),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);
            }
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], first_name_str);
        #endif
            break;
        }

    #ifdef __MMI_PHB_LAST_NAME_FIELD__    
        case MMI_PHB_FIELD_LAST_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_LAST_NAME));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);    
            SetInlineItemTextEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->last_name,
                MMI_PHB_NAME_FIELD_LENGTH + 1,
                (IMM_INPUT_TYPE_SENTENCE /*| INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING */),
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                NULL);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);

#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_LAST_NAME);
        #endif 
            break;
    #endif
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
        {
            U16 nick_name_str = STR_ID_PHB_NICK_NAME;;
            
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(nick_name_str));
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U8 name_length = srv_phb_get_alpha_field_length((phb_storage_enum)storage, MMI_PHB_CONTACT_FIELD_ID_NICK);
                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;

                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);    
            #if defined(__PHB_0x81_SUPPORT__)
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->nick_name,
                    name_length + 1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    (INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL),
                    NULL);
            #else
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->nick_name,
                    name_length + 1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);
            #endif
            }
            else
            {
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);    
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->nick_name,
                    MMI_PHB_NAME_FIELD_LENGTH + 1,
                    (IMM_INPUT_TYPE_SENTENCE /*| INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING */),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);
            }
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], nick_name_str);
        #endif
            break;
        }
   #endif
    
        case MMI_PHB_FIELD_NUMBER:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NUMBER));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->number,
                MMI_PHB_NUMBER_LENGTH + 1,
                IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);

        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_NUMBER);
        #endif

        #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
            if (((phb_storage_enum)g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM) &&
                ((g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_NUMBER) ||
                (g_mmi_phb_contact_p->default_number == 0xff)))
            {
                if (g_mmi_phb_contact_p->number[0])
                {
                    SetInlineIconStyle(&wgui_inline_items[2 * item_index + 1], (PU8)GetImage(IMG_ID_PHB_DEFAULT_NUM),TRUE);
                }
                else if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_NUMBER)
                {
                    g_mmi_phb_contact_p->default_number = 0xfe;
                }
            }
        #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */  
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (!g_mmi_phb_contact_p->number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                mmi_phb_speed_dial_pre_del_number(g_mmi_phb_save_contact_p->store_index, SRV_PHB_ENTRY_FIELD_NUMBER);
            }
        #endif
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_MOBILE_NUMBER;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;

    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        case MMI_PHB_FIELD_ADD_MORE:
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADD_MORE_DETAILS));
            image_list[2 * item_index] = IMG_MORE_DETAILS;
            break;
    #endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */

        case MMI_PHB_FIELD_ADD_NUMBERS:
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADD_MORE_NUMBER));
            image_list[2 * item_index] = IMG_ID_PHB_NEW_NUMBER;
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
        {
            U16 str_id = 0;
            U8 index = field_index - MMI_PHB_FIELD_OPT_NUM_1;
        #ifdef __MMI_PHB_USIM_SUPPORT__
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
               
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                img_id = IMG_MOBILE_NUMBER;
			    #else
			    img_id = 0;
			    #endif
				
                if(g_mmi_phb_contact_p->opt_num[index].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_MOBILE_NUMBER));
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                                    g_mmi_phb_contact_p->opt_num[index].type,
                                    MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                    (phb_storage_enum)storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }

                    SetInlineItemCaption(
                        &wgui_inline_items[2 * item_index], 
                        (U8*)label);
                }
            }
            else
        #endif
            {
                img_id = mmi_phb_get_img_by_number_type(g_mmi_phb_contact_p->opt_num[index].type);
                str_id = mmi_phb_get_str_by_number_type(g_mmi_phb_contact_p->opt_num[index].type);
                SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(str_id));
            }
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8)g_mmi_phb_contact_p->opt_num[index].number,
                MMI_PHB_NUMBER_LENGTH + 1,
                IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
        #ifdef __MMI_PHB_USIM_SUPPORT__
            if(mmi_phb_check_storage(MMI_FALSE, storage))
            {
                if(g_mmi_phb_contact_p->opt_num[index].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_MOBILE_NUMBER);
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                                g_mmi_phb_contact_p->opt_num[index].type, 
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                (phb_storage_enum)storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }

                    SetInlineItemTextEditDefaultItemNameIfEmpty_with_string(
                        &wgui_inline_items[2 * item_index + 1],
                        (U8*)label);
                }
            }
            else
        #endif
            {
                SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], str_id);
            }
        #endif

        #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)   
            if (g_mmi_phb_contact_p->default_number == mmi_phb_get_field_mask_by_field_type(field_index))
            {
                if (g_mmi_phb_contact_p->opt_num[index].number[0])
                {
                    SetInlineIconStyle(&wgui_inline_items[2 * item_index + 1], (PU8)GetImage(IMG_ID_PHB_DEFAULT_NUM),TRUE);
                }
                else
                {
                    g_mmi_phb_contact_p->default_number = 0xfe;
                }
            }
        #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (!g_mmi_phb_contact_p->opt_num[index].number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                mmi_phb_speed_dial_pre_del_number(g_mmi_phb_save_contact_p->store_index, mmi_phb_get_field_mask_by_field_type(field_index));
            }
        #endif
            image_list[2 * item_index] = img_id;
            break;
        }

        case MMI_PHB_FIELD_COMPANY_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_COMPNAY_NAME));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->companyName,
                MMI_PHB_COMPANY_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);

            image_list[2 * item_index] = IMG_COMPANY_NAME;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_COMPNAY_NAME);
        #endif
            break;
        
        case MMI_PHB_FIELD_EMAIL:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(mmi_phb_get_email_address_id(1,storage)));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        #ifdef __MMI_PHB_USIM_SUPPORT__
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U8 name_length = srv_phb_get_alpha_field_length((phb_storage_enum)storage, MMI_PHB_CONTACT_FIELD_ID_EMAIL);
                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->emailAddress,
                    name_length + 1,
                    IMM_INPUT_TYPE_EMAIL,
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);

            }
            else
        #endif
            {
                SetInlineItemTextEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    (PU8) g_mmi_phb_contact_p->emailAddress,
                    MMI_PHB_EMAIL_LENGTH + 1,
                    IMM_INPUT_TYPE_EMAIL,
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);
            }
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);

            image_list[2 * item_index] = IMG_EMAIL_ADDRESS;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], mmi_phb_get_email_address_id(1, storage));
        #endif 
    
            break;
    
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_EMAIL2_ADRESS));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->emailAddress2,
                MMI_PHB_EMAIL_LENGTH + 1,
                IMM_INPUT_TYPE_EMAIL,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                NULL);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            #if 0
            #ifdef __OP01__
/* under construction !*/
            #else
/* under construction !*/
            #endif
            #else
                image_list[2 * item_index] = IMG_EMAIL_ADDRESS;
            #endif
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_EMAIL2_ADRESS);
        #endif
    
            break;
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */            
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ /* END #ifdef __MMI_PHB_OPTIONAL_FIELD__ */

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
        #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            {
                PU8 thumbnail_path;
                U32 max_index = 0;

            #if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
                max_index += 4;
            #endif
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                max_index++;
            #endif
                max_index++;
            #endif

                if (g_mmi_phb_res_p->selected_pic_index == max_index)    /* An Image in select path */     
                {
                    thumbnail_path = (PU8)g_mmi_phb_res_p->img_path;
                }
                else
                {
                    thumbnail_path = NULL;
                }

                g_mmi_phb_save_contact_p->pre_photo_idx = g_mmi_phb_res_p->selected_pic_index;

                SetInlineItemCaptionThumbnail(
                    &wgui_inline_items[2 * item_index],
                    (PU8)GetString(STR_ID_PHB_CALLER_PIC),
                    thumbnail_path,
                    NULL,
                    IMG_ID_PHB_VIEW_PHOTO,
                    1);
            }
        #else
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_CALLER_PIC));
        #endif
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[2 * item_index + 1],
                g_mmi_phb_resource.total_image_id,
                g_mmi_phb_resource.image_name_list,
                &g_mmi_phb_res_p->selected_pic_index);

            image_list[2 * item_index] = IMG_PICTURE;
        #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            RegisterInlineSelectHighlightHandler(
                &wgui_inline_items[2 * item_index + 1],
                mmi_phb_caller_res_highlight_hdlr);
        #endif
            break;
            
        case MMI_PHB_FIELD_RING:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_CALLER_RING));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[2 * item_index + 1],
                g_mmi_phb_resource.total_ring_tone,
                g_mmi_phb_resource.ring_tone_name_list,
                &g_mmi_phb_res_p->selected_ring_index);
            RegisterInlineSelectHighlightHandler(
                &wgui_inline_items[2 * item_index + 1],
                mmi_phb_ring_tone_highlight_hdlr);
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_RING_TONE;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;

    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ASSOCIATE_VIDEO));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemSelect(
                &wgui_inline_items[2 * item_index + 1],
                g_mmi_phb_resource.total_video_id,
                g_mmi_phb_resource.video_name_list,
                &g_mmi_phb_res_p->selected_video_index);
            image_list[2 * item_index] = IMG_ID_PHB_ASSOCIATE_VIDEO;
            break;
    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    #endif /* __MMI_PHB_CALLER_RES__ */
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_BIRTHDAY));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            if (g_mmi_phb_contact_p->b_day[0] == 0 && g_mmi_phb_contact_p->b_month[0] == 0 && g_mmi_phb_contact_p->b_year[0] == 0)
            {
                MYTIME current_time;
                CHAR time_string[6];

                GetDateTime(&current_time);
                sprintf(time_string, "%04d", current_time.nYear);
                mmi_asc_to_ucs2((CHAR*) g_mmi_phb_contact_p->b_year, time_string);
                sprintf(time_string, "%02d", current_time.nMonth);
                mmi_asc_to_ucs2((CHAR*) g_mmi_phb_contact_p->b_month, time_string);
                sprintf(time_string, "%02d", current_time.nDay);
                mmi_asc_to_ucs2((CHAR*) g_mmi_phb_contact_p->b_day, time_string);
                mmi_ucs2cpy((CHAR*) g_mmi_phb_contact_p->bday, (CHAR*) (PU8) GetString(STR_GLOBAL_NONE));
            }
            SetInlineItemDate(
                &wgui_inline_items[2 * item_index + 1],
                (U8*) g_mmi_phb_contact_p->b_day,
                (U8*) g_mmi_phb_contact_p->b_month,
                (U8*) g_mmi_phb_contact_p->b_year,
                mmi_phb_bday_editor_callback);
            DisableInlineItemHighlight(&wgui_inline_items[2 * item_index + 1]);
            set_inline_date_boundary(MMI_PHB_BDAY_MAX_YEAR_INT, 1900, 12, 1);
            image_list[2 * item_index] = IMG_ID_PHB_BIRTHDAY;
            RegisterInlineItemChangedNotification(mmi_phb_bday_changed_callback);
            break;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
    
    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_TITLE));            
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->title,
                MMI_PHB_TITLE_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_TITLE;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_TITLE);
        #endif
            break;
            
        case MMI_PHB_FIELD_URL:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_URL));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->url,
                MMI_PHB_URL_LENGTH + 1,
                IMM_INPUT_TYPE_URL);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_URL;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_URL);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_POBOX:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_POBOX));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->pobox,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_POBOX;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_POBOX);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_EXTENSION:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_EXTENSION));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->extension,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_EXTENSION;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_EXTENSION);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_STREET:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_STREET));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->street,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_STREET;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_STREET);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_CITY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_CITY));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->city,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_CITY;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_CITY);
        #endif            
            break;

        case MMI_PHB_FIELD_ADR_STATE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_STATE));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->state,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_STATE;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_STATE);
        #endif    
            break;

        case MMI_PHB_FIELD_ADR_POSTALCODE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_POSTALCODE));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->postalcode,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_POSTALCODE;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_POSTALCODE);
        #endif            
            break;

        case MMI_PHB_FIELD_ADR_COUNTRY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_COUNTRY));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->country,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_COUNTRY;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_COUNTRY);
        #endif
            break;

        case MMI_PHB_FIELD_NOTE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NOTE));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemTextEdit(
                &wgui_inline_items[2 * item_index + 1],
                (PU8) g_mmi_phb_contact_p->note,
                MMI_PHB_NOTE_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineTextEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_op_edit_custom_function);
            image_list[2 * item_index] = IMG_ID_PHB_NOTE;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_NOTE);
        #endif
            break;
    #endif
    #if 0
    #if defined(__MMI_IMPS__)
    #if defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __USB_IN_NORMAL_MODE__
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
    #else /* defined(IMPS_WV13_ENHANCEMENT) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
/* under construction !*/
        #endif 
/* under construction !*/
    #endif /* defined(IMPS_WV13_ENHANCEMENT) */
    #endif /* defined(__MMI_IMPS__) */
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
/* under construction !*/
        #endif 
/* under construction !*/
    #endif /* defined(__MMI_VOIP__) */
	#endif

        default:
            break;
    }
}


void mmi_phb_op_edit_inline_tab_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif

    g_mmi_phb_edit_option = MMI_FALSE;

    g_mmi_phb_save_contact_p->highlight_str = mmi_phb_get_str_by_field_type(g_mmi_phb_item_list[index], g_mmi_phb_save_contact_p->storage);
    g_mmi_phb_save_contact_p->highlight_type = g_mmi_phb_item_list[index];
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_phb_entry_op_save_contact_confirm, KEY_EVENT_UP);
    
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_VIEW_LSK);
    SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);

    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_ADD_NUMBERS:
            ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);
            SetLeftSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);

            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);
            break;
        
    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        case MMI_PHB_FIELD_ADD_MORE:
            ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);
            SetLeftSoftkeyFunction(mmi_phb_entry_add_more_details_confirm, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_entry_add_more_details_confirm, KEY_EVENT_UP);
    #endif
        default:
            break;
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_edit_contact_tap_callback);
#endif
}


#else


void mmi_phb_op_fill_inline_item_for_tab(
           U8 field_index,
           U8 item_index,
           U8 storage,
           U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
#if 0	
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[2 * item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemFullWidth(&wgui_inline_items[2 * item_index]);

    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
        {
            U16 first_name_str = mmi_phb_get_first_name_str(storage);
            
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(first_name_str));
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U32 name_length = mmi_phb_get_name_length(storage);
                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;
                
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            #if defined(__PHB_0x81_SUPPORT__)
                SetInlineItemFullScreenEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    first_name_str,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->name,
                    name_length + 1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            #else /* defined(__PHB_0x81_SUPPORT__) */ 
                SetInlineItemFullScreenEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    first_name_str,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->name,
                    name_length +1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            }
            else
            {
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
                SetInlineItemFullScreenEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    first_name_str,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->name,
                    MMI_PHB_NAME_FIELD_LENGTH +1,
                    (IMM_INPUT_TYPE_SENTENCE /*| INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING */),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            }
            
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
          
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], first_name_str);
        #endif 
            break;
        }

    #ifdef __MMI_PHB_LAST_NAME_FIELD__    
        case MMI_PHB_FIELD_LAST_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_LAST_NAME));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_LAST_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->last_name,
                MMI_PHB_NAME_FIELD_LENGTH +1,
                (IMM_INPUT_TYPE_SENTENCE /*| INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING */),
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
           
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_LAST_NAME);
        #endif 
            break;
    #endif
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:       
        {
            U16 nick_name_str = STR_ID_PHB_NICK_NAME;
            
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(nick_name_str));
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U8 name_length = srv_phb_get_alpha_field_length((phb_storage_enum)storage,MMI_PHB_CONTACT_FIELD_ID_NICK);
                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;
                
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            #if defined(__PHB_0x81_SUPPORT__)
                SetInlineItemFullScreenEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    nick_name_str,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->nick_name,
                    name_length + 1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            #else /* defined(__PHB_0x81_SUPPORT__) */ 
                SetInlineItemFullScreenEdit_ext(
                    &wgui_inline_items[2 * item_index + 1],
                    nick_name_str,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->nick_name,
                    name_length +1,
                    (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_GSM_EXTENDED_HANDLING),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            }
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], nick_name_str);
        #endif 
            break;
        }
        #endif
    
        case MMI_PHB_FIELD_NUMBER:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NUMBER));
            if (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
            //#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
                || g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM
            //#endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
                )
            {
            #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            #ifdef __MMI_FTE_SUPPORT__
                if (g_mmi_phb_contact_p->number[0] == 0)
            #else
                if (IsInlineItemDefaultTextEnable() &&
                    (g_mmi_phb_contact_p->number[0] == 0))
            #endif
                {
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)GetString(STR_ID_PHB_NUMBER));
                }
                else
            #endif
                {
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)g_mmi_phb_contact_p->number);
                }
            }
            else
            {
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
                SetInlineItemFullScreenEdit(
                    &wgui_inline_items[2 * item_index + 1],
                    STR_ID_PHB_NUMBER,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->number,
                    MMI_PHB_NUMBER_LENGTH + 1,
                    IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
                SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk_for_number);
            #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
                SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_NUMBER);
            #endif 
            }

        #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
            if ((g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM) &&
                ((g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_NUMBER) ||
                (g_mmi_phb_contact_p->default_number == 0xff)))
            {
                if (g_mmi_phb_contact_p->number[0])
                {
                    SetInlineIconStyle(&wgui_inline_items[2 * item_index + 1], (PU8)GetImage(IMG_ID_PHB_DEFAULT_NUM),TRUE);
                }
                else if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_NUMBER)
                {
                    g_mmi_phb_contact_p->default_number = 0xfe;
                }
            }
        #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (!g_mmi_phb_contact_p->number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                mmi_phb_speed_dial_pre_del_number(g_mmi_phb_save_contact_p->store_index, SRV_PHB_ENTRY_FIELD_NUMBER);
            }
        #endif
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_MOBILE_NUMBER;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;

    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        case MMI_PHB_FIELD_ADD_MORE:
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADD_MORE_DETAILS));
            image_list[2 * item_index] = IMG_MORE_DETAILS;
            break;
    #endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */

        case MMI_PHB_FIELD_ADD_NUMBERS:
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADD_MORE_NUMBER));
            image_list[2 * item_index] = IMG_ID_PHB_NEW_NUMBER;
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
        {
            U16 str_id = 0;
            U8 index = field_index - MMI_PHB_FIELD_OPT_NUM_1;
        #ifdef __MMI_PHB_USIM_SUPPORT__
            
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                img_id = IMG_MOBILE_NUMBER;
			    #else
			    img_id = 0;
			    #endif
                if(g_mmi_phb_contact_p->opt_num[index].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_MOBILE_NUMBER));
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                                g_mmi_phb_contact_p->opt_num[index].type, 
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                (phb_storage_enum)storage);
                    
                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }

                    SetInlineItemCaption(
                        &wgui_inline_items[2 * item_index], 
                        (U8*)label);
                }
            }
            else
        #endif
            {
                img_id = mmi_phb_get_img_by_number_type(g_mmi_phb_contact_p->opt_num[index].type);
                str_id = mmi_phb_get_str_by_number_type(g_mmi_phb_contact_p->opt_num[index].type);
                SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(str_id));
            }
            if (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
            #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
                || MMI_TRUE
            #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
                )
            {
            #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            #ifdef __MMI_FTE_SUPPORT__
                if (g_mmi_phb_contact_p->opt_num[index].number[0] == 0)
            #else
                if (IsInlineItemDefaultTextEnable() &&
                    (g_mmi_phb_contact_p->opt_num[index].number[0] == 0))
            #endif
                {
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)GetString(str_id));
                }
                else
            #endif
                {
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)g_mmi_phb_contact_p->opt_num[index].number);
                }
            }
            else
            {
                SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
                SetInlineItemFullScreenEdit(
                    &wgui_inline_items[2 * item_index + 1],
                    str_id,
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8)g_mmi_phb_contact_p->opt_num[index].number,
                    MMI_PHB_NUMBER_LENGTH + 1,
                    IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
                SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk_for_number);
            #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            #ifdef __MMI_PHB_USIM_SUPPORT__
                if(mmi_phb_check_storage(MMI_FALSE, storage))
                {
                    if(g_mmi_phb_contact_p->opt_num[index].type == MMI_PHB_NUM_TYPE_MOBILE)
                    {
                        SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_MOBILE_NUMBER);
                    }
                    else
                    {
                        WCHAR *label = srv_phb_get_field_type_label(
                                    g_mmi_phb_contact_p->opt_num[index].type, 
                                    MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                    (phb_storage_enum)storage);

                        if ((label == NULL) || (label[0] == '\0'))
                        {
                            label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                        }

                        SetInlineItemTextEditDefaultItemNameIfEmpty_with_string(
                            &wgui_inline_items[2 * item_index + 1],
                            (U8*)label);
                    }
                }
                else
            #endif
                {
                    SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], str_id);
                }
            #endif 
            }
        #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)   
            if (g_mmi_phb_contact_p->default_number == mmi_phb_get_field_mask_by_field_type(field_index))
            {
                if (g_mmi_phb_contact_p->opt_num[index].number[0])
                {
                    SetInlineIconStyle(&wgui_inline_items[2 * item_index + 1], (PU8)GetImage(IMG_ID_PHB_DEFAULT_NUM),TRUE);
                }
                else
                {
                    g_mmi_phb_contact_p->default_number = 0xfe;
                }
            }
        #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
        #ifdef __MMI_PHB_SPEED_DIAL__
            if (!g_mmi_phb_contact_p->opt_num[index].number[0]
                && (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
                ))
            {
                mmi_phb_speed_dial_pre_del_number(g_mmi_phb_save_contact_p->store_index, mmi_phb_get_field_mask_by_field_type(field_index));
            }
        #endif
            image_list[2 * item_index] = img_id;
            break;
        }

        case MMI_PHB_FIELD_COMPANY_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_COMPNAY_NAME));

            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[2 * item_index + 1],
                STR_COMPNAY_NAME,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->companyName,
                MMI_PHB_COMPANY_LENGTH+ 1,
                IMM_INPUT_TYPE_SENTENCE);
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
            image_list[2 * item_index] = IMG_COMPANY_NAME;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_COMPNAY_NAME);
        #endif 
            break;

        case MMI_PHB_FIELD_EMAIL:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(mmi_phb_get_email_address_id(1,storage)));

            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
        #ifdef __MMI_PHB_USIM_SUPPORT__
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U8 name_length = srv_phb_get_alpha_field_length((phb_storage_enum)storage,MMI_PHB_CONTACT_FIELD_ID_EMAIL);
                name_length = (name_length > MMI_PHB_EMAIL_LENGTH) ? MMI_PHB_EMAIL_LENGTH : name_length;
                SetInlineItemFullScreenEdit_ext2(
                    &wgui_inline_items[2 * item_index + 1],
                    mmi_phb_get_email_address_id(1,storage),
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->emailAddress,
                    name_length + 1,
                    (IMM_INPUT_TYPE_EMAIL),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);

            }
            else
        #endif
            {
                SetInlineItemFullScreenEdit_ext2(
                    &wgui_inline_items[2 * item_index + 1],
                    mmi_phb_get_email_address_id(1,storage),
                    IMG_SCR_PBOOK_CAPTION,
                    (PU8) g_mmi_phb_contact_p->emailAddress,
                    MMI_PHB_EMAIL_LENGTH + 1,
                    (IMM_INPUT_TYPE_EMAIL),
                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                    NULL);
            }
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk_for_email);
            image_list[2 * item_index] = IMG_EMAIL_ADDRESS;
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], mmi_phb_get_email_address_id(1,storage));
        #endif 

            break;
        #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_EMAIL2_ADRESS));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext2(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_EMAIL2_ADRESS,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->emailAddress2,
                MMI_PHB_EMAIL_LENGTH + 1,
                (IMM_INPUT_TYPE_EMAIL),
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                NULL);
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk_for_email);
        #if 0
        #ifdef __OP01__
/* under construction !*/
        #else
/* under construction !*/
        #endif
        #else
            image_list[2 * item_index] = IMG_EMAIL_ADDRESS;
        #endif
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_EMAIL2_ADRESS);
        #endif

            break;
        #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */            
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ /* END #ifdef __MMI_PHB_OPTIONAL_FIELD__ */

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_CALLER_PIC));

            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], g_mmi_phb_resource.image_name_list[g_mmi_phb_res_p->selected_pic_index]);
            image_list[2 * item_index] = IMG_PICTURE;
            break;
            
        case MMI_PHB_FIELD_RING:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_CALLER_RING));

            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_res_p->selected_ring_index]);
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_RING_TONE;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;

    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ASSOCIATE_VIDEO));

            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], g_mmi_phb_resource.video_name_list[g_mmi_phb_res_p->selected_video_index]);
            image_list[2 * item_index] = IMG_ID_PHB_ASSOCIATE_VIDEO;
            break;
    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    #endif /* __MMI_PHB_CALLER_RES__ */
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_BIRTHDAY));
            mmi_phb_bday_format(
                g_mmi_phb_contact_p->bday,
                g_mmi_phb_contact_p->b_day,
                g_mmi_phb_contact_p->b_month,
                g_mmi_phb_contact_p->b_year);

            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (U8*)g_mmi_phb_contact_p->bday);
            image_list[2 * item_index] = IMG_ID_PHB_BIRTHDAY;
            break;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
    
    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_TITLE));            
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_TITLE,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->title,
                MMI_PHB_TITLE_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            image_list[2 * item_index] = IMG_ID_PHB_TITLE;
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_TITLE);
        #endif
            break;
            
        case MMI_PHB_FIELD_URL:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_URL));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_URL,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->url,
                MMI_PHB_URL_LENGTH + 1,
                IMM_INPUT_TYPE_URL);
            image_list[2 * item_index] = IMG_ID_PHB_URL;
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_URL);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_POBOX:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_POBOX));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_POBOX,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->pobox,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_POBOX;
        
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_POBOX);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_EXTENSION:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_EXTENSION));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_EXTENSION,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->extension,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_EXTENSION;
        
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_EXTENSION);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_STREET:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_STREET));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_STREET,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->street,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_STREET;

            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_STREET);
        #endif
            break;

        case MMI_PHB_FIELD_ADR_CITY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_CITY));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_CITY,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->city,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_CITY;
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_CITY);
        #endif            
            break;

        case MMI_PHB_FIELD_ADR_STATE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_STATE));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_STATE,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->state,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_STATE;
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_STATE);
        #endif    
            break;

        case MMI_PHB_FIELD_ADR_POSTALCODE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_POSTALCODE));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_POSTALCODE,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->postalcode,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_ASCII_CHAR,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_POSTALCODE;
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_POSTALCODE);
        #endif            
            break;

        case MMI_PHB_FIELD_ADR_COUNTRY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_COUNTRY));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit_ext(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_ADR_COUNTRY,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->country,
                MMI_PHB_ADDRESS_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE,
                INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
            image_list[2 * item_index] = IMG_ID_PHB_ADR_COUNTRY;
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_ADR_COUNTRY);
        #endif
            break;

        case MMI_PHB_FIELD_NOTE:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NOTE));
            SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], KEY_LSK, KEY_EVENT_UP);
            SetInlineItemFullScreenEdit(
                &wgui_inline_items[2 * item_index + 1],
                STR_ID_PHB_NOTE,
                IMG_SCR_PBOOK_CAPTION,
                (PU8) g_mmi_phb_contact_p->note,
                MMI_PHB_NOTE_LENGTH + 1,
                IMM_INPUT_TYPE_SENTENCE);
            image_list[2 * item_index] = IMG_ID_PHB_NOTE;
            
            SetInlineFullScreenEditCustomFunction(&wgui_inline_items[2 * item_index + 1], mmi_phb_set_full_scr_lsk);
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
            SetInlineItemTextEditDefaultItemNameIfEmpty(&wgui_inline_items[2 * item_index + 1], STR_ID_PHB_NOTE);
        #endif
            break;
    #endif
    #if 0
    #if defined(__MMI_IMPS__)
    #if defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __USB_IN_NORMAL_MODE__
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
    #else /* defined(IMPS_WV13_ENHANCEMENT) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
/* under construction !*/
        #endif 
/* under construction !*/
    #endif /* defined(IMPS_WV13_ENHANCEMENT) */
    #endif /* defined(__MMI_IMPS__) */
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
/* under construction !*/
        #endif 
/* under construction !*/
    #endif /* defined(__MMI_VOIP__) */
	#endif

        default:
            break;
    }
}


void mmi_phb_op_edit_inline_tab_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif

    g_mmi_phb_edit_option = MMI_FALSE;

    g_mmi_phb_save_contact_p->highlight_str = mmi_phb_get_str_by_field_type(g_mmi_phb_item_list[index], g_mmi_phb_save_contact_p->storage);
    g_mmi_phb_save_contact_p->highlight_type = g_mmi_phb_item_list[index];

#ifndef __MMI_WGUI_DISABLE_CSK__    
#ifndef __MMI_MAINLCD_96X64__

    ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif	

    switch (g_mmi_phb_save_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NAME:
            if (g_mmi_phb_contact_p->name[0] != 0)
            {
                SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
				DisableCategory57ScreenRskBack();
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);
                g_mmi_phb_edit_option = MMI_TRUE;
            }
            else
            {
               // SetInlineItemActivation(&wgui_inline_items[index], KEY_LSK, KEY_EVENT_UP);
				SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
                mmi_phb_edit_name_highlight_hdlr(g_mmi_phb_contact_p->name);
            }
            break;
    
        case MMI_PHB_FIELD_NUMBER:
            if (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
            //#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
                || g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM
            //#endif   //defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)  
                )
            {
                SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
                mmi_phb_edit_number_highlight_hdlr(g_mmi_phb_contact_p->number);
            }
            break;

	#ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            if (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
            //#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
                || MMI_TRUE
            //#endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
                )
            {
                mmi_phb_edit_number_highlight_hdlr(g_mmi_phb_contact_p->opt_num[0].number);
            }
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            if (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
            //#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
                || MMI_TRUE
            //#endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
                )
            {
                mmi_phb_edit_number_highlight_hdlr(g_mmi_phb_contact_p->opt_num[1].number);
            }
            break;
                
        case MMI_PHB_FIELD_OPT_NUM_3:
            if (srv_sim_ctrl_is_available(MMI_SIM1)
            #if (MMI_MAX_SIM_NUM >= 2)
                || srv_sim_ctrl_is_available(MMI_SIM2)
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                || srv_sim_ctrl_is_available(MMI_SIM3)
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                || srv_sim_ctrl_is_available(MMI_SIM4)
            #endif
            //#if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
                || MMI_TRUE
            //#endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */
                )
            {
                mmi_phb_edit_number_highlight_hdlr(g_mmi_phb_contact_p->opt_num[2].number);
            }
            break;    
	#endif

        case MMI_PHB_FIELD_ADD_NUMBERS:
            ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);
            SetLeftSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);

            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_entry_inline_edit_num_for_tab, KEY_EVENT_UP);
            break;

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
        {
		#if defined(__MMI_PHB_UI_IN_TABS__)&&!defined(__MMI_FTE_SUPPORT__)

			  if (g_mmi_phb_res_p->selected_pic_index == 0)
	            {
	                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);            
	                SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);

	                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	                SetCenterSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);
	            }
            	else
			
			#else
            if (g_mmi_phb_res_p->selected_pic_index == 0)
            {
                ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);            
                SetLeftSoftkeyFunction(mmi_phb_entry_choose_caller_pic, KEY_EVENT_UP);

                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_phb_entry_choose_caller_pic, KEY_EVENT_UP);
            }
            else
			#endif
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);            
                SetLeftSoftkeyFunction(mmi_phb_entry_image_option, KEY_EVENT_UP);
                
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_phb_entry_image_view, KEY_EVENT_UP);
                g_mmi_phb_edit_option = MMI_TRUE;
            }
            break;
        }
            
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
        {
            if (g_mmi_phb_res_p->selected_video_index == 0)
            {
                ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);            
                SetLeftSoftkeyFunction(mmi_phb_entry_choose_caller_video, KEY_EVENT_UP);

                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_phb_entry_choose_caller_video, KEY_EVENT_UP);
            }
            else
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);            
                SetLeftSoftkeyFunction(mmi_phb_video_pre_entry_file_option, KEY_EVENT_UP);
                #ifndef __MMI_PHB_SLIM__
                ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_PLAY);
				#endif
                SetCenterSoftkeyFunction(mmi_phb_entry_video_view, KEY_EVENT_UP);
                g_mmi_phb_edit_option = MMI_TRUE;
            }
            break;
        }
    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */

        case MMI_PHB_FIELD_RING:
        {
			#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif
			DisableCategory57ScreenRskBack();
			ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
			SetLeftSoftkeyFunction(mmi_phb_entry_op_edit_option, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
	#ifndef __MMI_MAINLCD_96X64__	
			ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
	#else
			ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	#endif
			SetCenterSoftkeyFunction(mmi_phb_entry_choose_caller_ringtone, KEY_EVENT_UP);
#endif
            break;
        }
   #endif /* __MMI_PHB_CALLER_RES__ */

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)           
        case MMI_PHB_FIELD_BIRTHDAY:
        {
            ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);        
            SetLeftSoftkeyFunction(entry_inline_birthday_full_screen, KEY_EVENT_UP);
			
#ifndef __MMI_WGUI_DISABLE_CSK__            
#ifndef __MMI_MAINLCD_96X64__
            ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif
            SetCenterSoftkeyFunction(entry_inline_birthday_full_screen, KEY_EVENT_UP);
            break;
        }
    #endif

    #if 0
    #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __USB_IN_NORMAL_MODE__
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
    #endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */
	#endif
    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
        case MMI_PHB_FIELD_ADD_MORE:
            ChangeLeftSoftkey(STR_GLOBAL_ADD, 0);
            SetLeftSoftkeyFunction(mmi_phb_entry_add_more_details_confirm, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_phb_entry_add_more_details_confirm, KEY_EVENT_UP);
    #endif
        default:
            break;
    }

   // SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
   // SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_exit_edit_contact_entry_inline_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->done_flag == 0)
    {
        g_mmi_phb_save_contact_p->done_flag = GetInlineListMenuChanged();
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_entry_edit_contact_entry_inline_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8              *guiBuffer;
    U8              *inputBuffer;
    U16             DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8              item_index = 0, single_line = 0;
    U8              i = 0;
    U8              field_type;
    MMI_BOOL        flag = MMI_FALSE;
    S32             highlight_item = 0;
    U8 storage = g_mmi_phb_save_contact_p->storage;
    U8 sel_index = 0xff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_0,
            mmi_phb_exit_edit_contact_entry_inline_tab_0,
            mmi_phb_entry_edit_contact_entry_inline_tab_0,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ADD_NEW_ENTRY,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_0,
            mmi_phb_exit_edit_contact_entry_inline_tab_0,
            mmi_phb_entry_edit_contact_entry_inline_tab_0,
            MMI_FRM_TAB_PAGE))
    #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_op_edit_inline_tab_highlight_hdlr);

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));

    while ((field_type = mmi_phb_edit_get_field_type(0, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_save_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_inline_item_for_tab(
                    field_type,
                    item_index++,
                    g_mmi_phb_save_contact_p->storage,
                    DetailPbNameImageList);

            /**
             * caculate highlight index
             */
            if (!flag && (g_mmi_phb_save_contact_p->add_detail == MMI_TRUE || g_mmi_phb_save_contact_p->first_highlight_type != 0xff))
            {
                if (field_type == g_mmi_phb_save_contact_p->highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (mmi_phb_check_storage(MMI_TRUE, storage) && ((g_mmi_phb_save_contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM) != SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM))
    {
            g_mmi_phb_item_list[2 * item_index] = MMI_PHB_FIELD_ADD_NUMBERS;
            mmi_phb_op_fill_inline_item_for_tab(
                MMI_PHB_FIELD_ADD_NUMBERS,
                item_index++,
                g_mmi_phb_save_contact_p->storage,
                DetailPbNameImageList);

            single_line = 1;
    }
#ifdef __MMI_PHB_USIM_SUPPORT__  
    else
    {
        for(i = MMI_PHB_USIM_FIELD_ANR1 ; i<= MMI_PHB_USIM_FIELD_ANR3; i++)
        {
            if(mmi_phb_check_usim_detail(g_mmi_phb_save_contact_p->storage,phb_edit_usim_field_optional[i]))
            {
                g_mmi_phb_item_list[2 * item_index] = MMI_PHB_FIELD_ADD_NUMBERS;
                mmi_phb_op_fill_inline_item_for_tab(
                    MMI_PHB_FIELD_ADD_NUMBERS,
                    item_index++,
                    g_mmi_phb_save_contact_p->storage,
                    DetailPbNameImageList);

                single_line = 1;
                break;
            }
        }
    }
#endif
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
    if (g_mmi_phb_save_contact_p->storage == PHB_STORAGE_SIM
        || g_mmi_phb_save_contact_p->storage == PHB_STORAGE_SIM2
        || g_mmi_phb_save_contact_p->storage == PHB_STORAGE_SIM3
        || g_mmi_phb_save_contact_p->storage == PHB_STORAGE_SIM4)
    {
        g_mmi_phb_item_list[2 * item_index] = MMI_PHB_FIELD_ADD_MORE;
        mmi_phb_op_fill_inline_item_for_tab(
            MMI_PHB_FIELD_ADD_MORE,
            item_index++,
            g_mmi_phb_save_contact_p->storage,
            DetailPbNameImageList);
        
        single_line = 1;
    }
#endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
   // inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
   if(!guiBuffer)
   {
   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_0);
   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_save_contact_p->add_detail = MMI_FALSE;
        g_mmi_phb_save_contact_p->first_highlight_type = 0xff;
    }
/*
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index - single_line, inputBuffer);
    }
*/
    if (g_mmi_phb_save_contact_p->done_flag)
    {
        SetInlineDoneFlag(guiBuffer);
        wgui_inline_list_menu_changed = 1;
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    DisableCategory57ScreenDone();
#endif
#if defined(__MMI_INLINE_SLIM__)
	DisableCategory57ScreenDone();
    EnableCategory57ScreenRskBack();
    wgui_inline_set_parent_group(g_mmi_phb_save_contact_p->sg_id);
#endif /* __MMI_INLINE_SLIM__ */
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

	 sel_index = cui_tab_get_select_index(SCR_ADD_NEW_ENTRY);
    ShowCategory657Screen(
        mmi_phb_inline_tab_get_title_bar_string(),
        mmi_phb_op_get_title_bar_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index - single_line,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        //MMI_PHB_INLINE_TAB_0,
        sel_index,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_cancel, mmi_phb_entry_op_save_contact_cancel);
#else
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_confirm, mmi_phb_entry_op_save_contact_cancel);
#endif

SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_exit_edit_contact_entry_inline_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif

    if (g_mmi_phb_save_contact_p->done_flag == 0)
    {
        g_mmi_phb_save_contact_p->done_flag = GetInlineListMenuChanged();
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_entry_edit_contact_entry_inline_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0, field_type;
    U8 storage = g_mmi_phb_save_contact_p->storage;
    MMI_BOOL        flag = MMI_FALSE;
    S32             highlight_item = 0;
	U8 sel_index = 0xff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_1,
            mmi_phb_exit_edit_contact_entry_inline_tab_1,
            mmi_phb_entry_edit_contact_entry_inline_tab_1,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ADD_NEW_ENTRY,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_1,
            mmi_phb_exit_edit_contact_entry_inline_tab_1,
            mmi_phb_entry_edit_contact_entry_inline_tab_1,
            MMI_FRM_TAB_PAGE))
    #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_op_edit_inline_tab_highlight_hdlr);

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));

    while ((field_type = mmi_phb_edit_get_field_type(1, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_save_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_inline_item_for_tab(
                    field_type,
                    item_index++,
                    g_mmi_phb_save_contact_p->storage,
                    DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag)
            {
                if (field_type == g_mmi_phb_save_contact_p->highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
   if(!guiBuffer)
    {
   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_1);
   	}
   if(!inputBuffer)
    {
   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_1);
   	}
   #endif

    if (mmi_phb_check_storage(MMI_TRUE, storage))
    {
    #ifdef __MMI_PHB_CALLER_RES__
        mmi_phb_contact_res_config();
    #endif
    }

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_save_contact_p->first_highlight_type = 0xff;
    }
    
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

#ifdef __MMI_PHB_CALLER_RES__
    if (g_mmi_phb_save_contact_p->done_flag || g_mmi_phb_res_p->done)
#else
    if (g_mmi_phb_save_contact_p->done_flag)
#endif
    {
        SetInlineDoneFlag(guiBuffer);
        wgui_inline_list_menu_changed = 1;
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    DisableCategory57ScreenDone();
#endif
#if defined(__MMI_INLINE_SLIM__)
	DisableCategory57ScreenDone();
    EnableCategory57ScreenRskBack();
    wgui_inline_set_parent_group(g_mmi_phb_save_contact_p->sg_id);
#endif /* __MMI_INLINE_SLIM__ */

	sel_index = cui_tab_get_select_index(SCR_ADD_NEW_ENTRY);
    ShowCategory657Screen(
        mmi_phb_inline_tab_get_title_bar_string(),
        mmi_phb_op_get_title_bar_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        //MMI_PHB_INLINE_TAB_1,
        sel_index,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_cancel, mmi_phb_entry_op_save_contact_cancel);
#else
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_confirm, mmi_phb_entry_op_save_contact_cancel);
#endif

SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_exit_edit_contact_entry_inline_tab_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mmi_phb_save_contact_p->done_flag == 0)
    {
        g_mmi_phb_save_contact_p->done_flag = GetInlineListMenuChanged();
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_entry_edit_contact_entry_inline_tab_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U8 tab_index;/*for sim tab  */
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0, field_type;
    U8 storage = g_mmi_phb_save_contact_p->storage;
    MMI_BOOL        flag = MMI_FALSE;
    S32             highlight_item = 0;
	U8 sel_index = 0xff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2,
            mmi_phb_exit_edit_contact_entry_inline_tab_2,
            mmi_phb_entry_edit_contact_entry_inline_tab_2,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ADD_NEW_ENTRY,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2,
            mmi_phb_exit_edit_contact_entry_inline_tab_2,
            mmi_phb_entry_edit_contact_entry_inline_tab_2,
            MMI_FRM_TAB_PAGE))
    #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_op_edit_inline_tab_highlight_hdlr);

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (mmi_phb_check_storage(MMI_FALSE, storage))
    {
        tab_index = 1;
    }
    else
#endif
    {
        tab_index = 2;
    }

    while ((field_type = mmi_phb_edit_get_field_type(tab_index, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_save_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_inline_item_for_tab(
                    field_type,
                    item_index++,
                    g_mmi_phb_save_contact_p->storage,
                    DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_save_contact_p->highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_save_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

    if (g_mmi_phb_save_contact_p->done_flag)
    {
        SetInlineDoneFlag(guiBuffer);
        wgui_inline_list_menu_changed = 1;
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    DisableCategory57ScreenDone();
#endif
#if defined(__MMI_INLINE_SLIM__)
	DisableCategory57ScreenDone();
    EnableCategory57ScreenRskBack();
    wgui_inline_set_parent_group(g_mmi_phb_save_contact_p->sg_id);
#endif /* __MMI_INLINE_SLIM__ */

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    if (phb_edit_default_field_tab[1][0] == MMI_PHB_FIELD_TOTAL)
    {
        tab_index = 1;
    }

	sel_index = cui_tab_get_select_index(SCR_ADD_NEW_ENTRY);
    ShowCategory657Screen(
        mmi_phb_inline_tab_get_title_bar_string(),
        mmi_phb_op_get_title_bar_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        //tab_index,
        sel_index,
        guiBuffer);

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_cancel, mmi_phb_entry_op_save_contact_cancel);
#else
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_confirm, mmi_phb_entry_op_save_contact_cancel);
#endif
SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_exit_edit_contact_entry_inline_tab_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->done_flag == 0)
    {
        g_mmi_phb_save_contact_p->done_flag = GetInlineListMenuChanged();
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_entry_edit_contact_entry_inline_tab_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0, field_type;
    U8 storage = g_mmi_phb_save_contact_p->storage;
    MMI_BOOL        flag = MMI_FALSE;
    S32             highlight_item = 0;
    S32 tab_index = MMI_PHB_INLINE_TAB_3;
	U8 sel_index = MMI_PHB_INLINE_TAB_3;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_3,
            mmi_phb_exit_edit_contact_entry_inline_tab_3,
            mmi_phb_entry_edit_contact_entry_inline_tab_3,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ADD_NEW_ENTRY,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_3,
            mmi_phb_exit_edit_contact_entry_inline_tab_3,
            mmi_phb_entry_edit_contact_entry_inline_tab_3,
            MMI_FRM_TAB_PAGE))
    #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_op_edit_inline_tab_highlight_hdlr);

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));

    while ((field_type = mmi_phb_edit_get_field_type(3, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_save_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_inline_item_for_tab(
                    field_type,
                    item_index++,
                    g_mmi_phb_save_contact_p->storage,
                    DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_save_contact_p->highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_3);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_3);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_save_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

    if (g_mmi_phb_save_contact_p->done_flag)
    {
        SetInlineDoneFlag(guiBuffer);
        wgui_inline_list_menu_changed = 1;
    }

    for (i = 0; i < MMI_PHB_INLINE_TAB_3; i++)
    {
        if (phb_edit_default_field_tab[i][0] == MMI_PHB_FIELD_TOTAL)
        {
            tab_index--;
        }
    }

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    DisableCategory57ScreenDone();
#endif
#if defined(__MMI_INLINE_SLIM__)
	DisableCategory57ScreenDone();
    EnableCategory57ScreenRskBack();
    wgui_inline_set_parent_group(g_mmi_phb_save_contact_p->sg_id);
#endif /* __MMI_INLINE_SLIM__ */

	sel_index = cui_tab_get_select_index(SCR_ADD_NEW_ENTRY);
    ShowCategory657Screen(
        mmi_phb_inline_tab_get_title_bar_string(),
        mmi_phb_op_get_title_bar_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        //tab_index,
        sel_index,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_cancel, mmi_phb_entry_op_save_contact_cancel);
#else
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_confirm, mmi_phb_entry_op_save_contact_cancel);
#endif
SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);

}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_exit_edit_contact_entry_inline_tab_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_save_contact_p->done_flag == 0)
    {
        g_mmi_phb_save_contact_p->done_flag = GetInlineListMenuChanged();
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_entry_edit_contact_entry_inline_tab_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0, field_type;
    U8 storage = g_mmi_phb_save_contact_p->storage;
    MMI_BOOL        flag = MMI_FALSE;
    S32             highlight_item = 0;
    S32 tab_index = MMI_PHB_INLINE_TAB_4;
	U8 sel_index = MMI_PHB_INLINE_TAB_4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_4,
            mmi_phb_exit_edit_contact_entry_inline_tab_4,
            mmi_phb_entry_edit_contact_entry_inline_tab_4,
            MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            g_mmi_phb_save_contact_p->sg_id,
            SCR_ADD_NEW_ENTRY,
            SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_4,
            mmi_phb_exit_edit_contact_entry_inline_tab_4,
            mmi_phb_entry_edit_contact_entry_inline_tab_4,
            MMI_FRM_TAB_PAGE))
    #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_op_edit_inline_tab_highlight_hdlr);

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));

    while ((field_type = mmi_phb_edit_get_field_type(4, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_save_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_inline_item_for_tab(
                    field_type,
                    item_index++,
                    g_mmi_phb_save_contact_p->storage,
                    DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_save_contact_p->highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_save_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_4);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ADD_NEW_ENTRY,SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_4);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_save_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

    if (g_mmi_phb_save_contact_p->done_flag)
    {
        SetInlineDoneFlag(guiBuffer);
        wgui_inline_list_menu_changed = 1;
    }

    for (i = 0; i < MMI_PHB_INLINE_TAB_4; i++)
    {
        if (phb_edit_default_field_tab[i][0] == MMI_PHB_FIELD_TOTAL)
        {
            tab_index--;
        }
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    DisableCategory57ScreenDone();
#endif
#if defined(__MMI_INLINE_SLIM__)
	DisableCategory57ScreenDone();
    EnableCategory57ScreenRskBack();
    wgui_inline_set_parent_group(g_mmi_phb_save_contact_p->sg_id);
#endif /* __MMI_INLINE_SLIM__ */

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

	sel_index = cui_tab_get_select_index(SCR_ADD_NEW_ENTRY);
    ShowCategory657Screen(
        mmi_phb_inline_tab_get_title_bar_string(),
        mmi_phb_op_get_title_bar_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        //tab_index,
        sel_index,
        guiBuffer);

    SetCenterSoftkeyFunction(get_left_softkey_function(KEY_EVENT_UP), KEY_EVENT_UP);

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_cancel, mmi_phb_entry_op_save_contact_cancel);
#else
    SetCategory57RightSoftkeyFunctions(mmi_phb_entry_op_save_contact_confirm, mmi_phb_entry_op_save_contact_cancel);
#endif
SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_add_entry
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_add_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_exit_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_add_entry
 * DESCRIPTION
 *  Draws the new entry screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct tab_pages_info_array[5];
    U8 tab_id = 0, sel_index = 0xff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_save_contact_prepare_data(g_mmi_phb_save_contact_p->contact, g_mmi_phb_save_contact_p->storage);

    tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_0;
    tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_edit_contact_entry_inline_tab_0;
    tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_0);
    tab_pages_info_array[tab_id++].tab_string = NULL;   

    if (mmi_phb_check_storage(MMI_TRUE, g_mmi_phb_save_contact_p->storage))
    {
        g_mmi_phb_save_contact_p->field_mask |= SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;
    }
    else
    {
    #ifdef __MMI_PHB_USIM_SUPPORT__         
        g_mmi_phb_save_contact_p->field_mask |= SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;
    
        if(mmi_phb_check_usim_detail_ex((phb_storage_enum)g_mmi_phb_save_contact_p->storage,0,PHB_SNE))
        {
            g_mmi_phb_save_contact_p->field_mask |= SRV_PHB_ENTRY_FIELD_NICK;
        }
        
    #else
        g_mmi_phb_save_contact_p->field_mask = SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;
    #endif
    }
    
    if (mmi_phb_check_storage(MMI_TRUE, g_mmi_phb_save_contact_p->storage))
    {   
        U8 index, temp_tab_id = tab_id;
        
        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }
            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_1;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_edit_contact_entry_inline_tab_1;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_1);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;
        
        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }
            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_edit_contact_entry_inline_tab_2;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_2);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;
        
        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }
            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_3;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_edit_contact_entry_inline_tab_3;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_3);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;
        
        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }
            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_4;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_edit_contact_entry_inline_tab_4;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_4);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;

    #if defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
        g_mmi_phb_save_contact_p->field_mask &= ~SRV_PHB_ENTRY_FIELD_PIC;
    #endif
    }
#ifdef __MMI_PHB_USIM_SUPPORT__     
    else
    {
        U8 index;
        MMI_BOOL flag;
        if (mmi_phb_usim_edit_get_total_field(tab_id))
        {
            index = 0;
            flag = MMI_FALSE;
            while (phb_usim_edit_total_field_tab[tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                if(mmi_phb_check_usim_detail_ex((phb_storage_enum)g_mmi_phb_save_contact_p->storage,index,PHB_EMAIL))
                {
                    g_mmi_phb_save_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_usim_edit_total_field_tab[tab_id][index++]);
                    flag = MMI_TRUE;
                }

                index++;
            }
            if(flag)
            {
                tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2;
                tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_edit_contact_entry_inline_tab_2;
                tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_2);
                tab_pages_info_array[tab_id++].tab_string = NULL;
            }
        }
    }
#endif

    if (g_mmi_phb_save_contact_p->first_highlight_type != 0xff)
    {
    #ifdef __MMI_PHB_USIM_SUPPORT__
        if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
        {
            sel_index = mmi_phb_usim_edit_get_page_index(g_mmi_phb_save_contact_p->first_highlight_type);
        }
        else
    #endif
        {
            sel_index = mmi_phb_edit_get_page_index(g_mmi_phb_save_contact_p->first_highlight_type);
        }
        g_mmi_phb_save_contact_p->highlight_type = g_mmi_phb_save_contact_p->first_highlight_type;
    }
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__

    if (sel_index >= tab_id)
    {
        sel_index = cui_tab_get_select_index(SCR_ENTRY_VIEW);
    }

	cui_tab_create(
		g_mmi_phb_save_contact_p->sg_id,
		SCR_ADD_NEW_ENTRY,
		tab_pages_info_array,
		tab_id,
		sel_index,
		NULL);

#else
    if (sel_index >= tab_id)
    {
        sel_index = mmi_frm_scrn_tab_get_active_page_index();
    }

    mmi_frm_scrn_tab_enter(
        g_mmi_phb_save_contact_p->sg_id,
        SCR_ADD_NEW_ENTRY,
        mmi_phb_exit_op_add_entry,
        mmi_phb_entry_op_add_entry,
        tab_pages_info_array,
        tab_id,
        sel_index);
        
    mmi_frm_scrn_set_leave_proc(
        g_mmi_phb_save_contact_p->sg_id,
        SCR_ADD_NEW_ENTRY,
        mmi_phb_editor_set_scrn_proc);
#endif
}

#else /* __MMI_PHB_UI_IN_TABS__ */


typedef enum
{
    MMI_PHB_INLINE_FIELD_NAME = CUI_INLINE_ITEM_ID_BASE + MMI_PHB_FIELD_NAME,
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    MMI_PHB_INLINE_FIELD_LAST_NAME,
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
    MMI_PHB_INLINE_FIELD_NICK_NAME,
#endif
    MMI_PHB_INLINE_FIELD_NUMBER,
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    MMI_PHB_INLINE_FIELD_MOBILE_NUMBER,
    MMI_PHB_INLINE_FIELD_HOME_NUMBER,
    MMI_PHB_INLINE_FIELD_OFFCIE_NUMBER,
    MMI_PHB_INLINE_FIELD_FAX_NUMBER,
    MMI_PHB_INLINE_FIELD_OPT_NUM_1,
    MMI_PHB_INLINE_FIELD_OPT_NUM_2,
    MMI_PHB_INLINE_FIELD_OPT_NUM_3,
    MMI_PHB_INLINE_FIELD_COMPANY_NAME,
    MMI_PHB_INLINE_FIELD_EMAIL,
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    MMI_PHB_INLINE_FIELD_EMAIL2,
#endif
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    MMI_PHB_INLINE_FIELD_BIRTHDAY,
#endif 
    MMI_PHB_INLINE_FIELD_PIC,
    MMI_PHB_INLINE_FIELD_RING,
#if defined(__MMI_PHB_CALLER_VIDEO__)
    MMI_PHB_INLINE_FIELD_VIDEO,
#endif 
    MMI_PHB_INLINE_FIELD_GROUP,
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#endif
#if defined(__MMI_PHB_POC_FIELD__)
    MMI_PHB_INLINE_FIELD_POC,
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
#endif
#endif
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    MMI_PHB_INLINE_FIELD_DEFAULT,
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
    MMI_PHB_INLINE_FIELD_TITLE,
    MMI_PHB_INLINE_FIELD_URL,
    MMI_PHB_INLINE_FIELD_ADDRESS,
    MMI_PHB_INLINE_FIELD_ADR_POBOX,
    MMI_PHB_INLINE_FIELD_ADR_EXTENSION,
    MMI_PHB_INLINE_FIELD_ADR_STREET,
    MMI_PHB_INLINE_FIELD_ADR_CITY,
    MMI_PHB_INLINE_FIELD_ADR_STATE,
    MMI_PHB_INLINE_FIELD_ADR_POSTALCODE,
    MMI_PHB_INLINE_FIELD_ADR_COUNTRY,
    MMI_PHB_INLINE_FIELD_NOTE,
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
    MMI_PHB_INLINE_FIELD_TOTAL
} mmi_phb_inline_item_enum;

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_index     [IN]            
 *  item_index      [IN]            
 *  store_index     [IN]            
 *  string_list     [?]             
 *  image_list      [?]             
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_phb_op_fill_inline_item(U16 item_id, U16 pre_item_id, U8 storage, mmi_id inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 field_index = item_id - CUI_INLINE_ITEM_ID_BASE;
#if 0	
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    cui_inline_set_item_date_time_struct bday_date;
#endif
    cui_inline_set_item_struct item;
    cui_inline_item_text_edit_struct item_text;
#if 0	
#if defined(__MMI_PHB_SIM_NUMBER_MANAGEMENT__) || defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif
#else
#if defined(__MMI_PHB_SIM_NUMBER_MANAGEMENT__) 
    cui_inline_item_display_only_struct item_display;
#endif
#endif
#ifndef __MMI_MAINLCD_96X64__
    cui_inline_set_item_struct caption_item;
    cui_inline_item_caption_struct item_caption;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pre_item_id != CUI_INLINE_INSERT_TAIL)
    {
        pre_item_id = pre_item_id+100;
    }

    item.item_id = item_id;
    item.item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    item.image_id = 0;
    item.item_data = &item_text;

    item_text.string_id = 0;
    item_text.default_text_id = 0;
    item_text.required_input_mode_set = NULL;
#ifndef __MMI_MAINLCD_96X64__
    #ifndef __MMI_PHB_SLIM__
    caption_item.image_id = mmi_phb_get_img_by_field_type(field_index);
    #endif
    caption_item.item_id = item_id + 100;
#endif

#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
    if (field_index == MMI_PHB_FIELD_PIC)
    {
        cui_inline_item_caption_tn_struct item_photo;
        item_photo.string_id = mmi_phb_get_str_by_field_type(field_index, storage);
        item_photo.default_id = IMG_ID_PHB_VIEW_PHOTO;
        item_photo.buffer_p = NULL;

        if (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_SELECT_PATH)    /* An Image in select path */     
        {
            item_photo.thumbnail_path = (PU8)g_mmi_phb_res_p->img_path;
        }
        else
        {
            item_photo.thumbnail_path = NULL;
        }
#ifndef __MMI_MAINLCD_96X64__
        caption_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION_THUMBNAIL;
        caption_item.item_data = &item_photo;
#endif
    }
    else
#endif
    {
#ifndef __MMI_MAINLCD_96X64__
        item_caption.string_id = mmi_phb_get_str_by_field_type(field_index, storage);
        caption_item.item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
        caption_item.item_data = &item_caption;
#endif
    }
#ifndef __MMI_MAINLCD_96X64__
    cui_inline_insert_item(inline_id, pre_item_id, &caption_item);
#endif

    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
            item_text.buffer_size = MMI_PHB_NAME_FIELD_LENGTH + 1;
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                item_text.input_type = IMM_INPUT_TYPE_SENTENCE |
                                            INPUT_TYPE_USE_ENCODING_BASED_LENGTH |
                                            INPUT_TYPE_ONE_LESS_CHARACTER |
                                            INPUT_TYPE_GSM_EXTENDED_HANDLING;

            #if defined(__PHB_0x81_SUPPORT__)
                item_text.input_extended_type = INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            #else
                item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            #endif
            }
            else
            {
                item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
                item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            }
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U32 name_length = mmi_phb_get_name_length(storage);

                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;
                cui_inline_set_text_len(inline_id, item_id, name_length + 1);
            }
            #ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->name);
	    #else
            if((g_mmi_phb_contact_p->name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->name)) == 0))
            {
		cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
	    else
	    {
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->name);
	    }
	    #endif
            break;

    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                item_text.input_type = IMM_INPUT_TYPE_SENTENCE |
                                            INPUT_TYPE_USE_ENCODING_BASED_LENGTH |
                                            INPUT_TYPE_ONE_LESS_CHARACTER |
                                            INPUT_TYPE_GSM_EXTENDED_HANDLING;
                
            #if defined(__PHB_0x81_SUPPORT__)
                item_text.input_extended_type = INPUT_TYPE_EXT_USE_0x81_ENCODING | INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            #else
                item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            #endif
            }
            else
            {
                item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
                item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            }
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U32 name_length = srv_phb_get_alpha_field_length((phb_storage_enum)storage, MMI_PHB_CONTACT_FIELD_ID_NICK);

                name_length = (name_length > MMI_PHB_NAME_FIELD_LENGTH) ? MMI_PHB_NAME_FIELD_LENGTH : name_length;
                cui_inline_set_text_len(inline_id, item_id, name_length + 1);
            }
           

	    #ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->nick_name);
            	#else
            if((g_mmi_phb_contact_p->nick_name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->nick_name)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->nick_name);
			}
			#endif
            break;
    #endif

    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
            item_text.buffer_size = MMI_PHB_NAME_FIELD_LENGTH + 1,
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE,
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
            cui_inline_insert_item(inline_id, pre_item_id, &item);
			
            
			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->last_name);
			#else
            if((g_mmi_phb_contact_p->last_name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->last_name)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->last_name);
			}
			#endif
            break;
    #endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */

        case MMI_PHB_FIELD_NUMBER:
            item_text.buffer_size = MMI_PHB_NUMBER_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING;
            item_text.input_extended_type = 0;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            

			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->number);
			#else
            if((g_mmi_phb_contact_p->number) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->number)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->number);
			}
			#endif
            break;
        
    #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
         case MMI_PHB_FIELD_ADD_MORE:
             cui_inline_delete_item(inline_id, item_id+100);
             item.item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY;
             item.image_id = IMG_MORE_DETAILS;
             item.item_data = &item_display;
             item_display.string_id = STR_ID_PHB_ADD_MORE_DETAILS;
             cui_inline_insert_item(inline_id, pre_item_id, &item);
             break;
    #endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
        {
            mmi_phb_wcs_num_struct *opt_num = &(g_mmi_phb_contact_p->opt_num[field_index - MMI_PHB_FIELD_OPT_NUM_1]);
            item_text.buffer_size = MMI_PHB_NUMBER_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, opt_num->number);
#else
            if((opt_num->number) && (mmi_ucs2strlen((const CHAR *)(opt_num->number)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
                cui_inline_set_value(inline_id, item_id, opt_num->number);
			}
			#endif
        #ifdef __MMI_PHB_USIM_SUPPORT__
            if(mmi_phb_check_storage(MMI_FALSE, storage))
            {
                WCHAR *label = srv_phb_get_field_type_label(
                                opt_num->type,
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                (phb_storage_enum)storage);

                if ((label == NULL) || (label[0] == '\0'))
                {
                    label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                }

                cui_inline_set_value(
                    inline_id,
                    item_id+100,
                    label);
            }
        #endif
            break;
        }

        case MMI_PHB_FIELD_COMPANY_NAME:
            item_text.buffer_size = MMI_PHB_COMPANY_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = 0;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            

			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->companyName);
			#else
            if((g_mmi_phb_contact_p->companyName) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->companyName)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->companyName);
			}
			#endif
			
            break;

        case MMI_PHB_FIELD_EMAIL:
            item_text.buffer_size = MMI_PHB_EMAIL_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_EMAIL;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
      #ifdef __MMI_PHB_USIM_SUPPORT__      
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                U32 name_length = srv_phb_get_alpha_field_length((phb_storage_enum)storage, MMI_PHB_CONTACT_FIELD_ID_EMAIL);

                name_length = (name_length > MMI_PHB_EMAIL_LENGTH) ? MMI_PHB_EMAIL_LENGTH : name_length;
                cui_inline_set_text_len(inline_id, item_id, name_length + 1);
            }
      #endif
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->emailAddress);
#else
            if((g_mmi_phb_contact_p->emailAddress) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->emailAddress)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->emailAddress);
			}
			#endif
            break;

    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            item_text.buffer_size = MMI_PHB_EMAIL_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_EMAIL;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->emailAddress2);
#else
            if((g_mmi_phb_contact_p->emailAddress2) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->emailAddress2)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
				cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->emailAddress2);
			}
			#endif
            break;
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) */
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
            item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
            item.item_data = NULL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            cui_inline_set_item_select(
                inline_id,
                item_id,
                g_mmi_phb_resource.total_image_id,
                g_mmi_phb_resource.image_name_list,
                (U8) g_mmi_phb_res_p->selected_pic_index);
            break;

        case MMI_PHB_FIELD_RING:
            item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
            item.item_data = NULL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            cui_inline_set_item_select(
                inline_id,
                item_id,
                g_mmi_phb_resource.total_ring_tone,
                g_mmi_phb_resource.ring_tone_name_list,
                (U8) g_mmi_phb_res_p->selected_ring_index);
            break;

   #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            item.item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
            item.item_data = NULL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            cui_inline_set_item_select(
                inline_id,
                item_id,
                g_mmi_phb_resource.total_video_id,
                g_mmi_phb_resource.video_name_list,
                (U8) g_mmi_phb_res_p->selected_video_index);
            break;
    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    #endif /* __MMI_PHB_CALLER_RES__ */

    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            if (!mmi_phb_bday_format(g_mmi_phb_contact_p->bday, g_mmi_phb_contact_p->b_day, g_mmi_phb_contact_p->b_month, g_mmi_phb_contact_p->b_year))
            {
                MYTIME current_time;

                GetDateTime(&current_time);

                bday_date.year = (U16) current_time.nYear;
                bday_date.month = (U16) current_time.nMonth;
                bday_date.day = (U16) current_time.nDay;
                bday_date.hour = 0;
                bday_date.minute = 0;
                bday_date.second = 0;
            }
            else
            {
                bday_date.year = (U16) gui_atoi(g_mmi_phb_contact_p->b_year);
                bday_date.month = (U16) gui_atoi(g_mmi_phb_contact_p->b_month);
                bday_date.day = (U16) gui_atoi(g_mmi_phb_contact_p->b_day);
                bday_date.hour = 0;
                bday_date.minute = 0;
                bday_date.second = 0;
            }
            item.item_flag = CUI_INLINE_ITEM_TYPE_DATE;
            item.item_data = NULL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            cui_inline_set_value(inline_id, item_id, &bday_date);
            cui_inline_set_item_attributes(inline_id, item_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT);
            g_mmi_phb_save_contact_p->bday_changed = MMI_TRUE;
            g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
            break;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

    #ifdef __MMI_PHB_INFO_FIELD__
        case MMI_PHB_FIELD_TITLE:
            item_text.buffer_size = MMI_PHB_TITLE_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = 0;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
           

            
	        #ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->title);
			#else
            if((g_mmi_phb_contact_p->title) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->title)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
                cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->title);
			}
			#endif
			
            break;

        case MMI_PHB_FIELD_URL:
            item_text.buffer_size = MMI_PHB_URL_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_URL;
            item_text.required_input_mode_set = NULL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            

			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->url);
			#else
            if((g_mmi_phb_contact_p->url) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->url)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->url);
			}
			#endif
			
            break;

        case MMI_PHB_FIELD_ADR_POBOX:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            item_text.required_input_mode_set = NULL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            

			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->pobox);
			#else
            if((g_mmi_phb_contact_p->pobox) &&(mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->pobox)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->pobox);
			}
			#endif
            break;

        case MMI_PHB_FIELD_ADR_EXTENSION:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->extension);
	#else
            if((g_mmi_phb_contact_p->extension) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->extension)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->extension);
			}
			#endif
            break;

        case MMI_PHB_FIELD_ADR_STREET:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            

			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->street);
			#else
            if((g_mmi_phb_contact_p->street) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->street)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
				cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->street);
			}
			#endif
			
            break;

        case MMI_PHB_FIELD_ADR_CITY:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->city);
	#else
            if((g_mmi_phb_contact_p->city) &&( mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->city)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
				cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->city);
			}
			#endif
            break;

        case MMI_PHB_FIELD_ADR_STATE:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->state);
	#else
            if((g_mmi_phb_contact_p->state) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->state)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
                cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->state);
			}
			#endif
            break;

        case MMI_PHB_FIELD_ADR_POSTALCODE:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_ASCII_CHAR;
            item_text.input_extended_type =INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->postalcode);
#else
            if((g_mmi_phb_contact_p->postalcode) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->postalcode)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
                cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->postalcode);
			}
			#endif
            break;

        case MMI_PHB_FIELD_ADR_COUNTRY:
            item_text.buffer_size = MMI_PHB_ADDRESS_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
            
			#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->country);
			#else
            if((g_mmi_phb_contact_p->country) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->country)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
				cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->country);
			}
			#endif
            break;

        case MMI_PHB_FIELD_NOTE:
            item_text.buffer_size = MMI_PHB_NOTE_LENGTH + 1;
            item_text.input_type = IMM_INPUT_TYPE_SENTENCE;
            item_text.input_extended_type = 0;
            cui_inline_insert_item(inline_id, pre_item_id, &item);
#ifndef __MMI_MAINLCD_96X64__
            cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->note);
#else
            if((g_mmi_phb_contact_p->note) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->note)) == 0))
            {
				cui_inline_set_value(inline_id, item_id, (void *) (get_string(STR_GLOBAL_EMPTY)));
            }
			else
			{
                cui_inline_set_value(inline_id, item_id, g_mmi_phb_contact_p->note);
			}
			#endif
            break;
    #endif /* __MMI_PHB_INFO_FIELD__ */
    #if 0
    #if defined(__MMI_VOIP__)
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
    #endif /* defined(__MMI_VOIP__) */
	#endif
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
        #if defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else /* defined(IMPS_WV13_ENHANCEMENT) */
/* under construction !*/
/* under construction !*/
        #endif /* defined(IMPS_WV13_ENHANCEMENT) */
/* under construction !*/
#ifndef __MMI_MAINLCD_96X64__
/* under construction !*/
	#else
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
    #endif /* defined(__MMI_IMPS__) */
	#endif

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid         [IN]        
 *  item_id     [IN]        
 *  value       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_get_value(mmi_id gid, U16 item_id, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
    {
        if (mmi_phb_edit_field_display((U8) (item_id - CUI_INLINE_ITEM_ID_BASE), g_mmi_phb_save_contact_p->field_mask, g_mmi_phb_save_contact_p->storage))
        {
            cui_inline_get_value(gid, item_id, value);
        }
    }
    else
#endif
    if (mmi_phb_edit_field_display((U8) (item_id - CUI_INLINE_ITEM_ID_BASE), g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
    {
        cui_inline_get_value(gid, item_id, value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_item_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_phb_get_item_value(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    cui_inline_set_item_date_time_struct bday_date;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_USIM_SUPPORT__
    if(mmi_phb_check_storage(MMI_FALSE, g_mmi_phb_save_contact_p->storage))
    {

        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_NICK_NAME, g_mmi_phb_contact_p->nick_name);
    #ifdef __MMI_PHB_OPTIONAL_FIELD__        
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_OPT_NUM_1, g_mmi_phb_contact_p->opt_num[0].number);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_OPT_NUM_2, g_mmi_phb_contact_p->opt_num[1].number);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_OPT_NUM_3, g_mmi_phb_contact_p->opt_num[2].number);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_EMAIL, g_mmi_phb_contact_p->emailAddress);
    #endif
    }
    else
#endif
    {
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_LAST_NAME, g_mmi_phb_contact_p->last_name);
#endif
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);

#ifdef __MMI_PHB_OPTIONAL_FIELD__
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_OPT_NUM_1, g_mmi_phb_contact_p->opt_num[0].number);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_COMPANY_NAME, g_mmi_phb_contact_p->companyName);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_EMAIL, g_mmi_phb_contact_p->emailAddress);
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_EMAIL2, g_mmi_phb_contact_p->emailAddress2);
#endif
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_OPT_NUM_2, g_mmi_phb_contact_p->opt_num[1].number);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_OPT_NUM_3, g_mmi_phb_contact_p->opt_num[2].number);
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        if (mmi_phb_edit_field_display(MMI_PHB_FIELD_BIRTHDAY, g_mmi_phb_save_contact_p->field_mask, PHB_STORAGE_NVRAM))
        {
            cui_inline_get_value(gid, MMI_PHB_INLINE_FIELD_BIRTHDAY, &bday_date);
            kal_wsprintf(g_mmi_phb_contact_p->b_year, "%04d", bday_date.year);
            kal_wsprintf(g_mmi_phb_contact_p->b_month, "%02d", bday_date.month);
            kal_wsprintf(g_mmi_phb_contact_p->b_day, "%02d", bday_date.day);
        }
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
#ifdef __MMI_PHB_CALLER_RES__
        {
        #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            S32 org_index = g_mmi_phb_res_p->selected_pic_index;
        #endif
            mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_PIC, &g_mmi_phb_res_p->selected_pic_index);

        #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            if (org_index != g_mmi_phb_res_p->selected_pic_index)
            {
                U32 max_index = 0;
                cui_inline_item_caption_tn_struct caption_tn_data;

            #if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
                max_index += 4;
            #endif
            #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                max_index++;
            #endif
                max_index++;
            #endif

                caption_tn_data.default_id = IMG_ID_PHB_VIEW_PHOTO;
                caption_tn_data.string_id= STR_ID_PHB_CALLER_PIC;
                caption_tn_data.buffer_p = NULL;

                if (g_mmi_phb_res_p->selected_pic_index == max_index)    /* An Image in select path */     
                {
                    caption_tn_data.thumbnail_path = (PU8)g_mmi_phb_res_p->img_path;
                }
                else
                {
                    caption_tn_data.thumbnail_path = NULL;
                }

                if (g_mmi_phb_res_p->img_path[0]
                    && ((org_index == max_index) || (g_mmi_phb_res_p->selected_pic_index == max_index))
                    )
                {
                    cui_inline_set_value(gid, MMI_PHB_INLINE_FIELD_PIC+100, &caption_tn_data);
                }
            }
        #endif
        }

        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_RING, &g_mmi_phb_res_p->selected_ring_index);
#if defined(__MMI_PHB_CALLER_VIDEO__)
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_VIDEO, &g_mmi_phb_res_p->selected_video_index);
#endif
#endif /* __MMI_PHB_CALLER_RES__ */
#if defined(__MMI_PHB_INFO_FIELD__)
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_TITLE, g_mmi_phb_contact_p->title);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_URL, g_mmi_phb_contact_p->url);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_POBOX, g_mmi_phb_contact_p->pobox);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_EXTENSION, g_mmi_phb_contact_p->extension);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_STREET, g_mmi_phb_contact_p->street);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_CITY, g_mmi_phb_contact_p->city);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_STATE, g_mmi_phb_contact_p->state);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_POSTALCODE, g_mmi_phb_contact_p->postalcode);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_ADR_COUNTRY, g_mmi_phb_contact_p->country);
        mmi_phb_get_value(gid, MMI_PHB_INLINE_FIELD_NOTE, g_mmi_phb_contact_p->note);
#endif /* defined(__MMI_PHB_INFO_FIELD__) */
#if 0
#if defined(__MMI_IMPS__)
#if !defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif
#endif /* defined(__MMI_IMPS__) */
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
#endif
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sim_editor_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_sim_editor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINLCD_96X64__			  
	S32 value_empty=0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            {
                cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*) evt;

                cui_inline_get_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
                cui_inline_get_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);

				
				#ifdef __MMI_MAINLCD_96X64__
                if (MMI_PHB_INLINE_FIELD_NAME==submit_evt->item_id)
                {
                value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
	            if(value_empty==0 )
	            {
				   memset(g_mmi_phb_contact_p->name, 0, sizeof(g_mmi_phb_contact_p->name));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
	            }
                }
				else if(MMI_PHB_INLINE_FIELD_NUMBER==submit_evt->item_id)
				{
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->number, 0, sizeof(g_mmi_phb_contact_p->number));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
	            }
				}
	            #endif
				

            #ifdef __MMI_PHB_USIM_SUPPORT__     
                mmi_phb_get_item_value(submit_evt->sender_id);      
            #endif
            #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
                if (submit_evt->item_id == MMI_PHB_FIELD_ADD_MORE + CUI_INLINE_ITEM_ID_BASE)
                {
                    mmi_phb_entry_add_more_details_confirm();
                }
                else
            #endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */
                {
                    if (evt->evt_id == EVT_ID_CUI_INLINE_SUBMIT)
                    {
                        if (submit_evt->sofktey_type == MMI_CENTER_SOFTKEY)
                        {
                            mmi_phb_edit_ok_for_csk();
                        }
                        else
                        {
                            mmi_phb_entry_op_edit_option();
                        }
                    }
                    else if (evt->evt_id == EVT_ID_CUI_INLINE_CSK_PRESS)
                    {
                        mmi_phb_edit_ok_for_csk();
                    }
                }
            }
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
            {
                cui_event_inline_common_struct *submit_evt = (cui_event_inline_common_struct*) evt;
                cui_inline_get_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
                cui_inline_get_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
            #ifdef __MMI_PHB_USIM_SUPPORT__     
                mmi_phb_get_item_value(submit_evt->sender_id);      
            #endif


			   #ifdef __MMI_MAINLCD_96X64__
                value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
	            if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->name, 0, sizeof(g_mmi_phb_contact_p->name));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
	            }		
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->number, 0, sizeof(g_mmi_phb_contact_p->number));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
	            }
				
	           #endif
			   
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*) evt;
                cui_inline_close(abort_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            {
                cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*) evt;
                #ifdef __MMI_MAINLCD_96X64__
                MMI_ID inline_gid = notify_evt->sender_id;
		#endif
                if (notify_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
                {
                    U16 str_id;

                    g_mmi_phb_save_contact_p->highlight_type = (U8) (notify_evt->item_id - CUI_INLINE_ITEM_ID_BASE);

                #ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
                    if (notify_evt->item_id == MMI_PHB_FIELD_ADD_MORE + CUI_INLINE_ITEM_ID_BASE)
                    {
                        str_id = STR_GLOBAL_ADD;
                    }
                    else
                #endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */
                    {
                        str_id = STR_GLOBAL_OPTIONS;
                    }

                    cui_inline_set_softkey_text(
                        notify_evt->sender_id,
                        notify_evt->item_id,
                        MMI_LEFT_SOFTKEY,
                        str_id);
                    cui_inline_set_softkey_icon(
                        notify_evt->sender_id,
                        notify_evt->item_id,
                        MMI_CENTER_SOFTKEY,
                        IMG_GLOBAL_SAVE_CSK);
                }
                else if (notify_evt->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED)
                {
                    g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
                }
                #ifdef __MMI_MAINLCD_96X64__
                cui_inline_set_title(inline_gid, mmi_phb_get_str_by_field_type(g_mmi_phb_save_contact_p->highlight_type, g_mmi_phb_save_contact_p->storage), IMG_SCR_PBOOK_CAPTION);
		draw_title();		
		#endif

                #ifdef __MMI_MAINLCD_96X64__
								
				cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if((value_empty==0 )||((g_mmi_phb_contact_p->name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->name)) == 0)))
			    {
					cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, (void *) get_string(STR_GLOBAL_EMPTY));
				}
				else
				{
					cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
				}
				
				cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if((value_empty==0 )||((g_mmi_phb_contact_p->number) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->number)) == 0)))
				{
					cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, (void *) get_string(STR_GLOBAL_EMPTY));
				}
				else
				{
					cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
				}
								
						
	            #endif



			

            }
            break;

    #ifndef __MMI_MAINLCD_96X64__
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            MMI_ID inline_gid = g_mmi_phb_save_contact_p->editor_id;
            U32 field_mask = g_mmi_phb_save_contact_p->field_mask;
            U8 storage = g_mmi_phb_save_contact_p->storage;

            if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_NUMBER, field_mask, storage))
            {
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_NUMBER + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    CUI_INLINE_RESET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
             }

            if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_NICK_NAME, field_mask, storage))
            {
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_NICK_NAME + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    CUI_INLINE_RESET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            cui_inline_set_default_icon_style(inline_gid, (U8*) GetImage(CHECKBOX_ON_IMAGE_ID));

        #ifdef __MMI_PHB_OPTIONAL_FIELD__       
            if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_OPT_NUM_1, field_mask, storage))
            {
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_OPT_NUM_1 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    CUI_INLINE_RESET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_OPT_NUM_2, field_mask, storage))
            {
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_OPT_NUM_2 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    CUI_INLINE_RESET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_OPT_NUM_3, field_mask, storage))
            {
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_OPT_NUM_3 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    CUI_INLINE_RESET_ATTRIBUTE,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            cui_inline_set_default_icon_style(inline_gid, (U8*) GetImage(CHECKBOX_ON_IMAGE_ID));

            if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_1 ||
                g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_2 ||
                g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_3)
            {
                U8 index = 0;
                #ifndef __MMI_PHB_SLIM__ 
                cui_inline_set_item_icon(
                    g_mmi_phb_save_contact_p->editor_id,
                    (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                    IMG_MOBILE_NUMBER);
				#endif
                index = g_mmi_phb_save_contact_p->highlight_type - MMI_PHB_FIELD_OPT_NUM_1;
                if(g_mmi_phb_contact_p->opt_num[index].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    cui_inline_set_value(
                        g_mmi_phb_save_contact_p->editor_id,
                        (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                        GetString(STR_ID_PHB_MOBILE_NUMBER));
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                            g_mmi_phb_contact_p->opt_num[index].type, 
                            MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                            (phb_storage_enum)g_mmi_phb_save_contact_p->storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }

                    cui_inline_set_value(
                        g_mmi_phb_save_contact_p->editor_id,
                        (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                        (U8*)label);
                }
            }
        #endif
        
        }
            break;
    #endif

	#else
	
	case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
	{
		MMI_ID inline_gid = g_mmi_phb_save_contact_p->editor_id;
		U32 field_mask = g_mmi_phb_save_contact_p->field_mask;
		U8 storage = g_mmi_phb_save_contact_p->storage;


	 #ifdef __MMI_PHB_USIM_SUPPORT__
		if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_NUMBER, field_mask, storage))
		{
			cui_inline_set_item_attributes(
				inline_gid,
				MMI_PHB_INLINE_FIELD_NUMBER + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
				CUI_INLINE_RESET_ATTRIBUTE,
				CUI_INLINE_ITEM_DEFAULT_ICON);
		 }
	
		if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_NICK_NAME, field_mask, storage))
		{
			cui_inline_set_item_attributes(
				inline_gid,
				MMI_PHB_INLINE_FIELD_NICK_NAME + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
				CUI_INLINE_RESET_ATTRIBUTE,
				CUI_INLINE_ITEM_DEFAULT_ICON);
		}
		cui_inline_set_default_icon_style(inline_gid, (U8*) GetImage(CHECKBOX_ON_IMAGE_ID));
	
        #ifdef __MMI_PHB_OPTIONAL_FIELD__		
		if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_OPT_NUM_1, field_mask, storage))
		{
			cui_inline_set_item_attributes(
				inline_gid,
				MMI_PHB_INLINE_FIELD_OPT_NUM_1 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
				CUI_INLINE_RESET_ATTRIBUTE,
				CUI_INLINE_ITEM_DEFAULT_ICON);
		}
		if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_OPT_NUM_2, field_mask, storage))
		{
			cui_inline_set_item_attributes(
				inline_gid,
				MMI_PHB_INLINE_FIELD_OPT_NUM_2 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
				CUI_INLINE_RESET_ATTRIBUTE,
				CUI_INLINE_ITEM_DEFAULT_ICON);
		}
		if (mmi_phb_edit_usim_field_display(MMI_PHB_FIELD_OPT_NUM_3, field_mask, storage))
		{
			cui_inline_set_item_attributes(
				inline_gid,
				MMI_PHB_INLINE_FIELD_OPT_NUM_3 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
				CUI_INLINE_RESET_ATTRIBUTE,
				CUI_INLINE_ITEM_DEFAULT_ICON);
		}
		cui_inline_set_default_icon_style(inline_gid, (U8*) GetImage(CHECKBOX_ON_IMAGE_ID));
	
		if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_1 ||
			g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_2 ||
			g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_3)
		{
			U8 index = 0;
		#ifndef __MMI_PHB_SLIM__ 
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                cui_inline_set_item_icon(
                    g_mmi_phb_save_contact_p->editor_id,
                    (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                    IMG_MOBILE_NUMBER);
		#else
		    cui_inline_set_item_icon(
				g_mmi_phb_save_contact_p->editor_id,
				(U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
				0);
		#endif
		#endif
                index = g_mmi_phb_save_contact_p->highlight_type - MMI_PHB_FIELD_OPT_NUM_1;
                if(g_mmi_phb_contact_p->opt_num[index].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    cui_inline_set_value(
                        g_mmi_phb_save_contact_p->editor_id,
                        (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                        GetString(STR_ID_PHB_MOBILE_NUMBER));
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                            g_mmi_phb_contact_p->opt_num[index].type, 
                            MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                            (phb_storage_enum)g_mmi_phb_save_contact_p->storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }

                    cui_inline_set_value(
                        g_mmi_phb_save_contact_p->editor_id,
                        (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                        (U8*)label);
                }
            }
        #endif
        
		#endif

		cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
		value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
		if((value_empty==0 )||((g_mmi_phb_contact_p->name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->name)) == 0)))
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, (void *) get_string(STR_GLOBAL_EMPTY));
		}
		else
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
		}
		
		cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
		value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
		if((value_empty==0 )||((g_mmi_phb_contact_p->number) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->number)) == 0)))
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, (void *) get_string(STR_GLOBAL_EMPTY));
		}
		else
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
		}

        }
            break;
    #endif

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_phone_editor_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt         [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_phb_phone_editor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0	
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */
#endif

#ifdef __MMI_MAINLCD_96X64__			  
	S32 value_empty=0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            {
                cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*) evt;
                mmi_phb_get_item_value(submit_evt->sender_id);
				#ifdef __MMI_MAINLCD_96X64__
                if (MMI_PHB_INLINE_FIELD_NAME==submit_evt->item_id)
                {
                value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
	            if(value_empty==0 )
	            {
				   memset(g_mmi_phb_contact_p->name, 0, sizeof(g_mmi_phb_contact_p->name));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
	            }
                }
				else if(MMI_PHB_INLINE_FIELD_NUMBER==submit_evt->item_id)
				{
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->number, 0, sizeof(g_mmi_phb_contact_p->number));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
	            }
				}
	            #endif
                if (submit_evt->sofktey_type == MMI_CENTER_SOFTKEY)
                {
                    mmi_phb_edit_ok_for_csk();
                }
                else
                {
                    mmi_phb_entry_op_edit_option();
                }
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            {
                cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*) evt;
                cui_inline_close(abort_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_CSK_PRESS:
            {
                cui_event_inline_csk_press_struct *csk_press_evt = (cui_event_inline_csk_press_struct*) evt;
                mmi_phb_get_item_value(csk_press_evt->sender_id);


				#ifdef __MMI_MAINLCD_96X64__
                if (MMI_PHB_INLINE_FIELD_NAME==csk_press_evt->item_id)
                {
                value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
	            if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->name, 0, sizeof(g_mmi_phb_contact_p->name));
				   cui_inline_set_value(csk_press_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
	            }
                }
				else if(MMI_PHB_INLINE_FIELD_NUMBER==csk_press_evt->item_id)
				{
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->number, 0, sizeof(g_mmi_phb_contact_p->number));
				   cui_inline_set_value(csk_press_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
	            }
				}
	            #endif
				
                mmi_phb_edit_ok_for_csk();
            }
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            {
                cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*) evt;
                MMI_ID inline_gid = notify_evt->sender_id;
                U16 item_id = notify_evt->item_id;

                if (notify_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
                {
                #ifdef __MMI_PHB_CALLER_RES__
                    mmi_phb_stop_ring_tone_id();
                #endif
                    g_mmi_phb_save_contact_p->highlight_type = (U8) (notify_evt->item_id - CUI_INLINE_ITEM_ID_BASE);
                    cui_inline_set_softkey_text(
                        inline_gid, item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
                    cui_inline_set_softkey_icon(
                        inline_gid, item_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_SAVE_CSK);
                }
                else if (notify_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
                {
                    mmi_phb_get_item_value(inline_gid);

                    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, 530);
                    MMI_TRACE(MMI_PHB_TRACE_GROUP, TRC_MMI_PHB_COMMON_TRACE_TEST, item_id);

                #ifdef __MMI_PHB_CALLER_RES__
                    if (item_id == MMI_PHB_INLINE_FIELD_RING)
                    {
                        mmi_phb_ring_tone_highlight_hdlr(g_mmi_phb_res_p->selected_ring_index);
                    }
                #endif /* __MMI_PHB_CALLER_RES__ */
                }
                else if(notify_evt->event_type == CUI_INLINE_NOTIFY_BACK_WITHOUT_CHANGE)
                {
                    mmi_phb_get_item_value(inline_gid);
                }
                else if (notify_evt->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED)
                {
                #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
                    if (item_id == MMI_PHB_INLINE_FIELD_BIRTHDAY)
                    {
                        g_mmi_phb_save_contact_p->bday_changed = MMI_TRUE;
                    }
                #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
                    g_mmi_phb_save_contact_p->done_flag = MMI_TRUE;
                }
                #ifdef __MMI_MAINLCD_96X64__
                cui_inline_set_title(inline_gid, mmi_phb_get_str_by_field_type(g_mmi_phb_save_contact_p->highlight_type, g_mmi_phb_save_contact_p->storage), IMG_SCR_PBOOK_CAPTION);
		draw_title();
		#endif

				#ifdef __MMI_MAINLCD_96X64__
                
                cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
                value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
                if((value_empty==0 )||((g_mmi_phb_contact_p->name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->name)) == 0)))
				{
					cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, (void *) get_string(STR_GLOBAL_EMPTY));
				}
				else
				{
				    cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
				}

                cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if((value_empty==0 )||((g_mmi_phb_contact_p->number) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->number)) == 0)))
				{
					cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, (void *) get_string(STR_GLOBAL_EMPTY));
				}
				else
				{
				    cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
				}
				
		
	            #endif

				
				
            }
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            MMI_ID inline_gid = g_mmi_phb_save_contact_p->editor_id;
            U32 field_mask = g_mmi_phb_save_contact_p->field_mask;

        #ifdef __MMI_PHB_CALLER_RES__
            mmi_phb_contact_res_config();
        #endif

        #if defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__)
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_NUMBER, field_mask, PHB_STORAGE_NVRAM))
            {
                U8 operation = CUI_INLINE_RESET_ATTRIBUTE;

                if (((phb_storage_enum)g_mmi_phb_save_contact_p->storage == PHB_STORAGE_NVRAM) &&
                    ((g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_NUMBER) || 
                     (g_mmi_phb_contact_p->default_number == 0xff)))
                {
                    operation = CUI_INLINE_SET_ATTRIBUTE;
                }
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_NUMBER + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    operation,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_OPT_NUM_1, field_mask, PHB_STORAGE_NVRAM))
            {
                U8 operation = CUI_INLINE_RESET_ATTRIBUTE;

                if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_HOME)
                {
                    operation = CUI_INLINE_SET_ATTRIBUTE;
                }
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_OPT_NUM_1 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    operation,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_OPT_NUM_2, field_mask, PHB_STORAGE_NVRAM))
            {
                U8 operation = CUI_INLINE_RESET_ATTRIBUTE;

                if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_OFFICE)
                {
                    operation = CUI_INLINE_SET_ATTRIBUTE;
                }
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_OPT_NUM_2 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    operation,
                    CUI_INLINE_ITEM_DEFAULT_ICON);
            }
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_OPT_NUM_3, field_mask, PHB_STORAGE_NVRAM))
            {
                U8 operation = CUI_INLINE_RESET_ATTRIBUTE;

                if (g_mmi_phb_contact_p->default_number == SRV_PHB_ENTRY_FIELD_FAX)
                {
                    operation = CUI_INLINE_SET_ATTRIBUTE;
                }
                cui_inline_set_item_attributes(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_OPT_NUM_3 + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL,
                    operation,
                    CUI_INLINE_ITEM_DEFAULT_ICON);

            }

            cui_inline_set_default_icon_style(inline_gid, (U8*) GetImage(CHECKBOX_ON_IMAGE_ID));
        #endif /* defined (__MMI_PHB_DEFAULT_NUMBER__) && defined(__MMI_PHB_OPTIONAL_FIELD__) */

        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_BIRTHDAY, field_mask, PHB_STORAGE_NVRAM))
            {
                cui_inline_set_date_boundary(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_BIRTHDAY,
                    MMI_PHB_BDAY_MAX_YEAR_INT,
                    1900,
                    12,
                    1);
            }
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

        #ifdef __MMI_PHB_CALLER_RES__
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_RING, field_mask, PHB_STORAGE_NVRAM))
            {
                cui_inline_set_item_select(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_RING,
                    g_mmi_phb_resource.total_ring_tone,
                    g_mmi_phb_resource.ring_tone_name_list,
                    (U8) g_mmi_phb_res_p->selected_ring_index);
            }
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_PIC, field_mask, PHB_STORAGE_NVRAM))
            {
            #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
                S32 org_index;
                
                mmi_phb_get_value(inline_gid, MMI_PHB_INLINE_FIELD_PIC, &org_index);
            
                if (org_index != g_mmi_phb_res_p->selected_pic_index)
                {
                    U32 max_index = 0;
                    cui_inline_item_caption_tn_struct caption_tn_data;
            
                #if !defined(LOW_COST_SUPPORT) && !defined(__MMI_FTE_SUPPORT_SLIM__) && !defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
                    max_index += 4;
                #endif
                #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
                #if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
                    max_index++;
                #endif
                    max_index++;
                #endif
 
                    caption_tn_data.default_id = IMG_ID_PHB_VIEW_PHOTO;
                    caption_tn_data.string_id= STR_ID_PHB_CALLER_PIC;
                    caption_tn_data.buffer_p = NULL;

                    if (g_mmi_phb_res_p->selected_pic_index == max_index)    /* An Image in select path */     
                    {
                        caption_tn_data.thumbnail_path = (PU8)g_mmi_phb_res_p->img_path;
                    }
                    else
                    {
                        caption_tn_data.thumbnail_path = NULL;
                    }

                    if (g_mmi_phb_res_p->img_path[0]
                        && ((org_index == max_index) || (g_mmi_phb_res_p->selected_pic_index == max_index))
                        )
                    {
                        cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_PIC+100, &caption_tn_data);
                    }
                }
            #endif

                cui_inline_set_item_select(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_PIC,
                    g_mmi_phb_resource.total_image_id,
                    g_mmi_phb_resource.image_name_list,
                    (U8) g_mmi_phb_res_p->selected_pic_index);
            }
        #if defined(__MMI_PHB_CALLER_VIDEO__)
            if (mmi_phb_edit_field_display(MMI_PHB_FIELD_VIDEO, field_mask, PHB_STORAGE_NVRAM))
            {
                cui_inline_set_item_select(
                    inline_gid,
                    MMI_PHB_INLINE_FIELD_VIDEO,
                    g_mmi_phb_resource.total_video_id,
                    g_mmi_phb_resource.video_name_list,
                    (U8) g_mmi_phb_res_p->selected_video_index);
            }
        #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
        #endif /* __MMI_PHB_CALLER_RES__ */

        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            if (g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_1 ||
                g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_2 ||
                g_mmi_phb_save_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_3)
            {
                #ifndef __MMI_PHB_SLIM__
                cui_inline_set_item_icon(
                    inline_gid,
                    (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                    mmi_phb_get_img_by_field_type(g_mmi_phb_save_contact_p->highlight_type));
                #endif
                cui_inline_set_value(
                    inline_gid,
                    (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE + MMI_PHB_INLINE_ITEM_CAPTION_ADDTIONAL),
                    GetString(mmi_phb_get_str_by_field_type(g_mmi_phb_save_contact_p->highlight_type, PHB_STORAGE_NVRAM)));
            }
        #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
        #if 0
        #if defined(__MMI_IMPS__)
        #if defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __USB_IN_NORMAL_MODE__
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
                #ifndef __MMI_PHB_SLIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
        #endif /* defined(IMPS_WV13_ENHANCEMENT) */
        #endif /* defined(__MMI_IMPS__) */
		#endif


		
#ifdef __MMI_MAINLCD_96X64__
		
		cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
		value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
		if((value_empty==0 )||((g_mmi_phb_contact_p->name) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->name)) == 0)))
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, (void *) get_string(STR_GLOBAL_EMPTY));
		}
		else
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
		}
		
		cui_inline_get_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
		value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
		if((value_empty==0 )||((g_mmi_phb_contact_p->number) && (mmi_ucs2strlen((const CHAR *)(g_mmi_phb_contact_p->number)) == 0)))
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, (void *) get_string(STR_GLOBAL_EMPTY));
		}
		else
		{
			cui_inline_set_value(inline_gid, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
		}
		
		
#endif

		
        }
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        {
            cui_event_inline_common_struct *common_evt = (cui_event_inline_common_struct*) evt;
			#ifdef __MMI_MAINLCD_96X64__
			cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*) evt;
			#endif
        #ifdef __MMI_PHB_CALLER_RES__
            mmi_phb_stop_ring_tone_id();
        #endif

            mmi_phb_get_item_value(common_evt->sender_id);
		    
                
               #ifdef __MMI_MAINLCD_96X64__
               
                
                value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->name),(U16 *) get_string(STR_GLOBAL_EMPTY));
	            if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->name, 0, sizeof(g_mmi_phb_contact_p->name));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NAME, g_mmi_phb_contact_p->name);
	            }		
				value_empty=srv_phb_compare_ucs2_string((U16 *) (g_mmi_phb_contact_p->number),(U16 *) get_string(STR_GLOBAL_EMPTY));
				if(value_empty==0 )
	            {
		           memset(g_mmi_phb_contact_p->number, 0, sizeof(g_mmi_phb_contact_p->number));
				   cui_inline_set_value(submit_evt->sender_id, MMI_PHB_INLINE_FIELD_NUMBER, g_mmi_phb_contact_p->number);
	            }
				
	           #endif
	            
        }
            break;

        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        #ifdef __MMI_PHB_CALLER_RES__
            mmi_phb_stop_ring_tone_id();
        #endif            
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        #ifdef __MMI_BIRTHDAY_REMINDER__
            mmi_tdl_br_clear_buffer_cb();
        #endif
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_construct_sim_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  prepare item data for inline CUI
 *****************************************************************************/
static void mmi_phb_construct_inline_editor(cui_inline_struct* inline_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inline_struct->items_count = 0;
    inline_struct->title = STR_GLOBAL_EDIT;
    inline_struct->title_icon = IMG_SCR_PBOOK_CAPTION;
    inline_struct->screen_flag = CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT;
    inline_struct->softkey = NULL;
    inline_struct->items = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_add_entry
 * DESCRIPTION
 *  Draws the new entry screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_add_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 field_index = 0, i, field_type;
    U8 storage = g_mmi_phb_save_contact_p->storage;
    mmi_id inline_id;
    cui_inline_struct inline_struct;
    U16 title_id;
    U32 *field_mask = &(g_mmi_phb_save_contact_p->field_mask);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_entry_save_contact_prepare_data(g_mmi_phb_contact_p, storage);

    if (mmi_phb_check_storage(MMI_TRUE, storage))
    {
        while ((field_type = mmi_phb_edit_get_default_field_type(field_index++)) != MMI_PHB_FIELD_TOTAL)
        {
            *field_mask |= mmi_phb_get_field_mask_by_field_type(field_type);
        }

    #if defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
        *field_mask &= ~SRV_PHB_ENTRY_FIELD_PIC;
    #endif
    }
    else
    {
        *field_mask |= SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;
    #ifdef __MMI_PHB_USIM_SUPPORT__
        if(mmi_phb_check_usim_detail_ex((phb_storage_enum)g_mmi_phb_save_contact_p->storage,0,PHB_EMAIL))
        {
            *field_mask |= SRV_PHB_ENTRY_FIELD_EMAIL1;
        }
    #endif
    }

    if (g_mmi_phb_save_contact_p->first_highlight_type != 0xff)
    {
        g_mmi_phb_save_contact_p->highlight_type = g_mmi_phb_save_contact_p->first_highlight_type;
    }

    mmi_phb_construct_inline_editor(&inline_struct);
    inline_id = cui_inline_create(g_mmi_phb_save_contact_p->sg_id, &inline_struct);

    g_mmi_phb_save_contact_p->editor_id = inline_id;

    for (i = MMI_PHB_FIELD_NAME; i < MMI_PHB_FIELD_TOTAL; i++)
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if ((i == MMI_PHB_FIELD_OPT_NUM_1) ||
            (i == MMI_PHB_FIELD_OPT_NUM_2) ||
            (i == MMI_PHB_FIELD_OPT_NUM_3))
        {
            field_index = mmi_phb_edit_get_opt_number_field((U8)(i - MMI_PHB_FIELD_OPT_NUM_1));
        }
        else
    #endif
        {
            field_index = i;
        }
        if (mmi_phb_edit_field_display(field_index, *field_mask, storage))
        {
            mmi_phb_op_fill_inline_item(
                (U16) (field_index + CUI_INLINE_ITEM_ID_BASE),
                (U16) CUI_INLINE_INSERT_TAIL,
                g_mmi_phb_save_contact_p->storage,
                inline_id);
        }
    }
#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
    if (mmi_phb_check_storage(MMI_FALSE, storage))
    {
        mmi_phb_op_fill_inline_item(
            (U16)(MMI_PHB_FIELD_ADD_MORE + CUI_INLINE_ITEM_ID_BASE),
            (U16)CUI_INLINE_INSERT_TAIL,
            g_mmi_phb_save_contact_p->storage,
            inline_id);
    }
#endif /* __MMI_PHB_SIM_NUMBER_MANAGEMENT__ */

    cui_inline_set_highlight_item(
        inline_id,
        (U16)(g_mmi_phb_save_contact_p->highlight_type + CUI_INLINE_ITEM_ID_BASE));

    if (g_mmi_phb_save_contact_p->action == MMI_PHB_OP_ADD)
    {
        title_id = STR_SCR_ADD_NEW_ENTRY_CAPTION;
    }
    else
    {
        title_id = STR_SCR_INLINE_EDIT_CAPTION;        
    }

    cui_inline_set_title(inline_id, title_id, IMG_SCR_PBOOK_CAPTION);

    cui_inline_run(inline_id);
}
#endif /* __MMI_PHB_UI_IN_TABS__ */

#define MMI_PHB_VIEW_CONTACT
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_view_callback
 * DESCRIPTION
 *  fte view toolbar callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_contact_view_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sg_id = mmi_phb_cntx_mgr_get_current_sg_id();
    mmi_phb_view_contact_cntx_struct * cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_phb_view_contact_cntx_struct *) mmi_frm_group_get_user_data(sg_id);

    if (index == MMI_PHB_VOICE_CALL)
    {
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
    //#ifdef __MMI_VIDEO_TELEPHONY__
        mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_VOICE_CALL);
    #else
        mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_CALL);
    #endif
    }
//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
//#ifdef __MMI_VIDEO_TELEPHONY__
    else if (index == MMI_PHB_VIDEO_CALL)
    {
        mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_VIDEO_CALL);
    }
#endif
    else if (index == MMI_PHB_SEND_MSG)
    {
    #ifdef __MMI_UNIFIED_COMPOSER__
        mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_MSG);
    #else /* __MMI_UNIFIED_COMPOSER__ */
        mmi_phb_view_entry_hdlr(cntx, MMI_PHB_OP_SMS);
    #endif /* __MMI_UNIFIED_COMPOSER__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_contact_list_update
 * DESCRIPTION
 *  fte contact main list toolbar update callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_contact_view_update(S32 index, MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
//#ifdef __MMI_VIDEO_TELEPHONY__
    wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
#endif
    wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_FALSE);

    switch (g_mmi_phb_view_contact_p->highlight_type)
    {
        case MMI_PHB_FIELD_NAME:
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        case MMI_PHB_FIELD_LAST_NAME:
    #endif
    #ifdef __MMI_PHB_USIM_SUPPORT__ /*for USIM SNE*/
        case MMI_PHB_FIELD_NICK_NAME:
    #endif
        {
            wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_TRUE);
        //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        #if defined(__MMI_VIDEO_TELEPHONY__)
            wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_TRUE);
        #endif
            
            wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_TRUE);
            break;
        }
        
        case MMI_PHB_FIELD_NUMBER:
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
    #endif
        {
            if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_NUMBER)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->number;
            }    
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            else if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_1)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->opt_num[0].number;
            }
            else if (g_mmi_phb_view_contact_p->highlight_type== MMI_PHB_FIELD_OPT_NUM_2)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->opt_num[1].number;
            }
            else if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_OPT_NUM_3)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->opt_num[2].number;
            }        
        #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
            if (mmi_ucs2strlen((CHAR *) g_mmi_phb_view_contact_p->select_data))
            {
                wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_TRUE);
            //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
            #if defined(__MMI_VIDEO_TELEPHONY__)
            //#ifdef __MMI_VIDEO_TELEPHONY__
                wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_TRUE);
            #endif

                wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_TRUE);
            }
            break;
        }
	#if 0
    #ifdef __MMI_VOIP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
    #endif
    #endif
    
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_EMAIL:
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        case MMI_PHB_FIELD_EMAIL2:
    #endif
            if (g_mmi_phb_view_contact_p->highlight_type == MMI_PHB_FIELD_EMAIL)
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->emailAddress;
            }
            
        #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
            else
            {
                g_mmi_phb_view_contact_p->select_data = g_mmi_phb_contact_p->emailAddress2;
            }
        #endif

            if (mmi_ucs2strlen((CHAR *) g_mmi_phb_view_contact_p->select_data))
            {
            #ifdef __MMI_UNIFIED_COMPOSER__
                wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_TRUE);
            #else /* __MMI_UNIFIED_COMPOSER__ */
            #endif /* __MMI_UNIFIED_COMPOSER__ */
            }
            break;
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
    }

#if (MMI_MAX_SIM_NUM == 1)
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
        {
            wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
        //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        #if defined(__MMI_VIDEO_TELEPHONY__)
        //#ifdef __MMI_VIDEO_TELEPHONY__
            wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
        #endif
        }
    }
    else
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
    //#ifdef __MMI_VIDEO_TELEPHONY__
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
    #endif
    }
#else /* MMI_MAX_SIM_NUM = 1 */
    if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF || !srv_sim_ctrl_any_sim_is_available())
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VOICE_CALL, MMI_FALSE);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
    //#ifdef __MMI_VIDEO_TELEPHONY__
        wgui_icon_bar_set_item_enable_state(MMI_PHB_VIDEO_CALL, MMI_FALSE);
    #endif
    }
#endif /* MMI_MAX_SIM_NUM = 1 */

#ifdef __MMI_UNIFIED_COMPOSER__
    if (!mms_is_ready())
    {
        wgui_icon_bar_set_item_enable_state(MMI_PHB_SEND_MSG, MMI_FALSE);
    }
#else /* __MMI_UNIFIED_COMPOSER__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */
    
    wgui_icon_bar_update();
}
#endif


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_fte_view_contact_tap_callback
 * DESCRIPTION
 *  fte view tap callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_fte_view_contact_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_view_contact_op_edit_entry_ext();
    }
}
#endif


static void mmi_phb_view_entry_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_view_entry_hdlr(g_mmi_phb_view_contact_p, MMI_PHB_OP_CALL_SEND_KEY);
}


void mmi_phb_view_entry_email_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_view_entry_hdlr(g_mmi_phb_view_contact_p, MMI_PHB_OP_EMAIL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_entry_send_key_hdlr
 * DESCRIPTION
 *  view entry send key handler.
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_view_entry_hdlr(mmi_phb_view_contact_cntx_struct *cntx, mmi_phb_op_action_enum op_action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_op_action_cntx_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_op_cntx_init(&op_cntx);

    op_cntx.store_index = cntx->store_index;
    op_cntx.op_action = op_action;
    
    switch (cntx->highlight_type)
    {
        case MMI_PHB_FIELD_NUMBER:
            op_cntx.data = cntx->contact->number;
            op_cntx.data_type = SRV_PHB_ENTRY_FIELD_NUMBER;
            break;
        
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            op_cntx.data = cntx->contact->opt_num[0].number;
            op_cntx.data_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            op_cntx.data = cntx->contact->opt_num[1].number;
            op_cntx.data_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:
            op_cntx.data = cntx->contact->opt_num[2].number;
            op_cntx.data_type = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
            break;
    #endif /*defined(__MMI_PHB_OPTIONAL_FIELD__) */
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_VOIP__ */
	#endif

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_EMAIL:
            if (op_action != MMI_PHB_OP_CALL_SEND_KEY)
            {
                op_cntx.data = cntx->contact->emailAddress;
                op_cntx.data_type = SRV_PHB_ENTRY_FIELD_EMAIL1;
            }
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        case MMI_PHB_FIELD_EMAIL2:
            if (op_action != MMI_PHB_OP_CALL_SEND_KEY)
            {
                op_cntx.data = cntx->contact->emailAddress2;
                op_cntx.data_type = SRV_PHB_ENTRY_FIELD_EMAIL2;
            }
            break;
    #endif
    #endif
        
        default:
            break;
    }

    mmi_phb_op_start(&op_cntx, cntx->sg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_view_entry_highlight_hdlr
 * DESCRIPTION
 *  view entry highlight handler.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static void mmi_phb_view_entry_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif

#ifndef __MMI_PHB_UI_IN_TABS__
    if (index%2 == 0)
    {
        return;
    }

    index = index/2;
#endif

    g_mmi_phb_view_contact_p->highlight_str = mmi_phb_get_str_by_field_type(g_mmi_phb_item_list[index], srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index));
    g_mmi_phb_view_contact_p->highlight_type = g_mmi_phb_item_list[index];

    //SetKeyHandler(mmi_phb_view_entry_send_key_hdlr, KEY_SEND, KEY_EVENT_UP);
	SetKeyUpHandler(mmi_phb_view_entry_send_key_hdlr, KEY_SEND);

		DisableCategory57ScreenRskBack();
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);    
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    
    SetLeftSoftkeyFunction(mmi_phb_entry_op_view_entry_options, KEY_EVENT_UP);

#ifdef __MMI_PHB_UI_IN_TABS__
    //SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetKeyDownHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW);
#endif

#ifdef __MMI_ICON_BAR_SUPPORT__
    mmi_phb_fte_contact_view_update(g_mmi_phb_view_contact_p->store_index, MMI_TRUE);
#endif

#ifndef __MMI_WGUI_DISABLE_CSK__            
#ifndef __MMI_MAINLCD_96X64__
    ChangeCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
#endif    
    
    SetCenterSoftkeyFunction(mmi_phb_view_contact_op_edit_entry_ext, KEY_EVENT_UP);
	
}

#else
static void mmi_phb_view_entry_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 storage = srv_phb_get_storage(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif



    g_mmi_phb_view_contact_p->highlight_str = mmi_phb_get_str_by_field_type(g_mmi_phb_item_list[index], srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index));
    g_mmi_phb_view_contact_p->highlight_type = g_mmi_phb_item_list[index];

	ChangeTitleString(GetString(mmi_phb_get_str_by_field_type(index, storage)));
	draw_title();
	//SetKeyHandler(mmi_phb_view_entry_send_key_hdlr, KEY_SEND, KEY_EVENT_UP);
	SetKeyUpHandler(mmi_phb_view_entry_send_key_hdlr, KEY_SEND);

}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_exit_op_view_entry
 * DESCRIPTION
 *  Exit function for mmi_phb_entry_op_view_entry()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_exit_op_view_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_RES__
    mmi_phb_stop_ring_tone_id();
#endif
}


#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_unlink_friend_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_phb_sns_unlink_friend_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_result_struct *evt;
    mmi_phb_sns_unlink_struct unlink_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&unlink_info, param->user_data, sizeof(mmi_phb_sns_unlink_struct));
    mmi_phb_mem_free(param->user_data);
    evt = (srv_sns_evt_result_struct *)param;
    if (SRV_SNS_OK != evt->result)
    {
        mmi_phb_popup_display_ext(
            STR_ID_PHB_SNS_ERROR,
            MMI_EVENT_FAILURE);
    }  
    mmi_frm_scrn_close(unlink_info.group_id, SCR_ID_PHB_SNS_PROGRESS);
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_view_unlink
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_view_unlink(U16 store_index, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_sns_unlink_struct *unlink_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unlink_info = (mmi_phb_sns_unlink_struct *)mmi_phb_mem_malloc(sizeof(mmi_phb_sns_unlink_struct), SRV_PHB_MEMORY_TYPE_CTR);
    unlink_info->contact_id = store_index;
    unlink_info->group_id = group_id;
    srv_sns_remove_contact(store_index, mmi_phb_sns_unlink_friend_callback, unlink_info);
    mmi_phb_sns_is_progress(group_id, STR_GLOBAL_PLEASE_WAIT);
}


#ifdef __MMI_SNS_MESSAGES__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_view_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_view_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_friend_struct *friend;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&friend) >= 0)
    {
        mmi_sns_new_direct_msg_launch(g_mmi_phb_view_contact_p->sg_id, friend);
    }
}
#endif


#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_view_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_sns_view_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    srv_sns_info_struct *sns_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
    {
        wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)sns_info->profile_url);
    }
}
#endif /* BROWSER_SUPPORT */
#endif


#ifdef __MMI_PHB_UI_IN_TABS__
#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_link_friend_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_phb_sns_get_friend_info_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_list_updated_struct *evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_sns_evt_list_updated_struct *)param;
    g_mmi_phb_view_contact_p->is_load_finish = MMI_TRUE;
    if (evt->total <= 0)
    {   
        mmi_phb_popup_display_ext(
            STR_ID_PHB_SNS_ERROR,
            MMI_EVENT_FAILURE);
        mmi_frm_group_close(g_mmi_phb_view_contact_p->sg_id);
    }
    else
    {
        mmi_frm_scrn_close(g_mmi_phb_view_contact_p->sg_id, SCR_ID_PHB_SNS_PROGRESS);
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sns_fill_view_item_for_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_phb_sns_fill_view_item_for_tab(U8 item_index, U16 *image_list, mmi_phb_field_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_info_struct *sns_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
	{
			switch (type)
			{
				case MMI_PHB_SNS_NAME:
                    SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_SNS_NAME));
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)(sns_info->user.user_name));
					image_list[2 * item_index] = IMG_ID_SNS_TAB_ME;
					break;

				case MMI_PHB_SNS_NUMBER:
                    if (sns_info->phone_len > 0 && sns_info->phone)
                    {
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_SNS_NUMBER));
                        SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)(sns_info->phone));
    					image_list[2 * item_index] = IMG_ID_SNS_TAB_ME;
                    }
					break;

                case MMI_PHB_SNS_BIRTHDAY:
                    if (sns_info->birthday_len > 0 && sns_info->birthday)
                    {
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_SNS_BIRTHDAY));
                        SetInlineItemDisplayOnly(&(wgui_inline_items[2 * item_index + 1]), (U8*)(sns_info->birthday));
                        image_list[2 * item_index] = IMG_ID_SNS_TAB_ME;
                    }
                    break;

                case MMI_PHB_SNS_EMAIL:
                    if (sns_info->email_len > 0 && sns_info->email)
                    {
                        WCHAR *account_name;
                        account_name = srv_sns_get_provider_name(sns_info->user.provider);
                        g_mmi_phb_view_contact_p->account_string = (WCHAR *)mmi_phb_mem_malloc(32 * sizeof(WCHAR), SRV_PHB_MEMORY_TYPE_CTR);
                        kal_wsprintf(g_mmi_phb_view_contact_p->account_string, "%w %w\n", account_name, GetString(STR_ID_PHB_SNS_EMAIL));
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*)g_mmi_phb_view_contact_p->account_string);
                        SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)(sns_info->email));
                        image_list[2 * item_index] = IMG_ID_SNS_TAB_ME;
                    }
                    break;

                case MMI_PHB_SNS_URL:
                    if (sns_info->profile_url_len > 0 && sns_info->profile_url)
                    {
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_SNS_URL));
                        SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8)(sns_info->profile_url));
                        image_list[2 * item_index] = IMG_ID_SNS_TAB_ME;
                    }
                    break;

				default:
					break;
            }
	}
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_fill_view_item_for_tab
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_op_fill_view_item_for_tab(
           U8 field_index,
           U8 item_index,
           U8 storage,
           U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0	
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */
#endif
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[2 * item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemFullWidth(&wgui_inline_items[2 * item_index]);
    SetInlineItemActivation(&wgui_inline_items[2 * item_index + 1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(mmi_phb_get_first_name_str(storage)));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->name);
        
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;

    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        case MMI_PHB_FIELD_LAST_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_LAST_NAME));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->last_name);
   
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;
    #endif
    
    #ifdef __MMI_PHB_USIM_SUPPORT__     
        case MMI_PHB_FIELD_NICK_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NICK_NAME));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->nick_name);
       
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_NAME;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;
    #endif
        case MMI_PHB_FIELD_NUMBER:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NUMBER));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->number);
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_MOBILE_NUMBER;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            #ifdef __MMI_PHB_USIM_SUPPORT__     /*for USIM  */
                if(mmi_phb_check_storage(MMI_FALSE, storage))
                {
                    if(g_mmi_phb_contact_p->opt_num[0].type == 0)
                    {
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_MOBILE_NUMBER));
                    }
                    else
                    {
                        WCHAR *label = srv_phb_get_field_type_label(
                                g_mmi_phb_contact_p->opt_num[0].type, 
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                (phb_storage_enum)storage);

                        if ((label == NULL) || (label[0] == '\0'))
                        {
                            label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                        }

                        SetInlineItemCaption(
                            &wgui_inline_items[2 * item_index],
                            (U8*)label);
                    }
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->opt_num[0].number);
                    
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                    image_list[2 * item_index] = IMG_MOBILE_NUMBER;
			        #else
			        image_list[2 * item_index] = 0;
			        #endif
                    break;
                }
                else
            #endif
                {
                    SetInlineItemCaption(
                        &wgui_inline_items[2 * item_index],
                        (U8*) GetString(mmi_phb_get_str_by_number_type(g_mmi_phb_contact_p->opt_num[0].type)));
                
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->opt_num[0].number);
                    image_list[2 * item_index] = mmi_phb_get_img_by_number_type(g_mmi_phb_contact_p->opt_num[0].type);
                    break;
                }
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            #ifdef __MMI_PHB_USIM_SUPPORT__
                if(mmi_phb_check_storage(MMI_FALSE, storage))
                {
                    if(g_mmi_phb_contact_p->opt_num[1].type == 0)
                    {
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_MOBILE_NUMBER));
                    }
                    else
                    {
                        WCHAR *label = srv_phb_get_field_type_label(
                                g_mmi_phb_contact_p->opt_num[1].type, 
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                (phb_storage_enum)storage);

                        if ((label == NULL) || (label[0] == '\0'))
                        {
                            label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                        }

                        SetInlineItemCaption(
                            &wgui_inline_items[2 * item_index],
                            (U8*) label);
                    }
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->opt_num[1].number);
                   
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                    image_list[2 * item_index] = IMG_MOBILE_NUMBER;
			        #else
			        image_list[2 * item_index] = 0;
			        #endif
                    break;
                }
                else
            #endif
                {
                    SetInlineItemCaption(
                        &wgui_inline_items[2 * item_index],
                        (U8*) GetString(mmi_phb_get_str_by_number_type(g_mmi_phb_contact_p->opt_num[1].type)));
                
               
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->opt_num[1].number);
                    image_list[2 * item_index] = mmi_phb_get_img_by_number_type(g_mmi_phb_contact_p->opt_num[1].type);
                    break;
                }

        
        case MMI_PHB_FIELD_OPT_NUM_3:
            #ifdef __MMI_PHB_USIM_SUPPORT__
                if(mmi_phb_check_storage(MMI_FALSE, storage))
                {
                    if(g_mmi_phb_contact_p->opt_num[2].type == 0)
                    {
                        SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_MOBILE_NUMBER));
                    }
                    else
                    {
                        WCHAR *label = srv_phb_get_field_type_label(
                                g_mmi_phb_contact_p->opt_num[2].type, 
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                (phb_storage_enum)storage);

                        if ((label == NULL) || (label[0] == '\0'))
                        {
                            label = (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                        }

                        SetInlineItemCaption(
                            &wgui_inline_items[2 * item_index],
                            (U8*) label);
                    }
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->opt_num[2].number);
                   
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                    image_list[2 * item_index] = IMG_MOBILE_NUMBER;
			        #else
			        image_list[2 * item_index] = 0;
			        #endif
                    break;
                }
                else
            #endif
                {
                    SetInlineItemCaption(
                        &wgui_inline_items[2 * item_index],
                        (U8*) GetString(mmi_phb_get_str_by_number_type(g_mmi_phb_contact_p->opt_num[2].type)));
               
                    SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->opt_num[2].number);
                    image_list[2 * item_index] = mmi_phb_get_img_by_number_type(g_mmi_phb_contact_p->opt_num[2].type);
                    break;
                }

        case MMI_PHB_FIELD_COMPANY_NAME:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_COMPNAY_NAME));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->companyName);
            image_list[2 * item_index] = IMG_COMPANY_NAME;
            break;

        case MMI_PHB_FIELD_EMAIL:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(mmi_phb_get_email_address_id(1,storage)));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->emailAddress);
            image_list[2 * item_index] = IMG_EMAIL_ADDRESS;
            break;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_EMAIL2_ADRESS));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->emailAddress2);
        #if 0
        #ifdef __OP01__
/* under construction !*/
        #else
/* under construction !*/
        #endif
        #else
            image_list[2 * item_index] = IMG_EMAIL_ADDRESS;
        #endif
            break;
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */    
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ /* END #ifdef __MMI_PHB_OPTIONAL_FIELD__ */

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
        #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
            {
                PU8 thumbnail_path;

                if (g_mmi_phb_res_p->image_location == MMI_PHB_IMAGE_SELECT_PATH)    /* An Image in select path */     
                {
                    thumbnail_path = (PU8)g_mmi_phb_res_p->img_path;
                }
                else
                {
                    thumbnail_path = NULL;
                }
        
                SetInlineItemCaptionThumbnail(
                    &wgui_inline_items[2 * item_index],
                    (PU8)GetString(STR_ID_PHB_CALLER_PIC),
                    thumbnail_path,
                    NULL,
                    IMG_ID_PHB_VIEW_PHOTO,
                    1);
            }
        #else
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_CALLER_PIC));
        #endif
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], g_mmi_phb_resource.image_name_list[g_mmi_phb_res_p->selected_pic_index]);
            image_list[2 * item_index] = IMG_PICTURE;
            break;

        case MMI_PHB_FIELD_RING:            

#ifdef __MMI_PHB_CALLER_RES__

			    for ( i= 0; i < g_mmi_phb_resource.total_ring_tone; ++i)
			    {
			        if (g_mmi_phb_resource.ring_tone_list[i] == g_mmi_phb_res_p->ring_id)
			        {
			            g_mmi_phb_res_p->selected_ring_index= i;
						break;
			        }
			    }	
#endif
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_CALLER_RING));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_res_p->selected_ring_index]);
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            image_list[2 * item_index] = IMG_RING_TONE;
			#else
			image_list[2 * item_index] = 0;
			#endif
            break;
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ASSOCIATE_VIDEO));
            SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], g_mmi_phb_resource.video_name_list[g_mmi_phb_res_p->selected_video_index]);
            image_list[2 * item_index] = IMG_ID_PHB_ASSOCIATE_VIDEO;
            break;
    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
    #endif /* __MMI_PHB_CALLER_RES__ */
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_BIRTHDAY));
            mmi_phb_bday_format(
                g_mmi_phb_contact_p->bday,
                g_mmi_phb_contact_p->b_day,
                g_mmi_phb_contact_p->b_month,
                g_mmi_phb_contact_p->b_year);

            SetInlineItemDisplayOnly(&(wgui_inline_items[2 * item_index + 1]), (U8*) g_mmi_phb_contact_p->bday);
            image_list[2 * item_index] = IMG_ID_PHB_BIRTHDAY;
            break;
    #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

    #if defined(__MMI_PHB_INFO_FIELD__)
          case MMI_PHB_FIELD_TITLE:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_TITLE));              
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->title);
              image_list[2 * item_index] = IMG_ID_PHB_TITLE;
              break;
        
          case MMI_PHB_FIELD_URL:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_URL));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->url);
              image_list[2 * item_index] = IMG_ID_PHB_URL;
              break;
        
          case MMI_PHB_FIELD_ADR_POBOX:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_POBOX));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->pobox);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_POBOX;
              break;
        
          case MMI_PHB_FIELD_ADR_EXTENSION:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_EXTENSION));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->extension);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_EXTENSION;
              break;
        
          case MMI_PHB_FIELD_ADR_STREET:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_STREET));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->street);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_STREET;
              break;
        
          case MMI_PHB_FIELD_ADR_CITY:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_CITY));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->city);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_CITY;
              break;
        
          case MMI_PHB_FIELD_ADR_STATE:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_STATE));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->state);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_STATE;
              break;
        
          case MMI_PHB_FIELD_ADR_POSTALCODE:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_POSTALCODE));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->postalcode);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_POSTALCODE;
              break;
        
          case MMI_PHB_FIELD_ADR_COUNTRY:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_ADR_COUNTRY));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->country);
              image_list[2 * item_index] = IMG_ID_PHB_ADR_COUNTRY;
              break;
        
        /*--- Note Field ---*/
          case MMI_PHB_FIELD_NOTE:
              SetInlineItemCaption(&wgui_inline_items[2 * item_index], (U8*) GetString(STR_ID_PHB_NOTE));
              SetInlineItemDisplayOnly(&wgui_inline_items[2 * item_index + 1], (PU8) g_mmi_phb_contact_p->note);
              image_list[2 * item_index] = IMG_ID_PHB_NOTE;
              break;
    #endif
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __USB_IN_NORMAL_MODE__
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
        #endif /* defined(IMPS_WV13_ENHANCEMENT) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_IMPS__) */
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_VOIP__) */ 
	#endif

    #ifdef __MMI_SNS_CONTACTS__
        case MMI_PHB_SNS_NAME:
	    case MMI_PHB_SNS_NUMBER:
        case MMI_PHB_SNS_BIRTHDAY:
        case MMI_PHB_SNS_EMAIL:
        case MMI_PHB_SNS_URL:
	    mmi_phb_sns_fill_view_item_for_tab(item_index, image_list, (mmi_phb_field_enum)field_index);
            break;
    #endif
    
	default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_entry_view_contact_entry_inline_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0, single_line = 0;
    U8 i = 0;
    S32 highlight_item = 0;
    U8 field_type;
    U8 storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    MMI_BOOL flag = MMI_FALSE;
#ifdef __MMI_ICON_BAR_SUPPORT__
    S32 item_count = MMI_PHB_TOOLBAR_ENUM_TOTAL - 1;
    PU8 item_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL - 1];
    PU8 item_disable_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL - 1];
    PU8 string[MMI_PHB_TOOLBAR_ENUM_TOTAL - 1];
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
			mmi_phb_cntx_mgr_get_current_sg_id(),
			SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0,
			NULL,
			mmi_phb_entry_view_contact_entry_inline_tab_0,
			MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            mmi_phb_cntx_mgr_get_current_sg_id(),
            SCR_ENTRY_VIEW,
            SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0,
            NULL,
            mmi_phb_entry_view_contact_entry_inline_tab_0,
            MMI_FRM_TAB_PAGE))
    #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));
	g_mmi_phb_view_contact_p->field_mask = SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;
		g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);

    while ((field_type = mmi_phb_edit_get_field_type(0, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_view_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_view_item_for_tab(
                field_type,
                item_index++,
                storage,
                DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_view_contact_p->first_highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_view_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index - single_line, inputBuffer);
    }
    
#ifndef __MMI_WGUI_DISABLE_CSK__    
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
#endif 


    wgui_inline_set_anykey_auto_enter(MMI_FALSE);

#ifdef __MMI_ICON_BAR_SUPPORT__
    item_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
    item_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
    item_disable_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
    item_disable_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
    string[MMI_PHB_VOICE_CALL] = (PU8)get_string(STR_GLOBAL_DIAL);
    string[MMI_PHB_SEND_MSG] = (PU8)get_string(STR_GLOBAL_SEND);
//#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#if defined(__MMI_VIDEO_TELEPHONY__)
    item_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_MEETING);
    item_disable_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_MEETING_DISABLED);
    string[MMI_PHB_VIDEO_CALL] = (PU8)get_string(STR_GLOBAL_DIAL_VIDEO_CALL);
#endif
    wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_fte_contact_view_callback);
#endif /* __MMI_ICON_BAR_SUPPORT__ */

    ShowCategory657Screen(
        STR_SCR_ENTRY_VIEW_CAPTION,
        GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index - single_line,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        MMI_PHB_INLINE_TAB_0,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */
    SetCategory57RightSoftkeyFunctions(NULL, mmi_frm_scrn_close_active_id);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_view_contact_tap_callback);
#endif /* (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_entry_view_contact_entry_inline_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0;
    S32 highlight_item = 0;
    U8 field_type;
    U8 storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    MMI_BOOL flag = MMI_FALSE;
	U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
			mmi_phb_cntx_mgr_get_current_sg_id(),
			SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1,
			NULL,
			mmi_phb_entry_view_contact_entry_inline_tab_1,
			MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            mmi_phb_cntx_mgr_get_current_sg_id(),
            SCR_ENTRY_VIEW,
            SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1,
            NULL,
            mmi_phb_entry_view_contact_entry_inline_tab_1,
            MMI_FRM_TAB_PAGE))
     #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);
    
    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));
#if 1
	#ifdef __MMI_PHB_CALLER_RES__
        mmi_phb_contact_build_res();
    #endif
	g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);
	if (mmi_phb_edit_get_total_field(1))
   {
            index = 0;
            
            while (phb_edit_default_field_tab[1][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[1][index++]);
            }
   }

#endif

    while ((field_type = mmi_phb_edit_get_field_type(1, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_view_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_view_item_for_tab(
                field_type,
                item_index++,
                storage,
                DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_view_contact_p->first_highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }


    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();

	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1);
	   	}
   #endif
    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_view_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

#ifndef __MMI_WGUI_DISABLE_CSK__    
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
#endif 	

    wgui_inline_set_anykey_auto_enter(MMI_FALSE);

    ShowCategory657Screen(
        STR_SCR_ENTRY_VIEW_CAPTION,
        GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        MMI_PHB_INLINE_TAB_1,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */
    SetCategory57RightSoftkeyFunctions(NULL, mmi_frm_scrn_close_active_id);
    
    SetCenterSoftkeyFunction(mmi_phb_view_contact_op_edit_entry_ext, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_view_contact_tap_callback);
#endif /* (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)) */
}


#ifdef __MMI_SNS_CONTACTS__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_entry_view_contact_exit_inline_tab_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_phb_view_contact_p->account_string)
    {
        mmi_phb_mem_free(g_mmi_phb_view_contact_p->account_string);
        g_mmi_phb_view_contact_p->account_string = NULL;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_entry_view_contact_entry_inline_tab_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 tab_index,item_index = 0;
    U8 i = 0;
    S32 highlight_item = 0;
    U8 field_type;
    U8 storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    MMI_BOOL flag = MMI_FALSE;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
			mmi_phb_cntx_mgr_get_current_sg_id(),
			SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2,
		#ifdef __MMI_SNS_CONTACTS__
            mmi_phb_entry_view_contact_exit_inline_tab_2,
        #else
            NULL,
        #endif
            mmi_phb_entry_view_contact_entry_inline_tab_2,
			MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            mmi_phb_cntx_mgr_get_current_sg_id(),
            SCR_ENTRY_VIEW,
            SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2,
        #ifdef __MMI_SNS_CONTACTS__
            mmi_phb_entry_view_contact_exit_inline_tab_2,
        #else
            NULL,
        #endif
            mmi_phb_entry_view_contact_entry_inline_tab_2,
            MMI_FRM_TAB_PAGE))
     #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);

#if 1
	if (mmi_phb_check_storage(MMI_TRUE, storage))
	{
		g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);
		if (mmi_phb_edit_get_total_field(2))
	   {
				index = 0;
				
				while (phb_edit_default_field_tab[2][index] != MMI_PHB_FIELD_TOTAL)
				{
					g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[2][index++]);
				}
	   }
	}
#ifdef __MMI_PHB_USIM_SUPPORT__
	else
	{
		g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);
        
        if (mmi_phb_usim_edit_get_total_field(1))
        {
            index = 0;
            //flag = MMI_FALSE;
            while (phb_usim_edit_total_field_tab[1][index] != MMI_PHB_FIELD_TOTAL)
            {
                if(mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, index, PHB_EMAIL))
                {
                    g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_usim_edit_total_field_tab[1][index++]);
                    //flag = MMI_TRUE;
                }

                 index++;
            }
        }
	}
#endif  /*__MMI_PHB_USIM_SUPPORT__*/	
#endif

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (mmi_phb_check_storage(MMI_FALSE, storage))
    {
        tab_index = 1;
    }
    else
#endif
    {
        tab_index = 2;
    }

    while ((field_type = mmi_phb_edit_get_field_type(tab_index, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_view_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_view_item_for_tab(
                field_type,
                item_index++,
                storage,
                DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_view_contact_p->first_highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_view_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }
    
#ifndef __MMI_WGUI_DISABLE_CSK__    
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 	
#endif
    wgui_inline_set_anykey_auto_enter(MMI_FALSE);

    if (phb_edit_default_field_tab[1][0] == MMI_PHB_FIELD_TOTAL)
    {
        tab_index = 1;
    }

    ShowCategory657Screen(
        STR_SCR_ENTRY_VIEW_CAPTION,
        GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        tab_index,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */
    SetCategory57RightSoftkeyFunctions(NULL, mmi_frm_scrn_close_active_id);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_view_contact_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_entry_view_contact_entry_inline_tab_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0;
    S32 highlight_item = 0;
    U8 field_type;
    U8 storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    MMI_BOOL        flag = MMI_FALSE;
    S32 tab_index = MMI_PHB_INLINE_TAB_3;
	U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
			mmi_phb_cntx_mgr_get_current_sg_id(),
			SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3,
			NULL,
			mmi_phb_entry_view_contact_entry_inline_tab_3,
			MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            mmi_phb_cntx_mgr_get_current_sg_id(),
            SCR_ENTRY_VIEW,
            SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3,
            NULL,
            mmi_phb_entry_view_contact_entry_inline_tab_3,
            MMI_FRM_TAB_PAGE))
     #endif
    {
        return;
    }

    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);
#if 1
			
			g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);
			if (mmi_phb_edit_get_total_field(3))
		   {
					index = 0;
					
					while (phb_edit_default_field_tab[3][index] != MMI_PHB_FIELD_TOTAL)
					{
						g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[3][index++]);
					}
		   }
		
#endif

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));

    while ((field_type = mmi_phb_edit_get_field_type(3, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_view_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_view_item_for_tab(
                field_type,
                item_index++,
                storage,
                DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_view_contact_p->first_highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }


    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_view_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

    for (i = 0; i < MMI_PHB_INLINE_TAB_4; i++)
    {
        if (phb_edit_default_field_tab[i][0] == MMI_PHB_FIELD_TOTAL)
        {
            tab_index--;
        }
    }

    
#ifndef __MMI_WGUI_DISABLE_CSK__	
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif 
#endif 

    wgui_inline_set_anykey_auto_enter(MMI_FALSE);

    ShowCategory657Screen(
        STR_SCR_ENTRY_VIEW_CAPTION,
        GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        tab_index,
        guiBuffer);

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);    
#endif /* __MMI_TOUCH_SCREEN__ */
    SetCategory57RightSoftkeyFunctions(NULL, mmi_frm_scrn_close_active_id);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_view_contact_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_entry_view_contact_entry_inline_tab_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 DetailPbNameImageList[2 * MAX_PB_FIELDS];
    U8 item_index = 0;
    U8 i = 0;
    S32 highlight_item = 0;
    U8 field_type;
    U8 storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    MMI_BOOL        flag = MMI_FALSE;
    S32 tab_index = MMI_PHB_INLINE_TAB_4;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	if (!cui_tab_enter(
			mmi_phb_cntx_mgr_get_current_sg_id(),
			SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_4,
			NULL,
			mmi_phb_entry_view_contact_entry_inline_tab_4,
			MMI_FRM_FULL_SCRN))
	#else
    if (!mmi_frm_scrn_tab_page_enter(
            mmi_phb_cntx_mgr_get_current_sg_id(),
            SCR_ENTRY_VIEW,
            SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_4,
            NULL,
            mmi_phb_entry_view_contact_entry_inline_tab_4,
            MMI_FRM_TAB_PAGE))
     #endif
    {
        return;
    }
    
    InitializeCategory57Screen();
    RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);
#if 1
				
				g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);
				if (mmi_phb_edit_get_total_field(4))
			   {
						index = 0;
						
						while (phb_edit_default_field_tab[4][index] != MMI_PHB_FIELD_TOTAL)
						{
							g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[4][index++]);
						}
			   }
			
#endif

    memset(DetailPbNameImageList, 0, (2 * MAX_PB_FIELDS) * sizeof(U16));

    while ((field_type = mmi_phb_edit_get_field_type(4, i++,storage)) != MMI_PHB_FIELD_TOTAL)
    {
        if (mmi_phb_edit_field_display(field_type, g_mmi_phb_view_contact_p->field_mask, storage))
        {
            g_mmi_phb_item_list[2 * item_index + 1] = field_type;
            mmi_phb_op_fill_view_item_for_tab(
                field_type,
                item_index++,
                storage,
                DetailPbNameImageList);
            /**
             * caculate highlight index
             */
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type != 0xff)
            {
                if (field_type == g_mmi_phb_view_contact_p->first_highlight_type)
                {
                    flag = MMI_TRUE;
                    highlight_item = 2 * item_index - 1;
                }
            }
        }
        else
        {
            if (!flag && g_mmi_phb_view_contact_p->first_highlight_type == field_type)
            {
                flag = MMI_TRUE;
                highlight_item = 2 * item_index - 1;
            }
        }        
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    inputBuffer = (U8*)mmi_frm_scrn_get_active_input_buf();
   #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
	   if(!guiBuffer)
	    {
	   		guiBuffer = cui_tab_get_screen_gui_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_4);
	   	}
	   if(!inputBuffer)
	    {
	   		inputBuffer = (U8 *)cui_tab_get_screen_input_buf(SCR_ENTRY_VIEW,SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_4);
	   	}
   #endif

    /**
     * Add or delete contact's details
     */
    if (flag)
    {
        guiBuffer = NULL;
        inputBuffer = NULL;
        g_mmi_phb_view_contact_p->first_highlight_type = 0xff;
    }

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2 * item_index, inputBuffer);
    }

    for (i = 0; i < MMI_PHB_INLINE_TAB_4; i++)
    {
        if (phb_edit_default_field_tab[i][0] == MMI_PHB_FIELD_TOTAL)
        {
            tab_index--;
        }
    }

#ifndef __MMI_WGUI_DISABLE_CSK__    
#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT);
#else
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
#endif 	

    wgui_inline_set_anykey_auto_enter(MMI_FALSE);

    ShowCategory657Screen(
        STR_SCR_ENTRY_VIEW_CAPTION,
        GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2 * item_index,
        DetailPbNameImageList,
        wgui_inline_items,
        highlight_item,
        tab_index,
        guiBuffer);    

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
#endif /* __MMI_TOUCH_SCREEN__ */
    SetCategory57RightSoftkeyFunctions(NULL, mmi_frm_scrn_close_active_id);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_fte_view_contact_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_view_entry
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_view_entry(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct tab_pages_info_array[5];
    U8 tab_id = 0, sel_index = 0xff;
    U8 index;
    U8 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SNS_CONTACTS__
    if (mmi_phb_sns_is_linked(g_mmi_phb_view_contact_p->store_index) && 
        g_mmi_phb_view_contact_p->is_load_finish == MMI_FALSE)
    { 
        mmi_phb_sns_is_progress(g_mmi_phb_view_contact_p->sg_id, STR_GLOBAL_PLEASE_WAIT);
        g_mmi_phb_view_contact_p->list_id = srv_sns_get_friends_by_contact(g_mmi_phb_view_contact_p->store_index);
        srv_sns_load_list(g_mmi_phb_view_contact_p->list_id, 0, mmi_phb_sns_get_friend_info_callback, NULL);
        return;
    }
#endif

    tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0;
    tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_view_contact_entry_inline_tab_0;
    tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_0);
    tab_pages_info_array[tab_id++].tab_string = NULL;   
    storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);

    g_mmi_phb_view_contact_p->field_mask = SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER;

    if (mmi_phb_check_storage(MMI_TRUE, storage))
    {
        U8 temp_tab_id = tab_id;
    #ifdef __MMI_PHB_CALLER_RES__
        mmi_phb_contact_build_res();
    #endif

        g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);

        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }

            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_view_contact_entry_inline_tab_1;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_1);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;
        
        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }

            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_view_contact_entry_inline_tab_2;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_2);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;

        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }

            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_view_contact_entry_inline_tab_3;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_3);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;
        
        if (mmi_phb_edit_get_total_field(temp_tab_id))
        {
            index = 0;
            
            while (phb_edit_default_field_tab[temp_tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_edit_default_field_tab[temp_tab_id][index++]);
            }

            tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_4;
            tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_view_contact_entry_inline_tab_4;
            tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_4);
            tab_pages_info_array[tab_id++].tab_string = NULL;
        }
        temp_tab_id++;

    #if defined(LOW_COST_SUPPORT) && !(defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__) && defined(__SRV_PHB_CALLER_RES_DATA_STORE__))
        g_mmi_phb_view_contact_p->field_mask &= ~SRV_PHB_ENTRY_FIELD_PIC;
    #endif
    }
  #ifdef __MMI_PHB_USIM_SUPPORT__
    else
    {
        MMI_BOOL flag;
        g_mmi_phb_view_contact_p->field_mask |= mmi_phb_contact_build_field_mask(g_mmi_phb_view_contact_p->contact);
        
        if (mmi_phb_usim_edit_get_total_field(tab_id))
        {
            index = 0;
            flag = MMI_FALSE;
            while (phb_usim_edit_total_field_tab[tab_id][index] != MMI_PHB_FIELD_TOTAL)
            {
                if(mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, index, PHB_EMAIL))
                {
                    g_mmi_phb_view_contact_p->field_mask |= mmi_phb_get_field_mask_by_field_type(phb_usim_edit_total_field_tab[tab_id][index++]);
                    flag = MMI_TRUE;
                }

                 index++;
            }
            if(flag)
            {
                tab_pages_info_array[tab_id].screen_id = SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2;
                tab_pages_info_array[tab_id].tab_entry_func = mmi_phb_entry_view_contact_entry_inline_tab_2;
                tab_pages_info_array[tab_id].tab_icon = (U8*)GetImage(IMG_ID_PHB_INLINE_TAB_ICON_2);
                tab_pages_info_array[tab_id++].tab_string = NULL;
            }
        }
    }
  #endif
  
    if (g_mmi_phb_view_contact_p->first_highlight_type != 0xff)
    {
    
    #ifdef __MMI_PHB_USIM_SUPPORT__
        if(mmi_phb_check_storage(MMI_FALSE, storage))
        {
            sel_index = mmi_phb_usim_edit_get_page_index(g_mmi_phb_view_contact_p->first_highlight_type);
        }
        else
    #endif
        {
            sel_index = mmi_phb_edit_get_page_index(g_mmi_phb_view_contact_p->first_highlight_type);
        }
    }

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
		if (sel_index >= tab_id)
		{
			sel_index = cui_tab_get_select_index(SCR_ENTRY_VIEW);
		}

		cui_tab_create(
			scrn_data->group_id,
        	SCR_ENTRY_VIEW,
			tab_pages_info_array,
			tab_id,
			sel_index,
			NULL);	
#else
    if (sel_index >= tab_id)
    {
        sel_index = mmi_frm_scrn_tab_get_active_page_index();
    }

    mmi_frm_scrn_tab_enter(
        scrn_data->group_id,
        SCR_ENTRY_VIEW,
        mmi_phb_exit_op_view_entry,
        (FunctionPtr)mmi_phb_entry_op_view_entry,
        tab_pages_info_array,
        tab_id,
        sel_index);
#endif
}


#else /* __MMI_PHB_UI_IN_TABS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_view_fill_item
 * DESCRIPTION
 *  Phonebook view contact, fill display items
 * PARAMETERS
 *  field_index                 [IN]              Field index for the enum value
 *  item_index                 [IN]              Item index for the inline editor
 *  entry_list                   [OUT]           String list for the data of the field
 *  title_list                     [OUT]           String list for title
 *  image_list                  [OUT]           Image list
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifndef __MMI_MAINLCD_96X64__
static MMI_BOOL mmi_phb_op_view_fill_item(
                U8 field_index,
                U8 item_index,
                U8 storage,
                CHAR **entry_list,
                U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0	
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */
#endif
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *entry_list = (CHAR *)GetString(mmi_phb_get_str_by_field_type(field_index, storage));
    *(entry_list+1) = (CHAR *)g_mmi_phb_contact_p->name;

#ifndef __MMI_SLIM_IMG_RES__
    #ifndef __MMI_PHB_SLIM__
    image_list[item_index] = mmi_phb_get_img_by_field_type(field_index);
    #endif
    image_list[item_index+1] = 0;
#endif

    entry_list++;

    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->name;
            break;
            
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->last_name;
            break;
    #endif

    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->nick_name;
            break;          
    #endif
        case MMI_PHB_FIELD_NUMBER:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->number;
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->opt_num[0].number;
        #if !defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_PHB_USIM_SUPPORT__)
            if(mmi_phb_check_storage(MMI_FALSE, storage))
            {         
            #ifndef __MMI_SLIM_IMG_RES__
                
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                image_list[item_index]= IMG_MOBILE_NUMBER;
			    #else
			    image_list[item_index]= 0;
			    #endif
            #endif

            #ifdef __MMI_PHB_USIM_SUPPORT__
                if(g_mmi_phb_contact_p->opt_num[0].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    *(entry_list-1) = (CHAR *)GetString(STR_ID_PHB_MOBILE_NUMBER);
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                                        g_mmi_phb_contact_p->opt_num[0].type, 
                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                        (phb_storage_enum)storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        *(entry_list-1) = (CHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }
                    else
                    {
                        *(entry_list-1) = (CHAR*)label;
                    }
                }
             #endif
            }
        #endif
            break;

        case MMI_PHB_FIELD_OPT_NUM_2:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->opt_num[1].number;
        #if !defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_PHB_USIM_SUPPORT__)
            if(mmi_phb_check_storage(MMI_FALSE, storage))
            {         
            #ifndef __MMI_SLIM_IMG_RES__
                image_list[item_index]= IMG_MOBILE_NUMBER;
            #endif

            #ifdef __MMI_PHB_USIM_SUPPORT__
                if(g_mmi_phb_contact_p->opt_num[1].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    *(entry_list-1) = (CHAR *)GetString(STR_ID_PHB_MOBILE_NUMBER);
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                                    g_mmi_phb_contact_p->opt_num[1].type, 
                                    MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                    (phb_storage_enum)storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        *(entry_list-1) = (CHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }
                    else
                    {
                        *(entry_list-1) = (CHAR*)label;
                    }
                }
            #endif
            }
        #endif
            break;
        
        case MMI_PHB_FIELD_OPT_NUM_3:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->opt_num[2].number;
        #if !defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_PHB_USIM_SUPPORT__)
            if(mmi_phb_check_storage(MMI_FALSE, storage))
            {
            #ifndef __MMI_SLIM_IMG_RES__
                
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
                image_list[item_index]= IMG_MOBILE_NUMBER;
			    #else
			    image_list[item_index]= 0;
			    #endif
            #endif

            #ifdef __MMI_PHB_USIM_SUPPORT__
                if(g_mmi_phb_contact_p->opt_num[2].type == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    *(entry_list-1) = (CHAR *)GetString(STR_ID_PHB_MOBILE_NUMBER);
                }
                else
                {
                    WCHAR *label = srv_phb_get_field_type_label(
                                    g_mmi_phb_contact_p->opt_num[2].type, 
                                    MMI_PHB_CONTACT_FIELD_ID_NUMBER, 
                                    (phb_storage_enum)storage);

                    if ((label == NULL) || (label[0] == '\0'))
                    {
                        *(entry_list-1) = (CHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                    }
                    else
                    {
                        *(entry_list-1) = (CHAR*)label;
                    }
                }
            #endif
            }
        #endif
            break;

        case MMI_PHB_FIELD_COMPANY_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->companyName;   
            break;

        case MMI_PHB_FIELD_EMAIL:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->emailAddress;
            break;

    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->emailAddress2;
            break;
    #endif

    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
            if (g_mmi_phb_res_p->selected_pic_index == 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                *entry_list = (CHAR *) g_mmi_phb_resource.image_name_list[g_mmi_phb_res_p->selected_pic_index];
            #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
                image_list[item_index] = IMG_ID_PHB_LIST_PHOTO;
            #endif
            }
            break;

        case MMI_PHB_FIELD_RING:
            if (g_mmi_phb_res_p->selected_ring_index == 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                *entry_list = (CHAR *) g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_res_p->selected_ring_index];
            }
            break;

        #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            if (g_mmi_phb_res_p->selected_video_index == 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                *entry_list = (CHAR *) g_mmi_phb_resource.video_name_list[g_mmi_phb_res_p->selected_video_index];
            }
            break;
        #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
        #endif /* __MMI_PHB_CALLER_RES__ */

        case MMI_PHB_FIELD_GROUP:
            result = MMI_FALSE;
            break;
        
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            if (mmi_phb_bday_format(
                    g_mmi_phb_contact_p->bday,
                    g_mmi_phb_contact_p->b_day,
                    g_mmi_phb_contact_p->b_month,
                    g_mmi_phb_contact_p->b_year))
            {
                *entry_list = (CHAR*) g_mmi_phb_contact_p->bday;
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->title;
            break;

        case MMI_PHB_FIELD_URL:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->url;
            break;

        case MMI_PHB_FIELD_ADR_POBOX:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->pobox;
            break;

        case MMI_PHB_FIELD_ADR_EXTENSION:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->extension;
            break;

        case MMI_PHB_FIELD_ADR_STREET:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->street;
            break;

        case MMI_PHB_FIELD_ADR_CITY:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->city;
            break;

        case MMI_PHB_FIELD_ADR_STATE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->state;
            break;

        case MMI_PHB_FIELD_ADR_POSTALCODE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->postalcode;
            break;

        case MMI_PHB_FIELD_ADR_COUNTRY:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->country;
            break;

        case MMI_PHB_FIELD_NOTE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->note;
            break;
    #endif /* __MMI_PHB_INFO_FIELD__ */
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
        #ifndef __MMI_SLIM_IMG_RES__
        #if !defined(IMPS_WV13_ENHANCEMENT)
        #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __USB_IN_NORMAL_MODE__
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
        #endif /* ndef (IMPS_WV13_ENHANCEMENT) */
        #endif
/* under construction !*/
    #endif /* defined(__MMI_IMPS__) */ 
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_VOIP__) */
	#endif
    
        default:
            result = MMI_FALSE;
            break;
    }

    if (!result
        || !(field_index == MMI_PHB_FIELD_NAME || field_index == MMI_PHB_FIELD_NUMBER ||(*entry_list && mmi_ucs2strlen(*entry_list) > 0))
        )
    {
        result = MMI_FALSE;
    }

    return result;
}

#else
static MMI_BOOL mmi_phb_op_view_fill_item(
                U8 field_index,
                U8 item_index,
                U8 storage,
                CHAR **entry_list,
                U16 *image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0	
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */
#endif
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	*entry_list = (CHAR *)g_mmi_phb_contact_p->name;
	

#ifndef __MMI_SLIM_IMG_RES__

    image_list[item_index] = 0;

#endif

    

    switch (field_index)
    {
        case MMI_PHB_FIELD_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->name;
            break;
            
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->last_name;
            break;
    #endif

    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->nick_name;
            break;          
    #endif
        case MMI_PHB_FIELD_NUMBER:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->number;
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->opt_num[0].number;
            break;

        case MMI_PHB_FIELD_OPT_NUM_2:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->opt_num[1].number;
            break;
        
        case MMI_PHB_FIELD_OPT_NUM_3:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->opt_num[2].number;
            break;

        case MMI_PHB_FIELD_COMPANY_NAME:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->companyName;   
            break;

        case MMI_PHB_FIELD_EMAIL:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->emailAddress;
            break;

    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            *entry_list = (CHAR *)g_mmi_phb_contact_p->emailAddress2;
            break;
    #endif

    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 

    #ifdef __MMI_PHB_CALLER_RES__
        case MMI_PHB_FIELD_PIC:
            if (g_mmi_phb_res_p->selected_pic_index == 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                *entry_list = (CHAR *) g_mmi_phb_resource.image_name_list[g_mmi_phb_res_p->selected_pic_index];
            #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
                image_list[item_index] = IMG_ID_PHB_LIST_PHOTO;
            #endif
            }
            break;

        case MMI_PHB_FIELD_RING:
            if (g_mmi_phb_res_p->selected_ring_index == 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                *entry_list = (CHAR *) g_mmi_phb_resource.ring_tone_name_list[g_mmi_phb_res_p->selected_ring_index];
            }
            break;

        #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            if (g_mmi_phb_res_p->selected_video_index == 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                *entry_list = (CHAR *) g_mmi_phb_resource.video_name_list[g_mmi_phb_res_p->selected_video_index];
            }
            break;
        #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
        #endif /* __MMI_PHB_CALLER_RES__ */

        case MMI_PHB_FIELD_GROUP:
            result = MMI_FALSE;
            break;
        
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            if (mmi_phb_bday_format(
                    g_mmi_phb_contact_p->bday,
                    g_mmi_phb_contact_p->b_day,
                    g_mmi_phb_contact_p->b_month,
                    g_mmi_phb_contact_p->b_year))
            {
                *entry_list = (CHAR*) g_mmi_phb_contact_p->bday;
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
        #endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */ 

    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->title;
            break;

        case MMI_PHB_FIELD_URL:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->url;
            break;

        case MMI_PHB_FIELD_ADR_POBOX:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->pobox;
            break;

        case MMI_PHB_FIELD_ADR_EXTENSION:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->extension;
            break;

        case MMI_PHB_FIELD_ADR_STREET:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->street;
            break;

        case MMI_PHB_FIELD_ADR_CITY:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->city;
            break;

        case MMI_PHB_FIELD_ADR_STATE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->state;
            break;

        case MMI_PHB_FIELD_ADR_POSTALCODE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->postalcode;
            break;

        case MMI_PHB_FIELD_ADR_COUNTRY:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->country;
            break;

        case MMI_PHB_FIELD_NOTE:
            *entry_list = (CHAR*) g_mmi_phb_contact_p->note;
            break;
    #endif /* __MMI_PHB_INFO_FIELD__ */
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_IMPS__) */ 
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_VOIP__) */
	#endif
    
        default:
            result = MMI_FALSE;
            break;
    }


    if(*entry_list && mmi_ucs2strlen(*entry_list) == 0)
	*entry_list=(CHAR *) (get_string(STR_GLOBAL_EMPTY));

	

    if (!result
        || !(field_index == MMI_PHB_FIELD_NAME || field_index == MMI_PHB_FIELD_NUMBER ||(*entry_list && mmi_ucs2strlen(*entry_list) > 0))
        )
    {
        result = MMI_FALSE;
    }

    return result;
}

#endif
static MMI_BOOL mmi_phb_set_viewer_flags(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index%2 == 0)
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
    }

    return MMI_TRUE;
}


#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_group_member_list_get_item
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
static S32 mmi_phb_viewer_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
        mmi_ucs2ncpy((CHAR*) menu_data[index].item_list[0], g_mmi_phb_view_contact_p->item_list[item_index + index], MAX_SUBMENU_CHARACTERS);

        menu_data[index].image_list[0] = (PU8)GetImage(g_mmi_phb_view_contact_p->img_list[item_index + index]);
    }

    return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_viewer_thumbnail_get_image_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_phb_viewer_thumbnail_get_image_path_callback(S32 index, CHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path[0] = '\0';
    path[1] = '\0';

    if ((index%2 == 0) && (g_mmi_phb_item_list[index/2] == MMI_PHB_FIELD_PIC)) /* in NVRAM */
    {
        U16 res_type;
        U16 img_id;

        srv_phb_get_image(g_mmi_phb_view_contact_p->store_index, &img_id, (U16*)path, &res_type);

        if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_viewer_thumbnail_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_phb_viewer_thumbnail_set_displayable(S32 index, MMI_BOOL displayable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_viewer_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_BOOL mmi_phb_viewer_thumbnail_get_displayable(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_viewer_thumbnail_get_menuitem_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_phb_viewer_thumbnail_get_menuitem_info(S32 item_idx, wgui_thumbnail_info_struct *menuitem_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menuitem_data->is_show_thumb = MMI_FALSE;

    if ((item_idx%2 == 0) && (g_mmi_phb_item_list[item_idx/2] == MMI_PHB_FIELD_PIC)) /* in NVRAM */
    {
        U16 res_type;
        U16 img_id;
        U16 img_path[SRV_FMGR_PATH_MAX_LEN + 1];

        srv_phb_get_image(g_mmi_phb_view_contact_p->store_index, &img_id, img_path, &res_type);

        menuitem_data->file_icon_ptr = (PU8)GetImage(IMG_STORAGE_HANDSET);

        if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
        {
        #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
            if (srv_fmgr_fs_path_exist((WCHAR*)img_path) >= 0)
            {
                menuitem_data->is_show_thumb = MMI_TRUE;
            }
        #endif
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_id_by_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_phb_get_id_by_list_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_view_entry
 * DESCRIPTION
 *  Displays the details of the selected phonebook entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_entry_op_view_entry(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *item_list[MAX_PB_FIELDS*2];
    U16 img_list[MAX_PB_FIELDS*2];
    U8 i;
    U8 field_index;
    U8 field_total;
    U8 item_index = 0;
    U8 storage = srv_phb_get_storage(g_mmi_phb_view_contact_p->store_index);
    MMI_BOOL flag = MMI_FALSE;
#ifdef __MMI_ICON_BAR_SUPPORT__
    S32 item_count = MMI_PHB_TOOLBAR_ENUM_TOTAL - 1;
    PU8 item_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL - 1];
    PU8 item_disable_icon[MMI_PHB_TOOLBAR_ENUM_TOTAL - 1];
    PU8 string[MMI_PHB_TOOLBAR_ENUM_TOTAL - 1];
#endif /* __MMI_ICON_BAR_SUPPORT__ */
    S32 highlight_item = 0;
    U8 *gui_buffer;
    U8 first_highlight_type = g_mmi_phb_view_contact_p->first_highlight_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ENTRY_VIEW,
            mmi_phb_exit_op_view_entry,
            (FunctionPtr)mmi_phb_entry_op_view_entry,
            MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        RegisterHighlightHandler(mmi_phb_view_entry_highlight_hdlr);
#ifndef __MMI_MAINLCD_96X64__
        wgui_fixed_list_register_get_flags_handler(mmi_phb_set_viewer_flags);
#endif
        if (mmi_phb_check_storage(MMI_TRUE, storage))
        {
        #ifdef __MMI_PHB_CALLER_RES__
            mmi_phb_contact_build_res();
        #endif
            field_total = MMI_PHB_FIELD_TOTAL;
        }
        #ifdef __MMI_PHB_USIM_SUPPORT__
        else
        {   
            #ifdef __MMI_PHB_OPTIONAL_FIELD__   
                field_total = MMI_PHB_FIELD_EMAIL+1;
            #else
                field_total = MMI_PHB_FIELD_NUMBER + 1;
            #endif
        }
        #else
        else
        {
            field_total = MMI_PHB_FIELD_NUMBER + 1;
        }
        #endif

        for (i = MMI_PHB_FIELD_NAME; i < field_total; i++)
        {
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            if ((i == MMI_PHB_FIELD_OPT_NUM_1) ||
                (i == MMI_PHB_FIELD_OPT_NUM_2) ||
                (i == MMI_PHB_FIELD_OPT_NUM_3))
            {
                field_index = mmi_phb_edit_get_opt_number_field((U8)(i - MMI_PHB_FIELD_OPT_NUM_1));
            }
            else
        #endif
            {
                field_index = i;
            }
#ifndef __MMI_MAINLCD_96X64__
#ifndef __MMI_PHB_SLIM__
            if (mmi_phb_op_view_fill_item(
                    field_index,
                    item_index*2,
                    storage,
                    &item_list[item_index*2],
                    img_list))
#else
            if (mmi_phb_op_view_fill_item(
                    field_index,
                    item_index*2,
                    storage,
                    &item_list[item_index*2],
                    NULL))
#endif
#else
            if (mmi_phb_op_view_fill_item(
                    field_index,
                    item_index,
                    storage,
                    &item_list[item_index],
                    img_list))
#endif
            {
                g_mmi_phb_item_list[item_index] = field_index;

                if (!flag && first_highlight_type != 0xff)
                {
                    if (first_highlight_type == field_index)
                    {
                        flag = MMI_TRUE;
                        highlight_item = item_index;
                    }
                }
                item_index++;
            }
            else
            {
                if (!flag && first_highlight_type != 0xff)
                {
                    if (first_highlight_type == field_index)
                    {
                        flag = MMI_TRUE;
                        highlight_item = item_index;
                    }
                }
            }
        }

        /* Add or delete contact's details */
        if (flag)
        {
            gui_buffer = NULL;
            first_highlight_type = 0xff;
        }
#ifndef __MMI_WGUI_DISABLE_CSK__
    #ifndef __MMI_MAINLCD_96X64__
        EnableCenterSoftkey(0, IMG_ID_PHB_CSK_EDIT); 
    #endif	
    #endif	

    #ifdef __MMI_ICON_BAR_SUPPORT__
        item_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL);
        item_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE);
        item_disable_icon[MMI_PHB_VOICE_CALL] = get_image(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
        item_disable_icon[MMI_PHB_SEND_MSG] = get_image(IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED);
        string[MMI_PHB_VOICE_CALL] = (PU8)get_string(STR_GLOBAL_DIAL);
        string[MMI_PHB_SEND_MSG] = (PU8)get_string(STR_GLOBAL_SEND);
    //#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    #if defined(__MMI_VIDEO_TELEPHONY__)
        item_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL);
        item_disable_icon[MMI_PHB_VIDEO_CALL] = get_image(IMG_GLOBAL_TOOLBAR_VIDEO_CALL_DISABLED);
        string[MMI_PHB_VIDEO_CALL] = (PU8)get_string(STR_GLOBAL_DIAL_VIDEO_CALL);
    #endif
        wgui_icon_bar_setup(item_count, item_icon, item_disable_icon, string, (GUIIconbarItemCallback)mmi_phb_fte_contact_view_callback);
    #endif /* __MMI_ICON_BAR_SUPPORT__ */

    #ifdef __MMI_SLIM_IMG_RES__
        for (i = 0; i < MAX_PB_FIELDS*2; )
        {
            img_list[i++] = gIndexIconsImageList[i/2];
            img_list[i++] = 0;
        }
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    #endif

    #ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
        mmi_phb_thumbnail_reset_displayable();
        wgui_thumbnail_register_get_image_path_func(mmi_phb_viewer_thumbnail_get_image_path_callback);
        wgui_thumbnail_register_set_displayable_func(mmi_phb_viewer_thumbnail_set_displayable);
        wgui_thumbnail_register_get_displayable_func(mmi_phb_viewer_thumbnail_get_displayable);
        wgui_thumbnail_register_get_image_info_func(mmi_phb_viewer_thumbnail_get_menuitem_info);
        wgui_thumbnail_register_get_store_id_func(mmi_phb_get_id_by_list_index);

        for (i = 0; i < MAX_PB_FIELDS*2; i++)
        {
            g_mmi_phb_view_contact_p->item_list[i] = item_list[i];
        }
        memcpy(g_mmi_phb_view_contact_p->img_list, img_list, MAX_PB_FIELDS*2*2);

        wgui_cat1034_show(
                (WCHAR*) GetString(STR_SCR_ENTRY_VIEW_CAPTION),
                (PU8) GetImage(GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID)),
                NULL,
                NULL,
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                item_index*2,
                mmi_phb_viewer_list_get_item,
                NULL,
                highlight_item*2+1,
                0,    
                IMG_ID_PHB_LIST_PHOTO,
                0,
                gui_buffer,
                NULL);
    #else
#ifndef __MMI_MAINLCD_96X64__
#ifndef __MMI_PHB_SLIM__
        ShowCategory84Screen(
            STR_SCR_ENTRY_VIEW_CAPTION,
            GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            item_index*2,
            (U8 **) item_list,
            img_list,
            WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
            highlight_item*2+1,
            gui_buffer);
#else
         ShowCategory84Screen(
            STR_SCR_ENTRY_VIEW_CAPTION,
            GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            item_index*2,
            (U8 **) item_list,
            NULL,
            WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
            highlight_item*2+1,
            gui_buffer);
#endif
#else
        ShowCategory84Screen(
            STR_SCR_ENTRY_VIEW_CAPTION,
            GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            item_index,
            (U8 **) item_list,
            NULL,
            WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
            highlight_item,
            gui_buffer);
#endif
    #endif

#ifdef __MMI_MAINLCD_96X64__ 
    ChangeLeftSoftkey(0, 0);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    #endif

    #ifdef __MMI_SLIM_IMG_RES__
        wgui_restore_list_menu_slim_style();
    #endif

    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_phb_fte_view_contact_tap_callback);
    #endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    }
}
#endif

#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_PHB_LAST_NAME_FIELD__
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
#endif /* def __MMI_IMPS__ */
#endif

#define MMI_PHB_EDITOR_UTIL

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_is_char_in_bcd
 * DESCRIPTION
 *  convert BCD string to ASCII
 * PARAMETERS
 *  dest                [IN/OUT]        An ASCII encoding string.
 *  source              [IN]            An BCD encoding string.
 *  max_dest_len        [IN]            The byte size of dest array.(include null terminate '\0')
 * RETURNS
 *  byte number after convert.
 *****************************************************************************/
MMI_BOOL mmi_phb_is_num_in_bcd(const U16* source, U8 num, U16 len_in_bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 str;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (source[i] != 0 && i < len_in_bytes)
    {
        str = (U8) source[i++];
        if (str == num)
        {
            result = MMI_TRUE;
            break;
        }
    }
    return result;
}


static U16 mmi_phb_get_email_address_id(U16 index,U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_phb_check_storage(MMI_FALSE, storage))    /*for usim*/
    {   
        return STR_EMAIL_ADRESS;
    }
    else if (index == 1)
    {
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__) && defined(__MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__)
        return STR_ID_PHB_EMAIL1_ADRESS;
    #else
        return STR_EMAIL_ADRESS;
    #endif
    }
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    else if (index == 2)
    {
        return STR_ID_PHB_EMAIL2_ADRESS;
    }
#endif
    else
    {
        MMI_ASSERT(0);
    }

    return 0;
}


#if defined(__MMI_PHB_INFO_FIELD__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_check_valid_url
 * DESCRIPTION
 *  check if the url is valid
 * PARAMETERS
 *  ucs2 url 
 * RETURNS
 *  return the url is valid or not
 *****************************************************************************/
MMI_BOOL mmi_phb_op_check_valid_url(CHAR* ucs2_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* utf8_url;
    MMI_BOOL is_url_valid = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(ucs2_url))
    {
        utf8_url = OslMalloc(MMI_PHB_URL_LENGTH + 1);
        memset(utf8_url, 0, MMI_PHB_URL_LENGTH + 1);
        mmi_ucs2_n_to_asc(utf8_url, ucs2_url, MMI_PHB_URL_LENGTH * ENCODING_LENGTH);
        if (applib_url_is_valid_ext(utf8_url, KAL_TRUE, KAL_FALSE) == 0)
        {
            is_url_valid = MMI_TRUE;
        }
        OslMfree(utf8_url);
    }
    else
    {
        is_url_valid = MMI_TRUE;
    }
    return is_url_valid;
}
#endif /* defined(__MMI_PHB_INFO_FIELD__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_op_remove_invalid_name_and_number
 * DESCRIPTION
 *  remove invalid char before add entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_entry_op_remove_invalid_name_and_number(mmi_phb_contact_info_struct *contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    S32 i;
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_remove_invalid_name(contact->name);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    srv_phb_remove_invalid_name(contact->last_name);
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
    srv_phb_remove_invalid_name(contact->nick_name);
#endif
    srv_phb_remove_invalid_number(contact->number);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_OPT_NUM_COUNT; i++)
    {
        srv_phb_remove_invalid_number(contact->opt_num[i].number);
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
}


MMI_BOOL mmi_phb_check_valid_number(U16 *number, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL valid = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_valid_number(number))
    {
        switch ((phb_storage_enum)storage)
        {
            case PHB_STORAGE_NVRAM:
        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            case PHB_STORAGE_TCARD:
        #endif
                if (!mmi_ucs2str((CHAR *) number, "?"))
                {
                    valid = MMI_TRUE;
                }
                break;
                
            case PHB_STORAGE_SIM:
        #if (MMI_MAX_SIM_NUM >= 2)
            case PHB_STORAGE_SIM2:
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
            case PHB_STORAGE_SIM3:
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            case PHB_STORAGE_SIM4:
        #endif
                if (!mmi_ucs2str((CHAR *) number, "w") && !mmi_ucs2str((CHAR *) number, "W") && !mmi_ucs2str((CHAR *) number, "?"))
                {
                    valid = MMI_TRUE;
                }
                break;
                
            default:
                break;
        }
    }

    return valid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_op_check_pre_save
 * DESCRIPTION
 *  Checks for mandatory fields for phonebook entry
 * PARAMETERS
 *  popup_error      [IN]        Popup error string
 * RETURNS
 *  the description of return value, if any.
 *****************************************************************************/
MMI_BOOL mmi_phb_op_check_pre_save(mmi_phb_contact_info_struct *contact, U8 storage, MMI_BOOL popup_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Require both name "and" numbe fields */
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
#else /* defined(__MMI_PHB_NAME_AND_NUM_REQUIRE__) */ /* Require Name "or" Number field */
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
    if (contact->name[0] == 0 &&    
    #ifdef __MMI_PHB_LAST_NAME_FIELD__    
        contact->last_name[0] == 0 &&
    #endif
        contact->number[0] == 0)
    {
        str_id = STR_ID_PHB_NAME_NUM_REQUIRE;
    }
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
    #ifdef __MMI_PHB_OPTIONAL_FIELD__   
    else if(mmi_phb_check_storage(MMI_FALSE, storage) && (!mmi_phb_check_valid_number(contact->opt_num[0].number, storage) ||
            !mmi_phb_check_valid_number(contact->opt_num[1].number, storage) ||
            !mmi_phb_check_valid_number(contact->opt_num[2].number, storage)))
    {
        str_id = STR_GLOBAL_INVALID_NUMBER;
    }
    else if (mmi_phb_check_storage(MMI_FALSE, storage) && contact->emailAddress[0] != 0 && !applib_is_valid_email_address_unicode(contact->emailAddress))
    {
        str_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
    }
    #endif
#endif
    else if (!mmi_phb_check_valid_number(contact->number, storage))
    {
        str_id = STR_GLOBAL_INVALID_NUMBER;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if (mmi_phb_check_storage(MMI_TRUE, storage) && (!mmi_phb_check_valid_number(contact->opt_num[0].number, storage) ||
            !mmi_phb_check_valid_number(contact->opt_num[1].number, storage) ||
            !mmi_phb_check_valid_number(contact->opt_num[2].number, storage)))
    {
        str_id = STR_GLOBAL_INVALID_NUMBER;
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if(mmi_phb_check_storage(MMI_TRUE, storage))
    {
        if (contact->emailAddress[0] != 0 && !applib_is_valid_email_address_unicode(contact->emailAddress))
        {
            str_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
        }
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        else if (contact->emailAddress2[0] != 0 && !applib_is_valid_email_address_unicode(contact->emailAddress2))
        {
            str_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    }
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (str_id == 0 && !mmi_phb_op_check_valid_url((CHAR*) contact->url))
    {
        str_id = STR_ID_PHB_URL_INVALID;
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

    if (str_id != 0)
    {
        if (popup_error)
        {
            mmi_popup_display_simple_ext(
                str_id,
                MMI_EVENT_FAILURE,
                g_mmi_phb_save_contact_p->sg_id,
                NULL);
        }
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_full_scr_lsk
 * DESCRIPTION
 *  Sets the LSK for Full-Screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_full_scr_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(handle_inline_full_screen_edit_complete, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(IMG_SCR_PBOOK_CAPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_full_scr_lsk_for_email
 * DESCRIPTION
 *  Sets the LSK for Full-Screen editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_full_scr_lsk_for_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(handle_inline_full_screen_edit_complete, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(IMG_SCR_PBOOK_CAPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_set_full_scr_lsk_for_number
 * DESCRIPTION
 *  Sets the LSK for number Full-Screen editor, only use in tab phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phb_set_full_scr_lsk_for_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_phb_op_email_custom_function
* DESCRIPTION
*
*
* PARAMETERS
*  void
* RETURNS
 *  the description of return value, if any.(?)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_phb_op_email_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imm_set_characters(MMI_TRUE, mmi_phb_e_mail_allowed);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_truncate_number_field_to_max_len
 * DESCRIPTION
 *  save the last MMI_PHB_NUMBER_LENGTH digit in the number field
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phb_truncate_number_field_to_max_len(U16 *ucs2_num_dest, U16 *ucs2_num_src, U16 number_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_len;
    U8 num_plus_index = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ucs2_num_dest, 0, (number_length + 1 + 1) * ENCODING_LENGTH);

    num_len = mmi_ucs2strlen((CHAR*) ucs2_num_src);

    if (num_len > number_length)
    {
        if (ucs2_num_src[0] == '+')
        {
            ucs2_num_dest[0] = ucs2_num_src[0];
            num_plus_index++;
        }

        for (i = 0; i < number_length; i++)
        {
            ucs2_num_dest[i + num_plus_index] = ucs2_num_src[num_len - number_length - 1 + i + num_plus_index];
        }
    }
    else
    {
        mmi_ucs2ncpy((CHAR*) ucs2_num_dest, (CHAR*) ucs2_num_src, number_length);
    }
}



#ifdef __MMI_PHB_USIM_SUPPORT__
MMI_BOOL mmi_phb_edit_usim_field_display(U8 field_type, U32 field_mask, U8 storage)
{
    MMI_BOOL is_display = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_type)
    {
        case MMI_PHB_FIELD_NAME:
            is_display = MMI_TRUE;
            break;

        case MMI_PHB_FIELD_NICK_NAME:
            if (mmi_phb_check_storage(MMI_FALSE, storage))
            {
                is_display = MMI_TRUE;
            }
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD__   
        case MMI_PHB_FIELD_OPT_NUM_1:           
            if (field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_1 && mmi_phb_check_storage(MMI_FALSE, storage))
            {
                is_display = MMI_TRUE;  
            }
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:           
            if (field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_2&& mmi_phb_check_storage(MMI_FALSE, storage))
            {
                is_display = MMI_TRUE;
            }   
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:   
            if (field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_3&& mmi_phb_check_storage(MMI_FALSE, storage))
            {
                is_display = MMI_TRUE;
            }   
            break;
               
        case MMI_PHB_FIELD_EMAIL:
            if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL1)
            {
                is_display = MMI_TRUE;   
            }
            break;

    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL2)
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif

    #endif /*  __MMI_PHB_OPTIONAL_FIELD__ */
    
        case MMI_PHB_FIELD_NUMBER:
            is_display = MMI_TRUE;
            break;

        case MMI_PHB_FIELD_TOTAL:
        default:
            break;
    }

    return is_display;
}
#ifdef __MMI_PHB_OPTIONAL_FIELD__

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_entry_usim_change_number_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_phb_entry_usim_change_number_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
    U8 storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_convert_to_name(
        name,
        g_mmi_phb_contact_p->name,
        NULL,
        MMI_PHB_NAME_LENGTH);

    storage = srv_phb_get_storage(g_mmi_phb_save_contact_p->store_index);

    if(storage == 0xFF)
    {
        storage = g_mmi_phb_save_contact_p->storage;
    }

    mmi_phb_entry_choose_field_ex(
        g_mmi_phb_save_contact_p->sg_id,
        name,
        storage,
        phb_edit_usim_number_type,
        0,
        mmi_phb_entry_usim_change_number_type,
        mmi_phb_usim_entry_change_number_type_done,
        mmi_frm_scrn_close_active_id);

}
#endif

#endif
static MMI_BOOL mmi_phb_edit_field_display(U8 field_type, U32 field_mask, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_display = MMI_FALSE;
#ifdef __MMI_SNS_CONTACTS__
    srv_sns_info_struct *sns_info;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_type)
    {
        case MMI_PHB_FIELD_NAME:
        case MMI_PHB_FIELD_NUMBER:
            is_display = MMI_TRUE;
            break;

    #ifdef __MMI_SNS_CONTACTS__
        case MMI_PHB_SNS_NAME:
            if (srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
            {
                if (sns_info->user.user_name_len && sns_info->user.user_name)
                {
                   is_display = MMI_TRUE; 
                }
            }
            break;
            
        case MMI_PHB_SNS_NUMBER:
            if (srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
            {
                if (sns_info->phone_len > 0 && sns_info->phone)
                {
                   is_display = MMI_TRUE; 
                }
            }
            break;
            
        case MMI_PHB_SNS_BIRTHDAY:
            if (srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
            {
                if (sns_info->birthday_len > 0 && sns_info->birthday)
                {
                   is_display = MMI_TRUE; 
                }
            }
            break;
            
        case MMI_PHB_SNS_EMAIL:
            if (srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
            {
                if (sns_info->email_len > 0 && sns_info->email)
                {
                   is_display = MMI_TRUE; 
                }
            }
            break;
            
        case MMI_PHB_SNS_URL:
            if (srv_sns_get_item2(g_mmi_phb_view_contact_p->list_id, 0, (void **)&sns_info) >= 0)
            {
                if (sns_info->profile_url_len > 0 && sns_info->profile_url)
                {
                   is_display = MMI_TRUE; 
                }
            }
            break;
    #endif
            
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
            if (mmi_phb_check_storage(MMI_TRUE, storage))
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif
    
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
            if (field_mask & SRV_PHB_ENTRY_FIELD_NICK && mmi_phb_check_storage(MMI_FALSE, storage))
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            if (field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_1)
            {
                is_display = MMI_TRUE;
            }
            break;
            
        case MMI_PHB_FIELD_COMPANY_NAME:
            if (field_mask & SRV_PHB_ENTRY_FIELD_COMPANY)
            {
                is_display = MMI_TRUE;
            }
            break;
            
        case MMI_PHB_FIELD_EMAIL:
            if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL1)
            {
                is_display = MMI_TRUE;
            }
            break;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            if (field_mask & SRV_PHB_ENTRY_FIELD_EMAIL2)
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif
    
        case MMI_PHB_FIELD_OPT_NUM_2:
            if (field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_2)
            {
                is_display = MMI_TRUE;
            }
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:
            if (field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_3)
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            if (field_mask & SRV_PHB_ENTRY_FIELD_BDAY)
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif
    
        case MMI_PHB_FIELD_PIC:
            if (field_mask & SRV_PHB_ENTRY_FIELD_PIC)
            {
                is_display = MMI_TRUE;
            }
            break;
            
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            if (field_mask & SRV_PHB_ENTRY_FIELD_VIDEO)
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif
    
        case MMI_PHB_FIELD_RING:
            if (field_mask & SRV_PHB_ENTRY_FIELD_RING)
            {
                is_display = MMI_TRUE;
            }
            break;
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            if (field_mask & SRV_PHB_ENTRY_FIELD_TITLE)
            {
                is_display = MMI_TRUE;
            }
            break;
            
        case MMI_PHB_FIELD_URL:
            if (field_mask & SRV_PHB_ENTRY_FIELD_URL)
            {
                is_display = MMI_TRUE;
            }
            break;
            
        case MMI_PHB_FIELD_ADR_POBOX:
        case MMI_PHB_FIELD_ADR_EXTENSION:
        case MMI_PHB_FIELD_ADR_STREET:   
        case MMI_PHB_FIELD_ADR_CITY:
        case MMI_PHB_FIELD_ADR_STATE:
        case MMI_PHB_FIELD_ADR_POSTALCODE:
        case MMI_PHB_FIELD_ADR_COUNTRY:
            if (field_mask & SRV_PHB_ENTRY_FIELD_ADDRESS)
            {
                is_display = MMI_TRUE;
            }
            break;
            
        case MMI_PHB_FIELD_NOTE:
            if (field_mask & SRV_PHB_ENTRY_FIELD_NOTE)
            {
                is_display = MMI_TRUE;
            }
            break;
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */ 

        default:
            break;
    }

    return is_display;
}


U8 mmi_phb_get_field_type_by_field_mask(U32 field_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 field_type = MMI_PHB_FIELD_TOTAL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_mask)
    {
        case SRV_PHB_ENTRY_FIELD_NAME:
            field_type = MMI_PHB_FIELD_NAME;
            break;

    #ifdef __MMI_PHB_USIM_SUPPORT__ 
        case SRV_PHB_ENTRY_FIELD_NICK:
            field_type = MMI_PHB_USIM_FIELD_SNE;
            break;
    #endif
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            field_type = MMI_PHB_FIELD_NUMBER;
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            field_type = MMI_PHB_FIELD_OPT_NUM_1;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            field_type = MMI_PHB_FIELD_OPT_NUM_2;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            field_type = MMI_PHB_FIELD_OPT_NUM_3;
            break;

        case SRV_PHB_ENTRY_FIELD_COMPANY:
            field_type = MMI_PHB_FIELD_COMPANY_NAME;
            break;
            
        case SRV_PHB_ENTRY_FIELD_EMAIL1:
            field_type = MMI_PHB_FIELD_EMAIL;
            break;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case SRV_PHB_ENTRY_FIELD_EMAIL2:
            field_type = MMI_PHB_FIELD_EMAIL2;
            break;
    #endif
    
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case SRV_PHB_ENTRY_FIELD_BDAY:
            field_type = MMI_PHB_FIELD_BIRTHDAY;
            break;
    #endif
    
        case SRV_PHB_ENTRY_FIELD_PIC:
            field_type = MMI_PHB_FIELD_PIC;
            break;
            
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case SRV_PHB_ENTRY_FIELD_VIDEO:
            field_type = MMI_PHB_FIELD_VIDEO;
            break;
    #endif
    
        case SRV_PHB_ENTRY_FIELD_RING:
            field_type = MMI_PHB_FIELD_RING;
            break;
    #if 0
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
    #if 0   
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        case SRV_PHB_ENTRY_FIELD_TITLE:
            field_type = MMI_PHB_FIELD_TITLE;
            break;
            
        case SRV_PHB_ENTRY_FIELD_URL:
            field_type = MMI_PHB_FIELD_URL;
            break;
            
        case SRV_PHB_ENTRY_FIELD_ADDRESS:
            field_type = MMI_PHB_FIELD_ADDRESS;
            break;
            
        case SRV_PHB_ENTRY_FIELD_NOTE:
            field_type = MMI_PHB_FIELD_NOTE;
            break;
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */
    
        default:
            break;
    }

    return field_type;
}


U32 mmi_phb_get_field_mask_by_field_type(U8 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_type)
    {
        case MMI_PHB_FIELD_NAME:
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
    #endif
            field_mask = SRV_PHB_ENTRY_FIELD_NAME;
            break;

    #ifdef __MMI_PHB_USIM_SUPPORT__
       case MMI_PHB_FIELD_NICK_NAME:
            field_mask = SRV_PHB_ENTRY_FIELD_NICK;
            break;  
    #endif

        case MMI_PHB_FIELD_NUMBER:
            field_mask = SRV_PHB_ENTRY_FIELD_NUMBER;
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_OPT_NUM_1:
            field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_2:
            field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_3:
            field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
            break;

        case MMI_PHB_FIELD_MOBILE_NUMBER:
        case MMI_PHB_FIELD_HOME_NUMBER:
        case MMI_PHB_FIELD_OFFCIE_NUMBER:
        case MMI_PHB_FIELD_FAX_NUMBER:
            field_mask = SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM;
            break;

        case MMI_PHB_FIELD_COMPANY_NAME:
            field_mask = SRV_PHB_ENTRY_FIELD_COMPANY;
            break;
            
        case MMI_PHB_FIELD_EMAIL:
            field_mask = SRV_PHB_ENTRY_FIELD_EMAIL1;
            break;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            field_mask = SRV_PHB_ENTRY_FIELD_EMAIL2;
            break;
    #endif
    
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            field_mask = SRV_PHB_ENTRY_FIELD_BDAY;
            break;
    #endif
    
        case MMI_PHB_FIELD_PIC:
            field_mask = SRV_PHB_ENTRY_FIELD_PIC;
            break;
            
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            field_mask = SRV_PHB_ENTRY_FIELD_VIDEO;
            break;
    #endif
    
        case MMI_PHB_FIELD_RING:
            field_mask = SRV_PHB_ENTRY_FIELD_RING;
            break;
            
        case MMI_PHB_FIELD_GROUP:
            break;
    #if 0        
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            field_mask = SRV_PHB_ENTRY_FIELD_TITLE;
            break;
            
        case MMI_PHB_FIELD_URL:
            field_mask = SRV_PHB_ENTRY_FIELD_URL;
            break;
            
        case MMI_PHB_FIELD_ADDRESS:
        case MMI_PHB_FIELD_ADR_POBOX:
        case MMI_PHB_FIELD_ADR_EXTENSION:
        case MMI_PHB_FIELD_ADR_STREET:   
        case MMI_PHB_FIELD_ADR_CITY:
        case MMI_PHB_FIELD_ADR_STATE:
        case MMI_PHB_FIELD_ADR_POSTALCODE:
        case MMI_PHB_FIELD_ADR_COUNTRY:
            field_mask = SRV_PHB_ENTRY_FIELD_ADDRESS;
            break;
            
        case MMI_PHB_FIELD_NOTE:
            field_mask = SRV_PHB_ENTRY_FIELD_NOTE;
            break;
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */
    
        default:
            break;
    }

    return field_mask;
}

#ifdef __MMI_PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_usim_field_mask_by_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_phb_get_usim_field_mask_by_field_mask(U32 field_mask,MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 field_type = MMI_PHB_USIM_FIELD_TOTAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_mask)
    {
        case SRV_PHB_ENTRY_FIELD_NICK:
            field_type = MMI_PHB_USIM_FIELD_SNE;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            field_type = MMI_PHB_USIM_FIELD_ANR1;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            field_type = MMI_PHB_USIM_FIELD_ANR2;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            field_type = MMI_PHB_USIM_FIELD_ANR3;
            break;

        case SRV_PHB_ENTRY_FIELD_EMAIL1:    
            field_type = MMI_PHB_USIM_FIELD_EMAIL1;
            break;
            
        default:
            break;
    }
    if(flag)
    {
        switch (field_type)
        {
            case MMI_PHB_USIM_FIELD_SNE:
                field_type = MMI_PHB_FIELD_NICK_NAME;
                break;
                
        #ifdef __MMI_PHB_OPTIONAL_FIELD__ 
            case MMI_PHB_USIM_FIELD_ANR1:
                field_type = MMI_PHB_FIELD_OPT_NUM_1;
                break;
                
            case MMI_PHB_USIM_FIELD_ANR2:
                field_type = MMI_PHB_FIELD_OPT_NUM_2;
                break;
                    
            case MMI_PHB_USIM_FIELD_ANR3:
                field_type = MMI_PHB_FIELD_OPT_NUM_3;
                break;
                
            case MMI_PHB_USIM_FIELD_EMAIL1:
                field_type = MMI_PHB_FIELD_EMAIL;
                break;
        #endif
                
            default:
                break;
        }
    }
    return field_type;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_usim_field_mask_by_field_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

U32 mmi_phb_get_usim_field_mask_by_field_type(U8 field_type,MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(flag)
    {
        switch (field_type)
        {   
            case MMI_PHB_FIELD_NICK_NAME:
                field_type = MMI_PHB_USIM_FIELD_SNE;
                break;
        #ifdef __MMI_PHB_OPTIONAL_FIELD__  
            case MMI_PHB_FIELD_OPT_NUM_1:
                field_type = MMI_PHB_USIM_FIELD_ANR1;
                break;
                
            case MMI_PHB_FIELD_OPT_NUM_2:
                field_type = MMI_PHB_USIM_FIELD_ANR2;
                break;
                    
            case MMI_PHB_FIELD_OPT_NUM_3:
                field_type = MMI_PHB_USIM_FIELD_ANR3;
                break;
        #endif
                
            default:
                break;
        }
    }
        
    switch (field_type)
        {
        case MMI_PHB_USIM_FIELD_SNE:
            field_mask = SRV_PHB_ENTRY_FIELD_NICK;
            break;
            
        case MMI_PHB_USIM_FIELD_ANR1:
            field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
            break;
            
        case MMI_PHB_USIM_FIELD_ANR2:
            field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
            break;
            
        case MMI_PHB_USIM_FIELD_ANR3:
            field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
            break;
            
        case MMI_PHB_USIM_FIELD_EMAIL1: 
            field_mask = SRV_PHB_ENTRY_FIELD_EMAIL1;
            break;
        default:
            break;
        }
    return field_mask;
  
}
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_check_usim_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_phb_check_usim_detail(U8 storage,U8 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flag = MMI_FALSE;
    U32 temp_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_mask = mmi_phb_get_usim_field_mask_by_field_type(field_type,MMI_FALSE);

    if(temp_mask == SRV_PHB_ENTRY_FIELD_NICK)
    {
        if((g_mmi_phb_save_contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NICK) == SRV_PHB_ENTRY_FIELD_NICK)
        {
            flag = MMI_FALSE;
        }
        else if(mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, 0, PHB_SNE))
        {
            flag = MMI_TRUE;
        }
            
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__        
    else if((temp_mask == SRV_PHB_ENTRY_FIELD_OPT_NUM_1) ||
            (temp_mask == SRV_PHB_ENTRY_FIELD_OPT_NUM_2) ||
            (temp_mask == SRV_PHB_ENTRY_FIELD_OPT_NUM_3))
    {
        U32 j;
        for (j = 0; j < MMI_PHB_OPT_NUM_COUNT; j++)
        {
            if (g_mmi_phb_contact_p->opt_order[j] == temp_mask)
            {
                break;
            }
        }
        if(((g_mmi_phb_save_contact_p->field_mask & temp_mask) == temp_mask))
        {
            flag = MMI_FALSE;
        }
        else if (mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, j, PHB_ANR))
        {
            flag = MMI_TRUE;
        }
    }
    else if(temp_mask == SRV_PHB_ENTRY_FIELD_EMAIL2)
    {
        //skip email1
        if(g_mmi_phb_save_contact_p->field_mask && SRV_PHB_ENTRY_FIELD_EMAIL2)
        {
            flag = MMI_FALSE;
        }
        else if(mmi_phb_check_usim_detail_ex((phb_storage_enum)storage, field_type-MMI_PHB_USIM_FIELD_EMAIL1, PHB_EMAIL))
        {
            flag = MMI_TRUE;
        }
    }
#endif    
    return flag;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_get_str_by_field_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_phb_get_str_by_field_type(U8 field_type, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_type)
    {
        case MMI_PHB_FIELD_NAME:
            str_id = mmi_phb_get_first_name_str(storage);
            break;
            
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
            str_id = STR_ID_PHB_LAST_NAME;
            break;
    #endif
    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
            str_id = STR_ID_PHB_NICK_NAME;
            break;
    #endif

        case MMI_PHB_FIELD_NUMBER:
            str_id = STR_ID_PHB_NUMBER;
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_MOBILE_NUMBER:
            str_id = STR_ID_PHB_MOBILE_NUMBER;
            break;
            
        case MMI_PHB_FIELD_HOME_NUMBER:
            str_id = STR_HOME_NUMBER;
            break;
            
        case MMI_PHB_FIELD_OFFCIE_NUMBER:
            str_id = STR_OFFICE_NUMBER;
            break;
            
        case MMI_PHB_FIELD_FAX_NUMBER:
            str_id = STR_FAX_NUMBER;
            break;
            
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
            if (mmi_phb_check_storage(MMI_TRUE, storage))
            {         
                str_id = mmi_phb_get_str_by_number_type(g_mmi_phb_contact_p->opt_num[field_type - MMI_PHB_FIELD_OPT_NUM_1].type);
            }
        #ifdef __MMI_PHB_USIM_SUPPORT__     
            else
            {            
                str_id = 0;
            }
        #endif
            break;
            
        case MMI_PHB_FIELD_COMPANY_NAME:
            str_id = STR_COMPNAY_NAME;
            break;
            
        case MMI_PHB_FIELD_EMAIL:
            str_id = mmi_phb_get_email_address_id(1,storage);
            break;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
            str_id = STR_ID_PHB_EMAIL2_ADRESS;
            break;
    #endif
    
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            str_id = STR_ID_PHB_BIRTHDAY;
            break;
    #endif
    
        case MMI_PHB_FIELD_PIC:
            str_id = STR_ID_PHB_CALLER_PIC;
            break;
            
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            str_id = STR_ID_PHB_ASSOCIATE_VIDEO;
            break;
    #endif
    
        case MMI_PHB_FIELD_RING:
            str_id = STR_ID_PHB_CALLER_RING;
            break;
            
        case MMI_PHB_FIELD_GROUP:
            break;
    #if 0        
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
    
    #if defined(__MMI_PHB_POC_FIELD__)
        case MMI_PHB_FIELD_POC:
            break;
    #endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            str_id = STR_ID_PHB_TITLE;
            break;
            
        case MMI_PHB_FIELD_URL:
            str_id = STR_ID_PHB_URL;
            break;
            
        case MMI_PHB_FIELD_ADDRESS:
            str_id = STR_ID_PHB_ADDRESS;
            break;
            
        case MMI_PHB_FIELD_ADR_POBOX:
            str_id = STR_ID_PHB_ADR_POBOX;
            break;
            
        case MMI_PHB_FIELD_ADR_EXTENSION:
            str_id = STR_ID_PHB_ADR_EXTENSION;
            break;
            
        case MMI_PHB_FIELD_ADR_STREET:
            str_id = STR_ID_PHB_ADR_STREET;
            break;
            
        case MMI_PHB_FIELD_ADR_CITY:
            str_id = STR_ID_PHB_ADR_CITY;
            break;
            
        case MMI_PHB_FIELD_ADR_STATE:
            str_id = STR_ID_PHB_ADR_STATE;
            break;
            
        case MMI_PHB_FIELD_ADR_POSTALCODE:
            str_id = STR_ID_PHB_ADR_POSTALCODE;
            break;
            
        case MMI_PHB_FIELD_ADR_COUNTRY:
            str_id = STR_ID_PHB_ADR_COUNTRY;
            break;
            
        case MMI_PHB_FIELD_NOTE:
            str_id = STR_ID_PHB_NOTE;
            break;
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_ADD_NUMBERS:
            str_id = STR_ID_PHB_ADD_MORE_NUMBER;
            break;
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

        case MMI_PHB_FIELD_TOTAL:
        default:
            break;
    }

    return str_id;
}


U16 mmi_phb_get_img_by_field_type(U8 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_type)
    {
        case MMI_PHB_FIELD_NAME:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_NAME;
			#else
			img_id = 0;
			#endif
            
            break;
            
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        case MMI_PHB_FIELD_LAST_NAME:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_NAME;
			#else
			img_id = 0;
			#endif
            break;
    #endif

    #ifdef __MMI_PHB_USIM_SUPPORT__
        case MMI_PHB_FIELD_NICK_NAME:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_NAME;
			#else
			img_id = 0;
			#endif
            break;
    #endif
        case MMI_PHB_FIELD_NUMBER:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_MOBILE_NUMBER;
			#else
			img_id = 0;
			#endif
            
            break;
            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_FIELD_MOBILE_NUMBER:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_MOBILE_NUMBER;
			#else
			img_id = 0;
			#endif
            
            break;
                
        case MMI_PHB_FIELD_HOME_NUMBER:
            img_id = IMG_HOME_NUMBER;
            break;
        case MMI_PHB_FIELD_OFFCIE_NUMBER:
            img_id = IMG_OFFICE_NUMBER;
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        case MMI_PHB_FIELD_FAX_NUMBER:
            img_id = IMG_FAX_NUMBER;
            break;
    #endif
            
        case MMI_PHB_FIELD_OPT_NUM_1:
        case MMI_PHB_FIELD_OPT_NUM_2:
        case MMI_PHB_FIELD_OPT_NUM_3:
            img_id = mmi_phb_get_img_by_number_type(g_mmi_phb_contact_p->opt_num[field_type - MMI_PHB_FIELD_OPT_NUM_1].type);
            break;

        case MMI_PHB_FIELD_COMPANY_NAME:
            img_id = IMG_COMPANY_NAME;
            break;
            
        case MMI_PHB_FIELD_EMAIL:
            img_id = IMG_EMAIL_ADDRESS;
            break;
            
    #if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
        case MMI_PHB_FIELD_EMAIL2:
	    #if 0		
        #ifdef __OP01__
/* under construction !*/
        #else
/* under construction !*/
        #endif
        #else
            img_id = IMG_EMAIL_ADDRESS;
        #endif
            break;
    #endif
    #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) */ 
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_FIELD_BIRTHDAY:
            img_id = IMG_ID_PHB_BIRTHDAY;
            break;
    #endif
    
        case MMI_PHB_FIELD_PIC:
            img_id = IMG_PICTURE;
            break;
            
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        case MMI_PHB_FIELD_VIDEO:
            img_id = IMG_ID_PHB_ASSOCIATE_VIDEO;
            break;
    #endif
    
        case MMI_PHB_FIELD_RING:
            
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_RING_TONE;
			#else
			img_id = 0;
			#endif
            break;
            
        case MMI_PHB_FIELD_GROUP:
            break;
    #if 0        
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
    
    #if defined(__MMI_PHB_POC_FIELD__)
        case MMI_PHB_FIELD_POC:
            break;
    #endif
    #if 0
    #if defined(__MMI_VOIP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_FIELD_TITLE:
            img_id = IMG_ID_PHB_TITLE;
            break;
            
        case MMI_PHB_FIELD_URL:
            img_id = IMG_ID_PHB_URL;
            break;

        case MMI_PHB_FIELD_ADDRESS:
            img_id = IMG_ID_PHB_ADDRESS;
            break;
            
        case MMI_PHB_FIELD_ADR_POBOX:
            img_id = IMG_ID_PHB_ADR_POBOX;
            break;
            
        case MMI_PHB_FIELD_ADR_EXTENSION:
            img_id = IMG_ID_PHB_ADR_EXTENSION;
            break;
            
        case MMI_PHB_FIELD_ADR_STREET:
            img_id = IMG_ID_PHB_ADR_STREET;
            break;
            
        case MMI_PHB_FIELD_ADR_CITY:
            img_id = IMG_ID_PHB_ADR_CITY;
            break;
            
        case MMI_PHB_FIELD_ADR_STATE:
            img_id = IMG_ID_PHB_ADR_STATE;
            break;
            
        case MMI_PHB_FIELD_ADR_POSTALCODE:
            img_id = IMG_ID_PHB_ADR_POSTALCODE;
            break;
            
        case MMI_PHB_FIELD_ADR_COUNTRY:
            img_id = IMG_ID_PHB_ADR_COUNTRY;
            break;
            
        case MMI_PHB_FIELD_NOTE:
            img_id = IMG_ID_PHB_NOTE;
            break;
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */
    
        case MMI_PHB_FIELD_TOTAL:
        default:
            break;
    }

    return img_id;
}


U16 mmi_phb_get_img_by_number_type(mmi_phb_num_type_enum number_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (number_type)
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_NUM_TYPE_MOBILE:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_MOBILE_NUMBER;
			#else
			img_id = 0;
			#endif
            
            break;
                
        case MMI_PHB_NUM_TYPE_HOME:
            img_id = IMG_HOME_NUMBER;
            break;
            
        case MMI_PHB_NUM_TYPE_OFFICE:
            img_id = IMG_OFFICE_NUMBER;
            break;

    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        case MMI_PHB_NUM_TYPE_FAX:
            img_id = IMG_FAX_NUMBER;
            break;
    #endif
    #endif
    
        default:
#if (!defined(__MMI_FTE_SUPPORT__) || defined(__FTE_NON_SLIM_RES__))
            img_id = IMG_MOBILE_NUMBER;
			#else
			img_id = 0;
			#endif
            
            break;
    }

    return img_id;
}


static U16 mmi_phb_get_str_by_number_type(mmi_phb_num_type_enum number_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (number_type)
    {
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case MMI_PHB_NUM_TYPE_MOBILE:
            str_id = STR_ID_PHB_MOBILE_NUMBER;
            break;
            
        case MMI_PHB_NUM_TYPE_HOME:
            str_id = STR_HOME_NUMBER;
            break;
            
        case MMI_PHB_NUM_TYPE_OFFICE:
            str_id = STR_OFFICE_NUMBER;
            break;
            
        case MMI_PHB_NUM_TYPE_FAX:
            str_id = STR_FAX_NUMBER;
            break;
    #endif
        default:
            break;
    }

    return str_id;
}


static U16 mmi_phb_get_first_name_str(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (mmi_phb_check_storage(MMI_TRUE, storage))
    {
        return STR_ID_PHB_FIRST_NAME;
    }
#endif

    return STR_ID_PHB_NAME;
}

#else /* __MMI_LOCAL_PHB_SUPPORT__ */

#include "PhonebookCore.h"

mmi_phb_contact_info_struct *g_mmi_phb_contact_p = NULL;

mmi_phb_save_contact_cntx_struct *g_mmi_phb_save_contact_p = NULL;

mmi_phb_view_contact_cntx_struct *g_mmi_phb_view_contact_p = NULL;

U16 mmi_phb_get_img_by_field_type(U8 field_type)
{
    return 0;
}

U8 mmi_phb_get_field_type_by_field_mask(U32 field_mask)
{
	return 0;
}

U16 mmi_phb_get_img_by_number_type(mmi_phb_num_type_enum number_type)
{
	return 0;
}

U16 mmi_phb_get_str_by_field_type(U8 field_type, U8 storage)
{
    return 0;
}


U32 mmi_phb_get_field_mask_by_field_type(U8 field_type)
{
    return 0;
}


void mmi_phb_truncate_number_field_to_max_len(U16 *ucs2_num_dest, U16 *ucs2_num_src, U16 number_length)
{
}


void mmi_phb_op_add_pre_entry(mmi_phb_save_contact_cntx_struct *save_cntx)
{
}


mmi_ret mmi_phb_edit_menu_cui_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


MMI_BOOL mmi_phb_op_check_pre_save(mmi_phb_contact_info_struct *contact, U8 storage, MMI_BOOL popup_error)
{
    return MMI_TRUE;
}


mmi_ret mmi_phb_sim_editor_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


mmi_ret mmi_phb_phone_editor_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
mmi_ret mmi_phb_number_editor_proc(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

mmi_ret mmi_phb_choose_storage_menu_cui_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


void mmi_phb_entry_op_view_entry(mmi_scrn_essential_struct* scrn_data)
{
}


void mmi_phb_op_add_new_entry_ext(MMI_ID parent_id)
{
}


MMI_BOOL mmi_phb_is_num_in_bcd(const U16* source, U8 num, U16 len_in_bytes)
{
    return MMI_TRUE;
}


void mmi_phb_view_entry_hdlr(mmi_phb_view_contact_cntx_struct *cntx, mmi_phb_op_action_enum op_action)
{
}


void mmi_phb_op_add_new_entry(void)
{
}

#endif /* __MMI_LOCAL_PHB_SUPPORT__ */

