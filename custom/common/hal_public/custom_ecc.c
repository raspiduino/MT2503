/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   custom_ecc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains ECC function.
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

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "string.h"
#include "sim_common_enums.h"   /* SIM data type */
#include "sim_public_api.h"

#if defined(PLUTO_MMI) || defined(NEPTUNE_MMI)
#include "mmi_features.h"
#endif

#include "custom_mmi_default_value.h"
#include "custom_ecc.h"

#define MAX_DIAL_PAD (41)

/* ECC buffers */
/* The last word means whether this entry should be regarded as emergency call if SIM card is present */
/* 0: ECC only if no SIM,  1: ECC always */
const kal_uint16 ecc_default_num[ ][ECC_CUSTOM_DEFAULT_ECC_LENGTH + 1] = 
{
    {0x0031, 0x0031, 0x0032, 0x0000, 1}, /* 112 */
    {0x0039, 0x0031, 0x0031, 0x0000, 1}, /* 911 */
#ifdef __MEXICO_ECC__
    {0x0030, 0x0038, 0x0030, 0x0000, 1}, /* 080 */
    {0x0030, 0x0036, 0x0030, 0x0000, 1}, /* 060 */
#endif /* __MEXICO_ECC__ */ 
#ifdef __RUSSIA_ECC__
    {0x0030, 0x0031, 0x0000, 0x0000, 1}, /* 01  */
    {0x0030, 0x0032, 0x0000, 0x0000, 1}, /* 02  */
    {0x0030, 0x0033, 0x0000, 0x0000, 1}, /* 03  */
    {0x0030, 0x0030, 0x0031, 0x0000, 1}, /* 001 */
    {0x0030, 0x0030, 0x0032, 0x0000, 1}, /* 002 */
    {0x0030, 0x0030, 0x0033, 0x0000, 1}, /* 003 */
#endif /* __RUSSIA_ECC__ */
#ifdef __PHILIPPINES_ECC__
    {0x0031, 0x0031, 0x0037, 0x0000, 1}, /* 117 */
#endif /* __PHILIPPINES_ECC__ */
#ifdef __BRAZIL_ECC__
    {0x0031, 0x0039, 0x0030, 0x0000, 1}, /* 190 */
#endif /* __BRAZIL_ECC__ */
#ifdef __PAKISTAN_ECC__
    {0x0031, 0x0035, 0x0000, 0x0000, 0}, /* 15 */
    {0x0031, 0x0031, 0x0035, 0x0000, 0}, /* 115 */
#endif /* __PAKISTAN_ECC__ */
//#ifdef __OP02__
    {0x0031, 0x0032, 0x0030, 0x0000, 0}, /* 120 */
    {0x0031, 0x0032, 0x0032, 0x0000, 0}, /* 122 */
//#endif /* __OP02__ */
#if defined(__CPHS__) && defined(__CPHS_NUM_999_AS_ECC__)
    {0x0039, 0x0039, 0x0039, 0x0000, 1}, /* 999 */
#else
    {0x0039, 0x0039, 0x0039, 0x0000, 0}, /* 999 */
#endif
    {0x0030, 0x0030, 0x0030, 0x0000, 0}, /* 000 */
    {0x0031, 0x0031, 0x0030, 0x0000, 0}, /* 110 */
    {0x0031, 0x0031, 0x0038, 0x0000, 0}, /* 118 */
    {0x0031, 0x0031, 0x0039, 0x0000, 0}, /* 119 */
    {0x0030, 0x0038, 0x0000, 0x0000, 0}, /* 08  */
    {0x0000, 0x0000, 0x0000, 0x0000, 0}
};

const kal_uint16 ecc_special_num[ ][ECC_CUSTOM_DEFAULT_ECC_LENGTH] =
{
#ifdef __PHILIPPINES_ECC__
    {0x0031, 0x0031, 0x0037, 0x0000}, /* 117 */
#endif /* __PHILIPPINES_ECC__ */
#ifdef __OP01_3G__ /* special requested by CMCC TD test case: 12.2 */
    {0x0039, 0x0039, 0x0039, 0x0000}, /* 999 */
    {0x0030, 0x0030, 0x0030, 0x0000}, /* 000 */
    {0x0031, 0x0031, 0x0030, 0x0000}, /* 110 */
    {0x0031, 0x0031, 0x0038, 0x0000}, /* 118 */
    {0x0031, 0x0031, 0x0039, 0x0000}, /* 119 */
    {0x0030, 0x0038, 0x0000, 0x0000}, /* 08  */
#endif
    {0x0000, 0x0000, 0x0000, 0x0000}
};

