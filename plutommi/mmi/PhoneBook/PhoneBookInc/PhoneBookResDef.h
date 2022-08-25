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
 *  PhoneBookResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Menu/String/Image/Screen ids for Phonebook application 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHONEBOOKRESDEF_H
#define _PHONEBOOKRESDEF_H

#ifndef __COSMOS_MMI_PACKAGE__

#if !defined(__IOT__)
#include "mmi_rp_app_phonebook_def.h"
#endif
#include "mmi_rp_srv_phb_def.h"

#include "MMIDataType.h"

/* auto add by kw_check begin */
#include "MMI_features.h"
#include "mmi_pluto_res_range_def.h"
/* auto add by kw_check end */

#if defined(__IOT__)
#define PHONE_BOOK_BASE (0)
#endif
/*
 *   Enum for phonebook option list item number, for populate resource
 */
typedef enum
{
#if 0
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
#endif
#endif
    MMI_PHB_OPTION_VIEW,
    MMI_PHB_OPTION_EDIT,
#if defined(__MMI_PHB_INFO_FIELD__)
    MMI_PHB_OPTION_EDIT_DETAIL,
#endif 
#if 0
#if defined(__MMI_IMPS__) || defined(__MMI_PHB_POC_FIELD__) || defined(__MMI_VOIP__)
/* under construction !*/
#endif 
#else
#if defined(__MMI_PHB_POC_FIELD__)
    MMI_PHB_OPTION_EDIT_SERVICE_FIELD,
#endif 
#endif 
    MMI_PHB_OPTION_DELETE,

#if defined(__MMI_VCARD__)
    MMI_PHB_OPTION_VCARD,
#endif 
#if defined(__MMI_BPP20_SUPPORT__)
    MMI_PHB_OPTION_PRINT,
#endif	
    MMI_PHB_OPTION_MOVE,
    MMI_PHB_OPTION_NO_SIM_TOTAL = MMI_PHB_OPTION_MOVE,

    MMI_PHB_OPTION_DIAL,     /* Dial from phonebook entry option menu */
#if defined(__IP_NUMBER__)
    MMI_PHB_OPTION_IP_DIAL,     /* IP Dial from phonebook entry option menu */
#endif 
#if defined(__MMI_PHB_SEND_SMS_FROM_PHB__)
    MMI_PHB_OPTION_SEND_SMS,    /* Send SMS from phonebook entry option menu */
#endif 
#if 0
#if defined(__MMI_PHB_SEND_MMS_FROM_PHB__)
/* under construction !*/
#endif
#endif
#if defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__)
    MMI_PHB_OPTION_SEND_POSTCARD,
#endif /* defined(__MMI_MMS_POSTCARD__) && defined(__MMI_PHB_INFO_FIELD__) */

    MMI_PHB_OPTION_COPY,
#if 0    
#if defined(__MMI_VRSD_DIAL__)
/* under construction !*/
#endif 
#endif 
    MMI_PHB_OPTION_ENUM_TOTAL
} mmi_phb_option_num_enum;


typedef enum
{
	MMI_PHB_OWNER_NUMBER,
#if (MMI_MAX_SIM_NUM >=2)
	MMI_PHB_CARD2_OWNER_NUMBER,
#endif
    MMI_PHB_FDN_NUMBER,
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_PHB_CARD2_FDN_NUMBER,
#endif
    MMI_PHB_BDN_NUMBER,
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_PHB_CARD2_BDN_NUMBER,
#endif
	MMI_PHB_SDN_NUMBER,
#if (MMI_MAX_SIM_NUM >= 2)
	MMI_PHB_CARD2_SDN_NUMBER,
#endif
	MMI_PHB_SOS_NUMBER,
#if (MMI_MAX_SIM_NUM >= 2)
	MMI_PHB_CARD2_SOS_NUMBER,
#endif
#if 0
#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
/* under construction !*/
#endif
#endif
    MMI_PHB_EXTRA_NUM_ENUM_TOTAL
} mmi_phb_extra_num_enum;


