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
 *   mkv_provider.c
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "drv_features_video.h"

#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)

#include "kal_public_defs.h"
#include "mkv_provider.h"
#include "fsal.h"
//#include "vcodec_dec_demuxer_if.h"
#include "vcodec_v2_trc.h"
#include "drv_comm.h"
#include "provider_utility.h"

#ifdef __MKV_PROVIDER_DEBUG__
#ifdef __MKV_PROVIDER_UT__
static kal_uint8 audio_buffer[802400];
static kal_uint8 subtitle_buffer[80240];
static kal_uint8 video_buffer[10240000];
#endif
static kal_uint64 audio_buffer_offset = 0;
static kal_uint64 subtitle_buffer_offset = 0;
static kal_uint64 video_buffer_offset = 0;

static kal_uint32 mkv_memalloc[2048000];
static kal_uint32 mkv_memalloc_size[2048000];
static kal_uint32 mkv_memalloc_index;
static kal_uint32 mkv_memalloc_index_after_open;
static kal_uint32 mkv_memalloc_size_after_open;
static kal_uint32 mkv_memalloc_totalsize;
static kal_uint32 mkv_memalloc_maxsize;
static kal_uint32 mkv_memalloc_free_count;
static kal_uint32 mkv_memalloc_assert_size = 999999;
static kal_uint32 mkv_memalloc_alloc = 0;
static kal_uint32 mkv_memalloc_free = 0;
#endif

#ifdef __MKV_MEMORY_CHECK__
static kal_uint32 mkv_memalloc_count;
#endif

#ifdef __MKV_PROVIDER_PROFILE__
static kal_uint32 u4mkvparserprofiletime = 0;
#endif

#ifdef __MKV_PROVIDER_UT__
static kal_uint32 mkvbuffer[80240];
static kal_uint32 buffer_offset = 0;
const kal_wchar* filename = L"E:\\01\\ssa_test.avi";  //L"E:\\test5.mkv";

void initmemory()
{
   if((kal_uint32)(&mkvbuffer) % 32 !=0)
   {
       buffer_offset = 32 - ((kal_uint32)&mkvbuffer % 32);
   }
}

kal_uint8* getmemory(kal_uint32 size)
{
    kal_uint32 addr = (kal_uint32)&mkvbuffer + buffer_offset;
    if(size % 32 != 0)
    { size = ((size / 32)+1)*32;}
    buffer_offset += size;
    return (kal_uint8*)addr;
}
#endif


static MKV_SP_PROVIDER_CONTEXT_T* g_mkv_provider[2];


/*****************************************************************************
 * FUNCTION
 *    _mkv_mem_alloc
 * DESCRIPTION
 *  This function is the mem alloc function for mkv parser.
 * PARAMETERS
 *  param1 : [IN]  kal_uint32 ulSize
 *                 The size which user want to allocate.
 * RETURNS
 *  return allocated memory pointer.
 ****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *    _mkv_mem_alloc
 * DESCRIPTION
 *  This function is the mem alloc function for mkv parser.
 * PARAMETERS
 *  param1 : [IN]  kal_uint32 ulSize
 *                 The size which user want to allocate.
 * RETURNS
 *  return allocated memory pointer.
 ****************************************************************************/
static void* _mkv_mem_alloc(const void* pUserMem, kal_uint32 u4Size, kal_bool fgAssert)
{
    SP_API_T *prSrcAPI = ((MKV_SP_PROVIDER_CONTEXT_T*)pUserMem)->prSourceAPI;
    void *srcHandle = ((MKV_SP_PROVIDER_CONTEXT_T*)pUserMem)->pvSourceHandle;
    void* buf = NULL;
#ifdef __MKV_PROVIDER_UT__
    buf = getmemory(u4Size);
#else

    buf = prSrcAPI->SPFN_MALLOC_CLA(srcHandle, u4Size, KAL_TRUE);
    if(fgAssert && u4Size)
    {
        if(NULL == buf)
        {
            ASSERT(0);
        }
    }
    prSrcAPI->SPFN_MEM_SET(buf, 0, u4Size);

#endif

    //MKV_TRACE4(TRACE_GROUP_4, MKVPROVIDER_MEM_ALLOC, u4Size, (kal_uint32)buf, mkv_memalloc_alloc++, 0);

#ifdef __MKV_PROVIDER_DEBUG__
    if(mkv_memalloc_index < 2048000)
    {
        video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MPEG4HW_RESOURCE_GET, (kal_uint32)buf);
        mkv_memalloc[mkv_memalloc_index] = (kal_uint32)buf;
        mkv_memalloc_size[mkv_memalloc_index] = u4Size;
        mkv_memalloc_index++;
        mkv_memalloc_totalsize += u4Size;
        if(mkv_memalloc_maxsize < mkv_memalloc_totalsize)
        {
            mkv_memalloc_maxsize = mkv_memalloc_totalsize;
        }
        if(mkv_memalloc_index >= 2048000)
        {
            ASSERT(0);
        }
        if(u4Size == mkv_memalloc_assert_size)
        {
            ASSERT(0);
        }
    }
#endif
#ifdef __MKV_MEMORY_CHECK__
    mkv_memalloc_count++;
#endif

    return buf;
}

/*****************************************************************************
 * FUNCTION
 *    _mkv_mem_free
 * DESCRIPTION
 *  This function is the mem free function for RM SDK PARSER.
 * PARAMETERS
 *  param1 : [IN]  void* ptr
 *                 The memory pointer which user want to release.
 * RETURNS
 *  None.
 ****************************************************************************/
static void _mkv_mem_free(const void* pUserMem, void** ptr)
{
    SP_API_T *prSrcAPI = ((MKV_SP_PROVIDER_CONTEXT_T*)pUserMem)->prSourceAPI;
    void *srcHandle = ((MKV_SP_PROVIDER_CONTEXT_T*)pUserMem)->pvSourceHandle;
    kal_uint32 addr = (kal_uint32)*ptr;
#ifdef __MKV_PROVIDER_DEBUG__
    kal_uint32 index;
#endif


#ifndef __MKV_PROVIDER_UT__
    if(NULL == addr)
    {
        ASSERT(0);
    }
    prSrcAPI->SPFN_FREE_CLA(srcHandle, (void*)addr);
#endif
    *ptr = NULL;
    //MKV_TRACE2(TRACE_GROUP_4, MKVPROVIDER_MEM_FREE, addr, mkv_memalloc_free++);

#ifdef __MKV_PROVIDER_DEBUG__
    if(mkv_memalloc_index < 2048000)
    {
        video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MPEG4HW_RESOURCE_FREE, addr);    
        for(index = 0; index < mkv_memalloc_index; index++)
        {
            if(mkv_memalloc[index] == addr)
            {
                mkv_memalloc[index] = 0;
                break;
            }
        }

        ASSERT(mkv_memalloc_size[index]);

        ASSERT(mkv_memalloc_totalsize >= mkv_memalloc_size[index]);

        mkv_memalloc_totalsize -= mkv_memalloc_size[index];

        if(index == mkv_memalloc_index)
            ASSERT(0);

        mkv_memalloc_free_count++;
    }
#endif
#ifdef __MKV_MEMORY_CHECK__
    ASSERT(mkv_memalloc_count > 0);
    mkv_memalloc_count--;
#endif
}

/*****************************************************************************
 * FUNCTION
 *    _mkv_read
 * DESCRIPTION
 *  This function is the file read function for RM SDK PARSER.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 ****************************************************************************/
static kal_uint32 _mkv_read(void* pUserRead, void* file_handle, BYTE* pBuf, kal_uint32 u4BytesToRead)
{
    FSAL_Status res;

    kal_uint32 bytes_read = u4BytesToRead;
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = NULL;

    if(pUserRead)
    {
        kal_uint32 index;    
        pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pUserRead;
        if(pr_mkv_provider->fgTerminate)
        {
	        return 0;
        }
        for(index = 0; index < MKV_TRACK_COUNT; index++)		
        {
            if(file_handle == pr_mkv_provider->paFileHandle[index]->prFileHandle)		
            {
                if(KAL_TRUE == pr_mkv_provider->fgAbort[index])
                {
                    return 0;                
                }
                break;
            }
        }
    }

    if (bytes_read)
    {
        MKV_START_LOGGING("MKF");
        //MKV_TRACE2(TRACE_GROUP_4, MKVPROVIDER_READ_FILE, 0, bytes_read);    
        res = FSAL_Read((STFSAL*)file_handle, pBuf, bytes_read);
        //MKV_TRACE2(TRACE_GROUP_4, MKVPROVIDER_READ_FILE, 1, bytes_read);
        MKV_STOP_LOGGING("MKF");
		
        if (res != FSAL_OK)
        {
            bytes_read = 0;
        }
    }

    return bytes_read;
}

/*****************************************************************************
 * FUNCTION
 *    _mkv_seek
 * DESCRIPTION
 *  This function is the file seek function for RM SDK PARSER.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 * RETURN VALUES                                     [this TAG is an alternative of RETURNS]
 *  ReturnValue1 : description of return value 1.
 *  ReturnValue2 : description of return value 2.
 *
 ****************************************************************************/
static kal_bool _mkv_seek(void* file_handle, kal_uint32 ulOffset, MKV_SEEKFILE_T eOrigin)
{
    FSAL_Status res;
    kal_uint32 file_size;
    kal_uint32 curr_pos;
    kal_uint32 seek_pos = ulOffset;
    kal_bool ret = KAL_FALSE;

    res = FSAL_GetFileSize((STFSAL*)file_handle, &file_size);
    if (res != FSAL_OK)
    {
        //return HXR_READ_ERROR;
        return KAL_FALSE;
    }

    switch (eOrigin)
    {
    case MKV_SEEK_START:
        if (ulOffset > file_size)
        {
            seek_pos = file_size;
            //ret = HXR_CORRUPT_FILE;
        }
        else
        {
            seek_pos = ulOffset;
            //ret = HXR_OK;
            ret = KAL_TRUE;
        }
        break;

    case MKV_SEEK_CUR:
        res = FSAL_GetCurPos((STFSAL*)file_handle, &curr_pos);
        if (res != FSAL_OK)
        {
            //return HXR_READ_ERROR;
            break;
        }

        if ((ulOffset + curr_pos) > file_size)
        {
            seek_pos = file_size;
            //ret = HXR_CORRUPT_FILE;
        }
        else if ((ulOffset + curr_pos) < curr_pos)
        {
            // very large offset, must corrupted.
            seek_pos = curr_pos;
            //ret = HXR_CORRUPT_FILE;
        }
        else
        {
            seek_pos = (ulOffset + curr_pos);
            //ret = HXR_OK;
            ret = KAL_TRUE;
        }

        break;

    case MKV_SEEK_END:
        if(file_size < (file_size - ulOffset)); /* if happen, handle overflow case here!! */
        {
            ASSERT(0);			
        }
        if (file_size < ulOffset)
        {
            seek_pos = 0;
            //ret = HXR_CORRUPT_FILE;
        }
        else
        {
            seek_pos = file_size - ulOffset;
            //ret = HXR_OK;
            ret = KAL_TRUE;
        }

        break;

    default:
#ifdef __MKV_PROVIDER_DEBUG__		
        ASSERT(0);
#endif
        break;
    }

    MKV_START_LOGGING("MKK");
    //MKV_TRACE2(TRACE_GROUP_4, MKVPROVIDER_SEEK_FILE, 0, ulOffset);
    res = FSAL_Seek((STFSAL*)file_handle, seek_pos);
    //MKV_TRACE2(TRACE_GROUP_4, MKVPROVIDER_SEEK_FILE, 1, ulOffset);
    MKV_STOP_LOGGING("MKK");
		
    if (res != FSAL_OK)
    {
        ret = KAL_FALSE;
#ifdef __MKV_PROVIDER_DEBUG__        
        ASSERT(0);
#endif        
    }

    return ret;
}


static kal_uint32 _mkv_get_curpos(void* file_handle)
{
    kal_uint32 curr_pos;
    FSAL_Status res;

    res = FSAL_GetCurPos((STFSAL*)file_handle, &curr_pos);
    if (res != FSAL_OK)
    {
        return 0;
    }
    return curr_pos;
}


#ifdef __VE_SUBTITLE_SUPPORT__

