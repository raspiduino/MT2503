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
 *   video_vt_api_v2.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   This file defines mp4 functions for video call
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
 ****************************************************************************/
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#include "med_status.h"
#include "vcodec_v2_trc.h"
#include "video_vt_api_v2.h"
//#include "drv_features.h"
#include "kal_trace.h"
#include "video_codec_parser_utility_v2.h"

#include "kal_general_types.h"

#include "drv_comm.h"

#ifdef  __VE_VIDEO_VT_SUPPORT__

// TODO: 
// For Tokiya
//VIDEO_CALL_STATUS VideoCall_SetEncActiveCodec(VIDEO_CALL_CODEC_TYPE type){return VIDEO_CALL_STATUS_OK;}
//kal_uint8 VideoCall_ToggleDropFrame(kal_bool indication){return indication;}
//VIDEO_CALL_STATUS VideoCall_Enc_UpdateI(void){return VIDEO_CALL_STATUS_OK;}


/*
// 
// for the engineering mode functions, it is tmp solution, should be moved to a proper place
kal_int32 mpeg4_enc_cbr_para_read_cbr_func_para1 (void) {return -1; }
kal_int32 mpeg4_enc_cbr_para_read_cbr_func_para2 (void) {return -1; }
kal_int32 mpeg4_enc_cbr_para_read_cbr_func_para3 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_dct_cut_level1 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_dct_cut_level2 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_dct_cut_level3 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_dct_cut_level4 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre1 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre2 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre3 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre4 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre5 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre6 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre7 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre8 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre9 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre10 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre11 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_md_thre12 (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_mbrc_thre (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_mb_bit_budget (void){return -1;}
kal_int32 mpeg4_enc_cbr_para_read_mbq_lb (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_mbq_ub (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_mbq_min (void) {return -1;}
kal_int32 mpeg4_enc_cbr_para_read_mbq_max (void) {return -1;}

void mpeg4_enc_cbr_para_write_cbr_func_para1 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_cbr_func_para2 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_cbr_func_para3 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_dct_cut_level1 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_dct_cut_level2 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_dct_cut_level3 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_dct_cut_level4 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre1 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre2 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre3 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre4 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre5 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre6 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre7 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre8 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre9 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre10 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre11 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_md_thre12 (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_mbrc_thre (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_mb_bit_budget (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_mbq_lb (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_mbq_ub (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_mbq_min (kal_uint32 value) {;}
void mpeg4_enc_cbr_para_write_mbq_max (kal_uint32 value) {;}
// ~tmp solution, should be moved to a proper place
*/


//#define VIDEOCALL_ENC_MAX_PKT_SIZE    1024
#define VIDEOCALL_ENC_PKT_SIZE_LIMIT  512
#define VIDEOCALL_ENC_PKT_SIZE_RESERVED  256 // hardware may encode to macroblock boundary

#define VIDEOCALL_DEC_MAX_WIDTH        176
#define VIDEOCALL_DEC_MAX_HEIGHT       144 

#define VIDEOCALL_DEC_HW_TIMEOUT_DURATION 1000

