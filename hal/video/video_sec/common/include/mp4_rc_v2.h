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
 *   mp4_rc_v2.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video mp4 encode rate control definitions
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MP4_RC_V2_H
#define MP4_RC_V2_H
#include "drv_features_video.h"

#if defined(__VE_VIDEO_ARCHI_V2__)

#include "kal_general_types.h"

///Rate control information
///
typedef struct
{
   kal_uint32     time_stamp[4];
   kal_uint8      time_stamp_index;
   kal_uint32     buffer_frame_num;
   kal_uint32     avg_frame_duration;
   kal_uint32     frame_rate;
   kal_bool       run_done;
}FR_STRUCT;

typedef struct
{
   kal_int32   buffer_bits;
   kal_int32   buffer_frame_num;
   kal_int32   quant_temp;
   FR_STRUCT   fr_rate;
   kal_int32	intra_mb_evaluation_count;
   kal_int32	same_quant_count;
   kal_uint32   th_intra_data;
   kal_bool    b_is_cbr;
}RC_STRUCT;

#define FRAME_Q_UPPER_BOUND 5
#define FRAME_Q_LOWER_BOUND 3
#define MB_Q_UPPER_BOUND 10
#define MB_Q_LOWER_BOUND 5
#define DCT_DEGREE_THRESHOLD 5  // when dct degree higher than this threshold, intra threshold would be raised to reduce intra blocks
#define HIGH_Q_THRESHOLD 27
#define LOW_Q_THRESHOLD 20
#define TARGET_BITRATE 51200

typedef struct
{
    kal_uint32 dct_cut_level1;
    kal_uint32 dct_cut_level2;
    kal_uint32 dct_cut_level3;
    kal_uint32 dct_cut_level4;
}CBR_DCT_LEV_STRUCT;

typedef struct
{
    kal_uint32 prev_qp_bak;	//preserve QP of the previous frame, updated after coded
    kal_uint32 highQcnt;			//the number of consecutive frames with high Q
    kal_uint32 P_frm_bitbudget;
    kal_uint32 base_mb_bitbudget;
    kal_uint32 cbr_thre1;
    kal_uint32 cbr_thre2;
    kal_uint32 cbr_thre3;
    kal_uint32 cbr_thre4_base;
    kal_uint32 cbr_thre5;
    kal_uint32 frm_q_lb;
    kal_uint32 frm_q_ub;
    kal_uint32 frm_q_min;
    kal_uint32 frm_q_max;
    kal_uint32 Is_drop_frm;
    kal_uint32 drop_aging_thre;
    kal_uint32 drop_aging_cnt;
    kal_uint32 drop_bit_thre;
    kal_uint32 share_denom;
    kal_uint32 intra_period;
    kal_int32  dct_degree;
    kal_int32   frm_bitbudget;
    kal_int32   base_frm_bitbudget;
    kal_int32   frm_accu_bit_consume;
    kal_int32   GOP_accu;			//preserve the accumulated bit counts of current GOP
    kal_int32   I_frm_accu_bit_consume;
    kal_uint32 bit_coded;
    kal_uint32 previous_time;
    kal_uint32 accuulated_encoding_time;
    kal_bool   is_next_second_start;
    kal_uint32 u4AccuFrmNum;     //used to count camera frame rate
    kal_uint32 u4FrmRate;        //use to dynamically adjust frame rate in case camera input is not stable
}CBR_STRUCT;

typedef struct
{
    kal_int32 bitrate;                     // bitrate mpeg4 encode bit rate
    kal_int32 frame_rate;             // frame_rate the frame rate of camera(image source)
    kal_int32 pixels_per_frame;  // how much pixels in a frames
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 cbr_func_para1;
    kal_uint32 cbr_func_para2;
    kal_uint32 cbr_func_para3;
    kal_bool  b_is_cbr;
}RC_INIT_PARAM;

typedef struct
{
    kal_uint32 bitrate;                 // mpeg4 encode bit rate
    kal_uint32 frame_rate;         //  the frame rate of camera(image source)
    kal_int32 quant;                    // the previous quantizer value
    kal_uint32 width;
    kal_uint32 height;
    kal_int32 bitcount;                // how much pixels in a frames
    kal_int32 predition_type;     // I_FRAME or P_FRAME
    kal_uint32 total_frames;      // total encode frame number
    kal_bool b_force_I_frame;  // force this frame as I_FRAME
    kal_uint32 mode;
    kal_uint32 intra_period;
    kal_uint32 q_accu;
}RC_UPDATE_PARAM;

typedef struct
{
    kal_uint32 quant;
    kal_uint32 intra_threshold;
    kal_uint32 mbrc_thre; 			//cbr_thre4
    kal_uint32 mb_bit_budget;		//CBR_mb_bitbudget;
    kal_uint32 mbq_lb;
    kal_uint32 mbq_ub;
    CBR_DCT_LEV_STRUCT cbr_dct_lev;
    kal_bool is_drop_nxt_frm;		//this is actually not for HW, for notifying system only
    kal_bool is_encode_i_nxt_frm;
}RC_RESULT;

/**
 * Initialize the rate control mechanism for mpeg4 encoder.
 *
 * @param  input_param input parameters for RC init
 * @return rc result
 *
 */
extern RC_RESULT mpeg4_init_RC(RC_INIT_PARAM input_param);

/**
 * Obtain the new quantizer value through rate control from previous frames.
 *
 * @param  input_param input parameters for RC update
 * @return rc result
 *
 */
extern RC_RESULT mpeg4_RC_UPdated(RC_UPDATE_PARAM input_param);

extern kal_int8 mpeg4_enc_get_skip_threshold(kal_int32 quantizer);

#if defined(__VE_VIDEO_VT_SUPPORT__)
extern void mpeg4_videocall_ratec_control(kal_uint32 mode, kal_int32 *temp, kal_int32 add, kal_uint32 target_frame_bits, kal_int32 bits);
extern kal_uint8 mpeg4_videocall_toggle_drop_frame(kal_bool indication);
#endif

#endif /*__VE_VIDEO_ARCHI_V2__*/
#endif /*MP4_RC_V2_H*/
