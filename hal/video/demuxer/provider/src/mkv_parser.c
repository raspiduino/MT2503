/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mkv_parser.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "drv_features_video.h"

#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)

#include "kal_public_defs.h"
#include "kal_release.h"
#include "mkv_parser.h"
#include "vcodec_v2_trc.h"
#include "video_dbg_v2.h"
#include "drv_comm.h"
#ifdef __MKV_PARSER_META__
#include "provider_utility.h"
#endif

#define MKV_CODECID_COUNT 24
static const kal_uint8* const mkv_codec_id[MKV_CODECID_COUNT] =
{
    "V_MPEG4/ISO/ASP",
    "V_MPEG4/ISO/AVC",
    "V_MS/VFW/FOURCC",
    "V_VP8",
    "H264",
    "XVID",
    "V_MJPEG",    
    "A_AAC",
    "A_MPEG/L3",
    "A_VORBIS",
    "A_AC3",
    "A_DTS",
    "A_AAC/MPEG4/LC",
    "A_AAC/MPEG4/LC/SBR",    
    "A_MPEG/L1",    
    "A_MPEG/L2",
    "A_MS/ACM",    
    "A_PCM/INT/BIG",       
    "A_PCM/INT/LIT", 
    "A_WAVPACK4",    
    "S_TEXT/UTF8",
    "S_TEXT/ASS",
    "S_TEXT/SSA",
    "S_VOBSUB"
};

#ifdef __MKV_PARSER_DEBUG__
//const static kal_uint32 u4ClutserElementLen = 5240;
//static kal_uint32 u4mkvparserbingo;
#endif

/*****************************************************************************
 * FUNCTION
 *    _mkv_parser_get_vint_size
 * DESCRIPTION
 *  This function is used to parse length of vint.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8 u1Data
 *                 The data use to parsing.
 * RETURNS
 *  return length of vint.
 *
 ****************************************************************************/

kal_uint64 _mkv_read_byte(kal_uint8 * pBuf, kal_uint32 u4size)
{
    kal_uint64 u4value = 0;
    kal_uint32 index;

    if(u4size == 0 || u4size > 8)
    {
        ASSERT(0);
    }

    for(index = u4size; index > 0; index--)
    {
        kal_uint64 temp;
		temp = (kal_uint64)pBuf[u4size - index]; 
        u4value += (temp << (index-1)*8);
    }

    return u4value;
}

kal_uint64 _mkv_read_byte_little_endian(kal_uint8 * pBuf, kal_uint32 u4size)
{
    kal_uint64 u4value = 0;
    kal_uint32 index;

    if(u4size == 0 || u4size > 8)
    {
        ASSERT(0);
    }

    for(index = u4size; index > 0; index--)
    {
        kal_uint64 temp;
		temp = (kal_uint64)pBuf[index-1]; 
        u4value += (temp << (index-1)*8);
    }

    return u4value;
}

static kal_uint32 _mkv_parser_get_vint_size(kal_uint8* u1Data)
{
    kal_uint32 u4len = 0;
    kal_int32 index;

    for (index = 7; index >= 0; index--)
    {
        u4len ++;
        if((*u1Data >> index) == 1)
        {
            break;
        }
    }

    return u4len;
}

static kal_uint64 _mkv_read_vint(kal_uint8 * pBuf, mkv_parser* pParser, void* pReadhdr, kal_uint32 * p4size)
{
    kal_uint64 u4value = 0;
    kal_uint64 u4checkvalue = 0;	
    kal_uint32 index;
    kal_uint8 mask;

    kal_uint32 u4size = _mkv_parser_get_vint_size(pBuf);


    if(pParser && pReadhdr)
    {
        if(u4size > 1)
        {
            pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf + 1, u4size - 1);
        }
    }

    mask = 0xFF << (8 - u4size);

    for(index = u4size; index > 0; index--)
    {

        if(index == u4size)
        {
            u4value = ((kal_uint64)(pBuf[u4size - index] & ~mask) << ((index-1))*8);
        }
        else
        {
            u4value += ((kal_uint64)pBuf[u4size - index] << ((index-1))*8);		
        }
    }

    if(p4size)
    {
        *p4size = u4size;
    }


    switch(u4size)
    {
        case 1:
            u4checkvalue = 0x7F;				
            break;
        case 2:
            u4checkvalue = 0x3FFF;				
            break;			
        case 3:
            u4checkvalue = 0x1FFFFFF;
            break;						
        case 4:
            u4checkvalue = 0x0FFFFFFF;
            break;						
        case 5:
            u4checkvalue = 0x07FFFFFFFF;
            break;			
        case 6:
            u4checkvalue = 0x03FFFFFFFFFF;
            break;		
        case 7:
            u4checkvalue = 0x01FFFFFFFFFFFF;
            break;				
        case 8:
            u4checkvalue = 0x00FFFFFFFFFFFFFF;
            break;				
    }
    if(u4value == u4checkvalue)
    {
        return MKV_UNKNOWN_LENGTH;
    }

    return u4value;
}

static kal_int64 _mkv_read_svint(kal_uint8 * pBuf, mkv_parser* pParser, void* pReadhdr, kal_uint32 * p4size)
{
    kal_int64 i4value = 0;
    i4value = _mkv_read_vint(pBuf, pParser, pReadhdr, p4size);
    switch(*p4size)
    {
        case 1:
            i4value -= 0x3F;				
            break;
        case 2:
            i4value -= 0x1FFF;				
            break;			
        case 3:
            i4value -= 0x7FFFFFF;
            break;						
        case 4:
            i4value -= 0x3FFFFFFFF;
            break;						
        case 5:
            i4value -= 0x1FFFFFFFFFF;
            break;			
        case 6:
            i4value -= 0xFFFFFFFFFFFF;
            break;		
        case 7:
            i4value -= 0x7FFFFFFFFFFFFF;
            break;				
	}
    return i4value;	
}

static kal_uint64 _mkv_read_float(kal_uint8 * pBuf, kal_uint32 u4size)
{
    kal_uint64 result = 0;
    kal_uint64 value = 0;

    value = _mkv_read_byte(pBuf, u4size);
    if(u4size == 4)
    {
        kal_uint32 fraction = 0;						   		    
        kal_uint16 exponent = 0;		
        exponent = (kal_uint16)(((value & 0x7F800000)>>23) - 127);
        fraction = (value | 0x800000) & 0xFFFFFF;
        if(exponent >= 23)
        {
            result = (kal_uint64)fraction << (exponent-23);
        }
        else
        {
            result = (kal_uint64)fraction >> (23-exponent);							
        }								
    }
    else if(u4size == 8)
    {
        kal_uint64 fraction = 0;						   		    
        kal_uint16 exponent = 0;			
        exponent = (kal_uint16)(((value & 0x7FF0000000000000)>>52) - 1023);
        fraction = (value | 0x10000000000000) & 0x1FFFFFFFFFFFFF;								
        if(exponent >= 52)
        {
            result = fraction << (exponent-52);
        }
        else
        {
            result = fraction >> (52-exponent);							
        }								
    }
    return result;
}

static kal_uint32 _mkv_parser_getscaletime(mkv_parser* pParser, kal_uint32 u4Time)
{
    if(MKV_DEFAULT_TIMECODESCALE != pParser->u4TimecodeScale)
    {
        u4Time = u4Time * pParser->u4TimecodeScale / MKV_DEFAULT_TIMECODESCALE;	
    }
    return u4Time;
}

static kal_bool _mkv_read_EBML(kal_uint8 * pBuf, kal_uint32 u4BufDataLen, mkv_parser* pParser, void* pReadhdr, mkv_ebml_element* prEBML)
{
    kal_bool result = KAL_FALSE;
    kal_uint32 u4Offset = 0;
    kal_uint32 u4Size = 0;	
	
    kal_mem_set(prEBML,0,sizeof(mkv_ebml_element));
				 
    prEBML->u4EbmlIDLen = _mkv_parser_get_vint_size(pBuf);
    if(prEBML->u4EbmlIDLen > MKV_CLASS_D_ELEMENTS_SIZE || (NULL != u4BufDataLen && u4BufDataLen < prEBML->u4EbmlIDLen+1))
    {
        return result;
    }
    prEBML->u4EbmlID = _mkv_read_byte(pBuf, prEBML->u4EbmlIDLen);
    u4Offset += prEBML->u4EbmlIDLen;
    prEBML->u4ElementSize = _mkv_read_vint(pBuf + u4Offset, pParser, pReadhdr, &u4Size);
    prEBML->u4ElementSizeLen = u4Size;
    prEBML->pu1Element = pBuf + u4Offset + u4Size;
    prEBML->u4EbmlTotalLength = prEBML->u4EbmlIDLen + prEBML->u4ElementSizeLen + prEBML->u4ElementSize;
    result = KAL_TRUE;
	
    return result;	
}

kal_bool mkv_parser_check_ebml(kal_uint8* pBuf)
{
   kal_bool result = KAL_FALSE;

#ifndef __MKV_SLIM__
   if(_mkv_parser_get_vint_size(pBuf) == MKV_CLASS_D_ELEMENTS_SIZE)
   {
#endif   
        if(_mkv_read_byte(pBuf, MKV_CLASS_D_ELEMENTS_SIZE) == MKV_EBML_ID)
        {
            result = KAL_TRUE;
        }
#ifndef __MKV_SLIM__		
   }
#endif

   return result;
}

static kal_bool _mkv_parser_ebml_header(mkv_parser* pParser, kal_uint32 u4Filesize)
{
    kal_bool result = KAL_FALSE;

#ifndef __MKV_SLIM__	
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    {
#endif    
        kal_uint8 *pEbmlbuf = NULL;
        kal_uint32 u4EbmlLength;

        pEbmlbuf = (kal_uint8 *) pParser->fpMalloc(pParser->pUserMem, 5 + 8, KAL_TRUE);  //EBML_ID, LENGTH(vint)
        pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pEbmlbuf, 5);

        u4EbmlLength = _mkv_read_vint(pEbmlbuf + 4, pParser, pParser->pfilehdr, NULL);

        pParser->fpSeek(pParser->pfilehdr, u4EbmlLength, MKV_SEEK_CUR);

        kal_mem_set(pEbmlbuf, 0, 13);
        if(5 == pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pEbmlbuf, 5))
        {
#ifndef __MKV_SLIM__        
            if(_mkv_parser_get_vint_size(pEbmlbuf) == MKV_CLASS_D_ELEMENTS_SIZE)
            {
#endif            
                 if(_mkv_read_byte(pEbmlbuf, MKV_CLASS_D_ELEMENTS_SIZE) == MKV_SEGMENT_ID)
                 {
                     pParser->u4SegmentLength = _mkv_read_vint(pEbmlbuf + 4, pParser, pParser->pfilehdr, NULL);
                     pParser->u4SegmentDataBase = pParser->fpGetcurpos(pParser->pfilehdr);
                     if(u4Filesize > pParser->u4SegmentDataBase + pParser->u4SegmentLength)
                     {
                         pParser->u4SegmentLength = u4Filesize - pParser->u4SegmentDataBase;
                     }
                     result = KAL_TRUE;
                 }
#ifndef __MKV_SLIM__				 
            }
#endif			
        }
        pParser->fpMfree(pParser->pUserMem, (void**)&pEbmlbuf);
#ifndef __MKV_SLIM__			
    }
#endif	
    return result;
}

static kal_bool _mkv_parser_read_CRC32(kal_uint8 * pBuf, kal_uint32* p4Length)
{
    kal_bool result = KAL_FALSE;
	kal_uint32 u4len = 0;

    *p4Length = 0;
	if(_mkv_read_byte(pBuf, MKV_CLASS_A_ELEMENTS_SIZE) != MKV_CRC32ID)
	{
		return result;
	}
	u4len++;
	if(_mkv_read_vint(pBuf+u4len, NULL, NULL, NULL) == 4)
	{
	    *p4Length = 6;

        result = KAL_TRUE;
	}
    return result;
}

static MKV_CODECID_T _mkv_parser_read_codec(const kal_uint8* pBuf, const kal_uint32 u4Length)
{
    MKV_CODECID_T ret = MKV_CODECID_UNKNOW;
	kal_uint32 index;
    for(index = 0; index < MKV_CODECID_COUNT; index++ )
    {
        if(0 == strncmp((const char *)pBuf, (const char *)mkv_codec_id[index], u4Length))
        {
            break;
        }
    }
    if(MKV_CODECID_COUNT == index)
    {
        index = MKV_CODECID_UNKNOW;
    }
    ret = (MKV_CODECID_T)index;
    	
    return ret;
}

static kal_bool _mkv_parser_read_seekhead(mkv_parser* pParser, kal_uint8 *pSeekheadbuf)
{
    kal_bool result = KAL_FALSE;
#ifndef __MKV_SLIM__	
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    {
        if(_mkv_parser_get_vint_size(pSeekheadbuf) == MKV_CLASS_D_ELEMENTS_SIZE)
        {
#endif            
             if(_mkv_read_byte(pSeekheadbuf, MKV_CLASS_D_ELEMENTS_SIZE) == MKV_SEEKHEAD_ID)
             {
                 kal_uint32 u4Length;
                 kal_uint8 *pSeekbuf;

                 kal_uint32 u4Offset = 0;
                 kal_uint32 u4CRCLen;				 

                 u4Length = _mkv_read_vint(pSeekheadbuf + MKV_CLASS_D_ELEMENTS_SIZE , pParser, pParser->pfilehdr, NULL);

                 if(u4Length > SEEKHEAD_BUFFER_SIZE)  // if seekhead section larger than 256, give up to read this section.
                 {
                     u4Length = SEEKHEAD_BUFFER_SIZE;
                 }
                 pSeekbuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, u4Length, KAL_TRUE);
                 pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pSeekbuf, u4Length);

                 _mkv_parser_read_CRC32(pSeekbuf+u4Offset, &u4CRCLen);
                 u4Offset += u4CRCLen;

                 while(u4Length > u4Offset)
                 {
                     kal_uint32 u4SeekLen = 0;
                     kal_uint64 u8SeekID = 0;
                     kal_uint64 u8SeekPos = 0;
					 
                     mkv_ebml_element rSeekEBML[2];					 
					 
                     if(_mkv_read_byte(pSeekbuf+u4Offset, MKV_CLASS_B_ELEMENTS_SIZE) != MKV_SEEK)
                     {
                         break;
                     }
                     u4Offset += MKV_CLASS_B_ELEMENTS_SIZE;

                     u4SeekLen = _mkv_parser_get_vint_size(pSeekbuf+u4Offset);
                     u4Offset += u4SeekLen;

                     _mkv_parser_read_CRC32(pSeekbuf+u4Offset, &u4CRCLen);
                     u4Offset += u4CRCLen;				 
					 

                     _mkv_read_EBML(pSeekbuf+u4Offset, NULL, NULL, NULL, &rSeekEBML[0]);
                     u4Offset += rSeekEBML[0].u4EbmlTotalLength;
					 
                     if(rSeekEBML[0].u4EbmlID != MKV_SEEK_ID)
                     {
                         break;
                     }

                     u8SeekID = _mkv_read_byte(rSeekEBML[0].pu1Element, rSeekEBML[0].u4ElementSize);


                     _mkv_read_EBML(pSeekbuf+u4Offset, NULL, NULL, NULL, &rSeekEBML[1]);
                     u4Offset += rSeekEBML[1].u4EbmlTotalLength;

                     if(rSeekEBML[1].u4EbmlID != MKV_SEEK_POSITION)
                     {
                         break;
                     }

                     u8SeekPos = _mkv_read_byte(rSeekEBML[1].pu1Element, rSeekEBML[1].u4ElementSize);

                     switch(u8SeekID)
                     {
                         case MKV_SEGMENTINFO_ID:
                            pParser->u4SegmentInfoBase = u8SeekPos + pParser->u4SegmentDataBase;
                            break;

                         case MKV_TRACKS_ID:
                            pParser->u4TracksBase = u8SeekPos + pParser->u4SegmentDataBase;
                            break;

                         case MKV_CUES_ID:
                            pParser->u4CuesBase = u8SeekPos + pParser->u4SegmentDataBase;
                            break;

                         case MKV_CLUSTER_ID:
                            pParser->u4ClusterBase = u8SeekPos + pParser->u4SegmentDataBase;
                            if(pParser->u4SeekheadBase != NULL)
                            {
                                u4Offset = u4Length;
                            }
                            break;
                         case MKV_SEEKHEAD_ID:
                            pParser->u4SeekheadBase = u8SeekPos + pParser->u4SegmentDataBase;
                            break;		
                         case MKV_TAGS_ID:
#ifdef __MKV_PARSER_META__						 	
                            pParser->u4TagsBase = u8SeekPos + pParser->u4SegmentDataBase;
#endif
                            break;							
                         case MKV_ATTACHMENTS_ID:
#ifdef __MKV_PARSER_META__						 	
                            pParser->u4AttachmentsBase = u8SeekPos + pParser->u4SegmentDataBase;
#endif
                            break;
#ifdef __MKV_PARSER_ASSERTUNKNOW__
                         case MKV_CHAPTERS_ID:
                            break;
#endif							
                         default:
#ifdef __MKV_PARSER_ASSERTUNKNOW__            						 	
                            ASSERT(0);
#endif
                            break;
                     }

                 }


                 pParser->fpMfree(pParser->pUserMem, (void**)&pSeekbuf);
                 if(u4Length == u4Offset)
                 {
                     result = KAL_TRUE;
                 }
             }
#ifndef __MKV_SLIM__				 
        }
    }
