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
 *   mp4_rc_v2.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video mp4 encode rate control algorithm
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_video.h"

#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(__VE_MP4_ENC_HW_SUPPORT__)

#include "drv_comm.h"
#include "vcodec_v2_trc.h"
#include "mp4_rc_v2.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "hal_custom_video.h"
#include "video_comm_v2.h"

/*input_yuv_data must 4bytes align*/

#define RC_MAX(a,b)          ( ((a)>(b))? a : b )
#define RC_MIN(a,b)          ( ((a)<(b))? a : b )
#define RC_ENFORCE_MINMAX(a,b,c)   RC_MAX(a,(RC_MIN(b,c)))

static kal_bool mpeg4_rc_assert_check = KAL_TRUE;

static const kal_int8 skip_thresholds[16] =
{
    -1, 2, 4, 6, 8, 12, 16, 21, 26, 29, 33, 37, 41, 46, 51, 56
};

static RC_STRUCT g_mpeg4_enc_rc_data;

#if defined(__VE_ENABLE_CBR__)
static CBR_STRUCT g_mpeg4_enc_cbr_data;

static kal_uint8 g_intra_thre_table[32] =
{
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6,
    6, 7, 7, 7, 7, 7, 9, 9
};
#endif

RC_RESULT mpeg4_init_RC_VBR(RC_INIT_PARAM input_param)
{
    kal_int32 bitrate = input_param.bitrate;
    kal_int32 frame_rate = input_param.frame_rate/10;   // 3-digit-format is assumed in v2, 30 fps would bring 300 in
    kal_int32 pixels_per_frame = input_param.pixels_per_frame;
    kal_int32 bits_per_pixel = (kal_uint32)bitrate;
    kal_int32 initial_quantiser;
    RC_RESULT rc_result;

#if defined(__VE_ENABLE_CBR__)
    rc_result.mbrc_thre = 0;
    rc_result.mbq_ub = 0;
    rc_result.mbq_lb = 0;
    rc_result.mb_bit_budget = 0;
    rc_result.is_encode_i_nxt_frm = KAL_FALSE;
    rc_result.is_drop_nxt_frm = KAL_FALSE;
    rc_result.cbr_dct_lev.dct_cut_level4 = 0;
    rc_result.cbr_dct_lev.dct_cut_level3 = 0;
    rc_result.cbr_dct_lev.dct_cut_level2 = 0;
    rc_result.cbr_dct_lev.dct_cut_level1 = 0;
#endif

    g_mpeg4_enc_rc_data.buffer_bits = 0;
    g_mpeg4_enc_rc_data.buffer_frame_num = 0;
    g_mpeg4_enc_rc_data.intra_mb_evaluation_count = 0;
    g_mpeg4_enc_rc_data.same_quant_count = 0;
    g_mpeg4_enc_rc_data.th_intra_data = 6;
    bits_per_pixel /= frame_rate;
    bits_per_pixel = (bits_per_pixel * 1024) / pixels_per_frame;

    initial_quantiser = 838861 / bits_per_pixel;

    initial_quantiser = ((initial_quantiser > 31*1024) ? 31 : (initial_quantiser < 8*1024) ? 8 : (initial_quantiser/1024) );

    g_mpeg4_enc_rc_data.quant_temp = (initial_quantiser * 1024);

    rc_result.quant = (kal_uint32)initial_quantiser;
    rc_result.intra_threshold = g_mpeg4_enc_rc_data.th_intra_data;
    return (rc_result);
}

