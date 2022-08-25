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
 *   mpeg4_hw_encore_v2.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   This file defines the core of mpeg4 encode
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
#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_ENC_HW_SUPPORT__

#include "mp4_hw.h"
#include "mpeg4_hw_encore_v2.h"
#include "intrCtrl.h"
#include "visualhisr.h"
#include "video_dbg_v2.h"

#include "drv_gfx_dct_control.h"
#include "mm_power_ctrl.h"
#include "video_comm_v2.h"
#include "vcodec_v2_trc.h"

//#include "drv_features.h"
#include "kal_general_types.h"
#include "mp4_decore_v2.h"
#include "kal_public_api.h"
//#include "med_status.h"
#include "mpeg4_hw_v2.h"
#include "mp4_rc_v2.h"
#include "reg_base.h"
#include "video_encoder_component_v2.h"
#include "kal_trace.h"
#include "mpeg4_hw_encoder_component_v2.h"
#include "MPEG4HWEncMem.h"
#include "video_codec_mem_v2.h"

MPEG4_ENC_INFO  g_mpeg4_encore_info;

/******************************************************************************
*
*
* MPEG4 HW for Performance Measurement
*
*
******************************************************************************/
#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT

static kal_uint64 mpeg4_bm_encode_total_time;
static kal_uint64 mpeg4_bm_encode_max_time;
static kal_uint64 mpeg4_bm_encode_min_time;
static kal_uint64 mpeg4_bm_encode_average_time;
static kal_uint64 mpeg4_bm_encode_frame_count;

static kal_uint64 mpeg4_bm_lisr_total_time;
static kal_uint64 mpeg4_bm_lisr_max_time;
static kal_uint64 mpeg4_bm_lisr_min_time;
static kal_uint64 mpeg4_bm_lisr_average_time;
static kal_uint64 mpeg4_bm_lisr_frame_count;

static kal_uint64 mpeg4_bm_hisr_total_time;
static kal_uint64 mpeg4_bm_hisr_max_time;
static kal_uint64 mpeg4_bm_hisr_min_time;
static kal_uint64 mpeg4_bm_hisr_average_time;
static kal_uint64 mpeg4_bm_hisr_frame_count;

static kal_uint32 mpeg4_bm_tick[4096];
kal_bool mpeg4_bm_para_init;

void mpeg4_measure_time_init(void)
{
    mpeg4_bm_encode_total_time = 0;
    mpeg4_bm_encode_max_time = 0;
    mpeg4_bm_encode_min_time = 0xffffffffffff;
    mpeg4_bm_encode_average_time = 0;
    mpeg4_bm_encode_frame_count = 1;

    mpeg4_bm_lisr_total_time = 0;
    mpeg4_bm_lisr_max_time = 0;
    mpeg4_bm_lisr_min_time = 0xffffffffffff;
    mpeg4_bm_lisr_average_time = 0;
    mpeg4_bm_lisr_frame_count = 1;

    mpeg4_bm_hisr_total_time = 0;
    mpeg4_bm_hisr_max_time = 0;
    mpeg4_bm_hisr_min_time = 0xffffffffffff;
    mpeg4_bm_hisr_average_time = 0;
    mpeg4_bm_hisr_frame_count = 1;
}

static void mpeg4_encode_time_measure(kal_uint32 current_frame_time)
{
    mpeg4_bm_encode_total_time += (kal_uint64)current_frame_time;
    if(current_frame_time > mpeg4_bm_encode_max_time)
    {
        mpeg4_bm_encode_max_time = current_frame_time;
    }
    if (current_frame_time < mpeg4_bm_encode_min_time)
        mpeg4_bm_encode_min_time = current_frame_time;
    mpeg4_bm_encode_average_time = mpeg4_bm_encode_total_time/mpeg4_bm_encode_frame_count;
    mpeg4_bm_tick[mpeg4_bm_encode_frame_count-1] = current_frame_time;
    mpeg4_bm_encode_frame_count++;
}

static void mpeg4_lisr_time_measure(kal_uint32 current_frame_time)
{
    mpeg4_bm_lisr_total_time += (kal_uint64)current_frame_time;
    if(current_frame_time > mpeg4_bm_lisr_max_time)
        mpeg4_bm_lisr_max_time = current_frame_time;
    if (current_frame_time < mpeg4_bm_lisr_min_time)
        mpeg4_bm_lisr_min_time = current_frame_time;
    mpeg4_bm_lisr_average_time = mpeg4_bm_lisr_total_time/mpeg4_bm_lisr_frame_count;
    mpeg4_bm_lisr_frame_count++;
}

static void mpeg4_hisr_time_measure(kal_uint32 current_frame_time)
{
    mpeg4_bm_hisr_total_time += (kal_uint64)current_frame_time;
    if(current_frame_time > mpeg4_bm_hisr_max_time)
        mpeg4_bm_hisr_max_time = current_frame_time;
    if (current_frame_time < mpeg4_bm_hisr_min_time)
        mpeg4_bm_hisr_min_time = current_frame_time;
    mpeg4_bm_hisr_average_time = mpeg4_bm_hisr_total_time/mpeg4_bm_hisr_frame_count;
    mpeg4_bm_hisr_frame_count++;
}

#endif

/******************************************************************************
*
*
* MPEG4 HW for VT Support
*
*
******************************************************************************/


const MPEG4_CBR_PARA g_mpeg4_encode_cbr_para = { 1,       // cbr_func_para1
                                           5,       // cbr_func_para2
                                           1,       // cbr_func_para3
                                           63,      // dct_cut_level1
                                           63,      // dct_cut_level2
                                           63,      // dct_cut_level3
                                           63,      // dct_cut_level4
                                           30,      // md_thre1
                                           500,     // md_thre2
                                           10000,   // md_thre3
                                           200,     // md_thre4
                                           10,      // md_thre5
                                           30,      // md_thre6
                                           10,      // md_thre7
                                           100,     // md_thre8
                                           5,       // md_thre9
                                           400,     // md_thre10
                                           250,     // md_thre11
                                           50,      // md_thre12
                                           557,     // mbrc_thre
                                           58,      // mb_bit_budget
                                           5,       // mbq_lb
                                           10,      // mbq_ub
                                           5,       // mbq_min
                                           31       // mbq_max
                                         };
#if 0
#ifdef DRV_MP4_ENCODE_CBR
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/******************************************************************************
*
*
* MPEG4 HW drivers internal function
*
*
******************************************************************************/
kal_uint32 mpeg4_encore_limit(kal_uint32 len, kal_uint32 line)
{
// UT by cloud
    kal_uint32 limit;

    limit = len >> 2; //the value is counted in word (4-bytes)
#if 1
    if(limit > 0xffff)
    {
        limit = 0xffff;
    }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    limit = limit & 0xfffc;    //4 word align

    if(!limit) EXT_ASSERT(0, limit, len, line);

    drv_trace2(TRACE_GROUP_10, MPEG4HW_MP4_ENC_VLC_LIMIT, limit, line);

    return limit;
}

/******************************************************************************
*
*
* MPEG4 HW for generating VOS, VO, VOL, GOV, VOP headers
*
*
******************************************************************************/

kal_int32 mpeg4_util_log2ceil(kal_int32 arg)
{
    kal_int32 j = 0, i = 1;

    while (arg > i)
    {
        i *= 2;
        j++;
    }

    if (j == 0)
        j = 1;

    return j;
}

void putbits(kal_uint8* in, kal_int32* bitcnt, kal_int32 data, kal_int32 data_length)
{
    kal_uint8 *temp, *temp1;
    kal_int32 t, count, count2;

    t = *bitcnt;
    temp = in;

    if ((t & 0x7) == 0)
        temp[t >> 3] = 0;

    if ((t & 0x7) + data_length <= 8)
    {
        temp[(t >> 3)] |= (data << (8 - ((t & 0x7) + data_length)));
    }
    else
    {
        count = (t & 7) + data_length;

        temp1 = &temp[t >> 3];
        *temp1 |= (data >> (data_length - 8 + (t & 7)));
        count2 = count - 16;
        temp1++;

        while (count2 >= 0)
        {
            *temp1 = (data >> count2) & 0xFF;

            temp1++;
            count2 -= 8;
        }
        *temp1 = (data&((1 << (count % 8)) - 1)) << ((8 - count % 8));
    }

    *bitcnt += data_length;
}

