#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#ifdef __MMI_URI_AGENT__

#include "MMIDataType.h"
#include "conversions.h"
#include "app_url.h"
#include "emailsrvgprot.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "EmailAppGProt.h"
#include "EmailAppProt.h"
#include "EmailAppStateMgr.h"
#include "EmailAppLib.h"

typedef enum
{
    MMI_EMAIL_URI_TO_TYPE = 0,
    MMI_EMAIL_URI_CC_TYPE,
    MMI_EMAIL_URI_BCC_TYPE
} mmi_email_uri_addr_type_enum;

typedef struct 
{
    BOOL is_valid;
    char *param;
    char *addr_ptr;
    char *to_ptr;
    char *cc_ptr;
    char *from_ptr;
    char *subject_ptr;
    char *body_ptr;
    U16 addr_len;
    U16 to_len;
    U16 cc_len;
    U16 from_len;
    U16 subject_len;
    U16 body_len;
    srv_uriagent_appid_enum ura_appid;
    srv_uriagent_uri_request_hdlr_cb cb;
} mmi_email_uri_info_struct;


static mmi_email_uri_info_struct email_uri_mailto_info;


static void mmi_email_uri_mailto_send(void);
static void mmi_email_uri_mailto_back(void);
static void mmi_email_uri_mailto_back_interrupt(void);
static BOOL mmi_email_uri_mailto_parser(void);
static BOOL mmi_email_uri_mailto_parse_sector(
                                              char **parser_head,
                                              char **parser_tail,
                                              char **parser_ptr,
                                              char *parser,
                                              U16 parser_len,
                                              U16 *sector_len);
static void mmi_email_uri_mailto_fill_data(
                                           mmi_email_app_send_param_struct *param,
                                           email_app_send_param_fill_enum *param_fill_flag);
static BOOL mmi_email_uri_mailto_convertor(
                                           char **src_ptr,
                                           U16 *src_len,
                                           char *buf_ptr,
                                           S32 buf_len,
                                           U16 *ucs2_len);
static BOOL mmi_email_uri_mailto_fill_addr(
                                           char *data,
                                           U16 data_len,
                                           mmi_email_uri_addr_type_enum type,
                                           mmi_email_app_send_param_struct *parm);
static void mmi_email_uri_mailto_post_handler(void);

static void mmi_email_uri_mailto_handler(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb);




