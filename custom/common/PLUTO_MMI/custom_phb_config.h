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
 *  custom_phb_config.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef CUSTOM_PHB_CONFIG_H
#define CUSTOM_PHB_CONFIG_H

#include "MMI_features.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Include 
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MMI_PHB_SIM_ENTRIES     MAX_PHB_SIM_ENTRY   /* Maximum number of entries in SIM */
#define MMI_PHB_PHONE_ENTRIES   MAX_PHB_PHONE_ENTRY /* Maximum number of entries in phone */

#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
#define MMI_PHB_TCARD_ENTRIES   MAX_PHB_TCARD_ENTRY /* Maximum number of entries in Tcard */
#else
#define MMI_PHB_TCARD_ENTRIES   0
#endif

#define MMI_PHB_SIM_COUNT (MMI_SIM_TOTAL)

#define MMI_PHB_TOTAL_SIM_ENTRIES (MMI_PHB_SIM_ENTRIES * MMI_PHB_SIM_COUNT)
#define MMI_PHB_BASIC_ENTRIES     (MMI_PHB_TOTAL_SIM_ENTRIES + MMI_PHB_PHONE_ENTRIES)
#define MMI_PHB_ENTRIES           (MMI_PHB_TOTAL_SIM_ENTRIES + MMI_PHB_PHONE_ENTRIES + MMI_PHB_TCARD_ENTRIES) /* Maximum number of entries in Phonebook */

#ifdef __MMI_PHB_USIM_SUPPORT__
#define MMI_PHB_MAX_ANR_COUNT    (3)
#define MMI_PHB_MAX_EMAIL_COUNT  (1)
#define MMI_PHB_MAX_SNE_COUNT    (1)
#define MMI_PHB_MAX_GAS_COUNT    (10)
#else
#define MMI_PHB_MAX_ANR_COUNT    (0)
#define MMI_PHB_MAX_EMAIL_COUNT  (0)
#define MMI_PHB_MAX_SNE_COUNT    (0)
#define MMI_PHB_MAX_GAS_COUNT    (0)
#endif /* __MMI_PHB_USIM_SUPPORT__ */

#define MMI_PHB_SIM_NUM_COUNT    (MMI_PHB_MAX_ANR_COUNT + 1)

#ifdef __MEXICO_ECC__
#define MAX_PHB_EXTRA_NUMBER 50
#else
#define MAX_PHB_EXTRA_NUMBER 32
#endif

#ifdef __MEXICO_ECC__
#define MMI_PHB_SRV_FDN_ENTRIES (50)
#else
#define MMI_PHB_FDN_ENTRIES (MAX_PHB_FDN_ENTRY)
#endif

#define MMI_PHB_FDN_TOTAL_ENTRIES (MMI_PHB_FDN_ENTRIES * MMI_PHB_SIM_COUNT)

#if defined(__MMI_PHB_LAST_NAME_FIELD__)
#define MMI_PHB_SPACE_LENGTH    1
#define MMI_PHB_NAME_LENGTH     ((MAX_PHB_NAME_LENGTH + 1) / 2 * 2 + MMI_PHB_SPACE_LENGTH)  /* max phonebook name length */
#else /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
#define MMI_PHB_NAME_LENGTH     ((MAX_PHB_NAME_LENGTH + 1) / 2)                             /* max phonebook name length */
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */

#define MMI_PHB_NAME_FIELD_LENGTH   ((MAX_PHB_NAME_LENGTH + 1) / 2)

#define MMI_PHB_NUMBER_LENGTH           40
#define MMI_PHB_NUMBER_PLUS_LENGTH      (MMI_PHB_NUMBER_LENGTH + 1)
#define MMI_PHB_NUMBER_BCD_LEN          ((MMI_PHB_NUMBER_PLUS_LENGTH + 1) / 2)
#define MMI_PHB_SOS_NUMBER_LENGTH       6
#define MMI_PHB_EMAIL_LENGTH            (60)
#define MMI_PHB_BDAY_LENGTH             12
#define MMI_PHB_TITLE_LENGTH            20
#define MMI_PHB_COMPANY_LENGTH          20
#define MMI_PHB_URL_LENGTH              128
#define MMI_PHB_ADDRESS_LENGTH          25
#define MMI_PHB_NOTE_LENGTH             30
#define MMI_PHB_IMPS_LENGTH             61
#define MMI_PHB_POC_LENGTH              62

