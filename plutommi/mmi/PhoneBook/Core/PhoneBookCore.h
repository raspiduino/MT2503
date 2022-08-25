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
 *  PhonebookCore.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is to maintain phonebook scenarios 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PHONEBOOK_CNTX_MGR_H
#define _PHONEBOOK_CNTX_MGR_H

#ifndef __RESOURCE_GEN_
#include "MMIDataType.h"
#include "Custom_phb_config.h"
#include "FileMgrGprot.h"
#include "FileMgrSrvGProt.h"
#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "PhoneBookResDef.h"
#include "FileMgrCuiGprot.h"

/* auto add by kw_check begin */
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "customer_email_num.h"
#include "MMI_features.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
/* auto add by kw_check end */

#if defined(__MMI_BT_PBAP_CLIENT__)
#include "PhbPbapSrvGprot.h"
#endif

#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvTypes.h"
#include "gdi_include.h"
#endif
#endif
/*undefine more detail in internal version*/
/*
#ifdef __MMI_PHB_OPTIONAL_FIELD__
#ifndef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
#define __MMI_PHB_SIM_NUMBER_MANAGEMENT__
#endif
#endif
*/

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#define MMI_PHB_MAX_DYNAMIC_SIM_NAME_LENGTH 64
#endif

#define MMI_PHB_LOG(x)                                  MMI_TRACE(MMI_PHB_TRACE_GROUP, x)
#define MMI_PHB_LOG1(x, x1)                             MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1)
#define MMI_PHB_LOG2(x, x1, x2)                         MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1, x2)
#define MMI_PHB_LOG3(x, x1, x2, x3)                     MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1, x2, x3)
#define MMI_PHB_LOG4(x, x1, x2, x3, x4)                 MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1, x2, x3, x4)
#define MMI_PHB_LOG5(x, x1, x2, x3, x4, x5)             MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1, x2, x3, x4, x5)
#define MMI_PHB_LOG6(x, x1, x2, x3, x4, x5, x6)         MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1, x2, x3, x4, x5, x6)
#define MMI_PHB_LOG7(x, x1, x2, x3, x4, x5, x6, x7)     MMI_TRACE(MMI_PHB_TRACE_GROUP, x, x1, x2, x3, x4, x5, x6, x7)

#if defined(__MMI_BT_PBAP_CLIENT__)
/*
#ifdef __MMI_SNS_CONTACTS__
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (5)
#elif defined(__MMI_PHB_CALLER_GROUP__)
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (3)
#else
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (2)
#endif
*/
#if defined(__MMI_SNS_CONTACTS__) && defined(__MMI_PHB_CALLER_GROUP__)
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (4 + SRV_PBAPC_LINK_NUM)
#endif

#if defined(__MMI_SNS_CONTACTS__) && !defined(__MMI_PHB_CALLER_GROUP__)
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (3 + SRV_PBAPC_LINK_NUM)
#endif

#if !defined(__MMI_SNS_CONTACTS__) && defined(__MMI_PHB_CALLER_GROUP__)
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (2 + SRV_PBAPC_LINK_NUM)
#endif

#if !defined(__MMI_SNS_CONTACTS__) && !defined(__MMI_PHB_CALLER_GROUP__)
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (1 + SRV_PBAPC_LINK_NUM)
#endif
#else /* defined(__MMI_BT_PBAP_CLIENT__) */
#ifdef __MMI_SNS_CONTACTS__
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (4)
#elif defined(__MMI_PHB_CALLER_GROUP__)
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (2)
#else
#define MMI_PHB_MAIN_SCREEN_TAB_COUNT                  (1)
#endif
#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

#ifdef __MMI_SNS_CONTACTS__
#define MMI_PHB_SNS_FAVORITE_MAX_NUM                    50 
#define MMI_PHB_SNS_PROVIDER_IMAGE_NUM                  3
#endif

#define MMI_PHB_LIST_DFAULT_FILTER                      (SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_NUMBER) /* contact list default filter */
#define MMI_PHB_STORE_INDEX_INVALID                     0xffff            /* invalid store index */
#define MMI_PHB_SG_INVALID_HANDLE                       0xffff            /* invalid sg handle */

#if defined(__MMI_PHB_CALLER_VIDEO__)
#define MAX_PB_VIDEO_TAGS                               30                /* Max Video tags allowed */
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */ 

#define MAX_PB_PICTURES_TAGS                            30                /* Max Pictures tags allowed */
#define MAX_PB_RING_TONES                               60                /* max ringtone tags allowed */
#if !defined(HARDWARE_LED_NOT_SUPPORT)
#define MAX_PB_ALERT_TYPES                              5                 /* max alert types allowed */
#else 
#define MAX_PB_ALERT_TYPES                              4                 /* max alert types allowed */
#endif 
#define MAX_PB_LED_PATTERNS                             6                 /* max LED patterns allowed */

#define MMI_PHB_INVALID_STORE_INDEX                     0xFFFF

