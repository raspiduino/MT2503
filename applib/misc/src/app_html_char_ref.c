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
 * app_html_char_ref.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is intended for HTML character reference convert operations.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "stdio.h"
#include "wchar.h"
#include "string.h"
#include "kal_general_types.h"
#include "app_html.h"

/***************************************************************************** 
 * Constant
 *****************************************************************************/
/* length of "&thetasym;" */
#define APPLIB_HTML_CHAR_REF_MAX_CHAR_ENTITY_LEN    10
#define APPLIB_HTML_CHAR_REF_MIN_CHAR_ENTITY_LEN    4

#define APPLIB_HTML_CHAR_REF_INVALID_UNICODE_128    128
#define APPLIB_HTML_CHAR_REF_INVALID_UNICODE_159    159

#define APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF       0xFFFF

/***************************************************************************** 
 * Macro
 *****************************************************************************/
#define APPLIB_HTML_CHAR_REF_ISLOWER(c)     ((c) >= 'a' && (c) <= 'z')
#define APPLIB_HTML_CHAR_REF_ISDIGIT(c)     ((c) >= '0' && (c) <= '9')
#define APPLIB_HTML_CHAR_REF_ISHEX(c)       (((c) >= '0' && (c) <= '9') || ((c) >= 'a' && (c) <= 'f') || ((c) >= 'A' && (c) <= 'F'))
#define APPLIB_HTML_CHAR_REF_TOLOWER(c)     (((c) >= 'A' && (c) <= 'Z') ? ((c) | 0x20) : (c))

/***************************************************************************** 
 * Enum
 *****************************************************************************/