#define MMI_PHB_FIELD_LABEL_LENGTH           (40)
#define MMI_PHB_FIELD_LABEL_COUNT            (10)

#define MMI_PHB_FIELD_LABEL_FIELD            (2)

#ifdef __MMI_PHB_OPTIONAL_FIELD__
#define MMI_PHB_NUMBER_FIELD_COUNT           (4)

#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
#define MMI_PHB_EMAIL_FIELD_COUNT            (2)
#else
#define MMI_PHB_EMAIL_FIELD_COUNT            (1)
#endif

#else /* __MMI_PHB_OPTIONAL_FIELD__ */
#define MMI_PHB_NUMBER_FIELD_COUNT           (1)
#define MMI_PHB_EMAIL_FIELD_COUNT            (0)
#endif  /* __MMI_PHB_OPTIONAL_FIELD__ */

#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)

#define SRV_PHB_PBAPC_NUMBER_COUNT           (MMI_PHB_NUMBER_FIELD_COUNT)

#define SRV_PHB_PBAPC_NUMBER_LENGTH          (MMI_PHB_NUMBER_PLUS_LENGTH)

#define SRV_PHB_PBAPC_NAME_LENGTH            (MMI_PHB_NAME_LENGTH)

#if defined(__MMI_WEARABLE_DEVICE__)
#define SRV_PHB_PBAPC_CONTACT_COUNT          (500)
#else
#define SRV_PHB_PBAPC_CONTACT_COUNT          (1000)
#endif

#define SRV_PHB_PBAPC_FOLDER_SIZE            (20)

#endif /* __MMI_PHB_PBAPC_SYNC_CONTACT__ */

#define MMI_PHB_ADDRESS_FIELD_COUNT          (1)
#define MMI_PHB_NOTE_FIELD_COUNT             (1)
#define MMI_PHB_URL_FIELD_COUNT              (1)

#define MMI_PHB_SPEED_DIAL_COUNT        8
#define MMI_PHB_SOS_NUMBER_COUNT        5
#ifdef __MMI_VUI_WIDGET_KEY_VIP_CONTACT__
#define MMI_PHB_VIP_CONTACT_COUNT       10
#else
#define MMI_PHB_VIP_CONTACT_COUNT       5
#endif
#define MMI_PHB_ICE_CONTACT_COUNT       3

#ifdef __OP01_FWPBW__
#define MMI_PHB_DIALER_DIRECT_DIAL_COUNT 5
#endif

#define MMI_PHB_GROUP_NAME_LENGTH       20          /* Caller Group Name Length */
#define MMI_PHB_GROUP_COUNT             20

#ifdef __MMI_PHB_USIM_SUPPORT__
#define MMI_PHB_GROUP_USIM_COUNT        PHB_MAX_ASSOCIATE_GRP * MMI_PHB_SIM_COUNT
#else
#define MMI_PHB_GROUP_USIM_COUNT        0
#endif

#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
#define MMI_PHB_GROUP_TCARD_COUNT       20
#else
#define MMI_PHB_GROUP_TCARD_COUNT       0
#endif

#define MMI_PHB_GROUP_TOTAL_COUNT MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT + MMI_PHB_GROUP_TCARD_COUNT

#define MMI_PHB_GROUP_FIELD_SIZE        ((MMI_PHB_GROUP_COUNT + 7) / 8)           /* bitmask */
#define MMI_PHB_GROUP_FIELD_TOTAL       MAX_PHB_PHONE_ENTRY
#define MMI_PHB_GROUP_FIELD_MAX_COUNT   (2000 / MMI_PHB_GROUP_FIELD_SIZE)
#define MMI_PHB_GROUP_FIELD_COUNT       (MMI_PHB_GROUP_FIELD_MAX_COUNT > MMI_PHB_GROUP_FIELD_TOTAL ? MMI_PHB_GROUP_FIELD_TOTAL : MMI_PHB_GROUP_FIELD_MAX_COUNT) /* group id count in a record */

