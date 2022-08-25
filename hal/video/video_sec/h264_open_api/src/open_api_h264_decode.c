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
 *   open_api_h264_decode.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements H.264 basic decode function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#if defined (__VE_H264_HW_OPEN_API_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__)
#include "kal_release.h"
#if defined (__VE_VIDEO_ARCHI_V2__)
#include "video_comm_v2.h"
#else
#include "video_comm.h"
#endif
#include "h264_dec_hw.h"
#include "h264_open_api_video_if.h"
#include "open_api_h264_decode.h"
#include "open_api_h264_driver.h"
#include "open_api_h264_memory_management.h"
#include "vcodec_v2_trc.h"

#ifdef dbg_print
#undef dbg_print
#define dbg_print(...)
#else
#define dbg_print(...)
#endif

/*******************************************************************************
*   Local global variable
*******************************************************************************/
H264_dec_info *g_open_api_h264_dec_info_ptr = NULL;
H264_DEC_ISR_PARAM  g_open_api_h264_dec_isr_param;
H264_DPB_list  g_open_api_h264_DPB_list, g_h264_DPB_list_output;
H264_dpb_frame_info  g_open_api_h264_dpb_frame_info;
H264_DPB_entry g_curr_dpb;
H264_emulation_info g_open_api_h264_emu_info;
kal_int32 picCnt, emuSize, emuModifyPos;


/*******************************************************************************
*   Extern variable
*******************************************************************************/
//extern kal_uint32 H264_base;
extern kal_bool fgDisplayOrderMode;
extern kal_bool fgReferenceCorrupted;

/*******************************************************************************
*   Extern function
*******************************************************************************/
extern void open_api_h264_free_dpb(H264_DPB_entry* p_DPB);
extern MEDIA_STATUS_CODE _VideoH264HandleAccessUnitBoundary(H264_NAL_unit *prNALu);
extern void _VideoH264VUIParameters(kal_uint8 *pu1SODB, kal_uint32 *bitcnt, H264_sps_info *sps);
extern void _VideoH264RBSPTrailingBits(kal_uint8 *p_addr, kal_uint32 *p_bitcnt);
extern kal_uint32 video_get_current_time(void);
extern void output_all_DPB_entries(kal_uint32 check_prior);

/*******************************************************************************
*   Local static H.264 handle decode function
*******************************************************************************/
kal_bool open_api_h264_reference_frame_check(kal_uint8* slice_config_addr, kal_uint8** ref_frame_addr);
void open_api_h264_dec_set_isr_vlc_param(kal_bool b_check);
void open_api_h264_set_next_decode_dpb(H264_DPB_entry *p_dpb);

/*******************************************************************************
*   H264 Syntas parse functions
*******************************************************************************/

kal_int32 h264_util_log2ceil(kal_int32 arg)
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

void open_api_h264_uitl_set_start_addr(kal_uint8 *p_addr)
{
    g_open_api_h264_emu_info.start_addr = p_addr;
    g_open_api_h264_emu_info.index = 0;
    g_open_api_h264_emu_info.emu_index = 0;
}

static void h264_uitl_check_emulation_code(kal_uint8 *p_addr, kal_uint32 start_bitcnt, kal_uint32 len)
{
    kal_uint32 index;
    kal_uint8 *p_check_point;
    kal_uint32 check_bytes = 0;
    kal_uint32 check_size;
    
    if (p_addr != g_open_api_h264_emu_info.start_addr) 
    {
        // reset the check point
        open_api_h264_uitl_set_start_addr(p_addr);
    }

    if(((start_bitcnt/8) + len) > g_open_api_h264_emu_info.index)
    {
        // check next N bytes of emulation code
        // if emulation code match, keep it in g_open_api_h264_emu_info.emu_match[] array
        p_check_point = &g_open_api_h264_emu_info.start_addr[g_open_api_h264_emu_info.index];
        check_size = VIDEO_MAX(len, 16);
        for(index = 0; index < check_size; index++)
        {
            if((*p_check_point) == 0x00)
            {
                p_check_point++;
                check_bytes++;
                if((*p_check_point) == 0x00)
                {
                    p_check_point++;
                    check_bytes++;
                    if((*p_check_point) == 0x03)
                    {
                        g_open_api_h264_emu_info.emu_match[g_open_api_h264_emu_info.emu_index] = g_open_api_h264_emu_info.index + check_bytes;
                        g_open_api_h264_emu_info.emu_index++;
                        if(g_open_api_h264_emu_info.emu_index >= 128)
                        {
                        	 video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                            EXT_ASSERT(0, g_open_api_h264_emu_info.emu_index, g_open_api_h264_emu_info.index, (kal_uint32)g_open_api_h264_emu_info.start_addr);
                        }
                    }
                }
            }
            p_check_point++;
            check_bytes++;
        }
        g_open_api_h264_emu_info.index += check_bytes;
    }
}


static kal_bool h264_util_match_emulation_code(kal_uint32 byte_offset)
{
    kal_uint32 index;
    kal_bool b_match = KAL_FALSE;
    
    for(index = 0; index < g_open_api_h264_emu_info.emu_index; index++)
    {
        if(byte_offset == g_open_api_h264_emu_info.emu_match[index])
        {
            b_match = KAL_TRUE;
            break;
        }
    }

    return b_match;
}


kal_int64 h264_uitl_ue_long(kal_uint8 *p_addr, kal_uint32 *p_bitcnt)
{
    kal_uint32 curByte, curByte1;
    kal_uint32 byte_offset, byte_offset_new;	
    kal_uint32 pos, bit_offset;	
    kal_uint32 bit = 0;
    kal_uint32 leadingZeroBits = 0;
    kal_int64 codeNum=0;
    kal_uint32 index;
    kal_uint32 check_byte = 0, match_count = 0;

    // check leading zeros first
    byte_offset = (*p_bitcnt)/8;
    byte_offset_new = byte_offset;
    curByte = byte_offset;
    bit_offset = (*p_bitcnt)& 0x7;
    pos = bit_offset + leadingZeroBits;
    bit = p_addr[curByte]&(1<<(7-(pos&7)));
    while(bit==0)
    {
         leadingZeroBits++;
         pos++;
         if(pos>=8)
         {
             curByte++;
             pos-=8;
         }
         bit = p_addr[curByte]&(1<<(7-(pos&7)));
    }

    // check emulation codes first
    h264_uitl_check_emulation_code(p_addr, *p_bitcnt, ((leadingZeroBits*2)/8)+1);
    byte_offset = (*p_bitcnt+leadingZeroBits+1)/8;
    byte_offset_new = byte_offset;
    curByte = byte_offset;
    bit_offset = (*p_bitcnt)& 0x7;
    check_byte = 0;
    
    if(h264_util_match_emulation_code(curByte))
    {
        check_byte++;
        byte_offset++;
        curByte++;
        match_count++;

        leadingZeroBits = 0;
        curByte1 = (*p_bitcnt)/8;
        pos = bit_offset + leadingZeroBits;
        bit = p_addr[curByte1]&(1<<(7-(pos&7)));
        while(bit==0)
        {
        	leadingZeroBits++;
        	pos++;
        	if(pos>=8)
        	{
        		curByte1++;
        		pos-=8;
        	}
        	if(h264_util_match_emulation_code(curByte1))
        	{
        		curByte1++;
        		match_count++;
        		if (match_count > 2)
        		{
        			check_byte++;
        			byte_offset++;
        			curByte++;
        		}
        	}
        	bit = p_addr[curByte1]&(1<<(7-(pos&7)));
        }

    }

    for(index =0; index < leadingZeroBits; index++)
    {
        byte_offset_new = ((*p_bitcnt+leadingZeroBits+1)+index+(check_byte*8))/8;       
        while (byte_offset < byte_offset_new)
        {
            byte_offset++;
            curByte++;
            if(h264_util_match_emulation_code(curByte))
            {
                byte_offset++;
                curByte++;
            } 
        }
        
        pos = bit_offset + (leadingZeroBits+1) + index;
        bit = p_addr[curByte]&(1<<(7-(pos&7)));
        codeNum += (bit == 0)? 0 : (kal_int64)((kal_uint64)1 << (kal_uint64)(leadingZeroBits - index - 1));
    }
    codeNum += (kal_int64)(((kal_uint64)1 << (kal_uint64)leadingZeroBits) - 1);

    // update parsed bit count
    (*p_bitcnt)+=(leadingZeroBits<<1)+1+check_byte*8;

    //drv_trace1(TRACE_GROUP_10,  CODENUM, codeNum);
    return codeNum;
}


kal_uint32 open_api_h264_uitl_ue(kal_uint8 *p_addr, kal_uint32 *p_bitcnt)
{
    return ((kal_uint32)h264_uitl_ue_long(p_addr, p_bitcnt));
}


kal_uint32 open_api_h264_uitl_u(kal_uint8 *p_addr, kal_uint32 *p_bitcnt, kal_int32 bit_len)
{
    kal_uint32 curByte;
    kal_uint32 byte_offset, byte_offset_new;	
    kal_uint32 pos, bit_offset;		
    kal_uint32 bit;
    kal_uint32 val = 0;
    kal_int32 index;
    kal_uint32 check_byte = 0;

    // check emulation code first
    h264_uitl_check_emulation_code(p_addr, *p_bitcnt, (bit_len/8)+1);
    byte_offset = (*p_bitcnt)/8;
    byte_offset_new = byte_offset;
    curByte = byte_offset;
    bit_offset = (*p_bitcnt)& 0x7;
    // check first byte
    if(h264_util_match_emulation_code(curByte))
    {
        curByte++;
        check_byte++;
    } 
            
    for (index=0; index<bit_len; index++) 
    {
        byte_offset_new = ((*p_bitcnt)+index)/8;       
        if(byte_offset != byte_offset_new)
        {
            byte_offset = byte_offset_new;
            curByte++;
            if(h264_util_match_emulation_code(curByte))
            {
                curByte++;
                check_byte++;
            } 
        }

        pos = bit_offset + index;
        bit = p_addr[curByte]&(1<<(7-(pos&7)));
        val += (bit==0)?0:(1<<(bit_len-index-1));
    }

    // update parsed bit count
    (*p_bitcnt)+=bit_len+check_byte*8;
    
    return val;
}

kal_int64 open_api_h264_uitl_se(kal_uint8 *p_addr, kal_uint32 *p_bitcnt)
{
    kal_int64 codeNum = h264_uitl_ue_long(p_addr, p_bitcnt);
    kal_int64 value;

    //drv_trace1(TRACE_GROUP_10,  CODENUM, codeNum);
    value = (kal_int64)(codeNum+1)/2;
    if((codeNum&0x01)==0)
        value = -value;

    //drv_trace1(TRACE_GROUP_10,  VALUE, value);
    return value;
}

/*******************************************************************************
*   H264 memory utility functions
*******************************************************************************/

kal_uint32 h264_util_align_mem(kal_uint32 start_addr, kal_uint32 bytes)
{
    kal_uint32 index = 0;
    kal_uint32 align_bytes = bytes;
    kal_uint32 ret_addr;

    if(bytes == 0)
        return start_addr;
    
    while(1)
    {
        align_bytes = align_bytes >> 1;
        if(align_bytes > 0)
        {
            index++;
        }
        else
        {
            break;
        }
    }

    ret_addr = (start_addr + bytes - 1) & (~((1<<index)-1));
    return ret_addr;
}

static void h264_util_init_mem(void)
{
    g_open_api_h264_dec_info_ptr->dec_param.slice_cmd_mem_index = 0;
}

static kal_uint8* h264_util_get_mem(kal_int32 size)
{
    kal_uint8 *p_addr;
    if((size + g_open_api_h264_dec_info_ptr->dec_param.slice_cmd_mem_index) > H264_MAX_SLICE_CMD_MEM_SIZE)
    {
    	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
    	EXT_ASSERT(0, size, g_open_api_h264_dec_info_ptr->dec_param.slice_cmd_mem_index, H264_MAX_SLICE_CMD_MEM_SIZE);
    }
        
    p_addr = &g_open_api_h264_dec_info_ptr->dec_param.slice_cmd_memory[g_open_api_h264_dec_info_ptr->dec_param.slice_cmd_mem_index];
    g_open_api_h264_dec_info_ptr->dec_param.slice_cmd_mem_index+=size;

    return p_addr;
}

/*******************************************************************************
*  H264 functions                                           
*******************************************************************************/

void open_api_h264_init_rpl_0(void)
{
  kal_uint32 index;
  
  for (index=0; index<g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number; index++) 
  {	
   g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].index_to_DPB = -1;
   g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].index_to_DPB = -1;
  }
  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used = 0;
  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used = 0;
}

