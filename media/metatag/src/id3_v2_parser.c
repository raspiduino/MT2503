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
*  id3_v2_parser.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   id3 v2 parsing definitions
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
#include "Conversions.h"
#include "app_str.h"

#include "id3_v2_parser.h"
#include "id3_v1_parser.h"

#if defined(__TAG_SUPPORT_ID3V2__)
/*  define macro 
*/
#define ID3_FRAME_HEADER_SIZE       ID3_TAG_V2_4_FRAME_HEADER_SIZE
/*
*   there my has unicode, so the read size should be frame max len*encoding len;
*   except frame has fix size header 10 byes, there also may has frame internal 
*   head, such as comment frame, has language and description before content;
*   so double the header size, but it still can't full match frame has 81 chars.
*/
#define ID3_READ_BUFFER_SIZE        (META_TAG_FRAME_MAX_SIZE+ID3_FRAME_HEADER_SIZE*2)
#define ID3_FRAME_BUFFER_SIZE       META_TAG_FRAME_MAX_SIZE
#define ID3_IMAGE_MIME_TYPE_LEN     10/*image/jpeg*/
#define ID3_IMAGE_MIN_TITLE_LEN     7
#define ID3_FRAME_MIN_SIZE          1

/*  define data struct
*/
typedef struct
{   
    id3_v2_tag_frame_hdr_struct     *frmhdr;
    meta_tag_internal_info_struct   *pInternal;

    kal_uint32 frame_location;
    kal_uint8* pData;
    kal_uint32 dataSize;
    kal_uint8* pBuffer;
    kal_uint32 bufferSize;
    kal_uint32 metaID;
    
}   id3_v2_tag_frame_parse_struct;

/*  define global variable
*/
static  const id3_v2_tag_frame_key_struct g_id3v2_key[META_TAG_ID3_V2_ATTR_NUMBER] = 
{
    {{"TT2", "TIT2", "TIT2"}, META_TAG_FRAME_TITLE },        
    {{"TP1", "TPE1", "TPE1"}, META_TAG_FRAME_ARTIST},
    {{"TCM", "TCOM", "TCOM"}, META_TAG_FRAME_AUTHOR},
    {{"TAL", "TALB", "TALB"}, META_TAG_FRAME_ALBUM },        
    {{"COM", "COMM", "COMM"}, META_TAG_FRAME_DESCRIPTION},
    {{"TCO", "TCON", "TCON"}, META_TAG_FRAME_GENRE }, 
    {{"TCR", "TCOP", "TCOP"}, META_TAG_FRAME_COPYRIGHT  },
    {{"TYE", "TYER", "TDRC"}, META_TAG_FRAME_YEAR },        
    {{"TRK", "TRCK", "TRCK"}, META_TAG_FRAME_TRACKNUM },
#ifdef __TAG_SUPPORT_WRITE_BACK__
    {{"POP", "POPM", "POPM"}, META_TAG_FRAME_RATING },
#endif
    //{{"SLT", "SYLT", "SYLT"}, META_TAG_FRAME_SYNCLYRICS },
    {{"PIC", "APIC", "APIC"}, META_TAG_FRAME_PICTURE }
};

/*  define function
*/
static kal_uint8   tag_parse_frames(
                kal_uint32 metaID, 
                meta_tag_internal_info_struct* pInternal
                );
static kal_uint8   tag_parse_frame_hdr(
                kal_uint8 hdrVersion,
                id3_v2_tag_frame_hdr_struct* pFrmHdr, 
                kal_uint8* pData
                );
static kal_uint8   tag_parse_frame_data(
                id3_v2_tag_frame_parse_struct* pGet
                );
static kal_uint8   tag_parse_single_frame(
                kal_uint32 metaID, 
                kal_uint8* pBuffer, 
                kal_uint32 bufferSize,
                meta_tag_internal_info_struct* pInternal,
                id3_v2_tag_frame_single_parse_struct* pInfo
                );
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static kal_uint8   tag_parse_image_frame_data(
                id3_v2_tag_frame_parse_struct* pGet
                );
#ifdef __TAG_SUPPORT_WRITE_BACK__
static kal_uint8  tag_parse_rating_frame_data(
                id3_v2_tag_frame_parse_struct* pGet
                );

kal_uint8 id3_tag_v2_parse_to_write(kal_uint32 metaID, meta_tag_internal_info_struct* pInternal);
static  kal_uint8  tag_write_frames_rating(kal_uint32 metaID, meta_tag_internal_info_struct* pInternal);
static kal_uint8  tag_parse_rewirte_frame_data(id3_v2_tag_frame_parse_struct *pGet);
#endif/* __TAG_SUPPORT_WRITE_BACK__ */

static kal_uint32  tag_reverse_unsync(
                kal_uint8 *buffer, 
                kal_uint32 size, 
                kal_uint32 *runSize, 
                kal_uint32 brkSize
                );
static kal_uint8   tag_get_frame_index(
                kal_uint8 hdrVersion, 
                kal_uint8* frameID
                );
static kal_uint8   tag_get_image_priority(
                kal_uint8 image_type
                );

/*****************************************************************************
 * FUNCTION
 *  id3_tag_v2_parse
 * DESCRIPTION
 *  parse id3 v2 meta 
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pInternal   [OUT]       meta tag detail information
 * RETURNS
 *  success return META_TAG_ERR_NONE,
 *****************************************************************************/