#endif	
    return result;
}

static kal_bool _mkv_parser_read_tracks(mkv_parser* pParser, kal_uint8 *pTrackbuf)
{
    kal_bool result = KAL_FALSE;
    mkv_parser_track* pTrackbase = NULL;
    const void* pUserMem = pParser->pUserMem;
	
#ifndef __MKV_SLIM__	
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    {
        if(_mkv_parser_get_vint_size(pTrackbuf) == MKV_CLASS_D_ELEMENTS_SIZE)
        {
#endif          
             if(_mkv_read_byte(pTrackbuf, MKV_CLASS_D_ELEMENTS_SIZE) == MKV_TRACKS_ID)
             {
                 kal_uint32 u4Length;
                 kal_uint8 *pTracksbuf;
                 kal_uint32 u4Offset = 0;
                 kal_uint32 u4CRCLen;

                 u4Length = _mkv_read_vint(pTrackbuf + MKV_CLASS_D_ELEMENTS_SIZE , pParser, pParser->pfilehdr, NULL);

                 if(u4Length > TRACKS_BUFFER_SIZE)  
                 {
                     u4Length = TRACKS_BUFFER_SIZE;
                 }
				 
                 pTracksbuf = (kal_uint8 *)pParser->fpMalloc(pUserMem, u4Length, KAL_FALSE);
                 if(NULL == pTracksbuf || pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pTracksbuf, u4Length) != u4Length)
                 {
                     return result;
                 }

                 _mkv_parser_read_CRC32(pTracksbuf+u4Offset, &u4CRCLen);
                 u4Offset += u4CRCLen;

                 while(u4Length > u4Offset)
                 {
                     kal_uint32 u4TrackLen = 0;
                     kal_uint32 u4Len = 0;
                     mkv_parser_track* pTrack;
                     kal_uint32 u4Offset1 = 0;
                     kal_uint8 *pTrackEntrybuf;
                     mkv_ebml_element rTrackEBML;

                     pTrack = (mkv_parser_track *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_track), KAL_FALSE);
                     if(NULL == pTrack)
                     {
                         break;
                     }
                     if(pParser->u4TrackCount == 0)
                     {
                         pParser->pTrackList = pTrack;
                     }
                     else
                     {
                         pTrackbase->next = (void*)pTrack;
                     }
                     pTrackbase = pTrack;

                     _mkv_read_EBML(pTracksbuf+u4Offset, NULL, NULL, NULL, &rTrackEBML);
                     u4Offset += (rTrackEBML.u4EbmlIDLen + rTrackEBML.u4ElementSizeLen);

                     if(rTrackEBML.u4EbmlID != MKV_TRACK_ENTRY)
                     {
                         break;
                     }

                     u4TrackLen = rTrackEBML.u4ElementSize;
                     if(u4TrackLen + u4Offset > u4Length)
                     {
                         break;
                     }

                     pParser->u4TrackCount++;
					 
                     if(u4TrackLen > u4Length)
                     {
                         u4TrackLen = u4Length;
                     }					 
					 
                     _mkv_parser_read_CRC32(pTracksbuf+u4Offset, &u4CRCLen);
                     u4Offset += u4CRCLen;
                     u4TrackLen -= u4CRCLen;

                     pTrackEntrybuf = pTracksbuf+u4Offset;
                     while(u4TrackLen > u4Offset1)
                     {
                         kal_uint32 u4Offset2 = 0;
                         kal_uint8 *pTrackPrivatebuf;

                         mkv_ebml_element rEBML;
                         _mkv_read_EBML(pTrackEntrybuf+u4Offset1, NULL, NULL, NULL, &rEBML);
                         u4Offset1 += rEBML.u4EbmlTotalLength;


                         switch(rEBML.u4EbmlID)
                         {
                             case MKV_TRACK_NUMBER:
                                 pTrack->u4TrackNumber = _mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#ifndef __MKV_SLIM__								 
                             case MKV_TRACK_UID:
                                 pTrack->u8TrackUID = _mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#endif								 
                             case MKV_TRACK_TYPE:
                             {
                                 kal_uint32 u4TrackType = _mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 switch(u4TrackType)
                                 {
                                    case 0x1:
                                      pTrack->u4TrackType = MKV_TRACKTYPE_VIDEO;
                                      pParser->fgVideoTrack = KAL_TRUE;
                                      break;
                                    case 0x2:
                                      pTrack->u4TrackType = MKV_TRACKTYPE_AUDIO;
                                      break;
#ifdef __VE_SUBTITLE_SUPPORT__										  
                                    case 0x11:
                                      pTrack->u4TrackType = MKV_TRACKTYPE_SUBTITLE;
                                      break;
#endif									  
#ifndef __MKV_SLIM__									  
                                    default:
                                      pTrack->u4TrackType = MKV_TRACKTYPE_NONE;
                                      break;
#endif									  
                                 }
                             }
                                 break;
#ifndef __MKV_SLIM__								 
                             case MKV_TRACK_FLAG_LACING:
                                 pTrack->fgFlagLacing = (kal_bool)_mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#endif								 
#ifdef __VE_SUBTITLE_SUPPORT__

                             case MKV_TRACK_FLAG_DEFAULT:
                                 pTrack->fgFlagDefault = (kal_bool)_mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#endif								 
#ifndef __MKV_SLIM__								 
                             case MKV_TRACK_MINCACHE:
                                 pTrack->u4MinCache = (kal_bool)_mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#endif								 
                             case MKV_TRACK_CODECID:
                             {
                                 const kal_uint8* pu1CodecID = rEBML.pu1Element;
                                 pTrack->CodecID = _mkv_parser_read_codec(pu1CodecID, rEBML.u4ElementSize);
                                 //ASSERT(pTrack->CodecID != MKV_CODECID_UNKNOW);  // TODO: must be remove!!
                             }
                                 break;
                             case MKV_TRACK_CODECPRIVATE:
                                 pTrack->u4CodecPrivateLen = rEBML.u4ElementSize;							 	
                                 pTrack->pu1CodecPrivate = (kal_uint8*)pParser->fpMalloc(pUserMem, pTrack->u4CodecPrivateLen + 1, KAL_FALSE);
                                 if(pTrack->pu1CodecPrivate)
                                 {
                                     kal_mem_cpy(pTrack->pu1CodecPrivate, rEBML.pu1Element, pTrack->u4CodecPrivateLen);
                                 }
                                 break;
                             case MKV_TRACK_DEFAULT_DURATION:
                                 pTrack->u8DefaultDuration = _mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#ifdef __VE_SUBTITLE_SUPPORT__								 
                             case MKV_TRACK_LANGUAGE:
                                 pTrack->pu1Language = (kal_uint8*)pParser->fpMalloc(pUserMem, rEBML.u4ElementSize + 1, KAL_FALSE);
                                 if(pTrack->pu1Language)
                                 {
                                     kal_mem_cpy(pTrack->pu1Language, rEBML.pu1Element, rEBML.u4ElementSize);
                                 }
                                 break;
#endif								 
#ifndef __MKV_SLIM__								 
                             case MKV_TRACK_NAME:
                                 pTrack->pu1Name = (kal_uint8*)pParser->fpMalloc(pUserMem, rEBML.u4ElementSize + 1, KAL_TRUE);
                                 kal_mem_cpy(pTrack->pu1Name, rEBML.pu1Element, rEBML.u4ElementSize);
                                 break;
#endif								 
                             case MKV_TRACK_VIDEO_ID:
                             {
                                 kal_uint32 u4TrackVideoLen = rEBML.u4ElementSize;
                                 pTrack->VideoInfo = (mkv_parser_track_video *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_track_video), KAL_TRUE);

                                 pTrackPrivatebuf = rEBML.pu1Element;
                                 while(u4TrackVideoLen > u4Offset2)
                                 {
                                     mkv_ebml_element rVideoEBML;
                                     _mkv_read_EBML(pTrackPrivatebuf+u4Offset2, NULL, NULL, NULL, &rVideoEBML);
                                     u4Offset2 += rVideoEBML.u4EbmlTotalLength;

                                     switch(rVideoEBML.u4EbmlID)
                                     {
                                        case MKV_TRACK_VIDEO_PIXEL_WIDTH:
                                            pTrack->VideoInfo->u4PixelWidth= _mkv_read_byte(rVideoEBML.pu1Element, rVideoEBML.u4ElementSize);
                                            break;
                                        case MKV_TRACK_VIDEO_PIXEL_HEIGHT:
                                            pTrack->VideoInfo->u4PixelHeight= _mkv_read_byte(rVideoEBML.pu1Element, rVideoEBML.u4ElementSize);
                                            break;
#ifndef __MKV_SLIM__											
                                        case MKV_TRACK_VIDEO_DISPLAY_WIDTH:
                                            pTrack->VideoInfo->u4DisplayWidth = _mkv_read_byte(rVideoEBML.pu1Element, rVideoEBML.u4ElementSize);
                                            break;
                                        case MKV_TRACK_VIDEO_DISPLAY_HEIGHT:
                                            pTrack->VideoInfo->u4DisplayHeight= _mkv_read_byte(rVideoEBML.pu1Element, rVideoEBML.u4ElementSize);
                                            break;
#endif											
#ifdef __VE_3D_SIDE_BY_SIDE__
                                        case MKV_TRACK_VIDEO_STEREOMODE:
                                            pTrack->VideoInfo->u4StereoMode= _mkv_read_byte(rVideoEBML.pu1Element, rVideoEBML.u4ElementSize);
                                            break;
#endif											
                                        default :
                                            break;
                                     }
                                 }
                             }
                                 break;
                             case MKV_TRACK_AUDIO_ID:
                             {
                                 kal_uint32 u4TrackAudioLen = rEBML.u4ElementSize;

                                 pTrack->AudioInfo = (mkv_parser_track_audio *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_track_audio), KAL_TRUE);

                                 /* Set default value*/
                                 pTrack->AudioInfo->u4SamplingFrequency = 8000;                                 
                                 pTrack->AudioInfo->u4Channels = 1;

                                 pTrackPrivatebuf = rEBML.pu1Element;

                                 while(u4TrackAudioLen > u4Offset2)
                                 {
                                     mkv_ebml_element rAudioEBML;
                                     _mkv_read_EBML(pTrackPrivatebuf+u4Offset2, NULL, NULL, NULL, &rAudioEBML);
                                     u4Offset2 += rAudioEBML.u4EbmlTotalLength;

                                     switch(rAudioEBML.u4EbmlID)
                                     {
                                        case MKV_TRACK_AUDIO_SAMPLING_FREQUENCY:
                                            pTrack->AudioInfo->u4SamplingFrequency = _mkv_read_float(rAudioEBML.pu1Element, rAudioEBML.u4ElementSize);
                                            break;
#ifndef __MKV_SLIM__											
                                        case MKV_TRACK_AUDIO_OUTPUT_SAMPLING_FREQUENCY:
                                            pTrack->AudioInfo->u4OutputsamplingFrequency = _mkv_read_float(rAudioEBML.pu1Element, rAudioEBML.u4ElementSize);
                                            break;
#endif											
                                        case MKV_TRACK_AUDIO_CHANNELS:
                                            pTrack->AudioInfo->u4Channels = _mkv_read_byte(rAudioEBML.pu1Element, rAudioEBML.u4ElementSize);
                                            break;
                                        case MKV_TRACK_AUDIO_BITDEPTH:
                                            pTrack->AudioInfo->u4BitDepth = _mkv_read_byte(rAudioEBML.pu1Element, rAudioEBML.u4ElementSize);
                                            break;
                                        default :
                                            break;
                                     }
                                 }
#ifndef __MKV_SLIM__								 
                                 if(pTrack->AudioInfo->u4OutputsamplingFrequency == 0)
                                 {
                                     pTrack->AudioInfo->u4OutputsamplingFrequency = pTrack->AudioInfo->u4SamplingFrequency;								 
                                 }
#endif								 
                             }
                                 break;
                             case MKV_TRACK_CONTENT_ENCODINGS_ID:  //LEVEL 3
                             {
                                 kal_uint32 u4TrackContentEncodingsLen = rEBML.u4ElementSize;

                                 pTrackPrivatebuf = rEBML.pu1Element;
                                 while(u4TrackContentEncodingsLen > u4Offset2)
                                 {
                                     kal_uint32 u4TrackContentEncodingID;

                                     kal_uint32 u4Offset3 = 0;
                                     u4Len = _mkv_parser_get_vint_size(pTrackPrivatebuf + u4Offset2);
                                     u4TrackContentEncodingID = _mkv_read_byte(pTrackPrivatebuf + u4Offset2, u4Len);
                                     u4Offset2 += u4Len;

                                     switch(u4TrackContentEncodingID)
                                     {
                                         case MKV_TRACK_CONTENT_ENCODING_ID:	//LEVEL 4
                                         {
                                             kal_uint32 u4TrackContentEncodingLen;										 	
                                             pTrack->i4ContentCompAlgo = -1;  // set not support default. 
                                             u4TrackContentEncodingLen = _mkv_read_vint(pTrackPrivatebuf + u4Offset2, NULL, NULL, &u4Len);
                                             u4Offset2 += u4Len;											 
                                             pTrackPrivatebuf += u4Offset2;
                                             while(u4TrackContentEncodingLen > u4Offset3)
                                             {

                                                 kal_uint32 u4Offset4 = 0;

                                                 mkv_ebml_element rTrackCompressionEBML;
                                                 _mkv_read_EBML(pTrackPrivatebuf + u4Offset3, NULL, NULL, NULL, &rTrackCompressionEBML);
                                                 u4Offset3 += rTrackCompressionEBML.u4EbmlTotalLength;
												 
                                                 switch(rTrackCompressionEBML.u4EbmlID)
                                                 {
                                                     case MKV_TRACK_CONTENT_ENCODING_TYPE:
                                                     {
                                                         kal_uint32 u4TrackContentEncodingType = _mkv_read_byte(rTrackCompressionEBML.pu1Element, rTrackCompressionEBML.u4ElementSize);

                                                         if(u4TrackContentEncodingType != 0)
                                                         {
                                                             pTrack->i4ContentCompAlgo = -1;
                                                         }
                                                     }													 	
                                                         break;
                                                     case MKV_TRACK_CONTENT_COMPRESSION:  //LEVEL 5
                                                     {
                                                         kal_uint32 u4TrackContentCompressionLen = rTrackCompressionEBML.u4ElementSize;

                                                         pTrackPrivatebuf = rTrackCompressionEBML.pu1Element;
                                                         while(u4TrackContentCompressionLen > u4Offset4)
                                                         {
                                                             mkv_ebml_element rContentCompEBML;
                                                             _mkv_read_EBML(pTrackPrivatebuf + u4Offset4, NULL, NULL, NULL, &rContentCompEBML);
                                                             u4Offset4 += rContentCompEBML.u4EbmlTotalLength;
															 
                                                             switch(rContentCompEBML.u4EbmlID)
                                                             {
                                                                 case MKV_TRACK_CONTENT_COMPALGO:  //LEVEL 6
                                                                     pTrack->i4ContentCompAlgo = _mkv_read_byte(rContentCompEBML.pu1Element, rContentCompEBML.u4ElementSize);
                                                                     break;
                                                                 case MKV_TRACK_CONTENT_COMPSETTINGS:  //LEVEL 6
                                                                 {													
                                                                     pTrack->pu1ContentCompSettingLen = rContentCompEBML.u4ElementSize;
																	
                                                                     pTrack->pu1ContentCompSettings = (kal_uint8 *)pParser->fpMalloc(pUserMem, pTrack->pu1ContentCompSettingLen + 1, KAL_TRUE);
                                                                     if(pTrack->pu1ContentCompSettings)
                                                                     {
                                                                         kal_mem_cpy(pTrack->pu1ContentCompSettings, rContentCompEBML.pu1Element, pTrack->pu1ContentCompSettingLen);
                                                                     }
                                                                 }
                                                                     break; 												
                                                                 default:
#ifdef __MKV_PARSER_ASSERTUNKNOW__            																 	
                                                                     ASSERT(0);
#endif
                                                                     break;
                                                             }
                                                         }														 
                                                     }
                                                         break;
                                                     default:  //skip
                                                         break;
                                                 }
                                             }
                                             u4Offset2 += u4TrackContentEncodingLen;											 
                                         }
                                             break;
                                         default:
#ifdef __MKV_PARSER_ASSERTUNKNOW__										 	
                                             ASSERT(0);
#else
                                             u4TrackContentEncodingsLen = u4Offset2;
#endif
                                             break; 											
                                     }										 
                                 }
                             }
                                 break;	 	
                             default:
                                 break;
                         }

                     }
                     u4Offset += u4Offset1;

                 }
                 pParser->fpMfree(pUserMem, (void**)&pTracksbuf);
                 result = KAL_TRUE;
             }
