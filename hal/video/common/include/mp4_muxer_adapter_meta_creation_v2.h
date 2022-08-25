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
 *   mp4_muxer_adapter_meta_creation_v2.h
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
 ****************************************************************************/
#ifndef __MP4_MUXER_ADAPTER_META_CREATION_V2_H
#define __MP4_MUXER_ADAPTER_META_CREATION_V2_H

#include "drv_features_video.h"
#include "video_types_v2.h"
#include "mp4_muxer_adapter_v2.h"
#include "video_buffer_management_v2.h"

/******************************************************************************
* Enum Definition
******************************************************************************/
enum TrakType
{
    VIDEO_TRACK,
    AUDIO_TRACK,
    UNKNOWN_TRACK
};

enum eBoxSize
{
    MOOV_SIZE = 8,          // Constant
    IUAM_SIZE = 44,         // Constant
    MVHD_SIZE = 108,        // Constant
    IODS_SIZE = 42,         // Constant
    TRAK_SIZE = 8,          // Constant
    TKHD_SIZE = 92,         // Constant
    MDIA_SIZE = 8,          // Constant
    MDHD_SIZE = 32,         // Constant
    HDLR_SIZE = 50,         // Variable, v: 32, a: 50
    MINF_SIZE = 8,          // Constant
    VMHD_SIZE = 20,         // Constant
    SMHD_SIZE = 16,         // Constant
    DINF_SIZE = 36,         // Constant
    STBL_SIZE = 8,          // Constant

    STSD_MAX_SIZE = 256,        // Variable, depend codec
    STSD_V_SIZE = 197,      // Video Max Stsd size
    STSD_A_SIZE = 69,       // Audio Max Stsd size

    STSC_MAX_SIZE = 40,     // Constant
    STSC_MIN_SIZE = 32,     // Constant

    STTS_MAX_SIZE = 256,    // Variable, depend on frame count, max buffer size
    STTS_A_SIZE = 24,       // Constant
    STTS_MIN_SIZE = 24,     // Constant, only one frame

    STSZ_MAX_SIZE = 256,    // Variable, depend on frame count, max buffer size
    STSZ_MIN_SIZE = 20,     // Constant

    STCO_MAX_SIZE = 256,    // Variable, depend on frame count, max buffer size
    STCO_MIN_SIZE = 20      // Constant
};

/******************************************************************************
* Macro Definition
******************************************************************************/
// Temp Meta file content offset (the position to store information)
#define MP4_POS_V_BASE                          0x0
#define MP4_POS_V_CODEC_TYPE                    MP4_POS_V_BASE              // video codec
#define MP4_POS_V_WIDTH                         (MP4_POS_V_BASE + 0x4)      // video width
#define MP4_POS_V_HEIGHT                        (MP4_POS_V_BASE + 0x8)      // video height
#define MP4_POS_V_MDAT_SIZE                     (MP4_POS_V_BASE + 0xC)      // video mdat position
#define MP4_POS_V_DURATION                      (MP4_POS_V_BASE + 0x10)     // video duration
#define MP4_POS_V_ROTATEANGLE                   (MP4_POS_V_BASE + 0x14)     // Clockwise, rotate angle
#define MP4_POS_V_HMIRROR                       (MP4_POS_V_BASE + 0x18)     // Horizontally Mirror
#define MP4_POS_V_RESERVED                      (MP4_POS_V_BASE + 0x1C)

#define MP4_POS_A_BASE                          0x20
#define MP4_POS_A_CODEC_TYPE                    MP4_POS_A_BASE              // audio codec
#define MP4_POS_A_FRAME_COUNT                   (MP4_POS_A_BASE + 0x4)      // audio frame count
#define MP4_POS_A_RESERVED                      (MP4_POS_A_BASE + 0x8)

#define MP4_POS_MEDIA_BASE                      0x30
#define MP4_POS_STOP_TIME                       MP4_POS_MEDIA_BASE          // kal_uint64, so it should reserve 8 bytes
#define MP4_POS_RECORD_AUDIO                    (MP4_POS_MEDIA_BASE + 0x8)  // record audio
#define MP4_POS_PSEUDO_MERGE                    (MP4_POS_MEDIA_BASE + 0xC) // use pseudo merge

