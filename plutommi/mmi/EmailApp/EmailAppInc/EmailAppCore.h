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
 * EmailAppCore.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to declare the Email app core function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_EMAIL_APP_CORE_H
#define _MMI_EMAIL_APP_CORE_H

#include "MMI_features.h"

//#include "SrvEmailGprot.h"
#include "App_usedetails.h"
#include "emailsrvgprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "customer_ps_inc.h"

/*
 * Define
 */

#define MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG     (10)
#define MMI_EMAIL_CONT_TEMP_MAX_LEN                 (256)
#define MMI_EMAIL_ACCT_TEMP_MAX_NUMBER              (10)
#define MMI_EMAIL_SIG_MAX_TEXT_LEN                  (50)
#define MMI_EMAIL_SIG_MAX_NUMBER                    (10) // it should depends on max account number
#define MMI_EMAIL_SIG_MAX_IMAGE_NUMBER              (5)  // multi image signature for one account
#define MMI_EMAIL_AUTO_CHECK_MAX_NUMBER             (10)
#define MMI_EMAIL_AUTO_CHECK_DAYS_OF_WEEK			(7)
#define MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT       (5)
#define MMI_EMAIL_AUTO_CHECK_SUNDAY					(0)
#define MMI_EMAIL_AUTO_CHECK_MONDAY					(1)
#define MMI_EMAIL_AUTO_CHECK_TUESDAY				(2)
#define MMI_EMAIL_AUTO_CHECK_WEDNESDAY		        (3)
#define MMI_EMAIL_AUTO_CHECK_THURSDAY				(4)
#define MMI_EMAIL_AUTO_CHECK_FRIDAY					(5)
#define MMI_EMAIL_AUTO_CHECK_SATURDAY				(6)
#define MMI_EMAIL_CONT_TEMP_INIT_FLAG_INDEX         (40)
#define MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER         (10)

/*
 * Typedef
 */

typedef S32                                         MMI_EMAIL_AUTO_CHECK_ID;
typedef S32                                         MMI_EMAIL_SIG_ID;

/* tempary use */
typedef enum
{
    MMI_EMAIL_SUCCESS,
    MMI_EMAIL_FAIL,
    MMI_EMAIL_ACCOUNT_ALREADY_EXIST,
    MMI_EMAIL_ACCOUNT_NOT_EXIST,
    MMI_EMAIL_WOULDBLOCK,
    MMI_EMAIL_END_OF_ENUM
} mmi_email_app_core_result_enum;
/* tempary use */


typedef void (*async_callback)(S32, void*);
typedef void (*auto_check_nofity_fn)(EMAIL_ACCT_ID);


typedef enum
{
    //MMI_EMAIL_CONT_TEMP_TYPE_ALL_KIND,
    MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED,
    MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED_ENG = MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED,
    MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED_SC,
    MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED_TC,
    MMI_EMAIL_CONT_TEMP_TYPE_USER_DEFINED,
    MMI_EMAIL_CONT_TEMP_TYPE_END_OF_ENUM
} mmi_email_cont_temp_type_enum;

typedef enum
{
    MMI_EMAIL_EMAIL_DATA_ALL_KIND,
    MMI_EMAIL_EMAIL_DATA_URL,
    MMI_EMAIL_EMAIL_DATA_ADDR,
    MMI_EMAIL_EMAIL_DATA_PHONE_NUMBER,
    MMI_EMAIL_EMAIL_DATA_END_OF_ENUM
} mmi_email_emaildata_aotufind_type_enum;

typedef enum
{
    MMI_EMAIL_SIG_INVALID = 0,
    MMI_EMAIL_SIG_INIT,
    MMI_EMAIL_SIG_OFF = MMI_EMAIL_SIG_INIT,
    MMI_EMAIL_SIG_ON,
    MMI_EMAIL_SIG_END_OF_ENUM
} mmi_email_sig_status_enmu;

typedef enum
{
    MMI_EMAIL_AUTO_CHECK_DISABLE,
    MMI_EMAIL_AUTO_CHECK_ENABLE,
    MMI_EMAIL_AUTO_CHECK_END_OF_ENUM
} mmi_email_auto_check_status_enum;

typedef struct
{
    WCHAR server_name[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];   /* The server name (WCHAR string) */
    U16 port_num;                       /* The part number, 0 means using the default value */
    U16 sec_port_num;                   /* security port num */
    srv_email_sec_mode_enum sec_mode;   /* The security mode */
} mmi_email_acct_server_struct;

/* signature */
typedef struct
{
    MMI_BOOL validity;
    U16 user_num;                                           /* This signature is used by how many account */
    WCHAR text[MMI_EMAIL_SIG_MAX_TEXT_LEN + 1];             /* Text of signature */
    U16 image_num;                                          /* Number of image of this signature */
    WCHAR image_name[MMI_EMAIL_SIG_MAX_IMAGE_NUMBER][EMAIL_ATTCH_FILE_NAME_LEN + 1];
                                                            /* use macro of file manager */
                                                            /* 
                                                               MMI_EMAIL_SIG_MAX_TEXT_LEN tempary use
                                                             */
} mmi_email_sig_struct;

