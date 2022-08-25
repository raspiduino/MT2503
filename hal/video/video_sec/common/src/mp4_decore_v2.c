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
 *   mp4_decore_v2.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   This file defines the core of mpeg4 decode
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
#include "drv_comm.h"
#include "drv_features_video.h"

#ifdef __VE_VIDEO_ARCHI_V2__
#ifdef __VE_MPEG4_DEC_HW_SUPPORT__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "kal_public_defs.h"
#include "kal_release.h"

#include "mp4_hw.h"
#include "mp4_decore_v2.h"
#include "intrCtrl.h"
#include "visualhisr.h"
#include "video_dbg_v2.h"

#include "drv_gfx_dct_control.h"
#include "mm_power_ctrl.h"
#include "Video_comm_v2.h"

#include "dma_sw.h"
#include "mpeg4_hw_v2.h"

#define MAX_BITSTREAM_LENGTH  262112 //1024
#define MPEG4_HW_DRIVER_MEM_MAGIC 0x721012

#define MPEG4_HW_DEC_ERROR_CONCEALMENT
#define MPEG4_HW_DEC_MB_NUMBER_CHECK
#define H263_PLUSTYPE

typedef enum
{
    BUFFER_MP4_CODEC_COMD, // MP4+0000h
    BUFFER_MP4_VLC_DMA_COMD, // MP4+0004h
    BUFFER_MP4_DEC_CODEC_CONF, // MP4+0200h
    BUFFER_MP4_DEC_IRQ_MASK, // MP4+0204h
    BUFFER_MP4_DEC_REF_ADDR, // MP4+0224h
    BUFFER_MP4_DEC_REC_ADDR, // MP4+0228h
    BUFFER_MP4_DEC_STORE_ADDR, // MP4+0230h
    BUFFER_MP4_DEC_DACP_ADDR,  // MP4+0234h
    BUFFER_MP4_DEC_MVP_ADDR, // MP4+0238h
    BUFFER_MP4_DEC_VOP_STRUC0, // MP4+0240h
    BUFFER_MP4_DEC_VOP_STRUC1,// MP4+0244h
    BUFFER_MP4_DEC_VOP_STRUC2,// MP4+0248h
    BUFFER_MP4_DEC_MB_STRUC0, // MP4+024Ch
    BUFFER_MP4_DEC_VLC_ADDR, // MP4+0260h
    BUFFER_MP4_DEC_VLC_BIT, // MP4+0264h
    BUFFER_MP4_DEC_VLC_LIMIT, // MP4+0268h
    BUFFER_MP4_DEC_QS_ADDR, // MP4+027Ch
    BUFFER_MP4_REGISTER_COUNT
}MPEG4_HW_REG_BUF_INDEX_T;

typedef struct
{
    kal_uint32 u4address;
    kal_uint32 u4value;
}MPEG4_HW_REGISTER_T;

typedef struct
{
    kal_bool fgReady;
    kal_uint8 vop_coded;
    kal_uint8 *p_bitstream_buffer;
    kal_uint32 bistream_length;
    kal_uint8 *p_reconstruct_buffer;
    kal_uint8 *p_reference_buffer;
    kal_uint32 resume_vlc_limit;
    kal_uint32 resume_vlc_addr;
    kal_uint8 vop_coding_type;
    MPEG4_HW_REGISTER_T rRegister[BUFFER_MP4_REGISTER_COUNT];
}MPEG4_HW_REGISTER_SET_T;

#ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
typedef struct
{
    kal_uint32 u4TotalMBCnt;
    kal_uint32 u4DecodedMBCnt;
    kal_uint8  dec_dma_handle;
    kal_uint8 *pu1RecBuf;
    kal_uint8 *pu1RefBuf;
    kal_bool fgFinish;
    kal_uint32 left;
    kal_uint32 SrcStart;
    kal_uint32 DstStart;
    void (*callbackFinish)(void);
}MPEG4_HW_ERROR_CONCEALMENT;

MPEG4_HW_ERROR_CONCEALMENT rErrConcealment;
#endif


MPEG4_HW_REGISTER_SET_T rMP4RegSet;
mp4_dec_info  g_mp4_dec_info;

static void mpeg4_write_reg_buffer(kal_uint32 u4index, kal_uint32 u4Value)
{
    ASSERT(u4index < BUFFER_MP4_REGISTER_COUNT);
    rMP4RegSet.rRegister[u4index].u4value = u4Value;
}

static kal_uint32 mpeg4_read_reg_buffer(kal_uint32 u4index)
{
    ASSERT(u4index < BUFFER_MP4_REGISTER_COUNT);
    return rMP4RegSet.rRegister[u4index].u4value;
}

/* This function read the bits from <"data address"+bitcnt> to <"data address"+bitcnt+num>
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  num read bit number.
 * @return the value that it read.
 */
static kal_int32 mpeg4_util_show_bits(kal_uint8 * data, kal_int32 bitcnt, kal_int32 num)
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

/* This function set the bits from <"data address"+bitcnt> to <"data address"+bitcnt+num>
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  num read bit number.
 * @param  data to be set.
 */
    static void mpeg4_util_set_bits(kal_uint8 * data, kal_int32 bitcnt, kal_uint32 num, kal_uint32 value)
    {
        kal_int32 tmp;
        kal_uint8 tmp2, tmp3;

        //ASSERT(value < (2<<num));

        tmp = (bitcnt & 0x7) + num;

        if (tmp <= 8)
        {
            tmp2 = data[bitcnt >> 3] & ((1<<(8 - tmp))-1);
            tmp3 = data[bitcnt >> 3] & (0xFF& (~((1<<(8-(bitcnt & 0x7)))-1))) ;
            data[bitcnt >> 3] = tmp2 | tmp3 | (value<<(8 - tmp));
        }
        else
        {
            data[bitcnt >> 3] = data[bitcnt >> 3] & (~((1<<(8-(bitcnt & 0x7)))-1));
            data[bitcnt >> 3] += value&((1<<(8-(bitcnt & 0x7)))-1);
            value = (value-(value&((1<<(8-(bitcnt & 0x7)))-1))) >> (8-(bitcnt & 0x7));

            tmp -= 8;
            bitcnt += (8 - (bitcnt & 0x7));

            while (tmp > 8)
            {
                data[bitcnt >> 3] = value&0xFF;

                tmp -= 8;
                bitcnt += 8;
                value >>= 8;
            }

            // ³Ñ¤Uªº tmp <= 8
            data[bitcnt >> 3] &= ((1<<(8-tmp))-1);
            data[bitcnt >> 3] |= value<<(8-tmp);

        }
        return;
    }


/* Increment bitcnt until end of user data
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  max size of the data (bitcnt)
 * @return  0 if success. -1 if not found end of user data.
 */