#define MP4_POS_STBL_BASE                       0x50
#define MP4_POS_STTS_LAST_TIME_STAMP            MP4_POS_STBL_BASE           // kal_uint64, so it should reserve 8 bytes
#define MP4_POS_STTS_GOT_FIRST_FRAME            (MP4_POS_STBL_BASE + 0x8)
#define MP4_POS_STTS_HAS_FIRST_DELTA            (MP4_POS_STBL_BASE + 0xC)
#define MP4_POS_STTS_SAMPLE_DELTA               (MP4_POS_STBL_BASE + 0x10)
#define MP4_POS_STTS_SAMPLE_COUNT               (MP4_POS_STBL_BASE + 0x14)
#define MP4_POS_STSC_SAMPLES                    (MP4_POS_STBL_BASE + 0x18)

#define MP4_POS_H264_BASE                       0x70
#define MP4_POS_H264_PROF_IND                   MP4_POS_H264_BASE           // for H.264 (AVCProfileIndication)
#define MP4_POS_H264_PROF_COMPAT                (MP4_POS_H264_BASE + 0x1)   // for H.264 (ProfileCompatibility)
#define MP4_POS_H264_LEVLE_IND                  (MP4_POS_H264_BASE + 0x2)   // for H.264 (AVCLevelIndication)
#define MP4_POS_H264_LEN_SIZE                   (MP4_POS_H264_BASE + 0x3)   // for H.264 (LengthSizeMinusOne)
#define MP4_POS_H264_NUM_OF_SPS                 (MP4_POS_H264_BASE + 0x4)   // for H.264 (Number_of_SPS)
#define MP4_POS_H264_NUM_OF_PPS                 (MP4_POS_H264_BASE + 0x5)   // for H.264 (Number_of_PPS)
#define MP4_POS_H264_MAX_SIZE                   (MP4_POS_H264_BASE + 0x6)

#define MP4_POS_RECORD_STATUS                   0x80
#define MP4_POS_PROCESS_STOP_TIME_STATUS        0x84

#define MP4_POS_VOS_DATA                        0x200                       // Extend the header of the temporary meta file 2KB for cluster alignment in NAND.
#define MP4_POS_END                             0x600                       // offset: 1536 bytes
#define MP4_POS_VOS_LENGTH                      (MP4_POS_END - 0x4)         // Extend the header of the temporary meta file 2KB for cluster alignment in NAND.

#define MP4_A_FRAMEINFO_COUNT                   MP4_POS_END
#define MP4_A_FRAMEINFO_START                   (MP4_POS_END + 0x4)

#define MP4_VOS_LENGTH                          4       // Size of MP4_POS_VOS_LENGTH

#define MP4_MAX_SPS_SIZE                        100
#define MP4_MAX_PPS_SIZE                        100

/******************************************************************************
* Structure Definition
******************************************************************************/
// Describe one frame's info
typedef struct
{
    kal_bool    fgFirstFrame;           // Is this frame the first frame?
    kal_bool    fgSyncFrame;            // Is this frame a I frame?
    kal_uint32  u4FrameSize;            // size of the frame
    kal_uint64  u8TimeStamp;            // time-stamp of the frame
} MP4_FRAME_INFO_T;

typedef struct
{
    kal_uint32 *pu4Data;                // of size MP4_STTS_ARRAY_SIZE_IN_BYTE
    kal_uint32 u4ReadWordIdx;           // Read index in word
    kal_uint32 u4WriteWordIdx;          // Write index in word
    kal_uint32 u4UsedSize;              // How many bytes are in the array?
    kal_uint32 u4WrittenSize;           // How many bytes have been written?
    kal_bool fgFlushBox;
    kal_uint32 u4TotalSize;
    kal_uint32 u4BoxSize;               // Box content: size of the box
    kal_uint32 u4SampleCount;           // Box content: it is equal to u4TotalFrames
    kal_uint32 u4EntryCount;             // Box content: entry size
}MP4_STBL_BOX_BUFFER_MGR_T;

typedef struct
{
    kal_uint32 u4PrevFrameSize;
    kal_uint32 u4FrameCount;
    kal_uint32 u4TotalFrameCount;
    kal_uint32 u4FilePos;
    kal_uint32 u4MaxFrameCount;
}MP4_AUDIO_STBL_MGR_T;