void open_api_h264_init_dpb_frame_list(kal_uint32 max_num)
{
    kal_uint32 index;
    g_open_api_h264_dpb_frame_info.max_queue_num = (max_num>1? max_num: 2);//Scott, at least 2 
    g_open_api_h264_dpb_frame_info.p_start = NULL;
    g_open_api_h264_dpb_frame_info.p_end = NULL;
    g_open_api_h264_dpb_frame_info.p_next_parse = NULL;
    g_open_api_h264_dpb_frame_info.last_IDR_no=0xffffffff;
    
    kal_mem_set(g_open_api_h264_dpb_frame_info.frame_list, 0, sizeof(H264_dpb_frame_entry)*(H264_MAX_DPB_ENTRY*2));
    for(index = 0; index < (H264_MAX_DPB_ENTRY*2); index++)
    {
        g_open_api_h264_dpb_frame_info.frame_list[index].index= index;
    }
    
    /*Scott, Make it more clear */
    g_open_api_h264_dpb_frame_info.p_dpb_decode = NULL;
    g_open_api_h264_dpb_frame_info.p_prev_display = NULL;
    g_open_api_h264_dpb_frame_info.display_time = NULL;
    g_open_api_h264_dpb_frame_info.prev_display_time = NULL;
    
}

/* Initialize the H264_DPB_list.
 * @param pic_size picture size 
 * @return None
 */
void open_api_h264_init_dpb_list(kal_uint32 pic_size)
{
    kal_uint32 index;

    //initialize DPB list
    g_open_api_h264_DPB_list.num_used = 0;
    //g_open_api_h264_DPB_list.p_buffer = g_open_api_h264_dec_info_ptr->p_frame_buffer_memory;
    g_open_api_h264_DPB_list.wait_for_free = 0;
    for (index = 0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
    {
        /*
        g_open_api_h264_DPB_list.dpbe[index].mem_addr = 
		             g_open_api_h264_DPB_list.p_buffer + index * pic_size;
        */
        g_open_api_h264_DPB_list.dpbe[index].mem_addr = NULL;
        
        /*	Clear to black color for CR 'MAUI_01212997'. SJ 20081027. Moved to the above layer	*/
        //kal_mem_set(g_open_api_h264_DPB_list.dpbe[index].mem_addr, 0, g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits*16*16);
        //kal_mem_set((kal_uint8 *)(g_open_api_h264_DPB_list.dpbe[index].mem_addr+g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits*16*16), 128, (kal_uint32)(g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits*16*16)>>1);
        
        g_open_api_h264_DPB_list.dpbe[index].b_used = KAL_FALSE;
        g_open_api_h264_DPB_list.dpbe[index].index = index;
        g_open_api_h264_DPB_list.dpbe[index].status_marked = -1;
        g_open_api_h264_DPB_list.dpbe[index].pic_num = -1;
        g_open_api_h264_DPB_list.dpbe[index].is_corrupted= KAL_FALSE;
        g_open_api_h264_DPB_list.dpbe[index].isOutputed = -1;
    }    
    if (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number < 16)
    {
    	for (index = (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index < 17; index++)
    	{
    		g_open_api_h264_DPB_list.dpbe[index].mem_addr = g_open_api_h264_DPB_list.dpbe[0].mem_addr;
    	}
    }
    g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list = &g_open_api_h264_DPB_list;
    open_api_h264_init_dpb_frame_list(g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number);

    g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb = &g_curr_dpb;
}

#if defined(__H264_OPEN_API_DRIVER_ERROR_CONCEALMENT__)

#if defined(__VE_MTK_TARGET__)
#pragma arm section rwdata = "NONCACHEDRW", zidata = ="NONCACHEDZI"
#endif
kal_uint8 skip_slice[4]={0x00,0x2A,0x38,0x9E};//skip run:1350
#if defined(__VE_MTK_TARGET__)
#pragma arm section rwdata , zidata 
#endif

#endif
/* Allocate and initialize SPS related recource
 * @param sps sps information
 * @param b_first whether the SPS is the first one SPS in parameter sets, allocate resource in the first SPS
 * @return None 
 */
MEDIA_STATUS_CODE h264_set_sps_vars(H264_sps_info *sps, kal_bool b_first)
{
    kal_uint32 max_dpb_size;
    //kal_uint32 max_size;
    kal_uint32 pic_size;
    kal_uint32 CropUnitX,CropUnitY;

    if(b_first == KAL_FALSE)
    {
        // only check parameter legal or not 
        if((g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs != (sps->pic_width_in_mbs_minus1 + 1)) ||
            (g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs != (sps->pic_height_in_map_units_minus1 + 1)))
        {
        	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
        	EXT_ASSERT(0, sps->pic_width_in_mbs_minus1, sps->pic_height_in_map_units_minus1, g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs);
                return VIDEO_UNSUPPORT;
        }
    }
    else
    {
        g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs = sps->pic_width_in_mbs_minus1 + 1;
        g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_samples_L = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*16;
        g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_samples_C = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*8;
        g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs = sps->pic_height_in_map_units_minus1 + 1;
        g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_samples_L = g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs*16;
        g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_samples_C = g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs*8;
        g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs * g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs;
        g_open_api_h264_dec_info_ptr->dec_param.crop_unit_X = 2;
        g_open_api_h264_dec_info_ptr->dec_param.crop_unit_Y = 2 * (2 - sps->frame_mbs_only_flag);
        switch (sps->level_idc) 
        {	
        // from Table A-1 - Level limits
        case 10:
            max_dpb_size = 152064;		// 148.5k
            break;
        case 11:
            max_dpb_size = 345600;		// 337.5k
            break;
        case 12:
            max_dpb_size = 912384;		// 891k
            break;
        case 13:
            max_dpb_size = 912384;		// 891k
            break;
        case 20:
            max_dpb_size = 912384;		// 891k
            break;
        case 21:
            max_dpb_size = 1824768;		// 1782k
            break;
        case 22:
            max_dpb_size = 3110400;		// 3037.5k
            break;
        case 30:
            max_dpb_size = 3110400;		// 3037.5k
            break;
        default:
            max_dpb_size = 0;
            video_dbg_trace(H264_DEC_ASSERT,__LINE__);
            EXT_ASSERT(0, sps->level_idc, 0, 0);
            break;
        }
        
        /* Allocate frame buffer memory */
        
        // init working memory
        /*Force to Level 3 for better performance*/
        if (max_dpb_size > H264_DEC_PLAYER_DPB_MAX_SIZE)
        {
        	max_dpb_size = H264_DEC_PLAYER_DPB_MAX_SIZE;  
        }
        //max_dpb_size = H264_DEC_PLAYER_DPB_MAX_SIZE;
        //max_size = H264_MAX_FRAME_SIZE;
        
        if (max_dpb_size > g_open_api_h264_dec_info_ptr->system_dpb_size)
        {
            max_dpb_size = g_open_api_h264_dec_info_ptr->system_dpb_size;
        }
        
        // calculate picture size and DPB number
        pic_size = g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits*16*16*3/2;
        g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number = max_dpb_size/pic_size;
        
        /*Scott, in this case, out of spec [The value of num_ref_frames shall be in the range of 0 to MaxDpbSize]*/
        if(g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number< sps->num_ref_frames)
        {
         //max_dpb_size = VIDEO_MIN(3110400, (pic_size*sps->num_ref_frames));
         //g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number = max_dpb_size/pic_size;
         return VIDEO_UNSUPPORT;
        }

        g_open_api_h264_dec_info_ptr->dec_param.max_dpb_size = max_dpb_size;

        g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number  = VIDEO_MIN(g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number, 16);

        //kal_mem_set(g_open_api_h264_dec_info_ptr->p_frame_buffer_memory,0,H264_MAX_FRAME_BUFFER_SIZE(g_open_api_h264_dec_info_ptr->dec_param.max_dpb_size,max_size));
        
        // initailize reference list parameters
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_ref_frames = sps->num_ref_frames;

        open_api_h264_init_rpl_0();
        
        /*Scott, Cropping is ignored.*/
	 g_open_api_h264_dec_info_ptr->width= (kal_uint16)g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*16;
        g_open_api_h264_dec_info_ptr->height= (kal_uint16)g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs*16;

        /*Scott, compute cropping*/
        CropUnitX=g_open_api_h264_dec_info_ptr->dec_param.crop_unit_X;
        CropUnitY=g_open_api_h264_dec_info_ptr->dec_param.crop_unit_Y;

        g_open_api_h264_dec_info_ptr->crop_x0 = (kal_uint16)(sps->frame_crop_left_offset * CropUnitX);
        g_open_api_h264_dec_info_ptr->crop_x1 = (kal_uint16)(g_open_api_h264_dec_info_ptr->width - (CropUnitX * sps->frame_crop_right_offset + 1));
        g_open_api_h264_dec_info_ptr->crop_y0 = (kal_uint16)(sps->frame_crop_top_offset * CropUnitY);
        g_open_api_h264_dec_info_ptr->crop_y1 = (kal_uint16)(g_open_api_h264_dec_info_ptr->height - (CropUnitY * sps->frame_crop_bottom_offset + 1));  

        g_open_api_h264_dec_info_ptr->real_width = g_open_api_h264_dec_info_ptr->crop_x1 - g_open_api_h264_dec_info_ptr->crop_x0 + 1;
        g_open_api_h264_dec_info_ptr->real_height= g_open_api_h264_dec_info_ptr->crop_y1 - g_open_api_h264_dec_info_ptr->crop_y0 + 1;

        // initialize DPB list
        open_api_h264_init_dpb_list(pic_size);
    }
    return MEDIA_STATUS_OK;
}

/* Sort short term reference list
 * @param None
 * @return None 
 */
static void h264_sort_str_list(void)
{
    kal_uint32 str_used = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used;
    kal_uint32 index, index2, found_index;
    kal_uint32 min_num = 0;
    kal_int32 index_to_dpb;
    kal_uint32 num;

    if(str_used == 0)
    {
    	VIDEO_ASSERT(0);
    	ASSERT(0);
    }

    // sort from small to large
    min_num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[0].num;
    for(index = 0; index < str_used; index++)
    {
        found_index = index;
        for(index2 = index; index2 < str_used; index2++)
        {
            if((kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index2].num < min_num)
            {
                min_num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index2].num;
                found_index = index2;
            }
        }

        if(found_index != index)
        {
            num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[found_index].num;
            index_to_dpb = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[found_index].index_to_DPB;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[found_index].num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].num;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[found_index].index_to_DPB = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].index_to_DPB;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].num = (kal_int32)num;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].index_to_DPB = index_to_dpb;
        }
    }

}


/* Check short term reference list, sort it when needed
 * @param slice slice information
 * @return None 
 */
static void open_api_h264_check_str_list(H264_slice_info *slice)
{
    kal_uint32 index;
    kal_int32 frame_num = (kal_int32)slice->frame_num;
    kal_bool b_sort = KAL_FALSE;
    kal_uint32 str_used = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used;

    //8.2.4.1
    for (index = 0; index < (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used; index++) 
    {
        if(g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].num > frame_num)
        {
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].num -=  (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.max_frame_num;
            b_sort = KAL_TRUE;
        }    
    }

    // the new added one is not the largest one, need to sort
    if(b_sort == KAL_TRUE)
    {
        h264_sort_str_list();
    }

    // re-construct rpe list, rpe from large to small for short term reference 
    for(index = 0; index < str_used; index++)
    {
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.rpe[index] = &g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[str_used - index - 1];
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.rpeStatus[index] = H264_rpe_short_term;
    }
}

/* Sort long term reference list
 * @param None
 * @return None 
 */
static void h264_sort_ltr_list(void)
{
    kal_uint32 ltr_used = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used;
    kal_uint32 str_used = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used;
    kal_uint32 index, index2, found_index;
    kal_uint32 min_num = 0;
    kal_int32 index_to_dpb;
    kal_uint32 num;
    
    // sort from small to large 
    min_num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[0].num;
    for(index = 0; index < ltr_used; index++)
    {
        found_index = index;
        for(index2 = index; index2 < ltr_used; index2++)
        {
            if((kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index2].num < min_num)
            {
                min_num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index2].num;
                found_index = index2;
            }
        }

        if(found_index != index)
        {
            num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[found_index].num;
            index_to_dpb = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[found_index].index_to_DPB;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[found_index].num = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].num;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[found_index].index_to_DPB = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].index_to_DPB;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].num = (kal_int32)num;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].index_to_DPB = index_to_dpb;
        }
    }

    // re-construct rpe list, rpe from small to large for short term reference 
    for(index = str_used; index < (str_used+ltr_used); index++)
    {
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.rpe[index] = &g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index - str_used];
        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.rpeStatus[index] = H264_rpe_long_term;
    }
}

/* POC type 0 handler
 * @param sps sps information of the curent slice
 * @param slice slice information
 * @param nalu NALU of the current parsed slice
 * @return None 
 */