kal_uint8 id3_tag_v2_parse(kal_uint32 metaID, meta_tag_internal_info_struct* pInternal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    id3_v2_tag_hdr_struct   ahdr;
    kal_uint32 u32Tmp;
    kal_uint8  u8HdrBuf[ID3_TAG_V2_HEADER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    u32Tmp = pInternal->func_p->tag_read(
        metaID, u8HdrBuf, ID3_TAG_V2_HEADER_SIZE);

    if (u32Tmp != ID3_TAG_V2_HEADER_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    /*  
    *   ID3v2/file identifier      "ID3"
    *   ID3v2 version               $04 00
    *   ID3v2 flags                 %abcd0000
    *   ID3v2 size                  4 * %0xxxxxxx
    */
    if (0 != memcmp(u8HdrBuf, ID3_TAG_V2_MAGIC_ID, ID3_TAG_V2_MAGIC_SIZE))
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, 0);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (0 != u8HdrBuf[4])
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[4]);

        return  META_TAG_ERR_NOT_SUPPORT;
    } 
    ahdr.size       = META_TAG_GET_UNSYNC_U32_BE(u8HdrBuf+6);
    ahdr.flags      = u8HdrBuf[5];
    ahdr.version    = u8HdrBuf[3];

    switch(ahdr.version)/*this is version bytes*/
    {
    case 2:
        /*  
        *   it's illegal that the zero bits has value,
        *   currently, can't support compress tag.
        */
        if (ahdr.flags & (ID3_TAG_V2_2_FLAG_ZERO|ID3_TAG_V2_2_FLAG_COMPRESS))
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.flags);

            return  META_TAG_ERR_NOT_SUPPORT;
        }
        break;
    case 3:
        
        if (ahdr.flags & ID3_TAG_V2_3_FLAG_ZERO)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.flags);

            return  META_TAG_ERR_NOT_SUPPORT;
        }
        /*
        *   parse extend header information, 
        *   this information just skipped 
        */
        if (ahdr.flags & ID3_TAG_V2_3_FLAG_EXT_HEADER)
        {
            u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 
                ID3_TAG_V2_HEADER_SIZE);
            if (u32Tmp != ID3_TAG_V2_HEADER_SIZE)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            ahdr.exthdr.size    = META_TAG_GET_U32_BE(u8HdrBuf);
            ahdr.exthdr.flags   = META_TAG_GET_U16_BE(&u8HdrBuf[4]);
            if (ahdr.exthdr.flags & ID3_TAG_V2_3_EXT_FLAG_ZERO)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.exthdr.flags);

                return  META_TAG_ERR_NOT_SUPPORT;
            }
            ahdr.exthdr.padding_size    = META_TAG_GET_U32_BE(&u8HdrBuf[6]);
            if (ahdr.exthdr.flags & ID3_TAG_V2_3_EXT_FLAG_CRC)
            {
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 4);
                if (u32Tmp != 4)
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                ahdr.exthdr.crc = META_TAG_GET_U32_BE(u8HdrBuf);
            }
        }
        break;
    case 4:
       
        if (ahdr.flags & ID3_TAG_V2_4_FLAG_ZERO)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.flags);

            return  META_TAG_ERR_NOT_SUPPORT;
        }
        if (ahdr.flags & ID3_TAG_V2_4_FLAG_EXT_HEADER)
        {
            u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 6);
            if (u32Tmp != 6)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            if ((1 != u8HdrBuf[4]) || /*the flag numbers must be 1*/
                (u8HdrBuf[5] & ID3_TAG_V2_4_EXT_FLAG_ZERO))
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[4]);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            ahdr.exthdr.size    = META_TAG_GET_U32_BE(u8HdrBuf);
            ahdr.exthdr.flags   = u8HdrBuf[5];
            if (ahdr.exthdr.flags & ID3_TAG_V2_4_EXT_FLAG_UPDATE)
            {
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 1);
                if (u32Tmp != 1 || 0 != u8HdrBuf[0])
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[0]);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
            }
            if (ahdr.exthdr.flags & ID3_TAG_V2_4_EXT_FLAG_CRC)
            {
                /*
                *   CRC value can't be check, if the whole data can't be received.
                */
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 6);
                if (u32Tmp != 6 || 5 != u8HdrBuf[0])
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[0]);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                ahdr.exthdr.crc = META_TAG_GET_UNSYNC_U35_BE(&u8HdrBuf[1]);
            }
            if (ahdr.exthdr.flags & ID3_TAG_V2_4_EXT_FLAG_RESTRICTIONS)
            {
                /*
                *   just ignore this flags! and the data length should be 1
                */
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 2);
                if (u32Tmp != 2 || 1 != u8HdrBuf[0])
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[0]);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                ahdr.exthdr.restrictions    = u8HdrBuf[1];
            }
        }
        break;
    default:
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, 0);

        return  META_TAG_ERR_NOT_SUPPORT;
    }
    pInternal->hdr_flags    = ahdr.flags;
    pInternal->hdr_version  = ahdr.version;
    pInternal->hdr_size     = ahdr.size;

    return  tag_parse_frames(metaID, pInternal);
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_v2_parse_attach_cover
 * DESCRIPTION
 *  parse id3 v2 meta picture information
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pBuffer     [IN]        function for input
 *  bufferSize  [IN/OUT]    information for output
 *  pInternal   [OUT]       meta tag detail format
 * RETURNS
 *  success return META_TAG_ERR_NONE,
 *****************************************************************************/
kal_uint8 id3_tag_v2_parse_attach_cover(
                kal_uint32 metaID, 
                kal_uint8* pBuffer, 
                kal_uint32 bufferSize,
                meta_tag_internal_info_struct* pInternal
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    id3_v2_tag_frame_single_parse_struct     frmInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frmInfo.data_offset = pInternal->image_info.data_offset;
    frmInfo.data_size   = pInternal->image_info.data_size;
    frmInfo.frame_ID    = META_TAG_FRAME_PICTURE;

    return  tag_parse_single_frame(metaID, pBuffer, bufferSize, 
        pInternal, &frmInfo);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  tag_parse_single_frame
 * DESCRIPTION
 *  get frame data
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pBuffer     [IN]        function for input
 *  bufferSize  [IN/OUT]    information for output
 *  pInternal   [OUT]       meta tag detail format
 *  pInfo       [IN]        frame information
 * RETURNS
 *  success return META_TAG_ERR_NONE,
 *****************************************************************************/
static kal_uint8   tag_parse_single_frame(
                    kal_uint32 metaID, 
                    kal_uint8* pBuffer, 
                    kal_uint32 bufferSize,
                    meta_tag_internal_info_struct* pInternal,
                    id3_v2_tag_frame_single_parse_struct* pInfo
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    id3_v2_tag_frame_hdr_struct     frameHdr;
    kal_int32 s32Tmp, s32Read, s32DataSize, s32Skip, s32ToGet;
    kal_uint8  u8TmpBuf[ID3_READ_BUFFER_SIZE];
    kal_uint8  u8Unsync, u8HdrSize, u8Tmp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bufferSize < ID3_FRAME_HEADER_SIZE)
    {
        /*need add error log*/
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, bufferSize);

        return  META_TAG_ERR_NOT_ENOUGH_BUFFER;
    }
    switch(pInternal->hdr_version)
    {
    case 2: 
        
        u8Unsync    = pInternal->hdr_flags & ID3_TAG_V2_2_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_2_FRAME_HEADER_SIZE;
        break;
    case 3:
        
        u8Unsync    = pInternal->hdr_flags & ID3_TAG_V2_3_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_3_FRAME_HEADER_SIZE;
        break;
    case 4:   
        
        u8Unsync    = pInternal->hdr_flags & ID3_TAG_V2_4_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_4_FRAME_HEADER_SIZE;
        break;
    default:        ASSERT(0);

        u8Unsync    = 0;
        u8HdrSize   = 0;
        break;
    }
    s32Read  = pInternal->func_p->tag_read(metaID, u8TmpBuf, ID3_READ_BUFFER_SIZE);
    if (s32Read <= u8HdrSize+ID3_IMAGE_MIN_TITLE_LEN)
    {
        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (u8Unsync)
    {        
        s32DataSize = tag_reverse_unsync(u8TmpBuf, s32Read, NULL, s32Read);
        if (s32DataSize <= u8HdrSize+ID3_IMAGE_MIN_TITLE_LEN)
        {
            return  META_TAG_ERR_INVAILD_DATA;
        }
    }
    else
    {
        s32DataSize = s32Read;
    }    
    u8Tmp = tag_parse_frame_hdr(pInternal->hdr_version, 
            &frameHdr, u8TmpBuf);  
    
    if (u8Tmp != ID3_TAG_FRAME_ERR_NONE)
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8Tmp);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    frameHdr.index = tag_get_frame_index(pInternal->hdr_version,
        frameHdr.id);
    if (frameHdr.index >= META_TAG_ID3_V2_ATTR_NUMBER)
    {
        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (g_id3v2_key[frameHdr.index].key_frameID != pInfo->frame_ID)
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, pInfo->frame_ID);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    s32ToGet    = u8HdrSize+frameHdr.data_offset;
    s32DataSize -= s32ToGet;

    if ((0 != u8Unsync) && (4 == pInternal->hdr_version) &&
        (frameHdr.flags & ID3_TAG_V2_4_FRAME_FLAG_UNSYNCH))
    {
        u8Unsync = 1;
        s32DataSize = tag_reverse_unsync(u8TmpBuf+s32ToGet, s32DataSize, 
            NULL, s32DataSize);
    }
    /*
    *   use s32read to record real read frame size, not including 10 frame header;
    */
    s32Read     = frameHdr.data_offset;

    if (s32DataSize >= pInfo->data_offset)
    {
        s32Skip = 0;
        s32DataSize -= pInfo->data_offset;
        if (s32DataSize > bufferSize)
        {
            /* MAUI_02953619: Image data size maybe smaller than read buffer size */
            s32DataSize = bufferSize;
        }        
        memcpy(pBuffer, u8TmpBuf+s32ToGet+pInfo->data_offset,
            s32DataSize);
    }
    else
    {
        s32Skip = pInfo->data_offset-s32DataSize;
        s32DataSize = 0;
    }
    
    while (s32Skip > 0)
    {
        if (u8Unsync)
        {        
            s32ToGet = frameHdr.size-s32Read;
            if (s32ToGet > ID3_READ_BUFFER_SIZE)
                s32ToGet = ID3_READ_BUFFER_SIZE;

            s32Tmp  = pInternal->func_p->tag_read(metaID, u8TmpBuf, s32ToGet);
            if (s32Tmp != s32ToGet)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            s32Tmp = tag_reverse_unsync(u8TmpBuf, s32ToGet, NULL, s32ToGet);
            s32Read += s32Tmp;

            if (s32Tmp >= s32Skip)
            {
                s32DataSize = s32Tmp - s32Skip;
                s32Skip = 0;

                memcpy(pBuffer, u8TmpBuf+s32Skip, s32DataSize);
            }
            else
            {
                s32Skip -= s32Tmp;
            }
        }
        else
        {
            s32Tmp = pInternal->func_p->tag_seek(metaID, s32Skip, FUNC_SEEK_CUR);
            if (s32Tmp < 0)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            s32Read += s32Skip;
            s32Skip = 0;
        }
    }
    
    while (s32DataSize < (kal_int32)pInfo->data_size)
    {
        s32ToGet = pInfo->data_size-s32DataSize;    
        s32Tmp   = pInternal->func_p->tag_read(metaID, pBuffer+s32DataSize, s32ToGet);
        if (s32Tmp != s32ToGet)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

            return  META_TAG_ERR_INVAILD_DATA;
        }
        if (u8Unsync)
        {
            s32Tmp = tag_reverse_unsync(pBuffer+s32DataSize, 
                s32Tmp, NULL, s32Tmp);
            if (0 == s32Tmp)
            {
                return META_TAG_ERR_INVAILD_DATA;
            }
        }
        s32DataSize += s32Tmp;
    }
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  tag_parse_frames
 * DESCRIPTION
 *  parse id3 frames data 
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pInternal   [IN/OUT]    information for output
 * RETURNS
 *  success return META_TAG_ERR_NONE,
 *****************************************************************************/