union BoxData
{
    kal_uint8 au1Moov[MOOV_SIZE];
    kal_uint8 au1Iuam[IUAM_SIZE];
    kal_uint8 au1Mvhd[MVHD_SIZE];
    kal_uint8 au1Iods[IODS_SIZE];
    kal_uint8 au1Trak[TRAK_SIZE];
    kal_uint8 au1Tkhd[TKHD_SIZE];
    kal_uint8 au1Mdia[MDIA_SIZE];
    kal_uint8 au1Mdhd[MDHD_SIZE];
    kal_uint8 au1Hdlr[HDLR_SIZE];
    kal_uint8 au1Minf[MINF_SIZE];
    kal_uint8 au1Vmhd[VMHD_SIZE];
    kal_uint8 au1Smhd[SMHD_SIZE];
    kal_uint8 au1Dinf[DINF_SIZE];
    kal_uint8 au1Stbl[STBL_SIZE];
    kal_uint8 au1Stsd[STSD_MAX_SIZE];
    kal_uint8 au1Stsc[STSC_MAX_SIZE];
    kal_uint8 au1Stts[STTS_MAX_SIZE];
    kal_uint8 au1Stsz[STSZ_MAX_SIZE];
    kal_uint8 au1Stco[STCO_MAX_SIZE];
};

#define DEFAULT_VIDEO_BOX_SIZE  (MOOV_SIZE + MVHD_SIZE + IODS_SIZE +    \
                                 TRAK_SIZE + TKHD_SIZE + MDIA_SIZE +    \
                                 MDHD_SIZE + HDLR_SIZE + MINF_SIZE +    \
                                 VMHD_SIZE + DINF_SIZE + STBL_SIZE + IUAM_SIZE)

#define DEFAULT_AUDIO_BOX_SIZE  (TRAK_SIZE + TKHD_SIZE + MDIA_SIZE +    \
                                 MDHD_SIZE + HDLR_SIZE + MINF_SIZE +    \
                                 SMHD_SIZE + DINF_SIZE + STBL_SIZE)


#define MIN_VIDEO_STBL_SIZE     (STSD_MAX_SIZE + STSC_MIN_SIZE + STTS_MIN_SIZE + STSZ_MIN_SIZE + STCO_MIN_SIZE)
#define MIN_AUDIO_STBL_SIZE     (STSD_A_SIZE + STSC_MIN_SIZE + STTS_MIN_SIZE + STSZ_MIN_SIZE + STCO_MIN_SIZE)

typedef struct
{
    union BoxData   uBoxData;
    kal_uint32      u4CreateTime;
    kal_uint32      u4TimeScale;
    enum TrakType   eTrakType;

    kal_uint32      u4TrakID;
    kal_uint32      u4VCodec;
    kal_uint32      u4Width;
    kal_uint32      u4Height;
    kal_uint32      u4VDuration;
#ifdef __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
    MUXER_ROTATION_ANGLE_T eRotateAngle;
    kal_bool        fgHorizontallyMirror;
#endif

    kal_uint32      u4ACodec;
    kal_uint32      u4AFrameCount;
    kal_uint32      u4ADuration;
    kal_uint32      u4ASamplePerFrame;
    kal_uint32      u4ASampleSize;
    kal_uint32      u4ATimeScale;
    kal_uint32      u4AudioDataOffset;

    kal_uint32      u4ClusterSize;
    kal_uint32      u4STBLReservedSize;
    kal_bool        fgUsePseudoMerge;
}MP4_BOX_MGR_T;

/******************************************************************************
* STTS - for STTS buffer management
******************************************************************************/
#define MP4_STTS_ARRAY_SIZE_IN_WORD          (MP4_STTS_ARRAY_SIZE_IN_BYTE >> 2)
#define MP4_STTS_ARRAY_THRESHOLD_IN_BYTE     (MP4_STTS_ARRAY_SIZE_IN_BYTE >> 1)
#define MP4_STTS_SIZE_OFFSET_IN_BYTE         0
#define MP4_STTS_TYPE_OFFSET_IN_BYTE         4
#define MP4_STTS_FLAGS_OFFSET_IN_BYTE        8
#define MP4_STTS_ENTRY_COUNT_OFFSET_IN_BYTE  12
#define MP4_STTS_HEADER_SIZE_IN_BYTE         16      /* size + box_type + ver_flags + entry_count */
#define MP4_STTS_ENTRY_DATA_SIZE_IN_BYTE     8       /* sample_count + sample_delta */
#define MP4_STTS_SIZE_OFFSET_IN_WORD         (MP4_STTS_SIZE_OFFSET_IN_BYTE >> 2)
#define MP4_STTS_TYPE_OFFSET_IN_WORD         (MP4_STTS_TYPE_OFFSET_IN_BYTE >> 2)
#define MP4_STTS_FLAGS_OFFSET_IN_WORD        (MP4_STTS_FLAGS_OFFSET_IN_BYTE >> 2)
#define MP4_STTS_ENTRY_COUNT_OFFSET_IN_WORD  (MP4_STTS_ENTRY_COUNT_OFFSET_IN_BYTE >> 2)
#define MP4_STTS_HEADER_SIZE_IN_WORD         (MP4_STTS_HEADER_SIZE_IN_BYTE >> 2)
#define MP4_STTS_ENTRY_DATA_SIZE_IN_WORD     (MP4_STTS_ENTRY_DATA_SIZE_IN_BYTE >> 2)
#define MP4_STTS_SIZE_FILE_OFFSET            0
#define MP4_STTS_ENTRY_COUNT_FILE_OFFSET     12