kal_int32 gen_vop(kal_uint8* temp, MPEG4_ENCODER_INFO* header, kal_int32 first)
{
    kal_int32 bitcnt = 0;
    kal_uint32 seconds = 0;
    kal_uint32 rem = 0;
    kal_uint32 duration;
    kal_uint32 old_reference;

    if (header->short_header == 0)
    {
        putbits(temp, &bitcnt, VOP_START_CODE, 32);

        putbits(temp, &bitcnt, header->predition_type == MPEG4_ENCORE_I_VOP ? 0 : 1, 2);

        if (first)
        {
            if(header->fixed_vop_time_increment !=0)
            {
                duration = header->fixed_vop_time_increment;
            }
            else
            {
                duration = (header->u8TimeStamp - header->prev_u8TimeStamp) * header->time_increment / 1000000;
            }
            header->prev_u8TimeStamp = header->u8TimeStamp;

            seconds = (header->vop_time_increment + duration) / header->time_increment;
            header->vop_time_increment =
                rem = (header->vop_time_increment + duration) % header->time_increment;
        }

        while (seconds)
        {
            seconds--;
            putbits(temp, &bitcnt, 1, 1);
        }

        putbits(temp, &bitcnt, 0, 1);         // time_base = 0
        putbits(temp, &bitcnt, 1, 1);         // marker

        seconds = mpeg4_util_log2ceil(header->time_increment);
        putbits(temp, &bitcnt, rem, seconds); // time_inc = 0

        putbits(temp, &bitcnt, 1, 1);         // marker
        putbits(temp, &bitcnt, 1, 1);         // coded

        if (header->predition_type == MPEG4_ENCORE_P_VOP)  // will be changed when support for static sprites is added
            putbits(temp, &bitcnt, 0, 1);

        putbits(temp, &bitcnt, 0, 3);         // intra_dc_vlc_threshold

        putbits(temp, &bitcnt, (kal_int32)(header->quantizer), 5);
        if (header->predition_type != MPEG4_ENCORE_I_VOP)
            putbits(temp, &bitcnt, header->fcode, 3);
    }
    else
    {
        putbits(temp, &bitcnt, SHV_START_CODE, 22);

        //add for short header time
        {
            old_reference = header->time_base;

            if(header->fixed_vop_time_increment !=0)
            {
                duration = header->fixed_vop_time_increment;
            }
            else
            {
                duration = (header->u8TimeStamp - header->prev_u8TimeStamp) * header->time_increment / 1000000;
            }
            header->prev_u8TimeStamp = header->u8TimeStamp;

            seconds = (header->vop_time_increment + duration) / header->time_increment;
            header->vop_time_increment =
                rem = (header->vop_time_increment + duration) % header->time_increment;
            header->time_base = VIDEO_ANYBASE_TO_ANYBASE(duration, (32 *1024), 30);
        }
        // cloud, 101230 
        //putbits(temp, &bitcnt, ((header->time_base + old_reference + 1)&0xff), 8); //temporal_reference
        header->time_base =((header->time_base + old_reference + 1)& 0xff);
        putbits(temp, &bitcnt, header->time_base, 8); //temporal_reference                
        //header->time_base += 6;
        //header->time_base = header->time_base & 0xFF;
        putbits(temp, &bitcnt, 1, 1);                              // marker
        putbits(temp, &bitcnt, 0, 1);                              // zero
        putbits(temp, &bitcnt, 0, 3);                              // split_screen_indicator,document_camera_indicator,full_picture

        if (header->width == 128 && header->height == 96)
            putbits(temp, &bitcnt, 1, 3);                          // source_format
        else if (header->width == 176 && header->height == 144)
            putbits(temp, &bitcnt, 2, 3);                          // source_format
        else if (header->width == 352 && header->height == 288)
            putbits(temp, &bitcnt, 3, 3);                          // source_format
        else if (header->width == 704 && header->height == 576)
            putbits(temp, &bitcnt, 4, 3);                          // source_format
        else
            EXT_ASSERT(0, header->width, header->height, 0);

        putbits(temp, &bitcnt, header->predition_type == MPEG4_ENCORE_I_VOP ? 0 : 1, 1);
        putbits(temp, &bitcnt, 0, 4);                              // four_reserved_zero_bits
        putbits(temp, &bitcnt, (kal_int32)(header->quantizer), 5); // vop_quant
        putbits(temp, &bitcnt, 0, 1);                              // zero
        putbits(temp, &bitcnt, 0, 1);                              // pei
        header->fcode = 1;
    }

    return bitcnt;
}

kal_int32 gen_vos(kal_uint8* temp, MPEG4_ENCODER_INFO* in, MEDIA_STATUS_CODE* result)
{
    kal_int32 bitcnt = 0;
    kal_uint32 vol_control_parameters = 0;

    *result = MEDIA_STATUS_OK;

    if (KAL_TRUE == g_mpeg4_encore_info.enc_info.short_header)
    {
        return bitcnt;
    }

    putbits(temp, &bitcnt, 0x01B0, 32);                // visual_object_sequence_start_code
    putbits(temp, &bitcnt, 1, 8);                          // profile_and_level_indication, 1: Simple Profile/Level 1
    putbits(temp, &bitcnt, 0x01B5, 32);               // visual_object_start_code
    putbits(temp, &bitcnt, 9, 8);                         // 00001001b => is_visual_object_identifier:0 visual_object_type: 0001b (video ID)
    putbits(temp, &bitcnt, VO_START_CODE, 27);
    putbits(temp, &bitcnt, 1, 5);                           // vo_id
    putbits(temp, &bitcnt, VOL_START_CODE_MIN, 32);
    putbits(temp, &bitcnt, 0, 1);                           // random_accessible_vol
    putbits(temp, &bitcnt, 1, 8);                           // video_object_type_indication
    putbits(temp, &bitcnt, 0, 1);                           // is_object_layer_identifier
    putbits(temp, &bitcnt, 1, 4);                           // aspect_ratio_info : square pixels


    putbits(temp, &bitcnt, vol_control_parameters, 1);      // vol_control_parameters

    if (vol_control_parameters)
    {
        putbits(temp, &bitcnt, 1, 2);                           // chroma_format = 4:2:0
        putbits(temp, &bitcnt, 1, 1);                           // low_delay
        putbits(temp, &bitcnt, 1, 1);

        putbits(temp, &bitcnt, (VOS_BIT_RATE >> 15), 15);       // first_half_bit_rate
        putbits(temp, &bitcnt, 1, 1);                           // marker_bit
        putbits(temp, &bitcnt, (VOS_BIT_RATE & 0x7fff), 15);    // latter_half_bit_rate
        putbits(temp, &bitcnt, 1, 1);                           // marker_bit
        putbits(temp, &bitcnt, (VOS_VBV_BUFFER_SIZE >> 3), 15); // first_half_vbv_buffer_size
        putbits(temp, &bitcnt, 1, 1);                           // marker_bit
        putbits(temp, &bitcnt, (VOS_VBV_BUFFER_SIZE & 0x3), 3); // latter_half_vbv_buffer_size
        putbits(temp, &bitcnt, (VOS_OCCUPANCY >> 15), 11);      // first_half_vbv_occupancy
        putbits(temp, &bitcnt, 1, 1);                           // marker_bit
        putbits(temp, &bitcnt, (VOS_OCCUPANCY & 0x7fff), 15);   // latter_half_vbv_occupancy
        putbits(temp, &bitcnt, 1, 1);                           // marker_bit
    }

    putbits(temp, &bitcnt, RECTANGULAR, 2);                 // shape             // is_object_layer_identifier
    putbits(temp, &bitcnt, 1, 1);                           // marker
    putbits(temp, &bitcnt, in->time_increment, 16);         // time_increment_resolution
    /*
    putbits(temp,&bitcnt,1, 1);          // marker
    putbits(temp,&bitcnt,0, 1);          // fixed_vop_rate
    putbits(temp,&bitcnt,1, 1);          // marker
    */
    putbits(temp, &bitcnt, 5, 3); // marker

    putbits(temp, &bitcnt, in->width, 13);
    putbits(temp, &bitcnt, 1, 1); // marker
    putbits(temp, &bitcnt, in->height, 13);
    /*
    putbits(temp,&bitcnt,1, 1);         // marker
    putbits(temp,&bitcnt,0, 1);         // kal_int32erlaced
    putbits(temp,&bitcnt,1, 1);         // obmc_disable on
    putbits(temp,&bitcnt,0, 1);         // sprite_usage //version 1
    putbits(temp,&bitcnt,0, 1);         // [Ag] not 8bits
    putbits(temp,&bitcnt,0, 1);         // H.263 quant_type
    putbits(temp,&bitcnt,1, 1);         // complexity_estimation_disable
    putbits(temp,&bitcnt,1, 1);         // resync_marker_disable
    putbits(temp,&bitcnt,0, 1);         // data_partitioning off
    putbits(temp,&bitcnt,0, 1);         // scalability
    putbits(temp,&bitcnt,0, 1);
    */
    if(in->b_resync_marker == KAL_TRUE)
    {
        putbits(temp, &bitcnt, 0x510, 11); // marker, kal_int32erlaced, obmc_disable on, sprite_usage, not 8bits, H.263 quant_type
    }
    else
    {
        putbits(temp, &bitcnt, 0x518, 11); // marker, kal_int32erlaced, obmc_disable on, sprite_usage, not 8bits, H.263 quant_type
    }
    putbits(temp, &bitcnt, (1 << (8 - (bitcnt & 7))) - 1, (8 - (bitcnt & 7)));

    if (bitcnt > (ENC_MAX_VOS_SIZE * 8))
    {
        VIDEO_WARNING(VIDEO_DBG_OWNER_ENCODER);

        *result = VIDEO_ERROR;
        return -1;
    }

    return bitcnt;
}