#ifndef __MKV_SLIM__					 
        }
    }
#endif

    return result;
}

#ifdef __MKV_INDEX_TABLE__	
static void _mkv_parser_indextable_compress(MKV_PROVIDER_INDEX_TABLE* indextable)
{
    kal_uint32 index;
    kal_uint32 u4Used = 0;
	
    indextable->u4CompressedTime = indextable->table[MKV_PARSER_INDEX_TABLE_COUNT-1].u4Time;
    for(index = 0; index < MKV_PARSER_INDEX_TABLE_COUNT;) 
    {
        kal_mem_cpy(&indextable->table[index/2],&indextable->table[index], sizeof(MKV_PROVIDER_INDEX_ITEM));
		u4Used++;
		index += 2;
    }
	
    indextable->u4Used = u4Used;
}
#endif

static void _mkv_parser_indextable_add(mkv_parser* pParser, kal_uint32 u4KeyframeTime, mkv_parser_cluster* pCluster, kal_uint32 u4TrackNumber, kal_uint32 u4MinKeyframeInterval)
{					
#ifdef __MKV_INDEX_TABLE__	
    if((pParser->pIndexTable->u4MaxTime + u4MinKeyframeInterval) < u4KeyframeTime)
    {
        pParser->pIndexTable->u4MaxTime = u4KeyframeTime;
        if(pParser->pIndexTable->u4Used == MKV_PARSER_INDEX_TABLE_COUNT)
        {
            _mkv_parser_indextable_compress(pParser->pIndexTable);
        }
        if(pParser->pIndexTable->u4Used < MKV_PARSER_INDEX_TABLE_COUNT)
        {
            MKV_PROVIDER_INDEX_ITEM* pTable = &(pParser->pIndexTable->table[pParser->pIndexTable->u4Used]);
            pTable->u4Time = u4KeyframeTime;
            pTable->u4ClusterPosition = pCluster->u4ClusterStart;		
            pTable->u4ClusterOffset = pCluster->u4Offset;
            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_INDEXTABLE_ADD, pParser->pIndexTable->u4Used, u4KeyframeTime, (kal_uint32)pTable->u4ClusterPosition, u4TrackNumber);		
            pParser->pIndexTable->u4Used++;
        }
    }
#endif

}

static kal_uint32 _mkv_parser_read_block(kal_uint32 u4ElementID, mkv_parser* pParser, kal_uint32 u4TrackNumber, void* pReadhdr, mkv_parser_cluster* pCluster, kal_uint32 u4Len, mkv_parser_block* pBlock)
{
    kal_uint32 result = 0; //Tracknumber (0: means error)
#ifndef __MKV_SLIM__	    
    if(pParser && pCluster && pReadhdr && pParser->fpRead && pParser->fpSeek && pParser->fpGetcurpos && pParser->fpMalloc && pParser->fpMfree)
    {
#endif    
        kal_uint8 *pBuf = NULL;
        pBuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, 11, KAL_TRUE);
        if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 4) == 4)
        {
            kal_uint32 u4Offset = 1;
            kal_uint8 u1Flag;
                        
            if(u4Offset == _mkv_parser_get_vint_size(pBuf))
            {            
                mkv_parser_block* block;
                kal_uint32 u4Track;
                kal_int16 i2Timecode;
                u4Track = _mkv_read_vint(pBuf, NULL, NULL, &u4Offset);				
                result = u4Track;

                i2Timecode = _mkv_read_byte(pBuf+u4Offset, 2);	
                u4Offset += 2;  //Timecode
                
                u1Flag = _mkv_read_byte(pBuf+u4Offset, 1);
#ifdef __MKV_INDEX_TABLE__		
                if (pParser->u1VideoTrackIndex == u4Track)
                {
                    if(u4ElementID == MKV_CLUSTER_SIMPLEBLOCK && ((u1Flag & MKV_BLOCKFLAG_KEYFRAME) >> 7))
                    {
                        kal_uint32 u4KeyframeTime; 
                        u4KeyframeTime = pCluster->u4TimeCode + i2Timecode;
                        u4KeyframeTime = _mkv_parser_getscaletime(pParser, u4KeyframeTime);
                        _mkv_parser_indextable_add(pParser, u4KeyframeTime, pCluster, u4TrackNumber, MKV_PARSER_INDEX_TABLE_MIN_TIMEINTERVAL);
                    }
                }
#endif
                if (u4TrackNumber != u4Track)
                {
                    kal_uint32 u4Timestamp; 
   					u4Timestamp = pCluster->u4TimeCode + i2Timecode;   
                    u4Timestamp = _mkv_parser_getscaletime(pParser, u4Timestamp);					
                    MKV_TRACE2(TRACE_GROUP_2, MKVPARSER_BLOCK_INFO, u4Track, u4Timestamp);
		
#ifdef __MKV_CLUSTER_TABLE__
                    if(pParser->u1VideoTrackIndex == u4Track || pParser->u1AudioTrackIndex == u4Track ||pParser->u1SubtitleTrackIndex == u4Track)
                    {
                        kal_int16 u2ClusterId = -1;

                        kal_uint32 index;
                        for(index = 0; index < MKV_PARSER_CLUSTER_CACHE_COUNT; index++)
                        {
                            if(pParser->rCacheCluster[index].u4ClusterBase == pCluster->u4ClusterBase)
                            {
                                u2ClusterId = (kal_int16)index;
                                break;
                            }
                            else if(pParser->rCacheCluster[index].u4ClusterBase > pCluster->u4ClusterBase)
                            {
                                u2ClusterId = -1;
                                break;
                            }									
                        }
						

                        if(index == MKV_PARSER_CLUSTER_CACHE_COUNT 
                           && pParser->pClusterTable->u1ClusterInfoUsed < MKV_PARSER_CLUSTER_CACHE_COUNT && pParser->pClusterTable->u4Used < MKV_PARSER_CLUSTER_TABLE_COUNT
                           && pCluster->u4ClusterBase > pParser->rCacheCluster[pParser->pClusterTable->u1ClusterInfoMaxBase].u4ClusterBase)
                        {
                            MKV_PARSER_CLUSTER_INOF* prWriteCacheCluster = &(pParser->rCacheCluster[pParser->pClusterTable->u1ClusterInfoWrite]);
#ifdef __MKV_PARSER_DEBUG__                            
                            if(prWriteCacheCluster->u4ClusterBase != 0 || 
                               prWriteCacheCluster->u2Used != 0)
                            {
                                // check variable correct !! write index value (u4ClusterBase, u2Used) should equle to 0
                                ASSERT(0);
                            }							

                            prWriteCacheCluster->u2CacheCount[0] = 0;
                            prWriteCacheCluster->u2CacheCount[1] = 0;
#ifdef __VE_SUBTITLE_SUPPORT__								
                            prWriteCacheCluster->u2CacheCount[2] = 0;								
#endif
#endif								
                            prWriteCacheCluster->u4ClusterBase = pCluster->u4ClusterBase;
                            prWriteCacheCluster->u4MinOffset = pCluster->u4Offset;
                            prWriteCacheCluster->u4MaxOffset = 0;								
                            prWriteCacheCluster->fgDisableFill = KAL_FALSE;								
                            prWriteCacheCluster->u1TrackOwner = u4TrackNumber;								
                            prWriteCacheCluster->u4Timecode = pCluster->u4TimeCode;

                            u2ClusterId = pParser->pClusterTable->u1ClusterInfoWrite;
                            pParser->pClusterTable->u1ClusterInfoMaxBase = pParser->pClusterTable->u1ClusterInfoWrite;

                            pParser->pClusterTable->u1ClusterInfoUsed++;
                            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTER_ADD, u4TrackNumber, (kal_uint32)pCluster->u4ClusterBase, pParser->pClusterTable->u1ClusterInfoWrite, pParser->pClusterTable->u1ClusterInfoUsed); 				
 
                            pParser->pClusterTable->u1ClusterInfoWrite++;								
                            if(MKV_PARSER_CLUSTER_CACHE_COUNT == pParser->pClusterTable->u1ClusterInfoWrite)
                            {
                                pParser->pClusterTable->u1ClusterInfoWrite = 0;
                            }
                        }

                        if(u2ClusterId != -1)
                        {
                            if(pParser->pClusterTable->u4Used == MKV_PARSER_CLUSTER_TABLE_COUNT || pParser->rCacheCluster[u2ClusterId].fgDisableFill)
                            {	
                                MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTERTABLE_SKIP, u4Track, pCluster->u4Offset, pParser->rCacheCluster[u2ClusterId].u4MaxOffset, pParser->pClusterTable->u1ClusterInfoUsed);				                            
                                pParser->rCacheCluster[u2ClusterId].fgDisableFill = KAL_TRUE;
                                u2ClusterId = -1;                                
                            }					
                        }                        

                        if(u2ClusterId != -1 && pCluster->u4ClusterBase == pParser->rCacheCluster[pParser->pClusterTable->u1ClusterInfoMaxBase].u4ClusterBase)
                        {
                            if(pCluster->u4Offset > pParser->rCacheCluster[u2ClusterId].u4MaxOffset && pParser->rCacheCluster[u2ClusterId].u1TrackOwner == u4TrackNumber)
                            {
                                MKV_PARSER_CLUSTER_ELEMENT* pTable = &(pParser->pClusterTable->table[pParser->pClusterTable->u4Write]);
                                MKV_PARSER_CLUSTER_INOF* prCacheCluster = &(pParser->rCacheCluster[u2ClusterId]);
                                MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTERTABLE_ADD, u4Track, pCluster->u4Offset, pParser->pClusterTable->u4Write, pParser->pClusterTable->u4Used+1);						    
                                pTable->u2TrackID = u4Track;
                                pTable->u4Offset = pCluster->u4Offset;
                                pTable->u2ClusterID = u2ClusterId;								
                                prCacheCluster->u2Used++;
                                prCacheCluster->u4MaxOffset = pCluster->u4Offset;
                                prCacheCluster->u4MaxTimestamp= u4Timestamp;								
                                if(pParser->u1VideoTrackIndex == u4Track)
                                {
                                    prCacheCluster->u2CacheCount[1]++;
                                }
                                else if(pParser->u1AudioTrackIndex == u4Track)
                                {
                                    prCacheCluster->u2CacheCount[0]++;
                                }
#ifdef __VE_SUBTITLE_SUPPORT__									
                                else if(pParser->u1SubtitleTrackIndex == u4Track)
                                {
                                    prCacheCluster->u2CacheCount[2]++;
                                }
#endif									
#ifdef __MKV_PARSER_DEBUG__	
                                pTable->u4ClusterBase = pCluster->u4ClusterBase;
                                pTable->u4Timecode = u4Timestamp;
                                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPARSER_CLUSTERITEM_ADD, u4Timestamp);	
#endif							
                                pParser->pClusterTable->u4Used++;
                                pParser->pClusterTable->u4Write++;
                                if(MKV_PARSER_CLUSTER_TABLE_COUNT == pParser->pClusterTable->u4Write)
                                {
                                    pParser->pClusterTable->u4Write = 0;
                                }								

			    }
                        }																
                    }
#endif
                    pParser->fpSeek(pReadhdr, u4Len-4, MKV_SEEK_CUR);
                    pParser->fpMfree(pParser->pUserMem, (void**)&pBuf);
                    return result;
                }
                block = (mkv_parser_block *)pParser->fpMalloc(pParser->pUserMem, sizeof(mkv_parser_block), KAL_TRUE);            
                block->u4TrackNumber = u4Track;
	
                block->i2Timecode = i2Timecode;
                u4Offset += 1;  //flag
                /* read flag of simpleblock (block) */

                block->u2Lacetype = ((u1Flag & MKV_BLOCKFLAG_LACINGFLAG) >> 1);
#ifndef __MKV_SLIM__				
                block->fgInvisible = (kal_bool)((u1Flag & MKV_BLOCKFLAG_INVISIBLE) >> 3);
