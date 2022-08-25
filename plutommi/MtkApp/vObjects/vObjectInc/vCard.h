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
 * vCard.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receving vcard object.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VCARD_H
#define _MMI_VCARD_H

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_phb_config.h"
#include "MMI_features.h"


/* vcard parse result enum */
typedef enum
{
    MMI_VCARD_PARSE_NO_ERROR,               /* no error */    
    MMI_VCARD_PARSE_BEGIN_ERROR,            /* begin field check error */
    MMI_VCARD_PARSE_VERSION_ERROR,          /* version field check error */
    MMI_VCARD_PARSE_FILE_SIZE_TOO_LARGE,    /* vcard file too large */
    MMI_VCARD_PARSE_UNKNOW_ERROR,           /* other error */
    MMI_VCARD_PARSE_VERSION_21,             /* vcard version 2.1 */
    MMI_VCARD_PARSE_VERSION_30,             /* vcard version 3.0 */
    MMI_VCARD_PARSE_ENUM_TATOL              /* enmu total */
} vcard_parse_enum;


typedef enum
{
    MMI_VCARD_VERSION_21,                   /* vcard version 2.1 */
    MMI_VCARD_VERSION_30                    /* vcard version 3.0 */
} mmi_vcard_version_enum;


typedef enum
{
    MMI_VCARD_PARSE_VCARD_PHB,
    MMI_VCARD_PARSE_VCARD_FMGR,
    MMI_VCARD_PARSE_VCARD_BOTH,
    MMI_VCARD_PARSE_VCARD_TOTAL
} mmi_vcard_parse_vcard_enum;


typedef enum
{
    MMI_VCARD_BUILD_VCARD_SEND_SMS,
    MMI_VCARD_BUILD_VCARD_SEND_MMS,
    MMI_VCARD_BUILD_VCARD_SEND_BT,
    MMI_VCARD_BUILD_VCARD_SEND_EMAIL,
    MMI_VCARD_BUILD_VCARD_FMG,
    MMI_VCARD_BUILD_VCARD_TOTAL
} mmi_vcard_build_vcard_enum;


#ifndef __COSMOS_MMI_PACKAGE__
#if defined(__IOT__)
#define VCARD_BASE (0)
#endif
typedef enum
{
    EVT_ID_VCARD_CANCEL = VCARD_BASE + 1,
    EVT_ID_VCARD_DONE,
    EVT_ID_VCARD_EXPORT_CANCEL,
    EVT_ID_VCARD_EXPORT_DONE,
    EVT_ID_VCARD_IMPORT_CANCEL,
    EVT_ID_VCARD_IMPORT_DONE,
    EVT_ID_VCARD_MAX
} mmi_vcard_event_enum;
#endif /* __COSMOS_MMI_PACKAGE__ */

#define CUI_VARD_TO_SIM4_DONE     11
#define CUI_VARD_TO_SIM3_DONE     10
#define CUI_VARD_TO_IMPORT_DONE   9
#define CUI_VARD_TO_EXPORT_DONE   8
#define CUI_VARD_TO_EMAIL_DONE    7
#define CUI_VARD_TO_SMS_DONE      6
#define CUI_VARD_TO_MMS_DONE      5
#define CUI_VARD_TO_BT_DONE       4
#define CUI_VARD_TO_PHONE_DONE    3
#define CUI_VARD_TO_SIM2_DONE     2
#define CUI_VARD_TO_SIM_DONE      1
#define CUI_VARD_TO_FMGR_DONE     0
#define CUI_VARD_TO_PHONE_FAIL    -1
#define CUI_VARD_TO_SIM2_FAIL     -2
#define CUI_VARD_TO_SIM_FAIL      -3
#define CUI_VARD_TO_FMGR_FAIL     -4
#define CUI_VARD_TO_EMAIL_FAIL    -5
#define CUI_VARD_TO_SMS_FAIL      -6
#define CUI_VARD_TO_MMS_FAIL      -7
#define CUI_VARD_TO_BT_FAIL       -8
#define CUI_VARD_USB_MODE         -9
#define CUI_VARD_NAME_EMPTY       -10
#define CUI_VARD_TO_IMPORT_FAIL   -11
#define CUI_VARD_TO_EXPORT_FAIL   -12
#define CUI_VARD_TO_SIM3_FAIL     -13
#define CUI_VARD_TO_SIM4_FAIL     -14



typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    S32 result;
} cui_vcard_result_struct;


typedef struct
{
    WCHAR* first_name;                                      /* wcs family name field */
    WCHAR* second_name;                                     /* wcs given name field */
    WCHAR* third_name;                                      /* wcs additional name field */
    WCHAR* fourth_name;                                     /* wcs name prefix field */
    WCHAR* fifth_name;                                      /* wcs name suffix field */
    WCHAR* nick_name;                                       /* wcs nick name field */
    WCHAR* number;                                          /* wcs mobile number field*/
    mmi_phb_wcs_num_struct* opt_num[MMI_PHB_OPT_NUM_COUNT]; /* wcs optional number field */
    WCHAR* email;                                           /* wcs email address field */
    WCHAR* email2;                                          /* wcs email address2 field */
    WCHAR* company;                                         /* wcs company name field */
    U16 b_year;                                             /* birthday year field */
    U8 b_month;                                             /* birthday month field */
    U8 b_day;                                               /* birthday day field */
    WCHAR* url;                                             /* url field */
    WCHAR* title;                                           /* title field */
    WCHAR* note;                                            /* note field */
    WCHAR* pobox;                                           /* pobox field */
    WCHAR* extension;                                       /* extension field */
    WCHAR* street;                                          /* street field */
    WCHAR* city;                                            /* city field */
    WCHAR* state;                                           /* state field */
    WCHAR* postalcode;                                      /* postalcode field */
    WCHAR* country;                                         /* country field */
    WCHAR* image_path;                                      /* image path */
    U8 default_number;                                      /* default number */
} mmi_vcard_field_data_struct;


