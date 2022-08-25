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
 *
 * Filename:
 * ---------
 *   mp4_decore_v2.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video decode core definitions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MP4_DECORE_V2_H
#define MP4_DECORE_V2_H

#include "drv_comm.h"
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_DEC_HW_SUPPORT__

#include "kal_general_types.h"
#include "kal_public_defs.h"

#define VO_START_CODE              0x8
#define VO_START_CODE_MIN          0x100
#define VO_START_CODE_MAX          0x11f

#define VOL_START_CODE              0x12
#define VOL_START_CODE_MIN          0x120
#define VOL_START_CODE_MAX          0x12f

#define VOS_START_CODE           0x1b0
#define VOS_END_CODE             0x1b1
#define USR_START_CODE           0x1b2
#define GOP_START_CODE           0x1b3
#define VSO_START_CODE           0x1b5
#define VOP_START_CODE             0x1b6
#define STF_START_CODE           0x1c3 // stuffing_start_code
#define SHV_START_CODE           0x020
#define SHV_END_MARKER           0x03f

#define I_VOP                       0
#define P_VOP                       1
#define B_VOP                       2
#define S_VOP                       3

#define MP4_DECODE_FAILED                0        // The frame is decoded failed due to H/W report error
#define MP4_DECODE_OK                    1        // The frame is decode succesfully
#define MP4_DECODE_OK_BYPASS            2        // The frame is NOT decoded directly, use previous frame
#define MP4_DECODE_FAILED_TIMEOUT    3        // The frame is decoded failed due to timeout
#define MP4_DECODE_FAILED_VLC_LIMIT    4        // The frame is decoded failed due to VLC limit reached
#define MP4_DECODE_BYPASS_PIPELINE    5        // HW is not triggered due to pipeline initial stage
#define MP4_DECODE_BYPASS_EOF    6        // HW is not triggered due EOF received without pipeline stage triggered

#define MP4_HW_DEC_COMPLETE 0x00000001
#define MP4_HW_DEC_EOF_CODE 0x721012

// Allow the maximum decoded frame width, this is software definition
#define MP4_DEC_MAX_FRAME_WIDTH            720
// Allow the maximum decoded frame height, this is software definition
#define MP4_DEC_MAX_FRAME_HEIGHT           480
// Allow the maximum decoded frame width, this is chip limitation
#define MP4_CHIP_DEC_MAX_FRAME_WIDTH       720
// Allow the maximum decoded frame height, this is chip limitation
#define MP4_CHIP_DEC_MAX_FRAME_HEIGHT      480
// Slim mode max frame width
#define MP4_SLIM_MODE_MAX_FRAME_WIDTH      352
// Slim mode max frame height
#define MP4_SLIM_MODE_MAX_FRAME_HEIGHT     288

// Quantization scale, (external memory)
#define MP4_DEC_QS_WORK_SIZE(_FRAME_WIDTH,_FRAME_HEIGHT) \
    (((((_FRAME_WIDTH+15)/16)+3)>>2)*4*((_FRAME_HEIGHT+15)/16))

// DACP + DATA STORE + Motion Vector Storage (internal memory)
#define MP4_DEC_MAX_WORK_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT) \
    (4096+(((_FRAME_WIDTH*_FRAME_HEIGHT+255)/256)*32)+360)

typedef enum
{
    VIDEO_MP4_DEC_PARAM_WIDTH,
    VIDEO_MP4_DEC_PARAM_HEIGHT,
    VIDEO_MP4_DEC_PARAM_REAL_WIDTH,
    VIDEO_MP4_DEC_PARAM_REAL_HEIGHT,
    VIDEO_MP4_DEC_PARAM_EXT_MEM_SIZE,
    VIDEO_MP4_DEC_PARAM_INT_MEM_SIZE,
    VIDEO_MP4_DEC_PARAM_MAX_WIDTH,
    VIDEO_MP4_DEC_PARAM_MAX_HEIGHT,
    VIDEO_MP4_DEC_PARAM_MAX_SIZE,
    VIDEO_MP4_DEC_PARAM_PROFILE,
    VIDEO_MP4_DEC_PARAM_LEVEL,
    VIDEO_MP4_DEC_PARAM_EXT_MEM_ADDR,
    VIDEO_MP4_DEC_PARAM_INT_MEM_ADDR
}MPEG4_DEC_PARAM_TYPE;