typedef struct
{
    kal_uint8 dec_gpt_handle;		
    kal_bool b_start_gpt_check;
    kal_bool b_dec_parse_short_header;
    m4v_dec_im dec_parse_hdr;
    m4v_dec_im dec_parse_hdr_chk;
    kal_bool b_dec_parse_header_parsed;	

    kal_bool dec_open;
    kal_bool enc_open;
//    kal_bool dec_running;
    kal_bool enc_running;	
//    video_call_callback dec_callback;
//    video_call_callback enc_callback;
    kal_bool b_dec_short_header;
    kal_bool b_enc_short_header;

    m4v_dec_im dec_hdr;
    kal_bool b_dec_header_parsed;
    kal_uint8 *p_dec_working_buffer;
    kal_uint8 *p_dec_rec_buffer;
    kal_uint8 *p_dec_ref_buffer;
    kal_uint8 *p_dec_deblock_buffer;    
    kal_uint8 *p_dec_dacp_addr;
    kal_uint8 *p_dec_store_addr;
    kal_uint8 *p_dec_mvp_addr;	
    kal_uint8 *p_dec_qs_addr;

    kal_uint8 *enc_working_memory;	
    kal_uint8 *enc_frame_buffer_addr;
    kal_uint32 enc_time_stamp;	
    kal_uint32 enc_const_delay;      // const delay for time stamp(AV sync)	
    kal_uint8 *enc_input_yuv_data;
    kal_uint32 enc_total_frame;	
    m4v_enc_im enc_im;	
    kal_uint32 enc_bit_rate;
    kal_uint32 max_pkt_size;	
    kal_uint32 enc_bitstreams_ptr;
    kal_uint8 enc_vos_data[MAX_VOS_LENGTH];
    kal_uint32 enc_vos_size;
    kal_bool b_enc_yuv_source;	
    kal_bool b_enc_force_I_frame;
    kal_uint32 enc_trigger_limit;
    kal_uint32 enc_toal_save_bytes;
    kal_uint32 dec_decoded_mbno;
    kal_uint32 dec_total_mbno;
    kal_uint32 dec_dmacopy_mbno;
    kal_uint8  dec_dma_handle;
    
#if defined(ShorterIntraPeriod)    
    kal_uint8 enc_for_I_frame_period;
#endif    
//    VIDEO_CALL_QUALITY quality_mode;
}VIDEO_CALL_MP4_INFO;


static VIDEO_CALL_MP4_INFO g_videocall_mp4_info;

void mpeg4_videocall_dec_parse_open(void)
{
    drv_trace0(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_OPEN_START);

    g_videocall_mp4_info.b_dec_parse_header_parsed = KAL_FALSE;		
    g_videocall_mp4_info.b_dec_parse_short_header = KAL_FALSE;
    g_videocall_mp4_info.dec_parse_hdr.short_video_header = 0;

    drv_trace0(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_OPEN_END);
}

void h263_videocall_dec_parse_open(void)
{
    drv_trace0(TRACE_GROUP_10, H263_TRC_VIDEOCALL_DEC_PARSE_OPEN_START);

    g_videocall_mp4_info.b_dec_parse_header_parsed = KAL_TRUE;		
    g_videocall_mp4_info.b_dec_parse_short_header = KAL_TRUE;
    g_videocall_mp4_info.dec_parse_hdr.short_video_header = 1;

    drv_trace0(TRACE_GROUP_10, H263_TRC_VIDEOCALL_DEC_PARSE_OPEN_ENDT);
}

kal_bool mpeg4_videocall_dec_parse_packet(kal_uint8 *p_data, kal_uint32 length, Video_Call_Parse_Info *p_info)
{
    kal_int32 bitcnt = 0;
    kal_uint32 byte_offset;	
    kal_uint32 index;	
    kal_uint32 parse_byte;
    MEDIA_STATUS_CODE result;	

    drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_START, g_videocall_mp4_info.b_dec_parse_header_parsed);	 

    if(g_videocall_mp4_info.b_dec_parse_header_parsed == KAL_FALSE)
    {
        // check if it is short header pkt first
        if (video_plane_with_short_header(&g_videocall_mp4_info.dec_parse_hdr, p_data, &bitcnt) == KAL_TRUE)
        {
            //video_dbg_trace(VIDEOCALL_DEC_PARSE_SHV, *p_data);
            drv_trace0(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_SHORT_HDR);	
            g_videocall_mp4_info.b_dec_parse_header_parsed = KAL_TRUE;
            g_videocall_mp4_info.b_dec_parse_short_header = KAL_TRUE;
            g_videocall_mp4_info.dec_parse_hdr.short_video_header = 1;
        }
    }

    bitcnt = 0;
    if(g_videocall_mp4_info.b_dec_parse_header_parsed == KAL_FALSE)
    {
        bitcnt = mpeg4_read_header_imformation(&g_videocall_mp4_info.dec_parse_hdr, p_data, bitcnt, length * 8);
        if (bitcnt < 0)
        {
            //video_dbg_trace(VIDEOCALL_DEC_PARSE_Loc1, *p_data);
            drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_NO_VOS_HDR_ERR, bitcnt);
            //VIDEO_ASSERT(0);  
            return KAL_FALSE;	
        }
        else
        {
            g_videocall_mp4_info.b_dec_parse_header_parsed = KAL_TRUE;
            g_videocall_mp4_info.b_dec_parse_short_header = KAL_FALSE;
            g_videocall_mp4_info.dec_parse_hdr.short_video_header = 0;
            //video_dbg_trace(VIDEOCALL_DEC_PARSE_Loc3, *p_data);
            drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_VOS_HDR, bitcnt);
        }
        p_info->b_new_session = KAL_TRUE;
        #if 0 // temp solution annu 20100223