static kal_int32 mpeg4_util_user_data(kal_uint8 * data, kal_int32 * bitcnt, kal_uint32 max_parse_data_size)
{
    kal_int32 bit = 0;

    *bitcnt += 32;

    while (mpeg4_util_show_bits(data, *bitcnt + bit, 24) != 1)
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
static kal_int32 mpeg4_util_get_bits(kal_uint8 * data, kal_int32 *bitcnt, kal_int32 num)
{
    kal_uint32 ret;

    ret = mpeg4_util_show_bits(data,*bitcnt,num);
    (*bitcnt)+=num;

    return ret;
}


/* This function get a long word(4 bytes) from a specific address
 * @param  a input data address
 * @return a long word are casted by *a,*(a+1),*(a+2),*(a+3)
 */
static kal_int32 mpeg4_util_show_word(kal_uint8 * a)
{
    return ((a[0] << 24) + (a[1] << 16) + (a[2] << 8) + a[3]);
}


/* This function implement log2(arg)
 * @param  arg input data
 * @return log2(arg)
 */
static kal_int32 mpeg4_util_log2ceil(kal_int32 arg)
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

/* This function decode the VOS bitstream.
 * @param  hdr bistream header information structure
 * @param  data bistream start address
 * @param  bitcnt start bit count
 * @param  max_parse_data_size maximum parse data size
 * @return the bit count that it read.
 */
static kal_int32 mpeg4_read_header_imformation(m4v_dec_im_v2 * hdr, kal_uint8 * data, kal_int32 bitcnt, kal_uint32 max_parse_data_size)
{
    kal_int32 version, temp;

    hdr->short_video_header = 0;

    /* VisualObjectSequence()*/
    if (mpeg4_util_show_word(data + (bitcnt >> 3)) == VOS_START_CODE)
    {
        bitcnt += 32;

        hdr->version = mpeg4_util_get_bits(data, &bitcnt, 8);
        while (mpeg4_util_show_word(data + (bitcnt >> 3)) == USR_START_CODE)
        {
            if (mpeg4_util_user_data(data, &bitcnt, max_parse_data_size))
                return -1;
        }
    }
    else
    {
        hdr->version = 0;
    }

    // special file. garbage between VOS start code and VO start code
    temp = mpeg4_util_show_word(data + (bitcnt >> 3));
    while ((temp&0xFFFFFF00) != 0x00000100)
    {
        bitcnt += 8;
        temp = mpeg4_util_show_word(data + (bitcnt >> 3));
        if(bitcnt >= max_parse_data_size)
        {
            // No Start code matched
            return -2;
        }
    }

    /* VisualObject() */
    if (mpeg4_util_show_word(data + (bitcnt >> 3)) == VSO_START_CODE)
    {
        bitcnt += 32;

        temp = mpeg4_util_get_bits(data, &bitcnt, 1);

        if (temp) // is_visual_object_identifier ==1
        {
            bitcnt += 7;
        }

        temp = mpeg4_util_get_bits(data, &bitcnt, 4);

        if (temp != 1)
            return -1; // format error!
        else
        {
            kal_bool video_signal_type = (kal_bool)mpeg4_util_get_bits(data, &bitcnt, 1);

            if (video_signal_type)
            {
                kal_uint8 temp;

                temp = mpeg4_util_get_bits(data, &bitcnt, 4); /*video_format,video_range*/
                temp = mpeg4_util_get_bits(data, &bitcnt, 1);
                if (temp)                         /*coulour_description*/
                {
                    mpeg4_util_get_bits(data, &bitcnt, 24);
                }
            }
        }

        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align
        while (mpeg4_util_show_word(data + (bitcnt >> 3)) == USR_START_CODE)
        {
            if (mpeg4_util_user_data(data, &bitcnt, max_parse_data_size))
                return -1;
        }
    }

    /* Vidio object start code */
    if (mpeg4_util_show_word(data + (bitcnt >> 3)) <= VO_START_CODE_MAX && mpeg4_util_show_word(data + (bitcnt >> 3)) >= VO_START_CODE_MIN)
    {
        bitcnt += 32;
    }

    // special file. garbage between VO start code and VOL start code
    temp = mpeg4_util_show_word(data + (bitcnt >> 3));
    while ((temp&0xFFFFFF00) != 0x00000100)
    {
        bitcnt += 8;
        temp = mpeg4_util_show_word(data + (bitcnt >> 3));
        if(bitcnt >= max_parse_data_size)
        {
            // No Start code matched
            return -2;
        }
    }

    /* VideoObjectLayer() */
    if (mpeg4_util_show_word(data + (bitcnt >> 3)) <= VOL_START_CODE_MAX && mpeg4_util_show_word(data + (bitcnt >> 3)) >= VOL_START_CODE_MIN)
    {
        bitcnt += 32 + 9/*random access + ID */;

        if (mpeg4_util_show_bits(data, bitcnt, 1))
        {
            bitcnt++;

            version = mpeg4_util_get_bits(data, &bitcnt, 4);
            bitcnt += 3;
        }
        else
        {
            bitcnt++;
            version = 1;
        }

        temp = mpeg4_util_get_bits(data, &bitcnt, 4); //aspect_ratio_info

        if (temp == 0x000f)
        {
            bitcnt += 16;
        }

        if (mpeg4_util_show_bits(data, bitcnt++, 1) == 1)
        {
            bitcnt += 3;
            bitcnt += (mpeg4_util_show_bits(data, bitcnt, 1)) ? 80 : 1;
        }

        temp = mpeg4_util_get_bits(data, &bitcnt, 2); //vol_shape

        if (temp != 0)
            return -1;

        bitcnt++/*marker*/;

        hdr->time_increment_resolution = mpeg4_util_get_bits(data, &bitcnt, 16);
        hdr->time_increment_length = mpeg4_util_log2ceil(hdr->time_increment_resolution);
        bitcnt += 1/*marker*/;

        hdr->b_fixed_vop_rate = (kal_bool)mpeg4_util_get_bits(data, &bitcnt, 1); /*fixed_vop_rate*/

        if (hdr->b_fixed_vop_rate)
        {
            hdr->fixed_vop_time_increment = mpeg4_util_get_bits(data, &bitcnt, hdr->time_increment_length);
        }

        bitcnt++; //marker;
        hdr->real_width = mpeg4_util_get_bits(data, &bitcnt, 13);
        bitcnt++; //marker;
        hdr->real_height = mpeg4_util_get_bits(data, &bitcnt, 13);
        bitcnt++; //marker;

        hdr->width = (hdr->real_width + 0xf) & (~0xf);
        hdr->height = (hdr->real_height + 0xf) & (~0xf);

        hdr->interlaced = mpeg4_util_get_bits(data, &bitcnt, 1);             /* interlaced */
        bitcnt++;                                                /*obmc_disable*/

        temp = mpeg4_util_get_bits(data, &bitcnt, ((version != 1) ? 2 : 1)); //sprite_enable

        if (temp != 0)
            return -1;

        temp = mpeg4_util_get_bits(data, &bitcnt, 1); //not_8_bit

        if (temp != 0)
            return -1;

        hdr->quant_type = mpeg4_util_get_bits(data, &bitcnt, 1);

        if (hdr->quant_type != 0)
            return -1;

        if (version != 1)
            bitcnt++;                     /* quarter_pixel*/

        temp = mpeg4_util_get_bits(data, &bitcnt, 1); //complexity disable

        if (temp != 1)
            return -1;

        hdr->resync_marker_disable = mpeg4_util_get_bits(data, &bitcnt, 1);
        hdr->data_partitioned = mpeg4_util_get_bits(data, &bitcnt, 1);

        if (hdr->data_partitioned)
        {
            hdr->resversible_vlc = mpeg4_util_get_bits(data, &bitcnt, 1);
        }
        else
            hdr->resversible_vlc = 0;

        hdr->time_base = 0;
        hdr->old_time_base = 0;
        hdr->old_vop_time_increment = 0;

        if (version == 0)
            bitcnt += 2; /*reduced_resolution_vop_enable, newpred_enable*/
        bitcnt++;        // scaleible
    }
    else                 /*if(mpeg4_util_show_bits(data,bitcnt,24) == 0x80)*/
    {
        /* no VideoObjectLayer() */
        return -2;
    }

    /*Jensen add, 2005/10/21*/
    bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

    /* For special file */
    if ((mpeg4_util_show_bits(data, bitcnt, 24) != 0x1) && ((mpeg4_util_show_bits(data, bitcnt, 32) & 0x00ffffff) == 0x01))
    {
        bitcnt += 1;
        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align
    }

    /* user_data() */
    while (mpeg4_util_show_bits(data, bitcnt, 32) == USR_START_CODE)
    {
        if (mpeg4_util_user_data(data, &bitcnt, max_parse_data_size))
        {
            // do not check it since it dose not affect really decode procedure
            // some files may fail at this check
            //return -1;
        }
    }

    if (mpeg4_util_show_word(data + (bitcnt >> 3)) == VOS_END_CODE)
    {
        bitcnt += 32;
    }

    return bitcnt;
}

/* This function decode the video_plane_with_short_header().
 * @param  hdr bistream header information structure
 * @param  data   bitstream start address
 * @param  bitcnt_init  start bit count
 * @param  max_parse_data_size max parse size.
 * @return the total bit count that this function has parsed.
 */
static kal_int32 mpeg4_read_VOP_short_header(m4v_dec_im_v2 * hdr, kal_uint8 * data, kal_int32 bitcnt_init, kal_int32 max_parse_data_size)
{
    kal_int32 bitcnt = bitcnt_init;
    kal_uint32 source_format = 0;
    kal_uint32 tmp;
#ifdef MPEG4_HW_DEC_MB_NUMBER_CHECK
    kal_uint32 u4NumbGobInVop;
    kal_int32 bitcnt_resync_marker;
#endif
#ifdef H263_PLUSTYPE
    kal_uint16 customWidth = 0;
    kal_uint16 customHeight = 0;
#endif

     /* video_plane_with_short_header() */
    if (mpeg4_util_show_bits(data, bitcnt, 22) != (kal_int32)SHV_START_CODE)
    {
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
            VIDEO_DBG_DECODER_MPEG4HWADPT_SHR_HDR_ERR, __LINE__);
        return -1;
    }

    hdr->old_temporal_reference = hdr->temporal_reference;
    //bitcnt += 22 + 8/*temporal_reference*/ + 1/*marker bit*/ + 1 /*zero_bit*/
    //              + 1/*split_screen_indicator*/ + 1/*document_camera_indicator*/ + 1/*full_picture_freeze_release*/;
    bitcnt += 22;
    hdr->temporal_reference = mpeg4_util_get_bits(data, &bitcnt, 8);
    bitcnt +=  1/*marker bit*/ + 1 /*zero_bit*/
                  + 1/*split_screen_indicator*/ + 1/*document_camera_indicator*/ + 1/*full_picture_freeze_release*/;

    source_format = mpeg4_util_get_bits(data, &bitcnt, 3);
    hdr->b_source_format = source_format;

#ifdef H263_PLUSTYPE
    if ((source_format == 0) || /* forbidden */
        (source_format == 6) )  /* reserved  */
    {
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
            VIDEO_DBG_DECODER_MPEG4HWADPT_SHR_HDR_ERR, __LINE__);
        return 0;
    }
    else if (source_format != 7)
    {
        if (mpeg4_util_show_bits(data, bitcnt, 1) == 0)
        {
            hdr->vop_coding_type = 0;
        }
        else
        {
            hdr->vop_coding_type = 1;
        }

        bitcnt++;

        bitcnt += 4; /*four_reserved_zero_bits*/
        hdr->vop_quant = mpeg4_util_get_bits(data, &bitcnt, 5);
        bitcnt++;
    }
    else   /* extented PTYPE */
    {
        kal_uint8 ufep;
        kal_uint32 par; // pixel aspect ratio
        kal_uint8 customPictureClockFrequency = 0;

        ufep = mpeg4_util_get_bits(data, &bitcnt, 3);
        if (ufep == 1)  /* read OPPTYPE 18bits */
        {
            source_format = mpeg4_util_get_bits(data, &bitcnt, 3);
            if ((source_format == 0) || /* forbidden */
                (source_format == 7) )  /* reserved  */
            {
                video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                    VIDEO_DBG_DECODER_MPEG4HWADPT_SHR_HDR_ERR, __LINE__);
                return 0;
            }

            /* custom PCF off(0)/on(1) */
            /* CPCFC is not supported but implementation exists */
            customPictureClockFrequency = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (customPictureClockFrequency)
            {
                return(0);
            }
            /* unrestricted motion vector off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* syntax-based arithmetic coding off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* advanced prediction  off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* advanced intra coding  off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* deblocking filter  off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* slice structured off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* reference picture selection off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* independent segment decoding off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* alternative inter vlc mode  off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* optional modified quantization mode  off(0)/on(1) */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp) return(0);
            /* marker */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if (tmp == 0) return(0);
            /* reserved, 3 zeros */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 3);
            if (tmp) return(0);
        }
        else if(ufep > 1)
        {
            return(0);
        }

        /* mpptype is decoded anyway regardless of value of ufep */
        /* picture coding type */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 3);
        if(tmp>1 || (!tmp && !ufep)) return(0);
        hdr->vop_coding_type = tmp;

        /* reference picture resampling off(0)/on(1) */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
        if (tmp) return(0);

        /* reduced-resolution update  off(0)/on(1) */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
        if (tmp) return(0);
        /* rounding type */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 1);

        /* reserved (zero) bits */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 2);
        if(tmp) return(0);

        /* marker */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
        if (tmp == 0) return(0);

        /* Plus header decoding continues after plustype */
        /* Picture header location of CPM */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
        if(tmp) return(0);

        if((ufep == 1) && (source_format == 6))
        {
            /* Custom Picture Format */

            /* Pixel aspect ratio */
            par = mpeg4_util_get_bits(data, &bitcnt, 4);
            if(par == 0xF)
            {
                // Extended PAR
                tmp = mpeg4_util_get_bits(data, &bitcnt, 16);
            }

            /* Picture width indication */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 9);
            if(tmp>511) return(0); /* [0,...,511] */
            customWidth = ((tmp+1)*4);
            /* marker */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
            if(tmp == 0) return(0);

            /* Picture height indication */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 9);
            if( (tmp==0) || (tmp>288) ) return(0); /* [1,...,288] */
            customHeight = (tmp*4);

            /* CFCFC is currently not supported
             * (although implementation exists) */
            if (customPictureClockFrequency)
            {
                /* clock conversion code */
                tmp = mpeg4_util_get_bits(data, &bitcnt, 1);

                /* clock divisor */
                tmp = mpeg4_util_get_bits(data, &bitcnt, 7);
                if (tmp == 0)
                    return (0);
            }
        }
        /* CPCFC is currently not supported because we could not test it */
        if (customPictureClockFrequency)
        {
            /* Extended temporal reference */
            tmp = mpeg4_util_get_bits(data, &bitcnt, 2);
        }

        /* QP */
        tmp = mpeg4_util_get_bits(data, &bitcnt, 5);
        if (tmp == 0) return(0);
     }