#define MMI_PHB_BIRTHDAY_LENGTH                         10
#define MMI_PHB_BIRTHDAY_YEAR_LENGTH                    4
#define MMI_PHB_BIRTHDAY_MONTH_LENGTH                   2
#define MMI_PHB_BIRTHDAY_DAY_LENGTH                     2

#define MAX_PB_MANDATORY_FIELDS                         2
#define MAX_PB_VIEW_FIELDS                              (MMI_PHB_FIELD_TOTAL - MAX_PB_MANDATORY_FIELDS)        /* Exclude mandatory field */

#define MAX_PB_FIELDS                                   (MMI_PHB_FIELD_TOTAL)                                  /* max phonebook fields */

#define MMI_PHB_FIELD_ADD_MORE                          (MMI_PHB_FIELD_TOTAL + 1)
#define MMI_PHB_FIELD_ADD_NUMBERS                       (MMI_PHB_FIELD_TOTAL + 2)
#define MMI_PHB_FIELD_ADD_EMAILS                        (MMI_PHB_FIELD_TOTAL + 3)

#ifdef __MMI_PHB_UI_IN_TABS__
#define MMI_PHB_EDITOR_TAB_TOTAL                        (5)
#define MMI_PHB_EDITOR_TAB_ITEM_TOTAL                   (15)
#ifdef __MMI_PHB_USIM_SUPPORT__
#define MMI_PHB_USIM_EDITOR_TAB_TOTAL                   (2)
#endif
#endif

/**
 * Contact fields enum
 */
typedef enum
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
    MMI_PHB_FIELD_MOBILE_NUMBER,
    MMI_PHB_FIELD_HOME_NUMBER,
    MMI_PHB_FIELD_OFFCIE_NUMBER,
    MMI_PHB_FIELD_FAX_NUMBER,
    MMI_PHB_FIELD_OPT_NUM_1,
    MMI_PHB_FIELD_OPT_NUM_2,
    MMI_PHB_FIELD_OPT_NUM_3,
    MMI_PHB_FIELD_COMPANY_NAME,
    MMI_PHB_FIELD_EMAIL,
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    MMI_PHB_FIELD_EMAIL2,
#endif
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */ 
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    MMI_PHB_FIELD_BIRTHDAY,
#endif 
    MMI_PHB_FIELD_PIC,
    MMI_PHB_FIELD_RING,
#if defined(__MMI_PHB_CALLER_VIDEO__)
    MMI_PHB_FIELD_VIDEO,
#endif 
    MMI_PHB_FIELD_GROUP,
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
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    MMI_PHB_FIELD_DEFAULT,
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
    MMI_PHB_FIELD_TITLE,
    MMI_PHB_FIELD_URL,
    MMI_PHB_FIELD_ADDRESS,
    MMI_PHB_FIELD_ADR_POBOX,
    MMI_PHB_FIELD_ADR_EXTENSION,
    MMI_PHB_FIELD_ADR_STREET,
    MMI_PHB_FIELD_ADR_CITY,
    MMI_PHB_FIELD_ADR_STATE,
    MMI_PHB_FIELD_ADR_POSTALCODE,
    MMI_PHB_FIELD_ADR_COUNTRY,
    MMI_PHB_FIELD_NOTE,
#endif /* defined(__MMI_PHB_INFO_FIELD__) */ 
#ifdef __MMI_SNS_CONTACTS__
    MMI_PHB_SNS_NAME,
    MMI_PHB_SNS_NUMBER,
    MMI_PHB_SNS_BIRTHDAY,
    MMI_PHB_SNS_EMAIL,
    MMI_PHB_SNS_URL,
#endif
    MMI_PHB_FIELD_TOTAL
} mmi_phb_field_enum;

#ifdef __MMI_PHB_USIM_SUPPORT__
typedef enum
{
	MMI_PHB_USIM_FIELD_SNE,
	MMI_PHB_USIM_FIELD_ANR1,
	MMI_PHB_USIM_FIELD_ANR2,
	MMI_PHB_USIM_FIELD_ANR3,
	MMI_PHB_USIM_FIELD_EMAIL1,
	MMI_PHB_USIM_FIELD_EMAIL2,
	MMI_PHB_USIM_FIELD_TOTAL
}mmi_phb_USIM_field_enum;
#endif
/**
 * Phonebook Screen Group type
 */
typedef enum
{
    MMI_PHB_SG_MAIN,
    MMI_PHB_SG_RES,
    MMI_PHB_SG_MARK_SEVERAL,
    MMI_PHB_SG_GROUP,
    MMI_PHB_SG_SETTING,
    
    MMI_PHB_SG_CUI_SAVE,
    MMI_PHB_SG_CUI_VIEW,
    MMI_PHB_SG_CUI_LIST,
    MMI_PHB_SG_CUI_LIST_MULTI,
    MMI_PHB_SG_CUI_LIST_GROUP_TAB,

    MMI_PHB_SG_TOTAL
} mmi_phb_sg_type_enum;

typedef enum
{
    MMI_PHB_CHECK_STORAGE_EMPTY,
    MMI_PHB_CHECK_STORAGE_FULL,
    MMI_PHB_CHECK_STORAGE_BOTH,
    MMI_PHB_CHECK_STORAGE_TOTAL
}mmi_phb_check_storage_enum;