void mmi_email_uri_init(void)
{
    srv_uriagent_register_hdlr_by_scheme(
        EMAIL_URI_MAILTO_SCHEME,
        mmi_email_uri_mailto_handler,
        MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_handler
* DESCRIPTION
*  Check the URI string and display compose mail screen
* PARAMETERS
*  ura_appid        [IN]        
*  url              [IN]        the source string contained data
*  param            [IN]        
*  options          [IN]        
*  cb               [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_email_uri_mailto_handler(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_HANDLER, __LINE__);

    if ((url == NULL) || (param == NULL) || !mmi_email_smgr_show_ui_check(NULL))
    {
        if (cb != NULL)
        {
            (*cb)(ura_appid, SRV_URIAGENT_APPID_EMAIL, SRV_URIAGENT_ERR_UNSUPPORTED);
        }
        return;
    }

    /* avoid the continuous key press on browser */
    if (email_uri_mailto_info.param)
    {
        if (email_uri_mailto_info.cb != NULL)
        {
            (*email_uri_mailto_info.cb)(email_uri_mailto_info.ura_appid, SRV_URIAGENT_APPID_EMAIL, SRV_URIAGENT_ERR_PROCESSING);
        }
        return;
    }

    memset(&email_uri_mailto_info, 0, sizeof(mmi_email_uri_info_struct));
    email_uri_mailto_info.param = OslMalloc(sizeof(char) * (EMAIL_URI_BUFFER_LENGTH + 1));
    memset(email_uri_mailto_info.param, 0, sizeof(char) * (EMAIL_URI_BUFFER_LENGTH + 1));
    memcpy(email_uri_mailto_info.param, param, EMAIL_URI_BUFFER_LENGTH * sizeof(char));
    if (!mmi_email_uri_mailto_parser())
    {
        if (cb != NULL)
        {
            (*cb)(ura_appid, SRV_URIAGENT_APPID_EMAIL, SRV_URIAGENT_ERR_UNSUPPORTED);
        }
        if (email_uri_mailto_info.param)            // it's better free the ctrl buffer before calling CALLBACK
        {
            OslMfree(email_uri_mailto_info.param);
            email_uri_mailto_info.param = NULL;
        }
        return;
    }
    email_uri_mailto_info.cb = cb;
    email_uri_mailto_info.ura_appid = ura_appid;
    if (email_uri_mailto_info.cb != NULL)
    {
        (*email_uri_mailto_info.cb)(email_uri_mailto_info.ura_appid, SRV_URIAGENT_APPID_EMAIL, SRV_URIAGENT_ERR_OK);
    }
    email_uri_mailto_info.cb = NULL;
    if (options == SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
    {
        mmi_email_util_display_confirm_ext(
            0,
            mmi_email_uri_mailto_send,
            mmi_email_uri_mailto_back,
            mmi_email_uri_mailto_back_interrupt,
            NULL,
            TRUE,
            GetString(STR_EMAIL_URI_SEND_NOW_ID),
            MMI_EVENT_QUERY);
    }
    else
    {
        mmi_email_uri_mailto_send();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_back
* DESCRIPTION
*  Go back to the last screen and free the memory
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_uri_mailto_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_BACK, __LINE__);

    if (email_uri_mailto_info.param)
    {
        OslMfree(email_uri_mailto_info.param);
        email_uri_mailto_info.param = NULL;
    }
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_back_interrupt
* DESCRIPTION
*  Free the memory
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_uri_mailto_back_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_uri_mailto_info.param)
    {
        OslMfree(email_uri_mailto_info.param);
        email_uri_mailto_info.param = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_find_sector
* DESCRIPTION
*  Search the string find the first match of '&' or '?'
* PARAMETERS
*  void
* RETURNS
*  The match pointer
*****************************************************************************/
char* mmi_email_uri_mailto_find_sector(char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *finder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    finder = data;
    while (*finder && (*finder != '&') && (*finder != '?'))
    {
        finder++;
    }
    return ((*finder) ? finder : NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_parser
* DESCRIPTION
*  Parse the data and save the pointer
* PARAMETERS
*  void
* RETURNS
*  Whether successful
*****************************************************************************/
BOOL mmi_email_uri_mailto_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *parser_head = NULL, *parser_tail = NULL;
    BOOL is_valid = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_PARSER, __LINE__);

    parser_head = email_uri_mailto_info.param;
    if (parser_head[0] != '?')
    {   // in this IF, to handle Email address
        email_uri_mailto_info.addr_ptr = parser_head;
        parser_tail = mmi_email_uri_mailto_find_sector(parser_head);
        if (parser_tail == NULL)    // only Email address found
        {
            email_uri_mailto_info.addr_len = strlen(email_uri_mailto_info.param);
            return TRUE;
        }
        else
        {
            email_uri_mailto_info.addr_len = parser_tail - parser_head;
            parser_tail[0] = '&';
            parser_head = parser_tail + 1;
        }
        email_uri_mailto_info.is_valid = TRUE;
    }
    else
    {   // just ignore '?'
        parser_head += 1;
    }
    do 
    {
        switch (parser_head[0])
        {
            case 't':
            case 'T':
                {   // handle {to}
                    is_valid = mmi_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &email_uri_mailto_info.to_ptr,
                                EMAIL_URI_MAILTO_TO_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_TO_HEADER),
                                &email_uri_mailto_info.to_len);
                }
                break;
            case 'c':
            case 'C':
                {   // handle {cc}
                    is_valid = mmi_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &email_uri_mailto_info.cc_ptr,
                                EMAIL_URI_MAILTO_CC_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_CC_HEADER),
                                &email_uri_mailto_info.cc_len);
                }
                break;
            case 'f':
            case 'F':
                {   // handle {from}
                    is_valid = mmi_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &email_uri_mailto_info.from_ptr,
                                EMAIL_URI_MAILTO_FROM_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_FROM_HEADER),
                                &email_uri_mailto_info.from_len);
                    is_valid = FALSE;
                }
                break;
            case 's':
            case 'S':
                {   // handle {subject}
                    is_valid = mmi_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &email_uri_mailto_info.subject_ptr,
                                EMAIL_URI_MAILTO_SUB_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_SUB_HEADER),
                                &email_uri_mailto_info.subject_len);
                }
                break;
            case 'b':
            case 'B':
                {   // handle {body}, so {bcc} not supported
                    is_valid = mmi_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &email_uri_mailto_info.body_ptr,
                                EMAIL_URI_MAILTO_BODY_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_BODY_HEADER),
                                &email_uri_mailto_info.body_len);
                }
                break;
            default:
                {
                    parser_tail = mmi_email_uri_mailto_find_sector(parser_head);
                    if (parser_tail != NULL)
                    {
                        if (parser_tail[1] != '\0')
                        {
                            parser_head = parser_tail + 1;
                        }
                        else
                        {   // reach the end
                            parser_tail = NULL;
                        }
                    }
                }
                break;
        }
        if (!email_uri_mailto_info.is_valid)
        {
            email_uri_mailto_info.is_valid = is_valid;
        }
    } while(parser_tail != NULL);
    return email_uri_mailto_info.is_valid;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_parse_sector