static  kal_uint8  tag_parse_frames(
                kal_uint32 metaID, 
                meta_tag_internal_info_struct* pInternal
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    id3_v2_tag_frame_hdr_struct     frameHdr;
    id3_v2_tag_frame_parse_struct   frameGet;

    kal_uint32 u32Loaction, u32Ret, u32Read, u32ToGet, u32Got, u32Skip;
    kal_uint32 u32ParseSize, u32RunSize;
    kal_int32 s32Tmp;
    kal_uint8  u8TmpBuf[ID3_READ_BUFFER_SIZE+2];/*add two bytes for padding zero*/
    kal_uint8  u8FrameBuf[ID3_FRAME_BUFFER_SIZE+2];
    kal_uint8  u8Unsync, u8HdrSize, u8Tmp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    frameGet.bufferSize = ID3_FRAME_BUFFER_SIZE;
    frameGet.pBuffer    = u8FrameBuf;
    frameGet.frmhdr     = &frameHdr;
    frameGet.metaID     = metaID;
    frameGet.pInternal  = pInternal;

    switch(pInternal->hdr_version)
    {
    case 2: 
        
        u8Unsync    = ID3_TAG_V2_2_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_2_FRAME_HEADER_SIZE;
        break;
    case 3:

        u8Unsync    = ID3_TAG_V2_3_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_3_FRAME_HEADER_SIZE;
        break;
    case 4:   
        
        u8Unsync    = ID3_TAG_V2_4_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_4_FRAME_HEADER_SIZE;
        break;
    default:        ASSERT(0);

        u8Unsync    = 0;
        u8HdrSize   = 0;
        break;
    }

    u32Read     = 0;
    u32Got      = 0;
    u32Skip     = 0;
    u32ToGet    = ID3_READ_BUFFER_SIZE;
    if (u32ToGet > pInternal->hdr_size)
    {
        u32ToGet = pInternal->hdr_size;
    }
    /*
    *   to get current frame location in data stream
    */
    u32ParseSize= 0;
    u32Loaction = pInternal->func_p->tag_getlocation(metaID);

    while (u32ParseSize < pInternal->hdr_size)
    {
        if (0 != u32ToGet)
        {
            if ((u32Skip > 0) && !(pInternal->hdr_flags & u8Unsync))
            {
                /*
                *   sync mode, just use seek function to find next frame!
                */
                /*
                *   it's terrible when the meta data has picture & used unsync!
                *   how to get picture location!
                */
                s32Tmp = pInternal->func_p->tag_seek(metaID, u32Skip, FUNC_SEEK_CUR);
                if (s32Tmp < 0)
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                u32ParseSize += u32Skip;
                u32Read += u32Skip;
                u32Skip = 0;
                u32ToGet    = ID3_READ_BUFFER_SIZE;
                if (u32ToGet + u32Read > pInternal->hdr_size)
                {
                    u32ToGet = pInternal->hdr_size - u32Read;
                }
            }
            u32Ret = pInternal->func_p->tag_read(metaID, u8TmpBuf+u32Got, u32ToGet);
            if (u32Ret != u32ToGet)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Ret);

                return  META_TAG_ERR_INVAILD_DATA;
            }      
            u32Read += u32Ret;
            
            if (u32Skip > 0)
            {
                if (pInternal->hdr_flags & u8Unsync)
                {                
                    s32Tmp  = tag_reverse_unsync(u8TmpBuf+u32Got, u32Ret,
                        &u32RunSize, u32Skip);
                }
                else
                {
                    if (u32Skip > u32Ret)
                    {
                        u32RunSize = u32Ret;//used in file size
                    }
                    else
                    {
                        u32RunSize = u32Skip;
                    }
                    s32Tmp  = u32Ret;   //valid data size
                }
                u32ParseSize += u32RunSize;

                if (u32RunSize == u32Ret)
                {
                    u32Skip     -= s32Tmp;
                    u32ToGet    = ID3_READ_BUFFER_SIZE;
                    if (u32ToGet + u32Read > pInternal->hdr_size)
                    {
                        u32ToGet = pInternal->hdr_size - u32Read;
                    }
                    u32Got      = 0;
                    continue;
                }
                u32Got  = u32Ret-u32RunSize;
                u32Skip = 0;

                memcpy(u8TmpBuf, u8TmpBuf+u32RunSize, u32Got);
                u32ToGet = ID3_READ_BUFFER_SIZE-u32Got;
                if (u32ToGet > pInternal->hdr_size - u32Read)
                {
                    u32ToGet = pInternal->hdr_size - u32Read;
                }
                continue;
            }
            u32Got += u32Ret;
        }
        if (u32Got <= u8HdrSize)
        {
            /*
            *   data not enough, may has error
            */
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Got);
            break;
        }
        /*
        *   parse frame header
        */
        if (pInternal->hdr_flags & u8Unsync)
        {                
            u32Ret  = tag_reverse_unsync(u8TmpBuf, u32Got,
                &u32RunSize, u8HdrSize);
            if (u32Ret < u8HdrSize)
            {
                /*
                *   data not enough, may has error
                */
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Ret);
                break;
            }
        }
        else
        {
            u32RunSize = u8HdrSize;
        }
        u8Tmp = tag_parse_frame_hdr(pInternal->hdr_version, 
            &frameHdr, u8TmpBuf);        

        if (u8Tmp == ID3_TAG_FRAME_ERR_NONE)
        {
            frameHdr.index = tag_get_frame_index(pInternal->hdr_version, 
                frameHdr.id);
        }
        else
        {            
            frameHdr.index = META_TAG_ID3_V2_ATTR_NUMBER;
        }
        if (frameHdr.size < ID3_FRAME_MIN_SIZE)
        {   
            /*
            *   maybe follow the padding data;
            */
            break;
        }

        if (META_TAG_ID3_V2_ATTR_NUMBER > frameHdr.index)
        {
            /*
            *   calc frame header start position;
            */
            frameGet.frame_location = u32Loaction + u32Read-u32Got;
            s32Tmp = u32RunSize;

            if (pInternal->hdr_flags & u8Unsync)
            {                
                u32Ret  = tag_reverse_unsync(u8TmpBuf+s32Tmp, u32Got-s32Tmp,
                    &u32RunSize, frameHdr.size);

            
                u32Skip = frameHdr.size - u32Ret;/*Skip data which cann't match in buffer*/
            }
            else
            {
                if (frameHdr.size >= u32Got-s32Tmp)
                {
                    u32RunSize  = u32Got-s32Tmp;
                    u32Skip     = frameHdr.size - u32RunSize; 
                    /*Skip data which cann't match in buffer*/
                    /*the huge frame, such as lyrics or artwork, must be skip from there*/
                    /*maybe we can break, and use information in id3v1*/
                }
                else
                {
                    u32Skip     = 0;
                    u32RunSize  = frameHdr.size;
                }
                u32Ret = u32RunSize;                
            }
            frameGet.dataSize   = u32Ret;
            frameGet.pData      = u8TmpBuf+s32Tmp+frameHdr.data_offset;
            tag_parse_frame_data(&frameGet);

            u32RunSize += s32Tmp;
        }
        else
        {
            if (pInternal->hdr_flags & u8Unsync)
            {
                u32Skip = frameHdr.size;
            }
            else
            {
                if (u32Got - u32RunSize > frameHdr.size)
                {
                    u32RunSize += frameHdr.size;
                }
                else
                {
                    u32Skip = frameHdr.size-(u32Got-u32RunSize);
                    u32RunSize = u32Got;
                }
            }            
        }
        /*
        *   Skip the unsupported frame or the frame may not all parsed!
        */     
        if (u32Got > u32RunSize)
        {
            u32Got -= u32RunSize;
            memcpy(u8TmpBuf, u8TmpBuf+u32RunSize, u32Got);
        }
        else
        {
            u32Got  = 0;
        }
        u32ToGet = ID3_READ_BUFFER_SIZE-u32Got;
        if (u32ToGet + u32Read > pInternal->hdr_size)
        {
            u32ToGet = pInternal->hdr_size - u32Read;
        }
        u32ParseSize += u32RunSize;
    }    
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  tag_parse_frame_hdr
 * DESCRIPTION
 *  parse id3 frame header information 
 * PARAMETERS
 *  hdrVersion  [IN]        meta header version information
 *  pFrmHdr     [OUT]       meta frame header information
 *  pData       [IN]        meta data
 * RETURNS
 *  success return ID3_TAG_FRAME_ERR_NONE
 *****************************************************************************/