static kal_bool _mkv_getSSA_payload(void *pvHandle, SPIF_PROVIDER_FRAME_INFO_T* pFrameInfo)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    /* Events are stored in the Block in this order: ReadOrder, Layer, Style, Name, MarginL, MarginR, MarginV, Effect, Text */
    /* Events are stored in the Block in this order:               0,       1,       2,       3,          4,           5,           6,        7,     8 */	
    VSD_SSA_INFO_T* pu1Payload;

    const kal_char seperators = ',';
    kal_uint8* pu1next;	
    kal_uint8* pu1curr;
    kal_uint32 index;

    pFrameInfo->u4PayloadNum = 1;
    pFrameInfo->u4PayloadSize = sizeof(VSD_SSA_INFO_T);	
    pFrameInfo->pu1Payload = _mkv_mem_alloc(pr_mkv_provider, sizeof(VSD_SSA_INFO_T),KAL_TRUE);

    pu1Payload = (VSD_SSA_INFO_T *) pFrameInfo->pu1Payload;	

    kal_strtok_r((kal_char*)pFrameInfo->pu1Addr, &seperators, (kal_char **)&pu1next);
    pu1curr = pu1next;	

    for(index = 1; index < 9; index++)
    {
        while(seperators == *pu1next)
        {
            index++;
            pu1next++;
            if(index > 8)
            {
                break;
            }
        }	
        pu1curr = pu1next;		
		
        kal_strtok_r(NULL, &seperators, (kal_char **)&pu1next);

        if(index == 2)
        {
            pu1Payload->pu1Style = pu1curr;
            pu1Payload->u4StyleSize = pu1next - pu1curr;
#ifdef __MKV_MAUI_03155540
            if(pr_mkv_provider->u4SSA_style_len == 0)
            {
                pr_mkv_provider->pu1SSA_style = _mkv_mem_alloc(pr_mkv_provider, sizeof(VSD_SSA_INFO_T),KAL_FALSE);
                if(pr_mkv_provider->pu1SSA_style)
                {
                    kal_mem_cpy(pr_mkv_provider->pu1SSA_style,pu1Payload->pu1Style,pu1Payload->u4StyleSize);
                    pr_mkv_provider->u4SSA_style_len = pu1Payload->u4StyleSize;
                }
            }
            else
            {
                if(strncmp((char*)pr_mkv_provider->pu1SSA_style, (char*)pu1Payload->pu1Style, pr_mkv_provider->u4SSA_style_len) != 0)
                {
                    return KAL_FALSE;
                }
            }
#endif
        }
        else if(index == 4)
        {
            pu1Payload->u4LeftMargin = atoi(pu1curr, 4);
        }
        else if(index == 5)
        {
            pu1Payload->u4RightMargin = atoi(pu1curr, 4);
        }
        else if(index == 6)
        {
            pu1Payload->u4VerticalMargin= atoi(pu1curr, 4);
        }		
        else if(index == 8)
        {
            pu1Payload->pu1Subtitle= pu1curr;
            pu1Payload->u4SubtitleSize= pFrameInfo->u4FrameSize - (pu1curr - pFrameInfo->pu1Addr);
        }

    }	
	
    return KAL_TRUE;
}
#endif

static kal_bool _mkv_IsNeedheader(media_codec_type_t eCodecType)
{
    kal_bool fgHeader = KAL_FALSE;
    switch(eCodecType)
    {
        case MEDIA_CODEC_VID_MPEG4:
        case MEDIA_CODEC_VID_H264:					
        case MEDIA_CODEC_AUD_VORBIS:
#ifdef __VE_SUBTITLE_SUPPORT__				
#ifdef __MKV_SUBTITLE_HEADER__
        case MEDIA_CODEC_SUB_SSA:					
#endif  //__MKV_SUBTITLE_HEADER__					
#endif
            fgHeader = KAL_TRUE;
            break;
        default:
            break;
    }
    return fgHeader;
}


static kal_uint32 _mkv_readheaderstream(void *pvHandle, mkv_provider_codecinfo* pCodecInfo, kal_uint32 u4BuffAddr,SPIF_PROVIDER_FRAME_INFO_T* frame_info)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;
    void *prSrcHandle = pr_mkv_provider->pvSourceHandle;
    kal_uint32 u4Size = pCodecInfo->u4CodecPrivateSize;
    media_codec_type_t eCodecType = pCodecInfo->eCodecType;	
    kal_uint32 u4HeaderSize = u4Size;	

    if(eCodecType == MEDIA_CODEC_VID_H264)
    {
#ifdef __VE_H264_DEC_SUPPORT__		        
        kal_uint32 u4offset = 5;

        PU_VID_PARAM_SET_T *prVideoParamSetData;
        SPIF_H264_DECODER_PAYLOAD_INFO_T *prPayload = NULL;
        kal_uint32 i;			

        if(u4Size <= 5)
        {
            return 0;
        }		

        prVideoParamSetData = _mkv_mem_alloc(pr_mkv_provider, sizeof(PU_VID_PARAM_SET_T), KAL_TRUE);

        // size info of NAL, get from _mkv_parse_codec_specific_data
        prVideoParamSetData->u4NALuSizeInfo = pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_VIDEO]->u1NALULenSize;
        prVideoParamSetData->u4ParamSetTotalSize = pCodecInfo->u4CodecPrivateSize - u4offset;
        prVideoParamSetData->pu1ParamSetBuff = pCodecInfo->pu1CodecPrivateData + u4offset;
        u4HeaderSize = prVideoParamSetData->u4ParamSetTotalSize;

        // Obtain Parameter set NAL units
        ProviderUtilityGetParamSetNalUnits(prSrcAPI, prSrcHandle, prVideoParamSetData);
        prSrcAPI->SPFN_MEM_COPY((void*)u4BuffAddr, prVideoParamSetData->pu1ParamSetBuff, prVideoParamSetData->u4ParamSetTotalSize);			
			
        frame_info->u4PayloadNum = prVideoParamSetData->u4NumOfNALuParamSet;
        frame_info->u4PayloadSize = sizeof(SPIF_H264_DECODER_PAYLOAD_INFO_T) * prVideoParamSetData->u4NumOfNALuParamSet;
        prPayload = (SPIF_H264_DECODER_PAYLOAD_INFO_T *)_mkv_mem_alloc(pr_mkv_provider, frame_info->u4PayloadSize, KAL_FALSE);
        for(i = 0; i < prVideoParamSetData->u4NumOfNALuParamSet; i++)
        {
            prPayload[i].u4Address = (kal_uint32)u4BuffAddr + (prVideoParamSetData->prNALCTRLBuff[i].u4Address - (kal_uint32)prVideoParamSetData->pu1ParamSetBuff);
            prPayload[i].u4Length = prVideoParamSetData->prNALCTRLBuff[i].u4Length;
        }
        frame_info->pu1Payload = (kal_uint8 *)prPayload;
			
        if(prVideoParamSetData->prNALCTRLBuff)
        {
#if defined(__MKV_MEMORY_CHECK__) || defined(__MKV_PROVIDER_DEBUG__)	
            prSrcAPI->SPFN_FREE_CLA(prSrcHandle, prVideoParamSetData->prNALCTRLBuff);				
#else          
            _mkv_mem_free(pr_mkv_provider, (void**)&prVideoParamSetData->prNALCTRLBuff);						            
#endif
        }
			
        _mkv_mem_free(pr_mkv_provider, (void**)&prVideoParamSetData);						
#endif			
		
    }
    else if(eCodecType == MEDIA_CODEC_VID_MPEG4)
    {
        prSrcAPI->SPFN_MEM_COPY((void*)u4BuffAddr, pCodecInfo->pu1CodecPrivateData, u4Size);
    }
    else if(eCodecType == MEDIA_CODEC_AUD_VORBIS)
    {
        kal_uint32 u4PacketLen[3];
        kal_uint32 index;
        kal_uint32 offset = 1;  // skip first 2: mean 2 + 1 packet. 
        kal_uint32 acc_len = 0;

        for(index = 0; index < 3 - 1 ; index++)
        {
            kal_uint32 len = 0;
            while(1)
            {
                kal_uint32 temp;
                temp = _mkv_read_byte(pCodecInfo->pu1CodecPrivateData + offset, 1);
                len += temp;
                offset++;
                if(temp < 255)
                    break;
            }
            u4PacketLen[index] = len;
            acc_len += len;
        }	
        u4PacketLen[index] = u4Size - offset - acc_len;		
		
        u4HeaderSize = u4PacketLen[0] + u4PacketLen[2];

    	prSrcAPI->SPFN_MEM_COPY((void*)u4BuffAddr, pCodecInfo->pu1CodecPrivateData + offset, u4PacketLen[0]);
        prSrcAPI->SPFN_MEM_COPY((void*)(u4BuffAddr + u4PacketLen[0]), pCodecInfo->pu1CodecPrivateData + offset + u4PacketLen[0] + u4PacketLen[1], u4PacketLen[2]);
    }   

#ifdef __VE_SUBTITLE_SUPPORT__
#ifdef __MKV_SUBTITLE_HEADER__
    else if(eCodecType == MEDIA_CODEC_SUB_SSA)
    {
        prSrcAPI->SPFN_MEM_COPY((void*)u4BuffAddr, pCodecInfo->pu1CodecPrivateData, u4Size);
    }
#endif	
#endif	
    return u4HeaderSize;
}

static void _mkv_sendheader(void *pvHandle, SP_PORT_TYPE_T eTrackType)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;
    void *prSrcHandle = pr_mkv_provider->pvSourceHandle;
    SPIF_PROVIDER_FRAME_INFO_T* frame_info;
    kal_uint32 u4BuffAddr;
    mkv_provider_codecinfo* pCodecInfo = pr_mkv_provider->paCodecInfo[eTrackType];
    kal_uint32 u4Size = pCodecInfo->u4CodecPrivateSize;
    kal_uint32 u4ActualBufSize;
    media_codec_type_t eCodecType = pCodecInfo->eCodecType;
    kal_uint32 u4HeaderSize = 0;

    if(u4Size == 0 || KAL_FALSE == _mkv_IsNeedheader(eCodecType))
    {
        pCodecInfo->fgSendHeader = KAL_TRUE;    
        return;
    }

    frame_info = _mkv_mem_alloc(pr_mkv_provider, sizeof(SPIF_PROVIDER_FRAME_INFO_T), KAL_TRUE);    
	
    u4BuffAddr = prSrcAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(prSrcHandle, eTrackType, u4Size, &u4ActualBufSize);

    if(NULL == u4BuffAddr)
    {
        ASSERT(0);
    }


    u4HeaderSize = _mkv_readheaderstream(pvHandle, pCodecInfo, u4BuffAddr, frame_info);    

    prSrcAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(prSrcHandle, eTrackType, u4BuffAddr + u4HeaderSize);

    frame_info->pu1Addr = (kal_uint8 *)u4BuffAddr;
    frame_info->fgHeader = KAL_TRUE;
    frame_info->u4FrameSize = u4HeaderSize;


    if (prSrcAPI->SPFN_ADD_ONE_DATA(prSrcHandle, eTrackType, frame_info) == PROVIDER_ERROR_WAIT_RESOURCE)
    {
        ASSERT(0);
    }
    if(frame_info->pu1Payload)		
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&frame_info->pu1Payload);		
    }

    _mkv_mem_free(pr_mkv_provider, (void**)&frame_info);		
    pCodecInfo->fgSendHeader = KAL_TRUE;

}

static kal_bool _mkv_deliver_bitstream(void *pvHandle, SP_PORT_TYPE_T eTrackType, SPIF_PROVIDER_FRAME_INFO_T* frame_info, mkv_parser_block* block)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;	
    void *pvSrcHandle = pr_mkv_provider->pvSourceHandle;		
    mkv_parser_track *pTrack;	
    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;		
    kal_uint32 u4BuffAddr = NULL;	

    kal_uint32 u4Framecount = block->u4Framecount;
    kal_uint32 u4Bitstreamsize = 0;	
    kal_uint32 u4OverSize = 0;	

    if(u4Framecount == 0)
    {
        u4Framecount = 1;
    }
	
    pTrack = pr_mkv_provider->paCodecInfo[eTrackType]->pTrack;	  
    if(frame_info->u8Timestamp < pr_mkv_provider->u4StartTime[eTrackType])
    {
        _mkv_seek(pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, block->u4Length, MKV_SEEK_CUR);		  
        if(block->u4FrameLen)
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&block->u4FrameLen);
        }			
        _mkv_mem_free(pr_mkv_provider, (void**)&block);

        return KAL_TRUE;
    }

    //set key frame flag
    if(SOURCE_PROVIDER_PORT_VIDEO != eTrackType)    
    {
        frame_info->fgKeyFrame = KAL_TRUE;  // audio and subtitle always are key frame
    }
    else
    {
        frame_info->fgKeyFrame = block->fgkeyframe;    
    }
		
    if(pr_mkv_provider->eOpenType == MED_MODE_PREVIEW && pr_mkv_provider->u4FrameDeliver[eTrackType] > 0  || frame_info->u8Timestamp > pr_mkv_provider->u4StopTime[eTrackType])
    {	
        pr_mkv_provider->fgTrackEOF[eTrackType] = KAL_TRUE;	
	
        if(pr_mkv_provider->u4StopTime[eTrackType] < frame_info->u8Timestamp)
        {
            frame_info->u8Timestamp = pr_mkv_provider->u4StopTime[eTrackType];
        }	
        frame_info->fgEof = KAL_TRUE;
	
        if (prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, frame_info) == PROVIDER_ERROR_NONE)
        {
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_EOF, (kal_uint32)frame_info->u8Timestamp);						
        } 				
        if(block->u4FrameLen)
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&block->u4FrameLen);
        }						
        _mkv_mem_free(pr_mkv_provider, (void**)&block); 		

        return KAL_TRUE;		
    }
	
    if(!pr_mkv_provider->paCodecInfo[eTrackType]->fgSendHeader)
    {
        _mkv_sendheader(pr_mkv_provider, eTrackType);
    } 

	
    /* read bitstream */
    if(block->u4Length > 0)	
    {
#ifndef __MKV_PROVIDER_UT__
        kal_uint32 u4AvailableSize = 0;
        kal_uint32 u4DataLen = block->u4Length + u4Framecount * pTrack->pu1ContentCompSettingLen;
        kal_uint32 u4ReadSize = block->u4Length;		
        u4Bitstreamsize = prSrcAPI->SPFN_BITSTREAM_BUF_SIZE(pvSrcHandle, eTrackType);

        if(u4DataLen > u4Bitstreamsize)
        {
            u4OverSize = u4DataLen - u4Bitstreamsize;
            u4ReadSize = block->u4Length - u4OverSize;
            u4DataLen = u4Bitstreamsize;
            MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_ERROR, __LINE__, block->u4Length);				
        }

        u4BuffAddr = prSrcAPI->SPFN_BITSTREAM_BUF_QUERY_AVAILABLE_SIZE(pvSrcHandle, eTrackType, u4DataLen, &u4AvailableSize);
        if(u4AvailableSize > u4Bitstreamsize)
        {
            ASSERT(0);
        }
        if(u4BuffAddr == NULL)
        {
            pr_mkv_provider->paBlock[eTrackType] = block;
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_WAIT_BITSTREAM, (kal_uint32)frame_info->u8Timestamp);  
            MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_WAIT_RESOURCE, (kal_uint32)frame_info->u8Timestamp, __LINE__);									 
			
            return KAL_FALSE;
        }
				
		
        if(pTrack->i4ContentCompAlgo == 3)
        {		
            if(u4Framecount == 1)
            {            					
                kal_mem_cpy((void *)u4BuffAddr, pTrack->pu1ContentCompSettings, pTrack->pu1ContentCompSettingLen);
                _mkv_read(pr_mkv_provider, pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, (kal_uint8 *)u4BuffAddr + pTrack->pu1ContentCompSettingLen, u4ReadSize);
                if(u4OverSize > 0)						
                {
                    _mkv_seek(pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, u4OverSize, MKV_SEEK_CUR);	
                }				
            }
            else
            {
                kal_uint32 frame;
                kal_uint8* address = (kal_uint8 *)u4BuffAddr;
						
                if(u4OverSize > 0)						
                {
                    _mkv_seek(pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, block->u4Length, MKV_SEEK_CUR);                
                }
                else
                {
                    for(frame = 0; frame < u4Framecount; frame++)
                    {
                        kal_mem_cpy((void *)address, pTrack->pu1ContentCompSettings, pTrack->pu1ContentCompSettingLen);
                        address+=pTrack->pu1ContentCompSettingLen;
                        _mkv_read(pr_mkv_provider, pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, address, block->u4FrameLen[frame]);
                        address+=block->u4FrameLen[frame];						
                    }
                }
            }
        }
        else
        {
            _mkv_read(pr_mkv_provider, pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, (kal_uint8 *)u4BuffAddr, u4ReadSize);
            if(u4OverSize > 0)						
            {
                _mkv_seek(pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, u4OverSize, MKV_SEEK_CUR);                
            }
        }
        if(u4OverSize > 0)
        {
            prSrcAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(pvSrcHandle, eTrackType, u4BuffAddr + u4Bitstreamsize);		        
        }
        else
        {
            prSrcAPI->SPFN_BITSTREAM_BUF_UPDATA_ADD(pvSrcHandle, eTrackType, u4BuffAddr + u4DataLen);		
        }

