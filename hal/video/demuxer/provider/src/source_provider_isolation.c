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
 *   source_provider_isolation.c
 *
 * Project:
 * --------
 *	MTK
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
 *
 ****************************************************************************/

#include "drv_comm.h"
#ifdef __VE_SOURCE_PROVIDER__

#include "source_provider_component.h"
#include "media_provider_mem_usage.h"
#include "vcodec_v2_trc.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
#include "mp4_provider.h"
#endif

#ifdef __VE_SP_AVI__
#include "avi_provider.h"
#endif

#ifdef __VE_SP_RM__
extern PROVIDER_ERROR_T RMProviderGetHandle(void *pvSrcHandle, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr);
extern PROVIDER_ERROR_T RMProviderReleaseHandle(void* pvHandle);
extern kal_bool RMProviderCheckIntegrity(kal_uint8* pBuf, kal_uint32 ulSize);
#endif

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
#include "flv_provider.h"
#endif

#ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
#include "mkv_provider.h"
#endif
extern SP_API_T rAPIsForPrv;

#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
const SP_PARSER_PARAM_T rMP4ParserParam = {
    MP4_SP_VIDEO_MEM_SIZE/5, 16, 1024, 10, 500,
    1024,  0, 1024, 10, 500
    #ifdef __VE_SUBTITLE_SUPPORT__ 
    ,1024, 16, 1024, 10, 500
    #endif
    };
#endif

#ifdef __VE_SP_AVI__
const SP_PARSER_PARAM_T rAVIParserParam = {
    (AVI_SP_VIDEO_MEM_SIZE*4/5), 16, 1024, 10, 500,
    (AVI_SP_AUDIO_MEM_SIZE/5), 0, (AVI_SP_AUDIO_MEM_SIZE/10), 10, 500
    #ifdef __VE_SUBTITLE_SUPPORT__ 
    ,1024, 16, 1024, 10, 500
    #endif
    };
#endif

#ifdef __VE_SP_RM__
const SP_PARSER_PARAM_T rRMParserParam = {
    1024, 1280, 1024, 10, 500,
    1024, 0, 1024, 10, 500
    #ifdef __VE_SUBTITLE_SUPPORT__ 
    ,1024, 16, 1024, 10, 500
    #endif
    };
#endif

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
const SP_PARSER_PARAM_T rFLVParserParam = {
    FLV_SP_VIDEO_MEM_SIZE/5, 16, 1024, 10, 500,
    FLV_SP_AUDIO_MEM_SIZE/5, 0, 1024, 10, 500
    #ifdef __VE_SUBTITLE_SUPPORT__ 
    ,1024, 16, 1024, 10, 500
    #endif
    };
#endif

#ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
const SP_PARSER_PARAM_T rMKVParserParam = {
    1024, 16, 1024, 10, 500,
    1024, 0, (MKV_SP_AUDIO_MEM_SIZE/10), 10, 500    
    #ifdef __VE_SUBTITLE_SUPPORT__ 
    ,1024, 16, 0, 0, 500
    #endif
    };
#endif

#ifdef __VE_STREAM_SUPPORT__
const SP_PARSER_PARAM_T rStreamingParserParam = {
    (STREAMING_SP_VIDEO_MEM_SIZE>>1), 16, 0, 0, 0,
    (STREAMING_SP_AUDIO_MEM_SIZE>>1), 0, 0, 0, 0
    #ifdef __VE_SUBTITLE_SUPPORT__ 
    ,1024, 16, 0, 0, 0
    #endif
    };
#endif

