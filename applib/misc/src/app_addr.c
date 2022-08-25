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
 * app_addr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains address encode/decode function.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_ADDR_C
#define _APP_ADDR_C

#include <stdlib.h>

#include "kal_release.h"        /* Basic data type */
//#include "stack_common.h"       /* Message ID range and SAP */
//#include "stack_msgs.h"         /* Message ID */
//#include "app_ltlcom.h"         /* Task message communiction */
//#include "stack_timer.h"        /* stack_timer_struct */
//#include "l4a.h"                /* L4 data type */
//#include "mnsms_struct.h"
//#include "smsal_peer_struct.h"
//#include "smsal_structs.h"
//#include "smsal_structs.h"
	#include "ps_public_utility.h"

//suggested add
    #include "kal_general_types.h"
    #include "string.h"
    #include "ps_public_enum.h"
    #include "stdio.h"

#define IPV4_BYTE_NUM 4
#define IPV4_STR_MAX_LEN (IPV4_BYTE_NUM * 3 + 3)

#define DIGIT_NUM(x) (1 + (x > 10) + (x > 100))
#define IS_DIGIT(x) ((x >= '0') && (x <= '9'))

kal_uint8 applib_addr_bcd_char_2_digit(kal_uint8 ch);

/*****************************************************************************
 * Unpack functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_addr_bcd_byte_len
 * DESCRIPTION
 *  Calculate byte size needed to save the address string in BCD format.
 *  Scan not more than n bytes.
 * PARAMETERS
 *  str        [IN]        address string
 *  n          [IN]        Consider at most n character
 * RETURNS
 *  The byte length of address string
 *****************************************************************************/
kal_uint16 applib_addr_bcd_byte_len(char *str, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str)
    {
        for (i = 0; i < n; i++)
        {
            if (applib_addr_bcd_char_2_digit(*(str + i)) != 0xFF)
            {
                len++;
            }
        }
    }
    return ((len + 1) / 2);
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_bcd_strlen
 * DESCRIPTION
 *  Calculate number of digits of 0xF terminated bcd_array. (TON+NPI included as 1st byte)
 *  Scan not more than n bytes.
 * PARAMETERS
 *  bcd_array       [IN]        BCD digit array
 *  n               [IN]        Compare at most n elements.
 * RETURNS
 *  The length of address string in ASCII(not including NULL terminator)
 *****************************************************************************/
kal_uint16 applib_addr_bcd_strlen(kal_uint8 *bcd_array, kal_uint16 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bcd_array)
    {
        if ((bcd_array[0] & 0xF0) == 0x90)
        {
            len++;
            n--;
        }
        bcd_array++;
        
        for (; bcd_array && n > 0; n--)
        {
            if ((*bcd_array & 0x0F) != 0x0F)
            {
                ++len;
            }
            else
            {
                break;
            }
    
            if ((*bcd_array >> 4 & 0x0F) != 0x0F)
            {
                ++len;
            }
            else
            {
                break;
            }
    
            ++bcd_array;
        }
    }
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_bcd_char_2_digit
 * DESCRIPTION
 *  Converts BCD char to digit
 * PARAMETERS
 *  ch       [IN]        character
 * RETURNS
 *  BCD digit value; 0xFF if failed
 *****************************************************************************/