#endif

        pr_mkv_provider->pu1BitstreamAddress[eTrackType] = (kal_uint8 *)u4BuffAddr;	

    }
			
    pr_mkv_provider->paBlock[eTrackType] = NULL;

#ifndef __MKV_SLIM__	
    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_MSG, __LINE__);
#endif
		
    /* set frame info */
    frame_info->pu1Addr = (kal_uint8 *)pr_mkv_provider->pu1BitstreamAddress[eTrackType];	
    if(u4OverSize > 0)
    {
        frame_info->u4FrameSize = u4Bitstreamsize;
        if(SOURCE_PROVIDER_PORT_AUDIO == eTrackType) 
        {
            frame_info->fgSilent = KAL_TRUE;
        }		
    }
    else
    {
	frame_info->u4FrameSize = block->u4Length + pTrack->pu1ContentCompSettingLen;
    }
	
#ifdef __VE_H264_DEC_SUPPORT__
    if(MKV_CODECID_V_MPEG4_ISO_AVC == pTrack->CodecID || MKV_CODECID_V_H264 == pTrack->CodecID)		
    {
        ProviderUtilityGetAvcSampleNALU(prSrcAPI, pr_mkv_provider->pvSourceHandle,frame_info,pr_mkv_provider->paCodecInfo[eTrackType]->u1NALULenSize);
#ifdef __MKV_PROVIDER_DEBUG__
        mkv_memalloc[mkv_memalloc_index] = (kal_uint32)frame_info->pu1Payload;
        mkv_memalloc_size[mkv_memalloc_index] = frame_info->u4PayloadSize;
        mkv_memalloc_index++;
        mkv_memalloc_totalsize += frame_info->u4PayloadSize;
#endif  //__MKV_PROVIDER_DEBUG__		
#ifdef __MKV_MEMORY_CHECK__
        mkv_memalloc_count++;
#endif  //__MKV_MEMORY_CHECK__

    }
#endif  //__VE_H264_DEC_SUPPORT__

#ifdef __VE_SUBTITLE_SUPPORT__
    if(MKV_CODECID_S_TEXT_ASS == pTrack->CodecID || MKV_CODECID_S_TEXT_SSA == pTrack->CodecID)		
    {
        if(block->u4Length > 0)
        {
#ifdef __MKV_MAUI_03155540
            if(KAL_FALSE == _mkv_getSSA_payload(pr_mkv_provider, frame_info))
            {
                frame_info->u4FrameSize = 0;
            }
#else
            _mkv_getSSA_payload(pr_mkv_provider, frame_info);
#endif
        }
    }
#endif //__VE_SUBTITLE_SUPPORT__

    if(u4Framecount <= 1)
    {
        if(block->u4FrameLen)
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&block->u4FrameLen);
        }
        _mkv_mem_free(pr_mkv_provider, (void**)&block);	

        if(frame_info->u4FrameSize > 0)
        {
            err = prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, frame_info); 		
            MKV_TRACE8(TRACE_GROUP_2, MKVPROVIDER_DELIVER_FRAME, eTrackType, (kal_uint32)frame_info->u8Timestamp, (kal_uint32)frame_info->pu1Addr, frame_info->u4FrameSize, frame_info->fgKeyFrame, pr_mkv_provider->u4FrameDeliver[eTrackType], frame_info->u4PayloadNum, frame_info->fgEof);		 		
        }

        if(err != PROVIDER_ERROR_NONE)
        {
            /* bitstream have added, but metadata fail (resend metadata when next call parse video) */		
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_WAIT_BUFFERHEADER, (kal_uint32)frame_info->u8Timestamp);  			
            MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_WAIT_RESOURCE, (kal_uint32)frame_info->u8Timestamp, __LINE__); 
            return KAL_TRUE;
        }			   
    }
    else //send each frame separately (PS: AAC and vorbis must send frame by frame)
    {
        kal_uint32 index; 
        kal_uint64 u8Timestampbase = frame_info->u8Timestamp; 
        block->u4Length = 0;			
        for(index = 0; index < u4Framecount; index++)
        {		
            if(block->u4FrameLen[index] == 0)
            {
                continue;
            }
            frame_info->pu1Addr = (kal_uint8 *)pr_mkv_provider->pu1BitstreamAddress[eTrackType];
            frame_info->u8Timestamp = u8Timestampbase + index * (pTrack->u8DefaultDuration / MKV_DEFAULT_TIMECODESCALE);
            frame_info->u4FrameSize = block->u4FrameLen[index] + pTrack->pu1ContentCompSettingLen;			  

            err = prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, frame_info); 	

            MKV_TRACE8(TRACE_GROUP_2, MKVPROVIDER_DELIVER_FRAME, eTrackType, (kal_uint32)frame_info->u8Timestamp, (kal_uint32)frame_info->pu1Addr, frame_info->u4FrameSize, frame_info->fgKeyFrame, pr_mkv_provider->u4FrameDeliver[eTrackType], frame_info->u4PayloadNum, frame_info->fgEof);				
			
            if(err != PROVIDER_ERROR_NONE)
            {
                /* bitstream have added, but metadata fail (resend metadata when next call parse video) */
                pr_mkv_provider->paBlock[eTrackType] = block;		
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_WAIT_BUFFERHEADER, (kal_uint32)frame_info->u8Timestamp);  							
                MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_WAIT_RESOURCE, (kal_uint32)frame_info->u8Timestamp, __LINE__); 
			
                return KAL_TRUE;
            }			
            else
            {
                pr_mkv_provider->pu1BitstreamAddress[eTrackType] += frame_info->u4FrameSize;
                block->u4FrameLen[index] = 0;
            }
        }				
        if(block->u4FrameLen)
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&block->u4FrameLen);
        }
        _mkv_mem_free(pr_mkv_provider, (void**)&block); 		   
    }		 
		   
    frame_info->u4FrameSize = 0;
	
    pr_mkv_provider->u4Timestamp[eTrackType]= frame_info->u8Timestamp;
    pr_mkv_provider->u4FrameDeliver[eTrackType]++;				
	
    if(frame_info->pu1Payload) 	
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&frame_info->pu1Payload);		
    }
    return KAL_TRUE;
}

static kal_bool _mkv_deliver(void *pvHandle, mkv_parser_block* block)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;	
    void *pvSrcHandle = pr_mkv_provider->pvSourceHandle;

    SPIF_PROVIDER_FRAME_INFO_T* frame_info = NULL;
    SP_PORT_TYPE_T eTrackType = SOURCE_PROVIDER_PORT_MAX;	
    kal_bool fgResult = KAL_FALSE;

    MKV_TRACE4(TRACE_GROUP_2, MKVPROVIDER_DELIVER, block->u4TrackNumber, (kal_uint32)block->i2Timecode, block->u4Framecount, block->u4Length);
    
    if(block->u4TrackNumber == pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_VIDEO])
    {
        eTrackType = SOURCE_PROVIDER_PORT_VIDEO;    		
        if(block->u4Duration)
        {
            // bypass video and audio track duration block.
            pr_mkv_provider->u4Timestamp[eTrackType] += block->u4Duration;
            _mkv_mem_free(pr_mkv_provider, (void**)&block);
            return KAL_TRUE;
        }		
    }
    else if(block->u4TrackNumber == pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_AUDIO])
    {
        eTrackType = SOURCE_PROVIDER_PORT_AUDIO;    				
        if(block->u4Duration)
        {
            // bypass video and audio track duration block.
            pr_mkv_provider->u4Timestamp[eTrackType] += block->u4Duration;            
            _mkv_mem_free(pr_mkv_provider, (void**)&block);
            return KAL_TRUE;
        }		
    }
#ifdef __VE_SUBTITLE_SUPPORT__	
	else if(block->u4TrackNumber == pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE])
    {
        eTrackType = SOURCE_PROVIDER_PORT_SUBTITLE;        
        if(block->fgDuration) 
        {
            if(pr_mkv_provider->subtitle_duration_frame != NULL)        
            {
                ASSERT(0);
            }
            pr_mkv_provider->subtitle_duration_frame = _mkv_mem_alloc(pr_mkv_provider, sizeof(SPIF_PROVIDER_FRAME_INFO_T), KAL_TRUE);        
            pr_mkv_provider->subtitle_duration_frame->fgSilent = KAL_TRUE;			

            if(pr_mkv_provider->paBlock[SOURCE_PROVIDER_PORT_SUBTITLE] != NULL || pr_mkv_provider->paFrameInfo[SOURCE_PROVIDER_PORT_SUBTITLE]->u4FrameSize > 0)		
            {     
                pr_mkv_provider->subtitle_duration_frame->u8Timestamp = block->u4Duration;
            }
            else
            {
                pr_mkv_provider->subtitle_duration_frame->u8Timestamp = pr_mkv_provider->u4Timestamp[eTrackType] + block->u4Duration; 	                   
                if(prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, pr_mkv_provider->subtitle_duration_frame) == PROVIDER_ERROR_NONE)
                {              
                    _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->subtitle_duration_frame);        
                }				
            }
            _mkv_mem_free(pr_mkv_provider, (void**)&block);        
            return KAL_TRUE;			
        }	
    }
#endif // __VE_SUBTITLE_SUPPORT__	
    else
    {
        ASSERT(0);
    }

    MKV_START_LOGGING("MKD");
	
    frame_info = pr_mkv_provider->paFrameInfo[eTrackType];    
    kal_mem_set(frame_info, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));		
    frame_info->u8Timestamp = pr_mkv_provider->paCluster[eTrackType]->u4TimeCode + block->i2Timecode;	

    if(MKV_DEFAULT_TIMECODESCALE != pr_mkv_provider->mkvparser->u4TimecodeScale)
    {
        frame_info->u8Timestamp = frame_info->u8Timestamp * pr_mkv_provider->mkvparser->u4TimecodeScale / MKV_DEFAULT_TIMECODESCALE;   
    }

    fgResult = _mkv_deliver_bitstream(pr_mkv_provider, eTrackType, frame_info, block);

#ifndef __MKV_SLIM__

    if(KAL_TRUE == fgResult)
    {    	
        if(SOURCE_PROVIDER_PORT_VIDEO == eTrackType)
        {
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_DELIVER_VIDEO, (kal_uint32)frame_info->u8Timestamp);
        }
        else if(SOURCE_PROVIDER_PORT_AUDIO == eTrackType)
        {
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_DELIVER_AUDIO, (kal_uint32)frame_info->u8Timestamp);
        }
#ifdef __VE_SUBTITLE_SUPPORT__	
        else if(SOURCE_PROVIDER_PORT_SUBTITLE == eTrackType)
        {        
            video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_DELIVER_SUBTITLE, (kal_uint32)frame_info->u8Timestamp);
        }    