static kal_uint8 tag_parse_frame_hdr(
                kal_uint8 hdrVersion,
                id3_v2_tag_frame_hdr_struct* pFrmHdr,
                kal_uint8* pData
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    pFrmHdr->data_offset = 0;

    switch(hdrVersion)
    {
    case 2:

        memcpy(pFrmHdr->id, pData, 3);
        pFrmHdr->size   = META_TAG_GET_UNSYNC_U24_BE(pData+3);
        pFrmHdr->flags  = 0;
        break;
    case 3:

        memcpy(pFrmHdr->id, pData, 4);
        /*it's special in version 2.3 for frame size*/
        pFrmHdr->size   = META_TAG_GET_U32_BE(pData+4);
        pFrmHdr->flags  = META_TAG_GET_U16_BE(pData+8);

        if (pFrmHdr->flags & ID3_TAG_V2_3_FRAME_FLAG_ZERO)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, pFrmHdr->flags);

            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        if (pFrmHdr->flags & (
            ID3_TAG_V2_3_FRAME_FLAG_TAG_PRESERV|ID3_TAG_V2_3_FRAME_FLAG_FILE_PRESERV|
            ID3_TAG_V2_3_FRAME_FLAG_COMPRESS|ID3_TAG_V2_3_FRAME_FLAG_ENCRYPT
            ))
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, pFrmHdr->flags);

            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        if (pFrmHdr->flags & ID3_TAG_V2_3_FRAME_FLAG_GROUP_ID)
        {
            pFrmHdr->data_offset++;
        }
        break;
    case 4:

        memcpy(pFrmHdr->id, pData, 4);
        pFrmHdr->size   = META_TAG_GET_U32_BE(pData+4);
        pFrmHdr->flags  = META_TAG_GET_U16_BE(pData+8);

        if (pFrmHdr->flags & ID3_TAG_V2_4_FRAME_FLAG_ZERO)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, pFrmHdr->flags);

            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        if (pFrmHdr->flags & (
            ID3_TAG_V2_4_FRAME_FLAG_TAG_PRESERV|ID3_TAG_V2_4_FRAME_FLAG_FILE_PRESERV|
            ID3_TAG_V2_4_FRAME_FLAG_COMPRESS|ID3_TAG_V2_4_FRAME_FLAG_ENCRYPT
            ))
        {
            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        if (pFrmHdr->flags & ID3_TAG_V2_4_FRAME_FLAG_GROUP_ID)
        {
            pFrmHdr->data_offset++;
        }
        break;
    default:    ASSERT(0);
        break;
    }
    return  ID3_TAG_FRAME_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  tag_reverse_unsync
 * DESCRIPTION
 *  revise unsync data to sync data 
 * PARAMETERS
 *  buffer      [IN]        
 *  size        [IN]        
 *  runSize     [OUT] runging size
 *  brkSize     [In] break runing size
 * RETURNS
 *  success return real data size
 *****************************************************************************/