#if defined(__MMI_PHB_MULTI_OPERATION__)
typedef enum
{
    MMI_PHB_MULTI_OP_OPTION_SELECT_ALL,
    MMI_PHB_MULTI_OP_OPTION_UNSELECT_ALL,
    MMI_PHB_MULTI_OP_OPTION_SELECT_ALL_FROM_SIM,
    MMI_PHB_MULTI_OP_OPTION_UNSELECT_ALL_FROM_SIM,
    MMI_PHB_MULTI_OP_OPTION_SELECT_ALL_FROM_PHONE,
    MMI_PHB_MULTI_OP_OPTION_UNSELECT_ALL_FROM_PHONE,
    MMI_PHB_MULTI_OP_OPTION_COPY_SELECTED,
    MMI_PHB_MULTI_OP_OPTION_DELETE_SELECTED,
#ifdef __MMI_UDX_VCARD_SUPPORT__
    MMI_PHB_MULTI_OP_OPTION_BUILD_UDX,
#endif
    MMI_PHB_MULTI_OP_OPTION_ENUM_TOTAL
} mmi_phb_multi_operation_option_enum;
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */

/* screen ids */
typedef enum
{
    SCR_PBOOK_MAIN_MENU = PHONE_BOOK_BASE + 1,
    SCR_PBOOK_LIST,
    SCR_SEARCH_NAME_ENTRY,
    SCR_PBOOK_ENTRY_OPTIONS,
    SCR_IN_PROGRESS_PHB,
    SCR_ID_PHB_SPECIAL_NUMBER,
    SCR_PBSETTINGS_LIST,
    SCR_VIEW_FIELDS,
    SCR_SAVE_FIELDS_QUERY,
    SCR_STORAGE_LOCATION_OPTIONS,
    SCR_DELETE_ALL_MENU,
    SCR_ID_DELETE_ALL_CHECK_PHONE_LOCK,
    SCR_STORAGE_LOCATION_MENU,
    SCR_MEMORY_STATUS,
    SCR_CALLER_GROUPS,
    SCR_CALLER_GROUPS_SELECT,    /* __MMI_PHB_GROUP_MEMBER_MOVE_SUPPORT__ */
    SCR_CALLER_GRP_DETAILS,
    SCR_ID_PHB_CALLERGROUP_MEMBER_LIST,             /* MTK 2004-02-10 Wilson. Caller Group Member List */
    SCR_ID_PHB_CALLERGROUP_MEMBER_VIEW_OPTION,      /* MTK 2004-02-10 Wilson. Caller Group Member List */
    SCR_ID_PHB_CALLERGROUP_MEMBER_DELETE_MEMBER,    /* MTK 2004-02-10 Wilson. Caller Group Member List */
    SCR_ID_PHB_NO_GROUP,
    SCR_OWNER_NUMBERS,
    SCR_OWNER_NUMBER_OPTIONS,
    SCR_OWNER_NUMBER_EDIT,
    SCR_COPY_ALL_MENU,
    SCR_PHB_DUMMY,
    SCR_ID_PHB_PROCESSING,
    SCR_ENTRY_VIEW,
    SCR_INLINE_EDIT,
    SCR_ID_PHB_EDIT_DETAIL,
    SCR_ID_PHB_EDIT_SERVICE_FIELD,
    SCR_ADD_NEW_ENTRY,
    SCR_SEARCH_OPTIONS,
    SCR_CHOOSE_NUMBER,
    SCR_SOS_DISPLAY,
    SCR_ENTER_SOS_NUMBER,
    SCR_ID_PHB_SPEED_DIAL,
    SCR_SPEED_DIAL_LIST,
    SCR_DIRECT_DIAL_LIST,
    SCR_DIRECT_DIAL_EDIT,
    SCR_ID_SPEED_DIAL_SET_NUM_OPTION,
    SCR_SDN_LIST,
    /* CF5 ICE */
    SCR_ID_PHB_ICE_CONTACT,
    SCR_ID_OPTION_COPY_DUPLICATE,
    SCR_ID_PHB_OPTION_COPY,
    SCR_ID_PHB_OPTION_MOVE,
    SCR_COPY_ENTRY_QUERY,
    SCR_DELETE_ENTRY_QUERY,
    SCR_DELETE_ALL_QUERY,
    SCR_SAVE_QUERY,
    SCR_ID_PHB_ADD_ABORT_CONFIRM,
    SCR_ID_PHB_DS_OPTIONS,
    SCR_ID_PHB_DS_SWITCH,
    SCR_MOVE_QUERY,
    SCR_DUPLICATE_QUERY,
    SCR_SAVE_CALLER_GRP,
    SCR_COPY_FROM_PHONE,
    SCR_COPY_FROM_SIM,
    SCR_EDIT_ENTRY_QUERY,
    SCR_OWN_NUM_ERASE,
    SCR_OWN_NUM_EDIT,
    SCR_CONFIRM_SOS_CALL,
    SCR_VIEW_PICTURE,
    SCR_COPY_ALL_PROGRESS,
    SCR_ID_PHB_MMS_CHOOSE_ENTRY,
    SCR_ID_PHB_VCARD_MYCARD,
    SCR_ID_PHB_VCARD_EDIT_MYCARD,
    SCR_ID_PHB_VCARD_CONFIRM_SAVE_MYCARD,
    SCR_ID_PHB_IMAGE_OPTION,
    SCR_ID_PHB_IMAGE_VIEW_IMAGE,
    SCR_ID_PHB_FMGR_SAVE_OPTION,
    SCR_ID_PHB_QUICK_SEARCH_LIST,                   /* MTK 2004-04-27 Wilson, Quick Search */
    SCR_ID_PHB_QUICK_SEARCH_OPTION,
    SCR_ID_PHB_REFRESH_SIM_CONFIRM,
    SCR_ID_PHB_SORTING_EMAIL,
    SCR_ID_PHB_VIDEO_OPTION,
    SCR_ID_PHB_VIDEO_PREVIEW,
    SCR_ID_PHB_VIDEO_VIEW,
    SCR_ID_PHB_EDIT_VOIP,
    SCR_ID_PHB_EDIT_VOIP_OPTIONS,
    SCR_ID_PHB_CALLER_VIDEO,
    SCR_ID_PHB_CALLER_PIC,
    SCR_ID_PHB_SWFLASH_OPTION,
    SCR_ID_PHB_SWFLASH_PREVIEW,
    SCR_ID_PHB_SWFLASH_VIEW,    
    SCR_ID_PHB_NAME_LIST_FILTER_OPTIONS,
    SCR_ID_PHB_GENERIC_QUICK_SEARCH_LIST,
    SCR_ID_PHB_GENERIC_QUICK_SEARCH_OPTIONS,
    SCR_ID_PHB_AVATAR_IMAGE_OPTION,
    SCR_ID_PHB_AVATAR_VIDEO_OPTION,
    SCR_ID_PHB_MULTI_OP_OPTION,
    SCR_ID_PHB_MULTI_OP_PHB_LIST,
    SCR_ID_PHB_GENERIC_MULTI_SELECT,
    SCR_ID_PHB_GENERIC_MULTI_SELECT_AND_QUICK_SEARCH_OPTIONS,
    SCR_ID_PHB_GENERIC_MULTI_SELECT_AND_QUICK_SEARCH,
    SCR_ID_PHB_SPEAK_NAME_OPTIONS,
    /* vcard 3.0 */
    SCR_ID_PHB_VCARD_VERSION_OPTIONS,
    /* phonebook vip contact */
    SCR_ID_PHB_VIP_CONTACT_LIST,
    SCR_ID_PHB_VIP_CONTACT_LIST_OPTION,
    SCR_ID_PHB_VIP_CONTACT_DATA_OPTION,
    SCR_ID_PHB_VIP_CONTACT_DATA_SEND_MESSAGE,
    /* phonebook vip contact */
    /* for tab entry edit entry */
    SCR_ID_PHB_ADD_CONTACT_INLINE_TAB_0,
    SCR_ID_PHB_ADD_CONTACT_INLINE_TAB_1,
    SCR_ID_PHB_ADD_CONTACT_INLINE_TAB_2,
    SCR_ID_PHB_ADD_CONTACT_INLINE_TAB_3,
    SCR_ID_PHB_ADD_CONTACT_INLINE_TAB_4,
    SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_0,
    SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_1,
    SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_2,
    SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_3,
    SCR_ID_PHB_EDIT_CONTACT_INLINE_TAB_4,
    SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_0,
    SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_1,
    SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_2,
    SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_3,
    SCR_ID_PHB_VIEW_CONTACT_INLINE_TAB_4,
    SCR_ID_PHB_MARK_SEVERAL_TAB_0,
    SCR_ID_PHB_MARK_SEVERAL_TAB_1,
    SCR_ID_PHB_MARK_SEVERAL_SELECT_NUMBER,
    SCR_ID_PHB_MARK_SEVERAL_SELECT_NUMBER_FOR_GROUP,
    SCR_ID_PHB_TAB_EDIT_NUM,
    SCR_ID_PHB_TAB_EDIT_CALLER_PIC,
    SCR_ID_PHB_TAB_EDIT_CALLER_VIDEO,
    SCR_ID_PHB_TAB_EDIT_CALLER_RINGTONE,
    SCR_ID_PHB_TAB_EDIT_CALLER_GROUP,
    SCR_ID_PHB_TAB_EDIT_BIRTHDAY,
    SCR_ID_PHB_TAB_EDIT_PREFERRED_NUM,
    SCR_ID_PHB_PIC_OPTION,
    SCR_ID_PHB_EDIT_ENTRY_OPTION,
    SCR_ID_PHB_EDIT_NUM_OPTION,
    SCR_ID_PHB_SAVE_CONTACT_OPT,
    SCR_ID_PHB_SAVE_CONTACT_OPT_UPDATE_LIST,
    SCR_ID_PHB_SEND_MESSAGE,
    SCR_ID_PHB_COPY_SEVERAL,
    SCR_ID_PHB_MOVE_SEVERAL,
    SCR_ID_PHB_CALLER_GROUP_OP,
    SCR_ID_PHB_CALLER_GROUP_MEMBERS_LIST_OP,
    SCR_ID_PHB_CALLER_GROUP_EDIT_CALLER_ALERT,
    SCR_ID_PHB_CALLER_GROUP_EDIT_CALLER_LED,
    SCR_ID_PHB_OPTION_SEND_MESSAGE,
    SCR_ID_PHB_VIEW_ENTRY_0PTION,
    SCR_ID_PHB_COMMON_LIST,
    SCR_ID_PHB_CONTACT_EIDT_GROUP_INFO,  /* __MMI_PHB_GROUP_ENHANCE__ */
    SCR_ID_PHB_CONTACT_VIEW_GROUP_INFO,
    /* __MMI_SNS_CONTACTS__ */
    SCR_ID_PHB_SNS_TAB0,
    SCR_ID_PHB_SNS_TAB1,
    SCR_ID_PHB_SNS_PROGRESS,
    SCR_ID_PHB_SNS_QUERY,
#ifdef __VCARD_CLOUD_SUPPORT__
    SCR_ID_PHB_CLOUD_LIST,
    SCR_ID_PHB_CLOUD_PROGRESS,
    SCR_ID_PHB_CLOUD_POPUP,
#endif
    /* pls add phonebook internal screen before this, then it will be cleared , while exec clear old history function */
    SCR_ID_PHB_INTERNAL_SCREEN_TOTAL,

    
    /* VF UE - PB copy SIM when startup */
    SCR_ID_PHB_STARTUP_COPY_SIM,
    SCR_ID_PHB_STARTUP_COPY_SIM2,
    SCR_ID_PHB_STARTUP_COPY_SIM3,
    SCR_ID_PHB_STARTUP_COPY_SIM4,

    /* phonebook unsaved contact */
    SCR_ID_PHB_SAVE_CONTACT_NOTIFY_OPTIONS,
    SCR_ID_PHB_UNSAVED_DATA_CONFIRM,
    SCR_ID_PHB_UNSAVED_DATA_OPTIONS,
    SCR_ID_PHB_UNSAVED_DATA_LIST,
    SCR_ID_PHB_UPDATE_DATA_LIST,

    /* phonebook for matv */
    SCR_ID_MATV_SMS_PHB_LIST,

    SCR_ID_PHB_PBAP_LIST,
    
    SCR_ID_PHB_PBAP_LIST2,
    
    SCR_ID_PHB_PBAPC_VIEW_CONTACT,
    
    SCR_ID_PHB_PBAP_VIEW_CONTACT_DETAIL,

    SCR_ID_PHB_PBAPC_SEL_OP_NUM,

    /* cui sel contact */
    SCR_ID_PHB_PBAPC_TAB,
    SCR_ID_PHB_PBAPC_LOCAL,
    SCR_ID_PHB_PBAPC_BT,
    SCR_ID_PHB_PBAPC_BT1,

    SCR_ID_PHB_ENUM_TOTAL
    
} SCREENID_LIST_PHONE_BOOK;