#endif // __VE_SUBTITLE_SUPPORT__		
    }

#endif // __MKV_SLIM__

	MKV_STOP_LOGGING("MKD");

	return fgResult;
}

/*****************************************************************************
 * FUNCTION
 *  _rm_get_codec_type
 * DESCRIPTION
 *  This function is to convert fourCC to a defined codec type.
 * PARAMETERS
 *  param1 : [IN]  UINT32 ulSize
 *                 The size which user want to allocate.* RETURNS
 *  media_codec_type_t
*****************************************************************************/
static media_codec_type_t _mkv_get_codec_type(mkv_parser_track* pTrack)
{
    media_codec_type_t ret = MEDIA_CODEC_NONE;
    MKV_CODECID_T CodecID = pTrack->CodecID;	
    switch(CodecID)
    {
        /* VIDEO */
#ifdef __VE_H264_DEC_SUPPORT__		
        case MKV_CODECID_V_MPEG4_ISO_AVC:
            if(pTrack->u4CodecPrivateLen > 0)			
            {
                ret = MEDIA_CODEC_VID_H264;
            }
            break;
#endif			
        case MKV_CODECID_V_MPEG4_ISO_ASP:
            ret = MEDIA_CODEC_VID_MPEG4;
            break;
        case MKV_CODECID_V_MS_VFW_FOURCC:
        {
            mkv_BitmapInfoheader* bitmapinfo;
            if(pTrack->u4CodecPrivateLen > 0)
            {
                bitmapinfo = (mkv_BitmapInfoheader*)pTrack->pu1CodecPrivate;                        
                if(pTrack->VideoInfo)
                {
                    if(pTrack->VideoInfo->u4PixelWidth == 0)
                    {
                        pTrack->VideoInfo->u4PixelWidth = bitmapinfo->biWidth;
                    }            
                    if(pTrack->VideoInfo->u4PixelHeight == 0)
                    {
                        pTrack->VideoInfo->u4PixelHeight = bitmapinfo->biHeight;
                    }			
                }
                if(bitmapinfo->biCompression == 0x33363248) //H263
                {
                    ret = MEDIA_CODEC_VID_H263;  
                }			    
                else if(bitmapinfo->biCompression == 0x30355844) //DX50 
                {
                    ret = MEDIA_CODEC_VID_MPEG4;  
                }				
                else if(bitmapinfo->biCompression == 0x44495658) //XVID
                {
                    ret = MEDIA_CODEC_VID_MPEG4;
                }			
                else if(bitmapinfo->biCompression == 0x58564944) //DIVX
                {
                    ret = MEDIA_CODEC_VID_MPEG4;
                }						
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            }
        }
            break;	
#ifdef  __VE_MJPEG_DEC_SW_SUPPORT__			
        case MKV_CODECID_V_MJPEG:
            ret = MEDIA_CODEC_VID_MJPG;
            break;			
#endif
#ifdef __VE_VP8_DEC_SW_SUPPORT__
        case MKV_CODECID_V_VP8:
            ret = MEDIA_CODEC_VID_VP8;
            break;				
#endif			
        /* AUDIO */
#ifdef AAC_DECODE		
        case MKV_CODECID_A_AAC:
        case MKV_CODECID_A_AAC_MPEG4_LC:			
        case MKV_CODECID_A_AAC_MPEG4_LC_SBR:			
            ret = MEDIA_CODEC_AUD_AAC;
            break;				
#endif			
        case MKV_CODECID_A_MPEG_L3:
            ret = MEDIA_CODEC_AUD_MPEGLAYER3;
            break;			
#ifdef MUSICAM_DECODE			
        case MKV_CODECID_A_MPEG_L1:
        case MKV_CODECID_A_MPEG_L2:
            ret = MEDIA_CODEC_AUD_MPEG;
            break;	
#endif			
        case MKV_CODECID_A_MS_ACM:
        {
            mkv_Waveformatex* prWaveformatex;
            if(pTrack->u4CodecPrivateLen > 0)
            {
                prWaveformatex = (mkv_Waveformatex*)pTrack->pu1CodecPrivate;
                switch(prWaveformatex->u2FormatTag)
                {
                    case WAVE_FORMAT_PCM:
                        ret = MEDIA_CODEC_AUD_PCM;
                        break;
                    case WAVE_FORMAT_MPEG:
                        ret = MEDIA_CODEC_AUD_MPEG;
                        break;						
                    case WAVE_FORMAT_MPEGLAYER3:
                        ret = MEDIA_CODEC_AUD_MPEGLAYER3;
                        break;							
                    default:
                        break;
                }					
            }
        }
            break;
        case MKV_CODECID_A_PCM_INT_LIT:    // only support LIT			
            ret = MEDIA_CODEC_AUD_PCM;
            break;		
#ifdef __VORBIS_DECODE__			
        case MKV_CODECID_A_VORBIS:
            ret = MEDIA_CODEC_AUD_VORBIS;
            break;
#endif			
#ifdef __VE_SUBTITLE_SUPPORT__
        /* SUBTITLE */						   
        case MKV_CODECID_S_TEXT_UTF8:
            ret = MEDIA_CODEC_SUB_UTF8;
            break;			
        case MKV_CODECID_S_TEXT_ASS:
        case MKV_CODECID_S_TEXT_SSA:			
            ret = MEDIA_CODEC_SUB_SSA;
            break;			
#endif			
        default: /* Don't need ASSERT*/            
            break;		
    }
	
    if(pTrack->i4ContentCompAlgo != 0 && pTrack->i4ContentCompAlgo != 3)
    {
        // Not support compress zlib, bzlib, lzo1x, encrption
        ret = MEDIA_CODEC_NONE;        
    }
	
    return ret;
}

static void _mkv_parse_codec_specific_data(void *pvHandle, kal_uint16 stream_idx, mkv_provider_codecinfo* prCodecInfo)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    kal_uint32 streamindex;
    MKV_CODECID_T CodecID = MKV_CODECID_UNKNOW;
    mkv_parser_track* pTrackInfo = NULL;

    for(streamindex = 0; streamindex < pr_mkv_provider->mkvparser->u4TrackCount; streamindex++)
    {
        pTrackInfo = pr_mkv_provider->pTrackInfo[streamindex];
        if(pTrackInfo == NULL)
        {
            continue;
        }
        if(stream_idx == pTrackInfo->u4TrackNumber)
        {
            CodecID = pTrackInfo->CodecID;            
            break;
        }
    }

    if(NULL == pTrackInfo)
    {
        ASSERT(0);
    }

    prCodecInfo->eCodecType = _mkv_get_codec_type(pTrackInfo);
    prCodecInfo->pTrack = pTrackInfo;
	
    if(pTrackInfo->u4CodecPrivateLen == 0)	
    {
        return;
    }	
    switch(CodecID)
    {
#ifdef __VE_H264_DEC_SUPPORT__                
        case MKV_CODECID_V_MPEG4_ISO_AVC:
        {
            prCodecInfo->u1NALULenSize = ((kal_uint8)_mkv_read_byte(pTrackInfo->pu1CodecPrivate + 4, 1) & 0x03) + 1; 		
#ifdef __VE_DUMP_PROVIDER_BITSTREAM__			
            kal_trace(TRACE_GROUP_1, VE_TRC_H264_NALUSIZELEN, prCodecInfo->u1NALULenSize);
#endif
            prCodecInfo->u4CodecPrivateSize = pTrackInfo->u4CodecPrivateLen;
            prCodecInfo->pu1CodecPrivateData = pTrackInfo->pu1CodecPrivate;		
        }    			
            break;
#endif			
        case MKV_CODECID_V_MPEG4_ISO_ASP:
        case MKV_CODECID_S_TEXT_ASS:	
        case MKV_CODECID_S_TEXT_SSA:
        case MKV_CODECID_A_VORBIS:			
            prCodecInfo->u4CodecPrivateSize = pTrackInfo->u4CodecPrivateLen;
            prCodecInfo->pu1CodecPrivateData = pTrackInfo->pu1CodecPrivate;
/*	    codecinfo->pu1CodecPrivateData = _mkv_mem_alloc(pr_mkv_provider, codecinfo->u4CodecPrivateSize);			
            kal_mem_cpy(codecinfo->pu1CodecPrivateData, pr_mkv_provider->pTrackInfo[streamindex]->pu1CodecPrivate, codecinfo->u4CodecPrivateSize);				
*/			
            break;									
    }
}

/*****************************************************************************
 * FUNCTION
 *    MKVProviderOpen
 * DESCRIPTION
 *  This function is used to open MKV provider.
 *  1) Initialize MKV control structure
 *  2) Create File handle (allocate memory from core)
 *  3) Create RM parser (header, video, audio)
 *  4) Set IO function to parser
 *  5) Parse header section
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 ****************************************************************************/
static PROVIDER_ERROR_T MKVProviderOpen(void *pvHandle, SPIF_PROVIDER_OPEN_INFO_T *prInfo)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    SPIF_OPEN_INFO_T* rOpenFile = NULL;
    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;
    kal_uint8 *pu1FileInfoBuf = NULL;
    kal_uint32 bytes_read;
    kal_uint32 u4FileSize = 0;		

    MKV_START_LOGGING("MKO");

    // Initialize MKV control structure
    pr_mkv_provider->eOpenTrack = prInfo->eOpenTrack;
    pr_mkv_provider->eOpenType = prInfo->eOpenType;

    // Create File handle

    rOpenFile = (SPIF_OPEN_INFO_T *)_mkv_mem_alloc(pr_mkv_provider,sizeof(SPIF_OPEN_INFO_T), KAL_TRUE);

    pr_mkv_provider->mkv_file_handle = rOpenFile;

    rOpenFile->prFileHandle = (STFSAL *)_mkv_mem_alloc(pr_mkv_provider, sizeof(STFSAL), KAL_TRUE);
    rOpenFile->pu1Data = prInfo->pu1Data;
    rOpenFile->u4Size = prInfo->u4DataSize;

    rOpenFile->pu1SetBuf = (kal_uint8 *)_mkv_mem_alloc(pr_mkv_provider, MKV_CORE_FILE_BUFFER_SIZE, KAL_FALSE);
    if(rOpenFile->pu1SetBuf)
    {
        rOpenFile->fgSetBuffer = KAL_TRUE;
        rOpenFile->u4SetBufSize = MKV_CORE_FILE_BUFFER_SIZE;
    }

    /* open file */
#ifdef __MKV_PROVIDER_UT__
    if(FSAL_Open(rOpenFile->prFileHandle, (void*)rOpenFile->pu1Data, FSAL_READ_SHARED) != FSAL_OK)
#else
    if(prSrcAPI->SPFN_BASE_FILE_OPEN(rOpenFile) != PROVIDER_ERROR_NONE)
#endif
    {
        return PROVIDER_ERROR;
    }

    // prepare seek hint
    if(pr_mkv_provider->eOpenType != MED_MODE_PREVIEW) 
    {
        rOpenFile->prSeekHint= (FS_FileLocationHint *)_mkv_mem_alloc(pr_mkv_provider, MKV_FILE_SEEK_HINT_SIZE * sizeof(FS_FileLocationHint), KAL_FALSE);
    }
    if(rOpenFile->prSeekHint)
    {
        rOpenFile->fgSetSeekHint= KAL_TRUE;
        rOpenFile->u4SetHintSize = MKV_FILE_SEEK_HINT_SIZE;
    }	
	
    if(rOpenFile->prSeekHint)    
    {
        FSAL_Status eRet;
        kal_uint32 i;
        // get file size
        eRet = FSAL_GetFileSize(rOpenFile->prFileHandle, &u4FileSize);
        if (eRet != FSAL_OK)
        {
            return PROVIDER_ERROR;
        }
        for (i = 0; i < MKV_FILE_SEEK_HINT_SIZE; i++)
        {
            kal_uint64 temp = ((kal_uint64) u4FileSize * (kal_uint64) (i + 1)) / (kal_uint64) (MKV_FILE_SEEK_HINT_SIZE + 1);
			rOpenFile->prSeekHint[i].Index = (kal_uint32) temp;
        }
        //DRM_set_seek_hint(rOpenFile->prFileHandle->hFile, MKV_FILE_SEEK_HINT_SIZE, rOpenFile->prSeekHint);
        FSAL_SetSeekHint(rOpenFile->prFileHandle, MKV_FILE_SEEK_HINT_SIZE, rOpenFile->prSeekHint);
    }
	
    pu1FileInfoBuf = (void *)_mkv_mem_alloc(pr_mkv_provider, 5, KAL_TRUE);

    bytes_read = _mkv_read(pr_mkv_provider, rOpenFile->prFileHandle, pu1FileInfoBuf, 5);

    /* test if mkv file */
    if ((bytes_read != 5) || ! mkv_parser_check_ebml(pu1FileInfoBuf))
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&pu1FileInfoBuf);    
        return PROVIDER_ERROR;
    }

    _mkv_mem_free(pr_mkv_provider, (void**)&pu1FileInfoBuf);    

    _mkv_seek(rOpenFile->prFileHandle, 0, MKV_SEEK_START);

    /* create mkv header parser */
    pr_mkv_provider->mkvparser = mkv_parser_create(pr_mkv_provider, NULL, pr_mkv_provider, _mkv_mem_alloc, _mkv_mem_free);

    mkv_parser_set_io(pr_mkv_provider->mkvparser, pr_mkv_provider, rOpenFile->prFileHandle, _mkv_read, _mkv_seek, _mkv_get_curpos);
    mkv_parser_set_deliver(pr_mkv_provider->mkvparser, pr_mkv_provider, _mkv_deliver);

    if(mkv_parser_init(pr_mkv_provider->mkvparser, (pr_mkv_provider->eOpenType!= MED_MODE_PREVIEW)?KAL_TRUE:KAL_FALSE, u4FileSize) == KAL_FALSE)
    {
        return PROVIDER_ERROR;
    }

    /* traverse trace info in mkv parser*/
    {
        kal_uint32 index;
        kal_uint32 index_video = 0;
        kal_uint32 index_audio = 0;
        kal_uint32 index_subtitle = 0;
        mkv_parser_track* pTrack = pr_mkv_provider->mkvparser->pTrackList;		
        if(pr_mkv_provider->mkvparser->u4TrackCount == 0  || pTrack == NULL)
        {
            return PROVIDER_ERROR;
        }
        pr_mkv_provider->pTrackInfo = _mkv_mem_alloc(pr_mkv_provider, pr_mkv_provider->mkvparser->u4TrackCount * sizeof(mkv_parser_track*), KAL_FALSE);
        if(pr_mkv_provider->pTrackInfo == NULL)
        {
            pr_mkv_provider->mkvparser->u4TrackCount = 0;
        }

        for(index = 0; index < pr_mkv_provider->mkvparser->u4TrackCount; index++)
        {
            if(pTrack == NULL)
            {
                ASSERT(0);
                pr_mkv_provider->mkvparser->u4TrackCount = index;
                break;
            }
		
            pr_mkv_provider->pTrackInfo[index] = pTrack;

            if(_mkv_get_codec_type(pTrack) == MEDIA_CODEC_NONE)
            {
                pTrack = pTrack->next;
                continue;
            }
			
            switch(pTrack->u4TrackType)
            {
                case MKV_TRACKTYPE_VIDEO:
                    pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO]++;
                    break;
                case MKV_TRACKTYPE_AUDIO:
                    pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO]++;
                    break;
#ifdef __VE_SUBTITLE_SUPPORT__					
                case MKV_TRACKTYPE_SUBTITLE:
                    pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE]++;
                    break;					