static kal_uint32  tag_reverse_unsync(kal_uint8 *buffer, kal_uint32 size, kal_uint32 *runSize, kal_uint32 brkSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8  *psrc, *pdst;
    kal_uint32 i, n;
    kal_uint8  u8Prev = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    psrc    = buffer;
    pdst    = NULL;
    i       = 0;
    n       = size;

    while (n > 1 && i < brkSize)
    {
        n--;
        i++;
        if (psrc[0] == 0xff && psrc[1] == 0x00)
        {
            psrc++;            
            pdst = psrc;
            u8Prev = *psrc++;
            n--;
            break;
        }
        psrc++;        
    }
    if (NULL == pdst)
    {
        if (NULL != runSize)
        {
            *runSize = size-n;
        }
        return  i;
    }
    while (n > 0 && i < brkSize)
    {
        n--;
        if (u8Prev != 0xff || *psrc != 0x00)
        {
            *pdst++ = *psrc; 
            i++;
        }
        u8Prev = *psrc++;        
    }    
    if (NULL != runSize)
    {
        *runSize = size-n;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  tag_get_frame_index
 * DESCRIPTION
 *  get id3 frame id
 * PARAMETERS
 *  hdrVersion  [IN]     
 *  frameID     [IN]
 * RETURNS
 *  success return frame index
 *****************************************************************************/
static kal_uint8   tag_get_frame_index(kal_uint8 hdrVersion, kal_uint8* frameID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8  i, n, k = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    k = hdrVersion-2;
    n = (0 == k) ? 3 : 4;

    for (i = 0; i < META_TAG_ID3_V2_ATTR_NUMBER; i++)
    {
        if (0 == strncmp((const char*)frameID, g_id3v2_key[i].key_string[k], n))
        {
            break;
        }
    }
    return  i;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  tag_parse_image_frame_data
 * DESCRIPTION
 *  parse id3 image frame data information 
 *      Text encoding      $xx
 *      MIME type          <text string> $00
 *      Picture type       $xx
 *      Description        <text string according to encoding> $00 (00)
 *      Picture data       <binary data>
 * PARAMETERS
 *  pGet        
 * RETURNS
 *  success return ID3_TAG_FRAME_ERR_NONE
 *****************************************************************************/
static kal_uint8   tag_parse_image_frame_data(id3_v2_tag_frame_parse_struct* pGet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 s32Tmp, s32Size;
    kal_uint8 u8Tmp, u8Type, u8Terminator;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    META_GET_TERMINATOR_LEN(pGet->pData[0], u8Terminator);

    if (2 == pGet->pInternal->hdr_version)
    {
        /*
        *   use 'PNG'/'JPG' just 3 bytes define image type
        */
        s32Size = 4;/*3 bytes format+1 byte text encoding format*/
    }
    else
    {
        /*
        *   find string type in data, encoding type META_TAG_TEXT_ENCODING_ISO_8859_1;
        */
        s32Tmp = meta_tag_find_terminator(&pGet->pData[1], pGet->dataSize-1,
            META_TAG_TEXT_ENCODING_ISO_8859_1);
        
        if (s32Tmp <= 0 || s32Tmp > ID3_IMAGE_MIME_TYPE_LEN || 
            s32Tmp >= (kal_int32)pGet->dataSize)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        s32Size = s32Tmp+1;/*add 1 byte for text encoding format*/
        s32Size += 1; // u8Terminator;
    }
    u8Tmp = tag_get_image_priority(pGet->pData[s32Size]); 

    if (u8Tmp > pGet->pInternal->image_info.priority)
    {            
        s32Size++;
        /*
        *   skip the description, which before the image data
        */
        s32Tmp  = meta_tag_find_terminator(&pGet->pData[s32Size], 
            pGet->dataSize-s32Size, pGet->pData[0]);
        if (s32Tmp < 0 )
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        u8Type  = meta_tag_get_image_type(&pGet->pData[1], s32Size-2);
        if (u8Type >= META_TAG_IMG_TOTAL)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8Type);

            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        pGet->pInternal->image_info.priority = u8Tmp;   
        pGet->pInternal->image_info.frame_location = pGet->frame_location;
        pGet->pInternal->image_info.data_offset = 
            pGet->frmhdr->data_offset+s32Size+s32Tmp+u8Terminator;
        pGet->pInternal->image_info.data_size   = 
            pGet->frmhdr->size - pGet->pInternal->image_info.data_offset;
        pGet->pInternal->image_info.mime_type   = u8Type;
    }
    return  ID3_TAG_FRAME_ERR_NONE;
}

#ifdef __TAG_SUPPORT_WRITE_BACK__
/*****************************************************************************
 * FUNCTION
 *  tag_parse_rating_frame_data
 * DESCRIPTION
 *  parse id3 rating frame data information 
 *      Email to user	<text string> $00
 *      rating         	$xx
 *      counter        	$xx xx xx xx (xx ...)
  * PARAMETERS
 *  pGet        
 * RETURNS
 *  success return ID3_TAG_FRAME_ERR_NONE
 *****************************************************************************/
static kal_uint8  tag_parse_rewirte_frame_data(id3_v2_tag_frame_parse_struct *pGet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32   i = 0;
    kal_uint8   tmp[4];
    kal_uint32  tmp32;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(i < pGet->dataSize)
    {
        if (0 == pGet->pData[i])
        {
            break;
        }
        i++;
    }
    if (i >= pGet->dataSize)
    {
        return ID3_TAG_FRAME_ERR_NOT_SUPPORT;
    }

    pGet->pData[++i] = pGet->pInternal->music_info.user_rate;
   

    if (pGet->dataSize - i >= 4)
    {
        memcpy((char*)tmp, (char*)&pGet->pInternal->music_info.play_count, 4 );
        tmp32 = META_TAG_GET_U32_BE(tmp);
        memcpy((char*)(pGet->pData + pGet->dataSize - 4), (char *)&tmp32, 4);
    }
    return ID3_TAG_FRAME_ERR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  tag_parse_rating_frame_data
 * DESCRIPTION
 *  parse id3 rating frame data information 
 *      Email to user	<text string> $00
 *      rating         	$xx
 *      counter        	$xx xx xx xx (xx ...)
  * PARAMETERS
 *  pGet        
 * RETURNS
 *  success return ID3_TAG_FRAME_ERR_NONE
 *****************************************************************************/
static kal_uint8  tag_parse_rating_frame_data(id3_v2_tag_frame_parse_struct *pGet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32   i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(i < pGet->dataSize)
    {
        if (0 == pGet->pData[i])
        {
            break;
        }
        i++;
    }
    if (i >= pGet->dataSize)
    {
        return ID3_TAG_FRAME_ERR_NOT_SUPPORT;
    }

    pGet->pInternal->music_info.user_rate = pGet->pData[++i];

    if (pGet->dataSize - i >= 4)
    {
        pGet->pInternal->music_info.play_count = META_TAG_GET_U32_BE(pGet->pData + pGet->dataSize - 4);
    }
    else
    {
        pGet->pInternal->music_info.play_count = 0;
    }
    return ID3_TAG_FRAME_ERR_NONE;
}

kal_uint8 id3_tag_v2_parse_to_write(kal_uint32 metaID, meta_tag_internal_info_struct* pInternal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    id3_v2_tag_hdr_struct   ahdr;
    kal_uint32 u32Tmp;
    kal_uint8  u8HdrBuf[ID3_TAG_V2_HEADER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    u32Tmp = pInternal->func_p->tag_read(
        metaID, u8HdrBuf, ID3_TAG_V2_HEADER_SIZE);

    if (u32Tmp != ID3_TAG_V2_HEADER_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    /*  
    *   ID3v2/file identifier      "ID3"
    *   ID3v2 version               $04 00
    *   ID3v2 flags                 %abcd0000
    *   ID3v2 size                  4 * %0xxxxxxx
    */
    if (0 != memcmp(u8HdrBuf, ID3_TAG_V2_MAGIC_ID, ID3_TAG_V2_MAGIC_SIZE))
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, 0);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (0 != u8HdrBuf[4])
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[4]);

        return  META_TAG_ERR_NOT_SUPPORT;
    } 
    ahdr.size       = META_TAG_GET_UNSYNC_U32_BE(u8HdrBuf+6);
    ahdr.flags      = u8HdrBuf[5];
    ahdr.version    = u8HdrBuf[3];

    switch(ahdr.version)/*this is version bytes*/
    {
    case 2:
        /*  
        *   it's illegal that the zero bits has value,
        *   currently, can't support compress tag.
        */
        if (ahdr.flags & (ID3_TAG_V2_2_FLAG_ZERO|ID3_TAG_V2_2_FLAG_COMPRESS))
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.flags);

            return  META_TAG_ERR_NOT_SUPPORT;
        }
        break;
    case 3:
        
        if (ahdr.flags & ID3_TAG_V2_3_FLAG_ZERO)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.flags);

            return  META_TAG_ERR_NOT_SUPPORT;
        }
        /*
        *   parse extend header information, 
        *   this information just skipped 
        */
        if (ahdr.flags & ID3_TAG_V2_3_FLAG_EXT_HEADER)
        {
            u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 
                ID3_TAG_V2_HEADER_SIZE);
            if (u32Tmp != ID3_TAG_V2_HEADER_SIZE)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            ahdr.exthdr.size    = META_TAG_GET_U32_BE(u8HdrBuf);
            ahdr.exthdr.flags   = META_TAG_GET_U16_BE(&u8HdrBuf[4]);
            if (ahdr.exthdr.flags & ID3_TAG_V2_3_EXT_FLAG_ZERO)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.exthdr.flags);

                return  META_TAG_ERR_NOT_SUPPORT;
            }
            ahdr.exthdr.padding_size    = META_TAG_GET_U32_BE(&u8HdrBuf[6]);
            if (ahdr.exthdr.flags & ID3_TAG_V2_3_EXT_FLAG_CRC)
            {
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 4);
                if (u32Tmp != 4)
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                ahdr.exthdr.crc = META_TAG_GET_U32_BE(u8HdrBuf);
            }
        }
        break;
    case 4:
       
        if (ahdr.flags & ID3_TAG_V2_4_FLAG_ZERO)
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, ahdr.flags);

            return  META_TAG_ERR_NOT_SUPPORT;
        }
        if (ahdr.flags & ID3_TAG_V2_4_FLAG_EXT_HEADER)
        {
            u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 6);
            if (u32Tmp != 6)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Tmp);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            if ((1 != u8HdrBuf[4]) || /*the flag numbers must be 1*/
                (u8HdrBuf[5] & ID3_TAG_V2_4_EXT_FLAG_ZERO))
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[4]);

                return  META_TAG_ERR_INVAILD_DATA;
            }
            ahdr.exthdr.size    = META_TAG_GET_U32_BE(u8HdrBuf);
            ahdr.exthdr.flags   = u8HdrBuf[5];
            if (ahdr.exthdr.flags & ID3_TAG_V2_4_EXT_FLAG_UPDATE)
            {
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 1);
                if (u32Tmp != 1 || 0 != u8HdrBuf[0])
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[0]);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
            }
            if (ahdr.exthdr.flags & ID3_TAG_V2_4_EXT_FLAG_CRC)
            {
                /*
                *   CRC value can't be check, if the whole data can't be received.
                */
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 6);
                if (u32Tmp != 6 || 5 != u8HdrBuf[0])
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[0]);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                ahdr.exthdr.crc = META_TAG_GET_UNSYNC_U35_BE(&u8HdrBuf[1]);
            }
            if (ahdr.exthdr.flags & ID3_TAG_V2_4_EXT_FLAG_RESTRICTIONS)
            {
                /*
                *   just ignore this flags! and the data length should be 1
                */
                u32Tmp = pInternal->func_p->tag_read(metaID, u8HdrBuf, 2);
                if (u32Tmp != 2 || 1 != u8HdrBuf[0])
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u8HdrBuf[0]);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                ahdr.exthdr.restrictions    = u8HdrBuf[1];
            }
        }
        break;
    default:
        META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, 0);

        return  META_TAG_ERR_NOT_SUPPORT;
    }
    pInternal->hdr_flags    = ahdr.flags;
    pInternal->hdr_version  = ahdr.version;
    pInternal->hdr_size     = ahdr.size;

    return  tag_write_frames_rating(metaID, pInternal);

}

