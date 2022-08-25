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
 *   video_codec_parser_utility_v2.c
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *   This file defines the video codec parser utility function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_video.h"
#include "video_codec_parser_utility_v2.h"


/* This function read the bits from <"data address"+bitcnt> to <"data address"+bitcnt+num>
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  num read bit number.
 * @return the value that it read.
 */
kal_int32 mpeg4_codec_util_show_bits(kal_uint8 * data, kal_int32 bitcnt, kal_int32 num)
{
    kal_int32 tmp, out, tmp1;

    tmp = (bitcnt & 0x7) + num;

    if (tmp <= 8)
        out = (data[bitcnt >> 3] >> (8 - tmp)) & ((1 << num) - 1);
    else
    {
        out = data[bitcnt >> 3]&((1 << (8 - (bitcnt & 0x7))) - 1);

        tmp -= 8;
        bitcnt += (8 - (bitcnt & 0x7));

        while (tmp > 8)
        {
            out = (out << 8) + data[bitcnt >> 3];

            tmp -= 8;
            bitcnt += 8;
        }

        tmp1 = (data[bitcnt >> 3] >> (8 - tmp)) & ((1 << tmp) - 1);
        out = (out << tmp) + tmp1;
    }

    return out;
}


/* Increment bitcnt until end of user data
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  max size of the data (bitcnt)
 * @return  0 if success. -1 if not found end of user data.
 */
kal_int32 mpeg4_codec_util_user_data(kal_uint8 * data, kal_int32 * bitcnt, kal_uint32 max_parse_data_size)
{
    kal_int32 bit = 0;

    *bitcnt += 32;

    while (mpeg4_codec_util_show_bits(data, *bitcnt + bit, 24) != 1)
    {
        bit += 8;
        if (bit > max_parse_data_size)
        {
            break;
        }
    }

    *bitcnt += bit;

    return 0;
}

/* This function read the bits from <"data address"+bitcnt> to <"data address"+bitcnt+num>, and add bitcnt of num
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  num read bit number.
 * @return the value that it read.
 */
kal_int32 mpeg4_codec_util_get_bits(kal_uint8 * data, kal_int32 *bitcnt, kal_int32 num)
{
    kal_uint32 ret;

    ret = mpeg4_codec_util_show_bits(data,*bitcnt,num);
    (*bitcnt)+=num;

    return ret;
}


/* This function get a long word(4 bytes) from a specific address
 * @param  a input data address
 * @return a long word are casted by *a,*(a+1),*(a+2),*(a+3)
 */
kal_int32 mpeg4_codec_util_show_word(kal_uint8 * a)
{
    return ((a[0] << 24) + (a[1] << 16) + (a[2] << 8) + a[3]);
}


/* This function implement log2(arg)
 * @param  arg input data
 * @return log2(arg)
 */
kal_int32 mpeg4_codec_util_log2ceil(kal_int32 arg)
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

/* This function decode the VOP bitstream.
 * @param  hdr bistream header information structure
 * @param  data   VOP start address
 * @param  bitcnt_init  start bit count
 * @param  result Media status, which is based MEDIA_STATUS_CODE structure.
 * @return the total bit count that this function has parsed.
 */
kal_int32 mpeg4_read_VOP_header(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt_init, MEDIA_STATUS_CODE * result)
{
    kal_int32 bitcnt = bitcnt_init;

    kal_int32 count;
    hdr->H263 = 0;
    *result = MEDIA_STATUS_OK;

    if (hdr->short_video_header == 0)
    {
        /* try to parse VOL again */
        bitcnt = mpeg4_read_header_imformation(hdr, data, bitcnt_init, 0xffffffff);

        if (bitcnt == -2)
        {
            bitcnt = 0;
        }

        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

        /* Group_of_VideoObjectPlane() */
        if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) == 0x01B3)
        {
            bitcnt += 32;

            count = 0;
            while (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) != VOP_START_CODE && count < 50)
            {
                bitcnt += 8;
                count++;
            }
        }

        /* VideoObjectPlane() */
        if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) != VOP_START_CODE)
        {
            //VIDEO_ASSERT(0);

            //g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_BITSTREAM_ERROR;
            *result = VIDEO_ERROR;
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
            drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_VOP_HEADER, 13, bitcnt);