typedef struct
{
    MP4_STBL_BOX_BUFFER_MGR_T rBufferMgr;
    kal_uint64 u8PrevTimeStamp;
    kal_uint32 u4SampleDelta;           // Box content: the time delta of the consecutive frames
    kal_bool fgGotFirstFrame;           // Has the first frame been received?
    kal_bool fgHasFirstDelta;           // The first delta has been computed.
} MP4_STTS_BOX_T;

/******************************************************************************
* STSC - for STSC management
******************************************************************************/
typedef struct
{
    kal_uint32 u4SampleCount;
} MP4_STSC_BOX_T;

/******************************************************************************
* STSZ - for STSZ buffer management
******************************************************************************/
#define MP4_STSZ_ARRAY_SIZE_IN_WORD          (MP4_STSZ_ARRAY_SIZE_IN_BYTE >> 2)
#define MP4_STSZ_ARRAY_THRESHOLD_IN_BYTE     (MP4_STSZ_ARRAY_SIZE_IN_BYTE >> 1)
#define MP4_STSZ_SIZE_OFFSET_IN_BYTE         0
#define MP4_STSZ_TYPE_OFFSET_IN_BYTE         4
#define MP4_STSZ_FLAGS_OFFSET_IN_BYTE        8
#define MP4_STSZ_SAMPLE_SIZE_OFFSET_IN_BYTE  12
#define MP4_STSZ_SAMPLE_COUNT_OFFSET_IN_BYTE 16
#define MP4_STSZ_HEADER_SIZE_IN_BYTE         20      /* size + box_type + ver_flags + sample_size + sample_count */
#define MP4_STSZ_ENTRY_DATA_SIZE_IN_BYTE     4       /* entry_size */
        // array offset
#define MP4_STSZ_SIZE_OFFSET_IN_WORD         (MP4_STSZ_SIZE_OFFSET_IN_BYTE >> 2)
#define MP4_STSZ_TYPE_OFFSET_IN_WORD         (MP4_STSZ_TYPE_OFFSET_IN_BYTE >> 2)
#define MP4_STSZ_FLAGS_OFFSET_IN_WORD        (MP4_STSZ_FLAGS_OFFSET_IN_BYTE >> 2)
#define MP4_STSZ_SAMPLE_SIZE_OFFSET_IN_WORD  (MP4_STSZ_SAMPLE_SIZE_OFFSET_IN_BYTE >> 2)
#define MP4_STSZ_SAMPLE_COUNT_OFFSET_IN_WORD (MP4_STSZ_SAMPLE_COUNT_OFFSET_IN_BYTE >> 2)
#define MP4_STSZ_HEADER_SIZE_IN_WORD         (MP4_STSZ_HEADER_SIZE_IN_BYTE >> 2)
#define MP4_STSZ_ENTRY_DATA_SIZE_IN_WORD     (MP4_STSZ_ENTRY_DATA_SIZE_IN_BYTE >> 2)
        // File offset
#define MP4_STSZ_SIZE_FILE_OFFSET            MP4_STSZ_SIZE_OFFSET_IN_BYTE
#define MP4_STSZ_SAMPLE_SIZE_FILE_OFFSET     MP4_STSZ_SAMPLE_SIZE_OFFSET_IN_BYTE
#define MP4_STSZ_SAMPLE_COUNT_FILE_OFFSET    MP4_STSZ_SAMPLE_COUNT_OFFSET_IN_BYTE

typedef struct
{
    MP4_STBL_BOX_BUFFER_MGR_T rBufferMgr;
    kal_bool fgGotFirstFrame;           // Has the first frame been received?
} MP4_STSZ_BOX_T;