/*****************************************************************************
 * FUNCTION
 *  tag_parse_frames
 * DESCRIPTION
 *  parse id3 frames data 
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pInternal   [IN/OUT]    information for output
 * RETURNS
 *  success return META_TAG_ERR_NONE,
 *****************************************************************************/
static  kal_uint8  tag_write_frames_rating(kal_uint32 metaID, meta_tag_internal_info_struct* pInternal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    id3_v2_tag_frame_hdr_struct     frameHdr;
    id3_v2_tag_frame_parse_struct   frameGet;

    kal_uint32 u32Loaction, u32Ret, u32Read, u32ToGet, u32Got, u32Skip;
    kal_uint32 u32ParseSize, u32RunSize;
    kal_int32  s32Tmp;
    kal_uint8  u8TmpBuf[ID3_READ_BUFFER_SIZE+2];/*add two bytes for padding zero*/
    kal_uint8  u8FrameBuf[ID3_FRAME_BUFFER_SIZE+2];
    kal_uint8  u8Unsync, u8HdrSize, u8Tmp;
    kal_uint8  tmp[8];
    kal_uint32 tmp32;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    frameGet.bufferSize = ID3_FRAME_BUFFER_SIZE;
    frameGet.pBuffer    = u8FrameBuf;
    frameGet.frmhdr     = &frameHdr;
    frameGet.metaID     = metaID;
    frameGet.pInternal  = pInternal;

    switch(pInternal->hdr_version)
    {
    case 2: 
        
        u8Unsync    = ID3_TAG_V2_2_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_2_FRAME_HEADER_SIZE;
		return META_TAG_ERR_NOT_SUPPORT;

    case 3:

        u8Unsync    = ID3_TAG_V2_3_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_3_FRAME_HEADER_SIZE;
        break;
    case 4:   
        
        u8Unsync    = ID3_TAG_V2_4_FLAG_UNSYNCH;
        u8HdrSize   = ID3_TAG_V2_4_FRAME_HEADER_SIZE;
		return META_TAG_ERR_NOT_SUPPORT;

    default:        ASSERT(0);

        u8Unsync    = 0;
        u8HdrSize   = 0;
        break;
    }

    u32Read     = 0;
    u32Got      = 0;
    u32Skip     = 0;
    u32ToGet    = ID3_READ_BUFFER_SIZE;
    if (u32ToGet > pInternal->hdr_size)
    {
        u32ToGet = pInternal->hdr_size;
    }
    /*
    *   to get current frame location in data stream
    */
    u32ParseSize= 0;
    u32Loaction = pInternal->func_p->tag_getlocation(metaID);

    while (u32ParseSize < pInternal->hdr_size)
    {
        if (0 != u32ToGet)
        {
            if ((u32Skip > 0) && !(pInternal->hdr_flags & u8Unsync))
            {
                /*
                *   sync mode, just use seek function to find next frame!
                */
                /*
                *   it's terrible when the meta data has picture & used unsync!
                *   how to get picture location!
                */
                s32Tmp = pInternal->func_p->tag_seek(metaID, u32Skip, FUNC_SEEK_CUR);
                if (s32Tmp < 0)
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

                    return  META_TAG_ERR_INVAILD_DATA;
                }
                u32ParseSize += u32Skip;
                u32Read += u32Skip;
                u32Skip = 0;
                u32ToGet    = ID3_READ_BUFFER_SIZE;
                if (u32ToGet + u32Read > pInternal->hdr_size)
                {
                    u32ToGet = pInternal->hdr_size - u32Read;
                }
            }
            u32Ret = pInternal->func_p->tag_read(metaID, u8TmpBuf+u32Got, u32ToGet);
            if (u32Ret != u32ToGet)
            {
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Ret);

                return  META_TAG_ERR_INVAILD_DATA;
            }      
            u32Read += u32Ret;
            
            if (u32Skip > 0)
            {
                if (pInternal->hdr_flags & u8Unsync)
                {                
                    s32Tmp  = tag_reverse_unsync(u8TmpBuf+u32Got, u32Ret,
                        &u32RunSize, u32Skip);
                }
                else
                {
                    if (u32Skip > u32Ret)
                    {
                        u32RunSize = u32Ret;//used in file size
                    }
                    else
                    {
                        u32RunSize = u32Skip;
                    }
                    s32Tmp  = u32Ret;   //valid data size
                }
                u32ParseSize += u32RunSize;

                if (u32RunSize == u32Ret)
                {
                    u32Skip     -= s32Tmp;
                    u32ToGet    = ID3_READ_BUFFER_SIZE;
                    if (u32ToGet + u32Read > pInternal->hdr_size)
                    {
                        u32ToGet = pInternal->hdr_size - u32Read;
                    }
                    u32Got      = 0;
                    continue;
                }
                u32Got  = u32Ret-u32RunSize;
                u32Skip = 0;

                memcpy(u8TmpBuf, u8TmpBuf+u32RunSize, u32Got);
                u32ToGet = ID3_READ_BUFFER_SIZE-u32Got;
                if (u32ToGet > pInternal->hdr_size - u32Read)
                {
                    u32ToGet = pInternal->hdr_size - u32Read;
                }
                continue;
            }
            u32Got += u32Ret;
        }
        if (u32Got <= u8HdrSize)
        {
            /*
            *   data not enough, may has error
            */
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Got);
            break;
        }
        /*
        *   parse frame header
        */
        if (pInternal->hdr_flags & u8Unsync)
        {                
            u32Ret  = tag_reverse_unsync(u8TmpBuf, u32Got,
                &u32RunSize, u8HdrSize);
            if (u32Ret < u8HdrSize)
            {
                /*
                *   data not enough, may has error
                */
                META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, u32Ret);
                break;
            }
        }
        else
        {
            u32RunSize = u8HdrSize;
        }
        u8Tmp = tag_parse_frame_hdr(pInternal->hdr_version, 
            &frameHdr, u8TmpBuf);        

        if (u8Tmp == ID3_TAG_FRAME_ERR_NONE)
        {
            frameHdr.index = tag_get_frame_index(pInternal->hdr_version, 
                frameHdr.id);
        }
        else
        {            
            frameHdr.index = META_TAG_ID3_V2_ATTR_NUMBER;
        }
        if (frameHdr.size < ID3_FRAME_MIN_SIZE)
        {   
            /*
            *   maybe follow the padding data;
            */
			if (0 == frameHdr.id[0])
			{
				frameGet.frame_location = u32Loaction + u32Read-u32Got;
				if (frameHdr.size - frameGet.frame_location <= 16)
				{
					return META_TAG_ERR_NOT_ENOUGH_PADDING;
				}
				s32Tmp = pInternal->func_p->tag_seek(metaID, frameGet.frame_location, 0);
				if (s32Tmp < 0)
				{
                    return  META_TAG_ERR_INVAILD_DATA;
                }
				memset((char*)frameGet.pBuffer, 0, 16);
				memcpy((char*)frameGet.pBuffer, (char*)"POPM" , 4);
				frameGet.pBuffer[7] = 6;
				frameGet.pBuffer[11] = frameGet.pInternal->music_info.user_rate;
				memcpy((char*)tmp, (char*)&frameGet.pInternal->music_info.play_count, 4 );
        		tmp32 = META_TAG_GET_U32_BE(tmp);
				memcpy((char*)(frameGet.pBuffer+ 12), (char *)&tmp32, 4);
		
				s32Tmp = pInternal->func_p->tag_write(metaID, frameGet.pBuffer, 16);
				if (s32Tmp < 0)
				{
					return META_TAG_ERR_INVAILD_DATA;
				}
				else
				{
					s32Tmp = pInternal->func_p->tag_commit(metaID);
					return META_TAG_ERR_NONE;
				}
				
			}
			else
			{
				return META_TAG_ERR_INVAILD_DATA;
			}
        }

        if (META_TAG_ID3_V2_ATTR_NUMBER > frameHdr.index)
        {
        if (META_TAG_FRAME_RATING == g_id3v2_key[frameHdr.index].key_frameID)
        {
            /*
            *   calc frame header start position;
            */
            frameGet.frame_location = u32Loaction + u32Read-u32Got;
            s32Tmp = u32RunSize;

            if (pInternal->hdr_flags & u8Unsync)
            {                
                return META_TAG_ERR_NOT_SUPPORT;
            }
            else
            {
                if (frameHdr.size >= u32Got-s32Tmp)
                {
                    u32RunSize  = u32Got-s32Tmp;
                    u32Skip     = frameHdr.size - u32RunSize; 
                    /*Skip data which cann't match in buffer*/
                    /*the huge frame, such as lyrics or artwork, must be skip from there*/
                    /*maybe we can break, and use information in id3v1*/
                }
                else
                {
                    u32Skip     = 0;
                    u32RunSize  = frameHdr.size;
                }
                u32Ret = u32RunSize;                
            }
            frameGet.dataSize   = u32Ret;
            frameGet.pData      = u8TmpBuf+s32Tmp+frameHdr.data_offset;
            s32Tmp = pInternal->func_p->tag_seek(metaID, frameGet.frame_location + 10, 0);
            if (s32Tmp < 0)
            {
                return  META_TAG_ERR_INVAILD_DATA;
            }
            tag_parse_rewirte_frame_data(&frameGet);
            s32Tmp = pInternal->func_p->tag_write(metaID, frameGet.pData, frameGet.dataSize);
            if (s32Tmp < 0)
            {
                return META_TAG_ERR_INVAILD_DATA;
            }
            else
            {
                s32Tmp = pInternal->func_p->tag_commit(metaID);
                return META_TAG_ERR_NONE;
            }
        }
        }
        else
        {
            if (pInternal->hdr_flags & u8Unsync)
            {
                u32Skip = frameHdr.size;
            }
            else
            {
                if (u32Got - u32RunSize > frameHdr.size)
                {
                    u32RunSize += frameHdr.size;
                }
                else
                {
                    u32Skip = frameHdr.size-(u32Got-u32RunSize);
                    u32RunSize = u32Got;
                }
            }            
        }
        /*
        *   Skip the unsupported frame or the frame may not all parsed!
        */     
        if (u32Got > u32RunSize)
        {
            u32Got -= u32RunSize;
            memcpy(u8TmpBuf, u8TmpBuf+u32RunSize, u32Got);
        }
        else
        {
            u32Got  = 0;
        }
        u32ToGet = ID3_READ_BUFFER_SIZE-u32Got;
        if (u32ToGet + u32Read > pInternal->hdr_size)
        {
            u32ToGet = pInternal->hdr_size - u32Read;
        }
        u32ParseSize += u32RunSize;
    }    
    return  META_TAG_ERR_NONE;	
}