#endif
            return 0;
        }

        bitcnt += 32;
        hdr->H263 = hdr->short_video_header = 0;
        hdr->vop_coding_type = mpeg4_codec_util_get_bits(data, &bitcnt, 2); /*0: I frame, 1: P frame*/
        hdr->old_time_base = hdr->time_base;
        hdr->old_vop_time_increment = hdr->vop_time_increment;

        hdr->time_increment = 0;
        while (mpeg4_codec_util_show_bits(data, bitcnt, 1) != 0)
        {
            bitcnt++;
            hdr->time_base++;
            hdr->time_increment++;
        }

        bitcnt += 2; // time_mod + marker
        hdr->vop_time_increment = mpeg4_codec_util_get_bits(data, &bitcnt, hdr->time_increment_length);
        bitcnt++;    // marker
        hdr->vop_coded = mpeg4_codec_util_get_bits(data, &bitcnt, 1);

        if (hdr->vop_coding_type > 1)
        {
            hdr->vop_coded = KAL_FALSE; // Handle the non supported frames as non-coded frames
        }
        else
        {
            //hdr->vop_coded = KAL_TRUE; // Handle the I/P frame set as non-coded frames in bitstream
        }

        if (!hdr->vop_coded)
        {
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
            drv_trace1(TRACE_GROUP_10, MPEG4_TRC_READ_VOP_HEADER_NOT_CODED, bitcnt);
#endif
            return bitcnt;
        }

        if (hdr->vop_coding_type != 0)
        {
            hdr->rounding_code = mpeg4_codec_util_get_bits(data, &bitcnt, 1);
        }
        else
            hdr->rounding_code = 0;

        hdr->intra_dc_vlc_thr = mpeg4_codec_util_get_bits(data, &bitcnt, 3);

        hdr->use_intra_dc_vlc = hdr->intra_dc_vlc_thr == 0 ? 1 : (hdr->intra_dc_vlc_thr == 1 && hdr->vop_quant < 13) ? 1
                                                                     : (hdr->intra_dc_vlc_thr == 2 && hdr->vop_quant < 15)
                                                                           ? 1
                                                                           : (hdr->intra_dc_vlc_thr == 3 && hdr->vop_quant < 17)
                                                                                 ? 1
                                                                                 : (hdr->intra_dc_vlc_thr == 4 && hdr->vop_quant < 19)
                                                                                       ? 1
                                                                                       : (hdr->intra_dc_vlc_thr == 5 && hdr->vop_quant < 21)
                                                                                             ? 1 : (hdr->intra_dc_vlc_thr == 6 && hdr->vop_quant < 23) ? 1 : 0;

        hdr->vop_quant = mpeg4_codec_util_get_bits(data, &bitcnt, 5);
        if (hdr->vop_coding_type != 0)
        {
            hdr->fcode = mpeg4_codec_util_get_bits(data, &bitcnt, 3);
        }
        else
        {
            hdr->fcode = 0;
        }
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
        drv_trace1(TRACE_GROUP_10, MPEG4_TRC_READ_VOP_HEADER_VALID_VOP, bitcnt);
#endif
    }
    else
    {
         /* video_plane_with_short_header() */
        if(video_plane_with_short_header(hdr, data, &bitcnt) == KAL_FALSE)
        {
            *result = VIDEO_ERROR;
            return 0;
        }

        hdr->quant_type = 0;
        hdr->resync_marker_disable = 1;
        hdr->data_partitioned = 0;
        hdr->resversible_vlc = 0;
        hdr->rounding_code = 0;
        hdr->fcode = 1;
        hdr->vop_coded = 1;
        hdr->interlaced = 0;
        hdr->use_intra_dc_vlc = 0;
        hdr->intra_dc_vlc_thr = 0;
        hdr->time_base = 0;
        hdr->old_time_base = 0;
        hdr->vop_time_increment = 0;
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
        drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_VOP_HEADER_VALID_SHV_VOP, bitcnt, hdr->vop_coding_type);
#endif
    }

    return bitcnt;
}