/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct {
    const kal_char  *name;   
    kal_int32       value;  
} applib_html_char_ref_strtable_entry_t;

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static const applib_html_char_ref_strtable_entry_t applib_html_char_ref_entities_strtable[] = {
/* Character entity references for ISO 8859-1 characters */
    {"nbsp",     0x00A0},
    {"iexcl",    0x00A1},
    {"cent",     0x00A2},
    {"pound",    0x00A3},
    {"curren",   0x00A4},
    {"yen",      0x00A5},
    {"brvbar",   0x00A6},
    {"sect",     0x00A7},
    {"uml",      0x00A8},
    {"copy",     0x00A9},
    {"ordf",     0x00AA},
    {"laquo",    0x00AB},
    {"not",      0x00AC},
    {"shy",      0x00AD},
    {"reg",      0x00AE},
    {"macr",     0x00AF},
    {"deg",      0x00B0},
    {"plusmn",   0x00B1},
    {"sup2",     0x00B2},
    {"sup3",     0x00B3},
    {"acute",    0x00B4},
    {"micro",    0x00B5},
    {"para",     0x00B6},
    {"middot",   0x00B7},
    {"cedil",    0x00B8},
    {"sup1",     0x00B9},
    {"ordm",     0x00BA},
    {"raquo",    0x00BB},
    {"frac14",   0x00BC},
    {"frac12",   0x00BD},
    {"frac34",   0x00BE},
    {"iquest",   0x00BF},
    {"Agrave",   0x00C0},
    {"Aacute",   0x00C1},
    {"Acirc",    0x00C2},
    {"Atilde",   0x00C3},
    {"Auml",     0x00C4},
    {"Aring",    0x00C5},
    {"AElig",    0x00C6},
    {"Ccedil",   0x00C7},
    {"Egrave",   0x00C8},
    {"Eacute",   0x00C9},
    {"Ecirc",    0x00CA},
    {"Euml",     0x00CB},
    {"Igrave",   0x00CC},
    {"Iacute",   0x00CD},
    {"Icirc",    0x00CE},
    {"Iuml",     0x00CF},
    {"ETH",      0x00D0},
    {"Ntilde",   0x00D1},
    {"Ograve",   0x00D2},
    {"Oacute",   0x00D3},
    {"Ocirc",    0x00D4},
    {"Otilde",   0x00D5},
    {"Ouml",     0x00D6},
    {"times",    0x00D7},
    {"Oslash",   0x00D8},
    {"Ugrave",   0x00D9},
    {"Uacute",   0x00DA},
    {"Ucirc",    0x00DB},
    {"Uuml",     0x00DC},
    {"Yacute",   0x00DD},
    {"THORN",    0x00DE},
    {"szlig",    0x00DF},
    {"agrave",   0x00E0},
    {"aacute",   0x00E1},
    {"acirc",    0x00E2},
    {"atilde",   0x00E3},
    {"auml",     0x00E4},
    {"aring",    0x00E5},
    {"aelig",    0x00E6},
    {"ccedil",   0x00E7},
    {"egrave",   0x00E8},
    {"eacute",   0x00E9},
    {"ecirc",    0x00EA},
    {"euml",     0x00EB},
    {"igrave",   0x00EC},
    {"iacute",   0x00ED},
    {"icirc",    0x00EE},
    {"iuml",     0x00EF},
    {"eth",      0x00F0},
    {"ntilde",   0x00F1},
    {"ograve",   0x00F2},
    {"oacute",   0x00F3},
    {"ocirc",    0x00F4},
    {"otilde",   0x00F5},
    {"ouml",     0x00F6},
    {"divide",   0x00F7},
    {"oslash",   0x00F8},
    {"ugrave",   0x00F9},
    {"uacute",   0x00FA},
    {"ucirc",    0x00FB},
    {"uuml",     0x00FC},
    {"yacute",   0x00FD},
    {"thorn",    0x00FE},
    {"yuml",     0x00FF},

/* Character entity references for markup-significant and internationalization characters */
    {"quot",     0x0022},
    {"amp",      0x0026},
    {"lt",       0x003C},
    {"gt",       0x003E},
    {"apos",     0x0027},
    {"OElig",    0x0152},
    {"oelig",    0x0153},
    {"Scaron",   0x0160},
    {"scaron",   0x0161},
    {"Yuml",     0x0178},
    {"circ",     0x02C6},
    {"tilde",    0x02DC},
    {"ensp",     0x2002},
    {"emsp",     0x2003},
    {"thinsp",   0x2009},
    {"zwnj",     0x200C},
    {"zwj",      0x200D},
    {"lrm",      0x200E},
    {"rlm",      0x200F},
    {"ndash",    0x2013},
    {"mdash",    0x2014},
    {"lsquo",    0x2018},
    {"rsquo",    0x2019},
    {"sbquo",    0x201A},
    {"ldquo",    0x201C},
    {"rdquo",    0x201D},
    {"bdquo",    0x201E},
    {"dagger",   0x2020},
    {"Dagger",   0x2021},
    {"permil",   0x2030},
    {"lsaquo",   0x2039},
    {"rsaquo",   0x203A},
    {"euro",     0x20AC},

/* Character entity references for symbols, mathematical symbols, and Greek letters */
    {"fnof",     0x0192},
    {"Alpha",    0x0391},
    {"Beta",     0x0392},
    {"Gamma",    0x0393},
    {"Delta",    0x0394},
    {"Epsilon",  0x0395},
    {"Zeta",     0x0396},
    {"Eta",      0x0397},
    {"Theta",    0x0398},
    {"Iota",     0x0399},
    {"Kappa",    0x039A},
    {"Lambda",   0x039B},
    {"Mu",       0x039C},
    {"Nu",       0x039D},
    {"Xi",       0x039E},
    {"Omicron",  0x039F},
    {"Pi",       0x03A0},
    {"Rho",      0x03A1},
    {"Sigma",    0x03A3},
    {"Tau",      0x03A4},
    {"Upsilon",  0x03A5},
    {"Phi",      0x03A6},
    {"Chi",      0x03A7},
    {"Psi",      0x03A8},
    {"Omega",    0x03A9},
    {"alpha",    0x03B1},
    {"beta",     0x03B2},
    {"gamma",    0x03B3},
    {"delta",    0x03B4},
    {"epsilon",  0x03B5},
    {"zeta",     0x03B6},
    {"eta",      0x03B7},
    {"theta",    0x03B8},
    {"iota",     0x03B9},
    {"kappa",    0x03BA},
    {"lambda",   0x03BB},
    {"mu",       0x03BC},
    {"nu",       0x03BD},
    {"xi",       0x03BE},
    {"omicron",  0x03BF},
    {"pi",       0x03C0},
    {"rho",      0x03C1},
    {"sigmaf",   0x03C2},
    {"sigma",    0x03C3},
    {"tau",      0x03C4},
    {"upsilon",  0x03C5},
    {"phi",      0x03C6},
    {"chi",      0x03C7},
    {"psi",      0x03C8},
    {"omega",    0x03C9},
    {"thetasym", 0x03D1},
    {"upsih",    0x03D2},
    {"piv",      0x03D6},
    {"bull",     0x2022},
    {"hellip",   0x2026},
    {"prime",    0x2032},
    {"Prime",    0x2033},
    {"oline",    0x203E},
    {"frasl",    0x2044},
    {"weierp",   0x2118},
    {"image",    0x2111},
    {"real",     0x211C},
    {"trade",    0x2122},
    {"alefsym",  0x2135},
    {"larr",     0x2190},
    {"uarr",     0x2191},
    {"rarr",     0x2192},
    {"darr",     0x2193},
    {"harr",     0x2194},
    {"crarr",    0x21B5},
    {"lArr",     0x21D0},
    {"uArr",     0x21D1},
    {"rArr",     0x21D2},
    {"dArr",     0x21D3},
    {"hArr",     0x21D4},
    {"forall",   0x2200},
    {"part",     0x2202},
    {"exist",    0x2203},
    {"empty",    0x2205},
    {"nabla",    0x2207},
    {"isin",     0x2208},
    {"notin",    0x2209},
    {"ni",       0x220B},
    {"prod",     0x220F},
    {"sum",      0x2211},
    {"minus",    0x2212},
    {"lowast",   0x2217},
    {"radic",    0x221A},
    {"prop",     0x221D},
    {"infin",    0x221E},
    {"ang",      0x2220},
    {"and",      0x2227},
    {"or",       0x2228},
    {"cap",      0x2229},
    {"cup",      0x222A},
    {"int",      0x222B},
    {"there4",   0x2234},
    {"sim",      0x223C},
    {"cong",     0x2245},
    {"asymp",    0x2248},
    {"ne",       0x2260},
    {"equiv",    0x2261},
    {"le",       0x2264},
    {"ge",       0x2265},
    {"sub",      0x2282},
    {"sup",      0x2283},
    {"nsub",     0x2284},
    {"sube",     0x2286},
    {"supe",     0x2287},
    {"oplus",    0x2295},
    {"otimes",   0x2297},
    {"perp",     0x22A5},
    {"sdot",     0x22C5},
    {"lceil",    0x2308},
    {"rceil",    0x2309},
    {"lfloor",   0x230A},
    {"rfloor",   0x230B},
    {"lang",     0x2329},
    {"rang",     0x232A},
    {"loz",      0x25CA},
    {"spades",   0x2660},
    {"clubs",    0x2663},
    {"hearts",   0x2665},
    {"diams",    0x2666},
};