typedef enum
{
    MMI_PHB_OP_NONE,
    MMI_PHB_OP_ADD,
    MMI_PHB_OP_EDIT,
    MMI_PHB_OP_DELETE,
    MMI_PHB_OP_COPY,
    MMI_PHB_OP_MOVE,
    MMI_PHB_OP_COPY_ALL,
    MMI_PHB_OP_DELETE_ALL,
    MMI_PHB_OP_MOVE_ALL,
    MMI_PHB_OP_MULTI_DELETE,
    MMI_PHB_OP_MULTI_COPY,
    MMI_PHB_OP_MULTI_MOVE,

    MMI_PHB_OP_CALL,
    MMI_PHB_OP_CALL_SEND_KEY,
    MMI_PHB_OP_VIDEO_CALL,
    MMI_PHB_OP_IP_CALL,
    MMI_PHB_OP_VOICE_CALL,
    MMI_PHB_OP_MSG,
    MMI_PHB_OP_SMS,
    MMI_PHB_OP_MMS,
    MMI_PHB_OP_EMAIL,
    MMI_PHB_OP_SEND_CARD,
    MMI_PHB_OP_IM,
    MMI_PHB_OP_POSTCARD,
    
    MMI_PHB_OP_TOTAL
} mmi_phb_op_action_enum;


typedef enum
{
    MMI_PHB_STATE_IDLE,
    MMI_PHB_STATE_READ = 0x01,
    MMI_PHB_STATE_UPDATE = 0x02,
    MMI_PHB_STATE_COPY_MULTI = 0x04,
    MMI_PHB_STATE_DELETE_MULTI = 0x08,
    #ifndef __MMI_PHB_SLIM_NO_SAT__
    MMI_PHB_STATE_SAT = 0x10,
    #endif
	
    MMI_PHB_STATE_DM = 0x20,
    MMI_PHB_STATE_TOTAL
} mmi_phb_state_enum;

typedef enum
{
    MMI_PHB_GRP_MEM_OP_NONE,                 /* No operation */
    MMI_PHB_GRP_MEM_OP_MS_ADD,               /* mark seveal add member */
    MMI_PHB_GRP_MEM_OP_MS_MOVE,              /* mark seveal move member */
    MMI_PHB_GRP_MEM_OP_MS_REMOVE,            /* mark seveal remove member */
    MMI_PHB_GRP_MEM_OP_ADD,                  /* add member */
    MMI_PHB_GRP_MEM_OP_MOVE,                 /* move member */
    MMI_PHB_GRP_MEM_OP_REMOVE,               /* remove one member */
    MMI_PHB_GRP_MEM_OP_REMOVE_ALL,           /* remove all member */
    MMI_PHB_GRP_MEM_OP_TOTAL_TOTAL           /* enmu total */
} mmi_phb_group_member_op_enum;

#if defined(__MMI_PHB_MULTI_OPERATION__)
typedef enum
{
    MMI_PHB_MARK_SEVERAL_PRE_NONE,            /* No operation */
#ifdef __MMI_UNIFIED_COMPOSER__
    MMI_PHB_MARK_SEVERAL_PRE_SEND_MESSAGE,    /* mark seveal send message */
#else
    MMI_PHB_MARK_SEVERAL_PRE_SEND_SMS,        /* mark seveal send sms */
#if defined(__MMI_MMS__) &&  defined(OBIGO_Q03C_MMS_V02) && !defined(__MMI_SLIM_MMS_2__)
    MMI_PHB_MARK_SEVERAL_PRE_SEND_MMS,        /* mark seveal send mms */
#endif
#endif
#ifdef __MMI_UDX_VCARD_SUPPORT__
    MMI_PHB_MARK_SEVERAL_PRE_BUILD_UDX,       /* mark seveal build udx */
#endif
#ifdef __MMI_OPP_SUPPORT__
    MMI_PHB_MARK_SEVERAL_PRE_SEND_VCARD,      /* mark seveal send vcard */
#endif
#if defined(__MMI_MULTI_VCARD__)
    MMI_PHB_MARK_SEVERAL_PRE_BACKUP,          /* mark seveal backup */
#endif
    MMI_PHB_MARK_SEVERAL_PRE_DELETE_SELECTED, /* mark seveal remove member */
    MMI_PHB_MARK_SEVERAL_PRE_TOTAL            /* enmu total */
}mmi_phb_mark_several_pre_enum;
#endif

#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
typedef struct
{
    MMI_ID sg_id;
    U16 path[SRV_FMGR_PATH_MAX_LEN + 1];
    U8 type;
} mmi_phb_select_image_struct;
#endif

typedef struct
{
    U16 store_index;                                /* choose number store index */
    MMI_BOOL ip_call;                               /* for dial call flag */
} mmi_phb_choose_number_struct;


typedef struct
{
    mmi_phb_op_action_enum op_action;
    U16 *data;
    U32 data_type;
    U16 store_index;
    MMI_BOOL ip_call;
} mmi_phb_op_action_cntx_struct;