#define CUI_PHB_SAVE_CONTACT_COUNT              1
#define CUI_PHB_VIEW_CONTACT_COUNT              1
#define CUI_PHB_SELECT_CONTACT_COUNT            5
#define CUI_PHB_MULTI_SELECT_CONTACT_COUNT      2
#define CUI_PHB_LIST_GROUP_COUNT                1

typedef enum
{
    /* Screen Group ID, pls don't change the order, and add screen Id before this */
    GRP_ID_PHB_BEGIN = SCR_ID_PHB_ENUM_TOTAL + 1,
    GRP_ID_PHB_MAIN = GRP_ID_PHB_BEGIN,
#if !defined (__MMI_PHB_UI_IN_TABS__) && defined (__MMI_PHB_PBAPC_SYNC_CONTACT__)
    GRP_ID_PHB_LIST,
#endif
    GRP_ID_PHB_CUI_SAVE,
    GRP_ID_PHB_CUI_VIEW = GRP_ID_PHB_CUI_SAVE + CUI_PHB_SAVE_CONTACT_COUNT,
    GRP_ID_PHB_CUI_LIST = GRP_ID_PHB_CUI_VIEW + CUI_PHB_VIEW_CONTACT_COUNT,
    GRP_ID_PHB_CUI_LIST_MULTI = GRP_ID_PHB_CUI_LIST + CUI_PHB_SELECT_CONTACT_COUNT,
    GRP_ID_PHB_CUI_LIST_GROUP_TAB = GRP_ID_PHB_CUI_LIST_MULTI + CUI_PHB_MULTI_SELECT_CONTACT_COUNT,

    GRP_ID_PHB_MARK_SEVERAL = GRP_ID_PHB_CUI_LIST_GROUP_TAB + CUI_PHB_LIST_GROUP_COUNT,
    GRP_ID_PHB_OP_ALL,
    GRP_ID_PHB_RES,
    GRP_ID_PHB_GROUP,
    GRP_ID_PHB_SETTING,
    GRP_ID_PHB_EXTRA_NUMBER,
    GRP_ID_PHB_SPEED_DIAL,
    GRP_ID_PHB_DIRECT_DIAL,
    GRP_ID_PHB_VIP_CONTACT,
    GRP_ID_PHB_MY_NUMBER,
    GRP_ID_PHB_COPY_SIM_DATA,
    GRP_ID_PHB_URIAGENT,
    GRP_ID_PHB_SAVE_NOTIFY,
    GRP_ID_PHB_DIALER_SEARCH,
    GRP_ID_PHB_SC,
    GRP_ID_CHOOSE_FIELD,
    GRP_ID_PHB_MATV_GROUP,
    GRP_ID_PHB_PBAP_OP_OPTION,
    GRP_ID_PHB_PBAP_SETTING,
    GRP_ID_PHB_PBAPC_VIEW_CONTACT,

    GRP_ID_PHB_PBAPC_SELECT_CONTACT,
    
    GRP_ID_PHBLIST_PBAPC_SELECT_CONTACT,

    /* Screen Group ID, pls don't change the order, and add new SG Id before this */
    GRP_ID_PHB_END
} grp_id_phb_enum;