#endif					
                default:
#ifndef __MKV_SLIM__                
                    ASSERT(0);
#endif
                    break;
            }
				
            pTrack = pTrack->next;

        }		
        if((pr_mkv_provider->eOpenTrack & SOURCE_PROVIDER_TRACK_VIDEO) == NULL)		
        {
            pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] = 0;
        }			
        if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] > 0)
        {
            pr_mkv_provider->video_stream_info = _mkv_mem_alloc(pr_mkv_provider, pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] * sizeof(SPIF_VIDEO_STREAM_INFO_T), KAL_FALSE); 
            if(pr_mkv_provider->video_stream_info == NULL)
            {
                pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] = 0;
            }
        }

        if((pr_mkv_provider->eOpenTrack & SOURCE_PROVIDER_TRACK_AUDIO) == NULL)		
        {
            pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] = 0;
        }

        if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] > 0)		
        {
            pr_mkv_provider->audio_stream_info = _mkv_mem_alloc(pr_mkv_provider, pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] * sizeof(SPIF_AUDIO_STREAM_INFO_T), KAL_FALSE); 		
            if(pr_mkv_provider->audio_stream_info == NULL)
            {
                pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] = 0;
            }
        }
#ifdef __VE_SUBTITLE_SUPPORT__
        if((pr_mkv_provider->eOpenTrack & SOURCE_PROVIDER_TRACK_SUBTITLE) == NULL)		
        {
            pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE] = 0;
        }			
        if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE] > 0)		
        {
            pr_mkv_provider->subtitle_stream_info = _mkv_mem_alloc(pr_mkv_provider, pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE] * sizeof(SPIF_SUBTITLE_STREAM_INFO_T), KAL_FALSE); 		
            if(pr_mkv_provider->subtitle_stream_info == NULL)
            {
                pr_mkv_provider->subtitle_stream_info = 0;
            }
        }			
#endif		
        for(index = 0; index < pr_mkv_provider->mkvparser->u4TrackCount; index++)
        {
            mkv_parser_track* pTrack = pr_mkv_provider->pTrackInfo[index];
            if(NULL == pTrack)
            {
                ASSERT(0);
            }
            if(_mkv_get_codec_type(pTrack) == MEDIA_CODEC_NONE)
            {
                continue;
            }
				
            switch(pTrack->u4TrackType)
            {
                case MKV_TRACKTYPE_VIDEO:
                    {
                        SPIF_VIDEO_STREAM_INFO_T* video_stream_info;
                        if(pr_mkv_provider->video_stream_info == NULL || pTrack->VideoInfo == NULL)
                        {
                            break;
                        }
                        video_stream_info = &pr_mkv_provider->video_stream_info[index_video];						
                        video_stream_info->u4StreamIndex = pTrack->u4TrackNumber;
                        video_stream_info->eCodecType = _mkv_get_codec_type(pTrack);
                        video_stream_info->u4Width = pTrack->VideoInfo->u4PixelWidth;
                        video_stream_info->u4Height = pTrack->VideoInfo->u4PixelHeight;	
                        if(pTrack->u8DefaultDuration != 0)
                        {
                            if(pTrack->u8DefaultDuration >= MKV_DEFAULT_TIMECODESCALE)
                            {
                                video_stream_info->u4Fps = 1000 * 100 / (pTrack->u8DefaultDuration / MKV_DEFAULT_TIMECODESCALE);  //30fps, set u4Fps 3000
                            }
                            else
                            {
                                video_stream_info->u4Fps = 1000 * 100 * (MKV_DEFAULT_TIMECODESCALE / pTrack->u8DefaultDuration);  //30fps, set u4Fps 3000                            
                            }
                        }
                        video_stream_info->u8Duration = pr_mkv_provider->mkvparser->u4Duration;
                        index_video++; 
                    }
                    break;
                case MKV_TRACKTYPE_AUDIO:
                    {
                        SPIF_AUDIO_STREAM_INFO_T* audio_stream_info;
                        if(pr_mkv_provider->audio_stream_info == NULL || pTrack->AudioInfo == NULL)
                        {
                            break;
                        }						
                        audio_stream_info = &pr_mkv_provider->audio_stream_info[index_audio];						
                        audio_stream_info->u4StreamIndex = pTrack->u4TrackNumber;
                        audio_stream_info->eCodecType = _mkv_get_codec_type(pTrack);					
                        audio_stream_info->u2Channels = pTrack->AudioInfo->u4Channels;
                        audio_stream_info->u8Duration = pr_mkv_provider->mkvparser->u4Duration;
                        audio_stream_info->u4SampleRate = pTrack->AudioInfo->u4SamplingFrequency;
                        audio_stream_info->u2BitsPerSample = pTrack->AudioInfo->u4BitDepth;
                        if(audio_stream_info->eCodecType == MEDIA_CODEC_AUD_AAC || audio_stream_info->eCodecType == MEDIA_CODEC_AUD_HE_AAC)
                        {
                            audio_stream_info->fgAddHeader = KAL_TRUE;
                        }					
                        index_audio++;
                    }						
                    break;
#ifdef __VE_SUBTITLE_SUPPORT__					
                case MKV_TRACKTYPE_SUBTITLE:
                    {
                        SPIF_SUBTITLE_STREAM_INFO_T* subtitle_stream_info;
                        if(pr_mkv_provider->subtitle_stream_info == NULL)
                        {
                            break;
                        }												
                        subtitle_stream_info = &pr_mkv_provider->subtitle_stream_info[index_subtitle];							
                        subtitle_stream_info->u4StreamIndex = pTrack->u4TrackNumber;
                        subtitle_stream_info->eCodecType = _mkv_get_codec_type(pTrack);			
                        subtitle_stream_info->u8Duration = pr_mkv_provider->mkvparser->u4Duration;
                        subtitle_stream_info->fgDefault = pTrack->fgFlagDefault;
                        if(pTrack->pu1Language)
                        {
                            kal_mem_cpy(&subtitle_stream_info->u4Language, pTrack->pu1Language, 3);					
                        }
                        else
                        {
                            subtitle_stream_info->u4Language = 6778469; //eng 0x656e67
                        }
                        index_subtitle++;						
                    }					
                    break;					
#endif					
                default:
                    ASSERT(0);
                    break;					
            }            
        }
    }

    /* video */
    if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] > 0 && pr_mkv_provider->eOpenTrack & SOURCE_PROVIDER_TRACK_VIDEO)
    {
        SPIF_OPEN_INFO_T* rVideoOpenFile = NULL;
		kal_uint32 u4VideoBufSize = MKV_VIDEO_FILE_BUFFER_SIZE;

        if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] == 0)
        {
            u4VideoBufSize += MKV_AUDIO_FILE_BUFFER_SIZE;
        }
		
        rVideoOpenFile = (SPIF_OPEN_INFO_T *)_mkv_mem_alloc(pr_mkv_provider,sizeof(SPIF_OPEN_INFO_T), KAL_TRUE);

        pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_VIDEO] = rVideoOpenFile;
        rVideoOpenFile->prFileHandle = (STFSAL *)_mkv_mem_alloc(pr_mkv_provider, sizeof(STFSAL), KAL_TRUE);
        rVideoOpenFile->pu1Data = prInfo->pu1Data;
        rVideoOpenFile->u4Size = prInfo->u4DataSize;

	rVideoOpenFile->pu1SetBuf = (kal_uint8 *)_mkv_mem_alloc(pr_mkv_provider, u4VideoBufSize, KAL_FALSE);
        if(rVideoOpenFile->pu1SetBuf)
        {
            rVideoOpenFile->fgSetBuffer = KAL_TRUE;
            rVideoOpenFile->u4SetBufSize = u4VideoBufSize;
        }
        if(pr_mkv_provider->mkv_file_handle->prSeekHint)
        {
            rVideoOpenFile->prSeekHint = pr_mkv_provider->mkv_file_handle->prSeekHint;
            rVideoOpenFile->fgSetSeekHint= KAL_TRUE;
            rVideoOpenFile->u4SetHintSize = MKV_FILE_SEEK_HINT_SIZE;
        }			
		
        /* open file */
#ifdef __MKV_PROVIDER_UT__
        if(FSAL_Open(rVideoOpenFile->prFileHandle, (void*)rVideoOpenFile->pu1Data, FSAL_READ_SHARED) != FSAL_OK)
#else
        if(prSrcAPI->SPFN_BASE_FILE_OPEN(rVideoOpenFile) != PROVIDER_ERROR_NONE)
#endif
        {
            return PROVIDER_ERROR;
        }
        pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_VIDEO] = (mkv_parser_cluster*)_mkv_mem_alloc(pr_mkv_provider, sizeof(mkv_parser_cluster), KAL_TRUE);
        pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_VIDEO] = _mkv_mem_alloc(pr_mkv_provider, sizeof(mkv_provider_codecinfo), KAL_TRUE);		
        pr_mkv_provider->paFrameInfo[SOURCE_PROVIDER_PORT_VIDEO] = _mkv_mem_alloc(pr_mkv_provider, sizeof(SPIF_PROVIDER_FRAME_INFO_T), KAL_TRUE);		
    }

    /* audio */	
    if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] > 0  && pr_mkv_provider->eOpenTrack & SOURCE_PROVIDER_TRACK_AUDIO)
    {
        SPIF_OPEN_INFO_T* rAudioOpenFile = NULL;
	kal_uint32 u4AudioBufSize = MKV_AUDIO_FILE_BUFFER_SIZE;

        if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] == 0)
        {
            u4AudioBufSize += MKV_VIDEO_FILE_BUFFER_SIZE;
        }

		
        rAudioOpenFile = (SPIF_OPEN_INFO_T *)_mkv_mem_alloc(pr_mkv_provider,sizeof(SPIF_OPEN_INFO_T), KAL_TRUE);

        pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_AUDIO] = rAudioOpenFile;
        rAudioOpenFile->prFileHandle = (STFSAL *)_mkv_mem_alloc(pr_mkv_provider, sizeof(STFSAL), KAL_TRUE);
        rAudioOpenFile->pu1Data = prInfo->pu1Data;
        rAudioOpenFile->u4Size = prInfo->u4DataSize;

        rAudioOpenFile->pu1SetBuf = (kal_uint8 *)_mkv_mem_alloc(pr_mkv_provider, u4AudioBufSize, KAL_FALSE);
        if(rAudioOpenFile->pu1SetBuf)
        {
            rAudioOpenFile->fgSetBuffer = KAL_TRUE;
            rAudioOpenFile->u4SetBufSize = u4AudioBufSize;
        }
        if(pr_mkv_provider->mkv_file_handle->prSeekHint)
        {
            rAudioOpenFile->prSeekHint = pr_mkv_provider->mkv_file_handle->prSeekHint;
            rAudioOpenFile->fgSetSeekHint= KAL_TRUE;
            rAudioOpenFile->u4SetHintSize = MKV_FILE_SEEK_HINT_SIZE;
        }

		
        /* open file */
#ifdef __MKV_PROVIDER_UT__
        if(FSAL_Open(rAudioOpenFile->prFileHandle, (void*)rAudioOpenFile->pu1Data, FSAL_READ_SHARED) != FSAL_OK)