#define MMI_PHB_FIELDS_MASK_SIZE        (sizeof(mmi_phb_phone_mask_struct))           /* support mask 32 fields */
#define MMI_PHB_FIELDS_MASK_TOTAL       MAX_PHB_PHONE_ENTRY
#define MMI_PHB_FIELDS_MASK_MAX_COUNT   (2000 / MMI_PHB_FIELDS_MASK_SIZE)
#define MMI_PHB_FIELDS_MASK_COUNT       (MMI_PHB_FIELDS_MASK_MAX_COUNT > MMI_PHB_FIELDS_MASK_TOTAL ? MMI_PHB_FIELDS_MASK_TOTAL : MMI_PHB_FIELDS_MASK_MAX_COUNT) /* fields mask count in a record */

#define MMI_PHB_QSEARCH_LENGTH          6
#define MMI_PHB_BDAY_MIN_YEAR_INT       1900        /* Min Year */
#define MMI_PHB_BDAY_MAX_YEAR_INT       2030        /* Max Year */


#if defined(__MMI_PHB_INFO_FIELD__)
#if !defined(__MMI_PHB_UI_IN_TABS__)
#define MMI_PHB_EDIT_MEM (15 * 1024)
#else
#define MMI_PHB_EDIT_MEM (10 * 1024)
#endif
#else
#define MMI_PHB_EDIT_MEM (5 * 1024)
#endif

#if defined(__MMI_PHB_MULTI_OPERATION__) || defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
#define MMI_PHB_LIST_MEM (15 * MMI_PHB_ENTRIES)
#else
#define MMI_PHB_LIST_MEM (10 * MMI_PHB_ENTRIES)
#endif

#define MMI_PHB_SIM_CACHE_MEM (sizeof(srv_phb_sim_cache_struct) * (MMI_PHB_ENTRIES - MMI_PHB_PHONE_ENTRIES))

#if defined(__MMI_PHB_USIM_SUPPORT__)
#define MMI_PHB_USIM_CACHE_SIZE (sizeof(srv_phb_sim_email_struct) * MMI_PHB_MAX_EMAIL_COUNT + sizeof(srv_phb_sim_anr_struct) * MMI_PHB_MAX_ANR_COUNT + sizeof(srv_phb_sim_sne_struct) + sizeof(srv_phb_sim_grp_struct))
#define MMI_PHB_USIM_CACHE_MEM  (MMI_PHB_USIM_CACHE_SIZE * (MMI_PHB_ENTRIES - MMI_PHB_PHONE_ENTRIES) + sizeof(srv_phb_sim_aas_struct) * MMI_PHB_FIELD_LABEL_COUNT + sizeof(srv_phb_sim_gas_struct) * MMI_PHB_MAX_GAS_COUNT)
#else
#define MMI_PHB_USIM_CACHE_MEM  (0)
#endif

#define MMI_PHB_TCARD_CACHE_MEM (MMI_PHB_TCARD_ENTRIES * sizeof(mmi_phb_info_struct))

#define MMI_PHB_OTHER_MEM (10 * 1024)

#define MMI_PHB_MEM_SIZE (MMI_PHB_EDIT_MEM + MMI_PHB_LIST_MEM + MMI_PHB_OTHER_MEM + MMI_PHB_SIM_CACHE_MEM + MMI_PHB_USIM_CACHE_MEM + MMI_PHB_TCARD_CACHE_MEM)

#define MMI_PHB_OPT_NUM_COUNT       3

#define MMI_PHB_SIM_IMSI_LEN       16

#ifndef VOIP_URI_LEN
#define VOIP_URI_LEN           (41)
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
 
typedef kal_uint16 mmi_phb_contact_id;
typedef kal_uint16 mmi_phb_sub_id;

