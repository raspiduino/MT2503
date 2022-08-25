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
 * EmailAppCore.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email app core function.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#ifdef __MMI_EMAIL__

#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_email_def.h"
#else
#include "mmi_rp_app_email_def.h"
#endif

#include "Phbsrvgprot.h"
#include "FontDcl.h"
#include "EmailAppCore.h"
#include "MMIDataType.h"
#include "FontRes.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "emailsrvgprot.h"
#include "TimerEvents.h"
#include "FileMgrSrvGProt.h"
#include "fs_func.h"
#include "fs_type.h"
#include "string.h"
#include "SSCStringTable.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "fs_errcode.h"
#include "app_usedetails.h"
#include "custom_phb_config.h"
#include "ps_public_enum.h"
#include "mmi_frm_timer_gprot.h"
#include "app_datetime.h"
#include "mmi_inet_app_trc.h"
#include "GeneralSettingSrvGprot.h"
#include "Lang_interface.h"

static CHAR app_core_path[] = "App_Core\\";
static CHAR cont_temp_file[] = "cont_temp";
//static CHAR acct_temp_file[] = "acct_temp";
static CHAR sig_data_file[] = "sig_data";
static CHAR sig_map_file[] = "sig_map";
static CHAR auto_check_data_file[] = "auto_check_data";
static CHAR auto_check_map_file[] = "auto_check_map";
static CHAR sig_image_path[] = "sig_image\\";
static CHAR sig_image_name[] = "sig_image";
#ifdef __MMI_EMAIL_IMAP_PUSH__
static CHAR imap_push_file[] = "imap_push";
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

static S32 g_fs_error_detail = 0;

static U8 curr_lang[SSC_SIZE]; /*to temporarily save current phone language, in order to recover*/
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;


mmi_email_acct_temp_struct acct_template_list[] =
    {
#ifdef CUSTOM_EMAIL_PROFILE_TEMPLATES
        CUSTOM_EMAIL_PROFILE_TEMPLATES
#else /* CUSTOM_EMAIL_PROFILE_TEMPLATES */
    #ifdef __SSL_SUPPORT__
        {
            L"Gmail",
            L"@gmail.com",
            SRV_EMAIL_PROT_IMAP4, /* protocol */
            {
                L"imap.gmail.com",
                993, 
                993,
                SRV_EMAIL_SEC_SSL_TLS
            }, /* incoming_server */
            {
                L"smtp.gmail.com",
                465,
                465,
                SRV_EMAIL_SEC_SSL_TLS
            }, /* outgoing_server */
            MMI_TRUE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"Yahoo",
            L"@yahoo.com",
            SRV_EMAIL_PROT_IMAP4, /* protocol */
            {
                L"imap-ssl.mail.yahoo.com",
                993,
                993,
                SRV_EMAIL_SEC_SSL_TLS
            }, /* incoming_server */
            {
                L"smtp.mail.yahoo.com",
                465,
                465,
                SRV_EMAIL_SEC_SSL_TLS
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"Hotmail",
            L"@hotmail.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop3.live.com",
                995, 
                995,
                SRV_EMAIL_SEC_SSL_TLS
            }, /* incoming_server */
            {
                L"smtp.live.com",
                587,
                587,
                SRV_EMAIL_SEC_STARTTLS
            }, /* outgoing_server */
            MMI_TRUE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"163",
            L"@163.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.163.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.163.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"QQ",
            L"@qq.com",
            SRV_EMAIL_PROT_IMAP4, /* protocol */
            {
                L"imap.qq.com",
                143, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.qq.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"126",
            L"@126.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.126.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.126.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"Sohu",
            L"@sohu.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.sohu.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.sohu.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"Sina",
            L"@sina.com.cn",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.sina.com.cn",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.sina.com.cn",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        }
    #else
        {
            L"Yahoo",
            L"@yahoo.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.mail.yahoo.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.mail.yahoo.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"163",
            L"@163.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.163.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.163.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"QQ",
            L"@qq.com",
            SRV_EMAIL_PROT_IMAP4, /* protocol */
            {
                L"imap.qq.com",
                143, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.qq.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"126",
            L"@126.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.126.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.126.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"Sohu",
            L"@sohu.com",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.sohu.com",
                110, 
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.sohu.com",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        },
        {
            L"Sina",
            L"@sina.com.cn",
            SRV_EMAIL_PROT_POP3, /* protocol */
            {
                L"pop.sina.com.cn",
                110,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* incoming_server */
            {
                L"smtp.sina.com.cn",
                25,
                0,
                SRV_EMAIL_SEC_NONE
            }, /* outgoing_server */
            MMI_FALSE, /* username_format */
            MMI_TRUE /* outgoing_auth */
        }
    #endif /* __SSL_SUPPORT__ */
#endif /* CUSTOM_EMAIL_PROFILE_TEMPLATES */
    };


typedef struct
{
    /* all operation is based on current status of roaming */
    MMI_BOOL roaming;
    /* This list is loaded from NVRAM when init Email */
    mmi_email_acct_sig_map acct_sig_list[MMI_EMAIL_SIG_MAX_NUMBER];
    /* This list is loaded from NVRAM when init Email */
    mmi_email_acct_auto_check_map acct_auto_check_list[MMI_EMAIL_AUTO_CHECK_MAX_NUMBER];
    eventid auto_check_eventid_list[MMI_EMAIL_AUTO_CHECK_MAX_NUMBER];
    async_callback callback;
    void *user_data;
    EMAIL_ACCT_ID curr_acct;
    S32 sig_image_index;
    auto_check_nofity_fn nofity_fn;
    MMI_TIMER_IDS auto_check_timers[MMI_EMAIL_AUTO_CHECK_MAX_NUMBER];
    EMAIL_ACCT_ID auto_check_acct_id_array[MMI_EMAIL_AUTO_CHECK_MAX_NUMBER];
} mmi_email_app_core_context_struct;


#ifdef __MMI_EMAIL_IMAP_PUSH__
typedef struct
{
    MMI_BOOL feature_on;
    MMI_BOOL acct_on[MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER];
} mmi_email_imap_push_cntx_struct;
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

mmi_email_app_core_context_struct g_mmi_email_app_core_cntx;
mmi_email_app_core_context_struct *mmi_email_app_core_cntx_p;

/* content template */
static void mmi_email_cont_temp_init(void);
static mmi_email_app_core_result_enum mmi_email_cont_temp_read_text(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len);
static mmi_email_app_core_result_enum mmi_email_cont_temp_clear_text(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index);
static mmi_email_app_core_result_enum mmi_email_cont_temp_write_text(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len);
static void mmi_email_cont_temp_get_file_path(WCHAR *file_path, U16 len);

/* account template */
static mmi_email_app_core_result_enum mmi_email_acct_temp_read_acct(
                                S32 index,
                                mmi_email_acct_temp_struct *acct_temp);

/* signature */
static void mmi_email_sig_init(void);
static void mmi_email_sig_reset(void);
static mmi_ret mmi_email_sig_add_image_callback(mmi_event_struct *param);
static mmi_ret mmi_email_sig_edit_image_callback(mmi_event_struct *param);
static mmi_ret mmi_email_sig_copy_image_callback(mmi_event_struct *param);
static mmi_email_app_core_result_enum mmi_email_sig_read_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_sig_struct *signature);
static mmi_email_app_core_result_enum mmi_email_sig_write_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_sig_struct *signature);
static mmi_email_app_core_result_enum mmi_email_sig_read_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_sig_map *sig_map);
static mmi_email_app_core_result_enum mmi_email_sig_write_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_sig_map *sig_map);
static void mmi_email_sig_get_file_path(WCHAR *file_path, U16 len, MMI_BOOL map);
static mmi_email_app_core_result_enum mmi_email_sig_acct_check(EMAIL_ACCT_ID acct_id);

/* auto check */
static void mmi_email_auto_check_init(void);
static mmi_email_app_core_result_enum mmi_email_auto_check_read_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_auto_check_struct *auto_check_data);
static mmi_email_app_core_result_enum mmi_email_auto_check_write_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_auto_check_struct *auto_check_data);
static mmi_email_app_core_result_enum mmi_email_auto_check_write_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_auto_check_map *auto_check_map);
static mmi_email_app_core_result_enum mmi_email_auto_check_read_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_auto_check_map *auto_check_map);
static U32 mmi_email_auto_check_get_time_out(EMAIL_ACCT_ID acct_id);
static void mmi_email_auto_check_get_file_path(WCHAR *file_path, U16 len, MMI_BOOL map);
static mmi_email_app_core_result_enum mmi_email_auto_check_acct_check(EMAIL_ACCT_ID acct_id);
static void mmi_email_auto_check_time_out_handle(void *data);

/* imap push */
#ifdef __MMI_EMAIL_IMAP_PUSH__
static void mmi_email_imap_push_init(void);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_core_init
 * DESCRIPTION
 *  This function is used to initialize context of app core.
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern void mmi_email_app_core_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *dir_path = NULL;
    /*S32 result;*/
#ifdef __MMI_EMAIL_IMAP_PUSH__
    MMI_BOOL status = MMI_FALSE;
    U32 count = 10;
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_CORE_INIT, __LINE__);

    dir_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    mmi_email_app_core_cntx_p = &g_mmi_email_app_core_cntx;
    kal_wsprintf(dir_path, "%s%s", srv_email_get_root_path(), app_core_path);
    /*result =*/ FS_CreateDir(dir_path);
    kal_wsprintf(dir_path, "%s%s%s", srv_email_get_root_path(), app_core_path, sig_image_path);
    /*result = */FS_CreateDir(dir_path);
    free_ctrl_buffer(dir_path);

    mmi_email_cont_temp_init();

    mmi_email_sig_init();
    mmi_email_auto_check_init();
#ifdef __MMI_EMAIL_IMAP_PUSH__
    mmi_email_imap_push_init();