#if defined(__VE_ENABLE_CBR__)
RC_RESULT mpeg4_init_RC_CBR(RC_INIT_PARAM input_param)
{
    kal_uint32 mbcnt = ((input_param.width + 15) / 16) * ((input_param.height + 15) / 16);
    CBR_STRUCT *pCS = &g_mpeg4_enc_cbr_data;
    RC_RESULT hw_data;
    kal_int32 bitrate = input_param.bitrate * 0.9;
    kal_int32 frame_rate = (input_param.frame_rate%10)?(input_param.frame_rate/10 + 1):(input_param.frame_rate/10);
    kal_uint32 u4IntraInterval = 0;

    pCS->prev_qp_bak = 13;
    pCS->cbr_thre1 = input_param.cbr_func_para1;
    pCS->cbr_thre2 = input_param.cbr_func_para2;
    pCS->cbr_thre5 = input_param.cbr_func_para3;
    pCS->P_frm_bitbudget = (kal_uint32)(bitrate / (frame_rate + pCS->cbr_thre1));
    pCS->base_frm_bitbudget = pCS->frm_bitbudget = pCS->P_frm_bitbudget * (pCS->cbr_thre1 + 1);
    pCS->GOP_accu = pCS->highQcnt = pCS->frm_accu_bit_consume = 0;  // reset to 0 for GOP
    pCS->base_mb_bitbudget = pCS->frm_bitbudget / mbcnt;
    pCS->cbr_thre4_base = (kal_uint32)mbcnt / 10;
    pCS->frm_q_min = 5; // Set minimum less than 5 does not greatly enhance video quality
    pCS->frm_q_max = 31;
    pCS->frm_q_lb = FRAME_Q_LOWER_BOUND;
    pCS->frm_q_ub = FRAME_Q_UPPER_BOUND;
    pCS->Is_drop_frm = 0;
    pCS->I_frm_accu_bit_consume = 0;
    pCS->drop_aging_cnt = pCS->drop_aging_thre = 4;
    pCS->drop_bit_thre = (kal_uint32)(pCS->frm_bitbudget * 0.3);
    pCS->share_denom = (kal_uint32)(frame_rate - 1);
    if (VC_ERR_NONE != HalCustomQueryVideoSettings(HALC_I_FRM_RATE, &u4IntraInterval))
    {
        ASSERT(0);
    }
    pCS->intra_period = frame_rate * u4IntraInterval;//VideoCallGetIntraInterval();//(frame_rate<<1); // Refresh I frame every 2 seconds
    pCS->dct_degree = 0;
    pCS->bit_coded = 0;
    pCS->previous_time = video_get_current_time();
    pCS->is_next_second_start= KAL_FALSE;
    pCS->accuulated_encoding_time = 0;
    pCS->u4AccuFrmNum = 0;
    pCS->u4FrmRate = frame_rate;

    hw_data.mb_bit_budget = pCS->base_mb_bitbudget;
    hw_data.quant = 13;
    hw_data.is_drop_nxt_frm = KAL_FALSE;
    hw_data.intra_threshold= 6;
    hw_data.mbrc_thre = hw_data.mb_bit_budget * pCS->cbr_thre4_base * 2;// for 1st I-frame.
    hw_data.mbq_lb = MB_Q_LOWER_BOUND;
    hw_data.mbq_ub = MB_Q_UPPER_BOUND;
    hw_data.cbr_dct_lev.dct_cut_level1 = 63;
    hw_data.cbr_dct_lev.dct_cut_level2 = 63;
    hw_data.cbr_dct_lev.dct_cut_level3 = 63;
    hw_data.cbr_dct_lev.dct_cut_level4 = 63;
    hw_data.is_encode_i_nxt_frm = KAL_TRUE;

    drv_trace8(TRACE_GROUP_10, CBR_INIT,
        0, hw_data.quant,
        input_param.frame_rate, frame_rate,
        pCS->frm_bitbudget, pCS->frm_accu_bit_consume,
        0, (kal_int32)hw_data.is_encode_i_nxt_frm);

    return hw_data;
}
#endif