typedef struct
{
    MMI_BOOL status;                            /* Status of this signature */
    MMI_EMAIL_SIG_ID sig_id;                    /* Signature id (index) of this account */
    EMAIL_ACCT_ID acct_id;                      /* Account id */
} mmi_email_acct_sig_map;

/* auto check */
typedef struct
{
    MMI_BOOL status;                            /* Status of this auto check */
    MMI_EMAIL_AUTO_CHECK_ID auto_check_id;      /* Signature id (index) of this account */
    EMAIL_ACCT_ID acct_id;                      /* Account id */
} mmi_email_acct_auto_check_map;

typedef struct
{
    U32 start_time;
    U32 stop_time;
    U32 interval;
} mmi_email_auto_check_time_segment;

typedef struct
{
    MMI_BOOL enable;
    U16 roaming_num;
    mmi_email_auto_check_time_segment roaming[MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT];
    U16 normal_num;
    mmi_email_auto_check_time_segment normal[MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT];
} mmi_email_auto_check_day_struct;

typedef struct
{
	U16 user_num;
	MMI_BOOL validity;
	mmi_email_auto_check_day_struct days[MMI_EMAIL_AUTO_CHECK_DAYS_OF_WEEK];
} mmi_email_auto_check_struct;

/* autofind */
typedef struct
{
    mmi_email_emaildata_aotufind_type_enum type;
    WCHAR *start_index;
    S32 len;
} mmi_email_emaildata_autofind_struct;

/* account template */
typedef struct
{
    WCHAR acct_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
    WCHAR addr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    srv_email_prot_type_enum protocol;
    mmi_email_acct_server_struct incoming_server;
    mmi_email_acct_server_struct outgoing_server;
    MMI_BOOL username_format;
    MMI_BOOL outgoing_auth;
} mmi_email_acct_temp_struct;

/*
 * Extern Global Function
 */

void mmi_email_app_core_init(void);

extern S32 mmi_email_app_core_get_fs_error_detail(void);

/*
 * Content template api
 */
mmi_email_app_core_result_enum mmi_email_cont_temp_get_valid_number(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 *number);
mmi_email_app_core_result_enum mmi_email_cont_temp_read(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len);
mmi_email_app_core_result_enum mmi_email_cont_temp_edit(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len);
mmi_email_app_core_result_enum mmi_email_cont_temp_clear(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index);

/*
 * Email data api
 */
applib_address_node_struct* mmi_email_emaildata_autofind(
                                    CHAR *text,
                                    MMI_BOOL text_type,
                                    U32 len,
                                    applib_addr_type_enum type,
                                    applib_mem_alloc_fn mem_alloc,
                                    applib_mem_free_fn mem_free,
                                    applib_check_stop_fn check_stop_fn,
                                    applib_charset_enum input_data_type,
                                    MMI_BOOL *is_stopped);
mmi_email_app_core_result_enum mmi_email_emaildata_disp_name_to_addr(
                                        WCHAR *disp_name,
                                        U16 len_1,
                                        WCHAR *addr_1,
                                        U16 len_2,
                                        WCHAR *addr_2);
mmi_email_app_core_result_enum mmi_email_emaildata_group_to_addr(
                                        WCHAR *group,
                                        S32 *addr_num,
                                        U16 addr_len,
                                        WCHAR **addr_list_1,
                                        WCHAR **addr_list_2);


/*
 * Account template api
 */
mmi_email_app_core_result_enum mmi_email_acct_temp_get_num(S32 *num);
mmi_email_app_core_result_enum mmi_email_acct_temp_check_addr(
                                        WCHAR *addr,
                                        S32 *index);
mmi_email_app_core_result_enum mmi_email_acct_temp_get_acct(
                                        S32 index,
                                        mmi_email_acct_temp_struct *acct_temp);

mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_num(S32 *num);
mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_name(S32 index, WCHAR *group_name, S32 name_len);
mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_data_num(WCHAR *group_name, S32 *num);
mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_data_all(
                                WCHAR *group_name,
                                S32 *num,
                                mmi_email_acct_temp_struct *acct_temp);
mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_data_by_index(
                                WCHAR *group_name,
                                S32 index,
                                mmi_email_acct_temp_struct *acct_temp);


/*
 * Signature api
 */
mmi_email_app_core_result_enum mmi_email_sig_list_acct_id(
                                        EMAIL_ACCT_ID *acct_id_list,
                                        U16 *array_len);
mmi_email_app_core_result_enum mmi_email_sig_list_id(
                                        MMI_EMAIL_SIG_ID *sig_id_list,
                                        U16 *array_len);