kal_bool video_plane_with_short_header(m4v_dec_im * hdr, kal_uint8 * data, kal_int32* bitcnt_init)
{
    kal_int32 temp;
    kal_uint32 source_format;
    kal_int32 bitcnt = *bitcnt_init;

        if (mpeg4_codec_util_show_bits(data, bitcnt, 22) != (kal_int32)SHV_START_CODE)
        {
            //VIDEO_ASSERT(0);

            //g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_BITSTREAM_ERROR;
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
            drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_VOP_HEADER_NO_SHV_START_CODE, 13, bitcnt);
#endif
            return KAL_FALSE;
        }

        hdr->old_temporal_reference = hdr->temporal_reference;
        //bitcnt += 22 + 8/*temporal_reference*/ + 1/*marker bit*/ + 1 /*zero_bit*/
        //              + 1/*split_screen_indicator*/ + 1/*document_camera_indicator*/ + 1/*full_picture_freeze_release*/;
        bitcnt += 22;
        hdr->temporal_reference = mpeg4_codec_util_get_bits(data, &bitcnt, 8);
        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 1);/*marker bit*/
        if(temp != 1)
            return KAL_FALSE;
        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 1);/*zero_bit*/
        if(temp != 0)
            return KAL_FALSE;

        bitcnt +=  1/*split_screen_indicator*/ + 1/*document_camera_indicator*/ + 1/*full_picture_freeze_release*/;

        source_format = mpeg4_codec_util_get_bits(data, &bitcnt, 3);

        if (source_format == 1)
        {
            hdr->width = 128;
            hdr->height = 96;
        }
        else if (source_format < 6 && source_format > 1)
        {
            hdr->width = 176 << (source_format - 2);
            hdr->height = 144 << (source_format - 2);
        }
        else
        {
            return KAL_FALSE;
        }
        /*else
            assert(0);*/

        if (mpeg4_codec_util_show_bits(data, bitcnt, 1) == 0)
        {
            hdr->vop_coding_type = 0;
        }
        else
        {
            hdr->vop_coding_type = 1;
        }

        bitcnt++;

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 4);/*four_reserved_zero_bits*/
        if(temp != 0)
            return KAL_FALSE;

        hdr->vop_quant = mpeg4_codec_util_get_bits(data, &bitcnt, 5);
        bitcnt++;

        do
        {
            source_format = mpeg4_codec_util_get_bits(data, &bitcnt, 1);
            if (source_format == 1)
                bitcnt += 8;
        } while (source_format == 1);

        *bitcnt_init = bitcnt;
        return KAL_TRUE;
}

kal_int32 mpeg4_read_header_imformation(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt, kal_uint32 max_parse_data_size)
{
    kal_int32 version, temp;

    hdr->short_video_header = 0;

    /* VisualObjectSequence()*/
    if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) == VOS_START_CODE)
    {
        bitcnt += 32;

        hdr->version = mpeg4_codec_util_get_bits(data, &bitcnt, 8);
        while (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) == USR_START_CODE)
        {
            if (mpeg4_codec_util_user_data(data, &bitcnt, max_parse_data_size))
                return -1;
        }
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
        drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_HEADER_INFORMATION, 8, bitcnt);
#endif
    }
    else
    {
        hdr->version = 0;
    }

    /* VisualObject() */
    if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) == VSO_START_CODE)
    {
        bitcnt += 32;

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 1);

        if (temp) // is_visual_object_identifier ==1
        {
            bitcnt += 7;
        }

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 4);

        if (temp != 1)
            return -1; // format error!
        else
        {
            kal_bool video_signal_type = (kal_bool)mpeg4_codec_util_get_bits(data, &bitcnt, 1);

            if (video_signal_type)
            {
                kal_uint8 temp;

                temp = mpeg4_codec_util_get_bits(data, &bitcnt, 4); /*video_format,video_range*/
                temp = mpeg4_codec_util_get_bits(data, &bitcnt, 1);
                if (temp)                         /*coulour_description*/
                {
                    mpeg4_codec_util_get_bits(data, &bitcnt, 24);
                }
            }
        }

        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align
        while (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) == USR_START_CODE)
        {
            if (mpeg4_codec_util_user_data(data, &bitcnt, max_parse_data_size))
                return -1;
        }
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
        drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_HEADER_INFORMATION, 9, bitcnt);