/******************************************************************************
* STCO - for STCO buffer management
******************************************************************************/
#define MP4_STCO_ARRAY_SIZE_IN_WORD          (MP4_STCO_ARRAY_SIZE_IN_BYTE >> 2)
#define MP4_STCO_ARRAY_THRESHOLD_IN_BYTE     (MP4_STCO_ARRAY_SIZE_IN_BYTE >> 1)
#define MP4_STCO_SIZE_OFFSET_IN_BYTE         0
#define MP4_STCO_TYPE_OFFSET_IN_BYTE         4
#define MP4_STCO_FLAGS_OFFSET_IN_BYTE        8
#define MP4_STCO_ENTRY_COUNT_OFFSET_IN_BYTE  12
#define MP4_STCO_HEADER_SIZE_IN_BYTE         16      /* size + box_type + ver_flags + entry_count */
#define MP4_STCO_ENTRY_DATA_SIZE_IN_BYTE     4       /* chunk_offset */
        // array offset
#define MP4_STCO_SIZE_OFFSET_IN_WORD         (MP4_STCO_SIZE_OFFSET_IN_BYTE >> 2)
#define MP4_STCO_TYPE_OFFSET_IN_WORD         (MP4_STCO_TYPE_OFFSET_IN_BYTE >> 2)
#define MP4_STCO_FLAGS_OFFSET_IN_WORD        (MP4_STCO_FLAGS_OFFSET_IN_BYTE >> 2)
#define MP4_STCO_ENTRY_COUNT_OFFSET_IN_WORD  (MP4_STCO_ENTRY_COUNT_OFFSET_IN_BYTE >> 2)
#define MP4_STCO_HEADER_SIZE_IN_WORD         (MP4_STCO_HEADER_SIZE_IN_BYTE >> 2)
#define MP4_STCO_ENTRY_DATA_SIZE_IN_WORD     (MP4_STCO_ENTRY_DATA_SIZE_IN_BYTE >> 2)
        // file offset
#define MP4_STCO_SIZE_FILE_OFFSET            MP4_STCO_SIZE_OFFSET_IN_BYTE
#define MP4_STCO_ENTRY_COUNT_FILE_OFFSET     MP4_STCO_ENTRY_COUNT_OFFSET_IN_BYTE
#define MP4_BIT_STREAM_FILE_OFFSET_IN_BYTE   0x20

#define MP4_VSAMPLES_PER_CHUNK                  30
#define MP4_ASAMPLES_PER_CHUNK                  25

typedef struct
{
    MP4_STBL_BOX_BUFFER_MGR_T rBufferMgr;
    kal_uint32 u4ChunkOffset;           // Box content: chunk offset
    kal_bool fgGotFirstFrame;           // Has the first frame been received?
} MP4_STCO_BOX_T;

/******************************************************************************
* STSS - for STSS buffer management
******************************************************************************/
#define MP4_STSS_ARRAY_SIZE_IN_WORD          (MP4_STSS_ARRAY_SIZE_IN_BYTE >> 2)
#define MP4_STSS_ARRAY_THRESHOLD_IN_BYTE     (MP4_STSS_ARRAY_SIZE_IN_BYTE >> 1)
#define MP4_STSS_SIZE_OFFSET_IN_BYTE         0
#define MP4_STSS_TYPE_OFFSET_IN_BYTE         4
#define MP4_STSS_FLAGS_OFFSET_IN_BYTE        8
#define MP4_STSS_ENTRY_COUNT_OFFSET_IN_BYTE  12
#define MP4_STSS_HEADER_SIZE_IN_BYTE         16      /* size + box_type + ver_flags + entry_count */
#define MP4_STSS_ENTRY_DATA_SIZE_IN_BYTE     4       /* sample_number */
        // array offset
#define MP4_STSS_SIZE_OFFSET_IN_WORD         (MP4_STSS_SIZE_OFFSET_IN_BYTE >> 2)
#define MP4_STSS_TYPE_OFFSET_IN_WORD         (MP4_STSS_TYPE_OFFSET_IN_BYTE >> 2)
#define MP4_STSS_FLAGS_OFFSET_IN_WORD        (MP4_STSS_FLAGS_OFFSET_IN_BYTE >> 2)
#define MP4_STSS_ENTRY_COUNT_OFFSET_IN_WORD  (MP4_STSS_ENTRY_COUNT_OFFSET_IN_BYTE >> 2)
#define MP4_STSS_HEADER_SIZE_IN_WORD         (MP4_STSS_HEADER_SIZE_IN_BYTE >> 2)
#define MP4_STSS_ENTRY_DATA_SIZE_IN_WORD     (MP4_STSS_ENTRY_DATA_SIZE_IN_BYTE >> 2)
        // file offset