typedef struct
{
    U8 storage;
    U32 field_type;
    srv_phb_contact_data_struct* phb_data;
} mmi_phb_unsaved_data_struct;

typedef struct mmi_phb_unsaved_data_node_struct
{
    struct mmi_phb_unsaved_data_node_struct* next;
    mmi_phb_unsaved_data_struct* object;
} mmi_phb_unsaved_data_node_struct;


typedef struct
{
    mmi_id sg_id;
    U8 src_storage;
    U8 dst_storage;
    U8 state;
	U8 extra_handler;                                      /* extral handler: bit 0, for birthday reminder */
    mmi_phb_op_action_enum action;
    U16 store_index;
    MMI_BOOL canceled;
    MMI_BOOL end_key_press;

    U16 total_count;
    U16 active_index;

}mmi_phb_op_cntx_struct;


typedef struct
{
    mmi_id sg_id;
    MenucuiPtr LSK_function;
    MenucuiPtr CSK_function;
    MenucuiPtr RSK_function;
}mmi_phb_confirm_user_data_struct;


typedef struct
{
    U16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];
#ifdef __MMI_PHB_LAST_NAME_FIELD__    
    U16 last_name[MMI_PHB_NAME_FIELD_LENGTH + 1];
#endif
#ifdef __MMI_PHB_USIM_SUPPORT__
	U16 nick_name[MMI_PHB_FIELD_LABEL_LENGTH+1];
#endif
    U16 number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_phb_wcs_num_struct opt_num[MMI_PHB_OPT_NUM_COUNT];  /* UCS2 home number field point */
    U8 opt_order[MMI_PHB_OPT_NUM_COUNT];
    U16 companyName[MMI_PHB_COMPANY_LENGTH + 1];            /* UCS2 company name field point */
    U16 emailAddress[MMI_PHB_EMAIL_LENGTH + 1];             /* UCS2 eamil address field point */
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    U16 emailAddress2[MMI_PHB_EMAIL_LENGTH + 1];            /* UCS2 eamil address field point */
#endif
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    U16 bday[MMI_PHB_BIRTHDAY_LENGTH + 1 + 4];               /* UCS2 birthday field point, 4 for other languages */
    U16 b_year[MMI_PHB_BIRTHDAY_YEAR_LENGTH + 1];            /* UCS2 birthday field point */
    U16 b_month[MMI_PHB_BIRTHDAY_MONTH_LENGTH + 1];          /* UCS2 birthday field point */
    U16 b_day[MMI_PHB_BIRTHDAY_DAY_LENGTH + 1];              /* UCS2 birthday field point */
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
    U16 title[MMI_PHB_TITLE_LENGTH + 1];                    /* UCS2 title field point */
    U16 url[MMI_PHB_URL_LENGTH + 1];                        /* UCS2 url field point */
    U16 pobox[MMI_PHB_ADDRESS_LENGTH + 1];                  /* UCS2 pobox field point */
    U16 extension[MMI_PHB_ADDRESS_LENGTH + 1];              /* UCS2 extension field point */
    U16 street[MMI_PHB_ADDRESS_LENGTH + 1];                 /* UCS2 street field point */
    U16 city[MMI_PHB_ADDRESS_LENGTH + 1];                   /* UCS2 city field point */
    U16 state[MMI_PHB_ADDRESS_LENGTH + 1];                  /* UCS2 state field point */
    U16 postalcode[MMI_PHB_ADDRESS_LENGTH + 1];             /* UCS2 postal code field point */
    U16 country[MMI_PHB_ADDRESS_LENGTH + 1];                /* UCS2 country field point */
    U16 note[MMI_PHB_NOTE_LENGTH + 1];                   /* UCS2 note field point */
#endif
    U32 group_id;                                          /* group id field point */
    U16 ring_tone_id;                                      /* caller ringtone field point */
    U16 ring_tone[SRV_FMGR_PATH_MAX_LEN + 1];              /* caller ringtone field point */
    U16 picture_id;                                        /* select piture id */
    U16 picture[SRV_FMGR_PATH_MAX_LEN + 1];                        /* caller pic field point */
#if defined(__MMI_PHB_CALLER_VIDEO__)
    U16 video_id;                                          /* select video id */
    U16 video[SRV_FMGR_PATH_MAX_LEN + 1];                          /* caller video field point */
#endif
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#endif
#if 0
#if defined(__MMI_VOIP__)
/* under construction !*/
#endif
#endif
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    U8 default_number;                                     /* default number field point */
#endif
} mmi_phb_contact_info_struct;

/**
  * Contact resource setting
  */
typedef enum
{
    MMI_PHB_RES_RING,
    MMI_PHB_RES_IMAGE,
    MMI_PHB_RES_AVATAR_IMG,
    MMI_PHB_RES_VIDEO,
    MMI_PHB_RES_SWFLASH,
    MMI_PHB_RES_AVATAR_VIDEO,
    MMI_PHB_RES_TYPE_TOTAL
} mmi_phb_res_type_enum;