#endif
    if(hdr->b_source_format == 7)
    {
        if((source_format>=1) && (source_format<=5))
        {
            hdr->b_source_format = source_format;
        }
    }

    if (hdr->b_source_format == 1)
    {
        hdr->real_width = 128;
        hdr->real_height = 96;
    }
    else if (hdr->b_source_format < 6 && hdr->b_source_format > 1)
    {
        hdr->real_width = 176 << (source_format - 2);
        hdr->real_height = 144 << (source_format - 2);
    }
    else
    {
        ASSERT(hdr->b_source_format == 7);
        if((hdr->real_width==0) && (hdr->real_height==0))
        {
            //ASSERT(source_format == 6);
            if((source_format != 6))
            {
                return(0);

            }
            hdr->real_width = customWidth;
            hdr->real_height = customHeight;
        }
    }

    // Always 16 multiple
    hdr->width = hdr->real_width;
    hdr->height = hdr->real_height;

    do
    {
        tmp = mpeg4_util_get_bits(data, &bitcnt, 1);
        if (tmp == 1)
            bitcnt += 8;
    } while (tmp == 1);

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

#ifdef MPEG4_HW_DEC_MB_NUMBER_CHECK
    /* Parse MB number information */
    bitcnt_resync_marker = bitcnt;
    bitcnt_resync_marker += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

    if(hdr->b_source_format == 1)
    {
        u4NumbGobInVop = 6;
    }
    else if(hdr->b_source_format == 2)
    {
        u4NumbGobInVop = 9;
    }
    else if((hdr->b_source_format >= 3) && (hdr->b_source_format <= 5))
    {
        u4NumbGobInVop = 18;
    }
    else
    {
        ASSERT(hdr->b_source_format == 7);
        if((hdr->real_width==0) && (hdr->real_height==0))
        {
            ASSERT(source_format == 6);
        }
        // No number of GOBs in VOP information
        return bitcnt;
    }

    /* resync_marker */
    while(((kal_uint32)bitcnt_resync_marker)+22 < max_parse_data_size)
    {
        kal_uint32 u4temp;
        kal_uint32 gob_number = 0;

        u4temp = mpeg4_util_show_word(data + (bitcnt_resync_marker >> 3));

        if(((u4temp & 0xFFFF8000) == 0x8000) /* b'0000 0000 0000 0000 1 */ &&
            ((u4temp & 0x00007C00) != 0)) /* gob_number != 0 */
        {
            gob_number = (u4temp & 0x00007C00) >> 10;
        }

        if(gob_number >= u4NumbGobInVop)
        {
    #ifdef MPEG4HWDECDEBUG
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK, gob_number);
    #endif
            mpeg4_util_set_bits(data, bitcnt_resync_marker+17, 5, u4NumbGobInVop-1);
        }

        bitcnt_resync_marker += 8;
    }
#endif

    return bitcnt;
}

/* This function decode the VOP bitstream.
 * @param  hdr bistream header information structure
 * @param  data   VOP start address
 * @param  bitcnt_init  start bit count
 * @param  max_parse_data_size max parse size.
 * @return the total bit count that this function has parsed.
 */
static kal_int32 mpeg4_read_VOP_header(m4v_dec_im_v2 * hdr, kal_uint8 * data, kal_int32 bitcnt_init, kal_int32 max_parse_data_size)
{
    kal_int32 bitcnt = bitcnt_init;
    kal_int32 count;
    kal_uint32 u4NumOfMB, u4NumOfBits;
    #ifdef MPEG4_HW_DEC_MB_NUMBER_CHECK
    kal_int32 bitcnt_resync_marker;
    #endif

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
        VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK, (kal_uint32)data);
