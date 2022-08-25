extern "C"
{
#include "app_base64.h"
#include "app_mine.h"
#include "app_url.h"
#include "app_usedetails.h"
#include "app_qp.h"
#include "app_ua.h"

}

#define MMI_MSG_MAX_ADDRESS_LEN 255

AVK_ADD_ITEM(AVK_OTHER_APPLIB_AUTO,L"Auto case",AVK_OTHER_APPLIB);


AVK_CASE(AVK_OTHER_APPLIB_BASE64,AVK_OTHER_APPLIB_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define VS_FW_BASE64_LEN    (64)
    #define BASE64_LINE_WRAP_COUNT (76)
    
    applib_base64_part_context cntx;
    kal_char    src[] = "MediaTek (Beijing) Inc";
    kal_char    des_encode[VS_FW_BASE64_LEN];
    kal_char    des_decode[VS_FW_BASE64_LEN];
    
    kal_int32   src_len, des_len1, des_len2, temp;
    kal_int32   reval, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    src_len = strlen(src);
    memset(des_encode, 0, sizeof(des_encode));
    des_len1 = VS_FW_BASE64_LEN;
    
    /*applib_base64_part_encode_init*/
    reval = applib_base64_part_encode_init(&cntx, 0, KAL_TRUE);
	AVK_LOG_FUN(applib_base64_part_encode_init,(reval==0)&&(BASE64_LINE_WRAP_COUNT==cntx.wrap_max));


    /*applib_base64_part_encode_append*/
    temp =src_len;
    reval=applib_base64_part_encode_append(&cntx, src, &temp, des_encode, des_len1);
	AVK_LOG_FUN(applib_base64_part_encode_append,(reval>0));
    
    /*applib_base64_part_encode_finish*/
    reval=applib_base64_part_encode_finish(&cntx, des_encode+reval, des_len1-reval);
    AVK_LOG_FUN(applib_base64_part_encode_finish,(reval>0));

    /*applib_find_base64_boundary*/
    reval=applib_find_base64_boundary(des_encode,des_len1);
    AVK_LOG_FUN(applib_find_base64_boundary,(reval>0));

    /*applib_base64_part_decode_init*/
    reval=applib_base64_part_decode_init(&cntx,0); 
	AVK_LOG_FUN(applib_base64_part_decode_init,(reval==0));

    /*applib_base64_part_decode_append*/
    temp=des_len1;
    reval=applib_base64_part_decode_append(&cntx, des_encode, &temp, src,src_len);
	AVK_LOG_FUN(applib_base64_part_decode_append,(reval>0));

    /*applib_base64_part_decode_finish*/    
    reval=applib_base64_part_decode_finish(&cntx, NULL);
	AVK_LOG_FUN(applib_base64_part_decode_finish,(reval==0));
    
    
    src_len = strlen(src);
    memset(des_encode, 0, sizeof(des_encode));
    des_len1 = VS_FW_BASE64_LEN;
    
    /*applib_base64_encode*/
    reval= applib_base64_encode(
            src,            /* src */
            src_len,        /* srcl */
            des_encode,     /* dst */
            des_len1       /* dstl */);
	AVK_LOG_FUN(applib_base64_encode,(reval>0));

    /*applib_base64_encode_len*/
    reval =applib_base64_encode_len(src_len);
	AVK_LOG_FUN(applib_base64_encode_len,(reval==src_len*2));

    /*applib_base64_decode*/
	des_len2 = VS_FW_BASE64_LEN;
	memset(des_decode, 0, sizeof(des_decode));
    reval = applib_base64_decode(
                des_encode,     /* src */
                des_len1,       /* srcl */
                des_decode,     /* dst */
                des_len2);      /* dstl */
	AVK_LOG_FUN(applib_base64_decode,(reval>0));

    /*applib_base64_decode_len*/
    reval =applib_base64_decode_len(des_decode,des_len1);
	AVK_LOG_FUN(applib_base64_decode_len,(reval==des_len1));

    /*applib_base64_encode_basic*/
    src_len = strlen(src);
    memset(des_encode, 0, sizeof(des_encode));
    des_len1 = VS_FW_BASE64_LEN;
    des_len2 = VS_FW_BASE64_LEN;

    reval = applib_base64_encode_basic(
            src,            /* src */
            src_len,        /* srcl */
            des_encode,     /* dst */
            des_len1,       /* dstl */
            KAL_TRUE);      /* auto_line_wrap */
    AVK_LOG_FUN(applib_base64_encode_basic,(reval>0));

    /*applib_base64_decode_basic*/
    memset(des_decode, 0, sizeof(des_decode));
    des_len2 = VS_FW_BASE64_LEN;
    des_len1 = strlen(des_encode);
   
    ret = applib_base64_decode_basic(
                des_encode,     /* src */
                des_len1,       /* srcl */
                des_decode,     /* dst */
                des_len2);      /* dstl */
	AVK_LOG_FUN(applib_base64_decode_basic,(reval>0));

}