#endif
                if(u4ElementID == MKV_CLUSTER_SIMPLEBLOCK)
                {
#ifndef __MKV_SLIM__	                
                    block->fgDiscardable = (kal_bool)(u1Flag & MKV_BLOCKFLAG_DISCARDABLE);
#endif
                    block->fgkeyframe = (kal_bool)((u1Flag & MKV_BLOCKFLAG_KEYFRAME) >> 7);
                }

                /* for get key frame time*/
                if(pBlock)
                {
                    pParser->fpSeek(pReadhdr, u4Len-4, MKV_SEEK_CUR);
                    kal_mem_cpy(pBlock, block, sizeof(mkv_parser_block));
                    pParser->fpMfree(pParser->pUserMem, (void**)&block);
                    pParser->fpMfree(pParser->pUserMem, (void**)&pBuf);					
                    return result;                    
                }

                kal_mem_set(pBuf, 0, 11);				
                switch(block->u2Lacetype)
                {
                    case MKV_BLOCKLACING_NONE:
                        block->u4Length = u4Len - u4Offset;
                        /* deliver frame*/
                        if(pParser->fpDeliver(pParser->pUserDeliver, block)!= KAL_TRUE)
                        {
                            result = 0; //means deliver fail;
                        }
                        break;
                    case MKV_BLOCKLACING_XIPH:
                    {
                        kal_int32 index;
                        kal_uint32 offset = 0;
                        kal_uint8 *pFramelenBuf = NULL;
                        kal_uint32 acc_len = 0;
                        kal_uint32 u4BaseAddr;
                        kal_uint32* p4Framelen;
						
                        pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 1);

                        u4BaseAddr = pParser->fpGetcurpos(pReadhdr);
                        block->u4Framecount = _mkv_read_byte(pBuf, 1) + 1;
                        u4Offset++;
						
                        p4Framelen = (kal_uint32 *)pParser->fpMalloc(pParser->pUserMem, block->u4Framecount * sizeof(kal_uint32), KAL_TRUE);
                        pFramelenBuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, block->u4Framecount, KAL_TRUE);
                        pParser->fpRead(pParser->pUserRead, pReadhdr, pFramelenBuf, block->u4Framecount);
                        for(index = 0; index < block->u4Framecount - 1 ; index++)
                        {
                            kal_uint32 len = 0;
                            while(1)
                            {
                                kal_uint32 temp;
                                temp = _mkv_read_byte(pFramelenBuf + offset, 1);
                                len += temp;
                                offset++;
                                if(offset == block->u4Framecount)
                                {
                                    u4BaseAddr += offset;	
                                    u4Offset += offset;
                                    pParser->fpRead(pParser->pUserRead, pReadhdr, pFramelenBuf, block->u4Framecount);
                                    offset = 0;	
								    
                                }
                                if(temp < 255)
                                    break;
                            }
                            p4Framelen[index] = len;

                            if(u4Len < u4Offset + offset + acc_len + len)
                            {
                                p4Framelen[index] = u4Len - u4Offset - offset - acc_len;
                                break;
                            }
                            acc_len += len;
                        }
                        pParser->fpSeek(pReadhdr, u4BaseAddr + offset, MKV_SEEK_START);
                        if(index == block->u4Framecount - 1)
                        {
                            p4Framelen[index] = u4Len - u4Offset - offset - acc_len;
                        }
                        block->u4Length = u4Len - u4Offset - offset;
                        block->u4FrameLen = p4Framelen;
						
                        /* deliver frame*/
                        if(pParser->fpDeliver(pParser->pUserDeliver, block) != KAL_TRUE)
                        {
                            result = 0; //means deliver fail;
                        }
						
                        pParser->fpMfree(pParser->pUserMem, (void**)&pFramelenBuf);
                    }
                        break;
                    case MKV_BLOCKLACING_EBML:
                    {
                        kal_int32 index = 0;
                        kal_uint32 offset = 0;
                        kal_uint8 *pFramelenBuf = NULL;
                        kal_uint32 acc_len = 0;
                        kal_uint32* p4Framelen;

                        pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 1);

                        block->u4Framecount = _mkv_read_byte(pBuf, 1) + 1;
                        u4Offset++;

                        p4Framelen = (kal_uint32 *)pParser->fpMalloc(pParser->pUserMem, block->u4Framecount * sizeof(kal_uint32), KAL_TRUE);
                        pFramelenBuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, 8, KAL_TRUE);
                        pParser->fpRead(pParser->pUserRead, pReadhdr, pFramelenBuf, 1);
                        p4Framelen[index] = _mkv_read_vint(pFramelenBuf, pParser, pReadhdr, &offset);
                        u4Offset += offset;                        
                        if(u4Len < u4Offset + p4Framelen[index])
                        {
                            p4Framelen[index] = u4Len - u4Offset;
                        }
                        acc_len += p4Framelen[index];
						
                        for(index = 1; index < block->u4Framecount - 1 ; index++)
                        {
                            kal_mem_set(pFramelenBuf, 0, 8);
                            pParser->fpRead(pParser->pUserRead, pReadhdr, pFramelenBuf, 1);						
                            p4Framelen[index] = p4Framelen[index-1] + _mkv_read_svint(pFramelenBuf, pParser, pReadhdr, &offset);
                            u4Offset += offset;

                            if(u4Len < u4Offset + acc_len + p4Framelen[index] || u4Len < p4Framelen[index])
                            {
                                if(u4Len < u4Offset + acc_len)
                                {
                                    p4Framelen[index] = 0;
                                }
                                else
                                {
                                    p4Framelen[index] = u4Len - u4Offset - acc_len;
                                }
                                break;
                            }
                            acc_len += p4Framelen[index];
                        }
                        if(index == block->u4Framecount - 1)
                        {
                            p4Framelen[index] = u4Len - u4Offset - acc_len;
                        }
                        block->u4Length = u4Len - u4Offset;
                        block->u4FrameLen = p4Framelen;

						/* deliver frame*/
                        if(pParser->fpDeliver(pParser->pUserDeliver, block) != KAL_TRUE)
                        {
                            result = 0; //means deliver fail;
                        }						
						
                        pParser->fpMfree(pParser->pUserMem, (void**)&pFramelenBuf);

                    }
                        break;
                    case MKV_BLOCKLACING_FIXED:
                    {
                        kal_int32 index = 0;
                        kal_int32 u4length;
                        kal_uint32* p4Framelen;

                        pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 1);

                        block->u4Framecount = _mkv_read_byte(pBuf, 1) + 1;
                        u4Offset++;
                        p4Framelen = (kal_uint32 *)pParser->fpMalloc(pParser->pUserMem, block->u4Framecount * sizeof(kal_uint32), KAL_TRUE);
                        block->u4Length = u4Len - u4Offset;
                        u4length = block->u4Length/block->u4Framecount;
                        for(index = 0; index < block->u4Framecount; index++)
                        {
                            p4Framelen[index] = u4length;
                        }

                        block->u4FrameLen = p4Framelen;										
                        /* deliver frame*/
                        if(pParser->fpDeliver(pParser->pUserDeliver, block) != KAL_TRUE)
                        {
                            result = 0; //means deliver fail;
                        }                        
											
                    }	
                        break;
#ifdef __MKV_SLIM__						
                    default:
                        ASSERT(0);
                        break;
#endif						
                }
			
            }
            else
            {
#ifdef __MKV_PARSER_ASSERTUNKNOW__            
                ASSERT(0);
#endif
            }

        }
        pParser->fpMfree(pParser->pUserMem, (void**)&pBuf);
#ifndef __MKV_SLIM__			
    }
#endif	
    return result;
}

static MKV_PARSER_ERROR_T _mkv_parser_read_cluster_element(mkv_parser* pParser, kal_uint32 u4TrackNumber, void* pReadhdr, mkv_parser_cluster* pCluster, mkv_parser_block* pBlock)
{
    MKV_PARSER_ERROR_T result = MKV_PARSER_ERROR_NONE;
#ifndef __MKV_SLIM__		
    if(pParser && pCluster && pReadhdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    {
#endif    
        kal_uint8 *pBuf = NULL;
        const void* pUserMem = pParser->pUserMem;
        kal_uint64 u8Pos = pParser->fpGetcurpos(pReadhdr);			

#if 0
/* under construction !*/
/* under construction !*/
#endif

        pBuf = (kal_uint8 *)pParser->fpMalloc(pUserMem, 12, KAL_TRUE);  // 4 + 8
        if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 2) == 2)
        {
            kal_uint32 u4IDsize;
            kal_uint32 u4ElementID;
            kal_uint32 u4ElementLen;
            kal_uint32 u4Lensize;
            u4IDsize = _mkv_parser_get_vint_size(pBuf);
#ifndef __MKV_SLIM__			
            if(u4IDsize > 1)
            {
#endif
                if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf+2, u4IDsize-1) != (u4IDsize-1))
                {
                    pCluster->u4Offset = pCluster->u4Length;
                    pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase + pCluster->u4Length, MKV_SEEK_START);
                    MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_ERROR, __LINE__, MKV_PARSER_ERROR_CORRUPT);    							
                    return MKV_PARSER_ERROR_CORRUPT;
                }								
#ifndef __MKV_SLIM__				
            }
#endif			

            u4ElementID = _mkv_read_byte(pBuf, u4IDsize);

            u4ElementLen = _mkv_read_vint(pBuf + u4IDsize, pParser, pReadhdr, &u4Lensize);

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
#endif
            switch(u4ElementID)
            {
                case MKV_CLUSTER_BLOCKGROUP:
                {
                    kal_uint32 u4Offset = 0;
                    kal_uint32 u4Blockduration = 0;
                    kal_uint32 u4BlockTrackNumber = 0;
					
                    while(u4ElementLen > u4Offset)					
                    {
                        mkv_ebml_element rEBML;						
						 
                        kal_mem_set(pBuf, 0, 12);
						
                        if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 2) != 2)
                        {
                            break;
                        }

                        _mkv_read_EBML(pBuf, MKV_CLASS_A_ELEMENTS_SIZE + 1, pParser, pReadhdr, &rEBML);
                        u4Offset += rEBML.u4EbmlTotalLength;						

                        switch(rEBML.u4EbmlID)
                        {
                            case MKV_CLUSTER_BLOCK:
                            {

                                u4BlockTrackNumber = _mkv_parser_read_block(u4ElementID, pParser, u4TrackNumber, pReadhdr, pCluster, rEBML.u4ElementSize, pBlock);
                                if(0 == u4BlockTrackNumber)
                                {
                                    u4Offset = u4ElementLen;
                                }

                            }
                                break;
                            case MKV_CLUSTER_BLOCK_DURATION:
                            {
                                kal_uint32 u4Len = rEBML.u4ElementSize; 

                                kal_mem_set(pBuf, 0, 12);
                                pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, u4Len);
								
                                u4Blockduration = _mkv_read_byte(pBuf, u4Len);

                            }								
                                break;
                            case MKV_CLUSTER_BLOCK_REFERENCEBLOCK:
                            {
                                kal_uint32 u4Len = rEBML.u4ElementSize; 
								
                                pParser->fpSeek(pReadhdr, u4Len, MKV_SEEK_CUR); 
                            }
                                break;	
                            default:
#ifdef __MKV_PARSER_ASSERTUNKNOW__								
                                ASSERT(0);
#else
                                u4Offset = u4ElementLen;
#endif
                                break;
                        }

                    }
                    if(u4TrackNumber == u4BlockTrackNumber)
                    {
                        /*  send a dummy frame for block duration case */
                        if(u4Blockduration > 0)
                        {
                            mkv_parser_block* block;
                            block = (mkv_parser_block *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_block), KAL_TRUE); 
                            block->u4TrackNumber = u4BlockTrackNumber;
                            block->u4Duration = u4Blockduration;
                            block->fgDuration = KAL_TRUE;
                            pParser->fpDeliver(pParser->pUserDeliver, block);
                        }
                    }
                }
                    break;
                case MKV_CLUSTER_SIMPLEBLOCK:
                {
                    _mkv_parser_read_block(u4ElementID, pParser, u4TrackNumber, pReadhdr, pCluster, u4ElementLen, pBlock);					
                }
                    break;
                case MKV_CLUSTER_ID:
                {							
                    pCluster->u4Offset = pCluster->u4Length;
                    pParser->fpSeek(pReadhdr, u8Pos, MKV_SEEK_START);					
                }
                    break;					
                default:  //seek pass unknown ID
#ifdef __MKV_PARSER_ASSERTUNKNOW__   
                    ASSERT(0);
#else                
                    if(u4ElementLen < (pCluster->u4Length - pCluster->u4Offset - u4IDsize - u4Lensize))
                    {
                        pParser->fpSeek(pReadhdr, u4ElementLen, MKV_SEEK_CUR);
                    }
                    else
                    {
                        pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase + pCluster->u4Length, MKV_SEEK_START);
                    }
#endif					
                    break;
            }
            if(pCluster->u4Offset < pCluster->u4Length)
            {
                pCluster->u4Offset += (u4IDsize+u4Lensize+u4ElementLen);
            }
        }
        else
        {
            if(pParser->u4SegmentLength != MKV_UNKNOWN_LENGTH)        
            {
                result = MKV_PARSER_ERROR_CORRUPT;
                MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_ERROR, __LINE__, MKV_PARSER_ERROR_CORRUPT);    					
            }					
            else
            {
                result = MKV_PARSER_ERROR_EOF;
            }
        }
		
        pParser->fpMfree(pUserMem, (void**)&pBuf);
#ifndef __MKV_SLIM__			
    }
#endif	
    return result;
}


static MKV_PARSER_ERROR_T _mkv_parser_read_cluster_info(mkv_parser* pParser, void* pReadhdr, mkv_parser_cluster* pCluster)
{
    MKV_PARSER_ERROR_T result = MKV_PARSER_ERROR_NONE;
#ifndef __MKV_SLIM__		
    if(pParser && pReadhdr && pParser->fpRead && pParser->fpSeek && pParser->fpMalloc && pParser->fpMfree)
    {
#endif    
        kal_uint8 *pBuf = NULL;
		kal_uint32 readlen = 0;

        pCluster->u4Length = 0;
        pBuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, 13, KAL_TRUE);
        readlen = pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 5);
        if (readlen == 5)
        {
#ifndef __MKV_SLIM__        
            if(_mkv_parser_get_vint_size(pBuf) == MKV_CLASS_D_ELEMENTS_SIZE)
            {
#endif            
                if(_mkv_read_byte(pBuf, MKV_CLASS_D_ELEMENTS_SIZE) == MKV_CLUSTER_ID)
                {
                     kal_uint32 u4Offset = 0;
                     kal_uint32 u4Size = 0;
                     kal_uint32 u4ClusterLen;
					 
#if defined(__MKV_INDEX_TABLE__) || defined(__MKV_CLUSTER_TABLE__)
                     pCluster->u4ClusterStart = pParser->fpGetcurpos(pReadhdr) - 5; 
#endif
				 	
                     u4ClusterLen = _mkv_read_vint(pBuf + 4 , pParser, pReadhdr, &u4Size);
                     pCluster->u4Length = u4ClusterLen;
                     pCluster->u4ClusterBase = pParser->fpGetcurpos(pReadhdr);

                     while(u4ClusterLen > u4Offset)
                     {
                         kal_uint32 u4ElementID;
                         kal_uint32 u4IDLen = 0;
                         kal_uint32 u4ElementLen;

                         kal_mem_set(pBuf, 0, 13);

                         if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, 2) != 2)
                         {
                            break;
                         }

                         u4IDLen = _mkv_parser_get_vint_size(pBuf);
                         if(u4IDLen > 1)
                         {
                             if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf+2, u4IDLen-1) != (u4IDLen-1))
                             {
                                break;
                             }								 
                         }
						 
                         u4ElementID = _mkv_read_byte(pBuf, u4IDLen);
                         u4Offset += u4IDLen;

                         switch(u4ElementID)
                         {
                             case MKV_CLUSTER_TIMECODE:
                                 u4ElementLen = _mkv_read_vint(pBuf+u4IDLen, pParser, pReadhdr, &u4Size);
                                 u4Offset += u4Size;

                                 kal_mem_set(pBuf, 0, 13);
                                 if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, u4ElementLen) != u4ElementLen)
                                 {
                                    u4ClusterLen = 0; //break while loop
                                    // error
                                    break;
                                 }
                                 pCluster->u4TimeCode = _mkv_read_byte(pBuf, u4ElementLen);
                                 u4Offset += u4ElementLen;								 
                                 break;
#ifndef __MKV_SLIM__								 
                             case MKV_CLUSTER_POSITION:
                             case MKV_CLUSTER_PRESIZE:
                                 u4ElementLen = _mkv_read_vint(pBuf+u4IDLen, pParser, pReadhdr, &u4Size);
                                 u4Offset += u4Size;

                                 kal_mem_set(pBuf, 0, 13);
                                 if (pParser->fpRead(pParser->pUserRead, pReadhdr, pBuf, u4ElementLen) != u4ElementLen)
                                 {
                                    u4ClusterLen = 0; //break while loop
                                    // error
                                    break;
                                 }
                                 u4Offset += u4ElementLen;
                                 break;
#endif								 
                             case MKV_CLUSTER_BLOCKGROUP:
                             case MKV_CLUSTER_BLOCK:
                             case MKV_CLUSTER_SIMPLEBLOCK:
                                u4Offset -= u4IDLen;
                                u4ClusterLen = 0; //break while loop
                                break;

                             default:  //seek pass unknown ID
#ifdef __MKV_PARSER_ASSERTUNKNOW__   
                                 ASSERT(0);
#else
                                 u4ElementLen = _mkv_read_vint(pBuf+u4IDLen, pParser, pReadhdr, &u4Size);
                                 u4Offset += u4Size;
                                 if(u4ElementLen < u4ClusterLen)
                                 {
                                     pParser->fpSeek(pReadhdr, u4ElementLen, MKV_SEEK_CUR);
                                 }
                                 else
                                 {
                                     pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase + pCluster->u4Length, MKV_SEEK_START);
                                 }
                                 u4Offset += u4ElementLen;
#endif								 
                                 break;
                         }
                         //ASSERT(pCluster->u4Length > u4Offset); // TODO: must remove!!
                     }