/******************************************************************************
*
*
* MPEG4 HW ISRs
*
*
******************************************************************************/

void mpeg4_encore_lisr(void)
{
#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT
    static kal_uint32 mpeg4_bm_start_time, mpeg4_bm_end_time, mpeg4_bm_total_time;
    mpeg4_bm_start_time = drv_get_current_time();
#endif

    IRQMask(IRQ_MPEG4_ENC_CODE);
    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ISR, video_get_current_time());
    visual_active_hisr(VISUAL_MPEG4_ENC_HISR_ID);

#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT
    mpeg4_bm_end_time = drv_get_current_time();
    mpeg4_bm_total_time = drv_get_duration_tick(mpeg4_bm_start_time, mpeg4_bm_end_time);
    mpeg4_lisr_time_measure(mpeg4_bm_total_time);
#endif
}


void mpeg4_encore_hisr(void)
{
    kal_uint32 status;
    kal_uint32 temp_ptr;
    kal_uint32 temp_int;
    kal_uint32 bitcnt;
    kal_uint32 frame_length;
    RC_UPDATE_PARAM rc_input_param;
    RC_RESULT rc_result;
    MPEG4_ENCODER_INFO* enc_info = &g_mpeg4_encore_info.enc_info;
    MPEG4_ENCORE_FRAME_INFO* frame_info = &g_mpeg4_encore_info.frame_info;

#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT
    static kal_uint32 mpeg4_bm_start_time, mpeg4_bm_end_time, mpeg4_bm_total_time;
    mpeg4_bm_start_time = drv_get_current_time();
#endif

    drv_trace2(TRACE_GROUP_10, MPEG4HW_ENTER_HISR, enc_info->u8TimeStamp, (kal_uint32)g_mpeg4_encore_info.encode_yuv);

    status = DRV_Reg32(MP4_ENC_IRQ_STS);
    DRV_WriteReg32(MP4_ENC_IRQ_ACK, status);

    if (!status)
    {
        VIDEO_WARNING(VIDEO_DBG_OWNER_ENCODER);
        video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ISR_ERROR, video_get_current_time());
        VideoEncoderUpdateBitstreamWP(g_mpeg4_encore_info.bits_buffer_end, 0);
        MPEG4HWHwResourceFree(VIDEO_MPEG4HW_ENC);
        MPEG4EncCallbackYUVDone(g_mpeg4_encore_info.encode_yuv);
#if ENC_BLOCKING
    kal_set_eg_events(g_mpeg4_encore_info.eEncodeComplete, MP4_HW_ENC_COMPLETE, KAL_OR);
#endif
        goto MPEG4HW_HIRT_EXIT;
    }

    if (status & MP4_ENC_IRQ_STS_ENC) // encode done
    {
#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT
        mpeg4_encode_time_measure(DRV_Reg32(MP4_ENC_CYCLE_COUNT));
#endif
        video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENC_DONE, video_get_current_time());

        if(g_mpeg4_encore_info.drop_bitstream)
        {
            //VideoEncoderUpdateBitstreamWP((kal_uint8 *)g_mpeg4_encore_info.current_bitstream_addr, 0);
            g_mpeg4_encore_info.drop_bitstream = KAL_FALSE;
            frame_info->drop = KAL_TRUE;
            frame_info->took_away = KAL_FALSE;
            MPEG4HWHwResourceFree(VIDEO_MPEG4HW_ENC);
            MPEG4EncCallbackYUVDone(g_mpeg4_encore_info.encode_yuv);
            MPEG4EncCallbackBITSDone();
#if ENC_BLOCKING
    kal_set_eg_events(g_mpeg4_encore_info.eEncodeComplete, MP4_HW_ENC_COMPLETE, KAL_OR);
#endif
            goto MPEG4HW_HIRT_EXIT;
        }

        temp_ptr = DRV_Reg32(MP4_ENC_VLC_WORD);
        temp_int = DRV_Reg32(MP4_ENC_VLC_BITCNT);
        bitcnt = (temp_ptr - g_mpeg4_encore_info.current_bitstream_addr) * 8 + temp_int;
#ifdef __VE_VIDEO_VT_SUPPORT__        
        enc_info->mbrc_q_sum = DRV_Reg32(MP4_ENC_MBRC_Q_SUM);