#endif

    if (hdr->short_video_header == 0)
    {
        /* try to parse VOL again */
        bitcnt = mpeg4_read_header_imformation(hdr, data, bitcnt_init, max_parse_data_size);

        if (bitcnt == -2)
        {
            bitcnt = 0;
        }

        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

        /* Group_of_VideoObjectPlane() */
        if (mpeg4_util_show_word(data + (bitcnt >> 3)) == 0x01B3)
        {
            bitcnt += 32;

            count = 0;
            while (mpeg4_util_show_word(data + (bitcnt >> 3)) != VOP_START_CODE && count < 50)
            {
                bitcnt += 8;
                count++;
            }
        }

        /* VideoObjectPlane() */
        if (mpeg4_util_show_word(data + (bitcnt >> 3)) != VOP_START_CODE)
        {
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                VIDEO_DBG_DECODER_MPEG4HWADPT_VOP_HDR_ERR, (kal_uint32)(data + (bitcnt >> 3)));
            return 0;
        }

        bitcnt += 32;
        hdr->short_video_header = 0;
        hdr->vop_coding_type = mpeg4_util_get_bits(data, &bitcnt, 2); /*0: I frame, 1: P frame*/
        hdr->old_time_base = hdr->time_base;
        hdr->old_vop_time_increment = hdr->vop_time_increment;

        hdr->time_increment = 0;
        while (mpeg4_util_show_bits(data, bitcnt, 1) != 0)
        {
            bitcnt++;
            hdr->time_base++;
            hdr->time_increment++;
        }

        bitcnt += 2; // time_mod + marker
        hdr->vop_time_increment = mpeg4_util_get_bits(data, &bitcnt, hdr->time_increment_length);
        bitcnt++;    // marker
        hdr->vop_coded = mpeg4_util_get_bits(data, &bitcnt, 1);

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
            return bitcnt;
        }

        if (hdr->vop_coding_type != 0)
        {
            hdr->rounding_code = mpeg4_util_get_bits(data, &bitcnt, 1);
        }
        else
            hdr->rounding_code = 0;

        hdr->intra_dc_vlc_thr = mpeg4_util_get_bits(data, &bitcnt, 3);

        hdr->use_intra_dc_vlc = hdr->intra_dc_vlc_thr == 0 ? 1 : (hdr->intra_dc_vlc_thr == 1 && hdr->vop_quant < 13) ? 1
                                                                     : (hdr->intra_dc_vlc_thr == 2 && hdr->vop_quant < 15)
                                                                           ? 1
                                                                           : (hdr->intra_dc_vlc_thr == 3 && hdr->vop_quant < 17)
                                                                                 ? 1
                                                                                 : (hdr->intra_dc_vlc_thr == 4 && hdr->vop_quant < 19)
                                                                                       ? 1
                                                                                       : (hdr->intra_dc_vlc_thr == 5 && hdr->vop_quant < 21)
                                                                                             ? 1 : (hdr->intra_dc_vlc_thr == 6 && hdr->vop_quant < 23) ? 1 : 0;

        hdr->vop_quant = mpeg4_util_get_bits(data, &bitcnt, 5);
        if (hdr->vop_coding_type != 0)
        {
            hdr->fcode = mpeg4_util_get_bits(data, &bitcnt, 3);
        }
        else
        {
            hdr->fcode = 0;
        }

        #ifdef MPEG4_HW_DEC_MB_NUMBER_CHECK
        if ((hdr->vop_coding_type == 1) || (hdr->vop_coding_type == 0))
        {
            /* Parse MB number information */
            bitcnt_resync_marker = bitcnt;
            bitcnt_resync_marker += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

            /* resync_marker */
            u4NumOfMB = (((hdr->width+15)/16) * ((hdr->height+15)/16));
            u4NumOfBits = mpeg4_util_log2ceil(((hdr->width+15)/16 * (hdr->height+15)/16) - 1);

            while((kal_uint32)bitcnt_resync_marker < max_parse_data_size)
            {
                kal_uint32 u4temp, resync_mark_patn;
                kal_uint32 mbnum = 0;
                kal_uint32 marker_length = 0;

                mbnum = 0;
                u4temp = mpeg4_util_show_word(data + (bitcnt_resync_marker >> 3));
                if (hdr->vop_coding_type == 1)  // P Frame
                {
                    marker_length = 15 + hdr->fcode;
                    resync_mark_patn = 0x1 << (31 - marker_length);
                    if( ((u4temp&((~resync_mark_patn) - (resync_mark_patn-1))) == 0 ) && ((u4temp&resync_mark_patn) != 0) )
                    {
                        mbnum = mpeg4_util_show_bits(data, bitcnt_resync_marker+marker_length+1, u4NumOfBits);
                    }
                }
                else if(hdr->vop_coding_type == 0) // I frame
                {
                    marker_length = 16;
                    if( ((u4temp&0xFFFF0000) == 0) && ((u4temp&0x8000) != 0) )
                    {
                        mbnum = mpeg4_util_show_bits(data, bitcnt_resync_marker+marker_length+1, u4NumOfBits);
                    }
                }

                if(bitcnt_resync_marker+marker_length+1+u4NumOfBits > max_parse_data_size)
                {
                    break; // To avoid overwrite memory
                }

                if(mbnum >= u4NumOfMB)
                {
                #ifdef MPEG4HWDECDEBUG
                    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                        VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK, bitcnt_resync_marker);
                    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                        VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK, marker_length);
                    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                        VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK, hdr->vop_coding_type);
                    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                        VIDEO_DBG_DECODER_MPEG4HWADPT_MBNUM_CHECK, u4temp);
                #endif
                    mpeg4_util_set_bits(data, bitcnt_resync_marker+marker_length+1, u4NumOfBits, u4NumOfMB-1);
                }

                bitcnt_resync_marker += 8;
            }
        }
        #endif

    }
    else
    {
        /* video_plane_with_short_header() */
        bitcnt = mpeg4_read_VOP_short_header(hdr, data, bitcnt_init, max_parse_data_size);
    }

    return bitcnt;
}

#if 0
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

 /* Mpeg4 decode reset function.
 * @param None
 * @return None
 */
void mpeg4_dec_reset(void)
{
    kal_uint32 savedMask;
    kal_uint8 index;
    kal_uint32 rec_addr;
    kal_uint32 ref_addr;
    kal_uint32 deblock_addr;

    rec_addr = DRV_Reg32(MP4_DEC_REC_ADDR);
    ref_addr = DRV_Reg32(MP4_DEC_REF_ADDR);
    deblock_addr = DRV_Reg32(MP4_DEC_DEBLOCK_ADDR);

    savedMask = SaveAndSetIRQMask();

    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_DEC_RST);

    for (index = 0; index < 20; index++)
        ;

    DRV_WriteReg32(MP4_CODEC_COMD, 0);

    RestoreIRQMask(savedMask);

    DRV_WriteReg32(MP4_DEC_REC_ADDR, rec_addr);
    DRV_WriteReg32(MP4_DEC_REF_ADDR, ref_addr);
    DRV_WriteReg32(MP4_DEC_DEBLOCK_ADDR, deblock_addr);

}

  /* Mpeg4 core reset function for V2 series.
  * @param None
  * @return None
  */
void mpeg4_core_reset(void)
 {
    kal_uint32 savedMask;
    kal_uint8 index;
    //kal_int32  dctRet;

    savedMask = SaveAndSetIRQMask();
    // To make sure that power is ON to core reset

    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_CORE_RST);

    for (index = 0; index < 20; index++)
        ;

    DRV_WriteReg32(MP4_CODEC_COMD, 0);

    RestoreIRQMask(savedMask);
}


/* This function write HW register Buffer Set.
 * @param None
 * @return None
 */
static void mpeg4_decode_write_register_buf_set(void)
{
    m4v_dec_im_v2* hdr = &g_mp4_dec_info.dec_hdr;
    kal_uint32 temp = 0;
    kal_uint32 mbwidth, mbheight, header_extension_bit;
    kal_uint32 temp_ptr, temp_int;
    kal_int32 bitcnt;
    kal_uint32 u4MaxLen;

    if (hdr->vop_coded == 1)
    {
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_DACP_ADDR,
            (kal_uint32)g_mp4_dec_info.p_dec_dacp_addr);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_STORE_ADDR,
            (kal_uint32)g_mp4_dec_info.p_dec_store_addr);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_MVP_ADDR,
            (kal_uint32)g_mp4_dec_info.p_dec_mvp_addr);

        temp = (MP4_DEC_CODEC_CONF_IRQ |
                MP4_DEC_CODEC_CONF_DCT |
                MP4_DEC_CODEC_CONF_VPGOB |
                MP4_DEC_CODEC_CONF_MC_BURST |
                MP4_DEC_CODEC_CONF_DQUAN);

        if(hdr->vop_coding_type == 1) // P frame
        {
            temp |= MP4_DEC_CODEC_CONF_DQFIX;
        }

        temp |= MP4_DEC_CODEC_CONF_HECFIX;

        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_CODEC_CONF, temp);

        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_IRQ_MASK, MP4_DEC_IRQ_MASK_BLOCK);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_REC_ADDR,
            (kal_uint32)g_mp4_dec_info.p_reconstruct_buffer);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_REF_ADDR,
            (kal_uint32)g_mp4_dec_info.p_prev_dec_ref_addr);

        temp = (hdr->vop_coding_type == 0) ? 1 : 0;
        temp = (temp << MP4_DEC_VOP_STRUC0_TYPE_BITCNT) | (hdr->data_partitioned << MP4_DEC_VOP_STRUC0_DATA_BITCNT)
               | (hdr->resversible_vlc << MP4_DEC_VOP_STRUC0_RVLC_BITCNT)
               | (hdr->short_video_header << MP4_DEC_VOP_STRUC0_SHORT_BITCNT)
               | (hdr->fcode << MP4_DEC_VOP_STRUC0_FCODE_BITCNT)
               | (hdr->rounding_code << MP4_DEC_VOP_STRUC0_ROUND_BITCNT)
               | (hdr->vop_quant << MP4_DEC_VOP_STRUC0_QUANT_BITCNT)
               | (hdr->intra_dc_vlc_thr << MP4_DEC_VOP_STRUC0_VLCTHR_BITCNT);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VOP_STRUC0, temp);

        mbwidth = hdr->width >> 4;
        mbheight = hdr->height >> 4;
        hdr->mblength = mpeg4_util_log2ceil(hdr->width * hdr->height >> 8);
        {    // bitcnt in header extension
            kal_uint16 bitcnt = 0;

            bitcnt++;                                                              // marker bit
            bitcnt += hdr->time_increment_length;                     // vop_time_increment (1-16 bits)
            bitcnt++;                                                             // marker bit
            bitcnt += 2;                                                         // vop_coding_type
            bitcnt += 3;                                                        // intra_dc_vlc_thr

            if (hdr->vop_coding_type != 0)
            {
                bitcnt += 3;
            } // vop_fcode_forward
            header_extension_bit = bitcnt;
        }

        temp = (mbwidth << MP4_DEC_VOP_STRUC1_XLIMIT_BITCNT) | (mbheight << MP4_DEC_VOP_STRUC1_YLIMIT_BITCNT)
               | (hdr->mblength << MP4_DEC_VOP_STRUC1_MBLENGTH_BITCNT)
               | (header_extension_bit << MP4_DEC_VOP_STRUC1_HEADERBIT_BITCNT);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VOP_STRUC1, temp);

        temp = ((mbwidth * mbheight) << MP4_DEC_VOP_STRUC2_MBCOUNT_BITCNT);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VOP_STRUC2 , temp);

        temp = (hdr->vop_quant << MP4_DEC_MB_STRUC0_QUANTIZER_BITCNT)
                | (hdr->use_intra_dc_vlc << MP4_DEC_MB_STRUC0_DCVLC_BITCNT);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_MB_STRUC0 , temp);

         /* VLC ADDR should be 4 byte align. Calculate related parameters */
        bitcnt = g_mp4_dec_info.bitcnt_offset;
        ASSERT(bitcnt >= 0);
        temp_ptr = (kal_uint32)g_mp4_dec_info.p_bitstream_buffer + (bitcnt >> 3);
        temp_int = bitcnt & 0x7;
        temp_int += (temp_ptr & 0x3) * 8;
        temp_ptr -= (temp_ptr & 0x3);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VLC_ADDR, temp_ptr);
        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VLC_BIT, temp_int);

        // ((size_in_byte+15)/16)*4 + 4
        temp = (((g_mp4_dec_info.bistream_length)+15)/16)*4+4;
        u4MaxLen = (((MAX_BITSTREAM_LENGTH+15)/16)*4+4)<<2;
        if(g_mp4_dec_info.bistream_length > u4MaxLen)
        {
            // This bitstream needs to be decoded twice
            mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VLC_LIMIT, u4MaxLen>>2);

            g_mp4_dec_info.resume_vlc_addr = temp_ptr+u4MaxLen;
            temp = (((g_mp4_dec_info.bistream_length-u4MaxLen)+15)/16)*4+4;
            g_mp4_dec_info.resume_vlc_limit = temp;
        }
        else
        {
            g_mp4_dec_info.resume_vlc_addr = 0;
            g_mp4_dec_info.resume_vlc_limit = 0;
            mpeg4_write_reg_buffer(BUFFER_MP4_DEC_VLC_LIMIT, temp);
        }

        #if 1
        // Quantization scale information
        ASSERT((g_mp4_dec_info.p_dec_qs_addr != NULL) &&
            (g_mp4_dec_info.p_dec_qs_addr != (kal_uint8 *)MPEG4_HW_DRIVER_MEM_MAGIC));
        temp = (kal_uint32)g_mp4_dec_info.p_dec_qs_addr;
        #else