#endif /* __TAG_SUPPORT_WRITE_BACK__ */

/*****************************************************************************
 * FUNCTION
 *  tag_parse_frame_data
 * DESCRIPTION
 *  parse id3 frame data information 
 * PARAMETERS
 *  pGet        
 * RETURNS
 *  success return ID3_TAG_FRAME_ERR_NONE
 *****************************************************************************/
static kal_uint8   tag_parse_frame_data(id3_v2_tag_frame_parse_struct* pGet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8*  pbuffer;
    kal_int32   s32Tmp, s32Size;
    kal_uint8   u8Tmp, u8Null, u8Terminator, u8Charset = META_TAG_TEXT_ENCODING_UCS2;
    kal_uint8   isUCSII = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pGet->pInternal->hdr_version)
    {
    case 2:
    case 3:

        if ((pGet->pData[0] > META_TAG_TEXT_ENCODING_UTF16) &&
            g_id3v2_key[pGet->frmhdr->index].key_frameID != META_TAG_FRAME_RATING)
        {
            return ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
    	break;
    case 4:

        if (pGet->pData[0] > META_TAG_TEXT_ENCODING_UTF8)
        {
            return ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        break;
    default:    ASSERT(0);
        break;
    }
    /*
    *   revise data for check data
    */
    if ((4 == pGet->pInternal->hdr_version) && 
        (pGet->frmhdr->flags & ID3_TAG_V2_4_FRAME_FLAG_UNSYNCH) &&
        (!(pGet->pInternal->hdr_flags & ID3_TAG_V2_4_FLAG_UNSYNCH)))
    {
        /*
        *   have no break size, so go through the string
        */
        pGet->dataSize = tag_reverse_unsync(pGet->pData, pGet->dataSize, 
            NULL, pGet->dataSize);
    }
    switch (g_id3v2_key[pGet->frmhdr->index].key_frameID)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    case META_TAG_FRAME_PICTURE:

        return  tag_parse_image_frame_data(pGet);
#ifdef __TAG_SUPPORT_WRITE_BACK__
	case META_TAG_FRAME_RATING:

		return tag_parse_rating_frame_data(pGet);
#endif /* __TAG_SUPPORT_WRITE_BACK__ */
    case META_TAG_FRAME_DESCRIPTION:

        /*
        *   need skip language format 3 bytes+1 byte text encoding type,
        *       Text encoding          $xx
        *       Language               $xx xx xx
        *       Short content description. <text string according to encoding> $00 (00)
        *       The actual text        <full text string according to encoding>
        */
        s32Tmp  = meta_tag_find_terminator(&pGet->pData[4], 
            pGet->dataSize-4, pGet->pData[0]);
        if (s32Tmp < 0 )
        {
            META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);
            
            return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
        }
        META_GET_TERMINATOR_LEN(pGet->pData[0], u8Terminator);
        pbuffer = pGet->pData+4+s32Tmp+u8Terminator;
        break;
    default:
        
        pbuffer = pGet->pData+1;
        break;
    }
    
    switch(pGet->pData[0])
    {
    case META_TAG_TEXT_ENCODING_ISO_8859_1:
       
        u8Tmp = pGet->pData[pGet->dataSize];
        pGet->pData[pGet->dataSize] = 0;
        
        if ((META_TAG_TEXT_ENCODING_UCS2 == pGet->pInternal->prefer_charset) ||
            (g_id3v2_key[pGet->frmhdr->index].key_frameID == META_TAG_FRAME_YEAR) ||
            (g_id3v2_key[pGet->frmhdr->index].key_frameID == META_TAG_FRAME_TRACKNUM) ||
            (g_id3v2_key[pGet->frmhdr->index].key_frameID == META_TAG_FRAME_GENRE))
        {
            isUCSII = 1;
            s32Size = mmi_chset_text_to_ucs2(pGet->pBuffer, 
                pGet->bufferSize + 2, pbuffer);
        }
        else
        {            
            if (pGet->dataSize > pGet->bufferSize)
            {
                s32Size = pGet->bufferSize;
            }
            else
            {
                s32Size = pGet->dataSize;
            }
            kal_mem_cpy((void*)pGet->pBuffer, (const void*)pbuffer, s32Size);
            
            if (s32Size%2 != 0)
            {
                if (s32Size >= (kal_int32)pGet->bufferSize)
                {
                    s32Size -= 1;
                }
                else
                {
                    pGet->pBuffer[s32Size] = 0;
                    s32Size ++;
                }
            }
            u8Charset = META_TAG_TEXT_ENCODING_ISO_8859_1;
        }        
        pGet->pData[pGet->dataSize] = u8Tmp;
        break;
    case META_TAG_TEXT_ENCODING_UTF16:

        u8Tmp   = pGet->pData[pGet->dataSize];
        u8Null  = pGet->pData[pGet->dataSize+1];
        pGet->pData[pGet->dataSize]     = 0;
        pGet->pData[pGet->dataSize+1]   = 0;
        s32Size = mmi_chset_convert(CHSET_UTF16LE, CHSET_UCS2, 
            (char*)pbuffer, 
            (char*)pGet->pBuffer, 
            pGet->bufferSize);
        pGet->pData[pGet->dataSize]     = u8Tmp;
        pGet->pData[pGet->dataSize+1]   = u8Null;
        break;
    case META_TAG_TEXT_ENCODING_UTF16_BE:

        u8Tmp   = pGet->pData[pGet->dataSize];
        u8Null  = pGet->pData[pGet->dataSize+1];
        pGet->pData[pGet->dataSize]     = 0;
        pGet->pData[pGet->dataSize+1]   = 0;

        s32Size = mmi_chset_convert(CHSET_UTF16BE, CHSET_UCS2, 
            (char*)pbuffer, 
            (char*)pGet->pBuffer, 
            pGet->bufferSize);

        pGet->pData[pGet->dataSize]     = u8Tmp;
        pGet->pData[pGet->dataSize+1]   = u8Null;
        break;
    case META_TAG_TEXT_ENCODING_UTF8:

        u8Tmp = pGet->pData[pGet->dataSize];
        pGet->pData[pGet->dataSize] = 0;
        s32Size = mmi_chset_convert(CHSET_UTF8, CHSET_UCS2, 
            (char*)pbuffer, 
            (char*)pGet->pBuffer, 
            pGet->bufferSize);
        pGet->pData[pGet->dataSize] = u8Tmp;
        break;
    default: 

        s32Size = 0;
        break;
    }
    if (s32Size < 2)
    {
        return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;
    }
    if (isUCSII)
    {
        s32Size -= 2;
    }
    else
    {
        if (pGet->pBuffer[s32Size - 1] == 0)
            s32Size --;
        if (pGet->pBuffer[s32Size - 1] == 0)
            s32Size --;
    }
    

    switch (g_id3v2_key[pGet->frmhdr->index].key_frameID)
    {
    case META_TAG_FRAME_YEAR:
		if ((kal_uint16)pGet->pBuffer[0] >= L'0' && (kal_uint16)pGet->pBuffer[0] <= '9')
		{
			pGet->pInternal->music_info.year = 
            (kal_int32)app_ucs2_atoi((const kal_int8*)pGet->pBuffer);
		}
		else
		{
			pGet->pInternal->music_info.year = -1;
		}
        break;
    case META_TAG_FRAME_TRACKNUM:

        pGet->pInternal->music_info.track_number = 
            (kal_int32)app_ucs2_atoi((const kal_int8*)pGet->pBuffer);
    	break;
    case META_TAG_FRAME_GENRE:

        if (0 == app_ucs2_strncmp((const kal_int8*)pGet->pBuffer, 
            (const kal_int8*)L"RX", 2))
        {
            app_ucs2_strcpy((kal_int8*)pGet->pBuffer, (const kal_int8*)L"Remix");
            s32Size = 12;
        }
        else if (0 == app_ucs2_strncmp((const kal_int8*)pGet->pBuffer, 
            (const kal_int8*)L"CR", 2))
        {
            app_ucs2_strcpy((kal_int8*)pGet->pBuffer, (const kal_int8*)L"Cover");
            s32Size = 12;
        }
        else
        {
#if defined (__TAG_SUPPORT_ID3V1__) 
            s32Tmp = id3_tag_v1_u16_parse_number(
                (kal_uint16*)pGet->pBuffer, s32Size/2);

            if (s32Tmp >= 0)
            {
                pbuffer = (kal_uint8*)id3_tag_v1_get_genre(s32Tmp);
                if (NULL == pbuffer)
                {
                    META_TAG_ERR_TRACE(FILE_ID_ID3_V2_PARSER, s32Tmp);

                    return  ID3_TAG_FRAME_ERR_NOT_SUPPORT;  
                }
                s32Size = mmi_chset_convert(CHSET_UTF8, CHSET_UCS2, 
                    (char*)pbuffer, 
                    (char*)pGet->pBuffer, 
                    pGet->bufferSize);
            }
#endif  /*defined (__TAG_SUPPORT_ID3V1__) */
            /*
            *   else directly copy string as genre.
            */
        }
        /*
        *   do not add break here, for copy genre to frame data
        */
    default:

        if (s32Size > META_TAG_FRAME_MAX_SIZE)
        {
            s32Size = META_TAG_FRAME_MAX_SIZE;
        }

        if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->pBuffer, s32Size/2))
        {        
            pbuffer = 
                pGet->pInternal->func_p->tag_getbuffer(pGet->metaID, s32Size);
            ASSERT(NULL != pbuffer);
            memcpy(pbuffer, pGet->pBuffer, s32Size);     
        
            s32Tmp = g_id3v2_key[pGet->frmhdr->index].key_frameID;
        
            pGet->pInternal->music_info.txt_frame[s32Tmp].data 
                = (kal_uint16*)pbuffer;
            pGet->pInternal->music_info.txt_frame[s32Tmp].data_size 
                = (kal_uint16)s32Size;  
            pGet->pInternal->music_info.txt_frame[s32Tmp].data_encoding
                = u8Charset;
        }
        break;  
    }
    return  ID3_TAG_FRAME_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  tag_get_image_priority
 * DESCRIPTION
 *  get attached picture priority
 * PARAMETERS
 *  image_type        
 * RETURNS
 *  success return image type priority
 *****************************************************************************/
static kal_uint8   tag_get_image_priority(kal_uint8 image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8  u8Ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    switch(image_type)
    {
    case 1:     u8Ret = 2;  break;      /*32x32 pixels 'file icon' (PNG only)*/
    case 2:     u8Ret = 3;  break;      /*Other file icon*/    
    case 3:     u8Ret = 10; break;      /*Cover (front)*/
    case 4:     u8Ret = 5;  break;      /*Cover (back)*/
    case 5:     u8Ret = 9;  break;      /*Leaflet page*/
    case 6:     u8Ret = 6;  break;      /*Media (e.g. lable side of CD)*/  
    case 7:     u8Ret = 8;  break;      /*Lead artist/lead performer/soloist*/
    case 8:     u8Ret = 7;  break;      /*Artist/performer*/
    case 9:     u8Ret = 4;  break;      /*Conductor*/
    default:    u8Ret = 1;  break;      
    }

    return  u8Ret;
}
#endif  /*#if defined(__TAG_SUPPORT_ID3V2__)*/
