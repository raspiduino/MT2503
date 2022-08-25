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
 *   mpeg4_hw_encore_v2.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file declares the core of mpeg4 encode
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MPEG4_HW_ENCORE_V2_H
#define MPEG4_HW_ENCORE_V2_H

#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_ENC_HW_SUPPORT__

#include "mp4_rc_v2.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"

#define ENC_BLOCKING 1

// Maximum encode internal (working) memory
// #define ENC_MAX_INT_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)     (3072+1024+328 + (_FRAME_WIDTH*(56+32)) + (3*16*16))
// Maximum encode internal (working) memory
// #define ENC_MAX_EXT_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)     (_FRAME_WIDTH * _FRAME_HEIGHT * 3) // W x H x 1.5 x 2
// Maximum VOS size (bytes)
#define ENC_MAX_VOS_SIZE            40
// Maximum VOP size (bytes)
#define ENC_MAX_VOP_SIZE            25
// Minimum size to encode one frame in VT
#define ENC_MIN_BUF_SIZE_VT         2048
// Maximum packet number within one frame
#define ENC_MAX_PACKET_NUMBER       99
// Default MPEG4 HW encoder intra period
#define ENC_DEFAULT_INTRA_PERIOD    128

#if ENC_BLOCKING
#define MP4_HW_ENC_COMPLETE 0x00000001
#endif

typedef enum
{
    MPEG4_ENCORE_I_VOP = 0,
    MPEG4_ENCORE_P_VOP,
    MPEG4_ENCORE_B_VOP,
    MPEG4_ENCORE_HEADER,
    MPEG4_ENCORE_MAX
} MPEG4_ENCORE_BITS_TYPE;

typedef enum
{
    MPEG4_ENCORE_STATE_OPEN,
    MPEG4_ENCORE_STATE_CLOSE,
    MPEG4_ENCORE_STATE_INIT,
    MPEG4_ENCORE_STATE_PAUSE,
    MPEG4_ENCORE_STATE_RUN,
    MPEG4_ENCORE_STATE_MAX
}MPEG4_ENCORE_STATE;

typedef enum
{
    MPEG4_ENCORE_PARAM_WIDTH,
    MPEG4_ENCORE_PARAM_HEIGHT,
    MPEG4_ENCORE_PARAM_BITRATE,
    MPEG4_ENCORE_PARAM_FRAME_RATE,
    MPEG4_ENCORE_PARAM_SHORT_HEADER,
    MPEG4_ENCORE_SYNC_INTERVAL,
    MPEG4_ENCORE_PARAM_MEMORY_REQUIREMENT,
    MPEG4_ENCORE_PARAM_MAX_PKG_SIZE,
    MPEG4_ENCORE_FORCE_ENCODE_I,
    MPEG4_ENCORE_PARAM_SCENARIO,
    //MPEG4_ENCORE_PARAM_QUALITY,
    //MPEG4_ENCORE_CODEC_TYPE,
    //MPEG4_ENCORE_PARAM_BITSTREAM_BUFFER_CACHEABLE,
    MPEG4_ENCORE_TIME_INCREMENT,
    MPEG4_ENCORE_PARAM_MAX_ENUM
}MPEG4_ENCORE_PARAM_TYPE;

typedef enum
{
    MPEG4_ENCORE_SCENARIO_REC,
    MPEG4_ENCORE_SCENARIO_VT,
    MPEG4_ENCORE_SCENARIO_MAX
} MPEG4_ENCORE_SCENARIO;

typedef struct
{
    kal_uint8* int_mem_addr;
    kal_uint32 int_mem_size;
    kal_uint8* ext_mem_addr;
    kal_uint32 ext_mem_size;
    kal_uint8* res_mem_addr;
    kal_uint32 res_mem_size;
}MPEG4_ENCORE_MEM_INFO;

typedef struct
{
    kal_uint32 u4Addr;
    kal_uint32 u4Size;
} MPEG4_ENCORE_PKT_INFO;

