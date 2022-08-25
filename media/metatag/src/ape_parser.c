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
*  ape_parser.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   ape parsing definitions
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include <stdlib.h>
#include "kal_trace.h"
#include "ape_parser.h"
#include "meta_tag_api.h"
#include "kal_general_types.h"
#include "meta_tag_parser.h"
#include "med_trc.h"
#include "kal_public_api.h"
#include "string.h"
#include "Conversions.h"

#if defined(__TAG_SUPPORT_APE__)
/*  define macro 
*/
#define APE_VAL_MAX_LEN         244
#define APE_KEY_MAX_LEN         32
#define APE_KEY_MAX_NUM         32
#define APE_READ_HEADER_SIZE    (8+APE_KEY_MAX_LEN)
#define APE_READ_BUFFER_SIZE    META_TAG_FRAME_MAX_SIZE

/*  define function
*/
static  kal_uint8 tag_get_key_index(
                    kal_uint8* pbuffer, 
                    kal_uint8 size
                    );
/*  define global variable
*/
static  const ape_tag_key_struct g_ape_key[META_TAG_APE_ATTR_NUMBER] = 
{
    {"TITLE",       5, META_TAG_FRAME_TITLE,        META_TAG_ATTR_TITLE},
    {"ARTIST",      6, META_TAG_FRAME_ARTIST,       META_TAG_ATTR_ARTIST},
    {"ALBUM",       5, META_TAG_FRAME_ALBUM,        META_TAG_ATTR_ALBUM},
    {"COMMENT",     7, META_TAG_FRAME_DESCRIPTION,  META_TAG_ATTR_DESCRIPTION},
    {"GENRE",       5, META_TAG_FRAME_GENRE,        META_TAG_ATTR_GENRE},
    {"YEAR",        4, META_TAG_FRAME_YEAR,         META_TAG_ATTR_YEAR},
    {"TRACK",       5, META_TAG_FRAME_TRACKNUM,     META_TAG_ATTR_TRACKNUM},
    {"COPYRIGHT",   9, META_TAG_FRAME_COPYRIGHT,    META_TAG_ATTR_COPYRIGHT},
	{"COMPOSER",    8, META_TAG_FRAME_AUTHOR,    	META_TAG_ATTR_AUTHOR}
};


/*****************************************************************************
 * FUNCTION
 *  ape_tag_parse
 * DESCRIPTION
 *  parse ape tag meta 
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pInternal   [IN/OUT]    information for output
 * RETURNS
 *  success return META_TAG_ERR_NONE, 
 *****************************************************************************/