#endif
        /********************************************************
        *  Do the rate control
        ********************************************************/
        kal_mem_set(&rc_input_param, 0, sizeof(RC_UPDATE_PARAM));

        rc_input_param.bitrate = enc_info->bit_rate;
        rc_input_param.frame_rate = enc_info->frame_rate;
        rc_input_param.quant = enc_info->quantizer;
        rc_input_param.width = enc_info->width;
        rc_input_param.height = enc_info->height;
        rc_input_param.bitcount = bitcnt;

        if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_REC)
        {
            rc_input_param.predition_type = (kal_int32)enc_info->predition_type;
            rc_input_param.total_frames = g_mpeg4_encore_info.total_frames;
            rc_input_param.b_force_I_frame = g_mpeg4_encore_info.force_i_frame;
            rc_input_param.mode = 1;
        }
        else if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
        {
            rc_input_param.total_frames = g_mpeg4_encore_info.total_frames;
            rc_input_param.intra_period = enc_info->frame_rate;
            rc_input_param.q_accu = enc_info->mbrc_q_sum;
            rc_input_param.b_force_I_frame = KAL_FALSE;
        }
        else
        {
            ASSERT(0);
        }

        // calling rate control function
        rc_result = mpeg4_RC_UPdated(rc_input_param);

        if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
        {
            enc_info->is_drop_nxt_frm = rc_result.is_drop_nxt_frm;
            enc_info->is_encode_i_nxt_frm = rc_result.is_encode_i_nxt_frm;
            enc_info->mbrc_thre = rc_result.mbrc_thre;
            enc_info->mb_bit_budget = rc_result.mb_bit_budget;
            enc_info->mbq_lb = rc_result.mbq_lb;
            enc_info->mbq_ub = rc_result.mbq_ub;
            enc_info->cbr_dct_lev = rc_result.cbr_dct_lev;
        }
        enc_info->quantizer = rc_result.quant;
        enc_info->intra_threshold = rc_result.intra_threshold;
        /********************************************************
        *  ~Do the rate control
        ********************************************************/


        // stuffing bits to byte-aligned
        if (enc_info->short_header)
        {
            // short-header mode: stuffing bits all zeros
            while ((bitcnt & 7) != 0)
            {
                putbits((kal_uint8 *)g_mpeg4_encore_info.current_bitstream_addr, (kal_int32 *)&bitcnt,0,1);
            }

        }
        else
        {
            // stuffing bits: one zero and followed by 1 to 7 ones
            putbits((kal_uint8 *)g_mpeg4_encore_info.current_bitstream_addr, (kal_int32 *)&bitcnt,0,1);
            while ((bitcnt & 7) != 0)
            {
                putbits((kal_uint8 *)g_mpeg4_encore_info.current_bitstream_addr, (kal_int32 *)&bitcnt,1,1);
            }
        }

        frame_length = (bitcnt / 8) + (((bitcnt & 7) == 0) ? 0 : 1);
        VideoEncoderUpdateBitstreamWP((kal_uint8 *)(g_mpeg4_encore_info.current_bitstream_addr+frame_length), 1);

        frame_info->total_len += frame_length;
        frame_info->pkt_info[frame_info->pkt_num].u4Addr = g_mpeg4_encore_info.current_bitstream_addr;
        frame_info->pkt_info[frame_info->pkt_num].u4Size = frame_length;
        frame_info->took_away = KAL_FALSE;
        g_mpeg4_encore_info.total_saved_bytes += frame_info->pkt_info[frame_info->pkt_num].u4Size;

        frame_info->pkt_num++;

        // rec&ref address exchange
        temp_int = DRV_Reg32(MP4_ENC_REF_ADDR);
        DRV_WriteReg32(MP4_ENC_REF_ADDR, DRV_Reg32(MP4_ENC_REC_ADDR));
        DRV_WriteReg32(MP4_ENC_REC_ADDR, temp_int);

        video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_TOTAL_ENCODE, g_mpeg4_encore_info.hisr_total_frames);
        drv_trace2(TRACE_GROUP_10, MPEG4HW_DMA_ENCODED_FRAME, g_mpeg4_encore_info.hisr_total_frames, frame_info->total_len);
        g_mpeg4_encore_info.hisr_total_frames++;

        MPEG4HWHwResourceFree(VIDEO_MPEG4HW_ENC);
        MPEG4EncCallbackYUVDone(g_mpeg4_encore_info.encode_yuv);
        MPEG4EncCallbackBITSDone();

#if ENC_BLOCKING
    kal_set_eg_events(g_mpeg4_encore_info.eEncodeComplete, MP4_HW_ENC_COMPLETE, KAL_OR);
#endif

    }
    else if(status&MP4_ENC_IRQ_STS_DMA) // DMA limit
    {
        kal_uint32 u4AvailLen = 0, rest;
        kal_uint8* pu1Curr = NULL;
        kal_uint8* pu1Next;
        kal_bool   fgConti = KAL_FALSE;

        video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENC_DMA, video_get_current_time());

        if (!g_mpeg4_encore_info.drop_bitstream)
        {
//          pu1Curr = (kal_uint8 *)(g_mpeg4_encore_info.current_bitstream_addr + g_mpeg4_encore_info.avail_len * 4);
            pu1Curr = g_mpeg4_encore_info.bits_trigger_limit;
            VideoEncoderQueryBitstreamNewWP(pu1Curr, &pu1Next, &u4AvailLen);
        }
        if (pu1Next == pu1Curr)
        {
            fgConti = KAL_TRUE;
        }

        drv_trace2(TRACE_GROUP_10, MPEG4HW_DMA_LIMIT_HIT, u4AvailLen, fgConti);

        /********************************************************
        *  no available buffer
        ********************************************************/
        if(!u4AvailLen)
        {
            drv_trace1(TRACE_GROUP_10, MPEG4HW_MP4_HISR_DMA, 1);
            // drop the frame and encode the rest to the dummy buffer
            g_mpeg4_encore_info.drop_bitstream = KAL_TRUE;

            DRV_WriteReg32(MP4_CORE_VLC_LIMIT, (ENC_MAX_RESUME_BUFFER_SIZE >> 2));
            DRV_WriteReg32(MP4_CORE_VLC_ADDR, (kal_uint32)g_mpeg4_encore_info.res_mem_addr);
            DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);

            video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENC_DROP, video_get_current_time());
        }
        /********************************************************
        *  available buffer is continuous
        ********************************************************/
        else if(u4AvailLen >= 16 && fgConti)
        {
            kal_uint32 limit;

            frame_info->total_len += ((kal_uint32)pu1Curr - g_mpeg4_encore_info.current_bitstream_addr);
            frame_info->pkt_info[frame_info->pkt_num].u4Addr = g_mpeg4_encore_info.current_bitstream_addr;
            frame_info->pkt_info[frame_info->pkt_num].u4Size = ((kal_uint32)pu1Curr - g_mpeg4_encore_info.current_bitstream_addr);
            g_mpeg4_encore_info.total_saved_bytes += frame_info->pkt_info[frame_info->pkt_num].u4Size;
            frame_info->pkt_num++;

            limit = mpeg4_encore_limit(u4AvailLen, __LINE__);
            drv_trace1(TRACE_GROUP_10, MPEG4HW_MP4_HISR_DMA, 2);
            // continuous to do the encoding
            DRV_WriteReg32(MP4_CORE_VLC_LIMIT, limit);
            DRV_WriteReg32(MP4_CORE_VLC_ADDR, (kal_uint32)pu1Next);
            DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);

            g_mpeg4_encore_info.current_bitstream_addr = (kal_uint32)pu1Next;
            g_mpeg4_encore_info.avail_len = limit;
            g_mpeg4_encore_info.bits_trigger_limit = (kal_uint8*)g_mpeg4_encore_info.current_bitstream_addr + limit * 4;

            video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENC_RESUM_CONTI, video_get_current_time());
        }
        /********************************************************
        *  available buffer is not continuous
        ********************************************************/
        else //if(u4AvailLen && !fgConti)
        {
            kal_uint32 limit;
            drv_trace1(TRACE_GROUP_10, MPEG4HW_MP4_HISR_DMA, 3);
/*
#if 0
            if ( DRV_Reg32(MP4_CORE_VLC_WORD) != (DRV_Reg32(MP4_ENC_VLC_ADDR)+DRV_Reg32(MP4_ENC_VLC_LIMIT)*4) )
            {
            vlc_addr = DRV_Reg32(MP4_CORE_VLC_WORD) + 4;
            }
#else
            vlc_addr = (DRV_Reg32(MP4_ENC_VLC_ADDR)+DRV_Reg32(MP4_ENC_VLC_LIMIT)*4);
#endif
*/
            rest = (kal_uint32)g_mpeg4_encore_info.bits_buffer_end - (kal_uint32)pu1Curr;
            kal_prompt_trace(MOD_VIDEO, "DMA Limit: pu1Curr 0x%x, bits_buffer_end 0x%x, rest %d", pu1Curr, g_mpeg4_encore_info.bits_buffer_end, rest);
            if(rest)
            {
                VideoEncoderUpdateBitstreamWP((kal_uint8 *)pu1Curr, 1);
                VideoEncoderUpdateBitstreamWP(g_mpeg4_encore_info.bits_buffer_end, 0);
            }
            else
            {
                VideoEncoderUpdateBitstreamWP(g_mpeg4_encore_info.bits_buffer_end, 1);
            }
            frame_info->total_len += ((kal_uint32)pu1Curr - g_mpeg4_encore_info.current_bitstream_addr);
            frame_info->pkt_info[frame_info->pkt_num].u4Addr = g_mpeg4_encore_info.current_bitstream_addr;
            frame_info->pkt_info[frame_info->pkt_num].u4Size = ((kal_uint32)pu1Curr - g_mpeg4_encore_info.current_bitstream_addr);

            g_mpeg4_encore_info.total_saved_bytes += frame_info->pkt_info[frame_info->pkt_num].u4Size;
            frame_info->pkt_num++;

            // continuous to do the encoding
            if(u4AvailLen < 16)
            {
                kal_uint8* pu1StartAddr;
                kal_uint8* pu1EndAddr;
                kal_uint8* pu1WritePtr;
                kal_uint8* pu1ReadAddr;
                kal_uint32 u4BuffLen;

                VideoEncoderAllocateBitstreamBuffer(&pu1StartAddr, &pu1EndAddr, &pu1WritePtr, &pu1ReadAddr, &u4BuffLen);
                pu1Next = pu1WritePtr;
                if ((kal_uint32)pu1ReadAddr <= (kal_uint32)pu1WritePtr)
                {
                    u4AvailLen = (kal_uint32)pu1EndAddr - (kal_uint32)pu1WritePtr;
                }
                else
                {
                    u4AvailLen = (kal_uint32)pu1ReadAddr - (kal_uint32)pu1WritePtr;
                }
            }
            g_mpeg4_encore_info.current_bitstream_addr = (kal_uint32)pu1Next;

            limit = mpeg4_encore_limit(u4AvailLen, __LINE__);
            g_mpeg4_encore_info.avail_len = limit;
            DRV_WriteReg32(MP4_CORE_VLC_LIMIT, limit);
            DRV_WriteReg32(MP4_CORE_VLC_ADDR, (kal_uint32)pu1Next);
            DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);
            g_mpeg4_encore_info.bits_buffer_end = (kal_uint8 *)(pu1Next+u4AvailLen);
            g_mpeg4_encore_info.bits_trigger_limit = (kal_uint8*)g_mpeg4_encore_info.current_bitstream_addr + limit * 4;

            video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENC_RESUM_NOT_CONTI, video_get_current_time());
        }
    }