static ecc_record_struct ecc_sim1_number[ECC_CUSTOM_MAX_SIM_RECORD] = {0};
#ifdef __REL5__
static ecc_record_struct ecc_nw1_number[ECC_CUSTOM_MAX_NW_RECORD] = {0};
#endif
#ifdef __GEMINI__
static ecc_record_struct ecc_sim2_number[ECC_CUSTOM_MAX_SIM_RECORD] = {0};
#ifdef __REL5__
static ecc_record_struct ecc_nw2_number[ECC_CUSTOM_MAX_NW_RECORD] = {0};
#endif
#if (GEMINI_PLUS >= 3) // Gemini+
static ecc_record_struct ecc_sim3_number[ECC_CUSTOM_MAX_SIM_RECORD] = {0};
#ifdef __REL5__
static ecc_record_struct ecc_nw3_number[ECC_CUSTOM_MAX_NW_RECORD] = {0};
#endif
#if (GEMINI_PLUS >= 4) // Gemini+
static ecc_record_struct ecc_sim4_number[ECC_CUSTOM_MAX_SIM_RECORD] = {0};
#ifdef __REL5__
static ecc_record_struct ecc_nw4_number[ECC_CUSTOM_MAX_NW_RECORD] = {0};
#endif
#endif
#endif
#endif /* __GEMINI__ */
#if defined(PLUTO_MMI) && defined(__MMI_PHB_SOS_NUM_EDIT__)
static ecc_record_struct ecc_nvram_number[ECC_CUSTOM_MAX_NVRAM_RECORD] = {0};
#endif