typedef enum
{
    VIDEO_MP4_PARSE_VOS_RDY,
    VIDEO_MP4_PARSE_VOS_RDY_WITH_VOP,
    VIDEO_MP4_PARSE_SHR_HDR_RDY,
    VIDEO_MP4_PARSE_VOS_ERR,
    VIDEO_MP4_PARSE_SHR_HDR_ERR,
    VIDEO_MP4_PARSE_UNKNOWN_ERR
}MPEG4_HDR_PARSE_STATUS;

typedef struct
{
    MPEG4_HDR_PARSE_STATUS eStatus;
    kal_int32 i4bitcnt;
}mp4_dec_parse_param;

typedef enum
{
    MPEG4_SIMPLE = 0,
    MPEG4_ADVANCED_SIMPLE
} MPEG4Profile;

typedef enum
{
    MPEG4_LEVEL0 = 0,
    MPEG4_LEVEL1,
    MPEG4_LEVEL2,
    MPEG4_LEVEL3
} MPEG4Level;

/* these information is obtained from bitstream parser */
typedef struct
{
    // Frame width, 16 aligned
    kal_uint16 width;
    // Frame height, 16 aligned
    kal_uint16 height;
    // VOL width
    kal_uint16 real_width;
    // VOL height
    kal_uint16 real_height;
    // This is an 8-bit integer used to signal the profile and level identification
    kal_uint8 version;
    // 0: intra coded(I), 01: predictive-coded (P)
    kal_uint8 vop_coding_type;
    // Used inverse quantisation type to inverse quantisation of the DCT coefficients.
    kal_uint8 quant_type;
    // '1' indicates that the macroblock data is rearranged differently, specifically,
    // motion vector data is separated from the texture data (i.e., DCT coefficients)
    kal_uint8 data_partitioned;
    // '1' indicates that the reversible variable length tables
    // (Table B?23, Table B?24 and Table B?25) should be used
    kal_uint8 resversible_vlc;
    // H.263 or not
    kal_uint8 short_video_header;
    // vop_fcode_forward, values from 1 to 7; the value of zero is forbidden.
    // It is used in decoding of motion vectors.
    kal_uint8 fcode;
    // Signals the value of the parameter rounding_control used for pixel
    // value interpolation in motion compensation for P-VOPs.
    kal_uint8 rounding_code;
    // Specify the absolute value of quantiser scale to be used for inverse quantising the
    // macroblock until updated by any subsequent dquant, dbquant, or quant_scale.
    kal_uint8 vop_quant;
    // The value of this internal flag is set to 1 when the values of intra_dc_thr
    // and the DCT quantiser indicate the usage of the intra DC VLCs as shown in Table 6?21.
    // Otherwise, the value of this flag is set to 0.
    kal_uint8 intra_dc_vlc_thr;
    // vop_time_increment_resolution, indicates the number of evenly spaced subintervals,
    // called ticks, within one modulo time. One modulo time represents the fixed interval
    // of one second. The value zero is forbidden.
    kal_uint16 time_increment_resolution;
    // This value represents the absolute vop_time_increment from the
    // synchronization point marked by the modulo_time_base measured
    // in the number of clock ticks. It can take a value in the range
    // of [0,vop_time_increment_resolution)
    kal_uint16 vop_time_increment;
    // old value of vop time increment
    kal_uint16 old_vop_time_increment;
    // when set to '0' indicates that no subsequent data exists for the VOP
    kal_uint8 vop_coded;
    // time base
    kal_uint8 time_base;
    // temp temp base
    kal_uint8 old_time_base;
    // 1' indicates that there is no resync_marker in coded VOPs
    kal_uint8 resync_marker_disable;
    // =1, may contain interlaced video. =0, are non-interlanced video.
    kal_uint8 interlaced;
    // The value of this internal flag is set to 1 when the values of intra_dc_thr
    // and the DCT quantiser indicate the usage of the intra DC VLCs as shown in Table 6?21.
    // Otherwise, the value of this flag is set to 0.
    kal_uint8 use_intra_dc_vlc;
    // =log2(hdr.height * hdr.width/(16*16))
    kal_uint8 mblength;
    // =Log2(vop_time_increment)
    kal_uint8 time_increment_length;
    kal_bool b_fixed_vop_rate;
    kal_uint32 fixed_vop_time_increment;
    kal_uint32 time_increment;

    kal_uint32 temporal_reference;
    kal_uint32 old_temporal_reference;

    kal_uint8 b_source_format;
} m4v_dec_im_v2;