MPEG4HW_HIRT_EXIT:
    IRQUnmask(IRQ_MPEG4_ENC_CODE);

    drv_trace0(TRACE_GROUP_10, MPEG4HW_EXIT_HISR);


#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT
    mpeg4_bm_end_time = drv_get_current_time();
    mpeg4_bm_total_time = drv_get_duration_tick(mpeg4_bm_start_time, mpeg4_bm_end_time);
    mpeg4_hisr_time_measure(mpeg4_bm_total_time);
#endif
}

/******************************************************************************
*
*
* MPEG4 HW drivers external function
*
*
******************************************************************************/

MPEG4_ENCORE_FRAME_INFO* mpeg4_encore_get_frame_info(void)
{
    return &g_mpeg4_encore_info.frame_info;
}

kal_bool mpeg4_encore_check_encoder_status(void)
{
    if (g_mpeg4_encore_info.state == MPEG4_ENCORE_STATE_RUN ||
        g_mpeg4_encore_info.state == MPEG4_ENCORE_STATE_PAUSE)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

kal_bool mepg4_encore_check_bits_buffer_status(void)
{
    if (!g_mpeg4_encore_info.frame_info.took_away)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

/******************************************************************************
*
*
* MPEG4 HW driver functions
*
*
******************************************************************************/

kal_bool mpeg4_encore_open(void *param)
{
    kal_bool ret = KAL_TRUE;
    kal_uint32 u4MaxWidth, u4MaxHeight;
    MPEG4_ENCORE_MEM_INFO* init_param = (MPEG4_ENCORE_MEM_INFO*)param;

    g_mpeg4_encore_info.state = MPEG4_ENCORE_STATE_OPEN;

    if(g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
    {
#ifdef __VE_VIDEO_VT_SUPPORT__
        u4MaxWidth = MPEG4_ENC_VT_MAX_WIDTH;
        u4MaxHeight = MPEG4_ENC_VT_MAX_HEIGHT;
#else
        ASSERT(0);
#endif
    }
    else
    {
        u4MaxWidth = MPEG4_HW_ENC_MAX_WIDTH;
        u4MaxHeight = MPEG4_HW_ENC_MAX_HEIGHT;
    }


    /********************************************************
    *  keep related memory address & size
    ********************************************************/
    g_mpeg4_encore_info.int_mem_addr = init_param->int_mem_addr;
    g_mpeg4_encore_info.int_mem_size = init_param->int_mem_size;
    g_mpeg4_encore_info.ext_mem_addr = init_param->ext_mem_addr;
    g_mpeg4_encore_info.ext_mem_size = init_param->ext_mem_size;
    g_mpeg4_encore_info.res_mem_addr = init_param->res_mem_addr;
    g_mpeg4_encore_info.res_mem_size = init_param->res_mem_size;


    /********************************************************
    *  internal memory partition
    ********************************************************/
    g_mpeg4_encore_info.workmem_dacp = init_param->int_mem_addr;
    g_mpeg4_encore_info.workmem_data_store = init_param->int_mem_addr + 1024;
    g_mpeg4_encore_info.workmem_mvp = init_param->int_mem_addr + 1024 + 3072;
    g_mpeg4_encore_info.workmem_ref_int = init_param->int_mem_addr + 1024 + 3072 + 360;
    g_mpeg4_encore_info.workmem_cur_int = init_param->int_mem_addr + 1024 + 3072 + 360 + (u4MaxWidth*(56+32));


    /********************************************************
    *  external memory partition
    ********************************************************/
    g_mpeg4_encore_info.workmem_ref = init_param->ext_mem_addr;
    g_mpeg4_encore_info.workmem_rec = init_param->ext_mem_addr + (u4MaxWidth*u4MaxHeight*3/2);


    /********************************************************
    *  init hardware resource
    ********************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    //MPEG4HWOpen(VIDEO_MPEG4HW_ENC);
    MPEG4HWOpen(VIDEO_MPEG4HW_ENC);
#endif
    // switch GMC
    DRV_WriteReg32(MP4_SWITCH_GMC_PORT, 0);


    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_OPEN, 1);

    return ret;
}


kal_bool mpeg4_encore_init(void)
{
    kal_bool ret = KAL_TRUE;
    kal_uint8 index;
    kal_uint32 savedMask, value;
    MPEG4_ENCODER_INFO* enc_info;

    /**********    SetIRQMask    **********/ savedMask = SaveAndSetIRQMask();

    /********************************************************
    *  reset hardware
    ********************************************************/
    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_ENC_RST);
    for (index = 0; index < 20; index++) ;
    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_CORE_RST);
    for (index = 0; index < 20; index++) ;
    DRV_WriteReg32(MP4_CODEC_COMD, 0);


    /********************************************************
    *  register LISR/HISR
    ********************************************************/
    IRQ_Register_LISR(IRQ_MPEG4_ENC_CODE, mpeg4_encore_lisr, "MPEG4");
    VISUAL_Register_HISR(VISUAL_MPEG4_ENC_HISR_ID, mpeg4_encore_hisr);
    IRQSensitivity(IRQ_MPEG4_ENC_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_MPEG4_ENC_CODE);

    /**********    RestoreIRQMask    **********/ RestoreIRQMask(savedMask);

    if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
    {
        g_mpeg4_encore_info.enc_info.b_is_cbr = KAL_TRUE;
    }
    else
    {
        g_mpeg4_encore_info.enc_info.b_is_cbr = KAL_FALSE;
    }

    /********************************************************
    *  init rate control
    ********************************************************/
    {

    RC_INIT_PARAM rc_input_param;
    RC_RESULT rc_result;
    enc_info = &g_mpeg4_encore_info.enc_info;

    ASSERT(enc_info->frame_rate);

    kal_mem_set(&rc_input_param, 0, sizeof(RC_INIT_PARAM));

    rc_input_param.bitrate = enc_info->bit_rate;
    rc_input_param.frame_rate = enc_info->frame_rate;
    rc_input_param.pixels_per_frame = enc_info->width * enc_info->height;
    rc_input_param.b_is_cbr = enc_info->b_is_cbr;

    //cloud, 100927
    rc_input_param.width = enc_info->width;
    rc_input_param.height = enc_info->height;
    rc_input_param.cbr_func_para1 = g_mpeg4_encode_cbr_para.cbr_func_para1;
    rc_input_param.cbr_func_para2 = g_mpeg4_encode_cbr_para.cbr_func_para2;
    rc_input_param.cbr_func_para3= g_mpeg4_encode_cbr_para.cbr_func_para3;

    rc_result = mpeg4_init_RC(rc_input_param);

    enc_info->quantizer = rc_result.quant;
    enc_info->intra_threshold = rc_result.intra_threshold;

    if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_REC)
    {
        enc_info->time_increment = (kal_int32)(enc_info->frame_rate/10);
        enc_info->fixed_vop_time_increment = (kal_int32)(enc_info->time_increment / (enc_info->frame_rate/10));
        enc_info->vop_time_increment = -1 * enc_info->fixed_vop_time_increment;
    }
    else if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
    {
        enc_info->mbrc_thre = rc_result.mbrc_thre;
        enc_info->mb_bit_budget = rc_result.mb_bit_budget;
        enc_info->mbq_lb = rc_result.mbq_lb;
        enc_info->mbq_ub = rc_result.mbq_ub;
        enc_info->cbr_dct_lev = rc_result.cbr_dct_lev;
        enc_info->is_drop_nxt_frm = rc_result.is_drop_nxt_frm;
        enc_info->is_encode_i_nxt_frm = rc_result.is_encode_i_nxt_frm;

//        enc_info->time_increment = 32 * 1024 - 1;
        enc_info->fixed_vop_time_increment = 0;
        enc_info->vop_time_increment = 0;
        enc_info->prev_u8TimeStamp = 0;
        enc_info->u8TimeStamp = 0;
        ASSERT(enc_info->time_increment !=  0);
    }
    }


    /********************************************************
    *  set to registers
    ********************************************************/
    DRV_WriteReg32(MP4_ENC_REF_ADDR,      (kal_int32)g_mpeg4_encore_info.workmem_ref);
    DRV_WriteReg32(MP4_ENC_REC_ADDR,      (kal_int32)g_mpeg4_encore_info.workmem_rec);
    DRV_WriteReg32(MP4_ENC_DACP_ADDR,     (kal_int32)g_mpeg4_encore_info.workmem_dacp);
    DRV_WriteReg32(MP4_ENC_STORE_ADDR,    (kal_int32)g_mpeg4_encore_info.workmem_data_store);
    DRV_WriteReg32(MP4_ENC_MVP_ADDR,      (kal_int32)g_mpeg4_encore_info.workmem_mvp);
    DRV_WriteReg32(MP4_ENC_REF_INT_ADDR,  (kal_int32)g_mpeg4_encore_info.workmem_ref_int);
    DRV_WriteReg32(MP4_ENC_CUR_INT_ADDR,  (kal_int32)g_mpeg4_encore_info.workmem_cur_int);

    value = 0;

    value = MP4_ENC_CODEC_CONF_ENC | MP4_ENC_CODEC_CONF_IRQ | MP4_ENC_CODEC_CONF_DCT | MP4_ENC_CODEC_CONF_HALF |
            MP4_ENC_CODEC_CONF_FME | MP4_ENC_CODEC_CONF_PMV | MP4_ENC_CODEC_CONF_MC_BURST | MP4_ENC_CODEC_CONF_STEP_VALUE |
            MP4_ENC_CODEC_CONF_PREFETCH;

    if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
    {
        #ifdef DRV_MP4_ENCODE_CBR
        value |= (MP4_ENC_CODEC_CONF_CBR_EN | MP4_ENC_CODEC_CONF_MD_EN);
        #endif
    }

    DRV_WriteReg32(MP4_ENC_CODEC_CONF, value);
    DRV_WriteReg32(MP4_ENC_IRQ_MASK, (MP4_ENC_IRQ_MASK_BLOCK | MP4_ENC_IRQ_MASK_PACK));


    /********************************************************
    *  init control variables
    ********************************************************/
    g_mpeg4_encore_info.total_frames = 0;
    g_mpeg4_encore_info.hisr_total_frames = 0;
    g_mpeg4_encore_info.force_i_frame = KAL_FALSE;
    g_mpeg4_encore_info.frame_info.pkt_num = 0;
    g_mpeg4_encore_info.frame_info.took_away = KAL_TRUE;
    g_mpeg4_encore_info.drop_bitstream = KAL_FALSE;


    /********************************************************
    *  init encode info variables
    ********************************************************/
    enc_info->intra_num = 0;
    enc_info->fcode = 1;

#ifdef ENC_BLOCKING
    if(g_mpeg4_encore_info.eEncodeComplete== 0)
    {
        g_mpeg4_encore_info.eEncodeComplete = kal_create_event_group("MP4_HW_ENC_EVENT");
    }
#endif

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_INIT, 1);

    return ret;
}