/* under construction !*/
        #else
        p_info->b_new_frame = KAL_FALSE;
        #endif
        p_info->real_width = g_videocall_mp4_info.dec_parse_hdr.width;
        p_info->real_height = g_videocall_mp4_info.dec_parse_hdr.height;
        p_info->width = (g_videocall_mp4_info.dec_parse_hdr.width + 0xf) & (~0xf); 
        p_info->height = (g_videocall_mp4_info.dec_parse_hdr.height + 0xf) & (~0xf); 
        p_info->prev_frame_duration = 0;
        #if 1 // temp solution annu 20100223
        p_info->b_sync_frame = KAL_FALSE;
        p_info->b_header_not_complete= KAL_FALSE;
        #endif
        //video_dbg_trace(VIDEOCALL_DEC_PARSE_RES, p_info->width*1000+p_info->height);
        drv_trace2(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_RES, p_info->width, p_info->height);
    }
    else
    {        
        if(g_videocall_mp4_info.dec_parse_hdr.short_video_header == KAL_FALSE)
        {
            bitcnt = mpeg4_read_header_imformation(&g_videocall_mp4_info.dec_parse_hdr_chk, p_data, bitcnt, length * 8);
            if(bitcnt == -1)
            {
                p_info->b_new_session = KAL_TRUE;
                return KAL_FALSE;
            }
            else if(bitcnt == -2)
            {
                p_info->b_new_session = KAL_FALSE;
            }
            else
            {
                p_info->b_new_session = KAL_TRUE;
            }
        }
        
        bitcnt = mpeg4_read_VOP_header(&g_videocall_mp4_info.dec_parse_hdr, p_data, bitcnt, &result);
        if(bitcnt <= 0)
        {
            //video_dbg_trace(VIDEOCALL_DEC_PARSE_Loc4, *p_data);
            //video_dbg_trace(VIDEOCALL_DEC_PARSE_LENGTH, length);
            /* not start of frame VOP */
            //p_info->b_new_session = KAL_FALSE;
            p_info->b_new_frame = KAL_FALSE;	 
            p_info->b_header_not_complete = KAL_FALSE; 
            drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_NO_VOP_HDR_ERR, bitcnt);
        }
        else
        {
            parse_byte = bitcnt/8;
            if((bitcnt&0x7)!=0)
                parse_byte++;
            if(parse_byte <= length)
            {    
                //video_dbg_trace(VIDEOCALL_DEC_PARSE_NEW_FRAME_LENGTH, length);
                /* start of frame VOP */
                //p_info->b_new_session = KAL_FALSE;
                p_info->b_new_frame = KAL_TRUE; 
                p_info->b_header_not_complete = KAL_FALSE;
                p_info->real_width = g_videocall_mp4_info.dec_parse_hdr.width;
                p_info->real_height = g_videocall_mp4_info.dec_parse_hdr.height;
                p_info->width = (g_videocall_mp4_info.dec_parse_hdr.width + 0xf) & (~0xf); 
                p_info->height = (g_videocall_mp4_info.dec_parse_hdr.height + 0xf) & (~0xf); 
                //video_dbg_trace(VIDEOCALL_DEC_PARSE_Loc5, length);
                if(g_videocall_mp4_info.dec_parse_hdr.vop_coding_type == 0)
                {
                    /* I frame */
                    p_info->b_sync_frame = KAL_TRUE;
                    drv_trace8(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_I, (*p_data), (*(p_data+1)), (*(p_data+2)), 
                                        (*(p_data+3)), (*(p_data+4)), (*(p_data+5)), (*(p_data+6)), (*(p_data+7)));
                    //video_dbg_trace(VIDEOCALL_DEC_PARSE_IFrame, *p_data);
                }
                else
                {
                    p_info->b_sync_frame = KAL_FALSE; 
                    drv_trace8(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_P, (*p_data), (*(p_data+1)), (*(p_data+2)), 
                                        (*(p_data+3)), (*(p_data+4)), (*(p_data+5)), (*(p_data+6)), (*(p_data+7)));
                    //video_dbg_trace(VIDEOCALL_DEC_PARSE_PFrame, *p_data);
                }
                //if(g_videocall_mp4_info.b_dec_parse_short_header == KAL_TRUE)
                if(g_videocall_mp4_info.dec_parse_hdr.short_video_header == 1)                
                {
               	    if(g_videocall_mp4_info.dec_parse_hdr.temporal_reference > g_videocall_mp4_info.dec_parse_hdr.old_temporal_reference)
                        p_info->prev_frame_duration = (g_videocall_mp4_info.dec_parse_hdr.temporal_reference - g_videocall_mp4_info.dec_parse_hdr.old_temporal_reference - 1)*1000/30;
                    else
                        p_info->prev_frame_duration = (256 - (g_videocall_mp4_info.dec_parse_hdr.old_temporal_reference + 1 - g_videocall_mp4_info.dec_parse_hdr.temporal_reference))*1000/30;
                }
                else
                {
                    if(g_videocall_mp4_info.dec_parse_hdr.b_fixed_vop_rate==KAL_FALSE)
                    {
                        if(g_videocall_mp4_info.dec_parse_hdr.time_increment > 0)
                        {
	                      p_info->prev_frame_duration = ((g_videocall_mp4_info.dec_parse_hdr.time_increment-1) *1000)
	                                 + ((g_videocall_mp4_info.dec_parse_hdr.time_increment_resolution - g_videocall_mp4_info.dec_parse_hdr.old_vop_time_increment)*1000/g_videocall_mp4_info.dec_parse_hdr.time_increment_resolution)					
	                                 + (g_videocall_mp4_info.dec_parse_hdr.vop_time_increment *1000/g_videocall_mp4_info.dec_parse_hdr.time_increment_resolution);					
                        }
                        else
                        {
                            p_info->prev_frame_duration = (g_videocall_mp4_info.dec_parse_hdr.vop_time_increment - g_videocall_mp4_info.dec_parse_hdr.old_vop_time_increment)*1000/g_videocall_mp4_info.dec_parse_hdr.time_increment_resolution;
                        }
                    }
                    else
                    {
                        p_info->prev_frame_duration = g_videocall_mp4_info.dec_parse_hdr.fixed_vop_time_increment*1000/g_videocall_mp4_info.dec_parse_hdr.time_increment_resolution;
                    }
                }
                //video_dbg_trace(VIDEOCALL_DEC_PARSE_DURATION, p_info->prev_frame_duration);	
                //video_dbg_trace(VIDEOCALL_DEC_PARSE_DURATION, g_videocall_mp4_info.dec_parse_hdr.time_increment);
                drv_trace0(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_VOP_HDR);
                //video_dbg_trace(VIDEOCALL_DEC_PARSE_RES2, p_info->width*1000+p_info->height);
                drv_trace2(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_RES2, p_info->width, p_info->height);
            }
            else
            {
                p_info->b_new_session = KAL_FALSE;
                p_info->b_new_frame = KAL_TRUE; 
                p_info->b_header_not_complete = KAL_TRUE;	
                //video_dbg_trace(VIDEOCALL_DEC_PARSE_NewSession, *p_data);
                drv_trace0(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_VOP_HDR_NOT_COMPLETE);
            }
        }
    }

    /* find macroblock_number */
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

    /* find whether another VOP in the video pkt or not */
    p_info->length = length;	
    byte_offset = bitcnt / 8;
    if(length > 3)
    {
	    if(g_videocall_mp4_info.b_dec_parse_short_header == KAL_FALSE)
	    {
	        for(index = byte_offset; index < (length - 3); index++)
	        {
	            if((p_data[index] == 0x00) && (p_data[index+1]==0x00) && (p_data[index+2]==0x01) && (p_data[index+3]==0xb6))
	            {
	                p_info->length = index;
	                //video_dbg_trace(VIDEOCALL_DEC_PARSE_FoundFrame, *p_data);
	                drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_ANOTHER_VOP, p_info->length);
	                break;
	            }
	        }
	    }
	    else
	    {
	        for(index = byte_offset; index < (length - 2); index++)
	        {
	            if((p_data[index] == 0x00) && (p_data[index+1]==0x00) && (p_data[index+2]==0x80 || p_data[index+2]==0x81 || p_data[index+2]==0x82 || p_data[index+2]==0x83))
	            {
	                p_info->length = index;
 
	                drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_ANOTHER_VOP, p_info->length);
	                break;
	            }
	        }
	    }
   }
    //video_dbg_trace(VIDEOCALL_DEC_PARSE_FINAL_LENGTH, p_info->length);

    drv_trace1(TRACE_GROUP_10, MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_END, p_info->length);

    return KAL_TRUE;
}