#ifdef __MKV_INDEX_TABLE__
                     if(NULL == pParser->u4CuesBase)
                     {
                         if(pCluster->u4ClusterStart > pParser->rClusterCache[0].u4Start)
                         {
                             kal_mem_cpy((void*)&pParser->rClusterCache[1], (void*)&pParser->rClusterCache[0], sizeof(MKV_PARSER_CLUSTER_TABLE));
                             pParser->rClusterCache[0].u4Start = pCluster->u4ClusterStart;
                             pParser->rClusterCache[0].u4Timecode= pCluster->u4TimeCode;						 
                         }
                         else if(pCluster->u4ClusterStart > pParser->rClusterCache[1].u4Start)
                         {
                             pParser->rClusterCache[1].u4Start = pCluster->u4ClusterStart;
                             pParser->rClusterCache[1].u4Timecode= pCluster->u4TimeCode;						                          
                         }
                     }					 
                     if(!pParser->fgVideoTrack)
                     {
                         kal_uint32 u4KeyframeTime; 
                         u4KeyframeTime = pCluster->u4TimeCode;
                         u4KeyframeTime = _mkv_parser_getscaletime(pParser, u4KeyframeTime);
                         _mkv_parser_indextable_add(pParser, u4KeyframeTime, pCluster, 0, MKV_PARSER_INDEX_TABLE_MIN_TIMEINTERVAL);						 
                     }					 
#endif						 

                     pCluster->u4Offset = u4Offset;
                     if(pCluster->u4ClusterBase && pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase + pCluster->u4Offset, MKV_SEEK_START) != KAL_TRUE)
                     {
                         result = MKV_PARSER_ERROR_EOF;
                     }
                }
                else
                {
                    result = MKV_PARSER_ERROR_CORRUPT;                
                }
#ifndef __MKV_SLIM__				
            }
            else
            {
                result = MKV_PARSER_ERROR_CORRUPT;				  
            }
#endif			
        }
        else if(readlen == 0)
        {
            result = MKV_PARSER_ERROR_EOF;
        }
        else
        {
            result = MKV_PARSER_ERROR_CORRUPT;
            MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_ERROR, __LINE__, MKV_PARSER_ERROR_CORRUPT);    										
        }			
        pParser->fpMfree(pParser->pUserMem, (void**)&pBuf);
#ifndef __MKV_SLIM__			
    }
#endif	

    return result;
}

static kal_bool _mkv_parser_read_segment_info(mkv_parser* pParser, kal_uint8 *pbuf)
{
    kal_bool result = KAL_FALSE;
#ifndef __MKV_SLIM__		
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    {
        if(_mkv_parser_get_vint_size(pbuf) == MKV_CLASS_D_ELEMENTS_SIZE)
        {
#endif          
             if(_mkv_read_byte(pbuf, MKV_CLASS_D_ELEMENTS_SIZE) == MKV_SEGMENTINFO_ID)
             {
                 const void* pUserMem = pParser->pUserMem;             
                 kal_uint32 u4Length;
                 kal_uint8 *pSegmentbuf;
                 kal_uint32 u4Offset = 0;
                 kal_uint32 u4CRCLen;
				 
                 u4Length = _mkv_read_vint(pbuf + MKV_CLASS_D_ELEMENTS_SIZE, pParser, pParser->pfilehdr, NULL);
                 if(u4Length > SEGMENTINFO_BUFFER_SIZE)  
                 {
                     u4Length = SEGMENTINFO_BUFFER_SIZE;
                 }
				 
                 pSegmentbuf = (kal_uint8 *)pParser->fpMalloc(pUserMem, u4Length, KAL_TRUE);
                 if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pSegmentbuf, u4Length) == u4Length)
                 {
                     result = KAL_TRUE;
                 }

                 _mkv_parser_read_CRC32(pSegmentbuf+u4Offset, &u4CRCLen);
                 u4Offset += u4CRCLen;

                 /* Set default value*/
                 pParser->u4TimecodeScale = MKV_DEFAULT_TIMECODESCALE;

                 while(u4Length > u4Offset)
                 {
                     mkv_ebml_element rEBML;
					 
                     _mkv_read_EBML(pSegmentbuf + u4Offset, NULL, NULL, NULL, &rEBML);
                     u4Offset += rEBML.u4EbmlTotalLength;
					 
                     switch(rEBML.u4EbmlID)
                     {
                         case MKV_SEGMENTINFO_DURATION:
                             pParser->u4Duration = _mkv_read_float(rEBML.pu1Element, rEBML.u4ElementSize);
						 	 
                             break;
                         case MKV_SEGMENTINFO_TIMECODESCALE:
                             pParser->u4TimecodeScale = _mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);
                             break;						 	
#ifndef __MKV_SLIM__							 
                         case MKV_SEGMENTINFO_FILENAME:
                             pParser->pu1Filename = (kal_uint8 *)pParser->fpMalloc(pUserMem, rEBML.u4ElementSize, KAL_FALSE);
                             if(pParser->pu1Filename)
                             {
                                 kal_mem_cpy(pParser->pu1Filename, rEBML.pu1Element,rEBML.u4ElementSize);
                             }
                             break;
                         case MKV_SEGMENTINFO_TITLE:
                             pParser->pu1Title= (kal_uint8 *)pParser->fpMalloc(pUserMem, rEBML.u4ElementSize, KAL_FALSE);
                             if(pParser->pu1Title)
                             {
                                 kal_mem_cpy(pParser->pu1Title, rEBML.pu1Element,rEBML.u4ElementSize);
                             }
                             break;							 
#endif							 
                         default:
                             break;
                     }

                 }
                 if(MKV_DEFAULT_TIMECODESCALE != pParser->u4TimecodeScale)
                 {
                     pParser->u4Duration = pParser->u4Duration * pParser->u4TimecodeScale / MKV_DEFAULT_TIMECODESCALE; 	
                 }

                 pParser->fpMfree(pUserMem, (void**)&pSegmentbuf);
             }
#ifndef __MKV_SLIM__						 
        }
    }
#endif	

    return result;
}

#ifdef __MKV_PARSER_META__
static kal_bool _mkv_parser_read_tags(mkv_parser* pParser, kal_uint8 *pbuf)
{
    kal_bool result = KAL_FALSE;
#ifndef __MKV_SLIM__		
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    {    
#endif    
        mkv_ebml_element rEBMLL1, rEBMLL2, rEBMLL3, rEBMLL4;    
        if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, MKV_CLASS_D_ELEMENTS_SIZE + 1) == (MKV_CLASS_D_ELEMENTS_SIZE + 1))
        {
            if(KAL_FALSE == _mkv_read_EBML(pbuf, MKV_CLASS_D_ELEMENTS_SIZE + 1, pParser, pParser->pfilehdr, &rEBMLL1))
            {
                return result;
            }
            if(MKV_TAGS_ID != rEBMLL1.u4EbmlID)
            {
                return result;                
			}		
        }	
        if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, MKV_CLASS_B_ELEMENTS_SIZE + 1) == (MKV_CLASS_B_ELEMENTS_SIZE + 1))
        {
            kal_uint32 u4Offset2 = 0;
            if(KAL_FALSE == _mkv_read_EBML(pbuf, MKV_CLASS_B_ELEMENTS_SIZE + 1, pParser, pParser->pfilehdr, &rEBMLL2))
            {
                return result;
            }
            if(MKV_TAG != rEBMLL2.u4EbmlID)
            {
                return result;                
            }	
            while(u4Offset2 < rEBMLL2.u4ElementSize)
            {
                if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, MKV_CLASS_B_ELEMENTS_SIZE + 1) == (MKV_CLASS_B_ELEMENTS_SIZE + 1))
                {
                    kal_uint32 u4Length;
                    kal_uint8* pTagbuf = NULL;
                    kal_uint32 u4FilePos; 
                    if(KAL_FALSE == _mkv_read_EBML(pbuf, MKV_CLASS_B_ELEMENTS_SIZE + 1, pParser, pParser->pfilehdr, &rEBMLL3))
                    {
                        u4Offset2 = rEBMLL2.u4ElementSize;
                    }
                    if(MKV_TAG_SIMPLETAG != rEBMLL3.u4EbmlID)
                    {
                        u4Offset2 += (rEBMLL3.u4EbmlTotalLength); 
                        if(pParser->fpSeek(pParser->pfilehdr, rEBMLL3.u4ElementSize, MKV_SEEK_CUR) != KAL_TRUE)
                        {
                            break;
                        }		
                        continue;
                    }

                    u4Length = rEBMLL3.u4ElementSize;
					
                    if(rEBMLL3.u4ElementSize > TAG_BUFFER_SIZE)  
                    {
                        u4Length = TAG_BUFFER_SIZE;
                    }
				 
                    pTagbuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, u4Length, KAL_FALSE);


                    u4FilePos = pParser->fpGetcurpos(pParser->pfilehdr);
                    if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pTagbuf, u4Length) == u4Length)
                    {
                        kal_uint32 u4Offset4 = 0; 						
                        kal_uint32* pu8TargetTag = NULL;
                        kal_uint32* pu4TargetTagLen = NULL;
                        while(u4Offset4 < u4Length)
                        {
                            if(KAL_TRUE == _mkv_read_EBML(pTagbuf + u4Offset4, NULL, pParser, pParser->pfilehdr, &rEBMLL4))
                            {
                                switch(rEBMLL4.u4EbmlID)
                                {
                                    case MKV_TAG_NAME:
                                        {
                                            if (strncmp("TITLE", rEBMLL4.pu1Element, 5) == 0)
                                            {
                                                pu8TargetTag = &pParser->u4Meta[MKV_META_TITLE][0];
                                                pu4TargetTagLen = &pParser->u4Meta[MKV_META_TITLE][1];
                                            }
                                            else if(strncmp("ARTIST", rEBMLL4.pu1Element, 6) == 0)
                                            {
                                                pu8TargetTag = &pParser->u4Meta[MKV_META_ARTIST][0];
                                                pu4TargetTagLen = &pParser->u4Meta[MKV_META_ARTIST][1];
                                            }
                                            else if(strncmp("DATE_RELEASED", rEBMLL4.pu1Element, 13) == 0)
                                            {
                                                pu8TargetTag = &pParser->u4Meta[MKV_META_DATE][0];
                                                pu4TargetTagLen = &pParser->u4Meta[MKV_META_DATE][1];
                                            }
                                            else if(strncmp("DESCRIPTION", rEBMLL4.pu1Element, 11) == 0)
                                            {
                                                pu8TargetTag = &pParser->u4Meta[MKV_META_ANNOTATION][0];
                                                pu4TargetTagLen = &pParser->u4Meta[MKV_META_ANNOTATION][1];
                                            }
                                            else if(strncmp("CONTENT_TYPE", rEBMLL4.pu1Element, 12) == 0)
                                            {
                                                pu8TargetTag = &pParser->u4Meta[MKV_META_TYPE][0];
                                                pu4TargetTagLen = &pParser->u4Meta[MKV_META_TYPE][1];
                                            }
                                        }
                                        break;
                                    case MKV_TAG_STRING:
                                        {
                                            if(NULL != pu8TargetTag)
                                            {
                                                *pu8TargetTag = u4FilePos + u4Offset4 + rEBMLL4.u4EbmlIDLen + rEBMLL4.u4ElementSizeLen;
                                                *pu4TargetTagLen = rEBMLL4.u4ElementSize;
                                            }
                                        }
                                        break;
                                    case MKV_TAG_LANGUAGE:
                                        break;										
                                    default:
                                        break;
                                }
                                u4Offset4 += rEBMLL4.u4EbmlTotalLength;
                            }
                            else
                            {
                                u4Offset4 = u4Length;
                            }
                        }
                    }
                    else
                    {
                        u4Offset2 = rEBMLL2.u4ElementSize;  
                    }
                    pParser->fpMfree(pParser->pUserMem, (void**)&pTagbuf);
                }	
                u4Offset2 += (rEBMLL3.u4EbmlTotalLength);
            }
        }			
#ifndef __MKV_SLIM__			
    }
#endif	

    return result;
}

static kal_bool _mkv_parser_read_atachments(mkv_parser* pParser, kal_uint8 *pbuf)
{
    kal_bool result = KAL_FALSE;
#ifndef __MKV_SLIM__		
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpMalloc && pParser->fpMfree)
    { 
#endif    
        mkv_ebml_element rEBMLL1, rEBMLL2, rEBMLL3;    
        kal_uint32 u4Offset1 = 0;
        if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, MKV_CLASS_D_ELEMENTS_SIZE + 1) == (MKV_CLASS_D_ELEMENTS_SIZE + 1))
        {
            if(KAL_FALSE == _mkv_read_EBML(pbuf, MKV_CLASS_D_ELEMENTS_SIZE + 1, pParser, pParser->pfilehdr, &rEBMLL1))
            {
                return result;
            }
            if(MKV_ATTACHMENTS_ID != rEBMLL1.u4EbmlID)
            {
                return result;                
            }		
        }	
        while(u4Offset1 < rEBMLL1.u4ElementSize)
        {
            if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, MKV_CLASS_B_ELEMENTS_SIZE + 1) == (MKV_CLASS_B_ELEMENTS_SIZE + 1))
            {
                kal_uint32 u4Offset2 = 0;
                if(KAL_FALSE == _mkv_read_EBML(pbuf, MKV_CLASS_B_ELEMENTS_SIZE + 1, pParser, pParser->pfilehdr, &rEBMLL2))
                {
                    return result;
                }
                if(MKV_ATTACHED_FILE != rEBMLL2.u4EbmlID)
                {
                    return result;                
                }	
                while(u4Offset2 < rEBMLL2.u4ElementSize)
                {                 
                    kal_uint32 u4EbmlIDLen;
                    kal_mem_set(pbuf, 0, 13);
					
                    if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, 1) != 1)					
                    {
                        break;
                    }
                    u4EbmlIDLen = _mkv_parser_get_vint_size(pbuf);
                    if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf + 1, u4EbmlIDLen) != u4EbmlIDLen)					
                    {
                        break;
                    }					
				
                    if(KAL_TRUE == _mkv_read_EBML(pbuf, NULL, pParser, pParser->pfilehdr, &rEBMLL3))
                    {
                        kal_uint8* pAttbuf = NULL;
                        kal_uint32 u4DataLength = rEBMLL3.u4ElementSize;
                        kal_uint32 u4FilePos = NULL;

						
                        rEBMLL3.pu1Element = NULL;						
                        u4FilePos = pParser->fpGetcurpos(pParser->pfilehdr);

                        if(u4DataLength > ATTACH_BUFFER_SIZE)
                        {
                            if(pParser->fpSeek(pParser->pfilehdr, u4DataLength, MKV_SEEK_CUR) != KAL_TRUE)
                            {
                                break;
                            }
                        }
                        else
                        {
                            pAttbuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, u4DataLength, KAL_FALSE);
							rEBMLL3.pu1Element = pAttbuf;
                            
                            if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pAttbuf, u4DataLength) != u4DataLength)                                
                            {
                                pParser->fpMfree(pParser->pUserMem, (void**)&pAttbuf);
                                break;
                            }
                        }                    

                        switch(rEBMLL3.u4EbmlID)
                        {
                            case MKV_FILE_NAME:
                                break;
                            case MKV_FILE_MINETYPE:
                                {
                                    if(strncmp("image/jpeg", rEBMLL3.pu1Element, 10) == 0)
                                    {
                                        pParser->u4Meta[MKV_META_THUMBTYPE][0] = MKV_MIMETYPE_JPEG;
									}
                                    if(strncmp("image/png", rEBMLL3.pu1Element, 9) == 0)
                                    {
                                        pParser->u4Meta[MKV_META_THUMBTYPE][0] = MKV_MIMETYPE_PNG;
                                    }
                                }
                                break;
                            case MKV_FILE_DATA:
                                {
                                    pParser->u4Meta[MKV_META_THUMB][0] = u4FilePos;
                                    pParser->u4Meta[MKV_META_THUMB][1] = rEBMLL3.u4ElementSize;
                                }
                                break;
                            case MKV_FILE_UID:
                                break;							
                            default:
                                break;
                        }
                        u4Offset2 += (rEBMLL3.u4EbmlTotalLength);
                        if(pAttbuf)
                        {
                            pParser->fpMfree(pParser->pUserMem, (void**)&pAttbuf);
                        }
                    }
                    else
                    {
                        u4Offset2 = rEBMLL2.u4ElementSize;
                    }
                }
            }
            u4Offset1 += (rEBMLL2.u4EbmlTotalLength);
        }
#ifndef __MKV_SLIM__			
    }
#endif	
    return result;
}

#endif