/* under construction !*/
/* under construction !*/
        #endif

        mpeg4_write_reg_buffer(BUFFER_MP4_DEC_QS_ADDR, temp);

        /* start decode */
        mpeg4_write_reg_buffer(BUFFER_MP4_CODEC_COMD, MP4_CODEC_COMD_DEC_START);
    }
    else
    {
        // Nothing to do with non-coded frame
    }
}

/* This function write HW register.
 * @param None
 * @return None
 */
static void mpeg4_decode_write_register(void)
{
    m4v_dec_im_v2* hdr = &g_mp4_dec_info.dec_hdr;

    ASSERT(rMP4RegSet.fgReady == KAL_TRUE);

    // To preserve the information before next header parse
    rMP4RegSet.vop_coded = hdr->vop_coded;
    rMP4RegSet.p_bitstream_buffer = g_mp4_dec_info.p_bitstream_buffer;
    rMP4RegSet.bistream_length = g_mp4_dec_info.bistream_length;
    rMP4RegSet.p_reconstruct_buffer = g_mp4_dec_info.p_reconstruct_buffer;
    rMP4RegSet.p_reference_buffer = g_mp4_dec_info.p_prev_dec_ref_addr;
    rMP4RegSet.resume_vlc_addr= g_mp4_dec_info.resume_vlc_addr;
    rMP4RegSet.resume_vlc_limit= g_mp4_dec_info.resume_vlc_limit;
    rMP4RegSet.vop_coding_type = hdr->vop_coding_type;

    if (rMP4RegSet.vop_coded == 1)
    {
        if(KAL_FALSE == MPEG4HWHwResourceGet(VIDEO_MPEG4HW_DEC))
        {
            ASSERT(0); // resource controll should be handled at upper (VT) layer
        }

        mpeg4_dec_reset();

        //if (g_video_enc_status.running == KAL_FALSE)
        {
            mpeg4_core_reset();  /* Encoder is not running */
        }

#ifdef MPEG4HWDECDEBUG
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
            VIDEO_DBG_DECODER_MPEG4HWADPT_DECODE, mpeg4_read_reg_buffer(BUFFER_MP4_DEC_REC_ADDR));
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
            VIDEO_DBG_DECODER_MPEG4HWADPT_REFERENCE, mpeg4_read_reg_buffer(BUFFER_MP4_DEC_REF_ADDR));
#endif

        DRV_WriteReg32(MP4_DEC_DACP_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_DACP_ADDR));
        DRV_WriteReg32(MP4_DEC_STORE_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_STORE_ADDR));
        DRV_WriteReg32(MP4_DEC_MVP_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_MVP_ADDR));

        DRV_WriteReg32(MP4_DEC_CODEC_CONF,
                mpeg4_read_reg_buffer(BUFFER_MP4_DEC_CODEC_CONF));

        DRV_WriteReg32(MP4_DEC_IRQ_MASK,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_IRQ_MASK));
        DRV_WriteReg32(MP4_DEC_REC_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_REC_ADDR));
        DRV_WriteReg32(MP4_DEC_REF_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_REF_ADDR));

        DRV_WriteReg32(MP4_DEC_VOP_STRUC0,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_VOP_STRUC0));

        DRV_WriteReg32(MP4_DEC_VOP_STRUC1,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_VOP_STRUC1));

        DRV_WriteReg32(MP4_DEC_VOP_STRUC2,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_VOP_STRUC2));

        DRV_WriteReg32(MP4_DEC_MB_STRUC0,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_MB_STRUC0));

        DRV_WriteReg32(MP4_DEC_VLC_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_VLC_ADDR));
        DRV_WriteReg32(MP4_DEC_VLC_BIT,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_VLC_BIT));

        DRV_WriteReg32(MP4_DEC_VLC_LIMIT,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_VLC_LIMIT));

        DRV_WriteReg32(MP4_DEC_QS_ADDR,
            mpeg4_read_reg_buffer(BUFFER_MP4_DEC_QS_ADDR));

        IRQUnmask(IRQ_MPEG4_DEC_CODE);
        DRV_WriteReg32(MP4_CODEC_COMD,
            mpeg4_read_reg_buffer(BUFFER_MP4_CODEC_COMD));

        // Only I and P frames are decoded. And will be next frame's
        // reference, even decode error (concealment).
        g_mp4_dec_info.p_prev_dec_ref_addr = rMP4RegSet.p_reconstruct_buffer;
    }
    else
    {
        // non-coded frame, do nothing
        visual_active_hisr(VISUAL_MPEG4_SEEK_FIRST_HISR_ID);
    }
    //g_mp4_dec_info.p_prev_dec_ref_addr = g_mp4_dec_info.p_reconstruct_buffer;
    rMP4RegSet.fgReady = KAL_FALSE;
}

#ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
static void mpeg4_dec_err_conceal_prepare(void)
{
    kal_uint32 value, decoded;
    kal_uint16 xlimit, ylimit;

    value = DRV_Reg32(MP4_CORE_VOP_STRUC1);
    xlimit = value&0xFF;
    ylimit = (value&0xFF00)>>8;

    rErrConcealment.u4TotalMBCnt = xlimit * ylimit;

    value = DRV_Reg32(MP4_CORE_VOP_STRUC3);
    decoded = (((value&0x1F00)>>8))*xlimit;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    if (decoded >= rErrConcealment.u4TotalMBCnt)
    {
        decoded = 0;
    }
    rErrConcealment.u4DecodedMBCnt= decoded;

    rErrConcealment.pu1RecBuf= (kal_uint8*)DRV_Reg32(MP4_DEC_REC_ADDR);
    rErrConcealment.pu1RefBuf = (kal_uint8*)DRV_Reg32(MP4_DEC_REF_ADDR);
}

void mpeg4_hw_dec_dma_init()
{
#ifdef __VE_MTK_TARGET__
    if (!rErrConcealment.dec_dma_handle)
    {
        rErrConcealment.dec_dma_handle = DMA_FullSize_GetChannel(DMA_MPEG4);
        ASSERT(rErrConcealment.dec_dma_handle != 0xff);
    }
    rErrConcealment.callbackFinish = NULL;
#endif
}

void mpeg4_hw_dec_dma_deinit()
{
#ifdef __VE_MTK_TARGET__
    if (rErrConcealment.dec_dma_handle)
    {
        DMA_FullSize_FreeChannel(rErrConcealment.dec_dma_handle);
        rErrConcealment.dec_dma_handle = 0;
    }
#endif
}

/* Need to be DMA copy more than once */
static void mpeg4_hw_dec_dmacopy_Left_callback(void)
{
#ifdef __VE_MTK_TARGET__
    DMA_INPUT input;
    DMA_SWCOPYMENU menu;
    kal_uint32 length;

    ASSERT(rErrConcealment.left > 0);
    length = rErrConcealment.left;
    menu.srcaddr = rErrConcealment.SrcStart + (0xFFF0<<2);
    menu.dstaddr = rErrConcealment.DstStart + (0xFFF0<<2);
    input.type = DMA_SWCOPY;
    input.menu = &menu;
    input.callback = NULL;

    if (((menu.srcaddr & 0x7) != 0) ||((menu.dstaddr & 0x7) != 0) ||(length & 0x7 != 0))
    {
        /* Ref/Rec buffer and length should be 8 byte aligned */
        EXT_ASSERT(0, menu.srcaddr, menu.dstaddr, length);
    }
    else
    {
        input.size = DMA_LONG;
        if(length>>2 > 0xFFF0)
        {
            input.count = 0xFFF0;
            rErrConcealment.left = length - (0xFFF0<<2);
            rErrConcealment.SrcStart += (0xFFF0<<2);
            rErrConcealment.DstStart += (0xFFF0<<2);
            input.callback = mpeg4_hw_dec_dmacopy_Left_callback;
        }
        else
        {
            input.count = length>>2;
            input.callback = rErrConcealment.callbackFinish;
        }
    }
#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
        VIDEO_DBG_DECODER_MPEG4HWADPT_ECL_DMA_LEFT, rErrConcealment.left);
#endif

    DMA_FullSize_Config(rErrConcealment.dec_dma_handle,&input,KAL_TRUE);