#endif
    }

    //if (g_video_dec_status.scenario == VIDEO_SCENARIO_VCALL)
    {
        // check the already parsed length
        if (bitcnt >= max_parse_data_size)
            return -2;
    }

    /* Vidio object start code */
    if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) <= VO_START_CODE_MAX && mpeg4_codec_util_show_word(data + (bitcnt >> 3)) >= VO_START_CODE_MIN)
    {
        bitcnt += 32;
    }

    //if (g_video_dec_status.scenario == VIDEO_SCENARIO_VCALL)
    {
        // check the already parsed length
        if (bitcnt >= max_parse_data_size)
            return -2;
    }

    /* VideoObjectLayer() */
    if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) <= VOL_START_CODE_MAX && mpeg4_codec_util_show_word(data + (bitcnt >> 3)) >= VOL_START_CODE_MIN)
    {
        bitcnt += 32 + 9/*random access + ID */;

        if (mpeg4_codec_util_show_bits(data, bitcnt, 1))
        {
            bitcnt++;

            version = mpeg4_codec_util_get_bits(data, &bitcnt, 4);
            bitcnt += 3;
        }
        else
        {
            bitcnt++;
            version = 1;
        }

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 4); //aspect_ratio_info

        if (temp == 0x000f)
        {
            bitcnt += 16;
        }

        if (mpeg4_codec_util_show_bits(data, bitcnt++, 1) == 1)
        {
            bitcnt += 3;
            bitcnt += (mpeg4_codec_util_show_bits(data, bitcnt, 1)) ? 80 : 1;
        }

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 2); //vol_shape

        if (temp != 0)
            return -1;

        bitcnt++/*marker*/;

        hdr->time_increment_resolution = mpeg4_codec_util_get_bits(data, &bitcnt, 16);
        hdr->time_increment_length = mpeg4_codec_util_log2ceil(hdr->time_increment_resolution);
        bitcnt += 1/*marker*/;

        hdr->b_fixed_vop_rate = (kal_bool)mpeg4_codec_util_get_bits(data, &bitcnt, 1); /*fixed_vop_rate*/

        if (hdr->b_fixed_vop_rate)
        {
            hdr->fixed_vop_time_increment = mpeg4_codec_util_get_bits(data, &bitcnt, hdr->time_increment_length);
        }

        bitcnt++; //marker;
        hdr->width = mpeg4_codec_util_get_bits(data, &bitcnt, 13);
        bitcnt++; //marker;
        hdr->height = mpeg4_codec_util_get_bits(data, &bitcnt, 13);
        bitcnt++; //marker;

        hdr->interlaced = mpeg4_codec_util_get_bits(data, &bitcnt, 1);             /* interlaced */

        bitcnt++;                                                /*obmc_disable*/

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, ((version != 1) ? 2 : 1)); //sprite_enable

        if (temp != 0)
            return -1;

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 1); //not_8_bit

        if (temp != 0)
            return -1;

        hdr->quant_type = mpeg4_codec_util_get_bits(data, &bitcnt, 1);

        if (hdr->quant_type != 0)
            return -1;

        if (version != 1)
            bitcnt++;                     /* quarter_pixel*/

        temp = mpeg4_codec_util_get_bits(data, &bitcnt, 1); //complexity disable

        if (temp != 1)
            return -1;

        hdr->resync_marker_disable = mpeg4_codec_util_get_bits(data, &bitcnt, 1);
        hdr->data_partitioned = mpeg4_codec_util_get_bits(data, &bitcnt, 1);

        if (hdr->data_partitioned)
        {
            hdr->resversible_vlc = mpeg4_codec_util_get_bits(data, &bitcnt, 1);
        }
        else
            hdr->resversible_vlc = 0;

        hdr->time_base = 0;
        hdr->old_time_base = 0;
        hdr->old_vop_time_increment = 0;

        if (version == 0)
            bitcnt += 2; /*reduced_resolution_vop_enable, newpred_enable*/
        bitcnt++;        // scaleible
        //if (g_video_dec_status.scenario == VIDEO_SCENARIO_VCALL)
        {
            // check the already parsed length
            if (bitcnt > max_parse_data_size)
            return -2;
        }
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
        drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_HEADER_INFORMATION, 10, bitcnt);
#endif
    }
    else                 /*if(mpeg4_codec_util_show_bits(data,bitcnt,24) == 0x80)*/
    {
        /* no VideoObjectLayer() */
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
        drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_HEADER_INFORMATION, 11, bitcnt);
#endif
        return -2;
    }

    /*Jensen add, 2005/10/21*/
    bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

    /* For special file */
    if ((mpeg4_codec_util_show_bits(data, bitcnt, 24) != 0x1) && ((mpeg4_codec_util_show_bits(data, bitcnt, 32) & 0x00ffffff) == 0x01))
    {
        bitcnt += 1;
        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align
    }

    /* user_data() */
    if (mpeg4_codec_util_show_bits(data, bitcnt, 32) == USR_START_CODE)
    {
        if (mpeg4_codec_util_user_data(data, &bitcnt, max_parse_data_size))
        {
            // do not check it since it dose not affect really decode procedure
            // some files may fail at this check
            //return -1;
        }
    }

    if (mpeg4_codec_util_show_word(data + (bitcnt >> 3)) == VOS_END_CODE)
    {
        bitcnt += 32;
    }
#ifdef __VIDEO_CODEC_PARSER_DEBUG__
    drv_trace2(TRACE_GROUP_10, MPEG4_TRC_READ_HEADER_INFORMATION, 12, bitcnt);
#endif

    return bitcnt;
}