static const kal_uint8 applib_html_char_ref_entities_hashTable[] = {
  87, 255, 100, 115, 101, 241, 226, 255, 224, 255,
  255, 225, 232, 130, 255, 255, 244, 126, 192, 73,
  136, 202, 255, 234, 35, 98, 33, 125, 48, 86,
  255, 34, 255, 200, 179, 154, 255, 255, 185, 141,
  108, 255, 106, 255, 131, 175, 22, 182, 65, 137,
  247, 8, 255, 128, 255, 6, 50, 255, 255, 255,
  255, 160, 142, 255, 255, 205, 255, 255, 209, 255,
  255, 109, 25, 18, 19, 255, 255, 13, 74, 169,
  37, 30, 121, 57, 243, 148, 10, 14, 255, 54,
  113, 133, 255, 26, 66, 111, 69, 255, 255, 255,
  255, 62, 112, 150, 255, 89, 255, 255, 36, 195,
  255, 124, 155, 157, 231, 99, 147, 215, 140, 177,
  233, 119, 255, 246, 237, 70, 181, 28, 255, 255,
  156, 218, 94, 123, 2, 255, 1, 51, 172, 49,
  153, 152, 132, 255, 16, 5, 188, 170, 40, 255,
  255, 103, 242, 59, 255, 67, 117, 223, 255, 255,
  255, 81, 53, 82, 32, 194, 129, 92, 206, 146,
  255, 102, 3, 104, 4, 27, 31, 178, 75, 24,
  220, 221, 20, 151, 85, 255, 64, 255, 255, 60,
  227, 255, 255, 255, 68, 255, 190, 255, 187, 255,
  43, 255, 122, 239, 219, 199, 193, 255, 110, 210,
  45, 235, 23, 139, 208, 91, 96, 255, 255, 183,
  255, 61, 168, 213, 255, 230, 255, 255, 145, 144,
  184, 238, 77, 252, 80, 163, 97, 255, 189, 255,
  0, 255, 56, 93, 176, 255, 83, 255, 255, 107,
  255, 255, 255, 255, 180, 72, 46, 255, 197, 95,
  255, 255, 255, 167, 88, 255, 255, 21, 255, 114,
  79, 255, 229, 251, 255, 171, 55, 211, 78, 255,
  255, 105, 217, 255, 255, 143, 255, 255, 250, 41,
  255, 255, 47, 228, 166, 255, 255, 255, 245, 149,
  255, 255, 52, 196, 207, 255, 39, 135, 255, 165,
  134, 255, 255, 29, 255, 191, 240, 255, 164, 214,
  255, 174, 222, 15, 58, 255, 255, 255, 71, 255,
  236, 159, 158, 255, 248, 11, 255, 38, 255, 7,
  255, 9, 162, 201, 255, 255, 90, 212, 44, 203,
  42, 255, 17, 255, 120, 173, 255, 198, 255, 116,
  12, 127, 216, 204, 138, 255, 161, 84, 255, 255,
  76, 255, 255, 249, 186, 118, 255, 255, 63
};