#else
        if(prSrcAPI->SPFN_BASE_FILE_OPEN(rAudioOpenFile) != PROVIDER_ERROR_NONE)
#endif
        {
            return PROVIDER_ERROR;
        }
        pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_AUDIO] = (mkv_parser_cluster*)_mkv_mem_alloc(pr_mkv_provider, sizeof(mkv_parser_cluster), KAL_TRUE);
        pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_AUDIO] = _mkv_mem_alloc(pr_mkv_provider, sizeof(mkv_provider_codecinfo), KAL_TRUE);		
        pr_mkv_provider->paFrameInfo[SOURCE_PROVIDER_PORT_AUDIO] = _mkv_mem_alloc(pr_mkv_provider, sizeof(SPIF_PROVIDER_FRAME_INFO_T), KAL_TRUE);	
    }
#ifdef __VE_SUBTITLE_SUPPORT__
	/* subtitle */ 
    if(pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE] > 0 && pr_mkv_provider->eOpenTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)
    {
        SPIF_OPEN_INFO_T* rSubtitleOpenFile = NULL;
        rSubtitleOpenFile = (SPIF_OPEN_INFO_T *)_mkv_mem_alloc(pr_mkv_provider,sizeof(SPIF_OPEN_INFO_T), KAL_TRUE);

        pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_SUBTITLE] = rSubtitleOpenFile;
        rSubtitleOpenFile->prFileHandle = (STFSAL *)_mkv_mem_alloc(pr_mkv_provider, sizeof(STFSAL), KAL_TRUE);
        rSubtitleOpenFile->pu1Data = prInfo->pu1Data;
        rSubtitleOpenFile->u4Size = prInfo->u4DataSize;

        rSubtitleOpenFile->pu1SetBuf = (kal_uint8 *)_mkv_mem_alloc(pr_mkv_provider, MKV_SUBTITLE_FILE_BUFFER_SIZE, KAL_FALSE);
        if(rSubtitleOpenFile->pu1SetBuf)
        {
            rSubtitleOpenFile->fgSetBuffer = KAL_TRUE;
            rSubtitleOpenFile->u4SetBufSize = MKV_SUBTITLE_FILE_BUFFER_SIZE;
        }
        if(pr_mkv_provider->mkv_file_handle->prSeekHint)
        {
            rSubtitleOpenFile->prSeekHint = pr_mkv_provider->mkv_file_handle->prSeekHint;
            rSubtitleOpenFile->fgSetSeekHint= KAL_TRUE;
            rSubtitleOpenFile->u4SetHintSize = MKV_FILE_SEEK_HINT_SIZE;
        }

		
        /* open file */
#ifdef __MKV_PROVIDER_UT__
        if(FSAL_Open(rSubtitleOpenFile->prFileHandle, (void*)rSubtitleOpenFile->pu1Data, FSAL_READ_SHARED) != FSAL_OK)
#else
        if(prSrcAPI->SPFN_BASE_FILE_OPEN(rSubtitleOpenFile) != PROVIDER_ERROR_NONE)
#endif
        {
            return PROVIDER_ERROR;
        }
        pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_SUBTITLE] = (mkv_parser_cluster*)_mkv_mem_alloc(pr_mkv_provider, sizeof(mkv_parser_cluster), KAL_TRUE);
        pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_SUBTITLE] = _mkv_mem_alloc(pr_mkv_provider, sizeof(mkv_provider_codecinfo), KAL_TRUE);		
        pr_mkv_provider->paFrameInfo[SOURCE_PROVIDER_PORT_SUBTITLE] = _mkv_mem_alloc(pr_mkv_provider, sizeof(SPIF_PROVIDER_FRAME_INFO_T), KAL_TRUE);    
    }
#endif	

#ifdef __MKV_PROVIDER_DEBUG__
    mkv_memalloc_index_after_open = mkv_memalloc_index;
    mkv_memalloc_size_after_open = mkv_memalloc_totalsize;
#endif

    MKV_STOP_LOGGING("MKO");

    return PROVIDER_ERROR_NONE;

}

/*****************************************************************************
 * FUNCTION
 *    MKVProviderClose
 * DESCRIPTION
 *  This function is used to close RM provider.
 *  1) Release resource
 * PARAMETERS
 *  param1 : [IN]  void *pvHandle
 *                 The MKV provider handler.
 * RETURNS
 *  return value description.
 *
 ****************************************************************************/
static PROVIDER_ERROR_T MKVProviderClose(void *pvHandle)
{
    return PROVIDER_ERROR_NONE;
}

static PROVIDER_ERROR_T MKVProviderInit(void *pvHandle)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    kal_bool result = KAL_TRUE; //seek result		
    kal_uint32 u4KeyframeTime;    
    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;
    kal_uint32 index;

    for(index = 0; index < MKV_TRACK_COUNT; index++)
    {
        pr_mkv_provider->fgTrackEOF[index] = KAL_FALSE;
        //seek video/audio/subtitle parser	 
        if(pr_mkv_provider->u2StreamCount[index] > 0 && pr_mkv_provider->paFileHandle[index])
        {
            result = mkv_parser_seek(pr_mkv_provider->mkvparser, pr_mkv_provider->paFileHandle[index]->prFileHandle, 0, &u4KeyframeTime, pr_mkv_provider->paCluster[index], KAL_TRUE);		   
            if(KAL_FALSE == result)
            {
                err = PROVIDER_ERROR;				
            }		
        }		
    }
 
    return err;
}

/*****************************************************************************
 * FUNCTION
 *    MKVProviderDeInit
 * DESCRIPTION
 *  This function is used to deinit MKV provider.
 *  Do nothing.
 * PARAMETERS
 *  param1 : [IN]  void *pvHandle
 *                 The MKV provider handler.
 * RETURNS
 *  return value description.
 ****************************************************************************/
static PROVIDER_ERROR_T MKVProviderDeInit(void *pvHandle)
{
    return PROVIDER_ERROR_NONE;
}
/*****************************************************************************
 * FUNCTION
 *    MKVProviderGetParameter
 * DESCRIPTION
 *  This function is used to get MKV provider parameter.
 *  Do nothing.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 ****************************************************************************/
static PROVIDER_ERROR_T MKVProviderGetParameter(void *pvHandle, PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;

    switch (eCmd)
    {
        case PROVIDER_PARAM_VID_STREAM_INFO:
        {
            SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
            if (pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO] > 0)
            {
                prStreamInfo->fgSupport = KAL_TRUE;
                prStreamInfo->u4Num = pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_VIDEO];
                prStreamInfo->pvStreamInfo = pr_mkv_provider->video_stream_info;
            }
            else
            {
                prStreamInfo->fgSupport = KAL_FALSE;
            }		
        }			
            break;			
        case PROVIDER_PARAM_AUD_STREAM_INFO:
        {			
            SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
            if (pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO] > 0)
            {
                prStreamInfo->fgSupport = KAL_TRUE;
                prStreamInfo->u4Num = pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_AUDIO];
                prStreamInfo->pvStreamInfo = pr_mkv_provider->audio_stream_info;
            }
            else
            {
                prStreamInfo->fgSupport = KAL_FALSE;
            }			
        }			
            break;
#ifdef __VE_SUBTITLE_SUPPORT__			
        case PROVIDER_PARAM_SUBS_STREAM_INFO:
        {			
            SPIF_STREAM_INFO_T *prStreamInfo = (SPIF_STREAM_INFO_T *)pParam;
            if (pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE] > 0)
            {
                prStreamInfo->fgSupport = KAL_TRUE;
                prStreamInfo->u4Num = pr_mkv_provider->u2StreamCount[SOURCE_PROVIDER_PORT_SUBTITLE];
		prStreamInfo->pvStreamInfo = pr_mkv_provider->subtitle_stream_info;
            }
            else
            {
                prStreamInfo->fgSupport = KAL_FALSE;
            }			
        }			
            break;			
#endif			
#ifdef __VE_MOT_CATEGORY__ 
        case PROVIDER_PARAM_META_DATA:
        {
            SPIF_META_DATA_T *prMetaData = (SPIF_META_DATA_T *)pParam;
            MKV_MIMETYPE_T eThumbType;

            mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_TITLE,prMetaData->pu2Title,prMetaData->u2TitleLen, NULL);
            mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_ARTIST,prMetaData->pu2Artist,prMetaData->u2ArtistLen, NULL);
            mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_DATE,prMetaData->pu2Date,prMetaData->u2DateLen, NULL);
            mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_ANNOTATION,prMetaData->pu2Annotation,prMetaData->u4AnnotationLen, NULL);
            mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_TYPE,prMetaData->pu2Type,prMetaData->u2TypeLen, NULL);			
            mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_THUMB,prMetaData->pu1ThumbnailData,prMetaData->u4ThumbnailDataAllocatedLen, &prMetaData->u4ThumbnailDataUsagedLen);
            if(prMetaData->u4ThumbnailDataUsagedLen > 0)
            {
                mkv_parser_get_meta(pr_mkv_provider->mkvparser, MKV_META_THUMBTYPE, &eThumbType, NULL, NULL);	
                switch(eThumbType)
                {
                    case MKV_MIMETYPE_JPEG:
                        prMetaData->eThumbnailType = SOURCE_PROVIDER_THUMBNAIL_JPG;
                        break;
                    case MKV_MIMETYPE_PNG:
                        prMetaData->eThumbnailType = SOURCE_PROVIDER_THUMBNAIL_PNG;					
                        break;
#if 0
/* under construction !*/
/* under construction !*/
#endif
                }
            }
	
        }
            break;
#endif			
        case PROVIDER_PARAM_META_CAPABILITY:
        {
            SP_CAPABILITY_T *prCap = (SP_CAPABILITY_T *)pParam;
            *prCap = SOURCE_PROVIDER_SEEK;
        }
            break;
        case PROVIDER_PARAM_KEY_FRAME_TIME:
        {
            SPIF_KEY_FRAME_TIME_T *prKeyFrameTime = (SPIF_KEY_FRAME_TIME_T *)pParam;
            kal_uint16 u2SeekStream = 0;
            kal_uint32 u4KeyFrameTime;
            MKV_TRACKTYPE_T eTracktype = MKV_TRACKTYPE_NONE;

            prKeyFrameTime->u8KeyFrameTime = 0;

            if(prKeyFrameTime->u8StartTime == 0)
            {
                break;
            }
			
            if(SOURCE_PROVIDER_PORT_AUDIO == prKeyFrameTime->ePort)
            {
                eTracktype = MKV_TRACKTYPE_AUDIO;
            }
            else if(SOURCE_PROVIDER_PORT_VIDEO == prKeyFrameTime->ePort)
            {
                eTracktype = MKV_TRACKTYPE_VIDEO;
            }
#ifdef __VE_SUBTITLE_SUPPORT__			
            else if(SOURCE_PROVIDER_PORT_SUBTITLE == prKeyFrameTime->ePort)
            {
                eTracktype = MKV_TRACKTYPE_SUBTITLE;				
            }
#endif			
#ifdef __MKV_PROVIDER_DEBUG__	
            else
            {
                err = PROVIDER_ERROR;
                break;
            }
#endif

            u2SeekStream = pr_mkv_provider->u2StreamIdx[prKeyFrameTime->ePort];

            if (prKeyFrameTime->eDirect == SOURCE_PROVIDER_SEARCH_BACKWARD)
            {
                if(mkv_parser_get_keyframe_time(pr_mkv_provider->mkvparser, u2SeekStream, (kal_uint32)prKeyFrameTime->u8StartTime, &u4KeyFrameTime, eTracktype, &(pr_mkv_provider->fgAbort[prKeyFrameTime->ePort])) == KAL_FALSE)
                {
                    err = PROVIDER_ERROR;
                }
                prKeyFrameTime->u8KeyFrameTime = u4KeyFrameTime;
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_QUERYTIME, (kal_uint32)prKeyFrameTime->u8StartTime);
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_KEYFRAMETIME, (kal_uint32)prKeyFrameTime->u8KeyFrameTime);				
                MKV_TRACE4(TRACE_GROUP_2, MKVPROVIDER_GET_KEYFRAMETIME, prKeyFrameTime->ePort, (kal_uint32)prKeyFrameTime->u8StartTime, (kal_uint32)prKeyFrameTime->u8KeyFrameTime, 0); 
            }
            else
            {   /* search the key frame newer than "time", ie. SOURCE_PROVIDER_SEARCH_FORWARD*/
                err = PROVIDER_ERROR;
            }			
        }
            break;
        case PROVIDER_PARAM_DRM_FSAL:
            pParam = pr_mkv_provider->mkv_file_handle->prFileHandle;
            break;    
#ifdef __VE_3D_SIDE_BY_SIDE__
        case PROVIDER_PARAM_3D_SBS:
        {
            kal_bool *pfg3DSBS = (kal_bool *)pParam;
            kal_uint32 u4StereoMode = 0;
            mkv_parser_track* pTrack = pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_VIDEO]->pTrack;

            if(NULL == pTrack)
            {
                ASSERT(0);
            }
            u4StereoMode = pTrack->VideoInfo->u4StereoMode;
            if(u4StereoMode == 1 || u4StereoMode == 11)
            {
                *pfg3DSBS = KAL_TRUE;
            }
		}
            break;
