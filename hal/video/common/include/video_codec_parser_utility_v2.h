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
 *   video_codec_parser_utility_v2.h
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *   This file defines the video codec parser interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VIDEOCODEC_PARSER_UTILITY_H
#define VIDEOCODEC_PARSER_UTILITY_H
#include "drv_features_video.h"
//#if defined(__VE_VIDEO_ARCHI_V2__)

#include "kal_general_types.h"
#include "med_status.h"

#define VO_START_CODE		      0x8
#define VO_START_CODE_MIN	      0x100
#define VO_START_CODE_MAX	      0x11f

#define VOL_START_CODE		      0x12
#define VOL_START_CODE_MIN	      0x120
#define VOL_START_CODE_MAX	      0x12f

#define VOS_START_CODE           0x1b0
#define VOS_END_CODE             0x1b1
#define USR_START_CODE           0x1b2
#define GOP_START_CODE           0x1b3
#define VSO_START_CODE           0x1b5
#define VOP_START_CODE	         0x1b6
#define STF_START_CODE           0x1c3 // stuffing_start_code
#define SHV_START_CODE           0x020
#define SHV_END_MARKER           0x03f

/* these information is obtained from bitstream parser */
typedef struct
{
    // Frame width
    kal_uint16 width;
    // Frame height
    kal_uint16 height;
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
    kal_uint8 H263;
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
} m4v_dec_im;

extern kal_int32 mpeg4_codec_util_show_bits(kal_uint8 * data, kal_int32 bitcnt, kal_int32 num);
extern kal_int32 mpeg4_codec_util_user_data(kal_uint8 * data, kal_int32 * bitcnt, kal_uint32 max_parse_data_size);
extern kal_int32 mpeg4_codec_util_get_bits(kal_uint8 * data, kal_int32 *bitcnt, kal_int32 num);
extern kal_int32 mpeg4_codec_util_show_word(kal_uint8 * a);
extern kal_int32 mpeg4_codec_util_log2ceil(kal_int32 arg);
extern kal_int32 mpeg4_read_VOP_header(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt_init, MEDIA_STATUS_CODE * result);
extern kal_bool video_plane_with_short_header(m4v_dec_im * hdr, kal_uint8 * data, kal_int32* bitcnt_init);
extern kal_int32 mpeg4_read_header_imformation(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt, kal_uint32 max_parse_data_size);

//#endif // __VE_VIDEO_ARCHI_V2__
#endif // VIDEOCODEC_PARSER_UTILITY_H