typedef struct
{
    kal_bool   drop;
    kal_bool   took_away;
    kal_bool   encode_done;
    kal_uint8* start_ptr;
    kal_int32  fcode;
    kal_uint32 total_len;
    kal_uint32 took_idx;
    kal_uint32 pkt_num;
    MPEG4_ENCORE_BITS_TYPE bits_type;
    MPEG4_ENCORE_PKT_INFO  pkt_info[ENC_MAX_PACKET_NUMBER];
}MPEG4_ENCORE_FRAME_INFO;

typedef struct
{
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 bit_rate;
    kal_uint32 frame_rate;
    kal_uint32 i_interval;
    kal_uint32 max_pkt_size;
    kal_bool   short_header;

    // RC variables
    kal_int32  pixels_per_frame;
    kal_uint32 cbr_func_para1;
    kal_uint32 cbr_func_para2;
    kal_uint32 cbr_func_para3;
    kal_bool   b_is_cbr;

    /// store the intra frame number.
    kal_int32   intra_num;
    /// I_VOP or P_VOP
    MPEG4_ENCORE_BITS_TYPE   predition_type;
    /// This value represents the absolute vop_time_increment from the
    /// synchronization point marked by the modulo_time_base measured
    /// in the number of clock ticks. It can take a value in the range
    /// of [0,vop_time_increment_resolution)
    kal_int32   vop_time_increment;
    kal_int32   fixed_vop_time_increment;
    /// vop_time_increment_resolution, indicates the number of evenly spaced subintervals,
    /// called ticks, within one modulo time. One modulo time represents the fixed interval
    /// of one second. The value zero is forbidden.
    kal_int32   time_increment;
    kal_uint64  u8TimeStamp;
    kal_int32   prev_u8TimeStamp;

    /// quantizer value
    kal_int32   quantizer;
    kal_uint32  intra_threshold;
    /// vop_fcode_forward, values from 1 to 7; the value of zero is forbidden.
    /// It is used in decoding of motion vectors.
    kal_int32   fcode;
    kal_int32   time_base;
    kal_bool    b_resync_marker;
    kal_int32   prev_vop_time_increment;

    // for VT CBR rate control
    kal_uint32  mbrc_q_sum;
    kal_uint32  mbrc_thre; 			//cbr_thre4
    kal_uint32  mb_bit_budget;		//CBR_mb_bitbudget;
    kal_uint32  mbq_lb;
    kal_uint32  mbq_ub;
    CBR_DCT_LEV_STRUCT cbr_dct_lev;
    kal_bool    is_drop_nxt_frm;		//this is actually not for HW, for notifying system only
    kal_bool    is_encode_i_nxt_frm;

}MPEG4_ENCODER_INFO;

