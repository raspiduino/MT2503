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

extern "C"
{
#include "kal_general_types.h"
#include "Conversions.h"
#include "Unicodexdcl.h"
#if defined(PLUTO_MMI)
#include "mmi_rp_srv_mmi_charset_def.h"
#endif

}
#if defined(__MMI_CHSET_BIG5__) || defined(__MMI_CHSET_GB2312__) || defined(__MMI_CHSET_HKSCS__)
#define __MMI_CHSET_IDEOGRAM_SUPPORT__
#endif 
#define AVK_PLUTO_CHSET_LEN  128
static MMI_BOOL avk_pluto_chset_is_encoding_valid(mmi_chset_enum encoding);


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_chset_get_encoding
 * DESCRIPTION
 *  test encoding related APIs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_chset_get_encoding()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_chset_enum def_enc = MMI_CHSET_BASE, chset_list[MMI_CHSET_TOTAL];
    MMI_BOOL valid_encoding = MMI_FALSE, is_enabled = MMI_FALSE;
    kal_int32 chset_size = 0;
    const kal_int8 *mime_name = NULL;
#if defined(PLUTO_MMI)
    mmi_chset_enum def_eng = MMI_CHSET_BASE;
    kal_int32 chset_enable = -100;
#if defined(__MMI_SET_DEF_ENCODING_TYPE__) 
    kal_int32 chset_lang = 0;
#endif

#ifndef __COSMOS_MMI_PACKAGE__
    kal_uint16 chset_string = 100;
#endif

#endif //#if defined(PLUTO_MMI)

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set encoding by name */
#ifdef __MMI_CHSET_GB2312__
    valid_encoding = mmi_chset_set_default_encoding_type((const kal_int8*)"GB2312");
#else
    valid_encoding = mmi_chset_set_default_encoding_type((const kal_int8*)"UTF-8");