SP_ERROR_TYPE_T _SourceProviderObtainProviderHandle(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr, SP_API_T* pAPIsForPrv)
{
    PROVIDER_ERROR_T rRet = PROVIDER_ERROR_NONE;
    SPIF_PROVIDER_HANDLE_T *prPrvHandle = &prSrcProviderMgr->rPrvHandle;
    
    switch (prSrcProviderMgr->rSrcInfo.eFileType)
    {
    #ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MP4:
        {
            rRet = MP4ProviderGetHandle((void *)prSrcProviderMgr, pAPIsForPrv, prPrvHandle);
        }
        break;
    #endif

    #ifdef __VE_SP_AVI__
    case SOURCE_PROVIDER_AVI:
        {
            rRet = AviProviderGetHandle((void *)prSrcProviderMgr, pAPIsForPrv, prPrvHandle);
        }
        break;
    #endif

    #ifdef __VE_SP_RM__
    case SOURCE_PROVIDER_RM:
        {            
            rRet = RMProviderGetHandle((void *)prSrcProviderMgr, pAPIsForPrv, prPrvHandle);
        }
        break;
    #endif

    #ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_FLV:
            rRet = FLVProviderGetHandle((void *)prSrcProviderMgr, pAPIsForPrv, prPrvHandle);
        break;
    #endif

#ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MKV:
            rRet = MKVProviderGetHandle((void *)prSrcProviderMgr, pAPIsForPrv, prPrvHandle);
        break;
#endif

    default:
        SP_TRACE_CONTAINER_TYPE_ERROR(prSrcProviderMgr->rSrcInfo.eFileType, 0, (kal_uint32)prSrcProviderMgr);
        rRet = PROVIDER_ERROR;
    }

    if (rRet == PROVIDER_ERROR_NONE)
    {
        return SOURCE_PROVIDER_ERROR_NONE;
    }
    else
    {
        return SOURCE_PROVIDER_ERROR;
    }
}

SP_ERROR_TYPE_T _SourceProviderReleaseProviderHandle(SRC_PRIVDER_CONTEXT_T *prSrcProviderMgr)
{
    PROVIDER_ERROR_T rRet = PROVIDER_ERROR_NONE;
    void *pvPrvHandle = prSrcProviderMgr->rPrvHandle.pvHandle;
    
    switch (prSrcProviderMgr->rSrcInfo.eFileType)
    {
    #ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MP4:
        {
            rRet = MP4ProviderReleaseHandle(pvPrvHandle);
        }
        break;
    #endif

    #ifdef __VE_SP_AVI__
    case SOURCE_PROVIDER_AVI:
        {
            rRet = AviProviderReleaseHandle(pvPrvHandle);
        }
        break;
    #endif

    #ifdef __VE_SP_RM__
    case SOURCE_PROVIDER_RM:
        {            
            rRet = RMProviderReleaseHandle(pvPrvHandle);
        }
        break;
    #endif
        
    #ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_FLV:
            rRet = FLVProviderReleaseHandle(pvPrvHandle);
        break;
    #endif

    #ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MKV:
            rRet = MKVProviderReleaseHandle(pvPrvHandle);
        break;	
    #endif

    default:
        SP_TRACE_CONTAINER_TYPE_ERROR(prSrcProviderMgr->rSrcInfo.eFileType, 0, (kal_uint32)prSrcProviderMgr);
        rRet = PROVIDER_ERROR;
    }

    if (rRet == PROVIDER_ERROR_NONE)
    {
        return SOURCE_PROVIDER_ERROR_NONE;
    }
    else
    {
        return SOURCE_PROVIDER_ERROR;
    }
}