typedef struct
{
    U8 total_ring_tone;                             /* total count of ring tone */
    U16 ring_tone_list[MAX_PB_RING_TONES];          /* ring tong id array */
    U8 *ring_tone_name_list[MAX_PB_RING_TONES];     /* ring tong name array */
    
    //U8 *led_name_list[MAX_PB_LED_PATTERNS + 1];     /* alert name array */
    
    //U8 *alert_name_list[MAX_PB_ALERT_TYPES + 1];    /* alert name array */

#if defined(__MMI_PHB_CALLER_VIDEO__)
    U8 total_video_id;                              /* total video id */        
    U16 video_id_list[MAX_PB_VIDEO_TAGS];           /* video id array */
    U8 *video_name_list[MAX_PB_VIDEO_TAGS];         /* video name array */
#endif

    U8 total_image_id;                              /* total count of image */
    U16 image_id_list[MAX_PB_PICTURES_TAGS];        /* image id array */
    U8 *image_name_list[MAX_PB_PICTURES_TAGS];      /* image name array */

} mmi_phb_resource_struct;

typedef struct
{
    mmi_id sg_id;                                   /* instance sg id */
    mmi_id child_id;

    U16 curr_res_type;
    
    U8 done;
    U16 highlight_index;
    
    U16 ring_id;
    S32 selected_ring_index;                        /* selected ting tone index */    
    U8 ring_location;
    U16 ring_temp_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 ring_path[SRV_FMGR_PATH_MAX_LEN + 1];
    
    S32 selected_pattern_index;                     /* selected pattern index */    
    
    S32 selected_alert_index;                       /* selected alert index */
    
#if defined(__MMI_PHB_CALLER_VIDEO__)
    U16 video_id;
    S32 selected_video_index;                       /* selected video index */
    U8 video_location;                              /* video location */
    U8 video_audio;                                 /* video's audio on/off flag */
    U16 video_temp_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 video_path[SRV_FMGR_PATH_MAX_LEN + 1];
#endif
    
    U16 img_id;
    S32 selected_pic_index;                         /* selected picture index */
    U8 image_location;                              /* selected picture location */
    U16 img_temp_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 img_path[SRV_FMGR_PATH_MAX_LEN + 1];
} mmi_phb_caller_res_struct;

/**
 * SG: Save Res from filemgr to phonebook
 */
typedef struct
{
    mmi_id sg_id;                                   /* current sg id */
    U16 res_path[SRV_FMGR_PATH_MAX_LEN + 1];            /* res path to save to phonebook */
    U16 recv_res_id;                                /* receive resource and associate to phb entry */
    U8 recv_res_from;                               /* receive resource and associate to phb entry */
} mmi_phb_filemgr_caller_res_struct;


#ifdef __MMI_SNS_CONTACTS__
/* PHB sns list */
typedef enum
{
    MMI_PHB_SNS_LIST_FRIEND,
    MMI_PHB_SNS_LIST_FAVORITE,
    MMI_PHB_SNS_LIST_TOTAL
} mmi_phb_sns_list_enum;

typedef enum
{
    MMI_PHB_SNS_NO_READY,
    MMI_PHB_SNS_NO_ACCOUNT,
    MMI_PHB_SNS_ERROR_TOTAL
} mmi_phb_sns_error_enum;

typedef enum
{
    MMI_PHB_SNS_STATE_IDLE,
    MMI_PHB_SNS_STATE_PREPARE,
    MMI_PHB_SNS_STATE_READY,
    MMI_PHB_SNS_STATE_RELOAD,
    MMI_PHB_SNS_STATE_ADD,
    MMI_PHB_SNS_STATE_REMOVE,
    MMI_PHB_SNS_STATE_SEARCH,
    MMI_PHB_SNS_STATE_RESEARCH,
    MMI_PHB_SNS_STATE_REFRESH,
    MMI_PHB_SNS_STATE_TOTAL
} mmi_phb_sns_state_enum;


typedef struct
{
    mmi_id group_id;
    U16 contact_id;
}mmi_phb_sns_unlink_struct;

typedef struct
{
    S32 highlight_index;
    S32 list_id;
    S32 provider;
    MMI_BOOL is_valid;
    MMI_BOOL is_search;
    MMI_BOOL is_clear;
    U16 total;
    S16 start_index;
    S16 end_index;
    WCHAR search_buffer[SRV_SNS_MAX_LEN_NAME];
    WCHAR search_temp_buffer[SRV_SNS_MAX_LEN_NAME];
    mmi_phb_sns_state_enum state;
    srv_sns_user_list_struct *user;
    MMI_BOOL is_group;
}mmi_phb_sns_friend_list_struct;

typedef struct
{
    S32 list_id;
    MMI_BOOL is_valid;
    U16 total;
}mmi_phb_sns_filter_list_struct;

typedef struct
{
    S32 highlight_index;
    S32 list_id;
    MMI_BOOL is_valid;
    MMI_BOOL is_search;
    MMI_BOOL is_clear;
    U16 total;
    S16 start_index;
    S16 end_index;
    WCHAR search_buffer[SRV_SNS_MAX_LEN_NAME];
    WCHAR search_temp_buffer[SRV_SNS_MAX_LEN_NAME];
    mmi_phb_sns_state_enum state;
    srv_sns_user_list_struct *user;
    U16 favorite_count;
}mmi_phb_sns_favorite_list_struct;