typedef enum
{
    /* Inline CUI Item ID */
    INLINE_ID_PHB_BEGIN = GRP_ID_PHB_END + 1,
    INLINE_ID_PHB_NAME = INLINE_ID_PHB_BEGIN,
    INLINE_ID_PHB_EXTRA_NAME,
    INLINE_ID_PHB_NUMBER,
    INLINE_ID_PHB_EXTRA_NUMBER,

    INLINE_ID_PHB_ICE_BEGIN,
    INLINE_ID_PHB_ICE1_CAPTION = INLINE_ID_PHB_ICE_BEGIN,
    INLINE_ID_PHB_ICE1_NUMBER,
    INLINE_ID_PHB_ICE2_CAPTION,
    INLINE_ID_PHB_ICE2_NUMBER,
    INLINE_ID_PHB_ICE3_CAPTION,
    INLINE_ID_PHB_ICE3_NUMBER,
    INLINE_ID_PHB_ICE_END = INLINE_ID_PHB_ICE3_NUMBER,

    INLINE_ID_PHB_FIRST_NAME,
    INLINE_ID_PHB_LAST_NAME,
    INLINE_ID_PHB_MOBILE_NUMBER,
    INLINE_ID_PHB_HOME_NUMBER,
    INLINE_ID_PHB_OFFICE_NUMBER,
    INLINE_ID_PHB_FAX_NUMBER,
    INLINE_ID_PHB_OPTION_NUMBER_1,
    INLINE_ID_PHB_OPTION_NUMBER_2,
    INLINE_ID_PHB_OPTION_NUMBER_3,
    INLINE_ID_PHB_COMPANY_NAME,
    INLINE_ID_PHB_EMAIL_ADDR,
    INLINE_ID_PHB_EMAIL_ADDR2,

    INLINE_ID_PHB_GROUP_NAME_CAPTION,
    INLINE_ID_PHB_GROUP_NAME,
    INLINE_ID_PHB_GROUP_PICTURE_CAPTION,
    INLINE_ID_PHB_GROUP_PICTURE,
    INLINE_ID_PHB_GROUP_RINGTONE_CAPTION,
    INLINE_ID_PHB_GROUP_RINGTONE,
    INLINE_ID_PHB_GROUP_VIDEO_CAPTION,
    INLINE_ID_PHB_GROUP_VIDEO,

    /* Inline CUI Item ID, pls add new item Id before this */
    INLINE_ID_PHB_END
} inline_id_phb_enum;


