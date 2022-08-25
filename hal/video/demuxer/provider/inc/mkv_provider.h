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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_video.h"

#if defined(__VE_MKV_FILE_FORMAT_SUPPORT__)

#ifndef MKV_PROVIDER_H
#define MKV_PROVIDER_H

#include "source_provider_if.h"
#include "mkv_parser.h"
#ifdef __VE_SUBTITLE_SUPPORT__
#include "video_subtitle_decoder_if.h"
#endif

#define __MKV_MAUI_03155540


//#define __MKV_PROVIDER_UT__
//#define __MKV_PROVIDER_DEBUG__
//#define __MKV_PROVIDER_PROFILE__
//#define __MKV_SWLA__
//#define __MKV_MEMORY_CHECK__

//#define __MKV_SUBTITLE_HEADER__

#define MKV_CORE_FILE_BUFFER_SIZE (2 * 1024)
#define MKV_VIDEO_FILE_BUFFER_SIZE (8 * 1024)
#define MKV_AUDIO_FILE_BUFFER_SIZE (5 * 1024)
#define MKV_SUBTITLE_FILE_BUFFER_SIZE (5 * 1024)
#define MKV_FILE_SEEK_HINT_SIZE (1023)

#ifndef __VIDEO_SUBTITLE_SUPPORT__
#define MKV_TRACK_COUNT   2
#else
#define MKV_TRACK_COUNT   3
#endif

typedef struct mkv_provider_codecinfo
{
    media_codec_type_t eCodecType;
    kal_uint32 u4CodecPrivateSize;
    kal_uint8* pu1CodecPrivateData;
    mkv_parser_track* pTrack;
    kal_uint8 u1NALULenSize;  //H264 only
    kal_bool fgSendHeader;	
}mkv_provider_codecinfo;

typedef struct mkv_BitmapInfoheader{
  kal_uint32 biSize;
  kal_uint32 biWidth;
  kal_uint32 biHeight;
  kal_uint16 biPlanes;
  kal_uint16 biBitCount;
  kal_uint32 biCompression;
  kal_uint32 biSizeImage;
  kal_uint32 biXPelsPerMeter;
  kal_uint32 biYPelsPerMeter;
  kal_uint32 biClrUsed;
  kal_uint32 biClrImportant;
} mkv_BitmapInfoheader;


typedef struct mkv_Waveformatex{
    kal_uint16 u2FormatTag;
    kal_uint16 u2Channels;	
    kal_uint32 u4SamplesPerSec;
    kal_uint32 u4AvgBytesPerSec;
    kal_uint16 u2BlockAlign;
    kal_uint16 u2BitsPerSample;		
}mkv_Waveformatex;	

#define WAVE_FORMAT_PCM     1
#define WAVE_FORMAT_MPEG       0x0050
#define WAVE_FORMAT_MPEGLAYER3 0x0055

typedef struct MKV_SP_PROVIDER_CONTEXT_T
{
    PROVIDER_API_T* rMKVProviderAPI;
    void * pvSourceHandle;
    SP_API_T* prSourceAPI;
    SP_TRACK_T eOpenTrack; 
    med_mode_enum eOpenType;

    SPIF_OPEN_INFO_T* mkv_file_handle;

    kal_bool fgTerminate;

    /* header */
    mkv_parser* mkvparser;
    mkv_parser_track **pTrackInfo;	
    kal_uint16 u2StreamCount[MKV_TRACK_COUNT]; 	
    SPIF_VIDEO_STREAM_INFO_T* video_stream_info;
    SPIF_AUDIO_STREAM_INFO_T* audio_stream_info;
    SPIF_SUBTITLE_STREAM_INFO_T* subtitle_stream_info;	

    kal_uint16 u2StreamIdx[MKV_TRACK_COUNT]; 
    SPIF_OPEN_INFO_T* paFileHandle[MKV_TRACK_COUNT]; 
    mkv_parser_cluster* paCluster[MKV_TRACK_COUNT]; 
    mkv_parser_block* paBlock[MKV_TRACK_COUNT]; // want deliver block data
    SPIF_PROVIDER_FRAME_INFO_T* paFrameInfo[MKV_TRACK_COUNT]; // want deliver frame info
    kal_uint8* pu1BitstreamAddress[MKV_TRACK_COUNT];  //next deliver bitstream address in bitstream buffer

    mkv_provider_codecinfo* paCodecInfo[MKV_TRACK_COUNT]; // current select track codec inforamtion
    kal_uint32 u4Timestamp[MKV_TRACK_COUNT];
    kal_bool fgTrackEOF[MKV_TRACK_COUNT];
    kal_uint32 u4StartTime[MKV_TRACK_COUNT];  // millisecond	
    kal_uint32 u4StopTime[MKV_TRACK_COUNT];    	

    kal_bool fgAbort[MKV_TRACK_COUNT];

    /* debug */
    kal_uint32 u4FrameDeliver[MKV_TRACK_COUNT];
    kal_uint32 u4PacketGet[MKV_TRACK_COUNT];


#ifdef __VE_SUBTITLE_SUPPORT__
    SPIF_PROVIDER_FRAME_INFO_T* subtitle_duration_frame;	
#ifdef __MKV_MAUI_03155540
    kal_uint8* pu1SSA_style;
    kal_uint32 u4SSA_style_len;	
#endif
#endif	

}MKV_SP_PROVIDER_CONTEXT_T;

#ifdef __MKV_SWLA__
#define MKV_START_LOGGING(sym)  VIDEO_START_LOGGING(sym)
#define MKV_STOP_LOGGING(sym) VIDEO_STOP_LOGGING(sym)
#define MKV_LABEL_LOGGING(sym) VIDEO_LABEL_LOGGING(sym)
#else
#define MKV_START_LOGGING(sym)  do{}while(0);
#define MKV_STOP_LOGGING(sym) do{}while(0);
#define MKV_LABEL_LOGGING(sym) do{}while(0);
#endif

extern PROVIDER_ERROR_T MKVProviderGetHandle(void *pvSrcHandle, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr);
extern PROVIDER_ERROR_T MKVProviderReleaseHandle(void* pvHandle);
extern kal_bool MKVProviderCheckIntegrity(kal_uint8* pBuf, kal_uint32 ulSize);

#endif //MKV_PROVIDER_H
#endif //__VE_MKV_FILE_FORMAT_SUPPORT__