RC_RESULT mpeg4_init_RC(RC_INIT_PARAM input_param)
{
    g_mpeg4_enc_rc_data.b_is_cbr = input_param.b_is_cbr;
    if(!g_mpeg4_enc_rc_data.b_is_cbr) {
        return mpeg4_init_RC_VBR(input_param);
    }
    else{
    #if defined(__VE_ENABLE_CBR__)
        return mpeg4_init_RC_CBR(input_param);
    #else
        ASSERT(0);
        return *(RC_RESULT*)&input_param;
    #endif
    }
}

RC_RESULT mpeg4_RC_UPdated_VBR(RC_UPDATE_PARAM input_param)
{
    kal_uint32 frame_rate = input_param.frame_rate/10;// 3-digit-format is assumed in v2, 30 fps would bring 300 in
    kal_int32 quant = input_param.quant;
    kal_int32 bitcount = input_param.bitcount;
    kal_uint32 mode = input_param.mode;
    kal_int32 target_bitrate = input_param.bitrate;
    kal_int32 framerate;
    kal_int32 bits = bitcount;
    kal_int32 temp;
    kal_int32 add;
    kal_int32 out_quant;
    kal_int32 adjust_value;
    kal_int32 frame_rate_factor;
    RC_RESULT rc_result;
    kal_int32 avg_frame_bits;
    
#if defined(__VE_ENABLE_CBR__)
    rc_result.mbrc_thre = 0;
    rc_result.mbq_ub = 0;
    rc_result.mbq_lb = 0;
    rc_result.mb_bit_budget = 0;
    rc_result.is_encode_i_nxt_frm = KAL_FALSE;
    rc_result.is_drop_nxt_frm = KAL_FALSE;
    rc_result.cbr_dct_lev.dct_cut_level4 = 0;
    rc_result.cbr_dct_lev.dct_cut_level3 = 0;
    rc_result.cbr_dct_lev.dct_cut_level2 = 0;
    rc_result.cbr_dct_lev.dct_cut_level1 = 0;
#endif

    adjust_value = 0;

    framerate = (kal_int32)g_mpeg4_enc_rc_data.fr_rate.frame_rate;

    if (mpeg4_rc_assert_check)
    {
#if defined(__VE_MP4_V2_ENHANCE__)
        // zoom may be duration short, but incoming frame rate keeps 30fps
        if(framerate >= 35)
        {
            drv_trace1(TRACE_GROUP_10, VIDEO_TRC_MP4_FRAMERATE_WARNING, framerate);
            ASSERT(framerate < 50);
        }
#else
        if(framerate >= 35)
        {
            drv_trace1(TRACE_GROUP_10, VIDEO_TRC_MP4_FRAMERATE_WARNING, framerate);
            ASSERT(framerate < 35);
        }
#endif
    }

    if (framerate == 0)
        framerate = frame_rate;

   frame_rate_factor = framerate/16;
   if ((framerate%16) >= 8)
       frame_rate_factor++;

   if (frame_rate_factor == 0)
      frame_rate_factor = 1;

    g_mpeg4_enc_rc_data.buffer_bits = (g_mpeg4_enc_rc_data.buffer_bits
                                                     * g_mpeg4_enc_rc_data.buffer_frame_num + bits)
                                                    / (g_mpeg4_enc_rc_data.buffer_frame_num + 1);

    if (g_mpeg4_enc_rc_data.buffer_frame_num < 4)
        g_mpeg4_enc_rc_data.buffer_frame_num++;

    if ((quant+adjust_value) > 20)
        g_mpeg4_enc_rc_data.th_intra_data = 2;
    else if ((quant+adjust_value) > 15)
        g_mpeg4_enc_rc_data.th_intra_data = 3;
    else if ((quant+adjust_value) > 8)
        g_mpeg4_enc_rc_data.th_intra_data = 4;
    else
        g_mpeg4_enc_rc_data.th_intra_data = 5;

    add = RC_ENFORCE_MINMAX(307,(g_mpeg4_enc_rc_data.quant_temp/10),1536);

    if ( (g_mpeg4_enc_rc_data.buffer_bits*100) > (target_bitrate*115/framerate))
        temp = add/frame_rate_factor;
    else if ( (g_mpeg4_enc_rc_data.buffer_bits*100) > (target_bitrate*105/framerate))
        temp = add/(2*frame_rate_factor);
    else if( (g_mpeg4_enc_rc_data.buffer_bits*115) < ((target_bitrate*100)/(framerate)) )
        temp = -add/(frame_rate_factor);
    else if( (g_mpeg4_enc_rc_data.buffer_bits*105) < ((target_bitrate*100)/(framerate)) )
        temp = -add/(2*frame_rate_factor);
    else
        temp = 0;

    g_mpeg4_enc_rc_data.th_intra_data = RC_ENFORCE_MINMAX(1,g_mpeg4_enc_rc_data.th_intra_data,6);

    if (mode == 1) // for Video Recorder
    {
#if defined(__VE_MP4_V2_ENHANCE__)
        g_mpeg4_enc_rc_data.quant_temp =RC_ENFORCE_MINMAX((2*1024), (g_mpeg4_enc_rc_data.quant_temp + temp), (20*1024));
#else
        g_mpeg4_enc_rc_data.quant_temp =RC_ENFORCE_MINMAX((6*1024), (g_mpeg4_enc_rc_data.quant_temp + temp), (20*1024));
#endif
    }
    else if (mode>=2)
    {
        g_mpeg4_enc_rc_data.quant_temp =RC_ENFORCE_MINMAX((6*1024), (g_mpeg4_enc_rc_data.quant_temp + temp), (25*1024));
    }

    out_quant = (kal_int32)(g_mpeg4_enc_rc_data.quant_temp/1024);

    if (out_quant >= 10)
    {
        avg_frame_bits = target_bitrate/framerate;
        if ((g_mpeg4_enc_rc_data.buffer_bits) > avg_frame_bits)
        {
            g_mpeg4_enc_rc_data.buffer_bits = avg_frame_bits;
        }
    }

    rc_result.quant = (kal_uint32)out_quant;
    rc_result.intra_threshold = g_mpeg4_enc_rc_data.th_intra_data;
    return (rc_result);
}