AVK_CASE(AVK_OTHER_APPLIB_MIME,AVK_OTHER_APPLIB_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_type=NULL;
    kal_char strtype[]="image/bmp";
    kal_wchar *filepath=(kal_wchar *)L"Z:\\Img.jpeg";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*applib_mime_type_look_up_ext*/
    mime_type = applib_mime_type_look_up(strtype, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
	AVK_LOG_FUN(applib_mime_type_look_up,(mime_type != NULL) && (MIME_TYPE_IMAGE == mime_type->mime_type));


    /*applib_mime_type_look_up_ext*/
    mime_type = applib_mime_type_look_up_ext(NULL, strtype, NULL, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
	AVK_LOG_FUN(applib_mime_type_look_up_ext,(mime_type != NULL) && (MIME_TYPE_IMAGE == mime_type->mime_type));

    /*applib_mime_get_file_type*/
    mime_type = applib_mime_get_file_type(filepath);
	AVK_LOG_FUN(applib_mime_get_file_type,0==strcmp(mime_type->file_ext,"jpeg"));

    /*applib_mime_get_mime_type*/
	AVK_LOG_FUN(applib_mime_get_mime_type,MIME_TYPE_TEXT==applib_mime_get_mime_type("text"));
    
    /*applib_mime_register_mime_type*/
    mime_type = (applib_mime_type_struct *)applib_mime_register_mime_type(MIME_TYPE_IMAGE, MIME_SUBTYPE_GIF, "gif2", "ext_gif");
    mime_type = applib_mime_type_look_up("gif2", NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
	AVK_LOG_FUN(applib_mime_register_mime_type,(mime_type != NULL) && (MIME_TYPE_IMAGE == mime_type->mime_type));
 
}

static kal_bool vs_other_applib_mine_cb(void *arg_p, kal_int32 arg_v, const applib_mime_type_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // If the subtype does not match what we want, return KAL_TRUE to visit next
    // Otherwise, return KAL_FALSE to stop traversal
    AVK_ASYN_DONE();
    return ((kal_bool)(entry->mime_subtype != (applib_mime_subtype_enum)arg_v));
}

AVK_ASYN_CASE(AVK_OTHER_APPLIB_MIME_ASYN,AVK_OTHER_APPLIB_AUTO)
{    
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_type=NULL;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	/*applib_mime_traverse*/
    mime_type = (applib_mime_type_struct *)applib_mime_traverse(NULL, MIME_SUBTYPE_AUDIO_MP3, vs_other_applib_mine_cb);
	AVK_LOG_FUN(applib_mime_traverse,(mime_type != NULL));
    if (mime_type != NULL)
    {
        AVK_CASE_RESULT(AVK_PASS);
    }else{
		AVK_CASE_RESULT(AVK_FAIL);
	}  
	
}

AVK_CASE(AVK_OTHER_APPLIB_QP,AVK_OTHER_APPLIB_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define VS_FW_QP_LEN    (64)
    
    kal_char str_src[VS_FW_QP_LEN]="MediaTek (Beijing) Inc";
    kal_char str_dest[VS_FW_QP_LEN];
    kal_uint8 opt=0;
    S32 reval, srclen, destlen, temp;
    applib_qprint_context cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srclen = strlen(str_src);
    destlen = VS_FW_QP_LEN;

    /*applib_qprint_part_encode_init*/
    reval = applib_qprint_part_encode_init(&cntx, 0, opt);
	AVK_LOG_FUN(applib_qprint_part_encode_init,(reval >= 0));

    /*applib_qprint_part_encode_append*/
    temp = srclen;
    reval = applib_qprint_part_encode_append(&cntx, str_src, &temp, str_dest, destlen);
	AVK_LOG_FUN(applib_qprint_part_encode_append,(reval > 0));
   
    /*applib_qprint_part_encode_finish*/
    reval = applib_qprint_part_encode_finish(&cntx, str_dest + reval, destlen - reval); 
	AVK_LOG_FUN(applib_qprint_part_encode_finish,(reval >= 0));   

    /*applib_qprint_encode_basic*/
    /*QPOPT_ENCODE_CRLF 0*/
    srclen = strlen(str_src);
    destlen = VS_FW_QP_LEN;
    memset(str_dest, 0, destlen);
    reval = applib_qprint_encode_basic(str_src, srclen, str_dest, destlen, opt);
	AVK_LOG_FUN(applib_qprint_encode_basic,(reval > 0));

    /*applib_qprint_part_decode_init*/
    reval = applib_qprint_part_decode_init(&cntx,0,opt);
	AVK_LOG_FUN(applib_qprint_part_decode_init,(reval >= 0));

    /*applib_qprint_part_decode_append*/
    temp = destlen;
    memset(str_src, 0, srclen);
    reval = applib_qprint_part_decode_append(&cntx,str_dest,&temp,str_src,srclen);
	AVK_LOG_FUN(applib_qprint_part_decode_append,(reval > 0) && (temp == strlen(str_dest)));

    /*applib_qprint_part_decode_finish*/
    reval = applib_qprint_part_decode_finish(&cntx,NULL);
	AVK_LOG_FUN(applib_qprint_part_decode_finish,(reval >= 0));

    /*applib_qprint_decode_basic*/
    memset(str_src, 0, srclen);
    destlen = strlen(str_dest);
    srclen = VS_FW_QP_LEN;
    reval = applib_qprint_decode_basic(str_dest, destlen, str_src, srclen, 0);
	AVK_LOG_FUN(applib_qprint_decode_basic,(reval > 0));
	
}

AVK_CASE(AVK_OTHER_APPLIB_UA,AVK_OTHER_APPLIB_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const S8* user_agent_string;
    char *ua_prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*applib_inet_get_user_agent_string*/
    user_agent_string = (const S8*)applib_inet_get_user_agent_string();
	AVK_LOG_FUN(applib_inet_get_user_agent_string,(user_agent_string!=NULL));
 
    /*mmi_em_inet_get_user_agent_profile*/
    ua_prof = (char*)applib_inet_get_user_agent_profile();
	AVK_LOG_FUN(applib_inet_get_user_agent_profile,(0==strcmp(ua_prof,"")));
	
}

AVK_CASE(AVK_OTHER_APPLIB_URL,AVK_OTHER_APPLIB_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define URL_LENGTH_OUTPUT (100)
    
    kal_char url_in[URL_LENGTH_OUTPUT]="sms%20send";
    kal_char url_out[URL_LENGTH_OUTPUT];
    kal_char special_chars_array[]=" #<>[]";
    S32 url_inlen, url_outlen, special_chars_array_len;

	kal_char url[]="http://172.27.42.125:8800/Send%20Text%20Message.htm";
    kal_char str_ip[]="127.0.0.1";
    applib_url_struct url_st;
    S32 reval=1, len_ip=0;
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*applib_url_is_valid*/
    reval=applib_url_is_valid(url);
	AVK_LOG_FUN(applib_url_is_valid,(0==reval));

    /*applib_url_is_valid_ext*/
    reval=applib_url_is_valid_ext(url, KAL_TRUE, KAL_FALSE);
	AVK_LOG_FUN(applib_url_is_valid_ext,(0==reval));

    /*applib_parse_url*/
    reval = applib_parse_url(url, &url_st);
	AVK_LOG_FUN(applib_parse_url,(0 == reval) && (applib_scheme_http == url_st.scheme_type));
    
    /*applib_url_check_scheme*/
    /* scheme        = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." ) */
    reval = applib_url_check_scheme(&url_st);
	AVK_LOG_FUN(applib_url_check_scheme,(0==reval));

    /*applib_url_check_host*/
    reval = applib_url_check_host(&url_st);
	AVK_LOG_FUN(applib_url_check_host,(0==reval));
    
    /*applib_url_check_port*/
    reval = applib_url_check_port(&url_st);
	AVK_LOG_FUN(applib_url_check_port,(0==reval));
    
    /*applib_url_check_ip*/
    len_ip=strlen(str_ip);
    reval = applib_url_check_ip(str_ip, len_ip);
	AVK_LOG_FUN(applib_url_check_ip,(1==reval));
    
    /*applib_cvt_escape_string_to_normal_string, applib_cvt_normal_string_to_escape_string*/   
    url_inlen=strlen(url_in);
    memset(url_out, 0, URL_LENGTH_OUTPUT);
    url_outlen=URL_LENGTH_OUTPUT;
    
    ret = applib_cvt_escape_string_to_normal_string(url_in, url_inlen, url_out, url_outlen); 
	AVK_LOG_FUN(applib_cvt_escape_string_to_normal_string,ret);

    special_chars_array_len=strlen(special_chars_array);
    memset(url_in, 0, URL_LENGTH_OUTPUT);
    url_outlen=strlen(url_out);
    url_inlen=URL_LENGTH_OUTPUT;
    ret = applib_cvt_normal_string_to_escape_string(url_out, url_outlen, special_chars_array, special_chars_array_len, url_in, url_inlen);   
    AVK_LOG_FUN(applib_cvt_normal_string_to_escape_string,ret);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_malloc
 * DESCRIPTION
 *  function to call OslMalloc
 * PARAMETERS
 *  size        [IN]        size to malloc
 * RETURNS
 *  address be malloced
 *****************************************************************************/
void* tst_other_applib_usedetail_malloc(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void* p;

    p = OslMalloc(size);
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_free
 * DESCRIPTION
 *  function to call OslMfree
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
void tst_other_applib_usedetail_free(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OslMfree(p);
    p = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_hilite_check_stop_func
 * DESCRIPTION
 *  function to check the condition of stop extract hilite item
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool tst_other_applib_usedetail_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == APPLIB_ADDR_TYPE_EMAIL && addr->length > MMI_EMAIL_MAX_ADDR_LEN * 2)
    {
        return KAL_FALSE;
    }
    if (type == APPLIB_ADDR_TYPE_URL && addr->length > MMI_MSG_MAX_ADDRESS_LEN * 2)
    {
        return KAL_FALSE;
    }
    if (num >= 2)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

AVK_CASE(AVK_OTHER_APPLIB_USEDETAILS,AVK_OTHER_APPLIB_AUTO)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret, is_stopped=KAL_FALSE;
	S32 str_len;
	kal_char str_email[64];
    kal_wchar wstr_email[64];
	kal_char str_input[128];
    kal_wchar wstr_input[128];

	applib_addr_type_enum enum_type=APPLIB_ADDR_TYPE_URL;
    applib_charset_enum enum_charset=APPLIB_INPUT_DATA_TYPE_ASCII;
    
    applib_address_node_struct *curr_url1=NULL;
    applib_address_node_struct *curr_url2=NULL;

	strcpy((char *) str_email, (const char *)"sasha42@163.com");
	strcpy((char*) str_input, (const char *)"web address is: http://www.google.com hello, mediatek, http://www.google.com, mediatek");
	mmi_wcscpy((WCHAR*) wstr_email, (const WCHAR*)L"sasha42@163.com");
	mmi_wcscpy((WCHAR*) wstr_input, (const WCHAR*)L"web address is: http://www.google.com hello, mediatek, http://www.google.com, mediatek");
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*applib_is_valid_email_address*/
    ret = applib_is_valid_email_address(str_email);
	AVK_LOG_FUN(applib_is_valid_email_address,ret);
    
    /*applib_is_valid_email_address_unicode*/
    ret = applib_is_valid_email_address_unicode(wstr_email);
	AVK_LOG_FUN(applib_is_valid_email_address_unicode,ret);

    /*applib_get_exclusive_address_list_from_text*/
    str_len=strlen(str_input);
    curr_url1 = applib_get_exclusive_address_list_from_text(
                                                enum_type,
                                                tst_other_applib_usedetail_malloc,
                                                tst_other_applib_usedetail_free,
                                                str_input,
                                                str_len);
	AVK_LOG_FUN(applib_get_exclusive_address_list_from_text,(curr_url1 != NULL) && (enum_type == curr_url1->dataType));

    /*applib_get_exclusive_address_list_from_text_ext*/ 
    str_len=strlen(str_input);
    curr_url2 = applib_get_exclusive_address_list_from_text_ext(
                                                enum_type,
                                                tst_other_applib_usedetail_malloc,
                                                tst_other_applib_usedetail_free,
                                                tst_other_applib_usedetail_check_stop_func,
                                                enum_charset,
                                                str_input,
                                                str_len,
                                                &is_stopped);
	AVK_LOG_FUN(applib_get_exclusive_address_list_from_text_ext,(curr_url2 != NULL) && (enum_type == curr_url2->dataType));

    /*applib_get_address_list_from_text*/
    str_len=strlen(str_input);
    curr_url1 = applib_get_address_list_from_text(
                                                enum_type,
                                                tst_other_applib_usedetail_malloc,
                                                tst_other_applib_usedetail_free,
                                                str_input,
                                                str_len);
	AVK_LOG_FUN(applib_get_address_list_from_text,(curr_url1 != NULL) && (enum_type == curr_url1->dataType));
    
    /*applib_get_address_list_from_text_ext*/
    is_stopped=KAL_FALSE;
    enum_charset=APPLIB_INPUT_DATA_TYPE_UNICODE;
    str_len=mmi_wcslen(wstr_input)*2;
    curr_url2 = applib_get_address_list_from_text_ext(
                                                enum_type,
                                                tst_other_applib_usedetail_malloc,
                                                tst_other_applib_usedetail_free,
                                                tst_other_applib_usedetail_check_stop_func,
                                                enum_charset,
                                                (char *)wstr_input,
                                                str_len,
                                                &is_stopped);//revised 6th parameter
	AVK_LOG_FUN(applib_get_address_list_from_text_ext,(curr_url2 != NULL) && (enum_type == curr_url2->dataType));
	
    
    /*applib_concatenate_address_list*/
    curr_url1=applib_concatenate_address_list(curr_url1,curr_url2);
	AVK_LOG_FUN(applib_concatenate_address_list,(curr_url1 != NULL) && (enum_type == curr_url2->dataType));
    
    /*applib_remove_duplicate_address*/
    applib_remove_duplicate_address(&curr_url1,tst_other_applib_usedetail_free);
	AVK_LOG_FUN(applib_remove_duplicate_address,(curr_url1 != NULL) && (curr_url1->next->next == NULL));
    
    /*applib_remove_duplicate_unicode_address*/
    applib_remove_duplicate_unicode_address(&curr_url2,tst_other_applib_usedetail_free);
	AVK_LOG_FUN(applib_remove_duplicate_unicode_address,(curr_url2 != NULL) && (curr_url2->next == NULL));

	/*applib_free_address_list*/
    ret=applib_free_address_list(&curr_url1,tst_other_applib_usedetail_free);
	AVK_LOG_FUN(applib_free_address_list,ret);

}