/* Phonebook resource menu items */
typedef enum
{
#if defined(__MMI_PHB_QUICK_SEARCH__)
    MMI_PHB_MAIN_QUICK_SEARCH,
#endif 
    MMI_PHB_MAIN_SEARCH_ENTRY,
    MMI_PHB_MAIN_NEW_ENTRY,
#if defined(__MMI_PHB_MULTI_OPERATION__)
    MMI_PHB_MAIN_MULTI_OP,
#else /* defined(__MMI_PHB_MULTI_OPERATION__) */
    MMI_PHB_MAIN_DELETE_ALL,
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
    MMI_PHB_MAIN_CALLER_GROUPS,
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    MMI_PHB_MAIN_SYNC,
#endif
    MMI_PHB_MAIN_SETTINGS,
    MMI_PHB_MAIN_EXTRA_NUMBER,
    MMI_PHB_MAIN_NO_SIM_ENUM_TOTAL = MMI_PHB_MAIN_EXTRA_NUMBER,
#if !defined(__MMI_PHB_MULTI_OPERATION__)
    MMI_PHB_MAIN_COPY_ALL,
#endif /* defined(__MMI_PHB_MULTI_OPERATION__) */
    MMI_PHB_MAIN_ENUM_TOTAL
} mmi_phb_main_menu_enum;

#if 0
#if defined(__MMI_SWFLASH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif

#endif

#endif /* _PHONEBOOKDEFRES_H */ 

