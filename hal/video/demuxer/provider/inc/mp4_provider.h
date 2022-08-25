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
 *   mp4_media_provider.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MP4_PROVIDER_H
#define _MP4_PROVIDER_H

#include "drv_features_video.h"

#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__

#include "app_ltlcom.h"
#include "mpl_common.h"
#include "source_provider_if.h"
//#include "source_provider_component.h"
#include "provider_utility.h"
#include "mp4_parser.h"
#include "fsal.h"

#define MP4_PROVIDER_FSAL_BUF_SIZE   (2048 / 4) /* 1024 bytes per track */
#define MP4_PROVIDER_STCO_BUF_SIZE   (2048 / 4) /* 512 bytes per track */
#define MP4_PROVIDER_STSZ_BUF_SIZE   (2048 / 4) /* 512 bytes per track */
#define MP4_PROVIDER_STSS_BUF_SIZE   (2048 / 4) /* 512 bytes per track */
#define MP4_PROVIDER_STTS_BUF_SIZE   (2048 / 4) /* 512 bytes per track */
#define MP4_PROVIDER_MAP_BUF_SIZE    (2048 / 4) /* 512 bytes per track */
#define MP4_PROVIDER_STBL_BUF_SIZE   (1024 / 4 * 8) /* 8K bytes */
#define MP4_PROVIDER_SEEK_HINT_SIZE  (2047) /* 2047*8 bytes */
#define MP4_PROVIDER_CHECK_CONTAINER_LEN 16
#define MP4_PROVIDER_CHECK_FTYP 0x66747970
#define MP4_PROVIDER_SAMPLE_NO_MAX (0xFFFFFFFF)
#define MP4_PROVIDER_DURATION_MARGIN (500)
#define MP4_PROVIDER_BATCH_READ_MAX (50)
#define MP4_PROVIDER_VID_FPS_UPPER_BOUND (12000)
#define MP4_PROVIDER_AUD_SAMPLE_GAP_THRESHOLD (512)
#define MP4_PROVIDER_VID_SAMPLE_GAP_THRESHOLD (1024)
#define MP4_PROVIDER_MIN_READ_SIZE (32 * 1024)
#define MP4_PROVIDER_MIN_ACCU_TIME (10)

/* SPS/PPS related */
#define MP4_PROVIDER_AVC_CONFIG_REC_SPS_OFFSET (5) /* total bytes before numOfSequenceParameterSets in AVCDecoderConfigurationRecord */
#define MP4_PROVIDER_PARAMSET_LENGTH           (3*1024)
#define MP4_PROVIDER_MAX_DESCRIPTION (80)

/* track related buffer pool of MP4 Media Provider */
typedef struct {
    kal_uint32 fsal_buf[MP4_PROVIDER_FSAL_BUF_SIZE];
    kal_uint32 fsal_buf_stsz[MP4_PROVIDER_STSZ_BUF_SIZE];
    kal_uint32 fsal_buf_stco[MP4_PROVIDER_STCO_BUF_SIZE];
    kal_uint32 fsal_buf_stts[MP4_PROVIDER_STTS_BUF_SIZE];
    //kal_uint32 fsal_buf_mdat[MP4_MP_MDAT_A_BUF_SIZE];

    STMp4Parser t_parser; /* MP4 Parser structure */
    STFSAL t_fsal; /* FSAL structure to open file */
    STFSAL t_fsal_stsz; /* FSAL structure to read STSZ */
    STFSAL t_fsal_stco; /* FSAL structure to read STCO */
    STFSAL t_fsal_mdat; /* FSAL structure to read media data */
    STFSAL t_fsal_stts; /* FSAL structure to read STTS */

} MP4_PROVIDER_TRACK_BUF_POOL_AUD_T;