typedef struct
{
    mmi_id sns_cui_link;
    mmi_id sns_cui_filter;
    mmi_phb_sns_error_enum sns_error_type;
    gdi_image_cache_bmp_struct image_buffer[MMI_PHB_SNS_PROVIDER_IMAGE_NUM];
    MMI_BOOL is_parse_image[MMI_PHB_SNS_PROVIDER_IMAGE_NUM];
}mmi_phb_sns_misc_struct;
#endif

/** 
 * SG: phonebook list
 */
typedef struct
{
    mmi_id sg_id;                           /* instance sg id */
    mmi_id parent_id;                       /* Caller group id */
    mmi_id child_id;                        /* child group id */
    U8 storage;                             /* select storage, default is preffered storage */
    U8 display_type;                        /* name display type */
    U16 store_index;                        /* selected contact store index */
    U16 list_index;                         /* contact list index */
    U16 *contact_array;                     /* contact list content */
    U16 contact_count;                      /* contact count */
    
    U32 filter;                             /* field bit mask to select */
    
    U32 user_data;                          /* parent user data */
    
    U16 qsearch_input_buffer[MMI_PHB_NAME_LENGTH + 1];
    srv_phb_group_filter_struct group_filter;

    /**
     * for mark several
     */
    U16 select_count;
    U8  bitmask[(MMI_PHB_ENTRIES + 7) / 8];
    U16 mark_count;
    U16 mark_index;
    U16 *mark_array;
    U8 *mark_field;
    
    /**
     * set screen info
     */
    U16 lsk_img;
    U16 lsk_label;

    /**
     * For tab group
     */
    U8 group_id;
    U8 *group_array;

#ifdef __MMI_SNS_CONTACTS__
	CHAR* sns_favorite[MMI_PHB_SNS_FAVORITE_MAX_NUM];   /* sns favorite mask */
	mmi_phb_sns_friend_list_struct *sns_friend_list;
	mmi_phb_sns_favorite_list_struct *sns_favorite_list;
#endif

#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
    MMI_BOOL is_widget;
#endif
#ifdef __MMI_NCENTER_SUPPORT__
    MMI_BOOL is_disable_ncenter;
#endif
    MMI_BOOL evt_out;                           /* make sure sg has sent evt out */
} mmi_phb_list_cntx_struct;

/** 
  * SG: save a contact to phonebook
  */
typedef struct
{
    mmi_id sg_id;                               /* instance sg id */
    mmi_id parent_id;                           /* Caller group id */
    mmi_id child_id;                            /* child group id */
    U32 style;                                  /* save contact style */
    mmi_id editor_id;                           /* editor group id */
    mmi_id menu_storage_id;                     /* choose storage menu gid */
    mmi_id menu_add_replace_id;                 /* let user choose save contact or replace exist */
    U32 user_data;                              /* parent user data */
    MMI_BOOL is_popup;                          /* TRUE: popup by phonebook */
    U16 store_index;                            /* contact's store index, if action is edit */
    U16 highlight_str;                          /* current highlight item str id */
    U8 highlight_type;                          /* first highlight item type */
    U8 first_highlight_type;                    /* first entry highlight str id */
    U32 field_mask;                             /* contact's fields be editing */
    U8 done_flag;                               /* content is changed */
    MMI_BOOL bday_changed;                      /* birthday changed */
#ifdef __MMI_PHB_SIM_NUMBER_MANAGEMENT__
    MMI_BOOL add_more;                          /* change storage to phone from sim */
#endif
    MMI_BOOL add_detail;                        /* increase contact's detail info */
    mmi_phb_caller_res_struct *res;             /* contact's resource buffer */
    mmi_phb_contact_info_struct *contact;       /* contact's buffer */
#ifdef __MMI_PHB_GROUP_ENHANCE__
    U8 group_highlight_index;
    U8 group_id_list[MMI_PHB_GROUP_COUNT];
#endif
    U8 storage;                                 /* contact's storage */
    mmi_phb_op_action_enum action;              /* Op action: Add/Edit */
#ifdef __MMI_SAVE_CONTACT_REPLACE__
    mmi_phb_list_cntx_struct *update_list;      /* update contact list */
#endif
    MMI_BOOL edit_temp_done;                    /* temp editing state */
    U16 edit_temp_buff[100];                    /* temp editing buffer */
    void *input_buffer;                         /* editor category input buffer */
    MMI_BOOL evt_out;                           /* make sure sg has sent evt out */
    MMI_BOOL is_from_email;                     /* whether save email to phone */
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__) && defined(__MMI_PHB_UI_IN_TABS__)
	U8 pre_photo_idx;
#endif
} mmi_phb_save_contact_cntx_struct;

/** 
 * SG: View a contact
 */