/* Characters 128-159 of unicode is specificly disallowed from use in HTML by the 
   HTML standard, which means that NCRs with these numbers are illegal. Most browsers 
   will probably interpret these as if they were written using windows-1252 encoding*/
static const kal_uint16 applib_html_char_ref_windows1252_to_unicode[] = {
  0x20AC, 0x0081, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
  0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008D, 0x017D, 0x008F,
  0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
  0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0x009D, 0x017E, 0x0178
};

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static kal_bool     applib_html_char_ref_cvt_char_entity_ref(const kal_char     *input,
                                                             const kal_int32    input_len,
                                                             kal_char           *output,
                                                             kal_int32          *output_len,
                                                             kal_bool           xml);
static kal_bool     applib_html_char_ref_cvt_numeric_char_ref(const kal_char    *input,
                                                              const kal_int32    input_size,
                                                              kal_char          *output,
                                                              kal_int32         *output_len);
static kal_int32    applib_html_char_ref_entity_to_int(const kal_char *name, kal_int32 length, kal_bool to_lower_case);
static kal_uint32   applib_html_char_ref_numeric_to_int(const kal_char *s, kal_int32 numeric_len);
static kal_int32    applib_html_char_ref_unicode_to_utf8(kal_uint32 uc, kal_char *s);
static kal_uint32   applib_html_char_ref_strhash(const kal_char *s, kal_int32 len, kal_bool to_lower_case);
static kal_int32    applib_html_char_ref_strncmp_lc(const kal_char *s1, const kal_char *s2, kal_int32 len);
static kal_int32    applib_html_char_ref_hex_str_to_int(const kal_char *s, kal_int32 numeric_len);
static kal_int32    applib_html_char_ref_dec_str_to_int(const kal_char *s, kal_int32 numeric_len);

/*****************************************************************************
 * FUNCTION
 *  applib_html_cvt_char_ref
 * DESCRIPTION
 *  This function is used to convert character reference. The input string shall 
 *  start with '&' and end with ';'. The output character is encoded in UTF-8 
 *  and the output_len will be set as 1~4 byte(s).
 * PARAMETERS
 *  *input          [IN]        UTF-8 encoded input string
 *  input_size      [IN]        Size of input string in byte
 *  *output         [OUT]       UTF-8 encoded output character
 *  *output_size    [IN/OUT]    Size of output character in byte. The caller set
 *                              avalable size for *output and this size should be
 *                              larger than APPLIB_HTML_MAX_UTF8_SIZE_PER_CHAR(4). 
 *                              After converting character reference,
 *                              this value will be set as actual output size.
 * RETURNS
 *  KAL_TRUE:   Successful to convert character reference.
 *  KAL_FALSE:  Failed to convert character reference.
 *****************************************************************************/