#endif
}

void mpeg4_hw_dec_dmacopy_V_callback()
{
#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
        VIDEO_DBG_DECODER_MPEG4HWADPT_ERR_CCL, 4);
#endif

    rErrConcealment.fgFinish = KAL_TRUE;
    return;
}

void mpeg4_hw_dec_dmacopy_U_callback()
{
#ifdef __VE_MTK_TARGET__
    DMA_INPUT input;
    DMA_SWCOPYMENU menu;
    kal_uint32 length, yu_offset, mb_offset;

    length = (rErrConcealment.u4TotalMBCnt-rErrConcealment.u4DecodedMBCnt) * 64;
    yu_offset = rErrConcealment.u4TotalMBCnt * (256+64);
    mb_offset = rErrConcealment.u4DecodedMBCnt * 64;
    menu.srcaddr = (kal_uint32)(rErrConcealment.pu1RefBuf + yu_offset + mb_offset);
    menu.dstaddr = (kal_uint32)(rErrConcealment.pu1RecBuf + yu_offset + mb_offset);
    input.type = DMA_SWCOPY;
    input.menu = &menu;
    input.callback = mpeg4_hw_dec_dmacopy_V_callback;

    if (((menu.srcaddr & 0x7) != 0) ||((menu.dstaddr & 0x7) != 0) ||(length & 0x7 != 0))
    {
        /* Ref/Rec buffer and length should be 8 byte aligned */
        EXT_ASSERT(0, menu.srcaddr, menu.dstaddr, length);
    }
    else
    {
        input.size = DMA_LONG;
        if(length>>2 > 0xFFF0)
        {
            input.count = 0xFFF0;
            rErrConcealment.left = length- (0xFFF0<<2);
            rErrConcealment.callbackFinish = mpeg4_hw_dec_dmacopy_V_callback;
            input.callback = mpeg4_hw_dec_dmacopy_Left_callback;
        }
        else
        {
            input.count = length>>2;
            input.callback = mpeg4_hw_dec_dmacopy_V_callback;
        }
    }

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
        VIDEO_DBG_DECODER_MPEG4HWADPT_ERR_CCL, 3);
#endif

    DMA_FullSize_Config(rErrConcealment.dec_dma_handle,&input,KAL_TRUE);
#endif
}

void mpeg4_hw_dec_dmacopy_Y_callback()
{
#ifdef __VE_MTK_TARGET__
    DMA_INPUT input;
    DMA_SWCOPYMENU menu;
    kal_uint32 length, y_offset, mb_offset;

    length = (rErrConcealment.u4TotalMBCnt-rErrConcealment.u4DecodedMBCnt) * 64;
    y_offset = rErrConcealment.u4TotalMBCnt * 256;
    mb_offset = rErrConcealment.u4DecodedMBCnt * 64;
    menu.srcaddr = (kal_uint32)(rErrConcealment.pu1RefBuf + y_offset + mb_offset);
    menu.dstaddr = (kal_uint32)(rErrConcealment.pu1RecBuf + y_offset + mb_offset);
    input.type = DMA_SWCOPY;
    input.menu = &menu;
    input.callback = mpeg4_hw_dec_dmacopy_U_callback;

    if (((menu.srcaddr & 0x7) != 0) ||((menu.dstaddr & 0x7) != 0) ||(length & 0x7 != 0))
    {
        /* Ref/Rec buffer and length should be 8 byte aligned */
        EXT_ASSERT(0, menu.srcaddr, menu.dstaddr, length);
    }
    else
    {
        input.size = DMA_LONG;
        if(length>>2 > 0xFFF0)
        {
            input.count = 0xFFF0;
            rErrConcealment.left = length- (0xFFF0<<2);
            rErrConcealment.callbackFinish = mpeg4_hw_dec_dmacopy_U_callback;
            input.callback = mpeg4_hw_dec_dmacopy_Left_callback;
        }
        else
        {
            input.count = length>>2;
            input.callback = mpeg4_hw_dec_dmacopy_U_callback;
        }
    }
#ifdef MPEG4HWDECDEBUG
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
            VIDEO_DBG_DECODER_MPEG4HWADPT_ERR_CCL, 2);
#endif

    DMA_FullSize_Config(rErrConcealment.dec_dma_handle,&input,KAL_TRUE);
#endif
}

static void mpeg4_hw_dec_error_conceal(void)
{
#ifdef __VE_MTK_TARGET__
    DMA_INPUT input;
    DMA_SWCOPYMENU menu;
    kal_uint32 length, mb_offset;
    kal_uint32 index;

    length = (rErrConcealment.u4TotalMBCnt-rErrConcealment.u4DecodedMBCnt) * 256;
    if(length == 0)
    {
        return;
    }
    mb_offset = rErrConcealment.u4DecodedMBCnt * 256;
    menu.srcaddr = (kal_uint32)(rErrConcealment.pu1RefBuf + mb_offset);
    menu.dstaddr = (kal_uint32)(rErrConcealment.pu1RecBuf+ mb_offset);
    input.type = DMA_SWCOPY;
    input.menu = &menu;
    input.callback = mpeg4_hw_dec_dmacopy_Y_callback;

    rErrConcealment.SrcStart = menu.srcaddr;
    rErrConcealment.DstStart = menu.dstaddr;

    if (((menu.srcaddr & 0x7) != 0) ||((menu.dstaddr & 0x7) != 0) ||(length & 0x7 != 0))
    {
        /* Ref/Rec buffer and length should be 8 byte aligned */
        EXT_ASSERT(0, menu.srcaddr, menu.dstaddr, length);
    }
    else
    {
        input.size = DMA_LONG;
        if(length>>2 > 0xFFF0)
        {
            input.count = 0xFFF0;
            rErrConcealment.left = length- (0xFFF0<<2);
            rErrConcealment.callbackFinish = mpeg4_hw_dec_dmacopy_Y_callback;
            input.callback = mpeg4_hw_dec_dmacopy_Left_callback;
        }
        else
        {
            input.count = length>>2;
            input.callback = mpeg4_hw_dec_dmacopy_Y_callback;
        }
    }

    rErrConcealment.fgFinish = KAL_FALSE;
    DMA_FullSize_Config(rErrConcealment.dec_dma_handle, &input, KAL_TRUE);

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
        VIDEO_DBG_DECODER_MPEG4HWADPT_ERR_CCL, 1);
#endif

    for (index = 0; index < 50; index++)
    {
        if(rErrConcealment.fgFinish == KAL_FALSE)
        {
            kal_sleep_task(2);
        }
        else
        {
            break;
        }
    }

    if(index==50)
    {
      /* somthing wrong. */
      video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_ERR_CCL,
          5);
    }

#endif
}
#endif /* MPEG4_HW_DEC_ERROR_CONCEALMENT */

void mpeg4_dec_LISR(void)
{
    IRQMask(IRQ_MPEG4_DEC_CODE);

    visual_active_hisr(VISUAL_MPEG4_SEEK_FIRST_HISR_ID);
}

void mp4_dec_intr_dlr(void)
{
    kal_uint32 status;

    status = DRV_Reg32(MP4_DEC_IRQ_STS);
    // Decode success, decode fail

    #if 0
/* under construction !*/
    #else
    kal_cancel_timer(g_mp4_dec_info.rTimerID);
    #endif

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_INTERRUPT,
        rMP4RegSet.vop_coded);
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_INTERRUPT,
        status);
#endif

////mpeg4_dec_seek_lisr_process
    if(rMP4RegSet.vop_coded == 1)
    {
        //IRQMask(IRQ_MPEG4_DEC_CODE);
        DRV_WriteReg32(MP4_DEC_IRQ_ACK, status);

        if (status & MP4_DEC_IRQ_STS_DEC)
        {
            DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_STOP);
            g_mp4_dec_info.decode_result = MP4_DECODE_OK;
        }
        else if ((status & MP4_DEC_IRQ_STS_DMA))
        {
            // VLC DMA limit reached
            g_mp4_dec_info.decode_result = MP4_DECODE_FAILED_VLC_LIMIT;

#ifdef MPEG4HWDECDEBUG
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                VIDEO_DBG_DECODER_MPEG4HWADPT_VLC_LIMIT, rMP4RegSet.resume_vlc_addr);
            video_dbg_trace(VIDEO_DBG_OWNER_DECODER,
                VIDEO_DBG_DECODER_MPEG4HWADPT_VLC_LIMIT, rMP4RegSet.resume_vlc_limit);
#endif

            if(rMP4RegSet.resume_vlc_addr != 0)
            {
                DRV_WriteReg32(MP4_CORE_VLC_LIMIT, rMP4RegSet.resume_vlc_limit);
                DRV_WriteReg32(MP4_CORE_VLC_ADDR, rMP4RegSet.resume_vlc_addr);
                DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_RELOAD);

                rMP4RegSet.resume_vlc_limit = 0;
                rMP4RegSet.resume_vlc_addr = 0;

                // Wait for interrupt for resume
                IRQUnmask(IRQ_MPEG4_DEC_CODE);
                return;
            }
            else
            {
                #ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
                mpeg4_dec_err_conceal_prepare();
                #endif
                #if 0
/* under construction !*/
/* under construction !*/
                #endif

                g_mp4_dec_info.decode_err_cnt++;
                g_mp4_dec_info.decode_result = MP4_DECODE_FAILED_VLC_LIMIT;
            }
        }
        else
        {
            // error concealment >"<
            #ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
            mpeg4_dec_err_conceal_prepare();
            #endif

            #if 0
/* under construction !*/
/* under construction !*/
            #endif

            g_mp4_dec_info.decode_err_cnt++;
            g_mp4_dec_info.decode_result = MP4_DECODE_FAILED;
            //ASSERT(0);
        }

        //IRQUnmask(IRQ_MPEG4_DEC_CODE);
    }
    else
    {
        // Non-coded frame
        g_mp4_dec_info.decode_result = MP4_DECODE_OK_BYPASS;
    }
