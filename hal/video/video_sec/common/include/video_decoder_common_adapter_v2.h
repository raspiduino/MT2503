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
 *   video_decoder_common_adapter_v2.h
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
 *
 * removed!
 ****************************************************************************/
#ifndef VIDEO_DECODER_COMMON_ADAPTER_V2_H
#define VIDEO_DECODER_COMMON_ADAPTER_V2_H
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "video_codec_if_v2.h"
#include "app_ltlcom.h"
#include "vcodec_if.h"


// SW CODEC API

typedef void    (*PFN_MALLOC)                        (IN HANDLE                             /* hDrv */, 
                                                      IN unsigned int                       /* u4Size */, 
									   		          IN unsigned int                       /*u4AlignSize*/,
                                                      IN VCODEC_MEMORY_TYPE_T                     /* fgCacheable */, 
                                                      OUT VCODEC_BUFFER_T *                  /* prBuf */	// 由caller提供VCODEC_BUFFER_T *位置，callee只負責將VA,PA,status填入
                                                      );  /* buffer address must cache line align */      

typedef void    (*PFN_INTMALLOC)                     (IN HANDLE                             /* hDrv */, 
                                                      IN unsigned int                       /* u4Size */,                                                      
													  IN unsigned int                       /*u4AlignSize*/,
													  OUT VCODEC_BUFFER_T *                 /* pBuffer_adr */	
                                                      );        

typedef void    (*PFN_FREE)                          (IN HANDLE                             /* hDrv */, 
                                                      IN VCODEC_BUFFER_T *                   /* prBuf */
                                                      );  /* same memory type with malloc */  

typedef void    (*PFN_INTFREE)                       (IN HANDLE                             /* hDrv */,                                                       
  													  IN VCODEC_BUFFER_T *                 /* pBuffer_adr */	
                                                      );  /* same memory type with malloc */  
                                                      
typedef VCODEC_DEC_ERROR_T  (*PFN_SETYUVBUFFER)      (IN HANDLE                              /* hDrv */, 
                                                      IN VCODEC_DEC_YUV_BUFFER_PARAM_T *  /* prYUVParam */
                                                      );
                                                      
typedef VCODEC_DEC_ERROR_T  (*PFN_GETYUVBUFFER)      (IN  HANDLE                             /* hDrv */,                                                       
                                                      OUT VCODEC_BUFFER_T *                  /* prYUVBuf */
                                                      );
                                                      
typedef void    (*PFN_REFFREEYUVBuffer)              (IN HANDLE                             /* hDrv */, 
                                                      IN VCODEC_BUFFER_T *                   /* prYUVBuf */
                                                      );
                                                      
typedef VCODEC_DEC_ERROR_T  (*PFN_QUERYINFO)         (IN HANDLE                              /* hDrv */,
                                                      IN VCODEC_DEC_QUERY_INFO_TYPE_T        /* query id*/,
											    	  OUT void *                           /* pvParamData*/ /* */
                                                      );
                           
typedef void   (*PFN_RETURNBITSTREAM)                (IN HANDLE                             /* hDrv */,                                                       
                                                      IN VCODEC_BUFFER_T  *                  /* prBuffer */  /* Input buffer address */,
                                                      IN unsigned int                          /* u4BuffSize */ /* Input buffer total size */
                                                      );


typedef struct
{
    kal_bool fgIsCodecInit;
    kal_bool fgEOF;
    kal_bool fgYUVCacheable;
    kal_bool fgYUVOriginCacheable;
    kal_bool fgBsCacheable;
    kal_bool fgBsOriginCacheable;
    kal_uint16 u2FrameWidth;
    kal_uint16 u2FrameHeight;
    kal_uint32 u4BufferSize;
    VCODEC_DEC_API_T  *prDecAPI;
    HANDLE hDrvHandle;
    HANDLE hCodecHandle;
    void *prCustomSetting;
    VIDEO_ADAPTOR_CODEC_T eDecType;
    VIDEO_ADAPTOR_SCENARIO_T eScenario;
    kal_uint32 u4GetIntMemSize;
    kal_uint32 u4MaxRetryValue;
    kal_uint32 u4DecodeErrRetryCount;
    VIDEO_CONTAINER_INFO_T* prContainerInfo;
}VIDEO_DECODER_ADAPTER_CTRL_T;

VIDEO_DECODER_CODEC_API_T* GetVideoDecoderAdapterHandle(VIDEO_ADAPTOR_CODEC_T eType, VIDEO_ADAPTOR_SCENARIO_T eScenario);


#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_DECODER_COMMON_ADAPTER_V2_H */ 