void mkv_parser_get_meta(mkv_parser* pParser, MKV_META_T eMetaType, void* pBuffer, kal_uint32 u4Len, kal_uint32* pu4Size)
{
#ifdef __MKV_PARSER_META__	

    if(MKV_META_THUMBTYPE == eMetaType)
    {
        kal_mem_cpy(pBuffer, &pParser->u4Meta[eMetaType][0], sizeof(kal_uint32));
	}
    else
    {
    	kal_uint32 u4ReadSize;
        kal_uint8* pu1Temp = NULL;
    	
        if(MKV_META_THUMB != eMetaType)		
        {
            u4ReadSize = (pParser->u4Meta[eMetaType][1] <= 2 * u4Len)?pParser->u4Meta[eMetaType][1]: 2 * u4Len;
            pu1Temp = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, u4ReadSize, KAL_FALSE);
        }
        else
        {
            u4ReadSize = (pParser->u4Meta[eMetaType][1] <= u4Len)?pParser->u4Meta[eMetaType][1]: 0;        
            pu1Temp = pBuffer;
        }
    	
        if(NULL != pParser->u4Meta[eMetaType][0] && u4ReadSize > 0 && NULL != pu1Temp)
        {
            if(pParser->fpSeek(pParser->pfilehdr, pParser->u4Meta[eMetaType][0], MKV_SEEK_START) == KAL_TRUE)
            {
                pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pu1Temp, u4ReadSize);		
            }        
        }

        if(MKV_META_THUMB != eMetaType && u4ReadSize > 0 && NULL != pBuffer)
        {
            ProviderUtilityUtf8toUcs2(pBuffer, 2*u4Len, pu1Temp, u4ReadSize);
        }

        if(MKV_META_THUMB != eMetaType && NULL != pu1Temp)
        {
            pParser->fpMfree(pParser->pUserMem, (void**)&pu1Temp);
        }
		
        if(NULL != pu4Size)
        {
            *pu4Size = u4ReadSize;
        }
    }
#endif	
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
#endif

static kal_uint32 _mkv_parser_find_next_level1ID (mkv_parser* pParser, void* pReadhdr, kal_uint32 u4ID)
{
    kal_uint32 pResult = 0;
#ifndef __MKV_SLIM__		
    if(pParser && pParser->pfilehdr && pParser->fpRead && pParser->fpSeek && pParser->fpMalloc && pParser->fpMfree)
    {
#endif    
        kal_uint8 *pbuf = NULL;
        kal_uint32 u4IDsize;
        kal_uint32 u4Length;
        kal_uint32 u4ElementID;
        kal_uint32 u4Offset = 0;
        kal_uint32 u4Start = pParser->fpGetcurpos(pReadhdr);
        kal_uint32 u4MaxReadCount = 1024; 		

        pbuf = (kal_uint8 *)pParser->fpMalloc(pParser->pUserMem, 12, KAL_TRUE);  //ID, LENGTH(vint) 4+8

        while(u4Offset + u4Start < pParser->u4SegmentLength)
        {
            kal_uint32 size = 1;
            kal_mem_set(pbuf, 0, 12);
            if(pParser->fpRead(pParser->pUserRead, pReadhdr, pbuf, 5) != 5)
            {
                break;
            }

            u4IDsize = _mkv_parser_get_vint_size(pbuf);

            u4ElementID = _mkv_read_byte(pbuf, u4IDsize);

//----
            if(MKV_CLASS_D_ELEMENTS_SIZE != u4IDsize && MKV_VOID != u4ElementID)
            {
                kal_uint32 index = 0;
                while(index < 5 && u4MaxReadCount > 0)
                {
                    u4IDsize = _mkv_parser_get_vint_size(pbuf + index);                
                    if(MKV_CLASS_D_ELEMENTS_SIZE != u4IDsize)
                    {
                        u4Offset++;
                        index++; 
                        u4MaxReadCount--;						
                    }
                    else
                    {
                        if(pParser->fpSeek(pReadhdr, u4Start + u4Offset, MKV_SEEK_START) != KAL_TRUE)
                        {
                            pParser->fpMfree(pParser->pUserMem, (void**)&pbuf);                    
                            return NULL;
                        }   					
                        break;
                    }
                }
                if(u4MaxReadCount == 0)
                {
                    pParser->fpMfree(pParser->pUserMem, (void**)&pbuf);                    
                    return NULL;                    
                }
                else
                {
                    continue;

                }                 
            }		
//----			
            u4Length = 0;

            pResult = u4Start + u4Offset;

            if(u4ElementID == u4ID)
            {
                break;
            }
            else
            {
                pResult = 0; 
            }

            switch(u4ElementID)
            {
                case MKV_SEGMENTINFO_ID:
                case MKV_TRACKS_ID:
                case MKV_SEEKHEAD_ID:
                case MKV_CLUSTER_ID:
                case MKV_CUES_ID:
                case MKV_TAGS_ID:
                case MKV_CHAPTERS_ID:					
                case MKV_ATTACHMENTS_ID:

                    u4Length = _mkv_read_vint(pbuf + u4IDsize , pParser, pReadhdr, &size);
                    u4Offset += (u4IDsize+size);
                    break;
#ifdef __MKV_PARSER_ASSERTUNKNOW__					
                case MKV_VOID:
#else
                default:
#endif
                    if(pParser->fpSeek(pReadhdr, u4Start + u4Offset, MKV_SEEK_START) != KAL_TRUE)
                    {
                        pParser->fpMfree(pParser->pUserMem, (void**)&pbuf);                    
                        return NULL;
                    }
                    kal_mem_set(pbuf, 0, 12);
                    pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pbuf, 2);
                    u4Length = _mkv_read_vint(pbuf + u4IDsize , pParser, pReadhdr, &size);
                    u4Offset += (u4IDsize+size);
                    break;
#ifdef __MKV_PARSER_ASSERTUNKNOW__
                default:
                    ASSERT(0);
                    break;
#endif					
            }
            if(pParser->fpSeek(pReadhdr, u4Length, MKV_SEEK_CUR) != KAL_TRUE)
            {
                pParser->fpMfree(pParser->pUserMem, (void**)&pbuf);            
                return NULL;
            }

            u4Offset += u4Length;

        }
        pParser->fpMfree(pParser->pUserMem, (void**)&pbuf);

#ifndef __MKV_SLIM__	
    }
#endif	
    if(pResult != 0)
    {
        pParser->fpSeek(pReadhdr, pResult, MKV_SEEK_START);
    }
    else
    {
        pParser->fpSeek(pReadhdr, pParser->u4SegmentDataBase, MKV_SEEK_START);
    }
    return pResult;
}


/*****************************************************************************
 * Interface API
 ****************************************************************************/

mkv_parser* mkv_parser_create(void*              pUserError,
                              mkv_error_func_ptr  fpError,
                              void*              pUserMem,
                              mkv_malloc_func_ptr fpMalloc,
                              mkv_free_func_ptr   fpFree)
{
    mkv_parser* pmkv_parser;
    pmkv_parser = (mkv_parser*) fpMalloc(pUserMem, sizeof(mkv_parser), KAL_TRUE);
    pmkv_parser->fpMalloc = fpMalloc;
    pmkv_parser->fpMfree = fpFree;
    pmkv_parser->pUserMem = pUserMem;

    return pmkv_parser;
}

void mkv_parser_close(mkv_parser* pParser)
{
    kal_uint32 index;
    mkv_parser_track* pTrack = pParser->pTrackList;
    const void* pUserMem = pParser->pUserMem;
#ifdef __MKV_INDEX_TABLE__
    if(pParser->pIndexTable)
    {
        pParser->fpMfree(pUserMem, (void**)&pParser->pIndexTable);	
    }
#endif
#ifdef __MKV_CLUSTER_TABLE__
    if(pParser->pClusterTable)
    {
        pParser->fpMfree(pUserMem, (void**)&pParser->pClusterTable);	
    }
#endif

    for(index = 0; index < pParser->u4TrackCount; index++)
    {
        mkv_parser_track* pNext;
        pNext = (mkv_parser_track*)pTrack->next;
        if(pTrack->VideoInfo)
        {
            pParser->fpMfree(pUserMem, (void**)&pTrack->VideoInfo);	        
        }		
        if(pTrack->AudioInfo)
        {
            pParser->fpMfree(pUserMem, (void**)&pTrack->AudioInfo);	        
        }		
#ifdef __VE_SUBTITLE_SUPPORT__		
        if(pTrack->pu1Language)
        {
            pParser->fpMfree(pUserMem, (void**)&pTrack->pu1Language);	        
        }
#endif		
#ifndef __MKV_SLIM__		
        if(pTrack->pu1Name)
        {
            pParser->fpMfree(pUserMem, (void**)&pTrack->pu1Name);	        
        }		
#endif		
        if(pTrack->pu1CodecPrivate)
        {
            pParser->fpMfree(pUserMem, (void**)&pTrack->pu1CodecPrivate);	        
        }		
        if(pTrack->pu1ContentCompSettings)
        {
            pParser->fpMfree(pUserMem, (void**)&pTrack->pu1ContentCompSettings);	        
        }				
        if(pTrack)
        {
	    pParser->fpMfree(pUserMem, (void**)&pTrack);	
        }
	pTrack = pNext;
    }
#ifndef __MKV_SLIM__
    if(pParser->pu1Filename)
    {
        pParser->fpMfree(pUserMem, (void**)&pParser->pu1Filename);
    }
    if(pParser->pu1Title)
    {
        pParser->fpMfree(pUserMem, (void**)&pParser->pu1Title);
    }
#endif		

    pParser->fpMfree(pUserMem, (void**)&pParser);
}

kal_bool mkv_parser_set_io(mkv_parser*        pParser,
                           void* 	          pUserRead,
                           void*              pfilehdr,
                           mkv_read_func_ptr  fpRead,
                           mkv_seek_func_ptr  fpSeek,
                           mkv_get_curpos_func_prt fpGetcurpos)
{
    kal_bool retVal = KAL_FALSE;

    if (pParser && fpRead && fpSeek && fpGetcurpos)
    {
        /* Assign the default io functions */
        pParser->fpRead    = fpRead;
        pParser->fpSeek    = fpSeek;
        pParser->fpGetcurpos = fpGetcurpos;
        pParser->pfilehdr = pfilehdr;
        pParser->pUserRead = pUserRead;
        /* Clear the return value */
        retVal = KAL_TRUE;
    }
    return retVal;
}

kal_bool mkv_parser_set_deliver(mkv_parser*        pParser,
	                       void*              pUserDeliver,
                           mkv_deliver_func_ptr fpDeliver)
{
    kal_bool retVal = KAL_FALSE;

    if (pParser)
    {
        /* Assign the default io functions */
        pParser->fpDeliver    = fpDeliver;
		pParser->pUserDeliver = pUserDeliver;

        /* Clear the return value */
        retVal = KAL_TRUE;
    }
    return retVal;
}


kal_bool mkv_parser_init(mkv_parser* pParser, kal_bool fgCheckIndextable, kal_uint32 u4Filesize)
{
    kal_bool retVal = KAL_FALSE;
    kal_uint8 *pBuf = NULL;
    void* pUserMem = pParser->pUserMem;
	
    if(_mkv_parser_ebml_header(pParser, u4Filesize) != KAL_TRUE)
    {
        return KAL_FALSE;
    }

    pBuf = (kal_uint8 *)pParser->fpMalloc(pUserMem, 5 + 8, KAL_TRUE);

    if(_mkv_parser_find_next_level1ID(pParser, pParser->pfilehdr, MKV_SEEKHEAD_ID) != 0)
    {
        pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 5);

        if(_mkv_parser_read_seekhead(pParser, pBuf) != KAL_TRUE)
        {
            return KAL_FALSE;
        }
        if(fgCheckIndextable && pParser->u4SeekheadBase != NULL && pParser->u4ClusterBase == NULL)
        // fgCheckIndextable = fasle is for speed case			
        {
            pParser->fpSeek(pParser->pfilehdr, pParser->u4SeekheadBase, MKV_SEEK_START);
            kal_mem_set(pBuf, 0, 13); 
            if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 5) == 5)
            {
                _mkv_parser_read_seekhead(pParser, pBuf);
            }
        }    
    }

    if(pParser->u4TracksBase == NULL)
    {
        pParser->fpSeek(pParser->pfilehdr, pParser->u4SegmentDataBase, MKV_SEEK_START);    
        if(_mkv_parser_find_next_level1ID(pParser, pParser->pfilehdr, MKV_TRACKS_ID) != 0)
        {
            pParser->u4TracksBase = pParser->fpGetcurpos(pParser->pfilehdr);
        }
    }
	
    if(pParser->u4TracksBase != NULL)
    {
        if(pParser->fpSeek(pParser->pfilehdr, pParser->u4TracksBase, MKV_SEEK_START) != KAL_TRUE)
        {
            return KAL_FALSE;
        }
        else
        {
            kal_mem_set(pBuf, 0, 13);
            if(pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 5) != 5)
            {
                return KAL_FALSE;          
            }
            if(_mkv_parser_read_tracks(pParser, pBuf) != KAL_TRUE)
            {
                return KAL_FALSE;
            }
        }
    }
    else
    {
        return KAL_FALSE;
    }

    if(pParser->u4SegmentInfoBase == NULL)
    {
        pParser->fpSeek(pParser->pfilehdr, pParser->u4SegmentDataBase, MKV_SEEK_START);    
        if(_mkv_parser_find_next_level1ID(pParser, pParser->pfilehdr, MKV_SEGMENTINFO_ID) != 0)
        {
            pParser->u4SegmentInfoBase = pParser->fpGetcurpos(pParser->pfilehdr);
        }
		else
        {
            pParser->u4TimecodeScale = MKV_DEFAULT_TIMECODESCALE;
        }
    }
	
    if(pParser->u4SegmentInfoBase!= NULL)
    {
        if(pParser->fpSeek(pParser->pfilehdr, pParser->u4SegmentInfoBase, MKV_SEEK_START) != KAL_TRUE)
        {
            return KAL_FALSE;
        }
        else	
        {
            kal_mem_set(pBuf, 0, 13);        
            pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 5);
            if(_mkv_parser_read_segment_info(pParser, pBuf) != KAL_TRUE)
            {
                return KAL_FALSE;
            }            
        }
    }

    if(pParser->fpSeek(pParser->pfilehdr, pParser->u4SegmentDataBase, MKV_SEEK_START) != KAL_TRUE)
    {
        return KAL_FALSE;
    }

    if(pParser->u4ClusterBase == NULL)
    {
        pParser->fpSeek(pParser->pfilehdr, pParser->u4SegmentDataBase, MKV_SEEK_START);    
        pParser->u4ClusterBase = _mkv_parser_find_next_level1ID(pParser, pParser->pfilehdr, MKV_CLUSTER_ID);
    }

#ifdef __MKV_INDEX_TABLE__
    pParser->pIndexTable = pParser->fpMalloc(pUserMem, sizeof(MKV_PROVIDER_INDEX_TABLE), KAL_TRUE);
#endif
#ifdef __MKV_CLUSTER_TABLE__
    pParser->pClusterTable = (MKV_PARSER_CLUSTERELEMENT_TABLE *)pParser->fpMalloc(pUserMem, sizeof(MKV_PARSER_CLUSTERELEMENT_TABLE), KAL_TRUE);
#endif
#ifdef __MKV_PARSER_DEBUG__	 
//	u4mkvparserbingo = 0;
#endif

    if(fgCheckIndextable && pParser->u4CuesBase)    // Check cue count
    {
        kal_uint32 u4CuesLen = 0;
        pParser->fpSeek(pParser->pfilehdr, pParser->u4CuesBase, MKV_SEEK_START);		
        if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 5) == 5)
        {
#ifndef __MKV_SLIM__        
            if(_mkv_parser_get_vint_size(pBuf) == 4)
            {
#endif            
                if(_mkv_read_byte(pBuf, 4) == MKV_CUES_ID)
                {
                    u4CuesLen = _mkv_read_vint(pBuf + 4 , pParser, pParser->pfilehdr, NULL);                    
                }                
#ifndef __MKV_SLIM__				
            }
#endif			
        }		
        if(u4CuesLen == 0)
        {
            pParser->u4CuesBase = NULL;
        }		
    }