kal_uint8 applib_addr_bcd_char_2_digit(kal_uint8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* input digit is a phone number digit */
    if (ch == '*')
    {
        return 0xa;
    }
    else if (ch == '#')
    {
        return 0xb;
    }
    else if (ch == 'p')
    {
        return 0xc;
    }
    else if (ch == 'w')
    {
        return 0xd;
    }
    else if (ch >= '0' && ch <= '9')
    {
        return (ch - '0');
    }

    return (char)0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_bcd_digit_2_char
 * DESCRIPTION
 *  Converts BCD digit to char
 * PARAMETERS
 *  digit       [IN]        BCD Digit
 * RETURNS
 *  Character format of BCD Digit; 0xFF if failed
 *****************************************************************************/
char applib_addr_bcd_digit_2_char(kal_uint8 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Re-assign the value of BCD encoding numbers */
    if (digit < 0xa)
    {
        return ('0' + digit);
    }
    else if (digit == 0xa)
    {
        return '*';
    }
    else if (digit == 0xb)
    {
        return '#';
    }
    else if (digit == 0xc)
    {
        return 'p';
    }
    else if (digit == 0xd)
    {
        return 'w';
    }
    else
    {
        return (char)0xFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_bcd_2_string
 * DESCRIPTION
 *  This function is used to unpack BCD digits (TON+NPI included as 1st byte) to character string
 * PARAMETERS
 *  bcd_array       [IN]       BCD byte array 
 *  size            [IN]       BCD byte array size
 *  buf             [OUT]      Output string buffer
 *  buf_size        [IN]       Output buffer size
 * RETURNS
 *****************************************************************************/
void applib_addr_bcd_2_string(kal_uint8 *bcd_array, kal_uint16 size, char *buf, kal_uint16 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j = 0;
    char digit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bcd_array == NULL || size == 0 || buf == NULL || buf_size == 0)
    {
        return;
    }
    
    memset(buf, 0x0, buf_size);
    if ((bcd_array[0] & 0xF0) == 0x90)
    {
        buf[j++] = '+';
    }

    for (i = 1; i < size && j < buf_size - 1; i++)
    {
        if (j < buf_size - 1)
        {
            digit = applib_addr_bcd_digit_2_char((kal_uint8)(bcd_array[i] & 0x0F));
            if (digit == (char)0xFF)
            {
                return;
            }
            buf[j] = digit;
            j++;
        }
        if (j < buf_size - 1)
        {
            digit = applib_addr_bcd_digit_2_char((kal_uint8)((bcd_array[i] >> 4) & 0x0F));
            if (digit == (char)0xFF)
            {
                return;
            }
            buf[j] = digit;
            j++;
        }
    }

    buf[j] = 0;
}

/*****************************************************************************
 * FUNCTION
 *  applib_addr_gsm7_strlen
 * DESCRIPTION
 *  Calculate character number of gsm7_array
 * PARAMETERS
 *  gsm7_array      [IN]        Packed gsm7 address array
 *  size            [IN]        Array size
 * RETURNS
 *  The length of address string in ASCII(not including NULL terminator)
 *****************************************************************************/
kal_uint16 applib_addr_gsm7_strlen(kal_uint8 *gsm7_array, kal_uint16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gsm7_array)
    {
        return smsal_msg_len_in_character(SMSAL_DEFAULT_DCS, size, gsm7_array[size - 1]);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_gsm7_2_string
 * DESCRIPTION
 *  This function is used to unpack gsm 7-bit address to character string
 * PARAMETERS
 *  gsm7_array    [IN]    packed gsm7 address data
 *  buf           [OUT]   buffer for unpacked ASCII string
 *  buf_size      [IN]    dst buffer size (ex. applib_addr_gsm7_len(...)+1)
 * RETURNS
 *****************************************************************************/
void applib_addr_gsm7_2_string(kal_uint8 *gsm7_array, char *buf, kal_uint16 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gsm7_array == NULL || buf == NULL || buf_size == 0)
    {
        return;
    }

    smsal_gsm7_unpack(gsm7_array, (kal_uint8 *)buf, buf_size, 0);
    buf[buf_size - 1] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_number_strlen
 * DESCRIPTION
 *  This function is used to calculate character number of BCD address.
 *  The BCD address array should include TON+NPI as the 1st byte.
 *  Based on TON, GSM 7-bit or BCD format is determined.
 * PARAMETERS
 *  src        [IN]    packed BCD address data with TON+NPI as 1st byte
 *  src_size   [IN]    src buffer size
 *  buf        [OUT]   buffer for unpacked ASCII string
 *  buf_size   [IN]    dst buffer size
 * RETURNS
 *****************************************************************************/
kal_uint16 applib_addr_number_strlen(kal_uint8 *src, kal_uint16 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src[0] & 0xf0) == 0xd0)  /* See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet) */
    {
        return applib_addr_gsm7_strlen(src + 1, (kal_uint16)(src_size - 1));
    }
    else
    {
        return applib_addr_bcd_strlen(src, src_size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_number_2_string
 * DESCRIPTION
 *  This function is used to unpack BCD number (TON+NPI included as 1st byte) to character string.
 *  Based on TON, GSM 7-bit or BCD format is determined.
 * PARAMETERS
 *  src        [IN]    packed BCD address data with TON+NPI as 1st byte
 *  src_size   [IN]    src buffer size
 *  buf        [OUT]   buffer for unpacked ASCII string
 *  buf_size   [IN]    dst buffer size
 * RETURNS
 *****************************************************************************/
void applib_addr_number_2_string(kal_uint8 *src, kal_uint16 src_size, char *dst, kal_uint16 dst_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src[0] & 0xf0) == 0xd0)  /* See 03.40 9.1.2.5 Type-of-number: Alphanumeric(7-bit default alphabet) */
    {
        kal_uint16 dst_len = applib_addr_number_strlen((kal_uint8 *)src, src_size);
        dst_size = (dst_len + 1 < dst_size) ? (dst_len + 1) : dst_size;
        applib_addr_gsm7_2_string(&src[1], dst, dst_size);
    }
    else
    {
        applib_addr_bcd_2_string(&src[0], src_size, dst, dst_size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_ipv4_strlen
 * DESCRIPTION
 *  Calculate character number of gsm7_array
 * PARAMETERS
 *  ipv4_array      [IN]        4-byte IPv4 address array
 *  size            [IN]        IPv4 address bytes (should be 4)
 * RETURNS
 *  The length of address string in ASCII(not including NULL terminator)
 *****************************************************************************/
kal_uint16 applib_addr_ipv4_strlen(kal_uint8 *ipv4_array, kal_uint16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ipv4_array && size == IPV4_BYTE_NUM)
    {
        /* number of "dots" = 3 */
        return (3 + 
            DIGIT_NUM(ipv4_array[0]) + 
            DIGIT_NUM(ipv4_array[1]) + 
            DIGIT_NUM(ipv4_array[2]) + 
            DIGIT_NUM(ipv4_array[3]));
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_ipv4_2_string
 * DESCRIPTION
 *  This function is used to convert IPv4 address to character string.
 * PARAMETERS
 *  src        [IN]    4-byte IPv4 address
 *  src_size   [IN]    IPv4 address bytes (should be 4)
 *  buf        [OUT]   buffer for ASCII string
 *  buf_size   [IN]    dst buffer size
 * RETURNS
 *****************************************************************************/
void applib_addr_ipv4_2_string(kal_uint8 *src, kal_uint16 src_size, char *dst, kal_uint16 dst_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src == NULL || src_size != IPV4_BYTE_NUM || dst == NULL ||
        dst_size < applib_addr_ipv4_strlen(src, src_size) + 1)
    {
        return;
    }
    memset(dst, 0x0, dst_size);
    sprintf(dst, "%d.%d.%d.%d", src[0], src[1], src[2], src[3]);
}


/*****************************************************************************
 * Pack functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_addr_string_2_ipv4
 * DESCRIPTION
 *  This function is used to convert IPv4 address to character string.
 * PARAMETERS
 *  src        [IN]    4-byte IPv4 address string
 *  buf        [OUT]   buffer for IPv4 byte array
 *  buf_size   [IN]    dst buffer size (should be 4)
 * RETURNS
 *****************************************************************************/
void applib_addr_string_2_ipv4(char *src, kal_uint8 *dst, kal_uint16 dst_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j, len;
    char *p;
    char tmp[IPV4_STR_MAX_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(src);
    if (len == 0 || dst == NULL || dst_size < IPV4_BYTE_NUM)
    {
        return;
    }
    memset(dst, 0x0, dst_size);
    memcpy(tmp, src, IPV4_STR_MAX_LEN);
    src = tmp;
    for (i = 0; i < IPV4_BYTE_NUM; i++)
    {
        if ((p = strchr(src, '.')) != NULL)
        {
            *p = '\0';
        }
        else if (i != 3)
        {
            return;
        }
            
        len = strlen(src);
        if (len == 0 || len > 3)
        {
            return;
        }
        p = src;
        for (j = 0; j < len; j++)
        {
            if (!IS_DIGIT(p[j]))
            {
                return;
            }
        }

        dst[i] = (kal_uint8)atoi(src);
        src += len + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_addr_string_2_bcd
 * DESCRIPTION
 *  This function is used to convert string to BCD array w/o TON+NPI byte
 * PARAMETERS
 *  bcd_array       [IN]       BCD byte array 
 *  size            [IN]       BCD byte array size
 *  buf             [OUT]      Output string buffer
 *  buf_size        [IN]       Output buffer size
 * RETURNS
 *****************************************************************************/
void applib_addr_string_2_bcd(char *src, kal_uint16 src_size, kal_uint8 *dst, kal_uint16 dst_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j = 0;
    kal_uint8 byte = 0;
    kal_bool is_lhbyte = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(src) < src_size || dst == NULL || dst_size == 0)
    {
        return;
    }
    
    for (i = 0; i < src_size && j < dst_size; i++)
    {
        if ((byte = applib_addr_bcd_char_2_digit(src[i])) == 0xFF)
        {
            continue;
        }

        if (!is_lhbyte)
        {
            dst[j] = byte;
            is_lhbyte = KAL_TRUE;
        }
        else
        {
            dst[j++] |= (char)(byte << 4);
            is_lhbyte = KAL_FALSE;
        }
    }

    if (is_lhbyte)
    {
        dst[j] |= 0xF0;
    }
}


#endif  /* _APP_ADDR_C */