kal_bool mpeg4_encore_gen_vos_VT(kal_uint8* addr, kal_uint32 avail_len, MP4HwEncVT_VOS_PAR *VOSSetting, kal_uint32* write_len)
{
    kal_bool ret = KAL_TRUE;
    MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
    kal_int32 bitcnt = 0;
    MPEG4_ENCODER_INFO enc_info;
    enc_info.time_increment = VOSSetting->vop_time_increment_resolution;
    enc_info.width = VOSSetting->width;
    enc_info.height = VOSSetting->height;
    enc_info.b_resync_marker = KAL_TRUE;

    bitcnt = gen_vos(addr, &enc_info, &result);

    if (result != MEDIA_STATUS_OK)
    {
        ret = KAL_FALSE;
    }
    else
    {
        *write_len = bitcnt/8;
        ASSERT(*write_len<avail_len);
        ASSERT(!(bitcnt%8));
    }

    return ret;
}

kal_bool mpeg4_encore_gen_vos(kal_uint8* addr, kal_uint32 avail_len, kal_uint32* write_len)
{
    kal_bool ret = KAL_TRUE;
    MEDIA_STATUS_CODE result = MEDIA_STATUS_OK;
    kal_int32 bitcnt = 0;
    MPEG4_ENCODER_INFO* enc_info = &g_mpeg4_encore_info.enc_info;
    MPEG4_ENCORE_FRAME_INFO* frame_info = &g_mpeg4_encore_info.frame_info;

    frame_info->encode_done = KAL_FALSE;

    bitcnt = gen_vos(addr, enc_info, &result);

    if (result != MEDIA_STATUS_OK)
    {
        ret = KAL_FALSE;
    }
    else if(bitcnt > 0)
    {
        *write_len = bitcnt/8;
        ASSERT(*write_len<avail_len);
        ASSERT(!(bitcnt%8));

        if(!g_mpeg4_encore_info.frame_info.took_away)
            ASSERT(0);

        frame_info->bits_type = MPEG4_ENCORE_HEADER;
        frame_info->took_idx = 0;
        frame_info->took_away = KAL_FALSE;
        frame_info->pkt_num  = 1;
        frame_info->start_ptr = addr;
        frame_info->total_len = *write_len;
        frame_info->pkt_info[0].u4Addr = (kal_uint32)addr;
        frame_info->pkt_info[0].u4Size = *write_len;
    }

    frame_info->encode_done = KAL_TRUE;

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_GEN_VOS, 1);

    return ret;
}