typedef struct
{
    kal_uint8* int_mem_addr;
    kal_uint32 int_mem_size;
    kal_uint8* ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint32 max_width;
    kal_uint32 max_height;
}mp4_dec_init_param;

typedef struct
{
    kal_uint8* bitstream_addr;
    kal_uint32 bitstream_length;
    kal_uint8* yuv_addr;
    kal_uint8* ref_addr; // reference buffer for 1st frame
    kal_bool fgIsEOF; // Set EOF to retrieve last frame
}mp4_dec_decode_input_param;

typedef struct
{
    kal_uint8* bitstream_addr;
    kal_uint32 bitstream_length;
    kal_uint8* disp_yuv_addr;
    kal_uint8* free_ref_yuv_addr; // frame buffer to be reference free
    kal_uint32 u4result;
    kal_uint8 u1_vop_coding_type;
}mp4_dec_decode_output_param;

typedef struct
{
    kal_uint8 *p_int_mem_addr;
    kal_uint32 int_mem_size;
    kal_uint8 *p_ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint32 max_width;
    kal_uint32 max_height;

    m4v_dec_im_v2 dec_hdr;

    kal_bool b_dec_header_parsed;
    kal_uint8 *p_dec_working_buffer;
    kal_uint8 *p_dec_deblock_buffer;
    kal_uint8 *p_dec_dacp_addr;
    kal_uint8 *p_dec_store_addr;
    kal_uint8 *p_dec_mvp_addr;
    kal_uint8 *p_dec_qs_addr;

    kal_uint8 *p_prev_dec_ref_addr; // Previous dec, current ref
    kal_uint8 *p_bitstream_buffer;
    kal_uint32 bistream_length;
    kal_uint8 *p_reconstruct_buffer;
    kal_int32 bitcnt_offset;

    // To decode twice
    kal_uint32 resume_vlc_limit;
    kal_uint32 resume_vlc_addr;

    kal_int32 decode_err_cnt;
    kal_eventgrpid eDecodeComplete;
    kal_uint32 decode_result;

    #if 1
    kal_timerid rTimerID; // To avoid H/W no response
    #else
/* under construction !*/
    #endif
}mp4_dec_info;

typedef struct
{
    kal_bool (*init)(void *param);
    kal_uint32 (*decode)(void *in_param, void *out_param);
    mp4_dec_parse_param (*parseVOS)(void *param);
    kal_bool (*get_param)(MPEG4_DEC_PARAM_TYPE type, kal_uint32 *p_value);
    kal_bool (*set_param)(MPEG4_DEC_PARAM_TYPE type, void *p_param);
    void (*flush)(void);
    void (*deinit)(void);
}MP4_DEC_DRIVER;


extern void mpeg4_dec_reset(void);
extern void mpeg4_core_reset(void);

/* function prototype for memory allocation */
void *MPEG4HwDecMalloc(unsigned int size);

/* function prototype for memory free*/
void MPEG4HwDecFree(void *ptr);

MP4_DEC_DRIVER* GetMPEG4HwDecHandle(void);

#define MPEG4HWDECDEBUG // MPEG4 HW solution decoder debug

#endif /* __VE_MPEG4_DEC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /*MP4_DECORE_V2_H*/