typedef enum
{
    MMI_PHB_CONTACT_FIELD_ID_NAME,
    MMI_PHB_CONTACT_FIELD_ID_NICK,
    MMI_PHB_CONTACT_FIELD_ID_NUMBER,
    MMI_PHB_CONTACT_FIELD_ID_EMAIL,
    MMI_PHB_CONTACT_FIELD_ID_COMPANY,
    MMI_PHB_CONTACT_FIELD_ID_ADDRESS,
    MMI_PHB_CONTACT_FIELD_ID_TITLE,
    MMI_PHB_CONTACT_FIELD_ID_URL,
    MMI_PHB_CONTACT_FIELD_ID_NOTE,
    MMI_PHB_CONTACT_FIELD_ID_GROUP,
    MMI_PHB_CONTACT_FIELD_ID_BDAY,
    MMI_PHB_CONTACT_FIELD_ID_RING,
    MMI_PHB_CONTACT_FIELD_ID_IMAGE,
    MMI_PHB_CONTACT_FIELD_ID_VIDEO,
    MMI_PHB_CONTACT_FIELD_ID_VOIP,
    MMI_PHB_CONTACT_FIELD_ID_IMPS,
    MMI_PHB_CONTACT_FIELD_ID_MSN,
    
    /* add new data field befor this */
    MMI_PHB_CONTACT_FIELD_DATA_TOTAL,
    MMI_PHB_CONTACT_FIELD_ID_DEF = MMI_PHB_CONTACT_FIELD_DATA_TOTAL,
    MMI_PHB_CONTACT_FIELD_ID_VT,
    MMI_PHB_CONTACT_FIELD_ID_TOTAL
} mmi_phb_contact_field_id_enum;

#define MMI_PHB_CONTACT_FIELD_EXIST      (1)    /* special flag for mark a contact exist */
#define MMI_PHB_CONTACT_FIELD_NAME       (1 << (MMI_PHB_CONTACT_FIELD_ID_NAME + 1))
#define MMI_PHB_CONTACT_FIELD_NICK       (1 << (MMI_PHB_CONTACT_FIELD_ID_NICK + 1))
#define MMI_PHB_CONTACT_FIELD_NUMBER     (1 << (MMI_PHB_CONTACT_FIELD_ID_NUMBER + 1))
#define MMI_PHB_CONTACT_FIELD_EMAIL      (1 << (MMI_PHB_CONTACT_FIELD_ID_EMAIL + 1))
#define MMI_PHB_CONTACT_FIELD_COMPANY    (1 << (MMI_PHB_CONTACT_FIELD_ID_COMPANY + 1))
#define MMI_PHB_CONTACT_FIELD_ADDRESS    (1 << (MMI_PHB_CONTACT_FIELD_ID_ADDRESS + 1))
#define MMI_PHB_CONTACT_FIELD_TITLE      (1 << (MMI_PHB_CONTACT_FIELD_ID_TITLE + 1))
#define MMI_PHB_CONTACT_FIELD_URL        (1 << (MMI_PHB_CONTACT_FIELD_ID_URL + 1))
#define MMI_PHB_CONTACT_FIELD_NOTE       (1 << (MMI_PHB_CONTACT_FIELD_ID_NOTE + 1))
#define MMI_PHB_CONTACT_FIELD_GROUP      (1 << (MMI_PHB_CONTACT_FIELD_ID_GROUP + 1))
#define MMI_PHB_CONTACT_FIELD_BDAY       (1 << (MMI_PHB_CONTACT_FIELD_ID_BDAY + 1))
#define MMI_PHB_CONTACT_FIELD_RING       (1 << (MMI_PHB_CONTACT_FIELD_ID_RING + 1))
#define MMI_PHB_CONTACT_FIELD_IMAGE      (1 << (MMI_PHB_CONTACT_FIELD_ID_IMAGE + 1))
#define MMI_PHB_CONTACT_FIELD_VIDEO      (1 << (MMI_PHB_CONTACT_FIELD_ID_VIDEO + 1))
#define MMI_PHB_CONTACT_FIELD_VOIP       (1 << (MMI_PHB_CONTACT_FIELD_ID_VOIP + 1))
#define MMI_PHB_CONTACT_FIELD_IMPS       (1 << (MMI_PHB_CONTACT_FIELD_ID_IMPS + 1))
#define MMI_PHB_CONTACT_FIELD_MSN        (1 << (MMI_PHB_CONTACT_FIELD_ID_MSN + 1))
#define MMI_PHB_CONTACT_FIELD_DEF        (1 << (MMI_PHB_CONTACT_FIELD_ID_DEF + 1))
#define MMI_PHB_CONTACT_FIELD_VT         (1 << (MMI_PHB_CONTACT_FIELD_ID_VT + 1))