#define MP4_STSS_SIZE_FILE_OFFSET            MP4_STSS_SIZE_OFFSET_IN_BYTE
#define MP4_STSS_ENTRY_COUNT_FILE_OFFSET     MP4_STSS_ENTRY_COUNT_OFFSET_IN_BYTE

typedef struct
{
    MP4_STBL_BOX_BUFFER_MGR_T rBufferMgr;
    kal_bool fgGotFirstFrame;           // Has the first frame been received?
} MP4_STSS_BOX_T;

typedef struct
{
    MP4_STTS_BOX_T  rStts;
    MP4_STSC_BOX_T  rStsc;
    MP4_STSZ_BOX_T  rStsz;
    MP4_STCO_BOX_T  rStco;
    MP4_STSS_BOX_T  rStss;
    kal_uint32 u4TotalDuration;
    kal_uint32 u4ClusterSize;
} MP4_VIDEO_STBL_MGR_T;

typedef struct
{
	kal_uint32 u4DefaultBoxSize;
	kal_uint32 u4SttsBoxSize;
	kal_uint32 u4StszBoxSize;
	kal_uint32 u4StcoBoxSize;
	kal_uint32 u4StssBoxSize;
} MP4_GET_BOX_SIZE_T;

/******************************************************************************
* Exported API
******************************************************************************/
// Init
extern void MP4_InitMeta(kal_bool fgRecording);
extern void MP4_DeInitMeta(kal_bool fgRecording);

// Temp Meta
extern VIDEO_ERROR_TYPE_T MP4_WriteMeta(STFSAL * const prFileHandle, const kal_uint32 u4Offset, const kal_uint32 u4Size, kal_uint8 *const pu1Data);
extern VIDEO_ERROR_TYPE_T MP4_ReadMeta(STFSAL *const prFileHandle, const kal_uint32 u4Offset, const kal_uint32 u4Size, kal_uint8 *const pu1Data);
extern VIDEO_ERROR_TYPE_T MP4_WriteH264Configuration(STFSAL *const prFileHandle, void * const pPrivateData);

// Video
extern VIDEO_ERROR_TYPE_T MP4_GenVideoFileHeader(STFSAL *const prFSALVideo, STFSAL *const prFSALTmpMeta, kal_uint32 *const pu4BitStreamOffset);

// STBL
extern VIDEO_ERROR_TYPE_T MP4_STBL_AddOneVFrame(MP4_FRAME_INFO_T *const prFrameInfo);
extern kal_bool MP4_STBL_HasData2Write(void);
extern VIDEO_ERROR_TYPE_T MP4_STBL_WriteData(MP4_FILE_MGR_T *const prMp4FileMgr);
extern VIDEO_ERROR_TYPE_T MP4_STBL_FlushData(MP4_FILE_MGR_T *const prMp4FileMgr);
extern VIDEO_ERROR_TYPE_T MP4_STBL_SettleDown(MP4_FILE_MGR_T *const prMp4FileMgr);
extern VIDEO_ERROR_TYPE_T MP4_STBL_AddOneAFrame(MP4_FILE_MGR_T *const prMp4FileMgr, kal_uint32 u4FrameSize);
extern void MP4_GetVideoBoxSize(MP4_GET_BOX_SIZE_T *const pParam);
extern kal_uint32 MP4_GetAudioBoxSize(const kal_uint32 u4ReservedAudioFrameCount);
extern kal_uint32 MP4_GetAudioFrameCount(void);
extern kal_uint32 MP4_GetVideoDuration(void);
extern void MP4_SetAudioTimeLimit(kal_uint32 u4AudioFrameCount);
extern kal_uint32 MP4_GetTempFileSize(void);

// Audio
extern VIDEO_ERROR_TYPE_T MP4_GenAudioFileHeader(STFSAL *const prAudioHandle);
extern VIDEO_ERROR_TYPE_T MP4_ParseAMRHeader(kal_uint8 u1AMRType, kal_uint8 u1FrameHeader, kal_uint8 *pu1FrameLength);

extern VIDEO_ERROR_TYPE_T MP4_CreateMetaFile(MP4_FILE_MGR_T *const prMp4FileMgr, const kal_bool fgUsePseudoMerge, const kal_uint32 u4ClusterSize, const kal_bool fgRecordAudio, const kal_uint32 u4VideoFileSize);

#endif  // __MP4_MUXER_ADAPTER_META_CREATION_V2_H