SP_ERROR_TYPE_T _SourceProviderObtainMemInfo(SP_FILE_TYPE_T eFileType, SPIF_PROVIDER_MEM_INFO_T *prProviderMemInfo, med_mode_enum eOpenMode, SP_TRACK_T eTrack)
{
    kal_uint32 u4CoreMemSize, u4VideoMemSize, u4AudioMemSize;
#ifdef __VE_SUBTITLE_SUPPORT__
    kal_uint32 u4SubtitleMemSize;
#endif
    
    switch (eFileType)
    {
    #ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MP4:
        {  
            #ifdef __VE_SP_PREVIEW__
            if (eOpenMode == MED_MODE_PREVIEW
                #ifdef __VE_MOT_DECRYPTION__
                || eOpenMode == MED_MODE_MOT_PREVIEW
                #endif
				#ifdef __VE_KMV_SUPPORT__  //Gary, KMV
                || eOpenMode == MED_MODE_KMV_PREVIEW
                #endif
                )
            {
                u4CoreMemSize= MP4_SP_CORE_PREVIEW_MEM_SIZE + MP4_SP_VIDEO_WORKING_MEM_SIZE;
                u4VideoMemSize = MP4_SP_VIDEO_PREVIEW_MEM_SIZE;
                u4AudioMemSize = MP4_SP_AUDIO_PREVIEW_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = MP4_SP_SUBTITLE_PREVIEW_MEM_SIZE;
                #endif
            }
            else
            #endif
            {
                u4CoreMemSize = MP4_SP_CORE_MEM_SIZE;

                if(!(eTrack & SOURCE_PROVIDER_TRACK_META))
                {
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)?MP4_SP_AUDIO_WORKING_MEM_SIZE:0;
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)?MP4_SP_VIDEO_WORKING_MEM_SIZE:0;
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)?MP4_SP_SUBTITLE_WORKING_MEM_SIZE:0;
                    #endif
                }
                u4VideoMemSize = MP4_SP_VIDEO_MEM_SIZE;
                u4AudioMemSize = MP4_SP_AUDIO_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = MP4_SP_SUBTITLE_MEM_SIZE;
                #endif
            }
        }
        break;
    #endif        

    #ifdef __VE_SP_AVI__
    case SOURCE_PROVIDER_AVI:
        {
            #ifdef __VE_SP_PREVIEW__
            if (eOpenMode == MED_MODE_PREVIEW
                #ifdef __VE_MOT_DECRYPTION__
                || eOpenMode == MED_MODE_MOT_PREVIEW
                #endif
                )
            {
                u4CoreMemSize = AVI_SP_CORE_PREVIEW_MEM_SIZE + AVI_SP_VIDEO_WORKING_MEM_SIZE;
                u4VideoMemSize = AVI_SP_VIDEO_PREVIEW_MEM_SIZE;
                u4AudioMemSize = AVI_SP_AUDIO_PREVIEW_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = AVI_SP_SUBTITLE_PREVIEW_MEM_SIZE;
                #endif
            }
            else
            #endif
            {            
                u4CoreMemSize = AVI_SP_CORE_MEM_SIZE;

                if(!(eTrack & SOURCE_PROVIDER_TRACK_META))
                {
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)?AVI_SP_AUDIO_WORKING_MEM_SIZE:0;
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)?AVI_SP_VIDEO_WORKING_MEM_SIZE:0;
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)?AVI_SP_SUBTITLE_WORKING_MEM_SIZE:0;
                    #endif
                }
                u4VideoMemSize = AVI_SP_VIDEO_MEM_SIZE;
                u4AudioMemSize = AVI_SP_AUDIO_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = AVI_SP_SUBTITLE_MEM_SIZE;
                #endif
            }
        }
        break;
    #endif

    #ifdef __VE_SP_RM__
    case SOURCE_PROVIDER_RM:
        {
            #ifdef __VE_SP_PREVIEW__
            if (eOpenMode == MED_MODE_PREVIEW
                #ifdef __VE_MOT_DECRYPTION__
                || eOpenMode == MED_MODE_MOT_PREVIEW
                #endif
               )
            {
                u4CoreMemSize = RM_SP_CORE_PREVIEW_MEM_SIZE + RM_SP_VIDEO_WORKING_MEM_SIZE;
                u4VideoMemSize = RM_SP_VIDEO_PREVIEW_MEM_SIZE;
                u4AudioMemSize = RM_SP_AUDIO_PREVIEW_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = RM_SP_SUBTITLE_PREVIEW_MEM_SIZE;
                #endif
            }
            else
            #endif
            {             
                u4CoreMemSize = RM_SP_CORE_MEM_SIZE;
                
                if(!(eTrack & SOURCE_PROVIDER_TRACK_META))
                {
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)?RM_SP_AUDIO_WORKING_MEM_SIZE:0;
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)?RM_SP_VIDEO_WORKING_MEM_SIZE:0;
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)?RM_SP_SUBTITLE_WORKING_MEM_SIZE:0;
                    #endif
                }
                u4VideoMemSize = RM_SP_VIDEO_MEM_SIZE;
                u4AudioMemSize = RM_SP_AUDIO_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = RM_SP_SUBTITLE_MEM_SIZE;
                #endif
            }
        }
        break;
    #endif

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_FLV:
        {
            #ifdef __VE_SP_PREVIEW__
            if (eOpenMode == MED_MODE_PREVIEW
                #ifdef __VE_MOT_DECRYPTION__
                || eOpenMode == MED_MODE_MOT_PREVIEW
                #endif
               )
            {
                u4CoreMemSize = FLV_SP_CORE_PREVIEW_MEM_SIZE + FLV_SP_VIDEO_WORKING_MEM_SIZE;
                u4VideoMemSize = FLV_SP_VIDEO_PREVIEW_MEM_SIZE;
                u4AudioMemSize = FLV_SP_AUDIO_PREVIEW_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = FLV_SP_SUBTITLE_PREVIEW_MEM_SIZE;
                #endif
            }
            else
            #endif            
            {
                u4CoreMemSize = FLV_SP_CORE_MEM_SIZE;

                if(!(eTrack & SOURCE_PROVIDER_TRACK_META))
                {
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)?FLV_SP_AUDIO_WORKING_MEM_SIZE:0;
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)?FLV_SP_VIDEO_WORKING_MEM_SIZE:0;
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)?FLV_SP_SUBTITLE_WORKING_MEM_SIZE:0;
                    #endif
                }
                u4VideoMemSize = FLV_SP_VIDEO_MEM_SIZE;
                u4AudioMemSize = FLV_SP_AUDIO_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = FLV_SP_SUBTITLE_MEM_SIZE;
                #endif
            }
        }
        break;