kal_bool applib_html_cvt_char_ref(const kal_char    *input,
                                  const kal_int32   input_size,
                                  kal_char          *output,
                                  kal_int32         *output_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*output_size < APPLIB_HTML_MAX_UTF8_SIZE_PER_CHAR ||
        input_size < APPLIB_HTML_CHAR_REF_MIN_CHAR_ENTITY_LEN || input_size > APPLIB_HTML_CHAR_REF_MAX_CHAR_ENTITY_LEN ||
        *input != '&' || *(input+input_size-1) != ';')
    {
        return KAL_FALSE;
    }

    if (*(input+1) == '#')
    {
        return applib_html_char_ref_cvt_numeric_char_ref(input, input_size, output, output_size);
    }
    else
    {
        return applib_html_char_ref_cvt_char_entity_ref(input, input_size, output, output_size, KAL_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_cvt_char_entity_ref
 * DESCRIPTION
 *  This function is used to convert character entity reference.
 * PARAMETERS
 *  *input          [IN]    UTF-8 encoded input string
 *  input_size      [IN]    Size of input string in byte
 *  *output         [OUT]   UTF-8 encoded output character
 *  *output_size    [OUT]   Size of output character in byte
 *  xml             [IN]    Is xml or not
 * RETURNS
 *  KAL_TRUE:   Successful to convert character entity reference.
 *  KAL_FALSE:  Failed to convert character entity reference.
 *****************************************************************************/
static kal_bool applib_html_char_ref_cvt_char_entity_ref(const kal_char     *input,
                                                         const kal_int32    input_size,
                                                         kal_char           *output,
                                                         kal_int32          *output_size,
                                                         kal_bool           xml)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   ch;
    kal_int32   refLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refLen = input_size - 1 - (input[input_size - 1] == ';');
    ch = applib_html_char_ref_entity_to_int(input + 1, refLen, KAL_FALSE);
    if (ch == APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF && !xml)
    {
        ch = applib_html_char_ref_entity_to_int(input + 1, refLen, KAL_TRUE);
    }

    if (ch == APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF)
    {
        *output_size = 0;
        return KAL_FALSE;
    }

    *output_size = applib_html_char_ref_unicode_to_utf8((kal_uint32)ch, output);
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_cvt_numeric_char_ref
 * DESCRIPTION
 *  This function is used to convert numeric character reference.
 * PARAMETERS
 *  *input          [IN]    UTF-8 encoded input string
 *  input_size      [IN]    Size of input string in byte
 *  *output         [OUT]   UTF-8 encoded output character
 *  *output_size    [OUT]   Size of output character in byte
 * RETURNS
 *  KAL_TRUE:   Successful to convert character entity reference.
 *  KAL_FALSE:  Failed to convert character entity reference.
 *****************************************************************************/
static kal_bool applib_html_char_ref_cvt_numeric_char_ref(const kal_char    *input,
                                                          const kal_int32    input_size,
                                                          kal_char          *output,
                                                          kal_int32         *output_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  ch;
    kal_int32   numeric_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numeric_len = input_size - 2 - (input[input_size - 1] == ';');  /* 2: length of "&#" */
    ch = applib_html_char_ref_numeric_to_int(input+2, numeric_len);  /* 2: length of "&#" */

    if (ch == APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF)
    {
        *output_size = 0;
        return KAL_FALSE;
    }

    if (ch >= APPLIB_HTML_CHAR_REF_INVALID_UNICODE_128 && 
        ch <= APPLIB_HTML_CHAR_REF_INVALID_UNICODE_159)
    {
        ch = (kal_uint32)applib_html_char_ref_windows1252_to_unicode[ch - APPLIB_HTML_CHAR_REF_INVALID_UNICODE_128];
    }

    *output_size = applib_html_char_ref_unicode_to_utf8(ch, output);
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_str_to_int
 * DESCRIPTION
 *  This function is used to convert character entity reference string to the 
 *  corresponding unicode.
 * PARAMETERS
 *  *name           [IN]    Character entity name
 *  length          [IN]    Length of character entity name
 *  to_lower_case   [IN]    Convert to lower case or not
 * RETURNS
 *  The corresponding unicode.
 *****************************************************************************/
static kal_int32 applib_html_char_ref_entity_to_int(const kal_char *name, kal_int32 length, kal_bool to_lower_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8                             *hash_table = applib_html_char_ref_entities_hashTable;
    kal_int32                                   hash_table_size = sizeof(applib_html_char_ref_entities_hashTable);
    const applib_html_char_ref_strtable_entry_t *string_table = applib_html_char_ref_entities_strtable;

    kal_uint32  h = applib_html_char_ref_strhash(name, length, to_lower_case);
    kal_int32   idx = h % hash_table_size;
    kal_int32   step = 1 + (h % (hash_table_size - 2));
    kal_int32   tidx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (;;)
    {
        tidx = hash_table[idx];
        if (tidx == 0xff)
        {
            return APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF;
        }
        if (to_lower_case)
        {
            if (!applib_html_char_ref_strncmp_lc(name, string_table[tidx].name, length) &&
                string_table[tidx].name[length] == '\0')
            {
                return string_table[tidx].value;
            }
        }
        else
        {
            if (!strncmp (name, string_table[tidx].name, (size_t)length) &&
                string_table[tidx].name[length] == '\0')
            {
                return string_table[tidx].value;
            }
        }
        idx += step;
        if (idx >= hash_table_size)
        {
            idx -= hash_table_size;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_numeric_to_int
 * DESCRIPTION
 *  This function is used to convert numeric string to the corresponding unicode.
 * PARAMETERS
 *  *s              [IN]    Numeric string
 *  numeric_len     [IN]    Length of numeric string
 * RETURNS
 *  The corresponding unicode.
 *****************************************************************************/
static kal_uint32 applib_html_char_ref_numeric_to_int(const kal_char *s, kal_int32 numeric_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*s == 'x' || *s == 'X')
    {
        numeric_len--;
        ch = applib_html_char_ref_hex_str_to_int(s + 1, numeric_len);
    }
    else
    {
        ch = applib_html_char_ref_dec_str_to_int(s, numeric_len);
    }

    if (ch >= 0x110000 || ch < 0 || (ch >= 0 && ch <= 8) || (ch >= 14 && ch <= 31) || 
        (ch >= 0xD800 && ch < 0xE000) || ch == 0xFFFF || ch == 0xFFFE)
    {
        return APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF;
    }

    return (kal_uint32)ch;
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_unicode_to_utf8
 * DESCRIPTION
 *  This function is used to convert unicode to UTF-8. The caller shall make sure 
 *  the size of output buffer is large enough.
 * PARAMETERS
 *  uc  [IN]    Unicode
 *  *s  [OUT]   UTF-8 encoded output buffer.
 * RETURNS
 *  Size of output string.
 *****************************************************************************/
static kal_int32 applib_html_char_ref_unicode_to_utf8(kal_uint32 uc, kal_char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   dn;
    kal_uint8   mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (uc < 0x80)
    {
        dn = 1;
        mask = 0;
    }
    else if (uc < 0x800)
    {
        dn = 2;
        mask = 0xc0;
    }
    else if (uc < 0x10000)
    {
        dn = 3;
        mask = 0xe0;
    }
    else if (uc < 0x200000)
    {
        dn = 4;
        mask = 0xf0;
    }
    else
    {
        return -1;
    }

    if (s)
    {
        switch (dn)
        {
            case 4:
                s[3] = (kal_int8)((uc & 0x3f) | 0x80);
                uc >>= 6;
              
            case 3:
                s[2] = (kal_int8)((uc & 0x3f) | 0x80);
                uc >>= 6;
              
            case 2:
                s[1] = (kal_int8)((uc & 0x3f) | 0x80);
                uc >>= 6;
              
            case 1:
                s[0] = (kal_int8)(uc | mask);
        }
    }

    return dn;
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_strhash
 * DESCRIPTION
 *  This function is a hash function.
 * PARAMETERS
 *  *s              [IN]    Input string
 *  len             [IN]    Length of input string
 *  to_lower_case   [IN]    Convert to lower case or not
 * RETURNS
 *  String hash value.
 *****************************************************************************/
static kal_uint32 applib_html_char_ref_strhash(const kal_char *s, kal_int32 len, kal_bool to_lower_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   i;
    kal_int32   c0 = 0, c1 = 0, c2 = 0, c3 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = len;
  
    switch (len & 0x3)
    {
        case 0:
            while (i > 0)
            {
                --i;
                c3 ^= to_lower_case ? APPLIB_HTML_CHAR_REF_TOLOWER(s[i]) : s[i];
              
        case 3:
                --i;
                c2 ^= to_lower_case ? APPLIB_HTML_CHAR_REF_TOLOWER(s[i]) : s[i];
              
        case 2:
                --i;
                c1 ^= to_lower_case ? APPLIB_HTML_CHAR_REF_TOLOWER(s[i]) : s[i];
              
        case 1:
                --i;
                c0 ^= to_lower_case ? APPLIB_HTML_CHAR_REF_TOLOWER(s[i]) : s[i];
              
            }
    }

    return (((kal_uint32)c0) << 24) | (((kal_uint32)c1) << 16) |
           (((kal_uint32)c2) <<  8) | ((kal_uint32)c3);
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_strncmp_lc
 * DESCRIPTION
 *  This function is used to convert two string which is converted to lower case.
 * PARAMETERS
 *  *s1     [IN]    String one
 *  *s2     [IN]    String two
 *  len     [IN]    Length of string to be compared
 * RETURNS
 *  0:              str1 is equal to str2
 *  less than 0:    str1 is less than str2
 *  greater than 0: str1 is greater than str2 
 *****************************************************************************/
static kal_int32 applib_html_char_ref_strncmp_lc(const kal_char *s1, const kal_char *s2, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len <= 0)
    {
        return 0;
    }

    for (; APPLIB_HTML_CHAR_REF_TOLOWER(*s1) == APPLIB_HTML_CHAR_REF_TOLOWER(*s2);
           s1++, s2++)
    {
        if ((--len <= 0) || (*s1 == '\0'))
        {
            return 0;
        }
    }
    return (APPLIB_HTML_CHAR_REF_TOLOWER(*s1) - APPLIB_HTML_CHAR_REF_TOLOWER(*s2));
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_hex_str_to_int
 * DESCRIPTION
 *  This function is used to convert a hexadecimal string to the corresponding integer.
 * PARAMETERS
 *  *s              [IN]    Hexadecimal string
 *  numeric_len     [IN]    Length of hexadecimal string
 * RETURNS
 *  The corresponding integer.
 *****************************************************************************/
static kal_int32 applib_html_char_ref_hex_str_to_int(const kal_char *s, kal_int32 numeric_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  n = 0;
    kal_uint8   c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (numeric_len <= 0)
    {
        return APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF;
    }
    
    while (numeric_len && APPLIB_HTML_CHAR_REF_ISHEX(c = (kal_uint8)*s))
    {
        if (APPLIB_HTML_CHAR_REF_ISDIGIT(c))
        {
            n = (n << 4) + (c - '0');
        }
        else if (APPLIB_HTML_CHAR_REF_ISLOWER(c))
        {
            n = (n << 4) + (c - 'a' + 10);
        }
        else
        {
            n = (n << 4) + (c - 'A' + 10);
        }
        s++;
        numeric_len--;
    }

    if (numeric_len == 0)
    {
        return (kal_int32)n;
    }
    else
    {
        return APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_html_char_ref_dec_str_to_int
 * DESCRIPTION
 *  This function is used to convert a decimal string to the corresponding integer.
 * PARAMETERS
 *  *s              [IN]    Decimal string
 *  numeric_len     [IN]    Length of decimal string
 * RETURNS
 *  The corresponding integer.
 *****************************************************************************/
static kal_int32 applib_html_char_ref_dec_str_to_int(const kal_char *s, kal_int32 numeric_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   n = 0;
    kal_uint8   c;
    kal_char    sign;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (numeric_len <= 0)
    {
        return APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF;
    }

    sign = *s;
    if (*s == '-' || *s == '+')
    {
        s++;
        numeric_len--;
    }
    
    while (numeric_len && APPLIB_HTML_CHAR_REF_ISDIGIT(c = (kal_uint8)*s))
    {
        n = n * 10 + (c - '0');
        s++;
        numeric_len--;
    }

    if (numeric_len == 0)
    {
        if (sign == '-')
        {
            return (kal_int32)-n;
        }
        else
        {
            return (kal_int32)n;
        }
    }
    else
    {
        return APPLIB_HTML_CHAR_REF_INVALID_CHAR_REF;
    }
}