* DESCRIPTION
*  Parse the sector and save the pointer and length
* PARAMETERS
*  parser_head      [IN]
*  parser_tail      [IN]
*  parser_ptr       [IN]
*  parser           [IN]
*  parser_len       [IN]
*  sector_len       [IN]
* RETURNS
*  void
*****************************************************************************/
BOOL mmi_email_uri_mailto_parse_sector(
        char **parser_head,
        char **parser_tail,
        char **parser_ptr,
        char *parser,
        U16 parser_len,
        U16 *sector_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_valid = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_PARSE_SECTOR, __LINE__);

    // this sector sting is too short..
    if ((parser_len + 1) >= (U16)strlen(*parser_head))
    {
        (*parser_tail)[0] = '\0';
        memset(*parser_head, 0, strlen(*parser_head));
        *parser_tail = NULL;
        return FALSE;
    }

    // compare with the {title}:to/subject/...
    if (mmi_email_uti_strnicmp(*parser_head, parser, parser_len) == 0)
    {
        *parser_head += parser_len;
        while ((*parser_head)[0] == ' ')    // ignore the spaces
        {
            if ((*parser_head)[1] != '\0')  // it's not the end
            {
                *parser_head += 1;
            }
            else                            // reach the end
            {
                *parser_tail = NULL;
                return FALSE;
            }
        }
        if ((*parser_head)[0] == '=')       // find the {=}
        {
            *parser_head += 1;
            *parser_ptr = *parser_head;
            is_valid = ((((*parser_head)[0] == '&') || ((*parser_head)[0] == '\0')) ? FALSE : TRUE);
        }
    }

    // to find the end of this sector
    *parser_tail = mmi_email_uri_mailto_find_sector(*parser_head);
    if (*parser_tail != NULL)
    {                                       // it's not the last sector
        if (is_valid)
        {
            *sector_len = *parser_tail - *parser_head;
        }
        if ((*parser_tail)[1] != '\0')      // skip the char {?}/{&}
        {
            *parser_head = *parser_tail + 1;
        }
        else                                // next sector is invalid
        {
            *parser_tail = NULL;
        }
    }
    else                                    // this is the last sector
    {
        if (is_valid)
        {
            *sector_len = strlen(*parser_head);
        }
    }
    return is_valid;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_fill_data