#endif

#ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MKV:
        {
            #ifdef __VE_SP_PREVIEW__
            if (eOpenMode == MED_MODE_PREVIEW
                #ifdef __VE_MOT_DECRYPTION__
                || eOpenMode == MED_MODE_MOT_PREVIEW
                #endif
               )
            {
                u4CoreMemSize = MKV_SP_CORE_PREVIEW_MEM_SIZE + MKV_SP_VIDEO_WORKING_MEM_SIZE;
                u4VideoMemSize = MKV_SP_VIDEO_PREVIEW_MEM_SIZE;
                u4AudioMemSize = MKV_SP_AUDIO_PREVIEW_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = MKV_SP_SUBTITLE_PREVIEW_MEM_SIZE;
                #endif
            }
            else
            #endif            
            {
                u4CoreMemSize = MKV_SP_CORE_MEM_SIZE;
                                
                if(!(eTrack & SOURCE_PROVIDER_TRACK_META))
                {
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)?MKV_SP_AUDIO_WORKING_MEM_SIZE:0;
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)?MKV_SP_VIDEO_WORKING_MEM_SIZE:0;
                    #ifdef __VE_SUBTITLE_SUPPORT__
                    u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)?MKV_SP_SUBTITLE_WORKING_MEM_SIZE:0;
                    #endif
                }
                u4VideoMemSize = MKV_SP_VIDEO_MEM_SIZE;
                u4AudioMemSize = MKV_SP_AUDIO_MEM_SIZE;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4SubtitleMemSize = MKV_SP_SUBTITLE_MEM_SIZE;
                #endif
            }
        }
        break;
#endif


#ifdef __VE_STREAM_SUPPORT__
    case SOURCE_PROVIDER_STREAMING:
        {
            u4CoreMemSize = STREAMING_SP_CORE_MEM_SIZE;
                                
            if(!(eTrack & SOURCE_PROVIDER_TRACK_META))
            {
                u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_AUDIO)?STREAMING_SP_AUDIO_WORKING_MEM_SIZE:0;
                u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_VIDEO)?STREAMING_SP_VIDEO_WORKING_MEM_SIZE:0;
                #ifdef __VE_SUBTITLE_SUPPORT__
                u4CoreMemSize += (eTrack & SOURCE_PROVIDER_TRACK_SUBTITLE)?STREAMING_SP_SUBTITLE_WORKING_MEM_SIZE:0;
                #endif
            }
            u4VideoMemSize = STREAMING_SP_VIDEO_MEM_SIZE;
            u4AudioMemSize = STREAMING_SP_AUDIO_MEM_SIZE;
            #ifdef __VE_SUBTITLE_SUPPORT__
            u4SubtitleMemSize = STREAMING_SP_SUBTITLE_MEM_SIZE;
            #endif
        }
        break;