kal_bool mpeg4_encore_encode(kal_uint8* encode_yuv, kal_uint64 timestamp, kal_uint8* write_ptr, kal_uint8* buff_end)
{
    kal_bool   ret = KAL_TRUE;
    kal_uint32 bitcnt = 0;
    kal_int32  skip_threshold;
    kal_int32  temp, temp_ptr, temp_int;
    kal_uint32 mb_length, limit = 0;
    MPEG4_ENCODER_INFO* enc_info = &g_mpeg4_encore_info.enc_info;
    MPEG4_ENCORE_FRAME_INFO* frame_info = &g_mpeg4_encore_info.frame_info;

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_ENCODE, (kal_uint32)encode_yuv);

    if(!MPEG4HWHwResourceGet(VIDEO_MPEG4HW_ENC))
        ASSERT(0);

    ASSERT(encode_yuv);

    g_mpeg4_encore_info.encode_yuv = encode_yuv;
    g_mpeg4_encore_info.total_frames++;
    g_mpeg4_encore_info.current_bitstream_addr = (kal_uint32)write_ptr;

    /* VOP should be 8 bytes aligned */
    if(((kal_int32)g_mpeg4_encore_info.encode_yuv & 0x7))
    {
        EXT_ASSERT(0, (kal_int32)g_mpeg4_encore_info.encode_yuv, 0, 0);
    }

    DRV_WriteReg32(MP4_ENC_VOP_ADDR, (kal_int32)encode_yuv);
#if 1 //cloud workaround, 1102
    if (( (enc_info->b_is_cbr) && (enc_info->is_encode_i_nxt_frm)) ||
        (!(enc_info->b_is_cbr) && !((g_mpeg4_encore_info.total_frames-1) % enc_info->i_interval))
       )
#else
/* under construction !*/
#endif
    {
        enc_info->predition_type = MPEG4_ENCORE_I_VOP;
        enc_info->intra_num++;
    }
    else
    {
        if(!g_mpeg4_encore_info.force_i_frame)
        {
            enc_info->predition_type = MPEG4_ENCORE_P_VOP;
        }
        else
        {
            enc_info->predition_type = MPEG4_ENCORE_I_VOP;
            enc_info->intra_num++;
        }
    }

    if(g_mpeg4_encore_info.force_i_frame)
    {
        g_mpeg4_encore_info.force_i_frame = KAL_FALSE;
    }

    drv_trace4(TRACE_GROUP_10, MPEG4HW_MP4_CBR_I_FRAME, (kal_uint32)encode_yuv, enc_info->predition_type, enc_info->is_encode_i_nxt_frm, 0);

    enc_info->u8TimeStamp = timestamp;
    bitcnt = gen_vop(write_ptr, enc_info, 1);

    g_mpeg4_encore_info.frame_info.fcode = enc_info->fcode;

    skip_threshold = mpeg4_enc_get_skip_threshold(enc_info->quantizer);

    DRV_WriteReg32(MP4_ENC_CONF,
        (skip_threshold << MP4_ENC_CONF_SKIP_BITCNT) | (enc_info->intra_threshold<< MP4_ENC_CONF_INTRA_BITCNT));

    if(enc_info->max_pkt_size != 0)
    {
        DRV_WriteReg32(MP4_ENC_RESYNC_CONF0, MP4_ENC_RESYNC_CONF0_MODE_EN | MP4_ENC_RESYNC_CONF0_MODE_BITS
            | ((enc_info->max_pkt_size >> 1) & MP4_ENC_RESYNC_CONF0_PERIOD_BITS_MASK));
    }
    else
    {
        DRV_WriteReg32(MP4_ENC_RESYNC_CONF0, 0);
    }


    /********************************************************
    *  MP4_ENC_VOP_STRUC0
    ********************************************************/
    temp = ((enc_info->predition_type == MPEG4_ENCORE_I_VOP ? 1 : 0) << MP4_ENC_VOP_STRUC0_TYPE_BITCNT)
       | (0 << MP4_ENC_VOP_STRUC0_DATA_BITCNT) /*data_partition*/
       | (enc_info->fcode << MP4_ENC_VOP_STRUC0_FCODE_BITCNT)
       | (0 << MP4_ENC_VOP_STRUC0_ROUND_BITCNT)                                              /*RoundingType*/
       | (((kal_int32)(enc_info->quantizer)) << MP4_ENC_VOP_STRUC0_QUANT_BITCNT)
       | (enc_info->short_header << MP4_ENC_VOP_STRUC0_SHORT_BITCNT);
    DRV_WriteReg32(MP4_ENC_VOP_STRUC0, temp);


    /********************************************************
    *  MP4_ENC_VOP_STRUC1
    ********************************************************/
    mb_length = ( mpeg4_util_log2ceil(((enc_info->height+15)/16)*((enc_info->width+15)/16)) );
    DRV_WriteReg32(MP4_ENC_VOP_STRUC1,
        ( (enc_info->width >> 4) << MP4_ENC_VOP_STRUC1_XLIMIT_BITCNT)
        | ((enc_info->height >> 4) << MP4_ENC_VOP_STRUC1_YLIMIT_BITCNT)
        | (mb_length << MP4_ENC_VOP_STRUC1_MBLENGTH_BITCNT));


    /********************************************************
    *  MP4_ENC_VOP_STRUC2
    ********************************************************/
    DRV_WriteReg32(MP4_ENC_VOP_STRUC2,
        (enc_info->width >> 4) * (enc_info->height >> 4) << MP4_ENC_VOP_STRUC2_MBCOUNT_BITCNT);


    /********************************************************
    *  MP4_ENC_VOP_STRUC3
    ********************************************************/
    DRV_WriteReg32(MP4_ENC_VOP_STRUC3, 0);


    temp_ptr = (kal_int32)write_ptr + (bitcnt >> 3);
    temp_int = bitcnt & 0x7;

    temp_int += (temp_ptr & 0x3) * 8;
    temp_ptr -= (temp_ptr & 0x3);

    DRV_WriteReg32(MP4_ENC_VLC_ADDR, temp_ptr);
    DRV_WriteReg32(MP4_ENC_VLC_BIT, temp_int);
    drv_trace1(TRACE_GROUP_10, MPEG4HW_MP4_ENC_VLC_ADDR, DRV_Reg32(MP4_ENC_VLC_ADDR));

    limit = ((kal_uint32)buff_end - (kal_uint32)temp_ptr);
    g_mpeg4_encore_info.bits_buffer_end = (kal_uint8 *)(temp_ptr + limit);
    drv_trace4(TRACE_GROUP_10, MPEG4HW_MP4_ENC_PARAM, bitcnt, limit, (kal_uint32)write_ptr, (kal_uint32)buff_end);

    limit = mpeg4_encore_limit(limit, __LINE__);
    DRV_WriteReg32(MP4_ENC_VLC_LIMIT, limit);    // 16 bit

    g_mpeg4_encore_info.avail_len = limit;
    g_mpeg4_encore_info.bits_trigger_limit= (kal_uint8 *)(temp_ptr + limit * 4 );