#endif
        case PROVIDER_PARAM_HEADER_INFO:
        {
            SPIF_PROVIDER_HEADER_INFO_T *prHeaderInfo = (SPIF_PROVIDER_HEADER_INFO_T *)pParam;			
            media_codec_type_t eCodecType = pr_mkv_provider->paCodecInfo[prHeaderInfo->eType]->eCodecType;			

            prHeaderInfo->fgHeader = _mkv_IsNeedheader(eCodecType);            
        }
            break;
        default:
        {
            //ASSERT(0);
            err = PROVIDER_ERROR;
        }
            break;
    }
    return err;

}

/*****************************************************************************
 * FUNCTION
 *    MKVProviderSetParameter
 * DESCRIPTION
 *  This function is used to set RM provider parameter.
 *  Do nothing.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 ****************************************************************************/
static PROVIDER_ERROR_T MKVProviderSetParameter(void *pvHandle, PROVIDER_PARAM_TYPE_T eCmd, void * pParam)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;

    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;
    mkv_parser* prMkvParser = pr_mkv_provider->mkvparser;

    switch (eCmd)
    {
        case PROVIDER_PARAM_SEEK_TIME:
        {
            SPIF_SEEK_TIME_T *prSeekTime = (SPIF_SEEK_TIME_T *)pParam;			
            kal_uint32 u4KeyframeTime;
            kal_bool result; //seek result			
            SP_PORT_TYPE_T eTrackType = prSeekTime->eType;
            MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_SET_SEEKTIME, eTrackType, prSeekTime->u8StartTime);			 

            pr_mkv_provider->fgTrackEOF[eTrackType] = KAL_FALSE;
            pr_mkv_provider->u4StartTime[eTrackType] = (kal_uint32)prSeekTime->u8StartTime;            
            pr_mkv_provider->u4StopTime[eTrackType] = (kal_uint32)prSeekTime->u8EndTime;				

			
            if(SOURCE_PROVIDER_PORT_VIDEO == prSeekTime->eType)			
            {
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_SET_VIDEO_SEEKTIME, pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_VIDEO]);

                result = mkv_parser_get_keyframe_time(prMkvParser, pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_VIDEO], pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_VIDEO], &u4KeyframeTime, MKV_TRACKTYPE_VIDEO, &(pr_mkv_provider->fgAbort[SOURCE_PROVIDER_PORT_VIDEO]));
                if(result)
                {
                    pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_VIDEO] = u4KeyframeTime;                
                    if(KAL_FALSE == mkv_parser_seek(prMkvParser, pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_VIDEO]->prFileHandle, pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_VIDEO], &u4KeyframeTime, pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_VIDEO], KAL_FALSE))
                    {
                        err = PROVIDER_ERROR;				                    
                    }					
                }
                else
                {
                    err = PROVIDER_ERROR;				
                }
            }
            else if(SOURCE_PROVIDER_PORT_AUDIO == prSeekTime->eType)
            {
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_SET_AUDIO_SEEKTIME, pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_AUDIO]);				
                result = mkv_parser_seek(prMkvParser, pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_AUDIO]->prFileHandle, pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_AUDIO], &u4KeyframeTime, pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_AUDIO], (pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_AUDIO] <= pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_AUDIO])?KAL_TRUE:KAL_FALSE);
                if(KAL_FALSE == result)
                {
                    err = PROVIDER_ERROR;				
                }															
            }	
#ifdef __VE_SUBTITLE_SUPPORT__			
            else if(SOURCE_PROVIDER_PORT_SUBTITLE== prSeekTime->eType)
            {
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_SET_SUBTITLE_SEEKTIME, pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_SUBTITLE]);				
                result = mkv_parser_seek(prMkvParser, pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_SUBTITLE]->prFileHandle, pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_SUBTITLE], &u4KeyframeTime, pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_SUBTITLE], (pr_mkv_provider->u4StartTime[SOURCE_PROVIDER_PORT_SUBTITLE] <= pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_SUBTITLE])? KAL_TRUE:KAL_FALSE);
                if(KAL_FALSE == result)
                {
                    err = PROVIDER_ERROR;				
                }				
			
                if(pr_mkv_provider->subtitle_duration_frame)
                {
                   _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->subtitle_duration_frame);	
                }				
            }	
#endif			
            else
            {
                ASSERT(0);            
            }	
			
            pr_mkv_provider->u4Timestamp[eTrackType] = pr_mkv_provider->u4StartTime[eTrackType];
            if(pr_mkv_provider->paFrameInfo[eTrackType]->pu1Payload)
            {
                _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paFrameInfo[eTrackType]->pu1Payload);
            }
            kal_mem_set(pr_mkv_provider->paFrameInfo[eTrackType], 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));				
            if(pr_mkv_provider->paBlock[eTrackType])
            {
                if(pr_mkv_provider->paBlock[eTrackType]->u4FrameLen)
                {
                    _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paBlock[eTrackType]->u4FrameLen);	
                }
                    _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paBlock[eTrackType]);	
            }			
        }
            break;    
        case PROVIDER_PARAM_SELECT_STREAM:
        {
            SPIF_STREAM_T *prStream = (SPIF_STREAM_T *)pParam;
			
            mkv_provider_codecinfo* pCodecInfo = pr_mkv_provider->paCodecInfo[prStream->eType];
            pr_mkv_provider->u2StreamIdx[prStream->eType] = prStream->u1Track;
            /* parsing codec private */
            prSrcAPI->SPFN_MEM_SET(pCodecInfo, 0, sizeof(mkv_provider_codecinfo));            			
            _mkv_parse_codec_specific_data(pr_mkv_provider, pr_mkv_provider->u2StreamIdx[prStream->eType], pCodecInfo);

			
            if(SOURCE_PROVIDER_PORT_VIDEO == prStream->eType)
            {			
                mkv_parser_select_track(prMkvParser, MKV_TRACKTYPE_VIDEO, prStream->u1Track, KAL_TRUE);
            }
            else if(SOURCE_PROVIDER_PORT_AUDIO == prStream->eType)
            {						
                mkv_parser_select_track(prMkvParser, MKV_TRACKTYPE_AUDIO, prStream->u1Track, KAL_TRUE);				
            }					
#ifdef __VE_SUBTITLE_SUPPORT__			
            else if(SOURCE_PROVIDER_PORT_SUBTITLE== prStream->eType)
            {			
                mkv_parser_select_track(prMkvParser, MKV_TRACKTYPE_SUBTITLE, prStream->u1Track, KAL_TRUE);								
            }			
#endif			
#ifndef __MKV_SLIM__
            else
            {
                ASSERT(0);            
            }
#endif			

        }
            break;
        case PROVIDER_PARAM_DESELECT_STREAM:
        {
            SPIF_STREAM_T *prStream = (SPIF_STREAM_T *)pParam;
            pr_mkv_provider->u2StreamIdx[prStream->eType] = 0;			
			
            if(SOURCE_PROVIDER_PORT_VIDEO == prStream->eType)
            {
                mkv_parser_select_track(prMkvParser, MKV_TRACKTYPE_VIDEO, 0, KAL_FALSE);
            }
            else if(SOURCE_PROVIDER_PORT_AUDIO == prStream->eType)
            {
                mkv_parser_select_track(prMkvParser, MKV_TRACKTYPE_AUDIO, 0, KAL_FALSE);				
            }					
#ifdef __VE_SUBTITLE_SUPPORT__			
            else if(SOURCE_PROVIDER_PORT_SUBTITLE== prStream->eType)
            {
                mkv_parser_select_track(prMkvParser, MKV_TRACKTYPE_SUBTITLE, 0, KAL_FALSE);								
            }			
#endif			
#ifndef __MKV_SLIM__
            else
            {
                ASSERT(0);            
            }			
#endif			
        }
            break;
                       
        case PROVIDER_PARAM_SEND_HEADER:
        {
            SPIF_SNED_HEADER_T *prSendHeader = (SPIF_SNED_HEADER_T *)pParam;

            if (prSendHeader->fgVideo == KAL_TRUE && pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_VIDEO] != 0)
            {
                pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_VIDEO]->fgSendHeader = KAL_FALSE;                
            }
            if (prSendHeader->fgAudio== KAL_TRUE && pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_AUDIO] != 0)
            {
                pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_AUDIO]->fgSendHeader = KAL_FALSE;
            }
#ifdef __VE_SUBTITLE_SUPPORT__			
#ifdef __MKV_SUBTITLE_HEADER__
            if (prSendHeader->fgSubtitle== KAL_TRUE && pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE] != 0)
            {
                pr_mkv_provider->paCodecInfo[SOURCE_PROVIDER_PORT_SUBTITLE]->fgSendHeader = KAL_FALSE;                
            }			
#endif //__MKV_SUBTITLE_HEADER__			
#endif			
        }						
            break;           
        case PROVIDER_PARAM_QUICK_CLOSE:
            pr_mkv_provider->fgTerminate = KAL_TRUE;
            break;    

        case PROVIDER_PARAM_ABORT_PROCESS:
            {
                SPIF_ABORT_INFO_T *prAbort = (SPIF_ABORT_INFO_T *)pParam;			
                pr_mkv_provider->fgAbort[prAbort->eType] = prAbort->fgEnable;
            }
            break;
        default:
        {
            //ASSERT(0);
            err = PROVIDER_ERROR;
        }
            break;
    }
    return err;
		
}


static PROVIDER_ERROR_T MKVProviderParseData(void *pvHandle,SP_PORT_TYPE_T eTrackType, kal_uint32 *pu4Time)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;
    void *pvSrcHandle = pr_mkv_provider->pvSourceHandle;

    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;
    MKV_PARSER_ERROR_T result = MKV_PARSER_ERROR_NONE;

    kal_uint32 u4Timestamp = pr_mkv_provider->u4Timestamp[eTrackType];
    SPIF_PROVIDER_FRAME_INFO_T* pFrameInfo = pr_mkv_provider->paFrameInfo[eTrackType];
    mkv_parser* prMkvParser = pr_mkv_provider->mkvparser;

    if(pr_mkv_provider->paBlock[eTrackType] != NULL)
    {
        if(KAL_FALSE == _mkv_deliver(pr_mkv_provider, pr_mkv_provider->paBlock[eTrackType]))
        {
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
        else
        {
            _mkv_seek(pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, pr_mkv_provider->paCluster[eTrackType]->u4ClusterBase + pr_mkv_provider->paCluster[eTrackType]->u4Offset,MKV_SEEK_START);
        }		
    }  

    if(pFrameInfo->u4FrameSize > 0)	
    {
//        MKV_TRACE2(TRACE_GROUP_2, MKVPROVIDER_MSG, __LINE__, pFrameInfo->u4FrameSize);    
        if(prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, pFrameInfo) != PROVIDER_ERROR_NONE)
        {
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }			
        else
        {
            pFrameInfo->u4FrameSize = 0;
            pr_mkv_provider->u4Timestamp[eTrackType] = pFrameInfo->u8Timestamp;			

            if(pFrameInfo->pu1Payload)		
            {
                _mkv_mem_free(pr_mkv_provider, (void**)&pFrameInfo->pu1Payload);        
            }
        }
    }

#ifdef __VE_SUBTITLE_SUPPORT__		
    /* for subtitle duration */
    if(SOURCE_PROVIDER_PORT_SUBTITLE == eTrackType && pr_mkv_provider->subtitle_duration_frame != NULL)
    {
        pr_mkv_provider->subtitle_duration_frame->u8Timestamp += pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_SUBTITLE];
        if(prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, pr_mkv_provider->subtitle_duration_frame) != PROVIDER_ERROR_NONE)
        {              
            return PROVIDER_ERROR_WAIT_RESOURCE;
        }
        else
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->subtitle_duration_frame);        
        }
    }  
#endif	// __VE_SUBTITLE_SUPPORT__
	
    if(KAL_FALSE == pr_mkv_provider->fgTrackEOF[eTrackType])
    {
        MKV_TRACE4(TRACE_GROUP_2, MKVPROVIDER_PARSE, pr_mkv_provider->u2StreamIdx[eTrackType], pr_mkv_provider->u4Timestamp[eTrackType], pr_mkv_provider->u4PacketGet[eTrackType], pr_mkv_provider->paCluster[eTrackType]->u4Offset);    
    
        result = mkv_parser_demux(prMkvParser, pr_mkv_provider->u2StreamIdx[eTrackType], pr_mkv_provider->paFileHandle[eTrackType]->prFileHandle, pr_mkv_provider->paCluster[eTrackType]);
        /* pr_mkv_provider->u4Timestamp[eTrackType] may change in  _mkv_deliver of mkv_parser_demux*/	
    
    	pr_mkv_provider->u4PacketGet[eTrackType]++;
    
        if(pr_mkv_provider->u4Timestamp[eTrackType] > u4Timestamp)	
        {
            *pu4Time = pr_mkv_provider->u4Timestamp[eTrackType] - u4Timestamp;
        }
    }
    
    if(MKV_PARSER_ERROR_NONE != result || pr_mkv_provider->fgTrackEOF[eTrackType])
    {   
        if(MKV_PARSER_ERROR_EOF == result)
        {
            pr_mkv_provider->fgTrackEOF[eTrackType] = KAL_TRUE;
        }
    
        kal_mem_set(pFrameInfo, 0, sizeof(SPIF_PROVIDER_FRAME_INFO_T));
        // select the small one as eof timestamp from: 1) current timestamp; 2) file duration; 3)stoptime		
        pFrameInfo->u8Timestamp = pr_mkv_provider->u4Timestamp[eTrackType];
        if(SOURCE_PROVIDER_PORT_VIDEO == eTrackType && pr_mkv_provider->video_stream_info->u4Fps > 0)
        {
            pFrameInfo->u8Timestamp += (100000/pr_mkv_provider->video_stream_info->u4Fps);
        }
        if(prMkvParser->u4Duration < pFrameInfo->u8Timestamp)
        {
            pFrameInfo->u8Timestamp = prMkvParser->u4Duration;
        }
        if(pr_mkv_provider->u4StopTime[eTrackType] < pFrameInfo->u8Timestamp)
        {
            pFrameInfo->u8Timestamp = pr_mkv_provider->u4StopTime[eTrackType];
        }
        pFrameInfo->fgEof = KAL_TRUE;
    
        if (prSrcAPI->SPFN_ADD_ONE_DATA(pvSrcHandle, eTrackType, pFrameInfo) != PROVIDER_ERROR_NONE)
        {
            err = PROVIDER_ERROR_WAIT_RESOURCE;
        }
        else
        {
            if(MKV_PARSER_ERROR_EOF == result || pr_mkv_provider->fgTrackEOF[eTrackType])
            {
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_EOF, (kal_uint32)eTrackType);																
                err = PROVIDER_ERROR_EOF;
            }
            else if(MKV_PARSER_ERROR_CORRUPT == result) 
            {
                video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_ERROR_LINE, __LINE__);
                err = PROVIDER_ERROR_DELAY_REPORT_WITH_EOF; 		   
            }
        }		 
    }

    return err;
}