VIDEO_CALL_STATUS VideoCall_SetDecParseCodec(VIDEO_CALL_CODEC_TYPE type)
{
    VIDEO_CALL_STATUS eStatus = VIDEO_CALL_STATUS_CODEC_UNSUPPORT;

    //video_dbg_trace(VIDEOCALL_DEC_SET_PARSE_CODEC, video_get_current_time());
    //video_dbg_trace(VIDEOCALL_DEC_SET_PARSE_CODEC, (kal_uint32)type);
    drv_trace0(TRACE_GROUP_10, VIDEOCALL_DRV_TRC_SET_DEC_PARSE_CODEC);

    switch(type)
    {
    case VIDEO_CALL_CODEC_MPEG4:
        mpeg4_videocall_dec_parse_open();
        eStatus = VIDEO_CALL_STATUS_OK;
        break;
    case VIDEO_CALL_CODEC_H263:
        h263_videocall_dec_parse_open();
        eStatus = VIDEO_CALL_STATUS_OK;
        break;
    default:
        break;
    }
	 
    return eStatus;
}

VIDEO_CALL_STATUS VideoCall_ParsePacket(kal_uint8 *p_data, kal_uint32 length, Video_Call_Parse_Info *p_info)
{
    kal_bool result;
    //video_dbg_trace(VIDEOCALL_PARSE_PKT, video_get_current_time());
    drv_trace1(TRACE_GROUP_10, VIDEOCALL_DRV_TRC_PARSE_PKT, length);

    /*
    if(g_videocall_status.p_dec_parse_driver == NULL)
    {
        return VIDEO_CALL_STATUS_ERROR;
        //EXT_ASSERT(0, g_videocall_status.dec_status, g_videocall_status.enc_status, 0);
    }
    */

    if (length < 50) 
    {    
        kal_buffer_trace(TRACE_GROUP_10, VIDEOCALL_DRV_TRC_PARSE_PKT_CONTENT, length, p_data);                                                               
    }
	
    result = mpeg4_videocall_dec_parse_packet(p_data, length, p_info);
    if( result == KAL_TRUE)
    {
        if(p_info->length >0)
            return VIDEO_CALL_STATUS_OK;
        else
            return VIDEO_CALL_STATUS_ERROR;
    }
    else
        return VIDEO_CALL_STATUS_ERROR;
}


#endif  /* __VE_VIDEO_VT_SUPPORT__*/

#endif /*__VE_VIDEO_ARCHI_V2__*/
