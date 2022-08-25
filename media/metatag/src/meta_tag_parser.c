/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*   meta_tag_parser.c
*
* Project:
* --------
*   Maui
*
* Description:
* ------------
*   This file includes primary exported functions of audio module.
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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "meta_tag_api.h"
//#include "meta_tag_parser.h"
#include "kal_general_types.h"
#include "string.h"

#if defined(__META_DATA_PARSE_API__)
/*  define global variable
*/
static  const char* g_image_type[META_TAG_IMG_TOTAL] = 
{         
    "PNG",          /*META_TAG_IMG_PNG = 0, */    
    "JPG",          /*META_TAG_IMG_JPG,     */   
    "JPEG",         /*META_TAG_IMG_JPEG,    */
    "GIF",          /*META_TAG_IMG_GIF,     */
    "BMP",          /*META_TAG_IMG_BMP,     */
    "-->",          /*META_TAG_IMG_URL_WAP, */
};

/*****************************************************************************
 * FUNCTION
 *  meta_tag_find_terminator
 * DESCRIPTION
 *  GET string length 
 * PARAMETERS
 *  pbuffer     [IN]        stream data
 *  size        [IN]        data size
 * RETURNS
 *  if no terminal char, return -1 
 *****************************************************************************/
kal_int32 meta_tag_find_terminator(kal_uint8* pbuffer, 
                                   kal_uint32 size, kal_uint8 encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0, n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(encoding)
    {
    case META_TAG_TEXT_ENCODING_UTF16:
    case META_TAG_TEXT_ENCODING_UTF16_BE:

        n = (kal_int32)(size/2);        
        while (i < n)
        {
            if (pbuffer[i] == 0 && pbuffer[i+1] == 0)
            {
                return i;
            }
            i+=2;
        }
        break;        
    default:

        while (i < (kal_int32)size)
        {
            if (pbuffer[i] == 0)
            {
                return i;
            }
            i++;
        }
    	break;        
    }    
    return  -1;
}


/*****************************************************************************
 * FUNCTION
 *  meta_tag_get_image_type
 * DESCRIPTION
 *  GET IMAGE type 
 * PARAMETERS
 *  pbuffer     [IN]        stream data
 *  size        [IN]        data size
 * RETURNS
 *   
 *****************************************************************************/
kal_uint8  meta_tag_get_image_type(kal_uint8* pbuffer, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for (i = 0; i < (kal_int32)size; i++)
    {
        if (pbuffer[i] >= 'a' && pbuffer[i] <= 'z')
        {
            pbuffer[i] -= 'a'-'A'; 
        }
    }
    if (size > 6)
    {
        if (0 == strncmp("IMAGE/", (char*)pbuffer, 6))
        {
            pbuffer += 6; 
            size -= 6;
        }
        else
        {
            return  META_TAG_IMG_TOTAL;
        }
    }
    for (i = 0; i < META_TAG_IMG_TOTAL; i++)
    {
        if (0 == strncmp(g_image_type[i], (char*)pbuffer, size))
        {
            break;
        }
    }
    return  (kal_uint8)i;
}


/*****************************************************************************
 * FUNCTION
 *  meta_tag_is_empty_asci_item
 * DESCRIPTION
 *  check string whether it's full of space char 
 * PARAMETERS
 *  pbuffer     [IN]        stream data
 *  size        [IN]        data size
 * RETURNS
 *   
 *****************************************************************************/
kal_uint8  meta_tag_is_empty_asci_item(kal_uint8* pbuffer, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for (i = 0; i < size; i++)
    {
        if (0 == pbuffer[i])
        {
            break;
        }
        if (0x20 != pbuffer[i])
        {
            return  0;
        }
    }
    return  1;
}


/*****************************************************************************
 * FUNCTION
 *  meta_tag_is_empty_ucs2_item
 * DESCRIPTION
 *  check string whether it's full of space char 
 * PARAMETERS
 *  pbuffer     [IN]        stream data
 *  size        [IN]        data size
 * RETURNS
 *   
 *****************************************************************************/
kal_uint8  meta_tag_is_empty_ucs2_item(kal_uint16* pbuffer, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for (i = 0; i < size; i++)
    {
        if (0 == pbuffer[i])
            break;
        
        if (0x20 != pbuffer[i])
            return  0;
    }
    return  1;
}

#endif  /*#if defined(__META_DATA_PARSE_API__)*/