typedef struct {

    kal_uint32 fsal_buf[MP4_PROVIDER_FSAL_BUF_SIZE];
    kal_uint32 fsal_buf_stsz[MP4_PROVIDER_STSZ_BUF_SIZE];
    kal_uint32 fsal_buf_stco[MP4_PROVIDER_STCO_BUF_SIZE];
    kal_uint32 fsal_buf_stss[MP4_PROVIDER_STSS_BUF_SIZE];
    kal_uint32 fsal_buf_stts[MP4_PROVIDER_STTS_BUF_SIZE];
    //kal_uint32 fsal_buf_mdat[MP4_MP_MDAT_V_BUF_SIZE];

    STMp4Parser t_parser; /* MP4 Parser structure */
    STFSAL t_fsal; /* FSAL structure to open file */
    STFSAL t_fsal_stsz; /* FSAL structure to read STSZ */
    STFSAL t_fsal_stco; /* FSAL structure to read STCO */
    STFSAL t_fsal_mdat; /* FSAL structure to read media data */
    STFSAL t_fsal_stss; /* FSAL structure to read STSS */
    STFSAL t_fsal_stts; /* FSAL structure to read STTS */
} MP4_PROVIDER_TRACK_BUF_POOL_VID_T;

/* common buffer pool of MP4 Media Provider */
typedef struct {
    FS_FileLocationHint t_fsal_seek_hint[MP4_PROVIDER_SEEK_HINT_SIZE];
    kal_uint32 stbl_buf[MP4_PROVIDER_STBL_BUF_SIZE];
} MP4_PROVIDER_COMMON_BUF_POOL_T;

#ifdef __VE_PGDL_SUPPORT__
/* track related buffer pool of MP4 Media Provider for PDL */
typedef struct {
    kal_uint32 fsal_buf[MP4_PROVIDER_FSAL_BUF_SIZE];
    kal_uint32 fsal_buf_stsz[MP4_PROVIDER_STSZ_BUF_SIZE];
    kal_uint32 fsal_buf_stco[MP4_PROVIDER_STCO_BUF_SIZE];

    STMp4Parser t_parser; /* MP4 Parser structure */
    STFSAL t_fsal; /* FSAL structure to open file */
    STFSAL t_fsal_stsz; /* FSAL structure to read STSZ */
    STFSAL t_fsal_stco; /* FSAL structure to read STCO */

} MP4_PROVIDER_TRACK_BUF_POOL_PDL_T;
#endif


/* track related buffer pool of MP4 Media Provider for KMV Subtitle */
typedef struct {
    kal_uint32 fsal_buf[MP4_PROVIDER_FSAL_BUF_SIZE];
    kal_uint32 fsal_buf_STSZ[MP4_PROVIDER_STSZ_BUF_SIZE];
    kal_uint32 fsal_buf_STCO[MP4_PROVIDER_STCO_BUF_SIZE];
    kal_uint32 fsal_buf_MAP[MP4_PROVIDER_MAP_BUF_SIZE];
    STMp4Parser t_parser; /* MP4 Parser structure */
    STFSAL t_fsal; /* FSAL structure to open file */
    STFSAL t_fsal_STSZ;
    STFSAL t_fsal_STCO;
    STFSAL t_fsal_MAP;

} MP4_PROVIDER_TRACK_BUF_POOL_KMV_T;