#endif

    if (valid_encoding)
    {
        AVK_LOG_FUN(mmi_chset_set_default_encoding_type, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_set_default_encoding_type, AVK_FAIL);

    }
    /* check for valid encoding */
    valid_encoding = MMI_FALSE;
    def_enc = mmi_chset_get_default_encoding_type();
    valid_encoding = avk_pluto_chset_is_encoding_valid(def_enc);

    if (valid_encoding)
    {
        AVK_LOG_FUN(avk_pluto_chset_is_encoding_valid, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(avk_pluto_chset_is_encoding_valid, AVK_FAIL);

    }

    /* set encoding by ID */
    valid_encoding = MMI_FALSE;
    valid_encoding = mmi_chset_set_default_encoding_type_by_id(def_enc);

    if (valid_encoding)
    {
        AVK_LOG_FUN(mmi_chset_set_default_encoding_type_by_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_set_default_encoding_type_by_id, AVK_FAIL);

    }

#if defined(PLUTO_MMI)
    /* Get enabled chset list */
    chset_enable = mmi_chset_get_enabled_chset_list(chset_list);

    if (chset_enable > 0)
    {
        AVK_LOG_FUN(mmi_chset_get_enabled_chset_list, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_get_enabled_chset_list, AVK_FAIL);

    }
#endif //#if defined(PLUTO_MMI)

    /* Check if chset is enabled */
    is_enabled = mmi_chset_is_enabled(MMI_CHSET_ASCII);

    if (is_enabled)
    {
        AVK_LOG_FUN(mmi_chset_is_enabled, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_is_enabled, AVK_FAIL);

    }
    
#if defined(PLUTO_MMI)
    /* get default english chset */
    def_eng = mmi_chset_get_english_default_chset();

    if (def_eng)
    {
        AVK_LOG_FUN(mmi_chset_get_english_default_chset, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_get_english_default_chset, AVK_FAIL);

    }

#ifndef __COSMOS_MMI_PACKAGE__
    /* Get chset string */
    chset_string = mmi_chset_get_chset_string(MMI_CHSET_ASCII);

    if (chset_string == STR_DEF_ENCODING_TYPE_ASCII)
    {
        AVK_LOG_FUN(mmi_chset_get_chset_string, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_get_chset_string, AVK_FAIL);

    }
#endif //#ifndef __COSMOS_MMI_PACKAGE__

#if defined(__MMI_SET_DEF_ENCODING_TYPE__)
    /* Get chset list by language */
    chset_lang = mmi_chset_get_chset_list_by_language(chset_list, &def_eng);

    if (chset_lang)
    {
        AVK_LOG_FUN(mmi_chset_get_chset_list_by_language, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_get_chset_list_by_language, AVK_FAIL);

    }
#endif //#if defined(__MMI_SET_DEF_ENCODING_TYPE__)
#endif //#if defined(PLUTO_MMI)

    /* Get preferred mime name */
    mime_name = chset_get_preferred_mime_name(MMI_CHSET_ASCII);

    if (mime_name == NULL)
    {
        AVK_LOG_FUN(chset_get_preferred_mime_name, AVK_FAIL);

    }
    else
    {
        AVK_LOG_FUN(chset_get_preferred_mime_name, AVK_PASS);
    }

    /* Get char size of charset */
    chset_size = mmi_chset_get_char_size_of_charset(MMI_CHSET_ASCII);

    if (chset_size > 0)
    {
        AVK_LOG_FUN(mmi_chset_get_char_size_of_charset, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_get_char_size_of_charset, AVK_FAIL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_chset_is_encoding_valid
 * DESCRIPTION
 *  check if the encoding is valid or not
 * PARAMETERS
 *  encoding        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL avk_pluto_chset_is_encoding_valid(mmi_chset_enum encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_chset_enum encoding_set[] = {CHSET_ASCII,
        MMI_CHSET_ASCII,
        CHSET_ARABIC_ISO,
        MMI_CHSET_ARABIC_ISO,
        CHSET_ARABIC_WIN,
        MMI_CHSET_ARABIC_WIN,
        CHSET_PERSIAN_CP1097,
        MMI_CHSET_PERSIAN_CP1097,
        CHSET_PERSIAN_CP1098,
        MMI_CHSET_PERSIAN_CP1098,
        CHSET_BALTIC_ISO,
        MMI_CHSET_BALTIC_ISO,
        CHSET_BALTIC_WIN,
        MMI_CHSET_BALTIC_WIN,
        CHSET_CEURO_ISO,
        MMI_CHSET_CEURO_ISO,
        CHSET_CEURO_WIN,
        MMI_CHSET_CEURO_WIN,
        CHSET_CYRILLIC_ISO,
        MMI_CHSET_CYRILLIC_ISO,
        CHSET_CYRILLIC_WIN,
        MMI_CHSET_CYRILLIC_WIN,
        CHSET_GREEK_ISO,
        MMI_CHSET_GREEK_ISO,
        CHSET_GREEK_WIN,
        MMI_CHSET_GREEK_WIN,
        CHSET_HEBREW_ISO,
        MMI_CHSET_HEBREW_ISO,
        CHSET_HEBREW_WIN,
        MMI_CHSET_HEBREW_WIN,
        CHSET_LATIN_ISO,
        MMI_CHSET_LATIN_ISO,
        CHSET_NORDIC_ISO,
        MMI_CHSET_NORDIC_ISO,
        CHSET_SEURO_ISO,
        MMI_CHSET_SEURO_ISO,
        CHSET_TURKISH_ISO,
        MMI_CHSET_TURKISH_ISO,
        CHSET_TURKISH_WIN,
        MMI_CHSET_TURKISH_WIN,
        CHSET_WESTERN_ISO,
        MMI_CHSET_WESTERN_ISO,
        CHSET_ARMENIAN_ISO,
        MMI_CHSET_ARMENIAN_ISO,
        CHSET_THAI_WIN,
        MMI_CHSET_THAI_WIN,
        CHSET_VIETNAMESE_WIN,
        MMI_CHSET_VIETNAMESE_WIN,
        CHSET_KOI8_R,
        MMI_CHSET_KOI8_R,
        CHSET_TIS_620,
        MMI_CHSET_TIS_620,
        CHSET_WESTERN_WIN,
        MMI_CHSET_WESTERN_WIN,
        CHSET_BIG5,
        MMI_CHSET_BIG5,
        CHSET_GB2312,
        MMI_CHSET_GB2312,
        CHSET_HKSCS,
        MMI_CHSET_HKSCS,
        CHSET_SJIS,
        MMI_CHSET_SJIS,
        CHSET_GB18030,
        MMI_CHSET_GB18030,
        CHSET_UTF7,
        MMI_CHSET_UTF7,
        CHSET_EUCKR,
        MMI_CHSET_EUCKR,
        CHSET_UTF16LE,
        MMI_CHSET_UTF16LE,
        CHSET_UTF16BE,
        MMI_CHSET_UTF16BE,
        CHSET_UTF8,
        MMI_CHSET_UTF8,
        CHSET_UCS2,
        MMI_CHSET_UCS2
    };
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CHSET_TOTAL * 2; i++)
    {
        if (encoding == encoding_set[i])
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_chset_conversions_01
 * DESCRIPTION
 *  converts from onw format to another
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_chset_conversions_01()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    S32 str_len = 0;
    kal_int16 ucs_to_char = 0, char_to_ucs = 0;
    UI_character_type ucs_buf[AVK_PLUTO_CHSET_LEN * 2], char_buf[AVK_PLUTO_CHSET_LEN];
    kal_uint8 is_text = 0;
#endif
    kal_uint32 src_end_pos = 0, ret = 0;    
    U16 des_buf[AVK_PLUTO_CHSET_LEN];        
    char src_utf8[] = "mediaTek";
    //char src_utf16[] = {0xFF, 0xFE, 0x54, 0x80, 0xD1, 0x53, 0xD1, 0x79, 0x80, 0x62, 0x00, 0x00};      /* 联发科技 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_IDEOGRAM_SUPPORT__
    memset(ucs_buf, 0, AVK_PLUTO_CHSET_LEN * 2);
    memset(char_buf, 0, AVK_PLUTO_CHSET_LEN);

    mmi_ucs2cpy((char*)ucs_buf, (const char*)L"mediatek");
    str_len = mmi_ucs2strlen((char*)ucs_buf);

    /* UCS to text */
    ucs_to_char = mmi_chset_ucs2_to_text_str((kal_uint8*)char_buf, AVK_PLUTO_CHSET_LEN, (kal_uint8*)ucs_buf, GB2312_ENCODING_TYPE);

    if ((str_len + 1) == ucs_to_char)
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_text_str, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_text_str, AVK_FAIL);

    }

    ucs_to_char = mmi_chset_ucs2_to_text_str_ex(
                    (kal_uint8*) char_buf,
                    AVK_PLUTO_CHSET_LEN,
                    (kal_uint8*)ucs_buf,
                    GB2312_ENCODING_TYPE,
                    &src_end_pos);

    if (((str_len + 1) == ucs_to_char) && (src_end_pos > 0))
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_text_str_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_text_str_ex, AVK_FAIL);

    }

    /* text to UCS */
    memset(ucs_buf, 0, AVK_PLUTO_CHSET_LEN * 2);
    char_to_ucs = mmi_chset_text_to_ucs2_str(
                    (kal_uint8*) ucs_buf,
                    AVK_PLUTO_CHSET_LEN * 2,
                    (kal_uint8*) char_buf,
                    GB2312_ENCODING_TYPE);
    char_to_ucs = mmi_ucs2cmp((char*)ucs_buf, (const char*)L"mediatek");

    if (!char_to_ucs)
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2_str, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2_str, AVK_FAIL);

    }
    /* set UCS buffer again */
    memset(ucs_buf, 0, AVK_PLUTO_CHSET_LEN * 2);
    src_end_pos = 0;
    char_to_ucs = mmi_chset_text_to_ucs2_str_ex(
                    (kal_uint8*) ucs_buf,
                    AVK_PLUTO_CHSET_LEN * 2,
                    (kal_uint8*) char_buf,
                    GB2312_ENCODING_TYPE,
                    &src_end_pos);
    char_to_ucs = mmi_ucs2cmp((char*)ucs_buf, (const char*)L"mediatek");

    if (!char_to_ucs)
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2_str_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2_str_ex, AVK_FAIL);

    }

    /* is text in str */
    is_text = mmi_chset_is_text_in_str((kal_uint8*)char_buf);

    if (is_text > 0)
    {
        AVK_LOG_FUN(mmi_chset_is_text_in_str, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_is_text_in_str, AVK_FAIL);

    }