static PROVIDER_ERROR_T MKVProviderParseVideo(void *pvHandle, kal_uint32 *pu4Time)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;
	
    *pu4Time = 100;  //default value

    MKV_START_LOGGING("MKV");

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_PARSE_VIDEO, pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_VIDEO]);
    err = MKVProviderParseData(pvHandle, SOURCE_PROVIDER_PORT_VIDEO, pu4Time);

    MKV_STOP_LOGGING("MKV");

    return err;
}

static PROVIDER_ERROR_T MKVProviderParseAudio(void *pvHandle, kal_uint32 *pu4Time)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;
	
    *pu4Time = 1;  //default value

    MKV_START_LOGGING("MKA");

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_PARSE_AUDIO, pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_AUDIO]);
    err = MKVProviderParseData(pvHandle, SOURCE_PROVIDER_PORT_AUDIO, pu4Time);
	
    MKV_STOP_LOGGING("MKA");

    return err;
}

#ifdef __VE_SUBTITLE_SUPPORT__
static PROVIDER_ERROR_T MKVProviderParseSubtitle(void *pvHandle, kal_uint32 *pu4Time)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;
    PROVIDER_ERROR_T err = PROVIDER_ERROR_NONE;

#ifdef __MKV_PROVIDER_PROFILE__

    if(video_get_duration_ms(u4mkvparserprofiletime) > 500)
    {
        u4mkvparserprofiletime = video_get_current_time(); 
        MKV_TRACE8(TRACE_GROUP_2, MKVPROVIDER_PROFILE, (kal_uint32)pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_VIDEO], (kal_uint32)pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_AUDIO], (kal_uint32)pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_SUBTITLE], (kal_uint32)pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_VIDEO]->u4TimeCode, (kal_uint32)pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_AUDIO]->u4TimeCode, (kal_uint32)pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_SUBTITLE]->u4TimeCode, 0, 0);

    }
#endif

    if(pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_AUDIO])
    {
        if(pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_SUBTITLE]->u4ClusterBase > pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_AUDIO]->u4ClusterBase)
        {
            *pu4Time = 600;  
            return err;
        }
    }
    else if(pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_VIDEO])
    {
        if(pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_SUBTITLE]->u4ClusterBase > pr_mkv_provider->paCluster[SOURCE_PROVIDER_PORT_VIDEO]->u4ClusterBase)
        {
            *pu4Time = 600;  
            return err;
        }
    }

    *pu4Time = 100;  //default value

    MKV_START_LOGGING("MKS");		

    video_dbg_trace(VIDEO_DBG_OWNER_FILEREADER, VIDEO_DBG_MKVPROVIDER_PARSE_SUBTITLE, pr_mkv_provider->u4Timestamp[SOURCE_PROVIDER_PORT_SUBTITLE]);	
    err = MKVProviderParseData(pvHandle, SOURCE_PROVIDER_PORT_SUBTITLE, pu4Time);

    MKV_STOP_LOGGING("MKS");

    return err;	
}
#endif


/*****************************************************************************
 * Interface API
 ****************************************************************************/
 static const PROVIDER_API_T rMKVProviderAPI =
{
    MKVProviderOpen,
    MKVProviderClose,
    MKVProviderInit,
    MKVProviderDeInit,
    MKVProviderGetParameter,
    MKVProviderSetParameter,
    MKVProviderParseVideo,
    MKVProviderParseAudio
#ifdef __VE_SUBTITLE_SUPPORT__
    ,MKVProviderParseSubtitle
#endif
};
/*****************************************************************************
 * FUNCTION
 *    MKVProviderGetHandle
 * DESCRIPTION
 *  This function is used to get RM handle.
 *  Create RM control structure  (allocate memory from core)
 *  Set source component handle, source handle function (callback functions, common resource functions) to rm provider
 *  Create RM handle (allocate memory from core)
 *  Get events and mutexs
 *  Return RM provide handle and RM provider APIs
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 ****************************************************************************/
PROVIDER_ERROR_T MKVProviderGetHandle(void *pvSrcHandle, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider;
#ifdef __MKV_MEMORY_CHECK__
    mkv_memalloc_count = 0;
#endif
	
#ifdef __MKV_PROVIDER_UT__
    initmemory();
    pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T *)getmemory(sizeof(MKV_SP_PROVIDER_CONTEXT_T));
#else
    pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T *)prSrcAPI->SPFN_MALLOC_CLA(pvSrcHandle, sizeof(MKV_SP_PROVIDER_CONTEXT_T), KAL_TRUE);
    prSrcAPI->SPFN_MEM_SET(pr_mkv_provider, 0, sizeof(MKV_SP_PROVIDER_CONTEXT_T));
#endif
    // Set source component handle, source handle function
    pr_mkv_provider->pvSourceHandle = pvSrcHandle;
    pr_mkv_provider->prSourceAPI = prSrcAPI;

    // Create MKV handle
    pr_mkv_provider->rMKVProviderAPI = (PROVIDER_API_T *)&rMKVProviderAPI;

    // Return MKV provide handle and MKV provider APIs
#ifndef __MKV_PROVIDER_UT__
    prPrvHdlr->pvHandle = (void *)pr_mkv_provider;
    prPrvHdlr->prAPI = pr_mkv_provider->rMKVProviderAPI;
#endif

#ifdef __MKV_PROVIDER_UT__
    {
        SPIF_PROVIDER_OPEN_INFO_T Fileinfo;
        SPIF_META_DATA_T *prMetaData;
        kal_uint32 u4Time;
        kal_uint32 index;
        kal_uint32 u4KeyframeTime;

        Fileinfo.pu1Data = (kal_uint8 *)filename;
        Fileinfo .u4DataSize = wcslen(filename);
        pr_mkv_provider->rMKVProviderAPI->PFN_OPEN(NULL, &Fileinfo);
        pr_mkv_provider->rMKVProviderAPI->PFN_INIT(NULL);
        pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_VIDEO] = 1;
        pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_AUDIO] = 2;//10;
        pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_SUBTITLE] = 3;

        mkv_parser_seek(pr_mkv_provider->mkvparser, pr_mkv_provider->paFileHandle[SOURCE_PROVIDER_PORT_VIDEO]->prFileHandle, 0, &u4KeyframeTime, NULL, KAL_TRUE);
        mkv_parser_get_keyframe_time(pr_mkv_provider->mkvparser, pr_mkv_provider->u2StreamIdx[SOURCE_PROVIDER_PORT_VIDEO], 6666, &u4KeyframeTime, MKV_TRACKTYPE_VIDEO, &(pr_mkv_provider->fgAbort[SOURCE_PROVIDER_PORT_VIDEO]));

        for(index = 500; index>0;index--)
        {
            pr_mkv_provider->rMKVProviderAPI->PFN_PARSE_VIDEO(NULL, &u4Time);
            pr_mkv_provider->rMKVProviderAPI->PFN_PARSE_SUBTITLE(NULL, &u4Time);
            pr_mkv_provider->rMKVProviderAPI->PFN_PARSE_AUDIO(NULL, &u4Time);
        }
        ASSERT(index == 0);

    }
#endif

    if(NULL == g_mkv_provider[0])
    {
        g_mkv_provider[0] = pr_mkv_provider;
    }
    else
    {
        g_mkv_provider[1] = pr_mkv_provider;    
    }

    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *    MKVProviderReleaseHandle
 * DESCRIPTION
 *  This function is used to release MKV handle.
 * PARAMETERS
 *  param1 : [IN]  void* pvHandle
 *                 The MKV provider handler.
 * RETURNS
 *  return value.
 *
 ****************************************************************************/
PROVIDER_ERROR_T MKVProviderReleaseHandle(void* pvHandle)
{
    MKV_SP_PROVIDER_CONTEXT_T* pr_mkv_provider = (MKV_SP_PROVIDER_CONTEXT_T*)pvHandle;

    SP_API_T *prSrcAPI = pr_mkv_provider->prSourceAPI;
    void *pvSrcHandle = pr_mkv_provider->pvSourceHandle;

    kal_uint32 index;

    if(pr_mkv_provider->mkv_file_handle->prFileHandle)
    {
        FSAL_Close(pr_mkv_provider->mkv_file_handle->prFileHandle);

        if(pr_mkv_provider->mkv_file_handle->pu1SetBuf)
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->mkv_file_handle->pu1SetBuf);
        }
        if(pr_mkv_provider->mkv_file_handle->prSeekHint)
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->mkv_file_handle->prSeekHint);
        }		
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->mkv_file_handle->prFileHandle);
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->mkv_file_handle);		  
    }

    for(index = 0; index < MKV_TRACK_COUNT ;index++)
    {
        if(pr_mkv_provider->paFileHandle[index])
        {
            FSAL_Close(pr_mkv_provider->paFileHandle[index]->prFileHandle);
    
            if(pr_mkv_provider->paFileHandle[index]->pu1SetBuf)
            {
                _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paFileHandle[index]->pu1SetBuf);
            }
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paFileHandle[index]->prFileHandle);
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paFileHandle[index]);		  
        }		
        if(pr_mkv_provider->paCodecInfo[index])	
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paCodecInfo[index]);        
        }	
        if(pr_mkv_provider->paCluster[index])	
        {
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paCluster[index]);            
        }	
        if(pr_mkv_provider->paFrameInfo[index])
        {
            if(pr_mkv_provider->paFrameInfo[index]->pu1Payload)		
            {
                _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paFrameInfo[index]->pu1Payload); 	   
            }
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paFrameInfo[index]);
        }	
        if(pr_mkv_provider->paBlock[index])
        {
            if(pr_mkv_provider->paBlock[index]->u4FrameLen)
            {
                _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paBlock[index]->u4FrameLen);
            }
            _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->paBlock[index]);
        }
    }
    if(pr_mkv_provider->video_stream_info)
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->video_stream_info);
    }	
    if(pr_mkv_provider->audio_stream_info)
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->audio_stream_info);
    }	
	
#ifdef __VE_SUBTITLE_SUPPORT__	
#ifdef __MKV_MAUI_03155540
    if(pr_mkv_provider->pu1SSA_style)
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->pu1SSA_style);    
    }
#endif
    if(pr_mkv_provider->subtitle_stream_info)
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->subtitle_stream_info);
    }	

    if(pr_mkv_provider->subtitle_duration_frame)
    {
       _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->subtitle_duration_frame);	
    }
#endif	

    if(pr_mkv_provider->pTrackInfo)
    {
        _mkv_mem_free(pr_mkv_provider, (void**)&pr_mkv_provider->pTrackInfo);
    }	

    if(pr_mkv_provider->mkvparser)
    {
        mkv_parser_close(pr_mkv_provider->mkvparser);
    }

    prSrcAPI->SPFN_FREE_CLA(pvSrcHandle, pr_mkv_provider);

#ifdef __MKV_PROVIDER_DEBUG__ 
	ASSERT(mkv_memalloc_totalsize == 0);
#endif
#ifdef __MKV_MEMORY_CHECK__
    ASSERT(mkv_memalloc_count == 0);
#endif

    if(pvHandle == g_mkv_provider[0])
    {
        g_mkv_provider[0] = NULL;
    }
    else
    {
        g_mkv_provider[1] = NULL;    
    }
	
    return PROVIDER_ERROR_NONE;
}

/*****************************************************************************
 * FUNCTION
 *    MKVProviderCheckIntegrity
 * DESCRIPTION
 *  This function is used to check whether the file is RMFF.
 * PARAMETERS
 *  param1 : [IN]  kal_uint8* pBuf
 *                 The data buffer use to parsing.
 *  param2 : [IN]  kal_uint32 ulSize
 *                 The data size use to parsing.
 * RETURNS
 *  return value description.
 ****************************************************************************/
kal_bool MKVProviderCheckIntegrity(kal_uint8* pBuf, kal_uint32 ulSize)
{
    kal_bool result = KAL_FALSE;
    if(ulSize >= 4)
    {
        result =  mkv_parser_check_ebml(pBuf);
    }
    return result;
}

#endif //__VE_MKV_FILE_FORMAT_SUPPORT__