typedef struct
{
    mmi_id sg_id;                               /* instance sg id */
    mmi_id parent_id;                           /* caller group id */
    mmi_id child_id;                            /* child group id */
    U16 store_index;                            /* view contact's store index */
    U8 highlight_type;                          /* first highlight item type */
    U16 highlight_str;                          /* current highlight str id */
    U8 first_highlight_type;                    /* first entry highlight str id */
    U16 *select_data;                           /* current highlight data */
    mmi_phb_caller_res_struct *res;             /* contact's res buffer */
    U32 field_mask;                             /* contact's fields be viewed */
    mmi_phb_contact_info_struct *contact;       /* contact's content */
#ifdef __MMI_PHB_PHOTO_STICKER_SUPPORT__
    CHAR *item_list[MAX_PB_FIELDS*2];
    U16 img_list[MAX_PB_FIELDS*2];
#endif
#ifdef __MMI_PHB_GROUP_ENHANCE__
    U8 *group_array;
    U8 group_highlight;
#endif
#ifdef __MMI_SNS_CONTACTS__
    S32 list_id;
    MMI_BOOL is_load_finish;
    WCHAR *account_string;
#endif
} mmi_phb_view_contact_cntx_struct;


typedef struct
{
    U8 refresh_type;
    U16 old_store_index;
    U16 new_store_index;

    mmi_id sg_id;                               /* caller id */
} mmi_phb_refresh_struct;

typedef struct
{
    U16 age;
    U16 sg_type;
    U16 parent_id;
    
    mmi_phb_refresh_struct refresh_data;
    FunctionPtr refresh_cb;

    void *private_data;

    mmi_event_struct* delay_event;
} mmi_phb_sg_data_struct;

typedef struct
{
    U8 highlight_index;
    U16 *number_to_dial[MMI_PHB_FIELD_TOTAL];      /* nunber array for choose number */
    U32 number_type[MMI_PHB_FIELD_TOTAL];          /* number type array for choose number */
} mmi_phb_choose_field_struct;

typedef struct
{
    MMI_BOOL ready;
    MMI_BOOL processing;
    
    /**
     * phonebook operation state, will be transfer to DataMgr as user data,
     * and should compare the state in rsp handler
     */
    U16 state;
	#ifdef __DM_LAWMO_SUPPORT__
    U16 qstate[5];
	#endif

    mmi_phb_sg_data_struct* sg_stack[GRP_ID_PHB_END - GRP_ID_PHB_BEGIN]; /* current running screen group */
	#ifndef __MMI_SUPPORT_ASMV2__
	KAL_ADM_ID adm_id;
	void *asm_pool;
	#endif

    
} mmi_phb_cntx_mgr_struct;

typedef struct
{
    U32 count;
    U8 group_id_list[MMI_PHB_GROUP_COUNT];
    mmi_phb_group_member_op_enum op;
    MMI_BOOL finished;
} mmi_phb_group_member_data_struct;


/**
 * Extern Global varible
 */
extern mmi_phb_cntx_mgr_struct g_phb_cntx_mgr;
extern mmi_phb_view_contact_cntx_struct *g_mmi_phb_view_contact_p;
extern mmi_phb_list_cntx_struct *g_mmi_phb_list_p;
extern mmi_phb_contact_info_struct *g_mmi_phb_contact_p;
extern mmi_phb_save_contact_cntx_struct *g_mmi_phb_save_contact_p;
extern mmi_phb_resource_struct g_mmi_phb_resource;
extern mmi_phb_caller_res_struct *g_mmi_phb_res_p;
extern mmi_phb_choose_field_struct g_mmi_phb_choose_field;
extern mmi_phb_op_cntx_struct g_mmi_phb_op_cntx;