#endif /* __MMI_CHSET_IDEOGRAM_SUPPORT__ */ 
    /* charset convert */
    ret = mmi_chset_convert(
            MMI_CHSET_UTF8,     /* src_type */
            MMI_CHSET_UCS2,     /* dest_type */
            (char*)src_utf8,    /* src_buff */
            (char*)des_buf,     /* dest_buff */
            AVK_PLUTO_CHSET_LEN);

    if (ret > 0)
    {
        AVK_LOG_FUN(mmi_chset_convert, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_convert, AVK_FAIL);

    }

    /* charset convert ex */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    src_end_pos = 0;
    ret = mmi_chset_convert_ex(
            MMI_CHSET_UTF8,     /* src_type */
            MMI_CHSET_UCS2,     /* dest_type */
            (char*)src_utf8,    /* src_buff */
            (char*)des_buf,     /* dest_buff */
            AVK_PLUTO_CHSET_LEN,
            &src_end_pos);

    if (ret > 0)
    {
        AVK_LOG_FUN(mmi_chset_convert_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_convert_ex, AVK_FAIL);

    }

    /* Chset convert */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    ret = 0;
    ret = chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)src_utf8, (char*)des_buf, AVK_PLUTO_CHSET_LEN);

    if (ret > 0)
    {
        AVK_LOG_FUN(chset_convert, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(chset_convert, AVK_FAIL);

    }

    /* Chset convert ex */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    src_end_pos = 0;
    ret = 0;
    ret = chset_convert_ex(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)src_utf8,
            (char*)des_buf,
            AVK_PLUTO_CHSET_LEN,
            &src_end_pos);

    if (ret > 0)
    {
        AVK_LOG_FUN(chset_convert_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(chset_convert_ex, AVK_FAIL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_chset_conversions_02
 * DESCRIPTION
 *  converts from onw format to another
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_chset_conversions_02()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_GB18030__
    kal_uint32 conv_res = 0;
    char gb18030_buff[] = {0x54, 0x80, 0xD1, 0x53, 0xD1, 0x79, 0x80, 0x62, 0x00, 0x00};      /* 联发科技 */
#endif
    kal_uint32 src_end_pos = 0;
    U16 des_buf[AVK_PLUTO_CHSET_LEN];
    kal_uint16 res = 0;
    U16 ucs2_buff[9 * ENCODING_LENGTH];
    char src_utf8[] = "mediatek";
    WCHAR uni = L'A';
    kal_uint16 dst_ch = 0, src_ch = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CHSET_GB18030__
    conv_res = mmi_chset_convert_with_src_length(
                MMI_CHSET_GB18030,
                MMI_CHSET_UCS2,
                gb18030_buff,
                AVK_PLUTO_CHSET_LEN,
                (char *)des_buf,               
                AVK_PLUTO_CHSET_LEN);

    if (conv_res > 0)
    {
        AVK_LOG_FUN(mmi_chset_convert_with_src_length, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_convert_with_src_length, AVK_FAIL);

    }
#endif /* __MMI_CHSET_GB18030__ */ 

    /* UCS2 to wchar */
    res = UCS2_TO_WCHAR(uni);
    if (res > 0)
    {
        AVK_LOG_FUN(UCS2_TO_WCHAR, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(UCS2_TO_WCHAR, AVK_FAIL);

    }

    /* mixed test to UCS2 */
    memset(ucs2_buff, 0, 9 * ENCODING_LENGTH);
    mmi_chset_mixed_text_to_ucs2_str((U8*) ucs2_buff, 9 * ENCODING_LENGTH, (U8*) src_utf8, MMI_CHSET_ASCII);

    if (!mmi_ucs2cmp((char*)ucs2_buff, (const char*)L"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_mixed_text_to_ucs2_str, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_mixed_text_to_ucs2_str, AVK_FAIL);

    }

    /* mixed test to UCS2 ex */
    memset(ucs2_buff, 0, 9 * ENCODING_LENGTH);
    mmi_chset_mixed_text_to_ucs2_str_ex(
        (U8*) ucs2_buff,
        9 * ENCODING_LENGTH,
        (U8*) src_utf8,
        MMI_CHSET_ASCII,
        &src_end_pos);

    if (!mmi_ucs2cmp((char*)ucs2_buff, (const char*)L"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_mixed_text_to_ucs2_str_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_mixed_text_to_ucs2_str_ex, AVK_FAIL);

    }

    /* text to UCS2 */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    res = 0;
    res = mmi_chset_text_to_ucs2((kal_uint8*) des_buf, AVK_PLUTO_CHSET_LEN, (kal_uint8*) src_utf8);

    if ((res == 18) && (!mmi_ucs2cmp((char*)des_buf, (const char*)L"mediatek")))
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2, AVK_FAIL);

    }

    /* text to UCS2 ex */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    res = 0;
    src_end_pos = 0;
    res = mmi_chset_text_to_ucs2_ex((kal_uint8*) des_buf, AVK_PLUTO_CHSET_LEN, (kal_uint8*) src_utf8, &src_end_pos);

    if ((res == 18) && (!mmi_ucs2cmp((char*)des_buf, (const char*)L"mediatek")))
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_text_to_ucs2_ex, AVK_FAIL);

    }

    /* UTF8 to UCS2 */
    res = 0;
    src_ch = src_utf8[0];
    res = mmi_chset_utf8_to_ucs2((kal_uint8*) & dst_ch, (kal_uint8*) & src_ch);

    if (dst_ch == src_ch)
    {
        AVK_LOG_FUN(mmi_chset_utf8_to_ucs2, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_utf8_to_ucs2, AVK_FAIL);

    }

    /* UCS2 to UTF8 */
    res = 0;
    src_ch = 0;
    res = mmi_chset_ucs2_to_utf8((kal_uint8*) & src_ch, dst_ch);
    if (src_ch == dst_ch)
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf8, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf8, AVK_FAIL);

    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_chset_conversions_03
 * DESCRIPTION
 *  converts from onw format to another
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_chset_conversions_03()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret = 0, src_end_pos = 0;
    U16 des_buf[AVK_PLUTO_CHSET_LEN];
    kal_uint8 src_utf8[] = "mediatek";
    kal_uint8 utf8_buf[AVK_PLUTO_CHSET_LEN];
    U16 ch = L'A';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* UTF8 to UCS2 string */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    ret = mmi_chset_utf8_to_ucs2_string((kal_uint8*) des_buf, AVK_PLUTO_CHSET_LEN, src_utf8);

    if (!mmi_ucs2cmp((char*)des_buf, (const char*)L"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_utf8_to_ucs2_string, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_utf8_to_ucs2_string, AVK_FAIL);

    }

    /* UTF8 to UCS2 string ex */
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    ret = mmi_chset_utf8_to_ucs2_string_ex((kal_uint8*) des_buf, AVK_PLUTO_CHSET_LEN, src_utf8, &src_end_pos);

    if (!mmi_ucs2cmp((char*)des_buf, (const char*)L"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_utf8_to_ucs2_string_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_utf8_to_ucs2_string_ex, AVK_FAIL);

    }

    /* UCS2 to UTF8 string */
    ret = 0;
    memset(utf8_buf, 0, AVK_PLUTO_CHSET_LEN);

    ret = mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_buf, AVK_PLUTO_CHSET_LEN, (kal_uint8*) des_buf);

    if (!mmi_ucs2cmp((char*)utf8_buf, (const char*)"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf8_string, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf8_string, AVK_FAIL);

    }

    /* UCS2 to UTF8 string ex */
    ret = 0;
    src_end_pos = 0;
    memset(utf8_buf, 0, AVK_PLUTO_CHSET_LEN);

    ret = mmi_chset_ucs2_to_utf8_string_ex(
            (kal_uint8*) utf8_buf,
            AVK_PLUTO_CHSET_LEN,
            (kal_uint8*) des_buf,
            &src_end_pos);

    if (!mmi_ucs2cmp((char*)utf8_buf, (const char*)"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf8_string_ex, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf8_string_ex, AVK_FAIL);

    }

    /* wchar to ucs2 */
    ret = 0;
    ret = mmi_chset_wchar_to_ucs2(ch, GB2312_ENCODING_TYPE);

    if (!ret)
    {
        AVK_LOG_FUN(mmi_chset_wchar_to_ucs2, AVK_FAIL);

    }
    else
    {
        AVK_LOG_FUN(mmi_chset_wchar_to_ucs2, AVK_PASS);
    }

    /* ucs2 to wchar */
    ret = 0;
    ret = mmi_chset_ucs2_to_wchar(ch, GB2312_ENCODING_TYPE);

    if (!ret)
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_wchar, AVK_FAIL);

    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_wchar, AVK_PASS);
    }

    /* Encoding Decoding */
    ret = 0;
    src_end_pos = 0;
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    ret = EncodingDecoding(UTF8_TO_UCS2, (char*)des_buf, (char*)src_utf8, AVK_PLUTO_CHSET_LEN, &src_end_pos);

    if (!mmi_ucs2cmp((char*)des_buf, (const char*)L"mediatek"))
    {
        AVK_LOG_FUN(EncodingDecoding, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(EncodingDecoding, AVK_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_chset_conversions_04
 * DESCRIPTION
 *  converts from onw format to another
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_chset_conversions_04()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len = 0;
    kal_uint32 src_end_pos = 0;
    mmi_chset_enum byte_order;
    WCHAR src_utf16[20];
    U16 des_buf[AVK_PLUTO_CHSET_LEN];

#ifdef __MMI_CHSET_SJIS__
    U16 ucs2_buf[AVK_PLUTO_CHSET_LEN];
    kal_uint32 ret;
#endif 
    kal_uint8 src_utf8[] = "mediatek";
    char src_utf16str[] = {0xFF, 0xFE, 0x54, 0x80, 0xD1, 0x53, 0xD1, 0x79, 0x80, 0x62, 0x00, 0x00};      /* 联发科技 */
    mmi_chset_enum charset;
    MMI_BOOL id_get = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(src_utf16, (const WCHAR*)L"mediatek");

    /* Get the string length */
    len = mmi_chset_utf8_strlen(src_utf8);

    if (len == 8)
    {
        AVK_LOG_FUN(mmi_chset_utf8_strlen, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_utf8_strlen, AVK_FAIL);

    }

    /* Get byte order */
    byte_order = (mmi_chset_enum) mmi_chset_get_utf_byte_order((const kal_int8*)src_utf16str);

    switch (byte_order)
    {
        case MMI_CHSET_UTF16LE:
        case MMI_CHSET_UTF16BE:
        case MMI_CHSET_UTF8:
        	  AVK_LOG_FUN(mmi_chset_get_utf_byte_order, AVK_PASS);
        	  break;
        case -1:
            AVK_LOG_FUN(mmi_chset_get_utf_byte_order, AVK_FAIL);
            break;
    }

    /* Get utf16 string length */
    len = 0;
    len = mmi_chset_utf16_strlen((kal_int8*) src_utf16, MMI_CHSET_UTF16LE);
    if (len == 8)
    {
        AVK_LOG_FUN(mmi_chset_utf16_strlen, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_utf16_strlen, AVK_FAIL);

    }

    /* UCS2 to UTF16 */
    len = 0;
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    len = mmi_chset_ucs2_to_utf16_bom_str(
            (kal_uint8*) des_buf,
            21,
            MMI_CHSET_UTF16LE,
            (kal_uint8*) src_utf16,
            &src_end_pos);

    if (!mmi_ucs2cmp((char*)(des_buf + 1), (const char*)L"mediatek"))
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf16_bom_str, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_utf16_bom_str, AVK_FAIL);

    }

    charset = mmi_chset_guess((char*)src_utf16, AVK_PLUTO_CHSET_LEN, (mmi_chset_enum) 0, CHSET_GUESS_ALL);

    if (avk_pluto_chset_is_encoding_valid(charset))
    {
        AVK_LOG_FUN(mmi_chset_guess, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_guess, AVK_FAIL);

    }

#ifdef __MMI_CHSET_SJIS__
    /* UCS2 to SJIS */

    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    ret = 0;
    src_end_pos = 0;
    ret = mmi_chset_ucs2_to_sjis((kal_uint8*)des_buf, AVK_PLUTO_CHSET_LEN, (kal_uint8*)src_utf16, &src_end_pos);
    if (ret > 0)
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_sjis, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_ucs2_to_sjis, AVK_FAIL);

    }

    /* SJIS to UCS2 */
    ret = 0;
    src_end_pos = 0;
    memset(des_buf, 0, AVK_PLUTO_CHSET_LEN);
    ret = mmi_chset_sjis_to_ucs2((kal_uint8*)ucs2_buf, AVK_PLUTO_CHSET_LEN, (kal_uint8*)des_buf, &src_end_pos);

    if (ret > 0)
    {
        AVK_LOG_FUN(mmi_chset_sjis_to_ucs2, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_sjis_to_ucs2, AVK_FAIL);

    }