#endif

    default:
        SP_TRACE_CONTAINER_TYPE_ERROR(eFileType, eOpenMode, 0);     
        return SOURCE_PROVIDER_ERROR;
    }

    prProviderMemInfo->u4CoreMem = u4CoreMemSize;
    prProviderMemInfo->u4VideoMem = u4VideoMemSize;
    prProviderMemInfo->u4AudioMem = u4AudioMemSize;
    #ifdef __VE_SUBTITLE_SUPPORT__
    prProviderMemInfo->u4SubtitleMem = u4SubtitleMemSize;
    #endif

    return SOURCE_PROVIDER_ERROR_NONE;
}

SP_PARSER_PARAM_T * _SourceProviderObtainParserParam(SP_FILE_TYPE_T eFileType)
{
    SP_PARSER_PARAM_T *prParserParam = NULL;
        
    switch (eFileType)
    {
#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
    case SOURCE_PROVIDER_MP4:
        {            
            prParserParam = (SP_PARSER_PARAM_T *)&rMP4ParserParam;
        }
        break;
#endif        

#ifdef __VE_SP_AVI__
    case SOURCE_PROVIDER_AVI:
        {
            prParserParam =  (SP_PARSER_PARAM_T *)&rAVIParserParam;
        }
        break;
#endif

#ifdef __VE_SP_RM__
    case SOURCE_PROVIDER_RM:
        {
            prParserParam =  (SP_PARSER_PARAM_T *)&rRMParserParam;
        }
        break;
#endif

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
        case SOURCE_PROVIDER_FLV:
            {
                prParserParam =  (SP_PARSER_PARAM_T *)&rFLVParserParam;
            }
            break;
#endif

#ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
        case SOURCE_PROVIDER_MKV:
            {
                prParserParam =  (SP_PARSER_PARAM_T *)&rMKVParserParam;
            }
            break;
#endif


#ifdef __VE_STREAM_SUPPORT__
        case SOURCE_PROVIDER_STREAMING:
            {
                prParserParam =  (SP_PARSER_PARAM_T *)&rStreamingParserParam;
            }
            break;
#endif


    default:
        SP_TRACE_CONTAINER_TYPE_ERROR(eFileType, 0, 0);  
        break;
    }

    return prParserParam;

}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#ifdef __VE_MOT_DECRYPTION__
SP_FILE_TYPE_T _SourceProviderObtainContainerType(med_mode_enum eOpenType, kal_uint8 *pu1Buf, kal_uint32 u4Len)
#else
SP_FILE_TYPE_T _SourceProviderObtainContainerType(kal_uint8 *pu1Buf, kal_uint32 u4Len)
#endif
{
#ifdef __VE_MOT_DECRYPTION__
    if (eOpenType == MED_MODE_MOT_FILE || eOpenType == MED_MODE_MOT_PREVIEW)
    {
        #ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
        if (MP4ProviderCheckMotIntegrity(pu1Buf, u4Len) == KAL_TRUE) // mp4
        {
            return SOURCE_PROVIDER_MP4;
        } else
        #endif
        
        {
            return SOURCE_PROVIDER_MAX;
        }
    }
#endif

    #ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__
    if (MP4ProviderCheckIntegrity(pu1Buf, u4Len) == KAL_TRUE) // mp4
    {
        return SOURCE_PROVIDER_MP4;
    } else
    #endif
    
    #ifdef __VE_SP_AVI__
    if(AviProviderCheckIntegrity(pu1Buf, u4Len) == KAL_TRUE) // AVI
    {
        return SOURCE_PROVIDER_AVI;
    } else 
    #endif
    
    #ifdef __VE_SP_RM__
    if(RMProviderCheckIntegrity(pu1Buf, u4Len) == KAL_TRUE) // RM
    {
        return SOURCE_PROVIDER_RM;
    } else 
    #endif
    
    #ifdef __VE_FLV_FILE_FORMAT_SUPPORT__
    if(FLVProviderCheckIntegrity(pu1Buf, u4Len) == KAL_TRUE) // FLV
    {
        return SOURCE_PROVIDER_FLV;
    } else  
    #endif
    
    #ifdef __VE_MKV_FILE_FORMAT_SUPPORT__
    if(MKVProviderCheckIntegrity(pu1Buf, u4Len) == KAL_TRUE) // FLV
    {
        return SOURCE_PROVIDER_MKV;
    } else  
    #endif
	
    {
        // can't find
        return SOURCE_PROVIDER_MAX;
    }    
}


#endif // __VE_SOURCE_PROVIDER__

