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
 *   flv_provider.h
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
 ****************************************************************************/

#include "drv_features_video.h"
#include "source_provider_if.h"
#include "provider_utility.h"
#include "flv_parser.h"

#ifndef _FLV_PROVIDER_H
#define _FLV_PROVIDER_H

#ifdef __VE_FLV_FILE_FORMAT_SUPPORT__

#define FLV_MP_FSAL_BUF_SIZE       (4096 / 4) /* 4096 bytes */
#define FLV_MP_FSAL_AUD_BUF_SIZE   (4096 / 4) /* 4096 bytes */
#define FLV_MP_PARAMSET_LENGTH           (3*1024)
#define FLV_MP_BATCH_READ_MAX (50)
#define FLV_MP_SEEK_HINT_SIZE  (2047) /* 2047*8 bytes */

#define FLV_FLAG_KEY_FRAME (1<<0)
#define FLV_FLAG_PARTIAL_DATA (1<<1)

typedef struct {
    STFSAL t_fsal; /* FSAL structure to open file */
    kal_uint32 fsal_buf[FLV_MP_FSAL_AUD_BUF_SIZE];
    STFSAL t_fsal_mdat; /* FSAL structure to read media data */
} flv_mp_track_buf_pool_aud;

typedef struct {
    STFSAL t_fsal; /* FSAL structure to open file */
    kal_uint32 fsal_buf[FLV_MP_FSAL_BUF_SIZE];
    STFSAL t_fsal_mdat; /* FSAL structure to read media data */
} flv_mp_track_buf_pool_vid;

/* common buffer pool of FLV Media Provider */
typedef struct {
    FS_FileLocationHint t_fsal_seek_hint[FLV_MP_SEEK_HINT_SIZE];

    // Key table usage
    STFSAL t_fsal_key_table; /* FSAL structure to read key table */
    kal_uint32 fsal_key_table_buf[FLV_MP_FSAL_BUF_SIZE];
} flv_mp_common_buf_pool;

typedef struct
{
    kal_uint8* p_mem_start;
    kal_uint32 offset[FLV_MP_BATCH_READ_MAX];
    kal_uint32 size[FLV_MP_BATCH_READ_MAX];
    kal_uint32 flags[FLV_MP_BATCH_READ_MAX];
    kal_uint32 DecTime[FLV_MP_BATCH_READ_MAX];
    kal_uint32 DispTime[FLV_MP_BATCH_READ_MAX];
    kal_uint32 skipsize[FLV_MP_BATCH_READ_MAX]; /* 為了找第2張的頭所skip掉的量 */
    kal_uint32 frame_idx_start; /* the frame index of idx 0 is frame_idx_start */
    kal_uint32 curr_frame_idx;
    kal_uint32 curr_frame_offset;
    kal_uint32 curr_frame_size;
    kal_uint32 curr_frame_flags;
    kal_uint32 curr_frame_dec_time;
    kal_uint32 curr_frame_disp_time;
    kal_uint32 drop_size;
    #if 1 /* 記錄前一次已讀進來的bitstream是否可以供這次使用*/
    kal_uint32 LastReadOffset; /* File offset start read last time */
    kal_uint32 LastReadAmount; /* Data amount read last time */
    kal_uint8* LastMemStart; /* Memory start address for last read */
    #endif
    #if 1 /* throughput profiling*/
    kal_uint32 count;
    kal_uint32 accum_time;
    kal_uint32 accum_size;
    #endif
    kal_uint8  read_idx;
    kal_uint8  write_idx;
} FLV_PVDR_BATCH_READ_STRUCT;

typedef struct
{
    kal_uint32 u4SeekTime;
    kal_uint32 u4KeyTime;
    kal_uint32 u4SampleIndex;
    kal_uint32 u4Offset;
} FLV_PVDR_SEEK_STRUCT;

typedef struct
{
    FLV_PVDR_BATCH_READ_STRUCT t_batch[FLV_TRACK_TOTAL];
    SP_TRACK_T eTrack; //med_track_enum eMode;
    kal_uint32 start_time[FLV_TRACK_TOTAL]; /* start time of demux range */
    kal_uint32 stop_time; /* stop time of demux range */
    kal_bool afgEos[FLV_TRACK_TOTAL];

    med_mode_enum eSrcType; /* media source type */
    union{
        kal_wchar file_name[MPL_MAX_FILE_NAME_LEN]; /* file name */
        kal_uint32 file_buf_addr; /* the start address of the file located */
    }u_src;
    kal_int32 file_handle; /* handle of file */
    kal_uint32 file_size; /* file size */

    flv_mp_track_buf_pool_aud* pt_track_buf_pool_aud;
    flv_mp_track_buf_pool_vid* pt_track_buf_pool_vid;
    SPIF_VIDEO_STREAM_INFO_T *prVidStreamInfo;
    SPIF_AUDIO_STREAM_INFO_T *prAudStrmInfo;

    STFSAL* pt_fsal[FLV_TRACK_TOTAL]; /* FSAL handle pointer to file */
    STFSAL* pt_fsal_mdat[FLV_TRACK_TOTAL]; /* FSAL handle pointer to read bitstream data */
    kal_uint32* p_fsal_buf[FLV_TRACK_TOTAL]; /* FSAL working buffer pointer to file */
    kal_bool fgSelectedTrack[FLV_TRACK_TOTAL]; /* is selected track to demux */
    kal_uint64 demux_time[FLV_TRACK_TOTAL]; /* composition time of the last "demuxing" sample, in ms */
    kal_uint8 track_no[FLV_TRACK_TOTAL]; // FLV_TRACK_AUDIO/FLV_TRACK_VIDEO

    kal_uint32 sample_no_start[FLV_TRACK_TOTAL]; /* 1st "demuxing" sample number after start */
    kal_uint32 curr_sample_no[FLV_TRACK_TOTAL]; /* current "demuxing" sample number */
    kal_uint32 curr_accum_size[FLV_TRACK_TOTAL]; /* current accumulated size */
    kal_uint32 bad_sample_no[FLV_TRACK_TOTAL]; /* corrupted sample number */
    kal_uint32 sample_no_sync[FLV_TRACK_TOTAL];

    flv_mp_common_buf_pool* pt_comn_buf_pool;
    FS_FileLocationHint* pt_fsal_seek_hint; /* FSAL seek hint */

    //Source component
    SP_API_T *prSourceAPI;
    void *prSourceHandle;

    FLV_PVDR_SEEK_STRUCT t_seek_param[FLV_TRACK_TOTAL];

    FLVParser *ptFLVParser[FLV_TRACK_TOTAL];
    FLVMetaData *ptFLVMetaData;

    PU_VID_PARAM_SET_T* prVideoParamSetData;

    SPIF_PROVIDER_FRAME_INFO_T rFrameInfo[FLV_TRACK_TOTAL];
}FLV_PROVIDER_CTRL_T;

kal_bool FLVProviderCheckIntegrity(kal_uint8 *pu1Buf, kal_uint32 u4Len);
PROVIDER_ERROR_T FLVProviderGetHandle(void *prSrcMgr, SP_API_T *prSrcAPI, SPIF_PROVIDER_HANDLE_T *prPrvHdlr);
PROVIDER_ERROR_T FLVProviderReleaseHandle(void* pvHandle);

#endif /* __VE_FLV_FILE_FORMAT_SUPPORT__ */
#endif /* _FLV_PROVIDER_H */