#if defined(__VE_ENABLE_CBR__)
RC_RESULT mpeg4_RC_UPdated_CBR(RC_UPDATE_PARAM input_param)
{
    RC_RESULT hw_data;
    CBR_STRUCT *pCS = &g_mpeg4_enc_cbr_data;
    kal_uint32 P_frm_bitbudget = (pCS->P_frm_bitbudget);
    kal_int32  f_accu_bit_consume = (pCS->frm_accu_bit_consume);
    kal_int32  I_f_accu_bit_consume = (pCS->I_frm_accu_bit_consume);
    kal_int32  f_bitbudget = (pCS->frm_bitbudget);
    kal_int32  I_f_share_part = 0;
    kal_int32  tempQ = 0;
    kal_int32  mbcnt = ((input_param.width + 15) / 16) * ((input_param.height + 15) / 16);
    kal_int32  diff= 0;
    kal_int32  share_part = 0;
    kal_int32  ofs = 0;
    kal_int32  bitrate = input_param.bitrate * 0.9;
    kal_uint32 encoding_time = 0;
    kal_int32 frame_rate = pCS->u4FrmRate;

    diff = input_param.bitcount - f_bitbudget;
    f_accu_bit_consume += diff;
    pCS->GOP_accu += diff;

    pCS->bit_coded += input_param.bitcount;

    if (diff > f_bitbudget)
        pCS->dct_degree += 1;

    if (f_accu_bit_consume > (f_bitbudget<<2))
        pCS->dct_degree += 4;
    else if (f_accu_bit_consume > (f_bitbudget + (f_bitbudget>>1)))
        pCS->dct_degree += 2;
    else
        pCS->dct_degree = pCS->dct_degree;

    if (pCS->GOP_accu < 0)
        pCS->dct_degree -= 1;
    else
        pCS->dct_degree = pCS->dct_degree;

    encoding_time = video_get_duration_ms( pCS->previous_time );
    pCS->accuulated_encoding_time += encoding_time;
    pCS->previous_time = video_get_current_time();

    if ( pCS->accuulated_encoding_time >= 1000 )
    {
        pCS->accuulated_encoding_time %= 1000;
        pCS->is_next_second_start = KAL_TRUE;
        if (pCS->u4AccuFrmNum != 0)
        {
            pCS->u4FrmRate = pCS->u4AccuFrmNum;
        }
        pCS->u4AccuFrmNum = 1;
        drv_trace1(TRACE_GROUP_10, CBR_BITRATE, pCS->bit_coded);
    }
    else
    {
        pCS->is_next_second_start = KAL_FALSE;
        pCS->u4AccuFrmNum += 1;
    }

    if (((input_param.total_frames) % (kal_int32)pCS->intra_period) == 0) // next is I-VOP
    {
        P_frm_bitbudget = (kal_uint32)(bitrate / (frame_rate + pCS->cbr_thre1));
        pCS->share_denom = (kal_uint32)(frame_rate - 1);
        f_bitbudget = P_frm_bitbudget * (pCS->cbr_thre1 + 1);
        pCS->base_mb_bitbudget = hw_data.mb_bit_budget = f_bitbudget / mbcnt;
        pCS->prev_qp_bak = hw_data.quant = 15;
        hw_data.is_encode_i_nxt_frm = KAL_TRUE;
        pCS->dct_degree = 0;
        //if (((input_param.total_frames) % (kal_int32)frame_rate) == 0)  // next is 1st in a second
        if ( pCS->is_next_second_start == KAL_TRUE ) // next is 1st frm in a second
        {
            if ( (pCS->bit_coded < bitrate) && (f_accu_bit_consume < 0))
            {
                if (f_accu_bit_consume < (((kal_int32)bitrate - TARGET_BITRATE)>>2))
                    f_accu_bit_consume = ((kal_int32)bitrate - TARGET_BITRATE)>>2;
                else
                    f_accu_bit_consume = f_accu_bit_consume;
            }
            else
            {
                f_accu_bit_consume = f_accu_bit_consume;
            }
            pCS->bit_coded = 0;
            pCS->dct_degree = 0;
        }
    } else {
        tempQ = input_param.q_accu / mbcnt;  //Eason: pre_first_Q is average MB QP of the previous frame, retrieve from MP4_ENC_MBRC_Q_SUM

        if (((input_param.total_frames - 1) % (kal_int32)(pCS->intra_period)) == 0) { // current is I-VOP
            I_f_accu_bit_consume += f_accu_bit_consume;
            I_f_share_part = I_f_accu_bit_consume / pCS->cbr_thre5;  //Eason: Share the bits consumption to the later cbr_thre5 frames
            f_accu_bit_consume = 0;
        }
        if (I_f_accu_bit_consume != 0) {  //Eason: Slowly add the bit comsumption of I frame into f_accu_bit_consume, frame by frame
            f_accu_bit_consume += I_f_share_part;
            I_f_accu_bit_consume -= I_f_share_part;
            //Eason: I_f_accu_bit_consume is not always divisable by I_f_share_part, so this can happend.  Note the "/" operation
            if (I_f_accu_bit_consume < I_f_share_part)  // the remaining debt may be < share_part
                I_f_share_part = I_f_accu_bit_consume;
        }
        //if (((input_param.total_frames) % (kal_int32)frame_rate) == 0)  // next is 1st in a second
        if ( pCS->is_next_second_start == KAL_TRUE ) // next is 1st frm in a second
        {
            P_frm_bitbudget = (kal_int32)(bitrate / frame_rate);
            pCS->share_denom = (kal_uint32)(frame_rate);
            if ( (pCS->bit_coded < bitrate) && (f_accu_bit_consume < 0))
            {
                if (f_accu_bit_consume < (((kal_int32)bitrate - TARGET_BITRATE)>>2))
                    f_accu_bit_consume = ((kal_int32)bitrate - TARGET_BITRATE)>>2;
                else
                    f_accu_bit_consume = f_accu_bit_consume;
            }
            else
            {
                f_accu_bit_consume = f_accu_bit_consume;
            }
            pCS->bit_coded = 0;
            pCS->dct_degree = 0;
        }

        pCS->cbr_thre3 = P_frm_bitbudget>>2;    // Fine-tune: decrease cbr_thre3 for more varied Q and more stricted CBR
        ofs = (kal_int32)(f_accu_bit_consume / (kal_int32)(pCS->cbr_thre3));
        if ((ofs < 0) && (pCS->GOP_accu > 0)) {
            ofs = 1;
        }
        tempQ += ofs;
        tempQ = RC_ENFORCE_MINMAX((kal_int32)(pCS->prev_qp_bak - pCS->frm_q_lb), (tempQ), (kal_int32)(pCS->prev_qp_bak + pCS->frm_q_ub));
        tempQ = RC_ENFORCE_MINMAX((kal_int32)(pCS->frm_q_min), (tempQ), (kal_int32)(pCS->frm_q_max));
        pCS->prev_qp_bak = hw_data.quant = tempQ;

        //share_part = f_accu_bit_consume / (kal_int32)(pCS->cbr_thre2);
        if (pCS->share_denom == 0) // protect framerate variance
            pCS->share_denom = 1;
        share_part = f_accu_bit_consume / (kal_int32)(pCS->share_denom);
        pCS->share_denom -= 1;
        f_bitbudget = P_frm_bitbudget - share_part; //Eason: share part of the bit consumption to the next frame
        f_accu_bit_consume -= share_part;

        if (f_bitbudget <= 0){ //Eason: if the former frame consumes too many bits, share part will be large and f_bitbudget may become less than zero
            f_bitbudget = pCS->base_frm_bitbudget / 4;
            f_accu_bit_consume += share_part;
            pCS->dct_degree = 10;
        }

        hw_data.mb_bit_budget = f_bitbudget / mbcnt;
        if (hw_data.mb_bit_budget == 0) { //Eason: CMR_mb_bitbudget has no reason to be less than ot equal to zero unless f_bitbudget goes wrong
            hw_data.mb_bit_budget = pCS->base_mb_bitbudget / 4;
            f_bitbudget = hw_data.mb_bit_budget * mbcnt;
        }
        hw_data.is_encode_i_nxt_frm = KAL_FALSE;
    }

    if (pCS->prev_qp_bak > HIGH_Q_THRESHOLD) {
        pCS->highQcnt++;
    } else if (pCS->prev_qp_bak < LOW_Q_THRESHOLD) {
        pCS->highQcnt = 0;
    }
    if ( ((input_param.total_frames- 1) > 30) && (pCS->highQcnt > (frame_rate>>1)) ) {
        pCS->prev_qp_bak = hw_data.quant = pCS->prev_qp_bak - 2;
        pCS->highQcnt = 0;
    }
    // reset threshold for mb-level rate control
    hw_data.mbrc_thre = hw_data.mb_bit_budget * pCS->cbr_thre4_base;

    if (pCS->Is_drop_frm!=0) {
        pCS->drop_bit_thre = (kal_int32)f_bitbudget*0.3;    // drop when bit accumulation is over this thre, move to mpeg4_init_RC_CBR()
        if ((input_param.total_frames -1)== 0)
            pCS->drop_aging_cnt = pCS->drop_aging_thre;

        if ((f_accu_bit_consume > (kal_int32)pCS->drop_bit_thre) && (pCS->drop_aging_cnt == 0))  {
            // reset drop count, and drop next frame
            pCS->drop_aging_cnt = pCS->drop_aging_thre;
            hw_data.is_drop_nxt_frm= KAL_TRUE;
        } else {
            hw_data.is_drop_nxt_frm= KAL_FALSE;
            if (pCS->drop_aging_cnt > 0)
                pCS->drop_aging_cnt--;
        }
    } else{
        hw_data.is_drop_nxt_frm= KAL_FALSE;
    }

    pCS->frm_accu_bit_consume = f_accu_bit_consume;
    pCS->P_frm_bitbudget = P_frm_bitbudget;
    pCS->frm_bitbudget = f_bitbudget;
    pCS->I_frm_accu_bit_consume = I_f_accu_bit_consume;

    hw_data.mbq_lb = MB_Q_LOWER_BOUND;
    hw_data.mbq_ub = MB_Q_UPPER_BOUND;
    if ( pCS->dct_degree >= DCT_DEGREE_THRESHOLD )
        hw_data.intra_threshold= (kal_uint32)(g_intra_thre_table[hw_data.quant]*2);
    else
        hw_data.intra_threshold= (kal_uint32)g_intra_thre_table[hw_data.quant];

    pCS->dct_degree = (pCS->dct_degree < 0)? 0 : pCS->dct_degree;
    if (((input_param.total_frames) % (kal_int32)pCS->intra_period) == 0)
    {
        hw_data.cbr_dct_lev.dct_cut_level1 = 63;
        hw_data.cbr_dct_lev.dct_cut_level2 = 63;
        hw_data.cbr_dct_lev.dct_cut_level3 = 63;
        hw_data.cbr_dct_lev.dct_cut_level4 = 63;
    }
    else
    {
        kal_int32 tmp1 = 63 - pCS->dct_degree;
        kal_int32 tmp2 = 63 - (pCS->dct_degree<<1);
        kal_int32 tmp3 = 63 - (pCS->dct_degree<<2);
        kal_int32 tmp4 = 63 - (pCS->dct_degree<<3);
        hw_data.cbr_dct_lev.dct_cut_level1 = (tmp1>27)?tmp1:27;
        hw_data.cbr_dct_lev.dct_cut_level2 = (tmp2>14)?tmp2:14;
        hw_data.cbr_dct_lev.dct_cut_level3 = (tmp3> 2)?tmp3: 2;
        hw_data.cbr_dct_lev.dct_cut_level4 = (tmp4> 0)?tmp4: 0;
    }

    drv_trace8(TRACE_GROUP_10, CBR_TRACE,
                input_param.bitcount, hw_data.quant,
                pCS->dct_degree, input_param.q_accu,
                f_bitbudget, f_accu_bit_consume,
                input_param.total_frames, (kal_int32)hw_data.is_encode_i_nxt_frm);

    drv_trace4(TRACE_GROUP_10, CBR_TRACE2,
                encoding_time, pCS->accuulated_encoding_time,
                pCS->u4AccuFrmNum, pCS->u4FrmRate);

    return hw_data;
}
#endif

RC_RESULT mpeg4_RC_UPdated(RC_UPDATE_PARAM input_param)
{
    if(!g_mpeg4_enc_rc_data.b_is_cbr) {
        return mpeg4_RC_UPdated_VBR(input_param);
    }
    else{
    #if defined(__VE_ENABLE_CBR__)
        return mpeg4_RC_UPdated_CBR(input_param);
    #else
        ASSERT(0);
        return *(RC_RESULT*)&input_param;
    #endif
    }
}

kal_int8 mpeg4_enc_get_skip_threshold(kal_int32 quantizer)
{
    kal_int8 skip_threshold;
    skip_threshold = ((quantizer < 16) ?
                              skip_thresholds[quantizer] : 60);
    return skip_threshold;
}

#endif /*__VE_MP4_ENC_HW_SUPPORT__*/
#endif /* __VE_VIDEO_ARCHI_V2__ */