#define MMI_PHB_CONTACT_FIELD_ALL             0xFFFFFFFF      /* phonebook ALL field */

#define MMI_PHB_CONTACT_FIELD_SIM            (MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER)    /* phonebook SIM fields */
#define MMI_PHB_CONTACT_FIELD_OPTIONAL       (MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL)   /* nvram optional fields */
#define MMI_PHB_CONTACT_FIELD_RES            (MMI_PHB_CONTACT_FIELD_RING | MMI_PHB_CONTACT_FIELD_IMAGE | MMI_PHB_CONTACT_FIELD_VIDEO)    /* phonebook res fields */
#define MMI_PHB_CONTACT_FIELD_INFO           (MMI_PHB_CONTACT_FIELD_RES | MMI_PHB_CONTACT_FIELD_ADDRESS | MMI_PHB_CONTACT_FIELD_TITLE | MMI_PHB_CONTACT_FIELD_URL | MMI_PHB_CONTACT_FIELD_NOTE | MMI_PHB_CONTACT_FIELD_COMPANY | MMI_PHB_CONTACT_FIELD_VOIP | MMI_PHB_CONTACT_FIELD_IMPS | MMI_PHB_CONTACT_FIELD_BDAY | MMI_PHB_CONTACT_FIELD_MSN)    /* nvram info fields */
 
#define MMI_PHB_CONTACT_FIELD_ALL_NUM        (MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_VOIP)    /* phonebook all number fields */
#define MMI_PHB_CONTACT_FIELD_MMS            (MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL)   /* phonebook gsm number & email fields */

typedef enum
{
    MMI_PHB_NUM_TYPE_NONE,
    MMI_PHB_NUM_TYPE_MOBILE,
    MMI_PHB_NUM_TYPE_HOME,
    MMI_PHB_NUM_TYPE_OFFICE,
    MMI_PHB_NUM_TYPE_FAX,
    MMI_PHB_NUM_TYPE_TOTAL,
    MMI_PHB_NUM_TYPE_USER_BASE = MMI_PHB_NUM_TYPE_TOTAL /* user define type id */
} mmi_phb_num_type_enum;

typedef enum
{
    MMI_PHB_EMAIL_TYPE_NONE,
    MMI_PHB_EMAIL_TYPE_HOME,
    MMI_PHB_EMAIL_TYPE_OFFICE,
    MMI_PHB_EMAIL_TYPE_TOTAL,
    MMI_PHB_EMAIL_TYPE_USER_BASE = MMI_PHB_EMAIL_TYPE_TOTAL /* user define type id */
} mmi_phb_email_type_enum;


typedef struct
{
    kal_uint16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];
    kal_uint8 number[MMI_PHB_NUMBER_BCD_LEN];
} srv_phb_sim_adn_struct;

typedef struct
{
    srv_phb_sim_adn_struct adn;
    kal_uint32 field_mask;
#ifdef __MMI_PHB_USIM_SUPPORT__
    kal_uint8 number_count;
    kal_uint8 email_count;
#endif
} srv_phb_sim_cache_struct;


#if defined(__MMI_PHB_USIM_SUPPORT__)
typedef struct
{
    kal_uint8 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    kal_uint8 type;
} srv_phb_sim_anr_struct;


typedef struct
{
    kal_uint8 email[MMI_PHB_EMAIL_LENGTH + 1];
} srv_phb_sim_email_struct;