#endif /* __MMI_CHSET_SJIS__ */ 

    /* Get charset ID */
    charset = MMI_CHSET_BASE;
#ifdef __MMI_CHSET_GB2312__
    id_get = chset_get_charset_id((const kal_int8*)"GB2312", &charset);

    if (id_get && (charset == MMI_CHSET_GB2312))
#else
    id_get = chset_get_charset_id((const kal_int8*)"ISO-10646-UCS-2", &charset);

    if (id_get && (charset == MMI_CHSET_UCS2))
#endif
    {
        AVK_LOG_FUN(chset_get_charset_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(chset_get_charset_id, AVK_FAIL);

    }

    /* mmi charset ID */
    charset = MMI_CHSET_BASE;
#ifdef __MMI_CHSET_GB2312__
    id_get = mmi_chset_get_charset_id((const kal_int8*)"GB2312", &charset);

    if (id_get && (charset == MMI_CHSET_GB2312))
#else
    id_get = mmi_chset_get_charset_id((const kal_int8*)"ISO-10646-UCS-2", &charset);

    if (id_get && (charset == MMI_CHSET_UCS2))
#endif
    {
        AVK_LOG_FUN(mmi_chset_get_charset_id, AVK_PASS);
    }
    else
    {
        AVK_LOG_FUN(mmi_chset_get_charset_id, AVK_FAIL);

    }
}

AVK_CASE(AVK_PLUTO_CSET_CASE1,AVK_PLUTO_CSET)
{
	avk_pluto_chset_get_encoding();
}
AVK_CASE(AVK_PLUTO_CSET_CASE2,AVK_PLUTO_CSET)
{
    avk_pluto_chset_conversions_01();
}
AVK_CASE(AVK_PLUTO_CSET_CASE3,AVK_PLUTO_CSET)
{
    avk_pluto_chset_conversions_02();
}
AVK_CASE(AVK_PLUTO_CSET_CASE4,AVK_PLUTO_CSET)
{
    avk_pluto_chset_conversions_03();
}
AVK_CASE(AVK_PLUTO_CSET_CASE5,AVK_PLUTO_CSET)
{
    avk_pluto_chset_conversions_04();
}