typedef struct
{
    MPEG4_ENCORE_STATE state;
    MPEG4_ENCORE_SCENARIO scenario;
    kal_uint8* int_mem_addr; // hardware configuration working memory
    kal_uint32 int_mem_size;
    kal_uint8* ext_mem_addr; // hardware ref&rec frames working memory
    kal_uint32 ext_mem_size;
    kal_uint8* res_mem_addr; // hardware resume encoding memory
    kal_uint32 res_mem_size;

    kal_bool   force_i_frame;
    kal_uint8* bits_buffer_end;
    kal_uint8* bits_trigger_limit;
    kal_uint32 total_saved_bytes;
    kal_uint32 total_frames;
    kal_uint32 hisr_total_frames;
    kal_uint32 avail_len;

    // (0128h) for MP4_ENC_REF_ADDR. (# of Pels/frame) * 1.5.
    // __align(4)
    kal_uint8* workmem_ref;
    // (012Ch) for MP4_ENC_REC_ADDR. (# of Pels/frame) * 1.5
    // __align(4)
    kal_uint8* workmem_rec;
    // (0130h) for MP4_ENC_DATA_STORE_ADDR. 3K for encoder; (# of MBs/frame) * (32 bytes) for decoder.
    // __align(4)
    kal_uint8* workmem_data_store;
    // (0134h) for MP4_ENC_DACP_ADDR. 1K for encoder; 4K for decoder.
    // __align(4)
    kal_uint8* workmem_dacp;
    // (0138h) for MP4_ENC_MVP_ADDR. (# of MBs/width) * (2 * 4 bytes).
    // __align(4)
    kal_uint8* workmem_mvp;
    // (018Ch) for MP4_ENC_REF_INT_ADDR. (frame width) * (56 + 32 bytes).
    // __align(8)
    kal_uint8* workmem_ref_int;
    // (0190h) for MP4_ENC_CUR_INT_ADDR. 3 MBs size.
    // __align(8)
    kal_uint8* workmem_cur_int;

    // encode info
    MPEG4_ENCODER_INFO enc_info;

    // frame info
    MPEG4_ENCORE_FRAME_INFO frame_info;

    kal_uint32 current_bitstream_addr;
    kal_uint8* encode_yuv;
    kal_bool   drop_bitstream;

#if ENC_BLOCKING
    kal_eventgrpid eEncodeComplete;
#endif

}MPEG4_ENC_INFO;

typedef struct
{
    kal_bool (*open)(void *param);
    kal_bool (*init)(void);
    kal_bool (*gen_vos)(kal_uint8* addr, kal_uint32 avail_len, kal_uint32* write_len);
    kal_bool (*encode) (kal_uint8* encode_yuv, kal_uint64 timestamp, kal_uint8* write_ptr, kal_uint8* buff_end);
    kal_bool (*get_param)(MPEG4_ENCORE_PARAM_TYPE type, void *);
    kal_bool (*set_param)(MPEG4_ENCORE_PARAM_TYPE type, void *);
    void (*close)(void);
}MPEG4_ENC_DRIVER;


typedef struct{
    kal_int32 cbr_func_para1;
    kal_int32 cbr_func_para2;
    kal_int32 cbr_func_para3;
    kal_int32 dct_cut_level1;
    kal_int32 dct_cut_level2;
    kal_int32 dct_cut_level3;
    kal_int32 dct_cut_level4;
    kal_int32 md_thre1;
    kal_int32 md_thre2;
    kal_int32 md_thre3;
    kal_int32 md_thre4;
    kal_int32 md_thre5;
    kal_int32 md_thre6;
    kal_int32 md_thre7;
    kal_int32 md_thre8;
    kal_int32 md_thre9;
    kal_int32 md_thre10;
    kal_int32 md_thre11;
    kal_int32 md_thre12;
    kal_int32 mbrc_thre;
    kal_int32 mb_bit_budget;
    kal_int32 mbq_lb;
    kal_int32 mbq_ub;
    kal_int32 mbq_min;
    kal_int32 mbq_max;
} MPEG4_CBR_PARA;


MPEG4_ENC_DRIVER* GetMPEG4HWEncDriverHandle(void);
MPEG4_ENCORE_FRAME_INFO* mpeg4_encore_get_frame_info(void);
kal_bool mpeg4_encore_check_encoder_status(void);
kal_bool mepg4_encore_check_bits_buffer_status(void);


typedef struct
{
    kal_uint32 vop_time_increment_resolution;
    kal_uint32 width;
    kal_uint32 height;
} MP4HwEncVT_VOS_PAR;

kal_bool mpeg4_encore_gen_vos_VT(kal_uint8* addr, kal_uint32 avail_len, MP4HwEncVT_VOS_PAR *VOSSetting, kal_uint32* write_len);

//extern MPEG4_HW_ENCODER_CTRL_T rMPEG4HWEncCtrl;

#endif /* __VE_MPEG4_ENC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* MPEG4_HW_ENCORE_V2_H */