typedef struct
{
#if 1
   kal_wchar pu2Title[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Artist[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Album[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Author[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Genre[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Copyright[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Date[MP4_PROVIDER_MAX_DESCRIPTION+1];
   kal_wchar pu2Comment[MP4_PROVIDER_MAX_DESCRIPTION+1];
#endif
} MP4_PROVIDER_USER_DATA_T;

typedef struct
{

  kal_uint32 m_tSTCO;
  kal_uint32 m_metaoffset;
  kal_uint32 m_nChunk;
  kal_uint16 m_KMV_type;
  kal_uint8 m_SampleInChunk;

} MP4_PROVIDER_KMV_DATA_T;

typedef struct
{
    kal_uint8* p_mem_start;
    kal_uint32 sample_offset[MP4_PROVIDER_BATCH_READ_MAX];
    kal_uint32 sample_size[MP4_PROVIDER_BATCH_READ_MAX];
    kal_uint32 sample_no_start; /* the sample no of idx 0 is sample_no_start */
    kal_uint32 curr_sample_no;
    kal_uint32 curr_sample_offset;
    #if 1 /* throughput profiling*/
    kal_uint32 count;
    kal_uint32 accum_time;
    kal_uint32 accum_size;
    #endif
    kal_uint32  read_idx;
    kal_uint32  write_idx;
} MP4_PROVIDER_BATCH_READ_T;

typedef struct
{
    union{
        kal_uint32 u4FileBufAddr; /* the start address of the file located */
        kal_wchar acFileName[MPL_MAX_FILE_NAME_LEN]; /* file name */      
    }u_src;

    MP4_PROVIDER_BATCH_READ_T t_batch[SOURCE_PROVIDER_PORT_MAX-1];

    //media_stream_t* pt_stream_info[SOURCE_PROVIDER_PORT_MAX-1]; /* specific stream information */
    kal_uint64 dispatch_time[SOURCE_PROVIDER_PORT_MAX-1]; /* decode time of the last "dispatching" sample, in ms */
    kal_uint64 demux_time[SOURCE_PROVIDER_PORT_MAX-1]; /* composition time of the last "demuxing" sample, in ms */
    
    // Add one data fail. Stored
    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo[SOURCE_PROVIDER_PORT_MAX-1];

    STFSAL* pt_fsal[SOURCE_PROVIDER_PORT_MAX]; /* FSAL handle pointer to file */
    STFSAL* pt_fsal_stsz[SOURCE_PROVIDER_PORT_MAX]; /* FSAL handle pointer to read STSZ */
    STFSAL* pt_fsal_stco[SOURCE_PROVIDER_PORT_MAX]; /* FSAL handle pointer to read STCO */
    STFSAL* pt_fsal_stss[SOURCE_PROVIDER_PORT_MAX-1]; /* FSAL handle pointer to read STSS */
    STFSAL* pt_fsal_stts[SOURCE_PROVIDER_PORT_MAX-1]; /* FSAL handle pointer to read STTS */
    STFSAL* pt_fsal_mdat[SOURCE_PROVIDER_PORT_MAX-1]; /* FSAL handle pointer to read media data */
    STFSAL* pt_fsal_map;                              /* FSAL handle pointer to read KMV map data */
    kal_uint32* p_fsal_buf[SOURCE_PROVIDER_PORT_MAX]; /* FSAL working buffer pointer to file */
    kal_uint32* p_fsal_buf_stsz[SOURCE_PROVIDER_PORT_MAX]; /* FSAL working buffer pointer to read STSZ */
    kal_uint32* p_fsal_buf_stco[SOURCE_PROVIDER_PORT_MAX]; /* FSAL working buffer pointer to read STCO */
    kal_uint32* p_fsal_buf_stss[SOURCE_PROVIDER_PORT_MAX-1]; /* FSAL working buffer pointer to read STSS */
    kal_uint32* p_fsal_buf_stts[SOURCE_PROVIDER_PORT_MAX-1]; /* FSAL working buffer pointer to read STTS */
    kal_uint32* p_fsal_buf_map;                             /* FSAL working buffer pointer to read MAP */
    
    kal_uint32 au4CurrSampleNo[SOURCE_PROVIDER_PORT_MAX-1]; /* current "demuxing" sample number */
    kal_uint32 bad_sample_no[SOURCE_PROVIDER_PORT_MAX-1]; /* corrupted sample number */
    kal_uint32 au4TimeScale[SOURCE_PROVIDER_PORT_MAX-1]; /* time-scale */
    kal_uint32 au4SampleCount[SOURCE_PROVIDER_PORT_MAX-1]; /* the number of samples in the track */
    kal_uint32 au4SampleNoStart[SOURCE_PROVIDER_PORT_MAX-1]; /* 1st "demuxing" sample number after start */
    kal_uint32 au4SampleNoSync[SOURCE_PROVIDER_PORT_MAX-1]; /* should invoke MP4_GetCompositionTime */
    kal_uint32 au4LastReleaseSampleNo[SOURCE_PROVIDER_PORT_MAX-1]; /* last release sample number */

    SP_TRACK_T eTrack; //med_track_enum eMode;
    kal_uint32 au4StartTime[SOURCE_PROVIDER_PORT_MAX-1]; /* start time of demux range */
    kal_uint32 stop_time; /* stop time of demux range */

    /* track specific buffer pool */
    MP4_PROVIDER_TRACK_BUF_POOL_AUD_T* pt_track_buf_pool_aud;
    MP4_PROVIDER_TRACK_BUF_POOL_VID_T* pt_track_buf_pool_vid;
    MP4_PROVIDER_TRACK_BUF_POOL_KMV_T* pt_track_buf_pool_sub;

    SPIF_VIDEO_STREAM_INFO_T *prVidStreamInfo;
    SPIF_AUDIO_STREAM_INFO_T *prAudStrmInfo;
	MP4_PROVIDER_KMV_DATA_T prKmvInfo;
    kal_uint32 u4VidTrackNum;
    kal_uint32 u4AudTrackNum;

    STMp4Parser* pt_parser; /* handle pointer of MP4 Parser */

    kal_int32 file_handle; /* handle of file */
    kal_uint32 u4FileSize; /* file size */
    kal_uint32 u4KMVFileLen;
    kal_uint32 u4UUIDFileLen;

    kal_uint32 u4MovieTimeScale;
    kal_uint32 u4MovieDuration; /* movie duration, in ms */

    /* common buffer pool */
    MP4_PROVIDER_COMMON_BUF_POOL_T* pt_comn_buf_pool;
    kal_uint32* p_stbl_buf; /* buffer to cache table */

    FS_FileLocationHint* pt_fsal_seek_hint; /* FSAL seek hint */

    //Source component
    SP_API_T *prSourceAPI;
    void *prSourceHandle;


    // Parameter set data
    PU_VID_PARAM_SET_T* prVideoParamSetData;
    MP4_PROVIDER_USER_DATA_T* prUdtaInfo;
    kal_uint32 stss_next_index[SOURCE_PROVIDER_PORT_MAX-1];

    kal_uint8 au1TrackNo[SOURCE_PROVIDER_PORT_MAX-1]; /* track number; if it equals MP4_RESERVED_TRACK_NO, it means no such type track  */
    
    kal_uint8 Decrypted_Key[16];

    SP_PORT_TYPE_T eTrackType[MP4_NUM_TRACKS]; /* track type */

    kal_bool afgEos[SOURCE_PROVIDER_PORT_MAX-1];

    med_mode_enum eSrcType; /* media source type */

    kal_bool fgSelectedTrack[SOURCE_PROVIDER_PORT_MAX-1]; /* is selected track to demux */

    kal_bool fgResend[SOURCE_PROVIDER_PORT_MAX-1];



#ifdef __VE_PGDL_SUPPORT__
    /***********************/
    /*    PROGRESSIVE DL   */
    /***********************/
    kal_bool fgWaitMeta;    //meta data is not enough in Open stage, used for pgdl
    MP4_PROVIDER_TRACK_BUF_POOL_PDL_T* pt_track_buf_pool_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    STMp4Parser* pt_parser_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    STFSAL* pt_fsal_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    STFSAL* pt_fsal_stsz_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    STFSAL* pt_fsal_stco_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    kal_uint32* p_fsal_buf_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    kal_uint32* p_fsal_buf_stco_pdl[SOURCE_PROVIDER_PORT_MAX-1];
    kal_uint32* p_fsal_buf_stsz_pdl[SOURCE_PROVIDER_PORT_MAX-1];
#endif /* __VE_PGDL_SUPPORT__ */
}MP4_PROVIDER_CTRL_T;

#ifdef __VE_MOT_DECRYPTION__
extern kal_bool MP4ProviderCheckMotIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len);
#endif
extern kal_bool MP4ProviderCheckIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len);
//extern PROVIDER_ERROR_T MP4ProviderGetMemInfo(SPIF_PROVIDER_MEM_INFO_T *pvMem);
extern PROVIDER_ERROR_T MP4ProviderGetHandle(void *prSrcMgr, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr);
extern PROVIDER_ERROR_T MP4ProviderReleaseHandle(void* pvHandle);
extern media_error_t mp4_mp_is_prog_dl_file(kal_uint8* p_file_buf, kal_uint32 buf_size, kal_bool* is_pdl);
extern media_error_t mp4_mp_scramble_buffer(kal_uint8* p_file_buf, kal_uint32 buf_size);
#endif /* __VE_MP43GP_FILE_FORMAT_SUPPORT__ */

#endif /* _MP4_MEDIA_PROVIDER_H */