////

    kal_set_eg_events(g_mp4_dec_info.eDecodeComplete, MP4_HW_DEC_COMPLETE, KAL_OR);
}

static void mpeg4_hw_dec_timeout(void* p)
{
    #if 0
/* under construction !*/
/* under construction !*/
    #else
    ASSERT(g_mp4_dec_info.rTimerID != NULL);
    kal_cancel_timer(g_mp4_dec_info.rTimerID);
    #endif

#ifdef MPEG4HWDECDEBUG
    video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_TIMEOUT, 0);
#endif

#ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
    mpeg4_dec_err_conceal_prepare();
#endif

    mpeg4_dec_reset();
    mpeg4_core_reset();

    g_mp4_dec_info.decode_err_cnt++;
    g_mp4_dec_info.decode_result = MP4_DECODE_FAILED_TIMEOUT;
    kal_set_eg_events(g_mp4_dec_info.eDecodeComplete, MP4_HW_DEC_COMPLETE, KAL_OR);
}

kal_bool mp4_dec_init(void *param)
{
    kal_bool bRet = KAL_TRUE;
    mp4_dec_init_param *p_init_param = (mp4_dec_init_param*)param;
    kal_uint32 savedMask;
    //kal_int32  dctRet;

    g_mp4_dec_info.max_width = p_init_param->max_width;
    g_mp4_dec_info.max_height= p_init_param->max_height;
    #if 1
    g_mp4_dec_info.p_int_mem_addr = (kal_uint8 *)MPEG4_HW_DRIVER_MEM_MAGIC;
    g_mp4_dec_info.int_mem_size = 0;
    #else
/* under construction !*/
/* under construction !*/
    #endif

    g_mp4_dec_info.p_ext_mem_addr = (kal_uint8 *)MPEG4_HW_DRIVER_MEM_MAGIC; //p_init_param->ext_mem_addr;
    g_mp4_dec_info.ext_mem_size = 0; //p_init_param->ext_mem_size;

    #if 1
    g_mp4_dec_info.p_dec_working_buffer = (kal_uint8 *)MPEG4_HW_DRIVER_MEM_MAGIC;
    g_mp4_dec_info.p_dec_dacp_addr = (kal_uint8 *)MPEG4_HW_DRIVER_MEM_MAGIC;
    g_mp4_dec_info.p_dec_store_addr = (kal_uint8*)MPEG4_HW_DRIVER_MEM_MAGIC;
    g_mp4_dec_info.p_dec_mvp_addr = (kal_uint8*)MPEG4_HW_DRIVER_MEM_MAGIC;
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    g_mp4_dec_info.p_dec_qs_addr = (kal_uint8 *)MPEG4_HW_DRIVER_MEM_MAGIC;

    g_mp4_dec_info.p_prev_dec_ref_addr = NULL;
    g_mp4_dec_info.p_bitstream_buffer = NULL;
    g_mp4_dec_info.bistream_length = 0;
    g_mp4_dec_info.p_reconstruct_buffer = NULL;
    g_mp4_dec_info.bitcnt_offset = 0;

    g_mp4_dec_info.resume_vlc_addr = 0;
    g_mp4_dec_info.resume_vlc_limit = 0;

    g_mp4_dec_info.decode_err_cnt = 0;
    if(g_mp4_dec_info.eDecodeComplete== 0)
    {
        g_mp4_dec_info.eDecodeComplete = kal_create_event_group("MP4_HW_DEC_EVENT");
    }

    kal_mem_set(&(g_mp4_dec_info.dec_hdr), 0, sizeof(m4v_dec_im_v2));

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
    if (NULL == g_mp4_dec_info.rTimerID)
    {
        g_mp4_dec_info.rTimerID = kal_create_timer("MP4HWDEC_TIMER");
    }
    #endif

#if 1 /* Central control of geting DCT and clock gate */
    MPEG4HWOpen(VIDEO_MPEG4HW_DEC);
#else
#if defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
#else
    #if 1 // Preempt to use DCT
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    savedMask = SaveAndSetIRQMask();
    DRV_WriteReg32(MP4_SWITCH_GMC_PORT, 0);
    RestoreIRQMask(savedMask);

    /* Register LISR */
    IRQ_Register_LISR(IRQ_MPEG4_DEC_CODE, mpeg4_dec_LISR, "MPEG4Seek");
    IRQSensitivity(IRQ_MPEG4_DEC_CODE, LEVEL_SENSITIVE);
    //IRQUnmask(IRQ_MPEG4_DEC_CODE);
    /* Register HISR */
    VISUAL_Register_HISR(VISUAL_MPEG4_SEEK_FIRST_HISR_ID, mp4_dec_intr_dlr);

    // Register Buffer initialization
    rMP4RegSet.fgReady = KAL_FALSE;
    rMP4RegSet.resume_vlc_addr = 0;
    rMP4RegSet.resume_vlc_limit = 0;
    rMP4RegSet.rRegister[BUFFER_MP4_VLC_DMA_COMD].u4address= 0x4;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_CODEC_CONF].u4address= 0x200;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_IRQ_MASK].u4address= 0x204;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_REF_ADDR].u4address= 0x224;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_REC_ADDR].u4address= 0x228;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_STORE_ADDR].u4address= 0x230;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_DACP_ADDR].u4address= 0x234;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_MVP_ADDR].u4address= 0x238;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_VOP_STRUC0].u4address= 0x240;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_VOP_STRUC1].u4address= 0x244;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_VOP_STRUC2].u4address= 0x248;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_MB_STRUC0].u4address= 0x24C;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_VLC_ADDR].u4address= 0x260;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_VLC_BIT].u4address= 0x264;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_VLC_LIMIT].u4address= 0x268;
    rMP4RegSet.rRegister[BUFFER_MP4_DEC_QS_ADDR].u4address= 0x27C;

    #ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
    mpeg4_hw_dec_dma_init();
    #endif

    return bRet;
}

static void mp4_dec_close(void)
{
    #ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
    mpeg4_hw_dec_dma_deinit();
    #endif

#if 1 /* Central control of geting DCT and clock gate */
    MPEG4HWClose(VIDEO_MPEG4HW_DEC);
#else
#if defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
}

kal_uint32 mp4_dec_decode(void *in_param, void *out_param)
{
    mp4_dec_decode_input_param *p_decode_param = (mp4_dec_decode_input_param*)in_param;
    mp4_dec_decode_output_param *p_decode_result = (mp4_dec_decode_output_param*)out_param;
    kal_int32 bitcnt = 1; // To avoid header parse error judgement
    kal_uint8 *bitstream_p_addr;
    kal_uint8 *yuv_p_addr;
    kal_uint32 bitstream_length;
    kal_uint32 u4Flags = 0;
    kal_uint32 u4ParseStartTime, u4ParseTime;
    kal_bool fgWaitDecodeEvent = KAL_FALSE;
    kal_bool fgIsEOF = p_decode_param->fgIsEOF;

    #if 1 // pipeline stage 2: Write register buffer to H/W register
    if(rMP4RegSet.fgReady == KAL_TRUE)
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
        kal_set_timer(g_mp4_dec_info.rTimerID, mpeg4_hw_dec_timeout, NULL, 600, 0); // 20*4.615 ms
        #endif

        mpeg4_decode_write_register();
        fgWaitDecodeEvent = KAL_TRUE;
    }
    #endif

    if(fgIsEOF != KAL_TRUE)
    {
    #if 1 // pipeline stage 1: Parse Header and generate regster buffer
        u4ParseStartTime = video_get_current_time();

        bitstream_p_addr = p_decode_param->bitstream_addr;
        yuv_p_addr = p_decode_param->yuv_addr;
        bitstream_length = p_decode_param->bitstream_length;

        bitcnt = mpeg4_read_VOP_header(&g_mp4_dec_info.dec_hdr, bitstream_p_addr,
            0, bitstream_length<<3);

        if(bitcnt <= 0)
        {
            // Header parse error, return error after decode event is retrieved.
            // treat as non-coded frame
            bitcnt = 0;
            g_mp4_dec_info.dec_hdr.vop_coded = 0;
        }

#ifdef MPEG4_PATTERN_TEST
        g_mp4_dec_info.dec_hdr.vop_coded = 0;
#endif

        g_mp4_dec_info.p_bitstream_buffer = bitstream_p_addr;
        g_mp4_dec_info.bistream_length = bitstream_length;
        g_mp4_dec_info.p_reconstruct_buffer = yuv_p_addr;
        g_mp4_dec_info.bitcnt_offset = bitcnt;

        // 1st frame's reference buffer
        if(g_mp4_dec_info.p_prev_dec_ref_addr == NULL)
        {
            ASSERT(p_decode_param->ref_addr != NULL);
            g_mp4_dec_info.p_prev_dec_ref_addr = p_decode_param->ref_addr;
        }
        u4ParseTime = video_get_duration_ms(u4ParseStartTime);

        #ifdef MPEG4HWDECDEBUG
        video_dbg_trace(VIDEO_DBG_OWNER_DECODER, VIDEO_DBG_DECODER_MPEG4HWADPT_DEC,
            u4ParseTime);
        #endif

        mpeg4_decode_write_register_buf_set();
        rMP4RegSet.fgReady = KAL_TRUE;
        #endif
    }

    if(fgWaitDecodeEvent == KAL_TRUE)
    {
        kal_retrieve_eg_events(g_mp4_dec_info.eDecodeComplete, MP4_HW_DEC_COMPLETE,
            KAL_AND_CONSUME, &u4Flags, KAL_SUSPEND);

        p_decode_result->u4result = g_mp4_dec_info.decode_result;
        p_decode_result->bitstream_addr = rMP4RegSet.p_bitstream_buffer;
        p_decode_result->bitstream_length = rMP4RegSet.bistream_length;
        p_decode_result->disp_yuv_addr = rMP4RegSet.p_reconstruct_buffer;
        p_decode_result->u1_vop_coding_type = rMP4RegSet.vop_coding_type;
        if(rMP4RegSet.vop_coded)
        {
            p_decode_result->free_ref_yuv_addr = rMP4RegSet.p_reference_buffer;
        }
        else
        {
            p_decode_result->free_ref_yuv_addr = p_decode_result->disp_yuv_addr;
        }

        switch(g_mp4_dec_info.decode_result)
        {
            case MP4_DECODE_OK:
                break;
            case MP4_DECODE_FAILED:
            case MP4_DECODE_FAILED_VLC_LIMIT:
            case MP4_DECODE_FAILED_TIMEOUT:
            #ifdef MPEG4_HW_DEC_ERROR_CONCEALMENT
                mpeg4_hw_dec_error_conceal();
            #endif
                break;
            case MP4_DECODE_OK_BYPASS:
                // repeat last frame
                break;
        }

        if (rMP4RegSet.vop_coded == 1)
        {
            MPEG4HWHwResourceFree(VIDEO_MPEG4HW_DEC);
        }
        return g_mp4_dec_info.decode_result;
    }
    else
    {
        if(fgIsEOF != KAL_TRUE)
        {
            p_decode_result->u4result = MP4_DECODE_BYPASS_PIPELINE;
        }
        else
        {
            // EOF is received but no pipeline stage is triggered
            p_decode_result->u4result = MP4_DECODE_BYPASS_EOF;
        }
        return p_decode_result->u4result;
    }

}