static void h264_handle_poc_type0(H264_sps_info *sps, H264_slice_info *slice, H264_NAL_unit *nalu)
{
    if (nalu->nal_unit_type == H264_sliceOfIDR) 
    {
        g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_msb = 0;
        g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb = 0;
    }
    else if (g_open_api_h264_dec_info_ptr->dec_param.prev_pic_has_MMCO5==1) 
    {        
        g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_msb = 0;
        g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb = g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt;
    } 
    else 
    {
        g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_msb = g_open_api_h264_dec_info_ptr->dec_param.prev_ref_pic_oder_cnt_msb;
        g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb = g_open_api_h264_dec_info_ptr->dec_param.prev_ref_pic_oder_cnt_lsb;
    }
    
    if ( ((kal_int32)slice->pic_order_cnt_lsb < g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb) && 
         ((g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb-(kal_int32)slice->pic_order_cnt_lsb) >= (kal_int32)(g_open_api_h264_dec_info_ptr->dec_param.max_pic_order_cnt_lsb>>1)) ) 
    {
        g_open_api_h264_dec_info_ptr->dec_param.pic_order_cnt_msb = g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_msb + (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.max_pic_order_cnt_lsb;
    } 
    else if ( ((kal_int32)slice->pic_order_cnt_lsb > g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb) && 
                (((kal_int32)slice->pic_order_cnt_lsb - g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_lsb) > (kal_int32)(g_open_api_h264_dec_info_ptr->dec_param.max_pic_order_cnt_lsb>>1)) ) 
    {	
        g_open_api_h264_dec_info_ptr->dec_param.pic_order_cnt_msb = g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_msb - (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.max_pic_order_cnt_lsb;
    } else
    {
        g_open_api_h264_dec_info_ptr->dec_param.pic_order_cnt_msb = g_open_api_h264_dec_info_ptr->dec_param.prev_pic_order_cnt_msb;
    }
    
    g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt = g_open_api_h264_dec_info_ptr->dec_param.pic_order_cnt_msb + (kal_int32)slice->pic_order_cnt_lsb;
    g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt = g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt + slice->delta_pic_order_cnt_bottom;

}


/* POC type 1 handler
 * @param sps sps information of the curent slice
 * @param slice slice information
 * @param nalu NALU of the current parsed slice
 * @return None 
 */
static void h264_handle_poc_type1(H264_sps_info *sps, H264_slice_info *slice, H264_NAL_unit *nalu)
{
    kal_int32 expectedPicOrderCnt, absFrameNum, picOrderCntCycleCnt=0;
    kal_int32 expectedDeltaPerPicOrderCntCycle, frameNumInPicOrderCntCycle=0;
    kal_uint32 index;

    if (nalu->nal_unit_type != H264_sliceOfIDR) 
    {
        if (g_open_api_h264_dec_info_ptr->dec_param.prev_pic_has_MMCO5==1) 
        {
            g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset = 0;
        } 
        else 
        {
            g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset = g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset;
        }
    }
    
    if (nalu->nal_unit_type == H264_sliceOfIDR) 
    {
        g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset = 0;
    } 
    else if (g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num > (kal_int32)slice->frame_num) 
    {
        g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset = g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset + (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.max_frame_num;
    }
    else 
    {
        g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset = g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset;
    }
    
    if(sps->num_ref_frames_in_pic_order_cnt_cycle != 0)
        absFrameNum = g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset + (kal_int32)slice->frame_num;
    else
        absFrameNum = 0; 
    if ( (nalu->nal_ref_idc==0) && (absFrameNum>0) )
        absFrameNum = absFrameNum-1;

    if(absFrameNum > 0) 
    {
        picOrderCntCycleCnt = (absFrameNum-1) / (kal_int32)sps->num_ref_frames_in_pic_order_cnt_cycle;
        frameNumInPicOrderCntCycle = (absFrameNum-1) % (kal_int32)sps->num_ref_frames_in_pic_order_cnt_cycle;
    }
    
    expectedDeltaPerPicOrderCntCycle = 0;
    for(index=0; index<(kal_int32)sps->num_ref_frames_in_pic_order_cnt_cycle; index++)
        expectedDeltaPerPicOrderCntCycle += sps->offset_for_ref_frame[index];

    if(absFrameNum > 0)
    {
        expectedPicOrderCnt = picOrderCntCycleCnt * expectedDeltaPerPicOrderCntCycle;
        for(index=0; index<=(kal_uint32)frameNumInPicOrderCntCycle; index++)
            expectedPicOrderCnt = expectedPicOrderCnt + sps->offset_for_ref_frame[index];
    } 
    else
    {
        expectedPicOrderCnt = 0;
    }
    if( nalu->nal_ref_idc == 0 )
        expectedPicOrderCnt = expectedPicOrderCnt + sps->offset_for_non_ref_pic;

    g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt = expectedPicOrderCnt + slice->delta_pic_order_cnt[0];
    g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt = g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt + 
                                                                                        sps->offset_for_top_to_bottom_field + slice->delta_pic_order_cnt[1];
    
}


/* POC type 2 handler
 * @param sps sps information of the curent slice
 * @param slice slice information
 * @param nalu NALU of the current parsed slice
 * @return None 
 */
static void h264_handle_poc_type2(H264_sps_info *sps, H264_slice_info *slice, H264_NAL_unit *nalu)
{
    kal_int32 tempPicOrderCnt;

    if (nalu->nal_unit_type != H264_sliceOfIDR) 
    {
        if (g_open_api_h264_dec_info_ptr->dec_param.prev_pic_has_MMCO5 == 1) 
        {
            g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset = 0;
        } 
        else 
        {
            g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset = g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset;
        }
    }

    if (nalu->nal_unit_type == H264_sliceOfIDR) 
    {
        g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset = 0;
    }
    else if (g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num > (kal_int32)slice->frame_num) //frame number is roll back
    {
        g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset = g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset + (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.max_frame_num;
    } 
    else 
    {
        g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset = g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num_offset;
    }
    
    if( nalu->nal_unit_type == H264_sliceOfIDR)
        tempPicOrderCnt = 0;
    else if( nalu->nal_ref_idc == 0 )
        tempPicOrderCnt = 2 * ( g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset + (kal_int32)slice->frame_num ) - 1;
    else
        tempPicOrderCnt = 2 * ( g_open_api_h264_dec_info_ptr->dec_param.frame_num_offset + (kal_int32)slice->frame_num );
   
    g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt = tempPicOrderCnt;
    g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt = tempPicOrderCnt;
   
}

/* Estimate POC of current slice according to POC type
 * @param sps sps information of the curent slice
 * @param slice slice information
 * @param nalu NALU of the current parsed slice
 * @return None 
 */
static void h264_estimate_poc(H264_sps_info *sps, H264_slice_info *slice, H264_NAL_unit *nalu)
{        
    // handle POC according to type

     if (sps->pic_order_cnt_type > 2)
    {
    	dbg_print("[DRV H264]Pic_Order_Cnt_Type is Error (>2): %d\n\r", sps->pic_order_cnt_type);
    }
    
    switch (sps->pic_order_cnt_type) 
    {
    case 0:
        h264_handle_poc_type0(sps, slice, nalu);
        break;
    case 1:
        h264_handle_poc_type1(sps, slice, nalu);
        break;
    case 2:
        h264_handle_poc_type2(sps, slice, nalu);
        break;
    default:
        VIDEO_ASSERT(0);
        break;
    }
    g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt = VIDEO_MIN(g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt, 
                                                                                        g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt);
    // Constraints from Clause 8.2.1
    if (nalu->nal_unit_type == H264_sliceOfIDR) 
    {
        if (g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt != 0)
        {
        	VIDEO_ASSERT(0);
        }
    }

    // record pic order cnt information
    if(nalu->nal_ref_idc !=0)
    {
        g_open_api_h264_dec_info_ptr->dec_param.prev_ref_pic_oder_cnt_msb = g_open_api_h264_dec_info_ptr->dec_param.pic_order_cnt_msb;
        g_open_api_h264_dec_info_ptr->dec_param.prev_ref_pic_oder_cnt_lsb = (kal_int32)slice->pic_order_cnt_lsb;//g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt;
    }
}

/* Set and verify variables of slice header, only set in the first slice in one frame
 * @param sps sps information of the current slice
 * @param pps pps information of the current slice
 * @param slice slice information
 * @param nalu NALU of the current parsed slice
 * @return None 
 */
void h264_set_slice_header_vars(H264_sps_info *sps, H264_pps_info *pps, H264_slice_info *slice, H264_NAL_unit *nalu)
{
    // record last frame number first
    g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num = (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num;

    // initialize slice command memory
    h264_util_init_mem();
    
    // Some functions are called at a new AU starts.
    g_open_api_h264_dec_info_ptr->dec_param.max_frame_num = 1<<(sps->log2_max_frame_num_minus4+4);
    g_open_api_h264_dec_info_ptr->dec_param.max_pic_order_cnt_lsb = 1<<(sps->log2_max_pic_order_cnt_lsb_minus4+4);
    g_open_api_h264_dec_info_ptr->dec_param.max_pic_num = g_open_api_h264_dec_info_ptr->dec_param.max_frame_num;
    g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num = slice->frame_num;

    // Check if video loss. Conceal if yes.
    if(nalu->nal_unit_type == H264_sliceOfIDR)
    {
        g_open_api_h264_dec_info_ptr->dec_param.prev_ref_frame_num = 0;
        if(slice->frame_num !=0)
        {
        	VIDEO_ASSERT(0);
        }
    }
    else
    {
        if ( (slice->frame_num != g_open_api_h264_dec_info_ptr->dec_param.prev_ref_frame_num)
             && (slice->frame_num != ((g_open_api_h264_dec_info_ptr->dec_param.prev_ref_frame_num+1)%g_open_api_h264_dec_info_ptr->dec_param.max_frame_num)) ) 
        {       
            // no use?
            //h264_fill_frame_gap(g_open_api_h264_dec_info_ptr->dec_param.prev_ref_frame_num, slice->frame_num, slice);
            g_open_api_h264_dec_info_ptr->dec_param.prev_ref_frame_num = slice->frame_num;
        }
        else
        { 
            if ( (nalu->nal_ref_idc!=0) && 
                 ((nalu->nal_unit_type==H264_sliceOfIDR)||(nalu->nal_unit_type==H264_sliceOfnonIDR)) ) 
            {
                g_open_api_h264_dec_info_ptr->dec_param.prev_ref_frame_num = slice->frame_num;
            }
        }
    }

    // Estimate POC of new AU
    h264_estimate_poc(sps, slice, nalu);

    // check short term reference list
    open_api_h264_check_str_list(slice);
    h264_sort_ltr_list();
}

/* parse reference list reordering command in slice header
  * @param pps pps information of the current slice
  * @param slice slice information
  * @param p_addr start address of the slice NALU
  * @param p_bitcnt input is the offset bit that should start to parse, return value is the next bits that caller can continue to parse
 * @return None 
 */
MEDIA_STATUS_CODE h264_ref_pic_list_reordering(H264_pps_info *pps, H264_slice_info *slice, kal_uint8 *p_addr, kal_uint32 *p_bitcnt)
{
    H264_ref_pic_list *p_ref_list0 = &g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0;
    H264_DPB_list *p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
    kal_uint32 ltr_used = p_ref_list0->num_LTR_used;
    kal_uint32 str_used = p_ref_list0->num_STR_used;
    kal_uint32 max_pic_num = g_open_api_h264_dec_info_ptr->dec_param.max_pic_num;
    H264_ref_pic_reorder_cmd *cmd, *cmd2;
    kal_uint32 idc, diff, long_num;
    kal_uint32 picNumL0Pred = g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num;
    kal_uint32 picNumL0NoWrap, picNumL0=0;
    kal_uint32 index, index2, total_num;
    kal_int32 found_index;
    H264_rpe_status cur_status = H264_rpe_short_term;
    H264_ref_pic_entry *cur_rpe;
    kal_uint32 refIdxL0 = 0;

    // temp is only used for the current slice, not temp one is for the whole frame
    kal_mem_cpy( p_ref_list0->rpeStatus_temp, p_ref_list0->rpeStatus, sizeof(H264_rpe_status)*(str_used+ltr_used));
    kal_mem_cpy(p_ref_list0->rpe_temp, p_ref_list0->rpe, sizeof(H264_ref_pic_entry*)*(str_used+ltr_used));        
    if((str_used+ltr_used) < 16)
    {
        //p_ref_list0->rpe_temp[str_used+ltr_used] = NULL;
        for(index = (str_used+ltr_used); index < 16; index++)
        {
            p_ref_list0->rpe_temp[index] = NULL;
            p_ref_list0->rpe[index] = NULL;
        }
    }
    
    if (slice->slice_type != H264_slice_typeP)
    {
       return MEDIA_STATUS_OK;      
    }
    
    slice->ref_pic_list_reordering_flag_l0 = (kal_uint8)open_api_h264_uitl_u(p_addr, p_bitcnt, 1);
    if (slice->ref_pic_list_reordering_flag_l0 == 1) 
    {
        slice->ref_pic_reorder_cmd = (H264_ref_pic_reorder_cmd*)h264_util_get_mem(sizeof(H264_ref_pic_reorder_cmd));
        slice->ref_pic_reorder_cmd->nextCmd = NULL;
        cmd = slice->ref_pic_reorder_cmd;
        cmd2 = cmd->nextCmd;
        while(1) 
        {
            cur_rpe = 0;
            idc = open_api_h264_uitl_ue(p_addr, p_bitcnt);
            cmd->reordering_of_pic_nums_idc	 = idc;
            if (idc >3)
            {
            	dbg_print("[DRV H264]Reodrering_Of_Pic_Nums_Idc is Error (>3): %d\n\r", idc);
            }
            if (idc == 3)
            {
                break;
            }
            if ( (idc==0) || (idc==1) ) 
            {	
                // reordering process for short-term ref pics
                diff = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                cmd->abs_diff_pic_num_minus1 = diff;
                //Deal with RefPicList0
                if (idc==0) 
                {
                    if ( ((kal_int32)(picNumL0Pred-(diff+1))) < 0 )
                    	{
                        picNumL0NoWrap=picNumL0Pred-(diff+1)+max_pic_num;
                    	}
                    else
                    	{
                        picNumL0NoWrap=picNumL0Pred-(diff+1);
                    	}
                } 
                else 
                {	
                    // idc==1
                    if ( (picNumL0Pred+(diff+1)) >= (kal_int32)max_pic_num )
                    	{
                        picNumL0NoWrap=picNumL0Pred+(diff+1)-max_pic_num;
                    	}
                    else
                    	{
                        picNumL0NoWrap=picNumL0Pred+(diff+1);
                    	}
                }
                
                picNumL0Pred = picNumL0NoWrap;	// for next iteration
                
                if (picNumL0NoWrap > g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num)
                    picNumL0 = picNumL0NoWrap - max_pic_num;
                else
                    picNumL0 = picNumL0NoWrap;

                found_index = -1;
                for(index = 0; index < 16; index++)
                {
                    if(p_ref_list0->rpe[index] !=NULL)
                    {
                        if(p_ref_list0->rpeStatus[index] == H264_rpe_short_term) 
                        {
                            if(p_ref_list0->rpe[index]->num == picNumL0)
                            {
                                found_index = (kal_int32)index;
                                break;
                            }
                        }
                    }
                }
                if(found_index == -1)
                {
                	dbg_print("[DRV H264]h264_decore.c,__LINE__:%d, hdr_parse_frames_no:%d\n\r",__LINE__ ,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
                	video_dbg_trace(H264_DEC_PARSE_ERROR_AT_LINE,__LINE__);
                    return VIDEO_ERROR;
                }
                else
                {
                    cur_status = p_ref_list0->rpeStatus[found_index];
                    cur_rpe = p_ref_list0->rpe[found_index];
                }
                
                if (p_DPB_list->dpbe[cur_rpe->index_to_DPB].status_marked != H264_shortterm_ref)
                {
                	dbg_print("[DRV H264]h264_decore.c,__LINE__:%d, hdr_parse_frames_no:%d\n\r",__LINE__ ,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
                	video_dbg_trace(H264_DEC_PARSE_ERROR_AT_LINE,__LINE__);
                    return VIDEO_ERROR;
                }
            }
            else if (idc==2) 
            {	
                // reordering process for long-term ref pics
                long_num = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                cmd->long_term_pic_num = long_num;

                found_index = -1;
                for(index = 0; index < 16; index++)
                {
                    if(p_ref_list0->rpe[index] !=NULL)
                    {
                        if(p_ref_list0->rpeStatus[index] == H264_rpe_long_term) 
                        {
                            if(p_ref_list0->rpe[index]->num == long_num)
                            {
                                found_index = (kal_int32)index;
                                break;
                            }
                        }
                    }
                }
                if(found_index == -1)
                {
                	dbg_print("[DRV H264]h264_decore.c,__LINE__:%d, hdr_parse_frames_no:%d\n\r",__LINE__ ,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
                	video_dbg_trace(H264_DEC_PARSE_ERROR_AT_LINE,__LINE__);
                    return VIDEO_ERROR;
                }
                else
                {
                    cur_status = p_ref_list0->rpeStatus[found_index];
                    cur_rpe = p_ref_list0->rpe[found_index];
                }

                if (p_DPB_list->dpbe[cur_rpe->index_to_DPB].status_marked != H264_longterm_ref)
                {
                	dbg_print("[DRV H264]h264_decore.c,__LINE__:%d, hdr_parse_frames_no:%d\n\r",__LINE__ ,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
                	video_dbg_trace(H264_DEC_PARSE_ERROR_AT_LINE,__LINE__);
                    return VIDEO_ERROR;
                }
            }

            // reorder according to the command
            index2 = 0;
            for(index=refIdxL0; index<16; index++)
            {
                // copy to rpe_temp_reorder list first (except the found one)
                if(p_ref_list0->rpe_temp[index]!=NULL)
                {
                    if ( (idc==0) || (idc==1) )
                    {
                        if((p_ref_list0->rpe_temp[index]->num!= picNumL0) || (p_ref_list0->rpeStatus_temp[index]==H264_rpe_long_term))
                        {
                            p_ref_list0->rpe_temp_reorder[index2] = p_ref_list0->rpe_temp[index];
                            p_ref_list0->rpeStatus_temp_reorder[index2] = p_ref_list0->rpeStatus_temp[index];
                            index2++;
                        }
                    }
                    else if(idc==2)
                    {
                        if((p_ref_list0->rpe_temp[index]->num != cmd->long_term_pic_num) || (p_ref_list0->rpeStatus_temp[index]==H264_rpe_short_term))
                        {
                            p_ref_list0->rpe_temp_reorder[index2] = p_ref_list0->rpe_temp[index];
                            p_ref_list0->rpeStatus_temp_reorder[index2] = p_ref_list0->rpeStatus_temp[index];
                            index2++;
                        }
                    }
                }
            }
            p_ref_list0->rpe_temp_reorder[index2] = NULL;

            total_num = index2;	
            index2 = 0;
            for(index=refIdxL0+1; index<(refIdxL0+1+total_num); index++)
            {
                // copy from rpe_temp_reorder to really temp list (after the reorder one)
                if(p_ref_list0->rpe_temp_reorder[index2]!=NULL)
                {
                    p_ref_list0->rpe_temp[index] = p_ref_list0->rpe_temp_reorder[index2];
                    p_ref_list0->rpeStatus_temp[index] = p_ref_list0->rpeStatus_temp_reorder[index2];
                    index2++;
                }
                else
                {
                    //ASSERT(0);
                    dbg_print("[DRV H264]h264_decore.c,__LINE__:%d, hdr_parse_frames_no:%d\n\r",__LINE__ ,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
                    video_dbg_trace(H264_DEC_PARSE_ERROR_AT_LINE,__LINE__);
                    return VIDEO_ERROR;
                }
            }
            total_num = refIdxL0+total_num + 1;
            // assign the found one
            p_ref_list0->rpeStatus_temp[refIdxL0] = cur_status;
            p_ref_list0->rpe_temp[refIdxL0] = cur_rpe;
            refIdxL0++;

            // next command
            cmd2 = (H264_ref_pic_reorder_cmd*)h264_util_get_mem(sizeof(H264_ref_pic_reorder_cmd));
            cmd2->nextCmd = NULL;
            cmd->nextCmd = cmd2;
            cmd = cmd2;
        }
    }
    
   return MEDIA_STATUS_OK;
}

/* Decide reference frame list
 * @param None
 * @return None 
 */
void h264_pre_make_ref_frame(void)
{
    H264_ref_pic_entry **rpe = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.rpe;
    kal_uint32 index;
    kal_uint32 used_mask = 0;
 
    // find the one except current one, that should not in reference frame list
    for (index=0; index<16; index++) 	
    {
        if (rpe[index] == NULL) 
        {
            break;
        }
        if (rpe[index]->index_to_DPB== -1) 
        {
            break;
        } 
        used_mask |= (1<<rpe[index]->index_to_DPB);
    }

    for(index =0; index < 18; index++)
    {
        if (((used_mask&(1<<index)) == 0) && (index != g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->index))
        {
            g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index = index;
            break;
        }
    }

    if(index == 18)
    {
    	VIDEO_ASSERT(0);
    }
}

/* Assign reference list to each slice
 * @param slice slice information
 * @return None 
 */
void h264_make_ref_frame_list(H264_slice_info *slice)
{
    H264_ref_pic_entry **rpe = g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.rpe_temp;
    kal_uint64 index;
    kal_uint64 mask, mask2;

    mask=mask2=0;

    // assign slice reference list 
    #ifdef __VE_MTK_TARGET__
    slice->ref_frame_index_list = 0xffffffffffffffffuLL;
    #else
    slice->ref_frame_index_list = 0xffffffffffffffff;
    #endif
    for (index=0; index<16; index++) 	
    {
        if (rpe[index] == NULL) 
        {
            break;
        }
        if (rpe[index]->index_to_DPB== -1) 
        {
            break;
        } 
        else 
        {
            if(rpe[index]->index_to_DPB == g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->index)
            {
            	  dbg_print("[DRV H264]h264_make_ref_frame_list(), __LINE__:%d\n\r",__LINE__);
            	  video_dbg_trace(H264_DEC_MAKE_REF_FRMAE_LIST_ERROR,__LINE__);      
            	  #ifdef __H264_DEBUG_ASSERT__
            	  VIDEO_ASSERT(0);
            	  #endif
            }
            else if((kal_uint32)rpe[index]->index_to_DPB > g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->index)
            {
                if(rpe[index]->index_to_DPB == g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
                {
                    dbg_print("[DRV H264]h264_make_ref_frame_list(), __LINE__:%d\n\r",__LINE__);
                    video_dbg_trace(H264_DEC_MAKE_REF_FRMAE_LIST_ERROR,__LINE__);            
                    #ifdef __H264_DEBUG_ASSERT__
                    VIDEO_ASSERT(0);
                    #endif
                }
                else if((kal_uint32)rpe[index]->index_to_DPB > g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
                {
                    mask = ((kal_uint64)(rpe[index]->index_to_DPB - (kal_int32)2)) << (kal_uint64)(index*4);
                }
                else 
                {
                    mask = ((kal_uint64)(rpe[index]->index_to_DPB - (kal_int32)1)) << (kal_uint64)(index*4);
                }
            }
            else
            {
                if(rpe[index]->index_to_DPB == g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
                {
                    dbg_print("[DRV H264]h264_make_ref_frame_list(), __LINE__:%d\n\r",__LINE__);
                    video_dbg_trace(H264_DEC_MAKE_REF_FRMAE_LIST_ERROR,__LINE__);             
                    #ifdef __H264_DEBUG_ASSERT__
                    VIDEO_ASSERT(0);
		    #endif
                }
                else if((kal_uint32)rpe[index]->index_to_DPB > g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
                {
                    mask = ((kal_uint64)(rpe[index]->index_to_DPB - (kal_int32)1)) << (kal_uint64)(index*4);
                }
                else 
                {
                    mask = ((kal_uint64)(rpe[index]->index_to_DPB - (kal_int32)0)) << (kal_uint64)(index*4);
                }
            }
            mask2 = ~(((kal_uint64)(0xf)) << (kal_uint64)(index*4));
            mask = mask | mask2;
            slice->ref_frame_index_list &= mask;
        }
    }

    // check whether the last prefetch one matches any item in the reference list
    slice->b_recInd = KAL_FALSE;
    if (rpe[0] != NULL) 
    {    
        for (index=0; index<16; index++) 
        {
            if (rpe[index] == NULL) 
            {
                break;
            }
            if (rpe[index]->index_to_DPB == -1)
                break;
            if (rpe[index]->index_to_DPB == g_open_api_h264_dec_info_ptr->dec_param.last_ref_index_to_DPB) 
            {
                slice->b_recInd = KAL_TRUE;
                slice->index_recInd = (kal_uint32)index;
                break;
            }
        }
    }
}

/* Decode ref pic marking commands from bitstream. The cmds are not performmed right now but after a new au is detected.
  * @param sps sps information of the current slice
  * @param pps pps information of the current slice
  * @param slice slice information
  * @param nalu NALU of the current parsed slice  
  * @param p_addr start address of the slice NALU
  * @param p_bitcnt input is the offset bit that should start to parse, return value is the next bits that caller can continue to parse
 * @return None 
 */
MEDIA_STATUS_CODE h264_dec_ref_pic_marking(H264_sps_info *sps, H264_pps_info *pps, H264_slice_info *slice, H264_NAL_unit *nalu, kal_uint8 *p_addr, kal_uint32 *p_bitcnt)
{
    kal_uint32 ope;
    H264_ref_pic_marking *cmd=NULL, *cmd2=NULL;

    if (nalu->nal_unit_type == 5) 
    {
        // Constraints from Clause 7.4.3.3
        slice->no_output_of_prior_pics_flag = (kal_uint8)open_api_h264_uitl_u(p_addr, p_bitcnt, 1);
        slice->long_term_reference_flag = (kal_uint8)open_api_h264_uitl_u(p_addr, p_bitcnt, 1);
        //g_open_api_h264_dec_info_ptr->dec_param.cur_pic_has_MMCO5 = KAL_TRUE;
    } 
    else 
    {	
        slice->adaptive_ref_pic_marking_mode_flag = (kal_uint8)open_api_h264_uitl_u(p_addr, p_bitcnt, 1);
        if (slice->adaptive_ref_pic_marking_mode_flag == 1) 
        {
            slice->ref_pic_marking = (H264_ref_pic_marking*)h264_util_get_mem(sizeof(H264_ref_pic_marking));
            slice->ref_pic_marking->nextCmd = NULL;
            cmd = slice->ref_pic_marking;
            cmd->nextCmd = NULL;
            //cmd2 = cmd->nextCmd;
            // parse the command until break
            while(1) 
            {
                ope = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                cmd->memory_management_control_operation = ope;
                if (ope == 0)
                    break;
                //if (ope > 6 || ope==5)
                if (ope > 6)	//ope == 5 is error?
                {
                	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);     
                	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r",__LINE__);
                	return VIDEO_ERROR;    
                }
                
                if ( (ope==1) ||(ope==3) )
                {
                    cmd->difference_of_pic_nums_minus1 = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                    drv_trace2(TRACE_GROUP_10,OPEN_API_HW_REFMARK_DIFFOFPICNUMMINUS1, ope, cmd->difference_of_pic_nums_minus1);
                }
                if (ope==2)
                {
                    cmd->long_term_pic_num = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                    drv_trace2(TRACE_GROUP_10, OPEN_API_HW_REFMARK_LONGTERMPICNUM, ope, cmd->long_term_pic_num);
                }
                if ( (ope==3)||(ope==6) )
                {
                    cmd->long_term_frame_idx = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                    drv_trace2(TRACE_GROUP_10, OPEN_API_HW_REFMARK_LONGTERMFRAMEIDX, ope, cmd->long_term_frame_idx);
                }
                if (ope==4)
                {
                    cmd->max_long_term_frame_idx_plus1 = open_api_h264_uitl_ue(p_addr, p_bitcnt);
                    drv_trace2(TRACE_GROUP_10, OPEN_API_HW_REFMARK_MAXLONGTERMFRAMEIDXPLUS1, ope, cmd->max_long_term_frame_idx_plus1);
                }
                if (ope==5)
                {
                    drv_trace0(TRACE_GROUP_10, OPEN_API_HW_REFMARK_MMCOTYPE5);
                }
                
                cmd2 = (H264_ref_pic_marking*)h264_util_get_mem(sizeof(H264_ref_pic_marking));
                cmd2->nextCmd = NULL;
                cmd->nextCmd = cmd2;
                cmd = cmd2;
            };
        }
    }	
   return MEDIA_STATUS_OK;
}

/* Record the last IDR frame number
 * open_api_h264_set_last_IDR_frame_no
 * @param None
 * @return None
 */
void open_api_h264_set_last_IDR_frame_no(kal_uint32 no)
{
   if(g_open_api_h264_dpb_frame_info.last_IDR_no==0xffffffff)
   {
   	g_open_api_h264_dpb_frame_info.last_IDR_no=no;
      // mtk01429
      //drv_trace1(TRACE_GROUP_10,H264_DRV_TRC_IDR_FOUND,no);
   }
}

/* Sort slice by first mb in slice header (the order is stored in g_open_api_h264_dec_info_ptr->dec_param.slice_order[])
 * Sort from the large to small 
 * @param None
 * @return None 
 */
static void h264_sort_slice_order(void)
{
    H264_slice_info *slice = g_open_api_h264_dec_info_ptr->dec_param.all_slice;
    kal_uint32 total_slice_num = g_open_api_h264_dec_info_ptr->dec_param.total_slice_num;
    kal_uint32 index, index2;
    kal_uint32 local_max_num, global_max_num;
    kal_uint32 found_index = 0;

    global_max_num = 0xffffffff;
    for(index = 0; index < total_slice_num; index++)
    {
        //local_max_num = slice[index].first_mb_in_slice;
        local_max_num = 0;
        found_index = index;
        for(index2 = 0; index2 < total_slice_num; index2++)
        {
            if((slice[index2].first_mb_in_slice >= local_max_num) && (slice[index2].first_mb_in_slice < global_max_num))
            {
                 local_max_num = slice[index2].first_mb_in_slice;
                 found_index = index2;
            }
        }
        global_max_num = local_max_num;
        // sort slice order from the largest first mb to the smallest one
        g_open_api_h264_dec_info_ptr->dec_param.slice_order[index] = found_index;
    }
}

/* Make slice configuration for HW according to slice settings
 * @param None
 * @return None 
 */
static void h264_make_slice_conf(void)
{
    kal_uint32 index;
    kal_uint32 total_slice_num = g_open_api_h264_dec_info_ptr->dec_param.total_slice_num;
    kal_uint32 *p_slice_conf = (kal_uint32*)g_open_api_h264_dec_info_ptr->p_slice_conf_memory;
    kal_uint8 *p_u8p;
    H264_slice_info *slice = g_open_api_h264_dec_info_ptr->dec_param.all_slice;
    H264_slice_info *curr_slice;
    H264_pps_info *pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[g_open_api_h264_dec_info_ptr->dec_param.active_pps_id];

    g_open_api_h264_dec_info_ptr->dec_param.frame_type = 0;
    for(index = 0; index < total_slice_num; index++)
    {
        // configure slice configuration
        //curr_slice = &slice[total_slice_num-index-1];
        curr_slice = &slice[g_open_api_h264_dec_info_ptr->dec_param.slice_order[total_slice_num-index-1]];
        p_slice_conf = (kal_uint32*)((kal_uint32)g_open_api_h264_dec_info_ptr->p_slice_conf_memory + index*32);
        
        *p_slice_conf = (kal_uint32)((curr_slice->ref_frame_index_list>>32)&0xffffffff);
        p_slice_conf++;

        *p_slice_conf = (kal_uint32)(curr_slice->ref_frame_index_list&0xffffffff);
        p_slice_conf++;

        *p_slice_conf = curr_slice->slice_length;
        p_slice_conf++;

        // H/W will read this address and fetch slice bitstream
        // So it should be physical address
        *p_slice_conf = (kal_uint32)curr_slice->slice_data;
        p_slice_conf++;

        // SLICE_START_BIT_CNT, FILTEROFFSETA, FILTEROFFSETB, INIT_SLICE_QP, REC_LIST_IDX
        p_u8p = (kal_uint8*)p_slice_conf;
        *p_u8p++ = (kal_uint8)(((((kal_uint32)curr_slice->slice_alpha_c0_offset_div2 << (kal_uint32)1) & 0x3) << 6) | (curr_slice->slice_data_bit_offset & 0x3f));
        *p_u8p++ = (kal_uint8)((((kal_uint32)curr_slice->slice_beta_offset_div2 << (kal_uint32)1) << 3) | ((((kal_uint32)curr_slice->slice_alpha_c0_offset_div2 << (kal_uint32)1) & 0x1c) >> 2));
        *p_u8p++ = 26 + pps->pic_init_qp_minus26 + curr_slice->slice_qp_delta;
        *p_u8p = 0xf;

        if(curr_slice->b_recInd == KAL_TRUE)
        {
            *p_u8p = (kal_uint8)(curr_slice->index_recInd&0xf);
            // valid bit = 1
            *p_u8p |= 0x10;
        }
        else
        {
            *p_u8p = 0xf;
            // valid bit = 0 
        }

        p_u8p++;

        if (curr_slice->num_ref_idx_active_override_flag == 1)
        {
            *p_u8p++ = ((curr_slice->num_ref_idx_l0_active_minus1&0xf)<<4)|((curr_slice->slice_type?0:1)<<2)|(kal_uint8)(curr_slice->disable_deblocking_filter_idc&3);
        }
        else
        {
            *p_u8p++ = ((pps->num_ref_idx_l0_active_minus1&0xf)<<4)|((curr_slice->slice_type?0:1)<<2)|(kal_uint8)(curr_slice->disable_deblocking_filter_idc&3);
        }
        if (curr_slice->slice_type == 0)
        {
            g_open_api_h264_dec_info_ptr->dec_param.frame_type = 1;
        }
        *p_u8p++ = pps->chroma_qp_index_offset&0x1f;	// chroma_qp_index_offset[4:0]
        *p_u8p++ = 0;
        *p_u8p++ = 0;
        //p_u8p += 2;	// Skip 1'd0, curr_qp_from_mc[5:0], mb_skip_run[11:0]

        p_slice_conf = (kal_uint32*)p_u8p;
        *p_slice_conf++ = 0;
        *p_slice_conf = 0;

    }
#if defined(__H264_OPEN_API_DRIVER_ERROR_CONCEALMENT__)
    curr_slice = &slice[g_open_api_h264_dec_info_ptr->dec_param.slice_order[0]];
    p_slice_conf = (kal_uint32*)((kal_uint32)g_open_api_h264_dec_info_ptr->p_slice_conf_memory + total_slice_num*32);
    *p_slice_conf = (kal_uint32)((curr_slice->ref_frame_index_list>>32)&0xffffffff);;
    p_slice_conf++;
    *p_slice_conf = (kal_uint32)(curr_slice->ref_frame_index_list&0xffffffff);
    p_slice_conf++;
    *p_slice_conf = 4;
    p_slice_conf++;
    *p_slice_conf= (kal_uint32)skip_slice;
    p_slice_conf++;
    p_u8p = (kal_uint8*)p_slice_conf;
    *p_u8p++=(kal_uint8)(((((kal_uint32)curr_slice->slice_alpha_c0_offset_div2 << (kal_uint32)1) & 0x3) << 6) /*| (curr_slice->slice_data_bit_offset & 0x3f)*/);
    *p_u8p++=(kal_uint8)((((kal_uint32)curr_slice->slice_beta_offset_div2 << (kal_uint32)1) << 3) | ((((kal_uint32)curr_slice->slice_alpha_c0_offset_div2 << (kal_uint32)1) & 0x1c) >> 2));
    *p_u8p++=26 + pps->pic_init_qp_minus26 + curr_slice->slice_qp_delta;//qp
    *p_u8p=0xf;
    p_u8p++;
    if (curr_slice->num_ref_idx_active_override_flag == 1)
    {
        *p_u8p++ = ((curr_slice->num_ref_idx_l0_active_minus1&0xf)<<4)|((/*curr_slice->slice_type*/0?0:1)<<2)|(kal_uint8)(curr_slice->disable_deblocking_filter_idc&3);
    }
    else
    {
        *p_u8p++ = ((pps->num_ref_idx_l0_active_minus1&0xf)<<4)|((/*curr_slice->slice_type*/0?0:1)<<2)|(kal_uint8)(curr_slice->disable_deblocking_filter_idc&3);
    }
    *p_u8p++ = pps->chroma_qp_index_offset&0x1f;	// chroma_qp_index_offset[4:0]
    *p_u8p++ = 0;
    *p_u8p++ = 0;
    p_slice_conf = (kal_uint32*)p_u8p;
    *p_slice_conf++ = 0;
    *p_slice_conf = 0;
#endif
}

/* Make macroblock to slice group map
 * @param None
 * @return None 
 */	
 #if 1
static void h264_make_mb_2_sg_map(void)
{
    kal_uint8 *p_sg_map = g_open_api_h264_dec_info_ptr->p_slice_group_memory;
    H264_slice_info *slice = &g_open_api_h264_dec_info_ptr->dec_param.all_slice[0];
    H264_pps_info *pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[g_open_api_h264_dec_info_ptr->dec_param.active_pps_id];
    kal_uint32 index, index2, index_group, index_num;
    kal_uint32 slice_group_num = pps->num_slice_groups_minus1;
    kal_uint32 cdf = (kal_uint32)pps->slice_group_change_direction_flag;
    kal_uint32 mb_num = g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits;
    kal_uint32 mb_width = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs;
    kal_uint32 mb_height = g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs;
    kal_uint32 yTopLeft = 0, xTopLeft = 0, yBottomRight = 0, xBottomRight = 0;
    kal_uint32 x, y;
    kal_int32 x_i, y_i;
    kal_int32 xDir, yDir, rightBound, leftBound, bottomBound, topBound;
    kal_uint32 sg0_num, mapUnitVacant, upper_left_size;

    if (pps->slice_group_map_type > 6)
    {
    	dbg_print("[DRV H264]Slice_Group_Map_Type is Error (>6): %d\n\r", pps->slice_group_map_type);
    }
    
    switch(pps->slice_group_map_type) 
    {
    case 0: // Interleaved
        index=0; 
        do 
        {
            for (index_group=0; (index_group<=slice_group_num)&&(index<mb_num); index+= pps->run_length_minus1[index_group++]+1) 
            {
                for(index2=0; (index2<=pps->run_length_minus1[index_group])&&((index+index2)<mb_num); index2++)
                {
                    p_sg_map[index+index2] = (kal_uint8)index_group;
                }
            }
        } while (index < mb_num);
        break;
    case 1: // Dispersed
        for(index=0; index<mb_num; index++)
        {
            p_sg_map[index] = (kal_uint8)(((index % mb_width)+ (((index/mb_width)*(slice_group_num+1))/2))%(slice_group_num+1));
        }
        break;
    case 2: // Foreground with left-over
        for (index=0; index<mb_num; index++) 
        {
            p_sg_map[index] = (kal_uint8)slice_group_num;
        }
        index_group = slice_group_num - 1;
        while(1)
        {
            if (index_group < H264_MAX_SLICE_GROUP)
            {
                yTopLeft = pps->top_left[index_group] / mb_width;
                xTopLeft = pps->top_left[index_group] % mb_width;
                yBottomRight = pps->bottom_right[index_group]/mb_width;
                xBottomRight = pps->bottom_right[index_group]%mb_width;
            }
            for (y=yTopLeft; y<=yBottomRight; y++)
            {
                for (x=xTopLeft; x<=xBottomRight; x++)
                {
                    p_sg_map[y*mb_width+x] = (kal_uint8)index_group;	
                }
            }
            if(index_group==0)
                break;
            index_group--;    
        }
        break;
    case 3: // Box-out
        for (index=0; index<mb_num; index++)
        {
            p_sg_map[index] = 1;
        }
        rightBound = leftBound = x_i = (kal_int32)(mb_width - cdf)/2;
        bottomBound = topBound = y_i = (kal_int32)(mb_height - cdf)/2;
        xDir = (kal_int32)cdf -1;
        yDir = (kal_int32)cdf;
        sg0_num = VIDEO_MIN((slice->slice_group_change_cycle*(pps->slice_group_change_rate_minus1+1)), mb_num);
        for (index=0; index<sg0_num; index+=mapUnitVacant) 
        {
            mapUnitVacant = p_sg_map[y_i*mb_width + x_i];
            if (mapUnitVacant == 1)
            	    p_sg_map[y_i*mb_width + x_i] = 0;
            if ( (xDir==-1)&&(x_i==leftBound) ) 
            {
                leftBound = VIDEO_MAX((leftBound-1), 0);
                x_i = leftBound;
                xDir = 0;
                yDir = (kal_int32)(2*cdf) - 1;
            } 
            else if ( (xDir==1)&&(x_i==rightBound) ) 
            {
                rightBound = (kal_int32)VIDEO_MIN((rightBound+1), (kal_int32)(mb_width-1));
                x_i = rightBound;
                xDir = 0;
                yDir = 1 - (kal_int32)(2*cdf);
            } 
            else if ( (yDir==-1)&&(y_i==topBound) ) 
            {
                topBound = VIDEO_MAX((topBound-1), 0);
                y_i = topBound;
                xDir = 1 - (kal_int32)(2*cdf);
                yDir = 0;
            } 
            else if ( (yDir==1)&&(y_i==bottomBound) ) 
            {
                bottomBound = (kal_int32)VIDEO_MIN((bottomBound+1), (kal_int32)(mb_height-1));
                y_i = bottomBound;
                xDir = (kal_int32)(2*cdf) - 1;
                yDir = 0;
            } 
            else 
            {
                x_i = x_i + xDir;
                y_i = y_i + yDir;
            }
        }
        break;
    case 4: // raster scan
        sg0_num = VIDEO_MIN((slice->slice_group_change_cycle*(pps->slice_group_change_rate_minus1+1)), mb_num);
        upper_left_size = (cdf==1?(mb_num-sg0_num):sg0_num);
        for (index=0; index<mb_num; index++) 
        {
            if (index<upper_left_size)
            	   p_sg_map[index] = (kal_uint8)cdf;
            else
                p_sg_map[index] = (kal_uint8)(1 - cdf);
        }
        break;
    case 5: // wipe
        sg0_num = VIDEO_MIN((slice->slice_group_change_cycle*(pps->slice_group_change_rate_minus1+1)), mb_num);
        upper_left_size = (cdf==1?(mb_num-sg0_num):sg0_num);
        index_num=0;
        for (index=0; index<mb_width; index++) 
        {
            for (index2=0; index2<mb_height; index2++) 
            {
                if (index_num < upper_left_size)
                    p_sg_map[index2*mb_width + index] = (kal_uint8)(1 - cdf);
                else
                    p_sg_map[index2*mb_width + index] = (kal_uint8)cdf;
                index_num++;
            }
        }
        break;
    case 6:
         for (index=0; index<mb_num; index++)
         {
             p_sg_map[index] = pps->slice_group_id[index];	
         }
         break;
    default:
        break;
    }
}
#endif

/* Make macroblock to slice map (the map will be assigned to HW)
 * @param None
 * @return None 
 */	
static void h264_make_mb_2_slice_map(void)
{
    kal_uint32 index, index2;
    kal_uint32 width = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs;
    kal_uint32 height = g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs;
    kal_uint32 total_slice_num = g_open_api_h264_dec_info_ptr->dec_param.total_slice_num;
    kal_uint16 *p_slice_map = (kal_uint16*)g_open_api_h264_dec_info_ptr->p_slice_map_memory;
    kal_uint8 *p_sg_map = g_open_api_h264_dec_info_ptr->p_slice_group_memory;
    kal_uint32 check_end;
    kal_uint32 sg_id,first_mb_in_slice;
    H264_slice_info *slice = g_open_api_h264_dec_info_ptr->dec_param.all_slice;

    // only one slice in the current frame
    if(g_open_api_h264_dec_info_ptr->dec_param.total_slice_num == 1)
    {
        for(index = 0; index < height; index++)
        {
             kal_mem_set(p_slice_map + index*(1024/16), 0, width*2);
        }
        return;
    }
    
#ifdef __H264_SLICEMAP_DEBUG__
    for(index = 0; index < height; index++)
    {
        kal_mem_set(p_slice_map + index*(1024/16), 0xff, width*2);
        kal_mem_set(p_slice_map + index*(1024/16) + width, 0xee, ((1024/16)-width)*2);
    }
#endif

    // make macroblock to slice group map first
    h264_make_mb_2_sg_map();

    // make macroblock to slice number map (according to macroblock to slice group map)
    // procedure from the largest first macroblock slice
    for(index = 0; index < total_slice_num; index++)
    {
        check_end = g_open_api_h264_dec_info_ptr->dec_param.pic_size_in_map_nits;
        
        first_mb_in_slice=slice[g_open_api_h264_dec_info_ptr->dec_param.slice_order[index]].first_mb_in_slice;
        if(first_mb_in_slice > H264_MAX_MB_NUMBER)
        {
        	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);
        	return;
        }
        //Get what slice group does this slice belong to.
        sg_id = p_sg_map[first_mb_in_slice];
        for (index2 = 0; index2 < index; index2++)  
        {
            first_mb_in_slice=slice[g_open_api_h264_dec_info_ptr->dec_param.slice_order[index2]].first_mb_in_slice;
            if(first_mb_in_slice > H264_MAX_MB_NUMBER)
            {
            	  video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);
               return;
            }
         //Find the slice which has the closest first macro block (within the same slice group)
            if (p_sg_map[first_mb_in_slice] == sg_id) 
               check_end = first_mb_in_slice;
        }

        for (index2 = slice[g_open_api_h264_dec_info_ptr->dec_param.slice_order[index]].first_mb_in_slice; index2 < check_end; index2++) 
        {
            if (p_sg_map[index2]==sg_id) 
            {
                if(p_slice_map[(index2/width)*(1024/16)+(index2%width)]!=0xffff)
                {
                    video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);
                }
                p_slice_map[(index2/width)*(1024/16)+(index2%width)] = (kal_uint16)(total_slice_num - index - 1);
            }
        }
    }
#if defined(__H264_OPEN_API_DRIVER_ERROR_CONCEALMENT__)
    for(index2=0;index2<width*height;index2++)
    {
        if(0xffff==p_slice_map[(index2/width)*(1024/16)+(index2%width)])
            p_slice_map[(index2/width)*(1024/16)+(index2%width)]=total_slice_num;
    }
#endif
}
kal_bool open_api_h264_reference_frame_check(kal_uint8* slice_config_addr, kal_uint8** ref_frame_addr)
{
 kal_uint32 slice_idx,rpl_byte,rpl_idx,index,dpb_idx;
 kal_uint8* ref_addr;
 
 for(slice_idx=0;slice_idx<g_open_api_h264_dec_info_ptr->dec_param.total_slice_num;slice_idx++)
 {
  
  /* Check one byte (i.e. 2 index) in each loop*/
  for(rpl_byte=0;rpl_byte<8;rpl_byte++) 
  {
   index = *(slice_config_addr+ rpl_byte);
   
   for(rpl_idx=0;rpl_idx<2;rpl_idx++)
   {
      if((index & 0x0F) != 0xF)
      {
         /* This entry is used */
         ref_addr = ref_frame_addr[index & 0x0F] ;
      
         /* Find the DPB */
         for(dpb_idx = 0; dpb_idx < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); dpb_idx++)
         {
            if(ref_addr == g_open_api_h264_DPB_list.dpbe[dpb_idx].mem_addr) /* Coresponding DPB Found!!*/
            {
               if(g_open_api_h264_DPB_list.dpbe[dpb_idx].b_used==KAL_FALSE)
               {
               	#ifdef __H264_DEBUG_ASSERT__
               	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
               	VIDEO_ASSERT(0); //Reference A non-used frame   
               	#endif
               	return KAL_FALSE;
               }

               if (g_open_api_h264_DPB_list.dpbe[dpb_idx].status_marked != H264_shortterm_ref &&
                   g_open_api_h264_DPB_list.dpbe[dpb_idx].status_marked != H264_longterm_ref)
               {
               	#ifdef __H264_DEBUG_ASSERT__
               	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
               	VIDEO_ASSERT(0); //Reference A non-reference frame  
               	#endif
               	return KAL_FALSE;
               }
         
             break;
            }          
         }
         if(dpb_idx==18)
         {
         	#ifdef __H264_DEBUG_ASSERT__
         	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
         	VIDEO_ASSERT(0); //No dpb found in the reference frame.  
         	#endif
         	return KAL_FALSE;
         }          
      }    
      index>>=4;
   }
   
  }  
   
  slice_config_addr += 32 ; 
 }  
   return KAL_TRUE;
}

/* Construct decode related parameters for the next frame
 * @param dpb_addr the decode dpb
 * @return None 
 */	
void open_api_h264_decode_main(kal_uint32 frame_addr_offset,kal_uint32 dpb_addr)
{
    kal_uint32 index;
    kal_uint32 last_ref_index = 0;
    kal_uint32 set_value;
    H264_pps_info *pps;
    kal_uint32 mc_y_buff_size;
    kal_uint32 mc_uv_buff_size;
    kal_bool b_found = KAL_FALSE,  result;
    kal_uint32 *p_ref_addr = (kal_uint32*)g_open_api_h264_dec_info_ptr->p_ref_frame_memory;
    H264_DPB_list *p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
    kal_uint32 cur_dpb_index = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->index;
    volatile kal_uint32 delay;
    kal_uint32 dblk_addr0, dblk_addr1, mc_line_addr, mc_mv_addr, cavlc_addr;
    kal_uint32 dblk_size;
    
    //First, log the offset from the slice 0 to the frame begining
    g_open_api_h264_dec_info_ptr->frame_addr_offset = frame_addr_offset;

    // sort slice order so that make macroblock to slice map will be correct
    h264_sort_slice_order();
    // construct slice configuration setting
    h264_make_slice_conf();  
    // construct macroblock to slice map 
    h264_make_mb_2_slice_map();


    /*Delay is need to reset H/W*/
    OPEN_API_WriteReg32(H264_DEC_COMD, H264_DEC_COMD_RST);
    for (delay=0;delay<100;delay++);

    OPEN_API_WriteReg32(H264_DEC_SLICE_MAP_ADDR, (kal_uint32)g_open_api_h264_dec_info_ptr->pfnVideoV2PAddrCallback((kal_uint32)g_open_api_h264_dec_info_ptr->p_slice_map_memory));
    OPEN_API_WriteReg32(H264_REF_FRAME_ADDR, (kal_uint32)g_open_api_h264_dec_info_ptr->pfnVideoV2PAddrCallback((kal_uint32)g_open_api_h264_dec_info_ptr->p_ref_frame_memory));

    // Construct reference frame list
    for (index=0; index<16; index++) 
    {
        p_ref_addr[index] = 0;
    }
    for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number + 1); index++) 
    {
        if(g_open_api_h264_dec_info_ptr->dec_param.last_ref_index_to_DPB == index)
        {
            b_found = KAL_TRUE;
        }

        if(index < cur_dpb_index)
        {
            if(index < g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
            {
                p_ref_addr[index] = (kal_uint32)p_DPB_list->dpbe[index].mem_addr;
                if(b_found == KAL_FALSE)
                {
                    last_ref_index++;
                }
            }
            else if(index > g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
            {
                p_ref_addr[index - 1] = (kal_uint32)p_DPB_list->dpbe[index].mem_addr;
                if(b_found == KAL_FALSE)
                {
                    last_ref_index++;
                }
            }
            //else do nothing    
        }
        else if(index > cur_dpb_index)
        {
            if(index < g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
            {
                p_ref_addr[index - 1] = (kal_uint32)p_DPB_list->dpbe[index].mem_addr;
                if(b_found == KAL_FALSE)
                {
                    last_ref_index++;
                }
            }
            else if(index > g_open_api_h264_dec_info_ptr->dec_param.non_ref_DPB_index)
            {
                p_ref_addr[index - 2] = (kal_uint32)p_DPB_list->dpbe[index].mem_addr;
                if(b_found == KAL_FALSE)
                {
                    last_ref_index++;
                }
            }
            //else do nothing
        }
    // if(index == cur_dpb_index) => do nothing
    }
//#if defined(__H264_OPEN_API_DRIVER_ERROR_CONCEALMENT__)
    for(index=0;index<16;index++)
    {
        if(NULL==p_ref_addr[index])
            p_ref_addr[index]=(kal_uint32)g_open_api_h264_dec_info_ptr->p_curr_dec_addr;
    }
//#endif
    g_open_api_h264_dec_info_ptr->p_prev_dec_addr = g_open_api_h264_dec_info_ptr->p_curr_dec_addr;
    g_open_api_h264_dec_info_ptr->p_curr_dec_addr = p_DPB_list->dpbe[cur_dpb_index].mem_addr;    
    result = open_api_h264_reference_frame_check(g_open_api_h264_dec_info_ptr->p_slice_conf_memory, (kal_uint8**)g_open_api_h264_dec_info_ptr->p_ref_frame_memory);

    if(!result)
    {
    	video_dbg_trace(H264_DEC_REF_FRAME_CHECK_ERROR,g_open_api_h264_dec_info_ptr->dec_frames_no);
    }

    // check current frame will be prefetched or not
    set_value = 0;
    if (g_open_api_h264_dec_info_ptr->dec_param.frame_type == 1)
    {
        set_value |= H264_PIC_CONF_FRAME_TYPE;
    }
    if (g_open_api_h264_dec_info_ptr->dec_param.b_ref_curr_frame == KAL_TRUE)
    {
        set_value |= H264_PIC_CONF_REF_CURR_FRAME;
    }
    set_value |= (last_ref_index<<H264_PIC_CONF_LAST_REF_INDEX_OFFSET);
    if(g_open_api_h264_dec_info_ptr->dec_param.b_ref_curr_frame == KAL_TRUE)
    {
        g_open_api_h264_dec_info_ptr->dec_param.last_ref_index_to_DPB = (kal_int32)cur_dpb_index;
        g_open_api_h264_dec_info_ptr->dec_param.b_ref_curr_frame = KAL_FALSE;
    }

    // other settings
    pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[g_open_api_h264_dec_info_ptr->dec_param.active_pps_id];
    OPEN_API_WriteReg32(H264_DEC_PIC_CONF, (kal_uint32)(set_value |H264_PIC_CONF_MC_MF_CACHE_EN |H264_PIC_CONF_ERR_STALL_EN |H264_PIC_CONF_IRQ_EN| (pps->constrained_intra_pred_flag<<17) |
				((g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs-1)<<8) | (g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs-1)));
	

    OPEN_API_WriteReg32(H264_DEC_SLICE_CONF, (kal_uint32)g_open_api_h264_dec_info_ptr->pfnVideoV2PAddrCallback((kal_uint32)g_open_api_h264_dec_info_ptr->p_slice_conf_memory));
    
    open_api_h264_dec_set_isr_vlc_param(KAL_FALSE);
    
    #ifdef __H264_DUMMY_B_SLICE_SUPPORT__
    if(g_open_api_h264_dec_info_ptr->dec_param.B_slice_exists==KAL_TRUE)
    {
    	OPEN_API_WriteReg32(H264_DEC_DMA_LIMIT, 1);
    }
    else
    #endif
    {
    	OPEN_API_WriteReg32(H264_DEC_DMA_LIMIT, 0xffff);
    }
    
    if(g_open_api_h264_dec_info_ptr->dec_param.slice_total_length >= H264_DMA_LIMIT_SIZE)
    {
        open_api_h264_dec_set_isr_vlc_param(KAL_TRUE);
    }
    
    /* (Scott,MAUI_00744472) It's hw limitation, we only support mc prefetch under the following condition */
    if((g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs > 2) &&
       (g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs > 3) )
    {
     OPEN_API_WriteReg32(H264_MC_LINE_BUF_OFFSET, ((H264_MC_LINE_YBUF_OFFSET<<H264_MC_YBUF_OFFSET)| 
                                                                              (H264_MC_LINE_UVBUF_OFFSET<<H264_MC_UVBUF_OFFSET)|
                                                                              H264_MC_PFH_EN));
    }
    else
    {
      OPEN_API_WriteReg32(H264_MC_LINE_BUF_OFFSET, 0);
    }
    
    OPEN_API_WriteReg32(H264_DEC_DEB_BUF_ADDR, (kal_uint32)g_open_api_h264_dec_info_ptr->int_mem_p_addr);
    dblk_size = H264_DEB_BUFFER_SIZE(H264_MAX_FRAME_WIDTH); 

    //DBLK data buffer0&buffer1
    dblk_addr0 = h264_util_align_mem(((kal_uint32)g_open_api_h264_dec_info_ptr->int_mem_p_addr + dblk_size), 512); 
    OPEN_API_WriteReg32(H264_DEC_DEB_DAT_BUF0_ADDR, dblk_addr0);
    dblk_addr1 = dblk_addr0 + 1024;
    OPEN_API_WriteReg32(H264_DEC_DEB_DAT_BUF1_ADDR, dblk_addr1);

    // MC line  buffer
    mc_line_addr = dblk_addr1+1024;
    OPEN_API_WriteReg32(H264_MC_LINE_BUF_ADDR, mc_line_addr);

    // MC MV buffer
    mc_mv_addr = mc_line_addr + H264_MC_LINE_BUFFER_SIZE(H264_MAX_FRAME_WIDTH);
    OPEN_API_WriteReg32(H264_MC_MV_BUFFER_ADDR, mc_mv_addr);

    cavlc_addr = mc_mv_addr + H264_MC_MV_BUFFER_SIZE;
    OPEN_API_WriteReg32(H264_CAVLC_BASE_ADDR, cavlc_addr);

    mc_uv_buff_size = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*8*(8+8*H264_MC_LINE_UVBUF_OFFSET);
    mc_uv_buff_size = (mc_uv_buff_size<<16);
    mc_y_buff_size = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*16*(16+8*H264_MC_LINE_YBUF_OFFSET);                                                                              
    OPEN_API_WriteReg32(H264_MC_LINE_BUF_SIZE, (mc_uv_buff_size | mc_y_buff_size));

    // Reference frame address is physical address,
    // So we don't need to transfer it to virtual
    OPEN_API_WriteReg32(H264_DEC_REC_ADDR, (kal_uint32)p_DPB_list->dpbe[cur_dpb_index].mem_addr);


    OPEN_API_WriteReg32(H264_DEC_REC_Y_SIZE, g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_samples_L*g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_samples_L);

    open_api_h264_set_next_decode_dpb((H264_DPB_entry *)(dpb_addr));

    g_open_api_h264_dec_info_ptr->hdr_parse_frames_no++;    
       
    OPEN_API_WriteReg32(H264_DEC_IRQ_POS,0xffffffff);
    OPEN_API_WriteReg32(H264_DEC_IRQ_MASK, 0x20);

    OPEN_API_WriteReg32(H264_DEC_COMD, H264_DEC_COMD_START); // H.264 decode start
}


/* Set  all DPB status as un-used
 * @param None
 * @return None
 */
void open_api_h264_set_all_dpb_status_unused(void)
{
    kal_uint32 index;

    for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
    {
    	g_open_api_h264_DPB_list.dpbe[index].status_marked = H264_unused_ref;
    }
}

/* IDR reference picture marking
 * @param slice slice information
 * @return None 
 */	
static void h264_IDR_ref_marking(H264_slice_info *slice)
{
	H264_ref_pic_list *p_ref_list0 = &g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0;
	H264_DPB_list *p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
	H264_DPB_entry *p_cur_dpb = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb;
	kal_uint32 index;
	
	// nalu->nal_unit_type == 5 -> has this syntax element
	if (slice->no_output_of_prior_pics_flag==0)
	{
	    if (fgDisplayOrderMode == KAL_TRUE)
        {
            output_all_DPB_entries(1);
        }
	}
	else
	{	// s->no_output_of_prior_pics_flag==1
		//reset_dpb_rpl(0);
		dbg_print("[DRV H264]no_output_of_prior_pics_flag = 1\n\r");
		VIDEO_ASSERT(0);
	    if (fgDisplayOrderMode == KAL_TRUE)
        {
            output_all_DPB_entries(1);
        }
	}

	open_api_h264_set_all_dpb_status_unused();

    fgReferenceCorrupted = p_cur_dpb->is_corrupted;
	if (slice->long_term_reference_flag == 0) 
	{
		// set current picture as short term reference
		p_ref_list0->num_STR_used = 1;
		p_ref_list0->num_LTR_used = 0;
		p_ref_list0->max_longterm_frame_idx = -1;
		p_ref_list0->strpe[0].index_to_DPB = (kal_int32)p_cur_dpb->index;
		p_ref_list0->strpe[0].num = p_cur_dpb->pic_num;
		p_DPB_list->dpbe[p_cur_dpb->index].status_marked = H264_shortterm_ref;
	} 
	else 
	{
		// set current picture as long term reference
		p_ref_list0->num_STR_used = 0;
		p_ref_list0->num_LTR_used = 1;
		p_ref_list0->max_longterm_frame_idx = 0;
		p_ref_list0->ltrpe[0].index_to_DPB = (kal_int32)p_cur_dpb->index;
		p_ref_list0->ltrpe[0].num = 0;
		p_DPB_list->dpbe[p_cur_dpb->index].status_marked = H264_longterm_ref;
	}
	//p_DPB_list->num_used++;

	// Release the buffer of the "H264_unused_ref" DPB entry
	for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
    	{
    		if (  (p_DPB_list->dpbe[index].b_used == KAL_TRUE) && (p_DPB_list->dpbe[index].status_marked ==H264_unused_ref) 
    		&& (p_DPB_list->dpbe[index].isOutputed == 1)  )
        	{
        		open_api_h264_free_dpb(&p_DPB_list->dpbe[index]);
        		p_DPB_list->num_used--;
        	}
    	}

}


/* Non-IDR reference picture marking
 * @param slice slice information
 * @return None 
 */	
static void h264_nonIDR_ref_marking(H264_slice_info *slice)
{
    H264_ref_pic_marking *cmd;
    kal_uint32 ope;
    kal_bool b_found = KAL_FALSE;
    kal_int32 pic_num;
    kal_uint32 index, index2, index_to_DPB = 0;
    H264_ref_pic_entry *p_ref_pic_entry;
    H264_DPB_list *p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
    H264_ref_pic_list *p_ref_list0 = &g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0;
    H264_DPB_entry *p_cur_dpb = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb;
    kal_bool b_assign_cur_pic = KAL_FALSE;
    
    if (p_cur_dpb->is_corrupted)
    {
    	video_dbg_trace(H264_DEC_IGNORE_MMCO,video_get_current_time());
        fgReferenceCorrupted = KAL_TRUE;
    	return;
    }
    
    if (slice->adaptive_ref_pic_marking_mode_flag == 1)
    {
        //MMCO
        cmd = slice->ref_pic_marking;
        do 
        {
            ope = cmd->memory_management_control_operation;
            switch (ope) 
            {             // Deal with RefPicList0
            case 1:    // Marking process of a short-term ref pic as UnusedForRef
            case 3:    // Marking process of a LongTermFrameIdx to a short-term ref pic
                b_found = KAL_FALSE;	
                pic_num = (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num - (kal_int32)(cmd->difference_of_pic_nums_minus1+1);
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe;
                for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used; index++) 
                {
                    if(p_ref_pic_entry[index].num == pic_num)
                    {
                        index_to_DPB = p_ref_pic_entry[index].index_to_DPB; 
                        if(p_DPB_list->dpbe[index_to_DPB].status_marked != H264_shortterm_ref)
                        {
                        	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);     
                        	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r",__LINE__);
                           g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->is_corrupted = KAL_TRUE;
                           g_open_api_h264_dec_info_ptr->is_error_occur = KAL_TRUE;
                           fgReferenceCorrupted = KAL_TRUE;
                           return;
                            //ASSERT(0);
                        }
                        b_found = KAL_TRUE;
                        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used--;
                        for(index2 = index; index2 < (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used; index2++)
                        {
                             p_ref_pic_entry[index2].index_to_DPB = p_ref_pic_entry[index2+1].index_to_DPB;
                             p_ref_pic_entry[index2].num = p_ref_pic_entry[index2+1].num;
                        }
                        break;
                    }
                }

                if(b_found == KAL_FALSE)
                {
                	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                    VIDEO_ASSERT(0);
                }
                else
                {
                    if (ope==1) 
                    {
                        p_DPB_list->dpbe[index_to_DPB].status_marked = H264_unused_ref;
                    } 
                    else 
                    {
                        p_DPB_list->dpbe[index_to_DPB].status_marked = H264_longterm_ref;
                        p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe;
                        b_found = KAL_FALSE;
                        for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index++) 
                        {
                            //if(p_ref_pic_entry[index].num == pic_num)
                            if(p_ref_pic_entry[index].num == cmd->long_term_frame_idx)
                            {
                                if(p_DPB_list->dpbe[p_ref_pic_entry[index].index_to_DPB].status_marked != H264_longterm_ref)
                                {
                                	  video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);      
                                	  dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r",__LINE__);
                                    g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->is_corrupted = KAL_TRUE;
                                    g_open_api_h264_dec_info_ptr->is_error_occur = KAL_TRUE;
                                    fgReferenceCorrupted = KAL_TRUE;
                                    return;
                                    //ASSERT(0);
                                }
                                b_found = KAL_TRUE;
                                // replace one already in long term list 
                                p_ref_pic_entry[index].index_to_DPB = (kal_int32)index_to_DPB;
                                p_ref_pic_entry[index].num = (kal_int32)cmd->long_term_frame_idx;
                                break;
                            }
                        }
                        if(b_found == KAL_FALSE)
                        {
                            // find ont empty slot
                            p_ref_pic_entry[g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used].index_to_DPB = (kal_int32)index_to_DPB;
                            p_ref_pic_entry[g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used].num = (kal_int32)cmd->long_term_frame_idx;
                            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used++;
                            //sort long term list
                            h264_sort_ltr_list();
                        }
                    }
                }
                break;
            case 2:	// Marking process of a long-term ref pic as UnusedForRef
                b_found = KAL_FALSE;	
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe;
                for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index++) 
                {
                    if(p_ref_pic_entry[index].num == cmd->long_term_pic_num)
                    {
                        index_to_DPB = p_ref_pic_entry[index].index_to_DPB; 
                        if(p_DPB_list->dpbe[index_to_DPB].status_marked != H264_longterm_ref)
                        {
                        	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                        	VIDEO_ASSERT(0);
                        }
                        b_found = KAL_TRUE;
                        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used--;
                        for(index2 = index; index2 < (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index2++)
                        {
                             p_ref_pic_entry[index2].index_to_DPB = p_ref_pic_entry[index2+1].index_to_DPB;
                             p_ref_pic_entry[index2].num = p_ref_pic_entry[index2+1].num;
                        }
                        break;
                    }
                }
                if(b_found == KAL_FALSE)
                {
                	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                    VIDEO_ASSERT(0);
                }
                else
                {
                    p_DPB_list->dpbe[index_to_DPB].status_marked = H264_unused_ref;
                } 
                break                                                                                                                                                                                                             ;
            case 4:	// Decoding process for MaxLongTermFrameIdx
                pic_num = ((kal_int32)(cmd->max_long_term_frame_idx_plus1))-1;
                b_found = KAL_FALSE;	
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe;
                for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index++) 
                {
                    if(p_ref_pic_entry[index].num > pic_num)
                    {
                        index_to_DPB = p_ref_pic_entry[index].index_to_DPB; 
                        if(p_DPB_list->dpbe[index_to_DPB].status_marked != H264_longterm_ref)
                        {
                        	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                        	VIDEO_ASSERT(0);
                        }
                        b_found = KAL_TRUE;
                        for(index2 = index; index2 < (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index2++)
                        {
                             p_DPB_list->dpbe[p_ref_pic_entry[index2].index_to_DPB].status_marked = H264_unused_ref;
                        }
                        // pic number larger than this one is removed
                        g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used = (kal_int32)index;
                        break;
                    }
                }
                g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.max_longterm_frame_idx = pic_num;
                break;
            case 5:	// Marking process of all ref pics as "UnusedForRef" and set MaxLongTermFrameIdx to "no long-term frame indices"
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe;
                for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used; index++) 
                {
                    p_DPB_list->dpbe[p_ref_pic_entry[index].index_to_DPB].status_marked = H264_unused_ref;  
                }
                g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used = 0;
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe;
                for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index++) 
                {
                    p_DPB_list->dpbe[p_ref_pic_entry[index].index_to_DPB].status_marked = H264_unused_ref;     
                }
                g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used = 0;
                for (index=0; index<g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number; index++) 
                {	
                	g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].index_to_DPB = -1;
                	g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe[index].num = 0;
                	g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].index_to_DPB = -1;
                	g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe[index].num = 0;
                }
                g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.max_longterm_frame_idx = -1;
                g_open_api_h264_dec_info_ptr->dec_param.cur_pic_has_MMCO5 = KAL_TRUE;
                g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num = 0;
                g_open_api_h264_dec_info_ptr->dec_param.prev_frame_num = 0;

                if (g_open_api_h264_dec_info_ptr->dec_param.cur_pic_has_MMCO5)
                {
                    p_cur_dpb->pic_num = 0;

                    g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt -= g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt;
                    g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt -= g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt;
                    g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt = VIDEO_MIN(g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt, g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt);
                    p_cur_dpb->top_POC = g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt;
                    p_cur_dpb->bottom_POC = g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt;
                    p_cur_dpb->POC = g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt;

            	    if (fgDisplayOrderMode == KAL_TRUE)
                    {
                        output_all_DPB_entries(1);
                    }

                    for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
                    {
                        if (  (p_DPB_list->dpbe[index].b_used == KAL_TRUE) && (p_DPB_list->dpbe[index].isOutputed == 1)  )
                        {
                            open_api_h264_free_dpb(&p_DPB_list->dpbe[index]);
                            p_DPB_list->num_used--;
                        }
                    }
                }

                break;
            case 6:	// Process for assigning a long-term frame index to the current pic
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.ltrpe;
                b_found = KAL_FALSE;
                for (index=0; index<(kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used; index++) 
                {
                    if(p_ref_pic_entry[index].num == cmd->long_term_frame_idx)
                    {
                        if(p_DPB_list->dpbe[p_ref_pic_entry[index].index_to_DPB].status_marked != H264_longterm_ref)
                        {
                        	 video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);
                        	 dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r",__LINE__);
                        	 return;
                            //ASSERT(0);
                        }
                        b_found = KAL_TRUE;
                        // replace one already in long term list 
                        p_ref_pic_entry[index].index_to_DPB = (kal_int32)p_cur_dpb->index;
                        p_ref_pic_entry[index].num = (kal_int32)cmd->long_term_frame_idx;
                        break;
                    }
                }
                if(b_found == KAL_FALSE)
                {
                    // find ont empty slot
                    p_ref_pic_entry[g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used].index_to_DPB = (kal_int32)p_cur_dpb->index;
                    p_ref_pic_entry[g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used].num = (kal_int32)cmd->long_term_frame_idx;
                    g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_LTR_used++;
                    //sort long term list
                    h264_sort_ltr_list();
                }
                p_DPB_list->dpbe[p_cur_dpb->index].status_marked = H264_longterm_ref;
                b_assign_cur_pic = KAL_TRUE;
                break;
             default:
                break;             
            }	// switch (ope) {	// Deal with RefPicList0
            cmd = cmd->nextCmd;
        } while (ope != 0 && cmd!= 0);
    }

    if(b_assign_cur_pic==KAL_FALSE)
    {
        //if(slice->b_nal_ref_idc == KAL_TRUE)
        //{
            // sliding_window_check
            if((p_ref_list0->num_STR_used + p_ref_list0->num_LTR_used) == p_ref_list0->num_ref_frames && p_ref_list0->num_STR_used > 0)
            {
                if(p_ref_list0->num_STR_used == 0)
                {
                	video_dbg_trace(H264_DEC_ASSERT,__LINE__);
                    VIDEO_ASSERT(0);
                }
                p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe;
                g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used--;
                p_DPB_list->dpbe[p_ref_pic_entry[0].index_to_DPB].status_marked = H264_unused_ref;   
                for (index=0; index< (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used; index++) 
                {
                    p_ref_pic_entry[index].index_to_DPB = p_ref_pic_entry[index+1].index_to_DPB;
                    p_ref_pic_entry[index].num = p_ref_pic_entry[index+1].num;
                }
            }

            //assign current picture as short term 
            p_ref_pic_entry =  g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.strpe;           
            p_ref_pic_entry[g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used].index_to_DPB = (kal_int32)p_cur_dpb->index;           
            p_ref_pic_entry[g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used].num = p_cur_dpb->pic_num;
            p_DPB_list->dpbe[p_cur_dpb->index].status_marked = H264_shortterm_ref;
            g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_STR_used++;
        //}
        //else
        //{
        //    p_DPB_list->dpbe[p_cur_dpb->index].status_marked = H264_unused_ref;
        //}
    }
}

/* Decoder picture buffer status and reference picture list status trace
* @param None
* @return None
*/
void h264_dpb_trace(void)
{
    kal_uint32 index;
    H264_DPB_list* p_dpb_list=g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
    H264_ref_pic_list * p_ref_list=&(g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0);
    drv_trace4(TRACE_GROUP_10, OPEN_API_HW_REFLIST_DPBNUM, 
        p_dpb_list->num_used, 
        p_dpb_list->last_POC,
        (kal_uint32)(p_dpb_list->p_buffer),
        p_dpb_list->wait_for_free);
    for(index=0;index<H264_MAX_DPB_ENTRY+1;index++)
    {
        drv_trace8(TRACE_GROUP_10, OPEN_API_HW_REFLIST_DBPINFO,
            p_dpb_list->dpbe[index].b_used,
            p_dpb_list->dpbe[index].index,
            p_dpb_list->dpbe[index].index_to_list,
            p_dpb_list->dpbe[index].status_marked,
            p_dpb_list->dpbe[index].pic_num,
            p_dpb_list->dpbe[index].POC,
            p_dpb_list->dpbe[index].is_corrupted,
            (kal_uint32)(p_dpb_list->dpbe[index].mem_addr));
    }
    drv_trace1(TRACE_GROUP_10, OPEN_API_HW_REFLIST_STRNUM,
        p_ref_list->num_STR_used);
    for(index=0;index<H264_MAX_DPB_ENTRY;index++)
    {
        drv_trace2(TRACE_GROUP_10, OPEN_API_HW_REFLIST_STRINFO,
            p_ref_list->strpe[index].index_to_DPB,
            p_ref_list->strpe[index].num);
    }
    drv_trace2(TRACE_GROUP_10, OPEN_API_HW_REFLIST_LTRNUM,
        p_ref_list->num_LTR_used,
        p_ref_list->max_longterm_frame_idx);
    for(index=0;index<H264_MAX_DPB_ENTRY;index++)
    {
        drv_trace2(TRACE_GROUP_10, OPEN_API_HW_REFLIST_LTRINFO,
            p_ref_list->ltrpe[index].index_to_DPB,
            p_ref_list->ltrpe[index].num);
    }
}


/* Reference picture marking
 * @param None
 * @return None 
 */	
void h264_ref_marking(void)
{
    H264_slice_info *slice = &g_open_api_h264_dec_info_ptr->dec_param.all_slice[0];
    H264_DPB_entry *p_cur_dpb = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb;

    video_dbg_trace(H264_DEC_REF_MARKING, 1);

    if(slice->b_nal_ref_idc == KAL_TRUE)
    {
        if(slice->b_idr == KAL_TRUE)
            h264_IDR_ref_marking(slice);
        else
            h264_nonIDR_ref_marking(slice);
    }
    else
    {
        //p_DPB_list->dpbe[p_cur_dpb->index].status_marked = H264_unused_ref;
        p_cur_dpb->status_marked = H264_unused_ref;
        /*
        p_cur_dpb->top_POC = g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt;
        p_cur_dpb->bottom_POC = g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt;
        p_cur_dpb->POC = g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt;
        */
    }
    h264_dpb_trace();

    g_open_api_h264_dec_info_ptr->dec_param.cur_pic_has_MMCO5 = KAL_FALSE;
}

void open_api_h264_dec_init_isr_param(void)
{
    g_open_api_h264_dec_isr_param.b_check_reentry = KAL_FALSE;
    g_open_api_h264_dec_isr_param.b_check_av_error = KAL_FALSE;
    //If h264_dec_update_slice_addr() is used. this flag can't be reset
    //g_open_api_h264_dec_isr_param.check_vlc_addr = KAL_FALSE;
    g_open_api_h264_dec_isr_param.speed_recover_count = 0;   
}

void open_api_h264_dec_set_isr_vlc_param(kal_bool b_check)
{
	g_open_api_h264_dec_isr_param.check_vlc_addr = b_check;
	video_dbg_trace(H264_DEC_SET_ISR_VLC_ADDR_FLG, g_open_api_h264_dec_isr_param.check_vlc_addr);
}

#endif /*#ifdef __VE_H264_HW_OPEN_API_SUPPORT__*/