#ifdef __MKV_PARSER_META__
    if(pParser->u4TagsBase)
    {
        kal_mem_set(pBuf, 0, 13);
        pParser->fpSeek(pParser->pfilehdr, pParser->u4TagsBase, MKV_SEEK_START);		
        _mkv_parser_read_tags(pParser, pBuf);
    }
    if(pParser->u4AttachmentsBase)
    {
        kal_mem_set(pBuf, 0, 13);
        pParser->fpSeek(pParser->pfilehdr, pParser->u4AttachmentsBase, MKV_SEEK_START);		
        _mkv_parser_read_atachments(pParser, pBuf);
    }	
#endif	

    if(pParser->u4ClusterBase)
    {
        retVal= KAL_TRUE;
    }

    pParser->fpMfree(pUserMem, (void**)&pBuf);
    return retVal;
}

kal_bool mkv_parser_select_track(mkv_parser* pParser, MKV_TRACKTYPE_T eType, kal_uint32 u4TrackNumber, kal_bool fgSelect)
{
    kal_bool result = KAL_TRUE;

    switch(eType)
    {
        case MKV_TRACKTYPE_VIDEO:
            if(fgSelect)
            {
                pParser->u1VideoTrackIndex = u4TrackNumber;				
            }
            else
            {
                pParser->u1VideoTrackIndex = 0;				          
            }
            break;
#if defined(__MKV_INDEX_TABLE__) || defined(__MKV_CLUSTER_TABLE__)				
        case MKV_TRACKTYPE_AUDIO:
            if(fgSelect)
            {
                pParser->u1AudioTrackIndex = u4TrackNumber;				
            }
            else
            {
                pParser->u1AudioTrackIndex = 0;				          
            }
            break;
#ifdef __VE_SUBTITLE_SUPPORT__				
        case MKV_TRACKTYPE_SUBTITLE:
            if(fgSelect)
            {
                pParser->u1SubtitleTrackIndex = u4TrackNumber;				
            }
            else
            {
                pParser->u1SubtitleTrackIndex = 0;				          
            }
            break;			
#endif			
#endif //__MKV_INDEX_TABLE__ || __MKV_CLUSTER_TABLE__ 		
        default:
            break;
    }

    return result;
}


kal_bool mkv_parser_seek(mkv_parser* pParser, void* pTrackhdr, kal_uint32 time, kal_uint32* pu4keyframetime, mkv_parser_cluster* pcluster, kal_bool fgReset)
{
    kal_bool result = KAL_FALSE;
    kal_uint64 u4TargetPosition = pParser->u4ClusterBase;

    *pu4keyframetime = 0;

#ifdef __MKV_CLUSTER_TABLE__
    if(pcluster) // pcluster = NULL for mkv_parser_get_keyframe_time only, get key frame time don't reset cluster cache
    {
        kal_uint32 index;
        kal_uint32 u4MinTimecode = 0xFFFFFFFF, u4MaxTimecode = 0;
				
        for(index = 0; index < MKV_PARSER_CLUSTER_CACHE_COUNT; index++)
        {
            MKV_PARSER_CLUSTER_INOF* rIndexCacheCluster = &(pParser->rCacheCluster[index]);
            if(rIndexCacheCluster->u4ClusterBase)
            {
                if(rIndexCacheCluster->u4Timecode < u4MinTimecode)
                {
                    u4MinTimecode = rIndexCacheCluster->u4Timecode;
                }
                if(rIndexCacheCluster->u4MaxTimestamp > u4MaxTimecode)
                {
                    u4MaxTimecode = rIndexCacheCluster->u4MaxTimestamp;
                }				
            }
        }
        if(u4MinTimecode == 0xFFFFFFFF)
        {
            u4MinTimecode = 0;
        }
		
        if(0 == time || time < u4MinTimecode || time> u4MaxTimecode || fgReset)
        {
            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTER_RESET, time, u4MinTimecode, u4MaxTimecode, pParser->pClusterTable->u4Used);	  
        
            kal_mem_set(pParser->pClusterTable, 0, sizeof(MKV_PARSER_CLUSTERELEMENT_TABLE));
            kal_mem_set(pParser->rCacheCluster, 0, sizeof(MKV_PARSER_CLUSTER_INOF) * MKV_PARSER_CLUSTER_CACHE_COUNT);
        }
    }
#endif

    if(pcluster)
    {
        kal_mem_set(pcluster, 0, sizeof(mkv_parser_cluster));								        
    }

    if(0 == time)
    {
        if(u4TargetPosition)
        {
            pParser->fpSeek(pTrackhdr, u4TargetPosition , MKV_SEEK_START);	  //seek to MKV_CLUSTER_ID position.	
            return KAL_TRUE;
        }
        else
        {
            return result;
        }        
    }
	
    /* 1. from index table */
#ifdef __MKV_INDEX_TABLE__ 
    if(NULL == pParser->u4CuesBase || (pParser->pIndexTable->u4MaxTime >= time && pParser->pIndexTable->u4CompressedTime <= time))
#else
    if(NULL == pParser->u4CuesBase)
#endif
    {
#ifdef __MKV_INDEX_TABLE__    
        MKV_PARSER_START_LOGGING("MPI");

        /* max time in index table is larger than seek time*/
        if(pParser->pIndexTable->u4Used > 0)
        {
            /* binary search in index table */
            kal_uint32 start = 0;
            kal_uint32 end = pParser->pIndexTable->u4Used;
    
            while(start + 1 < end)
            {
                kal_uint32 temp = (start + end) >> 1;
                if(pParser->pIndexTable->table[temp].u4Time > time)
                {
                    end = temp;
                }
                else
                {
                    start = temp;
                }            
            }
            u4TargetPosition = pParser->pIndexTable->table[start].u4ClusterPosition;
            *pu4keyframetime = pParser->pIndexTable->table[start].u4Time;	
            if(*pu4keyframetime > time)
            {
                *pu4keyframetime = 0;
                u4TargetPosition = pParser->u4ClusterBase;
            }
            else 
            {
                if(pcluster && pParser->pIndexTable->table[start].u4ClusterOffset)
                {
                    kal_mem_set(pcluster, 0, sizeof(mkv_parser_cluster));
                    pcluster->u4Offset = pParser->pIndexTable->table[start].u4ClusterOffset;
                    pcluster->u4ClusterBase = u4TargetPosition;
                    pcluster->u4Length = 0xfffffff0;
                }
            }
            result = KAL_TRUE;
        }
        else
        {

            kal_uint32 index;
            for(index = 0; index < 2 ; index++)
            {
                MKV_PARSER_CLUSTER_TABLE* rIndexCluster = &(pParser->rClusterCache[index]);
                if(time > rIndexCluster->u4Timecode && rIndexCluster->u4Start)
                {
                    u4TargetPosition = rIndexCluster->u4Start;
                    result = KAL_TRUE;
                }
            }
            if(KAL_FALSE == result)
            {
                 u4TargetPosition = pParser->u4ClusterBase;
                 result = KAL_TRUE;
            }
        }
        MKV_PARSER_STOP_LOGGING("MPI");
#else
    /* No cue and no define __MKV_INDEX_TABLE__ do nothing, return KAL_FALSE */
#endif
    }
    else	
    /* 2. from cue*/
    {
        kal_uint8 *pBuf = NULL;
        mkv_parser_cuepoint *pCuePoint;
        void* pUserMem = pParser->pUserMem;
	
        MKV_PARSER_START_LOGGING("MPC");
        pParser->fpSeek(pParser->pfilehdr, pParser->u4CuesBase, MKV_SEEK_START);		
        pBuf = (kal_uint8 *)pParser->fpMalloc(pUserMem, 12, KAL_TRUE);  //Cues ID (4) + max EBML len (8)
        if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 5) == 5)
        {
#ifndef __MKV_SLIM__        
            if(_mkv_parser_get_vint_size(pBuf) == 4)
            {
#endif            
                if(_mkv_read_byte(pBuf, 4) == MKV_CUES_ID)
                {
                     kal_uint32 u4Offset = 0;
                     kal_uint32 u4Size = 0;
                     kal_uint32 u4CuesLen;
                     kal_uint8 *pCuePointBuf = NULL; 					 

                     pCuePoint = (mkv_parser_cuepoint *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_cuepoint), KAL_TRUE);

                     u4Offset +=4;
                     u4CuesLen = _mkv_read_vint(pBuf + 4 , pParser, pParser->pfilehdr, &u4Size);
                     u4Offset += u4Size;

                     /* read CuePoint */
                     while(u4Offset < u4CuesLen && KAL_FALSE == result)
                     {
                         kal_uint32 u4CuePointLen;
                         kal_uint32 u4Offset1 = 0;
                         kal_uint32 u4CueTime = 0xFFFFFFFF;	
                         kal_uint64 u4CueClusterPosition = NULL;						 
                         kal_uint32 u4CueTrack = 0;							 
                         kal_uint32 u4CueBlockNumber = 1;  // DEFAULT VALUE = 1 (SHOULD NOT = 0)	 					 
						 
                         kal_mem_set(pBuf, 0, 12);
                         if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 2) != 2)
                         {
                             break;
                         }

                         if(_mkv_read_byte(pBuf, 1) == MKV_CRC32ID)
                         {
                             pParser->fpSeek(pParser->pfilehdr, 4, MKV_SEEK_CUR); // seek after CRC32
                             if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pBuf, 2) != 2)
                             {
                                 break;
                             }
                             u4Offset += 6;
                         }
						 
                         if(_mkv_read_byte(pBuf, 1) != MKV_CUE_POINT)
                         {
                             break;
                         }
                         u4Offset +=1;
                         u4CuePointLen = _mkv_read_vint(pBuf + 1 , pParser, pParser->pfilehdr, &u4Size);
                         u4Offset +=u4Size;
                         pCuePointBuf = (kal_uint8 *)pParser->fpMalloc(pUserMem, u4CuePointLen, KAL_TRUE);
                         if (pParser->fpRead(pParser->pUserRead, pParser->pfilehdr, pCuePointBuf, u4CuePointLen) != u4CuePointLen)
                         {
                             break;
                         }
                         u4Offset +=u4CuePointLen;

                         while(u4Offset1 < u4CuePointLen && KAL_FALSE == result)
                         {						     							 
                             kal_uint32 u4Offset2 = 0;
							 
                             mkv_ebml_element rEBML;
							 kal_uint8 *pCuePointPosBuf = NULL; 					 
                             _mkv_read_EBML(pCuePointBuf + u4Offset1, NULL, NULL, NULL, &rEBML);
							 pCuePointPosBuf = rEBML.pu1Element;
                             u4Offset1 += rEBML.u4EbmlTotalLength;
							 
                             switch(rEBML.u4EbmlID)
                             {
                                 case MKV_CUE_TIME:
                                     u4CueTime = _mkv_read_byte(rEBML.pu1Element, rEBML.u4ElementSize);	
                                     u4CueTime = _mkv_parser_getscaletime(pParser, u4CueTime);
                                     break;
                                 case MKV_CUE_TRACK_POSITION:
                                 {
                                     kal_uint32 u4CueTrackPositionLen = rEBML.u4ElementSize;

                                     while(u4Offset2 < u4CueTrackPositionLen)
                                     {
                                         mkv_ebml_element rCueEBML;
                                         _mkv_read_EBML(pCuePointPosBuf + u4Offset2, NULL, NULL, NULL, &rCueEBML);
                                         u4Offset2 += rCueEBML.u4EbmlTotalLength;										 
    											
                                         switch(rCueEBML.u4EbmlID)
                                         {
                                             case MKV_CUE_TRACK:
                                                 u4CueTrack = _mkv_read_byte(rCueEBML.pu1Element, rCueEBML.u4ElementSize);
                                                 break;
                                             case MKV_CUE_CLUSTER_POSITION:
                                                 u4CueClusterPosition = _mkv_read_byte(rCueEBML.pu1Element, rCueEBML.u4ElementSize);
                                                 break;
                                             case MKV_CUE_CLUSTER_BLOCK_NUMBER:
                                                 u4CueBlockNumber = _mkv_read_byte(rCueEBML.pu1Element, rCueEBML.u4ElementSize);
                                                 break;

                                             default:
                                                 break;
                                         }																					    
                                     }
                                 }
                                     break;
                                 default:
#ifdef __MKV_PARSER_ASSERTUNKNOW__								 	
                                     ASSERT(0);
#endif
                                     break;
                             }
                         }

                             if(u4CueClusterPosition == pCuePoint->u4CueClusterPosition && pParser->u1VideoTrackIndex == u4CueTrack && u4CueBlockNumber <= 1)
                             {
                                 u4CueTime = pCuePoint->u4CueTime;
                             }
							 	
#ifdef __MKV_INDEX_TABLE__
                             if(u4CueClusterPosition && u4CueTime != 0xFFFFFFFF && (0 == pParser->u1VideoTrackIndex || pParser->u1VideoTrackIndex == u4CueTrack))
                             {
                                 mkv_parser_cluster rCluster;
                                 rCluster.u4ClusterStart = pParser->u4SegmentDataBase + u4CueClusterPosition;
                                 rCluster.u4Offset = 0;
                                 _mkv_parser_indextable_add(pParser, u4CueTime, &rCluster, 0, 0);
                             }							 
#endif

                             if(u4CueTime != 0xFFFFFFFF && (0 == pParser->u1VideoTrackIndex || pParser->u1VideoTrackIndex == u4CueTrack))
                             {
                                 if(u4CueTime > time && u4CueClusterPosition)
                                 {
                                     result = KAL_TRUE;
                                     break;
                                 }
                                 if(u4CueClusterPosition)
                                 {
                                     pCuePoint->u4CueTime = u4CueTime;
                                     pCuePoint->u4CueClusterPosition = u4CueClusterPosition;
                                 }
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
#endif						 
                         pParser->fpMfree(pUserMem, (void**)&pCuePointBuf); 
                    }
                    if(pCuePointBuf)
                    {
                        pParser->fpMfree(pUserMem, (void**)&pCuePointBuf); 
                    }
                    if(KAL_FALSE == result)   // for seek to file end
                    {
                        if(pCuePoint->u4CueClusterPosition)
                        {
                            result = KAL_TRUE;
                        }
                    }
                    if(result)
                    {
                        if(pCuePoint->u4CueClusterPosition)
                        {
                            u4TargetPosition = pParser->u4SegmentDataBase + pCuePoint->u4CueClusterPosition;
                            *pu4keyframetime = pCuePoint->u4CueTime;
                        }
			else
                        {
                            u4TargetPosition = pParser->u4ClusterBase;
                            *pu4keyframetime = 0;
                        }							
                    }
                    pParser->fpMfree(pUserMem, (void**)&pCuePoint);                 
                }
#ifndef __MKV_SLIM__				
            }
#endif			
        }
        pParser->fpMfree(pUserMem, (void**)&pBuf); 				
        MKV_PARSER_STOP_LOGGING("MPC");
    }

    /* jump to seek entry  */
    if(u4TargetPosition)
    {
        pParser->fpSeek(pTrackhdr, u4TargetPosition , MKV_SEEK_START);    //seek to MKV_CLUSTER_ID position.    
    }
    return result;
}

kal_bool mkv_parser_get_keyframe_time(mkv_parser* pParser, kal_uint32 u4TrackNumber, kal_uint32 u4Targettime, kal_uint32* p4Keyframetime, MKV_TRACKTYPE_T eTracktype, kal_bool* pfgAbort)
{
    kal_bool result = KAL_FALSE;
    kal_uint32 u4Time = 0;	

    *p4Keyframetime = 0;

    if(eTracktype == MKV_TRACKTYPE_AUDIO && u4Targettime >= pParser->u4Duration)
    {
        *p4Keyframetime = pParser->u4Duration; 
        return KAL_TRUE;    
    }

#ifdef  __MKV_KEYFRAME_TIME_CACHE__
    if(eTracktype == MKV_TRACKTYPE_AUDIO)
    {
        if(u4Targettime <= pParser->u4AudioQueryTime && u4Targettime >= pParser->u4AudioKeyframeTime)
        {
            *p4Keyframetime = pParser->u4AudioKeyframeTime; 
#ifdef __MKV_PARSER_DEBUG__			
            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_KEYFRAMETIME_BINGO, u4Targettime, pParser->u4AudioQueryTime, pParser->u4AudioKeyframeTime, 0);    		
#endif
            return KAL_TRUE;
        }	 
    }
    else if(eTracktype == MKV_TRACKTYPE_VIDEO)
    {
        if(u4Targettime <= pParser->u4VideoQueryTime && u4Targettime >= pParser->u4VideoKeyframeTime)
        {
            *p4Keyframetime = pParser->u4VideoKeyframeTime; 
#ifdef __MKV_PARSER_DEBUG__						
            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_KEYFRAMETIME_BINGO, u4Targettime, pParser->u4VideoQueryTime, pParser->u4VideoKeyframeTime, 1);    		
#endif
            return KAL_TRUE;
        }	 
    }