* DESCRIPTION
*  Fill the data to the buffer
* PARAMETERS
*  param            [IN]
*  param_fill_flag  [IN]
* RETURNS
*  void
*****************************************************************************/
void mmi_email_uri_mailto_fill_data(
        mmi_email_app_send_param_struct *param,
        email_app_send_param_fill_enum *param_fill_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *temp_ptr = NULL, *url_ptr = NULL;
    BOOL ret = TRUE;
    U16 ucs2_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_FILL_DATA, __LINE__);

    url_ptr = email_uri_mailto_info.param;
    email_uri_mailto_info.param = OslMalloc((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH);
    // above buffer used to store UCS-2 string
    memset(email_uri_mailto_info.param, 0, (EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH);
    temp_ptr = OslMalloc((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH);
    // above buffer used as exchange buffer
    if (email_uri_mailto_info.addr_ptr != NULL)
    {
        if (!mmi_email_uri_mailto_convertor(
                &email_uri_mailto_info.addr_ptr,
                &email_uri_mailto_info.addr_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (email_uri_mailto_info.to_ptr != NULL))
    {
        if (!mmi_email_uri_mailto_convertor(
                &email_uri_mailto_info.to_ptr,
                &email_uri_mailto_info.to_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (email_uri_mailto_info.cc_ptr != NULL))
    {
        if (!mmi_email_uri_mailto_convertor(
                &email_uri_mailto_info.cc_ptr,
                &email_uri_mailto_info.cc_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (email_uri_mailto_info.subject_ptr != NULL))
    {
        if (!mmi_email_uri_mailto_convertor(
                &email_uri_mailto_info.subject_ptr,
                &email_uri_mailto_info.subject_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (email_uri_mailto_info.body_ptr != NULL))
    {
        if (!mmi_email_uri_mailto_convertor(
                &email_uri_mailto_info.body_ptr,
                &email_uri_mailto_info.body_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    OslMfree(temp_ptr);
    OslMfree(url_ptr);  // free the original param
    if (!ret)
    {
        OslMfree(email_uri_mailto_info.param);
        email_uri_mailto_info.param = NULL;
        return;
    }
    if (mmi_email_uri_mailto_fill_addr(
            email_uri_mailto_info.addr_ptr,
            email_uri_mailto_info.addr_len,
            MMI_EMAIL_URI_TO_TYPE,
            param))
    {
        *param_fill_flag |= EMAIL_TO_FILL_FLAG;
    }
    if (mmi_email_uri_mailto_fill_addr(
            email_uri_mailto_info.to_ptr,
            email_uri_mailto_info.to_len,
            MMI_EMAIL_URI_TO_TYPE,
            param))
    {
        *param_fill_flag |= EMAIL_TO_FILL_FLAG;
    }
    if (mmi_email_uri_mailto_fill_addr(
            email_uri_mailto_info.cc_ptr,
            email_uri_mailto_info.cc_len,
            MMI_EMAIL_URI_CC_TYPE,
            param))
    {
        *param_fill_flag |= EMAIL_CC_FILL_FLAG;
    }
    if ((email_uri_mailto_info.subject_ptr != NULL) &&
        (email_uri_mailto_info.subject_len != 0))
    {
        param->subj = email_uri_mailto_info.subject_ptr;
        *param_fill_flag |= EMAIL_SUBJ_FILL_FLAG;
    }
    if ((email_uri_mailto_info.body_ptr != NULL) &&
        (email_uri_mailto_info.body_len != 0))
    {
        param->cont = email_uri_mailto_info.body_ptr;
        *param_fill_flag |= EMAIL_CONT_FILL_FLAG;
    }
    param->parent_id = GRP_ID_ROOT;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_convertor
* DESCRIPTION
*  Convert the escape URL encoding string to UCS2
* PARAMETERS
*  src_ptr          [IN/OUT]
*  src_len          [IN/OUT]
*  buf_ptr          [IN]
*  buf_len          [IN]
* RETURNS
*  void
*****************************************************************************/
BOOL mmi_email_uri_mailto_convertor(
        char **src_ptr,
        U16 *src_len,
        char *buf_ptr,
        S32 buf_len,
        U16 *ucs2_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mmiEncoding = 0;
    U16 out_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buf_ptr, 0, buf_len);
    if (applib_cvt_escape_string_to_normal_string(
            *src_ptr,
            *src_len,
            buf_ptr,
            buf_len))
    {
        *src_ptr = email_uri_mailto_info.param + *ucs2_len; // *src_ptr's value changed !!
        *src_len = strlen(buf_ptr);
    }
    else
    {
        return FALSE;
    }
    mmiEncoding = MMI_CHSET_UTF8;
    out_len = mmi_chset_convert(
                (mmi_chset_enum)mmiEncoding,
                MMI_CHSET_UCS2,
                (char*)buf_ptr,
                (char*)*src_ptr,
                (EMAIL_URI_BUFFER_LENGTH * ENCODING_LENGTH) - *ucs2_len);
    if (out_len == 0)
    {
        return FALSE;
    }
    *ucs2_len += out_len;
    return TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_fill_addr
* DESCRIPTION
*  Parse the data for multi-address filled(UCS2 encoding)
* PARAMETERS
*  data         [IN]
*  data_len     [IN]
*  parm         [IN]
* RETURNS
*  void
*****************************************************************************/
BOOL mmi_email_uri_mailto_fill_addr(
        char *data,
        U16 data_len,
        mmi_email_uri_addr_type_enum type,
        mmi_email_app_send_param_struct *parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    WCHAR *temp_ptr = NULL, *comma_symb_ptr = NULL;
    BOOL is_valid = FALSE;
    U32 *num_ptr = NULL;
    S32 addr_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((data == NULL) || (data_len == 0))
    {
        return FALSE;
    }
    if (type == MMI_EMAIL_URI_TO_TYPE)
    {
        i = 0;
        num_ptr = &(parm->to_num);
    }
    else if (type == MMI_EMAIL_URI_CC_TYPE)
    {
        i = parm->to_num;
        num_ptr = &(parm->cc_num);
    }
    else
    {
        i = parm->to_num + parm->cc_num;
        num_ptr = &(parm->bcc_num);
    }
    for (; i < MMI_EMAIL_MAX_ADDR_NUM; i++)     // to find a blank position
    {
        if (!parm->addr[i].addr_mail || (mmi_wcslen((WCHAR*)parm->addr[i].addr_mail) == 0))
        {
            break;
        }
    }
    if (i == MMI_EMAIL_MAX_ADDR_NUM - 1)        // [NEED REVISE] should not {-1}
    {                                           // if no blank position found, return flase
        return FALSE;
    }
    temp_ptr = (WCHAR*)data;
    parm->addr[i].addr_mail = (CHAR*)temp_ptr;
    while ((comma_symb_ptr = mmi_wcschr(temp_ptr, L',')) != NULL)
    {
        comma_symb_ptr[0] = L'\0';
        comma_symb_ptr += 1;
        while (comma_symb_ptr[0] == L' ')
        {
            comma_symb_ptr += 1;
        }
        if (comma_symb_ptr[0] == L',')
        {
            temp_ptr = comma_symb_ptr;
            continue;
        }
        if (comma_symb_ptr[0] != L'\0')
        {
            temp_ptr = comma_symb_ptr;
            addr_len = mmi_wcslen((WCHAR*)parm->addr[i].addr_mail);
            if ((addr_len != 0) &&
                (addr_len <= MMI_EMAIL_MAX_ADDR_LEN) &&
                (mmi_email_util_chk_addr_ex((WCHAR*)parm->addr[i].addr_mail)))
            {
                is_valid = TRUE;
                if ((i + 1) == MMI_EMAIL_MAX_ADDR_NUM)  // no blank position
                {
                    break;
                }
                else
                {
                    parm->addr[++i].addr_mail = (CHAR*)temp_ptr;
                    (*num_ptr) += 1;
                }
            }
            else
            {
                parm->addr[i].addr_mail = (CHAR*)temp_ptr;
            }
        }
        comma_symb_ptr = NULL;
    }
    if (parm->addr[i].addr_mail)
    {
        addr_len = mmi_wcslen((WCHAR*)parm->addr[i].addr_mail);
        if ((addr_len != 0) &&
            (addr_len <= MMI_EMAIL_MAX_ADDR_LEN) &&
            (mmi_email_util_chk_addr_ex((WCHAR*)parm->addr[i].addr_mail)))
        {
            is_valid = TRUE;
            (*num_ptr) += 1;
        }
        else
        {
            parm->addr[i].addr_mail = NULL;
        }
    }
    return is_valid;
}


void mmi_email_uri_mailto_send_switch_stor_lsk_callback(BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        mmi_email_uri_mailto_send();
    }
    else
    {
        if (email_uri_mailto_info.param)
        {
            OslMfree(email_uri_mailto_info.param);
            email_uri_mailto_info.param = NULL;
        }
        mmi_email_lib_error_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
    }
}


void mmi_email_uri_mailto_send_switch_stor_rsk_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_uri_mailto_info.param)
    {
        OslMfree(email_uri_mailto_info.param);
        email_uri_mailto_info.param = NULL;
    }
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_send
* DESCRIPTION
*  Display compose mail screen for URI mailto
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_uri_mailto_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_send_param_struct *email_param = NULL;
    email_app_send_param_fill_enum mail_param_fill_flag = EMAIL_NONE_FILL_FLAG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_SEND, __LINE__);

    if (!mmi_email_smgr_show_ui_check(NULL))
    {
        return;
    }

    email_param = OslMalloc(sizeof(mmi_email_app_send_param_struct));
    memset(email_param, 0, sizeof(mmi_email_app_send_param_struct));
    if ((email_uri_mailto_info.param != NULL) && mmi_email_smgr_network_check())
    {
        mmi_email_uri_mailto_fill_data(email_param, &mail_param_fill_flag);
        if (mail_param_fill_flag != 0)
        {
            mmi_email_app_send(email_param, mail_param_fill_flag);
        }
        else
        {
            mmi_email_lib_error_popup(STR_GLOBAL_INVALID_EMAIL_ADDRESS);
        }
    }
    OslMfree(email_param);
    mmi_email_uri_mailto_post_handler();
}


/*****************************************************************************
* FUNCTION
*  mmi_email_uri_mailto_post_handler
* DESCRIPTION
*  Post handler of URI mailto
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_uri_mailto_post_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, EMAILAPP_FUNC_MMI_EMAIL_URI_MAILTO_POST_HANDLER, __LINE__);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_EMAIL_CONFIRM_URI)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_EMAIL_CONFIRM_URI);
    }
    if (email_uri_mailto_info.cb != NULL)
    {
        (*email_uri_mailto_info.cb)(email_uri_mailto_info.ura_appid, SRV_URIAGENT_APPID_EMAIL, SRV_URIAGENT_ERR_OK);
    }
    if (email_uri_mailto_info.param)
    {
        OslMfree(email_uri_mailto_info.param);
        email_uri_mailto_info.param = NULL;
    }
    return;
}












#endif /* __MMI_URI_AGENT__ */
#endif /* __MMI_EMAIL__ */