typedef struct
{
    kal_uint16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];
} srv_phb_sim_sne_struct;

typedef struct
{
    kal_uint16 label[MMI_PHB_FIELD_LABEL_LENGTH + 1];
} srv_phb_sim_aas_struct;

typedef struct
{
    kal_uint16 group_name[MMI_PHB_GROUP_NAME_LENGTH + 1];
} srv_phb_sim_gas_struct;

typedef struct
{
    kal_uint16 grp; /*bit mask, max: 16 groups*/
} srv_phb_sim_grp_struct;

#endif


typedef struct
{
    kal_uint8 storage_type;
    kal_uint8 number_index;
    mmi_phb_contact_id contact_index;
} mmi_phb_number_id;


typedef mmi_phb_number_id SRV_PHB_ID;


/* number fields struct */
typedef struct
{
    mmi_phb_num_type_enum type;                             /* number type */
    kal_uint16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];      /* WCS number data */
} mmi_phb_wcs_num_struct;

/* number fields struct */
typedef struct
{
    mmi_phb_sub_id sub_id;                                  /* number id */
    mmi_phb_num_type_enum type;                             /* number type */
    kal_uint8 last_used_sim;                                /*last used sim, high 4 bits for sms, low 4 bits for call*/
    kal_uint8 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];       /* ascii number data */
} mmi_phb_asc_num_struct;

/* name & number fields in a phonebook entry */
typedef struct
{
    kal_uint16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];                   /* name field */
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    kal_uint16 l_name[MMI_PHB_NAME_FIELD_LENGTH + 1];                /* last name field */
#endif
} mmi_phb_name_struct;


typedef struct
{
    mmi_phb_sub_id sub_id;                         /* email id field, same as number id */
    kal_uint8 type;                                /* email type field, refer: mmi_phb_email_type_enum */
    kal_uint8 email[MMI_PHB_EMAIL_LENGTH + 1];     /* email data field */
} mmi_phb_email_struct;

/* optional fields in a phonebook entry */
typedef struct
{
    mmi_phb_asc_num_struct num[MMI_PHB_NUMBER_FIELD_COUNT]; /* ASCII home number*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_phb_email_struct email_address[MMI_PHB_EMAIL_FIELD_COUNT];   /* ASCII email address */
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    kal_uint8 default_number;
#endif
#endif
} mmi_phb_optional_fields_struct;

/* birthday field struct */
typedef struct
{
    kal_uint16 b_year;      /* year field */
    kal_uint8  b_month;     /* month field */
    kal_uint8  b_day;       /* day field */
} mmi_phb_bday_struct;

/* address filed struct */
typedef struct
{
    kal_uint16 pobox[MMI_PHB_ADDRESS_LENGTH + 1];       /* pobox field */
    kal_uint16 extension[MMI_PHB_ADDRESS_LENGTH + 1];   /* extension field */
    kal_uint16 street[MMI_PHB_ADDRESS_LENGTH + 1];      /* street field */
    kal_uint16 city[MMI_PHB_ADDRESS_LENGTH + 1];        /* city field */
    kal_uint16 state[MMI_PHB_ADDRESS_LENGTH + 1];       /* state field */
    kal_uint16 postalcode[MMI_PHB_ADDRESS_LENGTH + 1];  /* postalcode field */
    kal_uint16 country[MMI_PHB_ADDRESS_LENGTH + 1];     /* country field */
} mmi_phb_address_struct;

/* info filed struct */
typedef struct
{
    kal_uint16 res_type;
    kal_uint16 image_id;
    kal_uint16 ringtone_id;
#ifdef __MMI_PHB_CALLER_VIDEO__
    kal_uint16 video_id;
#endif

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    kal_uint16 company[MMI_PHB_COMPANY_LENGTH + 1];        /* USC2 company name */
#endif
#if defined(__MMI_PHB_INFO_FIELD__)
    kal_uint8  url[MMI_PHB_URL_LENGTH + 1];             /* url field */
    kal_uint16 title[MMI_PHB_TITLE_LENGTH + 1];         /* title field */
    kal_uint16 note[MMI_PHB_NOTE_LENGTH + 1];           /* note field */
    mmi_phb_address_struct address;                     /* address field */
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    mmi_phb_bday_struct bday;                              /* bday field */
#endif

#if defined(__MMI_VOIP__)
    kal_uint8  voip[VOIP_URI_LEN];                         /* voip field */
#endif

#if defined(__MMI_IMPS__)
/* under construction !*/
#endif

#if defined(__MMI_PHB_MSN_FIELD__)
    kal_uint8  msn[MMI_PHB_EMAIL_LENGTH + 1];              /* imps field */
#endif

} mmi_phb_info_struct;