#endif	


    result = mkv_parser_seek(pParser, pParser->pfilehdr, u4Targettime, p4Keyframetime, NULL, KAL_FALSE);    // file hdr will be move to MKV_CLUSTER_ID position

    u4Time = *p4Keyframetime;

    MKV_PARSER_START_LOGGING("MPG");	
    if(result)
    {
        mkv_parser_cluster* pCluster;
        mkv_parser_block* pBlock;
        mkv_parser_cluster* pTemp;	

        if(eTracktype == MKV_TRACKTYPE_AUDIO || pParser->u4CuesBase == NULL)
        {
            void* const pUserMem = pParser->pUserMem;
            
            if(eTracktype == MKV_TRACKTYPE_AUDIO)
            {
                result = KAL_FALSE;            
            }
			
            pCluster = (mkv_parser_cluster *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_cluster), KAL_TRUE);	
            pBlock = (mkv_parser_block *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_block), KAL_TRUE);
            pTemp = (mkv_parser_cluster *)pParser->fpMalloc(pUserMem, sizeof(mkv_parser_cluster), KAL_TRUE);					

            while(1)
            {
                if(KAL_TRUE == *pfgAbort)
               	{
                    break;
                }

                kal_mem_set(pTemp, 0, sizeof(mkv_parser_cluster));					
    			
                if(_mkv_parser_find_next_level1ID(pParser, pParser->pfilehdr, MKV_CLUSTER_ID) == 0)
                {
                    break;
                }			
                if(_mkv_parser_read_cluster_info(pParser, pParser->pfilehdr, pTemp)!= MKV_PARSER_ERROR_NONE)
                {
                    pParser->fpMfree(pUserMem, (void**)&pCluster);
                    pParser->fpMfree(pUserMem, (void**)&pBlock);
                    pParser->fpMfree(pUserMem, (void**)&pTemp);
                    MKV_PARSER_STOP_LOGGING("MPG");    								
                    return KAL_FALSE;
                }

                u4Time = pTemp->u4TimeCode;
                u4Time = _mkv_parser_getscaletime(pParser, u4Time);

                if(u4Time > u4Targettime)
                {
                    break;
                }
                kal_mem_cpy(pCluster, pTemp, sizeof(mkv_parser_cluster));
    
                if(pParser->fpSeek(pParser->pfilehdr, pCluster->u4Length - pCluster->u4Offset, MKV_SEEK_CUR) != KAL_TRUE)
                {
                    break;
                }            			
    
            };
			
            pParser->fpMfree(pUserMem, (void**)&pTemp);	
            pParser->fpSeek(pParser->pfilehdr, pCluster->u4ClusterBase + pCluster->u4Offset, MKV_SEEK_START);
    		
            while(pCluster->u4Length != 0)
            {
                if(KAL_TRUE == *pfgAbort)
               	{
                    break;
                }            
        	    //kal_mem_set(pBlock, 0, sizeof(mkv_parser_block));  //don't reset, block may be other track data.
        	    if(MKV_PARSER_ERROR_NONE != _mkv_parser_read_cluster_element(pParser, u4TrackNumber, pParser->pfilehdr, pCluster, pBlock))
        	    {
        	        break;
        	    }
        	    u4Time = pCluster->u4TimeCode + pBlock->i2Timecode;
                u4Time = _mkv_parser_getscaletime(pParser, u4Time);
        	    if(u4Time <= u4Targettime)    
        	    {        	   
            	    if((eTracktype == MKV_TRACKTYPE_VIDEO && pBlock->fgkeyframe) || eTracktype != MKV_TRACKTYPE_VIDEO)
            	    {
            	        if(pBlock->u4TrackNumber == u4TrackNumber)
            	        {
#ifdef __MKV_INDEX_TABLE__		
                            if (eTracktype == MKV_TRACKTYPE_VIDEO)
                            {
                                _mkv_parser_indextable_add(pParser, u4Time, pCluster, u4TrackNumber, 0);								
                            }
#endif            	        
            	            *p4Keyframetime = u4Time;						 
            	        }
            	    }
        	    }
        	    else
        	    {
        	        result = KAL_TRUE;
        	        break;
        	    }
    			
        	    if(pCluster->u4Offset >= pCluster->u4Length)
        	    {
        	        break;
        	    }
            }
            pParser->fpMfree(pUserMem, (void**)&pBlock);
            pParser->fpMfree(pUserMem, (void**)&pCluster);
        }
    }

    if(eTracktype == MKV_TRACKTYPE_AUDIO && KAL_FALSE == result)
    {
        *p4Keyframetime = u4Time;
        result = KAL_TRUE;
    }

#ifdef  __MKV_KEYFRAME_TIME_CACHE__
    if(eTracktype == MKV_TRACKTYPE_AUDIO)
    {
        pParser->u4AudioQueryTime = u4Targettime;    
        pParser->u4AudioKeyframeTime = *p4Keyframetime;		
    }
    else if(eTracktype == MKV_TRACKTYPE_VIDEO)
    {
        pParser->u4VideoQueryTime = u4Targettime;    
        pParser->u4VideoKeyframeTime = *p4Keyframetime;		
    }
#endif	
    MKV_PARSER_STOP_LOGGING("MPG"); 			

    return result;
}

MKV_PARSER_ERROR_T mkv_parser_demux(mkv_parser* pParser, kal_uint32 u4TrackNumber, void* pReadhdr, mkv_parser_cluster* pCluster)
{
    MKV_PARSER_ERROR_T result = MKV_PARSER_ERROR_NONE;
#ifndef __MKV_INDEX_TABLE__    	
    if(pCluster->u4Length == 0 || pCluster->u4Offset >= pCluster->u4Length)
    {
#else
    if(pCluster->u4Length == 0 || pCluster->u4Offset >= pCluster->u4Length || pCluster->u4Length == 0xfffffff0)
    {
        kal_uint32 offset = 0;
        if(pCluster->u4Length == 0xfffffff0)
        {
            offset = pCluster->u4Offset;
        }
#endif		
        if(_mkv_parser_find_next_level1ID(pParser, pReadhdr, MKV_CLUSTER_ID) != 0)
        {
            result = _mkv_parser_read_cluster_info(pParser, pReadhdr, pCluster);
            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTER_INFO, u4TrackNumber, (kal_uint32)pCluster->u4ClusterBase, pCluster->u4TimeCode, pCluster->u4Length);
 
#ifdef __MKV_INDEX_TABLE__			
            if(offset != 0)
            {
                pCluster->u4Offset = offset;
                pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase+ pCluster->u4Offset , MKV_SEEK_START);   
            }			
#endif			
        }
        else
        {
            result = MKV_PARSER_ERROR_EOF;
        }
    }
    if(MKV_PARSER_ERROR_NONE == result)
    {
#ifdef __MKV_CLUSTER_TABLE__    
        kal_uint32 index;
        kal_bool fgClear = KAL_TRUE;
        kal_uint32 u4ClusterItemCount = pParser->pClusterTable->u4Used;
        kal_uint32 u4ClusterItemRead = pParser->pClusterTable->u4Read;		

        if(NULL == pCluster->u4Length)
        {
            ASSERT(0);
            return MKV_PARSER_ERROR_CORRUPT;        
        }

        for(index = 0; index < u4ClusterItemCount; index++)
        {
            kal_uint32 u4Trackindex = 0;
            kal_uint32 cur = (u4ClusterItemRead + index)% MKV_PARSER_CLUSTER_TABLE_COUNT;      

            MKV_PARSER_CLUSTER_ELEMENT* element = &(pParser->pClusterTable->table[cur]);
            MKV_PARSER_CLUSTER_INOF* cluster = &(pParser->rCacheCluster[element->u2ClusterID]);
            kal_uint64 u4ClusterBase = cluster->u4ClusterBase;
			
#ifdef __MKV_PARSER_DEBUG__			
            if(element->u4ClusterBase != cluster->u4ClusterBase)
            {
                ASSERT(0);
            }
#endif
			
            if(pParser->pClusterTable->u4Used == 0)
            {
#ifdef __MKV_PARSER_DEBUG__            
                if(pParser->pClusterTable->u4Read != pParser->pClusterTable->u4Write)
            {
                    ASSERT(0);
            }
#endif
                break;
            }
            if((u4ClusterBase > pCluster->u4ClusterBase)  // large than current cluster
            || (u4ClusterBase == pCluster->u4ClusterBase && pCluster->u4Offset < cluster->u4MinOffset)  // equal to current cluster and current cluster offset small thatn cache cluster MIN offset
            || (u4ClusterBase == pCluster->u4ClusterBase && pCluster->u4Offset > cluster->u4MaxOffset)) // equal to current cluster and current cluster offset large thatn cache cluster MAX offset
            {
                break;
            }			

//--------			
            if(pParser->u1AudioTrackIndex == u4TrackNumber)
            {
                u4Trackindex = 0;
            }
            else if(pParser->u1VideoTrackIndex == u4TrackNumber)
            {
                u4Trackindex = 1;            
            }
#ifdef __VE_SUBTITLE_SUPPORT__			
            else if(pParser->u1SubtitleTrackIndex == u4TrackNumber)
            {
                u4Trackindex = 2;            
            }			
#endif

            if(u4ClusterBase == pCluster->u4ClusterBase && pCluster->u4Offset < cluster->u4MaxOffset)  // u4MaxOffset < pCluster->u4Offset < u4MinOffset
            {
                if(cluster->u2CacheCount[u4Trackindex] == 0)
                {
                    kal_uint32 u4MaxOffset = cluster->u4MaxOffset;

                    pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase + u4MaxOffset , MKV_SEEK_START);  
                    MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_DEMUX_FLY, u4TrackNumber, (kal_uint32)pCluster->u4TimeCode, pCluster->u4Offset, u4MaxOffset);					 
#ifdef __MKV_PARSER_DEBUG__
                    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPARSER_CLUSTERITEM_FLY, u4MaxOffset);	
#endif					
                    if(u4MaxOffset > pCluster->u4Length)
                    {
                        ASSERT(0);
                    }
                    pCluster->u4Offset = u4MaxOffset;
        
                    break;
                }
            }

//--------			
            if(element->u2TrackID == u4TrackNumber)
            {
                if(u4ClusterBase < pCluster->u4ClusterBase || (u4ClusterBase == pCluster->u4ClusterBase && element->u4Offset < pCluster->u4Offset))
                {
                    element->u2TrackID = 0;									
                    if(fgClear)
                    {				    
			MKV_TRACE8(TRACE_GROUP_2, MKVPARSER_CLUSTERTABLE_REMOVE, u4TrackNumber, element->u2TrackID, (kal_uint32)pCluster->u4ClusterBase,pCluster->u4Length, pCluster->u4Offset, element->u4Offset, pParser->pClusterTable->u4Read, pParser->pClusterTable->u4Used);					 
#ifdef __MKV_PARSER_DEBUG__   						
			video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPARSER_CLUSTERITEM_REMOVE, element->u4Timecode);	
#endif
                        pParser->pClusterTable->u4Used--;
                        pParser->pClusterTable->u4Read++;
                        if(MKV_PARSER_CLUSTER_TABLE_COUNT == pParser->pClusterTable->u4Read)
                        {
                            pParser->pClusterTable->u4Read = 0;
                        }

#ifdef __MKV_PARSER_DEBUG__   						
                        if(cluster->u2CacheCount[u4Trackindex] == 0)
                        {
                            ASSERT(0);
                        }
#endif											
                        cluster->u2CacheCount[u4Trackindex]--;	

#ifdef __MKV_PARSER_DEBUG__   						
                        if(cluster->u2Used == 0)
                        {
                            ASSERT(0);
                        }
#endif						
                        cluster->u2Used--;																									

                        if(0 == cluster->u2Used)
                        {
                            pParser->pClusterTable->u1ClusterInfoUsed--; 
                            cluster->u4ClusterBase = 0;							
                            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTER_REMOVE, u4ClusterBase, (kal_uint32)pCluster->u4ClusterBase, pParser->pClusterTable->u1ClusterInfoWrite, pParser->pClusterTable->u1ClusterInfoUsed);					
                        }
                    }
#ifdef __MKV_PARSER_DEBUG__ 					
                    else
                    {
                        MKV_TRACE8(TRACE_GROUP_2, MKVPARSER_CLUSTERTABLE_REMOVE_WITHOUT_CLEAN, u4TrackNumber, element->u2TrackID, (kal_uint32)pCluster->u4ClusterBase,pCluster->u4Length, pCluster->u4Offset, element->u4Offset, pParser->pClusterTable->u4Read, pParser->pClusterTable->u4Used);					 					
                    }
#endif					
					
                }				
                else
                {		                
                    if(u4ClusterBase == pCluster->u4ClusterBase && element->u4Offset == pCluster->u4Offset)
                    {
                        break;
                    }
					
                    pParser->fpSeek(pReadhdr, pCluster->u4ClusterBase + element->u4Offset , MKV_SEEK_START);  
                    MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_DEMUX_BINGO, u4TrackNumber, (kal_uint32)pCluster->u4TimeCode, pCluster->u4Offset, element->u4Offset);					
 
#ifdef __MKV_PARSER_DEBUG__
//                    u4mkvparserbingo++;

                    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPARSER_CLUSTERITEM_BINGO, element->u4Timecode);	
#endif					
                    if(element->u4Offset > pCluster->u4Length)
                    {
                        ASSERT(0);
                    }
                    pCluster->u4Offset = element->u4Offset;
                    break;
                }
            }
            else 
            {    // for clean hole in table             
                if(element->u2TrackID != 0)
                {              
                    fgClear = KAL_FALSE;
                }
                else    //element->u2TrackID == 0
                {	
                    if(fgClear)
                    {
                        MKV_TRACE8(TRACE_GROUP_2, MKVPARSER_CLUSTERTABLE_REMOVE, u4TrackNumber, element->u2TrackID, (kal_uint32)pCluster->u4ClusterBase,pCluster->u4Length, pCluster->u4Offset, element->u4Offset, pParser->pClusterTable->u4Read, pParser->pClusterTable->u4Used);					 
#ifdef __MKV_PARSER_DEBUG__   					
                        video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPARSER_CLUSTERITEM_REMOVE1, element->u4Timecode);	
#endif
                        pParser->pClusterTable->u4Used--;
                        pParser->pClusterTable->u4Read++;
                        if(MKV_PARSER_CLUSTER_TABLE_COUNT == pParser->pClusterTable->u4Read)
                        {
                            pParser->pClusterTable->u4Read = 0;
                        }           

#if 0 // Can't check this (u2TrackID is miss)						
#ifdef __MKV_PARSER_DEBUG__   						
/* under construction !*/
#endif											
/* under construction !*/
#endif						

#ifdef __MKV_PARSER_DEBUG__   						
                        if(cluster->u2Used == 0)
                        {
                            ASSERT(0);
                        }
#endif						
                        cluster->u2Used--;	

                        if(0 == cluster->u2Used)
                        {
                            pParser->pClusterTable->u1ClusterInfoUsed--; 
                            cluster->u4ClusterBase = 0;
                            MKV_TRACE4(TRACE_GROUP_2, MKVPARSER_CLUSTER_REMOVE, u4ClusterBase, (kal_uint32)pCluster->u4ClusterBase, pParser->pClusterTable->u1ClusterInfoWrite, pParser->pClusterTable->u1ClusterInfoUsed);					 
                        }
                    }
					
                }				
            }
//--------			
        }       
#endif		
        result = _mkv_parser_read_cluster_element(pParser, u4TrackNumber, pReadhdr, pCluster, NULL);
    }

    return result;
}

#endif //__VE_MKV_FILE_FORMAT_SUPPORT__