#if defined(PLUTO_MMI) && defined(__REL5__)
static kal_uint8 ecc_sim1_display_buffer[ECC_CUSTOM_MAX_SIM_RECORD][(MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH] = {0};
#ifdef __GEMINI__
static kal_uint8 ecc_sim2_display_buffer[ECC_CUSTOM_MAX_SIM_RECORD][(MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH] = {0};
#if (GEMINI_PLUS >= 3) // Gemini+
static kal_uint8 ecc_sim3_display_buffer[ECC_CUSTOM_MAX_SIM_RECORD][(MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH] = {0};
#if (GEMINI_PLUS >= 4) // Gemini+
static kal_uint8 ecc_sim4_display_buffer[ECC_CUSTOM_MAX_SIM_RECORD][(MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH] = {0};
#endif
#endif
#endif /* __GEMINI__ */
#endif /* defined(PLUTO_MMI) && defined(__REL5__) */

static kal_uint8 ecc_empty_display_buffer[ENCODING_LENGTH] = {0};


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_decode_bcd_2_ansii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void ecc_custom_decode_bcd_2_ansii(kal_uint8 *ecc_asnii, kal_uint8 *ecc_bcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(ecc_asnii + 0) = (*(ecc_bcd + 0) & 0x0F) == 0x0F ? 0 : (kal_uint8) (0x30 + ( *(ecc_bcd + 0) & 0x0F));
    *(ecc_asnii + 1) = (*(ecc_bcd + 0) & 0xF0) == 0xF0 ? 0 : (kal_uint8) (0x30 + ((*(ecc_bcd + 0) & 0xF0) >> 4));
    *(ecc_asnii + 2) = (*(ecc_bcd + 1) & 0x0F) == 0x0F ? 0 : (kal_uint8) (0x30 + ( *(ecc_bcd + 1) & 0x0F));
    *(ecc_asnii + 3) = (*(ecc_bcd + 1) & 0xF0) == 0xF0 ? 0 : (kal_uint8) (0x30 + ((*(ecc_bcd + 1) & 0xF0) >> 4));
    *(ecc_asnii + 4) = (*(ecc_bcd + 2) & 0x0F) == 0x0F ? 0 : (kal_uint8) (0x30 + ( *(ecc_bcd + 2) & 0x0F));
    *(ecc_asnii + 5) = (*(ecc_bcd + 2) & 0xF0) == 0xF0 ? 0 : (kal_uint8) (0x30 + ((*(ecc_bcd + 2) & 0xF0) >> 4));
}


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_bcd_digit_2_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  char
 *****************************************************************************/
static char ecc_custom_bcd_digit_2_char(kal_uint8 digit)
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
 *  ecc_custom_bcd_2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void ecc_custom_bcd_2_string(kal_uint8 *bcd_array, kal_uint16 size, char *buf, kal_uint16 buf_size)
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
            digit = ecc_custom_bcd_digit_2_char((kal_uint8)(bcd_array[i] & 0x0F));
            if (digit == (char)0xFF)
            {
                return;
            }
            buf[j] = digit;
            j++;
        }
        if (j < buf_size - 1)
        {
            digit = ecc_custom_bcd_digit_2_char((kal_uint8)((bcd_array[i] >> 4) & 0x0F));
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
 *  ecc_custom_str_n_to_ucs2_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
static kal_uint16 ecc_custom_str_n_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len)
    {
        pOutBuffer[++count] = *pInBuffer;
        pOutBuffer[++count] = 0;

        if (*pInBuffer == '\0')
        {            
            break;
        }
        else
        {
            len--;
            pInBuffer++;
        }
    }

    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_prepare_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void ecc_custom_prepare_number(kal_uint8 *ecc_out, kal_uint8 *ecc_in, ecc_num_encoding_enum ecc_encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 ecc_tmp[ECC_CUSTOM_MAX_BCD_LENGTH * 2 + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ecc_out, 0, (ECC_CUSTOM_MAX_BCD_LENGTH * 2 + 1) * ENCODING_LENGTH);

    switch (ecc_encoding)
    {
        case ECC_ENCODING_ANSII:
            ecc_custom_str_n_to_ucs2_str((kal_int8*) ecc_out, (kal_int8*) ecc_in, ECC_CUSTOM_MAX_BCD_LENGTH * 2);
            break;
        case ECC_ENCODING_UCS2:
            kal_dchar_strncpy((char*) ecc_out, (char*) ecc_in, ECC_CUSTOM_MAX_BCD_LENGTH * 4);
            break;
        case ECC_ENCODING_BCD:
            ecc_custom_decode_bcd_2_ansii(ecc_tmp, ecc_in);
            ecc_custom_str_n_to_ucs2_str((kal_int8*) ecc_out, (kal_int8*) ecc_tmp, ECC_CUSTOM_MAX_BCD_LENGTH * 2);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_get_sim_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  ecc_record_struct *
 *****************************************************************************/
static ecc_record_struct *ecc_custom_get_sim_context(kal_uint8 entry_index, kal_uint8 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_index == ECC_SIM1_CALL)
    {
        return &(ecc_sim1_number[entry_index]);
    }
#ifdef __GEMINI__
    else if (sim_index == ECC_SIM2_CALL)
    {
        return &(ecc_sim2_number[entry_index]);
    }
#if (GEMINI_PLUS >= 3) // Gemini+
    else if (sim_index == ECC_SIM3_CALL)
    {
        return &(ecc_sim3_number[entry_index]);
    }
#if (GEMINI_PLUS >= 4) // Gemini+
    else if (sim_index == ECC_SIM4_CALL)
    {
        return &(ecc_sim4_number[entry_index]);
    }
#endif
#endif
#endif /* __GEMINI__ */
    else
    {
        return NULL;
    }
}


#ifdef __REL5__
/*****************************************************************************
 * FUNCTION
 *  ecc_custom_get_nw_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  ecc_record_struct *
 *****************************************************************************/
static ecc_record_struct *ecc_custom_get_nw_context(kal_uint8 entry_index, kal_uint8 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_index == ECC_SIM1_CALL)
    {
        return &(ecc_nw1_number[entry_index]);
    }
#ifdef __GEMINI__
    else if (sim_index == ECC_SIM2_CALL)
    {
        return &(ecc_nw2_number[entry_index]);
    }
#if (GEMINI_PLUS >= 3) // Gemini+
    else if (sim_index == ECC_SIM3_CALL)
    {
        return &(ecc_nw3_number[entry_index]);
    }
#if (GEMINI_PLUS >= 4) // Gemini+
    else if (sim_index == ECC_SIM4_CALL)
    {
        return &(ecc_nw4_number[entry_index]);
    }
#endif
#endif
#endif /* __GEMINI__ */
    else
    {
        return NULL;
    }
}
#endif /* __REL5__ */


#if defined(PLUTO_MMI) && defined(__REL5__)
/*****************************************************************************
 * FUNCTION
 *  ecc_custom_get_display_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  kal_uint8 *
 *****************************************************************************/
static kal_uint8 *ecc_custom_get_display_context(kal_uint8 entry_index, kal_uint8 sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_index == ECC_SIM1_CALL)
    {
        return &(ecc_sim1_display_buffer[entry_index][0]);
    }
#ifdef __GEMINI__
    else if (sim_index == ECC_SIM2_CALL)
    {
        return &(ecc_sim2_display_buffer[entry_index][0]);
    }
#if (GEMINI_PLUS >= 3) // Gemini+
    else if (sim_index == ECC_SIM3_CALL)
    {
        return &(ecc_sim3_display_buffer[entry_index][0]);
    }
#if (GEMINI_PLUS >= 4) // Gemini+
    else if (sim_index == ECC_SIM4_CALL)
    {
        return &(ecc_sim4_display_buffer[entry_index][0]);
    }
#endif
#endif
#endif /* __GEMINI__ */
    else
    {
        return NULL;
    }
}
#endif /* defined(PLUTO_MMI) && defined(__REL5__) */


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_verify_emergency_number_with_suffix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool ecc_custom_verify_emergency_number_with_suffix(kal_uint8 *in_number, kal_uint8 *ecc_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 ecc_default_num_ext[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_dchar_strlen((char*) ecc_number) == 0)
    {
        return KAL_FALSE;
    }

    /* Additional check for p or w after emergency call */
    kal_dchar_strcpy((char*) ecc_default_num_ext, (char*) ecc_number);
    kal_dchar_strcat((char*) ecc_default_num_ext, (char*) L"p");
    if (kal_dchar_strncmp((char*) in_number, (char*) ecc_default_num_ext, kal_dchar_strlen((char*) ecc_default_num_ext)) == 0)
    {
        return KAL_TRUE;
    }

    kal_dchar_strcpy((char*) ecc_default_num_ext, (char*) ecc_number);
    kal_dchar_strcat((char*) ecc_default_num_ext, (char*) L"w");
    if (kal_dchar_strncmp((char*) in_number, (char*) ecc_default_num_ext, kal_dchar_strlen((char*) ecc_default_num_ext)) == 0)
    {
        return KAL_TRUE;
    }

    /* diamond, 2006/05/12 Additional check for + after emergency call */
    kal_dchar_strcpy((char*) ecc_default_num_ext, (char*) ecc_number);
    kal_dchar_strcat((char*) ecc_default_num_ext, (char*) L"+");
    if (kal_dchar_strncmp((char*) in_number, (char*) ecc_default_num_ext, kal_dchar_strlen((char*) ecc_default_num_ext)) == 0 &&
        kal_dchar_strncmp((char*) (in_number + (kal_dchar_strlen((char*) in_number) - 2)), (char*) L"#", 2) != 0)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_verify_emergency_number
 * DESCRIPTION
 *  Verify calling number from ECC pool
 * PARAMETERS
 *  number          [IN]    verified ECC number
 *  num_length      [IN]    verified ECC number length
 *  num_encoding    [IN]    verified ECC number coding scheme
 *  call_type       [IN]    verified ECC number call type
 *  ecc_category    [OUT]   returned verified ECC number category (REL5 only)
 *  ecc_display     [OUT]   returned verified ECC number display string (REL5 only)
 *  verify_detail   [OUT]   returned match detail
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool ecc_custom_verify_emergency_number(
             kal_uint8 *number,
             kal_uint8 num_length,
             ecc_num_encoding_enum num_encoding,
             ecc_call_type_enum call_type,
             kal_uint8 *ecc_category,
             kal_uint8 **ecc_display,
             kal_uint8 *verify_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ecc_additional_check_number[5][5] = 
    {
        {0x002A, 0x0033, 0x0031, 0x0023, 0x002B}, /* prefix = *31#+ */
        {0x0023, 0x0033, 0x0031, 0x0023, 0x002B}, /* prefix = #31#+ */
        {0x002A, 0x0033, 0x0031, 0x0023},         /* prefix = *31#  */
        {0x0023, 0x0033, 0x0031, 0x0023},         /* prefix = #31#  */
        {0x002B}    /* prefix = + */
    };

    kal_uint16 ecc_sat_number[] = {0x0031, 0x0031, 0x0032, 0x0000};

    kal_uint8 ecc_buffer[MAX_DIAL_PAD * ENCODING_LENGTH] = {0};
    kal_uint8 ecc_tmp[MAX_DIAL_PAD * ENCODING_LENGTH] = {0};
    kal_uint8 *ecc_verify;
    kal_uint8 i, j;
    kal_uint8 sim_with_ecc_num_case = 0;
    sim_interface_enum sim_id;

#ifdef GEMINI_PLUS
    kal_uint8 loop_count = GEMINI_PLUS;
#else
    kal_uint8 loop_count = 1;
#endif

    ecc_record_struct *sim_context;
#ifdef __REL5__
    ecc_record_struct *nw_context;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* default response data */
    if (ecc_category != NULL)
    {
        *ecc_category = 0;
    }

    if (ecc_display != NULL)
    {
        *ecc_display = &ecc_empty_display_buffer[0];
    }

    if (verify_detail != NULL)
    {
        *verify_detail = ECC_NOT_MATCH;
    }

    switch (num_encoding)
    {
        case ECC_ENCODING_ANSII:
            ecc_custom_str_n_to_ucs2_str((kal_int8*) ecc_buffer, (kal_int8*) number, MAX_DIAL_PAD - 1);
            break;
        case ECC_ENCODING_UCS2:
            kal_dchar_strncpy((char*) ecc_buffer, (char*) number, MAX_DIAL_PAD - 1);
            break;
        case ECC_ENCODING_BCD:
            ecc_custom_bcd_2_string(number, num_length, (char*) ecc_tmp, MAX_DIAL_PAD);
            ecc_custom_str_n_to_ucs2_str((kal_int8*) ecc_buffer, (kal_int8*) ecc_tmp, MAX_DIAL_PAD - 1);
            break;
        default:
            return KAL_FALSE;
            break;
    }

    if (kal_dchar_strlen((char*) ecc_buffer) == 0)
    {
        return KAL_FALSE;
    }

    /* Additional check for *31# and #31# before emergency call */
    /* Additional check for + before emergency call */
    if ((kal_dchar_strncmp((char*) ecc_buffer, (char*) ecc_additional_check_number[0], 10) == 0) ||
        (kal_dchar_strncmp((char*) ecc_buffer, (char*) ecc_additional_check_number[1], 10) == 0))
    {
        ecc_verify = ecc_buffer + 10;
    }
    else if ((kal_dchar_strncmp((char*) ecc_buffer, (char*) ecc_additional_check_number[2], 8) == 0) ||
             (kal_dchar_strncmp((char*) ecc_buffer, (char*) ecc_additional_check_number[3], 8) == 0))
    {
        ecc_verify = ecc_buffer + 8;
    }
    else if (kal_dchar_strncmp((char*) ecc_buffer, (char*) ecc_additional_check_number[4], 2) == 0)
    {
        ecc_verify = ecc_buffer + 2;
    }
    else
    {
        ecc_verify = ecc_buffer;
    }

    if (kal_dchar_strlen((char*) ecc_verify) == 0)
    {
        return KAL_FALSE;
    }

    if (call_type == ECC_SAT_CALL)
    {
        if (kal_dchar_strcmp((char*) ecc_verify, (char*) ecc_sat_number) == 0)
        {
            if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }

    /* verify SIM record first */
    for (j = ECC_SIM1_CALL; j < loop_count; j++)
    {
        if (call_type != j && call_type != ECC_ALL_CALL)
        {
            continue;
        }

        for (i = 0; i < ECC_CUSTOM_MAX_SIM_RECORD; i++)
        {
        #ifdef __GEMINI_3G_SWITCH__
            sim_id = l4c_gemini_get_switched_sim_id(j);
        #else
            sim_id = j;
        #endif
            sim_context = ecc_custom_get_sim_context(i, sim_id);

            if (kal_dchar_strcmp((char*) ecc_verify, (char*) sim_context->ecc_number) == 0)
            {
            #ifdef __REL5__
                if (ecc_category != NULL) *ecc_category = sim_context->ecc_category;
            #ifdef PLUTO_MMI
                if (ecc_display != NULL) *ecc_display = sim_context->ecc_display;
            #endif
            #endif /* __REL5__ */
                if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
                return KAL_TRUE;
            }

            if (ecc_custom_verify_emergency_number_with_suffix(ecc_verify, sim_context->ecc_number))
            {
            #ifdef __REL5__
                if (ecc_category != NULL) *ecc_category = sim_context->ecc_category;
            #ifdef PLUTO_MMI
                if (ecc_display != NULL) *ecc_display = sim_context->ecc_display;
            #endif
            #endif /* __REL5__ */
                if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
                return KAL_TRUE;
            }

            if (verify_detail != NULL && kal_dchar_strncmp((char*) sim_context->ecc_number, (char*) ecc_verify, kal_dchar_strlen((char*) ecc_verify)) == 0)
            {
                *verify_detail = ECC_PARTIALLY_MATCH;
            }            
        }
    }

    /* verify NW record second */
#ifdef __REL5__
    for (j = ECC_SIM1_CALL; j < loop_count; j++)
    {
        if (call_type != j && call_type != ECC_ALL_CALL)
        {
            continue;
        }

        for (i = 0; i < ECC_CUSTOM_MAX_NW_RECORD; i++)
        {
        #ifdef __GEMINI_3G_SWITCH__
            sim_id = l4c_gemini_get_switched_sim_id(j);
        #else
            sim_id = j;
        #endif
            nw_context = ecc_custom_get_nw_context(i, sim_id);

            if (kal_dchar_strcmp((char*) ecc_verify, (char*) nw_context->ecc_number) == 0)
            {
                if (ecc_category != NULL) *ecc_category = nw_context->ecc_category;
                if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
                return KAL_TRUE;
            }

            if (ecc_custom_verify_emergency_number_with_suffix(ecc_verify, nw_context->ecc_number))
            {
                if (ecc_category != NULL) *ecc_category = nw_context->ecc_category;
                if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
                return KAL_TRUE;
            }

            if (verify_detail != NULL && kal_dchar_strncmp((char*) nw_context->ecc_number, (char*) ecc_verify, kal_dchar_strlen((char*) ecc_verify)) == 0)
            {
                *verify_detail = ECC_PARTIALLY_MATCH;
            }            
        }
    }
#endif /* __REL5__ */

    /* verify NVRAM record next */
#if defined(PLUTO_MMI) && defined(__MMI_PHB_SOS_NUM_EDIT__)
    for (i = 0; i < ECC_CUSTOM_MAX_NVRAM_RECORD; i++)
    {
        if (kal_dchar_strcmp((char*) ecc_verify, (char*) ecc_nvram_number[i].ecc_number) == 0)
        {
            if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
            return KAL_TRUE;
        }

        if (ecc_custom_verify_emergency_number_with_suffix(ecc_verify, ecc_nvram_number[i].ecc_number))
        {
            if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;
            return KAL_TRUE;
        }

        if (verify_detail != NULL && kal_dchar_strncmp((char*) ecc_nvram_number[i].ecc_number, (char*) ecc_verify, kal_dchar_strlen((char*) ecc_verify)) == 0)
        {
            *verify_detail = ECC_PARTIALLY_MATCH;
        }
    }
#endif /* defined(PLUTO_MMI) && defined(__MMI_PHB_SOS_NUM_EDIT__) */

    /* verify default record finally */
    for (i = 0; ecc_default_num[i][0] != 0x00; i++)
    {
    #ifdef __GEMINI__
        #ifdef __GEMINI_3G_SWITCH__
            sim_id = l4c_gemini_get_switched_sim_id(SIM1);
        #else
            sim_id = SIM1;
        #endif
        if (call_type == ECC_SIM1_CALL && check_sim_card_status(sim_id) != SIM_CARD_NOT_INSERTED && !(kal_bool) ecc_default_num[i][ECC_CUSTOM_DEFAULT_ECC_LENGTH])
        {
            sim_with_ecc_num_case = 1;
        }
        #ifdef __GEMINI_3G_SWITCH__
            sim_id = l4c_gemini_get_switched_sim_id(SIM2);
        #else
            sim_id = SIM2;
        #endif
        if (call_type == ECC_SIM2_CALL && check_sim_card_status(sim_id) != SIM_CARD_NOT_INSERTED && !(kal_bool) ecc_default_num[i][ECC_CUSTOM_DEFAULT_ECC_LENGTH])
        {
            sim_with_ecc_num_case = 1;
        }
    #if (GEMINI_PLUS >= 3) // Gemini+
        if (call_type == ECC_SIM3_CALL && check_sim_card_status(SIM3) != SIM_CARD_NOT_INSERTED && !(kal_bool) ecc_default_num[i][ECC_CUSTOM_DEFAULT_ECC_LENGTH])
        {
            sim_with_ecc_num_case = 1;
        }
    #if (GEMINI_PLUS >= 4) // Gemini+
        if (call_type == ECC_SIM4_CALL && check_sim_card_status(SIM4) != SIM_CARD_NOT_INSERTED && !(kal_bool) ecc_default_num[i][ECC_CUSTOM_DEFAULT_ECC_LENGTH])
        {
            sim_with_ecc_num_case = 1;
        }
    #endif
    #endif
        if (call_type == ECC_ALL_CALL &&
            check_sim_card_status(SIM1) != SIM_CARD_NOT_INSERTED &&
            check_sim_card_status(SIM2) != SIM_CARD_NOT_INSERTED &&
    #if (GEMINI_PLUS >= 3) // Gemini+
            check_sim_card_status(SIM3) != SIM_CARD_NOT_INSERTED &&
    #if (GEMINI_PLUS >= 4) // Gemini+
            check_sim_card_status(SIM4) != SIM_CARD_NOT_INSERTED &&
    #endif
    #endif
            !(kal_bool) ecc_default_num[i][ECC_CUSTOM_DEFAULT_ECC_LENGTH])
        {
            sim_with_ecc_num_case = 1;
        }
    #else /* __GEMINI__ */
        if (check_sim_card_status() != SIM_CARD_NOT_INSERTED && !(kal_bool) ecc_default_num[i][ECC_CUSTOM_DEFAULT_ECC_LENGTH])
        {
            sim_with_ecc_num_case = 1;
        }
    #endif /* __GEMINI__ */

#ifndef __OP01_3G__
        if (sim_with_ecc_num_case != 0)
        {
            sim_with_ecc_num_case = 0;
        	continue;
        }
#endif

        if (kal_dchar_strcmp((char*) ecc_verify, (char*) ecc_default_num[i]) == 0)
        {
            if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;

            /* special handle */
            /* MMI: it is an ECC */
            /* Protocol: it is an normal call */
        #ifdef __OP01_3G__
            if (sim_with_ecc_num_case != 0)
        #endif
            {
                for (j = 0; ecc_special_num[j][0] != 0x00; j++)
                {
                    if(kal_dchar_strcmp((char*) ecc_special_num[j], (char*) ecc_default_num[i]) == 0)
                    {
                        if(stack_get_active_module_id() != MOD_MMI)
                        {
                            return KAL_FALSE;
                        }
                        break;
                    }
                }
            }

            return KAL_TRUE;
        }

        if (ecc_custom_verify_emergency_number_with_suffix(ecc_verify, (kal_uint8*) ecc_default_num[i]))
        {
            if (verify_detail != NULL) *verify_detail = ECC_FULLY_MATCH;

            /* special handle */
            /* MMI: it is an ECC */
            /* Protocol: it is an normal call */
        #ifdef __OP01_3G__
            if (sim_with_ecc_num_case != 0)
        #endif
            {
                for (j = 0; ecc_special_num[j][0] != 0x00; j++)
                {
                    if(kal_dchar_strcmp((char*) ecc_special_num[j], (char*) ecc_default_num[i]) == 0)
                    {
                        if(stack_get_active_module_id() != MOD_MMI)
                        {
                            return KAL_FALSE;
                        }
                        break;
                    }
                }
            }

            return KAL_TRUE;
        }

        if (verify_detail != NULL && kal_dchar_strncmp((char*) ecc_default_num[i], (char*) ecc_verify, kal_dchar_strlen((char*) ecc_verify)) == 0)
        {
            *verify_detail = ECC_PARTIALLY_MATCH;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_update_emergency_number
 * DESCRIPTION
 *  Update ECC pool from applications
 * PARAMETERS
 *  number          [IN]    input ECC number
 *  num_encoding    [IN]    input ECC number coding scheme
 *  ecc_src         [IN]    input ECC number source
 *  ecc_category    [IN]    input ECC number category (REL5 only)
 *  ecc_display     [IN]    input ECC number display string (REL5 only)
 *  index           [IN]    input ECC number index (ex: 1 ~ 5)
 *  total           [IN]    input ECC number total (ex: 5)
 * RETURNS
 *  void
 *****************************************************************************/
void ecc_custom_update_emergency_number(
         kal_uint8 *number,
         ecc_num_encoding_enum num_encoding,
         ecc_src_type_enum ecc_src,
         kal_uint8 ecc_category,
         kal_uint8 *ecc_display,
         kal_uint8 index,
         kal_uint8 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ecc_record_struct *sim_context;
#ifdef __REL5__
    ecc_record_struct *nw_context;
#ifdef PLUTO_MMI
    kal_uint8 *display_context;
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(index > 0 && index <= total);

    if (number != NULL && *number == 0xFF)
    {
        return; /* skip invalid entry */
    }

    switch (ecc_src)
    {
        case ECC_SRC_SIM1:
    #ifdef __GEMINI__
        case ECC_SRC_SIM2:
    #if (GEMINI_PLUS >= 3) // Gemini+
        case ECC_SRC_SIM3:
    #if (GEMINI_PLUS >= 4) // Gemini+
        case ECC_SRC_SIM4:
    #endif
    #endif
    #endif /* __GEMINI__ */
            sim_context = ecc_custom_get_sim_context(index - 1, ecc_src - ECC_SRC_SIM1);
        #if defined(PLUTO_MMI) && defined(__REL5__)
            display_context = ecc_custom_get_display_context(index - 1, ecc_src - ECC_SRC_SIM1);
        #endif
            if (number != NULL)
            {
                ecc_custom_prepare_number(sim_context->ecc_number, number, num_encoding);
            #ifdef __REL5__
                sim_context->ecc_category = ecc_category;
            #endif
            }
        #if defined(PLUTO_MMI) && defined(__REL5__)
            else
            {
                kal_dchar_strcpy((char*) display_context, (char*) ecc_display);
                sim_context->ecc_display = display_context;
            }
        #endif /* defined(PLUTO_MMI) && defined(__REL5__) */
            break;

        case ECC_SRC_NW1:
    #ifdef __GEMINI__
        case ECC_SRC_NW2:
    #if (GEMINI_PLUS >= 3) // Gemini+
        case ECC_SRC_NW3:
    #if (GEMINI_PLUS >= 4) // Gemini+
        case ECC_SRC_NW4:
    #endif
    #endif
    #endif /* __GEMINI__ */
        #ifdef __REL5__
            nw_context = ecc_custom_get_nw_context(index - 1, ecc_src - ECC_SRC_NW1);
            ecc_custom_prepare_number(nw_context->ecc_number, number, num_encoding);
            nw_context->ecc_category = ecc_category;
        #endif /* __REL5__ */
            break;

        case ECC_SRC_NVRAM:
        #if defined(PLUTO_MMI) && defined(__MMI_PHB_SOS_NUM_EDIT__)
            if (*number == 0xFF)
            {
                return;
            }
            ecc_custom_prepare_number(ecc_nvram_number[index - 1].ecc_number, number, num_encoding);
        #endif /* defined(PLUTO_MMI) && defined(__MMI_PHB_SOS_NUM_EDIT__) */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ecc_custom_get_first_2_default_num
 * DESCRIPTION
 *  Get ECC pool first 2 default items
 * PARAMETERS
 *  ecc_num1        [IN]    return ECC number
 *  ecc_num2        [IN]    return ECC number
 * RETURNS
 *  void
 *****************************************************************************/
void ecc_custom_get_first_2_default_num(
         kal_uint8 **ecc_num1,
         kal_uint8 **ecc_num2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ecc_num1 = (kal_uint8*) (&ecc_default_num[0][0]);
    *ecc_num2 = (kal_uint8*) (&ecc_default_num[1][0]);
}