#endif /* __MMI_EMAIL_IMAP_PUSH__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_core_init
 * DESCRIPTION
 *  This function is used to initialize context of app core.
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_cont_temp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path;
    FS_HANDLE file_handle;
    WCHAR *cont_temp;
    CHAR tempLang[SSC_SIZE];
    CHAR *str_ptr;
    U8 i;
    U8 j;
    S16 k = 0;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_INIT, __LINE__);

    file_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    cont_temp = (WCHAR*)get_ctrl_buffer((MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2);
    mmi_email_cont_temp_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle >= 0)
    {
        FS_GetFileSize(file_handle, &size);
        /* handle situation of return error */
        FS_Close(file_handle);
        if (size == MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG *
                    MMI_EMAIL_CONT_TEMP_TYPE_END_OF_ENUM *
                    (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2)
        {
            /* full size of file */
            free_ctrl_buffer(cont_temp);
            free_ctrl_buffer(file_path);
            return;
        }
        /* partial init */
        FS_Delete(file_path);
    }
    file_handle = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        free_ctrl_buffer(cont_temp);
        return;
    }
    FS_Close(file_handle);
    memcpy(curr_lang, (CHAR*)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SIZE);
    for (i = 0; i < MMI_EMAIL_CONT_TEMP_TYPE_USER_DEFINED; i++)
    {
        /* set system language */
        memset(tempLang, 0, SSC_SIZE);
        switch (i)
        {
        case MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED_ENG:
            memcpy(tempLang, SSC_ENGLISH, SSC_SIZE);
            break;
        case MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED_SC:
            memcpy(tempLang, SSC_SCHINESE, SSC_SIZE);
            break;
        case MMI_EMAIL_CONT_TEMP_TYPE_PRE_DEFINED_TC:
            memcpy(tempLang, SSC_TCHINESE, SSC_SIZE);
            break;
        }

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
        srv_setting_set_language_ext((U8 *)tempLang);      
#else
        k = mmi_lang_support((U8 *)tempLang);
        if (k >= 0)
            {
            srv_setting_set_language_ext((U8)k);
        }
#endif

        /* set system language */
        for (j = 0; j < MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG; j++)
        {
            str_ptr = GetString((U16)(STR_EMAIL_TEMPLATE_1 + j));
            if (mmi_ucs2strlen(str_ptr) >= MMI_EMAIL_CONT_TEMP_MAX_LEN + 1)
            {
                memcpy(cont_temp, str_ptr, (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2);
            }
            else
            {
                memcpy(cont_temp, str_ptr, mmi_ucs2strlen(str_ptr) * 2);
                cont_temp[mmi_ucs2strlen(str_ptr)] = 0;
            }
            mmi_email_cont_temp_write_text((mmi_email_cont_temp_type_enum)i, j, cont_temp, (U16)(MMI_EMAIL_CONT_TEMP_MAX_LEN + 1));
        }
    }
    /* reset system language */

 #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    srv_setting_set_language_ext((U8 *)curr_lang);      
 #else
    k = mmi_lang_support((U8 *)curr_lang);
    if (k >= 0)
    {
        srv_setting_set_language_ext((U8)k);
    }
 #endif

    /* reset system language */
    /* init user define */
    cont_temp[0] = 0;
    for (i = 0; i < MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG; i++)
    {
        mmi_email_cont_temp_write_text(MMI_EMAIL_CONT_TEMP_TYPE_USER_DEFINED, i, cont_temp, (U16)(MMI_EMAIL_CONT_TEMP_MAX_LEN + 1));
    }
    free_ctrl_buffer(cont_temp);
    /* init user define */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_get_valid_number
 * DESCRIPTION
 *  This function is used to get number of content template.
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  number          : [OUT] Total content template number
 * RETURNS
 *  result of this operation
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_cont_temp_get_valid_number(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR text[MMI_EMAIL_CONT_TEMP_MAX_LEN + 1];
    mmi_email_app_core_result_enum result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_GET_VALID_NUMBER, __LINE__);

    if (number == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    *number = 0;
    for (i = 0; i < MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG; i++)
    {
        result = mmi_email_cont_temp_read_text(
                    type,
                    i,
                    text,
                    (U16)(MMI_EMAIL_CONT_TEMP_MAX_LEN + 1));
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        if (mmi_wcslen(text) != 0)
        {
            (*number)++;
        }
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_read
 * DESCRIPTION
 *  This function is used to get text of content template.
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  index           : [IN]  The index of content template
 *  buff_len        : [IN]  The length of buffer to store content template
 *  text            : [OUT] The buffer used to store text of content template
 * RETURNS
 *  result of this operation
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_cont_temp_read(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_READ, __LINE__);

    if (text == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    return mmi_email_cont_temp_read_text(type, index, text, len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_edit
 * DESCRIPTION
 *  This function is used to edit text of content template.
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  index           : [IN]  The index of content template
 *  buff_len        : [IN]  The length of buffer to store content template
 *  text            : [OUT] The buffer used to store text of content template
 * RETURNS
 *  result of this operation
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_cont_temp_edit(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_EDIT, __LINE__);
    return mmi_email_cont_temp_write_text(type, index, text, len);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_clear
 * DESCRIPTION
 *  This function is used to delete one content template.
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  index           : [IN]  The index of content template app want to delete
 * RETURNS
 *  result of this operation
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_cont_temp_clear(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_CLEAR, __LINE__);
    return mmi_email_cont_temp_clear_text(type, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_read_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  index           : [IN]  The index of content template
 *  buff_len        : [IN]  The length of buffer to store content template
 *  text            : [OUT] The buffer used to store text of content template
 * RETURNS
 *  result of this operation
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_cont_temp_read_text(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *temp_text;
    WCHAR *file_path;
    FS_HANDLE file_handle;
    S32 result;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_READ_TEXT, __LINE__);

    if (text == NULL || index >= MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG)
    {
        return MMI_EMAIL_FAIL;
    }
    temp_text = (WCHAR*)get_ctrl_buffer((MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2);
    file_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);

    mmi_email_cont_temp_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        free_ctrl_buffer(temp_text);
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(
                file_handle,
                (type * MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG + index) * (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2,
                FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        free_ctrl_buffer(temp_text);
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Read(file_handle, temp_text, (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2, &read);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR || read != (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2)
    {
        free_ctrl_buffer(temp_text);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    if (len >= MMI_EMAIL_CONT_TEMP_MAX_LEN + 1)
    {
        mmi_wcsncpy(text, temp_text, MMI_EMAIL_CONT_TEMP_MAX_LEN);
        text[MMI_EMAIL_CONT_TEMP_MAX_LEN] = 0;
    }
    else
    {
        mmi_wcsncpy(text, temp_text, len - 1);
        text[len - 1] = 0;
    }
    free_ctrl_buffer(temp_text);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_clear_text
 * DESCRIPTION
 *  This function is used to clear text of content template
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  index           : [IN]  The index of content template
 * RETURNS
 *  result of this operation
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_cont_temp_clear_text(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *empty_text;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_CLEAR_TEXT, __LINE__);

    empty_text = (WCHAR*)get_ctrl_buffer((MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2);
    empty_text[0] = 0;
    result =  mmi_email_cont_temp_write_text(type, index, empty_text, MMI_EMAIL_CONT_TEMP_MAX_LEN + 1);
    free_ctrl_buffer(empty_text);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_write_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            : [IN]  Whitch type of template
 *  index           : [IN]  The index of content template
 *  buff_len        : [IN]  The length of buffer to store content template
 *  text            : [OUT] The buffer used to store text of content template
 * RETURNS
 *  result of this operation
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_cont_temp_write_text(
                                        mmi_email_cont_temp_type_enum type,
                                        U16 index,
                                        WCHAR *text,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *temp_text;
    WCHAR *file_path;
    FS_HANDLE file_handle;
    S32 result;
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_WRITE_TEXT, __LINE__);

    if (text == NULL || index >= MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG)
    {
        return MMI_EMAIL_FAIL;
    }
    temp_text = (WCHAR*)get_ctrl_buffer((MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2);
    file_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);

    mmi_email_cont_temp_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        free_ctrl_buffer(temp_text);
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(
                file_handle,
                (type * MMI_EMAIL_CONT_TEMP_MAX_NUMBER_PRE_LANG + index) * (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2,
                FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        free_ctrl_buffer(temp_text);
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    memset(temp_text, 0, (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2);
    if (len >= MMI_EMAIL_CONT_TEMP_MAX_LEN + 1)
    {
        mmi_wcsncpy(temp_text, text, MMI_EMAIL_CONT_TEMP_MAX_LEN);
        temp_text[MMI_EMAIL_CONT_TEMP_MAX_LEN] = 0;
    }
    else
    {
        mmi_wcsncpy(temp_text, text, len - 1);
    }
    result = FS_Write(file_handle, temp_text, (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2, &written);
    FS_Close(file_handle);
    free_ctrl_buffer(temp_text);
    if (result != FS_NO_ERROR || written != (MMI_EMAIL_CONT_TEMP_MAX_LEN + 1) * 2)
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_temp_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_cont_temp_get_file_path(WCHAR *file_path, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_CONT_TEMP_GET_FILE_PATH, __LINE__);

    if (len < mmi_ucs2strlen(srv_email_get_root_path()) + strlen(app_core_path) + strlen(cont_temp_file) + 1)
    {
        return;
    }
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, cont_temp_file);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emaildata_autofind
 * DESCRIPTION
 *  This function is used to get next autofind
 * PARAMETERS
 *  autofind           : [IN]  Result of find
 * RETURNS
 *  
 ****************************************************************************/
extern applib_address_node_struct* mmi_email_emaildata_autofind(
                                    CHAR *text,
                                    MMI_BOOL text_type,
                                    U32 len,
                                    applib_addr_type_enum type,
                                    applib_mem_alloc_fn mem_alloc,
                                    applib_mem_free_fn mem_free,
                                    applib_check_stop_fn check_stop_fn,
                                    applib_charset_enum input_data_type,
                                    MMI_BOOL *is_stopped)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *addr_list_head = NULL;
    applib_address_node_struct *addr_list_tail = NULL;
    applib_address_node_struct *temp_node_ptr;
    //S32 curr_page;
    U32 offset;
    CHAR *buff = NULL;
    FS_HANDLE file_handle;
    U32 file_len;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_EMAILDATA_AUTOFIND, __LINE__);

    if (text == NULL)
    {
        return NULL;
    }
    if (text_type == MMI_TRUE) /* real buffer */
    {
        if (len == 0)
        {
            return NULL;
        }
        return applib_get_address_list_from_text_ext(
                type,
                mem_alloc,
                mem_free,
                check_stop_fn,
                input_data_type,
                text,
                len,
                is_stopped);
    }
    else /* get content from file */
    {
        file_handle = FS_Open((WCHAR*)text, FS_READ_ONLY);
        if (file_handle < 0)
        {
            g_fs_error_detail = file_handle;
            return NULL;
        }
        FS_GetFileSize(file_handle, &file_len);
        buff = (CHAR*)get_ctrl_buffer(1024 * 2);
        if (file_len <= 1024 * 2) /* 2K */
        {
            FS_Read(file_handle, buff, 1024 * 2, &read);
            return applib_get_address_list_from_text_ext(
                    type,
                    mem_alloc,
                    mem_free,
                    check_stop_fn,
                    input_data_type,
                    buff,
                    read,
                    is_stopped);
        }
        else
        {
            //curr_page = 0;
            do
            {
                FS_GetFilePosition(file_handle, &offset);
                FS_Read(file_handle, buff, 1024 * 2, &read);
                temp_node_ptr = applib_get_address_list_from_text_ext(
                                    type,
                                    mem_alloc,
                                    mem_free,
                                    check_stop_fn,
                                    input_data_type,
                                    buff,
                                    read,
                                    is_stopped);
                if (temp_node_ptr != NULL)
                {
                    if (addr_list_head == NULL)
                    {
                        addr_list_head = temp_node_ptr;
                        addr_list_tail = addr_list_head;
                    }
                    else
                    {
                        addr_list_tail->next = temp_node_ptr;
                    }
                    while (addr_list_tail->next != NULL)
                    {
                        addr_list_tail->pos += offset;
                        addr_list_tail = addr_list_tail->next;
                    }
                }
                if (addr_list_tail->pos + addr_list_tail->length- offset >= 1024 * 2 - 100) /* max address len */
                {
                    FS_Seek(
                        file_handle,
                        offset + 1024 * 2 -(addr_list_tail->pos + addr_list_tail->length),
                        FS_FILE_CURRENT);
                }
                else
                {
                    FS_Seek(file_handle, 100, FS_FILE_CURRENT);
                }
            } while (read != 1024 * 2);
        }
    }
    return addr_list_head;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emaildata_disp_name_to_addr
 * DESCRIPTION
 *  This function is used to get address by display name
 *  This function only can find first contact with same display name.
 * PARAMETERS
 *  disp_name          : [IN]  Display name
 *  len_1              : [IN]  Length of buffer for first address
 *  addr_1             : [OUT] Buffer to store first address
 *  len_2              : [IN]  Length of buffer for second address
 *  addr_2             : [OUT] Buffer to store second address
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_emaildata_disp_name_to_addr(
                                        WCHAR *disp_name,
                                        U16 len_1,
                                        WCHAR *addr_1,
                                        U16 len_2,
                                        WCHAR *addr_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 contact_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_EMAILDATA_DISP_NAME_TO_ADDR, __LINE__);

    if (disp_name == NULL || (addr_1 == NULL && addr_2 == NULL))
    {
        return MMI_EMAIL_FAIL;
    }
    contact_id = srv_phb_oplib_search(disp_name, SRV_PHB_SEARCH_TYPE_NAME);
    if (contact_id < 0)
    {
        return MMI_EMAIL_FAIL; /* error code of phb */
    }
    /* (*addr) = 0 when no email address is found */
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (addr_1 != NULL)
    {
        srv_phb_get_email_address(contact_id, addr_1, len_1);
    }
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (addr_2 != NULL)
    {
        srv_phb_get_email_address2(contact_id, addr_2, len_2);
    }
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__*/
    #endif /* __MMI_PHB_OPTIONAL_FIELD__*/
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_emaildata_group_to_addr
 * DESCRIPTION
 *  This function is used to get address by group
 * PARAMETERS
 *  group              : [IN]  Group name
 *  addr_num           : [IN/OUT] Address number app want or app core given
 *  len                : [IN]  Length of buffer for address
 *  addr_list          : [OUT] Buffer to store address
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_emaildata_group_to_addr(
                                        WCHAR *group,
                                        S32 *addr_num,
                                        U16 addr_len,
                                        WCHAR **addr_list_1,
                                        WCHAR **addr_list_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_list[MMI_PHB_GROUP_COUNT];
    U16 *contact_list = NULL;
    /* (20 * (20 + 1)) * 2 */
    WCHAR group_name_list[MMI_PHB_GROUP_COUNT * (MMI_PHB_GROUP_NAME_LENGTH + 1)];
    U8 group_number; 
    S32 contact_number;
    U8 i;
    srv_phb_group_filter_struct group_filter =
    {
        0,
        MMI_TRUE
    };
    srv_phb_filter_struct filter =
    {
        PHB_STORAGE_MAX,
        SRV_PHB_INVALID_INDEX,
        NULL,
        NULL
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_EMAILDATA_GROUP_TO_ADDR, __LINE__);

    if (group == NULL || addr_num == NULL || (addr_list_1 == NULL && addr_list_2 == NULL))
    {
        return MMI_EMAIL_FAIL;
    }
    //group_number = srv_phb_datamgr_get_group_list(group_list, group_name_list);
    group_number = srv_phb_get_group_list(group_list, group_name_list, PHB_STORAGE_NVRAM);
    for (i = 0; i < group_number; i++)
    {
        if (mmi_ucs2cmp((CHAR*)(group_name_list + (MMI_PHB_GROUP_NAME_LENGTH + 1) * i), (CHAR*)group) == 0)
        {
            break;
        }
    }
    if (i == group_number)
    {
        return MMI_EMAIL_FAIL;
    }
    group_filter.group_mask = group_list[i];
    filter.group_filter = &group_filter;
    contact_list = (U16*)get_ctrl_buffer((*addr_num) * 2);
    contact_number = srv_phb_oplib_build_contact_list(&filter, contact_list, *addr_num);
    if (contact_number < 0)
    {
        free_ctrl_buffer(contact_list);
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < *addr_num; i++)
    {
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if (addr_list_1 != NULL && *addr_list_1 != NULL)
        {
            srv_phb_get_email_address(contact_list[i], addr_list_1[i], addr_len);
        }

        #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        if (addr_list_2 != NULL && *addr_list_2 != NULL)
        {
            srv_phb_get_email_address2(contact_list[i], addr_list_1[i], addr_len);
        }
        #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__*/
        #endif /* __MMI_PHB_OPTIONAL_FIELD__*/
    }
    free_ctrl_buffer(contact_list);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_acct_temp_get_num
 * DESCRIPTION
 *  This function is used to get number of account template
 * PARAMETERS
 *  num                : [OUT]  The number of account template
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_acct_temp_get_num(S32 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCT_TEMP_GET_NUM, __LINE__);

    if (num == NULL)
    {
        return MMI_EMAIL_FAIL;
    }

    *num = sizeof(acct_template_list) / sizeof(mmi_email_acct_temp_struct);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_acct_temp_check_addr
 * DESCRIPTION
 *  This function is used to check if account template with same email address exist
 * PARAMETERS
 *  addr               : [IN]  Buffer to store the address
 *  index              : [IN]  The match index of account template
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_acct_temp_check_addr(
                                        WCHAR *addr,
                                        S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    mmi_email_app_core_result_enum result;
    mmi_email_acct_temp_struct acct_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCT_TEMP_CHECK_ADDR, __LINE__);

    if (addr == NULL || index == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    *index = -1;
    for (i = 0; i < MMI_EMAIL_ACCT_TEMP_MAX_NUMBER; i++)
    {
        result = mmi_email_acct_temp_read_acct(i, &acct_temp);
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        if (mmi_ucs2cmp((CHAR*)acct_temp.addr, (CHAR*)addr) == 0)
        {
            *index = i;
            break;
        }
    }
    if (i == MMI_EMAIL_ACCT_TEMP_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    else
    {
        return MMI_EMAIL_SUCCESS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_acct_temp_get_acct
 * DESCRIPTION
 *  This function is used to get information of certain account template
 * PARAMETERS
 *  index              : [IN]  Index of account template
 *  acct_temp          : [IN]  Buffer to store information of account template
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_acct_temp_get_acct(
                                        S32 index,
                                        mmi_email_acct_temp_struct *acct_temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCT_TEMP_GET_ACCT, __LINE__);

    if (acct_temp == NULL ||
        index < 0 ||
        index >= MMI_EMAIL_ACCT_TEMP_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    return mmi_email_acct_temp_read_acct(index, acct_temp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_acct_temp_read_acct
 * DESCRIPTION
 *  This function is used to read account template from NVRAM
 * PARAMETERS
 *  index              : [IN]  Index of account template
 *  acct_temp          : [IN]  Buffer to store information of account template
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_acct_temp_read_acct(
                                        S32 index,
                                        mmi_email_acct_temp_struct *acct_temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_ACCT_TEMP_READ_ACCT, __LINE__);

    if (acct_temp == NULL)
    {
        return MMI_EMAIL_FAIL;
    }

    memcpy(acct_temp, &acct_template_list[index], sizeof(mmi_email_acct_temp_struct));
    return MMI_EMAIL_SUCCESS;
}


mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_num(S32 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 acct_template_group_num = 0;
    U32 acct_template_num = sizeof(acct_template_list) / sizeof(mmi_email_acct_temp_struct);
    U32 i = 0;
    U32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < acct_template_num; i++)
    {
        MMI_BOOL is_new_group = MMI_TRUE;
        for (j = 0; j < i; j++)
        {
            if (mmi_wcscmp(acct_template_list[j].acct_name, acct_template_list[i].acct_name) == 0)
            {
                is_new_group = MMI_FALSE;
    }
        }
        if (is_new_group == MMI_TRUE)
        {
            acct_template_group_num++;
        }
    }
    *num = acct_template_group_num;
    return MMI_EMAIL_SUCCESS;
}


mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_name(
                                S32 index,
                                WCHAR *group_name,
                                S32 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 acct_template_group_num = 0;
    U32 acct_template_num = sizeof(acct_template_list) / sizeof(mmi_email_acct_temp_struct);
    U32 i = 0;
    U32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_name == NULL || name_len < SRV_EMAIL_MAX_ACCT_NAME_LEN + 1)
    {
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < acct_template_num; i++)
    {
        MMI_BOOL is_new_group = MMI_TRUE;
        for (j = 0; j < i; j++)
        {
            if (mmi_wcscmp(acct_template_list[j].acct_name, acct_template_list[i].acct_name) == 0)
            {
                is_new_group = MMI_FALSE;
        }
    }
        if (is_new_group == MMI_TRUE)
        {
            acct_template_group_num++;
        }
        if (acct_template_group_num == index + 1)
        {
            mmi_wcscpy(group_name, acct_template_list[i].acct_name);
            return MMI_EMAIL_SUCCESS;
        }
    }
    return MMI_EMAIL_FAIL;
}


mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_data_num(WCHAR *group_name, S32 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acct_template_num = sizeof(acct_template_list) / sizeof(mmi_email_acct_temp_struct);
    U32 i = 0;
    U32 group_data_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_name == NULL || num == NULL)
    {
        return MMI_EMAIL_FAIL;
}
    for (i = 0; i < acct_template_num; i++)
{
        if (mmi_wcscmp(group_name, acct_template_list[i].acct_name) == 0)
{
            group_data_num++;
}
    }
    *num = group_data_num;
    return MMI_EMAIL_SUCCESS;
}


mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_data_all(
                                WCHAR *group_name,
                                S32 *num,
                                mmi_email_acct_temp_struct *acct_temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 acct_template_num = sizeof(acct_template_list) / sizeof(mmi_email_acct_temp_struct);
    S32 i = 0;
    S32 group_data_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_name == NULL || num == NULL || acct_temp == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < acct_template_num; i++)
    {
        if (group_data_num >= *num)
        {
            return MMI_EMAIL_SUCCESS;
        }
        if (mmi_wcscmp(group_name, acct_template_list[i].acct_name) == 0)
        {
            memcpy(acct_temp + group_data_num, &acct_template_list[i], sizeof(mmi_email_acct_temp_struct));
            group_data_num++;
        }
    }
    *num = group_data_num;
    return MMI_EMAIL_SUCCESS;
}


mmi_email_app_core_result_enum mmi_email_acct_temp_get_group_data_by_index(
                                WCHAR *group_name,
                                S32 index,
                                mmi_email_acct_temp_struct *acct_temp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acct_template_num = sizeof(acct_template_list) / sizeof(mmi_email_acct_temp_struct);
    U32 i = 0;
    U32 group_data_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_name == NULL || acct_temp == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < acct_template_num; i++)
    {
        if (mmi_wcscmp(group_name, acct_template_list[i].acct_name) == 0)
        {
            group_data_num++;
            if (index == group_data_num - 1)
            {
                memcpy(acct_temp, &acct_template_list[i], sizeof(mmi_email_acct_temp_struct));
                return MMI_EMAIL_SUCCESS;
            }
        }
    }
    return MMI_EMAIL_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_create
 * DESCRIPTION
 *  This function is used for account to create new signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_create(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_acct_sig_map acct_sig_map;
    mmi_email_app_core_result_enum result;
    S32 fs_result;
    U32 read;
    FS_HANDLE file_handle;
    WCHAR *file_path;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_CREATE, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result == MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_ALREADY_EXIST;
    }
    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        fs_result = FS_Read(file_handle, &signature, sizeof(mmi_email_sig_struct), &read);
        if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_sig_struct))
        {
            FS_Close(file_handle);
            g_fs_error_detail = fs_result;
            return MMI_EMAIL_FAIL;
        }
        if (signature.validity == MMI_FALSE)
        {
            break;
        }
    }
    FS_Close(file_handle);
    if (i == MMI_EMAIL_SIG_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    acct_sig_map.status = MMI_FALSE;
    acct_sig_map.acct_id = acct_id;
    acct_sig_map.sig_id = (MMI_EMAIL_SIG_ID)(i + 1);
    result = mmi_email_sig_write_map(acct_id, &acct_sig_map);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memcpy(
        &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
        &acct_sig_map,
        sizeof(mmi_email_acct_sig_map));
    memset(&signature, 0, sizeof(mmi_email_sig_struct));
    signature.image_num = 0;
    signature.user_num = 1;
    signature.validity = MMI_TRUE;
    result = mmi_email_sig_write_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        acct_sig_map.acct_id = 0;
        acct_sig_map.sig_id = 0;
        acct_sig_map.status = MMI_FALSE;
        mmi_email_sig_write_map(acct_id, &acct_sig_map);
        memcpy(
            &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
            &acct_sig_map,
            sizeof(mmi_email_acct_sig_map));
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_list_acct_id
 * DESCRIPTION
 *  This function is used for account to create new signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_list_acct_id(
                                        EMAIL_ACCT_ID *acct_id_list,
                                        U16 *array_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_acct_sig_map sig_map;
    mmi_email_app_core_result_enum result;
    U16 index = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_LIST_ACCT_ID, __LINE__);

    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        result = mmi_email_sig_read_map((EMAIL_ACCT_ID)(i + 1), &sig_map);
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        if (sig_map.acct_id != EMAIL_ACCT_INVALID_ID)
        {
            acct_id_list[index] = sig_map.acct_id;
            index++;
            if (index >= *array_len)
            {
                break;
            }
        }
    }
    *array_len = index;
    for (i = index; i < *array_len; i++)
    {
        acct_id_list[i] = EMAIL_ACCT_INVALID_ID;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_list_id
 * DESCRIPTION
 *  This function is used for account to create new signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_list_id(
                                        MMI_EMAIL_SIG_ID *sig_id_list,
                                        U16 *array_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;
    U16 index = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_LIST_ID, __LINE__);

    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        result = mmi_email_sig_read_info((EMAIL_ACCT_ID)(i + 1), &signature);
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        if (signature.validity == MMI_TRUE)
        {
            sig_id_list[index] = (MMI_EMAIL_SIG_ID)(i + 1);
            index++;
            if (index >= *array_len)
            {
                break;
            }
        }
    }
    *array_len = index;
    for (i = index; i < *array_len; i++)
    {
        sig_id_list[i] = 0;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_use_exist
 * DESCRIPTION
 *  This function is used for account use exist signature as its signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 *  index              : [IN]  Index of signature app want this account to use
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_use_exist(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_EMAIL_SIG_ID sig_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_acct_sig_map acct_sig_map;
    //S16 error;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_USE_EXIST, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result == MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_ALREADY_EXIST;
    }
    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_SIG_MAX_NUMBER ||
        sig_id <= 0 ||
        sig_id > MMI_EMAIL_SIG_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }

    acct_sig_map.sig_id = sig_id;
    acct_sig_map.acct_id = acct_id;
    acct_sig_map.status = MMI_TRUE;
    result = mmi_email_sig_write_map(acct_id, &acct_sig_map);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memcpy(
        &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
        &acct_sig_map,
        sizeof(mmi_email_acct_sig_map));
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        acct_sig_map.sig_id = 0;
        acct_sig_map.acct_id = 0;
        acct_sig_map.status = MMI_FALSE;
        mmi_email_sig_write_map(acct_id, &acct_sig_map);
        memset(
            &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
            0,
            sizeof(mmi_email_acct_sig_map));
        return result;
    }
    signature.user_num++;
    result = mmi_email_sig_write_info(sig_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        acct_sig_map.acct_id = 0;
        acct_sig_map.sig_id = 0;
        acct_sig_map.status = MMI_FALSE;
        mmi_email_sig_write_map(acct_id, &acct_sig_map);
        memset(
            &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
            0,
            sizeof(mmi_email_acct_sig_map));
        return result;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_create
 * DESCRIPTION
 *  This function is used for account to create new signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_delete_acct(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL destroy_sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_DELETE_ACCT, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    signature.user_num--;
    if (signature.user_num == 0 || destroy_sig == MMI_TRUE)
    {
        result = mmi_email_sig_delete_all_image(acct_id);
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        memset(&signature, 0, sizeof(mmi_email_sig_struct));
    }
    result = mmi_email_sig_write_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        /* images already deleted */
        return result;
    }
    mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].sig_id = 0;
    mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].acct_id = 0;
    mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].status = MMI_FALSE;
    /* could not roll back even write file failed */
    mmi_email_sig_write_map(acct_id, &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)]);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_get_status
 * DESCRIPTION
 *  This function is used to get status (On or Off) of one accout
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to get the right status of signature
 *  status             : [OUT] Used to store the status of signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_get_status(EMAIL_ACCT_ID acct_id, MMI_BOOL *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_GET_STATUS, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (status == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    *status = mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].status;
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_set_status
 * DESCRIPTION
 *  This function is used to set status of one accout
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right status of signature
 *  status             : [IN]  Used to store the status of signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_set_status(EMAIL_ACCT_ID acct_id, MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum result;
    MMI_BOOL org_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_SET_STATUS, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    org_status = mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].status;
    mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].status = status;
    result = mmi_email_sig_write_map(acct_id, &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)]);
    if (result != MMI_EMAIL_SUCCESS)
    {
        mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].status = org_status;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_get_signature
 * DESCRIPTION
 *  This function is used to get whole information of one accout's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to get the right signature
 *  signature          : [OUT] The buffer used to store the signature certian account
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_get_signature(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_sig_struct *signature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_GET_SIGNATURE, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    return mmi_email_sig_read_info(acct_id, signature);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_get_text
 * DESCRIPTION
 *  This function is used to get text of one accout's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 *  buff_len           : [IN]  The length of buffer
 *  text               : [OUT] The buffer used to store the text of signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_get_text(
                                        EMAIL_ACCT_ID acct_id,
                                        WCHAR *text,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_GET_TEXT, __LINE__);

    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (len >= MMI_EMAIL_SIG_MAX_TEXT_LEN + 1)
    {
        mmi_wcsncpy(text, signature.text, MMI_EMAIL_SIG_MAX_TEXT_LEN);
        text[MMI_EMAIL_SIG_MAX_TEXT_LEN] = 0;
    }
    else
    {
        mmi_wcsncpy(text, signature.text, len - 1);
        text[len - 1] = 0;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_set_text
 * DESCRIPTION
 *  This function is used to set text of one accout's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 *  buff_len           : [IN]  The length of buffer
 *  text               : [IN]  The buffer used to store the text of signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_set_text(
                                        EMAIL_ACCT_ID acct_id,
                                        WCHAR *text,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_SET_TEXT, __LINE__);

    if (text == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memset(signature.text, 0, (MMI_EMAIL_SIG_MAX_TEXT_LEN + 1) * 2);
    if (len > MMI_EMAIL_SIG_MAX_TEXT_LEN + 1)
    {
        mmi_wcsncpy(signature.text, text, MMI_EMAIL_SIG_MAX_TEXT_LEN);
        signature.text[MMI_EMAIL_SIG_MAX_TEXT_LEN] = 0;
    }
    else
    {
        mmi_wcsncpy(signature.text, text, len - 1);
    }
    return mmi_email_sig_write_info(acct_id, &signature);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_clear_text
 * DESCRIPTION
 *  This function is used to clear text of one accout's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to clear the right signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_clear_text(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_CLEAR_TEXT, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memset(signature.text, 0, (MMI_EMAIL_SIG_MAX_TEXT_LEN + 1) * 2);
    return mmi_email_sig_write_info(acct_id, &signature);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_add_image
 * DESCRIPTION
 *  This function is used to add a image as one account's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 *  image              : [IN]  Path of image added as a signature
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern S32 mmi_email_sig_add_image(
                                        EMAIL_ACCT_ID acct_id,
                                        WCHAR *image_path,
                                        async_callback callback,
                                        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    WCHAR *dst_path;
    WCHAR *image_name;
    mmi_email_app_core_result_enum result;
    S32 fmgr_result;
    WCHAR *ext_name;
    S32 ext_name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_ADD_IMAGE, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (image_path == NULL || mmi_wcslen(image_path) == 0)
    {
        return MMI_EMAIL_FAIL;
    }
    dst_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        free_ctrl_buffer(dst_path);
        return result;
    }
    if (signature.image_num >= MMI_EMAIL_SIG_MAX_IMAGE_NUMBER)
    {
        free_ctrl_buffer(dst_path);
        return MMI_EMAIL_FAIL;
    }
    image_name = (WCHAR*)srv_fmgr_path_get_filename_ptr(image_path);
    if (mmi_wcslen(image_name) >= EMAIL_ATTCH_FILE_NAME_LEN + 1)
    {
        ext_name = mmi_wcsrchr(image_name, L'.');
        if (ext_name != NULL)
        {
            ext_name_len = mmi_wcslen(ext_name);
            if (ext_name_len >= EMAIL_ATTCH_FILE_NAME_LEN + 1)
            {
                mmi_wcsncpy(signature.image_name[signature.image_num], image_name, EMAIL_ATTCH_FILE_NAME_LEN);
            }
            else
            {
                memcpy(signature.image_name[signature.image_num], image_name, (EMAIL_ATTCH_FILE_NAME_LEN - ext_name_len) * 2);
                memcpy(
                    signature.image_name[signature.image_num] + (EMAIL_ATTCH_FILE_NAME_LEN - ext_name_len),
                    ext_name,
                    ext_name_len * 2);
            }
            signature.image_name[signature.image_num][EMAIL_ATTCH_FILE_NAME_LEN] = 0;
        }
        else
        {
            mmi_wcsncpy(signature.image_name[signature.image_num], image_name, EMAIL_ATTCH_FILE_NAME_LEN);
            signature.image_name[signature.image_num][EMAIL_ATTCH_FILE_NAME_LEN] = 0;
        }
    }
    else
    {
        mmi_wcsncpy(signature.image_name[signature.image_num], image_name, mmi_wcslen(image_name));
        signature.image_name[signature.image_num][mmi_wcslen(image_name)] = 0;
    }
    signature.image_num++;
    result = mmi_email_sig_write_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        free_ctrl_buffer(dst_path);
        return MMI_EMAIL_FAIL;
    }
    mmi_email_app_core_cntx_p->curr_acct = acct_id;
    mmi_email_app_core_cntx_p->user_data = user_data;
    mmi_email_app_core_cntx_p->callback = callback;
    mmi_email_sig_get_image_path(acct_id, (U16)(signature.image_num - 1), dst_path, SRV_FMGR_PATH_MAX_LEN + 1);
    FS_Delete(dst_path);
    fmgr_result = srv_fmgr_async_copy(
                    image_path,
                    dst_path,
                    0,
                    mmi_email_sig_add_image_callback,
                    NULL);
    free_ctrl_buffer(dst_path);
    if (fmgr_result == 0)
    {
        return MMI_EMAIL_SUCCESS;
    }
    else if (fmgr_result < 0)
    {
        g_fs_error_detail = fmgr_result;
        mmi_email_sig_read_info(acct_id, &signature);
        signature.image_num--;
        memset(signature.image_name[signature.image_num], 0, (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
        mmi_email_sig_write_info(acct_id, &signature);
        return fmgr_result;
    }
    else
    {
        return MMI_EMAIL_WOULDBLOCK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_add_image_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_ret mmi_email_sig_add_image_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *async_evt;
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_ADD_IMAGE_CALLBACK, __LINE__);

    switch (param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            async_evt = (srv_fmgr_async_done_event_struct*)param;
            if (async_evt->result == 0)
            {
                if (mmi_email_app_core_cntx_p->callback != NULL)
                {
                    (*mmi_email_app_core_cntx_p->callback)(MMI_EMAIL_SUCCESS, mmi_email_app_core_cntx_p->user_data);
                }
            }
            else
            {
                g_fs_error_detail = async_evt->result;
                result = mmi_email_sig_read_info(mmi_email_app_core_cntx_p->curr_acct, &signature);
                if (result == MMI_EMAIL_SUCCESS)
                {
                    signature.image_num--;
                    memset(signature.image_name[signature.image_num], 0, (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
                    mmi_email_sig_write_info(mmi_email_app_core_cntx_p->curr_acct, &signature);
                }
                if (mmi_email_app_core_cntx_p->callback != NULL)
                {
                    (*mmi_email_app_core_cntx_p->callback)(async_evt->result, mmi_email_app_core_cntx_p->user_data);
                }
            }
            mmi_email_app_core_cntx_p->user_data = NULL;
            mmi_email_app_core_cntx_p->callback = NULL;
            mmi_email_app_core_cntx_p->curr_acct = EMAIL_ACCT_INVALID_ID;
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_edit_image
 * DESCRIPTION
 *  This function is used to edit the image of one account's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 *  index              : [IN]  Index of iamge of signature
 *  image              : [IN]  Path of image
 * RETURNS
 *  
 ****************************************************************************/
extern S32 mmi_email_sig_edit_image(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index,
                                        WCHAR *image_path,
                                        async_callback callback,
                                        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_sig_struct signature;
    WCHAR *dst_path;
    FS_HANDLE file_handle;
    WCHAR *image_name;
    S32 attr = 0;
    mmi_email_app_core_result_enum result;
    S32 fmgr_result;
    S16 i;
    WCHAR *ext_name;
    S32 ext_name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_EDIT_IMAGE, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (image_path == NULL || mmi_wcslen(image_path) == 0 || index >= MMI_EMAIL_SIG_MAX_IMAGE_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    dst_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    mmi_email_sig_get_image_path(acct_id, index, dst_path, SRV_FMGR_PATH_MAX_LEN + 1);
    if (mmi_wcscmp(dst_path, image_path) == 0)
    {
        free_ctrl_buffer(dst_path);
        return MMI_EMAIL_SUCCESS;
    }
    memset(&signature, 0, sizeof(mmi_email_sig_struct));
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        free_ctrl_buffer(dst_path);
        return result;
    }
    if (signature.image_num <= index)
    {
        free_ctrl_buffer(dst_path);
        return MMI_EMAIL_FAIL;
    }
    image_name = (WCHAR*)srv_fmgr_path_get_filename_ptr(image_path);
    if (mmi_wcslen(image_name) >= EMAIL_ATTCH_FILE_NAME_LEN + 1)
    {
        ext_name = mmi_wcsrchr(image_name, L'.');
        if (ext_name != NULL)
        {
            ext_name_len = mmi_wcslen(ext_name);
            if (ext_name_len >= EMAIL_ATTCH_FILE_NAME_LEN + 1)
            {
                mmi_wcsncpy(signature.image_name[index], image_name, EMAIL_ATTCH_FILE_NAME_LEN);
            }
            else
            {
                memcpy(signature.image_name[index], image_name, (EMAIL_ATTCH_FILE_NAME_LEN - ext_name_len) * 2);
                memcpy(
                    signature.image_name[index] + (EMAIL_ATTCH_FILE_NAME_LEN - ext_name_len),
                    ext_name,
                    ext_name_len * 2);
            }
            signature.image_name[index][EMAIL_ATTCH_FILE_NAME_LEN] = 0;
        }
        else
        {
            mmi_wcsncpy(signature.image_name[index], image_name, EMAIL_ATTCH_FILE_NAME_LEN);
            signature.image_name[index][EMAIL_ATTCH_FILE_NAME_LEN] = 0;
        }
    }
    else
    {
        mmi_wcsncpy(signature.image_name[index], image_name, mmi_wcslen(image_name));
        signature.image_name[index][mmi_wcslen(image_name)] = 0;
    }
    result = mmi_email_sig_write_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        free_ctrl_buffer(dst_path);
        return MMI_EMAIL_FAIL;
    }
    mmi_email_app_core_cntx_p->curr_acct = acct_id;
    mmi_email_app_core_cntx_p->user_data = user_data;
    mmi_email_app_core_cntx_p->callback = callback;
    mmi_email_app_core_cntx_p->sig_image_index = index;
    file_handle = FS_Open((U16*)dst_path, FS_READ_WRITE);
    if (file_handle > 0)
    {
        /* if read-only, reset it */
        attr = FS_GetAttributes((const WCHAR*)dst_path);
        if (attr & FS_ATTR_READ_ONLY)
        {
            FS_SetAttributes((const WCHAR*)dst_path, (U8)(attr & ~(FS_ATTR_READ_ONLY)));
        }
        FS_Close(file_handle);
    }
    FS_Delete(dst_path);
    fmgr_result = srv_fmgr_async_copy(
                    image_path,
                    dst_path,
                    0,
                    mmi_email_sig_edit_image_callback,
                    NULL);
    free_ctrl_buffer(dst_path);
    if (fmgr_result == 0)
    {
        return MMI_EMAIL_SUCCESS;
    }
    else if (fmgr_result < 0)
    {
        g_fs_error_detail = fmgr_result;
        mmi_email_sig_read_info(mmi_email_app_core_cntx_p->curr_acct, &signature);
        memset(
            signature.image_name[mmi_email_app_core_cntx_p->sig_image_index],
            0,
            (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
        for (i = mmi_email_app_core_cntx_p->sig_image_index; i < signature.image_num - 1; i++)
        {
            memcpy(
                signature.image_name[i],
                signature.image_name[i + 1],
                (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
        }
        memset(
            signature.image_name[signature.image_num - 1],
            0,
            (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
        signature.image_num--;
        mmi_email_sig_write_info(mmi_email_app_core_cntx_p->curr_acct, &signature);
        return fmgr_result;
    }
    else
    {
        return MMI_EMAIL_WOULDBLOCK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_edit_image_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_ret mmi_email_sig_edit_image_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *async_evt;
    mmi_email_sig_struct signature;
    mmi_email_app_core_result_enum result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_EDIT_IMAGE_CALLBACK, __LINE__);
    switch (param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            async_evt = (srv_fmgr_async_done_event_struct*)param;
            if (async_evt->result == 0)
            {
                if (mmi_email_app_core_cntx_p->callback != NULL)
                {
                    (*mmi_email_app_core_cntx_p->callback)(MMI_EMAIL_SUCCESS, mmi_email_app_core_cntx_p->user_data);
                }
            }
            else
            {
                g_fs_error_detail = async_evt->result;
                result = mmi_email_sig_read_info(mmi_email_app_core_cntx_p->curr_acct, &signature);
                if (result == MMI_EMAIL_SUCCESS)
                {
                    memset(
                        signature.image_name[mmi_email_app_core_cntx_p->sig_image_index],
                        0,
                        (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
                    for (i = mmi_email_app_core_cntx_p->sig_image_index; i < signature.image_num - 1; i++)
                    {
                        memcpy(
                            signature.image_name[i],
                            signature.image_name[i + 1],
                            (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
                    }
                    memset(
                        signature.image_name[signature.image_num - 1],
                        0,
                        (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
                    signature.image_num--;
                    mmi_email_sig_write_info(mmi_email_app_core_cntx_p->curr_acct, &signature);
                }
                if (mmi_email_app_core_cntx_p->callback != NULL)
                {
                    (*mmi_email_app_core_cntx_p->callback)(async_evt->result, mmi_email_app_core_cntx_p->user_data);
                }
            }
            mmi_email_app_core_cntx_p->user_data = NULL;
            mmi_email_app_core_cntx_p->callback = NULL;
            mmi_email_app_core_cntx_p->sig_image_index = -1;
            mmi_email_app_core_cntx_p->curr_acct = EMAIL_ACCT_INVALID_ID;
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_copy_image
 * DESCRIPTION
 *  This function is used to edit the image of one account's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 *  index              : [IN]  Index of iamge of signature
 *  dst_path           : [IN]  Destination path
 * RETURNS
 *  
 ****************************************************************************/
extern S32 mmi_email_sig_copy_image(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index,
                                        WCHAR *dst_path,
                                        async_callback callback,
                                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR image_path[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_email_app_core_result_enum result;
    S32 fmgr_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_COPY_IMAGE, __LINE__);
    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (dst_path == NULL || mmi_wcslen(dst_path) == 0 || index >= MMI_EMAIL_SIG_MAX_IMAGE_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_app_core_cntx_p->callback = callback;
    mmi_email_app_core_cntx_p->user_data = user_data;
    mmi_email_sig_get_image_path(acct_id, index, image_path, SRV_FMGR_PATH_MAX_LEN + 1);
    fmgr_result = srv_fmgr_async_copy(
                    image_path,
                    dst_path,
                    0,
                    mmi_email_sig_copy_image_callback,
                    NULL);
    free_ctrl_buffer(dst_path);
    if (fmgr_result == 0)
    {
        return MMI_EMAIL_SUCCESS;
    }
    else if (fmgr_result < 0)
    {
        g_fs_error_detail = fmgr_result;
        return fmgr_result;
    }
    else
    {
        return MMI_EMAIL_WOULDBLOCK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_copy_image_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_ret mmi_email_sig_copy_image_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *async_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_COPY_IMAGE_CALLBACK, __LINE__);

    switch (param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            async_evt = (srv_fmgr_async_done_event_struct*)param;
            if (async_evt->result == 0)
            {
                if (mmi_email_app_core_cntx_p->callback != NULL)
                {
                    (*mmi_email_app_core_cntx_p->callback)(MMI_EMAIL_SUCCESS, mmi_email_app_core_cntx_p->user_data);
                }
            }
            else
            {
                g_fs_error_detail = async_evt->result;
                if (mmi_email_app_core_cntx_p->callback != NULL)
                {
                    (*mmi_email_app_core_cntx_p->callback)(async_evt->result, mmi_email_app_core_cntx_p->user_data);
                }
            }
            mmi_email_app_core_cntx_p->user_data = NULL;
            mmi_email_app_core_cntx_p->callback = NULL;
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_delete_image
 * DESCRIPTION
 *  This function is used to delete the image of one account's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 *  index              : [IN]  Index of iamge to be deleted of a signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_delete_image(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR image_path[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_email_sig_struct signature;
    FS_HANDLE file_handle;
    S32 attr = 0;
    mmi_email_app_core_result_enum result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_DELETE_IMAGE, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_SIG_MAX_NUMBER ||
        index >= MMI_EMAIL_SIG_MAX_IMAGE_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memset(
        signature.image_name[index],
        0,
        (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
    for (i = index; i < signature.image_num - 1; i++)
    {
        memcpy(
            signature.image_name[i],
            signature.image_name[i + 1],
            (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
    }
    memset(
        signature.image_name[signature.image_num - 1],
        0,
        (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
    signature.image_num--;
    mmi_email_sig_get_image_path(acct_id, index, image_path, SRV_FMGR_PATH_MAX_LEN + 1);    
    file_handle = FS_Open((U16*)image_path, FS_READ_WRITE);
    if (file_handle > 0)
    {
        /* if read-only, reset it */
        attr = FS_GetAttributes((const WCHAR*)image_path);
        if (attr & FS_ATTR_READ_ONLY)
        {
            FS_SetAttributes((const WCHAR*)image_path, (U8)(attr & ~(FS_ATTR_READ_ONLY)));
        }
        FS_Close(file_handle);
    }
    FS_Delete(image_path);
    return mmi_email_sig_write_info(acct_id, &signature);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_delete_all_image
 * DESCRIPTION
 *  This function is used to delete all images of one account's signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id used to set the right signature
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_delete_all_image(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR image_path[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_email_sig_struct signature;
    FS_HANDLE file_handle;
    S32 attr = 0;
    mmi_email_app_core_result_enum result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_DELETE_ALL_IMAGE, __LINE__);

    result = mmi_email_sig_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    result = mmi_email_sig_read_info(acct_id, &signature);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memset(
        signature.image_name,
        0,
        MMI_EMAIL_SIG_MAX_IMAGE_NUMBER * (EMAIL_ATTCH_FILE_NAME_LEN + 1) * 2);
    for (i = 0; i < signature.image_num; i++)
    {
        mmi_email_sig_get_image_path(acct_id, i, image_path, SRV_FMGR_PATH_MAX_LEN + 1);
        file_handle = FS_Open((U16*)image_path, FS_READ_WRITE);
        if (file_handle > 0)
        {
            /* if read-only, reset it */
            attr = FS_GetAttributes((const WCHAR*)image_path);
            if (attr & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes((const WCHAR*)image_path, (U8)(attr & ~(FS_ATTR_READ_ONLY)));
            }
            FS_Close(file_handle);
        }
        FS_Delete(image_path);
    }
    signature.image_num = 0;
    return mmi_email_sig_write_info(acct_id, &signature);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_init
 * DESCRIPTION
 *  This function is used to init account to signature map
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_sig_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path;
    FS_HANDLE file_handle;
    U16 i;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_INIT, __LINE__);

    file_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        free_ctrl_buffer(file_path);
        mmi_email_sig_reset();
        return;
    }
    FS_GetFileSize(file_handle, &size);
    FS_Close(file_handle);
    if (size != sizeof(mmi_email_acct_sig_map) * MMI_EMAIL_SIG_MAX_NUMBER)
    {
        /* Force to re-create */
        free_ctrl_buffer(file_path);
        mmi_email_sig_reset();
        return;
    }

    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        mmi_email_sig_reset();
        return;
    }
    FS_GetFileSize(file_handle, &size);
    FS_Close(file_handle);
    if (size != sizeof(mmi_email_sig_struct) * MMI_EMAIL_SIG_MAX_NUMBER)
    {
        /* Force to re-create */
        mmi_email_sig_reset();
        return;
    }

    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        mmi_email_sig_read_map(
            (EMAIL_ACCT_ID)(i + 1),
            &mmi_email_app_core_cntx_p->acct_sig_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_sig_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path;
    mmi_email_acct_sig_map sig_map;
    mmi_email_sig_struct signature;
    FS_HANDLE file_handle_map;
    FS_HANDLE file_handle_info;
    U32 written = 0;
    U16 i = 0;
    EMAIL_ACCT_ID acct_id_list[MMI_EMAIL_SIG_MAX_NUMBER];
    //srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    S32 acct_cnt = MMI_EMAIL_SIG_MAX_NUMBER;
    S32 fs_result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    FS_Delete(file_path);
    file_handle_map = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (file_handle_map < 0)
    {
        free_ctrl_buffer(file_path);
        return;
    }
    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    FS_Delete(file_path);
    file_handle_info = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (file_handle_info < 0)
    {
        FS_Close(file_handle_map);
        free_ctrl_buffer(file_path);
        return;
    }
    free_ctrl_buffer(file_path);

    memset(acct_id_list, 0, MMI_EMAIL_SIG_MAX_NUMBER * sizeof(EMAIL_ACCT_ID));
    /*result =*/ srv_email_acct_get_acct_id(0, &acct_cnt, acct_id_list);
    memset(&sig_map, 0, sizeof(mmi_email_acct_sig_map));
    memset(&signature, 0, sizeof(mmi_email_sig_struct));
    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        sig_map.acct_id = acct_id_list[i];
        if (acct_id_list[i] != EMAIL_ACCT_INVALID_ID)
        {
            signature.validity = MMI_TRUE;
            signature.user_num = 1;
            sig_map.sig_id = i;
        }
        else
        {
            signature.validity = MMI_FALSE;
            signature.user_num = 0;
            sig_map.sig_id = 0;
        }
        fs_result = FS_Write(file_handle_info, &signature, sizeof(mmi_email_sig_struct), &written);
        if (fs_result != FS_NO_ERROR || written != sizeof(mmi_email_sig_struct))
        {
            FS_Close(file_handle_map);
            FS_Close(file_handle_info);
            return;
        }
        fs_result = FS_Write(file_handle_map, &sig_map, sizeof(mmi_email_acct_sig_map),  &written);
        if (fs_result != FS_NO_ERROR || written != sizeof(mmi_email_acct_sig_map))
        {
            FS_Close(file_handle_map);
            FS_Close(file_handle_info);
            return;
        }
    }
    FS_Close(file_handle_map);
    FS_Close(file_handle_info);
    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        mmi_email_sig_read_map(
            (EMAIL_ACCT_ID)(i + 1),
            &mmi_email_app_core_cntx_p->acct_sig_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_get_image_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_sig_get_image_path(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 index,
                                        WCHAR *image_path,
                                        U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *temp_path;
    S32 sig_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_GET_IMAGE_PATH, __LINE__);

    temp_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    if (image_path == NULL)
    {
        free_ctrl_buffer(temp_path);
        return MMI_EMAIL_FAIL;
    }
    sig_id = mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].sig_id;
    kal_wsprintf(
        temp_path,
        "%s%s%s%s%d%d",
        srv_email_get_root_path(),
        app_core_path,
        sig_image_path,
        sig_image_name,
        sig_id,
        index);
    if (mmi_wcslen(temp_path) >= len)
    {
        free_ctrl_buffer(temp_path);
        return MMI_EMAIL_FAIL;
    }
    memcpy(image_path, temp_path, mmi_wcslen(temp_path) * 2);
    image_path[mmi_wcslen(temp_path)] = 0;
    free_ctrl_buffer(temp_path);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_read_info
 * DESCRIPTION
 *  This function is used to get information of a signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 *  signature          : [IN]  Buffer to store signature
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_sig_read_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_sig_struct *signature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    U32 index;
    S32 result;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_READ_INFO, __LINE__);

    if (acct_id <= 0 || acct_id > MMI_EMAIL_SIG_MAX_NUMBER || signature == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    /* to avoid read file fail and write random content to file */
    memset(signature, 0, sizeof(mmi_email_sig_struct));

    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    index = mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].sig_id;
    if (index != 0)
    {
        result = FS_Seek(file_handle, (index - 1) * sizeof(mmi_email_sig_struct), FS_FILE_BEGIN);
        if (result < FS_NO_ERROR)
        {
            FS_Close(file_handle);
            g_fs_error_detail = result;
            return MMI_EMAIL_FAIL;
        }
    }
    result = FS_Read(file_handle, signature, sizeof(mmi_email_sig_struct), &read);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR || read != sizeof(mmi_email_sig_struct))
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_get_info
 * DESCRIPTION
 *  This function is used to get information of a signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 *  signature          : [IN]  Buffer to store signature
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_sig_write_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_sig_struct *signature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    U32 index;
    S32 result;
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_WRITE_INFO, __LINE__);

    if (acct_id <= 0 || acct_id > MMI_EMAIL_SIG_MAX_NUMBER || signature == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    index = mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)].sig_id;
    if (index != 0)
    {
        result = FS_Seek(file_handle, (index - 1) * sizeof(mmi_email_sig_struct), FS_FILE_BEGIN);
        if (result < FS_NO_ERROR)
        {
            FS_Close(file_handle);
            g_fs_error_detail = result;
            return MMI_EMAIL_FAIL;
        }
    }
    result = FS_Write(file_handle, signature, sizeof(mmi_email_sig_struct), &written);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR || written != sizeof(mmi_email_sig_struct))
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_read_map
 * DESCRIPTION
 *  This function is used to get information of map with account and signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 *  sig_map            : [IN]  Buffer to store map
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_sig_read_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_sig_map *sig_map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_READ_MAP, __LINE__);

    if (acct_id <= 0 || acct_id > MMI_EMAIL_SIG_MAX_NUMBER || sig_map == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    /* to avoid read file fail and write random content to file */
    memset(sig_map, 0, sizeof(mmi_email_acct_sig_map));

    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(file_handle, (acct_id - 1) * sizeof(mmi_email_acct_sig_map), FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Read(file_handle, sig_map, sizeof(mmi_email_acct_sig_map), &read);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR || read != sizeof(mmi_email_acct_sig_map))
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_write_map
 * DESCRIPTION
 *  This function is used to set information of map with account and signature
 * PARAMETERS
 *  acct_id            : [IN]  The account id
 *  sig_map            : [IN]  Buffer to store map
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_sig_write_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_sig_map *sig_map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_WRITE_MAP, __LINE__);

    if (acct_id <= 0 || acct_id > MMI_EMAIL_SIG_MAX_NUMBER || sig_map == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_sig_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(file_handle, (acct_id - 1) * sizeof(mmi_email_acct_sig_map), FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Write(file_handle, sig_map, sizeof(mmi_email_acct_sig_map), &written);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR || written != sizeof(mmi_email_acct_sig_map))
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_sig_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_sig_get_file_path(WCHAR *file_path, U16 len, MMI_BOOL map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_GET_FILE_PATH, __LINE__);

    if (map)
    {
        if (len < mmi_ucs2strlen(srv_email_get_root_path()) + strlen(app_core_path) + strlen(sig_map_file) + 1)
        {
            return;
        }
        kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, sig_map_file);
    }
    else
    {
        if (len < mmi_ucs2strlen(srv_email_get_root_path()) + strlen(app_core_path) + strlen(sig_data_file) + 1)
        {
            return;
        }
        kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, sig_data_file);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_create
 * DESCRIPTION
 *  This function is used to create a new auto check for a account
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_sig_acct_check(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_SIG_ACCT_CHECK, __LINE__);

    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        if (mmi_email_app_core_cntx_p->acct_sig_list[i].acct_id == acct_id)
        {
            return MMI_EMAIL_SUCCESS;
        }
    }
    return MMI_EMAIL_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_create
 * DESCRIPTION
 *  This function is used to create a new auto check for a account
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_create(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_acct_auto_check_map auto_check_map;
    mmi_email_app_core_result_enum result;
    S32 fs_result;
    U32 read;
    FS_HANDLE file_handle;
    WCHAR *file_path;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_CREATE, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result == MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_ALREADY_EXIST;
    }
    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
    {
        fs_result = FS_Read(file_handle, &auto_check_data, sizeof(mmi_email_auto_check_struct), &read);
        if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_auto_check_struct))
        {
            FS_Close(file_handle);
            g_fs_error_detail = fs_result;
            return MMI_EMAIL_FAIL;
        }
        if (auto_check_data.validity == MMI_FALSE)
        {
            break;
        }
    }
	FS_Close(file_handle);
    if (i == MMI_EMAIL_SIG_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    auto_check_map.status = MMI_TRUE;
    auto_check_map.acct_id = acct_id;
    auto_check_map.auto_check_id = i + 1;
    result = mmi_email_auto_check_write_map(acct_id, &auto_check_map);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memcpy(
        &mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)],
        &auto_check_map,
        sizeof(mmi_email_acct_auto_check_map));
    memset(&auto_check_data, 0, sizeof(mmi_email_auto_check_struct));
    auto_check_data.user_num = 1;
    auto_check_data.validity = MMI_TRUE;
    result = mmi_email_auto_check_write_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        auto_check_map.acct_id = 0;
        auto_check_map.auto_check_id = 0;
        auto_check_map.status = MMI_FALSE;
        mmi_email_auto_check_write_map(acct_id, &auto_check_map);
        memset(
            &mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)],
            0,
            sizeof(mmi_email_acct_auto_check_map));
        return result;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_list_acct_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_list_acct_id(
                                        EMAIL_ACCT_ID *acct_id_list,
                                        U16 *array_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_acct_auto_check_map auto_check_map;
    mmi_email_app_core_result_enum result;
    U16 index = 0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_LIST_ACCT_ID, __LINE__);

    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        result = mmi_email_auto_check_read_map((EMAIL_ACCT_ID)(i + 1), &auto_check_map);
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        if (auto_check_map.acct_id != EMAIL_ACCT_INVALID_ID)
        {
            acct_id_list[index] = auto_check_map.acct_id;
            index++;
            if (index >= *array_len)
            {
                break;
            }
        }
    }
    *array_len = index;
    for (i = index; i < *array_len; i++)
    {
        acct_id_list[i] = EMAIL_ACCT_INVALID_ID;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_list_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_list_id(
                                        MMI_EMAIL_SIG_ID *auto_check_id_list,
                                        U16 *array_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;
    U16 index;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_LIST_ID, __LINE__);

    index = 0;
    for (i = 0; i < MMI_EMAIL_SIG_MAX_NUMBER; i++)
    {
        result = mmi_email_auto_check_read_info(i + 1, &auto_check_data);
        if (result != MMI_EMAIL_SUCCESS)
        {
            return result;
        }
        if (auto_check_data.validity == MMI_TRUE)
        {
            auto_check_id_list[index] = (MMI_EMAIL_SIG_ID)i;
            index++;
            if (index >= *array_len)
            {
                break;
            }
        }
    }
    *array_len = index;
    for (i = index; i < *array_len; i++)
    {
        auto_check_id_list[i] = 0;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_use_exist
 * DESCRIPTION
 *  This function is used to map account to an exist auto check
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 *  index              : [IN]  Which auto check to use
 *  callback           : [IN]  Callback to notify app
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_use_exist(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_EMAIL_AUTO_CHECK_ID auto_check_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_acct_auto_check_map auto_check_map;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_USE_EXIST, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result == MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_ALREADY_EXIST;
    }

    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_SIG_MAX_NUMBER ||
        auto_check_id <= 0 ||
        auto_check_id > MMI_EMAIL_SIG_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }

    auto_check_map.auto_check_id = auto_check_id;
    auto_check_map.acct_id = acct_id;
    auto_check_map.status = MMI_TRUE;
    result = mmi_email_auto_check_write_map(acct_id, &auto_check_map);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memcpy(
        &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
        &auto_check_data,
        sizeof(mmi_email_acct_auto_check_map));
    auto_check_data.user_num++;
    result = mmi_email_auto_check_write_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        auto_check_map.acct_id = 0;
        auto_check_map.auto_check_id = 0;
        auto_check_map.status = MMI_FALSE;
        mmi_email_auto_check_write_map(acct_id, &auto_check_map);
        memset(
            &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)],
            0,
            sizeof(mmi_email_acct_auto_check_map));
        return result;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_set_roaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern void mmi_email_auto_check_set_roaming(MMI_BOOL roaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_SET_ROAMING, __LINE__);

    mmi_email_app_core_cntx_p->roaming = roaming;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_set_roaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern void mmi_email_auto_check_get_roaming(MMI_BOOL *roaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_ROAMING, __LINE__);

    *roaming = mmi_email_app_core_cntx_p->roaming;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_delete_acct
 * DESCRIPTION
 *  This function is used to remove this account from mapping to one auto check
 *  If this auto check is only for this account, it will be reset.
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_delete_acct(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL destroy_auto_check)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_DELETE_ACCT, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    auto_check_data.user_num--;
    if (destroy_auto_check == MMI_TRUE || auto_check_data.user_num == 0)
    {
        memset(&auto_check_data, 0, sizeof(mmi_email_auto_check_struct));
    }
    result = mmi_email_auto_check_write_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)].auto_check_id = 0;
    mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)].acct_id = 0;
    mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)].status = MMI_FALSE;
    mmi_email_sig_write_map(acct_id, &mmi_email_app_core_cntx_p->acct_sig_list[(U16)(acct_id - 1)]);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_start_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_start_service(auto_check_nofity_fn nofity_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL status;
    U32 time_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_START_SERVICE, __LINE__);

    /*if (nofity_fn == NULL)
    {
        return MMI_EMAIL_FAIL;
    }*/
    mmi_email_app_core_cntx_p->nofity_fn = nofity_fn;
    for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
    {
        mmi_email_app_core_cntx_p->auto_check_acct_id_array[i] = (EMAIL_ACCT_ID)(i + 1);
        status = MMI_FALSE;
        mmi_email_auto_check_get_status((EMAIL_ACCT_ID)(i + 1), &status);
        if (status == MMI_FALSE)
        {
            continue;
        }
        time_out = 0;
        time_out = mmi_email_auto_check_get_time_out((EMAIL_ACCT_ID)(i + 1));
        if (time_out == 0)
        {
            continue;
        }
        StartTimerEx(
            (U16)mmi_email_app_core_cntx_p->auto_check_timers[i],
            time_out * 1000,//time in ms
            mmi_email_auto_check_time_out_handle,
            &mmi_email_app_core_cntx_p->auto_check_acct_id_array[i]);
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_stop_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern void mmi_email_auto_check_stop_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_STOP_SERVICE, __LINE__);

    for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
    {
        StopTimer((U16)mmi_email_app_core_cntx_p->auto_check_timers[i]);
    }
    mmi_email_app_core_cntx_p->nofity_fn = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_start(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time_out;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_START, __LINE__);

    /*if (mmi_email_app_core_cntx_p->nofity_fn == NULL)
    {
        return MMI_EMAIL_FAIL;
    }*/
    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    time_out = mmi_email_auto_check_get_time_out(acct_id);
    if (time_out == 0)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_app_core_cntx_p->acct_auto_check_list[acct_id - 1].status = MMI_TRUE;
    result = mmi_email_auto_check_write_map(
                acct_id,
                &mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)]);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }

    StartTimerEx(
        (U16)mmi_email_app_core_cntx_p->auto_check_timers[acct_id - 1],
        time_out * 1000,
        mmi_email_auto_check_time_out_handle,
        &mmi_email_app_core_cntx_p->auto_check_acct_id_array[acct_id - 1]);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_stop(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL status;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_STOP, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    mmi_email_auto_check_get_status(acct_id, &status);
    if (status == MMI_FALSE)
    {
        return MMI_EMAIL_SUCCESS;
    }
    result = mmi_email_auto_check_write_map(
                acct_id,
                &mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)]);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    StopTimer((U16)mmi_email_app_core_cntx_p->auto_check_timers[acct_id - 1]);
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_get_status
 * DESCRIPTION
 *  This function is used to get status of certain account's auto check
 * PARAMETERS
 *  acct_id            : [IN]  Which account to get
 *  status             : [OUT] Status of this auto check
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_get_status(
                                        EMAIL_ACCT_ID acct_id,
                                        MMI_BOOL *status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_STATUS, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (status == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    *status = mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)].status;
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_set_status
 * DESCRIPTION
 *  This function is used to set status of certain account's auto check
 * PARAMETERS
 *  acct_id            : [IN]  Which account to get
 *  status             : [IN]  Status of this auto check
 * RETURNS
 *  
 ****************************************************************************/
//extern void mmi_email_auto_check_set_status(
//                EMAIL_ACCT_ID acct_id,
//                MMI_BOOL status)
//{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)acct_id].status = status;
//}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_get_day_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_get_day_enable(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        MMI_BOOL *enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_DAY_ENABLE, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY || enable == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    *enable = auto_check_data.days[day].enable;
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_set_day_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_set_day_enable(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_SET_DAY_ENABLE, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    auto_check_data.days[day].enable = enable;
    return mmi_email_auto_check_write_info(acct_id, &auto_check_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_reset_day
 * DESCRIPTION
 *  This function is used to clear one day's auto check of certain account
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 *  day                : [IN]  Which day to set
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_reset_day(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_RESET_DAY, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    result =  mmi_email_auto_check_write_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memset(&auto_check_data.days[day], 0, sizeof(mmi_email_auto_check_day_struct));
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_reset_all_day
 * DESCRIPTION
 *  This function is used to clear all days' auto check of certain account
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_reset_all_day(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_RESET_ALL_DAY, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    memset(
        auto_check_data.days,
        0,
        sizeof(mmi_email_auto_check_day_struct) * MMI_EMAIL_AUTO_CHECK_DAYS_OF_WEEK);
    return mmi_email_auto_check_write_info(acct_id, &auto_check_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_get_segment_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_get_segment_num(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_SEGMENT_NUM, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY || num == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (mmi_email_app_core_cntx_p->roaming == MMI_TRUE)
    {
        *num = auto_check_data.days[day].roaming_num;
    }
    else
    {
        *num = auto_check_data.days[day].normal_num;
    }
    return MMI_EMAIL_SUCCESS;
}


/************************ segment list operation ****************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_get_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_get_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 index,
                                        mmi_email_auto_check_time_segment *segment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_SEGMENT, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (mmi_email_app_core_cntx_p->roaming == MMI_TRUE)
    {
        if (index >= auto_check_data.days[day].roaming_num)
        {
            return MMI_EMAIL_FAIL;
        }
        memcpy(
            segment,
            &auto_check_data.days[day].roaming[index],
            sizeof(mmi_email_auto_check_time_segment));
        return MMI_EMAIL_SUCCESS;
    }
    else
    {
        if (index >= auto_check_data.days[day].normal_num)
        {
            return MMI_EMAIL_FAIL;
        }
        else
        {
            memcpy(
                segment,
                &auto_check_data.days[day].normal[index],
                sizeof(mmi_email_auto_check_time_segment));
            return MMI_EMAIL_SUCCESS;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_add_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_add_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        mmi_email_auto_check_time_segment *segment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_ADD_SEGMENT, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (mmi_email_app_core_cntx_p->roaming == MMI_TRUE)
    {
        if (auto_check_data.days[day].roaming_num >= MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT)
        {
            return MMI_EMAIL_FAIL;
        }
        else
        {
            memcpy(
                &auto_check_data.days[day].roaming[auto_check_data.days[day].roaming_num],
                segment,
                sizeof(mmi_email_auto_check_time_segment));
            auto_check_data.days[day].roaming_num++;
        }
    }
    else
    {
        if (auto_check_data.days[day].normal_num >= MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT)
        {
            return MMI_EMAIL_FAIL;
        }
        else
        {
            memcpy(
                &auto_check_data.days[day].normal[auto_check_data.days[day].normal_num],
                segment,
                sizeof(mmi_email_auto_check_time_segment));
            auto_check_data.days[day].normal_num++;
        }
    }
    return mmi_email_auto_check_write_info(acct_id, &auto_check_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_edit_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_edit_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 index,
                                        mmi_email_auto_check_time_segment *segment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_EDIT_SEGMENT, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (mmi_email_app_core_cntx_p->roaming == MMI_TRUE)
    {
        if (index >= auto_check_data.days[day].roaming_num)
        {
            return MMI_EMAIL_FAIL;
        }
        memcpy(
            &auto_check_data.days[day].roaming[index],
            segment,
            sizeof(mmi_email_auto_check_time_segment));
    }
    else
    {
        if (index >= auto_check_data.days[day].normal_num)
        {
            return MMI_EMAIL_FAIL;
        }
        else
        {
            memcpy(
                &auto_check_data.days[day].normal[index],
                segment,
                sizeof(mmi_email_auto_check_time_segment));
        }
    }
    return mmi_email_auto_check_write_info(acct_id, &auto_check_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_delete_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_delete_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day,
                                        U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_DELETE_SEGMENT, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (mmi_email_app_core_cntx_p->roaming == MMI_TRUE)
    {
        if (index >= auto_check_data.days[day].roaming_num)
        {
            return MMI_EMAIL_FAIL;
        }
        if (index == MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT)
        {
            memset(
                &auto_check_data.days[day].roaming[index],
                0,
                sizeof(mmi_email_auto_check_time_segment));
        }
        else
        {
            for (i = index; i < auto_check_data.days[day].roaming_num - 1; i++)
            {
                memcpy(
                    &auto_check_data.days[day].roaming[i],
                    &auto_check_data.days[day].roaming[i + 1],
                    sizeof(mmi_email_auto_check_time_segment));
            }
            memset(
                &auto_check_data.days[day].roaming[auto_check_data.days[day].roaming_num - 1],
                0,
                sizeof(mmi_email_auto_check_time_segment));
        }
        auto_check_data.days[day].roaming_num--;
    }
    else
    {
        if (index == MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT)
        {
            memset(
                &auto_check_data.days[day].normal[index],
                0,
                sizeof(mmi_email_auto_check_time_segment));
        }
        else
        {
            for (i = index; i < auto_check_data.days[day].normal_num; i++)
            {
                memcpy(
                    &auto_check_data.days[day].normal[i],
                    &auto_check_data.days[day].normal[i + 1],
                    sizeof(mmi_email_auto_check_time_segment));
            }
            memset(
                &auto_check_data.days[day].normal[auto_check_data.days[day].normal_num - 1],
                0,
                sizeof(mmi_email_auto_check_time_segment));
        }
        auto_check_data.days[day].normal_num--;
    }
    return mmi_email_auto_check_write_info(acct_id, &auto_check_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_delete_all_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id            : [IN]
 * RETURNS
 *  
 ****************************************************************************/
extern mmi_email_app_core_result_enum mmi_email_auto_check_delete_all_segment(
                                        EMAIL_ACCT_ID acct_id,
                                        U16 day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_auto_check_struct auto_check_data;
    mmi_email_app_core_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_DELETE_ALL_SEGMENT, __LINE__);

    result = mmi_email_auto_check_acct_check(acct_id);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return MMI_EMAIL_ACCOUNT_NOT_EXIST;
    }
    if (day > MMI_EMAIL_AUTO_CHECK_SATURDAY)
    {
        return MMI_EMAIL_FAIL;
    }
    result = mmi_email_auto_check_read_info(acct_id, &auto_check_data);
    if (result != MMI_EMAIL_SUCCESS)
    {
        return result;
    }
    if (mmi_email_app_core_cntx_p->roaming == MMI_TRUE)
    {
        memset(
            auto_check_data.days[day].roaming,
            0,
            sizeof(mmi_email_auto_check_time_segment) * MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT);
        auto_check_data.days[day].roaming_num = 0;
    }
    else
    {
        memset(
            auto_check_data.days[day].normal,
            0,
            sizeof(mmi_email_auto_check_time_segment) * MMI_EMAIL_AUTO_CHECK_MAX_TIME_SEGMENT);
        auto_check_data.days[day].normal_num = 0;
    }
    return mmi_email_auto_check_write_info(acct_id, &auto_check_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_auto_check_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path;
    FS_HANDLE file_handle;
    mmi_email_acct_auto_check_map auto_check_map;
    mmi_email_auto_check_struct auto_check;
    U32 write;
    U16 i;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_INIT, __LINE__);

    file_path = (WCHAR*)get_ctrl_buffer((SRV_FMGR_PATH_MAX_LEN + 1) * 2);
    mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);

    if (file_handle >= 0)
    {
        FS_GetFileSize(file_handle, &size);
        if (size != sizeof(mmi_email_acct_auto_check_map) * MMI_EMAIL_AUTO_CHECK_MAX_NUMBER)
        {
            /* Force to re-create */
            FS_Close(file_handle);
            file_handle = -1;
        }
    }

    if (file_handle < 0)
    {
        file_handle = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (file_handle < 0)
        {
             free_ctrl_buffer(file_path);
            return;
        }
        memset(&auto_check_map, 0, sizeof(mmi_email_acct_auto_check_map));
        for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
        {
            FS_Write(file_handle, &auto_check_map, sizeof(mmi_email_acct_auto_check_map), &write);
        }
        FS_Close(file_handle);
        mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
        file_handle = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (file_handle < 0)
        {
            free_ctrl_buffer(file_path);
            return;
        }
        memset(&auto_check, 0, sizeof(mmi_email_auto_check_struct));
        for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
        {
            FS_Write(file_handle, &auto_check, sizeof(mmi_email_auto_check_struct), &write);
        }
    }
    free_ctrl_buffer(file_path);
    FS_Close(file_handle);
    for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
    {
        mmi_email_auto_check_read_map(
            (EMAIL_ACCT_ID)i + 1,
            &mmi_email_app_core_cntx_p->acct_auto_check_list[i]);
    }
    memset(
        mmi_email_app_core_cntx_p->auto_check_eventid_list,
        0,
        sizeof(eventid) * MMI_EMAIL_AUTO_CHECK_MAX_NUMBER);
    mmi_email_app_core_cntx_p->nofity_fn = NULL;
    for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
    {
        mmi_email_app_core_cntx_p->auto_check_timers[i] = (MMI_TIMER_IDS)(EMAIL_MMI_AUTO_CHECK_TIMER_0 + i);
    }
    /* init event scheduler */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_read_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_auto_check_read_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_auto_check_struct *auto_check_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_EMAIL_AUTO_CHECK_ID auto_check_id;
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_READ_INFO, __LINE__);

    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_AUTO_CHECK_MAX_NUMBER ||
        auto_check_data == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    auto_check_id = mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)].auto_check_id;
    if (auto_check_id == 0)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(file_handle, (auto_check_id - 1) * sizeof(mmi_email_auto_check_struct), FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Read(file_handle, auto_check_data, sizeof(mmi_email_auto_check_struct), &read);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_write_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_auto_check_write_info(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_auto_check_struct *auto_check_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_EMAIL_AUTO_CHECK_ID auto_check_id;
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_WRITE_INFO, __LINE__);

    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_AUTO_CHECK_MAX_NUMBER ||
        auto_check_data == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    auto_check_id = mmi_email_app_core_cntx_p->acct_auto_check_list[(U16)(acct_id - 1)].auto_check_id;
    if (auto_check_id == 0)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_FALSE);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(file_handle, (auto_check_id - 1) * sizeof(mmi_email_auto_check_struct), FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Write(file_handle, auto_check_data, sizeof(mmi_email_auto_check_struct), &write);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_read_map
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_auto_check_read_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_auto_check_map *auto_check_map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_READ_MAP, __LINE__);

    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_AUTO_CHECK_MAX_NUMBER ||
        auto_check_map == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(file_handle, (acct_id - 1) * sizeof(mmi_email_acct_auto_check_map), FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Read(file_handle, auto_check_map, sizeof(mmi_email_acct_auto_check_map), &read);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_write_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_auto_check_write_map(
                                        EMAIL_ACCT_ID acct_id,
                                        mmi_email_acct_auto_check_map *auto_check_map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN + 1];
    FS_HANDLE file_handle;
    S32 result;
    U32 write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_WRITE_MAP, __LINE__);

    if (acct_id <= 0 ||
        acct_id > MMI_EMAIL_AUTO_CHECK_MAX_NUMBER ||
        auto_check_map == NULL)
    {
        return MMI_EMAIL_FAIL;
    }
    mmi_email_auto_check_get_file_path(file_path, SRV_FMGR_PATH_MAX_LEN + 1, MMI_TRUE);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Seek(file_handle, (acct_id - 1) * sizeof(mmi_email_acct_auto_check_map), FS_FILE_BEGIN);
    if (result < FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    result = FS_Write(file_handle, auto_check_map, sizeof(mmi_email_acct_auto_check_map), &write);
    FS_Close(file_handle);
    if (result != FS_NO_ERROR)
    {
        g_fs_error_detail = result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_get_time_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static U32 mmi_email_auto_check_get_time_out(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct curr_time;
    mmi_email_auto_check_time_segment segment;
    MMI_BOOL enable;
    U16 num;
    U16 count = 0;
    U16 i;
    U16 day = 0;
    U32 time_point;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_TIME_OUT, __LINE__);

    applib_dt_get_date_time(&curr_time);
    day = curr_time.DayIndex;
    time_point = curr_time.nHour * 60 * 60 + curr_time.nMin * 60 + curr_time.nSec;
    mmi_email_auto_check_get_day_enable(acct_id, day, &enable);
    if (enable == MMI_TRUE)
    {
        mmi_email_auto_check_get_segment_num(acct_id, day, &num);
        if (num > 0)
        {
            for (i = 0; i < num; i++)
            {
                mmi_email_auto_check_get_segment(acct_id, day, i, &segment);
                if (time_point <= segment.start_time)
                {
                    return segment.start_time - time_point;
                }
                else
                {
                    if (time_point <= segment.stop_time)
                    {
                        return segment.interval;
                    }
                }
            }
        }
    }
    else
    {
        while (count != MMI_EMAIL_AUTO_CHECK_DAYS_OF_WEEK)
        {
            count++;
            day = (day + 1) % MMI_EMAIL_AUTO_CHECK_DAYS_OF_WEEK;
            mmi_email_auto_check_get_day_enable(acct_id, day, &enable);
            if (enable == MMI_TRUE)
            {
                mmi_email_auto_check_get_segment_num(acct_id, day, &num);
                if (num != 0)
                {
                    mmi_email_auto_check_get_segment(acct_id, day, 0, &segment);
                    return count * 24 * 60 * 60 + (time_point - segment.start_time);
                }
            }
        }
        return 0;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_time_out_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_auto_check_time_out_handle(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID *acct_id = (EMAIL_ACCT_ID*)data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_TIME_OUT_HANDLE, __LINE__);

    if (mmi_email_app_core_cntx_p->nofity_fn == NULL)
    {
        return;
    }
    (*mmi_email_app_core_cntx_p->nofity_fn)(*acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
static void mmi_email_auto_check_get_file_path(WCHAR* file_path, U16 len, MMI_BOOL map)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_GET_FILE_PATH, __LINE__);

    if (map)
    {
        if (len < mmi_ucs2strlen(srv_email_get_root_path()) + strlen(app_core_path) + strlen(auto_check_map_file) + 1)
        {
            return;
        }
        kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, auto_check_map_file);
    }
    else
    {
        if (len < mmi_ucs2strlen(srv_email_get_root_path()) + strlen(app_core_path) + strlen(auto_check_data_file) + 1)
        {
            return;
        }
        kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, auto_check_data_file);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_auto_check_create
 * DESCRIPTION
 *  This function is used to create a new auto check for a account
 * PARAMETERS
 *  acct_id            : [IN]  Which account to set
 * RETURNS
 *  
 ****************************************************************************/
static mmi_email_app_core_result_enum mmi_email_auto_check_acct_check(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_AUTO_CHECK_ACCT_CHECK, __LINE__);

    for (i = 0; i < MMI_EMAIL_AUTO_CHECK_MAX_NUMBER; i++)
    {
        if (mmi_email_app_core_cntx_p->acct_auto_check_list[i].acct_id == acct_id)
        {
            return MMI_EMAIL_SUCCESS;
        }
    }
    return MMI_EMAIL_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_core_get_fs_error_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ****************************************************************************/
extern S32 mmi_email_app_core_get_fs_error_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_APP_CORE_GET_FS_ERROR_DETAIL, __LINE__);

    return g_fs_error_detail;
}


#ifdef __MMI_EMAIL_IMAP_PUSH__
static void mmi_email_imap_push_init(void)
{
    WCHAR *file_path = NULL;
    FS_HANDLE file_handle;
    S32 fs_result = FS_NO_ERROR;
    mmi_email_imap_push_cntx_struct imap_push_cntx;
    U32 written = 0;
    U32 size;

    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, imap_push_file);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    if (file_handle >= 0)
    {
        fs_result = FS_GetFileSize(file_handle, &size);
        FS_Close(file_handle);
        if (fs_result == FS_NO_ERROR && size == sizeof(mmi_email_imap_push_cntx_struct))
        {
            free_ctrl_buffer(file_path);
            return;
        }
        FS_Delete(file_path);
    }
    file_handle = FS_Open(file_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    free_ctrl_buffer(file_path);
    memset(&imap_push_cntx, 0, sizeof(mmi_email_imap_push_cntx_struct));
    FS_Write(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct) ,&written);
    FS_Close(file_handle);
}


extern mmi_email_app_core_result_enum mmi_email_imap_push_acct_add(EMAIL_ACCT_ID acct_id)
{
    mmi_email_imap_push_cntx_struct imap_push_cntx;
    U32 read = 0;
    U32 written = 0;
    FS_HANDLE file_handle;
    WCHAR *file_path = NULL;
    S32 fs_result = 0;

    if (acct_id <= EMAIL_ACCT_INVALID_ID || acct_id > MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }

    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, imap_push_file);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    fs_result = FS_Read(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &read);
    if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_imap_push_cntx_struct))
    {
        FS_Close(file_handle);
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    if (imap_push_cntx.acct_on[acct_id - 1] == MMI_TRUE)
    {
        FS_Close(file_handle);
        return MMI_EMAIL_SUCCESS;
    }
    imap_push_cntx.acct_on[acct_id - 1] = MMI_TRUE;
    fs_result = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_result != FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    fs_result = FS_Write(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &written);
    FS_Close(file_handle);
    if (fs_result != FS_NO_ERROR || written != sizeof(mmi_email_imap_push_cntx_struct))
    {
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


extern mmi_email_app_core_result_enum mmi_email_imap_push_acct_remove(EMAIL_ACCT_ID acct_id)
{
    mmi_email_imap_push_cntx_struct imap_push_cntx;
    U32 read = 0;
    U32 written = 0;
    FS_HANDLE file_handle;
    WCHAR *file_path = NULL;
    S32 fs_result = 0;

    if (acct_id <= EMAIL_ACCT_INVALID_ID || acct_id > MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER)
    {
        return MMI_EMAIL_FAIL;
    }

    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, imap_push_file);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    fs_result = FS_Read(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &read);
    if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_imap_push_cntx_struct))
    {
        FS_Close(file_handle);
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    if (imap_push_cntx.acct_on[acct_id - 1] == MMI_FALSE)
    {
        FS_Close(file_handle);
        return MMI_EMAIL_SUCCESS;
    }
    fs_result = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_result != FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    imap_push_cntx.acct_on[acct_id - 1] = MMI_FALSE;
    fs_result = FS_Write(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &written);
    FS_Close(file_handle);
    if (fs_result != FS_NO_ERROR || written != sizeof(mmi_email_imap_push_cntx_struct))
    {
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


extern mmi_email_app_core_result_enum mmi_email_imap_push_acct_get(EMAIL_ACCT_ID *acct_array, U32 *count)
{
    mmi_email_imap_push_cntx_struct imap_push_cntx;
    U32 read = 0;
    FS_HANDLE file_handle;
    WCHAR *file_path = NULL;
    S32 fs_result = 0;
    U16 index = 0;
    U16 loop_number = 0;
    U16 write_number = 0;

    if (acct_array == NULL || count == NULL)
    {
        return MMI_EMAIL_FAIL;
    }

    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, imap_push_file);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    fs_result = FS_Read(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &read);
    FS_Close(file_handle);
    if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_imap_push_cntx_struct))
    {
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    if (MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER < *count)
    {
        loop_number = MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER;
    }
    else
    {
        loop_number = *count;
    }
    for (index = 0; write_number < loop_number && index < MMI_EMAIL_IMAP_PUSH_ACCT_MAX_NUMBER; index++)
    {
        if (imap_push_cntx.acct_on[index] == MMI_TRUE)
        {
            acct_array[write_number++] = index + 1;
        }
    }
    *count = write_number;
    return MMI_EMAIL_SUCCESS;
}


extern mmi_email_app_core_result_enum mmi_email_imap_push_set_status(MMI_BOOL status)
{
    mmi_email_imap_push_cntx_struct imap_push_cntx;
    U32 read = 0;
    U32 written = 0;
    FS_HANDLE file_handle;
    WCHAR *file_path = NULL;
    S32 fs_result = 0;

    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, imap_push_file);
    file_handle = FS_Open(file_path, FS_READ_WRITE);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    fs_result = FS_Read(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &read);
    if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_imap_push_cntx_struct))
    {
        FS_Close(file_handle);
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    if (imap_push_cntx.feature_on == status)
    {
        FS_Close(file_handle);
        return MMI_EMAIL_SUCCESS;
    }
    fs_result = FS_Seek(file_handle, 0, FS_FILE_BEGIN);
    if (fs_result != FS_NO_ERROR)
    {
        FS_Close(file_handle);
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    imap_push_cntx.feature_on = status;
    fs_result = FS_Write(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &written);
    FS_Close(file_handle);
    if (fs_result != FS_NO_ERROR || written != sizeof(mmi_email_imap_push_cntx_struct))
    {
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    return MMI_EMAIL_SUCCESS;
}


extern mmi_email_app_core_result_enum mmi_email_imap_push_get_status(MMI_BOOL *status)
{
    mmi_email_imap_push_cntx_struct imap_push_cntx;
    U32 read = 0;
    FS_HANDLE file_handle;
    WCHAR *file_path = NULL;
    S32 fs_result = 0;

    if (status == NULL)
    {
         return MMI_EMAIL_FAIL;
    }

    file_path = (WCHAR*)get_ctrl_buffer(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(file_path, "%s%s%s", srv_email_get_root_path(), app_core_path, imap_push_file);
    file_handle = FS_Open(file_path, FS_READ_ONLY);
    free_ctrl_buffer(file_path);
    if (file_handle < 0)
    {
        g_fs_error_detail = file_handle;
        return MMI_EMAIL_FAIL;
    }
    fs_result = FS_Read(file_handle, &imap_push_cntx, sizeof(mmi_email_imap_push_cntx_struct), &read);
    FS_Close(file_handle);
    if (fs_result != FS_NO_ERROR || read != sizeof(mmi_email_imap_push_cntx_struct))
    {
        g_fs_error_detail = fs_result;
        return MMI_EMAIL_FAIL;
    }
    *status = imap_push_cntx.feature_on;
    return MMI_EMAIL_SUCCESS;
}
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

#endif /* __MMI_EMAIL__ */