/* group info struct */
typedef struct
{
    kal_uint16 group_name[MMI_PHB_GROUP_NAME_LENGTH + 1];
    kal_uint16 res_type;
    kal_uint16 ringtone_id;
    kal_uint16 image_id;
#ifdef __MMI_PHB_CALLER_VIDEO__
    kal_uint16 video_id;
#endif
    kal_uint8  order_index;
} mmi_phb_group_info_struct;

/* my number struct */
typedef struct
{
    kal_uint16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];         /* name_ucs2 field */
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    kal_uint16 l_name[MMI_PHB_NAME_FIELD_LENGTH + 1];       /* l_name_ucs2 field */
#endif
    kal_uint16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];         /* number field 1 for + Sign and 1 for Null Termination. */
    kal_uint16 homeNumber[MMI_PHB_NUMBER_PLUS_LENGTH + 1];     /* home number field */
    kal_uint16 companyName[MMI_PHB_COMPANY_LENGTH + 1];     /* company name field */
    kal_uint16 emailAddress[MMI_PHB_EMAIL_LENGTH + 1];        /* email address field */
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    kal_uint16 emailAddress2[MMI_PHB_EMAIL_LENGTH + 1];       /* email address 2 field */
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    kal_uint16 officeNumber[MMI_PHB_NUMBER_PLUS_LENGTH + 1];   /* office number field */
    kal_uint16 faxNumber[MMI_PHB_NUMBER_PLUS_LENGTH + 1];      /* fax number field */
} mmi_phb_my_number_struct;

/* owner number struct */
typedef struct
{
    kal_uint16 name[MMI_PHB_NAME_LENGTH + 1];
    kal_uint16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
} mmi_phb_owner_number_struct;

/* VIP contact struct */
typedef struct
{
    kal_uint8  is_sync;
    kal_uint16 store_index;
    /* It is only for showing VIP contact list */
    kal_uint16 name[MMI_PHB_NAME_LENGTH + 1];
    kal_uint16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    kal_uint32 num_type;
} mmi_phb_vip_contact_struct;

/* Speed dial struct */
typedef mmi_phb_vip_contact_struct mmi_phb_speed_dial_struct;

/* SOS number struct */
typedef struct
{
    kal_uint8  type;
    kal_uint8  length;
    kal_uint16 number[MMI_PHB_SOS_NUMBER_LENGTH + 1];
} mmi_phb_sos_number_struct;

/* ICE contact struct */
typedef struct
{
    kal_uint16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
} mmi_phb_ice_contact_struct;


typedef struct
{
    kal_uint32 field_mask;
#if (MMI_PHB_NUMBER_FIELD_COUNT > 1)
    kal_uint8 num_count;
#endif
#if (MMI_PHB_EMAIL_FIELD_COUNT > 1)
    kal_uint8 email_count;
#endif
} mmi_phb_phone_mask_struct;

#if defined(__BT_PBAP_CLIENT__)

#if defined(__MMI_WEARABLE_DEVICE__)
#define MMI_PHB_PBAPC_MAX_PSE_CONTACT                   (200) // read max pse contact
#else
#ifdef __EMPTY_MMI__
#define MMI_PHB_PBAPC_MAX_PSE_CONTACT                   (100)
#else
#define MMI_PHB_PBAPC_MAX_PSE_CONTACT                   (1000) // read max pse contact
#endif
#endif

#endif

#endif /* CUSTOM_PHB_CONFIG_H */