#ifdef DRV_MP4_ENCODE_CBR
    /********************************************************
    *  CBR related parameters
    ********************************************************/
    if(enc_info->b_is_cbr) {
        temp  = 0;
        temp |= enc_info->cbr_dct_lev.dct_cut_level1;
        temp |= enc_info->cbr_dct_lev.dct_cut_level2<<8;
        temp |= enc_info->cbr_dct_lev.dct_cut_level3<<16;
        temp |= enc_info->cbr_dct_lev.dct_cut_level4<<24;
        DRV_WriteReg32(MP4_ENC_DCT_CUT_LEVLE, temp);

        temp  = 0;
        if(enc_info->mbrc_thre > 8191)
        {
            enc_info->mbrc_thre = 8191;  //13 bit
        }
        if(enc_info->mb_bit_budget > 255)
        {
            enc_info->mb_bit_budget = 255;  //8 bit
        }
        temp |= enc_info->mbrc_thre;
        temp |= enc_info->mb_bit_budget<<16;
        DRV_WriteReg32(MP4_ENC_MBRC_INFO, temp);

        temp  = 0;
        temp |= enc_info->mbq_lb;   //5 bit
        temp |= enc_info->mbq_ub<<8;   //5 bit
        temp |= g_mpeg4_encode_cbr_para.mbq_min<<16;   //5 bit
        temp |= g_mpeg4_encode_cbr_para.mbq_max<<24;   //5 bit
        DRV_WriteReg32(MP4_ENC_MBRC_Q_LIMIT, temp);

        temp  = 0;
        temp |= g_mpeg4_encode_cbr_para.md_thre1; // MD_THRE1  //8 bit
        temp |= g_mpeg4_encode_cbr_para.md_thre6<<16; // MD_THRE6  //8 bit
        DRV_WriteReg32(MP4_ENC_MD_THREA, temp);

        temp  = 0;
        temp |= g_mpeg4_encode_cbr_para.md_thre2; // MD_THRE2  //16 bit
        temp |= g_mpeg4_encode_cbr_para.md_thre3<<16; // MD_THRE3  //16 bit
        DRV_WriteReg32(MP4_ENC_MD_THREB, temp);

        temp  = 0;
        temp |= g_mpeg4_encode_cbr_para.md_thre4; // MD_THRE4  //16 bit
        temp |= g_mpeg4_encode_cbr_para.md_thre10<<16; // MD_THRE5  //16 bit
        DRV_WriteReg32(MP4_ENC_MD_THREC, temp);

        temp  = 0;
        temp |= g_mpeg4_encode_cbr_para.md_thre7; // MD_THRE7  //8 bit
        temp |= g_mpeg4_encode_cbr_para.md_thre8<<8; // MD_THRE8   //16 bit
        DRV_WriteReg32(MP4_ENC_MD_THRED, temp);

        temp  = 0;
        temp |= g_mpeg4_encode_cbr_para.md_thre9; // MD_THRE9  //8 bit
        temp |= g_mpeg4_encode_cbr_para.md_thre10<<8; // MD_THRE10  //16 bit
        DRV_WriteReg32(MP4_ENC_MD_THREE, temp);

        temp  = 0;
        temp |= g_mpeg4_encode_cbr_para.md_thre11; // MD_THRE11  //8 bit
        temp |= g_mpeg4_encode_cbr_para.md_thre12<<8; // MD_THRE12  //16 bit
        DRV_WriteReg32(MP4_ENC_MD_THREF, temp);
    }
#endif

    frame_info->start_ptr = (kal_uint8 *)g_mpeg4_encore_info.current_bitstream_addr;
    frame_info->bits_type = enc_info->predition_type;
    frame_info->took_idx = 0;
    frame_info->pkt_num  = 0;
    frame_info->total_len = 0;
    frame_info->drop = KAL_FALSE;


    /********************************************************
    *  Trigger encoder to start encoding
    ********************************************************/
    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_START_ENC, video_get_current_time());
    if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
    {
        mpeg4_dec_reset();
        mpeg4_core_reset();
    }
	
    IRQUnmask(IRQ_MPEG4_ENC_CODE);
    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_ENC_START); // Video Object Plane Level start

#if ENC_BLOCKING
    {
        kal_uint32 u4Flags = 0;
        kal_retrieve_eg_events(g_mpeg4_encore_info.eEncodeComplete, MP4_HW_ENC_COMPLETE,
            KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);
    }
#endif

    return ret;
}


kal_bool mpeg4_encore_get_param(MPEG4_ENCORE_PARAM_TYPE type, void *p_value)
{
    kal_bool ret = KAL_TRUE;


    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_GET_PARAM, 1);

    return ret;
}


kal_bool mpeg4_encore_set_param(MPEG4_ENCORE_PARAM_TYPE type, void *p_value)
{
    kal_bool ret = KAL_TRUE;

    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_SET_PARAM, type);

    switch(type)
    {
    case MPEG4_ENCORE_PARAM_WIDTH:
        g_mpeg4_encore_info.enc_info.width = *(kal_uint32*)(p_value);
        break;

    case MPEG4_ENCORE_PARAM_HEIGHT:
        g_mpeg4_encore_info.enc_info.height = *(kal_uint32*)(p_value);
        break;

    case MPEG4_ENCORE_PARAM_BITRATE:
        g_mpeg4_encore_info.enc_info.bit_rate = *(kal_uint32*)(p_value);
        break;

    case MPEG4_ENCORE_PARAM_FRAME_RATE:
        g_mpeg4_encore_info.enc_info.frame_rate = *(kal_uint32*)(p_value);
        break;

    case MPEG4_ENCORE_SYNC_INTERVAL:
        g_mpeg4_encore_info.enc_info.i_interval = *(kal_uint32*)(p_value);
        break;

    case MPEG4_ENCORE_PARAM_MAX_PKG_SIZE:
        if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
        {
            g_mpeg4_encore_info.enc_info.max_pkt_size = *(kal_uint32*)(p_value);
        }
        else
        {
            g_mpeg4_encore_info.enc_info.max_pkt_size = 0;
        }
        break;

    case MPEG4_ENCORE_PARAM_SHORT_HEADER:
        g_mpeg4_encore_info.enc_info.short_header = *(kal_bool*)(p_value);
        break;

    case MPEG4_ENCORE_FORCE_ENCODE_I:
        g_mpeg4_encore_info.force_i_frame = *(kal_bool*)(p_value);
        break;

    case MPEG4_ENCORE_PARAM_SCENARIO:
        g_mpeg4_encore_info.scenario = *(MPEG4_ENCORE_SCENARIO*)(p_value);
        if (g_mpeg4_encore_info.scenario == MPEG4_ENCORE_SCENARIO_VT)
        {
            g_mpeg4_encore_info.enc_info.b_is_cbr = KAL_TRUE;
        }
        break;

    case MPEG4_ENCORE_TIME_INCREMENT:
        g_mpeg4_encore_info.enc_info.time_increment= *(kal_int32*)(p_value);
        break;

    default:
        break;
    }

    return ret;
}


void mpeg4_encore_close(void)
{
    //kal_uint32 savedMask;

    //savedMask = SaveAndSetIRQMask();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    MPEG4HWClose(VIDEO_MPEG4HW_ENC);
#endif
    //RestoreIRQMask(savedMask);
    MPEG4HWHwResourceFreeIfOccupy(VIDEO_MPEG4HW_ENC);
    video_dbg_trace(VIDEO_DBG_OWNER_ENCODER, VIDEO_DBG_HWENCV2_CLOSE, 1);
}


const MPEG4_ENC_DRIVER  mpeg4_encore_driver =
{
    mpeg4_encore_open,
    mpeg4_encore_init,
    mpeg4_encore_gen_vos,
    mpeg4_encore_encode,
    mpeg4_encore_get_param,
    mpeg4_encore_set_param,
    mpeg4_encore_close
};


MPEG4_ENC_DRIVER* GetMPEG4HWEncDriverHandle(void)
{

#ifdef MPEG4_ENCORE_PERFORMANCE_MEASURMENT
    if(!mpeg4_bm_para_init)
        mpeg4_measure_time_init();
    mpeg4_bm_para_init=KAL_TRUE;
#endif

    return (MPEG4_ENC_DRIVER*)&mpeg4_encore_driver;
}


#endif /* __VE_MPEG4_ENC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