#ifdef __MMI_PHB_INFO_FIELD__
#define VCARD_WRITE_BUFF_LEN      3500          /* vcard write buffer size */
#define VCARD_READ_BUFF_LEN        2048         /* vcard read buffer size */
#else /* __MMI_PHB_INFO_FIELD__ */
#define VCARD_WRITE_BUFF_LEN      1024          /* vcard write buffer size */
#define VCARD_READ_BUFF_LEN          512        /* vcard read buffer size */
#endif /* __MMI_PHB_INFO_FIELD__ */


#if defined(__MMI_FILE_MANAGER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_fmgr_sms_forward
 * DESCRIPTION
 *  Forward vcard to SMS from file manager.
 *  This is a intermediate function between file manager and SMS app.
 * PARAMETERS
 *  path        :     [IN]      vcard file path
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcard_fmgr_sms_forward(S8 *path);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_recv_from_file_mgr
 * DESCRIPTION
 *  A pre-entry function of receiving vcard functuion. This vcard is forwarded from file manager.
 * PARAMETERS
 *  path        :     [IN]      vcard file path
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_vcard_recv_from_file_mgr(S8* path);
#endif /* defined(__MMI_FILE_MANAGER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_writer_v21_to_file
 * DESCRIPTION
 *  write select phonebook entry into vcard format into destination file.
 * PARAMETERS
 *  path                :           [IN]        Destination path
 *  field_content       :           [IN]        vcard filed content
 * RETURNS
 *  S32
 * RETURN VALUES
 *  fs_error             :                fs op error info
 *****************************************************************************/
extern S32 mmi_vcard_writer_v21_to_file(U16* path, mmi_vcard_field_data_struct* field_content);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_parse_file
 * DESCRIPTION
 *  Read one line to parse for each filed.
 * PARAMETERS
 *  fh      [IN]        file handle ready to read and parse.
 * RETURNS
 *  fs_error             :                fs op error info
 *****************************************************************************/
extern S32 mmi_vcard_parse_file(U16* path, mmi_vcard_field_data_struct* vcard_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_get_version
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern S32 mmi_vcard_get_version(S8 *path);


/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_check_tcard_file
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern MMI_BOOL mmi_vcard_check_tcard_file(void);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_parse_vcard_creat
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern mmi_id cui_vcard_parse_vcard_creat(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_parse_vcard_set_path
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_parse_vcard_set_path(mmi_id sg_id, U16* path);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_parse_vcard_set_type
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_parse_vcard_set_type(mmi_id sg_id, mmi_vcard_parse_vcard_enum type);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_parse_vcard_run
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_parse_vcard_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_parse_vcard_close
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_parse_vcard_close(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_build_vcard_creat
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern mmi_id cui_vcard_build_vcard_creat(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_build_vcard_set_data
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_build_vcard_set_data(mmi_id sg_id, mmi_vcard_field_data_struct* vcard_data);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_build_vcard_set_type
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_build_vcard_set_type(mmi_id sg_id, mmi_vcard_build_vcard_enum type);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_build_vcard_run
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_build_vcard_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_build_vcard_close
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_build_vcard_close(mmi_id sg_id);


#if defined(__MMI_OPP_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  cui_vcard_multi_send_creat
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern mmi_id cui_vcard_multi_send_creat(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_multi_send_set_contact_list
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_multi_send_set_contact_list(mmi_id sg_id, U16* contact_list, U16 contact_count);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_multi_send_run
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_multi_send_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_multi_send_close
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_multi_send_close(mmi_id sg_id);
#endif /* defined(__MMI_OPP_SUPPORT__) */


#if defined(__MMI_MULTI_VCARD__)
/*****************************************************************************
 * FUNCTION
 *  cui_vcard_export_vcard_creat
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern mmi_id cui_vcard_export_vcard_creat(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_export_vcard_set_contact_list
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_export_vcard_set_contact_list(mmi_id sg_id, U16* contact_list, U16 contact_count);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_export_vcard_cancel
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_export_vcard_cancel(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_export_vcard_run
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_export_vcard_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_export_vcard_close
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_export_vcard_close(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_import_vcard_creat
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern mmi_id cui_vcard_import_vcard_creat(mmi_id parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_import_vcard_set_contact_list
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_import_vcard_set_contact_list(mmi_id sg_id, U16* contact_list, U16 contact_count);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_import_vcard_cancel
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_import_vcard_cancel(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_import_vcard_run
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_import_vcard_run(mmi_id sg_id);


/*****************************************************************************
 * FUNCTION
 *  cui_vcard_import_vcard_close
 * DESCRIPTION
 *  get a vcard file version
 * PARAMETERS
 *  path                :     [IN]        The vcard file location in file system.
 * RETURNS
 *  S32
 * RETURN VALUES
 *  <0                  :                 fs op error
 *  vcard_parse_enum    :                 vcard parse result
 *****************************************************************************/
extern void cui_vcard_import_vcard_close(mmi_id sg_id);
#endif /* defined(__MMI_MULTI_VCARD__) */

#endif /* _MMI_VCARD_H */

