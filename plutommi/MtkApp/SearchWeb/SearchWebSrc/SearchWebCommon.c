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
 *  SearchWebCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Common procedures for search modules.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SEARCH_WEB__

#include "SearchWebProt.h"
#include "SearchWebBaiduProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "stdio.h"
#include "Conversions.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "SearchWebGProt.h"
#include "CustMenuRes.h"
#include "mmi_rp_app_search_web_def.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "SearchWebGoogleProt.h"


/****************************************************************************
 * Global Functions
 ****************************************************************************/

#define INTERNAL_FUNCTIONS /* --------------------------------------------- */

/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_to_hex_encoding
 * DESCRIPTION
 *  Encode the raw data to hex string encoding. If buffer size is not large
 *  enough, some bytes will be truncated.
 * PARAMETERS
 *  raw_data            [IN]  Raw data
 *  data_size           [IN]  Data size
 *  dest_str            [OUT] Output encoding
 *  dest_buffer_size    [IN]  Buffer size of dest_str
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sweb_to_hex_encoding(const U8 *raw_data, U32 data_size, CHAR *dest_str, U32 dest_buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; i < data_size && (i << 1) + 1 < dest_buffer_size - 2; i++)
    {
        register U32 digit;

        /* Digit 1 */
        digit = ((U32)raw_data[i] >> 4) & 0xf;
        dest_str[i << 1] = mmi_sweb_to_hex_char(digit);
        /* Digit 2 */
        digit = (U32)raw_data[i] & 0xf;
        dest_str[(i << 1) + 1] = mmi_sweb_to_hex_char(digit);
    }

    dest_str[i << 1] = '\0';

    return (MMI_BOOL)((i << 1) + 1 < dest_buffer_size - 2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_is_url_unreserved_char
 * DESCRIPTION
 *  To test a character if it is an URL-unreserved character.
 * PARAMETERS
 *  ch      [IN] Character
 * RETURNS
 *  MMI_TRUE:   Unreserved char
 *  MMI_FALSE:  Reserved
 *****************************************************************************/
static MMI_BOOL mmi_sweb_is_url_unreserved_char(const CHAR ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const CHAR MARK_CHARS[] = "-_.!~*'()"; /* See RFC-2396 */
    const CHAR *mark_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_sweb_is_alphabet(ch) || mmi_sweb_is_digit(ch))
    {
        return MMI_TRUE;
    }

    for (mark_p = MARK_CHARS; *mark_p != '\0'; mark_p++)
    {
        if (*mark_p == ch)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_to_request_form_url_encoding
 * DESCRIPTION
 *  Encode he string to the escaped encoding of URL for request form.
 * PARAMETERS
 *  dest            [OUT] Output string
 *  max_dest_len    [IN]  Maximum length of output string. NOTE this value is
 *                        not buffer size. dest[max_dest_len] may be filled
 *                        as '\0'
 *  raw_data        [IN]  Data to be encoded
 *  raw_data_size   [IN]  Data size
 *  truncated       [OUT] Will be set to MMI_TRUE if the string is truncated.
 *                        That is, the encoding should be longer than the
 *                        max_dest_len.
 * RETURNS
 *  The position of the null terminator '\0' in dest_url.
 *****************************************************************************/
static CHAR *mmi_sweb_to_request_form_url_encoding(
    CHAR *dest,
    U32 max_dest_len, /* dest[max_dest_len] will be filled as '\0' in worst case */
    const CHAR* raw_data,
    U32 raw_data_size,
    MMI_BOOL *truncated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 dest_len;
    CHAR ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_len = 0;
    
    for (i = 0; i < raw_data_size && (dest_len + 3) <= max_dest_len; i++)
    {
        ch = raw_data[i];

        if (mmi_sweb_is_url_unreserved_char(ch))
        {
            dest[dest_len++] = ch;
        }
        else if (ch == ' ') /* HTML 4.01 Specification */
        {
            dest[dest_len++] = '+';
        }
        else
        {
            U32 val;

            dest[dest_len++] = '%'; /* [0] */
            val = ((U32)ch >> 4) & 0xf;
            dest[dest_len++] = mmi_sweb_to_hex_char(val); /* [1] */
            val = ((U32)ch) & 0xf;
            dest[dest_len++] = mmi_sweb_to_hex_char(val); /* [2] */
        }
    }

    /* dest[max_dest_len] will be filled as '\0' in worst case */
    dest[dest_len] = '\0';

    if (truncated != NULL)
    {
        *truncated = (MMI_BOOL)(i >= raw_data_size);
    }

    return &(dest[dest_len]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_trim
 * DESCRIPTION
 *  Trim string; eliminate head and tail spaces.
 * PARAMETERS
 *  src     [IN]  Source string
 *  dest    [OUT] Destination
 * RETURNS
 *  dest
 *****************************************************************************/
U16 *mmi_sweb_trim(const U16 *src, U16 *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 *src_p, *src_end_p;
    U16 *dest_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    src_p = src;
    src_end_p = src + mmi_wcslen(src);
    dest_p = dest;

    /* Trim head spaces */
    while (src_p != src_end_p && *src_p == L' ')
    {
        src_p++;
    }

    /* Trim tail spaces */
    while (src_end_p != src_p && *(src_end_p - 1) == L' ')
    {
        src_end_p--;
    }

    while (src_p != src_end_p)
    {
        *(dest_p++) = *(src_p++);
    }

    *(dest_p) = L'\0';

    return dest;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_strcat
 * DESCRIPTION
 *  Concatenate string to dest
 * PARAMETERS
 *  dest    [IN/OUT] Destination string
 *  string  [IN]     Source string
 * RETURNS
 *  The position of the null terminator '\0' in dest_url.
 *****************************************************************************/
CHAR *mmi_sweb_strcat(register CHAR *dest, register const CHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*dest != '\0')
    {
        dest++;
    }
    
    while (*string != '\0')
    {
        *dest = *string;
        dest++;
        string++;
    }

    *dest = '\0';

    return dest; /* Note here, returns the tail position */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_append_url_param
 * DESCRIPTION
 *  Append a parameter to dest_url.
 * PARAMETERS
 *  dest_url    [IN/OUT] Output URL.
 *  first_param [IN] Flag to indicate whether this is the first parameter of
 *                   the URL. If MMI_TRUE, '?' will be used to concatenate the
 *                   URL and the parameter. Otherwise, '&' will be used.
 *  param_name  [IN] The name of the parameter
 *  param_val   [IN] The value of the parameter
 * RETURNS
 *  The position of the null terminator '\0' in dest_url.
 *****************************************************************************/
CHAR *mmi_sweb_append_url_param(CHAR *dest_url, MMI_BOOL first_param, const CHAR *param_name, const CHAR *param_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 url_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url_len = strlen(dest_url);

    /* Append '?' or '&' */
    dest_url[url_len] = (first_param ? '?' : '&');
    dest_url[++url_len] = '\0';

    /* Returns string tail */
    return mmi_sweb_strcat(
              mmi_sweb_strcat(
                  mmi_sweb_strcat(dest_url + url_len, param_name), "="), param_val);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_append_url_param_int
 * DESCRIPTION
 *  Append a parameter to dest_url.
 * PARAMETERS
 *  dest_url    [IN/OUT] Output URL.
 *  first_param [IN] Flag to indicate whether this is the first parameter of
 *                   the URL. If MMI_TRUE, '?' will be used to concatenate the
 *                   URL and the parameter. Otherwise, '&' will be used.
 *  param_name  [IN] The name of the parameter
 *  param_val   [IN] The value of the parameter. It will be converted to decimal
 *                   string.
 * RETURNS
 *  The position of the null terminator '\0' in dest_url.
 *****************************************************************************/
CHAR *mmi_sweb_append_url_param_int(CHAR *dest_url, MMI_BOOL first_param, const CHAR *param_name, const U32 param_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR param_val_str[15];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(param_val_str, "%d", param_val);
    return mmi_sweb_append_url_param(dest_url, first_param, param_name, param_val_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_append_url_param_ucs2
 * DESCRIPTION
 *  Append a parameter to dest_url.
 * PARAMETERS
 *  dest_url    [IN/OUT] Output URL.
 *  first_param [IN] Flag to indicate whether this is the first parameter of
 *                   the URL. If MMI_TRUE, '?' will be used to concatenate the
 *                   URL and the parameter. Otherwise, '&' will be used.
 *  param_name  [IN] The name of the parameter
 *  param_val   [IN] UCS2-encoded string of the value of the parameter.
 *                   It will be encoded to escaped encoding in the result.
 *  target_encoding [IN] The encoding of param_val should be encoded first.
 *                       For example, UTF-8. After encoded, the param_val will
 *                       be encoded to escaped encoding finally.
 *  url_buffer_size [IN] Maximum size of URL, including the tail '\0'.
 *                       If the param_val so long to put into the URL, it will
 *                       be truncated.
 *  truncated   [OUT] If the param_val is known to be truncated, MMI_TRUE will
 *                    be set. But if we don't know whether param_val is truncated
 *                    or not, may be yes may be no, MMI_FALSE will be set.
 * RETURNS
 *  The position of the null terminator '\0' in dest_url.
 *****************************************************************************/
CHAR *mmi_sweb_append_url_param_ucs2(
    CHAR *dest_url,
    MMI_BOOL first_param,
    const CHAR *param_name,
    const U16 *param_val,
    mmi_chset_enum target_encoding,
    U32 url_buffer_size,
    MMI_BOOL *truncated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *buffer;
    CHAR *url_tail;
    S32 dest_url_len;
    S32 max_param_val_len;
    U32 encoding_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_url_len = strlen(dest_url);
    max_param_val_len =
        (S32)url_buffer_size - (dest_url_len + 1 + strlen(param_name) + 1) - 1;
    /*                                     '?' or '&'     param        '=' */

    if (max_param_val_len <= 0)
    {
        if (truncated != NULL)
        {
            *truncated = MMI_TRUE;
        }
        return dest_url + dest_url_len;
    }
    
    buffer = (CHAR*)OslMalloc(max_param_val_len + 1);

    /* NOTE: We are unable to know whether it is truncated in mmi_chset_convert */
    /* buffer <= Encode(param_val) */
    encoding_len = mmi_chset_convert(MMI_CHSET_UCS2, target_encoding, (CHAR*)param_val, buffer, max_param_val_len + 1);

    /* encoding_len includes null terminator */
    while (encoding_len > 0 && buffer[encoding_len - 1] == 0)
    {
        encoding_len--;
    }

    /* dest_url += "&param_name=%xx%xx%xx"*/
    url_tail = mmi_sweb_append_url_param(dest_url, first_param, param_name, "");
    url_tail = mmi_sweb_to_request_form_url_encoding(url_tail, max_param_val_len, buffer, encoding_len, truncated);

    OslMfree(buffer);

    return url_tail;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_read_common_history
 * DESCRIPTION
 *  Read the common search history from NVRAM.
 * PARAMETERS
 *  history     [OUT] Search history. If failed to read or the history is not
 *                    initialized yet, it will still be initialized.
 * RETURNS
 *  The data in NVRAM is already initialized.
 *****************************************************************************/
MMI_BOOL mmi_sweb_read_common_history(nvram_ef_search_web_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SEARCH_WEB_HISTORY_LID, 1, history, sizeof(nvram_ef_search_web_history_struct), &error);

    if (history->valid_magic_number != NVRAM_EF_SEARCH_WEB_HISTORY_VALID_MAGIC_NUMBER) /* history is invalid */
    {
        error = -1; /* Reset history */
    }

    if (error < 0)
    {
        mmi_sweb_clear_history(history);
    }
    else
    {
        for (i = 0; i < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM; i++)
        {
            history->entry[i].string[NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN] = L'\0';
        }
    }

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_READ_COMMON_HISTORY, (U32)history, error);

    return (MMI_BOOL)(error >= 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_write_common_history
 * DESCRIPTION
 *  Write search history to NVRAM.
 * PARAMETERS
 *  history     [IN] Search history.
 * RETURNS
 *  Success or not
 *****************************************************************************/
MMI_BOOL mmi_sweb_write_common_history(const nvram_ef_search_web_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_SEARCH_WEB_HISTORY_LID, 1, (void*)history, sizeof(nvram_ef_search_web_history_struct), &error);

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_WRITE_COMMON_HISTORY, (U32)history, error);

    return (MMI_BOOL)(error >= 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_put_into_history
 * DESCRIPTION
 *  Put an input string to the history. This function will try to find if the
 *  string is already in the history first. If yes, just reorder the history;
 *  otherwise flush the oldest entry and put the new entry in.
 * PARAMETERS
 *  history     [IN/OUT] Search history.
 *  string      [IN]     String
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_put_into_history(nvram_ef_search_web_history_struct *history, const U16 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 candidate_order_index;
    U8  candidate_entry_index;
    MMI_BOOL found_in_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set as the oldest record */
    candidate_order_index = MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM - 1;
    /* To skip copying the string into history because already an entry is found */
    found_in_history = MMI_FALSE;
    
    for (i = 0; i < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM; i++)
    {
        if (history->order[i] >= MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM) /* Unused or invalid */
        {
            history->order[i] = i; /* Assign the i-th entry */
            candidate_order_index = i;
            break;
        }

        if (mmi_wcscmp(history->entry[history->order[i]].string, string) == 0)
        {
            /* We found an entry matches the string */
            candidate_order_index = i;
            found_in_history = MMI_TRUE;
            break;
        }
    }

    /* Rotate [0 ~ candidate_order_index] */
    candidate_entry_index = history->order[candidate_order_index];
    for (i = candidate_order_index; i > 0 ; i--)
    {
        history->order[i] = history->order[i - 1]; /* Shift down one entry */
    }
    history->order[0] = candidate_entry_index;

    if (!found_in_history)
    {
        mmi_wcsncpy(history->entry[candidate_entry_index].string, string, NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN);
    }

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_PUT_INTO_HISTORY, (U32)history, candidate_order_index, found_in_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_get_history_entry
 * DESCRIPTION
 *  Get an entry in the history by given index.
 * PARAMETERS
 *  history     [IN] Search history
 *  string      [IN] Entry index
 * RETURNS
 *  The entry if exists. NULL if not found, no so many entries in the history.
 *****************************************************************************/
const nvram_ef_search_web_history_entry_struct *mmi_sweb_get_history_entry(
    const nvram_ef_search_web_history_struct *history,
    U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM);
    
    if (history->order[index] < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM)
    {
        return &(history->entry[history->order[index]]);
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sweb_clear_history
 * DESCRIPTION
 *  Reset and validate the history.
 * PARAMETERS
 *  history     [IN/OUT] History to be reset and validated
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sweb_clear_history(nvram_ef_search_web_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM; i++)
    {
        history->order[i] = (kal_uint8)0xff; /* Mark as unused */
        history->entry[i].string[0] = L'\0';
    }
    
    /* Validate history */
    history->valid_magic_number = NVRAM_EF_SEARCH_WEB_HISTORY_VALID_MAGIC_NUMBER;

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_CLEAR_HISTORY, (U32)history);
}


#define EXPORTED_FUNCTIONS /* --------------------------------------------- */

/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_hot_key_is_enabled
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
MMI_BOOL mmi_search_web_hot_key_is_enabled(mmi_search_web_hot_key_enum hot_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if WAP_SUPPORT

#ifdef __MMI_SEARCH_WEB_BAIDU__
    if (mmi_sweb_baidu_hot_key_is_enabled(hot_key))
    {
        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_HOT_KEY_IS_ENABLED, hot_key, 10, MMI_TRUE);
        return MMI_TRUE;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

#ifdef __MMI_SEARCH_WEB_GOOGLE__
    if (mmi_sweb_google_hot_key_is_enabled(hot_key))
    {
        MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_HOT_KEY_IS_ENABLED, hot_key, 20, MMI_TRUE);
        return MMI_TRUE;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

#endif /* WAP_SUPPORT */


    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_HOT_KEY_IS_ENABLED, hot_key, 9999, MMI_FALSE);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_trigger_by_hot_key
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
void mmi_search_web_trigger_by_hot_key(mmi_search_web_hot_key_enum hot_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_SEARCH_WEB_TRACE_GROUP, TRC_MMI_SEARCH_WEB_TRIGGER_BY_HOT_KEY, hot_key);
    
#ifdef __MMI_SEARCH_WEB_BAIDU__
    if (mmi_sweb_baidu_hot_key_is_enabled(hot_key))
    {
        mmi_search_web_baidu_open_search_bar();
        return;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

#ifdef __MMI_SEARCH_WEB_GOOGLE__
    if (mmi_sweb_google_hot_key_is_enabled(hot_key))
    {
        mmi_search_web_google_open_search_bar();
        return;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_get_idle_hint
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
MMI_BOOL mmi_search_web_get_idle_hint(const U8 **icon_data, const WCHAR **string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SEARCH_WEB_GOOGLE__
    if (mmi_sweb_google_get_idle_hint_config(icon_data, string))
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */
    
#ifdef __MMI_SEARCH_WEB_BAIDU__
    if (mmi_sweb_baidu_get_idle_hint_config(icon_data, string))
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */    
    *icon_data = NULL;
    *string = NULL;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_get_application_name
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
const U16 *mmi_search_web_get_application_name(mmi_search_web_hot_key_enum hot_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SEARCH_WEB_BAIDU__
    if (mmi_sweb_baidu_hot_key_is_enabled(hot_key))
    {
        return (U16*)get_string(GetStringIdOfItem(MENU_ID_SEARCH_WEB_BAIDU_ENTRY));
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

#ifdef __MMI_SEARCH_WEB_GOOGLE__
    if (mmi_sweb_google_hot_key_is_enabled(hot_key))
    {
        return mmi_sweb_google_get_app_name();
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

    return (U16*)get_string(STR_GLOBAL_NONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_entry_dedicated_key_setting
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
void mmi_search_web_entry_dedicated_key_setting(mmi_search_web_hot_key_enum hot_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SEARCH_WEB_BAIDU__
    if (mmi_sweb_baidu_hot_key_is_enabled(hot_key))
    {
        mmi_popup_display(
            get_string(STR_ID_SEARCH_WEB_BAIDU_PLEASE_DISABLE_HOT_KEY_FIRST),
            MMI_EVENT_FAILURE,
            NULL);
        return;
    }
#endif /* __MMI_SEARCH_WEB_BAIDU__ */

    mmi_popup_display(
        get_string(STR_GLOBAL_NOT_AVAILABLE),
        MMI_EVENT_FAILURE,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_trigger_by_down_key
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
void mmi_search_web_trigger_by_down_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_search_web_trigger_by_hot_key(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_trigger_by_long_pressing_star
 * DESCRIPTION
 *  Please refer to SearchWebGProt.h
 *****************************************************************************/
void mmi_search_web_trigger_by_long_pressing_star(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_search_web_trigger_by_hot_key(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_search_web_init
 * DESCRIPTION
 *  Initialize search module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_search_web_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SEARCH_WEB_BAIDU__
    mmi_sweb_baidu_init();
#endif
}


#endif /* __MMI_SEARCH_WEB__ */