mmi_email_app_core_result_enum mmi_email_sig_use_exist(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_EMAIL_SIG_ID sig_id);
mmi_email_app_core_result_enum mmi_email_sig_create(EMAIL_ACCT_ID acct_id);
mmi_email_app_core_result_enum mmi_email_sig_delete_acct(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL destroy_sig);
mmi_email_app_core_result_enum mmi_email_sig_get_status(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL *status);
mmi_email_app_core_result_enum mmi_email_sig_set_status(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL status);
mmi_email_app_core_result_enum mmi_email_sig_get_signature(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_sig_struct *signature);
mmi_email_app_core_result_enum mmi_email_sig_get_text(
                                        EMAIL_ACCT_ID acct_id,
                                        WCHAR *text,
                                        U16 len);
mmi_email_app_core_result_enum mmi_email_sig_set_text(
                                        EMAIL_ACCT_ID acct_id,
                                        WCHAR *text,
                                        U16 len);
mmi_email_app_core_result_enum mmi_email_sig_clear_text(EMAIL_ACCT_ID acct_id);
mmi_email_app_core_result_enum mmi_email_sig_get_image_path(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index,
                                        WCHAR *image_path,
                                        U16 len);
S32 mmi_email_sig_add_image(
                                        EMAIL_ACCT_ID acct_id,
                                        WCHAR *image_path,
                                        async_callback callback,
                                        void* user_data);
S32 mmi_email_sig_edit_image(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index,
                                        WCHAR *image_path,
                                        async_callback callback,
                                        void* user_data);
mmi_email_app_core_result_enum mmi_email_sig_delete_image(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index);
mmi_email_app_core_result_enum mmi_email_sig_delete_all_image(EMAIL_ACCT_ID acct_id);


/*
 * Auto check api
 */
mmi_email_app_core_result_enum mmi_email_auto_check_list_acct_id(
                                        EMAIL_ACCT_ID *acct_id_list,
                                        U16 *array_len);
mmi_email_app_core_result_enum mmi_email_auto_check_create(EMAIL_ACCT_ID acct_id);
mmi_email_app_core_result_enum mmi_email_auto_check_list_id(
                                        MMI_EMAIL_SIG_ID *auto_check_id_list,
                                        U16 *array_len);
mmi_email_app_core_result_enum mmi_email_auto_check_use_exist(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_EMAIL_AUTO_CHECK_ID auto_check_id);
mmi_email_app_core_result_enum mmi_email_auto_check_delete_acct(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL destroy_auto_check);
mmi_email_app_core_result_enum mmi_email_auto_check_start(EMAIL_ACCT_ID acct_id);
mmi_email_app_core_result_enum mmi_email_auto_check_stop(EMAIL_ACCT_ID acct_id);
mmi_email_app_core_result_enum mmi_email_auto_check_stop_all(void);
extern void mmi_email_auto_check_stop_service(void);
extern mmi_email_app_core_result_enum mmi_email_auto_check_start_service(auto_check_nofity_fn nofity_fn);
mmi_email_app_core_result_enum mmi_email_auto_check_get_status(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL *status);
//void mmi_email_auto_check_set_status(
//                EMAIL_ACCT_ID acct_id,
//                MMI_BOOL status);
mmi_email_app_core_result_enum mmi_email_auto_check_reset_day(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day);
mmi_email_app_core_result_enum mmi_email_auto_check_reset_all_day(EMAIL_ACCT_ID acct_id);
mmi_email_app_core_result_enum mmi_email_auto_check_get_day_enable(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        MMI_BOOL *enable);
mmi_email_app_core_result_enum mmi_email_auto_check_set_day_enable(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        MMI_BOOL enable);
mmi_email_app_core_result_enum mmi_email_auto_check_get_segment_num(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 *num);
/************************ segment list operation ****************************/
mmi_email_app_core_result_enum mmi_email_auto_check_get_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 index,
                                        mmi_email_auto_check_time_segment *segment);
mmi_email_app_core_result_enum mmi_email_auto_check_add_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        mmi_email_auto_check_time_segment *segment);
mmi_email_app_core_result_enum mmi_email_auto_check_edit_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 index,
                                        mmi_email_auto_check_time_segment *segment);
mmi_email_app_core_result_enum mmi_email_auto_check_delete_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 index);
mmi_email_app_core_result_enum mmi_email_auto_check_delete_all_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day);

#ifdef __MMI_EMAIL_IMAP_PUSH__
/************************ imap push mail ************************************/
extern mmi_email_app_core_result_enum mmi_email_imap_push_set_status(MMI_BOOL status);
extern mmi_email_app_core_result_enum mmi_email_imap_push_get_status(MMI_BOOL *status);
extern mmi_email_app_core_result_enum mmi_email_imap_push_acct_add(EMAIL_ACCT_ID acct_id);
extern mmi_email_app_core_result_enum mmi_email_imap_push_acct_remove(EMAIL_ACCT_ID acct_id);
extern mmi_email_app_core_result_enum mmi_email_imap_push_acct_get(EMAIL_ACCT_ID *acct_array, U32 *count);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


#endif /* _MMI_EMAIL_APP_CORE_H */