kal_uint8 ape_tag_parse(
                kal_uint32 metaID, 
                meta_tag_internal_info_struct* pInternal
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32  s32Tmp;
    kal_uint32 u32Item, u32Size, u32Read;
    kal_uint32 u32ItemSize, u32ItemFlag, u32ItemRetSize;
    kal_uint32 u32Attr;
    kal_uint8  *pBuffer;
    kal_uint8  u8TmpBuf[APE_READ_BUFFER_SIZE+2];
    kal_uint8  u8ValBuf[APE_VAL_MAX_LEN + 1], u8Tmp, u8FrameID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    s32Tmp = pInternal->func_p->tag_read(metaID, u8TmpBuf, APE_TAG_FOOTER_SIZE);
    if (s32Tmp != APE_TAG_FOOTER_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

        return  META_TAG_ERR_INVAILD_DATA;
    }

    /*check the data header, whether it is APE TAG*/
    if (0 != kal_mem_cmp(u8TmpBuf, APE_TAG_MAGIC_ID, APE_TAG_MAGIC_SIZE))
    {
        META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, 0);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    /*get tag total size and total item; the total size not include header*/
    u32Size = META_TAG_GET_U32_LE(u8TmpBuf+12);
    u32Item = META_TAG_GET_U32_LE(u8TmpBuf+16);

    /*not support item count more then APE_KEY_MAX_NUM*/
    if (u32Item > APE_KEY_MAX_NUM)
    {
        u32Item = APE_KEY_MAX_NUM;
    }

    s32Tmp  = 0-u32Size;
    s32Tmp  = pInternal->func_p->tag_seek(metaID, s32Tmp, FUNC_SEEK_CUR);
    if (s32Tmp < 0)
    {
        META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    u32Attr = 0;
    /*parse tag item*/
    while (u32Item > 0)
    {
        u32Read = pInternal->func_p->tag_read(metaID, u8TmpBuf, APE_READ_HEADER_SIZE);
        if (u32Read != APE_READ_HEADER_SIZE)
        {
            return  META_TAG_ERR_INVAILD_DATA;
        }

        u32ItemSize = META_TAG_GET_U32_LE(u8TmpBuf);
        u32ItemFlag = META_TAG_GET_U32_LE(u8TmpBuf+4);

        u8Tmp = tag_get_key_index(u8TmpBuf+8, APE_KEY_MAX_LEN); 
        
        if (u8Tmp >= META_TAG_APE_ATTR_NUMBER)
        {
            /*skip the item we are not support*/
            s32Tmp = meta_tag_find_terminator(u8TmpBuf+8, APE_KEY_MAX_LEN,
                META_TAG_TEXT_ENCODING_ISO_8859_1);
            if (s32Tmp < 0)
            {
                if (u32Size > APE_VAL_MAX_LEN)
                {
                    u32Read = APE_VAL_MAX_LEN;
                }
                else
                {
                    u32Read = u32Size;
                }
                s32Tmp = pInternal->func_p->tag_read(metaID, u8ValBuf, u32Read);
                if ((kal_int32)u32Read != s32Tmp)
                {
                    META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                s32Tmp = meta_tag_find_terminator(u8ValBuf, u32Read,
                    META_TAG_TEXT_ENCODING_ISO_8859_1);
                if (s32Tmp < 0)
                {
                    META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                s32Tmp = u32ItemSize-(u32Read-s32Tmp-1);
            }
            else
            {
                s32Tmp = u32ItemSize-(APE_KEY_MAX_LEN-s32Tmp-1);
            }
            s32Tmp  = pInternal->func_p->tag_seek(metaID, s32Tmp, FUNC_SEEK_CUR);
            if (s32Tmp < 0)
            {
                META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            u32Item--;
            continue;
        }
        else
        {
            u32Read     = APE_KEY_MAX_LEN-g_ape_key[u8Tmp].key_len-1;    
            s32Tmp      = u32ItemSize-u32Read;
            /*
            *   Item Flag last two Bits meaning text encoding format
            *   Just support UTF8
            */
            u32ItemFlag = (u32ItemFlag >> 1)&3;
            if (0 != u32ItemFlag)
            {
                if (s32Tmp > 0)
                {
                    s32Tmp  = pInternal->func_p->tag_seek(metaID, s32Tmp, FUNC_SEEK_CUR);
                    if (s32Tmp < 0)
                    {
                        META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

                        return  META_TAG_ERR_INVAILD_DATA;
                    }
                }
                u32Item--;
                continue;
            }
            /*copy remain data from key buffer*/            
            memcpy(u8ValBuf, u8TmpBuf+APE_READ_HEADER_SIZE-u32Read, u32Read);
            /*when key val + item val < APE_KEY_MAX_LEN*/
            if (s32Tmp <= 0)
            {
                u32ItemRetSize = u32ItemSize;
                if (s32Tmp < 0)
                {
                    s32Tmp  = pInternal->func_p->tag_seek(metaID, s32Tmp, FUNC_SEEK_CUR);
                    if (s32Tmp < 0)
                    {
                        META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

                        return  META_TAG_ERR_INVAILD_DATA;
                    }
                }
            }
            else
            {    
                /*omit item value when it huge then APE_VAL_MAX_LEN*/
                if (u32ItemSize > APE_VAL_MAX_LEN)
                {
                    s32Tmp = APE_VAL_MAX_LEN-u32Read;
                }
                u32ItemRetSize = u32Read+s32Tmp;
                u32Read = pInternal->func_p->tag_read(metaID, 
                    u8ValBuf+u32Read, s32Tmp);

                if ((kal_int32)u32Read != s32Tmp)
                {
                    META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                if (u32ItemSize > APE_VAL_MAX_LEN)
                {
                    s32Tmp  = pInternal->func_p->tag_seek(metaID, 
                        u32ItemSize-APE_VAL_MAX_LEN, FUNC_SEEK_CUR);
                    if (s32Tmp < 0)
                    {
                        META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, s32Tmp);
                        
                        return  META_TAG_ERR_INVAILD_DATA;
                    }
                }
            }
        }

        if (u32ItemRetSize <= APE_VAL_MAX_LEN)
        {
            u8ValBuf[u32ItemRetSize] = 0;
        }
        else
        {
            META_TAG_ERR_TRACE(FILE_ID_APE_PARSER, u32ItemRetSize);
            u8ValBuf[APE_VAL_MAX_LEN] = 0;
        }
        

        switch(g_ape_key[u8Tmp].key_attr)
        {
        case META_TAG_ATTR_YEAR: 
            if (u8ValBuf[0] >= '0' && u8ValBuf[0] <= '9')
            {
                pInternal->music_info.year = 
                (kal_int32)atoi((const char*)u8ValBuf);
            }
            else
            {
                pInternal->music_info.year = -1;
            }            
            break;
        case META_TAG_ATTR_TRACKNUM:   
            
            pInternal->music_info.track_number = 
                (kal_int32)atoi((const char*)u8ValBuf);
            break;
        default:
            break;
        }
        u8FrameID   = (kal_uint8)g_ape_key[u8Tmp].key_frameID;
        u32Attr     |= g_ape_key[u8Tmp].key_attr;
        
        if (u8FrameID < META_TAG_FRAME_TXT_TOTAL)
        {
            s32Tmp = meta_tag_is_empty_asci_item(u8ValBuf, u32ItemRetSize);
            if (0 == s32Tmp)
            {
                s32Tmp = mmi_chset_convert(CHSET_UTF8, CHSET_UCS2, 
                    (char*)u8ValBuf, 
                    (char*)u8TmpBuf, 
                    (kal_int32)(APE_READ_BUFFER_SIZE + 2));
                if (s32Tmp > 2)
                {
                    s32Tmp -= 2;
                    if (s32Tmp > META_TAG_FRAME_MAX_SIZE)
                    {
                        s32Tmp = META_TAG_FRAME_MAX_SIZE;
                    }
                    pBuffer = pInternal->func_p->tag_getbuffer(metaID, s32Tmp);
                    ASSERT(NULL != pBuffer);
                    memcpy(pBuffer, u8TmpBuf, s32Tmp);

                    pInternal->music_info.txt_frame[u8FrameID].data = 
                        (kal_uint16*)pBuffer;
                    pInternal->music_info.txt_frame[u8FrameID].data_size = 
                        (kal_uint16)s32Tmp;    
                    pInternal->music_info.txt_frame[u8FrameID].data_encoding = 
                        META_TAG_TEXT_ENCODING_UCS2;
                }
            }
        }        
        u32Item--;
        /*
        *   the attributes meet our requirement, so break
        */
        if ((u32Attr & META_TAG_ATTR_APE) == META_TAG_ATTR_APE)
        {
            break;
        }
    }
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  tag_get_key_index
 * DESCRIPTION
 *  get ape tag type 
 * PARAMETERS
 *  pbuffer     [IN]        stream data
 *  size        [IN]        data size
 * RETURNS
 *  ape_tag_frame_enum, 
 *****************************************************************************/
static  kal_uint8 tag_get_key_index(kal_uint8* pbuffer, kal_uint8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for (i = 0; i < size; i++)
    {
        if (pbuffer[i] >= 'a' && pbuffer[i] <= 'z')
        {
            pbuffer[i] -= 'a'-'A'; 
        }
        if (0 == pbuffer[i])
        {
            break;
        }
    }
    if (i == size)
    {
        return  META_TAG_APE_ATTR_NUMBER;
    }

    for (i = 0; i < META_TAG_APE_ATTR_NUMBER; i++)
    {
        if (0 == strncmp((char*)pbuffer, g_ape_key[i].key_string, g_ape_key[i].key_len) &&
            strlen((char*)g_ape_key[i].key_string) == strlen((char*)pbuffer))
        {
            break;
        }
    }
    return  (kal_uint8)i;
}
#endif  /*#if defined(__TAG_SUPPORT_APE__)*/