/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntxmgr_init
 * DESCRIPTION
 *  initilize phonebook context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_create_handle
 * DESCRIPTION
 *  creat new screen groups, if the screen group support multi instance, user should call this api
 * PARAMETERS
 *  sg_type                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern U32 mmi_phb_cntx_mgr_create_handle(U16 sg_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_release_handle
 * DESCRIPTION
 *  Free SG data buffer, before call this function, user must be sure, user private data has been freed
 * PARAMETERS
 *  U32                      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_release_handle(U32 handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_handle_by_sg_id
 * DESCRIPTION
 *  Get sg_handle by sg_id, the sg_id must be in history
 * PARAMETERS
 *  sg_id                      [IN]
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 mmi_phb_cntx_mgr_get_handle_by_sg_id(U16 sg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_handle
 * DESCRIPTION
 *  Get current running phonebook sg handle
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 mmi_phb_cntx_mgr_get_handle(void);

extern mmi_phb_sg_data_struct * mmi_phb_cntx_mgr_get_instance(mmi_id sg_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_set_data
 * DESCRIPTION
 *  Set SG private data
 * PARAMETERS
 *  handle                      [IN]
 *  data                         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_set_data(U32 handle, void* data);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_data
 * DESCRIPTION
 *  Get SG private data
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  void*
 *****************************************************************************/
extern void* mmi_phb_cntx_mgr_get_data(U32 handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_set_parent_id
 * DESCRIPTION
 *  Set SG parent gropu id
 * PARAMETERS
 *  handle                      [IN]
 *  parent_id                  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_set_parent_id(U32 handle, mmi_id parent_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_parent_id
 * DESCRIPTION
 *  Get SG parent group id
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id mmi_phb_cntx_mgr_get_parent_id(U32 handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_sg_tpye
 * DESCRIPTION
 *  Get SG type
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 mmi_phb_cntx_mgr_get_sg_tpye(U32 handle);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_sg_id
 * DESCRIPTION
 *  Get SG ID
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  U16
 *****************************************************************************/
extern mmi_id mmi_phb_cntx_mgr_get_sg_id(U32 handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_refresh_data
 * DESCRIPTION
 *  Get refresh data from cntx mgr
 * PARAMETERS
 *  handle                      [IN]
 * RETURNS
 *  mmi_phb_refresh_struct*
 *****************************************************************************/
extern mmi_phb_refresh_struct* mmi_phb_cntx_mgr_get_refresh_data(U32 handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_controller
 * DESCRIPTION
 *  Cntx mgr state handler
 * PARAMETERS
 *  state                     [IN]
 *  set                        [IN]             MMI_TRUE: set to state; MMI_FALSE: reset
 *  data                      [IN]             for callers pass data to handle
 * RETURNS
 *  MMI_BOOL                                Verify the operation on the state is success or not
 *****************************************************************************/
extern MMI_BOOL mmi_phb_cntx_mgr_controller(U16 state, MMI_BOOL set, void *data);

#ifdef __DM_LAWMO_SUPPORT__
extern void mmi_phb_cntx_mgr_qstate_in(U16 state);
extern U16 mmi_phb_cntx_mgr_qstate_out(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_get_state
 * DESCRIPTION
 *  Get cntx mgr state
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 mmi_phb_cntx_mgr_get_state(void);

extern MMI_BOOL mmi_phb_cntx_mgr_state_is_set(U16 state);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_controller
 * DESCRIPTION
 *  Cntx mgr state handler
 * PARAMETERS
 *  state                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_set_state(U16 state);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_controller
 * DESCRIPTION
 *  Cntx mgr state handler
 * PARAMETERS
 *  state                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_reset_state(U16 state);

extern mmi_id mmi_phb_cntx_mgr_get_current_sg_id(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_sim_refresh
 * DESCRIPTION
 *  Cntx mgr receive sim refresh command
 * PARAMETERS
 *  storage                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHB_SLIM_NO_SAT__ 
extern void mmi_phb_cntx_mgr_sim_refresh(U8 storage);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_at
 * DESCRIPTION
 *  Cntx mgr receive at operation
 * PARAMETERS
 *  operation                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_at(U8 operation);

/*****************************************************************************
 * FUNCTION
 *  mmi_phb_cntx_mgr_clear_history
 * DESCRIPTION
 *  Cntx mgr clear all phonebook screen in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phb_cntx_mgr_clear_history(void);
extern void mmi_phb_cntx_mgr_refresh(mmi_phb_op_cntx_struct *op_cntx, U16 *contact_array, U16 contact_count, U16 store_index);
extern void mmi_phb_cntx_mgr_input_method_change(void);

/**
 * PhbCui.c
 */
extern mmi_phb_list_cntx_struct* cui_phb_list_select_contact_create_cntx(U8 list_type);
extern mmi_ret cui_phb_list_select_contact_proc(mmi_event_struct *evt);
extern mmi_ret cui_phb_list_select_group_member_proc(mmi_event_struct *evt);
extern void cui_phb_list_select_contact_set_cntx(mmi_phb_list_cntx_struct *list_cntx);
extern mmi_ret mmi_phb_launch_proc(mmi_event_struct *evt);

extern MMI_BOOL mmi_phb_display_popup_cb(
            mmi_id parent_id,
            UI_string_type string,
            mmi_event_notify_enum event_id,
            mmi_proc_func proc,
            void* user_data);

extern MMI_BOOL mmi_phb_usb_app_unavailable_popup(S32 result);
extern void mmi_phb_ucm_app_entry_error_message(void);

extern void mmi_phb_fmgr_cui_res_handle(cui_file_selector_result_event_struct *res);

#if defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__)
extern void mmi_phb_camera_cui_res_handle(WCHAR* path);
#endif/* defined(__MMI_CAMCORDER__) || defined(__MMI_CAMERA__) */

extern void mmi_phb_cntx_mgr_post_evt(mmi_id sg_id, MMI_BOOL evt_wait, mmi_event_struct *evt);

/* temp resolution */
#if 0
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
#endif

extern void mmi_phb_confirm_user_data_init(mmi_phb_confirm_user_data_struct * arg);
extern mmi_ret mmi_phb_comfirm_proc(mmi_event_struct *evt);
extern U16 mmi_phb_get_storage_full_str_id(U8 storage);
extern MMI_BOOL mmi_phb_check_storage(MMI_BOOL is_or, U8 storage);

#endif /* _PHONEBOOK_CNTX_MGR_H */ 