/* This function decode the VOS or video_plane_with_short_header() .
 * @param  param include bitstream address and length
 * @return the parsed status.
 */
mp4_dec_parse_param mp4_dec_parse_VOS(void *param)
{
    kal_int32 bitcnt;
    mp4_dec_decode_input_param *p_decode_param = (mp4_dec_decode_input_param*)param;
    kal_uint8 *bitstream_v_addr;
    kal_uint32 bitstream_length;
    mp4_dec_parse_param t_result = {VIDEO_MP4_PARSE_UNKNOWN_ERR, 0};

    bitstream_v_addr = p_decode_param->bitstream_addr;
    bitstream_length = p_decode_param->bitstream_length;

    bitcnt = 0;
    bitcnt = mpeg4_read_header_imformation(&g_mp4_dec_info.dec_hdr,
        bitstream_v_addr, bitcnt, bitstream_length<<3);

    if (bitcnt > 0)
    {
        t_result.i4bitcnt = bitcnt;
        t_result.eStatus= VIDEO_MP4_PARSE_VOS_RDY; // VOS parsed ready

        bitcnt += (((bitcnt & 7) == 0) ? 0 : (8 - (bitcnt & 7))); //byte_align

        if ((bitcnt>>3) < bitstream_length)
        {
            /* Group_of_VideoObjectPlane() */
            if (mpeg4_util_show_word(bitstream_v_addr + (bitcnt >> 3)) == GOP_START_CODE)
            {
                bitcnt += 32;
                while (mpeg4_util_show_word(bitstream_v_addr + (bitcnt >> 3)) != VOP_START_CODE &&
                    (bitcnt < (bitstream_length<<3)))
                {
                    bitcnt += 8;
                }
            }

            // Check if Group_of_VideoObjectPlane of VOP is followed
            if (mpeg4_util_show_word(bitstream_v_addr + (bitcnt >> 3)) == VOP_START_CODE)
            {
                /* Group_of_VideoObjectPlane() || VideoObjectPlane() */
                t_result.eStatus= VIDEO_MP4_PARSE_VOS_RDY_WITH_VOP; // VOS with VOP
            }
        }
    }

    else if (bitcnt == -2)
    {
        bitcnt = 0;
        bitcnt = mpeg4_read_VOP_short_header(&g_mp4_dec_info.dec_hdr,
            bitstream_v_addr,bitcnt, bitstream_length<<3);

        if(bitcnt > 0)
        {
            t_result.i4bitcnt = bitcnt;
            t_result.eStatus= VIDEO_MP4_PARSE_SHR_HDR_RDY; // short header ready
            g_mp4_dec_info.dec_hdr.short_video_header = 1;

        }
        else
        {
            t_result.eStatus = VIDEO_MP4_PARSE_SHR_HDR_ERR; //short header error
        }
    }
    else if(bitcnt == -1)
    {
        t_result.eStatus = VIDEO_MP4_PARSE_VOS_ERR;// VOS error
    }
    else
    {
        t_result.eStatus =  VIDEO_MP4_PARSE_UNKNOWN_ERR;
    }

    return t_result;
}

kal_bool mp4_dec_get_param(MPEG4_DEC_PARAM_TYPE type, kal_uint32 *p_value)
{
    kal_bool   bRet = KAL_TRUE;

    if (type == VIDEO_MP4_DEC_PARAM_WIDTH)
    {
        *p_value = g_mp4_dec_info.dec_hdr.width;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_HEIGHT)
    {
        *p_value = g_mp4_dec_info.dec_hdr.height;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_REAL_WIDTH)
    {
        *p_value = g_mp4_dec_info.dec_hdr.real_width;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_REAL_HEIGHT)
    {
        *p_value = g_mp4_dec_info.dec_hdr.real_height;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_EXT_MEM_SIZE)
    {
        // Currently no external memory is required for working buffer
        *p_value = 0;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_INT_MEM_SIZE)
    {
        *p_value = MP4_DEC_MAX_WORK_MEMORY(g_mp4_dec_info.max_width,
            g_mp4_dec_info.max_height);
    }
    else if (type == VIDEO_MP4_DEC_PARAM_MAX_WIDTH)
    {
        *p_value = g_mp4_dec_info.max_width;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_MAX_HEIGHT)
    {
        *p_value = g_mp4_dec_info.max_height;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_MAX_SIZE)
    {
        *p_value = g_mp4_dec_info.max_width*g_mp4_dec_info.max_height;

    }
    else if (type == VIDEO_MP4_DEC_PARAM_PROFILE)
    {
        *p_value = MPEG4_SIMPLE;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_LEVEL)
    {
        *p_value = MPEG4_LEVEL3;
    }
    else
    {
        ASSERT(0);
        bRet = KAL_FALSE;
    }
    return bRet;
}

kal_bool mp4_dec_set_param(MPEG4_DEC_PARAM_TYPE type, void *p_param)
{
    kal_bool   bRet = KAL_TRUE;
    mp4_dec_init_param *p_set_param = (mp4_dec_init_param*)p_param;

    if (type == VIDEO_MP4_DEC_PARAM_EXT_MEM_ADDR)
    {
        g_mp4_dec_info.p_ext_mem_addr = p_set_param->ext_mem_addr;
        g_mp4_dec_info.ext_mem_size = p_set_param->ext_mem_size;
        g_mp4_dec_info.p_dec_qs_addr = g_mp4_dec_info.p_ext_mem_addr;
    }
    else if (type == VIDEO_MP4_DEC_PARAM_INT_MEM_ADDR)
    {
        g_mp4_dec_info.p_int_mem_addr = p_set_param->int_mem_addr;
        g_mp4_dec_info.int_mem_size = p_set_param->int_mem_size;
        g_mp4_dec_info.p_dec_working_buffer = g_mp4_dec_info.p_int_mem_addr;
        g_mp4_dec_info.p_dec_dacp_addr = g_mp4_dec_info.p_dec_working_buffer;
        g_mp4_dec_info.p_dec_store_addr = (kal_uint8*)((kal_uint32)g_mp4_dec_info.p_dec_dacp_addr+4096);
        g_mp4_dec_info.p_dec_mvp_addr = (kal_uint8*) ((kal_uint32)g_mp4_dec_info.p_dec_store_addr+
            (((g_mp4_dec_info.max_width*g_mp4_dec_info.max_height+255)/256)*32));
    }
    else
    {
        ASSERT(0);
        bRet = KAL_FALSE;
    }
    return bRet;
}

static void mp4_dec_flush(void)
{
    g_mp4_dec_info.p_prev_dec_ref_addr = NULL;
    rMP4RegSet.fgReady = KAL_FALSE;
    return;
}

static const MP4_DEC_DRIVER  mp4_dec_driver =
{
    mp4_dec_init,
    mp4_dec_decode,
    mp4_dec_parse_VOS,
    mp4_dec_get_param,
    mp4_dec_set_param,
    mp4_dec_flush,
    mp4_dec_close
};

MP4_DEC_DRIVER* GetMPEG4HwDecHandle(void)
{
    return (MP4_DEC_DRIVER*)&mp4_dec_driver;
}

#endif /* __VE_MPEG4_DEC_HW_SUPPORT__ */
#endif /* __VE_VIDEO_ARCHI_V2__ */
